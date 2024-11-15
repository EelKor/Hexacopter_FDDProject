//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_sys_F550_FaultInjection_44.cpp
//
// Code generated for Simulink model 'F550_FaultInjection'.
//
// Model version                  : 4.153
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Aug 10 17:25:22 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "rt_sys_F550_FaultInjection_44.h"
#include "F550_FaultInjection_private.h"

// System initialize for atomic system:
void F550_FaultInjection_SourceBlock_Init(DW_SourceBlock_F550_FaultInjection_T
  *localDW)
{
  // Start for MATLABSystem: '<S19>/SourceBlock'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.orbMetadataObj = ORB_ID(input_rc);
  uORB_read_initialize(localDW->obj.orbMetadataObj, &localDW->obj.eventStructObj);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void F550_FaultInjection_SourceBlock(B_SourceBlock_F550_FaultInjection_T *localB,
  DW_SourceBlock_F550_FaultInjection_T *localDW)
{
  // MATLABSystem: '<S19>/SourceBlock'
  localB->SourceBlock_o1 = uORB_read_step(localDW->obj.orbMetadataObj,
    &localDW->obj.eventStructObj, &localB->SourceBlock_o2, false, 5000.0);
}

// Termination for atomic system:
void F550_FaultInjection_SourceBlock_Term(DW_SourceBlock_F550_FaultInjection_T
  *localDW)
{
  // Terminate for MATLABSystem: '<S19>/SourceBlock'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uORB_read_terminate(&localDW->obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S19>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
