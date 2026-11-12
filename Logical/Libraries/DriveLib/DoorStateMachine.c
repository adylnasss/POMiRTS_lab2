
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif
void DoorStateMachine(struct DoorStateMachine* inst)
{
	static plcbit previousSw[4];
	plcbit sw1Click = (inst->sw1 != previousSw[0]);
	plcbit sw2Click = (inst->sw2 != previousSw[1]);
	plcbit sw3Click = (inst->sw3 != previousSw[2]);
	plcbit sw4Click = (inst->sw4 != previousSw[3]);

	/* Remember levels every cycle; either edge is a one-cycle click. */
	previousSw[0] = inst->sw1;
	previousSw[1] = inst->sw2;
	previousSw[2] = inst->sw3;
	previousSw[3] = inst->sw4;

	switch (inst->state){
		case ST_INIT:
			inst->speed = 0;
			inst->state=ST_UNKNOWN;
			break;
		
		case ST_UNKNOWN:
			if (sw1Click && inst->direction == 0){
				inst->state = ST_OPEN;
				break;
			} else if (sw4Click && inst->direction == 1){
				inst->state = ST_CLOSE;
				break;
			} else {
				inst->speed = (inst->direction == 0)?-50:50;
				break;
			}
		
		case ST_OPEN:
			if (inst->direction == 0){
				inst->speed = 0;
				break;
			} 
			else if (inst->direction == 1){
				inst->state = ST_ACC_POS;
				break;
			} 
			else {
				inst->state = ST_UNKNOWN;
				break;
			}
		
		case ST_ACC_POS:
			if (inst->direction == 1 && !sw2Click){
				inst->speed = 100;	
				break;
			}
			else if (inst->direction == 1 && sw2Click){
				inst->state = ST_POS;
				break;
			} 
			else if (inst->direction == 0) {
				inst->state = ST_DEC_NEG;
				break;
			} 
			else {
				inst->speed = 0;
				inst->state = ST_UNKNOWN;
				break;
			}
		
		case ST_POS:
			if (inst->direction == 1 && !sw3Click){
				inst->speed = 200;
				break;
			}
			else if (inst->direction == 1){
				inst->state = ST_DEC_POS;
				break;
			}
			else if (inst->direction == 0){
				inst->state = ST_NEG;
				break;
			}
			else{
				inst->state = ST_UNKNOWN;
				break;
			}
		
		case ST_DEC_POS:
			if (inst->direction == 1 && !sw4Click){
				inst->speed=100;
				break;
			}
			else if (inst->direction == 1 && sw4Click)
			{
				inst->state = ST_CLOSE;
				break;
			}
			else if (inst->direction == 0)
			{
				inst->state = ST_ACC_NEG;
				break;
			}

			else{
				inst->state = ST_UNKNOWN;
				break;
			}
		
		case ST_CLOSE:
			if (inst->direction == 1)
			{
				inst->speed = 0;
				break;
			}
			else if(inst->direction == 0){
				inst->state = ST_ACC_NEG;
				break;
			}
			else
			{
				inst->state = ST_UNKNOWN;
				break;
			}
		
		case ST_ACC_NEG:
			if (inst->direction == 0 && !sw3Click){
				inst->speed = -100;
				break;
			}
			else if (sw3Click){
				inst->state = ST_NEG;
				break;
			}
			else if (inst->direction == 1){
				inst->state = ST_DEC_POS;
				break;
			}
			else {
				inst->state = ST_UNKNOWN;
				break;
			}
		
		case ST_NEG:
			if (inst->direction == 0 && !sw2Click){
				inst->speed = -200;
				break;
			}
			else if (inst->direction == 0) {
				inst->state = ST_DEC_NEG;
				break;
			}
			else if (inst->direction == 1){
				inst->state = ST_POS;
				break;
			}
			else{
				inst->state = ST_UNKNOWN;
				break;
			}
		case ST_DEC_NEG:
			if (inst->direction == 0 && !sw1Click){
				inst->speed = -100;
				break;
			}
			else if(inst->direction == 0){
				inst->state = ST_OPEN;
				break;
			}
			else if (inst->direction == 1){
				inst->state = ST_ACC_POS;
				break;
			}
			else {
				inst->state = ST_UNKNOWN;
				break;
			}
				
	}
}

