package MES;

import java.io.IOException;
import java.net.*;

public class UDPServer implements Runnable{
    private DatagramSocket udpSocket;
    private int port;
    private boolean running;

    private Thread receive, process;

    public void run() {
        running = true;
        System.out.println("Server started on port " + port);
    }

    //Initialize Server
    public UDPServer(int port) throws IOException {
        this.port = port;
        this.udpSocket = new DatagramSocket(this.port);
        process = new Thread(this, "server_process");
        process.start();
    }

    public void listen() throws Exception {
        receive = new Thread("receive_thread"){
        public void run() {
            try {
                System.out.println("-- Running Server at " + InetAddress.getLocalHost() + "--");
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
                Parser p = new Parser();
                msg = msg.split("([?>]\"?>)")[2];
                Order newOrder = p.parseFile(msg);
                //System.out.println("Message from " + packet.getAddress().getHostAddress() + ": " + msg2);
                //System.out.println("Message from " + packet.getAddress().getHostAddress() + ": " + msg);
            }
            }
        };
        receive.start();
    }
}