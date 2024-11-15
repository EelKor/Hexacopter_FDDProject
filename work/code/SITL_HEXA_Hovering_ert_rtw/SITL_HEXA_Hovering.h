//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: SITL_HEXA_Hovering.h
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
#ifndef SITL_HEXA_Hovering_h_
#define SITL_HEXA_Hovering_h_
#include <drivers/drv_hrt.h>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "MW_uORB_Write.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include "SITL_HEXA_Hovering_types.h"
#include <uORB/topics/vehicle_trajectory_waypoint.h>
#include <uORB/topics/position_setpoint_triplet.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/actuator_motors.h>
#include <uORB/topics/vehicle_local_position_setpoint.h>
#include <uORB/topics/vehicle_attitude_setpoint.h>
#include <uORB/topics/trajectory_waypoint.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/home_position.h>
#include <uORB/topics/vehicle_rates_setpoint.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/actuator_armed.h>
#include "rt_sys_SITL_HEXA_Hovering_0.h"
#include "Navigation.h"
#include "rt_sys_SITL_HEXA_Hovering_2.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_SITL_HEXA_Hovering_T {
  px4_Bus_vehicle_trajectory_waypoint BusAssignment1;// '<S572>/Bus Assignment1' 
  px4_Bus_vehicle_trajectory_waypoint In1;// '<S577>/In1'
  px4_Bus_vehicle_trajectory_waypoint r;
  px4_Bus_position_setpoint_triplet In1_p;// '<S589>/In1'
  px4_Bus_position_setpoint_triplet r1;
  px4_Bus_vehicle_local_position In1_c;// '<S609>/In1'
  px4_Bus_vehicle_local_position r_mb;
  px4_Bus_input_rc r_m;
  px4_Bus_actuator_motors BusAssignment;// '<S595>/Bus Assignment'
  real_T b_waypointsIn_data[9];
  real_T MatrixConcatenate_p[9];       // '<S559>/Matrix Concatenate'
  px4_Bus_vehicle_local_position_setpoint BusAssignment_a;// '<S7>/Bus Assignment' 
  px4_Bus_vehicle_local_position_setpoint BusAssignment_m;// '<S552>/Bus Assignment' 
  px4_Bus_vehicle_attitude_setpoint BusAssignment_h;// '<S6>/Bus Assignment'
  px4_Bus_trajectory_waypoint BusAssignment1_f;// '<S580>/Bus Assignment1'
  px4_Bus_vehicle_attitude In1_m;      // '<S608>/In1'
  px4_Bus_vehicle_attitude r1_c;
  px4_Bus_home_position In1_f;         // '<S588>/In1'
  real_T DataTypeConversion1[7];       // '<S4>/Data Type Conversion1'
  px4_Bus_home_position r2;
  px4_Bus_vehicle_rates_setpoint BusAssignment_h4;// '<S8>/Bus Assignment'
  px4_Bus_vehicle_angular_velocity In1_l;// '<S606>/In1'
  px4_Bus_vehicle_angular_velocity r2_k;
  real_T DataTypeConversion2[3];       // '<S4>/Data Type Conversion2'
  real_T VectorConcatenate[3];         // '<S21>/Vector Concatenate'
  real_T lla0[3];
  real_T virtualWaypoint[3];
  real_T MatrixConcatenate1[3];        // '<S578>/Matrix Concatenate1'
  real_T MatrixConcatenate1_k[3];      // '<S572>/Matrix Concatenate1'
  real_T dv[3];
  px4_Bus_actuator_armed In1_b;        // '<S607>/In1'
  px4_Bus_actuator_armed r3;
  real_T desiredZ;                     // '<S5>/Gain'
  real_T yaw_In;                       // '<S561>/yaw_In'
  real_T yaw_In_i;                     // '<S565>/yaw_In'
  real_T In;                           // '<S564>/In'
  real_T yaw_In_ik;                    // '<S568>/yaw_In'
  real_T Saturation;                   // '<S437>/Saturation'
  real_T Saturation_c;                 // '<S489>/Saturation'
  real_T Saturation_b;                 // '<S541>/Saturation'
  real_T Saturation_o;                 // '<S330>/Saturation'
  real_T Saturation_d;                 // '<S382>/Saturation'
  real_T Saturation_bi[2];             // '<S280>/Saturation'
  real_T Saturation_n[2];              // '<S230>/Saturation'
  real_T Gain1;                        // '<S12>/Gain1'
  real_T Saturation_e;                 // '<S173>/Saturation'
  real_T ProportionalGain;             // '<S71>/Proportional Gain'
  real_T ProportionalGain_a;           // '<S121>/Proportional Gain'
  real_T Filter_j;                     // '<S425>/Filter'
  real_T flat;
  real_T absx;
  real_T Gain_i;                       // '<S566>/Gain'
  real_T Sum_f;                        // '<S566>/Sum'
  real_T rtb_Merge_idx_3;
  real_T rtb_Merge_idx_2;
  real_T rtb_Merge_idx_0;
  real_T rtb_Merge_idx_1;
  real_T lla0_tmp;
  real_T flat_tmp;
  real_T dLat;
  real_T dLon;
  real_T flat_m;
  real_T absx_c;
  real_T r_k;
  real_T flat_tmp_c;
  real_T absx_b;
  real_T q;
  real_T scale;
  real_T absxk;
  real_T t;
  real_T Saturation3;                  // '<S3>/Saturation3'
  real_T Saturation2;                  // '<S3>/Saturation2'
  real_T Saturation1;                  // '<S3>/Saturation1'
  real_T Saturation_cl;                // '<S3>/Saturation'
  real_T u0;
  real_T Sum_l;                        // '<S20>/Sum'
  real_T fcn3;                         // '<S10>/fcn3'
  real_T rtb_Switch_j_idx_0;
  real_T rtb_Switch_j_idx_1;
  real_T rtb_Switch_j_idx_2;
  real_T rtb_Switch_j_idx_3;
  real_T VectorConcatenate_tmp;
  real_T VectorConcatenate_tmp_c;
  real_T VectorConcatenate_tmp_b;
  boolean_T x[6];
  real32_T ParamStep;
  int32_T ParamStep_p;
  int32_T iy;
  int32_T i1;
  int32_T j;
  int32_T ix;
  int32_T b_exponent;
  int32_T b_exponent_c;
  int32_T b_k;
  int32_T i;
  int32_T i1_f;
  int32_T i_p;
  int32_T i1_c;
  int8_T tmp_data[3];
  boolean_T distinctWptsIdx[3];
  boolean_T b[3];
  boolean_T IsNaN_l[2];                // '<S557>/IsNaN'
  int8_T rtPrevAction;
  int8_T rtAction;
  boolean_T latp2;
  boolean_T OR_g;                      // '<S557>/OR'
  boolean_T latp2_g;
  boolean_T b_varargout_1;
  B_PX4Timestamp_SITL_HEXA_Hovering_T PX4Timestamp1;// '<S6>/PX4 Timestamp'
  B_PX4Timestamp_SITL_HEXA_Hovering_T PX4Timestamp_pna;// '<S6>/PX4 Timestamp'
  B_MATLABSystem_SITL_HEXA_Hovering_T MATLABSystem_b;// '<S578>/MATLAB System'
  B_MATLABSystem_SITL_HEXA_Hovering_T MATLABSystem;// '<S578>/MATLAB System'
  B_PX4Timestamp_SITL_HEXA_Hovering_T PX4Timestamp_o;// '<S6>/PX4 Timestamp'
  B_PX4Timestamp_SITL_HEXA_Hovering_T PX4Timestamp_pn;// '<S6>/PX4 Timestamp'
  B_PX4Timestamp_SITL_HEXA_Hovering_T PX4Timestamp_p;// '<S6>/PX4 Timestamp'
  B_PX4Timestamp_SITL_HEXA_Hovering_T PX4Timestamp;// '<S6>/PX4 Timestamp'
};

// Block states (default storage) for system '<Root>'
struct DW_SITL_HEXA_Hovering_T {
  uav_sluav_internal_system_WaypointFollower_SITL_HEXA_Hovering_T obj;// '<S559>/UAV Waypoint Follower' 
  px4_internal_block_ParameterUpdate_SITL_HEXA_Hovering_T obj_o;// '<S596>/Read Parameter4' 
  px4_internal_block_ParameterUpdate_SITL_HEXA_Hovering_T obj_g;// '<S596>/Read Parameter3' 
  px4_internal_block_ParameterUpdate_SITL_HEXA_Hovering_T obj_d;// '<S596>/Read Parameter2' 
  px4_internal_block_ParameterUpdate_SITL_HEXA_Hovering_T obj_j;// '<S596>/Read Parameter13' 
  px4_internal_block_ParameterUpdate_SITL_HEXA_Hovering_T obj_i;// '<S596>/Read Parameter1' 
  px4_internal_block_ParameterUpdate_SITL_HEXA_Hovering_T obj_jb;// '<S596>/Read Parameter' 
  px4_internal_block_ParameterUpdate_SITL_HEXA_Hovering_T obj_b;// '<S586>/Read Parameter' 
  px4_internal_block_ParameterUpdate_SITL_HEXA_Hovering_T obj_ga;// '<S587>/Read Parameter' 
  px4_internal_block_ParameterUpdate_SITL_HEXA_Hovering_T obj_k;// '<S555>/Read Parameter' 
  px4_internal_block_Subscriber_SITL_HEXA_Hovering_T obj_m;// '<S605>/SourceBlock' 
  px4_internal_block_Subscriber_SITL_HEXA_Hovering_T obj_gv;// '<S604>/SourceBlock' 
  px4_internal_block_Subscriber_SITL_HEXA_Hovering_T obj_d0;// '<S603>/SourceBlock' 
  px4_internal_block_Subscriber_SITL_HEXA_Hovering_T obj_p;// '<S602>/SourceBlock' 
  px4_internal_block_Subscriber_SITL_HEXA_Hovering_T obj_kd;// '<S598>/SourceBlock' 
  px4_internal_block_Subscriber_SITL_HEXA_Hovering_T obj_kz;// '<S574>/SourceBlock' 
  px4_internal_block_Subscriber_SITL_HEXA_Hovering_T obj_gf;// '<S573>/SourceBlock' 
  px4_internal_block_Subscriber_SITL_HEXA_Hovering_T obj_e;// '<S576>/SourceBlock' 
  px4_internal_block_Publisher_SITL_HEXA_Hovering_T obj_kg;// '<S601>/SinkBlock' 
  px4_internal_block_Publisher_SITL_HEXA_Hovering_T obj_mc;// '<S583>/SinkBlock' 
  px4_internal_block_Publisher_SITL_HEXA_Hovering_T obj_dz;// '<S19>/SinkBlock'
  px4_internal_block_Publisher_SITL_HEXA_Hovering_T obj_mg;// '<S15>/SinkBlock'
  px4_internal_block_LLA2LocalCoordinates_SITL_HEXA_Hovering_T obj_mr;// '<S555>/LLA2LocalCoordinates' 
  real_T Delay_DSTATE;                 // '<S560>/Delay'
  real_T Delay_DSTATE_l[2];            // '<S557>/Delay'
  real_T Delay_DSTATE_n;               // '<S562>/Delay'
  real_T Delay_DSTATE_b;               // '<S563>/Delay'
  real_T Delay_DSTATE_c;               // '<S566>/Delay'
  real_T Delay_DSTATE_d;               // '<S567>/Delay'
  real_T Integrator_DSTATE;            // '<S430>/Integrator'
  real_T Filter_DSTATE;                // '<S425>/Filter'
  real_T Integrator_DSTATE_d;          // '<S482>/Integrator'
  real_T Filter_DSTATE_h;              // '<S477>/Filter'
  real_T Integrator_DSTATE_dd;         // '<S534>/Integrator'
  real_T Filter_DSTATE_l;              // '<S529>/Filter'
  real_T Filter_DSTATE_m;              // '<S370>/Filter'
  real_T Integrator_DSTATE_c;          // '<S375>/Integrator'
  real_T PrevY;                        // '<S11>/Rate Limiter2'
  real_T PrevY_f;                      // '<S11>/Rate Limiter1'
  px4_internal_block_LLA2LocalCoordinatesNED_SITL_HEXA_Hovering_T obj_mu;// '<S581>/MATLAB System' 
  int8_T If_ActiveSubsystem;           // '<S554>/If'
  DW_PX4Timestamp_SITL_HEXA_Hovering_T PX4Timestamp1;// '<S6>/PX4 Timestamp'
  DW_SinkBlock_SITL_HEXA_Hovering_T SinkBlock_a;// '<S17>/SinkBlock'
  DW_PX4Timestamp_SITL_HEXA_Hovering_T PX4Timestamp_pna;// '<S6>/PX4 Timestamp'
  DW_MATLABSystem_SITL_HEXA_Hovering_T MATLABSystem_b;// '<S578>/MATLAB System'
  DW_MATLABSystem_SITL_HEXA_Hovering_T MATLABSystem;// '<S578>/MATLAB System'
  DW_PX4Timestamp_SITL_HEXA_Hovering_T PX4Timestamp_o;// '<S6>/PX4 Timestamp'
  DW_PX4Timestamp_SITL_HEXA_Hovering_T PX4Timestamp_pn;// '<S6>/PX4 Timestamp'
  DW_SinkBlock_SITL_HEXA_Hovering_T SinkBlock_m;// '<S17>/SinkBlock'
  DW_PX4Timestamp_SITL_HEXA_Hovering_T PX4Timestamp_p;// '<S6>/PX4 Timestamp'
  DW_PX4Timestamp_SITL_HEXA_Hovering_T PX4Timestamp;// '<S6>/PX4 Timestamp'
};

// Parameters (default storage)
struct P_SITL_HEXA_Hovering_T_ {
  real_T MC_PITCHRATE_D;               // Variable: MC_PITCHRATE_D
                                          //  Referenced by: '<S475>/Derivative Gain'

  real_T MC_PITCHRATE_I;               // Variable: MC_PITCHRATE_I
                                          //  Referenced by: '<S479>/Integral Gain'

  real_T MC_PITCHRATE_P;               // Variable: MC_PITCHRATE_P
                                          //  Referenced by: '<S487>/Proportional Gain'

  real_T MC_PITCH_P;                   // Variable: MC_PITCH_P
                                          //  Referenced by: '<S71>/Proportional Gain'

  real_T MC_ROLLRATE_D;                // Variable: MC_ROLLRATE_D
                                          //  Referenced by: '<S527>/Derivative Gain'

  real_T MC_ROLLRATE_I;                // Variable: MC_ROLLRATE_I
                                          //  Referenced by: '<S531>/Integral Gain'

  real_T MC_ROLLRATE_P;                // Variable: MC_ROLLRATE_P
                                          //  Referenced by: '<S539>/Proportional Gain'

  real_T MC_ROLL_P;                    // Variable: MC_ROLL_P
                                          //  Referenced by: '<S121>/Proportional Gain'

  real_T MC_YAWRATE_D;                 // Variable: MC_YAWRATE_D
                                          //  Referenced by: '<S423>/Derivative Gain'

  real_T MC_YAWRATE_I;                 // Variable: MC_YAWRATE_I
                                          //  Referenced by: '<S427>/Integral Gain'

  real_T MC_YAWRATE_P;                 // Variable: MC_YAWRATE_P
                                          //  Referenced by: '<S435>/Proportional Gain'

  real_T MC_YAW_P;                     // Variable: MC_YAW_P
                                          //  Referenced by: '<S171>/Proportional Gain'

  real_T MPC_XY_P;                     // Variable: MPC_XY_P
                                          //  Referenced by: '<S278>/Proportional Gain'

  real_T MPC_XY_VEL_MAX;               // Variable: MPC_XY_VEL_MAX
                                          //  Referenced by: '<S280>/Saturation'

  real_T MPC_Z_P;                      // Variable: MPC_Z_P
                                          //  Referenced by: '<S328>/Proportional Gain'

  real_T MPC_Z_VEL_D_ACC;              // Variable: MPC_Z_VEL_D_ACC
                                          //  Referenced by: '<S368>/Derivative Gain'

  real_T MPC_Z_VEL_I_ACC;              // Variable: MPC_Z_VEL_I_ACC
                                          //  Referenced by: '<S372>/Integral Gain'

  real_T MPC_Z_VEL_MAX_DN;             // Variable: MPC_Z_VEL_MAX_DN
                                          //  Referenced by: '<S330>/Saturation'

  real_T MPC_Z_VEL_MAX_UP;             // Variable: MPC_Z_VEL_MAX_UP
                                          //  Referenced by: '<S330>/Saturation'

  real_T MPC_Z_VEL_P_ACC;              // Variable: MPC_Z_VEL_P_ACC
                                          //  Referenced by: '<S380>/Proportional Gain'

  real_T PID_vz_InitialConditionForFilter;
                             // Mask Parameter: PID_vz_InitialConditionForFilter
                                //  Referenced by: '<S370>/Filter'

  real_T PIDController_InitialConditionForFilter;
                      // Mask Parameter: PIDController_InitialConditionForFilter
                         //  Referenced by: '<S425>/Filter'

  real_T PIDController1_InitialConditionForFilter;
                     // Mask Parameter: PIDController1_InitialConditionForFilter
                        //  Referenced by: '<S477>/Filter'

  real_T PIDController2_InitialConditionForFilter;
                     // Mask Parameter: PIDController2_InitialConditionForFilter
                        //  Referenced by: '<S529>/Filter'

  real_T PID_vz_InitialConditionForIntegrator;
                         // Mask Parameter: PID_vz_InitialConditionForIntegrator
                            //  Referenced by: '<S375>/Integrator'

  real_T PIDController_InitialConditionForIntegrator;
                  // Mask Parameter: PIDController_InitialConditionForIntegrator
                     //  Referenced by: '<S430>/Integrator'

  real_T PIDController1_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController1_InitialConditionForIntegrator
                    //  Referenced by: '<S482>/Integrator'

  real_T PIDController2_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController2_InitialConditionForIntegrator
                    //  Referenced by: '<S534>/Integrator'

  real_T PIDController5_LowerSaturationLimit;
                          // Mask Parameter: PIDController5_LowerSaturationLimit
                             //  Referenced by: '<S173>/Saturation'

  real_T PID_vz_LowerSaturationLimit;
                                  // Mask Parameter: PID_vz_LowerSaturationLimit
                                     //  Referenced by:
                                     //    '<S382>/Saturation'
                                     //    '<S367>/DeadZone'

  real_T PIDController_LowerSaturationLimit;
                           // Mask Parameter: PIDController_LowerSaturationLimit
                              //  Referenced by: '<S230>/Saturation'

  real_T PIDController_LowerSaturationLimit_b;
                         // Mask Parameter: PIDController_LowerSaturationLimit_b
                            //  Referenced by:
                            //    '<S437>/Saturation'
                            //    '<S422>/DeadZone'

  real_T PIDController1_LowerSaturationLimit;
                          // Mask Parameter: PIDController1_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S489>/Saturation'
                             //    '<S474>/DeadZone'

  real_T PIDController2_LowerSaturationLimit;
                          // Mask Parameter: PIDController2_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S541>/Saturation'
                             //    '<S526>/DeadZone'

  real_T PID_vz_N;                     // Mask Parameter: PID_vz_N
                                          //  Referenced by: '<S378>/Filter Coefficient'

  real_T PIDController_N;              // Mask Parameter: PIDController_N
                                          //  Referenced by: '<S433>/Filter Coefficient'

  real_T PIDController1_N;             // Mask Parameter: PIDController1_N
                                          //  Referenced by: '<S485>/Filter Coefficient'

  real_T PIDController2_N;             // Mask Parameter: PIDController2_N
                                          //  Referenced by: '<S537>/Filter Coefficient'

  real_T PIDController_P;              // Mask Parameter: PIDController_P
                                          //  Referenced by: '<S228>/Proportional Gain'

  real_T PIDController5_UpperSaturationLimit;
                          // Mask Parameter: PIDController5_UpperSaturationLimit
                             //  Referenced by: '<S173>/Saturation'

  real_T PID_vz_UpperSaturationLimit;
                                  // Mask Parameter: PID_vz_UpperSaturationLimit
                                     //  Referenced by:
                                     //    '<S382>/Saturation'
                                     //    '<S367>/DeadZone'

  real_T PIDController_UpperSaturationLimit;
                           // Mask Parameter: PIDController_UpperSaturationLimit
                              //  Referenced by: '<S230>/Saturation'

  real_T PIDController_UpperSaturationLimit_p;
                         // Mask Parameter: PIDController_UpperSaturationLimit_p
                            //  Referenced by:
                            //    '<S437>/Saturation'
                            //    '<S422>/DeadZone'

  real_T PIDController1_UpperSaturationLimit;
                          // Mask Parameter: PIDController1_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S489>/Saturation'
                             //    '<S474>/DeadZone'

  real_T PIDController2_UpperSaturationLimit;
                          // Mask Parameter: PIDController2_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S541>/Saturation'
                             //    '<S526>/DeadZone'

  uint8_T CompareToConstant_const;    // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S570>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Out1_Y0;// Computed Parameter: Out1_Y0
                                                 //  Referenced by: '<S577>/Out1'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value;// Computed Parameter: Constant_Value
                                                        //  Referenced by: '<S582>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                          //  Referenced by: '<S576>/Constant'

  px4_Bus_position_setpoint_triplet Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                 //  Referenced by: '<S589>/Out1'

  px4_Bus_position_setpoint_triplet Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                        //  Referenced by: '<S574>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                              //  Referenced by: '<S609>/Out1'

  px4_Bus_vehicle_local_position Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                     //  Referenced by: '<S605>/Constant'

  px4_Bus_actuator_motors Constant_Value_a;// Computed Parameter: Constant_Value_a
                                              //  Referenced by: '<S600>/Constant'

  px4_Bus_input_rc Out1_Y0_f;          // Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S599>/Out1'

  px4_Bus_input_rc Constant_Value_k;   // Computed Parameter: Constant_Value_k
                                          //  Referenced by: '<S598>/Constant'

  px4_Bus_vehicle_local_position_setpoint Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                              //  Referenced by: '<S590>/Constant'

  px4_Bus_vehicle_local_position_setpoint Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                              //  Referenced by: '<S16>/Constant'

  px4_Bus_vehicle_attitude Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S608>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_lh;// Computed Parameter: Constant_Value_lh
                                                //  Referenced by: '<S604>/Constant'

  px4_Bus_vehicle_attitude_setpoint Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                        //  Referenced by: '<S14>/Constant'

  px4_Bus_home_position Out1_Y0_o;     // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S588>/Out1'

  px4_Bus_home_position Constant_Value_b0;// Computed Parameter: Constant_Value_b0
                                             //  Referenced by: '<S573>/Constant'

  px4_Bus_vehicle_angular_velocity Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                //  Referenced by: '<S606>/Out1'

  px4_Bus_vehicle_angular_velocity Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                       //  Referenced by: '<S602>/Constant'

  px4_Bus_vehicle_rates_setpoint Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                     //  Referenced by: '<S18>/Constant'

  px4_Bus_actuator_armed Out1_Y0_d;    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S607>/Out1'

  px4_Bus_actuator_armed Constant_Value_jl;// Computed Parameter: Constant_Value_jl
                                              //  Referenced by: '<S603>/Constant'

  real_T Constant_Value_im[4];         // Expression: [1 0 0 0]
                                          //  Referenced by: '<S9>/Constant'

  real_T Constant_Value_be;            // Expression: 1
                                          //  Referenced by: '<S24>/Constant'

  real_T Constant_Value_m;             // Expression: 1
                                          //  Referenced by: '<S25>/Constant'

  real_T Switch1_Threshold;            // Expression: 0
                                          //  Referenced by: '<S29>/Switch1'

  real_T Yawrate_sp_Y0;                // Computed Parameter: Yawrate_sp_Y0
                                          //  Referenced by: '<S11>/Yawrate_sp'

  real_T Pitchrate_sp_Y0;              // Computed Parameter: Pitchrate_sp_Y0
                                          //  Referenced by: '<S11>/Pitchrate_sp'

  real_T Rollrate_spl_Y0;              // Computed Parameter: Rollrate_spl_Y0
                                          //  Referenced by: '<S11>/Rollrate_spl'

  real_T Constant_Value_p;             // Expression: 2*pi
                                          //  Referenced by: '<S29>/Constant'

  real_T Switch_Threshold;             // Expression: pi
                                          //  Referenced by: '<S29>/Switch'

  real_T RateLimiter2_RisingLim;       // Expression: 180*pi/180
                                          //  Referenced by: '<S11>/Rate Limiter2'

  real_T RateLimiter2_FallingLim;      // Expression: -180*pi/180
                                          //  Referenced by: '<S11>/Rate Limiter2'

  real_T RateLimiter2_IC;              // Expression: 0
                                          //  Referenced by: '<S11>/Rate Limiter2'

  real_T RateLimiter1_RisingLim;       // Expression: 180*pi/180
                                          //  Referenced by: '<S11>/Rate Limiter1'

  real_T RateLimiter1_FallingLim;      // Expression: -180*pi/180
                                          //  Referenced by: '<S11>/Rate Limiter1'

  real_T RateLimiter1_IC;              // Expression: 0
                                          //  Referenced by: '<S11>/Rate Limiter1'

  real_T Constant_Value_j4;            // Expression: 0
                                          //  Referenced by: '<S183>/Constant'

  real_T tau_Thrust_Y0;                // Computed Parameter: tau_Thrust_Y0
                                          //  Referenced by: '<S12>/tau_Thrust'

  real_T des_pitch_Y0;                 // Computed Parameter: des_pitch_Y0
                                          //  Referenced by: '<S12>/des_pitch'

  real_T des_roll_Y0;                  // Computed Parameter: des_roll_Y0
                                          //  Referenced by: '<S12>/des_roll'

  real_T XY_velocity_setpoint_Y0; // Computed Parameter: XY_velocity_setpoint_Y0
                                     //  Referenced by: '<S12>/XY_velocity_setpoint'

  real_T Z_velocity_setpoint_Y0;   // Computed Parameter: Z_velocity_setpoint_Y0
                                      //  Referenced by: '<S12>/Z_velocity_setpoint'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S365>/Constant1'

  real_T Gain1_Gain;                   // Expression: -1
                                          //  Referenced by: '<S183>/Gain1'

  real_T Clamping_zero_Value;          // Expression: 0
                                          //  Referenced by: '<S365>/Clamping_zero'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S370>/Filter'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S375>/Integrator'

  real_T Gain_Gain;                    // Expression: -1
                                          //  Referenced by: '<S184>/Gain'

  real_T Gain1_Gain_f;                 // Expression: -1
                                          //  Referenced by: '<S12>/Gain1'

  real_T tau_yaw_Y0;                   // Computed Parameter: tau_yaw_Y0
                                          //  Referenced by: '<S13>/tau_yaw'

  real_T tau_pitch_Y0;                 // Computed Parameter: tau_pitch_Y0
                                          //  Referenced by: '<S13>/tau_pitch'

  real_T tau_roll_Y0;                  // Computed Parameter: tau_roll_Y0
                                          //  Referenced by: '<S13>/tau_roll'

  real_T Constant1_Value_k;            // Expression: 0
                                          //  Referenced by: '<S420>/Constant1'

  real_T Constant1_Value_j;            // Expression: 0
                                          //  Referenced by: '<S472>/Constant1'

  real_T Constant1_Value_ka;           // Expression: 0
                                          //  Referenced by: '<S524>/Constant1'

  real_T Clamping_zero_Value_i;        // Expression: 0
                                          //  Referenced by: '<S420>/Clamping_zero'

  real_T Integrator_gainval_h;       // Computed Parameter: Integrator_gainval_h
                                        //  Referenced by: '<S430>/Integrator'

  real_T Filter_gainval_f;             // Computed Parameter: Filter_gainval_f
                                          //  Referenced by: '<S425>/Filter'

  real_T Clamping_zero_Value_d;        // Expression: 0
                                          //  Referenced by: '<S472>/Clamping_zero'

  real_T Integrator_gainval_b;       // Computed Parameter: Integrator_gainval_b
                                        //  Referenced by: '<S482>/Integrator'

  real_T Filter_gainval_l;             // Computed Parameter: Filter_gainval_l
                                          //  Referenced by: '<S477>/Filter'

  real_T Clamping_zero_Value_e;        // Expression: 0
                                          //  Referenced by: '<S524>/Clamping_zero'

  real_T Integrator_gainval_n;       // Computed Parameter: Integrator_gainval_n
                                        //  Referenced by: '<S534>/Integrator'

  real_T Filter_gainval_a;             // Computed Parameter: Filter_gainval_a
                                          //  Referenced by: '<S529>/Filter'

  real_T yaw_Out_Y0;                   // Computed Parameter: yaw_Out_Y0
                                          //  Referenced by: '<S568>/yaw_Out'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S566>/Delay'

  real_T Rate_Value;                   // Expression: 0.01
                                          //  Referenced by: '<S566>/Rate'

  real_T Gain1_Gain_b;                 // Expression: -1
                                          //  Referenced by: '<S566>/Gain1'

  real_T Gain_Gain_e;                  // Expression: -1
                                          //  Referenced by: '<S566>/Gain'

  real_T Delay_InitialCondition_g;     // Expression: 1
                                          //  Referenced by: '<S567>/Delay'

  real_T Constant_Value_f;             // Expression: 0
                                          //  Referenced by: '<S567>/Constant'

  real_T Out_Y0;                       // Computed Parameter: Out_Y0
                                          //  Referenced by: '<S564>/Out'

  real_T Gain_Gain_l;                  // Expression: -1
                                          //  Referenced by: '<S562>/Gain'

  real_T yaw_Out_Y0_f;                 // Computed Parameter: yaw_Out_Y0_f
                                          //  Referenced by: '<S565>/yaw_Out'

  real_T Delay_InitialCondition_n;     // Expression: 0.0
                                          //  Referenced by: '<S557>/Delay'

  real_T Delay_InitialCondition_m;     // Expression: 0.0
                                          //  Referenced by: '<S562>/Delay'

  real_T Switch_Threshold_j;           // Expression: 0
                                          //  Referenced by: '<S562>/Switch'

  real_T Rateofdescent_Value;          // Expression: 0.02
                                          //  Referenced by: '<S562>/Rate of descent'

  real_T Gain2_Gain;                   // Expression: -1
                                          //  Referenced by: '<S562>/Gain2'

  real_T Gain1_Gain_a;                 // Expression: -1
                                          //  Referenced by: '<S562>/Gain1'

  real_T Delay_InitialCondition_j;     // Expression: 1
                                          //  Referenced by: '<S563>/Delay'

  real_T Constant_Value_nn;            // Expression: 0
                                          //  Referenced by: '<S563>/Constant'

  real_T Constant_Value_jd;            // Expression: 0
                                          //  Referenced by: '<S569>/Constant'

  real_T Constant_Value_gw;            // Expression: 6
                                          //  Referenced by: '<S559>/Constant'

  real_T yaw_Out_Y0_p;                 // Computed Parameter: yaw_Out_Y0_p
                                          //  Referenced by: '<S561>/yaw_Out'

  real_T Delay_InitialCondition_g0;    // Expression: 1
                                          //  Referenced by: '<S560>/Delay'

  real_T Constant_Value_ic;            // Expression: 0
                                          //  Referenced by: '<S560>/Constant'

  real_T ReadParameter_SampleTime;     // Expression: -1
                                          //  Referenced by: '<S555>/Read Parameter'

  real_T ReadParameter_SampleTime_c;   // Expression: -1
                                          //  Referenced by: '<S587>/Read Parameter'

  real_T ReadParameter_SampleTime_g;   // Expression: -1
                                          //  Referenced by: '<S586>/Read Parameter'

  real_T ReadParameter_SampleTime_n;   // Expression: -1
                                          //  Referenced by: '<S596>/Read Parameter'

  real_T ReadParameter1_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S596>/Read Parameter1'

  real_T ReadParameter13_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S596>/Read Parameter13'

  real_T ReadParameter2_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S596>/Read Parameter2'

  real_T ReadParameter3_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S596>/Read Parameter3'

  real_T ReadParameter4_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S596>/Read Parameter4'

  real_T Gain_Gain_h;                  // Expression: 5
                                          //  Referenced by: '<S3>/Gain'

  real_T Saturation3_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S3>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S3>/Saturation3'

  real_T Gain1_Gain_e;                 // Expression: 5
                                          //  Referenced by: '<S3>/Gain1'

  real_T Saturation2_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S3>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S3>/Saturation2'

  real_T Gain2_Gain_h;                 // Expression: 10
                                          //  Referenced by: '<S3>/Gain2'

  real_T Saturation1_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S3>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S3>/Saturation1'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<S3>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S3>/Saturation'

  real_T Saturation4_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S3>/Saturation4'

  real_T Saturation4_LowerSat;         // Expression: 0
                                          //  Referenced by: '<S3>/Saturation4'

  real_T Gain_Gain_b;                  // Expression: 0.01
                                          //  Referenced by: '<S596>/Gain'

  real_T Gain1_Gain_o;                 // Expression: 0.01
                                          //  Referenced by: '<S596>/Gain1'

  real_T Gain2_Gain_d;                 // Expression: 0.01
                                          //  Referenced by: '<S596>/Gain2'

  real_T Gain3_Gain;                   // Expression: 0.01
                                          //  Referenced by: '<S596>/Gain3'

  real_T Gain4_Gain;                   // Expression: 0.01
                                          //  Referenced by: '<S596>/Gain4'

  real_T Gain5_Gain;                   // Expression: 0.01
                                          //  Referenced by: '<S596>/Gain5'

  real_T Constant_Value_a0;            // Expression: 0
                                          //  Referenced by: '<S595>/Constant'

  real_T Switch_Threshold_l;           // Expression: 0
                                          //  Referenced by: '<S9>/Switch'

  real_T Constant_Value_n5;            // Expression: 0
                                          //  Referenced by: '<S5>/Constant'

  real_T Constant1_Value_b;            // Expression: 0
                                          //  Referenced by: '<S5>/Constant1'

  real_T Constant2_Value;              // Expression: -5
                                          //  Referenced by: '<S5>/Constant2'

  real_T Gain_Gain_c;                  // Expression: -1
                                          //  Referenced by: '<S5>/Gain'

  real_T thrust_sp_bX_Value;           // Expression: 0
                                          //  Referenced by: '<S6>/thrust_sp_bX'

  real_T thrust_sp_bY_Value;           // Expression: 0
                                          //  Referenced by: '<S6>/thrust_sp_bY'

  real_T Constant_Value_go;            // Expression: 0
                                          //  Referenced by: '<S7>/Constant'

  real_T thrust_sp_bX_Value_m;         // Expression: 0
                                          //  Referenced by: '<S8>/thrust_sp_bX'

  real_T thrust_sp_bY_Value_m;         // Expression: 0
                                          //  Referenced by: '<S8>/thrust_sp_bY'

  real_T Gain1_Gain_j;                 // Expression: -1
                                          //  Referenced by: '<S5>/Gain1'

  real_T Gain2_Gain_n;                 // Expression: -1
                                          //  Referenced by: '<S5>/Gain2'

  uint64_T Constant7_Value;            // Computed Parameter: Constant7_Value
                                          //  Referenced by: '<S580>/Constant7'

  real32_T Constant1_Value_d[2];       // Computed Parameter: Constant1_Value_d
                                          //  Referenced by: '<S587>/Constant1'

  real32_T Constant_Value_f2;          // Computed Parameter: Constant_Value_f2
                                          //  Referenced by: '<S587>/Constant'

  real32_T Gain_Gain_hp;               // Computed Parameter: Gain_Gain_hp
                                          //  Referenced by: '<S586>/Gain'

  real32_T Constant1_Value_k4[2];      // Computed Parameter: Constant1_Value_k4
                                          //  Referenced by: '<S586>/Constant1'

  real32_T Constant_Value_l4;          // Computed Parameter: Constant_Value_l4
                                          //  Referenced by: '<S586>/Constant'

  real32_T Constant_Value_fh[3];       // Computed Parameter: Constant_Value_fh
                                          //  Referenced by: '<S580>/Constant'

  real32_T Constant1_Value_h[3];       // Computed Parameter: Constant1_Value_h
                                          //  Referenced by: '<S580>/Constant1'

  real32_T Constant2_Value_f[3];       // Computed Parameter: Constant2_Value_f
                                          //  Referenced by: '<S580>/Constant2'

  real32_T Constant3_Value;            // Computed Parameter: Constant3_Value
                                          //  Referenced by: '<S580>/Constant3'

  real32_T Constant4_Value;            // Computed Parameter: Constant4_Value
                                          //  Referenced by: '<S580>/Constant4'

  boolean_T Constant5_Value;           // Computed Parameter: Constant5_Value
                                          //  Referenced by: '<S578>/Constant5'

  boolean_T Constant5_Value_k;         // Computed Parameter: Constant5_Value_k
                                          //  Referenced by: '<S579>/Constant5'

  boolean_T Constant1_Value_dl;        // Computed Parameter: Constant1_Value_dl
                                          //  Referenced by: '<S581>/Constant1'

  boolean_T Constant5_Value_h;         // Computed Parameter: Constant5_Value_h
                                          //  Referenced by: '<S581>/Constant5'

  boolean_T Constant5_Value_l;         // Computed Parameter: Constant5_Value_l
                                          //  Referenced by: '<S580>/Constant5'

  int8_T Constant_Value_mp;            // Computed Parameter: Constant_Value_mp
                                          //  Referenced by: '<S365>/Constant'

  int8_T Constant2_Value_k;            // Computed Parameter: Constant2_Value_k
                                          //  Referenced by: '<S365>/Constant2'

  int8_T Constant3_Value_i;            // Computed Parameter: Constant3_Value_i
                                          //  Referenced by: '<S365>/Constant3'

  int8_T Constant4_Value_j;            // Computed Parameter: Constant4_Value_j
                                          //  Referenced by: '<S365>/Constant4'

  int8_T Constant_Value_dt;            // Computed Parameter: Constant_Value_dt
                                          //  Referenced by: '<S420>/Constant'

  int8_T Constant2_Value_l;            // Computed Parameter: Constant2_Value_l
                                          //  Referenced by: '<S420>/Constant2'

  int8_T Constant3_Value_j;            // Computed Parameter: Constant3_Value_j
                                          //  Referenced by: '<S420>/Constant3'

  int8_T Constant4_Value_c;            // Computed Parameter: Constant4_Value_c
                                          //  Referenced by: '<S420>/Constant4'

  int8_T Constant_Value_d5;            // Computed Parameter: Constant_Value_d5
                                          //  Referenced by: '<S472>/Constant'

  int8_T Constant2_Value_e;            // Computed Parameter: Constant2_Value_e
                                          //  Referenced by: '<S472>/Constant2'

  int8_T Constant3_Value_k;            // Computed Parameter: Constant3_Value_k
                                          //  Referenced by: '<S472>/Constant3'

  int8_T Constant4_Value_n;            // Computed Parameter: Constant4_Value_n
                                          //  Referenced by: '<S472>/Constant4'

  int8_T Constant_Value_km;            // Computed Parameter: Constant_Value_km
                                          //  Referenced by: '<S524>/Constant'

  int8_T Constant2_Value_m;            // Computed Parameter: Constant2_Value_m
                                          //  Referenced by: '<S524>/Constant2'

  int8_T Constant3_Value_d;            // Computed Parameter: Constant3_Value_d
                                          //  Referenced by: '<S524>/Constant3'

  int8_T Constant4_Value_b;            // Computed Parameter: Constant4_Value_b
                                          //  Referenced by: '<S524>/Constant4'

  uint8_T Constant_Value_fm;           // Computed Parameter: Constant_Value_fm
                                          //  Referenced by: '<S572>/Constant'

  uint8_T Constant6_Value;             // Computed Parameter: Constant6_Value
                                          //  Referenced by: '<S580>/Constant6'

};

// Real-time Model Data Structure
struct tag_RTM_SITL_HEXA_Hovering_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_SITL_HEXA_Hovering_T SITL_HEXA_Hovering_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_SITL_HEXA_Hovering_T SITL_HEXA_Hovering_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_SITL_HEXA_Hovering_T SITL_HEXA_Hovering_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void SITL_HEXA_Hovering_initialize(void);
  extern void SITL_HEXA_Hovering_step(void);
  extern void SITL_HEXA_Hovering_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_SITL_HEXA_Hovering_T *const SITL_HEXA_Hovering_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S189>/Data Type Duplicate' : Unused code path elimination
//  Block '<S189>/Data Type Propagation' : Unused code path elimination
//  Block '<S575>/Compare' : Unused code path elimination
//  Block '<S575>/Constant' : Unused code path elimination
//  Block '<S576>/NOT' : Unused code path elimination
//  Block '<S571>/Subtract' : Unused code path elimination
//  Block '<S573>/NOT' : Unused code path elimination
//  Block '<S574>/NOT' : Unused code path elimination
//  Block '<S597>/Compare' : Unused code path elimination
//  Block '<S597>/Constant' : Unused code path elimination
//  Block '<S594>/Bitwise Operator' : Unused code path elimination
//  Block '<S594>/Data Type Conversion' : Unused code path elimination
//  Block '<S594>/Data Type Conversion1' : Unused code path elimination
//  Block '<S594>/Data Type Conversion2' : Unused code path elimination
//  Block '<S594>/Gain' : Unused code path elimination
//  Block '<S594>/Gain1' : Unused code path elimination
//  Block '<S598>/NOT' : Unused code path elimination
//  Block '<S602>/NOT' : Unused code path elimination
//  Block '<S603>/NOT' : Unused code path elimination
//  Block '<S604>/NOT' : Unused code path elimination
//  Block '<S605>/NOT' : Unused code path elimination
//  Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S557>/Reshape1' : Reshape block reduction
//  Block '<S4>/Data Type Conversion3' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'SITL_HEXA_Hovering'
//  '<S1>'   : 'SITL_HEXA_Hovering/CLAW'
//  '<S2>'   : 'SITL_HEXA_Hovering/Navigation'
//  '<S3>'   : 'SITL_HEXA_Hovering/actuatorOutputs'
//  '<S4>'   : 'SITL_HEXA_Hovering/uORBInput'
//  '<S5>'   : 'SITL_HEXA_Hovering/CLAW/Controller'
//  '<S6>'   : 'SITL_HEXA_Hovering/CLAW/Controller/Publish vehicle_attitude_setpoint'
//  '<S7>'   : 'SITL_HEXA_Hovering/CLAW/Controller/Publish vehicle_local_position_setpoint'
//  '<S8>'   : 'SITL_HEXA_Hovering/CLAW/Controller/Publish vehicle_rate_setpoint'
//  '<S9>'   : 'SITL_HEXA_Hovering/CLAW/Controller/Quaternion Validity Check'
//  '<S10>'  : 'SITL_HEXA_Hovering/CLAW/Controller/Quaternions to Rotation Angles'
//  '<S11>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller'
//  '<S12>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller'
//  '<S13>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller'
//  '<S14>'  : 'SITL_HEXA_Hovering/CLAW/Controller/Publish vehicle_attitude_setpoint/PX4 uORB Message'
//  '<S15>'  : 'SITL_HEXA_Hovering/CLAW/Controller/Publish vehicle_attitude_setpoint/PX4 uORB Write'
//  '<S16>'  : 'SITL_HEXA_Hovering/CLAW/Controller/Publish vehicle_local_position_setpoint/PX4 uORB Message'
//  '<S17>'  : 'SITL_HEXA_Hovering/CLAW/Controller/Publish vehicle_local_position_setpoint/PX4 uORB Write'
//  '<S18>'  : 'SITL_HEXA_Hovering/CLAW/Controller/Publish vehicle_rate_setpoint/PX4 uORB Message'
//  '<S19>'  : 'SITL_HEXA_Hovering/CLAW/Controller/Publish vehicle_rate_setpoint/PX4 uORB Write'
//  '<S20>'  : 'SITL_HEXA_Hovering/CLAW/Controller/Quaternion Validity Check/Quaternion Norm'
//  '<S21>'  : 'SITL_HEXA_Hovering/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation'
//  '<S22>'  : 'SITL_HEXA_Hovering/CLAW/Controller/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S23>'  : 'SITL_HEXA_Hovering/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S24>'  : 'SITL_HEXA_Hovering/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S25>'  : 'SITL_HEXA_Hovering/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S26>'  : 'SITL_HEXA_Hovering/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S27>'  : 'SITL_HEXA_Hovering/CLAW/Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S28>'  : 'SITL_HEXA_Hovering/CLAW/Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S29>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/Calculate minimum Turn'
//  '<S30>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3'
//  '<S31>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4'
//  '<S32>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5'
//  '<S33>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Anti-windup'
//  '<S34>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/D Gain'
//  '<S35>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/External Derivative'
//  '<S36>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Filter'
//  '<S37>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Filter ICs'
//  '<S38>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/I Gain'
//  '<S39>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Ideal P Gain'
//  '<S40>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Ideal P Gain Fdbk'
//  '<S41>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Integrator'
//  '<S42>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Integrator ICs'
//  '<S43>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/N Copy'
//  '<S44>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/N Gain'
//  '<S45>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/P Copy'
//  '<S46>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Parallel P Gain'
//  '<S47>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Reset Signal'
//  '<S48>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Saturation'
//  '<S49>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Saturation Fdbk'
//  '<S50>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Sum'
//  '<S51>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Sum Fdbk'
//  '<S52>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Tracking Mode'
//  '<S53>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Tracking Mode Sum'
//  '<S54>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Tsamp - Integral'
//  '<S55>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Tsamp - Ngain'
//  '<S56>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/postSat Signal'
//  '<S57>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/preSat Signal'
//  '<S58>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Anti-windup/Disabled'
//  '<S59>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/D Gain/Disabled'
//  '<S60>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/External Derivative/Disabled'
//  '<S61>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Filter/Disabled'
//  '<S62>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Filter ICs/Disabled'
//  '<S63>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/I Gain/Disabled'
//  '<S64>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Ideal P Gain/Passthrough'
//  '<S65>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S66>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Integrator/Disabled'
//  '<S67>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Integrator ICs/Disabled'
//  '<S68>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S69>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/N Gain/Disabled'
//  '<S70>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/P Copy/Disabled'
//  '<S71>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S72>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Reset Signal/Disabled'
//  '<S73>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Saturation/Passthrough'
//  '<S74>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Saturation Fdbk/Disabled'
//  '<S75>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Sum/Passthrough_P'
//  '<S76>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Sum Fdbk/Disabled'
//  '<S77>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Tracking Mode/Disabled'
//  '<S78>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S79>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S80>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S81>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/postSat Signal/Forward_Path'
//  '<S82>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller3/preSat Signal/Forward_Path'
//  '<S83>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Anti-windup'
//  '<S84>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/D Gain'
//  '<S85>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/External Derivative'
//  '<S86>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Filter'
//  '<S87>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Filter ICs'
//  '<S88>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/I Gain'
//  '<S89>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Ideal P Gain'
//  '<S90>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S91>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Integrator'
//  '<S92>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Integrator ICs'
//  '<S93>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/N Copy'
//  '<S94>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/N Gain'
//  '<S95>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/P Copy'
//  '<S96>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Parallel P Gain'
//  '<S97>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Reset Signal'
//  '<S98>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Saturation'
//  '<S99>'  : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Saturation Fdbk'
//  '<S100>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Sum'
//  '<S101>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Sum Fdbk'
//  '<S102>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Tracking Mode'
//  '<S103>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Tracking Mode Sum'
//  '<S104>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Tsamp - Integral'
//  '<S105>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Tsamp - Ngain'
//  '<S106>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/postSat Signal'
//  '<S107>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/preSat Signal'
//  '<S108>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Anti-windup/Disabled'
//  '<S109>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/D Gain/Disabled'
//  '<S110>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/External Derivative/Disabled'
//  '<S111>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Filter/Disabled'
//  '<S112>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Filter ICs/Disabled'
//  '<S113>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/I Gain/Disabled'
//  '<S114>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S115>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S116>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Integrator/Disabled'
//  '<S117>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Integrator ICs/Disabled'
//  '<S118>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S119>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/N Gain/Disabled'
//  '<S120>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/P Copy/Disabled'
//  '<S121>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S122>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Reset Signal/Disabled'
//  '<S123>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Saturation/Passthrough'
//  '<S124>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S125>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Sum/Passthrough_P'
//  '<S126>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S127>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Tracking Mode/Disabled'
//  '<S128>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S129>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S130>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S131>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S132>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S133>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Anti-windup'
//  '<S134>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/D Gain'
//  '<S135>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/External Derivative'
//  '<S136>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Filter'
//  '<S137>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Filter ICs'
//  '<S138>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/I Gain'
//  '<S139>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Ideal P Gain'
//  '<S140>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Ideal P Gain Fdbk'
//  '<S141>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Integrator'
//  '<S142>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Integrator ICs'
//  '<S143>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/N Copy'
//  '<S144>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/N Gain'
//  '<S145>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/P Copy'
//  '<S146>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Parallel P Gain'
//  '<S147>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Reset Signal'
//  '<S148>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Saturation'
//  '<S149>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Saturation Fdbk'
//  '<S150>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Sum'
//  '<S151>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Sum Fdbk'
//  '<S152>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Tracking Mode'
//  '<S153>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Tracking Mode Sum'
//  '<S154>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Tsamp - Integral'
//  '<S155>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Tsamp - Ngain'
//  '<S156>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/postSat Signal'
//  '<S157>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/preSat Signal'
//  '<S158>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Anti-windup/Disabled'
//  '<S159>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/D Gain/Disabled'
//  '<S160>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/External Derivative/Disabled'
//  '<S161>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Filter/Disabled'
//  '<S162>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Filter ICs/Disabled'
//  '<S163>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/I Gain/Disabled'
//  '<S164>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Ideal P Gain/Passthrough'
//  '<S165>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Ideal P Gain Fdbk/Disabled'
//  '<S166>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Integrator/Disabled'
//  '<S167>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Integrator ICs/Disabled'
//  '<S168>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/N Copy/Disabled wSignal Specification'
//  '<S169>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/N Gain/Disabled'
//  '<S170>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/P Copy/Disabled'
//  '<S171>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Parallel P Gain/Internal Parameters'
//  '<S172>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Reset Signal/Disabled'
//  '<S173>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Saturation/Enabled'
//  '<S174>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Saturation Fdbk/Disabled'
//  '<S175>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Sum/Passthrough_P'
//  '<S176>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Sum Fdbk/Disabled'
//  '<S177>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Tracking Mode/Disabled'
//  '<S178>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Tracking Mode Sum/Passthrough'
//  '<S179>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Tsamp - Integral/TsSignalSpecification'
//  '<S180>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/Tsamp - Ngain/Passthrough'
//  '<S181>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/postSat Signal/Forward_Path'
//  '<S182>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_att_controller/PID Controller5/preSat Signal/Forward_Path'
//  '<S183>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/Altitude Signal conditioning'
//  '<S184>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/Calculate Transformation Matrix'
//  '<S185>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller'
//  '<S186>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1'
//  '<S187>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude'
//  '<S188>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz'
//  '<S189>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/Altitude Signal conditioning/Saturation Dynamic'
//  '<S190>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Anti-windup'
//  '<S191>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/D Gain'
//  '<S192>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/External Derivative'
//  '<S193>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Filter'
//  '<S194>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Filter ICs'
//  '<S195>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/I Gain'
//  '<S196>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Ideal P Gain'
//  '<S197>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Ideal P Gain Fdbk'
//  '<S198>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Integrator'
//  '<S199>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Integrator ICs'
//  '<S200>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/N Copy'
//  '<S201>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/N Gain'
//  '<S202>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/P Copy'
//  '<S203>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Parallel P Gain'
//  '<S204>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Reset Signal'
//  '<S205>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Saturation'
//  '<S206>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Saturation Fdbk'
//  '<S207>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Sum'
//  '<S208>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Sum Fdbk'
//  '<S209>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Tracking Mode'
//  '<S210>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Tracking Mode Sum'
//  '<S211>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Tsamp - Integral'
//  '<S212>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Tsamp - Ngain'
//  '<S213>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/postSat Signal'
//  '<S214>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/preSat Signal'
//  '<S215>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Anti-windup/Disabled'
//  '<S216>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/D Gain/Disabled'
//  '<S217>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/External Derivative/Disabled'
//  '<S218>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Filter/Disabled'
//  '<S219>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Filter ICs/Disabled'
//  '<S220>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/I Gain/Disabled'
//  '<S221>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S222>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S223>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Integrator/Disabled'
//  '<S224>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Integrator ICs/Disabled'
//  '<S225>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S226>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/N Gain/Disabled'
//  '<S227>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/P Copy/Disabled'
//  '<S228>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S229>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Reset Signal/Disabled'
//  '<S230>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Saturation/Enabled'
//  '<S231>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S232>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Sum/Passthrough_P'
//  '<S233>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Sum Fdbk/Disabled'
//  '<S234>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Tracking Mode/Disabled'
//  '<S235>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S236>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S237>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S238>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/postSat Signal/Forward_Path'
//  '<S239>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller/preSat Signal/Forward_Path'
//  '<S240>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Anti-windup'
//  '<S241>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/D Gain'
//  '<S242>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/External Derivative'
//  '<S243>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Filter'
//  '<S244>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Filter ICs'
//  '<S245>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/I Gain'
//  '<S246>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Ideal P Gain'
//  '<S247>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S248>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Integrator'
//  '<S249>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Integrator ICs'
//  '<S250>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/N Copy'
//  '<S251>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/N Gain'
//  '<S252>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/P Copy'
//  '<S253>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Parallel P Gain'
//  '<S254>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Reset Signal'
//  '<S255>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Saturation'
//  '<S256>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Saturation Fdbk'
//  '<S257>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Sum'
//  '<S258>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Sum Fdbk'
//  '<S259>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Tracking Mode'
//  '<S260>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Tracking Mode Sum'
//  '<S261>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Tsamp - Integral'
//  '<S262>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Tsamp - Ngain'
//  '<S263>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/postSat Signal'
//  '<S264>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/preSat Signal'
//  '<S265>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Anti-windup/Disabled'
//  '<S266>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/D Gain/Disabled'
//  '<S267>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/External Derivative/Disabled'
//  '<S268>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Filter/Disabled'
//  '<S269>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Filter ICs/Disabled'
//  '<S270>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/I Gain/Disabled'
//  '<S271>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S272>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S273>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Integrator/Disabled'
//  '<S274>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Integrator ICs/Disabled'
//  '<S275>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S276>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/N Gain/Disabled'
//  '<S277>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/P Copy/Disabled'
//  '<S278>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S279>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Reset Signal/Disabled'
//  '<S280>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Saturation/Enabled'
//  '<S281>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S282>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Sum/Passthrough_P'
//  '<S283>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S284>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Tracking Mode/Disabled'
//  '<S285>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S286>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S287>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S288>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S289>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S290>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Anti-windup'
//  '<S291>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/D Gain'
//  '<S292>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/External Derivative'
//  '<S293>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Filter'
//  '<S294>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Filter ICs'
//  '<S295>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/I Gain'
//  '<S296>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Ideal P Gain'
//  '<S297>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S298>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Integrator'
//  '<S299>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Integrator ICs'
//  '<S300>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/N Copy'
//  '<S301>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/N Gain'
//  '<S302>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/P Copy'
//  '<S303>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Parallel P Gain'
//  '<S304>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Reset Signal'
//  '<S305>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Saturation'
//  '<S306>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Saturation Fdbk'
//  '<S307>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Sum'
//  '<S308>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Sum Fdbk'
//  '<S309>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Tracking Mode'
//  '<S310>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Tracking Mode Sum'
//  '<S311>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Tsamp - Integral'
//  '<S312>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Tsamp - Ngain'
//  '<S313>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/postSat Signal'
//  '<S314>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/preSat Signal'
//  '<S315>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Anti-windup/Disabled'
//  '<S316>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/D Gain/Disabled'
//  '<S317>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/External Derivative/Disabled'
//  '<S318>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Filter/Disabled'
//  '<S319>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Filter ICs/Disabled'
//  '<S320>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/I Gain/Disabled'
//  '<S321>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S322>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Ideal P Gain Fdbk/Disabled'
//  '<S323>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Integrator/Disabled'
//  '<S324>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Integrator ICs/Disabled'
//  '<S325>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/N Copy/Disabled wSignal Specification'
//  '<S326>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/N Gain/Disabled'
//  '<S327>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/P Copy/Disabled'
//  '<S328>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Parallel P Gain/Internal Parameters'
//  '<S329>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Reset Signal/Disabled'
//  '<S330>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Saturation/Enabled'
//  '<S331>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Saturation Fdbk/Disabled'
//  '<S332>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Sum/Passthrough_P'
//  '<S333>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Sum Fdbk/Disabled'
//  '<S334>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S335>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S336>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S337>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S338>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/postSat Signal/Forward_Path'
//  '<S339>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_Altitude/preSat Signal/Forward_Path'
//  '<S340>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Anti-windup'
//  '<S341>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/D Gain'
//  '<S342>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/External Derivative'
//  '<S343>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Filter'
//  '<S344>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Filter ICs'
//  '<S345>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/I Gain'
//  '<S346>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Ideal P Gain'
//  '<S347>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Ideal P Gain Fdbk'
//  '<S348>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Integrator'
//  '<S349>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Integrator ICs'
//  '<S350>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/N Copy'
//  '<S351>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/N Gain'
//  '<S352>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/P Copy'
//  '<S353>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Parallel P Gain'
//  '<S354>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Reset Signal'
//  '<S355>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Saturation'
//  '<S356>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Saturation Fdbk'
//  '<S357>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Sum'
//  '<S358>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Sum Fdbk'
//  '<S359>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Tracking Mode'
//  '<S360>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Tracking Mode Sum'
//  '<S361>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Tsamp - Integral'
//  '<S362>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Tsamp - Ngain'
//  '<S363>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/postSat Signal'
//  '<S364>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/preSat Signal'
//  '<S365>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Anti-windup/Disc. Clamping Parallel'
//  '<S366>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S367>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S368>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/D Gain/Internal Parameters'
//  '<S369>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/External Derivative/Error'
//  '<S370>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Filter/Disc. Forward Euler Filter'
//  '<S371>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Filter ICs/Internal IC - Filter'
//  '<S372>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/I Gain/Internal Parameters'
//  '<S373>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Ideal P Gain/Passthrough'
//  '<S374>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Ideal P Gain Fdbk/Passthrough'
//  '<S375>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Integrator/Discrete'
//  '<S376>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Integrator ICs/Internal IC'
//  '<S377>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/N Copy/Disabled'
//  '<S378>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/N Gain/Internal Parameters'
//  '<S379>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/P Copy/Disabled'
//  '<S380>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Parallel P Gain/Internal Parameters'
//  '<S381>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Reset Signal/Disabled'
//  '<S382>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Saturation/Enabled'
//  '<S383>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Saturation Fdbk/Passthrough'
//  '<S384>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Sum/Sum_PID'
//  '<S385>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Sum Fdbk/Enabled'
//  '<S386>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Tracking Mode/Disabled'
//  '<S387>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Tracking Mode Sum/Passthrough'
//  '<S388>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Tsamp - Integral/TsSignalSpecification'
//  '<S389>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/Tsamp - Ngain/Passthrough'
//  '<S390>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/postSat Signal/Feedback_Path'
//  '<S391>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_pos_controller/PID_vz/preSat Signal/Feedback_Path'
//  '<S392>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller'
//  '<S393>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1'
//  '<S394>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2'
//  '<S395>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Anti-windup'
//  '<S396>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/D Gain'
//  '<S397>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/External Derivative'
//  '<S398>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Filter'
//  '<S399>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Filter ICs'
//  '<S400>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/I Gain'
//  '<S401>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Ideal P Gain'
//  '<S402>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Ideal P Gain Fdbk'
//  '<S403>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Integrator'
//  '<S404>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Integrator ICs'
//  '<S405>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/N Copy'
//  '<S406>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/N Gain'
//  '<S407>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/P Copy'
//  '<S408>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Parallel P Gain'
//  '<S409>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Reset Signal'
//  '<S410>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Saturation'
//  '<S411>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Saturation Fdbk'
//  '<S412>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Sum'
//  '<S413>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Sum Fdbk'
//  '<S414>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Tracking Mode'
//  '<S415>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Tracking Mode Sum'
//  '<S416>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Tsamp - Integral'
//  '<S417>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Tsamp - Ngain'
//  '<S418>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/postSat Signal'
//  '<S419>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/preSat Signal'
//  '<S420>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S421>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S422>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S423>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/D Gain/Internal Parameters'
//  '<S424>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/External Derivative/Error'
//  '<S425>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S426>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S427>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/I Gain/Internal Parameters'
//  '<S428>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S429>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S430>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Integrator/Discrete'
//  '<S431>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Integrator ICs/Internal IC'
//  '<S432>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/N Copy/Disabled'
//  '<S433>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/N Gain/Internal Parameters'
//  '<S434>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/P Copy/Disabled'
//  '<S435>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S436>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Reset Signal/Disabled'
//  '<S437>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Saturation/Enabled'
//  '<S438>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S439>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Sum/Sum_PID'
//  '<S440>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Sum Fdbk/Disabled'
//  '<S441>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Tracking Mode/Disabled'
//  '<S442>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S443>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S444>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S445>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/postSat Signal/Forward_Path'
//  '<S446>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller/preSat Signal/Forward_Path'
//  '<S447>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Anti-windup'
//  '<S448>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/D Gain'
//  '<S449>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/External Derivative'
//  '<S450>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Filter'
//  '<S451>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Filter ICs'
//  '<S452>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/I Gain'
//  '<S453>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Ideal P Gain'
//  '<S454>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S455>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Integrator'
//  '<S456>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Integrator ICs'
//  '<S457>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/N Copy'
//  '<S458>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/N Gain'
//  '<S459>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/P Copy'
//  '<S460>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Parallel P Gain'
//  '<S461>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Reset Signal'
//  '<S462>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Saturation'
//  '<S463>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Saturation Fdbk'
//  '<S464>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Sum'
//  '<S465>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Sum Fdbk'
//  '<S466>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Tracking Mode'
//  '<S467>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Tracking Mode Sum'
//  '<S468>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Tsamp - Integral'
//  '<S469>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Tsamp - Ngain'
//  '<S470>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/postSat Signal'
//  '<S471>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/preSat Signal'
//  '<S472>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S473>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S474>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S475>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/D Gain/Internal Parameters'
//  '<S476>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/External Derivative/Error'
//  '<S477>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S478>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S479>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/I Gain/Internal Parameters'
//  '<S480>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S481>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S482>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Integrator/Discrete'
//  '<S483>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Integrator ICs/Internal IC'
//  '<S484>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/N Copy/Disabled'
//  '<S485>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/N Gain/Internal Parameters'
//  '<S486>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/P Copy/Disabled'
//  '<S487>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S488>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Reset Signal/Disabled'
//  '<S489>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Saturation/Enabled'
//  '<S490>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S491>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Sum/Sum_PID'
//  '<S492>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S493>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Tracking Mode/Disabled'
//  '<S494>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S495>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S496>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S497>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S498>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S499>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Anti-windup'
//  '<S500>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/D Gain'
//  '<S501>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/External Derivative'
//  '<S502>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Filter'
//  '<S503>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Filter ICs'
//  '<S504>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/I Gain'
//  '<S505>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Ideal P Gain'
//  '<S506>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Ideal P Gain Fdbk'
//  '<S507>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Integrator'
//  '<S508>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Integrator ICs'
//  '<S509>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/N Copy'
//  '<S510>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/N Gain'
//  '<S511>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/P Copy'
//  '<S512>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Parallel P Gain'
//  '<S513>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Reset Signal'
//  '<S514>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Saturation'
//  '<S515>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Saturation Fdbk'
//  '<S516>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Sum'
//  '<S517>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Sum Fdbk'
//  '<S518>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Tracking Mode'
//  '<S519>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Tracking Mode Sum'
//  '<S520>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Tsamp - Integral'
//  '<S521>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Tsamp - Ngain'
//  '<S522>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/postSat Signal'
//  '<S523>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/preSat Signal'
//  '<S524>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S525>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S526>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S527>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/D Gain/Internal Parameters'
//  '<S528>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/External Derivative/Error'
//  '<S529>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S530>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S531>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/I Gain/Internal Parameters'
//  '<S532>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Ideal P Gain/Passthrough'
//  '<S533>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S534>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Integrator/Discrete'
//  '<S535>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Integrator ICs/Internal IC'
//  '<S536>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/N Copy/Disabled'
//  '<S537>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/N Gain/Internal Parameters'
//  '<S538>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/P Copy/Disabled'
//  '<S539>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S540>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Reset Signal/Disabled'
//  '<S541>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Saturation/Enabled'
//  '<S542>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Saturation Fdbk/Disabled'
//  '<S543>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Sum/Sum_PID'
//  '<S544>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Sum Fdbk/Disabled'
//  '<S545>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Tracking Mode/Disabled'
//  '<S546>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S547>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S548>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S549>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/postSat Signal/Forward_Path'
//  '<S550>' : 'SITL_HEXA_Hovering/CLAW/Controller/mc_rate_controller/PID Controller2/preSat Signal/Forward_Path'
//  '<S551>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm'
//  '<S552>' : 'SITL_HEXA_Hovering/Navigation/uORB Publish'
//  '<S553>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission'
//  '<S554>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem'
//  '<S555>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC'
//  '<S556>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE'
//  '<S557>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land'
//  '<S558>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off'
//  '<S559>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint'
//  '<S560>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE'
//  '<S561>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE/Enabled Subsystem2'
//  '<S562>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land'
//  '<S563>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land'
//  '<S564>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land/Enabled Subsystem'
//  '<S565>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land/Enabled Subsystem2'
//  '<S566>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Ensure smooth ascend during Takeoff'
//  '<S567>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff'
//  '<S568>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff/Enabled Subsystem2'
//  '<S569>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning'
//  '<S570>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning/Compare To Constant'
//  '<S571>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC'
//  '<S572>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC'
//  '<S573>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead'
//  '<S574>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead'
//  '<S575>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/Compare To Constant'
//  '<S576>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read'
//  '<S577>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read/Enabled Subsystem'
//  '<S578>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint'
//  '<S579>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_WayPoint'
//  '<S580>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Empty_WayPoint'
//  '<S581>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Next_WayPoint'
//  '<S582>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Message'
//  '<S583>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Write'
//  '<S584>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP'
//  '<S585>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem'
//  '<S586>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem1'
//  '<S587>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem2'
//  '<S588>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead/Enabled Subsystem'
//  '<S589>' : 'SITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead/Enabled Subsystem'
//  '<S590>' : 'SITL_HEXA_Hovering/Navigation/uORB Publish/PX4 uORB Message'
//  '<S591>' : 'SITL_HEXA_Hovering/Navigation/uORB Publish/PX4 uORB Write'
//  '<S592>' : 'SITL_HEXA_Hovering/actuatorOutputs/Fault Injection Module'
//  '<S593>' : 'SITL_HEXA_Hovering/actuatorOutputs/MATLAB Function'
//  '<S594>' : 'SITL_HEXA_Hovering/actuatorOutputs/Radio Control Transmitter'
//  '<S595>' : 'SITL_HEXA_Hovering/actuatorOutputs/uORB_actuator_outputs'
//  '<S596>' : 'SITL_HEXA_Hovering/actuatorOutputs/Fault Injection Module/Fault_Injection_SIL'
//  '<S597>' : 'SITL_HEXA_Hovering/actuatorOutputs/Fault Injection Module/Fault_Injection_SIL/Compare To Constant'
//  '<S598>' : 'SITL_HEXA_Hovering/actuatorOutputs/Radio Control Transmitter/PX4 uORB Read'
//  '<S599>' : 'SITL_HEXA_Hovering/actuatorOutputs/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S600>' : 'SITL_HEXA_Hovering/actuatorOutputs/uORB_actuator_outputs/PX4 uORB Message'
//  '<S601>' : 'SITL_HEXA_Hovering/actuatorOutputs/uORB_actuator_outputs/PX4 uORB Write'
//  '<S602>' : 'SITL_HEXA_Hovering/uORBInput/PX4 uORB Read1'
//  '<S603>' : 'SITL_HEXA_Hovering/uORBInput/PX4 uORB Read2'
//  '<S604>' : 'SITL_HEXA_Hovering/uORBInput/vehicle_attitude'
//  '<S605>' : 'SITL_HEXA_Hovering/uORBInput/vehicle_local_pos'
//  '<S606>' : 'SITL_HEXA_Hovering/uORBInput/PX4 uORB Read1/Enabled Subsystem'
//  '<S607>' : 'SITL_HEXA_Hovering/uORBInput/PX4 uORB Read2/Enabled Subsystem'
//  '<S608>' : 'SITL_HEXA_Hovering/uORBInput/vehicle_attitude/Enabled Subsystem'
//  '<S609>' : 'SITL_HEXA_Hovering/uORBInput/vehicle_local_pos/Enabled Subsystem'

#endif                                 // SITL_HEXA_Hovering_h_

//
// File trailer for generated code.
//
// [EOF]
//
