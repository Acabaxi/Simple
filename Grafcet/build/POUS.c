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
  __INIT_VAR(data__->SENDDOWNSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENDUPSIGNAL,__BOOL_LITERAL(FALSE),retain)
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
  data__->__nb_steps = 23;
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
  data__->__nb_transitions = 30;
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
#define MOVEFRONT1 __step_list[9]
#define __SFC_MOVEFRONT1 9
#define ROTATINGLEFT __step_list[10]
#define __SFC_ROTATINGLEFT 10
#define NOTBUSYBACK0 __step_list[11]
#define __SFC_NOTBUSYBACK0 11
#define MOVEBACKSTEP0 __step_list[12]
#define __SFC_MOVEBACKSTEP0 12
#define TURNOFFBACK0 __step_list[13]
#define __SFC_TURNOFFBACK0 13
#define RESETROTATE0 __step_list[14]
#define __SFC_RESETROTATE0 14
#define RESETDONEL __step_list[15]
#define __SFC_RESETDONEL 15
#define MOVEFRONT0 __step_list[16]
#define __SFC_MOVEFRONT0 16
#define ROTATINGRIGHT __step_list[17]
#define __SFC_ROTATINGRIGHT 17
#define NOTBUSYFRONT0 __step_list[18]
#define __SFC_NOTBUSYFRONT0 18
#define MOVEFRONTSTEP0 __step_list[19]
#define __SFC_MOVEFRONTSTEP0 19
#define TURNOFFFRONT0 __step_list[20]
#define __SFC_TURNOFFFRONT0 20
#define RESETROTATE __step_list[21]
#define __SFC_RESETROTATE 21
#define RESETDONER __step_list[22]
#define __SFC_RESETDONER 22

// Actions definitions
#define __SFC_COMPUTE_FUNCTION_BLOCKS 0
#define __SFC_ISBUSY 1
#define __SFC_FORWARDMOTOR 2
#define __SFC_FORWARDTIMERON 3
#define __SFC_BACKMOTOR 4
#define __SFC_LEFTROTMOTOR 5
#define __SFC_RIGHTROTMOTOR 6

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
    __SET_VAR(data__->,__transition_list[12],,__GET_VAR(data__->SENDUPSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->SENDUPSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->MOVEFRONT1.X)) {
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
  if (__GET_VAR(data__->ROTATINGLEFT.X)) {
    __SET_VAR(data__->,__transition_list[14],,__GET_VAR(data__->SENSORROTLEFT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->SENSORROTLEFT,));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->NOTBUSYBACK0.X)) {
    __SET_VAR(data__->,__transition_list[15],,!(__GET_VAR(data__->UPNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,!(__GET_VAR(data__->UPNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[16],,__GET_VAR(data__->REACHEDSENSORUP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->REACHEDSENSORUP,));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->TURNOFFBACK0.X)) {
    __SET_VAR(data__->,__transition_list[17],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->RESETROTATE0.X)) {
    __SET_VAR(data__->,__transition_list[18],,__GET_VAR(data__->SENSORROTRIGHT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->SENSORROTRIGHT,));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->RESETDONEL.X)) {
    __SET_VAR(data__->,__transition_list[19],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[20],,__GET_VAR(data__->TON3.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->TON3.Q,));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[21],,__GET_VAR(data__->SENDDOWNSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->SENDDOWNSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->MOVEFRONT0.X)) {
    __SET_VAR(data__->,__transition_list[22],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->ROTATINGRIGHT.X)) {
    __SET_VAR(data__->,__transition_list[23],,__GET_VAR(data__->SENSORROTRIGHT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->SENSORROTRIGHT,));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->NOTBUSYFRONT0.X)) {
    __SET_VAR(data__->,__transition_list[24],,!(__GET_VAR(data__->DOWNNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,!(__GET_VAR(data__->DOWNNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->MOVEFRONTSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[25],,__GET_VAR(data__->REACHEDSENSORDOWN,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->REACHEDSENSORDOWN,));
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->TURNOFFFRONT0.X)) {
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
  if (__GET_VAR(data__->RESETROTATE.X)) {
    __SET_VAR(data__->,__transition_list[27],,__GET_VAR(data__->SENSORROTLEFT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->SENSORROTLEFT,));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->RESETDONER.X)) {
    __SET_VAR(data__->,__transition_list[28],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->MOVEFRONTSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[29],,__GET_VAR(data__->TON2.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->TON2.Q,));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
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
    __SET_VAR(data__->,MOVEFRONT1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,ROTATINGLEFT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,NOTBUSYBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,MOVEBACKSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,TURNOFFBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,RESETROTATE0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,RESETDONEL.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,MOVEBACKSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,MOVEFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,ROTATINGRIGHT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,NOTBUSYFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,MOVEFRONTSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,TURNOFFFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,RESETROTATE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,RESETDONER.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
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
    __SET_VAR(data__->,MOVEFRONT1.X,,1);
    data__->MOVEFRONT1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,ROTATINGLEFT.X,,1);
    data__->ROTATINGLEFT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,NOTBUSYBACK0.X,,1);
    data__->NOTBUSYBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,MOVEBACKSTEP0.X,,1);
    data__->MOVEBACKSTEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,TURNOFFBACK0.X,,1);
    data__->TURNOFFBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,RESETROTATE0.X,,1);
    data__->RESETROTATE0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,RESETDONEL.X,,1);
    data__->RESETDONEL.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,TURNOFFBACK0.X,,1);
    data__->TURNOFFBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,MOVEFRONT0.X,,1);
    data__->MOVEFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,ROTATINGRIGHT.X,,1);
    data__->ROTATINGRIGHT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,NOTBUSYFRONT0.X,,1);
    data__->NOTBUSYFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,MOVEFRONTSTEP0.X,,1);
    data__->MOVEFRONTSTEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,TURNOFFFRONT0.X,,1);
    data__->TURNOFFFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,RESETROTATE.X,,1);
    data__->RESETROTATE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,RESETDONER.X,,1);
    data__->RESETDONER.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
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

  // MOVEFRONT1 action associations
  {
    char active = __GET_VAR(data__->MOVEFRONT1.X);
    char activated = active && !data__->MOVEFRONT1.prev_state;
    char desactivated = !active && data__->MOVEFRONT1.prev_state;

    if (active)       {__SET_VAR(data__->,BACKMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,BACKMOTOR,,0);};

  }

  // ROTATINGLEFT action associations
  {
    char active = __GET_VAR(data__->ROTATINGLEFT.X);
    char activated = active && !data__->ROTATINGLEFT.prev_state;
    char desactivated = !active && data__->ROTATINGLEFT.prev_state;

    if (active)       {__SET_VAR(data__->,LEFTROTMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,LEFTROTMOTOR,,0);};

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

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

  // RESETROTATE0 action associations
  {
    char active = __GET_VAR(data__->RESETROTATE0.X);
    char activated = active && !data__->RESETROTATE0.prev_state;
    char desactivated = !active && data__->RESETROTATE0.prev_state;

    if (active)       {__SET_VAR(data__->,RIGHTROTMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,RIGHTROTMOTOR,,0);};

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
  if (data__->__action_list[__SFC_LEFTROTMOTOR].reset) {
    __SET_VAR(data__->,LEFTROTMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_LEFTROTMOTOR].set) {
    __SET_VAR(data__->,LEFTROTMOTOR,,1);
  }
  if (data__->__action_list[__SFC_RIGHTROTMOTOR].reset) {
    __SET_VAR(data__->,RIGHTROTMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_RIGHTROTMOTOR].set) {
    __SET_VAR(data__->,RIGHTROTMOTOR,,1);
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
#undef MOVEFRONT1
#undef __SFC_MOVEFRONT1
#undef ROTATINGLEFT
#undef __SFC_ROTATINGLEFT
#undef NOTBUSYBACK0
#undef __SFC_NOTBUSYBACK0
#undef MOVEBACKSTEP0
#undef __SFC_MOVEBACKSTEP0
#undef TURNOFFBACK0
#undef __SFC_TURNOFFBACK0
#undef RESETROTATE0
#undef __SFC_RESETROTATE0
#undef RESETDONEL
#undef __SFC_RESETDONEL
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
#undef __SFC_COMPUTE_FUNCTION_BLOCKS
#undef __SFC_ISBUSY
#undef __SFC_FORWARDMOTOR
#undef __SFC_FORWARDTIMERON
#undef __SFC_BACKMOTOR
#undef __SFC_LEFTROTMOTOR
#undef __SFC_RIGHTROTMOTOR





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





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  LINEARCONVEYOR_init__(&data__->AT1,retain);
  LINEARCONVEYOR_init__(&data__->SAT1,retain);
  ROTARYCONVEYOR_init__(&data__->SAT2,retain);
  LINEARCONVEYOR_init__(&data__->SBT1,retain);
  __INIT_EXTERNAL(BOOL,SENSORAT1_EX,data__->SENSORAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORAT2_EX,data__->SENSORAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT1_EX,data__->SENSORSAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT2_EX,data__->SENSORSAT2_EX,retain)
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
  LINEARCONVEYOR_init__(&data__->AT2,retain);
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
  __SET_VAR(data__->CT2.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKCT2_EX,));
  __SET_VAR(data__->CT2.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTCT2_EX,));
  __SET_VAR(data__->CT2.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNCT2_EX,));
  __SET_VAR(data__->CT2.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTCT2,));
  __SET_VAR(data__->CT2.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTCT2,));
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
  __SET_VAR(data__->SAT2.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSAT2_EX,));
  __SET_VAR(data__->SAT2.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNSAT2_EX,));
  __SET_VAR(data__->SAT2.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTSAT2,));
  __SET_VAR(data__->SAT2.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTSAT2,));
  __SET_VAR(data__->SAT2.,FRONTNOTBUSY,,__GET_VAR(data__->SBT1.ISBUSY,));
  __SET_VAR(data__->SAT2.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSBT1,));
  __SET_VAR(data__->SAT2.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSAT2,));
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
  __SET_EXTERNAL(data__->,SENSORCT4_EX,,__GET_LOCATED(data__->SENSORCT4,));
  __SET_VAR(data__->PM1.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORPM1,));
  ROLL_body__(&data__->PM1);
  __SET_VAR(data__->CT4.,ROLLBUSY,,__GET_VAR(data__->PM1.HASPIECE,));
  __SET_VAR(data__->CT4.,PUSHSIGNAL,,__GET_EXTERNAL(data__->PUSHTOROLLCT4_EX,));
  __SET_VAR(data__->CT4.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTCT4_EX,));
  __SET_VAR(data__->CT4.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT4,));
  __SET_VAR(data__->CT4.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORCT5,));
  __SET_VAR(data__->CT4.,SENSORPUSHFORWARD,,__GET_LOCATED(data__->SENSORPUSHFORWARDCT4,));
  __SET_VAR(data__->CT4.,SENSORPUSHBACK,,__GET_LOCATED(data__->SENSORPUSHBACKCT4,));
  PUSHER_body__(&data__->CT4);
  __SET_LOCATED(data__->,FORWARDCT4,,__GET_VAR(data__->CT4.FORWARDMOTOR,));
  __SET_LOCATED(data__->,PUSHFORWARDCT4,,__GET_VAR(data__->CT4.PUSHMOTORFORWARD,));
  __SET_LOCATED(data__->,PUSHBACKCT4,,__GET_VAR(data__->CT4.PUSHMOTORBACK,));
  __SET_VAR(data__->PM2.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORPM2,));
  ROLL_body__(&data__->PM2);
  __SET_VAR(data__->CT5.,ROLLBUSY,,__GET_VAR(data__->PM2.HASPIECE,));
  __SET_VAR(data__->CT5.,PUSHSIGNAL,,__GET_EXTERNAL(data__->PUSHTOROLLCT5_EX,));
  __SET_VAR(data__->CT5.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTCT5_EX,));
  __SET_VAR(data__->CT5.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT5,));
  __SET_VAR(data__->CT5.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORCT6,));
  __SET_VAR(data__->CT5.,SENSORPUSHFORWARD,,__GET_LOCATED(data__->SENSORPUSHFORWARDCT5,));
  __SET_VAR(data__->CT5.,SENSORPUSHBACK,,__GET_LOCATED(data__->SENSORPUSHBACKCT5,));
  PUSHER_body__(&data__->CT5);
  __SET_LOCATED(data__->,FORWARDCT5,,__GET_VAR(data__->CT5.FORWARDMOTOR,));
  __SET_EXTERNAL(data__->,SENSORCT5_EX,,__GET_LOCATED(data__->SENSORCT5,));
  __SET_LOCATED(data__->,PUSHFORWARDCT5,,__GET_VAR(data__->CT5.PUSHMOTORFORWARD,));
  __SET_LOCATED(data__->,PUSHBACKCT5,,__GET_VAR(data__->CT5.PUSHMOTORBACK,));
  __SET_EXTERNAL(data__->,SENSORCT6_EX,,__GET_LOCATED(data__->SENSORCT6,));
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
  __SET_LOCATED(data__->,FORWARDCT6,,__GET_VAR(data__->CT6.FORWARDMOTOR,));
  __SET_LOCATED(data__->,PUSHFORWARDCT6,,__GET_VAR(data__->CT6.PUSHMOTORFORWARD,));
  __SET_LOCATED(data__->,PUSHBACKCT6,,__GET_VAR(data__->CT6.PUSHMOTORBACK,));
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
  __SET_VAR(data__->AT2.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORAT2,));
  __SET_VAR(data__->AT2.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKAT2_EX,));
  LINEARCONVEYOR_body__(&data__->AT2);
  __SET_VAR(data__->SAT7.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSAT7,));
  __SET_VAR(data__->SAT7.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKSAT7_EX,));
  __SET_VAR(data__->SAT7.,BACKNOTBUSY,,__GET_VAR(data__->AT2.ISBUSY,));
  __SET_VAR(data__->SAT7.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSAT6,));
  __SET_VAR(data__->SAT7.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORAT2,));
  LINEARCONVEYOR_body__(&data__->SAT7);
  __SET_VAR(data__->SAT6.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKSAT6_EX,));
  __SET_VAR(data__->SAT6.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNSAT6_EX,));
  __SET_VAR(data__->SAT6.,SENDUPSIGNAL,,__GET_EXTERNAL(data__->SENDUPSAT6_EX,));
  __SET_VAR(data__->SAT6.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTSAT6,));
  __SET_VAR(data__->SAT6.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTSAT6,));
  __SET_VAR(data__->SAT6.,BACKNOTBUSY,,__GET_VAR(data__->SAT7.ISBUSY,));
  __SET_VAR(data__->SAT6.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSBT7,));
  __SET_VAR(data__->SAT6.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSAT6,));
  __SET_VAR(data__->SAT6.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORSAT7,));
  ROTARYCONVEYOR_body__(&data__->SAT6);
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
  __SET_LOCATED(data__->,BACKSAT6,,__GET_VAR(data__->SAT6.BACKMOTOR,));
  __SET_LOCATED(data__->,FORWARDMT6,,__GET_VAR(data__->MT6.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDSBT7,,__GET_VAR(data__->SBT7.FORWARDMOTOR,));
  __SET_LOCATED(data__->,BACKSBT6,,__GET_VAR(data__->SBT6.BACKMOTOR,));
  __SET_LOCATED(data__->,RIGHTROTSCT6,,__GET_VAR(data__->SCT6.RIGHTROTMOTOR,));
  __SET_LOCATED(data__->,FORWARDCT7,,__GET_VAR(data__->CT7.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDAT2,,__GET_VAR(data__->AT2.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDSAT7,,__GET_VAR(data__->SAT7.FORWARDMOTOR,));
  __SET_LOCATED(data__->,RIGHTROTSAT6,,__GET_VAR(data__->SAT6.RIGHTROTMOTOR,));
  __SET_LOCATED(data__->,BACKMT6,,__GET_VAR(data__->MT6.BACKMOTOR,));
  __SET_LOCATED(data__->,RIGHTROTCT8,,__GET_VAR(data__->CT8.RIGHTROTMOTOR,));
  __SET_LOCATED(data__->,RIGHTROTSBT6,,__GET_VAR(data__->SBT6.RIGHTROTMOTOR,));
  __SET_LOCATED(data__->,LEFTROTSCT6,,__GET_VAR(data__->SCT6.LEFTROTMOTOR,));
  __SET_LOCATED(data__->,BACKSBT7,,__GET_VAR(data__->SBT7.BACKMOTOR,));
  __SET_LOCATED(data__->,FORWARDMT5,,__GET_VAR(data__->MT5.FORWARDMOTOR,));
  __SET_LOCATED(data__->,BACKAT2,,__GET_VAR(data__->AT2.BACKMOTOR,));
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





void PROGRAM1_init__(PROGRAM1 *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,II,data__->II,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTAT1_EX,data__->RUNFRONTAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT1_EX,data__->RUNFRONTSAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT2_EX,data__->RUNFRONTSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT1_EX,data__->RUNFRONTSBT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT2_EX,data__->RUNFRONTSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT1_EX,data__->RUNFRONTSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT2_EX,data__->RUNFRONTSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT1_EX,data__->RUNFRONTMT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT2_EX,data__->RUNFRONTMT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT1_EX,data__->RUNFRONTCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSAT2_EX,data__->SENDDOWNSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNCT2_EX,data__->SENDDOWNCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORAT1_EX,data__->SENSORAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT1_EX,data__->SENSORSAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT2_EX,data__->SENSORSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT1_EX,data__->SENSORSBT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT2_EX,data__->SENSORSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT1_EX,data__->SENSORSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT2_EX,data__->SENSORSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT1_EX,data__->SENSORMT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT2_EX,data__->SENSORMT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT1_EX,data__->SENSORCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT2_EX,data__->SENSORCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT4_EX,data__->SENSORCT4_EX,retain)
  UINT i;
  data__->__nb_steps = 26;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 11;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 26;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define STEP0 __step_list[0]
#define __SFC_STEP0 0
#define STEP1 __step_list[1]
#define __SFC_STEP1 1
#define STEP2 __step_list[2]
#define __SFC_STEP2 2
#define STEP4 __step_list[3]
#define __SFC_STEP4 3
#define STEP3 __step_list[4]
#define __SFC_STEP3 4
#define STEP5 __step_list[5]
#define __SFC_STEP5 5
#define STEP7 __step_list[6]
#define __SFC_STEP7 6
#define STEP8 __step_list[7]
#define __SFC_STEP8 7
#define STEP9 __step_list[8]
#define __SFC_STEP9 8
#define STEP10 __step_list[9]
#define __SFC_STEP10 9
#define STEP11 __step_list[10]
#define __SFC_STEP11 10
#define STEP12 __step_list[11]
#define __SFC_STEP12 11
#define STEP13 __step_list[12]
#define __SFC_STEP13 12
#define STEP14 __step_list[13]
#define __SFC_STEP14 13
#define STEP15 __step_list[14]
#define __SFC_STEP15 14
#define STEP16 __step_list[15]
#define __SFC_STEP16 15
#define STEP17 __step_list[16]
#define __SFC_STEP17 16
#define STEP18 __step_list[17]
#define __SFC_STEP18 17
#define STEP19 __step_list[18]
#define __SFC_STEP19 18
#define STEP20 __step_list[19]
#define __SFC_STEP20 19
#define STEP21 __step_list[20]
#define __SFC_STEP21 20
#define STEP22 __step_list[21]
#define __SFC_STEP22 21
#define STEP23 __step_list[22]
#define __SFC_STEP23 22
#define STEP24 __step_list[23]
#define __SFC_STEP24 23
#define STEP25 __step_list[24]
#define __SFC_STEP25 24
#define STEP6 __step_list[25]
#define __SFC_STEP6 25

// Actions definitions
#define __SFC_RUNFRONTAT1_EX 0
#define __SFC_RUNFRONTSAT1_EX 1
#define __SFC_RUNFRONTSAT2_EX 2
#define __SFC_RUNFRONTSBT1_EX 3
#define __SFC_RUNFRONTSBT2_EX 4
#define __SFC_RUNFRONTSCT1_EX 5
#define __SFC_RUNFRONTSCT2_EX 6
#define __SFC_RUNFRONTMT1_EX 7
#define __SFC_RUNFRONTMT2_EX 8
#define __SFC_RUNFRONTCT1_EX 9
#define __SFC_SENDDOWNCT2_EX 10

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
    __SET_VAR(data__->,__transition_list[0],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
    __SET_VAR(data__->,__transition_list[1],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->STEP2.X)) {
    __SET_VAR(data__->,__transition_list[2],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->STEP4.X)) {
    __SET_VAR(data__->,__transition_list[3],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->STEP3.X)) {
    __SET_VAR(data__->,__transition_list[4],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->STEP5.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->STEP7.X)) {
    __SET_VAR(data__->,__transition_list[6],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->STEP8.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_EXTERNAL(data__->SENSORSBT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_EXTERNAL(data__->SENSORSBT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->STEP9.X)) {
    __SET_VAR(data__->,__transition_list[8],,!(__GET_EXTERNAL(data__->SENSORSBT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,!(__GET_EXTERNAL(data__->SENSORSBT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->STEP10.X)) {
    __SET_VAR(data__->,__transition_list[9],,__GET_EXTERNAL(data__->SENSORSBT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_EXTERNAL(data__->SENSORSBT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->STEP11.X)) {
    __SET_VAR(data__->,__transition_list[10],,!(__GET_EXTERNAL(data__->SENSORSBT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,!(__GET_EXTERNAL(data__->SENSORSBT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->STEP12.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_EXTERNAL(data__->SENSORSCT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_EXTERNAL(data__->SENSORSCT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->STEP13.X)) {
    __SET_VAR(data__->,__transition_list[12],,!(__GET_EXTERNAL(data__->SENSORSCT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,!(__GET_EXTERNAL(data__->SENSORSCT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->STEP14.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_EXTERNAL(data__->SENSORSCT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_EXTERNAL(data__->SENSORSCT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->STEP15.X)) {
    __SET_VAR(data__->,__transition_list[14],,!(__GET_EXTERNAL(data__->SENSORSCT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,!(__GET_EXTERNAL(data__->SENSORSCT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->STEP16.X)) {
    __SET_VAR(data__->,__transition_list[15],,__GET_EXTERNAL(data__->SENSORMT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_EXTERNAL(data__->SENSORMT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->STEP17.X)) {
    __SET_VAR(data__->,__transition_list[16],,!(__GET_EXTERNAL(data__->SENSORMT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,!(__GET_EXTERNAL(data__->SENSORMT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->STEP18.X)) {
    __SET_VAR(data__->,__transition_list[17],,__GET_EXTERNAL(data__->SENSORMT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_EXTERNAL(data__->SENSORMT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->STEP19.X)) {
    __SET_VAR(data__->,__transition_list[18],,!(__GET_EXTERNAL(data__->SENSORMT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,!(__GET_EXTERNAL(data__->SENSORMT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->STEP20.X)) {
    __SET_VAR(data__->,__transition_list[19],,__GET_EXTERNAL(data__->SENSORCT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_EXTERNAL(data__->SENSORCT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->STEP21.X)) {
    __SET_VAR(data__->,__transition_list[20],,!(__GET_EXTERNAL(data__->SENSORCT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,!(__GET_EXTERNAL(data__->SENSORCT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->STEP22.X)) {
    __SET_VAR(data__->,__transition_list[21],,__GET_EXTERNAL(data__->SENSORCT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_EXTERNAL(data__->SENSORCT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->STEP23.X)) {
    __SET_VAR(data__->,__transition_list[22],,!(__GET_EXTERNAL(data__->SENSORCT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,!(__GET_EXTERNAL(data__->SENSORCT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->STEP24.X)) {
    __SET_VAR(data__->,__transition_list[23],,__GET_EXTERNAL(data__->SENSORCT4_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_EXTERNAL(data__->SENSORCT4_EX,));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->STEP25.X)) {
    __SET_VAR(data__->,__transition_list[24],,!(__GET_EXTERNAL(data__->SENSORCT4_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,!(__GET_EXTERNAL(data__->SENSORCT4_EX,)));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->STEP6.X)) {
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

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP5.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP9.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP10.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP12.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP13.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP14.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP15.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP16.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP17.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP18.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP19.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP20.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP21.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP22.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP23.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP24.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP25.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP6.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP4.X,,1);
    data__->STEP4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP6.X,,1);
    data__->STEP6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP3.X,,1);
    data__->STEP3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP5.X,,1);
    data__->STEP5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP7.X,,1);
    data__->STEP7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP8.X,,1);
    data__->STEP8.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP9.X,,1);
    data__->STEP9.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP10.X,,1);
    data__->STEP10.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP11.X,,1);
    data__->STEP11.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP12.X,,1);
    data__->STEP12.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP13.X,,1);
    data__->STEP13.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP14.X,,1);
    data__->STEP14.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP15.X,,1);
    data__->STEP15.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP16.X,,1);
    data__->STEP16.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP17.X,,1);
    data__->STEP17.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP18.X,,1);
    data__->STEP18.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP19.X,,1);
    data__->STEP19.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP20.X,,1);
    data__->STEP20.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP21.X,,1);
    data__->STEP21.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP22.X,,1);
    data__->STEP22.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP23.X,,1);
    data__->STEP23.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP24.X,,1);
    data__->STEP24.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP25.X,,1);
    data__->STEP25.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // STEP1 action associations
  {
    char active = __GET_VAR(data__->STEP1.X);
    char activated = active && !data__->STEP1.prev_state;
    char desactivated = !active && data__->STEP1.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,0);};

  }

  // STEP2 action associations
  {
    char active = __GET_VAR(data__->STEP2.X);
    char activated = active && !data__->STEP2.prev_state;
    char desactivated = !active && data__->STEP2.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,0);};

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
  if (data__->__action_list[__SFC_RUNFRONTAT1_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTAT1_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTSAT1_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTSAT1_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,1);
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


  goto __end;

__end:
  return;
} // PROGRAM1_body__() 

// Steps undefinitions
#undef STEP0
#undef __SFC_STEP0
#undef STEP1
#undef __SFC_STEP1
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
#undef STEP6
#undef __SFC_STEP6

// Actions undefinitions
#undef __SFC_RUNFRONTAT1_EX
#undef __SFC_RUNFRONTSAT1_EX
#undef __SFC_RUNFRONTSAT2_EX
#undef __SFC_RUNFRONTSBT1_EX
#undef __SFC_RUNFRONTSBT2_EX
#undef __SFC_RUNFRONTSCT1_EX
#undef __SFC_RUNFRONTSCT2_EX
#undef __SFC_RUNFRONTMT1_EX
#undef __SFC_RUNFRONTMT2_EX
#undef __SFC_RUNFRONTCT1_EX
#undef __SFC_SENDDOWNCT2_EX





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





