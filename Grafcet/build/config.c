/*******************************************/
/*     FILE GENERATED BY iec2c             */
/* Editing this file is not recommended... */
/*******************************************/

#include "iec_std_lib.h"

#include "accessor.h"

#include "POUS.h"

// CONFIGURATION CONFIG
__DECLARE_GLOBAL(BOOL,CONFIG,II)
__DECLARE_GLOBAL(BOOL,CONFIG,RUNFRONTAT1_EX)
__DECLARE_GLOBAL(BOOL,CONFIG,RUNFRONTSAT1_EX)
__DECLARE_GLOBAL(BOOL,CONFIG,RUNFRONTSAT2_EX)
__DECLARE_GLOBAL(BOOL,CONFIG,RUNFRONTSBT1_EX)
__DECLARE_GLOBAL(BOOL,CONFIG,SENDDOWNSAT2_EX)
__DECLARE_GLOBAL(BOOL,CONFIG,SENSORAT1_EX)
__DECLARE_GLOBAL(BOOL,CONFIG,SENSORSAT1_EX)
__DECLARE_GLOBAL(BOOL,CONFIG,SENSORSAT2_EX)
__DECLARE_GLOBAL(BOOL,CONFIG,SENSORSBT1_EX)

void RESOURCE1_init__(void);

void config_init__(void) {
  BOOL retain;
  retain = 0;
  __INIT_GLOBAL(BOOL,II,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,RUNFRONTAT1_EX,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,RUNFRONTSAT1_EX,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,RUNFRONTSAT2_EX,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,RUNFRONTSBT1_EX,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,SENDDOWNSAT2_EX,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,SENSORAT1_EX,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,SENSORSAT1_EX,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,SENSORSAT2_EX,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,SENSORSBT1_EX,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  RESOURCE1_init__();
}

void RESOURCE1_run__(unsigned long tick);

void config_run__(unsigned long tick) {
  RESOURCE1_run__(tick);
}
unsigned long long common_ticktime__ = 20000000ULL; /*ns*/
unsigned long greatest_tick_count__ = (unsigned long)0UL; /*tick*/
