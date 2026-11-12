/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1794314041_2_
#define _BUR_1794314041_2_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
#else
#endif


/* Variables */
_GLOBAL signed short gAxis02_MotorStep0;
_GLOBAL struct SdcDiDoIf_typ gAxis02_DiDoIf;
_GLOBAL struct SdcEncIf16_typ gAxis02_EncIf1;
_GLOBAL struct SdcDrvIf16_typ gAxis02_DrvIf;
_GLOBAL struct SdcHwCfg_typ gAxis02_HW;
_GLOBAL struct ACP10AXIS_typ gAxis02;
_GLOBAL struct DriveStateMachine stateMachine;
_GLOBAL struct LedStateMachine ledSM;
_GLOBAL struct DoorStateMachine doorSM;
_GLOBAL plcbit gAxis01_ModuleOk;
_GLOBAL struct SdcDiDoIf_typ gAxis01_DiDoIf;
_GLOBAL struct SdcDrvIf16_typ gAxis01_DrvIf;
_GLOBAL struct SdcHwCfg_typ gAxis01_HW;
_GLOBAL struct ACP10AXIS_typ gAxis01;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Global.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/DriveLib/DriveLib.fun\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1794314041_2_ */

