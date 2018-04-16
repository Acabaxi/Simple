package MES;
import java.net.*;
import java.io.*;

import com.sun.org.apache.xpath.internal.operations.Mod;
import net.wimpi.modbus.*;
import net.wimpi.modbus.msg.*;
import net.wimpi.modbus.io.*;
import net.wimpi.modbus.net.*;
import net.wimpi.modbus.util.*;

public class Modbus {
    TCPMasterConnection con = null; //the connection
    ModbusTCPTransaction trans = null; //the transaction
    WriteCoilRequest reqWCoil = null; //the request
    ReadCoilsRequest reqRCoil = null;
    ReadCoilsResponse CoilResp = null;
    int port = 5503;

    public Modbus() {
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
    }
}
