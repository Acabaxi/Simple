package MES;

public class Transform extends Order{
    private String from;
    private String to;
    private String quantity;

    public Transform(String number, String oType){
        super(number, oType);
    }

    public void setFrom(String from){
        this.from = from;
    }

    public void setTo(String to){
        this.to = to;
    }

    public void setQuantity(String quantity){
        this.quantity = quantity;
    }

    public String getFrom() {
        return from;
    }

    public String getTo() {
        return to;
    }

    public String getQuantity() {
        return quantity;
    }
}
