//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mc_att_controller.cpp
//
// Code generated for Simulink model 'Copy_of_HITL_HEXA_MISSION'.
//
// Model version                  : 5.1
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Mon Oct 14 16:51:03 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "rtwtypes.h"
#include "mc_att_controller.h"
#include "Copy_of_HITL_HEXA_MISSION.h"
#include <math.h>
#include "Copy_of_HITL_HEXA_MISSION_private.h"

const real_T Copy_of_HITL_HEXA_MISSION_period = 0.004;

// System initialize for enable system: '<S23>/mc_att_controller'
void Copy_of_HITL_HEXA_MISSION_mc_att_controller_Init(void)
{
  static const char_T ParameterNameStr[9] = "SL_YAW_P";
  static const char_T ParameterNameStr_0[15] = "SL_YAWRATE_MAX";
  static const char_T ParameterNameStr_1[17] = "SL_PITCHRATE_MAX";
  static const char_T ParameterNameStr_2[11] = "SL_PITCH_P";
  static const char_T ParameterNameStr_3[16] = "SL_ROLLRATE_MAX";
  static const char_T ParameterNameStr_4[10] = "SL_ROLL_P";
  real_T tmp;

  // InitializeConditions for RateLimiter: '<S28>/Rate Limiter2'
  Copy_of_HITL_HEXA_MISSION_DW.PrevY =
    Copy_of_HITL_HEXA_MISSION_P.RateLimiter2_IC;

  // InitializeConditions for RateLimiter: '<S28>/Rate Limiter1'
  Copy_of_HITL_HEXA_MISSION_DW.PrevY_b =
    Copy_of_HITL_HEXA_MISSION_P.RateLimiter1_IC;

  // Start for MATLABSystem: '<S28>/Read Parameter4'
  Copy_of_HITL_HEXA_MISSION_DW.obj_km.matlabCodegenIsDeleted = false;
  Copy_of_HITL_HEXA_MISSION_DW.obj_km.SampleTime =
    Copy_of_HITL_HEXA_MISSION_P.ReadParameter4_SampleTime_b;
  Copy_of_HITL_HEXA_MISSION_DW.obj_km.isInitialized = 1;
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_km.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_km.SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_DW.obj_km.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr[0], true, tmp * 1000.0);
  Copy_of_HITL_HEXA_MISSION_DW.obj_km.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S28>/Read Parameter4'

  // Start for MATLABSystem: '<S28>/Read Parameter11'
  Copy_of_HITL_HEXA_MISSION_DW.obj_hg.matlabCodegenIsDeleted = false;
  Copy_of_HITL_HEXA_MISSION_DW.obj_hg.SampleTime =
    Copy_of_HITL_HEXA_MISSION_P.ReadParameter11_SampleTime;
  Copy_of_HITL_HEXA_MISSION_DW.obj_hg.isInitialized = 1;
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_hg.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_hg.SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_DW.obj_hg.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_0[0], true, tmp * 1000.0);
  Copy_of_HITL_HEXA_MISSION_DW.obj_hg.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S28>/Read Parameter11'

  // Start for MATLABSystem: '<S28>/Read Parameter9'
  Copy_of_HITL_HEXA_MISSION_DW.obj_pk.matlabCodegenIsDeleted = false;
  Copy_of_HITL_HEXA_MISSION_DW.obj_pk.SampleTime =
    Copy_of_HITL_HEXA_MISSION_P.ReadParameter9_SampleTime;
  Copy_of_HITL_HEXA_MISSION_DW.obj_pk.isInitialized = 1;
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_pk.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_pk.SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_DW.obj_pk.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_1[0], true, tmp * 1000.0);
  Copy_of_HITL_HEXA_MISSION_DW.obj_pk.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S28>/Read Parameter9'

  // Start for MATLABSystem: '<S28>/Read Parameter5'
  Copy_of_HITL_HEXA_MISSION_DW.obj_jv.matlabCodegenIsDeleted = false;
  Copy_of_HITL_HEXA_MISSION_DW.obj_jv.SampleTime =
    Copy_of_HITL_HEXA_MISSION_P.ReadParameter5_SampleTime_m;
  Copy_of_HITL_HEXA_MISSION_DW.obj_jv.isInitialized = 1;
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_jv.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_jv.SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_DW.obj_jv.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_2[0], true, tmp * 1000.0);
  Copy_of_HITL_HEXA_MISSION_DW.obj_jv.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S28>/Read Parameter5'

  // Start for MATLABSystem: '<S28>/Read Parameter10'
  Copy_of_HITL_HEXA_MISSION_DW.obj_g2.matlabCodegenIsDeleted = false;
  Copy_of_HITL_HEXA_MISSION_DW.obj_g2.SampleTime =
    Copy_of_HITL_HEXA_MISSION_P.ReadParameter10_SampleTime;
  Copy_of_HITL_HEXA_MISSION_DW.obj_g2.isInitialized = 1;
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_g2.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_g2.SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_DW.obj_g2.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_3[0], true, tmp * 1000.0);
  Copy_of_HITL_HEXA_MISSION_DW.obj_g2.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S28>/Read Parameter10'

  // Start for MATLABSystem: '<S28>/Read Parameter6'
  Copy_of_HITL_HEXA_MISSION_DW.obj_m5.matlabCodegenIsDeleted = false;
  Copy_of_HITL_HEXA_MISSION_DW.obj_m5.SampleTime =
    Copy_of_HITL_HEXA_MISSION_P.ReadParameter6_SampleTime;
  Copy_of_HITL_HEXA_MISSION_DW.obj_m5.isInitialized = 1;
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_m5.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_m5.SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_DW.obj_m5.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_4[0], true, tmp * 1000.0);
  Copy_of_HITL_HEXA_MISSION_DW.obj_m5.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S28>/Read Parameter6'

  // SystemInitialize for Switch: '<S194>/Switch2' incorporates:
  //   Outport: '<S28>/Yawrate_sp'

  Copy_of_HITL_HEXA_MISSION_B.Switch2_o =
    Copy_of_HITL_HEXA_MISSION_P.Yawrate_sp_Y0;

  // SystemInitialize for Switch: '<S92>/Switch2' incorporates:
  //   Outport: '<S28>/Pitchrate_sp'

  Copy_of_HITL_HEXA_MISSION_B.Switch2_l =
    Copy_of_HITL_HEXA_MISSION_P.Pitchrate_sp_Y0;

  // SystemInitialize for Switch: '<S143>/Switch2' incorporates:
  //   Outport: '<S28>/Rollrate_spl'

  Copy_of_HITL_HEXA_MISSION_B.Switch2_n =
    Copy_of_HITL_HEXA_MISSION_P.Rollrate_spl_Y0;
}

// Output and update for enable system: '<S23>/mc_att_controller'
void Copy_of_HITL_HEXA_MISSION_mc_att_controller(void)
{
  real32_T ParamStep;

  // Outputs for Enabled SubSystem: '<S23>/mc_att_controller' incorporates:
  //   EnablePort: '<S28>/Enable'

  if (Copy_of_HITL_HEXA_MISSION_B.In1_b.armed) {
    real_T rtb_Sum5;
    real32_T rtb_Gain1_a;
    boolean_T b_varargout_2;

    // Sum: '<S28>/Sum5'
    rtb_Sum5 = Copy_of_HITL_HEXA_MISSION_B.Merge[3] -
      Copy_of_HITL_HEXA_MISSION_B.VectorConcatenate[0];

    // Switch: '<S44>/Switch' incorporates:
    //   Abs: '<S44>/Abs'

    if (fabs(rtb_Sum5) > Copy_of_HITL_HEXA_MISSION_P.Switch_Threshold) {
      // Switch: '<S44>/Switch1' incorporates:
      //   Constant: '<S44>/Constant'
      //   Sum: '<S44>/Add'
      //   Sum: '<S44>/Subtract'

      if (rtb_Sum5 > Copy_of_HITL_HEXA_MISSION_P.Switch1_Threshold) {
        rtb_Sum5 -= Copy_of_HITL_HEXA_MISSION_P.Constant_Value_p;
      } else {
        rtb_Sum5 += Copy_of_HITL_HEXA_MISSION_P.Constant_Value_p;
      }

      // End of Switch: '<S44>/Switch1'
    }

    // End of Switch: '<S44>/Switch'

    // MATLABSystem: '<S28>/Read Parameter4'
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_km.SampleTime !=
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter4_SampleTime_b) {
      Copy_of_HITL_HEXA_MISSION_DW.obj_km.SampleTime =
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter4_SampleTime_b;
    }

    b_varargout_2 = MW_Param_Step
      (Copy_of_HITL_HEXA_MISSION_DW.obj_km.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S191>/PProd Out' incorporates:
    //   MATLABSystem: '<S28>/Read Parameter4'
    //
    rtb_Sum5 *= ParamStep;

    // MATLABSystem: '<S28>/Read Parameter11'
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_hg.SampleTime !=
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter11_SampleTime) {
      Copy_of_HITL_HEXA_MISSION_DW.obj_hg.SampleTime =
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter11_SampleTime;
    }

    b_varargout_2 = MW_Param_Step
      (Copy_of_HITL_HEXA_MISSION_DW.obj_hg.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Gain: '<S47>/Gain1' incorporates:
    //   MATLABSystem: '<S28>/Read Parameter11'
    //
    ParamStep *= Copy_of_HITL_HEXA_MISSION_P.Gain1_Gain_k;

    // Switch: '<S194>/Switch2' incorporates:
    //   RelationalOperator: '<S194>/LowerRelop1'
    //   RelationalOperator: '<S194>/UpperRelop'
    //   Switch: '<S194>/Switch'
    //   UnaryMinus: '<S28>/Unary Minus'

    if (rtb_Sum5 > ParamStep) {
      // Switch: '<S194>/Switch2'
      Copy_of_HITL_HEXA_MISSION_B.Switch2_o = ParamStep;
    } else if (rtb_Sum5 < -ParamStep) {
      // Switch: '<S194>/Switch' incorporates:
      //   Switch: '<S194>/Switch2'
      //   UnaryMinus: '<S28>/Unary Minus'

      Copy_of_HITL_HEXA_MISSION_B.Switch2_o = -ParamStep;
    } else {
      // Switch: '<S194>/Switch2' incorporates:
      //   Switch: '<S194>/Switch'

      Copy_of_HITL_HEXA_MISSION_B.Switch2_o = rtb_Sum5;
    }

    // End of Switch: '<S194>/Switch2'

    // MATLABSystem: '<S28>/Read Parameter9'
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_pk.SampleTime !=
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter9_SampleTime) {
      Copy_of_HITL_HEXA_MISSION_DW.obj_pk.SampleTime =
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter9_SampleTime;
    }

    b_varargout_2 = MW_Param_Step
      (Copy_of_HITL_HEXA_MISSION_DW.obj_pk.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Gain: '<S45>/Gain1' incorporates:
    //   MATLABSystem: '<S28>/Read Parameter9'
    //
    rtb_Gain1_a = Copy_of_HITL_HEXA_MISSION_P.Gain1_Gain_i * ParamStep;

    // RateLimiter: '<S28>/Rate Limiter2'
    rtb_Sum5 = Copy_of_HITL_HEXA_MISSION_B.Gain1 -
      Copy_of_HITL_HEXA_MISSION_DW.PrevY;
    if (rtb_Sum5 > Copy_of_HITL_HEXA_MISSION_P.RateLimiter2_RisingLim *
        Copy_of_HITL_HEXA_MISSION_period) {
      rtb_Sum5 = Copy_of_HITL_HEXA_MISSION_P.RateLimiter2_RisingLim *
        Copy_of_HITL_HEXA_MISSION_period + Copy_of_HITL_HEXA_MISSION_DW.PrevY;
    } else if (rtb_Sum5 < Copy_of_HITL_HEXA_MISSION_P.RateLimiter2_FallingLim *
               Copy_of_HITL_HEXA_MISSION_period) {
      rtb_Sum5 = Copy_of_HITL_HEXA_MISSION_P.RateLimiter2_FallingLim *
        Copy_of_HITL_HEXA_MISSION_period + Copy_of_HITL_HEXA_MISSION_DW.PrevY;
    } else {
      rtb_Sum5 = Copy_of_HITL_HEXA_MISSION_B.Gain1;
    }

    Copy_of_HITL_HEXA_MISSION_DW.PrevY = rtb_Sum5;

    // End of RateLimiter: '<S28>/Rate Limiter2'

    // Sum: '<S28>/Sum2'
    rtb_Sum5 -= Copy_of_HITL_HEXA_MISSION_B.VectorConcatenate[1];

    // MATLABSystem: '<S28>/Read Parameter5'
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_jv.SampleTime !=
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter5_SampleTime_m) {
      Copy_of_HITL_HEXA_MISSION_DW.obj_jv.SampleTime =
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter5_SampleTime_m;
    }

    b_varargout_2 = MW_Param_Step
      (Copy_of_HITL_HEXA_MISSION_DW.obj_jv.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S89>/PProd Out' incorporates:
    //   MATLABSystem: '<S28>/Read Parameter5'
    //
    rtb_Sum5 *= ParamStep;

    // Switch: '<S92>/Switch2' incorporates:
    //   RelationalOperator: '<S92>/LowerRelop1'
    //   RelationalOperator: '<S92>/UpperRelop'
    //   Switch: '<S92>/Switch'
    //   UnaryMinus: '<S28>/Unary Minus1'

    if (rtb_Sum5 > rtb_Gain1_a) {
      // Switch: '<S92>/Switch2'
      Copy_of_HITL_HEXA_MISSION_B.Switch2_l = rtb_Gain1_a;
    } else if (rtb_Sum5 < -rtb_Gain1_a) {
      // Switch: '<S92>/Switch' incorporates:
      //   Switch: '<S92>/Switch2'
      //   UnaryMinus: '<S28>/Unary Minus1'

      Copy_of_HITL_HEXA_MISSION_B.Switch2_l = -rtb_Gain1_a;
    } else {
      // Switch: '<S92>/Switch2' incorporates:
      //   Switch: '<S92>/Switch'

      Copy_of_HITL_HEXA_MISSION_B.Switch2_l = rtb_Sum5;
    }

    // End of Switch: '<S92>/Switch2'

    // MATLABSystem: '<S28>/Read Parameter10'
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_g2.SampleTime !=
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter10_SampleTime) {
      Copy_of_HITL_HEXA_MISSION_DW.obj_g2.SampleTime =
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter10_SampleTime;
    }

    b_varargout_2 = MW_Param_Step
      (Copy_of_HITL_HEXA_MISSION_DW.obj_g2.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Gain: '<S46>/Gain1' incorporates:
    //   MATLABSystem: '<S28>/Read Parameter10'
    //
    rtb_Gain1_a = Copy_of_HITL_HEXA_MISSION_P.Gain1_Gain_o * ParamStep;

    // RateLimiter: '<S28>/Rate Limiter1'
    rtb_Sum5 = Copy_of_HITL_HEXA_MISSION_B.Switch2[1] -
      Copy_of_HITL_HEXA_MISSION_DW.PrevY_b;
    if (rtb_Sum5 > Copy_of_HITL_HEXA_MISSION_P.RateLimiter1_RisingLim *
        Copy_of_HITL_HEXA_MISSION_period) {
      rtb_Sum5 = Copy_of_HITL_HEXA_MISSION_P.RateLimiter1_RisingLim *
        Copy_of_HITL_HEXA_MISSION_period + Copy_of_HITL_HEXA_MISSION_DW.PrevY_b;
    } else if (rtb_Sum5 < Copy_of_HITL_HEXA_MISSION_P.RateLimiter1_FallingLim *
               Copy_of_HITL_HEXA_MISSION_period) {
      rtb_Sum5 = Copy_of_HITL_HEXA_MISSION_P.RateLimiter1_FallingLim *
        Copy_of_HITL_HEXA_MISSION_period + Copy_of_HITL_HEXA_MISSION_DW.PrevY_b;
    } else {
      rtb_Sum5 = Copy_of_HITL_HEXA_MISSION_B.Switch2[1];
    }

    Copy_of_HITL_HEXA_MISSION_DW.PrevY_b = rtb_Sum5;

    // End of RateLimiter: '<S28>/Rate Limiter1'

    // Sum: '<S28>/Sum3'
    rtb_Sum5 -= Copy_of_HITL_HEXA_MISSION_B.VectorConcatenate[2];

    // MATLABSystem: '<S28>/Read Parameter6'
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_m5.SampleTime !=
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter6_SampleTime) {
      Copy_of_HITL_HEXA_MISSION_DW.obj_m5.SampleTime =
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter6_SampleTime;
    }

    b_varargout_2 = MW_Param_Step
      (Copy_of_HITL_HEXA_MISSION_DW.obj_m5.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S140>/PProd Out' incorporates:
    //   MATLABSystem: '<S28>/Read Parameter6'
    //
    rtb_Sum5 *= ParamStep;

    // Switch: '<S143>/Switch2' incorporates:
    //   RelationalOperator: '<S143>/LowerRelop1'
    //   RelationalOperator: '<S143>/UpperRelop'
    //   Switch: '<S143>/Switch'
    //   UnaryMinus: '<S28>/Unary Minus2'

    if (rtb_Sum5 > rtb_Gain1_a) {
      // Switch: '<S143>/Switch2'
      Copy_of_HITL_HEXA_MISSION_B.Switch2_n = rtb_Gain1_a;
    } else if (rtb_Sum5 < -rtb_Gain1_a) {
      // Switch: '<S143>/Switch' incorporates:
      //   Switch: '<S143>/Switch2'
      //   UnaryMinus: '<S28>/Unary Minus2'

      Copy_of_HITL_HEXA_MISSION_B.Switch2_n = -rtb_Gain1_a;
    } else {
      // Switch: '<S143>/Switch2' incorporates:
      //   Switch: '<S143>/Switch'

      Copy_of_HITL_HEXA_MISSION_B.Switch2_n = rtb_Sum5;
    }

    // End of Switch: '<S143>/Switch2'
  }

  // End of Outputs for SubSystem: '<S23>/mc_att_controller'
}

// Termination for enable system: '<S23>/mc_att_controller'
void Copy_of_HITL_HEXA_MISSION_mc_att_controller_Term(void)
{
  // Terminate for MATLABSystem: '<S28>/Read Parameter4'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_km.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_km.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S28>/Read Parameter4'

  // Terminate for MATLABSystem: '<S28>/Read Parameter11'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_hg.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_hg.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S28>/Read Parameter11'

  // Terminate for MATLABSystem: '<S28>/Read Parameter9'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_pk.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_pk.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S28>/Read Parameter9'

  // Terminate for MATLABSystem: '<S28>/Read Parameter5'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_jv.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_jv.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S28>/Read Parameter5'

  // Terminate for MATLABSystem: '<S28>/Read Parameter10'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_g2.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_g2.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S28>/Read Parameter10'

  // Terminate for MATLABSystem: '<S28>/Read Parameter6'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_m5.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_m5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S28>/Read Parameter6'
}

//
// File trailer for generated code.
//
// [EOF]
//
