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
    reachedSensorBack : BOOL;
    reachedSensor : BOOL;
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
    := reachedSensorBack;
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
    := reachedSensorFront;
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
  END_VAR
  VAR_EXTERNAL
    ii : BOOL;
  END_VAR
  VAR
    sensorAT1 AT %IX0.0.0.0 : BOOL;
    sensorSaT1 AT %IX0.0.0.2 : BOOL;
    sensorSaT2 AT %IX0.0.0.3 : BOOL;
    sensorSbT1 AT %IX0.0.0.23 : BOOL;
    sensorRotRightSaT3 AT %IX0.0.0.5 : BOOL;
    sensorRotLeftSaT3 AT %IX0.0.0.4 : BOOL;
    forwardAT1 AT %QX0.0.1.1 : BOOL;
    forwardSaT1 AT %QX0.0.1.6 : BOOL;
    forwardSaT2 AT %QX0.0.1.8 : BOOL;
    forwardSbT1 AT %QX0.0.1.38 : BOOL;
    rightRotSaT3 AT %QX0.0.1.10 : BOOL;
    leftRotSaT3 AT %QX0.0.1.9 : BOOL;
    backAT1 AT %QX0.0.1.0 : BOOL;
    backSaT1 AT %QX0.0.1.5 : BOOL;
    backSaT2 AT %QX0.0.1.7 : BOOL;
  END_VAR
  VAR_EXTERNAL
    sensorAT1_ex : BOOL;
    sensorSaT1_ex : BOOL;
    sensorSaT2_ex : BOOL;
    sensorSbT1_ex : BOOL;
    runFrontAT1_ex : BOOL;
    runFrontSaT1_ex : BOOL;
    runFrontSaT2_ex : BOOL;
    runFrontSbT1_ex : BOOL;
    sendDownSaT2_ex : BOOL;
  END_VAR
  VAR
    SbT1 : LinearConveyor;
    NOT40_OUT : BOOL;
    NOT32_OUT : BOOL;
    NOT31_OUT : BOOL;
  END_VAR

  sensorSaT1_ex := sensorSaT1;
  sensorSaT2_ex := sensorSaT2;
  sensorAT1_ex := sensorAT1;
  sensorSbT1_ex := sensorSbT1;
  SbT1(forwardSignal := runFrontSbT1_ex, reachedSensor := sensorSbT1);
  NOT40_OUT := NOT(SbT1.isBusy);
  SaT2(forwardSignal := runFrontSaT2_ex, sendDownSignal := sendDownSaT2_ex, sensorRotRight := sensorRotRightSaT3, sensorRotLeft := sensorRotLeftSaT3, frontNotBusy := NOT40_OUT, reachedSensor := sensorSaT2);
  forwardSaT2 := SaT2.forwardMotor;
  forwardSbT1 := SbT1.forwardMotor;
  NOT32_OUT := NOT(SaT2.isBusy);
  SaT1(forwardSignal := runFrontSaT1_ex, frontNotBusy := NOT32_OUT, reachedSensorFront := sensorSaT2, reachedSensor := sensorSaT1);
  NOT31_OUT := NOT(SaT1.isBusy);
  AT1(forwardSignal := runFrontAT1_ex, frontNotBusy := NOT31_OUT, reachedSensorFront := sensorSaT1, reachedSensor := sensorAT1);
  forwardAT1 := AT1.forwardMotor;
  forwardSaT1 := SaT1.forwardMotor;
  rightRotSaT3 := SaT2.rightRotMotor;
  backAT1 := AT1.backMotor;
  backSaT1 := SaT1.backMotor;
  leftRotSaT3 := SaT2.leftRotMotor;
END_PROGRAM

PROGRAM program1
  VAR_EXTERNAL
    ii : BOOL;
    runFrontAT1_ex : BOOL;
    runFrontSaT1_ex : BOOL;
    runFrontSaT2_ex : BOOL;
    runFrontSbT1_ex : BOOL;
    sendDownSaT2_ex : BOOL;
    sensorAT1_ex : BOOL;
    sensorSaT1_ex : BOOL;
    sensorSaT2_ex : BOOL;
    sensorSbT1_ex : BOOL;
  END_VAR

  INITIAL_STEP Step0:
  END_STEP

  TRANSITION FROM Step0 TO Step1
    := true;
  END_TRANSITION

  STEP Step1:
    runFrontAT1_ex(N);
  END_STEP

  TRANSITION FROM Step1 TO (Step2, Step6)
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
    sendDownSaT2_ex(N);
  END_STEP

  TRANSITION FROM Step3 TO Step5
    := not sensorSaT1_ex;
  END_TRANSITION

  STEP Step5:
  END_STEP

  TRANSITION FROM Step5 TO Step0
    := false;
  END_TRANSITION

  STEP Step6:
  END_STEP

  TRANSITION FROM Step6 TO Step0
    := true;
  END_TRANSITION

END_PROGRAM


CONFIGURATION config
  VAR_GLOBAL
    ii : BOOL;
    runFrontAT1_ex : BOOL;
    runFrontSaT1_ex : BOOL;
    runFrontSaT2_ex : BOOL;
    runFrontSbT1_ex : BOOL;
    sendDownSaT2_ex : BOOL;
    sensorAT1_ex : BOOL;
    sensorSaT1_ex : BOOL;
    sensorSaT2_ex : BOOL;
    sensorSbT1_ex : BOOL;
  END_VAR

  RESOURCE resource1 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance1 WITH task0 : program1;
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
