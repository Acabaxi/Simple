/*******************************************/
/*     FILE GENERATED BY iec2c             */
/* Editing this file is not recommended... */
/*******************************************/

#include "iec_std_lib.h"

// RESOURCE RESOURCE1

extern unsigned long long common_ticktime__;

#include "accessor.h"
#include "POUS.h"

#include "config.h"

#include "POUS.c"

BOOL TASK0;
PROGRAM2 RESOURCE1__INSTANCE1;
#define INSTANCE1 RESOURCE1__INSTANCE1
PROGRAM1 RESOURCE1__INSTANCE2;
#define INSTANCE2 RESOURCE1__INSTANCE2
PROGRAM0 RESOURCE1__INSTANCE0;
#define INSTANCE0 RESOURCE1__INSTANCE0

void RESOURCE1_init__(void) {
  BOOL retain;
  retain = 0;
  
  TASK0 = __BOOL_LITERAL(FALSE);
  PROGRAM2_init__(&INSTANCE1,retain);
  PROGRAM1_init__(&INSTANCE2,retain);
  PROGRAM0_init__(&INSTANCE0,retain);
}

void RESOURCE1_run__(unsigned long tick) {
  TASK0 = !(tick % 1);
  if (TASK0) {
    PROGRAM2_body__(&INSTANCE1);
  }
  if (TASK0) {
    PROGRAM1_body__(&INSTANCE2);
  }
  if (TASK0) {
    PROGRAM0_body__(&INSTANCE0);
  }
}

