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


    public static void main(String args[]){

        /* The important instances of the classes mentioned before */
        TCPMasterConnection con = null; //the connection
        ModbusTCPTransaction trans = null; //the transaction
        WriteCoilRequest req = null; //the request
        ReadInputDiscretesResponse res = null; //the response


        InetAddress addr = null; //the slave's address
        try {
            addr = InetAddress.getByName("localhost"); //the slave's address
        } catch (UnknownHostException e){
            e.printStackTrace();
            System.exit(1);
        }

        System.out.println(addr.getHostName()+ "  "+addr.getHostAddress());

        int port = 5502;
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


        int i;
        for(i=1 ;i < 10; i+=2){
            try {
                req = new WriteCoilRequest(i,true);
                trans.setRequest(req);
                trans.execute();
                System.out.println(i);
            } catch(ModbusException md){
                System.out.println("Failed to send request");
                System.exit(1);
            }
        }


    }

}
