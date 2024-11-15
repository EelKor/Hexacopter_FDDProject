//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_sys_SITL_HEXA_Hovering_2.cpp
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
#include <uORB/topics/vehicle_local_position_setpoint.h>
#include "rt_sys_SITL_HEXA_Hovering_2.h"
#include "SITL_HEXA_Hovering_private.h"

// System initialize for atomic system:
void SITL_HEXA_Hovering_SinkBlock_Init(const
  px4_Bus_vehicle_local_position_setpoint *rtu_0,
  DW_SinkBlock_SITL_HEXA_Hovering_T *localDW)
{
  // Start for MATLABSystem: '<S17>/SinkBlock'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.orbMetadataObj = ORB_ID(vehicle_local_position_setpoint);
  uORB_write_initialize(localDW->obj.orbMetadataObj,
                        &localDW->obj.orbAdvertiseObj, rtu_0, 1);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void SITL_HEXA_Hovering_SinkBlock(const px4_Bus_vehicle_local_position_setpoint *
  rtu_0, DW_SinkBlock_SITL_HEXA_Hovering_T *localDW)
{
  // MATLABSystem: '<S17>/SinkBlock'
  uORB_write_step(localDW->obj.orbMetadataObj, &localDW->obj.orbAdvertiseObj,
                  rtu_0);
}

// Termination for atomic system:
void SITL_HEXA_Hovering_SinkBlock_Term(DW_SinkBlock_SITL_HEXA_Hovering_T
  *localDW)
{
  // Terminate for MATLABSystem: '<S17>/SinkBlock'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uORB_write_terminate(&localDW->obj.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S17>/SinkBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
