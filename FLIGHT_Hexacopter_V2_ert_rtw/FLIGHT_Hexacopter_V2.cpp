//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_Hexacopter_V2.cpp
//
// Code generated for Simulink model 'FLIGHT_Hexacopter_V2'.
//
// Model version                  : 3.72
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Sep  3 23:21:41 2025
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

#include <float.h>
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
  // Start for MATLABSystem: 'PX4 Timestamp' (':1287')
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_Hexacop_PX4Timestamp(B_PX4Timestamp_FLIGHT_Hexacop_T *localB)
{
  // MATLABSystem: 'PX4 Timestamp' (':1287')
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void FLIGHT_He_PX4Timestamp_Term(DW_PX4Timestamp_FLIGHT_Hexaco_T *localDW)
{
  // Terminate for MATLABSystem: 'PX4 Timestamp' (':1287')
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'PX4 Timestamp' (':1287')
}

// System initialize for atomic system:
void FLIGHT__PX4Timestamp_o_Init(DW_PX4Timestamp_FLIGHT_Hexa_o_T *localDW)
{
  // Start for MATLABSystem: 'PX4 Timestamp' (':1210:105')
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_Hexac_PX4Timestamp_c(B_PX4Timestamp_FLIGHT_Hexac_a_T *localB)
{
  // MATLABSystem: 'PX4 Timestamp' (':1210:105')
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void FLIGHT__PX4Timestamp_p_Term(DW_PX4Timestamp_FLIGHT_Hexa_o_T *localDW)
{
  // Terminate for MATLABSystem: 'PX4 Timestamp' (':1210:105')
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'PX4 Timestamp' (':1210:105')
}

// System initialize for atomic system:
void FLIGHT__PX4Timestamp_c_Init(DW_PX4Timestamp_FLIGHT_Hexa_j_T *localDW)
{
  // Start for MATLABSystem: 'PX4 Timestamp' (':1230:105')
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_Hexac_PX4Timestamp_j(B_PX4Timestamp_FLIGHT_Hexac_l_T *localB)
{
  // MATLABSystem: 'PX4 Timestamp' (':1230:105')
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void FLIGHT__PX4Timestamp_d_Term(DW_PX4Timestamp_FLIGHT_Hexa_j_T *localDW)
{
  // Terminate for MATLABSystem: 'PX4 Timestamp' (':1230:105')
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'PX4 Timestamp' (':1230:105')
}

// System initialize for atomic system:
void FLIGHT_Hex_SourceBlock_Init(DW_SourceBlock_FLIGHT_Hexacop_T *localDW)
{
  // Start for MATLABSystem: 'SourceBlock' (':318:9')
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
  // MATLABSystem: 'SourceBlock' (':318:9')
  localB->SourceBlock_o1 = uORB_read_step(localDW->obj.orbMetadataObj,
    &localDW->obj.eventStructObj, &localB->SourceBlock_o2, false, 1.0);
}

// Termination for atomic system:
void FLIGHT_Hex_SourceBlock_Term(DW_SourceBlock_FLIGHT_Hexacop_T *localDW)
{
  // Terminate for MATLABSystem: 'SourceBlock' (':318:9')
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uORB_read_terminate(&localDW->obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: 'SourceBlock' (':318:9')
}

// Function for MATLAB Function: ''MATLAB Function2' (':1576')'
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

// Function for MATLAB Function: ''MATLAB Function2' (':1576')'
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

// Function for MATLAB Function: ''MATLAB Function2' (':1576')'
static void FLIGHT_Hexacopter_V2_svd(const real32_T A[3], real32_T U[3],
  real32_T *s, real32_T *V)
{
  int32_T b_k;
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
    FLIGHT_Hexacopter_V2_B.absxk = static_cast<real32_T>(fabs(static_cast<real_T>
      (A[b_k])));
    if (rtIsNaNF(FLIGHT_Hexacopter_V2_B.absxk)) {
      FLIGHT_Hexacopter_V2_B.anrm = (rtNaNF);
      exitg1 = true;
    } else {
      if (FLIGHT_Hexacopter_V2_B.absxk > FLIGHT_Hexacopter_V2_B.anrm) {
        FLIGHT_Hexacopter_V2_B.anrm = FLIGHT_Hexacopter_V2_B.absxk;
      }

      b_k++;
    }
  }

  FLIGHT_Hexacopter_V2_B.absxk = FLIGHT_Hexacopter_V2_B.anrm;
  if ((FLIGHT_Hexacopter_V2_B.anrm > 0.0F) && (FLIGHT_Hexacopter_V2_B.anrm <
       9.09494702E-13F)) {
    doscale = true;
    FLIGHT_Hexacopter_V2_B.absxk = 9.09494702E-13F;
    FLIGHT_Hexacopter_V2_xzlascl(FLIGHT_Hexacopter_V2_B.anrm,
      FLIGHT_Hexacopter_V2_B.absxk, 3, 1, FLIGHT_Hexacopter_V2_B.b_A, 1, 3);
  } else if (FLIGHT_Hexacopter_V2_B.anrm > 1.09951163E+12F) {
    doscale = true;
    FLIGHT_Hexacopter_V2_B.absxk = 1.09951163E+12F;
    FLIGHT_Hexacopter_V2_xzlascl(FLIGHT_Hexacopter_V2_B.anrm,
      FLIGHT_Hexacopter_V2_B.absxk, 3, 1, FLIGHT_Hexacopter_V2_B.b_A, 1, 3);
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
    FLIGHT_Hexacopter_V2_xzlascl_k(FLIGHT_Hexacopter_V2_B.absxk,
      FLIGHT_Hexacopter_V2_B.anrm, 1, 1, s);
  }

  *V = 1.0F;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    real_T q;
    if (u1 < 0.0) {
      q = ceil(u1);
    } else {
      q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != q)) {
      q = fabs(u0 / u1);
      if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
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
  uint16_T rtb_DataTypeConversion_g_0;
  int8_T tmp_0;
  int8_T tmp_1;
  boolean_T b_varargout_1;
  boolean_T rtb_Compare_n;
  boolean_T tmp;

  {                                    // Sample time: [0.001s, 0.0s]
    rate_monotonic_scheduler();
  }

  // RateTransition: 'Rate Transition4' (':1068') incorporates:
  //   RateTransition generated from: 'Rate Transition' (':1176')
  //   RateTransition generated from: 'Rate Transition2' (':1298')
  //   RateTransition: 'Rate Transition' (':732')
  //   RateTransition: 'Rate Transition10' (':1995')
  //   RateTransition: 'Rate Transition11' (':2002')
  //   RateTransition: 'Rate Transition12' (':2003')
  //   RateTransition: 'Rate Transition14' (':2005')
  //   RateTransition: 'Rate Transition15' (':2009')
  //   RateTransition: 'Rate Transition16' (':2010')
  //   RateTransition: 'Rate Transition17' (':2011')
  //   RateTransition: 'Rate Transition18' (':2012')
  //   RateTransition: 'Rate Transition3' (':1980')
  //   RateTransition: 'Rate Transition6' (':1982')
  //   RateTransition: 'Rate Transition7' (':1987')
  //   RateTransition: 'Rate Transition8' (':1988')
  //   RateTransition: 'Rate Transition9' (':1989')
  //   RateTransition: 'Rate Transition1' (':1911')
  //   RateTransition: 'Rate Transition15' (':1924')
  //   RateTransition: 'Rate Transition16' (':1925')
  //   RateTransition: 'Rate Transition17' (':1927')
  //   RateTransition: 'Rate Transition4' (':1912')

  tmp = FLIGHT_Hexacopter_V2_M->Timing.RateInteraction.TID0_1;
  if (tmp) {
    // RateTransition: 'Rate Transition4' (':1068')
    FLIGHT_Hexacopter_V2_B.RateTransition4 =
      FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0;

    // RateTransition: 'Rate Transition5' (':1981')
    FLIGHT_Hexacopter_V2_B.RateTransition5 =
      FLIGHT_Hexacopter_V2_DW.RateTransition5_Buffer0;

    // RateTransition: 'Rate Transition2' (':1974')
    FLIGHT_Hexacopter_V2_B.RateTransition2 =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0;
  }

  // End of RateTransition: 'Rate Transition4' (':1068')

  // MATLABSystem: 'SourceBlock' (':299:9')
  b_varargout_1 = uORB_read_step(FLIGHT_Hexacopter_V2_DW.obj_m.orbMetadataObj,
    &FLIGHT_Hexacopter_V2_DW.obj_m.eventStructObj, &FLIGHT_Hexacopter_V2_B.r4,
    false, 1.0);

  // Outputs for Enabled SubSystem: 'Enabled Subsystem' (':299:3') incorporates:
  //   EnablePort: 'Enable' (':299:5')

  // Start for MATLABSystem: 'SourceBlock' (':299:9')
  if (b_varargout_1) {
    // SignalConversion generated from: 'In1' (':299:4')
    FLIGHT_Hexacopter_V2_B.In1_k = FLIGHT_Hexacopter_V2_B.r4;
  }

  // End of Outputs for SubSystem: 'Enabled Subsystem' (':299:3')

  // Sum: 'Sum1' (':1976')
  FLIGHT_Hexacopter_V2_B.IProdOut_b = FLIGHT_Hexacopter_V2_B.RateTransition2 -
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[0];

  // RateTransition: 'Rate Transition15' (':2009')
  if (tmp) {
    // RateTransition: 'Rate Transition15' (':2009')
    FLIGHT_Hexacopter_V2_B.RateTransition15 =
      FLIGHT_Hexacopter_V2_DW.RateTransition15_Buffer0;
  }

  // DiscreteIntegrator: 'Integrator' (':1978:843')
  if ((FLIGHT_Hexacopter_V2_B.RateTransition15 &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState <= 0)) ||
      ((!FLIGHT_Hexacopter_V2_B.RateTransition15) &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState == 1))) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCondit;
  }

  // Sum: 'Sum' (':1978:3518') incorporates:
  //   DiscreteIntegrator: 'Integrator' (':1978:843')
  //   Product: 'PProd Out' (':1978:909')

  FLIGHT_Hexacopter_V2_B.DeadZone = FLIGHT_Hexacopter_V2_B.IProdOut_b *
    FLIGHT_Hexacopter_V2_B.RateTransition5 +
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE;

  // RateTransition: 'Rate Transition18' (':2012') incorporates:
  //   RateTransition: 'Rate Transition3' (':1980')

  if (tmp) {
    // RateTransition: 'Rate Transition18' (':2012')
    FLIGHT_Hexacopter_V2_B.RateTransition18 =
      FLIGHT_Hexacopter_V2_DW.RateTransition18_Buffer0;

    // RateTransition: 'Rate Transition3' (':1980')
    FLIGHT_Hexacopter_V2_B.RateTransition3 =
      FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0;
  }

  // Sum: 'Sum' (':1967:220:337') incorporates:
  //   UnitDelay: 'Unit Delay1' (':1967:220:338')

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE += FLIGHT_Hexacopter_V2_B.In1_k.xyz
    [0];

  // Gain: 'tau' (':1967:220:372')
  FLIGHT_Hexacopter_V2_B.p = FLIGHT_Hexacopter_V2_P.tau_Gain *
    FLIGHT_Hexacopter_V2_B.RateTransition3;

  // Product: 'Product2' (':1967:220:361')
  FLIGHT_Hexacopter_V2_B.q = FLIGHT_Hexacopter_V2_B.p * FLIGHT_Hexacopter_V2_B.p;

  // Bias: 'Bias' (':1967:220:373')
  FLIGHT_Hexacopter_V2_B.r_b = FLIGHT_Hexacopter_V2_B.q +
    FLIGHT_Hexacopter_V2_P.Bias_Bias;

  // Gain: 'Gain' (':1967:220:358')
  FLIGHT_Hexacopter_V2_B.p *= FLIGHT_Hexacopter_V2_P.Gain_Gain_a;

  // Sum: 'Add1' (':1967:220:364')
  FLIGHT_Hexacopter_V2_B.d_p = FLIGHT_Hexacopter_V2_B.r_b +
    FLIGHT_Hexacopter_V2_B.p;

  // SampleTimeMath: 'TSamp' (':1966:4') incorporates:
  //   Product: 'Product1' (':1967:220:343')
  //   Product: 'Product3' (':1967:220:365')
  //   UnitDelay: 'Unit Delay1' (':1967:220:338')
  //
  //  About 'TSamp' (':1966:4'):
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.TSamp = FLIGHT_Hexacopter_V2_B.q /
    FLIGHT_Hexacopter_V2_B.d_p * FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt;

  // Saturate: 'Saturation' (':1978:923')
  if (FLIGHT_Hexacopter_V2_B.DeadZone >
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_UpperSaturati) {
    FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_UpperSaturati;
  } else if (FLIGHT_Hexacopter_V2_B.DeadZone <
             FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_LowerSaturati) {
    FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_LowerSaturati;
  } else {
    FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c = FLIGHT_Hexacopter_V2_B.DeadZone;
  }

  // Sum: 'Sum5' (':1977') incorporates:
  //   Product: 'Product2' (':1973')
  //   Saturate: 'Saturation' (':1978:923')
  //   Sum: 'Diff' (':1966:3')
  //   UnitDelay: 'UD' (':1966:5')
  //
  //  Block description for 'Diff' (':1966:3'):
  //
  //   Add in CPU
  //
  //  Block description for 'UD' (':1966:5'):
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_B.Sum5_f = FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c -
    (FLIGHT_Hexacopter_V2_B.TSamp - FLIGHT_Hexacopter_V2_DW.UD_DSTATE) *
    FLIGHT_Hexacopter_V2_B.RateTransition18;

  // RateTransition generated from: 'Rate Transition' (':1176') incorporates:
  //   RateTransition: 'Rate Transition1' (':1911')
  //   RateTransition: 'Rate Transition15' (':1924')
  //   RateTransition: 'Rate Transition16' (':1925')
  //   RateTransition: 'Rate Transition17' (':1927')
  //   RateTransition: 'Rate Transition2' (':884')
  //   RateTransition: 'Rate Transition4' (':1912')

  if (tmp) {
    // RateTransition generated from: 'Rate Transition' (':1176')
    FLIGHT_Hexacopter_V2_B.rc_ctrl_switch =
      FLIGHT_Hexacopter_V2_DW.RateTransition_8_Buffer0;

    // RateTransition: 'Rate Transition2' (':884')
    FLIGHT_Hexacopter_V2_B.RateTransition2_a[0] =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[0];
    FLIGHT_Hexacopter_V2_B.RateTransition2_a[1] =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[1];
    FLIGHT_Hexacopter_V2_B.RateTransition2_a[2] =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[2];

    // RateTransition: 'Rate Transition4' (':1912')
    FLIGHT_Hexacopter_V2_B.RateTransition4_l =
      FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_d;

    // RateTransition: 'Rate Transition5' (':1913')
    FLIGHT_Hexacopter_V2_B.RateTransition5_n =
      FLIGHT_Hexacopter_V2_DW.RateTransition5_Buffer0_h;

    // RateTransition: 'Rate Transition6' (':1914')
    FLIGHT_Hexacopter_V2_B.RateTransition6 =
      FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0;

    // RateTransition: 'Rate Transition9' (':1917')
    FLIGHT_Hexacopter_V2_B.RateTransition9 =
      FLIGHT_Hexacopter_V2_DW.RateTransition9_Buffer0;

    // RateTransition: 'Rate Transition10' (':1918')
    FLIGHT_Hexacopter_V2_B.RateTransition10 =
      FLIGHT_Hexacopter_V2_DW.RateTransition10_Buffer0;

    // RateTransition: 'Rate Transition11' (':1919')
    FLIGHT_Hexacopter_V2_B.RateTransition11 =
      FLIGHT_Hexacopter_V2_DW.RateTransition11_Buffer0;

    // RateTransition: 'Rate Transition17' (':1927')
    FLIGHT_Hexacopter_V2_B.RateTransition17 =
      FLIGHT_Hexacopter_V2_DW.RateTransition17_Buffer0;

    // RateTransition: 'Rate Transition1' (':1911')
    FLIGHT_Hexacopter_V2_B.RateTransition1 =
      FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0;

    // RateTransition: 'Rate Transition16' (':1925')
    FLIGHT_Hexacopter_V2_B.RateTransition16 =
      FLIGHT_Hexacopter_V2_DW.RateTransition16_Buffer0;

    // RateTransition: 'Rate Transition7' (':1915')
    FLIGHT_Hexacopter_V2_B.RateTransition7 =
      FLIGHT_Hexacopter_V2_DW.RateTransition7_Buffer0;

    // RateTransition: 'Rate Transition8' (':1916')
    FLIGHT_Hexacopter_V2_B.RateTransition8 =
      FLIGHT_Hexacopter_V2_DW.RateTransition8_Buffer0;

    // RateTransition: 'Rate Transition12' (':1920')
    FLIGHT_Hexacopter_V2_B.RateTransition12 =
      FLIGHT_Hexacopter_V2_DW.RateTransition12_Buffer0;

    // RateTransition: 'Rate Transition13' (':1921')
    FLIGHT_Hexacopter_V2_B.RateTransition13 =
      FLIGHT_Hexacopter_V2_DW.RateTransition13_Buffer0;

    // RateTransition: 'Rate Transition14' (':1922')
    FLIGHT_Hexacopter_V2_B.RateTransition14 =
      FLIGHT_Hexacopter_V2_DW.RateTransition14_Buffer0;

    // RateTransition: 'Rate Transition15' (':1924')
    FLIGHT_Hexacopter_V2_B.RateTransition15_l =
      FLIGHT_Hexacopter_V2_DW.RateTransition15_Buffer0_a;
  }

  // MATLAB Function: 'Omega_phi' (':1580')
  // :  omega_phi = [1, sin(phi)*tan(theta), cos(phi)*tan(theta)];
  FLIGHT_Hexacopter_V2_B.rtb_omega_phi_idx_1 = static_cast<real32_T>(sin(
    static_cast<real_T>(FLIGHT_Hexacopter_V2_B.RateTransition2_a[2]))) *
    static_cast<real32_T>(tan(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition2_a[1])));
  FLIGHT_Hexacopter_V2_B.rtb_omega_phi_idx_2 = static_cast<real32_T>(cos(
    static_cast<real_T>(FLIGHT_Hexacopter_V2_B.RateTransition2_a[2]))) *
    static_cast<real32_T>(tan(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition2_a[1])));

  // Sum: 'Diff' (':1524:3') incorporates:
  //   SampleTimeMath: 'TSamp' (':1524:4')
  //   UnitDelay: 'UD' (':1524:5')
  //
  //  About 'TSamp' (':1524:4'):
  //   y = u * K where K = 1 / ( w * Ts )
  //    *
  //  Block description for 'Diff' (':1524:3'):
  //
  //   Add in CPU
  //
  //  Block description for 'UD' (':1524:5'):
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[0] = FLIGHT_Hexacopter_V2_P.TSamp_WtEt_m -
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[0];

  // SampleTimeMath: 'TSamp' (':1524:4')
  //
  //  About 'TSamp' (':1524:4'):
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.rtb_TSamp_o_f =
    FLIGHT_Hexacopter_V2_B.rtb_omega_phi_idx_1 *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_m;
  FLIGHT_Hexacopter_V2_B.rtb_TSamp_o_idx_1 =
    FLIGHT_Hexacopter_V2_B.rtb_TSamp_o_f;

  // Sum: 'Diff' (':1524:3') incorporates:
  //   SampleTimeMath: 'TSamp' (':1524:4')
  //   UnitDelay: 'UD' (':1524:5')
  //
  //  About 'TSamp' (':1524:4'):
  //   y = u * K where K = 1 / ( w * Ts )
  //    *
  //  Block description for 'Diff' (':1524:3'):
  //
  //   Add in CPU
  //
  //  Block description for 'UD' (':1524:5'):
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[1] = FLIGHT_Hexacopter_V2_B.rtb_TSamp_o_f
    - FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[1];

  // SampleTimeMath: 'TSamp' (':1524:4')
  //
  //  About 'TSamp' (':1524:4'):
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.rtb_TSamp_o_f =
    FLIGHT_Hexacopter_V2_B.rtb_omega_phi_idx_2 *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_m;

  // Sum: 'Diff' (':1524:3') incorporates:
  //   SampleTimeMath: 'TSamp' (':1524:4')
  //   UnitDelay: 'UD' (':1524:5')
  //
  //  About 'TSamp' (':1524:4'):
  //   y = u * K where K = 1 / ( w * Ts )
  //    *
  //  Block description for 'Diff' (':1524:3'):
  //
  //   Add in CPU
  //
  //  Block description for 'UD' (':1524:5'):
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[2] = FLIGHT_Hexacopter_V2_B.rtb_TSamp_o_f
    - FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[2];

  // Product: 'Product' (':1514') incorporates:
  //   Product: 'Divide' (':1485')
  //   Product: 'Product1' (':1515')
  //   Sum: 'Add' (':1476')

  FLIGHT_Hexacopter_V2_B.Product_p = (FLIGHT_Hexacopter_V2_B.RateTransition10 -
    FLIGHT_Hexacopter_V2_B.RateTransition11) /
    FLIGHT_Hexacopter_V2_B.RateTransition9 * (FLIGHT_Hexacopter_V2_B.In1_k.xyz[1]
    * FLIGHT_Hexacopter_V2_B.In1_k.xyz[2]);

  // Product: 'Product2' (':1516') incorporates:
  //   Product: 'Divide1' (':1486')
  //   Product: 'Product3' (':1517')
  //   Sum: 'Add1' (':1477')

  FLIGHT_Hexacopter_V2_B.Product2_m = (FLIGHT_Hexacopter_V2_B.RateTransition11 -
    FLIGHT_Hexacopter_V2_B.RateTransition9) /
    FLIGHT_Hexacopter_V2_B.RateTransition10 * (FLIGHT_Hexacopter_V2_B.In1_k.xyz
    [0] * FLIGHT_Hexacopter_V2_B.In1_k.xyz[2]);

  // Product: 'Product4' (':1518') incorporates:
  //   Product: 'Divide2' (':1487')
  //   Product: 'Product5' (':1519')
  //   Sum: 'Add2' (':1478')

  FLIGHT_Hexacopter_V2_B.Product4 = (FLIGHT_Hexacopter_V2_B.RateTransition9 -
    FLIGHT_Hexacopter_V2_B.RateTransition10) /
    FLIGHT_Hexacopter_V2_B.RateTransition11 * (FLIGHT_Hexacopter_V2_B.In1_k.xyz
    [0] * FLIGHT_Hexacopter_V2_B.In1_k.xyz[1]);

  // Gain: 'tau' (':1756:219:350')
  FLIGHT_Hexacopter_V2_B.Product2_gt = FLIGHT_Hexacopter_V2_P.tau_Gain_f *
    FLIGHT_Hexacopter_V2_B.RateTransition17;

  // Product: 'Product2' (':1756:219:339') incorporates:
  //   Bias: 'Bias' (':1756:219:351')

  FLIGHT_Hexacopter_V2_B.Product2_gt *= 1.0F /
    (FLIGHT_Hexacopter_V2_B.Product2_gt + FLIGHT_Hexacopter_V2_P.Bias_Bias_h);

  // Sum: 'Sum' (':1756:219:332') incorporates:
  //   UnitDelay: 'Unit Delay' (':1756:219:331')

  FLIGHT_Hexacopter_V2_B.Sum_o = FLIGHT_Hexacopter_V2_B.RateTransition1 +
    FLIGHT_Hexacopter_V2_DW.UnitDelay_DSTATE;

  // Product: 'Product1' (':1756:219:334')
  FLIGHT_Hexacopter_V2_B.Product1_m = FLIGHT_Hexacopter_V2_B.Product2_gt *
    FLIGHT_Hexacopter_V2_B.Sum_o;

  // SampleTimeMath: 'TSamp' (':1522:4')
  //
  //  About 'TSamp' (':1522:4'):
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.TSamp_oi = FLIGHT_Hexacopter_V2_B.Product1_m *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_p;

  // Sum: 'Diff' (':1522:3') incorporates:
  //   UnitDelay: 'UD' (':1522:5')
  //
  //  Block description for 'Diff' (':1522:3'):
  //
  //   Add in CPU
  //
  //  Block description for 'UD' (':1522:5'):
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_B.Diff_k = FLIGHT_Hexacopter_V2_B.TSamp_oi -
    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_o;

  // SampleTimeMath: 'TSamp' (':1523:4')
  //
  //  About 'TSamp' (':1523:4'):
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.TSamp_d = FLIGHT_Hexacopter_V2_B.Diff_k *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_l;

  // Sum: 'Subtract' (':1583')
  FLIGHT_Hexacopter_V2_B.Subtract = FLIGHT_Hexacopter_V2_B.RateTransition2_a[2]
    - FLIGHT_Hexacopter_V2_B.Product1_m;

  // MATLAB Function: 'MATLAB Function' (':1574') incorporates:
  //   SignalConversion generated from: ' SFunction ' (':1574::39')
  //   Sum: 'Diff' (':1524:3')
  //
  //  Block description for 'Diff' (':1524:3'):
  //
  //   Add in CPU

  // :  phi_cmd_ddot = 0;
  //  Suppose
  // :  H = kd*(omega_dot*w + omega*fx - phi_cmd_ddot) + kp*(omega*w - phi_cmd_dot) + ki*e; 
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
    FLIGHT_Hexacopter_V2_B.RateTransition5_n * FLIGHT_Hexacopter_V2_B.Subtract;

  // Gain: 'Filter Coefficient' (':1817:882') incorporates:
  //   DiscreteIntegrator: 'Filter' (':1817:737')
  //   Gain: 'Derivative Gain' (':1817:688')
  //   Sum: 'SumD' (':1817:738')

  FLIGHT_Hexacopter_V2_B.FilterCoefficient =
    (FLIGHT_Hexacopter_V2_P.DiscretePIDController1_D *
     FLIGHT_Hexacopter_V2_B.Subtract - FLIGHT_Hexacopter_V2_DW.Filter_DSTATE) *
    FLIGHT_Hexacopter_V2_P.DiscretePIDController1_N;

  // Sum: 'Sum' (':1817:3522') incorporates:
  //   Gain: 'Proportional Gain' (':1817:913')

  FLIGHT_Hexacopter_V2_B.Sum_n = FLIGHT_Hexacopter_V2_P.DiscretePIDController1_P
    * FLIGHT_Hexacopter_V2_B.Subtract + FLIGHT_Hexacopter_V2_B.FilterCoefficient;

  // DiscreteIntegrator: 'Integrator' (':1820:843')
  if ((FLIGHT_Hexacopter_V2_B.RateTransition15_l &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_h <= 0)) ||
      ((!FLIGHT_Hexacopter_V2_B.RateTransition15_l) &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_h == 1))) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_h =
      FLIGHT_Hexacopter_V2_P.DiscretePIDController2_InitialC;
  }

  // MATLAB Function: 'MATLAB Function3' (':1577') incorporates:
  //   DiscreteIntegrator: 'Integrator' (':1820:843')

  //  PID Like Sliding Surface
  // :  s = kd*e_dot + kp*e + ki*integral_e;
  FLIGHT_Hexacopter_V2_B.s = (FLIGHT_Hexacopter_V2_B.RateTransition6 *
    FLIGHT_Hexacopter_V2_B.Sum_n + FLIGHT_Hexacopter_V2_B.RateTransition4_l *
    FLIGHT_Hexacopter_V2_B.Subtract) + FLIGHT_Hexacopter_V2_B.RateTransition5_n *
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_h;

  // DiscreteIntegrator: 'Discrete-Time Integrator' (':1887')
  if ((FLIGHT_Hexacopter_V2_B.RateTransition15_l &&
       (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRese <= 0)) ||
      ((!FLIGHT_Hexacopter_V2_B.RateTransition15_l) &&
       (FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRese == 1))) {
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE =
      FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_IC;
  }

  // MATLAB Function: 'MATLAB Function4' (':1578')
  //  Sign Function
  // R = -ks*sign(s) - kp*s;
  //  Modified Sigmoid
  // :  R = -ks*( s/(abs(s)+eps) ) - kp*s;
  FLIGHT_Hexacopter_V2_B.IProdOut_p = static_cast<real32_T>(fabs
    (static_cast<real_T>(FLIGHT_Hexacopter_V2_B.s)));
  FLIGHT_Hexacopter_V2_B.R = FLIGHT_Hexacopter_V2_B.s /
    (FLIGHT_Hexacopter_V2_B.IProdOut_p + FLIGHT_Hexacopter_V2_B.RateTransition12)
    * -FLIGHT_Hexacopter_V2_B.RateTransition7 -
    FLIGHT_Hexacopter_V2_B.RateTransition8 * FLIGHT_Hexacopter_V2_B.s;

  // S-Function (sdspdiag2): 'Create Diagonal Matrix' (':1482') incorporates:
  //   Constant: 'Constant' (':1744')
  //   Product: 'Divide3' (':1743')

  //  Super-Twisting
  // :  u1 = -lamda*abs(s)^0.5*sign(s)-w;
  // :  wdot = single(eta*sign(s));
  // :  ST_R = u1;
  memset(&FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[0], 0, 9U * sizeof(real_T));

  // :  G1 = kd*omega * gx;
  FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[0] =
    FLIGHT_Hexacopter_V2_P.Constant_Value_gr /
    FLIGHT_Hexacopter_V2_B.RateTransition9;

  // MATLAB Function: 'MATLAB Function1' (':1575')
  FLIGHT_Hexacopter_V2_B.G1[0] = 0.0F;

  // S-Function (sdspdiag2): 'Create Diagonal Matrix' (':1482') incorporates:
  //   Constant: 'Constant1' (':1747')
  //   Product: 'Divide4' (':1745')

  FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[4] =
    FLIGHT_Hexacopter_V2_P.Constant1_Value_f /
    FLIGHT_Hexacopter_V2_B.RateTransition10;

  // MATLAB Function: 'MATLAB Function1' (':1575')
  FLIGHT_Hexacopter_V2_B.G1[1] = 0.0F;

  // S-Function (sdspdiag2): 'Create Diagonal Matrix' (':1482') incorporates:
  //   Constant: 'Constant2' (':1748')
  //   Product: 'Divide5' (':1746')

  FLIGHT_Hexacopter_V2_B.CreateDiagonalMatrix[8] =
    FLIGHT_Hexacopter_V2_P.Constant2_Value_n /
    FLIGHT_Hexacopter_V2_B.RateTransition11;

  // MATLAB Function: 'MATLAB Function1' (':1575')
  FLIGHT_Hexacopter_V2_B.G1[2] = 0.0F;

  // MATLAB Function: 'MATLAB Function2' (':1576')
  // :  G1_inv = pinv(G1x);
  b_varargout_1 = true;
  for (FLIGHT_Hexacopter_V2_B.i = 0; FLIGHT_Hexacopter_V2_B.i < 3;
       FLIGHT_Hexacopter_V2_B.i++) {
    // MATLAB Function: 'MATLAB Function1' (':1575') incorporates:
    //   DataTypeConversion: 'Data Type Conversion1' (':1484')
    //   S-Function (sdspdiag2): 'Create Diagonal Matrix' (':1482')

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

    // MATLAB Function: 'MATLAB Function2' (':1576') incorporates:
    //   MATLAB Function: 'MATLAB Function1' (':1575')

    FLIGHT_Hexacopter_V2_B.G1_inv[FLIGHT_Hexacopter_V2_B.i] = 0.0F;
    if (b_varargout_1 && (rtIsInfF(FLIGHT_Hexacopter_V2_B.V) || rtIsNaNF
                          (FLIGHT_Hexacopter_V2_B.V))) {
      b_varargout_1 = false;
    }
  }

  // MATLAB Function: 'MATLAB Function2' (':1576')
  if (!b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.G1_inv[0] = (rtNaNF);
    FLIGHT_Hexacopter_V2_B.G1_inv[1] = (rtNaNF);
    FLIGHT_Hexacopter_V2_B.G1_inv[2] = (rtNaNF);
  } else {
    FLIGHT_Hexacopter_V2_svd(FLIGHT_Hexacopter_V2_B.G1, FLIGHT_Hexacopter_V2_B.U,
      &FLIGHT_Hexacopter_V2_B.DeadZone_d, &FLIGHT_Hexacopter_V2_B.V);
    FLIGHT_Hexacopter_V2_B.absx = static_cast<real32_T>(fabs(static_cast<real_T>
      (FLIGHT_Hexacopter_V2_B.DeadZone_d)));
    if (rtIsInfF(FLIGHT_Hexacopter_V2_B.absx) || rtIsNaNF
        (FLIGHT_Hexacopter_V2_B.absx)) {
      FLIGHT_Hexacopter_V2_B.absx = (rtNaNF);
    } else if (FLIGHT_Hexacopter_V2_B.absx < 2.3509887E-38F) {
      FLIGHT_Hexacopter_V2_B.absx = 1.4013E-45F;
    } else {
      frexp(static_cast<real_T>(FLIGHT_Hexacopter_V2_B.absx),
            &FLIGHT_Hexacopter_V2_B.ParamStep_g1);
      FLIGHT_Hexacopter_V2_B.absx = static_cast<real32_T>(ldexp(1.0,
        FLIGHT_Hexacopter_V2_B.ParamStep_g1 - 24));
    }

    FLIGHT_Hexacopter_V2_B.absx *= 3.0F;
    if (rtIsInfF(FLIGHT_Hexacopter_V2_B.DeadZone_d) || rtIsNaNF
        (FLIGHT_Hexacopter_V2_B.DeadZone_d)) {
      FLIGHT_Hexacopter_V2_B.absx = 3.402823466E+38F;
    }

    FLIGHT_Hexacopter_V2_B.i = 0;
    if (FLIGHT_Hexacopter_V2_B.DeadZone_d > FLIGHT_Hexacopter_V2_B.absx) {
      FLIGHT_Hexacopter_V2_B.i = 1;
    }

    if (FLIGHT_Hexacopter_V2_B.i > 0) {
      FLIGHT_Hexacopter_V2_B.DeadZone_d = 1.0F /
        FLIGHT_Hexacopter_V2_B.DeadZone_d;
      for (FLIGHT_Hexacopter_V2_B.i = 1; FLIGHT_Hexacopter_V2_B.i < 2;
           FLIGHT_Hexacopter_V2_B.i++) {
        FLIGHT_Hexacopter_V2_B.V *= FLIGHT_Hexacopter_V2_B.DeadZone_d;
      }

      FLIGHT_Hexacopter_V2_B.i = 0;
      for (FLIGHT_Hexacopter_V2_B.ParamStep_g1 = 0;
           FLIGHT_Hexacopter_V2_B.ParamStep_g1 < 3;
           FLIGHT_Hexacopter_V2_B.ParamStep_g1++) {
        for (FLIGHT_Hexacopter_V2_B.ParamStep_m =
             FLIGHT_Hexacopter_V2_B.ParamStep_g1 + 1;
             FLIGHT_Hexacopter_V2_B.ParamStep_m <=
             FLIGHT_Hexacopter_V2_B.ParamStep_g1 + 1;
             FLIGHT_Hexacopter_V2_B.ParamStep_m++) {
          FLIGHT_Hexacopter_V2_B.G1_inv[FLIGHT_Hexacopter_V2_B.ParamStep_m - 1] =
            0.0F;
        }
      }

      for (FLIGHT_Hexacopter_V2_B.ParamStep_g1 = 0;
           FLIGHT_Hexacopter_V2_B.ParamStep_g1 < 3;
           FLIGHT_Hexacopter_V2_B.ParamStep_g1++) {
        FLIGHT_Hexacopter_V2_B.i++;
        for (FLIGHT_Hexacopter_V2_B.ParamStep_m = FLIGHT_Hexacopter_V2_B.i;
             FLIGHT_Hexacopter_V2_B.ParamStep_m <= FLIGHT_Hexacopter_V2_B.i;
             FLIGHT_Hexacopter_V2_B.ParamStep_m += 3) {
          for (FLIGHT_Hexacopter_V2_B.ParamStep_n =
               FLIGHT_Hexacopter_V2_B.ParamStep_g1 + 1;
               FLIGHT_Hexacopter_V2_B.ParamStep_n <=
               FLIGHT_Hexacopter_V2_B.ParamStep_g1 + 1;
               FLIGHT_Hexacopter_V2_B.ParamStep_n++) {
            FLIGHT_Hexacopter_V2_B.G1_inv[FLIGHT_Hexacopter_V2_B.ParamStep_n - 1]
              += FLIGHT_Hexacopter_V2_B.U[FLIGHT_Hexacopter_V2_B.ParamStep_m - 1]
              * FLIGHT_Hexacopter_V2_B.V;
          }
        }
      }
    }
  }

  // MATLAB Function: 'MATLAB Function4' (':1578')
  // :  u = G1_inv * (-Hx + R);
  if (rtIsNaNF(FLIGHT_Hexacopter_V2_B.s)) {
    FLIGHT_Hexacopter_V2_B.V = (rtNaNF);
  } else if (FLIGHT_Hexacopter_V2_B.s < 0.0F) {
    FLIGHT_Hexacopter_V2_B.V = -1.0F;
  } else {
    FLIGHT_Hexacopter_V2_B.V = (FLIGHT_Hexacopter_V2_B.s > 0.0F);
  }

  // Switch: 'Switch' (':1900') incorporates:
  //   DiscreteIntegrator: 'Discrete-Time Integrator' (':1887')
  //   MATLAB Function: 'MATLAB Function4' (':1578')

  if (FLIGHT_Hexacopter_V2_B.RateTransition16) {
    FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c =
      -FLIGHT_Hexacopter_V2_B.RateTransition13 * static_cast<real32_T>(sqrt(
      static_cast<real_T>(FLIGHT_Hexacopter_V2_B.IProdOut_p))) *
      FLIGHT_Hexacopter_V2_B.V -
      FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE;
  } else {
    FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c = FLIGHT_Hexacopter_V2_B.R;
  }

  // MATLAB Function: 'MATLAB Function2' (':1576') incorporates:
  //   Switch: 'Switch' (':1900')

  FLIGHT_Hexacopter_V2_B.Saturation2 = (-FLIGHT_Hexacopter_V2_B.H +
    FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c) * FLIGHT_Hexacopter_V2_B.G1_inv[0];

  // Saturate: 'Saturation2' (':1581')
  if (FLIGHT_Hexacopter_V2_B.Saturation2 >
      FLIGHT_Hexacopter_V2_P.Saturation2_UpperSat) {
    FLIGHT_Hexacopter_V2_B.Saturation2 =
      FLIGHT_Hexacopter_V2_P.Saturation2_UpperSat;
  } else if (FLIGHT_Hexacopter_V2_B.Saturation2 <
             FLIGHT_Hexacopter_V2_P.Saturation2_LowerSat) {
    FLIGHT_Hexacopter_V2_B.Saturation2 =
      FLIGHT_Hexacopter_V2_P.Saturation2_LowerSat;
  }

  // End of Saturate: 'Saturation2' (':1581')

  // RateTransition: 'Rate Transition8' (':1988') incorporates:
  //   RateTransition: 'Rate Transition16' (':2010')

  if (tmp) {
    // RateTransition: 'Rate Transition8' (':1988')
    FLIGHT_Hexacopter_V2_B.RateTransition8_i =
      FLIGHT_Hexacopter_V2_DW.RateTransition8_Buffer0_a;

    // RateTransition: 'Rate Transition19' (':2013')
    FLIGHT_Hexacopter_V2_B.RateTransition19 =
      FLIGHT_Hexacopter_V2_DW.RateTransition19_Buffer0;

    // RateTransition: 'Rate Transition16' (':2010')
    FLIGHT_Hexacopter_V2_B.RateTransition16_e =
      FLIGHT_Hexacopter_V2_DW.RateTransition16_Buffer0_g;
  }

  // Sum: 'Sum6' (':1993')
  FLIGHT_Hexacopter_V2_B.IProdOut_p = FLIGHT_Hexacopter_V2_B.RateTransition19 -
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[1];

  // DiscreteIntegrator: 'Integrator' (':1991:843')
  if ((FLIGHT_Hexacopter_V2_B.RateTransition16_e &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_e <= 0)) ||
      ((!FLIGHT_Hexacopter_V2_B.RateTransition16_e) &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_e == 1))) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_l =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate1_InitialCondi;
  }

  // Sum: 'Sum' (':1991:3518') incorporates:
  //   DiscreteIntegrator: 'Integrator' (':1991:843')
  //   Product: 'PProd Out' (':1991:909')

  FLIGHT_Hexacopter_V2_B.DeadZone_d = FLIGHT_Hexacopter_V2_B.IProdOut_p *
    FLIGHT_Hexacopter_V2_B.RateTransition8_i +
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_l;

  // RateTransition: 'Rate Transition10' (':1995') incorporates:
  //   RateTransition: 'Rate Transition7' (':1987')

  if (tmp) {
    // RateTransition: 'Rate Transition10' (':1995')
    FLIGHT_Hexacopter_V2_B.RateTransition10_j =
      FLIGHT_Hexacopter_V2_DW.RateTransition10_Buffer0_g;

    // RateTransition: 'Rate Transition7' (':1987')
    FLIGHT_Hexacopter_V2_B.RateTransition7_h =
      FLIGHT_Hexacopter_V2_DW.RateTransition7_Buffer0_e;
  }

  // Sum: 'Sum' (':1984:220:337') incorporates:
  //   UnitDelay: 'Unit Delay1' (':1984:220:338')

  FLIGHT_Hexacopter_V2_B.Product2_l = FLIGHT_Hexacopter_V2_B.In1_k.xyz[1] +
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_a;

  // Gain: 'tau' (':1984:220:372')
  FLIGHT_Hexacopter_V2_B.p_l = FLIGHT_Hexacopter_V2_P.tau_Gain_k *
    FLIGHT_Hexacopter_V2_B.RateTransition7_h;

  // Product: 'Product2' (':1984:220:361')
  FLIGHT_Hexacopter_V2_B.q_o = FLIGHT_Hexacopter_V2_B.p_l *
    FLIGHT_Hexacopter_V2_B.p_l;

  // Bias: 'Bias' (':1984:220:373')
  FLIGHT_Hexacopter_V2_B.r_d = FLIGHT_Hexacopter_V2_B.q_o +
    FLIGHT_Hexacopter_V2_P.Bias_Bias_b;

  // Gain: 'Gain' (':1984:220:358')
  FLIGHT_Hexacopter_V2_B.p_l *= FLIGHT_Hexacopter_V2_P.Gain_Gain_b3;

  // Sum: 'Add1' (':1984:220:364')
  FLIGHT_Hexacopter_V2_B.d_g = FLIGHT_Hexacopter_V2_B.r_d +
    FLIGHT_Hexacopter_V2_B.p_l;

  // SampleTimeMath: 'TSamp' (':1983:4') incorporates:
  //   Product: 'Product1' (':1984:220:343')
  //   Product: 'Product3' (':1984:220:365')
  //
  //  About 'TSamp' (':1983:4'):
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.absx = FLIGHT_Hexacopter_V2_B.q_o /
    FLIGHT_Hexacopter_V2_B.d_g * FLIGHT_Hexacopter_V2_B.Product2_l *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_d;

  // Saturate: 'Saturation' (':1991:923')
  if (FLIGHT_Hexacopter_V2_B.DeadZone_d >
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate1_UpperSaturat) {
    FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate1_UpperSaturat;
  } else if (FLIGHT_Hexacopter_V2_B.DeadZone_d <
             FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate1_LowerSaturat) {
    FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate1_LowerSaturat;
  } else {
    FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c = FLIGHT_Hexacopter_V2_B.DeadZone_d;
  }

  // Sum: 'Sum4' (':1990') incorporates:
  //   Product: 'Product1' (':1986')
  //   Saturate: 'Saturation' (':1991:923')
  //   Sum: 'Diff' (':1983:3')
  //   UnitDelay: 'UD' (':1983:5')
  //
  //  Block description for 'Diff' (':1983:3'):
  //
  //   Add in CPU
  //
  //  Block description for 'UD' (':1983:5'):
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_B.Sum4 = FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c -
    (FLIGHT_Hexacopter_V2_B.absx - FLIGHT_Hexacopter_V2_DW.UD_DSTATE_b) *
    FLIGHT_Hexacopter_V2_B.RateTransition10_j;

  // RateTransition: 'Rate Transition' (':732') incorporates:
  //   RateTransition: 'Rate Transition13' (':2004')
  //   RateTransition: 'Rate Transition17' (':2011')

  if (tmp) {
    // RateTransition: 'Rate Transition' (':732')
    FLIGHT_Hexacopter_V2_B.RateTransition =
      FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0;

    // RateTransition: 'Rate Transition1' (':733')
    FLIGHT_Hexacopter_V2_B.RateTransition1_a =
      FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_g;

    // RateTransition: 'Rate Transition13' (':2004')
    FLIGHT_Hexacopter_V2_B.RateTransition13_a =
      FLIGHT_Hexacopter_V2_DW.RateTransition13_Buffer0_d;

    // RateTransition: 'Rate Transition20' (':2014')
    FLIGHT_Hexacopter_V2_B.RateTransition20 =
      FLIGHT_Hexacopter_V2_DW.RateTransition20_Buffer0;

    // RateTransition: 'Rate Transition17' (':2011')
    FLIGHT_Hexacopter_V2_B.RateTransition17_h =
      FLIGHT_Hexacopter_V2_DW.RateTransition17_Buffer0_e;
  }

  // Sum: 'Sum8' (':2007')
  FLIGHT_Hexacopter_V2_B.IProdOut_g = FLIGHT_Hexacopter_V2_B.RateTransition20 -
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[2];

  // DiscreteIntegrator: 'Integrator' (':2008:843')
  if ((FLIGHT_Hexacopter_V2_B.RateTransition17_h &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_es <= 0)) ||
      ((!FLIGHT_Hexacopter_V2_B.RateTransition17_h) &&
       (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_es == 1))) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_o =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate2_InitialCondi;
  }

  // Sum: 'Sum' (':2008:3518') incorporates:
  //   DiscreteIntegrator: 'Integrator' (':2008:843')
  //   Product: 'PProd Out' (':2008:909')

  FLIGHT_Hexacopter_V2_B.DeadZone_db = FLIGHT_Hexacopter_V2_B.IProdOut_g *
    FLIGHT_Hexacopter_V2_B.RateTransition13_a +
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_o;

  // RateTransition: 'Rate Transition11' (':2002') incorporates:
  //   RateTransition: 'Rate Transition12' (':2003')

  if (tmp) {
    // RateTransition: 'Rate Transition11' (':2002')
    FLIGHT_Hexacopter_V2_B.RateTransition11_a =
      FLIGHT_Hexacopter_V2_DW.RateTransition11_Buffer0_b;

    // RateTransition: 'Rate Transition12' (':2003')
    FLIGHT_Hexacopter_V2_B.RateTransition12_j =
      FLIGHT_Hexacopter_V2_DW.RateTransition12_Buffer0_j;
  }

  // Sum: 'Sum' (':1999:220:337') incorporates:
  //   UnitDelay: 'Unit Delay1' (':1999:220:338')

  FLIGHT_Hexacopter_V2_B.Product2_d = FLIGHT_Hexacopter_V2_B.In1_k.xyz[2] +
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_p;

  // Gain: 'tau' (':1999:220:372')
  FLIGHT_Hexacopter_V2_B.p_g = FLIGHT_Hexacopter_V2_P.tau_Gain_d *
    FLIGHT_Hexacopter_V2_B.RateTransition12_j;

  // Product: 'Product2' (':1999:220:361')
  FLIGHT_Hexacopter_V2_B.q_i = FLIGHT_Hexacopter_V2_B.p_g *
    FLIGHT_Hexacopter_V2_B.p_g;

  // Bias: 'Bias' (':1999:220:373')
  FLIGHT_Hexacopter_V2_B.r_m = FLIGHT_Hexacopter_V2_B.q_i +
    FLIGHT_Hexacopter_V2_P.Bias_Bias_p;

  // Gain: 'Gain' (':1999:220:358')
  FLIGHT_Hexacopter_V2_B.p_g *= FLIGHT_Hexacopter_V2_P.Gain_Gain_ow;

  // Sum: 'Add1' (':1999:220:364')
  FLIGHT_Hexacopter_V2_B.d_c = FLIGHT_Hexacopter_V2_B.r_m +
    FLIGHT_Hexacopter_V2_B.p_g;

  // SampleTimeMath: 'TSamp' (':1998:4') incorporates:
  //   Product: 'Product1' (':1999:220:343')
  //   Product: 'Product3' (':1999:220:365')
  //
  //  About 'TSamp' (':1998:4'):
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.TSamp_p = FLIGHT_Hexacopter_V2_B.q_i /
    FLIGHT_Hexacopter_V2_B.d_c * FLIGHT_Hexacopter_V2_B.Product2_d *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_b;

  // Saturate: 'Saturation' (':2008:923')
  if (FLIGHT_Hexacopter_V2_B.DeadZone_db >
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate2_UpperSaturat) {
    FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate2_UpperSaturat;
  } else if (FLIGHT_Hexacopter_V2_B.DeadZone_db <
             FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate2_LowerSaturat) {
    FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate2_LowerSaturat;
  } else {
    FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c = FLIGHT_Hexacopter_V2_B.DeadZone_db;
  }

  // Sum: 'Sum' (':726') incorporates:
  //   Product: 'Product3' (':2001')
  //   Product: 'yawrate_feedforward' (':724')
  //   Saturate: 'Saturation' (':2008:923')
  //   Sum: 'Sum7' (':2006')
  //   Sum: 'Diff' (':1998:3')
  //   UnitDelay: 'UD' (':1998:5')
  //
  //  Block description for 'Diff' (':1998:3'):
  //
  //   Add in CPU
  //
  //  Block description for 'UD' (':1998:5'):
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_B.Sum2_au = (FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c -
    (FLIGHT_Hexacopter_V2_B.TSamp_p - FLIGHT_Hexacopter_V2_DW.UD_DSTATE_d) *
    FLIGHT_Hexacopter_V2_B.RateTransition11_a) +
    FLIGHT_Hexacopter_V2_B.RateTransition *
    FLIGHT_Hexacopter_V2_B.RateTransition1_a;

  // SignalConversion generated from: 'Product1' (':160:195')
  FLIGHT_Hexacopter_V2_B.fv[0] = FLIGHT_Hexacopter_V2_B.RateTransition4;

  // Switch: 'Switch' (':1316') incorporates:
  //   Constant: 'Constant' (':1315:3')
  //   RelationalOperator: 'Compare' (':1315:2')

  if (FLIGHT_Hexacopter_V2_B.rc_ctrl_switch <=
      FLIGHT_Hexacopter_V2_P.CompareToConstant_const) {
    // SignalConversion generated from: 'Product1' (':160:195')
    FLIGHT_Hexacopter_V2_B.fv[1] = FLIGHT_Hexacopter_V2_B.Sum5_f;
  } else {
    // SignalConversion generated from: 'Product1' (':160:195')
    FLIGHT_Hexacopter_V2_B.fv[1] = FLIGHT_Hexacopter_V2_B.Saturation2;
  }

  // End of Switch: 'Switch' (':1316')

  // SignalConversion generated from: 'Product1' (':160:195')
  FLIGHT_Hexacopter_V2_B.fv[2] = FLIGHT_Hexacopter_V2_B.Sum4;
  FLIGHT_Hexacopter_V2_B.fv[3] = FLIGHT_Hexacopter_V2_B.Sum2_au;

  // Product: 'Product1' (':160:195') incorporates:
  //   Constant: 'Mixer matrix' (':160:192')

  for (FLIGHT_Hexacopter_V2_B.i = 0; FLIGHT_Hexacopter_V2_B.i < 6;
       FLIGHT_Hexacopter_V2_B.i++) {
    FLIGHT_Hexacopter_V2_B.Gain_g[FLIGHT_Hexacopter_V2_B.i] = 0.0F;
  }

  for (FLIGHT_Hexacopter_V2_B.i = 0; FLIGHT_Hexacopter_V2_B.i < 4;
       FLIGHT_Hexacopter_V2_B.i++) {
    FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c =
      FLIGHT_Hexacopter_V2_B.fv[FLIGHT_Hexacopter_V2_B.i];
    for (FLIGHT_Hexacopter_V2_B.ParamStep_g1 = 0;
         FLIGHT_Hexacopter_V2_B.ParamStep_g1 < 6;
         FLIGHT_Hexacopter_V2_B.ParamStep_g1++) {
      FLIGHT_Hexacopter_V2_B.Gain_g[FLIGHT_Hexacopter_V2_B.ParamStep_g1] +=
        FLIGHT_Hexacopter_V2_P.Mixermatrix_Value[6 * FLIGHT_Hexacopter_V2_B.i +
        FLIGHT_Hexacopter_V2_B.ParamStep_g1] *
        FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c;
    }
  }

  // End of Product: 'Product1' (':160:195')
  for (FLIGHT_Hexacopter_V2_B.i = 0; FLIGHT_Hexacopter_V2_B.i < 6;
       FLIGHT_Hexacopter_V2_B.i++) {
    // Saturate: 'Saturation1' (':160:198')
    FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c =
      FLIGHT_Hexacopter_V2_B.Gain_g[FLIGHT_Hexacopter_V2_B.i];
    if (FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c >
        FLIGHT_Hexacopter_V2_P.Saturation1_UpperSat) {
      FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c =
        FLIGHT_Hexacopter_V2_P.Saturation1_UpperSat;
    } else if (FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c <
               FLIGHT_Hexacopter_V2_P.Saturation1_LowerSat) {
      FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c =
        FLIGHT_Hexacopter_V2_P.Saturation1_LowerSat;
    }

    // Sum: 'Add1' (':160:2980') incorporates:
    //   Constant: 'Constant1' (':160:2981')
    //   Gain: 'Gain2' (':160:2979')
    //   Saturate: 'Saturation1' (':160:198')

    FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c = FLIGHT_Hexacopter_V2_P.Gain2_Gain *
      FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c +
      FLIGHT_Hexacopter_V2_P.Constant1_Value_k;
    FLIGHT_Hexacopter_V2_B.Gain_g[FLIGHT_Hexacopter_V2_B.i] =
      FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c;

    // DataTypeConversion: 'Data Type Conversion' (':160:2982')
    FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c = static_cast<real32_T>(floor(
      static_cast<real_T>(FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c)));
    if (rtIsNaNF(FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c) || rtIsInfF
        (FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c)) {
      FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c = 0.0F;
    } else {
      FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c = static_cast<real32_T>(fmod(
        static_cast<real_T>(FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c), 65536.0));
    }

    rtb_DataTypeConversion_g_0 = static_cast<uint16_T>
      (FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c < 0.0F ? static_cast<int32_T>(
        static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
          (-FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c)))) : static_cast<int32_T>(
        static_cast<uint16_T>(FLIGHT_Hexacopter_V2_B.rtb_Gain_g_c)));
    FLIGHT_Hexacopter_V2_B.DataTypeConversion_g[FLIGHT_Hexacopter_V2_B.i] =
      rtb_DataTypeConversion_g_0;

    // End of DataTypeConversion: 'Data Type Conversion' (':160:2982')

    // DataTypeConversion: 'Data Type Conversion6' (':1089') incorporates:
    //   DataTypeConversion: 'Data Type Conversion' (':160:2982')

    FLIGHT_Hexacopter_V2_B.DataTypeConversion6[FLIGHT_Hexacopter_V2_B.i] =
      rtb_DataTypeConversion_g_0;
  }

  // MATLABSystem: 'Read Parameter13' (':1125')
  b_varargout_1 = MW_ParamRead_Step
    (FLIGHT_Hexacopter_V2_DW.obj_oe.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_Hexacopter_V2_B.i);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.i = 0;
  }

  // RateTransition generated from: 'Rate Transition' (':1176')
  if (tmp) {
    // RateTransition generated from: 'Rate Transition' (':1176')
    FLIGHT_Hexacopter_V2_B.rc_inject_failure =
      FLIGHT_Hexacopter_V2_DW.RateTransition_4_Buffer0;
  }

  // RelationalOperator: 'Compare' (':1076:2') incorporates:
  //   Constant: 'Constant' (':1076:3')

  rtb_Compare_n = (FLIGHT_Hexacopter_V2_B.rc_inject_failure >=
                   FLIGHT_Hexacopter_V2_P.CompareToConstant_const_a);

  // MATLABSystem: 'Read Parameter1' (':1124')
  b_varargout_1 = MW_ParamRead_Step
    (FLIGHT_Hexacopter_V2_DW.obj_aw.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_Hexacopter_V2_B.ParamStep_g1);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_g1 = 0;
  }

  // MATLABSystem: 'Read Parameter2' (':1126')
  b_varargout_1 = MW_ParamRead_Step
    (FLIGHT_Hexacopter_V2_DW.obj_ps.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_Hexacopter_V2_B.ParamStep_m);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_m = 0;
  }

  // MATLABSystem: 'Read Parameter3' (':1127')
  b_varargout_1 = MW_ParamRead_Step
    (FLIGHT_Hexacopter_V2_DW.obj_hi.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_Hexacopter_V2_B.ParamStep_n);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_n = 0;
  }

  // MATLABSystem: 'Read Parameter4' (':1128')
  b_varargout_1 = MW_ParamRead_Step
    (FLIGHT_Hexacopter_V2_DW.obj_jg.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_Hexacopter_V2_B.ParamStep_p);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_p = 0;
  }

  // MATLABSystem: 'Read Parameter5' (':1129')
  b_varargout_1 = MW_ParamRead_Step
    (FLIGHT_Hexacopter_V2_DW.obj_ic5.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_Hexacopter_V2_B.ParamStep_l);
  if (b_varargout_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep_l = 0;
  }

  // Switch: 'Switch' (':1142') incorporates:
  //   Constant: 'Constant' (':1077')
  //   DataTypeConversion: 'Data Type Conversion3' (':1086')
  //   MATLABSystem: 'Read Parameter13' (':1125')
  //
  if (rtb_Compare_n) {
    FLIGHT_Hexacopter_V2_B.d = FLIGHT_Hexacopter_V2_B.i;
  } else {
    FLIGHT_Hexacopter_V2_B.d = FLIGHT_Hexacopter_V2_P.Constant_Value_hs;
  }

  // Gain: 'Gain' (':1136:1') incorporates:
  //   Switch: 'Switch' (':1142')

  FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Gain_Gain *
    FLIGHT_Hexacopter_V2_B.d;

  // Saturate: 'Saturation' (':1136:6')
  if (FLIGHT_Hexacopter_V2_B.u0 > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat) {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat;
  } else if (FLIGHT_Hexacopter_V2_B.u0 <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat) {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat;
  }

  // DataTypeConversion: 'Data Type Conversion7' (':1090') incorporates:
  //   Constant: 'Constant' (':1136:4658')
  //   Product: 'Product' (':1136:2')
  //   Saturate: 'Saturation' (':1136:6')
  //   Sum: 'Sum' (':1136:4660')
  //   Sum: 'Sum1' (':1136:4661')

  FLIGHT_Hexacopter_V2_B.d = floor((static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.DataTypeConversion6[0]) -
    FLIGHT_Hexacopter_V2_P.Constant_Value_b) * FLIGHT_Hexacopter_V2_B.u0 +
    FLIGHT_Hexacopter_V2_P.Constant_Value_b);
  if (rtIsNaN(FLIGHT_Hexacopter_V2_B.d) || rtIsInf(FLIGHT_Hexacopter_V2_B.d)) {
    FLIGHT_Hexacopter_V2_B.d = 0.0;
  } else {
    FLIGHT_Hexacopter_V2_B.d = fmod(FLIGHT_Hexacopter_V2_B.d, 65536.0);
  }

  // Switch: 'Switch1' (':1143') incorporates:
  //   Constant: 'Constant1' (':1078')
  //   DataTypeConversion: 'Data Type Conversion2' (':1085')
  //   MATLABSystem: 'Read Parameter1' (':1124')
  //
  if (rtb_Compare_n) {
    FLIGHT_Hexacopter_V2_B.d1 = FLIGHT_Hexacopter_V2_B.ParamStep_g1;
  } else {
    FLIGHT_Hexacopter_V2_B.d1 = FLIGHT_Hexacopter_V2_P.Constant1_Value;
  }

  // Gain: 'Gain' (':1137:1') incorporates:
  //   Switch: 'Switch1' (':1143')

  FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Gain_Gain_l *
    FLIGHT_Hexacopter_V2_B.d1;

  // Saturate: 'Saturation' (':1137:6')
  if (FLIGHT_Hexacopter_V2_B.u0 > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_f)
  {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_f;
  } else if (FLIGHT_Hexacopter_V2_B.u0 <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_a) {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_a;
  }

  // DataTypeConversion: 'Data Type Conversion7' (':1090') incorporates:
  //   Constant: 'Constant' (':1137:4658')
  //   Product: 'Product' (':1137:2')
  //   Saturate: 'Saturation' (':1137:6')
  //   Sum: 'Sum' (':1137:4660')
  //   Sum: 'Sum1' (':1137:4661')

  FLIGHT_Hexacopter_V2_B.d1 = floor((static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.DataTypeConversion6[1]) -
    FLIGHT_Hexacopter_V2_P.Constant_Value_lg) * FLIGHT_Hexacopter_V2_B.u0 +
    FLIGHT_Hexacopter_V2_P.Constant_Value_lg);
  if (rtIsNaN(FLIGHT_Hexacopter_V2_B.d1) || rtIsInf(FLIGHT_Hexacopter_V2_B.d1))
  {
    FLIGHT_Hexacopter_V2_B.d1 = 0.0;
  } else {
    FLIGHT_Hexacopter_V2_B.d1 = fmod(FLIGHT_Hexacopter_V2_B.d1, 65536.0);
  }

  // Switch: 'Switch2' (':1144') incorporates:
  //   Constant: 'Constant2' (':1079')
  //   DataTypeConversion: 'Data Type Conversion' (':1083')
  //   MATLABSystem: 'Read Parameter2' (':1126')
  //
  if (rtb_Compare_n) {
    FLIGHT_Hexacopter_V2_B.d2 = FLIGHT_Hexacopter_V2_B.ParamStep_m;
  } else {
    FLIGHT_Hexacopter_V2_B.d2 = FLIGHT_Hexacopter_V2_P.Constant2_Value;
  }

  // Gain: 'Gain' (':1138:1') incorporates:
  //   Switch: 'Switch2' (':1144')

  FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Gain_Gain_e *
    FLIGHT_Hexacopter_V2_B.d2;

  // Saturate: 'Saturation' (':1138:6')
  if (FLIGHT_Hexacopter_V2_B.u0 > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_e)
  {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_e;
  } else if (FLIGHT_Hexacopter_V2_B.u0 <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_m) {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_m;
  }

  // DataTypeConversion: 'Data Type Conversion7' (':1090') incorporates:
  //   Constant: 'Constant' (':1138:4658')
  //   Product: 'Product' (':1138:2')
  //   Saturate: 'Saturation' (':1138:6')
  //   Sum: 'Sum' (':1138:4660')
  //   Sum: 'Sum1' (':1138:4661')

  FLIGHT_Hexacopter_V2_B.d2 = floor((static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.DataTypeConversion6[2]) -
    FLIGHT_Hexacopter_V2_P.Constant_Value_n) * FLIGHT_Hexacopter_V2_B.u0 +
    FLIGHT_Hexacopter_V2_P.Constant_Value_n);
  if (rtIsNaN(FLIGHT_Hexacopter_V2_B.d2) || rtIsInf(FLIGHT_Hexacopter_V2_B.d2))
  {
    FLIGHT_Hexacopter_V2_B.d2 = 0.0;
  } else {
    FLIGHT_Hexacopter_V2_B.d2 = fmod(FLIGHT_Hexacopter_V2_B.d2, 65536.0);
  }

  // Switch: 'Switch3' (':1145') incorporates:
  //   Constant: 'Constant3' (':1080')
  //   DataTypeConversion: 'Data Type Conversion4' (':1087')
  //   MATLABSystem: 'Read Parameter3' (':1127')
  //
  if (rtb_Compare_n) {
    FLIGHT_Hexacopter_V2_B.d3 = FLIGHT_Hexacopter_V2_B.ParamStep_n;
  } else {
    FLIGHT_Hexacopter_V2_B.d3 = FLIGHT_Hexacopter_V2_P.Constant3_Value;
  }

  // Gain: 'Gain' (':1139:1') incorporates:
  //   Switch: 'Switch3' (':1145')

  FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Gain_Gain_n *
    FLIGHT_Hexacopter_V2_B.d3;

  // Saturate: 'Saturation' (':1139:6')
  if (FLIGHT_Hexacopter_V2_B.u0 > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_a)
  {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_a;
  } else if (FLIGHT_Hexacopter_V2_B.u0 <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d) {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d;
  }

  // DataTypeConversion: 'Data Type Conversion7' (':1090') incorporates:
  //   Constant: 'Constant' (':1139:4658')
  //   Product: 'Product' (':1139:2')
  //   Saturate: 'Saturation' (':1139:6')
  //   Sum: 'Sum' (':1139:4660')
  //   Sum: 'Sum1' (':1139:4661')

  FLIGHT_Hexacopter_V2_B.d3 = floor((static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.DataTypeConversion6[3]) -
    FLIGHT_Hexacopter_V2_P.Constant_Value_e3) * FLIGHT_Hexacopter_V2_B.u0 +
    FLIGHT_Hexacopter_V2_P.Constant_Value_e3);
  if (rtIsNaN(FLIGHT_Hexacopter_V2_B.d3) || rtIsInf(FLIGHT_Hexacopter_V2_B.d3))
  {
    FLIGHT_Hexacopter_V2_B.d3 = 0.0;
  } else {
    FLIGHT_Hexacopter_V2_B.d3 = fmod(FLIGHT_Hexacopter_V2_B.d3, 65536.0);
  }

  // Switch: 'Switch4' (':1146') incorporates:
  //   Constant: 'Constant4' (':1081')
  //   DataTypeConversion: 'Data Type Conversion1' (':1084')
  //   MATLABSystem: 'Read Parameter4' (':1128')
  //
  if (rtb_Compare_n) {
    FLIGHT_Hexacopter_V2_B.d4 = FLIGHT_Hexacopter_V2_B.ParamStep_p;
  } else {
    FLIGHT_Hexacopter_V2_B.d4 = FLIGHT_Hexacopter_V2_P.Constant4_Value;
  }

  // Gain: 'Gain' (':1140:1') incorporates:
  //   Switch: 'Switch4' (':1146')

  FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Gain_Gain_g *
    FLIGHT_Hexacopter_V2_B.d4;

  // Saturate: 'Saturation' (':1140:6')
  if (FLIGHT_Hexacopter_V2_B.u0 > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_en)
  {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_en;
  } else if (FLIGHT_Hexacopter_V2_B.u0 <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_o) {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_o;
  }

  // DataTypeConversion: 'Data Type Conversion7' (':1090') incorporates:
  //   Constant: 'Constant' (':1140:4658')
  //   Product: 'Product' (':1140:2')
  //   Saturate: 'Saturation' (':1140:6')
  //   Sum: 'Sum' (':1140:4660')
  //   Sum: 'Sum1' (':1140:4661')

  FLIGHT_Hexacopter_V2_B.d4 = floor((static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.DataTypeConversion6[4]) -
    FLIGHT_Hexacopter_V2_P.Constant_Value_d) * FLIGHT_Hexacopter_V2_B.u0 +
    FLIGHT_Hexacopter_V2_P.Constant_Value_d);
  if (rtIsNaN(FLIGHT_Hexacopter_V2_B.d4) || rtIsInf(FLIGHT_Hexacopter_V2_B.d4))
  {
    FLIGHT_Hexacopter_V2_B.d4 = 0.0;
  } else {
    FLIGHT_Hexacopter_V2_B.d4 = fmod(FLIGHT_Hexacopter_V2_B.d4, 65536.0);
  }

  // Switch: 'Switch5' (':1147') incorporates:
  //   Constant: 'Constant5' (':1082')
  //   DataTypeConversion: 'Data Type Conversion5' (':1088')
  //   MATLABSystem: 'Read Parameter5' (':1129')
  //
  if (rtb_Compare_n) {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_B.ParamStep_l;
  } else {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Constant5_Value;
  }

  // Gain: 'Gain' (':1141:1') incorporates:
  //   Switch: 'Switch5' (':1147')

  FLIGHT_Hexacopter_V2_B.u0 *= FLIGHT_Hexacopter_V2_P.Gain_Gain_f;

  // Saturate: 'Saturation' (':1141:6')
  if (FLIGHT_Hexacopter_V2_B.u0 > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_k)
  {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_k;
  } else if (FLIGHT_Hexacopter_V2_B.u0 <
             FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_k) {
    FLIGHT_Hexacopter_V2_B.u0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_k;
  }

  // DataTypeConversion: 'Data Type Conversion7' (':1090') incorporates:
  //   Constant: 'Constant' (':1141:4658')
  //   Product: 'Product' (':1141:2')
  //   Saturate: 'Saturation' (':1141:6')
  //   Sum: 'Sum' (':1141:4660')
  //   Sum: 'Sum1' (':1141:4661')

  FLIGHT_Hexacopter_V2_B.u0 = floor((static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.DataTypeConversion6[5]) -
    FLIGHT_Hexacopter_V2_P.Constant_Value_lv) * FLIGHT_Hexacopter_V2_B.u0 +
    FLIGHT_Hexacopter_V2_P.Constant_Value_lv);
  if (rtIsNaN(FLIGHT_Hexacopter_V2_B.u0) || rtIsInf(FLIGHT_Hexacopter_V2_B.u0))
  {
    FLIGHT_Hexacopter_V2_B.u0 = 0.0;
  } else {
    FLIGHT_Hexacopter_V2_B.u0 = fmod(FLIGHT_Hexacopter_V2_B.u0, 65536.0);
  }

  // RateTransition generated from: 'Rate Transition2' (':1298')
  if (tmp) {
    // RateTransition generated from: 'Rate Transition2' (':1298')
    FLIGHT_Hexacopter_V2_B.VehicleStatus_flag_armed =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_16_Buffer0;

    // RateTransition generated from: 'Rate Transition2' (':1298')
    FLIGHT_Hexacopter_V2_B.VehicleStatus_flag_kill =
      FLIGHT_Hexacopter_V2_DW.RateTransition2_17_Buffer0;
  }

  // MATLABSystem: 'PX4 PWM Output' (':1181') incorporates:
  //   DataTypeConversion: 'Data Type Conversion7' (':1090')

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

  // End of MATLABSystem: 'PX4 PWM Output' (':1181')
  FLIGHT_Hexacop_PX4Timestamp(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_pn);

  // BusAssignment: 'Bus Assignment' (':1699') incorporates:
  //   Constant: 'Constant' (':1698:17')

  FLIGHT_Hexacopter_V2_B.BusAssignment = FLIGHT_Hexacopter_V2_P.Constant_Value_g;

  // BusAssignment: 'Bus Assignment' (':1699') incorporates:
  //   DiscreteIntegrator: 'Integrator' (':1820:843')
  //   MATLABSystem: 'PX4 Timestamp' (':1701')
  //   Math: 'Transpose' (':1717')
  //   Sum: 'Diff' (':1523:3')
  //   Sum: 'Diff' (':1524:3')
  //   UnitDelay: 'UD' (':1523:5')
  //
  //  Block description for 'Diff' (':1523:3'):
  //
  //   Add in CPU
  //
  //  Block description for 'Diff' (':1524:3'):
  //
  //   Add in CPU
  //
  //  Block description for 'UD' (':1523:5'):
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
  FLIGHT_Hexacopter_V2_B.BusAssignment.phi_cmd =
    FLIGHT_Hexacopter_V2_B.Product1_m;
  FLIGHT_Hexacopter_V2_B.BusAssignment.phi_cmd_dot =
    FLIGHT_Hexacopter_V2_B.Diff_k;
  FLIGHT_Hexacopter_V2_B.BusAssignment.phi_cmd_ddot =
    FLIGHT_Hexacopter_V2_B.TSamp_d - FLIGHT_Hexacopter_V2_DW.UD_DSTATE_e;
  FLIGHT_Hexacopter_V2_B.BusAssignment.r = FLIGHT_Hexacopter_V2_B.R;

  // MATLABSystem: 'SinkBlock' (':1700:15') incorporates:
  //   BusAssignment: 'Bus Assignment' (':1699')

  uORB_write_step(FLIGHT_Hexacopter_V2_DW.obj_kg.orbMetadataObj,
                  &FLIGHT_Hexacopter_V2_DW.obj_kg.orbAdvertiseObj,
                  &FLIGHT_Hexacopter_V2_B.BusAssignment);
  FLIGHT_Hexac_PX4Timestamp_c(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_e);
  FLIGHT_Hexacop_PX4Timestamp(&FLIGHT_Hexacopter_V2_B.PX4Timestamp);

  // BusAssignment: 'Bus Assignment' (':1288:101') incorporates:
  //   Constant: 'Constant' (':1282')
  //   Gain: 'Gain' (':1283')
  //   MATLABSystem: 'PX4 Timestamp' (':1288:105')
  //   MATLABSystem: 'PX4 Timestamp' (':1287')
  //   Saturate: 'Saturation' (':1284')
  //   Sum: 'Subtract' (':1285')

  FLIGHT_Hexacopter_V2_B.BusAssignment_e.timestamp =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp_e.PX4Timestamp;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e.timestamp_sample =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp.PX4Timestamp;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e.reversible_flags = 0U;
  for (FLIGHT_Hexacopter_V2_B.i = 0; FLIGHT_Hexacopter_V2_B.i < 6;
       FLIGHT_Hexacopter_V2_B.i++) {
    // Saturate: 'Saturation' (':1284')
    rtb_DataTypeConversion_g_0 =
      FLIGHT_Hexacopter_V2_B.DataTypeConversion_g[FLIGHT_Hexacopter_V2_B.i];
    if (rtb_DataTypeConversion_g_0 >
        FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d) {
      rtb_DataTypeConversion_g_0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d;
    } else if (rtb_DataTypeConversion_g_0 <
               FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0) {
      rtb_DataTypeConversion_g_0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0;
    }

    FLIGHT_Hexacopter_V2_B.BusAssignment_e.control[FLIGHT_Hexacopter_V2_B.i] = (
      static_cast<real32_T>(rtb_DataTypeConversion_g_0) -
      FLIGHT_Hexacopter_V2_P.Constant_Value_ew) *
      FLIGHT_Hexacopter_V2_P.Gain_Gain_h;

    // Saturate: 'Saturation' (':1284') incorporates:
    //   Constant: 'Constant' (':1282')
    //   Constant: 'Constant4' (':1269')
    //   Gain: 'Gain' (':1283')
    //   Sum: 'Subtract' (':1285')

    rtb_DataTypeConversion_g_0 =
      FLIGHT_Hexacopter_V2_P.Constant4_Value_f[FLIGHT_Hexacopter_V2_B.i];
    if (rtb_DataTypeConversion_g_0 >
        FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d) {
      rtb_DataTypeConversion_g_0 = FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_d;
    } else if (rtb_DataTypeConversion_g_0 <
               FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0) {
      rtb_DataTypeConversion_g_0 = FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_d0;
    }

    FLIGHT_Hexacopter_V2_B.BusAssignment_e.control[FLIGHT_Hexacopter_V2_B.i + 6]
      = (static_cast<real32_T>(rtb_DataTypeConversion_g_0) -
         FLIGHT_Hexacopter_V2_P.Constant_Value_ew) *
      FLIGHT_Hexacopter_V2_P.Gain_Gain_h;
    FLIGHT_Hexacopter_V2_B.BusAssignment_e._padding0[FLIGHT_Hexacopter_V2_B.i] =
      0U;
  }

  // End of BusAssignment: 'Bus Assignment' (':1288:101')

  // MATLABSystem: 'SinkBlock' (':1288:104:15') incorporates:
  //   BusAssignment: 'Bus Assignment' (':1288:101')

  uORB_write_step(FLIGHT_Hexacopter_V2_DW.obj_nf.orbMetadataObj,
                  &FLIGHT_Hexacopter_V2_DW.obj_nf.orbAdvertiseObj,
                  &FLIGHT_Hexacopter_V2_B.BusAssignment_e);
  FLIGHT_Hexac_PX4Timestamp_c(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_c);

  // BusAssignment: 'Bus Assignment' (':1210:101') incorporates:
  //   MATLABSystem: 'PX4 Timestamp' (':1210:105')

  FLIGHT_Hexacopter_V2_B.BusAssignment_j.timestamp =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp_c.PX4Timestamp;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j.control_power[0] =
    FLIGHT_Hexacopter_V2_B.Sum5_f;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j.control_power[1] =
    FLIGHT_Hexacopter_V2_B.Sum4;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j.control_power[2] =
    FLIGHT_Hexacopter_V2_B.Sum2_au;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j._padding0[0] = 0U;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j._padding0[1] = 0U;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j._padding0[2] = 0U;
  FLIGHT_Hexacopter_V2_B.BusAssignment_j._padding0[3] = 0U;

  // MATLABSystem: 'SinkBlock' (':1210:104:15') incorporates:
  //   BusAssignment: 'Bus Assignment' (':1210:101')

  uORB_write_step(FLIGHT_Hexacopter_V2_DW.obj_fe.orbMetadataObj,
                  &FLIGHT_Hexacopter_V2_DW.obj_fe.orbAdvertiseObj,
                  &FLIGHT_Hexacopter_V2_B.BusAssignment_j);

  // Sum: 'Sum1' (':1999:220:339') incorporates:
  //   Bias: 'Bias1' (':1999:220:375')
  //   Gain: 'Gain1' (':1999:220:340')
  //   Product: 'Product5' (':1999:220:299')
  //   Product: 'Product4' (':1999:220:366')
  //   Sum: 'Sum2' (':1999:220:341')
  //   UnaryMinus: 'Unary Minus' (':1999:220:374')
  //   UnitDelay: 'Unit Delay1' (':1999:220:338')
  //   UnitDelay: 'Unit Delay2' (':1999:220:342')

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_p = ((-FLIGHT_Hexacopter_V2_B.q_i +
    FLIGHT_Hexacopter_V2_P.Bias1_Bias) / FLIGHT_Hexacopter_V2_B.d_c *
    FLIGHT_Hexacopter_V2_B.Product2_d + FLIGHT_Hexacopter_V2_B.In1_k.xyz[2]) *
    FLIGHT_Hexacopter_V2_P.Gain1_Gain_b +
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE;

  // Sum: 'Sum3' (':1999:220:345') incorporates:
  //   Product: 'Product2' (':1999:220:344')
  //   Product: 'Product5' (':1999:220:370')
  //   Sum: 'Add3' (':1999:220:371')
  //   UnitDelay: 'Unit Delay2' (':1999:220:342')

  FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE = FLIGHT_Hexacopter_V2_B.In1_k.xyz[2]
    - 1.0F / FLIGHT_Hexacopter_V2_B.d_c * (FLIGHT_Hexacopter_V2_B.r_m -
    FLIGHT_Hexacopter_V2_B.p_g) * FLIGHT_Hexacopter_V2_B.Product2_d;

  // DeadZone: 'DeadZone' (':2008:660')
  if (FLIGHT_Hexacopter_V2_B.DeadZone_db >
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate2_UpperSaturat) {
    FLIGHT_Hexacopter_V2_B.DeadZone_db -=
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate2_UpperSaturat;
  } else if (FLIGHT_Hexacopter_V2_B.DeadZone_db >=
             FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate2_LowerSaturat) {
    FLIGHT_Hexacopter_V2_B.DeadZone_db = 0.0F;
  } else {
    FLIGHT_Hexacopter_V2_B.DeadZone_db -=
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate2_LowerSaturat;
  }

  // End of DeadZone: 'DeadZone' (':2008:660')

  // RateTransition: 'Rate Transition14' (':2005')
  if (tmp) {
    // RateTransition: 'Rate Transition14' (':2005')
    FLIGHT_Hexacopter_V2_B.RateTransition14_c =
      FLIGHT_Hexacopter_V2_DW.RateTransition14_Buffer0_o;
  }

  // Product: 'IProd Out' (':2008:787')
  FLIGHT_Hexacopter_V2_B.IProdOut_g *= FLIGHT_Hexacopter_V2_B.RateTransition14_c;

  // Sum: 'Sum1' (':1984:220:339') incorporates:
  //   Bias: 'Bias1' (':1984:220:375')
  //   Gain: 'Gain1' (':1984:220:340')
  //   Product: 'Product5' (':1984:220:299')
  //   Product: 'Product4' (':1984:220:366')
  //   Sum: 'Sum2' (':1984:220:341')
  //   UnaryMinus: 'Unary Minus' (':1984:220:374')
  //   UnitDelay: 'Unit Delay1' (':1984:220:338')
  //   UnitDelay: 'Unit Delay2' (':1984:220:342')

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_a = ((-FLIGHT_Hexacopter_V2_B.q_o +
    FLIGHT_Hexacopter_V2_P.Bias1_Bias_o) / FLIGHT_Hexacopter_V2_B.d_g *
    FLIGHT_Hexacopter_V2_B.Product2_l + FLIGHT_Hexacopter_V2_B.In1_k.xyz[1]) *
    FLIGHT_Hexacopter_V2_P.Gain1_Gain_l +
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_c;

  // Sum: 'Sum3' (':1984:220:345') incorporates:
  //   Product: 'Product2' (':1984:220:344')
  //   Product: 'Product5' (':1984:220:370')
  //   Sum: 'Add3' (':1984:220:371')
  //   UnitDelay: 'Unit Delay2' (':1984:220:342')

  FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_c =
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[1] - 1.0F / FLIGHT_Hexacopter_V2_B.d_g *
    (FLIGHT_Hexacopter_V2_B.r_d - FLIGHT_Hexacopter_V2_B.p_l) *
    FLIGHT_Hexacopter_V2_B.Product2_l;

  // DeadZone: 'DeadZone' (':1991:660')
  if (FLIGHT_Hexacopter_V2_B.DeadZone_d >
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate1_UpperSaturat) {
    FLIGHT_Hexacopter_V2_B.DeadZone_d -=
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate1_UpperSaturat;
  } else if (FLIGHT_Hexacopter_V2_B.DeadZone_d >=
             FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate1_LowerSaturat) {
    FLIGHT_Hexacopter_V2_B.DeadZone_d = 0.0F;
  } else {
    FLIGHT_Hexacopter_V2_B.DeadZone_d -=
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate1_LowerSaturat;
  }

  // End of DeadZone: 'DeadZone' (':1991:660')

  // RateTransition: 'Rate Transition9' (':1989')
  if (tmp) {
    // RateTransition: 'Rate Transition9' (':1989')
    FLIGHT_Hexacopter_V2_B.RateTransition9_p =
      FLIGHT_Hexacopter_V2_DW.RateTransition9_Buffer0_h;
  }

  // Product: 'IProd Out' (':1991:787')
  FLIGHT_Hexacopter_V2_B.IProdOut_p *= FLIGHT_Hexacopter_V2_B.RateTransition9_p;

  // Sum: 'Sum1' (':1756:219:333') incorporates:
  //   Bias: 'Bias1' (':1756:219:352')
  //   Gain: 'Gain' (':1756:219:343')
  //   Product: 'Product4' (':1756:219:314')
  //   UnitDelay: 'Unit Delay' (':1756:219:331')

  FLIGHT_Hexacopter_V2_DW.UnitDelay_DSTATE =
    (FLIGHT_Hexacopter_V2_P.Gain_Gain_ar * FLIGHT_Hexacopter_V2_B.Product2_gt +
     FLIGHT_Hexacopter_V2_P.Bias1_Bias_k) * FLIGHT_Hexacopter_V2_B.Sum_o +
    FLIGHT_Hexacopter_V2_B.RateTransition1;

  // Sum: 'Sum1' (':1967:220:339') incorporates:
  //   Bias: 'Bias1' (':1967:220:375')
  //   Gain: 'Gain1' (':1967:220:340')
  //   Product: 'Product5' (':1967:220:299')
  //   Product: 'Product4' (':1967:220:366')
  //   Sum: 'Sum2' (':1967:220:341')
  //   UnaryMinus: 'Unary Minus' (':1967:220:374')
  //   UnitDelay: 'Unit Delay1' (':1967:220:338')
  //   UnitDelay: 'Unit Delay2' (':1967:220:342')

  FLIGHT_Hexacopter_V2_B.q = ((-FLIGHT_Hexacopter_V2_B.q +
    FLIGHT_Hexacopter_V2_P.Bias1_Bias_f) / FLIGHT_Hexacopter_V2_B.d_p *
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE +
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[0]) * FLIGHT_Hexacopter_V2_P.Gain1_Gain_h +
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_i;

  // Product: 'Product2' (':1967:220:344') incorporates:
  //   Product: 'Product5' (':1967:220:370')
  //   Sum: 'Add3' (':1967:220:371')
  //   UnitDelay: 'Unit Delay1' (':1967:220:338')

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE *= 1.0F / FLIGHT_Hexacopter_V2_B.d_p
    * (FLIGHT_Hexacopter_V2_B.r_b - FLIGHT_Hexacopter_V2_B.p);

  // Sum: 'Sum3' (':1967:220:345') incorporates:
  //   UnitDelay: 'Unit Delay1' (':1967:220:338')
  //   UnitDelay: 'Unit Delay2' (':1967:220:342')

  FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_i =
    FLIGHT_Hexacopter_V2_B.In1_k.xyz[0] -
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE;

  // DeadZone: 'DeadZone' (':1978:660')
  if (FLIGHT_Hexacopter_V2_B.DeadZone >
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_UpperSaturati) {
    FLIGHT_Hexacopter_V2_B.DeadZone -=
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_UpperSaturati;
  } else if (FLIGHT_Hexacopter_V2_B.DeadZone >=
             FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_LowerSaturati) {
    FLIGHT_Hexacopter_V2_B.DeadZone = 0.0F;
  } else {
    FLIGHT_Hexacopter_V2_B.DeadZone -=
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_LowerSaturati;
  }

  // End of DeadZone: 'DeadZone' (':1978:660')

  // RateTransition: 'Rate Transition6' (':1982')
  if (tmp) {
    // RateTransition: 'Rate Transition6' (':1982')
    FLIGHT_Hexacopter_V2_B.RateTransition6_o =
      FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_e;
  }

  // Product: 'IProd Out' (':1978:787')
  FLIGHT_Hexacopter_V2_B.IProdOut_b *= FLIGHT_Hexacopter_V2_B.RateTransition6_o;

  // Switch: 'Switch1' (':1978:3943') incorporates:
  //   Constant: 'Clamping_zero' (':1978:4030')
  //   Constant: 'Constant' (':1978:3944')
  //   Constant: 'Constant2' (':1978:3945')
  //   RelationalOperator: 'fix for DT propagation issue' (':1978:4032')

  if (FLIGHT_Hexacopter_V2_B.DeadZone >
      FLIGHT_Hexacopter_V2_P.Clamping_zero_Value_b) {
    tmp_0 = FLIGHT_Hexacopter_V2_P.Constant_Value_dr;
  } else {
    tmp_0 = FLIGHT_Hexacopter_V2_P.Constant2_Value_ns;
  }

  // Switch: 'Switch2' (':1978:3949') incorporates:
  //   Constant: 'Clamping_zero' (':1978:4030')
  //   Constant: 'Constant3' (':1978:3947')
  //   Constant: 'Constant4' (':1978:3948')
  //   RelationalOperator: 'fix for DT propagation issue1' (':1978:4037')

  if (FLIGHT_Hexacopter_V2_B.IProdOut_b >
      FLIGHT_Hexacopter_V2_P.Clamping_zero_Value_b) {
    tmp_1 = FLIGHT_Hexacopter_V2_P.Constant3_Value_n;
  } else {
    tmp_1 = FLIGHT_Hexacopter_V2_P.Constant4_Value_bo;
  }

  // Switch: 'Switch' (':1978:670') incorporates:
  //   Constant: 'Clamping_zero' (':1978:4030')
  //   Constant: 'Constant1' (':1978:655')
  //   Logic: 'AND3' (':1978:653')
  //   RelationalOperator: 'Equal1' (':1978:661')
  //   RelationalOperator: 'Relational Operator' (':1978:4031')
  //   Switch: 'Switch1' (':1978:3943')
  //   Switch: 'Switch2' (':1978:3949')

  if ((FLIGHT_Hexacopter_V2_P.Clamping_zero_Value_b !=
       FLIGHT_Hexacopter_V2_B.DeadZone) && (tmp_0 == tmp_1)) {
    FLIGHT_Hexacopter_V2_B.IProdOut_b = FLIGHT_Hexacopter_V2_P.Constant1_Value_j;
  }

  // Update for DiscreteIntegrator: 'Integrator' (':1978:843') incorporates:
  //   Switch: 'Switch' (':1978:670')

  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE +=
    FLIGHT_Hexacopter_V2_P.Integrator_gainval *
    FLIGHT_Hexacopter_V2_B.IProdOut_b;
  if (FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE >
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_UpperIntegrat) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_UpperIntegrat;
  } else if (FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE <
             FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_LowerIntegrat) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_LowerIntegrat;
  }

  FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState = static_cast<int8_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition15);

  // End of Update for DiscreteIntegrator: 'Integrator' (':1978:843')

  // Update for UnitDelay: 'Unit Delay1' (':1967:220:338')
  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE = FLIGHT_Hexacopter_V2_B.q;

  // Update for UnitDelay: 'UD' (':1966:5')
  //
  //  Block description for 'UD' (':1966:5'):
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE = FLIGHT_Hexacopter_V2_B.TSamp;

  // Update for UnitDelay: 'UD' (':1524:5') incorporates:
  //   SampleTimeMath: 'TSamp' (':1524:4')
  //   Sum: 'Diff' (':1524:3')
  //  *
  //  About 'TSamp' (':1524:4'):
  //   y = u * K where K = 1 / ( w * Ts )
  //    *
  //  About 'TSamp' (':1524:4'):
  //   y = u * K where K = 1 / ( w * Ts )
  //    *
  //  Block description for 'UD' (':1524:5'):
  //
  //   Store in Global RAM
  //
  //  Block description for 'Diff' (':1524:3'):
  //
  //   Add in CPU

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[0] = FLIGHT_Hexacopter_V2_P.TSamp_WtEt_m;
  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[1] =
    FLIGHT_Hexacopter_V2_B.rtb_TSamp_o_idx_1;
  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[2] = FLIGHT_Hexacopter_V2_B.rtb_TSamp_o_f;

  // Update for UnitDelay: 'UD' (':1522:5')
  //
  //  Block description for 'UD' (':1522:5'):
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_o = FLIGHT_Hexacopter_V2_B.TSamp_oi;

  // Update for UnitDelay: 'UD' (':1523:5')
  //
  //  Block description for 'UD' (':1523:5'):
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_e = FLIGHT_Hexacopter_V2_B.TSamp_d;

  // Update for DiscreteIntegrator: 'Filter' (':1817:737')
  FLIGHT_Hexacopter_V2_DW.Filter_DSTATE += FLIGHT_Hexacopter_V2_P.Filter_gainval
    * FLIGHT_Hexacopter_V2_B.FilterCoefficient;

  // Update for DiscreteIntegrator: 'Integrator' (':1820:843') incorporates:
  //   Gain: 'Integral Gain' (':1820:791')

  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_h +=
    FLIGHT_Hexacopter_V2_P.DiscretePIDController2_I *
    FLIGHT_Hexacopter_V2_B.Subtract *
    FLIGHT_Hexacopter_V2_P.Integrator_gainval_c;
  FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_h = static_cast<int8_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition15_l);

  // Update for DiscreteIntegrator: 'Discrete-Time Integrator' (':1887') incorporates:
  //   MATLAB Function: 'MATLAB Function4' (':1578')

  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE +=
    FLIGHT_Hexacopter_V2_B.RateTransition14 * FLIGHT_Hexacopter_V2_B.V *
    FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_gainval;
  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRese = static_cast<int8_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition15_l);

  // Switch: 'Switch1' (':1991:3943') incorporates:
  //   Constant: 'Clamping_zero' (':1991:4030')
  //   Constant: 'Constant' (':1991:3944')
  //   Constant: 'Constant2' (':1991:3945')
  //   RelationalOperator: 'fix for DT propagation issue' (':1991:4032')

  if (FLIGHT_Hexacopter_V2_B.DeadZone_d >
      FLIGHT_Hexacopter_V2_P.Clamping_zero_Value_a) {
    tmp_0 = FLIGHT_Hexacopter_V2_P.Constant_Value_fd;
  } else {
    tmp_0 = FLIGHT_Hexacopter_V2_P.Constant2_Value_g;
  }

  // Switch: 'Switch2' (':1991:3949') incorporates:
  //   Constant: 'Clamping_zero' (':1991:4030')
  //   Constant: 'Constant3' (':1991:3947')
  //   Constant: 'Constant4' (':1991:3948')
  //   RelationalOperator: 'fix for DT propagation issue1' (':1991:4037')

  if (FLIGHT_Hexacopter_V2_B.IProdOut_p >
      FLIGHT_Hexacopter_V2_P.Clamping_zero_Value_a) {
    tmp_1 = FLIGHT_Hexacopter_V2_P.Constant3_Value_b;
  } else {
    tmp_1 = FLIGHT_Hexacopter_V2_P.Constant4_Value_h;
  }

  // Switch: 'Switch' (':1991:670') incorporates:
  //   Constant: 'Clamping_zero' (':1991:4030')
  //   Constant: 'Constant1' (':1991:655')
  //   Logic: 'AND3' (':1991:653')
  //   RelationalOperator: 'Equal1' (':1991:661')
  //   RelationalOperator: 'Relational Operator' (':1991:4031')
  //   Switch: 'Switch1' (':1991:3943')
  //   Switch: 'Switch2' (':1991:3949')

  if ((FLIGHT_Hexacopter_V2_P.Clamping_zero_Value_a !=
       FLIGHT_Hexacopter_V2_B.DeadZone_d) && (tmp_0 == tmp_1)) {
    FLIGHT_Hexacopter_V2_B.IProdOut_p =
      FLIGHT_Hexacopter_V2_P.Constant1_Value_jy;
  }

  // Update for DiscreteIntegrator: 'Integrator' (':1991:843') incorporates:
  //   Switch: 'Switch' (':1991:670')

  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_l +=
    FLIGHT_Hexacopter_V2_P.Integrator_gainval_l *
    FLIGHT_Hexacopter_V2_B.IProdOut_p;
  if (FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_l >
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate1_UpperIntegra) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_l =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate1_UpperIntegra;
  } else if (FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_l <
             FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate1_LowerIntegra) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_l =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate1_LowerIntegra;
  }

  FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_e = static_cast<int8_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition16_e);

  // End of Update for DiscreteIntegrator: 'Integrator' (':1991:843')

  // Update for UnitDelay: 'UD' (':1983:5')
  //
  //  Block description for 'UD' (':1983:5'):
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_b = FLIGHT_Hexacopter_V2_B.absx;

  // Switch: 'Switch1' (':2008:3943') incorporates:
  //   Constant: 'Clamping_zero' (':2008:4030')
  //   Constant: 'Constant' (':2008:3944')
  //   Constant: 'Constant2' (':2008:3945')
  //   RelationalOperator: 'fix for DT propagation issue' (':2008:4032')

  if (FLIGHT_Hexacopter_V2_B.DeadZone_db >
      FLIGHT_Hexacopter_V2_P.Clamping_zero_Value) {
    tmp_0 = FLIGHT_Hexacopter_V2_P.Constant_Value_gl;
  } else {
    tmp_0 = FLIGHT_Hexacopter_V2_P.Constant2_Value_i;
  }

  // Switch: 'Switch2' (':2008:3949') incorporates:
  //   Constant: 'Clamping_zero' (':2008:4030')
  //   Constant: 'Constant3' (':2008:3947')
  //   Constant: 'Constant4' (':2008:3948')
  //   RelationalOperator: 'fix for DT propagation issue1' (':2008:4037')

  if (FLIGHT_Hexacopter_V2_B.IProdOut_g >
      FLIGHT_Hexacopter_V2_P.Clamping_zero_Value) {
    tmp_1 = FLIGHT_Hexacopter_V2_P.Constant3_Value_nf;
  } else {
    tmp_1 = FLIGHT_Hexacopter_V2_P.Constant4_Value_e;
  }

  // Switch: 'Switch' (':2008:670') incorporates:
  //   Constant: 'Clamping_zero' (':2008:4030')
  //   Constant: 'Constant1' (':2008:655')
  //   Logic: 'AND3' (':2008:653')
  //   RelationalOperator: 'Equal1' (':2008:661')
  //   RelationalOperator: 'Relational Operator' (':2008:4031')
  //   Switch: 'Switch1' (':2008:3943')
  //   Switch: 'Switch2' (':2008:3949')

  if ((FLIGHT_Hexacopter_V2_P.Clamping_zero_Value !=
       FLIGHT_Hexacopter_V2_B.DeadZone_db) && (tmp_0 == tmp_1)) {
    FLIGHT_Hexacopter_V2_B.IProdOut_g = FLIGHT_Hexacopter_V2_P.Constant1_Value_i;
  }

  // Update for DiscreteIntegrator: 'Integrator' (':2008:843') incorporates:
  //   Switch: 'Switch' (':2008:670')

  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_o +=
    FLIGHT_Hexacopter_V2_P.Integrator_gainval_e *
    FLIGHT_Hexacopter_V2_B.IProdOut_g;
  if (FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_o >
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate2_UpperIntegra) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_o =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate2_UpperIntegra;
  } else if (FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_o <
             FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate2_LowerIntegra) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_o =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate2_LowerIntegra;
  }

  FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_es = static_cast<int8_T>
    (FLIGHT_Hexacopter_V2_B.RateTransition17_h);

  // End of Update for DiscreteIntegrator: 'Integrator' (':2008:843')

  // Update for UnitDelay: 'UD' (':1998:5')
  //
  //  Block description for 'UD' (':1998:5'):
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_d = FLIGHT_Hexacopter_V2_B.TSamp_p;
}

// Model step function for TID1
void FLIGHT_Hexacopter_V2_step1(void)  // Sample time: [0.004s, 0.0s]
{
  int32_T tmp;
  real32_T Theta_idx_0;
  real32_T rtb_Filter_k_idx_0;
  real32_T rtb_Filter_k_idx_1;
  real32_T rtb_Gain7;
  real32_T rtb_NProdOut_idx_0;
  real32_T rtb_Sum2_i;
  real32_T rtb_Switch_gd_idx_0;
  real32_T rtb_Switch_gd_idx_1;
  real32_T rtb_read_mc_rollrate_p_o1;
  real32_T rtb_sincos_o1_idx_1;
  real32_T rtb_sincos_o1_idx_2;
  boolean_T rtb_AND;
  boolean_T rtb_AND1;
  boolean_T rtb_AND2;
  boolean_T rtb_XOR;
  boolean_T rtb_flag_alt;
  boolean_T rtb_flag_pos;

  // MATLABSystem: 'SourceBlock' (':281:9')
  rtb_flag_pos = uORB_read_step(FLIGHT_Hexacopter_V2_DW.obj_n.orbMetadataObj,
    &FLIGHT_Hexacopter_V2_DW.obj_n.eventStructObj, &FLIGHT_Hexacopter_V2_B.r2,
    false, 1.0);

  // Outputs for Enabled SubSystem: 'Enabled Subsystem' (':281:3') incorporates:
  //   EnablePort: 'Enable' (':281:5')

  // Start for MATLABSystem: 'SourceBlock' (':281:9')
  if (rtb_flag_pos) {
    // SignalConversion generated from: 'In1' (':281:4')
    FLIGHT_Hexacopter_V2_B.In1_p = FLIGHT_Hexacopter_V2_B.r2;
  }

  // End of Outputs for SubSystem: 'Enabled Subsystem' (':281:3')

  // Gain: 'Gain3' (':384') incorporates:
  //   Constant: 'Constant3' (':355')
  //   DataTypeConversion: 'Data Type Conversion3' (':359')
  //   Sum: 'Sum3' (':411')

  FLIGHT_Hexacopter_V2_B.Gain7 = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[0]) -
    FLIGHT_Hexacopter_V2_P.Constant3_Value_h) *
    FLIGHT_Hexacopter_V2_P.Gain3_Gain;

  // DeadZone: 'Dead Zone' (':364')
  if (FLIGHT_Hexacopter_V2_B.Gain7 > FLIGHT_Hexacopter_V2_P.DeadZone_End) {
    rtb_sincos_o1_idx_2 = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone_End;
  } else if (FLIGHT_Hexacopter_V2_B.Gain7 >=
             FLIGHT_Hexacopter_V2_P.DeadZone_Start) {
    rtb_sincos_o1_idx_2 = 0.0F;
  } else {
    rtb_sincos_o1_idx_2 = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone_Start;
  }

  // End of DeadZone: 'Dead Zone' (':364')

  // Gain: 'Gain1' (':381') incorporates:
  //   Constant: 'Constant2' (':354')
  //   DataTypeConversion: 'Data Type Conversion4' (':360')
  //   Sum: 'Sum2' (':410')

  FLIGHT_Hexacopter_V2_B.Gain7 = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[2]) -
    FLIGHT_Hexacopter_V2_P.Constant2_Value_e) *
    FLIGHT_Hexacopter_V2_P.Gain1_Gain_f;

  // DeadZone: 'Dead Zone1' (':365')
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

  // End of DeadZone: 'Dead Zone1' (':365')

  // Gain: 'Gain2' (':383') incorporates:
  //   Constant: 'Constant1' (':353')
  //   DataTypeConversion: 'Data Type Conversion5' (':361')
  //   Sum: 'Sum1' (':409')

  FLIGHT_Hexacopter_V2_B.Gain7 = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[3]) -
    FLIGHT_Hexacopter_V2_P.Constant1_Value_c) *
    FLIGHT_Hexacopter_V2_P.Gain2_Gain_l;

  // DeadZone: 'Dead Zone2' (':366')
  if (FLIGHT_Hexacopter_V2_B.Gain7 > FLIGHT_Hexacopter_V2_P.DeadZone2_End) {
    FLIGHT_Hexacopter_V2_B.Sum2_g = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone2_End;
  } else if (FLIGHT_Hexacopter_V2_B.Gain7 >=
             FLIGHT_Hexacopter_V2_P.DeadZone2_Start) {
    FLIGHT_Hexacopter_V2_B.Sum2_g = 0.0F;
  } else {
    FLIGHT_Hexacopter_V2_B.Sum2_g = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone2_Start;
  }

  // End of DeadZone: 'Dead Zone2' (':366')

  // Saturate: 'Saturation1' (':401')
  if (FLIGHT_Hexacopter_V2_B.Sum2_g >
      FLIGHT_Hexacopter_V2_P.Saturation1_UpperSat_p) {
    FLIGHT_Hexacopter_V2_B.Sum2_g =
      FLIGHT_Hexacopter_V2_P.Saturation1_UpperSat_p;
  } else if (FLIGHT_Hexacopter_V2_B.Sum2_g <
             FLIGHT_Hexacopter_V2_P.Saturation1_LowerSat_e) {
    FLIGHT_Hexacopter_V2_B.Sum2_g =
      FLIGHT_Hexacopter_V2_P.Saturation1_LowerSat_e;
  }

  // Gain: 'Gain6' (':387') incorporates:
  //   Saturate: 'Saturation1' (':401')

  FLIGHT_Hexacopter_V2_B.Gain6 = FLIGHT_Hexacopter_V2_P.MAX_CONTROL_ANGLE_RATE_Y
    * FLIGHT_Hexacopter_V2_B.Sum2_g;

  // Gain: 'Gain' (':380') incorporates:
  //   Constant: 'Constant' (':352')
  //   DataTypeConversion: 'Data Type Conversion6' (':362')
  //   Sum: 'Sum' (':408')

  FLIGHT_Hexacopter_V2_B.Gain7 = static_cast<real32_T>((static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[1]) -
    FLIGHT_Hexacopter_V2_P.Constant_Value_k3) *
    FLIGHT_Hexacopter_V2_P.Gain_Gain_b);

  // DeadZone: 'Dead Zone3' (':367')
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

  // End of DeadZone: 'Dead Zone3' (':367')

  // Fcn: 'Fcn3' (':373') incorporates:
  //   DataTypeConversion: 'Data Type Conversion11' (':358')

  FLIGHT_Hexacopter_V2_B.Gain7 = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[1]) - 1514.0F) / 420.0F;

  // DeadZone: 'Dead Zone7' (':370')
  if (FLIGHT_Hexacopter_V2_B.Gain7 > FLIGHT_Hexacopter_V2_P.DeadZone7_End) {
    FLIGHT_Hexacopter_V2_B.Sum2_g = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone7_End;
  } else if (FLIGHT_Hexacopter_V2_B.Gain7 >=
             FLIGHT_Hexacopter_V2_P.DeadZone7_Start) {
    FLIGHT_Hexacopter_V2_B.Sum2_g = 0.0F;
  } else {
    FLIGHT_Hexacopter_V2_B.Sum2_g = FLIGHT_Hexacopter_V2_B.Gain7 -
      FLIGHT_Hexacopter_V2_P.DeadZone7_Start;
  }

  // End of DeadZone: 'Dead Zone7' (':370')

  // MATLABSystem: 'Read Parameter39' (':1856')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_g.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // Saturate: 'Saturation10' (':402')
  if (FLIGHT_Hexacopter_V2_B.Sum2_g >
      FLIGHT_Hexacopter_V2_P.Saturation10_UpperSat) {
    FLIGHT_Hexacopter_V2_B.Sum2_g = FLIGHT_Hexacopter_V2_P.Saturation10_UpperSat;
  } else if (FLIGHT_Hexacopter_V2_B.Sum2_g <
             FLIGHT_Hexacopter_V2_P.Saturation10_LowerSat) {
    FLIGHT_Hexacopter_V2_B.Sum2_g = FLIGHT_Hexacopter_V2_P.Saturation10_LowerSat;
  }

  // Gain: 'Gain7' (':1862') incorporates:
  //   MATLABSystem: 'Read Parameter39' (':1856')
  //   Product: 'Product' (':1855')
  //   Saturate: 'Saturation10' (':402')
  //
  FLIGHT_Hexacopter_V2_B.Gain7 = FLIGHT_Hexacopter_V2_B.Sum2_g *
    FLIGHT_Hexacopter_V2_B.ParamStep * FLIGHT_Hexacopter_V2_P.Gain7_Gain;

  // MATLABSystem: 'SourceBlock' (':320:9')
  rtb_flag_pos = uORB_read_step(FLIGHT_Hexacopter_V2_DW.obj_l.orbMetadataObj,
    &FLIGHT_Hexacopter_V2_DW.obj_l.eventStructObj, &FLIGHT_Hexacopter_V2_B.r,
    false, 1.0);

  // Outputs for Enabled SubSystem: 'Enabled Subsystem' (':320:3') incorporates:
  //   EnablePort: 'Enable' (':320:5')

  // Start for MATLABSystem: 'SourceBlock' (':320:9')
  if (rtb_flag_pos) {
    // SignalConversion generated from: 'In1' (':320:4')
    FLIGHT_Hexacopter_V2_B.In1 = FLIGHT_Hexacopter_V2_B.r;
  }

  // End of Outputs for SubSystem: 'Enabled Subsystem' (':320:3')

  // Sum: 'Sum1' (':1821:8')
  FLIGHT_Hexacopter_V2_B.roll = FLIGHT_Hexacopter_V2_B.Gain7 -
    FLIGHT_Hexacopter_V2_B.In1.vz;

  // MATLABSystem: 'Read Parameter3' (':212')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_c4.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  FLIGHT_Hexacopt_SourceBlock(&FLIGHT_Hexacopter_V2_B.SourceBlock_l,
    &FLIGHT_Hexacopter_V2_DW.SourceBlock_l);

  // Outputs for Enabled SubSystem: 'Enabled Subsystem' (':318:3') incorporates:
  //   EnablePort: 'Enable' (':318:5')

  if (FLIGHT_Hexacopter_V2_B.SourceBlock_l.SourceBlock_o1) {
    // SignalConversion generated from: 'In1' (':318:4') incorporates:
    //   MATLABSystem: 'SourceBlock' (':318:9')

    FLIGHT_Hexacopter_V2_B.In1_e =
      FLIGHT_Hexacopter_V2_B.SourceBlock_l.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: 'Enabled Subsystem' (':318:3')

  // Logic: 'AND' (':428') incorporates:
  //   Constant: 'Constant' (':429:3')
  //   RelationalOperator: 'Compare' (':429:2')

  rtb_AND = (FLIGHT_Hexacopter_V2_B.In1_p.values[5] >
             FLIGHT_Hexacopter_V2_P.CompareToConstant1_const) ^
    FLIGHT_Hexacopter_V2_B.In1_e.armed;

  // DiscreteIntegrator: 'Integrator' (':1821:10:843')
  if ((rtb_AND && (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_l <= 0)) ||
      ((!rtb_AND) && (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_l == 1)))
  {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_lu =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCond_p;
  }

  // MATLABSystem: 'Read Parameter5' (':214')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_ia.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_k);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_k = 0.0F;
  }

  // Sum: 'Sum' (':1821:2:220:337') incorporates:
  //   UnitDelay: 'Unit Delay1' (':1821:2:220:338')

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i += FLIGHT_Hexacopter_V2_B.In1.vz;

  // MATLABSystem: 'Read Parameter11' (':196')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_jk.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_c);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_c = 0.0F;
  }

  // MATLAB Function: 'MATLAB Function' (':192') incorporates:
  //   MATLABSystem: 'Read Parameter11' (':196')
  //
  // :  w_radps = w_hz * 2*pi;
  FLIGHT_Hexacopter_V2_B.w_radps = FLIGHT_Hexacopter_V2_B.ParamStep_c * 2.0F *
    3.14159274F;

  // Gain: 'tau' (':1821:2:220:372')
  FLIGHT_Hexacopter_V2_B.p_j = FLIGHT_Hexacopter_V2_P.tau_Gain_g *
    FLIGHT_Hexacopter_V2_B.w_radps;

  // Product: 'Product2' (':1821:2:220:361')
  FLIGHT_Hexacopter_V2_B.q_c = FLIGHT_Hexacopter_V2_B.p_j *
    FLIGHT_Hexacopter_V2_B.p_j;

  // Bias: 'Bias' (':1821:2:220:373')
  FLIGHT_Hexacopter_V2_B.r_o = FLIGHT_Hexacopter_V2_B.q_c +
    FLIGHT_Hexacopter_V2_P.Bias_Bias_n;

  // Gain: 'Gain' (':1821:2:220:358')
  FLIGHT_Hexacopter_V2_B.p_j *= FLIGHT_Hexacopter_V2_P.Gain_Gain_oj;

  // Sum: 'Add1' (':1821:2:220:364')
  FLIGHT_Hexacopter_V2_B.d_n = FLIGHT_Hexacopter_V2_B.r_o +
    FLIGHT_Hexacopter_V2_B.p_j;

  // SampleTimeMath: 'TSamp' (':1821:1:4') incorporates:
  //   Product: 'Product1' (':1821:2:220:343')
  //   Product: 'Product3' (':1821:2:220:365')
  //   UnitDelay: 'Unit Delay1' (':1821:2:220:338')
  //
  //  About 'TSamp' (':1821:1:4'):
  //   y = u * K where K = 1 / ( w * Ts )
  //
  FLIGHT_Hexacopter_V2_B.TSamp_ku = FLIGHT_Hexacopter_V2_B.q_c /
    FLIGHT_Hexacopter_V2_B.d_n * FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i *
    FLIGHT_Hexacopter_V2_P.TSamp_WtEt_n;

  // MATLABSystem: 'Read Parameter26' (':423')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_lt.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_c);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_c = 0.0F;
  }

  // MATLAB Function: 'MATLAB Function2' (':1854') incorporates:
  //   DiscreteIntegrator: 'Integrator' (':1821:10:843')
  //   MATLABSystem: 'Read Parameter26' (':423')
  //   MATLABSystem: 'Read Parameter3' (':212')
  //   MATLABSystem: 'Read Parameter5' (':214')
  //   Product: 'PProd Out' (':1821:10:909')
  //   Product: 'Product2' (':1821:7')
  //   Sum: 'Diff' (':1821:1:3')
  //   Sum: 'Sum' (':1821:10:3518')
  //   Sum: 'Sum5' (':1821:9')
  //   UnitDelay: 'UD' (':1821:1:5')
  //  *
  //  Block description for 'Diff' (':1821:1:3'):
  //
  //   Add in CPU
  //
  //  Block description for 'UD' (':1821:1:5'):
  //
  //   Store in Global RAM

  // :  des_throttle = thr_hover - a_z/9.81;
  FLIGHT_Hexacopter_V2_B.des_throttle = FLIGHT_Hexacopter_V2_B.ParamStep_c -
    ((FLIGHT_Hexacopter_V2_B.roll * FLIGHT_Hexacopter_V2_B.ParamStep +
      FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_lu) -
     (FLIGHT_Hexacopter_V2_B.TSamp_ku - FLIGHT_Hexacopter_V2_DW.UD_DSTATE_a) *
     FLIGHT_Hexacopter_V2_B.ParamStep_k) / 9.81F;

  // MATLABSystem: 'Read Parameter28' (':528')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_ic.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // MATLABSystem: 'Read Parameter27' (':479')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_l3.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_k);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_k = 0.0F;
  }

  // Fcn: 'Fcn2' (':372') incorporates:
  //   DataTypeConversion: 'Data Type Conversion1' (':357')

  FLIGHT_Hexacopter_V2_B.Sum2_g = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[0]) - 1514.0F) / 420.0F;

  // DeadZone: 'Dead Zone6' (':369')
  if (FLIGHT_Hexacopter_V2_B.Sum2_g > FLIGHT_Hexacopter_V2_P.DeadZone6_End) {
    rtb_Sum2_i = FLIGHT_Hexacopter_V2_B.Sum2_g -
      FLIGHT_Hexacopter_V2_P.DeadZone6_End;
  } else if (FLIGHT_Hexacopter_V2_B.Sum2_g >=
             FLIGHT_Hexacopter_V2_P.DeadZone6_Start) {
    rtb_Sum2_i = 0.0F;
  } else {
    rtb_Sum2_i = FLIGHT_Hexacopter_V2_B.Sum2_g -
      FLIGHT_Hexacopter_V2_P.DeadZone6_Start;
  }

  // End of DeadZone: 'Dead Zone6' (':369')

  // MATLABSystem: 'Read Parameter40' (':1867')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_pn.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_c);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_c = 0.0F;
  }

  // Fcn: 'Fcn1' (':371') incorporates:
  //   DataTypeConversion: 'Data Type Conversion7' (':363')

  FLIGHT_Hexacopter_V2_B.Sum2_g = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.In1_p.values[2]) - 1514.0F) / 420.0F;

  // DeadZone: 'Dead Zone4' (':368')
  // :  R_b2i = [cos(heading), -sin(heading); sin(heading), cos(heading)];
  // body to inertia
  // :  V = R_b2i * [vx_b; vy_b];
  if (FLIGHT_Hexacopter_V2_B.Sum2_g > FLIGHT_Hexacopter_V2_P.DeadZone4_End) {
    FLIGHT_Hexacopter_V2_B.Sum2_g -= FLIGHT_Hexacopter_V2_P.DeadZone4_End;
  } else if (FLIGHT_Hexacopter_V2_B.Sum2_g >=
             FLIGHT_Hexacopter_V2_P.DeadZone4_Start) {
    FLIGHT_Hexacopter_V2_B.Sum2_g = 0.0F;
  } else {
    FLIGHT_Hexacopter_V2_B.Sum2_g -= FLIGHT_Hexacopter_V2_P.DeadZone4_Start;
  }

  // End of DeadZone: 'Dead Zone4' (':368')

  // Saturate: 'Saturation4' (':405')
  if (FLIGHT_Hexacopter_V2_B.Sum2_g >
      FLIGHT_Hexacopter_V2_P.Saturation4_UpperSat) {
    FLIGHT_Hexacopter_V2_B.Sum2_g = FLIGHT_Hexacopter_V2_P.Saturation4_UpperSat;
  } else if (FLIGHT_Hexacopter_V2_B.Sum2_g <
             FLIGHT_Hexacopter_V2_P.Saturation4_LowerSat) {
    FLIGHT_Hexacopter_V2_B.Sum2_g = FLIGHT_Hexacopter_V2_P.Saturation4_LowerSat;
  }

  // MATLAB Function: 'MATLAB Function3' (':2041') incorporates:
  //   Gain: 'Gain9' (':1883')
  //   MATLABSystem: 'Read Parameter40' (':1867')
  //   Product: 'Product2' (':1866')
  //   Saturate: 'Saturation4' (':405')
  //
  FLIGHT_Hexacopter_V2_B.Sum2_g = FLIGHT_Hexacopter_V2_B.Sum2_g *
    FLIGHT_Hexacopter_V2_B.ParamStep_c * FLIGHT_Hexacopter_V2_P.Gain9_Gain;

  // Saturate: 'Saturation9' (':407')
  if (rtb_Sum2_i > FLIGHT_Hexacopter_V2_P.Saturation9_UpperSat) {
    rtb_Sum2_i = FLIGHT_Hexacopter_V2_P.Saturation9_UpperSat;
  } else if (rtb_Sum2_i < FLIGHT_Hexacopter_V2_P.Saturation9_LowerSat) {
    rtb_Sum2_i = FLIGHT_Hexacopter_V2_P.Saturation9_LowerSat;
  }

  // MATLAB Function: 'MATLAB Function3' (':2041') incorporates:
  //   Gain: 'Gain8' (':1882')
  //   MATLABSystem: 'Read Parameter40' (':1867')
  //   Product: 'Product1' (':1865')
  //   Saturate: 'Saturation9' (':407')
  //
  rtb_Sum2_i = rtb_Sum2_i * FLIGHT_Hexacopter_V2_B.ParamStep_c *
    FLIGHT_Hexacopter_V2_P.Gain8_Gain;
  FLIGHT_Hexacopter_V2_B.ParamStep_c = static_cast<real32_T>(cos
    (static_cast<real_T>(FLIGHT_Hexacopter_V2_B.In1.heading))) *
    FLIGHT_Hexacopter_V2_B.Sum2_g + -static_cast<real32_T>(sin
    (static_cast<real_T>(FLIGHT_Hexacopter_V2_B.In1.heading))) * rtb_Sum2_i;
  rtb_Sum2_i = static_cast<real32_T>(sin(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.In1.heading))) * FLIGHT_Hexacopter_V2_B.Sum2_g +
    static_cast<real32_T>(cos(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.In1.heading))) * rtb_Sum2_i;

  // Logic: 'AND1' (':448') incorporates:
  //   Constant: 'Constant' (':449:3')
  //   Constant: 'Constant' (':1881:3')
  //   Constant: 'Constant' (':2137:3')
  //   MATLAB Function: 'MATLAB Function3' (':2041')
  //   RelationalOperator: 'Compare' (':449:2')
  //   RelationalOperator: 'Compare' (':1881:2')
  //   RelationalOperator: 'Compare' (':2137:2')

  // :  vx_i = V(1);
  // :  vy_i = V(2);
  rtb_AND1 = static_cast<boolean_T>(static_cast<boolean_T>
    ((FLIGHT_Hexacopter_V2_B.In1_p.values[5] >
      FLIGHT_Hexacopter_V2_P.CompareToConstant2_const) ^
     FLIGHT_Hexacopter_V2_B.In1_e.armed) ^ (FLIGHT_Hexacopter_V2_B.ParamStep_c ==
    FLIGHT_Hexacopter_V2_P.CompareToConstant6_const)) ^
    (FLIGHT_Hexacopter_V2_B.In1_p.values[10] >
     FLIGHT_Hexacopter_V2_P.CompareToConstant7_const);

  // DiscreteIntegrator: 'Discrete-Time Integrator' (':436')
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

  // Logic: 'AND2' (':1872') incorporates:
  //   Constant: 'Constant' (':1876:3')
  //   Constant: 'Constant' (':1880:3')
  //   Constant: 'Constant' (':2138:3')
  //   MATLAB Function: 'MATLAB Function3' (':2041')
  //   RelationalOperator: 'Compare' (':1876:2')
  //   RelationalOperator: 'Compare' (':1880:2')
  //   RelationalOperator: 'Compare' (':2138:2')

  rtb_AND2 = static_cast<boolean_T>(static_cast<boolean_T>
    ((FLIGHT_Hexacopter_V2_B.In1_p.values[5] >
      FLIGHT_Hexacopter_V2_P.CompareToConstant4_const) ^
     FLIGHT_Hexacopter_V2_B.In1_e.armed) ^ (rtb_Sum2_i ==
    FLIGHT_Hexacopter_V2_P.CompareToConstant5_const)) ^
    (FLIGHT_Hexacopter_V2_B.In1_p.values[10] >
     FLIGHT_Hexacopter_V2_P.CompareToConstant8_const);

  // DiscreteIntegrator: 'Discrete-Time Integrator1' (':437')
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

  // MATLAB Function: 'MATLAB Function5' (':2069') incorporates:
  //   Constant: 'Constant' (':2118:3')
  //   Constant: 'Constant5' (':2114')
  //   DataTypeConversion: 'Data Type Conversion16' (':2129')
  //   DataTypeConversion: 'Data Type Conversion17' (':2130')
  //   RelationalOperator: 'Compare' (':2118:2')

  //  X: Current Position NED
  //  L: Length of Square Waypoint
  //  flag: Engage WP Flight
  // :  if(isempty(X0))
  // :  if(isempty(WP_num))
  // :  if(isempty(WP))
  // %%%%% Code %%%%%%%
  // :  if(flag)
  if (FLIGHT_Hexacopter_V2_B.In1_p.values[10] >=
      FLIGHT_Hexacopter_V2_P.CompareToConstant_const_p) {
    //  Engage WP Flight
    //  Generate WP first Time
    // :  if(WP_num < 1)
    if (FLIGHT_Hexacopter_V2_DW.WP_num < 1.0) {
      // :  R_b2i = [cos(heading), -sin(heading); sin(heading), cos(heading)];
      // body to inertia
      // :  WP_b = [
      // :          X0(1),X0(2);
      // :          X0(1)+L,X0(2);
      // :          X0(1)+L,X0(2)+L;
      // :          X0(1), X0(2)+L;
      // :          X0(1), X0(2)];
      // :  WP = R_b2i * WP_b';
      FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_0 = cos(static_cast<real_T>
        (FLIGHT_Hexacopter_V2_B.In1.heading));
      FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_1 = sin(static_cast<real_T>
        (FLIGHT_Hexacopter_V2_B.In1.heading));
      FLIGHT_Hexacopter_V2_B.out_yawrate = sin(static_cast<real_T>
        (FLIGHT_Hexacopter_V2_B.In1.heading));
      FLIGHT_Hexacopter_V2_B.reletive_time_sec = cos(static_cast<real_T>
        (FLIGHT_Hexacopter_V2_B.In1.heading));
      FLIGHT_Hexacopter_V2_B.dv[0] = FLIGHT_Hexacopter_V2_DW.X0[0];
      FLIGHT_Hexacopter_V2_B.dv[1] = FLIGHT_Hexacopter_V2_DW.X0[1];
      FLIGHT_Hexacopter_V2_B.dv[2] = FLIGHT_Hexacopter_V2_DW.X0[0] +
        FLIGHT_Hexacopter_V2_P.Constant5_Value_j;
      FLIGHT_Hexacopter_V2_B.dv[3] = FLIGHT_Hexacopter_V2_DW.X0[1];
      FLIGHT_Hexacopter_V2_B.dv[4] = FLIGHT_Hexacopter_V2_DW.X0[0] +
        FLIGHT_Hexacopter_V2_P.Constant5_Value_j;
      FLIGHT_Hexacopter_V2_B.dv[5] = FLIGHT_Hexacopter_V2_DW.X0[1] +
        FLIGHT_Hexacopter_V2_P.Constant5_Value_j;
      FLIGHT_Hexacopter_V2_B.dv[6] = FLIGHT_Hexacopter_V2_DW.X0[0];
      FLIGHT_Hexacopter_V2_B.dv[7] = FLIGHT_Hexacopter_V2_DW.X0[1] +
        FLIGHT_Hexacopter_V2_P.Constant5_Value_j;
      FLIGHT_Hexacopter_V2_B.dv[8] = FLIGHT_Hexacopter_V2_DW.X0[0];
      FLIGHT_Hexacopter_V2_B.dv[9] = FLIGHT_Hexacopter_V2_DW.X0[1];
      for (FLIGHT_Hexacopter_V2_B.ParamStep_g = 0;
           FLIGHT_Hexacopter_V2_B.ParamStep_g < 5;
           FLIGHT_Hexacopter_V2_B.ParamStep_g++) {
        tmp = FLIGHT_Hexacopter_V2_B.ParamStep_g << 1;
        FLIGHT_Hexacopter_V2_B.peak_angle_rad = FLIGHT_Hexacopter_V2_B.dv[tmp];
        FLIGHT_Hexacopter_V2_B.WP = FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_0 *
          FLIGHT_Hexacopter_V2_B.peak_angle_rad;
        FLIGHT_Hexacopter_V2_B.WP_m = FLIGHT_Hexacopter_V2_B.out_yawrate *
          FLIGHT_Hexacopter_V2_B.peak_angle_rad;
        FLIGHT_Hexacopter_V2_B.peak_angle_rad = FLIGHT_Hexacopter_V2_B.dv[tmp +
          1];
        FLIGHT_Hexacopter_V2_DW.WP[tmp] =
          -FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_1 *
          FLIGHT_Hexacopter_V2_B.peak_angle_rad + FLIGHT_Hexacopter_V2_B.WP;
        FLIGHT_Hexacopter_V2_DW.WP[tmp + 1] =
          FLIGHT_Hexacopter_V2_B.reletive_time_sec *
          FLIGHT_Hexacopter_V2_B.peak_angle_rad + FLIGHT_Hexacopter_V2_B.WP_m;
      }
    }

    // :  WP_idx = rem(WP_num, length(WP)) + 1;
    // :  Current_WP = WP(:,WP_idx);
    FLIGHT_Hexacopter_V2_B.ParamStep_g = (static_cast<int32_T>(rt_remd_snf
      (FLIGHT_Hexacopter_V2_DW.WP_num, 5.0) + 1.0) - 1) << 1;
    FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_0 =
      FLIGHT_Hexacopter_V2_DW.WP[FLIGHT_Hexacopter_V2_B.ParamStep_g];
    FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_1 =
      FLIGHT_Hexacopter_V2_DW.WP[FLIGHT_Hexacopter_V2_B.ParamStep_g + 1];

    // :  distance = sqrt((Current_WP(1)-X(1))^2 + (Current_WP(2)-X(2))^2);
    FLIGHT_Hexacopter_V2_B.out_yawrate = FLIGHT_Hexacopter_V2_DW.WP[(
      static_cast<int32_T>(rt_remd_snf(FLIGHT_Hexacopter_V2_DW.WP_num, 5.0) +
      1.0) - 1) << 1] - FLIGHT_Hexacopter_V2_B.In1.x;
    FLIGHT_Hexacopter_V2_B.reletive_time_sec = FLIGHT_Hexacopter_V2_DW.WP[((
      static_cast<int32_T>(rt_remd_snf(FLIGHT_Hexacopter_V2_DW.WP_num, 5.0) +
      1.0) - 1) << 1) + 1] - FLIGHT_Hexacopter_V2_B.In1.y;

    // :  if(distance < 0.2)
    if (sqrt(FLIGHT_Hexacopter_V2_B.out_yawrate *
             FLIGHT_Hexacopter_V2_B.out_yawrate +
             FLIGHT_Hexacopter_V2_B.reletive_time_sec *
             FLIGHT_Hexacopter_V2_B.reletive_time_sec) < 0.2) {
      //  0.2m 이내라면
      // :  WP_num = WP_num+1;
      FLIGHT_Hexacopter_V2_DW.WP_num++;
    }
  } else {
    // :  else
    //  Stop
    // :  X0 = [0, 0];
    //  Update Reference Position
    // :  WP_num = 0;
    FLIGHT_Hexacopter_V2_DW.WP_num = 0.0;

    //  Reset WP Order
    // :  Current_WP = X0';
    FLIGHT_Hexacopter_V2_DW.X0[0] = 0.0;
    FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_0 = 0.0;
    FLIGHT_Hexacopter_V2_DW.X0[1] = 0.0;
    FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_1 = 0.0;
  }

  // End of MATLAB Function: 'MATLAB Function5' (':2069')

  // Switch: 'Switch' (':2119') incorporates:
  //   DataTypeConversion: 'Data Type Conversion18' (':2126')
  //   DiscreteIntegrator: 'Discrete-Time Integrator' (':436')
  //   DiscreteIntegrator: 'Discrete-Time Integrator1' (':437')

  if (FLIGHT_Hexacopter_V2_B.In1_p.values[10] >
      FLIGHT_Hexacopter_V2_P.Switch_Threshold) {
    rtb_Switch_gd_idx_0 = static_cast<real32_T>
      (FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_0);
    rtb_Switch_gd_idx_1 = static_cast<real32_T>
      (FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_1);
  } else {
    rtb_Switch_gd_idx_0 =
      FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE_c;
    rtb_Switch_gd_idx_1 = FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE;
  }

  // End of Switch: 'Switch' (':2119')

  // Product: 'PProd Out' (':2050:909') incorporates:
  //   MATLABSystem: 'Read Parameter27' (':479')
  //   Sum: 'Sum4' (':2051')
  //
  FLIGHT_Hexacopter_V2_B.Sum2_g = (rtb_Switch_gd_idx_0 -
    FLIGHT_Hexacopter_V2_B.In1.x) * FLIGHT_Hexacopter_V2_B.ParamStep_k;
  rtb_NProdOut_idx_0 = (rtb_Switch_gd_idx_1 - FLIGHT_Hexacopter_V2_B.In1.y) *
    FLIGHT_Hexacopter_V2_B.ParamStep_k;

  // Saturate: 'Saturation' (':2050:923')
  if (FLIGHT_Hexacopter_V2_B.Sum2_g >
      FLIGHT_Hexacopter_V2_P.DiscretePIDController_UpperSatu) {
    FLIGHT_Hexacopter_V2_B.Sum2_g =
      FLIGHT_Hexacopter_V2_P.DiscretePIDController_UpperSatu;
  } else if (FLIGHT_Hexacopter_V2_B.Sum2_g <
             FLIGHT_Hexacopter_V2_P.DiscretePIDController_LowerSatu) {
    FLIGHT_Hexacopter_V2_B.Sum2_g =
      FLIGHT_Hexacopter_V2_P.DiscretePIDController_LowerSatu;
  }

  // Sum: 'Sum7' (':517') incorporates:
  //   Saturate: 'Saturation' (':2050:923')

  rtb_Filter_k_idx_0 = FLIGHT_Hexacopter_V2_B.Sum2_g -
    FLIGHT_Hexacopter_V2_B.In1.vx;

  // Saturate: 'Saturation' (':2050:923')
  if (rtb_NProdOut_idx_0 >
      FLIGHT_Hexacopter_V2_P.DiscretePIDController_UpperSatu) {
    rtb_NProdOut_idx_0 = FLIGHT_Hexacopter_V2_P.DiscretePIDController_UpperSatu;
  } else if (rtb_NProdOut_idx_0 <
             FLIGHT_Hexacopter_V2_P.DiscretePIDController_LowerSatu) {
    rtb_NProdOut_idx_0 = FLIGHT_Hexacopter_V2_P.DiscretePIDController_LowerSatu;
  }

  // Sum: 'Sum7' (':517') incorporates:
  //   Saturate: 'Saturation' (':2050:923')

  rtb_Filter_k_idx_1 = rtb_NProdOut_idx_0 - FLIGHT_Hexacopter_V2_B.In1.vy;

  // Logic: 'XOR' (':2031')
  rtb_XOR = rtb_AND1 ^ rtb_AND2;

  // MATLABSystem: 'Read Parameter45' (':2023')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_k.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_k);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_k = 0.0F;
  }

  // DiscreteIntegrator: 'Integrator' (':514:843') incorporates:
  //   DiscreteIntegrator: 'Filter' (':514:737')

  rtb_flag_alt = !rtb_XOR;
  if ((rtb_XOR && (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_l3 <= 0)) ||
      (rtb_flag_alt && (FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_l3 ==
                        1))) {
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_k[0] =
      FLIGHT_Hexacopter_V2_P.PID_Altitude1_InitialConditio_f;
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_k[1] =
      FLIGHT_Hexacopter_V2_P.PID_Altitude1_InitialConditio_f;
  }

  // DiscreteIntegrator: 'Integrator' (':514:843') incorporates:
  //   MATLABSystem: 'Read Parameter45' (':2023')
  //   Product: 'IProd Out' (':514:787')
  //
  FLIGHT_Hexacopter_V2_B.Sum2_g = rtb_Filter_k_idx_0 *
    FLIGHT_Hexacopter_V2_B.ParamStep_k *
    FLIGHT_Hexacopter_V2_P.Integrator_gainval_f +
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_k[0];
  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_k[0] = FLIGHT_Hexacopter_V2_B.Sum2_g;

  // DiscreteIntegrator: 'Integrator' (':514:843')
  if (FLIGHT_Hexacopter_V2_B.Sum2_g >
      FLIGHT_Hexacopter_V2_P.PID_Altitude1_UpperIntegratorSa) {
    // DiscreteIntegrator: 'Integrator' (':514:843')
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_k[0] =
      FLIGHT_Hexacopter_V2_P.PID_Altitude1_UpperIntegratorSa;
  } else if (FLIGHT_Hexacopter_V2_B.Sum2_g <
             FLIGHT_Hexacopter_V2_P.PID_Altitude1_LowerIntegratorSa) {
    // DiscreteIntegrator: 'Integrator' (':514:843')
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_k[0] =
      FLIGHT_Hexacopter_V2_P.PID_Altitude1_LowerIntegratorSa;
  }

  // DiscreteIntegrator: 'Integrator' (':514:843') incorporates:
  //   MATLABSystem: 'Read Parameter45' (':2023')
  //   Product: 'IProd Out' (':514:787')
  //
  FLIGHT_Hexacopter_V2_B.Sum2_g = rtb_Filter_k_idx_1 *
    FLIGHT_Hexacopter_V2_B.ParamStep_k *
    FLIGHT_Hexacopter_V2_P.Integrator_gainval_f +
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_k[1];
  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_k[1] = FLIGHT_Hexacopter_V2_B.Sum2_g;

  // DiscreteIntegrator: 'Integrator' (':514:843')
  if (FLIGHT_Hexacopter_V2_B.Sum2_g >
      FLIGHT_Hexacopter_V2_P.PID_Altitude1_UpperIntegratorSa) {
    // DiscreteIntegrator: 'Integrator' (':514:843')
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_k[1] =
      FLIGHT_Hexacopter_V2_P.PID_Altitude1_UpperIntegratorSa;
  } else if (FLIGHT_Hexacopter_V2_B.Sum2_g <
             FLIGHT_Hexacopter_V2_P.PID_Altitude1_LowerIntegratorSa) {
    // DiscreteIntegrator: 'Integrator' (':514:843')
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_k[1] =
      FLIGHT_Hexacopter_V2_P.PID_Altitude1_LowerIntegratorSa;
  }

  // MATLABSystem: 'Read Parameter46' (':2024')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_pc.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_k);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_k = 0.0F;
  }

  // DiscreteIntegrator: 'Filter' (':514:737')
  if ((rtb_XOR && (FLIGHT_Hexacopter_V2_DW.Filter_PrevResetState <= 0)) ||
      (rtb_flag_alt && (FLIGHT_Hexacopter_V2_DW.Filter_PrevResetState == 1))) {
    FLIGHT_Hexacopter_V2_DW.Filter_DSTATE_i[0] =
      FLIGHT_Hexacopter_V2_P.PID_Altitude1_InitialConditionF;
    FLIGHT_Hexacopter_V2_DW.Filter_DSTATE_i[1] =
      FLIGHT_Hexacopter_V2_P.PID_Altitude1_InitialConditionF;
  }

  // Product: 'NProd Out' (':514:878') incorporates:
  //   Constant: 'Constant4' (':2034')
  //   DiscreteIntegrator: 'Filter' (':514:737')
  //   MATLABSystem: 'Read Parameter46' (':2024')
  //   Product: 'DProd Out' (':514:684')
  //   Sum: 'SumD' (':514:738')
  //
  // :  g = 9.81;
  // :  d2r = pi/180;
  // :  R_psi_inv= [sin(heading), -cos(heading); cos(heading), sin(heading)];
  // :  Theta = -1/g * R_psi_inv * a_cmd;
  FLIGHT_Hexacopter_V2_B.Sum2_g = (rtb_Filter_k_idx_0 *
    FLIGHT_Hexacopter_V2_B.ParamStep_k -
    FLIGHT_Hexacopter_V2_DW.Filter_DSTATE_i[0]) *
    FLIGHT_Hexacopter_V2_P.Constant4_Value_b;
  rtb_NProdOut_idx_0 = FLIGHT_Hexacopter_V2_B.Sum2_g;

  // Sum: 'Sum' (':514:3526') incorporates:
  //   MATLABSystem: 'Read Parameter28' (':528')
  //   Product: 'DProd Out' (':514:684')
  //   Product: 'PProd Out' (':514:909')
  //
  rtb_Filter_k_idx_0 = (rtb_Filter_k_idx_0 * FLIGHT_Hexacopter_V2_B.ParamStep +
                        FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_k[0]) +
    FLIGHT_Hexacopter_V2_B.Sum2_g;

  // Product: 'NProd Out' (':514:878') incorporates:
  //   Constant: 'Constant4' (':2034')
  //   DiscreteIntegrator: 'Filter' (':514:737')
  //   MATLABSystem: 'Read Parameter46' (':2024')
  //   Product: 'DProd Out' (':514:684')
  //   Sum: 'SumD' (':514:738')
  //
  FLIGHT_Hexacopter_V2_B.Sum2_g = (rtb_Filter_k_idx_1 *
    FLIGHT_Hexacopter_V2_B.ParamStep_k -
    FLIGHT_Hexacopter_V2_DW.Filter_DSTATE_i[1]) *
    FLIGHT_Hexacopter_V2_P.Constant4_Value_b;

  // Sum: 'Sum' (':514:3526') incorporates:
  //   MATLABSystem: 'Read Parameter28' (':528')
  //   Product: 'DProd Out' (':514:684')
  //   Product: 'PProd Out' (':514:909')
  //
  rtb_Filter_k_idx_1 = (rtb_Filter_k_idx_1 * FLIGHT_Hexacopter_V2_B.ParamStep +
                        FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_k[1]) +
    FLIGHT_Hexacopter_V2_B.Sum2_g;

  // MATLAB Function: 'MATLAB Function4' (':2059')
  Theta_idx_0 = -0.101936802F * static_cast<real32_T>(sin(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.In1.heading))) * rtb_Filter_k_idx_0 + -0.101936802F *
    -static_cast<real32_T>(cos(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.In1.heading))) * rtb_Filter_k_idx_1;
  rtb_Filter_k_idx_0 = -0.101936802F * static_cast<real32_T>(cos
    (static_cast<real_T>(FLIGHT_Hexacopter_V2_B.In1.heading))) *
    rtb_Filter_k_idx_0 + -0.101936802F * static_cast<real32_T>(sin
    (static_cast<real_T>(FLIGHT_Hexacopter_V2_B.In1.heading))) *
    rtb_Filter_k_idx_1;

  // MATLABSystem: 'SourceBlock' (':319:9')
  // :  des_phi = min(Theta(1), 20*d2r);
  // :  des_theta = min(Theta(2), 20*d2r);
  rtb_flag_pos = uORB_read_step(FLIGHT_Hexacopter_V2_DW.obj_a.orbMetadataObj,
    &FLIGHT_Hexacopter_V2_DW.obj_a.eventStructObj, &FLIGHT_Hexacopter_V2_B.r3,
    false, 1.0);

  // Outputs for Enabled SubSystem: 'Enabled Subsystem' (':319:3') incorporates:
  //   EnablePort: 'Enable' (':319:5')

  // Start for MATLABSystem: 'SourceBlock' (':319:9')
  if (rtb_flag_pos) {
    // SignalConversion generated from: 'In1' (':319:4')
    FLIGHT_Hexacopter_V2_B.In1_m = FLIGHT_Hexacopter_V2_B.r3;
  }

  // End of Outputs for SubSystem: 'Enabled Subsystem' (':319:3')

  // MATLAB Function: 'MATLAB Function' (':317')
  // :  if(nav_stat == 1)
  switch (FLIGHT_Hexacopter_V2_B.In1_m.nav_state) {
   case 1U:
    //  ALT Mode
    // :  flag_pos = false;
    rtb_flag_pos = false;

    // :  flag_alt = true;
    rtb_flag_alt = true;

    // :  flag_stab = false;
    break;

   case 2U:
    // :  elseif(nav_stat == 2)
    //  POS Mode
    // :  flag_pos = true;
    rtb_flag_pos = true;

    // :  flag_alt = false;
    rtb_flag_alt = false;

    // :  flag_stab = false;
    break;

   default:
    // :  else
    //  STAB mode
    // :  flag_pos = false;
    rtb_flag_pos = false;

    // :  flag_alt = false;
    rtb_flag_alt = false;

    // :  flag_stab = true;
    break;
  }

  // End of MATLAB Function: 'MATLAB Function' (':317')

  // MATLAB Function: 'MATLAB Function4' (':2059')
  if (!(Theta_idx_0 <= 0.34906584F)) {
    // SignalConversion generated from: ' SFunction ' (':537::33') incorporates:
    //   MATLAB Function: 'MATLAB Function' (':537')

    Theta_idx_0 = 0.34906584F;
  }

  if (!(rtb_Filter_k_idx_0 <= 0.34906584F)) {
    // SignalConversion generated from: ' SFunction ' (':537::33') incorporates:
    //   MATLAB Function: 'MATLAB Function' (':537')

    rtb_Filter_k_idx_0 = 0.34906584F;
  }

  // MATLAB Function: 'MATLAB Function' (':537') incorporates:
  //   Gain: 'Gain4' (':385')
  //   Gain: 'Gain5' (':386')
  //   Saturate: 'Saturation2' (':403')
  //   Saturate: 'Saturation3' (':404')

  // :  if(mode >= 1800 && flag_pos_mode)
  if ((FLIGHT_Hexacopter_V2_B.In1_p.values[5] < 1800) || (!rtb_flag_pos)) {
    if ((FLIGHT_Hexacopter_V2_B.In1_p.values[5] < 1800) &&
        (FLIGHT_Hexacopter_V2_B.In1_p.values[5] >= 1400) && rtb_flag_alt) {
      // Saturate: 'Saturation3' (':404')
      // :  elseif(mode <1800 && mode >=1400 && flag_alt_mode)
      //  Altitude
      // :  y = alt_u;
      if (rtb_sincos_o1_idx_2 > FLIGHT_Hexacopter_V2_P.Saturation3_UpperSat) {
        rtb_sincos_o1_idx_2 = FLIGHT_Hexacopter_V2_P.Saturation3_UpperSat;
      } else if (rtb_sincos_o1_idx_2 <
                 FLIGHT_Hexacopter_V2_P.Saturation3_LowerSat) {
        rtb_sincos_o1_idx_2 = FLIGHT_Hexacopter_V2_P.Saturation3_LowerSat;
      }

      Theta_idx_0 = FLIGHT_Hexacopter_V2_P.MAX_CONTROL_ANGLE_ROLL *
        rtb_sincos_o1_idx_2;

      // Saturate: 'Saturation2' (':403') incorporates:
      //   Gain: 'Gain4' (':385')
      //   Saturate: 'Saturation3' (':404')

      if (rtb_sincos_o1_idx_1 > FLIGHT_Hexacopter_V2_P.Saturation2_UpperSat_c) {
        rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Saturation2_UpperSat_c;
      } else if (rtb_sincos_o1_idx_1 <
                 FLIGHT_Hexacopter_V2_P.Saturation2_LowerSat_h) {
        rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Saturation2_LowerSat_h;
      }

      rtb_Filter_k_idx_0 = FLIGHT_Hexacopter_V2_P.MAX_CONTROL_ANGLE_PITCH *
        rtb_sincos_o1_idx_1;
    } else {
      // Saturate: 'Saturation3' (':404')
      // :  else
      //  Stablized
      // :  y = stab_u;
      if (rtb_sincos_o1_idx_2 > FLIGHT_Hexacopter_V2_P.Saturation3_UpperSat) {
        rtb_sincos_o1_idx_2 = FLIGHT_Hexacopter_V2_P.Saturation3_UpperSat;
      } else if (rtb_sincos_o1_idx_2 <
                 FLIGHT_Hexacopter_V2_P.Saturation3_LowerSat) {
        rtb_sincos_o1_idx_2 = FLIGHT_Hexacopter_V2_P.Saturation3_LowerSat;
      }

      Theta_idx_0 = FLIGHT_Hexacopter_V2_P.MAX_CONTROL_ANGLE_ROLL *
        rtb_sincos_o1_idx_2;

      // Saturate: 'Saturation2' (':403') incorporates:
      //   Gain: 'Gain4' (':385')
      //   Saturate: 'Saturation3' (':404')

      if (rtb_sincos_o1_idx_1 > FLIGHT_Hexacopter_V2_P.Saturation2_UpperSat_c) {
        rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Saturation2_UpperSat_c;
      } else if (rtb_sincos_o1_idx_1 <
                 FLIGHT_Hexacopter_V2_P.Saturation2_LowerSat_h) {
        rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Saturation2_LowerSat_h;
      }

      rtb_Filter_k_idx_0 = FLIGHT_Hexacopter_V2_P.MAX_CONTROL_ANGLE_PITCH *
        rtb_sincos_o1_idx_1;

      // Saturate: 'Saturation' (':400') incorporates:
      //   Gain: 'Gain5' (':386')
      //   Saturate: 'Saturation2' (':403')

      if (rtb_Gain7 > FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_h) {
        FLIGHT_Hexacopter_V2_B.des_throttle =
          FLIGHT_Hexacopter_V2_P.Saturation_UpperSat_h;
      } else if (rtb_Gain7 < FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_p) {
        FLIGHT_Hexacopter_V2_B.des_throttle =
          FLIGHT_Hexacopter_V2_P.Saturation_LowerSat_p;
      } else {
        FLIGHT_Hexacopter_V2_B.des_throttle = rtb_Gain7;
      }

      // End of Saturate: 'Saturation' (':400')
    }
  } else {
    //  position
    // :  y = pos_u;
  }

  // RateTransition: 'Rate Transition4' (':1068')
  FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0 =
    FLIGHT_Hexacopter_V2_B.des_throttle;

  // MATLABSystem: 'SourceBlock' (':326:6:9')
  rtb_flag_pos = uORB_read_step(FLIGHT_Hexacopter_V2_DW.obj_i.orbMetadataObj,
    &FLIGHT_Hexacopter_V2_DW.obj_i.eventStructObj, &FLIGHT_Hexacopter_V2_B.r1,
    false, 1.0);

  // Outputs for Enabled SubSystem: 'Enabled Subsystem' (':326:6:3') incorporates:
  //   EnablePort: 'Enable' (':326:6:5')

  // Start for MATLABSystem: 'SourceBlock' (':326:6:9')
  if (rtb_flag_pos) {
    // SignalConversion generated from: 'In1' (':326:6:4')
    FLIGHT_Hexacopter_V2_B.In1_b = FLIGHT_Hexacopter_V2_B.r1;
  }

  // End of Outputs for SubSystem: 'Enabled Subsystem' (':326:6:3')

  // MATLAB Function: 'quat2eul' (':327')
  //  Quaternion conversion to Euler angles based on the PX4 Firmware v1.10.2
  //  release.
  // :  phi = atan2(2*(q(1)*q(2) + q(3)* q(4)), q(1)^2 - q(2)^2 - q(3)^2 + q(4)^2); 
  // :  theta = asin(-2*(q(2)*q(4) - q(1)*q(3)));
  // :  psi = atan2(2*(q(2)*q(3) + q(1)* q(4)), q(1)^2 + q(2)^2 - q(3)^2 - q(4)^2); 
  // :  ypr = [psi theta phi];
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

  // RateTransition: 'Rate Transition2' (':884')
  FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[0] =
    FLIGHT_Hexacopter_V2_B.ypr[0];
  FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[1] =
    FLIGHT_Hexacopter_V2_B.ypr[1];
  FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[2] =
    FLIGHT_Hexacopter_V2_B.ypr[2];

  // RelationalOperator: 'Compare' (':623:2') incorporates:
  //   Constant: 'Constant' (':623:3')

  rtb_flag_alt = (FLIGHT_Hexacopter_V2_B.In1_p.values[6] >=
                  FLIGHT_Hexacopter_V2_P.CompareToConstant3_const);

  // MATLABSystem: 'PX4 Timestamp' (':642')
  FLIGHT_Hexacopter_V2_B.rtb_PX4Timestamp_c = hrt_absolute_time();

  // MATLABSystem: 'Read Parameter1' (':194')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_l4.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // MATLABSystem: 'Read Parameter' (':193')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_jf.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_k);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_k = 0.0F;
  }

  // MATLABSystem: 'Read Parameter2' (':205')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_a1.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_Hexacopter_V2_B.ParamStep_g);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_g = 0;
  }

  // MATLAB Function: 'MATLAB Function1' (':641') incorporates:
  //   DataTypeConversion: 'Data Type Conversion' (':624')
  //   DataTypeConversion: 'Data Type Conversion10' (':628')
  //   DataTypeConversion: 'Data Type Conversion12' (':629')
  //   DataTypeConversion: 'Data Type Conversion2' (':625')
  //   DataTypeConversion: 'Data Type Conversion8' (':626')
  //   DataTypeConversion: 'Data Type Conversion9' (':627')
  //   MATLABSystem: 'PX4 Timestamp' (':642')
  //   MATLABSystem: 'Read Parameter' (':193')
  //   MATLABSystem: 'Read Parameter1' (':194')
  //   MATLABSystem: 'Read Parameter2' (':205')
  //
  FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_0 = Theta_idx_0;
  FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_1 = rtb_Filter_k_idx_0;
  FLIGHT_Hexacopter_V2_B.out_yawrate = FLIGHT_Hexacopter_V2_B.Gain6;

  // :  if(isempty(start_time_usec))
  // :  if(flag && start_time_usec == -1)
  if (rtb_flag_alt && (FLIGHT_Hexacopter_V2_DW.start_time_usec == -1.0)) {
    // :  start_time_usec = time_usec;
    FLIGHT_Hexacopter_V2_DW.start_time_usec = static_cast<real_T>
      (FLIGHT_Hexacopter_V2_B.rtb_PX4Timestamp_c);
  }

  // :  d2r = pi/180;
  // :  if (flag && start_time_usec > 0)
  if (rtb_flag_alt && (FLIGHT_Hexacopter_V2_DW.start_time_usec > 0.0)) {
    //  time calculation
    // :  reletive_time_sec = double(time_usec - start_time_usec)*1e-6;
    FLIGHT_Hexacopter_V2_B.reletive_time_sec = (static_cast<real_T>
      (FLIGHT_Hexacopter_V2_B.rtb_PX4Timestamp_c) -
      FLIGHT_Hexacopter_V2_DW.start_time_usec) * 1.0E-6;
  } else {
    // :  else
    // :  start_time_usec = -1;
    FLIGHT_Hexacopter_V2_DW.start_time_usec = -1.0;

    // :  reletive_time_sec = 0;
    FLIGHT_Hexacopter_V2_B.reletive_time_sec = 0.0;
  }

  //  Define Doublet
  // :  t1 = 0;
  // :  t2 = t1+doublet_dt;
  // :  t3 = t2+doublet_dt;
  // :  peak_angle_rad = peak_angle_deg * d2r;
  FLIGHT_Hexacopter_V2_B.peak_angle_rad = FLIGHT_Hexacopter_V2_B.ParamStep *
    0.017453292519943295;

  //  Default Output
  // :  out_roll = in_roll;
  // :  out_pitch = in_pitch;
  // :  out_yawrate = in_yawrate;
  //  Generate Doublet Command
  // :  if(flag)
  if (rtb_flag_alt) {
    // :  if(reletive_time_sec >= t1 && reletive_time_sec < t2)
    if ((!(FLIGHT_Hexacopter_V2_B.reletive_time_sec >= 0.0)) ||
        (!(FLIGHT_Hexacopter_V2_B.reletive_time_sec <
           FLIGHT_Hexacopter_V2_B.ParamStep_k))) {
      if ((FLIGHT_Hexacopter_V2_B.reletive_time_sec >=
           FLIGHT_Hexacopter_V2_B.ParamStep_k) &&
          (FLIGHT_Hexacopter_V2_B.reletive_time_sec < static_cast<real_T>
           (FLIGHT_Hexacopter_V2_B.ParamStep_k) +
           FLIGHT_Hexacopter_V2_B.ParamStep_k)) {
        // :  elseif(reletive_time_sec >= t2 && reletive_time_sec < t3)
        // :  cmd = -peak_angle_rad;
        FLIGHT_Hexacopter_V2_B.peak_angle_rad =
          -FLIGHT_Hexacopter_V2_B.peak_angle_rad;
      } else {
        // :  else
        // :  cmd = 0;
        FLIGHT_Hexacopter_V2_B.peak_angle_rad = 0.0;
      }
    } else {
      // :  cmd = peak_angle_rad;
    }

    // :  switch(double(doublet_axis))
    switch (FLIGHT_Hexacopter_V2_B.ParamStep_g) {
     case 1:
      // :  case 1
      // :  out_roll = cmd;
      FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_0 =
        FLIGHT_Hexacopter_V2_B.peak_angle_rad;
      break;

     case 2:
      // :  case 2
      // :  out_pitch = cmd;
      FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_1 =
        FLIGHT_Hexacopter_V2_B.peak_angle_rad;
      break;

     case 3:
      // :  case 3
      // :  out_yawrate = cmd;
      FLIGHT_Hexacopter_V2_B.out_yawrate = FLIGHT_Hexacopter_V2_B.peak_angle_rad;
      break;
    }
  }

  // End of MATLAB Function: 'MATLAB Function1' (':641')

  // Gain: '1//2' (':1231:2') incorporates:
  //   Constant: 'Constant1' (':1239')
  //   DataTypeConversion: 'Data Type Conversion13' (':630')
  //   DataTypeConversion: 'Data Type Conversion14' (':631')

  FLIGHT_Hexacopter_V2_B.Gain6 = FLIGHT_Hexacopter_V2_P.u2_Gain *
    FLIGHT_Hexacopter_V2_P.Constant1_Value_fy;
  rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.u2_Gain * static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_1);
  rtb_sincos_o1_idx_2 = FLIGHT_Hexacopter_V2_P.u2_Gain * static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_0);

  // Trigonometry: 'sincos' (':1231:9')
  FLIGHT_Hexacopter_V2_B.ParamStep = static_cast<real32_T>(cos
    (static_cast<real_T>(FLIGHT_Hexacopter_V2_B.Gain6)));
  rtb_Gain7 = static_cast<real32_T>(sin(static_cast<real_T>
    (FLIGHT_Hexacopter_V2_B.Gain6)));
  rtb_Filter_k_idx_0 = static_cast<real32_T>(cos(static_cast<real_T>
    (rtb_sincos_o1_idx_1)));
  Theta_idx_0 = static_cast<real32_T>(sin(static_cast<real_T>
    (rtb_sincos_o1_idx_1)));
  rtb_Filter_k_idx_1 = static_cast<real32_T>(cos(static_cast<real_T>
    (rtb_sincos_o1_idx_2)));
  FLIGHT_Hexacopter_V2_B.ParamStep_k = static_cast<real32_T>(sin
    (static_cast<real_T>(rtb_sincos_o1_idx_2)));
  FLIGHT_Hexac_PX4Timestamp_j(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_j);

  // BusAssignment: 'Bus Assignment' (':1230:101') incorporates:
  //   DataTypeConversion: 'Data Type Conversion13' (':630')
  //   DataTypeConversion: 'Data Type Conversion14' (':631')
  //   DataTypeConversion: 'Data Type Conversion15' (':632')
  //   MATLABSystem: 'PX4 Timestamp' (':1230:105')

  FLIGHT_Hexacopter_V2_B.BusAssignment_f.timestamp =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp_j.PX4Timestamp;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.roll_body = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_0);
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.pitch_body = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_1);
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.yaw_body = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_0);
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.yaw_sp_move_rate = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_yawrate);

  // Fcn: 'q0' (':1231:5') incorporates:
  //   Fcn: 'q1' (':1231:6')
  //   Trigonometry: 'sincos' (':1231:9')

  rtb_sincos_o1_idx_2 = FLIGHT_Hexacopter_V2_B.ParamStep * rtb_Filter_k_idx_0;
  rtb_sincos_o1_idx_1 = rtb_Gain7 * Theta_idx_0;

  // BusAssignment: 'Bus Assignment' (':1230:101') incorporates:
  //   Fcn: 'q0' (':1231:5')
  //   Fcn: 'q1' (':1231:6')
  //   Trigonometry: 'sincos' (':1231:9')

  FLIGHT_Hexacopter_V2_B.BusAssignment_f.q_d[0] = rtb_sincos_o1_idx_2 *
    rtb_Filter_k_idx_1 + rtb_sincos_o1_idx_1 *
    FLIGHT_Hexacopter_V2_B.ParamStep_k;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.q_d[1] = rtb_sincos_o1_idx_2 *
    FLIGHT_Hexacopter_V2_B.ParamStep_k - rtb_sincos_o1_idx_1 *
    rtb_Filter_k_idx_1;

  // Fcn: 'q2' (':1231:7') incorporates:
  //   Fcn: 'q3' (':1231:8')
  //   Trigonometry: 'sincos' (':1231:9')

  rtb_sincos_o1_idx_2 = rtb_Gain7 * rtb_Filter_k_idx_0;
  rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_B.ParamStep * Theta_idx_0;

  // BusAssignment: 'Bus Assignment' (':1230:101') incorporates:
  //   Constant: 'Constant' (':1224')
  //   Fcn: 'q2' (':1231:7')
  //   Fcn: 'q3' (':1231:8')
  //   Trigonometry: 'sincos' (':1231:9')

  FLIGHT_Hexacopter_V2_B.BusAssignment_f.q_d[2] = rtb_sincos_o1_idx_1 *
    rtb_Filter_k_idx_1 + rtb_sincos_o1_idx_2 *
    FLIGHT_Hexacopter_V2_B.ParamStep_k;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.q_d[3] = rtb_sincos_o1_idx_2 *
    rtb_Filter_k_idx_1 - rtb_sincos_o1_idx_1 *
    FLIGHT_Hexacopter_V2_B.ParamStep_k;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.thrust_body[0] =
    FLIGHT_Hexacopter_V2_P.Constant_Value_i;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.thrust_body[1] =
    FLIGHT_Hexacopter_V2_P.Constant_Value_i;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.thrust_body[2] =
    FLIGHT_Hexacopter_V2_B.des_throttle;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.reset_integral = false;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f.fw_control_yaw_wheel = false;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f._padding0[0] = 0U;
  FLIGHT_Hexacopter_V2_B.BusAssignment_f._padding0[1] = 0U;

  // MATLABSystem: 'SinkBlock' (':1230:104:15') incorporates:
  //   BusAssignment: 'Bus Assignment' (':1230:101')

  uORB_write_step(FLIGHT_Hexacopter_V2_DW.obj_m1.orbMetadataObj,
                  &FLIGHT_Hexacopter_V2_DW.obj_m1.orbAdvertiseObj,
                  &FLIGHT_Hexacopter_V2_B.BusAssignment_f);

  // RateTransition: 'Rate Transition1' (':733') incorporates:
  //   DataTypeConversion: 'Data Type Conversion15' (':632')

  FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_g = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_yawrate);

  // RateTransition: 'Rate Transition20' (':2014') incorporates:
  //   DataTypeConversion: 'Data Type Conversion15' (':632')

  FLIGHT_Hexacopter_V2_DW.RateTransition20_Buffer0 = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_yawrate);
  FLIGHT_Hexac_PX4Timestamp_j(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_p);

  // MATLABSystem: 'Read Parameter9' (':218')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_ai.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // Gain: 'Gain1' (':190:180') incorporates:
  //   MATLABSystem: 'Read Parameter9' (':218')
  //
  rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Gain1_Gain_o *
    FLIGHT_Hexacopter_V2_B.ParamStep;

  // MATLABSystem: 'Read Parameter6' (':215')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_p.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // Product: 'PProd Out' (':685:909') incorporates:
  //   DataTypeConversion: 'Data Type Conversion14' (':631')
  //   MATLABSystem: 'Read Parameter6' (':215')
  //   Sum: 'Sum3' (':687')
  //
  rtb_sincos_o1_idx_2 = (static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_0) - FLIGHT_Hexacopter_V2_B.ypr[2])
    * FLIGHT_Hexacopter_V2_B.ParamStep;

  // Switch: 'Switch2' (':685:3846:8') incorporates:
  //   RelationalOperator: 'LowerRelop1' (':685:3846:6')

  if (rtb_sincos_o1_idx_2 > rtb_sincos_o1_idx_1) {
    rtb_sincos_o1_idx_2 = rtb_sincos_o1_idx_1;
  } else {
    // Gain: 'Gain' (':682')
    FLIGHT_Hexacopter_V2_B.ParamStep = FLIGHT_Hexacopter_V2_P.Gain_Gain_o *
      rtb_sincos_o1_idx_1;

    // Switch: 'Switch' (':685:3846:7') incorporates:
    //   RelationalOperator: 'UpperRelop' (':685:3846:9')

    if (rtb_sincos_o1_idx_2 < FLIGHT_Hexacopter_V2_B.ParamStep) {
      rtb_sincos_o1_idx_2 = FLIGHT_Hexacopter_V2_B.ParamStep;
    }

    // End of Switch: 'Switch' (':685:3846:7')
  }

  // End of Switch: 'Switch2' (':685:3846:8')

  // MATLABSystem: 'Read Parameter10' (':195')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_bq.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // Gain: 'Gain1' (':191:180') incorporates:
  //   MATLABSystem: 'Read Parameter10' (':195')
  //
  rtb_sincos_o1_idx_1 = FLIGHT_Hexacopter_V2_P.Gain1_Gain_j *
    FLIGHT_Hexacopter_V2_B.ParamStep;

  // MATLABSystem: 'Read Parameter7' (':216')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_fj.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // Product: 'PProd Out' (':684:909') incorporates:
  //   DataTypeConversion: 'Data Type Conversion13' (':630')
  //   MATLABSystem: 'Read Parameter7' (':216')
  //   Sum: 'Sum2' (':686')
  //
  FLIGHT_Hexacopter_V2_B.ParamStep *= static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_1) - FLIGHT_Hexacopter_V2_B.ypr[1];

  // Switch: 'Switch2' (':684:3846:8') incorporates:
  //   RelationalOperator: 'LowerRelop1' (':684:3846:6')

  if (FLIGHT_Hexacopter_V2_B.ParamStep > rtb_sincos_o1_idx_1) {
    FLIGHT_Hexacopter_V2_B.ParamStep = rtb_sincos_o1_idx_1;
  } else {
    // Gain: 'Gain1' (':683')
    rtb_sincos_o1_idx_1 *= FLIGHT_Hexacopter_V2_P.Gain1_Gain;

    // Switch: 'Switch' (':684:3846:7') incorporates:
    //   RelationalOperator: 'UpperRelop' (':684:3846:9')

    if (FLIGHT_Hexacopter_V2_B.ParamStep < rtb_sincos_o1_idx_1) {
      FLIGHT_Hexacopter_V2_B.ParamStep = rtb_sincos_o1_idx_1;
    }

    // End of Switch: 'Switch' (':684:3846:7')
  }

  // End of Switch: 'Switch2' (':684:3846:8')

  // BusAssignment: 'Bus Assignment' (':1251:101') incorporates:
  //   Constant: 'Constant3' (':1247')
  //   DataTypeConversion: 'Data Type Conversion15' (':632')
  //   MATLABSystem: 'PX4 Timestamp' (':1251:105')

  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.timestamp =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp_p.PX4Timestamp;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.roll = rtb_sincos_o1_idx_2;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.pitch =
    FLIGHT_Hexacopter_V2_B.ParamStep;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.yaw = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.out_yawrate);
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.thrust_body[0] =
    FLIGHT_Hexacopter_V2_P.Constant3_Value_m;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.thrust_body[1] =
    FLIGHT_Hexacopter_V2_P.Constant3_Value_m;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.thrust_body[2] =
    FLIGHT_Hexacopter_V2_B.des_throttle;
  FLIGHT_Hexacopter_V2_B.BusAssignment_e0.reset_integral = false;
  for (FLIGHT_Hexacopter_V2_B.ParamStep_g = 0;
       FLIGHT_Hexacopter_V2_B.ParamStep_g < 7;
       FLIGHT_Hexacopter_V2_B.ParamStep_g++) {
    FLIGHT_Hexacopter_V2_B.BusAssignment_e0._padding0[FLIGHT_Hexacopter_V2_B.ParamStep_g]
      = 0U;
  }

  // End of BusAssignment: 'Bus Assignment' (':1251:101')

  // MATLABSystem: 'SinkBlock' (':1251:104:15') incorporates:
  //   BusAssignment: 'Bus Assignment' (':1251:101')

  uORB_write_step(FLIGHT_Hexacopter_V2_DW.obj_mp.orbMetadataObj,
                  &FLIGHT_Hexacopter_V2_DW.obj_mp.orbAdvertiseObj,
                  &FLIGHT_Hexacopter_V2_B.BusAssignment_e0);

  // RateTransition: 'Rate Transition19' (':2013')
  FLIGHT_Hexacopter_V2_DW.RateTransition19_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ParamStep;

  // RateTransition: 'Rate Transition2' (':1974')
  FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0 = rtb_sincos_o1_idx_2;
  FLIGHT_Hexac_PX4Timestamp_j(&FLIGHT_Hexacopter_V2_B.PX4Timestamp_k);

  // BusAssignment: 'Bus Assignment' (':1256:101') incorporates:
  //   DataTypeConversion: 'Data Type Conversion15' (':632')
  //   MATLAB Function: 'MATLAB Function3' (':2041')
  //   MATLABSystem: 'PX4 Timestamp' (':1256:105')

  FLIGHT_Hexacopter_V2_B.BusAssignment_g.timestamp =
    FLIGHT_Hexacopter_V2_B.PX4Timestamp_k.PX4Timestamp;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.x = rtb_Switch_gd_idx_0;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.y = rtb_Switch_gd_idx_1;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.z = 0.0F;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.vx = FLIGHT_Hexacopter_V2_B.ParamStep_c;
  FLIGHT_Hexacopter_V2_B.BusAssignment_g.vy = rtb_Sum2_i;
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

  // MATLABSystem: 'SinkBlock' (':1256:104:15') incorporates:
  //   BusAssignment: 'Bus Assignment' (':1256:101')

  uORB_write_step(FLIGHT_Hexacopter_V2_DW.obj_pm.orbMetadataObj,
                  &FLIGHT_Hexacopter_V2_DW.obj_pm.orbAdvertiseObj,
                  &FLIGHT_Hexacopter_V2_B.BusAssignment_g);

  // RateTransition: 'Rate Transition1' (':1911') incorporates:
  //   DataTypeConversion: 'Data Type Conversion14' (':631')

  FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0 = static_cast<real32_T>
    (FLIGHT_Hexacopter_V2_B.rtb_Current_WP_idx_0);

  // Sum: 'Sum1' (':1821:2:220:339') incorporates:
  //   Bias: 'Bias1' (':1821:2:220:375')
  //   Gain: 'Gain1' (':1821:2:220:340')
  //   Product: 'Product5' (':1821:2:220:299')
  //   Product: 'Product4' (':1821:2:220:366')
  //   Sum: 'Sum2' (':1821:2:220:341')
  //   UnaryMinus: 'Unary Minus' (':1821:2:220:374')
  //   UnitDelay: 'Unit Delay1' (':1821:2:220:338')
  //   UnitDelay: 'Unit Delay2' (':1821:2:220:342')

  FLIGHT_Hexacopter_V2_B.q_c = ((-FLIGHT_Hexacopter_V2_B.q_c +
    FLIGHT_Hexacopter_V2_P.Bias1_Bias_m) / FLIGHT_Hexacopter_V2_B.d_n *
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i + FLIGHT_Hexacopter_V2_B.In1.vz)
    * FLIGHT_Hexacopter_V2_P.Gain1_Gain_a +
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_f;

  // Product: 'Product2' (':1821:2:220:344') incorporates:
  //   Product: 'Product5' (':1821:2:220:370')
  //   Sum: 'Add3' (':1821:2:220:371')
  //   UnitDelay: 'Unit Delay1' (':1821:2:220:338')

  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i *= 1.0F /
    FLIGHT_Hexacopter_V2_B.d_n * (FLIGHT_Hexacopter_V2_B.r_o -
    FLIGHT_Hexacopter_V2_B.p_j);

  // Sum: 'Sum3' (':1821:2:220:345') incorporates:
  //   UnitDelay: 'Unit Delay1' (':1821:2:220:338')
  //   UnitDelay: 'Unit Delay2' (':1821:2:220:342')

  FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_f = FLIGHT_Hexacopter_V2_B.In1.vz -
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i;

  // RateTransition: 'Rate Transition12' (':2003')
  FLIGHT_Hexacopter_V2_DW.RateTransition12_Buffer0_j =
    FLIGHT_Hexacopter_V2_B.w_radps;

  // RateTransition: 'Rate Transition3' (':1980')
  FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0 =
    FLIGHT_Hexacopter_V2_B.w_radps;

  // RateTransition: 'Rate Transition7' (':1987')
  FLIGHT_Hexacopter_V2_DW.RateTransition7_Buffer0_e =
    FLIGHT_Hexacopter_V2_B.w_radps;

  // MATLABSystem: 'Read Parameter4' (':213')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_c1.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep = 0.0F;
  }

  // RateTransition generated from: 'Rate Transition' (':1176')
  FLIGHT_Hexacopter_V2_DW.RateTransition_4_Buffer0 =
    FLIGHT_Hexacopter_V2_B.In1_p.values[7];

  // RateTransition generated from: 'Rate Transition' (':1176')
  FLIGHT_Hexacopter_V2_DW.RateTransition_8_Buffer0 =
    FLIGHT_Hexacopter_V2_B.In1_p.values[9];
  FLIGHT_Hexacopt_SourceBlock(&FLIGHT_Hexacopter_V2_B.SourceBlock_p,
    &FLIGHT_Hexacopter_V2_DW.SourceBlock_p);

  // Outputs for Enabled SubSystem: 'Enabled Subsystem' (':1186:3') incorporates:
  //   EnablePort: 'Enable' (':1186:5')

  if (FLIGHT_Hexacopter_V2_B.SourceBlock_p.SourceBlock_o1) {
    // SignalConversion generated from: 'In1' (':1186:4') incorporates:
    //   MATLABSystem: 'SourceBlock' (':1186:9')

    FLIGHT_Hexacopter_V2_B.In1_d =
      FLIGHT_Hexacopter_V2_B.SourceBlock_p.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: 'Enabled Subsystem' (':1186:3')

  // RelationalOperator: 'Compare' (':1899:2') incorporates:
  //   Constant: 'Constant' (':1899:3')

  rtb_flag_pos = (FLIGHT_Hexacopter_V2_B.In1_p.values[9] >=
                  FLIGHT_Hexacopter_V2_P.CompareToConstant1_const_j);

  // RateTransition: 'Rate Transition15' (':1924') incorporates:
  //   Constant: 'Constant' (':1720:3')
  //   Logic: 'XOR' (':1721')
  //   RelationalOperator: 'Compare' (':1720:2')

  FLIGHT_Hexacopter_V2_DW.RateTransition15_Buffer0_a = static_cast<boolean_T>
    ((FLIGHT_Hexacopter_V2_B.In1_p.values[9] >=
      FLIGHT_Hexacopter_V2_P.CompareToConstant_const_o) ^
     FLIGHT_Hexacopter_V2_B.In1_d.armed) ^ rtb_flag_pos;

  // RateTransition: 'Rate Transition16' (':1925')
  FLIGHT_Hexacopter_V2_DW.RateTransition16_Buffer0 = rtb_flag_pos;

  // RateTransition generated from: 'Rate Transition2' (':1298')
  FLIGHT_Hexacopter_V2_DW.RateTransition2_16_Buffer0 =
    FLIGHT_Hexacopter_V2_B.In1_d.armed;

  // RateTransition generated from: 'Rate Transition2' (':1298')
  FLIGHT_Hexacopter_V2_DW.RateTransition2_17_Buffer0 =
    FLIGHT_Hexacopter_V2_B.In1_d.manual_lockdown;

  // Logic: 'OR' (':1709') incorporates:
  //   Constant: 'Constant' (':1710:3')
  //   RelationalOperator: 'Compare' (':1710:2')

  rtb_flag_pos = (FLIGHT_Hexacopter_V2_B.In1_p.values[9] <=
                  FLIGHT_Hexacopter_V2_P.CompareToConstant_const_j) ^
    FLIGHT_Hexacopter_V2_B.In1_d.armed;

  // RateTransition: 'Rate Transition15' (':2009')
  FLIGHT_Hexacopter_V2_DW.RateTransition15_Buffer0 = rtb_flag_pos;

  // RateTransition: 'Rate Transition16' (':2010')
  FLIGHT_Hexacopter_V2_DW.RateTransition16_Buffer0_g = rtb_flag_pos;

  // RateTransition: 'Rate Transition17' (':2011')
  FLIGHT_Hexacopter_V2_DW.RateTransition17_Buffer0_e = rtb_flag_pos;

  // MATLABSystem: 'Read Parameter12' (':197')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_jo.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter12_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter12_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter12' (':197')

  // RateTransition: 'Rate Transition18' (':2012')
  FLIGHT_Hexacopter_V2_DW.RateTransition18_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter12_o1;

  // MATLABSystem: 'Read Parameter13' (':198')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_pf.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter13_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter13_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter13' (':198')

  // RateTransition: 'Rate Transition8' (':1988')
  FLIGHT_Hexacopter_V2_DW.RateTransition8_Buffer0_a =
    FLIGHT_Hexacopter_V2_B.ReadParameter13_o1;

  // MATLABSystem: 'Read Parameter14' (':199')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_fd.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter14_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter14_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter14' (':199')

  // RateTransition: 'Rate Transition9' (':1989')
  FLIGHT_Hexacopter_V2_DW.RateTransition9_Buffer0_h =
    FLIGHT_Hexacopter_V2_B.ReadParameter14_o1;

  // MATLABSystem: 'Read Parameter15' (':200')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_nn.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter15_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter15_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter15' (':200')

  // RateTransition: 'Rate Transition10' (':1995')
  FLIGHT_Hexacopter_V2_DW.RateTransition10_Buffer0_g =
    FLIGHT_Hexacopter_V2_B.ReadParameter15_o1;

  // MATLABSystem: 'Read Parameter16' (':201')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_j.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter16_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter16_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter16' (':201')

  // RateTransition: 'Rate Transition13' (':2004')
  FLIGHT_Hexacopter_V2_DW.RateTransition13_Buffer0_d =
    FLIGHT_Hexacopter_V2_B.ReadParameter16_o1;

  // MATLABSystem: 'Read Parameter17' (':202')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_d.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter17_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter17_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter17' (':202')

  // RateTransition: 'Rate Transition14' (':2005')
  FLIGHT_Hexacopter_V2_DW.RateTransition14_Buffer0_o =
    FLIGHT_Hexacopter_V2_B.ReadParameter17_o1;

  // MATLABSystem: 'Read Parameter18' (':203')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_ml.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter18_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter18_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter18' (':203')

  // RateTransition: 'Rate Transition11' (':2002')
  FLIGHT_Hexacopter_V2_DW.RateTransition11_Buffer0_b =
    FLIGHT_Hexacopter_V2_B.ReadParameter18_o1;

  // MATLABSystem: 'Read Parameter19' (':204')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_mc.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter19_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter19_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter19' (':204')

  // RateTransition: 'Rate Transition' (':732')
  FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter19_o1;

  // MATLABSystem: 'Read Parameter29' (':1032')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_br.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter29_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter29_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter29' (':1032')

  // RateTransition: 'Rate Transition4' (':1912')
  FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_d =
    FLIGHT_Hexacopter_V2_B.ReadParameter29_o1;

  // MATLABSystem: 'Read Parameter30' (':1033')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_mo.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter30_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter30_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter30' (':1033')

  // RateTransition: 'Rate Transition5' (':1913')
  FLIGHT_Hexacopter_V2_DW.RateTransition5_Buffer0_h =
    FLIGHT_Hexacopter_V2_B.ReadParameter30_o1;

  // MATLABSystem: 'Read Parameter31' (':1034')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_as.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter31_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter31_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter31' (':1034')

  // RateTransition: 'Rate Transition6' (':1914')
  FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter31_o1;

  // MATLABSystem: 'Read Parameter32' (':1035')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_lv.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter32_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter32_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter32' (':1035')

  // RateTransition: 'Rate Transition7' (':1915')
  FLIGHT_Hexacopter_V2_DW.RateTransition7_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter32_o1;

  // MATLABSystem: 'Read Parameter33' (':1036')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_bd.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter33_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter33_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter33' (':1036')

  // RateTransition: 'Rate Transition8' (':1916')
  FLIGHT_Hexacopter_V2_DW.RateTransition8_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter33_o1;

  // MATLABSystem: 'Read Parameter34' (':1725')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_oq.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter34_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter34_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter34' (':1725')

  // RateTransition: 'Rate Transition9' (':1917')
  FLIGHT_Hexacopter_V2_DW.RateTransition9_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter34_o1;

  // MATLABSystem: 'Read Parameter35' (':1726')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_b.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter35_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter35_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter35' (':1726')

  // RateTransition: 'Rate Transition10' (':1918')
  FLIGHT_Hexacopter_V2_DW.RateTransition10_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter35_o1;

  // MATLABSystem: 'Read Parameter36' (':1727')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_ln.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter36_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter36_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter36' (':1727')

  // RateTransition: 'Rate Transition11' (':1919')
  FLIGHT_Hexacopter_V2_DW.RateTransition11_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter36_o1;

  // MATLABSystem: 'Read Parameter37' (':1752')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_pi.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter37_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter37_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter37' (':1752')

  // RateTransition: 'Rate Transition12' (':1920')
  FLIGHT_Hexacopter_V2_DW.RateTransition12_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter37_o1;

  // MATLABSystem: 'Read Parameter38' (':1760')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_e.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ParamStep_k);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ParamStep_k = 0.0F;
  }

  // Gain: 'Gain' (':1763') incorporates:
  //   MATLABSystem: 'Read Parameter38' (':1760')
  //
  FLIGHT_Hexacopter_V2_B.ReadParameter37_o1 =
    FLIGHT_Hexacopter_V2_P.Gain_Gain_eb * FLIGHT_Hexacopter_V2_B.ParamStep_k;

  // RateTransition: 'Rate Transition17' (':1927')
  FLIGHT_Hexacopter_V2_DW.RateTransition17_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter37_o1;

  // MATLABSystem: 'Read Parameter41' (':1904')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_h.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter41_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter41_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter41' (':1904')

  // RateTransition: 'Rate Transition13' (':1921')
  FLIGHT_Hexacopter_V2_DW.RateTransition13_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter41_o1;

  // MATLABSystem: 'Read Parameter42' (':1905')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_fy.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter42_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter42_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter42' (':1905')

  // RateTransition: 'Rate Transition14' (':1922')
  FLIGHT_Hexacopter_V2_DW.RateTransition14_Buffer0 =
    FLIGHT_Hexacopter_V2_B.ReadParameter42_o1;

  // MATLABSystem: 'Read Parameter43' (':1930')
  MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_ox.MW_PARAMHANDLE, MW_SINGLE,
                    &FLIGHT_Hexacopter_V2_B.ParamStep_k);

  // MATLABSystem: 'Read Parameter44' (':1932')
  MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_o.MW_PARAMHANDLE, MW_SINGLE,
                    &FLIGHT_Hexacopter_V2_B.ParamStep_k);

  // MATLABSystem: 'Read Parameter8' (':217')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_f.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_Hexacopter_V2_B.ReadParameter8_o1);
  if (rtb_flag_pos) {
    FLIGHT_Hexacopter_V2_B.ReadParameter8_o1 = 0.0F;
  }

  // End of MATLABSystem: 'Read Parameter8' (':217')

  // RateTransition: 'Rate Transition6' (':1982')
  FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_e =
    FLIGHT_Hexacopter_V2_B.ReadParameter8_o1;

  // MATLABSystem: 'read_mc_rollrate_p' (':246')
  rtb_flag_pos = MW_ParamRead_Step(FLIGHT_Hexacopter_V2_DW.obj_c.MW_PARAMHANDLE,
    MW_SINGLE, &rtb_read_mc_rollrate_p_o1);
  if (rtb_flag_pos) {
    rtb_read_mc_rollrate_p_o1 = 0.0F;
  }

  // End of MATLABSystem: 'read_mc_rollrate_p' (':246')

  // RateTransition: 'Rate Transition5' (':1981')
  FLIGHT_Hexacopter_V2_DW.RateTransition5_Buffer0 = rtb_read_mc_rollrate_p_o1;

  // Update for DiscreteIntegrator: 'Integrator' (':1821:10:843') incorporates:
  //   MATLABSystem: 'Read Parameter4' (':213')
  //   Product: 'IProd Out' (':1821:10:787')
  //
  FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_lu += FLIGHT_Hexacopter_V2_B.roll *
    FLIGHT_Hexacopter_V2_B.ParamStep *
    FLIGHT_Hexacopter_V2_P.Integrator_gainval_ei;
  FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_l = static_cast<int8_T>
    (rtb_AND);

  // Update for UnitDelay: 'Unit Delay1' (':1821:2:220:338')
  FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i = FLIGHT_Hexacopter_V2_B.q_c;

  // Update for UnitDelay: 'UD' (':1821:1:5')
  //
  //  Block description for 'UD' (':1821:1:5'):
  //
  //   Store in Global RAM

  FLIGHT_Hexacopter_V2_DW.UD_DSTATE_a = FLIGHT_Hexacopter_V2_B.TSamp_ku;

  // Update for DiscreteIntegrator: 'Discrete-Time Integrator' (':436') incorporates:
  //   MATLAB Function: 'MATLAB Function3' (':2041')

  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE_c +=
    FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_gainva_h *
    FLIGHT_Hexacopter_V2_B.ParamStep_c;
  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRe_l = static_cast<int8_T>
    (rtb_AND1);

  // Update for DiscreteIntegrator: 'Discrete-Time Integrator1' (':437') incorporates:
  //   MATLAB Function: 'MATLAB Function3' (':2041')

  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_DSTATE +=
    FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator1_gainval * rtb_Sum2_i;
  FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_PrevRes = static_cast<int8_T>
    (rtb_AND2);

  // Update for DiscreteIntegrator: 'Integrator' (':514:843')
  FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_l3 = static_cast<int8_T>
    (rtb_XOR);

  // Update for DiscreteIntegrator: 'Filter' (':514:737') incorporates:
  //   DiscreteIntegrator: 'Integrator' (':514:843')
  //   Product: 'NProd Out' (':514:878')

  FLIGHT_Hexacopter_V2_DW.Filter_DSTATE_i[0] +=
    FLIGHT_Hexacopter_V2_P.Filter_gainval_f * rtb_NProdOut_idx_0;
  FLIGHT_Hexacopter_V2_DW.Filter_DSTATE_i[1] +=
    FLIGHT_Hexacopter_V2_P.Filter_gainval_f * FLIGHT_Hexacopter_V2_B.Sum2_g;
  FLIGHT_Hexacopter_V2_DW.Filter_PrevResetState = static_cast<int8_T>(rtb_XOR);
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
    static const char_T ParameterNameStr_d[17] = "MPC_XY_VEL_I_ACC";
    static const char_T ParameterNameStr_e[17] = "MPC_XY_VEL_D_ACC";
    static const char_T ParameterNameStr_f[17] = "DOUBLET_PEAK_ANG";
    static const char_T ParameterNameStr_g[11] = "DOUBLET_DT";
    static const char_T ParameterNameStr_h[13] = "DOUBLET_AXIS";
    static const char_T ParameterNameStr_i[16] = "MC_ROLLRATE_MAX";
    static const char_T ParameterNameStr_j[10] = "MC_ROLL_P";
    static const char_T ParameterNameStr_k[17] = "MC_PITCHRATE_MAX";
    static const char_T ParameterNameStr_l[11] = "MC_PITCH_P";
    static const char_T ParameterNameStr_m[16] = "MPC_Z_VEL_I_ACC";
    static const char_T ParameterNameStr_n[14] = "MC_ROLLRATE_D";
    static const char_T ParameterNameStr_o[15] = "MC_PITCHRATE_P";
    static const char_T ParameterNameStr_p[15] = "MC_PITCHRATE_I";
    static const char_T ParameterNameStr_q[15] = "MC_PITCHRATE_D";
    static const char_T ParameterNameStr_r[13] = "MC_YAWRATE_P";
    static const char_T ParameterNameStr_s[13] = "MC_YAWRATE_I";
    static const char_T ParameterNameStr_t[13] = "MC_YAWRATE_D";
    static const char_T ParameterNameStr_u[14] = "MC_YAWRATE_FF";
    static const char_T ParameterNameStr_v[11] = "SMC_K_SS_P";
    static const char_T ParameterNameStr_w[11] = "SMC_K_SS_I";
    static const char_T ParameterNameStr_x[11] = "SMC_K_SS_D";
    static const char_T ParameterNameStr_y[14] = "SMC_K_REACH_S";
    static const char_T ParameterNameStr_z[14] = "SMC_K_REACH_P";
    static const char_T ParameterNameStr_10[9] = "SMC_I_XX";
    static const char_T ParameterNameStr_11[9] = "SMC_I_YY";
    static const char_T ParameterNameStr_12[9] = "SMC_I_ZZ";
    static const char_T ParameterNameStr_13[12] = "SMC_EPSILON";
    static const char_T ParameterNameStr_14[15] = "SMC_LPF_CUTOFF";
    static const char_T ParameterNameStr_15[14] = "ST_SMC_LAMBDA";
    static const char_T ParameterNameStr_16[11] = "ST_SMC_ETA";
    static const char_T ParameterNameStr_17[11] = "MC_PITCH_I";
    static const char_T ParameterNameStr_18[10] = "MC_ROLL_I";
    static const char_T ParameterNameStr_19[14] = "MC_ROLLRATE_I";
    static const char_T ParameterNameStr_1a[14] = "MC_ROLLRATE_P";

    // Start for RateTransition: 'Rate Transition4' (':1068')
    FLIGHT_Hexacopter_V2_B.RateTransition4 =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialConditio;

    // Start for RateTransition: 'Rate Transition5' (':1981')
    FLIGHT_Hexacopter_V2_B.RateTransition5 =
      FLIGHT_Hexacopter_V2_P.RateTransition5_InitialConditio;

    // Start for RateTransition: 'Rate Transition2' (':1974')
    FLIGHT_Hexacopter_V2_B.RateTransition2 =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialConditio;

    // Start for RateTransition: 'Rate Transition15' (':2009')
    FLIGHT_Hexacopter_V2_B.RateTransition15 =
      FLIGHT_Hexacopter_V2_P.RateTransition15_InitialConditi;

    // Start for RateTransition: 'Rate Transition18' (':2012')
    FLIGHT_Hexacopter_V2_B.RateTransition18 =
      FLIGHT_Hexacopter_V2_P.RateTransition18_InitialConditi;

    // Start for RateTransition: 'Rate Transition3' (':1980')
    FLIGHT_Hexacopter_V2_B.RateTransition3 =
      FLIGHT_Hexacopter_V2_P.RateTransition3_InitialConditio;

    // Start for RateTransition generated from: 'Rate Transition' (':1176')
    FLIGHT_Hexacopter_V2_B.rc_ctrl_switch =
      FLIGHT_Hexacopter_V2_P.RateTransition_8_InitialConditi;

    // Start for RateTransition: 'Rate Transition2' (':884')
    FLIGHT_Hexacopter_V2_B.RateTransition2_a[0] =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_h;
    FLIGHT_Hexacopter_V2_B.RateTransition2_a[1] =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_h;
    FLIGHT_Hexacopter_V2_B.RateTransition2_a[2] =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_h;

    // Start for RateTransition: 'Rate Transition4' (':1912')
    FLIGHT_Hexacopter_V2_B.RateTransition4_l =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialCondit_m;

    // Start for RateTransition: 'Rate Transition5' (':1913')
    FLIGHT_Hexacopter_V2_B.RateTransition5_n =
      FLIGHT_Hexacopter_V2_P.RateTransition5_InitialCondit_g;

    // Start for RateTransition: 'Rate Transition6' (':1914')
    FLIGHT_Hexacopter_V2_B.RateTransition6 =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialConditio;

    // Start for RateTransition: 'Rate Transition9' (':1917')
    FLIGHT_Hexacopter_V2_B.RateTransition9 =
      FLIGHT_Hexacopter_V2_P.RateTransition9_InitialConditio;

    // Start for RateTransition: 'Rate Transition10' (':1918')
    FLIGHT_Hexacopter_V2_B.RateTransition10 =
      FLIGHT_Hexacopter_V2_P.RateTransition10_InitialConditi;

    // Start for RateTransition: 'Rate Transition11' (':1919')
    FLIGHT_Hexacopter_V2_B.RateTransition11 =
      FLIGHT_Hexacopter_V2_P.RateTransition11_InitialConditi;

    // Start for RateTransition: 'Rate Transition17' (':1927')
    FLIGHT_Hexacopter_V2_B.RateTransition17 =
      FLIGHT_Hexacopter_V2_P.RateTransition17_InitialConditi;

    // Start for RateTransition: 'Rate Transition1' (':1911')
    FLIGHT_Hexacopter_V2_B.RateTransition1 =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialConditio;

    // Start for RateTransition: 'Rate Transition16' (':1925')
    FLIGHT_Hexacopter_V2_B.RateTransition16 =
      FLIGHT_Hexacopter_V2_P.RateTransition16_InitialConditi;

    // Start for RateTransition: 'Rate Transition7' (':1915')
    FLIGHT_Hexacopter_V2_B.RateTransition7 =
      FLIGHT_Hexacopter_V2_P.RateTransition7_InitialConditio;

    // Start for RateTransition: 'Rate Transition8' (':1916')
    FLIGHT_Hexacopter_V2_B.RateTransition8 =
      FLIGHT_Hexacopter_V2_P.RateTransition8_InitialConditio;

    // Start for RateTransition: 'Rate Transition12' (':1920')
    FLIGHT_Hexacopter_V2_B.RateTransition12 =
      FLIGHT_Hexacopter_V2_P.RateTransition12_InitialConditi;

    // Start for RateTransition: 'Rate Transition13' (':1921')
    FLIGHT_Hexacopter_V2_B.RateTransition13 =
      FLIGHT_Hexacopter_V2_P.RateTransition13_InitialConditi;

    // Start for RateTransition: 'Rate Transition14' (':1922')
    FLIGHT_Hexacopter_V2_B.RateTransition14 =
      FLIGHT_Hexacopter_V2_P.RateTransition14_InitialConditi;

    // Start for RateTransition: 'Rate Transition15' (':1924')
    FLIGHT_Hexacopter_V2_B.RateTransition15_l =
      FLIGHT_Hexacopter_V2_P.RateTransition15_InitialCondi_p;

    // Start for RateTransition: 'Rate Transition8' (':1988')
    FLIGHT_Hexacopter_V2_B.RateTransition8_i =
      FLIGHT_Hexacopter_V2_P.RateTransition8_InitialCondit_c;

    // Start for RateTransition: 'Rate Transition19' (':2013')
    FLIGHT_Hexacopter_V2_B.RateTransition19 =
      FLIGHT_Hexacopter_V2_P.RateTransition19_InitialConditi;

    // Start for RateTransition: 'Rate Transition16' (':2010')
    FLIGHT_Hexacopter_V2_B.RateTransition16_e =
      FLIGHT_Hexacopter_V2_P.RateTransition16_InitialCondi_i;

    // Start for RateTransition: 'Rate Transition10' (':1995')
    FLIGHT_Hexacopter_V2_B.RateTransition10_j =
      FLIGHT_Hexacopter_V2_P.RateTransition10_InitialCondi_k;

    // Start for RateTransition: 'Rate Transition7' (':1987')
    FLIGHT_Hexacopter_V2_B.RateTransition7_h =
      FLIGHT_Hexacopter_V2_P.RateTransition7_InitialCondit_l;

    // Start for RateTransition: 'Rate Transition' (':732')
    FLIGHT_Hexacopter_V2_B.RateTransition =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialCondition;

    // Start for RateTransition: 'Rate Transition1' (':733')
    FLIGHT_Hexacopter_V2_B.RateTransition1_a =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialCondit_e;

    // Start for RateTransition: 'Rate Transition13' (':2004')
    FLIGHT_Hexacopter_V2_B.RateTransition13_a =
      FLIGHT_Hexacopter_V2_P.RateTransition13_InitialCondi_h;

    // Start for RateTransition: 'Rate Transition20' (':2014')
    FLIGHT_Hexacopter_V2_B.RateTransition20 =
      FLIGHT_Hexacopter_V2_P.RateTransition20_InitialConditi;

    // Start for RateTransition: 'Rate Transition17' (':2011')
    FLIGHT_Hexacopter_V2_B.RateTransition17_h =
      FLIGHT_Hexacopter_V2_P.RateTransition17_InitialCondi_p;

    // Start for RateTransition: 'Rate Transition11' (':2002')
    FLIGHT_Hexacopter_V2_B.RateTransition11_a =
      FLIGHT_Hexacopter_V2_P.RateTransition11_InitialCondi_g;

    // Start for RateTransition: 'Rate Transition12' (':2003')
    FLIGHT_Hexacopter_V2_B.RateTransition12_j =
      FLIGHT_Hexacopter_V2_P.RateTransition12_InitialCondi_h;

    // Start for RateTransition generated from: 'Rate Transition' (':1176')
    FLIGHT_Hexacopter_V2_B.rc_inject_failure =
      FLIGHT_Hexacopter_V2_P.RateTransition_4_InitialConditi;

    // Start for RateTransition generated from: 'Rate Transition2' (':1298')
    FLIGHT_Hexacopter_V2_B.VehicleStatus_flag_armed =
      FLIGHT_Hexacopter_V2_P.RateTransition2_16_InitialCondi;

    // Start for RateTransition generated from: 'Rate Transition2' (':1298')
    FLIGHT_Hexacopter_V2_B.VehicleStatus_flag_kill =
      FLIGHT_Hexacopter_V2_P.RateTransition2_17_InitialCondi;

    // Start for RateTransition: 'Rate Transition14' (':2005')
    FLIGHT_Hexacopter_V2_B.RateTransition14_c =
      FLIGHT_Hexacopter_V2_P.RateTransition14_InitialCondi_f;

    // Start for RateTransition: 'Rate Transition9' (':1989')
    FLIGHT_Hexacopter_V2_B.RateTransition9_p =
      FLIGHT_Hexacopter_V2_P.RateTransition9_InitialCondit_i;

    // Start for RateTransition: 'Rate Transition6' (':1982')
    FLIGHT_Hexacopter_V2_B.RateTransition6_o =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialCondit_f;

    // InitializeConditions for RateTransition: 'Rate Transition4' (':1068')
    FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialConditio;

    // InitializeConditions for RateTransition: 'Rate Transition5' (':1981')
    FLIGHT_Hexacopter_V2_DW.RateTransition5_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition5_InitialConditio;

    // InitializeConditions for RateTransition: 'Rate Transition2' (':1974')
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialConditio;

    // InitializeConditions for RateTransition: 'Rate Transition15' (':2009')
    FLIGHT_Hexacopter_V2_DW.RateTransition15_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition15_InitialConditi;

    // InitializeConditions for DiscreteIntegrator: 'Integrator' (':1978:843')
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCondit;
    FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState = 2;

    // InitializeConditions for RateTransition: 'Rate Transition18' (':2012')
    FLIGHT_Hexacopter_V2_DW.RateTransition18_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition18_InitialConditi;

    // InitializeConditions for UnitDelay: 'Unit Delay1' (':1967:220:338')
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE =
      FLIGHT_Hexacopter_V2_P.UnitDelay1_InitialCondition;

    // InitializeConditions for RateTransition: 'Rate Transition3' (':1980')
    FLIGHT_Hexacopter_V2_DW.RateTransition3_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition3_InitialConditio;

    // InitializeConditions for UnitDelay: 'UD' (':1966:5')
    //
    //  Block description for 'UD' (':1966:5'):
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevScale;

    // InitializeConditions for RateTransition generated from: 'Rate Transition' (':1176') 
    FLIGHT_Hexacopter_V2_DW.RateTransition_8_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition_8_InitialConditi;

    // InitializeConditions for RateTransition: 'Rate Transition2' (':884')
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[0] =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_h;

    // InitializeConditions for UnitDelay: 'UD' (':1524:5') incorporates:
    //   Sum: 'Diff' (':1524:3')
    //
    //  Block description for 'UD' (':1524:5'):
    //
    //   Store in Global RAM
    //
    //  Block description for 'Diff' (':1524:3'):
    //
    //   Add in CPU

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[0] =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevSca_e;

    // InitializeConditions for RateTransition: 'Rate Transition2' (':884')
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[1] =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_h;

    // InitializeConditions for UnitDelay: 'UD' (':1524:5') incorporates:
    //   Sum: 'Diff' (':1524:3')
    //
    //  Block description for 'UD' (':1524:5'):
    //
    //   Store in Global RAM
    //
    //  Block description for 'Diff' (':1524:3'):
    //
    //   Add in CPU

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[1] =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevSca_e;

    // InitializeConditions for RateTransition: 'Rate Transition2' (':884')
    FLIGHT_Hexacopter_V2_DW.RateTransition2_Buffer0_d[2] =
      FLIGHT_Hexacopter_V2_P.RateTransition2_InitialCondit_h;

    // InitializeConditions for UnitDelay: 'UD' (':1524:5') incorporates:
    //   Sum: 'Diff' (':1524:3')
    //
    //  Block description for 'UD' (':1524:5'):
    //
    //   Store in Global RAM
    //
    //  Block description for 'Diff' (':1524:3'):
    //
    //   Add in CPU

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_h[2] =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevSca_e;

    // InitializeConditions for RateTransition: 'Rate Transition4' (':1912')
    FLIGHT_Hexacopter_V2_DW.RateTransition4_Buffer0_d =
      FLIGHT_Hexacopter_V2_P.RateTransition4_InitialCondit_m;

    // InitializeConditions for RateTransition: 'Rate Transition5' (':1913')
    FLIGHT_Hexacopter_V2_DW.RateTransition5_Buffer0_h =
      FLIGHT_Hexacopter_V2_P.RateTransition5_InitialCondit_g;

    // InitializeConditions for RateTransition: 'Rate Transition6' (':1914')
    FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialConditio;

    // InitializeConditions for RateTransition: 'Rate Transition9' (':1917')
    FLIGHT_Hexacopter_V2_DW.RateTransition9_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition9_InitialConditio;

    // InitializeConditions for RateTransition: 'Rate Transition10' (':1918')
    FLIGHT_Hexacopter_V2_DW.RateTransition10_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition10_InitialConditi;

    // InitializeConditions for RateTransition: 'Rate Transition11' (':1919')
    FLIGHT_Hexacopter_V2_DW.RateTransition11_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition11_InitialConditi;

    // InitializeConditions for RateTransition: 'Rate Transition17' (':1927')
    FLIGHT_Hexacopter_V2_DW.RateTransition17_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition17_InitialConditi;

    // InitializeConditions for RateTransition: 'Rate Transition1' (':1911')
    FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialConditio;

    // InitializeConditions for UnitDelay: 'Unit Delay' (':1756:219:331')
    FLIGHT_Hexacopter_V2_DW.UnitDelay_DSTATE =
      FLIGHT_Hexacopter_V2_P.UnitDelay_InitialCondition;

    // InitializeConditions for UnitDelay: 'UD' (':1522:5')
    //
    //  Block description for 'UD' (':1522:5'):
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_o =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for UnitDelay: 'UD' (':1523:5')
    //
    //  Block description for 'UD' (':1523:5'):
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_e =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative1_ICPrevScale;

    // InitializeConditions for RateTransition: 'Rate Transition16' (':1925')
    FLIGHT_Hexacopter_V2_DW.RateTransition16_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition16_InitialConditi;

    // InitializeConditions for RateTransition: 'Rate Transition7' (':1915')
    FLIGHT_Hexacopter_V2_DW.RateTransition7_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition7_InitialConditio;

    // InitializeConditions for RateTransition: 'Rate Transition8' (':1916')
    FLIGHT_Hexacopter_V2_DW.RateTransition8_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition8_InitialConditio;

    // InitializeConditions for RateTransition: 'Rate Transition12' (':1920')
    FLIGHT_Hexacopter_V2_DW.RateTransition12_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition12_InitialConditi;

    // InitializeConditions for RateTransition: 'Rate Transition13' (':1921')
    FLIGHT_Hexacopter_V2_DW.RateTransition13_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition13_InitialConditi;

    // InitializeConditions for RateTransition: 'Rate Transition14' (':1922')
    FLIGHT_Hexacopter_V2_DW.RateTransition14_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition14_InitialConditi;

    // InitializeConditions for DiscreteIntegrator: 'Filter' (':1817:737')
    FLIGHT_Hexacopter_V2_DW.Filter_DSTATE =
      FLIGHT_Hexacopter_V2_P.DiscretePIDController1_InitialC;

    // InitializeConditions for RateTransition: 'Rate Transition15' (':1924')
    FLIGHT_Hexacopter_V2_DW.RateTransition15_Buffer0_a =
      FLIGHT_Hexacopter_V2_P.RateTransition15_InitialCondi_p;

    // InitializeConditions for DiscreteIntegrator: 'Integrator' (':1820:843')
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_h =
      FLIGHT_Hexacopter_V2_P.DiscretePIDController2_InitialC;
    FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_h = 2;

    // InitializeConditions for DiscreteIntegrator: 'Discrete-Time Integrator' (':1887') 
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_DSTATE =
      FLIGHT_Hexacopter_V2_P.DiscreteTimeIntegrator_IC;
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRese = 2;

    // InitializeConditions for RateTransition: 'Rate Transition8' (':1988')
    FLIGHT_Hexacopter_V2_DW.RateTransition8_Buffer0_a =
      FLIGHT_Hexacopter_V2_P.RateTransition8_InitialCondit_c;

    // InitializeConditions for RateTransition: 'Rate Transition19' (':2013')
    FLIGHT_Hexacopter_V2_DW.RateTransition19_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition19_InitialConditi;

    // InitializeConditions for RateTransition: 'Rate Transition16' (':2010')
    FLIGHT_Hexacopter_V2_DW.RateTransition16_Buffer0_g =
      FLIGHT_Hexacopter_V2_P.RateTransition16_InitialCondi_i;

    // InitializeConditions for DiscreteIntegrator: 'Integrator' (':1991:843')
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_l =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate1_InitialCondi;
    FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_e = 2;

    // InitializeConditions for RateTransition: 'Rate Transition10' (':1995')
    FLIGHT_Hexacopter_V2_DW.RateTransition10_Buffer0_g =
      FLIGHT_Hexacopter_V2_P.RateTransition10_InitialCondi_k;

    // InitializeConditions for UnitDelay: 'Unit Delay1' (':1984:220:338')
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_a =
      FLIGHT_Hexacopter_V2_P.UnitDelay1_InitialCondition_i;

    // InitializeConditions for RateTransition: 'Rate Transition7' (':1987')
    FLIGHT_Hexacopter_V2_DW.RateTransition7_Buffer0_e =
      FLIGHT_Hexacopter_V2_P.RateTransition7_InitialCondit_l;

    // InitializeConditions for UnitDelay: 'UD' (':1983:5')
    //
    //  Block description for 'UD' (':1983:5'):
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_b =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative1_ICPrevSca_o;

    // InitializeConditions for RateTransition: 'Rate Transition' (':732')
    FLIGHT_Hexacopter_V2_DW.RateTransition_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition_InitialCondition;

    // InitializeConditions for RateTransition: 'Rate Transition1' (':733')
    FLIGHT_Hexacopter_V2_DW.RateTransition1_Buffer0_g =
      FLIGHT_Hexacopter_V2_P.RateTransition1_InitialCondit_e;

    // InitializeConditions for RateTransition: 'Rate Transition13' (':2004')
    FLIGHT_Hexacopter_V2_DW.RateTransition13_Buffer0_d =
      FLIGHT_Hexacopter_V2_P.RateTransition13_InitialCondi_h;

    // InitializeConditions for RateTransition: 'Rate Transition20' (':2014')
    FLIGHT_Hexacopter_V2_DW.RateTransition20_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition20_InitialConditi;

    // InitializeConditions for RateTransition: 'Rate Transition17' (':2011')
    FLIGHT_Hexacopter_V2_DW.RateTransition17_Buffer0_e =
      FLIGHT_Hexacopter_V2_P.RateTransition17_InitialCondi_p;

    // InitializeConditions for DiscreteIntegrator: 'Integrator' (':2008:843')
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_o =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate2_InitialCondi;
    FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_es = 2;

    // InitializeConditions for RateTransition: 'Rate Transition11' (':2002')
    FLIGHT_Hexacopter_V2_DW.RateTransition11_Buffer0_b =
      FLIGHT_Hexacopter_V2_P.RateTransition11_InitialCondi_g;

    // InitializeConditions for UnitDelay: 'Unit Delay1' (':1999:220:338')
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_p =
      FLIGHT_Hexacopter_V2_P.UnitDelay1_InitialCondition_m;

    // InitializeConditions for RateTransition: 'Rate Transition12' (':2003')
    FLIGHT_Hexacopter_V2_DW.RateTransition12_Buffer0_j =
      FLIGHT_Hexacopter_V2_P.RateTransition12_InitialCondi_h;

    // InitializeConditions for UnitDelay: 'UD' (':1998:5')
    //
    //  Block description for 'UD' (':1998:5'):
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_d =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative3_ICPrevScale;

    // InitializeConditions for RateTransition generated from: 'Rate Transition' (':1176') 
    FLIGHT_Hexacopter_V2_DW.RateTransition_4_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition_4_InitialConditi;

    // InitializeConditions for RateTransition generated from: 'Rate Transition2' (':1298') 
    FLIGHT_Hexacopter_V2_DW.RateTransition2_16_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition2_16_InitialCondi;

    // InitializeConditions for RateTransition generated from: 'Rate Transition2' (':1298') 
    FLIGHT_Hexacopter_V2_DW.RateTransition2_17_Buffer0 =
      FLIGHT_Hexacopter_V2_P.RateTransition2_17_InitialCondi;

    // InitializeConditions for UnitDelay: 'Unit Delay2' (':1999:220:342')
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE =
      FLIGHT_Hexacopter_V2_P.UnitDelay2_InitialCondition;

    // InitializeConditions for RateTransition: 'Rate Transition14' (':2005')
    FLIGHT_Hexacopter_V2_DW.RateTransition14_Buffer0_o =
      FLIGHT_Hexacopter_V2_P.RateTransition14_InitialCondi_f;

    // InitializeConditions for UnitDelay: 'Unit Delay2' (':1984:220:342')
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_c =
      FLIGHT_Hexacopter_V2_P.UnitDelay2_InitialCondition_i;

    // InitializeConditions for RateTransition: 'Rate Transition9' (':1989')
    FLIGHT_Hexacopter_V2_DW.RateTransition9_Buffer0_h =
      FLIGHT_Hexacopter_V2_P.RateTransition9_InitialCondit_i;

    // InitializeConditions for UnitDelay: 'Unit Delay2' (':1967:220:342')
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_i =
      FLIGHT_Hexacopter_V2_P.UnitDelay2_InitialCondition_n;

    // InitializeConditions for RateTransition: 'Rate Transition6' (':1982')
    FLIGHT_Hexacopter_V2_DW.RateTransition6_Buffer0_e =
      FLIGHT_Hexacopter_V2_P.RateTransition6_InitialCondit_f;

    // InitializeConditions for DiscreteIntegrator: 'Integrator' (':1821:10:843') 
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_lu =
      FLIGHT_Hexacopter_V2_P.pid_ctrl_rollrate_InitialCond_p;
    FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_l = 2;

    // InitializeConditions for UnitDelay: 'Unit Delay1' (':1821:2:220:338')
    FLIGHT_Hexacopter_V2_DW.UnitDelay1_DSTATE_i =
      FLIGHT_Hexacopter_V2_P.UnitDelay1_InitialCondition_e;

    // InitializeConditions for UnitDelay: 'UD' (':1821:1:5')
    //
    //  Block description for 'UD' (':1821:1:5'):
    //
    //   Store in Global RAM

    FLIGHT_Hexacopter_V2_DW.UD_DSTATE_a =
      FLIGHT_Hexacopter_V2_P.DiscreteDerivative2_ICPrevSca_n;

    // InitializeConditions for DiscreteIntegrator: 'Discrete-Time Integrator' (':436') 
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_PrevRe_l = 2;
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;

    // InitializeConditions for DiscreteIntegrator: 'Discrete-Time Integrator1' (':437') 
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_PrevRes = 2;
    FLIGHT_Hexacopter_V2_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;

    // InitializeConditions for DiscreteIntegrator: 'Integrator' (':514:843')
    FLIGHT_Hexacopter_V2_DW.Integrator_PrevResetState_l3 = 2;

    // InitializeConditions for DiscreteIntegrator: 'Filter' (':514:737')
    FLIGHT_Hexacopter_V2_DW.Filter_PrevResetState = 2;

    // InitializeConditions for UnitDelay: 'Unit Delay2' (':1821:2:220:342')
    FLIGHT_Hexacopter_V2_DW.UnitDelay2_DSTATE_f =
      FLIGHT_Hexacopter_V2_P.UnitDelay2_InitialCondition_m;

    // SystemInitialize for MATLAB Function: 'MATLAB Function1' (':641')
    // :  start_time_usec = -1;
    FLIGHT_Hexacopter_V2_DW.start_time_usec = -1.0;

    // InitializeConditions for DiscreteIntegrator: 'Integrator' (':514:843')
    // :  X0 = [0,0];
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_k[0] =
      FLIGHT_Hexacopter_V2_P.PID_Altitude1_InitialConditio_f;

    // InitializeConditions for DiscreteIntegrator: 'Filter' (':514:737')
    FLIGHT_Hexacopter_V2_DW.Filter_DSTATE_i[0] =
      FLIGHT_Hexacopter_V2_P.PID_Altitude1_InitialConditionF;

    // InitializeConditions for DiscreteIntegrator: 'Integrator' (':514:843')
    FLIGHT_Hexacopter_V2_DW.Integrator_DSTATE_k[1] =
      FLIGHT_Hexacopter_V2_P.PID_Altitude1_InitialConditio_f;

    // InitializeConditions for DiscreteIntegrator: 'Filter' (':514:737')
    FLIGHT_Hexacopter_V2_DW.Filter_DSTATE_i[1] =
      FLIGHT_Hexacopter_V2_P.PID_Altitude1_InitialConditionF;

    // SystemInitialize for Enabled SubSystem: 'Enabled Subsystem' (':281:3')
    // SystemInitialize for SignalConversion generated from: 'In1' (':281:4') incorporates:
    //   Outport: 'Out1' (':281:6')

    // :  WP_num=0;
    // :  WP = [0 0; 0 0; 0 0; 0 0; 0 0]';
    FLIGHT_Hexacopter_V2_B.In1_p = FLIGHT_Hexacopter_V2_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: 'Enabled Subsystem' (':281:3')

    // SystemInitialize for Enabled SubSystem: 'Enabled Subsystem' (':299:3')
    // SystemInitialize for SignalConversion generated from: 'In1' (':299:4') incorporates:
    //   Outport: 'Out1' (':299:6')

    FLIGHT_Hexacopter_V2_B.In1_k = FLIGHT_Hexacopter_V2_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: 'Enabled Subsystem' (':299:3')

    // SystemInitialize for Enabled SubSystem: 'Enabled Subsystem' (':318:3')
    // SystemInitialize for SignalConversion generated from: 'In1' (':318:4') incorporates:
    //   Outport: 'Out1' (':318:6')

    FLIGHT_Hexacopter_V2_B.In1_e = FLIGHT_Hexacopter_V2_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: 'Enabled Subsystem' (':318:3')

    // SystemInitialize for Enabled SubSystem: 'Enabled Subsystem' (':319:3')
    // SystemInitialize for SignalConversion generated from: 'In1' (':319:4') incorporates:
    //   Outport: 'Out1' (':319:6')

    FLIGHT_Hexacopter_V2_B.In1_m = FLIGHT_Hexacopter_V2_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: 'Enabled Subsystem' (':319:3')

    // SystemInitialize for Enabled SubSystem: 'Enabled Subsystem' (':320:3')
    // SystemInitialize for SignalConversion generated from: 'In1' (':320:4') incorporates:
    //   Outport: 'Out1' (':320:6')

    FLIGHT_Hexacopter_V2_B.In1 = FLIGHT_Hexacopter_V2_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: 'Enabled Subsystem' (':320:3')

    // SystemInitialize for Enabled SubSystem: 'Enabled Subsystem' (':1186:3')
    // SystemInitialize for SignalConversion generated from: 'In1' (':1186:4') incorporates:
    //   Outport: 'Out1' (':1186:6')

    FLIGHT_Hexacopter_V2_B.In1_d = FLIGHT_Hexacopter_V2_P.Out1_Y0_g;

    // End of SystemInitialize for SubSystem: 'Enabled Subsystem' (':1186:3')

    // SystemInitialize for Enabled SubSystem: 'Enabled Subsystem' (':326:6:3')
    // SystemInitialize for SignalConversion generated from: 'In1' (':326:6:4') incorporates:
    //   Outport: 'Out1' (':326:6:6')

    FLIGHT_Hexacopter_V2_B.In1_b = FLIGHT_Hexacopter_V2_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: 'Enabled Subsystem' (':326:6:3')

    // Start for MATLABSystem: 'SourceBlock' (':299:9')
    FLIGHT_Hexacopter_V2_DW.obj_m.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_m.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_m.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_m.orbMetadataObj = ORB_ID
      (vehicle_angular_velocity);
    uORB_read_initialize(FLIGHT_Hexacopter_V2_DW.obj_m.orbMetadataObj,
                         &FLIGHT_Hexacopter_V2_DW.obj_m.eventStructObj);
    FLIGHT_Hexacopter_V2_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter13' (':1125')
    FLIGHT_Hexacopter_V2_DW.obj_oe.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_oe.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_oe.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr[0], true, 1.0);
    FLIGHT_Hexacopter_V2_DW.obj_oe.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter1' (':1124')
    FLIGHT_Hexacopter_V2_DW.obj_aw.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_aw.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_aw.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, 1.0);
    FLIGHT_Hexacopter_V2_DW.obj_aw.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter2' (':1126')
    FLIGHT_Hexacopter_V2_DW.obj_ps.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ps.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_ps.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1[0], true, 1.0);
    FLIGHT_Hexacopter_V2_DW.obj_ps.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter3' (':1127')
    FLIGHT_Hexacopter_V2_DW.obj_hi.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_hi.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_hi.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, 1.0);
    FLIGHT_Hexacopter_V2_DW.obj_hi.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter4' (':1128')
    FLIGHT_Hexacopter_V2_DW.obj_jg.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_jg.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_jg.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, 1.0);
    FLIGHT_Hexacopter_V2_DW.obj_jg.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter5' (':1129')
    FLIGHT_Hexacopter_V2_DW.obj_ic5.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ic5.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_ic5.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, 1.0);
    FLIGHT_Hexacopter_V2_DW.obj_ic5.isSetupComplete = true;

    // Start for MATLABSystem: 'PX4 PWM Output' (':1181')
    FLIGHT_Hexacopter_V2_DW.obj_md.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_md.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_md.isInitialized = 1;
    FLIGHT_Hexacopter_PWM_setupImpl(&FLIGHT_Hexacopter_V2_DW.obj_md, false,
      false);
    FLIGHT_Hexacopter_V2_DW.obj_md.isSetupComplete = true;
    FLIGHT_He_PX4Timestamp_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_pn);

    // Start for MATLABSystem: 'SinkBlock' (':1700:15') incorporates:
    //   BusAssignment: 'Bus Assignment' (':1699')

    FLIGHT_Hexacopter_V2_DW.obj_kg.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_kg.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_kg.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_kg.orbMetadataObj = ORB_ID
      (vehicle_attitude_smc_setpoint);
    uORB_write_initialize(FLIGHT_Hexacopter_V2_DW.obj_kg.orbMetadataObj,
                          &FLIGHT_Hexacopter_V2_DW.obj_kg.orbAdvertiseObj,
                          &FLIGHT_Hexacopter_V2_B.BusAssignment, 1);
    FLIGHT_Hexacopter_V2_DW.obj_kg.isSetupComplete = true;
    FLIGHT__PX4Timestamp_o_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_e);
    FLIGHT_He_PX4Timestamp_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp);

    // Start for MATLABSystem: 'SinkBlock' (':1288:104:15') incorporates:
    //   BusAssignment: 'Bus Assignment' (':1288:101')

    FLIGHT_Hexacopter_V2_DW.obj_nf.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_nf.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_nf.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_nf.orbMetadataObj = ORB_ID(actuator_motors);
    uORB_write_initialize(FLIGHT_Hexacopter_V2_DW.obj_nf.orbMetadataObj,
                          &FLIGHT_Hexacopter_V2_DW.obj_nf.orbAdvertiseObj,
                          &FLIGHT_Hexacopter_V2_B.BusAssignment_e, 1);
    FLIGHT_Hexacopter_V2_DW.obj_nf.isSetupComplete = true;
    FLIGHT__PX4Timestamp_o_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_c);

    // Start for MATLABSystem: 'SinkBlock' (':1210:104:15') incorporates:
    //   BusAssignment: 'Bus Assignment' (':1210:101')

    FLIGHT_Hexacopter_V2_DW.obj_fe.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_fe.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_fe.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_fe.orbMetadataObj = ORB_ID
      (actuator_controls_status_0);
    uORB_write_initialize(FLIGHT_Hexacopter_V2_DW.obj_fe.orbMetadataObj,
                          &FLIGHT_Hexacopter_V2_DW.obj_fe.orbAdvertiseObj,
                          &FLIGHT_Hexacopter_V2_B.BusAssignment_j, 1);
    FLIGHT_Hexacopter_V2_DW.obj_fe.isSetupComplete = true;

    // Start for MATLABSystem: 'SourceBlock' (':281:9')
    FLIGHT_Hexacopter_V2_DW.obj_n.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_n.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_n.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_n.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(FLIGHT_Hexacopter_V2_DW.obj_n.orbMetadataObj,
                         &FLIGHT_Hexacopter_V2_DW.obj_n.eventStructObj);
    FLIGHT_Hexacopter_V2_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter39' (':1856')
    FLIGHT_Hexacopter_V2_DW.obj_g.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_g.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_g.isSetupComplete = true;

    // Start for MATLABSystem: 'SourceBlock' (':320:9')
    FLIGHT_Hexacopter_V2_DW.obj_l.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_l.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_l.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_l.orbMetadataObj = ORB_ID(vehicle_local_position);
    uORB_read_initialize(FLIGHT_Hexacopter_V2_DW.obj_l.orbMetadataObj,
                         &FLIGHT_Hexacopter_V2_DW.obj_l.eventStructObj);
    FLIGHT_Hexacopter_V2_DW.obj_l.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter3' (':212')
    FLIGHT_Hexacopter_V2_DW.obj_c4.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_c4.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_c4.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_6[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_c4.isSetupComplete = true;
    FLIGHT_Hex_SourceBlock_Init(&FLIGHT_Hexacopter_V2_DW.SourceBlock_l);

    // Start for MATLABSystem: 'Read Parameter5' (':214')
    FLIGHT_Hexacopter_V2_DW.obj_ia.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ia.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_ia.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_7[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_ia.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter11' (':196')
    FLIGHT_Hexacopter_V2_DW.obj_jk.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_jk.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_jk.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_8[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_jk.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter26' (':423')
    FLIGHT_Hexacopter_V2_DW.obj_lt.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_lt.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_lt.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_9[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_lt.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter28' (':528')
    FLIGHT_Hexacopter_V2_DW.obj_ic.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ic.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_ic.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_a[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_ic.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter27' (':479')
    FLIGHT_Hexacopter_V2_DW.obj_l3.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_l3.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_l3.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_b[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_l3.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter40' (':1867')
    FLIGHT_Hexacopter_V2_DW.obj_pn.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_pn.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_pn.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_c[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_pn.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter45' (':2023')
    FLIGHT_Hexacopter_V2_DW.obj_k.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_k.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_d[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter46' (':2024')
    FLIGHT_Hexacopter_V2_DW.obj_pc.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_pc.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_pc.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_e[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_pc.isSetupComplete = true;

    // Start for MATLABSystem: 'SourceBlock' (':319:9')
    FLIGHT_Hexacopter_V2_DW.obj_a.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_a.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_a.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_a.orbMetadataObj = ORB_ID(vehicle_status);
    uORB_read_initialize(FLIGHT_Hexacopter_V2_DW.obj_a.orbMetadataObj,
                         &FLIGHT_Hexacopter_V2_DW.obj_a.eventStructObj);
    FLIGHT_Hexacopter_V2_DW.obj_a.isSetupComplete = true;

    // Start for MATLABSystem: 'SourceBlock' (':326:6:9')
    FLIGHT_Hexacopter_V2_DW.obj_i.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_i.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_i.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_i.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(FLIGHT_Hexacopter_V2_DW.obj_i.orbMetadataObj,
                         &FLIGHT_Hexacopter_V2_DW.obj_i.eventStructObj);
    FLIGHT_Hexacopter_V2_DW.obj_i.isSetupComplete = true;

    // Start for MATLABSystem: 'PX4 Timestamp' (':642')
    FLIGHT_Hexacopter_V2_DW.obj.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter1' (':194')
    FLIGHT_Hexacopter_V2_DW.obj_l4.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_l4.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_l4.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_f[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_l4.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter' (':193')
    FLIGHT_Hexacopter_V2_DW.obj_jf.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_jf.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_jf.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_g[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_jf.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter2' (':205')
    FLIGHT_Hexacopter_V2_DW.obj_a1.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_a1.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_a1.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_h[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_a1.isSetupComplete = true;
    FLIGHT__PX4Timestamp_c_Init(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_j);

    // Start for MATLABSystem: 'SinkBlock' (':1230:104:15') incorporates:
    //   BusAssignment: 'Bus Assignment' (':1230:101')

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

    // Start for MATLABSystem: 'Read Parameter9' (':218')
    FLIGHT_Hexacopter_V2_DW.obj_ai.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ai.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_ai.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_i[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_ai.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter6' (':215')
    FLIGHT_Hexacopter_V2_DW.obj_p.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_p.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_j[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_p.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter10' (':195')
    FLIGHT_Hexacopter_V2_DW.obj_bq.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_bq.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_bq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_k[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_bq.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter7' (':216')
    FLIGHT_Hexacopter_V2_DW.obj_fj.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_fj.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_fj.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_l[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_fj.isSetupComplete = true;

    // Start for MATLABSystem: 'SinkBlock' (':1251:104:15') incorporates:
    //   BusAssignment: 'Bus Assignment' (':1251:101')

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

    // Start for MATLABSystem: 'SinkBlock' (':1256:104:15') incorporates:
    //   BusAssignment: 'Bus Assignment' (':1256:101')

    FLIGHT_Hexacopter_V2_DW.obj_pm.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_pm.isSetupComplete = false;
    FLIGHT_Hexacopter_V2_DW.obj_pm.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_pm.orbMetadataObj = ORB_ID
      (vehicle_local_position_setpoint);
    uORB_write_initialize(FLIGHT_Hexacopter_V2_DW.obj_pm.orbMetadataObj,
                          &FLIGHT_Hexacopter_V2_DW.obj_pm.orbAdvertiseObj,
                          &FLIGHT_Hexacopter_V2_B.BusAssignment_g, 1);
    FLIGHT_Hexacopter_V2_DW.obj_pm.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter4' (':213')
    FLIGHT_Hexacopter_V2_DW.obj_c1.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_c1.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_c1.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_m[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_c1.isSetupComplete = true;
    FLIGHT_Hex_SourceBlock_Init(&FLIGHT_Hexacopter_V2_DW.SourceBlock_p);

    // Start for MATLABSystem: 'Read Parameter12' (':197')
    FLIGHT_Hexacopter_V2_DW.obj_jo.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_jo.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_jo.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_n[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_jo.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter13' (':198')
    FLIGHT_Hexacopter_V2_DW.obj_pf.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_pf.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_pf.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_o[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_pf.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter14' (':199')
    FLIGHT_Hexacopter_V2_DW.obj_fd.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_fd.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_fd.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_p[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_fd.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter15' (':200')
    FLIGHT_Hexacopter_V2_DW.obj_nn.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_nn.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_nn.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_q[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_nn.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter16' (':201')
    FLIGHT_Hexacopter_V2_DW.obj_j.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_j.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_j.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_r[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter17' (':202')
    FLIGHT_Hexacopter_V2_DW.obj_d.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_d.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_s[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter18' (':203')
    FLIGHT_Hexacopter_V2_DW.obj_ml.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ml.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_ml.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_t[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_ml.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter19' (':204')
    FLIGHT_Hexacopter_V2_DW.obj_mc.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_mc.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_mc.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_u[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_mc.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter29' (':1032')
    FLIGHT_Hexacopter_V2_DW.obj_br.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_br.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_br.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_v[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_br.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter30' (':1033')
    FLIGHT_Hexacopter_V2_DW.obj_mo.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_mo.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_mo.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_w[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_mo.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter31' (':1034')
    FLIGHT_Hexacopter_V2_DW.obj_as.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_as.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_as.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_x[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_as.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter32' (':1035')
    FLIGHT_Hexacopter_V2_DW.obj_lv.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_lv.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_lv.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_y[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_lv.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter33' (':1036')
    FLIGHT_Hexacopter_V2_DW.obj_bd.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_bd.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_bd.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_z[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_bd.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter34' (':1725')
    FLIGHT_Hexacopter_V2_DW.obj_oq.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_oq.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_oq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_10[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_oq.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter35' (':1726')
    FLIGHT_Hexacopter_V2_DW.obj_b.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_b.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_11[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_b.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter36' (':1727')
    FLIGHT_Hexacopter_V2_DW.obj_ln.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ln.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_ln.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_12[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_ln.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter37' (':1752')
    FLIGHT_Hexacopter_V2_DW.obj_pi.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_pi.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_pi.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_13[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_pi.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter38' (':1760')
    FLIGHT_Hexacopter_V2_DW.obj_e.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_e.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_e.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_14[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter41' (':1904')
    FLIGHT_Hexacopter_V2_DW.obj_h.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_h.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_h.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_15[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter42' (':1905')
    FLIGHT_Hexacopter_V2_DW.obj_fy.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_fy.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_fy.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_16[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_fy.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter43' (':1930')
    FLIGHT_Hexacopter_V2_DW.obj_ox.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_ox.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_ox.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_17[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_ox.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter44' (':1932')
    FLIGHT_Hexacopter_V2_DW.obj_o.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_o.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_o.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_18[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: 'Read Parameter8' (':217')
    FLIGHT_Hexacopter_V2_DW.obj_f.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_f.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_f.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_19[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_f.isSetupComplete = true;

    // Start for MATLABSystem: 'read_mc_rollrate_p' (':246')
    FLIGHT_Hexacopter_V2_DW.obj_c.matlabCodegenIsDeleted = false;
    FLIGHT_Hexacopter_V2_DW.obj_c.isInitialized = 1;
    FLIGHT_Hexacopter_V2_DW.obj_c.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1a[0], true, 4.0);
    FLIGHT_Hexacopter_V2_DW.obj_c.isSetupComplete = true;
  }
}

// Model terminate function
void FLIGHT_Hexacopter_V2_terminate(void)
{
  // Terminate for MATLABSystem: 'SourceBlock' (':299:9')
  if (!FLIGHT_Hexacopter_V2_DW.obj_m.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_m.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_m.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_V2_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: 'SourceBlock' (':299:9')

  // Terminate for MATLABSystem: 'Read Parameter13' (':1125')
  if (!FLIGHT_Hexacopter_V2_DW.obj_oe.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_oe.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter13' (':1125')

  // Terminate for MATLABSystem: 'Read Parameter1' (':1124')
  if (!FLIGHT_Hexacopter_V2_DW.obj_aw.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_aw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter1' (':1124')

  // Terminate for MATLABSystem: 'Read Parameter2' (':1126')
  if (!FLIGHT_Hexacopter_V2_DW.obj_ps.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_ps.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter2' (':1126')

  // Terminate for MATLABSystem: 'Read Parameter3' (':1127')
  if (!FLIGHT_Hexacopter_V2_DW.obj_hi.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_hi.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter3' (':1127')

  // Terminate for MATLABSystem: 'Read Parameter4' (':1128')
  if (!FLIGHT_Hexacopter_V2_DW.obj_jg.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_jg.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter4' (':1128')

  // Terminate for MATLABSystem: 'Read Parameter5' (':1129')
  if (!FLIGHT_Hexacopter_V2_DW.obj_ic5.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_ic5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter5' (':1129')

  // Terminate for MATLABSystem: 'PX4 PWM Output' (':1181')
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

  // End of Terminate for MATLABSystem: 'PX4 PWM Output' (':1181')
  FLIGHT_He_PX4Timestamp_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_pn);

  // Terminate for MATLABSystem: 'SinkBlock' (':1700:15')
  if (!FLIGHT_Hexacopter_V2_DW.obj_kg.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_kg.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_kg.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_kg.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_Hexacopter_V2_DW.obj_kg.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: 'SinkBlock' (':1700:15')
  FLIGHT__PX4Timestamp_p_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_e);
  FLIGHT_He_PX4Timestamp_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp);

  // Terminate for MATLABSystem: 'SinkBlock' (':1288:104:15')
  if (!FLIGHT_Hexacopter_V2_DW.obj_nf.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_nf.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_nf.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_nf.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_Hexacopter_V2_DW.obj_nf.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: 'SinkBlock' (':1288:104:15')
  FLIGHT__PX4Timestamp_p_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_c);

  // Terminate for MATLABSystem: 'SinkBlock' (':1210:104:15')
  if (!FLIGHT_Hexacopter_V2_DW.obj_fe.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_fe.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_fe.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_fe.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_Hexacopter_V2_DW.obj_fe.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: 'SinkBlock' (':1210:104:15')

  // Terminate for MATLABSystem: 'SourceBlock' (':281:9')
  if (!FLIGHT_Hexacopter_V2_DW.obj_n.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_n.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_n.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_V2_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: 'SourceBlock' (':281:9')

  // Terminate for MATLABSystem: 'Read Parameter39' (':1856')
  if (!FLIGHT_Hexacopter_V2_DW.obj_g.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter39' (':1856')

  // Terminate for MATLABSystem: 'SourceBlock' (':320:9')
  if (!FLIGHT_Hexacopter_V2_DW.obj_l.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_l.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_V2_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: 'SourceBlock' (':320:9')

  // Terminate for MATLABSystem: 'Read Parameter3' (':212')
  if (!FLIGHT_Hexacopter_V2_DW.obj_c4.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_c4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter3' (':212')
  FLIGHT_Hex_SourceBlock_Term(&FLIGHT_Hexacopter_V2_DW.SourceBlock_l);

  // Terminate for MATLABSystem: 'Read Parameter5' (':214')
  if (!FLIGHT_Hexacopter_V2_DW.obj_ia.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_ia.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter5' (':214')

  // Terminate for MATLABSystem: 'Read Parameter11' (':196')
  if (!FLIGHT_Hexacopter_V2_DW.obj_jk.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_jk.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter11' (':196')

  // Terminate for MATLABSystem: 'Read Parameter26' (':423')
  if (!FLIGHT_Hexacopter_V2_DW.obj_lt.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_lt.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter26' (':423')

  // Terminate for MATLABSystem: 'Read Parameter28' (':528')
  if (!FLIGHT_Hexacopter_V2_DW.obj_ic.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_ic.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter28' (':528')

  // Terminate for MATLABSystem: 'Read Parameter27' (':479')
  if (!FLIGHT_Hexacopter_V2_DW.obj_l3.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_l3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter27' (':479')

  // Terminate for MATLABSystem: 'Read Parameter40' (':1867')
  if (!FLIGHT_Hexacopter_V2_DW.obj_pn.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_pn.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter40' (':1867')

  // Terminate for MATLABSystem: 'Read Parameter45' (':2023')
  if (!FLIGHT_Hexacopter_V2_DW.obj_k.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter45' (':2023')

  // Terminate for MATLABSystem: 'Read Parameter46' (':2024')
  if (!FLIGHT_Hexacopter_V2_DW.obj_pc.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_pc.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter46' (':2024')

  // Terminate for MATLABSystem: 'SourceBlock' (':319:9')
  if (!FLIGHT_Hexacopter_V2_DW.obj_a.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_a.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_a.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_V2_DW.obj_a.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: 'SourceBlock' (':319:9')

  // Terminate for MATLABSystem: 'SourceBlock' (':326:6:9')
  if (!FLIGHT_Hexacopter_V2_DW.obj_i.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_i.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_i.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_Hexacopter_V2_DW.obj_i.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: 'SourceBlock' (':326:6:9')

  // Terminate for MATLABSystem: 'PX4 Timestamp' (':642')
  if (!FLIGHT_Hexacopter_V2_DW.obj.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'PX4 Timestamp' (':642')

  // Terminate for MATLABSystem: 'Read Parameter1' (':194')
  if (!FLIGHT_Hexacopter_V2_DW.obj_l4.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_l4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter1' (':194')

  // Terminate for MATLABSystem: 'Read Parameter' (':193')
  if (!FLIGHT_Hexacopter_V2_DW.obj_jf.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_jf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter' (':193')

  // Terminate for MATLABSystem: 'Read Parameter2' (':205')
  if (!FLIGHT_Hexacopter_V2_DW.obj_a1.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_a1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter2' (':205')
  FLIGHT__PX4Timestamp_d_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_j);

  // Terminate for MATLABSystem: 'SinkBlock' (':1230:104:15')
  if (!FLIGHT_Hexacopter_V2_DW.obj_m1.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_m1.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_m1.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_m1.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_Hexacopter_V2_DW.obj_m1.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: 'SinkBlock' (':1230:104:15')
  FLIGHT__PX4Timestamp_d_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_p);

  // Terminate for MATLABSystem: 'Read Parameter9' (':218')
  if (!FLIGHT_Hexacopter_V2_DW.obj_ai.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_ai.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter9' (':218')

  // Terminate for MATLABSystem: 'Read Parameter6' (':215')
  if (!FLIGHT_Hexacopter_V2_DW.obj_p.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter6' (':215')

  // Terminate for MATLABSystem: 'Read Parameter10' (':195')
  if (!FLIGHT_Hexacopter_V2_DW.obj_bq.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_bq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter10' (':195')

  // Terminate for MATLABSystem: 'Read Parameter7' (':216')
  if (!FLIGHT_Hexacopter_V2_DW.obj_fj.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_fj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter7' (':216')

  // Terminate for MATLABSystem: 'SinkBlock' (':1251:104:15')
  if (!FLIGHT_Hexacopter_V2_DW.obj_mp.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_mp.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_mp.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_mp.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_Hexacopter_V2_DW.obj_mp.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: 'SinkBlock' (':1251:104:15')
  FLIGHT__PX4Timestamp_d_Term(&FLIGHT_Hexacopter_V2_DW.PX4Timestamp_k);

  // Terminate for MATLABSystem: 'SinkBlock' (':1256:104:15')
  if (!FLIGHT_Hexacopter_V2_DW.obj_pm.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_pm.matlabCodegenIsDeleted = true;
    if ((FLIGHT_Hexacopter_V2_DW.obj_pm.isInitialized == 1) &&
        FLIGHT_Hexacopter_V2_DW.obj_pm.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_Hexacopter_V2_DW.obj_pm.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: 'SinkBlock' (':1256:104:15')

  // Terminate for MATLABSystem: 'Read Parameter4' (':213')
  if (!FLIGHT_Hexacopter_V2_DW.obj_c1.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_c1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter4' (':213')
  FLIGHT_Hex_SourceBlock_Term(&FLIGHT_Hexacopter_V2_DW.SourceBlock_p);

  // Terminate for MATLABSystem: 'Read Parameter12' (':197')
  if (!FLIGHT_Hexacopter_V2_DW.obj_jo.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_jo.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter12' (':197')

  // Terminate for MATLABSystem: 'Read Parameter13' (':198')
  if (!FLIGHT_Hexacopter_V2_DW.obj_pf.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_pf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter13' (':198')

  // Terminate for MATLABSystem: 'Read Parameter14' (':199')
  if (!FLIGHT_Hexacopter_V2_DW.obj_fd.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_fd.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter14' (':199')

  // Terminate for MATLABSystem: 'Read Parameter15' (':200')
  if (!FLIGHT_Hexacopter_V2_DW.obj_nn.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_nn.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter15' (':200')

  // Terminate for MATLABSystem: 'Read Parameter16' (':201')
  if (!FLIGHT_Hexacopter_V2_DW.obj_j.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter16' (':201')

  // Terminate for MATLABSystem: 'Read Parameter17' (':202')
  if (!FLIGHT_Hexacopter_V2_DW.obj_d.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter17' (':202')

  // Terminate for MATLABSystem: 'Read Parameter18' (':203')
  if (!FLIGHT_Hexacopter_V2_DW.obj_ml.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_ml.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter18' (':203')

  // Terminate for MATLABSystem: 'Read Parameter19' (':204')
  if (!FLIGHT_Hexacopter_V2_DW.obj_mc.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_mc.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter19' (':204')

  // Terminate for MATLABSystem: 'Read Parameter29' (':1032')
  if (!FLIGHT_Hexacopter_V2_DW.obj_br.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_br.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter29' (':1032')

  // Terminate for MATLABSystem: 'Read Parameter30' (':1033')
  if (!FLIGHT_Hexacopter_V2_DW.obj_mo.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_mo.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter30' (':1033')

  // Terminate for MATLABSystem: 'Read Parameter31' (':1034')
  if (!FLIGHT_Hexacopter_V2_DW.obj_as.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_as.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter31' (':1034')

  // Terminate for MATLABSystem: 'Read Parameter32' (':1035')
  if (!FLIGHT_Hexacopter_V2_DW.obj_lv.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_lv.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter32' (':1035')

  // Terminate for MATLABSystem: 'Read Parameter33' (':1036')
  if (!FLIGHT_Hexacopter_V2_DW.obj_bd.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_bd.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter33' (':1036')

  // Terminate for MATLABSystem: 'Read Parameter34' (':1725')
  if (!FLIGHT_Hexacopter_V2_DW.obj_oq.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_oq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter34' (':1725')

  // Terminate for MATLABSystem: 'Read Parameter35' (':1726')
  if (!FLIGHT_Hexacopter_V2_DW.obj_b.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter35' (':1726')

  // Terminate for MATLABSystem: 'Read Parameter36' (':1727')
  if (!FLIGHT_Hexacopter_V2_DW.obj_ln.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_ln.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter36' (':1727')

  // Terminate for MATLABSystem: 'Read Parameter37' (':1752')
  if (!FLIGHT_Hexacopter_V2_DW.obj_pi.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_pi.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter37' (':1752')

  // Terminate for MATLABSystem: 'Read Parameter38' (':1760')
  if (!FLIGHT_Hexacopter_V2_DW.obj_e.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter38' (':1760')

  // Terminate for MATLABSystem: 'Read Parameter41' (':1904')
  if (!FLIGHT_Hexacopter_V2_DW.obj_h.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter41' (':1904')

  // Terminate for MATLABSystem: 'Read Parameter42' (':1905')
  if (!FLIGHT_Hexacopter_V2_DW.obj_fy.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_fy.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter42' (':1905')

  // Terminate for MATLABSystem: 'Read Parameter43' (':1930')
  if (!FLIGHT_Hexacopter_V2_DW.obj_ox.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_ox.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter43' (':1930')

  // Terminate for MATLABSystem: 'Read Parameter44' (':1932')
  if (!FLIGHT_Hexacopter_V2_DW.obj_o.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter44' (':1932')

  // Terminate for MATLABSystem: 'Read Parameter8' (':217')
  if (!FLIGHT_Hexacopter_V2_DW.obj_f.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'Read Parameter8' (':217')

  // Terminate for MATLABSystem: 'read_mc_rollrate_p' (':246')
  if (!FLIGHT_Hexacopter_V2_DW.obj_c.matlabCodegenIsDeleted) {
    FLIGHT_Hexacopter_V2_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: 'read_mc_rollrate_p' (':246')
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
