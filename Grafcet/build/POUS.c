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





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->VAR1,0,retain)
  __INIT_LOCATED(BOOL,__IX0_0_0_0,data__->S0,retain)
  __INIT_LOCATED_VALUE(data__->S0,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_1,data__->S1,retain)
  __INIT_LOCATED_VALUE(data__->S1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0_0_2,data__->S2,retain)
  __INIT_LOCATED_VALUE(data__->S2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_0,data__->A0,retain)
  __INIT_LOCATED_VALUE(data__->A0,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_1,data__->A1,retain)
  __INIT_LOCATED_VALUE(data__->A1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_2,data__->A2,retain)
  __INIT_LOCATED_VALUE(data__->A2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_3,data__->A3,retain)
  __INIT_LOCATED_VALUE(data__->A3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_4,data__->A4,retain)
  __INIT_LOCATED_VALUE(data__->A4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0_1_5,data__->A5,retain)
  __INIT_LOCATED_VALUE(data__->A5,__BOOL_LITERAL(FALSE))
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,VAR1,,1);

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





void ROTARYCONVEYOR_init__(ROTARYCONVEYOR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->BACKSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FRONTNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORBACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORFRONT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ROTATELEFTSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ROTATERIGHTSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DONEROTATERIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DONEROTATELEFT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ROTATERIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ROTATELEFT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ISBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVENEXTBACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVENEXTFRONT,__BOOL_LITERAL(FALSE),retain)
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
  data__->__nb_transitions = 16;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define INITLINEARSTEP0 __step_list[0]
#define __SFC_INITLINEARSTEP0 0
#define MOVEFRONT0 __step_list[1]
#define __SFC_MOVEFRONT0 1
#define WAITFORNOTBUSYFRONT0 __step_list[2]
#define __SFC_WAITFORNOTBUSYFRONT0 2
#define MOVENEXTFRONTSTEP0 __step_list[3]
#define __SFC_MOVENEXTFRONTSTEP0 3
#define TURNOFFFRONT0 __step_list[4]
#define __SFC_TURNOFFFRONT0 4
#define MOVEBACK0 __step_list[5]
#define __SFC_MOVEBACK0 5
#define WAITFORNOTBUSYBACK0 __step_list[6]
#define __SFC_WAITFORNOTBUSYBACK0 6
#define MOVENEXTBACKSTEP0 __step_list[7]
#define __SFC_MOVENEXTBACKSTEP0 7
#define TURNOFFBACK0 __step_list[8]
#define __SFC_TURNOFFBACK0 8
#define ROTATINGRIGHT __step_list[9]
#define __SFC_ROTATINGRIGHT 9
#define STEP0 __step_list[10]
#define __SFC_STEP0 10
#define ROTATINGLEFT __step_list[11]
#define __SFC_ROTATINGLEFT 11
#define STEP1 __step_list[12]
#define __SFC_STEP1 12

// Actions definitions
#define __SFC_ISBUSY 0
#define __SFC_FORWARDMOTOR 1
#define __SFC_MOVENEXTFRONT 2
#define __SFC_BACKMOTOR 3
#define __SFC_MOVENEXTBACK 4
#define __SFC_ROTATERIGHT 5
#define __SFC_ROTATELEFT 6

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
  if (__GET_VAR(data__->INITLINEARSTEP0.X)) {
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
  if (__GET_VAR(data__->WAITFORNOTBUSYFRONT0.X)) {
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
  if (__GET_VAR(data__->MOVENEXTFRONTSTEP0.X)) {
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
  if (__GET_VAR(data__->INITLINEARSTEP0.X)) {
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
  if (__GET_VAR(data__->WAITFORNOTBUSYBACK0.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_VAR(data__->BACKNOTBUSY,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->BACKNOTBUSY,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->MOVENEXTBACKSTEP0.X)) {
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
  if (__GET_VAR(data__->INITLINEARSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[10],,__GET_VAR(data__->ROTATERIGHTSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->__transition_list[10]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[10],,__GET_VAR(data__->ROTATERIGHTSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[10],,0);
  }
  if (__GET_VAR(data__->ROTATINGRIGHT.X)) {
    __SET_VAR(data__->,__transition_list[11],,__GET_VAR(data__->DONEROTATERIGHT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->__transition_list[11]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[11],,__GET_VAR(data__->DONEROTATERIGHT,));
    }
    __SET_VAR(data__->,__transition_list[11],,0);
  }
  if (__GET_VAR(data__->STEP0.X)) {
    __SET_VAR(data__->,__transition_list[12],,__BOOL_LITERAL(TRUE));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__GET_VAR(data__->__transition_list[12]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[12],,__BOOL_LITERAL(TRUE));
    }
    __SET_VAR(data__->,__transition_list[12],,0);
  }
  if (__GET_VAR(data__->INITLINEARSTEP0.X)) {
    __SET_VAR(data__->,__transition_list[13],,__GET_VAR(data__->ROTATELEFTSIGNAL,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->__transition_list[13]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[13],,__GET_VAR(data__->ROTATELEFTSIGNAL,));
    }
    __SET_VAR(data__->,__transition_list[13],,0);
  }
  if (__GET_VAR(data__->ROTATINGLEFT.X)) {
    __SET_VAR(data__->,__transition_list[14],,__GET_VAR(data__->DONEROTATELEFT,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->__transition_list[14]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[14],,__GET_VAR(data__->DONEROTATELEFT,));
    }
    __SET_VAR(data__->,__transition_list[14],,0);
  }
  if (__GET_VAR(data__->STEP1.X)) {
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

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,INITLINEARSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,MOVEFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,WAITFORNOTBUSYFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,MOVENEXTFRONTSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,TURNOFFFRONT0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,INITLINEARSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,MOVEBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,WAITFORNOTBUSYBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,MOVENEXTBACKSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,TURNOFFBACK0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,INITLINEARSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,ROTATINGRIGHT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,STEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,INITLINEARSTEP0.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,ROTATINGLEFT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,STEP1.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,MOVEFRONT0.X,,1);
    data__->MOVEFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,WAITFORNOTBUSYFRONT0.X,,1);
    data__->WAITFORNOTBUSYFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,MOVENEXTFRONTSTEP0.X,,1);
    data__->MOVENEXTFRONTSTEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,TURNOFFFRONT0.X,,1);
    data__->TURNOFFFRONT0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[4])) {
    __SET_VAR(data__->,INITLINEARSTEP0.X,,1);
    data__->INITLINEARSTEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[5])) {
    __SET_VAR(data__->,MOVEBACK0.X,,1);
    data__->MOVEBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[6])) {
    __SET_VAR(data__->,WAITFORNOTBUSYBACK0.X,,1);
    data__->WAITFORNOTBUSYBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,MOVENEXTBACKSTEP0.X,,1);
    data__->MOVENEXTBACKSTEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,TURNOFFBACK0.X,,1);
    data__->TURNOFFBACK0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,INITLINEARSTEP0.X,,1);
    data__->INITLINEARSTEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[10])) {
    __SET_VAR(data__->,ROTATINGRIGHT.X,,1);
    data__->ROTATINGRIGHT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[11])) {
    __SET_VAR(data__->,STEP0.X,,1);
    data__->STEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[12])) {
    __SET_VAR(data__->,INITLINEARSTEP0.X,,1);
    data__->INITLINEARSTEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[13])) {
    __SET_VAR(data__->,ROTATINGLEFT.X,,1);
    data__->ROTATINGLEFT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[14])) {
    __SET_VAR(data__->,STEP1.X,,1);
    data__->STEP1.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[15])) {
    __SET_VAR(data__->,INITLINEARSTEP0.X,,1);
    data__->INITLINEARSTEP0.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }

  // Steps association
  // INITLINEARSTEP0 action associations
  {
    char active = __GET_VAR(data__->INITLINEARSTEP0.X);
    char activated = active && !data__->INITLINEARSTEP0.prev_state;
    char desactivated = !active && data__->INITLINEARSTEP0.prev_state;

    if (active)       {data__->__action_list[__SFC_ISBUSY].reset = 1;}

  }

  // MOVEFRONT0 action associations
  {
    char active = __GET_VAR(data__->MOVEFRONT0.X);
    char activated = active && !data__->MOVEFRONT0.prev_state;
    char desactivated = !active && data__->MOVEFRONT0.prev_state;

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].set = 1;}

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // WAITFORNOTBUSYFRONT0 action associations
  {
    char active = __GET_VAR(data__->WAITFORNOTBUSYFRONT0.X);
    char activated = active && !data__->WAITFORNOTBUSYFRONT0.prev_state;
    char desactivated = !active && data__->WAITFORNOTBUSYFRONT0.prev_state;

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].reset = 1;}

  }

  // MOVENEXTFRONTSTEP0 action associations
  {
    char active = __GET_VAR(data__->MOVENEXTFRONTSTEP0.X);
    char activated = active && !data__->MOVENEXTFRONTSTEP0.prev_state;
    char desactivated = !active && data__->MOVENEXTFRONTSTEP0.prev_state;

    if (active)       {data__->__action_list[__SFC_MOVENEXTFRONT].set = 1;}

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].set = 1;}

  }

  // TURNOFFFRONT0 action associations
  {
    char active = __GET_VAR(data__->TURNOFFFRONT0.X);
    char activated = active && !data__->TURNOFFFRONT0.prev_state;
    char desactivated = !active && data__->TURNOFFFRONT0.prev_state;

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].reset = 1;}

    if (active)       {data__->__action_list[__SFC_ISBUSY].reset = 1;}

  }

  // MOVEBACK0 action associations
  {
    char active = __GET_VAR(data__->MOVEBACK0.X);
    char activated = active && !data__->MOVEBACK0.prev_state;
    char desactivated = !active && data__->MOVEBACK0.prev_state;

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].set = 1;}

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // WAITFORNOTBUSYBACK0 action associations
  {
    char active = __GET_VAR(data__->WAITFORNOTBUSYBACK0.X);
    char activated = active && !data__->WAITFORNOTBUSYBACK0.prev_state;
    char desactivated = !active && data__->WAITFORNOTBUSYBACK0.prev_state;

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].reset = 1;}

  }

  // MOVENEXTBACKSTEP0 action associations
  {
    char active = __GET_VAR(data__->MOVENEXTBACKSTEP0.X);
    char activated = active && !data__->MOVENEXTBACKSTEP0.prev_state;
    char desactivated = !active && data__->MOVENEXTBACKSTEP0.prev_state;

    if (active)       {data__->__action_list[__SFC_MOVENEXTBACK].set = 1;}

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].set = 1;}

  }

  // TURNOFFBACK0 action associations
  {
    char active = __GET_VAR(data__->TURNOFFBACK0.X);
    char activated = active && !data__->TURNOFFBACK0.prev_state;
    char desactivated = !active && data__->TURNOFFBACK0.prev_state;

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].reset = 1;}

    if (active)       {data__->__action_list[__SFC_ISBUSY].reset = 1;}

  }

  // ROTATINGRIGHT action associations
  {
    char active = __GET_VAR(data__->ROTATINGRIGHT.X);
    char activated = active && !data__->ROTATINGRIGHT.prev_state;
    char desactivated = !active && data__->ROTATINGRIGHT.prev_state;

    if (active)       {data__->__action_list[__SFC_ROTATERIGHT].set = 1;}

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // STEP0 action associations
  {
    char active = __GET_VAR(data__->STEP0.X);
    char activated = active && !data__->STEP0.prev_state;
    char desactivated = !active && data__->STEP0.prev_state;

    if (active)       {data__->__action_list[__SFC_ROTATERIGHT].reset = 1;}

    if (active)       {data__->__action_list[__SFC_ISBUSY].reset = 1;}

  }

  // ROTATINGLEFT action associations
  {
    char active = __GET_VAR(data__->ROTATINGLEFT.X);
    char activated = active && !data__->ROTATINGLEFT.prev_state;
    char desactivated = !active && data__->ROTATINGLEFT.prev_state;

    if (active)       {data__->__action_list[__SFC_ROTATELEFT].set = 1;}

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // STEP1 action associations
  {
    char active = __GET_VAR(data__->STEP1.X);
    char activated = active && !data__->STEP1.prev_state;
    char desactivated = !active && data__->STEP1.prev_state;

    if (active)       {data__->__action_list[__SFC_ROTATELEFT].reset = 1;}

    if (active)       {data__->__action_list[__SFC_ISBUSY].reset = 1;}

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
  if (data__->__action_list[__SFC_MOVENEXTFRONT].reset) {
    __SET_VAR(data__->,MOVENEXTFRONT,,0);
  }
  else if (data__->__action_list[__SFC_MOVENEXTFRONT].set) {
    __SET_VAR(data__->,MOVENEXTFRONT,,1);
  }
  if (data__->__action_list[__SFC_BACKMOTOR].reset) {
    __SET_VAR(data__->,BACKMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_BACKMOTOR].set) {
    __SET_VAR(data__->,BACKMOTOR,,1);
  }
  if (data__->__action_list[__SFC_MOVENEXTBACK].reset) {
    __SET_VAR(data__->,MOVENEXTBACK,,0);
  }
  else if (data__->__action_list[__SFC_MOVENEXTBACK].set) {
    __SET_VAR(data__->,MOVENEXTBACK,,1);
  }
  if (data__->__action_list[__SFC_ROTATERIGHT].reset) {
    __SET_VAR(data__->,ROTATERIGHT,,0);
  }
  else if (data__->__action_list[__SFC_ROTATERIGHT].set) {
    __SET_VAR(data__->,ROTATERIGHT,,1);
  }
  if (data__->__action_list[__SFC_ROTATELEFT].reset) {
    __SET_VAR(data__->,ROTATELEFT,,0);
  }
  else if (data__->__action_list[__SFC_ROTATELEFT].set) {
    __SET_VAR(data__->,ROTATELEFT,,1);
  }


  goto __end;

__end:
  return;
} // ROTARYCONVEYOR_body__() 

// Steps undefinitions
#undef INITLINEARSTEP0
#undef __SFC_INITLINEARSTEP0
#undef MOVEFRONT0
#undef __SFC_MOVEFRONT0
#undef WAITFORNOTBUSYFRONT0
#undef __SFC_WAITFORNOTBUSYFRONT0
#undef MOVENEXTFRONTSTEP0
#undef __SFC_MOVENEXTFRONTSTEP0
#undef TURNOFFFRONT0
#undef __SFC_TURNOFFFRONT0
#undef MOVEBACK0
#undef __SFC_MOVEBACK0
#undef WAITFORNOTBUSYBACK0
#undef __SFC_WAITFORNOTBUSYBACK0
#undef MOVENEXTBACKSTEP0
#undef __SFC_MOVENEXTBACKSTEP0
#undef TURNOFFBACK0
#undef __SFC_TURNOFFBACK0
#undef ROTATINGRIGHT
#undef __SFC_ROTATINGRIGHT
#undef STEP0
#undef __SFC_STEP0
#undef ROTATINGLEFT
#undef __SFC_ROTATINGLEFT
#undef STEP1
#undef __SFC_STEP1

// Actions undefinitions
#undef __SFC_ISBUSY
#undef __SFC_FORWARDMOTOR
#undef __SFC_MOVENEXTFRONT
#undef __SFC_BACKMOTOR
#undef __SFC_MOVENEXTBACK
#undef __SFC_ROTATERIGHT
#undef __SFC_ROTATELEFT





void LINEARCONVEYOR_init__(LINEARCONVEYOR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->BACKSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDSIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORFRONT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FRONTNOTBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REACHEDSENSORBACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FORWARDMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BACKMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ISBUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVENEXTBACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVENEXTFRONT,__BOOL_LITERAL(FALSE),retain)
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
  data__->__nb_transitions = 10;
  data__->__lasttick_time = __CURRENT_TIME;
}

// Steps definitions
#define INITLINEARSTEP __step_list[0]
#define __SFC_INITLINEARSTEP 0
#define MOVEFRONT __step_list[1]
#define __SFC_MOVEFRONT 1
#define WAITFORNOTBUSYFRONT __step_list[2]
#define __SFC_WAITFORNOTBUSYFRONT 2
#define MOVENEXTFRONTSTEP __step_list[3]
#define __SFC_MOVENEXTFRONTSTEP 3
#define TURNOFFFRONT __step_list[4]
#define __SFC_TURNOFFFRONT 4
#define MOVEBACK __step_list[5]
#define __SFC_MOVEBACK 5
#define WAITFORNOTBUSYBACK __step_list[6]
#define __SFC_WAITFORNOTBUSYBACK 6
#define MOVENEXTBACKSTEP __step_list[7]
#define __SFC_MOVENEXTBACKSTEP 7
#define TURNOFFBACK __step_list[8]
#define __SFC_TURNOFFBACK 8

// Actions definitions
#define __SFC_ISBUSY 0
#define __SFC_FORWARDMOTOR 1
#define __SFC_MOVENEXTFRONT 2
#define __SFC_BACKMOTOR 3
#define __SFC_MOVENEXTBACK 4

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
  if (__GET_VAR(data__->WAITFORNOTBUSYFRONT.X)) {
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
  if (__GET_VAR(data__->MOVENEXTFRONTSTEP.X)) {
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
  if (__GET_VAR(data__->WAITFORNOTBUSYBACK.X)) {
    __SET_VAR(data__->,__transition_list[7],,__GET_VAR(data__->BACKNOTBUSY,));
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->__transition_list[7]));
    }
  }
  else {
    if (__DEBUG) {
      __SET_VAR(data__->,__debug_transition_list[7],,__GET_VAR(data__->BACKNOTBUSY,));
    }
    __SET_VAR(data__->,__transition_list[7],,0);
  }
  if (__GET_VAR(data__->MOVENEXTBACKSTEP.X)) {
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

  // Transitions reset steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,INITLINEARSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,MOVEFRONT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,WAITFORNOTBUSYFRONT.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[3])) {
    __SET_VAR(data__->,MOVENEXTFRONTSTEP.X,,0);
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
    __SET_VAR(data__->,WAITFORNOTBUSYBACK.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,MOVENEXTBACKSTEP.X,,0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,0);
  }

  // Transitions set steps
  if (__GET_VAR(data__->__transition_list[0])) {
    __SET_VAR(data__->,MOVEFRONT.X,,1);
    data__->MOVEFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[1])) {
    __SET_VAR(data__->,WAITFORNOTBUSYFRONT.X,,1);
    data__->WAITFORNOTBUSYFRONT.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[2])) {
    __SET_VAR(data__->,MOVENEXTFRONTSTEP.X,,1);
    data__->MOVENEXTFRONTSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
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
    __SET_VAR(data__->,WAITFORNOTBUSYBACK.X,,1);
    data__->WAITFORNOTBUSYBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[7])) {
    __SET_VAR(data__->,MOVENEXTBACKSTEP.X,,1);
    data__->MOVENEXTBACKSTEP.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[8])) {
    __SET_VAR(data__->,TURNOFFBACK.X,,1);
    data__->TURNOFFBACK.T.value = __time_to_timespec(1, 0, 0, 0, 0, 0);
  }
  if (__GET_VAR(data__->__transition_list[9])) {
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

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].set = 1;}

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // WAITFORNOTBUSYFRONT action associations
  {
    char active = __GET_VAR(data__->WAITFORNOTBUSYFRONT.X);
    char activated = active && !data__->WAITFORNOTBUSYFRONT.prev_state;
    char desactivated = !active && data__->WAITFORNOTBUSYFRONT.prev_state;

    if (active)       {data__->__action_list[__SFC_FORWARDMOTOR].reset = 1;}

  }

  // MOVENEXTFRONTSTEP action associations
  {
    char active = __GET_VAR(data__->MOVENEXTFRONTSTEP.X);
    char activated = active && !data__->MOVENEXTFRONTSTEP.prev_state;
    char desactivated = !active && data__->MOVENEXTFRONTSTEP.prev_state;

    if (active)       {data__->__action_list[__SFC_MOVENEXTFRONT].set = 1;}

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

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].set = 1;}

    if (active)       {data__->__action_list[__SFC_ISBUSY].set = 1;}

  }

  // WAITFORNOTBUSYBACK action associations
  {
    char active = __GET_VAR(data__->WAITFORNOTBUSYBACK.X);
    char activated = active && !data__->WAITFORNOTBUSYBACK.prev_state;
    char desactivated = !active && data__->WAITFORNOTBUSYBACK.prev_state;

    if (active)       {data__->__action_list[__SFC_BACKMOTOR].reset = 1;}

  }

  // MOVENEXTBACKSTEP action associations
  {
    char active = __GET_VAR(data__->MOVENEXTBACKSTEP.X);
    char activated = active && !data__->MOVENEXTBACKSTEP.prev_state;
    char desactivated = !active && data__->MOVENEXTBACKSTEP.prev_state;

    if (active)       {data__->__action_list[__SFC_MOVENEXTBACK].set = 1;}

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
  if (data__->__action_list[__SFC_MOVENEXTFRONT].reset) {
    __SET_VAR(data__->,MOVENEXTFRONT,,0);
  }
  else if (data__->__action_list[__SFC_MOVENEXTFRONT].set) {
    __SET_VAR(data__->,MOVENEXTFRONT,,1);
  }
  if (data__->__action_list[__SFC_BACKMOTOR].reset) {
    __SET_VAR(data__->,BACKMOTOR,,0);
  }
  else if (data__->__action_list[__SFC_BACKMOTOR].set) {
    __SET_VAR(data__->,BACKMOTOR,,1);
  }
  if (data__->__action_list[__SFC_MOVENEXTBACK].reset) {
    __SET_VAR(data__->,MOVENEXTBACK,,0);
  }
  else if (data__->__action_list[__SFC_MOVENEXTBACK].set) {
    __SET_VAR(data__->,MOVENEXTBACK,,1);
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
#undef WAITFORNOTBUSYFRONT
#undef __SFC_WAITFORNOTBUSYFRONT
#undef MOVENEXTFRONTSTEP
#undef __SFC_MOVENEXTFRONTSTEP
#undef TURNOFFFRONT
#undef __SFC_TURNOFFFRONT
#undef MOVEBACK
#undef __SFC_MOVEBACK
#undef WAITFORNOTBUSYBACK
#undef __SFC_WAITFORNOTBUSYBACK
#undef MOVENEXTBACKSTEP
#undef __SFC_MOVENEXTBACKSTEP
#undef TURNOFFBACK
#undef __SFC_TURNOFFBACK

// Actions undefinitions
#undef __SFC_ISBUSY
#undef __SFC_FORWARDMOTOR
#undef __SFC_MOVENEXTFRONT
#undef __SFC_BACKMOTOR
#undef __SFC_MOVENEXTBACK





