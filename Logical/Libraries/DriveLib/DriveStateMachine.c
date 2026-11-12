
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif 
void DriveStateMachine(struct DriveStateMachine* inst)
{
	UINT mask = inst->state & 0x6f;
	if(!inst->enable){
		inst->command = CMD_SHUTDOWN;
	}
	else{
		switch (mask){
			case STATE_DISABLED:
				inst->command = CMD_SHUTDOWN;
				break;
			
			case STATE_READY:
				inst->command = CMD_ENABLE;
				break;
			
			case STATE_SWITCHED_ON:
				inst->command = CMD_SWITCH_ON;
				break;
		}
	}
}
