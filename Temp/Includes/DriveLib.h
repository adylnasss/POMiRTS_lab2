/* Automation Studio generated header file */
/* Do not edit ! */
/* DriveLib  */

#ifndef _DRIVELIB_
#define _DRIVELIB_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */
#ifdef _REPLACE_CONST
 #define CMD_ENABLE 15U
 #define CMD_SHUTDOWN 6U
 #define CMD_SWITCH_ON 7U
 #define STATE_DISABLED 64U
 #define STATE_READY 33U
 #define STATE_SWITCHED_ON 35U
#else
 _GLOBAL_CONST unsigned short CMD_ENABLE;
 _GLOBAL_CONST unsigned short CMD_SHUTDOWN;
 _GLOBAL_CONST unsigned short CMD_SWITCH_ON;
 _GLOBAL_CONST unsigned short STATE_DISABLED;
 _GLOBAL_CONST unsigned short STATE_READY;
 _GLOBAL_CONST unsigned short STATE_SWITCHED_ON;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum state
{	ST_DEC_NEG = 9,
	ST_DEC_POS = 8,
	ST_NEG = 7,
	ST_POS = 6,
	ST_ACC_NEG = 5,
	ST_ACC_POS = 4,
	ST_CLOSE = 3,
	ST_OPEN = 2,
	ST_UNKNOWN = 1,
	ST_INIT = 0
} state;

typedef struct LedStateMachine
{
	/* VAR_INPUT (analog) */
	enum state state;
	/* VAR_OUTPUT (analog) */
	signed short timer;
	/* VAR_OUTPUT (digital) */
	plcbit led1;
	plcbit led2;
	plcbit led3;
	plcbit led4;
} LedStateMachine_typ;

typedef struct DriveStateMachine
{
	/* VAR_INPUT (analog) */
	unsigned short state;
	/* VAR_OUTPUT (analog) */
	unsigned short command;
	signed short speed;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DriveStateMachine_typ;

typedef struct DoorStateMachine
{
	/* VAR_OUTPUT (analog) */
	enum state state;
	signed short speed;
	/* VAR_INPUT (digital) */
	plcbit sw1;
	plcbit sw2;
	plcbit sw3;
	plcbit sw4;
	plcbit direction;
} DoorStateMachine_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void LedStateMachine(struct LedStateMachine* inst);
_BUR_PUBLIC void DriveStateMachine(struct DriveStateMachine* inst);
_BUR_PUBLIC void DoorStateMachine(struct DoorStateMachine* inst);


#ifdef __cplusplus
};
#endif
#endif /* _DRIVELIB_ */

