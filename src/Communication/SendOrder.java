package Communication;

import MES.*;
import net.wimpi.modbus.ModbusException;
import net.wimpi.modbus.io.ModbusTCPTransaction;
import net.wimpi.modbus.msg.ReadCoilsRequest;
import net.wimpi.modbus.msg.ReadCoilsResponse;
import net.wimpi.modbus.msg.WriteCoilRequest;
import net.wimpi.modbus.net.TCPMasterConnection;

import java.io.IOException;
import java.net.*;
import java.util.Vector;

public class SendOrder extends Modbus implements Runnable {
    private ModbusTCPTransaction trans = null; //the transaction
    private WriteCoilRequest WCoil = null; //the request
    private ReadCoilsRequest reqRCoilIdle = null;
    private ReadCoilsRequest reqRCoilCompleteTransform = null;

    private ReadCoilsResponse CoilRespIdle = null;
    private ReadCoilsResponse CoilRespCompleteTransform = null;

    private int idle = 0;
    private int i = 0;
    private int quantity = 0;

    private boolean runningOrders;
    private boolean loop = true; //stop creating useless trash xD 

    private Thread work;
    private int coilNumber;

    public void run() {
        runningOrders = true;
        System.out.println("Thread Send Order check");
    }

    public void SendLoop() {
        work = new Thread("receive_thread") {
            public void run() {
                System.out.println("Sending Orders");

                int i = 0; //why?

                try {
                    trans = new ModbusTCPTransaction(connect(5503));
                } catch (Exception e) {
                    e.printStackTrace();
                }

                while (true) { //why not just while(true) ???
                    //Do stuff :)
                	Transform t = null;
                	Unload u = null;
                	//get first orders of each type

                    //Check if idle ie available to receive orders
                    coilNumber = 0;
                    reqRCoilIdle = new ReadCoilsRequest(coilNumber, 1);
                    trans.setRequest(reqRCoilIdle);
                    try {
                        trans.execute();
                    } catch (ModbusException e) {
                        e.printStackTrace();
                    }
                    CoilRespIdle = (ReadCoilsResponse)trans.getResponse();
                    idle = Integer.parseInt(CoilRespIdle.getCoils().toString().trim());
                    try {
                        sleep(30);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }

                    if(idle == 1) {
                        if (!Main.transformReceived.isEmpty()) {
                            t = Main.transformReceived.get(0);
                        }
                        if (!Main.unloadReceived.isEmpty()) {
                            u = Main.unloadReceived.get(0);
                        }
                        //if we have transform
                        if (t != null) {
                            //send this order or do what you need
                            //remove after sending
                            if(i == 0) {
                                quantity = Integer.parseInt(t.getQuantity());
                                i = 1;
                            }
                            if(quantity >= 0){
                                WCoil = new WriteCoilRequest(1, true);
                                trans.setRequest(WCoil);
                                try {
                                    trans.execute();
                                } catch (ModbusException e) {
                                    e.printStackTrace();
                                }

                                try {
                                    sleep(30);
                                } catch (InterruptedException e) {
                                    e.printStackTrace();
                                }


                                coilNumber = 2;
                                reqRCoilCompleteTransform = new ReadCoilsRequest(coilNumber, 1);
                                trans.setRequest(reqRCoilCompleteTransform);
                                try {
                                    trans.execute();
                                } catch (ModbusException e) {
                                    e.printStackTrace();
                                }
                                CoilRespCompleteTransform = (ReadCoilsResponse)trans.getResponse();
                                int complete = Integer.parseInt(CoilRespCompleteTransform.getCoils().toString().trim());
                                System.out.println("Result of boolean complete: " + complete);
                                try {
                                    sleep(30);
                                } catch (InterruptedException e) {
                                    e.printStackTrace();
                                }

                                if(complete == 1) {
                                    quantity = quantity - 1;
                                    System.out.println("Result of int quantity: " + quantity);
                                }
                            }
                            if(quantity == 0) {
                                Main.transformReceived.remove(t);
                                i = 0;
                                //Add time stamp;
                                //Send to data base completed order
                            }

                            try {
                                sleep(30);
                            } catch (InterruptedException e) {
                                e.printStackTrace();
                            }

                        } else if (u != null) { //if we don't have any transform order, check if we have unload
                            //send this order
                            //remove after sending
                            Main.unloadReceived.remove(u);
                        }
                    }
                	
                	/* if you will need orders after sending then it's better to create other vectors 
                	 * and put them there after sending. You can create them in this class or in Main (probably better), wherever you want
                	 * something like this:
                	 * 
                	 * public static Vector<Unload> unloadSent = new Vector<>();
                	 * public static Vector<Transform> transformSent = new Vector<>();
                	 * 
                	 * and then after sending order you first put it to another vector and then remove:
                	 * 
                	 * Main.transformSent.add(t);
                	 * Main.transformReceived.remove(t);
                	 *  */

                }
            }
        };
        work.start();
    }
}
