package Communication;

import MES.*;
import net.wimpi.modbus.ModbusException;
import net.wimpi.modbus.io.ModbusTCPTransaction;
import net.wimpi.modbus.msg.ReadCoilsRequest;
import net.wimpi.modbus.msg.ReadCoilsResponse;
import net.wimpi.modbus.msg.WriteCoilRequest;
import net.wimpi.modbus.msg.WriteSingleRegisterRequest;
import net.wimpi.modbus.net.TCPMasterConnection;
import net.wimpi.modbus.procimg.SimpleRegister;

import java.io.IOException;
import java.net.*;
import java.util.*;

public class SendOrder extends Modbus implements Runnable {
    private ModbusTCPTransaction trans = null; //the transaction
    private WriteCoilRequest unLoadCommand = null; //the request
    private ReadCoilsRequest reqIdleState = null;

    private WriteSingleRegisterRequest unLoadDestination = null;
    private WriteSingleRegisterRequest pieceType = null;

    private SimpleRegister reg = new SimpleRegister(0);

    private ReadCoilsResponse respIdle = null;

    private int idle = 0;

    private boolean runningOrders;

    private Thread work;

    public void run() {
        runningOrders = true;
        System.out.println("Thread Send Order check");
    }

    public void SendLoop() {
        work = new Thread("receive_thread") {
            public void run() {
                System.out.println("Sending Orders");

                try {
                    trans = new ModbusTCPTransaction(connect(5503));
                } catch (Exception e) {
                    e.printStackTrace();
                }

                while (true) {
                    //Do stuff :)
                	Transform transform = null;
                	Unload unLoad = null;

                	//check if line can receive orders
                    reqIdleState = new ReadCoilsRequest(0, 1);
                    trans.setRequest(reqIdleState);
                    try {
                        trans.execute();
                    } catch (ModbusException e) {
                        e.printStackTrace();
                    }
                    //50 ms for line to respond
                    try {

                        sleep(50);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    respIdle = (ReadCoilsResponse)trans.getResponse();
                    idle = Integer.parseInt(respIdle.getCoils().toString().trim());

                    //if it can receive orders
                    if(idle == 0){
                        //Check if there are transform orders on queue to send
                        if(Main.transformReceived != null){
                            //Send transform order based on transform priority (faster orders first)
                        }
                        //Check if there are unload orders on queue to send
                        if(Main.unloadReceived != null){
                            unLoad = Main.unloadReceived.get(0);
                            //Send unLoad order based on stock available

                            //Write on register to tell what piece to remove from stock and unLoad
                            if(unLoad.getType().equals("P1") && unLoad.getQuantity() > 0){
                                pieceType = new WriteSingleRegisterRequest();
                                pieceType.setReference(0);
                                reg.setValue(1);
                                pieceType.setRegister(reg);
                                trans.setRequest(pieceType);
                                try {
                                    trans.execute();
                                } catch (ModbusException e) {
                                    e.printStackTrace();
                                }
                                //50 ms for line to respond
                                try {

                                    sleep(50);
                                } catch (InterruptedException e) {
                                    e.printStackTrace();
                                }
                                //unLoad destination zone PM1 or PM2 or PM3
                                if(unLoad.getDestination().equals("D1")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(1);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if(unLoad.getDestination().equals("D2")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(2);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if(unLoad.getDestination().equals("D3")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(3);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                            }
                            if(unLoad.getType().equals("P2")  && unLoad.getQuantity() > 0){
                                pieceType = new WriteSingleRegisterRequest();
                                pieceType.setReference(0);
                                reg.setValue(2);
                                pieceType.setRegister(reg);
                                trans.setRequest(pieceType);
                                try {
                                    trans.execute();
                                } catch (ModbusException e) {
                                    e.printStackTrace();
                                }
                                //50 ms for line to respond
                                try {

                                    sleep(50);
                                } catch (InterruptedException e) {
                                    e.printStackTrace();
                                }
                                //unLoad destination zone PM1 or PM2 or PM3
                                if(unLoad.getDestination().equals("D1")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(1);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if(unLoad.getDestination().equals("D2")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(2);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if(unLoad.getDestination().equals("D3")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(3);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                            }
                            if(unLoad.getType().equals("P3")  && unLoad.getQuantity() > 0){
                                pieceType = new WriteSingleRegisterRequest();
                                pieceType.setReference(0);
                                reg.setValue(3);
                                pieceType.setRegister(reg);
                                trans.setRequest(pieceType);
                                try {
                                    trans.execute();
                                } catch (ModbusException e) {
                                    e.printStackTrace();
                                }
                                //50 ms for line to respond
                                try {

                                    sleep(50);
                                } catch (InterruptedException e) {
                                    e.printStackTrace();
                                }
                                //unLoad destination zone PM1 or PM2 or PM3
                                if(unLoad.getDestination().equals("D1")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(1);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if(unLoad.getDestination().equals("D2")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(2);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if(unLoad.getDestination().equals("D3")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(3);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                            }
                            if(unLoad.getType().equals("P4")  && unLoad.getQuantity() > 0){
                                pieceType = new WriteSingleRegisterRequest();
                                pieceType.setReference(0);
                                reg.setValue(4);
                                pieceType.setRegister(reg);
                                trans.setRequest(pieceType);
                                try {
                                    trans.execute();
                                } catch (ModbusException e) {
                                    e.printStackTrace();
                                }
                                //50 ms for line to respond
                                try {

                                    sleep(50);
                                } catch (InterruptedException e) {
                                    e.printStackTrace();
                                }
                                //unLoad destination zone PM1 or PM2 or PM3
                                if(unLoad.getDestination().equals("D1")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(1);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if(unLoad.getDestination().equals("D2")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(2);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if(unLoad.getDestination().equals("D3")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(3);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                            }
                            if(unLoad.getType().equals("P5")  && unLoad.getQuantity() > 0){
                                pieceType = new WriteSingleRegisterRequest();
                                pieceType.setReference(0);
                                reg.setValue(5);
                                pieceType.setRegister(reg);
                                trans.setRequest(pieceType);
                                try {
                                    trans.execute();
                                } catch (ModbusException e) {
                                    e.printStackTrace();
                                }
                                //50 ms for line to respond
                                try {

                                    sleep(50);
                                } catch (InterruptedException e) {
                                    e.printStackTrace();
                                }
                                //unLoad destination zone PM1 or PM2 or PM3
                                if(unLoad.getDestination().equals("D1")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(1);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if(unLoad.getDestination().equals("D2")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(2);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if(unLoad.getDestination().equals("D3")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(3);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                            }
                            if(unLoad.getType().equals("P6")  && unLoad.getQuantity() > 0){
                                pieceType = new WriteSingleRegisterRequest();
                                pieceType.setReference(0);
                                reg.setValue(6);
                                pieceType.setRegister(reg);
                                trans.setRequest(pieceType);
                                try {
                                    trans.execute();
                                } catch (ModbusException e) {
                                    e.printStackTrace();
                                }
                                //50 ms for line to respond
                                try {

                                    sleep(50);
                                } catch (InterruptedException e) {
                                    e.printStackTrace();
                                }
                                //unLoad destination zone PM1 or PM2 or PM3
                                if(unLoad.getDestination().equals("D1")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(1);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if(unLoad.getDestination().equals("D2")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(2);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    System.out.println(unLoad.getQuantity());
                                    unLoad.decreaseQuantity();
                                    System.out.println(unLoad.getQuantity());
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if(unLoad.getDestination().equals("D3")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(3);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                            }
                            if(unLoad.getType().equals("P7")  && unLoad.getQuantity() > 0){
                                pieceType = new WriteSingleRegisterRequest();
                                pieceType.setReference(0);
                                reg.setValue(7);
                                pieceType.setRegister(reg);
                                trans.setRequest(pieceType);
                                try {
                                    trans.execute();
                                } catch (ModbusException e) {
                                    e.printStackTrace();
                                }
                                //50 ms for line to respond
                                try {

                                    sleep(50);
                                } catch (InterruptedException e) {
                                    e.printStackTrace();
                                }
                                //unLoad destination zone PM1 or PM2 or PM3
                                if(unLoad.getDestination().equals("D1")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(1);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if(unLoad.getDestination().equals("D2")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(2);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if(unLoad.getDestination().equals("D3")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(3);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                            }
                            if(unLoad.getType().equals("P8")  && unLoad.getQuantity() > 0){
                                pieceType = new WriteSingleRegisterRequest();
                                pieceType.setReference(0);
                                reg.setValue(8);
                                pieceType.setRegister(reg);
                                trans.setRequest(pieceType);
                                try {
                                    trans.execute();
                                } catch (ModbusException e) {
                                    e.printStackTrace();
                                }
                                //50 ms for line to respond
                                try {

                                    sleep(50);
                                } catch (InterruptedException e) {
                                    e.printStackTrace();
                                }
                                //unLoad destination zone PM1 or PM2 or PM3
                                if(unLoad.getDestination().equals("D1")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(1);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if(unLoad.getDestination().equals("D2")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(2);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if(unLoad.getDestination().equals("D3")){
                                    unLoadDestination = new WriteSingleRegisterRequest();
                                    unLoadDestination.setReference(2);
                                    reg.setValue(3);
                                    unLoadDestination.setRegister(reg);
                                    trans.setRequest(unLoadDestination);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    //Send unLoad command to PLC Boolean
                                    unLoadCommand = new WriteCoilRequest(1,true);
                                    trans.setRequest(unLoadCommand);
                                    try {
                                        trans.execute();
                                    } catch (ModbusException e) {
                                        e.printStackTrace();
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    unLoad.decreaseQuantity();
                                    //Remove Order and Send completed time to data base
                                    if(unLoad.getQuantity() == 0){
                                        Main.unloadReceived.remove(unLoad);
                                    }
                                    //50 ms for line to respond
                                    try {

                                        sleep(50);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                }
                            }
                        }
                    }

                    //if it can't receive orders
                    else if(idle == 1){
                        //Sleep for 5 seconds
                        try {
                            sleep(500);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }

                }
            }
        };
        work.start();
    }
}
