/*
 * DEBUGGER code
 * 
 * On "publish", when buffer is free, debugger stores arbitrary variables 
 * content into, and mark this buffer as filled
 * 
 * 
 * Buffer content is read asynchronously, (from non real time part), 
 * and then buffer marked free again.
 *  
 * 
 * */

#ifdef TARGET_DEBUG_DISABLE

void __init_debug    (void){}
void __cleanup_debug (void){}
void __retrieve_debug(void){}
void __publish_debug (void){}

#else

#include "iec_types_all.h"
#include "POUS.h"
/*for memcpy*/
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 942

/* Atomically accessed variable for buffer state */
#define BUFFER_FREE 0
#define BUFFER_BUSY 1
static long buffer_state = BUFFER_FREE;

/* The buffer itself */
char debug_buffer[BUFFER_SIZE];

/* Buffer's cursor*/
static char* buffer_cursor = debug_buffer;
static unsigned int retain_offset = 0;
/***
 * Declare programs 
 **/
extern PROGRAM1 RESOURCE1__INSTANCE1;
extern PROGRAM0 RESOURCE1__INSTANCE0;

/***
 * Declare global variables from resources and conf 
 **/
extern __IEC_BOOL_t CONFIG__II;
extern __IEC_BOOL_t CONFIG__RUNFRONTAT1_EX;
extern __IEC_BOOL_t CONFIG__RUNFRONTSAT1_EX;
extern __IEC_BOOL_t CONFIG__RUNFRONTSAT2_EX;
extern __IEC_BOOL_t CONFIG__RUNFRONTSBT1_EX;
extern __IEC_BOOL_t CONFIG__SENDDOWNSAT2_EX;
extern __IEC_BOOL_t CONFIG__SENSORAT1_EX;
extern __IEC_BOOL_t CONFIG__SENSORSAT1_EX;
extern __IEC_BOOL_t CONFIG__SENSORSAT2_EX;
extern __IEC_BOOL_t CONFIG__SENSORSBT1_EX;
extern       PROGRAM1   RESOURCE1__INSTANCE1;
extern       PROGRAM0   RESOURCE1__INSTANCE0;

typedef const struct {
    void *ptr;
    __IEC_types_enum type;
} dbgvardsc_t;

static dbgvardsc_t dbgvardsc[] = {
{&(CONFIG__II), BOOL_ENUM},
{&(CONFIG__RUNFRONTAT1_EX), BOOL_ENUM},
{&(CONFIG__RUNFRONTSAT1_EX), BOOL_ENUM},
{&(CONFIG__RUNFRONTSAT2_EX), BOOL_ENUM},
{&(CONFIG__RUNFRONTSBT1_EX), BOOL_ENUM},
{&(CONFIG__SENDDOWNSAT2_EX), BOOL_ENUM},
{&(CONFIG__SENSORAT1_EX), BOOL_ENUM},
{&(CONFIG__SENSORSAT1_EX), BOOL_ENUM},
{&(CONFIG__SENSORSAT2_EX), BOOL_ENUM},
{&(CONFIG__SENSORSBT1_EX), BOOL_ENUM},
{&(RESOURCE1__INSTANCE1.II), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE1.RUNFRONTAT1_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE1.RUNFRONTSAT1_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE1.RUNFRONTSAT2_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE1.RUNFRONTSBT1_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE1.SENDDOWNSAT2_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE1.SENSORAT1_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE1.SENSORSAT1_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE1.SENSORSAT2_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE1.SENSORSBT1_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE1.__step_list[0].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE1.__debug_transition_list[0]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE1.__step_list[1].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE1.__debug_transition_list[1]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE1.__step_list[2].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE1.__debug_transition_list[2]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE1.__step_list[3].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE1.__debug_transition_list[3]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE1.__step_list[4].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE1.__debug_transition_list[4]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE1.__step_list[5].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE1.__debug_transition_list[5]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE1.__step_list[6].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE1.__debug_transition_list[6]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.EN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.ENO), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.BACKSIGNAL), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.FORWARDTIMERON), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.FORWARDSIGNAL), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.BACKNOTBUSY), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.FRONTNOTBUSY), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.REACHEDSENSORFRONT), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.REACHEDSENSORBACK), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.REACHEDSENSOR), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.FORWARDMOTOR), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.BACKMOTOR), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.ISBUSY), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON0.EN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON0.ENO), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON0.IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON0.PT), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON0.Q), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON0.ET), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON0.STATE), SINT_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON0.PREV_IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON0.CURRENT_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON0.START_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON1.EN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON1.ENO), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON1.IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON1.PT), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON1.Q), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON1.ET), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON1.STATE), SINT_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON1.PREV_IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON1.CURRENT_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.TON1.START_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__step_list[0].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__action_list[0].state), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__debug_transition_list[0]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__step_list[1].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__debug_transition_list[1]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__step_list[2].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__debug_transition_list[2]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__step_list[3].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__debug_transition_list[3]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__step_list[4].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__debug_transition_list[4]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__debug_transition_list[5]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__debug_transition_list[6]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__step_list[5].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__debug_transition_list[7]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__step_list[6].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__debug_transition_list[8]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__step_list[7].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__debug_transition_list[9]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__step_list[8].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__debug_transition_list[10]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.AT1.__debug_transition_list[11]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.EN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.ENO), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.BACKSIGNAL), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.FORWARDTIMERON), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.FORWARDSIGNAL), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.BACKNOTBUSY), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.FRONTNOTBUSY), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.REACHEDSENSORFRONT), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.REACHEDSENSORBACK), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.REACHEDSENSOR), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.FORWARDMOTOR), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.BACKMOTOR), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.ISBUSY), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON0.EN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON0.ENO), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON0.IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON0.PT), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON0.Q), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON0.ET), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON0.STATE), SINT_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON0.PREV_IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON0.CURRENT_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON0.START_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON1.EN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON1.ENO), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON1.IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON1.PT), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON1.Q), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON1.ET), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON1.STATE), SINT_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON1.PREV_IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON1.CURRENT_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.TON1.START_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__step_list[0].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__action_list[0].state), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__debug_transition_list[0]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__step_list[1].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__debug_transition_list[1]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__step_list[2].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__debug_transition_list[2]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__step_list[3].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__debug_transition_list[3]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__step_list[4].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__debug_transition_list[4]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__debug_transition_list[5]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__debug_transition_list[6]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__step_list[5].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__debug_transition_list[7]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__step_list[6].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__debug_transition_list[8]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__step_list[7].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__debug_transition_list[9]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__step_list[8].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__debug_transition_list[10]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT1.__debug_transition_list[11]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.EN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.ENO), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.BACKSIGNAL), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.FORWARDTIMERON), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.FORWARDSIGNAL), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.SENDDOWNSIGNAL), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.SENDUPSIGNAL), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.SENSORROTRIGHT), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.SENSORROTLEFT), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.BACKNOTBUSY), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.FRONTNOTBUSY), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.DOWNNOTBUSY), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.UPNOTBUSY), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.REACHEDSENSORFRONT), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.REACHEDSENSORBACK), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.REACHEDSENSOR), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.FORWARDMOTOR), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.BACKMOTOR), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.RIGHTROTMOTOR), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.LEFTROTMOTOR), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.ISBUSY), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON0.EN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON0.ENO), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON0.IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON0.PT), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON0.Q), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON0.ET), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON0.STATE), SINT_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON0.PREV_IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON0.CURRENT_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON0.START_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON1.EN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON1.ENO), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON1.IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON1.PT), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON1.Q), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON1.ET), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON1.STATE), SINT_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON1.PREV_IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON1.CURRENT_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON1.START_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON2.EN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON2.ENO), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON2.IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON2.PT), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON2.Q), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON2.ET), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON2.STATE), SINT_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON2.PREV_IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON2.CURRENT_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON2.START_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON3.EN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON3.ENO), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON3.IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON3.PT), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON3.Q), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON3.ET), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON3.STATE), SINT_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON3.PREV_IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON3.CURRENT_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.TON3.START_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[0].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__action_list[0].state), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[0]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[1].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[1]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[2].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[2]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[3].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[3]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[4].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[4]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[5]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[6]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[5].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[7]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[6].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[8]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[7].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[9]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[8].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[10]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[11]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[12]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[9].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[13]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[10].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[14]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[11].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[15]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[12].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[16]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[13].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[17]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[14].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[18]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[15].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[19]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[20]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[21]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[16].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[22]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[17].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[23]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[18].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[24]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[19].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[25]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[20].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[26]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[21].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[27]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__step_list[22].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[28]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SAT2.__debug_transition_list[29]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.II), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE0.SENSORAT1), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE0.SENSORSAT1), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE0.SENSORSAT2), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE0.SENSORSBT1), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE0.SENSORROTRIGHTSAT3), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE0.SENSORROTLEFTSAT3), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE0.FORWARDAT1), BOOL_O_ENUM},
{&(RESOURCE1__INSTANCE0.FORWARDSAT1), BOOL_O_ENUM},
{&(RESOURCE1__INSTANCE0.FORWARDSAT2), BOOL_O_ENUM},
{&(RESOURCE1__INSTANCE0.FORWARDSBT1), BOOL_O_ENUM},
{&(RESOURCE1__INSTANCE0.RIGHTROTSAT3), BOOL_O_ENUM},
{&(RESOURCE1__INSTANCE0.LEFTROTSAT3), BOOL_O_ENUM},
{&(RESOURCE1__INSTANCE0.BACKAT1), BOOL_O_ENUM},
{&(RESOURCE1__INSTANCE0.BACKSAT1), BOOL_O_ENUM},
{&(RESOURCE1__INSTANCE0.BACKSAT2), BOOL_O_ENUM},
{&(RESOURCE1__INSTANCE0.SENSORAT1_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE0.SENSORSAT1_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE0.SENSORSAT2_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE0.SENSORSBT1_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE0.RUNFRONTAT1_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE0.RUNFRONTSAT1_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE0.RUNFRONTSAT2_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE0.RUNFRONTSBT1_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE0.SENDDOWNSAT2_EX), BOOL_P_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.EN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.ENO), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.BACKSIGNAL), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.FORWARDTIMERON), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.FORWARDSIGNAL), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.BACKNOTBUSY), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.FRONTNOTBUSY), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.REACHEDSENSORFRONT), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.REACHEDSENSORBACK), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.REACHEDSENSOR), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.FORWARDMOTOR), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.BACKMOTOR), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.ISBUSY), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON0.EN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON0.ENO), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON0.IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON0.PT), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON0.Q), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON0.ET), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON0.STATE), SINT_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON0.PREV_IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON0.CURRENT_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON0.START_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON1.EN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON1.ENO), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON1.IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON1.PT), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON1.Q), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON1.ET), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON1.STATE), SINT_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON1.PREV_IN), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON1.CURRENT_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.TON1.START_TIME), TIME_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__step_list[0].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__action_list[0].state), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__debug_transition_list[0]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__step_list[1].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__debug_transition_list[1]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__step_list[2].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__debug_transition_list[2]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__step_list[3].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__debug_transition_list[3]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__step_list[4].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__debug_transition_list[4]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__debug_transition_list[5]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__debug_transition_list[6]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__step_list[5].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__debug_transition_list[7]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__step_list[6].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__debug_transition_list[8]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__step_list[7].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__debug_transition_list[9]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__step_list[8].X), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__debug_transition_list[10]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.SBT1.__debug_transition_list[11]), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.NOT40_OUT), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.NOT32_OUT), BOOL_ENUM},
{&(RESOURCE1__INSTANCE0.NOT31_OUT), BOOL_ENUM}
};

typedef void(*__for_each_variable_do_fp)(dbgvardsc_t*);
void __for_each_variable_do(__for_each_variable_do_fp fp)
{
    int i;
    for(i = 0; i < sizeof(dbgvardsc)/sizeof(dbgvardsc_t); i++){
        dbgvardsc_t *dsc = &dbgvardsc[i];
        if(dsc->type != UNKNOWN_ENUM) 
            (*fp)(dsc);
    }
}

#define __Unpack_case_t(TYPENAME) \
        case TYPENAME##_ENUM :\
            *flags = ((__IEC_##TYPENAME##_t *)varp)->flags;\
            forced_value_p = *real_value_p = &((__IEC_##TYPENAME##_t *)varp)->value;\
            break;

#define __Unpack_case_p(TYPENAME)\
        case TYPENAME##_O_ENUM :\
            *flags = __IEC_OUTPUT_FLAG;\
        case TYPENAME##_P_ENUM :\
            *flags |= ((__IEC_##TYPENAME##_p *)varp)->flags;\
            *real_value_p = ((__IEC_##TYPENAME##_p *)varp)->value;\
            forced_value_p = &((__IEC_##TYPENAME##_p *)varp)->fvalue;\
            break;

void* UnpackVar(dbgvardsc_t *dsc, void **real_value_p, char *flags)
{
    void *varp = dsc->ptr;
    void *forced_value_p = NULL;
    *flags = 0;
    /* find data to copy*/
    switch(dsc->type){
        __ANY(__Unpack_case_t)
        __ANY(__Unpack_case_p)
    default:
        break;
    }
    if (*flags & __IEC_FORCE_FLAG)
        return forced_value_p;
    return *real_value_p;
}

void Remind(unsigned int offset, unsigned int count, void * p);

void RemindIterator(dbgvardsc_t *dsc)
{
    void *real_value_p = NULL;
    char flags = 0;
    UnpackVar(dsc, &real_value_p, &flags);

    if(flags & __IEC_RETAIN_FLAG){
        USINT size = __get_type_enum_size(dsc->type);
        /* compute next cursor positon*/
        unsigned int next_retain_offset = retain_offset + size;
        /* if buffer not full */
        Remind(retain_offset, size, real_value_p);
        /* increment cursor according size*/
        retain_offset = next_retain_offset;
    }
}

extern int CheckRetainBuffer(void);
extern void InitRetain(void);

void __init_debug(void)
{
    /* init local static vars */
    buffer_cursor = debug_buffer;
    retain_offset = 0;
    buffer_state = BUFFER_FREE;
    InitRetain();
    /* Iterate over all variables to fill debug buffer */
    if(CheckRetainBuffer()){
    	__for_each_variable_do(RemindIterator);
    }else{
    	char mstr[] = "RETAIN memory invalid - defaults used";
        LogMessage(LOG_WARNING, mstr, sizeof(mstr));
    }
    retain_offset = 0;
}

extern void InitiateDebugTransfer(void);
extern void CleanupRetain(void);

extern unsigned long __tick;

void __cleanup_debug(void)
{
    buffer_cursor = debug_buffer;
    InitiateDebugTransfer();
    CleanupRetain();
}

void __retrieve_debug(void)
{
}


void Retain(unsigned int offset, unsigned int count, void * p);

static inline void BufferIterator(dbgvardsc_t *dsc, int do_debug)
{
    void *real_value_p = NULL;
    void *visible_value_p = NULL;
    char flags = 0;

    visible_value_p = UnpackVar(dsc, &real_value_p, &flags);

    if(flags & ( __IEC_DEBUG_FLAG | __IEC_RETAIN_FLAG)){
        USINT size = __get_type_enum_size(dsc->type);
        if(flags & __IEC_DEBUG_FLAG){
            /* copy visible variable to buffer */;
            if(do_debug){
                /* compute next cursor positon.
                   No need to check overflow, as BUFFER_SIZE
                   is computed large enough */
		if((dsc->type == STRING_ENUM)   ||
		   (dsc->type == STRING_P_ENUM) ||
		   (dsc->type == STRING_O_ENUM)){
                    /* optimization for strings */
                    size = ((STRING*)visible_value_p)->len + 1;
                }
                char* next_cursor = buffer_cursor + size;
                /* copy data to the buffer */
                memcpy(buffer_cursor, visible_value_p, size);
                /* increment cursor according size*/
                buffer_cursor = next_cursor;
            }
            /* re-force real value of outputs (M and Q)*/
            if((flags & __IEC_FORCE_FLAG) && (flags & __IEC_OUTPUT_FLAG)){
                memcpy(real_value_p, visible_value_p, size);
            }
        }
        if(flags & __IEC_RETAIN_FLAG){
            /* compute next cursor positon*/
            unsigned int next_retain_offset = retain_offset + size;
            /* if buffer not full */
            Retain(retain_offset, size, real_value_p);
            /* increment cursor according size*/
            retain_offset = next_retain_offset;
        }
    }
}

void DebugIterator(dbgvardsc_t *dsc){
    BufferIterator(dsc, 1);
}

void RetainIterator(dbgvardsc_t *dsc){
    BufferIterator(dsc, 0);
}

extern void PLC_GetTime(IEC_TIME*);
extern int TryEnterDebugSection(void);
extern long AtomicCompareExchange(long*, long, long);
extern long long AtomicCompareExchange64(long long* , long long , long long);
extern void LeaveDebugSection(void);
extern void ValidateRetainBuffer(void);
extern void InValidateRetainBuffer(void);

void __publish_debug(void)
{
    retain_offset = 0;
    InValidateRetainBuffer();
    /* Check there is no running debugger re-configuration */
    if(TryEnterDebugSection()){
        /* Lock buffer */
        long latest_state = AtomicCompareExchange(
            &buffer_state,
            BUFFER_FREE,
            BUFFER_BUSY);
            
        /* If buffer was free */
        if(latest_state == BUFFER_FREE)
        {
            /* Reset buffer cursor */
            buffer_cursor = debug_buffer;
            /* Iterate over all variables to fill debug buffer */
            __for_each_variable_do(DebugIterator);
            
            /* Leave debug section,
             * Trigger asynchronous transmission 
             * (returns immediately) */
            InitiateDebugTransfer(); /* size */
        }else{
            /* when not debugging, do only retain */
            __for_each_variable_do(RetainIterator);
        }
        LeaveDebugSection();
    }else{
        /* when not debugging, do only retain */
        __for_each_variable_do(RetainIterator);
    }
    ValidateRetainBuffer();
}

#define __RegisterDebugVariable_case_t(TYPENAME) \
        case TYPENAME##_ENUM :\
            ((__IEC_##TYPENAME##_t *)varp)->flags |= flags;\
            if(force)\
             ((__IEC_##TYPENAME##_t *)varp)->value = *((TYPENAME *)force);\
            break;
#define __RegisterDebugVariable_case_p(TYPENAME)\
        case TYPENAME##_P_ENUM :\
            ((__IEC_##TYPENAME##_p *)varp)->flags |= flags;\
            if(force)\
             ((__IEC_##TYPENAME##_p *)varp)->fvalue = *((TYPENAME *)force);\
            break;\
        case TYPENAME##_O_ENUM :\
            ((__IEC_##TYPENAME##_p *)varp)->flags |= flags;\
            if(force){\
             ((__IEC_##TYPENAME##_p *)varp)->fvalue = *((TYPENAME *)force);\
             *(((__IEC_##TYPENAME##_p *)varp)->value) = *((TYPENAME *)force);\
            }\
            break;
void RegisterDebugVariable(int idx, void* force)
{
    if(idx  < sizeof(dbgvardsc)/sizeof(dbgvardsc_t)){
        unsigned char flags = force ?
            __IEC_DEBUG_FLAG | __IEC_FORCE_FLAG :
            __IEC_DEBUG_FLAG;
        dbgvardsc_t *dsc = &dbgvardsc[idx];
        void *varp = dsc->ptr;
        switch(dsc->type){
            __ANY(__RegisterDebugVariable_case_t)
            __ANY(__RegisterDebugVariable_case_p)
        default:
            break;
        }
    }
}

#define __ResetDebugVariablesIterator_case_t(TYPENAME) \
        case TYPENAME##_ENUM :\
            ((__IEC_##TYPENAME##_t *)varp)->flags &= ~(__IEC_DEBUG_FLAG|__IEC_FORCE_FLAG);\
            break;

#define __ResetDebugVariablesIterator_case_p(TYPENAME)\
        case TYPENAME##_P_ENUM :\
        case TYPENAME##_O_ENUM :\
            ((__IEC_##TYPENAME##_p *)varp)->flags &= ~(__IEC_DEBUG_FLAG|__IEC_FORCE_FLAG);\
            break;

void ResetDebugVariablesIterator(dbgvardsc_t *dsc)
{
    /* force debug flag to 0*/
    void *varp = dsc->ptr;
    switch(dsc->type){
        __ANY(__ResetDebugVariablesIterator_case_t)
        __ANY(__ResetDebugVariablesIterator_case_p)
    default:
        break;
    }
}

void ResetDebugVariables(void)
{
    __for_each_variable_do(ResetDebugVariablesIterator);
}

void FreeDebugData(void)
{
    /* atomically mark buffer as free */
    AtomicCompareExchange(
        &buffer_state,
        BUFFER_BUSY,
        BUFFER_FREE);
}
int WaitDebugData(unsigned long *tick);
/* Wait until debug data ready and return pointer to it */
int GetDebugData(unsigned long *tick, unsigned long *size, void **buffer){
    int wait_error = WaitDebugData(tick);
    if(!wait_error){
        *size = buffer_cursor - debug_buffer;
        *buffer = debug_buffer;
    }
    return wait_error;
}

#endif

