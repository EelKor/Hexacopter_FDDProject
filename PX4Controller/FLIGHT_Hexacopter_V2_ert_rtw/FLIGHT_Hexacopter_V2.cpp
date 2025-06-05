//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_Hexacopter_V2.cpp
//
// Code generated for Simulink model 'FLIGHT_Hexacopter_V2'.
//
// Model version                  : 1.165
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Thu Jun  5 13:05:15 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FLIGHT_Hexacopter_V2.h"
#include "FLIGHT_Hexacopter_V2_types.h"
#include "rtwtypes.h"
#include "FLIGHT_Hexacopter_V2_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include "rt_defines.h"

// Block signals (default storage)
B_FLIGHT_Hexacopter_V2_T FLIGHT_Hexacopter_V2_B;

// Block states (default storage)
DW_FLIGHT_Hexacopter_V2_T FLIGHT_Hexacopter_V2_DW;

// Real-time model
RT_MODEL_FLIGHT_Hexacopter_V2_T FLIGHT_Hexacopter_V2_M_ =
  RT_MODEL_FLIGHT_Hexacopter_V2_T();
RT_MODEL_FLIGHT_Hexacopter_V2_T *const FLIGHT_Hexacopter_V2_M =
  &FLIGHT_Hexacopter_V2_M_;

// Forward declaration for local functions
static void FLIGHT_Hexacopter_V2_xzlascl(real32_T cfrom, real32_T cto, int32_T m,
  int32_T n, real32_T A[3], int32_T iA0, int32_T lda);
static void FLIGHT_Hexacopter_V2_xzlascl_g(real32_T cfrom, real32_T cto, int32_T
  m, int32_T n, real32_T *A);
static void FLIGHT_Hexacopter_V2_svd(const real32_T A[3], real32_T U[3],
  real32_T *s, real32_T *V);
static void FLIGHT_Hexacopter_PWM_setupImpl(px4_internal_block_PWM_FLIGHT_T *obj,
  boolean_T armPWM, boolean_T forceFailsafe);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void FLIGHT_Hexacopter_V2_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(FLIGHT_Hexacopter_V2_M, 1));
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
  FLIGHT_Hexacopter_V2_M->Timing.RateInteraction.TID0_1 =
    (FLIGHT_Hexacopter_V2_M->Timing.TaskCounters.TID[1] == 0);

  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (FLIGHT_Hexacopter_V2_M->Timing.TaskCounters.TID[1])++;
  if ((FLIGHT_Hexacopter_V2_M->Timing.TaskCounters.TID[1]) > 3) {// Sample time: [0.004s, 0.0s] 
    FLIGHT_Hexacopter_V2_M->Timing.TaskCounters.TID[1] = 0;
  }
}

// System initialize for atomic system:
void FLIGHT_He_PX4Timestamp_Init(DW_PX4Timestamp_FLIGHT_Hexaco_T *localDW)
{
  // Start for MATLABSystem: '<S24>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_Hexacop_PX4Timestamp(B_PX4Timestamp_FLIGHT_Hexacop_T *localB)
{
  // MATLABSystem: '<S24>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void FLIGHT_He_PX4Timestamp_Term(DW_PX4Timestamp_FLIGHT_Hexaco_T *localDW)
{
  // Terminate for MATLABSystem: '<S24>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S24>/PX4 Timestamp'
}

// System initialize for atomic system:
void FLIGHT__PX4Timestamp_c_Init(DW_PX4Timestamp_FLIGHT_Hexa_j_T *localDW)
{
  // Start for MATLABSystem: '<S25>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_Hexac_PX4Timestamp_j(B_PX4Timestamp_FLIGHT_Hexac_l_T *localB)
{
  // MATLABSystem: '<S25>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void FLIGHT__PX4Timestamp_d_Term(DW_PX4Timestamp_FLIGHT_Hexa_j_T *localDW)
{
  // Terminate for MATLABSystem: '<S25>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S25>/PX4 Timestamp'
}

// System initialize for atomic system:
void FLIGHT__PX4Timestamp_k_Init(DW_PX4Timestamp_FLIGHT_Hexa_f_T *localDW)
{
  // Start for MATLABSystem: '<S28>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_Hexac_PX4Timestamp_p(B_PX4Timestamp_FLIGHT_Hexac_c_T *localB)
{
  // MATLABSystem: '<S28>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void FLIGHT__PX4Timestamp_m_Term(DW_PX4Timestamp_FLIGHT_Hexa_f_T *localDW)
{
  // Terminate for MATLABSystem: '<S28>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S28>/PX4 Timestamp'
}

// System initialize for atomic system:
void FLIGHT_Hex_SourceBlock_Init(DW_SourceBlock_FLIGHT_Hexacop_T *localDW)
{
  // Start for MATLABSystem: '<S217>/SourceBlock'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.orbMetadataObj = ORB_ID(actuator_armed);
  uORB_read_initialize(localDW->obj.orbMetadataObj, &localDW->obj.eventStructObj);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_Hexacopt_SourceBlock(B_SourceBlock_FLIGHT_Hexacopt_T *localB,
  DW_SourceBlock_FLIGHT_Hexacop_T *localDW)
{
  // MATLABSystem: '<S217>/SourceBlock'
  localB->SourceBlock_o1 = uORB_read_step(localDW->obj.orbMetadataObj,
    &localDW->obj.eventStructObj, &localB->SourceBlock_o2, false, 1.0);
}

// Termination for atomic system:
void FLIGHT_Hex_SourceBlock_Term(DW_SourceBlock_FLIGHT_Hexacop_T *localDW)
{
  // Terminate for MATLABSystem: '<S217>/SourceBlock'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uORB_read_terminate(&localDW->obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S217>/SourceBlock'
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

// Function for MATLAB Function: '<S9>/MATLAB Function2'
static void FLIGHT_Hexacopter_V2_xzlascl(real32_T cfrom, real32_T cto, int32_T m,
  int32_T n, real32_T A[3], int32_T iA0, int32_T lda)
{
  real32_T cfromc;
  real32_T ctoc;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    real32_T cfrom1;
    real32_T cto1;
    real32_T mul;
    cfrom1 = cfromc * 1.97215226E-31F;
    cto1 = ctoc / 5.0706024E+30F;
    if ((static_cast<real32_T>(fabs(static_cast<real_T>(cfrom1))) > static_cast<
         real32_T>(fabs(static_cast<real_T>(ctoc)))) && (ctoc != 0.0F)) {
      mul = 1.97215226E-31F;
      cfromc = cfrom1;
    } else if (static_cast<real32_T>(fabs(static_cast<real_T>(cto1))) >
               static_cast<real32_T>(fabs(static_cast<real_T>(cfromc)))) {
      mul = 5.0706024E+30F;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }

    for (int32_T j = 0; j < n; j++) {
      int32_T offset;
      offset = (j * lda + iA0) - 2;
      for (int32_T b_i = 0; b_i < m; b_i++) {
        int32_T tmp;
        tmp = (b_i + offset) + 1;
        A[tmp] *= mul;
      }
    }
  }
}

// Function for MATLAB Function: '<S9>/MATLAB Function2'
static void FLIGHT_Hexacopter_V2_xzlascl_g(real32_T cfrom, real32_T cto, int32_T
  m, int32_T n, real32_T *A)
{
  real32_T cfromc;
  real32_T ctoc;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    real32_T cfrom1;
    real32_T cto1;
    real32_T mul;
    cfrom1 = cfromc * 1.97215226E-31F;
    cto1 = ctoc / 5.0706024E+30F;
    if ((static_cast<real32_T>(fabs(static_cast<real_T>(cfrom1))) >
         static_cast<real32_T>(fabs(static_cast<real_T>(ctoc)))) && (ctoc !=
         0.0F)) {
      mul = 1.97215226E-31F;
      cfromc = cfrom1;
    } else if (static_cast<real32_T>(fabs(static_cast<real_T>(cto1))) >
               static_cast<real32_T>(fabs(static_cast<real_T>(cfromc)))) {
      mul = 5.0706024E+30F;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }

    for (int32_T j = 0; j < n; j++) {
      for (int32_T i = 0; i < m; i++) {
        *A *= mul;
      }
    }
  }
}

// Function for MATLAB Function: '<S9>/MATLAB Function2'
static void FLIGHT_Hexacopter_V2_svd(const real32_T A[3], real32_T U[3],
  real32_T *s, real32_T *V)
{
  int32_T b_k;
  real32_T absxk;
  real32_T b_absxk;
  real32_T scale;
  real32_T t;
  boolean_T doscale;
  boolean_T exitg1;
  FLIGHT_Hexacopter_V2_B.b_A[0] = A[0];
  FLIGHT_Hexacopter_V2_B.b_A[1] = A[1];
  FLIGHT_Hexacopter_V2_B.b_A[2] = A[2];
  doscale = false;
  FLIGHT_Hexacopter_V2_B.anrm = 0.0F;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 3)) {
    absxk = static_cast<real32_T>(fabs(static_cast<real_T>(A[b_k])));
    if (rtIsNaNF(absxk)) {
      FLIGHT_Hexacopter_V2_B.anrm = (rtNaNF);
      exitg1 = true;
    } else {
      if (absxk > FLIGHT_Hexacopter_V2_B.anrm) {
        FLIGHT_Hexacopter_V2_B.anrm = absxk;
      }

      b_k++;
    }
  }

  absxk = FLIGHT_Hexacopter_V2_B.anrm;
  if ((FLIGHT_Hexacopter_V2_B.anrm > 0.0F) && (FLIGHT_Hexacopter_V2_B.anrm <
       9.09494702E-13F)) {
    doscale = true;
    absxk = 9.09494702E-13F;
    FLIGHT_Hexacopter_V2_xzlascl(FLIGHT_Hexacopter_V2_B.anrm, absxk, 3, 1,
      FLIGHT_Hexacopter_V2_B.b_A, 1, 3);
  } else if (FLIGHT_Hexacopter_V2_B.anrm > 1.09951163E+12F) {
    doscale = true;
    absxk = 1.09951163E+12F;
    FLIGHT_Hexacopter_V2_xzlascl(FLIGHT_Hexacopter_V2_B.anrm, absxk, 3, 1,
      FLIGHT_Hexacopter_V2_B.b_A, 1, 3);
  }

  scale = 1.29246971E-26F;
  b_absxk = static_cast<real32_T>(fabs(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.b_A[0])));
  if (b_absxk > 1.29246971E-26F) {
    *s = 1.0F;
    scale = b_absxk;
  } else {
    t = b_absxk / 1.29246971E-26F;
    *s = t * t;
  }

  b_absxk = static_cast<real32_T>(fabs(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.b_A[1])));
  if (b_absxk > scale) {
    t = scale / b_absxk;
    *s = *s * t * t + 1.0F;
    scale = b_absxk;
  } else {
    t = b_absxk / scale;
    *s += t * t;
  }

  b_absxk = static_cast<real32_T>(fabs(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.b_A[2])));
  if (b_absxk > scale) {
    t = scale / b_absxk;
    *s = *s * t * t + 1.0F;
    scale = b_absxk;
  } else {
    t = b_absxk / scale;
    *s += t * t;
  }

  *s = scale * static_cast<real32_T>(sqrt(static_cast<real_T>(*s)));
  if (*s > 0.0F) {
    if (FLIGHT_Hexacopter_V2_B.b_A[0] < 0.0F) {
      *s = -*s;
    }

    if (static_cast<real32_T>(fabs(static_cast<real_T>(*s))) >= 9.86076132E-32F)
    {
      scale = 1.0F / *s;
      FLIGHT_Hexacopter_V2_B.b_A[0] *= scale;
      FLIGHT_Hexacopter_V2_B.b_A[1] *= scale;
      FLIGHT_Hexacopter_V2_B.b_A[2] *= scale;
    } else {
      FLIGHT_Hexacopter_V2_B.b_A[0] /= *s;
      FLIGHT_Hexacopter_V2_B.b_A[1] /= *s;
      FLIGHT_Hexacopter_V2_B.b_A[2] /= *s;
    }

    FLIGHT_Hexacopter_V2_B.b_A[0]++;
    *s = -*s;
  } else {
    *s = 0.0F;
  }

  if (*s != 0.0F) {
    scale = static_cast<real32_T>(fabs(static_cast<real_T>(*s)));
    b_absxk = *s / scale;
    *s = scale;
    U[0] = (-FLIGHT_Hexacopter_V2_B.b_A[0] + 1.0F) * b_absxk;
    U[1] = b_absxk * -FLIGHT_Hexacopter_V2_B.b_A[1];
    U[2] = b_absxk * -FLIGHT_Hexacopter_V2_B.b_A[2];
  } else {
    U[1] = 0.0F;
    U[2] = 0.0F;
    U[0] = 1.0F;
  }

  if (doscale) {
    FLIGHT_Hexacopter_V2_xzlascl_g(absxk, FLIGHT_Hexacopter_V2_B.anrm, 1, 1, s);
  }

  *V = 1.0F;
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

// Model step function for TID0
void FLIGHT_Hexacopter_V2_step0(void)  // Sample time: [0.001s, 0.0s]
{
  real32_T rtb_Product2_n;
  real32_T rtb_Sum5;
  real32_T rtb_Sum_a;
  real32_T rtb_TSamp_g;
  real32_T rtb_d_o;
  real32_T rtb_p_f;
  real32_T rtb_q_j3;
  real32_T rtb_r_p;
  real32_T tmp_4;
  uint32_T tmp;
  uint32_T tmp_0;
  uint32_T tmp_1;
  uint32_T tmp_2;
  uint32_T tmp_3;
  uint32_T tmp_5;
  uint16_T u0;
  boolean_T b_varargout_1;
  boolean_T rtb_Compare_n;

  {                                    // Sample time: [0.001s, 0.0s]
    rate_monotonic_scheduler();
  }

  // RateTransition: '<S10>/Rate Transition4'
  if (FLIGHT_Hexacopter_V2_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<S10>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4 =
      FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0;

    // RateTransition: '<S9>/Rate Transition3'
    FLIGHT_Hexacopter_V2_B.RateTransition3 =
      FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0;

    // RateTransition: '<S351>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.RateTransition =
      FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0;

    // RateTransition: '<S351>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4_a =
      FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_e;
  }

  // End of RateTransition: '<S10>/Rate Transition4'

  // MATLABSystem: '<S214>/SourceBlock'
  b_varargout_1 = uORB_read_step(FLIGHT_Hexacopter_V2_DW.obj_mh.orbMetadataObj,
    &FLIGHT_Hexacopter_V2_DW.obj_mh.eventStructObj, &FLIGHT_Hexacopter_V2_B.r4,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S214>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S215>/Enable'

  // Start for MATLABSystem: '<S214>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S215>/In1'
    FLIGHT_Hexacopter_V2_B.In1_k = FLIGHT_Hexacopter_V2_B.r4;
  }

  // End of Outputs for SubSystem: '<S214>/Enabled Subsystem'

  // Sum: '<S351>/Sum1'
  FLIGHT_Hexacopter_V2_B.roll = FLIGHT_Hexacopter_V2_B.RateTransition4_a -
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[0];

  // RateTransition: '<S351>/Rate Transition6' incorporates:
  //   RateTransition: '<S351>/Rate Transition2'

  if (FLIGHT_Hexacopter_V2_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<S351>/Rate Transition6'
    FLIGHT_Hexacopter_V2_B.RateTransition6 =
      FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0;

    // RateTransition: '<S351>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.RateTransition2 =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0;
  }

  // End of RateTransition: '<S351>/Rate Transition6'

  // DiscreteIntegrator: '<S548>/Integrator'
  if ((FLIGHT_Hexacopter_V2_B.RateTransition6 &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState <= 0)) ||
      ((!FLIGHT_Hexacopter_V2_B.RateTransition6) &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState == 1))) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCondit;
  }

  // Sum: '<S513>/Sum' incorporates:
  //   UnitDelay: '<S513>/Unit Delay1'

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE += FLIGHT_Hexacopter_V2_B.In1_k.xyz
    [0];

  // RateTransition: '<S351>/Rate Transition3' incorporates:
  //   RateTransition generated from: '<Root>/Rate Transition'

  if (FLIGHT_Hexacopter_V2_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<S351>/Rate Transition3'
    FLIGHT_Hexacopter_V2_B.RateTransition3_b =
      FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0_e;

    // RateTransition generated from: '<Root>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.rc_ctrl_switch =
      FLIGHT_Hexacopter_V2_DW.RateTransition_8_Buffer0;
  }

  // End of RateTransition: '<S351>/Rate Transition3'

  // Gain: '<S513>/tau'
  FLIGHT_Hexacopter_V2_B.p = FLIGHT_Hexacopter_V2_P.tau_Gain *
    FLIGHT_Hexacopter_V2_B.RateTransition3_b;

  // Product: '<S514>/Product2'
  FLIGHT_Hexacopter_V2_B.q = FLIGHT_Hexacopter_V2_B.p * FLIGHT_Hexacopter_V2_B.p;

  // Bias: '<S514>/Bias'
  FLIGHT_Hexacopter_V2_B.r_g = FLIGHT_Hexacopter_V2_B.q +
    FLIGHT_Hexacopter_V2_P.Bias_Bias;

  // Gain: '<S514>/Gain'
  FLIGHT_Hexacopter_V2_B.p *= FLIGHT_Hexacopter_V2_P.Gain_Gain_f5;

  // Sum: '<S514>/Add1'
  FLIGHT_Hexacopter_V2_B.d_g = FLIGHT_Hexacopter_V2_B.r_g +
    FLIGHT_Hexacopter_V2_B.p;

  // SampleTimeMath: '<S510>/TSamp' incorporates:
  //   Product: '<S513>/Product1'
  //   Product: '<S514>/Product3'
  //   UnitDelay: '<S513>/Unit Delay1'
  //
  //  About '<S510>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.TSamp = FLIGHT_Hexacopter_V2_B.q /
    FLIGHT_Hexacopter_V2_B.d_g * FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt;

  // Sum: '<S351>/Sum5' incorporates:
  //   DiscreteIntegrator: '<S548>/Integrator'
  //   Product: '<S351>/Product2'
  //   Product: '<S553>/PProd Out'
  //   Sum: '<S510>/Diff'
  //   Sum: '<S557>/Sum'
  //   UnitDelay: '<S510>/UD'
  //
  //  Block description for '<S510>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S510>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_B.Sum5_nz = (FLIGHT_Hexacopter_V2_B.roll *
    FLIGHT_Hexacopter_V2_B.RateTransition +
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE) - (FLIGHT_Hexacopter_V2_B.TSamp -
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE) * FLIGHT_Hexacopter_V2_B.RateTransition2;

  // Switch: '<S2>/Switch' incorporates:
  //   Constant: '<S11>/Constant'
  //   RelationalOperator: '<S11>/Compare'

  if (FLIGHT_Hexacopter_V2_B.rc_ctrl_switch <=
      FLIGHT_Hexacopter_V2_P.CompareToConstant_const) {
    FLIGHT_Hexacopter_V2_B.Switch = FLIGHT_Hexacopter_V2_B.Sum5_nz;
  } else {
    FLIGHT_Hexacopter_V2_B.Switch = FLIGHT_Hexacopter_V2_B.RateTransition3;
  }

  // End of Switch: '<S2>/Switch'

  // RateTransition: '<S350>/Rate Transition' incorporates:
  //   RateTransition: '<S350>/Rate Transition6'

  if (FLIGHT_Hexacopter_V2_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<S350>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.RateTransition_e =
      FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_c;

    // RateTransition: '<S350>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4_b =
      FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_k;

    // RateTransition: '<S350>/Rate Transition6'
    FLIGHT_Hexacopter_V2_B.RateTransition6_a =
      FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_i;
  }

  // End of RateTransition: '<S350>/Rate Transition'

  // Sum: '<S350>/Sum1'
  FLIGHT_Hexacopter_V2_B.roll_h = FLIGHT_Hexacopter_V2_B.RateTransition4_b -
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[1];

  // DiscreteIntegrator: '<S493>/Integrator'
  if ((FLIGHT_Hexacopter_V2_B.RateTransition6_a &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_h <= 0)) ||
      ((!FLIGHT_Hexacopter_V2_B.RateTransition6_a) &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_h == 1))) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_c =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCond_l;
  }

  // RateTransition: '<S350>/Rate Transition2' incorporates:
  //   RateTransition: '<S350>/Rate Transition3'

  if (FLIGHT_Hexacopter_V2_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<S350>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.RateTransition2_b =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_l;

    // RateTransition: '<S350>/Rate Transition3'
    FLIGHT_Hexacopter_V2_B.RateTransition3_be =
      FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0_p;
  }

  // End of RateTransition: '<S350>/Rate Transition2'

  // Sum: '<S458>/Sum' incorporates:
  //   UnitDelay: '<S458>/Unit Delay1'

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_k +=
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[1];

  // Gain: '<S458>/tau'
  FLIGHT_Hexacopter_V2_B.p_e = FLIGHT_Hexacopter_V2_P.tau_Gain_d *
    FLIGHT_Hexacopter_V2_B.RateTransition3_be;

  // Product: '<S459>/Product2'
  FLIGHT_Hexacopter_V2_B.q_e = FLIGHT_Hexacopter_V2_B.p_e *
    FLIGHT_Hexacopter_V2_B.p_e;

  // Bias: '<S459>/Bias'
  FLIGHT_Hexacopter_V2_B.r_a = FLIGHT_Hexacopter_V2_B.q_e +
    FLIGHT_Hexacopter_V2_P.Bias_Bias_o;

  // Gain: '<S459>/Gain'
  FLIGHT_Hexacopter_V2_B.p_e *= FLIGHT_Hexacopter_V2_P.Gain_Gain_bi;

  // Sum: '<S459>/Add1'
  FLIGHT_Hexacopter_V2_B.d_m = FLIGHT_Hexacopter_V2_B.r_a +
    FLIGHT_Hexacopter_V2_B.p_e;

  // SampleTimeMath: '<S455>/TSamp' incorporates:
  //   Product: '<S458>/Product1'
  //   Product: '<S459>/Product3'
  //   UnitDelay: '<S458>/Unit Delay1'
  //
  //  About '<S455>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.TSamp_c = FLIGHT_Hexacopter_V2_B.q_e /
    FLIGHT_Hexacopter_V2_B.d_m * FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_k *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_g;

  // Sum: '<S350>/Sum5' incorporates:
  //   DiscreteIntegrator: '<S493>/Integrator'
  //   Product: '<S350>/Product2'
  //   Product: '<S498>/PProd Out'
  //   Sum: '<S455>/Diff'
  //   Sum: '<S502>/Sum'
  //   UnitDelay: '<S455>/UD'
  //
  //  Block description for '<S455>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S455>/UD':
  //
  //   Store in Global RAM

  rtb_Sum5 = (FLIGHT_Hexacopter_V2_B.roll_h *
              FLIGHT_Hexacopter_V2_B.RateTransition_e +
              FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_c) -
    (FLIGHT_Hexacopter_V2_B.TSamp_c - FLIGHT_Hexacopter_V2_DW.UD_DSTATE_o) *
    FLIGHT_Hexacopter_V2_B.RateTransition2_b;

  // RateTransition: '<S10>/Rate Transition' incorporates:
  //   RateTransition: '<S352>/Rate Transition'
  //   RateTransition: '<S352>/Rate Transition6'

  if (FLIGHT_Hexacopter_V2_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<S10>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.RateTransition_j =
      FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_h;

    // RateTransition: '<S10>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1 =
      FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0;

    // RateTransition: '<S352>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.RateTransition_f =
      FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_hv;

    // RateTransition: '<S352>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4_ar =
      FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_c;

    // RateTransition: '<S352>/Rate Transition6'
    FLIGHT_Hexacopter_V2_B.RateTransition6_o =
      FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_o;
  }

  // End of RateTransition: '<S10>/Rate Transition'

  // Sum: '<S352>/Sum1'
  FLIGHT_Hexacopter_V2_B.roll_l = FLIGHT_Hexacopter_V2_B.RateTransition4_ar -
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[2];

  // DiscreteIntegrator: '<S603>/Integrator'
  if ((FLIGHT_Hexacopter_V2_B.RateTransition6_o &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_hd <= 0)) ||
      ((!FLIGHT_Hexacopter_V2_B.RateTransition6_o) &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_hd == 1))) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_o =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCond_p;
  }

  // RateTransition: '<S352>/Rate Transition2' incorporates:
  //   RateTransition: '<S352>/Rate Transition3'

  if (FLIGHT_Hexacopter_V2_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<S352>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.RateTransition2_d =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d;

    // RateTransition: '<S352>/Rate Transition3'
    FLIGHT_Hexacopter_V2_B.RateTransition3_e =
      FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0_d;
  }

  // End of RateTransition: '<S352>/Rate Transition2'

  // Sum: '<S568>/Sum' incorporates:
  //   UnitDelay: '<S568>/Unit Delay1'

  rtb_Product2_n = FLIGHT_Hexacopter_V2_B.In1_k.xyz[2] +
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_kh;

  // Gain: '<S568>/tau'
  rtb_p_f = FLIGHT_Hexacopter_V2_P.tau_Gain_m *
    FLIGHT_Hexacopter_V2_B.RateTransition3_e;

  // Product: '<S569>/Product2'
  rtb_q_j3 = rtb_p_f * rtb_p_f;

  // Bias: '<S569>/Bias'
  rtb_r_p = rtb_q_j3 + FLIGHT_Hexacopter_V2_P.Bias_Bias_g;

  // Gain: '<S569>/Gain'
  rtb_p_f *= FLIGHT_Hexacopter_V2_P.Gain_Gain_a;

  // Sum: '<S569>/Add1'
  rtb_d_o = rtb_r_p + rtb_p_f;

  // SampleTimeMath: '<S565>/TSamp' incorporates:
  //   Product: '<S568>/Product1'
  //   Product: '<S569>/Product3'
  //
  //  About '<S565>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  rtb_TSamp_g = rtb_q_j3 / rtb_d_o * rtb_Product2_n *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_m;

  // Sum: '<S10>/Sum' incorporates:
  //   DiscreteIntegrator: '<S603>/Integrator'
  //   Product: '<S10>/yawrate_feedforward'
  //   Product: '<S352>/Product2'
  //   Product: '<S608>/PProd Out'
  //   Sum: '<S352>/Sum5'
  //   Sum: '<S565>/Diff'
  //   Sum: '<S612>/Sum'
  //   UnitDelay: '<S565>/UD'
  //
  //  Block description for '<S565>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S565>/UD':
  //
  //   Store in Global RAM

  rtb_Sum_a = ((FLIGHT_Hexacopter_V2_B.roll_l *
                FLIGHT_Hexacopter_V2_B.RateTransition_f +
                FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_o) - (rtb_TSamp_g -
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_k) *
               FLIGHT_Hexacopter_V2_B.RateTransition2_d) +
    FLIGHT_Hexacopter_V2_B.RateTransition_j *
    FLIGHT_Hexacopter_V2_B.RateTransition1;

  // MATLAB Function: '<S14>/pwm_out2'
  tmp_4 = rt_roundf_snf(((-FLIGHT_Hexacopter_V2_B.Switch - rtb_Sum_a) *
    FLIGHT_Hexacopter_V2_B.RateTransition4 / 3.0F +
    FLIGHT_Hexacopter_V2_B.RateTransition4) * 1000.0F);
  if (tmp_4 < 65536.0F) {
    if (tmp_4 >= 0.0F) {
      u0 = static_cast<uint16_T>(tmp_4);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  tmp_5 = u0 + 1000U;
  if (tmp_4 < 65536.0F) {
    if (tmp_4 >= 0.0F) {
      u0 = static_cast<uint16_T>(tmp_4);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  if (u0 + 1000U > 65535U) {
    tmp_5 = 65535U;
  }

  tmp_4 = rt_roundf_snf(((FLIGHT_Hexacopter_V2_B.Switch + rtb_Sum_a) *
    FLIGHT_Hexacopter_V2_B.RateTransition4 / 3.0F +
    FLIGHT_Hexacopter_V2_B.RateTransition4) * 1000.0F);
  if (tmp_4 < 65536.0F) {
    if (tmp_4 >= 0.0F) {
      u0 = static_cast<uint16_T>(tmp_4);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  tmp_3 = u0 + 1000U;
  if (tmp_4 < 65536.0F) {
    if (tmp_4 >= 0.0F) {
      u0 = static_cast<uint16_T>(tmp_4);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  if (u0 + 1000U > 65535U) {
    tmp_3 = 65535U;
  }

  tmp_4 = rt_roundf_snf((((FLIGHT_Hexacopter_V2_B.Switch / 2.0F + rtb_Sum5) -
    rtb_Sum_a) * FLIGHT_Hexacopter_V2_B.RateTransition4 / 3.0F +
    FLIGHT_Hexacopter_V2_B.RateTransition4) * 1000.0F);
  if (tmp_4 < 65536.0F) {
    if (tmp_4 >= 0.0F) {
      u0 = static_cast<uint16_T>(tmp_4);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  tmp_2 = u0 + 1000U;
  if (tmp_4 < 65536.0F) {
    if (tmp_4 >= 0.0F) {
      u0 = static_cast<uint16_T>(tmp_4);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  if (u0 + 1000U > 65535U) {
    tmp_2 = 65535U;
  }

  tmp_4 = rt_roundf_snf((((-rtb_Sum5 - FLIGHT_Hexacopter_V2_B.Switch / 2.0F) +
    rtb_Sum_a) * FLIGHT_Hexacopter_V2_B.RateTransition4 / 3.0F +
    FLIGHT_Hexacopter_V2_B.RateTransition4) * 1000.0F);
  if (tmp_4 < 65536.0F) {
    if (tmp_4 >= 0.0F) {
      u0 = static_cast<uint16_T>(tmp_4);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  tmp_1 = u0 + 1000U;
  if (tmp_4 < 65536.0F) {
    if (tmp_4 >= 0.0F) {
      u0 = static_cast<uint16_T>(tmp_4);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  if (u0 + 1000U > 65535U) {
    tmp_1 = 65535U;
  }

  tmp_4 = rt_roundf_snf((((rtb_Sum5 - FLIGHT_Hexacopter_V2_B.Switch / 2.0F) +
    rtb_Sum_a) * FLIGHT_Hexacopter_V2_B.RateTransition4 / 3.0F +
    FLIGHT_Hexacopter_V2_B.RateTransition4) * 1000.0F);
  if (tmp_4 < 65536.0F) {
    if (tmp_4 >= 0.0F) {
      u0 = static_cast<uint16_T>(tmp_4);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  tmp_0 = u0 + 1000U;
  if (tmp_4 < 65536.0F) {
    if (tmp_4 >= 0.0F) {
      u0 = static_cast<uint16_T>(tmp_4);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  if (u0 + 1000U > 65535U) {
    tmp_0 = 65535U;
  }

  tmp_4 = rt_roundf_snf((((FLIGHT_Hexacopter_V2_B.Switch / 2.0F - rtb_Sum5) -
    rtb_Sum_a) * FLIGHT_Hexacopter_V2_B.RateTransition4 / 3.0F +
    FLIGHT_Hexacopter_V2_B.RateTransition4) * 1000.0F);
  if (tmp_4 < 65536.0F) {
    if (tmp_4 >= 0.0F) {
      u0 = static_cast<uint16_T>(tmp_4);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  tmp = u0 + 1000U;
  if (tmp_4 < 65536.0F) {
    if (tmp_4 >= 0.0F) {
      u0 = static_cast<uint16_T>(tmp_4);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  if (u0 + 1000U > 65535U) {
    tmp = 65535U;
  }

  // MATLABSystem: '<S12>/Read Parameter13'
  if (FLIGHT_Hexacopter_V2_DW.obj_oe.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS) {
    FLIGHT_Hexacopter_V2_DW.obj_oe.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_oe.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_Hexacopter_V2_B.ParamStep_me);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_me = 0;
  }

  // RateTransition generated from: '<Root>/Rate Transition'
  if (FLIGHT_Hexacopter_V2_M->Timing.RateInteraction.TID0_1) {
    // RateTransition generated from: '<Root>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.rc_inject_failure =
      FLIGHT_Hexacopter_V2_DW.RateTransition_4_Buffer0;
  }

  // RelationalOperator: '<S15>/Compare' incorporates:
  //   Constant: '<S15>/Constant'

  rtb_Compare_n = (FLIGHT_Hexacopter_V2_B.rc_inject_failure >=
                   FLIGHT_Hexacopter_V2_P.CompareToConstant_const_a);

  // MATLABSystem: '<S12>/Read Parameter1'
  if (FLIGHT_Hexacopter_V2_DW.obj_aw.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS) {
    FLIGHT_Hexacopter_V2_DW.obj_aw.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_aw.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_Hexacopter_V2_B.ParamStep_n);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_n = 0;
  }

  // MATLABSystem: '<S12>/Read Parameter2'
  if (FLIGHT_Hexacopter_V2_DW.obj_ps.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS) {
    FLIGHT_Hexacopter_V2_DW.obj_ps.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_ps.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_Hexacopter_V2_B.ParamStep_p);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_p = 0;
  }

  // MATLABSystem: '<S12>/Read Parameter3'
  if (FLIGHT_Hexacopter_V2_DW.obj_h.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS) {
    FLIGHT_Hexacopter_V2_DW.obj_h.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_h.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_Hexacopter_V2_B.ParamStep_l);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_l = 0;
  }

  // MATLABSystem: '<S12>/Read Parameter4'
  if (FLIGHT_Hexacopter_V2_DW.obj_jg.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS) {
    FLIGHT_Hexacopter_V2_DW.obj_jg.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_jg.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_Hexacopter_V2_B.ParamStep_j);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_j = 0;
  }

  // MATLABSystem: '<S12>/Read Parameter5'
  if (FLIGHT_Hexacopter_V2_DW.obj_ic5.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS) {
    FLIGHT_Hexacopter_V2_DW.obj_ic5.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_ic5.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_Hexacopter_V2_B.ParamStep_d);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_d = 0;
  }

  // Switch: '<S12>/Switch' incorporates:
  //   Constant: '<S12>/Constant'
  //   DataTypeConversion: '<S12>/Data Type Conversion3'
  //   MATLABSystem: '<S12>/Read Parameter13'
  //
  if (rtb_Compare_n) {
    FLIGHT_Hexacopter_V2_B.d = FLIGHT_Hexacopter_V2_B.ParamStep_me;
  } else {
    FLIGHT_Hexacopter_V2_B.d = FLIGHT_Hexacopter_V2_P.Constant_Value_hs;
  }

  // Gain: '<S16>/Gain' incorporates:
  //   Switch: '<S12>/Switch'

  FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Gain_Gain *
    FLIGHT_Hexacopter_V2_B.d;

  // Saturate: '<S16>/Saturation'
  if (FLIGHT_Hexacopter_V2_B.u0 > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat) {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat;
  } else if (FLIGHT_Hexacopter_V2_B.u0 <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat) {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat;
  }

  // DataTypeConversion: '<S12>/Data Type Conversion7' incorporates:
  //   Constant: '<S16>/Constant'
  //   DataTypeConversion: '<S12>/Data Type Conversion6'
  //   MATLAB Function: '<S14>/pwm_out2'
  //   Product: '<S16>/Product'
  //   Saturate: '<S16>/Saturation'
  //   Sum: '<S16>/Sum'
  //   Sum: '<S16>/Sum1'

  FLIGHT_Hexacopter_V2_B.d = floor((static_cast<real_T>(static_cast<uint16_T>
    (tmp_5)) - FLIGHT_Hexacopter_V2_P.Constant_Value_b) *
    FLIGHT_Hexacopter_V2_B.u0 + FLIGHT_Hexacopter_V2_P.Constant_Value_b);
  if (rtIsNaN(FLIGHT_Hexacopter_V2_B.d) || rtIsInf(FLIGHT_Hexacopter_V2_B.d)) {
    FLIGHT_Hexacopter_V2_B.d = 0.0;
  } else {
    FLIGHT_Hexacopter_V2_B.d = fmod(FLIGHT_Hexacopter_V2_B.d, 65536.0);
  }

  // Switch: '<S12>/Switch1' incorporates:
  //   Constant: '<S12>/Constant1'
  //   DataTypeConversion: '<S12>/Data Type Conversion2'
  //   MATLABSystem: '<S12>/Read Parameter1'
  //
  if (rtb_Compare_n) {
    FLIGHT_Hexacopter_V2_B.d1 = FLIGHT_Hexacopter_V2_B.ParamStep_n;
  } else {
    FLIGHT_Hexacopter_V2_B.d1 = FLIGHT_Hexacopter_V2_P.Constant1_Value;
  }

  // Gain: '<S17>/Gain' incorporates:
  //   Switch: '<S12>/Switch1'

  FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Gain_Gain_l *
    FLIGHT_Hexacopter_V2_B.d1;

  // Saturate: '<S17>/Saturation'
  if (FLIGHT_Hexacopter_V2_B.u0 > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_f)
  {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_f;
  } else if (FLIGHT_Hexacopter_V2_B.u0 <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_a) {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_a;
  }

  // DataTypeConversion: '<S12>/Data Type Conversion7' incorporates:
  //   Constant: '<S17>/Constant'
  //   DataTypeConversion: '<S12>/Data Type Conversion6'
  //   MATLAB Function: '<S14>/pwm_out2'
  //   Product: '<S17>/Product'
  //   Saturate: '<S17>/Saturation'
  //   Sum: '<S17>/Sum'
  //   Sum: '<S17>/Sum1'

  FLIGHT_Hexacopter_V2_B.d1 = floor((static_cast<real_T>(static_cast<uint16_T>
    (tmp_3)) - FLIGHT_Hexacopter_V2_P.Constant_Value_lg) *
    FLIGHT_Hexacopter_V2_B.u0 + FLIGHT_Hexacopter_V2_P.Constant_Value_lg);
  if (rtIsNaN(FLIGHT_Hexacopter_V2_B.d1) || rtIsInf(FLIGHT_Hexacopter_V2_B.d1))
  {
    FLIGHT_Hexacopter_V2_B.d1 = 0.0;
  } else {
    FLIGHT_Hexacopter_V2_B.d1 = fmod(FLIGHT_Hexacopter_V2_B.d1, 65536.0);
  }

  // Switch: '<S12>/Switch2' incorporates:
  //   Constant: '<S12>/Constant2'
  //   DataTypeConversion: '<S12>/Data Type Conversion'
  //   MATLABSystem: '<S12>/Read Parameter2'
  //
  if (rtb_Compare_n) {
    FLIGHT_Hexacopter_V2_B.d2 = FLIGHT_Hexacopter_V2_B.ParamStep_p;
  } else {
    FLIGHT_Hexacopter_V2_B.d2 = FLIGHT_Hexacopter_V2_P.Constant2_Value;
  }

  // Gain: '<S18>/Gain' incorporates:
  //   Switch: '<S12>/Switch2'

  FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Gain_Gain_e *
    FLIGHT_Hexacopter_V2_B.d2;

  // Saturate: '<S18>/Saturation'
  if (FLIGHT_Hexacopter_V2_B.u0 > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_e)
  {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_e;
  } else if (FLIGHT_Hexacopter_V2_B.u0 <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_m) {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_m;
  }

  // DataTypeConversion: '<S12>/Data Type Conversion7' incorporates:
  //   Constant: '<S18>/Constant'
  //   DataTypeConversion: '<S12>/Data Type Conversion6'
  //   MATLAB Function: '<S14>/pwm_out2'
  //   Product: '<S18>/Product'
  //   Saturate: '<S18>/Saturation'
  //   Sum: '<S18>/Sum'
  //   Sum: '<S18>/Sum1'

  FLIGHT_Hexacopter_V2_B.d2 = floor((static_cast<real_T>(static_cast<uint16_T>
    (tmp_2)) - FLIGHT_Hexacopter_V2_P.Constant_Value_n) *
    FLIGHT_Hexacopter_V2_B.u0 + FLIGHT_Hexacopter_V2_P.Constant_Value_n);
  if (rtIsNaN(FLIGHT_Hexacopter_V2_B.d2) || rtIsInf(FLIGHT_Hexacopter_V2_B.d2))
  {
    FLIGHT_Hexacopter_V2_B.d2 = 0.0;
  } else {
    FLIGHT_Hexacopter_V2_B.d2 = fmod(FLIGHT_Hexacopter_V2_B.d2, 65536.0);
  }

  // Switch: '<S12>/Switch3' incorporates:
  //   Constant: '<S12>/Constant3'
  //   DataTypeConversion: '<S12>/Data Type Conversion4'
  //   MATLABSystem: '<S12>/Read Parameter3'
  //
  if (rtb_Compare_n) {
    FLIGHT_Hexacopter_V2_B.d3 = FLIGHT_Hexacopter_V2_B.ParamStep_l;
  } else {
    FLIGHT_Hexacopter_V2_B.d3 = FLIGHT_Hexacopter_V2_P.Constant3_Value;
  }

  // Gain: '<S19>/Gain' incorporates:
  //   Switch: '<S12>/Switch3'

  FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Gain_Gain_n *
    FLIGHT_Hexacopter_V2_B.d3;

  // Saturate: '<S19>/Saturation'
  if (FLIGHT_Hexacopter_V2_B.u0 > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_a)
  {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_a;
  } else if (FLIGHT_Hexacopter_V2_B.u0 <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d) {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d;
  }

  // DataTypeConversion: '<S12>/Data Type Conversion7' incorporates:
  //   Constant: '<S19>/Constant'
  //   DataTypeConversion: '<S12>/Data Type Conversion6'
  //   MATLAB Function: '<S14>/pwm_out2'
  //   Product: '<S19>/Product'
  //   Saturate: '<S19>/Saturation'
  //   Sum: '<S19>/Sum'
  //   Sum: '<S19>/Sum1'

  FLIGHT_Hexacopter_V2_B.d3 = floor((static_cast<real_T>(static_cast<uint16_T>
    (tmp_1)) - FLIGHT_Hexacopter_V2_P.Constant_Value_e3) *
    FLIGHT_Hexacopter_V2_B.u0 + FLIGHT_Hexacopter_V2_P.Constant_Value_e3);
  if (rtIsNaN(FLIGHT_Hexacopter_V2_B.d3) || rtIsInf(FLIGHT_Hexacopter_V2_B.d3))
  {
    FLIGHT_Hexacopter_V2_B.d3 = 0.0;
  } else {
    FLIGHT_Hexacopter_V2_B.d3 = fmod(FLIGHT_Hexacopter_V2_B.d3, 65536.0);
  }

  // Switch: '<S12>/Switch4' incorporates:
  //   Constant: '<S12>/Constant4'
  //   DataTypeConversion: '<S12>/Data Type Conversion1'
  //   MATLABSystem: '<S12>/Read Parameter4'
  //
  if (rtb_Compare_n) {
    FLIGHT_Hexacopter_V2_B.d4 = FLIGHT_Hexacopter_V2_B.ParamStep_j;
  } else {
    FLIGHT_Hexacopter_V2_B.d4 = FLIGHT_Hexacopter_V2_P.Constant4_Value;
  }

  // Gain: '<S20>/Gain' incorporates:
  //   Switch: '<S12>/Switch4'

  FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Gain_Gain_g *
    FLIGHT_Hexacopter_V2_B.d4;

  // Saturate: '<S20>/Saturation'
  if (FLIGHT_Hexacopter_V2_B.u0 > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_en)
  {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_en;
  } else if (FLIGHT_Hexacopter_V2_B.u0 <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_o) {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_o;
  }

  // DataTypeConversion: '<S12>/Data Type Conversion7' incorporates:
  //   Constant: '<S20>/Constant'
  //   DataTypeConversion: '<S12>/Data Type Conversion6'
  //   MATLAB Function: '<S14>/pwm_out2'
  //   Product: '<S20>/Product'
  //   Saturate: '<S20>/Saturation'
  //   Sum: '<S20>/Sum'
  //   Sum: '<S20>/Sum1'

  FLIGHT_Hexacopter_V2_B.d4 = floor((static_cast<real_T>(static_cast<uint16_T>
    (tmp_0)) - FLIGHT_Hexacopter_V2_P.Constant_Value_d) *
    FLIGHT_Hexacopter_V2_B.u0 + FLIGHT_Hexacopter_V2_P.Constant_Value_d);
  if (rtIsNaN(FLIGHT_Hexacopter_V2_B.d4) || rtIsInf(FLIGHT_Hexacopter_V2_B.d4))
  {
    FLIGHT_Hexacopter_V2_B.d4 = 0.0;
  } else {
    FLIGHT_Hexacopter_V2_B.d4 = fmod(FLIGHT_Hexacopter_V2_B.d4, 65536.0);
  }

  // Switch: '<S12>/Switch5' incorporates:
  //   Constant: '<S12>/Constant5'
  //   DataTypeConversion: '<S12>/Data Type Conversion5'
  //   MATLABSystem: '<S12>/Read Parameter5'
  //
  if (rtb_Compare_n) {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_B.ParamStep_d;
  } else {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Constant5_Value;
  }

  // Gain: '<S21>/Gain' incorporates:
  //   Switch: '<S12>/Switch5'

  FLIGHT_Hexacopter_V2_B.u0 *= FLIGHT_Hexacopter_V2_P.Gain_Gain_f;

  // Saturate: '<S21>/Saturation'
  if (FLIGHT_Hexacopter_V2_B.u0 > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_k)
  {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_k;
  } else if (FLIGHT_Hexacopter_V2_B.u0 <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_k) {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_k;
  }

  // DataTypeConversion: '<S12>/Data Type Conversion7' incorporates:
  //   Constant: '<S21>/Constant'
  //   DataTypeConversion: '<S12>/Data Type Conversion6'
  //   MATLAB Function: '<S14>/pwm_out2'
  //   Product: '<S21>/Product'
  //   Saturate: '<S21>/Saturation'
  //   Sum: '<S21>/Sum'
  //   Sum: '<S21>/Sum1'

  FLIGHT_Hexacopter_V2_B.u0 = floor((static_cast<real_T>(static_cast<uint16_T>
    (tmp)) - FLIGHT_Hexacopter_V2_P.Constant_Value_lv) *
    FLIGHT_Hexacopter_V2_B.u0 + FLIGHT_Hexacopter_V2_P.Constant_Value_lv);
  if (rtIsNaN(FLIGHT_Hexacopter_V2_B.u0) || rtIsInf(FLIGHT_Hexacopter_V2_B.u0))
  {
    FLIGHT_Hexacopter_V2_B.u0 = 0.0;
  } else {
    FLIGHT_Hexacopter_V2_B.u0 = fmod(FLIGHT_Hexacopter_V2_B.u0, 65536.0);
  }

  // RateTransition generated from: '<Root>/Rate Transition2'
  if (FLIGHT_Hexacopter_V2_M->Timing.RateInteraction.TID0_1) {
    // RateTransition generated from: '<Root>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.VehicleStatus_flag_armed =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_16_Buffer0;

    // RateTransition generated from: '<Root>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.VehicleStatus_flag_kill =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_17_Buffer0;
  }

  // End of RateTransition generated from: '<Root>/Rate Transition2'

  // MATLABSystem: '<S1>/PX4 PWM Output' incorporates:
  //   DataTypeConversion: '<S12>/Data Type Conversion7'

  for (FLIGHT_Hexacopter_V2_B.ParamStep_me = 0;
       FLIGHT_Hexacopter_V2_B.ParamStep_me < 8;
       FLIGHT_Hexacopter_V2_B.ParamStep_me++) {
    FLIGHT_Hexacopter_V2_B.pwmValue[FLIGHT_Hexacopter_V2_B.ParamStep_me] = 0U;
  }

  FLIGHT_Hexacopter_V2_B.pwmValue[0] = static_cast<uint16_T>
    (FLIGHT_Hexacopter_V2_B.d < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>
      (-static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_Hexacopter_V2_B.d))))
     : static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.d)));
  FLIGHT_Hexacopter_V2_B.pwmValue[1] = static_cast<uint16_T>
    (FLIGHT_Hexacopter_V2_B.d1 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>
      (-static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_Hexacopter_V2_B.d1))))
     : static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.d1)));
  FLIGHT_Hexacopter_V2_B.pwmValue[2] = static_cast<uint16_T>
    (FLIGHT_Hexacopter_V2_B.d2 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>
      (-static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_Hexacopter_V2_B.d2))))
     : static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.d2)));
  FLIGHT_Hexacopter_V2_B.pwmValue[3] = static_cast<uint16_T>
    (FLIGHT_Hexacopter_V2_B.d3 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>
      (-static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_Hexacopter_V2_B.d3))))
     : static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.d3)));
  FLIGHT_Hexacopter_V2_B.pwmValue[4] = static_cast<uint16_T>
    (FLIGHT_Hexacopter_V2_B.d4 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>
      (-static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_Hexacopter_V2_B.d4))))
     : static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.d4)));
  FLIGHT_Hexacopter_V2_B.pwmValue[5] = static_cast<uint16_T>
    (FLIGHT_Hexacopter_V2_B.u0 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>
      (-static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_Hexacopter_V2_B.u0))))
     : static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u0)));
  if (FLIGHT_Hexacopter_V2_B.VehicleStatus_flag_armed) {
    if (!FLIGHT_Hexacopter_V2_DW.obj_md.isArmed) {
      FLIGHT_Hexacopter_V2_DW.obj_md.isArmed = true;
      pwm_arm(&FLIGHT_Hexacopter_V2_DW.obj_md.armAdvertiseObj);
    }

    pwm_setServo(FLIGHT_Hexacopter_V2_DW.obj_md.servoCount,
                 FLIGHT_Hexacopter_V2_DW.obj_md.channelMask,
                 &FLIGHT_Hexacopter_V2_B.pwmValue[0],
                 FLIGHT_Hexacopter_V2_DW.obj_md.isMain,
                 &FLIGHT_Hexacopter_V2_DW.obj_md.actuatorAdvertiseObj);
  } else {
    pwm_disarm(&FLIGHT_Hexacopter_V2_DW.obj_md.armAdvertiseObj);
    FLIGHT_Hexacopter_V2_DW.obj_md.isArmed = false;
    pwm_resetServo(FLIGHT_Hexacopter_V2_DW.obj_md.servoCount,
                   FLIGHT_Hexacopter_V2_DW.obj_md.isMain,
                   &FLIGHT_Hexacopter_V2_DW.obj_md.actuatorAdvertiseObj);
  }

  if (FLIGHT_Hexacopter_V2_DW.obj_md.isMain) {
    if (FLIGHT_Hexacopter_V2_B.VehicleStatus_flag_kill) {
      pwm_disarm(&FLIGHT_Hexacopter_V2_DW.obj_md.armAdvertiseObj);
    } else {
      pwm_arm(&FLIGHT_Hexacopter_V2_DW.obj_md.armAdvertiseObj);
    }
  }

  // End of MATLABSystem: '<S1>/PX4 PWM Output'
  FLIGHT_Hexacop_PX4Timestamp(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_e);

  // BusAssignment: '<S29>/Bus Assignment' incorporates:
  //   MATLABSystem: '<S29>/PX4 Timestamp'
  //   MATLABSystem: '<S3>/PX4 Timestamp'

  FLIGHT_Hexacopter_V2_B.BusAssignment_e.timestamp_sample = hrt_absolute_time();
  FLIGHT_Hexacopter_V2_B.BusAssignment_e.timestamp =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp_e.PX4Timestamp;

  // Saturate: '<S23>/Saturation' incorporates:
  //   MATLAB Function: '<S14>/pwm_out2'

  if (static_cast<uint16_T>(tmp_5) >
      FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d;
  } else if (static_cast<uint16_T>(tmp_5) <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0;
  } else {
    u0 = static_cast<uint16_T>(tmp_5);
  }

  // BusAssignment: '<S29>/Bus Assignment' incorporates:
  //   Constant: '<S23>/Constant'
  //   Gain: '<S23>/Gain'
  //   Saturate: '<S23>/Saturation'
  //   Sum: '<S23>/Subtract'

  FLIGHT_Hexacopter_V2_B.BusAssignment_e.control[0] = (static_cast<real32_T>(u0)
    - FLIGHT_Hexacopter_V2_P.Constant_Value_ew) *
    FLIGHT_Hexacopter_V2_P.Gain_Gain_h;

  // Saturate: '<S23>/Saturation' incorporates:
  //   MATLAB Function: '<S14>/pwm_out2'

  if (static_cast<uint16_T>(tmp_3) >
      FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d;
  } else if (static_cast<uint16_T>(tmp_3) <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0;
  } else {
    u0 = static_cast<uint16_T>(tmp_3);
  }

  // BusAssignment: '<S29>/Bus Assignment' incorporates:
  //   Constant: '<S23>/Constant'
  //   Gain: '<S23>/Gain'
  //   Saturate: '<S23>/Saturation'
  //   Sum: '<S23>/Subtract'

  FLIGHT_Hexacopter_V2_B.BusAssignment_e.control[1] = (static_cast<real32_T>(u0)
    - FLIGHT_Hexacopter_V2_P.Constant_Value_ew) *
    FLIGHT_Hexacopter_V2_P.Gain_Gain_h;

  // Saturate: '<S23>/Saturation' incorporates:
  //   MATLAB Function: '<S14>/pwm_out2'

  if (static_cast<uint16_T>(tmp_2) >
      FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d;
  } else if (static_cast<uint16_T>(tmp_2) <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0;
  } else {
    u0 = static_cast<uint16_T>(tmp_2);
  }

  // BusAssignment: '<S29>/Bus Assignment' incorporates:
  //   Constant: '<S23>/Constant'
  //   Gain: '<S23>/Gain'
  //   Saturate: '<S23>/Saturation'
  //   Sum: '<S23>/Subtract'

  FLIGHT_Hexacopter_V2_B.BusAssignment_e.control[2] = (static_cast<real32_T>(u0)
    - FLIGHT_Hexacopter_V2_P.Constant_Value_ew) *
    FLIGHT_Hexacopter_V2_P.Gain_Gain_h;

  // Saturate: '<S23>/Saturation' incorporates:
  //   MATLAB Function: '<S14>/pwm_out2'

  if (static_cast<uint16_T>(tmp_1) >
      FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d;
  } else if (static_cast<uint16_T>(tmp_1) <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0;
  } else {
    u0 = static_cast<uint16_T>(tmp_1);
  }

  // BusAssignment: '<S29>/Bus Assignment' incorporates:
  //   Constant: '<S23>/Constant'
  //   Gain: '<S23>/Gain'
  //   Saturate: '<S23>/Saturation'
  //   Sum: '<S23>/Subtract'

  FLIGHT_Hexacopter_V2_B.BusAssignment_e.control[3] = (static_cast<real32_T>(u0)
    - FLIGHT_Hexacopter_V2_P.Constant_Value_ew) *
    FLIGHT_Hexacopter_V2_P.Gain_Gain_h;

  // Saturate: '<S23>/Saturation' incorporates:
  //   MATLAB Function: '<S14>/pwm_out2'

  if (static_cast<uint16_T>(tmp_0) >
      FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d;
  } else if (static_cast<uint16_T>(tmp_0) <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0;
  } else {
    u0 = static_cast<uint16_T>(tmp_0);
  }

  // BusAssignment: '<S29>/Bus Assignment' incorporates:
  //   Constant: '<S23>/Constant'
  //   Gain: '<S23>/Gain'
  //   Saturate: '<S23>/Saturation'
  //   Sum: '<S23>/Subtract'

  FLIGHT_Hexacopter_V2_B.BusAssignment_e.control[4] = (static_cast<real32_T>(u0)
    - FLIGHT_Hexacopter_V2_P.Constant_Value_ew) *
    FLIGHT_Hexacopter_V2_P.Gain_Gain_h;

  // Saturate: '<S23>/Saturation' incorporates:
  //   MATLAB Function: '<S14>/pwm_out2'

  if (static_cast<uint16_T>(tmp) > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d)
  {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d;
  } else if (static_cast<uint16_T>(tmp) <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0;
  } else {
    u0 = static_cast<uint16_T>(tmp);
  }

  // BusAssignment: '<S29>/Bus Assignment' incorporates:
  //   Constant: '<S23>/Constant'
  //   Constant: '<S3>/Constant4'
  //   Gain: '<S23>/Gain'
  //   Saturate: '<S23>/Saturation'
  //   Sum: '<S23>/Subtract'

  FLIGHT_Hexacopter_V2_B.BusAssignment_e.control[5] = (static_cast<real32_T>(u0)
    - FLIGHT_Hexacopter_V2_P.Constant_Value_ew) *
    FLIGHT_Hexacopter_V2_P.Gain_Gain_h;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e.reversible_flags = 0U;
  for (FLIGHT_Hexacopter_V2_B.ParamStep_me = 0;
       FLIGHT_Hexacopter_V2_B.ParamStep_me < 6;
       FLIGHT_Hexacopter_V2_B.ParamStep_me++) {
    u0 =
      FLIGHT_Hexacopter_V2_P.Constant4_Value_f[FLIGHT_Hexacopter_V2_B.ParamStep_me];
    if (u0 > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d) {
      u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d;
    } else if (u0 < FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0) {
      u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0;
    }

    FLIGHT_Hexacopter_V2_B.BusAssignment_e.control[FLIGHT_Hexacopter_V2_B.ParamStep_me
      + 6] = (static_cast<real32_T>(u0) -
              FLIGHT_Hexacopter_V2_P.Constant_Value_ew) *
      FLIGHT_Hexacopter_V2_P.Gain_Gain_h;
    FLIGHT_Hexacopter_V2_B.BusAssignment_e._padding0[FLIGHT_Hexacopter_V2_B.ParamStep_me]
      = 0U;
  }

  // MATLABSystem: '<S40>/SinkBlock' incorporates:
  //   BusAssignment: '<S29>/Bus Assignment'

  uORB_write_step(FLIGHT_Hexacopter_V2_DW.obj_nf.orbMetadataObj,
                  &FLIGHT_Hexacopter_V2_DW.obj_nf.orbAdvertiseObj,
                  &FLIGHT_Hexacopter_V2_B.BusAssignment_e);
  FLIGHT_Hexacop_PX4Timestamp(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_c);

  // BusAssignment: '<S24>/Bus Assignment' incorporates:
  //   MATLABSystem: '<S24>/PX4 Timestamp'

  FLIGHT_Hexacopter_V2_B.BusAssignment_j.timestamp =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp_c.PX4Timestamp;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j.control_power[0] =
    FLIGHT_Hexacopter_V2_B.Sum5_nz;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j.control_power[1] = rtb_Sum5;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j.control_power[2] = rtb_Sum_a;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j._padding0[0] = 0U;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j._padding0[1] = 0U;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j._padding0[2] = 0U;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j._padding0[3] = 0U;

  // MATLABSystem: '<S32>/SinkBlock' incorporates:
  //   BusAssignment: '<S24>/Bus Assignment'

  uORB_write_step(FLIGHT_Hexacopter_V2_DW.obj_fe.orbMetadataObj,
                  &FLIGHT_Hexacopter_V2_DW.obj_fe.orbAdvertiseObj,
                  &FLIGHT_Hexacopter_V2_B.BusAssignment_j);

  // Sum: '<S568>/Sum1' incorporates:
  //   Bias: '<S569>/Bias1'
  //   Gain: '<S568>/Gain1'
  //   Product: '<S568>/Product5'
  //   Product: '<S569>/Product4'
  //   Sum: '<S568>/Sum2'
  //   UnaryMinus: '<S569>/Unary Minus'
  //   UnitDelay: '<S568>/Unit Delay1'
  //   UnitDelay: '<S568>/Unit Delay2'

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_kh = ((-rtb_q_j3 +
    FLIGHT_Hexacopter_V2_P.Bias1_Bias) / rtb_d_o * rtb_Product2_n +
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[2]) * FLIGHT_Hexacopter_V2_P.Gain1_Gain_d +
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE;

  // Sum: '<S568>/Sum3' incorporates:
  //   Product: '<S568>/Product2'
  //   Product: '<S569>/Product5'
  //   Sum: '<S569>/Add3'
  //   UnitDelay: '<S568>/Unit Delay2'

  FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE = FLIGHT_Hexacopter_V2_B.In1_k.xyz[2]
    - 1.0F / rtb_d_o * (rtb_r_p - rtb_p_f) * rtb_Product2_n;

  // RateTransition: '<S352>/Rate Transition1' incorporates:
  //   RateTransition: '<S350>/Rate Transition1'

  if (FLIGHT_Hexacopter_V2_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<S352>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1_c =
      FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_m;

    // RateTransition: '<S350>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1_d =
      FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_l;
  }

  // End of RateTransition: '<S352>/Rate Transition1'

  // Sum: '<S458>/Sum1' incorporates:
  //   Bias: '<S459>/Bias1'
  //   Gain: '<S458>/Gain1'
  //   Product: '<S458>/Product5'
  //   Product: '<S459>/Product4'
  //   Sum: '<S458>/Sum2'
  //   UnaryMinus: '<S459>/Unary Minus'
  //   UnitDelay: '<S458>/Unit Delay1'
  //   UnitDelay: '<S458>/Unit Delay2'

  FLIGHT_Hexacopter_V2_B.Sum5_nz = ((-FLIGHT_Hexacopter_V2_B.q_e +
    FLIGHT_Hexacopter_V2_P.Bias1_Bias_k) / FLIGHT_Hexacopter_V2_B.d_m *
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_k +
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[1]) * FLIGHT_Hexacopter_V2_P.Gain1_Gain_m +
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_l;

  // Product: '<S458>/Product2' incorporates:
  //   Product: '<S459>/Product5'
  //   Sum: '<S459>/Add3'
  //   UnitDelay: '<S458>/Unit Delay1'

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_k *= 1.0F /
    FLIGHT_Hexacopter_V2_B.d_m * (FLIGHT_Hexacopter_V2_B.r_a -
    FLIGHT_Hexacopter_V2_B.p_e);

  // Sum: '<S458>/Sum3' incorporates:
  //   UnitDelay: '<S458>/Unit Delay1'
  //   UnitDelay: '<S458>/Unit Delay2'

  FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_l =
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[1] -
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_k;

  // Sum: '<S513>/Sum1' incorporates:
  //   Bias: '<S514>/Bias1'
  //   Gain: '<S513>/Gain1'
  //   Product: '<S513>/Product5'
  //   Product: '<S514>/Product4'
  //   Sum: '<S513>/Sum2'
  //   UnaryMinus: '<S514>/Unary Minus'
  //   UnitDelay: '<S513>/Unit Delay1'
  //   UnitDelay: '<S513>/Unit Delay2'

  FLIGHT_Hexacopter_V2_B.q = ((-FLIGHT_Hexacopter_V2_B.q +
    FLIGHT_Hexacopter_V2_P.Bias1_Bias_a) / FLIGHT_Hexacopter_V2_B.d_g *
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE +
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[0]) * FLIGHT_Hexacopter_V2_P.Gain1_Gain_i +
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_h;

  // Product: '<S513>/Product2' incorporates:
  //   Product: '<S514>/Product5'
  //   Sum: '<S514>/Add3'
  //   UnitDelay: '<S513>/Unit Delay1'

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE *= 1.0F / FLIGHT_Hexacopter_V2_B.d_g
    * (FLIGHT_Hexacopter_V2_B.r_g - FLIGHT_Hexacopter_V2_B.p);

  // Sum: '<S513>/Sum3' incorporates:
  //   UnitDelay: '<S513>/Unit Delay1'
  //   UnitDelay: '<S513>/Unit Delay2'

  FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_h =
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[0] -
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE;

  // RateTransition: '<S351>/Rate Transition1' incorporates:
  //   RateTransition: '<S9>/Rate Transition2'

  if (FLIGHT_Hexacopter_V2_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<S351>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1_o =
      FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_l4;
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer[0] =
      FLIGHT_Hexacopter_V2_B.In1_k.xyz[0];
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer[1] =
      FLIGHT_Hexacopter_V2_B.In1_k.xyz[1];
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer[2] =
      FLIGHT_Hexacopter_V2_B.In1_k.xyz[2];

    // RateTransition: '<S3>/Rate Transition'
    FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer =
      FLIGHT_Hexacopter_V2_B.RateTransition3;
  }

  // End of RateTransition: '<S351>/Rate Transition1'

  // Update for DiscreteIntegrator: '<S548>/Integrator' incorporates:
  //   Product: '<S545>/IProd Out'

  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE += FLIGHT_Hexacopter_V2_B.roll *
    FLIGHT_Hexacopter_V2_B.RateTransition1_o *
    FLIGHT_Hexacopter_V2_P.Integrator_gainval;
  FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState = static_cast<int8_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition6);

  // Update for UnitDelay: '<S513>/Unit Delay1'
  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE = FLIGHT_Hexacopter_V2_B.q;

  // Update for UnitDelay: '<S510>/UD'
  //
  //  Block description for '<S510>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE = FLIGHT_Hexacopter_V2_B.TSamp;

  // Update for DiscreteIntegrator: '<S493>/Integrator' incorporates:
  //   Product: '<S490>/IProd Out'

  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_c += FLIGHT_Hexacopter_V2_B.roll_h *
    FLIGHT_Hexacopter_V2_B.RateTransition1_d *
    FLIGHT_Hexacopter_V2_P.Integrator_gainval_d;
  FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_h = static_cast<int8_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition6_a);

  // Update for UnitDelay: '<S458>/Unit Delay1'
  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_k = FLIGHT_Hexacopter_V2_B.Sum5_nz;

  // Update for UnitDelay: '<S455>/UD'
  //
  //  Block description for '<S455>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_o = FLIGHT_Hexacopter_V2_B.TSamp_c;

  // Update for DiscreteIntegrator: '<S603>/Integrator' incorporates:
  //   Product: '<S600>/IProd Out'

  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_o += FLIGHT_Hexacopter_V2_B.roll_l *
    FLIGHT_Hexacopter_V2_B.RateTransition1_c *
    FLIGHT_Hexacopter_V2_P.Integrator_gainval_b;
  FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_hd = static_cast<int8_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition6_o);

  // Update for UnitDelay: '<S565>/UD'
  //
  //  Block description for '<S565>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_k = rtb_TSamp_g;
}

// Model step function for TID1
void FLIGHT_Hexacopter_V2_step1(void)  // Sample time: [0.004s, 0.0s]
{
  boolean_T rtb_AND;
  boolean_T rtb_AND1;
  boolean_T rtb_flag_alt;
  boolean_T rtb_flag_pos;

  // MATLABSystem: '<S5>/Read Parameter34'
  if (FLIGHT_Hexacopter_V2_DW.obj_o.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_o.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_o.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter35'
  if (FLIGHT_Hexacopter_V2_DW.obj_b.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_b.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_b.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_m);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_m = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter36'
  if (FLIGHT_Hexacopter_V2_DW.obj_l.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_l.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_l.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_c);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_c = 0.0F;
  }

  // S-Function (sdspdiag2): '<S229>/Create Diagonal Matrix' incorporates:
  //   Constant: '<S229>/Constant'
  //   Constant: '<S229>/Constant1'
  //   Constant: '<S229>/Constant2'
  //   MATLABSystem: '<S5>/Read Parameter34'
  //   MATLABSystem: '<S5>/Read Parameter35'
  //   MATLABSystem: '<S5>/Read Parameter36'
  //   Product: '<S229>/Divide3'
  //   Product: '<S229>/Divide4'
  //   Product: '<S229>/Divide5'
  //
  memset(&FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[0], 0, 9U * sizeof(real_T));
  FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[0] =
    FLIGHT_Hexacopter_V2_P.Constant_Value_gr / FLIGHT_Hexacopter_V2_B.ParamStep;
  FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[4] =
    FLIGHT_Hexacopter_V2_P.Constant1_Value_f /
    FLIGHT_Hexacopter_V2_B.ParamStep_m;
  FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[8] =
    FLIGHT_Hexacopter_V2_P.Constant2_Value_n /
    FLIGHT_Hexacopter_V2_B.ParamStep_c;

  // MATLABSystem: '<S219>/SourceBlock'
  rtb_flag_pos = uORB_read_step(FLIGHT_Hexacopter_V2_DW.obj_lk.orbMetadataObj,
    &FLIGHT_Hexacopter_V2_DW.obj_lk.eventStructObj, &FLIGHT_Hexacopter_V2_B.r,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S219>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S225>/Enable'

  // Start for MATLABSystem: '<S219>/SourceBlock'
  if (rtb_flag_pos) {
    // SignalConversion generated from: '<S225>/In1'
    FLIGHT_Hexacopter_V2_B.In1 = FLIGHT_Hexacopter_V2_B.r;
  }

  // End of Outputs for SubSystem: '<S219>/Enabled Subsystem'

  // Trigonometry: '<S53>/SinCos'
  FLIGHT_Hexacopter_V2_B.Integrator_c = static_cast<real32_T>(sin
    (static_cast<real_T>(FLIGHT_Hexacopter_V2_B.In1.heading)));
  FLIGHT_Hexacopter_V2_B.roll_g = static_cast<real32_T>(cos(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.In1.heading)));

  // Concatenate: '<S53>/Matrix Concatenate' incorporates:
  //   Reshape: '<S53>/Reshape'
  //   Reshape: '<S53>/Reshape1'

  FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_0 =
    FLIGHT_Hexacopter_V2_B.roll_g;
  FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_3 =
    FLIGHT_Hexacopter_V2_B.roll_g;

  // MATLABSystem: '<S212>/SourceBlock'
  rtb_flag_pos = uORB_read_step(FLIGHT_Hexacopter_V2_DW.obj_nt.orbMetadataObj,
    &FLIGHT_Hexacopter_V2_DW.obj_nt.eventStructObj, &FLIGHT_Hexacopter_V2_B.r2,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S212>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S213>/Enable'

  // Start for MATLABSystem: '<S212>/SourceBlock'
  if (rtb_flag_pos) {
    // SignalConversion generated from: '<S213>/In1'
    FLIGHT_Hexacopter_V2_B.In1_p = FLIGHT_Hexacopter_V2_B.r2;
  }

  // End of Outputs for SubSystem: '<S212>/Enabled Subsystem'

  // Gain: '<S4>/Gain3' incorporates:
  //   Constant: '<S4>/Constant3'
  //   DataTypeConversion: '<S4>/Data Type Conversion3'
  //   Sum: '<S4>/Sum3'

  FLIGHT_Hexacopter_V2_B.Gain7 = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[0]) -
    FLIGHT_Hexacopter_V2_P.Constant3_Value_h) *
    FLIGHT_Hexacopter_V2_P.Gain3_Gain;

  // DeadZone: '<S4>/Dead Zone'
  if (FLIGHT_Hexacopter_V2_B.Gain7 > FLIGHT_Hexacopter_V2_P.DeadZone_End) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone_End;
  } else if (FLIGHT_Hexacopter_V2_B.Gain7 >=
             FLIGHT_Hexacopter_V2_P.DeadZone_Start) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = 0.0F;
  } else {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone_Start;
  }

  // End of DeadZone: '<S4>/Dead Zone'

  // Saturate: '<S4>/Saturation3'
  if (FLIGHT_Hexacopter_V2_B.ParamStep_cx >
      FLIGHT_Hexacopter_V2_P.Saturation3_UpperSat) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx =
      FLIGHT_Hexacopter_V2_P.Saturation3_UpperSat;
  } else if (FLIGHT_Hexacopter_V2_B.ParamStep_cx <
             FLIGHT_Hexacopter_V2_P.Saturation3_LowerSat) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx =
      FLIGHT_Hexacopter_V2_P.Saturation3_LowerSat;
  }

  // Gain: '<S4>/Gain4' incorporates:
  //   Saturate: '<S4>/Saturation3'

  FLIGHT_Hexacopter_V2_B.Gain4 = FLIGHT_Hexacopter_V2_P.MAX_CONTROL_ANGLE_ROLL *
    FLIGHT_Hexacopter_V2_B.ParamStep_cx;

  // Gain: '<S4>/Gain1' incorporates:
  //   Constant: '<S4>/Constant2'
  //   DataTypeConversion: '<S4>/Data Type Conversion4'
  //   Sum: '<S4>/Sum2'

  FLIGHT_Hexacopter_V2_B.Gain7 = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[1]) -
    FLIGHT_Hexacopter_V2_P.Constant2_Value_e) *
    FLIGHT_Hexacopter_V2_P.Gain1_Gain_f;

  // DeadZone: '<S4>/Dead Zone1'
  if (FLIGHT_Hexacopter_V2_B.Gain7 > FLIGHT_Hexacopter_V2_P.DeadZone1_End) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone1_End;
  } else if (FLIGHT_Hexacopter_V2_B.Gain7 >=
             FLIGHT_Hexacopter_V2_P.DeadZone1_Start) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = 0.0F;
  } else {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone1_Start;
  }

  // End of DeadZone: '<S4>/Dead Zone1'

  // Saturate: '<S4>/Saturation2'
  if (FLIGHT_Hexacopter_V2_B.ParamStep_cx >
      FLIGHT_Hexacopter_V2_P.Saturation2_UpperSat) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx =
      FLIGHT_Hexacopter_V2_P.Saturation2_UpperSat;
  } else if (FLIGHT_Hexacopter_V2_B.ParamStep_cx <
             FLIGHT_Hexacopter_V2_P.Saturation2_LowerSat) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx =
      FLIGHT_Hexacopter_V2_P.Saturation2_LowerSat;
  }

  // Gain: '<S4>/Gain5' incorporates:
  //   Saturate: '<S4>/Saturation2'

  FLIGHT_Hexacopter_V2_B.Gain5 = FLIGHT_Hexacopter_V2_P.MAX_CONTROL_ANGLE_PITCH *
    FLIGHT_Hexacopter_V2_B.ParamStep_cx;

  // Gain: '<S4>/Gain2' incorporates:
  //   Constant: '<S4>/Constant1'
  //   DataTypeConversion: '<S4>/Data Type Conversion5'
  //   Sum: '<S4>/Sum1'

  FLIGHT_Hexacopter_V2_B.Gain7 = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[3]) -
    FLIGHT_Hexacopter_V2_P.Constant1_Value_c) *
    FLIGHT_Hexacopter_V2_P.Gain2_Gain;

  // DeadZone: '<S4>/Dead Zone2'
  if (FLIGHT_Hexacopter_V2_B.Gain7 > FLIGHT_Hexacopter_V2_P.DeadZone2_End) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone2_End;
  } else if (FLIGHT_Hexacopter_V2_B.Gain7 >=
             FLIGHT_Hexacopter_V2_P.DeadZone2_Start) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = 0.0F;
  } else {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone2_Start;
  }

  // End of DeadZone: '<S4>/Dead Zone2'

  // Saturate: '<S4>/Saturation1'
  if (FLIGHT_Hexacopter_V2_B.ParamStep_cx >
      FLIGHT_Hexacopter_V2_P.Saturation1_UpperSat) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx =
      FLIGHT_Hexacopter_V2_P.Saturation1_UpperSat;
  } else if (FLIGHT_Hexacopter_V2_B.ParamStep_cx <
             FLIGHT_Hexacopter_V2_P.Saturation1_LowerSat) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx =
      FLIGHT_Hexacopter_V2_P.Saturation1_LowerSat;
  }

  // Gain: '<S4>/Gain6' incorporates:
  //   Saturate: '<S4>/Saturation1'

  FLIGHT_Hexacopter_V2_B.Gain6 = FLIGHT_Hexacopter_V2_P.MAX_CONTROL_ANGLE_RATE_Y
    * FLIGHT_Hexacopter_V2_B.ParamStep_cx;

  // Gain: '<S4>/Gain' incorporates:
  //   Constant: '<S4>/Constant'
  //   DataTypeConversion: '<S4>/Data Type Conversion6'
  //   Sum: '<S4>/Sum'

  FLIGHT_Hexacopter_V2_B.Gain7 = static_cast<real32_T>((static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[2]) -
    FLIGHT_Hexacopter_V2_P.Constant_Value_k3) *
    FLIGHT_Hexacopter_V2_P.Gain_Gain_b);

  // DeadZone: '<S4>/Dead Zone3'
  if (FLIGHT_Hexacopter_V2_B.Gain7 > FLIGHT_Hexacopter_V2_P.DeadZone3_End) {
    FLIGHT_Hexacopter_V2_B.Gain7_p = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone3_End;
  } else if (FLIGHT_Hexacopter_V2_B.Gain7 >=
             FLIGHT_Hexacopter_V2_P.DeadZone3_Start) {
    FLIGHT_Hexacopter_V2_B.Gain7_p = 0.0F;
  } else {
    FLIGHT_Hexacopter_V2_B.Gain7_p = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone3_Start;
  }

  // End of DeadZone: '<S4>/Dead Zone3'

  // Fcn: '<S4>/Fcn3' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion11'

  FLIGHT_Hexacopter_V2_B.Gain7 = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[2]) - 1514.0F) / 420.0F;

  // DeadZone: '<S4>/Dead Zone7'
  if (FLIGHT_Hexacopter_V2_B.Gain7 > FLIGHT_Hexacopter_V2_P.DeadZone7_End) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone7_End;
  } else if (FLIGHT_Hexacopter_V2_B.Gain7 >=
             FLIGHT_Hexacopter_V2_P.DeadZone7_Start) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = 0.0F;
  } else {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone7_Start;
  }

  // End of DeadZone: '<S4>/Dead Zone7'

  // MATLABSystem: '<S5>/Read Parameter39'
  if (FLIGHT_Hexacopter_V2_DW.obj_g.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_g.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_g.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_k);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_k = 0.0F;
  }

  // Saturate: '<S4>/Saturation10'
  if (FLIGHT_Hexacopter_V2_B.ParamStep_cx >
      FLIGHT_Hexacopter_V2_P.Saturation10_UpperSat) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx =
      FLIGHT_Hexacopter_V2_P.Saturation10_UpperSat;
  } else if (FLIGHT_Hexacopter_V2_B.ParamStep_cx <
             FLIGHT_Hexacopter_V2_P.Saturation10_LowerSat) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx =
      FLIGHT_Hexacopter_V2_P.Saturation10_LowerSat;
  }

  // Gain: '<S4>/Gain7' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter39'
  //   Product: '<S4>/Product'
  //   Saturate: '<S4>/Saturation10'
  //
  FLIGHT_Hexacopter_V2_B.Gain7 = FLIGHT_Hexacopter_V2_B.ParamStep_cx *
    FLIGHT_Hexacopter_V2_B.ParamStep_k * FLIGHT_Hexacopter_V2_P.Gain7_Gain;

  // Sum: '<S52>/Sum1'
  FLIGHT_Hexacopter_V2_B.roll_g = FLIGHT_Hexacopter_V2_B.Gain7 -
    FLIGHT_Hexacopter_V2_B.In1.vz;

  // MATLABSystem: '<S5>/Read Parameter3'
  if (FLIGHT_Hexacopter_V2_DW.obj_c4.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_c4.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_c4.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_k);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_k = 0.0F;
  }

  FLIGHT_Hexacopt_SourceBlock(&FLIGHT_Hexacopter_V2_B.SourceBlock_l,
    &FLIGHT_Hexacopter_V2_DW.SourceBlock_l);

  // Outputs for Enabled SubSystem: '<S217>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S223>/Enable'

  if (FLIGHT_Hexacopter_V2_B.SourceBlock_l.SourceBlock_o1) {
    // SignalConversion generated from: '<S223>/In1' incorporates:
    //   MATLABSystem: '<S217>/SourceBlock'

    FLIGHT_Hexacopter_V2_B.In1_e =
      FLIGHT_Hexacopter_V2_B.SourceBlock_l.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: '<S217>/Enabled Subsystem'

  // Logic: '<S4>/AND' incorporates:
  //   Constant: '<S43>/Constant'
  //   RelationalOperator: '<S43>/Compare'

  rtb_AND = (FLIGHT_Hexacopter_V2_B.In1_p.values[5] >
             FLIGHT_Hexacopter_V2_P.CompareToConstant1_const) ^
    FLIGHT_Hexacopter_V2_B.In1_e.armed;

  // DiscreteIntegrator: '<S192>/Integrator'
  if ((rtb_AND && (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_l <= 0)) ||
      ((!rtb_AND) && (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_l == 1)))
  {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_l =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCon_pr;
  }

  // MATLABSystem: '<S5>/Read Parameter5'
  if (FLIGHT_Hexacopter_V2_DW.obj_i.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_i.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_i.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_cx);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = 0.0F;
  }

  // Sum: '<S157>/Sum' incorporates:
  //   UnitDelay: '<S157>/Unit Delay1'

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i += FLIGHT_Hexacopter_V2_B.In1.vz;

  // MATLABSystem: '<S5>/Read Parameter11'
  if (FLIGHT_Hexacopter_V2_DW.obj_jk.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_jk.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_jk.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_b);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_b = 0.0F;
  }

  // MATLAB Function: '<S5>/MATLAB Function' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter11'
  //
  FLIGHT_Hexacopter_V2_B.w_radps = FLIGHT_Hexacopter_V2_B.ParamStep_b * 2.0F *
    3.14159274F;

  // Gain: '<S157>/tau'
  FLIGHT_Hexacopter_V2_B.p_j = FLIGHT_Hexacopter_V2_P.tau_Gain_g *
    FLIGHT_Hexacopter_V2_B.w_radps;

  // Product: '<S158>/Product2'
  FLIGHT_Hexacopter_V2_B.q_c = FLIGHT_Hexacopter_V2_B.p_j *
    FLIGHT_Hexacopter_V2_B.p_j;

  // Bias: '<S158>/Bias'
  FLIGHT_Hexacopter_V2_B.r_o = FLIGHT_Hexacopter_V2_B.q_c +
    FLIGHT_Hexacopter_V2_P.Bias_Bias_n;

  // Gain: '<S158>/Gain'
  FLIGHT_Hexacopter_V2_B.p_j *= FLIGHT_Hexacopter_V2_P.Gain_Gain_oj;

  // Sum: '<S158>/Add1'
  FLIGHT_Hexacopter_V2_B.d_n = FLIGHT_Hexacopter_V2_B.r_o +
    FLIGHT_Hexacopter_V2_B.p_j;

  // SampleTimeMath: '<S154>/TSamp' incorporates:
  //   Product: '<S157>/Product1'
  //   Product: '<S158>/Product3'
  //   UnitDelay: '<S157>/Unit Delay1'
  //
  //  About '<S154>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.TSamp_k = FLIGHT_Hexacopter_V2_B.q_c /
    FLIGHT_Hexacopter_V2_B.d_n * FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_n;

  // MATLABSystem: '<S5>/Read Parameter26'
  if (FLIGHT_Hexacopter_V2_DW.obj_lt.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_lt.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_lt.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_b);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_b = 0.0F;
  }

  // MATLAB Function: '<S4>/MATLAB Function2' incorporates:
  //   DiscreteIntegrator: '<S192>/Integrator'
  //   MATLABSystem: '<S5>/Read Parameter26'
  //   MATLABSystem: '<S5>/Read Parameter3'
  //   MATLABSystem: '<S5>/Read Parameter5'
  //   Product: '<S197>/PProd Out'
  //   Product: '<S52>/Product2'
  //   Sum: '<S154>/Diff'
  //   Sum: '<S201>/Sum'
  //   Sum: '<S52>/Sum5'
  //   UnitDelay: '<S154>/UD'
  //  *
  //  Block description for '<S154>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S154>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_B.Saturation5 = FLIGHT_Hexacopter_V2_B.ParamStep_b -
    ((FLIGHT_Hexacopter_V2_B.roll_g * FLIGHT_Hexacopter_V2_B.ParamStep_k +
      FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_l) -
     (FLIGHT_Hexacopter_V2_B.TSamp_k - FLIGHT_Hexacopter_V2_DW.UD_DSTATE_a) *
     FLIGHT_Hexacopter_V2_B.ParamStep_cx) / 9.81F;

  // Saturate: '<S4>/Saturation5'
  if (FLIGHT_Hexacopter_V2_B.Saturation5 >
      FLIGHT_Hexacopter_V2_P.Saturation5_UpperSat) {
    FLIGHT_Hexacopter_V2_B.Saturation5 =
      FLIGHT_Hexacopter_V2_P.Saturation5_UpperSat;
  } else if (FLIGHT_Hexacopter_V2_B.Saturation5 <
             FLIGHT_Hexacopter_V2_P.Saturation5_LowerSat) {
    FLIGHT_Hexacopter_V2_B.Saturation5 =
      FLIGHT_Hexacopter_V2_P.Saturation5_LowerSat;
  }

  // End of Saturate: '<S4>/Saturation5'

  // MATLABSystem: '<S5>/Read Parameter28'
  if (FLIGHT_Hexacopter_V2_DW.obj_ic.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_ic.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_ic.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_k);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_k = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter27'
  if (FLIGHT_Hexacopter_V2_DW.obj_l3.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_l3.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_l3.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_cx);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = 0.0F;
  }

  // Logic: '<S4>/AND1' incorporates:
  //   Constant: '<S44>/Constant'
  //   RelationalOperator: '<S44>/Compare'

  rtb_AND1 = (FLIGHT_Hexacopter_V2_B.In1_p.values[5] >
              FLIGHT_Hexacopter_V2_P.CompareToConstant2_const) ^
    FLIGHT_Hexacopter_V2_B.In1_e.armed;

  // DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'

  if (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE =
      FLIGHT_Hexacopter_V2_B.In1.x;
    if (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE >
        FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_UpperSat) {
      FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE =
        FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_UpperSat;
    } else if (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE <
               FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_LowerSat) {
      FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE =
        FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  rtb_flag_pos = !rtb_AND1;
  if ((rtb_AND1 && (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRese <= 0))
      || (rtb_flag_pos &&
          (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRese == 1))) {
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE =
      FLIGHT_Hexacopter_V2_B.In1.x;
    if (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE >
        FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_UpperSat) {
      FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE =
        FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_UpperSat;
    } else if (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE <
               FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_LowerSat) {
      FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE =
        FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  // DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
  if (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE =
      FLIGHT_Hexacopter_V2_B.In1.y;
    if (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE >
        FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator1_UpperSa) {
      FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE =
        FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator1_UpperSa;
    } else if (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE <
               FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator1_LowerSa) {
      FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE =
        FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator1_LowerSa;
    }
  }

  if ((rtb_AND1 && (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_PrevRes <= 0))
      || (rtb_flag_pos &&
          (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_PrevRes == 1))) {
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE =
      FLIGHT_Hexacopter_V2_B.In1.y;
    if (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE >
        FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator1_UpperSa) {
      FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE =
        FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator1_UpperSa;
    } else if (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE <
               FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator1_LowerSa) {
      FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE =
        FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator1_LowerSa;
    }
  }

  // Sum: '<S4>/Sum7' incorporates:
  //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
  //   MATLABSystem: '<S5>/Read Parameter27'
  //   Product: '<S92>/PProd Out'
  //   Sum: '<S4>/Sum5'
  //
  FLIGHT_Hexacopter_V2_B.Product_p =
    (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE -
     FLIGHT_Hexacopter_V2_B.In1.x) * FLIGHT_Hexacopter_V2_B.ParamStep_cx -
    FLIGHT_Hexacopter_V2_B.In1.vx;
  FLIGHT_Hexacopter_V2_B.Product4_gc =
    (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE -
     FLIGHT_Hexacopter_V2_B.In1.y) * FLIGHT_Hexacopter_V2_B.ParamStep_cx -
    FLIGHT_Hexacopter_V2_B.In1.vy;

  // Saturate: '<S4>/Saturation6' incorporates:
  //   Concatenate: '<S53>/Matrix Concatenate'
  //   Gain: '<S53>/Gain'
  //   MATLABSystem: '<S5>/Read Parameter28'
  //   Math: '<S53>/Transpose'
  //   Product: '<S142>/PProd Out'
  //   Product: '<S49>/MatrixMultiply'
  //   Reshape: '<S53>/Reshape1'
  //
  FLIGHT_Hexacopter_V2_B.Product2_m =
    (FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_0 *
     FLIGHT_Hexacopter_V2_B.Product_p + FLIGHT_Hexacopter_V2_B.Integrator_c *
     FLIGHT_Hexacopter_V2_B.Product4_gc) * FLIGHT_Hexacopter_V2_B.ParamStep_k;
  FLIGHT_Hexacopter_V2_B.Integrator_c = (FLIGHT_Hexacopter_V2_P.Gain_Gain_az *
    FLIGHT_Hexacopter_V2_B.Integrator_c * FLIGHT_Hexacopter_V2_B.Product_p +
    FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_3 *
    FLIGHT_Hexacopter_V2_B.Product4_gc) * FLIGHT_Hexacopter_V2_B.ParamStep_k;

  // MATLABSystem: '<S218>/SourceBlock'
  rtb_flag_pos = uORB_read_step(FLIGHT_Hexacopter_V2_DW.obj_ab.orbMetadataObj,
    &FLIGHT_Hexacopter_V2_DW.obj_ab.eventStructObj, &FLIGHT_Hexacopter_V2_B.r3,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S218>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S224>/Enable'

  // Start for MATLABSystem: '<S218>/SourceBlock'
  if (rtb_flag_pos) {
    // SignalConversion generated from: '<S224>/In1'
    FLIGHT_Hexacopter_V2_B.In1_m = FLIGHT_Hexacopter_V2_B.r3;
  }

  // End of Outputs for SubSystem: '<S218>/Enabled Subsystem'

  // MATLAB Function: '<S8>/MATLAB Function'
  switch (FLIGHT_Hexacopter_V2_B.In1_m.nav_state) {
   case 1:
    rtb_flag_pos = false;
    rtb_flag_alt = true;
    break;

   case 2:
    rtb_flag_pos = true;
    rtb_flag_alt = false;
    break;

   default:
    rtb_flag_pos = false;
    rtb_flag_alt = false;
    break;
  }

  // End of MATLAB Function: '<S8>/MATLAB Function'

  // SignalConversion generated from: '<S46>/ SFunction ' incorporates:
  //   MATLAB Function: '<S4>/MATLAB Function'

  FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_0 =
    FLIGHT_Hexacopter_V2_B.Gain4;

  // Saturate: '<S4>/Saturation'
  if (FLIGHT_Hexacopter_V2_B.Gain7_p >
      FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_h) {
    // SignalConversion generated from: '<S46>/ SFunction ' incorporates:
    //   MATLAB Function: '<S4>/MATLAB Function'

    FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_3 =
      FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_h;
  } else if (FLIGHT_Hexacopter_V2_B.Gain7_p <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_p) {
    // SignalConversion generated from: '<S46>/ SFunction ' incorporates:
    //   MATLAB Function: '<S4>/MATLAB Function'

    FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_3 =
      FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_p;
  } else {
    // SignalConversion generated from: '<S46>/ SFunction ' incorporates:
    //   MATLAB Function: '<S4>/MATLAB Function'

    FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_3 =
      FLIGHT_Hexacopter_V2_B.Gain7_p;
  }

  // End of Saturate: '<S4>/Saturation'

  // MATLAB Function: '<S4>/MATLAB Function' incorporates:
  //   Gain: '<S4>/Gain11'
  //   Saturate: '<S4>/Saturation6'
  //   SignalConversion generated from: '<S46>/ SFunction '

  if ((FLIGHT_Hexacopter_V2_B.In1_p.values[5] >= 1800) && rtb_flag_pos) {
    // Saturate: '<S4>/Saturation6'
    if (FLIGHT_Hexacopter_V2_B.Integrator_c >
        FLIGHT_Hexacopter_V2_P.Saturation6_UpperSat) {
      FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_0 =
        FLIGHT_Hexacopter_V2_P.Saturation6_UpperSat;
    } else if (FLIGHT_Hexacopter_V2_B.Integrator_c <
               FLIGHT_Hexacopter_V2_P.Saturation6_LowerSat) {
      FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_0 =
        FLIGHT_Hexacopter_V2_P.Saturation6_LowerSat;
    } else {
      FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_0 =
        FLIGHT_Hexacopter_V2_B.Integrator_c;
    }

    if (FLIGHT_Hexacopter_V2_B.Product2_m >
        FLIGHT_Hexacopter_V2_P.Saturation6_UpperSat) {
      FLIGHT_Hexacopter_V2_B.Product2_m =
        FLIGHT_Hexacopter_V2_P.Saturation6_UpperSat;
    } else if (FLIGHT_Hexacopter_V2_B.Product2_m <
               FLIGHT_Hexacopter_V2_P.Saturation6_LowerSat) {
      FLIGHT_Hexacopter_V2_B.Product2_m =
        FLIGHT_Hexacopter_V2_P.Saturation6_LowerSat;
    }

    FLIGHT_Hexacopter_V2_B.Gain5 = FLIGHT_Hexacopter_V2_P.Gain11_Gain *
      FLIGHT_Hexacopter_V2_B.Product2_m;
    FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_3 =
      FLIGHT_Hexacopter_V2_B.Saturation5;
  } else if ((FLIGHT_Hexacopter_V2_B.In1_p.values[5] < 1800) &&
             (FLIGHT_Hexacopter_V2_B.In1_p.values[5] >= 1400) && rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_3 =
      FLIGHT_Hexacopter_V2_B.Saturation5;
  }

  // RateTransition: '<S10>/Rate Transition4'
  FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0 =
    FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_3;

  // MATLABSystem: '<S5>/Read Parameter31'
  if (FLIGHT_Hexacopter_V2_DW.obj_as.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_as.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_as.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_k);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_k = 0.0F;
  }

  // MATLABSystem: '<S227>/SourceBlock'
  rtb_flag_pos = uORB_read_step(FLIGHT_Hexacopter_V2_DW.obj_i4.orbMetadataObj,
    &FLIGHT_Hexacopter_V2_DW.obj_i4.eventStructObj, &FLIGHT_Hexacopter_V2_B.r1,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S227>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S228>/Enable'

  // Start for MATLABSystem: '<S227>/SourceBlock'
  if (rtb_flag_pos) {
    // SignalConversion generated from: '<S228>/In1'
    FLIGHT_Hexacopter_V2_B.In1_b = FLIGHT_Hexacopter_V2_B.r1;
  }

  // End of Outputs for SubSystem: '<S227>/Enabled Subsystem'

  // MATLAB Function: '<S8>/quat2eul'
  FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_1 = static_cast<real32_T>(asin(static_cast<
    real_T>((FLIGHT_Hexacopter_V2_B.In1_b.q[1] * FLIGHT_Hexacopter_V2_B.In1_b.q
             [3] - FLIGHT_Hexacopter_V2_B.In1_b.q[0] *
             FLIGHT_Hexacopter_V2_B.In1_b.q[2]) * -2.0F)));
  FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_2 = rt_atan2f_snf
    ((FLIGHT_Hexacopter_V2_B.In1_b.q[0] * FLIGHT_Hexacopter_V2_B.In1_b.q[1] +
      FLIGHT_Hexacopter_V2_B.In1_b.q[2] * FLIGHT_Hexacopter_V2_B.In1_b.q[3]) *
     2.0F, ((FLIGHT_Hexacopter_V2_B.In1_b.q[0] * FLIGHT_Hexacopter_V2_B.In1_b.q
             [0] - FLIGHT_Hexacopter_V2_B.In1_b.q[1] *
             FLIGHT_Hexacopter_V2_B.In1_b.q[1]) -
            FLIGHT_Hexacopter_V2_B.In1_b.q[2] * FLIGHT_Hexacopter_V2_B.In1_b.q[2])
     + FLIGHT_Hexacopter_V2_B.In1_b.q[3] * FLIGHT_Hexacopter_V2_B.In1_b.q[3]);

  // MATLAB Function: '<S9>/Omega_phi'
  FLIGHT_Hexacopter_V2_B.Gain4 = static_cast<real32_T>(tan(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_1)));
  FLIGHT_Hexacopter_V2_B.omega_phi[0] = 1.0F;
  FLIGHT_Hexacopter_V2_B.omega_phi[1] = static_cast<real32_T>(sin
    (static_cast<real_T>(FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_2))) *
    FLIGHT_Hexacopter_V2_B.Gain4;
  FLIGHT_Hexacopter_V2_B.omega_phi[2] = static_cast<real32_T>(cos
    (static_cast<real_T>(FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_2))) *
    FLIGHT_Hexacopter_V2_B.Gain4;
  for (FLIGHT_Hexacopter_V2_B.i = 0; FLIGHT_Hexacopter_V2_B.i < 3;
       FLIGHT_Hexacopter_V2_B.i++) {
    // MATLAB Function: '<S9>/MATLAB Function1' incorporates:
    //   DataTypeConversion: '<S229>/Data Type Conversion1'
    //   MATLABSystem: '<S5>/Read Parameter31'
    //   S-Function (sdspdiag2): '<S229>/Create Diagonal Matrix'
    //
    FLIGHT_Hexacopter_V2_B.G1[FLIGHT_Hexacopter_V2_B.i] = (static_cast<real32_T>
      (FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[3 * FLIGHT_Hexacopter_V2_B.i
       + 1]) * (FLIGHT_Hexacopter_V2_B.ParamStep_k *
                FLIGHT_Hexacopter_V2_B.omega_phi[1]) + static_cast<real32_T>
      (FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[3 * FLIGHT_Hexacopter_V2_B.i])
      * FLIGHT_Hexacopter_V2_B.ParamStep_k) + static_cast<real32_T>
      (FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[3 * FLIGHT_Hexacopter_V2_B.i
       + 2]) * (FLIGHT_Hexacopter_V2_B.ParamStep_k *
                FLIGHT_Hexacopter_V2_B.omega_phi[2]);

    // SampleTimeMath: '<S233>/TSamp'
    //
    //  About '<S233>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )
    //
    FLIGHT_Hexacopter_V2_B.Gain4 =
      FLIGHT_Hexacopter_V2_B.omega_phi[FLIGHT_Hexacopter_V2_B.i] *
      FLIGHT_Hexacopter_V2_P.TSamp_WtEt_ma;
    FLIGHT_Hexacopter_V2_B.TSamp_o[FLIGHT_Hexacopter_V2_B.i] =
      FLIGHT_Hexacopter_V2_B.Gain4;

    // Sum: '<S233>/Diff' incorporates:
    //   SampleTimeMath: '<S233>/TSamp'
    //   UnitDelay: '<S233>/UD'
    //
    //  About '<S233>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )
    //    *
    //  Block description for '<S233>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S233>/UD':
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[FLIGHT_Hexacopter_V2_B.i] =
      FLIGHT_Hexacopter_V2_B.Gain4 -
      FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[FLIGHT_Hexacopter_V2_B.i];
  }

  // MATLABSystem: '<S5>/Read Parameter38'
  if (FLIGHT_Hexacopter_V2_DW.obj_e.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_e.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_e.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_cx);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = 0.0F;
  }

  // Gain: '<S343>/tau' incorporates:
  //   Gain: '<S9>/Gain'
  //   MATLABSystem: '<S5>/Read Parameter38'
  //
  FLIGHT_Hexacopter_V2_B.Gain7_p = FLIGHT_Hexacopter_V2_P.Gain_Gain_eb *
    FLIGHT_Hexacopter_V2_B.ParamStep_cx * FLIGHT_Hexacopter_V2_P.tau_Gain_f;

  // Product: '<S344>/Product2' incorporates:
  //   Bias: '<S344>/Bias'

  FLIGHT_Hexacopter_V2_B.Gain7_p *= 1.0F / (FLIGHT_Hexacopter_V2_B.Gain7_p +
    FLIGHT_Hexacopter_V2_P.Bias_Bias_h);

  // RelationalOperator: '<S45>/Compare' incorporates:
  //   Constant: '<S45>/Constant'

  rtb_flag_pos = (FLIGHT_Hexacopter_V2_B.In1_p.values[6] >=
                  FLIGHT_Hexacopter_V2_P.CompareToConstant3_const);
  FLIGHT_Hexac_PX4Timestamp_p(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_pna);

  // MATLABSystem: '<S5>/Read Parameter1'
  if (FLIGHT_Hexacopter_V2_DW.obj_l4.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_l4.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_l4.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_cx);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter'
  if (FLIGHT_Hexacopter_V2_DW.obj_jf.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_jf.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_jf.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_b);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_b = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter2'
  if (FLIGHT_Hexacopter_V2_DW.obj_a1.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_a1.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_a1.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_Hexacopter_V2_B.i);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.i = 0;
  }

  // MATLAB Function: '<S4>/MATLAB Function1' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion'
  //   DataTypeConversion: '<S4>/Data Type Conversion10'
  //   DataTypeConversion: '<S4>/Data Type Conversion12'
  //   DataTypeConversion: '<S4>/Data Type Conversion2'
  //   DataTypeConversion: '<S4>/Data Type Conversion8'
  //   DataTypeConversion: '<S4>/Data Type Conversion9'
  //   MATLABSystem: '<S4>/PX4 Timestamp'
  //   MATLABSystem: '<S5>/Read Parameter'
  //   MATLABSystem: '<S5>/Read Parameter1'
  //   MATLABSystem: '<S5>/Read Parameter2'
  //
  FLIGHT_Hexacopter_V2_B.out_roll =
    FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_0;
  FLIGHT_Hexacopter_V2_B.out_pitch = FLIGHT_Hexacopter_V2_B.Gain5;
  FLIGHT_Hexacopter_V2_B.out_yawrate = FLIGHT_Hexacopter_V2_B.Gain6;
  if (rtb_flag_pos && (FLIGHT_Hexacopter_V2_DW.start_time_usec == -1.0)) {
    FLIGHT_Hexacopter_V2_DW.start_time_usec = static_cast<real_T>
      (FLIGHT_Hexacopter_V2_B.PX4Timestamp_pna.PX4Timestamp);
  }

  if (rtb_flag_pos && (FLIGHT_Hexacopter_V2_DW.start_time_usec > 0.0)) {
    FLIGHT_Hexacopter_V2_B.reletive_time_sec = (static_cast<real_T>
      (FLIGHT_Hexacopter_V2_B.PX4Timestamp_pna.PX4Timestamp) -
      FLIGHT_Hexacopter_V2_DW.start_time_usec) * 1.0E-6;
  } else {
    FLIGHT_Hexacopter_V2_DW.start_time_usec = -1.0;
    FLIGHT_Hexacopter_V2_B.reletive_time_sec = 0.0;
  }

  FLIGHT_Hexacopter_V2_B.peak_angle_rad = FLIGHT_Hexacopter_V2_B.ParamStep_cx *
    0.017453292519943295;
  if (rtb_flag_pos) {
    switch (FLIGHT_Hexacopter_V2_B.i) {
     case 1:
      if ((FLIGHT_Hexacopter_V2_B.reletive_time_sec >= 0.0) &&
          (FLIGHT_Hexacopter_V2_B.reletive_time_sec <
           FLIGHT_Hexacopter_V2_B.ParamStep_b)) {
        FLIGHT_Hexacopter_V2_B.out_roll = FLIGHT_Hexacopter_V2_B.peak_angle_rad;
      } else if ((FLIGHT_Hexacopter_V2_B.reletive_time_sec >=
                  FLIGHT_Hexacopter_V2_B.ParamStep_b) &&
                 (FLIGHT_Hexacopter_V2_B.reletive_time_sec < static_cast<real_T>
                  (FLIGHT_Hexacopter_V2_B.ParamStep_b) +
                  FLIGHT_Hexacopter_V2_B.ParamStep_b)) {
        FLIGHT_Hexacopter_V2_B.out_roll = -FLIGHT_Hexacopter_V2_B.peak_angle_rad;
      } else {
        FLIGHT_Hexacopter_V2_B.out_roll = 0.0;
      }
      break;

     case 2:
      if ((FLIGHT_Hexacopter_V2_B.reletive_time_sec >= 0.0) &&
          (FLIGHT_Hexacopter_V2_B.reletive_time_sec <
           FLIGHT_Hexacopter_V2_B.ParamStep_b)) {
        FLIGHT_Hexacopter_V2_B.out_pitch = FLIGHT_Hexacopter_V2_B.peak_angle_rad;
      } else if ((FLIGHT_Hexacopter_V2_B.reletive_time_sec >=
                  FLIGHT_Hexacopter_V2_B.ParamStep_b) &&
                 (FLIGHT_Hexacopter_V2_B.reletive_time_sec < static_cast<real_T>
                  (FLIGHT_Hexacopter_V2_B.ParamStep_b) +
                  FLIGHT_Hexacopter_V2_B.ParamStep_b)) {
        FLIGHT_Hexacopter_V2_B.out_pitch =
          -FLIGHT_Hexacopter_V2_B.peak_angle_rad;
      } else {
        FLIGHT_Hexacopter_V2_B.out_pitch = 0.0;
      }
      break;

     case 3:
      if ((FLIGHT_Hexacopter_V2_B.reletive_time_sec >= 0.0) &&
          (FLIGHT_Hexacopter_V2_B.reletive_time_sec <
           FLIGHT_Hexacopter_V2_B.ParamStep_b)) {
        FLIGHT_Hexacopter_V2_B.out_yawrate =
          FLIGHT_Hexacopter_V2_B.peak_angle_rad;
      } else if ((FLIGHT_Hexacopter_V2_B.reletive_time_sec >=
                  FLIGHT_Hexacopter_V2_B.ParamStep_b) &&
                 (FLIGHT_Hexacopter_V2_B.reletive_time_sec < static_cast<real_T>
                  (FLIGHT_Hexacopter_V2_B.ParamStep_b) +
                  FLIGHT_Hexacopter_V2_B.ParamStep_b)) {
        FLIGHT_Hexacopter_V2_B.out_yawrate =
          -FLIGHT_Hexacopter_V2_B.peak_angle_rad;
      } else {
        FLIGHT_Hexacopter_V2_B.out_yawrate = 0.0;
      }
      break;
    }
  }

  // End of MATLAB Function: '<S4>/MATLAB Function1'

  // Sum: '<S343>/Sum' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion14'
  //   UnitDelay: '<S343>/Unit Delay'

  FLIGHT_Hexacopter_V2_B.Integrator_c = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_roll) + FLIGHT_Hexacopter_V2_DW.UnitDelay_DSTATE;

  // Product: '<S343>/Product1'
  FLIGHT_Hexacopter_V2_B.Saturation5 = FLIGHT_Hexacopter_V2_B.Gain7_p *
    FLIGHT_Hexacopter_V2_B.Integrator_c;

  // Sum: '<S9>/Subtract'
  FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_0 =
    FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_2 - FLIGHT_Hexacopter_V2_B.Saturation5;

  // MATLABSystem: '<S5>/Read Parameter29'
  if (FLIGHT_Hexacopter_V2_DW.obj_br.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_br.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_br.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_cx);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter30'
  if (FLIGHT_Hexacopter_V2_DW.obj_m.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_m.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_m.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_b);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_b = 0.0F;
  }

  // Product: '<S229>/Product' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter34'
  //   MATLABSystem: '<S5>/Read Parameter35'
  //   MATLABSystem: '<S5>/Read Parameter36'
  //   Product: '<S229>/Divide'
  //   Product: '<S229>/Product1'
  //   RateTransition: '<S9>/Rate Transition2'
  //   Sum: '<S229>/Add'
  //
  FLIGHT_Hexacopter_V2_B.Product_p = (FLIGHT_Hexacopter_V2_B.ParamStep_m -
    FLIGHT_Hexacopter_V2_B.ParamStep_c) / FLIGHT_Hexacopter_V2_B.ParamStep *
    (FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer[1] *
     FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer[2]);

  // Product: '<S229>/Product2' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter34'
  //   MATLABSystem: '<S5>/Read Parameter35'
  //   MATLABSystem: '<S5>/Read Parameter36'
  //   Product: '<S229>/Divide1'
  //   Product: '<S229>/Product3'
  //   RateTransition: '<S9>/Rate Transition2'
  //   Sum: '<S229>/Add1'
  //
  FLIGHT_Hexacopter_V2_B.Product2_m = (FLIGHT_Hexacopter_V2_B.ParamStep_c -
    FLIGHT_Hexacopter_V2_B.ParamStep) / FLIGHT_Hexacopter_V2_B.ParamStep_m *
    (FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer[0] *
     FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer[2]);

  // Product: '<S229>/Product4' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter34'
  //   MATLABSystem: '<S5>/Read Parameter35'
  //   MATLABSystem: '<S5>/Read Parameter36'
  //   Product: '<S229>/Divide2'
  //   Product: '<S229>/Product5'
  //   RateTransition: '<S9>/Rate Transition2'
  //   Sum: '<S229>/Add2'
  //
  FLIGHT_Hexacopter_V2_B.Product4_gc = (FLIGHT_Hexacopter_V2_B.ParamStep -
    FLIGHT_Hexacopter_V2_B.ParamStep_m) / FLIGHT_Hexacopter_V2_B.ParamStep_c *
    (FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer[0] *
     FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer[1]);

  // SampleTimeMath: '<S231>/TSamp'
  //
  //  About '<S231>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.Gain5 = FLIGHT_Hexacopter_V2_B.Saturation5 *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_p;

  // Sum: '<S231>/Diff' incorporates:
  //   UnitDelay: '<S231>/UD'
  //
  //  Block description for '<S231>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S231>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_B.Diff_kx = FLIGHT_Hexacopter_V2_B.Gain5 -
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_o2;

  // SampleTimeMath: '<S232>/TSamp'
  //
  //  About '<S232>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.Gain6 = FLIGHT_Hexacopter_V2_B.Diff_kx *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_l;

  // MATLAB Function: '<S9>/MATLAB Function' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter29'
  //   MATLABSystem: '<S5>/Read Parameter30'
  //   MATLABSystem: '<S5>/Read Parameter31'
  //   RateTransition: '<S9>/Rate Transition2'
  //   SignalConversion generated from: '<S237>/ SFunction '
  //   Sum: '<S233>/Diff'
  //  *
  //  Block description for '<S233>/Diff':
  //
  //   Add in CPU

  FLIGHT_Hexacopter_V2_B.Gain4 = (FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[0] *
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer[0] +
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[1] *
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer[1]) +
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[2] *
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer[2];
  FLIGHT_Hexacopter_V2_B.H = ((((FLIGHT_Hexacopter_V2_B.omega_phi[1] *
    FLIGHT_Hexacopter_V2_B.Product2_m + FLIGHT_Hexacopter_V2_B.Product_p) +
    FLIGHT_Hexacopter_V2_B.omega_phi[2] * FLIGHT_Hexacopter_V2_B.Product4_gc) +
    FLIGHT_Hexacopter_V2_B.Gain4) * FLIGHT_Hexacopter_V2_B.ParamStep_k +
    (FLIGHT_Hexacopter_V2_B.Gain4 - FLIGHT_Hexacopter_V2_B.Diff_kx) *
    FLIGHT_Hexacopter_V2_B.ParamStep_cx) + FLIGHT_Hexacopter_V2_B.ParamStep_b *
    FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_0;

  // Gain: '<S279>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S271>/Filter'
  //   Gain: '<S269>/Derivative Gain'
  //   Sum: '<S271>/SumD'

  FLIGHT_Hexacopter_V2_B.Gain4 =
    (FLIGHT_Hexacopter_V2_P.DiscretePIDController1_D *
     FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_0 -
     FLIGHT_Hexacopter_V2_DW.Filter_DSTATE) *
    FLIGHT_Hexacopter_V2_P.DiscretePIDController1_N;

  // Sum: '<S285>/Sum' incorporates:
  //   Gain: '<S281>/Proportional Gain'

  FLIGHT_Hexacopter_V2_B.Sum_n = FLIGHT_Hexacopter_V2_P.DiscretePIDController1_P
    * FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_0 +
    FLIGHT_Hexacopter_V2_B.Gain4;
  FLIGHT_Hexacopt_SourceBlock(&FLIGHT_Hexacopter_V2_B.SourceBlock_p,
    &FLIGHT_Hexacopter_V2_DW.SourceBlock_p);

  // Outputs for Enabled SubSystem: '<S220>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S226>/Enable'

  if (FLIGHT_Hexacopter_V2_B.SourceBlock_p.SourceBlock_o1) {
    // SignalConversion generated from: '<S226>/In1' incorporates:
    //   MATLABSystem: '<S220>/SourceBlock'

    FLIGHT_Hexacopter_V2_B.In1_d =
      FLIGHT_Hexacopter_V2_B.SourceBlock_p.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: '<S220>/Enabled Subsystem'

  // Logic: '<S9>/XOR' incorporates:
  //   Constant: '<S230>/Constant'
  //   RelationalOperator: '<S230>/Compare'

  rtb_flag_pos = (FLIGHT_Hexacopter_V2_B.In1_p.values[9] <=
                  FLIGHT_Hexacopter_V2_P.CompareToConstant_const_o) ^
    FLIGHT_Hexacopter_V2_B.In1_d.armed;

  // DiscreteIntegrator: '<S326>/Integrator'
  if ((rtb_flag_pos && (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_he <=
                        0)) || ((!rtb_flag_pos) &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_he == 1))) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_h =
      FLIGHT_Hexacopter_V2_P.DiscretePIDController2_InitialC;
  }

  // MATLAB Function: '<S9>/MATLAB Function3' incorporates:
  //   DiscreteIntegrator: '<S326>/Integrator'
  //   MATLABSystem: '<S5>/Read Parameter29'
  //   MATLABSystem: '<S5>/Read Parameter30'
  //   MATLABSystem: '<S5>/Read Parameter31'
  //
  FLIGHT_Hexacopter_V2_B.ParamStep_k = (FLIGHT_Hexacopter_V2_B.ParamStep_k *
    FLIGHT_Hexacopter_V2_B.Sum_n + FLIGHT_Hexacopter_V2_B.ParamStep_cx *
    FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_0) +
    FLIGHT_Hexacopter_V2_B.ParamStep_b *
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_h;

  // MATLABSystem: '<S5>/Read Parameter32'
  if (FLIGHT_Hexacopter_V2_DW.obj_lv.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_lv.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_lv.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter33'
  if (FLIGHT_Hexacopter_V2_DW.obj_bd.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_bd.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_bd.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_m);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_m = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter37'
  if (FLIGHT_Hexacopter_V2_DW.obj_pi.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_pi.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_pi.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_c);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep_c = 0.0F;
  }

  // MATLAB Function: '<S9>/MATLAB Function4' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter32'
  //   MATLABSystem: '<S5>/Read Parameter33'
  //   MATLABSystem: '<S5>/Read Parameter37'
  //
  FLIGHT_Hexacopter_V2_B.ParamStep_m = FLIGHT_Hexacopter_V2_B.ParamStep_k / (
    static_cast<real32_T>(fabs(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.ParamStep_k))) + FLIGHT_Hexacopter_V2_B.ParamStep_c)
    * -FLIGHT_Hexacopter_V2_B.ParamStep - FLIGHT_Hexacopter_V2_B.ParamStep_m *
    FLIGHT_Hexacopter_V2_B.ParamStep_k;

  // MATLAB Function: '<S9>/MATLAB Function2'
  rtb_flag_alt = true;
  FLIGHT_Hexacopter_V2_B.G1_inv[0] = 0.0F;
  if (rtIsInfF(FLIGHT_Hexacopter_V2_B.G1[0]) || rtIsNaNF
      (FLIGHT_Hexacopter_V2_B.G1[0])) {
    rtb_flag_alt = false;
  }

  FLIGHT_Hexacopter_V2_B.G1_inv[1] = 0.0F;
  if (rtb_flag_alt && (rtIsInfF(FLIGHT_Hexacopter_V2_B.G1[1]) || rtIsNaNF
                       (FLIGHT_Hexacopter_V2_B.G1[1]))) {
    rtb_flag_alt = false;
  }

  FLIGHT_Hexacopter_V2_B.G1_inv[2] = 0.0F;
  if (rtb_flag_alt && (rtIsInfF(FLIGHT_Hexacopter_V2_B.G1[2]) || rtIsNaNF
                       (FLIGHT_Hexacopter_V2_B.G1[2]))) {
    rtb_flag_alt = false;
  }

  if (!rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.G1_inv[0] = (rtNaNF);
    FLIGHT_Hexacopter_V2_B.G1_inv[1] = (rtNaNF);
    FLIGHT_Hexacopter_V2_B.G1_inv[2] = (rtNaNF);
  } else {
    FLIGHT_Hexacopter_V2_svd(FLIGHT_Hexacopter_V2_B.G1, FLIGHT_Hexacopter_V2_B.U,
      &FLIGHT_Hexacopter_V2_B.ParamStep_cx, &FLIGHT_Hexacopter_V2_B.ParamStep);
    FLIGHT_Hexacopter_V2_B.ParamStep_c = static_cast<real32_T>(fabs(static_cast<
      real_T>(FLIGHT_Hexacopter_V2_B.ParamStep_cx)));
    if (rtIsInfF(FLIGHT_Hexacopter_V2_B.ParamStep_c) || rtIsNaNF
        (FLIGHT_Hexacopter_V2_B.ParamStep_c)) {
      FLIGHT_Hexacopter_V2_B.ParamStep_c = (rtNaNF);
    } else if (FLIGHT_Hexacopter_V2_B.ParamStep_c < 2.3509887E-38F) {
      FLIGHT_Hexacopter_V2_B.ParamStep_c = 1.4013E-45F;
    } else {
      frexp(static_cast<real_T>(FLIGHT_Hexacopter_V2_B.ParamStep_c),
            &FLIGHT_Hexacopter_V2_B.exponent);
      FLIGHT_Hexacopter_V2_B.ParamStep_c = static_cast<real32_T>(ldexp(1.0,
        FLIGHT_Hexacopter_V2_B.exponent - 24));
    }

    FLIGHT_Hexacopter_V2_B.ParamStep_c *= 3.0F;
    if (rtIsInfF(FLIGHT_Hexacopter_V2_B.ParamStep_cx) || rtIsNaNF
        (FLIGHT_Hexacopter_V2_B.ParamStep_cx)) {
      FLIGHT_Hexacopter_V2_B.ParamStep_c = 3.402823466E+38F;
    }

    FLIGHT_Hexacopter_V2_B.i = 0;
    if (FLIGHT_Hexacopter_V2_B.ParamStep_cx > FLIGHT_Hexacopter_V2_B.ParamStep_c)
    {
      FLIGHT_Hexacopter_V2_B.i = 1;
    }

    if (FLIGHT_Hexacopter_V2_B.i > 0) {
      FLIGHT_Hexacopter_V2_B.ParamStep_cx = 1.0F /
        FLIGHT_Hexacopter_V2_B.ParamStep_cx;
      for (FLIGHT_Hexacopter_V2_B.i = 1; FLIGHT_Hexacopter_V2_B.i < 2;
           FLIGHT_Hexacopter_V2_B.i++) {
        FLIGHT_Hexacopter_V2_B.ParamStep *= FLIGHT_Hexacopter_V2_B.ParamStep_cx;
      }

      FLIGHT_Hexacopter_V2_B.i = 0;
      for (FLIGHT_Hexacopter_V2_B.exponent = 0; FLIGHT_Hexacopter_V2_B.exponent <
           3; FLIGHT_Hexacopter_V2_B.exponent++) {
        for (FLIGHT_Hexacopter_V2_B.ic = FLIGHT_Hexacopter_V2_B.exponent + 1;
             FLIGHT_Hexacopter_V2_B.ic <= FLIGHT_Hexacopter_V2_B.exponent + 1;
             FLIGHT_Hexacopter_V2_B.ic++) {
          FLIGHT_Hexacopter_V2_B.G1_inv[FLIGHT_Hexacopter_V2_B.ic - 1] = 0.0F;
        }
      }

      for (FLIGHT_Hexacopter_V2_B.exponent = 0; FLIGHT_Hexacopter_V2_B.exponent <
           3; FLIGHT_Hexacopter_V2_B.exponent++) {
        FLIGHT_Hexacopter_V2_B.i++;
        for (FLIGHT_Hexacopter_V2_B.ic = FLIGHT_Hexacopter_V2_B.i;
             FLIGHT_Hexacopter_V2_B.ic <= FLIGHT_Hexacopter_V2_B.i;
             FLIGHT_Hexacopter_V2_B.ic += 3) {
          for (FLIGHT_Hexacopter_V2_B.b_ic = FLIGHT_Hexacopter_V2_B.exponent + 1;
               FLIGHT_Hexacopter_V2_B.b_ic <= FLIGHT_Hexacopter_V2_B.exponent +
               1; FLIGHT_Hexacopter_V2_B.b_ic++) {
            FLIGHT_Hexacopter_V2_B.G1_inv[FLIGHT_Hexacopter_V2_B.b_ic - 1] +=
              FLIGHT_Hexacopter_V2_B.U[FLIGHT_Hexacopter_V2_B.ic - 1] *
              FLIGHT_Hexacopter_V2_B.ParamStep;
          }
        }
      }
    }
  }

  // Gain: '<S27>/1//2' incorporates:
  //   Constant: '<S3>/Constant1'
  //   DataTypeConversion: '<S4>/Data Type Conversion13'
  //   DataTypeConversion: '<S4>/Data Type Conversion14'

  FLIGHT_Hexacopter_V2_B.G1[0] = FLIGHT_Hexacopter_V2_P.u2_Gain *
    FLIGHT_Hexacopter_V2_P.Constant1_Value_fy;
  FLIGHT_Hexacopter_V2_B.G1[1] = FLIGHT_Hexacopter_V2_P.u2_Gain * static_cast<
    real32_T>(FLIGHT_Hexacopter_V2_B.out_pitch);
  FLIGHT_Hexacopter_V2_B.G1[2] = FLIGHT_Hexacopter_V2_P.u2_Gain *
    static_cast<real32_T>(FLIGHT_Hexacopter_V2_B.out_roll);

  // Trigonometry: '<S27>/sincos'
  FLIGHT_Hexacopter_V2_B.ParamStep = static_cast<real32_T>(cos
    (static_cast<real_T>(FLIGHT_Hexacopter_V2_B.G1[0])));
  FLIGHT_Hexacopter_V2_B.ParamStep_b = static_cast<real32_T>(sin
    (static_cast<real_T>(FLIGHT_Hexacopter_V2_B.G1[0])));
  FLIGHT_Hexacopter_V2_B.ParamStep_c = static_cast<real32_T>(cos
    (static_cast<real_T>(FLIGHT_Hexacopter_V2_B.G1[1])));
  FLIGHT_Hexacopter_V2_B.rtb_G1_c = static_cast<real32_T>(sin(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.G1[1])));
  FLIGHT_Hexacopter_V2_B.rtb_sincos_o2_idx_2 = static_cast<real32_T>(cos(
    static_cast<real_T>(FLIGHT_Hexacopter_V2_B.G1[2])));
  FLIGHT_Hexacopter_V2_B.rtb_G1_f = static_cast<real32_T>(sin(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.G1[2])));
  FLIGHT_Hexac_PX4Timestamp_j(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_j);

  // BusAssignment: '<S25>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion13'
  //   DataTypeConversion: '<S4>/Data Type Conversion14'
  //   DataTypeConversion: '<S4>/Data Type Conversion15'
  //   MATLABSystem: '<S25>/PX4 Timestamp'

  FLIGHT_Hexacopter_V2_B.BusAssignment_f.timestamp =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp_j.PX4Timestamp;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.roll_body = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_roll);
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.pitch_body = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_pitch);
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.yaw_body = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_roll);
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.yaw_sp_move_rate = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_yawrate);

  // Fcn: '<S27>/q0' incorporates:
  //   Fcn: '<S27>/q1'
  //   Trigonometry: '<S27>/sincos'

  FLIGHT_Hexacopter_V2_B.ParamStep_cx = FLIGHT_Hexacopter_V2_B.ParamStep *
    FLIGHT_Hexacopter_V2_B.ParamStep_c;
  FLIGHT_Hexacopter_V2_B.f = FLIGHT_Hexacopter_V2_B.ParamStep_b *
    FLIGHT_Hexacopter_V2_B.rtb_G1_c;

  // BusAssignment: '<S25>/Bus Assignment' incorporates:
  //   Fcn: '<S27>/q0'
  //   Fcn: '<S27>/q1'
  //   Trigonometry: '<S27>/sincos'

  FLIGHT_Hexacopter_V2_B.BusAssignment_f.q_d[0] =
    FLIGHT_Hexacopter_V2_B.ParamStep_cx *
    FLIGHT_Hexacopter_V2_B.rtb_sincos_o2_idx_2 + FLIGHT_Hexacopter_V2_B.f *
    FLIGHT_Hexacopter_V2_B.rtb_G1_f;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.q_d[1] =
    FLIGHT_Hexacopter_V2_B.ParamStep_cx * FLIGHT_Hexacopter_V2_B.rtb_G1_f -
    FLIGHT_Hexacopter_V2_B.f * FLIGHT_Hexacopter_V2_B.rtb_sincos_o2_idx_2;

  // Fcn: '<S27>/q2' incorporates:
  //   Fcn: '<S27>/q3'
  //   Trigonometry: '<S27>/sincos'

  FLIGHT_Hexacopter_V2_B.ParamStep_cx = FLIGHT_Hexacopter_V2_B.ParamStep_b *
    FLIGHT_Hexacopter_V2_B.ParamStep_c;
  FLIGHT_Hexacopter_V2_B.f = FLIGHT_Hexacopter_V2_B.ParamStep *
    FLIGHT_Hexacopter_V2_B.rtb_G1_c;

  // BusAssignment: '<S25>/Bus Assignment' incorporates:
  //   Constant: '<S3>/Constant'
  //   Fcn: '<S27>/q2'
  //   Fcn: '<S27>/q3'
  //   Trigonometry: '<S27>/sincos'

  FLIGHT_Hexacopter_V2_B.BusAssignment_f.q_d[2] = FLIGHT_Hexacopter_V2_B.f *
    FLIGHT_Hexacopter_V2_B.rtb_sincos_o2_idx_2 +
    FLIGHT_Hexacopter_V2_B.ParamStep_cx * FLIGHT_Hexacopter_V2_B.rtb_G1_f;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.q_d[3] =
    FLIGHT_Hexacopter_V2_B.ParamStep_cx *
    FLIGHT_Hexacopter_V2_B.rtb_sincos_o2_idx_2 - FLIGHT_Hexacopter_V2_B.f *
    FLIGHT_Hexacopter_V2_B.rtb_G1_f;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.thrust_body[0] =
    FLIGHT_Hexacopter_V2_P.Constant_Value_i;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.thrust_body[1] =
    FLIGHT_Hexacopter_V2_P.Constant_Value_i;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.thrust_body[2] =
    FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_3;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.reset_integral = false;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.fw_control_yaw_wheel = false;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f._padding0[0] = 0U;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f._padding0[1] = 0U;

  // MATLABSystem: '<S34>/SinkBlock' incorporates:
  //   BusAssignment: '<S25>/Bus Assignment'

  uORB_write_step(FLIGHT_Hexacopter_V2_DW.obj_m1.orbMetadataObj,
                  &FLIGHT_Hexacopter_V2_DW.obj_m1.orbAdvertiseObj,
                  &FLIGHT_Hexacopter_V2_B.BusAssignment_f);

  // RateTransition: '<S10>/Rate Transition1' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion15'

  FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0 = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_yawrate);

  // RateTransition: '<S352>/Rate Transition4' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion15'

  FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_c = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_yawrate);
  FLIGHT_Hexac_PX4Timestamp_j(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_p);

  // MATLABSystem: '<S5>/Read Parameter9'
  if (FLIGHT_Hexacopter_V2_DW.obj_a.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_a.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_a.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // Gain: '<S209>/Gain1' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter9'
  //
  FLIGHT_Hexacopter_V2_B.ParamStep_cx = FLIGHT_Hexacopter_V2_P.Gain1_Gain_o *
    FLIGHT_Hexacopter_V2_B.ParamStep;

  // MATLABSystem: '<S5>/Read Parameter6'
  if (FLIGHT_Hexacopter_V2_DW.obj_p.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_p.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_p.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // Product: '<S442>/PProd Out' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion14'
  //   MATLABSystem: '<S5>/Read Parameter6'
  //   Sum: '<S10>/Sum3'
  //
  FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_2 = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_roll) - FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_2) *
    FLIGHT_Hexacopter_V2_B.ParamStep;

  // Switch: '<S445>/Switch2' incorporates:
  //   RelationalOperator: '<S445>/LowerRelop1'

  if (FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_2 > FLIGHT_Hexacopter_V2_B.ParamStep_cx)
  {
    FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_2 = FLIGHT_Hexacopter_V2_B.ParamStep_cx;
  } else {
    // Gain: '<S10>/Gain'
    FLIGHT_Hexacopter_V2_B.ParamStep = FLIGHT_Hexacopter_V2_P.Gain_Gain_o *
      FLIGHT_Hexacopter_V2_B.ParamStep_cx;

    // Switch: '<S445>/Switch' incorporates:
    //   RelationalOperator: '<S445>/UpperRelop'

    if (FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_2 < FLIGHT_Hexacopter_V2_B.ParamStep)
    {
      FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_2 = FLIGHT_Hexacopter_V2_B.ParamStep;
    }

    // End of Switch: '<S445>/Switch'
  }

  // End of Switch: '<S445>/Switch2'

  // MATLABSystem: '<S5>/Read Parameter10'
  if (FLIGHT_Hexacopter_V2_DW.obj_bq.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_bq.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_bq.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // Gain: '<S210>/Gain1' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter10'
  //
  FLIGHT_Hexacopter_V2_B.ParamStep_cx = FLIGHT_Hexacopter_V2_P.Gain1_Gain_j *
    FLIGHT_Hexacopter_V2_B.ParamStep;

  // MATLABSystem: '<S5>/Read Parameter7'
  if (FLIGHT_Hexacopter_V2_DW.obj_fj.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_fj.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_fj.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // Product: '<S391>/PProd Out' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion13'
  //   MATLABSystem: '<S5>/Read Parameter7'
  //   Sum: '<S10>/Sum2'
  //
  FLIGHT_Hexacopter_V2_B.ParamStep *= static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_pitch) - FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_1;

  // Switch: '<S394>/Switch2' incorporates:
  //   RelationalOperator: '<S394>/LowerRelop1'

  if (FLIGHT_Hexacopter_V2_B.ParamStep > FLIGHT_Hexacopter_V2_B.ParamStep_cx) {
    FLIGHT_Hexacopter_V2_B.ParamStep = FLIGHT_Hexacopter_V2_B.ParamStep_cx;
  } else {
    // Gain: '<S10>/Gain1'
    FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_1 = FLIGHT_Hexacopter_V2_P.Gain1_Gain *
      FLIGHT_Hexacopter_V2_B.ParamStep_cx;

    // Switch: '<S394>/Switch' incorporates:
    //   RelationalOperator: '<S394>/UpperRelop'

    if (FLIGHT_Hexacopter_V2_B.ParamStep < FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_1)
    {
      FLIGHT_Hexacopter_V2_B.ParamStep = FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_1;
    }

    // End of Switch: '<S394>/Switch'
  }

  // End of Switch: '<S394>/Switch2'

  // BusAssignment: '<S26>/Bus Assignment' incorporates:
  //   Constant: '<S3>/Constant3'
  //   DataTypeConversion: '<S4>/Data Type Conversion15'
  //   MATLABSystem: '<S26>/PX4 Timestamp'

  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.timestamp =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp_p.PX4Timestamp;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.roll =
    FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_2;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.pitch =
    FLIGHT_Hexacopter_V2_B.ParamStep;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.yaw = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_yawrate);
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.thrust_body[0] =
    FLIGHT_Hexacopter_V2_P.Constant3_Value_m;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.thrust_body[1] =
    FLIGHT_Hexacopter_V2_P.Constant3_Value_m;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.thrust_body[2] =
    FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_3;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.reset_integral = false;
  for (FLIGHT_Hexacopter_V2_B.i = 0; FLIGHT_Hexacopter_V2_B.i < 7;
       FLIGHT_Hexacopter_V2_B.i++) {
    FLIGHT_Hexacopter_V2_B.BusAssignment_e0._padding0[FLIGHT_Hexacopter_V2_B.i] =
      0U;
  }

  // End of BusAssignment: '<S26>/Bus Assignment'

  // MATLABSystem: '<S36>/SinkBlock' incorporates:
  //   BusAssignment: '<S26>/Bus Assignment'

  uORB_write_step(FLIGHT_Hexacopter_V2_DW.obj_mp.orbMetadataObj,
                  &FLIGHT_Hexacopter_V2_DW.obj_mp.orbAdvertiseObj,
                  &FLIGHT_Hexacopter_V2_B.BusAssignment_e0);

  // RateTransition: '<S350>/Rate Transition4'
  FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_k =
    FLIGHT_Hexacopter_V2_B.ParamStep;

  // RateTransition: '<S351>/Rate Transition4'
  FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_e =
    FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_2;
  FLIGHT_Hexac_PX4Timestamp_j(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_k);

  // Fcn: '<S4>/Fcn1' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion7'

  FLIGHT_Hexacopter_V2_B.ParamStep = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[1]) - 1514.0F) / 420.0F;

  // DeadZone: '<S4>/Dead Zone4'
  if (FLIGHT_Hexacopter_V2_B.ParamStep > FLIGHT_Hexacopter_V2_P.DeadZone4_End) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = FLIGHT_Hexacopter_V2_B.ParamStep -
      FLIGHT_Hexacopter_V2_P.DeadZone4_End;
  } else if (FLIGHT_Hexacopter_V2_B.ParamStep >=
             FLIGHT_Hexacopter_V2_P.DeadZone4_Start) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = 0.0F;
  } else {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = FLIGHT_Hexacopter_V2_B.ParamStep -
      FLIGHT_Hexacopter_V2_P.DeadZone4_Start;
  }

  // End of DeadZone: '<S4>/Dead Zone4'

  // Saturate: '<S4>/Saturation4'
  if (FLIGHT_Hexacopter_V2_B.ParamStep_cx >
      FLIGHT_Hexacopter_V2_P.Saturation4_UpperSat) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx =
      FLIGHT_Hexacopter_V2_P.Saturation4_UpperSat;
  } else if (FLIGHT_Hexacopter_V2_B.ParamStep_cx <
             FLIGHT_Hexacopter_V2_P.Saturation4_LowerSat) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx =
      FLIGHT_Hexacopter_V2_P.Saturation4_LowerSat;
  }

  // Gain: '<S4>/Gain10' incorporates:
  //   Saturate: '<S4>/Saturation4'

  FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_3 =
    FLIGHT_Hexacopter_V2_P.Gain10_Gain * FLIGHT_Hexacopter_V2_B.ParamStep_cx;

  // Fcn: '<S4>/Fcn2' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion1'

  FLIGHT_Hexacopter_V2_B.ParamStep = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[0]) - 1514.0F) / 420.0F;

  // DeadZone: '<S4>/Dead Zone6'
  if (FLIGHT_Hexacopter_V2_B.ParamStep > FLIGHT_Hexacopter_V2_P.DeadZone6_End) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = FLIGHT_Hexacopter_V2_B.ParamStep -
      FLIGHT_Hexacopter_V2_P.DeadZone6_End;
  } else if (FLIGHT_Hexacopter_V2_B.ParamStep >=
             FLIGHT_Hexacopter_V2_P.DeadZone6_Start) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = 0.0F;
  } else {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx = FLIGHT_Hexacopter_V2_B.ParamStep -
      FLIGHT_Hexacopter_V2_P.DeadZone6_Start;
  }

  // End of DeadZone: '<S4>/Dead Zone6'

  // Saturate: '<S4>/Saturation9'
  if (FLIGHT_Hexacopter_V2_B.ParamStep_cx >
      FLIGHT_Hexacopter_V2_P.Saturation9_UpperSat) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx =
      FLIGHT_Hexacopter_V2_P.Saturation9_UpperSat;
  } else if (FLIGHT_Hexacopter_V2_B.ParamStep_cx <
             FLIGHT_Hexacopter_V2_P.Saturation9_LowerSat) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cx =
      FLIGHT_Hexacopter_V2_P.Saturation9_LowerSat;
  }

  // Gain: '<S4>/Gain9' incorporates:
  //   Saturate: '<S4>/Saturation9'

  FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_1 =
    FLIGHT_Hexacopter_V2_P.MAX_CONTROL_VELOCITY_XY *
    FLIGHT_Hexacopter_V2_B.ParamStep_cx;

  // BusAssignment: '<S30>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion15'
  //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
  //   MATLABSystem: '<S30>/PX4 Timestamp'

  FLIGHT_Hexacopter_V2_B.BusAssignment_g.timestamp =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp_k.PX4Timestamp;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.x =
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.y =
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.z = 0.0F;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.vx =
    FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_3;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.vy =
    FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_1;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.vz = FLIGHT_Hexacopter_V2_B.Gain7;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.acceleration[0] = 0.0F;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.thrust[0] = 0.0F;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.acceleration[1] = 0.0F;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.thrust[1] = 0.0F;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.acceleration[2] = 0.0F;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.thrust[2] = 0.0F;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.yaw = 0.0F;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.yawspeed = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_yawrate);

  // MATLABSystem: '<S42>/SinkBlock' incorporates:
  //   BusAssignment: '<S30>/Bus Assignment'

  uORB_write_step(FLIGHT_Hexacopter_V2_DW.obj_pm.orbMetadataObj,
                  &FLIGHT_Hexacopter_V2_DW.obj_pm.orbAdvertiseObj,
                  &FLIGHT_Hexacopter_V2_B.BusAssignment_g);
  FLIGHT_Hexac_PX4Timestamp_p(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_pn);

  // BusAssignment: '<S28>/Bus Assignment' incorporates:
  //   Constant: '<S37>/Constant'

  FLIGHT_Hexacopter_V2_B.BusAssignment = FLIGHT_Hexacopter_V2_P.Constant_Value_g;

  // BusAssignment: '<S28>/Bus Assignment' incorporates:
  //   DiscreteIntegrator: '<S326>/Integrator'
  //   MATLABSystem: '<S28>/PX4 Timestamp'
  //   Math: '<S28>/Transpose'
  //   RateTransition: '<S3>/Rate Transition'
  //   RateTransition: '<S9>/Rate Transition2'
  //   Sum: '<S232>/Diff'
  //   Sum: '<S233>/Diff'
  //   UnitDelay: '<S232>/UD'
  //
  //  Block description for '<S232>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S233>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S232>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_B.BusAssignment.timestamp =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp_pn.PX4Timestamp;
  FLIGHT_Hexacopter_V2_B.BusAssignment.tau_roll =
    FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer;
  FLIGHT_Hexacopter_V2_B.BusAssignment.s = FLIGHT_Hexacopter_V2_B.ParamStep_k;
  FLIGHT_Hexacopter_V2_B.BusAssignment.hx = FLIGHT_Hexacopter_V2_B.H;
  FLIGHT_Hexacopter_V2_B.BusAssignment.fx[0] = FLIGHT_Hexacopter_V2_B.Product_p;
  FLIGHT_Hexacopter_V2_B.BusAssignment.fx[1] = FLIGHT_Hexacopter_V2_B.Product2_m;
  FLIGHT_Hexacopter_V2_B.BusAssignment.fx[2] =
    FLIGHT_Hexacopter_V2_B.Product4_gc;
  FLIGHT_Hexacopter_V2_B.BusAssignment.g1x[0] = FLIGHT_Hexacopter_V2_B.G1_inv[0];
  FLIGHT_Hexacopter_V2_B.BusAssignment.omega[0] = 1.0F;
  FLIGHT_Hexacopter_V2_B.BusAssignment.omega_dot[0] =
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[0];
  FLIGHT_Hexacopter_V2_B.BusAssignment.w[0] =
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer[0];
  FLIGHT_Hexacopter_V2_B.BusAssignment.g1x[1] = FLIGHT_Hexacopter_V2_B.G1_inv[1];
  FLIGHT_Hexacopter_V2_B.BusAssignment.omega[1] =
    FLIGHT_Hexacopter_V2_B.omega_phi[1];
  FLIGHT_Hexacopter_V2_B.BusAssignment.omega_dot[1] =
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[1];
  FLIGHT_Hexacopter_V2_B.BusAssignment.w[1] =
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer[1];
  FLIGHT_Hexacopter_V2_B.BusAssignment.g1x[2] = FLIGHT_Hexacopter_V2_B.G1_inv[2];
  FLIGHT_Hexacopter_V2_B.BusAssignment.omega[2] =
    FLIGHT_Hexacopter_V2_B.omega_phi[2];
  FLIGHT_Hexacopter_V2_B.BusAssignment.omega_dot[2] =
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[2];
  FLIGHT_Hexacopter_V2_B.BusAssignment.w[2] =
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer[2];
  FLIGHT_Hexacopter_V2_B.BusAssignment.e =
    FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_0;
  FLIGHT_Hexacopter_V2_B.BusAssignment.e_dot = FLIGHT_Hexacopter_V2_B.Sum_n;
  FLIGHT_Hexacopter_V2_B.BusAssignment.integral_e =
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_h;
  FLIGHT_Hexacopter_V2_B.BusAssignment.phi_cmd =
    FLIGHT_Hexacopter_V2_B.Saturation5;
  FLIGHT_Hexacopter_V2_B.BusAssignment.phi_cmd_dot =
    FLIGHT_Hexacopter_V2_B.Diff_kx;
  FLIGHT_Hexacopter_V2_B.BusAssignment.phi_cmd_ddot =
    FLIGHT_Hexacopter_V2_B.Gain6 - FLIGHT_Hexacopter_V2_DW.UD_DSTATE_e;
  FLIGHT_Hexacopter_V2_B.BusAssignment.r = FLIGHT_Hexacopter_V2_B.ParamStep_m;

  // MATLABSystem: '<S38>/SinkBlock' incorporates:
  //   BusAssignment: '<S28>/Bus Assignment'

  uORB_write_step(FLIGHT_Hexacopter_V2_DW.obj_k.orbMetadataObj,
                  &FLIGHT_Hexacopter_V2_DW.obj_k.orbAdvertiseObj,
                  &FLIGHT_Hexacopter_V2_B.BusAssignment);

  // MATLAB Function: '<S9>/MATLAB Function2'
  FLIGHT_Hexacopter_V2_B.Gain7 = (-FLIGHT_Hexacopter_V2_B.H +
    FLIGHT_Hexacopter_V2_B.ParamStep_m) * FLIGHT_Hexacopter_V2_B.G1_inv[0];

  // Saturate: '<S9>/Saturation2'
  if (FLIGHT_Hexacopter_V2_B.Gain7 >
      FLIGHT_Hexacopter_V2_P.Saturation2_UpperSat_h) {
    FLIGHT_Hexacopter_V2_B.Gain7 = FLIGHT_Hexacopter_V2_P.Saturation2_UpperSat_h;
  } else if (FLIGHT_Hexacopter_V2_B.Gain7 <
             FLIGHT_Hexacopter_V2_P.Saturation2_LowerSat_i) {
    FLIGHT_Hexacopter_V2_B.Gain7 = FLIGHT_Hexacopter_V2_P.Saturation2_LowerSat_i;
  }

  // End of Saturate: '<S9>/Saturation2'

  // RateTransition: '<S9>/Rate Transition3'
  FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0 = FLIGHT_Hexacopter_V2_B.Gain7;

  // RateTransition generated from: '<Root>/Rate Transition2'
  FLIGHT_Hexacopter_V2_DW.RateTransition2_16_Buffer0 =
    FLIGHT_Hexacopter_V2_B.In1_d.armed;

  // RateTransition generated from: '<Root>/Rate Transition2'
  FLIGHT_Hexacopter_V2_DW.RateTransition2_17_Buffer0 =
    FLIGHT_Hexacopter_V2_B.In1_d.manual_lockdown;

  // RateTransition: '<S351>/Rate Transition6' incorporates:
  //   Constant: '<S345>/Constant'
  //   Logic: '<S10>/OR'
  //   RelationalOperator: '<S345>/Compare'

  FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0 =
    (FLIGHT_Hexacopter_V2_B.In1_p.values[9] <=
     FLIGHT_Hexacopter_V2_P.CompareToConstant_const_j) ^
    FLIGHT_Hexacopter_V2_B.In1_d.armed;

  // RateTransition: '<S350>/Rate Transition6' incorporates:
  //   Constant: '<S346>/Constant'
  //   Logic: '<S10>/OR1'
  //   RelationalOperator: '<S346>/Compare'

  FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_i =
    (FLIGHT_Hexacopter_V2_B.In1_p.values[9] <=
     FLIGHT_Hexacopter_V2_P.CompareToConstant1_const_p) ^
    FLIGHT_Hexacopter_V2_B.In1_d.armed;

  // RateTransition: '<S352>/Rate Transition6' incorporates:
  //   Constant: '<S347>/Constant'
  //   Logic: '<S10>/OR2'
  //   RelationalOperator: '<S347>/Compare'

  FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_o =
    (FLIGHT_Hexacopter_V2_B.In1_p.values[9] <=
     FLIGHT_Hexacopter_V2_P.CompareToConstant2_const_p) ^
    FLIGHT_Hexacopter_V2_B.In1_d.armed;

  // Sum: '<S343>/Sum1' incorporates:
  //   Bias: '<S344>/Bias1'
  //   DataTypeConversion: '<S4>/Data Type Conversion14'
  //   Gain: '<S344>/Gain'
  //   Product: '<S343>/Product4'
  //   UnitDelay: '<S343>/Unit Delay'

  FLIGHT_Hexacopter_V2_DW.UnitDelay_DSTATE =
    (FLIGHT_Hexacopter_V2_P.Gain_Gain_ar * FLIGHT_Hexacopter_V2_B.Gain7_p +
     FLIGHT_Hexacopter_V2_P.Bias1_Bias_ka) * FLIGHT_Hexacopter_V2_B.Integrator_c
    + static_cast<real32_T>(FLIGHT_Hexacopter_V2_B.out_roll);

  // Sum: '<S157>/Sum1' incorporates:
  //   Bias: '<S158>/Bias1'
  //   Gain: '<S157>/Gain1'
  //   Product: '<S157>/Product5'
  //   Product: '<S158>/Product4'
  //   Sum: '<S157>/Sum2'
  //   UnaryMinus: '<S158>/Unary Minus'
  //   UnitDelay: '<S157>/Unit Delay1'
  //   UnitDelay: '<S157>/Unit Delay2'

  FLIGHT_Hexacopter_V2_B.q_c = ((-FLIGHT_Hexacopter_V2_B.q_c +
    FLIGHT_Hexacopter_V2_P.Bias1_Bias_m) / FLIGHT_Hexacopter_V2_B.d_n *
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i + FLIGHT_Hexacopter_V2_B.In1.vz)
    * FLIGHT_Hexacopter_V2_P.Gain1_Gain_a +
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_f;

  // Product: '<S157>/Product2' incorporates:
  //   Product: '<S158>/Product5'
  //   Sum: '<S158>/Add3'
  //   UnitDelay: '<S157>/Unit Delay1'

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i *= 1.0F /
    FLIGHT_Hexacopter_V2_B.d_n * (FLIGHT_Hexacopter_V2_B.r_o -
    FLIGHT_Hexacopter_V2_B.p_j);

  // Sum: '<S157>/Sum3' incorporates:
  //   UnitDelay: '<S157>/Unit Delay1'
  //   UnitDelay: '<S157>/Unit Delay2'

  FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_f = FLIGHT_Hexacopter_V2_B.In1.vz -
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i;

  // RateTransition: '<S350>/Rate Transition3'
  FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0_p =
    FLIGHT_Hexacopter_V2_B.w_radps;

  // RateTransition: '<S351>/Rate Transition3'
  FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0_e =
    FLIGHT_Hexacopter_V2_B.w_radps;

  // RateTransition: '<S352>/Rate Transition3'
  FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0_d =
    FLIGHT_Hexacopter_V2_B.w_radps;

  // MATLABSystem: '<S5>/Read Parameter4'
  if (FLIGHT_Hexacopter_V2_DW.obj_c.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_c.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_c.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // RateTransition generated from: '<Root>/Rate Transition'
  FLIGHT_Hexacopter_V2_DW.RateTransition_4_Buffer0 =
    FLIGHT_Hexacopter_V2_B.In1_p.values[7];

  // RateTransition generated from: '<Root>/Rate Transition'
  FLIGHT_Hexacopter_V2_DW.RateTransition_8_Buffer0 =
    FLIGHT_Hexacopter_V2_B.In1_p.values[9];

  // MATLABSystem: '<S5>/Read Parameter12'
  if (FLIGHT_Hexacopter_V2_DW.obj_jo.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_jo.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_jo.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter12_o1);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ReadParameter12_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter12'

  // RateTransition: '<S351>/Rate Transition2'
  FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter12_o1;

  // MATLABSystem: '<S5>/Read Parameter13'
  if (FLIGHT_Hexacopter_V2_DW.obj_pf.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_pf.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_pf.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter13_o1);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ReadParameter13_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter13'

  // RateTransition: '<S350>/Rate Transition'
  FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_c =
    FLIGHT_Hexacopter_V2_B.ReadParameter13_o1;

  // MATLABSystem: '<S5>/Read Parameter14'
  if (FLIGHT_Hexacopter_V2_DW.obj_fd.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_fd.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_fd.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter14_o1);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ReadParameter14_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter14'

  // RateTransition: '<S350>/Rate Transition1'
  FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_l =
    FLIGHT_Hexacopter_V2_B.ReadParameter14_o1;

  // MATLABSystem: '<S5>/Read Parameter15'
  if (FLIGHT_Hexacopter_V2_DW.obj_n.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_n.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_n.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter15_o1);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ReadParameter15_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter15'

  // RateTransition: '<S350>/Rate Transition2'
  FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_l =
    FLIGHT_Hexacopter_V2_B.ReadParameter15_o1;

  // MATLABSystem: '<S5>/Read Parameter16'
  if (FLIGHT_Hexacopter_V2_DW.obj_j.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_j.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_j.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter16_o1);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ReadParameter16_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter16'

  // RateTransition: '<S352>/Rate Transition'
  FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_hv =
    FLIGHT_Hexacopter_V2_B.ReadParameter16_o1;

  // MATLABSystem: '<S5>/Read Parameter17'
  if (FLIGHT_Hexacopter_V2_DW.obj_d.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_d.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_d.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter17_o1);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ReadParameter17_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter17'

  // RateTransition: '<S352>/Rate Transition1'
  FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_m =
    FLIGHT_Hexacopter_V2_B.ReadParameter17_o1;

  // MATLABSystem: '<S5>/Read Parameter18'
  if (FLIGHT_Hexacopter_V2_DW.obj_ml.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_ml.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_ml.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter18_o1);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ReadParameter18_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter18'

  // RateTransition: '<S352>/Rate Transition2'
  FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d =
    FLIGHT_Hexacopter_V2_B.ReadParameter18_o1;

  // MATLABSystem: '<S5>/Read Parameter19'
  if (FLIGHT_Hexacopter_V2_DW.obj_mc.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_mc.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_mc.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter19_o1);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ReadParameter19_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter19'

  // RateTransition: '<S10>/Rate Transition'
  FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_h =
    FLIGHT_Hexacopter_V2_B.ReadParameter19_o1;

  // MATLABSystem: '<S5>/Read Parameter8'
  if (FLIGHT_Hexacopter_V2_DW.obj_f.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj_f.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj_f.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter8_o1);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.ReadParameter8_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter8'

  // RateTransition: '<S351>/Rate Transition1'
  FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_l4 =
    FLIGHT_Hexacopter_V2_B.ReadParameter8_o1;

  // MATLABSystem: '<S5>/read_mc_rollrate_p'
  if (FLIGHT_Hexacopter_V2_DW.obj.SampleTime !=
      FLIGHT_Hexacopter_V2_P.SampleTime) {
    FLIGHT_Hexacopter_V2_DW.obj.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
  }

  rtb_flag_alt = MW_Param_Step(FLIGHT_Hexacopter_V2_DW.obj.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.read_mc_rollrate_p_o1);
  if (rtb_flag_alt) {
    FLIGHT_Hexacopter_V2_B.read_mc_rollrate_p_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/read_mc_rollrate_p'

  // RateTransition: '<S351>/Rate Transition'
  FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0 =
    FLIGHT_Hexacopter_V2_B.read_mc_rollrate_p_o1;

  // Update for DiscreteIntegrator: '<S192>/Integrator' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter4'
  //   Product: '<S189>/IProd Out'
  //
  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_l += FLIGHT_Hexacopter_V2_B.roll_g *
    FLIGHT_Hexacopter_V2_B.ParamStep *
    FLIGHT_Hexacopter_V2_P.Integrator_gainval_e;
  FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_l = static_cast<int8_T>
    (rtb_AND);

  // Update for UnitDelay: '<S157>/Unit Delay1'
  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i = FLIGHT_Hexacopter_V2_B.q_c;

  // Update for UnitDelay: '<S154>/UD'
  //
  //  Block description for '<S154>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_a = FLIGHT_Hexacopter_V2_B.TSamp_k;

  // Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE +=
    FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_gainval *
    FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_3;
  if (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE >
      FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_UpperSat) {
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE =
      FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_UpperSat;
  } else if (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE <
             FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_LowerSat) {
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE =
      FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_LowerSat;
  }

  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRese = static_cast<int8_T>
    (rtb_AND1);

  // Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator'

  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE +=
    FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator1_gainval *
    FLIGHT_Hexacopter_V2_B.rtb_ypr_idx_1;
  if (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE >
      FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator1_UpperSa) {
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE =
      FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator1_UpperSa;
  } else if (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE <
             FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator1_LowerSa) {
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE =
      FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator1_LowerSa;
  }

  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_PrevRes = static_cast<int8_T>
    (rtb_AND1);

  // End of Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'

  // Update for UnitDelay: '<S233>/UD' incorporates:
  //   SampleTimeMath: '<S233>/TSamp'
  //   Sum: '<S233>/Diff'
  //
  //  About '<S233>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //    *
  //  Block description for '<S233>/UD':
  //
  //   Store in Global RAM
  //
  //  Block description for '<S233>/Diff':
  //
  //   Add in CPU

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[0] = FLIGHT_Hexacopter_V2_B.TSamp_o[0];
  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[1] = FLIGHT_Hexacopter_V2_B.TSamp_o[1];
  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[2] = FLIGHT_Hexacopter_V2_B.TSamp_o[2];

  // Update for UnitDelay: '<S231>/UD'
  //
  //  Block description for '<S231>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_o2 = FLIGHT_Hexacopter_V2_B.Gain5;

  // Update for UnitDelay: '<S232>/UD'
  //
  //  Block description for '<S232>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_e = FLIGHT_Hexacopter_V2_B.Gain6;

  // Update for DiscreteIntegrator: '<S271>/Filter'
  FLIGHT_Hexacopter_V2_DW.Filter_DSTATE += FLIGHT_Hexacopter_V2_P.Filter_gainval
    * FLIGHT_Hexacopter_V2_B.Gain4;

  // Update for DiscreteIntegrator: '<S326>/Integrator' incorporates:
  //   Gain: '<S323>/Integral Gain'

  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_h +=
    FLIGHT_Hexacopter_V2_P.DiscretePIDController2_I *
    FLIGHT_Hexacopter_V2_B.rtb_MatrixConcatenate_idx_0 *
    FLIGHT_Hexacopter_V2_P.Integrator_gainval_c;
  FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_he = static_cast<int8_T>
    (rtb_flag_pos);
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void FLIGHT_Hexacopter_V2_step(int_T tid)
{
  switch (tid) {
   case 0 :
    FLIGHT_Hexacopter_V2_step0();
    break;

   case 1 :
    FLIGHT_Hexacopter_V2_step1();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void FLIGHT_Hexacopter_V2_initialize(void)
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
    static const char_T ParameterNameStr_5[9] = "SMC_I_XX";
    static const char_T ParameterNameStr_6[9] = "SMC_I_YY";
    static const char_T ParameterNameStr_7[9] = "SMC_I_ZZ";
    static const char_T ParameterNameStr_8[17] = "MPC_Z_VEL_MAX_UP";
    static const char_T ParameterNameStr_9[16] = "MPC_Z_VEL_P_ACC";
    static const char_T ParameterNameStr_a[16] = "MPC_Z_VEL_D_ACC";
    static const char_T ParameterNameStr_b[17] = "IMU_DGYRO_CUTOFF";
    static const char_T ParameterNameStr_c[14] = "MPC_THR_HOVER";
    static const char_T ParameterNameStr_d[17] = "MPC_XY_VEL_P_ACC";
    static const char_T ParameterNameStr_e[9] = "MPC_XY_P";
    static const char_T ParameterNameStr_f[11] = "SMC_K_SS_D";
    static const char_T ParameterNameStr_g[15] = "SMC_LPF_CUTOFF";
    static const char_T ParameterNameStr_h[17] = "DOUBLET_PEAK_ANG";
    static const char_T ParameterNameStr_i[11] = "DOUBLET_DT";
    static const char_T ParameterNameStr_j[13] = "DOUBLET_AXIS";
    static const char_T ParameterNameStr_k[11] = "SMC_K_SS_P";
    static const char_T ParameterNameStr_l[11] = "SMC_K_SS_I";
    static const char_T ParameterNameStr_m[14] = "SMC_K_REACH_S";
    static const char_T ParameterNameStr_n[14] = "SMC_K_REACH_P";
    static const char_T ParameterNameStr_o[12] = "SMC_EPSILON";
    static const char_T ParameterNameStr_p[16] = "MC_ROLLRATE_MAX";
    static const char_T ParameterNameStr_q[10] = "MC_ROLL_P";
    static const char_T ParameterNameStr_r[17] = "MC_PITCHRATE_MAX";
    static const char_T ParameterNameStr_s[11] = "MC_PITCH_P";
    static const char_T ParameterNameStr_t[16] = "MPC_Z_VEL_I_ACC";
    static const char_T ParameterNameStr_u[14] = "MC_ROLLRATE_D";
    static const char_T ParameterNameStr_v[15] = "MC_PITCHRATE_P";
    static const char_T ParameterNameStr_w[15] = "MC_PITCHRATE_I";
    static const char_T ParameterNameStr_x[15] = "MC_PITCHRATE_D";
    static const char_T ParameterNameStr_y[13] = "MC_YAWRATE_P";
    static const char_T ParameterNameStr_z[13] = "MC_YAWRATE_I";
    static const char_T ParameterNameStr_10[13] = "MC_YAWRATE_D";
    static const char_T ParameterNameStr_11[14] = "MC_YAWRATE_FF";
    static const char_T ParameterNameStr_12[14] = "MC_ROLLRATE_I";
    static const char_T ParameterNameStr_13[14] = "MC_ROLLRATE_P";
    real_T tmp;

    // Start for RateTransition: '<S10>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4 =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialConditio;

    // Start for RateTransition: '<S9>/Rate Transition3'
    FLIGHT_Hexacopter_V2_B.RateTransition3 =
      FLIGHT_Hexacopter_V2_P.RateTransition3_InitialConditio;

    // Start for RateTransition: '<S351>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.RateTransition =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialCondition;

    // Start for RateTransition: '<S351>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4_a =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialCondit_l;

    // Start for RateTransition: '<S351>/Rate Transition6'
    FLIGHT_Hexacopter_V2_B.RateTransition6 =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialConditio;

    // Start for RateTransition: '<S351>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.RateTransition2 =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialConditio;

    // Start for RateTransition: '<S351>/Rate Transition3'
    FLIGHT_Hexacopter_V2_B.RateTransition3_b =
      FLIGHT_Hexacopter_V2_P.RateTransition3_InitialCondit_o;

    // Start for RateTransition generated from: '<Root>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.rc_ctrl_switch =
      FLIGHT_Hexacopter_V2_P.RateTransition_8_InitialConditi;

    // Start for RateTransition: '<S350>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.RateTransition_e =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialConditi_n;

    // Start for RateTransition: '<S350>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4_b =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialCondit_d;

    // Start for RateTransition: '<S350>/Rate Transition6'
    FLIGHT_Hexacopter_V2_B.RateTransition6_a =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialCondit_l;

    // Start for RateTransition: '<S350>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.RateTransition2_b =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_p;

    // Start for RateTransition: '<S350>/Rate Transition3'
    FLIGHT_Hexacopter_V2_B.RateTransition3_be =
      FLIGHT_Hexacopter_V2_P.RateTransition3_InitialCondit_m;

    // Start for RateTransition: '<S10>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.RateTransition_j =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialConditi_c;

    // Start for RateTransition: '<S10>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1 =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialConditio;

    // Start for RateTransition: '<S352>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.RateTransition_f =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialConditi_m;

    // Start for RateTransition: '<S352>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4_ar =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialCondit_a;

    // Start for RateTransition: '<S352>/Rate Transition6'
    FLIGHT_Hexacopter_V2_B.RateTransition6_o =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialCondit_e;

    // Start for RateTransition: '<S352>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.RateTransition2_d =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_d;

    // Start for RateTransition: '<S352>/Rate Transition3'
    FLIGHT_Hexacopter_V2_B.RateTransition3_e =
      FLIGHT_Hexacopter_V2_P.RateTransition3_InitialCondi_o5;

    // Start for RateTransition generated from: '<Root>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.rc_inject_failure =
      FLIGHT_Hexacopter_V2_P.RateTransition_4_InitialConditi;

    // Start for RateTransition generated from: '<Root>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.VehicleStatus_flag_armed =
      FLIGHT_Hexacopter_V2_P.RateTransition2_16_InitialCondi;

    // Start for RateTransition generated from: '<Root>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.VehicleStatus_flag_kill =
      FLIGHT_Hexacopter_V2_P.RateTransition2_17_InitialCondi;

    // Start for RateTransition: '<S352>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1_c =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialCondit_d;

    // Start for RateTransition: '<S350>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1_d =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialCondit_f;

    // Start for RateTransition: '<S351>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1_o =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialCondit_p;

    // InitializeConditions for RateTransition: '<S10>/Rate Transition4'
    FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialConditio;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition3'
    FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition3_InitialConditio;

    // InitializeConditions for RateTransition: '<S351>/Rate Transition'
    FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialCondition;

    // InitializeConditions for RateTransition: '<S351>/Rate Transition4'
    FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_e =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialCondit_l;

    // InitializeConditions for RateTransition: '<S351>/Rate Transition6'
    FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialConditio;

    // InitializeConditions for DiscreteIntegrator: '<S548>/Integrator'
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCondit;
    FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState = 2;

    // InitializeConditions for RateTransition: '<S351>/Rate Transition2'
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialConditio;

    // InitializeConditions for UnitDelay: '<S513>/Unit Delay1'
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE =
      FLIGHT_Hexacopter_V2_P.UnitDelay1_InitialCondition;

    // InitializeConditions for RateTransition: '<S351>/Rate Transition3'
    FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0_e =
      FLIGHT_Hexacopter_V2_P.RateTransition3_InitialCondit_o;

    // InitializeConditions for UnitDelay: '<S510>/UD'
    //
    //  Block description for '<S510>/UD':
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevScale;

    // InitializeConditions for RateTransition generated from: '<Root>/Rate Transition' 
    FLIGHT_Hexacopter_V2_DW.RateTransition_8_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition_8_InitialConditi;

    // InitializeConditions for RateTransition: '<S350>/Rate Transition'
    FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_c =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialConditi_n;

    // InitializeConditions for RateTransition: '<S350>/Rate Transition4'
    FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_k =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialCondit_d;

    // InitializeConditions for RateTransition: '<S350>/Rate Transition6'
    FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_i =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialCondit_l;

    // InitializeConditions for DiscreteIntegrator: '<S493>/Integrator'
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_c =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCond_l;
    FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_h = 2;

    // InitializeConditions for RateTransition: '<S350>/Rate Transition2'
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_l =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_p;

    // InitializeConditions for UnitDelay: '<S458>/Unit Delay1'
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_k =
      FLIGHT_Hexacopter_V2_P.UnitDelay1_InitialCondition_h;

    // InitializeConditions for RateTransition: '<S350>/Rate Transition3'
    FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0_p =
      FLIGHT_Hexacopter_V2_P.RateTransition3_InitialCondit_m;

    // InitializeConditions for UnitDelay: '<S455>/UD'
    //
    //  Block description for '<S455>/UD':
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_o =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevSca_k;

    // InitializeConditions for RateTransition: '<S10>/Rate Transition'
    FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_h =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialConditi_c;

    // InitializeConditions for RateTransition: '<S10>/Rate Transition1'
    FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialConditio;

    // InitializeConditions for RateTransition: '<S352>/Rate Transition'
    FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_hv =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialConditi_m;

    // InitializeConditions for RateTransition: '<S352>/Rate Transition4'
    FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_c =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialCondit_a;

    // InitializeConditions for RateTransition: '<S352>/Rate Transition6'
    FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_o =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialCondit_e;

    // InitializeConditions for DiscreteIntegrator: '<S603>/Integrator'
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_o =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCond_p;
    FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_hd = 2;

    // InitializeConditions for RateTransition: '<S352>/Rate Transition2'
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_d;

    // InitializeConditions for UnitDelay: '<S568>/Unit Delay1'
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_kh =
      FLIGHT_Hexacopter_V2_P.UnitDelay1_InitialCondition_c;

    // InitializeConditions for RateTransition: '<S352>/Rate Transition3'
    FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0_d =
      FLIGHT_Hexacopter_V2_P.RateTransition3_InitialCondi_o5;

    // InitializeConditions for UnitDelay: '<S565>/UD'
    //
    //  Block description for '<S565>/UD':
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_k =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevSca_f;

    // InitializeConditions for RateTransition generated from: '<Root>/Rate Transition' 
    FLIGHT_Hexacopter_V2_DW.RateTransition_4_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition_4_InitialConditi;

    // InitializeConditions for RateTransition generated from: '<Root>/Rate Transition2' 
    FLIGHT_Hexacopter_V2_DW.RateTransition2_16_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition2_16_InitialCondi;

    // InitializeConditions for RateTransition generated from: '<Root>/Rate Transition2' 
    FLIGHT_Hexacopter_V2_DW.RateTransition2_17_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition2_17_InitialCondi;

    // InitializeConditions for UnitDelay: '<S568>/Unit Delay2'
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE =
      FLIGHT_Hexacopter_V2_P.UnitDelay2_InitialCondition;

    // InitializeConditions for RateTransition: '<S352>/Rate Transition1'
    FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_m =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialCondit_d;

    // InitializeConditions for UnitDelay: '<S458>/Unit Delay2'
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_l =
      FLIGHT_Hexacopter_V2_P.UnitDelay2_InitialCondition_b;

    // InitializeConditions for RateTransition: '<S350>/Rate Transition1'
    FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_l =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialCondit_f;

    // InitializeConditions for UnitDelay: '<S513>/Unit Delay2'
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_h =
      FLIGHT_Hexacopter_V2_P.UnitDelay2_InitialCondition_e;

    // InitializeConditions for RateTransition: '<S351>/Rate Transition1'
    FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_l4 =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialCondit_p;

    // InitializeConditions for DiscreteIntegrator: '<S192>/Integrator'
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_l =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCon_pr;
    FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_l = 2;

    // InitializeConditions for UnitDelay: '<S157>/Unit Delay1'
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i =
      FLIGHT_Hexacopter_V2_P.UnitDelay1_InitialCondition_e;

    // InitializeConditions for UnitDelay: '<S154>/UD'
    //
    //  Block description for '<S154>/UD':
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_a =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevSca_n;

    // InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' 
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRese = 2;
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' 
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_PrevRes = 2;
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;

    // InitializeConditions for UnitDelay: '<S233>/UD' incorporates:
    //   Sum: '<S233>/Diff'
    //
    //  Block description for '<S233>/UD':
    //
    //   Store in Global RAM
    //
    //  Block description for '<S233>/Diff':
    //
    //   Add in CPU

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[0] =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevSca_e;
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[1] =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevSca_e;
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[2] =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevSca_e;

    // InitializeConditions for UnitDelay: '<S343>/Unit Delay'
    FLIGHT_Hexacopter_V2_DW.UnitDelay_DSTATE =
      FLIGHT_Hexacopter_V2_P.UnitDelay_InitialCondition;

    // InitializeConditions for UnitDelay: '<S231>/UD'
    //
    //  Block description for '<S231>/UD':
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_o2 =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for UnitDelay: '<S232>/UD'
    //
    //  Block description for '<S232>/UD':
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_e =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative1_ICPrevScale;

    // InitializeConditions for DiscreteIntegrator: '<S271>/Filter'
    FLIGHT_Hexacopter_V2_DW.Filter_DSTATE =
      FLIGHT_Hexacopter_V2_P.DiscretePIDController1_InitialC;

    // InitializeConditions for DiscreteIntegrator: '<S326>/Integrator'
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_h =
      FLIGHT_Hexacopter_V2_P.DiscretePIDController2_InitialC;
    FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_he = 2;

    // InitializeConditions for UnitDelay: '<S157>/Unit Delay2'
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_f =
      FLIGHT_Hexacopter_V2_P.UnitDelay2_InitialCondition_m;

    // SystemInitialize for MATLAB Function: '<S4>/MATLAB Function1'
    FLIGHT_Hexacopter_V2_DW.start_time_usec = -1.0;

    // SystemInitialize for Enabled SubSystem: '<S212>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S213>/In1' incorporates:
    //   Outport: '<S213>/Out1'

    FLIGHT_Hexacopter_V2_B.In1_p = FLIGHT_Hexacopter_V2_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S212>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S214>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S215>/In1' incorporates:
    //   Outport: '<S215>/Out1'

    FLIGHT_Hexacopter_V2_B.In1_k = FLIGHT_Hexacopter_V2_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S214>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S217>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S223>/In1' incorporates:
    //   Outport: '<S223>/Out1'

    FLIGHT_Hexacopter_V2_B.In1_e = FLIGHT_Hexacopter_V2_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S217>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S218>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S224>/In1' incorporates:
    //   Outport: '<S224>/Out1'

    FLIGHT_Hexacopter_V2_B.In1_m = FLIGHT_Hexacopter_V2_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S218>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S219>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S225>/In1' incorporates:
    //   Outport: '<S225>/Out1'

    FLIGHT_Hexacopter_V2_B.In1 = FLIGHT_Hexacopter_V2_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S219>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S220>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S226>/In1' incorporates:
    //   Outport: '<S226>/Out1'

    FLIGHT_Hexacopter_V2_B.In1_d = FLIGHT_Hexacopter_V2_P.Out1_Y0_g;

    // End of SystemInitialize for SubSystem: '<S220>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S227>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S228>/In1' incorporates:
    //   Outport: '<S228>/Out1'

    FLIGHT_Hexacopter_V2_B.In1_b = FLIGHT_Hexacopter_V2_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S227>/Enabled Subsystem'

    // Start for MATLABSystem: '<S214>/SourceBlock'
    FLIGHT_Hexacopter_V2_DW.obj_mh.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_mh.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_mh.orbMetadataObj = ORB_ID
      (vehicle_angular_velocity);
    uORB_read_initialize(FLIGHT_Hexacopter_V2_DW.obj_mh.orbMetadataObj,
                         &FLIGHT_Hexacopter_V2_DW.obj_mh.eventStructObj);
    FLIGHT_Hexacopter_V2_DW.obj_mh.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter13'
    FLIGHT_Hexacopter_V2_DW.obj_oe.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_oe.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS;
    FLIGHT_Hexacopter_V2_DW.obj_oe.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_oe.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_oe.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_oe.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_oe.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S12>/Read Parameter13'

    // Start for MATLABSystem: '<S12>/Read Parameter1'
    FLIGHT_Hexacopter_V2_DW.obj_aw.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_aw.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS;
    FLIGHT_Hexacopter_V2_DW.obj_aw.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_aw.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_aw.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_aw.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_aw.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S12>/Read Parameter1'

    // Start for MATLABSystem: '<S12>/Read Parameter2'
    FLIGHT_Hexacopter_V2_DW.obj_ps.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ps.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS;
    FLIGHT_Hexacopter_V2_DW.obj_ps.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_ps.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_ps.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_ps.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_ps.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S12>/Read Parameter2'

    // Start for MATLABSystem: '<S12>/Read Parameter3'
    FLIGHT_Hexacopter_V2_DW.obj_h.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_h.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS;
    FLIGHT_Hexacopter_V2_DW.obj_h.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_h.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_h.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_h.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S12>/Read Parameter3'

    // Start for MATLABSystem: '<S12>/Read Parameter4'
    FLIGHT_Hexacopter_V2_DW.obj_jg.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_jg.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS;
    FLIGHT_Hexacopter_V2_DW.obj_jg.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_jg.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_jg.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_jg.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_jg.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S12>/Read Parameter4'

    // Start for MATLABSystem: '<S12>/Read Parameter5'
    FLIGHT_Hexacopter_V2_DW.obj_ic5.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ic5.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime_SAS;
    FLIGHT_Hexacopter_V2_DW.obj_ic5.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_ic5.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_ic5.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_ic5.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_ic5.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S12>/Read Parameter5'

    // Start for MATLABSystem: '<S1>/PX4 PWM Output'
    FLIGHT_Hexacopter_V2_DW.obj_md.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_md.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_md.isInitialized = 1;
    FLIGHT_Hexacopter_PWM_setupImpl(&FLIGHT_Hexacopter_V2_DW.obj_md, false,
      false);
    FLIGHT_Hexacopter_V2_DW.obj_md.isSetupComplete = true;
    FLIGHT_He_PX4Timestamp_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_e);

    // Start for MATLABSystem: '<S3>/PX4 Timestamp'
    FLIGHT_Hexacopter_V2_DW.obj_a5.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_a5.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_a5.isSetupComplete = true;

    // Start for MATLABSystem: '<S40>/SinkBlock' incorporates:
    //   BusAssignment: '<S29>/Bus Assignment'

    FLIGHT_Hexacopter_V2_DW.obj_nf.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_nf.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_nf.orbMetadataObj = ORB_ID(actuator_motors);
    uORB_write_initialize(FLIGHT_Hexacopter_V2_DW.obj_nf.orbMetadataObj,
                          &FLIGHT_Hexacopter_V2_DW.obj_nf.orbAdvertiseObj,
                          &FLIGHT_Hexacopter_V2_B.BusAssignment_e, 1);
    FLIGHT_Hexacopter_V2_DW.obj_nf.isSetupComplete = true;
    FLIGHT_He_PX4Timestamp_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_c);

    // Start for MATLABSystem: '<S32>/SinkBlock' incorporates:
    //   BusAssignment: '<S24>/Bus Assignment'

    FLIGHT_Hexacopter_V2_DW.obj_fe.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_fe.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_fe.orbMetadataObj = ORB_ID
      (actuator_controls_status_0);
    uORB_write_initialize(FLIGHT_Hexacopter_V2_DW.obj_fe.orbMetadataObj,
                          &FLIGHT_Hexacopter_V2_DW.obj_fe.orbAdvertiseObj,
                          &FLIGHT_Hexacopter_V2_B.BusAssignment_j, 1);
    FLIGHT_Hexacopter_V2_DW.obj_fe.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter34'
    FLIGHT_Hexacopter_V2_DW.obj_o.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_o.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_o.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_o.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_o.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_o.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter34'

    // Start for MATLABSystem: '<S5>/Read Parameter35'
    FLIGHT_Hexacopter_V2_DW.obj_b.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_b.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_b.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_b.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_b.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_6[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter35'

    // Start for MATLABSystem: '<S5>/Read Parameter36'
    FLIGHT_Hexacopter_V2_DW.obj_l.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_l.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_l.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_l.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_l.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_l.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_7[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter36'

    // Start for MATLABSystem: '<S219>/SourceBlock'
    FLIGHT_Hexacopter_V2_DW.obj_lk.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_lk.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_lk.orbMetadataObj = ORB_ID
      (vehicle_local_position);
    uORB_read_initialize(FLIGHT_Hexacopter_V2_DW.obj_lk.orbMetadataObj,
                         &FLIGHT_Hexacopter_V2_DW.obj_lk.eventStructObj);
    FLIGHT_Hexacopter_V2_DW.obj_lk.isSetupComplete = true;

    // Start for MATLABSystem: '<S212>/SourceBlock'
    FLIGHT_Hexacopter_V2_DW.obj_nt.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_nt.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_nt.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(FLIGHT_Hexacopter_V2_DW.obj_nt.orbMetadataObj,
                         &FLIGHT_Hexacopter_V2_DW.obj_nt.eventStructObj);
    FLIGHT_Hexacopter_V2_DW.obj_nt.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter39'
    FLIGHT_Hexacopter_V2_DW.obj_g.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_g.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_g.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_g.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_g.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_8[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter39'

    // Start for MATLABSystem: '<S5>/Read Parameter3'
    FLIGHT_Hexacopter_V2_DW.obj_c4.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_c4.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_c4.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_c4.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_c4.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_c4.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_9[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_c4.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter3'
    FLIGHT_Hex_SourceBlock_Init(&FLIGHT_Hexacopter_V2_DW.SourceBlock_l);

    // Start for MATLABSystem: '<S5>/Read Parameter5'
    FLIGHT_Hexacopter_V2_DW.obj_i.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_i.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_i.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_i.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_i.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_i.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_a[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_i.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter5'

    // Start for MATLABSystem: '<S5>/Read Parameter11'
    FLIGHT_Hexacopter_V2_DW.obj_jk.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_jk.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_jk.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_jk.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_jk.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_jk.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_b[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_jk.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter11'

    // Start for MATLABSystem: '<S5>/Read Parameter26'
    FLIGHT_Hexacopter_V2_DW.obj_lt.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_lt.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_lt.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_lt.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_lt.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_lt.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_c[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_lt.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter26'

    // Start for MATLABSystem: '<S5>/Read Parameter28'
    FLIGHT_Hexacopter_V2_DW.obj_ic.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ic.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_ic.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_ic.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_ic.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_ic.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_d[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_ic.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter28'

    // Start for MATLABSystem: '<S5>/Read Parameter27'
    FLIGHT_Hexacopter_V2_DW.obj_l3.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_l3.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_l3.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_l3.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_l3.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_l3.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_e[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_l3.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter27'

    // Start for MATLABSystem: '<S218>/SourceBlock'
    FLIGHT_Hexacopter_V2_DW.obj_ab.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ab.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_ab.orbMetadataObj = ORB_ID(vehicle_status);
    uORB_read_initialize(FLIGHT_Hexacopter_V2_DW.obj_ab.orbMetadataObj,
                         &FLIGHT_Hexacopter_V2_DW.obj_ab.eventStructObj);
    FLIGHT_Hexacopter_V2_DW.obj_ab.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter31'
    FLIGHT_Hexacopter_V2_DW.obj_as.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_as.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_as.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_as.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_as.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_as.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_f[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_as.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter31'

    // Start for MATLABSystem: '<S227>/SourceBlock'
    FLIGHT_Hexacopter_V2_DW.obj_i4.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_i4.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_i4.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(FLIGHT_Hexacopter_V2_DW.obj_i4.orbMetadataObj,
                         &FLIGHT_Hexacopter_V2_DW.obj_i4.eventStructObj);
    FLIGHT_Hexacopter_V2_DW.obj_i4.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter38'
    FLIGHT_Hexacopter_V2_DW.obj_e.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_e.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_e.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_e.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_e.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_e.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_g[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter38'
    FLIGHT__PX4Timestamp_k_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_pna);

    // Start for MATLABSystem: '<S5>/Read Parameter1'
    FLIGHT_Hexacopter_V2_DW.obj_l4.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_l4.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_l4.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_l4.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_l4.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_l4.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_h[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_l4.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter1'

    // Start for MATLABSystem: '<S5>/Read Parameter'
    FLIGHT_Hexacopter_V2_DW.obj_jf.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_jf.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_jf.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_jf.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_jf.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_jf.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_i[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_jf.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter'

    // Start for MATLABSystem: '<S5>/Read Parameter2'
    FLIGHT_Hexacopter_V2_DW.obj_a1.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_a1.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_a1.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_a1.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_a1.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_a1.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_j[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_a1.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter2'

    // Start for MATLABSystem: '<S5>/Read Parameter29'
    FLIGHT_Hexacopter_V2_DW.obj_br.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_br.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_br.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_br.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_br.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_br.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_k[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_br.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter29'

    // Start for MATLABSystem: '<S5>/Read Parameter30'
    FLIGHT_Hexacopter_V2_DW.obj_m.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_m.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_m.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_m.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_m.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_m.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_l[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter30'
    FLIGHT_Hex_SourceBlock_Init(&FLIGHT_Hexacopter_V2_DW.SourceBlock_p);

    // Start for MATLABSystem: '<S5>/Read Parameter32'
    FLIGHT_Hexacopter_V2_DW.obj_lv.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_lv.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_lv.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_lv.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_lv.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_lv.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_m[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_lv.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter32'

    // Start for MATLABSystem: '<S5>/Read Parameter33'
    FLIGHT_Hexacopter_V2_DW.obj_bd.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_bd.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_bd.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_bd.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_bd.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_bd.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_n[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_bd.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter33'

    // Start for MATLABSystem: '<S5>/Read Parameter37'
    FLIGHT_Hexacopter_V2_DW.obj_pi.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_pi.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_pi.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_pi.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_pi.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_pi.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_o[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_pi.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter37'
    FLIGHT__PX4Timestamp_c_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_j);

    // Start for MATLABSystem: '<S34>/SinkBlock' incorporates:
    //   BusAssignment: '<S25>/Bus Assignment'

    FLIGHT_Hexacopter_V2_DW.obj_m1.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_m1.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_m1.orbMetadataObj = ORB_ID
      (vehicle_attitude_setpoint);
    uORB_write_initialize(FLIGHT_Hexacopter_V2_DW.obj_m1.orbMetadataObj,
                          &FLIGHT_Hexacopter_V2_DW.obj_m1.orbAdvertiseObj,
                          &FLIGHT_Hexacopter_V2_B.BusAssignment_f, 1);
    FLIGHT_Hexacopter_V2_DW.obj_m1.isSetupComplete = true;
    FLIGHT__PX4Timestamp_c_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_p);

    // Start for MATLABSystem: '<S5>/Read Parameter9'
    FLIGHT_Hexacopter_V2_DW.obj_a.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_a.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_a.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_a.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_a.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_p[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter9'

    // Start for MATLABSystem: '<S5>/Read Parameter6'
    FLIGHT_Hexacopter_V2_DW.obj_p.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_p.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_p.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_p.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_p.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_q[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter6'

    // Start for MATLABSystem: '<S5>/Read Parameter10'
    FLIGHT_Hexacopter_V2_DW.obj_bq.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_bq.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_bq.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_bq.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_bq.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_bq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_r[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_bq.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter10'

    // Start for MATLABSystem: '<S5>/Read Parameter7'
    FLIGHT_Hexacopter_V2_DW.obj_fj.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_fj.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_fj.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_fj.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_fj.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_fj.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_s[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_fj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter7'

    // Start for MATLABSystem: '<S36>/SinkBlock' incorporates:
    //   BusAssignment: '<S26>/Bus Assignment'

    FLIGHT_Hexacopter_V2_DW.obj_mp.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_mp.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_mp.orbMetadataObj = ORB_ID
      (vehicle_rates_setpoint);
    uORB_write_initialize(FLIGHT_Hexacopter_V2_DW.obj_mp.orbMetadataObj,
                          &FLIGHT_Hexacopter_V2_DW.obj_mp.orbAdvertiseObj,
                          &FLIGHT_Hexacopter_V2_B.BusAssignment_e0, 1);
    FLIGHT_Hexacopter_V2_DW.obj_mp.isSetupComplete = true;
    FLIGHT__PX4Timestamp_c_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_k);

    // Start for MATLABSystem: '<S42>/SinkBlock' incorporates:
    //   BusAssignment: '<S30>/Bus Assignment'

    FLIGHT_Hexacopter_V2_DW.obj_pm.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_pm.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_pm.orbMetadataObj = ORB_ID
      (vehicle_local_position_setpoint);
    uORB_write_initialize(FLIGHT_Hexacopter_V2_DW.obj_pm.orbMetadataObj,
                          &FLIGHT_Hexacopter_V2_DW.obj_pm.orbAdvertiseObj,
                          &FLIGHT_Hexacopter_V2_B.BusAssignment_g, 1);
    FLIGHT_Hexacopter_V2_DW.obj_pm.isSetupComplete = true;
    FLIGHT__PX4Timestamp_k_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_pn);

    // Start for MATLABSystem: '<S38>/SinkBlock' incorporates:
    //   BusAssignment: '<S28>/Bus Assignment'

    FLIGHT_Hexacopter_V2_DW.obj_k.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_k.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_k.orbMetadataObj = ORB_ID
      (vehicle_attitude_smc_setpoint);
    uORB_write_initialize(FLIGHT_Hexacopter_V2_DW.obj_k.orbMetadataObj,
                          &FLIGHT_Hexacopter_V2_DW.obj_k.orbAdvertiseObj,
                          &FLIGHT_Hexacopter_V2_B.BusAssignment, 1);
    FLIGHT_Hexacopter_V2_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter4'
    FLIGHT_Hexacopter_V2_DW.obj_c.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_c.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_c.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_c.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_c.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_c.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_t[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter4'

    // Start for MATLABSystem: '<S5>/Read Parameter12'
    FLIGHT_Hexacopter_V2_DW.obj_jo.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_jo.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_jo.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_jo.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_jo.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_jo.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_u[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_jo.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter12'

    // Start for MATLABSystem: '<S5>/Read Parameter13'
    FLIGHT_Hexacopter_V2_DW.obj_pf.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_pf.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_pf.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_pf.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_pf.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_pf.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_v[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_pf.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter13'

    // Start for MATLABSystem: '<S5>/Read Parameter14'
    FLIGHT_Hexacopter_V2_DW.obj_fd.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_fd.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_fd.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_fd.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_fd.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_fd.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_w[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_fd.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter14'

    // Start for MATLABSystem: '<S5>/Read Parameter15'
    FLIGHT_Hexacopter_V2_DW.obj_n.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_n.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_n.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_n.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_n.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_n.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_x[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter15'

    // Start for MATLABSystem: '<S5>/Read Parameter16'
    FLIGHT_Hexacopter_V2_DW.obj_j.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_j.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_j.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_j.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_j.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_j.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_y[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter16'

    // Start for MATLABSystem: '<S5>/Read Parameter17'
    FLIGHT_Hexacopter_V2_DW.obj_d.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_d.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_d.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_d.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_d.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_z[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter17'

    // Start for MATLABSystem: '<S5>/Read Parameter18'
    FLIGHT_Hexacopter_V2_DW.obj_ml.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ml.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_ml.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_ml.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_ml.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_ml.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_10[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_ml.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter18'

    // Start for MATLABSystem: '<S5>/Read Parameter19'
    FLIGHT_Hexacopter_V2_DW.obj_mc.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_mc.SampleTime =
      FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_mc.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_mc.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_mc.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_mc.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_11[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_mc.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter19'

    // Start for MATLABSystem: '<S5>/Read Parameter8'
    FLIGHT_Hexacopter_V2_DW.obj_f.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_f.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj_f.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj_f.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj_f.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj_f.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_12[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/Read Parameter8'

    // Start for MATLABSystem: '<S5>/read_mc_rollrate_p'
    FLIGHT_Hexacopter_V2_DW.obj.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj.SampleTime = FLIGHT_Hexacopter_V2_P.SampleTime;
    FLIGHT_Hexacopter_V2_DW.obj.isInitialized = 1;
    if (FLIGHT_Hexacopter_V2_DW.obj.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_Hexacopter_V2_DW.obj.SampleTime;
    }

    FLIGHT_Hexacopter_V2_DW.obj.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_13[0], true, tmp * 1000.0);
    FLIGHT_Hexacopter_V2_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/read_mc_rollrate_p'
  }
}

// Model terminate function
void FLIGHT_Hexacopter_V2_terminate(void)
{
  // Terminate for MATLABSystem: '<S214>/SourceBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_mh.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_mh.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_mh.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_mh.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_V2_DW.obj_mh.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S214>/SourceBlock'

  // Terminate for MATLABSystem: '<S12>/Read Parameter13'
  if (!FLIGHT_Hexacopter_V2_DW.obj_oe.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_oe.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter13'

  // Terminate for MATLABSystem: '<S12>/Read Parameter1'
  if (!FLIGHT_Hexacopter_V2_DW.obj_aw.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_aw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter1'

  // Terminate for MATLABSystem: '<S12>/Read Parameter2'
  if (!FLIGHT_Hexacopter_V2_DW.obj_ps.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_ps.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter2'

  // Terminate for MATLABSystem: '<S12>/Read Parameter3'
  if (!FLIGHT_Hexacopter_V2_DW.obj_h.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter3'

  // Terminate for MATLABSystem: '<S12>/Read Parameter4'
  if (!FLIGHT_Hexacopter_V2_DW.obj_jg.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_jg.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter4'

  // Terminate for MATLABSystem: '<S12>/Read Parameter5'
  if (!FLIGHT_Hexacopter_V2_DW.obj_ic5.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_ic5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter5'

  // Terminate for MATLABSystem: '<S1>/PX4 PWM Output'
  if (!FLIGHT_Hexacopter_V2_DW.obj_md.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_md.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_md.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_md.isSetupComplete) {
      pwm_disarm(&FLIGHT_Hexacopter_V2_DW.obj_md.armAdvertiseObj);
      pwm_resetServo(FLIGHT_Hexacopter_V2_DW.obj_md.servoCount,
                     FLIGHT_Hexacopter_V2_DW.obj_md.isMain,
                     &FLIGHT_Hexacopter_V2_DW.obj_md.actuatorAdvertiseObj);
      pwm_close(FLIGHT_Hexacopter_V2_DW.obj_md.servoCount,
                &FLIGHT_Hexacopter_V2_DW.obj_md.actuatorAdvertiseObj,
                &FLIGHT_Hexacopter_V2_DW.obj_md.armAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1>/PX4 PWM Output'
  FLIGHT_He_PX4Timestamp_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_e);

  // Terminate for MATLABSystem: '<S3>/PX4 Timestamp'
  if (!FLIGHT_Hexacopter_V2_DW.obj_a5.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_a5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/PX4 Timestamp'

  // Terminate for MATLABSystem: '<S40>/SinkBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_nf.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_nf.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_nf.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_nf.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_Hexacopter_V2_DW.obj_nf.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S40>/SinkBlock'
  FLIGHT_He_PX4Timestamp_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_c);

  // Terminate for MATLABSystem: '<S32>/SinkBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_fe.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_fe.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_fe.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_fe.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_Hexacopter_V2_DW.obj_fe.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S32>/SinkBlock'

  // Terminate for MATLABSystem: '<S5>/Read Parameter34'
  if (!FLIGHT_Hexacopter_V2_DW.obj_o.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter34'

  // Terminate for MATLABSystem: '<S5>/Read Parameter35'
  if (!FLIGHT_Hexacopter_V2_DW.obj_b.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter35'

  // Terminate for MATLABSystem: '<S5>/Read Parameter36'
  if (!FLIGHT_Hexacopter_V2_DW.obj_l.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter36'

  // Terminate for MATLABSystem: '<S219>/SourceBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_lk.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_lk.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_lk.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_lk.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_V2_DW.obj_lk.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S219>/SourceBlock'

  // Terminate for MATLABSystem: '<S212>/SourceBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_nt.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_nt.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_nt.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_nt.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_V2_DW.obj_nt.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S212>/SourceBlock'

  // Terminate for MATLABSystem: '<S5>/Read Parameter39'
  if (!FLIGHT_Hexacopter_V2_DW.obj_g.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter39'

  // Terminate for MATLABSystem: '<S5>/Read Parameter3'
  if (!FLIGHT_Hexacopter_V2_DW.obj_c4.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_c4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter3'
  FLIGHT_Hex_SourceBlock_Term(&FLIGHT_Hexacopter_V2_DW.SourceBlock_l);

  // Terminate for MATLABSystem: '<S5>/Read Parameter5'
  if (!FLIGHT_Hexacopter_V2_DW.obj_i.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter5'

  // Terminate for MATLABSystem: '<S5>/Read Parameter11'
  if (!FLIGHT_Hexacopter_V2_DW.obj_jk.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_jk.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter11'

  // Terminate for MATLABSystem: '<S5>/Read Parameter26'
  if (!FLIGHT_Hexacopter_V2_DW.obj_lt.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_lt.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter26'

  // Terminate for MATLABSystem: '<S5>/Read Parameter28'
  if (!FLIGHT_Hexacopter_V2_DW.obj_ic.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_ic.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter28'

  // Terminate for MATLABSystem: '<S5>/Read Parameter27'
  if (!FLIGHT_Hexacopter_V2_DW.obj_l3.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_l3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter27'

  // Terminate for MATLABSystem: '<S218>/SourceBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_ab.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_ab.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_ab.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_ab.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_V2_DW.obj_ab.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S218>/SourceBlock'

  // Terminate for MATLABSystem: '<S5>/Read Parameter31'
  if (!FLIGHT_Hexacopter_V2_DW.obj_as.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_as.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter31'

  // Terminate for MATLABSystem: '<S227>/SourceBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_i4.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_i4.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_i4.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_i4.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_V2_DW.obj_i4.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S227>/SourceBlock'

  // Terminate for MATLABSystem: '<S5>/Read Parameter38'
  if (!FLIGHT_Hexacopter_V2_DW.obj_e.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter38'
  FLIGHT__PX4Timestamp_m_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_pna);

  // Terminate for MATLABSystem: '<S5>/Read Parameter1'
  if (!FLIGHT_Hexacopter_V2_DW.obj_l4.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_l4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter1'

  // Terminate for MATLABSystem: '<S5>/Read Parameter'
  if (!FLIGHT_Hexacopter_V2_DW.obj_jf.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_jf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter'

  // Terminate for MATLABSystem: '<S5>/Read Parameter2'
  if (!FLIGHT_Hexacopter_V2_DW.obj_a1.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_a1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter2'

  // Terminate for MATLABSystem: '<S5>/Read Parameter29'
  if (!FLIGHT_Hexacopter_V2_DW.obj_br.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_br.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter29'

  // Terminate for MATLABSystem: '<S5>/Read Parameter30'
  if (!FLIGHT_Hexacopter_V2_DW.obj_m.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter30'
  FLIGHT_Hex_SourceBlock_Term(&FLIGHT_Hexacopter_V2_DW.SourceBlock_p);

  // Terminate for MATLABSystem: '<S5>/Read Parameter32'
  if (!FLIGHT_Hexacopter_V2_DW.obj_lv.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_lv.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter32'

  // Terminate for MATLABSystem: '<S5>/Read Parameter33'
  if (!FLIGHT_Hexacopter_V2_DW.obj_bd.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_bd.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter33'

  // Terminate for MATLABSystem: '<S5>/Read Parameter37'
  if (!FLIGHT_Hexacopter_V2_DW.obj_pi.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_pi.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter37'
  FLIGHT__PX4Timestamp_d_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_j);

  // Terminate for MATLABSystem: '<S34>/SinkBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_m1.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_m1.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_m1.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_m1.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_Hexacopter_V2_DW.obj_m1.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S34>/SinkBlock'
  FLIGHT__PX4Timestamp_d_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_p);

  // Terminate for MATLABSystem: '<S5>/Read Parameter9'
  if (!FLIGHT_Hexacopter_V2_DW.obj_a.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter9'

  // Terminate for MATLABSystem: '<S5>/Read Parameter6'
  if (!FLIGHT_Hexacopter_V2_DW.obj_p.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter6'

  // Terminate for MATLABSystem: '<S5>/Read Parameter10'
  if (!FLIGHT_Hexacopter_V2_DW.obj_bq.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_bq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter10'

  // Terminate for MATLABSystem: '<S5>/Read Parameter7'
  if (!FLIGHT_Hexacopter_V2_DW.obj_fj.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_fj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter7'

  // Terminate for MATLABSystem: '<S36>/SinkBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_mp.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_mp.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_mp.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_mp.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_Hexacopter_V2_DW.obj_mp.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S36>/SinkBlock'
  FLIGHT__PX4Timestamp_d_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_k);

  // Terminate for MATLABSystem: '<S42>/SinkBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_pm.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_pm.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_pm.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_pm.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_Hexacopter_V2_DW.obj_pm.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S42>/SinkBlock'
  FLIGHT__PX4Timestamp_m_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_pn);

  // Terminate for MATLABSystem: '<S38>/SinkBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_k.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_k.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_k.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_Hexacopter_V2_DW.obj_k.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S38>/SinkBlock'

  // Terminate for MATLABSystem: '<S5>/Read Parameter4'
  if (!FLIGHT_Hexacopter_V2_DW.obj_c.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter4'

  // Terminate for MATLABSystem: '<S5>/Read Parameter12'
  if (!FLIGHT_Hexacopter_V2_DW.obj_jo.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_jo.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter12'

  // Terminate for MATLABSystem: '<S5>/Read Parameter13'
  if (!FLIGHT_Hexacopter_V2_DW.obj_pf.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_pf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter13'

  // Terminate for MATLABSystem: '<S5>/Read Parameter14'
  if (!FLIGHT_Hexacopter_V2_DW.obj_fd.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_fd.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter14'

  // Terminate for MATLABSystem: '<S5>/Read Parameter15'
  if (!FLIGHT_Hexacopter_V2_DW.obj_n.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter15'

  // Terminate for MATLABSystem: '<S5>/Read Parameter16'
  if (!FLIGHT_Hexacopter_V2_DW.obj_j.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter16'

  // Terminate for MATLABSystem: '<S5>/Read Parameter17'
  if (!FLIGHT_Hexacopter_V2_DW.obj_d.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter17'

  // Terminate for MATLABSystem: '<S5>/Read Parameter18'
  if (!FLIGHT_Hexacopter_V2_DW.obj_ml.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_ml.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter18'

  // Terminate for MATLABSystem: '<S5>/Read Parameter19'
  if (!FLIGHT_Hexacopter_V2_DW.obj_mc.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_mc.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter19'

  // Terminate for MATLABSystem: '<S5>/Read Parameter8'
  if (!FLIGHT_Hexacopter_V2_DW.obj_f.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter8'

  // Terminate for MATLABSystem: '<S5>/read_mc_rollrate_p'
  if (!FLIGHT_Hexacopter_V2_DW.obj.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/read_mc_rollrate_p'
}

//
// File trailer for generated code.
//
// [EOF]
//
