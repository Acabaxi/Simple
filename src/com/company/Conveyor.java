package com.company;

import java.util.ArrayList;
import java.util.List;

public class Conveyor {

    int numberConnections = 4;
    boolean sensor;
    boolean busy;

    public boolean isBusy(){
        return this.sensor;
    }

    Conveyor connections[] = new Conveyor[numberConnections];

    public Conveyor(){
        for(int i = 0; i < numberConnections;i++){
            this.connections[i] = null;
        }
        resetBusy();
        resetSensor();
    }

    public void setSensor(){
        this.sensor = true;
    }

    public void resetSensor(){
        this.sensor = false;
    }

    public boolean getSensor(){
        return this.sensor;
    }

    public void setBusy(){
        this.busy = true;
    }

    public void resetBusy(){
        this.busy = false;
    }

    public boolean getBusy(){
        return this.busy;
    }


}

class Rolls extends Conveyor{

    public Rolls(){
        super();
    }

}

class LinearConveyor extends Conveyor{

    public int modbusForwardCoil;
    public int modbusBackwardCoil;
    public int modbusSensorCoil;

    public LinearConveyor(){
        super();
        modbusForwardCoil = 0;
        modbusBackwardCoil = 0;
        modbusSensorCoil = 0;
    }
    public LinearConveyor(int fCoil, int bCoil, int sCoil){
        super();
        modbusForwardCoil = fCoil;
        modbusBackwardCoil = bCoil;
        modbusSensorCoil = sCoil;

    }

    public LinearConveyor(int fCoil, int bCoil, int sCoil, Conveyor up, Conveyor down, Conveyor left, Conveyor right){
        super();
        modbusForwardCoil = fCoil;
        modbusBackwardCoil = bCoil;
        modbusSensorCoil = sCoil;

        this.connections[0] = up;
        this.connections[1] = down;
        this.connections[2] = left;
        this.connections[3] = right;
    }

    public static void moveForward(){
        int a =1 ;
        return;
    }

    public static void moveBack(){
        System.out.println("Moving Backwards");
    }

}

class RotaryConveyor extends LinearConveyor{

    boolean sensorRotateF;
    boolean sensorRotateB;

    public void rotateF(){

    }

    public void rotateB() {

    }
}

