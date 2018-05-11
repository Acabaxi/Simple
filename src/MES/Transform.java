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
    
}
