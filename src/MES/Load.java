package MES;

public class Load extends Order{
    private String type;
    private String from;
    private String quantity;

    public Load(String number){
        super(number);
    }

    public void setType(String type){
        this.type = type;
    }

    public void setFrom(String from){
        this.from = from;
    }

    public void setQuantity(String quantity){
        this.quantity = quantity;
    }

    public String getType() {
        return type;
    }

    public String getFrom() {
        return from;
    }

    public String getQuantity() {
        return quantity;
    }
}
