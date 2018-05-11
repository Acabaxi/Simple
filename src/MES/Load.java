package MES;

public class Load extends Order {
    private String type;
    private String from;

    public Load(String number, String oType){
        super(number, oType);
    }

    public void setType(String type){
        this.type = type;
    }

    public void setFrom(String from){
        this.from = from;
    }

    public String getType() {
        return type;
    }

    public String getFrom() {
        return from;
    }
}
