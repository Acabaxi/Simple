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
	private ModbusTCPTransaction trans = null; // the transaction
	private WriteCoilRequest unLoadCommand = null; // the request
	private ReadCoilsRequest reqIdleState = null;

	private WriteSingleRegisterRequest unLoadDestination = null;
	private WriteSingleRegisterRequest pieceType = null;
	private WriteSingleRegisterRequest pieceFrom = null;
	private WriteSingleRegisterRequest pieceTo = null;

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
					//Transform transform = null;
					//Unload unLoad = null;
					Order order = null;

					//1 s for line to respond
					try {

						sleep(1000);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
					//Reset coils and registers written
					pieceType = new WriteSingleRegisterRequest();
					pieceType.setReference(0);
					reg.setValue(0);
					pieceType.setRegister(reg);
					trans.setRequest(pieceType);
					try {
						trans.execute();
					} catch (ModbusException e) {
						e.printStackTrace();
					}
					unLoadDestination = new WriteSingleRegisterRequest();
					unLoadDestination.setReference(2);
					reg.setValue(0);
					unLoadDestination.setRegister(reg);
					trans.setRequest(unLoadDestination);
					try {
						trans.execute();
					} catch (ModbusException e) {
						e.printStackTrace();
					}
					unLoadCommand = new WriteCoilRequest(1,false);
					trans.setRequest(unLoadCommand);
					try {
						trans.execute();
					} catch (ModbusException e) {
						e.printStackTrace();
					}

					//1 s for line to respond
					try {

						sleep(1000);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}

					//check if line can receive orders
					reqIdleState = new ReadCoilsRequest(0, 1);
					trans.setRequest(reqIdleState);
					try {
						trans.execute();
					} catch (ModbusException e) {
						e.printStackTrace();
					}

					respIdle = (ReadCoilsResponse)trans.getResponse();
					idle = Integer.parseInt(respIdle.getCoils().toString().trim());

					//if it can receive orders
					if(idle == 0) {
						//Check if there are transform orders on queue to send
						if (!Main.ordersReceived.isEmpty()) {
							//Send transform order based on transform priority (faster orders first)
							order = Main.ordersReceived.get(0);
							if (order.getDo().equals("T")) {
								Transform transform = (Transform) order;


								//1 s for line to respond
								try {

									sleep(1000);
								} catch (InterruptedException e) {
									e.printStackTrace();
								}

								//Register and coil resets
								pieceFrom = new WriteSingleRegisterRequest();
								pieceFrom.setReference(0);
								reg.setValue(0);
								pieceFrom.setRegister(reg);
								trans.setRequest(pieceFrom);
								try {
									trans.execute();
								} catch (ModbusException e) {
									e.printStackTrace();
								}
								pieceTo = new WriteSingleRegisterRequest();
								pieceTo.setReference(3);
								reg.setValue(0);
								pieceTo.setRegister(reg);
								trans.setRequest(pieceTo);
								try {
									trans.execute();
								} catch (ModbusException e) {
									e.printStackTrace();
								}

								String orderFrom = transform.getFrom();
								int valFrom = Integer.parseInt((orderFrom.substring(1)));
								String orderTo = transform.getTo();
								int valTo = Integer.parseInt((orderTo.substring(1)));

								if (transform.getQuantity() > 0) {
									//Write on register to tell what piece to remove from stock
									pieceFrom = new WriteSingleRegisterRequest();
									pieceFrom.setReference(0);
									reg.setValue(valFrom);
									pieceFrom.setRegister(reg);
									trans.setRequest(pieceFrom);
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
									//Write on register to tell what piece to transform into
									pieceTo = new WriteSingleRegisterRequest();
									pieceTo.setReference(3);
									reg.setValue(valTo);
									pieceTo.setRegister(reg);
									trans.setRequest(pieceTo);
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

									//Choose place where to transform Cell 1, 2 or 3

									//decrease quantity
									transform.decreaseQuantity();
									//Remove order if quantity equals zero
									if (transform.getQuantity() == 0) {
										Main.ordersReceived.remove(transform);
									}
									//50 ms for line to respond
									try {

										sleep(50);
									} catch (InterruptedException e) {
										e.printStackTrace();
									}
								}

							}

							//Check if there are unload orders on queue to send
							else if (order.getDo().equals("U")) {
								Unload unLoad = (Unload) order;
								System.out.println("this is unload number " + unLoad.getNumber() + ", quant " + unLoad.getQuantity());

								String orderType = unLoad.getType();
								int valT = Integer.parseInt(orderType.substring(1));
								String destination = unLoad.getDestination();
								int valD = Integer.parseInt(destination.substring(1));
								//Send unLoad order based on stock available

								//Write on register to tell what piece to remove from stock and unLoad
								if (unLoad.getQuantity() > 0) {
									pieceType = new WriteSingleRegisterRequest();
									pieceType.setReference(0);
									reg.setValue(valT);
									pieceType.setRegister(reg);
									trans.setRequest(pieceType);
									try {
										trans.execute();
									} catch (ModbusException e) {
										e.printStackTrace();
									}
									//20 ms for line to respond
									try {

										sleep(20);
									} catch (InterruptedException e) {
										e.printStackTrace();
									}
									//unLoad destination zone PM1 or PM2 or PM3
									unLoadDestination = new WriteSingleRegisterRequest();
									unLoadDestination.setReference(2);
									reg.setValue(valD);
									unLoadDestination.setRegister(reg);
									trans.setRequest(unLoadDestination);
									try {
										trans.execute();
									} catch (ModbusException e) {
										e.printStackTrace();
									}
									//20 ms for line to respond
									try {

										sleep(20);
									} catch (InterruptedException e) {
										e.printStackTrace();
									}
									//Send unLoad command to PLC Boolean
									unLoadCommand = new WriteCoilRequest(1, true);
									trans.setRequest(unLoadCommand);
									try {
										trans.execute();
									} catch (ModbusException e) {
										e.printStackTrace();
									}
									//20 ms for line to respond
									try {

										sleep(20);
									} catch (InterruptedException e) {
										e.printStackTrace();
									}
									unLoad.decreaseQuantity();
									//Remove Order and Send completed time to data base
									if (unLoad.getQuantity() == 0) {
										Main.ordersReceived.remove(unLoad);
									}
								}
							}
						}
					}
				//if it can't receive orders
				else if(idle == 1){
					//Sleep for 5 seconds
					try {
						sleep(5000);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}

			}
		}
	};
	work.start();
}}
