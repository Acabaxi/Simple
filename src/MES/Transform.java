package MES;

public class Transform extends Order{
    private String from;
    private String to;

    public Transform(String number, String oType){
        super(number, oType);
    }

    public void setFrom(String from){
        this.from = from;
    }

    public void setTo(String to){
        this.to = to;
    }

    public String getFrom() {
        return from;
    }

    public String getTo() {
        return to;
    }
    
    public String machine() {
    	switch(this.from) {
    	case "P1":
    		return "a";
    	case "P2":
    		return "b";
    	case "P3":
    		return "a";
    	case "P4":
    		return "b";
    	case "P5":
    		return "a";
    	case "P6":
    		return "b";
    	case "P7":
    		return "c";
    	case "P8":
    		return "c";
    	case "P9":
    		return "c";
    	default: return "";
    	}
    }
    
    public int getDoTime() {
    	int t = 0;
    	if(this.machine().equals("c"))
    		t = 20;
    	else if(this.machine().equals("a")) {
    		if(this.from.equals("P3"))
    			t = 10;
    		else t = 5;
    	}
    	else if(this.machine().equals("b")) {
    		if(this.from.equals("P2"))
    			t = 10;
    		else t = 5;
    	}
    	return (this.getQuantity() * t);
    }
    
    public Transform makeCopy() {
    	Transform t = new Transform(this.getNumber(), this.getDo());
    	t.setFrom(this.getFrom());
    	t.setTo(this.getTo());
    	t.setQuantity(this.getQuantity());
    	t.setTimeReceived(this.getTimeReceived());
    	t.setTimeSent(this.getTimeSent());
    	t.setTimeFinished(this.getTimeFinished());
    	return t;
    }
}
