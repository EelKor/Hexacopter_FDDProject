//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mc_att_controller.cpp
//
// Code generated for Simulink model 'SITL_HEXA_MISSION'.
//
// Model version                  : 5.6
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Sun Oct 20 19:46:11 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "rtwtypes.h"
#include "mc_att_controller.h"
#include "SITL_HEXA_MISSION.h"
#include <math.h>
#include "SITL_HEXA_MISSION_private.h"

const real_T SITL_HEXA_MISSION_period = 0.004;

// System initialize for enable system: '<S5>/mc_att_controller'
void SITL_HEXA_MISSION_mc_att_controller_Init(void)
{
  // InitializeConditions for RateLimiter: '<S11>/Rate Limiter2'
  SITL_HEXA_MISSION_DW.PrevY = SITL_HEXA_MISSION_P.RateLimiter2_IC;

  // InitializeConditions for RateLimiter: '<S11>/Rate Limiter1'
  SITL_HEXA_MISSION_DW.PrevY_f = SITL_HEXA_MISSION_P.RateLimiter1_IC;

  // SystemInitialize for Saturate: '<S173>/Saturation' incorporates:
  //   Outport: '<S11>/Yawrate_sp'

  SITL_HEXA_MISSION_B.Saturation_e = SITL_HEXA_MISSION_P.Yawrate_sp_Y0;

  // SystemInitialize for Gain: '<S71>/Proportional Gain' incorporates:
  //   Outport: '<S11>/Pitchrate_sp'

  SITL_HEXA_MISSION_B.ProportionalGain = SITL_HEXA_MISSION_P.Pitchrate_sp_Y0;

  // SystemInitialize for Gain: '<S121>/Proportional Gain' incorporates:
  //   Outport: '<S11>/Rollrate_spl'

  SITL_HEXA_MISSION_B.ProportionalGain_a = SITL_HEXA_MISSION_P.Rollrate_spl_Y0;
}

// Output and update for enable system: '<S5>/mc_att_controller'
void SITL_HEXA_MISSION_mc_att_controller(void)
{
  // Outputs for Enabled SubSystem: '<S5>/mc_att_controller' incorporates:
  //   EnablePort: '<S11>/Enable'

  if (SITL_HEXA_MISSION_B.In1_b.armed) {
    real_T rtb_Sum5;

    // Sum: '<S11>/Sum5'
    rtb_Sum5 = SITL_HEXA_MISSION_B.Merge[3] -
      SITL_HEXA_MISSION_B.VectorConcatenate[0];

    // Switch: '<S29>/Switch' incorporates:
    //   Abs: '<S29>/Abs'

    if (fabs(rtb_Sum5) > SITL_HEXA_MISSION_P.Switch_Threshold) {
      // Switch: '<S29>/Switch1' incorporates:
      //   Constant: '<S29>/Constant'
      //   Sum: '<S29>/Add'
      //   Sum: '<S29>/Subtract'

      if (rtb_Sum5 > SITL_HEXA_MISSION_P.Switch1_Threshold) {
        rtb_Sum5 -= SITL_HEXA_MISSION_P.Constant_Value_p;
      } else {
        rtb_Sum5 += SITL_HEXA_MISSION_P.Constant_Value_p;
      }

      // End of Switch: '<S29>/Switch1'
    }

    // End of Switch: '<S29>/Switch'

    // Gain: '<S171>/Proportional Gain'
    rtb_Sum5 *= SITL_HEXA_MISSION_P.MC_YAW_P;

    // Saturate: '<S173>/Saturation'
    if (rtb_Sum5 > SITL_HEXA_MISSION_P.PIDController5_UpperSaturationLimit) {
      // Saturate: '<S173>/Saturation'
      SITL_HEXA_MISSION_B.Saturation_e =
        SITL_HEXA_MISSION_P.PIDController5_UpperSaturationLimit;
    } else if (rtb_Sum5 <
               SITL_HEXA_MISSION_P.PIDController5_LowerSaturationLimit) {
      // Saturate: '<S173>/Saturation'
      SITL_HEXA_MISSION_B.Saturation_e =
        SITL_HEXA_MISSION_P.PIDController5_LowerSaturationLimit;
    } else {
      // Saturate: '<S173>/Saturation'
      SITL_HEXA_MISSION_B.Saturation_e = rtb_Sum5;
    }

    // End of Saturate: '<S173>/Saturation'

    // RateLimiter: '<S11>/Rate Limiter2'
    rtb_Sum5 = SITL_HEXA_MISSION_B.Gain1 - SITL_HEXA_MISSION_DW.PrevY;
    if (rtb_Sum5 > SITL_HEXA_MISSION_P.RateLimiter2_RisingLim *
        SITL_HEXA_MISSION_period) {
      rtb_Sum5 = SITL_HEXA_MISSION_P.RateLimiter2_RisingLim *
        SITL_HEXA_MISSION_period + SITL_HEXA_MISSION_DW.PrevY;
    } else if (rtb_Sum5 < SITL_HEXA_MISSION_P.RateLimiter2_FallingLim *
               SITL_HEXA_MISSION_period) {
      rtb_Sum5 = SITL_HEXA_MISSION_P.RateLimiter2_FallingLim *
        SITL_HEXA_MISSION_period + SITL_HEXA_MISSION_DW.PrevY;
    } else {
      rtb_Sum5 = SITL_HEXA_MISSION_B.Gain1;
    }

    SITL_HEXA_MISSION_DW.PrevY = rtb_Sum5;

    // End of RateLimiter: '<S11>/Rate Limiter2'

    // Gain: '<S71>/Proportional Gain' incorporates:
    //   Sum: '<S11>/Sum2'

    SITL_HEXA_MISSION_B.ProportionalGain = (rtb_Sum5 -
      SITL_HEXA_MISSION_B.VectorConcatenate[1]) * SITL_HEXA_MISSION_P.MC_PITCH_P;

    // RateLimiter: '<S11>/Rate Limiter1'
    rtb_Sum5 = SITL_HEXA_MISSION_B.Saturation_n[1] -
      SITL_HEXA_MISSION_DW.PrevY_f;
    if (rtb_Sum5 > SITL_HEXA_MISSION_P.RateLimiter1_RisingLim *
        SITL_HEXA_MISSION_period) {
      rtb_Sum5 = SITL_HEXA_MISSION_P.RateLimiter1_RisingLim *
        SITL_HEXA_MISSION_period + SITL_HEXA_MISSION_DW.PrevY_f;
    } else if (rtb_Sum5 < SITL_HEXA_MISSION_P.RateLimiter1_FallingLim *
               SITL_HEXA_MISSION_period) {
      rtb_Sum5 = SITL_HEXA_MISSION_P.RateLimiter1_FallingLim *
        SITL_HEXA_MISSION_period + SITL_HEXA_MISSION_DW.PrevY_f;
    } else {
      rtb_Sum5 = SITL_HEXA_MISSION_B.Saturation_n[1];
    }

    SITL_HEXA_MISSION_DW.PrevY_f = rtb_Sum5;

    // End of RateLimiter: '<S11>/Rate Limiter1'

    // Gain: '<S121>/Proportional Gain' incorporates:
    //   Sum: '<S11>/Sum3'

    SITL_HEXA_MISSION_B.ProportionalGain_a = (rtb_Sum5 -
      SITL_HEXA_MISSION_B.VectorConcatenate[2]) * SITL_HEXA_MISSION_P.MC_ROLL_P;
  }

  // End of Outputs for SubSystem: '<S5>/mc_att_controller'
}

//
// File trailer for generated code.
//
// [EOF]
//
