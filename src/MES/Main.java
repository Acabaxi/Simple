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
                UDPServer server = new UDPServer(54322);
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
        //Get inventory
        //Update Stock
        //Send Restart Line Command

        //Start scheduler for orders
        //Define commands to send to PLC

        //Send Commands
        //Receive command completed response

        //Connect to Data Base
        //Upload relevant info to Data Base

        /*
        // Important variables and Objects
        TCPMasterConnection con = null; //the connection
        ModbusTCPTransaction trans = null; //the transaction
        WriteCoilRequest reqWCoil = null; //the request
        ReadCoilsRequest reqRCoil = null;
        ReadCoilsResponse CoilResp = null;
        int port = 5503;

        InetAddress addr = null; //the slave's address
        try {
            addr = InetAddress.getByName("localhost"); //the slave's address
        } catch (UnknownHostException e){
            e.printStackTrace();
            System.exit(1);
        }

        con = new TCPMasterConnection(addr);
        con.setPort(port);

        try {
            con.connect();
        } catch(Exception langException){

            System.out.println("Failed to connect");
            langException.printStackTrace();
            System.exit(1);
        }

        trans = new ModbusTCPTransaction(con);

        // Print address and port number used
        System.out.println(addr.getHostName()+ "  "+addr.getHostAddress());
        System.out.println(con.getPort());

        // Test code to write and read coils
        while(true){
            try {
                //Write Coil
                reqWCoil = new WriteCoilRequest(0,true);
                trans.setRequest(reqWCoil);
                trans.execute();
                //Read Coil
                reqRCoil = new ReadCoilsRequest(1, 1);
                trans.setRequest(reqRCoil);
                trans.execute();
                CoilResp = (ReadCoilsResponse)trans.getResponse();
                System.out.println("Response : "+CoilResp.getCoils().toString());
            } catch(ModbusException md){
                System.out.println("Failed to send request");
                System.exit(1);
            }

        }  */
    }
}