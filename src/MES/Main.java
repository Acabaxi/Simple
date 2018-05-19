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
    //public static Vector<Unload> unloadReceived = new Vector<>();
    //public static Vector<Transform> transformReceived = new Vector<>();
    public static Vector<Order> ordersReceived = new Vector<>();
    public static final Modbus modbus = new Modbus();
    public static final SendOrder sendOrder = new SendOrder();


    public static void main(String args[]) throws Exception {

        Main m = new Main();
        UDPServer server = new UDPServer(54321);
        m.MainMenu(server);

        //Start UDP connection DONE
        //Receive XML Orders DONE
        //UDP Server working in thread DONE
        //try {
        //        UDPServer server = new UDPServer(54321);
        //        server.listen();
        //} catch (Exception e) {
        //        e.printStackTrace();
        //    }
        //Parse DONE
        //While order received Parse and create object of order type DONE
        //Scheduler FIFO in list
        //Start ModBus connection DONE
        //try {
        //    modbus.connect();
        //} catch (Exception e) {
        //    e.printStackTrace();
        //}
        //Get inventory
        //Update Stock
        //Send Restart Line Command
        //Send Commands
        //Test Code

        /*
        READ COIL TEST CODE

        */


        /*
        while(true){
            try {
                //Write Coil
                mb.reqWCoil = new WriteCoilRequest(0,true);
                mb.trans.setRequest(mb.reqWCoil);
                mb.trans.execute();
                //Read Coil
                mb.reqRCoil = new ReadCoilsRequest(1, 1);
                mb.trans.setRequest(mb.reqRCoil);
                mb.trans.execute();
                mb.CoilResp = (ReadCoilsResponse)mb.trans.getResponse();
                System.out.println("Response : "+mb.CoilResp.getCoils().toString());
            } catch(ModbusException md){
                System.out.println("Failed to send request");
                System.exit(1);
            }
        } */

        //Start scheduler for orders
        //Define commands to send to PLC

        //Send Commands
        //Receive command completed response

        //Connect to Data Base
        //Upload relevant info to Data Base
    }

    public void MainMenu(UDPServer server){
        Scanner ss = new Scanner(System.in);
        System.out.println("\nChoose an option: ");
        System.out.println("1 - Start UDP");
        System.out.println("2 - Choose First");
        System.out.println("3 - Send Orders");

        String resp = ss.next();
        switch (resp) {
            case "1":
                ControlUDP(server);
                break;
            case "2":
                ChooseFirst(server);
                break;
            case "3":
                SendOrders(server);
                break;
        }
    }
    public void ControlUDP(UDPServer server){
        try {
            server.listen();
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