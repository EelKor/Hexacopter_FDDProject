//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Mixer_FaultInjection_types.h
//
// Code generated for Simulink model 'Mixer_FaultInjection'.
//
// Model version                  : 4.142
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Aug 23 16:15:46 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Mixer_FaultInjection_types_h_
#define RTW_HEADER_Mixer_FaultInjection_types_h_
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include <uORB/topics/actuator_controls.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/actuator_outputs.h>

// Custom Type definition for MATLABSystem: '<S2>/Read Parameter4'
#include "MW_Parameter.h"
#ifndef struct_px4_internal_block_ParameterUpdate_Mixer_FaultInjection_T
#define struct_px4_internal_block_ParameterUpdate_Mixer_FaultInjection_T

struct px4_internal_block_ParameterUpdate_Mixer_FaultInjection_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  MW_Param_Handle MW_PARAMHANDLE;
};

#endif      // struct_px4_internal_block_ParameterUpdate_Mixer_FaultInjection_T

#ifndef struct_b_px4_internal_block_SampleTimeImpl_Mixer_FaultInjection_T
#define struct_b_px4_internal_block_SampleTimeImpl_Mixer_FaultInjection_T

struct b_px4_internal_block_SampleTimeImpl_Mixer_FaultInjection_T
{
  int32_T __dummy;
};

#endif     // struct_b_px4_internal_block_SampleTimeImpl_Mixer_FaultInjection_T

#ifndef struct_px4_internal_block_Subscriber_Mixer_FaultInjection_T
#define struct_px4_internal_block_Subscriber_Mixer_FaultInjection_T

struct px4_internal_block_Subscriber_Mixer_FaultInjection_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_px4_internal_block_SampleTimeImpl_Mixer_FaultInjection_T SampleTimeHandler;
  pollfd_t eventStructObj;
  orb_metadata_t * orbMetadataObj;
};

#endif           // struct_px4_internal_block_Subscriber_Mixer_FaultInjection_T

#ifndef struct_px4_internal_block_Publisher_Mixer_FaultInjection_T
#define struct_px4_internal_block_Publisher_Mixer_FaultInjection_T

struct px4_internal_block_Publisher_Mixer_FaultInjection_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  orb_advert_t orbAdvertiseObj;
  orb_metadata_t * orbMetadataObj;
};

#endif            // struct_px4_internal_block_Publisher_Mixer_FaultInjection_T

// Parameters for system: '<S2>/CalcFaultInjectedPWM1'
typedef struct P_calcFaultInjectedPWM_T_ P_calcFaultInjectedPWM_T;

// Parameters (default storage)
typedef struct P_Mixer_FaultInjection_T_ P_Mixer_FaultInjection_T;

// Forward declaration for rtModel
typedef struct tag_RTM_Mixer_FaultInjection_T RT_MODEL_Mixer_FaultInjection_T;

#endif                              // RTW_HEADER_Mixer_FaultInjection_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
