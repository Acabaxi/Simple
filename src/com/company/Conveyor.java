package com.company;

public class Conveyor {

    boolean sensor;
    boolean busy;

    public boolean isBusy(){
        return this.sensor;
    }
}

class Rolls extends Conveyor{
    
}

class LinearConveyor extends Conveyor{

    public void moveForward(){

    }

    public void moveBack(){

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
