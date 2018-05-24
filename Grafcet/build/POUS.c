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
#define INITIALLOAD1 __step_list[0]
#define __SFC_INITIALLOAD1 0
#define PUTP5 __step_list[1]
#define __SFC_PUTP5 1
#define STEP0 __step_list[2]
#define __SFC_STEP0 2
#define STEP1 __step_list[3]
#define __SFC_STEP1 3
#define PUTP6 __step_list[4]
#define __SFC_PUTP6 4
#define PUTP7 __step_list[5]
#define __SFC_PUTP7 5
#define PUTP9 __step_list[6]
#define __SFC_PUTP9 6
#define PUTP10 __step_list[7]
#define __SFC_PUTP10 7
#define PUTP11 __step_list[8]
#define __SFC_PUTP11 8
#define PUTP8 __step_list[9]
#define __SFC_PUTP8 9
#define PUTP12 __step_list[10]
#define __SFC_PUTP12 10
#define PUTP4 __step_list[11]
#define __SFC_PUTP4 11

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
  if (__GET_VAR(data__->INITIALLOAD1.X)) {
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
  if (__GET_VAR(data__->PUTP5.X)) {
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
  if (__GET_VAR(data__->STEP0.X)) {
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
  if (__GET_VAR(data__->STEP1.X)) {
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
  if (__GET_VAR(data__->INITIALLOAD1.X)) {
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
  if (__GET_VAR(data__->PUTP6.X)) {
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
  if (__GET_VAR(data__->INITIALLOAD1.X)) {
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
  if (__GET_VAR(data__->PUTP7.X)) {
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
  if (__GET_VAR(data__->INITIALLOAD1.X)) {
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
  if (__GET_VAR(data__->PUTP9.X)) {
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
  if (__GET_VAR(data__->INITIALLOAD1.X)) {
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
  if (__GET_VAR(data__->PUTP10.X)) {
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
  if (__GET_VAR(data__->INITIALLOAD1.X)) {
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
  if (__GET_VAR(data__->PUTP11.X)) {
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
  if (__GET_VAR(data__->INITIALLOAD1.X)) {
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
  if (__GET_VAR(data__->PUTP8.X)) {
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
  if (__GET_VAR(data__->INITIALLOAD1.X)) {
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
  if (__GET_VAR(data__->PUTP12.X)) {
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
  if (__GET_VAR(data__->INITIALLOAD1.X)) {
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
  if (__GET_VAR(data__->PUTP4.X)) {
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
    __SET_VAR(data__->,INITIALLOAD1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,PUTP5.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,INITIALLOAD1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,PUTP6.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,INITIALLOAD1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,PUTP7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,INITIALLOAD1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,PUTP9.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,INITIALLOAD1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,PUTP10.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,INITIALLOAD1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,PUTP11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,INITIALLOAD1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,PUTP8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,INITIALLOAD1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,PUTP12.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,INITIALLOAD1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,PUTP4.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,PUTP5.X,,1);
    data__->PUTP5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,INITIALLOAD1.X,,1);
    data__->INITIALLOAD1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,PUTP6.X,,1);
    data__->PUTP6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,PUTP7.X,,1);
    data__->PUTP7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,PUTP9.X,,1);
    data__->PUTP9.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,PUTP10.X,,1);
    data__->PUTP10.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,PUTP11.X,,1);
    data__->PUTP11.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,PUTP8.X,,1);
    data__->PUTP8.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,PUTP12.X,,1);
    data__->PUTP12.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,PUTP4.X,,1);
    data__->PUTP4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // PUTP5 action associations
  {
    char active = __GET_VAR(data__->PUTP5.X);
    char activated = active && !data__->PUTP5.prev_state;
    char desactivated = !active && data__->PUTP5.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P2].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P2].state,,0);};

  }

  // STEP0 action associations
  {
    char active = __GET_VAR(data__->STEP0.X);
    char activated = active && !data__->STEP0.prev_state;
    char desactivated = !active && data__->STEP0.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_RESETWAREHOUSE].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_RESETWAREHOUSE].state,,0);};

  }

  // PUTP6 action associations
  {
    char active = __GET_VAR(data__->PUTP6.X);
    char activated = active && !data__->PUTP6.prev_state;
    char desactivated = !active && data__->PUTP6.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P3].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P3].state,,0);};

  }

  // PUTP7 action associations
  {
    char active = __GET_VAR(data__->PUTP7.X);
    char activated = active && !data__->PUTP7.prev_state;
    char desactivated = !active && data__->PUTP7.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P4].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P4].state,,0);};

  }

  // PUTP9 action associations
  {
    char active = __GET_VAR(data__->PUTP9.X);
    char activated = active && !data__->PUTP9.prev_state;
    char desactivated = !active && data__->PUTP9.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P6].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P6].state,,0);};

  }

  // PUTP10 action associations
  {
    char active = __GET_VAR(data__->PUTP10.X);
    char activated = active && !data__->PUTP10.prev_state;
    char desactivated = !active && data__->PUTP10.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P7].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P7].state,,0);};

  }

  // PUTP11 action associations
  {
    char active = __GET_VAR(data__->PUTP11.X);
    char activated = active && !data__->PUTP11.prev_state;
    char desactivated = !active && data__->PUTP11.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P8].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P8].state,,0);};

  }

  // PUTP8 action associations
  {
    char active = __GET_VAR(data__->PUTP8.X);
    char activated = active && !data__->PUTP8.prev_state;
    char desactivated = !active && data__->PUTP8.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P5].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P5].state,,0);};

  }

  // PUTP12 action associations
  {
    char active = __GET_VAR(data__->PUTP12.X);
    char activated = active && !data__->PUTP12.prev_state;
    char desactivated = !active && data__->PUTP12.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_P9].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_P9].state,,0);};

  }

  // PUTP4 action associations
  {
    char active = __GET_VAR(data__->PUTP4.X);
    char activated = active && !data__->PUTP4.prev_state;
    char desactivated = !active && data__->PUTP4.prev_state;

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
#undef INITIALLOAD1
#undef __SFC_INITIALLOAD1
#undef PUTP5
#undef __SFC_PUTP5
#undef STEP0
#undef __SFC_STEP0
#undef STEP1
#undef __SFC_STEP1
#undef PUTP6
#undef __SFC_PUTP6
#undef PUTP7
#undef __SFC_PUTP7
#undef PUTP9
#undef __SFC_PUTP9
#undef PUTP10
#undef __SFC_PUTP10
#undef PUTP11
#undef __SFC_PUTP11
#undef PUTP8
#undef __SFC_PUTP8
#undef PUTP12
#undef __SFC_PUTP12
#undef PUTP4
#undef __SFC_PUTP4

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





void GANTRY_init__(GANTRY *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->MOTORZUP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTORZUP0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTORZDOWN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTORYUP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTORYDOWN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTORXRIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTORXLEFT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GRAB,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GANTRYBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORZTOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORZBOTTOM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORY0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORY1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORY2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORY3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORY4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORX0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORX1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PIECESENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESETTIMERY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESETTIMERX,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON1,retain);
  TON_init__(&data__->TON2,retain);
  __INIT_VAR(data__->GRABTIMER,0,retain)
  __INIT_VAR(data__->YPOSITION,0,retain)
  __INIT_VAR(data__->XPOSITION,0,retain)
  __INIT_VAR(data__->PICKPIECE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELEASEPIECE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X0Y0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X0Y1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X0Y2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X0Y3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X0Y4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X1Y0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X1Y1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X1Y2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X1Y3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X1Y4,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON3,retain);
  TON_init__(&data__->TON4,retain);
  UINT i;
  data__->__nb_steps = 34;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 21;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 46;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define STEP0 __step_list[0]
#define __SFC_STEP0 0
#define STEP8 __step_list[1]
#define __SFC_STEP8 1
#define STEP2 __step_list[2]
#define __SFC_STEP2 2
#define STEP5 __step_list[3]
#define __SFC_STEP5 3
#define GANTRYIDLE __step_list[4]
#define __SFC_GANTRYIDLE 4
#define STEP6 __step_list[5]
#define __SFC_STEP6 5
#define STEP9 __step_list[6]
#define __SFC_STEP9 6
#define STEP12 __step_list[7]
#define __SFC_STEP12 7
#define STEP13 __step_list[8]
#define __SFC_STEP13 8
#define STEP14 __step_list[9]
#define __SFC_STEP14 9
#define STEP15 __step_list[10]
#define __SFC_STEP15 10
#define STEP16 __step_list[11]
#define __SFC_STEP16 11
#define STEP17 __step_list[12]
#define __SFC_STEP17 12
#define STEP11 __step_list[13]
#define __SFC_STEP11 13
#define STEP18 __step_list[14]
#define __SFC_STEP18 14
#define STEP19 __step_list[15]
#define __SFC_STEP19 15
#define STEP20 __step_list[16]
#define __SFC_STEP20 16
#define STEP21 __step_list[17]
#define __SFC_STEP21 17
#define STEP22 __step_list[18]
#define __SFC_STEP22 18
#define STEP23 __step_list[19]
#define __SFC_STEP23 19
#define STEP24 __step_list[20]
#define __SFC_STEP24 20
#define STEP25 __step_list[21]
#define __SFC_STEP25 21
#define STEP26 __step_list[22]
#define __SFC_STEP26 22
#define STEP1 __step_list[23]
#define __SFC_STEP1 23
#define STEP10 __step_list[24]
#define __SFC_STEP10 24
#define STEP27 __step_list[25]
#define __SFC_STEP27 25
#define STEP29 __step_list[26]
#define __SFC_STEP29 26
#define STEP28 __step_list[27]
#define __SFC_STEP28 27
#define STEP30 __step_list[28]
#define __SFC_STEP30 28
#define STEP31 __step_list[29]
#define __SFC_STEP31 29
#define STEP32 __step_list[30]
#define __SFC_STEP32 30
#define STEP7 __step_list[31]
#define __SFC_STEP7 31
#define STEP3 __step_list[32]
#define __SFC_STEP3 32
#define STEP4 __step_list[33]
#define __SFC_STEP4 33

// Actions definitions
#define __SFC_COMPUTE_FUNCTION_BLOCKS 0
#define __SFC_SETGANTRYBUSY 1
#define __SFC_RESETMOTORS 2
#define __SFC_GOTOY0 3
#define __SFC_GOTOX0 4
#define __SFC_GOTOY1 5
#define __SFC_GOTOX1 6
#define __SFC_GOTOY2 7
#define __SFC_GOTOY3 8
#define __SFC_GOTOY4 9
#define __SFC_MOTORZUP 10
#define __SFC_GANTRYBUSY 11
#define __SFC_MOTORYUP 12
#define __SFC_RESETTIMERY 13
#define __SFC_MOTORYDOWN 14
#define __SFC_MOTORZDOWN 15
#define __SFC_GRAB 16
#define __SFC_GRABTIMER 17
#define __SFC_MOTORXLEFT 18
#define __SFC_RESETTIMERX 19
#define __SFC_MOTORXRIGHT 20

// Code part
void GANTRY_body__(GANTRY *data__) {
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
    __SET_VAR(data__->,__transition_list[0],,__GET_VAR(data__->SENSORZTOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->SENSORZTOP,));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->STEP8.X)) {
    __SET_VAR(data__->,__transition_list[1],,__GET_VAR(data__->TON1.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->TON1.Q,));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->STEP2.X)) {
    __SET_VAR(data__->,__transition_list[2],,__GET_VAR(data__->SENSORY0,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->SENSORY0,));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->STEP5.X) && __GET_VAR(data__->STEP4.X)) {
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
  if (__GET_VAR(data__->GANTRYIDLE.X)) {
    __SET_VAR(data__->,__transition_list[4],,__GET_VAR(data__->X0Y0,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->X0Y0,));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->STEP6.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_VAR(data__->SENSORZTOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->SENSORZTOP,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->STEP9.X)) {
    __SET_VAR(data__->,__transition_list[6],,((__GET_VAR(data__->SENSORX0,) == 1) && (__GET_VAR(data__->SENSORY0,) == 1)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,((__GET_VAR(data__->SENSORX0,) == 1) && (__GET_VAR(data__->SENSORY0,) == 1)));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->GANTRYIDLE.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_VAR(data__->X1Y1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->X1Y1,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->STEP12.X)) {
    __SET_VAR(data__->,__transition_list[8],,__GET_VAR(data__->SENSORZTOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->SENSORZTOP,));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->STEP13.X)) {
    __SET_VAR(data__->,__transition_list[9],,((__GET_VAR(data__->SENSORX1,) == 1) && (__GET_VAR(data__->SENSORY1,) == 1)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,((__GET_VAR(data__->SENSORX1,) == 1) && (__GET_VAR(data__->SENSORY1,) == 1)));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->GANTRYIDLE.X)) {
    __SET_VAR(data__->,__transition_list[10],,__GET_VAR(data__->X1Y2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->X1Y2,));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->STEP14.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->SENSORZTOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->SENSORZTOP,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->STEP15.X)) {
    __SET_VAR(data__->,__transition_list[12],,((__GET_VAR(data__->SENSORX1,) == 1) && (__GET_VAR(data__->SENSORY2,) == 1)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,((__GET_VAR(data__->SENSORX1,) == 1) && (__GET_VAR(data__->SENSORY2,) == 1)));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->GANTRYIDLE.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_VAR(data__->X1Y3,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->X1Y3,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->STEP16.X)) {
    __SET_VAR(data__->,__transition_list[14],,__GET_VAR(data__->SENSORZTOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->SENSORZTOP,));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->STEP17.X)) {
    __SET_VAR(data__->,__transition_list[15],,((__GET_VAR(data__->SENSORX1,) == 1) && (__GET_VAR(data__->SENSORY3,) == 1)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,((__GET_VAR(data__->SENSORX1,) == 1) && (__GET_VAR(data__->SENSORY3,) == 1)));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->GANTRYIDLE.X)) {
    __SET_VAR(data__->,__transition_list[16],,__GET_VAR(data__->X1Y4,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->X1Y4,));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->STEP11.X)) {
    __SET_VAR(data__->,__transition_list[17],,__GET_VAR(data__->SENSORZTOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->SENSORZTOP,));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->STEP18.X)) {
    __SET_VAR(data__->,__transition_list[18],,((__GET_VAR(data__->SENSORX1,) == 1) && (__GET_VAR(data__->SENSORY4,) == 1)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,((__GET_VAR(data__->SENSORX1,) == 1) && (__GET_VAR(data__->SENSORY4,) == 1)));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->GANTRYIDLE.X)) {
    __SET_VAR(data__->,__transition_list[19],,__GET_VAR(data__->X0Y4,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->X0Y4,));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->STEP19.X)) {
    __SET_VAR(data__->,__transition_list[20],,__GET_VAR(data__->SENSORZTOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->SENSORZTOP,));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->STEP20.X)) {
    __SET_VAR(data__->,__transition_list[21],,((__GET_VAR(data__->SENSORX0,) == 1) && (__GET_VAR(data__->SENSORY4,) == 1)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,((__GET_VAR(data__->SENSORX0,) == 1) && (__GET_VAR(data__->SENSORY4,) == 1)));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->GANTRYIDLE.X)) {
    __SET_VAR(data__->,__transition_list[22],,__GET_VAR(data__->X0Y2,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->X0Y2,));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->STEP21.X)) {
    __SET_VAR(data__->,__transition_list[23],,__GET_VAR(data__->SENSORZTOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->SENSORZTOP,));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->STEP22.X)) {
    __SET_VAR(data__->,__transition_list[24],,((__GET_VAR(data__->SENSORX0,) == 1) && (__GET_VAR(data__->SENSORY2,) == 1)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,((__GET_VAR(data__->SENSORX0,) == 1) && (__GET_VAR(data__->SENSORY2,) == 1)));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->GANTRYIDLE.X)) {
    __SET_VAR(data__->,__transition_list[25],,__GET_VAR(data__->X0Y3,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->X0Y3,));
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->STEP23.X)) {
    __SET_VAR(data__->,__transition_list[26],,__GET_VAR(data__->SENSORZTOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->SENSORZTOP,));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->STEP24.X)) {
    __SET_VAR(data__->,__transition_list[27],,((__GET_VAR(data__->SENSORX0,) == 1) && (__GET_VAR(data__->SENSORY3,) == 1)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,((__GET_VAR(data__->SENSORX0,) == 1) && (__GET_VAR(data__->SENSORY3,) == 1)));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->GANTRYIDLE.X)) {
    __SET_VAR(data__->,__transition_list[28],,__GET_VAR(data__->X0Y1,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->X0Y1,));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->STEP25.X)) {
    __SET_VAR(data__->,__transition_list[29],,__GET_VAR(data__->SENSORZTOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->SENSORZTOP,));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->STEP26.X)) {
    __SET_VAR(data__->,__transition_list[30],,((__GET_VAR(data__->SENSORX0,) == 1) && (__GET_VAR(data__->SENSORY1,) == 1)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,((__GET_VAR(data__->SENSORX0,) == 1) && (__GET_VAR(data__->SENSORY1,) == 1)));
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->GANTRYIDLE.X)) {
    __SET_VAR(data__->,__transition_list[31],,__GET_VAR(data__->PICKPIECE,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->PICKPIECE,));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
    __SET_VAR(data__->,__transition_list[32],,__GET_VAR(data__->SENSORZBOTTOM,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->__transition_list[32]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->SENSORZBOTTOM,));
    }
    __SET_VAR(data__->,__transition_list[32],,0);
  }
  if (__GET_VAR(data__->STEP10.X)) {
    __SET_VAR(data__->,__transition_list[33],,__GET_VAR(data__->TON3.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->__transition_list[33]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->TON3.Q,));
    }
    __SET_VAR(data__->,__transition_list[33],,0);
  }
  if (__GET_VAR(data__->STEP27.X)) {
    __SET_VAR(data__->,__transition_list[34],,__GET_VAR(data__->SENSORZTOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_VAR(data__->__transition_list[34]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_VAR(data__->SENSORZTOP,));
    }
    __SET_VAR(data__->,__transition_list[34],,0);
  }
  if (__GET_VAR(data__->GANTRYIDLE.X)) {
    __SET_VAR(data__->,__transition_list[35],,__GET_VAR(data__->RELEASEPIECE,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->__transition_list[35]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->RELEASEPIECE,));
    }
    __SET_VAR(data__->,__transition_list[35],,0);
  }
  if (__GET_VAR(data__->STEP29.X)) {
    __SET_VAR(data__->,__transition_list[36],,__GET_VAR(data__->SENSORZBOTTOM,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->__transition_list[36]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->SENSORZBOTTOM,));
    }
    __SET_VAR(data__->,__transition_list[36],,0);
  }
  if (__GET_VAR(data__->STEP28.X)) {
    __SET_VAR(data__->,__transition_list[37],,__GET_VAR(data__->TON4.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_VAR(data__->__transition_list[37]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_VAR(data__->TON4.Q,));
    }
    __SET_VAR(data__->,__transition_list[37],,0);
  }
  if (__GET_VAR(data__->STEP30.X)) {
    __SET_VAR(data__->,__transition_list[38],,__GET_VAR(data__->SENSORZTOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_VAR(data__->__transition_list[38]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_VAR(data__->SENSORZTOP,));
    }
    __SET_VAR(data__->,__transition_list[38],,0);
  }
  if (__GET_VAR(data__->GANTRYIDLE.X)) {
    __SET_VAR(data__->,__transition_list[39],,__GET_VAR(data__->X1Y0,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,__GET_VAR(data__->__transition_list[39]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,__GET_VAR(data__->X1Y0,));
    }
    __SET_VAR(data__->,__transition_list[39],,0);
  }
  if (__GET_VAR(data__->STEP31.X)) {
    __SET_VAR(data__->,__transition_list[40],,__GET_VAR(data__->SENSORZTOP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_VAR(data__->__transition_list[40]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_VAR(data__->SENSORZTOP,));
    }
    __SET_VAR(data__->,__transition_list[40],,0);
  }
  if (__GET_VAR(data__->STEP32.X)) {
    __SET_VAR(data__->,__transition_list[41],,((__GET_VAR(data__->SENSORX1,) == 1) && (__GET_VAR(data__->SENSORY0,) == 1)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,__GET_VAR(data__->__transition_list[41]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,((__GET_VAR(data__->SENSORX1,) == 1) && (__GET_VAR(data__->SENSORY0,) == 1)));
    }
    __SET_VAR(data__->,__transition_list[41],,0);
  }
  if (__GET_VAR(data__->STEP8.X)) {
    __SET_VAR(data__->,__transition_list[42],,__GET_VAR(data__->SENSORY0,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,__GET_VAR(data__->__transition_list[42]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,__GET_VAR(data__->SENSORY0,));
    }
    __SET_VAR(data__->,__transition_list[42],,0);
  }
  if (__GET_VAR(data__->STEP7.X)) {
    __SET_VAR(data__->,__transition_list[43],,__GET_VAR(data__->TON2.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,__GET_VAR(data__->__transition_list[43]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,__GET_VAR(data__->TON2.Q,));
    }
    __SET_VAR(data__->,__transition_list[43],,0);
  }
  if (__GET_VAR(data__->STEP3.X)) {
    __SET_VAR(data__->,__transition_list[44],,__GET_VAR(data__->SENSORX0,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,__GET_VAR(data__->__transition_list[44]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,__GET_VAR(data__->SENSORX0,));
    }
    __SET_VAR(data__->,__transition_list[44],,0);
  }
  if (__GET_VAR(data__->STEP7.X)) {
    __SET_VAR(data__->,__transition_list[45],,__GET_VAR(data__->SENSORX0,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,__GET_VAR(data__->__transition_list[45]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,__GET_VAR(data__->SENSORX0,));
    }
    __SET_VAR(data__->,__transition_list[45],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP5.X,,0);
    __SET_VAR(data__->,STEP4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP6.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP9.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP12.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP13.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP14.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP15.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP16.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP17.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP18.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP19.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP20.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP21.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP22.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP23.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP24.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP25.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP26.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,STEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,STEP10.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,STEP27.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,STEP29.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,STEP28.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,STEP30.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,STEP31.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,STEP32.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,STEP8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,STEP7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,STEP3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,STEP7.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP8.X,,1);
    data__->STEP8.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP7.X,,1);
    data__->STEP7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP5.X,,1);
    data__->STEP5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,1);
    data__->GANTRYIDLE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP6.X,,1);
    data__->STEP6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP9.X,,1);
    data__->STEP9.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,1);
    data__->GANTRYIDLE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP12.X,,1);
    data__->STEP12.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP13.X,,1);
    data__->STEP13.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,1);
    data__->GANTRYIDLE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP14.X,,1);
    data__->STEP14.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP15.X,,1);
    data__->STEP15.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,1);
    data__->GANTRYIDLE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP16.X,,1);
    data__->STEP16.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP17.X,,1);
    data__->STEP17.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,1);
    data__->GANTRYIDLE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP11.X,,1);
    data__->STEP11.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP18.X,,1);
    data__->STEP18.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,1);
    data__->GANTRYIDLE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP19.X,,1);
    data__->STEP19.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP20.X,,1);
    data__->STEP20.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,1);
    data__->GANTRYIDLE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP21.X,,1);
    data__->STEP21.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP22.X,,1);
    data__->STEP22.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,1);
    data__->GANTRYIDLE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP23.X,,1);
    data__->STEP23.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP24.X,,1);
    data__->STEP24.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,1);
    data__->GANTRYIDLE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP25.X,,1);
    data__->STEP25.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP26.X,,1);
    data__->STEP26.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,1);
    data__->GANTRYIDLE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,STEP10.X,,1);
    data__->STEP10.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,STEP27.X,,1);
    data__->STEP27.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,1);
    data__->GANTRYIDLE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,STEP29.X,,1);
    data__->STEP29.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,STEP28.X,,1);
    data__->STEP28.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,STEP30.X,,1);
    data__->STEP30.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,1);
    data__->GANTRYIDLE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,STEP31.X,,1);
    data__->STEP31.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,STEP32.X,,1);
    data__->STEP32.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,GANTRYIDLE.X,,1);
    data__->GANTRYIDLE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,STEP5.X,,1);
    data__->STEP5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,STEP3.X,,1);
    data__->STEP3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,STEP4.X,,1);
    data__->STEP4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,STEP4.X,,1);
    data__->STEP4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // STEP0 action associations
  {
    char active = __GET_VAR(data__->STEP0.X);
    char activated = active && !data__->STEP0.prev_state;
    char desactivated = !active && data__->STEP0.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORZUP,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORZUP,,0);};

    if (active)       {data__->__action_list[__SFC_GANTRYBUSY].set = 1;}

    if (active)       {data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].set = 1;}

  }

  // STEP8 action associations
  {
    char active = __GET_VAR(data__->STEP8.X);
    char activated = active && !data__->STEP8.prev_state;
    char desactivated = !active && data__->STEP8.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORYUP,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORYUP,,0);};

    if (active)       {__SET_VAR(data__->,RESETTIMERY,,1);};
    if (desactivated) {__SET_VAR(data__->,RESETTIMERY,,0);};

  }

  // STEP2 action associations
  {
    char active = __GET_VAR(data__->STEP2.X);
    char activated = active && !data__->STEP2.prev_state;
    char desactivated = !active && data__->STEP2.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORYDOWN,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORYDOWN,,0);};

  }

  // GANTRYIDLE action associations
  {
    char active = __GET_VAR(data__->GANTRYIDLE.X);
    char activated = active && !data__->GANTRYIDLE.prev_state;
    char desactivated = !active && data__->GANTRYIDLE.prev_state;

    if (active)       {data__->__action_list[__SFC_GANTRYBUSY].reset = 1;}

    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SETGANTRYBUSY].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_SETGANTRYBUSY].state,,0);};

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_RESETMOTORS].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_RESETMOTORS].state,,0);};

  }

  // STEP6 action associations
  {
    char active = __GET_VAR(data__->STEP6.X);
    char activated = active && !data__->STEP6.prev_state;
    char desactivated = !active && data__->STEP6.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORZUP,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORZUP,,0);};

  }

  // STEP9 action associations
  {
    char active = __GET_VAR(data__->STEP9.X);
    char activated = active && !data__->STEP9.prev_state;
    char desactivated = !active && data__->STEP9.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOY0].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOY0].state,,0);};

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOX0].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOX0].state,,0);};

  }

  // STEP12 action associations
  {
    char active = __GET_VAR(data__->STEP12.X);
    char activated = active && !data__->STEP12.prev_state;
    char desactivated = !active && data__->STEP12.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORZUP,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORZUP,,0);};

  }

  // STEP13 action associations
  {
    char active = __GET_VAR(data__->STEP13.X);
    char activated = active && !data__->STEP13.prev_state;
    char desactivated = !active && data__->STEP13.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOY1].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOY1].state,,0);};

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOX1].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOX1].state,,0);};

  }

  // STEP14 action associations
  {
    char active = __GET_VAR(data__->STEP14.X);
    char activated = active && !data__->STEP14.prev_state;
    char desactivated = !active && data__->STEP14.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORZUP,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORZUP,,0);};

  }

  // STEP15 action associations
  {
    char active = __GET_VAR(data__->STEP15.X);
    char activated = active && !data__->STEP15.prev_state;
    char desactivated = !active && data__->STEP15.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOY2].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOY2].state,,0);};

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOX1].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOX1].state,,0);};

  }

  // STEP16 action associations
  {
    char active = __GET_VAR(data__->STEP16.X);
    char activated = active && !data__->STEP16.prev_state;
    char desactivated = !active && data__->STEP16.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORZUP,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORZUP,,0);};

  }

  // STEP17 action associations
  {
    char active = __GET_VAR(data__->STEP17.X);
    char activated = active && !data__->STEP17.prev_state;
    char desactivated = !active && data__->STEP17.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOY3].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOY3].state,,0);};

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOX1].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOX1].state,,0);};

  }

  // STEP11 action associations
  {
    char active = __GET_VAR(data__->STEP11.X);
    char activated = active && !data__->STEP11.prev_state;
    char desactivated = !active && data__->STEP11.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORZUP,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORZUP,,0);};

  }

  // STEP18 action associations
  {
    char active = __GET_VAR(data__->STEP18.X);
    char activated = active && !data__->STEP18.prev_state;
    char desactivated = !active && data__->STEP18.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOY4].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOY4].state,,0);};

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOX1].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOX1].state,,0);};

  }

  // STEP19 action associations
  {
    char active = __GET_VAR(data__->STEP19.X);
    char activated = active && !data__->STEP19.prev_state;
    char desactivated = !active && data__->STEP19.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORZUP,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORZUP,,0);};

  }

  // STEP20 action associations
  {
    char active = __GET_VAR(data__->STEP20.X);
    char activated = active && !data__->STEP20.prev_state;
    char desactivated = !active && data__->STEP20.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOY4].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOY4].state,,0);};

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOX0].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOX0].state,,0);};

  }

  // STEP21 action associations
  {
    char active = __GET_VAR(data__->STEP21.X);
    char activated = active && !data__->STEP21.prev_state;
    char desactivated = !active && data__->STEP21.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORZUP,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORZUP,,0);};

  }

  // STEP22 action associations
  {
    char active = __GET_VAR(data__->STEP22.X);
    char activated = active && !data__->STEP22.prev_state;
    char desactivated = !active && data__->STEP22.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOY2].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOY2].state,,0);};

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOX0].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOX0].state,,0);};

  }

  // STEP23 action associations
  {
    char active = __GET_VAR(data__->STEP23.X);
    char activated = active && !data__->STEP23.prev_state;
    char desactivated = !active && data__->STEP23.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORZUP,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORZUP,,0);};

  }

  // STEP24 action associations
  {
    char active = __GET_VAR(data__->STEP24.X);
    char activated = active && !data__->STEP24.prev_state;
    char desactivated = !active && data__->STEP24.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOY3].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOY3].state,,0);};

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOX0].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOX0].state,,0);};

  }

  // STEP25 action associations
  {
    char active = __GET_VAR(data__->STEP25.X);
    char activated = active && !data__->STEP25.prev_state;
    char desactivated = !active && data__->STEP25.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORZUP,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORZUP,,0);};

  }

  // STEP26 action associations
  {
    char active = __GET_VAR(data__->STEP26.X);
    char activated = active && !data__->STEP26.prev_state;
    char desactivated = !active && data__->STEP26.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOY1].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOY1].state,,0);};

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOX0].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOX0].state,,0);};

  }

  // STEP1 action associations
  {
    char active = __GET_VAR(data__->STEP1.X);
    char activated = active && !data__->STEP1.prev_state;
    char desactivated = !active && data__->STEP1.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORZDOWN,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORZDOWN,,0);};

  }

  // STEP10 action associations
  {
    char active = __GET_VAR(data__->STEP10.X);
    char activated = active && !data__->STEP10.prev_state;
    char desactivated = !active && data__->STEP10.prev_state;

    if (active)       {data__->__action_list[__SFC_GRAB].set = 1;}

    if (active)       {__SET_VAR(data__->,GRABTIMER,,1);};
    if (desactivated) {__SET_VAR(data__->,GRABTIMER,,0);};

  }

  // STEP27 action associations
  {
    char active = __GET_VAR(data__->STEP27.X);
    char activated = active && !data__->STEP27.prev_state;
    char desactivated = !active && data__->STEP27.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORZUP,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORZUP,,0);};

  }

  // STEP29 action associations
  {
    char active = __GET_VAR(data__->STEP29.X);
    char activated = active && !data__->STEP29.prev_state;
    char desactivated = !active && data__->STEP29.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORZDOWN,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORZDOWN,,0);};

  }

  // STEP28 action associations
  {
    char active = __GET_VAR(data__->STEP28.X);
    char activated = active && !data__->STEP28.prev_state;
    char desactivated = !active && data__->STEP28.prev_state;

    if (active)       {data__->__action_list[__SFC_GRAB].reset = 1;}

    if (active)       {__SET_VAR(data__->,GRABTIMER,,1);};
    if (desactivated) {__SET_VAR(data__->,GRABTIMER,,0);};

  }

  // STEP30 action associations
  {
    char active = __GET_VAR(data__->STEP30.X);
    char activated = active && !data__->STEP30.prev_state;
    char desactivated = !active && data__->STEP30.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORZUP,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORZUP,,0);};

  }

  // STEP31 action associations
  {
    char active = __GET_VAR(data__->STEP31.X);
    char activated = active && !data__->STEP31.prev_state;
    char desactivated = !active && data__->STEP31.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORZUP,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORZUP,,0);};

  }

  // STEP32 action associations
  {
    char active = __GET_VAR(data__->STEP32.X);
    char activated = active && !data__->STEP32.prev_state;
    char desactivated = !active && data__->STEP32.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOY0].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOY0].state,,0);};

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_GOTOX1].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_GOTOX1].state,,0);};

  }

  // STEP7 action associations
  {
    char active = __GET_VAR(data__->STEP7.X);
    char activated = active && !data__->STEP7.prev_state;
    char desactivated = !active && data__->STEP7.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORXLEFT,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORXLEFT,,0);};

    if (active)       {__SET_VAR(data__->,RESETTIMERX,,1);};
    if (desactivated) {__SET_VAR(data__->,RESETTIMERX,,0);};

  }

  // STEP3 action associations
  {
    char active = __GET_VAR(data__->STEP3.X);
    char activated = active && !data__->STEP3.prev_state;
    char desactivated = !active && data__->STEP3.prev_state;

    if (active)       {__SET_VAR(data__->,MOTORXRIGHT,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORXRIGHT,,0);};

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
  if (data__->__action_list[__SFC_MOTORZUP].reset) {
    __SET_VAR(data__->,MOTORZUP,,0);
  }
  else if (data__->__action_list[__SFC_MOTORZUP].set) {
    __SET_VAR(data__->,MOTORZUP,,1);
  }
  if (data__->__action_list[__SFC_GANTRYBUSY].reset) {
    __SET_VAR(data__->,GANTRYBUSY,,0);
  }
  else if (data__->__action_list[__SFC_GANTRYBUSY].set) {
    __SET_VAR(data__->,GANTRYBUSY,,1);
  }
  if (data__->__action_list[__SFC_MOTORYUP].reset) {
    __SET_VAR(data__->,MOTORYUP,,0);
  }
  else if (data__->__action_list[__SFC_MOTORYUP].set) {
    __SET_VAR(data__->,MOTORYUP,,1);
  }
  if (data__->__action_list[__SFC_RESETTIMERY].reset) {
    __SET_VAR(data__->,RESETTIMERY,,0);
  }
  else if (data__->__action_list[__SFC_RESETTIMERY].set) {
    __SET_VAR(data__->,RESETTIMERY,,1);
  }
  if (data__->__action_list[__SFC_MOTORYDOWN].reset) {
    __SET_VAR(data__->,MOTORYDOWN,,0);
  }
  else if (data__->__action_list[__SFC_MOTORYDOWN].set) {
    __SET_VAR(data__->,MOTORYDOWN,,1);
  }
  if (data__->__action_list[__SFC_MOTORZDOWN].reset) {
    __SET_VAR(data__->,MOTORZDOWN,,0);
  }
  else if (data__->__action_list[__SFC_MOTORZDOWN].set) {
    __SET_VAR(data__->,MOTORZDOWN,,1);
  }
  if (data__->__action_list[__SFC_GRAB].reset) {
    __SET_VAR(data__->,GRAB,,0);
  }
  else if (data__->__action_list[__SFC_GRAB].set) {
    __SET_VAR(data__->,GRAB,,1);
  }
  if (data__->__action_list[__SFC_GRABTIMER].reset) {
    __SET_VAR(data__->,GRABTIMER,,0);
  }
  else if (data__->__action_list[__SFC_GRABTIMER].set) {
    __SET_VAR(data__->,GRABTIMER,,1);
  }
  if (data__->__action_list[__SFC_MOTORXLEFT].reset) {
    __SET_VAR(data__->,MOTORXLEFT,,0);
  }
  else if (data__->__action_list[__SFC_MOTORXLEFT].set) {
    __SET_VAR(data__->,MOTORXLEFT,,1);
  }
  if (data__->__action_list[__SFC_RESETTIMERX].reset) {
    __SET_VAR(data__->,RESETTIMERX,,0);
  }
  else if (data__->__action_list[__SFC_RESETTIMERX].set) {
    __SET_VAR(data__->,RESETTIMERX,,1);
  }
  if (data__->__action_list[__SFC_MOTORXRIGHT].reset) {
    __SET_VAR(data__->,MOTORXRIGHT,,0);
  }
  else if (data__->__action_list[__SFC_MOTORXRIGHT].set) {
    __SET_VAR(data__->,MOTORXRIGHT,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_COMPUTE_FUNCTION_BLOCKS].state)) {
    __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->RESETTIMERY,));
    __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 13, 0, 0, 0));
    TON_body__(&data__->TON1);
    __SET_VAR(data__->TON2.,IN,,__GET_VAR(data__->RESETTIMERX,));
    __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
    TON_body__(&data__->TON2);
    __SET_VAR(data__->TON3.,IN,,__GET_VAR(data__->GRABTIMER,));
    __SET_VAR(data__->TON3.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
    TON_body__(&data__->TON3);
    __SET_VAR(data__->TON4.,IN,,__GET_VAR(data__->GRABTIMER,));
    __SET_VAR(data__->TON4.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
    TON_body__(&data__->TON4);
  }

  if(__GET_VAR(data__->__action_list[__SFC_SETGANTRYBUSY].state)) {
    __SET_VAR(data__->,GANTRYBUSY,,1);
  }

  if(__GET_VAR(data__->__action_list[__SFC_RESETMOTORS].state)) {
    __SET_VAR(data__->,MOTORZUP,,0);
    __SET_VAR(data__->,MOTORZDOWN,,0);
    __SET_VAR(data__->,MOTORYUP,,0);
    __SET_VAR(data__->,MOTORYDOWN,,0);
    __SET_VAR(data__->,MOTORXRIGHT,,0);
    __SET_VAR(data__->,MOTORXLEFT,,0);
  }

  if(__GET_VAR(data__->__action_list[__SFC_GOTOY0].state)) {
    if (((((__GET_VAR(data__->SENSORY1,) == 1) || (__GET_VAR(data__->SENSORY2,) == 1)) || (__GET_VAR(data__->SENSORY3,) == 1)) || (__GET_VAR(data__->SENSORY4,) == 1))) {
      __SET_VAR(data__->,MOTORYUP,,1);
    } else if ((__GET_VAR(data__->SENSORY0,) == 1)) {
      __SET_VAR(data__->,MOTORYUP,,0);
    };
  }

  if(__GET_VAR(data__->__action_list[__SFC_GOTOX0].state)) {
    if ((__GET_VAR(data__->SENSORX0,) == 0)) {
      __SET_VAR(data__->,MOTORXLEFT,,1);
    } else if ((__GET_VAR(data__->SENSORX0,) == 1)) {
      __SET_VAR(data__->,MOTORXLEFT,,0);
    };
  }

  if(__GET_VAR(data__->__action_list[__SFC_GOTOY1].state)) {
    if ((((__GET_VAR(data__->SENSORY2,) == 1) || (__GET_VAR(data__->SENSORY3,) == 1)) || (__GET_VAR(data__->SENSORY4,) == 1))) {
      __SET_VAR(data__->,MOTORYUP,,1);
    } else if ((__GET_VAR(data__->SENSORY0,) == 1)) {
      __SET_VAR(data__->,MOTORYDOWN,,1);
    } else if ((__GET_VAR(data__->SENSORY1,) == 1)) {
      __SET_VAR(data__->,MOTORYUP,,0);
      __SET_VAR(data__->,MOTORYDOWN,,0);
    };
  }

  if(__GET_VAR(data__->__action_list[__SFC_GOTOX1].state)) {
    if ((__GET_VAR(data__->SENSORX1,) == 0)) {
      __SET_VAR(data__->,MOTORXRIGHT,,1);
    } else if ((__GET_VAR(data__->SENSORX1,) == 1)) {
      __SET_VAR(data__->,MOTORXRIGHT,,0);
    };
  }

  if(__GET_VAR(data__->__action_list[__SFC_GOTOY2].state)) {
    if (((__GET_VAR(data__->SENSORY3,) == 1) || (__GET_VAR(data__->SENSORY4,) == 1))) {
      __SET_VAR(data__->,MOTORYUP,,1);
    } else if (((__GET_VAR(data__->SENSORY0,) == 1) || (__GET_VAR(data__->SENSORY1,) == 1))) {
      __SET_VAR(data__->,MOTORYDOWN,,1);
    } else if ((__GET_VAR(data__->SENSORY2,) == 1)) {
      __SET_VAR(data__->,MOTORYUP,,0);
      __SET_VAR(data__->,MOTORYDOWN,,0);
    };
  }

  if(__GET_VAR(data__->__action_list[__SFC_GOTOY3].state)) {
    if ((__GET_VAR(data__->SENSORY4,) == 1)) {
      __SET_VAR(data__->,MOTORYUP,,1);
    } else if ((((__GET_VAR(data__->SENSORY0,) == 1) || (__GET_VAR(data__->SENSORY1,) == 1)) || (__GET_VAR(data__->SENSORY2,) == 1))) {
      __SET_VAR(data__->,MOTORYDOWN,,1);
    } else if ((__GET_VAR(data__->SENSORY3,) == 1)) {
      __SET_VAR(data__->,MOTORYUP,,0);
      __SET_VAR(data__->,MOTORYDOWN,,0);
    };
  }

  if(__GET_VAR(data__->__action_list[__SFC_GOTOY4].state)) {
    if (((((__GET_VAR(data__->SENSORY0,) == 1) || (__GET_VAR(data__->SENSORY1,) == 1)) || (__GET_VAR(data__->SENSORY2,) == 1)) || (__GET_VAR(data__->SENSORY3,) == 1))) {
      __SET_VAR(data__->,MOTORYDOWN,,1);
    } else if ((__GET_VAR(data__->SENSORY4,) == 1)) {
      __SET_VAR(data__->,MOTORYUP,,0);
      __SET_VAR(data__->,MOTORYDOWN,,0);
    };
  }



  goto __end;

__end:
  return;
} // GANTRY_body__() 

// Steps undefinitions
#undef STEP0
#undef __SFC_STEP0
#undef STEP8
#undef __SFC_STEP8
#undef STEP2
#undef __SFC_STEP2
#undef STEP5
#undef __SFC_STEP5
#undef GANTRYIDLE
#undef __SFC_GANTRYIDLE
#undef STEP6
#undef __SFC_STEP6
#undef STEP9
#undef __SFC_STEP9
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
#undef STEP11
#undef __SFC_STEP11
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
#undef STEP26
#undef __SFC_STEP26
#undef STEP1
#undef __SFC_STEP1
#undef STEP10
#undef __SFC_STEP10
#undef STEP27
#undef __SFC_STEP27
#undef STEP29
#undef __SFC_STEP29
#undef STEP28
#undef __SFC_STEP28
#undef STEP30
#undef __SFC_STEP30
#undef STEP31
#undef __SFC_STEP31
#undef STEP32
#undef __SFC_STEP32
#undef STEP7
#undef __SFC_STEP7
#undef STEP3
#undef __SFC_STEP3
#undef STEP4
#undef __SFC_STEP4

// Actions undefinitions
#undef __SFC_COMPUTE_FUNCTION_BLOCKS
#undef __SFC_SETGANTRYBUSY
#undef __SFC_RESETMOTORS
#undef __SFC_GOTOY0
#undef __SFC_GOTOX0
#undef __SFC_GOTOY1
#undef __SFC_GOTOX1
#undef __SFC_GOTOY2
#undef __SFC_GOTOY3
#undef __SFC_GOTOY4
#undef __SFC_MOTORZUP
#undef __SFC_GANTRYBUSY
#undef __SFC_MOTORYUP
#undef __SFC_RESETTIMERY
#undef __SFC_MOTORYDOWN
#undef __SFC_MOTORZDOWN
#undef __SFC_GRAB
#undef __SFC_GRABTIMER
#undef __SFC_MOTORXLEFT
#undef __SFC_RESETTIMERX
#undef __SFC_MOTORXRIGHT





void LINEARCONVEYOR_init__(LINEARCONVEYOR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RECEIVEPIECE,__BOOL_LITERAL(FALSE),retain)
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
  UINT i;
  data__->__nb_steps = 12;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 4;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 14;
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
#define STEP0 __step_list[4]
#define __SFC_STEP0 4
#define TURNOFFFRONT __step_list[5]
#define __SFC_TURNOFFFRONT 5
#define MOVEBACK __step_list[6]
#define __SFC_MOVEBACK 6
#define NOTBUSYBACK __step_list[7]
#define __SFC_NOTBUSYBACK 7
#define MOVEBACKSTEP __step_list[8]
#define __SFC_MOVEBACKSTEP 8
#define STEP1 __step_list[9]
#define __SFC_STEP1 9
#define TURNOFFBACK __step_list[10]
#define __SFC_TURNOFFBACK 10
#define MOVEFRONT0 __step_list[11]
#define __SFC_MOVEFRONT0 11

// Actions definitions
#define __SFC_ISBUSY 0
#define __SFC_FORWARDMOTOR 1
#define __SFC_FORWARDTIMERON 2
#define __SFC_BACKMOTOR 3

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
    __SET_VAR(data__->,__transition_list[3],,!(__GET_VAR(data__->REACHEDSENSOR,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,!(__GET_VAR(data__->REACHEDSENSOR,)));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->STEP0.X)) {
    __SET_VAR(data__->,__transition_list[4],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->TURNOFFFRONT.X)) {
    __SET_VAR(data__->,__transition_list[5],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__BOOL_LITERAL(TRUE));
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
    __SET_VAR(data__->,__transition_list[9],,!(__GET_VAR(data__->REACHEDSENSOR,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,!(__GET_VAR(data__->REACHEDSENSOR,)));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
    __SET_VAR(data__->,__transition_list[10],,__GET_VAR(data__->REACHEDSENSORBACK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->REACHEDSENSORBACK,));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->TURNOFFBACK.X)) {
    __SET_VAR(data__->,__transition_list[11],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[12],,__GET_VAR(data__->RECEIVEPIECE,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->RECEIVEPIECE,));
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
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,TURNOFFFRONT.X,,0);
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
    __SET_VAR(data__->,STEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,MOVEFRONT0.X,,0);
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
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,TURNOFFFRONT.X,,1);
    data__->TURNOFFFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
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
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,1);
    data__->TURNOFFBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,MOVEFRONT0.X,,1);
    data__->MOVEFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
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
#undef STEP0
#undef __SFC_STEP0
#undef TURNOFFFRONT
#undef __SFC_TURNOFFFRONT
#undef MOVEBACK
#undef __SFC_MOVEBACK
#undef NOTBUSYBACK
#undef __SFC_NOTBUSYBACK
#undef MOVEBACKSTEP
#undef __SFC_MOVEBACKSTEP
#undef STEP1
#undef __SFC_STEP1
#undef TURNOFFBACK
#undef __SFC_TURNOFFBACK
#undef MOVEFRONT0
#undef __SFC_MOVEFRONT0

// Actions undefinitions
#undef __SFC_ISBUSY
#undef __SFC_FORWARDMOTOR
#undef __SFC_FORWARDTIMERON
#undef __SFC_BACKMOTOR





void ROTARYCONVEYOR_init__(ROTARYCONVEYOR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SENDUPRIGHTSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENDRIGHTDOWNSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENDRIGHTUPSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RECEIVEPIECE,__BOOL_LITERAL(FALSE),retain)
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
  UINT i;
  data__->__nb_steps = 43;
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
  data__->__nb_transitions = 50;
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
#define STEP1 __step_list[4]
#define __SFC_STEP1 4
#define TURNOFFFRONT __step_list[5]
#define __SFC_TURNOFFFRONT 5
#define MOVEBACK __step_list[6]
#define __SFC_MOVEBACK 6
#define NOTBUSYBACK __step_list[7]
#define __SFC_NOTBUSYBACK 7
#define MOVEBACKSTEP __step_list[8]
#define __SFC_MOVEBACKSTEP 8
#define STEP2 __step_list[9]
#define __SFC_STEP2 9
#define TURNOFFBACK __step_list[10]
#define __SFC_TURNOFFBACK 10
#define ROTATERIGHT2 __step_list[11]
#define __SFC_ROTATERIGHT2 11
#define RIGHTROTATEED2 __step_list[12]
#define __SFC_RIGHTROTATEED2 12
#define NOTBUSYFRONT2 __step_list[13]
#define __SFC_NOTBUSYFRONT2 13
#define ROTATINGLEFT2 __step_list[14]
#define __SFC_ROTATINGLEFT2 14
#define ROTATINGLEFT3 __step_list[15]
#define __SFC_ROTATINGLEFT3 15
#define NOTBUSYBACK2 __step_list[16]
#define __SFC_NOTBUSYBACK2 16
#define ROTATERIGHT1 __step_list[17]
#define __SFC_ROTATERIGHT1 17
#define RIGHTROTATEED1 __step_list[18]
#define __SFC_RIGHTROTATEED1 18
#define NOTBUSYFRONT1 __step_list[19]
#define __SFC_NOTBUSYFRONT1 19
#define ROTATINGLEFT1 __step_list[20]
#define __SFC_ROTATINGLEFT1 20
#define ROTATINGLEFT4 __step_list[21]
#define __SFC_ROTATINGLEFT4 21
#define NOTBUSYBACK3 __step_list[22]
#define __SFC_NOTBUSYBACK3 22
#define ROTATERIGHT0 __step_list[23]
#define __SFC_ROTATERIGHT0 23
#define RIGHTROTATEED0 __step_list[24]
#define __SFC_RIGHTROTATEED0 24
#define ROTATINGLEFT0 __step_list[25]
#define __SFC_ROTATINGLEFT0 25
#define NOTBUSYBACK1 __step_list[26]
#define __SFC_NOTBUSYBACK1 26
#define MOVEBACKSTEP1 __step_list[27]
#define __SFC_MOVEBACKSTEP1 27
#define TURNOFFBACK1 __step_list[28]
#define __SFC_TURNOFFBACK1 28
#define ROTATERIGHT __step_list[29]
#define __SFC_ROTATERIGHT 29
#define RIGHTROTATEED __step_list[30]
#define __SFC_RIGHTROTATEED 30
#define ROTATINGLEFT __step_list[31]
#define __SFC_ROTATINGLEFT 31
#define NOTBUSYBACK0 __step_list[32]
#define __SFC_NOTBUSYBACK0 32
#define MOVEBACKSTEP0 __step_list[33]
#define __SFC_MOVEBACKSTEP0 33
#define TURNOFFBACK0 __step_list[34]
#define __SFC_TURNOFFBACK0 34
#define MOVEFRONT0 __step_list[35]
#define __SFC_MOVEFRONT0 35
#define ROTATINGRIGHT __step_list[36]
#define __SFC_ROTATINGRIGHT 36
#define NOTBUSYFRONT0 __step_list[37]
#define __SFC_NOTBUSYFRONT0 37
#define MOVEFRONTSTEP0 __step_list[38]
#define __SFC_MOVEFRONTSTEP0 38
#define TURNOFFFRONT0 __step_list[39]
#define __SFC_TURNOFFFRONT0 39
#define RESETROTATE __step_list[40]
#define __SFC_RESETROTATE 40
#define RESETDONER __step_list[41]
#define __SFC_RESETDONER 41
#define MOVEFRONT1 __step_list[42]
#define __SFC_MOVEFRONT1 42

// Actions definitions
#define __SFC_RESETPOSITION 0
#define __SFC_ISBUSY 1
#define __SFC_FORWARDMOTOR 2
#define __SFC_BACKMOTOR 3
#define __SFC_RIGHTROTMOTOR 4
#define __SFC_LEFTROTMOTOR 5
#define __SFC_READYTORECEIVE 6

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
    __SET_VAR(data__->,__transition_list[3],,!(__GET_VAR(data__->REACHEDSENSOR,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,!(__GET_VAR(data__->REACHEDSENSOR,)));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
    __SET_VAR(data__->,__transition_list[4],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->TURNOFFFRONT.X)) {
    __SET_VAR(data__->,__transition_list[5],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__BOOL_LITERAL(TRUE));
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
    __SET_VAR(data__->,__transition_list[9],,!(__GET_VAR(data__->REACHEDSENSOR,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,!(__GET_VAR(data__->REACHEDSENSOR,)));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->STEP2.X)) {
    __SET_VAR(data__->,__transition_list[10],,__GET_VAR(data__->REACHEDSENSORBACK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->REACHEDSENSORBACK,));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->TURNOFFBACK.X)) {
    __SET_VAR(data__->,__transition_list[11],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[12],,__GET_VAR(data__->SENDRIGHTDOWNSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->SENDRIGHTDOWNSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->ROTATERIGHT2.X)) {
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
  if (__GET_VAR(data__->RIGHTROTATEED2.X)) {
    __SET_VAR(data__->,__transition_list[14],,__GET_VAR(data__->SENSORROTRIGHT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->SENSORROTRIGHT,));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->NOTBUSYFRONT2.X)) {
    __SET_VAR(data__->,__transition_list[15],,!(__GET_VAR(data__->DOWNNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,!(__GET_VAR(data__->DOWNNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->ROTATINGLEFT2.X)) {
    __SET_VAR(data__->,__transition_list[16],,__GET_VAR(data__->REACHEDSENSORDOWN,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->REACHEDSENSORDOWN,));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->ROTATINGLEFT3.X)) {
    __SET_VAR(data__->,__transition_list[17],,__GET_VAR(data__->SENSORROTLEFT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->SENSORROTLEFT,));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->NOTBUSYBACK2.X)) {
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
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[19],,__GET_VAR(data__->SENDRIGHTUPSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->SENDRIGHTUPSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->ROTATERIGHT1.X)) {
    __SET_VAR(data__->,__transition_list[20],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->RIGHTROTATEED1.X)) {
    __SET_VAR(data__->,__transition_list[21],,__GET_VAR(data__->SENSORROTRIGHT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->SENSORROTRIGHT,));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->NOTBUSYFRONT1.X)) {
    __SET_VAR(data__->,__transition_list[22],,!(__GET_VAR(data__->UPNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,!(__GET_VAR(data__->UPNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->ROTATINGLEFT1.X)) {
    __SET_VAR(data__->,__transition_list[23],,__GET_VAR(data__->REACHEDSENSORUP,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->REACHEDSENSORUP,));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->ROTATINGLEFT4.X)) {
    __SET_VAR(data__->,__transition_list[24],,__GET_VAR(data__->SENSORROTLEFT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->SENSORROTLEFT,));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->NOTBUSYBACK3.X)) {
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
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[26],,__GET_VAR(data__->SENDUPRIGHTSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->SENDUPRIGHTSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->ROTATERIGHT0.X)) {
    __SET_VAR(data__->,__transition_list[27],,__GET_VAR(data__->SENSORROTRIGHT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->SENSORROTRIGHT,));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->RIGHTROTATEED0.X)) {
    __SET_VAR(data__->,__transition_list[28],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->ROTATINGLEFT0.X)) {
    __SET_VAR(data__->,__transition_list[29],,__GET_VAR(data__->SENSORROTLEFT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->SENSORROTLEFT,));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->NOTBUSYBACK1.X)) {
    __SET_VAR(data__->,__transition_list[30],,!(__GET_VAR(data__->FRONTNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,!(__GET_VAR(data__->FRONTNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP1.X)) {
    __SET_VAR(data__->,__transition_list[31],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }
  if (__GET_VAR(data__->TURNOFFBACK1.X)) {
    __SET_VAR(data__->,__transition_list[32],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->__transition_list[32]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[32],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[33],,__GET_VAR(data__->SENDLEFTDOWNSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->__transition_list[33]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->SENDLEFTDOWNSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[33],,0);
  }
  if (__GET_VAR(data__->ROTATERIGHT.X)) {
    __SET_VAR(data__->,__transition_list[34],,__GET_VAR(data__->SENSORROTRIGHT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_VAR(data__->__transition_list[34]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_VAR(data__->SENSORROTRIGHT,));
    }
    __SET_VAR(data__->,__transition_list[34],,0);
  }
  if (__GET_VAR(data__->RIGHTROTATEED.X)) {
    __SET_VAR(data__->,__transition_list[35],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->__transition_list[35]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[35],,0);
  }
  if (__GET_VAR(data__->ROTATINGLEFT.X)) {
    __SET_VAR(data__->,__transition_list[36],,__GET_VAR(data__->SENSORROTLEFT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->__transition_list[36]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->SENSORROTLEFT,));
    }
    __SET_VAR(data__->,__transition_list[36],,0);
  }
  if (__GET_VAR(data__->NOTBUSYBACK0.X)) {
    __SET_VAR(data__->,__transition_list[37],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_VAR(data__->__transition_list[37]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[37],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[38],,__GET_VAR(data__->REACHEDSENSORBACK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_VAR(data__->__transition_list[38]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_VAR(data__->REACHEDSENSORBACK,));
    }
    __SET_VAR(data__->,__transition_list[38],,0);
  }
  if (__GET_VAR(data__->TURNOFFBACK0.X)) {
    __SET_VAR(data__->,__transition_list[39],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,__GET_VAR(data__->__transition_list[39]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[39],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[40],,__GET_VAR(data__->SENDDOWNSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_VAR(data__->__transition_list[40]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_VAR(data__->SENDDOWNSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[40],,0);
  }
  if (__GET_VAR(data__->MOVEFRONT0.X)) {
    __SET_VAR(data__->,__transition_list[41],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,__GET_VAR(data__->__transition_list[41]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[41],,0);
  }
  if (__GET_VAR(data__->ROTATINGRIGHT.X)) {
    __SET_VAR(data__->,__transition_list[42],,__GET_VAR(data__->SENSORROTRIGHT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,__GET_VAR(data__->__transition_list[42]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,__GET_VAR(data__->SENSORROTRIGHT,));
    }
    __SET_VAR(data__->,__transition_list[42],,0);
  }
  if (__GET_VAR(data__->NOTBUSYFRONT0.X)) {
    __SET_VAR(data__->,__transition_list[43],,!(__GET_VAR(data__->DOWNNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,__GET_VAR(data__->__transition_list[43]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,!(__GET_VAR(data__->DOWNNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[43],,0);
  }
  if (__GET_VAR(data__->MOVEFRONTSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[44],,__GET_VAR(data__->REACHEDSENSORDOWN,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,__GET_VAR(data__->__transition_list[44]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,__GET_VAR(data__->REACHEDSENSORDOWN,));
    }
    __SET_VAR(data__->,__transition_list[44],,0);
  }
  if (__GET_VAR(data__->TURNOFFFRONT0.X)) {
    __SET_VAR(data__->,__transition_list[45],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,__GET_VAR(data__->__transition_list[45]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[45],,0);
  }
  if (__GET_VAR(data__->RESETROTATE.X)) {
    __SET_VAR(data__->,__transition_list[46],,__GET_VAR(data__->SENSORROTLEFT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,__GET_VAR(data__->__transition_list[46]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,__GET_VAR(data__->SENSORROTLEFT,));
    }
    __SET_VAR(data__->,__transition_list[46],,0);
  }
  if (__GET_VAR(data__->RESETDONER.X)) {
    __SET_VAR(data__->,__transition_list[47],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,__GET_VAR(data__->__transition_list[47]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[47],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[48],,__GET_VAR(data__->RECEIVEPIECE,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,__GET_VAR(data__->__transition_list[48]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,__GET_VAR(data__->RECEIVEPIECE,));
    }
    __SET_VAR(data__->,__transition_list[48],,0);
  }
  if (__GET_VAR(data__->MOVEFRONT1.X)) {
    __SET_VAR(data__->,__transition_list[49],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,__GET_VAR(data__->__transition_list[49]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[49],,0);
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
    __SET_VAR(data__->,STEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,TURNOFFFRONT.X,,0);
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
    __SET_VAR(data__->,STEP2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,ROTATERIGHT2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,RIGHTROTATEED2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,NOTBUSYFRONT2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,ROTATINGLEFT2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,ROTATINGLEFT3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,NOTBUSYBACK2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,ROTATERIGHT1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,RIGHTROTATEED1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,NOTBUSYFRONT1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,ROTATINGLEFT1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,ROTATINGLEFT4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,NOTBUSYBACK3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,ROTATERIGHT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,RIGHTROTATEED0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,ROTATINGLEFT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,NOTBUSYBACK1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,MOVEBACKSTEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,TURNOFFBACK1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,ROTATERIGHT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,RIGHTROTATEED.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,ROTATINGLEFT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,NOTBUSYBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,MOVEBACKSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,TURNOFFBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,MOVEFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,ROTATINGRIGHT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,NOTBUSYFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,MOVEFRONTSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,TURNOFFFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,RESETROTATE.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,RESETDONER.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,MOVEFRONT1.X,,0);
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
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,TURNOFFFRONT.X,,1);
    data__->TURNOFFFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
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
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,1);
    data__->TURNOFFBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,ROTATERIGHT2.X,,1);
    data__->ROTATERIGHT2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,RIGHTROTATEED2.X,,1);
    data__->RIGHTROTATEED2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,NOTBUSYFRONT2.X,,1);
    data__->NOTBUSYFRONT2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,ROTATINGLEFT2.X,,1);
    data__->ROTATINGLEFT2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,ROTATINGLEFT3.X,,1);
    data__->ROTATINGLEFT3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,NOTBUSYBACK2.X,,1);
    data__->NOTBUSYBACK2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,ROTATERIGHT1.X,,1);
    data__->ROTATERIGHT1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,RIGHTROTATEED1.X,,1);
    data__->RIGHTROTATEED1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,NOTBUSYFRONT1.X,,1);
    data__->NOTBUSYFRONT1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,ROTATINGLEFT1.X,,1);
    data__->ROTATINGLEFT1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,ROTATINGLEFT4.X,,1);
    data__->ROTATINGLEFT4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,NOTBUSYBACK3.X,,1);
    data__->NOTBUSYBACK3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,ROTATERIGHT0.X,,1);
    data__->ROTATERIGHT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,RIGHTROTATEED0.X,,1);
    data__->RIGHTROTATEED0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,ROTATINGLEFT0.X,,1);
    data__->ROTATINGLEFT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,NOTBUSYBACK1.X,,1);
    data__->NOTBUSYBACK1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,MOVEBACKSTEP1.X,,1);
    data__->MOVEBACKSTEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,TURNOFFBACK1.X,,1);
    data__->TURNOFFBACK1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,ROTATERIGHT.X,,1);
    data__->ROTATERIGHT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,RIGHTROTATEED.X,,1);
    data__->RIGHTROTATEED.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,ROTATINGLEFT.X,,1);
    data__->ROTATINGLEFT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,NOTBUSYBACK0.X,,1);
    data__->NOTBUSYBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,MOVEBACKSTEP0.X,,1);
    data__->MOVEBACKSTEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,TURNOFFBACK0.X,,1);
    data__->TURNOFFBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,MOVEFRONT0.X,,1);
    data__->MOVEFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,ROTATINGRIGHT.X,,1);
    data__->ROTATINGRIGHT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,NOTBUSYFRONT0.X,,1);
    data__->NOTBUSYFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,MOVEFRONTSTEP0.X,,1);
    data__->MOVEFRONTSTEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,TURNOFFFRONT0.X,,1);
    data__->TURNOFFFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,RESETROTATE.X,,1);
    data__->RESETROTATE.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,RESETDONER.X,,1);
    data__->RESETDONER.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,MOVEFRONT1.X,,1);
    data__->MOVEFRONT1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
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

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_RESETPOSITION].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_RESETPOSITION].state,,0);};

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

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].set = 1;}

  }

  // TURNOFFBACK action associations
  {
    char active = __GET_VAR(data__->TURNOFFBACK.X);
    char activated = active && !data__->TURNOFFBACK.prev_state;
    char desactivated = !active && data__->TURNOFFBACK.prev_state;

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].reset = 1;}

  }

  // ROTATERIGHT2 action associations
  {
    char active = __GET_VAR(data__->ROTATERIGHT2.X);
    char activated = active && !data__->ROTATERIGHT2.prev_state;
    char desactivated = !active && data__->ROTATERIGHT2.prev_state;

    if (active)       {__SET_VAR(data__->,BACKMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,BACKMOTOR,,0);};

  }

  // RIGHTROTATEED2 action associations
  {
    char active = __GET_VAR(data__->RIGHTROTATEED2.X);
    char activated = active && !data__->RIGHTROTATEED2.prev_state;
    char desactivated = !active && data__->RIGHTROTATEED2.prev_state;

    if (active)       {__SET_VAR(data__->,RIGHTROTMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,RIGHTROTMOTOR,,0);};

  }

  // NOTBUSYFRONT2 action associations
  {
    char active = __GET_VAR(data__->NOTBUSYFRONT2.X);
    char activated = active && !data__->NOTBUSYFRONT2.prev_state;
    char desactivated = !active && data__->NOTBUSYFRONT2.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // ROTATINGLEFT2 action associations
  {
    char active = __GET_VAR(data__->ROTATINGLEFT2.X);
    char activated = active && !data__->ROTATINGLEFT2.prev_state;
    char desactivated = !active && data__->ROTATINGLEFT2.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDMOTOR,,0);};

  }

  // ROTATINGLEFT3 action associations
  {
    char active = __GET_VAR(data__->ROTATINGLEFT3.X);
    char activated = active && !data__->ROTATINGLEFT3.prev_state;
    char desactivated = !active && data__->ROTATINGLEFT3.prev_state;

    if (active)       {__SET_VAR(data__->,LEFTROTMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,LEFTROTMOTOR,,0);};

  }

  // ROTATERIGHT1 action associations
  {
    char active = __GET_VAR(data__->ROTATERIGHT1.X);
    char activated = active && !data__->ROTATERIGHT1.prev_state;
    char desactivated = !active && data__->ROTATERIGHT1.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDMOTOR,,0);};

  }

  // RIGHTROTATEED1 action associations
  {
    char active = __GET_VAR(data__->RIGHTROTATEED1.X);
    char activated = active && !data__->RIGHTROTATEED1.prev_state;
    char desactivated = !active && data__->RIGHTROTATEED1.prev_state;

    if (active)       {__SET_VAR(data__->,RIGHTROTMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,RIGHTROTMOTOR,,0);};

  }

  // NOTBUSYFRONT1 action associations
  {
    char active = __GET_VAR(data__->NOTBUSYFRONT1.X);
    char activated = active && !data__->NOTBUSYFRONT1.prev_state;
    char desactivated = !active && data__->NOTBUSYFRONT1.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // ROTATINGLEFT1 action associations
  {
    char active = __GET_VAR(data__->ROTATINGLEFT1.X);
    char activated = active && !data__->ROTATINGLEFT1.prev_state;
    char desactivated = !active && data__->ROTATINGLEFT1.prev_state;

    if (active)       {__SET_VAR(data__->,BACKMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,BACKMOTOR,,0);};

  }

  // ROTATINGLEFT4 action associations
  {
    char active = __GET_VAR(data__->ROTATINGLEFT4.X);
    char activated = active && !data__->ROTATINGLEFT4.prev_state;
    char desactivated = !active && data__->ROTATINGLEFT4.prev_state;

    if (active)       {__SET_VAR(data__->,LEFTROTMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,LEFTROTMOTOR,,0);};

  }

  // ROTATERIGHT0 action associations
  {
    char active = __GET_VAR(data__->ROTATERIGHT0.X);
    char activated = active && !data__->ROTATERIGHT0.prev_state;
    char desactivated = !active && data__->ROTATERIGHT0.prev_state;

    if (active)       {__SET_VAR(data__->,RIGHTROTMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,RIGHTROTMOTOR,,0);};

  }

  // RIGHTROTATEED0 action associations
  {
    char active = __GET_VAR(data__->RIGHTROTATEED0.X);
    char activated = active && !data__->RIGHTROTATEED0.prev_state;
    char desactivated = !active && data__->RIGHTROTATEED0.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDMOTOR,,0);};

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

    if (active)       {__SET_VAR(data__->,READYTORECEIVE,,1);};
    if (desactivated) {__SET_VAR(data__->,READYTORECEIVE,,0);};

  }

  // ROTATINGLEFT0 action associations
  {
    char active = __GET_VAR(data__->ROTATINGLEFT0.X);
    char activated = active && !data__->ROTATINGLEFT0.prev_state;
    char desactivated = !active && data__->ROTATINGLEFT0.prev_state;

    if (active)       {__SET_VAR(data__->,LEFTROTMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,LEFTROTMOTOR,,0);};

  }

  // MOVEBACKSTEP1 action associations
  {
    char active = __GET_VAR(data__->MOVEBACKSTEP1.X);
    char activated = active && !data__->MOVEBACKSTEP1.prev_state;
    char desactivated = !active && data__->MOVEBACKSTEP1.prev_state;

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].set = 1;}

  }

  // TURNOFFBACK1 action associations
  {
    char active = __GET_VAR(data__->TURNOFFBACK1.X);
    char activated = active && !data__->TURNOFFBACK1.prev_state;
    char desactivated = !active && data__->TURNOFFBACK1.prev_state;

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].reset = 1;}

  }

  // ROTATERIGHT action associations
  {
    char active = __GET_VAR(data__->ROTATERIGHT.X);
    char activated = active && !data__->ROTATERIGHT.prev_state;
    char desactivated = !active && data__->ROTATERIGHT.prev_state;

    if (active)       {__SET_VAR(data__->,RIGHTROTMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,RIGHTROTMOTOR,,0);};

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

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

  }

  // MOVEBACKSTEP0 action associations
  {
    char active = __GET_VAR(data__->MOVEBACKSTEP0.X);
    char activated = active && !data__->MOVEBACKSTEP0.prev_state;
    char desactivated = !active && data__->MOVEBACKSTEP0.prev_state;

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

  // MOVEFRONT1 action associations
  {
    char active = __GET_VAR(data__->MOVEFRONT1.X);
    char activated = active && !data__->MOVEFRONT1.prev_state;
    char desactivated = !active && data__->MOVEFRONT1.prev_state;

    if (active)       {__SET_VAR(data__->,FORWARDMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,FORWARDMOTOR,,0);};

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
  if (data__->__action_list[__SFC_LEFTROTMOTOR].reset) {
    __SET_VAR(data__->,LEFTROTMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_LEFTROTMOTOR].set) {
    __SET_VAR(data__->,LEFTROTMOTOR,,1);
  }
  if (data__->__action_list[__SFC_READYTORECEIVE].reset) {
    __SET_VAR(data__->,READYTORECEIVE,,0);
  }
  else if (data__->__action_list[__SFC_READYTORECEIVE].set) {
    __SET_VAR(data__->,READYTORECEIVE,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_RESETPOSITION].state)) {
    __SET_VAR(data__->,LEFTROTMOTOR,,!(__GET_VAR(data__->SENSORROTLEFT,)));
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
#undef STEP1
#undef __SFC_STEP1
#undef TURNOFFFRONT
#undef __SFC_TURNOFFFRONT
#undef MOVEBACK
#undef __SFC_MOVEBACK
#undef NOTBUSYBACK
#undef __SFC_NOTBUSYBACK
#undef MOVEBACKSTEP
#undef __SFC_MOVEBACKSTEP
#undef STEP2
#undef __SFC_STEP2
#undef TURNOFFBACK
#undef __SFC_TURNOFFBACK
#undef ROTATERIGHT2
#undef __SFC_ROTATERIGHT2
#undef RIGHTROTATEED2
#undef __SFC_RIGHTROTATEED2
#undef NOTBUSYFRONT2
#undef __SFC_NOTBUSYFRONT2
#undef ROTATINGLEFT2
#undef __SFC_ROTATINGLEFT2
#undef ROTATINGLEFT3
#undef __SFC_ROTATINGLEFT3
#undef NOTBUSYBACK2
#undef __SFC_NOTBUSYBACK2
#undef ROTATERIGHT1
#undef __SFC_ROTATERIGHT1
#undef RIGHTROTATEED1
#undef __SFC_RIGHTROTATEED1
#undef NOTBUSYFRONT1
#undef __SFC_NOTBUSYFRONT1
#undef ROTATINGLEFT1
#undef __SFC_ROTATINGLEFT1
#undef ROTATINGLEFT4
#undef __SFC_ROTATINGLEFT4
#undef NOTBUSYBACK3
#undef __SFC_NOTBUSYBACK3
#undef ROTATERIGHT0
#undef __SFC_ROTATERIGHT0
#undef RIGHTROTATEED0
#undef __SFC_RIGHTROTATEED0
#undef ROTATINGLEFT0
#undef __SFC_ROTATINGLEFT0
#undef NOTBUSYBACK1
#undef __SFC_NOTBUSYBACK1
#undef MOVEBACKSTEP1
#undef __SFC_MOVEBACKSTEP1
#undef TURNOFFBACK1
#undef __SFC_TURNOFFBACK1
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
#undef MOVEFRONT1
#undef __SFC_MOVEFRONT1

// Actions undefinitions
#undef __SFC_RESETPOSITION
#undef __SFC_ISBUSY
#undef __SFC_FORWARDMOTOR
#undef __SFC_BACKMOTOR
#undef __SFC_RIGHTROTMOTOR
#undef __SFC_LEFTROTMOTOR
#undef __SFC_READYTORECEIVE





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
  __INIT_VAR(data__->FORWARDTIMERON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUSHMOTORFORWARD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUSHMOTORBACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ISBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ROLLBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUSHSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUSHUPSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDROLL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORBACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORFRONT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORPUSHFORWARD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORPUSHBACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FRONTNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  UINT i;
  data__->__nb_steps = 17;
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
  data__->__nb_transitions = 20;
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
#define PUSHROLL0 __step_list[13]
#define __SFC_PUSHROLL0 13
#define NOTBUSYFRONT2 __step_list[14]
#define __SFC_NOTBUSYFRONT2 14
#define PUSHTOROLL0 __step_list[15]
#define __SFC_PUSHTOROLL0 15
#define RETRACTPUSHER0 __step_list[16]
#define __SFC_RETRACTPUSHER0 16

// Actions definitions
#define __SFC_ISBUSY 0
#define __SFC_FORWARDMOTOR 1
#define __SFC_FORWARDTIMERON 2
#define __SFC_BACKMOTOR 3
#define __SFC_PUSHMOTORFORWARD 4
#define __SFC_PUSHMOTORBACK 5

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
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_VAR(data__->BACKSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->BACKSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->MOVEBACK0.X)) {
    __SET_VAR(data__->,__transition_list[6],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->NOTBUSYBACK0.X)) {
    __SET_VAR(data__->,__transition_list[7],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[8],,__GET_VAR(data__->REACHEDSENSORBACK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->REACHEDSENSORBACK,));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->TURNOFFBACK0.X)) {
    __SET_VAR(data__->,__transition_list[9],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[10],,__GET_VAR(data__->PUSHSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->PUSHSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->PUSHROLL.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->NOTBUSYFRONT1.X)) {
    __SET_VAR(data__->,__transition_list[12],,!(__GET_VAR(data__->ROLLBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,!(__GET_VAR(data__->ROLLBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->PUSHTOROLL.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_VAR(data__->REACHEDROLL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->REACHEDROLL,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->RETRACTPUSHER.X)) {
    __SET_VAR(data__->,__transition_list[14],,__GET_VAR(data__->SENSORPUSHBACK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->SENSORPUSHBACK,));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[15],,__GET_VAR(data__->PUSHUPSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->PUSHUPSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->PUSHROLL0.X)) {
    __SET_VAR(data__->,__transition_list[16],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->NOTBUSYFRONT2.X)) {
    __SET_VAR(data__->,__transition_list[17],,!(__GET_VAR(data__->ROLLBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,!(__GET_VAR(data__->ROLLBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->PUSHTOROLL0.X)) {
    __SET_VAR(data__->,__transition_list[18],,__GET_VAR(data__->REACHEDROLL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->REACHEDROLL,));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->RETRACTPUSHER0.X)) {
    __SET_VAR(data__->,__transition_list[19],,__GET_VAR(data__->SENSORPUSHBACK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->SENSORPUSHBACK,));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
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
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,MOVEBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,NOTBUSYBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,MOVEBACKSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,TURNOFFBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,PUSHROLL.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,NOTBUSYFRONT1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,PUSHTOROLL.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,RETRACTPUSHER.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,PUSHROLL0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,NOTBUSYFRONT2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,PUSHTOROLL0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,RETRACTPUSHER0.X,,0);
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
    __SET_VAR(data__->,MOVEBACK0.X,,1);
    data__->MOVEBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,NOTBUSYBACK0.X,,1);
    data__->NOTBUSYBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,MOVEBACKSTEP0.X,,1);
    data__->MOVEBACKSTEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,TURNOFFBACK0.X,,1);
    data__->TURNOFFBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,PUSHROLL.X,,1);
    data__->PUSHROLL.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,NOTBUSYFRONT1.X,,1);
    data__->NOTBUSYFRONT1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,PUSHTOROLL.X,,1);
    data__->PUSHTOROLL.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,RETRACTPUSHER.X,,1);
    data__->RETRACTPUSHER.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,PUSHROLL0.X,,1);
    data__->PUSHROLL0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,NOTBUSYFRONT2.X,,1);
    data__->NOTBUSYFRONT2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,PUSHTOROLL0.X,,1);
    data__->PUSHTOROLL0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,RETRACTPUSHER0.X,,1);
    data__->RETRACTPUSHER0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
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

  // PUSHROLL0 action associations
  {
    char active = __GET_VAR(data__->PUSHROLL0.X);
    char activated = active && !data__->PUSHROLL0.prev_state;
    char desactivated = !active && data__->PUSHROLL0.prev_state;

    if (active)       {__SET_VAR(data__->,BACKMOTOR,,1);};
    if (desactivated) {__SET_VAR(data__->,BACKMOTOR,,0);};

  }

  // NOTBUSYFRONT2 action associations
  {
    char active = __GET_VAR(data__->NOTBUSYFRONT2.X);
    char activated = active && !data__->NOTBUSYFRONT2.prev_state;
    char desactivated = !active && data__->NOTBUSYFRONT2.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // PUSHTOROLL0 action associations
  {
    char active = __GET_VAR(data__->PUSHTOROLL0.X);
    char activated = active && !data__->PUSHTOROLL0.prev_state;
    char desactivated = !active && data__->PUSHTOROLL0.prev_state;

    if (active)       {__SET_VAR(data__->,PUSHMOTORFORWARD,,1);};
    if (desactivated) {__SET_VAR(data__->,PUSHMOTORFORWARD,,0);};

  }

  // RETRACTPUSHER0 action associations
  {
    char active = __GET_VAR(data__->RETRACTPUSHER0.X);
    char activated = active && !data__->RETRACTPUSHER0.prev_state;
    char desactivated = !active && data__->RETRACTPUSHER0.prev_state;

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
#undef PUSHROLL0
#undef __SFC_PUSHROLL0
#undef NOTBUSYFRONT2
#undef __SFC_NOTBUSYFRONT2
#undef PUSHTOROLL0
#undef __SFC_PUSHTOROLL0
#undef RETRACTPUSHER0
#undef __SFC_RETRACTPUSHER0

// Actions undefinitions
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
  __INIT_VAR(data__->MACHINETYPE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->USETOOL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->READYTOSEND,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TOOLTIMERON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INITIALPIECE_SAVED,0,retain)
  __INIT_VAR(data__->INITIALPIECE,0,retain)
  __INIT_VAR(data__->CURRENTPIECE,0,retain)
  __INIT_VAR(data__->FINALPIECE_SAVED,0,retain)
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
  R_TRIG_init__(&data__->ASD,retain);
  TON_init__(&data__->TON2,retain);
  TON_init__(&data__->TON3,retain);
  TON_init__(&data__->TON4,retain);
  TON_init__(&data__->TON5,retain);
  TON_init__(&data__->TON6,retain);
  TON_init__(&data__->TON7,retain);
  TON_init__(&data__->TON8,retain);
  TON_init__(&data__->TON9,retain);
  TON_init__(&data__->TON10,retain);
  UINT i;
  data__->__nb_steps = 60;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 24;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 75;
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
#define STEP46 __step_list[44]
#define __SFC_STEP46 44
#define STEP34 __step_list[45]
#define __SFC_STEP34 45
#define CHECKIFFINALC __step_list[46]
#define __SFC_CHECKIFFINALC 46
#define STEP40 __step_list[47]
#define __SFC_STEP40 47
#define STEP26 __step_list[48]
#define __SFC_STEP26 48
#define STEP41 __step_list[49]
#define __SFC_STEP41 49
#define STEP33 __step_list[50]
#define __SFC_STEP33 50
#define STEP42 __step_list[51]
#define __SFC_STEP42 51
#define STEP35 __step_list[52]
#define __SFC_STEP35 52
#define STEP37 __step_list[53]
#define __SFC_STEP37 53
#define STEP36 __step_list[54]
#define __SFC_STEP36 54
#define STEP38 __step_list[55]
#define __SFC_STEP38 55
#define STEP39 __step_list[56]
#define __SFC_STEP39 56
#define STEP44 __step_list[57]
#define __SFC_STEP44 57
#define STEP43 __step_list[58]
#define __SFC_STEP43 58
#define STEP45 __step_list[59]
#define __SFC_STEP45 59

// Actions definitions
#define __SFC_INCREMENTTOOLNUMBER 0
#define __SFC_TOOLSTANDBY 1
#define __SFC_COMPUTE_FUNCTION_BLOCKS 2
#define __SFC_SAVEPIECES 3
#define __SFC_CURRENTASINITIAL 4
#define __SFC_SETCURRENT3 5
#define __SFC_SETCURRENT5 6
#define __SFC_SETCURRENT7 7
#define __SFC_SETCURRENT6 8
#define __SFC_SETCURRENT4 9
#define __SFC_SETCURRENT8 10
#define __SFC_SETCURRENT9 11
#define __SFC_ISBUSY 12
#define __SFC_FORWARDMOTOR 13
#define __SFC_FORWARDTIMERON 14
#define __SFC_BACKMOTOR 15
#define __SFC_MOTORDOWN 16
#define __SFC_MOTORRIGHT 17
#define __SFC_TOOLPLUS 18
#define __SFC_USETOOL 19
#define __SFC_TOOLTIMERON 20
#define __SFC_MOTORUP 21
#define __SFC_MOTORLEFT 22
#define __SFC_READYTOSEND 23

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
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[5],,__GET_VAR(data__->BACKSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->BACKSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->MOVEBACK.X)) {
    __SET_VAR(data__->,__transition_list[6],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->NOTBUSYBACK.X)) {
    __SET_VAR(data__->,__transition_list[7],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,!(__GET_VAR(data__->BACKNOTBUSY,)));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->MOVEBACKSTEP.X)) {
    __SET_VAR(data__->,__transition_list[8],,__GET_VAR(data__->REACHEDSENSORBACK,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->REACHEDSENSORBACK,));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->TURNOFFBACK.X)) {
    __SET_VAR(data__->,__transition_list[9],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP.X)) {
    __SET_VAR(data__->,__transition_list[10],,__GET_VAR(data__->TOOLPIECE,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->TOOLPIECE,));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->MOVEFRONT0.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->REACHEDSENSOR,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->REACHEDSENSOR,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->STEP2.X)) {
    __SET_VAR(data__->,__transition_list[12],,(((__GET_VAR(data__->INITIALPIECE_SAVED,) == 1) || (__GET_VAR(data__->INITIALPIECE_SAVED,) == 3)) || (__GET_VAR(data__->INITIALPIECE_SAVED,) == 5)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,(((__GET_VAR(data__->INITIALPIECE_SAVED,) == 1) || (__GET_VAR(data__->INITIALPIECE_SAVED,) == 3)) || (__GET_VAR(data__->INITIALPIECE_SAVED,) == 5)));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->STEP4.X)) {
    __SET_VAR(data__->,__transition_list[13],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->CHECKIFFINALA.X)) {
    __SET_VAR(data__->,__transition_list[14],,(__GET_VAR(data__->CURRENTPIECE,) != __GET_VAR(data__->FINALPIECE_SAVED,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,(__GET_VAR(data__->CURRENTPIECE,) != __GET_VAR(data__->FINALPIECE_SAVED,)));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->STEP11.X)) {
    __SET_VAR(data__->,__transition_list[15],,(__GET_VAR(data__->CURRENTPIECE,) == 1));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,(__GET_VAR(data__->CURRENTPIECE,) == 1));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->STEP5.X)) {
    __SET_VAR(data__->,__transition_list[16],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->STEP0.X)) {
    __SET_VAR(data__->,__transition_list[17],,(__GET_VAR(data__->TOOLNUMBER,) == 1));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,(__GET_VAR(data__->TOOLNUMBER,) == 1));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->STEP8.X)) {
    __SET_VAR(data__->,__transition_list[18],,__GET_VAR(data__->TON2.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->TON2.Q,));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
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
  if (__GET_VAR(data__->STEP11.X)) {
    __SET_VAR(data__->,__transition_list[20],,(__GET_VAR(data__->CURRENTPIECE,) == 3));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,(__GET_VAR(data__->CURRENTPIECE,) == 3));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->STEP12.X)) {
    __SET_VAR(data__->,__transition_list[21],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->STEP14.X)) {
    __SET_VAR(data__->,__transition_list[22],,(__GET_VAR(data__->TOOLNUMBER,) == 2));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,(__GET_VAR(data__->TOOLNUMBER,) == 2));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->STEP13.X)) {
    __SET_VAR(data__->,__transition_list[23],,__GET_VAR(data__->TON3.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->TON3.Q,));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->STEP15.X)) {
    __SET_VAR(data__->,__transition_list[24],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->STEP11.X)) {
    __SET_VAR(data__->,__transition_list[25],,(__GET_VAR(data__->CURRENTPIECE,) == 5));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,(__GET_VAR(data__->CURRENTPIECE,) == 5));
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->STEP16.X)) {
    __SET_VAR(data__->,__transition_list[26],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->STEP18.X)) {
    __SET_VAR(data__->,__transition_list[27],,(__GET_VAR(data__->TOOLNUMBER,) == 3));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,(__GET_VAR(data__->TOOLNUMBER,) == 3));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->STEP17.X)) {
    __SET_VAR(data__->,__transition_list[28],,__GET_VAR(data__->TON4.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->TON4.Q,));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->STEP19.X)) {
    __SET_VAR(data__->,__transition_list[29],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->SENDTONEXT.X)) {
    __SET_VAR(data__->,__transition_list[30],,(__GET_VAR(data__->SENSORUP,) && __GET_VAR(data__->SENSORLEFT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,(__GET_VAR(data__->SENSORUP,) && __GET_VAR(data__->SENSORLEFT,)));
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->STEP3.X)) {
    __SET_VAR(data__->,__transition_list[31],,__GET_VAR(data__->NEXTREADYTORECEIVE,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->NEXTREADYTORECEIVE,));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }
  if (__GET_VAR(data__->STEP10.X)) {
    __SET_VAR(data__->,__transition_list[32],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->__transition_list[32]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->REACHEDSENSORFRONT,));
    }
    __SET_VAR(data__->,__transition_list[32],,0);
  }
  if (__GET_VAR(data__->CHECKIFFINALA.X)) {
    __SET_VAR(data__->,__transition_list[33],,(__GET_VAR(data__->CURRENTPIECE,) == __GET_VAR(data__->FINALPIECE_SAVED,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->__transition_list[33]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,(__GET_VAR(data__->CURRENTPIECE,) == __GET_VAR(data__->FINALPIECE_SAVED,)));
    }
    __SET_VAR(data__->,__transition_list[33],,0);
  }
  if (__GET_VAR(data__->STEP2.X)) {
    __SET_VAR(data__->,__transition_list[34],,(((__GET_VAR(data__->INITIALPIECE_SAVED,) == 2) || (__GET_VAR(data__->INITIALPIECE_SAVED,) == 4)) || (__GET_VAR(data__->INITIALPIECE_SAVED,) == 6)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_VAR(data__->__transition_list[34]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,(((__GET_VAR(data__->INITIALPIECE_SAVED,) == 2) || (__GET_VAR(data__->INITIALPIECE_SAVED,) == 4)) || (__GET_VAR(data__->INITIALPIECE_SAVED,) == 6)));
    }
    __SET_VAR(data__->,__transition_list[34],,0);
  }
  if (__GET_VAR(data__->STEP7.X)) {
    __SET_VAR(data__->,__transition_list[35],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->__transition_list[35]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[35],,0);
  }
  if (__GET_VAR(data__->CHECKIFFINALB.X)) {
    __SET_VAR(data__->,__transition_list[36],,(__GET_VAR(data__->CURRENTPIECE,) != __GET_VAR(data__->FINALPIECE_SAVED,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->__transition_list[36]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,(__GET_VAR(data__->CURRENTPIECE,) != __GET_VAR(data__->FINALPIECE_SAVED,)));
    }
    __SET_VAR(data__->,__transition_list[36],,0);
  }
  if (__GET_VAR(data__->STEP27.X)) {
    __SET_VAR(data__->,__transition_list[37],,(__GET_VAR(data__->CURRENTPIECE,) == 4));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_VAR(data__->__transition_list[37]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,(__GET_VAR(data__->CURRENTPIECE,) == 4));
    }
    __SET_VAR(data__->,__transition_list[37],,0);
  }
  if (__GET_VAR(data__->STEP20.X)) {
    __SET_VAR(data__->,__transition_list[38],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_VAR(data__->__transition_list[38]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    }
    __SET_VAR(data__->,__transition_list[38],,0);
  }
  if (__GET_VAR(data__->STEP28.X)) {
    __SET_VAR(data__->,__transition_list[39],,(__GET_VAR(data__->TOOLNUMBER,) == 2));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,__GET_VAR(data__->__transition_list[39]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,(__GET_VAR(data__->TOOLNUMBER,) == 2));
    }
    __SET_VAR(data__->,__transition_list[39],,0);
  }
  if (__GET_VAR(data__->STEP21.X)) {
    __SET_VAR(data__->,__transition_list[40],,__GET_VAR(data__->TON6.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_VAR(data__->__transition_list[40]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_VAR(data__->TON6.Q,));
    }
    __SET_VAR(data__->,__transition_list[40],,0);
  }
  if (__GET_VAR(data__->STEP29.X)) {
    __SET_VAR(data__->,__transition_list[41],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,__GET_VAR(data__->__transition_list[41]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[41],,0);
  }
  if (__GET_VAR(data__->STEP27.X)) {
    __SET_VAR(data__->,__transition_list[42],,(__GET_VAR(data__->CURRENTPIECE,) == 2));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,__GET_VAR(data__->__transition_list[42]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,(__GET_VAR(data__->CURRENTPIECE,) == 2));
    }
    __SET_VAR(data__->,__transition_list[42],,0);
  }
  if (__GET_VAR(data__->STEP9.X)) {
    __SET_VAR(data__->,__transition_list[43],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,__GET_VAR(data__->__transition_list[43]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    }
    __SET_VAR(data__->,__transition_list[43],,0);
  }
  if (__GET_VAR(data__->STEP23.X)) {
    __SET_VAR(data__->,__transition_list[44],,(__GET_VAR(data__->TOOLNUMBER,) == 1));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,__GET_VAR(data__->__transition_list[44]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,(__GET_VAR(data__->TOOLNUMBER,) == 1));
    }
    __SET_VAR(data__->,__transition_list[44],,0);
  }
  if (__GET_VAR(data__->STEP22.X)) {
    __SET_VAR(data__->,__transition_list[45],,__GET_VAR(data__->TON5.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,__GET_VAR(data__->__transition_list[45]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,__GET_VAR(data__->TON5.Q,));
    }
    __SET_VAR(data__->,__transition_list[45],,0);
  }
  if (__GET_VAR(data__->STEP24.X)) {
    __SET_VAR(data__->,__transition_list[46],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,__GET_VAR(data__->__transition_list[46]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[46],,0);
  }
  if (__GET_VAR(data__->STEP27.X)) {
    __SET_VAR(data__->,__transition_list[47],,(__GET_VAR(data__->CURRENTPIECE,) == 6));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,__GET_VAR(data__->__transition_list[47]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,(__GET_VAR(data__->CURRENTPIECE,) == 6));
    }
    __SET_VAR(data__->,__transition_list[47],,0);
  }
  if (__GET_VAR(data__->STEP25.X)) {
    __SET_VAR(data__->,__transition_list[48],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,__GET_VAR(data__->__transition_list[48]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    }
    __SET_VAR(data__->,__transition_list[48],,0);
  }
  if (__GET_VAR(data__->STEP31.X)) {
    __SET_VAR(data__->,__transition_list[49],,(__GET_VAR(data__->TOOLNUMBER,) == 3));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,__GET_VAR(data__->__transition_list[49]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,(__GET_VAR(data__->TOOLNUMBER,) == 3));
    }
    __SET_VAR(data__->,__transition_list[49],,0);
  }
  if (__GET_VAR(data__->STEP30.X)) {
    __SET_VAR(data__->,__transition_list[50],,__GET_VAR(data__->TON7.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[50],,__GET_VAR(data__->__transition_list[50]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[50],,__GET_VAR(data__->TON7.Q,));
    }
    __SET_VAR(data__->,__transition_list[50],,0);
  }
  if (__GET_VAR(data__->STEP32.X)) {
    __SET_VAR(data__->,__transition_list[51],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[51],,__GET_VAR(data__->__transition_list[51]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[51],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[51],,0);
  }
  if (__GET_VAR(data__->CHECKIFFINALB.X)) {
    __SET_VAR(data__->,__transition_list[52],,(__GET_VAR(data__->CURRENTPIECE,) == __GET_VAR(data__->FINALPIECE_SAVED,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[52],,__GET_VAR(data__->__transition_list[52]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[52],,(__GET_VAR(data__->CURRENTPIECE,) == __GET_VAR(data__->FINALPIECE_SAVED,)));
    }
    __SET_VAR(data__->,__transition_list[52],,0);
  }
  if (__GET_VAR(data__->STEP2.X)) {
    __SET_VAR(data__->,__transition_list[53],,(__GET_VAR(data__->INITIALPIECE_SAVED,) == __GET_VAR(data__->FINALPIECE_SAVED,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[53],,__GET_VAR(data__->__transition_list[53]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[53],,(__GET_VAR(data__->INITIALPIECE_SAVED,) == __GET_VAR(data__->FINALPIECE_SAVED,)));
    }
    __SET_VAR(data__->,__transition_list[53],,0);
  }
  if (__GET_VAR(data__->STEP2.X)) {
    __SET_VAR(data__->,__transition_list[54],,((__GET_VAR(data__->INITIALPIECE_SAVED,) == 7) || (__GET_VAR(data__->INITIALPIECE_SAVED,) == 8)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[54],,__GET_VAR(data__->__transition_list[54]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[54],,((__GET_VAR(data__->INITIALPIECE_SAVED,) == 7) || (__GET_VAR(data__->INITIALPIECE_SAVED,) == 8)));
    }
    __SET_VAR(data__->,__transition_list[54],,0);
  }
  if (__GET_VAR(data__->STEP46.X)) {
    __SET_VAR(data__->,__transition_list[55],,(__GET_VAR(data__->MACHINETYPE,) == 1));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[55],,__GET_VAR(data__->__transition_list[55]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[55],,(__GET_VAR(data__->MACHINETYPE,) == 1));
    }
    __SET_VAR(data__->,__transition_list[55],,0);
  }
  if (__GET_VAR(data__->STEP34.X)) {
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
  if (__GET_VAR(data__->CHECKIFFINALC.X)) {
    __SET_VAR(data__->,__transition_list[57],,(__GET_VAR(data__->CURRENTPIECE,) != __GET_VAR(data__->FINALPIECE_SAVED,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[57],,__GET_VAR(data__->__transition_list[57]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[57],,(__GET_VAR(data__->CURRENTPIECE,) != __GET_VAR(data__->FINALPIECE_SAVED,)));
    }
    __SET_VAR(data__->,__transition_list[57],,0);
  }
  if (__GET_VAR(data__->STEP40.X)) {
    __SET_VAR(data__->,__transition_list[58],,((__GET_VAR(data__->CURRENTPIECE,) == 8) && (__GET_VAR(data__->FINALPIECE_SAVED,) == 7)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[58],,__GET_VAR(data__->__transition_list[58]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[58],,((__GET_VAR(data__->CURRENTPIECE,) == 8) && (__GET_VAR(data__->FINALPIECE_SAVED,) == 7)));
    }
    __SET_VAR(data__->,__transition_list[58],,0);
  }
  if (__GET_VAR(data__->STEP26.X)) {
    __SET_VAR(data__->,__transition_list[59],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[59],,__GET_VAR(data__->__transition_list[59]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[59],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    }
    __SET_VAR(data__->,__transition_list[59],,0);
  }
  if (__GET_VAR(data__->STEP41.X)) {
    __SET_VAR(data__->,__transition_list[60],,(__GET_VAR(data__->TOOLNUMBER,) == 2));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[60],,__GET_VAR(data__->__transition_list[60]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[60],,(__GET_VAR(data__->TOOLNUMBER,) == 2));
    }
    __SET_VAR(data__->,__transition_list[60],,0);
  }
  if (__GET_VAR(data__->STEP33.X)) {
    __SET_VAR(data__->,__transition_list[61],,__GET_VAR(data__->TON9.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[61],,__GET_VAR(data__->__transition_list[61]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[61],,__GET_VAR(data__->TON9.Q,));
    }
    __SET_VAR(data__->,__transition_list[61],,0);
  }
  if (__GET_VAR(data__->STEP42.X)) {
    __SET_VAR(data__->,__transition_list[62],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[62],,__GET_VAR(data__->__transition_list[62]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[62],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[62],,0);
  }
  if (__GET_VAR(data__->STEP40.X)) {
    __SET_VAR(data__->,__transition_list[63],,((__GET_VAR(data__->CURRENTPIECE,) == 7) && (__GET_VAR(data__->FINALPIECE_SAVED,) == 8)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[63],,__GET_VAR(data__->__transition_list[63]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[63],,((__GET_VAR(data__->CURRENTPIECE,) == 7) && (__GET_VAR(data__->FINALPIECE_SAVED,) == 8)));
    }
    __SET_VAR(data__->,__transition_list[63],,0);
  }
  if (__GET_VAR(data__->STEP35.X)) {
    __SET_VAR(data__->,__transition_list[64],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[64],,__GET_VAR(data__->__transition_list[64]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[64],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    }
    __SET_VAR(data__->,__transition_list[64],,0);
  }
  if (__GET_VAR(data__->STEP37.X)) {
    __SET_VAR(data__->,__transition_list[65],,(__GET_VAR(data__->TOOLNUMBER,) == 1));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[65],,__GET_VAR(data__->__transition_list[65]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[65],,(__GET_VAR(data__->TOOLNUMBER,) == 1));
    }
    __SET_VAR(data__->,__transition_list[65],,0);
  }
  if (__GET_VAR(data__->STEP36.X)) {
    __SET_VAR(data__->,__transition_list[66],,__GET_VAR(data__->TON8.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[66],,__GET_VAR(data__->__transition_list[66]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[66],,__GET_VAR(data__->TON8.Q,));
    }
    __SET_VAR(data__->,__transition_list[66],,0);
  }
  if (__GET_VAR(data__->STEP38.X)) {
    __SET_VAR(data__->,__transition_list[67],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[67],,__GET_VAR(data__->__transition_list[67]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[67],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[67],,0);
  }
  if (__GET_VAR(data__->STEP40.X)) {
    __SET_VAR(data__->,__transition_list[68],,(((__GET_VAR(data__->CURRENTPIECE,) == 7) || (__GET_VAR(data__->CURRENTPIECE,) == 8)) && (__GET_VAR(data__->FINALPIECE_SAVED,) == 9)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[68],,__GET_VAR(data__->__transition_list[68]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[68],,(((__GET_VAR(data__->CURRENTPIECE,) == 7) || (__GET_VAR(data__->CURRENTPIECE,) == 8)) && (__GET_VAR(data__->FINALPIECE_SAVED,) == 9)));
    }
    __SET_VAR(data__->,__transition_list[68],,0);
  }
  if (__GET_VAR(data__->STEP39.X)) {
    __SET_VAR(data__->,__transition_list[69],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[69],,__GET_VAR(data__->__transition_list[69]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[69],,(__GET_VAR(data__->SENSORDOWN,) && __GET_VAR(data__->SENSORRIGHT,)));
    }
    __SET_VAR(data__->,__transition_list[69],,0);
  }
  if (__GET_VAR(data__->STEP44.X)) {
    __SET_VAR(data__->,__transition_list[70],,(__GET_VAR(data__->TOOLNUMBER,) == 3));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[70],,__GET_VAR(data__->__transition_list[70]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[70],,(__GET_VAR(data__->TOOLNUMBER,) == 3));
    }
    __SET_VAR(data__->,__transition_list[70],,0);
  }
  if (__GET_VAR(data__->STEP43.X)) {
    __SET_VAR(data__->,__transition_list[71],,__GET_VAR(data__->TON10.Q,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[71],,__GET_VAR(data__->__transition_list[71]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[71],,__GET_VAR(data__->TON10.Q,));
    }
    __SET_VAR(data__->,__transition_list[71],,0);
  }
  if (__GET_VAR(data__->STEP45.X)) {
    __SET_VAR(data__->,__transition_list[72],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[72],,__GET_VAR(data__->__transition_list[72]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[72],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[72],,0);
  }
  if (__GET_VAR(data__->CHECKIFFINALC.X)) {
    __SET_VAR(data__->,__transition_list[73],,(__GET_VAR(data__->CURRENTPIECE,) == __GET_VAR(data__->FINALPIECE_SAVED,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[73],,__GET_VAR(data__->__transition_list[73]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[73],,(__GET_VAR(data__->CURRENTPIECE,) == __GET_VAR(data__->FINALPIECE_SAVED,)));
    }
    __SET_VAR(data__->,__transition_list[73],,0);
  }
  if (__GET_VAR(data__->STEP46.X)) {
    __SET_VAR(data__->,__transition_list[74],,(__GET_VAR(data__->MACHINETYPE,) == 0));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[74],,__GET_VAR(data__->__transition_list[74]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[74],,(__GET_VAR(data__->MACHINETYPE,) == 0));
    }
    __SET_VAR(data__->,__transition_list[74],,0);
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
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,MOVEBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,NOTBUSYBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,MOVEBACKSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,MOVEFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,CHECKIFFINALA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP5.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP12.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP14.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP13.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP15.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP16.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP18.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP17.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP19.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,SENDTONEXT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,STEP10.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,CHECKIFFINALA.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,STEP2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,STEP7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,CHECKIFFINALB.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,STEP27.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,STEP20.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,STEP28.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,STEP21.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,STEP29.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,STEP27.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,STEP9.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,STEP23.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,STEP22.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,STEP24.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,STEP27.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,STEP25.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,STEP31.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[50])) {
    __SET_VAR(data__->,STEP30.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[51])) {
    __SET_VAR(data__->,STEP32.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[52])) {
    __SET_VAR(data__->,CHECKIFFINALB.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[53])) {
    __SET_VAR(data__->,STEP2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[54])) {
    __SET_VAR(data__->,STEP2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[55])) {
    __SET_VAR(data__->,STEP46.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[56])) {
    __SET_VAR(data__->,STEP34.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[57])) {
    __SET_VAR(data__->,CHECKIFFINALC.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[58])) {
    __SET_VAR(data__->,STEP40.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[59])) {
    __SET_VAR(data__->,STEP26.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[60])) {
    __SET_VAR(data__->,STEP41.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[61])) {
    __SET_VAR(data__->,STEP33.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[62])) {
    __SET_VAR(data__->,STEP42.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[63])) {
    __SET_VAR(data__->,STEP40.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[64])) {
    __SET_VAR(data__->,STEP35.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[65])) {
    __SET_VAR(data__->,STEP37.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[66])) {
    __SET_VAR(data__->,STEP36.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[67])) {
    __SET_VAR(data__->,STEP38.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[68])) {
    __SET_VAR(data__->,STEP40.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[69])) {
    __SET_VAR(data__->,STEP39.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[70])) {
    __SET_VAR(data__->,STEP44.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[71])) {
    __SET_VAR(data__->,STEP43.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[72])) {
    __SET_VAR(data__->,STEP45.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[73])) {
    __SET_VAR(data__->,CHECKIFFINALC.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[74])) {
    __SET_VAR(data__->,STEP46.X,,0);
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
    __SET_VAR(data__->,MOVEBACK.X,,1);
    data__->MOVEBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,NOTBUSYBACK.X,,1);
    data__->NOTBUSYBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,MOVEBACKSTEP.X,,1);
    data__->MOVEBACKSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,1);
    data__->TURNOFFBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,MOVEFRONT0.X,,1);
    data__->MOVEFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP4.X,,1);
    data__->STEP4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,CHECKIFFINALA.X,,1);
    data__->CHECKIFFINALA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP11.X,,1);
    data__->STEP11.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP5.X,,1);
    data__->STEP5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP8.X,,1);
    data__->STEP8.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,CHECKIFFINALA.X,,1);
    data__->CHECKIFFINALA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP12.X,,1);
    data__->STEP12.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP14.X,,1);
    data__->STEP14.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP13.X,,1);
    data__->STEP13.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP15.X,,1);
    data__->STEP15.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,CHECKIFFINALA.X,,1);
    data__->CHECKIFFINALA.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP16.X,,1);
    data__->STEP16.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP18.X,,1);
    data__->STEP18.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP17.X,,1);
    data__->STEP17.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP19.X,,1);
    data__->STEP19.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,SENDTONEXT.X,,1);
    data__->SENDTONEXT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP3.X,,1);
    data__->STEP3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP10.X,,1);
    data__->STEP10.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,1);
    data__->INITLINEARSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,SENDTONEXT.X,,1);
    data__->SENDTONEXT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,STEP7.X,,1);
    data__->STEP7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,CHECKIFFINALB.X,,1);
    data__->CHECKIFFINALB.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,STEP27.X,,1);
    data__->STEP27.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,STEP20.X,,1);
    data__->STEP20.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,STEP28.X,,1);
    data__->STEP28.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,STEP21.X,,1);
    data__->STEP21.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,STEP29.X,,1);
    data__->STEP29.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,CHECKIFFINALB.X,,1);
    data__->CHECKIFFINALB.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,STEP9.X,,1);
    data__->STEP9.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,STEP23.X,,1);
    data__->STEP23.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,STEP22.X,,1);
    data__->STEP22.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,STEP24.X,,1);
    data__->STEP24.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,CHECKIFFINALB.X,,1);
    data__->CHECKIFFINALB.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,STEP25.X,,1);
    data__->STEP25.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,STEP31.X,,1);
    data__->STEP31.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,STEP30.X,,1);
    data__->STEP30.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[50])) {
    __SET_VAR(data__->,STEP32.X,,1);
    data__->STEP32.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[51])) {
    __SET_VAR(data__->,SENDTONEXT.X,,1);
    data__->SENDTONEXT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[52])) {
    __SET_VAR(data__->,SENDTONEXT.X,,1);
    data__->SENDTONEXT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[53])) {
    __SET_VAR(data__->,SENDTONEXT.X,,1);
    data__->SENDTONEXT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[54])) {
    __SET_VAR(data__->,STEP46.X,,1);
    data__->STEP46.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[55])) {
    __SET_VAR(data__->,STEP34.X,,1);
    data__->STEP34.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[56])) {
    __SET_VAR(data__->,CHECKIFFINALC.X,,1);
    data__->CHECKIFFINALC.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[57])) {
    __SET_VAR(data__->,STEP40.X,,1);
    data__->STEP40.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[58])) {
    __SET_VAR(data__->,STEP26.X,,1);
    data__->STEP26.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[59])) {
    __SET_VAR(data__->,STEP41.X,,1);
    data__->STEP41.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[60])) {
    __SET_VAR(data__->,STEP33.X,,1);
    data__->STEP33.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[61])) {
    __SET_VAR(data__->,STEP42.X,,1);
    data__->STEP42.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[62])) {
    __SET_VAR(data__->,CHECKIFFINALC.X,,1);
    data__->CHECKIFFINALC.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[63])) {
    __SET_VAR(data__->,STEP35.X,,1);
    data__->STEP35.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[64])) {
    __SET_VAR(data__->,STEP37.X,,1);
    data__->STEP37.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[65])) {
    __SET_VAR(data__->,STEP36.X,,1);
    data__->STEP36.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[66])) {
    __SET_VAR(data__->,STEP38.X,,1);
    data__->STEP38.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[67])) {
    __SET_VAR(data__->,CHECKIFFINALC.X,,1);
    data__->CHECKIFFINALC.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[68])) {
    __SET_VAR(data__->,STEP39.X,,1);
    data__->STEP39.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[69])) {
    __SET_VAR(data__->,STEP44.X,,1);
    data__->STEP44.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[70])) {
    __SET_VAR(data__->,STEP43.X,,1);
    data__->STEP43.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[71])) {
    __SET_VAR(data__->,STEP45.X,,1);
    data__->STEP45.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[72])) {
    __SET_VAR(data__->,SENDTONEXT.X,,1);
    data__->SENDTONEXT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[73])) {
    __SET_VAR(data__->,SENDTONEXT.X,,1);
    data__->SENDTONEXT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[74])) {
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

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SAVEPIECES].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SAVEPIECES].state,,0);};

  }

  // STEP2 action associations
  {
    char active = __GET_VAR(data__->STEP2.X);
    char activated = active && !data__->STEP2.prev_state;
    char desactivated = !active && data__->STEP2.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

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

  // STEP46 action associations
  {
    char active = __GET_VAR(data__->STEP46.X);
    char activated = active && !data__->STEP46.prev_state;
    char desactivated = !active && data__->STEP46.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_CURRENTASINITIAL].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_CURRENTASINITIAL].state,,0);};

  }

  // STEP26 action associations
  {
    char active = __GET_VAR(data__->STEP26.X);
    char activated = active && !data__->STEP26.prev_state;
    char desactivated = !active && data__->STEP26.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

    if (active)       {__SET_VAR(data__->,MOTORDOWN,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORDOWN,,0);};

    if (active)       {__SET_VAR(data__->,MOTORRIGHT,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORRIGHT,,0);};

  }

  // STEP41 action associations
  {
    char active = __GET_VAR(data__->STEP41.X);
    char activated = active && !data__->STEP41.prev_state;
    char desactivated = !active && data__->STEP41.prev_state;

    if (active)       {__SET_VAR(data__->,TOOLPLUS,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLPLUS,,0);};

  }

  // STEP33 action associations
  {
    char active = __GET_VAR(data__->STEP33.X);
    char activated = active && !data__->STEP33.prev_state;
    char desactivated = !active && data__->STEP33.prev_state;

    if (active)       {__SET_VAR(data__->,USETOOL,,1);};
    if (desactivated) {__SET_VAR(data__->,USETOOL,,0);};

    if (active)       {__SET_VAR(data__->,TOOLTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLTIMERON,,0);};

  }

  // STEP42 action associations
  {
    char active = __GET_VAR(data__->STEP42.X);
    char activated = active && !data__->STEP42.prev_state;
    char desactivated = !active && data__->STEP42.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT7].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT7].state,,0);};

  }

  // STEP35 action associations
  {
    char active = __GET_VAR(data__->STEP35.X);
    char activated = active && !data__->STEP35.prev_state;
    char desactivated = !active && data__->STEP35.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

    if (active)       {__SET_VAR(data__->,MOTORDOWN,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORDOWN,,0);};

    if (active)       {__SET_VAR(data__->,MOTORRIGHT,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORRIGHT,,0);};

  }

  // STEP37 action associations
  {
    char active = __GET_VAR(data__->STEP37.X);
    char activated = active && !data__->STEP37.prev_state;
    char desactivated = !active && data__->STEP37.prev_state;

    if (active)       {__SET_VAR(data__->,TOOLPLUS,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLPLUS,,0);};

  }

  // STEP36 action associations
  {
    char active = __GET_VAR(data__->STEP36.X);
    char activated = active && !data__->STEP36.prev_state;
    char desactivated = !active && data__->STEP36.prev_state;

    if (active)       {__SET_VAR(data__->,USETOOL,,1);};
    if (desactivated) {__SET_VAR(data__->,USETOOL,,0);};

    if (active)       {__SET_VAR(data__->,TOOLTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLTIMERON,,0);};

  }

  // STEP38 action associations
  {
    char active = __GET_VAR(data__->STEP38.X);
    char activated = active && !data__->STEP38.prev_state;
    char desactivated = !active && data__->STEP38.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT8].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT8].state,,0);};

  }

  // STEP39 action associations
  {
    char active = __GET_VAR(data__->STEP39.X);
    char activated = active && !data__->STEP39.prev_state;
    char desactivated = !active && data__->STEP39.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

    if (active)       {__SET_VAR(data__->,MOTORDOWN,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORDOWN,,0);};

    if (active)       {__SET_VAR(data__->,MOTORRIGHT,,1);};
    if (desactivated) {__SET_VAR(data__->,MOTORRIGHT,,0);};

  }

  // STEP44 action associations
  {
    char active = __GET_VAR(data__->STEP44.X);
    char activated = active && !data__->STEP44.prev_state;
    char desactivated = !active && data__->STEP44.prev_state;

    if (active)       {__SET_VAR(data__->,TOOLPLUS,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLPLUS,,0);};

  }

  // STEP43 action associations
  {
    char active = __GET_VAR(data__->STEP43.X);
    char activated = active && !data__->STEP43.prev_state;
    char desactivated = !active && data__->STEP43.prev_state;

    if (active)       {__SET_VAR(data__->,USETOOL,,1);};
    if (desactivated) {__SET_VAR(data__->,USETOOL,,0);};

    if (active)       {__SET_VAR(data__->,TOOLTIMERON,,1);};
    if (desactivated) {__SET_VAR(data__->,TOOLTIMERON,,0);};

  }

  // STEP45 action associations
  {
    char active = __GET_VAR(data__->STEP45.X);
    char activated = active && !data__->STEP45.prev_state;
    char desactivated = !active && data__->STEP45.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT9].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SETCURRENT9].state,,0);};

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
    __SET_VAR(data__->TON9.,IN,,__GET_VAR(data__->TOOLTIMERON,));
    __SET_VAR(data__->TON9.,PT,,__time_to_timespec(1, 0, 20, 0, 0, 0));
    TON_body__(&data__->TON9);
    __SET_VAR(data__->TON8.,IN,,__GET_VAR(data__->TOOLTIMERON,));
    __SET_VAR(data__->TON8.,PT,,__time_to_timespec(1, 0, 20, 0, 0, 0));
    TON_body__(&data__->TON8);
    __SET_VAR(data__->TON10.,IN,,__GET_VAR(data__->TOOLTIMERON,));
    __SET_VAR(data__->TON10.,PT,,__time_to_timespec(1, 0, 20, 0, 0, 0));
    TON_body__(&data__->TON10);
  }

  if(__GET_VAR(data__->__action_list[__SFC_SAVEPIECES].state)) {
    __SET_VAR(data__->,INITIALPIECE_SAVED,,__GET_VAR(data__->INITIALPIECE,));
    __SET_VAR(data__->,FINALPIECE_SAVED,,__GET_VAR(data__->FINALPIECE,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_CURRENTASINITIAL].state)) {
    __SET_VAR(data__->,CURRENTPIECE,,__GET_VAR(data__->INITIALPIECE_SAVED,));
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

  if(__GET_VAR(data__->__action_list[__SFC_SETCURRENT9].state)) {
    __SET_VAR(data__->,CURRENTPIECE,,9);
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
#undef STEP46
#undef __SFC_STEP46
#undef STEP34
#undef __SFC_STEP34
#undef CHECKIFFINALC
#undef __SFC_CHECKIFFINALC
#undef STEP40
#undef __SFC_STEP40
#undef STEP26
#undef __SFC_STEP26
#undef STEP41
#undef __SFC_STEP41
#undef STEP33
#undef __SFC_STEP33
#undef STEP42
#undef __SFC_STEP42
#undef STEP35
#undef __SFC_STEP35
#undef STEP37
#undef __SFC_STEP37
#undef STEP36
#undef __SFC_STEP36
#undef STEP38
#undef __SFC_STEP38
#undef STEP39
#undef __SFC_STEP39
#undef STEP44
#undef __SFC_STEP44
#undef STEP43
#undef __SFC_STEP43
#undef STEP45
#undef __SFC_STEP45

// Actions undefinitions
#undef __SFC_INCREMENTTOOLNUMBER
#undef __SFC_TOOLSTANDBY
#undef __SFC_COMPUTE_FUNCTION_BLOCKS
#undef __SFC_SAVEPIECES
#undef __SFC_CURRENTASINITIAL
#undef __SFC_SETCURRENT3
#undef __SFC_SETCURRENT5
#undef __SFC_SETCURRENT7
#undef __SFC_SETCURRENT6
#undef __SFC_SETCURRENT4
#undef __SFC_SETCURRENT8
#undef __SFC_SETCURRENT9
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





void FACTORYFLOORPROGRAM_init__(FACTORYFLOORPROGRAM *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,ISLOADINGP1,data__->ISLOADINGP1,retain)
  __INIT_EXTERNAL(BOOL,ISLOADINGP2,data__->ISLOADINGP2,retain)
  __INIT_EXTERNAL(BOOL,SENDRIGHTDOWNCT2_EX,data__->SENDRIGHTDOWNCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNCT8_EX,data__->SENDLEFTDOWNCT8_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT7_EX,data__->RUNFRONTCT7_EX,retain)
  __INIT_EXTERNAL(BOOL,PUSHUPCT6_EX,data__->PUSHUPCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDRIGHTUPCT8_EX,data__->SENDRIGHTUPCT8_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDUPRIGHTMT6_EX,data__->SENDUPRIGHTMT6_EX,retain)
  __INIT_EXTERNAL(INT,CELL1INITIAL,data__->CELL1INITIAL,retain)
  __INIT_EXTERNAL(INT,CELL1FINAL,data__->CELL1FINAL,retain)
  __INIT_EXTERNAL(INT,CELL2INITIAL,data__->CELL2INITIAL,retain)
  __INIT_EXTERNAL(INT,CELL2FINAL,data__->CELL2FINAL,retain)
  __INIT_EXTERNAL(INT,CELL3INITIAL,data__->CELL3INITIAL,retain)
  __INIT_EXTERNAL(INT,CELL3FINAL,data__->CELL3FINAL,retain)
  __INIT_EXTERNAL(BOOL,GANTRYBUSY_EX,data__->GANTRYBUSY_EX,retain)
  __INIT_EXTERNAL(BOOL,RECEIVEPIECEMT1_EX,data__->RECEIVEPIECEMT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RECEIVEPIECEMT2_EX,data__->RECEIVEPIECEMT2_EX,retain)
  __INIT_EXTERNAL(BOOL,PICKPIECE_EX,data__->PICKPIECE_EX,retain)
  __INIT_EXTERNAL(BOOL,RELEASEPIECE_EX,data__->RELEASEPIECE_EX,retain)
  __INIT_EXTERNAL(BOOL,X0Y0_EX,data__->X0Y0_EX,retain)
  __INIT_EXTERNAL(BOOL,X0Y1_EX,data__->X0Y1_EX,retain)
  __INIT_EXTERNAL(BOOL,X0Y2_EX,data__->X0Y2_EX,retain)
  __INIT_EXTERNAL(BOOL,X0Y3_EX,data__->X0Y3_EX,retain)
  __INIT_EXTERNAL(BOOL,X0Y4_EX,data__->X0Y4_EX,retain)
  __INIT_EXTERNAL(BOOL,X1Y0_EX,data__->X1Y0_EX,retain)
  __INIT_EXTERNAL(BOOL,X1Y1_EX,data__->X1Y1_EX,retain)
  __INIT_EXTERNAL(BOOL,X1Y2_EX,data__->X1Y2_EX,retain)
  __INIT_EXTERNAL(BOOL,X1Y3_EX,data__->X1Y3_EX,retain)
  __INIT_EXTERNAL(BOOL,X1Y4_EX,data__->X1Y4_EX,retain)
  LINEARCONVEYOR_init__(&data__->AT1,retain);
  __INIT_LOCATED(BOOL,__QX0_1_0_0,data__->WAREHOUSEBUSY,retain)
  __INIT_LOCATED_VALUE(data__->WAREHOUSEBUSY,__BOOL_LITERAL(FALSE))
  __INIT_VAR(data__->WAREHOUSEBUSYCOMM,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(BOOL,__QX0_1_0_5,data__->CELL1BUSY,retain)
  __INIT_LOCATED_VALUE(data__->CELL1BUSY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1_0_6,data__->CELL2BUSY,retain)
  __INIT_LOCATED_VALUE(data__->CELL2BUSY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1_0_7,data__->CELL3BUSY,retain)
  __INIT_LOCATED_VALUE(data__->CELL3BUSY,__BOOL_LITERAL(FALSE))
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
  __INIT_EXTERNAL(BOOL,SENSORSBT5_EX,data__->SENSORSBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT4_EX,data__->SENSORSBT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT3_EX,data__->SENSORSBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT1_EX,data__->SENSORSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT2_EX,data__->SENSORSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT3_EX,data__->SENSORSCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT4_EX,data__->SENSORSCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT5_EX,data__->SENSORSCT5_EX,retain)
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
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT3_EX,data__->RUNFRONTSBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT4_EX,data__->RUNFRONTSBT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT5_EX,data__->RUNFRONTSBT5_EX,retain)
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
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNSBT6_EX,data__->SENDLEFTDOWNSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNSCT6_EX,data__->SENDLEFTDOWNSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RECEIVEPIECEMT3_EX,data__->RECEIVEPIECEMT3_EX,retain)
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
  __INIT_LOCATED(BOOL,__IX0_0_0_70,data__->SENSORMT3,retain)
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
  __INIT_EXTERNAL(BOOL,SENSORMT4_EX,data__->SENSORMT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSBT7_EX,data__->RUNBACKSBT7_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT6_EX,data__->SENSORSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT6_EX,data__->RUNFRONTSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSBT6_EX,data__->SENDDOWNSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSAT6_EX,data__->SENDDOWNSAT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSBT6_EX,data__->RUNBACKSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT6_EX,data__->SENSORSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT6_EX,data__->RUNFRONTSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT3_EX,data__->RUNFRONTSCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT4_EX,data__->RUNFRONTSCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT5_EX,data__->RUNFRONTSCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSCT6_EX,data__->RUNBACKSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKMT6_EX,data__->RUNBACKMT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RECEIVEPIECEMT4_EX,data__->RECEIVEPIECEMT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT4_EX,data__->RUNFRONTMT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT3_EX,data__->RUNFRONTMT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSCT6_EX,data__->SENDDOWNSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNMT6_EX,data__->SENDDOWNMT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT3_EX,data__->SENSORMT3_EX,retain)
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
  __INIT_EXTERNAL(BOOL,TOOLPIECESBT5_EX,data__->TOOLPIECESBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESBT3_EX,data__->TOOLPIECESBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESCT3_EX,data__->TOOLPIECESCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESCT5_EX,data__->TOOLPIECESCT5_EX,retain)
  LINEARCONVEYOR_init__(&data__->SAT4,retain);
  MACHINE_init__(&data__->SAT5,retain);
  __INIT_EXTERNAL(BOOL,READYTOSENDSAT3_EX,data__->READYTOSENDSAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSAT5_EX,data__->READYTOSENDSAT5_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSBT5_EX,data__->READYTOSENDSBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSBT3_EX,data__->READYTOSENDSBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSCT3_EX,data__->READYTOSENDSCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSCT5_EX,data__->READYTOSENDSCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,PUTPIECEINSIGNAL_EX,data__->PUTPIECEINSIGNAL_EX,retain)
  __INIT_LOCATED(INT,__IW0_1_1_0,data__->INITIALPIECE,retain)
  __INIT_LOCATED_VALUE(data__->INITIALPIECE,0)
  __INIT_LOCATED(INT,__IW0_1_1_3,data__->FINALPIECE,retain)
  __INIT_LOCATED_VALUE(data__->FINALPIECE,0)
  MACHINE_init__(&data__->SBT3,retain);
  LINEARCONVEYOR_init__(&data__->SBT4,retain);
  MACHINE_init__(&data__->SBT5,retain);
  MACHINE_init__(&data__->SCT3,retain);
  LINEARCONVEYOR_init__(&data__->SCT4,retain);
  MACHINE_init__(&data__->SCT5,retain);
  GANTRY_init__(&data__->GANTRY0,retain);
  __INIT_LOCATED(BOOL,__QX0_0_1_121,data__->MOTORZUPGANTRY,retain)
  __INIT_LOCATED_VALUE(data__->MOTORZUPGANTRY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_122,data__->MOTORZDOWNGANTRY,retain)
  __INIT_LOCATED_VALUE(data__->MOTORZDOWNGANTRY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_120,data__->MOTORYUPGANTRY,retain)
  __INIT_LOCATED_VALUE(data__->MOTORYUPGANTRY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_119,data__->MOTORYDOWNGANTRY,retain)
  __INIT_LOCATED_VALUE(data__->MOTORYDOWNGANTRY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_118,data__->MOTORXLEFTGANTRY,retain)
  __INIT_LOCATED_VALUE(data__->MOTORXLEFTGANTRY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_117,data__->MOTORXRIGHTGANTRY,retain)
  __INIT_LOCATED_VALUE(data__->MOTORXRIGHTGANTRY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_123,data__->GRABPIECEGANTRY,retain)
  __INIT_LOCATED_VALUE(data__->GRABPIECEGANTRY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_87,data__->SENSORZTOPGANTRY,retain)
  __INIT_LOCATED_VALUE(data__->SENSORZTOPGANTRY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_86,data__->SENSORZBOTTOMGANTRY,retain)
  __INIT_LOCATED_VALUE(data__->SENSORZBOTTOMGANTRY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_85,data__->SENSORY4GANTRY,retain)
  __INIT_LOCATED_VALUE(data__->SENSORY4GANTRY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_84,data__->SENSORY3GANTRY,retain)
  __INIT_LOCATED_VALUE(data__->SENSORY3GANTRY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_83,data__->SENSORY2GANTRY,retain)
  __INIT_LOCATED_VALUE(data__->SENSORY2GANTRY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_82,data__->SENSORY1GANTRY,retain)
  __INIT_LOCATED_VALUE(data__->SENSORY1GANTRY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_81,data__->SENSORY0GANTRY,retain)
  __INIT_LOCATED_VALUE(data__->SENSORY0GANTRY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_80,data__->SENSORX1GANTRY,retain)
  __INIT_LOCATED_VALUE(data__->SENSORX1GANTRY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_79,data__->SENSORX0GANTRY,retain)
  __INIT_LOCATED_VALUE(data__->SENSORX0GANTRY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_88,data__->SENSORPIECEGANTRY,retain)
  __INIT_LOCATED_VALUE(data__->SENSORPIECEGANTRY,__BOOL_LITERAL(FALSE))
  LINEARCONVEYOR_init__(&data__->MT4,retain);
  LINEARCONVEYOR_init__(&data__->MT3,retain);
  __INIT_VAR(data__->NOT432_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OR438_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OR436_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->NOT427_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OR434_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OR209_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OR425_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OR210_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void FACTORYFLOORPROGRAM_body__(FACTORYFLOORPROGRAM *data__) {
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
  __SET_VAR(data__->,NOT432_OUT,,!(__GET_LOCATED(data__->SENSORROTRIGHTCT8,)));
  __SET_VAR(data__->,OR438_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->NOT432_OUT,),
    (BOOL)__GET_EXTERNAL(data__->ISLOADINGP2,)));
  __SET_VAR(data__->CT6.,ROLLBUSY,,__GET_VAR(data__->PM3.HASPIECE,));
  __SET_VAR(data__->CT6.,PUSHSIGNAL,,__GET_EXTERNAL(data__->PUSHTOROLLCT6_EX,));
  __SET_VAR(data__->CT6.,PUSHUPSIGNAL,,__GET_EXTERNAL(data__->PUSHUPCT6_EX,));
  __SET_VAR(data__->CT6.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTCT6_EX,));
  __SET_VAR(data__->CT6.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT6,));
  __SET_VAR(data__->CT6.,REACHEDROLL,,__GET_LOCATED(data__->SENSORPM3,));
  __SET_VAR(data__->CT6.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORCT8,));
  __SET_VAR(data__->CT6.,SENSORPUSHFORWARD,,__GET_LOCATED(data__->SENSORPUSHFORWARDCT6,));
  __SET_VAR(data__->CT6.,SENSORPUSHBACK,,__GET_LOCATED(data__->SENSORPUSHBACKCT6,));
  __SET_VAR(data__->CT6.,FRONTNOTBUSY,,__GET_VAR(data__->OR438_OUT,));
  PUSHER_body__(&data__->CT6);
  __SET_VAR(data__->CT5.,ROLLBUSY,,__GET_VAR(data__->PM2.HASPIECE,));
  __SET_VAR(data__->CT5.,PUSHSIGNAL,,__GET_EXTERNAL(data__->PUSHTOROLLCT5_EX,));
  __SET_VAR(data__->CT5.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTCT5_EX,));
  __SET_VAR(data__->CT5.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT5,));
  __SET_VAR(data__->CT5.,REACHEDROLL,,__GET_LOCATED(data__->SENSORPM2,));
  __SET_VAR(data__->CT5.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORCT6,));
  __SET_VAR(data__->CT5.,SENSORPUSHFORWARD,,__GET_LOCATED(data__->SENSORPUSHFORWARDCT5,));
  __SET_VAR(data__->CT5.,SENSORPUSHBACK,,__GET_LOCATED(data__->SENSORPUSHBACKCT5,));
  __SET_VAR(data__->CT5.,FRONTNOTBUSY,,__GET_VAR(data__->CT6.ISBUSY,));
  PUSHER_body__(&data__->CT5);
  __SET_VAR(data__->CT4.,ROLLBUSY,,__GET_VAR(data__->PM1.HASPIECE,));
  __SET_VAR(data__->CT4.,PUSHSIGNAL,,__GET_EXTERNAL(data__->PUSHTOROLLCT4_EX,));
  __SET_VAR(data__->CT4.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTCT4_EX,));
  __SET_VAR(data__->CT4.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT4,));
  __SET_VAR(data__->CT4.,REACHEDROLL,,__GET_LOCATED(data__->SENSORPM1,));
  __SET_VAR(data__->CT4.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORCT5,));
  __SET_VAR(data__->CT4.,SENSORPUSHFORWARD,,__GET_LOCATED(data__->SENSORPUSHFORWARDCT4,));
  __SET_VAR(data__->CT4.,SENSORPUSHBACK,,__GET_LOCATED(data__->SENSORPUSHBACKCT4,));
  __SET_VAR(data__->CT4.,FRONTNOTBUSY,,__GET_VAR(data__->CT5.ISBUSY,));
  PUSHER_body__(&data__->CT4);
  __SET_VAR(data__->CT2.,SENDRIGHTDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDRIGHTDOWNCT2_EX,));
  __SET_VAR(data__->CT2.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKCT2_EX,));
  __SET_VAR(data__->CT2.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTCT2_EX,));
  __SET_VAR(data__->CT2.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNCT2_EX,));
  __SET_VAR(data__->CT2.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTCT2,));
  __SET_VAR(data__->CT2.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTCT2,));
  __SET_VAR(data__->CT2.,DOWNNOTBUSY,,__GET_VAR(data__->CT4.ISBUSY,));
  __SET_VAR(data__->CT2.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT2,));
  __SET_VAR(data__->CT2.,REACHEDSENSORDOWN,,__GET_LOCATED(data__->SENSORCT4,));
  ROTARYCONVEYOR_body__(&data__->CT2);
  __SET_LOCATED(data__->,BACKCT2,,__GET_VAR(data__->CT2.BACKMOTOR,));
  __SET_VAR(data__->,OR436_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_EXTERNAL(data__->ISLOADINGP1,),
    (BOOL)__GET_VAR(data__->CT2.ISBUSY,)));
  __SET_VAR(data__->CT1.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT1,));
  __SET_VAR(data__->CT1.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTCT1_EX,));
  __SET_VAR(data__->CT1.,FRONTNOTBUSY,,__GET_VAR(data__->OR436_OUT,));
  __SET_VAR(data__->CT1.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORCT2,));
  LINEARCONVEYOR_body__(&data__->CT1);
  __SET_VAR(data__->AT2.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORAT2,));
  __SET_VAR(data__->AT2.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKAT2_EX,));
  __SET_VAR(data__->AT2.,WAREHOUSEBUSY,,__GET_LOCATED(data__->WAREHOUSEBUSY,));
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
  __SET_VAR(data__->SBT7.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSBT7,));
  __SET_VAR(data__->SBT7.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKSBT7_EX,));
  __SET_VAR(data__->SBT7.,BACKNOTBUSY,,__GET_VAR(data__->SAT6.ISBUSY,));
  __SET_VAR(data__->SBT7.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSBT6,));
  __SET_VAR(data__->SBT7.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORSAT6,));
  LINEARCONVEYOR_body__(&data__->SBT7);
  __SET_VAR(data__->SBT6.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKSBT6_EX,));
  __SET_VAR(data__->SBT6.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSBT6_EX,));
  __SET_VAR(data__->SBT6.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNSBT6_EX,));
  __SET_VAR(data__->SBT6.,SENDLEFTDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDLEFTDOWNSBT6_EX,));
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
  __SET_VAR(data__->SCT6.,SENDLEFTDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDLEFTDOWNSCT6_EX,));
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
  __SET_VAR(data__->CT7.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT7,));
  __SET_VAR(data__->CT7.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKCT7_EX,));
  __SET_VAR(data__->CT7.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTCT7_EX,));
  __SET_VAR(data__->CT7.,BACKNOTBUSY,,__GET_VAR(data__->MT6.ISBUSY,));
  __SET_VAR(data__->CT7.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORCT8,));
  __SET_VAR(data__->CT7.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORMT6,));
  LINEARCONVEYOR_body__(&data__->CT7);
  __SET_VAR(data__->MT6.,SENDUPRIGHTSIGNAL,,__GET_EXTERNAL(data__->SENDUPRIGHTMT6_EX,));
  __SET_VAR(data__->MT6.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKMT6_EX,));
  __SET_VAR(data__->MT6.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNMT6_EX,));
  __SET_VAR(data__->MT6.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTMT6,));
  __SET_VAR(data__->MT6.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTMT6,));
  __SET_VAR(data__->MT6.,BACKNOTBUSY,,__GET_VAR(data__->MT5.ISBUSY,));
  __SET_VAR(data__->MT6.,FRONTNOTBUSY,,__GET_VAR(data__->CT7.ISBUSY,));
  __SET_VAR(data__->MT6.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORCT7,));
  __SET_VAR(data__->MT6.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORMT6,));
  __SET_VAR(data__->MT6.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORMT5,));
  ROTARYCONVEYOR_body__(&data__->MT6);
  __SET_VAR(data__->,NOT427_OUT,,!(__GET_VAR(data__->MT6.READYTORECEIVE,)));
  __SET_VAR(data__->MT4.,RECEIVEPIECE,,__GET_EXTERNAL(data__->RECEIVEPIECEMT4_EX,));
  __SET_VAR(data__->MT4.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORMT4,));
  __SET_VAR(data__->MT4.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTMT4_EX,));
  __SET_VAR(data__->MT4.,FRONTNOTBUSY,,__GET_VAR(data__->NOT427_OUT,));
  __SET_VAR(data__->MT4.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORMT6,));
  LINEARCONVEYOR_body__(&data__->MT4);
  __SET_VAR(data__->,OR434_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_LOCATED(data__->SENSORMT4,),
    (BOOL)__GET_VAR(data__->MT4.ISBUSY,)));
  __SET_VAR(data__->MT3.,RECEIVEPIECE,,__GET_EXTERNAL(data__->RECEIVEPIECEMT3_EX,));
  __SET_VAR(data__->MT3.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORMT3,));
  __SET_VAR(data__->MT3.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTMT3_EX,));
  __SET_VAR(data__->MT3.,FRONTNOTBUSY,,__GET_VAR(data__->OR434_OUT,));
  __SET_VAR(data__->MT3.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORMT4,));
  LINEARCONVEYOR_body__(&data__->MT3);
  __SET_VAR(data__->MT2.,RECEIVEPIECE,,__GET_EXTERNAL(data__->RECEIVEPIECEMT2_EX,));
  __SET_VAR(data__->MT2.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTMT2_EX,));
  __SET_VAR(data__->MT2.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNMT2_EX,));
  __SET_VAR(data__->MT2.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTMT2,));
  __SET_VAR(data__->MT2.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTMT2,));
  __SET_VAR(data__->MT2.,FRONTNOTBUSY,,__GET_VAR(data__->CT1.ISBUSY,));
  __SET_VAR(data__->MT2.,DOWNNOTBUSY,,__GET_VAR(data__->MT3.ISBUSY,));
  __SET_VAR(data__->MT2.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORCT1,));
  __SET_VAR(data__->MT2.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORMT2,));
  __SET_VAR(data__->MT2.,REACHEDSENSORDOWN,,__GET_LOCATED(data__->SENSORMT3,));
  ROTARYCONVEYOR_body__(&data__->MT2);
  __SET_VAR(data__->MT1.,RECEIVEPIECE,,__GET_EXTERNAL(data__->RECEIVEPIECEMT1_EX,));
  __SET_VAR(data__->MT1.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORMT1,));
  __SET_VAR(data__->MT1.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTMT1_EX,));
  __SET_VAR(data__->MT1.,FRONTNOTBUSY,,__GET_VAR(data__->MT2.ISBUSY,));
  __SET_VAR(data__->MT1.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORMT2,));
  LINEARCONVEYOR_body__(&data__->MT1);
  __SET_VAR(data__->SCT5.,MACHINETYPE,,1);
  __SET_VAR(data__->SCT5.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSCT5,));
  __SET_VAR(data__->SCT5.,INITIALPIECE,,__GET_VAR(data__->SCT3.CURRENTPIECE,));
  __SET_VAR(data__->SCT5.,FINALPIECE,,__GET_EXTERNAL(data__->CELL3FINAL,));
  __SET_VAR(data__->SCT5.,NEXTREADYTORECEIVE,,__GET_VAR(data__->SCT6.READYTORECEIVE,));
  __SET_VAR(data__->SCT5.,TOOLPIECE,,__GET_EXTERNAL(data__->TOOLPIECESCT5_EX,));
  __SET_VAR(data__->SCT5.,TOOLSENSOR,,__GET_LOCATED(data__->TOOLSENSORSCT5,));
  __SET_VAR(data__->SCT5.,SENSORUP,,__GET_LOCATED(data__->TOOLUPSENSORSCT5,));
  __SET_VAR(data__->SCT5.,SENSORLEFT,,__GET_LOCATED(data__->TOOLLEFTSENSORSCT5,));
  __SET_VAR(data__->SCT5.,SENSORDOWN,,__GET_LOCATED(data__->TOOLDOWNSENSORSCT5,));
  __SET_VAR(data__->SCT5.,SENSORRIGHT,,__GET_LOCATED(data__->TOOLRIGHTSENSORSCT5,));
  __SET_VAR(data__->SCT5.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSCT5_EX,));
  __SET_VAR(data__->SCT5.,FRONTNOTBUSY,,__GET_VAR(data__->SCT6.ISBUSY,));
  __SET_VAR(data__->SCT5.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSCT6,));
  MACHINE_body__(&data__->SCT5);
  __SET_VAR(data__->SCT4.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSCT4,));
  __SET_VAR(data__->SCT4.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSCT4_EX,));
  __SET_VAR(data__->SCT4.,FRONTNOTBUSY,,__GET_VAR(data__->SCT5.ISBUSY,));
  __SET_VAR(data__->SCT4.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSCT5,));
  LINEARCONVEYOR_body__(&data__->SCT4);
  __SET_VAR(data__->SCT3.,MACHINETYPE,,0);
  __SET_VAR(data__->SCT3.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSCT3,));
  __SET_VAR(data__->SCT3.,INITIALPIECE,,__GET_EXTERNAL(data__->CELL3INITIAL,));
  __SET_VAR(data__->SCT3.,FINALPIECE,,__GET_EXTERNAL(data__->CELL3FINAL,));
  __SET_VAR(data__->SCT3.,NEXTREADYTORECEIVE,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->SCT3.,TOOLPIECE,,__GET_EXTERNAL(data__->TOOLPIECESCT3_EX,));
  __SET_VAR(data__->SCT3.,TOOLSENSOR,,__GET_LOCATED(data__->TOOLSENSORSCT3,));
  __SET_VAR(data__->SCT3.,SENSORUP,,__GET_LOCATED(data__->TOOLUPSENSORSCT3,));
  __SET_VAR(data__->SCT3.,SENSORLEFT,,__GET_LOCATED(data__->TOOLLEFTSENSORSCT3,));
  __SET_VAR(data__->SCT3.,SENSORDOWN,,__GET_LOCATED(data__->TOOLDOWNSENSORSCT3,));
  __SET_VAR(data__->SCT3.,SENSORRIGHT,,__GET_LOCATED(data__->TOOLRIGHTSENSORSCT3,));
  __SET_VAR(data__->SCT3.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSCT3_EX,));
  __SET_VAR(data__->SCT3.,FRONTNOTBUSY,,__GET_VAR(data__->SCT4.ISBUSY,));
  __SET_VAR(data__->SCT3.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSCT4,));
  MACHINE_body__(&data__->SCT3);
  __SET_VAR(data__->SCT2.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSCT2_EX,));
  __SET_VAR(data__->SCT2.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNSCT2_EX,));
  __SET_VAR(data__->SCT2.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTSCT2,));
  __SET_VAR(data__->SCT2.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTSCT2,));
  __SET_VAR(data__->SCT2.,FRONTNOTBUSY,,__GET_VAR(data__->MT1.ISBUSY,));
  __SET_VAR(data__->SCT2.,DOWNNOTBUSY,,__GET_VAR(data__->SCT3.ISBUSY,));
  __SET_VAR(data__->SCT2.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORMT1,));
  __SET_VAR(data__->SCT2.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSCT2,));
  __SET_VAR(data__->SCT2.,REACHEDSENSORDOWN,,__GET_LOCATED(data__->SENSORSCT3,));
  ROTARYCONVEYOR_body__(&data__->SCT2);
  __SET_VAR(data__->SCT1.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSCT1,));
  __SET_VAR(data__->SCT1.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSCT1_EX,));
  __SET_VAR(data__->SCT1.,FRONTNOTBUSY,,__GET_VAR(data__->SCT2.ISBUSY,));
  __SET_VAR(data__->SCT1.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSCT2,));
  LINEARCONVEYOR_body__(&data__->SCT1);
  __SET_VAR(data__->SBT5.,MACHINETYPE,,1);
  __SET_VAR(data__->SBT5.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSBT5,));
  __SET_VAR(data__->SBT5.,INITIALPIECE,,__GET_VAR(data__->SBT3.CURRENTPIECE,));
  __SET_VAR(data__->SBT5.,FINALPIECE,,__GET_EXTERNAL(data__->CELL2FINAL,));
  __SET_VAR(data__->SBT5.,NEXTREADYTORECEIVE,,__GET_VAR(data__->SBT6.READYTORECEIVE,));
  __SET_VAR(data__->SBT5.,TOOLPIECE,,__GET_EXTERNAL(data__->TOOLPIECESBT5_EX,));
  __SET_VAR(data__->SBT5.,TOOLSENSOR,,__GET_LOCATED(data__->TOOLSENSORSBT5,));
  __SET_VAR(data__->SBT5.,SENSORUP,,__GET_LOCATED(data__->TOOLUPSENSORSBT5,));
  __SET_VAR(data__->SBT5.,SENSORLEFT,,__GET_LOCATED(data__->TOOLLEFTSENSORSBT5,));
  __SET_VAR(data__->SBT5.,SENSORDOWN,,__GET_LOCATED(data__->TOOLDOWNSENSORSBT5,));
  __SET_VAR(data__->SBT5.,SENSORRIGHT,,__GET_LOCATED(data__->TOOLRIGHTSENSORSBT5,));
  __SET_VAR(data__->SBT5.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSBT5_EX,));
  __SET_VAR(data__->SBT5.,FRONTNOTBUSY,,__GET_VAR(data__->SBT6.ISBUSY,));
  __SET_VAR(data__->SBT5.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSBT6,));
  MACHINE_body__(&data__->SBT5);
  __SET_VAR(data__->SBT4.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSBT4,));
  __SET_VAR(data__->SBT4.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSBT4_EX,));
  __SET_VAR(data__->SBT4.,FRONTNOTBUSY,,__GET_VAR(data__->SBT5.ISBUSY,));
  __SET_VAR(data__->SBT4.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSBT5,));
  LINEARCONVEYOR_body__(&data__->SBT4);
  __SET_VAR(data__->SBT3.,MACHINETYPE,,0);
  __SET_VAR(data__->SBT3.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSBT3,));
  __SET_VAR(data__->SBT3.,INITIALPIECE,,__GET_EXTERNAL(data__->CELL2INITIAL,));
  __SET_VAR(data__->SBT3.,FINALPIECE,,__GET_EXTERNAL(data__->CELL2FINAL,));
  __SET_VAR(data__->SBT3.,NEXTREADYTORECEIVE,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->SBT3.,TOOLPIECE,,__GET_EXTERNAL(data__->TOOLPIECESBT3_EX,));
  __SET_VAR(data__->SBT3.,TOOLSENSOR,,__GET_LOCATED(data__->TOOLSENSORSBT3,));
  __SET_VAR(data__->SBT3.,SENSORUP,,__GET_LOCATED(data__->TOOLUPSENSORSBT3,));
  __SET_VAR(data__->SBT3.,SENSORLEFT,,__GET_LOCATED(data__->TOOLLEFTSENSORSBT3,));
  __SET_VAR(data__->SBT3.,SENSORDOWN,,__GET_LOCATED(data__->TOOLDOWNSENSORSBT3,));
  __SET_VAR(data__->SBT3.,SENSORRIGHT,,__GET_LOCATED(data__->TOOLRIGHTSENSORSBT3,));
  __SET_VAR(data__->SBT3.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSBT3_EX,));
  __SET_VAR(data__->SBT3.,FRONTNOTBUSY,,__GET_VAR(data__->SBT4.ISBUSY,));
  __SET_VAR(data__->SBT3.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSBT4,));
  MACHINE_body__(&data__->SBT3);
  __SET_VAR(data__->SBT2.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSBT2_EX,));
  __SET_VAR(data__->SBT2.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNSBT2_EX,));
  __SET_VAR(data__->SBT2.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTSBT2,));
  __SET_VAR(data__->SBT2.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTSBT2,));
  __SET_VAR(data__->SBT2.,FRONTNOTBUSY,,__GET_VAR(data__->SCT1.ISBUSY,));
  __SET_VAR(data__->SBT2.,DOWNNOTBUSY,,__GET_VAR(data__->SBT3.ISBUSY,));
  __SET_VAR(data__->SBT2.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSCT1,));
  __SET_VAR(data__->SBT2.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSBT2,));
  __SET_VAR(data__->SBT2.,REACHEDSENSORDOWN,,__GET_LOCATED(data__->SENSORSBT3,));
  ROTARYCONVEYOR_body__(&data__->SBT2);
  __SET_VAR(data__->SBT1.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSBT1,));
  __SET_VAR(data__->SBT1.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTSBT1_EX,));
  __SET_VAR(data__->SBT1.,FRONTNOTBUSY,,__GET_VAR(data__->SBT2.ISBUSY,));
  __SET_VAR(data__->SBT1.,REACHEDSENSORFRONT,,__GET_LOCATED(data__->SENSORSBT2,));
  LINEARCONVEYOR_body__(&data__->SBT1);
  __SET_VAR(data__->SAT5.,MACHINETYPE,,1);
  __SET_VAR(data__->SAT5.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSAT5,));
  __SET_VAR(data__->SAT5.,INITIALPIECE,,__GET_VAR(data__->SAT3.CURRENTPIECE,));
  __SET_VAR(data__->SAT5.,FINALPIECE,,__GET_EXTERNAL(data__->CELL1FINAL,));
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
  __SET_VAR(data__->SAT3.,MACHINETYPE,,0);
  __SET_VAR(data__->SAT3.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORSAT3,));
  __SET_VAR(data__->SAT3.,INITIALPIECE,,__GET_EXTERNAL(data__->CELL1INITIAL,));
  __SET_VAR(data__->SAT3.,FINALPIECE,,__GET_EXTERNAL(data__->CELL1FINAL,));
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
  __SET_VAR(data__->,OR209_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->CT2.FORWARDMOTOR,),
    (BOOL)__GET_VAR(data__->CT2.ISBUSY,)));
  __SET_VAR(data__->CT3.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT3,));
  __SET_VAR(data__->CT3.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKCT3_EX,));
  __SET_VAR(data__->CT3.,BACKNOTBUSY,,__GET_VAR(data__->OR209_OUT,));
  __SET_VAR(data__->CT3.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORCT2,));
  LINEARCONVEYOR_body__(&data__->CT3);
  __SET_LOCATED(data__->,BACKCT3,,__GET_VAR(data__->CT3.BACKMOTOR,));
  __SET_LOCATED(data__->,LEFTROTSAT2,,__GET_VAR(data__->SAT2.LEFTROTMOTOR,));
  __SET_LOCATED(data__->,LEFTROTCT2,,__GET_VAR(data__->CT2.LEFTROTMOTOR,));
  __SET_LOCATED(data__->,LEFTROTSBT2,,__GET_VAR(data__->SBT2.LEFTROTMOTOR,));
  __SET_LOCATED(data__->,LEFTROTSCT2,,__GET_VAR(data__->SCT2.LEFTROTMOTOR,));
  __SET_LOCATED(data__->,FORWARDMT1,,__GET_VAR(data__->MT1.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDSCT1,,__GET_VAR(data__->SCT1.FORWARDMOTOR,));
  __SET_LOCATED(data__->,LEFTROTMT2,,__GET_VAR(data__->MT2.LEFTROTMOTOR,));
  __SET_EXTERNAL(data__->,SENSORSAT3_EX,,__GET_LOCATED(data__->SENSORSAT3,));
  __SET_LOCATED(data__->,USETOOLSAT3,,__GET_VAR(data__->SAT3.USETOOL,));
  __SET_EXTERNAL(data__->,SENSORSCT3_EX,,__GET_LOCATED(data__->SENSORSCT3,));
  __SET_LOCATED(data__->,USETOOLSCT3,,__GET_VAR(data__->SCT3.USETOOL,));
  __SET_LOCATED(data__->,TOOLPLUSSAT3,,__GET_VAR(data__->SAT3.TOOLPLUS,));
  __SET_EXTERNAL(data__->,SENSORSBT3_EX,,__GET_LOCATED(data__->SENSORSBT3,));
  __SET_LOCATED(data__->,USETOOLSBT3,,__GET_VAR(data__->SBT3.USETOOL,));
  __SET_LOCATED(data__->,TOOLPLUSSCT3,,__GET_VAR(data__->SCT3.TOOLPLUS,));
  __SET_LOCATED(data__->,TOOLMINUSSAT3,,__GET_VAR(data__->SAT3.TOOLMINUS,));
  __SET_EXTERNAL(data__->,READYTOSENDSAT3_EX,,__GET_VAR(data__->SAT3.READYTOSEND,));
  __SET_EXTERNAL(data__->,SENSORCT4_EX,,__GET_LOCATED(data__->SENSORCT4,));
  __SET_LOCATED(data__->,TOOLPLUSSBT3,,__GET_VAR(data__->SBT3.TOOLPLUS,));
  __SET_LOCATED(data__->,TOOLMINUSSCT3,,__GET_VAR(data__->SCT3.TOOLMINUS,));
  __SET_LOCATED(data__->,FORWARDCT4,,__GET_VAR(data__->CT4.FORWARDMOTOR,));
  __SET_EXTERNAL(data__->,READYTOSENDSCT3_EX,,__GET_VAR(data__->SCT3.READYTOSEND,));
  __SET_LOCATED(data__->,ZUPSAT3,,__GET_VAR(data__->SAT3.MOTORUP,));
  __SET_LOCATED(data__->,TOOLMINUSSBT3,,__GET_VAR(data__->SBT3.TOOLMINUS,));
  __SET_LOCATED(data__->,ZUPSCT3,,__GET_VAR(data__->SCT3.MOTORUP,));
  __SET_LOCATED(data__->,PUSHFORWARDCT4,,__GET_VAR(data__->CT4.PUSHMOTORFORWARD,));
  __SET_EXTERNAL(data__->,READYTOSENDSBT3_EX,,__GET_VAR(data__->SBT3.READYTOSEND,));
  __SET_LOCATED(data__->,XLEFTSAT3,,__GET_VAR(data__->SAT3.MOTORLEFT,));
  __SET_LOCATED(data__->,PUSHBACKCT4,,__GET_VAR(data__->CT4.PUSHMOTORBACK,));
  __SET_LOCATED(data__->,ZDOWNSAT3,,__GET_VAR(data__->SAT3.MOTORDOWN,));
  __SET_LOCATED(data__->,ZUPSBT3,,__GET_VAR(data__->SBT3.MOTORUP,));
  __SET_LOCATED(data__->,XLEFTSCT3,,__GET_VAR(data__->SCT3.MOTORLEFT,));
  __SET_LOCATED(data__->,XRIGHTSAT3,,__GET_VAR(data__->SAT3.MOTORRIGHT,));
  __SET_LOCATED(data__->,ZDOWNSCT3,,__GET_VAR(data__->SCT3.MOTORDOWN,));
  __SET_LOCATED(data__->,XLEFTSBT3,,__GET_VAR(data__->SBT3.MOTORLEFT,));
  __SET_LOCATED(data__->,XRIGHTSCT3,,__GET_VAR(data__->SCT3.MOTORRIGHT,));
  __SET_LOCATED(data__->,FORWARDSAT3,,__GET_VAR(data__->SAT3.FORWARDMOTOR,));
  __SET_VAR(data__->GANTRY0.,SENSORZTOP,,__GET_LOCATED(data__->SENSORZTOPGANTRY,));
  __SET_VAR(data__->GANTRY0.,SENSORZBOTTOM,,__GET_LOCATED(data__->SENSORZBOTTOMGANTRY,));
  __SET_VAR(data__->GANTRY0.,SENSORY0,,__GET_LOCATED(data__->SENSORY0GANTRY,));
  __SET_VAR(data__->GANTRY0.,SENSORY1,,__GET_LOCATED(data__->SENSORY1GANTRY,));
  __SET_VAR(data__->GANTRY0.,SENSORY2,,__GET_LOCATED(data__->SENSORY2GANTRY,));
  __SET_VAR(data__->GANTRY0.,SENSORY3,,__GET_LOCATED(data__->SENSORY3GANTRY,));
  __SET_VAR(data__->GANTRY0.,SENSORY4,,__GET_LOCATED(data__->SENSORY4GANTRY,));
  __SET_VAR(data__->GANTRY0.,SENSORX0,,__GET_LOCATED(data__->SENSORX0GANTRY,));
  __SET_VAR(data__->GANTRY0.,SENSORX1,,__GET_LOCATED(data__->SENSORX1GANTRY,));
  __SET_VAR(data__->GANTRY0.,PIECESENSOR,,__GET_LOCATED(data__->SENSORPIECEGANTRY,));
  __SET_VAR(data__->GANTRY0.,PICKPIECE,,__GET_EXTERNAL(data__->PICKPIECE_EX,));
  __SET_VAR(data__->GANTRY0.,RELEASEPIECE,,__GET_EXTERNAL(data__->RELEASEPIECE_EX,));
  __SET_VAR(data__->GANTRY0.,X0Y0,,__GET_EXTERNAL(data__->X0Y0_EX,));
  __SET_VAR(data__->GANTRY0.,X0Y1,,__GET_EXTERNAL(data__->X0Y1_EX,));
  __SET_VAR(data__->GANTRY0.,X0Y2,,__GET_EXTERNAL(data__->X0Y2_EX,));
  __SET_VAR(data__->GANTRY0.,X0Y3,,__GET_EXTERNAL(data__->X0Y3_EX,));
  __SET_VAR(data__->GANTRY0.,X0Y4,,__GET_EXTERNAL(data__->X0Y4_EX,));
  __SET_VAR(data__->GANTRY0.,X1Y0,,__GET_EXTERNAL(data__->X1Y0_EX,));
  __SET_VAR(data__->GANTRY0.,X1Y1,,__GET_EXTERNAL(data__->X1Y1_EX,));
  __SET_VAR(data__->GANTRY0.,X1Y2,,__GET_EXTERNAL(data__->X1Y2_EX,));
  __SET_VAR(data__->GANTRY0.,X1Y3,,__GET_EXTERNAL(data__->X1Y3_EX,));
  __SET_VAR(data__->GANTRY0.,X1Y4,,__GET_EXTERNAL(data__->X1Y4_EX,));
  GANTRY_body__(&data__->GANTRY0);
  __SET_LOCATED(data__->,MOTORZUPGANTRY,,__GET_VAR(data__->GANTRY0.MOTORZUP,));
  __SET_LOCATED(data__->,ZDOWNSBT3,,__GET_VAR(data__->SBT3.MOTORDOWN,));
  __SET_LOCATED(data__->,FORWARDSCT3,,__GET_VAR(data__->SCT3.FORWARDMOTOR,));
  __SET_LOCATED(data__->,MOTORZDOWNGANTRY,,__GET_VAR(data__->GANTRY0.MOTORZDOWN,));
  __SET_LOCATED(data__->,XRIGHTSBT3,,__GET_VAR(data__->SBT3.MOTORRIGHT,));
  __SET_LOCATED(data__->,MOTORYUPGANTRY,,__GET_VAR(data__->GANTRY0.MOTORYUP,));
  __SET_LOCATED(data__->,MOTORYDOWNGANTRY,,__GET_VAR(data__->GANTRY0.MOTORYDOWN,));
  __SET_LOCATED(data__->,FORWARDSBT3,,__GET_VAR(data__->SBT3.FORWARDMOTOR,));
  __SET_LOCATED(data__->,MOTORXRIGHTGANTRY,,__GET_VAR(data__->GANTRY0.MOTORXRIGHT,));
  __SET_LOCATED(data__->,MOTORXLEFTGANTRY,,__GET_VAR(data__->GANTRY0.MOTORXLEFT,));
  __SET_LOCATED(data__->,GRABPIECEGANTRY,,__GET_VAR(data__->GANTRY0.GRAB,));
  __SET_EXTERNAL(data__->,SENSORSAT4_EX,,__GET_LOCATED(data__->SENSORSAT4,));
  __SET_LOCATED(data__->,FORWARDCT5,,__GET_VAR(data__->CT5.FORWARDMOTOR,));
  __SET_EXTERNAL(data__->,SENSORSCT4_EX,,__GET_LOCATED(data__->SENSORSCT4,));
  __SET_LOCATED(data__->,FORWARDSAT4,,__GET_VAR(data__->SAT4.FORWARDMOTOR,));
  __SET_EXTERNAL(data__->,SENSORCT5_EX,,__GET_LOCATED(data__->SENSORCT5,));
  __SET_LOCATED(data__->,PUSHFORWARDCT5,,__GET_VAR(data__->CT5.PUSHMOTORFORWARD,));
  __SET_LOCATED(data__->,FORWARDSCT4,,__GET_VAR(data__->SCT4.FORWARDMOTOR,));
  __SET_EXTERNAL(data__->,GANTRYBUSY_EX,,__GET_VAR(data__->GANTRY0.GANTRYBUSY,));
  __SET_EXTERNAL(data__->,SENSORSBT4_EX,,__GET_LOCATED(data__->SENSORSBT4,));
  __SET_LOCATED(data__->,PUSHBACKCT5,,__GET_VAR(data__->CT5.PUSHMOTORBACK,));
  __SET_LOCATED(data__->,FORWARDSBT4,,__GET_VAR(data__->SBT4.FORWARDMOTOR,));
  __SET_EXTERNAL(data__->,SENSORMT3_EX,,__GET_LOCATED(data__->SENSORMT3,));
  __SET_LOCATED(data__->,FORWARDCT6,,__GET_VAR(data__->CT6.FORWARDMOTOR,));
  __SET_LOCATED(data__->,PUSHFORWARDCT6,,__GET_VAR(data__->CT6.PUSHMOTORFORWARD,));
  __SET_LOCATED(data__->,BACKCT6,,__GET_VAR(data__->CT6.BACKMOTOR,));
  __SET_EXTERNAL(data__->,SENSORCT6_EX,,__GET_LOCATED(data__->SENSORCT6,));
  __SET_LOCATED(data__->,FORWARDMT3,,__GET_VAR(data__->MT3.FORWARDMOTOR,));
  __SET_LOCATED(data__->,PUSHBACKCT6,,__GET_VAR(data__->CT6.PUSHMOTORBACK,));
  __SET_LOCATED(data__->,BACKMT3,,__GET_VAR(data__->MT3.BACKMOTOR,));
  __SET_EXTERNAL(data__->,SENSORSAT5_EX,,__GET_LOCATED(data__->SENSORSAT5,));
  __SET_LOCATED(data__->,USETOOLSAT5,,__GET_VAR(data__->SAT5.USETOOL,));
  __SET_LOCATED(data__->,USETOOLSCT5,,__GET_VAR(data__->SCT5.USETOOL,));
  __SET_EXTERNAL(data__->,SENSORSCT5_EX,,__GET_LOCATED(data__->SENSORSCT5,));
  __SET_LOCATED(data__->,TOOLPLUSSAT5,,__GET_VAR(data__->SAT5.TOOLPLUS,));
  __SET_EXTERNAL(data__->,READYTOSENDSAT5_EX,,__GET_VAR(data__->SAT5.READYTOSEND,));
  __SET_LOCATED(data__->,USETOOLSBT5,,__GET_VAR(data__->SBT5.USETOOL,));
  __SET_EXTERNAL(data__->,SENSORSBT5_EX,,__GET_LOCATED(data__->SENSORSBT5,));
  __SET_LOCATED(data__->,TOOLPLUSSCT5,,__GET_VAR(data__->SCT5.TOOLPLUS,));
  __SET_EXTERNAL(data__->,READYTOSENDSCT5_EX,,__GET_VAR(data__->SCT5.READYTOSEND,));
  __SET_LOCATED(data__->,TOOLMINUSSAT5,,__GET_VAR(data__->SAT5.TOOLMINUS,));
  __SET_LOCATED(data__->,TOOLPLUSSBT5,,__GET_VAR(data__->SBT5.TOOLPLUS,));
  __SET_EXTERNAL(data__->,READYTOSENDSBT5_EX,,__GET_VAR(data__->SBT5.READYTOSEND,));
  __SET_LOCATED(data__->,TOOLMINUSSCT5,,__GET_VAR(data__->SCT5.TOOLMINUS,));
  __SET_LOCATED(data__->,ZUPSAT5,,__GET_VAR(data__->SAT5.MOTORUP,));
  __SET_EXTERNAL(data__->,SENSORMT4_EX,,__GET_LOCATED(data__->SENSORMT4,));
  __SET_LOCATED(data__->,TOOLMINUSSBT5,,__GET_VAR(data__->SBT5.TOOLMINUS,));
  __SET_LOCATED(data__->,ZUPSCT5,,__GET_VAR(data__->SCT5.MOTORUP,));
  __SET_LOCATED(data__->,XLEFTSAT5,,__GET_VAR(data__->SAT5.MOTORLEFT,));
  __SET_LOCATED(data__->,ZDOWNSAT5,,__GET_VAR(data__->SAT5.MOTORDOWN,));
  __SET_LOCATED(data__->,ZUPSBT5,,__GET_VAR(data__->SBT5.MOTORUP,));
  __SET_LOCATED(data__->,XLEFTSCT5,,__GET_VAR(data__->SCT5.MOTORLEFT,));
  __SET_LOCATED(data__->,XRIGHTSAT5,,__GET_VAR(data__->SAT5.MOTORRIGHT,));
  __SET_LOCATED(data__->,ZDOWNSCT5,,__GET_VAR(data__->SCT5.MOTORDOWN,));
  __SET_LOCATED(data__->,XLEFTSBT5,,__GET_VAR(data__->SBT5.MOTORLEFT,));
  __SET_LOCATED(data__->,XRIGHTSCT5,,__GET_VAR(data__->SCT5.MOTORRIGHT,));
  __SET_LOCATED(data__->,FORWARDSAT5,,__GET_VAR(data__->SAT5.FORWARDMOTOR,));
  __SET_LOCATED(data__->,ZDOWNSBT5,,__GET_VAR(data__->SBT5.MOTORDOWN,));
  __SET_LOCATED(data__->,FORWARDSCT5,,__GET_VAR(data__->SCT5.FORWARDMOTOR,));
  __SET_LOCATED(data__->,FORWARDMT4,,__GET_VAR(data__->MT4.FORWARDMOTOR,));
  __SET_LOCATED(data__->,XRIGHTSBT5,,__GET_VAR(data__->SBT5.MOTORRIGHT,));
  __SET_LOCATED(data__->,FORWARDSBT5,,__GET_VAR(data__->SBT5.FORWARDMOTOR,));
  __SET_LOCATED(data__->,BACKMT4,,__GET_VAR(data__->MT4.BACKMOTOR,));
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
  __SET_VAR(data__->,OR425_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->CT6.FORWARDMOTOR,),
    (BOOL)__GET_VAR(data__->CT6.ISBUSY,)));
  __SET_VAR(data__->CT8.,SENDRIGHTUPSIGNAL,,__GET_EXTERNAL(data__->SENDRIGHTUPCT8_EX,));
  __SET_VAR(data__->CT8.,BACKSIGNAL,,__GET_EXTERNAL(data__->RUNBACKCT8_EX,));
  __SET_VAR(data__->CT8.,FORWARDSIGNAL,,__GET_EXTERNAL(data__->RUNFRONTCT8_EX,));
  __SET_VAR(data__->CT8.,SENDDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDDOWNCT8_EX,));
  __SET_VAR(data__->CT8.,SENDLEFTDOWNSIGNAL,,__GET_EXTERNAL(data__->SENDLEFTDOWNCT8_EX,));
  __SET_VAR(data__->CT8.,SENSORROTRIGHT,,__GET_LOCATED(data__->SENSORROTRIGHTCT8,));
  __SET_VAR(data__->CT8.,SENSORROTLEFT,,__GET_LOCATED(data__->SENSORROTLEFTCT8,));
  __SET_VAR(data__->CT8.,BACKNOTBUSY,,__GET_VAR(data__->CT7.ISBUSY,));
  __SET_VAR(data__->CT8.,UPNOTBUSY,,__GET_VAR(data__->OR425_OUT,));
  __SET_VAR(data__->CT8.,REACHEDSENSOR,,__GET_LOCATED(data__->SENSORCT8,));
  __SET_VAR(data__->CT8.,REACHEDSENSORBACK,,__GET_LOCATED(data__->SENSORCT7,));
  __SET_VAR(data__->CT8.,REACHEDSENSORUP,,__GET_LOCATED(data__->SENSORCT6,));
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
  __SET_LOCATED(data__->,BACKSAT7,,__GET_VAR(data__->SAT7.BACKMOTOR,));
  __SET_LOCATED(data__->,BACKSBT7,,__GET_VAR(data__->SBT7.BACKMOTOR,));
  __SET_LOCATED(data__->,FORWARDMT5,,__GET_VAR(data__->MT5.FORWARDMOTOR,));
  __SET_LOCATED(data__->,RIGHTROTMT6,,__GET_VAR(data__->MT6.RIGHTROTMOTOR,));
  __SET_LOCATED(data__->,LEFTROTSAT6,,__GET_VAR(data__->SAT6.LEFTROTMOTOR,));
  __SET_LOCATED(data__->,BACKCT7,,__GET_VAR(data__->CT7.BACKMOTOR,));
  __SET_LOCATED(data__->,LEFTROTCT8,,__GET_VAR(data__->CT8.LEFTROTMOTOR,));
  __SET_VAR(data__->,OR210_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)3,
    (BOOL)__GET_VAR(data__->CT8.FORWARDMOTOR,),
    (BOOL)__GET_VAR(data__->CT8.ISBUSY,),
    (BOOL)__GET_VAR(data__->CT8.LEFTROTMOTOR,)));
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

  goto __end;

__end:
  return;
} // FACTORYFLOORPROGRAM_body__() 





void TRANSFORMPROGRAM_init__(TRANSFORMPROGRAM *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,TAKEPIECE,data__->TAKEPIECE,retain)
  __INIT_EXTERNAL(INT,PIECENUM,data__->PIECENUM,retain)
  __INIT_EXTERNAL(INT,CELL1INITIAL,data__->CELL1INITIAL,retain)
  __INIT_EXTERNAL(INT,CELL1FINAL,data__->CELL1FINAL,retain)
  __INIT_EXTERNAL(INT,CELL2INITIAL,data__->CELL2INITIAL,retain)
  __INIT_EXTERNAL(INT,CELL2FINAL,data__->CELL2FINAL,retain)
  __INIT_EXTERNAL(INT,CELL3INITIAL,data__->CELL3INITIAL,retain)
  __INIT_EXTERNAL(INT,CELL3FINAL,data__->CELL3FINAL,retain)
  __INIT_LOCATED(INT,__IW0_0_2_0,data__->WAREHOUSEIN,retain)
  __INIT_LOCATED_VALUE(data__->WAREHOUSEIN,0)
  __INIT_LOCATED(BOOL,__IX0_0_0_0,data__->SENSORAT1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(INT,__IW0_1_1_2,data__->PM,retain)
  __INIT_LOCATED_VALUE(data__->PM,0)
  __INIT_LOCATED(INT,__IW0_1_1_4,data__->INITIALPIECE,retain)
  __INIT_LOCATED_VALUE(data__->INITIALPIECE,0)
  __INIT_LOCATED(INT,__IW0_1_1_3,data__->FINALPIECE,retain)
  __INIT_LOCATED_VALUE(data__->FINALPIECE,0)
  __INIT_LOCATED(BOOL,__QX0_1_0_0,data__->WAREHOUSEBUSY,retain)
  __INIT_LOCATED_VALUE(data__->WAREHOUSEBUSY,__BOOL_LITERAL(FALSE))
  __INIT_EXTERNAL(BOOL,RUNFRONTAT1_EX,data__->RUNFRONTAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT1_EX,data__->RUNFRONTSAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT2_EX,data__->RUNFRONTSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT4_EX,data__->RUNFRONTSAT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT1_EX,data__->RUNFRONTSBT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT2_EX,data__->RUNFRONTSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT4_EX,data__->RUNFRONTSBT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT1_EX,data__->RUNFRONTSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT2_EX,data__->RUNFRONTSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT4_EX,data__->RUNFRONTSCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT1_EX,data__->RUNFRONTMT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT2_EX,data__->RUNFRONTMT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT1_EX,data__->RUNFRONTCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT4_EX,data__->RUNFRONTCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT5_EX,data__->RUNFRONTCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSAT7_EX,data__->RUNBACKSAT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSCT7_EX,data__->RUNBACKSCT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSBT7_EX,data__->RUNBACKSBT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSBT6_EX,data__->RUNBACKSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSAT6_EX,data__->RUNBACKSAT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSAT2_EX,data__->SENDDOWNSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSBT2_EX,data__->SENDDOWNSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSCT2_EX,data__->SENDDOWNSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESAT3_EX,data__->TOOLPIECESAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESAT5_EX,data__->TOOLPIECESAT5_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESBT3_EX,data__->TOOLPIECESBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESBT5_EX,data__->TOOLPIECESBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESCT3_EX,data__->TOOLPIECESCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESCT5_EX,data__->TOOLPIECESCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNCT2_EX,data__->SENDDOWNCT2_EX,retain)
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
  __INIT_EXTERNAL(BOOL,SENSORSBT3_EX,data__->SENSORSBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT4_EX,data__->SENSORSBT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT5_EX,data__->SENSORSBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT6_EX,data__->SENSORSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT7_EX,data__->SENSORSBT7_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT1_EX,data__->SENSORSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT2_EX,data__->SENSORSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT3_EX,data__->SENSORSCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT4_EX,data__->SENSORSCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT5_EX,data__->SENSORSCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT6_EX,data__->SENSORSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT7_EX,data__->SENSORSCT7_EX,retain)
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
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNSBT6_EX,data__->SENDLEFTDOWNSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNSCT6_EX,data__->SENDLEFTDOWNSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,PUTPIECEINSIGNAL_EX,data__->PUTPIECEINSIGNAL_EX,retain)
  REMOVEFROMWAREHOUSE_init__(&data__->REMOVEFROMWAREHOUSE0,retain);
  __INIT_LOCATED(BOOL,__IX0_1_0_1,data__->RUNUNLOAD,retain)
  __INIT_LOCATED_VALUE(data__->RUNUNLOAD,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1_0_2,data__->RUNTRANSFORMMACH1,retain)
  __INIT_LOCATED_VALUE(data__->RUNTRANSFORMMACH1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1_0_3,data__->RUNTRANSFORMMACH2,retain)
  __INIT_LOCATED_VALUE(data__->RUNTRANSFORMMACH2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1_0_4,data__->RUNTRANSFORMMACH3,retain)
  __INIT_LOCATED_VALUE(data__->RUNTRANSFORMMACH3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1_0_5,data__->CELL1BUSY,retain)
  __INIT_LOCATED_VALUE(data__->CELL1BUSY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1_0_6,data__->CELL2BUSY,retain)
  __INIT_LOCATED_VALUE(data__->CELL2BUSY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1_0_7,data__->CELL3BUSY,retain)
  __INIT_LOCATED_VALUE(data__->CELL3BUSY,__BOOL_LITERAL(FALSE))
  __INIT_EXTERNAL(BOOL,READYTOSENDSAT3_EX,data__->READYTOSENDSAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSAT5_EX,data__->READYTOSENDSAT5_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSBT3_EX,data__->READYTOSENDSBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSBT5_EX,data__->READYTOSENDSBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSCT3_EX,data__->READYTOSENDSCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSCT5_EX,data__->READYTOSENDSCT5_EX,retain)
  UINT i;
  data__->__nb_steps = 82;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  __SET_VAR(data__->,__step_list[20].X,,1);
  __SET_VAR(data__->,__step_list[47].X,,1);
  data__->__nb_actions = 38;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 81;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define MACHINETRANSFORM1 __step_list[0]
#define __SFC_MACHINETRANSFORM1 0
#define STEP89 __step_list[1]
#define __SFC_STEP89 1
#define STEP86 __step_list[2]
#define __SFC_STEP86 2
#define STEP85 __step_list[3]
#define __SFC_STEP85 3
#define STEP84 __step_list[4]
#define __SFC_STEP84 4
#define STEP87 __step_list[5]
#define __SFC_STEP87 5
#define STEP90 __step_list[6]
#define __SFC_STEP90 6
#define STEP98 __step_list[7]
#define __SFC_STEP98 7
#define STEP92 __step_list[8]
#define __SFC_STEP92 8
#define STEP93 __step_list[9]
#define __SFC_STEP93 9
#define STEP99 __step_list[10]
#define __SFC_STEP99 10
#define STEP94 __step_list[11]
#define __SFC_STEP94 11
#define STEP95 __step_list[12]
#define __SFC_STEP95 12
#define STEP96 __step_list[13]
#define __SFC_STEP96 13
#define STEP97 __step_list[14]
#define __SFC_STEP97 14
#define STEP100 __step_list[15]
#define __SFC_STEP100 15
#define STEP101 __step_list[16]
#define __SFC_STEP101 16
#define STEP102 __step_list[17]
#define __SFC_STEP102 17
#define STEP0 __step_list[18]
#define __SFC_STEP0 18
#define STEP2 __step_list[19]
#define __SFC_STEP2 19
#define MACHINETRANSFORM2 __step_list[20]
#define __SFC_MACHINETRANSFORM2 20
#define STEP113 __step_list[21]
#define __SFC_STEP113 21
#define STEP112 __step_list[22]
#define __SFC_STEP112 22
#define STEP91 __step_list[23]
#define __SFC_STEP91 23
#define STEP88 __step_list[24]
#define __SFC_STEP88 24
#define STEP104 __step_list[25]
#define __SFC_STEP104 25
#define STEP106 __step_list[26]
#define __SFC_STEP106 26
#define STEP107 __step_list[27]
#define __SFC_STEP107 27
#define STEP108 __step_list[28]
#define __SFC_STEP108 28
#define STEP109 __step_list[29]
#define __SFC_STEP109 29
#define STEP110 __step_list[30]
#define __SFC_STEP110 30
#define STEP119 __step_list[31]
#define __SFC_STEP119 31
#define STEP111 __step_list[32]
#define __SFC_STEP111 32
#define STEP114 __step_list[33]
#define __SFC_STEP114 33
#define STEP120 __step_list[34]
#define __SFC_STEP120 34
#define STEP115 __step_list[35]
#define __SFC_STEP115 35
#define STEP116 __step_list[36]
#define __SFC_STEP116 36
#define STEP117 __step_list[37]
#define __SFC_STEP117 37
#define STEP118 __step_list[38]
#define __SFC_STEP118 38
#define STEP121 __step_list[39]
#define __SFC_STEP121 39
#define STEP122 __step_list[40]
#define __SFC_STEP122 40
#define STEP103 __step_list[41]
#define __SFC_STEP103 41
#define STEP105 __step_list[42]
#define __SFC_STEP105 42
#define STEP123 __step_list[43]
#define __SFC_STEP123 43
#define STEP124 __step_list[44]
#define __SFC_STEP124 44
#define STEP125 __step_list[45]
#define __SFC_STEP125 45
#define STEP3 __step_list[46]
#define __SFC_STEP3 46
#define MACHINETRANSFORM3 __step_list[47]
#define __SFC_MACHINETRANSFORM3 47
#define STEP133 __step_list[48]
#define __SFC_STEP133 48
#define STEP132 __step_list[49]
#define __SFC_STEP132 49
#define STEP127 __step_list[50]
#define __SFC_STEP127 50
#define STEP126 __step_list[51]
#define __SFC_STEP126 51
#define STEP128 __step_list[52]
#define __SFC_STEP128 52
#define STEP129 __step_list[53]
#define __SFC_STEP129 53
#define STEP130 __step_list[54]
#define __SFC_STEP130 54
#define STEP131 __step_list[55]
#define __SFC_STEP131 55
#define STEP135 __step_list[56]
#define __SFC_STEP135 56
#define STEP134 __step_list[57]
#define __SFC_STEP134 57
#define STEP136 __step_list[58]
#define __SFC_STEP136 58
#define STEP145 __step_list[59]
#define __SFC_STEP145 59
#define STEP138 __step_list[60]
#define __SFC_STEP138 60
#define STEP139 __step_list[61]
#define __SFC_STEP139 61
#define STEP143 __step_list[62]
#define __SFC_STEP143 62
#define STEP137 __step_list[63]
#define __SFC_STEP137 63
#define STEP140 __step_list[64]
#define __SFC_STEP140 64
#define STEP144 __step_list[65]
#define __SFC_STEP144 65
#define STEP141 __step_list[66]
#define __SFC_STEP141 66
#define STEP142 __step_list[67]
#define __SFC_STEP142 67
#define STEP146 __step_list[68]
#define __SFC_STEP146 68
#define STEP147 __step_list[69]
#define __SFC_STEP147 69
#define STEP148 __step_list[70]
#define __SFC_STEP148 70
#define STEP152 __step_list[71]
#define __SFC_STEP152 71
#define STEP153 __step_list[72]
#define __SFC_STEP153 72
#define STEP154 __step_list[73]
#define __SFC_STEP154 73
#define STEP156 __step_list[74]
#define __SFC_STEP156 74
#define STEP157 __step_list[75]
#define __SFC_STEP157 75
#define STEP150 __step_list[76]
#define __SFC_STEP150 76
#define STEP155 __step_list[77]
#define __SFC_STEP155 77
#define STEP158 __step_list[78]
#define __SFC_STEP158 78
#define STEP159 __step_list[79]
#define __SFC_STEP159 79
#define STEP160 __step_list[80]
#define __SFC_STEP160 80
#define STEP4 __step_list[81]
#define __SFC_STEP4 81

// Actions definitions
#define __SFC_ACTION0 0
#define __SFC_SETPIECE1 1
#define __SFC_SETPIECE2 2
#define __SFC_SETPIECE3 3
#define __SFC_CELL1BUSY 4
#define __SFC_RUNTRANSFORMMACH1 5
#define __SFC_WAREHOUSEBUSY 6
#define __SFC_RUNFRONTSAT1_EX 7
#define __SFC_RUNFRONTAT1_EX 8
#define __SFC_SENDDOWNSAT2_EX 9
#define __SFC_TOOLPIECESAT3_EX 10
#define __SFC_RUNFRONTSAT4_EX 11
#define __SFC_TOOLPIECESAT5_EX 12
#define __SFC_SENDLEFTDOWNSAT6_EX 13
#define __SFC_RUNBACKSAT7_EX 14
#define __SFC_PUTPIECEINSIGNAL_EX 15
#define __SFC_CELL2BUSY 16
#define __SFC_RUNTRANSFORMMACH2 17
#define __SFC_RUNFRONTSAT2_EX 18
#define __SFC_RUNFRONTSBT1_EX 19
#define __SFC_SENDDOWNSBT2_EX 20
#define __SFC_TOOLPIECESBT3_EX 21
#define __SFC_RUNFRONTSBT4_EX 22
#define __SFC_TOOLPIECESBT5_EX 23
#define __SFC_SENDLEFTDOWNSBT6_EX 24
#define __SFC_RUNBACKSBT7_EX 25
#define __SFC_RUNBACKSAT6_EX 26
#define __SFC_CELL3BUSY 27
#define __SFC_RUNTRANSFORMMACH3 28
#define __SFC_RUNFRONTSBT2_EX 29
#define __SFC_RUNFRONTSCT1_EX 30
#define __SFC_SENDDOWNSCT2_EX 31
#define __SFC_TOOLPIECESCT3_EX 32
#define __SFC_RUNFRONTSCT4_EX 33
#define __SFC_TOOLPIECESCT5_EX 34
#define __SFC_SENDLEFTDOWNSCT6_EX 35
#define __SFC_RUNBACKSCT7_EX 36
#define __SFC_RUNBACKSBT6_EX 37

// Code part
void TRANSFORMPROGRAM_body__(TRANSFORMPROGRAM *data__) {
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
  if (__GET_VAR(data__->MACHINETRANSFORM1.X)) {
    __SET_VAR(data__->,__transition_list[0],,(__GET_LOCATED(data__->RUNTRANSFORMMACH1,) && !(__GET_LOCATED(data__->WAREHOUSEBUSY,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,(__GET_LOCATED(data__->RUNTRANSFORMMACH1,) && !(__GET_LOCATED(data__->WAREHOUSEBUSY,))));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->STEP89.X)) {
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
  if (__GET_VAR(data__->STEP86.X)) {
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
  if (__GET_VAR(data__->STEP85.X)) {
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
  if (__GET_VAR(data__->STEP84.X)) {
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
  if (__GET_VAR(data__->STEP87.X)) {
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
  if (__GET_VAR(data__->STEP90.X)) {
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
  if (__GET_VAR(data__->STEP98.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_EXTERNAL(data__->READYTOSENDSAT3_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_EXTERNAL(data__->READYTOSENDSAT3_EX,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->STEP92.X)) {
    __SET_VAR(data__->,__transition_list[8],,__GET_EXTERNAL(data__->SENSORSAT4_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_EXTERNAL(data__->SENSORSAT4_EX,));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->STEP93.X)) {
    __SET_VAR(data__->,__transition_list[9],,!(__GET_EXTERNAL(data__->SENSORSAT4_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,!(__GET_EXTERNAL(data__->SENSORSAT4_EX,)));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->STEP99.X)) {
    __SET_VAR(data__->,__transition_list[10],,__GET_EXTERNAL(data__->READYTOSENDSAT5_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_EXTERNAL(data__->READYTOSENDSAT5_EX,));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->STEP94.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_EXTERNAL(data__->SENSORSAT6_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_EXTERNAL(data__->SENSORSAT6_EX,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->STEP95.X)) {
    __SET_VAR(data__->,__transition_list[12],,!(__GET_EXTERNAL(data__->SENSORSAT6_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,!(__GET_EXTERNAL(data__->SENSORSAT6_EX,)));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->STEP96.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_EXTERNAL(data__->SENSORSAT7_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_EXTERNAL(data__->SENSORSAT7_EX,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->STEP97.X)) {
    __SET_VAR(data__->,__transition_list[14],,!(__GET_EXTERNAL(data__->SENSORSAT7_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,!(__GET_EXTERNAL(data__->SENSORSAT7_EX,)));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->STEP100.X)) {
    __SET_VAR(data__->,__transition_list[15],,__GET_EXTERNAL(data__->SENSORAT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_EXTERNAL(data__->SENSORAT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->STEP101.X)) {
    __SET_VAR(data__->,__transition_list[16],,!(__GET_EXTERNAL(data__->SENSORAT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,!(__GET_EXTERNAL(data__->SENSORAT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->STEP102.X)) {
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
  if (__GET_VAR(data__->STEP2.X)) {
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
  if (__GET_VAR(data__->MACHINETRANSFORM2.X)) {
    __SET_VAR(data__->,__transition_list[19],,(__GET_LOCATED(data__->RUNTRANSFORMMACH2,) && !(__GET_LOCATED(data__->WAREHOUSEBUSY,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,(__GET_LOCATED(data__->RUNTRANSFORMMACH2,) && !(__GET_LOCATED(data__->WAREHOUSEBUSY,))));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->STEP113.X)) {
    __SET_VAR(data__->,__transition_list[20],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->STEP112.X)) {
    __SET_VAR(data__->,__transition_list[21],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->STEP91.X)) {
    __SET_VAR(data__->,__transition_list[22],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->STEP88.X)) {
    __SET_VAR(data__->,__transition_list[23],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->STEP104.X)) {
    __SET_VAR(data__->,__transition_list[24],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->STEP106.X)) {
    __SET_VAR(data__->,__transition_list[25],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->STEP107.X)) {
    __SET_VAR(data__->,__transition_list[26],,__GET_EXTERNAL(data__->SENSORSBT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_EXTERNAL(data__->SENSORSBT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->STEP108.X)) {
    __SET_VAR(data__->,__transition_list[27],,!(__GET_EXTERNAL(data__->SENSORSBT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,!(__GET_EXTERNAL(data__->SENSORSBT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->STEP109.X)) {
    __SET_VAR(data__->,__transition_list[28],,__GET_EXTERNAL(data__->SENSORSBT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_EXTERNAL(data__->SENSORSBT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->STEP110.X)) {
    __SET_VAR(data__->,__transition_list[29],,!(__GET_EXTERNAL(data__->SENSORSBT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,!(__GET_EXTERNAL(data__->SENSORSBT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->STEP119.X)) {
    __SET_VAR(data__->,__transition_list[30],,__GET_EXTERNAL(data__->READYTOSENDSBT3_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_EXTERNAL(data__->READYTOSENDSBT3_EX,));
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->STEP111.X)) {
    __SET_VAR(data__->,__transition_list[31],,__GET_EXTERNAL(data__->SENSORSBT4_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_EXTERNAL(data__->SENSORSBT4_EX,));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }
  if (__GET_VAR(data__->STEP114.X)) {
    __SET_VAR(data__->,__transition_list[32],,!(__GET_EXTERNAL(data__->SENSORSBT4_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->__transition_list[32]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,!(__GET_EXTERNAL(data__->SENSORSBT4_EX,)));
    }
    __SET_VAR(data__->,__transition_list[32],,0);
  }
  if (__GET_VAR(data__->STEP120.X)) {
    __SET_VAR(data__->,__transition_list[33],,__GET_EXTERNAL(data__->READYTOSENDSBT5_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->__transition_list[33]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_EXTERNAL(data__->READYTOSENDSBT5_EX,));
    }
    __SET_VAR(data__->,__transition_list[33],,0);
  }
  if (__GET_VAR(data__->STEP115.X)) {
    __SET_VAR(data__->,__transition_list[34],,__GET_EXTERNAL(data__->SENSORSBT6_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_VAR(data__->__transition_list[34]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_EXTERNAL(data__->SENSORSBT6_EX,));
    }
    __SET_VAR(data__->,__transition_list[34],,0);
  }
  if (__GET_VAR(data__->STEP116.X)) {
    __SET_VAR(data__->,__transition_list[35],,!(__GET_EXTERNAL(data__->SENSORSBT6_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->__transition_list[35]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,!(__GET_EXTERNAL(data__->SENSORSBT6_EX,)));
    }
    __SET_VAR(data__->,__transition_list[35],,0);
  }
  if (__GET_VAR(data__->STEP117.X)) {
    __SET_VAR(data__->,__transition_list[36],,__GET_EXTERNAL(data__->SENSORSBT7_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->__transition_list[36]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_EXTERNAL(data__->SENSORSBT7_EX,));
    }
    __SET_VAR(data__->,__transition_list[36],,0);
  }
  if (__GET_VAR(data__->STEP118.X)) {
    __SET_VAR(data__->,__transition_list[37],,!(__GET_EXTERNAL(data__->SENSORSBT7_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_VAR(data__->__transition_list[37]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,!(__GET_EXTERNAL(data__->SENSORSBT7_EX,)));
    }
    __SET_VAR(data__->,__transition_list[37],,0);
  }
  if (__GET_VAR(data__->STEP121.X)) {
    __SET_VAR(data__->,__transition_list[38],,__GET_EXTERNAL(data__->SENSORSAT6_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_VAR(data__->__transition_list[38]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_EXTERNAL(data__->SENSORSAT6_EX,));
    }
    __SET_VAR(data__->,__transition_list[38],,0);
  }
  if (__GET_VAR(data__->STEP122.X)) {
    __SET_VAR(data__->,__transition_list[39],,!(__GET_EXTERNAL(data__->SENSORSAT6_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,__GET_VAR(data__->__transition_list[39]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,!(__GET_EXTERNAL(data__->SENSORSAT6_EX,)));
    }
    __SET_VAR(data__->,__transition_list[39],,0);
  }
  if (__GET_VAR(data__->STEP103.X)) {
    __SET_VAR(data__->,__transition_list[40],,__GET_EXTERNAL(data__->SENSORSAT7_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_VAR(data__->__transition_list[40]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_EXTERNAL(data__->SENSORSAT7_EX,));
    }
    __SET_VAR(data__->,__transition_list[40],,0);
  }
  if (__GET_VAR(data__->STEP105.X)) {
    __SET_VAR(data__->,__transition_list[41],,!(__GET_EXTERNAL(data__->SENSORSAT7_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,__GET_VAR(data__->__transition_list[41]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,!(__GET_EXTERNAL(data__->SENSORSAT7_EX,)));
    }
    __SET_VAR(data__->,__transition_list[41],,0);
  }
  if (__GET_VAR(data__->STEP123.X)) {
    __SET_VAR(data__->,__transition_list[42],,__GET_EXTERNAL(data__->SENSORAT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,__GET_VAR(data__->__transition_list[42]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,__GET_EXTERNAL(data__->SENSORAT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[42],,0);
  }
  if (__GET_VAR(data__->STEP124.X)) {
    __SET_VAR(data__->,__transition_list[43],,!(__GET_EXTERNAL(data__->SENSORAT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,__GET_VAR(data__->__transition_list[43]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,!(__GET_EXTERNAL(data__->SENSORAT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[43],,0);
  }
  if (__GET_VAR(data__->STEP125.X)) {
    __SET_VAR(data__->,__transition_list[44],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,__GET_VAR(data__->__transition_list[44]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[44],,0);
  }
  if (__GET_VAR(data__->STEP3.X)) {
    __SET_VAR(data__->,__transition_list[45],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,__GET_VAR(data__->__transition_list[45]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[45],,0);
  }
  if (__GET_VAR(data__->MACHINETRANSFORM3.X)) {
    __SET_VAR(data__->,__transition_list[46],,(__GET_LOCATED(data__->RUNTRANSFORMMACH3,) && !(__GET_LOCATED(data__->WAREHOUSEBUSY,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,__GET_VAR(data__->__transition_list[46]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,(__GET_LOCATED(data__->RUNTRANSFORMMACH3,) && !(__GET_LOCATED(data__->WAREHOUSEBUSY,))));
    }
    __SET_VAR(data__->,__transition_list[46],,0);
  }
  if (__GET_VAR(data__->STEP133.X)) {
    __SET_VAR(data__->,__transition_list[47],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,__GET_VAR(data__->__transition_list[47]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[47],,0);
  }
  if (__GET_VAR(data__->STEP132.X)) {
    __SET_VAR(data__->,__transition_list[48],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,__GET_VAR(data__->__transition_list[48]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[48],,0);
  }
  if (__GET_VAR(data__->STEP127.X)) {
    __SET_VAR(data__->,__transition_list[49],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,__GET_VAR(data__->__transition_list[49]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[49],,0);
  }
  if (__GET_VAR(data__->STEP126.X)) {
    __SET_VAR(data__->,__transition_list[50],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[50],,__GET_VAR(data__->__transition_list[50]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[50],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[50],,0);
  }
  if (__GET_VAR(data__->STEP128.X)) {
    __SET_VAR(data__->,__transition_list[51],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[51],,__GET_VAR(data__->__transition_list[51]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[51],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[51],,0);
  }
  if (__GET_VAR(data__->STEP129.X)) {
    __SET_VAR(data__->,__transition_list[52],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[52],,__GET_VAR(data__->__transition_list[52]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[52],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[52],,0);
  }
  if (__GET_VAR(data__->STEP130.X)) {
    __SET_VAR(data__->,__transition_list[53],,__GET_EXTERNAL(data__->SENSORSBT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[53],,__GET_VAR(data__->__transition_list[53]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[53],,__GET_EXTERNAL(data__->SENSORSBT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[53],,0);
  }
  if (__GET_VAR(data__->STEP131.X)) {
    __SET_VAR(data__->,__transition_list[54],,!(__GET_EXTERNAL(data__->SENSORSBT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[54],,__GET_VAR(data__->__transition_list[54]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[54],,!(__GET_EXTERNAL(data__->SENSORSBT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[54],,0);
  }
  if (__GET_VAR(data__->STEP135.X)) {
    __SET_VAR(data__->,__transition_list[55],,__GET_EXTERNAL(data__->SENSORSBT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[55],,__GET_VAR(data__->__transition_list[55]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[55],,__GET_EXTERNAL(data__->SENSORSBT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[55],,0);
  }
  if (__GET_VAR(data__->STEP134.X)) {
    __SET_VAR(data__->,__transition_list[56],,!(__GET_EXTERNAL(data__->SENSORSBT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[56],,__GET_VAR(data__->__transition_list[56]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[56],,!(__GET_EXTERNAL(data__->SENSORSBT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[56],,0);
  }
  if (__GET_VAR(data__->STEP136.X)) {
    __SET_VAR(data__->,__transition_list[57],,__GET_EXTERNAL(data__->SENSORSCT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[57],,__GET_VAR(data__->__transition_list[57]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[57],,__GET_EXTERNAL(data__->SENSORSCT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[57],,0);
  }
  if (__GET_VAR(data__->STEP145.X)) {
    __SET_VAR(data__->,__transition_list[58],,!(__GET_EXTERNAL(data__->SENSORSCT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[58],,__GET_VAR(data__->__transition_list[58]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[58],,!(__GET_EXTERNAL(data__->SENSORSCT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[58],,0);
  }
  if (__GET_VAR(data__->STEP138.X)) {
    __SET_VAR(data__->,__transition_list[59],,__GET_EXTERNAL(data__->SENSORSCT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[59],,__GET_VAR(data__->__transition_list[59]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[59],,__GET_EXTERNAL(data__->SENSORSCT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[59],,0);
  }
  if (__GET_VAR(data__->STEP139.X)) {
    __SET_VAR(data__->,__transition_list[60],,!(__GET_EXTERNAL(data__->SENSORSCT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[60],,__GET_VAR(data__->__transition_list[60]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[60],,!(__GET_EXTERNAL(data__->SENSORSCT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[60],,0);
  }
  if (__GET_VAR(data__->STEP143.X)) {
    __SET_VAR(data__->,__transition_list[61],,__GET_EXTERNAL(data__->READYTOSENDSCT3_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[61],,__GET_VAR(data__->__transition_list[61]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[61],,__GET_EXTERNAL(data__->READYTOSENDSCT3_EX,));
    }
    __SET_VAR(data__->,__transition_list[61],,0);
  }
  if (__GET_VAR(data__->STEP137.X)) {
    __SET_VAR(data__->,__transition_list[62],,__GET_EXTERNAL(data__->SENSORSCT4_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[62],,__GET_VAR(data__->__transition_list[62]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[62],,__GET_EXTERNAL(data__->SENSORSCT4_EX,));
    }
    __SET_VAR(data__->,__transition_list[62],,0);
  }
  if (__GET_VAR(data__->STEP140.X)) {
    __SET_VAR(data__->,__transition_list[63],,!(__GET_EXTERNAL(data__->SENSORSCT4_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[63],,__GET_VAR(data__->__transition_list[63]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[63],,!(__GET_EXTERNAL(data__->SENSORSCT4_EX,)));
    }
    __SET_VAR(data__->,__transition_list[63],,0);
  }
  if (__GET_VAR(data__->STEP144.X)) {
    __SET_VAR(data__->,__transition_list[64],,__GET_EXTERNAL(data__->READYTOSENDSCT5_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[64],,__GET_VAR(data__->__transition_list[64]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[64],,__GET_EXTERNAL(data__->READYTOSENDSCT5_EX,));
    }
    __SET_VAR(data__->,__transition_list[64],,0);
  }
  if (__GET_VAR(data__->STEP141.X)) {
    __SET_VAR(data__->,__transition_list[65],,__GET_EXTERNAL(data__->SENSORSCT6_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[65],,__GET_VAR(data__->__transition_list[65]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[65],,__GET_EXTERNAL(data__->SENSORSCT6_EX,));
    }
    __SET_VAR(data__->,__transition_list[65],,0);
  }
  if (__GET_VAR(data__->STEP142.X)) {
    __SET_VAR(data__->,__transition_list[66],,!(__GET_EXTERNAL(data__->SENSORSCT6_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[66],,__GET_VAR(data__->__transition_list[66]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[66],,!(__GET_EXTERNAL(data__->SENSORSCT6_EX,)));
    }
    __SET_VAR(data__->,__transition_list[66],,0);
  }
  if (__GET_VAR(data__->STEP146.X)) {
    __SET_VAR(data__->,__transition_list[67],,__GET_EXTERNAL(data__->SENSORSCT7_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[67],,__GET_VAR(data__->__transition_list[67]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[67],,__GET_EXTERNAL(data__->SENSORSCT7_EX,));
    }
    __SET_VAR(data__->,__transition_list[67],,0);
  }
  if (__GET_VAR(data__->STEP147.X)) {
    __SET_VAR(data__->,__transition_list[68],,!(__GET_EXTERNAL(data__->SENSORSCT7_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[68],,__GET_VAR(data__->__transition_list[68]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[68],,!(__GET_EXTERNAL(data__->SENSORSCT7_EX,)));
    }
    __SET_VAR(data__->,__transition_list[68],,0);
  }
  if (__GET_VAR(data__->STEP148.X)) {
    __SET_VAR(data__->,__transition_list[69],,__GET_EXTERNAL(data__->SENSORSBT6_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[69],,__GET_VAR(data__->__transition_list[69]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[69],,__GET_EXTERNAL(data__->SENSORSBT6_EX,));
    }
    __SET_VAR(data__->,__transition_list[69],,0);
  }
  if (__GET_VAR(data__->STEP152.X)) {
    __SET_VAR(data__->,__transition_list[70],,!(__GET_EXTERNAL(data__->SENSORSBT6_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[70],,__GET_VAR(data__->__transition_list[70]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[70],,!(__GET_EXTERNAL(data__->SENSORSBT6_EX,)));
    }
    __SET_VAR(data__->,__transition_list[70],,0);
  }
  if (__GET_VAR(data__->STEP153.X)) {
    __SET_VAR(data__->,__transition_list[71],,__GET_EXTERNAL(data__->SENSORSBT7_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[71],,__GET_VAR(data__->__transition_list[71]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[71],,__GET_EXTERNAL(data__->SENSORSBT7_EX,));
    }
    __SET_VAR(data__->,__transition_list[71],,0);
  }
  if (__GET_VAR(data__->STEP154.X)) {
    __SET_VAR(data__->,__transition_list[72],,!(__GET_EXTERNAL(data__->SENSORSBT7_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[72],,__GET_VAR(data__->__transition_list[72]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[72],,!(__GET_EXTERNAL(data__->SENSORSBT7_EX,)));
    }
    __SET_VAR(data__->,__transition_list[72],,0);
  }
  if (__GET_VAR(data__->STEP156.X)) {
    __SET_VAR(data__->,__transition_list[73],,__GET_EXTERNAL(data__->SENSORSAT6_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[73],,__GET_VAR(data__->__transition_list[73]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[73],,__GET_EXTERNAL(data__->SENSORSAT6_EX,));
    }
    __SET_VAR(data__->,__transition_list[73],,0);
  }
  if (__GET_VAR(data__->STEP157.X)) {
    __SET_VAR(data__->,__transition_list[74],,!(__GET_EXTERNAL(data__->SENSORSAT6_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[74],,__GET_VAR(data__->__transition_list[74]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[74],,!(__GET_EXTERNAL(data__->SENSORSAT6_EX,)));
    }
    __SET_VAR(data__->,__transition_list[74],,0);
  }
  if (__GET_VAR(data__->STEP150.X)) {
    __SET_VAR(data__->,__transition_list[75],,__GET_EXTERNAL(data__->SENSORSAT7_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[75],,__GET_VAR(data__->__transition_list[75]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[75],,__GET_EXTERNAL(data__->SENSORSAT7_EX,));
    }
    __SET_VAR(data__->,__transition_list[75],,0);
  }
  if (__GET_VAR(data__->STEP155.X)) {
    __SET_VAR(data__->,__transition_list[76],,!(__GET_EXTERNAL(data__->SENSORSAT7_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[76],,__GET_VAR(data__->__transition_list[76]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[76],,!(__GET_EXTERNAL(data__->SENSORSAT7_EX,)));
    }
    __SET_VAR(data__->,__transition_list[76],,0);
  }
  if (__GET_VAR(data__->STEP158.X)) {
    __SET_VAR(data__->,__transition_list[77],,__GET_EXTERNAL(data__->SENSORAT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[77],,__GET_VAR(data__->__transition_list[77]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[77],,__GET_EXTERNAL(data__->SENSORAT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[77],,0);
  }
  if (__GET_VAR(data__->STEP159.X)) {
    __SET_VAR(data__->,__transition_list[78],,!(__GET_EXTERNAL(data__->SENSORAT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[78],,__GET_VAR(data__->__transition_list[78]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[78],,!(__GET_EXTERNAL(data__->SENSORAT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[78],,0);
  }
  if (__GET_VAR(data__->STEP160.X)) {
    __SET_VAR(data__->,__transition_list[79],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[79],,__GET_VAR(data__->__transition_list[79]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[79],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[79],,0);
  }
  if (__GET_VAR(data__->STEP4.X)) {
    __SET_VAR(data__->,__transition_list[80],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[80],,__GET_VAR(data__->__transition_list[80]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[80],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[80],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,MACHINETRANSFORM1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP89.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP86.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP85.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP84.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP87.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP90.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP98.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP92.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP93.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP99.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP94.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP95.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP96.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP97.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP100.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP101.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP102.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,MACHINETRANSFORM2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP113.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP112.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP91.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP88.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP104.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP106.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP107.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP108.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP109.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP110.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP119.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP111.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,STEP114.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,STEP120.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,STEP115.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,STEP116.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,STEP117.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,STEP118.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,STEP121.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,STEP122.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,STEP103.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,STEP105.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,STEP123.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,STEP124.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,STEP125.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,STEP3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,MACHINETRANSFORM3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,STEP133.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,STEP132.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,STEP127.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[50])) {
    __SET_VAR(data__->,STEP126.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[51])) {
    __SET_VAR(data__->,STEP128.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[52])) {
    __SET_VAR(data__->,STEP129.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[53])) {
    __SET_VAR(data__->,STEP130.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[54])) {
    __SET_VAR(data__->,STEP131.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[55])) {
    __SET_VAR(data__->,STEP135.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[56])) {
    __SET_VAR(data__->,STEP134.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[57])) {
    __SET_VAR(data__->,STEP136.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[58])) {
    __SET_VAR(data__->,STEP145.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[59])) {
    __SET_VAR(data__->,STEP138.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[60])) {
    __SET_VAR(data__->,STEP139.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[61])) {
    __SET_VAR(data__->,STEP143.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[62])) {
    __SET_VAR(data__->,STEP137.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[63])) {
    __SET_VAR(data__->,STEP140.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[64])) {
    __SET_VAR(data__->,STEP144.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[65])) {
    __SET_VAR(data__->,STEP141.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[66])) {
    __SET_VAR(data__->,STEP142.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[67])) {
    __SET_VAR(data__->,STEP146.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[68])) {
    __SET_VAR(data__->,STEP147.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[69])) {
    __SET_VAR(data__->,STEP148.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[70])) {
    __SET_VAR(data__->,STEP152.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[71])) {
    __SET_VAR(data__->,STEP153.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[72])) {
    __SET_VAR(data__->,STEP154.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[73])) {
    __SET_VAR(data__->,STEP156.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[74])) {
    __SET_VAR(data__->,STEP157.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[75])) {
    __SET_VAR(data__->,STEP150.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[76])) {
    __SET_VAR(data__->,STEP155.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[77])) {
    __SET_VAR(data__->,STEP158.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[78])) {
    __SET_VAR(data__->,STEP159.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[79])) {
    __SET_VAR(data__->,STEP160.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[80])) {
    __SET_VAR(data__->,STEP4.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP89.X,,1);
    data__->STEP89.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP86.X,,1);
    data__->STEP86.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP85.X,,1);
    data__->STEP85.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP84.X,,1);
    data__->STEP84.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP87.X,,1);
    data__->STEP87.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP90.X,,1);
    data__->STEP90.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP98.X,,1);
    data__->STEP98.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP92.X,,1);
    data__->STEP92.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP93.X,,1);
    data__->STEP93.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP99.X,,1);
    data__->STEP99.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP94.X,,1);
    data__->STEP94.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP95.X,,1);
    data__->STEP95.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP96.X,,1);
    data__->STEP96.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP97.X,,1);
    data__->STEP97.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP100.X,,1);
    data__->STEP100.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP101.X,,1);
    data__->STEP101.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP102.X,,1);
    data__->STEP102.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,MACHINETRANSFORM1.X,,1);
    data__->MACHINETRANSFORM1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP113.X,,1);
    data__->STEP113.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP112.X,,1);
    data__->STEP112.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP91.X,,1);
    data__->STEP91.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP88.X,,1);
    data__->STEP88.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP104.X,,1);
    data__->STEP104.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP106.X,,1);
    data__->STEP106.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP107.X,,1);
    data__->STEP107.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP108.X,,1);
    data__->STEP108.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP109.X,,1);
    data__->STEP109.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP110.X,,1);
    data__->STEP110.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP119.X,,1);
    data__->STEP119.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP111.X,,1);
    data__->STEP111.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP114.X,,1);
    data__->STEP114.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,STEP120.X,,1);
    data__->STEP120.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,STEP115.X,,1);
    data__->STEP115.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,STEP116.X,,1);
    data__->STEP116.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,STEP117.X,,1);
    data__->STEP117.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP3.X,,1);
    data__->STEP3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,STEP118.X,,1);
    data__->STEP118.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,STEP121.X,,1);
    data__->STEP121.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,STEP122.X,,1);
    data__->STEP122.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,STEP103.X,,1);
    data__->STEP103.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,STEP105.X,,1);
    data__->STEP105.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,STEP123.X,,1);
    data__->STEP123.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,STEP124.X,,1);
    data__->STEP124.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,STEP125.X,,1);
    data__->STEP125.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,MACHINETRANSFORM2.X,,1);
    data__->MACHINETRANSFORM2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,STEP133.X,,1);
    data__->STEP133.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,STEP132.X,,1);
    data__->STEP132.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,STEP127.X,,1);
    data__->STEP127.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,STEP126.X,,1);
    data__->STEP126.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[50])) {
    __SET_VAR(data__->,STEP128.X,,1);
    data__->STEP128.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[51])) {
    __SET_VAR(data__->,STEP129.X,,1);
    data__->STEP129.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[52])) {
    __SET_VAR(data__->,STEP130.X,,1);
    data__->STEP130.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[53])) {
    __SET_VAR(data__->,STEP131.X,,1);
    data__->STEP131.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[54])) {
    __SET_VAR(data__->,STEP135.X,,1);
    data__->STEP135.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[55])) {
    __SET_VAR(data__->,STEP134.X,,1);
    data__->STEP134.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[56])) {
    __SET_VAR(data__->,STEP136.X,,1);
    data__->STEP136.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[57])) {
    __SET_VAR(data__->,STEP145.X,,1);
    data__->STEP145.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[58])) {
    __SET_VAR(data__->,STEP138.X,,1);
    data__->STEP138.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[59])) {
    __SET_VAR(data__->,STEP139.X,,1);
    data__->STEP139.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[60])) {
    __SET_VAR(data__->,STEP143.X,,1);
    data__->STEP143.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[61])) {
    __SET_VAR(data__->,STEP137.X,,1);
    data__->STEP137.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[62])) {
    __SET_VAR(data__->,STEP140.X,,1);
    data__->STEP140.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[63])) {
    __SET_VAR(data__->,STEP144.X,,1);
    data__->STEP144.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[64])) {
    __SET_VAR(data__->,STEP141.X,,1);
    data__->STEP141.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[65])) {
    __SET_VAR(data__->,STEP142.X,,1);
    data__->STEP142.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[66])) {
    __SET_VAR(data__->,STEP146.X,,1);
    data__->STEP146.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP4.X,,1);
    data__->STEP4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[67])) {
    __SET_VAR(data__->,STEP147.X,,1);
    data__->STEP147.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[68])) {
    __SET_VAR(data__->,STEP148.X,,1);
    data__->STEP148.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[69])) {
    __SET_VAR(data__->,STEP152.X,,1);
    data__->STEP152.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[70])) {
    __SET_VAR(data__->,STEP153.X,,1);
    data__->STEP153.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[71])) {
    __SET_VAR(data__->,STEP154.X,,1);
    data__->STEP154.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[72])) {
    __SET_VAR(data__->,STEP156.X,,1);
    data__->STEP156.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[73])) {
    __SET_VAR(data__->,STEP157.X,,1);
    data__->STEP157.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[74])) {
    __SET_VAR(data__->,STEP150.X,,1);
    data__->STEP150.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[75])) {
    __SET_VAR(data__->,STEP155.X,,1);
    data__->STEP155.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[76])) {
    __SET_VAR(data__->,STEP158.X,,1);
    data__->STEP158.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[77])) {
    __SET_VAR(data__->,STEP159.X,,1);
    data__->STEP159.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[78])) {
    __SET_VAR(data__->,STEP160.X,,1);
    data__->STEP160.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[79])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[80])) {
    __SET_VAR(data__->,MACHINETRANSFORM3.X,,1);
    data__->MACHINETRANSFORM3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // MACHINETRANSFORM1 action associations
  {
    char active = __GET_VAR(data__->MACHINETRANSFORM1.X);
    char activated = active && !data__->MACHINETRANSFORM1.prev_state;
    char desactivated = !active && data__->MACHINETRANSFORM1.prev_state;

    if (active)       {data__->__action_list[__SFC_CELL1BUSY].reset = 1;}

  }

  // STEP89 action associations
  {
    char active = __GET_VAR(data__->STEP89.X);
    char activated = active && !data__->STEP89.prev_state;
    char desactivated = !active && data__->STEP89.prev_state;

    if (active)       {data__->__action_list[__SFC_RUNTRANSFORMMACH1].reset = 1;}

    if (active)       {data__->__action_list[__SFC_ACTION0].set = 1;}

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].set = 1;}

    if (active)       {data__->__action_list[__SFC_CELL1BUSY].set = 1;}

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SETPIECE1].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SETPIECE1].state,,0);};

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

  // STEP85 action associations
  {
    char active = __GET_VAR(data__->STEP85.X);
    char activated = active && !data__->STEP85.prev_state;
    char desactivated = !active && data__->STEP85.prev_state;

    if (active)       {data__->__action_list[__SFC_ACTION0].reset = 1;}

  }

  // STEP84 action associations
  {
    char active = __GET_VAR(data__->STEP84.X);
    char activated = active && !data__->STEP84.prev_state;
    char desactivated = !active && data__->STEP84.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SENDDOWNSAT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDDOWNSAT2_EX,,0);};

  }

  // STEP87 action associations
  {
    char active = __GET_VAR(data__->STEP87.X);
    char activated = active && !data__->STEP87.prev_state;
    char desactivated = !active && data__->STEP87.prev_state;

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].reset = 1;}

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

  // STEP96 action associations
  {
    char active = __GET_VAR(data__->STEP96.X);
    char activated = active && !data__->STEP96.prev_state;
    char desactivated = !active && data__->STEP96.prev_state;

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

  // MACHINETRANSFORM2 action associations
  {
    char active = __GET_VAR(data__->MACHINETRANSFORM2.X);
    char activated = active && !data__->MACHINETRANSFORM2.prev_state;
    char desactivated = !active && data__->MACHINETRANSFORM2.prev_state;

    if (active)       {data__->__action_list[__SFC_CELL2BUSY].reset = 1;}

  }

  // STEP113 action associations
  {
    char active = __GET_VAR(data__->STEP113.X);
    char activated = active && !data__->STEP113.prev_state;
    char desactivated = !active && data__->STEP113.prev_state;

    if (active)       {data__->__action_list[__SFC_RUNTRANSFORMMACH2].reset = 1;}

    if (active)       {data__->__action_list[__SFC_ACTION0].set = 1;}

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].set = 1;}

    if (active)       {data__->__action_list[__SFC_CELL2BUSY].set = 1;}

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SETPIECE2].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SETPIECE2].state,,0);};

  }

  // STEP112 action associations
  {
    char active = __GET_VAR(data__->STEP112.X);
    char activated = active && !data__->STEP112.prev_state;
    char desactivated = !active && data__->STEP112.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,0);};

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,0);};

  }

  // STEP91 action associations
  {
    char active = __GET_VAR(data__->STEP91.X);
    char activated = active && !data__->STEP91.prev_state;
    char desactivated = !active && data__->STEP91.prev_state;

    if (active)       {data__->__action_list[__SFC_ACTION0].reset = 1;}

  }

  // STEP88 action associations
  {
    char active = __GET_VAR(data__->STEP88.X);
    char activated = active && !data__->STEP88.prev_state;
    char desactivated = !active && data__->STEP88.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,0);};

  }

  // STEP104 action associations
  {
    char active = __GET_VAR(data__->STEP104.X);
    char activated = active && !data__->STEP104.prev_state;
    char desactivated = !active && data__->STEP104.prev_state;

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].reset = 1;}

  }

  // STEP106 action associations
  {
    char active = __GET_VAR(data__->STEP106.X);
    char activated = active && !data__->STEP106.prev_state;
    char desactivated = !active && data__->STEP106.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,0);};

  }

  // STEP108 action associations
  {
    char active = __GET_VAR(data__->STEP108.X);
    char activated = active && !data__->STEP108.prev_state;
    char desactivated = !active && data__->STEP108.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SENDDOWNSBT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDDOWNSBT2_EX,,0);};

  }

  // STEP110 action associations
  {
    char active = __GET_VAR(data__->STEP110.X);
    char activated = active && !data__->STEP110.prev_state;
    char desactivated = !active && data__->STEP110.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,TOOLPIECESBT3_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,TOOLPIECESBT3_EX,,0);};

  }

  // STEP111 action associations
  {
    char active = __GET_VAR(data__->STEP111.X);
    char activated = active && !data__->STEP111.prev_state;
    char desactivated = !active && data__->STEP111.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT4_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT4_EX,,0);};

  }

  // STEP114 action associations
  {
    char active = __GET_VAR(data__->STEP114.X);
    char activated = active && !data__->STEP114.prev_state;
    char desactivated = !active && data__->STEP114.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,TOOLPIECESBT5_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,TOOLPIECESBT5_EX,,0);};

  }

  // STEP115 action associations
  {
    char active = __GET_VAR(data__->STEP115.X);
    char activated = active && !data__->STEP115.prev_state;
    char desactivated = !active && data__->STEP115.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SENDLEFTDOWNSBT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDLEFTDOWNSBT6_EX,,0);};

  }

  // STEP117 action associations
  {
    char active = __GET_VAR(data__->STEP117.X);
    char activated = active && !data__->STEP117.prev_state;
    char desactivated = !active && data__->STEP117.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSBT7_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSBT7_EX,,0);};

  }

  // STEP118 action associations
  {
    char active = __GET_VAR(data__->STEP118.X);
    char activated = active && !data__->STEP118.prev_state;
    char desactivated = !active && data__->STEP118.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSAT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSAT6_EX,,0);};

  }

  // STEP121 action associations
  {
    char active = __GET_VAR(data__->STEP121.X);
    char activated = active && !data__->STEP121.prev_state;
    char desactivated = !active && data__->STEP121.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSAT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSAT6_EX,,0);};

  }

  // STEP122 action associations
  {
    char active = __GET_VAR(data__->STEP122.X);
    char activated = active && !data__->STEP122.prev_state;
    char desactivated = !active && data__->STEP122.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSAT7_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSAT7_EX,,0);};

  }

  // STEP103 action associations
  {
    char active = __GET_VAR(data__->STEP103.X);
    char activated = active && !data__->STEP103.prev_state;
    char desactivated = !active && data__->STEP103.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSAT7_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSAT7_EX,,0);};

  }

  // STEP105 action associations
  {
    char active = __GET_VAR(data__->STEP105.X);
    char activated = active && !data__->STEP105.prev_state;
    char desactivated = !active && data__->STEP105.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,PUTPIECEINSIGNAL_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,PUTPIECEINSIGNAL_EX,,0);};

  }

  // MACHINETRANSFORM3 action associations
  {
    char active = __GET_VAR(data__->MACHINETRANSFORM3.X);
    char activated = active && !data__->MACHINETRANSFORM3.prev_state;
    char desactivated = !active && data__->MACHINETRANSFORM3.prev_state;

    if (active)       {data__->__action_list[__SFC_CELL3BUSY].reset = 1;}

  }

  // STEP133 action associations
  {
    char active = __GET_VAR(data__->STEP133.X);
    char activated = active && !data__->STEP133.prev_state;
    char desactivated = !active && data__->STEP133.prev_state;

    if (active)       {data__->__action_list[__SFC_ACTION0].set = 1;}

    if (active)       {data__->__action_list[__SFC_RUNTRANSFORMMACH3].reset = 1;}

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].set = 1;}

    if (active)       {data__->__action_list[__SFC_CELL3BUSY].set = 1;}

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_SETPIECE3].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_SETPIECE3].state,,0);};

  }

  // STEP132 action associations
  {
    char active = __GET_VAR(data__->STEP132.X);
    char activated = active && !data__->STEP132.prev_state;
    char desactivated = !active && data__->STEP132.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,0);};

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,0);};

  }

  // STEP127 action associations
  {
    char active = __GET_VAR(data__->STEP127.X);
    char activated = active && !data__->STEP127.prev_state;
    char desactivated = !active && data__->STEP127.prev_state;

    if (active)       {data__->__action_list[__SFC_ACTION0].reset = 1;}

  }

  // STEP126 action associations
  {
    char active = __GET_VAR(data__->STEP126.X);
    char activated = active && !data__->STEP126.prev_state;
    char desactivated = !active && data__->STEP126.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,0);};

  }

  // STEP128 action associations
  {
    char active = __GET_VAR(data__->STEP128.X);
    char activated = active && !data__->STEP128.prev_state;
    char desactivated = !active && data__->STEP128.prev_state;

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].reset = 1;}

  }

  // STEP129 action associations
  {
    char active = __GET_VAR(data__->STEP129.X);
    char activated = active && !data__->STEP129.prev_state;
    char desactivated = !active && data__->STEP129.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,0);};

  }

  // STEP131 action associations
  {
    char active = __GET_VAR(data__->STEP131.X);
    char activated = active && !data__->STEP131.prev_state;
    char desactivated = !active && data__->STEP131.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,0);};

  }

  // STEP134 action associations
  {
    char active = __GET_VAR(data__->STEP134.X);
    char activated = active && !data__->STEP134.prev_state;
    char desactivated = !active && data__->STEP134.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,0);};

  }

  // STEP145 action associations
  {
    char active = __GET_VAR(data__->STEP145.X);
    char activated = active && !data__->STEP145.prev_state;
    char desactivated = !active && data__->STEP145.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SENDDOWNSCT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDDOWNSCT2_EX,,0);};

  }

  // STEP139 action associations
  {
    char active = __GET_VAR(data__->STEP139.X);
    char activated = active && !data__->STEP139.prev_state;
    char desactivated = !active && data__->STEP139.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,TOOLPIECESCT3_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,TOOLPIECESCT3_EX,,0);};

  }

  // STEP137 action associations
  {
    char active = __GET_VAR(data__->STEP137.X);
    char activated = active && !data__->STEP137.prev_state;
    char desactivated = !active && data__->STEP137.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSCT4_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSCT4_EX,,0);};

  }

  // STEP140 action associations
  {
    char active = __GET_VAR(data__->STEP140.X);
    char activated = active && !data__->STEP140.prev_state;
    char desactivated = !active && data__->STEP140.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,TOOLPIECESCT5_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,TOOLPIECESCT5_EX,,0);};

  }

  // STEP141 action associations
  {
    char active = __GET_VAR(data__->STEP141.X);
    char activated = active && !data__->STEP141.prev_state;
    char desactivated = !active && data__->STEP141.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SENDLEFTDOWNSCT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDLEFTDOWNSCT6_EX,,0);};

  }

  // STEP146 action associations
  {
    char active = __GET_VAR(data__->STEP146.X);
    char activated = active && !data__->STEP146.prev_state;
    char desactivated = !active && data__->STEP146.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSCT7_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSCT7_EX,,0);};

  }

  // STEP147 action associations
  {
    char active = __GET_VAR(data__->STEP147.X);
    char activated = active && !data__->STEP147.prev_state;
    char desactivated = !active && data__->STEP147.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSBT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSBT6_EX,,0);};

  }

  // STEP148 action associations
  {
    char active = __GET_VAR(data__->STEP148.X);
    char activated = active && !data__->STEP148.prev_state;
    char desactivated = !active && data__->STEP148.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSBT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSBT6_EX,,0);};

  }

  // STEP152 action associations
  {
    char active = __GET_VAR(data__->STEP152.X);
    char activated = active && !data__->STEP152.prev_state;
    char desactivated = !active && data__->STEP152.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSBT7_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSBT7_EX,,0);};

  }

  // STEP153 action associations
  {
    char active = __GET_VAR(data__->STEP153.X);
    char activated = active && !data__->STEP153.prev_state;
    char desactivated = !active && data__->STEP153.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSBT7_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSBT7_EX,,0);};

  }

  // STEP154 action associations
  {
    char active = __GET_VAR(data__->STEP154.X);
    char activated = active && !data__->STEP154.prev_state;
    char desactivated = !active && data__->STEP154.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSAT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSAT6_EX,,0);};

  }

  // STEP156 action associations
  {
    char active = __GET_VAR(data__->STEP156.X);
    char activated = active && !data__->STEP156.prev_state;
    char desactivated = !active && data__->STEP156.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSAT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSAT6_EX,,0);};

  }

  // STEP157 action associations
  {
    char active = __GET_VAR(data__->STEP157.X);
    char activated = active && !data__->STEP157.prev_state;
    char desactivated = !active && data__->STEP157.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSAT7_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSAT7_EX,,0);};

  }

  // STEP150 action associations
  {
    char active = __GET_VAR(data__->STEP150.X);
    char activated = active && !data__->STEP150.prev_state;
    char desactivated = !active && data__->STEP150.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSAT7_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSAT7_EX,,0);};

  }

  // STEP155 action associations
  {
    char active = __GET_VAR(data__->STEP155.X);
    char activated = active && !data__->STEP155.prev_state;
    char desactivated = !active && data__->STEP155.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,PUTPIECEINSIGNAL_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,PUTPIECEINSIGNAL_EX,,0);};

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
  if (data__->__action_list[__SFC_CELL1BUSY].reset) {
    __SET_LOCATED(data__->,CELL1BUSY,,0);
  }
  else if (data__->__action_list[__SFC_CELL1BUSY].set) {
    __SET_LOCATED(data__->,CELL1BUSY,,1);
  }
  if (data__->__action_list[__SFC_RUNTRANSFORMMACH1].reset) {
    __SET_LOCATED(data__->,RUNTRANSFORMMACH1,,0);
  }
  else if (data__->__action_list[__SFC_RUNTRANSFORMMACH1].set) {
    __SET_LOCATED(data__->,RUNTRANSFORMMACH1,,1);
  }
  if (data__->__action_list[__SFC_WAREHOUSEBUSY].reset) {
    __SET_LOCATED(data__->,WAREHOUSEBUSY,,0);
  }
  else if (data__->__action_list[__SFC_WAREHOUSEBUSY].set) {
    __SET_LOCATED(data__->,WAREHOUSEBUSY,,1);
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
  if (data__->__action_list[__SFC_CELL2BUSY].reset) {
    __SET_LOCATED(data__->,CELL2BUSY,,0);
  }
  else if (data__->__action_list[__SFC_CELL2BUSY].set) {
    __SET_LOCATED(data__->,CELL2BUSY,,1);
  }
  if (data__->__action_list[__SFC_RUNTRANSFORMMACH2].reset) {
    __SET_LOCATED(data__->,RUNTRANSFORMMACH2,,0);
  }
  else if (data__->__action_list[__SFC_RUNTRANSFORMMACH2].set) {
    __SET_LOCATED(data__->,RUNTRANSFORMMACH2,,1);
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
  if (data__->__action_list[__SFC_SENDDOWNSBT2_EX].reset) {
    __SET_EXTERNAL(data__->,SENDDOWNSBT2_EX,,0);
  }
  else if (data__->__action_list[__SFC_SENDDOWNSBT2_EX].set) {
    __SET_EXTERNAL(data__->,SENDDOWNSBT2_EX,,1);
  }
  if (data__->__action_list[__SFC_TOOLPIECESBT3_EX].reset) {
    __SET_EXTERNAL(data__->,TOOLPIECESBT3_EX,,0);
  }
  else if (data__->__action_list[__SFC_TOOLPIECESBT3_EX].set) {
    __SET_EXTERNAL(data__->,TOOLPIECESBT3_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTSBT4_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTSBT4_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTSBT4_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTSBT4_EX,,1);
  }
  if (data__->__action_list[__SFC_TOOLPIECESBT5_EX].reset) {
    __SET_EXTERNAL(data__->,TOOLPIECESBT5_EX,,0);
  }
  else if (data__->__action_list[__SFC_TOOLPIECESBT5_EX].set) {
    __SET_EXTERNAL(data__->,TOOLPIECESBT5_EX,,1);
  }
  if (data__->__action_list[__SFC_SENDLEFTDOWNSBT6_EX].reset) {
    __SET_EXTERNAL(data__->,SENDLEFTDOWNSBT6_EX,,0);
  }
  else if (data__->__action_list[__SFC_SENDLEFTDOWNSBT6_EX].set) {
    __SET_EXTERNAL(data__->,SENDLEFTDOWNSBT6_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNBACKSBT7_EX].reset) {
    __SET_EXTERNAL(data__->,RUNBACKSBT7_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNBACKSBT7_EX].set) {
    __SET_EXTERNAL(data__->,RUNBACKSBT7_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNBACKSAT6_EX].reset) {
    __SET_EXTERNAL(data__->,RUNBACKSAT6_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNBACKSAT6_EX].set) {
    __SET_EXTERNAL(data__->,RUNBACKSAT6_EX,,1);
  }
  if (data__->__action_list[__SFC_CELL3BUSY].reset) {
    __SET_LOCATED(data__->,CELL3BUSY,,0);
  }
  else if (data__->__action_list[__SFC_CELL3BUSY].set) {
    __SET_LOCATED(data__->,CELL3BUSY,,1);
  }
  if (data__->__action_list[__SFC_RUNTRANSFORMMACH3].reset) {
    __SET_LOCATED(data__->,RUNTRANSFORMMACH3,,0);
  }
  else if (data__->__action_list[__SFC_RUNTRANSFORMMACH3].set) {
    __SET_LOCATED(data__->,RUNTRANSFORMMACH3,,1);
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
  if (data__->__action_list[__SFC_SENDDOWNSCT2_EX].reset) {
    __SET_EXTERNAL(data__->,SENDDOWNSCT2_EX,,0);
  }
  else if (data__->__action_list[__SFC_SENDDOWNSCT2_EX].set) {
    __SET_EXTERNAL(data__->,SENDDOWNSCT2_EX,,1);
  }
  if (data__->__action_list[__SFC_TOOLPIECESCT3_EX].reset) {
    __SET_EXTERNAL(data__->,TOOLPIECESCT3_EX,,0);
  }
  else if (data__->__action_list[__SFC_TOOLPIECESCT3_EX].set) {
    __SET_EXTERNAL(data__->,TOOLPIECESCT3_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTSCT4_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTSCT4_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTSCT4_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTSCT4_EX,,1);
  }
  if (data__->__action_list[__SFC_TOOLPIECESCT5_EX].reset) {
    __SET_EXTERNAL(data__->,TOOLPIECESCT5_EX,,0);
  }
  else if (data__->__action_list[__SFC_TOOLPIECESCT5_EX].set) {
    __SET_EXTERNAL(data__->,TOOLPIECESCT5_EX,,1);
  }
  if (data__->__action_list[__SFC_SENDLEFTDOWNSCT6_EX].reset) {
    __SET_EXTERNAL(data__->,SENDLEFTDOWNSCT6_EX,,0);
  }
  else if (data__->__action_list[__SFC_SENDLEFTDOWNSCT6_EX].set) {
    __SET_EXTERNAL(data__->,SENDLEFTDOWNSCT6_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNBACKSCT7_EX].reset) {
    __SET_EXTERNAL(data__->,RUNBACKSCT7_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNBACKSCT7_EX].set) {
    __SET_EXTERNAL(data__->,RUNBACKSCT7_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNBACKSBT6_EX].reset) {
    __SET_EXTERNAL(data__->,RUNBACKSBT6_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNBACKSBT6_EX].set) {
    __SET_EXTERNAL(data__->,RUNBACKSBT6_EX,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_ACTION0].state)) {
    __SET_VAR(data__->REMOVEFROMWAREHOUSE0.,PIECENUM,,__GET_LOCATED(data__->INITIALPIECE,));
    __SET_VAR(data__->REMOVEFROMWAREHOUSE0.,SENSORAT1,,__GET_LOCATED(data__->SENSORAT1,));
    REMOVEFROMWAREHOUSE_body__(&data__->REMOVEFROMWAREHOUSE0);
    __SET_LOCATED(data__->,WAREHOUSEIN,,__GET_VAR(data__->REMOVEFROMWAREHOUSE0.WAREHOUSEIN,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_SETPIECE1].state)) {
    __SET_EXTERNAL(data__->,CELL1INITIAL,,__GET_LOCATED(data__->INITIALPIECE,));
    __SET_EXTERNAL(data__->,CELL1FINAL,,__GET_LOCATED(data__->FINALPIECE,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_SETPIECE2].state)) {
    __SET_EXTERNAL(data__->,CELL2INITIAL,,__GET_LOCATED(data__->INITIALPIECE,));
    __SET_EXTERNAL(data__->,CELL2FINAL,,__GET_LOCATED(data__->FINALPIECE,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_SETPIECE3].state)) {
    __SET_EXTERNAL(data__->,CELL3INITIAL,,__GET_LOCATED(data__->INITIALPIECE,));
    __SET_EXTERNAL(data__->,CELL3FINAL,,__GET_LOCATED(data__->FINALPIECE,));
  }



  goto __end;

__end:
  return;
} // TRANSFORMPROGRAM_body__() 

// Steps undefinitions
#undef MACHINETRANSFORM1
#undef __SFC_MACHINETRANSFORM1
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
#undef STEP0
#undef __SFC_STEP0
#undef STEP2
#undef __SFC_STEP2
#undef MACHINETRANSFORM2
#undef __SFC_MACHINETRANSFORM2
#undef STEP113
#undef __SFC_STEP113
#undef STEP112
#undef __SFC_STEP112
#undef STEP91
#undef __SFC_STEP91
#undef STEP88
#undef __SFC_STEP88
#undef STEP104
#undef __SFC_STEP104
#undef STEP106
#undef __SFC_STEP106
#undef STEP107
#undef __SFC_STEP107
#undef STEP108
#undef __SFC_STEP108
#undef STEP109
#undef __SFC_STEP109
#undef STEP110
#undef __SFC_STEP110
#undef STEP119
#undef __SFC_STEP119
#undef STEP111
#undef __SFC_STEP111
#undef STEP114
#undef __SFC_STEP114
#undef STEP120
#undef __SFC_STEP120
#undef STEP115
#undef __SFC_STEP115
#undef STEP116
#undef __SFC_STEP116
#undef STEP117
#undef __SFC_STEP117
#undef STEP118
#undef __SFC_STEP118
#undef STEP121
#undef __SFC_STEP121
#undef STEP122
#undef __SFC_STEP122
#undef STEP103
#undef __SFC_STEP103
#undef STEP105
#undef __SFC_STEP105
#undef STEP123
#undef __SFC_STEP123
#undef STEP124
#undef __SFC_STEP124
#undef STEP125
#undef __SFC_STEP125
#undef STEP3
#undef __SFC_STEP3
#undef MACHINETRANSFORM3
#undef __SFC_MACHINETRANSFORM3
#undef STEP133
#undef __SFC_STEP133
#undef STEP132
#undef __SFC_STEP132
#undef STEP127
#undef __SFC_STEP127
#undef STEP126
#undef __SFC_STEP126
#undef STEP128
#undef __SFC_STEP128
#undef STEP129
#undef __SFC_STEP129
#undef STEP130
#undef __SFC_STEP130
#undef STEP131
#undef __SFC_STEP131
#undef STEP135
#undef __SFC_STEP135
#undef STEP134
#undef __SFC_STEP134
#undef STEP136
#undef __SFC_STEP136
#undef STEP145
#undef __SFC_STEP145
#undef STEP138
#undef __SFC_STEP138
#undef STEP139
#undef __SFC_STEP139
#undef STEP143
#undef __SFC_STEP143
#undef STEP137
#undef __SFC_STEP137
#undef STEP140
#undef __SFC_STEP140
#undef STEP144
#undef __SFC_STEP144
#undef STEP141
#undef __SFC_STEP141
#undef STEP142
#undef __SFC_STEP142
#undef STEP146
#undef __SFC_STEP146
#undef STEP147
#undef __SFC_STEP147
#undef STEP148
#undef __SFC_STEP148
#undef STEP152
#undef __SFC_STEP152
#undef STEP153
#undef __SFC_STEP153
#undef STEP154
#undef __SFC_STEP154
#undef STEP156
#undef __SFC_STEP156
#undef STEP157
#undef __SFC_STEP157
#undef STEP150
#undef __SFC_STEP150
#undef STEP155
#undef __SFC_STEP155
#undef STEP158
#undef __SFC_STEP158
#undef STEP159
#undef __SFC_STEP159
#undef STEP160
#undef __SFC_STEP160
#undef STEP4
#undef __SFC_STEP4

// Actions undefinitions
#undef __SFC_ACTION0
#undef __SFC_SETPIECE1
#undef __SFC_SETPIECE2
#undef __SFC_SETPIECE3
#undef __SFC_CELL1BUSY
#undef __SFC_RUNTRANSFORMMACH1
#undef __SFC_WAREHOUSEBUSY
#undef __SFC_RUNFRONTSAT1_EX
#undef __SFC_RUNFRONTAT1_EX
#undef __SFC_SENDDOWNSAT2_EX
#undef __SFC_TOOLPIECESAT3_EX
#undef __SFC_RUNFRONTSAT4_EX
#undef __SFC_TOOLPIECESAT5_EX
#undef __SFC_SENDLEFTDOWNSAT6_EX
#undef __SFC_RUNBACKSAT7_EX
#undef __SFC_PUTPIECEINSIGNAL_EX
#undef __SFC_CELL2BUSY
#undef __SFC_RUNTRANSFORMMACH2
#undef __SFC_RUNFRONTSAT2_EX
#undef __SFC_RUNFRONTSBT1_EX
#undef __SFC_SENDDOWNSBT2_EX
#undef __SFC_TOOLPIECESBT3_EX
#undef __SFC_RUNFRONTSBT4_EX
#undef __SFC_TOOLPIECESBT5_EX
#undef __SFC_SENDLEFTDOWNSBT6_EX
#undef __SFC_RUNBACKSBT7_EX
#undef __SFC_RUNBACKSAT6_EX
#undef __SFC_CELL3BUSY
#undef __SFC_RUNTRANSFORMMACH3
#undef __SFC_RUNFRONTSBT2_EX
#undef __SFC_RUNFRONTSCT1_EX
#undef __SFC_SENDDOWNSCT2_EX
#undef __SFC_TOOLPIECESCT3_EX
#undef __SFC_RUNFRONTSCT4_EX
#undef __SFC_TOOLPIECESCT5_EX
#undef __SFC_SENDLEFTDOWNSCT6_EX
#undef __SFC_RUNBACKSCT7_EX
#undef __SFC_RUNBACKSBT6_EX





void GANTRYPROGRAMGOOD_init__(GANTRYPROGRAMGOOD *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,SENSORCT6_EX,data__->SENSORCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RECEIVEPIECEMT1_EX,data__->RECEIVEPIECEMT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RECEIVEPIECEMT2_EX,data__->RECEIVEPIECEMT2_EX,retain)
  __INIT_LOCATED(BOOL,__IX0_1_0_8,data__->MOUNT,retain)
  __INIT_LOCATED_VALUE(data__->MOUNT,__BOOL_LITERAL(FALSE))
  __INIT_EXTERNAL(BOOL,GANTRYBUSY_EX,data__->GANTRYBUSY_EX,retain)
  __INIT_EXTERNAL(BOOL,PICKPIECE_EX,data__->PICKPIECE_EX,retain)
  __INIT_EXTERNAL(BOOL,RELEASEPIECE_EX,data__->RELEASEPIECE_EX,retain)
  __INIT_EXTERNAL(BOOL,X0Y0_EX,data__->X0Y0_EX,retain)
  __INIT_EXTERNAL(BOOL,X0Y1_EX,data__->X0Y1_EX,retain)
  __INIT_EXTERNAL(BOOL,X0Y2_EX,data__->X0Y2_EX,retain)
  __INIT_EXTERNAL(BOOL,X0Y3_EX,data__->X0Y3_EX,retain)
  __INIT_EXTERNAL(BOOL,X0Y4_EX,data__->X0Y4_EX,retain)
  __INIT_EXTERNAL(BOOL,X1Y0_EX,data__->X1Y0_EX,retain)
  __INIT_EXTERNAL(BOOL,X1Y1_EX,data__->X1Y1_EX,retain)
  __INIT_EXTERNAL(BOOL,X1Y2_EX,data__->X1Y2_EX,retain)
  __INIT_EXTERNAL(BOOL,X1Y3_EX,data__->X1Y3_EX,retain)
  __INIT_EXTERNAL(BOOL,X1Y4_EX,data__->X1Y4_EX,retain)
  __INIT_LOCATED(INT,__IW0_0_2_0,data__->WAREHOUSEIN,retain)
  __INIT_LOCATED_VALUE(data__->WAREHOUSEIN,0)
  __INIT_LOCATED(BOOL,__IX0_0_0_0,data__->SENSORAT1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(INT,__IW0_1_1_2,data__->PM,retain)
  __INIT_LOCATED_VALUE(data__->PM,0)
  __INIT_LOCATED(INT,__IW0_1_1_5,data__->BOTTOMPIECE,retain)
  __INIT_LOCATED_VALUE(data__->BOTTOMPIECE,0)
  __INIT_LOCATED(INT,__IW0_1_1_1,data__->TOPPIECE,retain)
  __INIT_LOCATED_VALUE(data__->TOPPIECE,0)
  __INIT_VAR(data__->PIECETOUNLOAD,0,retain)
  __INIT_LOCATED(BOOL,__QX0_1_0_0,data__->WAREHOUSEBUSY,retain)
  __INIT_LOCATED_VALUE(data__->WAREHOUSEBUSY,__BOOL_LITERAL(FALSE))
  __INIT_EXTERNAL(BOOL,RUNFRONTAT1_EX,data__->RUNFRONTAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT1_EX,data__->RUNFRONTSAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT2_EX,data__->RUNFRONTSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT4_EX,data__->RUNFRONTSAT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT1_EX,data__->RUNFRONTSBT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT2_EX,data__->RUNFRONTSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT4_EX,data__->RUNFRONTSBT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT1_EX,data__->RUNFRONTSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT2_EX,data__->RUNFRONTSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT4_EX,data__->RUNFRONTSCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT1_EX,data__->RUNFRONTMT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT2_EX,data__->RUNFRONTMT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT1_EX,data__->RUNFRONTCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT4_EX,data__->RUNFRONTCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT5_EX,data__->RUNFRONTCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSAT7_EX,data__->RUNBACKSAT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSCT7_EX,data__->RUNBACKSCT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSBT7_EX,data__->RUNBACKSBT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSBT6_EX,data__->RUNBACKSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSAT6_EX,data__->RUNBACKSAT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSAT2_EX,data__->SENDDOWNSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSBT2_EX,data__->SENDDOWNSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSCT2_EX,data__->SENDDOWNSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESAT3_EX,data__->TOOLPIECESAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESAT5_EX,data__->TOOLPIECESAT5_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESBT3_EX,data__->TOOLPIECESBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESBT5_EX,data__->TOOLPIECESBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESCT3_EX,data__->TOOLPIECESCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESCT5_EX,data__->TOOLPIECESCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNCT2_EX,data__->SENDDOWNCT2_EX,retain)
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
  __INIT_EXTERNAL(BOOL,SENSORSBT3_EX,data__->SENSORSBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT4_EX,data__->SENSORSBT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT5_EX,data__->SENSORSBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT6_EX,data__->SENSORSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT7_EX,data__->SENSORSBT7_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT1_EX,data__->SENSORSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT2_EX,data__->SENSORSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT3_EX,data__->SENSORSCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT4_EX,data__->SENSORSCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT5_EX,data__->SENSORSCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT6_EX,data__->SENSORSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT7_EX,data__->SENSORSCT7_EX,retain)
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
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNSBT6_EX,data__->SENDLEFTDOWNSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNSCT6_EX,data__->SENDLEFTDOWNSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,PUTPIECEINSIGNAL_EX,data__->PUTPIECEINSIGNAL_EX,retain)
  REMOVEFROMWAREHOUSE_init__(&data__->REMOVEFROMWAREHOUSE0,retain);
  __INIT_LOCATED(BOOL,__IX0_1_0_1,data__->RUNUNLOAD,retain)
  __INIT_LOCATED_VALUE(data__->RUNUNLOAD,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1_0_2,data__->RUNTRANSFORMMACH1,retain)
  __INIT_LOCATED_VALUE(data__->RUNTRANSFORMMACH1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1_0_3,data__->RUNTRANSFORMMACH2,retain)
  __INIT_LOCATED_VALUE(data__->RUNTRANSFORMMACH2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1_0_4,data__->RUNTRANSFORMMACH3,retain)
  __INIT_LOCATED_VALUE(data__->RUNTRANSFORMMACH3,__BOOL_LITERAL(FALSE))
  __INIT_EXTERNAL(BOOL,READYTOSENDSAT3_EX,data__->READYTOSENDSAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSAT5_EX,data__->READYTOSENDSAT5_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSBT3_EX,data__->READYTOSENDSBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSBT5_EX,data__->READYTOSENDSBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSCT3_EX,data__->READYTOSENDSCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSCT5_EX,data__->READYTOSENDSCT5_EX,retain)
  UINT i;
  data__->__nb_steps = 54;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 24;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 53;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define STEP9 __step_list[0]
#define __SFC_STEP9 0
#define STEP30 __step_list[1]
#define __SFC_STEP30 1
#define STEP12 __step_list[2]
#define __SFC_STEP12 2
#define STEP11 __step_list[3]
#define __SFC_STEP11 3
#define STEP10 __step_list[4]
#define __SFC_STEP10 4
#define STEP13 __step_list[5]
#define __SFC_STEP13 5
#define STEP15 __step_list[6]
#define __SFC_STEP15 6
#define STEP16 __step_list[7]
#define __SFC_STEP16 7
#define STEP17 __step_list[8]
#define __SFC_STEP17 8
#define STEP18 __step_list[9]
#define __SFC_STEP18 9
#define STEP19 __step_list[10]
#define __SFC_STEP19 10
#define STEP20 __step_list[11]
#define __SFC_STEP20 11
#define STEP21 __step_list[12]
#define __SFC_STEP21 12
#define STEP22 __step_list[13]
#define __SFC_STEP22 13
#define STEP23 __step_list[14]
#define __SFC_STEP23 14
#define STEP24 __step_list[15]
#define __SFC_STEP24 15
#define STEP25 __step_list[16]
#define __SFC_STEP25 16
#define STEP26 __step_list[17]
#define __SFC_STEP26 17
#define STEP39 __step_list[18]
#define __SFC_STEP39 18
#define STEP1 __step_list[19]
#define __SFC_STEP1 19
#define STEP2 __step_list[20]
#define __SFC_STEP2 20
#define STEP3 __step_list[21]
#define __SFC_STEP3 21
#define STEP4 __step_list[22]
#define __SFC_STEP4 22
#define STEP5 __step_list[23]
#define __SFC_STEP5 23
#define STEP7 __step_list[24]
#define __SFC_STEP7 24
#define STEP8 __step_list[25]
#define __SFC_STEP8 25
#define STEP0 __step_list[26]
#define __SFC_STEP0 26
#define STEP6 __step_list[27]
#define __SFC_STEP6 27
#define STEP27 __step_list[28]
#define __SFC_STEP27 28
#define STEP46 __step_list[29]
#define __SFC_STEP46 29
#define STEP47 __step_list[30]
#define __SFC_STEP47 30
#define STEP48 __step_list[31]
#define __SFC_STEP48 31
#define STEP49 __step_list[32]
#define __SFC_STEP49 32
#define STEP50 __step_list[33]
#define __SFC_STEP50 33
#define STEP51 __step_list[34]
#define __SFC_STEP51 34
#define STEP52 __step_list[35]
#define __SFC_STEP52 35
#define STEP14 __step_list[36]
#define __SFC_STEP14 36
#define SENDTOP __step_list[37]
#define __SFC_SENDTOP 37
#define STEP28 __step_list[38]
#define __SFC_STEP28 38
#define STEP42 __step_list[39]
#define __SFC_STEP42 39
#define STEP41 __step_list[40]
#define __SFC_STEP41 40
#define STEP43 __step_list[41]
#define __SFC_STEP43 41
#define STEP45 __step_list[42]
#define __SFC_STEP45 42
#define STEP29 __step_list[43]
#define __SFC_STEP29 43
#define STEP31 __step_list[44]
#define __SFC_STEP31 44
#define STEP32 __step_list[45]
#define __SFC_STEP32 45
#define STEP33 __step_list[46]
#define __SFC_STEP33 46
#define STEP34 __step_list[47]
#define __SFC_STEP34 47
#define STEP35 __step_list[48]
#define __SFC_STEP35 48
#define STEP36 __step_list[49]
#define __SFC_STEP36 49
#define STEP37 __step_list[50]
#define __SFC_STEP37 50
#define STEP38 __step_list[51]
#define __SFC_STEP38 51
#define STEP40 __step_list[52]
#define __SFC_STEP40 52
#define STEP44 __step_list[53]
#define __SFC_STEP44 53

// Actions definitions
#define __SFC_ACTION0 0
#define __SFC_UNLOADBOTTOM 1
#define __SFC_UNLOADTOP 2
#define __SFC_WAREHOUSEBUSY 3
#define __SFC_MOUNT 4
#define __SFC_RUNFRONTSAT1_EX 5
#define __SFC_RUNFRONTAT1_EX 6
#define __SFC_RUNFRONTSAT2_EX 7
#define __SFC_RUNFRONTSBT1_EX 8
#define __SFC_RUNFRONTSBT2_EX 9
#define __SFC_RUNFRONTSCT1_EX 10
#define __SFC_RUNFRONTSCT2_EX 11
#define __SFC_RUNFRONTMT1_EX 12
#define __SFC_RECEIVEPIECEMT2_EX 13
#define __SFC_X1Y0_EX 14
#define __SFC_PICKPIECE_EX 15
#define __SFC_RELEASEPIECE_EX 16
#define __SFC_RUNFRONTMT2_EX 17
#define __SFC_RUNFRONTCT1_EX 18
#define __SFC_SENDDOWNCT2_EX 19
#define __SFC_RUNFRONTCT4_EX 20
#define __SFC_RUNFRONTCT5_EX 21
#define __SFC_PUSHTOROLLCT6_EX 22
#define __SFC_RECEIVEPIECEMT1_EX 23

// Code part
void GANTRYPROGRAMGOOD_body__(GANTRYPROGRAMGOOD *data__) {
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
  if (__GET_VAR(data__->STEP9.X)) {
    __SET_VAR(data__->,__transition_list[0],,(__GET_LOCATED(data__->MOUNT,) && !(__GET_LOCATED(data__->WAREHOUSEBUSY,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,(__GET_LOCATED(data__->MOUNT,) && !(__GET_LOCATED(data__->WAREHOUSEBUSY,))));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->STEP30.X)) {
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
  if (__GET_VAR(data__->STEP12.X)) {
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
  if (__GET_VAR(data__->STEP11.X)) {
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
  if (__GET_VAR(data__->STEP10.X)) {
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
  if (__GET_VAR(data__->STEP13.X)) {
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
  if (__GET_VAR(data__->STEP15.X)) {
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
  if (__GET_VAR(data__->STEP16.X)) {
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
  if (__GET_VAR(data__->STEP17.X)) {
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
  if (__GET_VAR(data__->STEP18.X)) {
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
  if (__GET_VAR(data__->STEP19.X)) {
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
  if (__GET_VAR(data__->STEP20.X)) {
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
  if (__GET_VAR(data__->STEP21.X)) {
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
  if (__GET_VAR(data__->STEP22.X)) {
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
  if (__GET_VAR(data__->STEP23.X)) {
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
  if (__GET_VAR(data__->STEP24.X)) {
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
  if (__GET_VAR(data__->STEP25.X)) {
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
  if (__GET_VAR(data__->STEP26.X)) {
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
  if (__GET_VAR(data__->STEP39.X) && __GET_VAR(data__->STEP40.X)) {
    __SET_VAR(data__->,__transition_list[18],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
    __SET_VAR(data__->,__transition_list[19],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->STEP2.X)) {
    __SET_VAR(data__->,__transition_list[20],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->STEP3.X)) {
    __SET_VAR(data__->,__transition_list[21],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->STEP4.X)) {
    __SET_VAR(data__->,__transition_list[22],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->STEP5.X)) {
    __SET_VAR(data__->,__transition_list[23],,__GET_EXTERNAL(data__->SENSORMT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_EXTERNAL(data__->SENSORMT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->STEP7.X)) {
    __SET_VAR(data__->,__transition_list[24],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->STEP8.X)) {
    __SET_VAR(data__->,__transition_list[25],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->STEP0.X)) {
    __SET_VAR(data__->,__transition_list[26],,__GET_EXTERNAL(data__->SENSORCT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_EXTERNAL(data__->SENSORCT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->STEP6.X)) {
    __SET_VAR(data__->,__transition_list[27],,!(__GET_EXTERNAL(data__->SENSORCT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,!(__GET_EXTERNAL(data__->SENSORCT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->STEP27.X)) {
    __SET_VAR(data__->,__transition_list[28],,__GET_EXTERNAL(data__->SENSORCT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_EXTERNAL(data__->SENSORCT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->STEP46.X)) {
    __SET_VAR(data__->,__transition_list[29],,!(__GET_EXTERNAL(data__->SENSORCT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,!(__GET_EXTERNAL(data__->SENSORCT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->STEP47.X)) {
    __SET_VAR(data__->,__transition_list[30],,__GET_EXTERNAL(data__->SENSORCT4_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_EXTERNAL(data__->SENSORCT4_EX,));
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->STEP48.X)) {
    __SET_VAR(data__->,__transition_list[31],,!(__GET_EXTERNAL(data__->SENSORCT4_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,!(__GET_EXTERNAL(data__->SENSORCT4_EX,)));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }
  if (__GET_VAR(data__->STEP49.X)) {
    __SET_VAR(data__->,__transition_list[32],,__GET_EXTERNAL(data__->SENSORCT5_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->__transition_list[32]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_EXTERNAL(data__->SENSORCT5_EX,));
    }
    __SET_VAR(data__->,__transition_list[32],,0);
  }
  if (__GET_VAR(data__->STEP50.X)) {
    __SET_VAR(data__->,__transition_list[33],,!(__GET_EXTERNAL(data__->SENSORCT5_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->__transition_list[33]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,!(__GET_EXTERNAL(data__->SENSORCT5_EX,)));
    }
    __SET_VAR(data__->,__transition_list[33],,0);
  }
  if (__GET_VAR(data__->STEP51.X)) {
    __SET_VAR(data__->,__transition_list[34],,__GET_EXTERNAL(data__->SENSORCT6_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_VAR(data__->__transition_list[34]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_EXTERNAL(data__->SENSORCT6_EX,));
    }
    __SET_VAR(data__->,__transition_list[34],,0);
  }
  if (__GET_VAR(data__->STEP52.X)) {
    __SET_VAR(data__->,__transition_list[35],,!(__GET_EXTERNAL(data__->SENSORCT6_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->__transition_list[35]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,!(__GET_EXTERNAL(data__->SENSORCT6_EX,)));
    }
    __SET_VAR(data__->,__transition_list[35],,0);
  }
  if (__GET_VAR(data__->STEP14.X)) {
    __SET_VAR(data__->,__transition_list[36],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->__transition_list[36]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[36],,0);
  }
  if (__GET_VAR(data__->SENDTOP.X)) {
    __SET_VAR(data__->,__transition_list[37],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_VAR(data__->__transition_list[37]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[37],,0);
  }
  if (__GET_VAR(data__->STEP28.X)) {
    __SET_VAR(data__->,__transition_list[38],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_VAR(data__->__transition_list[38]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[38],,0);
  }
  if (__GET_VAR(data__->STEP42.X)) {
    __SET_VAR(data__->,__transition_list[39],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,__GET_VAR(data__->__transition_list[39]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[39],,0);
  }
  if (__GET_VAR(data__->STEP41.X)) {
    __SET_VAR(data__->,__transition_list[40],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_VAR(data__->__transition_list[40]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[40],,0);
  }
  if (__GET_VAR(data__->STEP43.X)) {
    __SET_VAR(data__->,__transition_list[41],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,__GET_VAR(data__->__transition_list[41]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[41],,0);
  }
  if (__GET_VAR(data__->STEP45.X)) {
    __SET_VAR(data__->,__transition_list[42],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,__GET_VAR(data__->__transition_list[42]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[42],,0);
  }
  if (__GET_VAR(data__->STEP29.X)) {
    __SET_VAR(data__->,__transition_list[43],,__GET_EXTERNAL(data__->SENSORSBT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,__GET_VAR(data__->__transition_list[43]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,__GET_EXTERNAL(data__->SENSORSBT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[43],,0);
  }
  if (__GET_VAR(data__->STEP31.X)) {
    __SET_VAR(data__->,__transition_list[44],,!(__GET_EXTERNAL(data__->SENSORSBT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,__GET_VAR(data__->__transition_list[44]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,!(__GET_EXTERNAL(data__->SENSORSBT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[44],,0);
  }
  if (__GET_VAR(data__->STEP32.X)) {
    __SET_VAR(data__->,__transition_list[45],,__GET_EXTERNAL(data__->SENSORSBT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,__GET_VAR(data__->__transition_list[45]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,__GET_EXTERNAL(data__->SENSORSBT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[45],,0);
  }
  if (__GET_VAR(data__->STEP33.X)) {
    __SET_VAR(data__->,__transition_list[46],,!(__GET_EXTERNAL(data__->SENSORSBT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,__GET_VAR(data__->__transition_list[46]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,!(__GET_EXTERNAL(data__->SENSORSBT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[46],,0);
  }
  if (__GET_VAR(data__->STEP34.X)) {
    __SET_VAR(data__->,__transition_list[47],,__GET_EXTERNAL(data__->SENSORSCT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,__GET_VAR(data__->__transition_list[47]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,__GET_EXTERNAL(data__->SENSORSCT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[47],,0);
  }
  if (__GET_VAR(data__->STEP35.X)) {
    __SET_VAR(data__->,__transition_list[48],,!(__GET_EXTERNAL(data__->SENSORSCT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,__GET_VAR(data__->__transition_list[48]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,!(__GET_EXTERNAL(data__->SENSORSCT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[48],,0);
  }
  if (__GET_VAR(data__->STEP36.X)) {
    __SET_VAR(data__->,__transition_list[49],,__GET_EXTERNAL(data__->SENSORSCT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,__GET_VAR(data__->__transition_list[49]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,__GET_EXTERNAL(data__->SENSORSCT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[49],,0);
  }
  if (__GET_VAR(data__->STEP37.X)) {
    __SET_VAR(data__->,__transition_list[50],,!(__GET_EXTERNAL(data__->SENSORSCT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[50],,__GET_VAR(data__->__transition_list[50]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[50],,!(__GET_EXTERNAL(data__->SENSORSCT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[50],,0);
  }
  if (__GET_VAR(data__->STEP38.X)) {
    __SET_VAR(data__->,__transition_list[51],,__GET_EXTERNAL(data__->SENSORMT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[51],,__GET_VAR(data__->__transition_list[51]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[51],,__GET_EXTERNAL(data__->SENSORMT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[51],,0);
  }
  if (__GET_VAR(data__->STEP44.X)) {
    __SET_VAR(data__->,__transition_list[52],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[52],,__GET_VAR(data__->__transition_list[52]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[52],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[52],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP9.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP30.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP12.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP10.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP13.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP15.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP16.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP17.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP18.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP19.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP20.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP21.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP22.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP23.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP24.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP25.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP26.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP39.X,,0);
    __SET_VAR(data__->,STEP40.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP5.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP6.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP27.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP46.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP47.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP48.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,STEP49.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,STEP50.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,STEP51.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,STEP52.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,STEP14.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,SENDTOP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,STEP28.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,STEP42.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,STEP41.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,STEP43.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,STEP45.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,STEP29.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,STEP31.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,STEP32.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,STEP33.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,STEP34.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,STEP35.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,STEP36.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[50])) {
    __SET_VAR(data__->,STEP37.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[51])) {
    __SET_VAR(data__->,STEP38.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[52])) {
    __SET_VAR(data__->,STEP44.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP30.X,,1);
    data__->STEP30.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP12.X,,1);
    data__->STEP12.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP11.X,,1);
    data__->STEP11.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP14.X,,1);
    data__->STEP14.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP10.X,,1);
    data__->STEP10.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP13.X,,1);
    data__->STEP13.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP15.X,,1);
    data__->STEP15.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP16.X,,1);
    data__->STEP16.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP17.X,,1);
    data__->STEP17.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP18.X,,1);
    data__->STEP18.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP19.X,,1);
    data__->STEP19.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP20.X,,1);
    data__->STEP20.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP21.X,,1);
    data__->STEP21.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP22.X,,1);
    data__->STEP22.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP23.X,,1);
    data__->STEP23.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP24.X,,1);
    data__->STEP24.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP25.X,,1);
    data__->STEP25.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP26.X,,1);
    data__->STEP26.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP39.X,,1);
    data__->STEP39.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP3.X,,1);
    data__->STEP3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP4.X,,1);
    data__->STEP4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP5.X,,1);
    data__->STEP5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP7.X,,1);
    data__->STEP7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP8.X,,1);
    data__->STEP8.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP6.X,,1);
    data__->STEP6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP27.X,,1);
    data__->STEP27.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP46.X,,1);
    data__->STEP46.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP47.X,,1);
    data__->STEP47.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP48.X,,1);
    data__->STEP48.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP49.X,,1);
    data__->STEP49.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,STEP50.X,,1);
    data__->STEP50.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,STEP51.X,,1);
    data__->STEP51.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,STEP52.X,,1);
    data__->STEP52.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,STEP9.X,,1);
    data__->STEP9.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,SENDTOP.X,,1);
    data__->SENDTOP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,STEP28.X,,1);
    data__->STEP28.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,STEP42.X,,1);
    data__->STEP42.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP44.X,,1);
    data__->STEP44.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,STEP41.X,,1);
    data__->STEP41.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,STEP43.X,,1);
    data__->STEP43.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,STEP45.X,,1);
    data__->STEP45.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,STEP29.X,,1);
    data__->STEP29.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,STEP31.X,,1);
    data__->STEP31.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,STEP32.X,,1);
    data__->STEP32.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,STEP33.X,,1);
    data__->STEP33.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,STEP34.X,,1);
    data__->STEP34.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,STEP35.X,,1);
    data__->STEP35.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,STEP36.X,,1);
    data__->STEP36.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,STEP37.X,,1);
    data__->STEP37.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[50])) {
    __SET_VAR(data__->,STEP38.X,,1);
    data__->STEP38.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[51])) {
    __SET_VAR(data__->,STEP40.X,,1);
    data__->STEP40.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[52])) {
    __SET_VAR(data__->,STEP9.X,,1);
    data__->STEP9.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // STEP30 action associations
  {
    char active = __GET_VAR(data__->STEP30.X);
    char activated = active && !data__->STEP30.prev_state;
    char desactivated = !active && data__->STEP30.prev_state;

    if (active)       {data__->__action_list[__SFC_ACTION0].set = 1;}

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].set = 1;}

    if (activated)    {__SET_VAR(data__->,__action_list[__SFC_UNLOADBOTTOM].state,,1);}
    else              {__SET_VAR(data__->,__action_list[__SFC_UNLOADBOTTOM].state,,0);};

    if (active)       {data__->__action_list[__SFC_MOUNT].reset = 1;}

  }

  // STEP12 action associations
  {
    char active = __GET_VAR(data__->STEP12.X);
    char activated = active && !data__->STEP12.prev_state;
    char desactivated = !active && data__->STEP12.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,0);};

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,0);};

  }

  // STEP10 action associations
  {
    char active = __GET_VAR(data__->STEP10.X);
    char activated = active && !data__->STEP10.prev_state;
    char desactivated = !active && data__->STEP10.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,0);};

  }

  // STEP15 action associations
  {
    char active = __GET_VAR(data__->STEP15.X);
    char activated = active && !data__->STEP15.prev_state;
    char desactivated = !active && data__->STEP15.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,0);};

  }

  // STEP17 action associations
  {
    char active = __GET_VAR(data__->STEP17.X);
    char activated = active && !data__->STEP17.prev_state;
    char desactivated = !active && data__->STEP17.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,0);};

  }

  // STEP19 action associations
  {
    char active = __GET_VAR(data__->STEP19.X);
    char activated = active && !data__->STEP19.prev_state;
    char desactivated = !active && data__->STEP19.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,0);};

  }

  // STEP21 action associations
  {
    char active = __GET_VAR(data__->STEP21.X);
    char activated = active && !data__->STEP21.prev_state;
    char desactivated = !active && data__->STEP21.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSCT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSCT2_EX,,0);};

  }

  // STEP23 action associations
  {
    char active = __GET_VAR(data__->STEP23.X);
    char activated = active && !data__->STEP23.prev_state;
    char desactivated = !active && data__->STEP23.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTMT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTMT1_EX,,0);};

  }

  // STEP25 action associations
  {
    char active = __GET_VAR(data__->STEP25.X);
    char activated = active && !data__->STEP25.prev_state;
    char desactivated = !active && data__->STEP25.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RECEIVEPIECEMT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RECEIVEPIECEMT2_EX,,0);};

  }

  // STEP1 action associations
  {
    char active = __GET_VAR(data__->STEP1.X);
    char activated = active && !data__->STEP1.prev_state;
    char desactivated = !active && data__->STEP1.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,X1Y0_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,X1Y0_EX,,0);};

  }

  // STEP3 action associations
  {
    char active = __GET_VAR(data__->STEP3.X);
    char activated = active && !data__->STEP3.prev_state;
    char desactivated = !active && data__->STEP3.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,PICKPIECE_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,PICKPIECE_EX,,0);};

  }

  // STEP5 action associations
  {
    char active = __GET_VAR(data__->STEP5.X);
    char activated = active && !data__->STEP5.prev_state;
    char desactivated = !active && data__->STEP5.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RECEIVEPIECEMT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RECEIVEPIECEMT2_EX,,0);};

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTMT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTMT1_EX,,0);};

  }

  // STEP7 action associations
  {
    char active = __GET_VAR(data__->STEP7.X);
    char activated = active && !data__->STEP7.prev_state;
    char desactivated = !active && data__->STEP7.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RELEASEPIECE_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RELEASEPIECE_EX,,0);};

  }

  // STEP0 action associations
  {
    char active = __GET_VAR(data__->STEP0.X);
    char activated = active && !data__->STEP0.prev_state;
    char desactivated = !active && data__->STEP0.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTMT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTMT2_EX,,0);};

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTCT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTCT1_EX,,0);};

  }

  // STEP27 action associations
  {
    char active = __GET_VAR(data__->STEP27.X);
    char activated = active && !data__->STEP27.prev_state;
    char desactivated = !active && data__->STEP27.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SENDDOWNCT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDDOWNCT2_EX,,0);};

  }

  // STEP47 action associations
  {
    char active = __GET_VAR(data__->STEP47.X);
    char activated = active && !data__->STEP47.prev_state;
    char desactivated = !active && data__->STEP47.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTCT4_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTCT4_EX,,0);};

  }

  // STEP49 action associations
  {
    char active = __GET_VAR(data__->STEP49.X);
    char activated = active && !data__->STEP49.prev_state;
    char desactivated = !active && data__->STEP49.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTCT5_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTCT5_EX,,0);};

  }

  // STEP51 action associations
  {
    char active = __GET_VAR(data__->STEP51.X);
    char activated = active && !data__->STEP51.prev_state;
    char desactivated = !active && data__->STEP51.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,PUSHTOROLLCT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,PUSHTOROLLCT6_EX,,0);};

  }

  // STEP14 action associations
  {
    char active = __GET_VAR(data__->STEP14.X);
    char activated = active && !data__->STEP14.prev_state;
    char desactivated = !active && data__->STEP14.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_UNLOADTOP].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_UNLOADTOP].state,,0);};

    if (active)       {data__->__action_list[__SFC_ACTION0].reset = 1;}

  }

  // SENDTOP action associations
  {
    char active = __GET_VAR(data__->SENDTOP.X);
    char activated = active && !data__->SENDTOP.prev_state;
    char desactivated = !active && data__->SENDTOP.prev_state;

    if (active)       {data__->__action_list[__SFC_ACTION0].set = 1;}

  }

  // STEP28 action associations
  {
    char active = __GET_VAR(data__->STEP28.X);
    char activated = active && !data__->STEP28.prev_state;
    char desactivated = !active && data__->STEP28.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,0);};

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,0);};

  }

  // STEP41 action associations
  {
    char active = __GET_VAR(data__->STEP41.X);
    char activated = active && !data__->STEP41.prev_state;
    char desactivated = !active && data__->STEP41.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,0);};

  }

  // STEP45 action associations
  {
    char active = __GET_VAR(data__->STEP45.X);
    char activated = active && !data__->STEP45.prev_state;
    char desactivated = !active && data__->STEP45.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,0);};

  }

  // STEP31 action associations
  {
    char active = __GET_VAR(data__->STEP31.X);
    char activated = active && !data__->STEP31.prev_state;
    char desactivated = !active && data__->STEP31.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,0);};

  }

  // STEP33 action associations
  {
    char active = __GET_VAR(data__->STEP33.X);
    char activated = active && !data__->STEP33.prev_state;
    char desactivated = !active && data__->STEP33.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,0);};

  }

  // STEP35 action associations
  {
    char active = __GET_VAR(data__->STEP35.X);
    char activated = active && !data__->STEP35.prev_state;
    char desactivated = !active && data__->STEP35.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSCT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSCT2_EX,,0);};

  }

  // STEP37 action associations
  {
    char active = __GET_VAR(data__->STEP37.X);
    char activated = active && !data__->STEP37.prev_state;
    char desactivated = !active && data__->STEP37.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RECEIVEPIECEMT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RECEIVEPIECEMT1_EX,,0);};

  }

  // STEP44 action associations
  {
    char active = __GET_VAR(data__->STEP44.X);
    char activated = active && !data__->STEP44.prev_state;
    char desactivated = !active && data__->STEP44.prev_state;

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].reset = 1;}

    if (active)       {data__->__action_list[__SFC_ACTION0].reset = 1;}

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
    __SET_LOCATED(data__->,WAREHOUSEBUSY,,0);
  }
  else if (data__->__action_list[__SFC_WAREHOUSEBUSY].set) {
    __SET_LOCATED(data__->,WAREHOUSEBUSY,,1);
  }
  if (data__->__action_list[__SFC_MOUNT].reset) {
    __SET_LOCATED(data__->,MOUNT,,0);
  }
  else if (data__->__action_list[__SFC_MOUNT].set) {
    __SET_LOCATED(data__->,MOUNT,,1);
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
  if (data__->__action_list[__SFC_RECEIVEPIECEMT2_EX].reset) {
    __SET_EXTERNAL(data__->,RECEIVEPIECEMT2_EX,,0);
  }
  else if (data__->__action_list[__SFC_RECEIVEPIECEMT2_EX].set) {
    __SET_EXTERNAL(data__->,RECEIVEPIECEMT2_EX,,1);
  }
  if (data__->__action_list[__SFC_X1Y0_EX].reset) {
    __SET_EXTERNAL(data__->,X1Y0_EX,,0);
  }
  else if (data__->__action_list[__SFC_X1Y0_EX].set) {
    __SET_EXTERNAL(data__->,X1Y0_EX,,1);
  }
  if (data__->__action_list[__SFC_PICKPIECE_EX].reset) {
    __SET_EXTERNAL(data__->,PICKPIECE_EX,,0);
  }
  else if (data__->__action_list[__SFC_PICKPIECE_EX].set) {
    __SET_EXTERNAL(data__->,PICKPIECE_EX,,1);
  }
  if (data__->__action_list[__SFC_RELEASEPIECE_EX].reset) {
    __SET_EXTERNAL(data__->,RELEASEPIECE_EX,,0);
  }
  else if (data__->__action_list[__SFC_RELEASEPIECE_EX].set) {
    __SET_EXTERNAL(data__->,RELEASEPIECE_EX,,1);
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
  if (data__->__action_list[__SFC_RUNFRONTCT4_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTCT4_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTCT4_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTCT4_EX,,1);
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
  if (data__->__action_list[__SFC_RECEIVEPIECEMT1_EX].reset) {
    __SET_EXTERNAL(data__->,RECEIVEPIECEMT1_EX,,0);
  }
  else if (data__->__action_list[__SFC_RECEIVEPIECEMT1_EX].set) {
    __SET_EXTERNAL(data__->,RECEIVEPIECEMT1_EX,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_ACTION0].state)) {
    __SET_VAR(data__->REMOVEFROMWAREHOUSE0.,PIECENUM,,__GET_VAR(data__->PIECETOUNLOAD,));
    __SET_VAR(data__->REMOVEFROMWAREHOUSE0.,SENSORAT1,,__GET_LOCATED(data__->SENSORAT1,));
    REMOVEFROMWAREHOUSE_body__(&data__->REMOVEFROMWAREHOUSE0);
    __SET_LOCATED(data__->,WAREHOUSEIN,,__GET_VAR(data__->REMOVEFROMWAREHOUSE0.WAREHOUSEIN,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_UNLOADBOTTOM].state)) {
    __SET_VAR(data__->,PIECETOUNLOAD,,__GET_LOCATED(data__->BOTTOMPIECE,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_UNLOADTOP].state)) {
    __SET_VAR(data__->,PIECETOUNLOAD,,__GET_LOCATED(data__->TOPPIECE,));
  }



  goto __end;

__end:
  return;
} // GANTRYPROGRAMGOOD_body__() 

// Steps undefinitions
#undef STEP9
#undef __SFC_STEP9
#undef STEP30
#undef __SFC_STEP30
#undef STEP12
#undef __SFC_STEP12
#undef STEP11
#undef __SFC_STEP11
#undef STEP10
#undef __SFC_STEP10
#undef STEP13
#undef __SFC_STEP13
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
#undef STEP26
#undef __SFC_STEP26
#undef STEP39
#undef __SFC_STEP39
#undef STEP1
#undef __SFC_STEP1
#undef STEP2
#undef __SFC_STEP2
#undef STEP3
#undef __SFC_STEP3
#undef STEP4
#undef __SFC_STEP4
#undef STEP5
#undef __SFC_STEP5
#undef STEP7
#undef __SFC_STEP7
#undef STEP8
#undef __SFC_STEP8
#undef STEP0
#undef __SFC_STEP0
#undef STEP6
#undef __SFC_STEP6
#undef STEP27
#undef __SFC_STEP27
#undef STEP46
#undef __SFC_STEP46
#undef STEP47
#undef __SFC_STEP47
#undef STEP48
#undef __SFC_STEP48
#undef STEP49
#undef __SFC_STEP49
#undef STEP50
#undef __SFC_STEP50
#undef STEP51
#undef __SFC_STEP51
#undef STEP52
#undef __SFC_STEP52
#undef STEP14
#undef __SFC_STEP14
#undef SENDTOP
#undef __SFC_SENDTOP
#undef STEP28
#undef __SFC_STEP28
#undef STEP42
#undef __SFC_STEP42
#undef STEP41
#undef __SFC_STEP41
#undef STEP43
#undef __SFC_STEP43
#undef STEP45
#undef __SFC_STEP45
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
#undef STEP40
#undef __SFC_STEP40
#undef STEP44
#undef __SFC_STEP44

// Actions undefinitions
#undef __SFC_ACTION0
#undef __SFC_UNLOADBOTTOM
#undef __SFC_UNLOADTOP
#undef __SFC_WAREHOUSEBUSY
#undef __SFC_MOUNT
#undef __SFC_RUNFRONTSAT1_EX
#undef __SFC_RUNFRONTAT1_EX
#undef __SFC_RUNFRONTSAT2_EX
#undef __SFC_RUNFRONTSBT1_EX
#undef __SFC_RUNFRONTSBT2_EX
#undef __SFC_RUNFRONTSCT1_EX
#undef __SFC_RUNFRONTSCT2_EX
#undef __SFC_RUNFRONTMT1_EX
#undef __SFC_RECEIVEPIECEMT2_EX
#undef __SFC_X1Y0_EX
#undef __SFC_PICKPIECE_EX
#undef __SFC_RELEASEPIECE_EX
#undef __SFC_RUNFRONTMT2_EX
#undef __SFC_RUNFRONTCT1_EX
#undef __SFC_SENDDOWNCT2_EX
#undef __SFC_RUNFRONTCT4_EX
#undef __SFC_RUNFRONTCT5_EX
#undef __SFC_PUSHTOROLLCT6_EX
#undef __SFC_RECEIVEPIECEMT1_EX





void LOADPROGRAM_init__(LOADPROGRAM *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,ISLOADINGP1,data__->ISLOADINGP1,retain)
  __INIT_EXTERNAL(BOOL,ISLOADINGP2,data__->ISLOADINGP2,retain)
  __INIT_LOCATED(INT,__IW0_0_2_0,data__->WAREHOUSEIN,retain)
  __INIT_LOCATED_VALUE(data__->WAREHOUSEIN,0)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT6_EX,data__->RUNFRONTCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT6_EX,data__->SENSORCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDRIGHTDOWNCT2_EX,data__->SENDRIGHTDOWNCT2_EX,retain)
  __INIT_LOCATED(BOOL,__IX0_0_0_0,data__->SENSORAT1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(INT,__IW0_1_1_2,data__->PM,retain)
  __INIT_LOCATED_VALUE(data__->PM,0)
  __INIT_VAR(data__->INITIALPIECE,0,retain)
  __INIT_VAR(data__->FINALPIECE,0,retain)
  __INIT_EXTERNAL(BOOL,WAREHOUSEBUSY,data__->WAREHOUSEBUSY,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTAT1_EX,data__->RUNFRONTAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT1_EX,data__->RUNFRONTSAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT2_EX,data__->RUNFRONTSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT4_EX,data__->RUNFRONTSAT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT1_EX,data__->RUNFRONTSBT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT2_EX,data__->RUNFRONTSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT4_EX,data__->RUNFRONTSBT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT1_EX,data__->RUNFRONTSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT2_EX,data__->RUNFRONTSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT4_EX,data__->RUNFRONTSCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT1_EX,data__->RUNFRONTMT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT2_EX,data__->RUNFRONTMT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKMT5_EX,data__->RUNBACKMT5_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT1_EX,data__->RUNFRONTCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT3_EX,data__->RUNFRONTCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT4_EX,data__->RUNFRONTCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT5_EX,data__->RUNFRONTCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSAT7_EX,data__->RUNBACKSAT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSCT7_EX,data__->RUNBACKSCT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSBT7_EX,data__->RUNBACKSBT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSBT6_EX,data__->RUNBACKSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSAT6_EX,data__->RUNBACKSAT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSCT6_EX,data__->RUNBACKSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKCT9_EX,data__->RUNBACKCT9_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKCT3_EX,data__->RUNBACKCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSAT2_EX,data__->SENDDOWNSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSBT2_EX,data__->SENDDOWNSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSCT2_EX,data__->SENDDOWNSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESAT3_EX,data__->TOOLPIECESAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESAT5_EX,data__->TOOLPIECESAT5_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESBT3_EX,data__->TOOLPIECESBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESBT5_EX,data__->TOOLPIECESBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESCT3_EX,data__->TOOLPIECESCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESCT5_EX,data__->TOOLPIECESCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNCT2_EX,data__->SENDDOWNCT2_EX,retain)
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
  __INIT_EXTERNAL(BOOL,SENSORSBT3_EX,data__->SENSORSBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT4_EX,data__->SENSORSBT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT5_EX,data__->SENSORSBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT6_EX,data__->SENSORSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT7_EX,data__->SENSORSBT7_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT1_EX,data__->SENSORSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT2_EX,data__->SENSORSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT3_EX,data__->SENSORSCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT4_EX,data__->SENSORSCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT5_EX,data__->SENSORSCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT6_EX,data__->SENSORSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT7_EX,data__->SENSORSCT7_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT1_EX,data__->SENSORMT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT2_EX,data__->SENSORMT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT1_EX,data__->SENSORCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT2_EX,data__->SENSORCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT3_EX,data__->SENSORCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT4_EX,data__->SENSORCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT5_EX,data__->SENSORCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT7_EX,data__->SENSORCT7_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT8_EX,data__->SENSORCT8_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT9_EX,data__->SENSORCT9_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT6_EX,data__->SENSORMT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT5_EX,data__->SENSORMT5_EX,retain)
  __INIT_EXTERNAL(BOOL,PUSHTOROLLCT4_EX,data__->PUSHTOROLLCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,PUSHTOROLLCT5_EX,data__->PUSHTOROLLCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,PUSHTOROLLCT6_EX,data__->PUSHTOROLLCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNSAT6_EX,data__->SENDLEFTDOWNSAT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNSBT6_EX,data__->SENDLEFTDOWNSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNSCT6_EX,data__->SENDLEFTDOWNSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNCT8_EX,data__->SENDLEFTDOWNCT8_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKCT8_EX,data__->RUNBACKCT8_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKMT6_EX,data__->RUNBACKMT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKCT7_EX,data__->RUNBACKCT7_EX,retain)
  __INIT_EXTERNAL(BOOL,PUTPIECEINSIGNAL_EX,data__->PUTPIECEINSIGNAL_EX,retain)
  REMOVEFROMWAREHOUSE_init__(&data__->REMOVEFROMWAREHOUSE0,retain);
  __INIT_LOCATED(BOOL,__IX0_1_0_1,data__->RUNUNLOAD,retain)
  __INIT_LOCATED_VALUE(data__->RUNUNLOAD,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1_0_2,data__->RUNTRANSFORMMACH1,retain)
  __INIT_LOCATED_VALUE(data__->RUNTRANSFORMMACH1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1_0_3,data__->RUNTRANSFORMMACH2,retain)
  __INIT_LOCATED_VALUE(data__->RUNTRANSFORMMACH2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1_0_4,data__->RUNTRANSFORMMACH3,retain)
  __INIT_LOCATED_VALUE(data__->RUNTRANSFORMMACH3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1_0_5,data__->CELL1BUSY,retain)
  __INIT_LOCATED_VALUE(data__->CELL1BUSY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1_0_6,data__->CELL2BUSY,retain)
  __INIT_LOCATED_VALUE(data__->CELL2BUSY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1_0_7,data__->CELL3BUSY,retain)
  __INIT_LOCATED_VALUE(data__->CELL3BUSY,__BOOL_LITERAL(FALSE))
  __INIT_EXTERNAL(BOOL,READYTOSENDSAT3_EX,data__->READYTOSENDSAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSAT5_EX,data__->READYTOSENDSAT5_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSBT3_EX,data__->READYTOSENDSBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSBT5_EX,data__->READYTOSENDSBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSCT3_EX,data__->READYTOSENDSCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSCT5_EX,data__->READYTOSENDSCT5_EX,retain)
  UINT i;
  data__->__nb_steps = 39;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  __SET_VAR(data__->,__step_list[35].X,,1);
  data__->__nb_actions = 21;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 38;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define STEP7 __step_list[0]
#define __SFC_STEP7 0
#define STEP165 __step_list[1]
#define __SFC_STEP165 1
#define STEP8 __step_list[2]
#define __SFC_STEP8 2
#define STEP78 __step_list[3]
#define __SFC_STEP78 3
#define STEP79 __step_list[4]
#define __SFC_STEP79 4
#define STEP80 __step_list[5]
#define __SFC_STEP80 5
#define STEP82 __step_list[6]
#define __SFC_STEP82 6
#define STEP83 __step_list[7]
#define __SFC_STEP83 7
#define STEP84 __step_list[8]
#define __SFC_STEP84 8
#define STEP85 __step_list[9]
#define __SFC_STEP85 9
#define STEP11 __step_list[10]
#define __SFC_STEP11 10
#define STEP6 __step_list[11]
#define __SFC_STEP6 11
#define STEP163 __step_list[12]
#define __SFC_STEP163 12
#define STEP4 __step_list[13]
#define __SFC_STEP4 13
#define STEP162 __step_list[14]
#define __SFC_STEP162 14
#define STEP3 __step_list[15]
#define __SFC_STEP3 15
#define STEP161 __step_list[16]
#define __SFC_STEP161 16
#define STEP2 __step_list[17]
#define __SFC_STEP2 17
#define STEP151 __step_list[18]
#define __SFC_STEP151 18
#define STEP1 __step_list[19]
#define __SFC_STEP1 19
#define STEP149 __step_list[20]
#define __SFC_STEP149 20
#define STEP0 __step_list[21]
#define __SFC_STEP0 21
#define STEP147 __step_list[22]
#define __SFC_STEP147 22
#define STEP148 __step_list[23]
#define __SFC_STEP148 23
#define STEP152 __step_list[24]
#define __SFC_STEP152 24
#define STEP153 __step_list[25]
#define __SFC_STEP153 25
#define STEP154 __step_list[26]
#define __SFC_STEP154 26
#define STEP156 __step_list[27]
#define __SFC_STEP156 27
#define STEP157 __step_list[28]
#define __SFC_STEP157 28
#define STEP150 __step_list[29]
#define __SFC_STEP150 29
#define STEP155 __step_list[30]
#define __SFC_STEP155 30
#define STEP158 __step_list[31]
#define __SFC_STEP158 31
#define STEP159 __step_list[32]
#define __SFC_STEP159 32
#define STEP160 __step_list[33]
#define __SFC_STEP160 33
#define STEP12 __step_list[34]
#define __SFC_STEP12 34
#define STEP5 __step_list[35]
#define __SFC_STEP5 35
#define STEP164 __step_list[36]
#define __SFC_STEP164 36
#define STEP9 __step_list[37]
#define __SFC_STEP9 37
#define STEP10 __step_list[38]
#define __SFC_STEP10 38

// Actions definitions
#define __SFC_RUNBACKCT3_EX 0
#define __SFC_ISLOADINGP1 1
#define __SFC_SENDRIGHTDOWNCT2_EX 2
#define __SFC_RUNFRONTCT4_EX 3
#define __SFC_RUNFRONTCT5_EX 4
#define __SFC_RUNFRONTCT6_EX 5
#define __SFC_SENDLEFTDOWNCT8_EX 6
#define __SFC_RUNBACKCT7_EX 7
#define __SFC_RUNBACKMT6_EX 8
#define __SFC_ISLOADINGP2 9
#define __SFC_RUNBACKMT5_EX 10
#define __SFC_RUNBACKSCT6_EX 11
#define __SFC_RUNBACKSCT7_EX 12
#define __SFC_RUNBACKSBT6_EX 13
#define __SFC_RUNBACKSBT7_EX 14
#define __SFC_RUNBACKSAT6_EX 15
#define __SFC_RUNBACKSAT7_EX 16
#define __SFC_PUTPIECEINSIGNAL_EX 17
#define __SFC_CELL3BUSY 18
#define __SFC_RUNBACKCT8_EX 19
#define __SFC_RUNBACKCT9_EX 20

// Code part
void LOADPROGRAM_body__(LOADPROGRAM *data__) {
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
  if (__GET_VAR(data__->STEP7.X)) {
    __SET_VAR(data__->,__transition_list[0],,__GET_EXTERNAL(data__->SENSORCT3_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_EXTERNAL(data__->SENSORCT3_EX,));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->STEP165.X)) {
    __SET_VAR(data__->,__transition_list[1],,!(__GET_EXTERNAL(data__->SENSORCT3_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,__GET_VAR(data__->__transition_list[1]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[1],,!(__GET_EXTERNAL(data__->SENSORCT3_EX,)));
    }
    __SET_VAR(data__->,__transition_list[1],,0);
  }
  if (__GET_VAR(data__->STEP8.X)) {
    __SET_VAR(data__->,__transition_list[2],,__GET_EXTERNAL(data__->SENSORCT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_VAR(data__->__transition_list[2]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[2],,__GET_EXTERNAL(data__->SENSORCT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[2],,0);
  }
  if (__GET_VAR(data__->STEP78.X)) {
    __SET_VAR(data__->,__transition_list[3],,!(__GET_EXTERNAL(data__->SENSORCT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,__GET_VAR(data__->__transition_list[3]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[3],,!(__GET_EXTERNAL(data__->SENSORCT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[3],,0);
  }
  if (__GET_VAR(data__->STEP79.X)) {
    __SET_VAR(data__->,__transition_list[4],,__GET_EXTERNAL(data__->SENSORCT4_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_VAR(data__->__transition_list[4]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[4],,__GET_EXTERNAL(data__->SENSORCT4_EX,));
    }
    __SET_VAR(data__->,__transition_list[4],,0);
  }
  if (__GET_VAR(data__->STEP80.X)) {
    __SET_VAR(data__->,__transition_list[5],,!(__GET_EXTERNAL(data__->SENSORCT4_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,__GET_VAR(data__->__transition_list[5]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[5],,!(__GET_EXTERNAL(data__->SENSORCT4_EX,)));
    }
    __SET_VAR(data__->,__transition_list[5],,0);
  }
  if (__GET_VAR(data__->STEP82.X)) {
    __SET_VAR(data__->,__transition_list[6],,__GET_EXTERNAL(data__->SENSORCT5_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_VAR(data__->__transition_list[6]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[6],,__GET_EXTERNAL(data__->SENSORCT5_EX,));
    }
    __SET_VAR(data__->,__transition_list[6],,0);
  }
  if (__GET_VAR(data__->STEP83.X)) {
    __SET_VAR(data__->,__transition_list[7],,!(__GET_EXTERNAL(data__->SENSORCT5_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,!(__GET_EXTERNAL(data__->SENSORCT5_EX,)));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->STEP84.X)) {
    __SET_VAR(data__->,__transition_list[8],,__GET_EXTERNAL(data__->SENSORCT6_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_VAR(data__->__transition_list[8]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[8],,__GET_EXTERNAL(data__->SENSORCT6_EX,));
    }
    __SET_VAR(data__->,__transition_list[8],,0);
  }
  if (__GET_VAR(data__->STEP85.X)) {
    __SET_VAR(data__->,__transition_list[9],,!(__GET_EXTERNAL(data__->SENSORCT6_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,__GET_VAR(data__->__transition_list[9]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[9],,!(__GET_EXTERNAL(data__->SENSORCT6_EX,)));
    }
    __SET_VAR(data__->,__transition_list[9],,0);
  }
  if (__GET_VAR(data__->STEP11.X)) {
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
  if (__GET_VAR(data__->STEP6.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_EXTERNAL(data__->SENSORCT8_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_EXTERNAL(data__->SENSORCT8_EX,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->STEP163.X)) {
    __SET_VAR(data__->,__transition_list[12],,!(__GET_EXTERNAL(data__->SENSORCT8_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,!(__GET_EXTERNAL(data__->SENSORCT8_EX,)));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->STEP4.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_EXTERNAL(data__->SENSORCT7_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_EXTERNAL(data__->SENSORCT7_EX,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->STEP162.X)) {
    __SET_VAR(data__->,__transition_list[14],,!(__GET_EXTERNAL(data__->SENSORCT7_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,!(__GET_EXTERNAL(data__->SENSORCT7_EX,)));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->STEP3.X)) {
    __SET_VAR(data__->,__transition_list[15],,__GET_EXTERNAL(data__->SENSORMT6_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_VAR(data__->__transition_list[15]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[15],,__GET_EXTERNAL(data__->SENSORMT6_EX,));
    }
    __SET_VAR(data__->,__transition_list[15],,0);
  }
  if (__GET_VAR(data__->STEP161.X)) {
    __SET_VAR(data__->,__transition_list[16],,!(__GET_EXTERNAL(data__->SENSORMT6_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,__GET_VAR(data__->__transition_list[16]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[16],,!(__GET_EXTERNAL(data__->SENSORMT6_EX,)));
    }
    __SET_VAR(data__->,__transition_list[16],,0);
  }
  if (__GET_VAR(data__->STEP2.X)) {
    __SET_VAR(data__->,__transition_list[17],,__GET_EXTERNAL(data__->SENSORMT5_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_VAR(data__->__transition_list[17]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[17],,__GET_EXTERNAL(data__->SENSORMT5_EX,));
    }
    __SET_VAR(data__->,__transition_list[17],,0);
  }
  if (__GET_VAR(data__->STEP151.X)) {
    __SET_VAR(data__->,__transition_list[18],,!(__GET_EXTERNAL(data__->SENSORMT5_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,__GET_VAR(data__->__transition_list[18]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[18],,!(__GET_EXTERNAL(data__->SENSORMT5_EX,)));
    }
    __SET_VAR(data__->,__transition_list[18],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
    __SET_VAR(data__->,__transition_list[19],,__GET_EXTERNAL(data__->SENSORSCT6_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_EXTERNAL(data__->SENSORSCT6_EX,));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->STEP149.X)) {
    __SET_VAR(data__->,__transition_list[20],,!(__GET_EXTERNAL(data__->SENSORSCT6_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,!(__GET_EXTERNAL(data__->SENSORSCT6_EX,)));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->STEP0.X)) {
    __SET_VAR(data__->,__transition_list[21],,__GET_EXTERNAL(data__->SENSORSCT7_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_EXTERNAL(data__->SENSORSCT7_EX,));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->STEP147.X)) {
    __SET_VAR(data__->,__transition_list[22],,!(__GET_EXTERNAL(data__->SENSORSCT7_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,!(__GET_EXTERNAL(data__->SENSORSCT7_EX,)));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->STEP148.X)) {
    __SET_VAR(data__->,__transition_list[23],,__GET_EXTERNAL(data__->SENSORSBT6_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_EXTERNAL(data__->SENSORSBT6_EX,));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->STEP152.X)) {
    __SET_VAR(data__->,__transition_list[24],,!(__GET_EXTERNAL(data__->SENSORSBT6_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,!(__GET_EXTERNAL(data__->SENSORSBT6_EX,)));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->STEP153.X)) {
    __SET_VAR(data__->,__transition_list[25],,__GET_EXTERNAL(data__->SENSORSBT7_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_EXTERNAL(data__->SENSORSBT7_EX,));
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->STEP154.X)) {
    __SET_VAR(data__->,__transition_list[26],,!(__GET_EXTERNAL(data__->SENSORSBT7_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,!(__GET_EXTERNAL(data__->SENSORSBT7_EX,)));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->STEP156.X)) {
    __SET_VAR(data__->,__transition_list[27],,__GET_EXTERNAL(data__->SENSORSAT6_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_EXTERNAL(data__->SENSORSAT6_EX,));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->STEP157.X)) {
    __SET_VAR(data__->,__transition_list[28],,!(__GET_EXTERNAL(data__->SENSORSAT6_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,!(__GET_EXTERNAL(data__->SENSORSAT6_EX,)));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->STEP150.X)) {
    __SET_VAR(data__->,__transition_list[29],,__GET_EXTERNAL(data__->SENSORSAT7_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_EXTERNAL(data__->SENSORSAT7_EX,));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->STEP155.X)) {
    __SET_VAR(data__->,__transition_list[30],,!(__GET_EXTERNAL(data__->SENSORSAT7_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,!(__GET_EXTERNAL(data__->SENSORSAT7_EX,)));
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->STEP158.X)) {
    __SET_VAR(data__->,__transition_list[31],,__GET_EXTERNAL(data__->SENSORAT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_EXTERNAL(data__->SENSORAT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }
  if (__GET_VAR(data__->STEP159.X)) {
    __SET_VAR(data__->,__transition_list[32],,!(__GET_EXTERNAL(data__->SENSORAT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->__transition_list[32]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,!(__GET_EXTERNAL(data__->SENSORAT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[32],,0);
  }
  if (__GET_VAR(data__->STEP12.X)) {
    __SET_VAR(data__->,__transition_list[33],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->__transition_list[33]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[33],,0);
  }
  if (__GET_VAR(data__->STEP5.X)) {
    __SET_VAR(data__->,__transition_list[34],,__GET_EXTERNAL(data__->SENSORCT9_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_VAR(data__->__transition_list[34]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_EXTERNAL(data__->SENSORCT9_EX,));
    }
    __SET_VAR(data__->,__transition_list[34],,0);
  }
  if (__GET_VAR(data__->STEP164.X)) {
    __SET_VAR(data__->,__transition_list[35],,!(__GET_EXTERNAL(data__->SENSORCT9_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->__transition_list[35]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,!(__GET_EXTERNAL(data__->SENSORCT9_EX,)));
    }
    __SET_VAR(data__->,__transition_list[35],,0);
  }
  if (__GET_VAR(data__->STEP9.X)) {
    __SET_VAR(data__->,__transition_list[36],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->__transition_list[36]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[36],,0);
  }
  if (__GET_VAR(data__->STEP10.X)) {
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

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP7.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP165.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP8.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP78.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP79.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP80.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP82.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP83.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP84.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP85.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP6.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP163.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP4.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP162.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP3.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP161.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP2.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP151.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP1.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP149.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP147.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP148.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP152.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP153.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP154.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP156.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP157.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP150.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP155.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP158.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,STEP159.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,STEP12.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,STEP5.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,STEP164.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,STEP9.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,STEP10.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP165.X,,1);
    data__->STEP165.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP8.X,,1);
    data__->STEP8.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP78.X,,1);
    data__->STEP78.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP79.X,,1);
    data__->STEP79.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP80.X,,1);
    data__->STEP80.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP82.X,,1);
    data__->STEP82.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP83.X,,1);
    data__->STEP83.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP84.X,,1);
    data__->STEP84.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP85.X,,1);
    data__->STEP85.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP11.X,,1);
    data__->STEP11.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP12.X,,1);
    data__->STEP12.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP6.X,,1);
    data__->STEP6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP163.X,,1);
    data__->STEP163.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP4.X,,1);
    data__->STEP4.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP162.X,,1);
    data__->STEP162.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP3.X,,1);
    data__->STEP3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP161.X,,1);
    data__->STEP161.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP2.X,,1);
    data__->STEP2.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP151.X,,1);
    data__->STEP151.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP149.X,,1);
    data__->STEP149.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP147.X,,1);
    data__->STEP147.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP148.X,,1);
    data__->STEP148.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP152.X,,1);
    data__->STEP152.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP153.X,,1);
    data__->STEP153.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP154.X,,1);
    data__->STEP154.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP156.X,,1);
    data__->STEP156.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP157.X,,1);
    data__->STEP157.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP150.X,,1);
    data__->STEP150.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP155.X,,1);
    data__->STEP155.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP158.X,,1);
    data__->STEP158.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP159.X,,1);
    data__->STEP159.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,STEP160.X,,1);
    data__->STEP160.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,STEP7.X,,1);
    data__->STEP7.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,STEP164.X,,1);
    data__->STEP164.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,STEP9.X,,1);
    data__->STEP9.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP10.X,,1);
    data__->STEP10.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,STEP6.X,,1);
    data__->STEP6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,STEP5.X,,1);
    data__->STEP5.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // STEP165 action associations
  {
    char active = __GET_VAR(data__->STEP165.X);
    char activated = active && !data__->STEP165.prev_state;
    char desactivated = !active && data__->STEP165.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKCT3_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKCT3_EX,,0);};

    if (active)       {data__->__action_list[__SFC_ISLOADINGP1].set = 1;}

  }

  // STEP8 action associations
  {
    char active = __GET_VAR(data__->STEP8.X);
    char activated = active && !data__->STEP8.prev_state;
    char desactivated = !active && data__->STEP8.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SENDRIGHTDOWNCT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDRIGHTDOWNCT2_EX,,0);};

  }

  // STEP78 action associations
  {
    char active = __GET_VAR(data__->STEP78.X);
    char activated = active && !data__->STEP78.prev_state;
    char desactivated = !active && data__->STEP78.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTCT4_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTCT4_EX,,0);};

  }

  // STEP80 action associations
  {
    char active = __GET_VAR(data__->STEP80.X);
    char activated = active && !data__->STEP80.prev_state;
    char desactivated = !active && data__->STEP80.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTCT5_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTCT5_EX,,0);};

    if (active)       {data__->__action_list[__SFC_ISLOADINGP1].reset = 1;}

  }

  // STEP83 action associations
  {
    char active = __GET_VAR(data__->STEP83.X);
    char activated = active && !data__->STEP83.prev_state;
    char desactivated = !active && data__->STEP83.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTCT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTCT6_EX,,0);};

  }

  // STEP85 action associations
  {
    char active = __GET_VAR(data__->STEP85.X);
    char activated = active && !data__->STEP85.prev_state;
    char desactivated = !active && data__->STEP85.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SENDLEFTDOWNCT8_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDLEFTDOWNCT8_EX,,0);};

  }

  // STEP163 action associations
  {
    char active = __GET_VAR(data__->STEP163.X);
    char activated = active && !data__->STEP163.prev_state;
    char desactivated = !active && data__->STEP163.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKCT7_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKCT7_EX,,0);};

  }

  // STEP162 action associations
  {
    char active = __GET_VAR(data__->STEP162.X);
    char activated = active && !data__->STEP162.prev_state;
    char desactivated = !active && data__->STEP162.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKMT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKMT6_EX,,0);};

    if (active)       {data__->__action_list[__SFC_ISLOADINGP2].reset = 1;}

  }

  // STEP161 action associations
  {
    char active = __GET_VAR(data__->STEP161.X);
    char activated = active && !data__->STEP161.prev_state;
    char desactivated = !active && data__->STEP161.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKMT5_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKMT5_EX,,0);};

  }

  // STEP151 action associations
  {
    char active = __GET_VAR(data__->STEP151.X);
    char activated = active && !data__->STEP151.prev_state;
    char desactivated = !active && data__->STEP151.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSCT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSCT6_EX,,0);};

  }

  // STEP149 action associations
  {
    char active = __GET_VAR(data__->STEP149.X);
    char activated = active && !data__->STEP149.prev_state;
    char desactivated = !active && data__->STEP149.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSCT7_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSCT7_EX,,0);};

  }

  // STEP147 action associations
  {
    char active = __GET_VAR(data__->STEP147.X);
    char activated = active && !data__->STEP147.prev_state;
    char desactivated = !active && data__->STEP147.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSBT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSBT6_EX,,0);};

  }

  // STEP152 action associations
  {
    char active = __GET_VAR(data__->STEP152.X);
    char activated = active && !data__->STEP152.prev_state;
    char desactivated = !active && data__->STEP152.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSBT7_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSBT7_EX,,0);};

  }

  // STEP154 action associations
  {
    char active = __GET_VAR(data__->STEP154.X);
    char activated = active && !data__->STEP154.prev_state;
    char desactivated = !active && data__->STEP154.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSAT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSAT6_EX,,0);};

  }

  // STEP157 action associations
  {
    char active = __GET_VAR(data__->STEP157.X);
    char activated = active && !data__->STEP157.prev_state;
    char desactivated = !active && data__->STEP157.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKSAT7_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKSAT7_EX,,0);};

  }

  // STEP155 action associations
  {
    char active = __GET_VAR(data__->STEP155.X);
    char activated = active && !data__->STEP155.prev_state;
    char desactivated = !active && data__->STEP155.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,PUTPIECEINSIGNAL_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,PUTPIECEINSIGNAL_EX,,0);};

    if (active)       {data__->__action_list[__SFC_CELL3BUSY].reset = 1;}

  }

  // STEP164 action associations
  {
    char active = __GET_VAR(data__->STEP164.X);
    char activated = active && !data__->STEP164.prev_state;
    char desactivated = !active && data__->STEP164.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKCT8_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKCT8_EX,,0);};

    if (active)       {data__->__action_list[__SFC_ISLOADINGP2].set = 1;}

    if (active)       {__SET_EXTERNAL(data__->,RUNBACKCT9_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNBACKCT9_EX,,0);};

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
  if (data__->__action_list[__SFC_RUNBACKCT3_EX].reset) {
    __SET_EXTERNAL(data__->,RUNBACKCT3_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNBACKCT3_EX].set) {
    __SET_EXTERNAL(data__->,RUNBACKCT3_EX,,1);
  }
  if (data__->__action_list[__SFC_ISLOADINGP1].reset) {
    __SET_EXTERNAL(data__->,ISLOADINGP1,,0);
  }
  else if (data__->__action_list[__SFC_ISLOADINGP1].set) {
    __SET_EXTERNAL(data__->,ISLOADINGP1,,1);
  }
  if (data__->__action_list[__SFC_SENDRIGHTDOWNCT2_EX].reset) {
    __SET_EXTERNAL(data__->,SENDRIGHTDOWNCT2_EX,,0);
  }
  else if (data__->__action_list[__SFC_SENDRIGHTDOWNCT2_EX].set) {
    __SET_EXTERNAL(data__->,SENDRIGHTDOWNCT2_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTCT4_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTCT4_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTCT4_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTCT4_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTCT5_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTCT5_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTCT5_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTCT5_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTCT6_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTCT6_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTCT6_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTCT6_EX,,1);
  }
  if (data__->__action_list[__SFC_SENDLEFTDOWNCT8_EX].reset) {
    __SET_EXTERNAL(data__->,SENDLEFTDOWNCT8_EX,,0);
  }
  else if (data__->__action_list[__SFC_SENDLEFTDOWNCT8_EX].set) {
    __SET_EXTERNAL(data__->,SENDLEFTDOWNCT8_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNBACKCT7_EX].reset) {
    __SET_EXTERNAL(data__->,RUNBACKCT7_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNBACKCT7_EX].set) {
    __SET_EXTERNAL(data__->,RUNBACKCT7_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNBACKMT6_EX].reset) {
    __SET_EXTERNAL(data__->,RUNBACKMT6_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNBACKMT6_EX].set) {
    __SET_EXTERNAL(data__->,RUNBACKMT6_EX,,1);
  }
  if (data__->__action_list[__SFC_ISLOADINGP2].reset) {
    __SET_EXTERNAL(data__->,ISLOADINGP2,,0);
  }
  else if (data__->__action_list[__SFC_ISLOADINGP2].set) {
    __SET_EXTERNAL(data__->,ISLOADINGP2,,1);
  }
  if (data__->__action_list[__SFC_RUNBACKMT5_EX].reset) {
    __SET_EXTERNAL(data__->,RUNBACKMT5_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNBACKMT5_EX].set) {
    __SET_EXTERNAL(data__->,RUNBACKMT5_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNBACKSCT6_EX].reset) {
    __SET_EXTERNAL(data__->,RUNBACKSCT6_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNBACKSCT6_EX].set) {
    __SET_EXTERNAL(data__->,RUNBACKSCT6_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNBACKSCT7_EX].reset) {
    __SET_EXTERNAL(data__->,RUNBACKSCT7_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNBACKSCT7_EX].set) {
    __SET_EXTERNAL(data__->,RUNBACKSCT7_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNBACKSBT6_EX].reset) {
    __SET_EXTERNAL(data__->,RUNBACKSBT6_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNBACKSBT6_EX].set) {
    __SET_EXTERNAL(data__->,RUNBACKSBT6_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNBACKSBT7_EX].reset) {
    __SET_EXTERNAL(data__->,RUNBACKSBT7_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNBACKSBT7_EX].set) {
    __SET_EXTERNAL(data__->,RUNBACKSBT7_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNBACKSAT6_EX].reset) {
    __SET_EXTERNAL(data__->,RUNBACKSAT6_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNBACKSAT6_EX].set) {
    __SET_EXTERNAL(data__->,RUNBACKSAT6_EX,,1);
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
  if (data__->__action_list[__SFC_CELL3BUSY].reset) {
    __SET_LOCATED(data__->,CELL3BUSY,,0);
  }
  else if (data__->__action_list[__SFC_CELL3BUSY].set) {
    __SET_LOCATED(data__->,CELL3BUSY,,1);
  }
  if (data__->__action_list[__SFC_RUNBACKCT8_EX].reset) {
    __SET_EXTERNAL(data__->,RUNBACKCT8_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNBACKCT8_EX].set) {
    __SET_EXTERNAL(data__->,RUNBACKCT8_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNBACKCT9_EX].reset) {
    __SET_EXTERNAL(data__->,RUNBACKCT9_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNBACKCT9_EX].set) {
    __SET_EXTERNAL(data__->,RUNBACKCT9_EX,,1);
  }


  goto __end;

__end:
  return;
} // LOADPROGRAM_body__() 

// Steps undefinitions
#undef STEP7
#undef __SFC_STEP7
#undef STEP165
#undef __SFC_STEP165
#undef STEP8
#undef __SFC_STEP8
#undef STEP78
#undef __SFC_STEP78
#undef STEP79
#undef __SFC_STEP79
#undef STEP80
#undef __SFC_STEP80
#undef STEP82
#undef __SFC_STEP82
#undef STEP83
#undef __SFC_STEP83
#undef STEP84
#undef __SFC_STEP84
#undef STEP85
#undef __SFC_STEP85
#undef STEP11
#undef __SFC_STEP11
#undef STEP6
#undef __SFC_STEP6
#undef STEP163
#undef __SFC_STEP163
#undef STEP4
#undef __SFC_STEP4
#undef STEP162
#undef __SFC_STEP162
#undef STEP3
#undef __SFC_STEP3
#undef STEP161
#undef __SFC_STEP161
#undef STEP2
#undef __SFC_STEP2
#undef STEP151
#undef __SFC_STEP151
#undef STEP1
#undef __SFC_STEP1
#undef STEP149
#undef __SFC_STEP149
#undef STEP0
#undef __SFC_STEP0
#undef STEP147
#undef __SFC_STEP147
#undef STEP148
#undef __SFC_STEP148
#undef STEP152
#undef __SFC_STEP152
#undef STEP153
#undef __SFC_STEP153
#undef STEP154
#undef __SFC_STEP154
#undef STEP156
#undef __SFC_STEP156
#undef STEP157
#undef __SFC_STEP157
#undef STEP150
#undef __SFC_STEP150
#undef STEP155
#undef __SFC_STEP155
#undef STEP158
#undef __SFC_STEP158
#undef STEP159
#undef __SFC_STEP159
#undef STEP160
#undef __SFC_STEP160
#undef STEP12
#undef __SFC_STEP12
#undef STEP5
#undef __SFC_STEP5
#undef STEP164
#undef __SFC_STEP164
#undef STEP9
#undef __SFC_STEP9
#undef STEP10
#undef __SFC_STEP10

// Actions undefinitions
#undef __SFC_RUNBACKCT3_EX
#undef __SFC_ISLOADINGP1
#undef __SFC_SENDRIGHTDOWNCT2_EX
#undef __SFC_RUNFRONTCT4_EX
#undef __SFC_RUNFRONTCT5_EX
#undef __SFC_RUNFRONTCT6_EX
#undef __SFC_SENDLEFTDOWNCT8_EX
#undef __SFC_RUNBACKCT7_EX
#undef __SFC_RUNBACKMT6_EX
#undef __SFC_ISLOADINGP2
#undef __SFC_RUNBACKMT5_EX
#undef __SFC_RUNBACKSCT6_EX
#undef __SFC_RUNBACKSCT7_EX
#undef __SFC_RUNBACKSBT6_EX
#undef __SFC_RUNBACKSBT7_EX
#undef __SFC_RUNBACKSAT6_EX
#undef __SFC_RUNBACKSAT7_EX
#undef __SFC_PUTPIECEINSIGNAL_EX
#undef __SFC_CELL3BUSY
#undef __SFC_RUNBACKCT8_EX
#undef __SFC_RUNBACKCT9_EX





void GANTRYPROGRAM_init__(GANTRYPROGRAM *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,SENSORCT7_EX,data__->SENSORCT7_EX,retain)
  __INIT_EXTERNAL(BOOL,PUSHUPCT6_EX,data__->PUSHUPCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT7_EX,data__->RUNFRONTCT7_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT8_EX,data__->SENSORCT8_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDUPRIGHTMT6_EX,data__->SENDUPRIGHTMT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDRIGHTUPCT8_EX,data__->SENDRIGHTUPCT8_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT3_EX,data__->RUNFRONTMT3_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT4_EX,data__->RUNFRONTMT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT6_EX,data__->SENSORCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT3_EX,data__->SENSORMT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT4_EX,data__->SENSORMT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT6_EX,data__->SENSORMT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RECEIVEPIECEMT1_EX,data__->RECEIVEPIECEMT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RECEIVEPIECEMT2_EX,data__->RECEIVEPIECEMT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RECEIVEPIECEMT4_EX,data__->RECEIVEPIECEMT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNMT2_EX,data__->SENDDOWNMT2_EX,retain)
  __INIT_LOCATED(BOOL,__IX0_1_0_8,data__->MOUNT,retain)
  __INIT_LOCATED_VALUE(data__->MOUNT,__BOOL_LITERAL(FALSE))
  __INIT_EXTERNAL(BOOL,GANTRYBUSY_EX,data__->GANTRYBUSY_EX,retain)
  __INIT_EXTERNAL(BOOL,PICKPIECE_EX,data__->PICKPIECE_EX,retain)
  __INIT_EXTERNAL(BOOL,RELEASEPIECE_EX,data__->RELEASEPIECE_EX,retain)
  __INIT_EXTERNAL(BOOL,X0Y0_EX,data__->X0Y0_EX,retain)
  __INIT_EXTERNAL(BOOL,X0Y1_EX,data__->X0Y1_EX,retain)
  __INIT_EXTERNAL(BOOL,X0Y2_EX,data__->X0Y2_EX,retain)
  __INIT_EXTERNAL(BOOL,X0Y3_EX,data__->X0Y3_EX,retain)
  __INIT_EXTERNAL(BOOL,X0Y4_EX,data__->X0Y4_EX,retain)
  __INIT_EXTERNAL(BOOL,X1Y0_EX,data__->X1Y0_EX,retain)
  __INIT_EXTERNAL(BOOL,X1Y1_EX,data__->X1Y1_EX,retain)
  __INIT_EXTERNAL(BOOL,X1Y2_EX,data__->X1Y2_EX,retain)
  __INIT_EXTERNAL(BOOL,X1Y3_EX,data__->X1Y3_EX,retain)
  __INIT_EXTERNAL(BOOL,X1Y4_EX,data__->X1Y4_EX,retain)
  __INIT_LOCATED(INT,__IW0_0_2_0,data__->WAREHOUSEIN,retain)
  __INIT_LOCATED_VALUE(data__->WAREHOUSEIN,0)
  __INIT_LOCATED(BOOL,__IX0_0_0_0,data__->SENSORAT1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(INT,__IW0_1_1_2,data__->PM,retain)
  __INIT_LOCATED_VALUE(data__->PM,0)
  __INIT_LOCATED(INT,__IW0_1_1_5,data__->BOTTOMPIECE,retain)
  __INIT_LOCATED_VALUE(data__->BOTTOMPIECE,0)
  __INIT_LOCATED(INT,__IW0_1_1_1,data__->TOPPIECE,retain)
  __INIT_LOCATED_VALUE(data__->TOPPIECE,0)
  __INIT_VAR(data__->PIECETOUNLOAD,0,retain)
  __INIT_LOCATED(BOOL,__QX0_1_0_0,data__->WAREHOUSEBUSY,retain)
  __INIT_LOCATED_VALUE(data__->WAREHOUSEBUSY,__BOOL_LITERAL(FALSE))
  __INIT_EXTERNAL(BOOL,RUNFRONTAT1_EX,data__->RUNFRONTAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT1_EX,data__->RUNFRONTSAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT2_EX,data__->RUNFRONTSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT4_EX,data__->RUNFRONTSAT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT1_EX,data__->RUNFRONTSBT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT2_EX,data__->RUNFRONTSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT4_EX,data__->RUNFRONTSBT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT1_EX,data__->RUNFRONTSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT2_EX,data__->RUNFRONTSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT4_EX,data__->RUNFRONTSCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT1_EX,data__->RUNFRONTMT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT2_EX,data__->RUNFRONTMT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT1_EX,data__->RUNFRONTCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT4_EX,data__->RUNFRONTCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT5_EX,data__->RUNFRONTCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSAT7_EX,data__->RUNBACKSAT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSCT7_EX,data__->RUNBACKSCT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSBT7_EX,data__->RUNBACKSBT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSBT6_EX,data__->RUNBACKSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSAT6_EX,data__->RUNBACKSAT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSAT2_EX,data__->SENDDOWNSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSBT2_EX,data__->SENDDOWNSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSCT2_EX,data__->SENDDOWNSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESAT3_EX,data__->TOOLPIECESAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESAT5_EX,data__->TOOLPIECESAT5_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESBT3_EX,data__->TOOLPIECESBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESBT5_EX,data__->TOOLPIECESBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESCT3_EX,data__->TOOLPIECESCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESCT5_EX,data__->TOOLPIECESCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNCT2_EX,data__->SENDDOWNCT2_EX,retain)
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
  __INIT_EXTERNAL(BOOL,SENSORSBT3_EX,data__->SENSORSBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT4_EX,data__->SENSORSBT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT5_EX,data__->SENSORSBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT6_EX,data__->SENSORSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT7_EX,data__->SENSORSBT7_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT1_EX,data__->SENSORSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT2_EX,data__->SENSORSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT3_EX,data__->SENSORSCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT4_EX,data__->SENSORSCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT5_EX,data__->SENSORSCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT6_EX,data__->SENSORSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT7_EX,data__->SENSORSCT7_EX,retain)
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
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNSBT6_EX,data__->SENDLEFTDOWNSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNSCT6_EX,data__->SENDLEFTDOWNSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,PUTPIECEINSIGNAL_EX,data__->PUTPIECEINSIGNAL_EX,retain)
  REMOVEFROMWAREHOUSE_init__(&data__->REMOVEFROMWAREHOUSE0,retain);
  __INIT_LOCATED(BOOL,__IX0_1_0_1,data__->RUNUNLOAD,retain)
  __INIT_LOCATED_VALUE(data__->RUNUNLOAD,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1_0_2,data__->RUNTRANSFORMMACH1,retain)
  __INIT_LOCATED_VALUE(data__->RUNTRANSFORMMACH1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1_0_3,data__->RUNTRANSFORMMACH2,retain)
  __INIT_LOCATED_VALUE(data__->RUNTRANSFORMMACH2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1_0_4,data__->RUNTRANSFORMMACH3,retain)
  __INIT_LOCATED_VALUE(data__->RUNTRANSFORMMACH3,__BOOL_LITERAL(FALSE))
  __INIT_EXTERNAL(BOOL,READYTOSENDSAT3_EX,data__->READYTOSENDSAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSAT5_EX,data__->READYTOSENDSAT5_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSBT3_EX,data__->READYTOSENDSBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSBT5_EX,data__->READYTOSENDSBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSCT3_EX,data__->READYTOSENDSCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSCT5_EX,data__->READYTOSENDSCT5_EX,retain)
  UINT i;
  data__->__nb_steps = 84;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 25;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 80;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define STEP9 __step_list[0]
#define __SFC_STEP9 0
#define STEP30 __step_list[1]
#define __SFC_STEP30 1
#define STEP12 __step_list[2]
#define __SFC_STEP12 2
#define STEP11 __step_list[3]
#define __SFC_STEP11 3
#define STEP10 __step_list[4]
#define __SFC_STEP10 4
#define STEP13 __step_list[5]
#define __SFC_STEP13 5
#define STEP15 __step_list[6]
#define __SFC_STEP15 6
#define STEP16 __step_list[7]
#define __SFC_STEP16 7
#define STEP17 __step_list[8]
#define __SFC_STEP17 8
#define STEP18 __step_list[9]
#define __SFC_STEP18 9
#define STEP19 __step_list[10]
#define __SFC_STEP19 10
#define STEP20 __step_list[11]
#define __SFC_STEP20 11
#define STEP21 __step_list[12]
#define __SFC_STEP21 12
#define STEP22 __step_list[13]
#define __SFC_STEP22 13
#define STEP23 __step_list[14]
#define __SFC_STEP23 14
#define STEP24 __step_list[15]
#define __SFC_STEP24 15
#define STEP25 __step_list[16]
#define __SFC_STEP25 16
#define STEP26 __step_list[17]
#define __SFC_STEP26 17
#define STEP39 __step_list[18]
#define __SFC_STEP39 18
#define STEP53 __step_list[19]
#define __SFC_STEP53 19
#define STEP54 __step_list[20]
#define __SFC_STEP54 20
#define STEP56 __step_list[21]
#define __SFC_STEP56 21
#define STEP55 __step_list[22]
#define __SFC_STEP55 22
#define STEP59 __step_list[23]
#define __SFC_STEP59 23
#define STEP60 __step_list[24]
#define __SFC_STEP60 24
#define STEP61 __step_list[25]
#define __SFC_STEP61 25
#define STEP62 __step_list[26]
#define __SFC_STEP62 26
#define STEP63 __step_list[27]
#define __SFC_STEP63 27
#define STEP64 __step_list[28]
#define __SFC_STEP64 28
#define STEP88 __step_list[29]
#define __SFC_STEP88 29
#define STEP97 __step_list[30]
#define __SFC_STEP97 30
#define STEP98 __step_list[31]
#define __SFC_STEP98 31
#define STEP91 __step_list[32]
#define __SFC_STEP91 32
#define STEP92 __step_list[33]
#define __SFC_STEP92 33
#define STEP93 __step_list[34]
#define __SFC_STEP93 34
#define STEP94 __step_list[35]
#define __SFC_STEP94 35
#define STEP95 __step_list[36]
#define __SFC_STEP95 36
#define STEP96 __step_list[37]
#define __SFC_STEP96 37
#define STEP65 __step_list[38]
#define __SFC_STEP65 38
#define STEP66 __step_list[39]
#define __SFC_STEP66 39
#define STEP67 __step_list[40]
#define __SFC_STEP67 40
#define STEP68 __step_list[41]
#define __SFC_STEP68 41
#define STEP69 __step_list[42]
#define __SFC_STEP69 42
#define STEP70 __step_list[43]
#define __SFC_STEP70 43
#define STEP71 __step_list[44]
#define __SFC_STEP71 44
#define STEP81 __step_list[45]
#define __SFC_STEP81 45
#define STEP82 __step_list[46]
#define __SFC_STEP82 46
#define STEP72 __step_list[47]
#define __SFC_STEP72 47
#define STEP73 __step_list[48]
#define __SFC_STEP73 48
#define STEP74 __step_list[49]
#define __SFC_STEP74 49
#define STEP75 __step_list[50]
#define __SFC_STEP75 50
#define STEP76 __step_list[51]
#define __SFC_STEP76 51
#define STEP77 __step_list[52]
#define __SFC_STEP77 52
#define STEP79 __step_list[53]
#define __SFC_STEP79 53
#define STEP80 __step_list[54]
#define __SFC_STEP80 54
#define STEP78 __step_list[55]
#define __SFC_STEP78 55
#define STEP58 __step_list[56]
#define __SFC_STEP58 56
#define STEP57 __step_list[57]
#define __SFC_STEP57 57
#define STEP14 __step_list[58]
#define __SFC_STEP14 58
#define SENDTOP __step_list[59]
#define __SFC_SENDTOP 59
#define STEP28 __step_list[60]
#define __SFC_STEP28 60
#define STEP42 __step_list[61]
#define __SFC_STEP42 61
#define STEP41 __step_list[62]
#define __SFC_STEP41 62
#define STEP43 __step_list[63]
#define __SFC_STEP43 63
#define STEP45 __step_list[64]
#define __SFC_STEP45 64
#define STEP29 __step_list[65]
#define __SFC_STEP29 65
#define STEP31 __step_list[66]
#define __SFC_STEP31 66
#define STEP32 __step_list[67]
#define __SFC_STEP32 67
#define STEP33 __step_list[68]
#define __SFC_STEP33 68
#define STEP34 __step_list[69]
#define __SFC_STEP34 69
#define STEP35 __step_list[70]
#define __SFC_STEP35 70
#define STEP36 __step_list[71]
#define __SFC_STEP36 71
#define STEP37 __step_list[72]
#define __SFC_STEP37 72
#define STEP38 __step_list[73]
#define __SFC_STEP38 73
#define STEP40 __step_list[74]
#define __SFC_STEP40 74
#define STEP84 __step_list[75]
#define __SFC_STEP84 75
#define STEP85 __step_list[76]
#define __SFC_STEP85 76
#define STEP86 __step_list[77]
#define __SFC_STEP86 77
#define STEP87 __step_list[78]
#define __SFC_STEP87 78
#define STEP89 __step_list[79]
#define __SFC_STEP89 79
#define STEP90 __step_list[80]
#define __SFC_STEP90 80
#define STEP44 __step_list[81]
#define __SFC_STEP44 81
#define STEP83 __step_list[82]
#define __SFC_STEP83 82
#define STEP0 __step_list[83]
#define __SFC_STEP0 83

// Actions definitions
#define __SFC_ACTION0 0
#define __SFC_UNLOADBOTTOM 1
#define __SFC_UNLOADTOP 2
#define __SFC_WAREHOUSEBUSY 3
#define __SFC_MOUNT 4
#define __SFC_RUNFRONTSAT1_EX 5
#define __SFC_RUNFRONTAT1_EX 6
#define __SFC_RUNFRONTSAT2_EX 7
#define __SFC_RUNFRONTSBT1_EX 8
#define __SFC_RUNFRONTSBT2_EX 9
#define __SFC_RUNFRONTSCT1_EX 10
#define __SFC_RUNFRONTSCT2_EX 11
#define __SFC_RUNFRONTMT1_EX 12
#define __SFC_SENDDOWNMT2_EX 13
#define __SFC_RUNFRONTMT3_EX 14
#define __SFC_RECEIVEPIECEMT4_EX 15
#define __SFC_PICKPIECE_EX 16
#define __SFC_X0Y3_EX 17
#define __SFC_RELEASEPIECE_EX 18
#define __SFC_X1Y3_EX 19
#define __SFC_RUNFRONTMT4_EX 20
#define __SFC_SENDUPRIGHTMT6_EX 21
#define __SFC_RUNFRONTCT7_EX 22
#define __SFC_SENDRIGHTUPCT8_EX 23
#define __SFC_PUSHUPCT6_EX 24

// Code part
void GANTRYPROGRAM_body__(GANTRYPROGRAM *data__) {
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
  if (__GET_VAR(data__->STEP9.X)) {
    __SET_VAR(data__->,__transition_list[0],,(__GET_LOCATED(data__->MOUNT,) && !(__GET_LOCATED(data__->WAREHOUSEBUSY,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,(__GET_LOCATED(data__->MOUNT,) && !(__GET_LOCATED(data__->WAREHOUSEBUSY,))));
    }
    __SET_VAR(data__->,__transition_list[0],,0);
  }
  if (__GET_VAR(data__->STEP30.X)) {
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
  if (__GET_VAR(data__->STEP12.X)) {
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
  if (__GET_VAR(data__->STEP11.X)) {
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
  if (__GET_VAR(data__->STEP10.X)) {
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
  if (__GET_VAR(data__->STEP13.X)) {
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
  if (__GET_VAR(data__->STEP15.X)) {
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
  if (__GET_VAR(data__->STEP16.X)) {
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
  if (__GET_VAR(data__->STEP17.X)) {
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
  if (__GET_VAR(data__->STEP18.X)) {
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
  if (__GET_VAR(data__->STEP19.X)) {
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
  if (__GET_VAR(data__->STEP20.X)) {
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
  if (__GET_VAR(data__->STEP21.X)) {
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
  if (__GET_VAR(data__->STEP22.X)) {
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
  if (__GET_VAR(data__->STEP23.X)) {
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
  if (__GET_VAR(data__->STEP24.X)) {
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
  if (__GET_VAR(data__->STEP25.X)) {
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
  if (__GET_VAR(data__->STEP26.X)) {
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
  if (__GET_VAR(data__->STEP39.X)) {
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
  if (__GET_VAR(data__->STEP53.X)) {
    __SET_VAR(data__->,__transition_list[19],,__GET_EXTERNAL(data__->SENSORMT3_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_VAR(data__->__transition_list[19]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[19],,__GET_EXTERNAL(data__->SENSORMT3_EX,));
    }
    __SET_VAR(data__->,__transition_list[19],,0);
  }
  if (__GET_VAR(data__->STEP54.X)) {
    __SET_VAR(data__->,__transition_list[20],,!(__GET_EXTERNAL(data__->SENSORMT3_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,!(__GET_EXTERNAL(data__->SENSORMT3_EX,)));
    }
    __SET_VAR(data__->,__transition_list[20],,0);
  }
  if (__GET_VAR(data__->STEP56.X)) {
    __SET_VAR(data__->,__transition_list[21],,__GET_EXTERNAL(data__->SENSORMT4_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_VAR(data__->__transition_list[21]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[21],,__GET_EXTERNAL(data__->SENSORMT4_EX,));
    }
    __SET_VAR(data__->,__transition_list[21],,0);
  }
  if (__GET_VAR(data__->STEP55.X) && __GET_VAR(data__->STEP57.X)) {
    __SET_VAR(data__->,__transition_list[22],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,__GET_VAR(data__->__transition_list[22]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[22],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[22],,0);
  }
  if (__GET_VAR(data__->STEP59.X)) {
    __SET_VAR(data__->,__transition_list[23],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_VAR(data__->__transition_list[23]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[23],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    }
    __SET_VAR(data__->,__transition_list[23],,0);
  }
  if (__GET_VAR(data__->STEP60.X)) {
    __SET_VAR(data__->,__transition_list[24],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,__GET_VAR(data__->__transition_list[24]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[24],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[24],,0);
  }
  if (__GET_VAR(data__->STEP61.X)) {
    __SET_VAR(data__->,__transition_list[25],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_VAR(data__->__transition_list[25]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[25],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    }
    __SET_VAR(data__->,__transition_list[25],,0);
  }
  if (__GET_VAR(data__->STEP62.X)) {
    __SET_VAR(data__->,__transition_list[26],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,__GET_VAR(data__->__transition_list[26]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[26],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[26],,0);
  }
  if (__GET_VAR(data__->STEP63.X)) {
    __SET_VAR(data__->,__transition_list[27],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_VAR(data__->__transition_list[27]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[27],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    }
    __SET_VAR(data__->,__transition_list[27],,0);
  }
  if (__GET_VAR(data__->STEP64.X)) {
    __SET_VAR(data__->,__transition_list[28],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,__GET_VAR(data__->__transition_list[28]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[28],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[28],,0);
  }
  if (__GET_VAR(data__->STEP88.X) && __GET_VAR(data__->STEP90.X)) {
    __SET_VAR(data__->,__transition_list[29],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,__GET_VAR(data__->__transition_list[29]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[29],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[29],,0);
  }
  if (__GET_VAR(data__->STEP97.X)) {
    __SET_VAR(data__->,__transition_list[30],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_VAR(data__->__transition_list[30]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[30],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    }
    __SET_VAR(data__->,__transition_list[30],,0);
  }
  if (__GET_VAR(data__->STEP98.X)) {
    __SET_VAR(data__->,__transition_list[31],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,__GET_VAR(data__->__transition_list[31]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[31],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[31],,0);
  }
  if (__GET_VAR(data__->STEP91.X)) {
    __SET_VAR(data__->,__transition_list[32],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_VAR(data__->__transition_list[32]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[32],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    }
    __SET_VAR(data__->,__transition_list[32],,0);
  }
  if (__GET_VAR(data__->STEP92.X)) {
    __SET_VAR(data__->,__transition_list[33],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,__GET_VAR(data__->__transition_list[33]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[33],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[33],,0);
  }
  if (__GET_VAR(data__->STEP93.X)) {
    __SET_VAR(data__->,__transition_list[34],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_VAR(data__->__transition_list[34]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[34],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    }
    __SET_VAR(data__->,__transition_list[34],,0);
  }
  if (__GET_VAR(data__->STEP94.X)) {
    __SET_VAR(data__->,__transition_list[35],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,__GET_VAR(data__->__transition_list[35]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[35],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[35],,0);
  }
  if (__GET_VAR(data__->STEP95.X)) {
    __SET_VAR(data__->,__transition_list[36],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_VAR(data__->__transition_list[36]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[36],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    }
    __SET_VAR(data__->,__transition_list[36],,0);
  }
  if (__GET_VAR(data__->STEP96.X)) {
    __SET_VAR(data__->,__transition_list[37],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,__GET_VAR(data__->__transition_list[37]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[37],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[37],,0);
  }
  if (__GET_VAR(data__->STEP65.X)) {
    __SET_VAR(data__->,__transition_list[38],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_VAR(data__->__transition_list[38]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[38],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    }
    __SET_VAR(data__->,__transition_list[38],,0);
  }
  if (__GET_VAR(data__->STEP66.X)) {
    __SET_VAR(data__->,__transition_list[39],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,__GET_VAR(data__->__transition_list[39]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[39],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[39],,0);
  }
  if (__GET_VAR(data__->STEP67.X)) {
    __SET_VAR(data__->,__transition_list[40],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_VAR(data__->__transition_list[40]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[40],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    }
    __SET_VAR(data__->,__transition_list[40],,0);
  }
  if (__GET_VAR(data__->STEP68.X)) {
    __SET_VAR(data__->,__transition_list[41],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,__GET_VAR(data__->__transition_list[41]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[41],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[41],,0);
  }
  if (__GET_VAR(data__->STEP69.X)) {
    __SET_VAR(data__->,__transition_list[42],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,__GET_VAR(data__->__transition_list[42]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[42],,__GET_EXTERNAL(data__->GANTRYBUSY_EX,));
    }
    __SET_VAR(data__->,__transition_list[42],,0);
  }
  if (__GET_VAR(data__->STEP70.X)) {
    __SET_VAR(data__->,__transition_list[43],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,__GET_VAR(data__->__transition_list[43]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[43],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[43],,0);
  }
  if (__GET_VAR(data__->STEP71.X)) {
    __SET_VAR(data__->,__transition_list[44],,__GET_EXTERNAL(data__->SENSORMT4_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,__GET_VAR(data__->__transition_list[44]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[44],,__GET_EXTERNAL(data__->SENSORMT4_EX,));
    }
    __SET_VAR(data__->,__transition_list[44],,0);
  }
  if (__GET_VAR(data__->STEP81.X)) {
    __SET_VAR(data__->,__transition_list[45],,!(__GET_EXTERNAL(data__->SENSORMT4_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,__GET_VAR(data__->__transition_list[45]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[45],,!(__GET_EXTERNAL(data__->SENSORMT4_EX,)));
    }
    __SET_VAR(data__->,__transition_list[45],,0);
  }
  if (__GET_VAR(data__->STEP82.X)) {
    __SET_VAR(data__->,__transition_list[46],,__GET_EXTERNAL(data__->SENSORMT6_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,__GET_VAR(data__->__transition_list[46]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[46],,__GET_EXTERNAL(data__->SENSORMT6_EX,));
    }
    __SET_VAR(data__->,__transition_list[46],,0);
  }
  if (__GET_VAR(data__->STEP72.X)) {
    __SET_VAR(data__->,__transition_list[47],,!(__GET_EXTERNAL(data__->SENSORMT6_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,__GET_VAR(data__->__transition_list[47]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,!(__GET_EXTERNAL(data__->SENSORMT6_EX,)));
    }
    __SET_VAR(data__->,__transition_list[47],,0);
  }
  if (__GET_VAR(data__->STEP73.X)) {
    __SET_VAR(data__->,__transition_list[48],,__GET_EXTERNAL(data__->SENSORCT7_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,__GET_VAR(data__->__transition_list[48]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[48],,__GET_EXTERNAL(data__->SENSORCT7_EX,));
    }
    __SET_VAR(data__->,__transition_list[48],,0);
  }
  if (__GET_VAR(data__->STEP74.X)) {
    __SET_VAR(data__->,__transition_list[49],,!(__GET_EXTERNAL(data__->SENSORCT7_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,__GET_VAR(data__->__transition_list[49]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[49],,!(__GET_EXTERNAL(data__->SENSORCT7_EX,)));
    }
    __SET_VAR(data__->,__transition_list[49],,0);
  }
  if (__GET_VAR(data__->STEP75.X)) {
    __SET_VAR(data__->,__transition_list[50],,__GET_EXTERNAL(data__->SENSORCT8_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[50],,__GET_VAR(data__->__transition_list[50]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[50],,__GET_EXTERNAL(data__->SENSORCT8_EX,));
    }
    __SET_VAR(data__->,__transition_list[50],,0);
  }
  if (__GET_VAR(data__->STEP76.X)) {
    __SET_VAR(data__->,__transition_list[51],,!(__GET_EXTERNAL(data__->SENSORCT8_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[51],,__GET_VAR(data__->__transition_list[51]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[51],,!(__GET_EXTERNAL(data__->SENSORCT8_EX,)));
    }
    __SET_VAR(data__->,__transition_list[51],,0);
  }
  if (__GET_VAR(data__->STEP77.X)) {
    __SET_VAR(data__->,__transition_list[52],,__GET_EXTERNAL(data__->SENSORCT6_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[52],,__GET_VAR(data__->__transition_list[52]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[52],,__GET_EXTERNAL(data__->SENSORCT6_EX,));
    }
    __SET_VAR(data__->,__transition_list[52],,0);
  }
  if (__GET_VAR(data__->STEP79.X)) {
    __SET_VAR(data__->,__transition_list[53],,!(__GET_EXTERNAL(data__->SENSORCT6_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[53],,__GET_VAR(data__->__transition_list[53]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[53],,!(__GET_EXTERNAL(data__->SENSORCT6_EX,)));
    }
    __SET_VAR(data__->,__transition_list[53],,0);
  }
  if (__GET_VAR(data__->STEP80.X)) {
    __SET_VAR(data__->,__transition_list[54],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[54],,__GET_VAR(data__->__transition_list[54]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[54],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[54],,0);
  }
  if (__GET_VAR(data__->STEP58.X)) {
    __SET_VAR(data__->,__transition_list[55],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[55],,__GET_VAR(data__->__transition_list[55]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[55],,!(__GET_EXTERNAL(data__->GANTRYBUSY_EX,)));
    }
    __SET_VAR(data__->,__transition_list[55],,0);
  }
  if (__GET_VAR(data__->STEP14.X)) {
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
  if (__GET_VAR(data__->SENDTOP.X)) {
    __SET_VAR(data__->,__transition_list[57],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[57],,__GET_VAR(data__->__transition_list[57]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[57],,__GET_EXTERNAL(data__->SENSORAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[57],,0);
  }
  if (__GET_VAR(data__->STEP28.X)) {
    __SET_VAR(data__->,__transition_list[58],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[58],,__GET_VAR(data__->__transition_list[58]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[58],,!(__GET_EXTERNAL(data__->SENSORAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[58],,0);
  }
  if (__GET_VAR(data__->STEP42.X)) {
    __SET_VAR(data__->,__transition_list[59],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[59],,__GET_VAR(data__->__transition_list[59]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[59],,__GET_EXTERNAL(data__->SENSORSAT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[59],,0);
  }
  if (__GET_VAR(data__->STEP41.X)) {
    __SET_VAR(data__->,__transition_list[60],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[60],,__GET_VAR(data__->__transition_list[60]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[60],,!(__GET_EXTERNAL(data__->SENSORSAT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[60],,0);
  }
  if (__GET_VAR(data__->STEP43.X)) {
    __SET_VAR(data__->,__transition_list[61],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[61],,__GET_VAR(data__->__transition_list[61]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[61],,__GET_EXTERNAL(data__->SENSORSAT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[61],,0);
  }
  if (__GET_VAR(data__->STEP45.X)) {
    __SET_VAR(data__->,__transition_list[62],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[62],,__GET_VAR(data__->__transition_list[62]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[62],,!(__GET_EXTERNAL(data__->SENSORSAT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[62],,0);
  }
  if (__GET_VAR(data__->STEP29.X)) {
    __SET_VAR(data__->,__transition_list[63],,__GET_EXTERNAL(data__->SENSORSBT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[63],,__GET_VAR(data__->__transition_list[63]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[63],,__GET_EXTERNAL(data__->SENSORSBT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[63],,0);
  }
  if (__GET_VAR(data__->STEP31.X)) {
    __SET_VAR(data__->,__transition_list[64],,!(__GET_EXTERNAL(data__->SENSORSBT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[64],,__GET_VAR(data__->__transition_list[64]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[64],,!(__GET_EXTERNAL(data__->SENSORSBT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[64],,0);
  }
  if (__GET_VAR(data__->STEP32.X)) {
    __SET_VAR(data__->,__transition_list[65],,__GET_EXTERNAL(data__->SENSORSBT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[65],,__GET_VAR(data__->__transition_list[65]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[65],,__GET_EXTERNAL(data__->SENSORSBT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[65],,0);
  }
  if (__GET_VAR(data__->STEP33.X)) {
    __SET_VAR(data__->,__transition_list[66],,!(__GET_EXTERNAL(data__->SENSORSBT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[66],,__GET_VAR(data__->__transition_list[66]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[66],,!(__GET_EXTERNAL(data__->SENSORSBT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[66],,0);
  }
  if (__GET_VAR(data__->STEP34.X)) {
    __SET_VAR(data__->,__transition_list[67],,__GET_EXTERNAL(data__->SENSORSCT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[67],,__GET_VAR(data__->__transition_list[67]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[67],,__GET_EXTERNAL(data__->SENSORSCT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[67],,0);
  }
  if (__GET_VAR(data__->STEP35.X)) {
    __SET_VAR(data__->,__transition_list[68],,!(__GET_EXTERNAL(data__->SENSORSCT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[68],,__GET_VAR(data__->__transition_list[68]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[68],,!(__GET_EXTERNAL(data__->SENSORSCT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[68],,0);
  }
  if (__GET_VAR(data__->STEP36.X)) {
    __SET_VAR(data__->,__transition_list[69],,__GET_EXTERNAL(data__->SENSORSCT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[69],,__GET_VAR(data__->__transition_list[69]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[69],,__GET_EXTERNAL(data__->SENSORSCT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[69],,0);
  }
  if (__GET_VAR(data__->STEP37.X)) {
    __SET_VAR(data__->,__transition_list[70],,!(__GET_EXTERNAL(data__->SENSORSCT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[70],,__GET_VAR(data__->__transition_list[70]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[70],,!(__GET_EXTERNAL(data__->SENSORSCT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[70],,0);
  }
  if (__GET_VAR(data__->STEP38.X)) {
    __SET_VAR(data__->,__transition_list[71],,__GET_EXTERNAL(data__->SENSORMT1_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[71],,__GET_VAR(data__->__transition_list[71]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[71],,__GET_EXTERNAL(data__->SENSORMT1_EX,));
    }
    __SET_VAR(data__->,__transition_list[71],,0);
  }
  if (__GET_VAR(data__->STEP40.X)) {
    __SET_VAR(data__->,__transition_list[72],,!(__GET_EXTERNAL(data__->SENSORMT1_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[72],,__GET_VAR(data__->__transition_list[72]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[72],,!(__GET_EXTERNAL(data__->SENSORMT1_EX,)));
    }
    __SET_VAR(data__->,__transition_list[72],,0);
  }
  if (__GET_VAR(data__->STEP84.X)) {
    __SET_VAR(data__->,__transition_list[73],,__GET_EXTERNAL(data__->SENSORMT2_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[73],,__GET_VAR(data__->__transition_list[73]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[73],,__GET_EXTERNAL(data__->SENSORMT2_EX,));
    }
    __SET_VAR(data__->,__transition_list[73],,0);
  }
  if (__GET_VAR(data__->STEP85.X)) {
    __SET_VAR(data__->,__transition_list[74],,!(__GET_EXTERNAL(data__->SENSORMT2_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[74],,__GET_VAR(data__->__transition_list[74]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[74],,!(__GET_EXTERNAL(data__->SENSORMT2_EX,)));
    }
    __SET_VAR(data__->,__transition_list[74],,0);
  }
  if (__GET_VAR(data__->STEP86.X)) {
    __SET_VAR(data__->,__transition_list[75],,__GET_EXTERNAL(data__->SENSORMT3_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[75],,__GET_VAR(data__->__transition_list[75]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[75],,__GET_EXTERNAL(data__->SENSORMT3_EX,));
    }
    __SET_VAR(data__->,__transition_list[75],,0);
  }
  if (__GET_VAR(data__->STEP87.X)) {
    __SET_VAR(data__->,__transition_list[76],,!(__GET_EXTERNAL(data__->SENSORMT3_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[76],,__GET_VAR(data__->__transition_list[76]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[76],,!(__GET_EXTERNAL(data__->SENSORMT3_EX,)));
    }
    __SET_VAR(data__->,__transition_list[76],,0);
  }
  if (__GET_VAR(data__->STEP89.X)) {
    __SET_VAR(data__->,__transition_list[77],,__GET_EXTERNAL(data__->SENSORMT4_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[77],,__GET_VAR(data__->__transition_list[77]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[77],,__GET_EXTERNAL(data__->SENSORMT4_EX,));
    }
    __SET_VAR(data__->,__transition_list[77],,0);
  }
  if (__GET_VAR(data__->STEP44.X)) {
    __SET_VAR(data__->,__transition_list[78],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[78],,__GET_VAR(data__->__transition_list[78]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[78],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[78],,0);
  }
  if (__GET_VAR(data__->STEP83.X)) {
    __SET_VAR(data__->,__transition_list[79],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[79],,__GET_VAR(data__->__transition_list[79]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[79],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[79],,0);
  }

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP9.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP30.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP12.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP11.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP10.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP13.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP15.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP16.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP17.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP18.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP19.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP20.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP21.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP22.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP23.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP24.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP25.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP26.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP39.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP53.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP54.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP56.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP55.X,,0);
    __SET_VAR(data__->,STEP57.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP59.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP60.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP61.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP62.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP63.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP64.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP88.X,,0);
    __SET_VAR(data__->,STEP90.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP97.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP98.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,STEP91.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,STEP92.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,STEP93.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,STEP94.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,STEP95.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,STEP96.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,STEP65.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,STEP66.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,STEP67.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,STEP68.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,STEP69.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,STEP70.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,STEP71.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,STEP81.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,STEP82.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,STEP72.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,STEP73.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,STEP74.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[50])) {
    __SET_VAR(data__->,STEP75.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[51])) {
    __SET_VAR(data__->,STEP76.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[52])) {
    __SET_VAR(data__->,STEP77.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[53])) {
    __SET_VAR(data__->,STEP79.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[54])) {
    __SET_VAR(data__->,STEP80.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[55])) {
    __SET_VAR(data__->,STEP58.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[56])) {
    __SET_VAR(data__->,STEP14.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[57])) {
    __SET_VAR(data__->,SENDTOP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[58])) {
    __SET_VAR(data__->,STEP28.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[59])) {
    __SET_VAR(data__->,STEP42.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[60])) {
    __SET_VAR(data__->,STEP41.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[61])) {
    __SET_VAR(data__->,STEP43.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[62])) {
    __SET_VAR(data__->,STEP45.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[63])) {
    __SET_VAR(data__->,STEP29.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[64])) {
    __SET_VAR(data__->,STEP31.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[65])) {
    __SET_VAR(data__->,STEP32.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[66])) {
    __SET_VAR(data__->,STEP33.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[67])) {
    __SET_VAR(data__->,STEP34.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[68])) {
    __SET_VAR(data__->,STEP35.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[69])) {
    __SET_VAR(data__->,STEP36.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[70])) {
    __SET_VAR(data__->,STEP37.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[71])) {
    __SET_VAR(data__->,STEP38.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[72])) {
    __SET_VAR(data__->,STEP40.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[73])) {
    __SET_VAR(data__->,STEP84.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[74])) {
    __SET_VAR(data__->,STEP85.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[75])) {
    __SET_VAR(data__->,STEP86.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[76])) {
    __SET_VAR(data__->,STEP87.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[77])) {
    __SET_VAR(data__->,STEP89.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[78])) {
    __SET_VAR(data__->,STEP44.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[79])) {
    __SET_VAR(data__->,STEP83.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,STEP30.X,,1);
    data__->STEP30.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,STEP12.X,,1);
    data__->STEP12.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,STEP11.X,,1);
    data__->STEP11.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP14.X,,1);
    data__->STEP14.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,STEP10.X,,1);
    data__->STEP10.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP13.X,,1);
    data__->STEP13.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,STEP15.X,,1);
    data__->STEP15.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,STEP16.X,,1);
    data__->STEP16.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,STEP17.X,,1);
    data__->STEP17.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,STEP18.X,,1);
    data__->STEP18.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,STEP19.X,,1);
    data__->STEP19.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,STEP20.X,,1);
    data__->STEP20.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP21.X,,1);
    data__->STEP21.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP22.X,,1);
    data__->STEP22.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,STEP23.X,,1);
    data__->STEP23.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP24.X,,1);
    data__->STEP24.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP25.X,,1);
    data__->STEP25.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[16])) {
    __SET_VAR(data__->,STEP26.X,,1);
    data__->STEP26.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[17])) {
    __SET_VAR(data__->,STEP39.X,,1);
    data__->STEP39.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[18])) {
    __SET_VAR(data__->,STEP53.X,,1);
    data__->STEP53.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[19])) {
    __SET_VAR(data__->,STEP54.X,,1);
    data__->STEP54.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP58.X,,1);
    data__->STEP58.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[20])) {
    __SET_VAR(data__->,STEP56.X,,1);
    data__->STEP56.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[21])) {
    __SET_VAR(data__->,STEP55.X,,1);
    data__->STEP55.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[22])) {
    __SET_VAR(data__->,STEP59.X,,1);
    data__->STEP59.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[23])) {
    __SET_VAR(data__->,STEP60.X,,1);
    data__->STEP60.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[24])) {
    __SET_VAR(data__->,STEP61.X,,1);
    data__->STEP61.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[25])) {
    __SET_VAR(data__->,STEP62.X,,1);
    data__->STEP62.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[26])) {
    __SET_VAR(data__->,STEP63.X,,1);
    data__->STEP63.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[27])) {
    __SET_VAR(data__->,STEP64.X,,1);
    data__->STEP64.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[28])) {
    __SET_VAR(data__->,STEP88.X,,1);
    data__->STEP88.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[29])) {
    __SET_VAR(data__->,STEP97.X,,1);
    data__->STEP97.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[30])) {
    __SET_VAR(data__->,STEP98.X,,1);
    data__->STEP98.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP91.X,,1);
    data__->STEP91.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[32])) {
    __SET_VAR(data__->,STEP92.X,,1);
    data__->STEP92.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[33])) {
    __SET_VAR(data__->,STEP93.X,,1);
    data__->STEP93.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[34])) {
    __SET_VAR(data__->,STEP94.X,,1);
    data__->STEP94.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[35])) {
    __SET_VAR(data__->,STEP95.X,,1);
    data__->STEP95.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[36])) {
    __SET_VAR(data__->,STEP96.X,,1);
    data__->STEP96.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[37])) {
    __SET_VAR(data__->,STEP65.X,,1);
    data__->STEP65.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[38])) {
    __SET_VAR(data__->,STEP66.X,,1);
    data__->STEP66.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[39])) {
    __SET_VAR(data__->,STEP67.X,,1);
    data__->STEP67.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[40])) {
    __SET_VAR(data__->,STEP68.X,,1);
    data__->STEP68.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[41])) {
    __SET_VAR(data__->,STEP69.X,,1);
    data__->STEP69.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[42])) {
    __SET_VAR(data__->,STEP70.X,,1);
    data__->STEP70.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[43])) {
    __SET_VAR(data__->,STEP71.X,,1);
    data__->STEP71.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[44])) {
    __SET_VAR(data__->,STEP81.X,,1);
    data__->STEP81.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[45])) {
    __SET_VAR(data__->,STEP82.X,,1);
    data__->STEP82.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[46])) {
    __SET_VAR(data__->,STEP72.X,,1);
    data__->STEP72.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[47])) {
    __SET_VAR(data__->,STEP73.X,,1);
    data__->STEP73.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[48])) {
    __SET_VAR(data__->,STEP74.X,,1);
    data__->STEP74.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[49])) {
    __SET_VAR(data__->,STEP75.X,,1);
    data__->STEP75.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[50])) {
    __SET_VAR(data__->,STEP76.X,,1);
    data__->STEP76.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[51])) {
    __SET_VAR(data__->,STEP77.X,,1);
    data__->STEP77.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[52])) {
    __SET_VAR(data__->,STEP79.X,,1);
    data__->STEP79.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[53])) {
    __SET_VAR(data__->,STEP80.X,,1);
    data__->STEP80.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[54])) {
    __SET_VAR(data__->,STEP78.X,,1);
    data__->STEP78.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[55])) {
    __SET_VAR(data__->,STEP57.X,,1);
    data__->STEP57.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[56])) {
    __SET_VAR(data__->,SENDTOP.X,,1);
    data__->SENDTOP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[57])) {
    __SET_VAR(data__->,STEP28.X,,1);
    data__->STEP28.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[58])) {
    __SET_VAR(data__->,STEP42.X,,1);
    data__->STEP42.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP44.X,,1);
    data__->STEP44.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[59])) {
    __SET_VAR(data__->,STEP41.X,,1);
    data__->STEP41.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[60])) {
    __SET_VAR(data__->,STEP43.X,,1);
    data__->STEP43.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[61])) {
    __SET_VAR(data__->,STEP45.X,,1);
    data__->STEP45.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[62])) {
    __SET_VAR(data__->,STEP29.X,,1);
    data__->STEP29.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[63])) {
    __SET_VAR(data__->,STEP31.X,,1);
    data__->STEP31.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[64])) {
    __SET_VAR(data__->,STEP32.X,,1);
    data__->STEP32.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[65])) {
    __SET_VAR(data__->,STEP33.X,,1);
    data__->STEP33.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[66])) {
    __SET_VAR(data__->,STEP34.X,,1);
    data__->STEP34.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[67])) {
    __SET_VAR(data__->,STEP35.X,,1);
    data__->STEP35.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[68])) {
    __SET_VAR(data__->,STEP36.X,,1);
    data__->STEP36.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[69])) {
    __SET_VAR(data__->,STEP37.X,,1);
    data__->STEP37.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[70])) {
    __SET_VAR(data__->,STEP38.X,,1);
    data__->STEP38.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[71])) {
    __SET_VAR(data__->,STEP40.X,,1);
    data__->STEP40.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[72])) {
    __SET_VAR(data__->,STEP84.X,,1);
    data__->STEP84.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[73])) {
    __SET_VAR(data__->,STEP85.X,,1);
    data__->STEP85.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[74])) {
    __SET_VAR(data__->,STEP86.X,,1);
    data__->STEP86.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[75])) {
    __SET_VAR(data__->,STEP87.X,,1);
    data__->STEP87.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[76])) {
    __SET_VAR(data__->,STEP89.X,,1);
    data__->STEP89.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[77])) {
    __SET_VAR(data__->,STEP90.X,,1);
    data__->STEP90.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[78])) {
    __SET_VAR(data__->,STEP83.X,,1);
    data__->STEP83.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[79])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // STEP30 action associations
  {
    char active = __GET_VAR(data__->STEP30.X);
    char activated = active && !data__->STEP30.prev_state;
    char desactivated = !active && data__->STEP30.prev_state;

    if (active)       {data__->__action_list[__SFC_ACTION0].set = 1;}

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].set = 1;}

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_UNLOADBOTTOM].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_UNLOADBOTTOM].state,,0);};

    if (active)       {data__->__action_list[__SFC_MOUNT].reset = 1;}

  }

  // STEP12 action associations
  {
    char active = __GET_VAR(data__->STEP12.X);
    char activated = active && !data__->STEP12.prev_state;
    char desactivated = !active && data__->STEP12.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,0);};

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,0);};

  }

  // STEP10 action associations
  {
    char active = __GET_VAR(data__->STEP10.X);
    char activated = active && !data__->STEP10.prev_state;
    char desactivated = !active && data__->STEP10.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,0);};

  }

  // STEP15 action associations
  {
    char active = __GET_VAR(data__->STEP15.X);
    char activated = active && !data__->STEP15.prev_state;
    char desactivated = !active && data__->STEP15.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,0);};

  }

  // STEP17 action associations
  {
    char active = __GET_VAR(data__->STEP17.X);
    char activated = active && !data__->STEP17.prev_state;
    char desactivated = !active && data__->STEP17.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,0);};

  }

  // STEP19 action associations
  {
    char active = __GET_VAR(data__->STEP19.X);
    char activated = active && !data__->STEP19.prev_state;
    char desactivated = !active && data__->STEP19.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,0);};

  }

  // STEP21 action associations
  {
    char active = __GET_VAR(data__->STEP21.X);
    char activated = active && !data__->STEP21.prev_state;
    char desactivated = !active && data__->STEP21.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSCT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSCT2_EX,,0);};

  }

  // STEP23 action associations
  {
    char active = __GET_VAR(data__->STEP23.X);
    char activated = active && !data__->STEP23.prev_state;
    char desactivated = !active && data__->STEP23.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTMT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTMT1_EX,,0);};

  }

  // STEP25 action associations
  {
    char active = __GET_VAR(data__->STEP25.X);
    char activated = active && !data__->STEP25.prev_state;
    char desactivated = !active && data__->STEP25.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SENDDOWNMT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDDOWNMT2_EX,,0);};

  }

  // STEP39 action associations
  {
    char active = __GET_VAR(data__->STEP39.X);
    char activated = active && !data__->STEP39.prev_state;
    char desactivated = !active && data__->STEP39.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTMT3_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTMT3_EX,,0);};

  }

  // STEP54 action associations
  {
    char active = __GET_VAR(data__->STEP54.X);
    char activated = active && !data__->STEP54.prev_state;
    char desactivated = !active && data__->STEP54.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RECEIVEPIECEMT4_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RECEIVEPIECEMT4_EX,,0);};

  }

  // STEP59 action associations
  {
    char active = __GET_VAR(data__->STEP59.X);
    char activated = active && !data__->STEP59.prev_state;
    char desactivated = !active && data__->STEP59.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,PICKPIECE_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,PICKPIECE_EX,,0);};

  }

  // STEP61 action associations
  {
    char active = __GET_VAR(data__->STEP61.X);
    char activated = active && !data__->STEP61.prev_state;
    char desactivated = !active && data__->STEP61.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,X0Y3_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,X0Y3_EX,,0);};

  }

  // STEP63 action associations
  {
    char active = __GET_VAR(data__->STEP63.X);
    char activated = active && !data__->STEP63.prev_state;
    char desactivated = !active && data__->STEP63.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RELEASEPIECE_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RELEASEPIECE_EX,,0);};

  }

  // STEP97 action associations
  {
    char active = __GET_VAR(data__->STEP97.X);
    char activated = active && !data__->STEP97.prev_state;
    char desactivated = !active && data__->STEP97.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,X1Y3_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,X1Y3_EX,,0);};

  }

  // STEP91 action associations
  {
    char active = __GET_VAR(data__->STEP91.X);
    char activated = active && !data__->STEP91.prev_state;
    char desactivated = !active && data__->STEP91.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,PICKPIECE_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,PICKPIECE_EX,,0);};

  }

  // STEP93 action associations
  {
    char active = __GET_VAR(data__->STEP93.X);
    char activated = active && !data__->STEP93.prev_state;
    char desactivated = !active && data__->STEP93.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,X0Y3_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,X0Y3_EX,,0);};

  }

  // STEP95 action associations
  {
    char active = __GET_VAR(data__->STEP95.X);
    char activated = active && !data__->STEP95.prev_state;
    char desactivated = !active && data__->STEP95.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RELEASEPIECE_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RELEASEPIECE_EX,,0);};

  }

  // STEP65 action associations
  {
    char active = __GET_VAR(data__->STEP65.X);
    char activated = active && !data__->STEP65.prev_state;
    char desactivated = !active && data__->STEP65.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,PICKPIECE_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,PICKPIECE_EX,,0);};

  }

  // STEP67 action associations
  {
    char active = __GET_VAR(data__->STEP67.X);
    char activated = active && !data__->STEP67.prev_state;
    char desactivated = !active && data__->STEP67.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,X1Y3_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,X1Y3_EX,,0);};

  }

  // STEP69 action associations
  {
    char active = __GET_VAR(data__->STEP69.X);
    char activated = active && !data__->STEP69.prev_state;
    char desactivated = !active && data__->STEP69.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RELEASEPIECE_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RELEASEPIECE_EX,,0);};

  }

  // STEP71 action associations
  {
    char active = __GET_VAR(data__->STEP71.X);
    char activated = active && !data__->STEP71.prev_state;
    char desactivated = !active && data__->STEP71.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTMT4_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTMT4_EX,,0);};

    if (active)       {__SET_EXTERNAL(data__->,SENDUPRIGHTMT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDUPRIGHTMT6_EX,,0);};

  }

  // STEP73 action associations
  {
    char active = __GET_VAR(data__->STEP73.X);
    char activated = active && !data__->STEP73.prev_state;
    char desactivated = !active && data__->STEP73.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTCT7_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTCT7_EX,,0);};

  }

  // STEP74 action associations
  {
    char active = __GET_VAR(data__->STEP74.X);
    char activated = active && !data__->STEP74.prev_state;
    char desactivated = !active && data__->STEP74.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SENDRIGHTUPCT8_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDRIGHTUPCT8_EX,,0);};

  }

  // STEP77 action associations
  {
    char active = __GET_VAR(data__->STEP77.X);
    char activated = active && !data__->STEP77.prev_state;
    char desactivated = !active && data__->STEP77.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,PUSHUPCT6_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,PUSHUPCT6_EX,,0);};

  }

  // STEP58 action associations
  {
    char active = __GET_VAR(data__->STEP58.X);
    char activated = active && !data__->STEP58.prev_state;
    char desactivated = !active && data__->STEP58.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,X1Y3_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,X1Y3_EX,,0);};

  }

  // STEP14 action associations
  {
    char active = __GET_VAR(data__->STEP14.X);
    char activated = active && !data__->STEP14.prev_state;
    char desactivated = !active && data__->STEP14.prev_state;

    if (active)       {__SET_VAR(data__->,__action_list[__SFC_UNLOADTOP].state,,1);};
    if (desactivated) {__SET_VAR(data__->,__action_list[__SFC_UNLOADTOP].state,,0);};

    if (active)       {data__->__action_list[__SFC_ACTION0].reset = 1;}

  }

  // SENDTOP action associations
  {
    char active = __GET_VAR(data__->SENDTOP.X);
    char activated = active && !data__->SENDTOP.prev_state;
    char desactivated = !active && data__->SENDTOP.prev_state;

    if (active)       {data__->__action_list[__SFC_ACTION0].set = 1;}

  }

  // STEP28 action associations
  {
    char active = __GET_VAR(data__->STEP28.X);
    char activated = active && !data__->STEP28.prev_state;
    char desactivated = !active && data__->STEP28.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT1_EX,,0);};

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTAT1_EX,,0);};

  }

  // STEP41 action associations
  {
    char active = __GET_VAR(data__->STEP41.X);
    char activated = active && !data__->STEP41.prev_state;
    char desactivated = !active && data__->STEP41.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSAT2_EX,,0);};

  }

  // STEP45 action associations
  {
    char active = __GET_VAR(data__->STEP45.X);
    char activated = active && !data__->STEP45.prev_state;
    char desactivated = !active && data__->STEP45.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT1_EX,,0);};

  }

  // STEP31 action associations
  {
    char active = __GET_VAR(data__->STEP31.X);
    char activated = active && !data__->STEP31.prev_state;
    char desactivated = !active && data__->STEP31.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSBT2_EX,,0);};

  }

  // STEP33 action associations
  {
    char active = __GET_VAR(data__->STEP33.X);
    char activated = active && !data__->STEP33.prev_state;
    char desactivated = !active && data__->STEP33.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSCT1_EX,,0);};

  }

  // STEP35 action associations
  {
    char active = __GET_VAR(data__->STEP35.X);
    char activated = active && !data__->STEP35.prev_state;
    char desactivated = !active && data__->STEP35.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTSCT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTSCT2_EX,,0);};

  }

  // STEP37 action associations
  {
    char active = __GET_VAR(data__->STEP37.X);
    char activated = active && !data__->STEP37.prev_state;
    char desactivated = !active && data__->STEP37.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTMT1_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTMT1_EX,,0);};

  }

  // STEP40 action associations
  {
    char active = __GET_VAR(data__->STEP40.X);
    char activated = active && !data__->STEP40.prev_state;
    char desactivated = !active && data__->STEP40.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,SENDDOWNMT2_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,SENDDOWNMT2_EX,,0);};

  }

  // STEP85 action associations
  {
    char active = __GET_VAR(data__->STEP85.X);
    char activated = active && !data__->STEP85.prev_state;
    char desactivated = !active && data__->STEP85.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RUNFRONTMT3_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RUNFRONTMT3_EX,,0);};

  }

  // STEP87 action associations
  {
    char active = __GET_VAR(data__->STEP87.X);
    char activated = active && !data__->STEP87.prev_state;
    char desactivated = !active && data__->STEP87.prev_state;

    if (active)       {__SET_EXTERNAL(data__->,RECEIVEPIECEMT4_EX,,1);};
    if (desactivated) {__SET_EXTERNAL(data__->,RECEIVEPIECEMT4_EX,,0);};

  }

  // STEP44 action associations
  {
    char active = __GET_VAR(data__->STEP44.X);
    char activated = active && !data__->STEP44.prev_state;
    char desactivated = !active && data__->STEP44.prev_state;

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].reset = 1;}

  }

  // STEP83 action associations
  {
    char active = __GET_VAR(data__->STEP83.X);
    char activated = active && !data__->STEP83.prev_state;
    char desactivated = !active && data__->STEP83.prev_state;

    if (active)       {data__->__action_list[__SFC_ACTION0].reset = 1;}

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
    __SET_LOCATED(data__->,WAREHOUSEBUSY,,0);
  }
  else if (data__->__action_list[__SFC_WAREHOUSEBUSY].set) {
    __SET_LOCATED(data__->,WAREHOUSEBUSY,,1);
  }
  if (data__->__action_list[__SFC_MOUNT].reset) {
    __SET_LOCATED(data__->,MOUNT,,0);
  }
  else if (data__->__action_list[__SFC_MOUNT].set) {
    __SET_LOCATED(data__->,MOUNT,,1);
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
  if (data__->__action_list[__SFC_SENDDOWNMT2_EX].reset) {
    __SET_EXTERNAL(data__->,SENDDOWNMT2_EX,,0);
  }
  else if (data__->__action_list[__SFC_SENDDOWNMT2_EX].set) {
    __SET_EXTERNAL(data__->,SENDDOWNMT2_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTMT3_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTMT3_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTMT3_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTMT3_EX,,1);
  }
  if (data__->__action_list[__SFC_RECEIVEPIECEMT4_EX].reset) {
    __SET_EXTERNAL(data__->,RECEIVEPIECEMT4_EX,,0);
  }
  else if (data__->__action_list[__SFC_RECEIVEPIECEMT4_EX].set) {
    __SET_EXTERNAL(data__->,RECEIVEPIECEMT4_EX,,1);
  }
  if (data__->__action_list[__SFC_PICKPIECE_EX].reset) {
    __SET_EXTERNAL(data__->,PICKPIECE_EX,,0);
  }
  else if (data__->__action_list[__SFC_PICKPIECE_EX].set) {
    __SET_EXTERNAL(data__->,PICKPIECE_EX,,1);
  }
  if (data__->__action_list[__SFC_X0Y3_EX].reset) {
    __SET_EXTERNAL(data__->,X0Y3_EX,,0);
  }
  else if (data__->__action_list[__SFC_X0Y3_EX].set) {
    __SET_EXTERNAL(data__->,X0Y3_EX,,1);
  }
  if (data__->__action_list[__SFC_RELEASEPIECE_EX].reset) {
    __SET_EXTERNAL(data__->,RELEASEPIECE_EX,,0);
  }
  else if (data__->__action_list[__SFC_RELEASEPIECE_EX].set) {
    __SET_EXTERNAL(data__->,RELEASEPIECE_EX,,1);
  }
  if (data__->__action_list[__SFC_X1Y3_EX].reset) {
    __SET_EXTERNAL(data__->,X1Y3_EX,,0);
  }
  else if (data__->__action_list[__SFC_X1Y3_EX].set) {
    __SET_EXTERNAL(data__->,X1Y3_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTMT4_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTMT4_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTMT4_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTMT4_EX,,1);
  }
  if (data__->__action_list[__SFC_SENDUPRIGHTMT6_EX].reset) {
    __SET_EXTERNAL(data__->,SENDUPRIGHTMT6_EX,,0);
  }
  else if (data__->__action_list[__SFC_SENDUPRIGHTMT6_EX].set) {
    __SET_EXTERNAL(data__->,SENDUPRIGHTMT6_EX,,1);
  }
  if (data__->__action_list[__SFC_RUNFRONTCT7_EX].reset) {
    __SET_EXTERNAL(data__->,RUNFRONTCT7_EX,,0);
  }
  else if (data__->__action_list[__SFC_RUNFRONTCT7_EX].set) {
    __SET_EXTERNAL(data__->,RUNFRONTCT7_EX,,1);
  }
  if (data__->__action_list[__SFC_SENDRIGHTUPCT8_EX].reset) {
    __SET_EXTERNAL(data__->,SENDRIGHTUPCT8_EX,,0);
  }
  else if (data__->__action_list[__SFC_SENDRIGHTUPCT8_EX].set) {
    __SET_EXTERNAL(data__->,SENDRIGHTUPCT8_EX,,1);
  }
  if (data__->__action_list[__SFC_PUSHUPCT6_EX].reset) {
    __SET_EXTERNAL(data__->,PUSHUPCT6_EX,,0);
  }
  else if (data__->__action_list[__SFC_PUSHUPCT6_EX].set) {
    __SET_EXTERNAL(data__->,PUSHUPCT6_EX,,1);
  }
  if(__GET_VAR(data__->__action_list[__SFC_ACTION0].state)) {
    __SET_VAR(data__->REMOVEFROMWAREHOUSE0.,PIECENUM,,__GET_VAR(data__->PIECETOUNLOAD,));
    __SET_VAR(data__->REMOVEFROMWAREHOUSE0.,SENSORAT1,,__GET_LOCATED(data__->SENSORAT1,));
    REMOVEFROMWAREHOUSE_body__(&data__->REMOVEFROMWAREHOUSE0);
    __SET_LOCATED(data__->,WAREHOUSEIN,,__GET_VAR(data__->REMOVEFROMWAREHOUSE0.WAREHOUSEIN,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_UNLOADBOTTOM].state)) {
    __SET_VAR(data__->,PIECETOUNLOAD,,__GET_LOCATED(data__->BOTTOMPIECE,));
  }

  if(__GET_VAR(data__->__action_list[__SFC_UNLOADTOP].state)) {
    __SET_VAR(data__->,PIECETOUNLOAD,,__GET_LOCATED(data__->TOPPIECE,));
  }



  goto __end;

__end:
  return;
} // GANTRYPROGRAM_body__() 

// Steps undefinitions
#undef STEP9
#undef __SFC_STEP9
#undef STEP30
#undef __SFC_STEP30
#undef STEP12
#undef __SFC_STEP12
#undef STEP11
#undef __SFC_STEP11
#undef STEP10
#undef __SFC_STEP10
#undef STEP13
#undef __SFC_STEP13
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
#undef STEP26
#undef __SFC_STEP26
#undef STEP39
#undef __SFC_STEP39
#undef STEP53
#undef __SFC_STEP53
#undef STEP54
#undef __SFC_STEP54
#undef STEP56
#undef __SFC_STEP56
#undef STEP55
#undef __SFC_STEP55
#undef STEP59
#undef __SFC_STEP59
#undef STEP60
#undef __SFC_STEP60
#undef STEP61
#undef __SFC_STEP61
#undef STEP62
#undef __SFC_STEP62
#undef STEP63
#undef __SFC_STEP63
#undef STEP64
#undef __SFC_STEP64
#undef STEP88
#undef __SFC_STEP88
#undef STEP97
#undef __SFC_STEP97
#undef STEP98
#undef __SFC_STEP98
#undef STEP91
#undef __SFC_STEP91
#undef STEP92
#undef __SFC_STEP92
#undef STEP93
#undef __SFC_STEP93
#undef STEP94
#undef __SFC_STEP94
#undef STEP95
#undef __SFC_STEP95
#undef STEP96
#undef __SFC_STEP96
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
#undef STEP81
#undef __SFC_STEP81
#undef STEP82
#undef __SFC_STEP82
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
#undef STEP79
#undef __SFC_STEP79
#undef STEP80
#undef __SFC_STEP80
#undef STEP78
#undef __SFC_STEP78
#undef STEP58
#undef __SFC_STEP58
#undef STEP57
#undef __SFC_STEP57
#undef STEP14
#undef __SFC_STEP14
#undef SENDTOP
#undef __SFC_SENDTOP
#undef STEP28
#undef __SFC_STEP28
#undef STEP42
#undef __SFC_STEP42
#undef STEP41
#undef __SFC_STEP41
#undef STEP43
#undef __SFC_STEP43
#undef STEP45
#undef __SFC_STEP45
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
#undef STEP40
#undef __SFC_STEP40
#undef STEP84
#undef __SFC_STEP84
#undef STEP85
#undef __SFC_STEP85
#undef STEP86
#undef __SFC_STEP86
#undef STEP87
#undef __SFC_STEP87
#undef STEP89
#undef __SFC_STEP89
#undef STEP90
#undef __SFC_STEP90
#undef STEP44
#undef __SFC_STEP44
#undef STEP83
#undef __SFC_STEP83
#undef STEP0
#undef __SFC_STEP0

// Actions undefinitions
#undef __SFC_ACTION0
#undef __SFC_UNLOADBOTTOM
#undef __SFC_UNLOADTOP
#undef __SFC_WAREHOUSEBUSY
#undef __SFC_MOUNT
#undef __SFC_RUNFRONTSAT1_EX
#undef __SFC_RUNFRONTAT1_EX
#undef __SFC_RUNFRONTSAT2_EX
#undef __SFC_RUNFRONTSBT1_EX
#undef __SFC_RUNFRONTSBT2_EX
#undef __SFC_RUNFRONTSCT1_EX
#undef __SFC_RUNFRONTSCT2_EX
#undef __SFC_RUNFRONTMT1_EX
#undef __SFC_SENDDOWNMT2_EX
#undef __SFC_RUNFRONTMT3_EX
#undef __SFC_RECEIVEPIECEMT4_EX
#undef __SFC_PICKPIECE_EX
#undef __SFC_X0Y3_EX
#undef __SFC_RELEASEPIECE_EX
#undef __SFC_X1Y3_EX
#undef __SFC_RUNFRONTMT4_EX
#undef __SFC_SENDUPRIGHTMT6_EX
#undef __SFC_RUNFRONTCT7_EX
#undef __SFC_SENDRIGHTUPCT8_EX
#undef __SFC_PUSHUPCT6_EX





void UNLOADPROGRAM_init__(UNLOADPROGRAM *data__, BOOL retain) {
  __INIT_EXTERNAL(BOOL,ISLOADINGP1,data__->ISLOADINGP1,retain)
  __INIT_EXTERNAL(INT,PIECENUM,data__->PIECENUM,retain)
  __INIT_EXTERNAL(BOOL,TAKEPIECE,data__->TAKEPIECE,retain)
  __INIT_LOCATED(INT,__IW0_0_2_0,data__->WAREHOUSEIN,retain)
  __INIT_LOCATED_VALUE(data__->WAREHOUSEIN,0)
  __INIT_LOCATED(BOOL,__IX0_0_0_0,data__->SENSORAT1,retain)
  __INIT_LOCATED_VALUE(data__->SENSORAT1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(INT,__IW0_1_1_2,data__->PM,retain)
  __INIT_LOCATED_VALUE(data__->PM,0)
  __INIT_LOCATED(INT,__IW0_1_1_0,data__->INITIALPIECE,retain)
  __INIT_LOCATED_VALUE(data__->INITIALPIECE,0)
  __INIT_LOCATED(INT,__IW0_1_1_3,data__->FINALPIECE,retain)
  __INIT_LOCATED_VALUE(data__->FINALPIECE,0)
  __INIT_LOCATED(BOOL,__IX0_1_0_0,data__->WAREHOUSEBUSY,retain)
  __INIT_LOCATED_VALUE(data__->WAREHOUSEBUSY,__BOOL_LITERAL(FALSE))
  __INIT_EXTERNAL(BOOL,RUNFRONTAT1_EX,data__->RUNFRONTAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT1_EX,data__->RUNFRONTSAT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT2_EX,data__->RUNFRONTSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSAT4_EX,data__->RUNFRONTSAT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT1_EX,data__->RUNFRONTSBT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT2_EX,data__->RUNFRONTSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSBT4_EX,data__->RUNFRONTSBT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT1_EX,data__->RUNFRONTSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT2_EX,data__->RUNFRONTSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTSCT4_EX,data__->RUNFRONTSCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT1_EX,data__->RUNFRONTMT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTMT2_EX,data__->RUNFRONTMT2_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT1_EX,data__->RUNFRONTCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT4_EX,data__->RUNFRONTCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNFRONTCT5_EX,data__->RUNFRONTCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSAT7_EX,data__->RUNBACKSAT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSCT7_EX,data__->RUNBACKSCT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSBT7_EX,data__->RUNBACKSBT7_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSBT6_EX,data__->RUNBACKSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,RUNBACKSAT6_EX,data__->RUNBACKSAT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSAT2_EX,data__->SENDDOWNSAT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSBT2_EX,data__->SENDDOWNSBT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNSCT2_EX,data__->SENDDOWNSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESAT3_EX,data__->TOOLPIECESAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESAT5_EX,data__->TOOLPIECESAT5_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESBT3_EX,data__->TOOLPIECESBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESBT5_EX,data__->TOOLPIECESBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESCT3_EX,data__->TOOLPIECESCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,TOOLPIECESCT5_EX,data__->TOOLPIECESCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDDOWNCT2_EX,data__->SENDDOWNCT2_EX,retain)
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
  __INIT_EXTERNAL(BOOL,SENSORSBT3_EX,data__->SENSORSBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT4_EX,data__->SENSORSBT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT5_EX,data__->SENSORSBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT6_EX,data__->SENSORSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSBT7_EX,data__->SENSORSBT7_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT1_EX,data__->SENSORSCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT2_EX,data__->SENSORSCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT3_EX,data__->SENSORSCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT4_EX,data__->SENSORSCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT5_EX,data__->SENSORSCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT6_EX,data__->SENSORSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORSCT7_EX,data__->SENSORSCT7_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT1_EX,data__->SENSORMT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORMT2_EX,data__->SENSORMT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT1_EX,data__->SENSORCT1_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT2_EX,data__->SENSORCT2_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT3_EX,data__->SENSORCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT4_EX,data__->SENSORCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT5_EX,data__->SENSORCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,SENSORCT6_EX,data__->SENSORCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,PUSHTOROLLCT4_EX,data__->PUSHTOROLLCT4_EX,retain)
  __INIT_EXTERNAL(BOOL,PUSHTOROLLCT5_EX,data__->PUSHTOROLLCT5_EX,retain)
  __INIT_EXTERNAL(BOOL,PUSHTOROLLCT6_EX,data__->PUSHTOROLLCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNSAT6_EX,data__->SENDLEFTDOWNSAT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNSBT6_EX,data__->SENDLEFTDOWNSBT6_EX,retain)
  __INIT_EXTERNAL(BOOL,SENDLEFTDOWNSCT6_EX,data__->SENDLEFTDOWNSCT6_EX,retain)
  __INIT_EXTERNAL(BOOL,PUTPIECEINSIGNAL_EX,data__->PUTPIECEINSIGNAL_EX,retain)
  REMOVEFROMWAREHOUSE_init__(&data__->REMOVEFROMWAREHOUSE0,retain);
  __INIT_LOCATED(BOOL,__IX0_1_0_1,data__->RUNUNLOAD,retain)
  __INIT_LOCATED_VALUE(data__->RUNUNLOAD,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1_0_2,data__->RUNTRANSFORMMACH1,retain)
  __INIT_LOCATED_VALUE(data__->RUNTRANSFORMMACH1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1_0_3,data__->RUNTRANSFORMMACH2,retain)
  __INIT_LOCATED_VALUE(data__->RUNTRANSFORMMACH2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1_0_4,data__->RUNTRANSFORMMACH3,retain)
  __INIT_LOCATED_VALUE(data__->RUNTRANSFORMMACH3,__BOOL_LITERAL(FALSE))
  __INIT_EXTERNAL(BOOL,READYTOSENDSAT3_EX,data__->READYTOSENDSAT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSAT5_EX,data__->READYTOSENDSAT5_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSBT3_EX,data__->READYTOSENDSBT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSBT5_EX,data__->READYTOSENDSBT5_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSCT3_EX,data__->READYTOSENDSCT3_EX,retain)
  __INIT_EXTERNAL(BOOL,READYTOSENDSCT5_EX,data__->READYTOSENDSCT5_EX,retain)
  UINT i;
  data__->__nb_steps = 86;
  static const STEP temp_step = {{0, 0}, 0, {{0, 0}, 0}};
  for(i = 0; i < data__->__nb_steps; i++) {
    data__->__step_list[i] = temp_step;
  }
  __SET_VAR(data__->,__step_list[0].X,,1);
  data__->__nb_actions = 19;
  static const ACTION temp_action = {0, {0, 0}, 0, 0, {0, 0}, {0, 0}};
  for(i = 0; i < data__->__nb_actions; i++) {
    data__->__action_list[i] = temp_action;
  }
  data__->__nb_transitions = 87;
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
#define STEP85 __step_list[27]
#define __SFC_STEP85 27
#define STEP6 __step_list[28]
#define __SFC_STEP6 28
#define STEP47 __step_list[29]
#define __SFC_STEP47 29
#define STEP46 __step_list[30]
#define __SFC_STEP46 30
#define STEP28 __step_list[31]
#define __SFC_STEP28 31
#define STEP27 __step_list[32]
#define __SFC_STEP27 32
#define STEP29 __step_list[33]
#define __SFC_STEP29 33
#define STEP31 __step_list[34]
#define __SFC_STEP31 34
#define STEP32 __step_list[35]
#define __SFC_STEP32 35
#define STEP33 __step_list[36]
#define __SFC_STEP33 36
#define STEP34 __step_list[37]
#define __SFC_STEP34 37
#define STEP35 __step_list[38]
#define __SFC_STEP35 38
#define STEP36 __step_list[39]
#define __SFC_STEP36 39
#define STEP37 __step_list[40]
#define __SFC_STEP37 40
#define STEP38 __step_list[41]
#define __SFC_STEP38 41
#define STEP39 __step_list[42]
#define __SFC_STEP39 42
#define STEP40 __step_list[43]
#define __SFC_STEP40 43
#define STEP41 __step_list[44]
#define __SFC_STEP41 44
#define STEP42 __step_list[45]
#define __SFC_STEP42 45
#define STEP43 __step_list[46]
#define __SFC_STEP43 46
#define STEP44 __step_list[47]
#define __SFC_STEP44 47
#define STEP45 __step_list[48]
#define __SFC_STEP45 48
#define STEP48 __step_list[49]
#define __SFC_STEP48 49
#define STEP49 __step_list[50]
#define __SFC_STEP49 50
#define STEP50 __step_list[51]
#define __SFC_STEP50 51
#define STEP51 __step_list[52]
#define __SFC_STEP51 52
#define STEP53 __step_list[53]
#define __SFC_STEP53 53
#define STEP54 __step_list[54]
#define __SFC_STEP54 54
#define STEP55 __step_list[55]
#define __SFC_STEP55 55
#define STEP30 __step_list[56]
#define __SFC_STEP30 56
#define STEP80 __step_list[57]
#define __SFC_STEP80 57
#define STEP58 __step_list[58]
#define __SFC_STEP58 58
#define STEP57 __step_list[59]
#define __SFC_STEP57 59
#define STEP56 __step_list[60]
#define __SFC_STEP56 60
#define STEP59 __step_list[61]
#define __SFC_STEP59 61
#define STEP61 __step_list[62]
#define __SFC_STEP61 62
#define STEP62 __step_list[63]
#define __SFC_STEP62 63
#define STEP63 __step_list[64]
#define __SFC_STEP63 64
#define STEP64 __step_list[65]
#define __SFC_STEP64 65
#define STEP65 __step_list[66]
#define __SFC_STEP65 66
#define STEP66 __step_list[67]
#define __SFC_STEP66 67
#define STEP67 __step_list[68]
#define __SFC_STEP67 68
#define STEP68 __step_list[69]
#define __SFC_STEP68 69
#define STEP69 __step_list[70]
#define __SFC_STEP69 70
#define STEP70 __step_list[71]
#define __SFC_STEP70 71
#define STEP71 __step_list[72]
#define __SFC_STEP71 72
#define STEP72 __step_list[73]
#define __SFC_STEP72 73
#define STEP73 __step_list[74]
#define __SFC_STEP73 74
#define STEP74 __step_list[75]
#define __SFC_STEP74 75
#define STEP75 __step_list[76]
#define __SFC_STEP75 76
#define STEP76 __step_list[77]
#define __SFC_STEP76 77
#define STEP77 __step_list[78]
#define __SFC_STEP77 78
#define STEP78 __step_list[79]
#define __SFC_STEP78 79
#define STEP79 __step_list[80]
#define __SFC_STEP79 80
#define STEP81 __step_list[81]
#define __SFC_STEP81 81
#define STEP82 __step_list[82]
#define __SFC_STEP82 82
#define STEP83 __step_list[83]
#define __SFC_STEP83 83
#define STEP84 __step_list[84]
#define __SFC_STEP84 84
#define STEP60 __step_list[85]
#define __SFC_STEP60 85

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

// Code part
void UNLOADPROGRAM_body__(UNLOADPROGRAM *data__) {
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
    __SET_VAR(data__->,__transition_list[0],,(__GET_LOCATED(data__->RUNUNLOAD,) && !(__GET_LOCATED(data__->WAREHOUSEBUSY,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,__GET_VAR(data__->__transition_list[0]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[0],,(__GET_LOCATED(data__->RUNUNLOAD,) && !(__GET_LOCATED(data__->WAREHOUSEBUSY,))));
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
    __SET_VAR(data__->,__transition_list[20],,((__GET_EXTERNAL(data__->SENSORCT1_EX,) && !(__GET_EXTERNAL(data__->ISLOADINGP1,))) && !(__GET_EXTERNAL(data__->SENSORCT3_EX,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,__GET_VAR(data__->__transition_list[20]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[20],,((__GET_EXTERNAL(data__->SENSORCT1_EX,) && !(__GET_EXTERNAL(data__->ISLOADINGP1,))) && !(__GET_EXTERNAL(data__->SENSORCT3_EX,))));
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
    __SET_VAR(data__->,__transition_list[47],,((__GET_EXTERNAL(data__->SENSORCT1_EX,) && !(__GET_EXTERNAL(data__->ISLOADINGP1,))) && !(__GET_EXTERNAL(data__->SENSORCT3_EX,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,__GET_VAR(data__->__transition_list[47]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[47],,((__GET_EXTERNAL(data__->SENSORCT1_EX,) && !(__GET_EXTERNAL(data__->ISLOADINGP1,))) && !(__GET_EXTERNAL(data__->SENSORCT3_EX,))));
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
    __SET_VAR(data__->,__transition_list[76],,((__GET_EXTERNAL(data__->SENSORCT1_EX,) && !(__GET_EXTERNAL(data__->ISLOADINGP1,))) && !(__GET_EXTERNAL(data__->SENSORCT3_EX,))));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[76],,__GET_VAR(data__->__transition_list[76]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[76],,((__GET_EXTERNAL(data__->SENSORCT1_EX,) && !(__GET_EXTERNAL(data__->ISLOADINGP1,))) && !(__GET_EXTERNAL(data__->SENSORCT3_EX,))));
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
    __SET_VAR(data__->,__transition_list[84],,__GET_EXTERNAL(data__->SENSORCT6_EX,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[84],,__GET_VAR(data__->__transition_list[84]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[84],,__GET_EXTERNAL(data__->SENSORCT6_EX,));
    }
    __SET_VAR(data__->,__transition_list[84],,0);
  }
  if (__GET_VAR(data__->STEP84.X)) {
    __SET_VAR(data__->,__transition_list[85],,!(__GET_EXTERNAL(data__->SENSORCT6_EX,)));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[85],,__GET_VAR(data__->__transition_list[85]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[85],,!(__GET_EXTERNAL(data__->SENSORCT6_EX,)));
    }
    __SET_VAR(data__->,__transition_list[85],,0);
  }
  if (__GET_VAR(data__->STEP60.X)) {
    __SET_VAR(data__->,__transition_list[86],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[86],,__GET_VAR(data__->__transition_list[86]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[86],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[86],,0);
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
    __SET_VAR(data__->,STEP84.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[86])) {
    __SET_VAR(data__->,STEP60.X,,0);
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
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,STEP3.X,,1);
    data__->STEP3.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP6.X,,1);
    data__->STEP6.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
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
    __SET_VAR(data__->,STEP85.X,,1);
    data__->STEP85.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
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
  }
  if (__GET_VAR(data__->__transition_list[31])) {
    __SET_VAR(data__->,STEP27.X,,1);
    data__->STEP27.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP30.X,,1);
    data__->STEP30.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
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
    __SET_VAR(data__->,STEP85.X,,1);
    data__->STEP85.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
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
  }
  if (__GET_VAR(data__->__transition_list[60])) {
    __SET_VAR(data__->,STEP56.X,,1);
    data__->STEP56.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
    __SET_VAR(data__->,STEP60.X,,1);
    data__->STEP60.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
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
    __SET_VAR(data__->,STEP84.X,,1);
    data__->STEP84.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[85])) {
    __SET_VAR(data__->,STEP85.X,,1);
    data__->STEP85.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[86])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // STEP52 action associations
  {
    char active = __GET_VAR(data__->STEP52.X);
    char activated = active && !data__->STEP52.prev_state;
    char desactivated = !active && data__->STEP52.prev_state;

    if (active)       {data__->__action_list[__SFC_WAREHOUSEBUSY].set = 1;}

    if (active)       {data__->__action_list[__SFC_RUNUNLOAD].reset = 1;}

  }

  // STEP26 action associations
  {
    char active = __GET_VAR(data__->STEP26.X);
    char activated = active && !data__->STEP26.prev_state;
    char desactivated = !active && data__->STEP26.prev_state;

    if (active)       {data__->__action_list[__SFC_ACTION0].set = 1;}

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

  // STEP4 action associations
  {
    char active = __GET_VAR(data__->STEP4.X);
    char activated = active && !data__->STEP4.prev_state;
    char desactivated = !active && data__->STEP4.prev_state;

    if (active)       {data__->__action_list[__SFC_ACTION0].reset = 1;}

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

    if (active)       {data__->__action_list[__SFC_ACTION0].set = 1;}

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

  // STEP28 action associations
  {
    char active = __GET_VAR(data__->STEP28.X);
    char activated = active && !data__->STEP28.prev_state;
    char desactivated = !active && data__->STEP28.prev_state;

    if (active)       {data__->__action_list[__SFC_ACTION0].reset = 1;}

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

    if (active)       {data__->__action_list[__SFC_ACTION0].set = 1;}

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

  // STEP57 action associations
  {
    char active = __GET_VAR(data__->STEP57.X);
    char activated = active && !data__->STEP57.prev_state;
    char desactivated = !active && data__->STEP57.prev_state;

    if (active)       {data__->__action_list[__SFC_ACTION0].reset = 1;}

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
    __SET_LOCATED(data__->,WAREHOUSEBUSY,,0);
  }
  else if (data__->__action_list[__SFC_WAREHOUSEBUSY].set) {
    __SET_LOCATED(data__->,WAREHOUSEBUSY,,1);
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
  if(__GET_VAR(data__->__action_list[__SFC_ACTION0].state)) {
    __SET_VAR(data__->REMOVEFROMWAREHOUSE0.,PIECENUM,,__GET_LOCATED(data__->INITIALPIECE,));
    __SET_VAR(data__->REMOVEFROMWAREHOUSE0.,SENSORAT1,,__GET_LOCATED(data__->SENSORAT1,));
    REMOVEFROMWAREHOUSE_body__(&data__->REMOVEFROMWAREHOUSE0);
    __SET_LOCATED(data__->,WAREHOUSEIN,,__GET_VAR(data__->REMOVEFROMWAREHOUSE0.WAREHOUSEIN,));
  }



  goto __end;

__end:
  return;
} // UNLOADPROGRAM_body__() 

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
#undef STEP85
#undef __SFC_STEP85
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
#undef STEP84
#undef __SFC_STEP84
#undef STEP60
#undef __SFC_STEP60

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





