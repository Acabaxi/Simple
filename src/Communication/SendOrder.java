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
    private boolean loop = true;

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

                int i = 0;

                if(i == 0){
                    try {
                        trans = new ModbusTCPTransaction(connect(5503));
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    i = 1;
                }

                while (loop) {
                    //Do stuff :)

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
