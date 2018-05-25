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
    private TCPMasterConnection con; //the connection

    int port = 5503;

    public TCPMasterConnection connect(int port) throws UnknownHostException, Exception {
        this.port = port;
        InetAddress adr = null; //the slave's address
        try {
            adr = InetAddress.getByName("127.0.0.1"); //the slave's address
        } catch (UnknownHostException e){
            e.printStackTrace();
            System.exit(1);
        }
        this.con = new TCPMasterConnection(adr);
        con.setPort(this.port);

        try {
            con.connect();
        } catch(Exception langException){
            System.out.println("Failed to connect");
            langException.printStackTrace();
            System.exit(1);
        }
        return con;
    }
    public TCPMasterConnection getCon() {
        return con;
    }
}

