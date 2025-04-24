//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_hexacopter.cpp
//
// Code generated for Simulink model 'FLIGHT_hexacopter'.
//
// Model version                  : 1.146
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Thu Apr 24 17:45:28 2025
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
  if ((FLIGHT_hexacopter_M->Timing.TaskCounters.TID[1]) > 4) {// Sample time: [0.005s, 0.0s] 
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
void FLIGHT_h_ReadParameter_Init(DW_ReadParameter_FLIGHT_hexac_T *localDW)
{
  static const char_T ParameterNameStr[14] = "MPC_THR_HOVER";
  real_T tmp;

  // Start for MATLABSystem: '<S19>/Read Parameter'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  localDW->obj.isInitialized = 1;
  if (localDW->obj.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = localDW->obj.SampleTime;
  }

  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, tmp *
    1000.0);
  localDW->obj.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S19>/Read Parameter'
}

// Output and update for atomic system:
void FLIGHT_hexaco_ReadParameter(B_ReadParameter_FLIGHT_hexaco_T *localB,
  DW_ReadParameter_FLIGHT_hexac_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S19>/Read Parameter'
  if (localDW->obj.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  b_varargout_2 = MW_Param_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter_o1);
  if (b_varargout_2) {
    localB->ReadParameter_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S19>/Read Parameter'
}

// Termination for atomic system:
void FLIGHT_h_ReadParameter_Term(DW_ReadParameter_FLIGHT_hexac_T *localDW)
{
  // Terminate for MATLABSystem: '<S19>/Read Parameter'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/Read Parameter'
}

// System initialize for atomic system:
void FLIGHT__ReadParameter1_Init(DW_ReadParameter1_FLIGHT_hexa_T *localDW)
{
  static const char_T ParameterNameStr[16] = "MPC_Z_VEL_P_ACC";
  real_T tmp;

  // Start for MATLABSystem: '<S19>/Read Parameter1'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  localDW->obj.isInitialized = 1;
  if (localDW->obj.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = localDW->obj.SampleTime;
  }

  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, tmp *
    1000.0);
  localDW->obj.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S19>/Read Parameter1'
}

// Output and update for atomic system:
void FLIGHT_hexac_ReadParameter1(B_ReadParameter1_FLIGHT_hexac_T *localB,
  DW_ReadParameter1_FLIGHT_hexa_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S19>/Read Parameter1'
  if (localDW->obj.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  b_varargout_2 = MW_Param_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter1_o1);
  if (b_varargout_2) {
    localB->ReadParameter1_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S19>/Read Parameter1'
}

// Termination for atomic system:
void FLIGHT__ReadParameter1_Term(DW_ReadParameter1_FLIGHT_hexa_T *localDW)
{
  // Terminate for MATLABSystem: '<S19>/Read Parameter1'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/Read Parameter1'
}

// System initialize for atomic system:
void FLIGHT__ReadParameter2_Init(DW_ReadParameter2_FLIGHT_hexa_T *localDW)
{
  static const char_T ParameterNameStr[16] = "MPC_Z_VEL_I_ACC";
  real_T tmp;

  // Start for MATLABSystem: '<S19>/Read Parameter2'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  localDW->obj.isInitialized = 1;
  if (localDW->obj.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = localDW->obj.SampleTime;
  }

  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, tmp *
    1000.0);
  localDW->obj.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S19>/Read Parameter2'
}

// Output and update for atomic system:
void FLIGHT_hexac_ReadParameter2(B_ReadParameter2_FLIGHT_hexac_T *localB,
  DW_ReadParameter2_FLIGHT_hexa_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S19>/Read Parameter2'
  if (localDW->obj.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  b_varargout_2 = MW_Param_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter2_o1);
  if (b_varargout_2) {
    localB->ReadParameter2_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S19>/Read Parameter2'
}

// Termination for atomic system:
void FLIGHT__ReadParameter2_Term(DW_ReadParameter2_FLIGHT_hexa_T *localDW)
{
  // Terminate for MATLABSystem: '<S19>/Read Parameter2'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/Read Parameter2'
}

// System initialize for atomic system:
void FLIGHT__ReadParameter3_Init(DW_ReadParameter3_FLIGHT_hexa_T *localDW)
{
  static const char_T ParameterNameStr[16] = "MPC_Z_VEL_D_ACC";
  real_T tmp;

  // Start for MATLABSystem: '<S19>/Read Parameter3'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  localDW->obj.isInitialized = 1;
  if (localDW->obj.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = localDW->obj.SampleTime;
  }

  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, tmp *
    1000.0);
  localDW->obj.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S19>/Read Parameter3'
}

// Output and update for atomic system:
void FLIGHT_hexac_ReadParameter3(B_ReadParameter3_FLIGHT_hexac_T *localB,
  DW_ReadParameter3_FLIGHT_hexa_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S19>/Read Parameter3'
  if (localDW->obj.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  b_varargout_2 = MW_Param_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter3_o1);
  if (b_varargout_2) {
    localB->ReadParameter3_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S19>/Read Parameter3'
}

// Termination for atomic system:
void FLIGHT__ReadParameter3_Term(DW_ReadParameter3_FLIGHT_hexa_T *localDW)
{
  // Terminate for MATLABSystem: '<S19>/Read Parameter3'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/Read Parameter3'
}

// System initialize for atomic system:
void FLIGHT__PX4Timestamp_b_Init(DW_PX4Timestamp_FLIGHT_hexa_b_T *localDW)
{
  // Start for MATLABSystem: '<S565>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_hexac_PX4Timestamp_o(B_PX4Timestamp_FLIGHT_hexac_l_T *localB)
{
  // MATLABSystem: '<S565>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void FLIGHT__PX4Timestamp_o_Term(DW_PX4Timestamp_FLIGHT_hexa_b_T *localDW)
{
  // Terminate for MATLABSystem: '<S565>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S565>/PX4 Timestamp'
}

// System initialize for atomic system:
void FLIGHT__PX4Timestamp_l_Init(DW_PX4Timestamp_FLIGHT_hexa_f_T *localDW)
{
  // Start for MATLABSystem: '<S15>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_hexac_PX4Timestamp_p(B_PX4Timestamp_FLIGHT_hexac_c_T *localB)
{
  // MATLABSystem: '<S15>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void FLIGHT__PX4Timestamp_b_Term(DW_PX4Timestamp_FLIGHT_hexa_f_T *localDW)
{
  // Terminate for MATLABSystem: '<S15>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S15>/PX4 Timestamp'
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
  int32_T ParamStep;
  int32_T ParamStep_0;
  int32_T ParamStep_1;
  int32_T ParamStep_2;
  int32_T ParamStep_3;
  int32_T i;
  real32_T ParamStep_4;
  real32_T ParamStep_5;
  real32_T rtb_IProdOut;
  real32_T rtb_IProdOut_a;
  real32_T rtb_NProdOut;
  real32_T rtb_NProdOut_a;
  real32_T rtb_NProdOut_g;
  real32_T rtb_Sum4;
  uint32_T tmp;
  uint16_T tmp_0;
  boolean_T b_varargout_1;
  boolean_T rtb_Compare_a;

  {                                    // Sample time: [0.001s, 0.0s]
    rate_monotonic_scheduler();
  }

  // RateTransition: '<Root>/Rate Transition5' incorporates:
  //   RateTransition: '<Root>/Rate Transition'

  if (FLIGHT_hexacopter_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<Root>/Rate Transition5'
    FLIGHT_hexacopter_B.RateTransition5 =
      FLIGHT_hexacopter_DW.RateTransition5_Buffer0;

    // RateTransition: '<Root>/Rate Transition'
    FLIGHT_hexacopter_B.RateTransition =
      FLIGHT_hexacopter_DW.RateTransition_Buffer0;

    // RateTransition: '<Root>/Rate Transition1'
    FLIGHT_hexacopter_B.RateTransition1 =
      FLIGHT_hexacopter_DW.RateTransition1_Buffer0;

    // RateTransition: '<Root>/Rate Transition2'
    FLIGHT_hexacopter_B.RateTransition2 =
      FLIGHT_hexacopter_DW.RateTransition2_Buffer0;
  }

  // End of RateTransition: '<Root>/Rate Transition5'

  // MATLABSystem: '<S575>/SourceBlock'
  b_varargout_1 = uORB_read_step(FLIGHT_hexacopter_DW.obj_pe.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_pe.eventStructObj, &FLIGHT_hexacopter_B.r3, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S575>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S576>/Enable'

  // Start for MATLABSystem: '<S575>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S576>/In1'
    FLIGHT_hexacopter_B.In1_h = FLIGHT_hexacopter_B.r3;
  }

  // End of Outputs for SubSystem: '<S575>/Enabled Subsystem'

  // RateTransition: '<Root>/Rate Transition6'
  if (FLIGHT_hexacopter_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<Root>/Rate Transition6'
    FLIGHT_hexacopter_B.RateTransition6 =
      FLIGHT_hexacopter_DW.RateTransition6_Buffer0;
  }

  // End of RateTransition: '<Root>/Rate Transition6'

  // Outputs for Enabled SubSystem: '<Root>/SAS' incorporates:
  //   EnablePort: '<S9>/Enable'

  if (FLIGHT_hexacopter_B.RateTransition6) {
    // MATLABSystem: '<S9>/Read Parameter2'
    if (FLIGHT_hexacopter_DW.obj_d.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_d.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_d.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep_4);
    if (b_varargout_1) {
      ParamStep_4 = 0.0F;
    }

    // Sum: '<S9>/Sum1'
    rtb_Sum4 = FLIGHT_hexacopter_B.RateTransition -
      FLIGHT_hexacopter_B.In1_h.xyz[0];

    // Product: '<S501>/NProd Out' incorporates:
    //   Constant: '<S9>/Constant'
    //   DiscreteIntegrator: '<S493>/Filter'
    //   MATLABSystem: '<S9>/Read Parameter2'
    //   Product: '<S491>/DProd Out'
    //   Sum: '<S493>/SumD'
    //
    rtb_NProdOut = (rtb_Sum4 * ParamStep_4 - FLIGHT_hexacopter_DW.Filter_DSTATE)
      * FLIGHT_hexacopter_P.Constant_Value_j4;

    // MATLABSystem: '<S9>/read_mc_rollrate_p'
    if (FLIGHT_hexacopter_DW.obj.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep_4);
    if (b_varargout_1) {
      ParamStep_4 = 0.0F;
    }

    // Sum: '<S507>/Sum' incorporates:
    //   DiscreteIntegrator: '<S498>/Integrator'
    //   MATLABSystem: '<S9>/read_mc_rollrate_p'
    //   Product: '<S503>/PProd Out'
    //
    FLIGHT_hexacopter_B.Sum = (rtb_Sum4 * ParamStep_4 +
      FLIGHT_hexacopter_DW.Integrator_DSTATE) + rtb_NProdOut;

    // MATLABSystem: '<S9>/Read Parameter1'
    if (FLIGHT_hexacopter_DW.obj_ea.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_ea.SampleTime =
        FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_ea.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep_4);
    if (b_varargout_1) {
      ParamStep_4 = 0.0F;
    }

    // Product: '<S495>/IProd Out' incorporates:
    //   MATLABSystem: '<S9>/Read Parameter1'
    //
    rtb_IProdOut = rtb_Sum4 * ParamStep_4;

    // MATLABSystem: '<S9>/Read Parameter5'
    if (FLIGHT_hexacopter_DW.obj_h.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_h.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_h.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep_4);
    if (b_varargout_1) {
      ParamStep_4 = 0.0F;
    }

    // Sum: '<S9>/Sum'
    rtb_Sum4 = FLIGHT_hexacopter_B.RateTransition1 -
      FLIGHT_hexacopter_B.In1_h.xyz[1];

    // Product: '<S451>/NProd Out' incorporates:
    //   Constant: '<S9>/Constant1'
    //   DiscreteIntegrator: '<S443>/Filter'
    //   MATLABSystem: '<S9>/Read Parameter5'
    //   Product: '<S441>/DProd Out'
    //   Sum: '<S443>/SumD'
    //
    rtb_NProdOut_g = (rtb_Sum4 * ParamStep_4 -
                      FLIGHT_hexacopter_DW.Filter_DSTATE_j) *
      FLIGHT_hexacopter_P.Constant1_Value_f;

    // MATLABSystem: '<S9>/Read Parameter3'
    if (FLIGHT_hexacopter_DW.obj_b.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_b.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_b.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep_4);
    if (b_varargout_1) {
      ParamStep_4 = 0.0F;
    }

    // Sum: '<S457>/Sum' incorporates:
    //   DiscreteIntegrator: '<S448>/Integrator'
    //   MATLABSystem: '<S9>/Read Parameter3'
    //   Product: '<S453>/PProd Out'
    //
    FLIGHT_hexacopter_B.Sum_a = (rtb_Sum4 * ParamStep_4 +
      FLIGHT_hexacopter_DW.Integrator_DSTATE_c) + rtb_NProdOut_g;

    // MATLABSystem: '<S9>/Read Parameter4'
    if (FLIGHT_hexacopter_DW.obj_p.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_p.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_p.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep_4);
    if (b_varargout_1) {
      ParamStep_4 = 0.0F;
    }

    // Product: '<S445>/IProd Out' incorporates:
    //   MATLABSystem: '<S9>/Read Parameter4'
    //
    rtb_IProdOut_a = rtb_Sum4 * ParamStep_4;

    // MATLABSystem: '<S9>/Read Parameter8'
    if (FLIGHT_hexacopter_DW.obj_i.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_i.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_i.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep_4);
    if (b_varargout_1) {
      ParamStep_4 = 0.0F;
    }

    // Sum: '<S9>/Sum4'
    rtb_Sum4 = FLIGHT_hexacopter_B.RateTransition2 -
      FLIGHT_hexacopter_B.In1_h.xyz[2];

    // Product: '<S551>/NProd Out' incorporates:
    //   Constant: '<S9>/Constant2'
    //   DiscreteIntegrator: '<S543>/Filter'
    //   MATLABSystem: '<S9>/Read Parameter8'
    //   Product: '<S541>/DProd Out'
    //   Sum: '<S543>/SumD'
    //
    rtb_NProdOut_a = (rtb_Sum4 * ParamStep_4 -
                      FLIGHT_hexacopter_DW.Filter_DSTATE_h) *
      FLIGHT_hexacopter_P.Constant2_Value_m;

    // MATLABSystem: '<S9>/Read Parameter6'
    if (FLIGHT_hexacopter_DW.obj_a.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_a.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_a.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep_4);
    if (b_varargout_1) {
      ParamStep_4 = 0.0F;
    }

    // MATLABSystem: '<S9>/Read Parameter9'
    if (FLIGHT_hexacopter_DW.obj_e.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_e.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_e.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep_5);
    if (b_varargout_1) {
      ParamStep_5 = 0.0F;
    }

    // Sum: '<S9>/Sum2' incorporates:
    //   DiscreteIntegrator: '<S548>/Integrator'
    //   MATLABSystem: '<S9>/Read Parameter6'
    //   MATLABSystem: '<S9>/Read Parameter9'
    //   Product: '<S553>/PProd Out'
    //   Product: '<S9>/yawrate_feedforward'
    //   Sum: '<S557>/Sum'
    //
    FLIGHT_hexacopter_B.Sum2 = ((rtb_Sum4 * ParamStep_4 +
      FLIGHT_hexacopter_DW.Integrator_DSTATE_l) + rtb_NProdOut_a) + ParamStep_5 *
      FLIGHT_hexacopter_B.RateTransition2;

    // MATLABSystem: '<S9>/Read Parameter7'
    if (FLIGHT_hexacopter_DW.obj_j.SampleTime !=
        FLIGHT_hexacopter_P.SampleTime_SAS) {
      FLIGHT_hexacopter_DW.obj_j.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_j.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep_4);
    if (b_varargout_1) {
      ParamStep_4 = 0.0F;
    }

    // Update for DiscreteIntegrator: '<S493>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE += FLIGHT_hexacopter_P.Filter_gainval_o *
      rtb_NProdOut;

    // Update for DiscreteIntegrator: '<S498>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE +=
      FLIGHT_hexacopter_P.Integrator_gainval_i * rtb_IProdOut;

    // Update for DiscreteIntegrator: '<S443>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_j += FLIGHT_hexacopter_P.Filter_gainval_f
      * rtb_NProdOut_g;

    // Update for DiscreteIntegrator: '<S448>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_c +=
      FLIGHT_hexacopter_P.Integrator_gainval_im * rtb_IProdOut_a;

    // Update for DiscreteIntegrator: '<S543>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_h += FLIGHT_hexacopter_P.Filter_gainval_m
      * rtb_NProdOut_a;

    // Update for DiscreteIntegrator: '<S548>/Integrator' incorporates:
    //   MATLABSystem: '<S9>/Read Parameter7'
    //   Product: '<S545>/IProd Out'
    //
    FLIGHT_hexacopter_DW.Integrator_DSTATE_l += rtb_Sum4 * ParamStep_4 *
      FLIGHT_hexacopter_P.Integrator_gainval_e;
  }

  // End of Outputs for SubSystem: '<Root>/SAS'

  // RateTransition: '<Root>/Rate Transition3'
  if (FLIGHT_hexacopter_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<Root>/Rate Transition3'
    FLIGHT_hexacopter_B.RateTransition3 =
      FLIGHT_hexacopter_DW.RateTransition3_Buffer0;
  }

  // End of RateTransition: '<Root>/Rate Transition3'

  // Outputs for Enabled SubSystem: '<Root>/Mixer' incorporates:
  //   EnablePort: '<S6>/Enable'

  if (FLIGHT_hexacopter_B.RateTransition6) {
    // MATLAB Function: '<S6>/pwm_out2'
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
    ParamStep_4 = rt_roundf_snf(((-FLIGHT_hexacopter_B.Sum -
      FLIGHT_hexacopter_B.Sum2) * FLIGHT_hexacopter_B.RateTransition3 / 3.0F +
      FLIGHT_hexacopter_B.RateTransition3) * 1000.0F);
    if (ParamStep_4 < 65536.0F) {
      if (ParamStep_4 >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(ParamStep_4);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    tmp = tmp_0 + 1000U;
    if (ParamStep_4 < 65536.0F) {
      if (ParamStep_4 >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(ParamStep_4);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    if (tmp_0 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S6>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S6>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[0] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[0] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[0] = static_cast<uint16_T>(tmp);
    }

    // MATLAB Function: '<S6>/pwm_out2'
    ParamStep_4 = rt_roundf_snf(((FLIGHT_hexacopter_B.Sum +
      FLIGHT_hexacopter_B.Sum2) * FLIGHT_hexacopter_B.RateTransition3 / 3.0F +
      FLIGHT_hexacopter_B.RateTransition3) * 1000.0F);
    if (ParamStep_4 < 65536.0F) {
      if (ParamStep_4 >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(ParamStep_4);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    tmp = tmp_0 + 1000U;
    if (ParamStep_4 < 65536.0F) {
      if (ParamStep_4 >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(ParamStep_4);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    if (tmp_0 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S6>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S6>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[1] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[1] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[1] = static_cast<uint16_T>(tmp);
    }

    // MATLAB Function: '<S6>/pwm_out2'
    ParamStep_4 = rt_roundf_snf((((FLIGHT_hexacopter_B.Sum / 2.0F +
      FLIGHT_hexacopter_B.Sum_a) - FLIGHT_hexacopter_B.Sum2) *
      FLIGHT_hexacopter_B.RateTransition3 / 3.0F +
      FLIGHT_hexacopter_B.RateTransition3) * 1000.0F);
    if (ParamStep_4 < 65536.0F) {
      if (ParamStep_4 >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(ParamStep_4);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    tmp = tmp_0 + 1000U;
    if (ParamStep_4 < 65536.0F) {
      if (ParamStep_4 >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(ParamStep_4);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    if (tmp_0 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S6>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S6>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[2] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[2] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[2] = static_cast<uint16_T>(tmp);
    }

    // MATLAB Function: '<S6>/pwm_out2'
    ParamStep_4 = rt_roundf_snf((((-FLIGHT_hexacopter_B.Sum_a -
      FLIGHT_hexacopter_B.Sum / 2.0F) + FLIGHT_hexacopter_B.Sum2) *
      FLIGHT_hexacopter_B.RateTransition3 / 3.0F +
      FLIGHT_hexacopter_B.RateTransition3) * 1000.0F);
    if (ParamStep_4 < 65536.0F) {
      if (ParamStep_4 >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(ParamStep_4);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    tmp = tmp_0 + 1000U;
    if (ParamStep_4 < 65536.0F) {
      if (ParamStep_4 >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(ParamStep_4);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    if (tmp_0 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S6>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S6>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[3] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[3] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[3] = static_cast<uint16_T>(tmp);
    }

    // MATLAB Function: '<S6>/pwm_out2'
    ParamStep_4 = rt_roundf_snf((((FLIGHT_hexacopter_B.Sum_a -
      FLIGHT_hexacopter_B.Sum / 2.0F) + FLIGHT_hexacopter_B.Sum2) *
      FLIGHT_hexacopter_B.RateTransition3 / 3.0F +
      FLIGHT_hexacopter_B.RateTransition3) * 1000.0F);
    if (ParamStep_4 < 65536.0F) {
      if (ParamStep_4 >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(ParamStep_4);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    tmp = tmp_0 + 1000U;
    if (ParamStep_4 < 65536.0F) {
      if (ParamStep_4 >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(ParamStep_4);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    if (tmp_0 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S6>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S6>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[4] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[4] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[4] = static_cast<uint16_T>(tmp);
    }

    // MATLAB Function: '<S6>/pwm_out2'
    ParamStep_4 = rt_roundf_snf((((FLIGHT_hexacopter_B.Sum / 2.0F -
      FLIGHT_hexacopter_B.Sum_a) - FLIGHT_hexacopter_B.Sum2) *
      FLIGHT_hexacopter_B.RateTransition3 / 3.0F +
      FLIGHT_hexacopter_B.RateTransition3) * 1000.0F);
    if (ParamStep_4 < 65536.0F) {
      if (ParamStep_4 >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(ParamStep_4);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    tmp = tmp_0 + 1000U;
    if (ParamStep_4 < 65536.0F) {
      if (ParamStep_4 >= 0.0F) {
        tmp_0 = static_cast<uint16_T>(ParamStep_4);
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    if (tmp_0 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S6>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S6>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[5] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S6>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[5] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S6>/Output_Limits1'
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
  if (FLIGHT_hexacopter_DW.obj_g.SampleTime !=
      FLIGHT_hexacopter_P.SampleTime_SAS) {
    FLIGHT_hexacopter_DW.obj_g.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_g.MW_PARAMHANDLE,
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

  // RelationalOperator: '<S180>/Compare' incorporates:
  //   Constant: '<S180>/Constant'

  rtb_Compare_a = (FLIGHT_hexacopter_B.RateTransition4 >=
                   FLIGHT_hexacopter_P.CompareToConstant_const);

  // MATLABSystem: '<S4>/Read Parameter1'
  if (FLIGHT_hexacopter_DW.obj_j5.SampleTime !=
      FLIGHT_hexacopter_P.SampleTime_SAS) {
    FLIGHT_hexacopter_DW.obj_j5.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_j5.MW_PARAMHANDLE,
    MW_INT32, &ParamStep);
  if (b_varargout_1) {
    ParamStep = 0;
  }

  // MATLABSystem: '<S4>/Read Parameter2'
  if (FLIGHT_hexacopter_DW.obj_ao.SampleTime !=
      FLIGHT_hexacopter_P.SampleTime_SAS) {
    FLIGHT_hexacopter_DW.obj_ao.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_ao.MW_PARAMHANDLE,
    MW_INT32, &ParamStep_0);
  if (b_varargout_1) {
    ParamStep_0 = 0;
  }

  // MATLABSystem: '<S4>/Read Parameter3'
  if (FLIGHT_hexacopter_DW.obj_n.SampleTime !=
      FLIGHT_hexacopter_P.SampleTime_SAS) {
    FLIGHT_hexacopter_DW.obj_n.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_n.MW_PARAMHANDLE,
    MW_INT32, &ParamStep_1);
  if (b_varargout_1) {
    ParamStep_1 = 0;
  }

  // MATLABSystem: '<S4>/Read Parameter4'
  if (FLIGHT_hexacopter_DW.obj_c.SampleTime !=
      FLIGHT_hexacopter_P.SampleTime_SAS) {
    FLIGHT_hexacopter_DW.obj_c.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_c.MW_PARAMHANDLE,
    MW_INT32, &ParamStep_2);
  if (b_varargout_1) {
    ParamStep_2 = 0;
  }

  // MATLABSystem: '<S4>/Read Parameter5'
  if (FLIGHT_hexacopter_DW.obj_aq.SampleTime !=
      FLIGHT_hexacopter_P.SampleTime_SAS) {
    FLIGHT_hexacopter_DW.obj_aq.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_aq.MW_PARAMHANDLE,
    MW_INT32, &ParamStep_3);
  if (b_varargout_1) {
    ParamStep_3 = 0;
  }

  // Switch: '<S4>/Switch' incorporates:
  //   Constant: '<S4>/Constant'
  //   DataTypeConversion: '<S4>/Data Type Conversion3'
  //   MATLABSystem: '<S4>/Read Parameter13'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.u0 = i;
  } else {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Constant_Value_mc;
  }

  // Gain: '<S181>/Gain' incorporates:
  //   Switch: '<S4>/Switch'

  FLIGHT_hexacopter_B.u0 *= FLIGHT_hexacopter_P.Gain_Gain_j;

  // Saturate: '<S181>/Saturation'
  if (FLIGHT_hexacopter_B.u0 > FLIGHT_hexacopter_P.Saturation_UpperSat) {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_UpperSat;
  } else if (FLIGHT_hexacopter_B.u0 < FLIGHT_hexacopter_P.Saturation_LowerSat) {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_LowerSat;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S181>/Constant'
  //   Product: '<S181>/Product'
  //   Saturate: '<S181>/Saturation'
  //   Sum: '<S181>/Sum'
  //   Sum: '<S181>/Sum1'

  FLIGHT_hexacopter_B.u0 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[0]) -
    FLIGHT_hexacopter_P.Constant_Value_kf) * FLIGHT_hexacopter_B.u0 +
    FLIGHT_hexacopter_P.Constant_Value_kf);
  if (rtIsNaN(FLIGHT_hexacopter_B.u0) || rtIsInf(FLIGHT_hexacopter_B.u0)) {
    FLIGHT_hexacopter_B.u0 = 0.0;
  } else {
    FLIGHT_hexacopter_B.u0 = fmod(FLIGHT_hexacopter_B.u0, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7_k[0] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.u0 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-
       static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_hexacopter_B.u0)))) :
     static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_hexacopter_B.u0)));

  // Switch: '<S4>/Switch1' incorporates:
  //   Constant: '<S4>/Constant1'
  //   DataTypeConversion: '<S4>/Data Type Conversion2'
  //   MATLABSystem: '<S4>/Read Parameter1'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.u0 = ParamStep;
  } else {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Constant1_Value;
  }

  // Gain: '<S182>/Gain' incorporates:
  //   Switch: '<S4>/Switch1'

  FLIGHT_hexacopter_B.u0 *= FLIGHT_hexacopter_P.Gain_Gain_h;

  // Saturate: '<S182>/Saturation'
  if (FLIGHT_hexacopter_B.u0 > FLIGHT_hexacopter_P.Saturation_UpperSat_m) {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_UpperSat_m;
  } else if (FLIGHT_hexacopter_B.u0 < FLIGHT_hexacopter_P.Saturation_LowerSat_o)
  {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_LowerSat_o;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S182>/Constant'
  //   Product: '<S182>/Product'
  //   Saturate: '<S182>/Saturation'
  //   Sum: '<S182>/Sum'
  //   Sum: '<S182>/Sum1'

  FLIGHT_hexacopter_B.u0 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[1]) -
    FLIGHT_hexacopter_P.Constant_Value_ms) * FLIGHT_hexacopter_B.u0 +
    FLIGHT_hexacopter_P.Constant_Value_ms);
  if (rtIsNaN(FLIGHT_hexacopter_B.u0) || rtIsInf(FLIGHT_hexacopter_B.u0)) {
    FLIGHT_hexacopter_B.u0 = 0.0;
  } else {
    FLIGHT_hexacopter_B.u0 = fmod(FLIGHT_hexacopter_B.u0, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7_k[1] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.u0 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-
       static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_hexacopter_B.u0)))) :
     static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_hexacopter_B.u0)));

  // Switch: '<S4>/Switch2' incorporates:
  //   Constant: '<S4>/Constant2'
  //   DataTypeConversion: '<S4>/Data Type Conversion'
  //   MATLABSystem: '<S4>/Read Parameter2'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.u0 = ParamStep_0;
  } else {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Constant2_Value;
  }

  // Gain: '<S183>/Gain' incorporates:
  //   Switch: '<S4>/Switch2'

  FLIGHT_hexacopter_B.u0 *= FLIGHT_hexacopter_P.Gain_Gain_c;

  // Saturate: '<S183>/Saturation'
  if (FLIGHT_hexacopter_B.u0 > FLIGHT_hexacopter_P.Saturation_UpperSat_b) {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_UpperSat_b;
  } else if (FLIGHT_hexacopter_B.u0 < FLIGHT_hexacopter_P.Saturation_LowerSat_g)
  {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_LowerSat_g;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S183>/Constant'
  //   Product: '<S183>/Product'
  //   Saturate: '<S183>/Saturation'
  //   Sum: '<S183>/Sum'
  //   Sum: '<S183>/Sum1'

  FLIGHT_hexacopter_B.u0 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[2]) -
    FLIGHT_hexacopter_P.Constant_Value_ii) * FLIGHT_hexacopter_B.u0 +
    FLIGHT_hexacopter_P.Constant_Value_ii);
  if (rtIsNaN(FLIGHT_hexacopter_B.u0) || rtIsInf(FLIGHT_hexacopter_B.u0)) {
    FLIGHT_hexacopter_B.u0 = 0.0;
  } else {
    FLIGHT_hexacopter_B.u0 = fmod(FLIGHT_hexacopter_B.u0, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7_k[2] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.u0 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-
       static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_hexacopter_B.u0)))) :
     static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_hexacopter_B.u0)));

  // Switch: '<S4>/Switch3' incorporates:
  //   Constant: '<S4>/Constant3'
  //   DataTypeConversion: '<S4>/Data Type Conversion4'
  //   MATLABSystem: '<S4>/Read Parameter3'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.u0 = ParamStep_1;
  } else {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Constant3_Value;
  }

  // Gain: '<S184>/Gain' incorporates:
  //   Switch: '<S4>/Switch3'

  FLIGHT_hexacopter_B.u0 *= FLIGHT_hexacopter_P.Gain_Gain_n;

  // Saturate: '<S184>/Saturation'
  if (FLIGHT_hexacopter_B.u0 > FLIGHT_hexacopter_P.Saturation_UpperSat_be) {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_UpperSat_be;
  } else if (FLIGHT_hexacopter_B.u0 < FLIGHT_hexacopter_P.Saturation_LowerSat_e)
  {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_LowerSat_e;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S184>/Constant'
  //   Product: '<S184>/Product'
  //   Saturate: '<S184>/Saturation'
  //   Sum: '<S184>/Sum'
  //   Sum: '<S184>/Sum1'

  FLIGHT_hexacopter_B.u0 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[3]) -
    FLIGHT_hexacopter_P.Constant_Value_j4x) * FLIGHT_hexacopter_B.u0 +
    FLIGHT_hexacopter_P.Constant_Value_j4x);
  if (rtIsNaN(FLIGHT_hexacopter_B.u0) || rtIsInf(FLIGHT_hexacopter_B.u0)) {
    FLIGHT_hexacopter_B.u0 = 0.0;
  } else {
    FLIGHT_hexacopter_B.u0 = fmod(FLIGHT_hexacopter_B.u0, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7_k[3] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.u0 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-
       static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_hexacopter_B.u0)))) :
     static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_hexacopter_B.u0)));

  // Switch: '<S4>/Switch4' incorporates:
  //   Constant: '<S4>/Constant4'
  //   DataTypeConversion: '<S4>/Data Type Conversion1'
  //   MATLABSystem: '<S4>/Read Parameter4'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.u0 = ParamStep_2;
  } else {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Constant4_Value;
  }

  // Gain: '<S185>/Gain' incorporates:
  //   Switch: '<S4>/Switch4'

  FLIGHT_hexacopter_B.u0 *= FLIGHT_hexacopter_P.Gain_Gain_f;

  // Saturate: '<S185>/Saturation'
  if (FLIGHT_hexacopter_B.u0 > FLIGHT_hexacopter_P.Saturation_UpperSat_d) {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_UpperSat_d;
  } else if (FLIGHT_hexacopter_B.u0 < FLIGHT_hexacopter_P.Saturation_LowerSat_l)
  {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_LowerSat_l;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S185>/Constant'
  //   Product: '<S185>/Product'
  //   Saturate: '<S185>/Saturation'
  //   Sum: '<S185>/Sum'
  //   Sum: '<S185>/Sum1'

  FLIGHT_hexacopter_B.u0 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[4]) -
    FLIGHT_hexacopter_P.Constant_Value_l) * FLIGHT_hexacopter_B.u0 +
    FLIGHT_hexacopter_P.Constant_Value_l);
  if (rtIsNaN(FLIGHT_hexacopter_B.u0) || rtIsInf(FLIGHT_hexacopter_B.u0)) {
    FLIGHT_hexacopter_B.u0 = 0.0;
  } else {
    FLIGHT_hexacopter_B.u0 = fmod(FLIGHT_hexacopter_B.u0, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7_k[4] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.u0 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-
       static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_hexacopter_B.u0)))) :
     static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_hexacopter_B.u0)));

  // Switch: '<S4>/Switch5' incorporates:
  //   Constant: '<S4>/Constant5'
  //   DataTypeConversion: '<S4>/Data Type Conversion5'
  //   MATLABSystem: '<S4>/Read Parameter5'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.u0 = ParamStep_3;
  } else {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Constant5_Value;
  }

  // Gain: '<S186>/Gain' incorporates:
  //   Switch: '<S4>/Switch5'

  FLIGHT_hexacopter_B.u0 *= FLIGHT_hexacopter_P.Gain_Gain_m;

  // Saturate: '<S186>/Saturation'
  if (FLIGHT_hexacopter_B.u0 > FLIGHT_hexacopter_P.Saturation_UpperSat_i) {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_UpperSat_i;
  } else if (FLIGHT_hexacopter_B.u0 < FLIGHT_hexacopter_P.Saturation_LowerSat_n)
  {
    FLIGHT_hexacopter_B.u0 = FLIGHT_hexacopter_P.Saturation_LowerSat_n;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S186>/Constant'
  //   Product: '<S186>/Product'
  //   Saturate: '<S186>/Saturation'
  //   Sum: '<S186>/Sum'
  //   Sum: '<S186>/Sum1'

  FLIGHT_hexacopter_B.u0 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[5]) -
    FLIGHT_hexacopter_P.Constant_Value_o) * FLIGHT_hexacopter_B.u0 +
    FLIGHT_hexacopter_P.Constant_Value_o);
  if (rtIsNaN(FLIGHT_hexacopter_B.u0) || rtIsInf(FLIGHT_hexacopter_B.u0)) {
    FLIGHT_hexacopter_B.u0 = 0.0;
  } else {
    FLIGHT_hexacopter_B.u0 = fmod(FLIGHT_hexacopter_B.u0, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7_k[5] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.u0 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-
       static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_hexacopter_B.u0)))) :
     static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_hexacopter_B.u0)));

  // MATLABSystem: '<Root>/PX4 PWM Output' incorporates:
  //   Logic: '<Root>/NOT'

  for (i = 0; i < 8; i++) {
    FLIGHT_hexacopter_B.pwmValue[i] = 0U;
  }

  FLIGHT_hexacopter_B.pwmValue[0] = FLIGHT_hexacopter_B.DataTypeConversion7_k[0];
  FLIGHT_hexacopter_B.pwmValue[1] = FLIGHT_hexacopter_B.DataTypeConversion7_k[1];
  FLIGHT_hexacopter_B.pwmValue[2] = FLIGHT_hexacopter_B.DataTypeConversion7_k[2];
  FLIGHT_hexacopter_B.pwmValue[3] = FLIGHT_hexacopter_B.DataTypeConversion7_k[3];
  FLIGHT_hexacopter_B.pwmValue[4] = FLIGHT_hexacopter_B.DataTypeConversion7_k[4];
  FLIGHT_hexacopter_B.pwmValue[5] = FLIGHT_hexacopter_B.DataTypeConversion7_k[5];
  if (FLIGHT_hexacopter_B.RateTransition5) {
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
    if (!FLIGHT_hexacopter_B.RateTransition5) {
      pwm_disarm(&FLIGHT_hexacopter_DW.obj_dl.armAdvertiseObj);
    } else {
      pwm_arm(&FLIGHT_hexacopter_DW.obj_dl.armAdvertiseObj);
    }
  }

  // End of MATLABSystem: '<Root>/PX4 PWM Output'
  FLIGHT_hexac_PX4Timestamp_o(&FLIGHT_hexacopter_B.PX4Timestamp_o);

  // BusAssignment: '<S565>/Bus Assignment' incorporates:
  //   MATLABSystem: '<S565>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment_gi.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_o.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment_gi.control_power[0] =
    FLIGHT_hexacopter_B.Sum;
  FLIGHT_hexacopter_B.BusAssignment_gi.control_power[1] =
    FLIGHT_hexacopter_B.Sum_a;
  FLIGHT_hexacopter_B.BusAssignment_gi.control_power[2] =
    FLIGHT_hexacopter_B.Sum2;
  FLIGHT_hexacopter_B.BusAssignment_gi._padding0[0] = 0U;
  FLIGHT_hexacopter_B.BusAssignment_gi._padding0[1] = 0U;
  FLIGHT_hexacopter_B.BusAssignment_gi._padding0[2] = 0U;
  FLIGHT_hexacopter_B.BusAssignment_gi._padding0[3] = 0U;

  // MATLABSystem: '<S567>/SinkBlock' incorporates:
  //   BusAssignment: '<S565>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_jk.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_jk.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_gi);
  FLIGHT_hexac_PX4Timestamp_o(&FLIGHT_hexacopter_B.PX4Timestamp_n);
  FLIGHT_hexac_PX4Timestamp_o(&FLIGHT_hexacopter_B.PX4Timestamp_p);

  // BusAssignment: '<S569>/Bus Assignment' incorporates:
  //   Constant: '<S568>/Constant'
  //   Gain: '<S568>/Gain'
  //   MATLABSystem: '<S12>/PX4 Timestamp'
  //   MATLABSystem: '<S569>/PX4 Timestamp'
  //   Saturate: '<S568>/Saturation'
  //   Sum: '<S568>/Subtract'

  FLIGHT_hexacopter_B.BusAssignment_f.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_n.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment_f.timestamp_sample =
    FLIGHT_hexacopter_B.PX4Timestamp_p.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment_f.reversible_flags = 0U;
  for (i = 0; i < 6; i++) {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    ParamStep = FLIGHT_hexacopter_B.Output_Limits1[i];

    // Saturate: '<S568>/Saturation'
    if (ParamStep > FLIGHT_hexacopter_P.Saturation_UpperSat_ep) {
      ParamStep_4 = FLIGHT_hexacopter_P.Saturation_UpperSat_ep;
    } else if (ParamStep < FLIGHT_hexacopter_P.Saturation_LowerSat_p) {
      ParamStep_4 = FLIGHT_hexacopter_P.Saturation_LowerSat_p;
    } else {
      ParamStep_4 = static_cast<real32_T>(ParamStep);
    }

    FLIGHT_hexacopter_B.BusAssignment_f.control[i] = (ParamStep_4 -
      FLIGHT_hexacopter_P.Constant_Value_ez) * FLIGHT_hexacopter_P.Gain_Gain_mg;

    // Saturate: '<S568>/Saturation' incorporates:
    //   Constant: '<S12>/Constant1'
    //   Constant: '<S568>/Constant'
    //   Gain: '<S568>/Gain'
    //   Sum: '<S568>/Subtract'

    ParamStep_4 = FLIGHT_hexacopter_P.Constant1_Value_i[i];
    if (ParamStep_4 > FLIGHT_hexacopter_P.Saturation_UpperSat_ep) {
      ParamStep_4 = FLIGHT_hexacopter_P.Saturation_UpperSat_ep;
    } else if (ParamStep_4 < FLIGHT_hexacopter_P.Saturation_LowerSat_p) {
      ParamStep_4 = FLIGHT_hexacopter_P.Saturation_LowerSat_p;
    }

    FLIGHT_hexacopter_B.BusAssignment_f.control[i + 6] = (ParamStep_4 -
      FLIGHT_hexacopter_P.Constant_Value_ez) * FLIGHT_hexacopter_P.Gain_Gain_mg;
    FLIGHT_hexacopter_B.BusAssignment_f._padding0[i] = 0U;
  }

  // End of BusAssignment: '<S569>/Bus Assignment'

  // MATLABSystem: '<S572>/SinkBlock' incorporates:
  //   BusAssignment: '<S569>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_hf.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_hf.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_f);
  FLIGHT_hexac_PX4Timestamp_o(&FLIGHT_hexacopter_B.PX4Timestamp_ok);

  // BusAssignment: '<S570>/Bus Assignment' incorporates:
  //   Constant: '<S12>/Constant'
  //   Constant: '<S12>/Constant2'
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   MATLABSystem: '<S570>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_ok.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment.noutputs =
    FLIGHT_hexacopter_P.Constant2_Value_e;
  for (i = 0; i < 6; i++) {
    FLIGHT_hexacopter_B.BusAssignment.output[i] =
      FLIGHT_hexacopter_B.DataTypeConversion7_k[i];
  }

  for (i = 0; i < 10; i++) {
    FLIGHT_hexacopter_B.BusAssignment.output[i + 6] =
      FLIGHT_hexacopter_P.Constant_Value_bm[i];
  }

  FLIGHT_hexacopter_B.BusAssignment._padding0[0] = 0U;
  FLIGHT_hexacopter_B.BusAssignment._padding0[1] = 0U;
  FLIGHT_hexacopter_B.BusAssignment._padding0[2] = 0U;
  FLIGHT_hexacopter_B.BusAssignment._padding0[3] = 0U;

  // End of BusAssignment: '<S570>/Bus Assignment'

  // MATLABSystem: '<S574>/SinkBlock' incorporates:
  //   BusAssignment: '<S570>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_px.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_px.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment);
}

// Model step function for TID1
void FLIGHT_hexacopter_step1(void)     // Sample time: [0.005s, 0.0s]
{
  real_T rtb_out_yawrate;
  int32_T i;
  real32_T ParamStep;
  real32_T rtb_DeadZone;
  real32_T rtb_Saturation3;
  real32_T rtb_SinCos_o2;
  real32_T rtb_sincos_o1_0;
  real32_T rtb_sincos_o1_idx_1;
  real32_T rtb_sincos_o2_idx_1;
  real32_T tmp_1;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T b_varargout_1;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_o;
  FLIGHT_hexac_PX4Timestamp_p(&FLIGHT_hexacopter_B.PX4Timestamp_pn);

  // MATLABSystem: '<S410>/SourceBlock'
  b_varargout_1 = uORB_read_step(FLIGHT_hexacopter_DW.obj_p2.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_p2.eventStructObj, &FLIGHT_hexacopter_B.r2, false,
    5000.0);

  // Outputs for Enabled SubSystem: '<S410>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S411>/Enable'

  // Start for MATLABSystem: '<S410>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S411>/In1'
    FLIGHT_hexacopter_B.In1_n = FLIGHT_hexacopter_B.r2;
  }

  // End of Outputs for SubSystem: '<S410>/Enabled Subsystem'

  // SignalConversion generated from: '<S408>/Bus Selector'
  for (i = 0; i < 18; i++) {
    FLIGHT_hexacopter_B.values[i] = FLIGHT_hexacopter_B.In1_n.values[i];
  }

  // End of SignalConversion generated from: '<S408>/Bus Selector'

  // MATLABSystem: '<S401>/SourceBlock'
  b_varargout_1 = uORB_read_step(FLIGHT_hexacopter_DW.obj_kk.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_kk.eventStructObj, &FLIGHT_hexacopter_B.r, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S401>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S403>/Enable'

  // Start for MATLABSystem: '<S401>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S403>/In1'
    FLIGHT_hexacopter_B.In1 = FLIGHT_hexacopter_B.r;
  }

  // End of Outputs for SubSystem: '<S401>/Enabled Subsystem'

  // RelationalOperator: '<S409>/Compare' incorporates:
  //   Constant: '<S409>/Constant'

  rtb_Compare = (FLIGHT_hexacopter_B.values[4] >=
                 FLIGHT_hexacopter_P.CompareToConstant3_const);

  // If: '<Root>/If'
  if ((FLIGHT_hexacopter_B.values[5] > 1400) && (FLIGHT_hexacopter_B.values[5] <
       1800)) {
    // Outputs for IfAction SubSystem: '<Root>/Altitude_Mode' incorporates:
    //   ActionPort: '<S1>/Action Port'

    // Fcn: '<S18>/Fcn2' incorporates:
    //   DataTypeConversion: '<S18>/Data Type Conversion1'

    rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.values[0]) -
                       1514.0F) / 500.0F;

    // DeadZone: '<S18>/Dead Zone3'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone3_End) {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone3_End;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone3_Start) {
      ParamStep = 0.0F;
    } else {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone3_Start;
    }

    // End of DeadZone: '<S18>/Dead Zone3'

    // Saturate: '<S18>/Saturation9'
    if (ParamStep > FLIGHT_hexacopter_P.Saturation9_UpperSat) {
      ParamStep = FLIGHT_hexacopter_P.Saturation9_UpperSat;
    } else if (ParamStep < FLIGHT_hexacopter_P.Saturation9_LowerSat) {
      ParamStep = FLIGHT_hexacopter_P.Saturation9_LowerSat;
    }

    // SignalConversion generated from: '<S1>/des_roll' incorporates:
    //   Gain: '<S18>/Gain1'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S18>/Saturation9'

    FLIGHT_hexacopter_B.Merge1[0] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_ROLL *
      ParamStep;

    // Fcn: '<S18>/Fcn7' incorporates:
    //   DataTypeConversion: '<S18>/Data Type Conversion10'

    rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.values[3]) -
                       1514.0F) / 500.0F;

    // DeadZone: '<S18>/Dead Zone2'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone2_End) {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone2_End;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone2_Start) {
      ParamStep = 0.0F;
    } else {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone2_Start;
    }

    // End of DeadZone: '<S18>/Dead Zone2'

    // Saturate: '<S18>/Saturation3'
    if (ParamStep > FLIGHT_hexacopter_P.Saturation3_UpperSat) {
      ParamStep = FLIGHT_hexacopter_P.Saturation3_UpperSat;
    } else if (ParamStep < FLIGHT_hexacopter_P.Saturation3_LowerSat) {
      ParamStep = FLIGHT_hexacopter_P.Saturation3_LowerSat;
    }

    // SignalConversion generated from: '<S1>/des_r' incorporates:
    //   Gain: '<S18>/Gain3'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S18>/Saturation3'

    FLIGHT_hexacopter_B.Merge1[2] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_RATE_Y
      * ParamStep;

    // Fcn: '<S18>/Fcn3' incorporates:
    //   DataTypeConversion: '<S18>/Data Type Conversion11'

    rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.values[2]) -
                       1514.0F) / 500.0F;

    // DeadZone: '<S18>/Dead Zone4'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone4_End) {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone4_End;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone4_Start) {
      ParamStep = 0.0F;
    } else {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone4_Start;
    }

    // End of DeadZone: '<S18>/Dead Zone4'

    // Saturate: '<S18>/Saturation10'
    if (ParamStep > FLIGHT_hexacopter_P.Saturation10_UpperSat) {
      ParamStep = FLIGHT_hexacopter_P.Saturation10_UpperSat;
    } else if (ParamStep < FLIGHT_hexacopter_P.Saturation10_LowerSat) {
      ParamStep = FLIGHT_hexacopter_P.Saturation10_LowerSat;
    }

    // Gain: '<S18>/Gain' incorporates:
    //   Saturate: '<S18>/Saturation10'

    FLIGHT_hexacopter_B.Merge = FLIGHT_hexacopter_P.Gain_Gain_e * ParamStep;

    // Outputs for Enabled SubSystem: '<S1>/Vz Controller' incorporates:
    //   EnablePort: '<S19>/Enable'

    if (rtb_Compare) {
      // Gain: '<S19>/Gain' incorporates:
      //   Sum: '<S19>/Sum3'

      rtb_Saturation3 = (FLIGHT_hexacopter_B.Merge - FLIGHT_hexacopter_B.In1.vz)
        * FLIGHT_hexacopter_P.Gain_Gain_d;
      FLIGHT_hexac_ReadParameter3(&FLIGHT_hexacopter_B.ReadParameter3_p,
        &FLIGHT_hexacopter_DW.ReadParameter3_p);

      // Product: '<S59>/NProd Out' incorporates:
      //   Constant: '<S19>/Constant'
      //   DiscreteIntegrator: '<S51>/Filter'
      //   Product: '<S49>/DProd Out'
      //   Sum: '<S51>/SumD'

      rtb_SinCos_o2 = (rtb_Saturation3 *
                       FLIGHT_hexacopter_B.ReadParameter3_p.ReadParameter3_o1 -
                       FLIGHT_hexacopter_DW.Filter_DSTATE_i) *
        FLIGHT_hexacopter_P.Constant_Value_bi;
      FLIGHT_hexac_ReadParameter1(&FLIGHT_hexacopter_B.ReadParameter1_pna,
        &FLIGHT_hexacopter_DW.ReadParameter1_pna);

      // Sum: '<S65>/Sum' incorporates:
      //   DiscreteIntegrator: '<S56>/Integrator'
      //   Product: '<S61>/PProd Out'

      rtb_DeadZone = (rtb_Saturation3 *
                      FLIGHT_hexacopter_B.ReadParameter1_pna.ReadParameter1_o1 +
                      FLIGHT_hexacopter_DW.Integrator_DSTATE_e) + rtb_SinCos_o2;
      FLIGHT_hexaco_ReadParameter(&FLIGHT_hexacopter_B.ReadParameter_pn,
        &FLIGHT_hexacopter_DW.ReadParameter_pn);

      // Saturate: '<S63>/Saturation'
      if (rtb_DeadZone > FLIGHT_hexacopter_P.PIDController4_UpperSaturationL) {
        ParamStep = FLIGHT_hexacopter_P.PIDController4_UpperSaturationL;
      } else if (rtb_DeadZone <
                 FLIGHT_hexacopter_P.PIDController4_LowerSaturationL) {
        ParamStep = FLIGHT_hexacopter_P.PIDController4_LowerSaturationL;
      } else {
        ParamStep = rtb_DeadZone;
      }

      // Sum: '<S19>/Sum6' incorporates:
      //   Saturate: '<S63>/Saturation'

      FLIGHT_hexacopter_B.Saturation1_i = ParamStep +
        FLIGHT_hexacopter_B.ReadParameter_pn.ReadParameter_o1;

      // Saturate: '<S19>/Saturation1'
      if (FLIGHT_hexacopter_B.Saturation1_i >
          FLIGHT_hexacopter_P.Saturation1_UpperSat) {
        // Sum: '<S19>/Sum6' incorporates:
        //   Saturate: '<S19>/Saturation1'

        FLIGHT_hexacopter_B.Saturation1_i =
          FLIGHT_hexacopter_P.Saturation1_UpperSat;
      } else if (FLIGHT_hexacopter_B.Saturation1_i <
                 FLIGHT_hexacopter_P.Saturation1_LowerSat) {
        // Sum: '<S19>/Sum6' incorporates:
        //   Saturate: '<S19>/Saturation1'

        FLIGHT_hexacopter_B.Saturation1_i =
          FLIGHT_hexacopter_P.Saturation1_LowerSat;
      }

      // End of Saturate: '<S19>/Saturation1'

      // DeadZone: '<S48>/DeadZone'
      if (rtb_DeadZone > FLIGHT_hexacopter_P.PIDController4_UpperSaturationL) {
        rtb_DeadZone -= FLIGHT_hexacopter_P.PIDController4_UpperSaturationL;
      } else if (rtb_DeadZone >=
                 FLIGHT_hexacopter_P.PIDController4_LowerSaturationL) {
        rtb_DeadZone = 0.0F;
      } else {
        rtb_DeadZone -= FLIGHT_hexacopter_P.PIDController4_LowerSaturationL;
      }

      // End of DeadZone: '<S48>/DeadZone'
      FLIGHT_hexac_ReadParameter2(&FLIGHT_hexacopter_B.ReadParameter2_pn,
        &FLIGHT_hexacopter_DW.ReadParameter2_pn);

      // Product: '<S53>/IProd Out'
      rtb_Saturation3 *= FLIGHT_hexacopter_B.ReadParameter2_pn.ReadParameter2_o1;

      // Update for DiscreteIntegrator: '<S51>/Filter'
      FLIGHT_hexacopter_DW.Filter_DSTATE_i += FLIGHT_hexacopter_P.Filter_gainval
        * rtb_SinCos_o2;

      // Switch: '<S46>/Switch1' incorporates:
      //   Constant: '<S46>/Clamping_zero'
      //   Constant: '<S46>/Constant'
      //   Constant: '<S46>/Constant2'
      //   RelationalOperator: '<S46>/fix for DT propagation issue'

      if (rtb_DeadZone > FLIGHT_hexacopter_P.Clamping_zero_Value) {
        tmp = FLIGHT_hexacopter_P.Constant_Value_jc;
      } else {
        tmp = FLIGHT_hexacopter_P.Constant2_Value_mj;
      }

      // Switch: '<S46>/Switch2' incorporates:
      //   Constant: '<S46>/Clamping_zero'
      //   Constant: '<S46>/Constant3'
      //   Constant: '<S46>/Constant4'
      //   RelationalOperator: '<S46>/fix for DT propagation issue1'

      if (rtb_Saturation3 > FLIGHT_hexacopter_P.Clamping_zero_Value) {
        tmp_0 = FLIGHT_hexacopter_P.Constant3_Value_es;
      } else {
        tmp_0 = FLIGHT_hexacopter_P.Constant4_Value_j;
      }

      // Switch: '<S46>/Switch' incorporates:
      //   Constant: '<S46>/Clamping_zero'
      //   Constant: '<S46>/Constant1'
      //   Logic: '<S46>/AND3'
      //   RelationalOperator: '<S46>/Equal1'
      //   RelationalOperator: '<S46>/Relational Operator'
      //   Switch: '<S46>/Switch1'
      //   Switch: '<S46>/Switch2'

      if ((FLIGHT_hexacopter_P.Clamping_zero_Value != rtb_DeadZone) && (tmp ==
           tmp_0)) {
        rtb_Saturation3 = FLIGHT_hexacopter_P.Constant1_Value_n;
      }

      // Update for DiscreteIntegrator: '<S56>/Integrator' incorporates:
      //   Switch: '<S46>/Switch'

      FLIGHT_hexacopter_DW.Integrator_DSTATE_e +=
        FLIGHT_hexacopter_P.Integrator_gainval * rtb_Saturation3;
    }

    // End of Outputs for SubSystem: '<S1>/Vz Controller'

    // SignalConversion generated from: '<S1>/throttle' incorporates:
    //   Merge: '<Root>/Merge1'

    FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_B.Saturation1_i;

    // Fcn: '<S18>/Fcn1' incorporates:
    //   DataTypeConversion: '<S18>/Data Type Conversion2'

    rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.values[1]) -
                       1514.0F) / 500.0F;

    // DeadZone: '<S18>/Dead Zone1'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone1_End) {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone1_End;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone1_Start) {
      ParamStep = 0.0F;
    } else {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone1_Start;
    }

    // End of DeadZone: '<S18>/Dead Zone1'

    // Saturate: '<S18>/Saturation1'
    if (ParamStep > FLIGHT_hexacopter_P.Saturation1_UpperSat_d) {
      ParamStep = FLIGHT_hexacopter_P.Saturation1_UpperSat_d;
    } else if (ParamStep < FLIGHT_hexacopter_P.Saturation1_LowerSat_b) {
      ParamStep = FLIGHT_hexacopter_P.Saturation1_LowerSat_b;
    }

    // SignalConversion generated from: '<S1>/des_pitch' incorporates:
    //   Gain: '<S18>/Gain2'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S18>/Saturation1'

    FLIGHT_hexacopter_B.Merge1[1] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_PITCH *
      ParamStep;

    // End of Outputs for SubSystem: '<Root>/Altitude_Mode'
  } else if (FLIGHT_hexacopter_B.values[5] >= 1800) {
    // Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
    //   ActionPort: '<S5>/Action Port'

    // Outputs for Enabled SubSystem: '<S5>/XY Pos Controller' incorporates:
    //   EnablePort: '<S190>/Enable'

    if (rtb_Compare) {
      // MATLABSystem: '<S190>/Read Parameter'
      if (FLIGHT_hexacopter_DW.obj_eq.SampleTime !=
          FLIGHT_hexacopter_P.SampleTime) {
        FLIGHT_hexacopter_DW.obj_eq.SampleTime = FLIGHT_hexacopter_P.SampleTime;
      }

      b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_eq.MW_PARAMHANDLE,
        MW_SINGLE, &ParamStep);
      if (b_varargout_1) {
        ParamStep = 0.0F;
      }

      // Product: '<S335>/PProd Out' incorporates:
      //   Constant: '<S5>/Constant'
      //   MATLABSystem: '<S190>/Read Parameter'
      //   Sum: '<S190>/Sum'
      //
      FLIGHT_hexacopter_B.PProdOut[0] = (FLIGHT_hexacopter_P.Constant_Value_k[0]
        - FLIGHT_hexacopter_B.In1.x) * ParamStep;
      FLIGHT_hexacopter_B.PProdOut[1] = (FLIGHT_hexacopter_P.Constant_Value_k[1]
        - FLIGHT_hexacopter_B.In1.y) * ParamStep;
    }

    // End of Outputs for SubSystem: '<S5>/XY Pos Controller'

    // SignalConversion generated from: '<S5>/des_xy' incorporates:
    //   Constant: '<S5>/Constant'

    FLIGHT_hexacopter_B.OutportBufferFordes_xy[0] =
      FLIGHT_hexacopter_P.Constant_Value_k[0];
    FLIGHT_hexacopter_B.OutportBufferFordes_xy[1] =
      FLIGHT_hexacopter_P.Constant_Value_k[1];

    // Outputs for Enabled SubSystem: '<S5>/XY Velocity Controller' incorporates:
    //   EnablePort: '<S191>/Enable'

    if (rtb_Compare) {
      // Trigonometry: '<S349>/SinCos'
      rtb_Saturation3 = static_cast<real32_T>(sin(static_cast<real_T>
        (FLIGHT_hexacopter_B.In1.heading)));
      rtb_SinCos_o2 = static_cast<real32_T>(cos(static_cast<real_T>
        (FLIGHT_hexacopter_B.In1.heading)));

      // MATLABSystem: '<S191>/Read Parameter'
      if (FLIGHT_hexacopter_DW.obj_pi.SampleTime !=
          FLIGHT_hexacopter_P.SampleTime) {
        FLIGHT_hexacopter_DW.obj_pi.SampleTime = FLIGHT_hexacopter_P.SampleTime;
      }

      b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_pi.MW_PARAMHANDLE,
        MW_SINGLE, &ParamStep);
      if (b_varargout_1) {
        ParamStep = 0.0F;
      }

      // Sum: '<S191>/Sum'
      rtb_DeadZone = FLIGHT_hexacopter_B.PProdOut[0] -
        FLIGHT_hexacopter_B.In1.vx;
      rtb_sincos_o2_idx_1 = FLIGHT_hexacopter_B.PProdOut[1] -
        FLIGHT_hexacopter_B.In1.vy;

      // Saturate: '<S191>/Saturation' incorporates:
      //   Gain: '<S349>/Gain'
      //   MATLABSystem: '<S191>/Read Parameter'
      //   Product: '<S347>/MatrixMultiply'
      //   Product: '<S388>/PProd Out'
      //   Reshape: '<S349>/Reshape'
      //   Reshape: '<S349>/Reshape1'
      //
      rtb_sincos_o1_idx_1 = (rtb_SinCos_o2 * rtb_DeadZone + rtb_Saturation3 *
        rtb_sincos_o2_idx_1) * ParamStep;
      if (rtb_sincos_o1_idx_1 > FLIGHT_hexacopter_P.Saturation_UpperSat_e) {
        // Saturate: '<S191>/Saturation'
        FLIGHT_hexacopter_B.Saturation[0] =
          FLIGHT_hexacopter_P.Saturation_UpperSat_e;
      } else if (rtb_sincos_o1_idx_1 < FLIGHT_hexacopter_P.Saturation_LowerSat_a)
      {
        // Saturate: '<S191>/Saturation'
        FLIGHT_hexacopter_B.Saturation[0] =
          FLIGHT_hexacopter_P.Saturation_LowerSat_a;
      } else {
        // Saturate: '<S191>/Saturation'
        FLIGHT_hexacopter_B.Saturation[0] = rtb_sincos_o1_idx_1;
      }

      rtb_sincos_o1_idx_1 = (FLIGHT_hexacopter_P.Gain_Gain_a * rtb_Saturation3 *
        rtb_DeadZone + rtb_SinCos_o2 * rtb_sincos_o2_idx_1) * ParamStep;
      if (rtb_sincos_o1_idx_1 > FLIGHT_hexacopter_P.Saturation_UpperSat_e) {
        // Saturate: '<S191>/Saturation'
        FLIGHT_hexacopter_B.Saturation[1] =
          FLIGHT_hexacopter_P.Saturation_UpperSat_e;
      } else if (rtb_sincos_o1_idx_1 < FLIGHT_hexacopter_P.Saturation_LowerSat_a)
      {
        // Saturate: '<S191>/Saturation'
        FLIGHT_hexacopter_B.Saturation[1] =
          FLIGHT_hexacopter_P.Saturation_LowerSat_a;
      } else {
        // Saturate: '<S191>/Saturation'
        FLIGHT_hexacopter_B.Saturation[1] = rtb_sincos_o1_idx_1;
      }

      // End of Saturate: '<S191>/Saturation'

      // Gain: '<S191>/Gain1'
      FLIGHT_hexacopter_B.Gain1 = FLIGHT_hexacopter_P.Gain1_Gain_i *
        FLIGHT_hexacopter_B.Saturation[0];
    }

    // End of Outputs for SubSystem: '<S5>/XY Velocity Controller'

    // SignalConversion generated from: '<S5>/des_pitch' incorporates:
    //   Merge: '<Root>/Merge1'

    FLIGHT_hexacopter_B.Merge1[1] = FLIGHT_hexacopter_B.Gain1;

    // SignalConversion generated from: '<S5>/des_roll' incorporates:
    //   Merge: '<Root>/Merge1'

    FLIGHT_hexacopter_B.Merge1[0] = FLIGHT_hexacopter_B.Saturation[1];

    // Fcn: '<S188>/Fcn3' incorporates:
    //   DataTypeConversion: '<S188>/Data Type Conversion11'

    rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.values[2]) -
                       1514.0F) / 500.0F;

    // DeadZone: '<S188>/Dead Zone4'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone4_End_l) {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone4_End_l;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone4_Start_d) {
      ParamStep = 0.0F;
    } else {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone4_Start_d;
    }

    // End of DeadZone: '<S188>/Dead Zone4'

    // Saturate: '<S188>/Saturation10'
    if (ParamStep > FLIGHT_hexacopter_P.Saturation10_UpperSat_m) {
      ParamStep = FLIGHT_hexacopter_P.Saturation10_UpperSat_m;
    } else if (ParamStep < FLIGHT_hexacopter_P.Saturation10_LowerSat_n) {
      ParamStep = FLIGHT_hexacopter_P.Saturation10_LowerSat_n;
    }

    // Sum: '<S5>/Add' incorporates:
    //   Gain: '<S188>/Gain'
    //   Saturate: '<S188>/Saturation10'

    FLIGHT_hexacopter_B.Add = FLIGHT_hexacopter_P.Gain_Gain_o * ParamStep +
      FLIGHT_hexacopter_B.In1.z;

    // Outputs for Enabled SubSystem: '<S5>/Vz Controller' incorporates:
    //   EnablePort: '<S189>/Enable'

    // Outputs for Enabled SubSystem: '<S5>/Altitude Controller' incorporates:
    //   EnablePort: '<S187>/Enable'

    if (rtb_Compare) {
      // MATLABSystem: '<S187>/Read Parameter1'
      if (FLIGHT_hexacopter_DW.obj_m.SampleTime !=
          FLIGHT_hexacopter_P.SampleTime) {
        FLIGHT_hexacopter_DW.obj_m.SampleTime = FLIGHT_hexacopter_P.SampleTime;
      }

      b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_m.MW_PARAMHANDLE,
        MW_SINGLE, &ParamStep);
      if (b_varargout_1) {
        ParamStep = 0.0F;
      }

      // Product: '<S231>/PProd Out' incorporates:
      //   MATLABSystem: '<S187>/Read Parameter1'
      //   Sum: '<S187>/Sum'
      //
      FLIGHT_hexacopter_B.des_vz = (FLIGHT_hexacopter_B.Add -
        FLIGHT_hexacopter_B.In1.z) * ParamStep;

      // Saturate: '<S233>/Saturation'
      if (FLIGHT_hexacopter_B.des_vz >
          FLIGHT_hexacopter_P.PIDController4_UpperSaturatio_h) {
        // Product: '<S231>/PProd Out' incorporates:
        //   SignalConversion generated from: '<S189>/des_vz'

        FLIGHT_hexacopter_B.des_vz =
          FLIGHT_hexacopter_P.PIDController4_UpperSaturatio_h;
      } else if (FLIGHT_hexacopter_B.des_vz <
                 FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_a) {
        // Product: '<S231>/PProd Out' incorporates:
        //   SignalConversion generated from: '<S189>/des_vz'

        FLIGHT_hexacopter_B.des_vz =
          FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_a;
      }

      // End of Saturate: '<S233>/Saturation'

      // Gain: '<S189>/Gain' incorporates:
      //   Sum: '<S189>/Sum3'

      rtb_Saturation3 = (FLIGHT_hexacopter_B.des_vz - FLIGHT_hexacopter_B.In1.vz)
        * FLIGHT_hexacopter_P.Gain_Gain_b;
      FLIGHT_hexac_ReadParameter3(&FLIGHT_hexacopter_B.ReadParameter3_pn,
        &FLIGHT_hexacopter_DW.ReadParameter3_pn);

      // DiscreteIntegrator: '<S274>/Filter'
      if ((FLIGHT_hexacopter_B.des_vz > 0.0F) &&
          (FLIGHT_hexacopter_DW.Filter_PrevResetState <= 0)) {
        FLIGHT_hexacopter_DW.Filter_DSTATE_g =
          FLIGHT_hexacopter_P.PIDController4_InitialConditi_l;
      }

      // Product: '<S282>/NProd Out' incorporates:
      //   Constant: '<S189>/Constant'
      //   DiscreteIntegrator: '<S274>/Filter'
      //   Product: '<S272>/DProd Out'
      //   Sum: '<S274>/SumD'

      rtb_SinCos_o2 = (rtb_Saturation3 *
                       FLIGHT_hexacopter_B.ReadParameter3_pn.ReadParameter3_o1 -
                       FLIGHT_hexacopter_DW.Filter_DSTATE_g) *
        FLIGHT_hexacopter_P.Constant_Value_e;
      FLIGHT_hexac_ReadParameter1(&FLIGHT_hexacopter_B.ReadParameter1_pnaev,
        &FLIGHT_hexacopter_DW.ReadParameter1_pnaev);

      // DiscreteIntegrator: '<S279>/Integrator'
      if ((FLIGHT_hexacopter_B.des_vz > 0.0F) &&
          (FLIGHT_hexacopter_DW.Integrator_PrevResetState <= 0)) {
        FLIGHT_hexacopter_DW.Integrator_DSTATE_k =
          FLIGHT_hexacopter_P.PIDController4_InitialConditi_i;
      }

      // Sum: '<S288>/Sum' incorporates:
      //   DiscreteIntegrator: '<S279>/Integrator'
      //   Product: '<S284>/PProd Out'

      rtb_DeadZone = (rtb_Saturation3 *
                      FLIGHT_hexacopter_B.ReadParameter1_pnaev.ReadParameter1_o1
                      + FLIGHT_hexacopter_DW.Integrator_DSTATE_k) +
        rtb_SinCos_o2;
      FLIGHT_hexaco_ReadParameter(&FLIGHT_hexacopter_B.ReadParameter_pna,
        &FLIGHT_hexacopter_DW.ReadParameter_pna);

      // Saturate: '<S286>/Saturation'
      if (rtb_DeadZone > FLIGHT_hexacopter_P.PIDController4_UpperSaturati_hy) {
        ParamStep = FLIGHT_hexacopter_P.PIDController4_UpperSaturati_hy;
      } else if (rtb_DeadZone <
                 FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_f) {
        ParamStep = FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_f;
      } else {
        ParamStep = rtb_DeadZone;
      }

      // Sum: '<S189>/Sum6' incorporates:
      //   Saturate: '<S286>/Saturation'

      FLIGHT_hexacopter_B.Saturation1 = ParamStep +
        FLIGHT_hexacopter_B.ReadParameter_pna.ReadParameter_o1;

      // Saturate: '<S189>/Saturation1'
      if (FLIGHT_hexacopter_B.Saturation1 >
          FLIGHT_hexacopter_P.Saturation1_UpperSat_e) {
        // Sum: '<S189>/Sum6' incorporates:
        //   Saturate: '<S189>/Saturation1'

        FLIGHT_hexacopter_B.Saturation1 =
          FLIGHT_hexacopter_P.Saturation1_UpperSat_e;
      } else if (FLIGHT_hexacopter_B.Saturation1 <
                 FLIGHT_hexacopter_P.Saturation1_LowerSat_bn) {
        // Sum: '<S189>/Sum6' incorporates:
        //   Saturate: '<S189>/Saturation1'

        FLIGHT_hexacopter_B.Saturation1 =
          FLIGHT_hexacopter_P.Saturation1_LowerSat_bn;
      }

      // End of Saturate: '<S189>/Saturation1'

      // DeadZone: '<S271>/DeadZone'
      if (rtb_DeadZone > FLIGHT_hexacopter_P.PIDController4_UpperSaturati_hy) {
        rtb_DeadZone -= FLIGHT_hexacopter_P.PIDController4_UpperSaturati_hy;
      } else if (rtb_DeadZone >=
                 FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_f) {
        rtb_DeadZone = 0.0F;
      } else {
        rtb_DeadZone -= FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_f;
      }

      // End of DeadZone: '<S271>/DeadZone'
      FLIGHT_hexac_ReadParameter2(&FLIGHT_hexacopter_B.ReadParameter2_pna,
        &FLIGHT_hexacopter_DW.ReadParameter2_pna);

      // Product: '<S276>/IProd Out'
      rtb_Saturation3 *=
        FLIGHT_hexacopter_B.ReadParameter2_pna.ReadParameter2_o1;

      // Update for DiscreteIntegrator: '<S274>/Filter'
      FLIGHT_hexacopter_DW.Filter_DSTATE_g +=
        FLIGHT_hexacopter_P.Filter_gainval_h * rtb_SinCos_o2;
      if (FLIGHT_hexacopter_B.des_vz > 0.0F) {
        FLIGHT_hexacopter_DW.Filter_PrevResetState = 1;
      } else if (FLIGHT_hexacopter_B.des_vz < 0.0F) {
        FLIGHT_hexacopter_DW.Filter_PrevResetState = -1;
      } else if (FLIGHT_hexacopter_B.des_vz == 0.0F) {
        FLIGHT_hexacopter_DW.Filter_PrevResetState = 0;
      } else {
        FLIGHT_hexacopter_DW.Filter_PrevResetState = 2;
      }

      // End of Update for DiscreteIntegrator: '<S274>/Filter'

      // Switch: '<S269>/Switch1' incorporates:
      //   Constant: '<S269>/Clamping_zero'
      //   Constant: '<S269>/Constant'
      //   Constant: '<S269>/Constant2'
      //   RelationalOperator: '<S269>/fix for DT propagation issue'

      if (rtb_DeadZone > FLIGHT_hexacopter_P.Clamping_zero_Value_f) {
        tmp = FLIGHT_hexacopter_P.Constant_Value_mn;
      } else {
        tmp = FLIGHT_hexacopter_P.Constant2_Value_p;
      }

      // Switch: '<S269>/Switch2' incorporates:
      //   Constant: '<S269>/Clamping_zero'
      //   Constant: '<S269>/Constant3'
      //   Constant: '<S269>/Constant4'
      //   RelationalOperator: '<S269>/fix for DT propagation issue1'

      if (rtb_Saturation3 > FLIGHT_hexacopter_P.Clamping_zero_Value_f) {
        tmp_0 = FLIGHT_hexacopter_P.Constant3_Value_n;
      } else {
        tmp_0 = FLIGHT_hexacopter_P.Constant4_Value_i;
      }

      // Switch: '<S269>/Switch' incorporates:
      //   Constant: '<S269>/Clamping_zero'
      //   Constant: '<S269>/Constant1'
      //   Logic: '<S269>/AND3'
      //   RelationalOperator: '<S269>/Equal1'
      //   RelationalOperator: '<S269>/Relational Operator'
      //   Switch: '<S269>/Switch1'
      //   Switch: '<S269>/Switch2'

      if ((FLIGHT_hexacopter_P.Clamping_zero_Value_f != rtb_DeadZone) && (tmp ==
           tmp_0)) {
        rtb_Saturation3 = FLIGHT_hexacopter_P.Constant1_Value_m;
      }

      // Update for DiscreteIntegrator: '<S279>/Integrator' incorporates:
      //   Switch: '<S269>/Switch'

      FLIGHT_hexacopter_DW.Integrator_DSTATE_k +=
        FLIGHT_hexacopter_P.Integrator_gainval_l * rtb_Saturation3;
      if (FLIGHT_hexacopter_B.des_vz > 0.0F) {
        FLIGHT_hexacopter_DW.Integrator_PrevResetState = 1;
      } else if (FLIGHT_hexacopter_B.des_vz < 0.0F) {
        FLIGHT_hexacopter_DW.Integrator_PrevResetState = -1;
      } else if (FLIGHT_hexacopter_B.des_vz == 0.0F) {
        FLIGHT_hexacopter_DW.Integrator_PrevResetState = 0;
      } else {
        FLIGHT_hexacopter_DW.Integrator_PrevResetState = 2;
      }

      // End of Update for DiscreteIntegrator: '<S279>/Integrator'
    }

    // End of Outputs for SubSystem: '<S5>/Altitude Controller'
    // End of Outputs for SubSystem: '<S5>/Vz Controller'

    // Gain: '<S18>/Gain' incorporates:
    //   Merge: '<Root>/Merge'
    //   SignalConversion generated from: '<S5>/des_vz'

    FLIGHT_hexacopter_B.Merge = FLIGHT_hexacopter_B.des_vz;

    // SignalConversion generated from: '<S5>/throttle' incorporates:
    //   Merge: '<Root>/Merge1'

    FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_B.Saturation1;

    // Fcn: '<S188>/Fcn7' incorporates:
    //   DataTypeConversion: '<S188>/Data Type Conversion10'

    rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.values[3]) -
                       1514.0F) / 500.0F;

    // DeadZone: '<S188>/Dead Zone2'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone2_End_k) {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone2_End_k;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone2_Start_k) {
      ParamStep = 0.0F;
    } else {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone2_Start_k;
    }

    // End of DeadZone: '<S188>/Dead Zone2'

    // Saturate: '<S188>/Saturation3'
    if (ParamStep > FLIGHT_hexacopter_P.Saturation3_UpperSat_b) {
      ParamStep = FLIGHT_hexacopter_P.Saturation3_UpperSat_b;
    } else if (ParamStep < FLIGHT_hexacopter_P.Saturation3_LowerSat_a) {
      ParamStep = FLIGHT_hexacopter_P.Saturation3_LowerSat_a;
    }

    // SignalConversion generated from: '<S5>/des_r' incorporates:
    //   Gain: '<S188>/Gain3'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S188>/Saturation3'

    FLIGHT_hexacopter_B.Merge1[2] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_RATE_Y
      * ParamStep;

    // End of Outputs for SubSystem: '<Root>/If Action Subsystem'
  } else {
    // Outputs for IfAction SubSystem: '<Root>/Stabilized_Mode' incorporates:
    //   ActionPort: '<S10>/Action Port'

    // Gain: '<S10>/Gain' incorporates:
    //   Constant: '<S10>/Constant'
    //   Sum: '<S10>/Sum'

    rtb_Saturation3 = static_cast<real32_T>((static_cast<real_T>
      (FLIGHT_hexacopter_B.values[2]) - FLIGHT_hexacopter_P.Constant_Value_c) *
      FLIGHT_hexacopter_P.Gain_Gain);

    // DeadZone: '<S10>/Dead Zone3'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone3_End_l) {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone3_End_l;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone3_Start_p) {
      ParamStep = 0.0F;
    } else {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone3_Start_p;
    }

    // End of DeadZone: '<S10>/Dead Zone3'

    // Saturate: '<S10>/Saturation'
    if (ParamStep > FLIGHT_hexacopter_P.Saturation_UpperSat_o) {
      // SignalConversion generated from: '<S10>/throttle' incorporates:
      //   Merge: '<Root>/Merge1'

      FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_P.Saturation_UpperSat_o;
    } else if (ParamStep < FLIGHT_hexacopter_P.Saturation_LowerSat_el) {
      // SignalConversion generated from: '<S10>/throttle' incorporates:
      //   Merge: '<Root>/Merge1'

      FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_P.Saturation_LowerSat_el;
    } else {
      // SignalConversion generated from: '<S10>/throttle' incorporates:
      //   Merge: '<Root>/Merge1'

      FLIGHT_hexacopter_B.Merge1[3] = ParamStep;
    }

    // End of Saturate: '<S10>/Saturation'

    // Gain: '<S10>/Gain2' incorporates:
    //   Constant: '<S10>/Constant1'
    //   Sum: '<S10>/Sum1'

    rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.values[3]) -
                       FLIGHT_hexacopter_P.Constant1_Value_l) *
      FLIGHT_hexacopter_P.Gain2_Gain;

    // DeadZone: '<S10>/Dead Zone2'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone2_End_e) {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone2_End_e;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone2_Start_o) {
      ParamStep = 0.0F;
    } else {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone2_Start_o;
    }

    // End of DeadZone: '<S10>/Dead Zone2'

    // Saturate: '<S10>/Saturation1'
    if (ParamStep > FLIGHT_hexacopter_P.Saturation1_UpperSat_l) {
      ParamStep = FLIGHT_hexacopter_P.Saturation1_UpperSat_l;
    } else if (ParamStep < FLIGHT_hexacopter_P.Saturation1_LowerSat_i) {
      ParamStep = FLIGHT_hexacopter_P.Saturation1_LowerSat_i;
    }

    // SignalConversion generated from: '<S10>/des_r' incorporates:
    //   Gain: '<S10>/Gain6'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S10>/Saturation1'

    FLIGHT_hexacopter_B.Merge1[2] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_RATE_Y
      * ParamStep;

    // Gain: '<S10>/Gain1' incorporates:
    //   Constant: '<S10>/Constant2'
    //   Sum: '<S10>/Sum2'

    rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.values[1]) -
                       FLIGHT_hexacopter_P.Constant2_Value_i) *
      FLIGHT_hexacopter_P.Gain1_Gain_m;

    // DeadZone: '<S10>/Dead Zone1'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone1_End_m) {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone1_End_m;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone1_Start_c) {
      ParamStep = 0.0F;
    } else {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone1_Start_c;
    }

    // End of DeadZone: '<S10>/Dead Zone1'

    // Saturate: '<S10>/Saturation2'
    if (ParamStep > FLIGHT_hexacopter_P.Saturation2_UpperSat) {
      ParamStep = FLIGHT_hexacopter_P.Saturation2_UpperSat;
    } else if (ParamStep < FLIGHT_hexacopter_P.Saturation2_LowerSat) {
      ParamStep = FLIGHT_hexacopter_P.Saturation2_LowerSat;
    }

    // SignalConversion generated from: '<S10>/des_P' incorporates:
    //   Gain: '<S10>/Gain5'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S10>/Saturation2'

    FLIGHT_hexacopter_B.Merge1[1] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_PITCH *
      ParamStep;

    // Gain: '<S10>/Gain3' incorporates:
    //   Constant: '<S10>/Constant3'
    //   Sum: '<S10>/Sum3'

    rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.values[0]) -
                       FLIGHT_hexacopter_P.Constant3_Value_e) *
      FLIGHT_hexacopter_P.Gain3_Gain;

    // DeadZone: '<S10>/Dead Zone'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone_End) {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone_End;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone_Start) {
      ParamStep = 0.0F;
    } else {
      ParamStep = rtb_Saturation3 - FLIGHT_hexacopter_P.DeadZone_Start;
    }

    // End of DeadZone: '<S10>/Dead Zone'

    // Saturate: '<S10>/Saturation3'
    if (ParamStep > FLIGHT_hexacopter_P.Saturation3_UpperSat_b4) {
      ParamStep = FLIGHT_hexacopter_P.Saturation3_UpperSat_b4;
    } else if (ParamStep < FLIGHT_hexacopter_P.Saturation3_LowerSat_j) {
      ParamStep = FLIGHT_hexacopter_P.Saturation3_LowerSat_j;
    }

    // Gain: '<S10>/Gain4' incorporates:
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S10>/Saturation3'

    FLIGHT_hexacopter_B.Merge1[0] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_ROLL *
      ParamStep;

    // End of Outputs for SubSystem: '<Root>/Stabilized_Mode'
  }

  // End of If: '<Root>/If'

  // RelationalOperator: '<S407>/Compare' incorporates:
  //   Constant: '<S407>/Constant'

  rtb_Compare_o = (FLIGHT_hexacopter_B.values[6] >=
                   FLIGHT_hexacopter_P.CompareToConstant_const_n);
  FLIGHT_hexacop_PX4Timestamp(&FLIGHT_hexacopter_B.PX4Timestamp);

  // MATLABSystem: '<S3>/Read Parameter1'
  if (FLIGHT_hexacopter_DW.obj_ct.SampleTime != FLIGHT_hexacopter_P.SampleTime)
  {
    FLIGHT_hexacopter_DW.obj_ct.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_ct.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep);
  if (b_varargout_1) {
    ParamStep = 0.0F;
  }

  // MATLABSystem: '<S3>/Read Parameter'
  if (FLIGHT_hexacopter_DW.obj_cf.SampleTime != FLIGHT_hexacopter_P.SampleTime)
  {
    FLIGHT_hexacopter_DW.obj_cf.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_cf.MW_PARAMHANDLE,
    MW_SINGLE, &rtb_Saturation3);
  if (b_varargout_1) {
    rtb_Saturation3 = 0.0F;
  }

  // MATLABSystem: '<S3>/Read Parameter2'
  if (FLIGHT_hexacopter_DW.obj_l.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj_l.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_l.MW_PARAMHANDLE,
    MW_INT32, &i);
  if (b_varargout_1) {
    i = 0;
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
  FLIGHT_hexacopter_B.out_roll = FLIGHT_hexacopter_B.Merge1[0];
  FLIGHT_hexacopter_B.out_pitch = FLIGHT_hexacopter_B.Merge1[1];
  rtb_out_yawrate = FLIGHT_hexacopter_B.Merge1[2];
  if (rtb_Compare_o && (FLIGHT_hexacopter_DW.start_time_usec == -1.0)) {
    FLIGHT_hexacopter_DW.start_time_usec = static_cast<real_T>
      (FLIGHT_hexacopter_B.PX4Timestamp.PX4Timestamp);
  }

  if (rtb_Compare_o && (FLIGHT_hexacopter_DW.start_time_usec > 0.0)) {
    //  time calculation
    FLIGHT_hexacopter_B.reletive_time_sec = (static_cast<real_T>
      (FLIGHT_hexacopter_B.PX4Timestamp.PX4Timestamp) -
      FLIGHT_hexacopter_DW.start_time_usec) * 1.0E-6;
  } else {
    FLIGHT_hexacopter_DW.start_time_usec = -1.0;
    FLIGHT_hexacopter_B.reletive_time_sec = 0.0;
  }

  //  Define Doublet
  FLIGHT_hexacopter_B.peak_angle_rad = ParamStep * 0.017453292519943295;

  //  Default Output
  //  Generate Doublet Command
  if (rtb_Compare_o) {
    switch (i) {
     case 1:
      if ((FLIGHT_hexacopter_B.reletive_time_sec >= 0.0) &&
          (FLIGHT_hexacopter_B.reletive_time_sec < rtb_Saturation3)) {
        FLIGHT_hexacopter_B.out_roll = FLIGHT_hexacopter_B.peak_angle_rad;
      } else if ((FLIGHT_hexacopter_B.reletive_time_sec >= rtb_Saturation3) &&
                 (FLIGHT_hexacopter_B.reletive_time_sec < static_cast<real_T>
                  (rtb_Saturation3) + rtb_Saturation3)) {
        FLIGHT_hexacopter_B.out_roll = -FLIGHT_hexacopter_B.peak_angle_rad;
      } else {
        FLIGHT_hexacopter_B.out_roll = 0.0;
      }
      break;

     case 2:
      if ((FLIGHT_hexacopter_B.reletive_time_sec >= 0.0) &&
          (FLIGHT_hexacopter_B.reletive_time_sec < rtb_Saturation3)) {
        FLIGHT_hexacopter_B.out_pitch = FLIGHT_hexacopter_B.peak_angle_rad;
      } else if ((FLIGHT_hexacopter_B.reletive_time_sec >= rtb_Saturation3) &&
                 (FLIGHT_hexacopter_B.reletive_time_sec < static_cast<real_T>
                  (rtb_Saturation3) + rtb_Saturation3)) {
        FLIGHT_hexacopter_B.out_pitch = -FLIGHT_hexacopter_B.peak_angle_rad;
      } else {
        FLIGHT_hexacopter_B.out_pitch = 0.0;
      }
      break;

     case 3:
      if ((FLIGHT_hexacopter_B.reletive_time_sec >= 0.0) &&
          (FLIGHT_hexacopter_B.reletive_time_sec < rtb_Saturation3)) {
        rtb_out_yawrate = FLIGHT_hexacopter_B.peak_angle_rad;
      } else if ((FLIGHT_hexacopter_B.reletive_time_sec >= rtb_Saturation3) &&
                 (FLIGHT_hexacopter_B.reletive_time_sec < static_cast<real_T>
                  (rtb_Saturation3) + rtb_Saturation3)) {
        rtb_out_yawrate = -FLIGHT_hexacopter_B.peak_angle_rad;
      } else {
        rtb_out_yawrate = 0.0;
      }
      break;
    }
  }

  // End of MATLAB Function: '<S3>/MATLAB Function'

  // Gain: '<S579>/1//2' incorporates:
  //   Constant: '<Root>/Constant'
  //   DataTypeConversion: '<S3>/Data Type Conversion7'
  //   DataTypeConversion: '<S3>/Data Type Conversion8'

  rtb_DeadZone = FLIGHT_hexacopter_P.u2_Gain *
    FLIGHT_hexacopter_P.Constant_Value_a5;
  rtb_sincos_o1_idx_1 = FLIGHT_hexacopter_P.u2_Gain * static_cast<real32_T>
    (FLIGHT_hexacopter_B.out_pitch);
  ParamStep = FLIGHT_hexacopter_P.u2_Gain * static_cast<real32_T>
    (FLIGHT_hexacopter_B.out_roll);

  // Trigonometry: '<S579>/sincos'
  rtb_SinCos_o2 = static_cast<real32_T>(cos(static_cast<real_T>(rtb_DeadZone)));
  rtb_DeadZone = static_cast<real32_T>(sin(static_cast<real_T>(rtb_DeadZone)));
  rtb_sincos_o2_idx_1 = static_cast<real32_T>(cos(static_cast<real_T>
    (rtb_sincos_o1_idx_1)));
  rtb_sincos_o1_idx_1 = static_cast<real32_T>(sin(static_cast<real_T>
    (rtb_sincos_o1_idx_1)));
  rtb_Saturation3 = static_cast<real32_T>(cos(static_cast<real_T>(ParamStep)));
  rtb_sincos_o1_0 = static_cast<real32_T>(sin(static_cast<real_T>(ParamStep)));

  // BusAssignment: '<S15>/Bus Assignment' incorporates:
  //   Constant: '<S577>/Constant'

  FLIGHT_hexacopter_B.BusAssignment_d = FLIGHT_hexacopter_P.Constant_Value_j;

  // BusAssignment: '<S15>/Bus Assignment' incorporates:
  //   Constant: '<S15>/Constant'
  //   DataTypeConversion: '<S3>/Data Type Conversion7'
  //   DataTypeConversion: '<S3>/Data Type Conversion8'
  //   DataTypeConversion: '<S3>/Data Type Conversion9'
  //   MATLABSystem: '<S15>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment_d.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_pn.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment_d.roll_body = static_cast<real32_T>
    (FLIGHT_hexacopter_B.out_roll);
  FLIGHT_hexacopter_B.BusAssignment_d.pitch_body = static_cast<real32_T>
    (FLIGHT_hexacopter_B.out_pitch);
  FLIGHT_hexacopter_B.BusAssignment_d.yaw_sp_move_rate = static_cast<real32_T>
    (rtb_out_yawrate);
  FLIGHT_hexacopter_B.BusAssignment_d.thrust_body[0] =
    FLIGHT_hexacopter_P.Constant_Value_gq;
  FLIGHT_hexacopter_B.BusAssignment_d.thrust_body[1] =
    FLIGHT_hexacopter_P.Constant_Value_gq;
  FLIGHT_hexacopter_B.BusAssignment_d.thrust_body[2] =
    FLIGHT_hexacopter_B.Merge1[3];

  // Fcn: '<S579>/q0' incorporates:
  //   Fcn: '<S579>/q1'
  //   Trigonometry: '<S579>/sincos'

  ParamStep = rtb_SinCos_o2 * rtb_sincos_o2_idx_1;
  tmp_1 = rtb_DeadZone * rtb_sincos_o1_idx_1;

  // BusAssignment: '<S15>/Bus Assignment' incorporates:
  //   Fcn: '<S579>/q0'
  //   Fcn: '<S579>/q1'
  //   Trigonometry: '<S579>/sincos'

  FLIGHT_hexacopter_B.BusAssignment_d.q_d[0] = ParamStep * rtb_Saturation3 +
    tmp_1 * rtb_sincos_o1_0;
  FLIGHT_hexacopter_B.BusAssignment_d.q_d[1] = ParamStep * rtb_sincos_o1_0 -
    tmp_1 * rtb_Saturation3;

  // Fcn: '<S579>/q2' incorporates:
  //   Fcn: '<S579>/q3'
  //   Trigonometry: '<S579>/sincos'

  ParamStep = rtb_DeadZone * rtb_sincos_o2_idx_1;
  tmp_1 = rtb_SinCos_o2 * rtb_sincos_o1_idx_1;

  // BusAssignment: '<S15>/Bus Assignment' incorporates:
  //   Fcn: '<S579>/q2'
  //   Fcn: '<S579>/q3'
  //   Trigonometry: '<S579>/sincos'

  FLIGHT_hexacopter_B.BusAssignment_d.q_d[2] = tmp_1 * rtb_Saturation3 +
    ParamStep * rtb_sincos_o1_0;
  FLIGHT_hexacopter_B.BusAssignment_d.q_d[3] = ParamStep * rtb_Saturation3 -
    tmp_1 * rtb_sincos_o1_0;

  // MATLABSystem: '<S578>/SinkBlock' incorporates:
  //   BusAssignment: '<S15>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_pt.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_pt.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_d);
  FLIGHT_hexacop_PX4Timestamp(&FLIGHT_hexacopter_B.PX4Timestamp_pna);

  // BusAssignment: '<S16>/Bus Assignment' incorporates:
  //   Constant: '<S580>/Constant'

  FLIGHT_hexacopter_B.BusAssignment_g = FLIGHT_hexacopter_P.Constant_Value_n;

  // BusAssignment: '<S16>/Bus Assignment' incorporates:
  //   MATLABSystem: '<S16>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment_g.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_pna.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment_g.vx = FLIGHT_hexacopter_B.PProdOut[0];
  FLIGHT_hexacopter_B.BusAssignment_g.vy = FLIGHT_hexacopter_B.PProdOut[1];
  FLIGHT_hexacopter_B.BusAssignment_g.vz = FLIGHT_hexacopter_B.Merge;
  FLIGHT_hexacopter_B.BusAssignment_g.x =
    FLIGHT_hexacopter_B.OutportBufferFordes_xy[0];
  FLIGHT_hexacopter_B.BusAssignment_g.y =
    FLIGHT_hexacopter_B.OutportBufferFordes_xy[1];
  FLIGHT_hexacopter_B.BusAssignment_g.z = FLIGHT_hexacopter_B.Add;

  // MATLABSystem: '<S581>/SinkBlock' incorporates:
  //   BusAssignment: '<S16>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_pa.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_pa.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_g);
  FLIGHT_hexac_PX4Timestamp_p(&FLIGHT_hexacopter_B.PX4Timestamp_pnae);

  // MATLABSystem: '<S404>/SourceBlock'
  b_varargout_1 = uORB_read_step(FLIGHT_hexacopter_DW.obj_ab.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_ab.eventStructObj, &FLIGHT_hexacopter_B.r1, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S404>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S405>/Enable'

  // Start for MATLABSystem: '<S404>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S405>/In1'
    FLIGHT_hexacopter_B.In1_k = FLIGHT_hexacopter_B.r1;
  }

  // End of Outputs for SubSystem: '<S404>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<Root>/CAS' incorporates:
  //   EnablePort: '<S2>/Enable'

  //  Quaternion conversion to Euler angles based on the PX4 Firmware v1.10.2
  //  release.
  if (rtb_Compare) {
    // MATLABSystem: '<S2>/Read Parameter9'
    if (FLIGHT_hexacopter_DW.obj_k.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_k.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_k.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_1) {
      ParamStep = 0.0F;
    }

    // Gain: '<S73>/Gain1' incorporates:
    //   MATLABSystem: '<S2>/Read Parameter9'
    //
    rtb_SinCos_o2 = FLIGHT_hexacopter_P.Gain1_Gain_g * ParamStep;

    // MATLABSystem: '<S2>/Read Parameter'
    if (FLIGHT_hexacopter_DW.obj_jz.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_jz.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_jz.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_1) {
      ParamStep = 0.0F;
    }

    // Product: '<S166>/PProd Out' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion8'
    //   MATLAB Function: '<Root>/quat2eul'
    //   MATLABSystem: '<S2>/Read Parameter'
    //   Sum: '<S2>/Sum3'
    //
    ParamStep *= static_cast<real32_T>(FLIGHT_hexacopter_B.out_roll) -
      rt_atan2f_snf((FLIGHT_hexacopter_B.In1_k.q[0] *
                     FLIGHT_hexacopter_B.In1_k.q[1] +
                     FLIGHT_hexacopter_B.In1_k.q[2] *
                     FLIGHT_hexacopter_B.In1_k.q[3]) * 2.0F,
                    ((FLIGHT_hexacopter_B.In1_k.q[0] *
                      FLIGHT_hexacopter_B.In1_k.q[0] -
                      FLIGHT_hexacopter_B.In1_k.q[1] *
                      FLIGHT_hexacopter_B.In1_k.q[1]) -
                     FLIGHT_hexacopter_B.In1_k.q[2] *
                     FLIGHT_hexacopter_B.In1_k.q[2]) +
                    FLIGHT_hexacopter_B.In1_k.q[3] *
                    FLIGHT_hexacopter_B.In1_k.q[3]);

    // Switch: '<S169>/Switch2' incorporates:
    //   RelationalOperator: '<S169>/LowerRelop1'

    if (ParamStep > rtb_SinCos_o2) {
      // Switch: '<S169>/Switch2'
      FLIGHT_hexacopter_B.Switch2 = rtb_SinCos_o2;
    } else {
      // Gain: '<S2>/Gain'
      rtb_SinCos_o2 *= FLIGHT_hexacopter_P.Gain_Gain_m3;

      // Switch: '<S169>/Switch' incorporates:
      //   RelationalOperator: '<S169>/UpperRelop'

      if (ParamStep < rtb_SinCos_o2) {
        // Switch: '<S169>/Switch2'
        FLIGHT_hexacopter_B.Switch2 = rtb_SinCos_o2;
      } else {
        // Switch: '<S169>/Switch2'
        FLIGHT_hexacopter_B.Switch2 = ParamStep;
      }

      // End of Switch: '<S169>/Switch'
    }

    // End of Switch: '<S169>/Switch2'

    // MATLABSystem: '<S2>/Read Parameter10'
    if (FLIGHT_hexacopter_DW.obj_ds.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_ds.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_ds.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_1) {
      ParamStep = 0.0F;
    }

    // Gain: '<S74>/Gain1' incorporates:
    //   MATLABSystem: '<S2>/Read Parameter10'
    //
    rtb_SinCos_o2 = FLIGHT_hexacopter_P.Gain1_Gain_c * ParamStep;

    // MATLABSystem: '<S2>/Read Parameter1'
    if (FLIGHT_hexacopter_DW.obj_o.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_o.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_o.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_1) {
      ParamStep = 0.0F;
    }

    // Product: '<S115>/PProd Out' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion7'
    //   MATLAB Function: '<Root>/quat2eul'
    //   MATLABSystem: '<S2>/Read Parameter1'
    //   Sum: '<S2>/Sum2'
    //
    ParamStep *= static_cast<real32_T>(FLIGHT_hexacopter_B.out_pitch) -
      static_cast<real32_T>(asin(static_cast<real_T>
      ((FLIGHT_hexacopter_B.In1_k.q[1] * FLIGHT_hexacopter_B.In1_k.q[3] -
        FLIGHT_hexacopter_B.In1_k.q[0] * FLIGHT_hexacopter_B.In1_k.q[2]) * -2.0F)));

    // Switch: '<S118>/Switch2' incorporates:
    //   RelationalOperator: '<S118>/LowerRelop1'

    if (ParamStep > rtb_SinCos_o2) {
      // Switch: '<S118>/Switch2'
      FLIGHT_hexacopter_B.Switch2_i = rtb_SinCos_o2;
    } else {
      // Gain: '<S2>/Gain1'
      rtb_SinCos_o2 *= FLIGHT_hexacopter_P.Gain1_Gain;

      // Switch: '<S118>/Switch' incorporates:
      //   RelationalOperator: '<S118>/UpperRelop'

      if (ParamStep < rtb_SinCos_o2) {
        // Switch: '<S118>/Switch2'
        FLIGHT_hexacopter_B.Switch2_i = rtb_SinCos_o2;
      } else {
        // Switch: '<S118>/Switch2'
        FLIGHT_hexacopter_B.Switch2_i = ParamStep;
      }

      // End of Switch: '<S118>/Switch'
    }

    // End of Switch: '<S118>/Switch2'
  }

  // End of Outputs for SubSystem: '<Root>/CAS'

  // BusAssignment: '<S17>/Bus Assignment' incorporates:
  //   Constant: '<S582>/Constant'

  FLIGHT_hexacopter_B.BusAssignment_e = FLIGHT_hexacopter_P.Constant_Value_i;

  // BusAssignment: '<S17>/Bus Assignment' incorporates:
  //   Constant: '<S17>/Constant'
  //   DataTypeConversion: '<S3>/Data Type Conversion9'
  //   MATLABSystem: '<S17>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment_e.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_pnae.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment_e.roll = FLIGHT_hexacopter_B.Switch2;
  FLIGHT_hexacopter_B.BusAssignment_e.pitch = FLIGHT_hexacopter_B.Switch2_i;
  FLIGHT_hexacopter_B.BusAssignment_e.yaw = static_cast<real32_T>
    (rtb_out_yawrate);
  FLIGHT_hexacopter_B.BusAssignment_e.thrust_body[0] =
    FLIGHT_hexacopter_P.Constant_Value_ll;
  FLIGHT_hexacopter_B.BusAssignment_e.thrust_body[1] =
    FLIGHT_hexacopter_P.Constant_Value_ll;
  FLIGHT_hexacopter_B.BusAssignment_e.thrust_body[2] =
    FLIGHT_hexacopter_B.Merge1[3];

  // MATLABSystem: '<S583>/SinkBlock' incorporates:
  //   BusAssignment: '<S17>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_a4.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_a4.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_e);

  // RateTransition: '<Root>/Rate Transition'
  FLIGHT_hexacopter_DW.RateTransition_Buffer0 = FLIGHT_hexacopter_B.Switch2;

  // RateTransition: '<Root>/Rate Transition1'
  FLIGHT_hexacopter_DW.RateTransition1_Buffer0 = FLIGHT_hexacopter_B.Switch2_i;

  // RateTransition: '<Root>/Rate Transition2' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion9'

  FLIGHT_hexacopter_DW.RateTransition2_Buffer0 = static_cast<real32_T>
    (rtb_out_yawrate);

  // RateTransition: '<Root>/Rate Transition3'
  FLIGHT_hexacopter_DW.RateTransition3_Buffer0 = FLIGHT_hexacopter_B.Merge1[3];

  // RateTransition: '<Root>/Rate Transition4'
  FLIGHT_hexacopter_DW.RateTransition4_Buffer0 = FLIGHT_hexacopter_B.values[7];

  // RateTransition: '<Root>/Rate Transition5'
  FLIGHT_hexacopter_DW.RateTransition5_Buffer0 = rtb_Compare;

  // RateTransition: '<Root>/Rate Transition6'
  FLIGHT_hexacopter_DW.RateTransition6_Buffer0 = rtb_Compare;
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
    static const char_T ParameterNameStr_5[17] = "DOUBLET_PEAK_ANG";
    static const char_T ParameterNameStr_6[11] = "DOUBLET_DT";
    static const char_T ParameterNameStr_7[13] = "DOUBLET_AXIS";
    static const char_T ParameterNameStr_8[16] = "MC_ROLLRATE_MAX";
    static const char_T ParameterNameStr_9[10] = "MC_ROLL_P";
    static const char_T ParameterNameStr_a[17] = "MC_PITCHRATE_MAX";
    static const char_T ParameterNameStr_b[11] = "MC_PITCH_P";
    static const char_T ParameterNameStr_c[14] = "MC_ROLLRATE_D";
    static const char_T ParameterNameStr_d[14] = "MC_ROLLRATE_P";
    static const char_T ParameterNameStr_e[14] = "MC_ROLLRATE_I";
    static const char_T ParameterNameStr_f[15] = "MC_PITCHRATE_D";
    static const char_T ParameterNameStr_g[15] = "MC_PITCHRATE_P";
    static const char_T ParameterNameStr_h[15] = "MC_PITCHRATE_I";
    static const char_T ParameterNameStr_i[13] = "MC_YAWRATE_D";
    static const char_T ParameterNameStr_j[13] = "MC_YAWRATE_P";
    static const char_T ParameterNameStr_k[14] = "MC_YAWRATE_FF";
    static const char_T ParameterNameStr_l[13] = "MC_YAWRATE_I";
    static const char_T ParameterNameStr_m[8] = "MPC_Z_P";
    static const char_T ParameterNameStr_n[9] = "MPC_XY_P";
    static const char_T ParameterNameStr_o[17] = "MPC_XY_VEL_P_ACC";
    real_T tmp;
    int32_T i;

    // Start for RateTransition: '<Root>/Rate Transition5'
    FLIGHT_hexacopter_B.RateTransition5 =
      FLIGHT_hexacopter_P.RateTransition5_InitialConditio;

    // Start for RateTransition: '<Root>/Rate Transition'
    FLIGHT_hexacopter_B.RateTransition =
      FLIGHT_hexacopter_P.RateTransition_InitialCondition;

    // Start for RateTransition: '<Root>/Rate Transition1'
    FLIGHT_hexacopter_B.RateTransition1 =
      FLIGHT_hexacopter_P.RateTransition1_InitialConditio;

    // Start for RateTransition: '<Root>/Rate Transition2'
    FLIGHT_hexacopter_B.RateTransition2 =
      FLIGHT_hexacopter_P.RateTransition2_InitialConditio;

    // Start for RateTransition: '<Root>/Rate Transition6'
    FLIGHT_hexacopter_B.RateTransition6 =
      FLIGHT_hexacopter_P.RateTransition6_InitialConditio;

    // Start for RateTransition: '<Root>/Rate Transition3'
    FLIGHT_hexacopter_B.RateTransition3 =
      FLIGHT_hexacopter_P.RateTransition3_InitialConditio;

    // Start for RateTransition: '<Root>/Rate Transition4'
    FLIGHT_hexacopter_B.RateTransition4 =
      FLIGHT_hexacopter_P.RateTransition4_InitialConditio;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition5'
    FLIGHT_hexacopter_DW.RateTransition5_Buffer0 =
      FLIGHT_hexacopter_P.RateTransition5_InitialConditio;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition'
    FLIGHT_hexacopter_DW.RateTransition_Buffer0 =
      FLIGHT_hexacopter_P.RateTransition_InitialCondition;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition1'
    FLIGHT_hexacopter_DW.RateTransition1_Buffer0 =
      FLIGHT_hexacopter_P.RateTransition1_InitialConditio;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition2'
    FLIGHT_hexacopter_DW.RateTransition2_Buffer0 =
      FLIGHT_hexacopter_P.RateTransition2_InitialConditio;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition6'
    FLIGHT_hexacopter_DW.RateTransition6_Buffer0 =
      FLIGHT_hexacopter_P.RateTransition6_InitialConditio;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition3'
    FLIGHT_hexacopter_DW.RateTransition3_Buffer0 =
      FLIGHT_hexacopter_P.RateTransition3_InitialConditio;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition4'
    FLIGHT_hexacopter_DW.RateTransition4_Buffer0 =
      FLIGHT_hexacopter_P.RateTransition4_InitialConditio;

    // SystemInitialize for IfAction SubSystem: '<Root>/Altitude_Mode'
    // SystemInitialize for Enabled SubSystem: '<S1>/Vz Controller'
    // InitializeConditions for DiscreteIntegrator: '<S51>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_i =
      FLIGHT_hexacopter_P.PIDController4_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S56>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_e =
      FLIGHT_hexacopter_P.PIDController4_InitialConditi_a;
    FLIGHT__ReadParameter3_Init(&FLIGHT_hexacopter_DW.ReadParameter3_p);
    FLIGHT__ReadParameter1_Init(&FLIGHT_hexacopter_DW.ReadParameter1_pna);
    FLIGHT_h_ReadParameter_Init(&FLIGHT_hexacopter_DW.ReadParameter_pn);
    FLIGHT__ReadParameter2_Init(&FLIGHT_hexacopter_DW.ReadParameter2_pn);

    // SystemInitialize for Sum: '<S19>/Sum6' incorporates:
    //   Outport: '<S19>/throttle'
    //   Saturate: '<S19>/Saturation1'

    FLIGHT_hexacopter_B.Saturation1_i = FLIGHT_hexacopter_P.throttle_Y0;

    // End of SystemInitialize for SubSystem: '<S1>/Vz Controller'
    // End of SystemInitialize for SubSystem: '<Root>/Altitude_Mode'

    // SystemInitialize for Enabled SubSystem: '<Root>/CAS'
    // Start for MATLABSystem: '<S2>/Read Parameter9'
    FLIGHT_hexacopter_DW.obj_k.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_k.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_k.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_k.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_k.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_8[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_k.isSetupComplete = true;

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
      (&ParameterNameStr_9[0], true, tmp * 1000.0);
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
      (&ParameterNameStr_a[0], true, tmp * 1000.0);
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
      (&ParameterNameStr_b[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Read Parameter1'

    // SystemInitialize for Switch: '<S169>/Switch2' incorporates:
    //   Outport: '<S2>/des_p'

    FLIGHT_hexacopter_B.Switch2 = FLIGHT_hexacopter_P.des_p_Y0;

    // SystemInitialize for Switch: '<S118>/Switch2' incorporates:
    //   Outport: '<S2>/des_q'

    FLIGHT_hexacopter_B.Switch2_i = FLIGHT_hexacopter_P.des_q_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/CAS'

    // SystemInitialize for MATLAB Function: '<S3>/MATLAB Function'
    FLIGHT_hexacopter_DW.start_time_usec = -1.0;

    // SystemInitialize for IfAction SubSystem: '<Root>/If Action Subsystem'
    // SystemInitialize for Enabled SubSystem: '<S5>/Altitude Controller'
    // Start for MATLABSystem: '<S187>/Read Parameter1'
    FLIGHT_hexacopter_DW.obj_m.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_m.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_m.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_m.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_m.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_m.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_m[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S187>/Read Parameter1'
    // End of SystemInitialize for SubSystem: '<S5>/Altitude Controller'

    // SystemInitialize for SignalConversion generated from: '<S5>/des_xy' incorporates:
    //   Constant: '<S5>/Constant'

    FLIGHT_hexacopter_B.OutportBufferFordes_xy[0] =
      FLIGHT_hexacopter_P.Constant_Value_k[0];
    FLIGHT_hexacopter_B.OutportBufferFordes_xy[1] =
      FLIGHT_hexacopter_P.Constant_Value_k[1];

    // SystemInitialize for Enabled SubSystem: '<S5>/Vz Controller'
    // InitializeConditions for DiscreteIntegrator: '<S274>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_g =
      FLIGHT_hexacopter_P.PIDController4_InitialConditi_l;
    FLIGHT_hexacopter_DW.Filter_PrevResetState = 2;

    // InitializeConditions for DiscreteIntegrator: '<S279>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_k =
      FLIGHT_hexacopter_P.PIDController4_InitialConditi_i;
    FLIGHT_hexacopter_DW.Integrator_PrevResetState = 2;
    FLIGHT__ReadParameter3_Init(&FLIGHT_hexacopter_DW.ReadParameter3_pn);
    FLIGHT__ReadParameter1_Init(&FLIGHT_hexacopter_DW.ReadParameter1_pnaev);
    FLIGHT_h_ReadParameter_Init(&FLIGHT_hexacopter_DW.ReadParameter_pna);
    FLIGHT__ReadParameter2_Init(&FLIGHT_hexacopter_DW.ReadParameter2_pna);

    // SystemInitialize for Sum: '<S189>/Sum6' incorporates:
    //   Outport: '<S189>/throttle'
    //   Saturate: '<S189>/Saturation1'

    FLIGHT_hexacopter_B.Saturation1 = FLIGHT_hexacopter_P.throttle_Y0_o;

    // SystemInitialize for Product: '<S231>/PProd Out' incorporates:
    //   Outport: '<S189>/log_alt'
    //   SignalConversion generated from: '<S189>/des_vz'

    FLIGHT_hexacopter_B.des_vz = FLIGHT_hexacopter_P.log_alt_Y0;

    // End of SystemInitialize for SubSystem: '<S5>/Vz Controller'

    // SystemInitialize for Enabled SubSystem: '<S5>/XY Pos Controller'
    // Start for MATLABSystem: '<S190>/Read Parameter'
    FLIGHT_hexacopter_DW.obj_eq.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_eq.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_eq.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_eq.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_eq.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_eq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_n[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_eq.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S190>/Read Parameter'

    // SystemInitialize for Product: '<S335>/PProd Out' incorporates:
    //   Outport: '<S190>/des_vxvy'

    FLIGHT_hexacopter_B.PProdOut[0] = FLIGHT_hexacopter_P.des_vxvy_Y0;
    FLIGHT_hexacopter_B.PProdOut[1] = FLIGHT_hexacopter_P.des_vxvy_Y0;

    // End of SystemInitialize for SubSystem: '<S5>/XY Pos Controller'

    // SystemInitialize for Enabled SubSystem: '<S5>/XY Velocity Controller'
    // Start for MATLABSystem: '<S191>/Read Parameter'
    FLIGHT_hexacopter_DW.obj_pi.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_pi.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_pi.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_pi.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_pi.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_pi.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_o[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_pi.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S191>/Read Parameter'

    // SystemInitialize for Gain: '<S191>/Gain1' incorporates:
    //   Outport: '<S191>/des_pitch'

    FLIGHT_hexacopter_B.Gain1 = FLIGHT_hexacopter_P.des_pitch_Y0;

    // SystemInitialize for Outport: '<S191>/des_roll' incorporates:
    //   Saturate: '<S191>/Saturation'

    FLIGHT_hexacopter_B.Saturation[1] = FLIGHT_hexacopter_P.des_roll_Y0;

    // End of SystemInitialize for SubSystem: '<S5>/XY Velocity Controller'

    // SystemInitialize for Sum: '<S5>/Add' incorporates:
    //   Outport: '<S5>/des_z'

    FLIGHT_hexacopter_B.Add = FLIGHT_hexacopter_P.des_z_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem'

    // SystemInitialize for Gain: '<S18>/Gain' incorporates:
    //   Merge: '<Root>/Merge'

    FLIGHT_hexacopter_B.Merge = FLIGHT_hexacopter_P.Merge_InitialOutput;

    // SystemInitialize for Merge: '<Root>/Merge1'
    FLIGHT_hexacopter_B.Merge1[0] = FLIGHT_hexacopter_P.Merge1_InitialOutput;
    FLIGHT_hexacopter_B.Merge1[1] = FLIGHT_hexacopter_P.Merge1_InitialOutput;
    FLIGHT_hexacopter_B.Merge1[2] = FLIGHT_hexacopter_P.Merge1_InitialOutput;
    FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_P.Merge1_InitialOutput;

    // SystemInitialize for Enabled SubSystem: '<Root>/Mixer'
    for (i = 0; i < 6; i++) {
      // SystemInitialize for Saturate: '<S6>/Output_Limits1' incorporates:
      //   Outport: '<S6>/PWM'

      FLIGHT_hexacopter_B.Output_Limits1[i] = FLIGHT_hexacopter_P.PWM_Y0;
    }

    // End of SystemInitialize for SubSystem: '<Root>/Mixer'

    // SystemInitialize for Enabled SubSystem: '<S401>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S403>/In1' incorporates:
    //   Outport: '<S403>/Out1'

    FLIGHT_hexacopter_B.In1 = FLIGHT_hexacopter_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S401>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S404>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S405>/In1' incorporates:
    //   Outport: '<S405>/Out1'

    FLIGHT_hexacopter_B.In1_k = FLIGHT_hexacopter_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S404>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S410>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S411>/In1' incorporates:
    //   Outport: '<S411>/Out1'

    FLIGHT_hexacopter_B.In1_n = FLIGHT_hexacopter_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S410>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<Root>/SAS'
    // InitializeConditions for DiscreteIntegrator: '<S493>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE =
      FLIGHT_hexacopter_P.pid_ctrl_rollrate_InitialCondit;

    // InitializeConditions for DiscreteIntegrator: '<S498>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE =
      FLIGHT_hexacopter_P.pid_ctrl_rollrate_InitialCond_c;

    // InitializeConditions for DiscreteIntegrator: '<S443>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_j =
      FLIGHT_hexacopter_P.pid_ctrl_pitchrate_InitialCondi;

    // InitializeConditions for DiscreteIntegrator: '<S448>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_c =
      FLIGHT_hexacopter_P.pid_ctrl_pitchrate_InitialCon_c;

    // InitializeConditions for DiscreteIntegrator: '<S543>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_h =
      FLIGHT_hexacopter_P.pid_ctrl_yawrate_InitialConditi;

    // InitializeConditions for DiscreteIntegrator: '<S548>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_l =
      FLIGHT_hexacopter_P.pid_ctrl_yawrate_InitialCondi_h;

    // Start for MATLABSystem: '<S9>/Read Parameter2'
    FLIGHT_hexacopter_DW.obj_d.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_d.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_d.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_d.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_d.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_c[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter2'

    // Start for MATLABSystem: '<S9>/read_mc_rollrate_p'
    FLIGHT_hexacopter_DW.obj.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_d
      [0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/read_mc_rollrate_p'

    // Start for MATLABSystem: '<S9>/Read Parameter1'
    FLIGHT_hexacopter_DW.obj_ea.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_ea.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_ea.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_ea.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_ea.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_ea.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_e[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_ea.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter1'

    // Start for MATLABSystem: '<S9>/Read Parameter5'
    FLIGHT_hexacopter_DW.obj_h.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_h.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_h.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_h.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_h.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_h.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_f[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter5'

    // Start for MATLABSystem: '<S9>/Read Parameter3'
    FLIGHT_hexacopter_DW.obj_b.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_b.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_b.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_b.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_b.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_g[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter3'

    // Start for MATLABSystem: '<S9>/Read Parameter4'
    FLIGHT_hexacopter_DW.obj_p.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_p.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_p.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_p.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_p.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_h[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter4'

    // Start for MATLABSystem: '<S9>/Read Parameter8'
    FLIGHT_hexacopter_DW.obj_i.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_i.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_i.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_i.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_i.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_i.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_i[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_i.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter8'

    // Start for MATLABSystem: '<S9>/Read Parameter6'
    FLIGHT_hexacopter_DW.obj_a.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_a.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_a.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_a.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_a.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_j[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter6'

    // Start for MATLABSystem: '<S9>/Read Parameter9'
    FLIGHT_hexacopter_DW.obj_e.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_e.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_e.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_e.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_e.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_e.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_k[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter9'

    // Start for MATLABSystem: '<S9>/Read Parameter7'
    FLIGHT_hexacopter_DW.obj_j.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_j.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_j.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_j.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_j.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_j.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_l[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter7'

    // SystemInitialize for Sum: '<S507>/Sum' incorporates:
    //   Outport: '<S9>/tau_roll'

    FLIGHT_hexacopter_B.Sum = FLIGHT_hexacopter_P.tau_roll_Y0;

    // SystemInitialize for Sum: '<S457>/Sum' incorporates:
    //   Outport: '<S9>/tau_pitch'

    FLIGHT_hexacopter_B.Sum_a = FLIGHT_hexacopter_P.tau_pitch_Y0;

    // SystemInitialize for Sum: '<S9>/Sum2' incorporates:
    //   Outport: '<S9>/tau_yaw'

    FLIGHT_hexacopter_B.Sum2 = FLIGHT_hexacopter_P.tau_yaw_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/SAS'

    // SystemInitialize for Enabled SubSystem: '<S575>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S576>/In1' incorporates:
    //   Outport: '<S576>/Out1'

    FLIGHT_hexacopter_B.In1_h = FLIGHT_hexacopter_P.Out1_Y0_pn;

    // End of SystemInitialize for SubSystem: '<S575>/Enabled Subsystem'

    // Start for MATLABSystem: '<S575>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_pe.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_pe.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_pe.orbMetadataObj = ORB_ID(vehicle_angular_velocity);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_pe.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_pe.eventStructObj);
    FLIGHT_hexacopter_DW.obj_pe.isSetupComplete = true;

    // Start for MATLABSystem: '<S4>/Read Parameter13'
    FLIGHT_hexacopter_DW.obj_g.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_g.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_g.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_g.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_g.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr
      [0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_g.isSetupComplete = true;

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
    FLIGHT_hexacopter_DW.obj_n.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_n.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_n.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_n.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_n.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_n.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter3'

    // Start for MATLABSystem: '<S4>/Read Parameter4'
    FLIGHT_hexacopter_DW.obj_c.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_c.SampleTime = FLIGHT_hexacopter_P.SampleTime_SAS;
    FLIGHT_hexacopter_DW.obj_c.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_c.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_c.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_c.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_c.isSetupComplete = true;

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
    FLIGHT__PX4Timestamp_b_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_o);

    // Start for MATLABSystem: '<S567>/SinkBlock' incorporates:
    //   BusAssignment: '<S565>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_jk.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_jk.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_jk.orbMetadataObj = ORB_ID
      (actuator_controls_status_0);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_jk.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_jk.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_gi, 1);
    FLIGHT_hexacopter_DW.obj_jk.isSetupComplete = true;
    FLIGHT__PX4Timestamp_b_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_n);
    FLIGHT__PX4Timestamp_b_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_p);

    // Start for MATLABSystem: '<S572>/SinkBlock' incorporates:
    //   BusAssignment: '<S569>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_hf.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_hf.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_hf.orbMetadataObj = ORB_ID(actuator_motors);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_hf.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_hf.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_f, 1);
    FLIGHT_hexacopter_DW.obj_hf.isSetupComplete = true;
    FLIGHT__PX4Timestamp_b_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_ok);

    // Start for MATLABSystem: '<S574>/SinkBlock' incorporates:
    //   BusAssignment: '<S570>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_px.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_px.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_px.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_px.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_px.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment, 1);
    FLIGHT_hexacopter_DW.obj_px.isSetupComplete = true;
    FLIGHT__PX4Timestamp_l_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_pn);

    // Start for MATLABSystem: '<S410>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_p2.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_p2.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_p2.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_p2.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_p2.eventStructObj);
    FLIGHT_hexacopter_DW.obj_p2.isSetupComplete = true;

    // Start for MATLABSystem: '<S401>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_kk.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_kk.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_kk.orbMetadataObj = ORB_ID(vehicle_local_position);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_kk.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_kk.eventStructObj);
    FLIGHT_hexacopter_DW.obj_kk.isSetupComplete = true;
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
      (&ParameterNameStr_5[0], true, tmp * 1000.0);
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
      (&ParameterNameStr_6[0], true, tmp * 1000.0);
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
      (&ParameterNameStr_7[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/Read Parameter2'

    // Start for MATLABSystem: '<S578>/SinkBlock' incorporates:
    //   BusAssignment: '<S15>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_pt.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_pt.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_pt.orbMetadataObj = ORB_ID
      (vehicle_attitude_setpoint);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_pt.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_pt.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_d, 1);
    FLIGHT_hexacopter_DW.obj_pt.isSetupComplete = true;
    FLIGHT_he_PX4Timestamp_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_pna);

    // Start for MATLABSystem: '<S581>/SinkBlock' incorporates:
    //   BusAssignment: '<S16>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_pa.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_pa.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_pa.orbMetadataObj = ORB_ID
      (vehicle_local_position_setpoint);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_pa.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_pa.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_g, 1);
    FLIGHT_hexacopter_DW.obj_pa.isSetupComplete = true;
    FLIGHT__PX4Timestamp_l_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_pnae);

    // Start for MATLABSystem: '<S404>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_ab.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_ab.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_ab.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_ab.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_ab.eventStructObj);
    FLIGHT_hexacopter_DW.obj_ab.isSetupComplete = true;

    // Start for MATLABSystem: '<S583>/SinkBlock' incorporates:
    //   BusAssignment: '<S17>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_a4.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_a4.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_a4.orbMetadataObj = ORB_ID(vehicle_rates_setpoint);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_a4.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_a4.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_e, 1);
    FLIGHT_hexacopter_DW.obj_a4.isSetupComplete = true;
  }
}

// Model terminate function
void FLIGHT_hexacopter_terminate(void)
{
  // Terminate for MATLABSystem: '<S575>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_pe.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_pe.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_pe.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_pe.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_pe.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S575>/SourceBlock'

  // Terminate for Enabled SubSystem: '<Root>/SAS'
  // Terminate for MATLABSystem: '<S9>/Read Parameter2'
  if (!FLIGHT_hexacopter_DW.obj_d.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter2'

  // Terminate for MATLABSystem: '<S9>/read_mc_rollrate_p'
  if (!FLIGHT_hexacopter_DW.obj.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/read_mc_rollrate_p'

  // Terminate for MATLABSystem: '<S9>/Read Parameter1'
  if (!FLIGHT_hexacopter_DW.obj_ea.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_ea.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter1'

  // Terminate for MATLABSystem: '<S9>/Read Parameter5'
  if (!FLIGHT_hexacopter_DW.obj_h.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter5'

  // Terminate for MATLABSystem: '<S9>/Read Parameter3'
  if (!FLIGHT_hexacopter_DW.obj_b.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter3'

  // Terminate for MATLABSystem: '<S9>/Read Parameter4'
  if (!FLIGHT_hexacopter_DW.obj_p.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter4'

  // Terminate for MATLABSystem: '<S9>/Read Parameter8'
  if (!FLIGHT_hexacopter_DW.obj_i.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter8'

  // Terminate for MATLABSystem: '<S9>/Read Parameter6'
  if (!FLIGHT_hexacopter_DW.obj_a.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter6'

  // Terminate for MATLABSystem: '<S9>/Read Parameter9'
  if (!FLIGHT_hexacopter_DW.obj_e.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter9'

  // Terminate for MATLABSystem: '<S9>/Read Parameter7'
  if (!FLIGHT_hexacopter_DW.obj_j.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter7'
  // End of Terminate for SubSystem: '<Root>/SAS'

  // Terminate for MATLABSystem: '<S4>/Read Parameter13'
  if (!FLIGHT_hexacopter_DW.obj_g.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_g.matlabCodegenIsDeleted = true;
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
  if (!FLIGHT_hexacopter_DW.obj_n.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter3'

  // Terminate for MATLABSystem: '<S4>/Read Parameter4'
  if (!FLIGHT_hexacopter_DW.obj_c.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_c.matlabCodegenIsDeleted = true;
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
  FLIGHT__PX4Timestamp_o_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_o);

  // Terminate for MATLABSystem: '<S567>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_jk.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_jk.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_jk.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_jk.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_jk.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S567>/SinkBlock'
  FLIGHT__PX4Timestamp_o_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_n);
  FLIGHT__PX4Timestamp_o_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_p);

  // Terminate for MATLABSystem: '<S572>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_hf.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_hf.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_hf.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_hf.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_hf.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S572>/SinkBlock'
  FLIGHT__PX4Timestamp_o_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_ok);

  // Terminate for MATLABSystem: '<S574>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_px.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_px.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_px.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_px.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_px.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S574>/SinkBlock'
  FLIGHT__PX4Timestamp_b_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_pn);

  // Terminate for MATLABSystem: '<S410>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_p2.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_p2.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_p2.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_p2.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_p2.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S410>/SourceBlock'

  // Terminate for MATLABSystem: '<S401>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_kk.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_kk.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_kk.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_kk.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_kk.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S401>/SourceBlock'

  // Terminate for IfAction SubSystem: '<Root>/Altitude_Mode'
  // Terminate for Enabled SubSystem: '<S1>/Vz Controller'
  FLIGHT__ReadParameter3_Term(&FLIGHT_hexacopter_DW.ReadParameter3_p);
  FLIGHT__ReadParameter1_Term(&FLIGHT_hexacopter_DW.ReadParameter1_pna);
  FLIGHT_h_ReadParameter_Term(&FLIGHT_hexacopter_DW.ReadParameter_pn);
  FLIGHT__ReadParameter2_Term(&FLIGHT_hexacopter_DW.ReadParameter2_pn);

  // End of Terminate for SubSystem: '<S1>/Vz Controller'
  // End of Terminate for SubSystem: '<Root>/Altitude_Mode'

  // Terminate for IfAction SubSystem: '<Root>/If Action Subsystem'
  // Terminate for Enabled SubSystem: '<S5>/XY Pos Controller'
  // Terminate for MATLABSystem: '<S190>/Read Parameter'
  if (!FLIGHT_hexacopter_DW.obj_eq.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_eq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S190>/Read Parameter'
  // End of Terminate for SubSystem: '<S5>/XY Pos Controller'

  // Terminate for Enabled SubSystem: '<S5>/XY Velocity Controller'
  // Terminate for MATLABSystem: '<S191>/Read Parameter'
  if (!FLIGHT_hexacopter_DW.obj_pi.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_pi.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S191>/Read Parameter'
  // End of Terminate for SubSystem: '<S5>/XY Velocity Controller'

  // Terminate for Enabled SubSystem: '<S5>/Altitude Controller'
  // Terminate for MATLABSystem: '<S187>/Read Parameter1'
  if (!FLIGHT_hexacopter_DW.obj_m.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S187>/Read Parameter1'
  // End of Terminate for SubSystem: '<S5>/Altitude Controller'

  // Terminate for Enabled SubSystem: '<S5>/Vz Controller'
  FLIGHT__ReadParameter3_Term(&FLIGHT_hexacopter_DW.ReadParameter3_pn);
  FLIGHT__ReadParameter1_Term(&FLIGHT_hexacopter_DW.ReadParameter1_pnaev);
  FLIGHT_h_ReadParameter_Term(&FLIGHT_hexacopter_DW.ReadParameter_pna);
  FLIGHT__ReadParameter2_Term(&FLIGHT_hexacopter_DW.ReadParameter2_pna);

  // End of Terminate for SubSystem: '<S5>/Vz Controller'
  // End of Terminate for SubSystem: '<Root>/If Action Subsystem'
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

  // Terminate for MATLABSystem: '<S578>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_pt.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_pt.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_pt.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_pt.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_pt.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S578>/SinkBlock'
  FLIGHT_he_PX4Timestamp_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_pna);

  // Terminate for MATLABSystem: '<S581>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_pa.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_pa.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_pa.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_pa.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_pa.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S581>/SinkBlock'
  FLIGHT__PX4Timestamp_b_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_pnae);

  // Terminate for MATLABSystem: '<S404>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_ab.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_ab.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_ab.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_ab.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_ab.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S404>/SourceBlock'

  // Terminate for Enabled SubSystem: '<Root>/CAS'
  // Terminate for MATLABSystem: '<S2>/Read Parameter9'
  if (!FLIGHT_hexacopter_DW.obj_k.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_k.matlabCodegenIsDeleted = true;
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

  // Terminate for MATLABSystem: '<S583>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_a4.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_a4.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_a4.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_a4.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_a4.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S583>/SinkBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
