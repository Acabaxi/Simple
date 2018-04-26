TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    ADD10_OUT : UINT;
    EQ13_OUT : BOOL;
    SEL15_OUT : UINT;
    AND7_OUT : BOOL;
  END_VAR

  ADD10_OUT := ADD(COUNTER, 1);
  EQ13_OUT := EQ(N, ADD10_OUT);
  SEL15_OUT := SEL(EQ13_OUT, ADD10_OUT, 0);
  COUNTER := SEL15_OUT;
  AND7_OUT := AND(EQ13_OUT, TRIG);
  py_eval(TRIG := AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK



FUNCTION_BLOCK GetBoolString
  VAR_INPUT
    VALUE : BOOL;
  END_VAR
  VAR_OUTPUT
    CODE : STRING;
  END_VAR

  IF VALUE THEN
    CODE := 'True';
  ELSE
    CODE := 'False';
  END_IF;
END_FUNCTION_BLOCK

FUNCTION_BLOCK Button
  VAR
    ID : STRING;
  END_VAR
  VAR_INPUT
    back_id : STRING;
    sele_id : STRING;
    toggle : BOOL;
    set_state : BOOL;
    state_in : BOOL;
  END_VAR
  VAR_OUTPUT
    state_out : BOOL;
  END_VAR
  VAR
    init_Command : python_eval;
    GetButtonState : GetBoolString;
    setstate_Command : python_eval;
    getstate_Command : python_poll;
    GetButtonToggle : GetBoolString;
    CONCAT2_OUT : STRING;
    CONCAT22_OUT : STRING;
    STRING_TO_INT25_OUT : INT;
    INT_TO_BOOL26_OUT : BOOL;
    AND31_OUT : BOOL;
    CONCAT7_OUT : STRING;
  END_VAR

  GetButtonToggle(VALUE := toggle);
  CONCAT2_OUT := CONCAT('createSVGUIControl("button",back_id="', back_id, '",sele_id="', sele_id, '",toggle=', GetButtonToggle.CODE, ',active=True)');
  init_Command(TRIG := BOOL#1, CODE := CONCAT2_OUT);
  ID := init_Command.RESULT;
  CONCAT22_OUT := CONCAT('int(getAttr(', ID, ',"state",False))');
  getstate_Command(TRIG := init_Command.ACK, CODE := CONCAT22_OUT);
  STRING_TO_INT25_OUT := STRING_TO_INT(getstate_Command.RESULT);
  INT_TO_BOOL26_OUT := INT_TO_BOOL(STRING_TO_INT25_OUT);
  state_out := INT_TO_BOOL26_OUT;
  AND31_OUT := AND(init_Command.ACK, set_state);
  GetButtonState(VALUE := state_in);
  CONCAT7_OUT := CONCAT('setAttr(', ID, ',"state",', GetButtonState.CODE, ')');
  setstate_Command(TRIG := AND31_OUT, CODE := CONCAT7_OUT);
END_FUNCTION_BLOCK

FUNCTION_BLOCK Led
  VAR
    ID : STRING;
  END_VAR
  VAR_INPUT
    back_id : STRING;
    sele_id : STRING;
    state_in : BOOL;
  END_VAR
  VAR
    init_Command : python_eval;
    setstate_Command : python_poll;
    GetLedState : GetBoolString;
    CONCAT2_OUT : STRING;
    CONCAT7_OUT : STRING;
  END_VAR

  CONCAT2_OUT := CONCAT('createSVGUIControl("button",back_id="', back_id, '",sele_id="', sele_id, '",toggle=True,active=False)');
  init_Command(TRIG := BOOL#1, CODE := CONCAT2_OUT);
  ID := init_Command.RESULT;
  GetLedState(VALUE := state_in);
  CONCAT7_OUT := CONCAT('setAttr(', ID, ',"state",', GetLedState.CODE, ')');
  setstate_Command(TRIG := init_Command.ACK, CODE := CONCAT7_OUT);
END_FUNCTION_BLOCK

FUNCTION_BLOCK TextCtrl
  VAR
    ID : STRING;
  END_VAR
  VAR_INPUT
    back_id : STRING;
    set_text : BOOL;
    text : STRING;
  END_VAR
  VAR
    SVGUI_TEXTCTRL : python_eval;
    setstate_Command : python_eval;
    CONCAT1_OUT : STRING;
    AND31_OUT : BOOL;
    CONCAT12_OUT : STRING;
  END_VAR

  CONCAT1_OUT := CONCAT('createSVGUIControl("textControl", back_id="', back_id, '")');
  SVGUI_TEXTCTRL(TRIG := BOOL#1, CODE := CONCAT1_OUT);
  ID := SVGUI_TEXTCTRL.RESULT;
  AND31_OUT := AND(SVGUI_TEXTCTRL.ACK, set_text);
  CONCAT12_OUT := CONCAT('setAttr(', ID, ',"text","', text, '")');
  setstate_Command(TRIG := AND31_OUT, CODE := CONCAT12_OUT);
END_FUNCTION_BLOCK


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
    := frontNotBusy;
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
    := backNotBusy;
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
    := frontNotBusy;
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
    := backNotBusy;
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
    := upNotBusy;
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
    := downNotBusy;
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

PROGRAM program0
  VAR
    AT1 : LinearConveyor;
    SaT1 : LinearConveyor;
    SaT2 : RotaryConveyor;
    SbT1 : LinearConveyor;
  END_VAR
  VAR_EXTERNAL
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
  END_VAR
  VAR
    SbT2 : RotaryConveyor;
    backAT1 : BOOL;
    backSaT1 : BOOL;
  END_VAR
  VAR
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
    sensorPM22 AT %IX0.0.0.110 : BOOL;
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
    NOT92_OUT : BOOL;
    NOT80_OUT : BOOL;
    NOT75_OUT : BOOL;
    NOT64_OUT : BOOL;
    NOT52_OUT : BOOL;
    NOT47_OUT : BOOL;
    NOT14_OUT : BOOL;
    NOT40_OUT : BOOL;
    NOT32_OUT : BOOL;
    NOT31_OUT : BOOL;
    NOT98_OUT : BOOL;
  END_VAR

  sensorSaT1_ex := sensorSaT1;
  sensorSaT2_ex := sensorSaT2;
  sensorSbT2_ex := sensorSbT2;
  sensorScT1_ex := sensorScT1;
  sensorScT2_ex := sensorScT2;
  sensorAT1_ex := sensorAT1;
  sensorSbT1_ex := sensorSbT1;
  sensorMT1_ex := sensorMT1;
  sensorCT3_ex := sensorCT3;
  sensorMT2_ex := sensorMT2;
  sensorCT2_ex := sensorCT2;
  sensorCT1_ex := sensorCT1;
  CT2(backSignal := runBackCT2_ex, forwardSignal := runFrontCT2_ex, sendDownSignal := sendDownCT2_ex, sensorRotRight := sensorRotRightCT2, sensorRotLeft := sensorRotLeftCT2, reachedSensor := sensorCT2);
  NOT92_OUT := NOT(CT2.isBusy);
  CT1(reachedSensor := sensorCT1, forwardSignal := runFrontCT1_ex, frontNotBusy := NOT92_OUT, reachedSensorFront := sensorCT2);
  NOT80_OUT := NOT(CT1.isBusy);
  MT2(forwardSignal := runFrontMT2_ex, sendDownSignal := sendDownMT2_ex, sensorRotRight := sensorRotRightMT2, sensorRotLeft := sensorRotLeftMT2, frontNotBusy := NOT80_OUT, reachedSensorFront := sensorCT1, reachedSensor := sensorMT2);
  NOT75_OUT := NOT(MT2.isBusy);
  MT1(reachedSensor := sensorMT1, forwardSignal := runFrontMT1_ex, frontNotBusy := NOT75_OUT, reachedSensorFront := sensorMT2);
  NOT64_OUT := NOT(MT1.isBusy);
  ScT2(forwardSignal := runFrontScT2_ex, sendDownSignal := sendDownScT2_ex, sensorRotRight := sensorRotRightScT2, sensorRotLeft := sensorRotLeftScT2, frontNotBusy := NOT64_OUT, reachedSensor := sensorScT2);
  NOT52_OUT := NOT(ScT2.isBusy);
  ScT1(reachedSensor := sensorScT1, forwardSignal := runFrontSbT1_ex, frontNotBusy := NOT52_OUT, reachedSensorFront := sensorScT2);
  NOT47_OUT := NOT(ScT1.isBusy);
  SbT2(forwardSignal := runFrontSbT2_ex, sendDownSignal := sendDownSbT2_ex, sensorRotRight := sensorRotRightSbT2, sensorRotLeft := sensorRotLeftSbT2, frontNotBusy := NOT47_OUT, reachedSensorFront := sensorScT1, reachedSensor := sensorSbT2);
  NOT14_OUT := NOT(SbT2.isBusy);
  SbT1(reachedSensor := sensorSbT1, forwardSignal := runFrontSbT1_ex, frontNotBusy := NOT14_OUT, reachedSensorFront := sensorSbT2);
  NOT40_OUT := NOT(SbT1.isBusy);
  SaT2(forwardSignal := runFrontSaT2_ex, sendDownSignal := sendDownSaT2_ex, sensorRotRight := sensorRotRightSaT2, sensorRotLeft := sensorRotLeftSaT2, frontNotBusy := NOT40_OUT, reachedSensorFront := sensorSbT1, reachedSensor := sensorSaT2);
  forwardSaT2 := SaT2.forwardMotor;
  forwardScT2 := ScT2.forwardMotor;
  forwardCT2 := CT2.forwardMotor;
  forwardSbT1 := SbT1.forwardMotor;
  forwardSbT2 := SbT2.forwardMotor;
  forwardMT2 := MT2.forwardMotor;
  forwardCT1 := CT1.forwardMotor;
  NOT32_OUT := NOT(SaT2.isBusy);
  SaT1(reachedSensor := sensorSaT1, forwardSignal := runFrontSaT1_ex, frontNotBusy := NOT32_OUT, reachedSensorFront := sensorSaT2);
  NOT31_OUT := NOT(SaT1.isBusy);
  AT1(reachedSensor := sensorAT1, forwardSignal := runFrontAT1_ex, frontNotBusy := NOT31_OUT, reachedSensorFront := sensorSaT1);
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
  NOT98_OUT := NOT(CT2.isBusy);
  CT3(reachedSensor := sensorCT3, backSignal := runBackCT2_ex, backNotBusy := NOT98_OUT, reachedSensorBack := sensorCT2);
END_PROGRAM

PROGRAM program1
  VAR_EXTERNAL
    ii : BOOL;
    runFrontAT1_ex : BOOL;
    runFrontSaT1_ex : BOOL;
    runFrontSaT2_ex : BOOL;
    runFrontSbT1_ex : BOOL;
    runFrontSbT2_ex : BOOL;
    sendDownSaT2_ex : BOOL;
    sensorAT1_ex : BOOL;
    sensorSaT1_ex : BOOL;
    sensorSaT2_ex : BOOL;
    sensorSbT1_ex : BOOL;
    sensorSbT2_ex : BOOL;
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

  TRANSITION FROM Step2 TO Step4
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

  TRANSITION FROM Step9 TO Step0
    := not sensorSbT1_ex;
  END_TRANSITION

END_PROGRAM


CONFIGURATION config
  VAR_GLOBAL
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
  END_VAR

  RESOURCE resource1 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance1 WITH task0 : program2;
    PROGRAM instance2 WITH task0 : program1;
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
