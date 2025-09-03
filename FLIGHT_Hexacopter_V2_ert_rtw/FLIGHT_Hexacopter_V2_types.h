//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_Hexacopter_V2_types.h
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
#ifndef FLIGHT_Hexacopter_V2_types_h_
#define FLIGHT_Hexacopter_V2_types_h_
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include <uORB/topics/actuator_controls_status.h>
#include <uORB/topics/vehicle_attitude_setpoint.h>
#include <uORB/topics/vehicle_rates_setpoint.h>
#include <uORB/topics/vehicle_attitude_smc_setpoint.h>
#include <uORB/topics/actuator_motors.h>
#include <uORB/topics/vehicle_local_position_setpoint.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/vehicle_status.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_odometry.h>
#ifndef struct_d_px4_internal_block_SampleTi_T
#define struct_d_px4_internal_block_SampleTi_T

struct d_px4_internal_block_SampleTi_T
{
  int32_T __dummy;
};

#endif                                // struct_d_px4_internal_block_SampleTi_T

#ifndef struct_px4_internal_block_getPX4Abso_T
#define struct_px4_internal_block_getPX4Abso_T

struct px4_internal_block_getPX4Abso_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_px4_internal_block_SampleTi_T SampleTimeHandler;
};

#endif                                // struct_px4_internal_block_getPX4Abso_T

#ifndef struct_px4_internal_block_Subscriber_T
#define struct_px4_internal_block_Subscriber_T

struct px4_internal_block_Subscriber_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_px4_internal_block_SampleTi_T SampleTimeHandler;
  pollfd_t eventStructObj;
  orb_metadata_t * orbMetadataObj;
};

#endif                                // struct_px4_internal_block_Subscriber_T

#ifndef struct_px4_internal_block_PWM_FLIGHT_T
#define struct_px4_internal_block_PWM_FLIGHT_T

struct px4_internal_block_PWM_FLIGHT_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  unsigned int servoCount;
  int channelMask;
  boolean_T isMain;
  orb_advert_t armAdvertiseObj;
  orb_advert_t actuatorAdvertiseObj;
  boolean_T isArmed;
};

#endif                                // struct_px4_internal_block_PWM_FLIGHT_T

// Custom Type definition for MATLABSystem: ''read_mc_rollrate_p' (':246')'
#include "MW_Parameter.h"
#ifndef struct_px4_internal_block_ParameterU_T
#define struct_px4_internal_block_ParameterU_T

struct px4_internal_block_ParameterU_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Param_Handle MW_PARAMHANDLE;
};

#endif                                // struct_px4_internal_block_ParameterU_T

#ifndef struct_px4_internal_block_Publisher__T
#define struct_px4_internal_block_Publisher__T

struct px4_internal_block_Publisher__T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  orb_advert_t orbAdvertiseObj;
  orb_metadata_t * orbMetadataObj;
};

#endif                                // struct_px4_internal_block_Publisher__T

// Parameters (default storage)
typedef struct P_FLIGHT_Hexacopter_V2_T_ P_FLIGHT_Hexacopter_V2_T;

// Forward declaration for rtModel
typedef struct tag_RTM_FLIGHT_Hexacopter_V2_T RT_MODEL_FLIGHT_Hexacopter_V2_T;

#endif                                 // FLIGHT_Hexacopter_V2_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
