FUNCTION_BLOCK LinearConveyor
  VAR_INPUT
    backSignal : BOOL;
  END_VAR
  VAR
    forwardTimerOn : BOOL;
  END_VAR
  VAR_INPUT
    forwardSignal : BOOL;
    backNotBusy : BOOL;
    frontNotBusy : BOOL;
    reachedSensorFront : BOOL;
    reachedSensorBack : BOOL;
    reachedSensor : BOOL;
  END_VAR
  VAR_OUTPUT
    forwardMotor : BOOL;
    backMotor : BOOL;
    isBusy : BOOL;
    moveNextBack : BOOL;
    moveNextFront : BOOL;
  END_VAR
  VAR
    TON0 : TON;
    TON1 : TON;
  END_VAR

  INITIAL_STEP initLinearStep:
    isBusy(R);
    COMPUTE_FUNCTION_BLOCKS(S);
  END_STEP

  ACTION COMPUTE_FUNCTION_BLOCKS:
    TON1(IN := forwardTimerOn, PT := T#10s);
    TON0(IN := forwardTimerOn, PT := T#10s);
  END_ACTION

  TRANSITION FROM initLinearStep TO moveFront
    := forwardSignal;
  END_TRANSITION

  STEP moveFront:
    forwardMotor(N);
    isBusy(S);
  END_STEP

  TRANSITION FROM moveFront TO notBusyFront
    := reachedSensor;
  END_TRANSITION

  STEP notBusyFront:
  END_STEP

  TRANSITION FROM notBusyFront TO moveFrontStep
    := frontNotBusy;
  END_TRANSITION

  STEP moveFrontStep:
    moveNextFront(S);
    forwardTimerOn(N);
    forwardMotor(S);
  END_STEP

  TRANSITION FROM moveFrontStep TO turnOffFront
    := reachedSensorFront;
  END_TRANSITION

  STEP turnOffFront:
    forwardMotor(R);
    moveNextFront(R);
  END_STEP

  TRANSITION FROM turnOffFront TO initLinearStep
    := true;
  END_TRANSITION

  TRANSITION FROM moveFrontStep TO turnOffFront
    := TON0.Q;
  END_TRANSITION

  TRANSITION FROM initLinearStep TO moveBack
    := backSignal;
  END_TRANSITION

  STEP moveBack:
    backMotor(N);
    isBusy(S);
  END_STEP

  TRANSITION FROM moveBack TO notBusyBack
    := reachedSensor;
  END_TRANSITION

  STEP notBusyBack:
  END_STEP

  TRANSITION FROM notBusyBack TO moveBackStep
    := backNotBusy;
  END_TRANSITION

  STEP moveBackStep:
    moveNextBack(S);
    forwardTimerOn(N);
    backMotor(S);
  END_STEP

  TRANSITION FROM moveBackStep TO turnOffBack
    := reachedSensorBack;
  END_TRANSITION

  STEP turnOffBack:
    backMotor(R);
    moveNextBack(R);
  END_STEP

  TRANSITION FROM turnOffBack TO initLinearStep
    := true;
  END_TRANSITION

  TRANSITION FROM moveBackStep TO turnOffBack
    := TON1.Q;
  END_TRANSITION

END_FUNCTION_BLOCK

PROGRAM program0
  VAR
    AT1 : LinearConveyor;
  END_VAR
  VAR_EXTERNAL
    ii : BOOL;
  END_VAR
  VAR
    sensorAT1 AT %IX0.0.0.0 : BOOL;
    sensorSaT1 AT %IX0.0.0.1 : BOOL;
    sensorSaT2 AT %IX0.0.0.2 : BOOL;
    forwardAT1 AT %QX0.0.1.1 : BOOL;
    forwardSaT1 AT %QX0.0.1.3 : BOOL;
    forwardSaT2 AT %QX0.0.1.5 : BOOL;
    backAT1 AT %QX0.0.1.0 : BOOL;
    backSaT2 AT %QX0.0.1.2 : BOOL;
    backSaT3 AT %QX0.0.1.4 : BOOL;
  END_VAR
  VAR
    SaT1 : LinearConveyor;
    SaT2 : LinearConveyor;
    TP0 : TP;
  END_VAR
  VAR_EXTERNAL
    sensorAT1_ex : BOOL;
  END_VAR
  VAR
    NOT5_OUT : BOOL;
    NOT4_OUT : BOOL;
    NOT6_OUT : BOOL;
  END_VAR

  sensorAT1_ex := sensorAT1;
  NOT5_OUT := NOT(SaT1.isBusy);
  SaT2(forwardSignal := SaT1.moveNextFront, backNotBusy := NOT5_OUT, frontNotBusy := true, reachedSensorBack := sensorSaT1, reachedSensor := sensorSaT2);
  NOT4_OUT := NOT(SaT1.isBusy);
  AT1(backSignal := SaT1.moveNextBack, forwardSignal := ii, backNotBusy := false, frontNotBusy := NOT4_OUT, reachedSensorFront := sensorSaT1, reachedSensorBack := false, reachedSensor := sensorAT1);
  NOT6_OUT := NOT(SaT2.isBusy);
  SaT1(backSignal := SaT2.moveNextBack, forwardSignal := AT1.moveNextFront, backNotBusy := AT1.isBusy, frontNotBusy := NOT6_OUT, reachedSensorFront := sensorSaT2, reachedSensorBack := sensorAT1, reachedSensor := sensorSaT1);
  backSaT2 := SaT1.backMotor;
  backAT1 := AT1.backMotor;
  backSaT3 := SaT2.backMotor;
  forwardSaT1 := SaT1.forwardMotor;
  forwardSaT2 := SaT2.forwardMotor;
  forwardAT1 := AT1.forwardMotor;
  TP0(IN := true, PT := T#200ms);
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

PROGRAM program1
  VAR_EXTERNAL
    ii : BOOL;
    sensorAT1_ex : BOOL;
  END_VAR

  INITIAL_STEP Step0:
  END_STEP

  TRANSITION FROM Step0 TO Step1
    := true;
  END_TRANSITION

  STEP Step1:
    ii(N);
  END_STEP

  TRANSITION FROM Step1 TO Step2
    := sensorAT1_ex;
  END_TRANSITION

  STEP Step2:
  END_STEP

  TRANSITION FROM Step2 TO Step0
    := false;
  END_TRANSITION

END_PROGRAM


CONFIGURATION config
  VAR_GLOBAL
    ii : BOOL;
    forwardAT1 : BOOL;
    forwardSaT2 : BOOL;
    forwardSaT1 : BOOL;
    sensorAT1_ex : BOOL;
  END_VAR

  RESOURCE resource1 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance1 WITH task0 : program1;
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
