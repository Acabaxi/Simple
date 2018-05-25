package MES;

public class MachineB extends Machine {

	private int P2_P4 = 0;
	private int P4_P6 = 0;
	private int P6_P8 = 0;
	
	public MachineB(int id) {
		super(id);
	}
	
	public void increaseP(String p) {
		switch(p) {
		case "P2":
			this.p2_p4();
			break;
		case "P4": 
			this.p4_p6();
			break;
		case "P6": 
			this.p6_p8();
			break;
		}
	}
	
	public void p2_p4() {
		this.P2_P4 ++;
		this.plusTime(10);
	}
	
	public void p4_p6() {
		this.P4_P6 ++;
		this.plusTime(5);
	}
	
	public void p6_p8() {
		this.P6_P8 ++;
		this.plusTime(5);
	}
	
	public void printInfo() {
		String time = (this.getWTime() / 3600) + "h " + ((this.getWTime() % 3600) / 60) + "m " + ((this.getWTime() % 3600) % 60) + "s";
		int total = this.P2_P4 + this.P4_P6 + this.P6_P8;
		super.printInfo();
		System.out.println("Machine " + this.getId() + "B:");
		System.out.println("Working time: " + time);
		System.out.println("Processed pieces: " + total);
		System.out.println("P2 -> P4: " + this.P2_P4);
		System.out.println("P4 -> P6: " + this.P4_P6);
		System.out.println("P6 -> P8: " + this.P6_P8);
	}
}
