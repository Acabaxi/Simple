package Communication;

import MES.*;
import net.wimpi.modbus.ModbusException;
import net.wimpi.modbus.io.ModbusTCPTransaction;
import net.wimpi.modbus.msg.ReadCoilsRequest;
import net.wimpi.modbus.msg.ReadCoilsResponse;
import net.wimpi.modbus.msg.WriteCoilRequest;

import java.io.IOException;
import java.net.*;

public class SendOrder extends Modbus implements Runnable {
    private ModbusTCPTransaction trans = null; //the transaction
    private WriteCoilRequest WCoil = null; //the request
    private ReadCoilsRequest reqRCoilIdle = null;
    private ReadCoilsResponse CoilRespIdle = null;
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

                while (loop) {
                    //Do stuff :)

                    //Request State on idle status
                    coilNumber = 1;
                    reqRCoilIdle = new ReadCoilsRequest(coilNumber, 1);
                    trans.setRequest(reqRCoilIdle);
                    try {
                        trans.execute();
                    } catch (ModbusException e) {
                        e.printStackTrace();
                    }

                    CoilRespIdle = (ReadCoilsResponse)trans.getResponse();
                    Boolean idle = Boolean.parseBoolean(CoilRespIdle.getCoils().toString());
                    System.out.println("Result of boolean Idle: " +idle);
                    /*
                    if(idle){
                        //Check For Transform able to receive coil

                        //Check For UnLoad able to receive coil
                    } */
                }
            }
        };
        work.start();
    }
}
