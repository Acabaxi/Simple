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
PROGRAM0 RESOURCE1__INSTANCE0;
#define INSTANCE0 RESOURCE1__INSTANCE0

void RESOURCE1_init__(void) {
  BOOL retain;
  retain = 0;
  
  TASK0 = __BOOL_LITERAL(FALSE);
  PROGRAM0_init__(&INSTANCE0,retain);
}

void RESOURCE1_run__(unsigned long tick) {
  TASK0 = !(tick % 1);
  PROGRAM0_body__(&INSTANCE0);
}

