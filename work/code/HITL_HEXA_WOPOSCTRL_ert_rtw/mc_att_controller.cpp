//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mc_att_controller.cpp
//
// Code generated for Simulink model 'HITL_HEXA_WOPOSCTRL'.
//
// Model version                  : 4.141
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Sep 25 17:31:40 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "rtwtypes.h"
#include "mc_att_controller.h"
#include "HITL_HEXA_WOPOSCTRL.h"
#include <math.h>
#include "HITL_HEXA_WOPOSCTRL_private.h"

const real_T HITL_HEXA_WOPOSCTRL_period = 0.004;

// System initialize for enable system: '<S22>/mc_att_controller'
void HITL_HEXA_WOPOSCTRL_mc_att_controller_Init(void)
{
  static const char_T ParameterNameStr[9] = "SL_YAW_P";
  static const char_T ParameterNameStr_0[15] = "SL_YAWRATE_MAX";
  static const char_T ParameterNameStr_1[17] = "SL_PITCHRATE_MAX";
  static const char_T ParameterNameStr_2[11] = "SL_PITCH_P";
  static const char_T ParameterNameStr_3[16] = "SL_ROLLRATE_MAX";
  static const char_T ParameterNameStr_4[10] = "SL_ROLL_P";
  real_T tmp;

  // InitializeConditions for RateLimiter: '<S26>/Rate Limiter2'
  HITL_HEXA_WOPOSCTRL_DW.PrevY = HITL_HEXA_WOPOSCTRL_P.RateLimiter2_IC;

  // InitializeConditions for RateLimiter: '<S26>/Rate Limiter1'
  HITL_HEXA_WOPOSCTRL_DW.PrevY_b = HITL_HEXA_WOPOSCTRL_P.RateLimiter1_IC;

  // Start for MATLABSystem: '<S26>/Read Parameter4'
  HITL_HEXA_WOPOSCTRL_DW.obj_k.matlabCodegenIsDeleted = false;
  HITL_HEXA_WOPOSCTRL_DW.obj_k.SampleTime =
    HITL_HEXA_WOPOSCTRL_P.ReadParameter4_SampleTime_b;
  HITL_HEXA_WOPOSCTRL_DW.obj_k.isInitialized = 1;
  if (HITL_HEXA_WOPOSCTRL_DW.obj_k.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_WOPOSCTRL_DW.obj_k.SampleTime;
  }

  HITL_HEXA_WOPOSCTRL_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr
    [0], true, tmp * 1000.0);
  HITL_HEXA_WOPOSCTRL_DW.obj_k.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S26>/Read Parameter4'

  // Start for MATLABSystem: '<S26>/Read Parameter11'
  HITL_HEXA_WOPOSCTRL_DW.obj_hg.matlabCodegenIsDeleted = false;
  HITL_HEXA_WOPOSCTRL_DW.obj_hg.SampleTime =
    HITL_HEXA_WOPOSCTRL_P.ReadParameter11_SampleTime;
  HITL_HEXA_WOPOSCTRL_DW.obj_hg.isInitialized = 1;
  if (HITL_HEXA_WOPOSCTRL_DW.obj_hg.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_WOPOSCTRL_DW.obj_hg.SampleTime;
  }

  HITL_HEXA_WOPOSCTRL_DW.obj_hg.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_0[0], true, tmp * 1000.0);
  HITL_HEXA_WOPOSCTRL_DW.obj_hg.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S26>/Read Parameter11'

  // Start for MATLABSystem: '<S26>/Read Parameter9'
  HITL_HEXA_WOPOSCTRL_DW.obj_p.matlabCodegenIsDeleted = false;
  HITL_HEXA_WOPOSCTRL_DW.obj_p.SampleTime =
    HITL_HEXA_WOPOSCTRL_P.ReadParameter9_SampleTime;
  HITL_HEXA_WOPOSCTRL_DW.obj_p.isInitialized = 1;
  if (HITL_HEXA_WOPOSCTRL_DW.obj_p.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_WOPOSCTRL_DW.obj_p.SampleTime;
  }

  HITL_HEXA_WOPOSCTRL_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_1[0], true, tmp * 1000.0);
  HITL_HEXA_WOPOSCTRL_DW.obj_p.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S26>/Read Parameter9'

  // Start for MATLABSystem: '<S26>/Read Parameter5'
  HITL_HEXA_WOPOSCTRL_DW.obj_jv.matlabCodegenIsDeleted = false;
  HITL_HEXA_WOPOSCTRL_DW.obj_jv.SampleTime =
    HITL_HEXA_WOPOSCTRL_P.ReadParameter5_SampleTime_m;
  HITL_HEXA_WOPOSCTRL_DW.obj_jv.isInitialized = 1;
  if (HITL_HEXA_WOPOSCTRL_DW.obj_jv.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_WOPOSCTRL_DW.obj_jv.SampleTime;
  }

  HITL_HEXA_WOPOSCTRL_DW.obj_jv.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_2[0], true, tmp * 1000.0);
  HITL_HEXA_WOPOSCTRL_DW.obj_jv.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S26>/Read Parameter5'

  // Start for MATLABSystem: '<S26>/Read Parameter10'
  HITL_HEXA_WOPOSCTRL_DW.obj_g2.matlabCodegenIsDeleted = false;
  HITL_HEXA_WOPOSCTRL_DW.obj_g2.SampleTime =
    HITL_HEXA_WOPOSCTRL_P.ReadParameter10_SampleTime;
  HITL_HEXA_WOPOSCTRL_DW.obj_g2.isInitialized = 1;
  if (HITL_HEXA_WOPOSCTRL_DW.obj_g2.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_WOPOSCTRL_DW.obj_g2.SampleTime;
  }

  HITL_HEXA_WOPOSCTRL_DW.obj_g2.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_3[0], true, tmp * 1000.0);
  HITL_HEXA_WOPOSCTRL_DW.obj_g2.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S26>/Read Parameter10'

  // Start for MATLABSystem: '<S26>/Read Parameter6'
  HITL_HEXA_WOPOSCTRL_DW.obj_m.matlabCodegenIsDeleted = false;
  HITL_HEXA_WOPOSCTRL_DW.obj_m.SampleTime =
    HITL_HEXA_WOPOSCTRL_P.ReadParameter6_SampleTime;
  HITL_HEXA_WOPOSCTRL_DW.obj_m.isInitialized = 1;
  if (HITL_HEXA_WOPOSCTRL_DW.obj_m.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_WOPOSCTRL_DW.obj_m.SampleTime;
  }

  HITL_HEXA_WOPOSCTRL_DW.obj_m.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_4[0], true, tmp * 1000.0);
  HITL_HEXA_WOPOSCTRL_DW.obj_m.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S26>/Read Parameter6'

  // SystemInitialize for Switch: '<S183>/Switch2' incorporates:
  //   Outport: '<S26>/Yawrate_sp'

  HITL_HEXA_WOPOSCTRL_B.Switch2 = HITL_HEXA_WOPOSCTRL_P.Yawrate_sp_Y0;

  // SystemInitialize for Switch: '<S85>/Switch2' incorporates:
  //   Outport: '<S26>/Pitchrate_sp'

  HITL_HEXA_WOPOSCTRL_B.Switch2_l = HITL_HEXA_WOPOSCTRL_P.Pitchrate_sp_Y0;

  // SystemInitialize for Switch: '<S134>/Switch2' incorporates:
  //   Outport: '<S26>/Rollrate_spl'

  HITL_HEXA_WOPOSCTRL_B.Switch2_n = HITL_HEXA_WOPOSCTRL_P.Rollrate_spl_Y0;
}

// Output and update for enable system: '<S22>/mc_att_controller'
void HITL_HEXA_WOPOSCTRL_mc_att_controller(void)
{
  real32_T ParamStep;

  // Outputs for Enabled SubSystem: '<S22>/mc_att_controller' incorporates:
  //   EnablePort: '<S26>/Enable'

  if (HITL_HEXA_WOPOSCTRL_B.In1_b.armed) {
    real_T rtb_Sum5;
    real32_T rtb_Gain1_a;
    boolean_T b_varargout_2;

    // Sum: '<S26>/Sum5'
    rtb_Sum5 = HITL_HEXA_WOPOSCTRL_B.CastToDouble[2] -
      HITL_HEXA_WOPOSCTRL_B.VectorConcatenate[0];

    // Switch: '<S39>/Switch' incorporates:
    //   Abs: '<S39>/Abs'

    if (fabs(rtb_Sum5) > HITL_HEXA_WOPOSCTRL_P.Switch_Threshold) {
      // Switch: '<S39>/Switch1' incorporates:
      //   Constant: '<S39>/Constant'
      //   Sum: '<S39>/Add'
      //   Sum: '<S39>/Subtract'

      if (rtb_Sum5 > HITL_HEXA_WOPOSCTRL_P.Switch1_Threshold) {
        rtb_Sum5 -= HITL_HEXA_WOPOSCTRL_P.Constant_Value_p;
      } else {
        rtb_Sum5 += HITL_HEXA_WOPOSCTRL_P.Constant_Value_p;
      }

      // End of Switch: '<S39>/Switch1'
    }

    // End of Switch: '<S39>/Switch'

    // MATLABSystem: '<S26>/Read Parameter4'
    if (HITL_HEXA_WOPOSCTRL_DW.obj_k.SampleTime !=
        HITL_HEXA_WOPOSCTRL_P.ReadParameter4_SampleTime_b) {
      HITL_HEXA_WOPOSCTRL_DW.obj_k.SampleTime =
        HITL_HEXA_WOPOSCTRL_P.ReadParameter4_SampleTime_b;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_k.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S180>/PProd Out' incorporates:
    //   MATLABSystem: '<S26>/Read Parameter4'
    //
    rtb_Sum5 *= ParamStep;

    // MATLABSystem: '<S26>/Read Parameter11'
    if (HITL_HEXA_WOPOSCTRL_DW.obj_hg.SampleTime !=
        HITL_HEXA_WOPOSCTRL_P.ReadParameter11_SampleTime) {
      HITL_HEXA_WOPOSCTRL_DW.obj_hg.SampleTime =
        HITL_HEXA_WOPOSCTRL_P.ReadParameter11_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_hg.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Gain: '<S42>/Gain1' incorporates:
    //   MATLABSystem: '<S26>/Read Parameter11'
    //
    ParamStep *= HITL_HEXA_WOPOSCTRL_P.Gain1_Gain_k;

    // Switch: '<S183>/Switch2' incorporates:
    //   RelationalOperator: '<S183>/LowerRelop1'
    //   RelationalOperator: '<S183>/UpperRelop'
    //   Switch: '<S183>/Switch'
    //   UnaryMinus: '<S26>/Unary Minus'

    if (rtb_Sum5 > ParamStep) {
      // Switch: '<S183>/Switch2'
      HITL_HEXA_WOPOSCTRL_B.Switch2 = ParamStep;
    } else if (rtb_Sum5 < -ParamStep) {
      // Switch: '<S183>/Switch' incorporates:
      //   Switch: '<S183>/Switch2'
      //   UnaryMinus: '<S26>/Unary Minus'

      HITL_HEXA_WOPOSCTRL_B.Switch2 = -ParamStep;
    } else {
      // Switch: '<S183>/Switch2' incorporates:
      //   Switch: '<S183>/Switch'

      HITL_HEXA_WOPOSCTRL_B.Switch2 = rtb_Sum5;
    }

    // End of Switch: '<S183>/Switch2'

    // MATLABSystem: '<S26>/Read Parameter9'
    if (HITL_HEXA_WOPOSCTRL_DW.obj_p.SampleTime !=
        HITL_HEXA_WOPOSCTRL_P.ReadParameter9_SampleTime) {
      HITL_HEXA_WOPOSCTRL_DW.obj_p.SampleTime =
        HITL_HEXA_WOPOSCTRL_P.ReadParameter9_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_p.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Gain: '<S40>/Gain1' incorporates:
    //   MATLABSystem: '<S26>/Read Parameter9'
    //
    rtb_Gain1_a = HITL_HEXA_WOPOSCTRL_P.Gain1_Gain_i * ParamStep;

    // RateLimiter: '<S26>/Rate Limiter2'
    rtb_Sum5 = HITL_HEXA_WOPOSCTRL_B.CastToDouble[1] -
      HITL_HEXA_WOPOSCTRL_DW.PrevY;
    if (rtb_Sum5 > HITL_HEXA_WOPOSCTRL_P.RateLimiter2_RisingLim *
        HITL_HEXA_WOPOSCTRL_period) {
      rtb_Sum5 = HITL_HEXA_WOPOSCTRL_P.RateLimiter2_RisingLim *
        HITL_HEXA_WOPOSCTRL_period + HITL_HEXA_WOPOSCTRL_DW.PrevY;
    } else if (rtb_Sum5 < HITL_HEXA_WOPOSCTRL_P.RateLimiter2_FallingLim *
               HITL_HEXA_WOPOSCTRL_period) {
      rtb_Sum5 = HITL_HEXA_WOPOSCTRL_P.RateLimiter2_FallingLim *
        HITL_HEXA_WOPOSCTRL_period + HITL_HEXA_WOPOSCTRL_DW.PrevY;
    } else {
      rtb_Sum5 = HITL_HEXA_WOPOSCTRL_B.CastToDouble[1];
    }

    HITL_HEXA_WOPOSCTRL_DW.PrevY = rtb_Sum5;

    // End of RateLimiter: '<S26>/Rate Limiter2'

    // Sum: '<S26>/Sum2'
    rtb_Sum5 -= HITL_HEXA_WOPOSCTRL_B.VectorConcatenate[1];

    // MATLABSystem: '<S26>/Read Parameter5'
    if (HITL_HEXA_WOPOSCTRL_DW.obj_jv.SampleTime !=
        HITL_HEXA_WOPOSCTRL_P.ReadParameter5_SampleTime_m) {
      HITL_HEXA_WOPOSCTRL_DW.obj_jv.SampleTime =
        HITL_HEXA_WOPOSCTRL_P.ReadParameter5_SampleTime_m;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_jv.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S82>/PProd Out' incorporates:
    //   MATLABSystem: '<S26>/Read Parameter5'
    //
    rtb_Sum5 *= ParamStep;

    // Switch: '<S85>/Switch2' incorporates:
    //   RelationalOperator: '<S85>/LowerRelop1'
    //   RelationalOperator: '<S85>/UpperRelop'
    //   Switch: '<S85>/Switch'
    //   UnaryMinus: '<S26>/Unary Minus1'

    if (rtb_Sum5 > rtb_Gain1_a) {
      // Switch: '<S85>/Switch2'
      HITL_HEXA_WOPOSCTRL_B.Switch2_l = rtb_Gain1_a;
    } else if (rtb_Sum5 < -rtb_Gain1_a) {
      // Switch: '<S85>/Switch' incorporates:
      //   Switch: '<S85>/Switch2'
      //   UnaryMinus: '<S26>/Unary Minus1'

      HITL_HEXA_WOPOSCTRL_B.Switch2_l = -rtb_Gain1_a;
    } else {
      // Switch: '<S85>/Switch2' incorporates:
      //   Switch: '<S85>/Switch'

      HITL_HEXA_WOPOSCTRL_B.Switch2_l = rtb_Sum5;
    }

    // End of Switch: '<S85>/Switch2'

    // MATLABSystem: '<S26>/Read Parameter10'
    if (HITL_HEXA_WOPOSCTRL_DW.obj_g2.SampleTime !=
        HITL_HEXA_WOPOSCTRL_P.ReadParameter10_SampleTime) {
      HITL_HEXA_WOPOSCTRL_DW.obj_g2.SampleTime =
        HITL_HEXA_WOPOSCTRL_P.ReadParameter10_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_g2.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Gain: '<S41>/Gain1' incorporates:
    //   MATLABSystem: '<S26>/Read Parameter10'
    //
    rtb_Gain1_a = HITL_HEXA_WOPOSCTRL_P.Gain1_Gain_o * ParamStep;

    // RateLimiter: '<S26>/Rate Limiter1'
    rtb_Sum5 = HITL_HEXA_WOPOSCTRL_B.CastToDouble[0] -
      HITL_HEXA_WOPOSCTRL_DW.PrevY_b;
    if (rtb_Sum5 > HITL_HEXA_WOPOSCTRL_P.RateLimiter1_RisingLim *
        HITL_HEXA_WOPOSCTRL_period) {
      rtb_Sum5 = HITL_HEXA_WOPOSCTRL_P.RateLimiter1_RisingLim *
        HITL_HEXA_WOPOSCTRL_period + HITL_HEXA_WOPOSCTRL_DW.PrevY_b;
    } else if (rtb_Sum5 < HITL_HEXA_WOPOSCTRL_P.RateLimiter1_FallingLim *
               HITL_HEXA_WOPOSCTRL_period) {
      rtb_Sum5 = HITL_HEXA_WOPOSCTRL_P.RateLimiter1_FallingLim *
        HITL_HEXA_WOPOSCTRL_period + HITL_HEXA_WOPOSCTRL_DW.PrevY_b;
    } else {
      rtb_Sum5 = HITL_HEXA_WOPOSCTRL_B.CastToDouble[0];
    }

    HITL_HEXA_WOPOSCTRL_DW.PrevY_b = rtb_Sum5;

    // End of RateLimiter: '<S26>/Rate Limiter1'

    // Sum: '<S26>/Sum3'
    rtb_Sum5 -= HITL_HEXA_WOPOSCTRL_B.VectorConcatenate[2];

    // MATLABSystem: '<S26>/Read Parameter6'
    if (HITL_HEXA_WOPOSCTRL_DW.obj_m.SampleTime !=
        HITL_HEXA_WOPOSCTRL_P.ReadParameter6_SampleTime) {
      HITL_HEXA_WOPOSCTRL_DW.obj_m.SampleTime =
        HITL_HEXA_WOPOSCTRL_P.ReadParameter6_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_m.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S131>/PProd Out' incorporates:
    //   MATLABSystem: '<S26>/Read Parameter6'
    //
    rtb_Sum5 *= ParamStep;

    // Switch: '<S134>/Switch2' incorporates:
    //   RelationalOperator: '<S134>/LowerRelop1'
    //   RelationalOperator: '<S134>/UpperRelop'
    //   Switch: '<S134>/Switch'
    //   UnaryMinus: '<S26>/Unary Minus2'

    if (rtb_Sum5 > rtb_Gain1_a) {
      // Switch: '<S134>/Switch2'
      HITL_HEXA_WOPOSCTRL_B.Switch2_n = rtb_Gain1_a;
    } else if (rtb_Sum5 < -rtb_Gain1_a) {
      // Switch: '<S134>/Switch' incorporates:
      //   Switch: '<S134>/Switch2'
      //   UnaryMinus: '<S26>/Unary Minus2'

      HITL_HEXA_WOPOSCTRL_B.Switch2_n = -rtb_Gain1_a;
    } else {
      // Switch: '<S134>/Switch2' incorporates:
      //   Switch: '<S134>/Switch'

      HITL_HEXA_WOPOSCTRL_B.Switch2_n = rtb_Sum5;
    }

    // End of Switch: '<S134>/Switch2'
  }

  // End of Outputs for SubSystem: '<S22>/mc_att_controller'
}

// Termination for enable system: '<S22>/mc_att_controller'
void HITL_HEXA_WOPOSCTRL_mc_att_controller_Term(void)
{
  // Terminate for MATLABSystem: '<S26>/Read Parameter4'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_k.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S26>/Read Parameter4'

  // Terminate for MATLABSystem: '<S26>/Read Parameter11'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_hg.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_hg.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S26>/Read Parameter11'

  // Terminate for MATLABSystem: '<S26>/Read Parameter9'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_p.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S26>/Read Parameter9'

  // Terminate for MATLABSystem: '<S26>/Read Parameter5'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_jv.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_jv.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S26>/Read Parameter5'

  // Terminate for MATLABSystem: '<S26>/Read Parameter10'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_g2.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_g2.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S26>/Read Parameter10'

  // Terminate for MATLABSystem: '<S26>/Read Parameter6'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_m.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S26>/Read Parameter6'
}

//
// File trailer for generated code.
//
// [EOF]
//
