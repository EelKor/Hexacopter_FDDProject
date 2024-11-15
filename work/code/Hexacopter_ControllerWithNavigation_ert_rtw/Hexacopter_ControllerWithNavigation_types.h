//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Hexacopter_ControllerWithNavigation_types.h
//
// Code generated for Simulink model 'Hexacopter_ControllerWithNavigation'.
//
// Model version                  : 5.23
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Fri Jul 26 16:40:34 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef Hexacopter_ControllerWithNavigation_types_h_
#define Hexacopter_ControllerWithNavigation_types_h_
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/trajectory_waypoint.h>
#include <uORB/topics/vehicle_trajectory_waypoint.h>
#include <uORB/topics/home_position.h>
#include <uORB/topics/position_setpoint.h>
#include <uORB/topics/position_setpoint_triplet.h>
#ifndef struct_px4_internal_block_LLA2LocalCoordinatesNED_Hexacopter_Control_T
#define struct_px4_internal_block_LLA2LocalCoordinatesNED_Hexacopter_Control_T

struct px4_internal_block_LLA2LocalCoordinatesNED_Hexacopter_Control_T
{
  boolean_T matlabCodegenIsDeleted;
  boolean_T isSetupComplete;
};

#endif
      // struct_px4_internal_block_LLA2LocalCoordinatesNED_Hexacopter_Control_T

// Custom Type definition for MATLABSystem: '<S59>/Read Parameter'
#include "MW_Parameter.h"
#ifndef struct_px4_internal_block_ParameterUpdate_Hexacopter_ControllerWithN_T
#define struct_px4_internal_block_ParameterUpdate_Hexacopter_ControllerWithN_T

struct px4_internal_block_ParameterUpdate_Hexacopter_ControllerWithN_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  MW_Param_Handle MW_PARAMHANDLE;
};

#endif
      // struct_px4_internal_block_ParameterUpdate_Hexacopter_ControllerWithN_T

#ifndef struct_px4_internal_block_PWM_Hexacopter_ControllerWithNavigation_T
#define struct_px4_internal_block_PWM_Hexacopter_ControllerWithNavigation_T

struct px4_internal_block_PWM_Hexacopter_ControllerWithNavigation_T
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

#endif   // struct_px4_internal_block_PWM_Hexacopter_ControllerWithNavigation_T

#ifndef struct_b_px4_internal_block_SampleTimeImpl_Hexacopter_ControllerWith_T
#define struct_b_px4_internal_block_SampleTimeImpl_Hexacopter_ControllerWith_T

struct b_px4_internal_block_SampleTimeImpl_Hexacopter_ControllerWith_T
{
  int32_T __dummy;
};

#endif
      // struct_b_px4_internal_block_SampleTimeImpl_Hexacopter_ControllerWith_T

#ifndef struct_px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T
#define struct_px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T

struct px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_px4_internal_block_SampleTimeImpl_Hexacopter_ControllerWith_T
    SampleTimeHandler;
  pollfd_t eventStructObj;
  orb_metadata_t * orbMetadataObj;
};

#endif
      // struct_px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T

#ifndef struct_px4_internal_block_LLA2LocalCoordinates_Hexacopter_Controller_T
#define struct_px4_internal_block_LLA2LocalCoordinates_Hexacopter_Controller_T

struct px4_internal_block_LLA2LocalCoordinates_Hexacopter_Controller_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T previousValidReceived;
  boolean_T nextValidReceived;
};

#endif
      // struct_px4_internal_block_LLA2LocalCoordinates_Hexacopter_Controller_T

#ifndef struct_px4_internal_block_getPX4AbsoluteTime_Hexacopter_ControllerWi_T
#define struct_px4_internal_block_getPX4AbsoluteTime_Hexacopter_ControllerWi_T

struct px4_internal_block_getPX4AbsoluteTime_Hexacopter_ControllerWi_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_px4_internal_block_SampleTimeImpl_Hexacopter_ControllerWith_T
    SampleTimeHandler;
};

#endif
      // struct_px4_internal_block_getPX4AbsoluteTime_Hexacopter_ControllerWi_T

#ifndef struct_px4_internal_block_Publisher_Hexacopter_ControllerWithNavigat_T
#define struct_px4_internal_block_Publisher_Hexacopter_ControllerWithNavigat_T

struct px4_internal_block_Publisher_Hexacopter_ControllerWithNavigat_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  orb_advert_t orbAdvertiseObj;
  orb_metadata_t * orbMetadataObj;
};

#endif
      // struct_px4_internal_block_Publisher_Hexacopter_ControllerWithNavigat_T

#ifndef struct_cell_wrap_Hexacopter_ControllerWithNavigation_T
#define struct_cell_wrap_Hexacopter_ControllerWithNavigation_T

struct cell_wrap_Hexacopter_ControllerWithNavigation_T
{
  uint32_T f1[8];
};

#endif                // struct_cell_wrap_Hexacopter_ControllerWithNavigation_T

#ifndef struct_uav_sluav_internal_system_WaypointFollower_Hexacopter_Control_T
#define struct_uav_sluav_internal_system_WaypointFollower_Hexacopter_Control_T

struct uav_sluav_internal_system_WaypointFollower_Hexacopter_Control_T
{
  int32_T isInitialized;
  cell_wrap_Hexacopter_ControllerWithNavigation_T inputVarSize[3];
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
      // struct_uav_sluav_internal_system_WaypointFollower_Hexacopter_Control_T

// Parameters (default storage)
typedef struct P_Hexacopter_ControllerWithNavigation_T_
  P_Hexacopter_ControllerWithNavigation_T;

// Forward declaration for rtModel
typedef struct tag_RTM_Hexacopter_ControllerWithNavigation_T
  RT_MODEL_Hexacopter_ControllerWithNavigation_T;

#endif                          // Hexacopter_ControllerWithNavigation_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
