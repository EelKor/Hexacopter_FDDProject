//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_sys_CLAW_70.cpp
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
#include "rt_sys_CLAW_70.h"
#include "F550_FaultInjection_private.h"

// System initialize for atomic system:
void F550_FaultInjection_PX4Timestamp_Init(DW_PX4Timestamp_F550_FaultInjection_T
  *localDW)
{
  // Start for MATLABSystem: '<S24>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void F550_FaultInjection_PX4Timestamp(B_PX4Timestamp_F550_FaultInjection_T
  *localB)
{
  // MATLABSystem: '<S24>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void F550_FaultInjection_PX4Timestamp_Term(DW_PX4Timestamp_F550_FaultInjection_T
  *localDW)
{
  // Terminate for MATLABSystem: '<S24>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S24>/PX4 Timestamp'
}

//
// File trailer for generated code.
//
// [EOF]
//
