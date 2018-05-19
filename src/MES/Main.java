package MES;

import Communication.Modbus;
import Communication.UDPServer;
import Communication.SendOrder;

import java.io.IOException;
import java.net.InetAddress;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Vector;
import java.util.concurrent.TimeUnit;

public class Main{

    public static final String ANSI_RED = "\u001B[31m";
    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_BLUE = "\u001B[34m";


    public static Vector<Order> ordersReceived = new Vector<>();
    public static final Modbus modbus = new Modbus();
    public static final SendOrder sendOrder = new SendOrder();
    public static boolean startedUdp = false;


    public static void main(String args[]) throws Exception {

        Main m = new Main();
        UDPServer server = new UDPServer(54321);
        m.MainMenu(server);
    }

    public void MainMenu(UDPServer server){
        Scanner ss = new Scanner(System.in);
        System.out.println(ANSI_RED + "\nChoose an option: " + ANSI_RESET);
        if(!startedUdp) {
            System.out.println("1 - Start UDP");
            String resp = ss.next();
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
        else {
            System.out.println("1 - Check Orders");
            System.out.println("2 - Send Orders");

            String resp = ss.next();
            switch (resp) {
                case "1":
                    CheckOrders(server);
                    break;
                case "2":
                    SendOrders(server);
                    break;
                    default: System.out.println("Wrong option");
                        MainMenu(server);
                        break;
            }
        }
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
        Order o1 = null;
        if (!ordersReceived.isEmpty()){
            o1 = ordersReceived.firstElement();
        }
        if(o1 != null) {
        switch (o1.getDo()){
            case "U":
                Unload u = (Unload)o1;
                System.out.println(ANSI_BLUE + "Order number " + u.getNumber() + " - unload");
                System.out.println("type: " + u.getType());
                System.out.println("destination: " + u.getDestination());
                System.out.println("quantity: " + u.getQuantity() + ANSI_RESET);
                break;
            case "T": Transform t = (Transform)o1;
                System.out.println(ANSI_BLUE + "Order number " + t.getNumber() + " - transform");
                System.out.println("from: " + t.getFrom());
                System.out.println("to: " + t.getTo());
                System.out.println("quantity: " + t.getQuantity() + ANSI_RESET);
                break;
            case "M": Mount m = (Mount)o1;
                System.out.println(ANSI_BLUE + "Order number " + m.getNumber() + " - mount");
                System.out.println("Top: " + m.getBottom());
                System.out.println("Bottom: " + m.getTop());
                System.out.println("quantity: " + m.getQuantity() +ANSI_RESET);
                break;
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
        } catch (Exception e) {
            e.printStackTrace();
        }
        MainMenu(server);
    }

    }