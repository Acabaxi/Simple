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

FUNCTION_BLOCK Machine
  VAR_INPUT
    reachedSensor : BOOL;
  END_VAR
  VAR_OUTPUT
    useTool : BOOL;
  END_VAR
  VAR
    toolTimerOn : BOOL;
  END_VAR
  VAR_INPUT
    initialPiece : INT;
  END_VAR
  VAR_OUTPUT
    currentPiece : INT;
  END_VAR
  VAR_INPUT
    finalPiece : INT;
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
    TON0 : TON;
    TON1 : TON;
    asd : R_TRIG;
    TON2 : TON;
    TON3 : TON;
    TON4 : TON;
    TON5 : TON;
    TON6 : TON;
    TON7 : TON;
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
    TON1(IN := forwardTimerOn, PT := T#10s);
    TON0(IN := forwardTimerOn, PT := T#10s);
    TON2(IN := toolTimerOn, PT := T#5s);
    TON3(IN := toolTimerOn, PT := T#10s);
    TON4(IN := toolTimerOn, PT := T#5s);
    TON6(IN := toolTimerOn, PT := T#5s);
    TON5(IN := toolTimerOn, PT := T#10s);
    TON7(IN := toolTimerOn, PT := T#5s);
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

  TRANSITION FROM initLinearStep TO moveFront0
    := toolPiece;
  END_TRANSITION

  STEP moveFront0:
    forwardMotor(N);
  END_STEP

  TRANSITION FROM moveFront0 TO Step2
    := reachedSensor;
  END_TRANSITION

  STEP Step2:
  END_STEP

  TRANSITION FROM Step2 TO Step4
    := initialPiece = 1 OR initialPiece = 3 OR initialPiece = 5;
  END_TRANSITION

  STEP Step4:
    currentAsInitial(N);
  END_STEP

  ACTION currentAsInitial:
    currentPiece := initialPiece;
  END_ACTION

  TRANSITION FROM Step4 TO checkIfFinalA
    := true;
  END_TRANSITION

  STEP checkIfFinalA:
  END_STEP

  TRANSITION FROM checkIfFinalA TO Step11
    := currentPiece <> finalPiece;
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
    incrementToolNumber(N);
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
    incrementToolNumber(N);
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
  END_STEP

  TRANSITION FROM checkIfFinalA TO sendToNext
    := currentPiece = finalPiece;
  END_TRANSITION

  TRANSITION FROM Step2 TO Step7
    := initialPiece = 2 OR initialPiece = 4 OR initialPiece = 6;
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
    := currentPiece <> finalPiece;
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
    incrementToolNumber(N);
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
    incrementToolNumber(N);
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
    := currentPiece = finalPiece;
  END_TRANSITION

  TRANSITION FROM Step2 TO sendToNext
    := initialPiece = finalPiece;
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
    sensorSaT3_ex : BOOL;
    sensorSaT4_ex : BOOL;
    sensorSaT5_ex : BOOL;
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
    runFrontSaT3_ex : BOOL;
    runFrontSaT4_ex : BOOL;
    runFrontSaT5_ex : BOOL;
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
  END_VAR
  VAR
    SaT4 : LinearConveyor;
    SaT5 : Machine;
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
  ScT2(forwardSignal := runFrontScT2_ex, sendDownSignal := sendDownScT2_ex, sensorRotRight := sensorRotRightScT2, sensorRotLeft := sensorRotLeftScT2, frontNotBusy := MT1.isBusy, reachedSensorFront := sensorMT1, reachedSensor := sensorScT2);
  ScT1(reachedSensor := sensorScT1, forwardSignal := runFrontSbT1_ex, frontNotBusy := ScT2.isBusy, reachedSensorFront := sensorScT2);
  SbT2(forwardSignal := runFrontSbT2_ex, sendDownSignal := sendDownSbT2_ex, sensorRotRight := sensorRotRightSbT2, sensorRotLeft := sensorRotLeftSbT2, frontNotBusy := ScT1.isBusy, reachedSensorFront := sensorScT1, reachedSensor := sensorSbT2);
  SbT1(reachedSensor := sensorSbT1, forwardSignal := runFrontSbT1_ex, frontNotBusy := SbT2.isBusy, reachedSensorFront := sensorSbT2);
  AT2(reachedSensor := sensorAT2, backSignal := runBackAT2_ex);
  SaT7(reachedSensor := sensorSaT7, backSignal := runBackSaT7_ex, backNotBusy := AT2.isBusy, reachedSensorFront := sensorSaT6, reachedSensorBack := sensorAT2);
  SaT6(backSignal := runBackSaT6_ex, sendDownSignal := sendDownSaT6_ex, sendUpSignal := sendUpSaT6_ex, sensorRotRight := sensorRotRightSaT6, sensorRotLeft := sensorRotLeftSaT6, backNotBusy := SaT7.isBusy, reachedSensorFront := sensorSbT7, reachedSensor := sensorSaT6, reachedSensorBack := sensorSaT7);
  SaT5(reachedSensor := sensorSaT5, toolPiece := toolPieceSaT5_ex, toolSensor := toolSensorSaT5, sensorUp := toolUpSensorSaT5, sensorLeft := toolLeftSensorSaT5, sensorDown := toolDownSensorSaT5, sensorRight := toolRightSensorSaT5, forwardSignal := runFrontSaT5_ex, frontNotBusy := SaT6.isBusy, reachedSensorFront := sensorSaT6);
  SaT4(reachedSensor := sensorSaT4, forwardSignal := runFrontSaT4_ex, frontNotBusy := SaT5.isBusy, reachedSensorFront := sensorSaT5);
  SaT3(reachedSensor := sensorSaT3, initialPiece := 1, finalPiece := 7, toolPiece := toolPieceSaT3_ex, toolSensor := toolSensorSaT3, sensorUp := toolUpSensorSaT3, sensorLeft := toolLeftSensorSaT3, sensorDown := toolDownSensorSaT3, sensorRight := toolRightSensorSaT3, forwardSignal := runFrontSaT3_ex, frontNotBusy := SaT4.isBusy, reachedSensorFront := sensorSaT4);
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
  leftRotSaT2 := SaT2.leftRotMotor;
  leftRotCT2 := CT2.leftRotMotor;
  leftRotSbT2 := SbT2.leftRotMotor;
  leftRotScT2 := ScT2.leftRotMotor;
  forwardMT1 := MT1.forwardMotor;
  forwardScT1 := ScT1.forwardMotor;
  leftRotMT2 := MT2.leftRotMotor;
  sensorSaT3_ex := sensorSaT3;
  useToolSaT3 := SaT3.useTool;
  toolPlusSaT3 := SaT3.toolPlus;
  toolMinusSaT3 := SaT3.toolMinus;
  sensorCT4_ex := sensorCT4;
  PM1(reachedSensor := sensorPM1);
  CT4(rollBusy := PM1.hasPiece, pushSignal := pushToRollCT4_ex, forwardSignal := runFrontCT4_ex, reachedSensor := sensorCT4, reachedSensorFront := sensorCT5, sensorPushForward := sensorPushForwardCT4, sensorPushBack := sensorPushBackCT4);
  forwardCT4 := CT4.forwardMotor;
  zUpSaT3 := SaT3.motorUp;
  pushForwardCT4 := CT4.pushMotorForward;
  xLeftSaT3 := SaT3.motorLeft;
  pushBackCT4 := CT4.pushMotorBack;
  zDownSaT3 := SaT3.motorDown;
  xRightSaT3 := SaT3.motorRight;
  forwardSaT3 := SaT3.forwardMotor;
  sensorSaT4_ex := sensorSaT4;
  PM2(reachedSensor := sensorPM2);
  CT5(rollBusy := PM2.hasPiece, pushSignal := pushToRollCT5_ex, forwardSignal := runFrontCT5_ex, reachedSensor := sensorCT5, reachedSensorFront := sensorCT6, sensorPushForward := sensorPushForwardCT5, sensorPushBack := sensorPushBackCT5);
  forwardCT5 := CT5.forwardMotor;
  forwardSaT4 := SaT4.forwardMotor;
  sensorCT5_ex := sensorCT5;
  pushForwardCT5 := CT5.pushMotorForward;
  pushBackCT5 := CT5.pushMotorBack;
  sensorCT6_ex := sensorCT6;
  PM3(reachedSensor := sensorPM3);
  CT6(rollBusy := PM3.hasPiece, pushSignal := pushToRollCT6_ex, forwardSignal := runFrontCT6_ex, reachedSensor := sensorCT6, reachedSensorFront := sensorCT8, sensorPushForward := sensorPushForwardCT6, sensorPushBack := sensorPushBackCT6);
  forwardCT6 := CT6.forwardMotor;
  pushForwardCT6 := CT6.pushMotorForward;
  sensorSaT5_ex := sensorSaT5;
  toolPlusSaT5 := SaT5.toolPlus;
  toolMinusSaT5 := SaT5.toolMinus;
  zUpSaT5 := SaT5.motorUp;
  xLeftSaT5 := SaT5.motorLeft;
  zDownSaT5 := SaT5.motorDown;
  xRightSaT5 := SaT5.motorRight;
  forwardSaT5 := SaT5.forwardMotor;
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
  rightRotMT6 := MT6.rightRotMotor;
  backAT2 := AT2.backMotor;
  backSaT7 := SaT7.backMotor;
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

  INITIAL_STEP initialLoad:
  END_STEP

  TRANSITION FROM initialLoad TO putP3
    := pieceNum = 2;
  END_TRANSITION

  STEP putP3:
    P2(N);
  END_STEP

  ACTION P2:
    warehouseIn := 2;
  END_ACTION

  TRANSITION FROM putP3 TO Step2
    := sensorAT1;
  END_TRANSITION

  STEP Step2:
    resetWarehouse(N);
  END_STEP

  ACTION resetWarehouse:
    warehouseIn := 0;
  END_ACTION

  TRANSITION FROM Step2 TO Step0
    := not sensorAT1;
  END_TRANSITION

  STEP Step0:
  END_STEP

  TRANSITION FROM Step0 TO initialLoad
    := true;
  END_TRANSITION

  TRANSITION FROM initialLoad TO putP4
    := pieceNum = 3;
  END_TRANSITION

  STEP putP4:
    P3(N);
  END_STEP

  ACTION P3:
    warehouseIn := 3;
  END_ACTION

  TRANSITION FROM putP4 TO Step2
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad TO putP5
    := pieceNum = 4;
  END_TRANSITION

  STEP putP5:
    P4(N);
  END_STEP

  ACTION P4:
    warehouseIn := 4;
  END_ACTION

  TRANSITION FROM putP5 TO Step2
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad TO putP7
    := pieceNum = 6;
  END_TRANSITION

  STEP putP7:
    P6(N);
  END_STEP

  ACTION P6:
    warehouseIn := 6;
  END_ACTION

  TRANSITION FROM putP7 TO Step2
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad TO putP8
    := pieceNum = 7;
  END_TRANSITION

  STEP putP8:
    P7(N);
  END_STEP

  ACTION P7:
    warehouseIn := 7;
  END_ACTION

  TRANSITION FROM putP8 TO Step2
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad TO putP9
    := pieceNum = 8;
  END_TRANSITION

  STEP putP9:
    P8(N);
  END_STEP

  ACTION P8:
    warehouseIn := 8;
  END_ACTION

  TRANSITION FROM putP9 TO Step2
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad TO putP6
    := pieceNum = 5;
  END_TRANSITION

  STEP putP6:
    P5(N);
  END_STEP

  ACTION P5:
    warehouseIn := 5;
  END_ACTION

  TRANSITION FROM putP6 TO Step2
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad TO putP10
    := pieceNum = 9;
  END_TRANSITION

  STEP putP10:
    P9(N);
  END_STEP

  ACTION P9:
    warehouseIn := 9;
  END_ACTION

  TRANSITION FROM putP10 TO Step2
    := sensorAT1;
  END_TRANSITION

  TRANSITION FROM initialLoad TO putP2
    := pieceNum = 1;
  END_TRANSITION

  STEP putP2:
    P1(N);
  END_STEP

  ACTION P1:
    warehouseIn := 1;
  END_ACTION

  TRANSITION FROM putP2 TO Step2
    := sensorAT1;
  END_TRANSITION

END_FUNCTION_BLOCK

PROGRAM program1
  VAR
    warehouseIn AT %IW0.0.2.0 : INT;
  END_VAR
  VAR_EXTERNAL
    warehouseBusy : BOOL;
  END_VAR
  VAR
    sensorAT1 AT %IX0.0.0.0 : BOOL;
  END_VAR
  VAR
    initial : INT := 3;
  END_VAR
  VAR_EXTERNAL
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
    runFrontCT4_ex : BOOL;
    runFrontCT5_ex : BOOL;
    sendDownSaT2_ex : BOOL;
    toolPieceSaT3_ex : BOOL;
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
    sensorCT5_ex : BOOL;
    pushToRollCT4_ex : BOOL;
    pushToRollCT5_ex : BOOL;
    pushToRollCT6_ex : BOOL;
  END_VAR
  VAR
    removeFromWarehouse0 : removeFromWarehouse;
    PM : INT := 2;
    runUnload : BOOL;
  END_VAR

  INITIAL_STEP Step0:
  END_STEP

  TRANSITION FROM Step0 TO Step52
    := runUnload AND (not warehouseBusy);
  END_TRANSITION

  STEP Step52:
    warehouseBusy(S);
  END_STEP

  TRANSITION FROM Step52 TO Step26
    := PM = 1;
  END_TRANSITION

  STEP Step26:
    action0(N);
  END_STEP

  ACTION action0:
    removeFromWarehouse0(pieceNum := initial, sensorAT1 := sensorAT1);
    warehouseIn := removeFromWarehouse0.warehouseIn;
  END_ACTION

  TRANSITION FROM Step26 TO Step2
    := sensorAT1_ex;
  END_TRANSITION

  STEP Step2:
    runFrontSaT1_ex(N);
    runFrontAT1_ex(N);
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

  TRANSITION FROM Step1 TO Step1
    := true;
  END_TRANSITION

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
    action0(N);
  END_STEP

  TRANSITION FROM Step47 TO Step46
    := sensorAT1_ex;
  END_TRANSITION

  STEP Step46:
    runFrontSaT1_ex(N);
    runFrontAT1_ex(N);
  END_STEP

  TRANSITION FROM Step46 TO (Step28, Step30)
    := NOT sensorAT1_ex;
  END_TRANSITION

  STEP Step28:
  END_STEP

  TRANSITION FROM Step28 TO Step27
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

  TRANSITION FROM Step55 TO Step1
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
    action0(N);
  END_STEP

  TRANSITION FROM Step80 TO Step58
    := sensorAT1_ex;
  END_TRANSITION

  STEP Step58:
    runFrontSaT1_ex(N);
    runFrontAT1_ex(N);
  END_STEP

  TRANSITION FROM Step58 TO (Step57, Step60)
    := NOT sensorAT1_ex;
  END_TRANSITION

  STEP Step57:
  END_STEP

  TRANSITION FROM Step57 TO Step56
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

  TRANSITION FROM Step83 TO Step1
    := true;
  END_TRANSITION

  STEP Step60:
    warehouseBusy(R);
  END_STEP

  TRANSITION FROM Step60 TO Step0
    := true;
  END_TRANSITION

  INITIAL_STEP Step91:
  END_STEP

  TRANSITION FROM Step91 TO Step89
    := PM = 1;
  END_TRANSITION

  STEP Step89:
    action0(N);
  END_STEP

  TRANSITION FROM Step89 TO Step86
    := sensorAT1_ex;
  END_TRANSITION

  STEP Step86:
    runFrontSaT1_ex(N);
    runFrontAT1_ex(N);
  END_STEP

  TRANSITION FROM Step86 TO (Step85, Step88)
    := NOT sensorAT1_ex;
  END_TRANSITION

  STEP Step85:
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
  END_STEP

  TRANSITION FROM Step87 TO Step90
    := sensorSaT2_ex;
  END_TRANSITION

  STEP Step90:
    toolPieceSaT3_ex(N);
  END_STEP

  STEP Step88:
    warehouseBusy(R);
  END_STEP

  TRANSITION FROM Step88 TO Step91
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
    sensorSaT3_ex : BOOL;
    sensorSaT4_ex : BOOL;
    sensorSaT5_ex : BOOL;
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
    runFrontSaT3_ex : BOOL;
    runFrontSaT4_ex : BOOL;
    runFrontSaT5_ex : BOOL;
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
    toolPieceSaT3_ex : BOOL;
    toolPieceSaT5_ex : BOOL;
  END_VAR

  RESOURCE resource1 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance1 WITH task0 : program2;
    PROGRAM instance2 WITH task0 : program1;
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
