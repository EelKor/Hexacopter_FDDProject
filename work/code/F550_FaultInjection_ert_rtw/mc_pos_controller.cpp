//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mc_pos_controller.cpp
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
#include "mc_pos_controller.h"
#include "F550_FaultInjection.h"
#include "rtwtypes.h"
#include <math.h>
#include "F550_FaultInjection_private.h"

// System initialize for action system: '<S2>/mc_pos_controller'
void F550_FaultInjection_mc_pos_controller_Init(void)
{
  static const char_T ParameterNameStr[15] = "SL_XY_TILT_MAX";
  static const char_T ParameterNameStr_0[15] = "SL_YAWRATE_MAX";
  static const char_T ParameterNameStr_1[14] = "SL_XY_VEL_MAX";
  static const char_T ParameterNameStr_2[8] = "SL_XY_P";
  static const char_T ParameterNameStr_3[16] = "SL_XY_VEL_P_ACC";
  static const char_T ParameterNameStr_4[9] = "SL_YAW_P";
  static const char_T ParameterNameStr_5[7] = "SL_Z_P";
  static const char_T ParameterNameStr_6[16] = "SL_Z_VEL_MAX_UP";
  static const char_T ParameterNameStr_7[16] = "SL_Z_VEL_MAX_DN";
  static const char_T ParameterNameStr_8[15] = "SL_Z_VEL_P_ACC";
  static const char_T ParameterNameStr_9[15] = "SL_Z_VEL_D_ACC";
  static const char_T ParameterNameStr_a[15] = "SL_Z_VEL_I_ACC";
  real_T tmp;

  // InitializeConditions for DiscreteIntegrator: '<S384>/Filter'
  F550_FaultInjection_DW.Filter_DSTATE_k =
    F550_FaultInjection_P.PID_vz_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S389>/Integrator'
  F550_FaultInjection_DW.Integrator_DSTATE_o =
    F550_FaultInjection_P.PID_vz_InitialConditionForIntegrator;

  // Start for MATLABSystem: '<S30>/Read Parameter3'
  F550_FaultInjection_DW.obj_f.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_f.SampleTime =
    F550_FaultInjection_P.ReadParameter3_SampleTime_l;
  F550_FaultInjection_DW.obj_f.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_f.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_f.SampleTime;
  }

  F550_FaultInjection_DW.obj_f.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr
    [0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_f.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter3'

  // Start for MATLABSystem: '<S30>/Read Parameter11'
  F550_FaultInjection_DW.obj_kf.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_kf.SampleTime =
    F550_FaultInjection_P.ReadParameter11_SampleTime;
  F550_FaultInjection_DW.obj_kf.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_kf.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_kf.SampleTime;
  }

  F550_FaultInjection_DW.obj_kf.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_0[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_kf.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter11'

  // Start for MATLABSystem: '<S30>/Read Parameter1'
  F550_FaultInjection_DW.obj_j0.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_j0.SampleTime =
    F550_FaultInjection_P.ReadParameter1_SampleTime_o;
  F550_FaultInjection_DW.obj_j0.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_j0.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_j0.SampleTime;
  }

  F550_FaultInjection_DW.obj_j0.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_1[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_j0.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter1'

  // Start for MATLABSystem: '<S30>/Read Parameter'
  F550_FaultInjection_DW.obj_bu.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_bu.SampleTime =
    F550_FaultInjection_P.ReadParameter_SampleTime;
  F550_FaultInjection_DW.obj_bu.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_bu.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_bu.SampleTime;
  }

  F550_FaultInjection_DW.obj_bu.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_2[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_bu.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter'

  // Start for MATLABSystem: '<S30>/Read Parameter2'
  F550_FaultInjection_DW.obj_pc.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_pc.SampleTime =
    F550_FaultInjection_P.ReadParameter2_SampleTime_m;
  F550_FaultInjection_DW.obj_pc.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_pc.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_pc.SampleTime;
  }

  F550_FaultInjection_DW.obj_pc.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_3[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_pc.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter2'

  // Start for MATLABSystem: '<S30>/Read Parameter4'
  F550_FaultInjection_DW.obj_ds.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_ds.SampleTime =
    F550_FaultInjection_P.ReadParameter4_SampleTime_b;
  F550_FaultInjection_DW.obj_ds.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_ds.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_ds.SampleTime;
  }

  F550_FaultInjection_DW.obj_ds.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_4[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_ds.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter4'

  // Start for MATLABSystem: '<S30>/Read Parameter12'
  F550_FaultInjection_DW.obj_mn.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_mn.SampleTime =
    F550_FaultInjection_P.ReadParameter12_SampleTime;
  F550_FaultInjection_DW.obj_mn.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_mn.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_mn.SampleTime;
  }

  F550_FaultInjection_DW.obj_mn.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_5[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_mn.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter12'

  // Start for MATLABSystem: '<S30>/Read Parameter8'
  F550_FaultInjection_DW.obj_l0.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_l0.SampleTime =
    F550_FaultInjection_P.ReadParameter8_SampleTime;
  F550_FaultInjection_DW.obj_l0.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_l0.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_l0.SampleTime;
  }

  F550_FaultInjection_DW.obj_l0.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_6[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_l0.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter8'

  // Start for MATLABSystem: '<S30>/Read Parameter7'
  F550_FaultInjection_DW.obj_d3.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_d3.SampleTime =
    F550_FaultInjection_P.ReadParameter7_SampleTime;
  F550_FaultInjection_DW.obj_d3.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_d3.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_d3.SampleTime;
  }

  F550_FaultInjection_DW.obj_d3.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_7[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_d3.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter7'

  // Start for MATLABSystem: '<S30>/Read Parameter13'
  F550_FaultInjection_DW.obj_km.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_km.SampleTime =
    F550_FaultInjection_P.ReadParameter13_SampleTime_c;
  F550_FaultInjection_DW.obj_km.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_km.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_km.SampleTime;
  }

  F550_FaultInjection_DW.obj_km.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_8[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_km.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter13'

  // Start for MATLABSystem: '<S30>/Read Parameter15'
  F550_FaultInjection_DW.obj_ba.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_ba.SampleTime =
    F550_FaultInjection_P.ReadParameter15_SampleTime;
  F550_FaultInjection_DW.obj_ba.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_ba.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_ba.SampleTime;
  }

  F550_FaultInjection_DW.obj_ba.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_9[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_ba.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter15'

  // Start for MATLABSystem: '<S30>/Read Parameter14'
  F550_FaultInjection_DW.obj_a.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_a.SampleTime =
    F550_FaultInjection_P.ReadParameter14_SampleTime;
  F550_FaultInjection_DW.obj_a.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_a.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_a.SampleTime;
  }

  F550_FaultInjection_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_a[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_a.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter14'
}

// Output and update for action system: '<S2>/mc_pos_controller'
void F550_FaultInjection_mc_pos_controller(void)
{
  real_T rtb_Sum5;
  real_T rtb_Switch2_0;
  real_T rtb_Switch2_idx_0;
  real_T rtb_Switch2_idx_0_0;
  real_T rtb_Switch2_idx_1;
  real32_T ParamStep;
  real32_T ParamStep_0;
  real32_T rtb_Gain1_e1;
  real32_T rtb_Gain1_hf;
  real32_T rtb_Gain2;
  int8_T rtb_Switch1_h;
  int8_T tmp;
  boolean_T b_varargout_2;
  boolean_T rtb_RelationalOperator;

  // Gain: '<S149>/Gain1'
  F550_FaultInjection_B.Gain1 = F550_FaultInjection_P.Gain1_Gain_j *
    F550_FaultInjection_B.DataTypeConversion1[2];

  // Trigonometry: '<S150>/SinCos'
  F550_FaultInjection_B.IProdOut = sin(F550_FaultInjection_B.Merge[3]);
  F550_FaultInjection_B.Sum = cos(F550_FaultInjection_B.Merge[3]);

  // Sum: '<S30>/Sum5'
  rtb_Sum5 = F550_FaultInjection_B.Merge[3] -
    F550_FaultInjection_B.VectorConcatenate[0];

  // Switch: '<S151>/Switch' incorporates:
  //   Abs: '<S151>/Abs'

  if (fabs(rtb_Sum5) > F550_FaultInjection_P.Switch_Threshold) {
    // Switch: '<S151>/Switch1' incorporates:
    //   Constant: '<S151>/Constant'
    //   Sum: '<S151>/Add'
    //   Sum: '<S151>/Subtract'

    if (rtb_Sum5 > F550_FaultInjection_P.Switch1_Threshold) {
      rtb_Sum5 -= F550_FaultInjection_P.Constant_Value_jc;
    } else {
      rtb_Sum5 += F550_FaultInjection_P.Constant_Value_jc;
    }

    // End of Switch: '<S151>/Switch1'
  }

  // End of Switch: '<S151>/Switch'

  // MATLABSystem: '<S30>/Read Parameter3'
  if (F550_FaultInjection_DW.obj_f.SampleTime !=
      F550_FaultInjection_P.ReadParameter3_SampleTime_l) {
    F550_FaultInjection_DW.obj_f.SampleTime =
      F550_FaultInjection_P.ReadParameter3_SampleTime_l;
  }

  b_varargout_2 = MW_Param_Step(F550_FaultInjection_DW.obj_f.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // Gain: '<S152>/Gain1' incorporates:
  //   MATLABSystem: '<S30>/Read Parameter3'
  //
  rtb_Gain1_e1 = F550_FaultInjection_P.Gain1_Gain_p * ParamStep;

  // MATLABSystem: '<S30>/Read Parameter11'
  if (F550_FaultInjection_DW.obj_kf.SampleTime !=
      F550_FaultInjection_P.ReadParameter11_SampleTime) {
    F550_FaultInjection_DW.obj_kf.SampleTime =
      F550_FaultInjection_P.ReadParameter11_SampleTime;
  }

  b_varargout_2 = MW_Param_Step(F550_FaultInjection_DW.obj_kf.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // Gain: '<S153>/Gain1' incorporates:
  //   MATLABSystem: '<S30>/Read Parameter11'
  //
  rtb_Gain1_hf = F550_FaultInjection_P.Gain1_Gain_f * ParamStep;

  // MATLABSystem: '<S30>/Read Parameter1'
  if (F550_FaultInjection_DW.obj_j0.SampleTime !=
      F550_FaultInjection_P.ReadParameter1_SampleTime_o) {
    F550_FaultInjection_DW.obj_j0.SampleTime =
      F550_FaultInjection_P.ReadParameter1_SampleTime_o;
  }

  b_varargout_2 = MW_Param_Step(F550_FaultInjection_DW.obj_j0.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // Gain: '<S30>/Gain' incorporates:
  //   MATLABSystem: '<S30>/Read Parameter1'
  //
  rtb_Gain2 = F550_FaultInjection_P.Gain_Gain_dz * ParamStep;

  // MATLABSystem: '<S30>/Read Parameter'
  if (F550_FaultInjection_DW.obj_bu.SampleTime !=
      F550_FaultInjection_P.ReadParameter_SampleTime) {
    F550_FaultInjection_DW.obj_bu.SampleTime =
      F550_FaultInjection_P.ReadParameter_SampleTime;
  }

  b_varargout_2 = MW_Param_Step(F550_FaultInjection_DW.obj_bu.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep_0);
  if (b_varargout_2) {
    ParamStep_0 = 0.0F;
  }

  // Product: '<S245>/PProd Out' incorporates:
  //   MATLABSystem: '<S30>/Read Parameter'
  //   Sum: '<S30>/Sum1'
  //
  rtb_Switch2_idx_0 = (F550_FaultInjection_B.Merge[0] -
                       F550_FaultInjection_B.DataTypeConversion1[0]) *
    ParamStep_0;
  rtb_Switch2_idx_1 = (F550_FaultInjection_B.Merge[1] -
                       F550_FaultInjection_B.DataTypeConversion1[1]) *
    ParamStep_0;

  // MATLABSystem: '<S30>/Read Parameter2'
  if (F550_FaultInjection_DW.obj_pc.SampleTime !=
      F550_FaultInjection_P.ReadParameter2_SampleTime_m) {
    F550_FaultInjection_DW.obj_pc.SampleTime =
      F550_FaultInjection_P.ReadParameter2_SampleTime_m;
  }

  b_varargout_2 = MW_Param_Step(F550_FaultInjection_DW.obj_pc.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep_0);
  if (b_varargout_2) {
    ParamStep_0 = 0.0F;
  }

  // Switch: '<S248>/Switch2' incorporates:
  //   MATLABSystem: '<S30>/Read Parameter1'
  //   RelationalOperator: '<S248>/LowerRelop1'
  //   RelationalOperator: '<S248>/UpperRelop'
  //   Switch: '<S248>/Switch'
  //
  if (rtb_Switch2_idx_0 > ParamStep) {
    rtb_Switch2_idx_0 = ParamStep;
  } else if (rtb_Switch2_idx_0 < rtb_Gain2) {
    // Switch: '<S248>/Switch'
    rtb_Switch2_idx_0 = rtb_Gain2;
  }

  // Sum: '<S30>/Sum' incorporates:
  //   RelationalOperator: '<S248>/LowerRelop1'
  //   Switch: '<S248>/Switch2'

  rtb_Switch2_idx_0_0 = rtb_Switch2_idx_0 -
    F550_FaultInjection_B.DataTypeConversion1[3];

  // Switch: '<S248>/Switch2' incorporates:
  //   MATLABSystem: '<S30>/Read Parameter1'
  //   RelationalOperator: '<S248>/LowerRelop1'
  //   RelationalOperator: '<S248>/UpperRelop'
  //   Switch: '<S248>/Switch'
  //
  if (rtb_Switch2_idx_1 > ParamStep) {
    rtb_Switch2_idx_1 = ParamStep;
  } else if (rtb_Switch2_idx_1 < rtb_Gain2) {
    // Switch: '<S248>/Switch'
    rtb_Switch2_idx_1 = rtb_Gain2;
  }

  // Sum: '<S30>/Sum' incorporates:
  //   RelationalOperator: '<S248>/LowerRelop1'
  //   Switch: '<S248>/Switch2'

  rtb_Switch2_idx_1 -= F550_FaultInjection_B.DataTypeConversion1[4];

  // Gain: '<S30>/Gain2'
  rtb_Gain2 = F550_FaultInjection_P.Gain2_Gain_a * rtb_Gain1_e1;

  // Product: '<S196>/PProd Out' incorporates:
  //   MATLABSystem: '<S30>/Read Parameter2'
  //   Product: '<S30>/MatrixMultiply'
  //   Reshape: '<S150>/Reshape'
  //   Reshape: '<S150>/Reshape1'
  //
  rtb_Switch2_0 = (F550_FaultInjection_B.Sum * rtb_Switch2_idx_0_0 +
                   F550_FaultInjection_B.IProdOut * rtb_Switch2_idx_1) *
    ParamStep_0;

  // Switch: '<S199>/Switch2' incorporates:
  //   RelationalOperator: '<S199>/LowerRelop1'
  //   RelationalOperator: '<S199>/UpperRelop'
  //   Switch: '<S199>/Switch'

  if (rtb_Switch2_0 > rtb_Gain1_e1) {
    rtb_Switch2_0 = rtb_Gain1_e1;
  } else if (rtb_Switch2_0 < rtb_Gain2) {
    // Switch: '<S199>/Switch'
    rtb_Switch2_0 = rtb_Gain2;
  }

  rtb_Switch2_idx_0 = rtb_Switch2_0;

  // Product: '<S196>/PProd Out' incorporates:
  //   Gain: '<S150>/Gain'
  //   MATLABSystem: '<S30>/Read Parameter2'
  //   Product: '<S30>/MatrixMultiply'
  //   Reshape: '<S150>/Reshape1'
  //
  rtb_Switch2_0 = (F550_FaultInjection_P.Gain_Gain_j *
                   F550_FaultInjection_B.IProdOut * rtb_Switch2_idx_0_0 +
                   F550_FaultInjection_B.Sum * rtb_Switch2_idx_1) * ParamStep_0;

  // Switch: '<S199>/Switch2' incorporates:
  //   RelationalOperator: '<S199>/LowerRelop1'
  //   RelationalOperator: '<S199>/UpperRelop'
  //   Switch: '<S199>/Switch'

  if (rtb_Switch2_0 > rtb_Gain1_e1) {
    rtb_Switch2_0 = rtb_Gain1_e1;
  } else if (rtb_Switch2_0 < rtb_Gain2) {
    // Switch: '<S199>/Switch'
    rtb_Switch2_0 = rtb_Gain2;
  }

  // Gain: '<S30>/Gain1' incorporates:
  //   Merge: '<S2>/Merge'

  F550_FaultInjection_B.Merge_n[2] = F550_FaultInjection_P.Gain1_Gain_m *
    rtb_Switch2_idx_0;

  // MATLABSystem: '<S30>/Read Parameter4'
  if (F550_FaultInjection_DW.obj_ds.SampleTime !=
      F550_FaultInjection_P.ReadParameter4_SampleTime_b) {
    F550_FaultInjection_DW.obj_ds.SampleTime =
      F550_FaultInjection_P.ReadParameter4_SampleTime_b;
  }

  b_varargout_2 = MW_Param_Step(F550_FaultInjection_DW.obj_ds.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // Product: '<S294>/PProd Out' incorporates:
  //   MATLABSystem: '<S30>/Read Parameter4'
  //
  F550_FaultInjection_B.Sum = rtb_Sum5 * ParamStep;

  // Switch: '<S297>/Switch2' incorporates:
  //   RelationalOperator: '<S297>/LowerRelop1'
  //   RelationalOperator: '<S297>/UpperRelop'
  //   Switch: '<S297>/Switch'
  //   UnaryMinus: '<S30>/Unary Minus2'

  if (F550_FaultInjection_B.Sum > rtb_Gain1_hf) {
    // Merge: '<S2>/Merge' incorporates:
    //   SignalConversion generated from: '<S30>/Yawrate_sp'

    F550_FaultInjection_B.Merge_n[3] = rtb_Gain1_hf;
  } else if (F550_FaultInjection_B.Sum < -rtb_Gain1_hf) {
    // Switch: '<S297>/Switch' incorporates:
    //   Merge: '<S2>/Merge'
    //   SignalConversion generated from: '<S30>/Yawrate_sp'
    //   UnaryMinus: '<S30>/Unary Minus2'

    F550_FaultInjection_B.Merge_n[3] = -rtb_Gain1_hf;
  } else {
    // Merge: '<S2>/Merge' incorporates:
    //   SignalConversion generated from: '<S30>/Yawrate_sp'
    //   Switch: '<S297>/Switch'

    F550_FaultInjection_B.Merge_n[3] = F550_FaultInjection_B.Sum;
  }

  // End of Switch: '<S297>/Switch2'

  // SignalConversion generated from: '<S30>/des_roll' incorporates:
  //   Merge: '<S2>/Merge'
  //   Switch: '<S199>/Switch2'

  F550_FaultInjection_B.Merge_n[1] = rtb_Switch2_0;

  // MATLABSystem: '<S30>/Read Parameter12'
  if (F550_FaultInjection_DW.obj_mn.SampleTime !=
      F550_FaultInjection_P.ReadParameter12_SampleTime) {
    F550_FaultInjection_DW.obj_mn.SampleTime =
      F550_FaultInjection_P.ReadParameter12_SampleTime;
  }

  b_varargout_2 = MW_Param_Step(F550_FaultInjection_DW.obj_mn.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // Switch: '<S159>/Switch' incorporates:
  //   Constant: '<S149>/Constant'
  //   RelationalOperator: '<S159>/UpperRelop'
  //   Switch: '<S159>/Switch2'

  if (F550_FaultInjection_B.Gain1 < F550_FaultInjection_P.Constant_Value_gl) {
    F550_FaultInjection_B.Gain1 = F550_FaultInjection_P.Constant_Value_gl;
  }

  // Product: '<S343>/PProd Out' incorporates:
  //   Gain: '<S30>/Gain3'
  //   MATLABSystem: '<S30>/Read Parameter12'
  //   Sum: '<S30>/Sum2'
  //   Switch: '<S159>/Switch'
  //   Switch: '<S159>/Switch2'
  //
  F550_FaultInjection_B.Sum = (F550_FaultInjection_P.Gain3_Gain_k *
    F550_FaultInjection_B.Merge[2] - F550_FaultInjection_B.Gain1) * ParamStep;

  // MATLABSystem: '<S30>/Read Parameter8'
  if (F550_FaultInjection_DW.obj_l0.SampleTime !=
      F550_FaultInjection_P.ReadParameter8_SampleTime) {
    F550_FaultInjection_DW.obj_l0.SampleTime =
      F550_FaultInjection_P.ReadParameter8_SampleTime;
  }

  b_varargout_2 = MW_Param_Step(F550_FaultInjection_DW.obj_l0.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // MATLABSystem: '<S30>/Read Parameter7'
  if (F550_FaultInjection_DW.obj_d3.SampleTime !=
      F550_FaultInjection_P.ReadParameter7_SampleTime) {
    F550_FaultInjection_DW.obj_d3.SampleTime =
      F550_FaultInjection_P.ReadParameter7_SampleTime;
  }

  b_varargout_2 = MW_Param_Step(F550_FaultInjection_DW.obj_d3.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep_0);
  if (b_varargout_2) {
    ParamStep_0 = 0.0F;
  }

  // Switch: '<S346>/Switch2' incorporates:
  //   MATLABSystem: '<S30>/Read Parameter7'
  //   MATLABSystem: '<S30>/Read Parameter8'
  //   RelationalOperator: '<S346>/LowerRelop1'
  //   RelationalOperator: '<S346>/UpperRelop'
  //   Switch: '<S346>/Switch'
  //   UnaryMinus: '<S30>/Unary Minus1'
  //
  if (F550_FaultInjection_B.Sum > ParamStep) {
    F550_FaultInjection_B.Sum = ParamStep;
  } else if (F550_FaultInjection_B.Sum < -ParamStep_0) {
    // Switch: '<S346>/Switch' incorporates:
    //   MATLABSystem: '<S30>/Read Parameter7'
    //   UnaryMinus: '<S30>/Unary Minus1'
    //
    F550_FaultInjection_B.Sum = -ParamStep_0;
  }

  // Sum: '<S30>/Sum3' incorporates:
  //   Switch: '<S346>/Switch2'
  //   UnaryMinus: '<S30>/Unary Minus'

  rtb_Sum5 = F550_FaultInjection_B.Sum -
    (-F550_FaultInjection_B.DataTypeConversion1[5]);

  // MATLABSystem: '<S30>/Read Parameter13'
  if (F550_FaultInjection_DW.obj_km.SampleTime !=
      F550_FaultInjection_P.ReadParameter13_SampleTime_c) {
    F550_FaultInjection_DW.obj_km.SampleTime =
      F550_FaultInjection_P.ReadParameter13_SampleTime_c;
  }

  b_varargout_2 = MW_Param_Step(F550_FaultInjection_DW.obj_km.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // Product: '<S394>/PProd Out' incorporates:
  //   MATLABSystem: '<S30>/Read Parameter13'
  //
  F550_FaultInjection_B.Sum = rtb_Sum5 * ParamStep;

  // MATLABSystem: '<S30>/Read Parameter15'
  if (F550_FaultInjection_DW.obj_ba.SampleTime !=
      F550_FaultInjection_P.ReadParameter15_SampleTime) {
    F550_FaultInjection_DW.obj_ba.SampleTime =
      F550_FaultInjection_P.ReadParameter15_SampleTime;
  }

  b_varargout_2 = MW_Param_Step(F550_FaultInjection_DW.obj_ba.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // Product: '<S392>/NProd Out' incorporates:
  //   Constant: '<S30>/Constant'
  //   DiscreteIntegrator: '<S384>/Filter'
  //   MATLABSystem: '<S30>/Read Parameter15'
  //   Product: '<S383>/DProd Out'
  //   Sum: '<S384>/SumD'
  //
  F550_FaultInjection_B.Gain1 = (rtb_Sum5 * ParamStep -
    F550_FaultInjection_DW.Filter_DSTATE_k) *
    F550_FaultInjection_P.Constant_Value_gk;

  // Sum: '<S399>/Sum Fdbk'
  F550_FaultInjection_B.IProdOut = (F550_FaultInjection_B.Sum +
    F550_FaultInjection_DW.Integrator_DSTATE_o) + F550_FaultInjection_B.Gain1;

  // DeadZone: '<S382>/DeadZone'
  if (F550_FaultInjection_B.IProdOut >
      F550_FaultInjection_P.PID_vz_UpperSaturationLimit) {
    F550_FaultInjection_B.IProdOut -=
      F550_FaultInjection_P.PID_vz_UpperSaturationLimit;
  } else if (F550_FaultInjection_B.IProdOut >=
             F550_FaultInjection_P.PID_vz_LowerSaturationLimit) {
    F550_FaultInjection_B.IProdOut = 0.0;
  } else {
    F550_FaultInjection_B.IProdOut -=
      F550_FaultInjection_P.PID_vz_LowerSaturationLimit;
  }

  // End of DeadZone: '<S382>/DeadZone'

  // RelationalOperator: '<S380>/Relational Operator' incorporates:
  //   Constant: '<S380>/Clamping_zero'

  rtb_RelationalOperator = (F550_FaultInjection_P.Clamping_zero_Value !=
    F550_FaultInjection_B.IProdOut);

  // Switch: '<S380>/Switch1' incorporates:
  //   Constant: '<S380>/Clamping_zero'
  //   Constant: '<S380>/Constant'
  //   Constant: '<S380>/Constant2'
  //   RelationalOperator: '<S380>/fix for DT propagation issue'

  if (F550_FaultInjection_B.IProdOut > F550_FaultInjection_P.Clamping_zero_Value)
  {
    rtb_Switch1_h = F550_FaultInjection_P.Constant_Value_dl;
  } else {
    rtb_Switch1_h = F550_FaultInjection_P.Constant2_Value_c;
  }

  // End of Switch: '<S380>/Switch1'

  // MATLABSystem: '<S30>/Read Parameter14'
  if (F550_FaultInjection_DW.obj_a.SampleTime !=
      F550_FaultInjection_P.ReadParameter14_SampleTime) {
    F550_FaultInjection_DW.obj_a.SampleTime =
      F550_FaultInjection_P.ReadParameter14_SampleTime;
  }

  b_varargout_2 = MW_Param_Step(F550_FaultInjection_DW.obj_a.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // Product: '<S386>/IProd Out' incorporates:
  //   MATLABSystem: '<S30>/Read Parameter14'
  //
  F550_FaultInjection_B.IProdOut = rtb_Sum5 * ParamStep;

  // Switch: '<S380>/Switch2' incorporates:
  //   Constant: '<S380>/Clamping_zero'
  //   Constant: '<S380>/Constant3'
  //   Constant: '<S380>/Constant4'
  //   RelationalOperator: '<S380>/fix for DT propagation issue1'

  if (F550_FaultInjection_B.IProdOut > F550_FaultInjection_P.Clamping_zero_Value)
  {
    tmp = F550_FaultInjection_P.Constant3_Value_k;
  } else {
    tmp = F550_FaultInjection_P.Constant4_Value_b;
  }

  // Switch: '<S380>/Switch' incorporates:
  //   Constant: '<S380>/Constant1'
  //   Logic: '<S380>/AND3'
  //   RelationalOperator: '<S380>/Equal1'
  //   Switch: '<S380>/Switch2'

  if (rtb_RelationalOperator && (rtb_Switch1_h == tmp)) {
    F550_FaultInjection_B.IProdOut = F550_FaultInjection_P.Constant1_Value_f;
  }

  // DiscreteIntegrator: '<S389>/Integrator' incorporates:
  //   Switch: '<S380>/Switch'

  F550_FaultInjection_B.IProdOut = F550_FaultInjection_P.Integrator_gainval *
    F550_FaultInjection_B.IProdOut + F550_FaultInjection_DW.Integrator_DSTATE_o;

  // Sum: '<S398>/Sum'
  F550_FaultInjection_B.Sum = (F550_FaultInjection_B.Sum +
    F550_FaultInjection_B.IProdOut) + F550_FaultInjection_B.Gain1;

  // Saturate: '<S396>/Saturation' incorporates:
  //   Merge: '<S2>/Merge'

  if (F550_FaultInjection_B.Sum >
      F550_FaultInjection_P.PID_vz_UpperSaturationLimit) {
    F550_FaultInjection_B.Merge_n[0] =
      F550_FaultInjection_P.PID_vz_UpperSaturationLimit;
  } else if (F550_FaultInjection_B.Sum <
             F550_FaultInjection_P.PID_vz_LowerSaturationLimit) {
    F550_FaultInjection_B.Merge_n[0] =
      F550_FaultInjection_P.PID_vz_LowerSaturationLimit;
  } else {
    F550_FaultInjection_B.Merge_n[0] = F550_FaultInjection_B.Sum;
  }

  // End of Saturate: '<S396>/Saturation'

  // Update for DiscreteIntegrator: '<S384>/Filter'
  F550_FaultInjection_DW.Filter_DSTATE_k += F550_FaultInjection_P.Filter_gainval
    * F550_FaultInjection_B.Gain1;

  // Update for DiscreteIntegrator: '<S389>/Integrator'
  F550_FaultInjection_DW.Integrator_DSTATE_o = F550_FaultInjection_B.IProdOut;
}

// Termination for action system: '<S2>/mc_pos_controller'
void F550_FaultInjection_mc_pos_controller_Term(void)
{
  // Terminate for MATLABSystem: '<S30>/Read Parameter3'
  if (!F550_FaultInjection_DW.obj_f.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter3'

  // Terminate for MATLABSystem: '<S30>/Read Parameter11'
  if (!F550_FaultInjection_DW.obj_kf.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_kf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter11'

  // Terminate for MATLABSystem: '<S30>/Read Parameter1'
  if (!F550_FaultInjection_DW.obj_j0.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_j0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter1'

  // Terminate for MATLABSystem: '<S30>/Read Parameter'
  if (!F550_FaultInjection_DW.obj_bu.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_bu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter'

  // Terminate for MATLABSystem: '<S30>/Read Parameter2'
  if (!F550_FaultInjection_DW.obj_pc.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_pc.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter2'

  // Terminate for MATLABSystem: '<S30>/Read Parameter4'
  if (!F550_FaultInjection_DW.obj_ds.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_ds.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter4'

  // Terminate for MATLABSystem: '<S30>/Read Parameter12'
  if (!F550_FaultInjection_DW.obj_mn.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_mn.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter12'

  // Terminate for MATLABSystem: '<S30>/Read Parameter8'
  if (!F550_FaultInjection_DW.obj_l0.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_l0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter8'

  // Terminate for MATLABSystem: '<S30>/Read Parameter7'
  if (!F550_FaultInjection_DW.obj_d3.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_d3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter7'

  // Terminate for MATLABSystem: '<S30>/Read Parameter13'
  if (!F550_FaultInjection_DW.obj_km.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_km.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter13'

  // Terminate for MATLABSystem: '<S30>/Read Parameter15'
  if (!F550_FaultInjection_DW.obj_ba.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_ba.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter15'

  // Terminate for MATLABSystem: '<S30>/Read Parameter14'
  if (!F550_FaultInjection_DW.obj_a.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter14'
}

//
// File trailer for generated code.
//
// [EOF]
//
