package MES;
import java.util.*;

public class StatisticsUnload {

	private int id;
	private Vector<Integer> pieces = new Vector<>();
	
	public StatisticsUnload(int id) {
		this.id = id;
		for (int i = 0; i < 9; i++) {
			this.pieces.add(i, 0);
		}
	}
	
	public void increaseP(String p) {
		int i = Integer.parseInt(p.substring(1));
		i--;
		int val = this.pieces.get(i) + 1;
		this.pieces.set(i, val);
	}
	
	public void PrintStat() {
		System.out.println("\nDestination " + this.id + ":");
		for(int i = 0; i < this.pieces.size(); i++) {
			System.out.println("P" + (i + 1) + ": " + this.pieces.get(i));
		}
	}
	
}
