package MES;

public class Unload extends Order{
    private String type;
    private String destination;
    private int quantity;

    public Unload(String number, String oType){
        super(number, oType);
    }

    public void setType(String type){
        this.type = type;
    }

    public void setDestination(String destination){
        this.destination = destination;
    }

    public void setQuantity(int quantity){
        this.quantity = quantity;
    }

    public String getType() {
        return type;
    }

    public String getDestination() {
        return destination;
    }

    public int getQuantity() {
        return quantity;
    }
}
