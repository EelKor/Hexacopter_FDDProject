//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_hexacopter.cpp
//
// Code generated for Simulink model 'FLIGHT_hexacopter'.
//
// Model version                  : 1.250
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Fri May 23 13:47:19 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FLIGHT_hexacopter.h"
#include "FLIGHT_hexacopter_types.h"
#include "rtwtypes.h"
#include "FLIGHT_hexacopter_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"

// Block signals (default storage)
B_FLIGHT_hexacopter_T FLIGHT_hexacopter_B;

// Block states (default storage)
DW_FLIGHT_hexacopter_T FLIGHT_hexacopter_DW;

// Real-time model
RT_MODEL_FLIGHT_hexacopter_T FLIGHT_hexacopter_M_ = RT_MODEL_FLIGHT_hexacopter_T
  ();
RT_MODEL_FLIGHT_hexacopter_T *const FLIGHT_hexacopter_M = &FLIGHT_hexacopter_M_;

// Forward declaration for local functions
static void FLIGHT_hexacopter_PWM_setupImpl(px4_internal_block_PWM_FLIGHT_T *obj,
  boolean_T armPWM, boolean_T forceFailsafe);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void FLIGHT_hexacopter_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(FLIGHT_hexacopter_M, 1));
}

//
//         This function updates active task flag for each subrate
//         and rate transition flags for tasks that exchange data.
//         The function assumes rate-monotonic multitasking scheduler.
//         The function must be called at model base rate so that
//         the generated code self-manages all its subrates and rate
//         transition flags.
//
static void rate_monotonic_scheduler(void)
{
  // To ensure a deterministic data transfer between two rates,
  //  data is transferred at the priority of a fast task and the frequency
  //  of the slow task.  The following flags indicate when the data transfer
  //  happens.  That is, a rate interaction flag is set true when both rates
  //  will run, and false otherwise.


  // tid 0 shares data with slower tid rate: 1
  FLIGHT_hexacopter_M->Timing.RateInteraction.TID0_1 =
    (FLIGHT_hexacopter_M->Timing.TaskCounters.TID[1] == 0);

  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (FLIGHT_hexacopter_M->Timing.TaskCounters.TID[1])++;
  if ((FLIGHT_hexacopter_M->Timing.TaskCounters.TID[1]) > 3) {// Sample time: [0.004s, 0.0s] 
    FLIGHT_hexacopter_M->Timing.TaskCounters.TID[1] = 0;
  }
}

// System initialize for atomic system:
void FLIGHT_he_PX4Timestamp_Init(DW_PX4Timestamp_FLIGHT_hexaco_T *localDW)
{
  // Start for MATLABSystem: '<S3>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_hexacop_PX4Timestamp(B_PX4Timestamp_FLIGHT_hexacop_T *localB)
{
  // MATLABSystem: '<S3>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void FLIGHT_he_PX4Timestamp_Term(DW_PX4Timestamp_FLIGHT_hexaco_T *localDW)
{
  // Terminate for MATLABSystem: '<S3>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/PX4 Timestamp'
}

// System initialize for atomic system:
void FLIGHT__PX4Timestamp_b_Init(DW_PX4Timestamp_FLIGHT_hexa_b_T *localDW)
{
  // Start for MATLABSystem: '<S490>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_hexac_PX4Timestamp_o(B_PX4Timestamp_FLIGHT_hexac_l_T *localB)
{
  // MATLABSystem: '<S490>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void FLIGHT__PX4Timestamp_o_Term(DW_PX4Timestamp_FLIGHT_hexa_b_T *localDW)
{
  // Terminate for MATLABSystem: '<S490>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S490>/PX4 Timestamp'
}

// System initialize for atomic system:
void FLIGHT__PX4Timestamp_m_Init(DW_PX4Timestamp_FLIGHT_hexa_f_T *localDW)
{
  // Start for MATLABSystem: '<S504>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_hexac_PX4Timestamp_n(B_PX4Timestamp_FLIGHT_hexac_h_T *localB)
{
  // MATLABSystem: '<S504>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void FLIGHT__PX4Timestamp_k_Term(DW_PX4Timestamp_FLIGHT_hexa_f_T *localDW)
{
  // Terminate for MATLABSystem: '<S504>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S504>/PX4 Timestamp'
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

static void FLIGHT_hexacopter_PWM_setupImpl(px4_internal_block_PWM_FLIGHT_T *obj,
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

// Model step function for TID0
void FLIGHT_hexacopter_step0(void)     // Sample time: [0.001s, 0.0s]
{
  int32_T i;
  real32_T ParamStep;
  real32_T ParamStep_0;
  real32_T ParamStep_1;
  real32_T rtb_IProdOut;
  real32_T rtb_IProdOut_h;
  real32_T rtb_Integrator_cv;
  real32_T rtb_Integrator_k;
  real32_T rtb_Product2_a;
  real32_T rtb_TSamp_p4;
  real32_T rtb_d;
  real32_T rtb_p;
  real32_T rtb_r;
  real32_T rtb_w_radps;
  uint32_T tmp;
  uint16_T tmp_0;
  boolean_T b_varargout_1;
  boolean_T rtb_Compare_a;

  {                                    // Sample time: [0.001s, 0.0s]
    rate_monotonic_scheduler();
  }

  // RateTransition: '<Root>/rate_transition_arm'
  if (FLIGHT_hexacopter_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<Root>/rate_transition_arm'
    FLIGHT_hexacopter_B.rate_transition_arm =
      FLIGHT_hexacopter_DW.rate_transition_arm_Buffer0;

    // RateTransition: '<Root>/rate_transition_des_p'
    FLIGHT_hexacopter_B.rate_transition_des_p =
      FLIGHT_hexacopter_DW.rate_transition_des_p_Buffer0;

    // RateTransition: '<Root>/rate_transition_des_q'
    FLIGHT_hexacopter_B.rate_transition_des_q =
      FLIGHT_hexacopter_DW.rate_transition_des_q_Buffer0;

    // RateTransition: '<Root>/rate_transition_des_r'
    FLIGHT_hexacopter_B.rate_transition_des_r =
      FLIGHT_hexacopter_DW.rate_transition_des_r_Buffer0;
  }

  // End of RateTransition: '<Root>/rate_transition_arm'

  // MATLABSystem: '<S497>/SourceBlock'
  b_varargout_1 = uORB_read_step(FLIGHT_hexacopter_DW.obj_pe.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_pe.eventStructObj, &FLIGHT_hexacopter_B.r4, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S497>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S498>/Enable'

  // Start for MATLABSystem: '<S497>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S498>/In1'
    FLIGHT_hexacopter_B.In1_h = FLIGHT_hexacopter_B.r4;
  }

  // End of Outputs for SubSystem: '<S497>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<Root>/SAS' incorporates:
  //   EnablePort: '<S10>/Enable'

  if (FLIGHT_hexacopter_B.rate_transition_arm) {
    // MATLABSystem: '<S10>/Read Parameter10'
    if (FLIGHT_hexacopter_DW.obj_c.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_c.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_c.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_1) {
      ParamStep = 0.0F;
    }

    // MATLAB Function: '<S10>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S10>/Read Parameter10'
    //
    rtb_w_radps = ParamStep * 2.0F * 3.14159274F;

    // Gain: '<S315>/tau'
    rtb_Product2_a = FLIGHT_hexacopter_P.tau_Gain * rtb_w_radps;

    // Product: '<S316>/Product2'
    ParamStep = rtb_Product2_a * rtb_Product2_a;

    // Bias: '<S316>/Bias'
    rtb_d = ParamStep + FLIGHT_hexacopter_P.Bias_Bias;

    // Gain: '<S316>/Gain'
    rtb_Product2_a *= FLIGHT_hexacopter_P.Gain_Gain_i;

    // Sum: '<S316>/Add1'
    rtb_r = rtb_d + rtb_Product2_a;

    // Sum: '<S315>/Sum' incorporates:
    //   UnitDelay: '<S315>/Unit Delay1'

    rtb_Integrator_cv = FLIGHT_hexacopter_B.In1_h.xyz[1] +
      FLIGHT_hexacopter_DW.UnitDelay1_DSTATE;

    // Sum: '<S315>/Sum1' incorporates:
    //   Bias: '<S316>/Bias1'
    //   Gain: '<S315>/Gain1'
    //   Product: '<S315>/Product5'
    //   Product: '<S316>/Product4'
    //   Sum: '<S315>/Sum2'
    //   UnaryMinus: '<S316>/Unary Minus'
    //   UnitDelay: '<S315>/Unit Delay1'
    //   UnitDelay: '<S315>/Unit Delay2'

    FLIGHT_hexacopter_DW.UnitDelay1_DSTATE = ((-ParamStep +
      FLIGHT_hexacopter_P.Bias1_Bias) / rtb_r * rtb_Integrator_cv +
      FLIGHT_hexacopter_B.In1_h.xyz[1]) * FLIGHT_hexacopter_P.Gain1_Gain_j +
      FLIGHT_hexacopter_DW.UnitDelay2_DSTATE;

    // SampleTimeMath: '<S312>/TSamp' incorporates:
    //   Product: '<S315>/Product1'
    //   Product: '<S316>/Product3'
    //
    //  About '<S312>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )
    //
    rtb_TSamp_p4 = ParamStep / rtb_r * rtb_Integrator_cv *
      FLIGHT_hexacopter_P.TSamp_WtEt;

    // MATLABSystem: '<S10>/Read Parameter5'
    if (FLIGHT_hexacopter_DW.obj_h.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_h.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_h.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_1) {
      ParamStep = 0.0F;
    }

    // Sum: '<S309>/Sum1'
    rtb_Integrator_k = FLIGHT_hexacopter_B.rate_transition_des_q -
      FLIGHT_hexacopter_B.In1_h.xyz[1];

    // MATLABSystem: '<S10>/Read Parameter3'
    if (FLIGHT_hexacopter_DW.obj_b.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_b.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_b.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep_0);
    if (b_varargout_1) {
      ParamStep_0 = 0.0F;
    }

    // Sum: '<S309>/Sum5' incorporates:
    //   DiscreteIntegrator: '<S350>/Integrator'
    //   MATLABSystem: '<S10>/Read Parameter3'
    //   MATLABSystem: '<S10>/Read Parameter5'
    //   Product: '<S309>/Product2'
    //   Product: '<S355>/PProd Out'
    //   Sum: '<S312>/Diff'
    //   Sum: '<S359>/Sum'
    //   UnitDelay: '<S312>/UD'
    //  *
    //  Block description for '<S312>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S312>/UD':
    //
    //   Store in Global RAM

    FLIGHT_hexacopter_B.Sum5 = (rtb_Integrator_k * ParamStep_0 +
      FLIGHT_hexacopter_DW.Integrator_DSTATE_p) - (rtb_TSamp_p4 -
      FLIGHT_hexacopter_DW.UD_DSTATE_l) * ParamStep;

    // MATLABSystem: '<S10>/Read Parameter4'
    if (FLIGHT_hexacopter_DW.obj_p.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_p.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_p.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_1) {
      ParamStep = 0.0F;
    }

    // Product: '<S347>/IProd Out' incorporates:
    //   MATLABSystem: '<S10>/Read Parameter4'
    //
    rtb_IProdOut = rtb_Integrator_k * ParamStep;

    // Sum: '<S315>/Sum3' incorporates:
    //   Product: '<S315>/Product2'
    //   Product: '<S316>/Product5'
    //   Sum: '<S316>/Add3'
    //   UnitDelay: '<S315>/Unit Delay2'

    FLIGHT_hexacopter_DW.UnitDelay2_DSTATE = FLIGHT_hexacopter_B.In1_h.xyz[1] -
      1.0F / rtb_r * (rtb_d - rtb_Product2_a) * rtb_Integrator_cv;

    // Gain: '<S370>/tau'
    rtb_Integrator_k = FLIGHT_hexacopter_P.tau_Gain_n * rtb_w_radps;

    // Product: '<S371>/Product2'
    rtb_Integrator_cv = rtb_Integrator_k * rtb_Integrator_k;

    // Bias: '<S371>/Bias'
    rtb_r = rtb_Integrator_cv + FLIGHT_hexacopter_P.Bias_Bias_b;

    // Gain: '<S371>/Gain'
    rtb_Integrator_k *= FLIGHT_hexacopter_P.Gain_Gain_e;

    // Sum: '<S371>/Add1'
    rtb_d = rtb_r + rtb_Integrator_k;

    // Sum: '<S370>/Sum' incorporates:
    //   UnitDelay: '<S370>/Unit Delay1'

    rtb_Product2_a = FLIGHT_hexacopter_B.In1_h.xyz[0] +
      FLIGHT_hexacopter_DW.UnitDelay1_DSTATE_f;

    // Sum: '<S370>/Sum1' incorporates:
    //   Bias: '<S371>/Bias1'
    //   Gain: '<S370>/Gain1'
    //   Product: '<S370>/Product5'
    //   Product: '<S371>/Product4'
    //   Sum: '<S370>/Sum2'
    //   UnaryMinus: '<S371>/Unary Minus'
    //   UnitDelay: '<S370>/Unit Delay1'
    //   UnitDelay: '<S370>/Unit Delay2'

    FLIGHT_hexacopter_DW.UnitDelay1_DSTATE_f = ((-rtb_Integrator_cv +
      FLIGHT_hexacopter_P.Bias1_Bias_n) / rtb_d * rtb_Product2_a +
      FLIGHT_hexacopter_B.In1_h.xyz[0]) * FLIGHT_hexacopter_P.Gain1_Gain_e +
      FLIGHT_hexacopter_DW.UnitDelay2_DSTATE_c;

    // SampleTimeMath: '<S367>/TSamp' incorporates:
    //   Product: '<S370>/Product1'
    //   Product: '<S371>/Product3'
    //
    //  About '<S367>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )
    //
    rtb_Integrator_cv = rtb_Integrator_cv / rtb_d * rtb_Product2_a *
      FLIGHT_hexacopter_P.TSamp_WtEt_m;

    // MATLABSystem: '<S10>/Read Parameter2'
    if (FLIGHT_hexacopter_DW.obj_da.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_da.SampleTime =
        FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_da.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_1) {
      ParamStep = 0.0F;
    }

    // Sum: '<S310>/Sum1'
    rtb_p = FLIGHT_hexacopter_B.rate_transition_des_p -
      FLIGHT_hexacopter_B.In1_h.xyz[0];

    // MATLABSystem: '<S10>/read_mc_rollrate_p'
    if (FLIGHT_hexacopter_DW.obj_i.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_i.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_i.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep_0);
    if (b_varargout_1) {
      ParamStep_0 = 0.0F;
    }

    // Sum: '<S310>/Sum5' incorporates:
    //   DiscreteIntegrator: '<S405>/Integrator'
    //   MATLABSystem: '<S10>/Read Parameter2'
    //   MATLABSystem: '<S10>/read_mc_rollrate_p'
    //   Product: '<S310>/Product2'
    //   Product: '<S410>/PProd Out'
    //   Sum: '<S367>/Diff'
    //   Sum: '<S414>/Sum'
    //   UnitDelay: '<S367>/UD'
    //  *
    //  Block description for '<S367>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S367>/UD':
    //
    //   Store in Global RAM

    FLIGHT_hexacopter_B.Sum5_d = (rtb_p * ParamStep_0 +
      FLIGHT_hexacopter_DW.Integrator_DSTATE_c) - (rtb_Integrator_cv -
      FLIGHT_hexacopter_DW.UD_DSTATE_m) * ParamStep;

    // MATLABSystem: '<S10>/Read Parameter1'
    if (FLIGHT_hexacopter_DW.obj_ea.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_ea.SampleTime =
        FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_ea.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_1) {
      ParamStep = 0.0F;
    }

    // Product: '<S402>/IProd Out' incorporates:
    //   MATLABSystem: '<S10>/Read Parameter1'
    //
    rtb_IProdOut_h = rtb_p * ParamStep;

    // Sum: '<S370>/Sum3' incorporates:
    //   Product: '<S370>/Product2'
    //   Product: '<S371>/Product5'
    //   Sum: '<S371>/Add3'
    //   UnitDelay: '<S370>/Unit Delay2'

    FLIGHT_hexacopter_DW.UnitDelay2_DSTATE_c = FLIGHT_hexacopter_B.In1_h.xyz[0]
      - 1.0F / rtb_d * (rtb_r - rtb_Integrator_k) * rtb_Product2_a;

    // Gain: '<S425>/tau'
    rtb_p = FLIGHT_hexacopter_P.tau_Gain_c * rtb_w_radps;

    // Product: '<S426>/Product2'
    rtb_Integrator_k = rtb_p * rtb_p;

    // Bias: '<S426>/Bias'
    rtb_r = rtb_Integrator_k + FLIGHT_hexacopter_P.Bias_Bias_c;

    // Gain: '<S426>/Gain'
    rtb_p *= FLIGHT_hexacopter_P.Gain_Gain_b;

    // Sum: '<S426>/Add1'
    rtb_d = rtb_r + rtb_p;

    // Sum: '<S425>/Sum' incorporates:
    //   UnitDelay: '<S425>/Unit Delay1'

    rtb_Product2_a = FLIGHT_hexacopter_B.In1_h.xyz[2] +
      FLIGHT_hexacopter_DW.UnitDelay1_DSTATE_e;

    // Sum: '<S425>/Sum1' incorporates:
    //   Bias: '<S426>/Bias1'
    //   Gain: '<S425>/Gain1'
    //   Product: '<S425>/Product5'
    //   Product: '<S426>/Product4'
    //   Sum: '<S425>/Sum2'
    //   UnaryMinus: '<S426>/Unary Minus'
    //   UnitDelay: '<S425>/Unit Delay1'
    //   UnitDelay: '<S425>/Unit Delay2'

    FLIGHT_hexacopter_DW.UnitDelay1_DSTATE_e = ((-rtb_Integrator_k +
      FLIGHT_hexacopter_P.Bias1_Bias_i) / rtb_d * rtb_Product2_a +
      FLIGHT_hexacopter_B.In1_h.xyz[2]) * FLIGHT_hexacopter_P.Gain1_Gain_iw +
      FLIGHT_hexacopter_DW.UnitDelay2_DSTATE_e;

    // SampleTimeMath: '<S422>/TSamp' incorporates:
    //   Product: '<S425>/Product1'
    //   Product: '<S426>/Product3'
    //
    //  About '<S422>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )
    //
    rtb_w_radps = rtb_Integrator_k / rtb_d * rtb_Product2_a *
      FLIGHT_hexacopter_P.TSamp_WtEt_p;

    // MATLABSystem: '<S10>/Read Parameter8'
    if (FLIGHT_hexacopter_DW.obj_i4.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_i4.SampleTime =
        FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_i4.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_1) {
      ParamStep = 0.0F;
    }

    // MATLABSystem: '<S10>/Read Parameter6'
    if (FLIGHT_hexacopter_DW.obj_a.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_a.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_a.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep_0);
    if (b_varargout_1) {
      ParamStep_0 = 0.0F;
    }

    // Sum: '<S311>/Sum1'
    rtb_Integrator_k = FLIGHT_hexacopter_B.rate_transition_des_r -
      FLIGHT_hexacopter_B.In1_h.xyz[2];

    // MATLABSystem: '<S10>/Read Parameter9'
    if (FLIGHT_hexacopter_DW.obj_e.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_e.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_e.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep_1);
    if (b_varargout_1) {
      ParamStep_1 = 0.0F;
    }

    // Sum: '<S10>/Sum' incorporates:
    //   DiscreteIntegrator: '<S460>/Integrator'
    //   MATLABSystem: '<S10>/Read Parameter6'
    //   MATLABSystem: '<S10>/Read Parameter8'
    //   MATLABSystem: '<S10>/Read Parameter9'
    //   Product: '<S10>/yawrate_feedforward'
    //   Product: '<S311>/Product2'
    //   Product: '<S465>/PProd Out'
    //   Sum: '<S311>/Sum5'
    //   Sum: '<S422>/Diff'
    //   Sum: '<S469>/Sum'
    //   UnitDelay: '<S422>/UD'
    //  *
    //  Block description for '<S422>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S422>/UD':
    //
    //   Store in Global RAM

    FLIGHT_hexacopter_B.Sum = ((rtb_Integrator_k * ParamStep_0 +
      FLIGHT_hexacopter_DW.Integrator_DSTATE_g) - (rtb_w_radps -
      FLIGHT_hexacopter_DW.UD_DSTATE_jy) * ParamStep) + ParamStep_1 *
      FLIGHT_hexacopter_B.rate_transition_des_r;

    // MATLABSystem: '<S10>/Read Parameter7'
    if (FLIGHT_hexacopter_DW.obj_j.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_j.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_j.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_1) {
      ParamStep = 0.0F;
    }

    // Sum: '<S425>/Sum3' incorporates:
    //   Product: '<S425>/Product2'
    //   Product: '<S426>/Product5'
    //   Sum: '<S426>/Add3'
    //   UnitDelay: '<S425>/Unit Delay2'

    FLIGHT_hexacopter_DW.UnitDelay2_DSTATE_e = FLIGHT_hexacopter_B.In1_h.xyz[2]
      - 1.0F / rtb_d * (rtb_r - rtb_p) * rtb_Product2_a;

    // Update for UnitDelay: '<S312>/UD'
    //
    //  Block description for '<S312>/UD':
    //
    //   Store in Global RAM

    FLIGHT_hexacopter_DW.UD_DSTATE_l = rtb_TSamp_p4;

    // Update for DiscreteIntegrator: '<S350>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_p +=
      FLIGHT_hexacopter_P.Integrator_gainval * rtb_IProdOut;

    // Update for UnitDelay: '<S367>/UD'
    //
    //  Block description for '<S367>/UD':
    //
    //   Store in Global RAM

    FLIGHT_hexacopter_DW.UD_DSTATE_m = rtb_Integrator_cv;

    // Update for DiscreteIntegrator: '<S405>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_c +=
      FLIGHT_hexacopter_P.Integrator_gainval_b * rtb_IProdOut_h;

    // Update for UnitDelay: '<S422>/UD'
    //
    //  Block description for '<S422>/UD':
    //
    //   Store in Global RAM

    FLIGHT_hexacopter_DW.UD_DSTATE_jy = rtb_w_radps;

    // Update for DiscreteIntegrator: '<S460>/Integrator' incorporates:
    //   MATLABSystem: '<S10>/Read Parameter7'
    //   Product: '<S457>/IProd Out'
    //
    FLIGHT_hexacopter_DW.Integrator_DSTATE_g += rtb_Integrator_k * ParamStep *
      FLIGHT_hexacopter_P.Integrator_gainval_p;
  }

  // End of Outputs for SubSystem: '<Root>/SAS'

  // RateTransition: '<Root>/Rate Transition1' incorporates:
  //   RateTransition: '<Root>/rate_transition_throttle'

  if (FLIGHT_hexacopter_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<Root>/Rate Transition1'
    FLIGHT_hexacopter_B.RateTransition1 =
      FLIGHT_hexacopter_DW.RateTransition1_Buffer0;

    // RateTransition: '<Root>/rate_transition_ctrl_sw'
    FLIGHT_hexacopter_B.rate_transition_ctrl_sw =
      FLIGHT_hexacopter_DW.rate_transition_ctrl_sw_Buffer0;

    // RateTransition: '<Root>/rate_transition_throttle'
    FLIGHT_hexacopter_B.rate_transition_throttle =
      FLIGHT_hexacopter_DW.rate_transition_throttle_Buffer;
  }

  // End of RateTransition: '<Root>/Rate Transition1'

  // MATLAB Function: '<S13>/MATLAB Function' incorporates:
  //   Constant: '<S488>/Constant'
  //   RelationalOperator: '<S488>/Compare'

  if (FLIGHT_hexacopter_B.rate_transition_ctrl_sw >=
      FLIGHT_hexacopter_P.CompareToConstant_const) {
    rtb_Product2_a = FLIGHT_hexacopter_B.RateTransition1;
  } else {
    rtb_Product2_a = FLIGHT_hexacopter_B.Sum5_d;
  }

  // End of MATLAB Function: '<S13>/MATLAB Function'

  // Outputs for Enabled SubSystem: '<Root>/Mixer' incorporates:
  //   EnablePort: '<S7>/Enable'

  if (FLIGHT_hexacopter_B.rate_transition_arm) {
    // MATLAB Function: '<S7>/pwm_out2'
    // Function description:
    //   Control allocation. The quadrotor type is X-configuration,
    //   and the airframe is as follows:
    // 3↓   1↑
    //   \ /
    //   / \
    // 2↑   4↓
    // Input：
    //   Roll, Pitch, Yaw: attitude controller output.
    //   Thrust
    //  M1 = uint16(Thrust*scale + (- Roll + Pitch + Yaw) * scale_att + idle_PWM); 
    //  M2 = uint16(Thrust*scale + (Roll - Pitch + Yaw) * scale_att + idle_PWM); 
    //  M3 = uint16(Thrust*scale + (Roll + Pitch - Yaw) * scale_att + idle_PWM); 
    //  M4 = uint16(Thrust*scale + (- Roll - Pitch - Yaw) * scale_att + idle_PWM); 
    //  Hex X
    //  M1 = ((Pitch + Roll / 2 - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; 
    //  M2 = ((Pitch - Roll / 2 + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; 
    //  M3 = ((-Roll - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM;
    //  M4 = ((-Pitch - Roll / 2 + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; 
    //  M5 = ((-Pitch + Roll / 2 - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; 
    //  M6 = ((Roll + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM;
    //  M7 = 1000;
    //  M8 = 1000;
    //  Hex X (From Adam)
    //  Hex X (Version 2)
    //  Roll/Yaw
    //  M1 = ((-Roll - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM;
    //  M2 = ((Roll + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM;
    //  % + Pitch/Roll
    //  M6 = ((Pitch + Roll / 2 - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; 
    //  M4 = ((Pitch - Roll / 2 + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; 
    //  % - Pitch/Roll
    //  M5 = ((-Pitch - Roll / 2 + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; 
    //  M3 = ((-Pitch + Roll / 2 - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; 
    rtb_d = rt_roundf_snf(((-rtb_Product2_a - FLIGHT_hexacopter_B.Sum) *
      FLIGHT_hexacopter_B.rate_transition_throttle / 3.0F +
      FLIGHT_hexacopter_B.rate_transition_throttle) * 1000.0F);
    if (rtb_d < 65536.0F) {
      if (rtb_d >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(rtb_d);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    tmp = tmp_0 + 1000U;
    if (rtb_d < 65536.0F) {
      if (rtb_d >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(rtb_d);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    if (tmp_0 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S7>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S7>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[0] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[0] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[0] = static_cast<uint16_T>(tmp);
    }

    // MATLAB Function: '<S7>/pwm_out2'
    rtb_d = rt_roundf_snf(((rtb_Product2_a + FLIGHT_hexacopter_B.Sum) *
      FLIGHT_hexacopter_B.rate_transition_throttle / 3.0F +
      FLIGHT_hexacopter_B.rate_transition_throttle) * 1000.0F);
    if (rtb_d < 65536.0F) {
      if (rtb_d >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(rtb_d);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    tmp = tmp_0 + 1000U;
    if (rtb_d < 65536.0F) {
      if (rtb_d >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(rtb_d);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    if (tmp_0 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S7>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S7>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[1] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[1] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[1] = static_cast<uint16_T>(tmp);
    }

    // MATLAB Function: '<S7>/pwm_out2'
    rtb_d = rt_roundf_snf((((rtb_Product2_a / 2.0F + FLIGHT_hexacopter_B.Sum5) -
      FLIGHT_hexacopter_B.Sum) * FLIGHT_hexacopter_B.rate_transition_throttle /
      3.0F + FLIGHT_hexacopter_B.rate_transition_throttle) * 1000.0F);
    if (rtb_d < 65536.0F) {
      if (rtb_d >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(rtb_d);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    tmp = tmp_0 + 1000U;
    if (rtb_d < 65536.0F) {
      if (rtb_d >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(rtb_d);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    if (tmp_0 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S7>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S7>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[2] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[2] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[2] = static_cast<uint16_T>(tmp);
    }

    // MATLAB Function: '<S7>/pwm_out2'
    rtb_d = rt_roundf_snf((((-FLIGHT_hexacopter_B.Sum5 - rtb_Product2_a / 2.0F)
      + FLIGHT_hexacopter_B.Sum) * FLIGHT_hexacopter_B.rate_transition_throttle /
      3.0F + FLIGHT_hexacopter_B.rate_transition_throttle) * 1000.0F);
    if (rtb_d < 65536.0F) {
      if (rtb_d >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(rtb_d);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    tmp = tmp_0 + 1000U;
    if (rtb_d < 65536.0F) {
      if (rtb_d >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(rtb_d);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    if (tmp_0 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S7>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S7>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[3] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[3] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[3] = static_cast<uint16_T>(tmp);
    }

    // MATLAB Function: '<S7>/pwm_out2'
    rtb_d = rt_roundf_snf((((FLIGHT_hexacopter_B.Sum5 - rtb_Product2_a / 2.0F) +
      FLIGHT_hexacopter_B.Sum) * FLIGHT_hexacopter_B.rate_transition_throttle /
      3.0F + FLIGHT_hexacopter_B.rate_transition_throttle) * 1000.0F);
    if (rtb_d < 65536.0F) {
      if (rtb_d >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(rtb_d);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    tmp = tmp_0 + 1000U;
    if (rtb_d < 65536.0F) {
      if (rtb_d >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(rtb_d);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    if (tmp_0 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S7>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S7>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[4] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[4] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[4] = static_cast<uint16_T>(tmp);
    }

    // MATLAB Function: '<S7>/pwm_out2'
    rtb_d = rt_roundf_snf((((rtb_Product2_a / 2.0F - FLIGHT_hexacopter_B.Sum5) -
      FLIGHT_hexacopter_B.Sum) * FLIGHT_hexacopter_B.rate_transition_throttle /
      3.0F + FLIGHT_hexacopter_B.rate_transition_throttle) * 1000.0F);
    if (rtb_d < 65536.0F) {
      if (rtb_d >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(rtb_d);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    tmp = tmp_0 + 1000U;
    if (rtb_d < 65536.0F) {
      if (rtb_d >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(rtb_d);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    if (tmp_0 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S7>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S7>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[5] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[5] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S7>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[5] = static_cast<uint16_T>(tmp);
    }
  }

  // End of Outputs for SubSystem: '<Root>/Mixer'

  // DataTypeConversion: '<S4>/Data Type Conversion6'
  for (i = 0; i < 6; i++) {
    FLIGHT_hexacopter_B.DataTypeConversion6[i] =
      FLIGHT_hexacopter_B.Output_Limits1[i];
  }

  // End of DataTypeConversion: '<S4>/Data Type Conversion6'

  // MATLABSystem: '<S4>/Read Parameter13'
  if (FLIGHT_hexacopter_DW.obj_gv.SampleTime !=
      FLIGHT_hexacopter_P.SampleTime_SAS) {
    FLIGHT_hexacopter_DW.obj_gv.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_gv.MW_PARAMHANDLE,
    MW_INT32, &i);
  if (b_varargout_1) {
    i = 0;
  }

  // RateTransition: '<Root>/Rate Transition4'
  if (FLIGHT_hexacopter_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<Root>/Rate Transition4'
    FLIGHT_hexacopter_B.RateTransition4 =
      FLIGHT_hexacopter_DW.RateTransition4_Buffer0;
  }

  // End of RateTransition: '<Root>/Rate Transition4'

  // RelationalOperator: '<S185>/Compare' incorporates:
  //   Constant: '<S185>/Constant'

  rtb_Compare_a = (FLIGHT_hexacopter_B.RateTransition4 >=
                   FLIGHT_hexacopter_P.CompareToConstant_const_g);

  // MATLABSystem: '<S4>/Read Parameter1'
  if (FLIGHT_hexacopter_DW.obj_j5.SampleTime !=
      FLIGHT_hexacopter_P.SampleTime_SAS) {
    FLIGHT_hexacopter_DW.obj_j5.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_j5.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_hexacopter_B.ParamStep_c);
  if (b_varargout_1) {
    FLIGHT_hexacopter_B.ParamStep_c = 0;
  }

  // MATLABSystem: '<S4>/Read Parameter2'
  if (FLIGHT_hexacopter_DW.obj_ao.SampleTime !=
      FLIGHT_hexacopter_P.SampleTime_SAS) {
    FLIGHT_hexacopter_DW.obj_ao.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_ao.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_hexacopter_B.ParamStep_b);
  if (b_varargout_1) {
    FLIGHT_hexacopter_B.ParamStep_b = 0;
  }

  // MATLABSystem: '<S4>/Read Parameter3'
  if (FLIGHT_hexacopter_DW.obj_nt.SampleTime !=
      FLIGHT_hexacopter_P.SampleTime_SAS) {
    FLIGHT_hexacopter_DW.obj_nt.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_nt.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_hexacopter_B.ParamStep_p);
  if (b_varargout_1) {
    FLIGHT_hexacopter_B.ParamStep_p = 0;
  }

  // MATLABSystem: '<S4>/Read Parameter4'
  if (FLIGHT_hexacopter_DW.obj_cx.SampleTime !=
      FLIGHT_hexacopter_P.SampleTime_SAS) {
    FLIGHT_hexacopter_DW.obj_cx.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_cx.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_hexacopter_B.ParamStep_cv);
  if (b_varargout_1) {
    FLIGHT_hexacopter_B.ParamStep_cv = 0;
  }

  // MATLABSystem: '<S4>/Read Parameter5'
  if (FLIGHT_hexacopter_DW.obj_aq.SampleTime !=
      FLIGHT_hexacopter_P.SampleTime_SAS) {
    FLIGHT_hexacopter_DW.obj_aq.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_aq.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_hexacopter_B.ParamStep_f);
  if (b_varargout_1) {
    FLIGHT_hexacopter_B.ParamStep_f = 0;
  }

  // Switch: '<S4>/Switch' incorporates:
  //   Constant: '<S4>/Constant'
  //   DataTypeConversion: '<S4>/Data Type Conversion3'
  //   MATLABSystem: '<S4>/Read Parameter13'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.d = i;
  } else {
    FLIGHT_hexacopter_B.d = FLIGHT_hexacopter_P.Constant_Value_mc;
  }

  // Gain: '<S186>/Gain' incorporates:
  //   Switch: '<S4>/Switch'

  FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Gain_Gain_j *
    FLIGHT_hexacopter_B.d;

  // Saturate: '<S186>/Saturation'
  if (FLIGHT_hexacopter_B.u0 > FLIGHT_hexacopter_P.Saturation_UpperSat) {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_UpperSat;
  } else if (FLIGHT_hexacopter_B.u0 < FLIGHT_hexacopter_P.Saturation_LowerSat) {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_LowerSat;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S186>/Constant'
  //   Product: '<S186>/Product'
  //   Saturate: '<S186>/Saturation'
  //   Sum: '<S186>/Sum'
  //   Sum: '<S186>/Sum1'

  FLIGHT_hexacopter_B.d = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[0]) -
    FLIGHT_hexacopter_P.Constant_Value_k) * FLIGHT_hexacopter_B.u0 +
    FLIGHT_hexacopter_P.Constant_Value_k);
  if (rtIsNaN(FLIGHT_hexacopter_B.d) || rtIsInf(FLIGHT_hexacopter_B.d)) {
    FLIGHT_hexacopter_B.d = 0.0;
  } else {
    FLIGHT_hexacopter_B.d = fmod(FLIGHT_hexacopter_B.d, 65536.0);
  }

  // Switch: '<S4>/Switch1' incorporates:
  //   Constant: '<S4>/Constant1'
  //   DataTypeConversion: '<S4>/Data Type Conversion2'
  //   MATLABSystem: '<S4>/Read Parameter1'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.d1 = FLIGHT_hexacopter_B.ParamStep_c;
  } else {
    FLIGHT_hexacopter_B.d1 = FLIGHT_hexacopter_P.Constant1_Value;
  }

  // Gain: '<S187>/Gain' incorporates:
  //   Switch: '<S4>/Switch1'

  FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Gain_Gain_h *
    FLIGHT_hexacopter_B.d1;

  // Saturate: '<S187>/Saturation'
  if (FLIGHT_hexacopter_B.u0 > FLIGHT_hexacopter_P.Saturation_UpperSat_m) {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_UpperSat_m;
  } else if (FLIGHT_hexacopter_B.u0 < FLIGHT_hexacopter_P.Saturation_LowerSat_o)
  {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_LowerSat_o;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S187>/Constant'
  //   Product: '<S187>/Product'
  //   Saturate: '<S187>/Saturation'
  //   Sum: '<S187>/Sum'
  //   Sum: '<S187>/Sum1'

  FLIGHT_hexacopter_B.d1 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[1]) -
    FLIGHT_hexacopter_P.Constant_Value_ms) * FLIGHT_hexacopter_B.u0 +
    FLIGHT_hexacopter_P.Constant_Value_ms);
  if (rtIsNaN(FLIGHT_hexacopter_B.d1) || rtIsInf(FLIGHT_hexacopter_B.d1)) {
    FLIGHT_hexacopter_B.d1 = 0.0;
  } else {
    FLIGHT_hexacopter_B.d1 = fmod(FLIGHT_hexacopter_B.d1, 65536.0);
  }

  // Switch: '<S4>/Switch2' incorporates:
  //   Constant: '<S4>/Constant2'
  //   DataTypeConversion: '<S4>/Data Type Conversion'
  //   MATLABSystem: '<S4>/Read Parameter2'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.d2 = FLIGHT_hexacopter_B.ParamStep_b;
  } else {
    FLIGHT_hexacopter_B.d2 = FLIGHT_hexacopter_P.Constant2_Value;
  }

  // Gain: '<S188>/Gain' incorporates:
  //   Switch: '<S4>/Switch2'

  FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Gain_Gain_c *
    FLIGHT_hexacopter_B.d2;

  // Saturate: '<S188>/Saturation'
  if (FLIGHT_hexacopter_B.u0 > FLIGHT_hexacopter_P.Saturation_UpperSat_b) {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_UpperSat_b;
  } else if (FLIGHT_hexacopter_B.u0 < FLIGHT_hexacopter_P.Saturation_LowerSat_g)
  {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_LowerSat_g;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S188>/Constant'
  //   Product: '<S188>/Product'
  //   Saturate: '<S188>/Saturation'
  //   Sum: '<S188>/Sum'
  //   Sum: '<S188>/Sum1'

  FLIGHT_hexacopter_B.d2 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[2]) -
    FLIGHT_hexacopter_P.Constant_Value_i) * FLIGHT_hexacopter_B.u0 +
    FLIGHT_hexacopter_P.Constant_Value_i);
  if (rtIsNaN(FLIGHT_hexacopter_B.d2) || rtIsInf(FLIGHT_hexacopter_B.d2)) {
    FLIGHT_hexacopter_B.d2 = 0.0;
  } else {
    FLIGHT_hexacopter_B.d2 = fmod(FLIGHT_hexacopter_B.d2, 65536.0);
  }

  // Switch: '<S4>/Switch3' incorporates:
  //   Constant: '<S4>/Constant3'
  //   DataTypeConversion: '<S4>/Data Type Conversion4'
  //   MATLABSystem: '<S4>/Read Parameter3'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.d3 = FLIGHT_hexacopter_B.ParamStep_p;
  } else {
    FLIGHT_hexacopter_B.d3 = FLIGHT_hexacopter_P.Constant3_Value;
  }

  // Gain: '<S189>/Gain' incorporates:
  //   Switch: '<S4>/Switch3'

  FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Gain_Gain_n *
    FLIGHT_hexacopter_B.d3;

  // Saturate: '<S189>/Saturation'
  if (FLIGHT_hexacopter_B.u0 > FLIGHT_hexacopter_P.Saturation_UpperSat_be) {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_UpperSat_be;
  } else if (FLIGHT_hexacopter_B.u0 < FLIGHT_hexacopter_P.Saturation_LowerSat_e)
  {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_LowerSat_e;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S189>/Constant'
  //   Product: '<S189>/Product'
  //   Saturate: '<S189>/Saturation'
  //   Sum: '<S189>/Sum'
  //   Sum: '<S189>/Sum1'

  FLIGHT_hexacopter_B.d3 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[3]) -
    FLIGHT_hexacopter_P.Constant_Value_j) * FLIGHT_hexacopter_B.u0 +
    FLIGHT_hexacopter_P.Constant_Value_j);
  if (rtIsNaN(FLIGHT_hexacopter_B.d3) || rtIsInf(FLIGHT_hexacopter_B.d3)) {
    FLIGHT_hexacopter_B.d3 = 0.0;
  } else {
    FLIGHT_hexacopter_B.d3 = fmod(FLIGHT_hexacopter_B.d3, 65536.0);
  }

  // Switch: '<S4>/Switch4' incorporates:
  //   Constant: '<S4>/Constant4'
  //   DataTypeConversion: '<S4>/Data Type Conversion1'
  //   MATLABSystem: '<S4>/Read Parameter4'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.d4 = FLIGHT_hexacopter_B.ParamStep_cv;
  } else {
    FLIGHT_hexacopter_B.d4 = FLIGHT_hexacopter_P.Constant4_Value;
  }

  // Gain: '<S190>/Gain' incorporates:
  //   Switch: '<S4>/Switch4'

  FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Gain_Gain_f *
    FLIGHT_hexacopter_B.d4;

  // Saturate: '<S190>/Saturation'
  if (FLIGHT_hexacopter_B.u0 > FLIGHT_hexacopter_P.Saturation_UpperSat_d) {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_UpperSat_d;
  } else if (FLIGHT_hexacopter_B.u0 < FLIGHT_hexacopter_P.Saturation_LowerSat_l)
  {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_LowerSat_l;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S190>/Constant'
  //   Product: '<S190>/Product'
  //   Saturate: '<S190>/Saturation'
  //   Sum: '<S190>/Sum'
  //   Sum: '<S190>/Sum1'

  FLIGHT_hexacopter_B.d4 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[4]) -
    FLIGHT_hexacopter_P.Constant_Value_lw) * FLIGHT_hexacopter_B.u0 +
    FLIGHT_hexacopter_P.Constant_Value_lw);
  if (rtIsNaN(FLIGHT_hexacopter_B.d4) || rtIsInf(FLIGHT_hexacopter_B.d4)) {
    FLIGHT_hexacopter_B.d4 = 0.0;
  } else {
    FLIGHT_hexacopter_B.d4 = fmod(FLIGHT_hexacopter_B.d4, 65536.0);
  }

  // Switch: '<S4>/Switch5' incorporates:
  //   Constant: '<S4>/Constant5'
  //   DataTypeConversion: '<S4>/Data Type Conversion5'
  //   MATLABSystem: '<S4>/Read Parameter5'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_B.ParamStep_f;
  } else {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Constant5_Value;
  }

  // Gain: '<S191>/Gain' incorporates:
  //   Switch: '<S4>/Switch5'

  FLIGHT_hexacopter_B.u0 *= FLIGHT_hexacopter_P.Gain_Gain_m;

  // Saturate: '<S191>/Saturation'
  if (FLIGHT_hexacopter_B.u0 > FLIGHT_hexacopter_P.Saturation_UpperSat_i) {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_UpperSat_i;
  } else if (FLIGHT_hexacopter_B.u0 < FLIGHT_hexacopter_P.Saturation_LowerSat_n)
  {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_LowerSat_n;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S191>/Constant'
  //   Product: '<S191>/Product'
  //   Saturate: '<S191>/Saturation'
  //   Sum: '<S191>/Sum'
  //   Sum: '<S191>/Sum1'

  FLIGHT_hexacopter_B.u0 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[5]) -
    FLIGHT_hexacopter_P.Constant_Value_ox) * FLIGHT_hexacopter_B.u0 +
    FLIGHT_hexacopter_P.Constant_Value_ox);
  if (rtIsNaN(FLIGHT_hexacopter_B.u0) || rtIsInf(FLIGHT_hexacopter_B.u0)) {
    FLIGHT_hexacopter_B.u0 = 0.0;
  } else {
    FLIGHT_hexacopter_B.u0 = fmod(FLIGHT_hexacopter_B.u0, 65536.0);
  }

  // RateTransition: '<Root>/Rate Transition7'
  if (FLIGHT_hexacopter_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<Root>/Rate Transition7'
    FLIGHT_hexacopter_B.RateTransition7 =
      FLIGHT_hexacopter_DW.RateTransition7_Buffer0;
  }

  // End of RateTransition: '<Root>/Rate Transition7'

  // MATLABSystem: '<Root>/PX4 PWM Output' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion7'

  for (i = 0; i < 8; i++) {
    FLIGHT_hexacopter_B.pwmValue[i] = 0U;
  }

  FLIGHT_hexacopter_B.pwmValue[0] = static_cast<uint16_T>(FLIGHT_hexacopter_B.d <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-FLIGHT_hexacopter_B.d)))) : static_cast<int32_T>(
    static_cast<uint16_T>(FLIGHT_hexacopter_B.d)));
  FLIGHT_hexacopter_B.pwmValue[1] = static_cast<uint16_T>(FLIGHT_hexacopter_B.d1
    < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-FLIGHT_hexacopter_B.d1)))) : static_cast<int32_T>(
    static_cast<uint16_T>(FLIGHT_hexacopter_B.d1)));
  FLIGHT_hexacopter_B.pwmValue[2] = static_cast<uint16_T>(FLIGHT_hexacopter_B.d2
    < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-FLIGHT_hexacopter_B.d2)))) : static_cast<int32_T>(
    static_cast<uint16_T>(FLIGHT_hexacopter_B.d2)));
  FLIGHT_hexacopter_B.pwmValue[3] = static_cast<uint16_T>(FLIGHT_hexacopter_B.d3
    < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-FLIGHT_hexacopter_B.d3)))) : static_cast<int32_T>(
    static_cast<uint16_T>(FLIGHT_hexacopter_B.d3)));
  FLIGHT_hexacopter_B.pwmValue[4] = static_cast<uint16_T>(FLIGHT_hexacopter_B.d4
    < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-FLIGHT_hexacopter_B.d4)))) : static_cast<int32_T>(
    static_cast<uint16_T>(FLIGHT_hexacopter_B.d4)));
  FLIGHT_hexacopter_B.pwmValue[5] = static_cast<uint16_T>(FLIGHT_hexacopter_B.u0
    < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-FLIGHT_hexacopter_B.u0)))) : static_cast<int32_T>(
    static_cast<uint16_T>(FLIGHT_hexacopter_B.u0)));
  if (FLIGHT_hexacopter_B.rate_transition_arm) {
    if (!FLIGHT_hexacopter_DW.obj_dl.isArmed) {
      FLIGHT_hexacopter_DW.obj_dl.isArmed = true;
      pwm_arm(&FLIGHT_hexacopter_DW.obj_dl.armAdvertiseObj);
    }

    pwm_setServo(FLIGHT_hexacopter_DW.obj_dl.servoCount,
                 FLIGHT_hexacopter_DW.obj_dl.channelMask,
                 &FLIGHT_hexacopter_B.pwmValue[0],
                 FLIGHT_hexacopter_DW.obj_dl.isMain,
                 &FLIGHT_hexacopter_DW.obj_dl.actuatorAdvertiseObj);
  } else {
    pwm_disarm(&FLIGHT_hexacopter_DW.obj_dl.armAdvertiseObj);
    FLIGHT_hexacopter_DW.obj_dl.isArmed = false;
    pwm_resetServo(FLIGHT_hexacopter_DW.obj_dl.servoCount,
                   FLIGHT_hexacopter_DW.obj_dl.isMain,
                   &FLIGHT_hexacopter_DW.obj_dl.actuatorAdvertiseObj);
  }

  if (FLIGHT_hexacopter_DW.obj_dl.isMain) {
    if (FLIGHT_hexacopter_B.RateTransition7) {
      pwm_disarm(&FLIGHT_hexacopter_DW.obj_dl.armAdvertiseObj);
    } else {
      pwm_arm(&FLIGHT_hexacopter_DW.obj_dl.armAdvertiseObj);
    }
  }

  // End of MATLABSystem: '<Root>/PX4 PWM Output'
  FLIGHT_hexac_PX4Timestamp_o(&FLIGHT_hexacopter_B.PX4Timestamp_n);
  FLIGHT_hexac_PX4Timestamp_o(&FLIGHT_hexacopter_B.PX4Timestamp_p);

  // BusAssignment: '<S494>/Bus Assignment' incorporates:
  //   Constant: '<S493>/Constant'
  //   Gain: '<S493>/Gain'
  //   MATLABSystem: '<S15>/PX4 Timestamp'
  //   MATLABSystem: '<S494>/PX4 Timestamp'
  //   Saturate: '<S493>/Saturation'
  //   Sum: '<S493>/Subtract'

  FLIGHT_hexacopter_B.BusAssignment.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_n.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment.timestamp_sample =
    FLIGHT_hexacopter_B.PX4Timestamp_p.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment.reversible_flags = 0U;
  for (i = 0; i < 6; i++) {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Output_Limits1[i];

    // Saturate: '<S493>/Saturation'
    if (FLIGHT_hexacopter_B.ParamStep_c >
        FLIGHT_hexacopter_P.Saturation_UpperSat_ep) {
      rtb_d = FLIGHT_hexacopter_P.Saturation_UpperSat_ep;
    } else if (FLIGHT_hexacopter_B.ParamStep_c <
               FLIGHT_hexacopter_P.Saturation_LowerSat_p) {
      rtb_d = FLIGHT_hexacopter_P.Saturation_LowerSat_p;
    } else {
      rtb_d = static_cast<real32_T>(FLIGHT_hexacopter_B.ParamStep_c);
    }

    FLIGHT_hexacopter_B.BusAssignment.control[i] = (rtb_d -
      FLIGHT_hexacopter_P.Constant_Value_e) * FLIGHT_hexacopter_P.Gain_Gain_mg;

    // Saturate: '<S493>/Saturation' incorporates:
    //   Constant: '<S15>/Constant1'
    //   Constant: '<S493>/Constant'
    //   Gain: '<S493>/Gain'
    //   Sum: '<S493>/Subtract'

    rtb_Product2_a = FLIGHT_hexacopter_P.Constant1_Value_i[i];
    if (rtb_Product2_a > FLIGHT_hexacopter_P.Saturation_UpperSat_ep) {
      rtb_Product2_a = FLIGHT_hexacopter_P.Saturation_UpperSat_ep;
    } else if (rtb_Product2_a < FLIGHT_hexacopter_P.Saturation_LowerSat_p) {
      rtb_Product2_a = FLIGHT_hexacopter_P.Saturation_LowerSat_p;
    }

    FLIGHT_hexacopter_B.BusAssignment.control[i + 6] = (rtb_Product2_a -
      FLIGHT_hexacopter_P.Constant_Value_e) * FLIGHT_hexacopter_P.Gain_Gain_mg;
    FLIGHT_hexacopter_B.BusAssignment._padding0[i] = 0U;
  }

  // End of BusAssignment: '<S494>/Bus Assignment'

  // MATLABSystem: '<S496>/SinkBlock' incorporates:
  //   BusAssignment: '<S494>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_hf.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_hf.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment);
  FLIGHT_hexac_PX4Timestamp_o(&FLIGHT_hexacopter_B.PX4Timestamp_o);

  // BusAssignment: '<S490>/Bus Assignment' incorporates:
  //   MATLABSystem: '<S490>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment_gi.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_o.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment_gi.control_power[0] = 0.0F;
  FLIGHT_hexacopter_B.BusAssignment_gi.control_power[1] =
    FLIGHT_hexacopter_B.Sum5;
  FLIGHT_hexacopter_B.BusAssignment_gi.control_power[2] =
    FLIGHT_hexacopter_B.Sum;
  FLIGHT_hexacopter_B.BusAssignment_gi._padding0[0] = 0U;
  FLIGHT_hexacopter_B.BusAssignment_gi._padding0[1] = 0U;
  FLIGHT_hexacopter_B.BusAssignment_gi._padding0[2] = 0U;
  FLIGHT_hexacopter_B.BusAssignment_gi._padding0[3] = 0U;

  // MATLABSystem: '<S492>/SinkBlock' incorporates:
  //   BusAssignment: '<S490>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_jk.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_jk.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_gi);

  // RateTransition: '<Root>/Rate Transition'
  if (FLIGHT_hexacopter_M->Timing.RateInteraction.TID0_1) {
    FLIGHT_hexacopter_DW.RateTransition_Buffer[0] =
      FLIGHT_hexacopter_B.In1_h.xyz[0];
    FLIGHT_hexacopter_DW.RateTransition_Buffer[1] =
      FLIGHT_hexacopter_B.In1_h.xyz[1];
    FLIGHT_hexacopter_DW.RateTransition_Buffer[2] =
      FLIGHT_hexacopter_B.In1_h.xyz[2];
  }

  // End of RateTransition: '<Root>/Rate Transition'
}

// Model step function for TID1
void FLIGHT_hexacopter_step1(void)     // Sample time: [0.004s, 0.0s]
{
  real32_T rtb_Gain_f;
  real32_T rtb_Gain_p;
  real32_T rtb_PProdOut_ev_idx_0;
  real32_T rtb_PProdOut_ev_idx_1;
  real32_T rtb_Product5_dr;
  real32_T rtb_Product5_e;
  real32_T rtb_Product5_k;
  real32_T rtb_Product5_m;
  real32_T rtb_Saturation1;
  real32_T rtb_SinCos_o2;
  real32_T rtb_des_x;
  real32_T rtb_des_z;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T rtb_NOT;
  boolean_T rtb_NOT_h;
  boolean_T rtb_flag_pos;

  // MATLABSystem: '<S306>/SourceBlock'
  rtb_flag_pos = uORB_read_step(FLIGHT_hexacopter_DW.obj_n2.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_n2.eventStructObj, &FLIGHT_hexacopter_B.r2, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S306>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S307>/Enable'

  // Start for MATLABSystem: '<S306>/SourceBlock'
  if (rtb_flag_pos) {
    // SignalConversion generated from: '<S307>/In1'
    FLIGHT_hexacopter_B.In1_i = FLIGHT_hexacopter_B.r2;
  }

  // End of Outputs for SubSystem: '<S306>/Enabled Subsystem'

  // RateTransition: '<Root>/Rate Transition4'
  FLIGHT_hexacopter_DW.RateTransition4_Buffer0 =
    FLIGHT_hexacopter_B.In1_i.values[7];

  // RateTransition: '<Root>/rate_transition_ctrl_sw'
  FLIGHT_hexacopter_DW.rate_transition_ctrl_sw_Buffer0 =
    FLIGHT_hexacopter_B.In1_i.values[9];

  // MATLABSystem: '<S304>/SourceBlock'
  rtb_flag_pos = uORB_read_step(FLIGHT_hexacopter_DW.obj_ab.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_ab.eventStructObj, &FLIGHT_hexacopter_B.r1, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S304>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S305>/Enable'

  // Start for MATLABSystem: '<S304>/SourceBlock'
  if (rtb_flag_pos) {
    // SignalConversion generated from: '<S305>/In1'
    FLIGHT_hexacopter_B.In1_k = FLIGHT_hexacopter_B.r1;
  }

  // End of Outputs for SubSystem: '<S304>/Enabled Subsystem'

  // MATLAB Function: '<Root>/quat2eul'
  //  Quaternion conversion to Euler angles based on the PX4 Firmware v1.10.2
  //  release.
  FLIGHT_hexacopter_B.ypr[1] = static_cast<real32_T>(asin(static_cast<real_T>
    ((FLIGHT_hexacopter_B.In1_k.q[1] * FLIGHT_hexacopter_B.In1_k.q[3] -
      FLIGHT_hexacopter_B.In1_k.q[0] * FLIGHT_hexacopter_B.In1_k.q[2]) * -2.0F)));
  FLIGHT_hexacopter_B.ypr[2] = rt_atan2f_snf((FLIGHT_hexacopter_B.In1_k.q[0] *
    FLIGHT_hexacopter_B.In1_k.q[1] + FLIGHT_hexacopter_B.In1_k.q[2] *
    FLIGHT_hexacopter_B.In1_k.q[3]) * 2.0F, ((FLIGHT_hexacopter_B.In1_k.q[0] *
    FLIGHT_hexacopter_B.In1_k.q[0] - FLIGHT_hexacopter_B.In1_k.q[1] *
    FLIGHT_hexacopter_B.In1_k.q[1]) - FLIGHT_hexacopter_B.In1_k.q[2] *
    FLIGHT_hexacopter_B.In1_k.q[2]) + FLIGHT_hexacopter_B.In1_k.q[3] *
    FLIGHT_hexacopter_B.In1_k.q[3]);

  // MATLABSystem: '<S500>/SourceBlock'
  rtb_flag_pos = uORB_read_step(FLIGHT_hexacopter_DW.obj_hm.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_hm.eventStructObj, &FLIGHT_hexacopter_B.r5, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S500>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S502>/Enable'

  // Start for MATLABSystem: '<S500>/SourceBlock'
  if (rtb_flag_pos) {
    // SignalConversion generated from: '<S502>/In1'
    FLIGHT_hexacopter_B.In1_n = FLIGHT_hexacopter_B.r5;
  }

  // End of Outputs for SubSystem: '<S500>/Enabled Subsystem'

  // Outputs for Atomic SubSystem: '<Root>/Stabilized_Mode'
  // Gain: '<S12>/Gain' incorporates:
  //   Constant: '<S12>/Constant'
  //   Sum: '<S12>/Sum'

  FLIGHT_hexacopter_B.Product5_l = static_cast<real32_T>((static_cast<real_T>
    (FLIGHT_hexacopter_B.In1_i.values[2]) - FLIGHT_hexacopter_P.Constant_Value_c)
    * FLIGHT_hexacopter_P.Gain_Gain);

  // DeadZone: '<S12>/Dead Zone3'
  if (FLIGHT_hexacopter_B.Product5_l > FLIGHT_hexacopter_P.DeadZone3_End_l) {
    rtb_Product5_m = FLIGHT_hexacopter_B.Product5_l -
      FLIGHT_hexacopter_P.DeadZone3_End_l;
  } else if (FLIGHT_hexacopter_B.Product5_l >=
             FLIGHT_hexacopter_P.DeadZone3_Start_p) {
    rtb_Product5_m = 0.0F;
  } else {
    rtb_Product5_m = FLIGHT_hexacopter_B.Product5_l -
      FLIGHT_hexacopter_P.DeadZone3_Start_p;
  }

  // End of DeadZone: '<S12>/Dead Zone3'

  // Gain: '<S12>/Gain2' incorporates:
  //   Constant: '<S12>/Constant1'
  //   Sum: '<S12>/Sum1'

  FLIGHT_hexacopter_B.Product5_l = (static_cast<real32_T>
    (FLIGHT_hexacopter_B.In1_i.values[3]) -
    FLIGHT_hexacopter_P.Constant1_Value_l) * FLIGHT_hexacopter_P.Gain2_Gain_a;

  // DeadZone: '<S12>/Dead Zone2'
  if (FLIGHT_hexacopter_B.Product5_l > FLIGHT_hexacopter_P.DeadZone2_End) {
    rtb_Product5_e = FLIGHT_hexacopter_B.Product5_l -
      FLIGHT_hexacopter_P.DeadZone2_End;
  } else if (FLIGHT_hexacopter_B.Product5_l >=
             FLIGHT_hexacopter_P.DeadZone2_Start) {
    rtb_Product5_e = 0.0F;
  } else {
    rtb_Product5_e = FLIGHT_hexacopter_B.Product5_l -
      FLIGHT_hexacopter_P.DeadZone2_Start;
  }

  // End of DeadZone: '<S12>/Dead Zone2'

  // Gain: '<S12>/Gain1' incorporates:
  //   Constant: '<S12>/Constant2'
  //   Sum: '<S12>/Sum2'

  FLIGHT_hexacopter_B.Product5_l = (static_cast<real32_T>
    (FLIGHT_hexacopter_B.In1_i.values[1]) -
    FLIGHT_hexacopter_P.Constant2_Value_i) * FLIGHT_hexacopter_P.Gain1_Gain_m;

  // DeadZone: '<S12>/Dead Zone1'
  if (FLIGHT_hexacopter_B.Product5_l > FLIGHT_hexacopter_P.DeadZone1_End_m) {
    rtb_Product5_dr = FLIGHT_hexacopter_B.Product5_l -
      FLIGHT_hexacopter_P.DeadZone1_End_m;
  } else if (FLIGHT_hexacopter_B.Product5_l >=
             FLIGHT_hexacopter_P.DeadZone1_Start_c) {
    rtb_Product5_dr = 0.0F;
  } else {
    rtb_Product5_dr = FLIGHT_hexacopter_B.Product5_l -
      FLIGHT_hexacopter_P.DeadZone1_Start_c;
  }

  // End of DeadZone: '<S12>/Dead Zone1'

  // Gain: '<S12>/Gain3' incorporates:
  //   Constant: '<S12>/Constant3'
  //   Sum: '<S12>/Sum3'

  FLIGHT_hexacopter_B.Product5_l = (static_cast<real32_T>
    (FLIGHT_hexacopter_B.In1_i.values[0]) -
    FLIGHT_hexacopter_P.Constant3_Value_e) * FLIGHT_hexacopter_P.Gain3_Gain;

  // DeadZone: '<S12>/Dead Zone'
  if (FLIGHT_hexacopter_B.Product5_l > FLIGHT_hexacopter_P.DeadZone_End) {
    rtb_Product5_k = FLIGHT_hexacopter_B.Product5_l -
      FLIGHT_hexacopter_P.DeadZone_End;
  } else if (FLIGHT_hexacopter_B.Product5_l >=
             FLIGHT_hexacopter_P.DeadZone_Start) {
    rtb_Product5_k = 0.0F;
  } else {
    rtb_Product5_k = FLIGHT_hexacopter_B.Product5_l -
      FLIGHT_hexacopter_P.DeadZone_Start;
  }

  // End of DeadZone: '<S12>/Dead Zone'
  // End of Outputs for SubSystem: '<Root>/Stabilized_Mode'

  // Outputs for Atomic SubSystem: '<Root>/If Action Subsystem'
  // Fcn: '<S22>/Fcn2' incorporates:
  //   DataTypeConversion: '<S22>/Data Type Conversion1'
  //   Fcn: '<S192>/Fcn2'

  FLIGHT_hexacopter_B.ctoc = (static_cast<real32_T>
    (FLIGHT_hexacopter_B.In1_i.values[0]) - 1514.0F) / 500.0F;

  // End of Outputs for SubSystem: '<Root>/If Action Subsystem'

  // DeadZone: '<S22>/Dead Zone3' incorporates:
  //   Fcn: '<S22>/Fcn2'

  if (FLIGHT_hexacopter_B.ctoc > FLIGHT_hexacopter_P.DeadZone3_End_n) {
    rtb_Gain_p = FLIGHT_hexacopter_B.ctoc - FLIGHT_hexacopter_P.DeadZone3_End_n;
  } else if (FLIGHT_hexacopter_B.ctoc >= FLIGHT_hexacopter_P.DeadZone3_Start_l)
  {
    rtb_Gain_p = 0.0F;
  } else {
    rtb_Gain_p = FLIGHT_hexacopter_B.ctoc -
      FLIGHT_hexacopter_P.DeadZone3_Start_l;
  }

  // End of DeadZone: '<S22>/Dead Zone3'

  // Outputs for Atomic SubSystem: '<Root>/If Action Subsystem'
  // Fcn: '<S22>/Fcn1' incorporates:
  //   DataTypeConversion: '<S22>/Data Type Conversion2'
  //   Fcn: '<S192>/Fcn1'

  FLIGHT_hexacopter_B.cfromc = (static_cast<real32_T>
    (FLIGHT_hexacopter_B.In1_i.values[1]) - 1514.0F) / 500.0F;

  // End of Outputs for SubSystem: '<Root>/If Action Subsystem'

  // DeadZone: '<S22>/Dead Zone1' incorporates:
  //   Fcn: '<S22>/Fcn1'

  if (FLIGHT_hexacopter_B.cfromc > FLIGHT_hexacopter_P.DeadZone1_End_mj) {
    rtb_Gain_f = FLIGHT_hexacopter_B.cfromc -
      FLIGHT_hexacopter_P.DeadZone1_End_mj;
  } else if (FLIGHT_hexacopter_B.cfromc >= FLIGHT_hexacopter_P.DeadZone1_Start_n)
  {
    rtb_Gain_f = 0.0F;
  } else {
    rtb_Gain_f = FLIGHT_hexacopter_B.cfromc -
      FLIGHT_hexacopter_P.DeadZone1_Start_n;
  }

  // End of DeadZone: '<S22>/Dead Zone1'

  // Fcn: '<S22>/Fcn7' incorporates:
  //   DataTypeConversion: '<S22>/Data Type Conversion10'

  FLIGHT_hexacopter_B.Gain_i = (static_cast<real32_T>
    (FLIGHT_hexacopter_B.In1_i.values[3]) - 1514.0F) / 500.0F;

  // DeadZone: '<S22>/Dead Zone2'
  if (FLIGHT_hexacopter_B.Gain_i > FLIGHT_hexacopter_P.DeadZone2_End_b) {
    FLIGHT_hexacopter_B.Product5_l = FLIGHT_hexacopter_B.Gain_i -
      FLIGHT_hexacopter_P.DeadZone2_End_b;
  } else if (FLIGHT_hexacopter_B.Gain_i >= FLIGHT_hexacopter_P.DeadZone2_Start_m)
  {
    FLIGHT_hexacopter_B.Product5_l = 0.0F;
  } else {
    FLIGHT_hexacopter_B.Product5_l = FLIGHT_hexacopter_B.Gain_i -
      FLIGHT_hexacopter_P.DeadZone2_Start_m;
  }

  // End of DeadZone: '<S22>/Dead Zone2'

  // Saturate: '<S22>/Saturation3'
  if (FLIGHT_hexacopter_B.Product5_l >
      FLIGHT_hexacopter_P.Saturation3_UpperSat_d) {
    FLIGHT_hexacopter_B.Product5_l = FLIGHT_hexacopter_P.Saturation3_UpperSat_d;
  } else if (FLIGHT_hexacopter_B.Product5_l <
             FLIGHT_hexacopter_P.Saturation3_LowerSat_n) {
    FLIGHT_hexacopter_B.Product5_l = FLIGHT_hexacopter_P.Saturation3_LowerSat_n;
  }

  // Gain: '<S22>/Gain3' incorporates:
  //   Saturate: '<S22>/Saturation3'

  FLIGHT_hexacopter_B.Gain3 = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_RATE_Y *
    FLIGHT_hexacopter_B.Product5_l;

  // Fcn: '<S22>/Fcn3' incorporates:
  //   DataTypeConversion: '<S22>/Data Type Conversion11'

  FLIGHT_hexacopter_B.Gain_i = (static_cast<real32_T>
    (FLIGHT_hexacopter_B.In1_i.values[2]) - 1514.0F) / 500.0F;

  // DeadZone: '<S22>/Dead Zone4'
  if (FLIGHT_hexacopter_B.Gain_i > FLIGHT_hexacopter_P.DeadZone4_End) {
    FLIGHT_hexacopter_B.Product5_l = FLIGHT_hexacopter_B.Gain_i -
      FLIGHT_hexacopter_P.DeadZone4_End;
  } else if (FLIGHT_hexacopter_B.Gain_i >= FLIGHT_hexacopter_P.DeadZone4_Start)
  {
    FLIGHT_hexacopter_B.Product5_l = 0.0F;
  } else {
    FLIGHT_hexacopter_B.Product5_l = FLIGHT_hexacopter_B.Gain_i -
      FLIGHT_hexacopter_P.DeadZone4_Start;
  }

  // End of DeadZone: '<S22>/Dead Zone4'

  // Saturate: '<S22>/Saturation10'
  if (FLIGHT_hexacopter_B.Product5_l > FLIGHT_hexacopter_P.Saturation10_UpperSat)
  {
    FLIGHT_hexacopter_B.Product5_l = FLIGHT_hexacopter_P.Saturation10_UpperSat;
  } else if (FLIGHT_hexacopter_B.Product5_l <
             FLIGHT_hexacopter_P.Saturation10_LowerSat) {
    FLIGHT_hexacopter_B.Product5_l = FLIGHT_hexacopter_P.Saturation10_LowerSat;
  }

  // Gain: '<S22>/Gain' incorporates:
  //   Saturate: '<S22>/Saturation10'

  FLIGHT_hexacopter_B.Gain_i = FLIGHT_hexacopter_P.Gain_Gain_er *
    FLIGHT_hexacopter_B.Product5_l;

  // MATLABSystem: '<S301>/SourceBlock'
  rtb_flag_pos = uORB_read_step(FLIGHT_hexacopter_DW.obj_kk.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_kk.eventStructObj, &FLIGHT_hexacopter_B.r, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S301>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S303>/Enable'

  // Start for MATLABSystem: '<S301>/SourceBlock'
  if (rtb_flag_pos) {
    // SignalConversion generated from: '<S303>/In1'
    FLIGHT_hexacopter_B.In1 = FLIGHT_hexacopter_B.r;
  }

  // End of Outputs for SubSystem: '<S301>/Enabled Subsystem'

  // Gain: '<S1>/Gain' incorporates:
  //   Sum: '<S1>/Sum3'

  FLIGHT_hexacopter_B.IProdOut_d = (FLIGHT_hexacopter_B.Gain_i -
    FLIGHT_hexacopter_B.In1.vz) * FLIGHT_hexacopter_P.Gain_Gain_o;

  // MATLABSystem: '<S1>/Read Parameter2'
  if (FLIGHT_hexacopter_DW.obj_in.SampleTime != FLIGHT_hexacopter_P.SampleTime)
  {
    FLIGHT_hexacopter_DW.obj_in.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_in.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_hexacopter_B.ParamStep = 0.0F;
  }

  // Outputs for Atomic SubSystem: '<Root>/If Action Subsystem'
  // Logic: '<S1>/AND' incorporates:
  //   Logic: '<S5>/AND'

  rtb_NOT_h = !FLIGHT_hexacopter_B.In1_n.armed;

  // End of Outputs for SubSystem: '<Root>/If Action Subsystem'

  // Logic: '<S1>/NOT' incorporates:
  //   Constant: '<S23>/Constant'
  //   Logic: '<S1>/AND'
  //   RelationalOperator: '<S23>/Compare'

  rtb_NOT = (rtb_NOT_h || (FLIGHT_hexacopter_B.In1_i.values[5] <=
              FLIGHT_hexacopter_P.CompareToConstant1_const));

  // DiscreteIntegrator: '<S60>/Integrator'
  if (rtb_NOT || (FLIGHT_hexacopter_DW.Integrator_PrevResetState != 0)) {
    FLIGHT_hexacopter_DW.Integrator_DSTATE =
      FLIGHT_hexacopter_P.PIDController_InitialConditio_a;
  }

  // MATLABSystem: '<S1>/Read Parameter4'
  if (FLIGHT_hexacopter_DW.obj_lx.SampleTime != FLIGHT_hexacopter_P.SampleTime)
  {
    FLIGHT_hexacopter_DW.obj_lx.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_lx.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep_m);
  if (rtb_flag_pos) {
    FLIGHT_hexacopter_B.ParamStep_m = 0.0F;
  }

  // DiscreteIntegrator: '<S55>/Filter'
  if (rtb_NOT || (FLIGHT_hexacopter_DW.Filter_PrevResetState != 0)) {
    FLIGHT_hexacopter_DW.Filter_DSTATE =
      FLIGHT_hexacopter_P.PIDController_InitialConditionF;
  }

  // Product: '<S63>/NProd Out' incorporates:
  //   Constant: '<S1>/Constant'
  //   DiscreteIntegrator: '<S55>/Filter'
  //   MATLABSystem: '<S1>/Read Parameter4'
  //   Product: '<S53>/DProd Out'
  //   Sum: '<S55>/SumD'
  //
  FLIGHT_hexacopter_B.NProdOut = (FLIGHT_hexacopter_B.IProdOut_d *
    FLIGHT_hexacopter_B.ParamStep_m - FLIGHT_hexacopter_DW.Filter_DSTATE) *
    FLIGHT_hexacopter_P.Constant_Value_gx;

  // Sum: '<S69>/Sum' incorporates:
  //   DiscreteIntegrator: '<S60>/Integrator'
  //   MATLABSystem: '<S1>/Read Parameter2'
  //   Product: '<S65>/PProd Out'
  //
  FLIGHT_hexacopter_B.DeadZone = (FLIGHT_hexacopter_B.IProdOut_d *
    FLIGHT_hexacopter_B.ParamStep + FLIGHT_hexacopter_DW.Integrator_DSTATE) +
    FLIGHT_hexacopter_B.NProdOut;

  // MATLABSystem: '<S1>/Read Parameter1'
  if (FLIGHT_hexacopter_DW.obj_m.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj_m.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_m.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_hexacopter_B.ParamStep = 0.0F;
  }

  // Saturate: '<S67>/Saturation'
  if (FLIGHT_hexacopter_B.DeadZone >
      FLIGHT_hexacopter_P.PIDController_UpperSaturationLi) {
    FLIGHT_hexacopter_B.Product5_l =
      FLIGHT_hexacopter_P.PIDController_UpperSaturationLi;
  } else if (FLIGHT_hexacopter_B.DeadZone <
             FLIGHT_hexacopter_P.PIDController_LowerSaturationLi) {
    FLIGHT_hexacopter_B.Product5_l =
      FLIGHT_hexacopter_P.PIDController_LowerSaturationLi;
  } else {
    FLIGHT_hexacopter_B.Product5_l = FLIGHT_hexacopter_B.DeadZone;
  }

  // Sum: '<S1>/Sum6' incorporates:
  //   MATLABSystem: '<S1>/Read Parameter1'
  //   Saturate: '<S67>/Saturation'
  //
  rtb_Saturation1 = FLIGHT_hexacopter_B.Product5_l +
    FLIGHT_hexacopter_B.ParamStep;

  // Saturate: '<S1>/Saturation1'
  if (rtb_Saturation1 > FLIGHT_hexacopter_P.Saturation1_UpperSat_lr) {
    rtb_Saturation1 = FLIGHT_hexacopter_P.Saturation1_UpperSat_lr;
  } else if (rtb_Saturation1 < FLIGHT_hexacopter_P.Saturation1_LowerSat_e) {
    rtb_Saturation1 = FLIGHT_hexacopter_P.Saturation1_LowerSat_e;
  }

  // End of Saturate: '<S1>/Saturation1'

  // Outputs for Atomic SubSystem: '<Root>/If Action Subsystem'
  // Trigonometry: '<S249>/SinCos'
  FLIGHT_hexacopter_B.Product5_l = static_cast<real32_T>(sin(static_cast<real_T>
    (FLIGHT_hexacopter_B.In1.heading)));
  rtb_SinCos_o2 = static_cast<real32_T>(cos(static_cast<real_T>
    (FLIGHT_hexacopter_B.In1.heading)));

  // MATLABSystem: '<S194>/Read Parameter'
  if (FLIGHT_hexacopter_DW.obj_eq.SampleTime != FLIGHT_hexacopter_P.SampleTime)
  {
    FLIGHT_hexacopter_DW.obj_eq.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_eq.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_hexacopter_B.ParamStep = 0.0F;
  }

  // Logic: '<S5>/NOT' incorporates:
  //   Constant: '<S193>/Constant'
  //   Logic: '<S5>/AND'
  //   RelationalOperator: '<S193>/Compare'

  rtb_NOT_h = (rtb_NOT_h || (FLIGHT_hexacopter_B.In1_i.values[5] <=
    FLIGHT_hexacopter_P.CompareToConstant2_const));

  // DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
  if (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l =
      FLIGHT_hexacopter_B.In1.x;
    if (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l >
        FLIGHT_hexacopter_P.DiscreteTimeIntegrator_UpperSat) {
      FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l =
        FLIGHT_hexacopter_P.DiscreteTimeIntegrator_UpperSat;
    } else if (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l <
               FLIGHT_hexacopter_P.DiscreteTimeIntegrator_LowerSat) {
      FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l =
        FLIGHT_hexacopter_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  if (rtb_NOT_h || (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_PrevRese != 0))
  {
    FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l =
      FLIGHT_hexacopter_B.In1.x;
    if (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l >
        FLIGHT_hexacopter_P.DiscreteTimeIntegrator_UpperSat) {
      FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l =
        FLIGHT_hexacopter_P.DiscreteTimeIntegrator_UpperSat;
    } else if (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l <
               FLIGHT_hexacopter_P.DiscreteTimeIntegrator_LowerSat) {
      FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l =
        FLIGHT_hexacopter_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  rtb_des_x = FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l;

  // DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'
  if (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE =
      FLIGHT_hexacopter_B.In1.y;
    if (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE >
        FLIGHT_hexacopter_P.DiscreteTimeIntegrator1_UpperSa) {
      FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE =
        FLIGHT_hexacopter_P.DiscreteTimeIntegrator1_UpperSa;
    } else if (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE <
               FLIGHT_hexacopter_P.DiscreteTimeIntegrator1_LowerSa) {
      FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE =
        FLIGHT_hexacopter_P.DiscreteTimeIntegrator1_LowerSa;
    }
  }

  if (rtb_NOT_h || (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_PrevRes != 0))
  {
    FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE =
      FLIGHT_hexacopter_B.In1.y;
    if (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE >
        FLIGHT_hexacopter_P.DiscreteTimeIntegrator1_UpperSa) {
      FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE =
        FLIGHT_hexacopter_P.DiscreteTimeIntegrator1_UpperSa;
    } else if (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE <
               FLIGHT_hexacopter_P.DiscreteTimeIntegrator1_LowerSa) {
      FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE =
        FLIGHT_hexacopter_P.DiscreteTimeIntegrator1_LowerSa;
    }
  }

  rtb_des_z = FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE;

  // Product: '<S235>/PProd Out' incorporates:
  //   DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'
  //   MATLABSystem: '<S194>/Read Parameter'
  //   Sum: '<S194>/Sum'
  //
  rtb_PProdOut_ev_idx_0 = (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l
    - FLIGHT_hexacopter_B.In1.x) * FLIGHT_hexacopter_B.ParamStep;
  rtb_PProdOut_ev_idx_1 = (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE -
    FLIGHT_hexacopter_B.In1.y) * FLIGHT_hexacopter_B.ParamStep;

  // MATLABSystem: '<S195>/Read Parameter'
  if (FLIGHT_hexacopter_DW.obj_pi.SampleTime != FLIGHT_hexacopter_P.SampleTime)
  {
    FLIGHT_hexacopter_DW.obj_pi.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_pi.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_hexacopter_B.ParamStep = 0.0F;
  }

  // Sum: '<S195>/Sum'
  FLIGHT_hexacopter_B.t = rtb_PProdOut_ev_idx_0 - FLIGHT_hexacopter_B.In1.vx;
  FLIGHT_hexacopter_B.mul = rtb_PProdOut_ev_idx_1 - FLIGHT_hexacopter_B.In1.vy;

  // Saturate: '<S195>/Saturation' incorporates:
  //   Gain: '<S249>/Gain'
  //   MATLABSystem: '<S195>/Read Parameter'
  //   Product: '<S247>/MatrixMultiply'
  //   Product: '<S288>/PProd Out'
  //   Reshape: '<S249>/Reshape'
  //   Reshape: '<S249>/Reshape1'
  //
  FLIGHT_hexacopter_B.ParamStep_m = (rtb_SinCos_o2 * FLIGHT_hexacopter_B.t +
    FLIGHT_hexacopter_B.Product5_l * FLIGHT_hexacopter_B.mul) *
    FLIGHT_hexacopter_B.ParamStep;
  rtb_SinCos_o2 = (FLIGHT_hexacopter_P.Gain_Gain_a *
                   FLIGHT_hexacopter_B.Product5_l * FLIGHT_hexacopter_B.t +
                   rtb_SinCos_o2 * FLIGHT_hexacopter_B.mul) *
    FLIGHT_hexacopter_B.ParamStep;

  // DeadZone: '<S192>/Dead Zone3'
  if (FLIGHT_hexacopter_B.ctoc > FLIGHT_hexacopter_P.DeadZone3_End) {
    FLIGHT_hexacopter_B.ParamStep = FLIGHT_hexacopter_B.ctoc -
      FLIGHT_hexacopter_P.DeadZone3_End;
  } else if (FLIGHT_hexacopter_B.ctoc >= FLIGHT_hexacopter_P.DeadZone3_Start) {
    FLIGHT_hexacopter_B.ParamStep = 0.0F;
  } else {
    FLIGHT_hexacopter_B.ParamStep = FLIGHT_hexacopter_B.ctoc -
      FLIGHT_hexacopter_P.DeadZone3_Start;
  }

  // End of DeadZone: '<S192>/Dead Zone3'

  // Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
  FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;

  // DeadZone: '<S192>/Dead Zone1'
  if (FLIGHT_hexacopter_B.cfromc > FLIGHT_hexacopter_P.DeadZone1_End) {
    FLIGHT_hexacopter_B.Product5_l = FLIGHT_hexacopter_B.cfromc -
      FLIGHT_hexacopter_P.DeadZone1_End;
  } else if (FLIGHT_hexacopter_B.cfromc >= FLIGHT_hexacopter_P.DeadZone1_Start)
  {
    FLIGHT_hexacopter_B.Product5_l = 0.0F;
  } else {
    FLIGHT_hexacopter_B.Product5_l = FLIGHT_hexacopter_B.cfromc -
      FLIGHT_hexacopter_P.DeadZone1_Start;
  }

  // End of DeadZone: '<S192>/Dead Zone1'

  // Saturate: '<S192>/Saturation1'
  if (FLIGHT_hexacopter_B.Product5_l > FLIGHT_hexacopter_P.Saturation1_UpperSat)
  {
    FLIGHT_hexacopter_B.Product5_l = FLIGHT_hexacopter_P.Saturation1_UpperSat;
  } else if (FLIGHT_hexacopter_B.Product5_l <
             FLIGHT_hexacopter_P.Saturation1_LowerSat) {
    FLIGHT_hexacopter_B.Product5_l = FLIGHT_hexacopter_P.Saturation1_LowerSat;
  }

  // Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S192>/Gain2'
  //   Saturate: '<S192>/Saturation1'

  FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l +=
    FLIGHT_hexacopter_P.Gain2_Gain * FLIGHT_hexacopter_B.Product5_l *
    FLIGHT_hexacopter_P.DiscreteTimeIntegrator_gainval;
  if (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l >
      FLIGHT_hexacopter_P.DiscreteTimeIntegrator_UpperSat) {
    FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l =
      FLIGHT_hexacopter_P.DiscreteTimeIntegrator_UpperSat;
  } else if (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l <
             FLIGHT_hexacopter_P.DiscreteTimeIntegrator_LowerSat) {
    FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE_l =
      FLIGHT_hexacopter_P.DiscreteTimeIntegrator_LowerSat;
  }

  FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_PrevRese = static_cast<int8_T>
    (rtb_NOT_h);

  // Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'
  FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

  // Saturate: '<S192>/Saturation9'
  if (FLIGHT_hexacopter_B.ParamStep > FLIGHT_hexacopter_P.Saturation9_UpperSat)
  {
    FLIGHT_hexacopter_B.ParamStep = FLIGHT_hexacopter_P.Saturation9_UpperSat;
  } else if (FLIGHT_hexacopter_B.ParamStep <
             FLIGHT_hexacopter_P.Saturation9_LowerSat) {
    FLIGHT_hexacopter_B.ParamStep = FLIGHT_hexacopter_P.Saturation9_LowerSat;
  }

  // Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
  //   Gain: '<S192>/Gain1'
  //   Saturate: '<S192>/Saturation9'

  FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE +=
    FLIGHT_hexacopter_P.MAX_CONTROL_VELOCITY_XY * FLIGHT_hexacopter_B.ParamStep *
    FLIGHT_hexacopter_P.DiscreteTimeIntegrator1_gainval;
  if (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE >
      FLIGHT_hexacopter_P.DiscreteTimeIntegrator1_UpperSa) {
    FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE =
      FLIGHT_hexacopter_P.DiscreteTimeIntegrator1_UpperSa;
  } else if (FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE <
             FLIGHT_hexacopter_P.DiscreteTimeIntegrator1_LowerSa) {
    FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_DSTATE =
      FLIGHT_hexacopter_P.DiscreteTimeIntegrator1_LowerSa;
  }

  FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_PrevRes = static_cast<int8_T>
    (rtb_NOT_h);

  // End of Outputs for SubSystem: '<Root>/If Action Subsystem'

  // MATLABSystem: '<S501>/SourceBlock'
  rtb_flag_pos = uORB_read_step(FLIGHT_hexacopter_DW.obj_bw.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_bw.eventStructObj, &FLIGHT_hexacopter_B.r3, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S501>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S503>/Enable'

  // Start for MATLABSystem: '<S501>/SourceBlock'
  if (rtb_flag_pos) {
    // SignalConversion generated from: '<S503>/In1'
    FLIGHT_hexacopter_B.In1_f = FLIGHT_hexacopter_B.r3;
  }

  // End of Outputs for SubSystem: '<S501>/Enabled Subsystem'

  // MATLAB Function: '<S18>/MATLAB Function'
  switch (FLIGHT_hexacopter_B.In1_f.nav_state) {
   case 1:
    //  ALT Mode
    rtb_flag_pos = false;
    rtb_NOT_h = true;
    break;

   case 2:
    //  POS Mode
    rtb_flag_pos = true;
    rtb_NOT_h = false;
    break;

   default:
    //  STAB mode
    rtb_flag_pos = false;
    rtb_NOT_h = false;
    break;
  }

  // End of MATLAB Function: '<S18>/MATLAB Function'

  // Outputs for Atomic SubSystem: '<Root>/If Action Subsystem'
  // Saturate: '<S195>/Saturation'
  if (rtb_SinCos_o2 > FLIGHT_hexacopter_P.Saturation_UpperSat_e) {
    // SignalConversion generated from: '<S6>/ SFunction ' incorporates:
    //   MATLAB Function: '<Root>/MATLAB Function'

    rtb_SinCos_o2 = FLIGHT_hexacopter_P.Saturation_UpperSat_e;
  } else if (rtb_SinCos_o2 < FLIGHT_hexacopter_P.Saturation_LowerSat_a) {
    // SignalConversion generated from: '<S6>/ SFunction ' incorporates:
    //   MATLAB Function: '<Root>/MATLAB Function'

    rtb_SinCos_o2 = FLIGHT_hexacopter_P.Saturation_LowerSat_a;
  }

  if (FLIGHT_hexacopter_B.ParamStep_m >
      FLIGHT_hexacopter_P.Saturation_UpperSat_e) {
    FLIGHT_hexacopter_B.ParamStep_m = FLIGHT_hexacopter_P.Saturation_UpperSat_e;
  } else if (FLIGHT_hexacopter_B.ParamStep_m <
             FLIGHT_hexacopter_P.Saturation_LowerSat_a) {
    FLIGHT_hexacopter_B.ParamStep_m = FLIGHT_hexacopter_P.Saturation_LowerSat_a;
  }

  // SignalConversion generated from: '<S6>/ SFunction ' incorporates:
  //   Gain: '<S195>/Gain1'
  //   MATLAB Function: '<Root>/MATLAB Function'
  //   Saturate: '<S195>/Saturation'

  FLIGHT_hexacopter_B.Product5_l = FLIGHT_hexacopter_P.Gain1_Gain_i *
    FLIGHT_hexacopter_B.ParamStep_m;

  // End of Outputs for SubSystem: '<Root>/If Action Subsystem'

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   Gain: '<S12>/Gain4'
  //   Gain: '<S12>/Gain5'
  //   Gain: '<S12>/Gain6'
  //   Gain: '<S22>/Gain1'
  //   Gain: '<S22>/Gain2'
  //   Saturate: '<S12>/Saturation1'
  //   Saturate: '<S12>/Saturation2'
  //   Saturate: '<S12>/Saturation3'
  //   Saturate: '<S22>/Saturation1'
  //   Saturate: '<S22>/Saturation9'

  if ((FLIGHT_hexacopter_B.In1_i.values[5] < 1800) || (!rtb_flag_pos)) {
    if ((FLIGHT_hexacopter_B.In1_i.values[5] < 1800) &&
        (FLIGHT_hexacopter_B.In1_i.values[5] >= 1400) && rtb_NOT_h) {
      // Saturate: '<S22>/Saturation9'
      //  Altitude
      if (rtb_Gain_p > FLIGHT_hexacopter_P.Saturation9_UpperSat_c) {
        rtb_Gain_p = FLIGHT_hexacopter_P.Saturation9_UpperSat_c;
      } else if (rtb_Gain_p < FLIGHT_hexacopter_P.Saturation9_LowerSat_i) {
        rtb_Gain_p = FLIGHT_hexacopter_P.Saturation9_LowerSat_i;
      }

      rtb_SinCos_o2 = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_ROLL * rtb_Gain_p;

      // Saturate: '<S22>/Saturation1' incorporates:
      //   Gain: '<S22>/Gain1'
      //   Saturate: '<S22>/Saturation9'

      if (rtb_Gain_f > FLIGHT_hexacopter_P.Saturation1_UpperSat_d) {
        rtb_Gain_f = FLIGHT_hexacopter_P.Saturation1_UpperSat_d;
      } else if (rtb_Gain_f < FLIGHT_hexacopter_P.Saturation1_LowerSat_b) {
        rtb_Gain_f = FLIGHT_hexacopter_P.Saturation1_LowerSat_b;
      }

      FLIGHT_hexacopter_B.Product5_l =
        FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_PITCH * rtb_Gain_f;
    } else {
      // Outputs for Atomic SubSystem: '<Root>/Stabilized_Mode'
      // Saturate: '<S12>/Saturation3'
      //  Stablized
      if (rtb_Product5_k > FLIGHT_hexacopter_P.Saturation3_UpperSat) {
        rtb_Product5_k = FLIGHT_hexacopter_P.Saturation3_UpperSat;
      } else if (rtb_Product5_k < FLIGHT_hexacopter_P.Saturation3_LowerSat) {
        rtb_Product5_k = FLIGHT_hexacopter_P.Saturation3_LowerSat;
      }

      rtb_SinCos_o2 = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_ROLL *
        rtb_Product5_k;

      // Saturate: '<S12>/Saturation2' incorporates:
      //   Gain: '<S12>/Gain4'
      //   Saturate: '<S12>/Saturation3'

      if (rtb_Product5_dr > FLIGHT_hexacopter_P.Saturation2_UpperSat) {
        rtb_Product5_dr = FLIGHT_hexacopter_P.Saturation2_UpperSat;
      } else if (rtb_Product5_dr < FLIGHT_hexacopter_P.Saturation2_LowerSat) {
        rtb_Product5_dr = FLIGHT_hexacopter_P.Saturation2_LowerSat;
      }

      FLIGHT_hexacopter_B.Product5_l =
        FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_PITCH * rtb_Product5_dr;

      // Saturate: '<S12>/Saturation1' incorporates:
      //   Gain: '<S12>/Gain5'
      //   Saturate: '<S12>/Saturation2'

      if (rtb_Product5_e > FLIGHT_hexacopter_P.Saturation1_UpperSat_l) {
        rtb_Product5_e = FLIGHT_hexacopter_P.Saturation1_UpperSat_l;
      } else if (rtb_Product5_e < FLIGHT_hexacopter_P.Saturation1_LowerSat_i) {
        rtb_Product5_e = FLIGHT_hexacopter_P.Saturation1_LowerSat_i;
      }

      FLIGHT_hexacopter_B.Gain3 = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_RATE_Y *
        rtb_Product5_e;

      // Saturate: '<S12>/Saturation' incorporates:
      //   Gain: '<S12>/Gain6'
      //   Saturate: '<S12>/Saturation1'

      if (rtb_Product5_m > FLIGHT_hexacopter_P.Saturation_UpperSat_o) {
        rtb_Saturation1 = FLIGHT_hexacopter_P.Saturation_UpperSat_o;
      } else if (rtb_Product5_m < FLIGHT_hexacopter_P.Saturation_LowerSat_el) {
        rtb_Saturation1 = FLIGHT_hexacopter_P.Saturation_LowerSat_el;
      } else {
        rtb_Saturation1 = rtb_Product5_m;
      }

      // End of Saturate: '<S12>/Saturation'
      // End of Outputs for SubSystem: '<Root>/Stabilized_Mode'
    }
  } else {
    //  position
  }

  // RelationalOperator: '<S183>/Compare' incorporates:
  //   Constant: '<S183>/Constant'

  rtb_NOT_h = (FLIGHT_hexacopter_B.In1_i.values[6] >=
               FLIGHT_hexacopter_P.CompareToConstant1_const_e);
  FLIGHT_hexacop_PX4Timestamp(&FLIGHT_hexacopter_B.PX4Timestamp);

  // MATLABSystem: '<S3>/Read Parameter1'
  if (FLIGHT_hexacopter_DW.obj_ct.SampleTime != FLIGHT_hexacopter_P.SampleTime)
  {
    FLIGHT_hexacopter_DW.obj_ct.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_ct.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_hexacopter_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S3>/Read Parameter'
  if (FLIGHT_hexacopter_DW.obj_cf.SampleTime != FLIGHT_hexacopter_P.SampleTime)
  {
    FLIGHT_hexacopter_DW.obj_cf.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_cf.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep_m);
  if (rtb_flag_pos) {
    FLIGHT_hexacopter_B.ParamStep_m = 0.0F;
  }

  // MATLABSystem: '<S3>/Read Parameter2'
  if (FLIGHT_hexacopter_DW.obj_l.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj_l.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_l.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_hexacopter_B.ParamStep_k);
  if (rtb_flag_pos) {
    FLIGHT_hexacopter_B.ParamStep_k = 0;
  }

  // MATLAB Function: '<S3>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion'
  //   DataTypeConversion: '<S3>/Data Type Conversion1'
  //   DataTypeConversion: '<S3>/Data Type Conversion2'
  //   DataTypeConversion: '<S3>/Data Type Conversion3'
  //   DataTypeConversion: '<S3>/Data Type Conversion4'
  //   DataTypeConversion: '<S3>/Data Type Conversion5'
  //   MATLABSystem: '<S3>/PX4 Timestamp'
  //   MATLABSystem: '<S3>/Read Parameter'
  //   MATLABSystem: '<S3>/Read Parameter1'
  //   MATLABSystem: '<S3>/Read Parameter2'
  //
  FLIGHT_hexacopter_B.out_roll = rtb_SinCos_o2;
  FLIGHT_hexacopter_B.out_pitch = FLIGHT_hexacopter_B.Product5_l;
  FLIGHT_hexacopter_B.out_yawrate = FLIGHT_hexacopter_B.Gain3;
  if (rtb_NOT_h && (FLIGHT_hexacopter_DW.start_time_usec == -1.0)) {
    FLIGHT_hexacopter_DW.start_time_usec = static_cast<real_T>
      (FLIGHT_hexacopter_B.PX4Timestamp.PX4Timestamp);
  }

  if (rtb_NOT_h && (FLIGHT_hexacopter_DW.start_time_usec > 0.0)) {
    //  time calculation
    FLIGHT_hexacopter_B.reletive_time_sec = (static_cast<real_T>
      (FLIGHT_hexacopter_B.PX4Timestamp.PX4Timestamp) -
      FLIGHT_hexacopter_DW.start_time_usec) * 1.0E-6;
  } else {
    FLIGHT_hexacopter_DW.start_time_usec = -1.0;
    FLIGHT_hexacopter_B.reletive_time_sec = 0.0;
  }

  //  Define Doublet
  FLIGHT_hexacopter_B.peak_angle_rad = FLIGHT_hexacopter_B.ParamStep *
    0.017453292519943295;

  //  Default Output
  //  Generate Doublet Command
  if (rtb_NOT_h) {
    switch (FLIGHT_hexacopter_B.ParamStep_k) {
     case 1:
      if ((FLIGHT_hexacopter_B.reletive_time_sec >= 0.0) &&
          (FLIGHT_hexacopter_B.reletive_time_sec <
           FLIGHT_hexacopter_B.ParamStep_m)) {
        FLIGHT_hexacopter_B.out_roll = FLIGHT_hexacopter_B.peak_angle_rad;
      } else if ((FLIGHT_hexacopter_B.reletive_time_sec >=
                  FLIGHT_hexacopter_B.ParamStep_m) &&
                 (FLIGHT_hexacopter_B.reletive_time_sec < static_cast<real_T>
                  (FLIGHT_hexacopter_B.ParamStep_m) +
                  FLIGHT_hexacopter_B.ParamStep_m)) {
        FLIGHT_hexacopter_B.out_roll = -FLIGHT_hexacopter_B.peak_angle_rad;
      } else {
        FLIGHT_hexacopter_B.out_roll = 0.0;
      }
      break;

     case 2:
      if ((FLIGHT_hexacopter_B.reletive_time_sec >= 0.0) &&
          (FLIGHT_hexacopter_B.reletive_time_sec <
           FLIGHT_hexacopter_B.ParamStep_m)) {
        FLIGHT_hexacopter_B.out_pitch = FLIGHT_hexacopter_B.peak_angle_rad;
      } else if ((FLIGHT_hexacopter_B.reletive_time_sec >=
                  FLIGHT_hexacopter_B.ParamStep_m) &&
                 (FLIGHT_hexacopter_B.reletive_time_sec < static_cast<real_T>
                  (FLIGHT_hexacopter_B.ParamStep_m) +
                  FLIGHT_hexacopter_B.ParamStep_m)) {
        FLIGHT_hexacopter_B.out_pitch = -FLIGHT_hexacopter_B.peak_angle_rad;
      } else {
        FLIGHT_hexacopter_B.out_pitch = 0.0;
      }
      break;

     case 3:
      if ((FLIGHT_hexacopter_B.reletive_time_sec >= 0.0) &&
          (FLIGHT_hexacopter_B.reletive_time_sec <
           FLIGHT_hexacopter_B.ParamStep_m)) {
        FLIGHT_hexacopter_B.out_yawrate = FLIGHT_hexacopter_B.peak_angle_rad;
      } else if ((FLIGHT_hexacopter_B.reletive_time_sec >=
                  FLIGHT_hexacopter_B.ParamStep_m) &&
                 (FLIGHT_hexacopter_B.reletive_time_sec < static_cast<real_T>
                  (FLIGHT_hexacopter_B.ParamStep_m) +
                  FLIGHT_hexacopter_B.ParamStep_m)) {
        FLIGHT_hexacopter_B.out_yawrate = -FLIGHT_hexacopter_B.peak_angle_rad;
      } else {
        FLIGHT_hexacopter_B.out_yawrate = 0.0;
      }
      break;
    }
  }

  // End of MATLAB Function: '<S3>/MATLAB Function'

  // Outputs for Enabled SubSystem: '<Root>/CAS' incorporates:
  //   EnablePort: '<S2>/Enable'

  if (FLIGHT_hexacopter_B.In1_n.armed) {
    // MATLABSystem: '<S2>/Read Parameter9'
    if (FLIGHT_hexacopter_DW.obj_k4.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_k4.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_k4.MW_PARAMHANDLE,
      MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep);
    if (rtb_flag_pos) {
      FLIGHT_hexacopter_B.ParamStep = 0.0F;
    }

    // Gain: '<S77>/Gain1' incorporates:
    //   MATLABSystem: '<S2>/Read Parameter9'
    //
    FLIGHT_hexacopter_B.ParamStep_m = FLIGHT_hexacopter_P.Gain1_Gain_g *
      FLIGHT_hexacopter_B.ParamStep;

    // MATLABSystem: '<S2>/Read Parameter'
    if (FLIGHT_hexacopter_DW.obj_jz.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_jz.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_jz.MW_PARAMHANDLE,
      MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep);
    if (rtb_flag_pos) {
      FLIGHT_hexacopter_B.ParamStep = 0.0F;
    }

    // Product: '<S170>/PProd Out' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion8'
    //   MATLABSystem: '<S2>/Read Parameter'
    //   Sum: '<S2>/Sum3'
    //
    FLIGHT_hexacopter_B.ParamStep *= static_cast<real32_T>
      (FLIGHT_hexacopter_B.out_roll) - FLIGHT_hexacopter_B.ypr[2];

    // Switch: '<S173>/Switch2' incorporates:
    //   RelationalOperator: '<S173>/LowerRelop1'

    if (FLIGHT_hexacopter_B.ParamStep > FLIGHT_hexacopter_B.ParamStep_m) {
      // Switch: '<S173>/Switch2'
      FLIGHT_hexacopter_B.Switch2 = FLIGHT_hexacopter_B.ParamStep_m;
    } else {
      // Gain: '<S2>/Gain'
      FLIGHT_hexacopter_B.ParamStep_m *= FLIGHT_hexacopter_P.Gain_Gain_m3;

      // Switch: '<S173>/Switch' incorporates:
      //   RelationalOperator: '<S173>/UpperRelop'

      if (FLIGHT_hexacopter_B.ParamStep < FLIGHT_hexacopter_B.ParamStep_m) {
        // Switch: '<S173>/Switch2'
        FLIGHT_hexacopter_B.Switch2 = FLIGHT_hexacopter_B.ParamStep_m;
      } else {
        // Switch: '<S173>/Switch2'
        FLIGHT_hexacopter_B.Switch2 = FLIGHT_hexacopter_B.ParamStep;
      }

      // End of Switch: '<S173>/Switch'
    }

    // End of Switch: '<S173>/Switch2'

    // MATLABSystem: '<S2>/Read Parameter10'
    if (FLIGHT_hexacopter_DW.obj_ds.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_ds.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_ds.MW_PARAMHANDLE,
      MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep);
    if (rtb_flag_pos) {
      FLIGHT_hexacopter_B.ParamStep = 0.0F;
    }

    // Gain: '<S78>/Gain1' incorporates:
    //   MATLABSystem: '<S2>/Read Parameter10'
    //
    FLIGHT_hexacopter_B.ParamStep_m = FLIGHT_hexacopter_P.Gain1_Gain_c *
      FLIGHT_hexacopter_B.ParamStep;

    // MATLABSystem: '<S2>/Read Parameter1'
    if (FLIGHT_hexacopter_DW.obj_o.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_o.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_o.MW_PARAMHANDLE,
      MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep);
    if (rtb_flag_pos) {
      FLIGHT_hexacopter_B.ParamStep = 0.0F;
    }

    // Product: '<S119>/PProd Out' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion7'
    //   MATLABSystem: '<S2>/Read Parameter1'
    //   Sum: '<S2>/Sum2'
    //
    FLIGHT_hexacopter_B.ParamStep *= static_cast<real32_T>
      (FLIGHT_hexacopter_B.out_pitch) - FLIGHT_hexacopter_B.ypr[1];

    // Switch: '<S122>/Switch2' incorporates:
    //   RelationalOperator: '<S122>/LowerRelop1'

    if (FLIGHT_hexacopter_B.ParamStep > FLIGHT_hexacopter_B.ParamStep_m) {
      // Switch: '<S122>/Switch2'
      FLIGHT_hexacopter_B.Switch2_i = FLIGHT_hexacopter_B.ParamStep_m;
    } else {
      // Gain: '<S2>/Gain1'
      FLIGHT_hexacopter_B.ParamStep_m *= FLIGHT_hexacopter_P.Gain1_Gain;

      // Switch: '<S122>/Switch' incorporates:
      //   RelationalOperator: '<S122>/UpperRelop'

      if (FLIGHT_hexacopter_B.ParamStep < FLIGHT_hexacopter_B.ParamStep_m) {
        // Switch: '<S122>/Switch2'
        FLIGHT_hexacopter_B.Switch2_i = FLIGHT_hexacopter_B.ParamStep_m;
      } else {
        // Switch: '<S122>/Switch2'
        FLIGHT_hexacopter_B.Switch2_i = FLIGHT_hexacopter_B.ParamStep;
      }

      // End of Switch: '<S122>/Switch'
    }

    // End of Switch: '<S122>/Switch2'
  }

  // End of Outputs for SubSystem: '<Root>/CAS'

  // S-Function (sdspdiag2): '<S477>/Create Diagonal Matrix' incorporates:
  //   Constant: '<S477>/Constant'
  //   Constant: '<S477>/Constant1'
  //   Constant: '<S477>/Constant2'
  //   SignalConversion generated from: '<S477>/Create Diagonal Matrix'

  for (FLIGHT_hexacopter_B.ParamStep_k = 0; FLIGHT_hexacopter_B.ParamStep_k < 9;
       FLIGHT_hexacopter_B.ParamStep_k++) {
    FLIGHT_hexacopter_B.CreateDiagonalMatrix[FLIGHT_hexacopter_B.ParamStep_k] =
      0.0F;
  }

  FLIGHT_hexacopter_B.CreateDiagonalMatrix[0] = FLIGHT_hexacopter_P.Jxx;
  FLIGHT_hexacopter_B.CreateDiagonalMatrix[4] = FLIGHT_hexacopter_P.Jyy;
  FLIGHT_hexacopter_B.CreateDiagonalMatrix[8] = FLIGHT_hexacopter_P.Jzz;

  // End of S-Function (sdspdiag2): '<S477>/Create Diagonal Matrix'

  // RateTransition: '<Root>/rate_transition_throttle'
  FLIGHT_hexacopter_DW.rate_transition_throttle_Buffer = rtb_Saturation1;

  // MATLAB Function: '<S11>/Omega_phi'
  FLIGHT_hexacopter_B.ParamStep = static_cast<real32_T>(tan(static_cast<real_T>
    (FLIGHT_hexacopter_B.ypr[1])));
  FLIGHT_hexacopter_B.TmpSignalConversionAtSFun_c[0] = 1.0F;
  FLIGHT_hexacopter_B.TmpSignalConversionAtSFun_c[1] = static_cast<real32_T>(sin
    (static_cast<real_T>(FLIGHT_hexacopter_B.ypr[2]))) *
    FLIGHT_hexacopter_B.ParamStep;
  FLIGHT_hexacopter_B.TmpSignalConversionAtSFun_c[2] = static_cast<real32_T>(cos
    (static_cast<real_T>(FLIGHT_hexacopter_B.ypr[2]))) *
    FLIGHT_hexacopter_B.ParamStep;
  for (FLIGHT_hexacopter_B.ParamStep_k = 0; FLIGHT_hexacopter_B.ParamStep_k < 3;
       FLIGHT_hexacopter_B.ParamStep_k++) {
    // MATLAB Function: '<S11>/MATLAB Function1' incorporates:
    //   S-Function (sdspdiag2): '<S477>/Create Diagonal Matrix'

    FLIGHT_hexacopter_B.G1[FLIGHT_hexacopter_B.ParamStep_k] =
      (FLIGHT_hexacopter_B.CreateDiagonalMatrix[3 *
       FLIGHT_hexacopter_B.ParamStep_k + 1] *
       FLIGHT_hexacopter_B.TmpSignalConversionAtSFun_c[1] +
       FLIGHT_hexacopter_B.CreateDiagonalMatrix[3 *
       FLIGHT_hexacopter_B.ParamStep_k]) +
      FLIGHT_hexacopter_B.CreateDiagonalMatrix[3 *
      FLIGHT_hexacopter_B.ParamStep_k + 2] *
      FLIGHT_hexacopter_B.TmpSignalConversionAtSFun_c[2];

    // SampleTimeMath: '<S480>/TSamp'
    //
    //  About '<S480>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )
    //
    FLIGHT_hexacopter_B.ParamStep =
      FLIGHT_hexacopter_B.TmpSignalConversionAtSFun_c[FLIGHT_hexacopter_B.ParamStep_k]
      * FLIGHT_hexacopter_P.TSamp_WtEt_k;
    FLIGHT_hexacopter_B.TSamp[FLIGHT_hexacopter_B.ParamStep_k] =
      FLIGHT_hexacopter_B.ParamStep;

    // Sum: '<S480>/Diff' incorporates:
    //   SampleTimeMath: '<S480>/TSamp'
    //   UnitDelay: '<S480>/UD'
    //
    //  About '<S480>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )
    //    *
    //  Block description for '<S480>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S480>/UD':
    //
    //   Store in Global RAM

    FLIGHT_hexacopter_DW.UD_DSTATE[FLIGHT_hexacopter_B.ParamStep_k] =
      FLIGHT_hexacopter_B.ParamStep -
      FLIGHT_hexacopter_DW.UD_DSTATE[FLIGHT_hexacopter_B.ParamStep_k];
  }

  // SampleTimeMath: '<S478>/TSamp' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion8'
  //
  //  About '<S478>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  rtb_Product5_m = static_cast<real32_T>(FLIGHT_hexacopter_B.out_roll) *
    FLIGHT_hexacopter_P.TSamp_WtEt_c;

  // Sum: '<S478>/Diff' incorporates:
  //   UnitDelay: '<S478>/UD'
  //
  //  Block description for '<S478>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S478>/UD':
  //
  //   Store in Global RAM

  rtb_Gain_p = rtb_Product5_m - FLIGHT_hexacopter_DW.UD_DSTATE_j;

  // SampleTimeMath: '<S479>/TSamp'
  //
  //  About '<S479>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  rtb_Product5_e = rtb_Gain_p * FLIGHT_hexacopter_P.TSamp_WtEt_b;

  // Sum: '<S11>/Subtract' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion8'

  rtb_Product5_dr = FLIGHT_hexacopter_B.ypr[2] - static_cast<real32_T>
    (FLIGHT_hexacopter_B.out_roll);

  // SampleTimeMath: '<S481>/TSamp'
  //
  //  About '<S481>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  rtb_Product5_k = rtb_Product5_dr * FLIGHT_hexacopter_P.TSamp_WtEt_py;

  // MATLABSystem: '<S11>/Read Parameter'
  if (FLIGHT_hexacopter_DW.obj_g.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj_g.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_g.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_hexacopter_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S11>/Read Parameter1'
  if (FLIGHT_hexacopter_DW.obj_d.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj_d.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_d.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep_m);
  if (rtb_flag_pos) {
    FLIGHT_hexacopter_B.ParamStep_m = 0.0F;
  }

  // MATLABSystem: '<S11>/Read Parameter2'
  if (FLIGHT_hexacopter_DW.obj_k.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj_k.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_k.MW_PARAMHANDLE,
    MW_SINGLE, &rtb_Gain_f);
  if (rtb_flag_pos) {
    rtb_Gain_f = 0.0F;
  }

  // MATLAB Function: '<S11>/MATLAB Function3' incorporates:
  //   DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
  //   MATLABSystem: '<S11>/Read Parameter'
  //   MATLABSystem: '<S11>/Read Parameter1'
  //   MATLABSystem: '<S11>/Read Parameter2'
  //   Sum: '<S481>/Diff'
  //   UnitDelay: '<S481>/UD'
  //  *
  //  Block description for '<S481>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S481>/UD':
  //
  //   Store in Global RAM

  //  PID Like Sliding Surface
  rtb_Gain_f = ((rtb_Product5_k - FLIGHT_hexacopter_DW.UD_DSTATE_n) * rtb_Gain_f
                + FLIGHT_hexacopter_B.ParamStep * rtb_Product5_dr) +
    FLIGHT_hexacopter_B.ParamStep_m *
    FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE;

  // MATLABSystem: '<S11>/Read Parameter3'
  if (FLIGHT_hexacopter_DW.obj_n.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj_n.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_n.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_hexacopter_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S11>/Read Parameter4'
  if (FLIGHT_hexacopter_DW.obj.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep_m);
  if (rtb_flag_pos) {
    FLIGHT_hexacopter_B.ParamStep_m = 0.0F;
  }

  // MATLAB Function: '<S11>/MATLAB Function2'
  rtb_flag_pos = true;
  FLIGHT_hexacopter_B.ypr[0] = 0.0F;
  if (rtIsInfF(FLIGHT_hexacopter_B.G1[0]) || rtIsNaNF(FLIGHT_hexacopter_B.G1[0]))
  {
    rtb_flag_pos = false;
  }

  if (rtb_flag_pos && (rtIsInfF(FLIGHT_hexacopter_B.G1[1]) || rtIsNaNF
                       (FLIGHT_hexacopter_B.G1[1]))) {
    rtb_flag_pos = false;
  }

  if (rtb_flag_pos && (rtIsInfF(FLIGHT_hexacopter_B.G1[2]) || rtIsNaNF
                       (FLIGHT_hexacopter_B.G1[2]))) {
    rtb_flag_pos = false;
  }

  if (!rtb_flag_pos) {
    FLIGHT_hexacopter_B.ypr[0] = (rtNaNF);
  } else {
    rtb_flag_pos = false;
    FLIGHT_hexacopter_B.Product5_l = 0.0F;
    FLIGHT_hexacopter_B.ParamStep_k = 0;
    exitg1 = false;
    while ((!exitg1) && (FLIGHT_hexacopter_B.ParamStep_k < 3)) {
      FLIGHT_hexacopter_B.Gain3 = static_cast<real32_T>(fabs(static_cast<real_T>
        (FLIGHT_hexacopter_B.G1[FLIGHT_hexacopter_B.ParamStep_k])));
      if (rtIsNaNF(FLIGHT_hexacopter_B.Gain3)) {
        FLIGHT_hexacopter_B.Product5_l = (rtNaNF);
        exitg1 = true;
      } else {
        if (FLIGHT_hexacopter_B.Gain3 > FLIGHT_hexacopter_B.Product5_l) {
          FLIGHT_hexacopter_B.Product5_l = FLIGHT_hexacopter_B.Gain3;
        }

        FLIGHT_hexacopter_B.ParamStep_k++;
      }
    }

    FLIGHT_hexacopter_B.Gain3 = FLIGHT_hexacopter_B.Product5_l;
    guard1 = false;
    if ((FLIGHT_hexacopter_B.Product5_l > 0.0F) &&
        (FLIGHT_hexacopter_B.Product5_l < 9.09494702E-13F)) {
      rtb_flag_pos = true;
      FLIGHT_hexacopter_B.Gain3 = 9.09494702E-13F;
      guard1 = true;
    } else if (FLIGHT_hexacopter_B.Product5_l > 1.09951163E+12F) {
      rtb_flag_pos = true;
      FLIGHT_hexacopter_B.Gain3 = 1.09951163E+12F;
      guard1 = true;
    }

    if (guard1) {
      FLIGHT_hexacopter_B.cfromc = FLIGHT_hexacopter_B.Product5_l;
      FLIGHT_hexacopter_B.ctoc = FLIGHT_hexacopter_B.Gain3;
      rtb_NOT_h = true;
      while (rtb_NOT_h) {
        rtb_SinCos_o2 = FLIGHT_hexacopter_B.cfromc * 1.97215226E-31F;
        FLIGHT_hexacopter_B.t = FLIGHT_hexacopter_B.ctoc / 5.0706024E+30F;
        if ((rtb_SinCos_o2 > FLIGHT_hexacopter_B.ctoc) &&
            (FLIGHT_hexacopter_B.ctoc != 0.0F)) {
          FLIGHT_hexacopter_B.mul = 1.97215226E-31F;
          FLIGHT_hexacopter_B.cfromc = rtb_SinCos_o2;
        } else if (FLIGHT_hexacopter_B.t > FLIGHT_hexacopter_B.cfromc) {
          FLIGHT_hexacopter_B.mul = 5.0706024E+30F;
          FLIGHT_hexacopter_B.ctoc = FLIGHT_hexacopter_B.t;
        } else {
          FLIGHT_hexacopter_B.mul = FLIGHT_hexacopter_B.ctoc /
            FLIGHT_hexacopter_B.cfromc;
          rtb_NOT_h = false;
        }

        FLIGHT_hexacopter_B.G1[0] *= FLIGHT_hexacopter_B.mul;
        FLIGHT_hexacopter_B.G1[1] *= FLIGHT_hexacopter_B.mul;
        FLIGHT_hexacopter_B.G1[2] *= FLIGHT_hexacopter_B.mul;
      }
    }

    FLIGHT_hexacopter_B.ctoc = 1.29246971E-26F;
    rtb_SinCos_o2 = static_cast<real32_T>(fabs(static_cast<real_T>
      (FLIGHT_hexacopter_B.G1[0])));
    if (rtb_SinCos_o2 > 1.29246971E-26F) {
      FLIGHT_hexacopter_B.cfromc = 1.0F;
      FLIGHT_hexacopter_B.ctoc = rtb_SinCos_o2;
    } else {
      FLIGHT_hexacopter_B.t = rtb_SinCos_o2 / 1.29246971E-26F;
      FLIGHT_hexacopter_B.cfromc = FLIGHT_hexacopter_B.t * FLIGHT_hexacopter_B.t;
    }

    rtb_SinCos_o2 = static_cast<real32_T>(fabs(static_cast<real_T>
      (FLIGHT_hexacopter_B.G1[1])));
    if (rtb_SinCos_o2 > FLIGHT_hexacopter_B.ctoc) {
      FLIGHT_hexacopter_B.t = FLIGHT_hexacopter_B.ctoc / rtb_SinCos_o2;
      FLIGHT_hexacopter_B.cfromc = FLIGHT_hexacopter_B.cfromc *
        FLIGHT_hexacopter_B.t * FLIGHT_hexacopter_B.t + 1.0F;
      FLIGHT_hexacopter_B.ctoc = rtb_SinCos_o2;
    } else {
      FLIGHT_hexacopter_B.t = rtb_SinCos_o2 / FLIGHT_hexacopter_B.ctoc;
      FLIGHT_hexacopter_B.cfromc += FLIGHT_hexacopter_B.t *
        FLIGHT_hexacopter_B.t;
    }

    rtb_SinCos_o2 = static_cast<real32_T>(fabs(static_cast<real_T>
      (FLIGHT_hexacopter_B.G1[2])));
    if (rtb_SinCos_o2 > FLIGHT_hexacopter_B.ctoc) {
      FLIGHT_hexacopter_B.t = FLIGHT_hexacopter_B.ctoc / rtb_SinCos_o2;
      FLIGHT_hexacopter_B.cfromc = FLIGHT_hexacopter_B.cfromc *
        FLIGHT_hexacopter_B.t * FLIGHT_hexacopter_B.t + 1.0F;
      FLIGHT_hexacopter_B.ctoc = rtb_SinCos_o2;
    } else {
      FLIGHT_hexacopter_B.t = rtb_SinCos_o2 / FLIGHT_hexacopter_B.ctoc;
      FLIGHT_hexacopter_B.cfromc += FLIGHT_hexacopter_B.t *
        FLIGHT_hexacopter_B.t;
    }

    FLIGHT_hexacopter_B.cfromc = FLIGHT_hexacopter_B.ctoc * static_cast<real32_T>
      (sqrt(static_cast<real_T>(FLIGHT_hexacopter_B.cfromc)));
    if (FLIGHT_hexacopter_B.cfromc > 0.0F) {
      if (FLIGHT_hexacopter_B.G1[0] < 0.0F) {
        FLIGHT_hexacopter_B.cfromc = -FLIGHT_hexacopter_B.cfromc;
      }

      if (static_cast<real32_T>(fabs(static_cast<real_T>
            (FLIGHT_hexacopter_B.cfromc))) >= 9.86076132E-32F) {
        FLIGHT_hexacopter_B.ctoc = 1.0F / FLIGHT_hexacopter_B.cfromc;
        FLIGHT_hexacopter_B.G1[0] *= FLIGHT_hexacopter_B.ctoc;
        FLIGHT_hexacopter_B.G1[1] *= FLIGHT_hexacopter_B.ctoc;
        FLIGHT_hexacopter_B.G1[2] *= FLIGHT_hexacopter_B.ctoc;
      } else {
        FLIGHT_hexacopter_B.G1[0] /= FLIGHT_hexacopter_B.cfromc;
        FLIGHT_hexacopter_B.G1[1] /= FLIGHT_hexacopter_B.cfromc;
        FLIGHT_hexacopter_B.G1[2] /= FLIGHT_hexacopter_B.cfromc;
      }

      FLIGHT_hexacopter_B.G1[0]++;
      FLIGHT_hexacopter_B.cfromc = -FLIGHT_hexacopter_B.cfromc;
    } else {
      FLIGHT_hexacopter_B.cfromc = 0.0F;
    }

    if (FLIGHT_hexacopter_B.cfromc != 0.0F) {
      FLIGHT_hexacopter_B.ctoc = static_cast<real32_T>(fabs(static_cast<real_T>
        (FLIGHT_hexacopter_B.cfromc)));
      rtb_SinCos_o2 = FLIGHT_hexacopter_B.cfromc / FLIGHT_hexacopter_B.ctoc;
      FLIGHT_hexacopter_B.cfromc = FLIGHT_hexacopter_B.ctoc;
      FLIGHT_hexacopter_B.U[0] = (-FLIGHT_hexacopter_B.G1[0] + 1.0F) *
        rtb_SinCos_o2;
      FLIGHT_hexacopter_B.U[1] = rtb_SinCos_o2 * -FLIGHT_hexacopter_B.G1[1];
      FLIGHT_hexacopter_B.U[2] = rtb_SinCos_o2 * -FLIGHT_hexacopter_B.G1[2];
    } else {
      FLIGHT_hexacopter_B.U[1] = 0.0F;
      FLIGHT_hexacopter_B.U[2] = 0.0F;
      FLIGHT_hexacopter_B.U[0] = 1.0F;
    }

    if (rtb_flag_pos) {
      rtb_flag_pos = true;
      while (rtb_flag_pos) {
        FLIGHT_hexacopter_B.ctoc = FLIGHT_hexacopter_B.Gain3 * 1.97215226E-31F;
        rtb_SinCos_o2 = FLIGHT_hexacopter_B.Product5_l / 5.0706024E+30F;
        if ((FLIGHT_hexacopter_B.ctoc > FLIGHT_hexacopter_B.Product5_l) &&
            (FLIGHT_hexacopter_B.Product5_l != 0.0F)) {
          FLIGHT_hexacopter_B.t = 1.97215226E-31F;
          FLIGHT_hexacopter_B.Gain3 = FLIGHT_hexacopter_B.ctoc;
        } else if (rtb_SinCos_o2 > FLIGHT_hexacopter_B.Gain3) {
          FLIGHT_hexacopter_B.t = 5.0706024E+30F;
          FLIGHT_hexacopter_B.Product5_l = rtb_SinCos_o2;
        } else {
          FLIGHT_hexacopter_B.t = FLIGHT_hexacopter_B.Product5_l /
            FLIGHT_hexacopter_B.Gain3;
          rtb_flag_pos = false;
        }

        FLIGHT_hexacopter_B.cfromc *= FLIGHT_hexacopter_B.t;
      }
    }

    FLIGHT_hexacopter_B.Product5_l = 1.0F;
    rtb_flag_pos = (rtIsInfF(FLIGHT_hexacopter_B.cfromc) || rtIsNaNF
                    (FLIGHT_hexacopter_B.cfromc));
    if (rtb_flag_pos) {
      FLIGHT_hexacopter_B.Gain3 = (rtNaNF);
    } else if (FLIGHT_hexacopter_B.cfromc < 2.3509887E-38F) {
      FLIGHT_hexacopter_B.Gain3 = 1.4013E-45F;
    } else {
      frexp(static_cast<real_T>(FLIGHT_hexacopter_B.cfromc),
            &FLIGHT_hexacopter_B.r_c);
      FLIGHT_hexacopter_B.Gain3 = static_cast<real32_T>(ldexp(1.0,
        FLIGHT_hexacopter_B.r_c - 24));
    }

    FLIGHT_hexacopter_B.Gain3 *= 3.0F;
    if (rtb_flag_pos) {
      FLIGHT_hexacopter_B.Gain3 = 3.402823466E+38F;
    }

    FLIGHT_hexacopter_B.r_c = 0;
    if (FLIGHT_hexacopter_B.cfromc > FLIGHT_hexacopter_B.Gain3) {
      FLIGHT_hexacopter_B.r_c = 1;
    }

    if (FLIGHT_hexacopter_B.r_c > 0) {
      FLIGHT_hexacopter_B.Gain3 = 1.0F / FLIGHT_hexacopter_B.cfromc;
      for (FLIGHT_hexacopter_B.r_c = 1; FLIGHT_hexacopter_B.r_c < 2;
           FLIGHT_hexacopter_B.r_c++) {
        FLIGHT_hexacopter_B.Product5_l *= FLIGHT_hexacopter_B.Gain3;
      }

      for (FLIGHT_hexacopter_B.r_c = 0; FLIGHT_hexacopter_B.r_c < 3;
           FLIGHT_hexacopter_B.r_c++) {
        for (FLIGHT_hexacopter_B.ParamStep_k = FLIGHT_hexacopter_B.r_c + 1;
             FLIGHT_hexacopter_B.ParamStep_k <= FLIGHT_hexacopter_B.r_c + 1;
             FLIGHT_hexacopter_B.ParamStep_k++) {
          FLIGHT_hexacopter_B.ypr[FLIGHT_hexacopter_B.ParamStep_k - 1] = 0.0F;
        }
      }

      FLIGHT_hexacopter_B.br = 0;
      for (FLIGHT_hexacopter_B.r_c = 0; FLIGHT_hexacopter_B.r_c < 3;
           FLIGHT_hexacopter_B.r_c++) {
        FLIGHT_hexacopter_B.br++;
        for (FLIGHT_hexacopter_B.ParamStep_k = FLIGHT_hexacopter_B.br;
             FLIGHT_hexacopter_B.ParamStep_k <= FLIGHT_hexacopter_B.br;
             FLIGHT_hexacopter_B.ParamStep_k += 3) {
          for (FLIGHT_hexacopter_B.b_ic = FLIGHT_hexacopter_B.r_c + 1;
               FLIGHT_hexacopter_B.b_ic <= FLIGHT_hexacopter_B.r_c + 1;
               FLIGHT_hexacopter_B.b_ic++) {
            FLIGHT_hexacopter_B.ypr[FLIGHT_hexacopter_B.b_ic - 1] +=
              FLIGHT_hexacopter_B.U[FLIGHT_hexacopter_B.ParamStep_k - 1] *
              FLIGHT_hexacopter_B.Product5_l;
          }
        }
      }
    }
  }

  // MATLAB Function: '<S11>/MATLAB Function4'
  if (rtIsNaNF(rtb_Gain_f)) {
    FLIGHT_hexacopter_B.Product5_l = (rtNaNF);
  } else if (rtb_Gain_f < 0.0F) {
    FLIGHT_hexacopter_B.Product5_l = -1.0F;
  } else {
    FLIGHT_hexacopter_B.Product5_l = (rtb_Gain_f > 0.0F);
  }

  // MATLAB Function: '<S11>/MATLAB Function' incorporates:
  //   RateTransition: '<Root>/Rate Transition'
  //   Sum: '<S480>/Diff'
  //
  //  Block description for '<S480>/Diff':
  //
  //   Add in CPU

  FLIGHT_hexacopter_B.Gain3 = (FLIGHT_hexacopter_DW.UD_DSTATE[0] *
    FLIGHT_hexacopter_DW.RateTransition_Buffer[0] +
    FLIGHT_hexacopter_DW.UD_DSTATE[1] *
    FLIGHT_hexacopter_DW.RateTransition_Buffer[1]) +
    FLIGHT_hexacopter_DW.UD_DSTATE[2] *
    FLIGHT_hexacopter_DW.RateTransition_Buffer[2];

  // MATLAB Function: '<S11>/MATLAB Function2' incorporates:
  //   Constant: '<S477>/Constant'
  //   Constant: '<S477>/Constant1'
  //   Constant: '<S477>/Constant2'
  //   MATLAB Function: '<S11>/MATLAB Function'
  //   MATLAB Function: '<S11>/MATLAB Function4'
  //   MATLABSystem: '<S11>/Read Parameter3'
  //   MATLABSystem: '<S11>/Read Parameter4'
  //   Product: '<S477>/Divide'
  //   Product: '<S477>/Divide1'
  //   Product: '<S477>/Divide2'
  //   Product: '<S477>/Product'
  //   Product: '<S477>/Product1'
  //   Product: '<S477>/Product2'
  //   Product: '<S477>/Product3'
  //   Product: '<S477>/Product4'
  //   Product: '<S477>/Product5'
  //   RateTransition: '<Root>/Rate Transition'
  //   Saturate: '<S11>/Saturation2'
  //   Sum: '<S477>/Add'
  //   Sum: '<S477>/Add1'
  //   Sum: '<S477>/Add2'
  //   Sum: '<S479>/Diff'
  //   UnitDelay: '<S479>/UD'
  //  *
  //  Block description for '<S479>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S479>/UD':
  //
  //   Store in Global RAM

  FLIGHT_hexacopter_B.ParamStep = (-(((((((FLIGHT_hexacopter_P.Jzz -
    FLIGHT_hexacopter_P.Jxx) / FLIGHT_hexacopter_P.Jyy *
    (FLIGHT_hexacopter_DW.RateTransition_Buffer[0] *
     FLIGHT_hexacopter_DW.RateTransition_Buffer[2]) *
    FLIGHT_hexacopter_B.TmpSignalConversionAtSFun_c[1] +
    (FLIGHT_hexacopter_P.Jyy - FLIGHT_hexacopter_P.Jzz) /
    FLIGHT_hexacopter_P.Jxx * (FLIGHT_hexacopter_DW.RateTransition_Buffer[1] *
    FLIGHT_hexacopter_DW.RateTransition_Buffer[2])) + (FLIGHT_hexacopter_P.Jxx -
    FLIGHT_hexacopter_P.Jyy) / FLIGHT_hexacopter_P.Jzz *
    (FLIGHT_hexacopter_DW.RateTransition_Buffer[0] *
     FLIGHT_hexacopter_DW.RateTransition_Buffer[1]) *
    FLIGHT_hexacopter_B.TmpSignalConversionAtSFun_c[2]) +
    FLIGHT_hexacopter_B.Gain3) - (rtb_Product5_e -
    FLIGHT_hexacopter_DW.UD_DSTATE_g)) + (FLIGHT_hexacopter_B.Gain3 - rtb_Gain_p)
    * 0.0F) + 0.0F * rtb_Product5_dr) + (-FLIGHT_hexacopter_B.ParamStep *
    FLIGHT_hexacopter_B.Product5_l - FLIGHT_hexacopter_B.ParamStep_m *
    rtb_Gain_f)) * FLIGHT_hexacopter_B.ypr[0];

  // Saturate: '<S11>/Saturation2'
  if (FLIGHT_hexacopter_B.ParamStep > FLIGHT_hexacopter_P.Saturation2_UpperSat_i)
  {
    FLIGHT_hexacopter_B.ParamStep = FLIGHT_hexacopter_P.Saturation2_UpperSat_i;
  } else if (FLIGHT_hexacopter_B.ParamStep <
             FLIGHT_hexacopter_P.Saturation2_LowerSat_k) {
    FLIGHT_hexacopter_B.ParamStep = FLIGHT_hexacopter_P.Saturation2_LowerSat_k;
  }

  // RateTransition: '<Root>/Rate Transition1'
  FLIGHT_hexacopter_DW.RateTransition1_Buffer0 = FLIGHT_hexacopter_B.ParamStep;

  // RateTransition: '<Root>/rate_transition_des_p'
  FLIGHT_hexacopter_DW.rate_transition_des_p_Buffer0 =
    FLIGHT_hexacopter_B.Switch2;

  // RateTransition: '<Root>/rate_transition_des_q'
  FLIGHT_hexacopter_DW.rate_transition_des_q_Buffer0 =
    FLIGHT_hexacopter_B.Switch2_i;
  FLIGHT_hexac_PX4Timestamp_n(&FLIGHT_hexacopter_B.PX4Timestamp_i);

  // BusAssignment: '<S510>/Bus Assignment' incorporates:
  //   Constant: '<S21>/Constant'
  //   DataTypeConversion: '<S3>/Data Type Conversion9'
  //   MATLABSystem: '<S510>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment_a.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_i.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment_a.roll = FLIGHT_hexacopter_B.Switch2;
  FLIGHT_hexacopter_B.BusAssignment_a.pitch = FLIGHT_hexacopter_B.Switch2_i;
  FLIGHT_hexacopter_B.BusAssignment_a.yaw = static_cast<real32_T>
    (FLIGHT_hexacopter_B.out_yawrate);
  FLIGHT_hexacopter_B.BusAssignment_a.thrust_body[0] =
    FLIGHT_hexacopter_P.Constant_Value_ll;
  FLIGHT_hexacopter_B.BusAssignment_a.thrust_body[1] =
    FLIGHT_hexacopter_P.Constant_Value_ll;
  FLIGHT_hexacopter_B.BusAssignment_a.thrust_body[2] = rtb_Saturation1;
  FLIGHT_hexacopter_B.BusAssignment_a.reset_integral = false;
  for (FLIGHT_hexacopter_B.ParamStep_k = 0; FLIGHT_hexacopter_B.ParamStep_k < 7;
       FLIGHT_hexacopter_B.ParamStep_k++) {
    FLIGHT_hexacopter_B.BusAssignment_a._padding0[FLIGHT_hexacopter_B.ParamStep_k]
      = 0U;
  }

  // End of BusAssignment: '<S510>/Bus Assignment'

  // MATLABSystem: '<S512>/SinkBlock' incorporates:
  //   BusAssignment: '<S510>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_mq.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_mq.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_a);

  // RateTransition: '<Root>/rate_transition_des_r' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion9'

  FLIGHT_hexacopter_DW.rate_transition_des_r_Buffer0 = static_cast<real32_T>
    (FLIGHT_hexacopter_B.out_yawrate);
  FLIGHT_hexac_PX4Timestamp_n(&FLIGHT_hexacopter_B.PX4Timestamp_nd);

  // BusAssignment: '<S504>/Bus Assignment' incorporates:
  //   Constant: '<Root>/Constant'
  //   DataTypeConversion: '<S3>/Data Type Conversion7'
  //   DataTypeConversion: '<S3>/Data Type Conversion8'
  //   DataTypeConversion: '<S3>/Data Type Conversion9'
  //   MATLABSystem: '<S504>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment_p.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_nd.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment_p.roll_body = static_cast<real32_T>
    (FLIGHT_hexacopter_B.out_roll);
  FLIGHT_hexacopter_B.BusAssignment_p.pitch_body = static_cast<real32_T>
    (FLIGHT_hexacopter_B.out_pitch);
  FLIGHT_hexacopter_B.BusAssignment_p.yaw_body =
    FLIGHT_hexacopter_P.Constant_Value_a5;
  FLIGHT_hexacopter_B.BusAssignment_p.yaw_sp_move_rate = static_cast<real32_T>
    (FLIGHT_hexacopter_B.out_yawrate);
  FLIGHT_hexacopter_B.BusAssignment_p.q_d[0] = 0.0F;
  FLIGHT_hexacopter_B.BusAssignment_p.q_d[1] = 0.0F;
  FLIGHT_hexacopter_B.BusAssignment_p.q_d[2] = 0.0F;
  FLIGHT_hexacopter_B.BusAssignment_p.q_d[3] = 0.0F;
  FLIGHT_hexacopter_B.BusAssignment_p.thrust_body[0] = 0.0F;
  FLIGHT_hexacopter_B.BusAssignment_p.thrust_body[1] = 0.0F;
  FLIGHT_hexacopter_B.BusAssignment_p.thrust_body[2] = 0.0F;
  FLIGHT_hexacopter_B.BusAssignment_p.reset_integral = false;
  FLIGHT_hexacopter_B.BusAssignment_p.fw_control_yaw_wheel = false;
  FLIGHT_hexacopter_B.BusAssignment_p._padding0[0] = 0U;
  FLIGHT_hexacopter_B.BusAssignment_p._padding0[1] = 0U;

  // MATLABSystem: '<S507>/SinkBlock' incorporates:
  //   BusAssignment: '<S504>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_ez.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_ez.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_p);
  FLIGHT_hexacop_PX4Timestamp(&FLIGHT_hexacopter_B.PX4Timestamp_pn);

  // BusAssignment: '<S20>/Bus Assignment' incorporates:
  //   Constant: '<S508>/Constant'

  FLIGHT_hexacopter_B.BusAssignment_g = FLIGHT_hexacopter_P.Constant_Value_n;

  // BusAssignment: '<S20>/Bus Assignment' incorporates:
  //   MATLABSystem: '<S20>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment_g.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_pn.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment_g.vx = rtb_PProdOut_ev_idx_0;
  FLIGHT_hexacopter_B.BusAssignment_g.vy = rtb_PProdOut_ev_idx_1;
  FLIGHT_hexacopter_B.BusAssignment_g.vz = FLIGHT_hexacopter_B.Gain_i;
  FLIGHT_hexacopter_B.BusAssignment_g.x = rtb_des_x;
  FLIGHT_hexacopter_B.BusAssignment_g.y = rtb_des_z;
  FLIGHT_hexacopter_B.BusAssignment_g.z = 0.0F;

  // MATLABSystem: '<S509>/SinkBlock' incorporates:
  //   BusAssignment: '<S20>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_pa.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_pa.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_g);

  // DeadZone: '<S52>/DeadZone'
  if (FLIGHT_hexacopter_B.DeadZone >
      FLIGHT_hexacopter_P.PIDController_UpperSaturationLi) {
    FLIGHT_hexacopter_B.DeadZone -=
      FLIGHT_hexacopter_P.PIDController_UpperSaturationLi;
  } else if (FLIGHT_hexacopter_B.DeadZone >=
             FLIGHT_hexacopter_P.PIDController_LowerSaturationLi) {
    FLIGHT_hexacopter_B.DeadZone = 0.0F;
  } else {
    FLIGHT_hexacopter_B.DeadZone -=
      FLIGHT_hexacopter_P.PIDController_LowerSaturationLi;
  }

  // End of DeadZone: '<S52>/DeadZone'

  // MATLABSystem: '<S1>/Read Parameter3'
  if (FLIGHT_hexacopter_DW.obj_l5.SampleTime != FLIGHT_hexacopter_P.SampleTime)
  {
    FLIGHT_hexacopter_DW.obj_l5.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_flag_pos = MW_Param_Step(FLIGHT_hexacopter_DW.obj_l5.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_hexacopter_B.ParamStep = 0.0F;
  }

  // Product: '<S57>/IProd Out' incorporates:
  //   MATLABSystem: '<S1>/Read Parameter3'
  //
  FLIGHT_hexacopter_B.IProdOut_d *= FLIGHT_hexacopter_B.ParamStep;

  // RateTransition: '<Root>/Rate Transition7'
  FLIGHT_hexacopter_DW.RateTransition7_Buffer0 =
    FLIGHT_hexacopter_B.In1_n.manual_lockdown;

  // RateTransition: '<Root>/rate_transition_arm'
  FLIGHT_hexacopter_DW.rate_transition_arm_Buffer0 =
    FLIGHT_hexacopter_B.In1_n.armed;

  // Switch: '<S50>/Switch1' incorporates:
  //   Constant: '<S50>/Clamping_zero'
  //   Constant: '<S50>/Constant'
  //   Constant: '<S50>/Constant2'
  //   RelationalOperator: '<S50>/fix for DT propagation issue'

  if (FLIGHT_hexacopter_B.DeadZone > FLIGHT_hexacopter_P.Clamping_zero_Value) {
    tmp = FLIGHT_hexacopter_P.Constant_Value_ko;
  } else {
    tmp = FLIGHT_hexacopter_P.Constant2_Value_e;
  }

  // Switch: '<S50>/Switch2' incorporates:
  //   Constant: '<S50>/Clamping_zero'
  //   Constant: '<S50>/Constant3'
  //   Constant: '<S50>/Constant4'
  //   RelationalOperator: '<S50>/fix for DT propagation issue1'

  if (FLIGHT_hexacopter_B.IProdOut_d > FLIGHT_hexacopter_P.Clamping_zero_Value)
  {
    tmp_0 = FLIGHT_hexacopter_P.Constant3_Value_i;
  } else {
    tmp_0 = FLIGHT_hexacopter_P.Constant4_Value_d;
  }

  // Switch: '<S50>/Switch' incorporates:
  //   Constant: '<S50>/Clamping_zero'
  //   Constant: '<S50>/Constant1'
  //   Logic: '<S50>/AND3'
  //   RelationalOperator: '<S50>/Equal1'
  //   RelationalOperator: '<S50>/Relational Operator'
  //   Switch: '<S50>/Switch1'
  //   Switch: '<S50>/Switch2'

  if ((FLIGHT_hexacopter_P.Clamping_zero_Value != FLIGHT_hexacopter_B.DeadZone) &&
      (tmp == tmp_0)) {
    FLIGHT_hexacopter_B.IProdOut_d = FLIGHT_hexacopter_P.Constant1_Value_g;
  }

  // Update for DiscreteIntegrator: '<S60>/Integrator' incorporates:
  //   Switch: '<S50>/Switch'

  FLIGHT_hexacopter_DW.Integrator_DSTATE +=
    FLIGHT_hexacopter_P.Integrator_gainval_h * FLIGHT_hexacopter_B.IProdOut_d;
  if (FLIGHT_hexacopter_DW.Integrator_DSTATE >
      FLIGHT_hexacopter_P.PIDController_UpperIntegratorSa) {
    FLIGHT_hexacopter_DW.Integrator_DSTATE =
      FLIGHT_hexacopter_P.PIDController_UpperIntegratorSa;
  } else if (FLIGHT_hexacopter_DW.Integrator_DSTATE <
             FLIGHT_hexacopter_P.PIDController_LowerIntegratorSa) {
    FLIGHT_hexacopter_DW.Integrator_DSTATE =
      FLIGHT_hexacopter_P.PIDController_LowerIntegratorSa;
  }

  FLIGHT_hexacopter_DW.Integrator_PrevResetState = static_cast<int8_T>(rtb_NOT);

  // Update for DiscreteIntegrator: '<S55>/Filter' incorporates:
  //   DiscreteIntegrator: '<S60>/Integrator'

  FLIGHT_hexacopter_DW.Filter_DSTATE += FLIGHT_hexacopter_P.Filter_gainval *
    FLIGHT_hexacopter_B.NProdOut;
  FLIGHT_hexacopter_DW.Filter_PrevResetState = static_cast<int8_T>(rtb_NOT);

  // Update for UnitDelay: '<S480>/UD' incorporates:
  //   SampleTimeMath: '<S480>/TSamp'
  //   Sum: '<S480>/Diff'
  //
  //  About '<S480>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //    *
  //  Block description for '<S480>/UD':
  //
  //   Store in Global RAM
  //
  //  Block description for '<S480>/Diff':
  //
  //   Add in CPU

  FLIGHT_hexacopter_DW.UD_DSTATE[0] = FLIGHT_hexacopter_B.TSamp[0];
  FLIGHT_hexacopter_DW.UD_DSTATE[1] = FLIGHT_hexacopter_B.TSamp[1];
  FLIGHT_hexacopter_DW.UD_DSTATE[2] = FLIGHT_hexacopter_B.TSamp[2];

  // Update for UnitDelay: '<S478>/UD'
  //
  //  Block description for '<S478>/UD':
  //
  //   Store in Global RAM

  FLIGHT_hexacopter_DW.UD_DSTATE_j = rtb_Product5_m;

  // Update for UnitDelay: '<S479>/UD'
  //
  //  Block description for '<S479>/UD':
  //
  //   Store in Global RAM

  FLIGHT_hexacopter_DW.UD_DSTATE_g = rtb_Product5_e;

  // Update for UnitDelay: '<S481>/UD'
  //
  //  Block description for '<S481>/UD':
  //
  //   Store in Global RAM

  FLIGHT_hexacopter_DW.UD_DSTATE_n = rtb_Product5_k;

  // Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
  FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE +=
    FLIGHT_hexacopter_P.DiscreteTimeIntegrator_gainva_c * rtb_Product5_dr;
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void FLIGHT_hexacopter_step(int_T tid)
{
  switch (tid) {
   case 0 :
    FLIGHT_hexacopter_step0();
    break;

   case 1 :
    FLIGHT_hexacopter_step1();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void FLIGHT_hexacopter_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const char_T ParameterNameStr[14] = "FDD_M1_STATUS";
    static const char_T ParameterNameStr_0[14] = "FDD_M2_STATUS";
    static const char_T ParameterNameStr_1[14] = "FDD_M3_STATUS";
    static const char_T ParameterNameStr_2[14] = "FDD_M4_STATUS";
    static const char_T ParameterNameStr_3[14] = "FDD_M5_STATUS";
    static const char_T ParameterNameStr_4[14] = "FDD_M6_STATUS";
    static const char_T ParameterNameStr_5[16] = "MPC_Z_VEL_P_ACC";
    static const char_T ParameterNameStr_6[16] = "MPC_Z_VEL_D_ACC";
    static const char_T ParameterNameStr_7[14] = "MPC_THR_HOVER";
    static const char_T ParameterNameStr_8[17] = "DOUBLET_PEAK_ANG";
    static const char_T ParameterNameStr_9[11] = "DOUBLET_DT";
    static const char_T ParameterNameStr_a[13] = "DOUBLET_AXIS";
    static const char_T ParameterNameStr_b[8] = "K_SMC_P";
    static const char_T ParameterNameStr_c[8] = "K_SMC_I";
    static const char_T ParameterNameStr_d[8] = "K_SMC_D";
    static const char_T ParameterNameStr_e[10] = "K_REACH_S";
    static const char_T ParameterNameStr_f[10] = "K_REACH_P";
    static const char_T ParameterNameStr_g[16] = "MPC_Z_VEL_I_ACC";
    static const char_T ParameterNameStr_h[16] = "MC_ROLLRATE_MAX";
    static const char_T ParameterNameStr_i[10] = "MC_ROLL_P";
    static const char_T ParameterNameStr_j[17] = "MC_PITCHRATE_MAX";
    static const char_T ParameterNameStr_k[11] = "MC_PITCH_P";
    static const char_T ParameterNameStr_l[9] = "MPC_XY_P";
    static const char_T ParameterNameStr_m[17] = "MPC_XY_VEL_P_ACC";
    static const char_T ParameterNameStr_n[17] = "IMU_DGYRO_CUTOFF";
    static const char_T ParameterNameStr_o[15] = "MC_PITCHRATE_D";
    static const char_T ParameterNameStr_p[15] = "MC_PITCHRATE_P";
    static const char_T ParameterNameStr_q[15] = "MC_PITCHRATE_I";
    static const char_T ParameterNameStr_r[14] = "MC_ROLLRATE_D";
    static const char_T ParameterNameStr_s[14] = "MC_ROLLRATE_P";
    static const char_T ParameterNameStr_t[14] = "MC_ROLLRATE_I";
    static const char_T ParameterNameStr_u[13] = "MC_YAWRATE_D";
    static const char_T ParameterNameStr_v[13] = "MC_YAWRATE_P";
    static const char_T ParameterNameStr_w[14] = "MC_YAWRATE_FF";
    static const char_T ParameterNameStr_x[13] = "MC_YAWRATE_I";
    real_T tmp;
    int32_T i;

    // Start for RateTransition: '<Root>/rate_transition_arm'
    FLIGHT_hexacopter_B.rate_transition_arm =
      FLIGHT_hexacopter_P.rate_transition_arm_InitialCond;

    // Start for RateTransition: '<Root>/rate_transition_des_p'
    FLIGHT_hexacopter_B.rate_transition_des_p =
      FLIGHT_hexacopter_P.rate_transition_des_p_InitialCo;

    // Start for RateTransition: '<Root>/rate_transition_des_q'
    FLIGHT_hexacopter_B.rate_transition_des_q =
      FLIGHT_hexacopter_P.rate_transition_des_q_InitialCo;

    // Start for RateTransition: '<Root>/rate_transition_des_r'
    FLIGHT_hexacopter_B.rate_transition_des_r =
      FLIGHT_hexacopter_P.rate_transition_des_r_InitialCo;

    // Start for RateTransition: '<Root>/Rate Transition1'
    FLIGHT_hexacopter_B.RateTransition1 =
      FLIGHT_hexacopter_P.RateTransition1_InitialConditio;

    // Start for RateTransition: '<Root>/rate_transition_ctrl_sw'
    FLIGHT_hexacopter_B.rate_transition_ctrl_sw =
      FLIGHT_hexacopter_P.rate_transition_ctrl_sw_Initial;

    // Start for RateTransition: '<Root>/rate_transition_throttle'
    FLIGHT_hexacopter_B.rate_transition_throttle =
      FLIGHT_hexacopter_P.rate_transition_throttle_Initia;

    // Start for RateTransition: '<Root>/Rate Transition4'
    FLIGHT_hexacopter_B.RateTransition4 =
      FLIGHT_hexacopter_P.RateTransition4_InitialConditio;

    // Start for RateTransition: '<Root>/Rate Transition7'
    FLIGHT_hexacopter_B.RateTransition7 =
      FLIGHT_hexacopter_P.RateTransition7_InitialConditio;

    // InitializeConditions for RateTransition: '<Root>/rate_transition_arm'
    FLIGHT_hexacopter_DW.rate_transition_arm_Buffer0 =
      FLIGHT_hexacopter_P.rate_transition_arm_InitialCond;

    // InitializeConditions for RateTransition: '<Root>/rate_transition_des_p'
    FLIGHT_hexacopter_DW.rate_transition_des_p_Buffer0 =
      FLIGHT_hexacopter_P.rate_transition_des_p_InitialCo;

    // InitializeConditions for RateTransition: '<Root>/rate_transition_des_q'
    FLIGHT_hexacopter_DW.rate_transition_des_q_Buffer0 =
      FLIGHT_hexacopter_P.rate_transition_des_q_InitialCo;

    // InitializeConditions for RateTransition: '<Root>/rate_transition_des_r'
    FLIGHT_hexacopter_DW.rate_transition_des_r_Buffer0 =
      FLIGHT_hexacopter_P.rate_transition_des_r_InitialCo;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition1'
    FLIGHT_hexacopter_DW.RateTransition1_Buffer0 =
      FLIGHT_hexacopter_P.RateTransition1_InitialConditio;

    // InitializeConditions for RateTransition: '<Root>/rate_transition_ctrl_sw' 
    FLIGHT_hexacopter_DW.rate_transition_ctrl_sw_Buffer0 =
      FLIGHT_hexacopter_P.rate_transition_ctrl_sw_Initial;

    // InitializeConditions for RateTransition: '<Root>/rate_transition_throttle' 
    FLIGHT_hexacopter_DW.rate_transition_throttle_Buffer =
      FLIGHT_hexacopter_P.rate_transition_throttle_Initia;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition4'
    FLIGHT_hexacopter_DW.RateTransition4_Buffer0 =
      FLIGHT_hexacopter_P.RateTransition4_InitialConditio;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition7'
    FLIGHT_hexacopter_DW.RateTransition7_Buffer0 =
      FLIGHT_hexacopter_P.RateTransition7_InitialConditio;

    // InitializeConditions for DiscreteIntegrator: '<S60>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE =
      FLIGHT_hexacopter_P.PIDController_InitialConditio_a;

    // InitializeConditions for DiscreteIntegrator: '<S55>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE =
      FLIGHT_hexacopter_P.PIDController_InitialConditionF;

    // InitializeConditions for UnitDelay: '<S480>/UD' incorporates:
    //   Sum: '<S480>/Diff'
    //
    //  Block description for '<S480>/UD':
    //
    //   Store in Global RAM
    //
    //  Block description for '<S480>/Diff':
    //
    //   Add in CPU

    FLIGHT_hexacopter_DW.UD_DSTATE[0] =
      FLIGHT_hexacopter_P.DiscreteDerivative2_ICPrevSca_a;
    FLIGHT_hexacopter_DW.UD_DSTATE[1] =
      FLIGHT_hexacopter_P.DiscreteDerivative2_ICPrevSca_a;
    FLIGHT_hexacopter_DW.UD_DSTATE[2] =
      FLIGHT_hexacopter_P.DiscreteDerivative2_ICPrevSca_a;

    // InitializeConditions for UnitDelay: '<S478>/UD'
    //
    //  Block description for '<S478>/UD':
    //
    //   Store in Global RAM

    FLIGHT_hexacopter_DW.UD_DSTATE_j =
      FLIGHT_hexacopter_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for UnitDelay: '<S479>/UD'
    //
    //  Block description for '<S479>/UD':
    //
    //   Store in Global RAM

    FLIGHT_hexacopter_DW.UD_DSTATE_g =
      FLIGHT_hexacopter_P.DiscreteDerivative1_ICPrevScale;

    // InitializeConditions for UnitDelay: '<S481>/UD'
    //
    //  Block description for '<S481>/UD':
    //
    //   Store in Global RAM

    FLIGHT_hexacopter_DW.UD_DSTATE_n =
      FLIGHT_hexacopter_P.DiscreteDerivative3_ICPrevScale;

    // InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' 
    FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_DSTATE =
      FLIGHT_hexacopter_P.DiscreteTimeIntegrator_IC;

    // SystemInitialize for Enabled SubSystem: '<Root>/CAS'
    // Start for MATLABSystem: '<S2>/Read Parameter9'
    FLIGHT_hexacopter_DW.obj_k4.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_k4.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_k4.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_k4.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_k4.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_k4.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_h[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_k4.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Read Parameter9'

    // Start for MATLABSystem: '<S2>/Read Parameter'
    FLIGHT_hexacopter_DW.obj_jz.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_jz.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_jz.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_jz.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_jz.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_jz.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_i[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_jz.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Read Parameter'

    // Start for MATLABSystem: '<S2>/Read Parameter10'
    FLIGHT_hexacopter_DW.obj_ds.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_ds.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_ds.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_ds.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_ds.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_ds.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_j[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_ds.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Read Parameter10'

    // Start for MATLABSystem: '<S2>/Read Parameter1'
    FLIGHT_hexacopter_DW.obj_o.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_o.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_o.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_o.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_o.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_o.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_k[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Read Parameter1'

    // SystemInitialize for Switch: '<S173>/Switch2' incorporates:
    //   Outport: '<S2>/des_p'

    FLIGHT_hexacopter_B.Switch2 = FLIGHT_hexacopter_P.des_p_Y0;

    // SystemInitialize for Switch: '<S122>/Switch2' incorporates:
    //   Outport: '<S2>/des_q'

    FLIGHT_hexacopter_B.Switch2_i = FLIGHT_hexacopter_P.des_q_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/CAS'

    // SystemInitialize for MATLAB Function: '<S3>/MATLAB Function'
    FLIGHT_hexacopter_DW.start_time_usec = -1.0;

    // SystemInitialize for Atomic SubSystem: '<Root>/If Action Subsystem'
    // InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' 
    FLIGHT_hexacopter_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' 
    FLIGHT_hexacopter_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;

    // Start for MATLABSystem: '<S194>/Read Parameter'
    FLIGHT_hexacopter_DW.obj_eq.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_eq.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_eq.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_eq.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_eq.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_eq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_l[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_eq.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S194>/Read Parameter'

    // Start for MATLABSystem: '<S195>/Read Parameter'
    FLIGHT_hexacopter_DW.obj_pi.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_pi.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_pi.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_pi.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_pi.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_pi.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_m[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_pi.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S195>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem'

    // SystemInitialize for Enabled SubSystem: '<Root>/Mixer'
    for (i = 0; i < 6; i++) {
      // SystemInitialize for Saturate: '<S7>/Output_Limits1' incorporates:
      //   Outport: '<S7>/PWM'

      FLIGHT_hexacopter_B.Output_Limits1[i] = FLIGHT_hexacopter_P.PWM_Y0;
    }

    // End of SystemInitialize for SubSystem: '<Root>/Mixer'

    // SystemInitialize for Enabled SubSystem: '<S301>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S303>/In1' incorporates:
    //   Outport: '<S303>/Out1'

    FLIGHT_hexacopter_B.In1 = FLIGHT_hexacopter_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S301>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S304>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S305>/In1' incorporates:
    //   Outport: '<S305>/Out1'

    FLIGHT_hexacopter_B.In1_k = FLIGHT_hexacopter_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S304>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S306>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S307>/In1' incorporates:
    //   Outport: '<S307>/Out1'

    FLIGHT_hexacopter_B.In1_i = FLIGHT_hexacopter_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S306>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<Root>/SAS'
    // InitializeConditions for UnitDelay: '<S315>/Unit Delay1'
    FLIGHT_hexacopter_DW.UnitDelay1_DSTATE =
      FLIGHT_hexacopter_P.UnitDelay1_InitialCondition;

    // InitializeConditions for UnitDelay: '<S315>/Unit Delay2'
    FLIGHT_hexacopter_DW.UnitDelay2_DSTATE =
      FLIGHT_hexacopter_P.UnitDelay2_InitialCondition;

    // InitializeConditions for UnitDelay: '<S312>/UD'
    //
    //  Block description for '<S312>/UD':
    //
    //   Store in Global RAM

    FLIGHT_hexacopter_DW.UD_DSTATE_l =
      FLIGHT_hexacopter_P.DiscreteDerivative2_ICPrevScale;

    // InitializeConditions for DiscreteIntegrator: '<S350>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_p =
      FLIGHT_hexacopter_P.pid_ctrl_rollrate_InitialCondit;

    // InitializeConditions for UnitDelay: '<S370>/Unit Delay1'
    FLIGHT_hexacopter_DW.UnitDelay1_DSTATE_f =
      FLIGHT_hexacopter_P.UnitDelay1_InitialCondition_p;

    // InitializeConditions for UnitDelay: '<S370>/Unit Delay2'
    FLIGHT_hexacopter_DW.UnitDelay2_DSTATE_c =
      FLIGHT_hexacopter_P.UnitDelay2_InitialCondition_e;

    // InitializeConditions for UnitDelay: '<S367>/UD'
    //
    //  Block description for '<S367>/UD':
    //
    //   Store in Global RAM

    FLIGHT_hexacopter_DW.UD_DSTATE_m =
      FLIGHT_hexacopter_P.DiscreteDerivative2_ICPrevSca_n;

    // InitializeConditions for DiscreteIntegrator: '<S405>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_c =
      FLIGHT_hexacopter_P.pid_ctrl_rollrate_InitialCond_j;

    // InitializeConditions for UnitDelay: '<S425>/Unit Delay1'
    FLIGHT_hexacopter_DW.UnitDelay1_DSTATE_e =
      FLIGHT_hexacopter_P.UnitDelay1_InitialCondition_e;

    // InitializeConditions for UnitDelay: '<S425>/Unit Delay2'
    FLIGHT_hexacopter_DW.UnitDelay2_DSTATE_e =
      FLIGHT_hexacopter_P.UnitDelay2_InitialCondition_m;

    // InitializeConditions for UnitDelay: '<S422>/UD'
    //
    //  Block description for '<S422>/UD':
    //
    //   Store in Global RAM

    FLIGHT_hexacopter_DW.UD_DSTATE_jy =
      FLIGHT_hexacopter_P.DiscreteDerivative2_ICPrevSca_o;

    // InitializeConditions for DiscreteIntegrator: '<S460>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_g =
      FLIGHT_hexacopter_P.pid_ctrl_rollrate_InitialCond_p;

    // Start for MATLABSystem: '<S10>/Read Parameter10'
    FLIGHT_hexacopter_DW.obj_c.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_c.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_c.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_c.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_c.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_c.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_n[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/Read Parameter10'

    // Start for MATLABSystem: '<S10>/Read Parameter5'
    FLIGHT_hexacopter_DW.obj_h.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_h.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_h.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_h.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_h.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_h.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_o[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/Read Parameter5'

    // Start for MATLABSystem: '<S10>/Read Parameter3'
    FLIGHT_hexacopter_DW.obj_b.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_b.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_b.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_b.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_b.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_p[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/Read Parameter3'

    // Start for MATLABSystem: '<S10>/Read Parameter4'
    FLIGHT_hexacopter_DW.obj_p.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_p.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_p.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_p.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_p.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_q[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/Read Parameter4'

    // Start for MATLABSystem: '<S10>/Read Parameter2'
    FLIGHT_hexacopter_DW.obj_da.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_da.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_da.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_da.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_da.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_da.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_r[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_da.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/Read Parameter2'

    // Start for MATLABSystem: '<S10>/read_mc_rollrate_p'
    FLIGHT_hexacopter_DW.obj_i.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_i.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_i.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_i.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_i.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_i.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_s[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_i.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/read_mc_rollrate_p'

    // Start for MATLABSystem: '<S10>/Read Parameter1'
    FLIGHT_hexacopter_DW.obj_ea.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_ea.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_ea.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_ea.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_ea.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_ea.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_t[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_ea.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/Read Parameter1'

    // Start for MATLABSystem: '<S10>/Read Parameter8'
    FLIGHT_hexacopter_DW.obj_i4.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_i4.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_i4.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_i4.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_i4.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_i4.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_u[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_i4.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/Read Parameter8'

    // Start for MATLABSystem: '<S10>/Read Parameter6'
    FLIGHT_hexacopter_DW.obj_a.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_a.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_a.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_a.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_a.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_v[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/Read Parameter6'

    // Start for MATLABSystem: '<S10>/Read Parameter9'
    FLIGHT_hexacopter_DW.obj_e.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_e.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_e.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_e.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_e.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_e.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_w[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/Read Parameter9'

    // Start for MATLABSystem: '<S10>/Read Parameter7'
    FLIGHT_hexacopter_DW.obj_j.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_j.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_j.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_j.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_j.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_j.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_x[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/Read Parameter7'

    // SystemInitialize for Sum: '<S310>/Sum5' incorporates:
    //   Outport: '<S10>/tau_roll'

    FLIGHT_hexacopter_B.Sum5_d = FLIGHT_hexacopter_P.tau_roll_Y0;

    // SystemInitialize for Sum: '<S309>/Sum5' incorporates:
    //   Outport: '<S10>/tau_pitch'

    FLIGHT_hexacopter_B.Sum5 = FLIGHT_hexacopter_P.tau_pitch_Y0;

    // SystemInitialize for Sum: '<S10>/Sum' incorporates:
    //   Outport: '<S10>/tau_yaw'

    FLIGHT_hexacopter_B.Sum = FLIGHT_hexacopter_P.tau_yaw_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/SAS'

    // SystemInitialize for Enabled SubSystem: '<S497>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S498>/In1' incorporates:
    //   Outport: '<S498>/Out1'

    FLIGHT_hexacopter_B.In1_h = FLIGHT_hexacopter_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S497>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S501>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S503>/In1' incorporates:
    //   Outport: '<S503>/Out1'

    FLIGHT_hexacopter_B.In1_f = FLIGHT_hexacopter_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S501>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S500>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S502>/In1' incorporates:
    //   Outport: '<S502>/Out1'

    FLIGHT_hexacopter_B.In1_n = FLIGHT_hexacopter_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S500>/Enabled Subsystem'

    // Start for MATLABSystem: '<S497>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_pe.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_pe.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_pe.orbMetadataObj = ORB_ID(vehicle_angular_velocity);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_pe.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_pe.eventStructObj);
    FLIGHT_hexacopter_DW.obj_pe.isSetupComplete = true;

    // Start for MATLABSystem: '<S4>/Read Parameter13'
    FLIGHT_hexacopter_DW.obj_gv.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_gv.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_gv.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_gv.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_gv.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_gv.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_gv.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter13'

    // Start for MATLABSystem: '<S4>/Read Parameter1'
    FLIGHT_hexacopter_DW.obj_j5.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_j5.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_j5.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_j5.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_j5.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_j5.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_j5.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter1'

    // Start for MATLABSystem: '<S4>/Read Parameter2'
    FLIGHT_hexacopter_DW.obj_ao.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_ao.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_ao.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_ao.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_ao.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_ao.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_ao.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter2'

    // Start for MATLABSystem: '<S4>/Read Parameter3'
    FLIGHT_hexacopter_DW.obj_nt.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_nt.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_nt.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_nt.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_nt.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_nt.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_nt.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter3'

    // Start for MATLABSystem: '<S4>/Read Parameter4'
    FLIGHT_hexacopter_DW.obj_cx.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_cx.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_cx.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_cx.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_cx.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_cx.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_cx.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter4'

    // Start for MATLABSystem: '<S4>/Read Parameter5'
    FLIGHT_hexacopter_DW.obj_aq.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_aq.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_aq.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_aq.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_aq.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_aq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_aq.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter5'

    // Start for MATLABSystem: '<Root>/PX4 PWM Output'
    FLIGHT_hexacopter_DW.obj_dl.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_dl.isSetupComplete = false;
    FLIGHT_hexacopter_DW.obj_dl.isInitialized = 1;
    FLIGHT_hexacopter_PWM_setupImpl(&FLIGHT_hexacopter_DW.obj_dl, false, false);
    FLIGHT_hexacopter_DW.obj_dl.isSetupComplete = true;
    FLIGHT__PX4Timestamp_b_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_n);
    FLIGHT__PX4Timestamp_b_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_p);

    // Start for MATLABSystem: '<S496>/SinkBlock' incorporates:
    //   BusAssignment: '<S494>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_hf.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_hf.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_hf.orbMetadataObj = ORB_ID(actuator_motors);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_hf.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_hf.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment, 1);
    FLIGHT_hexacopter_DW.obj_hf.isSetupComplete = true;
    FLIGHT__PX4Timestamp_b_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_o);

    // Start for MATLABSystem: '<S492>/SinkBlock' incorporates:
    //   BusAssignment: '<S490>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_jk.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_jk.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_jk.orbMetadataObj = ORB_ID
      (actuator_controls_status_0);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_jk.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_jk.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_gi, 1);
    FLIGHT_hexacopter_DW.obj_jk.isSetupComplete = true;

    // Start for MATLABSystem: '<S306>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_n2.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_n2.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_n2.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_n2.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_n2.eventStructObj);
    FLIGHT_hexacopter_DW.obj_n2.isSetupComplete = true;

    // Start for MATLABSystem: '<S304>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_ab.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_ab.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_ab.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_ab.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_ab.eventStructObj);
    FLIGHT_hexacopter_DW.obj_ab.isSetupComplete = true;

    // Start for MATLABSystem: '<S500>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_hm.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_hm.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_hm.orbMetadataObj = ORB_ID(actuator_armed);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_hm.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_hm.eventStructObj);
    FLIGHT_hexacopter_DW.obj_hm.isSetupComplete = true;

    // Start for MATLABSystem: '<S301>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_kk.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_kk.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_kk.orbMetadataObj = ORB_ID(vehicle_local_position);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_kk.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_kk.eventStructObj);
    FLIGHT_hexacopter_DW.obj_kk.isSetupComplete = true;

    // Start for MATLABSystem: '<S1>/Read Parameter2'
    FLIGHT_hexacopter_DW.obj_in.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_in.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_in.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_in.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_in.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_in.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_in.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S1>/Read Parameter2'

    // Start for MATLABSystem: '<S1>/Read Parameter4'
    FLIGHT_hexacopter_DW.obj_lx.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_lx.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_lx.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_lx.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_lx.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_lx.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_6[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_lx.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S1>/Read Parameter4'

    // Start for MATLABSystem: '<S1>/Read Parameter1'
    FLIGHT_hexacopter_DW.obj_m.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_m.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_m.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_m.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_m.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_m.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_7[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S1>/Read Parameter1'

    // Start for MATLABSystem: '<S501>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_bw.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_bw.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_bw.orbMetadataObj = ORB_ID(vehicle_status);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_bw.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_bw.eventStructObj);
    FLIGHT_hexacopter_DW.obj_bw.isSetupComplete = true;
    FLIGHT_he_PX4Timestamp_Init(&FLIGHT_hexacopter_DW.PX4Timestamp);

    // Start for MATLABSystem: '<S3>/Read Parameter1'
    FLIGHT_hexacopter_DW.obj_ct.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_ct.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_ct.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_ct.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_ct.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_ct.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_8[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_ct.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/Read Parameter1'

    // Start for MATLABSystem: '<S3>/Read Parameter'
    FLIGHT_hexacopter_DW.obj_cf.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_cf.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_cf.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_cf.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_cf.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_cf.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_9[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_cf.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/Read Parameter'

    // Start for MATLABSystem: '<S3>/Read Parameter2'
    FLIGHT_hexacopter_DW.obj_l.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_l.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_l.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_l.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_l.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_l.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_a[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/Read Parameter2'

    // Start for MATLABSystem: '<S11>/Read Parameter'
    FLIGHT_hexacopter_DW.obj_g.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_g.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_g.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_g.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_g.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_b[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S11>/Read Parameter'

    // Start for MATLABSystem: '<S11>/Read Parameter1'
    FLIGHT_hexacopter_DW.obj_d.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_d.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_d.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_d.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_d.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_c[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S11>/Read Parameter1'

    // Start for MATLABSystem: '<S11>/Read Parameter2'
    FLIGHT_hexacopter_DW.obj_k.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_k.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_k.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_k.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_k.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_d[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S11>/Read Parameter2'

    // Start for MATLABSystem: '<S11>/Read Parameter3'
    FLIGHT_hexacopter_DW.obj_n.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_n.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_n.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_n.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_n.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_n.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_e[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S11>/Read Parameter3'

    // Start for MATLABSystem: '<S11>/Read Parameter4'
    FLIGHT_hexacopter_DW.obj.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_f
      [0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S11>/Read Parameter4'
    FLIGHT__PX4Timestamp_m_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_i);

    // Start for MATLABSystem: '<S512>/SinkBlock' incorporates:
    //   BusAssignment: '<S510>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_mq.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_mq.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_mq.orbMetadataObj = ORB_ID(vehicle_rates_setpoint);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_mq.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_mq.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_a, 1);
    FLIGHT_hexacopter_DW.obj_mq.isSetupComplete = true;
    FLIGHT__PX4Timestamp_m_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_nd);

    // Start for MATLABSystem: '<S507>/SinkBlock' incorporates:
    //   BusAssignment: '<S504>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_ez.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_ez.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_ez.orbMetadataObj = ORB_ID
      (vehicle_attitude_setpoint);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_ez.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_ez.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_p, 1);
    FLIGHT_hexacopter_DW.obj_ez.isSetupComplete = true;
    FLIGHT_he_PX4Timestamp_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_pn);

    // Start for MATLABSystem: '<S509>/SinkBlock' incorporates:
    //   BusAssignment: '<S20>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_pa.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_pa.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_pa.orbMetadataObj = ORB_ID
      (vehicle_local_position_setpoint);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_pa.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_pa.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_g, 1);
    FLIGHT_hexacopter_DW.obj_pa.isSetupComplete = true;

    // Start for MATLABSystem: '<S1>/Read Parameter3'
    FLIGHT_hexacopter_DW.obj_l5.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_l5.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_l5.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_l5.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_l5.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_l5.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_g[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_l5.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S1>/Read Parameter3'
  }
}

// Model terminate function
void FLIGHT_hexacopter_terminate(void)
{
  // Terminate for MATLABSystem: '<S497>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_pe.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_pe.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_pe.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_pe.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_pe.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S497>/SourceBlock'

  // Terminate for Enabled SubSystem: '<Root>/SAS'
  // Terminate for MATLABSystem: '<S10>/Read Parameter10'
  if (!FLIGHT_hexacopter_DW.obj_c.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/Read Parameter10'

  // Terminate for MATLABSystem: '<S10>/Read Parameter5'
  if (!FLIGHT_hexacopter_DW.obj_h.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/Read Parameter5'

  // Terminate for MATLABSystem: '<S10>/Read Parameter3'
  if (!FLIGHT_hexacopter_DW.obj_b.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/Read Parameter3'

  // Terminate for MATLABSystem: '<S10>/Read Parameter4'
  if (!FLIGHT_hexacopter_DW.obj_p.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/Read Parameter4'

  // Terminate for MATLABSystem: '<S10>/Read Parameter2'
  if (!FLIGHT_hexacopter_DW.obj_da.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_da.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/Read Parameter2'

  // Terminate for MATLABSystem: '<S10>/read_mc_rollrate_p'
  if (!FLIGHT_hexacopter_DW.obj_i.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/read_mc_rollrate_p'

  // Terminate for MATLABSystem: '<S10>/Read Parameter1'
  if (!FLIGHT_hexacopter_DW.obj_ea.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_ea.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/Read Parameter1'

  // Terminate for MATLABSystem: '<S10>/Read Parameter8'
  if (!FLIGHT_hexacopter_DW.obj_i4.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_i4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/Read Parameter8'

  // Terminate for MATLABSystem: '<S10>/Read Parameter6'
  if (!FLIGHT_hexacopter_DW.obj_a.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/Read Parameter6'

  // Terminate for MATLABSystem: '<S10>/Read Parameter9'
  if (!FLIGHT_hexacopter_DW.obj_e.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/Read Parameter9'

  // Terminate for MATLABSystem: '<S10>/Read Parameter7'
  if (!FLIGHT_hexacopter_DW.obj_j.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/Read Parameter7'
  // End of Terminate for SubSystem: '<Root>/SAS'

  // Terminate for MATLABSystem: '<S4>/Read Parameter13'
  if (!FLIGHT_hexacopter_DW.obj_gv.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_gv.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter13'

  // Terminate for MATLABSystem: '<S4>/Read Parameter1'
  if (!FLIGHT_hexacopter_DW.obj_j5.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_j5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter1'

  // Terminate for MATLABSystem: '<S4>/Read Parameter2'
  if (!FLIGHT_hexacopter_DW.obj_ao.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_ao.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter2'

  // Terminate for MATLABSystem: '<S4>/Read Parameter3'
  if (!FLIGHT_hexacopter_DW.obj_nt.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_nt.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter3'

  // Terminate for MATLABSystem: '<S4>/Read Parameter4'
  if (!FLIGHT_hexacopter_DW.obj_cx.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_cx.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter4'

  // Terminate for MATLABSystem: '<S4>/Read Parameter5'
  if (!FLIGHT_hexacopter_DW.obj_aq.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_aq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter5'

  // Terminate for MATLABSystem: '<Root>/PX4 PWM Output'
  if (!FLIGHT_hexacopter_DW.obj_dl.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_dl.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_dl.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_dl.isSetupComplete) {
      pwm_disarm(&FLIGHT_hexacopter_DW.obj_dl.armAdvertiseObj);
      pwm_resetServo(FLIGHT_hexacopter_DW.obj_dl.servoCount,
                     FLIGHT_hexacopter_DW.obj_dl.isMain,
                     &FLIGHT_hexacopter_DW.obj_dl.actuatorAdvertiseObj);
      pwm_close(FLIGHT_hexacopter_DW.obj_dl.servoCount,
                &FLIGHT_hexacopter_DW.obj_dl.actuatorAdvertiseObj,
                &FLIGHT_hexacopter_DW.obj_dl.armAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 PWM Output'
  FLIGHT__PX4Timestamp_o_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_n);
  FLIGHT__PX4Timestamp_o_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_p);

  // Terminate for MATLABSystem: '<S496>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_hf.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_hf.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_hf.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_hf.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_hf.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S496>/SinkBlock'
  FLIGHT__PX4Timestamp_o_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_o);

  // Terminate for MATLABSystem: '<S492>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_jk.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_jk.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_jk.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_jk.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_jk.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S492>/SinkBlock'

  // Terminate for MATLABSystem: '<S306>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_n2.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_n2.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_n2.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_n2.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_n2.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S306>/SourceBlock'

  // Terminate for MATLABSystem: '<S304>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_ab.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_ab.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_ab.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_ab.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_ab.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S304>/SourceBlock'

  // Terminate for MATLABSystem: '<S500>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_hm.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_hm.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_hm.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_hm.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_hm.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S500>/SourceBlock'

  // Terminate for MATLABSystem: '<S301>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_kk.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_kk.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_kk.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_kk.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_kk.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S301>/SourceBlock'

  // Terminate for MATLABSystem: '<S1>/Read Parameter2'
  if (!FLIGHT_hexacopter_DW.obj_in.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_in.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1>/Read Parameter2'

  // Terminate for MATLABSystem: '<S1>/Read Parameter4'
  if (!FLIGHT_hexacopter_DW.obj_lx.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_lx.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1>/Read Parameter4'

  // Terminate for MATLABSystem: '<S1>/Read Parameter1'
  if (!FLIGHT_hexacopter_DW.obj_m.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1>/Read Parameter1'

  // Terminate for Atomic SubSystem: '<Root>/If Action Subsystem'
  // Terminate for MATLABSystem: '<S194>/Read Parameter'
  if (!FLIGHT_hexacopter_DW.obj_eq.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_eq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S194>/Read Parameter'

  // Terminate for MATLABSystem: '<S195>/Read Parameter'
  if (!FLIGHT_hexacopter_DW.obj_pi.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_pi.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S195>/Read Parameter'
  // End of Terminate for SubSystem: '<Root>/If Action Subsystem'

  // Terminate for MATLABSystem: '<S501>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_bw.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_bw.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_bw.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_bw.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_bw.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S501>/SourceBlock'
  FLIGHT_he_PX4Timestamp_Term(&FLIGHT_hexacopter_DW.PX4Timestamp);

  // Terminate for MATLABSystem: '<S3>/Read Parameter1'
  if (!FLIGHT_hexacopter_DW.obj_ct.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_ct.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Read Parameter1'

  // Terminate for MATLABSystem: '<S3>/Read Parameter'
  if (!FLIGHT_hexacopter_DW.obj_cf.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_cf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Read Parameter'

  // Terminate for MATLABSystem: '<S3>/Read Parameter2'
  if (!FLIGHT_hexacopter_DW.obj_l.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Read Parameter2'

  // Terminate for Enabled SubSystem: '<Root>/CAS'
  // Terminate for MATLABSystem: '<S2>/Read Parameter9'
  if (!FLIGHT_hexacopter_DW.obj_k4.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_k4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Read Parameter9'

  // Terminate for MATLABSystem: '<S2>/Read Parameter'
  if (!FLIGHT_hexacopter_DW.obj_jz.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_jz.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Read Parameter'

  // Terminate for MATLABSystem: '<S2>/Read Parameter10'
  if (!FLIGHT_hexacopter_DW.obj_ds.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_ds.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Read Parameter10'

  // Terminate for MATLABSystem: '<S2>/Read Parameter1'
  if (!FLIGHT_hexacopter_DW.obj_o.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Read Parameter1'
  // End of Terminate for SubSystem: '<Root>/CAS'

  // Terminate for MATLABSystem: '<S11>/Read Parameter'
  if (!FLIGHT_hexacopter_DW.obj_g.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter'

  // Terminate for MATLABSystem: '<S11>/Read Parameter1'
  if (!FLIGHT_hexacopter_DW.obj_d.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter1'

  // Terminate for MATLABSystem: '<S11>/Read Parameter2'
  if (!FLIGHT_hexacopter_DW.obj_k.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter2'

  // Terminate for MATLABSystem: '<S11>/Read Parameter3'
  if (!FLIGHT_hexacopter_DW.obj_n.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter3'

  // Terminate for MATLABSystem: '<S11>/Read Parameter4'
  if (!FLIGHT_hexacopter_DW.obj.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter4'
  FLIGHT__PX4Timestamp_k_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_i);

  // Terminate for MATLABSystem: '<S512>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_mq.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_mq.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_mq.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_mq.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_mq.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S512>/SinkBlock'
  FLIGHT__PX4Timestamp_k_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_nd);

  // Terminate for MATLABSystem: '<S507>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_ez.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_ez.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_ez.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_ez.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_ez.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S507>/SinkBlock'
  FLIGHT_he_PX4Timestamp_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_pn);

  // Terminate for MATLABSystem: '<S509>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_pa.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_pa.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_pa.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_pa.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_pa.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S509>/SinkBlock'

  // Terminate for MATLABSystem: '<S1>/Read Parameter3'
  if (!FLIGHT_hexacopter_DW.obj_l5.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_l5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1>/Read Parameter3'
}

//
// File trailer for generated code.
//
// [EOF]
//
