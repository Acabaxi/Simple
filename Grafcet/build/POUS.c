void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->ADD10_OUT,0,retain)
  __INIT_VAR(data__->EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEL15_OUT,0,retain)
  __INIT_VAR(data__->AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->ADD10_OUT,)));
  __SET_VAR(data__->,SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (UINT)__GET_VAR(data__->ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->SEL15_OUT,));
  __SET_VAR(data__->,AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void GETBOOLSTRING_init__(GETBOOLSTRING *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->VALUE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
}

// Code part
void GETBOOLSTRING_body__(GETBOOLSTRING *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->VALUE,)) {
    __SET_VAR(data__->,CODE,,__STRING_LITERAL(4,"True"));
  } else {
    __SET_VAR(data__->,CODE,,__STRING_LITERAL(5,"False"));
  };

  goto __end;

__end:
  return;
} // GETBOOLSTRING_body__() 





void BUTTON_init__(BUTTON *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ID,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->BACK_ID,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->SELE_ID,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TOGGLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SET_STATE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATE_IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATE_OUT,__BOOL_LITERAL(FALSE),retain)
  PYTHON_EVAL_init__(&data__->INIT_COMMAND,retain);
  GETBOOLSTRING_init__(&data__->GETBUTTONSTATE,retain);
  PYTHON_EVAL_init__(&data__->SETSTATE_COMMAND,retain);
  PYTHON_POLL_init__(&data__->GETSTATE_COMMAND,retain);
  GETBOOLSTRING_init__(&data__->GETBUTTONTOGGLE,retain);
  __INIT_VAR(data__->CONCAT2_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->CONCAT22_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STRING_TO_INT25_OUT,0,retain)
  __INIT_VAR(data__->INT_TO_BOOL26_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AND31_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CONCAT7_OUT,__STRING_LITERAL(0,""),retain)
}

// Code part
void BUTTON_body__(BUTTON *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->GETBUTTONTOGGLE.,VALUE,,__GET_VAR(data__->TOGGLE,));
  GETBOOLSTRING_body__(&data__->GETBUTTONTOGGLE);
  __SET_VAR(data__->,CONCAT2_OUT,,CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)7,
    (STRING)__STRING_LITERAL(37,"createSVGUIControl(\"button\",back_id=\""),
    (STRING)__GET_VAR(data__->BACK_ID,),
    (STRING)__STRING_LITERAL(11,"\",sele_id=\""),
    (STRING)__GET_VAR(data__->SELE_ID,),
    (STRING)__STRING_LITERAL(9,"\",toggle="),
    (STRING)__GET_VAR(data__->GETBUTTONTOGGLE.CODE,),
    (STRING)__STRING_LITERAL(13,",active=True)")));
  __SET_VAR(data__->INIT_COMMAND.,TRIG,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->INIT_COMMAND.,CODE,,__GET_VAR(data__->CONCAT2_OUT,));
  PYTHON_EVAL_body__(&data__->INIT_COMMAND);
  __SET_VAR(data__->,ID,,__GET_VAR(data__->INIT_COMMAND.RESULT,));
  __SET_VAR(data__->,CONCAT22_OUT,,CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)3,
    (STRING)__STRING_LITERAL(12,"int(getAttr("),
    (STRING)__GET_VAR(data__->ID,),
    (STRING)__STRING_LITERAL(16,",\"state\",False))")));
  __SET_VAR(data__->GETSTATE_COMMAND.,TRIG,,__GET_VAR(data__->INIT_COMMAND.ACK,));
  __SET_VAR(data__->GETSTATE_COMMAND.,CODE,,__GET_VAR(data__->CONCAT22_OUT,));
  PYTHON_POLL_body__(&data__->GETSTATE_COMMAND);
  __SET_VAR(data__->,STRING_TO_INT25_OUT,,STRING_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->GETSTATE_COMMAND.RESULT,)));
  __SET_VAR(data__->,INT_TO_BOOL26_OUT,,INT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->STRING_TO_INT25_OUT,)));
  __SET_VAR(data__->,STATE_OUT,,__GET_VAR(data__->INT_TO_BOOL26_OUT,));
  __SET_VAR(data__->,AND31_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->INIT_COMMAND.ACK,),
    (BOOL)__GET_VAR(data__->SET_STATE,)));
  __SET_VAR(data__->GETBUTTONSTATE.,VALUE,,__GET_VAR(data__->STATE_IN,));
  GETBOOLSTRING_body__(&data__->GETBUTTONSTATE);
  __SET_VAR(data__->,CONCAT7_OUT,,CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)5,
    (STRING)__STRING_LITERAL(8,"setAttr("),
    (STRING)__GET_VAR(data__->ID,),
    (STRING)__STRING_LITERAL(9,",\"state\","),
    (STRING)__GET_VAR(data__->GETBUTTONSTATE.CODE,),
    (STRING)__STRING_LITERAL(1,")")));
  __SET_VAR(data__->SETSTATE_COMMAND.,TRIG,,__GET_VAR(data__->AND31_OUT,));
  __SET_VAR(data__->SETSTATE_COMMAND.,CODE,,__GET_VAR(data__->CONCAT7_OUT,));
  PYTHON_EVAL_body__(&data__->SETSTATE_COMMAND);

  goto __end;

__end:
  return;
} // BUTTON_body__() 





void LED_init__(LED *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ID,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->BACK_ID,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->SELE_ID,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE_IN,__BOOL_LITERAL(FALSE),retain)
  PYTHON_EVAL_init__(&data__->INIT_COMMAND,retain);
  PYTHON_POLL_init__(&data__->SETSTATE_COMMAND,retain);
  GETBOOLSTRING_init__(&data__->GETLEDSTATE,retain);
  __INIT_VAR(data__->CONCAT2_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->CONCAT7_OUT,__STRING_LITERAL(0,""),retain)
}

// Code part
void LED_body__(LED *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,CONCAT2_OUT,,CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)5,
    (STRING)__STRING_LITERAL(37,"createSVGUIControl(\"button\",back_id=\""),
    (STRING)__GET_VAR(data__->BACK_ID,),
    (STRING)__STRING_LITERAL(11,"\",sele_id=\""),
    (STRING)__GET_VAR(data__->SELE_ID,),
    (STRING)__STRING_LITERAL(27,"\",toggle=True,active=False)")));
  __SET_VAR(data__->INIT_COMMAND.,TRIG,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->INIT_COMMAND.,CODE,,__GET_VAR(data__->CONCAT2_OUT,));
  PYTHON_EVAL_body__(&data__->INIT_COMMAND);
  __SET_VAR(data__->,ID,,__GET_VAR(data__->INIT_COMMAND.RESULT,));
  __SET_VAR(data__->GETLEDSTATE.,VALUE,,__GET_VAR(data__->STATE_IN,));
  GETBOOLSTRING_body__(&data__->GETLEDSTATE);
  __SET_VAR(data__->,CONCAT7_OUT,,CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)5,
    (STRING)__STRING_LITERAL(8,"setAttr("),
    (STRING)__GET_VAR(data__->ID,),
    (STRING)__STRING_LITERAL(9,",\"state\","),
    (STRING)__GET_VAR(data__->GETLEDSTATE.CODE,),
    (STRING)__STRING_LITERAL(1,")")));
  __SET_VAR(data__->SETSTATE_COMMAND.,TRIG,,__GET_VAR(data__->INIT_COMMAND.ACK,));
  __SET_VAR(data__->SETSTATE_COMMAND.,CODE,,__GET_VAR(data__->CONCAT7_OUT,));
  PYTHON_POLL_body__(&data__->SETSTATE_COMMAND);

  goto __end;

__end:
  return;
} // LED_body__() 





void TEXTCTRL_init__(TEXTCTRL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ID,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->BACK_ID,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->SET_TEXT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TEXT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->SVGUI_TEXTCTRL,retain);
  PYTHON_EVAL_init__(&data__->SETSTATE_COMMAND,retain);
  __INIT_VAR(data__->CONCAT1_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->AND31_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CONCAT12_OUT,__STRING_LITERAL(0,""),retain)
}

// Code part
void TEXTCTRL_body__(TEXTCTRL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,CONCAT1_OUT,,CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)3,
    (STRING)__STRING_LITERAL(43,"createSVGUIControl(\"textControl\", back_id=\""),
    (STRING)__GET_VAR(data__->BACK_ID,),
    (STRING)__STRING_LITERAL(2,"\")")));
  __SET_VAR(data__->SVGUI_TEXTCTRL.,TRIG,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->SVGUI_TEXTCTRL.,CODE,,__GET_VAR(data__->CONCAT1_OUT,));
  PYTHON_EVAL_body__(&data__->SVGUI_TEXTCTRL);
  __SET_VAR(data__->,ID,,__GET_VAR(data__->SVGUI_TEXTCTRL.RESULT,));
  __SET_VAR(data__->,AND31_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->SVGUI_TEXTCTRL.ACK,),
    (BOOL)__GET_VAR(data__->SET_TEXT,)));
  __SET_VAR(data__->,CONCAT12_OUT,,CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)5,
    (STRING)__STRING_LITERAL(8,"setAttr("),
    (STRING)__GET_VAR(data__->ID,),
    (STRING)__STRING_LITERAL(9,",\"text\",\""),
    (STRING)__GET_VAR(data__->TEXT,),
    (STRING)__STRING_LITERAL(2,"\")")));
  __SET_VAR(data__->SETSTATE_COMMAND.,TRIG,,__GET_VAR(data__->AND31_OUT,));
  __SET_VAR(data__->SETSTATE_COMMAND.,CODE,,__GET_VAR(data__->CONCAT12_OUT,));
  PYTHON_EVAL_body__(&data__->SETSTATE_COMMAND);

  goto __end;

__end:
  return;
} // TEXTCTRL_body__() 





void LINEARCONVEYOR_init__(LINEARCONVEYOR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->REACHEDSENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDTIMERON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FRONTNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORFRONT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORBACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ISBUSY,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  UINT i;
  data__->__nb_steps = 9;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 5;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 12;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define INITLINEARSTEP __step_list[0]
#define __SFC_INITLINEARSTEP 0
#define MOVEFRONT __step_list[1]
#define __SFC_MOVEFRONT 1
#define NOTBUSYFRONT __step_list[2]
#define __SFC_NOTBUSYFRONT 2
#define MOVEFRONTSTEP __step_list[3]
#define __SFC_MOVEFRONTSTEP 3
#define TURNOFFFRONT __step_list[4]
#define __SFC_TURNOFFFRONT 4
#define MOVEBACK __step_list[5]
#define __SFC_MOVEBACK 5
#define NOTBUSYBACK __step_list[6]
#define __SFC_NOTBUSYBACK 6
#define MOVEBACKSTEP __step_list[7]
#define __SFC_MOVEBACKSTEP 7
#define TURNOFFBACK __step_list[8]
#define __SFC_TURNOFFBACK 8

// Actions definitions
#define __SFC_COMPUTE_FUNCTION_BLOCKS 0
#define __SFC_ISBUSY 1
#define __SFC_FORWARDMOTOR 2
#define __SFC_FORWARDTIMERON 3
#define __SFC_BACKMOTOR 4

// Code part
void LINEARCONVEYOR_body__(LINEARCONVEYOR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  INT i;
  TIME elapsed_time, current_time;

  // Calculate elapsed_time
  current_time = __CURRENT_TIME;
  elapsed_time = __time_sub(current_time, data__->__lasttick_time);
  data__->__lasttick_time = current_time;
  // Transitions initialization
  if (__DEBUG) {
    for (i = 0; i < data__->__nb_transitions; i++) {
      data__->__transition_list[i] = data__->__debug_transition_list[i];
    }
  }
  // Steps initialization
  for (i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i].prev_state = __GET_VAR(data__->__step_list[i].X);
    if (__GET_VAR(data__->__step_list[i].X)) {
      data__->__step_list[i].T.value = __time_add(data__->__step_list[i].T.value, elapsed_time);
    }
  }
  // Actions initialization
  for (i = 0; i < data__->__nb_actions; i++) {
    __SET_VAR(data__->,__action_list[i].state,,0);
    data__->__action_list[i].set = 0;
    data__->__action_list[i].reset = 0;
    if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].set_remaining_time = __time_sub(data__->__action_list[i].set_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].set = 1;
      }
    }
    if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].reset_remaining_time = __time_sub(data__->__action_list[i].reset_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].reset = 1;
      }
    }
  }

  // Transitions fire test
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[0],,__GET_VAR(data__->FORWARDSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->FORWARDSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->MOVEFRONT.X)) {
    __SET_VAR(data__->,__transition_list[1],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->NOTBUSYFRONT.X)) {
    __SET_VAR(data__->,__transition_list[2],,!(__GET_VAR(data__->FRONTNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,!(__GET_VAR(data__->FRONTNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->MOVEFRONTSTEP.X)) {
    __SET_VAR(data__->,__transition_list[3],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->TURNOFFFRONT.X)) {
    __SET_VAR(data__->,__transition_list[4],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->MOVEFRONTSTEP.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_VAR(data__->TON0.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->TON0.Q,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[6],,__GET_VAR(data__->BACKSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->BACKSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->MOVEBACK.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->NOTBUSYBACK.X)) {
    __SET_VAR(data__->,__transition_list[8],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP.X)) {
    __SET_VAR(data__->,__transition_list[9],,__GET_VAR(data__->REACHEDSENSORBACK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->REACHEDSENSORBACK,));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->TURNOFFBACK.X)) {
    __SET_VAR(data__->,__transition_list[10],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->TON1.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->TON1.Q,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,MOVEFRONT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,NOTBUSYFRONT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,MOVEFRONTSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,TURNOFFFRONT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,MOVEFRONTSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,MOVEBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,NOTBUSYBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,MOVEBACKSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,MOVEBACKSTEP.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,MOVEFRONT.X,,1);
    data__->MOVEFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,NOTBUSYFRONT.X,,1);
    data__->NOTBUSYFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,MOVEFRONTSTEP.X,,1);
    data__->MOVEFRONTSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,TURNOFFFRONT.X,,1);
    data__->TURNOFFFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,TURNOFFFRONT.X,,1);
    data__->TURNOFFFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,MOVEBACK.X,,1);
    data__->MOVEBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,NOTBUSYBACK.X,,1);
    data__->NOTBUSYBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,MOVEBACKSTEP.X,,1);
    data__->MOVEBACKSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,1);
    data__->TURNOFFBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,1);
    data__->TURNOFFBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // INITLINEARSTEP action associations
  {
    char active = __GET_VAR(data__->INITLINEARSTEP.X);
    char activated = active && !data__->INITLINEARSTEP.prev_state;
    char desactivated = !active && data__->INITLINEARSTEP.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].reset = 1;}

    if (active)       {data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].set = 1;}

  }

  // MOVEFRONT action associations
  {
    char active = __GET_VAR(data__->MOVEFRONT.X);
    char activated = active && !data__->MOVEFRONT.prev_state;
    char desactivated = !active && data__->MOVEFRONT.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDMOTOR,,0);};

  }

  // NOTBUSYFRONT action associations
  {
    char active = __GET_VAR(data__->NOTBUSYFRONT.X);
    char activated = active && !data__->NOTBUSYFRONT.prev_state;
    char desactivated = !active && data__->NOTBUSYFRONT.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // MOVEFRONTSTEP action associations
  {
    char active = __GET_VAR(data__->MOVEFRONTSTEP.X);
    char activated = active && !data__->MOVEFRONTSTEP.prev_state;
    char desactivated = !active && data__->MOVEFRONTSTEP.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDTIMERON,,0);};

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].set = 1;}

  }

  // TURNOFFFRONT action associations
  {
    char active = __GET_VAR(data__->TURNOFFFRONT.X);
    char activated = active && !data__->TURNOFFFRONT.prev_state;
    char desactivated = !active && data__->TURNOFFFRONT.prev_state;

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].reset = 1;}

  }

  // MOVEBACK action associations
  {
    char active = __GET_VAR(data__->MOVEBACK.X);
    char activated = active && !data__->MOVEBACK.prev_state;
    char desactivated = !active && data__->MOVEBACK.prev_state;

    if (active)       {__SET_VAR(data__->,BACKMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,BACKMOTOR,,0);};

  }

  // NOTBUSYBACK action associations
  {
    char active = __GET_VAR(data__->NOTBUSYBACK.X);
    char activated = active && !data__->NOTBUSYBACK.prev_state;
    char desactivated = !active && data__->NOTBUSYBACK.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // MOVEBACKSTEP action associations
  {
    char active = __GET_VAR(data__->MOVEBACKSTEP.X);
    char activated = active && !data__->MOVEBACKSTEP.prev_state;
    char desactivated = !active && data__->MOVEBACKSTEP.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDTIMERON,,0);};

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].set = 1;}

  }

  // TURNOFFBACK action associations
  {
    char active = __GET_VAR(data__->TURNOFFBACK.X);
    char activated = active && !data__->TURNOFFBACK.prev_state;
    char desactivated = !active && data__->TURNOFFBACK.prev_state;

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].reset = 1;}

  }


  // Actions state evaluation
  for (i = 0; i < data__->__nb_actions; i++) {
    if (data__->__action_list[i].set) {
      data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 1;
    }
    if (data__->__action_list[i].reset) {
      data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 0;
    }
    __SET_VAR(data__->,__action_list[i].state,,__GET_VAR(data__->__action_list[i].state) | data__->__action_list[i].stored);
  }

  // Actions execution
  if (data__->__action_list[__SFC_ISBUSY].reset) {
    __SET_VAR(data__->,ISBUSY,,0);
  }
  else if (data__->__action_list[__SFC_ISBUSY].set) {
    __SET_VAR(data__->,ISBUSY,,1);
  }
  if (data__->__action_list[__SFC_FORWARDMOTOR].reset) {
    __SET_VAR(data__->,FORWARDMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_FORWARDMOTOR].set) {
    __SET_VAR(data__->,FORWARDMOTOR,,1);
  }
  if (data__->__action_list[__SFC_FORWARDTIMERON].reset) {
    __SET_VAR(data__->,FORWARDTIMERON,,0);
  }
  else if (data__->__action_list[__SFC_FORWARDTIMERON].set) {
    __SET_VAR(data__->,FORWARDTIMERON,,1);
  }
  if (data__->__action_list[__SFC_BACKMOTOR].reset) {
    __SET_VAR(data__->,BACKMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_BACKMOTOR].set) {
    __SET_VAR(data__->,BACKMOTOR,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].state)) {
    __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->FORWARDTIMERON,));
    __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
    TON_body__(&data__->TON1);
    __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->FORWARDTIMERON,));
    __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
    TON_body__(&data__->TON0);
  }



  goto __end;

__end:
  return;
} // LINEARCONVEYOR_body__() 

// Steps undefinitions
#undef INITLINEARSTEP
#undef __SFC_INITLINEARSTEP
#undef MOVEFRONT
#undef __SFC_MOVEFRONT
#undef NOTBUSYFRONT
#undef __SFC_NOTBUSYFRONT
#undef MOVEFRONTSTEP
#undef __SFC_MOVEFRONTSTEP
#undef TURNOFFFRONT
#undef __SFC_TURNOFFFRONT
#undef MOVEBACK
#undef __SFC_MOVEBACK
#undef NOTBUSYBACK
#undef __SFC_NOTBUSYBACK
#undef MOVEBACKSTEP
#undef __SFC_MOVEBACKSTEP
#undef TURNOFFBACK
#undef __SFC_TURNOFFBACK

// Actions undefinitions
#undef __SFC_COMPUTE_FUNCTION_BLOCKS
#undef __SFC_ISBUSY
#undef __SFC_FORWARDMOTOR
#undef __SFC_FORWARDTIMERON
#undef __SFC_BACKMOTOR





void ROTARYCONVEYOR_init__(ROTARYCONVEYOR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->BACKSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDTIMERON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->READYTORECEIVE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENDDOWNSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENDLEFTDOWNSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORROTRIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORROTLEFT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FRONTNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOWNNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UPNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORFRONT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORDOWN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORBACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORUP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RIGHTROTMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LEFTROTMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ISBUSY,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  TON_init__(&data__->TON2,retain);
  TON_init__(&data__->TON3,retain);
  UINT i;
  data__->__nb_steps = 22;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 9;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 29;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define INITLINEARSTEP __step_list[0]
#define __SFC_INITLINEARSTEP 0
#define MOVEFRONT __step_list[1]
#define __SFC_MOVEFRONT 1
#define NOTBUSYFRONT __step_list[2]
#define __SFC_NOTBUSYFRONT 2
#define MOVEFRONTSTEP __step_list[3]
#define __SFC_MOVEFRONTSTEP 3
#define TURNOFFFRONT __step_list[4]
#define __SFC_TURNOFFFRONT 4
#define MOVEBACK __step_list[5]
#define __SFC_MOVEBACK 5
#define NOTBUSYBACK __step_list[6]
#define __SFC_NOTBUSYBACK 6
#define MOVEBACKSTEP __step_list[7]
#define __SFC_MOVEBACKSTEP 7
#define TURNOFFBACK __step_list[8]
#define __SFC_TURNOFFBACK 8
#define ROTATERIGHT __step_list[9]
#define __SFC_ROTATERIGHT 9
#define RIGHTROTATEED __step_list[10]
#define __SFC_RIGHTROTATEED 10
#define ROTATINGLEFT __step_list[11]
#define __SFC_ROTATINGLEFT 11
#define NOTBUSYBACK0 __step_list[12]
#define __SFC_NOTBUSYBACK0 12
#define MOVEBACKSTEP0 __step_list[13]
#define __SFC_MOVEBACKSTEP0 13
#define TURNOFFBACK0 __step_list[14]
#define __SFC_TURNOFFBACK0 14
#define MOVEFRONT0 __step_list[15]
#define __SFC_MOVEFRONT0 15
#define ROTATINGRIGHT __step_list[16]
#define __SFC_ROTATINGRIGHT 16
#define NOTBUSYFRONT0 __step_list[17]
#define __SFC_NOTBUSYFRONT0 17
#define MOVEFRONTSTEP0 __step_list[18]
#define __SFC_MOVEFRONTSTEP0 18
#define TURNOFFFRONT0 __step_list[19]
#define __SFC_TURNOFFFRONT0 19
#define RESETROTATE __step_list[20]
#define __SFC_RESETROTATE 20
#define RESETDONER __step_list[21]
#define __SFC_RESETDONER 21

// Actions definitions
#define __SFC_RESETPOSITION 0
#define __SFC_COMPUTE_FUNCTION_BLOCKS 1
#define __SFC_ISBUSY 2
#define __SFC_FORWARDMOTOR 3
#define __SFC_FORWARDTIMERON 4
#define __SFC_BACKMOTOR 5
#define __SFC_RIGHTROTMOTOR 6
#define __SFC_READYTORECEIVE 7
#define __SFC_LEFTROTMOTOR 8

// Code part
void ROTARYCONVEYOR_body__(ROTARYCONVEYOR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  INT i;
  TIME elapsed_time, current_time;

  // Calculate elapsed_time
  current_time = __CURRENT_TIME;
  elapsed_time = __time_sub(current_time, data__->__lasttick_time);
  data__->__lasttick_time = current_time;
  // Transitions initialization
  if (__DEBUG) {
    for (i = 0; i < data__->__nb_transitions; i++) {
      data__->__transition_list[i] = data__->__debug_transition_list[i];
    }
  }
  // Steps initialization
  for (i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i].prev_state = __GET_VAR(data__->__step_list[i].X);
    if (__GET_VAR(data__->__step_list[i].X)) {
      data__->__step_list[i].T.value = __time_add(data__->__step_list[i].T.value, elapsed_time);
    }
  }
  // Actions initialization
  for (i = 0; i < data__->__nb_actions; i++) {
    __SET_VAR(data__->,__action_list[i].state,,0);
    data__->__action_list[i].set = 0;
    data__->__action_list[i].reset = 0;
    if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].set_remaining_time = __time_sub(data__->__action_list[i].set_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].set = 1;
      }
    }
    if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].reset_remaining_time = __time_sub(data__->__action_list[i].reset_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].reset = 1;
      }
    }
  }

  // Transitions fire test
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[0],,__GET_VAR(data__->FORWARDSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->FORWARDSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->MOVEFRONT.X)) {
    __SET_VAR(data__->,__transition_list[1],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->NOTBUSYFRONT.X)) {
    __SET_VAR(data__->,__transition_list[2],,!(__GET_VAR(data__->FRONTNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,!(__GET_VAR(data__->FRONTNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->MOVEFRONTSTEP.X)) {
    __SET_VAR(data__->,__transition_list[3],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->TURNOFFFRONT.X)) {
    __SET_VAR(data__->,__transition_list[4],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->MOVEFRONTSTEP.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_VAR(data__->TON0.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->TON0.Q,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[6],,__GET_VAR(data__->BACKSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->BACKSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->MOVEBACK.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->NOTBUSYBACK.X)) {
    __SET_VAR(data__->,__transition_list[8],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP.X)) {
    __SET_VAR(data__->,__transition_list[9],,__GET_VAR(data__->REACHEDSENSORBACK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->REACHEDSENSORBACK,));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->TURNOFFBACK.X)) {
    __SET_VAR(data__->,__transition_list[10],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->TON1.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->TON1.Q,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[12],,__GET_VAR(data__->SENDLEFTDOWNSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->SENDLEFTDOWNSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->ROTATERIGHT.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_VAR(data__->SENSORROTRIGHT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->SENSORROTRIGHT,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->RIGHTROTATEED.X)) {
    __SET_VAR(data__->,__transition_list[14],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->ROTATINGLEFT.X)) {
    __SET_VAR(data__->,__transition_list[15],,__GET_VAR(data__->SENSORROTLEFT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->SENSORROTLEFT,));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->NOTBUSYBACK0.X)) {
    __SET_VAR(data__->,__transition_list[16],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[17],,__GET_VAR(data__->REACHEDSENSORBACK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->REACHEDSENSORBACK,));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->TURNOFFBACK0.X)) {
    __SET_VAR(data__->,__transition_list[18],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[19],,__GET_VAR(data__->TON3.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->TON3.Q,));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[20],,__GET_VAR(data__->SENDDOWNSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->SENDDOWNSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->MOVEFRONT0.X)) {
    __SET_VAR(data__->,__transition_list[21],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->ROTATINGRIGHT.X)) {
    __SET_VAR(data__->,__transition_list[22],,__GET_VAR(data__->SENSORROTRIGHT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->SENSORROTRIGHT,));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->NOTBUSYFRONT0.X)) {
    __SET_VAR(data__->,__transition_list[23],,!(__GET_VAR(data__->DOWNNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,!(__GET_VAR(data__->DOWNNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->MOVEFRONTSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[24],,__GET_VAR(data__->REACHEDSENSORDOWN,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->REACHEDSENSORDOWN,));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->TURNOFFFRONT0.X)) {
    __SET_VAR(data__->,__transition_list[25],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->RESETROTATE.X)) {
    __SET_VAR(data__->,__transition_list[26],,__GET_VAR(data__->SENSORROTLEFT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->SENSORROTLEFT,));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->RESETDONER.X)) {
    __SET_VAR(data__->,__transition_list[27],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->MOVEFRONTSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[28],,__GET_VAR(data__->TON2.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->TON2.Q,));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,MOVEFRONT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,NOTBUSYFRONT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,MOVEFRONTSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,TURNOFFFRONT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,MOVEFRONTSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,MOVEBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,NOTBUSYBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,MOVEBACKSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,MOVEBACKSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,ROTATERIGHT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,RIGHTROTATEED.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,ROTATINGLEFT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,NOTBUSYBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,MOVEBACKSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,TURNOFFBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,MOVEBACKSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,MOVEFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,ROTATINGRIGHT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,NOTBUSYFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,MOVEFRONTSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,TURNOFFFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,RESETROTATE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,RESETDONER.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,MOVEFRONTSTEP0.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,MOVEFRONT.X,,1);
    data__->MOVEFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,NOTBUSYFRONT.X,,1);
    data__->NOTBUSYFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,MOVEFRONTSTEP.X,,1);
    data__->MOVEFRONTSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,TURNOFFFRONT.X,,1);
    data__->TURNOFFFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,TURNOFFFRONT.X,,1);
    data__->TURNOFFFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,MOVEBACK.X,,1);
    data__->MOVEBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,NOTBUSYBACK.X,,1);
    data__->NOTBUSYBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,MOVEBACKSTEP.X,,1);
    data__->MOVEBACKSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,1);
    data__->TURNOFFBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,1);
    data__->TURNOFFBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,ROTATERIGHT.X,,1);
    data__->ROTATERIGHT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,RIGHTROTATEED.X,,1);
    data__->RIGHTROTATEED.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,ROTATINGLEFT.X,,1);
    data__->ROTATINGLEFT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,NOTBUSYBACK0.X,,1);
    data__->NOTBUSYBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,MOVEBACKSTEP0.X,,1);
    data__->MOVEBACKSTEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,TURNOFFBACK0.X,,1);
    data__->TURNOFFBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,TURNOFFBACK0.X,,1);
    data__->TURNOFFBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,MOVEFRONT0.X,,1);
    data__->MOVEFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,ROTATINGRIGHT.X,,1);
    data__->ROTATINGRIGHT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,NOTBUSYFRONT0.X,,1);
    data__->NOTBUSYFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,MOVEFRONTSTEP0.X,,1);
    data__->MOVEFRONTSTEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,TURNOFFFRONT0.X,,1);
    data__->TURNOFFFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,RESETROTATE.X,,1);
    data__->RESETROTATE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,RESETDONER.X,,1);
    data__->RESETDONER.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,TURNOFFFRONT0.X,,1);
    data__->TURNOFFFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // INITLINEARSTEP action associations
  {
    char active = __GET_VAR(data__->INITLINEARSTEP.X);
    char activated = active && !data__->INITLINEARSTEP.prev_state;
    char desactivated = !active && data__->INITLINEARSTEP.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].reset = 1;}

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_RESETPOSITION].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_RESETPOSITION].state,,0);};

    if (active)       {data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].set = 1;}

  }

  // MOVEFRONT action associations
  {
    char active = __GET_VAR(data__->MOVEFRONT.X);
    char activated = active && !data__->MOVEFRONT.prev_state;
    char desactivated = !active && data__->MOVEFRONT.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDMOTOR,,0);};

  }

  // NOTBUSYFRONT action associations
  {
    char active = __GET_VAR(data__->NOTBUSYFRONT.X);
    char activated = active && !data__->NOTBUSYFRONT.prev_state;
    char desactivated = !active && data__->NOTBUSYFRONT.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // MOVEFRONTSTEP action associations
  {
    char active = __GET_VAR(data__->MOVEFRONTSTEP.X);
    char activated = active && !data__->MOVEFRONTSTEP.prev_state;
    char desactivated = !active && data__->MOVEFRONTSTEP.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDTIMERON,,0);};

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].set = 1;}

  }

  // TURNOFFFRONT action associations
  {
    char active = __GET_VAR(data__->TURNOFFFRONT.X);
    char activated = active && !data__->TURNOFFFRONT.prev_state;
    char desactivated = !active && data__->TURNOFFFRONT.prev_state;

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].reset = 1;}

  }

  // MOVEBACK action associations
  {
    char active = __GET_VAR(data__->MOVEBACK.X);
    char activated = active && !data__->MOVEBACK.prev_state;
    char desactivated = !active && data__->MOVEBACK.prev_state;

    if (active)       {__SET_VAR(data__->,BACKMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,BACKMOTOR,,0);};

  }

  // NOTBUSYBACK action associations
  {
    char active = __GET_VAR(data__->NOTBUSYBACK.X);
    char activated = active && !data__->NOTBUSYBACK.prev_state;
    char desactivated = !active && data__->NOTBUSYBACK.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // MOVEBACKSTEP action associations
  {
    char active = __GET_VAR(data__->MOVEBACKSTEP.X);
    char activated = active && !data__->MOVEBACKSTEP.prev_state;
    char desactivated = !active && data__->MOVEBACKSTEP.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDTIMERON,,0);};

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].set = 1;}

  }

  // TURNOFFBACK action associations
  {
    char active = __GET_VAR(data__->TURNOFFBACK.X);
    char activated = active && !data__->TURNOFFBACK.prev_state;
    char desactivated = !active && data__->TURNOFFBACK.prev_state;

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].reset = 1;}

  }

  // ROTATERIGHT action associations
  {
    char active = __GET_VAR(data__->ROTATERIGHT.X);
    char activated = active && !data__->ROTATERIGHT.prev_state;
    char desactivated = !active && data__->ROTATERIGHT.prev_state;

    if (active)       {__SET_VAR(data__->,RIGHTROTMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,RIGHTROTMOTOR,,0);};

  }

  // RIGHTROTATEED action associations
  {
    char active = __GET_VAR(data__->RIGHTROTATEED.X);
    char activated = active && !data__->RIGHTROTATEED.prev_state;
    char desactivated = !active && data__->RIGHTROTATEED.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDMOTOR,,0);};

    if (active)       {__SET_VAR(data__->,READYTORECEIVE,,1);};
    if (desactivated) {__SET_VAR(data__->,READYTORECEIVE,,0);};

  }

  // ROTATINGLEFT action associations
  {
    char active = __GET_VAR(data__->ROTATINGLEFT.X);
    char activated = active && !data__->ROTATINGLEFT.prev_state;
    char desactivated = !active && data__->ROTATINGLEFT.prev_state;

    if (active)       {__SET_VAR(data__->,LEFTROTMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,LEFTROTMOTOR,,0);};

    if (active)       {__SET_VAR(data__->,ISBUSY,,1);};
    if (desactivated) {__SET_VAR(data__->,ISBUSY,,0);};

  }

  // MOVEBACKSTEP0 action associations
  {
    char active = __GET_VAR(data__->MOVEBACKSTEP0.X);
    char activated = active && !data__->MOVEBACKSTEP0.prev_state;
    char desactivated = !active && data__->MOVEBACKSTEP0.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDTIMERON,,0);};

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].set = 1;}

  }

  // TURNOFFBACK0 action associations
  {
    char active = __GET_VAR(data__->TURNOFFBACK0.X);
    char activated = active && !data__->TURNOFFBACK0.prev_state;
    char desactivated = !active && data__->TURNOFFBACK0.prev_state;

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].reset = 1;}

  }

  // MOVEFRONT0 action associations
  {
    char active = __GET_VAR(data__->MOVEFRONT0.X);
    char activated = active && !data__->MOVEFRONT0.prev_state;
    char desactivated = !active && data__->MOVEFRONT0.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDMOTOR,,0);};

  }

  // ROTATINGRIGHT action associations
  {
    char active = __GET_VAR(data__->ROTATINGRIGHT.X);
    char activated = active && !data__->ROTATINGRIGHT.prev_state;
    char desactivated = !active && data__->ROTATINGRIGHT.prev_state;

    if (active)       {__SET_VAR(data__->,RIGHTROTMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,RIGHTROTMOTOR,,0);};

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // MOVEFRONTSTEP0 action associations
  {
    char active = __GET_VAR(data__->MOVEFRONTSTEP0.X);
    char activated = active && !data__->MOVEFRONTSTEP0.prev_state;
    char desactivated = !active && data__->MOVEFRONTSTEP0.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDTIMERON,,0);};

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].set = 1;}

  }

  // TURNOFFFRONT0 action associations
  {
    char active = __GET_VAR(data__->TURNOFFFRONT0.X);
    char activated = active && !data__->TURNOFFFRONT0.prev_state;
    char desactivated = !active && data__->TURNOFFFRONT0.prev_state;

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].reset = 1;}

  }

  // RESETROTATE action associations
  {
    char active = __GET_VAR(data__->RESETROTATE.X);
    char activated = active && !data__->RESETROTATE.prev_state;
    char desactivated = !active && data__->RESETROTATE.prev_state;

    if (active)       {__SET_VAR(data__->,LEFTROTMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,LEFTROTMOTOR,,0);};

  }


  // Actions state evaluation
  for (i = 0; i < data__->__nb_actions; i++) {
    if (data__->__action_list[i].set) {
      data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 1;
    }
    if (data__->__action_list[i].reset) {
      data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 0;
    }
    __SET_VAR(data__->,__action_list[i].state,,__GET_VAR(data__->__action_list[i].state) | data__->__action_list[i].stored);
  }

  // Actions execution
  if (data__->__action_list[__SFC_ISBUSY].reset) {
    __SET_VAR(data__->,ISBUSY,,0);
  }
  else if (data__->__action_list[__SFC_ISBUSY].set) {
    __SET_VAR(data__->,ISBUSY,,1);
  }
  if (data__->__action_list[__SFC_FORWARDMOTOR].reset) {
    __SET_VAR(data__->,FORWARDMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_FORWARDMOTOR].set) {
    __SET_VAR(data__->,FORWARDMOTOR,,1);
  }
  if (data__->__action_list[__SFC_FORWARDTIMERON].reset) {
    __SET_VAR(data__->,FORWARDTIMERON,,0);
  }
  else if (data__->__action_list[__SFC_FORWARDTIMERON].set) {
    __SET_VAR(data__->,FORWARDTIMERON,,1);
  }
  if (data__->__action_list[__SFC_BACKMOTOR].reset) {
    __SET_VAR(data__->,BACKMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_BACKMOTOR].set) {
    __SET_VAR(data__->,BACKMOTOR,,1);
  }
  if (data__->__action_list[__SFC_RIGHTROTMOTOR].reset) {
    __SET_VAR(data__->,RIGHTROTMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_RIGHTROTMOTOR].set) {
    __SET_VAR(data__->,RIGHTROTMOTOR,,1);
  }
  if (data__->__action_list[__SFC_READYTORECEIVE].reset) {
    __SET_VAR(data__->,READYTORECEIVE,,0);
  }
  else if (data__->__action_list[__SFC_READYTORECEIVE].set) {
    __SET_VAR(data__->,READYTORECEIVE,,1);
  }
  if (data__->__action_list[__SFC_LEFTROTMOTOR].reset) {
    __SET_VAR(data__->,LEFTROTMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_LEFTROTMOTOR].set) {
    __SET_VAR(data__->,LEFTROTMOTOR,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_RESETPOSITION].state)) {
    __SET_VAR(data__->,LEFTROTMOTOR,,!(__GET_VAR(data__->SENSORROTLEFT,)));
  }

  if(__GET_VAR(data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].state)) {
    __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->FORWARDTIMERON,));
    __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
    TON_body__(&data__->TON1);
    __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->FORWARDTIMERON,));
    __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
    TON_body__(&data__->TON0);
    __SET_VAR(data__->TON3.,IN,,__GET_VAR(data__->FORWARDTIMERON,));
    __SET_VAR(data__->TON3.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
    TON_body__(&data__->TON3);
    __SET_VAR(data__->TON2.,IN,,__GET_VAR(data__->FORWARDTIMERON,));
    __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
    TON_body__(&data__->TON2);
  }



  goto __end;

__end:
  return;
} // ROTARYCONVEYOR_body__() 

// Steps undefinitions
#undef INITLINEARSTEP
#undef __SFC_INITLINEARSTEP
#undef MOVEFRONT
#undef __SFC_MOVEFRONT
#undef NOTBUSYFRONT
#undef __SFC_NOTBUSYFRONT
#undef MOVEFRONTSTEP
#undef __SFC_MOVEFRONTSTEP
#undef TURNOFFFRONT
#undef __SFC_TURNOFFFRONT
#undef MOVEBACK
#undef __SFC_MOVEBACK
#undef NOTBUSYBACK
#undef __SFC_NOTBUSYBACK
#undef MOVEBACKSTEP
#undef __SFC_MOVEBACKSTEP
#undef TURNOFFBACK
#undef __SFC_TURNOFFBACK
#undef ROTATERIGHT
#undef __SFC_ROTATERIGHT
#undef RIGHTROTATEED
#undef __SFC_RIGHTROTATEED
#undef ROTATINGLEFT
#undef __SFC_ROTATINGLEFT
#undef NOTBUSYBACK0
#undef __SFC_NOTBUSYBACK0
#undef MOVEBACKSTEP0
#undef __SFC_MOVEBACKSTEP0
#undef TURNOFFBACK0
#undef __SFC_TURNOFFBACK0
#undef MOVEFRONT0
#undef __SFC_MOVEFRONT0
#undef ROTATINGRIGHT
#undef __SFC_ROTATINGRIGHT
#undef NOTBUSYFRONT0
#undef __SFC_NOTBUSYFRONT0
#undef MOVEFRONTSTEP0
#undef __SFC_MOVEFRONTSTEP0
#undef TURNOFFFRONT0
#undef __SFC_TURNOFFFRONT0
#undef RESETROTATE
#undef __SFC_RESETROTATE
#undef RESETDONER
#undef __SFC_RESETDONER

// Actions undefinitions
#undef __SFC_RESETPOSITION
#undef __SFC_COMPUTE_FUNCTION_BLOCKS
#undef __SFC_ISBUSY
#undef __SFC_FORWARDMOTOR
#undef __SFC_FORWARDTIMERON
#undef __SFC_BACKMOTOR
#undef __SFC_RIGHTROTMOTOR
#undef __SFC_READYTORECEIVE
#undef __SFC_LEFTROTMOTOR





void WAREHOUSEINCONVEYOR_init__(WAREHOUSEINCONVEYOR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->REACHEDSENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WAREHOUSEBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDTIMERON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUTPIECEINSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUTPIECEIN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FRONTNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORFRONT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORBACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ISBUSY,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  UINT i;
  data__->__nb_steps = 12;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 6;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 16;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define INITLINEARSTEP __step_list[0]
#define __SFC_INITLINEARSTEP 0
#define MOVEFRONT __step_list[1]
#define __SFC_MOVEFRONT 1
#define NOTBUSYFRONT __step_list[2]
#define __SFC_NOTBUSYFRONT 2
#define MOVEFRONTSTEP __step_list[3]
#define __SFC_MOVEFRONTSTEP 3
#define TURNOFFFRONT __step_list[4]
#define __SFC_TURNOFFFRONT 4
#define MOVEBACK __step_list[5]
#define __SFC_MOVEBACK 5
#define NOTBUSYBACK __step_list[6]
#define __SFC_NOTBUSYBACK 6
#define MOVEBACKSTEP __step_list[7]
#define __SFC_MOVEBACKSTEP 7
#define TURNOFFBACK __step_list[8]
#define __SFC_TURNOFFBACK 8
#define MOVEBACK0 __step_list[9]
#define __SFC_MOVEBACK0 9
#define NOTBUSYBACK0 __step_list[10]
#define __SFC_NOTBUSYBACK0 10
#define STEP0 __step_list[11]
#define __SFC_STEP0 11

// Actions definitions
#define __SFC_COMPUTE_FUNCTION_BLOCKS 0
#define __SFC_ISBUSY 1
#define __SFC_FORWARDMOTOR 2
#define __SFC_FORWARDTIMERON 3
#define __SFC_BACKMOTOR 4
#define __SFC_PUTPIECEIN 5

// Code part
void WAREHOUSEINCONVEYOR_body__(WAREHOUSEINCONVEYOR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  INT i;
  TIME elapsed_time, current_time;

  // Calculate elapsed_time
  current_time = __CURRENT_TIME;
  elapsed_time = __time_sub(current_time, data__->__lasttick_time);
  data__->__lasttick_time = current_time;
  // Transitions initialization
  if (__DEBUG) {
    for (i = 0; i < data__->__nb_transitions; i++) {
      data__->__transition_list[i] = data__->__debug_transition_list[i];
    }
  }
  // Steps initialization
  for (i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i].prev_state = __GET_VAR(data__->__step_list[i].X);
    if (__GET_VAR(data__->__step_list[i].X)) {
      data__->__step_list[i].T.value = __time_add(data__->__step_list[i].T.value, elapsed_time);
    }
  }
  // Actions initialization
  for (i = 0; i < data__->__nb_actions; i++) {
    __SET_VAR(data__->,__action_list[i].state,,0);
    data__->__action_list[i].set = 0;
    data__->__action_list[i].reset = 0;
    if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].set_remaining_time = __time_sub(data__->__action_list[i].set_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].set = 1;
      }
    }
    if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].reset_remaining_time = __time_sub(data__->__action_list[i].reset_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].reset = 1;
      }
    }
  }

  // Transitions fire test
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[0],,__GET_VAR(data__->FORWARDSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->FORWARDSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->MOVEFRONT.X)) {
    __SET_VAR(data__->,__transition_list[1],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->NOTBUSYFRONT.X)) {
    __SET_VAR(data__->,__transition_list[2],,!(__GET_VAR(data__->FRONTNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,!(__GET_VAR(data__->FRONTNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->MOVEFRONTSTEP.X)) {
    __SET_VAR(data__->,__transition_list[3],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->TURNOFFFRONT.X)) {
    __SET_VAR(data__->,__transition_list[4],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->MOVEFRONTSTEP.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_VAR(data__->TON0.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->TON0.Q,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[6],,__GET_VAR(data__->BACKSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->BACKSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->MOVEBACK.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->NOTBUSYBACK.X)) {
    __SET_VAR(data__->,__transition_list[8],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP.X)) {
    __SET_VAR(data__->,__transition_list[9],,__GET_VAR(data__->REACHEDSENSORBACK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->REACHEDSENSORBACK,));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->TURNOFFBACK.X)) {
    __SET_VAR(data__->,__transition_list[10],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->TON1.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->TON1.Q,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[12],,__GET_VAR(data__->PUTPIECEINSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->PUTPIECEINSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->MOVEBACK0.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->NOTBUSYBACK0.X)) {
    __SET_VAR(data__->,__transition_list[14],,!(__GET_VAR(data__->WAREHOUSEBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,!(__GET_VAR(data__->WAREHOUSEBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->STEP0.X)) {
    __SET_VAR(data__->,__transition_list[15],,!(__GET_VAR(data__->REACHEDSENSOR,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,!(__GET_VAR(data__->REACHEDSENSOR,)));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,MOVEFRONT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,NOTBUSYFRONT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,MOVEFRONTSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,TURNOFFFRONT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,MOVEFRONTSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,MOVEBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,NOTBUSYBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,MOVEBACKSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,MOVEBACKSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,MOVEBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,NOTBUSYBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,MOVEFRONT.X,,1);
    data__->MOVEFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,NOTBUSYFRONT.X,,1);
    data__->NOTBUSYFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,MOVEFRONTSTEP.X,,1);
    data__->MOVEFRONTSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,TURNOFFFRONT.X,,1);
    data__->TURNOFFFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,TURNOFFFRONT.X,,1);
    data__->TURNOFFFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,MOVEBACK.X,,1);
    data__->MOVEBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,NOTBUSYBACK.X,,1);
    data__->NOTBUSYBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,MOVEBACKSTEP.X,,1);
    data__->MOVEBACKSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,1);
    data__->TURNOFFBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,1);
    data__->TURNOFFBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,MOVEBACK0.X,,1);
    data__->MOVEBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,NOTBUSYBACK0.X,,1);
    data__->NOTBUSYBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // INITLINEARSTEP action associations
  {
    char active = __GET_VAR(data__->INITLINEARSTEP.X);
    char activated = active && !data__->INITLINEARSTEP.prev_state;
    char desactivated = !active && data__->INITLINEARSTEP.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].reset = 1;}

    if (active)       {data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].set = 1;}

  }

  // MOVEFRONT action associations
  {
    char active = __GET_VAR(data__->MOVEFRONT.X);
    char activated = active && !data__->MOVEFRONT.prev_state;
    char desactivated = !active && data__->MOVEFRONT.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDMOTOR,,0);};

  }

  // NOTBUSYFRONT action associations
  {
    char active = __GET_VAR(data__->NOTBUSYFRONT.X);
    char activated = active && !data__->NOTBUSYFRONT.prev_state;
    char desactivated = !active && data__->NOTBUSYFRONT.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // MOVEFRONTSTEP action associations
  {
    char active = __GET_VAR(data__->MOVEFRONTSTEP.X);
    char activated = active && !data__->MOVEFRONTSTEP.prev_state;
    char desactivated = !active && data__->MOVEFRONTSTEP.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDTIMERON,,0);};

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].set = 1;}

  }

  // TURNOFFFRONT action associations
  {
    char active = __GET_VAR(data__->TURNOFFFRONT.X);
    char activated = active && !data__->TURNOFFFRONT.prev_state;
    char desactivated = !active && data__->TURNOFFFRONT.prev_state;

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].reset = 1;}

  }

  // MOVEBACK action associations
  {
    char active = __GET_VAR(data__->MOVEBACK.X);
    char activated = active && !data__->MOVEBACK.prev_state;
    char desactivated = !active && data__->MOVEBACK.prev_state;

    if (active)       {__SET_VAR(data__->,BACKMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,BACKMOTOR,,0);};

  }

  // NOTBUSYBACK action associations
  {
    char active = __GET_VAR(data__->NOTBUSYBACK.X);
    char activated = active && !data__->NOTBUSYBACK.prev_state;
    char desactivated = !active && data__->NOTBUSYBACK.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // MOVEBACKSTEP action associations
  {
    char active = __GET_VAR(data__->MOVEBACKSTEP.X);
    char activated = active && !data__->MOVEBACKSTEP.prev_state;
    char desactivated = !active && data__->MOVEBACKSTEP.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDTIMERON,,0);};

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].set = 1;}

  }

  // TURNOFFBACK action associations
  {
    char active = __GET_VAR(data__->TURNOFFBACK.X);
    char activated = active && !data__->TURNOFFBACK.prev_state;
    char desactivated = !active && data__->TURNOFFBACK.prev_state;

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].reset = 1;}

  }

  // MOVEBACK0 action associations
  {
    char active = __GET_VAR(data__->MOVEBACK0.X);
    char activated = active && !data__->MOVEBACK0.prev_state;
    char desactivated = !active && data__->MOVEBACK0.prev_state;

    if (active)       {__SET_VAR(data__->,BACKMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,BACKMOTOR,,0);};

  }

  // NOTBUSYBACK0 action associations
  {
    char active = __GET_VAR(data__->NOTBUSYBACK0.X);
    char activated = active && !data__->NOTBUSYBACK0.prev_state;
    char desactivated = !active && data__->NOTBUSYBACK0.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // STEP0 action associations
  {
    char active = __GET_VAR(data__->STEP0.X);
    char activated = active && !data__->STEP0.prev_state;
    char desactivated = !active && data__->STEP0.prev_state;

    if (active)       {__SET_VAR(data__->,PUTPIECEIN,,1);};
    if (desactivated) {__SET_VAR(data__->,PUTPIECEIN,,0);};

  }


  // Actions state evaluation
  for (i = 0; i < data__->__nb_actions; i++) {
    if (data__->__action_list[i].set) {
      data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 1;
    }
    if (data__->__action_list[i].reset) {
      data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 0;
    }
    __SET_VAR(data__->,__action_list[i].state,,__GET_VAR(data__->__action_list[i].state) | data__->__action_list[i].stored);
  }

  // Actions execution
  if (data__->__action_list[__SFC_ISBUSY].reset) {
    __SET_VAR(data__->,ISBUSY,,0);
  }
  else if (data__->__action_list[__SFC_ISBUSY].set) {
    __SET_VAR(data__->,ISBUSY,,1);
  }
  if (data__->__action_list[__SFC_FORWARDMOTOR].reset) {
    __SET_VAR(data__->,FORWARDMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_FORWARDMOTOR].set) {
    __SET_VAR(data__->,FORWARDMOTOR,,1);
  }
  if (data__->__action_list[__SFC_FORWARDTIMERON].reset) {
    __SET_VAR(data__->,FORWARDTIMERON,,0);
  }
  else if (data__->__action_list[__SFC_FORWARDTIMERON].set) {
    __SET_VAR(data__->,FORWARDTIMERON,,1);
  }
  if (data__->__action_list[__SFC_BACKMOTOR].reset) {
    __SET_VAR(data__->,BACKMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_BACKMOTOR].set) {
    __SET_VAR(data__->,BACKMOTOR,,1);
  }
  if (data__->__action_list[__SFC_PUTPIECEIN].reset) {
    __SET_VAR(data__->,PUTPIECEIN,,0);
  }
  else if (data__->__action_list[__SFC_PUTPIECEIN].set) {
    __SET_VAR(data__->,PUTPIECEIN,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].state)) {
    __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->FORWARDTIMERON,));
    __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
    TON_body__(&data__->TON1);
    __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->FORWARDTIMERON,));
    __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
    TON_body__(&data__->TON0);
  }



  goto __end;

__end:
  return;
} // WAREHOUSEINCONVEYOR_body__() 

// Steps undefinitions
#undef INITLINEARSTEP
#undef __SFC_INITLINEARSTEP
#undef MOVEFRONT
#undef __SFC_MOVEFRONT
#undef NOTBUSYFRONT
#undef __SFC_NOTBUSYFRONT
#undef MOVEFRONTSTEP
#undef __SFC_MOVEFRONTSTEP
#undef TURNOFFFRONT
#undef __SFC_TURNOFFFRONT
#undef MOVEBACK
#undef __SFC_MOVEBACK
#undef NOTBUSYBACK
#undef __SFC_NOTBUSYBACK
#undef MOVEBACKSTEP
#undef __SFC_MOVEBACKSTEP
#undef TURNOFFBACK
#undef __SFC_TURNOFFBACK
#undef MOVEBACK0
#undef __SFC_MOVEBACK0
#undef NOTBUSYBACK0
#undef __SFC_NOTBUSYBACK0
#undef STEP0
#undef __SFC_STEP0

// Actions undefinitions
#undef __SFC_COMPUTE_FUNCTION_BLOCKS
#undef __SFC_ISBUSY
#undef __SFC_FORWARDMOTOR
#undef __SFC_FORWARDTIMERON
#undef __SFC_BACKMOTOR
#undef __SFC_PUTPIECEIN





void PUSHER_init__(PUSHER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  TON_init__(&data__->TON1,retain);
  TON_init__(&data__->TON0,retain);
  __INIT_VAR(data__->FORWARDTIMERON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUSHMOTORFORWARD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUSHMOTORBACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ISBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ROLLBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUSHSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORBACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORFRONT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORPUSHFORWARD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORPUSHBACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FRONTNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  UINT i;
  data__->__nb_steps = 13;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 7;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 17;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define INITLINEARSTEP __step_list[0]
#define __SFC_INITLINEARSTEP 0
#define MOVEFRONT0 __step_list[1]
#define __SFC_MOVEFRONT0 1
#define NOTBUSYFRONT0 __step_list[2]
#define __SFC_NOTBUSYFRONT0 2
#define MOVEFRONTSTEP0 __step_list[3]
#define __SFC_MOVEFRONTSTEP0 3
#define TURNOFFFRONT0 __step_list[4]
#define __SFC_TURNOFFFRONT0 4
#define MOVEBACK0 __step_list[5]
#define __SFC_MOVEBACK0 5
#define NOTBUSYBACK0 __step_list[6]
#define __SFC_NOTBUSYBACK0 6
#define MOVEBACKSTEP0 __step_list[7]
#define __SFC_MOVEBACKSTEP0 7
#define TURNOFFBACK0 __step_list[8]
#define __SFC_TURNOFFBACK0 8
#define PUSHROLL __step_list[9]
#define __SFC_PUSHROLL 9
#define NOTBUSYFRONT1 __step_list[10]
#define __SFC_NOTBUSYFRONT1 10
#define PUSHTOROLL __step_list[11]
#define __SFC_PUSHTOROLL 11
#define RETRACTPUSHER __step_list[12]
#define __SFC_RETRACTPUSHER 12

// Actions definitions
#define __SFC_COMPUTE_FUNCTION_BLOCKS 0
#define __SFC_ISBUSY 1
#define __SFC_FORWARDMOTOR 2
#define __SFC_FORWARDTIMERON 3
#define __SFC_BACKMOTOR 4
#define __SFC_PUSHMOTORFORWARD 5
#define __SFC_PUSHMOTORBACK 6

// Code part
void PUSHER_body__(PUSHER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  INT i;
  TIME elapsed_time, current_time;

  // Calculate elapsed_time
  current_time = __CURRENT_TIME;
  elapsed_time = __time_sub(current_time, data__->__lasttick_time);
  data__->__lasttick_time = current_time;
  // Transitions initialization
  if (__DEBUG) {
    for (i = 0; i < data__->__nb_transitions; i++) {
      data__->__transition_list[i] = data__->__debug_transition_list[i];
    }
  }
  // Steps initialization
  for (i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i].prev_state = __GET_VAR(data__->__step_list[i].X);
    if (__GET_VAR(data__->__step_list[i].X)) {
      data__->__step_list[i].T.value = __time_add(data__->__step_list[i].T.value, elapsed_time);
    }
  }
  // Actions initialization
  for (i = 0; i < data__->__nb_actions; i++) {
    __SET_VAR(data__->,__action_list[i].state,,0);
    data__->__action_list[i].set = 0;
    data__->__action_list[i].reset = 0;
    if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].set_remaining_time = __time_sub(data__->__action_list[i].set_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].set = 1;
      }
    }
    if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].reset_remaining_time = __time_sub(data__->__action_list[i].reset_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].reset = 1;
      }
    }
  }

  // Transitions fire test
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[0],,__GET_VAR(data__->FORWARDSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->FORWARDSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->MOVEFRONT0.X)) {
    __SET_VAR(data__->,__transition_list[1],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->NOTBUSYFRONT0.X)) {
    __SET_VAR(data__->,__transition_list[2],,!(__GET_VAR(data__->FRONTNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,!(__GET_VAR(data__->FRONTNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->MOVEFRONTSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[3],,__GET_VAR(data__->TON0.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->TON0.Q,));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->TURNOFFFRONT0.X)) {
    __SET_VAR(data__->,__transition_list[4],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->MOVEFRONTSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[6],,__GET_VAR(data__->BACKSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->BACKSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->MOVEBACK0.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->NOTBUSYBACK0.X)) {
    __SET_VAR(data__->,__transition_list[8],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[9],,__GET_VAR(data__->TON1.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->TON1.Q,));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->TURNOFFBACK0.X)) {
    __SET_VAR(data__->,__transition_list[10],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->REACHEDSENSORBACK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->REACHEDSENSORBACK,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[12],,__GET_VAR(data__->PUSHSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->PUSHSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->PUSHROLL.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->NOTBUSYFRONT1.X)) {
    __SET_VAR(data__->,__transition_list[14],,!(__GET_VAR(data__->ROLLBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,!(__GET_VAR(data__->ROLLBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->PUSHTOROLL.X)) {
    __SET_VAR(data__->,__transition_list[15],,__GET_VAR(data__->SENSORPUSHFORWARD,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->SENSORPUSHFORWARD,));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->RETRACTPUSHER.X)) {
    __SET_VAR(data__->,__transition_list[16],,__GET_VAR(data__->SENSORPUSHBACK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->SENSORPUSHBACK,));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,MOVEFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,NOTBUSYFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,MOVEFRONTSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,TURNOFFFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,MOVEFRONTSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,MOVEBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,NOTBUSYBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,MOVEBACKSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,TURNOFFBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,MOVEBACKSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,PUSHROLL.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,NOTBUSYFRONT1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,PUSHTOROLL.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,RETRACTPUSHER.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,MOVEFRONT0.X,,1);
    data__->MOVEFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,NOTBUSYFRONT0.X,,1);
    data__->NOTBUSYFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,MOVEFRONTSTEP0.X,,1);
    data__->MOVEFRONTSTEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,TURNOFFFRONT0.X,,1);
    data__->TURNOFFFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,TURNOFFFRONT0.X,,1);
    data__->TURNOFFFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,MOVEBACK0.X,,1);
    data__->MOVEBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,NOTBUSYBACK0.X,,1);
    data__->NOTBUSYBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,MOVEBACKSTEP0.X,,1);
    data__->MOVEBACKSTEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,TURNOFFBACK0.X,,1);
    data__->TURNOFFBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,TURNOFFBACK0.X,,1);
    data__->TURNOFFBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,PUSHROLL.X,,1);
    data__->PUSHROLL.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,NOTBUSYFRONT1.X,,1);
    data__->NOTBUSYFRONT1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,PUSHTOROLL.X,,1);
    data__->PUSHTOROLL.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,RETRACTPUSHER.X,,1);
    data__->RETRACTPUSHER.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // INITLINEARSTEP action associations
  {
    char active = __GET_VAR(data__->INITLINEARSTEP.X);
    char activated = active && !data__->INITLINEARSTEP.prev_state;
    char desactivated = !active && data__->INITLINEARSTEP.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].reset = 1;}

    if (active)       {data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].set = 1;}

  }

  // MOVEFRONT0 action associations
  {
    char active = __GET_VAR(data__->MOVEFRONT0.X);
    char activated = active && !data__->MOVEFRONT0.prev_state;
    char desactivated = !active && data__->MOVEFRONT0.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDMOTOR,,0);};

  }

  // NOTBUSYFRONT0 action associations
  {
    char active = __GET_VAR(data__->NOTBUSYFRONT0.X);
    char activated = active && !data__->NOTBUSYFRONT0.prev_state;
    char desactivated = !active && data__->NOTBUSYFRONT0.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // MOVEFRONTSTEP0 action associations
  {
    char active = __GET_VAR(data__->MOVEFRONTSTEP0.X);
    char activated = active && !data__->MOVEFRONTSTEP0.prev_state;
    char desactivated = !active && data__->MOVEFRONTSTEP0.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDTIMERON,,0);};

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].set = 1;}

  }

  // TURNOFFFRONT0 action associations
  {
    char active = __GET_VAR(data__->TURNOFFFRONT0.X);
    char activated = active && !data__->TURNOFFFRONT0.prev_state;
    char desactivated = !active && data__->TURNOFFFRONT0.prev_state;

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].reset = 1;}

  }

  // MOVEBACK0 action associations
  {
    char active = __GET_VAR(data__->MOVEBACK0.X);
    char activated = active && !data__->MOVEBACK0.prev_state;
    char desactivated = !active && data__->MOVEBACK0.prev_state;

    if (active)       {__SET_VAR(data__->,BACKMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,BACKMOTOR,,0);};

  }

  // NOTBUSYBACK0 action associations
  {
    char active = __GET_VAR(data__->NOTBUSYBACK0.X);
    char activated = active && !data__->NOTBUSYBACK0.prev_state;
    char desactivated = !active && data__->NOTBUSYBACK0.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // MOVEBACKSTEP0 action associations
  {
    char active = __GET_VAR(data__->MOVEBACKSTEP0.X);
    char activated = active && !data__->MOVEBACKSTEP0.prev_state;
    char desactivated = !active && data__->MOVEBACKSTEP0.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDTIMERON,,0);};

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].set = 1;}

  }

  // TURNOFFBACK0 action associations
  {
    char active = __GET_VAR(data__->TURNOFFBACK0.X);
    char activated = active && !data__->TURNOFFBACK0.prev_state;
    char desactivated = !active && data__->TURNOFFBACK0.prev_state;

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].reset = 1;}

  }

  // PUSHROLL action associations
  {
    char active = __GET_VAR(data__->PUSHROLL.X);
    char activated = active && !data__->PUSHROLL.prev_state;
    char desactivated = !active && data__->PUSHROLL.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDMOTOR,,0);};

  }

  // NOTBUSYFRONT1 action associations
  {
    char active = __GET_VAR(data__->NOTBUSYFRONT1.X);
    char activated = active && !data__->NOTBUSYFRONT1.prev_state;
    char desactivated = !active && data__->NOTBUSYFRONT1.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // PUSHTOROLL action associations
  {
    char active = __GET_VAR(data__->PUSHTOROLL.X);
    char activated = active && !data__->PUSHTOROLL.prev_state;
    char desactivated = !active && data__->PUSHTOROLL.prev_state;

    if (active)       {__SET_VAR(data__->,PUSHMOTORFORWARD,,1);};
    if (desactivated) {__SET_VAR(data__->,PUSHMOTORFORWARD,,0);};

  }

  // RETRACTPUSHER action associations
  {
    char active = __GET_VAR(data__->RETRACTPUSHER.X);
    char activated = active && !data__->RETRACTPUSHER.prev_state;
    char desactivated = !active && data__->RETRACTPUSHER.prev_state;

    if (active)       {__SET_VAR(data__->,PUSHMOTORBACK,,1);};
    if (desactivated) {__SET_VAR(data__->,PUSHMOTORBACK,,0);};

  }


  // Actions state evaluation
  for (i = 0; i < data__->__nb_actions; i++) {
    if (data__->__action_list[i].set) {
      data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 1;
    }
    if (data__->__action_list[i].reset) {
      data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 0;
    }
    __SET_VAR(data__->,__action_list[i].state,,__GET_VAR(data__->__action_list[i].state) | data__->__action_list[i].stored);
  }

  // Actions execution
  if (data__->__action_list[__SFC_ISBUSY].reset) {
    __SET_VAR(data__->,ISBUSY,,0);
  }
  else if (data__->__action_list[__SFC_ISBUSY].set) {
    __SET_VAR(data__->,ISBUSY,,1);
  }
  if (data__->__action_list[__SFC_FORWARDMOTOR].reset) {
    __SET_VAR(data__->,FORWARDMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_FORWARDMOTOR].set) {
    __SET_VAR(data__->,FORWARDMOTOR,,1);
  }
  if (data__->__action_list[__SFC_FORWARDTIMERON].reset) {
    __SET_VAR(data__->,FORWARDTIMERON,,0);
  }
  else if (data__->__action_list[__SFC_FORWARDTIMERON].set) {
    __SET_VAR(data__->,FORWARDTIMERON,,1);
  }
  if (data__->__action_list[__SFC_BACKMOTOR].reset) {
    __SET_VAR(data__->,BACKMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_BACKMOTOR].set) {
    __SET_VAR(data__->,BACKMOTOR,,1);
  }
  if (data__->__action_list[__SFC_PUSHMOTORFORWARD].reset) {
    __SET_VAR(data__->,PUSHMOTORFORWARD,,0);
  }
  else if (data__->__action_list[__SFC_PUSHMOTORFORWARD].set) {
    __SET_VAR(data__->,PUSHMOTORFORWARD,,1);
  }
  if (data__->__action_list[__SFC_PUSHMOTORBACK].reset) {
    __SET_VAR(data__->,PUSHMOTORBACK,,0);
  }
  else if (data__->__action_list[__SFC_PUSHMOTORBACK].set) {
    __SET_VAR(data__->,PUSHMOTORBACK,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].state)) {
    __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->FORWARDTIMERON,));
    __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
    TON_body__(&data__->TON0);
    __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->FORWARDTIMERON,));
    __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
    TON_body__(&data__->TON1);
  }



  goto __end;

__end:
  return;
} // PUSHER_body__() 

// Steps undefinitions
#undef INITLINEARSTEP
#undef __SFC_INITLINEARSTEP
#undef MOVEFRONT0
#undef __SFC_MOVEFRONT0
#undef NOTBUSYFRONT0
#undef __SFC_NOTBUSYFRONT0
#undef MOVEFRONTSTEP0
#undef __SFC_MOVEFRONTSTEP0
#undef TURNOFFFRONT0
#undef __SFC_TURNOFFFRONT0
#undef MOVEBACK0
#undef __SFC_MOVEBACK0
#undef NOTBUSYBACK0
#undef __SFC_NOTBUSYBACK0
#undef MOVEBACKSTEP0
#undef __SFC_MOVEBACKSTEP0
#undef TURNOFFBACK0
#undef __SFC_TURNOFFBACK0
#undef PUSHROLL
#undef __SFC_PUSHROLL
#undef NOTBUSYFRONT1
#undef __SFC_NOTBUSYFRONT1
#undef PUSHTOROLL
#undef __SFC_PUSHTOROLL
#undef RETRACTPUSHER
#undef __SFC_RETRACTPUSHER

// Actions undefinitions
#undef __SFC_COMPUTE_FUNCTION_BLOCKS
#undef __SFC_ISBUSY
#undef __SFC_FORWARDMOTOR
#undef __SFC_FORWARDTIMERON
#undef __SFC_BACKMOTOR
#undef __SFC_PUSHMOTORFORWARD
#undef __SFC_PUSHMOTORBACK





void ROLL_init__(ROLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->REACHEDSENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->HASPIECE,__BOOL_LITERAL(FALSE),retain)
  UINT i;
  data__->__nb_steps = 2;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 1;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 2;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define STEP0 __step_list[0]
#define __SFC_STEP0 0
#define STEP1 __step_list[1]
#define __SFC_STEP1 1

// Actions definitions
#define __SFC_HASPIECE 0

// Code part
void ROLL_body__(ROLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  INT i;
  TIME elapsed_time, current_time;

  // Calculate elapsed_time
  current_time = __CURRENT_TIME;
  elapsed_time = __time_sub(current_time, data__->__lasttick_time);
  data__->__lasttick_time = current_time;
  // Transitions initialization
  if (__DEBUG) {
    for (i = 0; i < data__->__nb_transitions; i++) {
      data__->__transition_list[i] = data__->__debug_transition_list[i];
    }
  }
  // Steps initialization
  for (i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i].prev_state = __GET_VAR(data__->__step_list[i].X);
    if (__GET_VAR(data__->__step_list[i].X)) {
      data__->__step_list[i].T.value = __time_add(data__->__step_list[i].T.value, elapsed_time);
    }
  }
  // Actions initialization
  for (i = 0; i < data__->__nb_actions; i++) {
    __SET_VAR(data__->,__action_list[i].state,,0);
    data__->__action_list[i].set = 0;
    data__->__action_list[i].reset = 0;
    if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].set_remaining_time = __time_sub(data__->__action_list[i].set_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].set = 1;
      }
    }
    if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].reset_remaining_time = __time_sub(data__->__action_list[i].reset_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].reset = 1;
      }
    }
  }

  // Transitions fire test
  if (__GET_VAR(data__->STEP0.X)) {
    __SET_VAR(data__->,__transition_list[0],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
    __SET_VAR(data__->,__transition_list[1],,!(__GET_VAR(data__->REACHEDSENSOR,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,!(__GET_VAR(data__->REACHEDSENSOR,)));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP1.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // STEP1 action associations
  {
    char active = __GET_VAR(data__->STEP1.X);
    char activated = active && !data__->STEP1.prev_state;
    char desactivated = !active && data__->STEP1.prev_state;

    if (active)       {__SET_VAR(data__->,HASPIECE,,1);};
    if (desactivated) {__SET_VAR(data__->,HASPIECE,,0);};

  }


  // Actions state evaluation
  for (i = 0; i < data__->__nb_actions; i++) {
    if (data__->__action_list[i].set) {
      data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 1;
    }
    if (data__->__action_list[i].reset) {
      data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 0;
    }
    __SET_VAR(data__->,__action_list[i].state,,__GET_VAR(data__->__action_list[i].state) | data__->__action_list[i].stored);
  }

  // Actions execution
  if (data__->__action_list[__SFC_HASPIECE].reset) {
    __SET_VAR(data__->,HASPIECE,,0);
  }
  else if (data__->__action_list[__SFC_HASPIECE].set) {
    __SET_VAR(data__->,HASPIECE,,1);
  }


  goto __end;

__end:
  return;
} // ROLL_body__() 

// Steps undefinitions
#undef STEP0
#undef __SFC_STEP0
#undef STEP1
#undef __SFC_STEP1

// Actions undefinitions
#undef __SFC_HASPIECE





void MACHINE_init__(MACHINE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->REACHEDSENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->USETOOL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->READYTOSEND,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TOOLTIMERON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INITIALPIECE,0,retain)
  __INIT_VAR(data__->CURRENTPIECE,0,retain)
  __INIT_VAR(data__->FINALPIECE,0,retain)
  __INIT_VAR(data__->NEXTREADYTORECEIVE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TOOLPIECE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TOOLNUMBER,0,retain)
  __INIT_VAR(data__->TOOLPLUS,__BOOL_LITERAL(FALSE),0)
  __INIT_VAR(data__->TOOLSENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TOOLSENSORRE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TOOLMINUS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTORUP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTORLEFT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTORDOWN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTORRIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORUP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORLEFT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORDOWN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORRIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDTIMERON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FRONTNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORFRONT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORBACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ISBUSY,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  R_TRIG_init__(&data__->ASD,retain);
  TON_init__(&data__->TON2,retain);
  TON_init__(&data__->TON3,retain);
  TON_init__(&data__->TON4,retain);
  TON_init__(&data__->TON5,retain);
  TON_init__(&data__->TON6,retain);
  TON_init__(&data__->TON7,retain);
  UINT i;
  data__->__nb_steps = 44;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 22;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 56;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define INITLINEARSTEP __step_list[0]
#define __SFC_INITLINEARSTEP 0
#define MOVEFRONT __step_list[1]
#define __SFC_MOVEFRONT 1
#define NOTBUSYFRONT __step_list[2]
#define __SFC_NOTBUSYFRONT 2
#define MOVEFRONTSTEP __step_list[3]
#define __SFC_MOVEFRONTSTEP 3
#define TURNOFFFRONT __step_list[4]
#define __SFC_TURNOFFFRONT 4
#define MOVEBACK __step_list[5]
#define __SFC_MOVEBACK 5
#define NOTBUSYBACK __step_list[6]
#define __SFC_NOTBUSYBACK 6
#define MOVEBACKSTEP __step_list[7]
#define __SFC_MOVEBACKSTEP 7
#define TURNOFFBACK __step_list[8]
#define __SFC_TURNOFFBACK 8
#define MOVEFRONT0 __step_list[9]
#define __SFC_MOVEFRONT0 9
#define STEP2 __step_list[10]
#define __SFC_STEP2 10
#define STEP4 __step_list[11]
#define __SFC_STEP4 11
#define CHECKIFFINALA __step_list[12]
#define __SFC_CHECKIFFINALA 12
#define STEP11 __step_list[13]
#define __SFC_STEP11 13
#define STEP5 __step_list[14]
#define __SFC_STEP5 14
#define STEP0 __step_list[15]
#define __SFC_STEP0 15
#define STEP8 __step_list[16]
#define __SFC_STEP8 16
#define STEP1 __step_list[17]
#define __SFC_STEP1 17
#define STEP12 __step_list[18]
#define __SFC_STEP12 18
#define STEP14 __step_list[19]
#define __SFC_STEP14 19
#define STEP13 __step_list[20]
#define __SFC_STEP13 20
#define STEP15 __step_list[21]
#define __SFC_STEP15 21
#define STEP16 __step_list[22]
#define __SFC_STEP16 22
#define STEP18 __step_list[23]
#define __SFC_STEP18 23
#define STEP17 __step_list[24]
#define __SFC_STEP17 24
#define STEP19 __step_list[25]
#define __SFC_STEP19 25
#define SENDTONEXT __step_list[26]
#define __SFC_SENDTONEXT 26
#define STEP3 __step_list[27]
#define __SFC_STEP3 27
#define STEP10 __step_list[28]
#define __SFC_STEP10 28
#define STEP7 __step_list[29]
#define __SFC_STEP7 29
#define CHECKIFFINALB __step_list[30]
#define __SFC_CHECKIFFINALB 30
#define STEP27 __step_list[31]
#define __SFC_STEP27 31
#define STEP20 __step_list[32]
#define __SFC_STEP20 32
#define STEP28 __step_list[33]
#define __SFC_STEP28 33
#define STEP21 __step_list[34]
#define __SFC_STEP21 34
#define STEP29 __step_list[35]
#define __SFC_STEP29 35
#define STEP9 __step_list[36]
#define __SFC_STEP9 36
#define STEP23 __step_list[37]
#define __SFC_STEP23 37
#define STEP22 __step_list[38]
#define __SFC_STEP22 38
#define STEP24 __step_list[39]
#define __SFC_STEP24 39
#define STEP25 __step_list[40]
#define __SFC_STEP25 40
#define STEP31 __step_list[41]
#define __SFC_STEP31 41
#define STEP30 __step_list[42]
#define __SFC_STEP30 42
#define STEP32 __step_list[43]
#define __SFC_STEP32 43

// Actions definitions
#define __SFC_INCREMENTTOOLNUMBER 0
#define __SFC_TOOLSTANDBY 1
#define __SFC_COMPUTE_FUNCTION_BLOCKS 2
#define __SFC_CURRENTASINITIAL 3
#define __SFC_SETCURRENT3 4
#define __SFC_SETCURRENT5 5
#define __SFC_SETCURRENT7 6
#define __SFC_SETCURRENT6 7
#define __SFC_SETCURRENT4 8
#define __SFC_SETCURRENT8 9
#define __SFC_ISBUSY 10
#define __SFC_FORWARDMOTOR 11
#define __SFC_FORWARDTIMERON 12
#define __SFC_BACKMOTOR 13
#define __SFC_MOTORDOWN 14
#define __SFC_MOTORRIGHT 15
#define __SFC_TOOLPLUS 16
#define __SFC_USETOOL 17
#define __SFC_TOOLTIMERON 18
#define __SFC_MOTORUP 19
#define __SFC_MOTORLEFT 20
#define __SFC_READYTOSEND 21

// Code part
void MACHINE_body__(MACHINE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  INT i;
  TIME elapsed_time, current_time;

  // Calculate elapsed_time
  current_time = __CURRENT_TIME;
  elapsed_time = __time_sub(current_time, data__->__lasttick_time);
  data__->__lasttick_time = current_time;
  // Transitions initialization
  if (__DEBUG) {
    for (i = 0; i < data__->__nb_transitions; i++) {
      data__->__transition_list[i] = data__->__debug_transition_list[i];
    }
  }
  // Steps initialization
  for (i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i].prev_state = __GET_VAR(data__->__step_list[i].X);
    if (__GET_VAR(data__->__step_list[i].X)) {
      data__->__step_list[i].T.value = __time_add(data__->__step_list[i].T.value, elapsed_time);
    }
  }
  // Actions initialization
  for (i = 0; i < data__->__nb_actions; i++) {
    __SET_VAR(data__->,__action_list[i].state,,0);
    data__->__action_list[i].set = 0;
    data__->__action_list[i].reset = 0;
    if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].set_remaining_time = __time_sub(data__->__action_list[i].set_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].set = 1;
      }
    }
    if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].reset_remaining_time = __time_sub(data__->__action_list[i].reset_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].reset = 1;
      }
    }
  }

  // Transitions fire test
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[0],,__GET_VAR(data__->FORWARDSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->FORWARDSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->MOVEFRONT.X)) {
    __SET_VAR(data__->,__transition_list[1],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->NOTBUSYFRONT.X)) {
    __SET_VAR(data__->,__transition_list[2],,!(__GET_VAR(data__->FRONTNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,!(__GET_VAR(data__->FRONTNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->MOVEFRONTSTEP.X)) {
    __SET_VAR(data__->,__transition_list[3],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->TURNOFFFRONT.X)) {
    __SET_VAR(data__->,__transition_list[4],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->MOVEFRONTSTEP.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_VAR(data__->TON0.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->TON0.Q,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[6],,__GET_VAR(data__->BACKSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->BACKSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->MOVEBACK.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->NOTBUSYBACK.X)) {
    __SET_VAR(data__->,__transition_list[8],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP.X)) {
    __SET_VAR(data__->,__transition_list[9],,__GET_VAR(data__->REACHEDSENSORBACK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->REACHEDSENSORBACK,));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->TURNOFFBACK.X)) {
    __SET_VAR(data__->,__transition_list[10],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->TON1.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->TON1.Q,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[12],,__GET_VAR(data__->TOOLPIECE,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->TOOLPIECE,));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->MOVEFRONT0.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->STEP2.X)) {
    __SET_VAR(data__->,__transition_list[14],,(((__GET_VAR(data__->INITIALPIECE,) == 1) || (__GET_VAR(data__->INITIALPIECE,) == 3)) || (__GET_VAR(data__->INITIALPIECE,) == 5)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,(((__GET_VAR(data__->INITIALPIECE,) == 1) || (__GET_VAR(data__->INITIALPIECE,) == 3)) || (__GET_VAR(data__->INITIALPIECE,) == 5)));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->STEP4.X)) {
    __SET_VAR(data__->,__transition_list[15],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->CHECKIFFINALA.X)) {
    __SET_VAR(data__->,__transition_list[16],,(__GET_VAR(data__->CURRENTPIECE,) != __GET_VAR(data__->FINALPIECE,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,(__GET_VAR(data__->CURRENTPIECE,) != __GET_VAR(data__->FINALPIECE,)));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->STEP11.X)) {
    __SET_VAR(data__->,__transition_list[17],,(__GET_VAR(data__->CURRENTPIECE,) == 1));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,(__GET_VAR(data__->CURRENTPIECE,) == 1));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->STEP5.X)) {
    __SET_VAR(data__->,__transition_list[18],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->STEP0.X)) {
    __SET_VAR(data__->,__transition_list[19],,(__GET_VAR(data__->TOOLNUMBER,) == 1));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,(__GET_VAR(data__->TOOLNUMBER,) == 1));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->STEP8.X)) {
    __SET_VAR(data__->,__transition_list[20],,__GET_VAR(data__->TON2.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->TON2.Q,));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
    __SET_VAR(data__->,__transition_list[21],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->STEP11.X)) {
    __SET_VAR(data__->,__transition_list[22],,(__GET_VAR(data__->CURRENTPIECE,) == 3));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,(__GET_VAR(data__->CURRENTPIECE,) == 3));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->STEP12.X)) {
    __SET_VAR(data__->,__transition_list[23],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->STEP14.X)) {
    __SET_VAR(data__->,__transition_list[24],,(__GET_VAR(data__->TOOLNUMBER,) == 2));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,(__GET_VAR(data__->TOOLNUMBER,) == 2));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->STEP13.X)) {
    __SET_VAR(data__->,__transition_list[25],,__GET_VAR(data__->TON3.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->TON3.Q,));
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->STEP15.X)) {
    __SET_VAR(data__->,__transition_list[26],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->STEP11.X)) {
    __SET_VAR(data__->,__transition_list[27],,(__GET_VAR(data__->CURRENTPIECE,) == 5));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,(__GET_VAR(data__->CURRENTPIECE,) == 5));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->STEP16.X)) {
    __SET_VAR(data__->,__transition_list[28],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->STEP18.X)) {
    __SET_VAR(data__->,__transition_list[29],,(__GET_VAR(data__->TOOLNUMBER,) == 3));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,(__GET_VAR(data__->TOOLNUMBER,) == 3));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->STEP17.X)) {
    __SET_VAR(data__->,__transition_list[30],,__GET_VAR(data__->TON4.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->TON4.Q,));
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->STEP19.X)) {
    __SET_VAR(data__->,__transition_list[31],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }
  if (__GET_VAR(data__->SENDTONEXT.X)) {
    __SET_VAR(data__->,__transition_list[32],,(__GET_VAR(data__->SENSORUP,) && __GET_VAR(data__->SENSORLEFT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->__transition_list[32]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,(__GET_VAR(data__->SENSORUP,) && __GET_VAR(data__->SENSORLEFT,)));
    }
    __SET_VAR(data__->,__transition_list[32],,0);
  }
  if (__GET_VAR(data__->STEP3.X)) {
    __SET_VAR(data__->,__transition_list[33],,(!(__GET_VAR(data__->FRONTNOTBUSY,)) && __GET_VAR(data__->NEXTREADYTORECEIVE,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->__transition_list[33]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,(!(__GET_VAR(data__->FRONTNOTBUSY,)) && __GET_VAR(data__->NEXTREADYTORECEIVE,)));
    }
    __SET_VAR(data__->,__transition_list[33],,0);
  }
  if (__GET_VAR(data__->STEP10.X)) {
    __SET_VAR(data__->,__transition_list[34],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_VAR(data__->__transition_list[34]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    }
    __SET_VAR(data__->,__transition_list[34],,0);
  }
  if (__GET_VAR(data__->CHECKIFFINALA.X)) {
    __SET_VAR(data__->,__transition_list[35],,(__GET_VAR(data__->CURRENTPIECE,) == __GET_VAR(data__->FINALPIECE,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->__transition_list[35]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,(__GET_VAR(data__->CURRENTPIECE,) == __GET_VAR(data__->FINALPIECE,)));
    }
    __SET_VAR(data__->,__transition_list[35],,0);
  }
  if (__GET_VAR(data__->STEP2.X)) {
    __SET_VAR(data__->,__transition_list[36],,(((__GET_VAR(data__->INITIALPIECE,) == 2) || (__GET_VAR(data__->INITIALPIECE,) == 4)) || (__GET_VAR(data__->INITIALPIECE,) == 6)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->__transition_list[36]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,(((__GET_VAR(data__->INITIALPIECE,) == 2) || (__GET_VAR(data__->INITIALPIECE,) == 4)) || (__GET_VAR(data__->INITIALPIECE,) == 6)));
    }
    __SET_VAR(data__->,__transition_list[36],,0);
  }
  if (__GET_VAR(data__->STEP7.X)) {
    __SET_VAR(data__->,__transition_list[37],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_VAR(data__->__transition_list[37]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[37],,0);
  }
  if (__GET_VAR(data__->CHECKIFFINALB.X)) {
    __SET_VAR(data__->,__transition_list[38],,(__GET_VAR(data__->CURRENTPIECE,) != __GET_VAR(data__->FINALPIECE,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_VAR(data__->__transition_list[38]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,(__GET_VAR(data__->CURRENTPIECE,) != __GET_VAR(data__->FINALPIECE,)));
    }
    __SET_VAR(data__->,__transition_list[38],,0);
  }
  if (__GET_VAR(data__->STEP27.X)) {
    __SET_VAR(data__->,__transition_list[39],,(__GET_VAR(data__->CURRENTPIECE,) == 4));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,__GET_VAR(data__->__transition_list[39]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,(__GET_VAR(data__->CURRENTPIECE,) == 4));
    }
    __SET_VAR(data__->,__transition_list[39],,0);
  }
  if (__GET_VAR(data__->STEP20.X)) {
    __SET_VAR(data__->,__transition_list[40],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_VAR(data__->__transition_list[40]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    }
    __SET_VAR(data__->,__transition_list[40],,0);
  }
  if (__GET_VAR(data__->STEP28.X)) {
    __SET_VAR(data__->,__transition_list[41],,(__GET_VAR(data__->TOOLNUMBER,) == 2));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,__GET_VAR(data__->__transition_list[41]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,(__GET_VAR(data__->TOOLNUMBER,) == 2));
    }
    __SET_VAR(data__->,__transition_list[41],,0);
  }
  if (__GET_VAR(data__->STEP21.X)) {
    __SET_VAR(data__->,__transition_list[42],,__GET_VAR(data__->TON6.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,__GET_VAR(data__->__transition_list[42]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,__GET_VAR(data__->TON6.Q,));
    }
    __SET_VAR(data__->,__transition_list[42],,0);
  }
  if (__GET_VAR(data__->STEP29.X)) {
    __SET_VAR(data__->,__transition_list[43],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,__GET_VAR(data__->__transition_list[43]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[43],,0);
  }
  if (__GET_VAR(data__->STEP27.X)) {
    __SET_VAR(data__->,__transition_list[44],,(__GET_VAR(data__->CURRENTPIECE,) == 2));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,__GET_VAR(data__->__transition_list[44]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,(__GET_VAR(data__->CURRENTPIECE,) == 2));
    }
    __SET_VAR(data__->,__transition_list[44],,0);
  }
  if (__GET_VAR(data__->STEP9.X)) {
    __SET_VAR(data__->,__transition_list[45],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,__GET_VAR(data__->__transition_list[45]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    }
    __SET_VAR(data__->,__transition_list[45],,0);
  }
  if (__GET_VAR(data__->STEP23.X)) {
    __SET_VAR(data__->,__transition_list[46],,(__GET_VAR(data__->TOOLNUMBER,) == 1));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,__GET_VAR(data__->__transition_list[46]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,(__GET_VAR(data__->TOOLNUMBER,) == 1));
    }
    __SET_VAR(data__->,__transition_list[46],,0);
  }
  if (__GET_VAR(data__->STEP22.X)) {
    __SET_VAR(data__->,__transition_list[47],,__GET_VAR(data__->TON5.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,__GET_VAR(data__->__transition_list[47]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,__GET_VAR(data__->TON5.Q,));
    }
    __SET_VAR(data__->,__transition_list[47],,0);
  }
  if (__GET_VAR(data__->STEP24.X)) {
    __SET_VAR(data__->,__transition_list[48],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,__GET_VAR(data__->__transition_list[48]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[48],,0);
  }
  if (__GET_VAR(data__->STEP27.X)) {
    __SET_VAR(data__->,__transition_list[49],,(__GET_VAR(data__->CURRENTPIECE,) == 6));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,__GET_VAR(data__->__transition_list[49]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,(__GET_VAR(data__->CURRENTPIECE,) == 6));
    }
    __SET_VAR(data__->,__transition_list[49],,0);
  }
  if (__GET_VAR(data__->STEP25.X)) {
    __SET_VAR(data__->,__transition_list[50],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[50],,__GET_VAR(data__->__transition_list[50]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[50],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    }
    __SET_VAR(data__->,__transition_list[50],,0);
  }
  if (__GET_VAR(data__->STEP31.X)) {
    __SET_VAR(data__->,__transition_list[51],,(__GET_VAR(data__->TOOLNUMBER,) == 3));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[51],,__GET_VAR(data__->__transition_list[51]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[51],,(__GET_VAR(data__->TOOLNUMBER,) == 3));
    }
    __SET_VAR(data__->,__transition_list[51],,0);
  }
  if (__GET_VAR(data__->STEP30.X)) {
    __SET_VAR(data__->,__transition_list[52],,__GET_VAR(data__->TON7.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[52],,__GET_VAR(data__->__transition_list[52]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[52],,__GET_VAR(data__->TON7.Q,));
    }
    __SET_VAR(data__->,__transition_list[52],,0);
  }
  if (__GET_VAR(data__->STEP32.X)) {
    __SET_VAR(data__->,__transition_list[53],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[53],,__GET_VAR(data__->__transition_list[53]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[53],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[53],,0);
  }
  if (__GET_VAR(data__->CHECKIFFINALB.X)) {
    __SET_VAR(data__->,__transition_list[54],,(__GET_VAR(data__->CURRENTPIECE,) == __GET_VAR(data__->FINALPIECE,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[54],,__GET_VAR(data__->__transition_list[54]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[54],,(__GET_VAR(data__->CURRENTPIECE,) == __GET_VAR(data__->FINALPIECE,)));
    }
    __SET_VAR(data__->,__transition_list[54],,0);
  }
  if (__GET_VAR(data__->STEP2.X)) {
    __SET_VAR(data__->,__transition_list[55],,(__GET_VAR(data__->INITIALPIECE,) == __GET_VAR(data__->FINALPIECE,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[55],,__GET_VAR(data__->__transition_list[55]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[55],,(__GET_VAR(data__->INITIALPIECE,) == __GET_VAR(data__->FINALPIECE,)));
    }
    __SET_VAR(data__->,__transition_list[55],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,MOVEFRONT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,NOTBUSYFRONT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,MOVEFRONTSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,TURNOFFFRONT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,MOVEFRONTSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,MOVEBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,NOTBUSYBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,MOVEBACKSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,MOVEBACKSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,MOVEFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,CHECKIFFINALA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP5.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP12.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP14.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP13.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP15.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP16.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP18.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP17.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP19.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,SENDTONEXT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,STEP3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,STEP10.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,CHECKIFFINALA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,STEP2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,STEP7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,CHECKIFFINALB.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,STEP27.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,STEP20.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,STEP28.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,STEP21.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,STEP29.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,STEP27.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,STEP9.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,STEP23.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,STEP22.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,STEP24.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,STEP27.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[50])) {
    __SET_VAR(data__->,STEP25.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[51])) {
    __SET_VAR(data__->,STEP31.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[52])) {
    __SET_VAR(data__->,STEP30.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[53])) {
    __SET_VAR(data__->,STEP32.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[54])) {
    __SET_VAR(data__->,CHECKIFFINALB.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[55])) {
    __SET_VAR(data__->,STEP2.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,MOVEFRONT.X,,1);
    data__->MOVEFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,NOTBUSYFRONT.X,,1);
    data__->NOTBUSYFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,MOVEFRONTSTEP.X,,1);
    data__->MOVEFRONTSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,TURNOFFFRONT.X,,1);
    data__->TURNOFFFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,TURNOFFFRONT.X,,1);
    data__->TURNOFFFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,MOVEBACK.X,,1);
    data__->MOVEBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,NOTBUSYBACK.X,,1);
    data__->NOTBUSYBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,MOVEBACKSTEP.X,,1);
    data__->MOVEBACKSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,1);
    data__->TURNOFFBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,1);
    data__->TURNOFFBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,MOVEFRONT0.X,,1);
    data__->MOVEFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP4.X,,1);
    data__->STEP4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,CHECKIFFINALA.X,,1);
    data__->CHECKIFFINALA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP11.X,,1);
    data__->STEP11.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP5.X,,1);
    data__->STEP5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP8.X,,1);
    data__->STEP8.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,CHECKIFFINALA.X,,1);
    data__->CHECKIFFINALA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP12.X,,1);
    data__->STEP12.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP14.X,,1);
    data__->STEP14.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP13.X,,1);
    data__->STEP13.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP15.X,,1);
    data__->STEP15.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,CHECKIFFINALA.X,,1);
    data__->CHECKIFFINALA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP16.X,,1);
    data__->STEP16.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP18.X,,1);
    data__->STEP18.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP17.X,,1);
    data__->STEP17.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP19.X,,1);
    data__->STEP19.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,SENDTONEXT.X,,1);
    data__->SENDTONEXT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,STEP3.X,,1);
    data__->STEP3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,STEP10.X,,1);
    data__->STEP10.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,SENDTONEXT.X,,1);
    data__->SENDTONEXT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,STEP7.X,,1);
    data__->STEP7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,CHECKIFFINALB.X,,1);
    data__->CHECKIFFINALB.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,STEP27.X,,1);
    data__->STEP27.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,STEP20.X,,1);
    data__->STEP20.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,STEP28.X,,1);
    data__->STEP28.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,STEP21.X,,1);
    data__->STEP21.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,STEP29.X,,1);
    data__->STEP29.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,CHECKIFFINALB.X,,1);
    data__->CHECKIFFINALB.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,STEP9.X,,1);
    data__->STEP9.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,STEP23.X,,1);
    data__->STEP23.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,STEP22.X,,1);
    data__->STEP22.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,STEP24.X,,1);
    data__->STEP24.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,CHECKIFFINALB.X,,1);
    data__->CHECKIFFINALB.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,STEP25.X,,1);
    data__->STEP25.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[50])) {
    __SET_VAR(data__->,STEP31.X,,1);
    data__->STEP31.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[51])) {
    __SET_VAR(data__->,STEP30.X,,1);
    data__->STEP30.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[52])) {
    __SET_VAR(data__->,STEP32.X,,1);
    data__->STEP32.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[53])) {
    __SET_VAR(data__->,SENDTONEXT.X,,1);
    data__->SENDTONEXT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[54])) {
    __SET_VAR(data__->,SENDTONEXT.X,,1);
    data__->SENDTONEXT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[55])) {
    __SET_VAR(data__->,SENDTONEXT.X,,1);
    data__->SENDTONEXT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // INITLINEARSTEP action associations
  {
    char active = __GET_VAR(data__->INITLINEARSTEP.X);
    char activated = active && !data__->INITLINEARSTEP.prev_state;
    char desactivated = !active && data__->INITLINEARSTEP.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].reset = 1;}

    if (active)       {data__->__action_list[__SFC_INCREMENTTOOLNUMBER].set = 1;}

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_TOOLSTANDBY].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_TOOLSTANDBY].state,,0);};

    if (active)       {data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].set = 1;}

  }

  // MOVEFRONT action associations
  {
    char active = __GET_VAR(data__->MOVEFRONT.X);
    char activated = active && !data__->MOVEFRONT.prev_state;
    char desactivated = !active && data__->MOVEFRONT.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDMOTOR,,0);};

  }

  // NOTBUSYFRONT action associations
  {
    char active = __GET_VAR(data__->NOTBUSYFRONT.X);
    char activated = active && !data__->NOTBUSYFRONT.prev_state;
    char desactivated = !active && data__->NOTBUSYFRONT.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // MOVEFRONTSTEP action associations
  {
    char active = __GET_VAR(data__->MOVEFRONTSTEP.X);
    char activated = active && !data__->MOVEFRONTSTEP.prev_state;
    char desactivated = !active && data__->MOVEFRONTSTEP.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDTIMERON,,0);};

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].set = 1;}

  }

  // TURNOFFFRONT action associations
  {
    char active = __GET_VAR(data__->TURNOFFFRONT.X);
    char activated = active && !data__->TURNOFFFRONT.prev_state;
    char desactivated = !active && data__->TURNOFFFRONT.prev_state;

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].reset = 1;}

  }

  // MOVEBACK action associations
  {
    char active = __GET_VAR(data__->MOVEBACK.X);
    char activated = active && !data__->MOVEBACK.prev_state;
    char desactivated = !active && data__->MOVEBACK.prev_state;

    if (active)       {__SET_VAR(data__->,BACKMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,BACKMOTOR,,0);};

  }

  // NOTBUSYBACK action associations
  {
    char active = __GET_VAR(data__->NOTBUSYBACK.X);
    char activated = active && !data__->NOTBUSYBACK.prev_state;
    char desactivated = !active && data__->NOTBUSYBACK.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // MOVEBACKSTEP action associations
  {
    char active = __GET_VAR(data__->MOVEBACKSTEP.X);
    char activated = active && !data__->MOVEBACKSTEP.prev_state;
    char desactivated = !active && data__->MOVEBACKSTEP.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDTIMERON,,0);};

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].set = 1;}

  }

  // TURNOFFBACK action associations
  {
    char active = __GET_VAR(data__->TURNOFFBACK.X);
    char activated = active && !data__->TURNOFFBACK.prev_state;
    char desactivated = !active && data__->TURNOFFBACK.prev_state;

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].reset = 1;}

  }

  // MOVEFRONT0 action associations
  {
    char active = __GET_VAR(data__->MOVEFRONT0.X);
    char activated = active && !data__->MOVEFRONT0.prev_state;
    char desactivated = !active && data__->MOVEFRONT0.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDMOTOR,,0);};

  }

  // STEP4 action associations
  {
    char active = __GET_VAR(data__->STEP4.X);
    char activated = active && !data__->STEP4.prev_state;
    char desactivated = !active && data__->STEP4.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_CURRENTASINITIAL].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_CURRENTASINITIAL].state,,0);};

  }

  // STEP5 action associations
  {
    char active = __GET_VAR(data__->STEP5.X);
    char activated = active && !data__->STEP5.prev_state;
    char desactivated = !active && data__->STEP5.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

    if (active)       {__SET_VAR(data__->,MOTORDOWN,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORDOWN,,0);};

    if (active)       {__SET_VAR(data__->,MOTORRIGHT,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORRIGHT,,0);};

  }

  // STEP0 action associations
  {
    char active = __GET_VAR(data__->STEP0.X);
    char activated = active && !data__->STEP0.prev_state;
    char desactivated = !active && data__->STEP0.prev_state;

    if (active)       {__SET_VAR(data__->,TOOLPLUS,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLPLUS,,0);};

  }

  // STEP8 action associations
  {
    char active = __GET_VAR(data__->STEP8.X);
    char activated = active && !data__->STEP8.prev_state;
    char desactivated = !active && data__->STEP8.prev_state;

    if (active)       {__SET_VAR(data__->,USETOOL,,1);};
    if (desactivated) {__SET_VAR(data__->,USETOOL,,0);};

    if (active)       {__SET_VAR(data__->,TOOLTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLTIMERON,,0);};

  }

  // STEP1 action associations
  {
    char active = __GET_VAR(data__->STEP1.X);
    char activated = active && !data__->STEP1.prev_state;
    char desactivated = !active && data__->STEP1.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT3].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT3].state,,0);};

  }

  // STEP12 action associations
  {
    char active = __GET_VAR(data__->STEP12.X);
    char activated = active && !data__->STEP12.prev_state;
    char desactivated = !active && data__->STEP12.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

    if (active)       {__SET_VAR(data__->,MOTORDOWN,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORDOWN,,0);};

    if (active)       {__SET_VAR(data__->,MOTORRIGHT,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORRIGHT,,0);};

  }

  // STEP14 action associations
  {
    char active = __GET_VAR(data__->STEP14.X);
    char activated = active && !data__->STEP14.prev_state;
    char desactivated = !active && data__->STEP14.prev_state;

    if (active)       {__SET_VAR(data__->,TOOLPLUS,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLPLUS,,0);};

  }

  // STEP13 action associations
  {
    char active = __GET_VAR(data__->STEP13.X);
    char activated = active && !data__->STEP13.prev_state;
    char desactivated = !active && data__->STEP13.prev_state;

    if (active)       {__SET_VAR(data__->,USETOOL,,1);};
    if (desactivated) {__SET_VAR(data__->,USETOOL,,0);};

    if (active)       {__SET_VAR(data__->,TOOLTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLTIMERON,,0);};

  }

  // STEP15 action associations
  {
    char active = __GET_VAR(data__->STEP15.X);
    char activated = active && !data__->STEP15.prev_state;
    char desactivated = !active && data__->STEP15.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT5].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT5].state,,0);};

  }

  // STEP16 action associations
  {
    char active = __GET_VAR(data__->STEP16.X);
    char activated = active && !data__->STEP16.prev_state;
    char desactivated = !active && data__->STEP16.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

    if (active)       {__SET_VAR(data__->,MOTORDOWN,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORDOWN,,0);};

    if (active)       {__SET_VAR(data__->,MOTORRIGHT,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORRIGHT,,0);};

  }

  // STEP18 action associations
  {
    char active = __GET_VAR(data__->STEP18.X);
    char activated = active && !data__->STEP18.prev_state;
    char desactivated = !active && data__->STEP18.prev_state;

    if (active)       {__SET_VAR(data__->,TOOLPLUS,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLPLUS,,0);};

  }

  // STEP17 action associations
  {
    char active = __GET_VAR(data__->STEP17.X);
    char activated = active && !data__->STEP17.prev_state;
    char desactivated = !active && data__->STEP17.prev_state;

    if (active)       {__SET_VAR(data__->,USETOOL,,1);};
    if (desactivated) {__SET_VAR(data__->,USETOOL,,0);};

    if (active)       {__SET_VAR(data__->,TOOLTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLTIMERON,,0);};

  }

  // STEP19 action associations
  {
    char active = __GET_VAR(data__->STEP19.X);
    char activated = active && !data__->STEP19.prev_state;
    char desactivated = !active && data__->STEP19.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT7].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT7].state,,0);};

  }

  // SENDTONEXT action associations
  {
    char active = __GET_VAR(data__->SENDTONEXT.X);
    char activated = active && !data__->SENDTONEXT.prev_state;
    char desactivated = !active && data__->SENDTONEXT.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORUP,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORUP,,0);};

    if (active)       {__SET_VAR(data__->,MOTORLEFT,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORLEFT,,0);};

  }

  // STEP3 action associations
  {
    char active = __GET_VAR(data__->STEP3.X);
    char activated = active && !data__->STEP3.prev_state;
    char desactivated = !active && data__->STEP3.prev_state;

    if (active)       {__SET_VAR(data__->,READYTOSEND,,1);};
    if (desactivated) {__SET_VAR(data__->,READYTOSEND,,0);};

  }

  // STEP10 action associations
  {
    char active = __GET_VAR(data__->STEP10.X);
    char activated = active && !data__->STEP10.prev_state;
    char desactivated = !active && data__->STEP10.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDMOTOR,,0);};

  }

  // STEP7 action associations
  {
    char active = __GET_VAR(data__->STEP7.X);
    char activated = active && !data__->STEP7.prev_state;
    char desactivated = !active && data__->STEP7.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_CURRENTASINITIAL].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_CURRENTASINITIAL].state,,0);};

  }

  // STEP20 action associations
  {
    char active = __GET_VAR(data__->STEP20.X);
    char activated = active && !data__->STEP20.prev_state;
    char desactivated = !active && data__->STEP20.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

    if (active)       {__SET_VAR(data__->,MOTORDOWN,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORDOWN,,0);};

    if (active)       {__SET_VAR(data__->,MOTORRIGHT,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORRIGHT,,0);};

  }

  // STEP28 action associations
  {
    char active = __GET_VAR(data__->STEP28.X);
    char activated = active && !data__->STEP28.prev_state;
    char desactivated = !active && data__->STEP28.prev_state;

    if (active)       {__SET_VAR(data__->,TOOLPLUS,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLPLUS,,0);};

  }

  // STEP21 action associations
  {
    char active = __GET_VAR(data__->STEP21.X);
    char activated = active && !data__->STEP21.prev_state;
    char desactivated = !active && data__->STEP21.prev_state;

    if (active)       {__SET_VAR(data__->,USETOOL,,1);};
    if (desactivated) {__SET_VAR(data__->,USETOOL,,0);};

    if (active)       {__SET_VAR(data__->,TOOLTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLTIMERON,,0);};

  }

  // STEP29 action associations
  {
    char active = __GET_VAR(data__->STEP29.X);
    char activated = active && !data__->STEP29.prev_state;
    char desactivated = !active && data__->STEP29.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT6].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT6].state,,0);};

  }

  // STEP9 action associations
  {
    char active = __GET_VAR(data__->STEP9.X);
    char activated = active && !data__->STEP9.prev_state;
    char desactivated = !active && data__->STEP9.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

    if (active)       {__SET_VAR(data__->,MOTORDOWN,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORDOWN,,0);};

    if (active)       {__SET_VAR(data__->,MOTORRIGHT,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORRIGHT,,0);};

  }

  // STEP23 action associations
  {
    char active = __GET_VAR(data__->STEP23.X);
    char activated = active && !data__->STEP23.prev_state;
    char desactivated = !active && data__->STEP23.prev_state;

    if (active)       {__SET_VAR(data__->,TOOLPLUS,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLPLUS,,0);};

  }

  // STEP22 action associations
  {
    char active = __GET_VAR(data__->STEP22.X);
    char activated = active && !data__->STEP22.prev_state;
    char desactivated = !active && data__->STEP22.prev_state;

    if (active)       {__SET_VAR(data__->,USETOOL,,1);};
    if (desactivated) {__SET_VAR(data__->,USETOOL,,0);};

    if (active)       {__SET_VAR(data__->,TOOLTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLTIMERON,,0);};

  }

  // STEP24 action associations
  {
    char active = __GET_VAR(data__->STEP24.X);
    char activated = active && !data__->STEP24.prev_state;
    char desactivated = !active && data__->STEP24.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT4].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT4].state,,0);};

  }

  // STEP25 action associations
  {
    char active = __GET_VAR(data__->STEP25.X);
    char activated = active && !data__->STEP25.prev_state;
    char desactivated = !active && data__->STEP25.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

    if (active)       {__SET_VAR(data__->,MOTORDOWN,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORDOWN,,0);};

    if (active)       {__SET_VAR(data__->,MOTORRIGHT,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORRIGHT,,0);};

  }

  // STEP31 action associations
  {
    char active = __GET_VAR(data__->STEP31.X);
    char activated = active && !data__->STEP31.prev_state;
    char desactivated = !active && data__->STEP31.prev_state;

    if (active)       {__SET_VAR(data__->,TOOLPLUS,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLPLUS,,0);};

  }

  // STEP30 action associations
  {
    char active = __GET_VAR(data__->STEP30.X);
    char activated = active && !data__->STEP30.prev_state;
    char desactivated = !active && data__->STEP30.prev_state;

    if (active)       {__SET_VAR(data__->,USETOOL,,1);};
    if (desactivated) {__SET_VAR(data__->,USETOOL,,0);};

    if (active)       {__SET_VAR(data__->,TOOLTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLTIMERON,,0);};

  }

  // STEP32 action associations
  {
    char active = __GET_VAR(data__->STEP32.X);
    char activated = active && !data__->STEP32.prev_state;
    char desactivated = !active && data__->STEP32.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT8].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT8].state,,0);};

  }


  // Actions state evaluation
  for (i = 0; i < data__->__nb_actions; i++) {
    if (data__->__action_list[i].set) {
      data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 1;
    }
    if (data__->__action_list[i].reset) {
      data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 0;
    }
    __SET_VAR(data__->,__action_list[i].state,,__GET_VAR(data__->__action_list[i].state) | data__->__action_list[i].stored);
  }

  // Actions execution
  if (data__->__action_list[__SFC_ISBUSY].reset) {
    __SET_VAR(data__->,ISBUSY,,0);
  }
  else if (data__->__action_list[__SFC_ISBUSY].set) {
    __SET_VAR(data__->,ISBUSY,,1);
  }
  if (data__->__action_list[__SFC_FORWARDMOTOR].reset) {
    __SET_VAR(data__->,FORWARDMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_FORWARDMOTOR].set) {
    __SET_VAR(data__->,FORWARDMOTOR,,1);
  }
  if (data__->__action_list[__SFC_FORWARDTIMERON].reset) {
    __SET_VAR(data__->,FORWARDTIMERON,,0);
  }
  else if (data__->__action_list[__SFC_FORWARDTIMERON].set) {
    __SET_VAR(data__->,FORWARDTIMERON,,1);
  }
  if (data__->__action_list[__SFC_BACKMOTOR].reset) {
    __SET_VAR(data__->,BACKMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_BACKMOTOR].set) {
    __SET_VAR(data__->,BACKMOTOR,,1);
  }
  if (data__->__action_list[__SFC_MOTORDOWN].reset) {
    __SET_VAR(data__->,MOTORDOWN,,0);
  }
  else if (data__->__action_list[__SFC_MOTORDOWN].set) {
    __SET_VAR(data__->,MOTORDOWN,,1);
  }
  if (data__->__action_list[__SFC_MOTORRIGHT].reset) {
    __SET_VAR(data__->,MOTORRIGHT,,0);
  }
  else if (data__->__action_list[__SFC_MOTORRIGHT].set) {
    __SET_VAR(data__->,MOTORRIGHT,,1);
  }
  if (data__->__action_list[__SFC_TOOLPLUS].reset) {
    __SET_VAR(data__->,TOOLPLUS,,0);
  }
  else if (data__->__action_list[__SFC_TOOLPLUS].set) {
    __SET_VAR(data__->,TOOLPLUS,,1);
  }
  if (data__->__action_list[__SFC_USETOOL].reset) {
    __SET_VAR(data__->,USETOOL,,0);
  }
  else if (data__->__action_list[__SFC_USETOOL].set) {
    __SET_VAR(data__->,USETOOL,,1);
  }
  if (data__->__action_list[__SFC_TOOLTIMERON].reset) {
    __SET_VAR(data__->,TOOLTIMERON,,0);
  }
  else if (data__->__action_list[__SFC_TOOLTIMERON].set) {
    __SET_VAR(data__->,TOOLTIMERON,,1);
  }
  if (data__->__action_list[__SFC_MOTORUP].reset) {
    __SET_VAR(data__->,MOTORUP,,0);
  }
  else if (data__->__action_list[__SFC_MOTORUP].set) {
    __SET_VAR(data__->,MOTORUP,,1);
  }
  if (data__->__action_list[__SFC_MOTORLEFT].reset) {
    __SET_VAR(data__->,MOTORLEFT,,0);
  }
  else if (data__->__action_list[__SFC_MOTORLEFT].set) {
    __SET_VAR(data__->,MOTORLEFT,,1);
  }
  if (data__->__action_list[__SFC_READYTOSEND].reset) {
    __SET_VAR(data__->,READYTOSEND,,0);
  }
  else if (data__->__action_list[__SFC_READYTOSEND].set) {
    __SET_VAR(data__->,READYTOSEND,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_INCREMENTTOOLNUMBER].state)) {
    __SET_VAR(data__->ASD.,CLK,,__GET_VAR(data__->TOOLSENSOR,));
    R_TRIG_body__(&data__->ASD);
    __SET_VAR(data__->,TOOLSENSORRE,,__GET_VAR(data__->ASD.Q));
    if ((__GET_VAR(data__->ASD.Q,) == __BOOL_LITERAL(TRUE))) {
      __SET_VAR(data__->,TOOLNUMBER,,(__GET_VAR(data__->TOOLNUMBER,) + 1));
      if ((__GET_VAR(data__->TOOLNUMBER,) == 4)) {
        __SET_VAR(data__->,TOOLNUMBER,,1);
      };
    };
  }

  if(__GET_VAR(data__->__action_list[__SFC_TOOLSTANDBY].state)) {
    __SET_VAR(data__->,MOTORUP,,!(__GET_VAR(data__->SENSORUP,)));
    __SET_VAR(data__->,MOTORLEFT,,!(__GET_VAR(data__->SENSORLEFT,)));
  }

  if(__GET_VAR(data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].state)) {
    __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->FORWARDTIMERON,));
    __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
    TON_body__(&data__->TON1);
    __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->FORWARDTIMERON,));
    __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
    TON_body__(&data__->TON0);
    __SET_VAR(data__->TON2.,IN,,__GET_VAR(data__->TOOLTIMERON,));
    __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
    TON_body__(&data__->TON2);
    __SET_VAR(data__->TON3.,IN,,__GET_VAR(data__->TOOLTIMERON,));
    __SET_VAR(data__->TON3.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
    TON_body__(&data__->TON3);
    __SET_VAR(data__->TON4.,IN,,__GET_VAR(data__->TOOLTIMERON,));
    __SET_VAR(data__->TON4.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
    TON_body__(&data__->TON4);
    __SET_VAR(data__->TON6.,IN,,__GET_VAR(data__->TOOLTIMERON,));
    __SET_VAR(data__->TON6.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
    TON_body__(&data__->TON6);
    __SET_VAR(data__->TON5.,IN,,__GET_VAR(data__->TOOLTIMERON,));
    __SET_VAR(data__->TON5.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
    TON_body__(&data__->TON5);
    __SET_VAR(data__->TON7.,IN,,__GET_VAR(data__->TOOLTIMERON,));
    __SET_VAR(data__->TON7.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
    TON_body__(&data__->TON7);
  }

  if(__GET_VAR(data__->__action_list[__SFC_CURRENTASINITIAL].state)) {
    __SET_VAR(data__->,CURRENTPIECE,,__GET_VAR(data__->INITIALPIECE,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_SETCURRENT3].state)) {
    __SET_VAR(data__->,CURRENTPIECE,,3);
  }

  if(__GET_VAR(data__->__action_list[__SFC_SETCURRENT5].state)) {
    __SET_VAR(data__->,CURRENTPIECE,,5);
  }

  if(__GET_VAR(data__->__action_list[__SFC_SETCURRENT7].state)) {
    __SET_VAR(data__->,CURRENTPIECE,,7);
  }

  if(__GET_VAR(data__->__action_list[__SFC_SETCURRENT6].state)) {
    __SET_VAR(data__->,CURRENTPIECE,,6);
  }

  if(__GET_VAR(data__->__action_list[__SFC_SETCURRENT4].state)) {
    __SET_VAR(data__->,CURRENTPIECE,,4);
  }

  if(__GET_VAR(data__->__action_list[__SFC_SETCURRENT8].state)) {
    __SET_VAR(data__->,CURRENTPIECE,,8);
  }



  goto __end;

__end:
  return;
} // MACHINE_body__() 

// Steps undefinitions
#undef INITLINEARSTEP
#undef __SFC_INITLINEARSTEP
#undef MOVEFRONT
#undef __SFC_MOVEFRONT
#undef NOTBUSYFRONT
#undef __SFC_NOTBUSYFRONT
#undef MOVEFRONTSTEP
#undef __SFC_MOVEFRONTSTEP
#undef TURNOFFFRONT
#undef __SFC_TURNOFFFRONT
#undef MOVEBACK
#undef __SFC_MOVEBACK
#undef NOTBUSYBACK
#undef __SFC_NOTBUSYBACK
#undef MOVEBACKSTEP
#undef __SFC_MOVEBACKSTEP
#undef TURNOFFBACK
#undef __SFC_TURNOFFBACK
#undef MOVEFRONT0
#undef __SFC_MOVEFRONT0
#undef STEP2
#undef __SFC_STEP2
#undef STEP4
#undef __SFC_STEP4
#undef CHECKIFFINALA
#undef __SFC_CHECKIFFINALA
#undef STEP11
#undef __SFC_STEP11
#undef STEP5
#undef __SFC_STEP5
#undef STEP0
#undef __SFC_STEP0
#undef STEP8
#undef __SFC_STEP8
#undef STEP1
#undef __SFC_STEP1
#undef STEP12
#undef __SFC_STEP12
#undef STEP14
#undef __SFC_STEP14
#undef STEP13
#undef __SFC_STEP13
#undef STEP15
#undef __SFC_STEP15
#undef STEP16
#undef __SFC_STEP16
#undef STEP18
#undef __SFC_STEP18
#undef STEP17
#undef __SFC_STEP17
#undef STEP19
#undef __SFC_STEP19
#undef SENDTONEXT
#undef __SFC_SENDTONEXT
#undef STEP3
#undef __SFC_STEP3
#undef STEP10
#undef __SFC_STEP10
#undef STEP7
#undef __SFC_STEP7
#undef CHECKIFFINALB
#undef __SFC_CHECKIFFINALB
#undef STEP27
#undef __SFC_STEP27
#undef STEP20
#undef __SFC_STEP20
#undef STEP28
#undef __SFC_STEP28
#undef STEP21
#undef __SFC_STEP21
#undef STEP29
#undef __SFC_STEP29
#undef STEP9
#undef __SFC_STEP9
#undef STEP23
#undef __SFC_STEP23
#undef STEP22
#undef __SFC_STEP22
#undef STEP24
#undef __SFC_STEP24
#undef STEP25
#undef __SFC_STEP25
#undef STEP31
#undef __SFC_STEP31
#undef STEP30
#undef __SFC_STEP30
#undef STEP32
#undef __SFC_STEP32

// Actions undefinitions
#undef __SFC_INCREMENTTOOLNUMBER
#undef __SFC_TOOLSTANDBY
#undef __SFC_COMPUTE_FUNCTION_BLOCKS
#undef __SFC_CURRENTASINITIAL
#undef __SFC_SETCURRENT3
#undef __SFC_SETCURRENT5
#undef __SFC_SETCURRENT7
#undef __SFC_SETCURRENT6
#undef __SFC_SETCURRENT4
#undef __SFC_SETCURRENT8
#undef __SFC_ISBUSY
#undef __SFC_FORWARDMOTOR
#undef __SFC_FORWARDTIMERON
#undef __SFC_BACKMOTOR
#undef __SFC_MOTORDOWN
#undef __SFC_MOTORRIGHT
#undef __SFC_TOOLPLUS
#undef __SFC_USETOOL
#undef __SFC_TOOLTIMERON
#undef __SFC_MOTORUP
#undef __SFC_MOTORLEFT
#undef __SFC_READYTOSEND





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  LINEARCONVEYOR_init__(&data__->AT1,retain);
  __INIT_EXTERNAL(BOOL,WAREHOUSEBUSY,data__->WAREHOUSEBUSY,retain)
  __INIT_LOCATED(BOOL,__QX0_1_0_0,data__->WAREHOUSEBUSYCOMM,retain)
  __INIT_LOCATED_VALUE(data__->WAREHOUSEBUSYCOMM,__BOOL_LITERAL(FALSE))
  LINEARCONVEYOR_init__(&data__->SAT1,retain);
  ROTARYCONVEYOR_init__(&data__->SAT2,retain);
  LINEARCONVEYOR_init__(&data__->SBT1,retain);
  __INIT_EXTERNAL(BOOL,SENSORAT1_EX,data__->SENSORAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORAT2_EX,data__->SENSORAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT1_EX,data__->SENSORSAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT2_EX,data__->SENSORSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT3_EX,data__->SENSORSAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT4_EX,data__->SENSORSAT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT5_EX,data__->SENSORSAT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT6_EX,data__->SENSORSAT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT7_EX,data__->SENSORSAT7_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT1_EX,data__->SENSORSBT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT2_EX,data__->SENSORSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT1_EX,data__->SENSORSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT2_EX,data__->SENSORSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT7_EX,data__->SENSORSCT7_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT1_EX,data__->SENSORMT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT2_EX,data__->SENSORMT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT1_EX,data__->SENSORCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT2_EX,data__->SENSORCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT3_EX,data__->SENSORCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT4_EX,data__->SENSORCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT6_EX,data__->SENSORCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT5_EX,data__->SENSORCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT7_EX,data__->SENSORCT7_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT8_EX,data__->SENSORCT8_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT9_EX,data__->SENSORCT9_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKAT2_EX,data__->RUNBACKAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSAT7_EX,data__->RUNBACKSAT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSAT6_EX,data__->RUNBACKSAT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSCT7_EX,data__->RUNBACKSCT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKCT7_EX,data__->RUNBACKCT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKCT8_EX,data__->RUNBACKCT8_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKCT9_EX,data__->RUNBACKCT9_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTAT1_EX,data__->RUNFRONTAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT1_EX,data__->RUNFRONTSAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT2_EX,data__->RUNFRONTSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT3_EX,data__->RUNFRONTSAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT4_EX,data__->RUNFRONTSAT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT5_EX,data__->RUNFRONTSAT5_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT1_EX,data__->RUNFRONTSBT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT2_EX,data__->RUNFRONTSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT1_EX,data__->RUNFRONTSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT2_EX,data__->RUNFRONTSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT1_EX,data__->RUNFRONTMT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT2_EX,data__->RUNFRONTMT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT1_EX,data__->RUNFRONTCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT2_EX,data__->RUNFRONTCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT3_EX,data__->RUNFRONTCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT4_EX,data__->RUNFRONTCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT5_EX,data__->RUNFRONTCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT6_EX,data__->RUNFRONTCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT8_EX,data__->RUNFRONTCT8_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKCT2_EX,data__->RUNBACKCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKCT3_EX,data__->RUNBACKCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSAT2_EX,data__->SENDDOWNSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSBT2_EX,data__->SENDDOWNSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSCT2_EX,data__->SENDDOWNSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNMT2_EX,data__->SENDDOWNMT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNCT2_EX,data__->SENDDOWNCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNCT8_EX,data__->SENDDOWNCT8_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNSAT6_EX,data__->SENDLEFTDOWNSAT6_EX,retain)
  ROTARYCONVEYOR_init__(&data__->SBT2,retain);
  __INIT_LOCATED(BOOL,__QX0_0_1_0,data__->BACKAT1,retain)
  __INIT_LOCATED_VALUE(data__->BACKAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_2,data__->BACKAT2,retain)
  __INIT_LOCATED_VALUE(data__->BACKAT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_7,data__->BACKSAT2,retain)
  __INIT_LOCATED_VALUE(data__->BACKSAT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_31,data__->BACKSAT6,retain)
  __INIT_LOCATED_VALUE(data__->BACKSAT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_39,data__->BACKSBT2,retain)
  __INIT_LOCATED_VALUE(data__->BACKSBT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_63,data__->BACKSBT6,retain)
  __INIT_LOCATED_VALUE(data__->BACKSBT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_71,data__->BACKSCT2,retain)
  __INIT_LOCATED_VALUE(data__->BACKSCT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_95,data__->BACKSCT6,retain)
  __INIT_LOCATED_VALUE(data__->BACKSCT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_103,data__->BACKMT2,retain)
  __INIT_LOCATED_VALUE(data__->BACKMT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_113,data__->BACKMT6,retain)
  __INIT_LOCATED_VALUE(data__->BACKMT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_126,data__->BACKCT2,retain)
  __INIT_LOCATED_VALUE(data__->BACKCT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_146,data__->BACKCT8,retain)
  __INIT_LOCATED_VALUE(data__->BACKCT8,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_132,data__->BACKCT4,retain)
  __INIT_LOCATED_VALUE(data__->BACKCT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_136,data__->BACKCT5,retain)
  __INIT_LOCATED_VALUE(data__->BACKCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_140,data__->BACKCT6,retain)
  __INIT_LOCATED_VALUE(data__->BACKCT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_11,data__->BACKSAT3,retain)
  __INIT_LOCATED_VALUE(data__->BACKSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_22,data__->BACKSAT5,retain)
  __INIT_LOCATED_VALUE(data__->BACKSAT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_43,data__->BACKSBT3,retain)
  __INIT_LOCATED_VALUE(data__->BACKSBT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_54,data__->BACKSBT5,retain)
  __INIT_LOCATED_VALUE(data__->BACKSBT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_75,data__->BACKSCT3,retain)
  __INIT_LOCATED_VALUE(data__->BACKSCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_86,data__->BACKSCT5,retain)
  __INIT_LOCATED_VALUE(data__->BACKSCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_5,data__->BACKSAT1,retain)
  __INIT_LOCATED_VALUE(data__->BACKSAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_20,data__->BACKSAT4,retain)
  __INIT_LOCATED_VALUE(data__->BACKSAT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_35,data__->BACKSAT7,retain)
  __INIT_LOCATED_VALUE(data__->BACKSAT7,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_37,data__->BACKSBT1,retain)
  __INIT_LOCATED_VALUE(data__->BACKSBT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_52,data__->BACKSBT4,retain)
  __INIT_LOCATED_VALUE(data__->BACKSBT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_67,data__->BACKSBT7,retain)
  __INIT_LOCATED_VALUE(data__->BACKSBT7,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_69,data__->BACKSCT1,retain)
  __INIT_LOCATED_VALUE(data__->BACKSCT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_84,data__->BACKSCT4,retain)
  __INIT_LOCATED_VALUE(data__->BACKSCT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_99,data__->BACKSCT7,retain)
  __INIT_LOCATED_VALUE(data__->BACKSCT7,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_101,data__->BACKMT1,retain)
  __INIT_LOCATED_VALUE(data__->BACKMT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_107,data__->BACKMT3,retain)
  __INIT_LOCATED_VALUE(data__->BACKMT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_109,data__->BACKMT4,retain)
  __INIT_LOCATED_VALUE(data__->BACKMT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_111,data__->BACKMT5,retain)
  __INIT_LOCATED_VALUE(data__->BACKMT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_124,data__->BACKCT1,retain)
  __INIT_LOCATED_VALUE(data__->BACKCT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_130,data__->BACKCT3,retain)
  __INIT_LOCATED_VALUE(data__->BACKCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_144,data__->BACKCT7,retain)
  __INIT_LOCATED_VALUE(data__->BACKCT7,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_150,data__->BACKCT9,retain)
  __INIT_LOCATED_VALUE(data__->BACKCT9,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_0,data__->SENSORAT1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_1,data__->SENSORAT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORAT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_76,data__->SENSORMM1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORMM1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_77,data__->SENSORMM2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORMM2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_78,data__->SENSORMM3,retain)
  __INIT_LOCATED_VALUE(data__->SENSORMM3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_3,data__->SENSORSAT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSAT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_19,data__->SENSORSAT6,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSAT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_24,data__->SENSORSBT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSBT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_40,data__->SENSORSBT6,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSBT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_45,data__->SENSORSCT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSCT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_61,data__->SENSORSCT6,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSCT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_66,data__->SENSORMT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORMT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_73,data__->SENSORMT6,retain)
  __INIT_LOCATED_VALUE(data__->SENSORMT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_90,data__->SENSORCT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORCT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_104,data__->SENSORCT8,retain)
  __INIT_LOCATED_VALUE(data__->SENSORCT8,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_108,data__->SENSORPM1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORPM1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_109,data__->SENSORPM2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORPM2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_110,data__->SENSORPM3,retain)
  __INIT_LOCATED_VALUE(data__->SENSORPM3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_94,data__->SENSORCT4,retain)
  __INIT_LOCATED_VALUE(data__->SENSORCT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_97,data__->SENSORCT5,retain)
  __INIT_LOCATED_VALUE(data__->SENSORCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_100,data__->SENSORCT6,retain)
  __INIT_LOCATED_VALUE(data__->SENSORCT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_6,data__->SENSORSAT3,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_13,data__->SENSORSAT5,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSAT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_27,data__->SENSORSBT3,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSBT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_34,data__->SENSORSBT5,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSBT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_48,data__->SENSORSCT3,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_55,data__->SENSORSCT5,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_2,data__->SENSORSAT1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_12,data__->SENSORSAT4,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSAT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_22,data__->SENSORSAT7,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSAT7,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_23,data__->SENSORSBT1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSBT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_33,data__->SENSORSBT4,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSBT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_43,data__->SENSORSBT7,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSBT7,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_44,data__->SENSORSCT1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSCT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_54,data__->SENSORSCT4,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSCT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_64,data__->SENSORSCT7,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSCT7,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_65,data__->SENSORMT1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORMT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_69,data__->SENSORMT3,retain)
  __INIT_LOCATED_VALUE(data__->SENSORMT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_71,data__->SENSORMT4,retain)
  __INIT_LOCATED_VALUE(data__->SENSORMT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_72,data__->SENSORMT5,retain)
  __INIT_LOCATED_VALUE(data__->SENSORMT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_89,data__->SENSORCT1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORCT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_93,data__->SENSORCT3,retain)
  __INIT_LOCATED_VALUE(data__->SENSORCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_103,data__->SENSORCT7,retain)
  __INIT_LOCATED_VALUE(data__->SENSORCT7,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_107,data__->SENSORCT9,retain)
  __INIT_LOCATED_VALUE(data__->SENSORCT9,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_135,data__->PUSHFORWARDCT4,retain)
  __INIT_LOCATED_VALUE(data__->PUSHFORWARDCT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_139,data__->PUSHFORWARDCT5,retain)
  __INIT_LOCATED_VALUE(data__->PUSHFORWARDCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_143,data__->PUSHFORWARDCT6,retain)
  __INIT_LOCATED_VALUE(data__->PUSHFORWARDCT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_96,data__->SENSORPUSHFORWARDCT4,retain)
  __INIT_LOCATED_VALUE(data__->SENSORPUSHFORWARDCT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_99,data__->SENSORPUSHFORWARDCT5,retain)
  __INIT_LOCATED_VALUE(data__->SENSORPUSHFORWARDCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_102,data__->SENSORPUSHFORWARDCT6,retain)
  __INIT_LOCATED_VALUE(data__->SENSORPUSHFORWARDCT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_134,data__->PUSHBACKCT4,retain)
  __INIT_LOCATED_VALUE(data__->PUSHBACKCT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_138,data__->PUSHBACKCT5,retain)
  __INIT_LOCATED_VALUE(data__->PUSHBACKCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_142,data__->PUSHBACKCT6,retain)
  __INIT_LOCATED_VALUE(data__->PUSHBACKCT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_95,data__->SENSORPUSHBACKCT4,retain)
  __INIT_LOCATED_VALUE(data__->SENSORPUSHBACKCT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_98,data__->SENSORPUSHBACKCT5,retain)
  __INIT_LOCATED_VALUE(data__->SENSORPUSHBACKCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_101,data__->SENSORPUSHBACKCT6,retain)
  __INIT_LOCATED_VALUE(data__->SENSORPUSHBACKCT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_1,data__->FORWARDAT1,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_3,data__->FORWARDAT2,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDAT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_8,data__->FORWARDSAT2,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSAT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_32,data__->FORWARDSAT6,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSAT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_40,data__->FORWARDSBT2,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSBT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_64,data__->FORWARDSBT6,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSBT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_72,data__->FORWARDSCT2,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSCT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_96,data__->FORWARDSCT6,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSCT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_104,data__->FORWARDMT2,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDMT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_114,data__->FORWARDMT6,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDMT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_127,data__->FORWARDCT2,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDCT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_147,data__->FORWARDCT8,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDCT8,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_133,data__->FORWARDCT4,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDCT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_137,data__->FORWARDCT5,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_141,data__->FORWARDCT6,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDCT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_12,data__->FORWARDSAT3,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_23,data__->FORWARDSAT5,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSAT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_44,data__->FORWARDSBT3,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSBT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_55,data__->FORWARDSBT5,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSBT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_76,data__->FORWARDSCT3,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_87,data__->FORWARDSCT5,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_6,data__->FORWARDSAT1,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_21,data__->FORWARDSAT4,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSAT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_36,data__->FORWARDSAT7,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSAT7,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_38,data__->FORWARDSBT1,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSBT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_53,data__->FORWARDSBT4,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSBT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_68,data__->FORWARDSBT7,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSBT7,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_70,data__->FORWARDSCT1,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSCT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_85,data__->FORWARDSCT4,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSCT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_100,data__->FORWARDSCT7,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSCT7,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_102,data__->FORWARDMT1,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDMT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_108,data__->FORWARDMT3,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDMT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_110,data__->FORWARDMT4,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDMT4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_112,data__->FORWARDMT5,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDMT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_125,data__->FORWARDCT1,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDCT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_131,data__->FORWARDCT3,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_145,data__->FORWARDCT7,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDCT7,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_151,data__->FORWARDCT9,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDCT9,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_5,data__->SENSORROTRIGHTSAT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTRIGHTSAT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_21,data__->SENSORROTRIGHTSAT6,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTRIGHTSAT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_26,data__->SENSORROTRIGHTSBT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTRIGHTSBT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_42,data__->SENSORROTRIGHTSBT6,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTRIGHTSBT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_47,data__->SENSORROTRIGHTSCT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTRIGHTSCT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_63,data__->SENSORROTRIGHTSCT6,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTRIGHTSCT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_68,data__->SENSORROTRIGHTMT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTRIGHTMT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_75,data__->SENSORROTRIGHTMT6,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTRIGHTMT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_92,data__->SENSORROTRIGHTCT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTRIGHTCT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_106,data__->SENSORROTRIGHTCT8,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTRIGHTCT8,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_4,data__->SENSORROTLEFTSAT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTLEFTSAT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_20,data__->SENSORROTLEFTSAT6,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTLEFTSAT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_25,data__->SENSORROTLEFTSBT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTLEFTSBT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_41,data__->SENSORROTLEFTSBT6,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTLEFTSBT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_46,data__->SENSORROTLEFTSCT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTLEFTSCT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_62,data__->SENSORROTLEFTSCT6,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTLEFTSCT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_67,data__->SENSORROTLEFTMT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTLEFTMT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_74,data__->SENSORROTLEFTMT6,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTLEFTMT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_91,data__->SENSORROTLEFTCT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTLEFTCT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_105,data__->SENSORROTLEFTCT8,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTLEFTCT8,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_10,data__->RIGHTROTSAT2,retain)
  __INIT_LOCATED_VALUE(data__->RIGHTROTSAT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_34,data__->RIGHTROTSAT6,retain)
  __INIT_LOCATED_VALUE(data__->RIGHTROTSAT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_42,data__->RIGHTROTSBT2,retain)
  __INIT_LOCATED_VALUE(data__->RIGHTROTSBT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_66,data__->RIGHTROTSBT6,retain)
  __INIT_LOCATED_VALUE(data__->RIGHTROTSBT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_74,data__->RIGHTROTSCT2,retain)
  __INIT_LOCATED_VALUE(data__->RIGHTROTSCT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_98,data__->RIGHTROTSCT6,retain)
  __INIT_LOCATED_VALUE(data__->RIGHTROTSCT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_106,data__->RIGHTROTMT2,retain)
  __INIT_LOCATED_VALUE(data__->RIGHTROTMT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_116,data__->RIGHTROTMT6,retain)
  __INIT_LOCATED_VALUE(data__->RIGHTROTMT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_129,data__->RIGHTROTCT2,retain)
  __INIT_LOCATED_VALUE(data__->RIGHTROTCT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_149,data__->RIGHTROTCT8,retain)
  __INIT_LOCATED_VALUE(data__->RIGHTROTCT8,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_9,data__->LEFTROTSAT2,retain)
  __INIT_LOCATED_VALUE(data__->LEFTROTSAT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_33,data__->LEFTROTSAT6,retain)
  __INIT_LOCATED_VALUE(data__->LEFTROTSAT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_41,data__->LEFTROTSBT2,retain)
  __INIT_LOCATED_VALUE(data__->LEFTROTSBT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_65,data__->LEFTROTSBT6,retain)
  __INIT_LOCATED_VALUE(data__->LEFTROTSBT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_73,data__->LEFTROTSCT2,retain)
  __INIT_LOCATED_VALUE(data__->LEFTROTSCT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_97,data__->LEFTROTSCT6,retain)
  __INIT_LOCATED_VALUE(data__->LEFTROTSCT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_105,data__->LEFTROTMT2,retain)
  __INIT_LOCATED_VALUE(data__->LEFTROTMT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_115,data__->LEFTROTMT6,retain)
  __INIT_LOCATED_VALUE(data__->LEFTROTMT6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_128,data__->LEFTROTCT2,retain)
  __INIT_LOCATED_VALUE(data__->LEFTROTCT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_148,data__->LEFTROTCT8,retain)
  __INIT_LOCATED_VALUE(data__->LEFTROTCT8,__BOOL_LITERAL(FALSE))
  LINEARCONVEYOR_init__(&data__->SCT1,retain);
  ROTARYCONVEYOR_init__(&data__->SCT2,retain);
  LINEARCONVEYOR_init__(&data__->MT1,retain);
  ROTARYCONVEYOR_init__(&data__->MT2,retain);
  LINEARCONVEYOR_init__(&data__->CT1,retain);
  ROTARYCONVEYOR_init__(&data__->CT2,retain);
  LINEARCONVEYOR_init__(&data__->CT3,retain);
  WAREHOUSEINCONVEYOR_init__(&data__->AT2,retain);
  LINEARCONVEYOR_init__(&data__->SAT7,retain);
  LINEARCONVEYOR_init__(&data__->SBT7,retain);
  ROTARYCONVEYOR_init__(&data__->SBT6,retain);
  LINEARCONVEYOR_init__(&data__->SCT7,retain);
  ROTARYCONVEYOR_init__(&data__->SAT6,retain);
  ROTARYCONVEYOR_init__(&data__->SCT6,retain);
  LINEARCONVEYOR_init__(&data__->MT5,retain);
  ROTARYCONVEYOR_init__(&data__->MT6,retain);
  LINEARCONVEYOR_init__(&data__->CT7,retain);
  ROTARYCONVEYOR_init__(&data__->CT8,retain);
  LINEARCONVEYOR_init__(&data__->CT9,retain);
  __INIT_EXTERNAL(BOOL,SENDUPSAT6_EX,data__->SENDUPSAT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT7_EX,data__->SENSORSBT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSBT7_EX,data__->RUNBACKSBT7_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT6_EX,data__->SENSORSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT6_EX,data__->RUNFRONTSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSBT6_EX,data__->SENDDOWNSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSAT6_EX,data__->SENDDOWNSAT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSBT6_EX,data__->RUNBACKSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT6_EX,data__->SENSORSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT6_EX,data__->RUNFRONTSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSCT6_EX,data__->RUNBACKSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKMT6_EX,data__->RUNBACKMT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSCT6_EX,data__->SENDDOWNSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNMT6_EX,data__->SENDDOWNMT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT5_EX,data__->SENSORMT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT6_EX,data__->SENSORMT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKMT5_EX,data__->RUNBACKMT5_EX,retain)
  __INIT_EXTERNAL(BOOL,PUSHTOROLLCT4_EX,data__->PUSHTOROLLCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,PUSHTOROLLCT5_EX,data__->PUSHTOROLLCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,PUSHTOROLLCT6_EX,data__->PUSHTOROLLCT6_EX,retain)
  PUSHER_init__(&data__->CT4,retain);
  PUSHER_init__(&data__->CT5,retain);
  PUSHER_init__(&data__->CT6,retain);
  ROLL_init__(&data__->PM1,retain);
  ROLL_init__(&data__->PM2,retain);
  ROLL_init__(&data__->PM3,retain);
  MACHINE_init__(&data__->SAT3,retain);
  __INIT_LOCATED(BOOL,__IX0_0_0_7,data__->TOOLSENSORSAT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLSENSORSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_14,data__->TOOLSENSORSAT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLSENSORSAT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_28,data__->TOOLSENSORSBT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLSENSORSBT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_35,data__->TOOLSENSORSBT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLSENSORSBT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_49,data__->TOOLSENSORSCT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLSENSORSCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_56,data__->TOOLSENSORSCT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLSENSORSCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_16,data__->XRIGHTSAT3,retain)
  __INIT_LOCATED_VALUE(data__->XRIGHTSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_4,data__->WAREHOUSEIN,retain)
  __INIT_LOCATED_VALUE(data__->WAREHOUSEIN,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_17,data__->XLEFTSAT3,retain)
  __INIT_LOCATED_VALUE(data__->XLEFTSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_18,data__->ZUPSAT3,retain)
  __INIT_LOCATED_VALUE(data__->ZUPSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_19,data__->ZDOWNSAT3,retain)
  __INIT_LOCATED_VALUE(data__->ZDOWNSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_27,data__->XRIGHTSAT5,retain)
  __INIT_LOCATED_VALUE(data__->XRIGHTSAT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_28,data__->XLEFTSAT5,retain)
  __INIT_LOCATED_VALUE(data__->XLEFTSAT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_29,data__->ZUPSAT5,retain)
  __INIT_LOCATED_VALUE(data__->ZUPSAT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_30,data__->ZDOWNSAT5,retain)
  __INIT_LOCATED_VALUE(data__->ZDOWNSAT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_48,data__->XRIGHTSBT3,retain)
  __INIT_LOCATED_VALUE(data__->XRIGHTSBT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_49,data__->XLEFTSBT3,retain)
  __INIT_LOCATED_VALUE(data__->XLEFTSBT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_50,data__->ZUPSBT3,retain)
  __INIT_LOCATED_VALUE(data__->ZUPSBT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_51,data__->ZDOWNSBT3,retain)
  __INIT_LOCATED_VALUE(data__->ZDOWNSBT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_59,data__->XRIGHTSBT5,retain)
  __INIT_LOCATED_VALUE(data__->XRIGHTSBT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_60,data__->XLEFTSBT5,retain)
  __INIT_LOCATED_VALUE(data__->XLEFTSBT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_61,data__->ZUPSBT5,retain)
  __INIT_LOCATED_VALUE(data__->ZUPSBT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_62,data__->ZDOWNSBT5,retain)
  __INIT_LOCATED_VALUE(data__->ZDOWNSBT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_80,data__->XRIGHTSCT3,retain)
  __INIT_LOCATED_VALUE(data__->XRIGHTSCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_81,data__->XLEFTSCT3,retain)
  __INIT_LOCATED_VALUE(data__->XLEFTSCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_82,data__->ZUPSCT3,retain)
  __INIT_LOCATED_VALUE(data__->ZUPSCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_83,data__->ZDOWNSCT3,retain)
  __INIT_LOCATED_VALUE(data__->ZDOWNSCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_91,data__->XRIGHTSCT5,retain)
  __INIT_LOCATED_VALUE(data__->XRIGHTSCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_92,data__->XLEFTSCT5,retain)
  __INIT_LOCATED_VALUE(data__->XLEFTSCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_93,data__->ZUPSCT5,retain)
  __INIT_LOCATED_VALUE(data__->ZUPSCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_94,data__->ZDOWNSCT5,retain)
  __INIT_LOCATED_VALUE(data__->ZDOWNSCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_13,data__->TOOLMINUSSAT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLMINUSSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_14,data__->TOOLPLUSSAT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLPLUSSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_24,data__->TOOLMINUSSAT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLMINUSSAT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_25,data__->TOOLPLUSSAT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLPLUSSAT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_45,data__->TOOLMINUSSBT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLMINUSSBT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_46,data__->TOOLPLUSSBT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLPLUSSBT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_56,data__->TOOLMINUSSBT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLMINUSSBT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_57,data__->TOOLPLUSSBT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLPLUSSBT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_77,data__->TOOLMINUSSCT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLMINUSSCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_78,data__->TOOLPLUSSCT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLPLUSSCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_88,data__->TOOLMINUSSCT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLMINUSSCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_89,data__->TOOLPLUSSCT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLPLUSSCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_10,data__->TOOLUPSENSORSAT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLUPSENSORSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_17,data__->TOOLUPSENSORSAT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLUPSENSORSAT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_31,data__->TOOLUPSENSORSBT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLUPSENSORSBT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_38,data__->TOOLUPSENSORSBT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLUPSENSORSBT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_52,data__->TOOLUPSENSORSCT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLUPSENSORSCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_59,data__->TOOLUPSENSORSCT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLUPSENSORSCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_11,data__->TOOLDOWNSENSORSAT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLDOWNSENSORSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_18,data__->TOOLDOWNSENSORSAT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLDOWNSENSORSAT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_32,data__->TOOLDOWNSENSORSBT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLDOWNSENSORSBT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_39,data__->TOOLDOWNSENSORSBT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLDOWNSENSORSBT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_53,data__->TOOLDOWNSENSORSCT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLDOWNSENSORSCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_60,data__->TOOLDOWNSENSORSCT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLDOWNSENSORSCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_8,data__->TOOLLEFTSENSORSAT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLLEFTSENSORSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_15,data__->TOOLLEFTSENSORSAT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLLEFTSENSORSAT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_29,data__->TOOLLEFTSENSORSBT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLLEFTSENSORSBT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_36,data__->TOOLLEFTSENSORSBT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLLEFTSENSORSBT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_50,data__->TOOLLEFTSENSORSCT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLLEFTSENSORSCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_57,data__->TOOLLEFTSENSORSCT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLLEFTSENSORSCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_9,data__->TOOLRIGHTSENSORSAT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLRIGHTSENSORSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_16,data__->TOOLRIGHTSENSORSAT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLRIGHTSENSORSAT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_30,data__->TOOLRIGHTSENSORSBT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLRIGHTSENSORSBT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_37,data__->TOOLRIGHTSENSORSBT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLRIGHTSENSORSBT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_51,data__->TOOLRIGHTSENSORSCT3,retain)
  __INIT_LOCATED_VALUE(data__->TOOLRIGHTSENSORSCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_58,data__->TOOLRIGHTSENSORSCT5,retain)
  __INIT_LOCATED_VALUE(data__->TOOLRIGHTSENSORSCT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_15,data__->USETOOLSAT3,retain)
  __INIT_LOCATED_VALUE(data__->USETOOLSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_26,data__->USETOOLSAT5,retain)
  __INIT_LOCATED_VALUE(data__->USETOOLSAT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_47,data__->USETOOLSBT3,retain)
  __INIT_LOCATED_VALUE(data__->USETOOLSBT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_58,data__->USETOOLSBT5,retain)
  __INIT_LOCATED_VALUE(data__->USETOOLSBT5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_79,data__->USETOOLSCT3,retain)
  __INIT_LOCATED_VALUE(data__->USETOOLSCT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_90,data__->USETOOLSCT5,retain)
  __INIT_LOCATED_VALUE(data__->USETOOLSCT5,__BOOL_LITERAL(FALSE))
  __INIT_EXTERNAL(BOOL,TOOLPIECESAT3_EX,data__->TOOLPIECESAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESAT5_EX,data__->TOOLPIECESAT5_EX,retain)
  LINEARCONVEYOR_init__(&data__->SAT4,retain);
  MACHINE_init__(&data__->SAT5,retain);
  __INIT_EXTERNAL(BOOL,READYTOSENDSAT3_EX,data__->READYTOSENDSAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSAT5_EX,data__->READYTOSENDSAT5_EX,retain)
  __INIT_EXTERNAL(BOOL,PUTPIECEINSIGNAL_EX,data__->PUTPIECEINSIGNAL_EX,retain)
  __INIT_LOCATED(INT,__IW0_1_1_0,data__->INITIALPIECE,retain)
  __INIT_LOCATED_VALUE(data__->INITIALPIECE,1)
  __INIT_LOCATED(INT,__IW0_1_1_3,data__->FINALPIECE,retain)
  __INIT_LOCATED_VALUE(data__->FINALPIECE,7)
  __INIT_VAR(data__->OR210_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OR209_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_EXTERNAL(data__->,SENSORSAT1_EX,,__GET_LOCATED(data__->SENSORSAT1,));
  __SET_EXTERNAL(data__->,SENSORSAT2_EX,,__GET_LOCATED(data__->SENSORSAT2,));
  __SET_EXTERNAL(data__->,SENSORSBT2_EX,,__GET_LOCATED(data__->SENSORSBT2,));
  __SET_EXTERNAL(data__->,SENSORSCT1_EX,,__GET_LOCATED(data__->SENSORSCT1,));
  __SET_EXTERNAL(data__->,SENSORSCT2_EX,,__GET_LOCATED(data__->SENSORSCT2,));
  __SET_EXTERNAL(data__->,SENSORAT1_EX,,__GET_LOCATED(data__->SENSORAT1,));
  __SET_EXTERNAL(data__->,SENSORSBT1_EX,,__GET_LOCATED(data__->SENSORSBT1,));
  __SET_EXTERNAL(data__->,SENSORMT1_EX,,__GET_LOCATED(data__->SENSORMT1,));
  __SET_EXTERNAL(data__->,SENSORCT2_EX,,__GET_LOCATED(data__->SENSORCT2,));
  __SET_EXTERNAL(data__->,SENSORCT3_EX,,__GET_LOCATED(data__->SENSORCT3,));
  __SET_EXTERNAL(data__->,SENSORMT2_EX,,__GET_LOCATED(data__->SENSORMT2,));
  __SET_EXTERNAL(data__->,SENSORCT1_EX,,__GET_LOCATED(data__->SENSORCT1,));
  __SET_VAR(data__->PM1.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORPM1,));
  ROLL_body__(&data__->PM1);
  __SET_VAR(data__->PM2.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORPM2,));
  ROLL_body__(&data__->PM2);
  __SET_VAR(data__->PM3.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORPM3,));
  ROLL_body__(&data__->PM3);
  __SET_VAR(data__->CT6.,ROLLBUSY,,__GET_VAR(data__->PM3.HASPIECE,));
  __SET_VAR(data__->CT6.,PUSHSIGNAL,,__GET_EXTERNAL(data__->PUSHTOROLLCT6_EX,));
  __SET_VAR(data__->CT6.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTCT6_EX,));
  __SET_VAR(data__->CT6.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT6,));
  __SET_VAR(data__->CT6.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORCT8,));
  __SET_VAR(data__->CT6.,SENSORPUSHFORWARD,,__GET_LOCATED(data__->SENSORPUSHFORWARDCT6,));
  __SET_VAR(data__->CT6.,SENSORPUSHBACK,,__GET_LOCATED(data__->SENSORPUSHBACKCT6,));
  PUSHER_body__(&data__->CT6);
  __SET_VAR(data__->CT5.,ROLLBUSY,,__GET_VAR(data__->PM2.HASPIECE,));
  __SET_VAR(data__->CT5.,PUSHSIGNAL,,__GET_EXTERNAL(data__->PUSHTOROLLCT5_EX,));
  __SET_VAR(data__->CT5.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTCT5_EX,));
  __SET_VAR(data__->CT5.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT5,));
  __SET_VAR(data__->CT5.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORCT6,));
  __SET_VAR(data__->CT5.,SENSORPUSHFORWARD,,__GET_LOCATED(data__->SENSORPUSHFORWARDCT5,));
  __SET_VAR(data__->CT5.,SENSORPUSHBACK,,__GET_LOCATED(data__->SENSORPUSHBACKCT5,));
  __SET_VAR(data__->CT5.,FRONTNOTBUSY,,__GET_VAR(data__->CT6.ISBUSY,));
  PUSHER_body__(&data__->CT5);
  __SET_VAR(data__->CT4.,ROLLBUSY,,__GET_VAR(data__->PM1.HASPIECE,));
  __SET_VAR(data__->CT4.,PUSHSIGNAL,,__GET_EXTERNAL(data__->PUSHTOROLLCT4_EX,));
  __SET_VAR(data__->CT4.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTCT4_EX,));
  __SET_VAR(data__->CT4.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT4,));
  __SET_VAR(data__->CT4.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORCT5,));
  __SET_VAR(data__->CT4.,SENSORPUSHFORWARD,,__GET_LOCATED(data__->SENSORPUSHFORWARDCT4,));
  __SET_VAR(data__->CT4.,SENSORPUSHBACK,,__GET_LOCATED(data__->SENSORPUSHBACKCT4,));
  __SET_VAR(data__->CT4.,FRONTNOTBUSY,,__GET_VAR(data__->CT5.ISBUSY,));
  PUSHER_body__(&data__->CT4);
  __SET_VAR(data__->CT2.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKCT2_EX,));
  __SET_VAR(data__->CT2.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTCT2_EX,));
  __SET_VAR(data__->CT2.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNCT2_EX,));
  __SET_VAR(data__->CT2.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTCT2,));
  __SET_VAR(data__->CT2.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTCT2,));
  __SET_VAR(data__->CT2.,DOWNNOTBUSY,,__GET_VAR(data__->CT4.ISBUSY,));
  __SET_VAR(data__->CT2.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT2,));
  __SET_VAR(data__->CT2.,REACHEDSENSORDOWN,,__GET_LOCATED(data__->SENSORCT4,));
  ROTARYCONVEYOR_body__(&data__->CT2);
  __SET_VAR(data__->CT1.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT1,));
  __SET_VAR(data__->CT1.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTCT1_EX,));
  __SET_VAR(data__->CT1.,FRONTNOTBUSY,,__GET_VAR(data__->CT2.ISBUSY,));
  __SET_VAR(data__->CT1.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORCT2,));
  LINEARCONVEYOR_body__(&data__->CT1);
  __SET_VAR(data__->MT2.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTMT2_EX,));
  __SET_VAR(data__->MT2.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNMT2_EX,));
  __SET_VAR(data__->MT2.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTMT2,));
  __SET_VAR(data__->MT2.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTMT2,));
  __SET_VAR(data__->MT2.,FRONTNOTBUSY,,__GET_VAR(data__->CT1.ISBUSY,));
  __SET_VAR(data__->MT2.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORCT1,));
  __SET_VAR(data__->MT2.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORMT2,));
  ROTARYCONVEYOR_body__(&data__->MT2);
  __SET_VAR(data__->MT1.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORMT1,));
  __SET_VAR(data__->MT1.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTMT1_EX,));
  __SET_VAR(data__->MT1.,FRONTNOTBUSY,,__GET_VAR(data__->MT2.ISBUSY,));
  __SET_VAR(data__->MT1.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORMT2,));
  LINEARCONVEYOR_body__(&data__->MT1);
  __SET_VAR(data__->SCT2.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSCT2_EX,));
  __SET_VAR(data__->SCT2.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNSCT2_EX,));
  __SET_VAR(data__->SCT2.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTSCT2,));
  __SET_VAR(data__->SCT2.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTSCT2,));
  __SET_VAR(data__->SCT2.,FRONTNOTBUSY,,__GET_VAR(data__->MT1.ISBUSY,));
  __SET_VAR(data__->SCT2.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORMT1,));
  __SET_VAR(data__->SCT2.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSCT2,));
  ROTARYCONVEYOR_body__(&data__->SCT2);
  __SET_VAR(data__->SCT1.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSCT1,));
  __SET_VAR(data__->SCT1.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSBT1_EX,));
  __SET_VAR(data__->SCT1.,FRONTNOTBUSY,,__GET_VAR(data__->SCT2.ISBUSY,));
  __SET_VAR(data__->SCT1.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSCT2,));
  LINEARCONVEYOR_body__(&data__->SCT1);
  __SET_VAR(data__->SBT2.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSBT2_EX,));
  __SET_VAR(data__->SBT2.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNSBT2_EX,));
  __SET_VAR(data__->SBT2.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTSBT2,));
  __SET_VAR(data__->SBT2.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTSBT2,));
  __SET_VAR(data__->SBT2.,FRONTNOTBUSY,,__GET_VAR(data__->SCT1.ISBUSY,));
  __SET_VAR(data__->SBT2.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSCT1,));
  __SET_VAR(data__->SBT2.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSBT2,));
  ROTARYCONVEYOR_body__(&data__->SBT2);
  __SET_VAR(data__->SBT1.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSBT1,));
  __SET_VAR(data__->SBT1.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSBT1_EX,));
  __SET_VAR(data__->SBT1.,FRONTNOTBUSY,,__GET_VAR(data__->SBT2.ISBUSY,));
  __SET_VAR(data__->SBT1.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSBT2,));
  LINEARCONVEYOR_body__(&data__->SBT1);
  __SET_VAR(data__->AT2.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORAT2,));
  __SET_VAR(data__->AT2.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKAT2_EX,));
  __SET_VAR(data__->AT2.,WAREHOUSEBUSY,,__GET_EXTERNAL(data__->WAREHOUSEBUSY,));
  __SET_VAR(data__->AT2.,PUTPIECEINSIGNAL,,__GET_EXTERNAL(data__->PUTPIECEINSIGNAL_EX,));
  WAREHOUSEINCONVEYOR_body__(&data__->AT2);
  __SET_VAR(data__->SAT7.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSAT7,));
  __SET_VAR(data__->SAT7.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKSAT7_EX,));
  __SET_VAR(data__->SAT7.,BACKNOTBUSY,,__GET_VAR(data__->AT2.ISBUSY,));
  __SET_VAR(data__->SAT7.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSAT6,));
  __SET_VAR(data__->SAT7.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORAT2,));
  LINEARCONVEYOR_body__(&data__->SAT7);
  __SET_VAR(data__->SAT6.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKSAT6_EX,));
  __SET_VAR(data__->SAT6.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNSAT6_EX,));
  __SET_VAR(data__->SAT6.,SENDLEFTDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDLEFTDOWNSAT6_EX,));
  __SET_VAR(data__->SAT6.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTSAT6,));
  __SET_VAR(data__->SAT6.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTSAT6,));
  __SET_VAR(data__->SAT6.,BACKNOTBUSY,,__GET_VAR(data__->SAT7.ISBUSY,));
  __SET_VAR(data__->SAT6.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSBT7,));
  __SET_VAR(data__->SAT6.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSAT6,));
  __SET_VAR(data__->SAT6.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORSAT7,));
  ROTARYCONVEYOR_body__(&data__->SAT6);
  __SET_VAR(data__->SAT5.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSAT5,));
  __SET_VAR(data__->SAT5.,INITIALPIECE,,__GET_VAR(data__->SAT3.CURRENTPIECE,));
  __SET_VAR(data__->SAT5.,FINALPIECE,,__GET_LOCATED(data__->FINALPIECE,));
  __SET_VAR(data__->SAT5.,NEXTREADYTORECEIVE,,__GET_VAR(data__->SAT6.READYTORECEIVE,));
  __SET_VAR(data__->SAT5.,TOOLPIECE,,__GET_EXTERNAL(data__->TOOLPIECESAT5_EX,));
  __SET_VAR(data__->SAT5.,TOOLSENSOR,,__GET_LOCATED(data__->TOOLSENSORSAT5,));
  __SET_VAR(data__->SAT5.,SENSORUP,,__GET_LOCATED(data__->TOOLUPSENSORSAT5,));
  __SET_VAR(data__->SAT5.,SENSORLEFT,,__GET_LOCATED(data__->TOOLLEFTSENSORSAT5,));
  __SET_VAR(data__->SAT5.,SENSORDOWN,,__GET_LOCATED(data__->TOOLDOWNSENSORSAT5,));
  __SET_VAR(data__->SAT5.,SENSORRIGHT,,__GET_LOCATED(data__->TOOLRIGHTSENSORSAT5,));
  __SET_VAR(data__->SAT5.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSAT5_EX,));
  __SET_VAR(data__->SAT5.,FRONTNOTBUSY,,__GET_VAR(data__->SAT6.ISBUSY,));
  __SET_VAR(data__->SAT5.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSAT6,));
  MACHINE_body__(&data__->SAT5);
  __SET_VAR(data__->SAT4.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSAT4,));
  __SET_VAR(data__->SAT4.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSAT4_EX,));
  __SET_VAR(data__->SAT4.,FRONTNOTBUSY,,__GET_VAR(data__->SAT5.ISBUSY,));
  __SET_VAR(data__->SAT4.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSAT5,));
  LINEARCONVEYOR_body__(&data__->SAT4);
  __SET_VAR(data__->SAT3.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSAT3,));
  __SET_VAR(data__->SAT3.,INITIALPIECE,,__GET_LOCATED(data__->INITIALPIECE,));
  __SET_VAR(data__->SAT3.,FINALPIECE,,__GET_LOCATED(data__->FINALPIECE,));
  __SET_VAR(data__->SAT3.,NEXTREADYTORECEIVE,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->SAT3.,TOOLPIECE,,__GET_EXTERNAL(data__->TOOLPIECESAT3_EX,));
  __SET_VAR(data__->SAT3.,TOOLSENSOR,,__GET_LOCATED(data__->TOOLSENSORSAT3,));
  __SET_VAR(data__->SAT3.,SENSORUP,,__GET_LOCATED(data__->TOOLUPSENSORSAT3,));
  __SET_VAR(data__->SAT3.,SENSORLEFT,,__GET_LOCATED(data__->TOOLLEFTSENSORSAT3,));
  __SET_VAR(data__->SAT3.,SENSORDOWN,,__GET_LOCATED(data__->TOOLDOWNSENSORSAT3,));
  __SET_VAR(data__->SAT3.,SENSORRIGHT,,__GET_LOCATED(data__->TOOLRIGHTSENSORSAT3,));
  __SET_VAR(data__->SAT3.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSAT3_EX,));
  __SET_VAR(data__->SAT3.,FRONTNOTBUSY,,__GET_VAR(data__->SAT4.ISBUSY,));
  __SET_VAR(data__->SAT3.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSAT4,));
  MACHINE_body__(&data__->SAT3);
  __SET_VAR(data__->SAT2.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSAT2_EX,));
  __SET_VAR(data__->SAT2.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNSAT2_EX,));
  __SET_VAR(data__->SAT2.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTSAT2,));
  __SET_VAR(data__->SAT2.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTSAT2,));
  __SET_VAR(data__->SAT2.,FRONTNOTBUSY,,__GET_VAR(data__->SBT1.ISBUSY,));
  __SET_VAR(data__->SAT2.,DOWNNOTBUSY,,__GET_VAR(data__->SAT3.ISBUSY,));
  __SET_VAR(data__->SAT2.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSBT1,));
  __SET_VAR(data__->SAT2.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSAT2,));
  __SET_VAR(data__->SAT2.,REACHEDSENSORDOWN,,__GET_LOCATED(data__->SENSORSAT3,));
  ROTARYCONVEYOR_body__(&data__->SAT2);
  __SET_LOCATED(data__->,FORWARDSAT2,,__GET_VAR(data__->SAT2.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDSCT2,,__GET_VAR(data__->SCT2.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDCT2,,__GET_VAR(data__->CT2.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDSBT1,,__GET_VAR(data__->SBT1.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDSBT2,,__GET_VAR(data__->SBT2.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDMT2,,__GET_VAR(data__->MT2.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDCT1,,__GET_VAR(data__->CT1.FORWARDMOTOR,));
  __SET_VAR(data__->SAT1.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSAT1,));
  __SET_VAR(data__->SAT1.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSAT1_EX,));
  __SET_VAR(data__->SAT1.,FRONTNOTBUSY,,__GET_VAR(data__->SAT2.ISBUSY,));
  __SET_VAR(data__->SAT1.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSAT2,));
  LINEARCONVEYOR_body__(&data__->SAT1);
  __SET_VAR(data__->AT1.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORAT1,));
  __SET_VAR(data__->AT1.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTAT1_EX,));
  __SET_VAR(data__->AT1.,FRONTNOTBUSY,,__GET_VAR(data__->SAT1.ISBUSY,));
  __SET_VAR(data__->AT1.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSAT1,));
  LINEARCONVEYOR_body__(&data__->AT1);
  __SET_LOCATED(data__->,FORWARDAT1,,__GET_VAR(data__->AT1.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDSAT1,,__GET_VAR(data__->SAT1.FORWARDMOTOR,));
  __SET_LOCATED(data__->,RIGHTROTSAT2,,__GET_VAR(data__->SAT2.RIGHTROTMOTOR,));
  __SET_LOCATED(data__->,RIGHTROTCT2,,__GET_VAR(data__->CT2.RIGHTROTMOTOR,));
  __SET_LOCATED(data__->,RIGHTROTSBT2,,__GET_VAR(data__->SBT2.RIGHTROTMOTOR,));
  __SET_LOCATED(data__->,RIGHTROTSCT2,,__GET_VAR(data__->SCT2.RIGHTROTMOTOR,));
  __SET_LOCATED(data__->,BACKAT1,,__GET_VAR(data__->AT1.BACKMOTOR,));
  __SET_LOCATED(data__->,BACKSAT1,,__GET_VAR(data__->SAT1.BACKMOTOR,));
  __SET_LOCATED(data__->,RIGHTROTMT2,,__GET_VAR(data__->MT2.RIGHTROTMOTOR,));
  __SET_LOCATED(data__->,LEFTROTSAT2,,__GET_VAR(data__->SAT2.LEFTROTMOTOR,));
  __SET_LOCATED(data__->,LEFTROTCT2,,__GET_VAR(data__->CT2.LEFTROTMOTOR,));
  __SET_LOCATED(data__->,LEFTROTSBT2,,__GET_VAR(data__->SBT2.LEFTROTMOTOR,));
  __SET_LOCATED(data__->,LEFTROTSCT2,,__GET_VAR(data__->SCT2.LEFTROTMOTOR,));
  __SET_LOCATED(data__->,FORWARDMT1,,__GET_VAR(data__->MT1.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDSCT1,,__GET_VAR(data__->SCT1.FORWARDMOTOR,));
  __SET_LOCATED(data__->,LEFTROTMT2,,__GET_VAR(data__->MT2.LEFTROTMOTOR,));
  __SET_EXTERNAL(data__->,SENSORSAT3_EX,,__GET_LOCATED(data__->SENSORSAT3,));
  __SET_LOCATED(data__->,USETOOLSAT3,,__GET_VAR(data__->SAT3.USETOOL,));
  __SET_LOCATED(data__->,TOOLPLUSSAT3,,__GET_VAR(data__->SAT3.TOOLPLUS,));
  __SET_LOCATED(data__->,TOOLMINUSSAT3,,__GET_VAR(data__->SAT3.TOOLMINUS,));
  __SET_EXTERNAL(data__->,READYTOSENDSAT3_EX,,__GET_VAR(data__->SAT3.READYTOSEND,));
  __SET_EXTERNAL(data__->,SENSORCT4_EX,,__GET_LOCATED(data__->SENSORCT4,));
  __SET_LOCATED(data__->,FORWARDCT4,,__GET_VAR(data__->CT4.FORWARDMOTOR,));
  __SET_LOCATED(data__->,ZUPSAT3,,__GET_VAR(data__->SAT3.MOTORUP,));
  __SET_LOCATED(data__->,PUSHFORWARDCT4,,__GET_VAR(data__->CT4.PUSHMOTORFORWARD,));
  __SET_LOCATED(data__->,XLEFTSAT3,,__GET_VAR(data__->SAT3.MOTORLEFT,));
  __SET_LOCATED(data__->,PUSHBACKCT4,,__GET_VAR(data__->CT4.PUSHMOTORBACK,));
  __SET_LOCATED(data__->,ZDOWNSAT3,,__GET_VAR(data__->SAT3.MOTORDOWN,));
  __SET_LOCATED(data__->,XRIGHTSAT3,,__GET_VAR(data__->SAT3.MOTORRIGHT,));
  __SET_LOCATED(data__->,FORWARDSAT3,,__GET_VAR(data__->SAT3.FORWARDMOTOR,));
  __SET_EXTERNAL(data__->,SENSORSAT4_EX,,__GET_LOCATED(data__->SENSORSAT4,));
  __SET_LOCATED(data__->,FORWARDCT5,,__GET_VAR(data__->CT5.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDSAT4,,__GET_VAR(data__->SAT4.FORWARDMOTOR,));
  __SET_EXTERNAL(data__->,SENSORCT5_EX,,__GET_LOCATED(data__->SENSORCT5,));
  __SET_LOCATED(data__->,PUSHFORWARDCT5,,__GET_VAR(data__->CT5.PUSHMOTORFORWARD,));
  __SET_LOCATED(data__->,PUSHBACKCT5,,__GET_VAR(data__->CT5.PUSHMOTORBACK,));
  __SET_EXTERNAL(data__->,SENSORCT6_EX,,__GET_LOCATED(data__->SENSORCT6,));
  __SET_LOCATED(data__->,FORWARDCT6,,__GET_VAR(data__->CT6.FORWARDMOTOR,));
  __SET_LOCATED(data__->,PUSHFORWARDCT6,,__GET_VAR(data__->CT6.PUSHMOTORFORWARD,));
  __SET_LOCATED(data__->,PUSHBACKCT6,,__GET_VAR(data__->CT6.PUSHMOTORBACK,));
  __SET_EXTERNAL(data__->,SENSORSAT5_EX,,__GET_LOCATED(data__->SENSORSAT5,));
  __SET_LOCATED(data__->,TOOLPLUSSAT5,,__GET_VAR(data__->SAT5.TOOLPLUS,));
  __SET_EXTERNAL(data__->,READYTOSENDSAT5_EX,,__GET_VAR(data__->SAT5.READYTOSEND,));
  __SET_LOCATED(data__->,TOOLMINUSSAT5,,__GET_VAR(data__->SAT5.TOOLMINUS,));
  __SET_LOCATED(data__->,ZUPSAT5,,__GET_VAR(data__->SAT5.MOTORUP,));
  __SET_LOCATED(data__->,XLEFTSAT5,,__GET_VAR(data__->SAT5.MOTORLEFT,));
  __SET_LOCATED(data__->,ZDOWNSAT5,,__GET_VAR(data__->SAT5.MOTORDOWN,));
  __SET_LOCATED(data__->,XRIGHTSAT5,,__GET_VAR(data__->SAT5.MOTORRIGHT,));
  __SET_LOCATED(data__->,FORWARDSAT5,,__GET_VAR(data__->SAT5.FORWARDMOTOR,));
  __SET_EXTERNAL(data__->,SENSORSCT6_EX,,__GET_LOCATED(data__->SENSORSCT6,));
  __SET_EXTERNAL(data__->,SENSORSBT6_EX,,__GET_LOCATED(data__->SENSORSBT6,));
  __SET_EXTERNAL(data__->,SENSORSCT7_EX,,__GET_LOCATED(data__->SENSORSCT7,));
  __SET_EXTERNAL(data__->,SENSORSAT7_EX,,__GET_LOCATED(data__->SENSORSAT7,));
  __SET_EXTERNAL(data__->,SENSORMT5_EX,,__GET_LOCATED(data__->SENSORMT5,));
  __SET_EXTERNAL(data__->,SENSORAT2_EX,,__GET_LOCATED(data__->SENSORAT2,));
  __SET_EXTERNAL(data__->,SENSORSAT6_EX,,__GET_LOCATED(data__->SENSORSAT6,));
  __SET_EXTERNAL(data__->,SENSORSBT7_EX,,__GET_LOCATED(data__->SENSORSBT7,));
  __SET_EXTERNAL(data__->,SENSORCT9_EX,,__GET_LOCATED(data__->SENSORCT9,));
  __SET_EXTERNAL(data__->,SENSORCT7_EX,,__GET_LOCATED(data__->SENSORCT7,));
  __SET_EXTERNAL(data__->,SENSORCT8_EX,,__GET_LOCATED(data__->SENSORCT8,));
  __SET_EXTERNAL(data__->,SENSORMT6_EX,,__GET_LOCATED(data__->SENSORMT6,));
  __SET_LOCATED(data__->,WAREHOUSEBUSYCOMM,,__GET_EXTERNAL(data__->WAREHOUSEBUSY,));
  __SET_VAR(data__->SBT7.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSBT7,));
  __SET_VAR(data__->SBT7.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKSBT7_EX,));
  __SET_VAR(data__->SBT7.,BACKNOTBUSY,,__GET_VAR(data__->SAT6.ISBUSY,));
  __SET_VAR(data__->SBT7.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSBT6,));
  __SET_VAR(data__->SBT7.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORSAT6,));
  LINEARCONVEYOR_body__(&data__->SBT7);
  __SET_VAR(data__->SBT6.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKSBT6_EX,));
  __SET_VAR(data__->SBT6.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSBT6_EX,));
  __SET_VAR(data__->SBT6.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNSBT6_EX,));
  __SET_VAR(data__->SBT6.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTSBT6,));
  __SET_VAR(data__->SBT6.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTSBT6,));
  __SET_VAR(data__->SBT6.,BACKNOTBUSY,,__GET_VAR(data__->SBT7.ISBUSY,));
  __SET_VAR(data__->SBT6.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSCT7,));
  __SET_VAR(data__->SBT6.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSBT6,));
  __SET_VAR(data__->SBT6.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORSBT7,));
  ROTARYCONVEYOR_body__(&data__->SBT6);
  __SET_VAR(data__->SCT7.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSCT7,));
  __SET_VAR(data__->SCT7.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKSCT7_EX,));
  __SET_VAR(data__->SCT7.,BACKNOTBUSY,,__GET_VAR(data__->SBT6.ISBUSY,));
  __SET_VAR(data__->SCT7.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSCT6,));
  __SET_VAR(data__->SCT7.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORSBT6,));
  LINEARCONVEYOR_body__(&data__->SCT7);
  __SET_VAR(data__->SCT6.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKSCT6_EX,));
  __SET_VAR(data__->SCT6.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSCT6_EX,));
  __SET_VAR(data__->SCT6.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNSCT6_EX,));
  __SET_VAR(data__->SCT6.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTSCT6,));
  __SET_VAR(data__->SCT6.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTSCT6,));
  __SET_VAR(data__->SCT6.,BACKNOTBUSY,,__GET_VAR(data__->SCT7.ISBUSY,));
  __SET_VAR(data__->SCT6.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSCT6,));
  __SET_VAR(data__->SCT6.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORSCT7,));
  ROTARYCONVEYOR_body__(&data__->SCT6);
  __SET_VAR(data__->MT5.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORMT5,));
  __SET_VAR(data__->MT5.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKMT5_EX,));
  __SET_VAR(data__->MT5.,BACKNOTBUSY,,__GET_VAR(data__->SCT6.ISBUSY,));
  __SET_VAR(data__->MT5.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORMT6,));
  __SET_VAR(data__->MT5.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORSCT6,));
  LINEARCONVEYOR_body__(&data__->MT5);
  __SET_VAR(data__->MT6.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKMT6_EX,));
  __SET_VAR(data__->MT6.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNMT6_EX,));
  __SET_VAR(data__->MT6.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTMT6,));
  __SET_VAR(data__->MT6.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTMT6,));
  __SET_VAR(data__->MT6.,BACKNOTBUSY,,__GET_VAR(data__->MT5.ISBUSY,));
  __SET_VAR(data__->MT6.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORMT6,));
  __SET_VAR(data__->MT6.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORMT5,));
  ROTARYCONVEYOR_body__(&data__->MT6);
  __SET_VAR(data__->CT7.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT7,));
  __SET_VAR(data__->CT7.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKCT7_EX,));
  __SET_VAR(data__->CT7.,BACKNOTBUSY,,__GET_VAR(data__->MT6.ISBUSY,));
  __SET_VAR(data__->CT7.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORCT8,));
  __SET_VAR(data__->CT7.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORMT6,));
  LINEARCONVEYOR_body__(&data__->CT7);
  __SET_VAR(data__->CT8.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKCT8_EX,));
  __SET_VAR(data__->CT8.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTCT8_EX,));
  __SET_VAR(data__->CT8.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNCT8_EX,));
  __SET_VAR(data__->CT8.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTCT8,));
  __SET_VAR(data__->CT8.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTCT8,));
  __SET_VAR(data__->CT8.,BACKNOTBUSY,,__GET_VAR(data__->CT7.ISBUSY,));
  __SET_VAR(data__->CT8.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT8,));
  __SET_VAR(data__->CT8.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORCT7,));
  ROTARYCONVEYOR_body__(&data__->CT8);
  __SET_LOCATED(data__->,FORWARDCT8,,__GET_VAR(data__->CT8.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDSCT6,,__GET_VAR(data__->SCT6.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDSBT6,,__GET_VAR(data__->SBT6.FORWARDMOTOR,));
  __SET_LOCATED(data__->,BACKCT8,,__GET_VAR(data__->CT8.BACKMOTOR,));
  __SET_LOCATED(data__->,FORWARDSAT6,,__GET_VAR(data__->SAT6.FORWARDMOTOR,));
  __SET_LOCATED(data__->,BACKSCT6,,__GET_VAR(data__->SCT6.BACKMOTOR,));
  __SET_LOCATED(data__->,WAREHOUSEIN,,__GET_VAR(data__->AT2.PUTPIECEIN,));
  __SET_LOCATED(data__->,BACKSAT6,,__GET_VAR(data__->SAT6.BACKMOTOR,));
  __SET_LOCATED(data__->,FORWARDMT6,,__GET_VAR(data__->MT6.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDSBT7,,__GET_VAR(data__->SBT7.FORWARDMOTOR,));
  __SET_LOCATED(data__->,BACKSBT6,,__GET_VAR(data__->SBT6.BACKMOTOR,));
  __SET_LOCATED(data__->,RIGHTROTSCT6,,__GET_VAR(data__->SCT6.RIGHTROTMOTOR,));
  __SET_LOCATED(data__->,FORWARDCT7,,__GET_VAR(data__->CT7.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDSAT7,,__GET_VAR(data__->SAT7.FORWARDMOTOR,));
  __SET_LOCATED(data__->,RIGHTROTSAT6,,__GET_VAR(data__->SAT6.RIGHTROTMOTOR,));
  __SET_LOCATED(data__->,BACKMT6,,__GET_VAR(data__->MT6.BACKMOTOR,));
  __SET_LOCATED(data__->,RIGHTROTCT8,,__GET_VAR(data__->CT8.RIGHTROTMOTOR,));
  __SET_LOCATED(data__->,FORWARDAT2,,__GET_VAR(data__->AT2.FORWARDMOTOR,));
  __SET_LOCATED(data__->,RIGHTROTSBT6,,__GET_VAR(data__->SBT6.RIGHTROTMOTOR,));
  __SET_LOCATED(data__->,LEFTROTSCT6,,__GET_VAR(data__->SCT6.LEFTROTMOTOR,));
  __SET_LOCATED(data__->,BACKSBT7,,__GET_VAR(data__->SBT7.BACKMOTOR,));
  __SET_LOCATED(data__->,FORWARDMT5,,__GET_VAR(data__->MT5.FORWARDMOTOR,));
  __SET_LOCATED(data__->,BACKSAT7,,__GET_VAR(data__->SAT7.BACKMOTOR,));
  __SET_LOCATED(data__->,RIGHTROTMT6,,__GET_VAR(data__->MT6.RIGHTROTMOTOR,));
  __SET_LOCATED(data__->,LEFTROTSAT6,,__GET_VAR(data__->SAT6.LEFTROTMOTOR,));
  __SET_LOCATED(data__->,BACKCT7,,__GET_VAR(data__->CT7.BACKMOTOR,));
  __SET_LOCATED(data__->,LEFTROTCT8,,__GET_VAR(data__->CT8.LEFTROTMOTOR,));
  __SET_VAR(data__->,OR210_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->CT8.FORWARDMOTOR,),
    (BOOL)__GET_VAR(data__->CT8.ISBUSY,)));
  __SET_VAR(data__->CT9.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT9,));
  __SET_VAR(data__->CT9.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKCT9_EX,));
  __SET_VAR(data__->CT9.,BACKNOTBUSY,,__GET_VAR(data__->OR210_OUT,));
  __SET_VAR(data__->CT9.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORCT8,));
  LINEARCONVEYOR_body__(&data__->CT9);
  __SET_LOCATED(data__->,BACKCT9,,__GET_VAR(data__->CT9.BACKMOTOR,));
  __SET_LOCATED(data__->,BACKAT2,,__GET_VAR(data__->AT2.BACKMOTOR,));
  __SET_LOCATED(data__->,LEFTROTSBT6,,__GET_VAR(data__->SBT6.LEFTROTMOTOR,));
  __SET_LOCATED(data__->,BACKMT5,,__GET_VAR(data__->MT5.BACKMOTOR,));
  __SET_LOCATED(data__->,LEFTROTMT6,,__GET_VAR(data__->MT6.LEFTROTMOTOR,));
  __SET_LOCATED(data__->,BACKSCT7,,__GET_VAR(data__->SCT7.BACKMOTOR,));
  __SET_VAR(data__->,OR209_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->CT2.FORWARDMOTOR,),
    (BOOL)__GET_VAR(data__->CT2.ISBUSY,)));
  __SET_VAR(data__->CT3.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT3,));
  __SET_VAR(data__->CT3.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKCT2_EX,));
  __SET_VAR(data__->CT3.,BACKNOTBUSY,,__GET_VAR(data__->OR209_OUT,));
  __SET_VAR(data__->CT3.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORCT2,));
  LINEARCONVEYOR_body__(&data__->CT3);

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





void REMOVEFROMWAREHOUSE_init__(REMOVEFROMWAREHOUSE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PIECENUM,0,retain)
  __INIT_VAR(data__->WAREHOUSEIN,0,retain)
  __INIT_VAR(data__->SENSORAT1,__BOOL_LITERAL(FALSE),retain)
  UINT i;
  data__->__nb_steps = 12;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 10;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 20;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define INITIALLOAD __step_list[0]
#define __SFC_INITIALLOAD 0
#define PUTP3 __step_list[1]
#define __SFC_PUTP3 1
#define STEP2 __step_list[2]
#define __SFC_STEP2 2
#define STEP0 __step_list[3]
#define __SFC_STEP0 3
#define PUTP4 __step_list[4]
#define __SFC_PUTP4 4
#define PUTP5 __step_list[5]
#define __SFC_PUTP5 5
#define PUTP7 __step_list[6]
#define __SFC_PUTP7 6
#define PUTP8 __step_list[7]
#define __SFC_PUTP8 7
#define PUTP9 __step_list[8]
#define __SFC_PUTP9 8
#define PUTP6 __step_list[9]
#define __SFC_PUTP6 9
#define PUTP10 __step_list[10]
#define __SFC_PUTP10 10
#define PUTP2 __step_list[11]
#define __SFC_PUTP2 11

// Actions definitions
#define __SFC_P2 0
#define __SFC_RESETWAREHOUSE 1
#define __SFC_P3 2
#define __SFC_P4 3
#define __SFC_P6 4
#define __SFC_P7 5
#define __SFC_P8 6
#define __SFC_P5 7
#define __SFC_P9 8
#define __SFC_P1 9

// Code part
void REMOVEFROMWAREHOUSE_body__(REMOVEFROMWAREHOUSE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  INT i;
  TIME elapsed_time, current_time;

  // Calculate elapsed_time
  current_time = __CURRENT_TIME;
  elapsed_time = __time_sub(current_time, data__->__lasttick_time);
  data__->__lasttick_time = current_time;
  // Transitions initialization
  if (__DEBUG) {
    for (i = 0; i < data__->__nb_transitions; i++) {
      data__->__transition_list[i] = data__->__debug_transition_list[i];
    }
  }
  // Steps initialization
  for (i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i].prev_state = __GET_VAR(data__->__step_list[i].X);
    if (__GET_VAR(data__->__step_list[i].X)) {
      data__->__step_list[i].T.value = __time_add(data__->__step_list[i].T.value, elapsed_time);
    }
  }
  // Actions initialization
  for (i = 0; i < data__->__nb_actions; i++) {
    __SET_VAR(data__->,__action_list[i].state,,0);
    data__->__action_list[i].set = 0;
    data__->__action_list[i].reset = 0;
    if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].set_remaining_time = __time_sub(data__->__action_list[i].set_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].set = 1;
      }
    }
    if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].reset_remaining_time = __time_sub(data__->__action_list[i].reset_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].reset = 1;
      }
    }
  }

  // Transitions fire test
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[0],,(__GET_VAR(data__->PIECENUM,) == 2));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,(__GET_VAR(data__->PIECENUM,) == 2));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->PUTP3.X)) {
    __SET_VAR(data__->,__transition_list[1],,__GET_VAR(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->STEP2.X)) {
    __SET_VAR(data__->,__transition_list[2],,!(__GET_VAR(data__->SENSORAT1,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,!(__GET_VAR(data__->SENSORAT1,)));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->STEP0.X)) {
    __SET_VAR(data__->,__transition_list[3],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[4],,(__GET_VAR(data__->PIECENUM,) == 3));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,(__GET_VAR(data__->PIECENUM,) == 3));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->PUTP4.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_VAR(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[6],,(__GET_VAR(data__->PIECENUM,) == 4));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,(__GET_VAR(data__->PIECENUM,) == 4));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->PUTP5.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_VAR(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[8],,(__GET_VAR(data__->PIECENUM,) == 6));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,(__GET_VAR(data__->PIECENUM,) == 6));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->PUTP7.X)) {
    __SET_VAR(data__->,__transition_list[9],,__GET_VAR(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[10],,(__GET_VAR(data__->PIECENUM,) == 7));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,(__GET_VAR(data__->PIECENUM,) == 7));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->PUTP8.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[12],,(__GET_VAR(data__->PIECENUM,) == 8));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,(__GET_VAR(data__->PIECENUM,) == 8));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->PUTP9.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_VAR(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[14],,(__GET_VAR(data__->PIECENUM,) == 5));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,(__GET_VAR(data__->PIECENUM,) == 5));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->PUTP6.X)) {
    __SET_VAR(data__->,__transition_list[15],,__GET_VAR(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[16],,(__GET_VAR(data__->PIECENUM,) == 9));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,(__GET_VAR(data__->PIECENUM,) == 9));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->PUTP10.X)) {
    __SET_VAR(data__->,__transition_list[17],,__GET_VAR(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[18],,(__GET_VAR(data__->PIECENUM,) == 1));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,(__GET_VAR(data__->PIECENUM,) == 1));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->PUTP2.X)) {
    __SET_VAR(data__->,__transition_list[19],,__GET_VAR(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,PUTP3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,PUTP4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,PUTP5.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,PUTP7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,PUTP8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,PUTP9.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,PUTP6.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,PUTP10.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,PUTP2.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,PUTP3.X,,1);
    data__->PUTP3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,INITIALLOAD.X,,1);
    data__->INITIALLOAD.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,PUTP4.X,,1);
    data__->PUTP4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,PUTP5.X,,1);
    data__->PUTP5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,PUTP7.X,,1);
    data__->PUTP7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,PUTP8.X,,1);
    data__->PUTP8.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,PUTP9.X,,1);
    data__->PUTP9.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,PUTP6.X,,1);
    data__->PUTP6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,PUTP10.X,,1);
    data__->PUTP10.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,PUTP2.X,,1);
    data__->PUTP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // PUTP3 action associations
  {
    char active = __GET_VAR(data__->PUTP3.X);
    char activated = active && !data__->PUTP3.prev_state;
    char desactivated = !active && data__->PUTP3.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P2].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P2].state,,0);};

  }

  // STEP2 action associations
  {
    char active = __GET_VAR(data__->STEP2.X);
    char activated = active && !data__->STEP2.prev_state;
    char desactivated = !active && data__->STEP2.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_RESETWAREHOUSE].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_RESETWAREHOUSE].state,,0);};

  }

  // PUTP4 action associations
  {
    char active = __GET_VAR(data__->PUTP4.X);
    char activated = active && !data__->PUTP4.prev_state;
    char desactivated = !active && data__->PUTP4.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P3].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P3].state,,0);};

  }

  // PUTP5 action associations
  {
    char active = __GET_VAR(data__->PUTP5.X);
    char activated = active && !data__->PUTP5.prev_state;
    char desactivated = !active && data__->PUTP5.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P4].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P4].state,,0);};

  }

  // PUTP7 action associations
  {
    char active = __GET_VAR(data__->PUTP7.X);
    char activated = active && !data__->PUTP7.prev_state;
    char desactivated = !active && data__->PUTP7.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P6].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P6].state,,0);};

  }

  // PUTP8 action associations
  {
    char active = __GET_VAR(data__->PUTP8.X);
    char activated = active && !data__->PUTP8.prev_state;
    char desactivated = !active && data__->PUTP8.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P7].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P7].state,,0);};

  }

  // PUTP9 action associations
  {
    char active = __GET_VAR(data__->PUTP9.X);
    char activated = active && !data__->PUTP9.prev_state;
    char desactivated = !active && data__->PUTP9.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P8].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P8].state,,0);};

  }

  // PUTP6 action associations
  {
    char active = __GET_VAR(data__->PUTP6.X);
    char activated = active && !data__->PUTP6.prev_state;
    char desactivated = !active && data__->PUTP6.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P5].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P5].state,,0);};

  }

  // PUTP10 action associations
  {
    char active = __GET_VAR(data__->PUTP10.X);
    char activated = active && !data__->PUTP10.prev_state;
    char desactivated = !active && data__->PUTP10.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P9].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P9].state,,0);};

  }

  // PUTP2 action associations
  {
    char active = __GET_VAR(data__->PUTP2.X);
    char activated = active && !data__->PUTP2.prev_state;
    char desactivated = !active && data__->PUTP2.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P1].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P1].state,,0);};

  }


  // Actions state evaluation
  for (i = 0; i < data__->__nb_actions; i++) {
    if (data__->__action_list[i].set) {
      data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 1;
    }
    if (data__->__action_list[i].reset) {
      data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 0;
    }
    __SET_VAR(data__->,__action_list[i].state,,__GET_VAR(data__->__action_list[i].state) | data__->__action_list[i].stored);
  }

  // Actions execution
  if(__GET_VAR(data__->__action_list[__SFC_P2].state)) {
    __SET_VAR(data__->,WAREHOUSEIN,,2);
  }

  if(__GET_VAR(data__->__action_list[__SFC_RESETWAREHOUSE].state)) {
    __SET_VAR(data__->,WAREHOUSEIN,,0);
  }

  if(__GET_VAR(data__->__action_list[__SFC_P3].state)) {
    __SET_VAR(data__->,WAREHOUSEIN,,3);
  }

  if(__GET_VAR(data__->__action_list[__SFC_P4].state)) {
    __SET_VAR(data__->,WAREHOUSEIN,,4);
  }

  if(__GET_VAR(data__->__action_list[__SFC_P6].state)) {
    __SET_VAR(data__->,WAREHOUSEIN,,6);
  }

  if(__GET_VAR(data__->__action_list[__SFC_P7].state)) {
    __SET_VAR(data__->,WAREHOUSEIN,,7);
  }

  if(__GET_VAR(data__->__action_list[__SFC_P8].state)) {
    __SET_VAR(data__->,WAREHOUSEIN,,8);
  }

  if(__GET_VAR(data__->__action_list[__SFC_P5].state)) {
    __SET_VAR(data__->,WAREHOUSEIN,,5);
  }

  if(__GET_VAR(data__->__action_list[__SFC_P9].state)) {
    __SET_VAR(data__->,WAREHOUSEIN,,9);
  }

  if(__GET_VAR(data__->__action_list[__SFC_P1].state)) {
    __SET_VAR(data__->,WAREHOUSEIN,,1);
  }



  goto __end;

__end:
  return;
} // REMOVEFROMWAREHOUSE_body__() 

// Steps undefinitions
#undef INITIALLOAD
#undef __SFC_INITIALLOAD
#undef PUTP3
#undef __SFC_PUTP3
#undef STEP2
#undef __SFC_STEP2
#undef STEP0
#undef __SFC_STEP0
#undef PUTP4
#undef __SFC_PUTP4
#undef PUTP5
#undef __SFC_PUTP5
#undef PUTP7
#undef __SFC_PUTP7
#undef PUTP8
#undef __SFC_PUTP8
#undef PUTP9
#undef __SFC_PUTP9
#undef PUTP6
#undef __SFC_PUTP6
#undef PUTP10
#undef __SFC_PUTP10
#undef PUTP2
#undef __SFC_PUTP2

// Actions undefinitions
#undef __SFC_P2
#undef __SFC_RESETWAREHOUSE
#undef __SFC_P3
#undef __SFC_P4
#undef __SFC_P6
#undef __SFC_P7
#undef __SFC_P8
#undef __SFC_P5
#undef __SFC_P9
#undef __SFC_P1





void PROGRAM1_init__(PROGRAM1 *data__, BOOL retain) {
  __INIT_LOCATED(INT,__IW0_0_2_0,data__->WAREHOUSEIN,retain)
  __INIT_LOCATED_VALUE(data__->WAREHOUSEIN,0)
  __INIT_EXTERNAL(BOOL,WAREHOUSEBUSY,data__->WAREHOUSEBUSY,retain)
  __INIT_LOCATED(BOOL,__IX0_0_0_0,data__->SENSORAT1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(INT,__IW0_1_1_0,data__->INITIALPIECE,retain)
  __INIT_LOCATED_VALUE(data__->INITIALPIECE,0)
  __INIT_LOCATED(INT,__IW0_1_1_3,data__->FINALPIECE,retain)
  __INIT_LOCATED_VALUE(data__->FINALPIECE,0)
  __INIT_EXTERNAL(BOOL,RUNFRONTAT1_EX,data__->RUNFRONTAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT1_EX,data__->RUNFRONTSAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT2_EX,data__->RUNFRONTSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT4_EX,data__->RUNFRONTSAT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT1_EX,data__->RUNFRONTSBT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT2_EX,data__->RUNFRONTSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT1_EX,data__->RUNFRONTSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT2_EX,data__->RUNFRONTSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT1_EX,data__->RUNFRONTMT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT2_EX,data__->RUNFRONTMT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT1_EX,data__->RUNFRONTCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT4_EX,data__->RUNFRONTCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT5_EX,data__->RUNFRONTCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSAT7_EX,data__->RUNBACKSAT7_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSAT2_EX,data__->SENDDOWNSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESAT3_EX,data__->TOOLPIECESAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESAT5_EX,data__->TOOLPIECESAT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNCT2_EX,data__->SENDDOWNCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORAT1_EX,data__->SENSORAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORAT2_EX,data__->SENSORAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT1_EX,data__->SENSORSAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT2_EX,data__->SENSORSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT4_EX,data__->SENSORSAT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT6_EX,data__->SENSORSAT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT7_EX,data__->SENSORSAT7_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT1_EX,data__->SENSORSBT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT2_EX,data__->SENSORSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT1_EX,data__->SENSORSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT2_EX,data__->SENSORSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT1_EX,data__->SENSORMT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT2_EX,data__->SENSORMT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT1_EX,data__->SENSORCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT2_EX,data__->SENSORCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT4_EX,data__->SENSORCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT5_EX,data__->SENSORCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,PUSHTOROLLCT4_EX,data__->PUSHTOROLLCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,PUSHTOROLLCT5_EX,data__->PUSHTOROLLCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,PUSHTOROLLCT6_EX,data__->PUSHTOROLLCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNSAT6_EX,data__->SENDLEFTDOWNSAT6_EX,retain)
  __INIT_EXTERNAL(BOOL,PUTPIECEINSIGNAL_EX,data__->PUTPIECEINSIGNAL_EX,retain)
  REMOVEFROMWAREHOUSE_init__(&data__->REMOVEFROMWAREHOUSE0,retain);
  __INIT_LOCATED(INT,__IW0_1_1_2,data__->PM,retain)
  __INIT_LOCATED_VALUE(data__->PM,0)
  __INIT_LOCATED(BOOL,__IX0_1_0_1,data__->RUNUNLOAD,retain)
  __INIT_LOCATED_VALUE(data__->RUNUNLOAD,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1_0_2,data__->RUNTRANSFORMMACH1,retain)
  __INIT_LOCATED_VALUE(data__->RUNTRANSFORMMACH1,__BOOL_LITERAL(FALSE))
  __INIT_EXTERNAL(BOOL,READYTOSENDSAT3_EX,data__->READYTOSENDSAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSAT5_EX,data__->READYTOSENDSAT5_EX,retain)
  UINT i;
  data__->__nb_steps = 103;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  __SET_VAR(data__->,__step_list[84].X,,1);
  data__->__nb_actions = 27;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 105;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define STEP0 __step_list[0]
#define __SFC_STEP0 0
#define STEP52 __step_list[1]
#define __SFC_STEP52 1
#define STEP26 __step_list[2]
#define __SFC_STEP26 2
#define STEP2 __step_list[3]
#define __SFC_STEP2 3
#define STEP4 __step_list[4]
#define __SFC_STEP4 4
#define STEP3 __step_list[5]
#define __SFC_STEP3 5
#define STEP5 __step_list[6]
#define __SFC_STEP5 6
#define STEP7 __step_list[7]
#define __SFC_STEP7 7
#define STEP8 __step_list[8]
#define __SFC_STEP8 8
#define STEP9 __step_list[9]
#define __SFC_STEP9 9
#define STEP10 __step_list[10]
#define __SFC_STEP10 10
#define STEP11 __step_list[11]
#define __SFC_STEP11 11
#define STEP12 __step_list[12]
#define __SFC_STEP12 12
#define STEP13 __step_list[13]
#define __SFC_STEP13 13
#define STEP14 __step_list[14]
#define __SFC_STEP14 14
#define STEP15 __step_list[15]
#define __SFC_STEP15 15
#define STEP16 __step_list[16]
#define __SFC_STEP16 16
#define STEP17 __step_list[17]
#define __SFC_STEP17 17
#define STEP18 __step_list[18]
#define __SFC_STEP18 18
#define STEP19 __step_list[19]
#define __SFC_STEP19 19
#define STEP20 __step_list[20]
#define __SFC_STEP20 20
#define STEP21 __step_list[21]
#define __SFC_STEP21 21
#define STEP22 __step_list[22]
#define __SFC_STEP22 22
#define STEP23 __step_list[23]
#define __SFC_STEP23 23
#define STEP24 __step_list[24]
#define __SFC_STEP24 24
#define STEP25 __step_list[25]
#define __SFC_STEP25 25
#define STEP1 __step_list[26]
#define __SFC_STEP1 26
#define STEP6 __step_list[27]
#define __SFC_STEP6 27
#define STEP47 __step_list[28]
#define __SFC_STEP47 28
#define STEP46 __step_list[29]
#define __SFC_STEP46 29
#define STEP28 __step_list[30]
#define __SFC_STEP28 30
#define STEP27 __step_list[31]
#define __SFC_STEP27 31
#define STEP29 __step_list[32]
#define __SFC_STEP29 32
#define STEP31 __step_list[33]
#define __SFC_STEP31 33
#define STEP32 __step_list[34]
#define __SFC_STEP32 34
#define STEP33 __step_list[35]
#define __SFC_STEP33 35
#define STEP34 __step_list[36]
#define __SFC_STEP34 36
#define STEP35 __step_list[37]
#define __SFC_STEP35 37
#define STEP36 __step_list[38]
#define __SFC_STEP36 38
#define STEP37 __step_list[39]
#define __SFC_STEP37 39
#define STEP38 __step_list[40]
#define __SFC_STEP38 40
#define STEP39 __step_list[41]
#define __SFC_STEP39 41
#define STEP40 __step_list[42]
#define __SFC_STEP40 42
#define STEP41 __step_list[43]
#define __SFC_STEP41 43
#define STEP42 __step_list[44]
#define __SFC_STEP42 44
#define STEP43 __step_list[45]
#define __SFC_STEP43 45
#define STEP44 __step_list[46]
#define __SFC_STEP44 46
#define STEP45 __step_list[47]
#define __SFC_STEP45 47
#define STEP48 __step_list[48]
#define __SFC_STEP48 48
#define STEP49 __step_list[49]
#define __SFC_STEP49 49
#define STEP50 __step_list[50]
#define __SFC_STEP50 50
#define STEP51 __step_list[51]
#define __SFC_STEP51 51
#define STEP53 __step_list[52]
#define __SFC_STEP53 52
#define STEP54 __step_list[53]
#define __SFC_STEP54 53
#define STEP55 __step_list[54]
#define __SFC_STEP55 54
#define STEP30 __step_list[55]
#define __SFC_STEP30 55
#define STEP80 __step_list[56]
#define __SFC_STEP80 56
#define STEP58 __step_list[57]
#define __SFC_STEP58 57
#define STEP57 __step_list[58]
#define __SFC_STEP57 58
#define STEP56 __step_list[59]
#define __SFC_STEP56 59
#define STEP59 __step_list[60]
#define __SFC_STEP59 60
#define STEP61 __step_list[61]
#define __SFC_STEP61 61
#define STEP62 __step_list[62]
#define __SFC_STEP62 62
#define STEP63 __step_list[63]
#define __SFC_STEP63 63
#define STEP64 __step_list[64]
#define __SFC_STEP64 64
#define STEP65 __step_list[65]
#define __SFC_STEP65 65
#define STEP66 __step_list[66]
#define __SFC_STEP66 66
#define STEP67 __step_list[67]
#define __SFC_STEP67 67
#define STEP68 __step_list[68]
#define __SFC_STEP68 68
#define STEP69 __step_list[69]
#define __SFC_STEP69 69
#define STEP70 __step_list[70]
#define __SFC_STEP70 70
#define STEP71 __step_list[71]
#define __SFC_STEP71 71
#define STEP72 __step_list[72]
#define __SFC_STEP72 72
#define STEP73 __step_list[73]
#define __SFC_STEP73 73
#define STEP74 __step_list[74]
#define __SFC_STEP74 74
#define STEP75 __step_list[75]
#define __SFC_STEP75 75
#define STEP76 __step_list[76]
#define __SFC_STEP76 76
#define STEP77 __step_list[77]
#define __SFC_STEP77 77
#define STEP78 __step_list[78]
#define __SFC_STEP78 78
#define STEP79 __step_list[79]
#define __SFC_STEP79 79
#define STEP81 __step_list[80]
#define __SFC_STEP81 80
#define STEP82 __step_list[81]
#define __SFC_STEP82 81
#define STEP83 __step_list[82]
#define __SFC_STEP83 82
#define STEP60 __step_list[83]
#define __SFC_STEP60 83
#define STEP91 __step_list[84]
#define __SFC_STEP91 84
#define STEP89 __step_list[85]
#define __SFC_STEP89 85
#define STEP86 __step_list[86]
#define __SFC_STEP86 86
#define STEP85 __step_list[87]
#define __SFC_STEP85 87
#define STEP84 __step_list[88]
#define __SFC_STEP84 88
#define STEP87 __step_list[89]
#define __SFC_STEP87 89
#define STEP90 __step_list[90]
#define __SFC_STEP90 90
#define STEP98 __step_list[91]
#define __SFC_STEP98 91
#define STEP92 __step_list[92]
#define __SFC_STEP92 92
#define STEP93 __step_list[93]
#define __SFC_STEP93 93
#define STEP99 __step_list[94]
#define __SFC_STEP99 94
#define STEP94 __step_list[95]
#define __SFC_STEP94 95
#define STEP95 __step_list[96]
#define __SFC_STEP95 96
#define STEP96 __step_list[97]
#define __SFC_STEP96 97
#define STEP97 __step_list[98]
#define __SFC_STEP97 98
#define STEP100 __step_list[99]
#define __SFC_STEP100 99
#define STEP101 __step_list[100]
#define __SFC_STEP101 100
#define STEP102 __step_list[101]
#define __SFC_STEP102 101
#define STEP88 __step_list[102]
#define __SFC_STEP88 102

// Actions definitions
#define __SFC_ACTION0 0
#define __SFC_WAREHOUSEBUSY 1
#define __SFC_RUNUNLOAD 2
#define __SFC_RUNFRONTSAT1_EX 3
#define __SFC_RUNFRONTAT1_EX 4
#define __SFC_RUNFRONTSAT2_EX 5
#define __SFC_RUNFRONTSBT1_EX 6
#define __SFC_RUNFRONTSBT2_EX 7
#define __SFC_RUNFRONTSCT1_EX 8
#define __SFC_RUNFRONTSCT2_EX 9
#define __SFC_RUNFRONTMT1_EX 10
#define __SFC_RUNFRONTMT2_EX 11
#define __SFC_RUNFRONTCT1_EX 12
#define __SFC_SENDDOWNCT2_EX 13
#define __SFC_PUSHTOROLLCT4_EX 14
#define __SFC_RUNFRONTCT4_EX 15
#define __SFC_PUSHTOROLLCT5_EX 16
#define __SFC_RUNFRONTCT5_EX 17
#define __SFC_PUSHTOROLLCT6_EX 18
#define __SFC_RUNTRANSFORMMACH1 19
#define __SFC_SENDDOWNSAT2_EX 20
#define __SFC_TOOLPIECESAT3_EX 21
#define __SFC_RUNFRONTSAT4_EX 22
#define __SFC_TOOLPIECESAT5_EX 23
#define __SFC_SENDLEFTDOWNSAT6_EX 24
#define __SFC_RUNBACKSAT7_EX 25
#define __SFC_PUTPIECEINSIGNAL_EX 26

// Code part
void PROGRAM1_body__(PROGRAM1 *data__) {
  // Initialise TEMP variables

  INT i;
  TIME elapsed_time, current_time;

  // Calculate elapsed_time
  current_time = __CURRENT_TIME;
  elapsed_time = __time_sub(current_time, data__->__lasttick_time);
  data__->__lasttick_time = current_time;
  // Transitions initialization
  if (__DEBUG) {
    for (i = 0; i < data__->__nb_transitions; i++) {
      data__->__transition_list[i] = data__->__debug_transition_list[i];
    }
  }
  // Steps initialization
  for (i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i].prev_state = __GET_VAR(data__->__step_list[i].X);
    if (__GET_VAR(data__->__step_list[i].X)) {
      data__->__step_list[i].T.value = __time_add(data__->__step_list[i].T.value, elapsed_time);
    }
  }
  // Actions initialization
  for (i = 0; i < data__->__nb_actions; i++) {
    __SET_VAR(data__->,__action_list[i].state,,0);
    data__->__action_list[i].set = 0;
    data__->__action_list[i].reset = 0;
    if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].set_remaining_time = __time_sub(data__->__action_list[i].set_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].set = 1;
      }
    }
    if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].reset_remaining_time = __time_sub(data__->__action_list[i].reset_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].reset = 1;
      }
    }
  }

  // Transitions fire test
  if (__GET_VAR(data__->STEP0.X)) {
    __SET_VAR(data__->,__transition_list[0],,(__GET_LOCATED(data__->RUNUNLOAD,) && !(__GET_EXTERNAL(data__->WAREHOUSEBUSY,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,(__GET_LOCATED(data__->RUNUNLOAD,) && !(__GET_EXTERNAL(data__->WAREHOUSEBUSY,))));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->STEP52.X)) {
    __SET_VAR(data__->,__transition_list[1],,(__GET_LOCATED(data__->PM,) == 1));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,(__GET_LOCATED(data__->PM,) == 1));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->STEP26.X)) {
    __SET_VAR(data__->,__transition_list[2],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->STEP2.X)) {
    __SET_VAR(data__->,__transition_list[3],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->STEP4.X)) {
    __SET_VAR(data__->,__transition_list[4],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->STEP3.X)) {
    __SET_VAR(data__->,__transition_list[5],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->STEP5.X)) {
    __SET_VAR(data__->,__transition_list[6],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->STEP7.X)) {
    __SET_VAR(data__->,__transition_list[7],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->STEP8.X)) {
    __SET_VAR(data__->,__transition_list[8],,__GET_EXTERNAL(data__->SENSORSBT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_EXTERNAL(data__->SENSORSBT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->STEP9.X)) {
    __SET_VAR(data__->,__transition_list[9],,!(__GET_EXTERNAL(data__->SENSORSBT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,!(__GET_EXTERNAL(data__->SENSORSBT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->STEP10.X)) {
    __SET_VAR(data__->,__transition_list[10],,__GET_EXTERNAL(data__->SENSORSBT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_EXTERNAL(data__->SENSORSBT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->STEP11.X)) {
    __SET_VAR(data__->,__transition_list[11],,!(__GET_EXTERNAL(data__->SENSORSBT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,!(__GET_EXTERNAL(data__->SENSORSBT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->STEP12.X)) {
    __SET_VAR(data__->,__transition_list[12],,__GET_EXTERNAL(data__->SENSORSCT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_EXTERNAL(data__->SENSORSCT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->STEP13.X)) {
    __SET_VAR(data__->,__transition_list[13],,!(__GET_EXTERNAL(data__->SENSORSCT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,!(__GET_EXTERNAL(data__->SENSORSCT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->STEP14.X)) {
    __SET_VAR(data__->,__transition_list[14],,__GET_EXTERNAL(data__->SENSORSCT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_EXTERNAL(data__->SENSORSCT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->STEP15.X)) {
    __SET_VAR(data__->,__transition_list[15],,!(__GET_EXTERNAL(data__->SENSORSCT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,!(__GET_EXTERNAL(data__->SENSORSCT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->STEP16.X)) {
    __SET_VAR(data__->,__transition_list[16],,__GET_EXTERNAL(data__->SENSORMT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_EXTERNAL(data__->SENSORMT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->STEP17.X)) {
    __SET_VAR(data__->,__transition_list[17],,!(__GET_EXTERNAL(data__->SENSORMT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,!(__GET_EXTERNAL(data__->SENSORMT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->STEP18.X)) {
    __SET_VAR(data__->,__transition_list[18],,__GET_EXTERNAL(data__->SENSORMT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_EXTERNAL(data__->SENSORMT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->STEP19.X)) {
    __SET_VAR(data__->,__transition_list[19],,!(__GET_EXTERNAL(data__->SENSORMT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,!(__GET_EXTERNAL(data__->SENSORMT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->STEP20.X)) {
    __SET_VAR(data__->,__transition_list[20],,__GET_EXTERNAL(data__->SENSORCT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_EXTERNAL(data__->SENSORCT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->STEP21.X)) {
    __SET_VAR(data__->,__transition_list[21],,!(__GET_EXTERNAL(data__->SENSORCT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,!(__GET_EXTERNAL(data__->SENSORCT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->STEP22.X)) {
    __SET_VAR(data__->,__transition_list[22],,__GET_EXTERNAL(data__->SENSORCT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_EXTERNAL(data__->SENSORCT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->STEP23.X)) {
    __SET_VAR(data__->,__transition_list[23],,!(__GET_EXTERNAL(data__->SENSORCT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,!(__GET_EXTERNAL(data__->SENSORCT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->STEP24.X)) {
    __SET_VAR(data__->,__transition_list[24],,__GET_EXTERNAL(data__->SENSORCT4_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_EXTERNAL(data__->SENSORCT4_EX,));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->STEP25.X)) {
    __SET_VAR(data__->,__transition_list[25],,!(__GET_EXTERNAL(data__->SENSORCT4_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,!(__GET_EXTERNAL(data__->SENSORCT4_EX,)));
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
    __SET_VAR(data__->,__transition_list[26],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->STEP6.X)) {
    __SET_VAR(data__->,__transition_list[27],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->STEP52.X)) {
    __SET_VAR(data__->,__transition_list[28],,(__GET_LOCATED(data__->PM,) == 2));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,(__GET_LOCATED(data__->PM,) == 2));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->STEP47.X)) {
    __SET_VAR(data__->,__transition_list[29],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->STEP46.X)) {
    __SET_VAR(data__->,__transition_list[30],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->STEP28.X)) {
    __SET_VAR(data__->,__transition_list[31],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }
  if (__GET_VAR(data__->STEP27.X)) {
    __SET_VAR(data__->,__transition_list[32],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->__transition_list[32]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[32],,0);
  }
  if (__GET_VAR(data__->STEP29.X)) {
    __SET_VAR(data__->,__transition_list[33],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->__transition_list[33]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[33],,0);
  }
  if (__GET_VAR(data__->STEP31.X)) {
    __SET_VAR(data__->,__transition_list[34],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_VAR(data__->__transition_list[34]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[34],,0);
  }
  if (__GET_VAR(data__->STEP32.X)) {
    __SET_VAR(data__->,__transition_list[35],,__GET_EXTERNAL(data__->SENSORSBT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->__transition_list[35]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_EXTERNAL(data__->SENSORSBT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[35],,0);
  }
  if (__GET_VAR(data__->STEP33.X)) {
    __SET_VAR(data__->,__transition_list[36],,!(__GET_EXTERNAL(data__->SENSORSBT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->__transition_list[36]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,!(__GET_EXTERNAL(data__->SENSORSBT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[36],,0);
  }
  if (__GET_VAR(data__->STEP34.X)) {
    __SET_VAR(data__->,__transition_list[37],,__GET_EXTERNAL(data__->SENSORSBT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_VAR(data__->__transition_list[37]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_EXTERNAL(data__->SENSORSBT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[37],,0);
  }
  if (__GET_VAR(data__->STEP35.X)) {
    __SET_VAR(data__->,__transition_list[38],,!(__GET_EXTERNAL(data__->SENSORSBT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_VAR(data__->__transition_list[38]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,!(__GET_EXTERNAL(data__->SENSORSBT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[38],,0);
  }
  if (__GET_VAR(data__->STEP36.X)) {
    __SET_VAR(data__->,__transition_list[39],,__GET_EXTERNAL(data__->SENSORSCT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,__GET_VAR(data__->__transition_list[39]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,__GET_EXTERNAL(data__->SENSORSCT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[39],,0);
  }
  if (__GET_VAR(data__->STEP37.X)) {
    __SET_VAR(data__->,__transition_list[40],,!(__GET_EXTERNAL(data__->SENSORSCT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_VAR(data__->__transition_list[40]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,!(__GET_EXTERNAL(data__->SENSORSCT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[40],,0);
  }
  if (__GET_VAR(data__->STEP38.X)) {
    __SET_VAR(data__->,__transition_list[41],,__GET_EXTERNAL(data__->SENSORSCT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,__GET_VAR(data__->__transition_list[41]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,__GET_EXTERNAL(data__->SENSORSCT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[41],,0);
  }
  if (__GET_VAR(data__->STEP39.X)) {
    __SET_VAR(data__->,__transition_list[42],,!(__GET_EXTERNAL(data__->SENSORSCT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,__GET_VAR(data__->__transition_list[42]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,!(__GET_EXTERNAL(data__->SENSORSCT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[42],,0);
  }
  if (__GET_VAR(data__->STEP40.X)) {
    __SET_VAR(data__->,__transition_list[43],,__GET_EXTERNAL(data__->SENSORMT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,__GET_VAR(data__->__transition_list[43]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,__GET_EXTERNAL(data__->SENSORMT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[43],,0);
  }
  if (__GET_VAR(data__->STEP41.X)) {
    __SET_VAR(data__->,__transition_list[44],,!(__GET_EXTERNAL(data__->SENSORMT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,__GET_VAR(data__->__transition_list[44]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,!(__GET_EXTERNAL(data__->SENSORMT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[44],,0);
  }
  if (__GET_VAR(data__->STEP42.X)) {
    __SET_VAR(data__->,__transition_list[45],,__GET_EXTERNAL(data__->SENSORMT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,__GET_VAR(data__->__transition_list[45]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,__GET_EXTERNAL(data__->SENSORMT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[45],,0);
  }
  if (__GET_VAR(data__->STEP43.X)) {
    __SET_VAR(data__->,__transition_list[46],,!(__GET_EXTERNAL(data__->SENSORMT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,__GET_VAR(data__->__transition_list[46]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,!(__GET_EXTERNAL(data__->SENSORMT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[46],,0);
  }
  if (__GET_VAR(data__->STEP44.X)) {
    __SET_VAR(data__->,__transition_list[47],,__GET_EXTERNAL(data__->SENSORCT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,__GET_VAR(data__->__transition_list[47]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,__GET_EXTERNAL(data__->SENSORCT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[47],,0);
  }
  if (__GET_VAR(data__->STEP45.X)) {
    __SET_VAR(data__->,__transition_list[48],,!(__GET_EXTERNAL(data__->SENSORCT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,__GET_VAR(data__->__transition_list[48]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,!(__GET_EXTERNAL(data__->SENSORCT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[48],,0);
  }
  if (__GET_VAR(data__->STEP48.X)) {
    __SET_VAR(data__->,__transition_list[49],,__GET_EXTERNAL(data__->SENSORCT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,__GET_VAR(data__->__transition_list[49]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,__GET_EXTERNAL(data__->SENSORCT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[49],,0);
  }
  if (__GET_VAR(data__->STEP49.X)) {
    __SET_VAR(data__->,__transition_list[50],,!(__GET_EXTERNAL(data__->SENSORCT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[50],,__GET_VAR(data__->__transition_list[50]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[50],,!(__GET_EXTERNAL(data__->SENSORCT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[50],,0);
  }
  if (__GET_VAR(data__->STEP50.X)) {
    __SET_VAR(data__->,__transition_list[51],,__GET_EXTERNAL(data__->SENSORCT4_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[51],,__GET_VAR(data__->__transition_list[51]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[51],,__GET_EXTERNAL(data__->SENSORCT4_EX,));
    }
    __SET_VAR(data__->,__transition_list[51],,0);
  }
  if (__GET_VAR(data__->STEP51.X)) {
    __SET_VAR(data__->,__transition_list[52],,!(__GET_EXTERNAL(data__->SENSORCT4_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[52],,__GET_VAR(data__->__transition_list[52]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[52],,!(__GET_EXTERNAL(data__->SENSORCT4_EX,)));
    }
    __SET_VAR(data__->,__transition_list[52],,0);
  }
  if (__GET_VAR(data__->STEP53.X)) {
    __SET_VAR(data__->,__transition_list[53],,__GET_EXTERNAL(data__->SENSORCT5_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[53],,__GET_VAR(data__->__transition_list[53]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[53],,__GET_EXTERNAL(data__->SENSORCT5_EX,));
    }
    __SET_VAR(data__->,__transition_list[53],,0);
  }
  if (__GET_VAR(data__->STEP54.X)) {
    __SET_VAR(data__->,__transition_list[54],,!(__GET_EXTERNAL(data__->SENSORCT5_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[54],,__GET_VAR(data__->__transition_list[54]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[54],,!(__GET_EXTERNAL(data__->SENSORCT5_EX,)));
    }
    __SET_VAR(data__->,__transition_list[54],,0);
  }
  if (__GET_VAR(data__->STEP55.X)) {
    __SET_VAR(data__->,__transition_list[55],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[55],,__GET_VAR(data__->__transition_list[55]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[55],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[55],,0);
  }
  if (__GET_VAR(data__->STEP30.X)) {
    __SET_VAR(data__->,__transition_list[56],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[56],,__GET_VAR(data__->__transition_list[56]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[56],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[56],,0);
  }
  if (__GET_VAR(data__->STEP52.X)) {
    __SET_VAR(data__->,__transition_list[57],,(__GET_LOCATED(data__->PM,) == 3));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[57],,__GET_VAR(data__->__transition_list[57]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[57],,(__GET_LOCATED(data__->PM,) == 3));
    }
    __SET_VAR(data__->,__transition_list[57],,0);
  }
  if (__GET_VAR(data__->STEP80.X)) {
    __SET_VAR(data__->,__transition_list[58],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[58],,__GET_VAR(data__->__transition_list[58]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[58],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[58],,0);
  }
  if (__GET_VAR(data__->STEP58.X)) {
    __SET_VAR(data__->,__transition_list[59],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[59],,__GET_VAR(data__->__transition_list[59]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[59],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[59],,0);
  }
  if (__GET_VAR(data__->STEP57.X)) {
    __SET_VAR(data__->,__transition_list[60],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[60],,__GET_VAR(data__->__transition_list[60]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[60],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[60],,0);
  }
  if (__GET_VAR(data__->STEP56.X)) {
    __SET_VAR(data__->,__transition_list[61],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[61],,__GET_VAR(data__->__transition_list[61]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[61],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[61],,0);
  }
  if (__GET_VAR(data__->STEP59.X)) {
    __SET_VAR(data__->,__transition_list[62],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[62],,__GET_VAR(data__->__transition_list[62]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[62],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[62],,0);
  }
  if (__GET_VAR(data__->STEP61.X)) {
    __SET_VAR(data__->,__transition_list[63],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[63],,__GET_VAR(data__->__transition_list[63]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[63],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[63],,0);
  }
  if (__GET_VAR(data__->STEP62.X)) {
    __SET_VAR(data__->,__transition_list[64],,__GET_EXTERNAL(data__->SENSORSBT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[64],,__GET_VAR(data__->__transition_list[64]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[64],,__GET_EXTERNAL(data__->SENSORSBT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[64],,0);
  }
  if (__GET_VAR(data__->STEP63.X)) {
    __SET_VAR(data__->,__transition_list[65],,!(__GET_EXTERNAL(data__->SENSORSBT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[65],,__GET_VAR(data__->__transition_list[65]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[65],,!(__GET_EXTERNAL(data__->SENSORSBT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[65],,0);
  }
  if (__GET_VAR(data__->STEP64.X)) {
    __SET_VAR(data__->,__transition_list[66],,__GET_EXTERNAL(data__->SENSORSBT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[66],,__GET_VAR(data__->__transition_list[66]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[66],,__GET_EXTERNAL(data__->SENSORSBT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[66],,0);
  }
  if (__GET_VAR(data__->STEP65.X)) {
    __SET_VAR(data__->,__transition_list[67],,!(__GET_EXTERNAL(data__->SENSORSBT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[67],,__GET_VAR(data__->__transition_list[67]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[67],,!(__GET_EXTERNAL(data__->SENSORSBT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[67],,0);
  }
  if (__GET_VAR(data__->STEP66.X)) {
    __SET_VAR(data__->,__transition_list[68],,__GET_EXTERNAL(data__->SENSORSCT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[68],,__GET_VAR(data__->__transition_list[68]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[68],,__GET_EXTERNAL(data__->SENSORSCT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[68],,0);
  }
  if (__GET_VAR(data__->STEP67.X)) {
    __SET_VAR(data__->,__transition_list[69],,!(__GET_EXTERNAL(data__->SENSORSCT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[69],,__GET_VAR(data__->__transition_list[69]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[69],,!(__GET_EXTERNAL(data__->SENSORSCT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[69],,0);
  }
  if (__GET_VAR(data__->STEP68.X)) {
    __SET_VAR(data__->,__transition_list[70],,__GET_EXTERNAL(data__->SENSORSCT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[70],,__GET_VAR(data__->__transition_list[70]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[70],,__GET_EXTERNAL(data__->SENSORSCT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[70],,0);
  }
  if (__GET_VAR(data__->STEP69.X)) {
    __SET_VAR(data__->,__transition_list[71],,!(__GET_EXTERNAL(data__->SENSORSCT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[71],,__GET_VAR(data__->__transition_list[71]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[71],,!(__GET_EXTERNAL(data__->SENSORSCT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[71],,0);
  }
  if (__GET_VAR(data__->STEP70.X)) {
    __SET_VAR(data__->,__transition_list[72],,__GET_EXTERNAL(data__->SENSORMT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[72],,__GET_VAR(data__->__transition_list[72]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[72],,__GET_EXTERNAL(data__->SENSORMT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[72],,0);
  }
  if (__GET_VAR(data__->STEP71.X)) {
    __SET_VAR(data__->,__transition_list[73],,!(__GET_EXTERNAL(data__->SENSORMT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[73],,__GET_VAR(data__->__transition_list[73]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[73],,!(__GET_EXTERNAL(data__->SENSORMT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[73],,0);
  }
  if (__GET_VAR(data__->STEP72.X)) {
    __SET_VAR(data__->,__transition_list[74],,__GET_EXTERNAL(data__->SENSORMT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[74],,__GET_VAR(data__->__transition_list[74]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[74],,__GET_EXTERNAL(data__->SENSORMT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[74],,0);
  }
  if (__GET_VAR(data__->STEP73.X)) {
    __SET_VAR(data__->,__transition_list[75],,!(__GET_EXTERNAL(data__->SENSORMT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[75],,__GET_VAR(data__->__transition_list[75]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[75],,!(__GET_EXTERNAL(data__->SENSORMT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[75],,0);
  }
  if (__GET_VAR(data__->STEP74.X)) {
    __SET_VAR(data__->,__transition_list[76],,__GET_EXTERNAL(data__->SENSORCT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[76],,__GET_VAR(data__->__transition_list[76]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[76],,__GET_EXTERNAL(data__->SENSORCT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[76],,0);
  }
  if (__GET_VAR(data__->STEP75.X)) {
    __SET_VAR(data__->,__transition_list[77],,!(__GET_EXTERNAL(data__->SENSORCT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[77],,__GET_VAR(data__->__transition_list[77]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[77],,!(__GET_EXTERNAL(data__->SENSORCT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[77],,0);
  }
  if (__GET_VAR(data__->STEP76.X)) {
    __SET_VAR(data__->,__transition_list[78],,__GET_EXTERNAL(data__->SENSORCT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[78],,__GET_VAR(data__->__transition_list[78]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[78],,__GET_EXTERNAL(data__->SENSORCT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[78],,0);
  }
  if (__GET_VAR(data__->STEP77.X)) {
    __SET_VAR(data__->,__transition_list[79],,!(__GET_EXTERNAL(data__->SENSORCT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[79],,__GET_VAR(data__->__transition_list[79]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[79],,!(__GET_EXTERNAL(data__->SENSORCT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[79],,0);
  }
  if (__GET_VAR(data__->STEP78.X)) {
    __SET_VAR(data__->,__transition_list[80],,__GET_EXTERNAL(data__->SENSORCT4_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[80],,__GET_VAR(data__->__transition_list[80]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[80],,__GET_EXTERNAL(data__->SENSORCT4_EX,));
    }
    __SET_VAR(data__->,__transition_list[80],,0);
  }
  if (__GET_VAR(data__->STEP79.X)) {
    __SET_VAR(data__->,__transition_list[81],,!(__GET_EXTERNAL(data__->SENSORCT4_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[81],,__GET_VAR(data__->__transition_list[81]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[81],,!(__GET_EXTERNAL(data__->SENSORCT4_EX,)));
    }
    __SET_VAR(data__->,__transition_list[81],,0);
  }
  if (__GET_VAR(data__->STEP81.X)) {
    __SET_VAR(data__->,__transition_list[82],,__GET_EXTERNAL(data__->SENSORCT5_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[82],,__GET_VAR(data__->__transition_list[82]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[82],,__GET_EXTERNAL(data__->SENSORCT5_EX,));
    }
    __SET_VAR(data__->,__transition_list[82],,0);
  }
  if (__GET_VAR(data__->STEP82.X)) {
    __SET_VAR(data__->,__transition_list[83],,!(__GET_EXTERNAL(data__->SENSORCT5_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[83],,__GET_VAR(data__->__transition_list[83]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[83],,!(__GET_EXTERNAL(data__->SENSORCT5_EX,)));
    }
    __SET_VAR(data__->,__transition_list[83],,0);
  }
  if (__GET_VAR(data__->STEP83.X)) {
    __SET_VAR(data__->,__transition_list[84],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[84],,__GET_VAR(data__->__transition_list[84]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[84],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[84],,0);
  }
  if (__GET_VAR(data__->STEP60.X)) {
    __SET_VAR(data__->,__transition_list[85],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[85],,__GET_VAR(data__->__transition_list[85]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[85],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[85],,0);
  }
  if (__GET_VAR(data__->STEP91.X)) {
    __SET_VAR(data__->,__transition_list[86],,(__GET_LOCATED(data__->RUNTRANSFORMMACH1,) && !(__GET_EXTERNAL(data__->WAREHOUSEBUSY,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[86],,__GET_VAR(data__->__transition_list[86]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[86],,(__GET_LOCATED(data__->RUNTRANSFORMMACH1,) && !(__GET_EXTERNAL(data__->WAREHOUSEBUSY,))));
    }
    __SET_VAR(data__->,__transition_list[86],,0);
  }
  if (__GET_VAR(data__->STEP89.X)) {
    __SET_VAR(data__->,__transition_list[87],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[87],,__GET_VAR(data__->__transition_list[87]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[87],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[87],,0);
  }
  if (__GET_VAR(data__->STEP86.X)) {
    __SET_VAR(data__->,__transition_list[88],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[88],,__GET_VAR(data__->__transition_list[88]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[88],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[88],,0);
  }
  if (__GET_VAR(data__->STEP85.X)) {
    __SET_VAR(data__->,__transition_list[89],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[89],,__GET_VAR(data__->__transition_list[89]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[89],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[89],,0);
  }
  if (__GET_VAR(data__->STEP84.X)) {
    __SET_VAR(data__->,__transition_list[90],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[90],,__GET_VAR(data__->__transition_list[90]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[90],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[90],,0);
  }
  if (__GET_VAR(data__->STEP87.X)) {
    __SET_VAR(data__->,__transition_list[91],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[91],,__GET_VAR(data__->__transition_list[91]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[91],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[91],,0);
  }
  if (__GET_VAR(data__->STEP90.X)) {
    __SET_VAR(data__->,__transition_list[92],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[92],,__GET_VAR(data__->__transition_list[92]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[92],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[92],,0);
  }
  if (__GET_VAR(data__->STEP98.X)) {
    __SET_VAR(data__->,__transition_list[93],,__GET_EXTERNAL(data__->READYTOSENDSAT3_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[93],,__GET_VAR(data__->__transition_list[93]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[93],,__GET_EXTERNAL(data__->READYTOSENDSAT3_EX,));
    }
    __SET_VAR(data__->,__transition_list[93],,0);
  }
  if (__GET_VAR(data__->STEP92.X)) {
    __SET_VAR(data__->,__transition_list[94],,__GET_EXTERNAL(data__->SENSORSAT4_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[94],,__GET_VAR(data__->__transition_list[94]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[94],,__GET_EXTERNAL(data__->SENSORSAT4_EX,));
    }
    __SET_VAR(data__->,__transition_list[94],,0);
  }
  if (__GET_VAR(data__->STEP93.X)) {
    __SET_VAR(data__->,__transition_list[95],,!(__GET_EXTERNAL(data__->SENSORSAT4_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[95],,__GET_VAR(data__->__transition_list[95]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[95],,!(__GET_EXTERNAL(data__->SENSORSAT4_EX,)));
    }
    __SET_VAR(data__->,__transition_list[95],,0);
  }
  if (__GET_VAR(data__->STEP99.X)) {
    __SET_VAR(data__->,__transition_list[96],,__GET_EXTERNAL(data__->READYTOSENDSAT5_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[96],,__GET_VAR(data__->__transition_list[96]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[96],,__GET_EXTERNAL(data__->READYTOSENDSAT5_EX,));
    }
    __SET_VAR(data__->,__transition_list[96],,0);
  }
  if (__GET_VAR(data__->STEP94.X)) {
    __SET_VAR(data__->,__transition_list[97],,__GET_EXTERNAL(data__->SENSORSAT6_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[97],,__GET_VAR(data__->__transition_list[97]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[97],,__GET_EXTERNAL(data__->SENSORSAT6_EX,));
    }
    __SET_VAR(data__->,__transition_list[97],,0);
  }
  if (__GET_VAR(data__->STEP95.X)) {
    __SET_VAR(data__->,__transition_list[98],,!(__GET_EXTERNAL(data__->SENSORSAT6_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[98],,__GET_VAR(data__->__transition_list[98]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[98],,!(__GET_EXTERNAL(data__->SENSORSAT6_EX,)));
    }
    __SET_VAR(data__->,__transition_list[98],,0);
  }
  if (__GET_VAR(data__->STEP96.X)) {
    __SET_VAR(data__->,__transition_list[99],,__GET_EXTERNAL(data__->SENSORSAT7_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[99],,__GET_VAR(data__->__transition_list[99]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[99],,__GET_EXTERNAL(data__->SENSORSAT7_EX,));
    }
    __SET_VAR(data__->,__transition_list[99],,0);
  }
  if (__GET_VAR(data__->STEP97.X)) {
    __SET_VAR(data__->,__transition_list[100],,!(__GET_EXTERNAL(data__->SENSORSAT7_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[100],,__GET_VAR(data__->__transition_list[100]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[100],,!(__GET_EXTERNAL(data__->SENSORSAT7_EX,)));
    }
    __SET_VAR(data__->,__transition_list[100],,0);
  }
  if (__GET_VAR(data__->STEP100.X)) {
    __SET_VAR(data__->,__transition_list[101],,__GET_EXTERNAL(data__->SENSORAT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[101],,__GET_VAR(data__->__transition_list[101]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[101],,__GET_EXTERNAL(data__->SENSORAT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[101],,0);
  }
  if (__GET_VAR(data__->STEP101.X)) {
    __SET_VAR(data__->,__transition_list[102],,!(__GET_EXTERNAL(data__->SENSORAT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[102],,__GET_VAR(data__->__transition_list[102]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[102],,!(__GET_EXTERNAL(data__->SENSORAT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[102],,0);
  }
  if (__GET_VAR(data__->STEP102.X)) {
    __SET_VAR(data__->,__transition_list[103],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[103],,__GET_VAR(data__->__transition_list[103]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[103],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[103],,0);
  }
  if (__GET_VAR(data__->STEP88.X)) {
    __SET_VAR(data__->,__transition_list[104],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[104],,__GET_VAR(data__->__transition_list[104]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[104],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[104],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP52.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP26.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP5.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP9.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP10.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP12.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP13.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP14.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP15.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP16.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP17.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP18.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP19.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP20.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP21.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP22.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP23.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP24.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP25.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP6.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP52.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP47.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP46.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP28.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,STEP27.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,STEP29.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,STEP31.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,STEP32.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,STEP33.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,STEP34.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,STEP35.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,STEP36.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,STEP37.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,STEP38.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,STEP39.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,STEP40.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,STEP41.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,STEP42.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,STEP43.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,STEP44.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,STEP45.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,STEP48.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[50])) {
    __SET_VAR(data__->,STEP49.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[51])) {
    __SET_VAR(data__->,STEP50.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[52])) {
    __SET_VAR(data__->,STEP51.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[53])) {
    __SET_VAR(data__->,STEP53.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[54])) {
    __SET_VAR(data__->,STEP54.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[55])) {
    __SET_VAR(data__->,STEP55.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[56])) {
    __SET_VAR(data__->,STEP30.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[57])) {
    __SET_VAR(data__->,STEP52.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[58])) {
    __SET_VAR(data__->,STEP80.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[59])) {
    __SET_VAR(data__->,STEP58.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[60])) {
    __SET_VAR(data__->,STEP57.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[61])) {
    __SET_VAR(data__->,STEP56.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[62])) {
    __SET_VAR(data__->,STEP59.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[63])) {
    __SET_VAR(data__->,STEP61.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[64])) {
    __SET_VAR(data__->,STEP62.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[65])) {
    __SET_VAR(data__->,STEP63.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[66])) {
    __SET_VAR(data__->,STEP64.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[67])) {
    __SET_VAR(data__->,STEP65.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[68])) {
    __SET_VAR(data__->,STEP66.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[69])) {
    __SET_VAR(data__->,STEP67.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[70])) {
    __SET_VAR(data__->,STEP68.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[71])) {
    __SET_VAR(data__->,STEP69.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[72])) {
    __SET_VAR(data__->,STEP70.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[73])) {
    __SET_VAR(data__->,STEP71.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[74])) {
    __SET_VAR(data__->,STEP72.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[75])) {
    __SET_VAR(data__->,STEP73.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[76])) {
    __SET_VAR(data__->,STEP74.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[77])) {
    __SET_VAR(data__->,STEP75.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[78])) {
    __SET_VAR(data__->,STEP76.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[79])) {
    __SET_VAR(data__->,STEP77.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[80])) {
    __SET_VAR(data__->,STEP78.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[81])) {
    __SET_VAR(data__->,STEP79.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[82])) {
    __SET_VAR(data__->,STEP81.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[83])) {
    __SET_VAR(data__->,STEP82.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[84])) {
    __SET_VAR(data__->,STEP83.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[85])) {
    __SET_VAR(data__->,STEP60.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[86])) {
    __SET_VAR(data__->,STEP91.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[87])) {
    __SET_VAR(data__->,STEP89.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[88])) {
    __SET_VAR(data__->,STEP86.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[89])) {
    __SET_VAR(data__->,STEP85.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[90])) {
    __SET_VAR(data__->,STEP84.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[91])) {
    __SET_VAR(data__->,STEP87.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[92])) {
    __SET_VAR(data__->,STEP90.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[93])) {
    __SET_VAR(data__->,STEP98.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[94])) {
    __SET_VAR(data__->,STEP92.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[95])) {
    __SET_VAR(data__->,STEP93.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[96])) {
    __SET_VAR(data__->,STEP99.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[97])) {
    __SET_VAR(data__->,STEP94.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[98])) {
    __SET_VAR(data__->,STEP95.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[99])) {
    __SET_VAR(data__->,STEP96.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[100])) {
    __SET_VAR(data__->,STEP97.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[101])) {
    __SET_VAR(data__->,STEP100.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[102])) {
    __SET_VAR(data__->,STEP101.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[103])) {
    __SET_VAR(data__->,STEP102.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[104])) {
    __SET_VAR(data__->,STEP88.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP52.X,,1);
    data__->STEP52.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP26.X,,1);
    data__->STEP26.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP4.X,,1);
    data__->STEP4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP6.X,,1);
    data__->STEP6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP3.X,,1);
    data__->STEP3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP5.X,,1);
    data__->STEP5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP7.X,,1);
    data__->STEP7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP8.X,,1);
    data__->STEP8.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP9.X,,1);
    data__->STEP9.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP10.X,,1);
    data__->STEP10.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP11.X,,1);
    data__->STEP11.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP12.X,,1);
    data__->STEP12.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP13.X,,1);
    data__->STEP13.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP14.X,,1);
    data__->STEP14.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP15.X,,1);
    data__->STEP15.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP16.X,,1);
    data__->STEP16.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP17.X,,1);
    data__->STEP17.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP18.X,,1);
    data__->STEP18.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP19.X,,1);
    data__->STEP19.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP20.X,,1);
    data__->STEP20.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP21.X,,1);
    data__->STEP21.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP22.X,,1);
    data__->STEP22.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP23.X,,1);
    data__->STEP23.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP24.X,,1);
    data__->STEP24.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP25.X,,1);
    data__->STEP25.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP47.X,,1);
    data__->STEP47.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP46.X,,1);
    data__->STEP46.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP28.X,,1);
    data__->STEP28.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP30.X,,1);
    data__->STEP30.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP27.X,,1);
    data__->STEP27.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,STEP29.X,,1);
    data__->STEP29.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,STEP31.X,,1);
    data__->STEP31.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,STEP32.X,,1);
    data__->STEP32.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,STEP33.X,,1);
    data__->STEP33.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,STEP34.X,,1);
    data__->STEP34.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,STEP35.X,,1);
    data__->STEP35.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,STEP36.X,,1);
    data__->STEP36.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,STEP37.X,,1);
    data__->STEP37.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,STEP38.X,,1);
    data__->STEP38.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,STEP39.X,,1);
    data__->STEP39.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,STEP40.X,,1);
    data__->STEP40.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,STEP41.X,,1);
    data__->STEP41.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,STEP42.X,,1);
    data__->STEP42.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,STEP43.X,,1);
    data__->STEP43.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,STEP44.X,,1);
    data__->STEP44.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,STEP45.X,,1);
    data__->STEP45.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,STEP48.X,,1);
    data__->STEP48.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,STEP49.X,,1);
    data__->STEP49.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[50])) {
    __SET_VAR(data__->,STEP50.X,,1);
    data__->STEP50.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[51])) {
    __SET_VAR(data__->,STEP51.X,,1);
    data__->STEP51.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[52])) {
    __SET_VAR(data__->,STEP53.X,,1);
    data__->STEP53.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[53])) {
    __SET_VAR(data__->,STEP54.X,,1);
    data__->STEP54.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[54])) {
    __SET_VAR(data__->,STEP55.X,,1);
    data__->STEP55.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[55])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[56])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[57])) {
    __SET_VAR(data__->,STEP80.X,,1);
    data__->STEP80.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[58])) {
    __SET_VAR(data__->,STEP58.X,,1);
    data__->STEP58.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[59])) {
    __SET_VAR(data__->,STEP57.X,,1);
    data__->STEP57.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP60.X,,1);
    data__->STEP60.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[60])) {
    __SET_VAR(data__->,STEP56.X,,1);
    data__->STEP56.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[61])) {
    __SET_VAR(data__->,STEP59.X,,1);
    data__->STEP59.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[62])) {
    __SET_VAR(data__->,STEP61.X,,1);
    data__->STEP61.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[63])) {
    __SET_VAR(data__->,STEP62.X,,1);
    data__->STEP62.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[64])) {
    __SET_VAR(data__->,STEP63.X,,1);
    data__->STEP63.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[65])) {
    __SET_VAR(data__->,STEP64.X,,1);
    data__->STEP64.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[66])) {
    __SET_VAR(data__->,STEP65.X,,1);
    data__->STEP65.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[67])) {
    __SET_VAR(data__->,STEP66.X,,1);
    data__->STEP66.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[68])) {
    __SET_VAR(data__->,STEP67.X,,1);
    data__->STEP67.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[69])) {
    __SET_VAR(data__->,STEP68.X,,1);
    data__->STEP68.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[70])) {
    __SET_VAR(data__->,STEP69.X,,1);
    data__->STEP69.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[71])) {
    __SET_VAR(data__->,STEP70.X,,1);
    data__->STEP70.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[72])) {
    __SET_VAR(data__->,STEP71.X,,1);
    data__->STEP71.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[73])) {
    __SET_VAR(data__->,STEP72.X,,1);
    data__->STEP72.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[74])) {
    __SET_VAR(data__->,STEP73.X,,1);
    data__->STEP73.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[75])) {
    __SET_VAR(data__->,STEP74.X,,1);
    data__->STEP74.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[76])) {
    __SET_VAR(data__->,STEP75.X,,1);
    data__->STEP75.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[77])) {
    __SET_VAR(data__->,STEP76.X,,1);
    data__->STEP76.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[78])) {
    __SET_VAR(data__->,STEP77.X,,1);
    data__->STEP77.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[79])) {
    __SET_VAR(data__->,STEP78.X,,1);
    data__->STEP78.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[80])) {
    __SET_VAR(data__->,STEP79.X,,1);
    data__->STEP79.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[81])) {
    __SET_VAR(data__->,STEP81.X,,1);
    data__->STEP81.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[82])) {
    __SET_VAR(data__->,STEP82.X,,1);
    data__->STEP82.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[83])) {
    __SET_VAR(data__->,STEP83.X,,1);
    data__->STEP83.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[84])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[85])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[86])) {
    __SET_VAR(data__->,STEP89.X,,1);
    data__->STEP89.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[87])) {
    __SET_VAR(data__->,STEP86.X,,1);
    data__->STEP86.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[88])) {
    __SET_VAR(data__->,STEP85.X,,1);
    data__->STEP85.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP88.X,,1);
    data__->STEP88.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[89])) {
    __SET_VAR(data__->,STEP84.X,,1);
    data__->STEP84.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[90])) {
    __SET_VAR(data__->,STEP87.X,,1);
    data__->STEP87.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[91])) {
    __SET_VAR(data__->,STEP90.X,,1);
    data__->STEP90.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[92])) {
    __SET_VAR(data__->,STEP98.X,,1);
    data__->STEP98.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[93])) {
    __SET_VAR(data__->,STEP92.X,,1);
    data__->STEP92.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[94])) {
    __SET_VAR(data__->,STEP93.X,,1);
    data__->STEP93.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[95])) {
    __SET_VAR(data__->,STEP99.X,,1);
    data__->STEP99.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[96])) {
    __SET_VAR(data__->,STEP94.X,,1);
    data__->STEP94.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[97])) {
    __SET_VAR(data__->,STEP95.X,,1);
    data__->STEP95.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[98])) {
    __SET_VAR(data__->,STEP96.X,,1);
    data__->STEP96.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[99])) {
    __SET_VAR(data__->,STEP97.X,,1);
    data__->STEP97.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[100])) {
    __SET_VAR(data__->,STEP100.X,,1);
    data__->STEP100.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[101])) {
    __SET_VAR(data__->,STEP101.X,,1);
    data__->STEP101.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[102])) {
    __SET_VAR(data__->,STEP102.X,,1);
    data__->STEP102.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[103])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[104])) {
    __SET_VAR(data__->,STEP91.X,,1);
    data__->STEP91.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // STEP52 action associations
  {
    char active = __GET_VAR(data__->STEP52.X);
    char activated = active && !data__->STEP52.prev_state;
    char desactivated = !active && data__->STEP52.prev_state;

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].set = 1;}

  }

  // STEP26 action associations
  {
    char active = __GET_VAR(data__->STEP26.X);
    char activated = active && !data__->STEP26.prev_state;
    char desactivated = !active && data__->STEP26.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_ACTION0].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_ACTION0].state,,0);};

    if (active)       {data__->__action_list[__SFC_RUNUNLOAD].reset = 1;}

  }

  // STEP2 action associations
  {
    char active = __GET_VAR(data__->STEP2.X);
    char activated = active && !data__->STEP2.prev_state;
    char desactivated = !active && data__->STEP2.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,0);};

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,0);};

  }

  // STEP3 action associations
  {
    char active = __GET_VAR(data__->STEP3.X);
    char activated = active && !data__->STEP3.prev_state;
    char desactivated = !active && data__->STEP3.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,0);};

  }

  // STEP7 action associations
  {
    char active = __GET_VAR(data__->STEP7.X);
    char activated = active && !data__->STEP7.prev_state;
    char desactivated = !active && data__->STEP7.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,0);};

  }

  // STEP9 action associations
  {
    char active = __GET_VAR(data__->STEP9.X);
    char activated = active && !data__->STEP9.prev_state;
    char desactivated = !active && data__->STEP9.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,0);};

  }

  // STEP11 action associations
  {
    char active = __GET_VAR(data__->STEP11.X);
    char activated = active && !data__->STEP11.prev_state;
    char desactivated = !active && data__->STEP11.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,0);};

  }

  // STEP13 action associations
  {
    char active = __GET_VAR(data__->STEP13.X);
    char activated = active && !data__->STEP13.prev_state;
    char desactivated = !active && data__->STEP13.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSCT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSCT2_EX,,0);};

  }

  // STEP15 action associations
  {
    char active = __GET_VAR(data__->STEP15.X);
    char activated = active && !data__->STEP15.prev_state;
    char desactivated = !active && data__->STEP15.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTMT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTMT1_EX,,0);};

  }

  // STEP17 action associations
  {
    char active = __GET_VAR(data__->STEP17.X);
    char activated = active && !data__->STEP17.prev_state;
    char desactivated = !active && data__->STEP17.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTMT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTMT2_EX,,0);};

  }

  // STEP19 action associations
  {
    char active = __GET_VAR(data__->STEP19.X);
    char activated = active && !data__->STEP19.prev_state;
    char desactivated = !active && data__->STEP19.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTCT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTCT1_EX,,0);};

  }

  // STEP21 action associations
  {
    char active = __GET_VAR(data__->STEP21.X);
    char activated = active && !data__->STEP21.prev_state;
    char desactivated = !active && data__->STEP21.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SENDDOWNCT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDDOWNCT2_EX,,0);};

  }

  // STEP23 action associations
  {
    char active = __GET_VAR(data__->STEP23.X);
    char activated = active && !data__->STEP23.prev_state;
    char desactivated = !active && data__->STEP23.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,PUSHTOROLLCT4_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,PUSHTOROLLCT4_EX,,0);};

  }

  // STEP6 action associations
  {
    char active = __GET_VAR(data__->STEP6.X);
    char activated = active && !data__->STEP6.prev_state;
    char desactivated = !active && data__->STEP6.prev_state;

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].reset = 1;}

  }

  // STEP47 action associations
  {
    char active = __GET_VAR(data__->STEP47.X);
    char activated = active && !data__->STEP47.prev_state;
    char desactivated = !active && data__->STEP47.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_ACTION0].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_ACTION0].state,,0);};

    if (active)       {data__->__action_list[__SFC_RUNUNLOAD].reset = 1;}

  }

  // STEP46 action associations
  {
    char active = __GET_VAR(data__->STEP46.X);
    char activated = active && !data__->STEP46.prev_state;
    char desactivated = !active && data__->STEP46.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,0);};

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,0);};

  }

  // STEP27 action associations
  {
    char active = __GET_VAR(data__->STEP27.X);
    char activated = active && !data__->STEP27.prev_state;
    char desactivated = !active && data__->STEP27.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,0);};

  }

  // STEP31 action associations
  {
    char active = __GET_VAR(data__->STEP31.X);
    char activated = active && !data__->STEP31.prev_state;
    char desactivated = !active && data__->STEP31.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,0);};

  }

  // STEP33 action associations
  {
    char active = __GET_VAR(data__->STEP33.X);
    char activated = active && !data__->STEP33.prev_state;
    char desactivated = !active && data__->STEP33.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,0);};

  }

  // STEP35 action associations
  {
    char active = __GET_VAR(data__->STEP35.X);
    char activated = active && !data__->STEP35.prev_state;
    char desactivated = !active && data__->STEP35.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,0);};

  }

  // STEP37 action associations
  {
    char active = __GET_VAR(data__->STEP37.X);
    char activated = active && !data__->STEP37.prev_state;
    char desactivated = !active && data__->STEP37.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSCT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSCT2_EX,,0);};

  }

  // STEP39 action associations
  {
    char active = __GET_VAR(data__->STEP39.X);
    char activated = active && !data__->STEP39.prev_state;
    char desactivated = !active && data__->STEP39.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTMT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTMT1_EX,,0);};

  }

  // STEP41 action associations
  {
    char active = __GET_VAR(data__->STEP41.X);
    char activated = active && !data__->STEP41.prev_state;
    char desactivated = !active && data__->STEP41.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTMT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTMT2_EX,,0);};

  }

  // STEP43 action associations
  {
    char active = __GET_VAR(data__->STEP43.X);
    char activated = active && !data__->STEP43.prev_state;
    char desactivated = !active && data__->STEP43.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTCT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTCT1_EX,,0);};

  }

  // STEP45 action associations
  {
    char active = __GET_VAR(data__->STEP45.X);
    char activated = active && !data__->STEP45.prev_state;
    char desactivated = !active && data__->STEP45.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SENDDOWNCT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDDOWNCT2_EX,,0);};

  }

  // STEP49 action associations
  {
    char active = __GET_VAR(data__->STEP49.X);
    char activated = active && !data__->STEP49.prev_state;
    char desactivated = !active && data__->STEP49.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTCT4_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTCT4_EX,,0);};

  }

  // STEP51 action associations
  {
    char active = __GET_VAR(data__->STEP51.X);
    char activated = active && !data__->STEP51.prev_state;
    char desactivated = !active && data__->STEP51.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,PUSHTOROLLCT5_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,PUSHTOROLLCT5_EX,,0);};

  }

  // STEP30 action associations
  {
    char active = __GET_VAR(data__->STEP30.X);
    char activated = active && !data__->STEP30.prev_state;
    char desactivated = !active && data__->STEP30.prev_state;

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].reset = 1;}

  }

  // STEP80 action associations
  {
    char active = __GET_VAR(data__->STEP80.X);
    char activated = active && !data__->STEP80.prev_state;
    char desactivated = !active && data__->STEP80.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_ACTION0].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_ACTION0].state,,0);};

    if (active)       {data__->__action_list[__SFC_RUNUNLOAD].reset = 1;}

  }

  // STEP58 action associations
  {
    char active = __GET_VAR(data__->STEP58.X);
    char activated = active && !data__->STEP58.prev_state;
    char desactivated = !active && data__->STEP58.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,0);};

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,0);};

  }

  // STEP56 action associations
  {
    char active = __GET_VAR(data__->STEP56.X);
    char activated = active && !data__->STEP56.prev_state;
    char desactivated = !active && data__->STEP56.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,0);};

  }

  // STEP61 action associations
  {
    char active = __GET_VAR(data__->STEP61.X);
    char activated = active && !data__->STEP61.prev_state;
    char desactivated = !active && data__->STEP61.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,0);};

  }

  // STEP63 action associations
  {
    char active = __GET_VAR(data__->STEP63.X);
    char activated = active && !data__->STEP63.prev_state;
    char desactivated = !active && data__->STEP63.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,0);};

  }

  // STEP65 action associations
  {
    char active = __GET_VAR(data__->STEP65.X);
    char activated = active && !data__->STEP65.prev_state;
    char desactivated = !active && data__->STEP65.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,0);};

  }

  // STEP67 action associations
  {
    char active = __GET_VAR(data__->STEP67.X);
    char activated = active && !data__->STEP67.prev_state;
    char desactivated = !active && data__->STEP67.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSCT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSCT2_EX,,0);};

  }

  // STEP69 action associations
  {
    char active = __GET_VAR(data__->STEP69.X);
    char activated = active && !data__->STEP69.prev_state;
    char desactivated = !active && data__->STEP69.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTMT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTMT1_EX,,0);};

  }

  // STEP71 action associations
  {
    char active = __GET_VAR(data__->STEP71.X);
    char activated = active && !data__->STEP71.prev_state;
    char desactivated = !active && data__->STEP71.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTMT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTMT2_EX,,0);};

  }

  // STEP73 action associations
  {
    char active = __GET_VAR(data__->STEP73.X);
    char activated = active && !data__->STEP73.prev_state;
    char desactivated = !active && data__->STEP73.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTCT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTCT1_EX,,0);};

  }

  // STEP75 action associations
  {
    char active = __GET_VAR(data__->STEP75.X);
    char activated = active && !data__->STEP75.prev_state;
    char desactivated = !active && data__->STEP75.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SENDDOWNCT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDDOWNCT2_EX,,0);};

  }

  // STEP77 action associations
  {
    char active = __GET_VAR(data__->STEP77.X);
    char activated = active && !data__->STEP77.prev_state;
    char desactivated = !active && data__->STEP77.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTCT4_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTCT4_EX,,0);};

  }

  // STEP79 action associations
  {
    char active = __GET_VAR(data__->STEP79.X);
    char activated = active && !data__->STEP79.prev_state;
    char desactivated = !active && data__->STEP79.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTCT5_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTCT5_EX,,0);};

  }

  // STEP82 action associations
  {
    char active = __GET_VAR(data__->STEP82.X);
    char activated = active && !data__->STEP82.prev_state;
    char desactivated = !active && data__->STEP82.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,PUSHTOROLLCT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,PUSHTOROLLCT6_EX,,0);};

  }

  // STEP60 action associations
  {
    char active = __GET_VAR(data__->STEP60.X);
    char activated = active && !data__->STEP60.prev_state;
    char desactivated = !active && data__->STEP60.prev_state;

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].reset = 1;}

  }

  // STEP89 action associations
  {
    char active = __GET_VAR(data__->STEP89.X);
    char activated = active && !data__->STEP89.prev_state;
    char desactivated = !active && data__->STEP89.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_ACTION0].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_ACTION0].state,,0);};

    if (active)       {data__->__action_list[__SFC_RUNTRANSFORMMACH1].reset = 1;}

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].set = 1;}

  }

  // STEP86 action associations
  {
    char active = __GET_VAR(data__->STEP86.X);
    char activated = active && !data__->STEP86.prev_state;
    char desactivated = !active && data__->STEP86.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,0);};

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,0);};

  }

  // STEP84 action associations
  {
    char active = __GET_VAR(data__->STEP84.X);
    char activated = active && !data__->STEP84.prev_state;
    char desactivated = !active && data__->STEP84.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SENDDOWNSAT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDDOWNSAT2_EX,,0);};

  }

  // STEP90 action associations
  {
    char active = __GET_VAR(data__->STEP90.X);
    char activated = active && !data__->STEP90.prev_state;
    char desactivated = !active && data__->STEP90.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,TOOLPIECESAT3_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,TOOLPIECESAT3_EX,,0);};

  }

  // STEP92 action associations
  {
    char active = __GET_VAR(data__->STEP92.X);
    char activated = active && !data__->STEP92.prev_state;
    char desactivated = !active && data__->STEP92.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT4_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT4_EX,,0);};

  }

  // STEP93 action associations
  {
    char active = __GET_VAR(data__->STEP93.X);
    char activated = active && !data__->STEP93.prev_state;
    char desactivated = !active && data__->STEP93.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,TOOLPIECESAT5_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,TOOLPIECESAT5_EX,,0);};

  }

  // STEP94 action associations
  {
    char active = __GET_VAR(data__->STEP94.X);
    char activated = active && !data__->STEP94.prev_state;
    char desactivated = !active && data__->STEP94.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SENDLEFTDOWNSAT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDLEFTDOWNSAT6_EX,,0);};

  }

  // STEP95 action associations
  {
    char active = __GET_VAR(data__->STEP95.X);
    char activated = active && !data__->STEP95.prev_state;
    char desactivated = !active && data__->STEP95.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSAT7_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSAT7_EX,,0);};

  }

  // STEP97 action associations
  {
    char active = __GET_VAR(data__->STEP97.X);
    char activated = active && !data__->STEP97.prev_state;
    char desactivated = !active && data__->STEP97.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,PUTPIECEINSIGNAL_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,PUTPIECEINSIGNAL_EX,,0);};

  }

  // STEP88 action associations
  {
    char active = __GET_VAR(data__->STEP88.X);
    char activated = active && !data__->STEP88.prev_state;
    char desactivated = !active && data__->STEP88.prev_state;

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].reset = 1;}

  }


  // Actions state evaluation
  for (i = 0; i < data__->__nb_actions; i++) {
    if (data__->__action_list[i].set) {
      data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 1;
    }
    if (data__->__action_list[i].reset) {
      data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 0;
    }
    __SET_VAR(data__->,__action_list[i].state,,__GET_VAR(data__->__action_list[i].state) | data__->__action_list[i].stored);
  }

  // Actions execution
  if (data__->__action_list[__SFC_WAREHOUSEBUSY].reset) {
    __SET_EXTERNAL(data__->,WAREHOUSEBUSY,,0);
  }
  else if (data__->__action_list[__SFC_WAREHOUSEBUSY].set) {
    __SET_EXTERNAL(data__->,WAREHOUSEBUSY,,1);
  }
  if (data__->__action_list[__SFC_RUNUNLOAD].reset) {
    __SET_LOCATED(data__->,RUNUNLOAD,,0);
  }
  else if (data__->__action_list[__SFC_RUNUNLOAD].set) {
    __SET_LOCATED(data__->,RUNUNLOAD,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTSAT1_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTSAT1_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTAT1_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTAT1_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTSAT2_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTSAT2_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTSBT1_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTSBT1_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTSBT2_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTSBT2_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTSCT1_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTSCT1_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTSCT2_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTSCT2_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTSCT2_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTSCT2_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTMT1_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTMT1_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTMT1_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTMT1_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTMT2_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTMT2_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTMT2_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTMT2_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTCT1_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTCT1_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTCT1_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTCT1_EX,,1);
  }
  if (data__->__action_list[__SFC_SENDDOWNCT2_EX].reset) {
    __SET_EXTERNAL(data__->,SENDDOWNCT2_EX,,0);
  }
  else if (data__->__action_list[__SFC_SENDDOWNCT2_EX].set) {
    __SET_EXTERNAL(data__->,SENDDOWNCT2_EX,,1);
  }
  if (data__->__action_list[__SFC_PUSHTOROLLCT4_EX].reset) {
    __SET_EXTERNAL(data__->,PUSHTOROLLCT4_EX,,0);
  }
  else if (data__->__action_list[__SFC_PUSHTOROLLCT4_EX].set) {
    __SET_EXTERNAL(data__->,PUSHTOROLLCT4_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTCT4_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTCT4_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTCT4_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTCT4_EX,,1);
  }
  if (data__->__action_list[__SFC_PUSHTOROLLCT5_EX].reset) {
    __SET_EXTERNAL(data__->,PUSHTOROLLCT5_EX,,0);
  }
  else if (data__->__action_list[__SFC_PUSHTOROLLCT5_EX].set) {
    __SET_EXTERNAL(data__->,PUSHTOROLLCT5_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTCT5_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTCT5_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTCT5_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTCT5_EX,,1);
  }
  if (data__->__action_list[__SFC_PUSHTOROLLCT6_EX].reset) {
    __SET_EXTERNAL(data__->,PUSHTOROLLCT6_EX,,0);
  }
  else if (data__->__action_list[__SFC_PUSHTOROLLCT6_EX].set) {
    __SET_EXTERNAL(data__->,PUSHTOROLLCT6_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNTRANSFORMMACH1].reset) {
    __SET_LOCATED(data__->,RUNTRANSFORMMACH1,,0);
  }
  else if (data__->__action_list[__SFC_RUNTRANSFORMMACH1].set) {
    __SET_LOCATED(data__->,RUNTRANSFORMMACH1,,1);
  }
  if (data__->__action_list[__SFC_SENDDOWNSAT2_EX].reset) {
    __SET_EXTERNAL(data__->,SENDDOWNSAT2_EX,,0);
  }
  else if (data__->__action_list[__SFC_SENDDOWNSAT2_EX].set) {
    __SET_EXTERNAL(data__->,SENDDOWNSAT2_EX,,1);
  }
  if (data__->__action_list[__SFC_TOOLPIECESAT3_EX].reset) {
    __SET_EXTERNAL(data__->,TOOLPIECESAT3_EX,,0);
  }
  else if (data__->__action_list[__SFC_TOOLPIECESAT3_EX].set) {
    __SET_EXTERNAL(data__->,TOOLPIECESAT3_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTSAT4_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTSAT4_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTSAT4_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTSAT4_EX,,1);
  }
  if (data__->__action_list[__SFC_TOOLPIECESAT5_EX].reset) {
    __SET_EXTERNAL(data__->,TOOLPIECESAT5_EX,,0);
  }
  else if (data__->__action_list[__SFC_TOOLPIECESAT5_EX].set) {
    __SET_EXTERNAL(data__->,TOOLPIECESAT5_EX,,1);
  }
  if (data__->__action_list[__SFC_SENDLEFTDOWNSAT6_EX].reset) {
    __SET_EXTERNAL(data__->,SENDLEFTDOWNSAT6_EX,,0);
  }
  else if (data__->__action_list[__SFC_SENDLEFTDOWNSAT6_EX].set) {
    __SET_EXTERNAL(data__->,SENDLEFTDOWNSAT6_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNBACKSAT7_EX].reset) {
    __SET_EXTERNAL(data__->,RUNBACKSAT7_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNBACKSAT7_EX].set) {
    __SET_EXTERNAL(data__->,RUNBACKSAT7_EX,,1);
  }
  if (data__->__action_list[__SFC_PUTPIECEINSIGNAL_EX].reset) {
    __SET_EXTERNAL(data__->,PUTPIECEINSIGNAL_EX,,0);
  }
  else if (data__->__action_list[__SFC_PUTPIECEINSIGNAL_EX].set) {
    __SET_EXTERNAL(data__->,PUTPIECEINSIGNAL_EX,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_ACTION0].state)) {
    __SET_VAR(data__->REMOVEFROMWAREHOUSE0.,PIECENUM,,__GET_LOCATED(data__->INITIALPIECE,));
    __SET_VAR(data__->REMOVEFROMWAREHOUSE0.,SENSORAT1,,__GET_LOCATED(data__->SENSORAT1,));
    REMOVEFROMWAREHOUSE_body__(&data__->REMOVEFROMWAREHOUSE0);
    __SET_LOCATED(data__->,WAREHOUSEIN,,__GET_VAR(data__->REMOVEFROMWAREHOUSE0.WAREHOUSEIN,));
  }



  goto __end;

__end:
  return;
} // PROGRAM1_body__() 

// Steps undefinitions
#undef STEP0
#undef __SFC_STEP0
#undef STEP52
#undef __SFC_STEP52
#undef STEP26
#undef __SFC_STEP26
#undef STEP2
#undef __SFC_STEP2
#undef STEP4
#undef __SFC_STEP4
#undef STEP3
#undef __SFC_STEP3
#undef STEP5
#undef __SFC_STEP5
#undef STEP7
#undef __SFC_STEP7
#undef STEP8
#undef __SFC_STEP8
#undef STEP9
#undef __SFC_STEP9
#undef STEP10
#undef __SFC_STEP10
#undef STEP11
#undef __SFC_STEP11
#undef STEP12
#undef __SFC_STEP12
#undef STEP13
#undef __SFC_STEP13
#undef STEP14
#undef __SFC_STEP14
#undef STEP15
#undef __SFC_STEP15
#undef STEP16
#undef __SFC_STEP16
#undef STEP17
#undef __SFC_STEP17
#undef STEP18
#undef __SFC_STEP18
#undef STEP19
#undef __SFC_STEP19
#undef STEP20
#undef __SFC_STEP20
#undef STEP21
#undef __SFC_STEP21
#undef STEP22
#undef __SFC_STEP22
#undef STEP23
#undef __SFC_STEP23
#undef STEP24
#undef __SFC_STEP24
#undef STEP25
#undef __SFC_STEP25
#undef STEP1
#undef __SFC_STEP1
#undef STEP6
#undef __SFC_STEP6
#undef STEP47
#undef __SFC_STEP47
#undef STEP46
#undef __SFC_STEP46
#undef STEP28
#undef __SFC_STEP28
#undef STEP27
#undef __SFC_STEP27
#undef STEP29
#undef __SFC_STEP29
#undef STEP31
#undef __SFC_STEP31
#undef STEP32
#undef __SFC_STEP32
#undef STEP33
#undef __SFC_STEP33
#undef STEP34
#undef __SFC_STEP34
#undef STEP35
#undef __SFC_STEP35
#undef STEP36
#undef __SFC_STEP36
#undef STEP37
#undef __SFC_STEP37
#undef STEP38
#undef __SFC_STEP38
#undef STEP39
#undef __SFC_STEP39
#undef STEP40
#undef __SFC_STEP40
#undef STEP41
#undef __SFC_STEP41
#undef STEP42
#undef __SFC_STEP42
#undef STEP43
#undef __SFC_STEP43
#undef STEP44
#undef __SFC_STEP44
#undef STEP45
#undef __SFC_STEP45
#undef STEP48
#undef __SFC_STEP48
#undef STEP49
#undef __SFC_STEP49
#undef STEP50
#undef __SFC_STEP50
#undef STEP51
#undef __SFC_STEP51
#undef STEP53
#undef __SFC_STEP53
#undef STEP54
#undef __SFC_STEP54
#undef STEP55
#undef __SFC_STEP55
#undef STEP30
#undef __SFC_STEP30
#undef STEP80
#undef __SFC_STEP80
#undef STEP58
#undef __SFC_STEP58
#undef STEP57
#undef __SFC_STEP57
#undef STEP56
#undef __SFC_STEP56
#undef STEP59
#undef __SFC_STEP59
#undef STEP61
#undef __SFC_STEP61
#undef STEP62
#undef __SFC_STEP62
#undef STEP63
#undef __SFC_STEP63
#undef STEP64
#undef __SFC_STEP64
#undef STEP65
#undef __SFC_STEP65
#undef STEP66
#undef __SFC_STEP66
#undef STEP67
#undef __SFC_STEP67
#undef STEP68
#undef __SFC_STEP68
#undef STEP69
#undef __SFC_STEP69
#undef STEP70
#undef __SFC_STEP70
#undef STEP71
#undef __SFC_STEP71
#undef STEP72
#undef __SFC_STEP72
#undef STEP73
#undef __SFC_STEP73
#undef STEP74
#undef __SFC_STEP74
#undef STEP75
#undef __SFC_STEP75
#undef STEP76
#undef __SFC_STEP76
#undef STEP77
#undef __SFC_STEP77
#undef STEP78
#undef __SFC_STEP78
#undef STEP79
#undef __SFC_STEP79
#undef STEP81
#undef __SFC_STEP81
#undef STEP82
#undef __SFC_STEP82
#undef STEP83
#undef __SFC_STEP83
#undef STEP60
#undef __SFC_STEP60
#undef STEP91
#undef __SFC_STEP91
#undef STEP89
#undef __SFC_STEP89
#undef STEP86
#undef __SFC_STEP86
#undef STEP85
#undef __SFC_STEP85
#undef STEP84
#undef __SFC_STEP84
#undef STEP87
#undef __SFC_STEP87
#undef STEP90
#undef __SFC_STEP90
#undef STEP98
#undef __SFC_STEP98
#undef STEP92
#undef __SFC_STEP92
#undef STEP93
#undef __SFC_STEP93
#undef STEP99
#undef __SFC_STEP99
#undef STEP94
#undef __SFC_STEP94
#undef STEP95
#undef __SFC_STEP95
#undef STEP96
#undef __SFC_STEP96
#undef STEP97
#undef __SFC_STEP97
#undef STEP100
#undef __SFC_STEP100
#undef STEP101
#undef __SFC_STEP101
#undef STEP102
#undef __SFC_STEP102
#undef STEP88
#undef __SFC_STEP88

// Actions undefinitions
#undef __SFC_ACTION0
#undef __SFC_WAREHOUSEBUSY
#undef __SFC_RUNUNLOAD
#undef __SFC_RUNFRONTSAT1_EX
#undef __SFC_RUNFRONTAT1_EX
#undef __SFC_RUNFRONTSAT2_EX
#undef __SFC_RUNFRONTSBT1_EX
#undef __SFC_RUNFRONTSBT2_EX
#undef __SFC_RUNFRONTSCT1_EX
#undef __SFC_RUNFRONTSCT2_EX
#undef __SFC_RUNFRONTMT1_EX
#undef __SFC_RUNFRONTMT2_EX
#undef __SFC_RUNFRONTCT1_EX
#undef __SFC_SENDDOWNCT2_EX
#undef __SFC_PUSHTOROLLCT4_EX
#undef __SFC_RUNFRONTCT4_EX
#undef __SFC_PUSHTOROLLCT5_EX
#undef __SFC_RUNFRONTCT5_EX
#undef __SFC_PUSHTOROLLCT6_EX
#undef __SFC_RUNTRANSFORMMACH1
#undef __SFC_SENDDOWNSAT2_EX
#undef __SFC_TOOLPIECESAT3_EX
#undef __SFC_RUNFRONTSAT4_EX
#undef __SFC_TOOLPIECESAT5_EX
#undef __SFC_SENDLEFTDOWNSAT6_EX
#undef __SFC_RUNBACKSAT7_EX
#undef __SFC_PUTPIECEINSIGNAL_EX





void PROGRAM2_init__(PROGRAM2 *data__, BOOL retain) {
  __INIT_LOCATED(INT,__IW0_0_2_0,data__->WAREHOUSEIN,retain)
  __INIT_LOCATED_VALUE(data__->WAREHOUSEIN,2)
  __INIT_VAR(data__->P1_REG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P2_REG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P3_REG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P4_REG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P5_REG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P6_REG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P7_REG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P8_REG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P9_REG,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(BOOL,__IX0_0_0_0,data__->SENSORAT1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORAT1,__BOOL_LITERAL(FALSE))
  UINT i;
  data__->__nb_steps = 11;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 10;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 19;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define INITIALLOAD __step_list[0]
#define __SFC_INITIALLOAD 0
#define PUTP1 __step_list[1]
#define __SFC_PUTP1 1
#define STEP1 __step_list[2]
#define __SFC_STEP1 2
#define PUTP2 __step_list[3]
#define __SFC_PUTP2 3
#define PUTP3 __step_list[4]
#define __SFC_PUTP3 4
#define PUTP4 __step_list[5]
#define __SFC_PUTP4 5
#define PUTP6 __step_list[6]
#define __SFC_PUTP6 6
#define PUTP7 __step_list[7]
#define __SFC_PUTP7 7
#define PUTP8 __step_list[8]
#define __SFC_PUTP8 8
#define PUTP5 __step_list[9]
#define __SFC_PUTP5 9
#define PUTP9 __step_list[10]
#define __SFC_PUTP9 10

// Actions definitions
#define __SFC_P1 0
#define __SFC_RESETWAREHOUSE 1
#define __SFC_P2 2
#define __SFC_P3 3
#define __SFC_P4 4
#define __SFC_P6 5
#define __SFC_P7 6
#define __SFC_P8 7
#define __SFC_P5 8
#define __SFC_P9 9

// Code part
void PROGRAM2_body__(PROGRAM2 *data__) {
  // Initialise TEMP variables

  INT i;
  TIME elapsed_time, current_time;

  // Calculate elapsed_time
  current_time = __CURRENT_TIME;
  elapsed_time = __time_sub(current_time, data__->__lasttick_time);
  data__->__lasttick_time = current_time;
  // Transitions initialization
  if (__DEBUG) {
    for (i = 0; i < data__->__nb_transitions; i++) {
      data__->__transition_list[i] = data__->__debug_transition_list[i];
    }
  }
  // Steps initialization
  for (i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i].prev_state = __GET_VAR(data__->__step_list[i].X);
    if (__GET_VAR(data__->__step_list[i].X)) {
      data__->__step_list[i].T.value = __time_add(data__->__step_list[i].T.value, elapsed_time);
    }
  }
  // Actions initialization
  for (i = 0; i < data__->__nb_actions; i++) {
    __SET_VAR(data__->,__action_list[i].state,,0);
    data__->__action_list[i].set = 0;
    data__->__action_list[i].reset = 0;
    if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].set_remaining_time = __time_sub(data__->__action_list[i].set_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].set_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].set = 1;
      }
    }
    if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) > 0) {
      data__->__action_list[i].reset_remaining_time = __time_sub(data__->__action_list[i].reset_remaining_time, elapsed_time);
      if (__time_cmp(data__->__action_list[i].reset_remaining_time, __time_to_timespec(1, 0, 0, 0, 0, 0)) <= 0) {
        data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
        data__->__action_list[i].reset = 1;
      }
    }
  }

  // Transitions fire test
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[0],,__GET_VAR(data__->P1_REG,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->P1_REG,));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->PUTP1.X)) {
    __SET_VAR(data__->,__transition_list[1],,__GET_LOCATED(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_LOCATED(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
    __SET_VAR(data__->,__transition_list[2],,!(__GET_LOCATED(data__->SENSORAT1,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,!(__GET_LOCATED(data__->SENSORAT1,)));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[3],,__GET_VAR(data__->P2_REG,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->P2_REG,));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->PUTP2.X)) {
    __SET_VAR(data__->,__transition_list[4],,__GET_LOCATED(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_LOCATED(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_VAR(data__->P3_REG,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->P3_REG,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->PUTP3.X)) {
    __SET_VAR(data__->,__transition_list[6],,__GET_LOCATED(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_LOCATED(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_VAR(data__->P4_REG,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->P4_REG,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->PUTP4.X)) {
    __SET_VAR(data__->,__transition_list[8],,__GET_LOCATED(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_LOCATED(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[9],,__GET_VAR(data__->P6_REG,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->P6_REG,));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->PUTP6.X)) {
    __SET_VAR(data__->,__transition_list[10],,__GET_LOCATED(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_LOCATED(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->P7_REG,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->P7_REG,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->PUTP7.X)) {
    __SET_VAR(data__->,__transition_list[12],,__GET_LOCATED(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_LOCATED(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_VAR(data__->P8_REG,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->P8_REG,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->PUTP8.X)) {
    __SET_VAR(data__->,__transition_list[14],,__GET_LOCATED(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_LOCATED(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[15],,__GET_VAR(data__->P5_REG,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->P5_REG,));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->PUTP5.X)) {
    __SET_VAR(data__->,__transition_list[16],,__GET_LOCATED(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_LOCATED(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->INITIALLOAD.X)) {
    __SET_VAR(data__->,__transition_list[17],,__GET_VAR(data__->P9_REG,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->P9_REG,));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->PUTP9.X)) {
    __SET_VAR(data__->,__transition_list[18],,__GET_LOCATED(data__->SENSORAT1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_LOCATED(data__->SENSORAT1,));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,PUTP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,PUTP2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,PUTP3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,PUTP4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,PUTP6.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,PUTP7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,PUTP8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,PUTP5.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,INITIALLOAD.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,PUTP9.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,PUTP1.X,,1);
    data__->PUTP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,INITIALLOAD.X,,1);
    data__->INITIALLOAD.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,PUTP2.X,,1);
    data__->PUTP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,PUTP3.X,,1);
    data__->PUTP3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,PUTP4.X,,1);
    data__->PUTP4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,PUTP6.X,,1);
    data__->PUTP6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,PUTP7.X,,1);
    data__->PUTP7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,PUTP8.X,,1);
    data__->PUTP8.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,PUTP5.X,,1);
    data__->PUTP5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,PUTP9.X,,1);
    data__->PUTP9.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // PUTP1 action associations
  {
    char active = __GET_VAR(data__->PUTP1.X);
    char activated = active && !data__->PUTP1.prev_state;
    char desactivated = !active && data__->PUTP1.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P1].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P1].state,,0);};

  }

  // STEP1 action associations
  {
    char active = __GET_VAR(data__->STEP1.X);
    char activated = active && !data__->STEP1.prev_state;
    char desactivated = !active && data__->STEP1.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_RESETWAREHOUSE].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_RESETWAREHOUSE].state,,0);};

  }

  // PUTP2 action associations
  {
    char active = __GET_VAR(data__->PUTP2.X);
    char activated = active && !data__->PUTP2.prev_state;
    char desactivated = !active && data__->PUTP2.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P2].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P2].state,,0);};

  }

  // PUTP3 action associations
  {
    char active = __GET_VAR(data__->PUTP3.X);
    char activated = active && !data__->PUTP3.prev_state;
    char desactivated = !active && data__->PUTP3.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P3].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P3].state,,0);};

  }

  // PUTP4 action associations
  {
    char active = __GET_VAR(data__->PUTP4.X);
    char activated = active && !data__->PUTP4.prev_state;
    char desactivated = !active && data__->PUTP4.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P4].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P4].state,,0);};

  }

  // PUTP6 action associations
  {
    char active = __GET_VAR(data__->PUTP6.X);
    char activated = active && !data__->PUTP6.prev_state;
    char desactivated = !active && data__->PUTP6.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P6].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P6].state,,0);};

  }

  // PUTP7 action associations
  {
    char active = __GET_VAR(data__->PUTP7.X);
    char activated = active && !data__->PUTP7.prev_state;
    char desactivated = !active && data__->PUTP7.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P7].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P7].state,,0);};

  }

  // PUTP8 action associations
  {
    char active = __GET_VAR(data__->PUTP8.X);
    char activated = active && !data__->PUTP8.prev_state;
    char desactivated = !active && data__->PUTP8.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P8].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P8].state,,0);};

  }

  // PUTP5 action associations
  {
    char active = __GET_VAR(data__->PUTP5.X);
    char activated = active && !data__->PUTP5.prev_state;
    char desactivated = !active && data__->PUTP5.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P5].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P5].state,,0);};

  }

  // PUTP9 action associations
  {
    char active = __GET_VAR(data__->PUTP9.X);
    char activated = active && !data__->PUTP9.prev_state;
    char desactivated = !active && data__->PUTP9.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P9].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P9].state,,0);};

  }


  // Actions state evaluation
  for (i = 0; i < data__->__nb_actions; i++) {
    if (data__->__action_list[i].set) {
      data__->__action_list[i].set_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 1;
    }
    if (data__->__action_list[i].reset) {
      data__->__action_list[i].reset_remaining_time = __time_to_timespec(1, 0, 0, 0, 0, 0);
      data__->__action_list[i].stored = 0;
    }
    __SET_VAR(data__->,__action_list[i].state,,__GET_VAR(data__->__action_list[i].state) | data__->__action_list[i].stored);
  }

  // Actions execution
  if(__GET_VAR(data__->__action_list[__SFC_P1].state)) {
    __SET_LOCATED(data__->,WAREHOUSEIN,,1);
  }

  if(__GET_VAR(data__->__action_list[__SFC_RESETWAREHOUSE].state)) {
    __SET_LOCATED(data__->,WAREHOUSEIN,,0);
  }

  if(__GET_VAR(data__->__action_list[__SFC_P2].state)) {
    __SET_LOCATED(data__->,WAREHOUSEIN,,2);
  }

  if(__GET_VAR(data__->__action_list[__SFC_P3].state)) {
    __SET_LOCATED(data__->,WAREHOUSEIN,,3);
  }

  if(__GET_VAR(data__->__action_list[__SFC_P4].state)) {
    __SET_LOCATED(data__->,WAREHOUSEIN,,4);
  }

  if(__GET_VAR(data__->__action_list[__SFC_P6].state)) {
    __SET_LOCATED(data__->,WAREHOUSEIN,,6);
  }

  if(__GET_VAR(data__->__action_list[__SFC_P7].state)) {
    __SET_LOCATED(data__->,WAREHOUSEIN,,7);
  }

  if(__GET_VAR(data__->__action_list[__SFC_P8].state)) {
    __SET_LOCATED(data__->,WAREHOUSEIN,,8);
  }

  if(__GET_VAR(data__->__action_list[__SFC_P5].state)) {
    __SET_LOCATED(data__->,WAREHOUSEIN,,5);
  }

  if(__GET_VAR(data__->__action_list[__SFC_P9].state)) {
    __SET_LOCATED(data__->,WAREHOUSEIN,,9);
  }



  goto __end;

__end:
  return;
} // PROGRAM2_body__() 

// Steps undefinitions
#undef INITIALLOAD
#undef __SFC_INITIALLOAD
#undef PUTP1
#undef __SFC_PUTP1
#undef STEP1
#undef __SFC_STEP1
#undef PUTP2
#undef __SFC_PUTP2
#undef PUTP3
#undef __SFC_PUTP3
#undef PUTP4
#undef __SFC_PUTP4
#undef PUTP6
#undef __SFC_PUTP6
#undef PUTP7
#undef __SFC_PUTP7
#undef PUTP8
#undef __SFC_PUTP8
#undef PUTP5
#undef __SFC_PUTP5
#undef PUTP9
#undef __SFC_PUTP9

// Actions undefinitions
#undef __SFC_P1
#undef __SFC_RESETWAREHOUSE
#undef __SFC_P2
#undef __SFC_P3
#undef __SFC_P4
#undef __SFC_P6
#undef __SFC_P7
#undef __SFC_P8
#undef __SFC_P5
#undef __SFC_P9





