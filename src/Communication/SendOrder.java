package Communication;

import MES.*;
import net.wimpi.modbus.ModbusException;
import net.wimpi.modbus.io.ModbusTCPTransaction;
import net.wimpi.modbus.msg.*;
import net.wimpi.modbus.net.TCPMasterConnection;
import net.wimpi.modbus.procimg.SimpleRegister;

import java.awt.*;
import java.io.IOException;
import java.net.*;
import java.util.*;

public class SendOrder extends Modbus implements Runnable {
	public static final String ANSI_BLUE = "\u001B[34m";
	public static final String ANSI_RESET = "\u001B[0m";

	private ModbusTCPTransaction trans = null; // the transaction
	private WriteCoilRequest unLoadCommand = null; // the request
	private WriteCoilRequest runCell1 = null;
	private WriteCoilRequest runCell2 = null;
	private WriteCoilRequest runCell3 = null;
	private WriteCoilRequest claw = null;

	private ReadCoilsRequest reqIdleState = null;
	private ReadCoilsRequest reqCell1State = null;
	private ReadCoilsRequest reqCell2State = null;
	private ReadCoilsRequest reqCell3State = null;

	private ReadCoilsRequest reqLoadP1 = null;
	private ReadCoilsRequest reqLoadP2 = null;
	private ReadCoilsResponse resLoadP1 = null;
	private ReadCoilsResponse resLoadP2 = null;
	private int loadP1 = 0;
	private int reLoadP1 = 0;
	private int loadP2 = 0;
	private int reLoadP2 = 0;


	private WriteSingleRegisterRequest unLoadDestination = null;
	private WriteSingleRegisterRequest pieceType = null;
	private WriteSingleRegisterRequest pieceFrom = null;
	private WriteSingleRegisterRequest pieceBottom = null;
	private WriteSingleRegisterRequest pieceTop = null;
	private WriteSingleRegisterRequest pieceTo = null;

	private SimpleRegister reg = new SimpleRegister(0);

	private ReadCoilsResponse respIdle = null;
	private ReadCoilsResponse respCell1State = null;
	private ReadCoilsResponse respCell2State = null;
	private ReadCoilsResponse respCell3State = null;


	private int idle = 0;

	private boolean runningOrders;

	private Thread work;

	public void run() {
		runningOrders = true;
		System.out.println("Thread Send Order check");
	}

	public void reset() {
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
		unLoadCommand = new WriteCoilRequest(1, false);
		trans.setRequest(unLoadCommand);
		try {
			trans.execute();
		} catch (ModbusException e) {
			e.printStackTrace();
		}
		pieceBottom = new WriteSingleRegisterRequest();
		pieceBottom.setReference(0);
		reg.setValue(0);
		pieceBottom.setRegister(reg);
		trans.setRequest(pieceBottom);
		try {
			trans.execute();
		} catch (ModbusException e) {
			e.printStackTrace();
		}
		pieceTop = new WriteSingleRegisterRequest();
		pieceBottom.setReference(1);
		reg.setValue(0);
		pieceTop.setRegister(reg);
		trans.setRequest(pieceTop);
		try {
			trans.execute();
		} catch (ModbusException e) {
			e.printStackTrace();
		}
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
		runCell1 = new WriteCoilRequest(2, false);
		trans.setRequest(runCell1);
		try {
			trans.execute();
		} catch (ModbusException e) {
			e.printStackTrace();
		}
		runCell2 = new WriteCoilRequest(3, false);
		trans.setRequest(runCell2);
		try {
			trans.execute();
		} catch (ModbusException e) {
			e.printStackTrace();
		}
		runCell3 = new WriteCoilRequest(4, false);
		trans.setRequest(runCell3);
		try {
			trans.execute();
		} catch (ModbusException e) {
			e.printStackTrace();
		}
		claw = new WriteCoilRequest(8, false);
		trans.setRequest(claw);
		try {
			trans.execute();
		} catch (ModbusException e) {
			e.printStackTrace();
		}
	}

	public boolean checkCell(int numberOfCell) {
		int cell = 0;
		reqCell1State = new ReadCoilsRequest(numberOfCell, 1);
		trans.setRequest(reqCell1State);
		try {
			trans.execute();
		} catch (ModbusException e) {
			e.printStackTrace();
		}
		respCell1State = (ReadCoilsResponse) trans.getResponse();
		cell = Integer.parseInt(respCell1State.getCoils().toString().trim());
		if (cell == 0) return true;
		else return false;
	}

	private Order getOrder() {
		Vector<Order> v = Main.ordersReceived;
		Main.sorting.insertionSort(v);
		for (int i = 0; i < v.size(); i++) {
			Order o = v.get(i);
			//if(!Main.sorting.hasPieces(o))
			//continue;
			switch (o.getMachine()) {
				case "no":
					if (!o.getExecuting()) {
						Date d = new Date();
						o.setTimeSent(d);
						o.setExecuting(true);
					}
					return o;
				case "claw":
					if (this.checkCell(8)) {
						if (!o.getExecuting()) {
							Date d = new Date();
							o.setTimeSent(d);
							o.setExecuting(true);
						}
						return o;
					}
					break;
				case "a":
					if (this.checkCell(5) || this.checkCell(6)) {
						if (!o.getExecuting()) {
							Date d = new Date();
							o.setTimeSent(d);
							o.setExecuting(true);
						}
						return o;
					}
					break;
				case "b":
					if (this.checkCell(7)) {
						if (!o.getExecuting()) {
							Date d = new Date();
							o.setTimeSent(d);
							o.setExecuting(true);
						}
						return o;
					}
					break;
				case "c":
					if (this.checkCell(5) || this.checkCell(6) || this.checkCell(7)) {
						if (!o.getExecuting()) {
							Date d = new Date();
							o.setTimeSent(d);
							o.setExecuting(true);
						}
						return o;
					}
					break;
			}
		}
		return null;
	}

	public void SendLoop() {
		work = new Thread("receive_thread") {
			public void run() {
				//System.out.println("Sending Orders");
				try {
					trans = new ModbusTCPTransaction(connect(5503));
				} catch (Exception e) {
					e.printStackTrace();
				}
				//in case we start sending orders without having orders on the vector
				while (true) {
					if (getOrder() != null) {
						while (true) {
							//1 s delay to compensate for real time vs plc time
							try {
								sleep(500);
							} catch (InterruptedException e) {
								e.printStackTrace();
							}
							//Reset coils and registers written
							reset();
							// 0.5s for line to respond
							try {

								sleep(500);
							} catch (InterruptedException e) {
								e.printStackTrace();
							}


							//Check if load order is on the line to manage Stock
							reqLoadP1 = new ReadCoilsRequest(9, 1);
							trans.setRequest(reqLoadP1);
							try {
								trans.execute();
							} catch (ModbusException e) {
								e.printStackTrace();
							}
							resLoadP1 = (ReadCoilsResponse) trans.getResponse();
							loadP1 = Integer.parseInt(resLoadP1.getCoils().toString().trim());
							reqLoadP2 = new ReadCoilsRequest(10, 1);
							trans.setRequest(reqLoadP2);
							try {
								trans.execute();
							} catch (ModbusException e) {
								e.printStackTrace();
							}
							resLoadP2 = (ReadCoilsResponse) trans.getResponse();
							loadP2 = Integer.parseInt(resLoadP2.getCoils().toString().trim());

							if (loadP1 == 1) {
								if (loadP1 != reLoadP1) {
									Main.stock.increaseQuantity("P1");
								}
							}
							reLoadP1 = loadP1;

							if (loadP2 == 1) {
								if (loadP2 != reLoadP2) {
									Main.stock.increaseQuantity("P2");
								}
							}
							reLoadP2 = loadP2;

							//check if line can receive orders
							reqIdleState = new ReadCoilsRequest(0, 1);
							trans.setRequest(reqIdleState);
							try {
								trans.execute();
							} catch (ModbusException e) {
								e.printStackTrace();
							}
							respIdle = (ReadCoilsResponse) trans.getResponse();
							idle = Integer.parseInt(respIdle.getCoils().toString().trim());

							//if it can receive orders
							if (idle == 0) {
								System.out.println(ANSI_BLUE + "Line Free " + ANSI_RESET);
								Order order = getOrder();
								System.out.println(ANSI_BLUE + "Order " + order.getNumber() + ANSI_RESET); //Null if order transform
								//Check if there are orders
								if (order != null) {
									//Send transform order based on transform priority (faster orders first)
									if (order.getDo().equals("T")) {
										Transform transform = (Transform) order;
										System.out.println(ANSI_BLUE + "Transform number " + transform.getNumber() + ", Quantity " + transform.getQuantity() + ANSI_RESET);

										String orderFrom = transform.getFrom();
										int valFrom = Integer.parseInt((orderFrom.substring(1)));
										String orderTo = transform.getTo();
										int valTo = Integer.parseInt((orderTo.substring(1)));

										if (transform.getQuantity() > 0) {
											//Write on register to tell what piece to remove from stock
											Main.stock.decreaseQuantity(transform.getFrom());
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

											//Choose place where to transform Cell 1, 2 or 3s
											String machine = transform.getMachine();
											switch (machine) {
												case "b":
													//send it to cell 3
													runCell3 = new WriteCoilRequest(4, true);
													trans.setRequest(runCell3);
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
													break;
												case "a":
													if (checkCell(6)) {
														//send to cell 2
														runCell2 = new WriteCoilRequest(3, true);
														trans.setRequest(runCell2);
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
													} else {
														//send to cell 1
														runCell1 = new WriteCoilRequest(2, true);
														trans.setRequest(runCell1);
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
													}
													break;
												case "c":
													if (checkCell(7)) {
														//send to cell 3
														runCell3 = new WriteCoilRequest(4, true);
														trans.setRequest(runCell3);
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
													} else if (checkCell(6)) {
														//send to cell 2
														runCell2 = new WriteCoilRequest(3, true);
														trans.setRequest(runCell2);
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
													} else {
														//send to cell 1
														runCell1 = new WriteCoilRequest(2, true);
														trans.setRequest(runCell1);
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
													}
													break;
											}

											//decrease quantity
											transform.decreaseQuantity();
											Main.stock.increaseQuantity(transform.getTo());
											//Remove order if quantity equals zero
											if (transform.getQuantity() == 0) {
												//TODO send to DB
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
										System.out.println(ANSI_BLUE + "Unload number " + unLoad.getNumber() + ", Quantity " + unLoad.getQuantity() + ANSI_RESET);

										String orderType = unLoad.getType();
										int valT = Integer.parseInt(orderType.substring(1));
										String destination = unLoad.getDestination();
										int valD = Integer.parseInt(destination.substring(1));
										//Send unLoad order based on stock available

										//Write on register to tell what piece to remove from stock and unLoad
										if (unLoad.getQuantity() > 0) {
											Main.stock.decreaseQuantity(unLoad.getType());
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
											//unLoad destination zone PM1, PM2 or PM3
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
									//Send mount commands to line
									else if (order.getDo().equals("M")) {
										Mount mount = (Mount) order;
										Main.stock.decreaseQuantity(mount.getBottom());
										Main.stock.decreaseQuantity(mount.getTop());
										System.out.println(ANSI_BLUE + "Mount number " + mount.getNumber() + ", Quantity " + mount.getQuantity() + ANSI_RESET);

										String orderType = mount.getBottom();
										int valBot = Integer.parseInt(orderType.substring(1));
										String destination = mount.getTop();
										int valTop = Integer.parseInt(destination.substring(1));
										//Send mount order based on stock available

										if (mount.getQuantity() > 0) {
											//Write on register piece to remove from stock
											pieceBottom = new WriteSingleRegisterRequest();
											pieceBottom.setReference(0);
											reg.setValue(valBot);
											pieceBottom.setRegister(reg);
											trans.setRequest(pieceBottom);
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
											//Write on register piece for top
											pieceTop = new WriteSingleRegisterRequest();
											pieceTop.setReference(1);
											reg.setValue(valTop);
											pieceTop.setRegister(reg);
											trans.setRequest(pieceTop);
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

											//Send command to PLC mount
											claw = new WriteCoilRequest(8, true);
											trans.setRequest(claw);
											try {
												trans.execute();
											} catch (ModbusException e) {
												e.printStackTrace();
											}

											//Decrease quantity
											mount.decreaseQuantity();
											//Remove Order and Send completed time to data base
											if (mount.getQuantity() == 0) {
												Main.ordersReceived.remove(mount);
											}
										}
									}
								}
							}
							//if it can't receive orders
							else if (idle == 1) {
								//Sleep for 1 second
								System.out.println(ANSI_BLUE + "Line occupied " + ANSI_RESET);
								try {
									sleep(1000);
								} catch (InterruptedException e) {
									e.printStackTrace();
								}
							}
						}
					}
				}
			}
		};
		work.start();
	}
}
