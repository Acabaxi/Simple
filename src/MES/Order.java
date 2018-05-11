package MES;

import java.util.*;

public class Order {
    private String number;
    private String orderType;       //L-load T-transform U-unload
    private int quantity;
    private Date timeReceived;
    private Date timeSent;
    private Date timeFinished;
    

    public Order(String number, String type){
        this.number = number;
        this.orderType = type;
    }

    public String getNumber() {
        return this.number;
    }

    public String getDo(){return this.orderType;}
    
    public void setQuantity(int quantity){
        this.quantity = quantity;
    }
    
    public int getQuantity() {
        return quantity;
    }
    
    public void decreaseQuantity() {
    	if (this.quantity > 0)
    		this.quantity --;
    }
    
    public void setTimeReceived(Date t) {
    	this.timeReceived = t;
    }
    
    public Date getTimeReceived() {
    	return this.timeReceived;
    }  
    
    public void setTimeSent(Date t) {
    	this.timeSent = t;
    }
    
    public Date getTimeSent() {
    	return this.timeSent;
    }    
    public void setTimeFinished(Date t) {
    	this.timeFinished = t;
    }
    
    public Date getTimeFinished() {
    	return this.timeFinished;
    }
}