package Communication;

import MES.*;
import Communication.*;
import jdk.nashorn.internal.scripts.JD;
import net.wimpi.modbus.ModbusException;
import net.wimpi.modbus.io.ModbusTCPTransaction;
import net.wimpi.modbus.msg.*;
import net.wimpi.modbus.net.TCPMasterConnection;
import net.wimpi.modbus.procimg.SimpleRegister;

import java.awt.*;
import java.io.IOException;
import java.net.*;
import java.sql.SQLException;
import java.util.*;

import static java.lang.Thread.sleep;


public class SendOrder extends Modbus implements Runnable {
	public static final String ANSI_BLUE = "\u001B[34m";
	public static final String ANSI_RESET = "\u001B[0m";

	private ModbusTCPTransaction trans = null; // the transaction
	private WriteCoilRequest writeCoil = null;

	private ReadCoilsRequest reqCoil = null;
	private ReadCoilsRequest reqCellState = null;
	private ReadCoilsResponse respCoil = null;
	private ReadCoilsResponse respCellState = null;

	private int loadP1 = 0;
	private int reLoadP1 = 0;
	private int loadP2 = 0;
	private int reLoadP2 = 0;
	private int idle = 0;

	private int estadopecaDB = 0;

	private WriteSingleRegisterRequest register = null;

	private SimpleRegister reg = new SimpleRegister(0);

	private boolean runningOrders;

	private Thread work;

	public void run() {
		runningOrders = true;
		System.out.println("Thread Send Order check");
	}

	public void reset() {
		WriteCoil(1,false);
	}

	public void WriteRegister(int registerNumber, int numberToInsert){
		register = new WriteSingleRegisterRequest();
		register.setReference(registerNumber);
		reg.setValue(numberToInsert);
		register.setRegister(reg);
		trans.setRequest(register);
		try {
			trans.execute();
		} catch (ModbusException e) {
			e.printStackTrace();
		}
	}

	public boolean checkCell(int numberOfCell) {
		int cell = 0;
		reqCellState = new ReadCoilsRequest(numberOfCell, 1);
		trans.setRequest(reqCellState);
		try {
			trans.execute();
		} catch (ModbusException e) {
			e.printStackTrace();
		}
		respCellState = (ReadCoilsResponse) trans.getResponse();
		cell = Integer.parseInt(respCellState.getCoils().toString().trim());
		if (cell == 0) return true;
		else return false;
	}

	public int checkCoil(int numberOfCoil){
		int coil = 0;
		reqCoil = new ReadCoilsRequest(numberOfCoil, 1);
		trans.setRequest(reqCoil);
		try {
			trans.execute();
		} catch (ModbusException e) {
			e.printStackTrace();
		}
		respCoil = (ReadCoilsResponse) trans.getResponse();
		coil = Integer.parseInt(respCoil.getCoils().toString().trim());
		return coil;
	}

	public void WriteCoil(int numberOfCoil, boolean value){
		writeCoil = new WriteCoilRequest(numberOfCoil, value);
		trans.setRequest(writeCoil);
		try {
			trans.execute();
		} catch (ModbusException e) {
			e.printStackTrace();
		}
		//250 ms for line to respond
		sleepMethod(250);
	}

	public void sleepMethod(int timeMs){
		try {
			sleep(timeMs);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	public void DecreaseValueOnDataBase(int position){
		String valueString = null;
		try {
			valueString = JDBC.ReadFromDataBase("SELECT n_tipo_peca FROM armazem WHERE tipo_peca =" + position, "n_tipo_peca");
			int valueInt = Integer.parseInt(valueString);
			valueInt--;
			JDBC.WriteStringToDataBase("UPDATE armazem SET n_tipo_peca = " + valueInt + ",n_inicial_tipo_peca = '27' WHERE tipo_peca =" + position);
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	public void IncreaseValueOnDataBase(int position){
		String valueString = null;
		try {
			valueString = JDBC.ReadFromDataBase("SELECT n_tipo_peca FROM armazem WHERE tipo_peca =" + position, "n_tipo_peca");
			int valueInt = Integer.parseInt(valueString);
			valueInt++;
			JDBC.WriteStringToDataBase("UPDATE armazem SET n_tipo_peca = " + valueInt + ",n_inicial_tipo_peca = '27' WHERE tipo_peca =" + position);
		} catch (SQLException e) {
			e.printStackTrace();
		}
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
					if(this.checkCell(9)) {
						if (!o.getExecuting()) {
							Date d = new Date();
							o.setTimeSent(d);
							o.setExecuting(true);
						}
						return o;
					}
					break;
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
							//delay to compensate for real time vs plc time
							sleepMethod(500);
							//Reset coils and registers needed
							reset();

							//Check if load order is on the line to manage Stock
							loadP1 = checkCoil(9);
							loadP2 = checkCoil(10);
							//Rising edge mechanism
							if (loadP1 == 1) {
								if (loadP1 != reLoadP1) {
									Main.stock.increaseQuantity("P1");
									IncreaseValueOnDataBase(1);
								}
							}
							reLoadP1 = loadP1;

							if (loadP2 == 1) {
								if (loadP2 != reLoadP2) {
									Main.stock.increaseQuantity("P2");
									IncreaseValueOnDataBase(2);
								}
							}
							reLoadP2 = loadP2;

							//check if line can receive orders
							idle = checkCoil(0);

							//if it can receive orders
							if (idle == 0) {
								//System.out.println(ANSI_BLUE + "Line Free " + ANSI_RESET);
								Order order = getOrder();
								//Check if there are orders
								if (order != null) {
									//Send transform order based on transform priority (faster orders first)
									if (order.getDo().equals("T")) {
										Transform transform = (Transform) order;

										String orderFrom = transform.getFrom();
										int valFrom = Integer.parseInt((orderFrom.substring(1)));
										String orderTo = transform.getTo();
										int valTo = Integer.parseInt((orderTo.substring(1)));

										if (transform.getQuantity() > 0) {
											//Write on register to tell what piece to remove from stock
											WriteRegister(4,valFrom);
											Main.stock.decreaseQuantity(transform.getFrom());
											sleepMethod(50);
											//Write on register to tell what piece to transform into
											WriteRegister(3,valTo);
											sleepMethod(50);

											//Choose place where to transform Cell 1, 2 or 3s
											String mach = "";
											String machine = transform.getMachine();
											switch (machine) {
												case "b":
													//send it to cell 3
													WriteCoil(4, true);
													mach = "3b";
													break;
												case "a":
													if (checkCell(6)) {
														//send to cell 2
														WriteCoil(3, true);
														mach = "2a";
													} else {
														//send to cell 1
														WriteCoil(2, true);
														mach = "1a";
													}
													break;
												case "c":
													if (checkCell(7)) {
														//send to cell 3
														WriteCoil(4, true);
														mach = "3c";
													} else if (checkCell(6)) {
														//send to cell 2
														WriteCoil(3, true);
														mach = "2c";
													} else {
														//send to cell 1
														WriteCoil(2, true);
														mach = "1c";
													}
													break;
											}
											sleepMethod(2000);
											//decrease quantity
											transform.decreaseQuantity();

											//Update DataBase remove initial piece
											DecreaseValueOnDataBase(valFrom);


											Main.stock.increaseQuantity(transform.getTo());
											switch(mach) {
											case "1a": 
												Main.m1a.increaseP(transform.getFrom());
												break;
											case "2a":
												Main.m2a.increaseP(transform.getFrom());
												break;
											case "3b":
												Main.m3b.increaseP(transform.getFrom());
												break;
											case "1c":
												Main.m1c.increaseP(transform.getFrom(), transform.getTo());
												break;
											case "2c":
												Main.m2c.increaseP(transform.getFrom(), transform.getTo());
												break;
											case "3c":
												Main.m3c.increaseP(transform.getFrom(), transform.getTo());
												break;
											}

											System.out.println(ANSI_BLUE + "Transform number " + transform.getNumber() + ", Quantity " + transform.getQuantity() + ANSI_RESET);
											System.out.println("");
											//Remove order if quantity equals zero
											if (transform.getQuantity() == 0) {
												//JDBC.writeString("insert into ordem" + "(estado_ordem)" + "values ('id ordem', '')");
												//Add time stamp end order
												JDBC.WriteStringToDataBase("UPDATE ordem SET idordem = "+transform.getNumber()+", estado_ordem = '2', h_fim = now()");
												Date d = new Date();
												transform.setTimeFinished(d);
												Main.ordersCompleted.add(transform);
												Main.ordersReceived.remove(transform);
											}
										}
										//500 ms for line to respond
										sleepMethod(500);

										//Add result of transform to data base
										IncreaseValueOnDataBase(valTo);
									}
									//Check if there are unload orders on queue to send
									else if (order.getDo().equals("U")) {
										Unload unLoad = (Unload) order;

										String orderType = unLoad.getType();
										int valT = Integer.parseInt(orderType.substring(1));
										String destination = unLoad.getDestination();
										int valD = Integer.parseInt(destination.substring(1));
										//Send unLoad order based on stock available
										//Write on register to tell what piece to remove from stock and unLoad
										if (unLoad.getQuantity() > 0) {
											Main.stock.decreaseQuantity(unLoad.getType());
											WriteRegister(0,valT);
											sleepMethod(250);
											//unLoad destination zone PM1, PM2 or PM3
											WriteRegister(2,valD);
											// ms for line to respond
											sleepMethod(50);
											//Send unLoad command to PLC Boolean
											WriteCoil(1,true);

											//Data Base remove from stock
											DecreaseValueOnDataBase(valT);

											//ms for line to receive
											sleepMethod(3000);
											switch(valD) {
											case 1:
												Main.zone1.increaseP(unLoad.getType());
												break;
											case 2:
												Main.zone2.increaseP(unLoad.getType());
												break;
											case 3:
												Main.zone3.increaseP(unLoad.getType());
												break;
											}
											unLoad.decreaseQuantity();
											System.out.println(ANSI_BLUE + "Unload number " + unLoad.getNumber() + ", Quantity " + unLoad.getQuantity() + ANSI_RESET);
											System.out.println("");
											//Remove Order and Send completed time to data base
											if (unLoad.getQuantity() == 0) {
												//JDBC.writeString("insert into ordem" + "(estado_ordem)" + "values ('2')");
												//Add time stamp end time
												JDBC.WriteStringToDataBase("UPDATE ordem SET idordem = "+unLoad.getNumber()+", estado_ordem = '2', h_fim = now()");
												Date d = new Date();
												unLoad.setTimeFinished(d);
												Main.ordersCompleted.add(unLoad);
												Main.ordersReceived.remove(unLoad);
											}
										}
										sleepMethod(500);
									}
									//Send mount commands to line
									else if (order.getDo().equals("M")) {
										Mount mount = (Mount) order;
										Main.stock.decreaseQuantity(mount.getBottom());
										Main.stock.decreaseQuantity(mount.getTop());

										String orderType = mount.getBottom();
										int valBot = Integer.parseInt(orderType.substring(1));
										String destination = mount.getTop();
										int valTop = Integer.parseInt(destination.substring(1));
										//Send mount order based on stock available

										if (mount.getQuantity() > 0) {
											//Write on register piece to remove from stock
											WriteRegister(5,valBot);
											//250 ms for line to respond
											sleepMethod(250);
											//Write on register piece for top
											WriteRegister(1,valTop);
											sleepMethod(250);

											//Send command to PLC mount
											WriteCoil(8,true);

											//Decrease quantity
											mount.decreaseQuantity();
											Main.zone3.increaseP(mount.getTop());
											Main.zone3.increaseP(mount.getBottom());
											System.out.println(ANSI_BLUE + "Mount number " + mount.getNumber() + ", Quantity " + mount.getQuantity() + ANSI_RESET);
											System.out.println("");

											//DataBase update stock
											DecreaseValueOnDataBase(valBot);
											DecreaseValueOnDataBase(valTop);

											//Remove Order and Send completed time to data base
											if (mount.getQuantity() == 0) {
												JDBC.WriteStringToDataBase("UPDATE ordem SET idordem = "+mount.getNumber()+", estado_ordem = '2', h_fim = now()");
												Date d = new Date();
												mount.setTimeFinished(d);
												Main.ordersCompleted.add(mount);
												Main.ordersReceived.remove(mount);
											}
										}
									}
								}
							}
							//if it can't receive orders
							else if (idle == 1) {
								//Sleep for power saving purposes
								//System.out.println(ANSI_BLUE + "Line occupied " + ANSI_RESET);
								sleepMethod(2000);
							}
						}
					}
				}
			}
		};
		work.start();
	}
}
