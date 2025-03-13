//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_Hexacopter_fail.cpp
//
// Code generated for Simulink model 'FLIGHT_Hexacopter_fail'.
//
// Model version                  : 6.19
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Fri Jan 10 13:51:29 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FLIGHT_Hexacopter_fail.h"
#include "FLIGHT_Hexacopter_fail_types.h"
#include "rtwtypes.h"
#include "FLIGHT_Hexacopter_fail_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"

const real_T FLIGHT_Hexacopter_fail_period = 0.01;

// Block signals (default storage)
B_FLIGHT_Hexacopter_fail_T FLIGHT_Hexacopter_fail_B;

// Block states (default storage)
DW_FLIGHT_Hexacopter_fail_T FLIGHT_Hexacopter_fail_DW;

// Real-time model
RT_MODEL_FLIGHT_Hexacopter_fa_T FLIGHT_Hexacopter_fail_M_ =
  RT_MODEL_FLIGHT_Hexacopter_fa_T();
RT_MODEL_FLIGHT_Hexacopter_fa_T *const FLIGHT_Hexacopter_fail_M =
  &FLIGHT_Hexacopter_fail_M_;

// Forward declaration for local functions
static void FLIGHT_Hexacopter_PWM_setupImpl(px4_internal_block_PWM_FLIGHT_T *obj,
  boolean_T armPWM, boolean_T forceFailsafe);
real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = static_cast<real32_T>(atan2(static_cast<real_T>(static_cast<real32_T>
      (tmp)), static_cast<real_T>(static_cast<real32_T>(tmp_0))));
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = static_cast<real32_T>(atan2(static_cast<real_T>(u0), static_cast<real_T>
      (u1)));
  }

  return y;
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if (static_cast<real32_T>(fabs(static_cast<real_T>(u))) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = static_cast<real32_T>(floor(static_cast<real_T>(u + 0.5F)));
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = static_cast<real32_T>(ceil(static_cast<real_T>(u - 0.5F)));
    }
  } else {
    y = u;
  }

  return y;
}

static void FLIGHT_Hexacopter_PWM_setupImpl(px4_internal_block_PWM_FLIGHT_T *obj,
  boolean_T armPWM, boolean_T forceFailsafe)
{
  obj->isMain = true;
  pwm_open(&obj->actuatorAdvertiseObj, &obj->armAdvertiseObj);
  obj->servoCount = 8;
  if (armPWM) {
    pwm_arm(&obj->armAdvertiseObj);
    obj->isArmed = true;
  } else {
    pwm_disarm(&obj->armAdvertiseObj);
    obj->isArmed = false;
  }

  obj->channelMask = 63;
  if (obj->isMain) {
    if (forceFailsafe) {
      pwm_disarm(&obj->armAdvertiseObj);
    } else {
      pwm_arm(&obj->armAdvertiseObj);
    }
  }
}

// Model step function
void FLIGHT_Hexacopter_fail_step(void)
{
  real32_T rtb_DeadZone_h;
  real32_T rtb_DeadZone_i;
  real32_T rtb_FilterCoefficient_d;
  real32_T rtb_FilterCoefficient_g;
  real32_T rtb_Gain2;
  real32_T rtb_IntegralGain;
  real32_T rtb_IntegralGain_a;
  real32_T rtb_Saturation;
  real32_T rtb_Saturation_i;
  real32_T rtb_Saturation_n;
  uint16_T tmp;
  uint16_T tmp_0;
  uint16_T tmp_1;
  uint16_T tmp_2;
  uint16_T tmp_3;
  uint16_T tmp_4;
  int8_T tmp_5;
  int8_T tmp_6;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_e;

  // MATLABSystem: '<S186>/SourceBlock'
  rtb_Compare = uORB_read_step(FLIGHT_Hexacopter_fail_DW.obj_fg.orbMetadataObj,
    &FLIGHT_Hexacopter_fail_DW.obj_fg.eventStructObj,
    &FLIGHT_Hexacopter_fail_B.r2, false, 5000.0);

  // Outputs for Enabled SubSystem: '<S186>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S187>/Enable'

  // Start for MATLABSystem: '<S186>/SourceBlock'
  if (rtb_Compare) {
    // SignalConversion generated from: '<S187>/In1'
    FLIGHT_Hexacopter_fail_B.In1_k = FLIGHT_Hexacopter_fail_B.r2;
  }

  // End of Outputs for SubSystem: '<S186>/Enabled Subsystem'

  // MATLABSystem: '<S178>/SourceBlock'
  rtb_Compare = uORB_read_step(FLIGHT_Hexacopter_fail_DW.obj_e.orbMetadataObj,
    &FLIGHT_Hexacopter_fail_DW.obj_e.eventStructObj, &FLIGHT_Hexacopter_fail_B.r,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S178>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S182>/Enable'

  // Start for MATLABSystem: '<S178>/SourceBlock'
  if (rtb_Compare) {
    // SignalConversion generated from: '<S182>/In1'
    FLIGHT_Hexacopter_fail_B.In1 = FLIGHT_Hexacopter_fail_B.r;
  }

  // End of Outputs for SubSystem: '<S178>/Enabled Subsystem'

  // If: '<Root>/If'
  if (FLIGHT_Hexacopter_fail_B.In1_k.values[5] > 1400) {
    // Outputs for IfAction SubSystem: '<Root>/Altitude_Mode' incorporates:
    //   ActionPort: '<S1>/Action Port'

    // Fcn: '<S11>/Fcn3' incorporates:
    //   DataTypeConversion: '<S11>/Data Type Conversion11'

    FLIGHT_Hexacopter_fail_B.IntegralGain_e = (static_cast<real32_T>
      (FLIGHT_Hexacopter_fail_B.In1_k.values[2]) - 1500.0F) / 500.0F;

    // DeadZone: '<S11>/Dead Zone4'
    if (FLIGHT_Hexacopter_fail_B.IntegralGain_e >
        FLIGHT_Hexacopter_fail_P.DeadZone4_End) {
      rtb_Gain2 = FLIGHT_Hexacopter_fail_B.IntegralGain_e -
        FLIGHT_Hexacopter_fail_P.DeadZone4_End;
    } else if (FLIGHT_Hexacopter_fail_B.IntegralGain_e >=
               FLIGHT_Hexacopter_fail_P.DeadZone4_Start) {
      rtb_Gain2 = 0.0F;
    } else {
      rtb_Gain2 = FLIGHT_Hexacopter_fail_B.IntegralGain_e -
        FLIGHT_Hexacopter_fail_P.DeadZone4_Start;
    }

    // Saturate: '<S11>/Saturation10' incorporates:
    //   DeadZone: '<S11>/Dead Zone4'

    if (rtb_Gain2 > FLIGHT_Hexacopter_fail_P.Saturation10_UpperSat) {
      rtb_Gain2 = FLIGHT_Hexacopter_fail_P.Saturation10_UpperSat;
    } else if (rtb_Gain2 < FLIGHT_Hexacopter_fail_P.Saturation10_LowerSat) {
      rtb_Gain2 = FLIGHT_Hexacopter_fail_P.Saturation10_LowerSat;
    }

    // Gain: '<S12>/Gain' incorporates:
    //   Gain: '<S11>/Gain'
    //   Saturate: '<S11>/Saturation10'
    //   SignalConversion generated from: '<S1>/vel'
    //   Sum: '<S12>/Sum3'

    FLIGHT_Hexacopter_fail_B.IntegralGain_e =
      (FLIGHT_Hexacopter_fail_P.Gain_Gain_fo * rtb_Gain2 -
       FLIGHT_Hexacopter_fail_B.In1.vz) * FLIGHT_Hexacopter_fail_P.Gain_Gain_n1;

    // Gain: '<S52>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S44>/Filter'
    //   Gain: '<S42>/Derivative Gain'
    //   Sum: '<S44>/SumD'

    FLIGHT_Hexacopter_fail_B.FilterCoefficient_i =
      (FLIGHT_Hexacopter_fail_P.Kdvz * FLIGHT_Hexacopter_fail_B.IntegralGain_e -
       FLIGHT_Hexacopter_fail_DW.Filter_DSTATE_b) * FLIGHT_Hexacopter_fail_P.Nvz;

    // Sum: '<S58>/Sum' incorporates:
    //   DiscreteIntegrator: '<S49>/Integrator'
    //   Gain: '<S54>/Proportional Gain'

    FLIGHT_Hexacopter_fail_B.DeadZone_k = (FLIGHT_Hexacopter_fail_P.Kpvz *
      FLIGHT_Hexacopter_fail_B.IntegralGain_e +
      FLIGHT_Hexacopter_fail_DW.Integrator_DSTATE_n) +
      FLIGHT_Hexacopter_fail_B.FilterCoefficient_i;

    // Saturate: '<S56>/Saturation'
    if (FLIGHT_Hexacopter_fail_B.DeadZone_k >
        FLIGHT_Hexacopter_fail_P.PIDController4_UpperSaturationL) {
      rtb_Gain2 = FLIGHT_Hexacopter_fail_P.PIDController4_UpperSaturationL;
    } else if (FLIGHT_Hexacopter_fail_B.DeadZone_k <
               FLIGHT_Hexacopter_fail_P.PIDController4_LowerSaturationL) {
      rtb_Gain2 = FLIGHT_Hexacopter_fail_P.PIDController4_LowerSaturationL;
    } else {
      rtb_Gain2 = FLIGHT_Hexacopter_fail_B.DeadZone_k;
    }

    // Sum: '<S12>/Sum6' incorporates:
    //   Constant: '<S12>/Hovering Thrust'
    //   Saturate: '<S56>/Saturation'

    rtb_Gain2 += FLIGHT_Hexacopter_fail_P.THR_HOVER;

    // Saturate: '<S12>/Saturation1' incorporates:
    //   Merge: '<Root>/Merge1'

    if (rtb_Gain2 > FLIGHT_Hexacopter_fail_P.Saturation1_UpperSat) {
      FLIGHT_Hexacopter_fail_B.Merge1[3] =
        FLIGHT_Hexacopter_fail_P.Saturation1_UpperSat;
    } else if (rtb_Gain2 < FLIGHT_Hexacopter_fail_P.Saturation1_LowerSat) {
      FLIGHT_Hexacopter_fail_B.Merge1[3] =
        FLIGHT_Hexacopter_fail_P.Saturation1_LowerSat;
    } else {
      FLIGHT_Hexacopter_fail_B.Merge1[3] = rtb_Gain2;
    }

    // End of Saturate: '<S12>/Saturation1'

    // DeadZone: '<S41>/DeadZone'
    if (FLIGHT_Hexacopter_fail_B.DeadZone_k >
        FLIGHT_Hexacopter_fail_P.PIDController4_UpperSaturationL) {
      FLIGHT_Hexacopter_fail_B.DeadZone_k -=
        FLIGHT_Hexacopter_fail_P.PIDController4_UpperSaturationL;
    } else if (FLIGHT_Hexacopter_fail_B.DeadZone_k >=
               FLIGHT_Hexacopter_fail_P.PIDController4_LowerSaturationL) {
      FLIGHT_Hexacopter_fail_B.DeadZone_k = 0.0F;
    } else {
      FLIGHT_Hexacopter_fail_B.DeadZone_k -=
        FLIGHT_Hexacopter_fail_P.PIDController4_LowerSaturationL;
    }

    // End of DeadZone: '<S41>/DeadZone'

    // Gain: '<S46>/Integral Gain'
    FLIGHT_Hexacopter_fail_B.IntegralGain_e *= FLIGHT_Hexacopter_fail_P.Kivz;

    // Fcn: '<S11>/Fcn2' incorporates:
    //   DataTypeConversion: '<S11>/Data Type Conversion1'

    rtb_Gain2 = (static_cast<real32_T>(FLIGHT_Hexacopter_fail_B.In1_k.values[0])
                 - 1500.0F) / 500.0F;

    // DeadZone: '<S11>/Dead Zone3'
    if (rtb_Gain2 > FLIGHT_Hexacopter_fail_P.DeadZone3_End) {
      rtb_Gain2 -= FLIGHT_Hexacopter_fail_P.DeadZone3_End;
    } else if (rtb_Gain2 >= FLIGHT_Hexacopter_fail_P.DeadZone3_Start) {
      rtb_Gain2 = 0.0F;
    } else {
      rtb_Gain2 -= FLIGHT_Hexacopter_fail_P.DeadZone3_Start;
    }

    // Saturate: '<S11>/Saturation9' incorporates:
    //   DeadZone: '<S11>/Dead Zone3'

    if (rtb_Gain2 > FLIGHT_Hexacopter_fail_P.Saturation9_UpperSat) {
      rtb_Gain2 = FLIGHT_Hexacopter_fail_P.Saturation9_UpperSat;
    } else if (rtb_Gain2 < FLIGHT_Hexacopter_fail_P.Saturation9_LowerSat) {
      rtb_Gain2 = FLIGHT_Hexacopter_fail_P.Saturation9_LowerSat;
    }

    // SignalConversion generated from: '<S1>/des_roll' incorporates:
    //   Gain: '<S11>/Gain1'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S11>/Saturation9'

    FLIGHT_Hexacopter_fail_B.Merge1[0] =
      FLIGHT_Hexacopter_fail_P.MAX_CONTROL_ANGLE_ROLL * rtb_Gain2;

    // Fcn: '<S11>/Fcn7' incorporates:
    //   DataTypeConversion: '<S11>/Data Type Conversion10'

    rtb_Gain2 = (static_cast<real32_T>(FLIGHT_Hexacopter_fail_B.In1_k.values[3])
                 - 1500.0F) / 500.0F;

    // DeadZone: '<S11>/Dead Zone2'
    if (rtb_Gain2 > FLIGHT_Hexacopter_fail_P.DeadZone2_End) {
      rtb_Gain2 -= FLIGHT_Hexacopter_fail_P.DeadZone2_End;
    } else if (rtb_Gain2 >= FLIGHT_Hexacopter_fail_P.DeadZone2_Start) {
      rtb_Gain2 = 0.0F;
    } else {
      rtb_Gain2 -= FLIGHT_Hexacopter_fail_P.DeadZone2_Start;
    }

    // Saturate: '<S11>/Saturation3' incorporates:
    //   DeadZone: '<S11>/Dead Zone2'

    if (rtb_Gain2 > FLIGHT_Hexacopter_fail_P.Saturation3_UpperSat) {
      rtb_Gain2 = FLIGHT_Hexacopter_fail_P.Saturation3_UpperSat;
    } else if (rtb_Gain2 < FLIGHT_Hexacopter_fail_P.Saturation3_LowerSat) {
      rtb_Gain2 = FLIGHT_Hexacopter_fail_P.Saturation3_LowerSat;
    }

    // SignalConversion generated from: '<S1>/des_r' incorporates:
    //   Gain: '<S11>/Gain3'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S11>/Saturation3'

    FLIGHT_Hexacopter_fail_B.Merge1[2] =
      FLIGHT_Hexacopter_fail_P.MAX_CONTROL_ANGLE_RATE_Y * rtb_Gain2;

    // Fcn: '<S11>/Fcn1' incorporates:
    //   DataTypeConversion: '<S11>/Data Type Conversion2'

    rtb_Gain2 = (static_cast<real32_T>(FLIGHT_Hexacopter_fail_B.In1_k.values[1])
                 - 1500.0F) / 500.0F;

    // DeadZone: '<S11>/Dead Zone1'
    if (rtb_Gain2 > FLIGHT_Hexacopter_fail_P.DeadZone1_End) {
      rtb_Gain2 -= FLIGHT_Hexacopter_fail_P.DeadZone1_End;
    } else if (rtb_Gain2 >= FLIGHT_Hexacopter_fail_P.DeadZone1_Start) {
      rtb_Gain2 = 0.0F;
    } else {
      rtb_Gain2 -= FLIGHT_Hexacopter_fail_P.DeadZone1_Start;
    }

    // Saturate: '<S11>/Saturation1' incorporates:
    //   DeadZone: '<S11>/Dead Zone1'

    if (rtb_Gain2 > FLIGHT_Hexacopter_fail_P.Saturation1_UpperSat_b) {
      rtb_Gain2 = FLIGHT_Hexacopter_fail_P.Saturation1_UpperSat_b;
    } else if (rtb_Gain2 < FLIGHT_Hexacopter_fail_P.Saturation1_LowerSat_d) {
      rtb_Gain2 = FLIGHT_Hexacopter_fail_P.Saturation1_LowerSat_d;
    }

    // SignalConversion generated from: '<S1>/des_pitch' incorporates:
    //   Gain: '<S11>/Gain2'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S11>/Saturation1'

    FLIGHT_Hexacopter_fail_B.Merge1[1] =
      FLIGHT_Hexacopter_fail_P.MAX_CONTROL_ANGLE_PITCH * rtb_Gain2;

    // Switch: '<S39>/Switch1' incorporates:
    //   Constant: '<S39>/Clamping_zero'
    //   Constant: '<S39>/Constant'
    //   Constant: '<S39>/Constant2'
    //   RelationalOperator: '<S39>/fix for DT propagation issue'

    if (FLIGHT_Hexacopter_fail_B.DeadZone_k >
        FLIGHT_Hexacopter_fail_P.Clamping_zero_Value) {
      tmp_5 = FLIGHT_Hexacopter_fail_P.Constant_Value_ej;
    } else {
      tmp_5 = FLIGHT_Hexacopter_fail_P.Constant2_Value_d;
    }

    // Switch: '<S39>/Switch2' incorporates:
    //   Constant: '<S39>/Clamping_zero'
    //   Constant: '<S39>/Constant3'
    //   Constant: '<S39>/Constant4'
    //   RelationalOperator: '<S39>/fix for DT propagation issue1'

    if (FLIGHT_Hexacopter_fail_B.IntegralGain_e >
        FLIGHT_Hexacopter_fail_P.Clamping_zero_Value) {
      tmp_6 = FLIGHT_Hexacopter_fail_P.Constant3_Value_p;
    } else {
      tmp_6 = FLIGHT_Hexacopter_fail_P.Constant4_Value_f;
    }

    // Switch: '<S39>/Switch' incorporates:
    //   Constant: '<S39>/Clamping_zero'
    //   Constant: '<S39>/Constant1'
    //   Logic: '<S39>/AND3'
    //   RelationalOperator: '<S39>/Equal1'
    //   RelationalOperator: '<S39>/Relational Operator'
    //   Switch: '<S39>/Switch1'
    //   Switch: '<S39>/Switch2'

    if ((FLIGHT_Hexacopter_fail_P.Clamping_zero_Value !=
         FLIGHT_Hexacopter_fail_B.DeadZone_k) && (tmp_5 == tmp_6)) {
      FLIGHT_Hexacopter_fail_B.IntegralGain_e =
        FLIGHT_Hexacopter_fail_P.Constant1_Value_f;
    }

    // Update for DiscreteIntegrator: '<S49>/Integrator' incorporates:
    //   Switch: '<S39>/Switch'

    FLIGHT_Hexacopter_fail_DW.Integrator_DSTATE_n +=
      FLIGHT_Hexacopter_fail_P.Integrator_gainval *
      FLIGHT_Hexacopter_fail_B.IntegralGain_e;

    // Update for DiscreteIntegrator: '<S44>/Filter'
    FLIGHT_Hexacopter_fail_DW.Filter_DSTATE_b +=
      FLIGHT_Hexacopter_fail_P.Filter_gainval *
      FLIGHT_Hexacopter_fail_B.FilterCoefficient_i;

    // End of Outputs for SubSystem: '<Root>/Altitude_Mode'
  } else {
    // Outputs for IfAction SubSystem: '<Root>/Stabilized_Mode' incorporates:
    //   ActionPort: '<S9>/Action Port'

    // Gain: '<S9>/Gain' incorporates:
    //   Constant: '<S9>/Constant'
    //   Sum: '<S9>/Sum'

    rtb_Gain2 = static_cast<real32_T>((static_cast<real_T>
      (FLIGHT_Hexacopter_fail_B.In1_k.values[2]) -
      FLIGHT_Hexacopter_fail_P.Constant_Value_a1) *
      FLIGHT_Hexacopter_fail_P.Gain_Gain);

    // Saturate: '<S9>/Saturation' incorporates:
    //   Merge: '<Root>/Merge1'

    if (rtb_Gain2 > FLIGHT_Hexacopter_fail_P.Saturation_UpperSat_k) {
      FLIGHT_Hexacopter_fail_B.Merge1[3] =
        FLIGHT_Hexacopter_fail_P.Saturation_UpperSat_k;
    } else if (rtb_Gain2 < FLIGHT_Hexacopter_fail_P.Saturation_LowerSat_b) {
      FLIGHT_Hexacopter_fail_B.Merge1[3] =
        FLIGHT_Hexacopter_fail_P.Saturation_LowerSat_b;
    } else {
      FLIGHT_Hexacopter_fail_B.Merge1[3] = rtb_Gain2;
    }

    // End of Saturate: '<S9>/Saturation'

    // Gain: '<S9>/Gain2' incorporates:
    //   Constant: '<S9>/Constant1'
    //   Sum: '<S9>/Sum1'

    rtb_Gain2 = (static_cast<real32_T>(FLIGHT_Hexacopter_fail_B.In1_k.values[3])
                 - FLIGHT_Hexacopter_fail_P.Constant1_Value_k) *
      FLIGHT_Hexacopter_fail_P.Gain2_Gain;

    // Saturate: '<S9>/Saturation1' incorporates:
    //   Merge: '<Root>/Merge1'

    if (rtb_Gain2 > FLIGHT_Hexacopter_fail_P.Saturation1_UpperSat_i) {
      FLIGHT_Hexacopter_fail_B.Merge1[2] =
        FLIGHT_Hexacopter_fail_P.Saturation1_UpperSat_i;
    } else if (rtb_Gain2 < FLIGHT_Hexacopter_fail_P.Saturation1_LowerSat_c) {
      FLIGHT_Hexacopter_fail_B.Merge1[2] =
        FLIGHT_Hexacopter_fail_P.Saturation1_LowerSat_c;
    } else {
      FLIGHT_Hexacopter_fail_B.Merge1[2] = rtb_Gain2;
    }

    // End of Saturate: '<S9>/Saturation1'

    // Gain: '<S9>/Gain1' incorporates:
    //   Constant: '<S9>/Constant2'
    //   Sum: '<S9>/Sum2'

    rtb_Gain2 = (static_cast<real32_T>(FLIGHT_Hexacopter_fail_B.In1_k.values[1])
                 - FLIGHT_Hexacopter_fail_P.Constant2_Value_b) *
      FLIGHT_Hexacopter_fail_P.Gain1_Gain;

    // Saturate: '<S9>/Saturation2' incorporates:
    //   Merge: '<Root>/Merge1'

    if (rtb_Gain2 > FLIGHT_Hexacopter_fail_P.Saturation2_UpperSat) {
      FLIGHT_Hexacopter_fail_B.Merge1[1] =
        FLIGHT_Hexacopter_fail_P.Saturation2_UpperSat;
    } else if (rtb_Gain2 < FLIGHT_Hexacopter_fail_P.Saturation2_LowerSat) {
      FLIGHT_Hexacopter_fail_B.Merge1[1] =
        FLIGHT_Hexacopter_fail_P.Saturation2_LowerSat;
    } else {
      FLIGHT_Hexacopter_fail_B.Merge1[1] = rtb_Gain2;
    }

    // End of Saturate: '<S9>/Saturation2'

    // Gain: '<S9>/Gain3' incorporates:
    //   Constant: '<S9>/Constant3'
    //   Sum: '<S9>/Sum3'

    rtb_Gain2 = (static_cast<real32_T>(FLIGHT_Hexacopter_fail_B.In1_k.values[0])
                 - FLIGHT_Hexacopter_fail_P.Constant3_Value_h) *
      FLIGHT_Hexacopter_fail_P.Gain3_Gain;

    // Saturate: '<S9>/Saturation3' incorporates:
    //   Merge: '<Root>/Merge1'

    if (rtb_Gain2 > FLIGHT_Hexacopter_fail_P.Saturation3_UpperSat_e) {
      FLIGHT_Hexacopter_fail_B.Merge1[0] =
        FLIGHT_Hexacopter_fail_P.Saturation3_UpperSat_e;
    } else if (rtb_Gain2 < FLIGHT_Hexacopter_fail_P.Saturation3_LowerSat_n) {
      FLIGHT_Hexacopter_fail_B.Merge1[0] =
        FLIGHT_Hexacopter_fail_P.Saturation3_LowerSat_n;
    } else {
      FLIGHT_Hexacopter_fail_B.Merge1[0] = rtb_Gain2;
    }

    // End of Saturate: '<S9>/Saturation3'
    // End of Outputs for SubSystem: '<Root>/Stabilized_Mode'
  }

  // End of If: '<Root>/If'

  // MATLABSystem: '<S183>/SourceBlock'
  rtb_Compare = uORB_read_step(FLIGHT_Hexacopter_fail_DW.obj_j.orbMetadataObj,
    &FLIGHT_Hexacopter_fail_DW.obj_j.eventStructObj,
    &FLIGHT_Hexacopter_fail_B.r1, false, 1.0);

  // Outputs for Enabled SubSystem: '<S183>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S184>/Enable'

  // Start for MATLABSystem: '<S183>/SourceBlock'
  if (rtb_Compare) {
    // SignalConversion generated from: '<S184>/In1'
    FLIGHT_Hexacopter_fail_B.In1_n = FLIGHT_Hexacopter_fail_B.r1;
  }

  // End of Outputs for SubSystem: '<S183>/Enabled Subsystem'

  // RateLimiter: '<S3>/Rate Limiter1'
  rtb_Gain2 = FLIGHT_Hexacopter_fail_B.Merge1[0] -
    FLIGHT_Hexacopter_fail_DW.PrevY;
  if (rtb_Gain2 > static_cast<real32_T>
      (FLIGHT_Hexacopter_fail_P.RateLimiter1_RisingLim *
       FLIGHT_Hexacopter_fail_period)) {
    FLIGHT_Hexacopter_fail_B.IntegralGain_e = static_cast<real32_T>
      (FLIGHT_Hexacopter_fail_P.RateLimiter1_RisingLim *
       FLIGHT_Hexacopter_fail_period) + FLIGHT_Hexacopter_fail_DW.PrevY;
  } else if (rtb_Gain2 < static_cast<real32_T>
             (FLIGHT_Hexacopter_fail_P.RateLimiter1_FallingLim *
              FLIGHT_Hexacopter_fail_period)) {
    FLIGHT_Hexacopter_fail_B.IntegralGain_e = static_cast<real32_T>
      (FLIGHT_Hexacopter_fail_P.RateLimiter1_FallingLim *
       FLIGHT_Hexacopter_fail_period) + FLIGHT_Hexacopter_fail_DW.PrevY;
  } else {
    FLIGHT_Hexacopter_fail_B.IntegralGain_e = FLIGHT_Hexacopter_fail_B.Merge1[0];
  }

  FLIGHT_Hexacopter_fail_DW.PrevY = FLIGHT_Hexacopter_fail_B.IntegralGain_e;

  // End of RateLimiter: '<S3>/Rate Limiter1'

  // MATLABSystem: '<S180>/SourceBlock'
  rtb_Compare = uORB_read_step(FLIGHT_Hexacopter_fail_DW.obj_no.orbMetadataObj,
    &FLIGHT_Hexacopter_fail_DW.obj_no.eventStructObj,
    &FLIGHT_Hexacopter_fail_B.r3, false, 1.0);

  // Outputs for Enabled SubSystem: '<S180>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S181>/Enable'

  // Start for MATLABSystem: '<S180>/SourceBlock'
  if (rtb_Compare) {
    // SignalConversion generated from: '<S181>/In1'
    FLIGHT_Hexacopter_fail_B.In1_l = FLIGHT_Hexacopter_fail_B.r3;
  }

  // End of Outputs for SubSystem: '<S180>/Enabled Subsystem'

  // Saturate: '<S3>/Saturation'
  if (FLIGHT_Hexacopter_fail_B.IntegralGain_e >
      FLIGHT_Hexacopter_fail_P.MAX_CONTROL_ANGLE_ROLL) {
    FLIGHT_Hexacopter_fail_B.IntegralGain_e =
      FLIGHT_Hexacopter_fail_P.MAX_CONTROL_ANGLE_ROLL;
  } else if (FLIGHT_Hexacopter_fail_B.IntegralGain_e <
             FLIGHT_Hexacopter_fail_P.Saturation_LowerSat_k) {
    FLIGHT_Hexacopter_fail_B.IntegralGain_e =
      FLIGHT_Hexacopter_fail_P.Saturation_LowerSat_k;
  }

  // Gain: '<S157>/Proportional Gain' incorporates:
  //   MATLAB Function: '<Root>/quat2eul'
  //   Saturate: '<S3>/Saturation'
  //   Sum: '<S3>/Sum3'

  rtb_Gain2 = (FLIGHT_Hexacopter_fail_B.IntegralGain_e - rt_atan2f_snf
               ((FLIGHT_Hexacopter_fail_B.In1_n.q[0] *
                 FLIGHT_Hexacopter_fail_B.In1_n.q[1] +
                 FLIGHT_Hexacopter_fail_B.In1_n.q[2] *
                 FLIGHT_Hexacopter_fail_B.In1_n.q[3]) * 2.0F,
                ((FLIGHT_Hexacopter_fail_B.In1_n.q[0] *
                  FLIGHT_Hexacopter_fail_B.In1_n.q[0] -
                  FLIGHT_Hexacopter_fail_B.In1_n.q[1] *
                  FLIGHT_Hexacopter_fail_B.In1_n.q[1]) -
                 FLIGHT_Hexacopter_fail_B.In1_n.q[2] *
                 FLIGHT_Hexacopter_fail_B.In1_n.q[2]) +
                FLIGHT_Hexacopter_fail_B.In1_n.q[3] *
                FLIGHT_Hexacopter_fail_B.In1_n.q[3])) *
    FLIGHT_Hexacopter_fail_P.Kpr;

  // Saturate: '<S159>/Saturation'
  if (rtb_Gain2 > FLIGHT_Hexacopter_fail_P.MAX_CONTROL_ANGLE_RATE_ROLL) {
    rtb_Gain2 = FLIGHT_Hexacopter_fail_P.MAX_CONTROL_ANGLE_RATE_ROLL;
  } else if (rtb_Gain2 <
             FLIGHT_Hexacopter_fail_P.PIDController4_LowerSaturatio_m) {
    rtb_Gain2 = FLIGHT_Hexacopter_fail_P.PIDController4_LowerSaturatio_m;
  }

  // Sum: '<S8>/Sum1' incorporates:
  //   Saturate: '<S159>/Saturation'

  FLIGHT_Hexacopter_fail_B.IntegralGain_e = rtb_Gain2 -
    FLIGHT_Hexacopter_fail_B.In1_l.x;

  // Gain: '<S281>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S273>/Filter'
  //   Gain: '<S271>/Derivative Gain'
  //   Sum: '<S273>/SumD'

  FLIGHT_Hexacopter_fail_B.FilterCoefficient_i = (FLIGHT_Hexacopter_fail_P.Kdrr *
    FLIGHT_Hexacopter_fail_B.IntegralGain_e -
    FLIGHT_Hexacopter_fail_DW.Filter_DSTATE) * FLIGHT_Hexacopter_fail_P.Nrr;

  // Sum: '<S287>/Sum' incorporates:
  //   DiscreteIntegrator: '<S278>/Integrator'
  //   Gain: '<S283>/Proportional Gain'

  FLIGHT_Hexacopter_fail_B.DeadZone_k = (FLIGHT_Hexacopter_fail_P.Kprr *
    FLIGHT_Hexacopter_fail_B.IntegralGain_e +
    FLIGHT_Hexacopter_fail_DW.Integrator_DSTATE) +
    FLIGHT_Hexacopter_fail_B.FilterCoefficient_i;

  // Saturate: '<S285>/Saturation'
  if (FLIGHT_Hexacopter_fail_B.DeadZone_k >
      FLIGHT_Hexacopter_fail_P.PIDController2_UpperSaturationL) {
    rtb_Saturation = FLIGHT_Hexacopter_fail_P.PIDController2_UpperSaturationL;
  } else if (FLIGHT_Hexacopter_fail_B.DeadZone_k <
             FLIGHT_Hexacopter_fail_P.PIDController2_LowerSaturationL) {
    rtb_Saturation = FLIGHT_Hexacopter_fail_P.PIDController2_LowerSaturationL;
  } else {
    rtb_Saturation = FLIGHT_Hexacopter_fail_B.DeadZone_k;
  }

  // End of Saturate: '<S285>/Saturation'

  // RateLimiter: '<S3>/Rate Limiter2'
  rtb_Gain2 = FLIGHT_Hexacopter_fail_B.Merge1[1] -
    FLIGHT_Hexacopter_fail_DW.PrevY_o;
  if (rtb_Gain2 > static_cast<real32_T>
      (FLIGHT_Hexacopter_fail_P.RateLimiter2_RisingLim *
       FLIGHT_Hexacopter_fail_period)) {
    rtb_IntegralGain_a = static_cast<real32_T>
      (FLIGHT_Hexacopter_fail_P.RateLimiter2_RisingLim *
       FLIGHT_Hexacopter_fail_period) + FLIGHT_Hexacopter_fail_DW.PrevY_o;
  } else if (rtb_Gain2 < static_cast<real32_T>
             (FLIGHT_Hexacopter_fail_P.RateLimiter2_FallingLim *
              FLIGHT_Hexacopter_fail_period)) {
    rtb_IntegralGain_a = static_cast<real32_T>
      (FLIGHT_Hexacopter_fail_P.RateLimiter2_FallingLim *
       FLIGHT_Hexacopter_fail_period) + FLIGHT_Hexacopter_fail_DW.PrevY_o;
  } else {
    rtb_IntegralGain_a = FLIGHT_Hexacopter_fail_B.Merge1[1];
  }

  FLIGHT_Hexacopter_fail_DW.PrevY_o = rtb_IntegralGain_a;

  // End of RateLimiter: '<S3>/Rate Limiter2'

  // Saturate: '<S3>/Saturation1'
  if (rtb_IntegralGain_a > FLIGHT_Hexacopter_fail_P.MAX_CONTROL_ANGLE_PITCH) {
    rtb_IntegralGain_a = FLIGHT_Hexacopter_fail_P.MAX_CONTROL_ANGLE_PITCH;
  } else if (rtb_IntegralGain_a <
             FLIGHT_Hexacopter_fail_P.Saturation1_LowerSat_cj) {
    rtb_IntegralGain_a = FLIGHT_Hexacopter_fail_P.Saturation1_LowerSat_cj;
  }

  // Gain: '<S107>/Proportional Gain' incorporates:
  //   MATLAB Function: '<Root>/quat2eul'
  //   Saturate: '<S3>/Saturation1'
  //   Sum: '<S3>/Sum2'

  rtb_Gain2 = (rtb_IntegralGain_a - static_cast<real32_T>(asin(static_cast<
    real_T>((FLIGHT_Hexacopter_fail_B.In1_n.q[1] *
             FLIGHT_Hexacopter_fail_B.In1_n.q[3] -
             FLIGHT_Hexacopter_fail_B.In1_n.q[0] *
             FLIGHT_Hexacopter_fail_B.In1_n.q[2]) * -2.0F)))) *
    FLIGHT_Hexacopter_fail_P.Kpp;

  // Saturate: '<S109>/Saturation'
  if (rtb_Gain2 > FLIGHT_Hexacopter_fail_P.MAX_CONTROL_ANGLE_RATE_PITCH) {
    rtb_Gain2 = FLIGHT_Hexacopter_fail_P.MAX_CONTROL_ANGLE_RATE_PITCH;
  } else if (rtb_Gain2 <
             FLIGHT_Hexacopter_fail_P.PIDController3_LowerSaturationL) {
    rtb_Gain2 = FLIGHT_Hexacopter_fail_P.PIDController3_LowerSaturationL;
  }

  // Sum: '<S8>/Sum' incorporates:
  //   Saturate: '<S109>/Saturation'

  rtb_IntegralGain_a = rtb_Gain2 - FLIGHT_Hexacopter_fail_B.In1_l.y;

  // Gain: '<S229>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S221>/Filter'
  //   Gain: '<S219>/Derivative Gain'
  //   Sum: '<S221>/SumD'

  rtb_FilterCoefficient_d = (FLIGHT_Hexacopter_fail_P.Kdpr * rtb_IntegralGain_a
    - FLIGHT_Hexacopter_fail_DW.Filter_DSTATE_f) * FLIGHT_Hexacopter_fail_P.Npr;

  // Sum: '<S235>/Sum' incorporates:
  //   DiscreteIntegrator: '<S226>/Integrator'
  //   Gain: '<S231>/Proportional Gain'

  rtb_DeadZone_i = (FLIGHT_Hexacopter_fail_P.Kppr * rtb_IntegralGain_a +
                    FLIGHT_Hexacopter_fail_DW.Integrator_DSTATE_g) +
    rtb_FilterCoefficient_d;

  // Saturate: '<S233>/Saturation'
  if (rtb_DeadZone_i > FLIGHT_Hexacopter_fail_P.PIDController1_UpperSaturationL)
  {
    rtb_Saturation_n = FLIGHT_Hexacopter_fail_P.PIDController1_UpperSaturationL;
  } else if (rtb_DeadZone_i <
             FLIGHT_Hexacopter_fail_P.PIDController1_LowerSaturationL) {
    rtb_Saturation_n = FLIGHT_Hexacopter_fail_P.PIDController1_LowerSaturationL;
  } else {
    rtb_Saturation_n = rtb_DeadZone_i;
  }

  // End of Saturate: '<S233>/Saturation'

  // Sum: '<S8>/Sum4'
  rtb_IntegralGain = FLIGHT_Hexacopter_fail_B.Merge1[2] -
    FLIGHT_Hexacopter_fail_B.In1_l.z;

  // Gain: '<S333>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S325>/Filter'
  //   Gain: '<S323>/Derivative Gain'
  //   Sum: '<S325>/SumD'

  rtb_FilterCoefficient_g = (FLIGHT_Hexacopter_fail_P.Kdyr * rtb_IntegralGain -
    FLIGHT_Hexacopter_fail_DW.Filter_DSTATE_n) * FLIGHT_Hexacopter_fail_P.Nyr;

  // Sum: '<S339>/Sum' incorporates:
  //   DiscreteIntegrator: '<S330>/Integrator'
  //   Gain: '<S335>/Proportional Gain'

  rtb_DeadZone_h = (FLIGHT_Hexacopter_fail_P.Kpyr * rtb_IntegralGain +
                    FLIGHT_Hexacopter_fail_DW.Integrator_DSTATE_h) +
    rtb_FilterCoefficient_g;

  // Saturate: '<S337>/Saturation'
  if (rtb_DeadZone_h > FLIGHT_Hexacopter_fail_P.PIDController6_UpperSaturationL)
  {
    rtb_Saturation_i = FLIGHT_Hexacopter_fail_P.PIDController6_UpperSaturationL;
  } else if (rtb_DeadZone_h <
             FLIGHT_Hexacopter_fail_P.PIDController6_LowerSaturationL) {
    rtb_Saturation_i = FLIGHT_Hexacopter_fail_P.PIDController6_LowerSaturationL;
  } else {
    rtb_Saturation_i = rtb_DeadZone_h;
  }

  // End of Saturate: '<S337>/Saturation'

  // MATLAB Function: '<S5>/pwm_out2'
  rtb_Gain2 = rt_roundf_snf(((-rtb_Saturation - rtb_Saturation_i) *
    FLIGHT_Hexacopter_fail_B.Merge1[3] / 3.0F + FLIGHT_Hexacopter_fail_B.Merge1
    [3]) * 1000.0F + 1000.0F);
  if (rtb_Gain2 < 65536.0F) {
    if (rtb_Gain2 >= 0.0F) {
      tmp_4 = static_cast<uint16_T>(rtb_Gain2);
    } else {
      tmp_4 = 0U;
    }
  } else {
    tmp_4 = MAX_uint16_T;
  }

  rtb_Gain2 = rt_roundf_snf(((rtb_Saturation + rtb_Saturation_i) *
    FLIGHT_Hexacopter_fail_B.Merge1[3] / 3.0F + FLIGHT_Hexacopter_fail_B.Merge1
    [3]) * 1000.0F + 1000.0F);
  if (rtb_Gain2 < 65536.0F) {
    if (rtb_Gain2 >= 0.0F) {
      tmp_3 = static_cast<uint16_T>(rtb_Gain2);
    } else {
      tmp_3 = 0U;
    }
  } else {
    tmp_3 = MAX_uint16_T;
  }

  rtb_Gain2 = rt_roundf_snf((((rtb_Saturation / 2.0F + rtb_Saturation_n) -
    rtb_Saturation_i) * FLIGHT_Hexacopter_fail_B.Merge1[3] / 3.0F +
    FLIGHT_Hexacopter_fail_B.Merge1[3]) * 1000.0F + 1000.0F);
  if (rtb_Gain2 < 65536.0F) {
    if (rtb_Gain2 >= 0.0F) {
      tmp_2 = static_cast<uint16_T>(rtb_Gain2);
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint16_T;
  }

  rtb_Gain2 = rt_roundf_snf((((-rtb_Saturation_n - rtb_Saturation / 2.0F) +
    rtb_Saturation_i) * FLIGHT_Hexacopter_fail_B.Merge1[3] / 3.0F +
    FLIGHT_Hexacopter_fail_B.Merge1[3]) * 1000.0F + 1000.0F);
  if (rtb_Gain2 < 65536.0F) {
    if (rtb_Gain2 >= 0.0F) {
      tmp_1 = static_cast<uint16_T>(rtb_Gain2);
    } else {
      tmp_1 = 0U;
    }
  } else {
    tmp_1 = MAX_uint16_T;
  }

  rtb_Gain2 = rt_roundf_snf((((rtb_Saturation_n - rtb_Saturation / 2.0F) +
    rtb_Saturation_i) * FLIGHT_Hexacopter_fail_B.Merge1[3] / 3.0F +
    FLIGHT_Hexacopter_fail_B.Merge1[3]) * 1000.0F + 1000.0F);
  if (rtb_Gain2 < 65536.0F) {
    if (rtb_Gain2 >= 0.0F) {
      tmp_0 = static_cast<uint16_T>(rtb_Gain2);
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  rtb_Gain2 = rt_roundf_snf((((rtb_Saturation / 2.0F - rtb_Saturation_n) -
    rtb_Saturation_i) * FLIGHT_Hexacopter_fail_B.Merge1[3] / 3.0F +
    FLIGHT_Hexacopter_fail_B.Merge1[3]) * 1000.0F + 1000.0F);
  if (rtb_Gain2 < 65536.0F) {
    if (rtb_Gain2 >= 0.0F) {
      tmp = static_cast<uint16_T>(rtb_Gain2);
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint16_T;
  }

  // End of MATLAB Function: '<S5>/pwm_out2'

  // MATLABSystem: '<S4>/Read Parameter13'
  if (FLIGHT_Hexacopter_fail_DW.obj_k.SampleTime !=
      FLIGHT_Hexacopter_fail_P.ReadParameter13_SampleTime) {
    FLIGHT_Hexacopter_fail_DW.obj_k.SampleTime =
      FLIGHT_Hexacopter_fail_P.ReadParameter13_SampleTime;
  }

  rtb_Compare = MW_Param_Step(FLIGHT_Hexacopter_fail_DW.obj_k.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_Hexacopter_fail_B.ParamStep);
  if (rtb_Compare) {
    FLIGHT_Hexacopter_fail_B.ParamStep = 0;
  }

  // RelationalOperator: '<S169>/Compare' incorporates:
  //   Constant: '<S169>/Constant'

  rtb_Compare_e = (FLIGHT_Hexacopter_fail_B.In1_k.values[7] >=
                   FLIGHT_Hexacopter_fail_P.CompareToConstant_const);

  // MATLABSystem: '<S4>/Read Parameter1'
  if (FLIGHT_Hexacopter_fail_DW.obj_fo.SampleTime !=
      FLIGHT_Hexacopter_fail_P.ReadParameter1_SampleTime) {
    FLIGHT_Hexacopter_fail_DW.obj_fo.SampleTime =
      FLIGHT_Hexacopter_fail_P.ReadParameter1_SampleTime;
  }

  rtb_Compare = MW_Param_Step(FLIGHT_Hexacopter_fail_DW.obj_fo.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_Hexacopter_fail_B.ParamStep_m);
  if (rtb_Compare) {
    FLIGHT_Hexacopter_fail_B.ParamStep_m = 0;
  }

  // MATLABSystem: '<S4>/Read Parameter2'
  if (FLIGHT_Hexacopter_fail_DW.obj_b.SampleTime !=
      FLIGHT_Hexacopter_fail_P.ReadParameter2_SampleTime) {
    FLIGHT_Hexacopter_fail_DW.obj_b.SampleTime =
      FLIGHT_Hexacopter_fail_P.ReadParameter2_SampleTime;
  }

  rtb_Compare = MW_Param_Step(FLIGHT_Hexacopter_fail_DW.obj_b.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_Hexacopter_fail_B.ParamStep_c);
  if (rtb_Compare) {
    FLIGHT_Hexacopter_fail_B.ParamStep_c = 0;
  }

  // MATLABSystem: '<S4>/Read Parameter3'
  if (FLIGHT_Hexacopter_fail_DW.obj_n.SampleTime !=
      FLIGHT_Hexacopter_fail_P.ReadParameter3_SampleTime) {
    FLIGHT_Hexacopter_fail_DW.obj_n.SampleTime =
      FLIGHT_Hexacopter_fail_P.ReadParameter3_SampleTime;
  }

  rtb_Compare = MW_Param_Step(FLIGHT_Hexacopter_fail_DW.obj_n.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_Hexacopter_fail_B.ParamStep_k);
  if (rtb_Compare) {
    FLIGHT_Hexacopter_fail_B.ParamStep_k = 0;
  }

  // MATLABSystem: '<S4>/Read Parameter4'
  if (FLIGHT_Hexacopter_fail_DW.obj_f.SampleTime !=
      FLIGHT_Hexacopter_fail_P.ReadParameter4_SampleTime) {
    FLIGHT_Hexacopter_fail_DW.obj_f.SampleTime =
      FLIGHT_Hexacopter_fail_P.ReadParameter4_SampleTime;
  }

  rtb_Compare = MW_Param_Step(FLIGHT_Hexacopter_fail_DW.obj_f.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_Hexacopter_fail_B.ParamStep_cx);
  if (rtb_Compare) {
    FLIGHT_Hexacopter_fail_B.ParamStep_cx = 0;
  }

  // MATLABSystem: '<S4>/Read Parameter5'
  if (FLIGHT_Hexacopter_fail_DW.obj.SampleTime !=
      FLIGHT_Hexacopter_fail_P.ReadParameter5_SampleTime) {
    FLIGHT_Hexacopter_fail_DW.obj.SampleTime =
      FLIGHT_Hexacopter_fail_P.ReadParameter5_SampleTime;
  }

  rtb_Compare = MW_Param_Step(FLIGHT_Hexacopter_fail_DW.obj.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_Hexacopter_fail_B.ParamStep_b);
  if (rtb_Compare) {
    FLIGHT_Hexacopter_fail_B.ParamStep_b = 0;
  }

  // Switch: '<S4>/Switch' incorporates:
  //   Constant: '<S4>/Constant'
  //   DataTypeConversion: '<S4>/Data Type Conversion3'
  //   MATLABSystem: '<S4>/Read Parameter13'
  //
  if (rtb_Compare_e) {
    FLIGHT_Hexacopter_fail_B.d = FLIGHT_Hexacopter_fail_B.ParamStep;
  } else {
    FLIGHT_Hexacopter_fail_B.d = FLIGHT_Hexacopter_fail_P.Constant_Value_c;
  }

  // Gain: '<S170>/Gain' incorporates:
  //   Switch: '<S4>/Switch'

  FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Gain_Gain_k *
    FLIGHT_Hexacopter_fail_B.d;

  // Saturate: '<S5>/Output_Limits1'
  if (tmp_4 > FLIGHT_Hexacopter_fail_P.Output_Limits1_UpperSat) {
    tmp_4 = FLIGHT_Hexacopter_fail_P.Output_Limits1_UpperSat;
  } else if (tmp_4 < FLIGHT_Hexacopter_fail_P.Output_Limits1_LowerSat) {
    tmp_4 = FLIGHT_Hexacopter_fail_P.Output_Limits1_LowerSat;
  }

  // Saturate: '<S170>/Saturation'
  if (FLIGHT_Hexacopter_fail_B.u0 > FLIGHT_Hexacopter_fail_P.Saturation_UpperSat)
  {
    FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Saturation_UpperSat;
  } else if (FLIGHT_Hexacopter_fail_B.u0 <
             FLIGHT_Hexacopter_fail_P.Saturation_LowerSat) {
    FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Saturation_LowerSat;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S170>/Constant'
  //   DataTypeConversion: '<S4>/Data Type Conversion6'
  //   Product: '<S170>/Product'
  //   Saturate: '<S170>/Saturation'
  //   Saturate: '<S5>/Output_Limits1'
  //   Sum: '<S170>/Sum'
  //   Sum: '<S170>/Sum1'

  FLIGHT_Hexacopter_fail_B.d = floor((static_cast<real_T>(tmp_4) -
    FLIGHT_Hexacopter_fail_P.Constant_Value_n) * FLIGHT_Hexacopter_fail_B.u0 +
    FLIGHT_Hexacopter_fail_P.Constant_Value_n);
  if (rtIsNaN(FLIGHT_Hexacopter_fail_B.d) || rtIsInf(FLIGHT_Hexacopter_fail_B.d))
  {
    FLIGHT_Hexacopter_fail_B.d = 0.0;
  } else {
    FLIGHT_Hexacopter_fail_B.d = fmod(FLIGHT_Hexacopter_fail_B.d, 65536.0);
  }

  // Switch: '<S4>/Switch1' incorporates:
  //   Constant: '<S4>/Constant1'
  //   DataTypeConversion: '<S4>/Data Type Conversion2'
  //   MATLABSystem: '<S4>/Read Parameter1'
  //
  if (rtb_Compare_e) {
    FLIGHT_Hexacopter_fail_B.d1 = FLIGHT_Hexacopter_fail_B.ParamStep_m;
  } else {
    FLIGHT_Hexacopter_fail_B.d1 = FLIGHT_Hexacopter_fail_P.Constant1_Value;
  }

  // Gain: '<S171>/Gain' incorporates:
  //   Switch: '<S4>/Switch1'

  FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Gain_Gain_h *
    FLIGHT_Hexacopter_fail_B.d1;

  // Saturate: '<S5>/Output_Limits1'
  if (tmp_3 > FLIGHT_Hexacopter_fail_P.Output_Limits1_UpperSat) {
    tmp_3 = FLIGHT_Hexacopter_fail_P.Output_Limits1_UpperSat;
  } else if (tmp_3 < FLIGHT_Hexacopter_fail_P.Output_Limits1_LowerSat) {
    tmp_3 = FLIGHT_Hexacopter_fail_P.Output_Limits1_LowerSat;
  }

  // Saturate: '<S171>/Saturation'
  if (FLIGHT_Hexacopter_fail_B.u0 >
      FLIGHT_Hexacopter_fail_P.Saturation_UpperSat_l) {
    FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Saturation_UpperSat_l;
  } else if (FLIGHT_Hexacopter_fail_B.u0 <
             FLIGHT_Hexacopter_fail_P.Saturation_LowerSat_h) {
    FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Saturation_LowerSat_h;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S171>/Constant'
  //   DataTypeConversion: '<S4>/Data Type Conversion6'
  //   Product: '<S171>/Product'
  //   Saturate: '<S171>/Saturation'
  //   Saturate: '<S5>/Output_Limits1'
  //   Sum: '<S171>/Sum'
  //   Sum: '<S171>/Sum1'

  FLIGHT_Hexacopter_fail_B.d1 = floor((static_cast<real_T>(tmp_3) -
    FLIGHT_Hexacopter_fail_P.Constant_Value_i) * FLIGHT_Hexacopter_fail_B.u0 +
    FLIGHT_Hexacopter_fail_P.Constant_Value_i);
  if (rtIsNaN(FLIGHT_Hexacopter_fail_B.d1) || rtIsInf
      (FLIGHT_Hexacopter_fail_B.d1)) {
    FLIGHT_Hexacopter_fail_B.d1 = 0.0;
  } else {
    FLIGHT_Hexacopter_fail_B.d1 = fmod(FLIGHT_Hexacopter_fail_B.d1, 65536.0);
  }

  // Switch: '<S4>/Switch2' incorporates:
  //   Constant: '<S4>/Constant2'
  //   DataTypeConversion: '<S4>/Data Type Conversion'
  //   MATLABSystem: '<S4>/Read Parameter2'
  //
  if (rtb_Compare_e) {
    FLIGHT_Hexacopter_fail_B.d2 = FLIGHT_Hexacopter_fail_B.ParamStep_c;
  } else {
    FLIGHT_Hexacopter_fail_B.d2 = FLIGHT_Hexacopter_fail_P.Constant2_Value;
  }

  // Gain: '<S172>/Gain' incorporates:
  //   Switch: '<S4>/Switch2'

  FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Gain_Gain_n *
    FLIGHT_Hexacopter_fail_B.d2;

  // Saturate: '<S5>/Output_Limits1'
  if (tmp_2 > FLIGHT_Hexacopter_fail_P.Output_Limits1_UpperSat) {
    tmp_2 = FLIGHT_Hexacopter_fail_P.Output_Limits1_UpperSat;
  } else if (tmp_2 < FLIGHT_Hexacopter_fail_P.Output_Limits1_LowerSat) {
    tmp_2 = FLIGHT_Hexacopter_fail_P.Output_Limits1_LowerSat;
  }

  // Saturate: '<S172>/Saturation'
  if (FLIGHT_Hexacopter_fail_B.u0 >
      FLIGHT_Hexacopter_fail_P.Saturation_UpperSat_d) {
    FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Saturation_UpperSat_d;
  } else if (FLIGHT_Hexacopter_fail_B.u0 <
             FLIGHT_Hexacopter_fail_P.Saturation_LowerSat_c) {
    FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Saturation_LowerSat_c;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S172>/Constant'
  //   DataTypeConversion: '<S4>/Data Type Conversion6'
  //   Product: '<S172>/Product'
  //   Saturate: '<S172>/Saturation'
  //   Saturate: '<S5>/Output_Limits1'
  //   Sum: '<S172>/Sum'
  //   Sum: '<S172>/Sum1'

  FLIGHT_Hexacopter_fail_B.d2 = floor((static_cast<real_T>(tmp_2) -
    FLIGHT_Hexacopter_fail_P.Constant_Value_p) * FLIGHT_Hexacopter_fail_B.u0 +
    FLIGHT_Hexacopter_fail_P.Constant_Value_p);
  if (rtIsNaN(FLIGHT_Hexacopter_fail_B.d2) || rtIsInf
      (FLIGHT_Hexacopter_fail_B.d2)) {
    FLIGHT_Hexacopter_fail_B.d2 = 0.0;
  } else {
    FLIGHT_Hexacopter_fail_B.d2 = fmod(FLIGHT_Hexacopter_fail_B.d2, 65536.0);
  }

  // Switch: '<S4>/Switch3' incorporates:
  //   Constant: '<S4>/Constant3'
  //   DataTypeConversion: '<S4>/Data Type Conversion4'
  //   MATLABSystem: '<S4>/Read Parameter3'
  //
  if (rtb_Compare_e) {
    FLIGHT_Hexacopter_fail_B.d3 = FLIGHT_Hexacopter_fail_B.ParamStep_k;
  } else {
    FLIGHT_Hexacopter_fail_B.d3 = FLIGHT_Hexacopter_fail_P.Constant3_Value;
  }

  // Gain: '<S173>/Gain' incorporates:
  //   Switch: '<S4>/Switch3'

  FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Gain_Gain_f *
    FLIGHT_Hexacopter_fail_B.d3;

  // Saturate: '<S5>/Output_Limits1'
  if (tmp_1 > FLIGHT_Hexacopter_fail_P.Output_Limits1_UpperSat) {
    tmp_1 = FLIGHT_Hexacopter_fail_P.Output_Limits1_UpperSat;
  } else if (tmp_1 < FLIGHT_Hexacopter_fail_P.Output_Limits1_LowerSat) {
    tmp_1 = FLIGHT_Hexacopter_fail_P.Output_Limits1_LowerSat;
  }

  // Saturate: '<S173>/Saturation'
  if (FLIGHT_Hexacopter_fail_B.u0 >
      FLIGHT_Hexacopter_fail_P.Saturation_UpperSat_lk) {
    FLIGHT_Hexacopter_fail_B.u0 =
      FLIGHT_Hexacopter_fail_P.Saturation_UpperSat_lk;
  } else if (FLIGHT_Hexacopter_fail_B.u0 <
             FLIGHT_Hexacopter_fail_P.Saturation_LowerSat_l) {
    FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Saturation_LowerSat_l;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S173>/Constant'
  //   DataTypeConversion: '<S4>/Data Type Conversion6'
  //   Product: '<S173>/Product'
  //   Saturate: '<S173>/Saturation'
  //   Saturate: '<S5>/Output_Limits1'
  //   Sum: '<S173>/Sum'
  //   Sum: '<S173>/Sum1'

  FLIGHT_Hexacopter_fail_B.d3 = floor((static_cast<real_T>(tmp_1) -
    FLIGHT_Hexacopter_fail_P.Constant_Value_e) * FLIGHT_Hexacopter_fail_B.u0 +
    FLIGHT_Hexacopter_fail_P.Constant_Value_e);
  if (rtIsNaN(FLIGHT_Hexacopter_fail_B.d3) || rtIsInf
      (FLIGHT_Hexacopter_fail_B.d3)) {
    FLIGHT_Hexacopter_fail_B.d3 = 0.0;
  } else {
    FLIGHT_Hexacopter_fail_B.d3 = fmod(FLIGHT_Hexacopter_fail_B.d3, 65536.0);
  }

  // Switch: '<S4>/Switch4' incorporates:
  //   Constant: '<S4>/Constant4'
  //   DataTypeConversion: '<S4>/Data Type Conversion1'
  //   MATLABSystem: '<S4>/Read Parameter4'
  //
  if (rtb_Compare_e) {
    FLIGHT_Hexacopter_fail_B.d4 = FLIGHT_Hexacopter_fail_B.ParamStep_cx;
  } else {
    FLIGHT_Hexacopter_fail_B.d4 = FLIGHT_Hexacopter_fail_P.Constant4_Value;
  }

  // Gain: '<S174>/Gain' incorporates:
  //   Switch: '<S4>/Switch4'

  FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Gain_Gain_b *
    FLIGHT_Hexacopter_fail_B.d4;

  // Saturate: '<S5>/Output_Limits1'
  if (tmp_0 > FLIGHT_Hexacopter_fail_P.Output_Limits1_UpperSat) {
    tmp_0 = FLIGHT_Hexacopter_fail_P.Output_Limits1_UpperSat;
  } else if (tmp_0 < FLIGHT_Hexacopter_fail_P.Output_Limits1_LowerSat) {
    tmp_0 = FLIGHT_Hexacopter_fail_P.Output_Limits1_LowerSat;
  }

  // Saturate: '<S174>/Saturation'
  if (FLIGHT_Hexacopter_fail_B.u0 >
      FLIGHT_Hexacopter_fail_P.Saturation_UpperSat_o) {
    FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Saturation_UpperSat_o;
  } else if (FLIGHT_Hexacopter_fail_B.u0 <
             FLIGHT_Hexacopter_fail_P.Saturation_LowerSat_o) {
    FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Saturation_LowerSat_o;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S174>/Constant'
  //   DataTypeConversion: '<S4>/Data Type Conversion6'
  //   Product: '<S174>/Product'
  //   Saturate: '<S174>/Saturation'
  //   Saturate: '<S5>/Output_Limits1'
  //   Sum: '<S174>/Sum'
  //   Sum: '<S174>/Sum1'

  FLIGHT_Hexacopter_fail_B.d4 = floor((static_cast<real_T>(tmp_0) -
    FLIGHT_Hexacopter_fail_P.Constant_Value_jb) * FLIGHT_Hexacopter_fail_B.u0 +
    FLIGHT_Hexacopter_fail_P.Constant_Value_jb);
  if (rtIsNaN(FLIGHT_Hexacopter_fail_B.d4) || rtIsInf
      (FLIGHT_Hexacopter_fail_B.d4)) {
    FLIGHT_Hexacopter_fail_B.d4 = 0.0;
  } else {
    FLIGHT_Hexacopter_fail_B.d4 = fmod(FLIGHT_Hexacopter_fail_B.d4, 65536.0);
  }

  // Switch: '<S4>/Switch5' incorporates:
  //   Constant: '<S4>/Constant5'
  //   DataTypeConversion: '<S4>/Data Type Conversion5'
  //   MATLABSystem: '<S4>/Read Parameter5'
  //
  if (rtb_Compare_e) {
    FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_B.ParamStep_b;
  } else {
    FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Constant5_Value;
  }

  // Gain: '<S175>/Gain' incorporates:
  //   Switch: '<S4>/Switch5'

  FLIGHT_Hexacopter_fail_B.u0 *= FLIGHT_Hexacopter_fail_P.Gain_Gain_o;

  // Saturate: '<S5>/Output_Limits1'
  if (tmp > FLIGHT_Hexacopter_fail_P.Output_Limits1_UpperSat) {
    tmp = FLIGHT_Hexacopter_fail_P.Output_Limits1_UpperSat;
  } else if (tmp < FLIGHT_Hexacopter_fail_P.Output_Limits1_LowerSat) {
    tmp = FLIGHT_Hexacopter_fail_P.Output_Limits1_LowerSat;
  }

  // Saturate: '<S175>/Saturation'
  if (FLIGHT_Hexacopter_fail_B.u0 >
      FLIGHT_Hexacopter_fail_P.Saturation_UpperSat_m) {
    FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Saturation_UpperSat_m;
  } else if (FLIGHT_Hexacopter_fail_B.u0 <
             FLIGHT_Hexacopter_fail_P.Saturation_LowerSat_m) {
    FLIGHT_Hexacopter_fail_B.u0 = FLIGHT_Hexacopter_fail_P.Saturation_LowerSat_m;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S175>/Constant'
  //   DataTypeConversion: '<S4>/Data Type Conversion6'
  //   Product: '<S175>/Product'
  //   Saturate: '<S175>/Saturation'
  //   Saturate: '<S5>/Output_Limits1'
  //   Sum: '<S175>/Sum'
  //   Sum: '<S175>/Sum1'

  FLIGHT_Hexacopter_fail_B.u0 = floor((static_cast<real_T>(tmp) -
    FLIGHT_Hexacopter_fail_P.Constant_Value_ef) * FLIGHT_Hexacopter_fail_B.u0 +
    FLIGHT_Hexacopter_fail_P.Constant_Value_ef);
  if (rtIsNaN(FLIGHT_Hexacopter_fail_B.u0) || rtIsInf
      (FLIGHT_Hexacopter_fail_B.u0)) {
    FLIGHT_Hexacopter_fail_B.u0 = 0.0;
  } else {
    FLIGHT_Hexacopter_fail_B.u0 = fmod(FLIGHT_Hexacopter_fail_B.u0, 65536.0);
  }

  // RelationalOperator: '<S66>/Compare' incorporates:
  //   Constant: '<S66>/Constant'

  rtb_Compare = (FLIGHT_Hexacopter_fail_B.In1_k.values[4] >=
                 FLIGHT_Hexacopter_fail_P.CompareToConstant3_const);

  // MATLABSystem: '<Root>/PX4 PWM Output' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion7'
  //   Logic: '<Root>/NOT'

  for (FLIGHT_Hexacopter_fail_B.ParamStep = 0;
       FLIGHT_Hexacopter_fail_B.ParamStep < 8;
       FLIGHT_Hexacopter_fail_B.ParamStep++) {
    FLIGHT_Hexacopter_fail_B.pwmValue[FLIGHT_Hexacopter_fail_B.ParamStep] = 0U;
  }

  FLIGHT_Hexacopter_fail_B.pwmValue[0] = static_cast<uint16_T>
    (FLIGHT_Hexacopter_fail_B.d < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_Hexacopter_fail_B.d)))) : static_cast<int32_T>
     (static_cast<uint16_T>(FLIGHT_Hexacopter_fail_B.d)));
  FLIGHT_Hexacopter_fail_B.pwmValue[1] = static_cast<uint16_T>
    (FLIGHT_Hexacopter_fail_B.d1 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_Hexacopter_fail_B.d1)))) : static_cast<int32_T>
     (static_cast<uint16_T>(FLIGHT_Hexacopter_fail_B.d1)));
  FLIGHT_Hexacopter_fail_B.pwmValue[2] = static_cast<uint16_T>
    (FLIGHT_Hexacopter_fail_B.d2 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_Hexacopter_fail_B.d2)))) : static_cast<int32_T>
     (static_cast<uint16_T>(FLIGHT_Hexacopter_fail_B.d2)));
  FLIGHT_Hexacopter_fail_B.pwmValue[3] = static_cast<uint16_T>
    (FLIGHT_Hexacopter_fail_B.d3 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_Hexacopter_fail_B.d3)))) : static_cast<int32_T>
     (static_cast<uint16_T>(FLIGHT_Hexacopter_fail_B.d3)));
  FLIGHT_Hexacopter_fail_B.pwmValue[4] = static_cast<uint16_T>
    (FLIGHT_Hexacopter_fail_B.d4 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_Hexacopter_fail_B.d4)))) : static_cast<int32_T>
     (static_cast<uint16_T>(FLIGHT_Hexacopter_fail_B.d4)));
  FLIGHT_Hexacopter_fail_B.pwmValue[5] = static_cast<uint16_T>
    (FLIGHT_Hexacopter_fail_B.u0 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_Hexacopter_fail_B.u0)))) : static_cast<int32_T>
     (static_cast<uint16_T>(FLIGHT_Hexacopter_fail_B.u0)));
  if (rtb_Compare) {
    if (!FLIGHT_Hexacopter_fail_DW.obj_nt.isArmed) {
      FLIGHT_Hexacopter_fail_DW.obj_nt.isArmed = true;
      pwm_arm(&FLIGHT_Hexacopter_fail_DW.obj_nt.armAdvertiseObj);
    }

    pwm_setServo(FLIGHT_Hexacopter_fail_DW.obj_nt.servoCount,
                 FLIGHT_Hexacopter_fail_DW.obj_nt.channelMask,
                 &FLIGHT_Hexacopter_fail_B.pwmValue[0],
                 FLIGHT_Hexacopter_fail_DW.obj_nt.isMain,
                 &FLIGHT_Hexacopter_fail_DW.obj_nt.actuatorAdvertiseObj);
  } else {
    pwm_disarm(&FLIGHT_Hexacopter_fail_DW.obj_nt.armAdvertiseObj);
    FLIGHT_Hexacopter_fail_DW.obj_nt.isArmed = false;
    pwm_resetServo(FLIGHT_Hexacopter_fail_DW.obj_nt.servoCount,
                   FLIGHT_Hexacopter_fail_DW.obj_nt.isMain,
                   &FLIGHT_Hexacopter_fail_DW.obj_nt.actuatorAdvertiseObj);
  }

  if (FLIGHT_Hexacopter_fail_DW.obj_nt.isMain) {
    if (!rtb_Compare) {
      pwm_disarm(&FLIGHT_Hexacopter_fail_DW.obj_nt.armAdvertiseObj);
    } else {
      pwm_arm(&FLIGHT_Hexacopter_fail_DW.obj_nt.armAdvertiseObj);
    }
  }

  // End of MATLABSystem: '<Root>/PX4 PWM Output'

  // DeadZone: '<S322>/DeadZone'
  if (rtb_DeadZone_h > FLIGHT_Hexacopter_fail_P.PIDController6_UpperSaturationL)
  {
    rtb_DeadZone_h -= FLIGHT_Hexacopter_fail_P.PIDController6_UpperSaturationL;
  } else if (rtb_DeadZone_h >=
             FLIGHT_Hexacopter_fail_P.PIDController6_LowerSaturationL) {
    rtb_DeadZone_h = 0.0F;
  } else {
    rtb_DeadZone_h -= FLIGHT_Hexacopter_fail_P.PIDController6_LowerSaturationL;
  }

  // End of DeadZone: '<S322>/DeadZone'

  // Gain: '<S327>/Integral Gain'
  rtb_IntegralGain *= FLIGHT_Hexacopter_fail_P.Kiyr;

  // DeadZone: '<S218>/DeadZone'
  if (rtb_DeadZone_i > FLIGHT_Hexacopter_fail_P.PIDController1_UpperSaturationL)
  {
    rtb_DeadZone_i -= FLIGHT_Hexacopter_fail_P.PIDController1_UpperSaturationL;
  } else if (rtb_DeadZone_i >=
             FLIGHT_Hexacopter_fail_P.PIDController1_LowerSaturationL) {
    rtb_DeadZone_i = 0.0F;
  } else {
    rtb_DeadZone_i -= FLIGHT_Hexacopter_fail_P.PIDController1_LowerSaturationL;
  }

  // End of DeadZone: '<S218>/DeadZone'

  // Gain: '<S223>/Integral Gain'
  rtb_IntegralGain_a *= FLIGHT_Hexacopter_fail_P.Kipr;

  // DeadZone: '<S270>/DeadZone'
  if (FLIGHT_Hexacopter_fail_B.DeadZone_k >
      FLIGHT_Hexacopter_fail_P.PIDController2_UpperSaturationL) {
    FLIGHT_Hexacopter_fail_B.DeadZone_k -=
      FLIGHT_Hexacopter_fail_P.PIDController2_UpperSaturationL;
  } else if (FLIGHT_Hexacopter_fail_B.DeadZone_k >=
             FLIGHT_Hexacopter_fail_P.PIDController2_LowerSaturationL) {
    FLIGHT_Hexacopter_fail_B.DeadZone_k = 0.0F;
  } else {
    FLIGHT_Hexacopter_fail_B.DeadZone_k -=
      FLIGHT_Hexacopter_fail_P.PIDController2_LowerSaturationL;
  }

  // End of DeadZone: '<S270>/DeadZone'

  // Gain: '<S275>/Integral Gain'
  FLIGHT_Hexacopter_fail_B.IntegralGain_e *= FLIGHT_Hexacopter_fail_P.Kirr;

  // Switch: '<S268>/Switch1' incorporates:
  //   Constant: '<S268>/Clamping_zero'
  //   Constant: '<S268>/Constant'
  //   Constant: '<S268>/Constant2'
  //   RelationalOperator: '<S268>/fix for DT propagation issue'

  if (FLIGHT_Hexacopter_fail_B.DeadZone_k >
      FLIGHT_Hexacopter_fail_P.Clamping_zero_Value_d) {
    tmp_5 = FLIGHT_Hexacopter_fail_P.Constant_Value_h;
  } else {
    tmp_5 = FLIGHT_Hexacopter_fail_P.Constant2_Value_g;
  }

  // Switch: '<S268>/Switch2' incorporates:
  //   Constant: '<S268>/Clamping_zero'
  //   Constant: '<S268>/Constant3'
  //   Constant: '<S268>/Constant4'
  //   RelationalOperator: '<S268>/fix for DT propagation issue1'

  if (FLIGHT_Hexacopter_fail_B.IntegralGain_e >
      FLIGHT_Hexacopter_fail_P.Clamping_zero_Value_d) {
    tmp_6 = FLIGHT_Hexacopter_fail_P.Constant3_Value_l;
  } else {
    tmp_6 = FLIGHT_Hexacopter_fail_P.Constant4_Value_n;
  }

  // Switch: '<S268>/Switch' incorporates:
  //   Constant: '<S268>/Clamping_zero'
  //   Constant: '<S268>/Constant1'
  //   Logic: '<S268>/AND3'
  //   RelationalOperator: '<S268>/Equal1'
  //   RelationalOperator: '<S268>/Relational Operator'
  //   Switch: '<S268>/Switch1'
  //   Switch: '<S268>/Switch2'

  if ((FLIGHT_Hexacopter_fail_P.Clamping_zero_Value_d !=
       FLIGHT_Hexacopter_fail_B.DeadZone_k) && (tmp_5 == tmp_6)) {
    FLIGHT_Hexacopter_fail_B.IntegralGain_e =
      FLIGHT_Hexacopter_fail_P.Constant1_Value_o;
  }

  // Update for DiscreteIntegrator: '<S278>/Integrator' incorporates:
  //   Switch: '<S268>/Switch'

  FLIGHT_Hexacopter_fail_DW.Integrator_DSTATE +=
    FLIGHT_Hexacopter_fail_P.Integrator_gainval_h *
    FLIGHT_Hexacopter_fail_B.IntegralGain_e;

  // Update for DiscreteIntegrator: '<S273>/Filter'
  FLIGHT_Hexacopter_fail_DW.Filter_DSTATE +=
    FLIGHT_Hexacopter_fail_P.Filter_gainval_o *
    FLIGHT_Hexacopter_fail_B.FilterCoefficient_i;

  // Switch: '<S216>/Switch1' incorporates:
  //   Constant: '<S216>/Clamping_zero'
  //   Constant: '<S216>/Constant'
  //   Constant: '<S216>/Constant2'
  //   RelationalOperator: '<S216>/fix for DT propagation issue'

  if (rtb_DeadZone_i > FLIGHT_Hexacopter_fail_P.Clamping_zero_Value_j) {
    tmp_5 = FLIGHT_Hexacopter_fail_P.Constant_Value_d;
  } else {
    tmp_5 = FLIGHT_Hexacopter_fail_P.Constant2_Value_h;
  }

  // Switch: '<S216>/Switch2' incorporates:
  //   Constant: '<S216>/Clamping_zero'
  //   Constant: '<S216>/Constant3'
  //   Constant: '<S216>/Constant4'
  //   RelationalOperator: '<S216>/fix for DT propagation issue1'

  if (rtb_IntegralGain_a > FLIGHT_Hexacopter_fail_P.Clamping_zero_Value_j) {
    tmp_6 = FLIGHT_Hexacopter_fail_P.Constant3_Value_f;
  } else {
    tmp_6 = FLIGHT_Hexacopter_fail_P.Constant4_Value_b;
  }

  // Switch: '<S216>/Switch' incorporates:
  //   Constant: '<S216>/Clamping_zero'
  //   Constant: '<S216>/Constant1'
  //   Logic: '<S216>/AND3'
  //   RelationalOperator: '<S216>/Equal1'
  //   RelationalOperator: '<S216>/Relational Operator'
  //   Switch: '<S216>/Switch1'
  //   Switch: '<S216>/Switch2'

  if ((FLIGHT_Hexacopter_fail_P.Clamping_zero_Value_j != rtb_DeadZone_i) &&
      (tmp_5 == tmp_6)) {
    rtb_IntegralGain_a = FLIGHT_Hexacopter_fail_P.Constant1_Value_c;
  }

  // Update for DiscreteIntegrator: '<S226>/Integrator' incorporates:
  //   Switch: '<S216>/Switch'

  FLIGHT_Hexacopter_fail_DW.Integrator_DSTATE_g +=
    FLIGHT_Hexacopter_fail_P.Integrator_gainval_g * rtb_IntegralGain_a;

  // Update for DiscreteIntegrator: '<S221>/Filter'
  FLIGHT_Hexacopter_fail_DW.Filter_DSTATE_f +=
    FLIGHT_Hexacopter_fail_P.Filter_gainval_h * rtb_FilterCoefficient_d;

  // Switch: '<S320>/Switch1' incorporates:
  //   Constant: '<S320>/Clamping_zero'
  //   Constant: '<S320>/Constant'
  //   Constant: '<S320>/Constant2'
  //   RelationalOperator: '<S320>/fix for DT propagation issue'

  if (rtb_DeadZone_h > FLIGHT_Hexacopter_fail_P.Clamping_zero_Value_n) {
    tmp_5 = FLIGHT_Hexacopter_fail_P.Constant_Value_iw;
  } else {
    tmp_5 = FLIGHT_Hexacopter_fail_P.Constant2_Value_l;
  }

  // Switch: '<S320>/Switch2' incorporates:
  //   Constant: '<S320>/Clamping_zero'
  //   Constant: '<S320>/Constant3'
  //   Constant: '<S320>/Constant4'
  //   RelationalOperator: '<S320>/fix for DT propagation issue1'

  if (rtb_IntegralGain > FLIGHT_Hexacopter_fail_P.Clamping_zero_Value_n) {
    tmp_6 = FLIGHT_Hexacopter_fail_P.Constant3_Value_p2;
  } else {
    tmp_6 = FLIGHT_Hexacopter_fail_P.Constant4_Value_k;
  }

  // Switch: '<S320>/Switch' incorporates:
  //   Constant: '<S320>/Clamping_zero'
  //   Constant: '<S320>/Constant1'
  //   Logic: '<S320>/AND3'
  //   RelationalOperator: '<S320>/Equal1'
  //   RelationalOperator: '<S320>/Relational Operator'
  //   Switch: '<S320>/Switch1'
  //   Switch: '<S320>/Switch2'

  if ((FLIGHT_Hexacopter_fail_P.Clamping_zero_Value_n != rtb_DeadZone_h) &&
      (tmp_5 == tmp_6)) {
    rtb_IntegralGain = FLIGHT_Hexacopter_fail_P.Constant1_Value_j;
  }

  // Update for DiscreteIntegrator: '<S330>/Integrator' incorporates:
  //   Switch: '<S320>/Switch'

  FLIGHT_Hexacopter_fail_DW.Integrator_DSTATE_h +=
    FLIGHT_Hexacopter_fail_P.Integrator_gainval_a * rtb_IntegralGain;

  // Update for DiscreteIntegrator: '<S325>/Filter'
  FLIGHT_Hexacopter_fail_DW.Filter_DSTATE_n +=
    FLIGHT_Hexacopter_fail_P.Filter_gainval_f * rtb_FilterCoefficient_g;

  // Matfile logging
  rt_UpdateTXYLogVars(FLIGHT_Hexacopter_fail_M->rtwLogInfo,
                      (&FLIGHT_Hexacopter_fail_M->Timing.taskTime0));

  // signal main to stop simulation
  {                                    // Sample time: [0.01s, 0.0s]
    if ((rtmGetTFinal(FLIGHT_Hexacopter_fail_M)!=-1) &&
        !((rtmGetTFinal(FLIGHT_Hexacopter_fail_M)-
           FLIGHT_Hexacopter_fail_M->Timing.taskTime0) >
          FLIGHT_Hexacopter_fail_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(FLIGHT_Hexacopter_fail_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  FLIGHT_Hexacopter_fail_M->Timing.taskTime0 =
    ((time_T)(++FLIGHT_Hexacopter_fail_M->Timing.clockTick0)) *
    FLIGHT_Hexacopter_fail_M->Timing.stepSize0;
}

// Model initialize function
void FLIGHT_Hexacopter_fail_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(FLIGHT_Hexacopter_fail_M, -1);
  FLIGHT_Hexacopter_fail_M->Timing.stepSize0 = 0.01;

  // Setup for data logging
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    FLIGHT_Hexacopter_fail_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  // Setup for data logging
  {
    rtliSetLogXSignalInfo(FLIGHT_Hexacopter_fail_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(FLIGHT_Hexacopter_fail_M->rtwLogInfo, (NULL));
    rtliSetLogT(FLIGHT_Hexacopter_fail_M->rtwLogInfo, "tout");
    rtliSetLogX(FLIGHT_Hexacopter_fail_M->rtwLogInfo, "");
    rtliSetLogXFinal(FLIGHT_Hexacopter_fail_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(FLIGHT_Hexacopter_fail_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(FLIGHT_Hexacopter_fail_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(FLIGHT_Hexacopter_fail_M->rtwLogInfo, 0);
    rtliSetLogDecimation(FLIGHT_Hexacopter_fail_M->rtwLogInfo, 1);
    rtliSetLogY(FLIGHT_Hexacopter_fail_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(FLIGHT_Hexacopter_fail_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(FLIGHT_Hexacopter_fail_M->rtwLogInfo, (NULL));
  }

  // Matfile logging
  rt_StartDataLoggingWithStartTime(FLIGHT_Hexacopter_fail_M->rtwLogInfo, 0.0,
    rtmGetTFinal(FLIGHT_Hexacopter_fail_M),
    FLIGHT_Hexacopter_fail_M->Timing.stepSize0, (&rtmGetErrorStatus
    (FLIGHT_Hexacopter_fail_M)));

  {
    static const char_T ParameterNameStr[14] = "FDD_M1_STATUS";
    static const char_T ParameterNameStr_0[14] = "FDD_M2_STATUS";
    static const char_T ParameterNameStr_1[14] = "FDD_M3_STATUS";
    static const char_T ParameterNameStr_2[14] = "FDD_M4_STATUS";
    static const char_T ParameterNameStr_3[14] = "FDD_M5_STATUS";
    static const char_T ParameterNameStr_4[14] = "FDD_M6_STATUS";
    real_T tmp;

    // InitializeConditions for RateLimiter: '<S3>/Rate Limiter1'
    FLIGHT_Hexacopter_fail_DW.PrevY = FLIGHT_Hexacopter_fail_P.RateLimiter1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S278>/Integrator'
    FLIGHT_Hexacopter_fail_DW.Integrator_DSTATE =
      FLIGHT_Hexacopter_fail_P.PIDController2_InitialConditi_l;

    // InitializeConditions for DiscreteIntegrator: '<S273>/Filter'
    FLIGHT_Hexacopter_fail_DW.Filter_DSTATE =
      FLIGHT_Hexacopter_fail_P.PIDController2_InitialCondition;

    // InitializeConditions for RateLimiter: '<S3>/Rate Limiter2'
    FLIGHT_Hexacopter_fail_DW.PrevY_o = FLIGHT_Hexacopter_fail_P.RateLimiter2_IC;

    // InitializeConditions for DiscreteIntegrator: '<S226>/Integrator'
    FLIGHT_Hexacopter_fail_DW.Integrator_DSTATE_g =
      FLIGHT_Hexacopter_fail_P.PIDController1_InitialConditi_o;

    // InitializeConditions for DiscreteIntegrator: '<S221>/Filter'
    FLIGHT_Hexacopter_fail_DW.Filter_DSTATE_f =
      FLIGHT_Hexacopter_fail_P.PIDController1_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S330>/Integrator'
    FLIGHT_Hexacopter_fail_DW.Integrator_DSTATE_h =
      FLIGHT_Hexacopter_fail_P.PIDController6_InitialConditi_g;

    // InitializeConditions for DiscreteIntegrator: '<S325>/Filter'
    FLIGHT_Hexacopter_fail_DW.Filter_DSTATE_n =
      FLIGHT_Hexacopter_fail_P.PIDController6_InitialCondition;

    // SystemInitialize for Enabled SubSystem: '<S186>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S187>/In1' incorporates:
    //   Outport: '<S187>/Out1'

    FLIGHT_Hexacopter_fail_B.In1_k = FLIGHT_Hexacopter_fail_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S186>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S178>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S182>/In1' incorporates:
    //   Outport: '<S182>/Out1'

    FLIGHT_Hexacopter_fail_B.In1 = FLIGHT_Hexacopter_fail_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S178>/Enabled Subsystem'

    // SystemInitialize for IfAction SubSystem: '<Root>/Altitude_Mode'
    // InitializeConditions for DiscreteIntegrator: '<S49>/Integrator'
    FLIGHT_Hexacopter_fail_DW.Integrator_DSTATE_n =
      FLIGHT_Hexacopter_fail_P.PIDController4_InitialConditi_l;

    // InitializeConditions for DiscreteIntegrator: '<S44>/Filter'
    FLIGHT_Hexacopter_fail_DW.Filter_DSTATE_b =
      FLIGHT_Hexacopter_fail_P.PIDController4_InitialCondition;

    // End of SystemInitialize for SubSystem: '<Root>/Altitude_Mode'

    // SystemInitialize for Merge: '<Root>/Merge1'
    FLIGHT_Hexacopter_fail_B.Merge1[0] =
      FLIGHT_Hexacopter_fail_P.Merge1_InitialOutput;
    FLIGHT_Hexacopter_fail_B.Merge1[1] =
      FLIGHT_Hexacopter_fail_P.Merge1_InitialOutput;
    FLIGHT_Hexacopter_fail_B.Merge1[2] =
      FLIGHT_Hexacopter_fail_P.Merge1_InitialOutput;
    FLIGHT_Hexacopter_fail_B.Merge1[3] =
      FLIGHT_Hexacopter_fail_P.Merge1_InitialOutput;

    // SystemInitialize for Enabled SubSystem: '<S183>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S184>/In1' incorporates:
    //   Outport: '<S184>/Out1'

    FLIGHT_Hexacopter_fail_B.In1_n = FLIGHT_Hexacopter_fail_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S183>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S180>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S181>/In1' incorporates:
    //   Outport: '<S181>/Out1'

    FLIGHT_Hexacopter_fail_B.In1_l = FLIGHT_Hexacopter_fail_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S180>/Enabled Subsystem'

    // Start for MATLABSystem: '<S186>/SourceBlock'
    FLIGHT_Hexacopter_fail_DW.obj_fg.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_fail_DW.obj_fg.isInitialized = 1;
    FLIGHT_Hexacopter_fail_DW.obj_fg.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(FLIGHT_Hexacopter_fail_DW.obj_fg.orbMetadataObj,
                         &FLIGHT_Hexacopter_fail_DW.obj_fg.eventStructObj);
    FLIGHT_Hexacopter_fail_DW.obj_fg.isSetupComplete = true;

    // Start for MATLABSystem: '<S178>/SourceBlock'
    FLIGHT_Hexacopter_fail_DW.obj_e.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_fail_DW.obj_e.isInitialized = 1;
    FLIGHT_Hexacopter_fail_DW.obj_e.orbMetadataObj = ORB_ID
      (vehicle_local_position);
    uORB_read_initialize(FLIGHT_Hexacopter_fail_DW.obj_e.orbMetadataObj,
                         &FLIGHT_Hexacopter_fail_DW.obj_e.eventStructObj);
    FLIGHT_Hexacopter_fail_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S183>/SourceBlock'
    FLIGHT_Hexacopter_fail_DW.obj_j.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_fail_DW.obj_j.isInitialized = 1;
    FLIGHT_Hexacopter_fail_DW.obj_j.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(FLIGHT_Hexacopter_fail_DW.obj_j.orbMetadataObj,
                         &FLIGHT_Hexacopter_fail_DW.obj_j.eventStructObj);
    FLIGHT_Hexacopter_fail_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<S180>/SourceBlock'
    FLIGHT_Hexacopter_fail_DW.obj_no.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_fail_DW.obj_no.isInitialized = 1;
    FLIGHT_Hexacopter_fail_DW.obj_no.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(FLIGHT_Hexacopter_fail_DW.obj_no.orbMetadataObj,
                         &FLIGHT_Hexacopter_fail_DW.obj_no.eventStructObj);
    FLIGHT_Hexacopter_fail_DW.obj_no.isSetupComplete = true;

    // Start for MATLABSystem: '<S4>/Read Parameter13'
    FLIGHT_Hexacopter_fail_DW.obj_k.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_fail_DW.obj_k.SampleTime =
      FLIGHT_Hexacopter_fail_P.ReadParameter13_SampleTime;
    FLIGHT_Hexacopter_fail_DW.obj_k.isInitialized = 1;
    if (FLIGHT_Hexacopter_fail_DW.obj_k.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_fail_DW.obj_k.SampleTime;
    }

    FLIGHT_Hexacopter_fail_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_fail_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter13'

    // Start for MATLABSystem: '<S4>/Read Parameter1'
    FLIGHT_Hexacopter_fail_DW.obj_fo.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_fail_DW.obj_fo.SampleTime =
      FLIGHT_Hexacopter_fail_P.ReadParameter1_SampleTime;
    FLIGHT_Hexacopter_fail_DW.obj_fo.isInitialized = 1;
    if (FLIGHT_Hexacopter_fail_DW.obj_fo.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_fail_DW.obj_fo.SampleTime;
    }

    FLIGHT_Hexacopter_fail_DW.obj_fo.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_fail_DW.obj_fo.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter1'

    // Start for MATLABSystem: '<S4>/Read Parameter2'
    FLIGHT_Hexacopter_fail_DW.obj_b.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_fail_DW.obj_b.SampleTime =
      FLIGHT_Hexacopter_fail_P.ReadParameter2_SampleTime;
    FLIGHT_Hexacopter_fail_DW.obj_b.isInitialized = 1;
    if (FLIGHT_Hexacopter_fail_DW.obj_b.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_fail_DW.obj_b.SampleTime;
    }

    FLIGHT_Hexacopter_fail_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_fail_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter2'

    // Start for MATLABSystem: '<S4>/Read Parameter3'
    FLIGHT_Hexacopter_fail_DW.obj_n.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_fail_DW.obj_n.SampleTime =
      FLIGHT_Hexacopter_fail_P.ReadParameter3_SampleTime;
    FLIGHT_Hexacopter_fail_DW.obj_n.isInitialized = 1;
    if (FLIGHT_Hexacopter_fail_DW.obj_n.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_fail_DW.obj_n.SampleTime;
    }

    FLIGHT_Hexacopter_fail_DW.obj_n.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_fail_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter3'

    // Start for MATLABSystem: '<S4>/Read Parameter4'
    FLIGHT_Hexacopter_fail_DW.obj_f.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_fail_DW.obj_f.SampleTime =
      FLIGHT_Hexacopter_fail_P.ReadParameter4_SampleTime;
    FLIGHT_Hexacopter_fail_DW.obj_f.isInitialized = 1;
    if (FLIGHT_Hexacopter_fail_DW.obj_f.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_fail_DW.obj_f.SampleTime;
    }

    FLIGHT_Hexacopter_fail_DW.obj_f.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_fail_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter4'

    // Start for MATLABSystem: '<S4>/Read Parameter5'
    FLIGHT_Hexacopter_fail_DW.obj.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_fail_DW.obj.SampleTime =
      FLIGHT_Hexacopter_fail_P.ReadParameter5_SampleTime;
    FLIGHT_Hexacopter_fail_DW.obj.isInitialized = 1;
    if (FLIGHT_Hexacopter_fail_DW.obj.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_fail_DW.obj.SampleTime;
    }

    FLIGHT_Hexacopter_fail_DW.obj.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_fail_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter5'

    // Start for MATLABSystem: '<Root>/PX4 PWM Output'
    FLIGHT_Hexacopter_fail_DW.obj_nt.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_fail_DW.obj_nt.isSetupComplete = false;
    FLIGHT_Hexacopter_fail_DW.obj_nt.isInitialized = 1;
    FLIGHT_Hexacopter_PWM_setupImpl(&FLIGHT_Hexacopter_fail_DW.obj_nt, false,
      false);
    FLIGHT_Hexacopter_fail_DW.obj_nt.isSetupComplete = true;
  }
}

// Model terminate function
void FLIGHT_Hexacopter_fail_terminate(void)
{
  // Terminate for MATLABSystem: '<S186>/SourceBlock'
  if (!FLIGHT_Hexacopter_fail_DW.obj_fg.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_fail_DW.obj_fg.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_fail_DW.obj_fg.isInitialized == 1) &&
        FLIGHT_Hexacopter_fail_DW.obj_fg.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_fail_DW.obj_fg.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S186>/SourceBlock'

  // Terminate for MATLABSystem: '<S178>/SourceBlock'
  if (!FLIGHT_Hexacopter_fail_DW.obj_e.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_fail_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_fail_DW.obj_e.isInitialized == 1) &&
        FLIGHT_Hexacopter_fail_DW.obj_e.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_fail_DW.obj_e.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S178>/SourceBlock'

  // Terminate for MATLABSystem: '<S183>/SourceBlock'
  if (!FLIGHT_Hexacopter_fail_DW.obj_j.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_fail_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_fail_DW.obj_j.isInitialized == 1) &&
        FLIGHT_Hexacopter_fail_DW.obj_j.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_fail_DW.obj_j.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S183>/SourceBlock'

  // Terminate for MATLABSystem: '<S180>/SourceBlock'
  if (!FLIGHT_Hexacopter_fail_DW.obj_no.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_fail_DW.obj_no.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_fail_DW.obj_no.isInitialized == 1) &&
        FLIGHT_Hexacopter_fail_DW.obj_no.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_fail_DW.obj_no.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S180>/SourceBlock'

  // Terminate for MATLABSystem: '<S4>/Read Parameter13'
  if (!FLIGHT_Hexacopter_fail_DW.obj_k.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_fail_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter13'

  // Terminate for MATLABSystem: '<S4>/Read Parameter1'
  if (!FLIGHT_Hexacopter_fail_DW.obj_fo.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_fail_DW.obj_fo.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter1'

  // Terminate for MATLABSystem: '<S4>/Read Parameter2'
  if (!FLIGHT_Hexacopter_fail_DW.obj_b.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_fail_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter2'

  // Terminate for MATLABSystem: '<S4>/Read Parameter3'
  if (!FLIGHT_Hexacopter_fail_DW.obj_n.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_fail_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter3'

  // Terminate for MATLABSystem: '<S4>/Read Parameter4'
  if (!FLIGHT_Hexacopter_fail_DW.obj_f.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_fail_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter4'

  // Terminate for MATLABSystem: '<S4>/Read Parameter5'
  if (!FLIGHT_Hexacopter_fail_DW.obj.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_fail_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter5'

  // Terminate for MATLABSystem: '<Root>/PX4 PWM Output'
  if (!FLIGHT_Hexacopter_fail_DW.obj_nt.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_fail_DW.obj_nt.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_fail_DW.obj_nt.isInitialized == 1) &&
        FLIGHT_Hexacopter_fail_DW.obj_nt.isSetupComplete) {
      pwm_disarm(&FLIGHT_Hexacopter_fail_DW.obj_nt.armAdvertiseObj);
      pwm_resetServo(FLIGHT_Hexacopter_fail_DW.obj_nt.servoCount,
                     FLIGHT_Hexacopter_fail_DW.obj_nt.isMain,
                     &FLIGHT_Hexacopter_fail_DW.obj_nt.actuatorAdvertiseObj);
      pwm_close(FLIGHT_Hexacopter_fail_DW.obj_nt.servoCount,
                &FLIGHT_Hexacopter_fail_DW.obj_nt.actuatorAdvertiseObj,
                &FLIGHT_Hexacopter_fail_DW.obj_nt.armAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 PWM Output'
}

//
// File trailer for generated code.
//
// [EOF]
//
