package MES;

public class Stock {
	private int p1;
	private int p2;
	private int p3;
	private int p4;
	private int p5;
	private int p6;
	private int p7;
	private int p8;
	private int p9;
	
	public Stock() {}
	
	public void setQuantity(String type, int quantity) {
		switch(type) {
		case "P1": this.p1 = quantity;
				break;
		case "P2": this.p2 = quantity;
				break;
		case "P3": this.p3 = quantity;
				break;
		case "P4": this.p4 = quantity;
				break;
		case "P5": this.p5 = quantity;
				break;
		case "P6": this.p6 = quantity;
				break;
		case "P7": this.p7 = quantity;
				break;
		case "P8": this.p8 = quantity;
				break;
		case "P9": this.p9 = quantity;
				break;
		default: System.out.println("Wrong type");
				break;
		}
	}
	
	public int getQuantity(String type) {
		switch(type) {
		case "P1": return this.p1;
		case "P2": return this.p2;
		case "P3": return this.p3;
		case "P4": return this.p4;
		case "P5": return this.p5;
		case "P6": return this.p6;
		case "P7": return this.p7;
		case "P8": return this.p8;
		case "P9": return this.p9;
		default: return 0;
		}
	}
	
	public void increaseQuantity(String type) {
		switch(type) {
		case "P1": this.p1++;
				break;
		case "P2": this.p2++;
				break;
		case "P3": this.p3++;
				break;
		case "P4": this.p4++;
				break;
		case "P5": this.p5++;
				break;
		case "P6": this.p6++;
				break;
		case "P7": this.p7++;
				break;
		case "P8": this.p8++;
				break;
		case "P9": this.p9++;
				break;
		default: System.out.println("Wrong type");
				break;
		}
	}
	
	public void decreaseQuantity(String type) {
		switch(type) {
		case "P1": this.p1--;
				break;
		case "P2": this.p2--;
				break;
		case "P3": this.p3--;
				break;
		case "P4": this.p4--;
				break;
		case "P5": this.p5--;
				break;
		case "P6": this.p6--;
				break;
		case "P7": this.p7--;
				break;
		case "P8": this.p8--;
				break;
		case "P9": this.p9--;
				break;
		default: System.out.println("Wrong type");
				break;
		}
	}
	
}
