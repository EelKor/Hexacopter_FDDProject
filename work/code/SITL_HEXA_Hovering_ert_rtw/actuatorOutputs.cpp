//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: actuatorOutputs.cpp
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
#include "actuatorOutputs.h"
#include "rt_sys_SITL_HEXA_Hovering_0.h"
#include "SITL_HEXA_Hovering.h"
#include "rtwtypes.h"
#include "SITL_HEXA_Hovering_private.h"

// System initialize for atomic system: '<Root>/actuatorOutputs'
void SITL_HEXA_Hovering_actuatorOutputs_Init(void)
{
  static const char_T ParameterNameStr[14] = "FDD_M1_STATUS";
  static const char_T ParameterNameStr_0[14] = "FDD_M2_STATUS";
  static const char_T ParameterNameStr_1[14] = "FDD_M3_STATUS";
  static const char_T ParameterNameStr_2[14] = "FDD_M4_STATUS";
  static const char_T ParameterNameStr_3[14] = "FDD_M5_STATUS";
  static const char_T ParameterNameStr_4[14] = "FDD_M6_STATUS";
  real_T tmp;

  // Start for MATLABSystem: '<S596>/Read Parameter13'
  SITL_HEXA_Hovering_DW.obj_j.matlabCodegenIsDeleted = false;
  SITL_HEXA_Hovering_DW.obj_j.SampleTime =
    SITL_HEXA_Hovering_P.ReadParameter13_SampleTime;
  SITL_HEXA_Hovering_DW.obj_j.isInitialized = 1;
  if (SITL_HEXA_Hovering_DW.obj_j.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = SITL_HEXA_Hovering_DW.obj_j.SampleTime;
  }

  SITL_HEXA_Hovering_DW.obj_j.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0],
    true, tmp * 1000.0);
  SITL_HEXA_Hovering_DW.obj_j.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S596>/Read Parameter13'

  // Start for MATLABSystem: '<S596>/Read Parameter1'
  SITL_HEXA_Hovering_DW.obj_i.matlabCodegenIsDeleted = false;
  SITL_HEXA_Hovering_DW.obj_i.SampleTime =
    SITL_HEXA_Hovering_P.ReadParameter1_SampleTime;
  SITL_HEXA_Hovering_DW.obj_i.isInitialized = 1;
  if (SITL_HEXA_Hovering_DW.obj_i.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = SITL_HEXA_Hovering_DW.obj_i.SampleTime;
  }

  SITL_HEXA_Hovering_DW.obj_i.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_0[0], true, tmp * 1000.0);
  SITL_HEXA_Hovering_DW.obj_i.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S596>/Read Parameter1'

  // Start for MATLABSystem: '<S596>/Read Parameter2'
  SITL_HEXA_Hovering_DW.obj_d.matlabCodegenIsDeleted = false;
  SITL_HEXA_Hovering_DW.obj_d.SampleTime =
    SITL_HEXA_Hovering_P.ReadParameter2_SampleTime;
  SITL_HEXA_Hovering_DW.obj_d.isInitialized = 1;
  if (SITL_HEXA_Hovering_DW.obj_d.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = SITL_HEXA_Hovering_DW.obj_d.SampleTime;
  }

  SITL_HEXA_Hovering_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_1[0], true, tmp * 1000.0);
  SITL_HEXA_Hovering_DW.obj_d.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S596>/Read Parameter2'

  // Start for MATLABSystem: '<S596>/Read Parameter3'
  SITL_HEXA_Hovering_DW.obj_g.matlabCodegenIsDeleted = false;
  SITL_HEXA_Hovering_DW.obj_g.SampleTime =
    SITL_HEXA_Hovering_P.ReadParameter3_SampleTime;
  SITL_HEXA_Hovering_DW.obj_g.isInitialized = 1;
  if (SITL_HEXA_Hovering_DW.obj_g.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = SITL_HEXA_Hovering_DW.obj_g.SampleTime;
  }

  SITL_HEXA_Hovering_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_2[0], true, tmp * 1000.0);
  SITL_HEXA_Hovering_DW.obj_g.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S596>/Read Parameter3'

  // Start for MATLABSystem: '<S596>/Read Parameter4'
  SITL_HEXA_Hovering_DW.obj_o.matlabCodegenIsDeleted = false;
  SITL_HEXA_Hovering_DW.obj_o.SampleTime =
    SITL_HEXA_Hovering_P.ReadParameter4_SampleTime;
  SITL_HEXA_Hovering_DW.obj_o.isInitialized = 1;
  if (SITL_HEXA_Hovering_DW.obj_o.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = SITL_HEXA_Hovering_DW.obj_o.SampleTime;
  }

  SITL_HEXA_Hovering_DW.obj_o.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_3[0], true, tmp * 1000.0);
  SITL_HEXA_Hovering_DW.obj_o.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S596>/Read Parameter4'

  // Start for MATLABSystem: '<S596>/Read Parameter'
  SITL_HEXA_Hovering_DW.obj_jb.matlabCodegenIsDeleted = false;
  SITL_HEXA_Hovering_DW.obj_jb.SampleTime =
    SITL_HEXA_Hovering_P.ReadParameter_SampleTime_n;
  SITL_HEXA_Hovering_DW.obj_jb.isInitialized = 1;
  if (SITL_HEXA_Hovering_DW.obj_jb.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = SITL_HEXA_Hovering_DW.obj_jb.SampleTime;
  }

  SITL_HEXA_Hovering_DW.obj_jb.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_4[0], true, tmp * 1000.0);
  SITL_HEXA_Hovering_DW.obj_jb.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S596>/Read Parameter'
  SITL_HEXA_Hovering_PX4Timestamp_Init(&SITL_HEXA_Hovering_DW.PX4Timestamp1);

  // Start for MATLABSystem: '<S601>/SinkBlock' incorporates:
  //   BusAssignment: '<S595>/Bus Assignment'

  SITL_HEXA_Hovering_DW.obj_kg.matlabCodegenIsDeleted = false;
  SITL_HEXA_Hovering_DW.obj_kg.isInitialized = 1;
  SITL_HEXA_Hovering_DW.obj_kg.orbMetadataObj = ORB_ID(actuator_motors);
  uORB_write_initialize(SITL_HEXA_Hovering_DW.obj_kg.orbMetadataObj,
                        &SITL_HEXA_Hovering_DW.obj_kg.orbAdvertiseObj,
                        &SITL_HEXA_Hovering_B.BusAssignment, 1);
  SITL_HEXA_Hovering_DW.obj_kg.isSetupComplete = true;

  // Start for MATLABSystem: '<S598>/SourceBlock'
  SITL_HEXA_Hovering_DW.obj_kd.matlabCodegenIsDeleted = false;
  SITL_HEXA_Hovering_DW.obj_kd.isInitialized = 1;
  SITL_HEXA_Hovering_DW.obj_kd.orbMetadataObj = ORB_ID(input_rc);
  uORB_read_initialize(SITL_HEXA_Hovering_DW.obj_kd.orbMetadataObj,
                       &SITL_HEXA_Hovering_DW.obj_kd.eventStructObj);
  SITL_HEXA_Hovering_DW.obj_kd.isSetupComplete = true;
}

// Output and update for atomic system: '<Root>/actuatorOutputs'
void SITL_HEXA_Hovering_actuatorOutputs(void)
{
  real_T u0;
  real_T u0_0;
  real_T u0_1;
  real_T u0_2;
  int32_T ParamStep;
  int32_T ParamStep_0;
  int32_T ParamStep_1;
  int32_T ParamStep_2;
  int32_T ParamStep_3;
  int32_T ParamStep_4;
  boolean_T b_varargout_2;

  // Gain: '<S3>/Gain'
  SITL_HEXA_Hovering_B.Saturation3 = SITL_HEXA_Hovering_P.Gain_Gain_h *
    SITL_HEXA_Hovering_B.Saturation_b;

  // Saturate: '<S3>/Saturation3'
  if (SITL_HEXA_Hovering_B.Saturation3 >
      SITL_HEXA_Hovering_P.Saturation3_UpperSat) {
    SITL_HEXA_Hovering_B.Saturation3 = SITL_HEXA_Hovering_P.Saturation3_UpperSat;
  } else if (SITL_HEXA_Hovering_B.Saturation3 <
             SITL_HEXA_Hovering_P.Saturation3_LowerSat) {
    SITL_HEXA_Hovering_B.Saturation3 = SITL_HEXA_Hovering_P.Saturation3_LowerSat;
  }

  // End of Saturate: '<S3>/Saturation3'

  // Gain: '<S3>/Gain1'
  SITL_HEXA_Hovering_B.Saturation2 = SITL_HEXA_Hovering_P.Gain1_Gain_e *
    SITL_HEXA_Hovering_B.Saturation_c;

  // Saturate: '<S3>/Saturation2'
  if (SITL_HEXA_Hovering_B.Saturation2 >
      SITL_HEXA_Hovering_P.Saturation2_UpperSat) {
    SITL_HEXA_Hovering_B.Saturation2 = SITL_HEXA_Hovering_P.Saturation2_UpperSat;
  } else if (SITL_HEXA_Hovering_B.Saturation2 <
             SITL_HEXA_Hovering_P.Saturation2_LowerSat) {
    SITL_HEXA_Hovering_B.Saturation2 = SITL_HEXA_Hovering_P.Saturation2_LowerSat;
  }

  // End of Saturate: '<S3>/Saturation2'

  // Gain: '<S3>/Gain2'
  SITL_HEXA_Hovering_B.Saturation1 = SITL_HEXA_Hovering_P.Gain2_Gain_h *
    SITL_HEXA_Hovering_B.Saturation;

  // Saturate: '<S3>/Saturation1'
  if (SITL_HEXA_Hovering_B.Saturation1 >
      SITL_HEXA_Hovering_P.Saturation1_UpperSat) {
    SITL_HEXA_Hovering_B.Saturation1 = SITL_HEXA_Hovering_P.Saturation1_UpperSat;
  } else if (SITL_HEXA_Hovering_B.Saturation1 <
             SITL_HEXA_Hovering_P.Saturation1_LowerSat) {
    SITL_HEXA_Hovering_B.Saturation1 = SITL_HEXA_Hovering_P.Saturation1_LowerSat;
  }

  // End of Saturate: '<S3>/Saturation1'

  // Saturate: '<S3>/Saturation'
  if (SITL_HEXA_Hovering_B.Saturation_d >
      SITL_HEXA_Hovering_P.Saturation_UpperSat) {
    SITL_HEXA_Hovering_B.Saturation_cl =
      SITL_HEXA_Hovering_P.Saturation_UpperSat;
  } else if (SITL_HEXA_Hovering_B.Saturation_d <
             SITL_HEXA_Hovering_P.Saturation_LowerSat) {
    SITL_HEXA_Hovering_B.Saturation_cl =
      SITL_HEXA_Hovering_P.Saturation_LowerSat;
  } else {
    SITL_HEXA_Hovering_B.Saturation_cl = SITL_HEXA_Hovering_B.Saturation_d;
  }

  // End of Saturate: '<S3>/Saturation'

  // MATLAB Function: '<S3>/MATLAB Function'
  SITL_HEXA_Hovering_B.u0 = (-SITL_HEXA_Hovering_B.Saturation3 -
    SITL_HEXA_Hovering_B.Saturation1) * SITL_HEXA_Hovering_B.Saturation_cl / 3.0
    + SITL_HEXA_Hovering_B.Saturation_cl;
  u0 = (SITL_HEXA_Hovering_B.Saturation3 + SITL_HEXA_Hovering_B.Saturation1) *
    SITL_HEXA_Hovering_B.Saturation_cl / 3.0 +
    SITL_HEXA_Hovering_B.Saturation_cl;
  u0_0 = ((SITL_HEXA_Hovering_B.Saturation3 / 2.0 +
           SITL_HEXA_Hovering_B.Saturation2) - SITL_HEXA_Hovering_B.Saturation1)
    * SITL_HEXA_Hovering_B.Saturation_cl / 3.0 +
    SITL_HEXA_Hovering_B.Saturation_cl;
  u0_1 = ((-SITL_HEXA_Hovering_B.Saturation2 - SITL_HEXA_Hovering_B.Saturation3 /
           2.0) + SITL_HEXA_Hovering_B.Saturation1) *
    SITL_HEXA_Hovering_B.Saturation_cl / 3.0 +
    SITL_HEXA_Hovering_B.Saturation_cl;
  u0_2 = ((SITL_HEXA_Hovering_B.Saturation2 - SITL_HEXA_Hovering_B.Saturation3 /
           2.0) + SITL_HEXA_Hovering_B.Saturation1) *
    SITL_HEXA_Hovering_B.Saturation_cl / 3.0 +
    SITL_HEXA_Hovering_B.Saturation_cl;
  SITL_HEXA_Hovering_B.Saturation3 = ((SITL_HEXA_Hovering_B.Saturation3 / 2.0 -
    SITL_HEXA_Hovering_B.Saturation2) - SITL_HEXA_Hovering_B.Saturation1) *
    SITL_HEXA_Hovering_B.Saturation_cl / 3.0 +
    SITL_HEXA_Hovering_B.Saturation_cl;

  // MATLABSystem: '<S596>/Read Parameter13'
  if (SITL_HEXA_Hovering_DW.obj_j.SampleTime !=
      SITL_HEXA_Hovering_P.ReadParameter13_SampleTime) {
    SITL_HEXA_Hovering_DW.obj_j.SampleTime =
      SITL_HEXA_Hovering_P.ReadParameter13_SampleTime;
  }

  b_varargout_2 = MW_Param_Step(SITL_HEXA_Hovering_DW.obj_j.MW_PARAMHANDLE,
    MW_INT32, &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0;
  }

  // MATLABSystem: '<S596>/Read Parameter1'
  if (SITL_HEXA_Hovering_DW.obj_i.SampleTime !=
      SITL_HEXA_Hovering_P.ReadParameter1_SampleTime) {
    SITL_HEXA_Hovering_DW.obj_i.SampleTime =
      SITL_HEXA_Hovering_P.ReadParameter1_SampleTime;
  }

  b_varargout_2 = MW_Param_Step(SITL_HEXA_Hovering_DW.obj_i.MW_PARAMHANDLE,
    MW_INT32, &ParamStep_0);
  if (b_varargout_2) {
    ParamStep_0 = 0;
  }

  // MATLABSystem: '<S596>/Read Parameter2'
  if (SITL_HEXA_Hovering_DW.obj_d.SampleTime !=
      SITL_HEXA_Hovering_P.ReadParameter2_SampleTime) {
    SITL_HEXA_Hovering_DW.obj_d.SampleTime =
      SITL_HEXA_Hovering_P.ReadParameter2_SampleTime;
  }

  b_varargout_2 = MW_Param_Step(SITL_HEXA_Hovering_DW.obj_d.MW_PARAMHANDLE,
    MW_INT32, &ParamStep_1);
  if (b_varargout_2) {
    ParamStep_1 = 0;
  }

  // MATLABSystem: '<S596>/Read Parameter3'
  if (SITL_HEXA_Hovering_DW.obj_g.SampleTime !=
      SITL_HEXA_Hovering_P.ReadParameter3_SampleTime) {
    SITL_HEXA_Hovering_DW.obj_g.SampleTime =
      SITL_HEXA_Hovering_P.ReadParameter3_SampleTime;
  }

  b_varargout_2 = MW_Param_Step(SITL_HEXA_Hovering_DW.obj_g.MW_PARAMHANDLE,
    MW_INT32, &ParamStep_2);
  if (b_varargout_2) {
    ParamStep_2 = 0;
  }

  // MATLABSystem: '<S596>/Read Parameter4'
  if (SITL_HEXA_Hovering_DW.obj_o.SampleTime !=
      SITL_HEXA_Hovering_P.ReadParameter4_SampleTime) {
    SITL_HEXA_Hovering_DW.obj_o.SampleTime =
      SITL_HEXA_Hovering_P.ReadParameter4_SampleTime;
  }

  b_varargout_2 = MW_Param_Step(SITL_HEXA_Hovering_DW.obj_o.MW_PARAMHANDLE,
    MW_INT32, &ParamStep_3);
  if (b_varargout_2) {
    ParamStep_3 = 0;
  }

  // MATLABSystem: '<S596>/Read Parameter'
  if (SITL_HEXA_Hovering_DW.obj_jb.SampleTime !=
      SITL_HEXA_Hovering_P.ReadParameter_SampleTime_n) {
    SITL_HEXA_Hovering_DW.obj_jb.SampleTime =
      SITL_HEXA_Hovering_P.ReadParameter_SampleTime_n;
  }

  b_varargout_2 = MW_Param_Step(SITL_HEXA_Hovering_DW.obj_jb.MW_PARAMHANDLE,
    MW_INT32, &ParamStep_4);
  if (b_varargout_2) {
    ParamStep_4 = 0;
  }

  SITL_HEXA_Hovering_PX4Timestamp(&SITL_HEXA_Hovering_B.PX4Timestamp1);

  // BusAssignment: '<S595>/Bus Assignment' incorporates:
  //   Constant: '<S600>/Constant'

  SITL_HEXA_Hovering_B.BusAssignment = SITL_HEXA_Hovering_P.Constant_Value_a;

  // BusAssignment: '<S595>/Bus Assignment' incorporates:
  //   MATLABSystem: '<S595>/PX4 Timestamp1'

  SITL_HEXA_Hovering_B.BusAssignment.timestamp =
    SITL_HEXA_Hovering_B.PX4Timestamp1.PX4Timestamp;

  // Saturate: '<S3>/Saturation4'
  if (SITL_HEXA_Hovering_B.u0 > SITL_HEXA_Hovering_P.Saturation4_UpperSat) {
    SITL_HEXA_Hovering_B.u0 = SITL_HEXA_Hovering_P.Saturation4_UpperSat;
  } else if (SITL_HEXA_Hovering_B.u0 < SITL_HEXA_Hovering_P.Saturation4_LowerSat)
  {
    SITL_HEXA_Hovering_B.u0 = SITL_HEXA_Hovering_P.Saturation4_LowerSat;
  }

  // BusAssignment: '<S595>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S595>/Data Type Conversion'
  //   DataTypeConversion: '<S596>/Data Type Conversion3'
  //   Gain: '<S596>/Gain'
  //   MATLABSystem: '<S596>/Read Parameter13'
  //   Product: '<S596>/Product'
  //   Saturate: '<S3>/Saturation4'
  //
  SITL_HEXA_Hovering_B.BusAssignment.control[0] = static_cast<real32_T>
    (SITL_HEXA_Hovering_P.Gain_Gain_b * static_cast<real_T>(ParamStep) *
     SITL_HEXA_Hovering_B.u0);

  // Saturate: '<S3>/Saturation4'
  if (u0 > SITL_HEXA_Hovering_P.Saturation4_UpperSat) {
    u0 = SITL_HEXA_Hovering_P.Saturation4_UpperSat;
  } else if (u0 < SITL_HEXA_Hovering_P.Saturation4_LowerSat) {
    u0 = SITL_HEXA_Hovering_P.Saturation4_LowerSat;
  }

  // BusAssignment: '<S595>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S595>/Data Type Conversion'
  //   DataTypeConversion: '<S596>/Data Type Conversion1'
  //   Gain: '<S596>/Gain1'
  //   MATLABSystem: '<S596>/Read Parameter1'
  //   Product: '<S596>/Product1'
  //   Saturate: '<S3>/Saturation4'
  //
  SITL_HEXA_Hovering_B.BusAssignment.control[1] = static_cast<real32_T>
    (SITL_HEXA_Hovering_P.Gain1_Gain_o * static_cast<real_T>(ParamStep_0) * u0);

  // Saturate: '<S3>/Saturation4'
  if (u0_0 > SITL_HEXA_Hovering_P.Saturation4_UpperSat) {
    u0_0 = SITL_HEXA_Hovering_P.Saturation4_UpperSat;
  } else if (u0_0 < SITL_HEXA_Hovering_P.Saturation4_LowerSat) {
    u0_0 = SITL_HEXA_Hovering_P.Saturation4_LowerSat;
  }

  // BusAssignment: '<S595>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S595>/Data Type Conversion'
  //   DataTypeConversion: '<S596>/Data Type Conversion2'
  //   Gain: '<S596>/Gain2'
  //   MATLABSystem: '<S596>/Read Parameter2'
  //   Product: '<S596>/Product2'
  //   Saturate: '<S3>/Saturation4'
  //
  SITL_HEXA_Hovering_B.BusAssignment.control[2] = static_cast<real32_T>
    (SITL_HEXA_Hovering_P.Gain2_Gain_d * static_cast<real_T>(ParamStep_1) * u0_0);

  // Saturate: '<S3>/Saturation4'
  if (u0_1 > SITL_HEXA_Hovering_P.Saturation4_UpperSat) {
    u0_1 = SITL_HEXA_Hovering_P.Saturation4_UpperSat;
  } else if (u0_1 < SITL_HEXA_Hovering_P.Saturation4_LowerSat) {
    u0_1 = SITL_HEXA_Hovering_P.Saturation4_LowerSat;
  }

  // BusAssignment: '<S595>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S595>/Data Type Conversion'
  //   DataTypeConversion: '<S596>/Data Type Conversion4'
  //   Gain: '<S596>/Gain3'
  //   MATLABSystem: '<S596>/Read Parameter3'
  //   Product: '<S596>/Product3'
  //   Saturate: '<S3>/Saturation4'
  //
  SITL_HEXA_Hovering_B.BusAssignment.control[3] = static_cast<real32_T>
    (SITL_HEXA_Hovering_P.Gain3_Gain * static_cast<real_T>(ParamStep_2) * u0_1);

  // Saturate: '<S3>/Saturation4'
  if (u0_2 > SITL_HEXA_Hovering_P.Saturation4_UpperSat) {
    u0_2 = SITL_HEXA_Hovering_P.Saturation4_UpperSat;
  } else if (u0_2 < SITL_HEXA_Hovering_P.Saturation4_LowerSat) {
    u0_2 = SITL_HEXA_Hovering_P.Saturation4_LowerSat;
  }

  // BusAssignment: '<S595>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S595>/Data Type Conversion'
  //   DataTypeConversion: '<S596>/Data Type Conversion5'
  //   Gain: '<S596>/Gain4'
  //   MATLABSystem: '<S596>/Read Parameter4'
  //   Product: '<S596>/Product4'
  //   Saturate: '<S3>/Saturation4'
  //
  SITL_HEXA_Hovering_B.BusAssignment.control[4] = static_cast<real32_T>
    (SITL_HEXA_Hovering_P.Gain4_Gain * static_cast<real_T>(ParamStep_3) * u0_2);

  // Saturate: '<S3>/Saturation4'
  if (SITL_HEXA_Hovering_B.Saturation3 >
      SITL_HEXA_Hovering_P.Saturation4_UpperSat) {
    SITL_HEXA_Hovering_B.Saturation3 = SITL_HEXA_Hovering_P.Saturation4_UpperSat;
  } else if (SITL_HEXA_Hovering_B.Saturation3 <
             SITL_HEXA_Hovering_P.Saturation4_LowerSat) {
    SITL_HEXA_Hovering_B.Saturation3 = SITL_HEXA_Hovering_P.Saturation4_LowerSat;
  }

  // BusAssignment: '<S595>/Bus Assignment' incorporates:
  //   Constant: '<S595>/Constant'
  //   DataTypeConversion: '<S595>/Data Type Conversion'
  //   DataTypeConversion: '<S596>/Data Type Conversion6'
  //   Gain: '<S596>/Gain5'
  //   MATLABSystem: '<S596>/Read Parameter'
  //   Product: '<S596>/Product5'
  //   Saturate: '<S3>/Saturation4'
  //
  SITL_HEXA_Hovering_B.BusAssignment.control[5] = static_cast<real32_T>
    (SITL_HEXA_Hovering_P.Gain5_Gain * static_cast<real_T>(ParamStep_4) *
     SITL_HEXA_Hovering_B.Saturation3);
  SITL_HEXA_Hovering_B.BusAssignment.control[6] = static_cast<real32_T>
    (SITL_HEXA_Hovering_P.Constant_Value_a0);
  SITL_HEXA_Hovering_B.BusAssignment.control[7] = static_cast<real32_T>
    (SITL_HEXA_Hovering_P.Constant_Value_a0);
  SITL_HEXA_Hovering_B.BusAssignment.control[8] = static_cast<real32_T>
    (SITL_HEXA_Hovering_P.Constant_Value_a0);
  SITL_HEXA_Hovering_B.BusAssignment.control[9] = static_cast<real32_T>
    (SITL_HEXA_Hovering_P.Constant_Value_a0);
  SITL_HEXA_Hovering_B.BusAssignment.control[10] = static_cast<real32_T>
    (SITL_HEXA_Hovering_P.Constant_Value_a0);
  SITL_HEXA_Hovering_B.BusAssignment.control[11] = static_cast<real32_T>
    (SITL_HEXA_Hovering_P.Constant_Value_a0);

  // MATLABSystem: '<S601>/SinkBlock' incorporates:
  //   BusAssignment: '<S595>/Bus Assignment'

  uORB_write_step(SITL_HEXA_Hovering_DW.obj_kg.orbMetadataObj,
                  &SITL_HEXA_Hovering_DW.obj_kg.orbAdvertiseObj,
                  &SITL_HEXA_Hovering_B.BusAssignment);

  // MATLABSystem: '<S598>/SourceBlock'
  uORB_read_step(SITL_HEXA_Hovering_DW.obj_kd.orbMetadataObj,
                 &SITL_HEXA_Hovering_DW.obj_kd.eventStructObj,
                 &SITL_HEXA_Hovering_B.r_m, false, 5000.0);
}

// Termination for atomic system: '<Root>/actuatorOutputs'
void SITL_HEXA_Hovering_actuatorOutputs_Term(void)
{
  // Terminate for MATLABSystem: '<S596>/Read Parameter13'
  if (!SITL_HEXA_Hovering_DW.obj_j.matlabCodegenIsDeleted) {
    SITL_HEXA_Hovering_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S596>/Read Parameter13'

  // Terminate for MATLABSystem: '<S596>/Read Parameter1'
  if (!SITL_HEXA_Hovering_DW.obj_i.matlabCodegenIsDeleted) {
    SITL_HEXA_Hovering_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S596>/Read Parameter1'

  // Terminate for MATLABSystem: '<S596>/Read Parameter2'
  if (!SITL_HEXA_Hovering_DW.obj_d.matlabCodegenIsDeleted) {
    SITL_HEXA_Hovering_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S596>/Read Parameter2'

  // Terminate for MATLABSystem: '<S596>/Read Parameter3'
  if (!SITL_HEXA_Hovering_DW.obj_g.matlabCodegenIsDeleted) {
    SITL_HEXA_Hovering_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S596>/Read Parameter3'

  // Terminate for MATLABSystem: '<S596>/Read Parameter4'
  if (!SITL_HEXA_Hovering_DW.obj_o.matlabCodegenIsDeleted) {
    SITL_HEXA_Hovering_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S596>/Read Parameter4'

  // Terminate for MATLABSystem: '<S596>/Read Parameter'
  if (!SITL_HEXA_Hovering_DW.obj_jb.matlabCodegenIsDeleted) {
    SITL_HEXA_Hovering_DW.obj_jb.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S596>/Read Parameter'
  SITL_HEXA_Hovering_PX4Timestamp_Term(&SITL_HEXA_Hovering_DW.PX4Timestamp1);

  // Terminate for MATLABSystem: '<S601>/SinkBlock'
  if (!SITL_HEXA_Hovering_DW.obj_kg.matlabCodegenIsDeleted) {
    SITL_HEXA_Hovering_DW.obj_kg.matlabCodegenIsDeleted = true;
    if ((SITL_HEXA_Hovering_DW.obj_kg.isInitialized == 1) &&
        SITL_HEXA_Hovering_DW.obj_kg.isSetupComplete) {
      uORB_write_terminate(&SITL_HEXA_Hovering_DW.obj_kg.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S601>/SinkBlock'

  // Terminate for MATLABSystem: '<S598>/SourceBlock'
  if (!SITL_HEXA_Hovering_DW.obj_kd.matlabCodegenIsDeleted) {
    SITL_HEXA_Hovering_DW.obj_kd.matlabCodegenIsDeleted = true;
    if ((SITL_HEXA_Hovering_DW.obj_kd.isInitialized == 1) &&
        SITL_HEXA_Hovering_DW.obj_kd.isSetupComplete) {
      uORB_read_terminate(&SITL_HEXA_Hovering_DW.obj_kd.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S598>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
