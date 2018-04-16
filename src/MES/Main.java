package MES;
import java.net.*;
import java.io.*;

import com.sun.org.apache.xpath.internal.operations.Mod;
import net.wimpi.modbus.*;
import net.wimpi.modbus.msg.*;
import net.wimpi.modbus.io.*;
import net.wimpi.modbus.net.*;
import net.wimpi.modbus.util.*;

public class Main{

    public static void main(String args[]){

        //Start UDP connection
        //Receive XML Orders
        //UDP Server working in thread
        try {
                UDPServer server = new UDPServer(54321);
                server.listen();
            } catch (IOException e) {
                e.printStackTrace();
            } catch (Exception e) {
                e.printStackTrace();
            }

        //Parse
        //While order received Parse and create object of order type
        //Parser p = new Parser();
        //Order newOrder = p.parseFile("/home/sobaca/Documents/XMLFiles/Command.xml");
        //Start ModBus connection
        //Modbus mb = new Modbus();
        //mb.trans = new ModbusTCPTransaction(mb.con);

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