package MES;

public class Machine {
	
	private int id;
	private long workTime = 0;

	public Machine(int id) {
		this.id = id;
	}
	
	public int getId() {
		return this.id;
	}
	
	public void plusTime(int t) {
		this.workTime += t;
	}
	
	public long getWTime() {
		return this.workTime;
	}
	
	public void printInfo() {
		System.out.println("\n");
	}
}
