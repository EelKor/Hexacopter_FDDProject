//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: SITL_HEXA_Hovering_types.h
//
// Code generated for Simulink model 'SITL_HEXA_Hovering'.
//
// Model version                  : 5.7
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Oct 16 15:41:08 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef SITL_HEXA_Hovering_types_h_
#define SITL_HEXA_Hovering_types_h_
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include <uORB/topics/vehicle_attitude_setpoint.h>
#include <uORB/topics/vehicle_local_position_setpoint.h>
#include <uORB/topics/vehicle_rates_setpoint.h>
#include <uORB/topics/trajectory_waypoint.h>
#include <uORB/topics/vehicle_trajectory_waypoint.h>
#include <uORB/topics/home_position.h>
#include <uORB/topics/position_setpoint.h>
#include <uORB/topics/position_setpoint_triplet.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/actuator_motors.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_local_position.h>
#ifndef struct_b_px4_internal_block_SampleTimeImpl_SITL_HEXA_Hovering_T
#define struct_b_px4_internal_block_SampleTimeImpl_SITL_HEXA_Hovering_T

struct b_px4_internal_block_SampleTimeImpl_SITL_HEXA_Hovering_T
{
  int32_T __dummy;
};

#endif       // struct_b_px4_internal_block_SampleTimeImpl_SITL_HEXA_Hovering_T

#ifndef struct_px4_internal_block_getPX4AbsoluteTime_SITL_HEXA_Hovering_T
#define struct_px4_internal_block_getPX4AbsoluteTime_SITL_HEXA_Hovering_T

struct px4_internal_block_getPX4AbsoluteTime_SITL_HEXA_Hovering_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_px4_internal_block_SampleTimeImpl_SITL_HEXA_Hovering_T SampleTimeHandler;
};

#endif     // struct_px4_internal_block_getPX4AbsoluteTime_SITL_HEXA_Hovering_T

#ifndef struct_px4_internal_block_Publisher_SITL_HEXA_Hovering_T
#define struct_px4_internal_block_Publisher_SITL_HEXA_Hovering_T

struct px4_internal_block_Publisher_SITL_HEXA_Hovering_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  orb_advert_t orbAdvertiseObj;
  orb_metadata_t * orbMetadataObj;
};

#endif              // struct_px4_internal_block_Publisher_SITL_HEXA_Hovering_T

#ifndef struct_px4_internal_block_LLA2LocalCoordinatesNED_SITL_HEXA_Hovering_T
#define struct_px4_internal_block_LLA2LocalCoordinatesNED_SITL_HEXA_Hovering_T

struct px4_internal_block_LLA2LocalCoordinatesNED_SITL_HEXA_Hovering_T
{
  boolean_T matlabCodegenIsDeleted;
  boolean_T isSetupComplete;
};

#endif
      // struct_px4_internal_block_LLA2LocalCoordinatesNED_SITL_HEXA_Hovering_T

#ifndef struct_px4_internal_block_LLA2LocalCoordinates_SITL_HEXA_Hovering_T
#define struct_px4_internal_block_LLA2LocalCoordinates_SITL_HEXA_Hovering_T

struct px4_internal_block_LLA2LocalCoordinates_SITL_HEXA_Hovering_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T previousValidReceived;
  boolean_T nextValidReceived;
};

#endif   // struct_px4_internal_block_LLA2LocalCoordinates_SITL_HEXA_Hovering_T

// Custom Type definition for MATLABSystem: '<S586>/Read Parameter'
#include "MW_Parameter.h"
#ifndef struct_px4_internal_block_ParameterUpdate_SITL_HEXA_Hovering_T
#define struct_px4_internal_block_ParameterUpdate_SITL_HEXA_Hovering_T

struct px4_internal_block_ParameterUpdate_SITL_HEXA_Hovering_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  MW_Param_Handle MW_PARAMHANDLE;
};

#endif        // struct_px4_internal_block_ParameterUpdate_SITL_HEXA_Hovering_T

#ifndef struct_cell_wrap_SITL_HEXA_Hovering_T
#define struct_cell_wrap_SITL_HEXA_Hovering_T

struct cell_wrap_SITL_HEXA_Hovering_T
{
  uint32_T f1[8];
};

#endif                                 // struct_cell_wrap_SITL_HEXA_Hovering_T

#ifndef struct_uav_sluav_internal_system_WaypointFollower_SITL_HEXA_Hovering_T
#define struct_uav_sluav_internal_system_WaypointFollower_SITL_HEXA_Hovering_T

struct uav_sluav_internal_system_WaypointFollower_SITL_HEXA_Hovering_T
{
  int32_T isInitialized;
  cell_wrap_SITL_HEXA_Hovering_T inputVarSize[3];
  real_T LookaheadDistance;
  real_T WaypointIndex;
  real_T NumWaypoints;
  real_T WaypointsInternal[9];
  boolean_T LastWaypointFlag;
  boolean_T StartFlag;
  real_T InitialPose[4];
  real_T LookaheadFactor;
  uint8_T LookaheadDistFlag;
};

#endif
      // struct_uav_sluav_internal_system_WaypointFollower_SITL_HEXA_Hovering_T

#ifndef struct_px4_internal_block_Subscriber_SITL_HEXA_Hovering_T
#define struct_px4_internal_block_Subscriber_SITL_HEXA_Hovering_T

struct px4_internal_block_Subscriber_SITL_HEXA_Hovering_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_px4_internal_block_SampleTimeImpl_SITL_HEXA_Hovering_T SampleTimeHandler;
  pollfd_t eventStructObj;
  orb_metadata_t * orbMetadataObj;
};

#endif             // struct_px4_internal_block_Subscriber_SITL_HEXA_Hovering_T

// Parameters (default storage)
typedef struct P_SITL_HEXA_Hovering_T_ P_SITL_HEXA_Hovering_T;

// Forward declaration for rtModel
typedef struct tag_RTM_SITL_HEXA_Hovering_T RT_MODEL_SITL_HEXA_Hovering_T;

#endif                                 // SITL_HEXA_Hovering_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
