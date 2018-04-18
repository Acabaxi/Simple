package MES;

public class Order {
    private String number;
    private String orderType;       //L-load T-transform U-unload

    public Order(String number, String type){
        this.number = number;
        this.orderType = type;
    }

    public String getNumber() {
        return this.number;
    }

    public String getType(){return this.orderType;}
}