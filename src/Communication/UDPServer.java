package Communication;

import MES.*;

import java.io.IOException;
import java.net.*;
import java.util.*;

public class UDPServer implements Runnable{
    public static final String ANSI_BLUE = "\u001B[34m";
    public static final String ANSI_RESET = "\u001B[0m";
    private static DatagramSocket udpSocket;
    private static int port;
    private boolean running;

    private Thread receive, process;

    public void run() {
        running = true;
    }

    public void notRunning(){
        running = false;
        System.out.println("Server closed");
    }

    //Initialize Server
    public UDPServer(int port) throws IOException {
        this.port = port;
        this.udpSocket = new DatagramSocket(this.port);
        process = new Thread(this, "server_process");
        process.start();
    }

    public void close(){
        close();
    }

    public static void send(){
        try {
            byte[] message = "Send packet test".getBytes();

            // Get the internet address of the specified host
            InetAddress address = InetAddress.getLocalHost();

            // Initialize a datagram packet with data and address
            DatagramPacket packet = new DatagramPacket(message, message.length,
                    address, port);

            // Create a datagram socket, send the packet through it, close it.
            udpSocket.send(packet);
        } catch (Exception e) {
            System.err.println(e);
        }
    }

    public void listen() throws Exception {
        Parser p = new Parser();
        receive = new Thread("receive_thread"){
        public void run() {
            try {
                System.out.println(ANSI_BLUE + "-- Running Server UDP at " + InetAddress.getLocalHost() + "--" + ANSI_RESET);
            } catch (UnknownHostException e) {
                e.printStackTrace();
            }
            String msg;

            while(running) {
                byte[] buf = new byte[1024];
                DatagramPacket packet = new DatagramPacket(buf, buf.length);

                // blocks until a packet is received
                try {
                    udpSocket.receive(packet);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                msg = new String(packet.getData()).trim();
                Date timeReceived = new Date();
                msg = msg.split("]>")[1];
                Parser p = new Parser();
                Order o = p.parseFile(msg, timeReceived);
                if(o != null) Main.ordersReceived.add(o);
                //Order o1 = Main.ordersReceived.peek();
                //System.out.println("heeeeey! we parsed order number " + o1.getNumber());
                //System.out.println("Message from " + packet.getAddress().getHostAddress() + ": " + msg2);
                //System.out.println("Message from " + packet.getAddress().getHostAddress() + ": " + msg);
            }
                  }
        };
        receive.start();
    }
}