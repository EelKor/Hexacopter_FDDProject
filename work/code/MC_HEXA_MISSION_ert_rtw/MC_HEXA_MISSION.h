//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MC_HEXA_MISSION.h
//
// Code generated for Simulink model 'MC_HEXA_MISSION'.
//
// Model version                  : 4.139
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Aug 10 19:48:00 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_MC_HEXA_MISSION_h_
#define RTW_HEADER_MC_HEXA_MISSION_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "MC_HEXA_MISSION_types.h"
#include <uORB/topics/vehicle_trajectory_waypoint.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/position_setpoint_triplet.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/vehicle_local_position_setpoint.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/vehicle_attitude_setpoint.h>
#include <uORB/topics/trajectory_waypoint.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/home_position.h>
#include <uORB/topics/vehicle_rates_setpoint.h>
#include <uORB/topics/actuator_armed.h>

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

// Block signals for system '<S24>/PX4 Timestamp'
struct B_PX4Timestamp_MC_HEXA_MISSION_T {
  uint64_T PX4Timestamp;               // '<S24>/PX4 Timestamp'
};

// Block states (default storage) for system '<S24>/PX4 Timestamp'
struct DW_PX4Timestamp_MC_HEXA_MISSION_T {
  px4_internal_block_getPX4AbsoluteTime_MC_HEXA_MISSION_T obj;// '<S24>/PX4 Timestamp' 
  boolean_T objisempty;                // '<S24>/PX4 Timestamp'
};

// Block signals for system '<S583>/MATLAB System'
struct B_MATLABSystem_MC_HEXA_MISSION_T {
  real32_T MATLABSystem[3];            // '<S583>/MATLAB System'
  real_T dLat;
};

// Block states (default storage) for system '<S583>/MATLAB System'
struct DW_MATLABSystem_MC_HEXA_MISSION_T {
  px4_internal_block_LLA2LocalCoordinatesNED_MC_HEXA_MISSION_T obj;// '<S583>/MATLAB System' 
  boolean_T objisempty;                // '<S583>/MATLAB System'
};

// Block signals (default storage)
struct B_MC_HEXA_MISSION_T {
  px4_Bus_vehicle_trajectory_waypoint In1;// '<S582>/In1'
  px4_Bus_vehicle_trajectory_waypoint b_varargout_2;
  px4_Bus_vehicle_trajectory_waypoint BusAssignment1;// '<S577>/Bus Assignment1' 
  px4_Bus_vehicle_trajectory_waypoint BusAssignment1_m;// '<S577>/Bus Assignment1' 
  px4_Bus_vehicle_odometry In1_l;      // '<S601>/In1'
  px4_Bus_vehicle_odometry b_varargout_2_c;
  px4_Bus_position_setpoint_triplet In1_p;// '<S594>/In1'
  px4_Bus_position_setpoint_triplet b_varargout_2_k;
  px4_Bus_vehicle_local_position In1_c;// '<S604>/In1'
  px4_Bus_vehicle_local_position b_varargout_2_cx;
  px4_Bus_actuator_outputs BusAssignment_l;// '<S10>/Bus Assignment'
  px4_Bus_actuator_outputs BusAssignment_l_b;// '<S10>/Bus Assignment'
  px4_Bus_vehicle_local_position_setpoint BusAssignment_m;// '<S557>/Bus Assignment' 
  px4_Bus_vehicle_local_position_setpoint BusAssignment_m_p;// '<S557>/Bus Assignment' 
  px4_Bus_input_rc In1_k;              // '<S20>/In1'
  px4_Bus_input_rc b_varargout_2_cv;
  real_T b_waypointsIn_data[9];
  real_T MatrixConcatenate_p[9];       // '<S564>/Matrix Concatenate'
  px4_Bus_vehicle_attitude_setpoint BusAssignment_h;// '<S24>/Bus Assignment'
  px4_Bus_vehicle_attitude_setpoint BusAssignment_h_f;// '<S24>/Bus Assignment'
  px4_Bus_trajectory_waypoint BusAssignment1_f;// '<S585>/Bus Assignment1'
  px4_Bus_vehicle_attitude In1_m;      // '<S603>/In1'
  px4_Bus_vehicle_attitude b_varargout_2_g;
  px4_Bus_home_position In1_f;         // '<S593>/In1'
  px4_Bus_home_position b_varargout_2_g1;
  px4_Bus_vehicle_rates_setpoint BusAssignment_h4;// '<S25>/Bus Assignment'
  real_T b_varargout_3[3];
  real_T lla0[3];
  real_T MatrixConcatenate1[3];        // '<S583>/Matrix Concatenate1'
  real_T MatrixConcatenate1_k[3];      // '<S577>/Matrix Concatenate1'
  real_T rtb_CastToDouble_m[3];
  px4_Bus_actuator_armed In1_b;        // '<S602>/In1'
  real_T Merge[4];                     // '<S559>/Merge'
  real_T VectorConcatenate[3];         // '<S36>/Vector Concatenate'
  px4_Bus_actuator_armed b_varargout_2_n;
  real_T desiredZ;                     // '<S23>/Gain'
  real_T yaw_In;                       // '<S566>/yaw_In'
  real_T yaw_In_i;                     // '<S570>/yaw_In'
  real_T In;                           // '<S569>/In'
  real_T yaw_In_ik;                    // '<S573>/yaw_In'
  real_T Saturation;                   // '<S446>/Saturation'
  real_T Saturation_c;                 // '<S496>/Saturation'
  real_T Saturation_b;                 // '<S546>/Saturation'
  real_T Saturation_d;                 // '<S393>/Saturation'
  real_T Switch2[2];                   // '<S245>/Switch2'
  real_T Gain1;                        // '<S29>/Gain1'
  real_T Switch2_o;                    // '<S188>/Switch2'
  real_T Switch2_l;                    // '<S90>/Switch2'
  real_T Switch2_n;                    // '<S139>/Switch2'
  real_T PProdOut_pm;                  // '<S340>/PProd Out'
  real_T SinCos_o2;                    // '<S199>/SinCos'
  real_T IProdOut;                     // '<S536>/IProd Out'
  real_T Gain_i;                       // '<S571>/Gain'
  real_T Sum_f;                        // '<S571>/Sum'
  real_T Switch2_a;                    // '<S6>/Switch2'
  real_T Switch1_d;                    // '<S6>/Switch1'
  real_T Gain2_g;                      // '<S5>/Gain2'
  real_T Gain3;                        // '<S5>/Gain3'
  real_T Saturation1;                  // '<S12>/Saturation1'
  real_T rtb_CastToDouble_idx_0;
  real_T rtb_CastToDouble_idx_1;
  real_T u0;
  real_T dLat;
  real_T dLon;
  real_T flat;
  real_T absx;
  real_T r;
  real_T flat_tmp;
  real_T absx_p;
  real_T q;
  real_T scale;
  real_T absxk;
  real_T t;
  boolean_T x[6];
  real32_T ParamStep;
  int32_T ParamStep_l;
  int32_T ParamStep_j;
  int32_T iy;
  int32_T i1;
  int32_T j;
  int32_T ix;
  int32_T b_exponent;
  int32_T waypoints_data_tmp;
  int32_T b_k;
  int32_T i;
  int32_T i1_d;
  int8_T tmp_data[3];
  boolean_T distinctWptsIdx[3];
  boolean_T b[3];
  boolean_T IsNaN_l[2];                // '<S562>/IsNaN'
  int8_T rtPrevAction;
  int8_T rtAction;
  boolean_T Compare_k;                 // '<S11>/Compare'
  boolean_T OR_g;                      // '<S562>/OR'
  boolean_T Compare;                   // '<S18>/Compare'
  boolean_T latp2;
  B_PX4Timestamp_MC_HEXA_MISSION_T PX4Timestamp_pn;// '<S24>/PX4 Timestamp'
  B_MATLABSystem_MC_HEXA_MISSION_T MATLABSystem_b;// '<S583>/MATLAB System'
  B_MATLABSystem_MC_HEXA_MISSION_T MATLABSystem;// '<S583>/MATLAB System'
  B_PX4Timestamp_MC_HEXA_MISSION_T PX4Timestamp_o;// '<S24>/PX4 Timestamp'
  B_PX4Timestamp_MC_HEXA_MISSION_T PX4Timestamp_p;// '<S24>/PX4 Timestamp'
  B_PX4Timestamp_MC_HEXA_MISSION_T PX4Timestamp;// '<S24>/PX4 Timestamp'
};

// Block states (default storage) for system '<Root>'
struct DW_MC_HEXA_MISSION_T {
  uav_sluav_internal_system_WaypointFollower_MC_HEXA_MISSION_T obj;// '<S564>/UAV Waypoint Follower' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_b;// '<S591>/Read Parameter' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_g;// '<S592>/Read Parameter' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_k;// '<S560>/Read Parameter' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_n;// '<S30>/Read Parameter24' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_f;// '<S30>/Read Parameter23' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_d;// '<S30>/Read Parameter22' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_j;// '<S30>/Read Parameter21' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_l;// '<S30>/Read Parameter20' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_nu;// '<S30>/Read Parameter19' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_h;// '<S30>/Read Parameter18' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_hj;// '<S30>/Read Parameter17' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_gu;// '<S30>/Read Parameter16' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_gf;// '<S29>/Read Parameter8' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_m;// '<S29>/Read Parameter7' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_i;// '<S29>/Read Parameter3' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_kf;// '<S29>/Read Parameter2' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_c;// '<S29>/Read Parameter15' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_p;// '<S29>/Read Parameter14' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_n3;// '<S29>/Read Parameter13' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_do;// '<S29>/Read Parameter12' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_mt;// '<S29>/Read Parameter1' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_o;// '<S29>/Read Parameter' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_pk;// '<S28>/Read Parameter9' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_m5;// '<S28>/Read Parameter6' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_jv;// '<S28>/Read Parameter5' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_km;// '<S28>/Read Parameter4' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_hg;// '<S28>/Read Parameter11' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_g2;// '<S28>/Read Parameter10' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_p1;// '<S7>/Read Parameter5' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_cf;// '<S7>/Read Parameter4' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_n0;// '<S7>/Read Parameter3' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_ng;// '<S7>/Read Parameter2' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_ka;// '<S7>/Read Parameter13' 
  px4_internal_block_ParameterUpdate_MC_HEXA_MISSION_T obj_a;// '<S7>/Read Parameter1' 
  px4_internal_block_Subscriber_MC_HEXA_MISSION_T obj_mg;// '<S600>/SourceBlock' 
  px4_internal_block_Subscriber_MC_HEXA_MISSION_T obj_gv;// '<S599>/SourceBlock' 
  px4_internal_block_Subscriber_MC_HEXA_MISSION_T obj_d0;// '<S598>/SourceBlock' 
  px4_internal_block_Subscriber_MC_HEXA_MISSION_T obj_po;// '<S597>/SourceBlock' 
  px4_internal_block_Subscriber_MC_HEXA_MISSION_T obj_kz;// '<S579>/SourceBlock' 
  px4_internal_block_Subscriber_MC_HEXA_MISSION_T obj_gff;// '<S578>/SourceBlock' 
  px4_internal_block_Subscriber_MC_HEXA_MISSION_T obj_e;// '<S581>/SourceBlock'
  px4_internal_block_Subscriber_MC_HEXA_MISSION_T obj_da;// '<S19>/SourceBlock'
  px4_internal_block_Publisher_MC_HEXA_MISSION_T obj_o2;// '<S596>/SinkBlock'
  px4_internal_block_Publisher_MC_HEXA_MISSION_T obj_mc;// '<S588>/SinkBlock'
  px4_internal_block_Publisher_MC_HEXA_MISSION_T obj_dz;// '<S34>/SinkBlock'
  px4_internal_block_Publisher_MC_HEXA_MISSION_T obj_mgm;// '<S32>/SinkBlock'
  px4_internal_block_Publisher_MC_HEXA_MISSION_T obj_hy;// '<S22>/SinkBlock'
  px4_internal_block_LLA2LocalCoordinates_MC_HEXA_MISSION_T obj_mr;// '<S560>/LLA2LocalCoordinates' 
  real_T Delay_DSTATE;                 // '<S565>/Delay'
  real_T Delay_DSTATE_l[2];            // '<S562>/Delay'
  real_T Delay_DSTATE_n;               // '<S567>/Delay'
  real_T Delay_DSTATE_b;               // '<S568>/Delay'
  real_T Delay_DSTATE_c;               // '<S571>/Delay'
  real_T Delay_DSTATE_d;               // '<S572>/Delay'
  real_T Filter_DSTATE;                // '<S434>/Filter'
  real_T Integrator_DSTATE;            // '<S439>/Integrator'
  real_T Filter_DSTATE_h;              // '<S484>/Filter'
  real_T Integrator_DSTATE_d;          // '<S489>/Integrator'
  real_T Filter_DSTATE_l;              // '<S534>/Filter'
  real_T Integrator_DSTATE_dd;         // '<S539>/Integrator'
  real_T Filter_DSTATE_m;              // '<S381>/Filter'
  real_T Integrator_DSTATE_c;          // '<S386>/Integrator'
  real_T PrevY;                        // '<S28>/Rate Limiter2'
  real_T PrevY_b;                      // '<S28>/Rate Limiter1'
  px4_internal_block_LLA2LocalCoordinatesNED_MC_HEXA_MISSION_T obj_mu;// '<S586>/MATLAB System' 
  int8_T If_ActiveSubsystem;           // '<S559>/If'
  DW_PX4Timestamp_MC_HEXA_MISSION_T PX4Timestamp_pn;// '<S24>/PX4 Timestamp'
  DW_MATLABSystem_MC_HEXA_MISSION_T MATLABSystem_b;// '<S583>/MATLAB System'
  DW_MATLABSystem_MC_HEXA_MISSION_T MATLABSystem;// '<S583>/MATLAB System'
  DW_PX4Timestamp_MC_HEXA_MISSION_T PX4Timestamp_o;// '<S24>/PX4 Timestamp'
  DW_PX4Timestamp_MC_HEXA_MISSION_T PX4Timestamp_p;// '<S24>/PX4 Timestamp'
  DW_PX4Timestamp_MC_HEXA_MISSION_T PX4Timestamp;// '<S24>/PX4 Timestamp'
};

// Parameters (default storage)
struct P_MC_HEXA_MISSION_T_ {
  real_T PID_vz_InitialConditionForFilter;
                             // Mask Parameter: PID_vz_InitialConditionForFilter
                                //  Referenced by: '<S381>/Filter'

  real_T PIDController_InitialConditionForFilter;
                      // Mask Parameter: PIDController_InitialConditionForFilter
                         //  Referenced by: '<S434>/Filter'

  real_T PIDController1_InitialConditionForFilter;
                     // Mask Parameter: PIDController1_InitialConditionForFilter
                        //  Referenced by: '<S484>/Filter'

  real_T PIDController2_InitialConditionForFilter;
                     // Mask Parameter: PIDController2_InitialConditionForFilter
                        //  Referenced by: '<S534>/Filter'

  real_T PID_vz_InitialConditionForIntegrator;
                         // Mask Parameter: PID_vz_InitialConditionForIntegrator
                            //  Referenced by: '<S386>/Integrator'

  real_T PIDController_InitialConditionForIntegrator;
                  // Mask Parameter: PIDController_InitialConditionForIntegrator
                     //  Referenced by: '<S439>/Integrator'

  real_T PIDController1_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController1_InitialConditionForIntegrator
                    //  Referenced by: '<S489>/Integrator'

  real_T PIDController2_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController2_InitialConditionForIntegrator
                    //  Referenced by: '<S539>/Integrator'

  real_T PID_vz_LowerSaturationLimit;
                                  // Mask Parameter: PID_vz_LowerSaturationLimit
                                     //  Referenced by:
                                     //    '<S393>/Saturation'
                                     //    '<S379>/DeadZone'

  real_T PIDController_LowerSaturationLimit;
                           // Mask Parameter: PIDController_LowerSaturationLimit
                              //  Referenced by:
                              //    '<S446>/Saturation'
                              //    '<S432>/DeadZone'

  real_T PIDController1_LowerSaturationLimit;
                          // Mask Parameter: PIDController1_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S496>/Saturation'
                             //    '<S482>/DeadZone'

  real_T PIDController2_LowerSaturationLimit;
                          // Mask Parameter: PIDController2_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S546>/Saturation'
                             //    '<S532>/DeadZone'

  real_T PID_vz_UpperSaturationLimit;
                                  // Mask Parameter: PID_vz_UpperSaturationLimit
                                     //  Referenced by:
                                     //    '<S393>/Saturation'
                                     //    '<S379>/DeadZone'

  real_T PIDController_UpperSaturationLimit;
                           // Mask Parameter: PIDController_UpperSaturationLimit
                              //  Referenced by:
                              //    '<S446>/Saturation'
                              //    '<S432>/DeadZone'

  real_T PIDController1_UpperSaturationLimit;
                          // Mask Parameter: PIDController1_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S496>/Saturation'
                             //    '<S482>/DeadZone'

  real_T PIDController2_UpperSaturationLimit;
                          // Mask Parameter: PIDController2_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S546>/Saturation'
                             //    '<S532>/DeadZone'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S11>/Constant'

  uint16_T CompareToConstant_const_k;
                                    // Mask Parameter: CompareToConstant_const_k
                                       //  Referenced by: '<S18>/Constant'

  uint8_T CompareToConstant_const_d;// Mask Parameter: CompareToConstant_const_d
                                       //  Referenced by: '<S575>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Out1_Y0;// Computed Parameter: Out1_Y0
                                                 //  Referenced by: '<S582>/Out1'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value;// Computed Parameter: Constant_Value
                                                        //  Referenced by: '<S587>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                          //  Referenced by: '<S581>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0_e;  // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S601>/Out1'

  px4_Bus_vehicle_odometry Constant_Value_n;// Computed Parameter: Constant_Value_n
                                               //  Referenced by: '<S597>/Constant'

  px4_Bus_position_setpoint_triplet Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                 //  Referenced by: '<S594>/Out1'

  px4_Bus_position_setpoint_triplet Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                        //  Referenced by: '<S579>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                              //  Referenced by: '<S604>/Out1'

  px4_Bus_vehicle_local_position Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                     //  Referenced by: '<S600>/Constant'

  px4_Bus_actuator_outputs Constant_Value_c;// Computed Parameter: Constant_Value_c
                                               //  Referenced by: '<S21>/Constant'

  px4_Bus_vehicle_local_position_setpoint Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                              //  Referenced by: '<S595>/Constant'

  px4_Bus_input_rc Out1_Y0_i;          // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S20>/Out1'

  px4_Bus_input_rc Constant_Value_l;   // Computed Parameter: Constant_Value_l
                                          //  Referenced by: '<S19>/Constant'

  px4_Bus_vehicle_attitude_setpoint Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                        //  Referenced by: '<S31>/Constant'

  px4_Bus_vehicle_attitude Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S603>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_lh;// Computed Parameter: Constant_Value_lh
                                                //  Referenced by: '<S599>/Constant'

  px4_Bus_home_position Out1_Y0_o;     // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S593>/Out1'

  px4_Bus_home_position Constant_Value_b0;// Computed Parameter: Constant_Value_b0
                                             //  Referenced by: '<S578>/Constant'

  px4_Bus_vehicle_rates_setpoint Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                     //  Referenced by: '<S33>/Constant'

  px4_Bus_actuator_armed Out1_Y0_d;    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S602>/Out1'

  px4_Bus_actuator_armed Constant_Value_jl;// Computed Parameter: Constant_Value_jl
                                              //  Referenced by: '<S598>/Constant'

  real_T Constant1_Value;              // Expression: 1000
                                          //  Referenced by: '<S6>/Constant1'

  real_T Fault1_Value;                 // Expression: 100
                                          //  Referenced by: '<S7>/Fault1'

  real_T Constant1_Value_j;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant1'

  real_T Constant_Value_e1;            // Expression: 1100
                                          //  Referenced by: '<S13>/Constant'

  real_T Gain_Gain;                    // Expression: 0.01
                                          //  Referenced by: '<S13>/Gain'

  real_T Saturation1_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S13>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: 0
                                          //  Referenced by: '<S13>/Saturation1'

  real_T IDLEPWM_Value;                // Expression: 1100
                                          //  Referenced by: '<S13>/IDLE PWM'

  real_T Constant2_Value;              // Expression: 1000
                                          //  Referenced by: '<S6>/Constant2'

  real_T Fault2_Value;                 // Expression: 100
                                          //  Referenced by: '<S7>/Fault2'

  real_T Constant2_Value_o;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant2'

  real_T Constant_Value_f;             // Expression: 1100
                                          //  Referenced by: '<S14>/Constant'

  real_T Gain_Gain_d;                  // Expression: 0.01
                                          //  Referenced by: '<S14>/Gain'

  real_T Saturation1_UpperSat_e;       // Expression: 1
                                          //  Referenced by: '<S14>/Saturation1'

  real_T Saturation1_LowerSat_m;       // Expression: 0
                                          //  Referenced by: '<S14>/Saturation1'

  real_T IDLEPWM_Value_j;              // Expression: 1100
                                          //  Referenced by: '<S14>/IDLE PWM'

  real_T Constant3_Value;              // Expression: 1000
                                          //  Referenced by: '<S6>/Constant3'

  real_T Fault3_Value;                 // Expression: 100
                                          //  Referenced by: '<S7>/Fault3'

  real_T Constant3_Value_b;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant3'

  real_T Constant_Value_a;             // Expression: 1100
                                          //  Referenced by: '<S15>/Constant'

  real_T Gain_Gain_a;                  // Expression: 0.01
                                          //  Referenced by: '<S15>/Gain'

  real_T Saturation1_UpperSat_l;       // Expression: 1
                                          //  Referenced by: '<S15>/Saturation1'

  real_T Saturation1_LowerSat_g;       // Expression: 0
                                          //  Referenced by: '<S15>/Saturation1'

  real_T IDLEPWM_Value_k;              // Expression: 1100
                                          //  Referenced by: '<S15>/IDLE PWM'

  real_T Constant4_Value;              // Expression: 1000
                                          //  Referenced by: '<S6>/Constant4'

  real_T Fault4_Value;                 // Expression: 100
                                          //  Referenced by: '<S7>/Fault4'

  real_T Constant4_Value_e;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant4'

  real_T Constant_Value_j3;            // Expression: 1100
                                          //  Referenced by: '<S16>/Constant'

  real_T Gain_Gain_o;                  // Expression: 0.01
                                          //  Referenced by: '<S16>/Gain'

  real_T Saturation1_UpperSat_eb;      // Expression: 1
                                          //  Referenced by: '<S16>/Saturation1'

  real_T Saturation1_LowerSat_b;       // Expression: 0
                                          //  Referenced by: '<S16>/Saturation1'

  real_T IDLEPWM_Value_c;              // Expression: 1100
                                          //  Referenced by: '<S16>/IDLE PWM'

  real_T Constant5_Value;              // Expression: 1000
                                          //  Referenced by: '<S6>/Constant5'

  real_T Fault5_Value;                 // Expression: 100
                                          //  Referenced by: '<S7>/Fault5'

  real_T Constant5_Value_f;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant5'

  real_T Constant_Value_cx;            // Expression: 1100
                                          //  Referenced by: '<S17>/Constant'

  real_T Gain_Gain_ap;                 // Expression: 0.01
                                          //  Referenced by: '<S17>/Gain'

  real_T Saturation1_UpperSat_b;       // Expression: 1
                                          //  Referenced by: '<S17>/Saturation1'

  real_T Saturation1_LowerSat_o;       // Expression: 0
                                          //  Referenced by: '<S17>/Saturation1'

  real_T IDLEPWM_Value_e;              // Expression: 1100
                                          //  Referenced by: '<S17>/IDLE PWM'

  real_T Constant_Value_o;             // Expression: 1000
                                          //  Referenced by: '<S6>/Constant'

  real_T Fault_Value;                  // Expression: 100
                                          //  Referenced by: '<S7>/Fault'

  real_T Constant_Value_d3;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant'

  real_T Constant_Value_h;             // Expression: 1100
                                          //  Referenced by: '<S12>/Constant'

  real_T Gain_Gain_c;                  // Expression: 0.01
                                          //  Referenced by: '<S12>/Gain'

  real_T Saturation1_UpperSat_g;       // Expression: 1
                                          //  Referenced by: '<S12>/Saturation1'

  real_T Saturation1_LowerSat_c;       // Expression: 0
                                          //  Referenced by: '<S12>/Saturation1'

  real_T IDLEPWM_Value_h;              // Expression: 1100
                                          //  Referenced by: '<S12>/IDLE PWM'

  real_T ReadParameter1_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S7>/Read Parameter1'

  real_T ReadParameter13_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S7>/Read Parameter13'

  real_T ReadParameter2_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S7>/Read Parameter2'

  real_T ReadParameter3_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S7>/Read Parameter3'

  real_T ReadParameter4_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S7>/Read Parameter4'

  real_T ReadParameter5_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S7>/Read Parameter5'

  real_T Constant_Value_im[4];         // Expression: [1 0 0 0]
                                          //  Referenced by: '<S26>/Constant'

  real_T Constant_Value_be;            // Expression: 1
                                          //  Referenced by: '<S39>/Constant'

  real_T Constant_Value_m;             // Expression: 1
                                          //  Referenced by: '<S40>/Constant'

  real_T Switch1_Threshold;            // Expression: 0
                                          //  Referenced by: '<S44>/Switch1'

  real_T ReadParameter10_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S28>/Read Parameter10'

  real_T ReadParameter11_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S28>/Read Parameter11'

  real_T ReadParameter4_SampleTime_b;  // Expression: -1
                                          //  Referenced by: '<S28>/Read Parameter4'

  real_T ReadParameter5_SampleTime_m;  // Expression: -1
                                          //  Referenced by: '<S28>/Read Parameter5'

  real_T ReadParameter6_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S28>/Read Parameter6'

  real_T ReadParameter9_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S28>/Read Parameter9'

  real_T Yawrate_sp_Y0;                // Computed Parameter: Yawrate_sp_Y0
                                          //  Referenced by: '<S28>/Yawrate_sp'

  real_T Pitchrate_sp_Y0;              // Computed Parameter: Pitchrate_sp_Y0
                                          //  Referenced by: '<S28>/Pitchrate_sp'

  real_T Rollrate_spl_Y0;              // Computed Parameter: Rollrate_spl_Y0
                                          //  Referenced by: '<S28>/Rollrate_spl'

  real_T Constant_Value_p;             // Expression: 2*pi
                                          //  Referenced by: '<S44>/Constant'

  real_T Switch_Threshold;             // Expression: pi
                                          //  Referenced by: '<S44>/Switch'

  real_T RateLimiter2_RisingLim;       // Expression: 180*pi/180
                                          //  Referenced by: '<S28>/Rate Limiter2'

  real_T RateLimiter2_FallingLim;      // Expression: -180*pi/180
                                          //  Referenced by: '<S28>/Rate Limiter2'

  real_T RateLimiter2_IC;              // Expression: 0
                                          //  Referenced by: '<S28>/Rate Limiter2'

  real_T RateLimiter1_RisingLim;       // Expression: 180*pi/180
                                          //  Referenced by: '<S28>/Rate Limiter1'

  real_T RateLimiter1_FallingLim;      // Expression: -180*pi/180
                                          //  Referenced by: '<S28>/Rate Limiter1'

  real_T RateLimiter1_IC;              // Expression: 0
                                          //  Referenced by: '<S28>/Rate Limiter1'

  real_T Constant_Value_j4;            // Expression: 0
                                          //  Referenced by: '<S198>/Constant'

  real_T ReadParameter_SampleTime;     // Expression: -1
                                          //  Referenced by: '<S29>/Read Parameter'

  real_T ReadParameter1_SampleTime_m;  // Expression: -1
                                          //  Referenced by: '<S29>/Read Parameter1'

  real_T ReadParameter12_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S29>/Read Parameter12'

  real_T ReadParameter13_SampleTime_o; // Expression: -1
                                          //  Referenced by: '<S29>/Read Parameter13'

  real_T ReadParameter14_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S29>/Read Parameter14'

  real_T ReadParameter15_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S29>/Read Parameter15'

  real_T ReadParameter2_SampleTime_p;  // Expression: -1
                                          //  Referenced by: '<S29>/Read Parameter2'

  real_T ReadParameter3_SampleTime_j;  // Expression: -1
                                          //  Referenced by: '<S29>/Read Parameter3'

  real_T ReadParameter7_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S29>/Read Parameter7'

  real_T ReadParameter8_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S29>/Read Parameter8'

  real_T tau_Thrust_Y0;                // Computed Parameter: tau_Thrust_Y0
                                          //  Referenced by: '<S29>/tau_Thrust'

  real_T des_pitch_Y0;                 // Computed Parameter: des_pitch_Y0
                                          //  Referenced by: '<S29>/des_pitch'

  real_T des_roll_Y0;                  // Computed Parameter: des_roll_Y0
                                          //  Referenced by: '<S29>/des_roll'

  real_T Constant1_Value_o;            // Expression: 0
                                          //  Referenced by: '<S377>/Constant1'

  real_T Constant_Value_p3;            // Expression: 10
                                          //  Referenced by: '<S29>/Constant'

  real_T Clamping_zero_Value;          // Expression: 0
                                          //  Referenced by: '<S377>/Clamping_zero'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S381>/Filter'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S386>/Integrator'

  real_T Gain_Gain_l;                  // Expression: -1
                                          //  Referenced by: '<S199>/Gain'

  real_T Gain1_Gain;                   // Expression: -1
                                          //  Referenced by: '<S29>/Gain1'

  real_T ReadParameter16_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter16'

  real_T ReadParameter17_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter17'

  real_T ReadParameter18_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter18'

  real_T ReadParameter19_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter19'

  real_T ReadParameter20_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter20'

  real_T ReadParameter21_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter21'

  real_T ReadParameter22_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter22'

  real_T ReadParameter23_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter23'

  real_T ReadParameter24_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter24'

  real_T tau_yaw_Y0;                   // Computed Parameter: tau_yaw_Y0
                                          //  Referenced by: '<S30>/tau_yaw'

  real_T tau_pitch_Y0;                 // Computed Parameter: tau_pitch_Y0
                                          //  Referenced by: '<S30>/tau_pitch'

  real_T tau_roll_Y0;                  // Computed Parameter: tau_roll_Y0
                                          //  Referenced by: '<S30>/tau_roll'

  real_T Constant1_Value_k;            // Expression: 0
                                          //  Referenced by: '<S430>/Constant1'

  real_T Constant1_Value_jx;           // Expression: 0
                                          //  Referenced by: '<S480>/Constant1'

  real_T Constant1_Value_ka;           // Expression: 0
                                          //  Referenced by: '<S530>/Constant1'

  real_T Constant_Value_pd;            // Expression: 100
                                          //  Referenced by: '<S30>/Constant'

  real_T Filter_gainval_f;             // Computed Parameter: Filter_gainval_f
                                          //  Referenced by: '<S434>/Filter'

  real_T Integrator_gainval_h;       // Computed Parameter: Integrator_gainval_h
                                        //  Referenced by: '<S439>/Integrator'

  real_T Clamping_zero_Value_i;        // Expression: 0
                                          //  Referenced by: '<S430>/Clamping_zero'

  real_T Constant1_Value_f;            // Expression: 50
                                          //  Referenced by: '<S30>/Constant1'

  real_T Filter_gainval_l;             // Computed Parameter: Filter_gainval_l
                                          //  Referenced by: '<S484>/Filter'

  real_T Integrator_gainval_b;       // Computed Parameter: Integrator_gainval_b
                                        //  Referenced by: '<S489>/Integrator'

  real_T Clamping_zero_Value_d;        // Expression: 0
                                          //  Referenced by: '<S480>/Clamping_zero'

  real_T Constant2_Value_n;            // Expression: 50
                                          //  Referenced by: '<S30>/Constant2'

  real_T Filter_gainval_a;             // Computed Parameter: Filter_gainval_a
                                          //  Referenced by: '<S534>/Filter'

  real_T Integrator_gainval_n;       // Computed Parameter: Integrator_gainval_n
                                        //  Referenced by: '<S539>/Integrator'

  real_T Clamping_zero_Value_e;        // Expression: 0
                                          //  Referenced by: '<S530>/Clamping_zero'

  real_T yaw_Out_Y0;                   // Computed Parameter: yaw_Out_Y0
                                          //  Referenced by: '<S573>/yaw_Out'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S571>/Delay'

  real_T Rate_Value;                   // Expression: 0.01
                                          //  Referenced by: '<S571>/Rate'

  real_T Gain1_Gain_b;                 // Expression: -1
                                          //  Referenced by: '<S571>/Gain1'

  real_T Gain_Gain_e;                  // Expression: -1
                                          //  Referenced by: '<S571>/Gain'

  real_T Delay_InitialCondition_g;     // Expression: 1
                                          //  Referenced by: '<S572>/Delay'

  real_T Constant_Value_fo;            // Expression: 0
                                          //  Referenced by: '<S572>/Constant'

  real_T Out_Y0;                       // Computed Parameter: Out_Y0
                                          //  Referenced by: '<S569>/Out'

  real_T Gain_Gain_ls;                 // Expression: -1
                                          //  Referenced by: '<S567>/Gain'

  real_T yaw_Out_Y0_f;                 // Computed Parameter: yaw_Out_Y0_f
                                          //  Referenced by: '<S570>/yaw_Out'

  real_T Delay_InitialCondition_n;     // Expression: 0.0
                                          //  Referenced by: '<S562>/Delay'

  real_T Delay_InitialCondition_m;     // Expression: 0.0
                                          //  Referenced by: '<S567>/Delay'

  real_T Switch_Threshold_j;           // Expression: 0
                                          //  Referenced by: '<S567>/Switch'

  real_T Rateofdescent_Value;          // Expression: 0.02
                                          //  Referenced by: '<S567>/Rate of descent'

  real_T Gain2_Gain;                   // Expression: -1
                                          //  Referenced by: '<S567>/Gain2'

  real_T Gain1_Gain_a;                 // Expression: -1
                                          //  Referenced by: '<S567>/Gain1'

  real_T Delay_InitialCondition_j;     // Expression: 1
                                          //  Referenced by: '<S568>/Delay'

  real_T Constant_Value_nn;            // Expression: 0
                                          //  Referenced by: '<S568>/Constant'

  real_T Constant_Value_jd;            // Expression: 0
                                          //  Referenced by: '<S574>/Constant'

  real_T Constant_Value_gw;            // Expression: 6
                                          //  Referenced by: '<S564>/Constant'

  real_T yaw_Out_Y0_p;                 // Computed Parameter: yaw_Out_Y0_p
                                          //  Referenced by: '<S566>/yaw_Out'

  real_T Delay_InitialCondition_g0;    // Expression: 1
                                          //  Referenced by: '<S565>/Delay'

  real_T Constant_Value_ic;            // Expression: 0
                                          //  Referenced by: '<S565>/Constant'

  real_T ReadParameter_SampleTime_d;   // Expression: -1
                                          //  Referenced by: '<S560>/Read Parameter'

  real_T ReadParameter_SampleTime_c;   // Expression: -1
                                          //  Referenced by: '<S592>/Read Parameter'

  real_T ReadParameter_SampleTime_g;   // Expression: -1
                                          //  Referenced by: '<S591>/Read Parameter'

  real_T Switch_Threshold_l;           // Expression: 0
                                          //  Referenced by: '<S26>/Switch'

  real_T Gain_Gain_cc;                 // Expression: -1
                                          //  Referenced by: '<S23>/Gain'

  real_T Gain_Gain_j;                  // Expression: 5
                                          //  Referenced by: '<S5>/Gain'

  real_T Gain1_Gain_j;                 // Expression: 5
                                          //  Referenced by: '<S5>/Gain1'

  real_T Gain2_Gain_f;                 // Expression: 10
                                          //  Referenced by: '<S5>/Gain2'

  real_T Gain3_Gain;                   // Expression: 1
                                          //  Referenced by: '<S5>/Gain3'

  real_T Constant_Value_gp;            // Expression: 0
                                          //  Referenced by: '<S10>/Constant'

  real_T thrust_sp_bX_Value;           // Expression: 0
                                          //  Referenced by: '<S24>/thrust_sp_bX'

  real_T thrust_sp_bY_Value;           // Expression: 0
                                          //  Referenced by: '<S24>/thrust_sp_bY'

  real_T thrust_sp_bX_Value_m;         // Expression: 0
                                          //  Referenced by: '<S25>/thrust_sp_bX'

  real_T thrust_sp_bY_Value_m;         // Expression: 0
                                          //  Referenced by: '<S25>/thrust_sp_bY'

  real_T Constant17_Value;             // Expression: 6
                                          //  Referenced by: '<S10>/Constant17'

  uint64_T Constant7_Value;            // Computed Parameter: Constant7_Value
                                          //  Referenced by: '<S585>/Constant7'

  real32_T Gain1_Gain_k;               // Computed Parameter: Gain1_Gain_k
                                          //  Referenced by: '<S47>/Gain1'

  real32_T Gain1_Gain_i;               // Computed Parameter: Gain1_Gain_i
                                          //  Referenced by: '<S45>/Gain1'

  real32_T Gain1_Gain_o;               // Computed Parameter: Gain1_Gain_o
                                          //  Referenced by: '<S46>/Gain1'

  real32_T Gain1_Gain_o1;              // Computed Parameter: Gain1_Gain_o1
                                          //  Referenced by: '<S198>/Gain1'

  real32_T Gain1_Gain_p;               // Computed Parameter: Gain1_Gain_p
                                          //  Referenced by: '<S200>/Gain1'

  real32_T Gain_Gain_m;                // Computed Parameter: Gain_Gain_m
                                          //  Referenced by: '<S29>/Gain'

  real32_T Gain2_Gain_i;               // Computed Parameter: Gain2_Gain_i
                                          //  Referenced by: '<S29>/Gain2'

  real32_T Constant1_Value_d[2];       // Computed Parameter: Constant1_Value_d
                                          //  Referenced by: '<S592>/Constant1'

  real32_T Constant_Value_f2;          // Computed Parameter: Constant_Value_f2
                                          //  Referenced by: '<S592>/Constant'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S591>/Gain'

  real32_T Constant1_Value_k4[2];      // Computed Parameter: Constant1_Value_k4
                                          //  Referenced by: '<S591>/Constant1'

  real32_T Constant_Value_l4;          // Computed Parameter: Constant_Value_l4
                                          //  Referenced by: '<S591>/Constant'

  real32_T Constant_Value_fh[3];       // Computed Parameter: Constant_Value_fh
                                          //  Referenced by: '<S585>/Constant'

  real32_T Constant1_Value_h[3];       // Computed Parameter: Constant1_Value_h
                                          //  Referenced by: '<S585>/Constant1'

  real32_T Constant2_Value_f[3];       // Computed Parameter: Constant2_Value_f
                                          //  Referenced by: '<S585>/Constant2'

  real32_T Constant3_Value_a;          // Computed Parameter: Constant3_Value_a
                                          //  Referenced by: '<S585>/Constant3'

  real32_T Constant4_Value_g;          // Computed Parameter: Constant4_Value_g
                                          //  Referenced by: '<S585>/Constant4'

  boolean_T Constant5_Value_j;         // Computed Parameter: Constant5_Value_j
                                          //  Referenced by: '<S583>/Constant5'

  boolean_T Constant5_Value_k;         // Computed Parameter: Constant5_Value_k
                                          //  Referenced by: '<S584>/Constant5'

  boolean_T Constant1_Value_dl;        // Computed Parameter: Constant1_Value_dl
                                          //  Referenced by: '<S586>/Constant1'

  boolean_T Constant5_Value_h;         // Computed Parameter: Constant5_Value_h
                                          //  Referenced by: '<S586>/Constant5'

  boolean_T Constant5_Value_l;         // Computed Parameter: Constant5_Value_l
                                          //  Referenced by: '<S585>/Constant5'

  int8_T Constant_Value_mp;            // Computed Parameter: Constant_Value_mp
                                          //  Referenced by: '<S377>/Constant'

  int8_T Constant2_Value_k;            // Computed Parameter: Constant2_Value_k
                                          //  Referenced by: '<S377>/Constant2'

  int8_T Constant3_Value_i;            // Computed Parameter: Constant3_Value_i
                                          //  Referenced by: '<S377>/Constant3'

  int8_T Constant4_Value_j;            // Computed Parameter: Constant4_Value_j
                                          //  Referenced by: '<S377>/Constant4'

  int8_T Constant_Value_dt;            // Computed Parameter: Constant_Value_dt
                                          //  Referenced by: '<S430>/Constant'

  int8_T Constant2_Value_l;            // Computed Parameter: Constant2_Value_l
                                          //  Referenced by: '<S430>/Constant2'

  int8_T Constant3_Value_j;            // Computed Parameter: Constant3_Value_j
                                          //  Referenced by: '<S430>/Constant3'

  int8_T Constant4_Value_c;            // Computed Parameter: Constant4_Value_c
                                          //  Referenced by: '<S430>/Constant4'

  int8_T Constant_Value_d5;            // Computed Parameter: Constant_Value_d5
                                          //  Referenced by: '<S480>/Constant'

  int8_T Constant2_Value_e;            // Computed Parameter: Constant2_Value_e
                                          //  Referenced by: '<S480>/Constant2'

  int8_T Constant3_Value_k;            // Computed Parameter: Constant3_Value_k
                                          //  Referenced by: '<S480>/Constant3'

  int8_T Constant4_Value_n;            // Computed Parameter: Constant4_Value_n
                                          //  Referenced by: '<S480>/Constant4'

  int8_T Constant_Value_k;             // Computed Parameter: Constant_Value_k
                                          //  Referenced by: '<S530>/Constant'

  int8_T Constant2_Value_m;            // Computed Parameter: Constant2_Value_m
                                          //  Referenced by: '<S530>/Constant2'

  int8_T Constant3_Value_d;            // Computed Parameter: Constant3_Value_d
                                          //  Referenced by: '<S530>/Constant3'

  int8_T Constant4_Value_b;            // Computed Parameter: Constant4_Value_b
                                          //  Referenced by: '<S530>/Constant4'

  uint8_T ManualSwitch1_CurrentSetting;
                             // Computed Parameter: ManualSwitch1_CurrentSetting
                                //  Referenced by: '<S7>/Manual Switch1'

  uint8_T ManualSwitch2_CurrentSetting;
                             // Computed Parameter: ManualSwitch2_CurrentSetting
                                //  Referenced by: '<S7>/Manual Switch2'

  uint8_T ManualSwitch3_CurrentSetting;
                             // Computed Parameter: ManualSwitch3_CurrentSetting
                                //  Referenced by: '<S7>/Manual Switch3'

  uint8_T ManualSwitch4_CurrentSetting;
                             // Computed Parameter: ManualSwitch4_CurrentSetting
                                //  Referenced by: '<S7>/Manual Switch4'

  uint8_T ManualSwitch5_CurrentSetting;
                             // Computed Parameter: ManualSwitch5_CurrentSetting
                                //  Referenced by: '<S7>/Manual Switch5'

  uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<S7>/Manual Switch'

  uint8_T Constant_Value_fm;           // Computed Parameter: Constant_Value_fm
                                          //  Referenced by: '<S577>/Constant'

  uint8_T Constant6_Value;             // Computed Parameter: Constant6_Value
                                          //  Referenced by: '<S585>/Constant6'

};

// Real-time Model Data Structure
struct tag_RTM_MC_HEXA_MISSION_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_MC_HEXA_MISSION_T MC_HEXA_MISSION_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_MC_HEXA_MISSION_T MC_HEXA_MISSION_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_MC_HEXA_MISSION_T MC_HEXA_MISSION_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void MC_HEXA_MISSION_initialize(void);
  extern void MC_HEXA_MISSION_step(void);
  extern void MC_HEXA_MISSION_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_MC_HEXA_MISSION_T *const MC_HEXA_MISSION_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S7>/Scope' : Unused code path elimination
//  Block '<S9>/Bitwise Operator' : Unused code path elimination
//  Block '<S9>/Data Type Conversion' : Unused code path elimination
//  Block '<S9>/Data Type Conversion1' : Unused code path elimination
//  Block '<S9>/Data Type Conversion2' : Unused code path elimination
//  Block '<S9>/Gain' : Unused code path elimination
//  Block '<S9>/Gain1' : Unused code path elimination
//  Block '<S19>/NOT' : Unused code path elimination
//  Block '<S90>/Data Type Duplicate' : Unused code path elimination
//  Block '<S90>/Data Type Propagation' : Unused code path elimination
//  Block '<S139>/Data Type Duplicate' : Unused code path elimination
//  Block '<S139>/Data Type Propagation' : Unused code path elimination
//  Block '<S188>/Data Type Duplicate' : Unused code path elimination
//  Block '<S188>/Data Type Propagation' : Unused code path elimination
//  Block '<S205>/Data Type Duplicate' : Unused code path elimination
//  Block '<S205>/Data Type Propagation' : Unused code path elimination
//  Block '<S245>/Data Type Duplicate' : Unused code path elimination
//  Block '<S245>/Data Type Propagation' : Unused code path elimination
//  Block '<S294>/Data Type Duplicate' : Unused code path elimination
//  Block '<S294>/Data Type Propagation' : Unused code path elimination
//  Block '<S343>/Data Type Duplicate' : Unused code path elimination
//  Block '<S343>/Data Type Propagation' : Unused code path elimination
//  Block '<S580>/Compare' : Unused code path elimination
//  Block '<S580>/Constant' : Unused code path elimination
//  Block '<S581>/NOT' : Unused code path elimination
//  Block '<S576>/Subtract' : Unused code path elimination
//  Block '<S578>/NOT' : Unused code path elimination
//  Block '<S579>/NOT' : Unused code path elimination
//  Block '<S597>/NOT' : Unused code path elimination
//  Block '<S598>/NOT' : Unused code path elimination
//  Block '<S599>/NOT' : Unused code path elimination
//  Block '<S600>/NOT' : Unused code path elimination
//  Block '<S562>/Reshape1' : Reshape block reduction
//  Block '<S574>/Reshape3' : Reshape block reduction
//  Block '<S564>/Reshape1' : Reshape block reduction
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
//  '<Root>' : 'MC_HEXA_MISSION'
//  '<S1>'   : 'MC_HEXA_MISSION/Actuator'
//  '<S2>'   : 'MC_HEXA_MISSION/CLAW'
//  '<S3>'   : 'MC_HEXA_MISSION/Navigation'
//  '<S4>'   : 'MC_HEXA_MISSION/uORBInput'
//  '<S5>'   : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block'
//  '<S6>'   : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Emergency Kill'
//  '<S7>'   : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Fault_Injection'
//  '<S8>'   : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/MATLAB Function'
//  '<S9>'   : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Radio Control Transmitter'
//  '<S10>'  : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Subsystem'
//  '<S11>'  : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Emergency Kill/Compare To Constant'
//  '<S12>'  : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM'
//  '<S13>'  : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM1'
//  '<S14>'  : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM2'
//  '<S15>'  : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM3'
//  '<S16>'  : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM4'
//  '<S17>'  : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM5'
//  '<S18>'  : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Compare To Constant'
//  '<S19>'  : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Radio Control Transmitter/PX4 uORB Read'
//  '<S20>'  : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S21>'  : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Subsystem/PX4 uORB Message'
//  '<S22>'  : 'MC_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Subsystem/PX4 uORB Write'
//  '<S23>'  : 'MC_HEXA_MISSION/CLAW/Controller'
//  '<S24>'  : 'MC_HEXA_MISSION/CLAW/Controller/Publish vehicle_attitude_setpoint'
//  '<S25>'  : 'MC_HEXA_MISSION/CLAW/Controller/Publish vehicle_rate_setpoint'
//  '<S26>'  : 'MC_HEXA_MISSION/CLAW/Controller/Quaternion Validity Check'
//  '<S27>'  : 'MC_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles'
//  '<S28>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller'
//  '<S29>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller'
//  '<S30>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller'
//  '<S31>'  : 'MC_HEXA_MISSION/CLAW/Controller/Publish vehicle_attitude_setpoint/PX4 uORB Message'
//  '<S32>'  : 'MC_HEXA_MISSION/CLAW/Controller/Publish vehicle_attitude_setpoint/PX4 uORB Write'
//  '<S33>'  : 'MC_HEXA_MISSION/CLAW/Controller/Publish vehicle_rate_setpoint/PX4 uORB Message'
//  '<S34>'  : 'MC_HEXA_MISSION/CLAW/Controller/Publish vehicle_rate_setpoint/PX4 uORB Write'
//  '<S35>'  : 'MC_HEXA_MISSION/CLAW/Controller/Quaternion Validity Check/Quaternion Norm'
//  '<S36>'  : 'MC_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation'
//  '<S37>'  : 'MC_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S38>'  : 'MC_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S39>'  : 'MC_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S40>'  : 'MC_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S41>'  : 'MC_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S42>'  : 'MC_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S43>'  : 'MC_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S44>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/Calculate minimum Turn'
//  '<S45>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/Degrees to Radians'
//  '<S46>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/Degrees to Radians1'
//  '<S47>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/Degrees to Radians2'
//  '<S48>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3'
//  '<S49>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4'
//  '<S50>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5'
//  '<S51>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Anti-windup'
//  '<S52>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/D Gain'
//  '<S53>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Filter'
//  '<S54>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Filter ICs'
//  '<S55>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/I Gain'
//  '<S56>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Ideal P Gain'
//  '<S57>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Ideal P Gain Fdbk'
//  '<S58>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Integrator'
//  '<S59>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Integrator ICs'
//  '<S60>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/N Copy'
//  '<S61>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/N Gain'
//  '<S62>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/P Copy'
//  '<S63>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Parallel P Gain'
//  '<S64>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Reset Signal'
//  '<S65>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Saturation'
//  '<S66>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Saturation Fdbk'
//  '<S67>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Sum'
//  '<S68>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Sum Fdbk'
//  '<S69>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Tracking Mode'
//  '<S70>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Tracking Mode Sum'
//  '<S71>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Tsamp - Integral'
//  '<S72>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Tsamp - Ngain'
//  '<S73>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/postSat Signal'
//  '<S74>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/preSat Signal'
//  '<S75>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Anti-windup/Disabled'
//  '<S76>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/D Gain/Disabled'
//  '<S77>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Filter/Disabled'
//  '<S78>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Filter ICs/Disabled'
//  '<S79>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/I Gain/Disabled'
//  '<S80>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Ideal P Gain/Passthrough'
//  '<S81>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S82>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Integrator/Disabled'
//  '<S83>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Integrator ICs/Disabled'
//  '<S84>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S85>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/N Gain/Disabled'
//  '<S86>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/P Copy/Disabled'
//  '<S87>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Parallel P Gain/External Parameters'
//  '<S88>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Reset Signal/Disabled'
//  '<S89>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Saturation/External'
//  '<S90>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Saturation/External/Saturation Dynamic'
//  '<S91>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Saturation Fdbk/Disabled'
//  '<S92>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Sum/Passthrough_P'
//  '<S93>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Sum Fdbk/Disabled'
//  '<S94>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Tracking Mode/Disabled'
//  '<S95>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S96>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S97>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S98>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/postSat Signal/Forward_Path'
//  '<S99>'  : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/preSat Signal/Forward_Path'
//  '<S100>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Anti-windup'
//  '<S101>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/D Gain'
//  '<S102>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Filter'
//  '<S103>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Filter ICs'
//  '<S104>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/I Gain'
//  '<S105>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Ideal P Gain'
//  '<S106>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S107>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Integrator'
//  '<S108>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Integrator ICs'
//  '<S109>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/N Copy'
//  '<S110>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/N Gain'
//  '<S111>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/P Copy'
//  '<S112>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Parallel P Gain'
//  '<S113>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Reset Signal'
//  '<S114>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Saturation'
//  '<S115>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Saturation Fdbk'
//  '<S116>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Sum'
//  '<S117>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Sum Fdbk'
//  '<S118>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Tracking Mode'
//  '<S119>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Tracking Mode Sum'
//  '<S120>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Tsamp - Integral'
//  '<S121>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Tsamp - Ngain'
//  '<S122>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/postSat Signal'
//  '<S123>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/preSat Signal'
//  '<S124>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Anti-windup/Disabled'
//  '<S125>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/D Gain/Disabled'
//  '<S126>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Filter/Disabled'
//  '<S127>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Filter ICs/Disabled'
//  '<S128>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/I Gain/Disabled'
//  '<S129>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S130>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S131>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Integrator/Disabled'
//  '<S132>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Integrator ICs/Disabled'
//  '<S133>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S134>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/N Gain/Disabled'
//  '<S135>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/P Copy/Disabled'
//  '<S136>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Parallel P Gain/External Parameters'
//  '<S137>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Reset Signal/Disabled'
//  '<S138>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Saturation/External'
//  '<S139>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Saturation/External/Saturation Dynamic'
//  '<S140>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S141>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Sum/Passthrough_P'
//  '<S142>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S143>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Tracking Mode/Disabled'
//  '<S144>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S145>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S146>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S147>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S148>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S149>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Anti-windup'
//  '<S150>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/D Gain'
//  '<S151>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Filter'
//  '<S152>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Filter ICs'
//  '<S153>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/I Gain'
//  '<S154>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Ideal P Gain'
//  '<S155>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Ideal P Gain Fdbk'
//  '<S156>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Integrator'
//  '<S157>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Integrator ICs'
//  '<S158>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/N Copy'
//  '<S159>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/N Gain'
//  '<S160>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/P Copy'
//  '<S161>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Parallel P Gain'
//  '<S162>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Reset Signal'
//  '<S163>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Saturation'
//  '<S164>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Saturation Fdbk'
//  '<S165>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Sum'
//  '<S166>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Sum Fdbk'
//  '<S167>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Tracking Mode'
//  '<S168>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Tracking Mode Sum'
//  '<S169>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Tsamp - Integral'
//  '<S170>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Tsamp - Ngain'
//  '<S171>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/postSat Signal'
//  '<S172>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/preSat Signal'
//  '<S173>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Anti-windup/Disabled'
//  '<S174>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/D Gain/Disabled'
//  '<S175>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Filter/Disabled'
//  '<S176>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Filter ICs/Disabled'
//  '<S177>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/I Gain/Disabled'
//  '<S178>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Ideal P Gain/Passthrough'
//  '<S179>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Ideal P Gain Fdbk/Disabled'
//  '<S180>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Integrator/Disabled'
//  '<S181>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Integrator ICs/Disabled'
//  '<S182>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/N Copy/Disabled wSignal Specification'
//  '<S183>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/N Gain/Disabled'
//  '<S184>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/P Copy/Disabled'
//  '<S185>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Parallel P Gain/External Parameters'
//  '<S186>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Reset Signal/Disabled'
//  '<S187>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Saturation/External'
//  '<S188>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Saturation/External/Saturation Dynamic'
//  '<S189>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Saturation Fdbk/Disabled'
//  '<S190>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Sum/Passthrough_P'
//  '<S191>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Sum Fdbk/Disabled'
//  '<S192>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Tracking Mode/Disabled'
//  '<S193>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Tracking Mode Sum/Passthrough'
//  '<S194>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Tsamp - Integral/TsSignalSpecification'
//  '<S195>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Tsamp - Ngain/Passthrough'
//  '<S196>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/postSat Signal/Forward_Path'
//  '<S197>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/preSat Signal/Forward_Path'
//  '<S198>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/Altitude Signal conditioning'
//  '<S199>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/Calculate Transformation Matrix'
//  '<S200>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/Degrees to Radians'
//  '<S201>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller'
//  '<S202>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1'
//  '<S203>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude'
//  '<S204>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz'
//  '<S205>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/Altitude Signal conditioning/Saturation Dynamic'
//  '<S206>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Anti-windup'
//  '<S207>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/D Gain'
//  '<S208>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Filter'
//  '<S209>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Filter ICs'
//  '<S210>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/I Gain'
//  '<S211>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Ideal P Gain'
//  '<S212>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Ideal P Gain Fdbk'
//  '<S213>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Integrator'
//  '<S214>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Integrator ICs'
//  '<S215>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/N Copy'
//  '<S216>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/N Gain'
//  '<S217>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/P Copy'
//  '<S218>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Parallel P Gain'
//  '<S219>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Reset Signal'
//  '<S220>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Saturation'
//  '<S221>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Saturation Fdbk'
//  '<S222>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Sum'
//  '<S223>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Sum Fdbk'
//  '<S224>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Tracking Mode'
//  '<S225>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Tracking Mode Sum'
//  '<S226>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Tsamp - Integral'
//  '<S227>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Tsamp - Ngain'
//  '<S228>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/postSat Signal'
//  '<S229>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/preSat Signal'
//  '<S230>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Anti-windup/Disabled'
//  '<S231>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/D Gain/Disabled'
//  '<S232>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Filter/Disabled'
//  '<S233>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Filter ICs/Disabled'
//  '<S234>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/I Gain/Disabled'
//  '<S235>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S236>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S237>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Integrator/Disabled'
//  '<S238>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Integrator ICs/Disabled'
//  '<S239>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S240>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/N Gain/Disabled'
//  '<S241>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/P Copy/Disabled'
//  '<S242>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Parallel P Gain/External Parameters'
//  '<S243>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Reset Signal/Disabled'
//  '<S244>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Saturation/External'
//  '<S245>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Saturation/External/Saturation Dynamic'
//  '<S246>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S247>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Sum/Passthrough_P'
//  '<S248>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Sum Fdbk/Disabled'
//  '<S249>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Tracking Mode/Disabled'
//  '<S250>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S251>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S252>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S253>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/postSat Signal/Forward_Path'
//  '<S254>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/preSat Signal/Forward_Path'
//  '<S255>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Anti-windup'
//  '<S256>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/D Gain'
//  '<S257>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Filter'
//  '<S258>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Filter ICs'
//  '<S259>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/I Gain'
//  '<S260>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Ideal P Gain'
//  '<S261>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S262>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Integrator'
//  '<S263>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Integrator ICs'
//  '<S264>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/N Copy'
//  '<S265>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/N Gain'
//  '<S266>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/P Copy'
//  '<S267>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Parallel P Gain'
//  '<S268>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Reset Signal'
//  '<S269>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Saturation'
//  '<S270>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Saturation Fdbk'
//  '<S271>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Sum'
//  '<S272>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Sum Fdbk'
//  '<S273>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Tracking Mode'
//  '<S274>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Tracking Mode Sum'
//  '<S275>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Tsamp - Integral'
//  '<S276>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Tsamp - Ngain'
//  '<S277>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/postSat Signal'
//  '<S278>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/preSat Signal'
//  '<S279>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Anti-windup/Disabled'
//  '<S280>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/D Gain/Disabled'
//  '<S281>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Filter/Disabled'
//  '<S282>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Filter ICs/Disabled'
//  '<S283>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/I Gain/Disabled'
//  '<S284>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S285>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S286>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Integrator/Disabled'
//  '<S287>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Integrator ICs/Disabled'
//  '<S288>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S289>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/N Gain/Disabled'
//  '<S290>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/P Copy/Disabled'
//  '<S291>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Parallel P Gain/External Parameters'
//  '<S292>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Reset Signal/Disabled'
//  '<S293>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Saturation/External'
//  '<S294>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Saturation/External/Saturation Dynamic'
//  '<S295>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S296>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Sum/Passthrough_P'
//  '<S297>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S298>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Tracking Mode/Disabled'
//  '<S299>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S300>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S301>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S302>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S303>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S304>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Anti-windup'
//  '<S305>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/D Gain'
//  '<S306>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Filter'
//  '<S307>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Filter ICs'
//  '<S308>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/I Gain'
//  '<S309>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Ideal P Gain'
//  '<S310>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S311>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Integrator'
//  '<S312>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Integrator ICs'
//  '<S313>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/N Copy'
//  '<S314>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/N Gain'
//  '<S315>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/P Copy'
//  '<S316>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Parallel P Gain'
//  '<S317>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Reset Signal'
//  '<S318>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Saturation'
//  '<S319>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Saturation Fdbk'
//  '<S320>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Sum'
//  '<S321>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Sum Fdbk'
//  '<S322>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Tracking Mode'
//  '<S323>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Tracking Mode Sum'
//  '<S324>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Tsamp - Integral'
//  '<S325>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Tsamp - Ngain'
//  '<S326>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/postSat Signal'
//  '<S327>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/preSat Signal'
//  '<S328>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Anti-windup/Disabled'
//  '<S329>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/D Gain/Disabled'
//  '<S330>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Filter/Disabled'
//  '<S331>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Filter ICs/Disabled'
//  '<S332>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/I Gain/Disabled'
//  '<S333>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S334>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Ideal P Gain Fdbk/Disabled'
//  '<S335>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Integrator/Disabled'
//  '<S336>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Integrator ICs/Disabled'
//  '<S337>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/N Copy/Disabled wSignal Specification'
//  '<S338>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/N Gain/Disabled'
//  '<S339>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/P Copy/Disabled'
//  '<S340>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Parallel P Gain/External Parameters'
//  '<S341>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Reset Signal/Disabled'
//  '<S342>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Saturation/External'
//  '<S343>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Saturation/External/Saturation Dynamic'
//  '<S344>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Saturation Fdbk/Disabled'
//  '<S345>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Sum/Passthrough_P'
//  '<S346>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Sum Fdbk/Disabled'
//  '<S347>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S348>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S349>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S350>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S351>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/postSat Signal/Forward_Path'
//  '<S352>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/preSat Signal/Forward_Path'
//  '<S353>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Anti-windup'
//  '<S354>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/D Gain'
//  '<S355>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Filter'
//  '<S356>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Filter ICs'
//  '<S357>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/I Gain'
//  '<S358>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Ideal P Gain'
//  '<S359>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Ideal P Gain Fdbk'
//  '<S360>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Integrator'
//  '<S361>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Integrator ICs'
//  '<S362>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/N Copy'
//  '<S363>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/N Gain'
//  '<S364>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/P Copy'
//  '<S365>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Parallel P Gain'
//  '<S366>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Reset Signal'
//  '<S367>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Saturation'
//  '<S368>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Saturation Fdbk'
//  '<S369>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Sum'
//  '<S370>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Sum Fdbk'
//  '<S371>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Tracking Mode'
//  '<S372>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Tracking Mode Sum'
//  '<S373>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Tsamp - Integral'
//  '<S374>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Tsamp - Ngain'
//  '<S375>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/postSat Signal'
//  '<S376>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/preSat Signal'
//  '<S377>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Anti-windup/Disc. Clamping Parallel'
//  '<S378>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S379>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S380>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/D Gain/External Parameters'
//  '<S381>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Filter/Disc. Forward Euler Filter'
//  '<S382>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Filter ICs/Internal IC - Filter'
//  '<S383>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/I Gain/External Parameters'
//  '<S384>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Ideal P Gain/Passthrough'
//  '<S385>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Ideal P Gain Fdbk/Passthrough'
//  '<S386>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Integrator/Discrete'
//  '<S387>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Integrator ICs/Internal IC'
//  '<S388>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/N Copy/Disabled'
//  '<S389>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/N Gain/External Parameters'
//  '<S390>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/P Copy/Disabled'
//  '<S391>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Parallel P Gain/External Parameters'
//  '<S392>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Reset Signal/Disabled'
//  '<S393>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Saturation/Enabled'
//  '<S394>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Saturation Fdbk/Passthrough'
//  '<S395>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Sum/Sum_PID'
//  '<S396>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Sum Fdbk/Enabled'
//  '<S397>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Tracking Mode/Disabled'
//  '<S398>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Tracking Mode Sum/Passthrough'
//  '<S399>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Tsamp - Integral/TsSignalSpecification'
//  '<S400>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Tsamp - Ngain/Passthrough'
//  '<S401>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/postSat Signal/Feedback_Path'
//  '<S402>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/preSat Signal/Feedback_Path'
//  '<S403>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller'
//  '<S404>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1'
//  '<S405>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2'
//  '<S406>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Anti-windup'
//  '<S407>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/D Gain'
//  '<S408>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Filter'
//  '<S409>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Filter ICs'
//  '<S410>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/I Gain'
//  '<S411>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Ideal P Gain'
//  '<S412>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Ideal P Gain Fdbk'
//  '<S413>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Integrator'
//  '<S414>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Integrator ICs'
//  '<S415>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/N Copy'
//  '<S416>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/N Gain'
//  '<S417>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/P Copy'
//  '<S418>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Parallel P Gain'
//  '<S419>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Reset Signal'
//  '<S420>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Saturation'
//  '<S421>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Saturation Fdbk'
//  '<S422>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Sum'
//  '<S423>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Sum Fdbk'
//  '<S424>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Tracking Mode'
//  '<S425>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Tracking Mode Sum'
//  '<S426>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Tsamp - Integral'
//  '<S427>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Tsamp - Ngain'
//  '<S428>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/postSat Signal'
//  '<S429>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/preSat Signal'
//  '<S430>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S431>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S432>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S433>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/D Gain/External Parameters'
//  '<S434>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S435>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S436>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/I Gain/External Parameters'
//  '<S437>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S438>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S439>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Integrator/Discrete'
//  '<S440>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Integrator ICs/Internal IC'
//  '<S441>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/N Copy/Disabled'
//  '<S442>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/N Gain/External Parameters'
//  '<S443>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/P Copy/Disabled'
//  '<S444>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Parallel P Gain/External Parameters'
//  '<S445>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Reset Signal/Disabled'
//  '<S446>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Saturation/Enabled'
//  '<S447>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S448>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Sum/Sum_PID'
//  '<S449>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Sum Fdbk/Disabled'
//  '<S450>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Tracking Mode/Disabled'
//  '<S451>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S452>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S453>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S454>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/postSat Signal/Forward_Path'
//  '<S455>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/preSat Signal/Forward_Path'
//  '<S456>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Anti-windup'
//  '<S457>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/D Gain'
//  '<S458>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Filter'
//  '<S459>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Filter ICs'
//  '<S460>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/I Gain'
//  '<S461>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Ideal P Gain'
//  '<S462>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S463>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Integrator'
//  '<S464>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Integrator ICs'
//  '<S465>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/N Copy'
//  '<S466>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/N Gain'
//  '<S467>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/P Copy'
//  '<S468>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Parallel P Gain'
//  '<S469>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Reset Signal'
//  '<S470>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Saturation'
//  '<S471>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Saturation Fdbk'
//  '<S472>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Sum'
//  '<S473>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Sum Fdbk'
//  '<S474>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Tracking Mode'
//  '<S475>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Tracking Mode Sum'
//  '<S476>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Tsamp - Integral'
//  '<S477>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Tsamp - Ngain'
//  '<S478>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/postSat Signal'
//  '<S479>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/preSat Signal'
//  '<S480>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S481>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S482>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S483>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/D Gain/External Parameters'
//  '<S484>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S485>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S486>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/I Gain/External Parameters'
//  '<S487>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S488>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S489>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Integrator/Discrete'
//  '<S490>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Integrator ICs/Internal IC'
//  '<S491>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/N Copy/Disabled'
//  '<S492>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/N Gain/External Parameters'
//  '<S493>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/P Copy/Disabled'
//  '<S494>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Parallel P Gain/External Parameters'
//  '<S495>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Reset Signal/Disabled'
//  '<S496>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Saturation/Enabled'
//  '<S497>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S498>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Sum/Sum_PID'
//  '<S499>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S500>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Tracking Mode/Disabled'
//  '<S501>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S502>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S503>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S504>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S505>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S506>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Anti-windup'
//  '<S507>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/D Gain'
//  '<S508>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Filter'
//  '<S509>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Filter ICs'
//  '<S510>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/I Gain'
//  '<S511>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Ideal P Gain'
//  '<S512>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Ideal P Gain Fdbk'
//  '<S513>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Integrator'
//  '<S514>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Integrator ICs'
//  '<S515>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/N Copy'
//  '<S516>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/N Gain'
//  '<S517>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/P Copy'
//  '<S518>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Parallel P Gain'
//  '<S519>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Reset Signal'
//  '<S520>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Saturation'
//  '<S521>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Saturation Fdbk'
//  '<S522>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Sum'
//  '<S523>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Sum Fdbk'
//  '<S524>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Tracking Mode'
//  '<S525>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Tracking Mode Sum'
//  '<S526>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Tsamp - Integral'
//  '<S527>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Tsamp - Ngain'
//  '<S528>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/postSat Signal'
//  '<S529>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/preSat Signal'
//  '<S530>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S531>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S532>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S533>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/D Gain/External Parameters'
//  '<S534>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S535>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S536>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/I Gain/External Parameters'
//  '<S537>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Ideal P Gain/Passthrough'
//  '<S538>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S539>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Integrator/Discrete'
//  '<S540>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Integrator ICs/Internal IC'
//  '<S541>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/N Copy/Disabled'
//  '<S542>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/N Gain/External Parameters'
//  '<S543>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/P Copy/Disabled'
//  '<S544>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Parallel P Gain/External Parameters'
//  '<S545>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Reset Signal/Disabled'
//  '<S546>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Saturation/Enabled'
//  '<S547>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Saturation Fdbk/Disabled'
//  '<S548>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Sum/Sum_PID'
//  '<S549>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Sum Fdbk/Disabled'
//  '<S550>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Tracking Mode/Disabled'
//  '<S551>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S552>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S553>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S554>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/postSat Signal/Forward_Path'
//  '<S555>' : 'MC_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/preSat Signal/Forward_Path'
//  '<S556>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm'
//  '<S557>' : 'MC_HEXA_MISSION/Navigation/uORB Publish'
//  '<S558>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission'
//  '<S559>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem'
//  '<S560>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC'
//  '<S561>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE'
//  '<S562>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land'
//  '<S563>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off'
//  '<S564>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint'
//  '<S565>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE'
//  '<S566>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE/Enabled Subsystem2'
//  '<S567>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land'
//  '<S568>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land'
//  '<S569>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land/Enabled Subsystem'
//  '<S570>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land/Enabled Subsystem2'
//  '<S571>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Ensure smooth ascend during Takeoff'
//  '<S572>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff'
//  '<S573>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff/Enabled Subsystem2'
//  '<S574>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning'
//  '<S575>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning/Compare To Constant'
//  '<S576>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC'
//  '<S577>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC'
//  '<S578>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead'
//  '<S579>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead'
//  '<S580>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/Compare To Constant'
//  '<S581>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read'
//  '<S582>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read/Enabled Subsystem'
//  '<S583>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint'
//  '<S584>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_WayPoint'
//  '<S585>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Empty_WayPoint'
//  '<S586>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Next_WayPoint'
//  '<S587>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Message'
//  '<S588>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Write'
//  '<S589>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP'
//  '<S590>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem'
//  '<S591>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem1'
//  '<S592>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem2'
//  '<S593>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead/Enabled Subsystem'
//  '<S594>' : 'MC_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead/Enabled Subsystem'
//  '<S595>' : 'MC_HEXA_MISSION/Navigation/uORB Publish/PX4 uORB Message'
//  '<S596>' : 'MC_HEXA_MISSION/Navigation/uORB Publish/PX4 uORB Write'
//  '<S597>' : 'MC_HEXA_MISSION/uORBInput/PX4 uORB Read1'
//  '<S598>' : 'MC_HEXA_MISSION/uORBInput/PX4 uORB Read2'
//  '<S599>' : 'MC_HEXA_MISSION/uORBInput/vehicle_attitude'
//  '<S600>' : 'MC_HEXA_MISSION/uORBInput/vehicle_local_pos'
//  '<S601>' : 'MC_HEXA_MISSION/uORBInput/PX4 uORB Read1/Enabled Subsystem'
//  '<S602>' : 'MC_HEXA_MISSION/uORBInput/PX4 uORB Read2/Enabled Subsystem'
//  '<S603>' : 'MC_HEXA_MISSION/uORBInput/vehicle_attitude/Enabled Subsystem'
//  '<S604>' : 'MC_HEXA_MISSION/uORBInput/vehicle_local_pos/Enabled Subsystem'

#endif                                 // RTW_HEADER_MC_HEXA_MISSION_h_

//
// File trailer for generated code.
//
// [EOF]
//
