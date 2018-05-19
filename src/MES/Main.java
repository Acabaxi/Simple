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
        System.out.println("\nChoose an option: ");
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
            System.out.println("1 - Choose First");
            System.out.println("2 - Send Orders");

            String resp = ss.next();
            switch (resp) {
                case "1":
                    ChooseFirst(server);
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

    public void ChooseFirst(UDPServer server){
        Order o1 = null;
        if (!ordersReceived.isEmpty()){
            o1 = ordersReceived.firstElement();
        }
        if(o1 != null) {
        switch (o1.getDo()){
            case "U":
                System.out.println("here");
                Unload u = (Unload)o1;
                System.out.println("Order number " + u.getNumber() + " - unload");
                System.out.println("type: " + u.getType());
                System.out.println("destination: " + u.getDestination());
                System.out.println("quantity: " + u.getQuantity());
                int quantity = u.getQuantity();
                System.out.println("quantity integer: " + quantity);
                break;
            case "T": Transform t = (Transform)o1;
                System.out.println("Order number " + t.getNumber() + " - transform");
                System.out.println("from: " + t.getFrom());
                System.out.println("to: " + t.getTo());
                System.out.println("quantity: " + t.getQuantity());
                break;
        }
        }
        else {
        	System.out.println("No orders");
        }
        MainMenu(server);
    }

    public void SendOrders(UDPServer server){
        try {
            sendOrder.SendLoop();
        } catch (Exception e) {
            e.printStackTrace();
        }
        MainMenu(server);
    }

    }