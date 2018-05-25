package MES;

import Communication.JDBC;
import Communication.Modbus;
import Communication.UDPServer;
import Communication.SendOrder;

import java.awt.print.PrinterGraphics;
import java.io.IOException;
import java.net.InetAddress;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Vector;
import java.util.concurrent.TimeUnit;

public class Main{
    public static final String ANSI_RED = "\u001B[31m";
    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_BLUE = "\u001B[34m";

    public static Vector<Order> ordersReceived = new Vector<>();
    public static Vector<Order> ordersCompleted = new Vector<>();
    public static final Modbus modbus = new Modbus();
    public static final SendOrder sendOrder = new SendOrder();
    public static boolean startedUdp = false;
    public static boolean startedSendOrders = false;
    public static Stock stock = new Stock();
    public static Sorting sorting = new Sorting();
    public static MachineA m1a = new MachineA(1);
    public static MachineA m2a = new MachineA(2);
    public static MachineB m3b = new MachineB(3);
    public static MachineC m1c = new MachineC(1);
    public static MachineC m2c = new MachineC(2);
    public static MachineC m3c = new MachineC(3);
    public static StatisticsUnload zone1 = new StatisticsUnload(1);
    public static StatisticsUnload zone2 = new StatisticsUnload(2);
    public static StatisticsUnload zone3 = new StatisticsUnload(3);

    public static void main(String args[]) throws Exception {

        Main m = new Main();
        JDBC.connect();
        UDPServer server = new UDPServer(54321);
        //temporary block
        for (int i = 1; i <= 9; i++) {
                String type = "P" + i;
                //Add quantity from data base
                String stock = JDBC.ReadFromDataBase("SELECT n_tipo_peca FROM armazem WHERE tipo_peca =" + i, "n_tipo_peca");
                int stockInt = Integer.parseInt(stock);
                m.stock.setQuantity(type, stockInt);
            }
        //end of block
        m.MainMenu(server);
    }

    public void MainMenu(UDPServer server){
        Scanner ss = new Scanner(System.in);
        System.out.println(ANSI_RED + "\nChoose an option: " + ANSI_RESET);
        if(!startedUdp) {
            System.out.println("1 - Start UDP");
            String resp = ss.next();

            //update values on database when program starts
            JDBC.WriteStringToDataBase("UPDATE armazem SET n_tipo_peca = '27'");
            JDBC.WriteStringToDataBase("DELETE FROM ordem WHERE idordem <> 0");

            switch (resp) {
                case "1":
                    ControlUDP(server);
                    break;
                default:
                    System.out.println("Wrong option");
                    MainMenu(server);
                    break;
            }
        }
        else if (!startedSendOrders){
            System.out.println("1 - Check Orders");
            System.out.println("2 - Send Orders");
            System.out.println("3 - Print Statistics");

            String resp = ss.next();
            switch (resp) {
                case "1":
                    CheckOrders(server);
                    break;
                case "2":
                    SendOrders(server);
                    break;
                case "3":
                	PrintMachines(server);
                default: 
                	System.out.println("Wrong option");
                    MainMenu(server);
                    break;
            }
        }

        else if(startedSendOrders && startedUdp){
            System.out.println("1 - Check Orders");
            System.out.println("2 - Check Completed Orders");
            System.out.println("3 - Print Statistics");
            String resp = ss.next();
            switch (resp) {
                case "1":
                    CheckOrders(server);
                    break;
                case "2":
                    PrintCompletedOrders(server);
                    break;
                case "3":
                	PrintMachines(server);
                default: System.out.println("Wrong option");
                    MainMenu(server);
                    break;
            }
        }

        else{
            System.out.println("1 - Check Orders");
        }
    }
    
    public void PrintMachines(UDPServer server) {
    	System.out.println("\nUnload:");
    	this.zone1.PrintStat();
    	this.zone2.PrintStat();
    	this.zone3.PrintStat();
    	System.out.println("\nTransform machines:");
    	this.m1a.printInfo();
    	this.m2a.printInfo();
    	this.m3b.printInfo();
    	this.m1c.printInfo();
    	this.m2c.printInfo();
    	this.m3c.printInfo();
    	MainMenu(server);
    }
    public void ControlUDP(UDPServer server){
        try {
            server.listen();
            startedUdp = true;
        } catch (Exception e) {
            e.printStackTrace();
        }
        MainMenu(server);
    }

    public void CheckOrders(UDPServer server){
    	sorting.insertionSort(ordersReceived);
        SimpleDateFormat f = new SimpleDateFormat("yyyy-MM-DD HH:mm:ss");
        Order o1 = null;
        System.out.println(ANSI_BLUE + "List of orders Received" +ANSI_RESET);
        if (!ordersReceived.isEmpty()) {
            System.out.println(ordersReceived.size() + " orders");
            for (int i = 0; i < ordersReceived.size(); i++) {
                o1 = ordersReceived.get(i);

                if (o1 != null) {
                    switch (o1.getDo()) {
                        case "U":
                            Unload u = (Unload) o1;
                            System.out.println(ANSI_BLUE + "Order number " + u.getNumber() + " - unload");
                            System.out.println("type: " + u.getType());
                            System.out.println("destination: " + u.getDestination());
                            System.out.println("quantity: " + u.getQuantity());
                            System.out.println("time received: " + f.format(u.getTimeReceived()).toString() + ANSI_RESET);
                            System.out.println("");
                            break;
                        case "T":
                            Transform t = (Transform) o1;
                            System.out.println(ANSI_BLUE + "Order number " + t.getNumber() + " - transform");
                            System.out.println("from: " + t.getFrom());
                            System.out.println("to: " + t.getTo());
                            System.out.println("quantity: " + t.getQuantity());
                            System.out.println("time received: " + f.format(t.getTimeReceived()).toString() + ANSI_RESET);
                            System.out.println("");
                            break;
                        case "M":
                            Mount m = (Mount) o1;
                            System.out.println(ANSI_BLUE + "Order number " + m.getNumber() + " - mount");
                            System.out.println("Top: " + m.getBottom());
                            System.out.println("Bottom: " + m.getTop());
                            System.out.println("quantity: " + m.getQuantity());
                            System.out.println("time received: " + f.format(m.getTimeReceived()).toString() + ANSI_RESET);
                            System.out.println("");
                            break;
                    }
                }
            }
        }
        else {
        	System.out.println(ANSI_BLUE + "No orders" +ANSI_RESET);
        }
        MainMenu(server);
    }

    public void SendOrders(UDPServer server){
        try {
            System.out.println(ANSI_BLUE + "Sending Orders" + ANSI_RESET);
            sendOrder.SendLoop();
            startedSendOrders = true;
        } catch (Exception e) {
            e.printStackTrace();
        }
        MainMenu(server);
    }

    private void PrintCompletedOrders(UDPServer server){
        SimpleDateFormat f = new SimpleDateFormat("yyyy-MM-DD HH:mm:ss");
        Order o1 = null;
        System.out.println(ANSI_BLUE + "List of Completed Orders" +ANSI_RESET);
        if (!ordersCompleted.isEmpty()) {
            System.out.println(ordersCompleted.size() + " orders");
            for (int i = 0; i < ordersCompleted.size(); i++) {
                o1 = ordersCompleted.get(i);

                if (o1 != null) {
                    switch (o1.getDo()) {
                        case "U":
                            Unload u = (Unload) o1;
                            System.out.println(ANSI_BLUE + "Order number " + u.getNumber() + " - unload");
                            System.out.println("type: " + u.getType());
                            System.out.println("destination: " + u.getDestination());
                            System.out.println("quantity: " + u.getQuantity());
                            System.out.println("time completed: " + f.format(u.getTimeFinished()).toString() + ANSI_RESET);
                            System.out.println("");
                            break;
                        case "T":
                            Transform t = (Transform) o1;
                            System.out.println(ANSI_BLUE + "Order number " + t.getNumber() + " - transform");
                            System.out.println("from: " + t.getFrom());
                            System.out.println("to: " + t.getTo());
                            System.out.println("quantity: " + t.getQuantity());
                            System.out.println("time completed: " + f.format(t.getTimeFinished()).toString() + ANSI_RESET);
                            System.out.println("");

                            break;
                        case "M":
                            Mount m = (Mount) o1;
                            System.out.println(ANSI_BLUE + "Order number " + m.getNumber() + " - mount");
                            System.out.println("Top: " + m.getBottom());
                            System.out.println("Bottom: " + m.getTop());
                            System.out.println("quantity: " + m.getQuantity());
                            System.out.println("time completed: " + f.format(m.getTimeFinished()).toString() + ANSI_RESET);
                            System.out.println("");
                            break;
                    }
                }
            }
        }
        else {
            System.out.println(ANSI_BLUE + "No orders completed" +ANSI_RESET);
        }
        MainMenu(server);
    }
    }