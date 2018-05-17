#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// FUNCTION_BLOCK PYTHON_EVAL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DWORD,STATE)
  __DECLARE_VAR(STRING,BUFFER)
  __DECLARE_VAR(STRING,PREBUFFER)
  __DECLARE_VAR(BOOL,TRIGM1)
  __DECLARE_VAR(BOOL,TRIGGED)

} PYTHON_EVAL;

void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain);
// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__);
// FUNCTION_BLOCK PYTHON_POLL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DWORD,STATE)
  __DECLARE_VAR(STRING,BUFFER)
  __DECLARE_VAR(STRING,PREBUFFER)
  __DECLARE_VAR(BOOL,TRIGM1)
  __DECLARE_VAR(BOOL,TRIGGED)

} PYTHON_POLL;

void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain);
// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__);
// FUNCTION_BLOCK PYTHON_GEAR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(UINT,N)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  PYTHON_EVAL PY_EVAL;
  __DECLARE_VAR(UINT,COUNTER)
  __DECLARE_VAR(UINT,ADD10_OUT)
  __DECLARE_VAR(BOOL,EQ13_OUT)
  __DECLARE_VAR(UINT,SEL15_OUT)
  __DECLARE_VAR(BOOL,AND7_OUT)

} PYTHON_GEAR;

void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain);
// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__);
// FUNCTION_BLOCK GETBOOLSTRING
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,VALUE)
  __DECLARE_VAR(STRING,CODE)

  // FB private variables - TEMP, private and located variables

} GETBOOLSTRING;

void GETBOOLSTRING_init__(GETBOOLSTRING *data__, BOOL retain);
// Code part
void GETBOOLSTRING_body__(GETBOOLSTRING *data__);
// FUNCTION_BLOCK BUTTON
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(STRING,BACK_ID)
  __DECLARE_VAR(STRING,SELE_ID)
  __DECLARE_VAR(BOOL,TOGGLE)
  __DECLARE_VAR(BOOL,SET_STATE)
  __DECLARE_VAR(BOOL,STATE_IN)
  __DECLARE_VAR(BOOL,STATE_OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(STRING,ID)
  PYTHON_EVAL INIT_COMMAND;
  GETBOOLSTRING GETBUTTONSTATE;
  PYTHON_EVAL SETSTATE_COMMAND;
  PYTHON_POLL GETSTATE_COMMAND;
  GETBOOLSTRING GETBUTTONTOGGLE;
  __DECLARE_VAR(STRING,CONCAT2_OUT)
  __DECLARE_VAR(STRING,CONCAT22_OUT)
  __DECLARE_VAR(INT,STRING_TO_INT25_OUT)
  __DECLARE_VAR(BOOL,INT_TO_BOOL26_OUT)
  __DECLARE_VAR(BOOL,AND31_OUT)
  __DECLARE_VAR(STRING,CONCAT7_OUT)

} BUTTON;

void BUTTON_init__(BUTTON *data__, BOOL retain);
// Code part
void BUTTON_body__(BUTTON *data__);
// FUNCTION_BLOCK LED
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(STRING,BACK_ID)
  __DECLARE_VAR(STRING,SELE_ID)
  __DECLARE_VAR(BOOL,STATE_IN)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(STRING,ID)
  PYTHON_EVAL INIT_COMMAND;
  PYTHON_POLL SETSTATE_COMMAND;
  GETBOOLSTRING GETLEDSTATE;
  __DECLARE_VAR(STRING,CONCAT2_OUT)
  __DECLARE_VAR(STRING,CONCAT7_OUT)

} LED;

void LED_init__(LED *data__, BOOL retain);
// Code part
void LED_body__(LED *data__);
// FUNCTION_BLOCK TEXTCTRL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(STRING,BACK_ID)
  __DECLARE_VAR(BOOL,SET_TEXT)
  __DECLARE_VAR(STRING,TEXT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(STRING,ID)
  PYTHON_EVAL SVGUI_TEXTCTRL;
  PYTHON_EVAL SETSTATE_COMMAND;
  __DECLARE_VAR(STRING,CONCAT1_OUT)
  __DECLARE_VAR(BOOL,AND31_OUT)
  __DECLARE_VAR(STRING,CONCAT12_OUT)

} TEXTCTRL;

void TEXTCTRL_init__(TEXTCTRL *data__, BOOL retain);
// Code part
void TEXTCTRL_body__(TEXTCTRL *data__);
// FUNCTION_BLOCK LINEARCONVEYOR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,REACHEDSENSOR)
  __DECLARE_VAR(BOOL,BACKSIGNAL)
  __DECLARE_VAR(BOOL,FORWARDSIGNAL)
  __DECLARE_VAR(BOOL,BACKNOTBUSY)
  __DECLARE_VAR(BOOL,FRONTNOTBUSY)
  __DECLARE_VAR(BOOL,REACHEDSENSORFRONT)
  __DECLARE_VAR(BOOL,REACHEDSENSORBACK)
  __DECLARE_VAR(BOOL,FORWARDMOTOR)
  __DECLARE_VAR(BOOL,BACKMOTOR)
  __DECLARE_VAR(BOOL,ISBUSY)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,FORWARDTIMERON)
  TON TON0;
  TON TON1;
  STEP __step_list[9];
  UINT __nb_steps;
  ACTION __action_list[5];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[12];
  __IEC_BOOL_t __debug_transition_list[12];
  UINT __nb_transitions;
  TIME __lasttick_time;

} LINEARCONVEYOR;

void LINEARCONVEYOR_init__(LINEARCONVEYOR *data__, BOOL retain);
// Code part
void LINEARCONVEYOR_body__(LINEARCONVEYOR *data__);
// FUNCTION_BLOCK ROTARYCONVEYOR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,BACKSIGNAL)
  __DECLARE_VAR(BOOL,FORWARDSIGNAL)
  __DECLARE_VAR(BOOL,READYTORECEIVE)
  __DECLARE_VAR(BOOL,SENDDOWNSIGNAL)
  __DECLARE_VAR(BOOL,SENDLEFTDOWNSIGNAL)
  __DECLARE_VAR(BOOL,SENSORROTRIGHT)
  __DECLARE_VAR(BOOL,SENSORROTLEFT)
  __DECLARE_VAR(BOOL,BACKNOTBUSY)
  __DECLARE_VAR(BOOL,FRONTNOTBUSY)
  __DECLARE_VAR(BOOL,DOWNNOTBUSY)
  __DECLARE_VAR(BOOL,UPNOTBUSY)
  __DECLARE_VAR(BOOL,REACHEDSENSORFRONT)
  __DECLARE_VAR(BOOL,REACHEDSENSOR)
  __DECLARE_VAR(BOOL,REACHEDSENSORDOWN)
  __DECLARE_VAR(BOOL,REACHEDSENSORBACK)
  __DECLARE_VAR(BOOL,REACHEDSENSORUP)
  __DECLARE_VAR(BOOL,FORWARDMOTOR)
  __DECLARE_VAR(BOOL,BACKMOTOR)
  __DECLARE_VAR(BOOL,RIGHTROTMOTOR)
  __DECLARE_VAR(BOOL,LEFTROTMOTOR)
  __DECLARE_VAR(BOOL,ISBUSY)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,FORWARDTIMERON)
  TON TON0;
  TON TON1;
  TON TON2;
  TON TON3;
  STEP __step_list[22];
  UINT __nb_steps;
  ACTION __action_list[9];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[29];
  __IEC_BOOL_t __debug_transition_list[29];
  UINT __nb_transitions;
  TIME __lasttick_time;

} ROTARYCONVEYOR;

void ROTARYCONVEYOR_init__(ROTARYCONVEYOR *data__, BOOL retain);
// Code part
void ROTARYCONVEYOR_body__(ROTARYCONVEYOR *data__);
// FUNCTION_BLOCK WAREHOUSEINCONVEYOR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,REACHEDSENSOR)
  __DECLARE_VAR(BOOL,BACKSIGNAL)
  __DECLARE_VAR(BOOL,WAREHOUSEBUSY)
  __DECLARE_VAR(BOOL,FORWARDSIGNAL)
  __DECLARE_VAR(BOOL,PUTPIECEINSIGNAL)
  __DECLARE_VAR(BOOL,PUTPIECEIN)
  __DECLARE_VAR(BOOL,BACKNOTBUSY)
  __DECLARE_VAR(BOOL,FRONTNOTBUSY)
  __DECLARE_VAR(BOOL,REACHEDSENSORFRONT)
  __DECLARE_VAR(BOOL,REACHEDSENSORBACK)
  __DECLARE_VAR(BOOL,FORWARDMOTOR)
  __DECLARE_VAR(BOOL,BACKMOTOR)
  __DECLARE_VAR(BOOL,ISBUSY)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,FORWARDTIMERON)
  TON TON0;
  TON TON1;
  STEP __step_list[12];
  UINT __nb_steps;
  ACTION __action_list[6];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[16];
  __IEC_BOOL_t __debug_transition_list[16];
  UINT __nb_transitions;
  TIME __lasttick_time;

} WAREHOUSEINCONVEYOR;

void WAREHOUSEINCONVEYOR_init__(WAREHOUSEINCONVEYOR *data__, BOOL retain);
// Code part
void WAREHOUSEINCONVEYOR_body__(WAREHOUSEINCONVEYOR *data__);
// FUNCTION_BLOCK PUSHER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,FORWARDMOTOR)
  __DECLARE_VAR(BOOL,PUSHMOTORFORWARD)
  __DECLARE_VAR(BOOL,PUSHMOTORBACK)
  __DECLARE_VAR(BOOL,BACKMOTOR)
  __DECLARE_VAR(BOOL,ISBUSY)
  __DECLARE_VAR(BOOL,BACKSIGNAL)
  __DECLARE_VAR(BOOL,ROLLBUSY)
  __DECLARE_VAR(BOOL,PUSHSIGNAL)
  __DECLARE_VAR(BOOL,FORWARDSIGNAL)
  __DECLARE_VAR(BOOL,REACHEDSENSOR)
  __DECLARE_VAR(BOOL,REACHEDSENSORBACK)
  __DECLARE_VAR(BOOL,REACHEDSENSORFRONT)
  __DECLARE_VAR(BOOL,SENSORPUSHFORWARD)
  __DECLARE_VAR(BOOL,SENSORPUSHBACK)
  __DECLARE_VAR(BOOL,FRONTNOTBUSY)
  __DECLARE_VAR(BOOL,BACKNOTBUSY)

  // FB private variables - TEMP, private and located variables
  TON TON1;
  TON TON0;
  __DECLARE_VAR(BOOL,FORWARDTIMERON)
  STEP __step_list[13];
  UINT __nb_steps;
  ACTION __action_list[7];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[17];
  __IEC_BOOL_t __debug_transition_list[17];
  UINT __nb_transitions;
  TIME __lasttick_time;

} PUSHER;

void PUSHER_init__(PUSHER *data__, BOOL retain);
// Code part
void PUSHER_body__(PUSHER *data__);
// FUNCTION_BLOCK ROLL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,REACHEDSENSOR)
  __DECLARE_VAR(BOOL,HASPIECE)

  // FB private variables - TEMP, private and located variables
  STEP __step_list[2];
  UINT __nb_steps;
  ACTION __action_list[1];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[2];
  __IEC_BOOL_t __debug_transition_list[2];
  UINT __nb_transitions;
  TIME __lasttick_time;

} ROLL;

void ROLL_init__(ROLL *data__, BOOL retain);
// Code part
void ROLL_body__(ROLL *data__);
// FUNCTION_BLOCK MACHINE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,REACHEDSENSOR)
  __DECLARE_VAR(BOOL,USETOOL)
  __DECLARE_VAR(BOOL,READYTOSEND)
  __DECLARE_VAR(INT,INITIALPIECE)
  __DECLARE_VAR(INT,CURRENTPIECE)
  __DECLARE_VAR(INT,FINALPIECE)
  __DECLARE_VAR(BOOL,NEXTREADYTORECEIVE)
  __DECLARE_VAR(BOOL,TOOLPIECE)
  __DECLARE_VAR(BOOL,TOOLPLUS)
  __DECLARE_VAR(BOOL,TOOLSENSOR)
  __DECLARE_VAR(BOOL,TOOLMINUS)
  __DECLARE_VAR(BOOL,MOTORUP)
  __DECLARE_VAR(BOOL,MOTORLEFT)
  __DECLARE_VAR(BOOL,MOTORDOWN)
  __DECLARE_VAR(BOOL,MOTORRIGHT)
  __DECLARE_VAR(BOOL,SENSORUP)
  __DECLARE_VAR(BOOL,SENSORLEFT)
  __DECLARE_VAR(BOOL,SENSORDOWN)
  __DECLARE_VAR(BOOL,SENSORRIGHT)
  __DECLARE_VAR(BOOL,BACKSIGNAL)
  __DECLARE_VAR(BOOL,FORWARDSIGNAL)
  __DECLARE_VAR(BOOL,BACKNOTBUSY)
  __DECLARE_VAR(BOOL,FRONTNOTBUSY)
  __DECLARE_VAR(BOOL,REACHEDSENSORFRONT)
  __DECLARE_VAR(BOOL,REACHEDSENSORBACK)
  __DECLARE_VAR(BOOL,FORWARDMOTOR)
  __DECLARE_VAR(BOOL,BACKMOTOR)
  __DECLARE_VAR(BOOL,ISBUSY)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TOOLTIMERON)
  __DECLARE_VAR(INT,TOOLNUMBER)
  __DECLARE_VAR(BOOL,TOOLSENSORRE)
  __DECLARE_VAR(BOOL,FORWARDTIMERON)
  TON TON0;
  TON TON1;
  R_TRIG ASD;
  TON TON2;
  TON TON3;
  TON TON4;
  TON TON5;
  TON TON6;
  TON TON7;
  STEP __step_list[44];
  UINT __nb_steps;
  ACTION __action_list[22];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[56];
  __IEC_BOOL_t __debug_transition_list[56];
  UINT __nb_transitions;
  TIME __lasttick_time;

} MACHINE;

void MACHINE_init__(MACHINE *data__, BOOL retain);
// Code part
void MACHINE_body__(MACHINE *data__);
// PROGRAM PROGRAM0
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  LINEARCONVEYOR AT1;
  __DECLARE_EXTERNAL(BOOL,WAREHOUSEBUSY)
  __DECLARE_LOCATED(BOOL,WAREHOUSEBUSYCOMM)
  LINEARCONVEYOR SAT1;
  ROTARYCONVEYOR SAT2;
  LINEARCONVEYOR SBT1;
  __DECLARE_EXTERNAL(BOOL,SENSORAT1_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORAT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSAT1_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSAT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSAT3_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSAT4_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSAT5_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSAT6_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSAT7_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSBT1_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSBT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSCT1_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSCT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSCT7_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORMT1_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORMT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORCT1_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORCT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORCT3_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORCT4_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORCT6_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORCT5_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORCT7_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORCT8_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORCT9_EX)
  __DECLARE_EXTERNAL(BOOL,RUNBACKAT2_EX)
  __DECLARE_EXTERNAL(BOOL,RUNBACKSAT7_EX)
  __DECLARE_EXTERNAL(BOOL,RUNBACKSAT6_EX)
  __DECLARE_EXTERNAL(BOOL,RUNBACKSCT7_EX)
  __DECLARE_EXTERNAL(BOOL,RUNBACKCT7_EX)
  __DECLARE_EXTERNAL(BOOL,RUNBACKCT8_EX)
  __DECLARE_EXTERNAL(BOOL,RUNBACKCT9_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTAT1_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSAT1_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSAT2_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSAT3_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSAT4_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSAT5_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSBT1_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSBT2_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSCT1_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSCT2_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTMT1_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTMT2_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTCT1_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTCT2_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTCT3_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTCT4_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTCT5_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTCT6_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTCT8_EX)
  __DECLARE_EXTERNAL(BOOL,RUNBACKCT2_EX)
  __DECLARE_EXTERNAL(BOOL,RUNBACKCT3_EX)
  __DECLARE_EXTERNAL(BOOL,SENDDOWNSAT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENDDOWNSBT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENDDOWNSCT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENDDOWNMT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENDDOWNCT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENDDOWNCT8_EX)
  __DECLARE_EXTERNAL(BOOL,SENDLEFTDOWNSAT6_EX)
  ROTARYCONVEYOR SBT2;
  __DECLARE_LOCATED(BOOL,BACKAT1)
  __DECLARE_LOCATED(BOOL,BACKAT2)
  __DECLARE_LOCATED(BOOL,BACKSAT2)
  __DECLARE_LOCATED(BOOL,BACKSAT6)
  __DECLARE_LOCATED(BOOL,BACKSBT2)
  __DECLARE_LOCATED(BOOL,BACKSBT6)
  __DECLARE_LOCATED(BOOL,BACKSCT2)
  __DECLARE_LOCATED(BOOL,BACKSCT6)
  __DECLARE_LOCATED(BOOL,BACKMT2)
  __DECLARE_LOCATED(BOOL,BACKMT6)
  __DECLARE_LOCATED(BOOL,BACKCT2)
  __DECLARE_LOCATED(BOOL,BACKCT8)
  __DECLARE_LOCATED(BOOL,BACKCT4)
  __DECLARE_LOCATED(BOOL,BACKCT5)
  __DECLARE_LOCATED(BOOL,BACKCT6)
  __DECLARE_LOCATED(BOOL,BACKSAT3)
  __DECLARE_LOCATED(BOOL,BACKSAT5)
  __DECLARE_LOCATED(BOOL,BACKSBT3)
  __DECLARE_LOCATED(BOOL,BACKSBT5)
  __DECLARE_LOCATED(BOOL,BACKSCT3)
  __DECLARE_LOCATED(BOOL,BACKSCT5)
  __DECLARE_LOCATED(BOOL,BACKSAT1)
  __DECLARE_LOCATED(BOOL,BACKSAT4)
  __DECLARE_LOCATED(BOOL,BACKSAT7)
  __DECLARE_LOCATED(BOOL,BACKSBT1)
  __DECLARE_LOCATED(BOOL,BACKSBT4)
  __DECLARE_LOCATED(BOOL,BACKSBT7)
  __DECLARE_LOCATED(BOOL,BACKSCT1)
  __DECLARE_LOCATED(BOOL,BACKSCT4)
  __DECLARE_LOCATED(BOOL,BACKSCT7)
  __DECLARE_LOCATED(BOOL,BACKMT1)
  __DECLARE_LOCATED(BOOL,BACKMT3)
  __DECLARE_LOCATED(BOOL,BACKMT4)
  __DECLARE_LOCATED(BOOL,BACKMT5)
  __DECLARE_LOCATED(BOOL,BACKCT1)
  __DECLARE_LOCATED(BOOL,BACKCT3)
  __DECLARE_LOCATED(BOOL,BACKCT7)
  __DECLARE_LOCATED(BOOL,BACKCT9)
  __DECLARE_LOCATED(BOOL,SENSORAT1)
  __DECLARE_LOCATED(BOOL,SENSORAT2)
  __DECLARE_LOCATED(BOOL,SENSORMM1)
  __DECLARE_LOCATED(BOOL,SENSORMM2)
  __DECLARE_LOCATED(BOOL,SENSORMM3)
  __DECLARE_LOCATED(BOOL,SENSORSAT2)
  __DECLARE_LOCATED(BOOL,SENSORSAT6)
  __DECLARE_LOCATED(BOOL,SENSORSBT2)
  __DECLARE_LOCATED(BOOL,SENSORSBT6)
  __DECLARE_LOCATED(BOOL,SENSORSCT2)
  __DECLARE_LOCATED(BOOL,SENSORSCT6)
  __DECLARE_LOCATED(BOOL,SENSORMT2)
  __DECLARE_LOCATED(BOOL,SENSORMT6)
  __DECLARE_LOCATED(BOOL,SENSORCT2)
  __DECLARE_LOCATED(BOOL,SENSORCT8)
  __DECLARE_LOCATED(BOOL,SENSORPM1)
  __DECLARE_LOCATED(BOOL,SENSORPM2)
  __DECLARE_LOCATED(BOOL,SENSORPM3)
  __DECLARE_LOCATED(BOOL,SENSORCT4)
  __DECLARE_LOCATED(BOOL,SENSORCT5)
  __DECLARE_LOCATED(BOOL,SENSORCT6)
  __DECLARE_LOCATED(BOOL,SENSORSAT3)
  __DECLARE_LOCATED(BOOL,SENSORSAT5)
  __DECLARE_LOCATED(BOOL,SENSORSBT3)
  __DECLARE_LOCATED(BOOL,SENSORSBT5)
  __DECLARE_LOCATED(BOOL,SENSORSCT3)
  __DECLARE_LOCATED(BOOL,SENSORSCT5)
  __DECLARE_LOCATED(BOOL,SENSORSAT1)
  __DECLARE_LOCATED(BOOL,SENSORSAT4)
  __DECLARE_LOCATED(BOOL,SENSORSAT7)
  __DECLARE_LOCATED(BOOL,SENSORSBT1)
  __DECLARE_LOCATED(BOOL,SENSORSBT4)
  __DECLARE_LOCATED(BOOL,SENSORSBT7)
  __DECLARE_LOCATED(BOOL,SENSORSCT1)
  __DECLARE_LOCATED(BOOL,SENSORSCT4)
  __DECLARE_LOCATED(BOOL,SENSORSCT7)
  __DECLARE_LOCATED(BOOL,SENSORMT1)
  __DECLARE_LOCATED(BOOL,SENSORMT3)
  __DECLARE_LOCATED(BOOL,SENSORMT4)
  __DECLARE_LOCATED(BOOL,SENSORMT5)
  __DECLARE_LOCATED(BOOL,SENSORCT1)
  __DECLARE_LOCATED(BOOL,SENSORCT3)
  __DECLARE_LOCATED(BOOL,SENSORCT7)
  __DECLARE_LOCATED(BOOL,SENSORCT9)
  __DECLARE_LOCATED(BOOL,PUSHFORWARDCT4)
  __DECLARE_LOCATED(BOOL,PUSHFORWARDCT5)
  __DECLARE_LOCATED(BOOL,PUSHFORWARDCT6)
  __DECLARE_LOCATED(BOOL,SENSORPUSHFORWARDCT4)
  __DECLARE_LOCATED(BOOL,SENSORPUSHFORWARDCT5)
  __DECLARE_LOCATED(BOOL,SENSORPUSHFORWARDCT6)
  __DECLARE_LOCATED(BOOL,PUSHBACKCT4)
  __DECLARE_LOCATED(BOOL,PUSHBACKCT5)
  __DECLARE_LOCATED(BOOL,PUSHBACKCT6)
  __DECLARE_LOCATED(BOOL,SENSORPUSHBACKCT4)
  __DECLARE_LOCATED(BOOL,SENSORPUSHBACKCT5)
  __DECLARE_LOCATED(BOOL,SENSORPUSHBACKCT6)
  __DECLARE_LOCATED(BOOL,FORWARDAT1)
  __DECLARE_LOCATED(BOOL,FORWARDAT2)
  __DECLARE_LOCATED(BOOL,FORWARDSAT2)
  __DECLARE_LOCATED(BOOL,FORWARDSAT6)
  __DECLARE_LOCATED(BOOL,FORWARDSBT2)
  __DECLARE_LOCATED(BOOL,FORWARDSBT6)
  __DECLARE_LOCATED(BOOL,FORWARDSCT2)
  __DECLARE_LOCATED(BOOL,FORWARDSCT6)
  __DECLARE_LOCATED(BOOL,FORWARDMT2)
  __DECLARE_LOCATED(BOOL,FORWARDMT6)
  __DECLARE_LOCATED(BOOL,FORWARDCT2)
  __DECLARE_LOCATED(BOOL,FORWARDCT8)
  __DECLARE_LOCATED(BOOL,FORWARDCT4)
  __DECLARE_LOCATED(BOOL,FORWARDCT5)
  __DECLARE_LOCATED(BOOL,FORWARDCT6)
  __DECLARE_LOCATED(BOOL,FORWARDSAT3)
  __DECLARE_LOCATED(BOOL,FORWARDSAT5)
  __DECLARE_LOCATED(BOOL,FORWARDSBT3)
  __DECLARE_LOCATED(BOOL,FORWARDSBT5)
  __DECLARE_LOCATED(BOOL,FORWARDSCT3)
  __DECLARE_LOCATED(BOOL,FORWARDSCT5)
  __DECLARE_LOCATED(BOOL,FORWARDSAT1)
  __DECLARE_LOCATED(BOOL,FORWARDSAT4)
  __DECLARE_LOCATED(BOOL,FORWARDSAT7)
  __DECLARE_LOCATED(BOOL,FORWARDSBT1)
  __DECLARE_LOCATED(BOOL,FORWARDSBT4)
  __DECLARE_LOCATED(BOOL,FORWARDSBT7)
  __DECLARE_LOCATED(BOOL,FORWARDSCT1)
  __DECLARE_LOCATED(BOOL,FORWARDSCT4)
  __DECLARE_LOCATED(BOOL,FORWARDSCT7)
  __DECLARE_LOCATED(BOOL,FORWARDMT1)
  __DECLARE_LOCATED(BOOL,FORWARDMT3)
  __DECLARE_LOCATED(BOOL,FORWARDMT4)
  __DECLARE_LOCATED(BOOL,FORWARDMT5)
  __DECLARE_LOCATED(BOOL,FORWARDCT1)
  __DECLARE_LOCATED(BOOL,FORWARDCT3)
  __DECLARE_LOCATED(BOOL,FORWARDCT7)
  __DECLARE_LOCATED(BOOL,FORWARDCT9)
  __DECLARE_LOCATED(BOOL,SENSORROTRIGHTSAT2)
  __DECLARE_LOCATED(BOOL,SENSORROTRIGHTSAT6)
  __DECLARE_LOCATED(BOOL,SENSORROTRIGHTSBT2)
  __DECLARE_LOCATED(BOOL,SENSORROTRIGHTSBT6)
  __DECLARE_LOCATED(BOOL,SENSORROTRIGHTSCT2)
  __DECLARE_LOCATED(BOOL,SENSORROTRIGHTSCT6)
  __DECLARE_LOCATED(BOOL,SENSORROTRIGHTMT2)
  __DECLARE_LOCATED(BOOL,SENSORROTRIGHTMT6)
  __DECLARE_LOCATED(BOOL,SENSORROTRIGHTCT2)
  __DECLARE_LOCATED(BOOL,SENSORROTRIGHTCT8)
  __DECLARE_LOCATED(BOOL,SENSORROTLEFTSAT2)
  __DECLARE_LOCATED(BOOL,SENSORROTLEFTSAT6)
  __DECLARE_LOCATED(BOOL,SENSORROTLEFTSBT2)
  __DECLARE_LOCATED(BOOL,SENSORROTLEFTSBT6)
  __DECLARE_LOCATED(BOOL,SENSORROTLEFTSCT2)
  __DECLARE_LOCATED(BOOL,SENSORROTLEFTSCT6)
  __DECLARE_LOCATED(BOOL,SENSORROTLEFTMT2)
  __DECLARE_LOCATED(BOOL,SENSORROTLEFTMT6)
  __DECLARE_LOCATED(BOOL,SENSORROTLEFTCT2)
  __DECLARE_LOCATED(BOOL,SENSORROTLEFTCT8)
  __DECLARE_LOCATED(BOOL,RIGHTROTSAT2)
  __DECLARE_LOCATED(BOOL,RIGHTROTSAT6)
  __DECLARE_LOCATED(BOOL,RIGHTROTSBT2)
  __DECLARE_LOCATED(BOOL,RIGHTROTSBT6)
  __DECLARE_LOCATED(BOOL,RIGHTROTSCT2)
  __DECLARE_LOCATED(BOOL,RIGHTROTSCT6)
  __DECLARE_LOCATED(BOOL,RIGHTROTMT2)
  __DECLARE_LOCATED(BOOL,RIGHTROTMT6)
  __DECLARE_LOCATED(BOOL,RIGHTROTCT2)
  __DECLARE_LOCATED(BOOL,RIGHTROTCT8)
  __DECLARE_LOCATED(BOOL,LEFTROTSAT2)
  __DECLARE_LOCATED(BOOL,LEFTROTSAT6)
  __DECLARE_LOCATED(BOOL,LEFTROTSBT2)
  __DECLARE_LOCATED(BOOL,LEFTROTSBT6)
  __DECLARE_LOCATED(BOOL,LEFTROTSCT2)
  __DECLARE_LOCATED(BOOL,LEFTROTSCT6)
  __DECLARE_LOCATED(BOOL,LEFTROTMT2)
  __DECLARE_LOCATED(BOOL,LEFTROTMT6)
  __DECLARE_LOCATED(BOOL,LEFTROTCT2)
  __DECLARE_LOCATED(BOOL,LEFTROTCT8)
  LINEARCONVEYOR SCT1;
  ROTARYCONVEYOR SCT2;
  LINEARCONVEYOR MT1;
  ROTARYCONVEYOR MT2;
  LINEARCONVEYOR CT1;
  ROTARYCONVEYOR CT2;
  LINEARCONVEYOR CT3;
  WAREHOUSEINCONVEYOR AT2;
  LINEARCONVEYOR SAT7;
  LINEARCONVEYOR SBT7;
  ROTARYCONVEYOR SBT6;
  LINEARCONVEYOR SCT7;
  ROTARYCONVEYOR SAT6;
  ROTARYCONVEYOR SCT6;
  LINEARCONVEYOR MT5;
  ROTARYCONVEYOR MT6;
  LINEARCONVEYOR CT7;
  ROTARYCONVEYOR CT8;
  LINEARCONVEYOR CT9;
  __DECLARE_EXTERNAL(BOOL,SENDUPSAT6_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSBT7_EX)
  __DECLARE_EXTERNAL(BOOL,RUNBACKSBT7_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSBT6_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSBT6_EX)
  __DECLARE_EXTERNAL(BOOL,SENDDOWNSBT6_EX)
  __DECLARE_EXTERNAL(BOOL,SENDDOWNSAT6_EX)
  __DECLARE_EXTERNAL(BOOL,RUNBACKSBT6_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSCT6_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSCT6_EX)
  __DECLARE_EXTERNAL(BOOL,RUNBACKSCT6_EX)
  __DECLARE_EXTERNAL(BOOL,RUNBACKMT6_EX)
  __DECLARE_EXTERNAL(BOOL,SENDDOWNSCT6_EX)
  __DECLARE_EXTERNAL(BOOL,SENDDOWNMT6_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORMT5_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORMT6_EX)
  __DECLARE_EXTERNAL(BOOL,RUNBACKMT5_EX)
  __DECLARE_EXTERNAL(BOOL,PUSHTOROLLCT4_EX)
  __DECLARE_EXTERNAL(BOOL,PUSHTOROLLCT5_EX)
  __DECLARE_EXTERNAL(BOOL,PUSHTOROLLCT6_EX)
  PUSHER CT4;
  PUSHER CT5;
  PUSHER CT6;
  ROLL PM1;
  ROLL PM2;
  ROLL PM3;
  MACHINE SAT3;
  __DECLARE_LOCATED(BOOL,TOOLSENSORSAT3)
  __DECLARE_LOCATED(BOOL,TOOLSENSORSAT5)
  __DECLARE_LOCATED(BOOL,TOOLSENSORSBT3)
  __DECLARE_LOCATED(BOOL,TOOLSENSORSBT5)
  __DECLARE_LOCATED(BOOL,TOOLSENSORSCT3)
  __DECLARE_LOCATED(BOOL,TOOLSENSORSCT5)
  __DECLARE_LOCATED(BOOL,XRIGHTSAT3)
  __DECLARE_LOCATED(BOOL,WAREHOUSEIN)
  __DECLARE_LOCATED(BOOL,XLEFTSAT3)
  __DECLARE_LOCATED(BOOL,ZUPSAT3)
  __DECLARE_LOCATED(BOOL,ZDOWNSAT3)
  __DECLARE_LOCATED(BOOL,XRIGHTSAT5)
  __DECLARE_LOCATED(BOOL,XLEFTSAT5)
  __DECLARE_LOCATED(BOOL,ZUPSAT5)
  __DECLARE_LOCATED(BOOL,ZDOWNSAT5)
  __DECLARE_LOCATED(BOOL,XRIGHTSBT3)
  __DECLARE_LOCATED(BOOL,XLEFTSBT3)
  __DECLARE_LOCATED(BOOL,ZUPSBT3)
  __DECLARE_LOCATED(BOOL,ZDOWNSBT3)
  __DECLARE_LOCATED(BOOL,XRIGHTSBT5)
  __DECLARE_LOCATED(BOOL,XLEFTSBT5)
  __DECLARE_LOCATED(BOOL,ZUPSBT5)
  __DECLARE_LOCATED(BOOL,ZDOWNSBT5)
  __DECLARE_LOCATED(BOOL,XRIGHTSCT3)
  __DECLARE_LOCATED(BOOL,XLEFTSCT3)
  __DECLARE_LOCATED(BOOL,ZUPSCT3)
  __DECLARE_LOCATED(BOOL,ZDOWNSCT3)
  __DECLARE_LOCATED(BOOL,XRIGHTSCT5)
  __DECLARE_LOCATED(BOOL,XLEFTSCT5)
  __DECLARE_LOCATED(BOOL,ZUPSCT5)
  __DECLARE_LOCATED(BOOL,ZDOWNSCT5)
  __DECLARE_LOCATED(BOOL,TOOLMINUSSAT3)
  __DECLARE_LOCATED(BOOL,TOOLPLUSSAT3)
  __DECLARE_LOCATED(BOOL,TOOLMINUSSAT5)
  __DECLARE_LOCATED(BOOL,TOOLPLUSSAT5)
  __DECLARE_LOCATED(BOOL,TOOLMINUSSBT3)
  __DECLARE_LOCATED(BOOL,TOOLPLUSSBT3)
  __DECLARE_LOCATED(BOOL,TOOLMINUSSBT5)
  __DECLARE_LOCATED(BOOL,TOOLPLUSSBT5)
  __DECLARE_LOCATED(BOOL,TOOLMINUSSCT3)
  __DECLARE_LOCATED(BOOL,TOOLPLUSSCT3)
  __DECLARE_LOCATED(BOOL,TOOLMINUSSCT5)
  __DECLARE_LOCATED(BOOL,TOOLPLUSSCT5)
  __DECLARE_LOCATED(BOOL,TOOLUPSENSORSAT3)
  __DECLARE_LOCATED(BOOL,TOOLUPSENSORSAT5)
  __DECLARE_LOCATED(BOOL,TOOLUPSENSORSBT3)
  __DECLARE_LOCATED(BOOL,TOOLUPSENSORSBT5)
  __DECLARE_LOCATED(BOOL,TOOLUPSENSORSCT3)
  __DECLARE_LOCATED(BOOL,TOOLUPSENSORSCT5)
  __DECLARE_LOCATED(BOOL,TOOLDOWNSENSORSAT3)
  __DECLARE_LOCATED(BOOL,TOOLDOWNSENSORSAT5)
  __DECLARE_LOCATED(BOOL,TOOLDOWNSENSORSBT3)
  __DECLARE_LOCATED(BOOL,TOOLDOWNSENSORSBT5)
  __DECLARE_LOCATED(BOOL,TOOLDOWNSENSORSCT3)
  __DECLARE_LOCATED(BOOL,TOOLDOWNSENSORSCT5)
  __DECLARE_LOCATED(BOOL,TOOLLEFTSENSORSAT3)
  __DECLARE_LOCATED(BOOL,TOOLLEFTSENSORSAT5)
  __DECLARE_LOCATED(BOOL,TOOLLEFTSENSORSBT3)
  __DECLARE_LOCATED(BOOL,TOOLLEFTSENSORSBT5)
  __DECLARE_LOCATED(BOOL,TOOLLEFTSENSORSCT3)
  __DECLARE_LOCATED(BOOL,TOOLLEFTSENSORSCT5)
  __DECLARE_LOCATED(BOOL,TOOLRIGHTSENSORSAT3)
  __DECLARE_LOCATED(BOOL,TOOLRIGHTSENSORSAT5)
  __DECLARE_LOCATED(BOOL,TOOLRIGHTSENSORSBT3)
  __DECLARE_LOCATED(BOOL,TOOLRIGHTSENSORSBT5)
  __DECLARE_LOCATED(BOOL,TOOLRIGHTSENSORSCT3)
  __DECLARE_LOCATED(BOOL,TOOLRIGHTSENSORSCT5)
  __DECLARE_LOCATED(BOOL,USETOOLSAT3)
  __DECLARE_LOCATED(BOOL,USETOOLSAT5)
  __DECLARE_LOCATED(BOOL,USETOOLSBT3)
  __DECLARE_LOCATED(BOOL,USETOOLSBT5)
  __DECLARE_LOCATED(BOOL,USETOOLSCT3)
  __DECLARE_LOCATED(BOOL,USETOOLSCT5)
  __DECLARE_EXTERNAL(BOOL,TOOLPIECESAT3_EX)
  __DECLARE_EXTERNAL(BOOL,TOOLPIECESAT5_EX)
  LINEARCONVEYOR SAT4;
  MACHINE SAT5;
  __DECLARE_EXTERNAL(BOOL,READYTOSENDSAT3_EX)
  __DECLARE_EXTERNAL(BOOL,READYTOSENDSAT5_EX)
  __DECLARE_EXTERNAL(BOOL,PUTPIECEINSIGNAL_EX)
  __DECLARE_LOCATED(INT,INITIALPIECE)
  __DECLARE_LOCATED(INT,FINALPIECE)
  __DECLARE_VAR(BOOL,OR210_OUT)
  __DECLARE_VAR(BOOL,OR209_OUT)

} PROGRAM0;

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain);
// Code part
void PROGRAM0_body__(PROGRAM0 *data__);
// FUNCTION_BLOCK REMOVEFROMWAREHOUSE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(INT,PIECENUM)
  __DECLARE_VAR(INT,WAREHOUSEIN)
  __DECLARE_VAR(BOOL,SENSORAT1)

  // FB private variables - TEMP, private and located variables
  STEP __step_list[12];
  UINT __nb_steps;
  ACTION __action_list[10];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[20];
  __IEC_BOOL_t __debug_transition_list[20];
  UINT __nb_transitions;
  TIME __lasttick_time;

} REMOVEFROMWAREHOUSE;

void REMOVEFROMWAREHOUSE_init__(REMOVEFROMWAREHOUSE *data__, BOOL retain);
// Code part
void REMOVEFROMWAREHOUSE_body__(REMOVEFROMWAREHOUSE *data__);
// PROGRAM PROGRAM1
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_LOCATED(INT,WAREHOUSEIN)
  __DECLARE_EXTERNAL(BOOL,WAREHOUSEBUSY)
  __DECLARE_LOCATED(BOOL,SENSORAT1)
  __DECLARE_LOCATED(INT,INITIALPIECE)
  __DECLARE_LOCATED(INT,FINALPIECE)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTAT1_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSAT1_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSAT2_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSAT4_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSBT1_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSBT2_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSCT1_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTSCT2_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTMT1_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTMT2_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTCT1_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTCT4_EX)
  __DECLARE_EXTERNAL(BOOL,RUNFRONTCT5_EX)
  __DECLARE_EXTERNAL(BOOL,RUNBACKSAT7_EX)
  __DECLARE_EXTERNAL(BOOL,SENDDOWNSAT2_EX)
  __DECLARE_EXTERNAL(BOOL,TOOLPIECESAT3_EX)
  __DECLARE_EXTERNAL(BOOL,TOOLPIECESAT5_EX)
  __DECLARE_EXTERNAL(BOOL,SENDDOWNCT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORAT1_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORAT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSAT1_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSAT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSAT4_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSAT6_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSAT7_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSBT1_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSBT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSCT1_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORSCT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORMT1_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORMT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORCT1_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORCT2_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORCT4_EX)
  __DECLARE_EXTERNAL(BOOL,SENSORCT5_EX)
  __DECLARE_EXTERNAL(BOOL,PUSHTOROLLCT4_EX)
  __DECLARE_EXTERNAL(BOOL,PUSHTOROLLCT5_EX)
  __DECLARE_EXTERNAL(BOOL,PUSHTOROLLCT6_EX)
  __DECLARE_EXTERNAL(BOOL,SENDLEFTDOWNSAT6_EX)
  __DECLARE_EXTERNAL(BOOL,PUTPIECEINSIGNAL_EX)
  REMOVEFROMWAREHOUSE REMOVEFROMWAREHOUSE0;
  __DECLARE_LOCATED(INT,PM)
  __DECLARE_LOCATED(BOOL,RUNUNLOAD)
  __DECLARE_LOCATED(BOOL,RUNTRANSFORMMACH1)
  __DECLARE_EXTERNAL(BOOL,READYTOSENDSAT3_EX)
  __DECLARE_EXTERNAL(BOOL,READYTOSENDSAT5_EX)
  STEP __step_list[103];
  UINT __nb_steps;
  ACTION __action_list[27];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[105];
  __IEC_BOOL_t __debug_transition_list[105];
  UINT __nb_transitions;
  TIME __lasttick_time;

} PROGRAM1;

void PROGRAM1_init__(PROGRAM1 *data__, BOOL retain);
// Code part
void PROGRAM1_body__(PROGRAM1 *data__);
// PROGRAM PROGRAM2
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_LOCATED(INT,WAREHOUSEIN)
  __DECLARE_VAR(BOOL,P1_REG)
  __DECLARE_VAR(BOOL,P2_REG)
  __DECLARE_VAR(BOOL,P3_REG)
  __DECLARE_VAR(BOOL,P4_REG)
  __DECLARE_VAR(BOOL,P5_REG)
  __DECLARE_VAR(BOOL,P6_REG)
  __DECLARE_VAR(BOOL,P7_REG)
  __DECLARE_VAR(BOOL,P8_REG)
  __DECLARE_VAR(BOOL,P9_REG)
  __DECLARE_LOCATED(BOOL,SENSORAT1)
  STEP __step_list[11];
  UINT __nb_steps;
  ACTION __action_list[10];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[19];
  __IEC_BOOL_t __debug_transition_list[19];
  UINT __nb_transitions;
  TIME __lasttick_time;

} PROGRAM2;

void PROGRAM2_init__(PROGRAM2 *data__, BOOL retain);
// Code part
void PROGRAM2_body__(PROGRAM2 *data__);
#endif //__POUS_H
