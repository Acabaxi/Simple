package com.company;
import java.net.*;
import java.io.*;


import com.sun.org.apache.xpath.internal.operations.Mod;
import net.wimpi.modbus.*;
import net.wimpi.modbus.msg.*;
import net.wimpi.modbus.io.*;
import net.wimpi.modbus.net.*;
import net.wimpi.modbus.util.*;

public class Main{

    /*
    static LinearConveyor T1 = new LinearConveyor(0,1,0);
    LinearConveyor T2 = new LinearConveyor(2,3,1);
    LinearConveyor T3 = new LinearConveyor(4,5,2);
    */


    public static void main(String args[]){

        //T1.moveBack();

        //Comentado até haver ficheiro XML
        //Parser.parseXML();

        /* The important instances of the classes mentioned before */
        TCPMasterConnection con = null; //the connection
        ModbusTCPTransaction trans = null; //the transaction
        WriteCoilRequest reqWCoil = null; //the request
        ReadCoilsRequest reqRCoil = null;
        ReadCoilsResponse CoilResp = null;

        InetAddress addr = null; //the slave's address
        try {
            addr = InetAddress.getByName("localhost"); //the slave's address
        } catch (UnknownHostException e){
            e.printStackTrace();
            System.exit(1);
        }

        System.out.println(addr.getHostName()+ "  "+addr.getHostAddress());

        int port = 5503;

        //Not used yet
        int ref = 0; //the reference; offset where to start reading from
        int count = 0; //the number of DI's to read

        con = new TCPMasterConnection(addr);
        con.setPort(port);

        System.out.println(con.getPort());

        try {
            con.connect();
        } catch(Exception langException){

            System.out.println("Failed to connect");
            langException.printStackTrace();
            System.exit(1);
        }

        trans = new ModbusTCPTransaction(con);

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

        }


    }

}