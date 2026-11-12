
PROGRAM _INIT
        
(* ### BEGIN gAxis01 ### *)
        
(* initialize variables *)
        gAxis01_HW.DrvIf_Typ := ncSDC_DRVSERVO16;
        brsstrcpy(ADR(gAxis01_HW.DrvIf_Name[0]), ADR('gAxis01_DrvIf'));
        gAxis01_HW.DiDoIf_Typ := ncSDC_DIDO;
        brsstrcpy(ADR(gAxis01_HW.DiDoIf_Name[0]), ADR('gAxis01_DiDoIf'));
         
(* force variable offset generation *)
        gAxis01.size                      := gAxis01.size;
        gAxis01_DrvIf.iLifeCnt            := gAxis01_DrvIf.iLifeCnt;
        gAxis01_DiDoIf.iLifeCntDriveReady := gAxis01_DiDoIf.iLifeCntDriveReady;
        gAxis01_ModuleOk                  := gAxis01_ModuleOk;
         
(* assign your hardware inputs here*)
  
(*      gAxis01_DiDoIf.iPosHwEnd  := gAxis01_DiDoIf.iPosHwEnd;
        gAxis01_DiDoIf.iNegHwEnd  := gAxis01_DiDoIf.iNegHwEnd;
        gAxis01_DiDoIf.iReference := gAxis01_DiDoIf.iReference;
 *)
        
(* ### END gAxis01 ### *)


(* ### BEGIN gAxis02 ### *)
      
(* initialize general interfaces *)
      gAxis02.size := gAxis02.size;
      gAxis02_HW.DrvIf_Typ := ncSDC_DRVSM16;
      brsstrcpy( ADR(gAxis02_HW.DrvIf_Name[0]), ADR('gAxis02_DrvIf') );
      gAxis02_HW.DiDoIf_Typ := ncSDC_DIDO;
      brsstrcpy( ADR(gAxis02_HW.DiDoIf_Name[0]), ADR('gAxis02_DiDoIf') );
      gAxis02_HW.EncIf1_Typ := ncSDC_ENC16;
      brsstrcpy( ADR(gAxis02_HW.EncIf1_Name[0]), ADR('gAxis02_EncIf1') );
      gAxis02_EncIf1.iLifeCnt := gAxis02_EncIf1.iLifeCnt;
      
(* initialize old-value for delta step calculation *)
      gAxis02_oSetPosOld := gAxis02_DrvIf.oSetPos;
       
(* ### END gAxis02 ### *)

END_PROGRAM

