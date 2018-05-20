package MES;

public class Mount extends Order {
    private String bottomType;
    private String topType;

    public Mount(String number, String oType){
        super(number, oType);
    }

    public void setBottom(String type){
        this.bottomType = type;
    }

    public void setTop(String type){
        this.topType = type;
    }

    public String getBottom() {
        return this.bottomType;
    }

    public String getTop() {
        return this.topType;
    }
    
    public Mount makeCopy() {
    	Mount m = new Mount(this.getNumber(), this.getDo());
    	m.setBottom(this.getBottom());
    	m.setTop(this.getTop());
    	m.setQuantity(this.getQuantity());
    	m.setTimeReceived(this.getTimeReceived());
    	m.setTimeSent(this.getTimeSent());
    	m.setTimeFinished(this.getTimeFinished());
    	return m;
    }
}
