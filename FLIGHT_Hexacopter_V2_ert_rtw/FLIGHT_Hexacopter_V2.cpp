//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_Hexacopter_V2.cpp
//
// Code generated for Simulink model 'FLIGHT_Hexacopter_V2'.
//
// Model version                  : 3.5
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Aug  6 11:25:39 2025
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
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"

const real_T FLIGHT_Hexacopter_V2_period = 0.004;

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
static void FLIGHT_Hexacopter_V2_xzlascl_k(real32_T cfrom, real32_T cto, int32_T
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
  eventFlags[1] = ((boolean_T)FLIGHT_Hexacopter_V2_M->StepTask(1));
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
  // Start for MATLABSystem: '<S3>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_Hexacop_PX4Timestamp(B_PX4Timestamp_FLIGHT_Hexacop_T *localB)
{
  // MATLABSystem: '<S3>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void FLIGHT_He_PX4Timestamp_Term(DW_PX4Timestamp_FLIGHT_Hexaco_T *localDW)
{
  // Terminate for MATLABSystem: '<S3>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/PX4 Timestamp'
}

// System initialize for atomic system:
void FLIGHT__PX4Timestamp_o_Init(DW_PX4Timestamp_FLIGHT_Hexa_o_T *localDW)
{
  // Start for MATLABSystem: '<S24>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_Hexac_PX4Timestamp_c(B_PX4Timestamp_FLIGHT_Hexac_a_T *localB)
{
  // MATLABSystem: '<S24>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void FLIGHT__PX4Timestamp_p_Term(DW_PX4Timestamp_FLIGHT_Hexa_o_T *localDW)
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
void FLIGHT_Hex_SourceBlock_Init(DW_SourceBlock_FLIGHT_Hexacop_T *localDW)
{
  // Start for MATLABSystem: '<S226>/SourceBlock'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.orbMetadataObj = ORB_ID(actuator_armed);
  uORB_read_initialize(localDW->obj.orbMetadataObj, &localDW->obj.eventStructObj);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_Hexacopt_SourceBlock(B_SourceBlock_FLIGHT_Hexacopt_T *localB,
  DW_SourceBlock_FLIGHT_Hexacop_T *localDW)
{
  // MATLABSystem: '<S226>/SourceBlock'
  localB->SourceBlock_o1 = uORB_read_step(localDW->obj.orbMetadataObj,
    &localDW->obj.eventStructObj, &localB->SourceBlock_o2, false, 1.0);
}

// Termination for atomic system:
void FLIGHT_Hex_SourceBlock_Term(DW_SourceBlock_FLIGHT_Hexacop_T *localDW)
{
  // Terminate for MATLABSystem: '<S226>/SourceBlock'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uORB_read_terminate(&localDW->obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S226>/SourceBlock'
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
static void FLIGHT_Hexacopter_V2_xzlascl_k(real32_T cfrom, real32_T cto, int32_T
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
    FLIGHT_Hexacopter_V2_xzlascl_k(absxk, FLIGHT_Hexacopter_V2_B.anrm, 1, 1, s);
  }

  *V = 1.0F;
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
  uint16_T u0;
  boolean_T b_varargout_1;
  boolean_T rtb_Compare_n;
  boolean_T tmp;

  {                                    // Sample time: [0.001s, 0.0s]
    rate_monotonic_scheduler();
  }

  // RateTransition: '<S10>/Rate Transition4' incorporates:
  //   RateTransition generated from: '<Root>/Rate Transition'
  //   RateTransition generated from: '<Root>/Rate Transition2'
  //   RateTransition: '<S10>/Rate Transition'
  //   RateTransition: '<S364>/Rate Transition'
  //   RateTransition: '<S364>/Rate Transition1'
  //   RateTransition: '<S364>/Rate Transition2'
  //   RateTransition: '<S364>/Rate Transition3'
  //   RateTransition: '<S364>/Rate Transition6'
  //   RateTransition: '<S365>/Rate Transition1'
  //   RateTransition: '<S365>/Rate Transition2'
  //   RateTransition: '<S365>/Rate Transition3'
  //   RateTransition: '<S365>/Rate Transition6'
  //   RateTransition: '<S366>/Rate Transition1'
  //   RateTransition: '<S366>/Rate Transition2'
  //   RateTransition: '<S366>/Rate Transition3'
  //   RateTransition: '<S366>/Rate Transition6'
  //   RateTransition: '<S9>/Rate Transition1'
  //   RateTransition: '<S9>/Rate Transition15'
  //   RateTransition: '<S9>/Rate Transition16'
  //   RateTransition: '<S9>/Rate Transition17'
  //   RateTransition: '<S9>/Rate Transition4'

  tmp = FLIGHT_Hexacopter_V2_M->Timing.RateInteraction.TID0_1;
  if (tmp) {
    // RateTransition: '<S10>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4 =
      FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0;

    // RateTransition: '<S365>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.RateTransition =
      FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0;

    // RateTransition: '<S365>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4_a =
      FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_e;
  }

  // End of RateTransition: '<S10>/Rate Transition4'

  // MATLABSystem: '<S223>/SourceBlock'
  b_varargout_1 = uORB_read_step(FLIGHT_Hexacopter_V2_DW.obj_m.orbMetadataObj,
    &FLIGHT_Hexacopter_V2_DW.obj_m.eventStructObj, &FLIGHT_Hexacopter_V2_B.r4,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S223>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S224>/Enable'

  // Start for MATLABSystem: '<S223>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S224>/In1'
    FLIGHT_Hexacopter_V2_B.In1_k = FLIGHT_Hexacopter_V2_B.r4;
  }

  // End of Outputs for SubSystem: '<S223>/Enabled Subsystem'

  // Sum: '<S365>/Sum1'
  FLIGHT_Hexacopter_V2_B.roll = FLIGHT_Hexacopter_V2_B.RateTransition4_a -
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[0];

  // RateTransition: '<S365>/Rate Transition6' incorporates:
  //   RateTransition: '<S365>/Rate Transition2'

  if (tmp) {
    // RateTransition: '<S365>/Rate Transition6'
    FLIGHT_Hexacopter_V2_B.RateTransition6_h =
      FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_a;

    // RateTransition: '<S365>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.RateTransition2 =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0;
  }

  // DiscreteIntegrator: '<S569>/Integrator'
  if ((FLIGHT_Hexacopter_V2_B.RateTransition6_h &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState <= 0)) ||
      ((!FLIGHT_Hexacopter_V2_B.RateTransition6_h) &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState == 1))) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCondit;
  }

  // Sum: '<S533>/Sum' incorporates:
  //   UnitDelay: '<S533>/Unit Delay1'

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE += FLIGHT_Hexacopter_V2_B.In1_k.xyz
    [0];

  // RateTransition: '<S365>/Rate Transition3' incorporates:
  //   RateTransition generated from: '<Root>/Rate Transition'
  //   RateTransition: '<S9>/Rate Transition1'
  //   RateTransition: '<S9>/Rate Transition15'
  //   RateTransition: '<S9>/Rate Transition16'
  //   RateTransition: '<S9>/Rate Transition17'
  //   RateTransition: '<S9>/Rate Transition2'
  //   RateTransition: '<S9>/Rate Transition4'

  if (tmp) {
    // RateTransition: '<S365>/Rate Transition3'
    FLIGHT_Hexacopter_V2_B.RateTransition3 =
      FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0;

    // RateTransition generated from: '<Root>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.rc_ctrl_switch =
      FLIGHT_Hexacopter_V2_DW.RateTransition_8_Buffer0;

    // RateTransition: '<S9>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.RateTransition2_a[0] =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[0];
    FLIGHT_Hexacopter_V2_B.RateTransition2_a[1] =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[1];
    FLIGHT_Hexacopter_V2_B.RateTransition2_a[2] =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[2];

    // RateTransition: '<S9>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4_l =
      FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_d;

    // RateTransition: '<S9>/Rate Transition5'
    FLIGHT_Hexacopter_V2_B.RateTransition5 =
      FLIGHT_Hexacopter_V2_DW.RateTransition5_Buffer0;

    // RateTransition: '<S9>/Rate Transition6'
    FLIGHT_Hexacopter_V2_B.RateTransition6 =
      FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0;

    // RateTransition: '<S9>/Rate Transition9'
    FLIGHT_Hexacopter_V2_B.RateTransition9 =
      FLIGHT_Hexacopter_V2_DW.RateTransition9_Buffer0;

    // RateTransition: '<S9>/Rate Transition10'
    FLIGHT_Hexacopter_V2_B.RateTransition10 =
      FLIGHT_Hexacopter_V2_DW.RateTransition10_Buffer0;

    // RateTransition: '<S9>/Rate Transition11'
    FLIGHT_Hexacopter_V2_B.RateTransition11 =
      FLIGHT_Hexacopter_V2_DW.RateTransition11_Buffer0;

    // RateTransition: '<S9>/Rate Transition17'
    FLIGHT_Hexacopter_V2_B.RateTransition17 =
      FLIGHT_Hexacopter_V2_DW.RateTransition17_Buffer0;

    // RateTransition: '<S9>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1 =
      FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0;

    // RateTransition: '<S9>/Rate Transition16'
    FLIGHT_Hexacopter_V2_B.RateTransition16 =
      FLIGHT_Hexacopter_V2_DW.RateTransition16_Buffer0;

    // RateTransition: '<S9>/Rate Transition7'
    FLIGHT_Hexacopter_V2_B.RateTransition7 =
      FLIGHT_Hexacopter_V2_DW.RateTransition7_Buffer0;

    // RateTransition: '<S9>/Rate Transition8'
    FLIGHT_Hexacopter_V2_B.RateTransition8 =
      FLIGHT_Hexacopter_V2_DW.RateTransition8_Buffer0;

    // RateTransition: '<S9>/Rate Transition12'
    FLIGHT_Hexacopter_V2_B.RateTransition12 =
      FLIGHT_Hexacopter_V2_DW.RateTransition12_Buffer0;

    // RateTransition: '<S9>/Rate Transition13'
    FLIGHT_Hexacopter_V2_B.RateTransition13 =
      FLIGHT_Hexacopter_V2_DW.RateTransition13_Buffer0;

    // RateTransition: '<S9>/Rate Transition14'
    FLIGHT_Hexacopter_V2_B.RateTransition14 =
      FLIGHT_Hexacopter_V2_DW.RateTransition14_Buffer0;

    // RateTransition: '<S9>/Rate Transition15'
    FLIGHT_Hexacopter_V2_B.RateTransition15 =
      FLIGHT_Hexacopter_V2_DW.RateTransition15_Buffer0;
  }

  // Gain: '<S533>/tau'
  FLIGHT_Hexacopter_V2_B.p = FLIGHT_Hexacopter_V2_P.tau_Gain *
    FLIGHT_Hexacopter_V2_B.RateTransition3;

  // Product: '<S534>/Product2'
  FLIGHT_Hexacopter_V2_B.q = FLIGHT_Hexacopter_V2_B.p * FLIGHT_Hexacopter_V2_B.p;

  // Bias: '<S534>/Bias'
  FLIGHT_Hexacopter_V2_B.r_c = FLIGHT_Hexacopter_V2_B.q +
    FLIGHT_Hexacopter_V2_P.Bias_Bias;

  // Gain: '<S534>/Gain'
  FLIGHT_Hexacopter_V2_B.p *= FLIGHT_Hexacopter_V2_P.Gain_Gain_f5;

  // Sum: '<S534>/Add1'
  FLIGHT_Hexacopter_V2_B.d_b = FLIGHT_Hexacopter_V2_B.r_c +
    FLIGHT_Hexacopter_V2_B.p;

  // SampleTimeMath: '<S530>/TSamp' incorporates:
  //   Product: '<S533>/Product1'
  //   Product: '<S534>/Product3'
  //   UnitDelay: '<S533>/Unit Delay1'
  //
  //  About '<S530>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.TSamp = FLIGHT_Hexacopter_V2_B.q /
    FLIGHT_Hexacopter_V2_B.d_b * FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt;

  // Sum: '<S365>/Sum5' incorporates:
  //   DiscreteIntegrator: '<S569>/Integrator'
  //   Product: '<S365>/Product2'
  //   Product: '<S574>/PProd Out'
  //   Sum: '<S530>/Diff'
  //   Sum: '<S578>/Sum'
  //   UnitDelay: '<S530>/UD'
  //
  //  Block description for '<S530>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S530>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_B.Sum5_nz = (FLIGHT_Hexacopter_V2_B.roll *
    FLIGHT_Hexacopter_V2_B.RateTransition +
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE) - (FLIGHT_Hexacopter_V2_B.TSamp -
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE) * FLIGHT_Hexacopter_V2_B.RateTransition2;

  // MATLAB Function: '<S9>/Omega_phi'
  FLIGHT_Hexacopter_V2_B.rtb_omega_phi_idx_1 = static_cast<real32_T>(sin(
    static_cast<real_T>(FLIGHT_Hexacopter_V2_B.RateTransition2_a[2]))) *
    static_cast<real32_T>(tan(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition2_a[1])));
  FLIGHT_Hexacopter_V2_B.rtb_omega_phi_idx_2 = static_cast<real32_T>(cos(
    static_cast<real_T>(FLIGHT_Hexacopter_V2_B.RateTransition2_a[2]))) *
    static_cast<real32_T>(tan(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition2_a[1])));

  // Sum: '<S243>/Diff' incorporates:
  //   SampleTimeMath: '<S243>/TSamp'
  //   UnitDelay: '<S243>/UD'
  //
  //  About '<S243>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //    *
  //  Block description for '<S243>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S243>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[0] = FLIGHT_Hexacopter_V2_P.TSamp_WtEt_m -
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[0];

  // SampleTimeMath: '<S243>/TSamp'
  //
  //  About '<S243>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.rtb_TSamp_o_p =
    FLIGHT_Hexacopter_V2_B.rtb_omega_phi_idx_1 *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_m;
  FLIGHT_Hexacopter_V2_B.rtb_TSamp_o_idx_1 =
    FLIGHT_Hexacopter_V2_B.rtb_TSamp_o_p;

  // Sum: '<S243>/Diff' incorporates:
  //   SampleTimeMath: '<S243>/TSamp'
  //   UnitDelay: '<S243>/UD'
  //
  //  About '<S243>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //    *
  //  Block description for '<S243>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S243>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[1] = FLIGHT_Hexacopter_V2_B.rtb_TSamp_o_p
    - FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[1];

  // SampleTimeMath: '<S243>/TSamp'
  //
  //  About '<S243>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.rtb_TSamp_o_p =
    FLIGHT_Hexacopter_V2_B.rtb_omega_phi_idx_2 *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_m;

  // Sum: '<S243>/Diff' incorporates:
  //   SampleTimeMath: '<S243>/TSamp'
  //   UnitDelay: '<S243>/UD'
  //
  //  About '<S243>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //    *
  //  Block description for '<S243>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S243>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[2] = FLIGHT_Hexacopter_V2_B.rtb_TSamp_o_p
    - FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[2];

  // Product: '<S238>/Product' incorporates:
  //   Product: '<S238>/Divide'
  //   Product: '<S238>/Product1'
  //   Sum: '<S238>/Add'

  FLIGHT_Hexacopter_V2_B.Product_p = (FLIGHT_Hexacopter_V2_B.RateTransition10 -
    FLIGHT_Hexacopter_V2_B.RateTransition11) /
    FLIGHT_Hexacopter_V2_B.RateTransition9 * (FLIGHT_Hexacopter_V2_B.In1_k.xyz[1]
    * FLIGHT_Hexacopter_V2_B.In1_k.xyz[2]);

  // Product: '<S238>/Product2' incorporates:
  //   Product: '<S238>/Divide1'
  //   Product: '<S238>/Product3'
  //   Sum: '<S238>/Add1'

  FLIGHT_Hexacopter_V2_B.Product2_m = (FLIGHT_Hexacopter_V2_B.RateTransition11 -
    FLIGHT_Hexacopter_V2_B.RateTransition9) /
    FLIGHT_Hexacopter_V2_B.RateTransition10 * (FLIGHT_Hexacopter_V2_B.In1_k.xyz
    [0] * FLIGHT_Hexacopter_V2_B.In1_k.xyz[2]);

  // Product: '<S238>/Product4' incorporates:
  //   Product: '<S238>/Divide2'
  //   Product: '<S238>/Product5'
  //   Sum: '<S238>/Add2'

  FLIGHT_Hexacopter_V2_B.Product4 = (FLIGHT_Hexacopter_V2_B.RateTransition9 -
    FLIGHT_Hexacopter_V2_B.RateTransition10) /
    FLIGHT_Hexacopter_V2_B.RateTransition11 * (FLIGHT_Hexacopter_V2_B.In1_k.xyz
    [0] * FLIGHT_Hexacopter_V2_B.In1_k.xyz[1]);

  // Gain: '<S357>/tau'
  FLIGHT_Hexacopter_V2_B.Product2_gt = FLIGHT_Hexacopter_V2_P.tau_Gain_f *
    FLIGHT_Hexacopter_V2_B.RateTransition17;

  // Product: '<S358>/Product2' incorporates:
  //   Bias: '<S358>/Bias'

  FLIGHT_Hexacopter_V2_B.Product2_gt *= 1.0F /
    (FLIGHT_Hexacopter_V2_B.Product2_gt + FLIGHT_Hexacopter_V2_P.Bias_Bias_h);

  // Sum: '<S357>/Sum' incorporates:
  //   UnitDelay: '<S357>/Unit Delay'

  FLIGHT_Hexacopter_V2_B.Sum_oj = FLIGHT_Hexacopter_V2_B.RateTransition1 +
    FLIGHT_Hexacopter_V2_DW.UnitDelay_DSTATE;

  // Product: '<S357>/Product1'
  FLIGHT_Hexacopter_V2_B.Product1 = FLIGHT_Hexacopter_V2_B.Product2_gt *
    FLIGHT_Hexacopter_V2_B.Sum_oj;

  // SampleTimeMath: '<S241>/TSamp'
  //
  //  About '<S241>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.TSamp_oi = FLIGHT_Hexacopter_V2_B.Product1 *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_p;

  // Sum: '<S241>/Diff' incorporates:
  //   UnitDelay: '<S241>/UD'
  //
  //  Block description for '<S241>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S241>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_B.Diff_k = FLIGHT_Hexacopter_V2_B.TSamp_oi -
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_o;

  // SampleTimeMath: '<S242>/TSamp'
  //
  //  About '<S242>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.TSamp_d = FLIGHT_Hexacopter_V2_B.Diff_k *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_l;

  // Sum: '<S9>/Subtract'
  FLIGHT_Hexacopter_V2_B.Subtract = FLIGHT_Hexacopter_V2_B.RateTransition2_a[2]
    - FLIGHT_Hexacopter_V2_B.Product1;

  // MATLAB Function: '<S9>/MATLAB Function' incorporates:
  //   SignalConversion generated from: '<S247>/ SFunction '
  //   Sum: '<S243>/Diff'
  //
  //  Block description for '<S243>/Diff':
  //
  //   Add in CPU

  FLIGHT_Hexacopter_V2_B.H = ((((FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[0] *
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[0] + FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[1]
    * FLIGHT_Hexacopter_V2_B.In1_k.xyz[1]) +
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[2] * FLIGHT_Hexacopter_V2_B.In1_k.xyz[2])
    + ((FLIGHT_Hexacopter_V2_B.rtb_omega_phi_idx_1 *
        FLIGHT_Hexacopter_V2_B.Product2_m + FLIGHT_Hexacopter_V2_B.Product_p) +
       FLIGHT_Hexacopter_V2_B.rtb_omega_phi_idx_2 *
       FLIGHT_Hexacopter_V2_B.Product4)) *
    FLIGHT_Hexacopter_V2_B.RateTransition6 +
    (((FLIGHT_Hexacopter_V2_B.rtb_omega_phi_idx_1 *
       FLIGHT_Hexacopter_V2_B.In1_k.xyz[1] + FLIGHT_Hexacopter_V2_B.In1_k.xyz[0])
      + FLIGHT_Hexacopter_V2_B.rtb_omega_phi_idx_2 *
      FLIGHT_Hexacopter_V2_B.In1_k.xyz[2]) - FLIGHT_Hexacopter_V2_B.Diff_k) *
    FLIGHT_Hexacopter_V2_B.RateTransition4_l) +
    FLIGHT_Hexacopter_V2_B.RateTransition5 * FLIGHT_Hexacopter_V2_B.Subtract;

  // Gain: '<S290>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S282>/Filter'
  //   Gain: '<S280>/Derivative Gain'
  //   Sum: '<S282>/SumD'

  FLIGHT_Hexacopter_V2_B.FilterCoefficient =
    (FLIGHT_Hexacopter_V2_P.DiscretePIDController1_D *
     FLIGHT_Hexacopter_V2_B.Subtract - FLIGHT_Hexacopter_V2_DW.Filter_DSTATE) *
    FLIGHT_Hexacopter_V2_P.DiscretePIDController1_N;

  // Sum: '<S296>/Sum' incorporates:
  //   Gain: '<S292>/Proportional Gain'

  FLIGHT_Hexacopter_V2_B.Sum_n = FLIGHT_Hexacopter_V2_P.DiscretePIDController1_P
    * FLIGHT_Hexacopter_V2_B.Subtract + FLIGHT_Hexacopter_V2_B.FilterCoefficient;

  // DiscreteIntegrator: '<S339>/Integrator'
  if ((FLIGHT_Hexacopter_V2_B.RateTransition15 &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_h <= 0)) ||
      ((!FLIGHT_Hexacopter_V2_B.RateTransition15) &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_h == 1))) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_h =
      FLIGHT_Hexacopter_V2_P.DiscretePIDController2_InitialC;
  }

  // MATLAB Function: '<S9>/MATLAB Function3' incorporates:
  //   DiscreteIntegrator: '<S339>/Integrator'

  FLIGHT_Hexacopter_V2_B.s = (FLIGHT_Hexacopter_V2_B.RateTransition6 *
    FLIGHT_Hexacopter_V2_B.Sum_n + FLIGHT_Hexacopter_V2_B.RateTransition4_l *
    FLIGHT_Hexacopter_V2_B.Subtract) + FLIGHT_Hexacopter_V2_B.RateTransition5 *
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_h;

  // DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
  if ((FLIGHT_Hexacopter_V2_B.RateTransition15 &&
       (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRese <= 0)) ||
      ((!FLIGHT_Hexacopter_V2_B.RateTransition15) &&
       (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRese == 1))) {
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE =
      FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_IC;
  }

  // MATLAB Function: '<S9>/MATLAB Function4'
  FLIGHT_Hexacopter_V2_B.roll_h = static_cast<real32_T>(fabs(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.s)));
  FLIGHT_Hexacopter_V2_B.R = FLIGHT_Hexacopter_V2_B.s /
    (FLIGHT_Hexacopter_V2_B.roll_h + FLIGHT_Hexacopter_V2_B.RateTransition12) *
    -FLIGHT_Hexacopter_V2_B.RateTransition7 -
    FLIGHT_Hexacopter_V2_B.RateTransition8 * FLIGHT_Hexacopter_V2_B.s;

  // S-Function (sdspdiag2): '<S238>/Create Diagonal Matrix' incorporates:
  //   Constant: '<S238>/Constant'
  //   Product: '<S238>/Divide3'

  memset(&FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[0], 0, 9U * sizeof(real_T));
  FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[0] =
    FLIGHT_Hexacopter_V2_P.Constant_Value_gr /
    FLIGHT_Hexacopter_V2_B.RateTransition9;

  // MATLAB Function: '<S9>/MATLAB Function1'
  FLIGHT_Hexacopter_V2_B.G1[0] = 0.0F;

  // S-Function (sdspdiag2): '<S238>/Create Diagonal Matrix' incorporates:
  //   Constant: '<S238>/Constant1'
  //   Product: '<S238>/Divide4'

  FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[4] =
    FLIGHT_Hexacopter_V2_P.Constant1_Value_f /
    FLIGHT_Hexacopter_V2_B.RateTransition10;

  // MATLAB Function: '<S9>/MATLAB Function1'
  FLIGHT_Hexacopter_V2_B.G1[1] = 0.0F;

  // S-Function (sdspdiag2): '<S238>/Create Diagonal Matrix' incorporates:
  //   Constant: '<S238>/Constant2'
  //   Product: '<S238>/Divide5'

  FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[8] =
    FLIGHT_Hexacopter_V2_P.Constant2_Value_n /
    FLIGHT_Hexacopter_V2_B.RateTransition11;

  // MATLAB Function: '<S9>/MATLAB Function1'
  FLIGHT_Hexacopter_V2_B.G1[2] = 0.0F;

  // MATLAB Function: '<S9>/MATLAB Function2'
  b_varargout_1 = true;
  for (FLIGHT_Hexacopter_V2_B.i = 0; FLIGHT_Hexacopter_V2_B.i < 3;
       FLIGHT_Hexacopter_V2_B.i++) {
    // MATLAB Function: '<S9>/MATLAB Function1' incorporates:
    //   DataTypeConversion: '<S238>/Data Type Conversion1'
    //   S-Function (sdspdiag2): '<S238>/Create Diagonal Matrix'

    FLIGHT_Hexacopter_V2_B.V = ((static_cast<real32_T>
      (FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[3 * FLIGHT_Hexacopter_V2_B.i])
      * FLIGHT_Hexacopter_V2_B.RateTransition6 +
      FLIGHT_Hexacopter_V2_B.G1[FLIGHT_Hexacopter_V2_B.i]) +
      static_cast<real32_T>(FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[3 *
      FLIGHT_Hexacopter_V2_B.i + 1]) * (FLIGHT_Hexacopter_V2_B.RateTransition6 *
      FLIGHT_Hexacopter_V2_B.rtb_omega_phi_idx_1)) + static_cast<real32_T>
      (FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[3 * FLIGHT_Hexacopter_V2_B.i
       + 2]) * (FLIGHT_Hexacopter_V2_B.RateTransition6 *
                FLIGHT_Hexacopter_V2_B.rtb_omega_phi_idx_2);
    FLIGHT_Hexacopter_V2_B.G1[FLIGHT_Hexacopter_V2_B.i] =
      FLIGHT_Hexacopter_V2_B.V;

    // MATLAB Function: '<S9>/MATLAB Function2' incorporates:
    //   MATLAB Function: '<S9>/MATLAB Function1'

    FLIGHT_Hexacopter_V2_B.G1_inv[FLIGHT_Hexacopter_V2_B.i] = 0.0F;
    if (b_varargout_1 && (rtIsInfF(FLIGHT_Hexacopter_V2_B.V) || rtIsNaNF
                          (FLIGHT_Hexacopter_V2_B.V))) {
      b_varargout_1 = false;
    }
  }

  // MATLAB Function: '<S9>/MATLAB Function2'
  if (!b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.G1_inv[0] = (rtNaNF);
    FLIGHT_Hexacopter_V2_B.G1_inv[1] = (rtNaNF);
    FLIGHT_Hexacopter_V2_B.G1_inv[2] = (rtNaNF);
  } else {
    FLIGHT_Hexacopter_V2_svd(FLIGHT_Hexacopter_V2_B.G1, FLIGHT_Hexacopter_V2_B.U,
      &FLIGHT_Hexacopter_V2_B.TSamp_c, &FLIGHT_Hexacopter_V2_B.V);
    FLIGHT_Hexacopter_V2_B.absx = static_cast<real32_T>(fabs(static_cast<real_T>
      (FLIGHT_Hexacopter_V2_B.TSamp_c)));
    if (rtIsInfF(FLIGHT_Hexacopter_V2_B.absx) || rtIsNaNF
        (FLIGHT_Hexacopter_V2_B.absx)) {
      FLIGHT_Hexacopter_V2_B.absx = (rtNaNF);
    } else if (FLIGHT_Hexacopter_V2_B.absx < 2.3509887E-38F) {
      FLIGHT_Hexacopter_V2_B.absx = 1.4013E-45F;
    } else {
      frexp(static_cast<real_T>(FLIGHT_Hexacopter_V2_B.absx),
            &FLIGHT_Hexacopter_V2_B.ParamStep_f);
      FLIGHT_Hexacopter_V2_B.absx = static_cast<real32_T>(ldexp(1.0,
        FLIGHT_Hexacopter_V2_B.ParamStep_f - 24));
    }

    FLIGHT_Hexacopter_V2_B.absx *= 3.0F;
    if (rtIsInfF(FLIGHT_Hexacopter_V2_B.TSamp_c) || rtIsNaNF
        (FLIGHT_Hexacopter_V2_B.TSamp_c)) {
      FLIGHT_Hexacopter_V2_B.absx = 3.402823466E+38F;
    }

    FLIGHT_Hexacopter_V2_B.i = 0;
    if (FLIGHT_Hexacopter_V2_B.TSamp_c > FLIGHT_Hexacopter_V2_B.absx) {
      FLIGHT_Hexacopter_V2_B.i = 1;
    }

    if (FLIGHT_Hexacopter_V2_B.i > 0) {
      FLIGHT_Hexacopter_V2_B.TSamp_c = 1.0F / FLIGHT_Hexacopter_V2_B.TSamp_c;
      for (FLIGHT_Hexacopter_V2_B.i = 1; FLIGHT_Hexacopter_V2_B.i < 2;
           FLIGHT_Hexacopter_V2_B.i++) {
        FLIGHT_Hexacopter_V2_B.V *= FLIGHT_Hexacopter_V2_B.TSamp_c;
      }

      FLIGHT_Hexacopter_V2_B.i = 0;
      for (FLIGHT_Hexacopter_V2_B.ParamStep_f = 0;
           FLIGHT_Hexacopter_V2_B.ParamStep_f < 3;
           FLIGHT_Hexacopter_V2_B.ParamStep_f++) {
        for (FLIGHT_Hexacopter_V2_B.ParamStep_g =
             FLIGHT_Hexacopter_V2_B.ParamStep_f + 1;
             FLIGHT_Hexacopter_V2_B.ParamStep_g <=
             FLIGHT_Hexacopter_V2_B.ParamStep_f + 1;
             FLIGHT_Hexacopter_V2_B.ParamStep_g++) {
          FLIGHT_Hexacopter_V2_B.G1_inv[FLIGHT_Hexacopter_V2_B.ParamStep_g - 1] =
            0.0F;
        }
      }

      for (FLIGHT_Hexacopter_V2_B.ParamStep_f = 0;
           FLIGHT_Hexacopter_V2_B.ParamStep_f < 3;
           FLIGHT_Hexacopter_V2_B.ParamStep_f++) {
        FLIGHT_Hexacopter_V2_B.i++;
        for (FLIGHT_Hexacopter_V2_B.ParamStep_g = FLIGHT_Hexacopter_V2_B.i;
             FLIGHT_Hexacopter_V2_B.ParamStep_g <= FLIGHT_Hexacopter_V2_B.i;
             FLIGHT_Hexacopter_V2_B.ParamStep_g += 3) {
          for (FLIGHT_Hexacopter_V2_B.ParamStep_g1 =
               FLIGHT_Hexacopter_V2_B.ParamStep_f + 1;
               FLIGHT_Hexacopter_V2_B.ParamStep_g1 <=
               FLIGHT_Hexacopter_V2_B.ParamStep_f + 1;
               FLIGHT_Hexacopter_V2_B.ParamStep_g1++) {
            FLIGHT_Hexacopter_V2_B.G1_inv[FLIGHT_Hexacopter_V2_B.ParamStep_g1 -
              1] += FLIGHT_Hexacopter_V2_B.U[FLIGHT_Hexacopter_V2_B.ParamStep_g
              - 1] * FLIGHT_Hexacopter_V2_B.V;
          }
        }
      }
    }
  }

  // MATLAB Function: '<S9>/MATLAB Function4'
  if (rtIsNaNF(FLIGHT_Hexacopter_V2_B.s)) {
    FLIGHT_Hexacopter_V2_B.V = (rtNaNF);
  } else if (FLIGHT_Hexacopter_V2_B.s < 0.0F) {
    FLIGHT_Hexacopter_V2_B.V = -1.0F;
  } else {
    FLIGHT_Hexacopter_V2_B.V = (FLIGHT_Hexacopter_V2_B.s > 0.0F);
  }

  // Switch: '<S9>/Switch' incorporates:
  //   DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
  //   MATLAB Function: '<S9>/MATLAB Function4'

  if (FLIGHT_Hexacopter_V2_B.RateTransition16) {
    FLIGHT_Hexacopter_V2_B.f = -FLIGHT_Hexacopter_V2_B.RateTransition13 *
      static_cast<real32_T>(sqrt(static_cast<real_T>
      (FLIGHT_Hexacopter_V2_B.roll_h))) * FLIGHT_Hexacopter_V2_B.V -
      FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE;
  } else {
    FLIGHT_Hexacopter_V2_B.f = FLIGHT_Hexacopter_V2_B.R;
  }

  // MATLAB Function: '<S9>/MATLAB Function2' incorporates:
  //   Switch: '<S9>/Switch'

  FLIGHT_Hexacopter_V2_B.Saturation2 = (-FLIGHT_Hexacopter_V2_B.H +
    FLIGHT_Hexacopter_V2_B.f) * FLIGHT_Hexacopter_V2_B.G1_inv[0];

  // Saturate: '<S9>/Saturation2'
  if (FLIGHT_Hexacopter_V2_B.Saturation2 >
      FLIGHT_Hexacopter_V2_P.Saturation2_UpperSat) {
    FLIGHT_Hexacopter_V2_B.Saturation2 =
      FLIGHT_Hexacopter_V2_P.Saturation2_UpperSat;
  } else if (FLIGHT_Hexacopter_V2_B.Saturation2 <
             FLIGHT_Hexacopter_V2_P.Saturation2_LowerSat) {
    FLIGHT_Hexacopter_V2_B.Saturation2 =
      FLIGHT_Hexacopter_V2_P.Saturation2_LowerSat;
  }

  // End of Saturate: '<S9>/Saturation2'

  // Switch: '<S2>/Switch' incorporates:
  //   Constant: '<S11>/Constant'
  //   RelationalOperator: '<S11>/Compare'

  if (FLIGHT_Hexacopter_V2_B.rc_ctrl_switch <=
      FLIGHT_Hexacopter_V2_P.CompareToConstant_const) {
    FLIGHT_Hexacopter_V2_B.Switch_e = FLIGHT_Hexacopter_V2_B.Sum5_nz;
  } else {
    FLIGHT_Hexacopter_V2_B.Switch_e = FLIGHT_Hexacopter_V2_B.Saturation2;
  }

  // End of Switch: '<S2>/Switch'

  // RateTransition: '<S364>/Rate Transition' incorporates:
  //   RateTransition: '<S364>/Rate Transition6'

  if (tmp) {
    // RateTransition: '<S364>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.RateTransition_e =
      FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_c;

    // RateTransition: '<S364>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4_b =
      FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_k;

    // RateTransition: '<S364>/Rate Transition6'
    FLIGHT_Hexacopter_V2_B.RateTransition6_a =
      FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_i;
  }

  // Sum: '<S364>/Sum1'
  FLIGHT_Hexacopter_V2_B.roll_h = FLIGHT_Hexacopter_V2_B.RateTransition4_b -
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[1];

  // DiscreteIntegrator: '<S512>/Integrator'
  if ((FLIGHT_Hexacopter_V2_B.RateTransition6_a &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_hx <= 0)) ||
      ((!FLIGHT_Hexacopter_V2_B.RateTransition6_a) &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_hx == 1))) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_c =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCond_l;
  }

  // RateTransition: '<S364>/Rate Transition2' incorporates:
  //   RateTransition: '<S10>/Rate Transition'
  //   RateTransition: '<S364>/Rate Transition3'
  //   RateTransition: '<S366>/Rate Transition'
  //   RateTransition: '<S366>/Rate Transition6'

  if (tmp) {
    // RateTransition: '<S364>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.RateTransition2_b =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_l;

    // RateTransition: '<S364>/Rate Transition3'
    FLIGHT_Hexacopter_V2_B.RateTransition3_b =
      FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0_p;

    // RateTransition: '<S10>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.RateTransition_j =
      FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_h;

    // RateTransition: '<S10>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1_a =
      FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_g;

    // RateTransition: '<S366>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.RateTransition_f =
      FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_hv;

    // RateTransition: '<S366>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4_ar =
      FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_c;

    // RateTransition: '<S366>/Rate Transition6'
    FLIGHT_Hexacopter_V2_B.RateTransition6_o =
      FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_o;
  }

  // Sum: '<S476>/Sum' incorporates:
  //   UnitDelay: '<S476>/Unit Delay1'

  FLIGHT_Hexacopter_V2_B.Product2_h = FLIGHT_Hexacopter_V2_B.In1_k.xyz[1] +
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_k;

  // Gain: '<S476>/tau'
  FLIGHT_Hexacopter_V2_B.p_e = FLIGHT_Hexacopter_V2_P.tau_Gain_d *
    FLIGHT_Hexacopter_V2_B.RateTransition3_b;

  // Product: '<S477>/Product2'
  FLIGHT_Hexacopter_V2_B.q_e = FLIGHT_Hexacopter_V2_B.p_e *
    FLIGHT_Hexacopter_V2_B.p_e;

  // Bias: '<S477>/Bias'
  FLIGHT_Hexacopter_V2_B.r_a = FLIGHT_Hexacopter_V2_B.q_e +
    FLIGHT_Hexacopter_V2_P.Bias_Bias_o;

  // Gain: '<S477>/Gain'
  FLIGHT_Hexacopter_V2_B.p_e *= FLIGHT_Hexacopter_V2_P.Gain_Gain_bi;

  // Sum: '<S477>/Add1'
  FLIGHT_Hexacopter_V2_B.d_m = FLIGHT_Hexacopter_V2_B.r_a +
    FLIGHT_Hexacopter_V2_B.p_e;

  // SampleTimeMath: '<S473>/TSamp' incorporates:
  //   Product: '<S476>/Product1'
  //   Product: '<S477>/Product3'
  //
  //  About '<S473>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.TSamp_c = FLIGHT_Hexacopter_V2_B.q_e /
    FLIGHT_Hexacopter_V2_B.d_m * FLIGHT_Hexacopter_V2_B.Product2_h *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_g;

  // Sum: '<S364>/Sum5' incorporates:
  //   DiscreteIntegrator: '<S512>/Integrator'
  //   Product: '<S364>/Product2'
  //   Product: '<S517>/PProd Out'
  //   Sum: '<S473>/Diff'
  //   Sum: '<S521>/Sum'
  //   UnitDelay: '<S473>/UD'
  //
  //  Block description for '<S473>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S473>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_B.Sum5 = (FLIGHT_Hexacopter_V2_B.roll_h *
    FLIGHT_Hexacopter_V2_B.RateTransition_e +
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_c) -
    (FLIGHT_Hexacopter_V2_B.TSamp_c - FLIGHT_Hexacopter_V2_DW.UD_DSTATE_oi) *
    FLIGHT_Hexacopter_V2_B.RateTransition2_b;

  // Sum: '<S366>/Sum1'
  FLIGHT_Hexacopter_V2_B.absx = FLIGHT_Hexacopter_V2_B.RateTransition4_ar -
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[2];

  // DiscreteIntegrator: '<S626>/Integrator'
  if ((FLIGHT_Hexacopter_V2_B.RateTransition6_o &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_hd <= 0)) ||
      ((!FLIGHT_Hexacopter_V2_B.RateTransition6_o) &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_hd == 1))) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_o =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCond_p;
  }

  // RateTransition: '<S366>/Rate Transition2' incorporates:
  //   RateTransition: '<S366>/Rate Transition3'

  if (tmp) {
    // RateTransition: '<S366>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.RateTransition2_d =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_dg;

    // RateTransition: '<S366>/Rate Transition3'
    FLIGHT_Hexacopter_V2_B.RateTransition3_e =
      FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0_d;
  }

  // Sum: '<S590>/Sum' incorporates:
  //   UnitDelay: '<S590>/Unit Delay1'

  FLIGHT_Hexacopter_V2_B.Product2_mi = FLIGHT_Hexacopter_V2_B.In1_k.xyz[2] +
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_kh;

  // Gain: '<S590>/tau'
  FLIGHT_Hexacopter_V2_B.p_i = FLIGHT_Hexacopter_V2_P.tau_Gain_m *
    FLIGHT_Hexacopter_V2_B.RateTransition3_e;

  // Product: '<S591>/Product2'
  FLIGHT_Hexacopter_V2_B.q_n = FLIGHT_Hexacopter_V2_B.p_i *
    FLIGHT_Hexacopter_V2_B.p_i;

  // Bias: '<S591>/Bias'
  FLIGHT_Hexacopter_V2_B.r_h = FLIGHT_Hexacopter_V2_B.q_n +
    FLIGHT_Hexacopter_V2_P.Bias_Bias_g;

  // Gain: '<S591>/Gain'
  FLIGHT_Hexacopter_V2_B.p_i *= FLIGHT_Hexacopter_V2_P.Gain_Gain_a;

  // Sum: '<S591>/Add1'
  FLIGHT_Hexacopter_V2_B.d_e = FLIGHT_Hexacopter_V2_B.r_h +
    FLIGHT_Hexacopter_V2_B.p_i;

  // SampleTimeMath: '<S587>/TSamp' incorporates:
  //   Product: '<S590>/Product1'
  //   Product: '<S591>/Product3'
  //
  //  About '<S587>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.TSamp_a = FLIGHT_Hexacopter_V2_B.q_n /
    FLIGHT_Hexacopter_V2_B.d_e * FLIGHT_Hexacopter_V2_B.Product2_mi *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_ma;

  // Sum: '<S10>/Sum' incorporates:
  //   DiscreteIntegrator: '<S626>/Integrator'
  //   Product: '<S10>/yawrate_feedforward'
  //   Product: '<S366>/Product2'
  //   Product: '<S631>/PProd Out'
  //   Sum: '<S366>/Sum5'
  //   Sum: '<S587>/Diff'
  //   Sum: '<S635>/Sum'
  //   UnitDelay: '<S587>/UD'
  //
  //  Block description for '<S587>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S587>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_B.Sum_g = ((FLIGHT_Hexacopter_V2_B.absx *
    FLIGHT_Hexacopter_V2_B.RateTransition_f +
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_o) -
    (FLIGHT_Hexacopter_V2_B.TSamp_a - FLIGHT_Hexacopter_V2_DW.UD_DSTATE_k) *
    FLIGHT_Hexacopter_V2_B.RateTransition2_d) +
    FLIGHT_Hexacopter_V2_B.RateTransition_j *
    FLIGHT_Hexacopter_V2_B.RateTransition1_a;

  // MATLAB Function: '<S14>/pwm_out2'
  FLIGHT_Hexacopter_V2_B.f = rt_roundf_snf(((-FLIGHT_Hexacopter_V2_B.Switch_e -
    FLIGHT_Hexacopter_V2_B.Sum_g) * FLIGHT_Hexacopter_V2_B.RateTransition4 /
    3.0F + FLIGHT_Hexacopter_V2_B.RateTransition4) * 1000.0F);
  if (FLIGHT_Hexacopter_V2_B.f < 65536.0F) {
    if (FLIGHT_Hexacopter_V2_B.f >= 0.0F) {
      u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.f);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  FLIGHT_Hexacopter_V2_B.u5 = u0 + 1000U;
  if (FLIGHT_Hexacopter_V2_B.f < 65536.0F) {
    if (FLIGHT_Hexacopter_V2_B.f >= 0.0F) {
      u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.f);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  if (u0 + 1000U > 65535U) {
    FLIGHT_Hexacopter_V2_B.u5 = 65535U;
  }

  FLIGHT_Hexacopter_V2_B.f = rt_roundf_snf(((FLIGHT_Hexacopter_V2_B.Switch_e +
    FLIGHT_Hexacopter_V2_B.Sum_g) * FLIGHT_Hexacopter_V2_B.RateTransition4 /
    3.0F + FLIGHT_Hexacopter_V2_B.RateTransition4) * 1000.0F);
  if (FLIGHT_Hexacopter_V2_B.f < 65536.0F) {
    if (FLIGHT_Hexacopter_V2_B.f >= 0.0F) {
      u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.f);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  FLIGHT_Hexacopter_V2_B.u4 = u0 + 1000U;
  if (FLIGHT_Hexacopter_V2_B.f < 65536.0F) {
    if (FLIGHT_Hexacopter_V2_B.f >= 0.0F) {
      u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.f);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  if (u0 + 1000U > 65535U) {
    FLIGHT_Hexacopter_V2_B.u4 = 65535U;
  }

  FLIGHT_Hexacopter_V2_B.f = FLIGHT_Hexacopter_V2_B.Switch_e / 2.0F;
  FLIGHT_Hexacopter_V2_B.Switch_e = rt_roundf_snf((((FLIGHT_Hexacopter_V2_B.f +
    FLIGHT_Hexacopter_V2_B.Sum5) - FLIGHT_Hexacopter_V2_B.Sum_g) *
    FLIGHT_Hexacopter_V2_B.RateTransition4 / 3.0F +
    FLIGHT_Hexacopter_V2_B.RateTransition4) * 1000.0F);
  if (FLIGHT_Hexacopter_V2_B.Switch_e < 65536.0F) {
    if (FLIGHT_Hexacopter_V2_B.Switch_e >= 0.0F) {
      u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.Switch_e);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  FLIGHT_Hexacopter_V2_B.u3 = u0 + 1000U;
  if (FLIGHT_Hexacopter_V2_B.Switch_e < 65536.0F) {
    if (FLIGHT_Hexacopter_V2_B.Switch_e >= 0.0F) {
      u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.Switch_e);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  if (u0 + 1000U > 65535U) {
    FLIGHT_Hexacopter_V2_B.u3 = 65535U;
  }

  FLIGHT_Hexacopter_V2_B.Switch_e = rt_roundf_snf
    ((((-FLIGHT_Hexacopter_V2_B.Sum5 - FLIGHT_Hexacopter_V2_B.f) +
       FLIGHT_Hexacopter_V2_B.Sum_g) * FLIGHT_Hexacopter_V2_B.RateTransition4 /
      3.0F + FLIGHT_Hexacopter_V2_B.RateTransition4) * 1000.0F);
  if (FLIGHT_Hexacopter_V2_B.Switch_e < 65536.0F) {
    if (FLIGHT_Hexacopter_V2_B.Switch_e >= 0.0F) {
      u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.Switch_e);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  FLIGHT_Hexacopter_V2_B.u2 = u0 + 1000U;
  if (FLIGHT_Hexacopter_V2_B.Switch_e < 65536.0F) {
    if (FLIGHT_Hexacopter_V2_B.Switch_e >= 0.0F) {
      u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.Switch_e);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  if (u0 + 1000U > 65535U) {
    FLIGHT_Hexacopter_V2_B.u2 = 65535U;
  }

  FLIGHT_Hexacopter_V2_B.Switch_e = rt_roundf_snf((((FLIGHT_Hexacopter_V2_B.Sum5
    - FLIGHT_Hexacopter_V2_B.f) + FLIGHT_Hexacopter_V2_B.Sum_g) *
    FLIGHT_Hexacopter_V2_B.RateTransition4 / 3.0F +
    FLIGHT_Hexacopter_V2_B.RateTransition4) * 1000.0F);
  if (FLIGHT_Hexacopter_V2_B.Switch_e < 65536.0F) {
    if (FLIGHT_Hexacopter_V2_B.Switch_e >= 0.0F) {
      u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.Switch_e);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  FLIGHT_Hexacopter_V2_B.u1 = u0 + 1000U;
  if (FLIGHT_Hexacopter_V2_B.Switch_e < 65536.0F) {
    if (FLIGHT_Hexacopter_V2_B.Switch_e >= 0.0F) {
      u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.Switch_e);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  if (u0 + 1000U > 65535U) {
    FLIGHT_Hexacopter_V2_B.u1 = 65535U;
  }

  FLIGHT_Hexacopter_V2_B.f = rt_roundf_snf((((FLIGHT_Hexacopter_V2_B.f -
    FLIGHT_Hexacopter_V2_B.Sum5) - FLIGHT_Hexacopter_V2_B.Sum_g) *
    FLIGHT_Hexacopter_V2_B.RateTransition4 / 3.0F +
    FLIGHT_Hexacopter_V2_B.RateTransition4) * 1000.0F);
  if (FLIGHT_Hexacopter_V2_B.f < 65536.0F) {
    if (FLIGHT_Hexacopter_V2_B.f >= 0.0F) {
      u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.f);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  FLIGHT_Hexacopter_V2_B.u = u0 + 1000U;
  if (FLIGHT_Hexacopter_V2_B.f < 65536.0F) {
    if (FLIGHT_Hexacopter_V2_B.f >= 0.0F) {
      u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.f);
    } else {
      u0 = 0U;
    }
  } else {
    u0 = MAX_uint16_T;
  }

  if (u0 + 1000U > 65535U) {
    FLIGHT_Hexacopter_V2_B.u = 65535U;
  }

  // MATLABSystem: '<S12>/Read Parameter13'
  b_varargout_1 = MW_ParamRead_Step
    (FLIGHT_Hexacopter_V2_DW.obj_oe.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_Hexacopter_V2_B.i);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.i = 0;
  }

  // RateTransition generated from: '<Root>/Rate Transition'
  if (tmp) {
    // RateTransition generated from: '<Root>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.rc_inject_failure =
      FLIGHT_Hexacopter_V2_DW.RateTransition_4_Buffer0;
  }

  // RelationalOperator: '<S15>/Compare' incorporates:
  //   Constant: '<S15>/Constant'

  rtb_Compare_n = (FLIGHT_Hexacopter_V2_B.rc_inject_failure >=
                   FLIGHT_Hexacopter_V2_P.CompareToConstant_const_a);

  // MATLABSystem: '<S12>/Read Parameter1'
  b_varargout_1 = MW_ParamRead_Step
    (FLIGHT_Hexacopter_V2_DW.obj_aw.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_Hexacopter_V2_B.ParamStep_f);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_f = 0;
  }

  // MATLABSystem: '<S12>/Read Parameter2'
  b_varargout_1 = MW_ParamRead_Step
    (FLIGHT_Hexacopter_V2_DW.obj_ps.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_Hexacopter_V2_B.ParamStep_g);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_g = 0;
  }

  // MATLABSystem: '<S12>/Read Parameter3'
  b_varargout_1 = MW_ParamRead_Step
    (FLIGHT_Hexacopter_V2_DW.obj_hi.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_Hexacopter_V2_B.ParamStep_g1);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_g1 = 0;
  }

  // MATLABSystem: '<S12>/Read Parameter4'
  b_varargout_1 = MW_ParamRead_Step
    (FLIGHT_Hexacopter_V2_DW.obj_jg.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_Hexacopter_V2_B.ParamStep_m);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_m = 0;
  }

  // MATLABSystem: '<S12>/Read Parameter5'
  b_varargout_1 = MW_ParamRead_Step
    (FLIGHT_Hexacopter_V2_DW.obj_ic5.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_Hexacopter_V2_B.ParamStep_n);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_n = 0;
  }

  // Switch: '<S12>/Switch' incorporates:
  //   Constant: '<S12>/Constant'
  //   DataTypeConversion: '<S12>/Data Type Conversion3'
  //   MATLABSystem: '<S12>/Read Parameter13'
  //
  if (rtb_Compare_n) {
    FLIGHT_Hexacopter_V2_B.d = FLIGHT_Hexacopter_V2_B.i;
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
    (FLIGHT_Hexacopter_V2_B.u5)) - FLIGHT_Hexacopter_V2_P.Constant_Value_b) *
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
    FLIGHT_Hexacopter_V2_B.d1 = FLIGHT_Hexacopter_V2_B.ParamStep_f;
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
    (FLIGHT_Hexacopter_V2_B.u4)) - FLIGHT_Hexacopter_V2_P.Constant_Value_lg) *
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
    FLIGHT_Hexacopter_V2_B.d2 = FLIGHT_Hexacopter_V2_B.ParamStep_g;
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
    (FLIGHT_Hexacopter_V2_B.u3)) - FLIGHT_Hexacopter_V2_P.Constant_Value_n) *
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
    FLIGHT_Hexacopter_V2_B.d3 = FLIGHT_Hexacopter_V2_B.ParamStep_g1;
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
    (FLIGHT_Hexacopter_V2_B.u2)) - FLIGHT_Hexacopter_V2_P.Constant_Value_e3) *
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
    FLIGHT_Hexacopter_V2_B.d4 = FLIGHT_Hexacopter_V2_B.ParamStep_m;
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
    (FLIGHT_Hexacopter_V2_B.u1)) - FLIGHT_Hexacopter_V2_P.Constant_Value_d) *
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
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_B.ParamStep_n;
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
    (FLIGHT_Hexacopter_V2_B.u)) - FLIGHT_Hexacopter_V2_P.Constant_Value_lv) *
    FLIGHT_Hexacopter_V2_B.u0 + FLIGHT_Hexacopter_V2_P.Constant_Value_lv);
  if (rtIsNaN(FLIGHT_Hexacopter_V2_B.u0) || rtIsInf(FLIGHT_Hexacopter_V2_B.u0))
  {
    FLIGHT_Hexacopter_V2_B.u0 = 0.0;
  } else {
    FLIGHT_Hexacopter_V2_B.u0 = fmod(FLIGHT_Hexacopter_V2_B.u0, 65536.0);
  }

  // RateTransition generated from: '<Root>/Rate Transition2'
  if (tmp) {
    // RateTransition generated from: '<Root>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.VehicleStatus_flag_armed =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_16_Buffer0;

    // RateTransition generated from: '<Root>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.VehicleStatus_flag_kill =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_17_Buffer0;
  }

  // MATLABSystem: '<S1>/PX4 PWM Output' incorporates:
  //   DataTypeConversion: '<S12>/Data Type Conversion7'

  for (FLIGHT_Hexacopter_V2_B.i = 0; FLIGHT_Hexacopter_V2_B.i < 8;
       FLIGHT_Hexacopter_V2_B.i++) {
    FLIGHT_Hexacopter_V2_B.pwmValue[FLIGHT_Hexacopter_V2_B.i] = 0U;
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
  FLIGHT_Hexacop_PX4Timestamp(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_pn);

  // BusAssignment: '<S28>/Bus Assignment' incorporates:
  //   Constant: '<S37>/Constant'

  FLIGHT_Hexacopter_V2_B.BusAssignment = FLIGHT_Hexacopter_V2_P.Constant_Value_g;

  // BusAssignment: '<S28>/Bus Assignment' incorporates:
  //   DiscreteIntegrator: '<S339>/Integrator'
  //   MATLABSystem: '<S28>/PX4 Timestamp'
  //   Math: '<S28>/Transpose'
  //   Sum: '<S242>/Diff'
  //   Sum: '<S243>/Diff'
  //   UnitDelay: '<S242>/UD'
  //
  //  Block description for '<S242>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S243>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S242>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_B.BusAssignment.timestamp =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp_pn.PX4Timestamp;
  FLIGHT_Hexacopter_V2_B.BusAssignment.tau_roll =
    FLIGHT_Hexacopter_V2_B.Saturation2;
  FLIGHT_Hexacopter_V2_B.BusAssignment.s = FLIGHT_Hexacopter_V2_B.s;
  FLIGHT_Hexacopter_V2_B.BusAssignment.hx = FLIGHT_Hexacopter_V2_B.H;
  FLIGHT_Hexacopter_V2_B.BusAssignment.fx[0] = FLIGHT_Hexacopter_V2_B.Product_p;
  FLIGHT_Hexacopter_V2_B.BusAssignment.fx[1] = FLIGHT_Hexacopter_V2_B.Product2_m;
  FLIGHT_Hexacopter_V2_B.BusAssignment.fx[2] = FLIGHT_Hexacopter_V2_B.Product4;
  FLIGHT_Hexacopter_V2_B.BusAssignment.g1x[0] = FLIGHT_Hexacopter_V2_B.G1_inv[0];
  FLIGHT_Hexacopter_V2_B.BusAssignment.omega[0] = 1.0F;
  FLIGHT_Hexacopter_V2_B.BusAssignment.omega_dot[0] =
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[0];
  FLIGHT_Hexacopter_V2_B.BusAssignment.w[0] = FLIGHT_Hexacopter_V2_B.In1_k.xyz[0];
  FLIGHT_Hexacopter_V2_B.BusAssignment.g1x[1] = FLIGHT_Hexacopter_V2_B.G1_inv[1];
  FLIGHT_Hexacopter_V2_B.BusAssignment.omega[1] =
    FLIGHT_Hexacopter_V2_B.rtb_omega_phi_idx_1;
  FLIGHT_Hexacopter_V2_B.BusAssignment.omega_dot[1] =
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[1];
  FLIGHT_Hexacopter_V2_B.BusAssignment.w[1] = FLIGHT_Hexacopter_V2_B.In1_k.xyz[1];
  FLIGHT_Hexacopter_V2_B.BusAssignment.g1x[2] = FLIGHT_Hexacopter_V2_B.G1_inv[2];
  FLIGHT_Hexacopter_V2_B.BusAssignment.omega[2] =
    FLIGHT_Hexacopter_V2_B.rtb_omega_phi_idx_2;
  FLIGHT_Hexacopter_V2_B.BusAssignment.omega_dot[2] =
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[2];
  FLIGHT_Hexacopter_V2_B.BusAssignment.w[2] = FLIGHT_Hexacopter_V2_B.In1_k.xyz[2];
  FLIGHT_Hexacopter_V2_B.BusAssignment.e = FLIGHT_Hexacopter_V2_B.Subtract;
  FLIGHT_Hexacopter_V2_B.BusAssignment.e_dot = FLIGHT_Hexacopter_V2_B.Sum_n;
  FLIGHT_Hexacopter_V2_B.BusAssignment.integral_e =
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_h;
  FLIGHT_Hexacopter_V2_B.BusAssignment.phi_cmd = FLIGHT_Hexacopter_V2_B.Product1;
  FLIGHT_Hexacopter_V2_B.BusAssignment.phi_cmd_dot =
    FLIGHT_Hexacopter_V2_B.Diff_k;
  FLIGHT_Hexacopter_V2_B.BusAssignment.phi_cmd_ddot =
    FLIGHT_Hexacopter_V2_B.TSamp_d - FLIGHT_Hexacopter_V2_DW.UD_DSTATE_e;
  FLIGHT_Hexacopter_V2_B.BusAssignment.r = FLIGHT_Hexacopter_V2_B.R;

  // MATLABSystem: '<S38>/SinkBlock' incorporates:
  //   BusAssignment: '<S28>/Bus Assignment'

  uORB_write_step(FLIGHT_Hexacopter_V2_DW.obj_k.orbMetadataObj,
                  &FLIGHT_Hexacopter_V2_DW.obj_k.orbAdvertiseObj,
                  &FLIGHT_Hexacopter_V2_B.BusAssignment);
  FLIGHT_Hexac_PX4Timestamp_c(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_e);
  FLIGHT_Hexacop_PX4Timestamp(&FLIGHT_Hexacopter_V2_B.PX4Timestamp);

  // BusAssignment: '<S29>/Bus Assignment' incorporates:
  //   MATLABSystem: '<S29>/PX4 Timestamp'
  //   MATLABSystem: '<S3>/PX4 Timestamp'

  FLIGHT_Hexacopter_V2_B.BusAssignment_e.timestamp =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp_e.PX4Timestamp;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e.timestamp_sample =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp.PX4Timestamp;

  // Saturate: '<S23>/Saturation' incorporates:
  //   MATLAB Function: '<S14>/pwm_out2'

  if (static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u5) >
      FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d;
  } else if (static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u5) <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0;
  } else {
    u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u5);
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

  if (static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u4) >
      FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d;
  } else if (static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u4) <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0;
  } else {
    u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u4);
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

  if (static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u3) >
      FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d;
  } else if (static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u3) <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0;
  } else {
    u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u3);
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

  if (static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u2) >
      FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d;
  } else if (static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u2) <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0;
  } else {
    u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u2);
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

  if (static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u1) >
      FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d;
  } else if (static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u1) <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0;
  } else {
    u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u1);
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

  if (static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u) >
      FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d;
  } else if (static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u) <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0) {
    u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0;
  } else {
    u0 = static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.u);
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
  for (FLIGHT_Hexacopter_V2_B.i = 0; FLIGHT_Hexacopter_V2_B.i < 6;
       FLIGHT_Hexacopter_V2_B.i++) {
    u0 = FLIGHT_Hexacopter_V2_P.Constant4_Value_f[FLIGHT_Hexacopter_V2_B.i];
    if (u0 > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d) {
      u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d;
    } else if (u0 < FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0) {
      u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0;
    }

    FLIGHT_Hexacopter_V2_B.BusAssignment_e.control[FLIGHT_Hexacopter_V2_B.i + 6]
      = (static_cast<real32_T>(u0) - FLIGHT_Hexacopter_V2_P.Constant_Value_ew) *
      FLIGHT_Hexacopter_V2_P.Gain_Gain_h;
    FLIGHT_Hexacopter_V2_B.BusAssignment_e._padding0[FLIGHT_Hexacopter_V2_B.i] =
      0U;
  }

  // MATLABSystem: '<S40>/SinkBlock' incorporates:
  //   BusAssignment: '<S29>/Bus Assignment'

  uORB_write_step(FLIGHT_Hexacopter_V2_DW.obj_nf.orbMetadataObj,
                  &FLIGHT_Hexacopter_V2_DW.obj_nf.orbAdvertiseObj,
                  &FLIGHT_Hexacopter_V2_B.BusAssignment_e);
  FLIGHT_Hexac_PX4Timestamp_c(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_c);

  // BusAssignment: '<S24>/Bus Assignment' incorporates:
  //   MATLABSystem: '<S24>/PX4 Timestamp'

  FLIGHT_Hexacopter_V2_B.BusAssignment_j.timestamp =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp_c.PX4Timestamp;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j.control_power[0] =
    FLIGHT_Hexacopter_V2_B.Sum5_nz;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j.control_power[1] =
    FLIGHT_Hexacopter_V2_B.Sum5;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j.control_power[2] =
    FLIGHT_Hexacopter_V2_B.Sum_g;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j._padding0[0] = 0U;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j._padding0[1] = 0U;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j._padding0[2] = 0U;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j._padding0[3] = 0U;

  // MATLABSystem: '<S32>/SinkBlock' incorporates:
  //   BusAssignment: '<S24>/Bus Assignment'

  uORB_write_step(FLIGHT_Hexacopter_V2_DW.obj_fe.orbMetadataObj,
                  &FLIGHT_Hexacopter_V2_DW.obj_fe.orbAdvertiseObj,
                  &FLIGHT_Hexacopter_V2_B.BusAssignment_j);

  // Sum: '<S590>/Sum1' incorporates:
  //   Bias: '<S591>/Bias1'
  //   Gain: '<S590>/Gain1'
  //   Product: '<S590>/Product5'
  //   Product: '<S591>/Product4'
  //   Sum: '<S590>/Sum2'
  //   UnaryMinus: '<S591>/Unary Minus'
  //   UnitDelay: '<S590>/Unit Delay1'
  //   UnitDelay: '<S590>/Unit Delay2'

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_kh = ((-FLIGHT_Hexacopter_V2_B.q_n +
    FLIGHT_Hexacopter_V2_P.Bias1_Bias) / FLIGHT_Hexacopter_V2_B.d_e *
    FLIGHT_Hexacopter_V2_B.Product2_mi + FLIGHT_Hexacopter_V2_B.In1_k.xyz[2]) *
    FLIGHT_Hexacopter_V2_P.Gain1_Gain_d +
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE;

  // Sum: '<S590>/Sum3' incorporates:
  //   Product: '<S590>/Product2'
  //   Product: '<S591>/Product5'
  //   Sum: '<S591>/Add3'
  //   UnitDelay: '<S590>/Unit Delay2'

  FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE = FLIGHT_Hexacopter_V2_B.In1_k.xyz[2]
    - 1.0F / FLIGHT_Hexacopter_V2_B.d_e * (FLIGHT_Hexacopter_V2_B.r_h -
    FLIGHT_Hexacopter_V2_B.p_i) * FLIGHT_Hexacopter_V2_B.Product2_mi;

  // RateTransition: '<S366>/Rate Transition1' incorporates:
  //   RateTransition: '<S364>/Rate Transition1'
  //   RateTransition: '<S365>/Rate Transition1'

  if (tmp) {
    // RateTransition: '<S366>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1_c =
      FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_m;

    // RateTransition: '<S364>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1_d =
      FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_l;

    // RateTransition: '<S365>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1_o =
      FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_l4;
  }

  // Sum: '<S476>/Sum1' incorporates:
  //   Bias: '<S477>/Bias1'
  //   Gain: '<S476>/Gain1'
  //   Product: '<S476>/Product5'
  //   Product: '<S477>/Product4'
  //   Sum: '<S476>/Sum2'
  //   UnaryMinus: '<S477>/Unary Minus'
  //   UnitDelay: '<S476>/Unit Delay1'
  //   UnitDelay: '<S476>/Unit Delay2'

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_k = ((-FLIGHT_Hexacopter_V2_B.q_e +
    FLIGHT_Hexacopter_V2_P.Bias1_Bias_k) / FLIGHT_Hexacopter_V2_B.d_m *
    FLIGHT_Hexacopter_V2_B.Product2_h + FLIGHT_Hexacopter_V2_B.In1_k.xyz[1]) *
    FLIGHT_Hexacopter_V2_P.Gain1_Gain_m +
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_l;

  // Sum: '<S476>/Sum3' incorporates:
  //   Product: '<S476>/Product2'
  //   Product: '<S477>/Product5'
  //   Sum: '<S477>/Add3'
  //   UnitDelay: '<S476>/Unit Delay2'

  FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_l =
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[1] - 1.0F / FLIGHT_Hexacopter_V2_B.d_m *
    (FLIGHT_Hexacopter_V2_B.r_a - FLIGHT_Hexacopter_V2_B.p_e) *
    FLIGHT_Hexacopter_V2_B.Product2_h;

  // Sum: '<S357>/Sum1' incorporates:
  //   Bias: '<S358>/Bias1'
  //   Gain: '<S358>/Gain'
  //   Product: '<S357>/Product4'
  //   UnitDelay: '<S357>/Unit Delay'

  FLIGHT_Hexacopter_V2_DW.UnitDelay_DSTATE =
    (FLIGHT_Hexacopter_V2_P.Gain_Gain_ar * FLIGHT_Hexacopter_V2_B.Product2_gt +
     FLIGHT_Hexacopter_V2_P.Bias1_Bias_ka) * FLIGHT_Hexacopter_V2_B.Sum_oj +
    FLIGHT_Hexacopter_V2_B.RateTransition1;

  // Sum: '<S533>/Sum1' incorporates:
  //   Bias: '<S534>/Bias1'
  //   Gain: '<S533>/Gain1'
  //   Product: '<S533>/Product5'
  //   Product: '<S534>/Product4'
  //   Sum: '<S533>/Sum2'
  //   UnaryMinus: '<S534>/Unary Minus'
  //   UnitDelay: '<S533>/Unit Delay1'
  //   UnitDelay: '<S533>/Unit Delay2'

  FLIGHT_Hexacopter_V2_B.q = ((-FLIGHT_Hexacopter_V2_B.q +
    FLIGHT_Hexacopter_V2_P.Bias1_Bias_a) / FLIGHT_Hexacopter_V2_B.d_b *
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE +
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[0]) * FLIGHT_Hexacopter_V2_P.Gain1_Gain_i +
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_h;

  // Product: '<S533>/Product2' incorporates:
  //   Product: '<S534>/Product5'
  //   Sum: '<S534>/Add3'
  //   UnitDelay: '<S533>/Unit Delay1'

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE *= 1.0F / FLIGHT_Hexacopter_V2_B.d_b
    * (FLIGHT_Hexacopter_V2_B.r_c - FLIGHT_Hexacopter_V2_B.p);

  // Sum: '<S533>/Sum3' incorporates:
  //   UnitDelay: '<S533>/Unit Delay1'
  //   UnitDelay: '<S533>/Unit Delay2'

  FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_h =
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[0] -
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE;

  // Update for DiscreteIntegrator: '<S569>/Integrator' incorporates:
  //   Product: '<S566>/IProd Out'

  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE += FLIGHT_Hexacopter_V2_B.roll *
    FLIGHT_Hexacopter_V2_B.RateTransition1_o *
    FLIGHT_Hexacopter_V2_P.Integrator_gainval;
  FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState = static_cast<int8_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition6_h);

  // Update for UnitDelay: '<S533>/Unit Delay1'
  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE = FLIGHT_Hexacopter_V2_B.q;

  // Update for UnitDelay: '<S530>/UD'
  //
  //  Block description for '<S530>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE = FLIGHT_Hexacopter_V2_B.TSamp;

  // Update for UnitDelay: '<S243>/UD' incorporates:
  //   SampleTimeMath: '<S243>/TSamp'
  //   Sum: '<S243>/Diff'
  //  *
  //  About '<S243>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //    *
  //  About '<S243>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //    *
  //  Block description for '<S243>/UD':
  //
  //   Store in Global RAM
  //
  //  Block description for '<S243>/Diff':
  //
  //   Add in CPU

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[0] = FLIGHT_Hexacopter_V2_P.TSamp_WtEt_m;
  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[1] =
    FLIGHT_Hexacopter_V2_B.rtb_TSamp_o_idx_1;
  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[2] = FLIGHT_Hexacopter_V2_B.rtb_TSamp_o_p;

  // Update for UnitDelay: '<S241>/UD'
  //
  //  Block description for '<S241>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_o = FLIGHT_Hexacopter_V2_B.TSamp_oi;

  // Update for UnitDelay: '<S242>/UD'
  //
  //  Block description for '<S242>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_e = FLIGHT_Hexacopter_V2_B.TSamp_d;

  // Update for DiscreteIntegrator: '<S282>/Filter'
  FLIGHT_Hexacopter_V2_DW.Filter_DSTATE += FLIGHT_Hexacopter_V2_P.Filter_gainval
    * FLIGHT_Hexacopter_V2_B.FilterCoefficient;

  // Update for DiscreteIntegrator: '<S339>/Integrator' incorporates:
  //   Gain: '<S336>/Integral Gain'

  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_h +=
    FLIGHT_Hexacopter_V2_P.DiscretePIDController2_I *
    FLIGHT_Hexacopter_V2_B.Subtract *
    FLIGHT_Hexacopter_V2_P.Integrator_gainval_c;
  FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_h = static_cast<int8_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition15);

  // Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' incorporates:
  //   MATLAB Function: '<S9>/MATLAB Function4'

  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE +=
    FLIGHT_Hexacopter_V2_B.RateTransition14 * FLIGHT_Hexacopter_V2_B.V *
    FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_gainval;
  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRese = static_cast<int8_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition15);

  // Update for DiscreteIntegrator: '<S512>/Integrator' incorporates:
  //   Product: '<S509>/IProd Out'

  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_c += FLIGHT_Hexacopter_V2_B.roll_h *
    FLIGHT_Hexacopter_V2_B.RateTransition1_d *
    FLIGHT_Hexacopter_V2_P.Integrator_gainval_d;
  FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_hx = static_cast<int8_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition6_a);

  // Update for UnitDelay: '<S473>/UD'
  //
  //  Block description for '<S473>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_oi = FLIGHT_Hexacopter_V2_B.TSamp_c;

  // Update for DiscreteIntegrator: '<S626>/Integrator' incorporates:
  //   Product: '<S623>/IProd Out'

  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_o += FLIGHT_Hexacopter_V2_B.absx *
    FLIGHT_Hexacopter_V2_B.RateTransition1_c *
    FLIGHT_Hexacopter_V2_P.Integrator_gainval_b;
  FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_hd = static_cast<int8_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition6_o);

  // Update for UnitDelay: '<S587>/UD'
  //
  //  Block description for '<S587>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_k = FLIGHT_Hexacopter_V2_B.TSamp_a;
}

// Model step function for TID1
void FLIGHT_Hexacopter_V2_step1(void)  // Sample time: [0.004s, 0.0s]
{
  real32_T rtb_Gain7;
  real32_T rtb_RateLimiter_0;
  real32_T rtb_RateLimiter_1;
  real32_T rtb_ReadParameter8_o1;
  real32_T rtb_Sum7_idx_0;
  real32_T rtb_Sum7_idx_1;
  real32_T rtb_TmpSignalConversionAtSFun_0;
  real32_T rtb_TmpSignalConversionAtSFun_1;
  real32_T rtb_read_mc_rollrate_p_o1;
  real32_T rtb_sincos_o1_idx_1;
  real32_T tmp;
  real32_T tmp_0;
  boolean_T rtb_AND;
  boolean_T rtb_AND1;
  boolean_T rtb_AND2;
  boolean_T rtb_flag_alt;
  boolean_T rtb_flag_pos;

  // MATLABSystem: '<S228>/SourceBlock'
  rtb_flag_pos = uORB_read_step(FLIGHT_Hexacopter_V2_DW.obj_l.orbMetadataObj,
    &FLIGHT_Hexacopter_V2_DW.obj_l.eventStructObj, &FLIGHT_Hexacopter_V2_B.r,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S228>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S234>/Enable'

  // Start for MATLABSystem: '<S228>/SourceBlock'
  if (rtb_flag_pos) {
    // SignalConversion generated from: '<S234>/In1'
    FLIGHT_Hexacopter_V2_B.In1 = FLIGHT_Hexacopter_V2_B.r;
  }

  // End of Outputs for SubSystem: '<S228>/Enabled Subsystem'

  // Trigonometry: '<S56>/SinCos'
  FLIGHT_Hexacopter_V2_B.Integrator_c = static_cast<real32_T>(sin(static_cast<
    real_T>(FLIGHT_Hexacopter_V2_B.In1.heading)));
  FLIGHT_Hexacopter_V2_B.roll_g = static_cast<real32_T>(cos(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.In1.heading)));

  // Math: '<S56>/Transpose' incorporates:
  //   Reshape: '<S56>/Reshape'
  //   Reshape: '<S56>/Reshape1'
  //   SignalConversion generated from: '<S49>/ SFunction '

  rtb_TmpSignalConversionAtSFun_0 = FLIGHT_Hexacopter_V2_B.roll_g;
  rtb_TmpSignalConversionAtSFun_1 = FLIGHT_Hexacopter_V2_B.roll_g;

  // MATLABSystem: '<S221>/SourceBlock'
  rtb_flag_pos = uORB_read_step(FLIGHT_Hexacopter_V2_DW.obj_n.orbMetadataObj,
    &FLIGHT_Hexacopter_V2_DW.obj_n.eventStructObj, &FLIGHT_Hexacopter_V2_B.r2,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S221>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S222>/Enable'

  // Start for MATLABSystem: '<S221>/SourceBlock'
  if (rtb_flag_pos) {
    // SignalConversion generated from: '<S222>/In1'
    FLIGHT_Hexacopter_V2_B.In1_p = FLIGHT_Hexacopter_V2_B.r2;
  }

  // End of Outputs for SubSystem: '<S221>/Enabled Subsystem'

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
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone_End;
  } else if (FLIGHT_Hexacopter_V2_B.Gain7 >=
             FLIGHT_Hexacopter_V2_P.DeadZone_Start) {
    rtb_sincos_o1_idx_1 = 0.0F;
  } else {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone_Start;
  }

  // End of DeadZone: '<S4>/Dead Zone'

  // Saturate: '<S4>/Saturation3'
  if (rtb_sincos_o1_idx_1 > FLIGHT_Hexacopter_V2_P.Saturation3_UpperSat) {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Saturation3_UpperSat;
  } else if (rtb_sincos_o1_idx_1 < FLIGHT_Hexacopter_V2_P.Saturation3_LowerSat)
  {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Saturation3_LowerSat;
  }

  // Gain: '<S4>/Gain4' incorporates:
  //   Saturate: '<S4>/Saturation3'

  FLIGHT_Hexacopter_V2_B.Gain4 = FLIGHT_Hexacopter_V2_P.MAX_CONTROL_ANGLE_ROLL *
    rtb_sincos_o1_idx_1;

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
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone1_End;
  } else if (FLIGHT_Hexacopter_V2_B.Gain7 >=
             FLIGHT_Hexacopter_V2_P.DeadZone1_Start) {
    rtb_sincos_o1_idx_1 = 0.0F;
  } else {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone1_Start;
  }

  // End of DeadZone: '<S4>/Dead Zone1'

  // Saturate: '<S4>/Saturation2'
  if (rtb_sincos_o1_idx_1 > FLIGHT_Hexacopter_V2_P.Saturation2_UpperSat_c) {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Saturation2_UpperSat_c;
  } else if (rtb_sincos_o1_idx_1 < FLIGHT_Hexacopter_V2_P.Saturation2_LowerSat_h)
  {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Saturation2_LowerSat_h;
  }

  // Gain: '<S4>/Gain5' incorporates:
  //   Saturate: '<S4>/Saturation2'

  FLIGHT_Hexacopter_V2_B.Gain5 = FLIGHT_Hexacopter_V2_P.MAX_CONTROL_ANGLE_PITCH *
    rtb_sincos_o1_idx_1;

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
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone2_End;
  } else if (FLIGHT_Hexacopter_V2_B.Gain7 >=
             FLIGHT_Hexacopter_V2_P.DeadZone2_Start) {
    rtb_sincos_o1_idx_1 = 0.0F;
  } else {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone2_Start;
  }

  // End of DeadZone: '<S4>/Dead Zone2'

  // Saturate: '<S4>/Saturation1'
  if (rtb_sincos_o1_idx_1 > FLIGHT_Hexacopter_V2_P.Saturation1_UpperSat) {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Saturation1_UpperSat;
  } else if (rtb_sincos_o1_idx_1 < FLIGHT_Hexacopter_V2_P.Saturation1_LowerSat)
  {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Saturation1_LowerSat;
  }

  // Gain: '<S4>/Gain6' incorporates:
  //   Saturate: '<S4>/Saturation1'

  FLIGHT_Hexacopter_V2_B.Gain6 = FLIGHT_Hexacopter_V2_P.MAX_CONTROL_ANGLE_RATE_Y
    * rtb_sincos_o1_idx_1;

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
    rtb_Gain7 = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone3_End;
  } else if (FLIGHT_Hexacopter_V2_B.Gain7 >=
             FLIGHT_Hexacopter_V2_P.DeadZone3_Start) {
    rtb_Gain7 = 0.0F;
  } else {
    rtb_Gain7 = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone3_Start;
  }

  // End of DeadZone: '<S4>/Dead Zone3'

  // Fcn: '<S4>/Fcn3' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion11'

  FLIGHT_Hexacopter_V2_B.Gain7 = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[2]) - 1514.0F) / 420.0F;

  // DeadZone: '<S4>/Dead Zone7'
  if (FLIGHT_Hexacopter_V2_B.Gain7 > FLIGHT_Hexacopter_V2_P.DeadZone7_End) {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone7_End;
  } else if (FLIGHT_Hexacopter_V2_B.Gain7 >=
             FLIGHT_Hexacopter_V2_P.DeadZone7_Start) {
    rtb_sincos_o1_idx_1 = 0.0F;
  } else {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone7_Start;
  }

  // End of DeadZone: '<S4>/Dead Zone7'

  // MATLABSystem: '<S5>/Read Parameter39'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_g.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // Saturate: '<S4>/Saturation10'
  if (rtb_sincos_o1_idx_1 > FLIGHT_Hexacopter_V2_P.Saturation10_UpperSat) {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Saturation10_UpperSat;
  } else if (rtb_sincos_o1_idx_1 < FLIGHT_Hexacopter_V2_P.Saturation10_LowerSat)
  {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Saturation10_LowerSat;
  }

  // Gain: '<S4>/Gain7' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter39'
  //   Product: '<S4>/Product'
  //   Saturate: '<S4>/Saturation10'
  //
  FLIGHT_Hexacopter_V2_B.Gain7 = rtb_sincos_o1_idx_1 *
    FLIGHT_Hexacopter_V2_B.ParamStep * FLIGHT_Hexacopter_V2_P.Gain7_Gain;

  // Sum: '<S55>/Sum1'
  FLIGHT_Hexacopter_V2_B.roll_g = FLIGHT_Hexacopter_V2_B.Gain7 -
    FLIGHT_Hexacopter_V2_B.In1.vz;

  // MATLABSystem: '<S5>/Read Parameter3'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_c4.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  FLIGHT_Hexacopt_SourceBlock(&FLIGHT_Hexacopter_V2_B.SourceBlock_l,
    &FLIGHT_Hexacopter_V2_DW.SourceBlock_l);

  // Outputs for Enabled SubSystem: '<S226>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S232>/Enable'

  if (FLIGHT_Hexacopter_V2_B.SourceBlock_l.SourceBlock_o1) {
    // SignalConversion generated from: '<S232>/In1' incorporates:
    //   MATLABSystem: '<S226>/SourceBlock'

    FLIGHT_Hexacopter_V2_B.In1_e =
      FLIGHT_Hexacopter_V2_B.SourceBlock_l.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: '<S226>/Enabled Subsystem'

  // Logic: '<S4>/AND' incorporates:
  //   Constant: '<S43>/Constant'
  //   RelationalOperator: '<S43>/Compare'

  rtb_AND = (FLIGHT_Hexacopter_V2_B.In1_p.values[5] >
             FLIGHT_Hexacopter_V2_P.CompareToConstant1_const) ^
    FLIGHT_Hexacopter_V2_B.In1_e.armed;

  // DiscreteIntegrator: '<S200>/Integrator'
  if ((rtb_AND && (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_l <= 0)) ||
      ((!rtb_AND) && (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_l == 1)))
  {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_l =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCon_pr;
  }

  // MATLABSystem: '<S5>/Read Parameter5'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_ia.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_c);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_c = 0.0F;
  }

  // Sum: '<S164>/Sum' incorporates:
  //   UnitDelay: '<S164>/Unit Delay1'

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i += FLIGHT_Hexacopter_V2_B.In1.vz;

  // MATLABSystem: '<S5>/Read Parameter11'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_jk.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_k);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_k = 0.0F;
  }

  // MATLAB Function: '<S5>/MATLAB Function' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter11'
  //
  FLIGHT_Hexacopter_V2_B.w_radps = FLIGHT_Hexacopter_V2_B.ParamStep_k * 2.0F *
    3.14159274F;

  // Gain: '<S164>/tau'
  FLIGHT_Hexacopter_V2_B.p_j = FLIGHT_Hexacopter_V2_P.tau_Gain_g *
    FLIGHT_Hexacopter_V2_B.w_radps;

  // Product: '<S165>/Product2'
  FLIGHT_Hexacopter_V2_B.q_c = FLIGHT_Hexacopter_V2_B.p_j *
    FLIGHT_Hexacopter_V2_B.p_j;

  // Bias: '<S165>/Bias'
  FLIGHT_Hexacopter_V2_B.r_o = FLIGHT_Hexacopter_V2_B.q_c +
    FLIGHT_Hexacopter_V2_P.Bias_Bias_n;

  // Gain: '<S165>/Gain'
  FLIGHT_Hexacopter_V2_B.p_j *= FLIGHT_Hexacopter_V2_P.Gain_Gain_oj;

  // Sum: '<S165>/Add1'
  FLIGHT_Hexacopter_V2_B.d_n = FLIGHT_Hexacopter_V2_B.r_o +
    FLIGHT_Hexacopter_V2_B.p_j;

  // SampleTimeMath: '<S161>/TSamp' incorporates:
  //   Product: '<S164>/Product1'
  //   Product: '<S165>/Product3'
  //   UnitDelay: '<S164>/Unit Delay1'
  //
  //  About '<S161>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.TSamp_k = FLIGHT_Hexacopter_V2_B.q_c /
    FLIGHT_Hexacopter_V2_B.d_n * FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_n;

  // MATLABSystem: '<S5>/Read Parameter26'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_lt.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_k);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_k = 0.0F;
  }

  // MATLAB Function: '<S4>/MATLAB Function2' incorporates:
  //   DiscreteIntegrator: '<S200>/Integrator'
  //   MATLABSystem: '<S5>/Read Parameter26'
  //   MATLABSystem: '<S5>/Read Parameter3'
  //   MATLABSystem: '<S5>/Read Parameter5'
  //   Product: '<S205>/PProd Out'
  //   Product: '<S55>/Product2'
  //   Sum: '<S161>/Diff'
  //   Sum: '<S209>/Sum'
  //   Sum: '<S55>/Sum5'
  //   UnitDelay: '<S161>/UD'
  //  *
  //  Block description for '<S161>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S161>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_B.Saturation5 = FLIGHT_Hexacopter_V2_B.ParamStep_k -
    ((FLIGHT_Hexacopter_V2_B.roll_g * FLIGHT_Hexacopter_V2_B.ParamStep +
      FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_l) -
     (FLIGHT_Hexacopter_V2_B.TSamp_k - FLIGHT_Hexacopter_V2_DW.UD_DSTATE_a) *
     FLIGHT_Hexacopter_V2_B.ParamStep_c) / 9.81F;

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
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_ic.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter27'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_l3.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_c);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_c = 0.0F;
  }

  // Fcn: '<S4>/Fcn2' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion1'

  FLIGHT_Hexacopter_V2_B.Product1_e = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[0]) - 1514.0F) / 420.0F;

  // MATLABSystem: '<S5>/Read Parameter40'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_pn.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_k);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_k = 0.0F;
  }

  // DeadZone: '<S4>/Dead Zone6'
  if (FLIGHT_Hexacopter_V2_B.Product1_e > FLIGHT_Hexacopter_V2_P.DeadZone6_End)
  {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_B.Product1_e -
      FLIGHT_Hexacopter_V2_P.DeadZone6_End;
  } else if (FLIGHT_Hexacopter_V2_B.Product1_e >=
             FLIGHT_Hexacopter_V2_P.DeadZone6_Start) {
    rtb_sincos_o1_idx_1 = 0.0F;
  } else {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_B.Product1_e -
      FLIGHT_Hexacopter_V2_P.DeadZone6_Start;
  }

  // End of DeadZone: '<S4>/Dead Zone6'

  // Saturate: '<S4>/Saturation9'
  if (rtb_sincos_o1_idx_1 > FLIGHT_Hexacopter_V2_P.Saturation9_UpperSat) {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Saturation9_UpperSat;
  } else if (rtb_sincos_o1_idx_1 < FLIGHT_Hexacopter_V2_P.Saturation9_LowerSat)
  {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Saturation9_LowerSat;
  }

  // Product: '<S4>/Product1' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter40'
  //   Saturate: '<S4>/Saturation9'
  //
  FLIGHT_Hexacopter_V2_B.Product1_e = rtb_sincos_o1_idx_1 *
    FLIGHT_Hexacopter_V2_B.ParamStep_k;

  // Gain: '<S4>/Gain8'
  FLIGHT_Hexacopter_V2_B.Gain8 = FLIGHT_Hexacopter_V2_P.Gain8_Gain *
    FLIGHT_Hexacopter_V2_B.Product1_e;

  // Logic: '<S4>/AND1' incorporates:
  //   Constant: '<S44>/Constant'
  //   Constant: '<S48>/Constant'
  //   RelationalOperator: '<S44>/Compare'
  //   RelationalOperator: '<S48>/Compare'

  rtb_AND1 = static_cast<boolean_T>((FLIGHT_Hexacopter_V2_B.In1_p.values[5] >
    FLIGHT_Hexacopter_V2_P.CompareToConstant2_const) ^
    FLIGHT_Hexacopter_V2_B.In1_e.armed) ^ (FLIGHT_Hexacopter_V2_B.Gain8 ==
    FLIGHT_Hexacopter_V2_P.CompareToConstant6_const);

  // DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
  if (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE_c =
      FLIGHT_Hexacopter_V2_B.In1.x;
  }

  if ((rtb_AND1 && (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRe_l <= 0))
      || ((!rtb_AND1) &&
          (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRe_l == 1))) {
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE_c =
      FLIGHT_Hexacopter_V2_B.In1.x;
  }

  // Fcn: '<S4>/Fcn1' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion7'

  FLIGHT_Hexacopter_V2_B.Product2_e = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[1]) - 1514.0F) / 420.0F;

  // DeadZone: '<S4>/Dead Zone4'
  if (FLIGHT_Hexacopter_V2_B.Product2_e > FLIGHT_Hexacopter_V2_P.DeadZone4_End)
  {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_B.Product2_e -
      FLIGHT_Hexacopter_V2_P.DeadZone4_End;
  } else if (FLIGHT_Hexacopter_V2_B.Product2_e >=
             FLIGHT_Hexacopter_V2_P.DeadZone4_Start) {
    rtb_sincos_o1_idx_1 = 0.0F;
  } else {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_B.Product2_e -
      FLIGHT_Hexacopter_V2_P.DeadZone4_Start;
  }

  // End of DeadZone: '<S4>/Dead Zone4'

  // Saturate: '<S4>/Saturation4'
  if (rtb_sincos_o1_idx_1 > FLIGHT_Hexacopter_V2_P.Saturation4_UpperSat) {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Saturation4_UpperSat;
  } else if (rtb_sincos_o1_idx_1 < FLIGHT_Hexacopter_V2_P.Saturation4_LowerSat)
  {
    rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Saturation4_LowerSat;
  }

  // Product: '<S4>/Product2' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter40'
  //   Saturate: '<S4>/Saturation4'
  //
  FLIGHT_Hexacopter_V2_B.Product2_e = rtb_sincos_o1_idx_1 *
    FLIGHT_Hexacopter_V2_B.ParamStep_k;

  // Gain: '<S4>/Gain9'
  FLIGHT_Hexacopter_V2_B.ParamStep_k = FLIGHT_Hexacopter_V2_P.Gain9_Gain *
    FLIGHT_Hexacopter_V2_B.Product2_e;

  // Logic: '<S4>/AND2' incorporates:
  //   Constant: '<S46>/Constant'
  //   Constant: '<S47>/Constant'
  //   RelationalOperator: '<S46>/Compare'
  //   RelationalOperator: '<S47>/Compare'

  rtb_AND2 = static_cast<boolean_T>((FLIGHT_Hexacopter_V2_B.In1_p.values[5] >
    FLIGHT_Hexacopter_V2_P.CompareToConstant4_const) ^
    FLIGHT_Hexacopter_V2_B.In1_e.armed) ^ (FLIGHT_Hexacopter_V2_B.ParamStep_k ==
    FLIGHT_Hexacopter_V2_P.CompareToConstant5_const);

  // DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
  if (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE =
      FLIGHT_Hexacopter_V2_B.In1.y;
  }

  if ((rtb_AND2 && (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_PrevRes <= 0))
      || ((!rtb_AND2) &&
          (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_PrevRes == 1))) {
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE =
      FLIGHT_Hexacopter_V2_B.In1.y;
  }

  // Sum: '<S4>/Sum7' incorporates:
  //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
  //   MATLABSystem: '<S5>/Read Parameter27'
  //   Product: '<S96>/PProd Out'
  //   Sum: '<S4>/Sum5'
  //
  rtb_Sum7_idx_0 = (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE_c -
                    FLIGHT_Hexacopter_V2_B.In1.x) *
    FLIGHT_Hexacopter_V2_B.ParamStep_c - FLIGHT_Hexacopter_V2_B.In1.vx;
  rtb_Sum7_idx_1 = (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE -
                    FLIGHT_Hexacopter_V2_B.In1.y) *
    FLIGHT_Hexacopter_V2_B.ParamStep_c - FLIGHT_Hexacopter_V2_B.In1.vy;

  // RateLimiter: '<S4>/Rate Limiter'
  rtb_sincos_o1_idx_1 = static_cast<real32_T>(120.0 * FLIGHT_Hexacopter_V2_P.d2r
    * FLIGHT_Hexacopter_V2_period);
  FLIGHT_Hexacopter_V2_B.ParamStep_c = static_cast<real32_T>(120.0 *
    FLIGHT_Hexacopter_V2_P.d2r * FLIGHT_Hexacopter_V2_period);
  tmp = static_cast<real32_T>(-120.0 * FLIGHT_Hexacopter_V2_P.d2r *
    FLIGHT_Hexacopter_V2_period);
  tmp_0 = static_cast<real32_T>(-120.0 * FLIGHT_Hexacopter_V2_P.d2r *
    FLIGHT_Hexacopter_V2_period);

  // Product: '<S148>/PProd Out' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter28'
  //   Product: '<S52>/MatrixMultiply'
  //   Reshape: '<S56>/Reshape1'
  //   SignalConversion generated from: '<S49>/ SFunction '
  //
  rtb_RateLimiter_0 = (rtb_TmpSignalConversionAtSFun_0 * rtb_Sum7_idx_0 +
                       FLIGHT_Hexacopter_V2_B.Integrator_c * rtb_Sum7_idx_1) *
    FLIGHT_Hexacopter_V2_B.ParamStep;

  // RateLimiter: '<S4>/Rate Limiter'
  rtb_TmpSignalConversionAtSFun_0 = rtb_RateLimiter_0 -
    FLIGHT_Hexacopter_V2_DW.PrevY[0];
  if (rtb_TmpSignalConversionAtSFun_0 > rtb_sincos_o1_idx_1) {
    rtb_RateLimiter_0 = FLIGHT_Hexacopter_V2_DW.PrevY[0] +
      FLIGHT_Hexacopter_V2_B.ParamStep_c;
  } else if (rtb_TmpSignalConversionAtSFun_0 < tmp) {
    rtb_RateLimiter_0 = FLIGHT_Hexacopter_V2_DW.PrevY[0] + tmp_0;
  }

  FLIGHT_Hexacopter_V2_DW.PrevY[0] = rtb_RateLimiter_0;

  // Saturate: '<S4>/Saturation6'
  if (rtb_RateLimiter_0 > FLIGHT_Hexacopter_V2_P.Saturation6_UpperSat) {
    rtb_RateLimiter_1 = FLIGHT_Hexacopter_V2_P.Saturation6_UpperSat;
  } else if (rtb_RateLimiter_0 < FLIGHT_Hexacopter_V2_P.Saturation6_LowerSat) {
    rtb_RateLimiter_1 = FLIGHT_Hexacopter_V2_P.Saturation6_LowerSat;
  } else {
    rtb_RateLimiter_1 = rtb_RateLimiter_0;
  }

  // Product: '<S148>/PProd Out' incorporates:
  //   Gain: '<S56>/Gain'
  //   MATLABSystem: '<S5>/Read Parameter28'
  //   Product: '<S52>/MatrixMultiply'
  //   SignalConversion generated from: '<S49>/ SFunction '
  //
  rtb_RateLimiter_0 = (FLIGHT_Hexacopter_V2_P.Gain_Gain_az *
                       FLIGHT_Hexacopter_V2_B.Integrator_c * rtb_Sum7_idx_0 +
                       rtb_TmpSignalConversionAtSFun_1 * rtb_Sum7_idx_1) *
    FLIGHT_Hexacopter_V2_B.ParamStep;

  // RateLimiter: '<S4>/Rate Limiter'
  rtb_TmpSignalConversionAtSFun_0 = rtb_RateLimiter_0 -
    FLIGHT_Hexacopter_V2_DW.PrevY[1];
  if (rtb_TmpSignalConversionAtSFun_0 > rtb_sincos_o1_idx_1) {
    rtb_RateLimiter_0 = FLIGHT_Hexacopter_V2_DW.PrevY[1] +
      FLIGHT_Hexacopter_V2_B.ParamStep_c;
  } else if (rtb_TmpSignalConversionAtSFun_0 < tmp) {
    rtb_RateLimiter_0 = FLIGHT_Hexacopter_V2_DW.PrevY[1] + tmp_0;
  }

  FLIGHT_Hexacopter_V2_DW.PrevY[1] = rtb_RateLimiter_0;

  // Saturate: '<S4>/Saturation6'
  if (rtb_RateLimiter_0 > FLIGHT_Hexacopter_V2_P.Saturation6_UpperSat) {
    rtb_RateLimiter_0 = FLIGHT_Hexacopter_V2_P.Saturation6_UpperSat;
  } else if (rtb_RateLimiter_0 < FLIGHT_Hexacopter_V2_P.Saturation6_LowerSat) {
    rtb_RateLimiter_0 = FLIGHT_Hexacopter_V2_P.Saturation6_LowerSat;
  }

  // MATLABSystem: '<S227>/SourceBlock'
  rtb_flag_pos = uORB_read_step(FLIGHT_Hexacopter_V2_DW.obj_a.orbMetadataObj,
    &FLIGHT_Hexacopter_V2_DW.obj_a.eventStructObj, &FLIGHT_Hexacopter_V2_B.r3,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S227>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S233>/Enable'

  // Start for MATLABSystem: '<S227>/SourceBlock'
  if (rtb_flag_pos) {
    // SignalConversion generated from: '<S233>/In1'
    FLIGHT_Hexacopter_V2_B.In1_m = FLIGHT_Hexacopter_V2_B.r3;
  }

  // End of Outputs for SubSystem: '<S227>/Enabled Subsystem'

  // MATLAB Function: '<S8>/MATLAB Function'
  switch (FLIGHT_Hexacopter_V2_B.In1_m.nav_state) {
   case 1U:
    rtb_flag_pos = false;
    rtb_flag_alt = true;
    break;

   case 2U:
    rtb_flag_pos = true;
    rtb_flag_alt = false;
    break;

   default:
    rtb_flag_pos = false;
    rtb_flag_alt = false;
    break;
  }

  // End of MATLAB Function: '<S8>/MATLAB Function'

  // SignalConversion generated from: '<S49>/ SFunction ' incorporates:
  //   MATLAB Function: '<S4>/MATLAB Function'

  rtb_TmpSignalConversionAtSFun_0 = FLIGHT_Hexacopter_V2_B.Gain4;

  // Saturate: '<S4>/Saturation'
  if (rtb_Gain7 > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_h) {
    // SignalConversion generated from: '<S49>/ SFunction ' incorporates:
    //   MATLAB Function: '<S4>/MATLAB Function'

    rtb_TmpSignalConversionAtSFun_1 =
      FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_h;
  } else if (rtb_Gain7 < FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_p) {
    // SignalConversion generated from: '<S49>/ SFunction ' incorporates:
    //   MATLAB Function: '<S4>/MATLAB Function'

    rtb_TmpSignalConversionAtSFun_1 =
      FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_p;
  } else {
    // SignalConversion generated from: '<S49>/ SFunction ' incorporates:
    //   MATLAB Function: '<S4>/MATLAB Function'

    rtb_TmpSignalConversionAtSFun_1 = rtb_Gain7;
  }

  // End of Saturate: '<S4>/Saturation'

  // MATLAB Function: '<S4>/MATLAB Function' incorporates:
  //   Gain: '<S4>/Gain11'
  //   Saturate: '<S4>/Saturation6'
  //   SignalConversion generated from: '<S49>/ SFunction '

  if ((FLIGHT_Hexacopter_V2_B.In1_p.values[5] >= 1800) && rtb_flag_pos) {
    rtb_TmpSignalConversionAtSFun_0 = rtb_RateLimiter_0;
    FLIGHT_Hexacopter_V2_B.Gain5 = FLIGHT_Hexacopter_V2_P.Gain11_Gain *
      rtb_RateLimiter_1;
    rtb_TmpSignalConversionAtSFun_1 = FLIGHT_Hexacopter_V2_B.Saturation5;
  } else if ((FLIGHT_Hexacopter_V2_B.In1_p.values[5] < 1800) &&
             (FLIGHT_Hexacopter_V2_B.In1_p.values[5] >= 1400) && rtb_flag_alt) {
    rtb_TmpSignalConversionAtSFun_1 = FLIGHT_Hexacopter_V2_B.Saturation5;
  }

  // RateTransition: '<S10>/Rate Transition4'
  FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0 =
    rtb_TmpSignalConversionAtSFun_1;

  // MATLABSystem: '<S236>/SourceBlock'
  rtb_flag_pos = uORB_read_step(FLIGHT_Hexacopter_V2_DW.obj_i.orbMetadataObj,
    &FLIGHT_Hexacopter_V2_DW.obj_i.eventStructObj, &FLIGHT_Hexacopter_V2_B.r1,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S236>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S237>/Enable'

  // Start for MATLABSystem: '<S236>/SourceBlock'
  if (rtb_flag_pos) {
    // SignalConversion generated from: '<S237>/In1'
    FLIGHT_Hexacopter_V2_B.In1_b = FLIGHT_Hexacopter_V2_B.r1;
  }

  // End of Outputs for SubSystem: '<S236>/Enabled Subsystem'

  // MATLAB Function: '<S8>/quat2eul'
  FLIGHT_Hexacopter_V2_B.ypr[0] = rt_atan2f_snf((FLIGHT_Hexacopter_V2_B.In1_b.q
    [1] * FLIGHT_Hexacopter_V2_B.In1_b.q[2] + FLIGHT_Hexacopter_V2_B.In1_b.q[0] *
    FLIGHT_Hexacopter_V2_B.In1_b.q[3]) * 2.0F, ((FLIGHT_Hexacopter_V2_B.In1_b.q
    [0] * FLIGHT_Hexacopter_V2_B.In1_b.q[0] + FLIGHT_Hexacopter_V2_B.In1_b.q[1] *
    FLIGHT_Hexacopter_V2_B.In1_b.q[1]) - FLIGHT_Hexacopter_V2_B.In1_b.q[2] *
    FLIGHT_Hexacopter_V2_B.In1_b.q[2]) - FLIGHT_Hexacopter_V2_B.In1_b.q[3] *
    FLIGHT_Hexacopter_V2_B.In1_b.q[3]);
  FLIGHT_Hexacopter_V2_B.ypr[1] = static_cast<real32_T>(asin(static_cast<real_T>
    ((FLIGHT_Hexacopter_V2_B.In1_b.q[1] * FLIGHT_Hexacopter_V2_B.In1_b.q[3] -
      FLIGHT_Hexacopter_V2_B.In1_b.q[0] * FLIGHT_Hexacopter_V2_B.In1_b.q[2]) *
     -2.0F)));
  FLIGHT_Hexacopter_V2_B.ypr[2] = rt_atan2f_snf((FLIGHT_Hexacopter_V2_B.In1_b.q
    [0] * FLIGHT_Hexacopter_V2_B.In1_b.q[1] + FLIGHT_Hexacopter_V2_B.In1_b.q[2] *
    FLIGHT_Hexacopter_V2_B.In1_b.q[3]) * 2.0F, ((FLIGHT_Hexacopter_V2_B.In1_b.q
    [0] * FLIGHT_Hexacopter_V2_B.In1_b.q[0] - FLIGHT_Hexacopter_V2_B.In1_b.q[1] *
    FLIGHT_Hexacopter_V2_B.In1_b.q[1]) - FLIGHT_Hexacopter_V2_B.In1_b.q[2] *
    FLIGHT_Hexacopter_V2_B.In1_b.q[2]) + FLIGHT_Hexacopter_V2_B.In1_b.q[3] *
    FLIGHT_Hexacopter_V2_B.In1_b.q[3]);

  // RateTransition: '<S9>/Rate Transition2'
  FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[0] =
    FLIGHT_Hexacopter_V2_B.ypr[0];
  FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[1] =
    FLIGHT_Hexacopter_V2_B.ypr[1];
  FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[2] =
    FLIGHT_Hexacopter_V2_B.ypr[2];

  // RelationalOperator: '<S45>/Compare' incorporates:
  //   Constant: '<S45>/Constant'

  rtb_flag_alt = (FLIGHT_Hexacopter_V2_B.In1_p.values[6] >=
                  FLIGHT_Hexacopter_V2_P.CompareToConstant3_const);

  // MATLABSystem: '<S4>/PX4 Timestamp'
  FLIGHT_Hexacopter_V2_B.rtb_PX4Timestamp_m = hrt_absolute_time();

  // MATLABSystem: '<S5>/Read Parameter1'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_l4.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_jf.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_c);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_c = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter2'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_a1.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_Hexacopter_V2_B.ParamStep_cv);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_cv = 0;
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
  FLIGHT_Hexacopter_V2_B.out_roll = rtb_TmpSignalConversionAtSFun_0;
  FLIGHT_Hexacopter_V2_B.out_pitch = FLIGHT_Hexacopter_V2_B.Gain5;
  FLIGHT_Hexacopter_V2_B.out_yawrate = FLIGHT_Hexacopter_V2_B.Gain6;
  if (rtb_flag_alt && (FLIGHT_Hexacopter_V2_DW.start_time_usec == -1.0)) {
    FLIGHT_Hexacopter_V2_DW.start_time_usec = static_cast<real_T>
      (FLIGHT_Hexacopter_V2_B.rtb_PX4Timestamp_m);
  }

  if (rtb_flag_alt && (FLIGHT_Hexacopter_V2_DW.start_time_usec > 0.0)) {
    FLIGHT_Hexacopter_V2_B.reletive_time_sec = (static_cast<real_T>
      (FLIGHT_Hexacopter_V2_B.rtb_PX4Timestamp_m) -
      FLIGHT_Hexacopter_V2_DW.start_time_usec) * 1.0E-6;
  } else {
    FLIGHT_Hexacopter_V2_DW.start_time_usec = -1.0;
    FLIGHT_Hexacopter_V2_B.reletive_time_sec = 0.0;
  }

  FLIGHT_Hexacopter_V2_B.peak_angle_rad = FLIGHT_Hexacopter_V2_B.ParamStep *
    0.017453292519943295;
  if (rtb_flag_alt) {
    switch (FLIGHT_Hexacopter_V2_B.ParamStep_cv) {
     case 1:
      if ((FLIGHT_Hexacopter_V2_B.reletive_time_sec >= 0.0) &&
          (FLIGHT_Hexacopter_V2_B.reletive_time_sec <
           FLIGHT_Hexacopter_V2_B.ParamStep_c)) {
        FLIGHT_Hexacopter_V2_B.out_roll = FLIGHT_Hexacopter_V2_B.peak_angle_rad;
      } else if ((FLIGHT_Hexacopter_V2_B.reletive_time_sec >=
                  FLIGHT_Hexacopter_V2_B.ParamStep_c) &&
                 (FLIGHT_Hexacopter_V2_B.reletive_time_sec < static_cast<real_T>
                  (FLIGHT_Hexacopter_V2_B.ParamStep_c) +
                  FLIGHT_Hexacopter_V2_B.ParamStep_c)) {
        FLIGHT_Hexacopter_V2_B.out_roll = -FLIGHT_Hexacopter_V2_B.peak_angle_rad;
      } else {
        FLIGHT_Hexacopter_V2_B.out_roll = 0.0;
      }
      break;

     case 2:
      if ((FLIGHT_Hexacopter_V2_B.reletive_time_sec >= 0.0) &&
          (FLIGHT_Hexacopter_V2_B.reletive_time_sec <
           FLIGHT_Hexacopter_V2_B.ParamStep_c)) {
        FLIGHT_Hexacopter_V2_B.out_pitch = FLIGHT_Hexacopter_V2_B.peak_angle_rad;
      } else if ((FLIGHT_Hexacopter_V2_B.reletive_time_sec >=
                  FLIGHT_Hexacopter_V2_B.ParamStep_c) &&
                 (FLIGHT_Hexacopter_V2_B.reletive_time_sec < static_cast<real_T>
                  (FLIGHT_Hexacopter_V2_B.ParamStep_c) +
                  FLIGHT_Hexacopter_V2_B.ParamStep_c)) {
        FLIGHT_Hexacopter_V2_B.out_pitch =
          -FLIGHT_Hexacopter_V2_B.peak_angle_rad;
      } else {
        FLIGHT_Hexacopter_V2_B.out_pitch = 0.0;
      }
      break;

     case 3:
      if ((FLIGHT_Hexacopter_V2_B.reletive_time_sec >= 0.0) &&
          (FLIGHT_Hexacopter_V2_B.reletive_time_sec <
           FLIGHT_Hexacopter_V2_B.ParamStep_c)) {
        FLIGHT_Hexacopter_V2_B.out_yawrate =
          FLIGHT_Hexacopter_V2_B.peak_angle_rad;
      } else if ((FLIGHT_Hexacopter_V2_B.reletive_time_sec >=
                  FLIGHT_Hexacopter_V2_B.ParamStep_c) &&
                 (FLIGHT_Hexacopter_V2_B.reletive_time_sec < static_cast<real_T>
                  (FLIGHT_Hexacopter_V2_B.ParamStep_c) +
                  FLIGHT_Hexacopter_V2_B.ParamStep_c)) {
        FLIGHT_Hexacopter_V2_B.out_yawrate =
          -FLIGHT_Hexacopter_V2_B.peak_angle_rad;
      } else {
        FLIGHT_Hexacopter_V2_B.out_yawrate = 0.0;
      }
      break;
    }
  }

  // End of MATLAB Function: '<S4>/MATLAB Function1'

  // Gain: '<S27>/1//2' incorporates:
  //   Constant: '<S3>/Constant1'
  //   DataTypeConversion: '<S4>/Data Type Conversion13'
  //   DataTypeConversion: '<S4>/Data Type Conversion14'

  FLIGHT_Hexacopter_V2_B.Gain6 = FLIGHT_Hexacopter_V2_P.u2_Gain *
    FLIGHT_Hexacopter_V2_P.Constant1_Value_fy;
  rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.u2_Gain * static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_pitch);
  FLIGHT_Hexacopter_V2_B.ParamStep_c = FLIGHT_Hexacopter_V2_P.u2_Gain *
    static_cast<real32_T>(FLIGHT_Hexacopter_V2_B.out_roll);

  // Trigonometry: '<S27>/sincos'
  FLIGHT_Hexacopter_V2_B.ParamStep = static_cast<real32_T>(cos
    (static_cast<real_T>(FLIGHT_Hexacopter_V2_B.Gain6)));
  FLIGHT_Hexacopter_V2_B.Integrator_c = static_cast<real32_T>(sin
    (static_cast<real_T>(FLIGHT_Hexacopter_V2_B.Gain6)));
  rtb_TmpSignalConversionAtSFun_0 = static_cast<real32_T>(cos(static_cast<real_T>
    (rtb_sincos_o1_idx_1)));
  FLIGHT_Hexacopter_V2_B.Gain4 = static_cast<real32_T>(sin(static_cast<real_T>
    (rtb_sincos_o1_idx_1)));
  rtb_Gain7 = static_cast<real32_T>(cos(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.ParamStep_c)));
  FLIGHT_Hexacopter_V2_B.Saturation5 = static_cast<real32_T>(sin
    (static_cast<real_T>(FLIGHT_Hexacopter_V2_B.ParamStep_c)));
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

  rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_B.ParamStep *
    rtb_TmpSignalConversionAtSFun_0;
  FLIGHT_Hexacopter_V2_B.ParamStep_c = FLIGHT_Hexacopter_V2_B.Integrator_c *
    FLIGHT_Hexacopter_V2_B.Gain4;

  // BusAssignment: '<S25>/Bus Assignment' incorporates:
  //   Fcn: '<S27>/q0'
  //   Fcn: '<S27>/q1'
  //   Trigonometry: '<S27>/sincos'

  FLIGHT_Hexacopter_V2_B.BusAssignment_f.q_d[0] = rtb_sincos_o1_idx_1 *
    rtb_Gain7 + FLIGHT_Hexacopter_V2_B.ParamStep_c *
    FLIGHT_Hexacopter_V2_B.Saturation5;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.q_d[1] = rtb_sincos_o1_idx_1 *
    FLIGHT_Hexacopter_V2_B.Saturation5 - FLIGHT_Hexacopter_V2_B.ParamStep_c *
    rtb_Gain7;

  // Fcn: '<S27>/q2' incorporates:
  //   Fcn: '<S27>/q3'
  //   Trigonometry: '<S27>/sincos'

  rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_B.Integrator_c *
    rtb_TmpSignalConversionAtSFun_0;
  FLIGHT_Hexacopter_V2_B.ParamStep_c = FLIGHT_Hexacopter_V2_B.ParamStep *
    FLIGHT_Hexacopter_V2_B.Gain4;

  // BusAssignment: '<S25>/Bus Assignment' incorporates:
  //   Constant: '<S3>/Constant'
  //   Fcn: '<S27>/q2'
  //   Fcn: '<S27>/q3'
  //   Trigonometry: '<S27>/sincos'

  FLIGHT_Hexacopter_V2_B.BusAssignment_f.q_d[2] =
    FLIGHT_Hexacopter_V2_B.ParamStep_c * rtb_Gain7 + rtb_sincos_o1_idx_1 *
    FLIGHT_Hexacopter_V2_B.Saturation5;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.q_d[3] = rtb_sincos_o1_idx_1 *
    rtb_Gain7 - FLIGHT_Hexacopter_V2_B.ParamStep_c *
    FLIGHT_Hexacopter_V2_B.Saturation5;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.thrust_body[0] =
    FLIGHT_Hexacopter_V2_P.Constant_Value_i;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.thrust_body[1] =
    FLIGHT_Hexacopter_V2_P.Constant_Value_i;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.thrust_body[2] =
    rtb_TmpSignalConversionAtSFun_1;
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

  FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_g = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_yawrate);

  // RateTransition: '<S366>/Rate Transition4' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion15'

  FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_c = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_yawrate);
  FLIGHT_Hexac_PX4Timestamp_j(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_p);

  // MATLABSystem: '<S5>/Read Parameter9'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_ai.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // Gain: '<S218>/Gain1' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter9'
  //
  rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Gain1_Gain_o *
    FLIGHT_Hexacopter_V2_B.ParamStep;

  // MATLABSystem: '<S5>/Read Parameter6'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_p.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // Product: '<S459>/PProd Out' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion14'
  //   MATLABSystem: '<S5>/Read Parameter6'
  //   Sum: '<S10>/Sum3'
  //
  FLIGHT_Hexacopter_V2_B.ParamStep_c = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_roll) - FLIGHT_Hexacopter_V2_B.ypr[2]) *
    FLIGHT_Hexacopter_V2_B.ParamStep;

  // Switch: '<S462>/Switch2' incorporates:
  //   RelationalOperator: '<S462>/LowerRelop1'

  if (FLIGHT_Hexacopter_V2_B.ParamStep_c > rtb_sincos_o1_idx_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_c = rtb_sincos_o1_idx_1;
  } else {
    // Gain: '<S10>/Gain'
    FLIGHT_Hexacopter_V2_B.ParamStep = FLIGHT_Hexacopter_V2_P.Gain_Gain_o *
      rtb_sincos_o1_idx_1;

    // Switch: '<S462>/Switch' incorporates:
    //   RelationalOperator: '<S462>/UpperRelop'

    if (FLIGHT_Hexacopter_V2_B.ParamStep_c < FLIGHT_Hexacopter_V2_B.ParamStep) {
      FLIGHT_Hexacopter_V2_B.ParamStep_c = FLIGHT_Hexacopter_V2_B.ParamStep;
    }

    // End of Switch: '<S462>/Switch'
  }

  // End of Switch: '<S462>/Switch2'

  // MATLABSystem: '<S5>/Read Parameter10'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_bq.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // Gain: '<S219>/Gain1' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter10'
  //
  rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Gain1_Gain_j *
    FLIGHT_Hexacopter_V2_B.ParamStep;

  // MATLABSystem: '<S5>/Read Parameter7'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_fj.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // Product: '<S406>/PProd Out' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion13'
  //   MATLABSystem: '<S5>/Read Parameter7'
  //   Sum: '<S10>/Sum2'
  //
  FLIGHT_Hexacopter_V2_B.ParamStep *= static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_pitch) - FLIGHT_Hexacopter_V2_B.ypr[1];

  // Switch: '<S409>/Switch2' incorporates:
  //   RelationalOperator: '<S409>/LowerRelop1'

  if (FLIGHT_Hexacopter_V2_B.ParamStep > rtb_sincos_o1_idx_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep = rtb_sincos_o1_idx_1;
  } else {
    // Gain: '<S10>/Gain1'
    rtb_sincos_o1_idx_1 *= FLIGHT_Hexacopter_V2_P.Gain1_Gain;

    // Switch: '<S409>/Switch' incorporates:
    //   RelationalOperator: '<S409>/UpperRelop'

    if (FLIGHT_Hexacopter_V2_B.ParamStep < rtb_sincos_o1_idx_1) {
      FLIGHT_Hexacopter_V2_B.ParamStep = rtb_sincos_o1_idx_1;
    }

    // End of Switch: '<S409>/Switch'
  }

  // End of Switch: '<S409>/Switch2'

  // BusAssignment: '<S26>/Bus Assignment' incorporates:
  //   Constant: '<S3>/Constant3'
  //   DataTypeConversion: '<S4>/Data Type Conversion15'
  //   MATLABSystem: '<S26>/PX4 Timestamp'

  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.timestamp =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp_p.PX4Timestamp;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.roll =
    FLIGHT_Hexacopter_V2_B.ParamStep_c;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.pitch =
    FLIGHT_Hexacopter_V2_B.ParamStep;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.yaw = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_yawrate);
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.thrust_body[0] =
    FLIGHT_Hexacopter_V2_P.Constant3_Value_m;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.thrust_body[1] =
    FLIGHT_Hexacopter_V2_P.Constant3_Value_m;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.thrust_body[2] =
    rtb_TmpSignalConversionAtSFun_1;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.reset_integral = false;
  for (FLIGHT_Hexacopter_V2_B.ParamStep_cv = 0;
       FLIGHT_Hexacopter_V2_B.ParamStep_cv < 7;
       FLIGHT_Hexacopter_V2_B.ParamStep_cv++) {
    FLIGHT_Hexacopter_V2_B.BusAssignment_e0._padding0[FLIGHT_Hexacopter_V2_B.ParamStep_cv]
      = 0U;
  }

  // End of BusAssignment: '<S26>/Bus Assignment'

  // MATLABSystem: '<S36>/SinkBlock' incorporates:
  //   BusAssignment: '<S26>/Bus Assignment'

  uORB_write_step(FLIGHT_Hexacopter_V2_DW.obj_mp.orbMetadataObj,
                  &FLIGHT_Hexacopter_V2_DW.obj_mp.orbAdvertiseObj,
                  &FLIGHT_Hexacopter_V2_B.BusAssignment_e0);

  // RateTransition: '<S364>/Rate Transition4'
  FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_k =
    FLIGHT_Hexacopter_V2_B.ParamStep;

  // RateTransition: '<S365>/Rate Transition4'
  FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_e =
    FLIGHT_Hexacopter_V2_B.ParamStep_c;
  FLIGHT_Hexac_PX4Timestamp_j(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_k);

  // BusAssignment: '<S30>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion15'
  //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
  //   MATLABSystem: '<S30>/PX4 Timestamp'

  FLIGHT_Hexacopter_V2_B.BusAssignment_g.timestamp =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp_k.PX4Timestamp;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.x =
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE_c;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.y =
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.z = 0.0F;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.vx = FLIGHT_Hexacopter_V2_B.Product2_e;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.vy = FLIGHT_Hexacopter_V2_B.Product1_e;
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

  // RateTransition: '<S9>/Rate Transition1' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion14'

  FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0 = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_roll);

  // Sum: '<S164>/Sum1' incorporates:
  //   Bias: '<S165>/Bias1'
  //   Gain: '<S164>/Gain1'
  //   Product: '<S164>/Product5'
  //   Product: '<S165>/Product4'
  //   Sum: '<S164>/Sum2'
  //   UnaryMinus: '<S165>/Unary Minus'
  //   UnitDelay: '<S164>/Unit Delay1'
  //   UnitDelay: '<S164>/Unit Delay2'

  FLIGHT_Hexacopter_V2_B.q_c = ((-FLIGHT_Hexacopter_V2_B.q_c +
    FLIGHT_Hexacopter_V2_P.Bias1_Bias_m) / FLIGHT_Hexacopter_V2_B.d_n *
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i + FLIGHT_Hexacopter_V2_B.In1.vz)
    * FLIGHT_Hexacopter_V2_P.Gain1_Gain_a +
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_f;

  // Product: '<S164>/Product2' incorporates:
  //   Product: '<S165>/Product5'
  //   Sum: '<S165>/Add3'
  //   UnitDelay: '<S164>/Unit Delay1'

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i *= 1.0F /
    FLIGHT_Hexacopter_V2_B.d_n * (FLIGHT_Hexacopter_V2_B.r_o -
    FLIGHT_Hexacopter_V2_B.p_j);

  // Sum: '<S164>/Sum3' incorporates:
  //   UnitDelay: '<S164>/Unit Delay1'
  //   UnitDelay: '<S164>/Unit Delay2'

  FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_f = FLIGHT_Hexacopter_V2_B.In1.vz -
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i;

  // RateTransition: '<S364>/Rate Transition3'
  FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0_p =
    FLIGHT_Hexacopter_V2_B.w_radps;

  // RateTransition: '<S365>/Rate Transition3'
  FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0 =
    FLIGHT_Hexacopter_V2_B.w_radps;

  // RateTransition: '<S366>/Rate Transition3'
  FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0_d =
    FLIGHT_Hexacopter_V2_B.w_radps;

  // MATLABSystem: '<S5>/Read Parameter4'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_c1.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // RateTransition generated from: '<Root>/Rate Transition'
  FLIGHT_Hexacopter_V2_DW.RateTransition_4_Buffer0 =
    FLIGHT_Hexacopter_V2_B.In1_p.values[7];

  // RateTransition generated from: '<Root>/Rate Transition'
  FLIGHT_Hexacopter_V2_DW.RateTransition_8_Buffer0 =
    FLIGHT_Hexacopter_V2_B.In1_p.values[9];
  FLIGHT_Hexacopt_SourceBlock(&FLIGHT_Hexacopter_V2_B.SourceBlock_p,
    &FLIGHT_Hexacopter_V2_DW.SourceBlock_p);

  // Outputs for Enabled SubSystem: '<S229>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S235>/Enable'

  if (FLIGHT_Hexacopter_V2_B.SourceBlock_p.SourceBlock_o1) {
    // SignalConversion generated from: '<S235>/In1' incorporates:
    //   MATLABSystem: '<S229>/SourceBlock'

    FLIGHT_Hexacopter_V2_B.In1_d =
      FLIGHT_Hexacopter_V2_B.SourceBlock_p.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: '<S229>/Enabled Subsystem'

  // RelationalOperator: '<S240>/Compare' incorporates:
  //   Constant: '<S240>/Constant'

  rtb_flag_pos = (FLIGHT_Hexacopter_V2_B.In1_p.values[9] >=
                  FLIGHT_Hexacopter_V2_P.CompareToConstant1_const_j);

  // RateTransition: '<S9>/Rate Transition15' incorporates:
  //   Constant: '<S239>/Constant'
  //   Logic: '<S9>/XOR'
  //   RelationalOperator: '<S239>/Compare'

  FLIGHT_Hexacopter_V2_DW.RateTransition15_Buffer0 = static_cast<boolean_T>
    ((FLIGHT_Hexacopter_V2_B.In1_p.values[9] >=
      FLIGHT_Hexacopter_V2_P.CompareToConstant_const_o) ^
     FLIGHT_Hexacopter_V2_B.In1_d.armed) ^ rtb_flag_pos;

  // RateTransition: '<S9>/Rate Transition16'
  FLIGHT_Hexacopter_V2_DW.RateTransition16_Buffer0 = rtb_flag_pos;

  // RateTransition generated from: '<Root>/Rate Transition2'
  FLIGHT_Hexacopter_V2_DW.RateTransition2_16_Buffer0 =
    FLIGHT_Hexacopter_V2_B.In1_d.armed;

  // RateTransition generated from: '<Root>/Rate Transition2'
  FLIGHT_Hexacopter_V2_DW.RateTransition2_17_Buffer0 =
    FLIGHT_Hexacopter_V2_B.In1_d.manual_lockdown;

  // RateTransition: '<S365>/Rate Transition6' incorporates:
  //   Constant: '<S359>/Constant'
  //   Logic: '<S10>/OR'
  //   RelationalOperator: '<S359>/Compare'

  FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_a =
    (FLIGHT_Hexacopter_V2_B.In1_p.values[9] <=
     FLIGHT_Hexacopter_V2_P.CompareToConstant_const_j) ^
    FLIGHT_Hexacopter_V2_B.In1_d.armed;

  // RateTransition: '<S364>/Rate Transition6' incorporates:
  //   Constant: '<S360>/Constant'
  //   Logic: '<S10>/OR1'
  //   RelationalOperator: '<S360>/Compare'

  FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_i =
    (FLIGHT_Hexacopter_V2_B.In1_p.values[9] <=
     FLIGHT_Hexacopter_V2_P.CompareToConstant1_const_p) ^
    FLIGHT_Hexacopter_V2_B.In1_d.armed;

  // RateTransition: '<S366>/Rate Transition6' incorporates:
  //   Constant: '<S361>/Constant'
  //   Logic: '<S10>/OR2'
  //   RelationalOperator: '<S361>/Compare'

  FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_o =
    (FLIGHT_Hexacopter_V2_B.In1_p.values[9] <=
     FLIGHT_Hexacopter_V2_P.CompareToConstant2_const_p) ^
    FLIGHT_Hexacopter_V2_B.In1_d.armed;

  // MATLABSystem: '<S5>/Read Parameter12'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_jo.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter12_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter12_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter12'

  // RateTransition: '<S365>/Rate Transition2'
  FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter12_o1;

  // MATLABSystem: '<S5>/Read Parameter13'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_pf.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter13_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter13_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter13'

  // RateTransition: '<S364>/Rate Transition'
  FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_c =
    FLIGHT_Hexacopter_V2_B.ReadParameter13_o1;

  // MATLABSystem: '<S5>/Read Parameter14'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_fd.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter14_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter14_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter14'

  // RateTransition: '<S364>/Rate Transition1'
  FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_l =
    FLIGHT_Hexacopter_V2_B.ReadParameter14_o1;

  // MATLABSystem: '<S5>/Read Parameter15'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_nn.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter15_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter15_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter15'

  // RateTransition: '<S364>/Rate Transition2'
  FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_l =
    FLIGHT_Hexacopter_V2_B.ReadParameter15_o1;

  // MATLABSystem: '<S5>/Read Parameter16'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_j.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter16_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter16_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter16'

  // RateTransition: '<S366>/Rate Transition'
  FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_hv =
    FLIGHT_Hexacopter_V2_B.ReadParameter16_o1;

  // MATLABSystem: '<S5>/Read Parameter17'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_d.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter17_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter17_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter17'

  // RateTransition: '<S366>/Rate Transition1'
  FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_m =
    FLIGHT_Hexacopter_V2_B.ReadParameter17_o1;

  // MATLABSystem: '<S5>/Read Parameter18'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_ml.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter18_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter18_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter18'

  // RateTransition: '<S366>/Rate Transition2'
  FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_dg =
    FLIGHT_Hexacopter_V2_B.ReadParameter18_o1;

  // MATLABSystem: '<S5>/Read Parameter19'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_mc.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter19_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter19_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter19'

  // RateTransition: '<S10>/Rate Transition'
  FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_h =
    FLIGHT_Hexacopter_V2_B.ReadParameter19_o1;

  // MATLABSystem: '<S5>/Read Parameter29'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_br.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter29_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter29_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter29'

  // RateTransition: '<S9>/Rate Transition4'
  FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_d =
    FLIGHT_Hexacopter_V2_B.ReadParameter29_o1;

  // MATLABSystem: '<S5>/Read Parameter30'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_mo.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter30_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter30_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter30'

  // RateTransition: '<S9>/Rate Transition5'
  FLIGHT_Hexacopter_V2_DW.RateTransition5_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter30_o1;

  // MATLABSystem: '<S5>/Read Parameter31'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_as.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter31_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter31_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter31'

  // RateTransition: '<S9>/Rate Transition6'
  FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter31_o1;

  // MATLABSystem: '<S5>/Read Parameter32'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_lv.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter32_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter32_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter32'

  // RateTransition: '<S9>/Rate Transition7'
  FLIGHT_Hexacopter_V2_DW.RateTransition7_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter32_o1;

  // MATLABSystem: '<S5>/Read Parameter33'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_bd.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter33_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter33_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter33'

  // RateTransition: '<S9>/Rate Transition8'
  FLIGHT_Hexacopter_V2_DW.RateTransition8_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter33_o1;

  // MATLABSystem: '<S5>/Read Parameter34'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_o.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter34_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter34_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter34'

  // RateTransition: '<S9>/Rate Transition9'
  FLIGHT_Hexacopter_V2_DW.RateTransition9_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter34_o1;

  // MATLABSystem: '<S5>/Read Parameter35'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_b.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter35_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter35_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter35'

  // RateTransition: '<S9>/Rate Transition10'
  FLIGHT_Hexacopter_V2_DW.RateTransition10_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter35_o1;

  // MATLABSystem: '<S5>/Read Parameter36'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_ln.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter36_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter36_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter36'

  // RateTransition: '<S9>/Rate Transition11'
  FLIGHT_Hexacopter_V2_DW.RateTransition11_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter36_o1;

  // MATLABSystem: '<S5>/Read Parameter37'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_pi.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter37_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter37_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter37'

  // RateTransition: '<S9>/Rate Transition12'
  FLIGHT_Hexacopter_V2_DW.RateTransition12_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter37_o1;

  // MATLABSystem: '<S5>/Read Parameter38'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_e.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_c);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_c = 0.0F;
  }

  // Gain: '<S9>/Gain' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter38'
  //
  FLIGHT_Hexacopter_V2_B.ReadParameter37_o1 =
    FLIGHT_Hexacopter_V2_P.Gain_Gain_eb * FLIGHT_Hexacopter_V2_B.ParamStep_c;

  // RateTransition: '<S9>/Rate Transition17'
  FLIGHT_Hexacopter_V2_DW.RateTransition17_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter37_o1;

  // MATLABSystem: '<S5>/Read Parameter41'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_h.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter41_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter41_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter41'

  // RateTransition: '<S9>/Rate Transition13'
  FLIGHT_Hexacopter_V2_DW.RateTransition13_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter41_o1;

  // MATLABSystem: '<S5>/Read Parameter42'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_fy.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter42_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter42_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter42'

  // RateTransition: '<S9>/Rate Transition14'
  FLIGHT_Hexacopter_V2_DW.RateTransition14_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter42_o1;

  // MATLABSystem: '<S5>/Read Parameter8'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_f.MW_PARAMHANDLE,
    MW_SINGLE, &rtb_ReadParameter8_o1);
  if (rtb_flag_pos) {
    rtb_ReadParameter8_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/Read Parameter8'

  // RateTransition: '<S365>/Rate Transition1'
  FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_l4 = rtb_ReadParameter8_o1;

  // MATLABSystem: '<S5>/read_mc_rollrate_p'
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_c.MW_PARAMHANDLE,
    MW_SINGLE, &rtb_read_mc_rollrate_p_o1);
  if (rtb_flag_pos) {
    rtb_read_mc_rollrate_p_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S5>/read_mc_rollrate_p'

  // RateTransition: '<S365>/Rate Transition'
  FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0 = rtb_read_mc_rollrate_p_o1;

  // Update for DiscreteIntegrator: '<S200>/Integrator' incorporates:
  //   MATLABSystem: '<S5>/Read Parameter4'
  //   Product: '<S197>/IProd Out'
  //
  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_l += FLIGHT_Hexacopter_V2_B.roll_g *
    FLIGHT_Hexacopter_V2_B.ParamStep *
    FLIGHT_Hexacopter_V2_P.Integrator_gainval_e;
  FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_l = static_cast<int8_T>
    (rtb_AND);

  // Update for UnitDelay: '<S164>/Unit Delay1'
  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i = FLIGHT_Hexacopter_V2_B.q_c;

  // Update for UnitDelay: '<S161>/UD'
  //
  //  Block description for '<S161>/UD':
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_a = FLIGHT_Hexacopter_V2_B.TSamp_k;

  // Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE_c +=
    FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_gainva_h *
    FLIGHT_Hexacopter_V2_B.Gain8;
  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRe_l = static_cast<int8_T>
    (rtb_AND1);

  // Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE +=
    FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator1_gainval *
    FLIGHT_Hexacopter_V2_B.ParamStep_k;
  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_PrevRes = static_cast<int8_T>
    (rtb_AND2);
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
    static const char_T ParameterNameStr_5[17] = "MPC_Z_VEL_MAX_UP";
    static const char_T ParameterNameStr_6[16] = "MPC_Z_VEL_P_ACC";
    static const char_T ParameterNameStr_7[16] = "MPC_Z_VEL_D_ACC";
    static const char_T ParameterNameStr_8[17] = "IMU_DGYRO_CUTOFF";
    static const char_T ParameterNameStr_9[14] = "MPC_THR_HOVER";
    static const char_T ParameterNameStr_a[17] = "MPC_XY_VEL_P_ACC";
    static const char_T ParameterNameStr_b[9] = "MPC_XY_P";
    static const char_T ParameterNameStr_c[15] = "MPC_XY_VEL_MAX";
    static const char_T ParameterNameStr_d[17] = "DOUBLET_PEAK_ANG";
    static const char_T ParameterNameStr_e[11] = "DOUBLET_DT";
    static const char_T ParameterNameStr_f[13] = "DOUBLET_AXIS";
    static const char_T ParameterNameStr_g[16] = "MC_ROLLRATE_MAX";
    static const char_T ParameterNameStr_h[10] = "MC_ROLL_P";
    static const char_T ParameterNameStr_i[17] = "MC_PITCHRATE_MAX";
    static const char_T ParameterNameStr_j[11] = "MC_PITCH_P";
    static const char_T ParameterNameStr_k[16] = "MPC_Z_VEL_I_ACC";
    static const char_T ParameterNameStr_l[14] = "MC_ROLLRATE_D";
    static const char_T ParameterNameStr_m[15] = "MC_PITCHRATE_P";
    static const char_T ParameterNameStr_n[15] = "MC_PITCHRATE_I";
    static const char_T ParameterNameStr_o[15] = "MC_PITCHRATE_D";
    static const char_T ParameterNameStr_p[13] = "MC_YAWRATE_P";
    static const char_T ParameterNameStr_q[13] = "MC_YAWRATE_I";
    static const char_T ParameterNameStr_r[13] = "MC_YAWRATE_D";
    static const char_T ParameterNameStr_s[14] = "MC_YAWRATE_FF";
    static const char_T ParameterNameStr_t[11] = "SMC_K_SS_P";
    static const char_T ParameterNameStr_u[11] = "SMC_K_SS_I";
    static const char_T ParameterNameStr_v[11] = "SMC_K_SS_D";
    static const char_T ParameterNameStr_w[14] = "SMC_K_REACH_S";
    static const char_T ParameterNameStr_x[14] = "SMC_K_REACH_P";
    static const char_T ParameterNameStr_y[9] = "SMC_I_XX";
    static const char_T ParameterNameStr_z[9] = "SMC_I_YY";
    static const char_T ParameterNameStr_10[9] = "SMC_I_ZZ";
    static const char_T ParameterNameStr_11[12] = "SMC_EPSILON";
    static const char_T ParameterNameStr_12[15] = "SMC_LPF_CUTOFF";
    static const char_T ParameterNameStr_13[14] = "ST_SMC_LAMBDA";
    static const char_T ParameterNameStr_14[11] = "ST_SMC_ETA";
    static const char_T ParameterNameStr_15[14] = "MC_ROLLRATE_I";
    static const char_T ParameterNameStr_16[14] = "MC_ROLLRATE_P";

    // Start for RateTransition: '<S10>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4 =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialConditio;

    // Start for RateTransition: '<S365>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.RateTransition =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialCondition;

    // Start for RateTransition: '<S365>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4_a =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialCondit_l;

    // Start for RateTransition: '<S365>/Rate Transition6'
    FLIGHT_Hexacopter_V2_B.RateTransition6_h =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialCondit_j;

    // Start for RateTransition: '<S365>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.RateTransition2 =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialConditio;

    // Start for RateTransition: '<S365>/Rate Transition3'
    FLIGHT_Hexacopter_V2_B.RateTransition3 =
      FLIGHT_Hexacopter_V2_P.RateTransition3_InitialConditio;

    // Start for RateTransition generated from: '<Root>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.rc_ctrl_switch =
      FLIGHT_Hexacopter_V2_P.RateTransition_8_InitialConditi;

    // Start for RateTransition: '<S9>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.RateTransition2_a[0] =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_h;
    FLIGHT_Hexacopter_V2_B.RateTransition2_a[1] =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_h;
    FLIGHT_Hexacopter_V2_B.RateTransition2_a[2] =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_h;

    // Start for RateTransition: '<S9>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4_l =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialCondit_m;

    // Start for RateTransition: '<S9>/Rate Transition5'
    FLIGHT_Hexacopter_V2_B.RateTransition5 =
      FLIGHT_Hexacopter_V2_P.RateTransition5_InitialConditio;

    // Start for RateTransition: '<S9>/Rate Transition6'
    FLIGHT_Hexacopter_V2_B.RateTransition6 =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialConditio;

    // Start for RateTransition: '<S9>/Rate Transition9'
    FLIGHT_Hexacopter_V2_B.RateTransition9 =
      FLIGHT_Hexacopter_V2_P.RateTransition9_InitialConditio;

    // Start for RateTransition: '<S9>/Rate Transition10'
    FLIGHT_Hexacopter_V2_B.RateTransition10 =
      FLIGHT_Hexacopter_V2_P.RateTransition10_InitialConditi;

    // Start for RateTransition: '<S9>/Rate Transition11'
    FLIGHT_Hexacopter_V2_B.RateTransition11 =
      FLIGHT_Hexacopter_V2_P.RateTransition11_InitialConditi;

    // Start for RateTransition: '<S9>/Rate Transition17'
    FLIGHT_Hexacopter_V2_B.RateTransition17 =
      FLIGHT_Hexacopter_V2_P.RateTransition17_InitialConditi;

    // Start for RateTransition: '<S9>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1 =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialConditio;

    // Start for RateTransition: '<S9>/Rate Transition16'
    FLIGHT_Hexacopter_V2_B.RateTransition16 =
      FLIGHT_Hexacopter_V2_P.RateTransition16_InitialConditi;

    // Start for RateTransition: '<S9>/Rate Transition7'
    FLIGHT_Hexacopter_V2_B.RateTransition7 =
      FLIGHT_Hexacopter_V2_P.RateTransition7_InitialConditio;

    // Start for RateTransition: '<S9>/Rate Transition8'
    FLIGHT_Hexacopter_V2_B.RateTransition8 =
      FLIGHT_Hexacopter_V2_P.RateTransition8_InitialConditio;

    // Start for RateTransition: '<S9>/Rate Transition12'
    FLIGHT_Hexacopter_V2_B.RateTransition12 =
      FLIGHT_Hexacopter_V2_P.RateTransition12_InitialConditi;

    // Start for RateTransition: '<S9>/Rate Transition13'
    FLIGHT_Hexacopter_V2_B.RateTransition13 =
      FLIGHT_Hexacopter_V2_P.RateTransition13_InitialConditi;

    // Start for RateTransition: '<S9>/Rate Transition14'
    FLIGHT_Hexacopter_V2_B.RateTransition14 =
      FLIGHT_Hexacopter_V2_P.RateTransition14_InitialConditi;

    // Start for RateTransition: '<S9>/Rate Transition15'
    FLIGHT_Hexacopter_V2_B.RateTransition15 =
      FLIGHT_Hexacopter_V2_P.RateTransition15_InitialConditi;

    // Start for RateTransition: '<S364>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.RateTransition_e =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialConditi_n;

    // Start for RateTransition: '<S364>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4_b =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialCondit_d;

    // Start for RateTransition: '<S364>/Rate Transition6'
    FLIGHT_Hexacopter_V2_B.RateTransition6_a =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialCondit_l;

    // Start for RateTransition: '<S364>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.RateTransition2_b =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_p;

    // Start for RateTransition: '<S364>/Rate Transition3'
    FLIGHT_Hexacopter_V2_B.RateTransition3_b =
      FLIGHT_Hexacopter_V2_P.RateTransition3_InitialCondit_m;

    // Start for RateTransition: '<S10>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.RateTransition_j =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialConditi_c;

    // Start for RateTransition: '<S10>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1_a =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialCondit_e;

    // Start for RateTransition: '<S366>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.RateTransition_f =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialConditi_m;

    // Start for RateTransition: '<S366>/Rate Transition4'
    FLIGHT_Hexacopter_V2_B.RateTransition4_ar =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialCondit_a;

    // Start for RateTransition: '<S366>/Rate Transition6'
    FLIGHT_Hexacopter_V2_B.RateTransition6_o =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialCondit_e;

    // Start for RateTransition: '<S366>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.RateTransition2_d =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_d;

    // Start for RateTransition: '<S366>/Rate Transition3'
    FLIGHT_Hexacopter_V2_B.RateTransition3_e =
      FLIGHT_Hexacopter_V2_P.RateTransition3_InitialCondit_o;

    // Start for RateTransition generated from: '<Root>/Rate Transition'
    FLIGHT_Hexacopter_V2_B.rc_inject_failure =
      FLIGHT_Hexacopter_V2_P.RateTransition_4_InitialConditi;

    // Start for RateTransition generated from: '<Root>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.VehicleStatus_flag_armed =
      FLIGHT_Hexacopter_V2_P.RateTransition2_16_InitialCondi;

    // Start for RateTransition generated from: '<Root>/Rate Transition2'
    FLIGHT_Hexacopter_V2_B.VehicleStatus_flag_kill =
      FLIGHT_Hexacopter_V2_P.RateTransition2_17_InitialCondi;

    // Start for RateTransition: '<S366>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1_c =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialCondit_d;

    // Start for RateTransition: '<S364>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1_d =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialCondit_f;

    // Start for RateTransition: '<S365>/Rate Transition1'
    FLIGHT_Hexacopter_V2_B.RateTransition1_o =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialCondit_p;

    // InitializeConditions for RateTransition: '<S10>/Rate Transition4'
    FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialConditio;

    // InitializeConditions for RateTransition: '<S365>/Rate Transition'
    FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialCondition;

    // InitializeConditions for RateTransition: '<S365>/Rate Transition4'
    FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_e =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialCondit_l;

    // InitializeConditions for RateTransition: '<S365>/Rate Transition6'
    FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_a =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialCondit_j;

    // InitializeConditions for DiscreteIntegrator: '<S569>/Integrator'
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCondit;
    FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState = 2;

    // InitializeConditions for RateTransition: '<S365>/Rate Transition2'
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialConditio;

    // InitializeConditions for UnitDelay: '<S533>/Unit Delay1'
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE =
      FLIGHT_Hexacopter_V2_P.UnitDelay1_InitialCondition;

    // InitializeConditions for RateTransition: '<S365>/Rate Transition3'
    FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition3_InitialConditio;

    // InitializeConditions for UnitDelay: '<S530>/UD'
    //
    //  Block description for '<S530>/UD':
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevScale;

    // InitializeConditions for RateTransition generated from: '<Root>/Rate Transition' 
    FLIGHT_Hexacopter_V2_DW.RateTransition_8_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition_8_InitialConditi;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition2'
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[0] =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_h;

    // InitializeConditions for UnitDelay: '<S243>/UD' incorporates:
    //   Sum: '<S243>/Diff'
    //
    //  Block description for '<S243>/UD':
    //
    //   Store in Global RAM
    //
    //  Block description for '<S243>/Diff':
    //
    //   Add in CPU

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[0] =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevSca_e;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition2'
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[1] =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_h;

    // InitializeConditions for UnitDelay: '<S243>/UD' incorporates:
    //   Sum: '<S243>/Diff'
    //
    //  Block description for '<S243>/UD':
    //
    //   Store in Global RAM
    //
    //  Block description for '<S243>/Diff':
    //
    //   Add in CPU

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[1] =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevSca_e;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition2'
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[2] =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_h;

    // InitializeConditions for UnitDelay: '<S243>/UD' incorporates:
    //   Sum: '<S243>/Diff'
    //
    //  Block description for '<S243>/UD':
    //
    //   Store in Global RAM
    //
    //  Block description for '<S243>/Diff':
    //
    //   Add in CPU

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[2] =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevSca_e;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition4'
    FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_d =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialCondit_m;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition5'
    FLIGHT_Hexacopter_V2_DW.RateTransition5_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition5_InitialConditio;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition6'
    FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialConditio;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition9'
    FLIGHT_Hexacopter_V2_DW.RateTransition9_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition9_InitialConditio;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition10'
    FLIGHT_Hexacopter_V2_DW.RateTransition10_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition10_InitialConditi;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition11'
    FLIGHT_Hexacopter_V2_DW.RateTransition11_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition11_InitialConditi;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition17'
    FLIGHT_Hexacopter_V2_DW.RateTransition17_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition17_InitialConditi;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition1'
    FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialConditio;

    // InitializeConditions for UnitDelay: '<S357>/Unit Delay'
    FLIGHT_Hexacopter_V2_DW.UnitDelay_DSTATE =
      FLIGHT_Hexacopter_V2_P.UnitDelay_InitialCondition;

    // InitializeConditions for UnitDelay: '<S241>/UD'
    //
    //  Block description for '<S241>/UD':
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_o =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for UnitDelay: '<S242>/UD'
    //
    //  Block description for '<S242>/UD':
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_e =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative1_ICPrevScale;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition16'
    FLIGHT_Hexacopter_V2_DW.RateTransition16_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition16_InitialConditi;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition7'
    FLIGHT_Hexacopter_V2_DW.RateTransition7_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition7_InitialConditio;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition8'
    FLIGHT_Hexacopter_V2_DW.RateTransition8_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition8_InitialConditio;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition12'
    FLIGHT_Hexacopter_V2_DW.RateTransition12_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition12_InitialConditi;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition13'
    FLIGHT_Hexacopter_V2_DW.RateTransition13_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition13_InitialConditi;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition14'
    FLIGHT_Hexacopter_V2_DW.RateTransition14_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition14_InitialConditi;

    // InitializeConditions for DiscreteIntegrator: '<S282>/Filter'
    FLIGHT_Hexacopter_V2_DW.Filter_DSTATE =
      FLIGHT_Hexacopter_V2_P.DiscretePIDController1_InitialC;

    // InitializeConditions for RateTransition: '<S9>/Rate Transition15'
    FLIGHT_Hexacopter_V2_DW.RateTransition15_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition15_InitialConditi;

    // InitializeConditions for DiscreteIntegrator: '<S339>/Integrator'
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_h =
      FLIGHT_Hexacopter_V2_P.DiscretePIDController2_InitialC;
    FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_h = 2;

    // InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' 
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE =
      FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_IC;
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRese = 2;

    // InitializeConditions for RateTransition: '<S364>/Rate Transition'
    FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_c =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialConditi_n;

    // InitializeConditions for RateTransition: '<S364>/Rate Transition4'
    FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_k =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialCondit_d;

    // InitializeConditions for RateTransition: '<S364>/Rate Transition6'
    FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_i =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialCondit_l;

    // InitializeConditions for DiscreteIntegrator: '<S512>/Integrator'
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_c =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCond_l;
    FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_hx = 2;

    // InitializeConditions for RateTransition: '<S364>/Rate Transition2'
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_l =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_p;

    // InitializeConditions for UnitDelay: '<S476>/Unit Delay1'
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_k =
      FLIGHT_Hexacopter_V2_P.UnitDelay1_InitialCondition_h;

    // InitializeConditions for RateTransition: '<S364>/Rate Transition3'
    FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0_p =
      FLIGHT_Hexacopter_V2_P.RateTransition3_InitialCondit_m;

    // InitializeConditions for UnitDelay: '<S473>/UD'
    //
    //  Block description for '<S473>/UD':
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_oi =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevSca_k;

    // InitializeConditions for RateTransition: '<S10>/Rate Transition'
    FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_h =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialConditi_c;

    // InitializeConditions for RateTransition: '<S10>/Rate Transition1'
    FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_g =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialCondit_e;

    // InitializeConditions for RateTransition: '<S366>/Rate Transition'
    FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0_hv =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialConditi_m;

    // InitializeConditions for RateTransition: '<S366>/Rate Transition4'
    FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_c =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialCondit_a;

    // InitializeConditions for RateTransition: '<S366>/Rate Transition6'
    FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_o =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialCondit_e;

    // InitializeConditions for DiscreteIntegrator: '<S626>/Integrator'
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_o =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCond_p;
    FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_hd = 2;

    // InitializeConditions for RateTransition: '<S366>/Rate Transition2'
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_dg =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_d;

    // InitializeConditions for UnitDelay: '<S590>/Unit Delay1'
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_kh =
      FLIGHT_Hexacopter_V2_P.UnitDelay1_InitialCondition_c;

    // InitializeConditions for RateTransition: '<S366>/Rate Transition3'
    FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0_d =
      FLIGHT_Hexacopter_V2_P.RateTransition3_InitialCondit_o;

    // InitializeConditions for UnitDelay: '<S587>/UD'
    //
    //  Block description for '<S587>/UD':
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

    // InitializeConditions for UnitDelay: '<S590>/Unit Delay2'
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE =
      FLIGHT_Hexacopter_V2_P.UnitDelay2_InitialCondition;

    // InitializeConditions for RateTransition: '<S366>/Rate Transition1'
    FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_m =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialCondit_d;

    // InitializeConditions for UnitDelay: '<S476>/Unit Delay2'
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_l =
      FLIGHT_Hexacopter_V2_P.UnitDelay2_InitialCondition_b;

    // InitializeConditions for RateTransition: '<S364>/Rate Transition1'
    FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_l =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialCondit_f;

    // InitializeConditions for UnitDelay: '<S533>/Unit Delay2'
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_h =
      FLIGHT_Hexacopter_V2_P.UnitDelay2_InitialCondition_e;

    // InitializeConditions for RateTransition: '<S365>/Rate Transition1'
    FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_l4 =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialCondit_p;

    // InitializeConditions for DiscreteIntegrator: '<S200>/Integrator'
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_l =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCon_pr;
    FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_l = 2;

    // InitializeConditions for UnitDelay: '<S164>/Unit Delay1'
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i =
      FLIGHT_Hexacopter_V2_P.UnitDelay1_InitialCondition_e;

    // InitializeConditions for UnitDelay: '<S161>/UD'
    //
    //  Block description for '<S161>/UD':
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_a =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevSca_n;

    // InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' 
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRe_l = 2;
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' 
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_PrevRes = 2;
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;

    // InitializeConditions for RateLimiter: '<S4>/Rate Limiter'
    FLIGHT_Hexacopter_V2_DW.PrevY[0] = FLIGHT_Hexacopter_V2_P.RateLimiter_IC;
    FLIGHT_Hexacopter_V2_DW.PrevY[1] = FLIGHT_Hexacopter_V2_P.RateLimiter_IC;

    // InitializeConditions for UnitDelay: '<S164>/Unit Delay2'
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_f =
      FLIGHT_Hexacopter_V2_P.UnitDelay2_InitialCondition_m;

    // SystemInitialize for MATLAB Function: '<S4>/MATLAB Function1'
    FLIGHT_Hexacopter_V2_DW.start_time_usec = -1.0;

    // SystemInitialize for Enabled SubSystem: '<S221>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S222>/In1' incorporates:
    //   Outport: '<S222>/Out1'

    FLIGHT_Hexacopter_V2_B.In1_p = FLIGHT_Hexacopter_V2_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S221>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S223>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S224>/In1' incorporates:
    //   Outport: '<S224>/Out1'

    FLIGHT_Hexacopter_V2_B.In1_k = FLIGHT_Hexacopter_V2_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S223>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S226>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S232>/In1' incorporates:
    //   Outport: '<S232>/Out1'

    FLIGHT_Hexacopter_V2_B.In1_e = FLIGHT_Hexacopter_V2_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S226>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S227>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S233>/In1' incorporates:
    //   Outport: '<S233>/Out1'

    FLIGHT_Hexacopter_V2_B.In1_m = FLIGHT_Hexacopter_V2_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S227>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S228>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S234>/In1' incorporates:
    //   Outport: '<S234>/Out1'

    FLIGHT_Hexacopter_V2_B.In1 = FLIGHT_Hexacopter_V2_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S228>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S229>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S235>/In1' incorporates:
    //   Outport: '<S235>/Out1'

    FLIGHT_Hexacopter_V2_B.In1_d = FLIGHT_Hexacopter_V2_P.Out1_Y0_g;

    // End of SystemInitialize for SubSystem: '<S229>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S236>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S237>/In1' incorporates:
    //   Outport: '<S237>/Out1'

    FLIGHT_Hexacopter_V2_B.In1_b = FLIGHT_Hexacopter_V2_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S236>/Enabled Subsystem'

    // Start for MATLABSystem: '<S223>/SourceBlock'
    FLIGHT_Hexacopter_V2_DW.obj_m.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_m.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_m.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_m.orbMetadataObj = ORB_ID
      (vehicle_angular_velocity);
    uORB_read_initialize(FLIGHT_Hexacopter_V2_DW.obj_m.orbMetadataObj,
                         &FLIGHT_Hexacopter_V2_DW.obj_m.eventStructObj);
    FLIGHT_Hexacopter_V2_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter13'
    FLIGHT_Hexacopter_V2_DW.obj_oe.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_oe.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_oe.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr[0], true, 1.0);
    FLIGHT_Hexacopter_V2_DW.obj_oe.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter1'
    FLIGHT_Hexacopter_V2_DW.obj_aw.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_aw.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_aw.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, 1.0);
    FLIGHT_Hexacopter_V2_DW.obj_aw.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter2'
    FLIGHT_Hexacopter_V2_DW.obj_ps.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ps.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_ps.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1[0], true, 1.0);
    FLIGHT_Hexacopter_V2_DW.obj_ps.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter3'
    FLIGHT_Hexacopter_V2_DW.obj_hi.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_hi.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_hi.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, 1.0);
    FLIGHT_Hexacopter_V2_DW.obj_hi.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter4'
    FLIGHT_Hexacopter_V2_DW.obj_jg.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_jg.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_jg.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, 1.0);
    FLIGHT_Hexacopter_V2_DW.obj_jg.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter5'
    FLIGHT_Hexacopter_V2_DW.obj_ic5.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ic5.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_ic5.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, 1.0);
    FLIGHT_Hexacopter_V2_DW.obj_ic5.isSetupComplete = true;

    // Start for MATLABSystem: '<S1>/PX4 PWM Output'
    FLIGHT_Hexacopter_V2_DW.obj_md.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_md.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_md.isInitialized = 1;
    FLIGHT_Hexacopter_PWM_setupImpl(&FLIGHT_Hexacopter_V2_DW.obj_md, false,
      false);
    FLIGHT_Hexacopter_V2_DW.obj_md.isSetupComplete = true;
    FLIGHT_He_PX4Timestamp_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_pn);

    // Start for MATLABSystem: '<S38>/SinkBlock' incorporates:
    //   BusAssignment: '<S28>/Bus Assignment'

    FLIGHT_Hexacopter_V2_DW.obj_k.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_k.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_k.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_k.orbMetadataObj = ORB_ID
      (vehicle_attitude_smc_setpoint);
    uORB_write_initialize(FLIGHT_Hexacopter_V2_DW.obj_k.orbMetadataObj,
                          &FLIGHT_Hexacopter_V2_DW.obj_k.orbAdvertiseObj,
                          &FLIGHT_Hexacopter_V2_B.BusAssignment, 1);
    FLIGHT_Hexacopter_V2_DW.obj_k.isSetupComplete = true;
    FLIGHT__PX4Timestamp_o_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_e);
    FLIGHT_He_PX4Timestamp_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp);

    // Start for MATLABSystem: '<S40>/SinkBlock' incorporates:
    //   BusAssignment: '<S29>/Bus Assignment'

    FLIGHT_Hexacopter_V2_DW.obj_nf.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_nf.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_nf.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_nf.orbMetadataObj = ORB_ID(actuator_motors);
    uORB_write_initialize(FLIGHT_Hexacopter_V2_DW.obj_nf.orbMetadataObj,
                          &FLIGHT_Hexacopter_V2_DW.obj_nf.orbAdvertiseObj,
                          &FLIGHT_Hexacopter_V2_B.BusAssignment_e, 1);
    FLIGHT_Hexacopter_V2_DW.obj_nf.isSetupComplete = true;
    FLIGHT__PX4Timestamp_o_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_c);

    // Start for MATLABSystem: '<S32>/SinkBlock' incorporates:
    //   BusAssignment: '<S24>/Bus Assignment'

    FLIGHT_Hexacopter_V2_DW.obj_fe.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_fe.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_fe.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_fe.orbMetadataObj = ORB_ID
      (actuator_controls_status_0);
    uORB_write_initialize(FLIGHT_Hexacopter_V2_DW.obj_fe.orbMetadataObj,
                          &FLIGHT_Hexacopter_V2_DW.obj_fe.orbAdvertiseObj,
                          &FLIGHT_Hexacopter_V2_B.BusAssignment_j, 1);
    FLIGHT_Hexacopter_V2_DW.obj_fe.isSetupComplete = true;

    // Start for MATLABSystem: '<S228>/SourceBlock'
    FLIGHT_Hexacopter_V2_DW.obj_l.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_l.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_l.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_l.orbMetadataObj = ORB_ID(vehicle_local_position);
    uORB_read_initialize(FLIGHT_Hexacopter_V2_DW.obj_l.orbMetadataObj,
                         &FLIGHT_Hexacopter_V2_DW.obj_l.eventStructObj);
    FLIGHT_Hexacopter_V2_DW.obj_l.isSetupComplete = true;

    // Start for MATLABSystem: '<S221>/SourceBlock'
    FLIGHT_Hexacopter_V2_DW.obj_n.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_n.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_n.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_n.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(FLIGHT_Hexacopter_V2_DW.obj_n.orbMetadataObj,
                         &FLIGHT_Hexacopter_V2_DW.obj_n.eventStructObj);
    FLIGHT_Hexacopter_V2_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter39'
    FLIGHT_Hexacopter_V2_DW.obj_g.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_g.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_g.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter3'
    FLIGHT_Hexacopter_V2_DW.obj_c4.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_c4.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_c4.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_6[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_c4.isSetupComplete = true;
    FLIGHT_Hex_SourceBlock_Init(&FLIGHT_Hexacopter_V2_DW.SourceBlock_l);

    // Start for MATLABSystem: '<S5>/Read Parameter5'
    FLIGHT_Hexacopter_V2_DW.obj_ia.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ia.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_ia.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_7[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_ia.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter11'
    FLIGHT_Hexacopter_V2_DW.obj_jk.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_jk.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_jk.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_8[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_jk.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter26'
    FLIGHT_Hexacopter_V2_DW.obj_lt.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_lt.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_lt.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_9[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_lt.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter28'
    FLIGHT_Hexacopter_V2_DW.obj_ic.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ic.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_ic.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_a[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_ic.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter27'
    FLIGHT_Hexacopter_V2_DW.obj_l3.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_l3.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_l3.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_b[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_l3.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter40'
    FLIGHT_Hexacopter_V2_DW.obj_pn.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_pn.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_pn.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_c[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_pn.isSetupComplete = true;

    // Start for MATLABSystem: '<S227>/SourceBlock'
    FLIGHT_Hexacopter_V2_DW.obj_a.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_a.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_a.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_a.orbMetadataObj = ORB_ID(vehicle_status);
    uORB_read_initialize(FLIGHT_Hexacopter_V2_DW.obj_a.orbMetadataObj,
                         &FLIGHT_Hexacopter_V2_DW.obj_a.eventStructObj);
    FLIGHT_Hexacopter_V2_DW.obj_a.isSetupComplete = true;

    // Start for MATLABSystem: '<S236>/SourceBlock'
    FLIGHT_Hexacopter_V2_DW.obj_i.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_i.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_i.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_i.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(FLIGHT_Hexacopter_V2_DW.obj_i.orbMetadataObj,
                         &FLIGHT_Hexacopter_V2_DW.obj_i.eventStructObj);
    FLIGHT_Hexacopter_V2_DW.obj_i.isSetupComplete = true;

    // Start for MATLABSystem: '<S4>/PX4 Timestamp'
    FLIGHT_Hexacopter_V2_DW.obj.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter1'
    FLIGHT_Hexacopter_V2_DW.obj_l4.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_l4.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_l4.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_d[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_l4.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter'
    FLIGHT_Hexacopter_V2_DW.obj_jf.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_jf.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_jf.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_e[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_jf.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter2'
    FLIGHT_Hexacopter_V2_DW.obj_a1.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_a1.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_a1.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_f[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_a1.isSetupComplete = true;
    FLIGHT__PX4Timestamp_c_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_j);

    // Start for MATLABSystem: '<S34>/SinkBlock' incorporates:
    //   BusAssignment: '<S25>/Bus Assignment'

    FLIGHT_Hexacopter_V2_DW.obj_m1.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_m1.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_m1.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_m1.orbMetadataObj = ORB_ID
      (vehicle_attitude_setpoint);
    uORB_write_initialize(FLIGHT_Hexacopter_V2_DW.obj_m1.orbMetadataObj,
                          &FLIGHT_Hexacopter_V2_DW.obj_m1.orbAdvertiseObj,
                          &FLIGHT_Hexacopter_V2_B.BusAssignment_f, 1);
    FLIGHT_Hexacopter_V2_DW.obj_m1.isSetupComplete = true;
    FLIGHT__PX4Timestamp_c_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_p);

    // Start for MATLABSystem: '<S5>/Read Parameter9'
    FLIGHT_Hexacopter_V2_DW.obj_ai.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ai.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_ai.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_g[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_ai.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter6'
    FLIGHT_Hexacopter_V2_DW.obj_p.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_p.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_h[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_p.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter10'
    FLIGHT_Hexacopter_V2_DW.obj_bq.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_bq.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_bq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_i[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_bq.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter7'
    FLIGHT_Hexacopter_V2_DW.obj_fj.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_fj.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_fj.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_j[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_fj.isSetupComplete = true;

    // Start for MATLABSystem: '<S36>/SinkBlock' incorporates:
    //   BusAssignment: '<S26>/Bus Assignment'

    FLIGHT_Hexacopter_V2_DW.obj_mp.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_mp.isSetupComplete = false;
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
    FLIGHT_Hexacopter_V2_DW.obj_pm.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_pm.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_pm.orbMetadataObj = ORB_ID
      (vehicle_local_position_setpoint);
    uORB_write_initialize(FLIGHT_Hexacopter_V2_DW.obj_pm.orbMetadataObj,
                          &FLIGHT_Hexacopter_V2_DW.obj_pm.orbAdvertiseObj,
                          &FLIGHT_Hexacopter_V2_B.BusAssignment_g, 1);
    FLIGHT_Hexacopter_V2_DW.obj_pm.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter4'
    FLIGHT_Hexacopter_V2_DW.obj_c1.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_c1.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_c1.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_k[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_c1.isSetupComplete = true;
    FLIGHT_Hex_SourceBlock_Init(&FLIGHT_Hexacopter_V2_DW.SourceBlock_p);

    // Start for MATLABSystem: '<S5>/Read Parameter12'
    FLIGHT_Hexacopter_V2_DW.obj_jo.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_jo.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_jo.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_l[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_jo.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter13'
    FLIGHT_Hexacopter_V2_DW.obj_pf.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_pf.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_pf.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_m[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_pf.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter14'
    FLIGHT_Hexacopter_V2_DW.obj_fd.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_fd.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_fd.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_n[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_fd.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter15'
    FLIGHT_Hexacopter_V2_DW.obj_nn.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_nn.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_nn.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_o[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_nn.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter16'
    FLIGHT_Hexacopter_V2_DW.obj_j.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_j.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_j.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_p[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter17'
    FLIGHT_Hexacopter_V2_DW.obj_d.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_d.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_q[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter18'
    FLIGHT_Hexacopter_V2_DW.obj_ml.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ml.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_ml.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_r[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_ml.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter19'
    FLIGHT_Hexacopter_V2_DW.obj_mc.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_mc.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_mc.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_s[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_mc.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter29'
    FLIGHT_Hexacopter_V2_DW.obj_br.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_br.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_br.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_t[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_br.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter30'
    FLIGHT_Hexacopter_V2_DW.obj_mo.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_mo.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_mo.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_u[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_mo.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter31'
    FLIGHT_Hexacopter_V2_DW.obj_as.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_as.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_as.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_v[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_as.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter32'
    FLIGHT_Hexacopter_V2_DW.obj_lv.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_lv.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_lv.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_w[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_lv.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter33'
    FLIGHT_Hexacopter_V2_DW.obj_bd.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_bd.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_bd.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_x[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_bd.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter34'
    FLIGHT_Hexacopter_V2_DW.obj_o.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_o.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_o.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_y[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter35'
    FLIGHT_Hexacopter_V2_DW.obj_b.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_b.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_z[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_b.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter36'
    FLIGHT_Hexacopter_V2_DW.obj_ln.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ln.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_ln.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_10[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_ln.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter37'
    FLIGHT_Hexacopter_V2_DW.obj_pi.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_pi.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_pi.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_11[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_pi.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter38'
    FLIGHT_Hexacopter_V2_DW.obj_e.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_e.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_e.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_12[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter41'
    FLIGHT_Hexacopter_V2_DW.obj_h.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_h.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_h.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_13[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter42'
    FLIGHT_Hexacopter_V2_DW.obj_fy.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_fy.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_fy.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_14[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_fy.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter8'
    FLIGHT_Hexacopter_V2_DW.obj_f.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_f.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_f.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_15[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_f.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/read_mc_rollrate_p'
    FLIGHT_Hexacopter_V2_DW.obj_c.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_c.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_c.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_16[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_c.isSetupComplete = true;
  }
}

// Model terminate function
void FLIGHT_Hexacopter_V2_terminate(void)
{
  // Terminate for MATLABSystem: '<S223>/SourceBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_m.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_m.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_m.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_V2_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S223>/SourceBlock'

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
  if (!FLIGHT_Hexacopter_V2_DW.obj_hi.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_hi.matlabCodegenIsDeleted = true;
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
  FLIGHT_He_PX4Timestamp_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_pn);

  // Terminate for MATLABSystem: '<S38>/SinkBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_k.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_k.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_k.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_Hexacopter_V2_DW.obj_k.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S38>/SinkBlock'
  FLIGHT__PX4Timestamp_p_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_e);
  FLIGHT_He_PX4Timestamp_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp);

  // Terminate for MATLABSystem: '<S40>/SinkBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_nf.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_nf.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_nf.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_nf.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_Hexacopter_V2_DW.obj_nf.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S40>/SinkBlock'
  FLIGHT__PX4Timestamp_p_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_c);

  // Terminate for MATLABSystem: '<S32>/SinkBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_fe.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_fe.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_fe.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_fe.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_Hexacopter_V2_DW.obj_fe.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S32>/SinkBlock'

  // Terminate for MATLABSystem: '<S228>/SourceBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_l.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_l.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_V2_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S228>/SourceBlock'

  // Terminate for MATLABSystem: '<S221>/SourceBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_n.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_n.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_n.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_V2_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S221>/SourceBlock'

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
  if (!FLIGHT_Hexacopter_V2_DW.obj_ia.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_ia.matlabCodegenIsDeleted = true;
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

  // Terminate for MATLABSystem: '<S5>/Read Parameter40'
  if (!FLIGHT_Hexacopter_V2_DW.obj_pn.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_pn.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter40'

  // Terminate for MATLABSystem: '<S227>/SourceBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_a.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_a.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_a.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_V2_DW.obj_a.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S227>/SourceBlock'

  // Terminate for MATLABSystem: '<S236>/SourceBlock'
  if (!FLIGHT_Hexacopter_V2_DW.obj_i.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_i.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_i.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_V2_DW.obj_i.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S236>/SourceBlock'

  // Terminate for MATLABSystem: '<S4>/PX4 Timestamp'
  if (!FLIGHT_Hexacopter_V2_DW.obj.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/PX4 Timestamp'

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
  if (!FLIGHT_Hexacopter_V2_DW.obj_ai.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_ai.matlabCodegenIsDeleted = true;
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

  // Terminate for MATLABSystem: '<S5>/Read Parameter4'
  if (!FLIGHT_Hexacopter_V2_DW.obj_c1.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_c1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter4'
  FLIGHT_Hex_SourceBlock_Term(&FLIGHT_Hexacopter_V2_DW.SourceBlock_p);

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
  if (!FLIGHT_Hexacopter_V2_DW.obj_nn.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_nn.matlabCodegenIsDeleted = true;
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

  // Terminate for MATLABSystem: '<S5>/Read Parameter29'
  if (!FLIGHT_Hexacopter_V2_DW.obj_br.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_br.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter29'

  // Terminate for MATLABSystem: '<S5>/Read Parameter30'
  if (!FLIGHT_Hexacopter_V2_DW.obj_mo.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_mo.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter30'

  // Terminate for MATLABSystem: '<S5>/Read Parameter31'
  if (!FLIGHT_Hexacopter_V2_DW.obj_as.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_as.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter31'

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
  if (!FLIGHT_Hexacopter_V2_DW.obj_ln.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_ln.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter36'

  // Terminate for MATLABSystem: '<S5>/Read Parameter37'
  if (!FLIGHT_Hexacopter_V2_DW.obj_pi.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_pi.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter37'

  // Terminate for MATLABSystem: '<S5>/Read Parameter38'
  if (!FLIGHT_Hexacopter_V2_DW.obj_e.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter38'

  // Terminate for MATLABSystem: '<S5>/Read Parameter41'
  if (!FLIGHT_Hexacopter_V2_DW.obj_h.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter41'

  // Terminate for MATLABSystem: '<S5>/Read Parameter42'
  if (!FLIGHT_Hexacopter_V2_DW.obj_fy.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_fy.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter42'

  // Terminate for MATLABSystem: '<S5>/Read Parameter8'
  if (!FLIGHT_Hexacopter_V2_DW.obj_f.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter8'

  // Terminate for MATLABSystem: '<S5>/read_mc_rollrate_p'
  if (!FLIGHT_Hexacopter_V2_DW.obj_c.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/read_mc_rollrate_p'
}

uint8_T &RT_MODEL_FLIGHT_Hexacopter_V2_T::TaskCounter(int32_T idx)
{
  return (Timing.TaskCounters.TID[(idx)]);
}

boolean_T RT_MODEL_FLIGHT_Hexacopter_V2_T::StepTask(int32_T idx) const
{
  return (Timing.TaskCounters.TID[(idx)] == 0);
}

const char_T* RT_MODEL_FLIGHT_Hexacopter_V2_T::getErrorStatus() const
{
  return (errorStatus);
}

void RT_MODEL_FLIGHT_Hexacopter_V2_T::setErrorStatus(const char_T* const
  volatile aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
