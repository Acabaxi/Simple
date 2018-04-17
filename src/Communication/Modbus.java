package Communication;
import java.net.*;
import java.io.*;

import com.sun.org.apache.xpath.internal.operations.Mod;
import net.wimpi.modbus.*;
import net.wimpi.modbus.msg.*;
import net.wimpi.modbus.io.*;
import net.wimpi.modbus.net.*;
import net.wimpi.modbus.util.*;
import net.wimpi.modbus.procimg.*;

public class Modbus {
    private TCPMasterConnection con = null; //the connection
    private ModbusTCPTransaction trans = null; //the transaction
    /*
    private WriteCoilRequest reqWCoil = null; //the request
    private ReadCoilsRequest reqRCoil = null;
    private ReadCoilsResponse CoilResp = null;
    */
    int port = 5503;


    public void connect() throws UnknownHostException, Exception {
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
    public void close() {
        con.close();
    }
}

