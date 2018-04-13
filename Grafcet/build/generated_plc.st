PROGRAM program0
  VAR
    var1 : DINT;
  END_VAR
  VAR
    s0 AT %IX0.0.0.0 : BOOL;
    s1 AT %IX0.0.0.1 : BOOL;
    s2 AT %IX0.0.0.2 : BOOL;
    a0 AT %QX0.0.1.0 : BOOL;
    a1 AT %QX0.0.1.1 : BOOL;
    a2 AT %QX0.0.1.2 : BOOL;
    a3 AT %QX0.0.1.3 : BOOL;
    a4 AT %QX0.0.1.4 : BOOL;
    a5 AT %QX0.0.1.5 : BOOL;
  END_VAR

  var1:=1;
END_PROGRAM

FUNCTION_BLOCK RotaryConveyor
  VAR_INPUT
    backSignal : BOOL;
    forwardSignal : BOOL;
    reachedSensor : BOOL;
    backNotBusy : BOOL;
    frontNotBusy : BOOL;
    reachedSensorBack : BOOL;
    reachedSensorFront : BOOL;
    rotateLeftSignal : BOOL;
    rotateRightSignal : BOOL;
    doneRotateRight : BOOL;
    doneRotateLeft : BOOL;
  END_VAR
  VAR_OUTPUT
    rotateRight : BOOL;
    rotateLeft : BOOL;
    isBusy : BOOL;
    backMotor : BOOL;
    forwardMotor : BOOL;
    moveNextBack : BOOL;
    moveNextFront : BOOL;
  END_VAR

  INITIAL_STEP initLinearStep0:
    isBusy(R);
  END_STEP

  TRANSITION FROM initLinearStep0 TO moveFront0
    := forwardSignal;
  END_TRANSITION

  STEP moveFront0:
    forwardMotor(S);
    isBusy(S);
  END_STEP

  TRANSITION FROM moveFront0 TO waitForNotBusyFront0
    := reachedSensor;
  END_TRANSITION

  STEP waitForNotBusyFront0:
    forwardMotor(R);
  END_STEP

  TRANSITION FROM waitForNotBusyFront0 TO moveNextFrontStep0
    := frontNotBusy;
  END_TRANSITION

  STEP moveNextFrontStep0:
    moveNextFront(S);
    forwardMotor(S);
  END_STEP

  TRANSITION FROM moveNextFrontStep0 TO turnOffFront0
    := reachedSensorFront;
  END_TRANSITION

  STEP turnOffFront0:
    forwardMotor(R);
    isBusy(R);
  END_STEP

  TRANSITION FROM turnOffFront0 TO initLinearStep0
    := true;
  END_TRANSITION

  TRANSITION FROM initLinearStep0 TO moveBack0
    := backSignal;
  END_TRANSITION

  STEP moveBack0:
    backMotor(S);
    isBusy(S);
  END_STEP

  TRANSITION FROM moveBack0 TO waitForNotBusyBack0
    := reachedSensor;
  END_TRANSITION

  STEP waitForNotBusyBack0:
    backMotor(R);
  END_STEP

  TRANSITION FROM waitForNotBusyBack0 TO moveNextBackStep0
    := backNotBusy;
  END_TRANSITION

  STEP moveNextBackStep0:
    moveNextBack(S);
    backMotor(S);
  END_STEP

  TRANSITION FROM moveNextBackStep0 TO turnOffBack0
    := reachedSensorBack;
  END_TRANSITION

  STEP turnOffBack0:
    backMotor(R);
    isBusy(R);
  END_STEP

  TRANSITION FROM turnOffBack0 TO initLinearStep0
    := true;
  END_TRANSITION

  TRANSITION FROM initLinearStep0 TO rotatingRight
    := rotateRightSignal;
  END_TRANSITION

  STEP rotatingRight:
    rotateRight(S);
    isBusy(S);
  END_STEP

  TRANSITION FROM rotatingRight TO Step0
    := doneRotateRight;
  END_TRANSITION

  STEP Step0:
    rotateRight(R);
    isBusy(R);
  END_STEP

  TRANSITION FROM Step0 TO initLinearStep0
    := true;
  END_TRANSITION

  TRANSITION FROM initLinearStep0 TO rotatingLeft
    := rotateLeftSignal;
  END_TRANSITION

  STEP rotatingLeft:
    rotateLeft(S);
    isBusy(S);
  END_STEP

  TRANSITION FROM rotatingLeft TO Step1
    := doneRotateLeft;
  END_TRANSITION

  STEP Step1:
    rotateLeft(R);
    isBusy(R);
  END_STEP

  TRANSITION FROM Step1 TO initLinearStep0
    := true;
  END_TRANSITION

END_FUNCTION_BLOCK

FUNCTION_BLOCK LinearConveyor
  VAR_INPUT
    backSignal : BOOL;
    backNotBusy : BOOL;
    forwardSignal : BOOL;
    reachedSensorFront : BOOL;
    frontNotBusy : BOOL;
    reachedSensor : BOOL;
    reachedSensorBack : BOOL;
  END_VAR
  VAR_OUTPUT
    forwardMotor : BOOL;
    backMotor : BOOL;
    isBusy : BOOL;
    moveNextBack : BOOL;
    moveNextFront : BOOL;
  END_VAR

  INITIAL_STEP initLinearStep:
    isBusy(R);
  END_STEP

  TRANSITION FROM initLinearStep TO moveFront
    := forwardSignal;
  END_TRANSITION

  STEP moveFront:
    forwardMotor(S);
    isBusy(S);
  END_STEP

  TRANSITION FROM moveFront TO waitForNotBusyFront
    := reachedSensor;
  END_TRANSITION

  STEP waitForNotBusyFront:
    forwardMotor(R);
  END_STEP

  TRANSITION FROM waitForNotBusyFront TO moveNextFrontStep
    := frontNotBusy;
  END_TRANSITION

  STEP moveNextFrontStep:
    moveNextFront(S);
    forwardMotor(S);
  END_STEP

  TRANSITION FROM moveNextFrontStep TO turnOffFront
    := reachedSensorFront;
  END_TRANSITION

  STEP turnOffFront:
    forwardMotor(R);
  END_STEP

  TRANSITION FROM turnOffFront TO initLinearStep
    := true;
  END_TRANSITION

  TRANSITION FROM initLinearStep TO moveBack
    := backSignal;
  END_TRANSITION

  STEP moveBack:
    backMotor(S);
    isBusy(S);
  END_STEP

  TRANSITION FROM moveBack TO waitForNotBusyBack
    := reachedSensor;
  END_TRANSITION

  STEP waitForNotBusyBack:
    backMotor(R);
  END_STEP

  TRANSITION FROM waitForNotBusyBack TO moveNextBackStep
    := backNotBusy;
  END_TRANSITION

  STEP moveNextBackStep:
    moveNextBack(S);
    backMotor(S);
  END_STEP

  TRANSITION FROM moveNextBackStep TO turnOffBack
    := reachedSensorBack;
  END_TRANSITION

  STEP turnOffBack:
    backMotor(R);
  END_STEP

  TRANSITION FROM turnOffBack TO initLinearStep
    := true;
  END_TRANSITION

END_FUNCTION_BLOCK


CONFIGURATION config

  RESOURCE resource1 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 : program0;
  END_RESOURCE
END_CONFIGURATION
