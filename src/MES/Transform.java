package MES;

public class Transform extends Order{
    private String from;
    private String to;
    private int quantity;

    public Transform(String number, String oType){
        super(number, oType);
    }

    public void setFrom(String from){
        this.from = from;
    }

    public void setTo(String to){
        this.to = to;
    }

    public void setQuantity(int quantity){
        this.quantity = quantity;
    }

    public String getFrom() {
        return from;
    }

    public String getTo() {
        return to;
    }

    public int getQuantity() {
        return quantity;
    }
}
