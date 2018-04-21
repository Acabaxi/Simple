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
  __INIT_VAR(data__->BACKSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDTIMERON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FRONTNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORFRONT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORBACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSOR,__BOOL_LITERAL(FALSE),retain)
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
    __SET_VAR(data__->,__transition_list[2],,__GET_VAR(data__->FRONTNOTBUSY,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->FRONTNOTBUSY,));
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
    __SET_VAR(data__->,__transition_list[8],,__GET_VAR(data__->BACKNOTBUSY,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->BACKNOTBUSY,));
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
  __INIT_VAR(data__->REACHEDSENSORBACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSOR,__BOOL_LITERAL(FALSE),retain)
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
    __SET_VAR(data__->,__transition_list[2],,__GET_VAR(data__->FRONTNOTBUSY,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->FRONTNOTBUSY,));
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
    __SET_VAR(data__->,__transition_list[8],,__GET_VAR(data__->BACKNOTBUSY,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->BACKNOTBUSY,));
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
    __SET_VAR(data__->,__transition_list[15],,__GET_VAR(data__->UPNOTBUSY,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->UPNOTBUSY,));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[16],,__GET_VAR(data__->REACHEDSENSORBACK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->REACHEDSENSORBACK,));
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
    __SET_VAR(data__->,__transition_list[24],,__GET_VAR(data__->DOWNNOTBUSY,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->DOWNNOTBUSY,));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->MOVEFRONTSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[25],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->REACHEDSENSORFRONT,));
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





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  LINEARCONVEYOR_init__(&data__->AT1,retain);
  LINEARCONVEYOR_init__(&data__->SAT1,retain);
  ROTARYCONVEYOR_init__(&data__->SAT2,retain);
  __INIT_EXTERNAL(BOOL,II,data__->II,retain)
  __INIT_LOCATED(BOOL,__IX0_0_0_0,data__->SENSORAT1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_2,data__->SENSORSAT1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_3,data__->SENSORSAT2,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSAT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_23,data__->SENSORSBT1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORSBT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_5,data__->SENSORROTRIGHTSAT3,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTRIGHTSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_4,data__->SENSORROTLEFTSAT3,retain)
  __INIT_LOCATED_VALUE(data__->SENSORROTLEFTSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_1,data__->FORWARDAT1,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_6,data__->FORWARDSAT1,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_8,data__->FORWARDSAT2,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSAT2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_38,data__->FORWARDSBT1,retain)
  __INIT_LOCATED_VALUE(data__->FORWARDSBT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_10,data__->RIGHTROTSAT3,retain)
  __INIT_LOCATED_VALUE(data__->RIGHTROTSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_9,data__->LEFTROTSAT3,retain)
  __INIT_LOCATED_VALUE(data__->LEFTROTSAT3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_0,data__->BACKAT1,retain)
  __INIT_LOCATED_VALUE(data__->BACKAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_5,data__->BACKSAT1,retain)
  __INIT_LOCATED_VALUE(data__->BACKSAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_7,data__->BACKSAT2,retain)
  __INIT_LOCATED_VALUE(data__->BACKSAT2,__BOOL_LITERAL(FALSE))
  __INIT_EXTERNAL(BOOL,SENSORAT1_EX,data__->SENSORAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT1_EX,data__->SENSORSAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT2_EX,data__->SENSORSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT1_EX,data__->SENSORSBT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTAT1_EX,data__->RUNFRONTAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT1_EX,data__->RUNFRONTSAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT2_EX,data__->RUNFRONTSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT1_EX,data__->RUNFRONTSBT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSAT2_EX,data__->SENDDOWNSAT2_EX,retain)
  LINEARCONVEYOR_init__(&data__->SBT1,retain);
  __INIT_VAR(data__->NOT40_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->NOT32_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->NOT31_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_EXTERNAL(data__->,SENSORSAT1_EX,,__GET_LOCATED(data__->SENSORSAT1,));
  __SET_EXTERNAL(data__->,SENSORSAT2_EX,,__GET_LOCATED(data__->SENSORSAT2,));
  __SET_EXTERNAL(data__->,SENSORAT1_EX,,__GET_LOCATED(data__->SENSORAT1,));
  __SET_EXTERNAL(data__->,SENSORSBT1_EX,,__GET_LOCATED(data__->SENSORSBT1,));
  __SET_VAR(data__->SBT1.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSBT1_EX,));
  __SET_VAR(data__->SBT1.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSBT1,));
  LINEARCONVEYOR_body__(&data__->SBT1);
  __SET_VAR(data__->,NOT40_OUT,,!(__GET_VAR(data__->SBT1.ISBUSY,)));
  __SET_VAR(data__->SAT2.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSAT2_EX,));
  __SET_VAR(data__->SAT2.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNSAT2_EX,));
  __SET_VAR(data__->SAT2.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTSAT3,));
  __SET_VAR(data__->SAT2.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTSAT3,));
  __SET_VAR(data__->SAT2.,FRONTNOTBUSY,,__GET_VAR(data__->NOT40_OUT,));
  __SET_VAR(data__->SAT2.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSAT2,));
  ROTARYCONVEYOR_body__(&data__->SAT2);
  __SET_LOCATED(data__->,FORWARDSAT2,,__GET_VAR(data__->SAT2.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDSBT1,,__GET_VAR(data__->SBT1.FORWARDMOTOR,));
  __SET_VAR(data__->,NOT32_OUT,,!(__GET_VAR(data__->SAT2.ISBUSY,)));
  __SET_VAR(data__->SAT1.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSAT1_EX,));
  __SET_VAR(data__->SAT1.,FRONTNOTBUSY,,__GET_VAR(data__->NOT32_OUT,));
  __SET_VAR(data__->SAT1.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSAT2,));
  __SET_VAR(data__->SAT1.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSAT1,));
  LINEARCONVEYOR_body__(&data__->SAT1);
  __SET_VAR(data__->,NOT31_OUT,,!(__GET_VAR(data__->SAT1.ISBUSY,)));
  __SET_VAR(data__->AT1.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTAT1_EX,));
  __SET_VAR(data__->AT1.,FRONTNOTBUSY,,__GET_VAR(data__->NOT31_OUT,));
  __SET_VAR(data__->AT1.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSAT1,));
  __SET_VAR(data__->AT1.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORAT1,));
  LINEARCONVEYOR_body__(&data__->AT1);
  __SET_LOCATED(data__->,FORWARDAT1,,__GET_VAR(data__->AT1.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDSAT1,,__GET_VAR(data__->SAT1.FORWARDMOTOR,));
  __SET_LOCATED(data__->,RIGHTROTSAT3,,__GET_VAR(data__->SAT2.RIGHTROTMOTOR,));
  __SET_LOCATED(data__->,BACKAT1,,__GET_VAR(data__->AT1.BACKMOTOR,));
  __SET_LOCATED(data__->,BACKSAT1,,__GET_VAR(data__->SAT1.BACKMOTOR,));
  __SET_LOCATED(data__->,LEFTROTSAT3,,__GET_VAR(data__->SAT2.LEFTROTMOTOR,));

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
  __INIT_EXTERNAL(BOOL,SENDDOWNSAT2_EX,data__->SENDDOWNSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORAT1_EX,data__->SENSORAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT1_EX,data__->SENSORSAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSAT2_EX,data__->SENSORSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT1_EX,data__->SENSORSBT1_EX,retain)
  UINT i;
  data__->__nb_steps = 7;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 3;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 7;
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
#define STEP6 __step_list[6]
#define __SFC_STEP6 6

// Actions definitions
#define __SFC_RUNFRONTAT1_EX 0
#define __SFC_RUNFRONTSAT1_EX 1
#define __SFC_SENDDOWNSAT2_EX 2

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
    __SET_VAR(data__->,__transition_list[5],,__BOOL_LITERAL(FALSE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__BOOL_LITERAL(FALSE));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->STEP6.X)) {
    __SET_VAR(data__->,__transition_list[6],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
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
    __SET_VAR(data__->,STEP6.X,,1);
    data__->STEP6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP4.X,,1);
    data__->STEP4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
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
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
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

    if (active)       {__SET_EXTERNAL(data__->,SENDDOWNSAT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDDOWNSAT2_EX,,0);};

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
  if (data__->__action_list[__SFC_SENDDOWNSAT2_EX].reset) {
    __SET_EXTERNAL(data__->,SENDDOWNSAT2_EX,,0);
  }
  else if (data__->__action_list[__SFC_SENDDOWNSAT2_EX].set) {
    __SET_EXTERNAL(data__->,SENDDOWNSAT2_EX,,1);
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
#undef STEP6
#undef __SFC_STEP6

// Actions undefinitions
#undef __SFC_RUNFRONTAT1_EX
#undef __SFC_RUNFRONTSAT1_EX
#undef __SFC_SENDDOWNSAT2_EX





