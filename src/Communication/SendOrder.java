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
    private WriteCoilRequest WCoil1 = null; //the request
    private WriteCoilRequest WCoil2 = null; //the request
    private ReadCoilsRequest reqRCoilIdle1 = null;
    private ReadCoilsRequest reqRCoilIdle2 = null;

    private ReadCoilsResponse CoilRespIdle1 = null;
    private ReadCoilsResponse CoilRespIdle2 = null;

    private int idle1 = 0;
    private int idle2 = 0;


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

                if(i == 0){ //for what?
                    try {
                        trans = new ModbusTCPTransaction(connect(5503));
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    i = 1; //just try/catch doesn't work? what are you trying to do? maybe you wanted 'while'?
                }
                
                

                while (loop) { //why not just while(true) ??? 
                    //Do stuff :)
                	Transform t = null;
                	Unload u = null;
                	//get first orders of each type
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
                		Main.transformReceived.remove(t);
                	}
                	else if (u != null) { //if we don't have any transform order, check if we have unload
                		//send this order
                		//remove after sending
                		Main.unloadReceived.remove(u);
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
                	

                    //Request State on idle status
                    coilNumber = 0;
                    reqRCoilIdle1 = new ReadCoilsRequest(coilNumber, 1);
                    trans.setRequest(reqRCoilIdle1);
                    try {
                        trans.execute();
                    } catch (ModbusException e) {
                        e.printStackTrace();
                    }
                    CoilRespIdle1 = (ReadCoilsResponse)trans.getResponse();
                    idle1 = Integer.parseInt(CoilRespIdle1.getCoils().toString().trim());

                    if(i==1) {
                        System.out.println("Result of boolean Idle1 part one: " + idle1);
                        i = 2;
                    }

                    if(idle1 == 1){
                        WCoil1 = new WriteCoilRequest(1, true);
                        trans.setRequest(WCoil1);
                        try {
                            trans.execute();
                        } catch (ModbusException e) {
                            e.printStackTrace();
                        }
                        try {
                            sleep(50);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                        trans.setRequest(reqRCoilIdle1);
                        try {
                            trans.execute();
                        }
                        catch (ModbusException e) {
                            e.printStackTrace();
                        }
                        CoilRespIdle1 = (ReadCoilsResponse)trans.getResponse();
                        idle1 = Integer.parseInt(CoilRespIdle1.getCoils().toString().trim());
                        System.out.println("Result of boolean Idle1 part two: " +idle1);
                    }
                }
            }
        };
        work.start();
    }
}
