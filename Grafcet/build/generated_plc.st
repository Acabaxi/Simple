FUNCTION_BLOCK LinearConveyor
  VAR_INPUT
    reachedSensor : BOOL;
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
  END_VAR
  VAR_OUTPUT
    forwardMotor : BOOL;
    backMotor : BOOL;
    isBusy : BOOL;
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
  END_STEP

  TRANSITION FROM moveFront TO notBusyFront
    := reachedSensor;
  END_TRANSITION

  STEP notBusyFront:
    isBusy(S);
  END_STEP

  TRANSITION FROM notBusyFront TO moveFrontStep
    := not frontNotBusy;
  END_TRANSITION

  STEP moveFrontStep:
    forwardTimerOn(N);
    forwardMotor(S);
  END_STEP

  TRANSITION FROM moveFrontStep TO turnOffFront
    := reachedSensorFront;
  END_TRANSITION

  STEP turnOffFront:
    forwardMotor(R);
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
  END_STEP

  TRANSITION FROM moveBack TO notBusyBack
    := reachedSensor;
  END_TRANSITION

  STEP notBusyBack:
    isBusy(S);
  END_STEP

  TRANSITION FROM notBusyBack TO moveBackStep
    := not backNotBusy;
  END_TRANSITION

  STEP moveBackStep:
    forwardTimerOn(N);
    backMotor(S);
  END_STEP

  TRANSITION FROM moveBackStep TO turnOffBack
    := reachedSensorBack;
  END_TRANSITION

  STEP turnOffBack:
    backMotor(R);
  END_STEP

  TRANSITION FROM turnOffBack TO initLinearStep
    := true;
  END_TRANSITION

  TRANSITION FROM moveBackStep TO turnOffBack
    := TON1.Q;
  END_TRANSITION

END_FUNCTION_BLOCK

FUNCTION_BLOCK RotaryConveyor
  VAR_INPUT
    backSignal : BOOL;
  END_VAR
  VAR
    forwardTimerOn : BOOL;
  END_VAR
  VAR_INPUT
    forwardSignal : BOOL;
    sendDownSignal : BOOL;
    sendUpSignal : BOOL;
    sensorRotRight : BOOL;
    sensorRotLeft : BOOL;
    backNotBusy : BOOL;
    frontNotBusy : BOOL;
    downNotBusy : BOOL;
    upNotBusy : BOOL;
    reachedSensorFront : BOOL;
    reachedSensor : BOOL;
    reachedSensorDown : BOOL;
    reachedSensorBack : BOOL;
    reachedSensorUp : BOOL;
  END_VAR
  VAR_OUTPUT
    forwardMotor : BOOL;
    backMotor : BOOL;
    rightRotMotor : BOOL;
    leftRotMotor : BOOL;
    isBusy : BOOL;
  END_VAR
  VAR
    TON0 : TON;
    TON1 : TON;
    TON2 : TON;
    TON3 : TON;
  END_VAR

  INITIAL_STEP initLinearStep:
    isBusy(R);
    COMPUTE_FUNCTION_BLOCKS(S);
  END_STEP

  ACTION COMPUTE_FUNCTION_BLOCKS:
    TON1(IN := forwardTimerOn, PT := T#10s);
    TON0(IN := forwardTimerOn, PT := T#10s);
    TON3(IN := forwardTimerOn, PT := T#10s);
    TON2(IN := forwardTimerOn, PT := T#10s);
  END_ACTION

  TRANSITION FROM initLinearStep TO moveFront
    := forwardSignal;
  END_TRANSITION

  STEP moveFront:
    forwardMotor(N);
  END_STEP

  TRANSITION FROM moveFront TO notBusyFront
    := reachedSensor;
  END_TRANSITION

  STEP notBusyFront:
    isBusy(S);
  END_STEP

  TRANSITION FROM notBusyFront TO moveFrontStep
    := not frontNotBusy;
  END_TRANSITION

  STEP moveFrontStep:
    forwardTimerOn(N);
    forwardMotor(S);
  END_STEP

  TRANSITION FROM moveFrontStep TO turnOffFront
    := reachedSensorFront;
  END_TRANSITION

  STEP turnOffFront:
    forwardMotor(R);
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
  END_STEP

  TRANSITION FROM moveBack TO notBusyBack
    := reachedSensor;
  END_TRANSITION

  STEP notBusyBack:
    isBusy(S);
  END_STEP

  TRANSITION FROM notBusyBack TO moveBackStep
    := not backNotBusy;
  END_TRANSITION

  STEP moveBackStep:
    forwardTimerOn(N);
    backMotor(S);
  END_STEP

  TRANSITION FROM moveBackStep TO turnOffBack
    := reachedSensorBack;
  END_TRANSITION

  STEP turnOffBack:
    backMotor(R);
  END_STEP

  TRANSITION FROM turnOffBack TO initLinearStep
    := true;
  END_TRANSITION

  TRANSITION FROM moveBackStep TO turnOffBack
    := TON1.Q;
  END_TRANSITION

  TRANSITION FROM initLinearStep TO moveFront1
    := sendUpSignal;
  END_TRANSITION

  STEP moveFront1:
    backMotor(N);
  END_STEP

  TRANSITION FROM moveFront1 TO rotatingLeft
    := reachedSensor;
  END_TRANSITION

  STEP rotatingLeft:
    leftRotMotor(N);
    isBusy(S);
  END_STEP

  TRANSITION FROM rotatingLeft TO notBusyBack0
    := sensorRotLeft;
  END_TRANSITION

  STEP notBusyBack0:
    isBusy(S);
  END_STEP

  TRANSITION FROM notBusyBack0 TO moveBackStep0
    := not upNotBusy;
  END_TRANSITION

  STEP moveBackStep0:
    forwardTimerOn(N);
    backMotor(S);
  END_STEP

  TRANSITION FROM moveBackStep0 TO turnOffBack0
    := reachedSensorUp;
  END_TRANSITION

  STEP turnOffBack0:
    backMotor(R);
  END_STEP

  TRANSITION FROM turnOffBack0 TO resetRotate0
    := true;
  END_TRANSITION

  STEP resetRotate0:
    rightRotMotor(N);
  END_STEP

  TRANSITION FROM resetRotate0 TO resetDoneL
    := sensorRotRight;
  END_TRANSITION

  STEP resetDoneL:
  END_STEP

  TRANSITION FROM resetDoneL TO initLinearStep
    := true;
  END_TRANSITION

  TRANSITION FROM moveBackStep0 TO turnOffBack0
    := TON3.Q;
  END_TRANSITION

  TRANSITION FROM initLinearStep TO moveFront0
    := sendDownSignal;
  END_TRANSITION

  STEP moveFront0:
    forwardMotor(N);
  END_STEP

  TRANSITION FROM moveFront0 TO rotatingRight
    := reachedSensor;
  END_TRANSITION

  STEP rotatingRight:
    rightRotMotor(N);
    isBusy(S);
  END_STEP

  TRANSITION FROM rotatingRight TO notBusyFront0
    := sensorRotRight;
  END_TRANSITION

  STEP notBusyFront0:
    isBusy(S);
  END_STEP

  TRANSITION FROM notBusyFront0 TO moveFrontStep0
    := not downNotBusy;
  END_TRANSITION

  STEP moveFrontStep0:
    forwardTimerOn(N);
    forwardMotor(S);
  END_STEP

  TRANSITION FROM moveFrontStep0 TO turnOffFront0
    := reachedSensorDown;
  END_TRANSITION

  STEP turnOffFront0:
    forwardMotor(R);
  END_STEP

  TRANSITION FROM turnOffFront0 TO resetRotate
    := true;
  END_TRANSITION

  STEP resetRotate:
    leftRotMotor(N);
  END_STEP

  TRANSITION FROM resetRotate TO resetDoneR
    := sensorRotLeft;
  END_TRANSITION

  STEP resetDoneR:
  END_STEP

  TRANSITION FROM resetDoneR TO initLinearStep
    := true;
  END_TRANSITION

  TRANSITION FROM moveFrontStep0 TO turnOffFront0
    := TON2.Q;
  END_TRANSITION

END_FUNCTION_BLOCK

FUNCTION_BLOCK Pusher
  VAR
    TON1 : TON;
    TON0 : TON;
    forwardTimerOn : BOOL;
  END_VAR
  VAR_OUTPUT
    forwardMotor : BOOL;
    pushMotorForward : BOOL;
    pushMotorBack : BOOL;
    backMotor : BOOL;
    isBusy : BOOL;
  END_VAR
  VAR_INPUT
    backSignal : BOOL;
    rollBusy : BOOL;
    pushSignal : BOOL;
    forwardSignal : BOOL;
    reachedSensor : BOOL;
    reachedSensorBack : BOOL;
    reachedSensorFront : BOOL;
    sensorPushForward : BOOL;
    sensorPushBack : BOOL;
    frontNotBusy : BOOL;
    backNotBusy : BOOL;
  END_VAR

  INITIAL_STEP initLinearStep:
    isBusy(R);
    COMPUTE_FUNCTION_BLOCKS(S);
  END_STEP

  ACTION COMPUTE_FUNCTION_BLOCKS:
    TON0(IN := forwardTimerOn, PT := T#10s);
    TON1(IN := forwardTimerOn, PT := T#10s);
  END_ACTION

  TRANSITION FROM initLinearStep TO moveFront0
    := forwardSignal;
  END_TRANSITION

  STEP moveFront0:
    forwardMotor(N);
  END_STEP

  TRANSITION FROM moveFront0 TO notBusyFront0
    := reachedSensor;
  END_TRANSITION

  STEP notBusyFront0:
    isBusy(S);
  END_STEP

  TRANSITION FROM notBusyFront0 TO moveFrontStep0
    := not frontNotBusy;
  END_TRANSITION

  STEP moveFrontStep0:
    forwardTimerOn(N);
    forwardMotor(S);
  END_STEP

  TRANSITION FROM moveFrontStep0 TO turnOffFront0
    := TON0.Q;
  END_TRANSITION

  STEP turnOffFront0:
    forwardMotor(R);
  END_STEP

  TRANSITION FROM turnOffFront0 TO initLinearStep
    := true;
  END_TRANSITION

  TRANSITION FROM moveFrontStep0 TO turnOffFront0
    := reachedSensorFront;
  END_TRANSITION

  TRANSITION FROM initLinearStep TO moveBack0
    := backSignal;
  END_TRANSITION

  STEP moveBack0:
    backMotor(N);
  END_STEP

  TRANSITION FROM moveBack0 TO notBusyBack0
    := reachedSensor;
  END_TRANSITION

  STEP notBusyBack0:
    isBusy(S);
  END_STEP

  TRANSITION FROM notBusyBack0 TO moveBackStep0
    := not backNotBusy;
  END_TRANSITION

  STEP moveBackStep0:
    forwardTimerOn(N);
    backMotor(S);
  END_STEP

  TRANSITION FROM moveBackStep0 TO turnOffBack0
    := TON1.Q;
  END_TRANSITION

  STEP turnOffBack0:
    backMotor(R);
  END_STEP

  TRANSITION FROM turnOffBack0 TO initLinearStep
    := true;
  END_TRANSITION

  TRANSITION FROM moveBackStep0 TO turnOffBack0
    := reachedSensorBack;
  END_TRANSITION

  TRANSITION FROM initLinearStep TO pushRoll
    := pushSignal;
  END_TRANSITION

  STEP pushRoll:
    forwardMotor(N);
  END_STEP

  TRANSITION FROM pushRoll TO notBusyFront1
    := reachedSensor;
  END_TRANSITION

  STEP notBusyFront1:
    isBusy(S);
  END_STEP

  TRANSITION FROM notBusyFront1 TO pushToRoll
    := not rollBusy;
  END_TRANSITION

  STEP pushToRoll:
    pushMotorForward(N);
  END_STEP

  TRANSITION FROM pushToRoll TO retractPusher
    := sensorPushForward;
  END_TRANSITION

  STEP retractPusher:
    pushMotorBack(N);
  END_STEP

  TRANSITION FROM retractPusher TO initLinearStep
    := sensorPushBack;
  END_TRANSITION

END_FUNCTION_BLOCK

FUNCTION_BLOCK Roll
  VAR_INPUT
    reachedSensor : BOOL;
  END_VAR
  VAR_OUTPUT
    hasPiece : BOOL;
  END_VAR

  INITIAL_STEP Step0:
  END_STEP

  TRANSITION FROM Step0 TO Step1
    := reachedSensor;
  END_TRANSITION

  STEP Step1:
    hasPiece(N);
  END_STEP

  TRANSITION FROM Step1 TO Step0
    := not reachedSensor;
  END_TRANSITION

END_FUNCTION_BLOCK

PROGRAM program0
  VAR
    AT1 : LinearConveyor;
    SaT1 : LinearConveyor;
    SaT2 : RotaryConveyor;
    SbT1 : LinearConveyor;
  END_VAR
  VAR_EXTERNAL
    sensorAT1_ex : BOOL;
    sensorAT2_ex : BOOL;
    sensorSaT1_ex : BOOL;
    sensorSaT2_ex : BOOL;
    sensorSaT6_ex : BOOL;
    sensorSaT7_ex : BOOL;
    sensorSbT1_ex : BOOL;
    sensorSbT2_ex : BOOL;
    sensorScT1_ex : BOOL;
    sensorScT2_ex : BOOL;
    sensorScT7_ex : BOOL;
    sensorMT1_ex : BOOL;
    sensorMT2_ex : BOOL;
    sensorCT1_ex : BOOL;
    sensorCT2_ex : BOOL;
    sensorCT3_ex : BOOL;
    sensorCT4_ex : BOOL;
    sensorCT6_ex : BOOL;
    sensorCT5_ex : BOOL;
    sensorCT7_ex : BOOL;
    sensorCT8_ex : BOOL;
    sensorCT9_ex : BOOL;
    runBackAT2_ex : BOOL;
    runBackSaT7_ex : BOOL;
    runBackSaT6_ex : BOOL;
    runBackScT7_ex : BOOL;
    runBackCT7_ex : BOOL;
    runBackCT8_ex : BOOL;
    runBackCT9_ex : BOOL;
    runFrontAT1_ex : BOOL;
    runFrontSaT1_ex : BOOL;
    runFrontSaT2_ex : BOOL;
    runFrontSbT1_ex : BOOL;
    runFrontSbT2_ex : BOOL;
    runFrontScT1_ex : BOOL;
    runFrontScT2_ex : BOOL;
    runFrontMT1_ex : BOOL;
    runFrontMT2_ex : BOOL;
    runFrontCT1_ex : BOOL;
    runFrontCT2_ex : BOOL;
    runFrontCT3_ex : BOOL;
    runFrontCT4_ex : BOOL;
    runFrontCT5_ex : BOOL;
    runFrontCT6_ex : BOOL;
    runFrontCT8_ex : BOOL;
    runBackCT2_ex : BOOL;
    runBackCT3_ex : BOOL;
    sendDownSaT2_ex : BOOL;
    sendDownSbT2_ex : BOOL;
    sendDownScT2_ex : BOOL;
    sendDownMT2_ex : BOOL;
    sendDownCT2_ex : BOOL;
    sendDownCT8_ex : BOOL;
  END_VAR
  VAR
    SbT2 : RotaryConveyor;
  END_VAR
  VAR
    backAT1 AT %QX0.0.1.0 : BOOL;
    backAT2 AT %QX0.0.1.2 : BOOL;
    backSaT2 AT %QX0.0.1.7 : BOOL;
    backSaT6 AT %QX0.0.1.31 : BOOL;
    backSbT2 AT %QX0.0.1.39 : BOOL;
    backSbT6 AT %QX0.0.1.63 : BOOL;
    backScT2 AT %QX0.0.1.71 : BOOL;
    backScT6 AT %QX0.0.1.95 : BOOL;
    backMT2 AT %QX0.0.1.103 : BOOL;
    backMT6 AT %QX0.0.1.113 : BOOL;
    backCT2 AT %QX0.0.1.126 : BOOL;
    backCT8 AT %QX0.0.1.146 : BOOL;
    backCT4 AT %QX0.0.1.132 : BOOL;
    backCT5 AT %QX0.0.1.136 : BOOL;
    backCT6 AT %QX0.0.1.140 : BOOL;
    backSaT3 AT %QX0.0.1.11 : BOOL;
    backSaT5 AT %QX0.0.1.22 : BOOL;
    backSbT3 AT %QX0.0.1.43 : BOOL;
    backSbT5 AT %QX0.0.1.54 : BOOL;
    backScT3 AT %QX0.0.1.75 : BOOL;
    backScT5 AT %QX0.0.1.86 : BOOL;
    backSaT1 AT %QX0.0.1.5 : BOOL;
    backSaT4 AT %QX0.0.1.20 : BOOL;
    backSaT7 AT %QX0.0.1.35 : BOOL;
    backSbT1 AT %QX0.0.1.37 : BOOL;
    backSbT4 AT %QX0.0.1.52 : BOOL;
    backSbT7 AT %QX0.0.1.67 : BOOL;
    backScT1 AT %QX0.0.1.69 : BOOL;
    backScT4 AT %QX0.0.1.84 : BOOL;
    backScT7 AT %QX0.0.1.99 : BOOL;
    backMT1 AT %QX0.0.1.101 : BOOL;
    backMT3 AT %QX0.0.1.107 : BOOL;
    backMT4 AT %QX0.0.1.109 : BOOL;
    backMT5 AT %QX0.0.1.111 : BOOL;
    backCT1 AT %QX0.0.1.124 : BOOL;
    backCT3 AT %QX0.0.1.130 : BOOL;
    backCT7 AT %QX0.0.1.144 : BOOL;
    backCT9 AT %QX0.0.1.150 : BOOL;
    sensorAT1 AT %IX0.0.0.0 : BOOL;
    sensorAT2 AT %IX0.0.0.1 : BOOL;
    sensorMM1 AT %IX0.0.0.76 : BOOL;
    sensorMM2 AT %IX0.0.0.77 : BOOL;
    sensorMM3 AT %IX0.0.0.78 : BOOL;
    sensorSaT2 AT %IX0.0.0.3 : BOOL;
    sensorSaT6 AT %IX0.0.0.19 : BOOL;
    sensorSbT2 AT %IX0.0.0.24 : BOOL;
    sensorSbT6 AT %IX0.0.0.40 : BOOL;
    sensorScT2 AT %IX0.0.0.45 : BOOL;
    sensorScT6 AT %IX0.0.0.61 : BOOL;
    sensorMT2 AT %IX0.0.0.66 : BOOL;
    sensorMT6 AT %IX0.0.0.73 : BOOL;
    sensorCT2 AT %IX0.0.0.90 : BOOL;
    sensorCT8 AT %IX0.0.0.104 : BOOL;
    sensorPM1 AT %IX0.0.0.108 : BOOL;
    sensorPM2 AT %IX0.0.0.109 : BOOL;
    sensorPM3 AT %IX0.0.0.110 : BOOL;
    sensorCT4 AT %IX0.0.0.94 : BOOL;
    sensorCT5 AT %IX0.0.0.97 : BOOL;
    sensorCT6 AT %IX0.0.0.100 : BOOL;
    sensorSaT3 AT %IX0.0.0.6 : BOOL;
    sensorSaT5 AT %IX0.0.0.13 : BOOL;
    sensorSbT3 AT %IX0.0.0.27 : BOOL;
    sensorSbT5 AT %IX0.0.0.34 : BOOL;
    sensorScT3 AT %IX0.0.0.48 : BOOL;
    sensorScT5 AT %IX0.0.0.55 : BOOL;
    sensorSaT1 AT %IX0.0.0.2 : BOOL;
    sensorSaT4 AT %IX0.0.0.12 : BOOL;
    sensorSaT7 AT %IX0.0.0.22 : BOOL;
    sensorSbT1 AT %IX0.0.0.23 : BOOL;
    sensorSbT4 AT %IX0.0.0.33 : BOOL;
    sensorSbT7 AT %IX0.0.0.43 : BOOL;
    sensorScT1 AT %IX0.0.0.44 : BOOL;
    sensorScT4 AT %IX0.0.0.54 : BOOL;
    sensorScT7 AT %IX0.0.0.64 : BOOL;
    sensorMT1 AT %IX0.0.0.65 : BOOL;
    sensorMT3 AT %IX0.0.0.69 : BOOL;
    sensorMT4 AT %IX0.0.0.71 : BOOL;
    sensorMT5 AT %IX0.0.0.72 : BOOL;
    sensorCT1 AT %IX0.0.0.89 : BOOL;
    sensorCT3 AT %IX0.0.0.93 : BOOL;
    sensorCT7 AT %IX0.0.0.103 : BOOL;
    sensorCT9 AT %IX0.0.0.107 : BOOL;
    pushForwardCT4 AT %QX0.0.1.135 : BOOL;
    pushForwardCT5 AT %QX0.0.1.139 : BOOL;
    pushForwardCT6 AT %QX0.0.1.143 : BOOL;
    sensorPushForwardCT4 AT %IX0.0.0.96 : BOOL;
    sensorPushForwardCT5 AT %IX0.0.0.99 : BOOL;
    sensorPushForwardCT6 AT %IX0.0.0.102 : BOOL;
    pushBackCT4 AT %QX0.0.1.134 : BOOL;
    pushBackCT5 AT %QX0.0.1.138 : BOOL;
    pushBackCT6 AT %QX0.0.1.142 : BOOL;
    sensorPushBackCT4 AT %IX0.0.0.95 : BOOL;
    sensorPushBackCT5 AT %IX0.0.0.98 : BOOL;
    sensorPushBackCT6 AT %IX0.0.0.101 : BOOL;
    forwardAT1 AT %QX0.0.1.1 : BOOL;
    forwardAT2 AT %QX0.0.1.3 : BOOL;
    forwardSaT2 AT %QX0.0.1.8 : BOOL;
    forwardSaT6 AT %QX0.0.1.32 : BOOL;
    forwardSbT2 AT %QX0.0.1.40 : BOOL;
    forwardSbT6 AT %QX0.0.1.64 : BOOL;
    forwardScT2 AT %QX0.0.1.72 : BOOL;
    forwardScT6 AT %QX0.0.1.96 : BOOL;
    forwardMT2 AT %QX0.0.1.104 : BOOL;
    forwardMT6 AT %QX0.0.1.114 : BOOL;
    forwardCT2 AT %QX0.0.1.127 : BOOL;
    forwardCT8 AT %QX0.0.1.147 : BOOL;
    forwardCT4 AT %QX0.0.1.133 : BOOL;
    forwardCT5 AT %QX0.0.1.137 : BOOL;
    forwardCT6 AT %QX0.0.1.141 : BOOL;
    forwardSaT3 AT %QX0.0.1.12 : BOOL;
    forwardSaT5 AT %QX0.0.1.23 : BOOL;
    forwardSbT3 AT %QX0.0.1.44 : BOOL;
    forwardSbT5 AT %QX0.0.1.55 : BOOL;
    forwardScT3 AT %QX0.0.1.76 : BOOL;
    forwardScT5 AT %QX0.0.1.87 : BOOL;
    forwardSaT1 AT %QX0.0.1.6 : BOOL;
    forwardSaT4 AT %QX0.0.1.21 : BOOL;
    forwardSaT7 AT %QX0.0.1.36 : BOOL;
    forwardSbT1 AT %QX0.0.1.38 : BOOL;
    forwardSbT4 AT %QX0.0.1.53 : BOOL;
    forwardSbT7 AT %QX0.0.1.68 : BOOL;
    forwardScT1 AT %QX0.0.1.70 : BOOL;
    forwardScT4 AT %QX0.0.1.85 : BOOL;
    forwardScT7 AT %QX0.0.1.100 : BOOL;
    forwardMT1 AT %QX0.0.1.102 : BOOL;
    forwardMT3 AT %QX0.0.1.108 : BOOL;
    forwardMT4 AT %QX0.0.1.110 : BOOL;
    forwardMT5 AT %QX0.0.1.112 : BOOL;
    forwardCT1 AT %QX0.0.1.125 : BOOL;
    forwardCT3 AT %QX0.0.1.131 : BOOL;
    forwardCT7 AT %QX0.0.1.145 : BOOL;
    forwardCT9 AT %QX0.0.1.151 : BOOL;
    sensorRotRightSaT2 AT %IX0.0.0.5 : BOOL;
    sensorRotRightSaT6 AT %IX0.0.0.21 : BOOL;
    sensorRotRightSbT2 AT %IX0.0.0.26 : BOOL;
    sensorRotRightSbT6 AT %IX0.0.0.42 : BOOL;
    sensorRotRightScT2 AT %IX0.0.0.47 : BOOL;
    sensorRotRightScT6 AT %IX0.0.0.63 : BOOL;
    sensorRotRightMT2 AT %IX0.0.0.68 : BOOL;
    sensorRotRightMT6 AT %IX0.0.0.75 : BOOL;
    sensorRotRightCT2 AT %IX0.0.0.92 : BOOL;
    sensorRotRightCT8 AT %IX0.0.0.106 : BOOL;
    sensorRotLeftSaT2 AT %IX0.0.0.4 : BOOL;
    sensorRotLeftSaT6 AT %IX0.0.0.20 : BOOL;
    sensorRotLeftSbT2 AT %IX0.0.0.25 : BOOL;
    sensorRotLeftSbT6 AT %IX0.0.0.41 : BOOL;
    sensorRotLeftScT2 AT %IX0.0.0.46 : BOOL;
    sensorRotLeftScT6 AT %IX0.0.0.62 : BOOL;
    sensorRotLeftMT2 AT %IX0.0.0.67 : BOOL;
    sensorRotLeftMT6 AT %IX0.0.0.74 : BOOL;
    sensorRotLeftCT2 AT %IX0.0.0.91 : BOOL;
    sensorRotLeftCT8 AT %IX0.0.0.105 : BOOL;
    rightRotSaT2 AT %QX0.0.1.10 : BOOL;
    rightRotSaT6 AT %QX0.0.1.34 : BOOL;
    rightRotSbT2 AT %QX0.0.1.42 : BOOL;
    rightRotSbT6 AT %QX0.0.1.66 : BOOL;
    rightRotScT2 AT %QX0.0.1.74 : BOOL;
    rightRotScT6 AT %QX0.0.1.98 : BOOL;
    rightRotMT2 AT %QX0.0.1.106 : BOOL;
    rightRotMT6 AT %QX0.0.1.116 : BOOL;
    rightRotCT2 AT %QX0.0.1.129 : BOOL;
    rightRotCT8 AT %QX0.0.1.149 : BOOL;
    leftRotSaT2 AT %QX0.0.1.9 : BOOL;
    leftRotSaT6 AT %QX0.0.1.33 : BOOL;
    leftRotSbT2 AT %QX0.0.1.41 : BOOL;
    leftRotSbT6 AT %QX0.0.1.65 : BOOL;
    leftRotScT2 AT %QX0.0.1.73 : BOOL;
    leftRotScT6 AT %QX0.0.1.97 : BOOL;
    leftRotMT2 AT %QX0.0.1.105 : BOOL;
    leftRotMT6 AT %QX0.0.1.115 : BOOL;
    leftRotCT2 AT %QX0.0.1.128 : BOOL;
    leftRotCT8 AT %QX0.0.1.148 : BOOL;
  END_VAR
  VAR
    ScT1 : LinearConveyor;
    ScT2 : RotaryConveyor;
    MT1 : LinearConveyor;
    MT2 : RotaryConveyor;
    CT1 : LinearConveyor;
    CT2 : RotaryConveyor;
    CT3 : LinearConveyor;
    AT2 : LinearConveyor;
    SaT7 : LinearConveyor;
    SbT7 : LinearConveyor;
    SbT6 : RotaryConveyor;
    ScT7 : LinearConveyor;
    SaT6 : RotaryConveyor;
    ScT6 : RotaryConveyor;
    MT5 : LinearConveyor;
    MT6 : RotaryConveyor;
    CT7 : LinearConveyor;
    CT8 : RotaryConveyor;
    CT9 : LinearConveyor;
  END_VAR
  VAR_EXTERNAL
    sendUpSaT6_ex : BOOL;
    sensorSbT7_ex : BOOL;
    runBackSbT7_ex : BOOL;
    sensorSbT6_ex : BOOL;
    runFrontSbT6_ex : BOOL;
    sendDownSbT6_ex : BOOL;
    sendDownSaT6_ex : BOOL;
    runBackSbT6_ex : BOOL;
    sensorScT6_ex : BOOL;
    runFrontScT6_ex : BOOL;
    runBackScT6_ex : BOOL;
    runBackMT6_ex : BOOL;
    sendDownScT6_ex : BOOL;
    sendDownMT6_ex : BOOL;
    sensorMT5_ex : BOOL;
    sensorMT6_ex : BOOL;
    runBackMT5_ex : BOOL;
    pushToRollCT4_ex : BOOL;
    pushToRollCT5_ex : BOOL;
    pushToRollCT6_ex : BOOL;
  END_VAR
  VAR
    CT4 : Pusher;
    CT5 : Pusher;
    CT6 : Pusher;
    PM1 : Roll;
    PM2 : Roll;
    PM3 : Roll;
    OR210_OUT : BOOL;
    OR209_OUT : BOOL;
  END_VAR

  sensorSaT1_ex := sensorSaT1;
  sensorSaT2_ex := sensorSaT2;
  sensorSbT2_ex := sensorSbT2;
  sensorScT1_ex := sensorScT1;
  sensorScT2_ex := sensorScT2;
  sensorAT1_ex := sensorAT1;
  sensorSbT1_ex := sensorSbT1;
  sensorMT1_ex := sensorMT1;
  sensorCT2_ex := sensorCT2;
  sensorCT3_ex := sensorCT3;
  sensorMT2_ex := sensorMT2;
  sensorCT1_ex := sensorCT1;
  CT2(backSignal := runBackCT2_ex, forwardSignal := runFrontCT2_ex, sendDownSignal := sendDownCT2_ex, sensorRotRight := sensorRotRightCT2, sensorRotLeft := sensorRotLeftCT2, reachedSensor := sensorCT2, reachedSensorDown := sensorCT4);
  CT1(reachedSensor := sensorCT1, forwardSignal := runFrontCT1_ex, frontNotBusy := CT2.isBusy, reachedSensorFront := sensorCT2);
  MT2(forwardSignal := runFrontMT2_ex, sendDownSignal := sendDownMT2_ex, sensorRotRight := sensorRotRightMT2, sensorRotLeft := sensorRotLeftMT2, frontNotBusy := CT1.isBusy, reachedSensorFront := sensorCT1, reachedSensor := sensorMT2);
  MT1(reachedSensor := sensorMT1, forwardSignal := runFrontMT1_ex, frontNotBusy := MT2.isBusy, reachedSensorFront := sensorMT2);
  ScT2(forwardSignal := runFrontScT2_ex, sendDownSignal := sendDownScT2_ex, sensorRotRight := sensorRotRightScT2, sensorRotLeft := sensorRotLeftScT2, frontNotBusy := MT1.isBusy, reachedSensor := sensorScT2);
  ScT1(reachedSensor := sensorScT1, forwardSignal := runFrontSbT1_ex, frontNotBusy := ScT2.isBusy, reachedSensorFront := sensorScT2);
  SbT2(forwardSignal := runFrontSbT2_ex, sendDownSignal := sendDownSbT2_ex, sensorRotRight := sensorRotRightSbT2, sensorRotLeft := sensorRotLeftSbT2, frontNotBusy := ScT1.isBusy, reachedSensorFront := sensorScT1, reachedSensor := sensorSbT2);
  SbT1(reachedSensor := sensorSbT1, forwardSignal := runFrontSbT1_ex, frontNotBusy := SbT2.isBusy, reachedSensorFront := sensorSbT2);
  SaT2(forwardSignal := runFrontSaT2_ex, sendDownSignal := sendDownSaT2_ex, sensorRotRight := sensorRotRightSaT2, sensorRotLeft := sensorRotLeftSaT2, frontNotBusy := SbT1.isBusy, reachedSensorFront := sensorSbT1, reachedSensor := sensorSaT2);
  forwardSaT2 := SaT2.forwardMotor;
  forwardScT2 := ScT2.forwardMotor;
  forwardCT2 := CT2.forwardMotor;
  forwardSbT1 := SbT1.forwardMotor;
  forwardSbT2 := SbT2.forwardMotor;
  forwardMT2 := MT2.forwardMotor;
  forwardCT1 := CT1.forwardMotor;
  SaT1(reachedSensor := sensorSaT1, forwardSignal := runFrontSaT1_ex, frontNotBusy := SaT2.isBusy, reachedSensorFront := sensorSaT2);
  AT1(reachedSensor := sensorAT1, forwardSignal := runFrontAT1_ex, frontNotBusy := SaT1.isBusy, reachedSensorFront := sensorSaT1);
  forwardAT1 := AT1.forwardMotor;
  forwardSaT1 := SaT1.forwardMotor;
  rightRotSaT2 := SaT2.rightRotMotor;
  rightRotCT2 := CT2.rightRotMotor;
  rightRotSbT2 := SbT2.rightRotMotor;
  rightRotScT2 := ScT2.rightRotMotor;
  backAT1 := AT1.backMotor;
  backSaT1 := SaT1.backMotor;
  rightRotMT2 := MT2.rightRotMotor;
  leftRotSaT2 := SaT2.leftRotMotor;
  leftRotCT2 := CT2.leftRotMotor;
  leftRotSbT2 := SbT2.leftRotMotor;
  leftRotScT2 := ScT2.leftRotMotor;
  forwardMT1 := MT1.forwardMotor;
  forwardScT1 := ScT1.forwardMotor;
  leftRotMT2 := MT2.leftRotMotor;
  sensorCT4_ex := sensorCT4;
  PM1(reachedSensor := sensorPM1);
  CT4(rollBusy := PM1.hasPiece, pushSignal := pushToRollCT4_ex, forwardSignal := runFrontCT4_ex, reachedSensor := sensorCT4, reachedSensorFront := sensorCT5, sensorPushForward := sensorPushForwardCT4, sensorPushBack := sensorPushBackCT4);
  forwardCT4 := CT4.forwardMotor;
  pushForwardCT4 := CT4.pushMotorForward;
  pushBackCT4 := CT4.pushMotorBack;
  PM2(reachedSensor := sensorPM2);
  CT5(rollBusy := PM2.hasPiece, pushSignal := pushToRollCT5_ex, forwardSignal := runFrontCT5_ex, reachedSensor := sensorCT5, reachedSensorFront := sensorCT6, sensorPushForward := sensorPushForwardCT5, sensorPushBack := sensorPushBackCT5);
  forwardCT5 := CT5.forwardMotor;
  sensorCT5_ex := sensorCT5;
  pushForwardCT5 := CT5.pushMotorForward;
  pushBackCT5 := CT5.pushMotorBack;
  sensorCT6_ex := sensorCT6;
  PM3(reachedSensor := sensorPM3);
  CT6(rollBusy := PM3.hasPiece, pushSignal := pushToRollCT6_ex, forwardSignal := runFrontCT6_ex, reachedSensor := sensorCT6, reachedSensorFront := sensorCT8, sensorPushForward := sensorPushForwardCT6, sensorPushBack := sensorPushBackCT6);
  forwardCT6 := CT6.forwardMotor;
  pushForwardCT6 := CT6.pushMotorForward;
  pushBackCT6 := CT6.pushMotorBack;
  sensorScT6_ex := sensorScT6;
  sensorSbT6_ex := sensorSbT6;
  sensorScT7_ex := sensorScT7;
  sensorSaT7_ex := sensorSaT7;
  sensorMT5_ex := sensorMT5;
  sensorAT2_ex := sensorAT2;
  sensorSaT6_ex := sensorSaT6;
  sensorSbT7_ex := sensorSbT7;
  sensorCT9_ex := sensorCT9;
  sensorCT7_ex := sensorCT7;
  sensorCT8_ex := sensorCT8;
  sensorMT6_ex := sensorMT6;
  AT2(reachedSensor := sensorAT2, backSignal := runBackAT2_ex);
  SaT7(reachedSensor := sensorSaT7, backSignal := runBackSaT7_ex, backNotBusy := AT2.isBusy, reachedSensorFront := sensorSaT6, reachedSensorBack := sensorAT2);
  SaT6(backSignal := runBackSaT6_ex, sendDownSignal := sendDownSaT6_ex, sendUpSignal := sendUpSaT6_ex, sensorRotRight := sensorRotRightSaT6, sensorRotLeft := sensorRotLeftSaT6, backNotBusy := SaT7.isBusy, reachedSensorFront := sensorSbT7, reachedSensor := sensorSaT6, reachedSensorBack := sensorSaT7);
  SbT7(reachedSensor := sensorSbT7, backSignal := runBackSbT7_ex, backNotBusy := SaT6.isBusy, reachedSensorFront := sensorSbT6, reachedSensorBack := sensorSaT6);
  SbT6(backSignal := runBackSbT6_ex, forwardSignal := runFrontSbT6_ex, sendDownSignal := sendDownSbT6_ex, sensorRotRight := sensorRotRightSbT6, sensorRotLeft := sensorRotLeftSbT6, backNotBusy := SbT7.isBusy, reachedSensorFront := sensorScT7, reachedSensor := sensorSbT6, reachedSensorBack := sensorSbT7);
  ScT7(reachedSensor := sensorScT7, backSignal := runBackScT7_ex, backNotBusy := SbT6.isBusy, reachedSensorFront := sensorScT6, reachedSensorBack := sensorSbT6);
  ScT6(backSignal := runBackScT6_ex, forwardSignal := runFrontScT6_ex, sendDownSignal := sendDownScT6_ex, sensorRotRight := sensorRotRightScT6, sensorRotLeft := sensorRotLeftScT6, backNotBusy := ScT7.isBusy, reachedSensor := sensorScT6, reachedSensorBack := sensorScT7);
  MT5(reachedSensor := sensorMT5, backSignal := runBackMT5_ex, backNotBusy := ScT6.isBusy, reachedSensorFront := sensorMT6, reachedSensorBack := sensorScT6);
  MT6(backSignal := runBackMT6_ex, sendDownSignal := sendDownMT6_ex, sensorRotRight := sensorRotRightMT6, sensorRotLeft := sensorRotLeftMT6, backNotBusy := MT5.isBusy, reachedSensor := sensorMT6, reachedSensorBack := sensorMT5);
  CT7(reachedSensor := sensorCT7, backSignal := runBackCT7_ex, backNotBusy := MT6.isBusy, reachedSensorFront := sensorCT8, reachedSensorBack := sensorMT6);
  CT8(backSignal := runBackCT8_ex, forwardSignal := runFrontCT8_ex, sendDownSignal := sendDownCT8_ex, sensorRotRight := sensorRotRightCT8, sensorRotLeft := sensorRotLeftCT8, backNotBusy := CT7.isBusy, reachedSensor := sensorCT8, reachedSensorBack := sensorCT7);
  forwardCT8 := CT8.forwardMotor;
  forwardScT6 := ScT6.forwardMotor;
  forwardSbT6 := SbT6.forwardMotor;
  backCT8 := CT8.backMotor;
  forwardSaT6 := SaT6.forwardMotor;
  backScT6 := ScT6.backMotor;
  backSaT6 := SaT6.backMotor;
  forwardMT6 := MT6.forwardMotor;
  forwardSbT7 := SbT7.forwardMotor;
  backSbT6 := SbT6.backMotor;
  rightRotScT6 := ScT6.rightRotMotor;
  forwardCT7 := CT7.forwardMotor;
  forwardAT2 := AT2.forwardMotor;
  forwardSaT7 := SaT7.forwardMotor;
  rightRotSaT6 := SaT6.rightRotMotor;
  backMT6 := MT6.backMotor;
  rightRotCT8 := CT8.rightRotMotor;
  rightRotSbT6 := SbT6.rightRotMotor;
  leftRotScT6 := ScT6.leftRotMotor;
  backSbT7 := SbT7.backMotor;
  forwardMT5 := MT5.forwardMotor;
  backAT2 := AT2.backMotor;
  backSaT7 := SaT7.backMotor;
  rightRotMT6 := MT6.rightRotMotor;
  leftRotSaT6 := SaT6.leftRotMotor;
  backCT7 := CT7.backMotor;
  leftRotCT8 := CT8.leftRotMotor;
  OR210_OUT := OR(CT8.forwardMotor, CT8.isBusy);
  CT9(reachedSensor := sensorCT9, backSignal := runBackCT9_ex, backNotBusy := OR210_OUT, reachedSensorBack := sensorCT8);
  backCT9 := CT9.backMotor;
  leftRotSbT6 := SbT6.leftRotMotor;
  backMT5 := MT5.backMotor;
  leftRotMT6 := MT6.leftRotMotor;
  backScT7 := ScT7.backMotor;
  OR209_OUT := OR(CT2.forwardMotor, CT2.isBusy);
  CT3(reachedSensor := sensorCT3, backSignal := runBackCT2_ex, backNotBusy := OR209_OUT, reachedSensorBack := sensorCT2);
END_PROGRAM

PROGRAM program1
  VAR_EXTERNAL
    ii : BOOL;
    runFrontAT1_ex : BOOL;
    runFrontSaT1_ex : BOOL;
    runFrontSaT2_ex : BOOL;
    runFrontSbT1_ex : BOOL;
    runFrontSbT2_ex : BOOL;
    runFrontScT1_ex : BOOL;
    runFrontScT2_ex : BOOL;
    runFrontMT1_ex : BOOL;
    runFrontMT2_ex : BOOL;
    runFrontCT1_ex : BOOL;
    sendDownSaT2_ex : BOOL;
    sendDownCT2_ex : BOOL;
    sensorAT1_ex : BOOL;
    sensorSaT1_ex : BOOL;
    sensorSaT2_ex : BOOL;
    sensorSbT1_ex : BOOL;
    sensorSbT2_ex : BOOL;
    sensorScT1_ex : BOOL;
    sensorScT2_ex : BOOL;
    sensorMT1_ex : BOOL;
    sensorMT2_ex : BOOL;
    sensorCT1_ex : BOOL;
    sensorCT2_ex : BOOL;
    sensorCT4_ex : BOOL;
  END_VAR

  INITIAL_STEP Step0:
  END_STEP

  TRANSITION FROM Step0 TO Step1
    := true;
  END_TRANSITION

  STEP Step1:
    runFrontAT1_ex(N);
  END_STEP

  TRANSITION FROM Step1 TO Step2
    := sensorAT1_ex;
  END_TRANSITION

  STEP Step2:
    runFrontSaT1_ex(N);
  END_STEP

  TRANSITION FROM Step2 TO (Step4, Step6)
    := NOT sensorAT1_ex;
  END_TRANSITION

  STEP Step4:
  END_STEP

  TRANSITION FROM Step4 TO Step3
    := sensorSaT1_ex;
  END_TRANSITION

  STEP Step3:
    runFrontSaT2_ex(N);
  END_STEP

  TRANSITION FROM Step3 TO Step5
    := not sensorSaT1_ex;
  END_TRANSITION

  STEP Step5:
  END_STEP

  TRANSITION FROM Step5 TO Step7
    := sensorSaT2_ex;
  END_TRANSITION

  STEP Step7:
    runFrontSbT1_ex(N);
  END_STEP

  TRANSITION FROM Step7 TO Step8
    := not sensorSaT2_ex;
  END_TRANSITION

  STEP Step8:
  END_STEP

  TRANSITION FROM Step8 TO Step9
    := sensorSbT1_ex;
  END_TRANSITION

  STEP Step9:
    runFrontSbT2_ex(N);
  END_STEP

  TRANSITION FROM Step9 TO Step10
    := not sensorSbT1_ex;
  END_TRANSITION

  STEP Step10:
  END_STEP

  TRANSITION FROM Step10 TO Step11
    := sensorSbT2_ex;
  END_TRANSITION

  STEP Step11:
    runFrontScT1_ex(N);
  END_STEP

  TRANSITION FROM Step11 TO Step12
    := not sensorSbT2_ex;
  END_TRANSITION

  STEP Step12:
  END_STEP

  TRANSITION FROM Step12 TO Step13
    := sensorScT1_ex;
  END_TRANSITION

  STEP Step13:
    runFrontScT2_ex(N);
  END_STEP

  TRANSITION FROM Step13 TO Step14
    := not sensorScT1_ex;
  END_TRANSITION

  STEP Step14:
  END_STEP

  TRANSITION FROM Step14 TO Step15
    := sensorScT2_ex;
  END_TRANSITION

  STEP Step15:
    runFrontMT1_ex(N);
  END_STEP

  TRANSITION FROM Step15 TO Step16
    := not sensorScT2_ex;
  END_TRANSITION

  STEP Step16:
  END_STEP

  TRANSITION FROM Step16 TO Step17
    := sensorMT1_ex;
  END_TRANSITION

  STEP Step17:
    runFrontMT2_ex(N);
  END_STEP

  TRANSITION FROM Step17 TO Step18
    := not sensorMT1_ex;
  END_TRANSITION

  STEP Step18:
  END_STEP

  TRANSITION FROM Step18 TO Step19
    := sensorMT2_ex;
  END_TRANSITION

  STEP Step19:
    runFrontCT1_ex(N);
  END_STEP

  TRANSITION FROM Step19 TO Step20
    := not sensorMT2_ex;
  END_TRANSITION

  STEP Step20:
  END_STEP

  TRANSITION FROM Step20 TO Step21
    := sensorCT1_ex;
  END_TRANSITION

  STEP Step21:
    sendDownCT2_ex(N);
  END_STEP

  TRANSITION FROM Step21 TO Step22
    := not sensorCT1_ex;
  END_TRANSITION

  STEP Step22:
  END_STEP

  TRANSITION FROM Step22 TO Step23
    := sensorCT2_ex;
  END_TRANSITION

  STEP Step23:
  END_STEP

  TRANSITION FROM Step23 TO Step24
    := not sensorCT2_ex;
  END_TRANSITION

  STEP Step24:
  END_STEP

  TRANSITION FROM Step24 TO Step25
    := sensorCT4_ex;
  END_TRANSITION

  STEP Step25:
  END_STEP

  TRANSITION FROM Step25 TO Step0
    := not sensorCT4_ex;
  END_TRANSITION

  STEP Step6:
  END_STEP

  TRANSITION FROM Step6 TO Step0
    := true;
  END_TRANSITION

END_PROGRAM

PROGRAM program2
  VAR
    warehouseIn AT %IW0.0.2.0 : INT := 2;
  END_VAR
  VAR
    P1_reg : BOOL;
    P2_reg : BOOL;
    P3_reg : BOOL;
    P4_reg : BOOL;
    P5_reg : BOOL;
    P6_reg : BOOL;
    P7_reg : BOOL;
    P8_reg : BOOL;
    P9_reg : BOOL;
  END_VAR
  VAR
    sensorAT1 AT %IX0.0.0.0 : BOOL;
  END_VAR

  INITIAL_STEP initialLoad:
  END_STEP

  TRANSITION FROM initialLoad TO putP1
    := P1_reg;
  END_TRANSITION

  STEP putP1:
    P1(N);
  END_STEP

  ACTION P1:
    warehouseIn := 1;
  END_ACTION

  TRANSITION FROM putP1 TO Step1
    := sensorAT1;
  END_TRANSITION

  STEP Step1:
    resetWarehouse(N);
  END_STEP

  ACTION resetWarehouse:
    warehouseIn := 0;
  END_ACTION

  TRANSITION FROM Step1 TO initialLoad
    := not sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad TO putP2
    := P2_reg;
  END_TRANSITION

  STEP putP2:
    P2(N);
  END_STEP

  ACTION P2:
    warehouseIn := 2;
  END_ACTION

  TRANSITION FROM putP2 TO Step1
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad TO putP3
    := P3_reg;
  END_TRANSITION

  STEP putP3:
    P3(N);
  END_STEP

  ACTION P3:
    warehouseIn := 3;
  END_ACTION

  TRANSITION FROM putP3 TO Step1
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad TO putP4
    := P4_reg;
  END_TRANSITION

  STEP putP4:
    P4(N);
  END_STEP

  ACTION P4:
    warehouseIn := 4;
  END_ACTION

  TRANSITION FROM putP4 TO Step1
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad TO putP6
    := P6_reg;
  END_TRANSITION

  STEP putP6:
    P6(N);
  END_STEP

  ACTION P6:
    warehouseIn := 6;
  END_ACTION

  TRANSITION FROM putP6 TO Step1
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad TO putP7
    := P7_reg;
  END_TRANSITION

  STEP putP7:
    P7(N);
  END_STEP

  ACTION P7:
    warehouseIn := 7;
  END_ACTION

  TRANSITION FROM putP7 TO Step1
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad TO putP8
    := P8_reg;
  END_TRANSITION

  STEP putP8:
    P8(N);
  END_STEP

  ACTION P8:
    warehouseIn := 8;
  END_ACTION

  TRANSITION FROM putP8 TO Step1
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad TO putP5
    := P5_reg;
  END_TRANSITION

  STEP putP5:
    P5(N);
  END_STEP

  ACTION P5:
    warehouseIn := 5;
  END_ACTION

  TRANSITION FROM putP5 TO Step1
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad TO putP9
    := P9_reg;
  END_TRANSITION

  STEP putP9:
    P9(N);
  END_STEP

  ACTION P9:
    warehouseIn := 9;
  END_ACTION

  TRANSITION FROM putP9 TO Step1
    := sensorAT1;
  END_TRANSITION

END_PROGRAM


CONFIGURATION config
  VAR_GLOBAL
    ii : BOOL;
    pushToRollCT4_ex : BOOL;
    pushToRollCT5_ex : BOOL;
    pushToRollCT6_ex : BOOL;
    runFrontAT1_ex : BOOL;
    runFrontSaT1_ex : BOOL;
    runFrontSaT2_ex : BOOL;
    runFrontSbT1_ex : BOOL;
    runFrontSbT2_ex : BOOL;
    runFrontScT1_ex : BOOL;
    runFrontScT2_ex : BOOL;
    runFrontMT1_ex : BOOL;
    runFrontMT2_ex : BOOL;
    runFrontCT1_ex : BOOL;
    runFrontCT2_ex : BOOL;
    runFrontCT3_ex : BOOL;
    runBackCT2_ex : BOOL;
    runBackCT3_ex : BOOL;
    sendDownSaT2_ex : BOOL;
    sendDownSbT2_ex : BOOL;
    sendDownScT2_ex : BOOL;
    sendDownMT2_ex : BOOL;
    sendDownCT2_ex : BOOL;
    sensorAT1_ex : BOOL;
    sensorSaT1_ex : BOOL;
    sensorSaT2_ex : BOOL;
    sensorSbT1_ex : BOOL;
    sensorSbT2_ex : BOOL;
    sensorScT1_ex : BOOL;
    sensorScT2_ex : BOOL;
    sensorMT1_ex : BOOL;
    sensorMT2_ex : BOOL;
    sensorCT1_ex : BOOL;
    sensorCT2_ex : BOOL;
    sensorCT3_ex : BOOL;
    sensorCT4_ex : BOOL;
    sensorCT5_ex : BOOL;
    sensorCT6_ex : BOOL;
    sensorAT2_ex : BOOL;
    sensorSaT7_ex : BOOL;
    sensorSaT6_ex : BOOL;
    sensorSbT7_ex : BOOL;
    sensorSbT6_ex : BOOL;
    sensorScT7_ex : BOOL;
    sensorScT6_ex : BOOL;
    sensorMT5_ex : BOOL;
    sensorMT6_ex : BOOL;
    sensorCT7_ex : BOOL;
    sensorCT8_ex : BOOL;
    sensorCT9_ex : BOOL;
    sendDownSaT6_ex : BOOL;
    sendDownSbT6_ex : BOOL;
    sendDownScT6_ex : BOOL;
    sendDownMT6_ex : BOOL;
    sendDownCT8_ex : BOOL;
    runBackAT2_ex : BOOL;
    runBackSaT7_ex : BOOL;
    runBackSaT6_ex : BOOL;
    sendUpSaT6_ex : BOOL;
    runBackSbT7_ex : BOOL;
    runBackSbT6_ex : BOOL;
    runFrontSbT6_ex : BOOL;
    runBackScT7_ex : BOOL;
    runBackScT6_ex : BOOL;
    runFrontScT6_ex : BOOL;
    runBackMT5_ex : BOOL;
    runBackMT6_ex : BOOL;
    runBackCT7_ex : BOOL;
    runBackCT8_ex : BOOL;
    runFrontCT8_ex : BOOL;
    runFrontCT4_ex : BOOL;
    runFrontCT5_ex : BOOL;
    runFrontCT6_ex : BOOL;
    runBackCT9_ex : BOOL;
  END_VAR

  RESOURCE resource1 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance1 WITH task0 : program2;
    PROGRAM instance2 WITH task0 : program1;
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
