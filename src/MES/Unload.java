package MES;

public class Unload extends Order{
    private String type;
    private String destination;

    public Unload(String number, String oType){
        super(number, oType);
    }

    public void setType(String type){
        this.type = type;
    }

    public void setDestination(String destination){
        this.destination = destination;
    }

    public String getType() {
        return type;
    }

    public String getDestination() {
        return destination;
    }
}
