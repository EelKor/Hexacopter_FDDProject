//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mc_pos_controller.cpp
//
// Code generated for Simulink model 'HITL_HEXA_MISSION'.
//
// Model version                  : 5.5
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Oct 16 17:31:56 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "mc_pos_controller.h"
#include "HITL_HEXA_MISSION.h"
#include "rtwtypes.h"
#include <math.h>
#include "HITL_HEXA_MISSION_private.h"

// System initialize for enable system: '<S23>/mc_pos_controller'
void HITL_HEXA_MISSION_mc_pos_controller_Init(void)
{
  static const char_T ParameterNameStr[7] = "SL_Z_P";
  static const char_T ParameterNameStr_0[16] = "SL_Z_VEL_MAX_UP";
  static const char_T ParameterNameStr_1[16] = "SL_Z_VEL_MAX_DN";
  static const char_T ParameterNameStr_2[15] = "SL_Z_VEL_P_ACC";
  static const char_T ParameterNameStr_3[15] = "SL_Z_VEL_D_ACC";
  static const char_T ParameterNameStr_4[15] = "SL_Z_VEL_I_ACC";
  static const char_T ParameterNameStr_5[15] = "SL_XY_TILT_MAX";
  static const char_T ParameterNameStr_6[14] = "SL_XY_VEL_MAX";
  static const char_T ParameterNameStr_7[8] = "SL_XY_P";
  static const char_T ParameterNameStr_8[16] = "SL_XY_VEL_P_ACC";
  real_T tmp;

  // InitializeConditions for DiscreteIntegrator: '<S395>/Filter'
  HITL_HEXA_MISSION_DW.Filter_DSTATE_m =
    HITL_HEXA_MISSION_P.PID_vz_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S400>/Integrator'
  HITL_HEXA_MISSION_DW.Integrator_DSTATE_c =
    HITL_HEXA_MISSION_P.PID_vz_InitialConditionForIntegrator;

  // Start for MATLABSystem: '<S29>/Read Parameter12'
  HITL_HEXA_MISSION_DW.obj_do.matlabCodegenIsDeleted = false;
  HITL_HEXA_MISSION_DW.obj_do.SampleTime =
    HITL_HEXA_MISSION_P.ReadParameter12_SampleTime;
  HITL_HEXA_MISSION_DW.obj_do.isInitialized = 1;
  if (HITL_HEXA_MISSION_DW.obj_do.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_MISSION_DW.obj_do.SampleTime;
  }

  HITL_HEXA_MISSION_DW.obj_do.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0],
    true, tmp * 1000.0);
  HITL_HEXA_MISSION_DW.obj_do.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S29>/Read Parameter12'

  // Start for MATLABSystem: '<S29>/Read Parameter8'
  HITL_HEXA_MISSION_DW.obj_gf.matlabCodegenIsDeleted = false;
  HITL_HEXA_MISSION_DW.obj_gf.SampleTime =
    HITL_HEXA_MISSION_P.ReadParameter8_SampleTime;
  HITL_HEXA_MISSION_DW.obj_gf.isInitialized = 1;
  if (HITL_HEXA_MISSION_DW.obj_gf.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_MISSION_DW.obj_gf.SampleTime;
  }

  HITL_HEXA_MISSION_DW.obj_gf.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_0[0], true, tmp * 1000.0);
  HITL_HEXA_MISSION_DW.obj_gf.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S29>/Read Parameter8'

  // Start for MATLABSystem: '<S29>/Read Parameter7'
  HITL_HEXA_MISSION_DW.obj_m.matlabCodegenIsDeleted = false;
  HITL_HEXA_MISSION_DW.obj_m.SampleTime =
    HITL_HEXA_MISSION_P.ReadParameter7_SampleTime;
  HITL_HEXA_MISSION_DW.obj_m.isInitialized = 1;
  if (HITL_HEXA_MISSION_DW.obj_m.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_MISSION_DW.obj_m.SampleTime;
  }

  HITL_HEXA_MISSION_DW.obj_m.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1
    [0], true, tmp * 1000.0);
  HITL_HEXA_MISSION_DW.obj_m.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S29>/Read Parameter7'

  // Start for MATLABSystem: '<S29>/Read Parameter13'
  HITL_HEXA_MISSION_DW.obj_n3.matlabCodegenIsDeleted = false;
  HITL_HEXA_MISSION_DW.obj_n3.SampleTime =
    HITL_HEXA_MISSION_P.ReadParameter13_SampleTime_o;
  HITL_HEXA_MISSION_DW.obj_n3.isInitialized = 1;
  if (HITL_HEXA_MISSION_DW.obj_n3.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_MISSION_DW.obj_n3.SampleTime;
  }

  HITL_HEXA_MISSION_DW.obj_n3.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_2[0], true, tmp * 1000.0);
  HITL_HEXA_MISSION_DW.obj_n3.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S29>/Read Parameter13'

  // Start for MATLABSystem: '<S29>/Read Parameter15'
  HITL_HEXA_MISSION_DW.obj_c.matlabCodegenIsDeleted = false;
  HITL_HEXA_MISSION_DW.obj_c.SampleTime =
    HITL_HEXA_MISSION_P.ReadParameter15_SampleTime;
  HITL_HEXA_MISSION_DW.obj_c.isInitialized = 1;
  if (HITL_HEXA_MISSION_DW.obj_c.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_MISSION_DW.obj_c.SampleTime;
  }

  HITL_HEXA_MISSION_DW.obj_c.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3
    [0], true, tmp * 1000.0);
  HITL_HEXA_MISSION_DW.obj_c.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S29>/Read Parameter15'

  // Start for MATLABSystem: '<S29>/Read Parameter14'
  HITL_HEXA_MISSION_DW.obj_p.matlabCodegenIsDeleted = false;
  HITL_HEXA_MISSION_DW.obj_p.SampleTime =
    HITL_HEXA_MISSION_P.ReadParameter14_SampleTime;
  HITL_HEXA_MISSION_DW.obj_p.isInitialized = 1;
  if (HITL_HEXA_MISSION_DW.obj_p.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_MISSION_DW.obj_p.SampleTime;
  }

  HITL_HEXA_MISSION_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_4
    [0], true, tmp * 1000.0);
  HITL_HEXA_MISSION_DW.obj_p.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S29>/Read Parameter14'

  // Start for MATLABSystem: '<S29>/Read Parameter3'
  HITL_HEXA_MISSION_DW.obj_i.matlabCodegenIsDeleted = false;
  HITL_HEXA_MISSION_DW.obj_i.SampleTime =
    HITL_HEXA_MISSION_P.ReadParameter3_SampleTime_j;
  HITL_HEXA_MISSION_DW.obj_i.isInitialized = 1;
  if (HITL_HEXA_MISSION_DW.obj_i.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_MISSION_DW.obj_i.SampleTime;
  }

  HITL_HEXA_MISSION_DW.obj_i.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_5
    [0], true, tmp * 1000.0);
  HITL_HEXA_MISSION_DW.obj_i.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S29>/Read Parameter3'

  // Start for MATLABSystem: '<S29>/Read Parameter1'
  HITL_HEXA_MISSION_DW.obj_mt.matlabCodegenIsDeleted = false;
  HITL_HEXA_MISSION_DW.obj_mt.SampleTime =
    HITL_HEXA_MISSION_P.ReadParameter1_SampleTime_m;
  HITL_HEXA_MISSION_DW.obj_mt.isInitialized = 1;
  if (HITL_HEXA_MISSION_DW.obj_mt.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_MISSION_DW.obj_mt.SampleTime;
  }

  HITL_HEXA_MISSION_DW.obj_mt.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_6[0], true, tmp * 1000.0);
  HITL_HEXA_MISSION_DW.obj_mt.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S29>/Read Parameter1'

  // Start for MATLABSystem: '<S29>/Read Parameter'
  HITL_HEXA_MISSION_DW.obj_o.matlabCodegenIsDeleted = false;
  HITL_HEXA_MISSION_DW.obj_o.SampleTime =
    HITL_HEXA_MISSION_P.ReadParameter_SampleTime;
  HITL_HEXA_MISSION_DW.obj_o.isInitialized = 1;
  if (HITL_HEXA_MISSION_DW.obj_o.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_MISSION_DW.obj_o.SampleTime;
  }

  HITL_HEXA_MISSION_DW.obj_o.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_7
    [0], true, tmp * 1000.0);
  HITL_HEXA_MISSION_DW.obj_o.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S29>/Read Parameter'

  // Start for MATLABSystem: '<S29>/Read Parameter2'
  HITL_HEXA_MISSION_DW.obj_kf.matlabCodegenIsDeleted = false;
  HITL_HEXA_MISSION_DW.obj_kf.SampleTime =
    HITL_HEXA_MISSION_P.ReadParameter2_SampleTime_p;
  HITL_HEXA_MISSION_DW.obj_kf.isInitialized = 1;
  if (HITL_HEXA_MISSION_DW.obj_kf.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_MISSION_DW.obj_kf.SampleTime;
  }

  HITL_HEXA_MISSION_DW.obj_kf.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_8[0], true, tmp * 1000.0);
  HITL_HEXA_MISSION_DW.obj_kf.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S29>/Read Parameter2'

  // SystemInitialize for Saturate: '<S407>/Saturation' incorporates:
  //   Outport: '<S29>/tau_Thrust'

  HITL_HEXA_MISSION_B.Saturation_d = HITL_HEXA_MISSION_P.tau_Thrust_Y0;

  // SystemInitialize for Outport: '<S29>/des_pitch' incorporates:
  //   Gain: '<S29>/Gain1'

  HITL_HEXA_MISSION_B.Gain1 = HITL_HEXA_MISSION_P.des_pitch_Y0;

  // SystemInitialize for Outport: '<S29>/des_roll'
  HITL_HEXA_MISSION_B.Switch2[1] = HITL_HEXA_MISSION_P.des_roll_Y0;
}

// Output and update for enable system: '<S23>/mc_pos_controller'
void HITL_HEXA_MISSION_mc_pos_controller(void)
{
  real32_T ParamStep;

  // Outputs for Enabled SubSystem: '<S23>/mc_pos_controller' incorporates:
  //   EnablePort: '<S29>/Enable'

  if (HITL_HEXA_MISSION_B.In1_b.armed) {
    real_T Integrator;
    real_T rtb_MatrixMultiply_idx_1;
    real_T rtb_NProdOut;
    real_T rtb_SinCos_o1;
    real_T rtb_Switch_g_0;
    real32_T rtb_Gain1_k;
    real32_T rtb_Gain1_m;
    real32_T rtb_Gain2;
    int8_T rtb_Switch1_m;
    int8_T tmp;
    boolean_T b_varargout_2;
    boolean_T rtb_RelationalOperator;

    // Gain: '<S204>/Gain1'
    rtb_Gain1_m = HITL_HEXA_MISSION_P.Gain1_Gain_o1 *
      HITL_HEXA_MISSION_B.In1_c.z;

    // MATLABSystem: '<S29>/Read Parameter12'
    if (HITL_HEXA_MISSION_DW.obj_do.SampleTime !=
        HITL_HEXA_MISSION_P.ReadParameter12_SampleTime) {
      HITL_HEXA_MISSION_DW.obj_do.SampleTime =
        HITL_HEXA_MISSION_P.ReadParameter12_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_MISSION_DW.obj_do.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Switch: '<S211>/Switch' incorporates:
    //   Constant: '<S204>/Constant'
    //   RelationalOperator: '<S211>/UpperRelop'
    //   Switch: '<S211>/Switch2'

    if (rtb_Gain1_m < HITL_HEXA_MISSION_P.Constant_Value_j4) {
      rtb_Gain1_m = static_cast<real32_T>(HITL_HEXA_MISSION_P.Constant_Value_j4);
    }

    // Product: '<S352>/PProd Out' incorporates:
    //   MATLABSystem: '<S29>/Read Parameter12'
    //   Sum: '<S29>/Sum2'
    //   Switch: '<S211>/Switch'
    //   Switch: '<S211>/Switch2'
    //
    HITL_HEXA_MISSION_B.PProdOut_pm = (HITL_HEXA_MISSION_B.desiredZ -
      rtb_Gain1_m) * ParamStep;

    // MATLABSystem: '<S29>/Read Parameter8'
    if (HITL_HEXA_MISSION_DW.obj_gf.SampleTime !=
        HITL_HEXA_MISSION_P.ReadParameter8_SampleTime) {
      HITL_HEXA_MISSION_DW.obj_gf.SampleTime =
        HITL_HEXA_MISSION_P.ReadParameter8_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_MISSION_DW.obj_gf.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // MATLABSystem: '<S29>/Read Parameter7'
    if (HITL_HEXA_MISSION_DW.obj_m.SampleTime !=
        HITL_HEXA_MISSION_P.ReadParameter7_SampleTime) {
      HITL_HEXA_MISSION_DW.obj_m.SampleTime =
        HITL_HEXA_MISSION_P.ReadParameter7_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_MISSION_DW.obj_m.MW_PARAMHANDLE,
      MW_SINGLE, &rtb_Gain1_m);
    if (b_varargout_2) {
      rtb_Gain1_m = 0.0F;
    }

    // Switch: '<S355>/Switch2' incorporates:
    //   MATLABSystem: '<S29>/Read Parameter7'
    //   MATLABSystem: '<S29>/Read Parameter8'
    //   RelationalOperator: '<S355>/LowerRelop1'
    //   RelationalOperator: '<S355>/UpperRelop'
    //   Switch: '<S355>/Switch'
    //   UnaryMinus: '<S29>/Unary Minus1'
    //
    if (HITL_HEXA_MISSION_B.PProdOut_pm > ParamStep) {
      HITL_HEXA_MISSION_B.PProdOut_pm = ParamStep;
    } else if (HITL_HEXA_MISSION_B.PProdOut_pm < -rtb_Gain1_m) {
      // Switch: '<S355>/Switch' incorporates:
      //   MATLABSystem: '<S29>/Read Parameter7'
      //   UnaryMinus: '<S29>/Unary Minus1'
      //
      HITL_HEXA_MISSION_B.PProdOut_pm = -rtb_Gain1_m;
    }

    // End of Switch: '<S355>/Switch2'

    // Sum: '<S29>/Sum3' incorporates:
    //   UnaryMinus: '<S29>/Unary Minus'

    HITL_HEXA_MISSION_B.SinCos_o2 = HITL_HEXA_MISSION_B.PProdOut_pm -
      (-HITL_HEXA_MISSION_B.In1_c.vz);

    // MATLABSystem: '<S29>/Read Parameter13'
    if (HITL_HEXA_MISSION_DW.obj_n3.SampleTime !=
        HITL_HEXA_MISSION_P.ReadParameter13_SampleTime_o) {
      HITL_HEXA_MISSION_DW.obj_n3.SampleTime =
        HITL_HEXA_MISSION_P.ReadParameter13_SampleTime_o;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_MISSION_DW.obj_n3.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S405>/PProd Out' incorporates:
    //   MATLABSystem: '<S29>/Read Parameter13'
    //
    HITL_HEXA_MISSION_B.PProdOut_pm = HITL_HEXA_MISSION_B.SinCos_o2 * ParamStep;

    // MATLABSystem: '<S29>/Read Parameter15'
    if (HITL_HEXA_MISSION_DW.obj_c.SampleTime !=
        HITL_HEXA_MISSION_P.ReadParameter15_SampleTime) {
      HITL_HEXA_MISSION_DW.obj_c.SampleTime =
        HITL_HEXA_MISSION_P.ReadParameter15_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_MISSION_DW.obj_c.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S403>/NProd Out' incorporates:
    //   Constant: '<S29>/Constant'
    //   DiscreteIntegrator: '<S395>/Filter'
    //   MATLABSystem: '<S29>/Read Parameter15'
    //   Product: '<S393>/DProd Out'
    //   Sum: '<S395>/SumD'
    //
    rtb_NProdOut = (HITL_HEXA_MISSION_B.SinCos_o2 * ParamStep -
                    HITL_HEXA_MISSION_DW.Filter_DSTATE_m) *
      HITL_HEXA_MISSION_P.Constant_Value_p3;

    // Sum: '<S410>/Sum Fdbk'
    rtb_SinCos_o1 = (HITL_HEXA_MISSION_B.PProdOut_pm +
                     HITL_HEXA_MISSION_DW.Integrator_DSTATE_c) + rtb_NProdOut;

    // DeadZone: '<S392>/DeadZone'
    if (rtb_SinCos_o1 > HITL_HEXA_MISSION_P.PID_vz_UpperSaturationLimit) {
      rtb_SinCos_o1 -= HITL_HEXA_MISSION_P.PID_vz_UpperSaturationLimit;
    } else if (rtb_SinCos_o1 >= HITL_HEXA_MISSION_P.PID_vz_LowerSaturationLimit)
    {
      rtb_SinCos_o1 = 0.0;
    } else {
      rtb_SinCos_o1 -= HITL_HEXA_MISSION_P.PID_vz_LowerSaturationLimit;
    }

    // End of DeadZone: '<S392>/DeadZone'

    // RelationalOperator: '<S390>/Relational Operator' incorporates:
    //   Constant: '<S390>/Clamping_zero'

    rtb_RelationalOperator = (HITL_HEXA_MISSION_P.Clamping_zero_Value !=
      rtb_SinCos_o1);

    // Switch: '<S390>/Switch1' incorporates:
    //   Constant: '<S390>/Clamping_zero'
    //   Constant: '<S390>/Constant'
    //   Constant: '<S390>/Constant2'
    //   RelationalOperator: '<S390>/fix for DT propagation issue'

    if (rtb_SinCos_o1 > HITL_HEXA_MISSION_P.Clamping_zero_Value) {
      rtb_Switch1_m = HITL_HEXA_MISSION_P.Constant_Value_mp;
    } else {
      rtb_Switch1_m = HITL_HEXA_MISSION_P.Constant2_Value_k;
    }

    // End of Switch: '<S390>/Switch1'

    // MATLABSystem: '<S29>/Read Parameter14'
    if (HITL_HEXA_MISSION_DW.obj_p.SampleTime !=
        HITL_HEXA_MISSION_P.ReadParameter14_SampleTime) {
      HITL_HEXA_MISSION_DW.obj_p.SampleTime =
        HITL_HEXA_MISSION_P.ReadParameter14_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_MISSION_DW.obj_p.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S397>/IProd Out' incorporates:
    //   MATLABSystem: '<S29>/Read Parameter14'
    //
    rtb_SinCos_o1 = HITL_HEXA_MISSION_B.SinCos_o2 * ParamStep;

    // Switch: '<S390>/Switch2' incorporates:
    //   Constant: '<S390>/Clamping_zero'
    //   Constant: '<S390>/Constant3'
    //   Constant: '<S390>/Constant4'
    //   RelationalOperator: '<S390>/fix for DT propagation issue1'

    if (rtb_SinCos_o1 > HITL_HEXA_MISSION_P.Clamping_zero_Value) {
      tmp = HITL_HEXA_MISSION_P.Constant3_Value_i;
    } else {
      tmp = HITL_HEXA_MISSION_P.Constant4_Value_j;
    }

    // Switch: '<S390>/Switch' incorporates:
    //   Constant: '<S390>/Constant1'
    //   Logic: '<S390>/AND3'
    //   RelationalOperator: '<S390>/Equal1'
    //   Switch: '<S390>/Switch2'

    if (rtb_RelationalOperator && (rtb_Switch1_m == tmp)) {
      rtb_SinCos_o1 = HITL_HEXA_MISSION_P.Constant1_Value_o;
    }

    // DiscreteIntegrator: '<S400>/Integrator' incorporates:
    //   Switch: '<S390>/Switch'

    Integrator = HITL_HEXA_MISSION_P.Integrator_gainval * rtb_SinCos_o1 +
      HITL_HEXA_MISSION_DW.Integrator_DSTATE_c;

    // Sum: '<S409>/Sum'
    HITL_HEXA_MISSION_B.SinCos_o2 = (HITL_HEXA_MISSION_B.PProdOut_pm +
      Integrator) + rtb_NProdOut;

    // Saturate: '<S407>/Saturation'
    if (HITL_HEXA_MISSION_B.SinCos_o2 >
        HITL_HEXA_MISSION_P.PID_vz_UpperSaturationLimit) {
      // Saturate: '<S407>/Saturation'
      HITL_HEXA_MISSION_B.Saturation_d =
        HITL_HEXA_MISSION_P.PID_vz_UpperSaturationLimit;
    } else if (HITL_HEXA_MISSION_B.SinCos_o2 <
               HITL_HEXA_MISSION_P.PID_vz_LowerSaturationLimit) {
      // Saturate: '<S407>/Saturation'
      HITL_HEXA_MISSION_B.Saturation_d =
        HITL_HEXA_MISSION_P.PID_vz_LowerSaturationLimit;
    } else {
      // Saturate: '<S407>/Saturation'
      HITL_HEXA_MISSION_B.Saturation_d = HITL_HEXA_MISSION_B.SinCos_o2;
    }

    // End of Saturate: '<S407>/Saturation'

    // Trigonometry: '<S205>/SinCos'
    rtb_SinCos_o1 = sin(HITL_HEXA_MISSION_B.Merge[3]);
    HITL_HEXA_MISSION_B.SinCos_o2 = cos(HITL_HEXA_MISSION_B.Merge[3]);

    // MATLABSystem: '<S29>/Read Parameter3'
    if (HITL_HEXA_MISSION_DW.obj_i.SampleTime !=
        HITL_HEXA_MISSION_P.ReadParameter3_SampleTime_j) {
      HITL_HEXA_MISSION_DW.obj_i.SampleTime =
        HITL_HEXA_MISSION_P.ReadParameter3_SampleTime_j;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_MISSION_DW.obj_i.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Gain: '<S206>/Gain1' incorporates:
    //   MATLABSystem: '<S29>/Read Parameter3'
    //
    rtb_Gain1_k = HITL_HEXA_MISSION_P.Gain1_Gain_p * ParamStep;

    // MATLABSystem: '<S29>/Read Parameter1'
    if (HITL_HEXA_MISSION_DW.obj_mt.SampleTime !=
        HITL_HEXA_MISSION_P.ReadParameter1_SampleTime_m) {
      HITL_HEXA_MISSION_DW.obj_mt.SampleTime =
        HITL_HEXA_MISSION_P.ReadParameter1_SampleTime_m;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_MISSION_DW.obj_mt.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Gain: '<S29>/Gain' incorporates:
    //   MATLABSystem: '<S29>/Read Parameter1'
    //
    rtb_Gain2 = HITL_HEXA_MISSION_P.Gain_Gain_md * ParamStep;

    // MATLABSystem: '<S29>/Read Parameter'
    if (HITL_HEXA_MISSION_DW.obj_o.SampleTime !=
        HITL_HEXA_MISSION_P.ReadParameter_SampleTime) {
      HITL_HEXA_MISSION_DW.obj_o.SampleTime =
        HITL_HEXA_MISSION_P.ReadParameter_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_MISSION_DW.obj_o.MW_PARAMHANDLE,
      MW_SINGLE, &rtb_Gain1_m);
    if (b_varargout_2) {
      rtb_Gain1_m = 0.0F;
    }

    // Product: '<S301>/PProd Out' incorporates:
    //   MATLABSystem: '<S29>/Read Parameter'
    //   Sum: '<S29>/Sum1'
    //
    HITL_HEXA_MISSION_B.PProdOut_pm = (HITL_HEXA_MISSION_B.Merge[0] -
      HITL_HEXA_MISSION_B.In1_c.x) * rtb_Gain1_m;
    rtb_MatrixMultiply_idx_1 = (HITL_HEXA_MISSION_B.Merge[1] -
      HITL_HEXA_MISSION_B.In1_c.y) * rtb_Gain1_m;

    // Switch: '<S304>/Switch2' incorporates:
    //   MATLABSystem: '<S29>/Read Parameter1'
    //   RelationalOperator: '<S304>/LowerRelop1'
    //   RelationalOperator: '<S304>/UpperRelop'
    //   Switch: '<S304>/Switch'
    //
    if (HITL_HEXA_MISSION_B.PProdOut_pm > ParamStep) {
      HITL_HEXA_MISSION_B.PProdOut_pm = ParamStep;
    } else if (HITL_HEXA_MISSION_B.PProdOut_pm < rtb_Gain2) {
      // Switch: '<S304>/Switch'
      HITL_HEXA_MISSION_B.PProdOut_pm = rtb_Gain2;
    }

    if (rtb_MatrixMultiply_idx_1 > ParamStep) {
      rtb_MatrixMultiply_idx_1 = ParamStep;
    } else if (rtb_MatrixMultiply_idx_1 < rtb_Gain2) {
      // Switch: '<S304>/Switch'
      rtb_MatrixMultiply_idx_1 = rtb_Gain2;
    }

    // End of Switch: '<S304>/Switch2'

    // MATLABSystem: '<S29>/Read Parameter2'
    if (HITL_HEXA_MISSION_DW.obj_kf.SampleTime !=
        HITL_HEXA_MISSION_P.ReadParameter2_SampleTime_p) {
      HITL_HEXA_MISSION_DW.obj_kf.SampleTime =
        HITL_HEXA_MISSION_P.ReadParameter2_SampleTime_p;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_MISSION_DW.obj_kf.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Sum: '<S29>/Sum'
    HITL_HEXA_MISSION_B.PProdOut_pm -= HITL_HEXA_MISSION_B.In1_c.vx;
    rtb_MatrixMultiply_idx_1 -= HITL_HEXA_MISSION_B.In1_c.vy;

    // Gain: '<S29>/Gain2'
    rtb_Gain2 = HITL_HEXA_MISSION_P.Gain2_Gain_i * rtb_Gain1_k;

    // Product: '<S250>/PProd Out' incorporates:
    //   MATLABSystem: '<S29>/Read Parameter2'
    //   Product: '<S29>/MatrixMultiply'
    //   Reshape: '<S205>/Reshape'
    //   Reshape: '<S205>/Reshape1'
    //
    rtb_Switch_g_0 = (HITL_HEXA_MISSION_B.SinCos_o2 *
                      HITL_HEXA_MISSION_B.PProdOut_pm + rtb_SinCos_o1 *
                      rtb_MatrixMultiply_idx_1) * ParamStep;

    // Switch: '<S253>/Switch2' incorporates:
    //   RelationalOperator: '<S253>/LowerRelop1'
    //   RelationalOperator: '<S253>/UpperRelop'
    //   Switch: '<S253>/Switch'

    if (rtb_Switch_g_0 > rtb_Gain1_k) {
      HITL_HEXA_MISSION_B.Switch2[0] = rtb_Gain1_k;
    } else if (rtb_Switch_g_0 < rtb_Gain2) {
      // Switch: '<S253>/Switch'
      HITL_HEXA_MISSION_B.Switch2[0] = rtb_Gain2;
    } else {
      HITL_HEXA_MISSION_B.Switch2[0] = rtb_Switch_g_0;
    }

    // Product: '<S250>/PProd Out' incorporates:
    //   Gain: '<S205>/Gain'
    //   MATLABSystem: '<S29>/Read Parameter2'
    //   Product: '<S29>/MatrixMultiply'
    //   Reshape: '<S205>/Reshape1'
    //
    rtb_Switch_g_0 = (HITL_HEXA_MISSION_P.Gain_Gain_l2 * rtb_SinCos_o1 *
                      HITL_HEXA_MISSION_B.PProdOut_pm +
                      HITL_HEXA_MISSION_B.SinCos_o2 * rtb_MatrixMultiply_idx_1) *
      ParamStep;

    // Switch: '<S253>/Switch2' incorporates:
    //   RelationalOperator: '<S253>/LowerRelop1'
    //   RelationalOperator: '<S253>/UpperRelop'
    //   Switch: '<S253>/Switch'

    if (rtb_Switch_g_0 > rtb_Gain1_k) {
      HITL_HEXA_MISSION_B.Switch2[1] = rtb_Gain1_k;
    } else if (rtb_Switch_g_0 < rtb_Gain2) {
      // Switch: '<S253>/Switch'
      HITL_HEXA_MISSION_B.Switch2[1] = rtb_Gain2;
    } else {
      HITL_HEXA_MISSION_B.Switch2[1] = rtb_Switch_g_0;
    }

    // Gain: '<S29>/Gain1'
    HITL_HEXA_MISSION_B.Gain1 = HITL_HEXA_MISSION_P.Gain1_Gain *
      HITL_HEXA_MISSION_B.Switch2[0];

    // Update for DiscreteIntegrator: '<S395>/Filter'
    HITL_HEXA_MISSION_DW.Filter_DSTATE_m += HITL_HEXA_MISSION_P.Filter_gainval *
      rtb_NProdOut;

    // Update for DiscreteIntegrator: '<S400>/Integrator'
    HITL_HEXA_MISSION_DW.Integrator_DSTATE_c = Integrator;
  }

  // End of Outputs for SubSystem: '<S23>/mc_pos_controller'
}

// Termination for enable system: '<S23>/mc_pos_controller'
void HITL_HEXA_MISSION_mc_pos_controller_Term(void)
{
  // Terminate for MATLABSystem: '<S29>/Read Parameter12'
  if (!HITL_HEXA_MISSION_DW.obj_do.matlabCodegenIsDeleted) {
    HITL_HEXA_MISSION_DW.obj_do.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter12'

  // Terminate for MATLABSystem: '<S29>/Read Parameter8'
  if (!HITL_HEXA_MISSION_DW.obj_gf.matlabCodegenIsDeleted) {
    HITL_HEXA_MISSION_DW.obj_gf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter8'

  // Terminate for MATLABSystem: '<S29>/Read Parameter7'
  if (!HITL_HEXA_MISSION_DW.obj_m.matlabCodegenIsDeleted) {
    HITL_HEXA_MISSION_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter7'

  // Terminate for MATLABSystem: '<S29>/Read Parameter13'
  if (!HITL_HEXA_MISSION_DW.obj_n3.matlabCodegenIsDeleted) {
    HITL_HEXA_MISSION_DW.obj_n3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter13'

  // Terminate for MATLABSystem: '<S29>/Read Parameter15'
  if (!HITL_HEXA_MISSION_DW.obj_c.matlabCodegenIsDeleted) {
    HITL_HEXA_MISSION_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter15'

  // Terminate for MATLABSystem: '<S29>/Read Parameter14'
  if (!HITL_HEXA_MISSION_DW.obj_p.matlabCodegenIsDeleted) {
    HITL_HEXA_MISSION_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter14'

  // Terminate for MATLABSystem: '<S29>/Read Parameter3'
  if (!HITL_HEXA_MISSION_DW.obj_i.matlabCodegenIsDeleted) {
    HITL_HEXA_MISSION_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter3'

  // Terminate for MATLABSystem: '<S29>/Read Parameter1'
  if (!HITL_HEXA_MISSION_DW.obj_mt.matlabCodegenIsDeleted) {
    HITL_HEXA_MISSION_DW.obj_mt.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter1'

  // Terminate for MATLABSystem: '<S29>/Read Parameter'
  if (!HITL_HEXA_MISSION_DW.obj_o.matlabCodegenIsDeleted) {
    HITL_HEXA_MISSION_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter'

  // Terminate for MATLABSystem: '<S29>/Read Parameter2'
  if (!HITL_HEXA_MISSION_DW.obj_kf.matlabCodegenIsDeleted) {
    HITL_HEXA_MISSION_DW.obj_kf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter2'
}

//
// File trailer for generated code.
//
// [EOF]
//
