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

public class Modbus implements Runnable{
    private TCPMasterConnection con = null; //the connection
    private ModbusTCPTransaction trans = null; //the transaction
    private WriteCoilRequest reqWCoil = null; //the request
    private ReadCoilsRequest reqRCoil = null;
    private ReadCoilsResponse CoilResp = null;

    private boolean running;
    private Thread process, writing, reading;
    private int coilNumber;
    int port = 5503;

    public void run(){
        running = true;
        System.out.println("Modbus server started on port " + port);
    }

    public void connect(int port) throws UnknownHostException, Exception {
        this.port = port;
        InetAddress adr = null; //the slave's address


        try {
            adr = InetAddress.getByName("localhost"); //the slave's address
        } catch (UnknownHostException e){
            e.printStackTrace();
            System.exit(1);
        }

        this.con = new TCPMasterConnection(adr);
        con.setPort(this.port);

        process = new Thread(this, "server_process");
        process.start();

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

    public void WriteCoil(int coilNumber){

    }
}

