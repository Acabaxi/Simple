package MES;

import Communication.Modbus;
import Communication.UDPServer;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class Main{
    public static Queue<Order> ordersReceived= new LinkedList<Order>();
    public static final Modbus modbus = new Modbus();

    public static void main(String args[]){

        Main m = new Main();
        m.MainMenu();

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

    public void MainMenu(){
        Scanner ss = new Scanner(System.in);
        System.out.println("\nChoose an option: ");
        System.out.println("1 - Start UDP");
        System.out.println("2 - Check next order");
        System.out.println("3 - Start ModBus");
        String resp = ss.next();
        switch (resp){
            case "1": StartUDP();
            break;
            case "2": CheckFirst();
            break;
            case "3": StartModBus();
        }
    }

    public void StartUDP(){
        try {
            UDPServer server = new UDPServer(54321);
            server.listen();
        } catch (Exception e) {
            e.printStackTrace();
        }
        MainMenu();
    }

    public void StartModBus(){
        try {
            modbus.connect();
        } catch (Exception e) {
            e.printStackTrace();
        }
        MainMenu();
    }

    public void CheckFirst(){
        Order o1 = ordersReceived.poll();
        switch (o1.getDo()){
            case "U":
                System.out.println("here");
                Unload u = (Unload)o1;
                System.out.println("Order number " + u.getNumber() + " - unload");
                System.out.println("type: " + u.getType());
                System.out.println("destination: " + u.getDestination());
                System.out.println("quantity: " + u.getQuantity());
                break;
            case "T": Transform t = (Transform)o1;
                System.out.println("Order number " + t.getNumber() + " - transform");
                System.out.println("from: " + t.getFrom());
                System.out.println("to: " + t.getTo());
                System.out.println("quantity: " + t.getQuantity());
                break;
            case "L": Load l = (Load)o1;
                System.out.println("Order number " + l.getNumber() + " - load");
                System.out.println("type: " + l.getType());
                System.out.println("from: " + l.getFrom());
                System.out.println("quantity: " + l.getQuantity());
                break;
        }
        MainMenu();
    }
}