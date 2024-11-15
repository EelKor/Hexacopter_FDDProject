//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: HITL_HEXA_WOPOSCTRL_types.h
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
#ifndef RTW_HEADER_HITL_HEXA_WOPOSCTRL_types_h_
#define RTW_HEADER_HITL_HEXA_WOPOSCTRL_types_h_
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include <uORB/topics/input_rc.h>
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/vehicle_rates_setpoint.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_attitude_setpoint.h>

// Custom Type definition for MATLABSystem: '<S26>/Read Parameter9'
#include "MW_Parameter.h"
#ifndef struct_px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T
#define struct_px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T

struct px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  MW_Param_Handle MW_PARAMHANDLE;
};

#endif       // struct_px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T

#ifndef struct_b_px4_internal_block_SampleTimeImpl_HITL_HEXA_WOPOSCTRL_T
#define struct_b_px4_internal_block_SampleTimeImpl_HITL_HEXA_WOPOSCTRL_T

struct b_px4_internal_block_SampleTimeImpl_HITL_HEXA_WOPOSCTRL_T
{
  int32_T __dummy;
};

#endif      // struct_b_px4_internal_block_SampleTimeImpl_HITL_HEXA_WOPOSCTRL_T

#ifndef struct_px4_internal_block_Subscriber_HITL_HEXA_WOPOSCTRL_T
#define struct_px4_internal_block_Subscriber_HITL_HEXA_WOPOSCTRL_T

struct px4_internal_block_Subscriber_HITL_HEXA_WOPOSCTRL_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_px4_internal_block_SampleTimeImpl_HITL_HEXA_WOPOSCTRL_T SampleTimeHandler;
  pollfd_t eventStructObj;
  orb_metadata_t * orbMetadataObj;
};

#endif            // struct_px4_internal_block_Subscriber_HITL_HEXA_WOPOSCTRL_T

#ifndef struct_px4_internal_block_Publisher_HITL_HEXA_WOPOSCTRL_T
#define struct_px4_internal_block_Publisher_HITL_HEXA_WOPOSCTRL_T

struct px4_internal_block_Publisher_HITL_HEXA_WOPOSCTRL_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  orb_advert_t orbAdvertiseObj;
  orb_metadata_t * orbMetadataObj;
};

#endif             // struct_px4_internal_block_Publisher_HITL_HEXA_WOPOSCTRL_T

#ifndef struct_px4_internal_block_getPX4AbsoluteTime_HITL_HEXA_WOPOSCTRL_T
#define struct_px4_internal_block_getPX4AbsoluteTime_HITL_HEXA_WOPOSCTRL_T

struct px4_internal_block_getPX4AbsoluteTime_HITL_HEXA_WOPOSCTRL_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_px4_internal_block_SampleTimeImpl_HITL_HEXA_WOPOSCTRL_T SampleTimeHandler;
};

#endif    // struct_px4_internal_block_getPX4AbsoluteTime_HITL_HEXA_WOPOSCTRL_T

// Parameters (default storage)
typedef struct P_HITL_HEXA_WOPOSCTRL_T_ P_HITL_HEXA_WOPOSCTRL_T;

// Forward declaration for rtModel
typedef struct tag_RTM_HITL_HEXA_WOPOSCTRL_T RT_MODEL_HITL_HEXA_WOPOSCTRL_T;

#endif                               // RTW_HEADER_HITL_HEXA_WOPOSCTRL_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
