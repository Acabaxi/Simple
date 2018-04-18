package MES;

public class Unload extends Order{
    private String type;
    private String destination;
    private String quantity;

    public Unload(String number, String oType){
        super(number, oType);
    }

    public void setType(String type){
        this.type = type;
    }

    public void setDestination(String destination){
        this.destination = destination;
    }

    public void setQuantity(String quantity){
        this.quantity = quantity;
    }

    public String getType() {
        return type;
    }

    public String getDestination() {
        return destination;
    }

    public String getQuantity() {
        return quantity;
    }
}
