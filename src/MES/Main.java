package MES;

import Communication.Modbus;
import Communication.UDPServer;

import java.util.LinkedList;
import java.util.Queue;
import java.util.concurrent.TimeUnit;

public class Main{
    public static Queue<Order> ordersReceived= new LinkedList<Order>();
    public static final Modbus modbus = new Modbus();

    public static void main(String args[]){

        //Start UDP connection DONE
        //Receive XML Orders DONE
        //UDP Server working in thread DONE
        boolean check = false;
        try {
                UDPServer server = new UDPServer(54321);
                server.listen();
        } catch (Exception e) {
                e.printStackTrace();
            }
        //Parse DONE
        //While order received Parse and create object of order type DONE

        //Start ModBus connection DONE
        try {
            modbus.connect();
        } catch (Exception e) {
            e.printStackTrace();
        }
        //Get inventory
        //Update Stock
        //Send Restart Line Command

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
}