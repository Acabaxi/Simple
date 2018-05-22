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


FUNCTION_BLOCK removeFromWarehouse
  VAR_INPUT
    pieceNum : INT;
  END_VAR
  VAR_OUTPUT
    warehouseIn : INT;
  END_VAR
  VAR_INPUT
    sensorAT1 : BOOL;
  END_VAR

  INITIAL_STEP initialLoad1:
  END_STEP

  TRANSITION FROM initialLoad1 TO putP5
    := pieceNum = 2;
  END_TRANSITION

  STEP putP5:
    P2(N);
  END_STEP

  ACTION P2:
    warehouseIn := 2;
  END_ACTION

  TRANSITION FROM putP5 TO Step0
    := sensorAT1;
  END_TRANSITION

  STEP Step0:
    resetWarehouse(N);
  END_STEP

  ACTION resetWarehouse:
    warehouseIn := 0;
  END_ACTION

  TRANSITION FROM Step0 TO Step1
    := not sensorAT1;
  END_TRANSITION

  STEP Step1:
  END_STEP

  TRANSITION FROM Step1 TO initialLoad1
    := true;
  END_TRANSITION

  TRANSITION FROM initialLoad1 TO putP6
    := pieceNum = 3;
  END_TRANSITION

  STEP putP6:
    P3(N);
  END_STEP

  ACTION P3:
    warehouseIn := 3;
  END_ACTION

  TRANSITION FROM putP6 TO Step0
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad1 TO putP7
    := pieceNum = 4;
  END_TRANSITION

  STEP putP7:
    P4(N);
  END_STEP

  ACTION P4:
    warehouseIn := 4;
  END_ACTION

  TRANSITION FROM putP7 TO Step0
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad1 TO putP9
    := pieceNum = 6;
  END_TRANSITION

  STEP putP9:
    P6(N);
  END_STEP

  ACTION P6:
    warehouseIn := 6;
  END_ACTION

  TRANSITION FROM putP9 TO Step0
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad1 TO putP10
    := pieceNum = 7;
  END_TRANSITION

  STEP putP10:
    P7(N);
  END_STEP

  ACTION P7:
    warehouseIn := 7;
  END_ACTION

  TRANSITION FROM putP10 TO Step0
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad1 TO putP11
    := pieceNum = 8;
  END_TRANSITION

  STEP putP11:
    P8(N);
  END_STEP

  ACTION P8:
    warehouseIn := 8;
  END_ACTION

  TRANSITION FROM putP11 TO Step0
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad1 TO putP8
    := pieceNum = 5;
  END_TRANSITION

  STEP putP8:
    P5(N);
  END_STEP

  ACTION P5:
    warehouseIn := 5;
  END_ACTION

  TRANSITION FROM putP8 TO Step0
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad1 TO putP12
    := pieceNum = 9;
  END_TRANSITION

  STEP putP12:
    P9(N);
  END_STEP

  ACTION P9:
    warehouseIn := 9;
  END_ACTION

  TRANSITION FROM putP12 TO Step0
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad1 TO putP4
    := pieceNum = 1;
  END_TRANSITION

  STEP putP4:
    P1(N);
  END_STEP

  ACTION P1:
    warehouseIn := 1;
  END_ACTION

  TRANSITION FROM putP4 TO Step0
    := sensorAT1;
  END_TRANSITION

END_FUNCTION_BLOCK

FUNCTION_BLOCK Gantry
  VAR_OUTPUT
    motorZUp : BOOL;
    motorZUp0 : BOOL;
    motorZDown : BOOL;
    motorYUp : BOOL;
    motorYDown : BOOL;
    motorXRight : BOOL;
    motorXLeft : BOOL;
    grab : BOOL;
    gantryBusy : BOOL;
  END_VAR
  VAR_INPUT
    sensorZTop : BOOL;
    sensorZBottom : BOOL;
    sensorY0 : BOOL;
    sensorY1 : BOOL;
    sensorY2 : BOOL;
    sensorY3 : BOOL;
    sensorY4 : BOOL;
    sensorX0 : BOOL;
    sensorX1 : BOOL;
    pieceSensor : BOOL;
  END_VAR
  VAR
    resetTimerY : BOOL;
    resetTimerX : BOOL;
    TON1 : TON;
    TON2 : TON;
    grabTimer : BOOL := 0;
    Yposition : INT := 0;
    Xposition : INT := 0;
  END_VAR
  VAR_INPUT
    pickPiece : BOOL;
    releasePiece : BOOL;
    X0Y0 : BOOL;
    X0Y1 : BOOL;
    X0Y2 : BOOL;
    X0Y3 : BOOL;
    X0Y4 : BOOL;
    X1Y0 : BOOL;
    X1Y1 : BOOL;
    X1Y2 : BOOL;
    X1Y3 : BOOL;
    X1Y4 : BOOL;
  END_VAR
  VAR
    TON3 : TON;
    TON4 : TON;
  END_VAR

  INITIAL_STEP Step0:
    motorZUp(N);
    gantryBusy(S);
    COMPUTE_FUNCTION_BLOCKS(S);
  END_STEP

  ACTION COMPUTE_FUNCTION_BLOCKS:
    TON1(IN := resetTimerY, PT := T#13s);
    TON2(IN := resetTimerX, PT := T#5s);
    TON3(IN := grabTimer, PT := T#2s);
    TON4(IN := grabTimer, PT := T#1s);
  END_ACTION

  TRANSITION FROM Step0 TO (Step8, Step7)
    := sensorZTop;
  END_TRANSITION

  STEP Step8:
    motorYUp(N);
    resetTimerY(N);
  END_STEP

  TRANSITION FROM Step8 TO Step2
    := TON1.Q;
  END_TRANSITION

  STEP Step2:
    motorYDown(N);
  END_STEP

  TRANSITION FROM Step2 TO Step5
    := sensorY0;
  END_TRANSITION

  STEP Step5:
  END_STEP

  TRANSITION FROM (Step5, Step4) TO gantryIdle
    := true;
  END_TRANSITION

  STEP gantryIdle:
    gantryBusy(R);
    setGantryBusy(P0);
    resetMotors(N);
  END_STEP

  ACTION setGantryBusy:
    gantryBusy := 1;
  END_ACTION

  ACTION resetMotors:
    motorZUp := 0;
    motorZDown := 0;

    motorYUp := 0;
    motorYDown := 0;

    motorXRight := 0;
    motorXLeft := 0;
  END_ACTION

  TRANSITION FROM gantryIdle TO Step6
    := X0Y0;
  END_TRANSITION

  STEP Step6:
    motorZUp(N);
  END_STEP

  TRANSITION FROM Step6 TO Step9
    := sensorZTop;
  END_TRANSITION

  STEP Step9:
    gotoY0(N);
    gotoX0(N);
  END_STEP

  ACTION gotoY0:
    if sensorY1 = 1 OR sensorY2 = 1 OR sensorY3 = 1 OR sensorY4 = 1 then
      motorYUp := 1;
    elsif sensorY0 = 1 then
      motorYUp := 0;
    end_if;
  END_ACTION

  ACTION gotoX0:
    if sensorX0 = 0 then
      motorXLeft := 1;
    elsif sensorX0 = 1 then
      motorXLeft := 0;
    end_if;
  END_ACTION

  TRANSITION FROM Step9 TO gantryIdle
    := sensorX0 = 1 AND sensorY0 = 1;
  END_TRANSITION

  TRANSITION FROM gantryIdle TO Step12
    := X1Y1;
  END_TRANSITION

  STEP Step12:
    motorZUp(N);
  END_STEP

  TRANSITION FROM Step12 TO Step13
    := sensorZTop;
  END_TRANSITION

  STEP Step13:
    gotoY1(N);
    gotoX1(N);
  END_STEP

  ACTION gotoY1:
    if sensorY2 = 1 OR sensorY3 = 1 OR sensorY4 = 1 then
      motorYUp := 1;
    elsif sensorY0 = 1 then
      motorYDown := 1;
    elsif sensorY1 = 1 then
      motorYUp := 0;
      motorYDown := 0;
      end_if;
  END_ACTION

  ACTION gotoX1:

    if sensorX1 = 0 then
       motorXRight := 1;
    elsif sensorX1 = 1 then
       motorXRight := 0;
    end_if;

  END_ACTION

  TRANSITION FROM Step13 TO gantryIdle
    := sensorX1 = 1 AND sensorY1= 1;
  END_TRANSITION

  TRANSITION FROM gantryIdle TO Step14
    := X1Y2;
  END_TRANSITION

  STEP Step14:
    motorZUp(N);
  END_STEP

  TRANSITION FROM Step14 TO Step15
    := sensorZTop;
  END_TRANSITION

  STEP Step15:
    gotoY2(N);
    gotoX1(N);
  END_STEP

  ACTION gotoY2:
    if sensorY3 = 1 OR sensorY4 = 1 then
      motorYUp := 1;
    elsif sensorY0 = 1 OR sensorY1 = 1 then
      motorYDown := 1;
    elsif sensorY2 = 1 then
      motorYUp := 0;
      motorYDown := 0;
      end_if;
  END_ACTION

  TRANSITION FROM Step15 TO gantryIdle
    := sensorX1 = 1 AND sensorY2= 1;
  END_TRANSITION

  TRANSITION FROM gantryIdle TO Step16
    := X1Y3;
  END_TRANSITION

  STEP Step16:
    motorZUp(N);
  END_STEP

  TRANSITION FROM Step16 TO Step17
    := sensorZTop;
  END_TRANSITION

  STEP Step17:
    gotoY3(N);
    gotoX1(N);
  END_STEP

  ACTION gotoY3:
    if sensorY4 = 1 then
      motorYUp := 1;
      elsif sensorY0 = 1 OR sensorY1 = 1 OR sensorY2 = 1 then
      motorYDown := 1;
    elsif sensorY3 = 1 then
      motorYUp := 0;
      motorYDown := 0;
      end_if;
  END_ACTION

  TRANSITION FROM Step17 TO gantryIdle
    := sensorX1 = 1 AND sensorY3= 1;
  END_TRANSITION

  TRANSITION FROM gantryIdle TO Step11
    := X1Y4;
  END_TRANSITION

  STEP Step11:
    motorZUp(N);
  END_STEP

  TRANSITION FROM Step11 TO Step18
    := sensorZTop;
  END_TRANSITION

  STEP Step18:
    gotoY4(N);
    gotoX1(N);
  END_STEP

  ACTION gotoY4:
    if sensorY0 = 1 OR sensorY1 = 1 OR sensorY2 = 1 OR sensorY3 = 1 then
      motorYDown := 1;
    elsif sensorY4 = 1 then
      motorYUp := 0;
      motorYDown := 0;
      end_if;
  END_ACTION

  TRANSITION FROM Step18 TO gantryIdle
    := sensorX1 = 1 AND sensorY4= 1;
  END_TRANSITION

  TRANSITION FROM gantryIdle TO Step19
    := X0Y4;
  END_TRANSITION

  STEP Step19:
    motorZUp(N);
  END_STEP

  TRANSITION FROM Step19 TO Step20
    := sensorZTop;
  END_TRANSITION

  STEP Step20:
    gotoY4(N);
    gotoX0(N);
  END_STEP

  TRANSITION FROM Step20 TO gantryIdle
    := sensorX0 = 1 AND sensorY4= 1;
  END_TRANSITION

  TRANSITION FROM gantryIdle TO Step21
    := X0Y2;
  END_TRANSITION

  STEP Step21:
    motorZUp(N);
  END_STEP

  TRANSITION FROM Step21 TO Step22
    := sensorZTop;
  END_TRANSITION

  STEP Step22:
    gotoY2(N);
    gotoX0(N);
  END_STEP

  TRANSITION FROM Step22 TO gantryIdle
    := sensorX0 = 1 AND sensorY2= 1;
  END_TRANSITION

  TRANSITION FROM gantryIdle TO Step23
    := X0Y3;
  END_TRANSITION

  STEP Step23:
    motorZUp(N);
  END_STEP

  TRANSITION FROM Step23 TO Step24
    := sensorZTop;
  END_TRANSITION

  STEP Step24:
    gotoY3(N);
    gotoX0(N);
  END_STEP

  TRANSITION FROM Step24 TO gantryIdle
    := sensorX0 = 1 AND sensorY3= 1;
  END_TRANSITION

  TRANSITION FROM gantryIdle TO Step25
    := X0Y1;
  END_TRANSITION

  STEP Step25:
    motorZUp(N);
  END_STEP

  TRANSITION FROM Step25 TO Step26
    := sensorZTop;
  END_TRANSITION

  STEP Step26:
    gotoY1(N);
    gotoX0(N);
  END_STEP

  TRANSITION FROM Step26 TO gantryIdle
    := sensorX0 = 1 AND sensorY1= 1;
  END_TRANSITION

  TRANSITION FROM gantryIdle TO Step1
    := pickPiece;
  END_TRANSITION

  STEP Step1:
    motorZDown(N);
  END_STEP

  TRANSITION FROM Step1 TO Step10
    := sensorZBottom;
  END_TRANSITION

  STEP Step10:
    grab(S);
    grabTimer(N);
  END_STEP

  TRANSITION FROM Step10 TO Step27
    := TON3.Q;
  END_TRANSITION

  STEP Step27:
    motorZUp(N);
  END_STEP

  TRANSITION FROM Step27 TO gantryIdle
    := sensorZTop;
  END_TRANSITION

  TRANSITION FROM gantryIdle TO Step29
    := releasePiece;
  END_TRANSITION

  STEP Step29:
    motorZDown(N);
  END_STEP

  TRANSITION FROM Step29 TO Step28
    := sensorZBottom;
  END_TRANSITION

  STEP Step28:
    grab(R);
    grabTimer(N);
  END_STEP

  TRANSITION FROM Step28 TO Step30
    := TON4.Q;
  END_TRANSITION

  STEP Step30:
    motorZUp(N);
  END_STEP

  TRANSITION FROM Step30 TO gantryIdle
    := sensorZTop;
  END_TRANSITION

  TRANSITION FROM gantryIdle TO Step31
    := X1Y0;
  END_TRANSITION

  STEP Step31:
    motorZUp(N);
  END_STEP

  TRANSITION FROM Step31 TO Step32
    := sensorZTop;
  END_TRANSITION

  STEP Step32:
    gotoY0(N);
    gotoX1(N);
  END_STEP

  TRANSITION FROM Step32 TO gantryIdle
    := sensorX1 = 1 AND sensorY0 = 1;
  END_TRANSITION

  TRANSITION FROM Step8 TO Step5
    := sensorY0;
  END_TRANSITION

  STEP Step7:
    motorXLeft(N);
    resetTimerX(N);
  END_STEP

  TRANSITION FROM Step7 TO Step3
    := TON2.Q;
  END_TRANSITION

  STEP Step3:
    motorXRight(N);
  END_STEP

  TRANSITION FROM Step3 TO Step4
    := sensorX0;
  END_TRANSITION

  STEP Step4:
  END_STEP

  TRANSITION FROM Step7 TO Step4
    := sensorX0;
  END_TRANSITION

END_FUNCTION_BLOCK

FUNCTION_BLOCK LinearConveyor
  VAR_INPUT
    receivePiece : BOOL;
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

  INITIAL_STEP initLinearStep:
    isBusy(R);
  END_STEP

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
    := not frontNotBusy ;
  END_TRANSITION

  STEP moveFrontStep:
    forwardTimerOn(N);
    forwardMotor(S);
  END_STEP

  TRANSITION FROM moveFrontStep TO Step0
    := not reachedSensor;
  END_TRANSITION

  STEP Step0:
  END_STEP

  TRANSITION FROM Step0 TO turnOffFront
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

  TRANSITION FROM moveBackStep TO Step1
    := not reachedSensor;
  END_TRANSITION

  STEP Step1:
  END_STEP

  TRANSITION FROM Step1 TO turnOffBack
    := reachedSensorBack;
  END_TRANSITION

  STEP turnOffBack:
    backMotor(R);
  END_STEP

  TRANSITION FROM turnOffBack TO initLinearStep
    := true;
  END_TRANSITION

  TRANSITION FROM initLinearStep TO moveFront0
    := receivePiece;
  END_TRANSITION

  STEP moveFront0:
    forwardMotor(N);
  END_STEP

  TRANSITION FROM moveFront0 TO initLinearStep
    := reachedSensor;
  END_TRANSITION

END_FUNCTION_BLOCK

FUNCTION_BLOCK RotaryConveyor
  VAR_INPUT
    sendUpRightSignal : BOOL;
    sendRightDownSignal : BOOL;
    sendRIghtUpSignal : BOOL;
    receivePiece : BOOL;
    backSignal : BOOL;
  END_VAR
  VAR
    forwardTimerOn : BOOL;
  END_VAR
  VAR_INPUT
    forwardSignal : BOOL;
  END_VAR
  VAR_OUTPUT
    readyToReceive : BOOL;
  END_VAR
  VAR_INPUT
    sendDownSignal : BOOL;
    sendLeftDownSignal : BOOL;
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

  INITIAL_STEP initLinearStep:
    isBusy(R);
    resetPosition(N);
  END_STEP

  ACTION resetPosition:
    leftRotMotor := NOT(sensorRotLeft);
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
    := not frontNotBusy ;
  END_TRANSITION

  STEP moveFrontStep:
    forwardTimerOn(N);
    forwardMotor(S);
  END_STEP

  TRANSITION FROM moveFrontStep TO Step1
    := not reachedSensor;
  END_TRANSITION

  STEP Step1:
  END_STEP

  TRANSITION FROM Step1 TO turnOffFront
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

  TRANSITION FROM moveBackStep TO Step2
    := not reachedSensor;
  END_TRANSITION

  STEP Step2:
  END_STEP

  TRANSITION FROM Step2 TO turnOffBack
    := reachedSensorBack;
  END_TRANSITION

  STEP turnOffBack:
    backMotor(R);
  END_STEP

  TRANSITION FROM turnOffBack TO initLinearStep
    := true;
  END_TRANSITION

  TRANSITION FROM initLinearStep TO rotateRight2
    := sendRightDownSignal;
  END_TRANSITION

  STEP rotateRight2:
    backMotor(N);
  END_STEP

  TRANSITION FROM rotateRight2 TO rightRotateed2
    := reachedSensor;
  END_TRANSITION

  STEP rightRotateed2:
    rightRotMotor(N);
  END_STEP

  TRANSITION FROM rightRotateed2 TO notBusyFront2
    := sensorRotRight;
  END_TRANSITION

  STEP notBusyFront2:
  END_STEP

  TRANSITION FROM notBusyFront2 TO rotatingLeft2
    := not upNotBusy;
  END_TRANSITION

  STEP rotatingLeft2:
    forwardMotor(N);
  END_STEP

  TRANSITION FROM rotatingLeft2 TO Step3
    := reachedSensorDown;
  END_TRANSITION

  STEP Step3:
  END_STEP

  TRANSITION FROM Step3 TO initLinearStep
    := true;
  END_TRANSITION

  TRANSITION FROM initLinearStep TO rotateRight1
    := sendRightUpSignal;
  END_TRANSITION

  STEP rotateRight1:
    forwardMotor(N);
  END_STEP

  TRANSITION FROM rotateRight1 TO rightRotateed1
    := reachedSensor;
  END_TRANSITION

  STEP rightRotateed1:
    rightRotMotor(N);
  END_STEP

  TRANSITION FROM rightRotateed1 TO notBusyFront1
    := sensorRotRight;
  END_TRANSITION

  STEP notBusyFront1:
  END_STEP

  TRANSITION FROM notBusyFront1 TO rotatingLeft1
    := not upNotBusy;
  END_TRANSITION

  STEP rotatingLeft1:
    backMotor(N);
  END_STEP

  TRANSITION FROM rotatingLeft1 TO Step0
    := reachedSensorUp;
  END_TRANSITION

  STEP Step0:
  END_STEP

  TRANSITION FROM Step0 TO initLinearStep
    := true;
  END_TRANSITION

  TRANSITION FROM initLinearStep TO rotateRight0
    := sendUpRightSignal;
  END_TRANSITION

  STEP rotateRight0:
    rightRotMotor(N);
  END_STEP

  TRANSITION FROM rotateRight0 TO rightRotateed0
    := sensorRotRight;
  END_TRANSITION

  STEP rightRotateed0:
    forwardMotor(N);
    isBusy(S);
    readyToReceive(N);
  END_STEP

  TRANSITION FROM rightRotateed0 TO rotatingLeft0
    := reachedSensor;
  END_TRANSITION

  STEP rotatingLeft0:
    leftRotMotor(N);
  END_STEP

  TRANSITION FROM rotatingLeft0 TO notBusyBack1
    := sensorRotLeft;
  END_TRANSITION

  STEP notBusyBack1:
  END_STEP

  TRANSITION FROM notBusyBack1 TO moveBackStep1
    := not frontNotBusy;
  END_TRANSITION

  STEP moveBackStep1:
    forwardMotor(S);
  END_STEP

  TRANSITION FROM moveBackStep1 TO turnOffBack1
    := reachedSensorFront;
  END_TRANSITION

  STEP turnOffBack1:
    forwardMotor(R);
  END_STEP

  TRANSITION FROM turnOffBack1 TO initLinearStep
    := true;
  END_TRANSITION

  TRANSITION FROM initLinearStep TO rotateRight
    := sendLeftDownSignal;
  END_TRANSITION

  STEP rotateRight:
    rightRotMotor(N);
    isBusy(S);
  END_STEP

  TRANSITION FROM rotateRight TO rightRotateed
    := sensorRotRight;
  END_TRANSITION

  STEP rightRotateed:
    forwardMotor(N);
    readyToReceive(N);
  END_STEP

  TRANSITION FROM rightRotateed TO rotatingLeft
    := reachedSensor;
  END_TRANSITION

  STEP rotatingLeft:
    leftRotMotor(N);
  END_STEP

  TRANSITION FROM rotatingLeft TO notBusyBack0
    := sensorRotLeft;
  END_TRANSITION

  STEP notBusyBack0:
  END_STEP

  TRANSITION FROM notBusyBack0 TO moveBackStep0
    := not backNotBusy;
  END_TRANSITION

  STEP moveBackStep0:
    forwardTimerOn(N);
    backMotor(S);
  END_STEP

  TRANSITION FROM moveBackStep0 TO turnOffBack0
    := reachedSensorBack;
  END_TRANSITION

  STEP turnOffBack0:
    backMotor(R);
  END_STEP

  TRANSITION FROM turnOffBack0 TO initLinearStep
    := true;
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

  TRANSITION FROM initLinearStep TO moveFront1
    := receivePiece;
  END_TRANSITION

  STEP moveFront1:
    forwardMotor(N);
  END_STEP

  TRANSITION FROM moveFront1 TO initLinearStep
    := reachedSensor;
  END_TRANSITION

END_FUNCTION_BLOCK

FUNCTION_BLOCK WarehouseInConveyor
  VAR_INPUT
    reachedSensor : BOOL;
    backSignal : BOOL;
    warehouseBusy : BOOL;
  END_VAR
  VAR
    forwardTimerOn : BOOL;
  END_VAR
  VAR_INPUT
    forwardSignal : BOOL;
    putPieceInSignal : BOOL;
  END_VAR
  VAR_OUTPUT
    putPieceIn : BOOL;
  END_VAR
  VAR_INPUT
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

  TRANSITION FROM initLinearStep TO moveBack0
    := putPieceInSignal;
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

  TRANSITION FROM notBusyBack0 TO Step0
    := not warehouseBusy;
  END_TRANSITION

  STEP Step0:
    putPieceIn(N);
  END_STEP

  TRANSITION FROM Step0 TO initLinearStep
    := not reachedSensor;
  END_TRANSITION

END_FUNCTION_BLOCK

FUNCTION_BLOCK Pusher
  VAR
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
    pushUpSignal : BOOL;
    forwardSignal : BOOL;
    reachedSensor : BOOL;
    reachedRoll : BOOL;
    reachedSensorBack : BOOL;
    reachedSensorFront : BOOL;
    sensorPushForward : BOOL;
    sensorPushBack : BOOL;
    frontNotBusy : BOOL;
    backNotBusy : BOOL;
  END_VAR

  INITIAL_STEP initLinearStep:
    isBusy(R);
  END_STEP

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
    := reachedSensorFront;
  END_TRANSITION

  STEP turnOffFront0:
    forwardMotor(R);
  END_STEP

  TRANSITION FROM turnOffFront0 TO initLinearStep
    := true;
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
    := reachedSensorBack;
  END_TRANSITION

  STEP turnOffBack0:
    backMotor(R);
  END_STEP

  TRANSITION FROM turnOffBack0 TO initLinearStep
    := true;
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
    := reachedRoll;
  END_TRANSITION

  STEP retractPusher:
    pushMotorBack(N);
  END_STEP

  TRANSITION FROM retractPusher TO initLinearStep
    := sensorPushBack;
  END_TRANSITION

  TRANSITION FROM initLinearStep TO pushRoll0
    := pushUpSignal;
  END_TRANSITION

  STEP pushRoll0:
    backMotor(N);
  END_STEP

  TRANSITION FROM pushRoll0 TO notBusyFront2
    := reachedSensor;
  END_TRANSITION

  STEP notBusyFront2:
    isBusy(S);
  END_STEP

  TRANSITION FROM notBusyFront2 TO pushToRoll0
    := not rollBusy;
  END_TRANSITION

  STEP pushToRoll0:
    pushMotorForward(N);
  END_STEP

  TRANSITION FROM pushToRoll0 TO retractPusher0
    := reachedRoll;
  END_TRANSITION

  STEP retractPusher0:
    pushMotorBack(N);
  END_STEP

  TRANSITION FROM retractPusher0 TO initLinearStep
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

FUNCTION_BLOCK Machine
  VAR_INPUT
    machineType : BOOL;
    reachedSensor : BOOL;
  END_VAR
  VAR_OUTPUT
    useTool : BOOL;
    readyToSend : BOOL;
  END_VAR
  VAR
    toolTimerOn : BOOL;
    initialPiece_saved : INT;
  END_VAR
  VAR_INPUT
    initialPiece : INT;
  END_VAR
  VAR_OUTPUT
    currentPiece : INT;
  END_VAR
  VAR
    finalPiece_saved : INT;
  END_VAR
  VAR_INPUT
    finalPiece : INT;
    nextReadyToReceive : BOOL;
    toolPiece : BOOL;
  END_VAR
  VAR
    toolNumber : INT := 0;
  END_VAR
  VAR_OUTPUT NON_RETAIN
    toolPlus : BOOL;
  END_VAR
  VAR_INPUT
    toolSensor : BOOL;
  END_VAR
  VAR
    toolSensorRE : BOOL;
  END_VAR
  VAR_OUTPUT
    toolMinus : BOOL;
    motorUp : BOOL;
    motorLeft : BOOL;
    motorDown : BOOL;
    motorRight : BOOL;
  END_VAR
  VAR_INPUT
    sensorUp : BOOL;
    sensorLeft : BOOL;
    sensorDown : BOOL;
    sensorRight : BOOL;
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
    asd : R_TRIG;
    TON2 : TON;
    TON3 : TON;
    TON4 : TON;
    TON5 : TON;
    TON6 : TON;
    TON7 : TON;
    TON8 : TON;
    TON9 : TON;
    TON10 : TON;
  END_VAR

  INITIAL_STEP initLinearStep:
    isBusy(R);
    incrementToolNumber(S);
    toolStandby(N);
    COMPUTE_FUNCTION_BLOCKS(S);
  END_STEP

  ACTION incrementToolNumber:
    asd(
         CLK := toolSensor,
         Q => toolSensorRE);
         

    IF asd.Q = true then
      toolNumber := toolNumber + 1;
      IF toolNumber = 4 then
        toolNumber := 1;
        end_if;
    end_if;
  END_ACTION

  ACTION toolStandby:
    motorUp := NOT(sensorUp);
    motorLeft := NOT(sensorLeft);
  END_ACTION

  ACTION COMPUTE_FUNCTION_BLOCKS:
    TON2(IN := toolTimerOn, PT := T#5s);
    TON3(IN := toolTimerOn, PT := T#10s);
    TON4(IN := toolTimerOn, PT := T#5s);
    TON6(IN := toolTimerOn, PT := T#5s);
    TON5(IN := toolTimerOn, PT := T#10s);
    TON7(IN := toolTimerOn, PT := T#5s);
    TON9(IN := toolTimerOn, PT := T#20s);
    TON8(IN := toolTimerOn, PT := T#20s);
    TON10(IN := toolTimerOn, PT := T#20s);
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

  TRANSITION FROM initLinearStep TO moveFront0
    := toolPiece;
  END_TRANSITION

  STEP moveFront0:
    forwardMotor(N);
    savePieces(N);
  END_STEP

  ACTION savePieces:
    initialPiece_saved := initialPiece;
    finalPiece_saved := finalPiece;
  END_ACTION

  TRANSITION FROM moveFront0 TO Step2
    := reachedSensor;
  END_TRANSITION

  STEP Step2:
    isBusy(S);
  END_STEP

  TRANSITION FROM Step2 TO Step4
    := initialPiece_saved = 1 OR initialPiece_saved = 3 OR initialPiece_saved = 5;
  END_TRANSITION

  STEP Step4:
    currentAsInitial(N);
  END_STEP

  ACTION currentAsInitial:
    currentPiece := initialPiece_saved;
  END_ACTION

  TRANSITION FROM Step4 TO checkIfFinalA
    := true;
  END_TRANSITION

  STEP checkIfFinalA:
  END_STEP

  TRANSITION FROM checkIfFinalA TO Step11
    := currentPiece <> finalPiece_saved;
  END_TRANSITION

  STEP Step11:
  END_STEP

  TRANSITION FROM Step11 TO Step5
    := currentPiece = 1 ;
  END_TRANSITION

  STEP Step5:
    isBusy(S);
    motorDown(N);
    motorRight(N);
  END_STEP

  TRANSITION FROM Step5 TO Step0
    := sensorDown AND sensorRight;
  END_TRANSITION

  STEP Step0:
    toolPlus(N);
  END_STEP

  TRANSITION FROM Step0 TO Step8
    := toolNumber = 1;
  END_TRANSITION

  STEP Step8:
    useTool(N);
    toolTimerOn(N);
  END_STEP

  TRANSITION FROM Step8 TO Step1
    := TON2.Q;
  END_TRANSITION

  STEP Step1:
    setCurrent3(N);
  END_STEP

  ACTION setCurrent3:
    currentPiece := 3;
  END_ACTION

  TRANSITION FROM Step1 TO checkIfFinalA
    := true;
  END_TRANSITION

  TRANSITION FROM Step11 TO Step12
    := currentPiece = 3 ;
  END_TRANSITION

  STEP Step12:
    isBusy(S);
    motorDown(N);
    motorRight(N);
  END_STEP

  TRANSITION FROM Step12 TO Step14
    := sensorDown AND sensorRight;
  END_TRANSITION

  STEP Step14:
    toolPlus(N);
  END_STEP

  TRANSITION FROM Step14 TO Step13
    := toolNumber = 2;
  END_TRANSITION

  STEP Step13:
    useTool(N);
    toolTimerOn(N);
  END_STEP

  TRANSITION FROM Step13 TO Step15
    := TON3.Q;
  END_TRANSITION

  STEP Step15:
    setCurrent5(N);
  END_STEP

  ACTION setCurrent5:
    currentPiece := 5;
  END_ACTION

  TRANSITION FROM Step15 TO checkIfFinalA
    := true;
  END_TRANSITION

  TRANSITION FROM Step11 TO Step16
    := currentPiece = 5;
  END_TRANSITION

  STEP Step16:
    isBusy(S);
    motorDown(N);
    motorRight(N);
  END_STEP

  TRANSITION FROM Step16 TO Step18
    := sensorDown AND sensorRight;
  END_TRANSITION

  STEP Step18:
    toolPlus(N);
  END_STEP

  TRANSITION FROM Step18 TO Step17
    := toolNumber = 3;
  END_TRANSITION

  STEP Step17:
    useTool(N);
    toolTimerOn(N);
  END_STEP

  TRANSITION FROM Step17 TO Step19
    := TON4.Q;
  END_TRANSITION

  STEP Step19:
    setCurrent7(N);
  END_STEP

  ACTION setCurrent7:
    currentPiece := 7;
  END_ACTION

  TRANSITION FROM Step19 TO sendToNext
    := true;
  END_TRANSITION

  STEP sendToNext:
    motorUp(N);
    motorLeft(N);
  END_STEP

  TRANSITION FROM sendToNext TO Step3
    := sensorUp AND sensorLeft;
  END_TRANSITION

  STEP Step3:
    readyToSend(N);
  END_STEP

  TRANSITION FROM Step3 TO Step10
    := nextReadyToReceive;
  END_TRANSITION

  STEP Step10:
    forwardMotor(N);
  END_STEP

  TRANSITION FROM Step10 TO initLinearStep
    := reachedSensorFront;
  END_TRANSITION

  TRANSITION FROM checkIfFinalA TO sendToNext
    := currentPiece = finalPiece_saved;
  END_TRANSITION

  TRANSITION FROM Step2 TO Step7
    := initialPiece_saved = 2 OR initialPiece_saved = 4 OR initialPiece_saved = 6;
  END_TRANSITION

  STEP Step7:
    currentAsInitial(N);
  END_STEP

  TRANSITION FROM Step7 TO checkIfFinalB
    := true;
  END_TRANSITION

  STEP checkIfFinalB:
  END_STEP

  TRANSITION FROM checkIfFinalB TO Step27
    := currentPiece <> finalPiece_saved;
  END_TRANSITION

  STEP Step27:
  END_STEP

  TRANSITION FROM Step27 TO Step20
    := currentPiece = 4 ;
  END_TRANSITION

  STEP Step20:
    isBusy(S);
    motorDown(N);
    motorRight(N);
  END_STEP

  TRANSITION FROM Step20 TO Step28
    := sensorDown AND sensorRight;
  END_TRANSITION

  STEP Step28:
    toolPlus(N);
  END_STEP

  TRANSITION FROM Step28 TO Step21
    := toolNumber = 2;
  END_TRANSITION

  STEP Step21:
    useTool(N);
    toolTimerOn(N);
  END_STEP

  TRANSITION FROM Step21 TO Step29
    := TON6.Q;
  END_TRANSITION

  STEP Step29:
    setCurrent6(N);
  END_STEP

  ACTION setCurrent6:
    currentPiece := 6;
  END_ACTION

  TRANSITION FROM Step29 TO checkIfFinalB
    := true;
  END_TRANSITION

  TRANSITION FROM Step27 TO Step9
    := currentPiece = 2 ;
  END_TRANSITION

  STEP Step9:
    isBusy(S);
    motorDown(N);
    motorRight(N);
  END_STEP

  TRANSITION FROM Step9 TO Step23
    := sensorDown AND sensorRight;
  END_TRANSITION

  STEP Step23:
    toolPlus(N);
  END_STEP

  TRANSITION FROM Step23 TO Step22
    := toolNumber = 1;
  END_TRANSITION

  STEP Step22:
    useTool(N);
    toolTimerOn(N);
  END_STEP

  TRANSITION FROM Step22 TO Step24
    := TON5.Q;
  END_TRANSITION

  STEP Step24:
    setCurrent4(N);
  END_STEP

  ACTION setCurrent4:
    currentPiece := 4;
  END_ACTION

  TRANSITION FROM Step24 TO checkIfFinalB
    := true;
  END_TRANSITION

  TRANSITION FROM Step27 TO Step25
    := currentPiece = 6;
  END_TRANSITION

  STEP Step25:
    isBusy(S);
    motorDown(N);
    motorRight(N);
  END_STEP

  TRANSITION FROM Step25 TO Step31
    := sensorDown AND sensorRight;
  END_TRANSITION

  STEP Step31:
    toolPlus(N);
  END_STEP

  TRANSITION FROM Step31 TO Step30
    := toolNumber = 3;
  END_TRANSITION

  STEP Step30:
    useTool(N);
    toolTimerOn(N);
  END_STEP

  TRANSITION FROM Step30 TO Step32
    := TON7.Q;
  END_TRANSITION

  STEP Step32:
    setCurrent8(N);
  END_STEP

  ACTION setCurrent8:
    currentPiece := 8;
  END_ACTION

  TRANSITION FROM Step32 TO sendToNext
    := true;
  END_TRANSITION

  TRANSITION FROM checkIfFinalB TO sendToNext
    := currentPiece = finalPiece_saved;
  END_TRANSITION

  TRANSITION FROM Step2 TO sendToNext
    := initialPiece_saved = finalPiece_saved;
  END_TRANSITION

  TRANSITION FROM Step2 TO Step46
    := initialPiece_saved = 7 OR initialPiece_saved = 8 ;
  END_TRANSITION

  STEP Step46:
    currentAsInitial(N);
  END_STEP

  TRANSITION FROM Step46 TO Step34
    := machineType = 1;
  END_TRANSITION

  STEP Step34:
  END_STEP

  TRANSITION FROM Step34 TO checkIfFinalC
    := true;
  END_TRANSITION

  STEP checkIfFinalC:
  END_STEP

  TRANSITION FROM checkIfFinalC TO Step40
    := currentPiece <> finalPiece_saved;
  END_TRANSITION

  STEP Step40:
  END_STEP

  TRANSITION FROM Step40 TO Step26
    := currentPiece = 8 AND finalPiece_saved = 7;
  END_TRANSITION

  STEP Step26:
    isBusy(S);
    motorDown(N);
    motorRight(N);
  END_STEP

  TRANSITION FROM Step26 TO Step41
    := sensorDown AND sensorRight;
  END_TRANSITION

  STEP Step41:
    toolPlus(N);
  END_STEP

  TRANSITION FROM Step41 TO Step33
    := toolNumber = 2;
  END_TRANSITION

  STEP Step33:
    useTool(N);
    toolTimerOn(N);
  END_STEP

  TRANSITION FROM Step33 TO Step42
    := TON9.Q;
  END_TRANSITION

  STEP Step42:
    setCurrent7(N);
  END_STEP

  TRANSITION FROM Step42 TO checkIfFinalC
    := true;
  END_TRANSITION

  TRANSITION FROM Step40 TO Step35
    := currentPiece = 7 AND finalPiece_saved = 8;
  END_TRANSITION

  STEP Step35:
    isBusy(S);
    motorDown(N);
    motorRight(N);
  END_STEP

  TRANSITION FROM Step35 TO Step37
    := sensorDown AND sensorRight;
  END_TRANSITION

  STEP Step37:
    toolPlus(N);
  END_STEP

  TRANSITION FROM Step37 TO Step36
    := toolNumber = 1;
  END_TRANSITION

  STEP Step36:
    useTool(N);
    toolTimerOn(N);
  END_STEP

  TRANSITION FROM Step36 TO Step38
    := TON8.Q;
  END_TRANSITION

  STEP Step38:
    setCurrent8(N);
  END_STEP

  TRANSITION FROM Step38 TO checkIfFinalC
    := true;
  END_TRANSITION

  TRANSITION FROM Step40 TO Step39
    := (currentPiece = 7 OR currentPiece = 8) AND finalPiece_saved = 9;
  END_TRANSITION

  STEP Step39:
    isBusy(S);
    motorDown(N);
    motorRight(N);
  END_STEP

  TRANSITION FROM Step39 TO Step44
    := sensorDown AND sensorRight;
  END_TRANSITION

  STEP Step44:
    toolPlus(N);
  END_STEP

  TRANSITION FROM Step44 TO Step43
    := toolNumber = 3;
  END_TRANSITION

  STEP Step43:
    useTool(N);
    toolTimerOn(N);
  END_STEP

  TRANSITION FROM Step43 TO Step45
    := TON10.Q;
  END_TRANSITION

  STEP Step45:
    setCurrent9(N);
  END_STEP

  ACTION setCurrent9:
    currentPiece := 9;
  END_ACTION

  TRANSITION FROM Step45 TO sendToNext
    := true;
  END_TRANSITION

  TRANSITION FROM checkIfFinalC TO sendToNext
    := currentPiece = finalPiece_saved;
  END_TRANSITION

  TRANSITION FROM Step46 TO sendToNext
    := machineType = 0;
  END_TRANSITION

END_FUNCTION_BLOCK

PROGRAM factoryFloorProgram
  VAR_EXTERNAL
    sendRightDownCT2_ex : BOOL;
    sendLeftDownCT8_ex : BOOL;
    runFrontCT7_ex : BOOL;
    pushUpCT6_ex : BOOL;
    sendRightUpCT8_ex : BOOL;
    sendUpRightMT6_ex : BOOL;
    cell1Initial : INT;
    cell1Final : INT;
    cell2Initial : INT;
    cell2Final : INT;
    cell3Initial : INT;
    cell3Final : INT;
    gantryBusy_ex : BOOL;
    receivePieceMT1_ex : BOOL;
    receivePieceMT2_ex : BOOL;
    pickPiece_ex : BOOL;
    releasePiece_ex : BOOL;
    X0Y0_ex : BOOL;
    X0Y1_ex : BOOL;
    X0Y2_ex : BOOL;
    X0Y3_ex : BOOL;
    X0Y4_ex : BOOL;
    X1Y0_ex : BOOL;
    X1Y1_ex : BOOL;
    X1Y2_ex : BOOL;
    X1Y3_ex : BOOL;
    X1Y4_ex : BOOL;
  END_VAR
  VAR
    AT1 : LinearConveyor;
  END_VAR
  VAR
    warehouseBusy AT %QX0.1.0.0 : BOOL;
  END_VAR
  VAR
    warehouseBusyCOMM : BOOL;
  END_VAR
  VAR
    cell1Busy AT %QX0.1.0.5 : BOOL;
    cell2Busy AT %QX0.1.0.6 : BOOL;
    cell3Busy AT %QX0.1.0.7 : BOOL;
  END_VAR
  VAR
    SaT1 : LinearConveyor;
    SaT2 : RotaryConveyor;
    SbT1 : LinearConveyor;
  END_VAR
  VAR_EXTERNAL
    sensorAT1_ex : BOOL;
    sensorAT2_ex : BOOL;
    sensorSaT1_ex : BOOL;
    sensorSaT2_ex : BOOL;
    sensorSaT3_ex : BOOL;
    sensorSaT4_ex : BOOL;
    sensorSaT5_ex : BOOL;
    sensorSaT6_ex : BOOL;
    sensorSaT7_ex : BOOL;
    sensorSbT1_ex : BOOL;
    sensorSbT2_ex : BOOL;
    sensorSbT5_ex : BOOL;
    sensorSbT4_ex : BOOL;
    sensorSbT3_ex : BOOL;
    sensorScT1_ex : BOOL;
    sensorScT2_ex : BOOL;
    sensorScT3_ex : BOOL;
    sensorScT4_ex : BOOL;
    sensorScT5_ex : BOOL;
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
    runFrontSaT3_ex : BOOL;
    runFrontSaT4_ex : BOOL;
    runFrontSaT5_ex : BOOL;
    runFrontSbT1_ex : BOOL;
    runFrontSbT2_ex : BOOL;
    runFrontSbT3_ex : BOOL;
    runFrontSbT4_ex : BOOL;
    runFrontSbT5_ex : BOOL;
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
    sendLeftDownSaT6_ex : BOOL;
    sendLeftDownSbT6_ex : BOOL;
    sendLeftDownScT6_ex : BOOL;
    receivePieceMT3_ex : BOOL;
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
    sensorMT3 AT %IX0.0.0.70 : BOOL;
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
    AT2 : WarehouseInConveyor;
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
    sensorMT4_ex : BOOL;
    runBackSbT7_ex : BOOL;
    sensorSbT6_ex : BOOL;
    runFrontSbT6_ex : BOOL;
    sendDownSbT6_ex : BOOL;
    sendDownSaT6_ex : BOOL;
    runBackSbT6_ex : BOOL;
    sensorScT6_ex : BOOL;
    runFrontScT6_ex : BOOL;
    runFrontScT3_ex : BOOL;
    runFrontScT4_ex : BOOL;
    runFrontScT5_ex : BOOL;
    runBackScT6_ex : BOOL;
    runBackMT6_ex : BOOL;
    receivePieceMT4_ex : BOOL;
    runFrontMT4_ex : BOOL;
    runFrontMT3_ex : BOOL;
    sendDownScT6_ex : BOOL;
    sendDownMT6_ex : BOOL;
    sensorMT3_ex : BOOL;
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
    SaT3 : Machine;
  END_VAR
  VAR
    toolSensorSaT3 AT %IX0.0.0.7 : BOOL;
    toolSensorSaT5 AT %IX0.0.0.14 : BOOL;
    toolSensorSbT3 AT %IX0.0.0.28 : BOOL;
    toolSensorSbT5 AT %IX0.0.0.35 : BOOL;
    toolSensorScT3 AT %IX0.0.0.49 : BOOL;
    toolSensorScT5 AT %IX0.0.0.56 : BOOL;
    xRightSaT3 AT %QX0.0.1.16 : BOOL;
    warehouseIn AT %QX0.0.1.4 : BOOL;
    xLeftSaT3 AT %QX0.0.1.17 : BOOL;
    zUpSaT3 AT %QX0.0.1.18 : BOOL;
    zDownSaT3 AT %QX0.0.1.19 : BOOL;
    xRightSaT5 AT %QX0.0.1.27 : BOOL;
    xLeftSaT5 AT %QX0.0.1.28 : BOOL;
    zUpSaT5 AT %QX0.0.1.29 : BOOL;
    zDownSaT5 AT %QX0.0.1.30 : BOOL;
    xRightSbT3 AT %QX0.0.1.48 : BOOL;
    xLeftSbT3 AT %QX0.0.1.49 : BOOL;
    zUpSbT3 AT %QX0.0.1.50 : BOOL;
    zDownSbT3 AT %QX0.0.1.51 : BOOL;
    xRightSbT5 AT %QX0.0.1.59 : BOOL;
    xLeftSbT5 AT %QX0.0.1.60 : BOOL;
    zUpSbT5 AT %QX0.0.1.61 : BOOL;
    zDownSbT5 AT %QX0.0.1.62 : BOOL;
    xRightScT3 AT %QX0.0.1.80 : BOOL;
    xLeftScT3 AT %QX0.0.1.81 : BOOL;
    zUpScT3 AT %QX0.0.1.82 : BOOL;
    zDownScT3 AT %QX0.0.1.83 : BOOL;
    xRightScT5 AT %QX0.0.1.91 : BOOL;
    xLeftScT5 AT %QX0.0.1.92 : BOOL;
    zUpScT5 AT %QX0.0.1.93 : BOOL;
    zDownScT5 AT %QX0.0.1.94 : BOOL;
    toolMinusSaT3 AT %QX0.0.1.13 : BOOL;
    toolPlusSaT3 AT %QX0.0.1.14 : BOOL;
    toolMinusSaT5 AT %QX0.0.1.24 : BOOL;
    toolPlusSaT5 AT %QX0.0.1.25 : BOOL;
    toolMinusSbT3 AT %QX0.0.1.45 : BOOL;
    toolPlusSbT3 AT %QX0.0.1.46 : BOOL;
    toolMinusSbT5 AT %QX0.0.1.56 : BOOL;
    toolPlusSbT5 AT %QX0.0.1.57 : BOOL;
    toolMinusScT3 AT %QX0.0.1.77 : BOOL;
    toolPlusScT3 AT %QX0.0.1.78 : BOOL;
    toolMinusScT5 AT %QX0.0.1.88 : BOOL;
    toolPlusScT5 AT %QX0.0.1.89 : BOOL;
    toolUpSensorSaT3 AT %IX0.0.0.10 : BOOL;
    toolUpSensorSaT5 AT %IX0.0.0.17 : BOOL;
    toolUpSensorSbT3 AT %IX0.0.0.31 : BOOL;
    toolUpSensorSbT5 AT %IX0.0.0.38 : BOOL;
    toolUpSensorScT3 AT %IX0.0.0.52 : BOOL;
    toolUpSensorScT5 AT %IX0.0.0.59 : BOOL;
    toolDownSensorSaT3 AT %IX0.0.0.11 : BOOL;
    toolDownSensorSaT5 AT %IX0.0.0.18 : BOOL;
    toolDownSensorSbT3 AT %IX0.0.0.32 : BOOL;
    toolDownSensorSbT5 AT %IX0.0.0.39 : BOOL;
    toolDownSensorScT3 AT %IX0.0.0.53 : BOOL;
    toolDownSensorScT5 AT %IX0.0.0.60 : BOOL;
    toolLeftSensorSaT3 AT %IX0.0.0.8 : BOOL;
    toolLeftSensorSaT5 AT %IX0.0.0.15 : BOOL;
    toolLeftSensorSbT3 AT %IX0.0.0.29 : BOOL;
    toolLeftSensorSbT5 AT %IX0.0.0.36 : BOOL;
    toolLeftSensorScT3 AT %IX0.0.0.50 : BOOL;
    toolLeftSensorScT5 AT %IX0.0.0.57 : BOOL;
    toolRightSensorSaT3 AT %IX0.0.0.9 : BOOL;
    toolRightSensorSaT5 AT %IX0.0.0.16 : BOOL;
    toolRightSensorSbT3 AT %IX0.0.0.30 : BOOL;
    toolRightSensorSbT5 AT %IX0.0.0.37 : BOOL;
    toolRightSensorScT3 AT %IX0.0.0.51 : BOOL;
    toolRightSensorScT5 AT %IX0.0.0.58 : BOOL;
    useToolSaT3 AT %QX0.0.1.15 : BOOL;
    useToolSaT5 AT %QX0.0.1.26 : BOOL;
    useToolSbT3 AT %QX0.0.1.47 : BOOL;
    useToolSbT5 AT %QX0.0.1.58 : BOOL;
    useToolScT3 AT %QX0.0.1.79 : BOOL;
    useToolScT5 AT %QX0.0.1.90 : BOOL;
  END_VAR
  VAR_EXTERNAL
    toolPieceSaT3_ex : BOOL;
    toolPieceSaT5_ex : BOOL;
    toolPieceSbT5_ex : BOOL;
    toolPieceSbT3_ex : BOOL;
    toolPieceScT3_ex : BOOL;
    toolPieceScT5_ex : BOOL;
  END_VAR
  VAR
    SaT4 : LinearConveyor;
    SaT5 : Machine;
  END_VAR
  VAR_EXTERNAL
    readyToSendSaT3_ex : BOOL;
    readyToSendSaT5_ex : BOOL;
    readyToSendSbT5_ex : BOOL;
    readyToSendSbT3_ex : BOOL;
    readyToSendScT3_ex : BOOL;
    readyToSendScT5_ex : BOOL;
    putPieceInSignal_ex : BOOL;
  END_VAR
  VAR
    initialPiece AT %IW0.1.1.0 : INT;
    finalPiece AT %IW0.1.1.3 : INT;
  END_VAR
  VAR
    SbT3 : Machine;
    SbT4 : LinearConveyor;
    SbT5 : Machine;
    ScT3 : Machine;
    ScT4 : LinearConveyor;
    ScT5 : Machine;
    Gantry0 : Gantry;
  END_VAR
  VAR
    motorZUpGantry AT %QX0.0.1.121 : BOOL;
    motorZDownGantry AT %QX0.0.1.122 : BOOL;
    motorYUpGantry AT %QX0.0.1.120 : BOOL;
    motorYDownGantry AT %QX0.0.1.119 : BOOL;
    motorXLeftGantry AT %QX0.0.1.118 : BOOL;
    motorXRightGantry AT %QX0.0.1.117 : BOOL;
    grabPieceGantry AT %QX0.0.1.123 : BOOL;
    sensorZTopGantry AT %IX0.0.0.87 : BOOL;
    sensorZBottomGantry AT %IX0.0.0.86 : BOOL;
    sensorY4Gantry AT %IX0.0.0.85 : BOOL;
    sensorY3Gantry AT %IX0.0.0.84 : BOOL;
    sensorY2Gantry AT %IX0.0.0.83 : BOOL;
    sensorY1Gantry AT %IX0.0.0.82 : BOOL;
    sensorY0Gantry AT %IX0.0.0.81 : BOOL;
    sensorX1Gantry AT %IX0.0.0.80 : BOOL;
    sensorX0Gantry AT %IX0.0.0.79 : BOOL;
    sensorPieceGantry AT %IX0.0.0.88 : BOOL;
  END_VAR
  VAR
    MT4 : LinearConveyor;
    MT3 : LinearConveyor;
    NOT432_OUT : BOOL;
    NOT427_OUT : BOOL;
    OR209_OUT : BOOL;
    OR425_OUT : BOOL;
    OR210_OUT : BOOL;
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
  PM1(reachedSensor := sensorPM1);
  PM2(reachedSensor := sensorPM2);
  PM3(reachedSensor := sensorPM3);
  NOT432_OUT := NOT(sensorRotRightCT8);
  CT6(rollBusy := PM3.hasPiece, pushSignal := pushToRollCT6_ex, pushUpSignal := pushUpCT6_ex, forwardSignal := runFrontCT6_ex, reachedSensor := sensorCT6, reachedRoll := sensorPM3, reachedSensorFront := sensorCT8, sensorPushForward := sensorPushForwardCT6, sensorPushBack := sensorPushBackCT6, frontNotBusy := NOT432_OUT);
  CT5(rollBusy := PM2.hasPiece, pushSignal := pushToRollCT5_ex, forwardSignal := runFrontCT5_ex, reachedSensor := sensorCT5, reachedRoll := sensorPM2, reachedSensorFront := sensorCT6, sensorPushForward := sensorPushForwardCT5, sensorPushBack := sensorPushBackCT5, frontNotBusy := CT6.isBusy);
  CT4(rollBusy := PM1.hasPiece, pushSignal := pushToRollCT4_ex, forwardSignal := runFrontCT4_ex, reachedSensor := sensorCT4, reachedRoll := sensorPM1, reachedSensorFront := sensorCT5, sensorPushForward := sensorPushForwardCT4, sensorPushBack := sensorPushBackCT4, frontNotBusy := CT5.isBusy);
  CT2(sendRightDownSignal := sendRightDownCT2_ex, backSignal := runBackCT2_ex, forwardSignal := runFrontCT2_ex, sendDownSignal := sendDownCT2_ex, sensorRotRight := sensorRotRightCT2, sensorRotLeft := sensorRotLeftCT2, downNotBusy := CT4.isBusy, reachedSensor := sensorCT2, reachedSensorDown := sensorCT4);
  backCT2 := CT2.backMotor;
  CT1(reachedSensor := sensorCT1, forwardSignal := runFrontCT1_ex, frontNotBusy := CT2.isBusy, reachedSensorFront := sensorCT2);
  AT2(reachedSensor := sensorAT2, backSignal := runBackAT2_ex, warehouseBusy := warehouseBusy, putPieceInSignal := putPieceInSignal_ex);
  SaT7(reachedSensor := sensorSaT7, backSignal := runBackSaT7_ex, backNotBusy := AT2.isBusy, reachedSensorFront := sensorSaT6, reachedSensorBack := sensorAT2);
  SaT6(backSignal := runBackSaT6_ex, sendDownSignal := sendDownSaT6_ex, sendLeftDownSignal := sendLeftDownSaT6_ex, sensorRotRight := sensorRotRightSaT6, sensorRotLeft := sensorRotLeftSaT6, backNotBusy := SaT7.isBusy, reachedSensorFront := sensorSbT7, reachedSensor := sensorSaT6, reachedSensorBack := sensorSaT7);
  SbT7(reachedSensor := sensorSbT7, backSignal := runBackSbT7_ex, backNotBusy := SaT6.isBusy, reachedSensorFront := sensorSbT6, reachedSensorBack := sensorSaT6);
  SbT6(backSignal := runBackSbT6_ex, forwardSignal := runFrontSbT6_ex, sendDownSignal := sendDownSbT6_ex, sendLeftDownSignal := sendLeftDownSbT6_ex, sensorRotRight := sensorRotRightSbT6, sensorRotLeft := sensorRotLeftSbT6, backNotBusy := SbT7.isBusy, reachedSensorFront := sensorScT7, reachedSensor := sensorSbT6, reachedSensorBack := sensorSbT7);
  ScT7(reachedSensor := sensorScT7, backSignal := runBackScT7_ex, backNotBusy := SbT6.isBusy, reachedSensorFront := sensorScT6, reachedSensorBack := sensorSbT6);
  ScT6(backSignal := runBackScT6_ex, forwardSignal := runFrontScT6_ex, sendDownSignal := sendDownScT6_ex, sendLeftDownSignal := sendLeftDownScT6_ex, sensorRotRight := sensorRotRightScT6, sensorRotLeft := sensorRotLeftScT6, backNotBusy := ScT7.isBusy, reachedSensor := sensorScT6, reachedSensorBack := sensorScT7);
  MT5(reachedSensor := sensorMT5, backSignal := runBackMT5_ex, backNotBusy := ScT6.isBusy, reachedSensorFront := sensorMT6, reachedSensorBack := sensorScT6);
  CT7(reachedSensor := sensorCT7, backSignal := runBackCT7_ex, forwardSignal := runFrontCT7_ex, backNotBusy := MT6.isBusy, reachedSensorFront := sensorCT8, reachedSensorBack := sensorMT6);
  MT6(sendUpRightSignal := sendUpRightMT6_ex, backSignal := runBackMT6_ex, sendDownSignal := sendDownMT6_ex, sensorRotRight := sensorRotRightMT6, sensorRotLeft := sensorRotLeftMT6, backNotBusy := MT5.isBusy, frontNotBusy := CT7.isBusy, reachedSensorFront := sensorCT7, reachedSensor := sensorMT6, reachedSensorBack := sensorMT5);
  NOT427_OUT := NOT(MT6.readyToReceive);
  MT4(receivePiece := receivePieceMT4_ex, reachedSensor := sensorMT4, forwardSignal := runFrontMT4_ex, frontNotBusy := NOT427_OUT, reachedSensorFront := sensorMT6);
  MT3(receivePiece := receivePieceMT3_ex, reachedSensor := sensorMT3, forwardSignal := runFrontMT3_ex, frontNotBusy := MT4.isBusy, reachedSensorFront := sensorMT4);
  MT2(receivePiece := receivePieceMT2_ex, forwardSignal := runFrontMT2_ex, sendDownSignal := sendDownMT2_ex, sensorRotRight := sensorRotRightMT2, sensorRotLeft := sensorRotLeftMT2, frontNotBusy := CT1.isBusy, downNotBusy := MT3.isBusy, reachedSensorFront := sensorCT1, reachedSensor := sensorMT2, reachedSensorDown := sensorMT3);
  MT1(receivePiece := receivePieceMT1_ex, reachedSensor := sensorMT1, forwardSignal := runFrontMT1_ex, frontNotBusy := MT2.isBusy, reachedSensorFront := sensorMT2);
  ScT5(machineType := 1, reachedSensor := sensorScT5, initialPiece := ScT3.currentPiece, finalPiece := cell3Final, nextReadyToReceive := ScT6.readyToReceive, toolPiece := toolPieceScT5_ex, toolSensor := toolSensorScT5, sensorUp := toolUpSensorScT5, sensorLeft := toolLeftSensorScT5, sensorDown := toolDownSensorScT5, sensorRight := toolRightSensorScT5, forwardSignal := runFrontScT5_ex, frontNotBusy := ScT6.isBusy, reachedSensorFront := sensorScT6);
  ScT4(reachedSensor := sensorScT4, forwardSignal := runFrontScT4_ex, frontNotBusy := ScT5.isBusy, reachedSensorFront := sensorScT5);
  ScT3(machineType := 0, reachedSensor := sensorScT3, initialPiece := cell3Initial, finalPiece := cell3Final, nextReadyToReceive := true, toolPiece := toolPieceScT3_ex, toolSensor := toolSensorScT3, sensorUp := toolUpSensorScT3, sensorLeft := toolLeftSensorScT3, sensorDown := toolDownSensorScT3, sensorRight := toolRightSensorScT3, forwardSignal := runFrontScT3_ex, frontNotBusy := ScT4.isBusy, reachedSensorFront := sensorScT4);
  ScT2(forwardSignal := runFrontScT2_ex, sendDownSignal := sendDownScT2_ex, sensorRotRight := sensorRotRightScT2, sensorRotLeft := sensorRotLeftScT2, frontNotBusy := MT1.isBusy, downNotBusy := ScT3.isBusy, reachedSensorFront := sensorMT1, reachedSensor := sensorScT2, reachedSensorDown := sensorScT3);
  ScT1(reachedSensor := sensorScT1, forwardSignal := runFrontScT1_ex, frontNotBusy := ScT2.isBusy, reachedSensorFront := sensorScT2);
  SbT5(machineType := 1, reachedSensor := sensorSbT5, initialPiece := SbT3.currentPiece, finalPiece := cell2Final, nextReadyToReceive := SbT6.readyToReceive, toolPiece := toolPieceSbT5_ex, toolSensor := toolSensorSbT5, sensorUp := toolUpSensorSbT5, sensorLeft := toolLeftSensorSbT5, sensorDown := toolDownSensorSbT5, sensorRight := toolRightSensorSbT5, forwardSignal := runFrontSbT5_ex, frontNotBusy := SbT6.isBusy, reachedSensorFront := sensorSbT6);
  SbT4(reachedSensor := sensorSbT4, forwardSignal := runFrontSbT4_ex, frontNotBusy := SbT5.isBusy, reachedSensorFront := sensorSbT5);
  SbT3(machineType := 0, reachedSensor := sensorSbT3, initialPiece := cell2Initial, finalPiece := cell2Final, nextReadyToReceive := true, toolPiece := toolPieceSbT3_ex, toolSensor := toolSensorSbT3, sensorUp := toolUpSensorSbT3, sensorLeft := toolLeftSensorSbT3, sensorDown := toolDownSensorSbT3, sensorRight := toolRightSensorSbT3, forwardSignal := runFrontSbT3_ex, frontNotBusy := SbT4.isBusy, reachedSensorFront := sensorSbT4);
  SbT2(forwardSignal := runFrontSbT2_ex, sendDownSignal := sendDownSbT2_ex, sensorRotRight := sensorRotRightSbT2, sensorRotLeft := sensorRotLeftSbT2, frontNotBusy := ScT1.isBusy, downNotBusy := SbT3.isBusy, reachedSensorFront := sensorScT1, reachedSensor := sensorSbT2, reachedSensorDown := sensorSbT3);
  SbT1(reachedSensor := sensorSbT1, forwardSignal := runFrontSbT1_ex, frontNotBusy := SbT2.isBusy, reachedSensorFront := sensorSbT2);
  SaT5(machineType := 1, reachedSensor := sensorSaT5, initialPiece := SaT3.currentPiece, finalPiece := cell1Final, nextReadyToReceive := SaT6.readyToReceive, toolPiece := toolPieceSaT5_ex, toolSensor := toolSensorSaT5, sensorUp := toolUpSensorSaT5, sensorLeft := toolLeftSensorSaT5, sensorDown := toolDownSensorSaT5, sensorRight := toolRightSensorSaT5, forwardSignal := runFrontSaT5_ex, frontNotBusy := SaT6.isBusy, reachedSensorFront := sensorSaT6);
  SaT4(reachedSensor := sensorSaT4, forwardSignal := runFrontSaT4_ex, frontNotBusy := SaT5.isBusy, reachedSensorFront := sensorSaT5);
  SaT3(machineType := 0, reachedSensor := sensorSaT3, initialPiece := cell1Initial, finalPiece := cell1Final, nextReadyToReceive := true, toolPiece := toolPieceSaT3_ex, toolSensor := toolSensorSaT3, sensorUp := toolUpSensorSaT3, sensorLeft := toolLeftSensorSaT3, sensorDown := toolDownSensorSaT3, sensorRight := toolRightSensorSaT3, forwardSignal := runFrontSaT3_ex, frontNotBusy := SaT4.isBusy, reachedSensorFront := sensorSaT4);
  SaT2(forwardSignal := runFrontSaT2_ex, sendDownSignal := sendDownSaT2_ex, sensorRotRight := sensorRotRightSaT2, sensorRotLeft := sensorRotLeftSaT2, frontNotBusy := SbT1.isBusy, downNotBusy := SaT3.isBusy, reachedSensorFront := sensorSbT1, reachedSensor := sensorSaT2, reachedSensorDown := sensorSaT3);
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
  OR209_OUT := OR(CT2.forwardMotor, CT2.isBusy);
  CT3(reachedSensor := sensorCT3, backSignal := runBackCT3_ex, backNotBusy := OR209_OUT, reachedSensorBack := sensorCT2);
  backCT3 := CT3.backMotor;
  leftRotSaT2 := SaT2.leftRotMotor;
  leftRotCT2 := CT2.leftRotMotor;
  leftRotSbT2 := SbT2.leftRotMotor;
  leftRotScT2 := ScT2.leftRotMotor;
  forwardMT1 := MT1.forwardMotor;
  forwardScT1 := ScT1.forwardMotor;
  leftRotMT2 := MT2.leftRotMotor;
  sensorSaT3_ex := sensorSaT3;
  useToolSaT3 := SaT3.useTool;
  sensorScT3_ex := sensorScT3;
  useToolScT3 := ScT3.useTool;
  toolPlusSaT3 := SaT3.toolPlus;
  sensorSbT3_ex := sensorSbT3;
  useToolSbT3 := SbT3.useTool;
  toolPlusScT3 := ScT3.toolPlus;
  toolMinusSaT3 := SaT3.toolMinus;
  readyToSendSaT3_ex := SaT3.readyToSend;
  sensorCT4_ex := sensorCT4;
  toolPlusSbT3 := SbT3.toolPlus;
  toolMinusScT3 := ScT3.toolMinus;
  forwardCT4 := CT4.forwardMotor;
  readyToSendScT3_ex := ScT3.readyToSend;
  zUpSaT3 := SaT3.motorUp;
  toolMinusSbT3 := SbT3.toolMinus;
  zUpScT3 := ScT3.motorUp;
  pushForwardCT4 := CT4.pushMotorForward;
  readyToSendSbT3_ex := SbT3.readyToSend;
  xLeftSaT3 := SaT3.motorLeft;
  pushBackCT4 := CT4.pushMotorBack;
  zDownSaT3 := SaT3.motorDown;
  zUpSbT3 := SbT3.motorUp;
  xLeftScT3 := ScT3.motorLeft;
  xRightSaT3 := SaT3.motorRight;
  zDownScT3 := ScT3.motorDown;
  xLeftSbT3 := SbT3.motorLeft;
  xRightScT3 := ScT3.motorRight;
  forwardSaT3 := SaT3.forwardMotor;
  Gantry0(sensorZTop := sensorZTopGantry, sensorZBottom := sensorZBottomGantry, sensorY0 := sensorY0Gantry, sensorY1 := sensorY1Gantry, sensorY2 := sensorY2Gantry, sensorY3 := sensorY3Gantry, sensorY4 := sensorY4Gantry, sensorX0 := sensorX0Gantry, sensorX1 := sensorX1Gantry, pieceSensor := sensorPieceGantry, pickPiece := pickPiece_ex, releasePiece := releasePiece_ex, X0Y0 := X0Y0_ex, X0Y1 := X0Y1_ex, X0Y2 := X0Y2_ex, X0Y3 := X0Y3_ex, X0Y4 := X0Y4_ex, X1Y0 := X1Y0_ex, X1Y1 := X1Y1_ex, X1Y2 := X1Y2_ex, X1Y3 := X1Y3_ex, X1Y4 := X1Y4_ex);
  motorZUpGantry := Gantry0.motorZUp;
  zDownSbT3 := SbT3.motorDown;
  forwardScT3 := ScT3.forwardMotor;
  motorZDownGantry := Gantry0.motorZDown;
  xRightSbT3 := SbT3.motorRight;
  motorYUpGantry := Gantry0.motorYUp;
  motorYDownGantry := Gantry0.motorYDown;
  forwardSbT3 := SbT3.forwardMotor;
  motorXRightGantry := Gantry0.motorXRight;
  motorXLeftGantry := Gantry0.motorXLeft;
  grabPieceGantry := Gantry0.grab;
  sensorSaT4_ex := sensorSaT4;
  forwardCT5 := CT5.forwardMotor;
  sensorScT4_ex := sensorScT4;
  forwardSaT4 := SaT4.forwardMotor;
  sensorCT5_ex := sensorCT5;
  pushForwardCT5 := CT5.pushMotorForward;
  forwardScT4 := ScT4.forwardMotor;
  gantryBusy_ex := Gantry0.gantryBusy;
  sensorSbT4_ex := sensorSbT4;
  pushBackCT5 := CT5.pushMotorBack;
  forwardSbT4 := SbT4.forwardMotor;
  sensorMT3_ex := sensorMT3;
  forwardCT6 := CT6.forwardMotor;
  pushForwardCT6 := CT6.pushMotorForward;
  backCT6 := CT6.backMotor;
  sensorCT6_ex := sensorCT6;
  forwardMT3 := MT3.forwardMotor;
  pushBackCT6 := CT6.pushMotorBack;
  backMT3 := MT3.backMotor;
  sensorSaT5_ex := sensorSaT5;
  useToolSaT5 := SaT5.useTool;
  useToolScT5 := ScT5.useTool;
  sensorScT5_ex := sensorScT5;
  toolPlusSaT5 := SaT5.toolPlus;
  readyToSendSaT5_ex := SaT5.readyToSend;
  useToolSbT5 := SbT5.useTool;
  sensorSbT5_ex := sensorSbT5;
  toolPlusScT5 := ScT5.toolPlus;
  readyToSendScT5_ex := ScT5.readyToSend;
  toolMinusSaT5 := SaT5.toolMinus;
  toolPlusSbT5 := SbT5.toolPlus;
  readyToSendSbT5_ex := SbT5.readyToSend;
  toolMinusScT5 := ScT5.toolMinus;
  zUpSaT5 := SaT5.motorUp;
  sensorMT4_ex := sensorMT4;
  toolMinusSbT5 := SbT5.toolMinus;
  zUpScT5 := ScT5.motorUp;
  xLeftSaT5 := SaT5.motorLeft;
  zDownSaT5 := SaT5.motorDown;
  zUpSbT5 := SbT5.motorUp;
  xLeftScT5 := ScT5.motorLeft;
  xRightSaT5 := SaT5.motorRight;
  zDownScT5 := ScT5.motorDown;
  xLeftSbT5 := SbT5.motorLeft;
  xRightScT5 := ScT5.motorRight;
  forwardSaT5 := SaT5.forwardMotor;
  zDownSbT5 := SbT5.motorDown;
  forwardScT5 := ScT5.forwardMotor;
  forwardMT4 := MT4.forwardMotor;
  xRightSbT5 := SbT5.motorRight;
  forwardSbT5 := SbT5.forwardMotor;
  backMT4 := MT4.backMotor;
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
  OR425_OUT := OR(CT6.forwardMotor, CT6.isBusy);
  CT8(sendRIghtUpSignal := sendRightUpCT8_ex, backSignal := runBackCT8_ex, forwardSignal := runFrontCT8_ex, sendDownSignal := sendDownCT8_ex, sendLeftDownSignal := sendLeftDownCT8_ex, sensorRotRight := sensorRotRightCT8, sensorRotLeft := sensorRotLeftCT8, backNotBusy := CT7.isBusy, upNotBusy := OR425_OUT, reachedSensor := sensorCT8, reachedSensorBack := sensorCT7, reachedSensorUp := sensorCT6);
  forwardCT8 := CT8.forwardMotor;
  forwardScT6 := ScT6.forwardMotor;
  forwardSbT6 := SbT6.forwardMotor;
  backCT8 := CT8.backMotor;
  forwardSaT6 := SaT6.forwardMotor;
  backScT6 := ScT6.backMotor;
  warehouseIn := AT2.putPieceIn;
  backSaT6 := SaT6.backMotor;
  forwardMT6 := MT6.forwardMotor;
  forwardSbT7 := SbT7.forwardMotor;
  backSbT6 := SbT6.backMotor;
  rightRotScT6 := ScT6.rightRotMotor;
  forwardCT7 := CT7.forwardMotor;
  forwardSaT7 := SaT7.forwardMotor;
  rightRotSaT6 := SaT6.rightRotMotor;
  backMT6 := MT6.backMotor;
  rightRotCT8 := CT8.rightRotMotor;
  forwardAT2 := AT2.forwardMotor;
  rightRotSbT6 := SbT6.rightRotMotor;
  leftRotScT6 := ScT6.leftRotMotor;
  backSaT7 := SaT7.backMotor;
  backSbT7 := SbT7.backMotor;
  forwardMT5 := MT5.forwardMotor;
  rightRotMT6 := MT6.rightRotMotor;
  leftRotSaT6 := SaT6.leftRotMotor;
  backCT7 := CT7.backMotor;
  leftRotCT8 := CT8.leftRotMotor;
  OR210_OUT := OR(CT8.forwardMotor, CT8.isBusy, CT8.leftRotMotor);
  CT9(reachedSensor := sensorCT9, backSignal := runBackCT9_ex, backNotBusy := OR210_OUT, reachedSensorBack := sensorCT8);
  backCT9 := CT9.backMotor;
  backAT2 := AT2.backMotor;
  leftRotSbT6 := SbT6.leftRotMotor;
  backMT5 := MT5.backMotor;
  leftRotMT6 := MT6.leftRotMotor;
  backScT7 := ScT7.backMotor;
END_PROGRAM

PROGRAM transformProgram
  VAR_EXTERNAL
    takePiece : BOOL;
    pieceNum : INT;
    cell1Initial : INT;
    cell1Final : INT;
    cell2Initial : INT;
    cell2Final : INT;
    cell3Initial : INT;
    cell3Final : INT;
  END_VAR
  VAR
    warehouseIn AT %IW0.0.2.0 : INT;
    sensorAT1 AT %IX0.0.0.0 : BOOL;
    PM AT %IW0.1.1.2 : INT;
    initialPiece AT %IW0.1.1.4 : INT;
    finalPiece AT %IW0.1.1.3 : INT;
    warehouseBusy AT %QX0.1.0.0 : BOOL;
  END_VAR
  VAR_EXTERNAL
    runFrontAT1_ex : BOOL;
    runFrontSaT1_ex : BOOL;
    runFrontSaT2_ex : BOOL;
    runFrontSaT4_ex : BOOL;
    runFrontSbT1_ex : BOOL;
    runFrontSbT2_ex : BOOL;
    runFrontSbT4_ex : BOOL;
    runFrontScT1_ex : BOOL;
    runFrontScT2_ex : BOOL;
    runFrontScT4_ex : BOOL;
    runFrontMT1_ex : BOOL;
    runFrontMT2_ex : BOOL;
    runFrontCT1_ex : BOOL;
    runFrontCT4_ex : BOOL;
    runFrontCT5_ex : BOOL;
    runBackSaT7_ex : BOOL;
    runBackScT7_ex : BOOL;
    runBackSbT7_ex : BOOL;
    runBackSbT6_ex : BOOL;
    runBackSaT6_ex : BOOL;
    sendDownSaT2_ex : BOOL;
    sendDownSbT2_ex : BOOL;
    sendDownScT2_ex : BOOL;
    toolPieceSaT3_ex : BOOL;
    toolPieceSaT5_ex : BOOL;
    toolPieceSbT3_ex : BOOL;
    toolPieceSbT5_ex : BOOL;
    toolPieceScT3_ex : BOOL;
    toolPieceScT5_ex : BOOL;
    sendDownCT2_ex : BOOL;
    sensorAT1_ex : BOOL;
    sensorAT2_ex : BOOL;
    sensorSaT1_ex : BOOL;
    sensorSaT2_ex : BOOL;
    sensorSaT3_ex : BOOL;
    sensorSaT4_ex : BOOL;
    sensorSaT5_ex : BOOL;
    sensorSaT6_ex : BOOL;
    sensorSaT7_ex : BOOL;
    sensorSbT1_ex : BOOL;
    sensorSbT2_ex : BOOL;
    sensorSbT3_ex : BOOL;
    sensorSbT4_ex : BOOL;
    sensorSbT5_ex : BOOL;
    sensorSbT6_ex : BOOL;
    sensorSbT7_ex : BOOL;
    sensorScT1_ex : BOOL;
    sensorScT2_ex : BOOL;
    sensorScT3_ex : BOOL;
    sensorScT4_ex : BOOL;
    sensorScT5_ex : BOOL;
    sensorScT6_ex : BOOL;
    sensorScT7_ex : BOOL;
    sensorMT1_ex : BOOL;
    sensorMT2_ex : BOOL;
    sensorCT1_ex : BOOL;
    sensorCT2_ex : BOOL;
    sensorCT4_ex : BOOL;
    sensorCT5_ex : BOOL;
    pushToRollCT4_ex : BOOL;
    pushToRollCT5_ex : BOOL;
    pushToRollCT6_ex : BOOL;
    sendLeftDownSaT6_ex : BOOL;
    sendLeftDownSbT6_ex : BOOL;
    sendLeftDownScT6_ex : BOOL;
    putPieceInSignal_ex : BOOL;
  END_VAR
  VAR
    removeFromWarehouse0 : removeFromWarehouse;
  END_VAR
  VAR
    runUnload AT %IX0.1.0.1 : BOOL;
    runTransformMach1 AT %IX0.1.0.2 : BOOL;
    runTransformMach2 AT %IX0.1.0.3 : BOOL;
    runTransformMach3 AT %IX0.1.0.4 : BOOL;
    cell1Busy AT %QX0.1.0.5 : BOOL;
    cell2Busy AT %QX0.1.0.6 : BOOL;
    cell3Busy AT %QX0.1.0.7 : BOOL;
  END_VAR
  VAR_EXTERNAL
    readyToSendSaT3_ex : BOOL;
    readyToSendSaT5_ex : BOOL;
    readyToSendSbT3_ex : BOOL;
    readyToSendSbT5_ex : BOOL;
    readyToSendScT3_ex : BOOL;
    readyToSendScT5_ex : BOOL;
  END_VAR

  INITIAL_STEP machineTransform1:
    cell1Busy(R);
  END_STEP

  TRANSITION FROM machineTransform1 TO Step89
    := runTransformMach1 AND (not warehouseBusy);
  END_TRANSITION

  STEP Step89:
    runTransformMach1(R);
    action0(S);
    warehouseBusy(S);
    cell1Busy(S);
    setPiece1(N);
  END_STEP

  ACTION action0:
    removeFromWarehouse0(pieceNum := initialPiece, sensorAT1 := sensorAT1);
    warehouseIn := removeFromWarehouse0.warehouseIn;
  END_ACTION

  ACTION setPiece1:
    cell1Initial := initialPiece;
    cell1Final := finalPiece;
  END_ACTION

  TRANSITION FROM Step89 TO Step86
    := sensorAT1_ex;
  END_TRANSITION

  STEP Step86:
    runFrontSaT1_ex(N);
    runFrontAT1_ex(N);
  END_STEP

  TRANSITION FROM Step86 TO Step85
    := NOT sensorAT1_ex;
  END_TRANSITION

  STEP Step85:
    action0(R);
  END_STEP

  TRANSITION FROM Step85 TO Step84
    := sensorSaT1_ex;
  END_TRANSITION

  STEP Step84:
    sendDownSaT2_ex(N);
  END_STEP

  TRANSITION FROM Step84 TO Step87
    := not sensorSaT1_ex;
  END_TRANSITION

  STEP Step87:
    warehouseBusy(R);
  END_STEP

  TRANSITION FROM Step87 TO Step90
    := sensorSaT2_ex;
  END_TRANSITION

  STEP Step90:
    toolPieceSaT3_ex(N);
  END_STEP

  TRANSITION FROM Step90 TO Step98
    := not sensorSaT2_ex;
  END_TRANSITION

  STEP Step98:
  END_STEP

  TRANSITION FROM Step98 TO Step92
    := readyToSendSaT3_ex;
  END_TRANSITION

  STEP Step92:
    runFrontSaT4_ex(N);
  END_STEP

  TRANSITION FROM Step92 TO Step93
    := sensorSaT4_ex;
  END_TRANSITION

  STEP Step93:
    toolPieceSaT5_ex(N);
  END_STEP

  TRANSITION FROM Step93 TO Step99
    := not sensorSaT4_ex;
  END_TRANSITION

  STEP Step99:
  END_STEP

  TRANSITION FROM Step99 TO Step94
    := readyToSendSaT5_ex;
  END_TRANSITION

  STEP Step94:
    sendLeftDownSaT6_ex(N);
  END_STEP

  TRANSITION FROM Step94 TO Step95
    := sensorSaT6_ex;
  END_TRANSITION

  STEP Step95:
  END_STEP

  TRANSITION FROM Step95 TO (Step96, Step2)
    := not sensorSaT6_ex;
  END_TRANSITION

  STEP Step96:
    runBackSaT7_ex(N);
  END_STEP

  TRANSITION FROM Step96 TO Step97
    := sensorSaT7_ex;
  END_TRANSITION

  STEP Step97:
    putPieceInSignal_ex(N);
  END_STEP

  TRANSITION FROM Step97 TO Step100
    := not sensorSaT7_ex;
  END_TRANSITION

  STEP Step100:
  END_STEP

  TRANSITION FROM Step100 TO Step101
    := sensorAT2_ex;
  END_TRANSITION

  STEP Step101:
  END_STEP

  TRANSITION FROM Step101 TO Step102
    := not sensorAT2_ex;
  END_TRANSITION

  STEP Step102:
  END_STEP

  TRANSITION FROM Step102 TO Step0
    := true;
  END_TRANSITION

  STEP Step0:
  END_STEP

  STEP Step2:
  END_STEP

  TRANSITION FROM Step2 TO machineTransform1
    := true;
  END_TRANSITION

  INITIAL_STEP machineTransform2:
    cell2Busy(R);
  END_STEP

  TRANSITION FROM machineTransform2 TO Step113
    := runTransformMach2 AND (not warehouseBusy);
  END_TRANSITION

  STEP Step113:
    runTransformMach2(R);
    action0(S);
    warehouseBusy(S);
    cell2Busy(S);
    setPiece2(N);
  END_STEP

  ACTION setPiece2:
    cell2Initial := initialPiece;
    cell2Final := finalPiece;
  END_ACTION

  TRANSITION FROM Step113 TO Step112
    := sensorAT1_ex;
  END_TRANSITION

  STEP Step112:
    runFrontSaT1_ex(N);
    runFrontAT1_ex(N);
  END_STEP

  TRANSITION FROM Step112 TO Step91
    := NOT sensorAT1_ex;
  END_TRANSITION

  STEP Step91:
    action0(R);
  END_STEP

  TRANSITION FROM Step91 TO Step88
    := sensorSaT1_ex;
  END_TRANSITION

  STEP Step88:
    runFrontSaT2_ex(N);
  END_STEP

  TRANSITION FROM Step88 TO Step104
    := not sensorSaT1_ex;
  END_TRANSITION

  STEP Step104:
    warehouseBusy(R);
  END_STEP

  TRANSITION FROM Step104 TO Step106
    := sensorSaT2_ex;
  END_TRANSITION

  STEP Step106:
    runFrontSbT1_ex(N);
  END_STEP

  TRANSITION FROM Step106 TO Step107
    := not sensorSaT2_ex;
  END_TRANSITION

  STEP Step107:
  END_STEP

  TRANSITION FROM Step107 TO Step108
    := sensorSbT1_ex;
  END_TRANSITION

  STEP Step108:
    sendDownSbT2_ex(N);
  END_STEP

  TRANSITION FROM Step108 TO Step109
    := not sensorSbT1_ex;
  END_TRANSITION

  STEP Step109:
  END_STEP

  TRANSITION FROM Step109 TO Step110
    := sensorSbT2_ex;
  END_TRANSITION

  STEP Step110:
    toolPieceSbT3_ex(N);
  END_STEP

  TRANSITION FROM Step110 TO Step119
    := not sensorSbT2_ex;
  END_TRANSITION

  STEP Step119:
  END_STEP

  TRANSITION FROM Step119 TO Step111
    := readyToSendSbT3_ex;
  END_TRANSITION

  STEP Step111:
    runFrontSbT4_ex(N);
  END_STEP

  TRANSITION FROM Step111 TO Step114
    := sensorSbT4_ex;
  END_TRANSITION

  STEP Step114:
    toolPieceSbT5_ex(N);
  END_STEP

  TRANSITION FROM Step114 TO Step120
    := not sensorSbT4_ex;
  END_TRANSITION

  STEP Step120:
  END_STEP

  TRANSITION FROM Step120 TO Step115
    := readyToSendSbT5_ex;
  END_TRANSITION

  STEP Step115:
    sendLeftDownSbT6_ex(N);
  END_STEP

  TRANSITION FROM Step115 TO Step116
    := sensorSbT6_ex;
  END_TRANSITION

  STEP Step116:
  END_STEP

  TRANSITION FROM Step116 TO (Step117, Step3)
    := not sensorSbT6_ex;
  END_TRANSITION

  STEP Step117:
    runBackSbT7_ex(N);
  END_STEP

  TRANSITION FROM Step117 TO Step118
    := sensorSbT7_ex;
  END_TRANSITION

  STEP Step118:
    runBackSaT6_ex(N);
  END_STEP

  TRANSITION FROM Step118 TO Step121
    := not sensorSbT7_ex;
  END_TRANSITION

  STEP Step121:
    runBackSaT6_ex(N);
  END_STEP

  TRANSITION FROM Step121 TO Step122
    := sensorSaT6_ex;
  END_TRANSITION

  STEP Step122:
    runBackSaT7_ex(N);
  END_STEP

  TRANSITION FROM Step122 TO Step103
    := not sensorSaT6_ex;
  END_TRANSITION

  STEP Step103:
    runBackSaT7_ex(N);
  END_STEP

  TRANSITION FROM Step103 TO Step105
    := sensorSaT7_ex;
  END_TRANSITION

  STEP Step105:
    putPieceInSignal_ex(N);
  END_STEP

  TRANSITION FROM Step105 TO Step123
    := not sensorSaT7_ex;
  END_TRANSITION

  STEP Step123:
  END_STEP

  TRANSITION FROM Step123 TO Step124
    := sensorAT2_ex;
  END_TRANSITION

  STEP Step124:
  END_STEP

  TRANSITION FROM Step124 TO Step125
    := not sensorAT2_ex;
  END_TRANSITION

  STEP Step125:
  END_STEP

  TRANSITION FROM Step125 TO Step0
    := true;
  END_TRANSITION

  STEP Step3:
  END_STEP

  TRANSITION FROM Step3 TO machineTransform2
    := true;
  END_TRANSITION

  INITIAL_STEP machineTransform3:
    cell3Busy(R);
  END_STEP

  TRANSITION FROM machineTransform3 TO Step133
    := runTransformMach3 AND (not warehouseBusy);
  END_TRANSITION

  STEP Step133:
    action0(S);
    runTransformMach3(R);
    warehouseBusy(S);
    cell3Busy(S);
    setPiece3(N);
  END_STEP

  ACTION setPiece3:
    cell3Initial := initialPiece;
    cell3Final := finalPiece;
  END_ACTION

  TRANSITION FROM Step133 TO Step132
    := sensorAT1_ex;
  END_TRANSITION

  STEP Step132:
    runFrontSaT1_ex(N);
    runFrontAT1_ex(N);
  END_STEP

  TRANSITION FROM Step132 TO Step127
    := NOT sensorAT1_ex;
  END_TRANSITION

  STEP Step127:
    action0(R);
  END_STEP

  TRANSITION FROM Step127 TO Step126
    := sensorSaT1_ex;
  END_TRANSITION

  STEP Step126:
    runFrontSaT2_ex(N);
  END_STEP

  TRANSITION FROM Step126 TO Step128
    := not sensorSaT1_ex;
  END_TRANSITION

  STEP Step128:
    warehouseBusy(R);
  END_STEP

  TRANSITION FROM Step128 TO Step129
    := sensorSaT2_ex;
  END_TRANSITION

  STEP Step129:
    runFrontSbT1_ex(N);
  END_STEP

  TRANSITION FROM Step129 TO Step130
    := not sensorSaT2_ex;
  END_TRANSITION

  STEP Step130:
  END_STEP

  TRANSITION FROM Step130 TO Step131
    := sensorSbT1_ex;
  END_TRANSITION

  STEP Step131:
    runFrontSbT2_ex(N);
  END_STEP

  TRANSITION FROM Step131 TO Step135
    := not sensorSbT1_ex;
  END_TRANSITION

  STEP Step135:
  END_STEP

  TRANSITION FROM Step135 TO Step134
    := sensorSbT2_ex;
  END_TRANSITION

  STEP Step134:
    runFrontScT1_ex(N);
  END_STEP

  TRANSITION FROM Step134 TO Step136
    := not sensorSbT2_ex;
  END_TRANSITION

  STEP Step136:
  END_STEP

  TRANSITION FROM Step136 TO Step145
    := sensorScT1_ex;
  END_TRANSITION

  STEP Step145:
    sendDownScT2_ex(N);
  END_STEP

  TRANSITION FROM Step145 TO Step138
    :=  not sensorScT1_ex;
  END_TRANSITION

  STEP Step138:
  END_STEP

  TRANSITION FROM Step138 TO Step139
    := sensorScT2_ex;
  END_TRANSITION

  STEP Step139:
    toolPieceScT3_ex(N);
  END_STEP

  TRANSITION FROM Step139 TO Step143
    := not sensorScT2_ex;
  END_TRANSITION

  STEP Step143:
  END_STEP

  TRANSITION FROM Step143 TO Step137
    := readyToSendScT3_ex;
  END_TRANSITION

  STEP Step137:
    runFrontScT4_ex(N);
  END_STEP

  TRANSITION FROM Step137 TO Step140
    := sensorScT4_ex;
  END_TRANSITION

  STEP Step140:
    toolPieceScT5_ex(N);
  END_STEP

  TRANSITION FROM Step140 TO Step144
    := not sensorScT4_ex;
  END_TRANSITION

  STEP Step144:
  END_STEP

  TRANSITION FROM Step144 TO Step141
    := readyToSendScT5_ex;
  END_TRANSITION

  STEP Step141:
    sendLeftDownScT6_ex(N);
  END_STEP

  TRANSITION FROM Step141 TO Step142
    := sensorScT6_ex;
  END_TRANSITION

  STEP Step142:
  END_STEP

  TRANSITION FROM Step142 TO (Step146, Step4)
    := not sensorScT6_ex;
  END_TRANSITION

  STEP Step146:
    runBackScT7_ex(N);
  END_STEP

  TRANSITION FROM Step146 TO Step147
    := sensorScT7_ex;
  END_TRANSITION

  STEP Step147:
    runBackSbT6_ex(N);
  END_STEP

  TRANSITION FROM Step147 TO Step148
    := not sensorScT7_ex;
  END_TRANSITION

  STEP Step148:
    runBackSbT6_ex(N);
  END_STEP

  TRANSITION FROM Step148 TO Step152
    := sensorSbT6_ex;
  END_TRANSITION

  STEP Step152:
    runBackSbT7_ex(N);
  END_STEP

  TRANSITION FROM Step152 TO Step153
    := not sensorSbT6_ex;
  END_TRANSITION

  STEP Step153:
    runBackSbT7_ex(N);
  END_STEP

  TRANSITION FROM Step153 TO Step154
    := sensorSbT7_ex;
  END_TRANSITION

  STEP Step154:
    runBackSaT6_ex(N);
  END_STEP

  TRANSITION FROM Step154 TO Step156
    := not sensorSbT7_ex;
  END_TRANSITION

  STEP Step156:
    runBackSaT6_ex(N);
  END_STEP

  TRANSITION FROM Step156 TO Step157
    := sensorSaT6_ex;
  END_TRANSITION

  STEP Step157:
    runBackSaT7_ex(N);
  END_STEP

  TRANSITION FROM Step157 TO Step150
    := not sensorSaT6_ex;
  END_TRANSITION

  STEP Step150:
    runBackSaT7_ex(N);
  END_STEP

  TRANSITION FROM Step150 TO Step155
    := sensorSaT7_ex;
  END_TRANSITION

  STEP Step155:
    putPieceInSignal_ex(N);
  END_STEP

  TRANSITION FROM Step155 TO Step158
    := not sensorSaT7_ex;
  END_TRANSITION

  STEP Step158:
  END_STEP

  TRANSITION FROM Step158 TO Step159
    := sensorAT2_ex;
  END_TRANSITION

  STEP Step159:
  END_STEP

  TRANSITION FROM Step159 TO Step160
    := not sensorAT2_ex;
  END_TRANSITION

  STEP Step160:
  END_STEP

  TRANSITION FROM Step160 TO Step0
    := true;
  END_TRANSITION

  STEP Step4:
  END_STEP

  TRANSITION FROM Step4 TO machineTransform3
    := true;
  END_TRANSITION

END_PROGRAM

PROGRAM gantryProgramGood
  VAR_EXTERNAL
    sensorCT6_ex : BOOL;
    receivePieceMT1_ex : BOOL;
    receivePieceMT2_ex : BOOL;
  END_VAR
  VAR
    mount AT %IX0.1.0.8 : BOOL;
  END_VAR
  VAR_EXTERNAL
    gantryBusy_ex : BOOL;
    pickPiece_ex : BOOL;
    releasePiece_ex : BOOL;
    X0Y0_ex : BOOL;
    X0Y1_ex : BOOL;
    X0Y2_ex : BOOL;
    X0Y3_ex : BOOL;
    X0Y4_ex : BOOL;
    X1Y0_ex : BOOL;
    X1Y1_ex : BOOL;
    X1Y2_ex : BOOL;
    X1Y3_ex : BOOL;
    X1Y4_ex : BOOL;
  END_VAR
  VAR
    warehouseIn AT %IW0.0.2.0 : INT;
    sensorAT1 AT %IX0.0.0.0 : BOOL;
    PM AT %IW0.1.1.2 : INT;
    bottomPiece AT %IW0.1.1.5 : INT;
    topPiece AT %IW0.1.1.1 : INT;
  END_VAR
  VAR
    pieceToUnload : INT;
  END_VAR
  VAR
    warehouseBusy AT %QX0.1.0.0 : BOOL;
  END_VAR
  VAR_EXTERNAL
    runFrontAT1_ex : BOOL;
    runFrontSaT1_ex : BOOL;
    runFrontSaT2_ex : BOOL;
    runFrontSaT4_ex : BOOL;
    runFrontSbT1_ex : BOOL;
    runFrontSbT2_ex : BOOL;
    runFrontSbT4_ex : BOOL;
    runFrontScT1_ex : BOOL;
    runFrontScT2_ex : BOOL;
    runFrontScT4_ex : BOOL;
    runFrontMT1_ex : BOOL;
    runFrontMT2_ex : BOOL;
    runFrontCT1_ex : BOOL;
    runFrontCT4_ex : BOOL;
    runFrontCT5_ex : BOOL;
    runBackSaT7_ex : BOOL;
    runBackScT7_ex : BOOL;
    runBackSbT7_ex : BOOL;
    runBackSbT6_ex : BOOL;
    runBackSaT6_ex : BOOL;
    sendDownSaT2_ex : BOOL;
    sendDownSbT2_ex : BOOL;
    sendDownScT2_ex : BOOL;
    toolPieceSaT3_ex : BOOL;
    toolPieceSaT5_ex : BOOL;
    toolPieceSbT3_ex : BOOL;
    toolPieceSbT5_ex : BOOL;
    toolPieceScT3_ex : BOOL;
    toolPieceScT5_ex : BOOL;
    sendDownCT2_ex : BOOL;
    sensorAT1_ex : BOOL;
    sensorAT2_ex : BOOL;
    sensorSaT1_ex : BOOL;
    sensorSaT2_ex : BOOL;
    sensorSaT3_ex : BOOL;
    sensorSaT4_ex : BOOL;
    sensorSaT5_ex : BOOL;
    sensorSaT6_ex : BOOL;
    sensorSaT7_ex : BOOL;
    sensorSbT1_ex : BOOL;
    sensorSbT2_ex : BOOL;
    sensorSbT3_ex : BOOL;
    sensorSbT4_ex : BOOL;
    sensorSbT5_ex : BOOL;
    sensorSbT6_ex : BOOL;
    sensorSbT7_ex : BOOL;
    sensorScT1_ex : BOOL;
    sensorScT2_ex : BOOL;
    sensorScT3_ex : BOOL;
    sensorScT4_ex : BOOL;
    sensorScT5_ex : BOOL;
    sensorScT6_ex : BOOL;
    sensorScT7_ex : BOOL;
    sensorMT1_ex : BOOL;
    sensorMT2_ex : BOOL;
    sensorCT1_ex : BOOL;
    sensorCT2_ex : BOOL;
    sensorCT4_ex : BOOL;
    sensorCT5_ex : BOOL;
    pushToRollCT4_ex : BOOL;
    pushToRollCT5_ex : BOOL;
    pushToRollCT6_ex : BOOL;
    sendLeftDownSaT6_ex : BOOL;
    sendLeftDownSbT6_ex : BOOL;
    sendLeftDownScT6_ex : BOOL;
    putPieceInSignal_ex : BOOL;
  END_VAR
  VAR
    removeFromWarehouse0 : removeFromWarehouse;
  END_VAR
  VAR
    runUnload AT %IX0.1.0.1 : BOOL;
    runTransformMach1 AT %IX0.1.0.2 : BOOL;
    runTransformMach2 AT %IX0.1.0.3 : BOOL;
    runTransformMach3 AT %IX0.1.0.4 : BOOL;
  END_VAR
  VAR_EXTERNAL
    readyToSendSaT3_ex : BOOL;
    readyToSendSaT5_ex : BOOL;
    readyToSendSbT3_ex : BOOL;
    readyToSendSbT5_ex : BOOL;
    readyToSendScT3_ex : BOOL;
    readyToSendScT5_ex : BOOL;
  END_VAR

  INITIAL_STEP Step9:
  END_STEP

  TRANSITION FROM Step9 TO Step30
    := mount and (not warehouseBusy);
  END_TRANSITION

  STEP Step30:
    action0(S);
    warehouseBusy(S);
    unloadBottom(P1);
    mount(R);
  END_STEP

  ACTION action0:
    removeFromWarehouse0(pieceNum := pieceToUnload, sensorAT1 := sensorAT1);
    warehouseIn := removeFromWarehouse0.warehouseIn;
  END_ACTION

  ACTION unloadBottom:
    pieceToUnload := bottomPiece;
  END_ACTION

  TRANSITION FROM Step30 TO Step12
    := sensorAT1_ex;
  END_TRANSITION

  STEP Step12:
    runFrontSaT1_ex(N);
    runFrontAT1_ex(N);
  END_STEP

  TRANSITION FROM Step12 TO (Step11, Step14)
    := NOT sensorAT1_ex;
  END_TRANSITION

  STEP Step11:
  END_STEP

  TRANSITION FROM Step11 TO Step10
    := sensorSaT1_ex;
  END_TRANSITION

  STEP Step10:
    runFrontSaT2_ex(N);
  END_STEP

  TRANSITION FROM Step10 TO Step13
    := not sensorSaT1_ex;
  END_TRANSITION

  STEP Step13:
  END_STEP

  TRANSITION FROM Step13 TO Step15
    := sensorSaT2_ex;
  END_TRANSITION

  STEP Step15:
    runFrontSbT1_ex(N);
  END_STEP

  TRANSITION FROM Step15 TO Step16
    := not sensorSaT2_ex;
  END_TRANSITION

  STEP Step16:
  END_STEP

  TRANSITION FROM Step16 TO Step17
    := sensorSbT1_ex;
  END_TRANSITION

  STEP Step17:
    runFrontSbT2_ex(N);
  END_STEP

  TRANSITION FROM Step17 TO Step18
    := not sensorSbT1_ex;
  END_TRANSITION

  STEP Step18:
  END_STEP

  TRANSITION FROM Step18 TO Step19
    := sensorSbT2_ex;
  END_TRANSITION

  STEP Step19:
    runFrontScT1_ex(N);
  END_STEP

  TRANSITION FROM Step19 TO Step20
    := not sensorSbT2_ex;
  END_TRANSITION

  STEP Step20:
  END_STEP

  TRANSITION FROM Step20 TO Step21
    := sensorScT1_ex;
  END_TRANSITION

  STEP Step21:
    runFrontScT2_ex(N);
  END_STEP

  TRANSITION FROM Step21 TO Step22
    := not sensorScT1_ex;
  END_TRANSITION

  STEP Step22:
  END_STEP

  TRANSITION FROM Step22 TO Step23
    := sensorScT2_ex;
  END_TRANSITION

  STEP Step23:
    runFrontMT1_ex(N);
  END_STEP

  TRANSITION FROM Step23 TO Step24
    := not sensorScT2_ex;
  END_TRANSITION

  STEP Step24:
  END_STEP

  TRANSITION FROM Step24 TO Step25
    := sensorMT1_ex;
  END_TRANSITION

  STEP Step25:
    receivePieceMT2_ex(N);
  END_STEP

  TRANSITION FROM Step25 TO Step26
    := not sensorMT1_ex;
  END_TRANSITION

  STEP Step26:
  END_STEP

  TRANSITION FROM Step26 TO Step39
    := sensorMT2_ex;
  END_TRANSITION

  STEP Step39:
  END_STEP

  TRANSITION FROM (Step39, Step40) TO Step1
    := not gantryBusy_ex;
  END_TRANSITION

  STEP Step1:
    X1Y0_ex(N);
  END_STEP

  TRANSITION FROM Step1 TO Step2
    := gantryBusy_ex;
  END_TRANSITION

  STEP Step2:
  END_STEP

  TRANSITION FROM Step2 TO Step3
    := not gantryBusy_ex;
  END_TRANSITION

  STEP Step3:
    pickPiece_ex(N);
  END_STEP

  TRANSITION FROM Step3 TO Step4
    := gantryBusy_ex;
  END_TRANSITION

  STEP Step4:
  END_STEP

  TRANSITION FROM Step4 TO Step5
    := not gantryBusy_ex;
  END_TRANSITION

  STEP Step5:
    receivePieceMT2_ex(N);
    runFrontMT1_ex(N);
  END_STEP

  TRANSITION FROM Step5 TO Step7
    := sensorMT2_ex;
  END_TRANSITION

  STEP Step7:
    releasePiece_ex(N);
  END_STEP

  TRANSITION FROM Step7 TO Step8
    := gantryBusy_ex;
  END_TRANSITION

  STEP Step8:
  END_STEP

  TRANSITION FROM Step8 TO Step0
    := not gantryBusy_ex;
  END_TRANSITION

  STEP Step0:
    runFrontMT2_ex(N);
    runFrontCT1_ex(N);
  END_STEP

  TRANSITION FROM Step0 TO Step6
    := sensorCT1_ex;
  END_TRANSITION

  STEP Step6:
  END_STEP

  TRANSITION FROM Step6 TO Step27
    := not sensorCT1_Ex;
  END_TRANSITION

  STEP Step27:
    sendDownCT2_ex(N);
  END_STEP

  TRANSITION FROM Step27 TO Step46
    := sensorCT2_ex;
  END_TRANSITION

  STEP Step46:
  END_STEP

  TRANSITION FROM Step46 TO Step47
    := not sensorCT2_ex;
  END_TRANSITION

  STEP Step47:
    runFrontCT4_ex(N);
  END_STEP

  TRANSITION FROM Step47 TO Step48
    := sensorCT4_Ex;
  END_TRANSITION

  STEP Step48:
  END_STEP

  TRANSITION FROM Step48 TO Step49
    := not sensorCT4_Ex;
  END_TRANSITION

  STEP Step49:
    runFrontCT5_ex(N);
  END_STEP

  TRANSITION FROM Step49 TO Step50
    := sensorCT5_Ex;
  END_TRANSITION

  STEP Step50:
  END_STEP

  TRANSITION FROM Step50 TO Step51
    := not sensorCT5_ex;
  END_TRANSITION

  STEP Step51:
    pushToRollCT6_ex(N);
  END_STEP

  TRANSITION FROM Step51 TO Step52
    := sensorCT6_ex;
  END_TRANSITION

  STEP Step52:
  END_STEP

  TRANSITION FROM Step52 TO Step9
    := not sensorCT6_ex;
  END_TRANSITION

  STEP Step14:
    unloadTop(N);
    action0(R);
  END_STEP

  ACTION unloadTop:
    pieceToUnload := topPiece;
  END_ACTION

  TRANSITION FROM Step14 TO sendTop
    := true;
  END_TRANSITION

  STEP sendTop:
    action0(S);
  END_STEP

  TRANSITION FROM sendTop TO Step28
    := sensorAT1_ex;
  END_TRANSITION

  STEP Step28:
    runFrontSaT1_ex(N);
    runFrontAT1_ex(N);
  END_STEP

  TRANSITION FROM Step28 TO (Step42, Step44)
    := NOT sensorAT1_ex;
  END_TRANSITION

  STEP Step42:
  END_STEP

  TRANSITION FROM Step42 TO Step41
    := sensorSaT1_ex;
  END_TRANSITION

  STEP Step41:
    runFrontSaT2_ex(N);
  END_STEP

  TRANSITION FROM Step41 TO Step43
    := not sensorSaT1_ex;
  END_TRANSITION

  STEP Step43:
  END_STEP

  TRANSITION FROM Step43 TO Step45
    := sensorSaT2_ex;
  END_TRANSITION

  STEP Step45:
    runFrontSbT1_ex(N);
  END_STEP

  TRANSITION FROM Step45 TO Step29
    := not sensorSaT2_ex;
  END_TRANSITION

  STEP Step29:
  END_STEP

  TRANSITION FROM Step29 TO Step31
    := sensorSbT1_ex;
  END_TRANSITION

  STEP Step31:
    runFrontSbT2_ex(N);
  END_STEP

  TRANSITION FROM Step31 TO Step32
    := not sensorSbT1_ex;
  END_TRANSITION

  STEP Step32:
  END_STEP

  TRANSITION FROM Step32 TO Step33
    := sensorSbT2_ex;
  END_TRANSITION

  STEP Step33:
    runFrontScT1_ex(N);
  END_STEP

  TRANSITION FROM Step33 TO Step34
    := not sensorSbT2_ex;
  END_TRANSITION

  STEP Step34:
  END_STEP

  TRANSITION FROM Step34 TO Step35
    := sensorScT1_ex;
  END_TRANSITION

  STEP Step35:
    runFrontScT2_ex(N);
  END_STEP

  TRANSITION FROM Step35 TO Step36
    := not sensorScT1_ex;
  END_TRANSITION

  STEP Step36:
  END_STEP

  TRANSITION FROM Step36 TO Step37
    := sensorScT2_ex;
  END_TRANSITION

  STEP Step37:
    receivePieceMT1_ex(N);
  END_STEP

  TRANSITION FROM Step37 TO Step38
    := not sensorScT2_ex;
  END_TRANSITION

  STEP Step38:
  END_STEP

  TRANSITION FROM Step38 TO Step40
    := sensorMT1_ex;
  END_TRANSITION

  STEP Step40:
  END_STEP

  STEP Step44:
    warehouseBusy(R);
    action0(R);
  END_STEP

  TRANSITION FROM Step44 TO Step9
    := true;
  END_TRANSITION

END_PROGRAM

PROGRAM loadProgram
  VAR
    warehouseIn AT %IW0.0.2.0 : INT;
  END_VAR
  VAR_EXTERNAL
    runFrontCT6_ex : BOOL;
    sensorCT6_ex : BOOL;
    sendRightDownCT2_ex : BOOL;
  END_VAR
  VAR
    sensorAT1 AT %IX0.0.0.0 : BOOL;
    PM AT %IW0.1.1.2 : INT;
  END_VAR
  VAR
    initialPiece : INT;
    finalPiece : INT;
  END_VAR
  VAR_EXTERNAL
    warehouseBusy : BOOL;
    runFrontAT1_ex : BOOL;
    runFrontSaT1_ex : BOOL;
    runFrontSaT2_ex : BOOL;
    runFrontSaT4_ex : BOOL;
    runFrontSbT1_ex : BOOL;
    runFrontSbT2_ex : BOOL;
    runFrontSbT4_ex : BOOL;
    runFrontScT1_ex : BOOL;
    runFrontScT2_ex : BOOL;
    runFrontScT4_ex : BOOL;
    runFrontMT1_ex : BOOL;
    runFrontMT2_ex : BOOL;
    runBackMT5_ex : BOOL;
    runFrontCT1_ex : BOOL;
    runFrontCT3_ex : BOOL;
    runFrontCT4_ex : BOOL;
    runFrontCT5_ex : BOOL;
    runBackSaT7_ex : BOOL;
    runBackScT7_ex : BOOL;
    runBackSbT7_ex : BOOL;
    runBackSbT6_ex : BOOL;
    runBackSaT6_ex : BOOL;
    runBackScT6_ex : BOOL;
    runBackCT9_ex : BOOL;
    runBackCT3_ex : BOOL;
    sendDownSaT2_ex : BOOL;
    sendDownSbT2_ex : BOOL;
    sendDownScT2_ex : BOOL;
    toolPieceSaT3_ex : BOOL;
    toolPieceSaT5_ex : BOOL;
    toolPieceSbT3_ex : BOOL;
    toolPieceSbT5_ex : BOOL;
    toolPieceScT3_ex : BOOL;
    toolPieceScT5_ex : BOOL;
    sendDownCT2_ex : BOOL;
    sensorAT1_ex : BOOL;
    sensorAT2_ex : BOOL;
    sensorSaT1_ex : BOOL;
    sensorSaT2_ex : BOOL;
    sensorSaT3_ex : BOOL;
    sensorSaT4_ex : BOOL;
    sensorSaT5_ex : BOOL;
    sensorSaT6_ex : BOOL;
    sensorSaT7_ex : BOOL;
    sensorSbT1_ex : BOOL;
    sensorSbT2_ex : BOOL;
    sensorSbT3_ex : BOOL;
    sensorSbT4_ex : BOOL;
    sensorSbT5_ex : BOOL;
    sensorSbT6_ex : BOOL;
    sensorSbT7_ex : BOOL;
    sensorScT1_ex : BOOL;
    sensorScT2_ex : BOOL;
    sensorScT3_ex : BOOL;
    sensorScT4_ex : BOOL;
    sensorScT5_ex : BOOL;
    sensorScT6_ex : BOOL;
    sensorScT7_ex : BOOL;
    sensorMT1_ex : BOOL;
    sensorMT2_ex : BOOL;
    sensorCT1_ex : BOOL;
    sensorCT2_ex : BOOL;
    sensorCT3_ex : BOOL;
    sensorCT4_ex : BOOL;
    sensorCT5_ex : BOOL;
    sensorCT7_ex : BOOL;
    sensorCT8_ex : BOOL;
    sensorCT9_ex : BOOL;
    sensorMT6_ex : BOOL;
    sensorMT5_ex : BOOL;
    pushToRollCT4_ex : BOOL;
    pushToRollCT5_ex : BOOL;
    pushToRollCT6_ex : BOOL;
    sendLeftDownSaT6_ex : BOOL;
    sendLeftDownSbT6_ex : BOOL;
    sendLeftDownScT6_ex : BOOL;
    sendLeftDownCT8_ex : BOOL;
    runBackCT8_ex : BOOL;
    runBackMT6_ex : BOOL;
    runBackCT7_ex : BOOL;
    putPieceInSignal_ex : BOOL;
  END_VAR
  VAR
    removeFromWarehouse0 : removeFromWarehouse;
  END_VAR
  VAR
    runUnload AT %IX0.1.0.1 : BOOL;
    runTransformMach1 AT %IX0.1.0.2 : BOOL;
    runTransformMach2 AT %IX0.1.0.3 : BOOL;
    runTransformMach3 AT %IX0.1.0.4 : BOOL;
    cell1Busy AT %QX0.1.0.5 : BOOL;
    cell2Busy AT %QX0.1.0.6 : BOOL;
    cell3Busy AT %QX0.1.0.7 : BOOL;
  END_VAR
  VAR_EXTERNAL
    readyToSendSaT3_ex : BOOL;
    readyToSendSaT5_ex : BOOL;
    readyToSendSbT3_ex : BOOL;
    readyToSendSbT5_ex : BOOL;
    readyToSendScT3_ex : BOOL;
    readyToSendScT5_ex : BOOL;
  END_VAR

  INITIAL_STEP Step7:
  END_STEP

  TRANSITION FROM Step7 TO Step165
    := sensorCT3_ex;
  END_TRANSITION

  STEP Step165:
    runBackCT3_ex(N);
  END_STEP

  TRANSITION FROM Step165 TO Step8
    := not sensorCT3_ex;
  END_TRANSITION

  STEP Step8:
    sendRightDownCT2_ex(N);
  END_STEP

  TRANSITION FROM Step8 TO Step78
    := sensorCT2_ex;
  END_TRANSITION

  STEP Step78:
    runFrontCT4_ex(N);
  END_STEP

  TRANSITION FROM Step78 TO Step79
    := not sensorCT2_ex;
  END_TRANSITION

  STEP Step79:
  END_STEP

  TRANSITION FROM Step79 TO Step80
    := sensorCT4_ex;
  END_TRANSITION

  STEP Step80:
    runFrontCT5_ex(N);
  END_STEP

  TRANSITION FROM Step80 TO Step82
    := not sensorCT4_ex;
  END_TRANSITION

  STEP Step82:
  END_STEP

  TRANSITION FROM Step82 TO Step83
    := sensorCT5_ex;
  END_TRANSITION

  STEP Step83:
    runFrontCT6_ex(N);
  END_STEP

  TRANSITION FROM Step83 TO Step84
    := not sensorCT5_ex;
  END_TRANSITION

  STEP Step84:
  END_STEP

  TRANSITION FROM Step84 TO Step85
    := sensorCT6_ex;
  END_TRANSITION

  STEP Step85:
    sendLeftDownCT8_ex(N);
  END_STEP

  TRANSITION FROM Step85 TO (Step11, Step12)
    := not sensorCT6_ex;
  END_TRANSITION

  STEP Step11:
  END_STEP

  TRANSITION FROM Step11 TO Step6
    := true;
  END_TRANSITION

  STEP Step6:
  END_STEP

  TRANSITION FROM Step6 TO Step163
    := sensorCT8_ex;
  END_TRANSITION

  STEP Step163:
    runBackCT7_ex(N);
  END_STEP

  TRANSITION FROM Step163 TO Step4
    := not sensorCT8_ex;
  END_TRANSITION

  STEP Step4:
  END_STEP

  TRANSITION FROM Step4 TO Step162
    := sensorCT7_ex;
  END_TRANSITION

  STEP Step162:
    runBackMT6_ex(N);
  END_STEP

  TRANSITION FROM Step162 TO Step3
    := not sensorCT7_ex;
  END_TRANSITION

  STEP Step3:
  END_STEP

  TRANSITION FROM Step3 TO Step161
    := sensorMT6_ex;
  END_TRANSITION

  STEP Step161:
    runBackMT5_ex(N);
  END_STEP

  TRANSITION FROM Step161 TO Step2
    := not sensorMT6_ex;
  END_TRANSITION

  STEP Step2:
  END_STEP

  TRANSITION FROM Step2 TO Step151
    := sensorMT5_ex;
  END_TRANSITION

  STEP Step151:
    runBackScT6_ex(N);
  END_STEP

  TRANSITION FROM Step151 TO Step1
    := not sensorMT5_ex;
  END_TRANSITION

  STEP Step1:
  END_STEP

  TRANSITION FROM Step1 TO Step149
    := sensorScT6_ex;
  END_TRANSITION

  STEP Step149:
    runBackScT7_ex(N);
  END_STEP

  TRANSITION FROM Step149 TO Step0
    := not sensorScT6_ex;
  END_TRANSITION

  STEP Step0:
  END_STEP

  TRANSITION FROM Step0 TO Step147
    := sensorScT7_ex;
  END_TRANSITION

  STEP Step147:
    runBackSbT6_ex(N);
  END_STEP

  TRANSITION FROM Step147 TO Step148
    := not sensorScT7_ex;
  END_TRANSITION

  STEP Step148:
  END_STEP

  TRANSITION FROM Step148 TO Step152
    := sensorSbT6_ex;
  END_TRANSITION

  STEP Step152:
    runBackSbT7_ex(N);
  END_STEP

  TRANSITION FROM Step152 TO Step153
    := not sensorSbT6_ex;
  END_TRANSITION

  STEP Step153:
  END_STEP

  TRANSITION FROM Step153 TO Step154
    := sensorSbT7_ex;
  END_TRANSITION

  STEP Step154:
    runBackSaT6_ex(N);
  END_STEP

  TRANSITION FROM Step154 TO Step156
    := not sensorSbT7_ex;
  END_TRANSITION

  STEP Step156:
  END_STEP

  TRANSITION FROM Step156 TO Step157
    := sensorSaT6_ex;
  END_TRANSITION

  STEP Step157:
    runBackSaT7_ex(N);
  END_STEP

  TRANSITION FROM Step157 TO Step150
    := not sensorSaT6_ex;
  END_TRANSITION

  STEP Step150:
  END_STEP

  TRANSITION FROM Step150 TO Step155
    := sensorSaT7_ex;
  END_TRANSITION

  STEP Step155:
    putPieceInSignal_ex(N);
    cell3Busy(R);
  END_STEP

  TRANSITION FROM Step155 TO Step158
    := not sensorSaT7_ex;
  END_TRANSITION

  STEP Step158:
  END_STEP

  TRANSITION FROM Step158 TO Step159
    := sensorAT2_ex;
  END_TRANSITION

  STEP Step159:
  END_STEP

  TRANSITION FROM Step159 TO Step160
    := not sensorAT2_ex;
  END_TRANSITION

  STEP Step160:
  END_STEP

  STEP Step12:
  END_STEP

  TRANSITION FROM Step12 TO Step7
    := true;
  END_TRANSITION

  INITIAL_STEP Step5:
  END_STEP

  TRANSITION FROM Step5 TO Step164
    := sensorCT9_ex;
  END_TRANSITION

  STEP Step164:
    runBackCT8_ex(N);
    runBackCT9_ex(N);
  END_STEP

  TRANSITION FROM Step164 TO (Step9, Step10)
    := not sensorCT9_ex;
  END_TRANSITION

  STEP Step9:
  END_STEP

  TRANSITION FROM Step9 TO Step6
    := true;
  END_TRANSITION

  STEP Step10:
  END_STEP

  TRANSITION FROM Step10 TO Step5
    := true;
  END_TRANSITION

END_PROGRAM

PROGRAM gantryProgram
  VAR_EXTERNAL
    sensorCT7_ex : BOOL;
    pushUpCT6_ex : BOOL;
    runFrontCT7_ex : BOOL;
    sensorCT8_ex : BOOL;
    sendUpRightMT6_ex : BOOL;
    sendRightUpCT8_ex : BOOL;
    runFrontMT3_ex : BOOL;
    runFrontMT4_ex : BOOL;
    sensorCT6_ex : BOOL;
    sensorMT3_ex : BOOL;
    sensorMT4_ex : BOOL;
    sensorMT6_ex : BOOL;
    receivePieceMT1_ex : BOOL;
    receivePieceMT2_ex : BOOL;
    receivePieceMT4_ex : BOOL;
    sendDownMT2_ex : BOOL;
  END_VAR
  VAR
    mount AT %IX0.1.0.8 : BOOL;
  END_VAR
  VAR_EXTERNAL
    gantryBusy_ex : BOOL;
    pickPiece_ex : BOOL;
    releasePiece_ex : BOOL;
    X0Y0_ex : BOOL;
    X0Y1_ex : BOOL;
    X0Y2_ex : BOOL;
    X0Y3_ex : BOOL;
    X0Y4_ex : BOOL;
    X1Y0_ex : BOOL;
    X1Y1_ex : BOOL;
    X1Y2_ex : BOOL;
    X1Y3_ex : BOOL;
    X1Y4_ex : BOOL;
  END_VAR
  VAR
    warehouseIn AT %IW0.0.2.0 : INT;
    sensorAT1 AT %IX0.0.0.0 : BOOL;
    PM AT %IW0.1.1.2 : INT;
    bottomPiece AT %IW0.1.1.5 : INT;
    topPiece AT %IW0.1.1.1 : INT;
  END_VAR
  VAR
    pieceToUnload : INT := 1;
  END_VAR
  VAR
    warehouseBusy AT %QX0.1.0.0 : BOOL;
  END_VAR
  VAR_EXTERNAL
    runFrontAT1_ex : BOOL;
    runFrontSaT1_ex : BOOL;
    runFrontSaT2_ex : BOOL;
    runFrontSaT4_ex : BOOL;
    runFrontSbT1_ex : BOOL;
    runFrontSbT2_ex : BOOL;
    runFrontSbT4_ex : BOOL;
    runFrontScT1_ex : BOOL;
    runFrontScT2_ex : BOOL;
    runFrontScT4_ex : BOOL;
    runFrontMT1_ex : BOOL;
    runFrontMT2_ex : BOOL;
    runFrontCT1_ex : BOOL;
    runFrontCT4_ex : BOOL;
    runFrontCT5_ex : BOOL;
    runBackSaT7_ex : BOOL;
    runBackScT7_ex : BOOL;
    runBackSbT7_ex : BOOL;
    runBackSbT6_ex : BOOL;
    runBackSaT6_ex : BOOL;
    sendDownSaT2_ex : BOOL;
    sendDownSbT2_ex : BOOL;
    sendDownScT2_ex : BOOL;
    toolPieceSaT3_ex : BOOL;
    toolPieceSaT5_ex : BOOL;
    toolPieceSbT3_ex : BOOL;
    toolPieceSbT5_ex : BOOL;
    toolPieceScT3_ex : BOOL;
    toolPieceScT5_ex : BOOL;
    sendDownCT2_ex : BOOL;
    sensorAT1_ex : BOOL;
    sensorAT2_ex : BOOL;
    sensorSaT1_ex : BOOL;
    sensorSaT2_ex : BOOL;
    sensorSaT3_ex : BOOL;
    sensorSaT4_ex : BOOL;
    sensorSaT5_ex : BOOL;
    sensorSaT6_ex : BOOL;
    sensorSaT7_ex : BOOL;
    sensorSbT1_ex : BOOL;
    sensorSbT2_ex : BOOL;
    sensorSbT3_ex : BOOL;
    sensorSbT4_ex : BOOL;
    sensorSbT5_ex : BOOL;
    sensorSbT6_ex : BOOL;
    sensorSbT7_ex : BOOL;
    sensorScT1_ex : BOOL;
    sensorScT2_ex : BOOL;
    sensorScT3_ex : BOOL;
    sensorScT4_ex : BOOL;
    sensorScT5_ex : BOOL;
    sensorScT6_ex : BOOL;
    sensorScT7_ex : BOOL;
    sensorMT1_ex : BOOL;
    sensorMT2_ex : BOOL;
    sensorCT1_ex : BOOL;
    sensorCT2_ex : BOOL;
    sensorCT4_ex : BOOL;
    sensorCT5_ex : BOOL;
    pushToRollCT4_ex : BOOL;
    pushToRollCT5_ex : BOOL;
    pushToRollCT6_ex : BOOL;
    sendLeftDownSaT6_ex : BOOL;
    sendLeftDownSbT6_ex : BOOL;
    sendLeftDownScT6_ex : BOOL;
    putPieceInSignal_ex : BOOL;
  END_VAR
  VAR
    removeFromWarehouse0 : removeFromWarehouse;
  END_VAR
  VAR
    runUnload AT %IX0.1.0.1 : BOOL;
    runTransformMach1 AT %IX0.1.0.2 : BOOL;
    runTransformMach2 AT %IX0.1.0.3 : BOOL;
    runTransformMach3 AT %IX0.1.0.4 : BOOL;
  END_VAR
  VAR_EXTERNAL
    readyToSendSaT3_ex : BOOL;
    readyToSendSaT5_ex : BOOL;
    readyToSendSbT3_ex : BOOL;
    readyToSendSbT5_ex : BOOL;
    readyToSendScT3_ex : BOOL;
    readyToSendScT5_ex : BOOL;
  END_VAR

  INITIAL_STEP Step9:
  END_STEP

  TRANSITION FROM Step9 TO Step30
    := mount and (not warehouseBusy);
  END_TRANSITION

  STEP Step30:
    action0(S);
    warehouseBusy(S);
    unloadBottom(N);
    mount(R);
  END_STEP

  ACTION action0:
    removeFromWarehouse0(pieceNum := pieceToUnload, sensorAT1 := sensorAT1);
    warehouseIn := removeFromWarehouse0.warehouseIn;
  END_ACTION

  ACTION unloadBottom:
    pieceToUnload := bottomPiece;
  END_ACTION

  TRANSITION FROM Step30 TO Step12
    := sensorAT1_ex;
  END_TRANSITION

  STEP Step12:
    runFrontSaT1_ex(N);
    runFrontAT1_ex(N);
  END_STEP

  TRANSITION FROM Step12 TO (Step11, Step14)
    := NOT sensorAT1_ex;
  END_TRANSITION

  STEP Step11:
  END_STEP

  TRANSITION FROM Step11 TO Step10
    := sensorSaT1_ex;
  END_TRANSITION

  STEP Step10:
    runFrontSaT2_ex(N);
  END_STEP

  TRANSITION FROM Step10 TO Step13
    := not sensorSaT1_ex;
  END_TRANSITION

  STEP Step13:
  END_STEP

  TRANSITION FROM Step13 TO Step15
    := sensorSaT2_ex;
  END_TRANSITION

  STEP Step15:
    runFrontSbT1_ex(N);
  END_STEP

  TRANSITION FROM Step15 TO Step16
    := not sensorSaT2_ex;
  END_TRANSITION

  STEP Step16:
  END_STEP

  TRANSITION FROM Step16 TO Step17
    := sensorSbT1_ex;
  END_TRANSITION

  STEP Step17:
    runFrontSbT2_ex(N);
  END_STEP

  TRANSITION FROM Step17 TO Step18
    := not sensorSbT1_ex;
  END_TRANSITION

  STEP Step18:
  END_STEP

  TRANSITION FROM Step18 TO Step19
    := sensorSbT2_ex;
  END_TRANSITION

  STEP Step19:
    runFrontScT1_ex(N);
  END_STEP

  TRANSITION FROM Step19 TO Step20
    := not sensorSbT2_ex;
  END_TRANSITION

  STEP Step20:
  END_STEP

  TRANSITION FROM Step20 TO Step21
    := sensorScT1_ex;
  END_TRANSITION

  STEP Step21:
    runFrontScT2_ex(N);
  END_STEP

  TRANSITION FROM Step21 TO Step22
    := not sensorScT1_ex;
  END_TRANSITION

  STEP Step22:
  END_STEP

  TRANSITION FROM Step22 TO Step23
    := sensorScT2_ex;
  END_TRANSITION

  STEP Step23:
    runFrontMT1_ex(N);
  END_STEP

  TRANSITION FROM Step23 TO Step24
    := not sensorScT2_ex;
  END_TRANSITION

  STEP Step24:
  END_STEP

  TRANSITION FROM Step24 TO Step25
    := sensorMT1_ex;
  END_TRANSITION

  STEP Step25:
    sendDownMT2_ex(N);
  END_STEP

  TRANSITION FROM Step25 TO Step26
    := not sensorMT1_ex;
  END_TRANSITION

  STEP Step26:
  END_STEP

  TRANSITION FROM Step26 TO Step39
    := sensorMT2_ex;
  END_TRANSITION

  STEP Step39:
    runFrontMT3_ex(N);
  END_STEP

  TRANSITION FROM Step39 TO Step53
    := not sensorMT2_ex;
  END_TRANSITION

  STEP Step53:
  END_STEP

  TRANSITION FROM Step53 TO (Step54, Step58)
    := sensorMT3_ex;
  END_TRANSITION

  STEP Step54:
    receivePieceMT4_ex(N);
  END_STEP

  TRANSITION FROM Step54 TO Step56
    := not sensorMT3_ex;
  END_TRANSITION

  STEP Step56:
  END_STEP

  TRANSITION FROM Step56 TO Step55
    := sensorMT4_ex;
  END_TRANSITION

  STEP Step55:
  END_STEP

  TRANSITION FROM (Step55, Step57) TO Step59
    := not gantryBusy_ex;
  END_TRANSITION

  STEP Step59:
    pickPiece_ex(N);
  END_STEP

  TRANSITION FROM Step59 TO Step60
    := gantryBusy_ex;
  END_TRANSITION

  STEP Step60:
  END_STEP

  TRANSITION FROM Step60 TO Step61
    := not gantryBusy_ex;
  END_TRANSITION

  STEP Step61:
    X0Y3_ex(N);
  END_STEP

  TRANSITION FROM Step61 TO Step62
    := gantryBusy_ex;
  END_TRANSITION

  STEP Step62:
  END_STEP

  TRANSITION FROM Step62 TO Step63
    := not gantryBusy_ex;
  END_TRANSITION

  STEP Step63:
    releasePiece_ex(N);
  END_STEP

  TRANSITION FROM Step63 TO Step64
    := gantryBusy_ex;
  END_TRANSITION

  STEP Step64:
  END_STEP

  TRANSITION FROM Step64 TO Step65
    := not gantryBusy_ex;
  END_TRANSITION

  STEP Step65:
    pickPiece_ex(N);
  END_STEP

  TRANSITION FROM Step65 TO Step66
    := gantryBusy_ex;
  END_TRANSITION

  STEP Step66:
  END_STEP

  TRANSITION FROM Step66 TO Step67
    := not gantryBusy_ex;
  END_TRANSITION

  STEP Step67:
    X1Y3_ex(N);
  END_STEP

  TRANSITION FROM Step67 TO Step68
    := gantryBusy_ex;
  END_TRANSITION

  STEP Step68:
  END_STEP

  TRANSITION FROM Step68 TO Step69
    := not gantryBusy_ex;
  END_TRANSITION

  STEP Step69:
    releasePiece_ex(N);
  END_STEP

  TRANSITION FROM Step69 TO Step70
    := gantryBusy_ex;
  END_TRANSITION

  STEP Step70:
  END_STEP

  TRANSITION FROM Step70 TO Step71
    := not gantryBusy_ex;
  END_TRANSITION

  STEP Step71:
    runFrontMT4_ex(N);
    sendUpRightMT6_ex(N);
  END_STEP

  TRANSITION FROM Step71 TO Step81
    := sensorMT4_ex;
  END_TRANSITION

  STEP Step81:
  END_STEP

  TRANSITION FROM Step81 TO Step82
    := not sensorMT4_ex;
  END_TRANSITION

  STEP Step82:
  END_STEP

  TRANSITION FROM Step82 TO Step72
    := sensorMT6_ex;
  END_TRANSITION

  STEP Step72:
  END_STEP

  TRANSITION FROM Step72 TO Step73
    := not sensorMT6_ex;
  END_TRANSITION

  STEP Step73:
    runFrontCT7_ex(N);
  END_STEP

  TRANSITION FROM Step73 TO Step74
    := sensorCT7_ex;
  END_TRANSITION

  STEP Step74:
    sendRightUpCT8_ex(N);
  END_STEP

  TRANSITION FROM Step74 TO Step75
    := not sensorCT7_ex;
  END_TRANSITION

  STEP Step75:
  END_STEP

  TRANSITION FROM Step75 TO Step76
    := sensorCT8_ex;
  END_TRANSITION

  STEP Step76:
  END_STEP

  TRANSITION FROM Step76 TO Step77
    := not sensorCT8_ex;
  END_TRANSITION

  STEP Step77:
    pushUpCT6_ex(N);
  END_STEP

  TRANSITION FROM Step77 TO Step79
    := sensorCT6_ex;
  END_TRANSITION

  STEP Step79:
  END_STEP

  TRANSITION FROM Step79 TO Step80
    := not sensorCT6_ex;
  END_TRANSITION

  STEP Step80:
  END_STEP

  TRANSITION FROM Step80 TO Step78
    := true;
  END_TRANSITION

  STEP Step78:
  END_STEP

  STEP Step58:
    X1Y3_ex(N);
  END_STEP

  TRANSITION FROM Step58 TO Step57
    := not gantryBusy_ex;
  END_TRANSITION

  STEP Step57:
  END_STEP

  STEP Step14:
    action0(R);
  END_STEP

  TRANSITION FROM Step14 TO sendTop
    := false;
  END_TRANSITION

  STEP sendTop:
    action0(S);
  END_STEP

  TRANSITION FROM sendTop TO Step28
    := sensorAT1_ex;
  END_TRANSITION

  STEP Step28:
    runFrontSaT1_ex(N);
    runFrontAT1_ex(N);
  END_STEP

  TRANSITION FROM Step28 TO (Step42, Step44)
    := NOT sensorAT1_ex;
  END_TRANSITION

  STEP Step42:
  END_STEP

  TRANSITION FROM Step42 TO Step41
    := sensorSaT1_ex;
  END_TRANSITION

  STEP Step41:
    runFrontSaT2_ex(N);
  END_STEP

  TRANSITION FROM Step41 TO Step43
    := not sensorSaT1_ex;
  END_TRANSITION

  STEP Step43:
  END_STEP

  TRANSITION FROM Step43 TO Step45
    := sensorSaT2_ex;
  END_TRANSITION

  STEP Step45:
    runFrontSbT1_ex(N);
  END_STEP

  TRANSITION FROM Step45 TO Step29
    := not sensorSaT2_ex;
  END_TRANSITION

  STEP Step29:
  END_STEP

  TRANSITION FROM Step29 TO Step31
    := sensorSbT1_ex;
  END_TRANSITION

  STEP Step31:
    runFrontSbT2_ex(N);
  END_STEP

  TRANSITION FROM Step31 TO Step32
    := not sensorSbT1_ex;
  END_TRANSITION

  STEP Step32:
  END_STEP

  TRANSITION FROM Step32 TO Step33
    := sensorSbT2_ex;
  END_TRANSITION

  STEP Step33:
    runFrontScT1_ex(N);
  END_STEP

  TRANSITION FROM Step33 TO Step34
    := not sensorSbT2_ex;
  END_TRANSITION

  STEP Step34:
  END_STEP

  TRANSITION FROM Step34 TO Step35
    := sensorScT1_ex;
  END_TRANSITION

  STEP Step35:
    runFrontScT2_ex(N);
  END_STEP

  TRANSITION FROM Step35 TO Step36
    := not sensorScT1_ex;
  END_TRANSITION

  STEP Step36:
  END_STEP

  TRANSITION FROM Step36 TO Step37
    := sensorScT2_ex;
  END_TRANSITION

  STEP Step37:
    receivePieceMT1_ex(N);
  END_STEP

  TRANSITION FROM Step37 TO Step38
    := not sensorScT2_ex;
  END_TRANSITION

  STEP Step38:
  END_STEP

  TRANSITION FROM Step38 TO Step40
    := sensorMT1_ex;
  END_TRANSITION

  STEP Step40:
  END_STEP

  STEP Step44:
    warehouseBusy(R);
    action0(R);
  END_STEP

  TRANSITION FROM Step44 TO Step9
    := true;
  END_TRANSITION

END_PROGRAM

PROGRAM unloadProgram
  VAR_EXTERNAL
    pieceNum : INT;
    takePiece : BOOL;
  END_VAR
  VAR
    warehouseIn AT %IW0.0.2.0 : INT;
    sensorAT1 AT %IX0.0.0.0 : BOOL;
    PM AT %IW0.1.1.2 : INT;
    initialPiece AT %IW0.1.1.0 : INT;
    finalPiece AT %IW0.1.1.3 : INT;
    warehouseBusy AT %IX0.1.0.0 : BOOL;
  END_VAR
  VAR_EXTERNAL
    runFrontAT1_ex : BOOL;
    runFrontSaT1_ex : BOOL;
    runFrontSaT2_ex : BOOL;
    runFrontSaT4_ex : BOOL;
    runFrontSbT1_ex : BOOL;
    runFrontSbT2_ex : BOOL;
    runFrontSbT4_ex : BOOL;
    runFrontScT1_ex : BOOL;
    runFrontScT2_ex : BOOL;
    runFrontScT4_ex : BOOL;
    runFrontMT1_ex : BOOL;
    runFrontMT2_ex : BOOL;
    runFrontCT1_ex : BOOL;
    runFrontCT4_ex : BOOL;
    runFrontCT5_ex : BOOL;
    runBackSaT7_ex : BOOL;
    runBackScT7_ex : BOOL;
    runBackSbT7_ex : BOOL;
    runBackSbT6_ex : BOOL;
    runBackSaT6_ex : BOOL;
    sendDownSaT2_ex : BOOL;
    sendDownSbT2_ex : BOOL;
    sendDownScT2_ex : BOOL;
    toolPieceSaT3_ex : BOOL;
    toolPieceSaT5_ex : BOOL;
    toolPieceSbT3_ex : BOOL;
    toolPieceSbT5_ex : BOOL;
    toolPieceScT3_ex : BOOL;
    toolPieceScT5_ex : BOOL;
    sendDownCT2_ex : BOOL;
    sensorAT1_ex : BOOL;
    sensorAT2_ex : BOOL;
    sensorSaT1_ex : BOOL;
    sensorSaT2_ex : BOOL;
    sensorSaT3_ex : BOOL;
    sensorSaT4_ex : BOOL;
    sensorSaT5_ex : BOOL;
    sensorSaT6_ex : BOOL;
    sensorSaT7_ex : BOOL;
    sensorSbT1_ex : BOOL;
    sensorSbT2_ex : BOOL;
    sensorSbT3_ex : BOOL;
    sensorSbT4_ex : BOOL;
    sensorSbT5_ex : BOOL;
    sensorSbT6_ex : BOOL;
    sensorSbT7_ex : BOOL;
    sensorScT1_ex : BOOL;
    sensorScT2_ex : BOOL;
    sensorScT3_ex : BOOL;
    sensorScT4_ex : BOOL;
    sensorScT5_ex : BOOL;
    sensorScT6_ex : BOOL;
    sensorScT7_ex : BOOL;
    sensorMT1_ex : BOOL;
    sensorMT2_ex : BOOL;
    sensorCT1_ex : BOOL;
    sensorCT2_ex : BOOL;
    sensorCT4_ex : BOOL;
    sensorCT5_ex : BOOL;
    sensorCT6_ex : BOOL;
    pushToRollCT4_ex : BOOL;
    pushToRollCT5_ex : BOOL;
    pushToRollCT6_ex : BOOL;
    sendLeftDownSaT6_ex : BOOL;
    sendLeftDownSbT6_ex : BOOL;
    sendLeftDownScT6_ex : BOOL;
    putPieceInSignal_ex : BOOL;
  END_VAR
  VAR
    removeFromWarehouse0 : removeFromWarehouse;
  END_VAR
  VAR
    runUnload AT %IX0.1.0.1 : BOOL;
    runTransformMach1 AT %IX0.1.0.2 : BOOL;
    runTransformMach2 AT %IX0.1.0.3 : BOOL;
    runTransformMach3 AT %IX0.1.0.4 : BOOL;
  END_VAR
  VAR_EXTERNAL
    readyToSendSaT3_ex : BOOL;
    readyToSendSaT5_ex : BOOL;
    readyToSendSbT3_ex : BOOL;
    readyToSendSbT5_ex : BOOL;
    readyToSendScT3_ex : BOOL;
    readyToSendScT5_ex : BOOL;
  END_VAR

  INITIAL_STEP Step0:
  END_STEP

  TRANSITION FROM Step0 TO Step52
    := runUnload AND (not warehouseBusy);
  END_TRANSITION

  STEP Step52:
    warehouseBusy(S);
    runUnload(R);
  END_STEP

  TRANSITION FROM Step52 TO Step26
    := PM = 1;
  END_TRANSITION

  STEP Step26:
    action0(S);
  END_STEP

  ACTION action0:
    removeFromWarehouse0(pieceNum := initialPiece, sensorAT1 := sensorAT1);
    warehouseIn := removeFromWarehouse0.warehouseIn;
  END_ACTION

  TRANSITION FROM Step26 TO Step2
    := sensorAT1_ex;
  END_TRANSITION

  STEP Step2:
    runFrontSaT1_ex(N);
    runFrontAT1_ex(N);
  END_STEP

  TRANSITION FROM Step2 TO Step4
    := NOT sensorAT1_ex;
  END_TRANSITION

  STEP Step4:
    action0(R);
  END_STEP

  TRANSITION FROM Step4 TO (Step3, Step6)
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
    pushToRollCT4_ex(N);
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

  TRANSITION FROM Step25 TO Step1
    := not sensorCT4_ex;
  END_TRANSITION

  STEP Step1:
  END_STEP

  TRANSITION FROM Step1 TO Step85
    := true;
  END_TRANSITION

  STEP Step85:
  END_STEP

  STEP Step6:
    warehouseBusy(R);
  END_STEP

  TRANSITION FROM Step6 TO Step0
    := true;
  END_TRANSITION

  TRANSITION FROM Step52 TO Step47
    := PM = 2;
  END_TRANSITION

  STEP Step47:
    action0(S);
  END_STEP

  TRANSITION FROM Step47 TO Step46
    := sensorAT1_ex;
  END_TRANSITION

  STEP Step46:
    runFrontSaT1_ex(N);
    runFrontAT1_ex(N);
  END_STEP

  TRANSITION FROM Step46 TO Step28
    := NOT sensorAT1_ex;
  END_TRANSITION

  STEP Step28:
    action0(R);
  END_STEP

  TRANSITION FROM Step28 TO (Step27, Step30)
    := sensorSaT1_ex;
  END_TRANSITION

  STEP Step27:
    runFrontSaT2_ex(N);
  END_STEP

  TRANSITION FROM Step27 TO Step29
    := not sensorSaT1_ex;
  END_TRANSITION

  STEP Step29:
  END_STEP

  TRANSITION FROM Step29 TO Step31
    := sensorSaT2_ex;
  END_TRANSITION

  STEP Step31:
    runFrontSbT1_ex(N);
  END_STEP

  TRANSITION FROM Step31 TO Step32
    := not sensorSaT2_ex;
  END_TRANSITION

  STEP Step32:
  END_STEP

  TRANSITION FROM Step32 TO Step33
    := sensorSbT1_ex;
  END_TRANSITION

  STEP Step33:
    runFrontSbT2_ex(N);
  END_STEP

  TRANSITION FROM Step33 TO Step34
    := not sensorSbT1_ex;
  END_TRANSITION

  STEP Step34:
  END_STEP

  TRANSITION FROM Step34 TO Step35
    := sensorSbT2_ex;
  END_TRANSITION

  STEP Step35:
    runFrontScT1_ex(N);
  END_STEP

  TRANSITION FROM Step35 TO Step36
    := not sensorSbT2_ex;
  END_TRANSITION

  STEP Step36:
  END_STEP

  TRANSITION FROM Step36 TO Step37
    := sensorScT1_ex;
  END_TRANSITION

  STEP Step37:
    runFrontScT2_ex(N);
  END_STEP

  TRANSITION FROM Step37 TO Step38
    := not sensorScT1_ex;
  END_TRANSITION

  STEP Step38:
  END_STEP

  TRANSITION FROM Step38 TO Step39
    := sensorScT2_ex;
  END_TRANSITION

  STEP Step39:
    runFrontMT1_ex(N);
  END_STEP

  TRANSITION FROM Step39 TO Step40
    := not sensorScT2_ex;
  END_TRANSITION

  STEP Step40:
  END_STEP

  TRANSITION FROM Step40 TO Step41
    := sensorMT1_ex;
  END_TRANSITION

  STEP Step41:
    runFrontMT2_ex(N);
  END_STEP

  TRANSITION FROM Step41 TO Step42
    := not sensorMT1_ex;
  END_TRANSITION

  STEP Step42:
  END_STEP

  TRANSITION FROM Step42 TO Step43
    := sensorMT2_ex;
  END_TRANSITION

  STEP Step43:
    runFrontCT1_ex(N);
  END_STEP

  TRANSITION FROM Step43 TO Step44
    := not sensorMT2_ex;
  END_TRANSITION

  STEP Step44:
  END_STEP

  TRANSITION FROM Step44 TO Step45
    := sensorCT1_ex;
  END_TRANSITION

  STEP Step45:
    sendDownCT2_ex(N);
  END_STEP

  TRANSITION FROM Step45 TO Step48
    := not sensorCT1_ex;
  END_TRANSITION

  STEP Step48:
  END_STEP

  TRANSITION FROM Step48 TO Step49
    := sensorCT2_ex;
  END_TRANSITION

  STEP Step49:
    runFrontCT4_ex(N);
  END_STEP

  TRANSITION FROM Step49 TO Step50
    := not sensorCT2_ex;
  END_TRANSITION

  STEP Step50:
  END_STEP

  TRANSITION FROM Step50 TO Step51
    := sensorCT4_ex;
  END_TRANSITION

  STEP Step51:
    pushToRollCT5_ex(N);
  END_STEP

  TRANSITION FROM Step51 TO Step53
    := not sensorCT4_ex;
  END_TRANSITION

  STEP Step53:
  END_STEP

  TRANSITION FROM Step53 TO Step54
    := sensorCT5_ex;
  END_TRANSITION

  STEP Step54:
  END_STEP

  TRANSITION FROM Step54 TO Step55
    := not sensorCT5_ex;
  END_TRANSITION

  STEP Step55:
  END_STEP

  TRANSITION FROM Step55 TO Step85
    := true;
  END_TRANSITION

  STEP Step30:
    warehouseBusy(R);
  END_STEP

  TRANSITION FROM Step30 TO Step0
    := true;
  END_TRANSITION

  TRANSITION FROM Step52 TO Step80
    := PM = 3;
  END_TRANSITION

  STEP Step80:
    action0(S);
  END_STEP

  TRANSITION FROM Step80 TO Step58
    := sensorAT1_ex;
  END_TRANSITION

  STEP Step58:
    runFrontSaT1_ex(N);
    runFrontAT1_ex(N);
  END_STEP

  TRANSITION FROM Step58 TO Step57
    := NOT sensorAT1_ex;
  END_TRANSITION

  STEP Step57:
    action0(R);
  END_STEP

  TRANSITION FROM Step57 TO (Step56, Step60)
    := sensorSaT1_ex;
  END_TRANSITION

  STEP Step56:
    runFrontSaT2_ex(N);
  END_STEP

  TRANSITION FROM Step56 TO Step59
    := not sensorSaT1_ex;
  END_TRANSITION

  STEP Step59:
  END_STEP

  TRANSITION FROM Step59 TO Step61
    := sensorSaT2_ex;
  END_TRANSITION

  STEP Step61:
    runFrontSbT1_ex(N);
  END_STEP

  TRANSITION FROM Step61 TO Step62
    := not sensorSaT2_ex;
  END_TRANSITION

  STEP Step62:
  END_STEP

  TRANSITION FROM Step62 TO Step63
    := sensorSbT1_ex;
  END_TRANSITION

  STEP Step63:
    runFrontSbT2_ex(N);
  END_STEP

  TRANSITION FROM Step63 TO Step64
    := not sensorSbT1_ex;
  END_TRANSITION

  STEP Step64:
  END_STEP

  TRANSITION FROM Step64 TO Step65
    := sensorSbT2_ex;
  END_TRANSITION

  STEP Step65:
    runFrontScT1_ex(N);
  END_STEP

  TRANSITION FROM Step65 TO Step66
    := not sensorSbT2_ex;
  END_TRANSITION

  STEP Step66:
  END_STEP

  TRANSITION FROM Step66 TO Step67
    := sensorScT1_ex;
  END_TRANSITION

  STEP Step67:
    runFrontScT2_ex(N);
  END_STEP

  TRANSITION FROM Step67 TO Step68
    := not sensorScT1_ex;
  END_TRANSITION

  STEP Step68:
  END_STEP

  TRANSITION FROM Step68 TO Step69
    := sensorScT2_ex;
  END_TRANSITION

  STEP Step69:
    runFrontMT1_ex(N);
  END_STEP

  TRANSITION FROM Step69 TO Step70
    := not sensorScT2_ex;
  END_TRANSITION

  STEP Step70:
  END_STEP

  TRANSITION FROM Step70 TO Step71
    := sensorMT1_ex;
  END_TRANSITION

  STEP Step71:
    runFrontMT2_ex(N);
  END_STEP

  TRANSITION FROM Step71 TO Step72
    := not sensorMT1_ex;
  END_TRANSITION

  STEP Step72:
  END_STEP

  TRANSITION FROM Step72 TO Step73
    := sensorMT2_ex;
  END_TRANSITION

  STEP Step73:
    runFrontCT1_ex(N);
  END_STEP

  TRANSITION FROM Step73 TO Step74
    := not sensorMT2_ex;
  END_TRANSITION

  STEP Step74:
  END_STEP

  TRANSITION FROM Step74 TO Step75
    := sensorCT1_ex;
  END_TRANSITION

  STEP Step75:
    sendDownCT2_ex(N);
  END_STEP

  TRANSITION FROM Step75 TO Step76
    := not sensorCT1_ex;
  END_TRANSITION

  STEP Step76:
  END_STEP

  TRANSITION FROM Step76 TO Step77
    := sensorCT2_ex;
  END_TRANSITION

  STEP Step77:
    runFrontCT4_ex(N);
  END_STEP

  TRANSITION FROM Step77 TO Step78
    := not sensorCT2_ex;
  END_TRANSITION

  STEP Step78:
  END_STEP

  TRANSITION FROM Step78 TO Step79
    := sensorCT4_ex;
  END_TRANSITION

  STEP Step79:
    runFrontCT5_ex(N);
  END_STEP

  TRANSITION FROM Step79 TO Step81
    := not sensorCT4_ex;
  END_TRANSITION

  STEP Step81:
  END_STEP

  TRANSITION FROM Step81 TO Step82
    := sensorCT5_ex;
  END_TRANSITION

  STEP Step82:
    pushToRollCT6_ex(N);
  END_STEP

  TRANSITION FROM Step82 TO Step83
    := not sensorCT5_ex;
  END_TRANSITION

  STEP Step83:
  END_STEP

  TRANSITION FROM Step83 TO Step84
    := sensorCT6_ex;
  END_TRANSITION

  STEP Step84:
  END_STEP

  TRANSITION FROM Step84 TO Step85
    := not sensorCT6_ex;
  END_TRANSITION

  STEP Step60:
    warehouseBusy(R);
  END_STEP

  TRANSITION FROM Step60 TO Step0
    := true;
  END_TRANSITION

END_PROGRAM


CONFIGURATION config
  VAR_GLOBAL
    pushUpCT6_ex : BOOL;
    sendRightDownCT2_ex : BOOL;
    sendRightUpCT8_ex : BOOL;
    runFrontCT7_ex : BOOL;
    receivePieceMT3_ex : BOOL;
    sendUpRightMT6_ex : BOOL;
    receivePieceMT4_ex : BOOL;
    sensorMT3_ex : BOOL;
    sensorMT4_ex : BOOL;
    runFrontMT3_ex : BOOL;
    runFrontMT4_ex : BOOL;
    takePiece : BOOL;
    pieceNum : INT;
    cell1Initial : INT;
    cell1Final : INT;
    cell2Initial : INT;
    cell2Final : INT;
    cell3Initial : INT;
    cell3Final : INT;
    receivePieceMT1_ex : BOOL;
    receivePieceMT2_ex : BOOL;
    waitForOp_ex : BOOL;
    ii : BOOL;
    pickPiece_ex : BOOL;
    releasePiece_ex : BOOL;
    X0Y0_ex : BOOL;
    X0Y1_ex : BOOL;
    X0Y2_ex : BOOL;
    X0Y3_ex : BOOL;
    X0Y4_ex : BOOL;
    X1Y0_ex : BOOL;
    X1Y1_ex : BOOL;
    X1Y2_ex : BOOL;
    X1Y3_ex : BOOL;
    X1Y4_ex : BOOL;
    warehouseBusy : BOOL;
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
    sendLeftDownSaT6_ex : BOOL;
    sendLeftDownSbT6_ex : BOOL;
    sendLeftDownScT6_ex : BOOL;
    sendLeftDownCT8_ex : BOOL;
    sensorAT1_ex : BOOL;
    sensorSaT1_ex : BOOL;
    sensorSaT2_ex : BOOL;
    sensorSaT3_ex : BOOL;
    sensorSaT4_ex : BOOL;
    sensorSaT5_ex : BOOL;
    sensorSaT6_ex : BOOL;
    sensorSaT7_ex : BOOL;
    sensorSbT1_ex : BOOL;
    sensorSbT2_ex : BOOL;
    sensorSbT3_ex : BOOL;
    sensorSbT4_ex : BOOL;
    sensorSbT5_ex : BOOL;
    sensorSbT6_ex : BOOL;
    sensorSbT7_ex : BOOL;
    sensorScT1_ex : BOOL;
    sensorScT2_ex : BOOL;
    sensorScT3_ex : BOOL;
    sensorScT4_ex : BOOL;
    sensorScT5_ex : BOOL;
    sensorScT6_ex : BOOL;
    sensorScT7_ex : BOOL;
    sensorMT1_ex : BOOL;
    sensorMT2_ex : BOOL;
    sensorCT1_ex : BOOL;
    sensorCT2_ex : BOOL;
    sensorCT3_ex : BOOL;
    sensorCT4_ex : BOOL;
    sensorCT5_ex : BOOL;
    sensorCT6_ex : BOOL;
    sensorAT2_ex : BOOL;
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
    runBackSaT6_ex : BOOL;
    runBackSaT7_ex : BOOL;
    runBackSbT6_ex : BOOL;
    runBackSbT7_ex : BOOL;
    runBackScT6_ex : BOOL;
    runBackScT7_ex : BOOL;
    sendUpSaT6_ex : BOOL;
    runFrontSbT3_ex : BOOL;
    runFrontSbT4_ex : BOOL;
    runFrontSbT5_ex : BOOL;
    runFrontSbT6_ex : BOOL;
    runFrontSaT3_ex : BOOL;
    runFrontSaT4_ex : BOOL;
    runFrontSaT5_ex : BOOL;
    runFrontScT3_ex : BOOL;
    runFrontScT4_ex : BOOL;
    runFrontScT5_ex : BOOL;
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
    toolPieceSaT3_ex : BOOL;
    toolPieceSaT5_ex : BOOL;
    toolPieceSbT3_ex : BOOL;
    toolPieceSbT5_ex : BOOL;
    toolPieceScT3_ex : BOOL;
    toolPieceScT5_ex : BOOL;
    readyToSendSaT3_ex : BOOL;
    readyToSendSaT5_ex : BOOL;
    readyToSendSbT5_ex : BOOL;
    readyToSendSbT3_ex : BOOL;
    readyToSendScT3_ex : BOOL;
    readyToSendScT5_ex : BOOL;
    putPieceInSignal_ex : BOOL;
    gantryBusy_ex : BOOL;
  END_VAR

  RESOURCE resource1 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : factoryFloorProgram;
    PROGRAM instance3 WITH task0 : gantryProgram;
    PROGRAM instance1 WITH task0 : unloadProgram;
    PROGRAM instance2 WITH task0 : transformProgram;
    PROGRAM instance4 WITH task0 : loadProgram;
  END_RESOURCE
END_CONFIGURATION
