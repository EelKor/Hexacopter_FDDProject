//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_sys_SITL_HEXA_Hovering_0.cpp
//
// Code generated for Simulink model 'SITL_HEXA_Hovering'.
//
// Model version                  : 5.7
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Oct 16 15:41:08 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "rt_sys_SITL_HEXA_Hovering_0.h"
#include "SITL_HEXA_Hovering_private.h"

// System initialize for atomic system:
void SITL_HEXA_Hovering_PX4Timestamp_Init(DW_PX4Timestamp_SITL_HEXA_Hovering_T
  *localDW)
{
  // Start for MATLABSystem: '<S6>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void SITL_HEXA_Hovering_PX4Timestamp(B_PX4Timestamp_SITL_HEXA_Hovering_T *localB)
{
  // MATLABSystem: '<S6>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void SITL_HEXA_Hovering_PX4Timestamp_Term(DW_PX4Timestamp_SITL_HEXA_Hovering_T
  *localDW)
{
  // Terminate for MATLABSystem: '<S6>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/PX4 Timestamp'
}

//
// File trailer for generated code.
//
// [EOF]
//
