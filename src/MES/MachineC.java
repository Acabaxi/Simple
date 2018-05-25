package MES;

public class MachineC extends Machine {

	private int P7_P8 = 0;
	private int P8_P7 = 0;
	private int P7_P9 = 0;
	private int P8_P9 = 0;
	
	public MachineC(int id) {
		super(id);
	}
	
	public void increaseP(String p1, String p2) {
		switch(p1) {
		case "P7": 
			if(p2.equals("P8"))
				this.p7_p8();
			else
				this.p7_p9();
			break;
		case "P8":
			if(p2.equals("P7"))
				this.p8_p7();
			else
				this.p8_p9();
			break;
		}
	}
	
	public void p7_p8() {
		this.P7_P8 ++;
		this.plusTime(20);
	}
	
	public void p8_p7() {
		this.P8_P7 ++;
		this.plusTime(20);
	}
	
	public void p7_p9() {
		this.P7_P9 ++;
		this.plusTime(20);
	}
	
	public void p8_p9() {
		this.P8_P9 ++;
		this.plusTime(20);
	}
	
	public void printInfo() {
		String time = (this.getWTime() / 3600) + "h " + ((this.getWTime() % 3600) / 60) + "m " + ((this.getWTime() % 3600) % 60) + "s";
		int total = this.P7_P8 + this.P8_P7 + this.P7_P9 + this.P8_P9;
		super.printInfo();
		System.out.println("Machine " + this.getId() + "C:");
		System.out.println("Working time: " + time);
		System.out.println("Processed pieces: " + total);
		System.out.println("P7 -> P8: " + this.P7_P8);
		System.out.println("P8 -> P7: " + this.P8_P7);
		System.out.println("P7 -> P9: " + this.P7_P9);
		System.out.println("P8 -> P9: " + this.P8_P9);
	}
}
