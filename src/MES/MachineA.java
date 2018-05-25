package MES;

public class MachineA extends Machine {

	private int P1_P3 = 0;
	private int P3_P5 = 0;
	private int P5_P7 = 0;
	
	public MachineA(int id) {
		super(id);
	}
	
	public void increaseP(String p) {
		switch(p) {
		case "P1": 
			this.p1_p3();
			break;
		case "P3": 
			this.p3_p5();
			break;
		case "P5": 
			this.p5_p7();
			break;
		}
	}
	
	public void p1_p3() {
		this.P1_P3 ++;
		this.plusTime(5);
		//in every procedure like this (in classes MachineA/B/C)
		//String ID = this.getId() + "a";
		//IncreaseMachineTimeOnDB(ID, 5);
	}
	
	public void p3_p5() {
		this.P3_P5 ++;
		this.plusTime(10);
		//String ID = this.getId() + "a";
		//IncreaseMachineTimeOnDB(ID, 10);
	}
	
	public void p5_p7() {
		this.P5_P7 ++;
		this.plusTime(5);
		//String ID = this.getId() + "a";
		//IncreaseMachineTimeOnDB(ID, 5);
	}
	
	public void printInfo() {
		String time = (this.getWTime() / 3600) + "h " + ((this.getWTime() % 3600) / 60) + "m " + ((this.getWTime() % 3600) % 60) + "s";
		int total = this.P1_P3 + this.P3_P5 + this.P5_P7;
		super.printInfo();
		System.out.println("Machine " + this.getId() + "A:");
		System.out.println("Working time: " + time);
		System.out.println("Processed pieces: " + total);
		System.out.println("P1 -> P3: " + this.P1_P3);
		System.out.println("P3 -> P5: " + this.P3_P5);
		System.out.println("P5 -> P7: " + this.P5_P7);
	}
}
