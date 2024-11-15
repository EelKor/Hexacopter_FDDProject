//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: uORBReadWrite_example.cpp
//
// Code generated for Simulink model 'uORBReadWrite_example'.
//
// Model version                  : 1.1
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Aug  1 15:06:36 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "uORBReadWrite_example.h"
#include <uORB/topics/vehicle_rates_setpoint.h>
#include "rtwtypes.h"

// Block signals (default storage)
B_uORBReadWrite_example_T uORBReadWrite_example_B;

// Block states (default storage)
DW_uORBReadWrite_example_T uORBReadWrite_example_DW;

// Real-time model
RT_MODEL_uORBReadWrite_exampl_T uORBReadWrite_example_M_ =
  RT_MODEL_uORBReadWrite_exampl_T();
RT_MODEL_uORBReadWrite_exampl_T *const uORBReadWrite_example_M =
  &uORBReadWrite_example_M_;

// Model step function
void uORBReadWrite_example_step(void)
{
  px4_Bus_vehicle_rates_setpoint rtb_BusAssignment;
  boolean_T b_varargout_1;

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<S1>/Constant'
  //   MATLABSystem: '<Root>/PX4 Timestamp'

  rtb_BusAssignment = uORBReadWrite_example_P.Constant_Value_l;
  rtb_BusAssignment.timestamp = hrt_absolute_time();

  // MATLABSystem: '<S2>/SourceBlock'
  b_varargout_1 = uORB_read_step(uORBReadWrite_example_DW.obj_p.orbMetadataObj,
    &uORBReadWrite_example_DW.obj_p.eventStructObj,
    &uORBReadWrite_example_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S2>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S4>/Enable'

  // Start for MATLABSystem: '<S2>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S4>/In1'
    uORBReadWrite_example_B.In1 = uORBReadWrite_example_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S2>/Enabled Subsystem'

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<Root>/Constant'
  //   Sum: '<Root>/Add'

  rtb_BusAssignment.roll = uORBReadWrite_example_B.In1.roll_body +
    uORBReadWrite_example_P.Constant_Value_e;
  rtb_BusAssignment.pitch = uORBReadWrite_example_B.In1.pitch_body;
  rtb_BusAssignment.yaw = uORBReadWrite_example_B.In1.yaw_body;

  // MATLABSystem: '<S3>/SinkBlock' incorporates:
  //   BusAssignment: '<Root>/Bus Assignment'

  uORB_write_step(uORBReadWrite_example_DW.obj_a.orbMetadataObj,
                  &uORBReadWrite_example_DW.obj_a.orbAdvertiseObj,
                  &rtb_BusAssignment);
}

// Model initialize function
void uORBReadWrite_example_initialize(void)
{
  {
    px4_Bus_vehicle_rates_setpoint rtb_BusAssignment;

    // SystemInitialize for Enabled SubSystem: '<S2>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S4>/In1' incorporates:
    //   Outport: '<S4>/Out1'

    uORBReadWrite_example_B.In1 = uORBReadWrite_example_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S2>/Enabled Subsystem'

    // Start for MATLABSystem: '<Root>/PX4 Timestamp'
    uORBReadWrite_example_DW.obj.matlabCodegenIsDeleted = false;
    uORBReadWrite_example_DW.obj.isInitialized = 1;
    uORBReadWrite_example_DW.obj.isSetupComplete = true;

    // Start for MATLABSystem: '<S2>/SourceBlock'
    uORBReadWrite_example_DW.obj_p.matlabCodegenIsDeleted = false;
    uORBReadWrite_example_DW.obj_p.isInitialized = 1;
    uORBReadWrite_example_DW.obj_p.orbMetadataObj = ORB_ID
      (vehicle_rates_setpoint);
    uORB_read_initialize(uORBReadWrite_example_DW.obj_p.orbMetadataObj,
                         &uORBReadWrite_example_DW.obj_p.eventStructObj);
    uORBReadWrite_example_DW.obj_p.isSetupComplete = true;

    // Start for MATLABSystem: '<S3>/SinkBlock' incorporates:
    //   BusAssignment: '<Root>/Bus Assignment'

    uORBReadWrite_example_DW.obj_a.matlabCodegenIsDeleted = false;
    uORBReadWrite_example_DW.obj_a.isInitialized = 1;
    uORBReadWrite_example_DW.obj_a.orbMetadataObj = ORB_ID
      (vehicle_rates_setpoint);
    uORB_write_initialize(uORBReadWrite_example_DW.obj_a.orbMetadataObj,
                          &uORBReadWrite_example_DW.obj_a.orbAdvertiseObj,
                          &rtb_BusAssignment, 1);
    uORBReadWrite_example_DW.obj_a.isSetupComplete = true;
  }
}

// Model terminate function
void uORBReadWrite_example_terminate(void)
{
  // Terminate for MATLABSystem: '<Root>/PX4 Timestamp'
  if (!uORBReadWrite_example_DW.obj.matlabCodegenIsDeleted) {
    uORBReadWrite_example_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 Timestamp'

  // Terminate for MATLABSystem: '<S2>/SourceBlock'
  if (!uORBReadWrite_example_DW.obj_p.matlabCodegenIsDeleted) {
    uORBReadWrite_example_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((uORBReadWrite_example_DW.obj_p.isInitialized == 1) &&
        uORBReadWrite_example_DW.obj_p.isSetupComplete) {
      uORB_read_terminate(&uORBReadWrite_example_DW.obj_p.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S2>/SourceBlock'

  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!uORBReadWrite_example_DW.obj_a.matlabCodegenIsDeleted) {
    uORBReadWrite_example_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((uORBReadWrite_example_DW.obj_a.isInitialized == 1) &&
        uORBReadWrite_example_DW.obj_a.isSetupComplete) {
      uORB_write_terminate(&uORBReadWrite_example_DW.obj_a.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
