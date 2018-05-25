package Communication;

import MES.*;

import java.io.*;
import java.net.*;
import java.sql.Timestamp;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.*;
import MES.Order;
import Communication.JDBC;

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

    public void listen() throws Exception {
        Parser p = new Parser();
        receive = new Thread("receive_thread") {
            public void run() {
                try {
                    System.out.println(ANSI_BLUE + "-- Running Server UDP at " + InetAddress.getLocalHost() + "--" + ANSI_RESET);
                } catch (UnknownHostException e) {
                    e.printStackTrace();
                }
                String msg;

                while (running) {
                    byte[] buf = new byte[1024];
                    DatagramPacket packet = new DatagramPacket(buf, buf.length);

                    // blocks until a packet is received
                    try {
                        udpSocket.receive(packet);
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    InetAddress IPAddress = packet.getAddress();
                    int portaux = packet.getPort();
                    msg = new String(packet.getData()).trim();
                    Date timeReceived = new Date();
                    String[] splited = msg.split("]>");
                    if (splited.length > 1) {
                        msg = splited[1];
                        if (!msg.isEmpty()) {
                            Parser p = new Parser();
                            Order o = p.parseFile(msg, timeReceived);

                            //Send received order to Data Base
                            //Date current_time = new Date();
                            //SimpleDateFormat formatDB = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                            //Timestamp timestamp = new Timestamp(System.currentTimeMillis());
                            //JDBC.WriteStringToDataBase("INSERT into ordem (id_ordem, estado_ordem, h_ordem) VALUES (" + o.getNumber() +  ",1, " + timestamp + ")");

                            if (o != null) {
                                o.setPending(true);
                                Main.ordersReceived.add(o);
                                Main.sorting.insertionSort(Main.ordersReceived);
                            } else {
                                //Send XML
                                BufferedReader reader = null;
                                //List<String> list = new ArrayList<String>();
                                String list = "";
                                File responseXML = new File("/home/sobaca/Downloads/stores.xml");
                                try {
                                    reader = new BufferedReader(new FileReader(responseXML));
                                    String text;

                                    while ((text = reader.readLine()) != null) {
                                        list += text;
                                    }
                                } catch (FileNotFoundException e) {
                                    e.printStackTrace();
                                } catch (IOException e) {
                                    e.printStackTrace();
                                } finally {
                                    try {
                                        if (reader != null) {
                                            reader.close();
                                        }
                                    } catch (IOException e) {
                                    }
                                }
                                //System.out.println(list);
                                byte[] listBuff = list.getBytes();
                                DatagramPacket sendXML = new DatagramPacket(listBuff, listBuff.length, IPAddress, portaux);
                                try {
                                    udpSocket.send(sendXML);
                                } catch (IOException e) {
                                    e.printStackTrace();
                                }
                            }
                        }
                    }
                }
            }
        };
        receive.start();
    }
}