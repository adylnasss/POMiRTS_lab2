
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	stateMachine.enable = 1;
}

void _CYCLIC ProgramCyclic(void)
{
	timeCounter++;
	ledSM.timer = timeCounter;
	DoorStateMachine(&doorSM);
	ledSM.state = doorSM.state;
	LedStateMachine(&ledSM);
	stateMachine.speed = doorSM.speed;
	DriveStateMachine(&stateMachine);
}

void _EXIT ProgramExit(void)
{

}

