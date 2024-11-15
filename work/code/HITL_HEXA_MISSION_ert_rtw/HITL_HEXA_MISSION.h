//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: HITL_HEXA_MISSION.h
//
// Code generated for Simulink model 'HITL_HEXA_MISSION'.
//
// Model version                  : 5.5
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Oct 16 17:31:56 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef HITL_HEXA_MISSION_h_
#define HITL_HEXA_MISSION_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "HITL_HEXA_MISSION_types.h"
#include <uORB/topics/vehicle_trajectory_waypoint.h>
#include <uORB/topics/position_setpoint_triplet.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/vehicle_local_position_setpoint.h>
#include <uORB/topics/vehicle_attitude_setpoint.h>
#include <uORB/topics/trajectory_waypoint.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/home_position.h>
#include <uORB/topics/vehicle_rates_setpoint.h>
#include <uORB/topics/vehicle_angular_velocity.h>
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
struct B_PX4Timestamp_HITL_HEXA_MISSION_T {
  uint64_T PX4Timestamp;               // '<S24>/PX4 Timestamp'
};

// Block states (default storage) for system '<S24>/PX4 Timestamp'
struct DW_PX4Timestamp_HITL_HEXA_MISSION_T {
  px4_internal_block_getPX4AbsoluteTime_HITL_HEXA_MISSION_T obj;// '<S24>/PX4 Timestamp' 
  boolean_T objisempty;                // '<S24>/PX4 Timestamp'
};

// Block signals for system '<S603>/MATLAB System'
struct B_MATLABSystem_HITL_HEXA_MISSION_T {
  real32_T MATLABSystem[3];            // '<S603>/MATLAB System'
  real_T dLat;
};

// Block states (default storage) for system '<S603>/MATLAB System'
struct DW_MATLABSystem_HITL_HEXA_MISSION_T {
  px4_internal_block_LLA2LocalCoordinatesNED_HITL_HEXA_MISSION_T obj;// '<S603>/MATLAB System' 
  boolean_T objisempty;                // '<S603>/MATLAB System'
};

// Block signals (default storage)
struct B_HITL_HEXA_MISSION_T {
  px4_Bus_vehicle_trajectory_waypoint BusAssignment1;// '<S597>/Bus Assignment1' 
  px4_Bus_vehicle_trajectory_waypoint In1;// '<S602>/In1'
  px4_Bus_vehicle_trajectory_waypoint r;
  px4_Bus_position_setpoint_triplet In1_p;// '<S614>/In1'
  px4_Bus_position_setpoint_triplet r1;
  px4_Bus_vehicle_local_position In1_c;// '<S624>/In1'
  px4_Bus_vehicle_local_position r2;
  px4_Bus_actuator_outputs BusAssignment;// '<S10>/Bus Assignment'
  px4_Bus_input_rc In1_k;              // '<S20>/In1'
  px4_Bus_input_rc r3;
  real_T b_waypointsIn_data[9];
  real_T MatrixConcatenate_p[9];       // '<S584>/Matrix Concatenate'
  px4_Bus_vehicle_local_position_setpoint BusAssignment_m;// '<S577>/Bus Assignment' 
  px4_Bus_vehicle_attitude_setpoint BusAssignment_h;// '<S24>/Bus Assignment'
  px4_Bus_trajectory_waypoint BusAssignment1_f;// '<S605>/Bus Assignment1'
  px4_Bus_vehicle_attitude In1_m;      // '<S623>/In1'
  px4_Bus_vehicle_attitude r4;
  px4_Bus_home_position In1_f;         // '<S613>/In1'
  px4_Bus_home_position r5;
  px4_Bus_vehicle_rates_setpoint BusAssignment_h4;// '<S25>/Bus Assignment'
  px4_Bus_vehicle_angular_velocity In1_l;// '<S621>/In1'
  px4_Bus_vehicle_angular_velocity r6;
  real_T lla0[3];
  real_T virtualWaypoint[3];
  real_T MatrixConcatenate1[3];        // '<S603>/Matrix Concatenate1'
  real_T MatrixConcatenate1_k[3];      // '<S597>/Matrix Concatenate1'
  real_T dv[3];
  px4_Bus_actuator_armed In1_b;        // '<S622>/In1'
  real_T Merge[4];                     // '<S579>/Merge'
  real_T VectorConcatenate[3];         // '<S36>/Vector Concatenate'
  px4_Bus_actuator_armed r7;
  real_T desiredZ;                     // '<S23>/Gain'
  real_T yaw_In;                       // '<S586>/yaw_In'
  real_T yaw_In_i;                     // '<S590>/yaw_In'
  real_T In;                           // '<S589>/In'
  real_T yaw_In_ik;                    // '<S593>/yaw_In'
  real_T Saturation;                   // '<S462>/Saturation'
  real_T Saturation_c;                 // '<S514>/Saturation'
  real_T Saturation_b;                 // '<S566>/Saturation'
  real_T Saturation_d;                 // '<S407>/Saturation'
  real_T Switch2[2];                   // '<S253>/Switch2'
  real_T Gain1;                        // '<S29>/Gain1'
  real_T Switch2_o;                    // '<S194>/Switch2'
  real_T Switch2_l;                    // '<S92>/Switch2'
  real_T Switch2_n;                    // '<S143>/Switch2'
  real_T PProdOut_pm;                  // '<S352>/PProd Out'
  real_T SinCos_o2;                    // '<S205>/SinCos'
  real_T IProdOut;                     // '<S556>/IProd Out'
  real_T Gain_i;                       // '<S591>/Gain'
  real_T Sum_f;                        // '<S591>/Sum'
  real_T Switch4;                      // '<S6>/Switch4'
  real_T Switch2_a;                    // '<S6>/Switch2'
  real_T Switch1_d;                    // '<S6>/Switch1'
  real_T Gain2_g;                      // '<S5>/Gain2'
  real_T Gain3;                        // '<S5>/Gain3'
  real_T Saturation1;                  // '<S13>/Saturation1'
  real_T rtb_CastToDouble_idx_0;
  real_T rtb_CastToDouble_idx_1;
  real_T dLat;
  real_T dLon;
  real_T flat;
  real_T absx;
  real_T r_m;
  real_T flat_tmp;
  real_T absx_c;
  real_T q;
  real_T scale;
  real_T absxk;
  real_T t;
  boolean_T x[6];
  real32_T ParamStep;
  int32_T ParamStep_k;
  int32_T ParamStep_c;
  int32_T iy;
  int32_T i1;
  int32_T j;
  int32_T ix;
  int32_T b_exponent;
  int32_T b_k;
  int32_T i;
  int32_T i1_b;
  int8_T tmp_data[3];
  boolean_T distinctWptsIdx[3];
  boolean_T b[3];
  boolean_T IsNaN_l[2];                // '<S582>/IsNaN'
  int8_T rtPrevAction;
  int8_T rtAction;
  boolean_T Compare_k;                 // '<S11>/Compare'
  boolean_T OR_g;                      // '<S582>/OR'
  boolean_T Compare;                   // '<S12>/Compare'
  boolean_T latp2;
  B_PX4Timestamp_HITL_HEXA_MISSION_T PX4Timestamp_pn;// '<S24>/PX4 Timestamp'
  B_MATLABSystem_HITL_HEXA_MISSION_T MATLABSystem_b;// '<S603>/MATLAB System'
  B_MATLABSystem_HITL_HEXA_MISSION_T MATLABSystem;// '<S603>/MATLAB System'
  B_PX4Timestamp_HITL_HEXA_MISSION_T PX4Timestamp_o;// '<S24>/PX4 Timestamp'
  B_PX4Timestamp_HITL_HEXA_MISSION_T PX4Timestamp_p;// '<S24>/PX4 Timestamp'
  B_PX4Timestamp_HITL_HEXA_MISSION_T PX4Timestamp;// '<S24>/PX4 Timestamp'
};

// Block states (default storage) for system '<Root>'
struct DW_HITL_HEXA_MISSION_T {
  uav_sluav_internal_system_WaypointFollower_HITL_HEXA_MISSION_T obj;// '<S584>/UAV Waypoint Follower' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_b;// '<S611>/Read Parameter' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_g;// '<S612>/Read Parameter' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_k;// '<S580>/Read Parameter' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_n;// '<S30>/Read Parameter24' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_f;// '<S30>/Read Parameter23' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_d;// '<S30>/Read Parameter22' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_j;// '<S30>/Read Parameter21' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_l;// '<S30>/Read Parameter20' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_nu;// '<S30>/Read Parameter19' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_h;// '<S30>/Read Parameter18' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_hj;// '<S30>/Read Parameter17' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_gu;// '<S30>/Read Parameter16' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_gf;// '<S29>/Read Parameter8' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_m;// '<S29>/Read Parameter7' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_i;// '<S29>/Read Parameter3' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_kf;// '<S29>/Read Parameter2' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_c;// '<S29>/Read Parameter15' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_p;// '<S29>/Read Parameter14' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_n3;// '<S29>/Read Parameter13' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_do;// '<S29>/Read Parameter12' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_mt;// '<S29>/Read Parameter1' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_o;// '<S29>/Read Parameter' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_pk;// '<S28>/Read Parameter9' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_m5;// '<S28>/Read Parameter6' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_jv;// '<S28>/Read Parameter5' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_km;// '<S28>/Read Parameter4' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_hg;// '<S28>/Read Parameter11' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_g2;// '<S28>/Read Parameter10' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_p1;// '<S7>/Read Parameter5' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_cf;// '<S7>/Read Parameter4' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_n0;// '<S7>/Read Parameter3' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_ng;// '<S7>/Read Parameter2' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_ka;// '<S7>/Read Parameter13' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_MISSION_T obj_a;// '<S7>/Read Parameter1' 
  px4_internal_block_Subscriber_HITL_HEXA_MISSION_T obj_mg;// '<S620>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_MISSION_T obj_gv;// '<S619>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_MISSION_T obj_d0;// '<S618>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_MISSION_T obj_po;// '<S617>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_MISSION_T obj_kz;// '<S599>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_MISSION_T obj_gff;// '<S598>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_MISSION_T obj_e;// '<S601>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_MISSION_T obj_da;// '<S19>/SourceBlock' 
  px4_internal_block_Publisher_HITL_HEXA_MISSION_T obj_o2;// '<S616>/SinkBlock'
  px4_internal_block_Publisher_HITL_HEXA_MISSION_T obj_mc;// '<S608>/SinkBlock'
  px4_internal_block_Publisher_HITL_HEXA_MISSION_T obj_dz;// '<S34>/SinkBlock'
  px4_internal_block_Publisher_HITL_HEXA_MISSION_T obj_mgm;// '<S32>/SinkBlock'
  px4_internal_block_Publisher_HITL_HEXA_MISSION_T obj_hy;// '<S22>/SinkBlock'
  px4_internal_block_LLA2LocalCoordinates_HITL_HEXA_MISSION_T obj_mr;// '<S580>/LLA2LocalCoordinates' 
  real_T Delay_DSTATE;                 // '<S585>/Delay'
  real_T Delay_DSTATE_l[2];            // '<S582>/Delay'
  real_T Delay_DSTATE_n;               // '<S587>/Delay'
  real_T Delay_DSTATE_b;               // '<S588>/Delay'
  real_T Delay_DSTATE_c;               // '<S591>/Delay'
  real_T Delay_DSTATE_d;               // '<S592>/Delay'
  real_T Filter_DSTATE;                // '<S450>/Filter'
  real_T Integrator_DSTATE;            // '<S455>/Integrator'
  real_T Filter_DSTATE_h;              // '<S502>/Filter'
  real_T Integrator_DSTATE_d;          // '<S507>/Integrator'
  real_T Filter_DSTATE_l;              // '<S554>/Filter'
  real_T Integrator_DSTATE_dd;         // '<S559>/Integrator'
  real_T Filter_DSTATE_m;              // '<S395>/Filter'
  real_T Integrator_DSTATE_c;          // '<S400>/Integrator'
  real_T PrevY;                        // '<S28>/Rate Limiter2'
  real_T PrevY_b;                      // '<S28>/Rate Limiter1'
  px4_internal_block_LLA2LocalCoordinatesNED_HITL_HEXA_MISSION_T obj_mu;// '<S606>/MATLAB System' 
  int8_T If_ActiveSubsystem;           // '<S579>/If'
  DW_PX4Timestamp_HITL_HEXA_MISSION_T PX4Timestamp_pn;// '<S24>/PX4 Timestamp'
  DW_MATLABSystem_HITL_HEXA_MISSION_T MATLABSystem_b;// '<S603>/MATLAB System'
  DW_MATLABSystem_HITL_HEXA_MISSION_T MATLABSystem;// '<S603>/MATLAB System'
  DW_PX4Timestamp_HITL_HEXA_MISSION_T PX4Timestamp_o;// '<S24>/PX4 Timestamp'
  DW_PX4Timestamp_HITL_HEXA_MISSION_T PX4Timestamp_p;// '<S24>/PX4 Timestamp'
  DW_PX4Timestamp_HITL_HEXA_MISSION_T PX4Timestamp;// '<S24>/PX4 Timestamp'
};

// Parameters (default storage)
struct P_HITL_HEXA_MISSION_T_ {
  real_T PID_vz_InitialConditionForFilter;
                             // Mask Parameter: PID_vz_InitialConditionForFilter
                                //  Referenced by: '<S395>/Filter'

  real_T PIDController_InitialConditionForFilter;
                      // Mask Parameter: PIDController_InitialConditionForFilter
                         //  Referenced by: '<S450>/Filter'

  real_T PIDController1_InitialConditionForFilter;
                     // Mask Parameter: PIDController1_InitialConditionForFilter
                        //  Referenced by: '<S502>/Filter'

  real_T PIDController2_InitialConditionForFilter;
                     // Mask Parameter: PIDController2_InitialConditionForFilter
                        //  Referenced by: '<S554>/Filter'

  real_T PID_vz_InitialConditionForIntegrator;
                         // Mask Parameter: PID_vz_InitialConditionForIntegrator
                            //  Referenced by: '<S400>/Integrator'

  real_T PIDController_InitialConditionForIntegrator;
                  // Mask Parameter: PIDController_InitialConditionForIntegrator
                     //  Referenced by: '<S455>/Integrator'

  real_T PIDController1_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController1_InitialConditionForIntegrator
                    //  Referenced by: '<S507>/Integrator'

  real_T PIDController2_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController2_InitialConditionForIntegrator
                    //  Referenced by: '<S559>/Integrator'

  real_T PID_vz_LowerSaturationLimit;
                                  // Mask Parameter: PID_vz_LowerSaturationLimit
                                     //  Referenced by:
                                     //    '<S407>/Saturation'
                                     //    '<S392>/DeadZone'

  real_T PIDController_LowerSaturationLimit;
                           // Mask Parameter: PIDController_LowerSaturationLimit
                              //  Referenced by:
                              //    '<S462>/Saturation'
                              //    '<S447>/DeadZone'

  real_T PIDController1_LowerSaturationLimit;
                          // Mask Parameter: PIDController1_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S514>/Saturation'
                             //    '<S499>/DeadZone'

  real_T PIDController2_LowerSaturationLimit;
                          // Mask Parameter: PIDController2_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S566>/Saturation'
                             //    '<S551>/DeadZone'

  real_T PID_vz_UpperSaturationLimit;
                                  // Mask Parameter: PID_vz_UpperSaturationLimit
                                     //  Referenced by:
                                     //    '<S407>/Saturation'
                                     //    '<S392>/DeadZone'

  real_T PIDController_UpperSaturationLimit;
                           // Mask Parameter: PIDController_UpperSaturationLimit
                              //  Referenced by:
                              //    '<S462>/Saturation'
                              //    '<S447>/DeadZone'

  real_T PIDController1_UpperSaturationLimit;
                          // Mask Parameter: PIDController1_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S514>/Saturation'
                             //    '<S499>/DeadZone'

  real_T PIDController2_UpperSaturationLimit;
                          // Mask Parameter: PIDController2_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S566>/Saturation'
                             //    '<S551>/DeadZone'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S11>/Constant'

  uint16_T CompareToConstant_const_k;
                                    // Mask Parameter: CompareToConstant_const_k
                                       //  Referenced by: '<S12>/Constant'

  uint8_T CompareToConstant_const_d;// Mask Parameter: CompareToConstant_const_d
                                       //  Referenced by: '<S595>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Out1_Y0;// Computed Parameter: Out1_Y0
                                                 //  Referenced by: '<S602>/Out1'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value;// Computed Parameter: Constant_Value
                                                        //  Referenced by: '<S607>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                          //  Referenced by: '<S601>/Constant'

  px4_Bus_position_setpoint_triplet Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                 //  Referenced by: '<S614>/Out1'

  px4_Bus_position_setpoint_triplet Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                        //  Referenced by: '<S599>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                              //  Referenced by: '<S624>/Out1'

  px4_Bus_vehicle_local_position Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                     //  Referenced by: '<S620>/Constant'

  px4_Bus_actuator_outputs Constant_Value_c;// Computed Parameter: Constant_Value_c
                                               //  Referenced by: '<S21>/Constant'

  px4_Bus_input_rc Out1_Y0_i;          // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S20>/Out1'

  px4_Bus_input_rc Constant_Value_l;   // Computed Parameter: Constant_Value_l
                                          //  Referenced by: '<S19>/Constant'

  px4_Bus_vehicle_local_position_setpoint Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                              //  Referenced by: '<S615>/Constant'

  px4_Bus_vehicle_attitude Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S623>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_lh;// Computed Parameter: Constant_Value_lh
                                                //  Referenced by: '<S619>/Constant'

  px4_Bus_vehicle_attitude_setpoint Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                        //  Referenced by: '<S31>/Constant'

  px4_Bus_home_position Out1_Y0_o;     // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S613>/Out1'

  px4_Bus_home_position Constant_Value_b0;// Computed Parameter: Constant_Value_b0
                                             //  Referenced by: '<S598>/Constant'

  px4_Bus_vehicle_angular_velocity Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                //  Referenced by: '<S621>/Out1'

  px4_Bus_vehicle_angular_velocity Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                       //  Referenced by: '<S617>/Constant'

  px4_Bus_vehicle_rates_setpoint Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                     //  Referenced by: '<S33>/Constant'

  px4_Bus_actuator_armed Out1_Y0_d;    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S622>/Out1'

  px4_Bus_actuator_armed Constant_Value_jl;// Computed Parameter: Constant_Value_jl
                                              //  Referenced by: '<S618>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S6>/Constant1'

  real_T Constant1_Value_j;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant1'

  real_T Gain_Gain;                    // Expression: 0.01
                                          //  Referenced by: '<S14>/Gain'

  real_T Saturation1_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S14>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: 0
                                          //  Referenced by: '<S14>/Saturation1'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S6>/Constant2'

  real_T Constant2_Value_o;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant2'

  real_T Gain_Gain_f;                  // Expression: 0.01
                                          //  Referenced by: '<S15>/Gain'

  real_T Saturation1_UpperSat_g;       // Expression: 1
                                          //  Referenced by: '<S15>/Saturation1'

  real_T Saturation1_LowerSat_c;       // Expression: 0
                                          //  Referenced by: '<S15>/Saturation1'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<S6>/Constant3'

  real_T Constant3_Value_b;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant3'

  real_T Gain_Gain_f4;                 // Expression: 0.01
                                          //  Referenced by: '<S16>/Gain'

  real_T Saturation1_UpperSat_d;       // Expression: 1
                                          //  Referenced by: '<S16>/Saturation1'

  real_T Saturation1_LowerSat_d;       // Expression: 0
                                          //  Referenced by: '<S16>/Saturation1'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<S6>/Constant4'

  real_T Constant4_Value_e;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant4'

  real_T Gain_Gain_c;                  // Expression: 0.01
                                          //  Referenced by: '<S17>/Gain'

  real_T Saturation1_UpperSat_gv;      // Expression: 1
                                          //  Referenced by: '<S17>/Saturation1'

  real_T Saturation1_LowerSat_b;       // Expression: 0
                                          //  Referenced by: '<S17>/Saturation1'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<S6>/Constant5'

  real_T Constant5_Value_f;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant5'

  real_T Gain_Gain_l;                  // Expression: 0.01
                                          //  Referenced by: '<S18>/Gain'

  real_T Saturation1_UpperSat_i;       // Expression: 1
                                          //  Referenced by: '<S18>/Saturation1'

  real_T Saturation1_LowerSat_i;       // Expression: 0
                                          //  Referenced by: '<S18>/Saturation1'

  real_T Constant_Value_a;             // Expression: 0
                                          //  Referenced by: '<S6>/Constant'

  real_T Constant_Value_d3;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant'

  real_T Gain_Gain_m;                  // Expression: 0.01
                                          //  Referenced by: '<S13>/Gain'

  real_T Saturation1_UpperSat_ik;      // Expression: 1
                                          //  Referenced by: '<S13>/Saturation1'

  real_T Saturation1_LowerSat_n;       // Expression: 0
                                          //  Referenced by: '<S13>/Saturation1'

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
                                          //  Referenced by: '<S204>/Constant'

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
                                          //  Referenced by: '<S390>/Constant1'

  real_T Constant_Value_p3;            // Expression: 10
                                          //  Referenced by: '<S29>/Constant'

  real_T Clamping_zero_Value;          // Expression: 0
                                          //  Referenced by: '<S390>/Clamping_zero'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S395>/Filter'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S400>/Integrator'

  real_T Gain_Gain_l2;                 // Expression: -1
                                          //  Referenced by: '<S205>/Gain'

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
                                          //  Referenced by: '<S445>/Constant1'

  real_T Constant1_Value_jx;           // Expression: 0
                                          //  Referenced by: '<S497>/Constant1'

  real_T Constant1_Value_ka;           // Expression: 0
                                          //  Referenced by: '<S549>/Constant1'

  real_T Constant_Value_pd;            // Expression: 100
                                          //  Referenced by: '<S30>/Constant'

  real_T Filter_gainval_f;             // Computed Parameter: Filter_gainval_f
                                          //  Referenced by: '<S450>/Filter'

  real_T Integrator_gainval_h;       // Computed Parameter: Integrator_gainval_h
                                        //  Referenced by: '<S455>/Integrator'

  real_T Clamping_zero_Value_i;        // Expression: 0
                                          //  Referenced by: '<S445>/Clamping_zero'

  real_T Constant1_Value_f;            // Expression: 50
                                          //  Referenced by: '<S30>/Constant1'

  real_T Filter_gainval_l;             // Computed Parameter: Filter_gainval_l
                                          //  Referenced by: '<S502>/Filter'

  real_T Integrator_gainval_b;       // Computed Parameter: Integrator_gainval_b
                                        //  Referenced by: '<S507>/Integrator'

  real_T Clamping_zero_Value_d;        // Expression: 0
                                          //  Referenced by: '<S497>/Clamping_zero'

  real_T Constant2_Value_n;            // Expression: 50
                                          //  Referenced by: '<S30>/Constant2'

  real_T Filter_gainval_a;             // Computed Parameter: Filter_gainval_a
                                          //  Referenced by: '<S554>/Filter'

  real_T Integrator_gainval_n;       // Computed Parameter: Integrator_gainval_n
                                        //  Referenced by: '<S559>/Integrator'

  real_T Clamping_zero_Value_e;        // Expression: 0
                                          //  Referenced by: '<S549>/Clamping_zero'

  real_T yaw_Out_Y0;                   // Computed Parameter: yaw_Out_Y0
                                          //  Referenced by: '<S593>/yaw_Out'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S591>/Delay'

  real_T Rate_Value;                   // Expression: 0.01
                                          //  Referenced by: '<S591>/Rate'

  real_T Gain1_Gain_b;                 // Expression: -1
                                          //  Referenced by: '<S591>/Gain1'

  real_T Gain_Gain_e;                  // Expression: -1
                                          //  Referenced by: '<S591>/Gain'

  real_T Delay_InitialCondition_g;     // Expression: 1
                                          //  Referenced by: '<S592>/Delay'

  real_T Constant_Value_f;             // Expression: 0
                                          //  Referenced by: '<S592>/Constant'

  real_T Out_Y0;                       // Computed Parameter: Out_Y0
                                          //  Referenced by: '<S589>/Out'

  real_T Gain_Gain_ls;                 // Expression: -1
                                          //  Referenced by: '<S587>/Gain'

  real_T yaw_Out_Y0_f;                 // Computed Parameter: yaw_Out_Y0_f
                                          //  Referenced by: '<S590>/yaw_Out'

  real_T Delay_InitialCondition_n;     // Expression: 0.0
                                          //  Referenced by: '<S582>/Delay'

  real_T Delay_InitialCondition_m;     // Expression: 0.0
                                          //  Referenced by: '<S587>/Delay'

  real_T Switch_Threshold_j;           // Expression: 0
                                          //  Referenced by: '<S587>/Switch'

  real_T Rateofdescent_Value;          // Expression: 0.02
                                          //  Referenced by: '<S587>/Rate of descent'

  real_T Gain2_Gain;                   // Expression: -1
                                          //  Referenced by: '<S587>/Gain2'

  real_T Gain1_Gain_a;                 // Expression: -1
                                          //  Referenced by: '<S587>/Gain1'

  real_T Delay_InitialCondition_j;     // Expression: 1
                                          //  Referenced by: '<S588>/Delay'

  real_T Constant_Value_nn;            // Expression: 0
                                          //  Referenced by: '<S588>/Constant'

  real_T Constant_Value_jd;            // Expression: 0
                                          //  Referenced by: '<S594>/Constant'

  real_T Constant_Value_gw;            // Expression: 6
                                          //  Referenced by: '<S584>/Constant'

  real_T yaw_Out_Y0_p;                 // Computed Parameter: yaw_Out_Y0_p
                                          //  Referenced by: '<S586>/yaw_Out'

  real_T Delay_InitialCondition_g0;    // Expression: 1
                                          //  Referenced by: '<S585>/Delay'

  real_T Constant_Value_ic;            // Expression: 0
                                          //  Referenced by: '<S585>/Constant'

  real_T ReadParameter_SampleTime_d;   // Expression: -1
                                          //  Referenced by: '<S580>/Read Parameter'

  real_T ReadParameter_SampleTime_c;   // Expression: -1
                                          //  Referenced by: '<S612>/Read Parameter'

  real_T ReadParameter_SampleTime_g;   // Expression: -1
                                          //  Referenced by: '<S611>/Read Parameter'

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
                                          //  Referenced by: '<S605>/Constant7'

  real32_T Gain1_Gain_k;               // Computed Parameter: Gain1_Gain_k
                                          //  Referenced by: '<S47>/Gain1'

  real32_T Gain1_Gain_i;               // Computed Parameter: Gain1_Gain_i
                                          //  Referenced by: '<S45>/Gain1'

  real32_T Gain1_Gain_o;               // Computed Parameter: Gain1_Gain_o
                                          //  Referenced by: '<S46>/Gain1'

  real32_T Gain1_Gain_o1;              // Computed Parameter: Gain1_Gain_o1
                                          //  Referenced by: '<S204>/Gain1'

  real32_T Gain1_Gain_p;               // Computed Parameter: Gain1_Gain_p
                                          //  Referenced by: '<S206>/Gain1'

  real32_T Gain_Gain_md;               // Computed Parameter: Gain_Gain_md
                                          //  Referenced by: '<S29>/Gain'

  real32_T Gain2_Gain_i;               // Computed Parameter: Gain2_Gain_i
                                          //  Referenced by: '<S29>/Gain2'

  real32_T Constant1_Value_d[2];       // Computed Parameter: Constant1_Value_d
                                          //  Referenced by: '<S612>/Constant1'

  real32_T Constant_Value_f2;          // Computed Parameter: Constant_Value_f2
                                          //  Referenced by: '<S612>/Constant'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S611>/Gain'

  real32_T Constant1_Value_k4[2];      // Computed Parameter: Constant1_Value_k4
                                          //  Referenced by: '<S611>/Constant1'

  real32_T Constant_Value_l4;          // Computed Parameter: Constant_Value_l4
                                          //  Referenced by: '<S611>/Constant'

  real32_T Constant_Value_fh[3];       // Computed Parameter: Constant_Value_fh
                                          //  Referenced by: '<S605>/Constant'

  real32_T Constant1_Value_h[3];       // Computed Parameter: Constant1_Value_h
                                          //  Referenced by: '<S605>/Constant1'

  real32_T Constant2_Value_f[3];       // Computed Parameter: Constant2_Value_f
                                          //  Referenced by: '<S605>/Constant2'

  real32_T Constant3_Value_a;          // Computed Parameter: Constant3_Value_a
                                          //  Referenced by: '<S605>/Constant3'

  real32_T Constant4_Value_g;          // Computed Parameter: Constant4_Value_g
                                          //  Referenced by: '<S605>/Constant4'

  boolean_T Constant5_Value_j;         // Computed Parameter: Constant5_Value_j
                                          //  Referenced by: '<S603>/Constant5'

  boolean_T Constant5_Value_k;         // Computed Parameter: Constant5_Value_k
                                          //  Referenced by: '<S604>/Constant5'

  boolean_T Constant1_Value_dl;        // Computed Parameter: Constant1_Value_dl
                                          //  Referenced by: '<S606>/Constant1'

  boolean_T Constant5_Value_h;         // Computed Parameter: Constant5_Value_h
                                          //  Referenced by: '<S606>/Constant5'

  boolean_T Constant5_Value_l;         // Computed Parameter: Constant5_Value_l
                                          //  Referenced by: '<S605>/Constant5'

  int8_T Constant_Value_mp;            // Computed Parameter: Constant_Value_mp
                                          //  Referenced by: '<S390>/Constant'

  int8_T Constant2_Value_k;            // Computed Parameter: Constant2_Value_k
                                          //  Referenced by: '<S390>/Constant2'

  int8_T Constant3_Value_i;            // Computed Parameter: Constant3_Value_i
                                          //  Referenced by: '<S390>/Constant3'

  int8_T Constant4_Value_j;            // Computed Parameter: Constant4_Value_j
                                          //  Referenced by: '<S390>/Constant4'

  int8_T Constant_Value_dt;            // Computed Parameter: Constant_Value_dt
                                          //  Referenced by: '<S445>/Constant'

  int8_T Constant2_Value_l;            // Computed Parameter: Constant2_Value_l
                                          //  Referenced by: '<S445>/Constant2'

  int8_T Constant3_Value_j;            // Computed Parameter: Constant3_Value_j
                                          //  Referenced by: '<S445>/Constant3'

  int8_T Constant4_Value_c;            // Computed Parameter: Constant4_Value_c
                                          //  Referenced by: '<S445>/Constant4'

  int8_T Constant_Value_d5;            // Computed Parameter: Constant_Value_d5
                                          //  Referenced by: '<S497>/Constant'

  int8_T Constant2_Value_e;            // Computed Parameter: Constant2_Value_e
                                          //  Referenced by: '<S497>/Constant2'

  int8_T Constant3_Value_k;            // Computed Parameter: Constant3_Value_k
                                          //  Referenced by: '<S497>/Constant3'

  int8_T Constant4_Value_n;            // Computed Parameter: Constant4_Value_n
                                          //  Referenced by: '<S497>/Constant4'

  int8_T Constant_Value_k;             // Computed Parameter: Constant_Value_k
                                          //  Referenced by: '<S549>/Constant'

  int8_T Constant2_Value_m;            // Computed Parameter: Constant2_Value_m
                                          //  Referenced by: '<S549>/Constant2'

  int8_T Constant3_Value_d;            // Computed Parameter: Constant3_Value_d
                                          //  Referenced by: '<S549>/Constant3'

  int8_T Constant4_Value_b;            // Computed Parameter: Constant4_Value_b
                                          //  Referenced by: '<S549>/Constant4'

  uint8_T Constant_Value_fm;           // Computed Parameter: Constant_Value_fm
                                          //  Referenced by: '<S597>/Constant'

  uint8_T Constant6_Value;             // Computed Parameter: Constant6_Value
                                          //  Referenced by: '<S605>/Constant6'

};

// Real-time Model Data Structure
struct tag_RTM_HITL_HEXA_MISSION_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_HITL_HEXA_MISSION_T HITL_HEXA_MISSION_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_HITL_HEXA_MISSION_T HITL_HEXA_MISSION_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_HITL_HEXA_MISSION_T HITL_HEXA_MISSION_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void HITL_HEXA_MISSION_initialize(void);
  extern void HITL_HEXA_MISSION_step(void);
  extern void HITL_HEXA_MISSION_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_HITL_HEXA_MISSION_T *const HITL_HEXA_MISSION_M;

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
//  Block '<S92>/Data Type Duplicate' : Unused code path elimination
//  Block '<S92>/Data Type Propagation' : Unused code path elimination
//  Block '<S143>/Data Type Duplicate' : Unused code path elimination
//  Block '<S143>/Data Type Propagation' : Unused code path elimination
//  Block '<S194>/Data Type Duplicate' : Unused code path elimination
//  Block '<S194>/Data Type Propagation' : Unused code path elimination
//  Block '<S211>/Data Type Duplicate' : Unused code path elimination
//  Block '<S211>/Data Type Propagation' : Unused code path elimination
//  Block '<S253>/Data Type Duplicate' : Unused code path elimination
//  Block '<S253>/Data Type Propagation' : Unused code path elimination
//  Block '<S304>/Data Type Duplicate' : Unused code path elimination
//  Block '<S304>/Data Type Propagation' : Unused code path elimination
//  Block '<S355>/Data Type Duplicate' : Unused code path elimination
//  Block '<S355>/Data Type Propagation' : Unused code path elimination
//  Block '<S600>/Compare' : Unused code path elimination
//  Block '<S600>/Constant' : Unused code path elimination
//  Block '<S601>/NOT' : Unused code path elimination
//  Block '<S596>/Subtract' : Unused code path elimination
//  Block '<S598>/NOT' : Unused code path elimination
//  Block '<S599>/NOT' : Unused code path elimination
//  Block '<S617>/NOT' : Unused code path elimination
//  Block '<S618>/NOT' : Unused code path elimination
//  Block '<S619>/NOT' : Unused code path elimination
//  Block '<S620>/NOT' : Unused code path elimination
//  Block '<S582>/Reshape1' : Reshape block reduction
//  Block '<S594>/Reshape3' : Reshape block reduction
//  Block '<S584>/Reshape1' : Reshape block reduction
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
//  '<Root>' : 'HITL_HEXA_MISSION'
//  '<S1>'   : 'HITL_HEXA_MISSION/Actuator'
//  '<S2>'   : 'HITL_HEXA_MISSION/CLAW'
//  '<S3>'   : 'HITL_HEXA_MISSION/Navigation'
//  '<S4>'   : 'HITL_HEXA_MISSION/uORBInput'
//  '<S5>'   : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block'
//  '<S6>'   : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Emergency Kill'
//  '<S7>'   : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Fault_Injection'
//  '<S8>'   : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/MATLAB Function'
//  '<S9>'   : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Radio Control Transmitter'
//  '<S10>'  : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Subsystem'
//  '<S11>'  : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Emergency Kill/Compare To Constant'
//  '<S12>'  : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Compare To Constant'
//  '<S13>'  : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference'
//  '<S14>'  : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference1'
//  '<S15>'  : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference2'
//  '<S16>'  : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference3'
//  '<S17>'  : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference4'
//  '<S18>'  : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference5'
//  '<S19>'  : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Radio Control Transmitter/PX4 uORB Read'
//  '<S20>'  : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S21>'  : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Subsystem/PX4 uORB Message'
//  '<S22>'  : 'HITL_HEXA_MISSION/Actuator/Custom Mixer and PWM Output Block/Subsystem/PX4 uORB Write'
//  '<S23>'  : 'HITL_HEXA_MISSION/CLAW/Controller'
//  '<S24>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Publish vehicle_attitude_setpoint'
//  '<S25>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Publish vehicle_rate_setpoint'
//  '<S26>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Quaternion Validity Check'
//  '<S27>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles'
//  '<S28>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller'
//  '<S29>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller'
//  '<S30>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller'
//  '<S31>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Publish vehicle_attitude_setpoint/PX4 uORB Message'
//  '<S32>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Publish vehicle_attitude_setpoint/PX4 uORB Write'
//  '<S33>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Publish vehicle_rate_setpoint/PX4 uORB Message'
//  '<S34>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Publish vehicle_rate_setpoint/PX4 uORB Write'
//  '<S35>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Quaternion Validity Check/Quaternion Norm'
//  '<S36>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation'
//  '<S37>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S38>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S39>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S40>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S41>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S42>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S43>'  : 'HITL_HEXA_MISSION/CLAW/Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S44>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/Calculate minimum Turn'
//  '<S45>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/Degrees to Radians'
//  '<S46>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/Degrees to Radians1'
//  '<S47>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/Degrees to Radians2'
//  '<S48>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3'
//  '<S49>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4'
//  '<S50>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5'
//  '<S51>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Anti-windup'
//  '<S52>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/D Gain'
//  '<S53>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/External Derivative'
//  '<S54>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Filter'
//  '<S55>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Filter ICs'
//  '<S56>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/I Gain'
//  '<S57>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Ideal P Gain'
//  '<S58>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Ideal P Gain Fdbk'
//  '<S59>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Integrator'
//  '<S60>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Integrator ICs'
//  '<S61>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/N Copy'
//  '<S62>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/N Gain'
//  '<S63>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/P Copy'
//  '<S64>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Parallel P Gain'
//  '<S65>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Reset Signal'
//  '<S66>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Saturation'
//  '<S67>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Saturation Fdbk'
//  '<S68>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Sum'
//  '<S69>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Sum Fdbk'
//  '<S70>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Tracking Mode'
//  '<S71>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Tracking Mode Sum'
//  '<S72>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Tsamp - Integral'
//  '<S73>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Tsamp - Ngain'
//  '<S74>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/postSat Signal'
//  '<S75>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/preSat Signal'
//  '<S76>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Anti-windup/Disabled'
//  '<S77>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/D Gain/Disabled'
//  '<S78>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/External Derivative/Disabled'
//  '<S79>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Filter/Disabled'
//  '<S80>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Filter ICs/Disabled'
//  '<S81>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/I Gain/Disabled'
//  '<S82>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Ideal P Gain/Passthrough'
//  '<S83>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S84>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Integrator/Disabled'
//  '<S85>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Integrator ICs/Disabled'
//  '<S86>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S87>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/N Gain/Disabled'
//  '<S88>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/P Copy/Disabled'
//  '<S89>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Parallel P Gain/External Parameters'
//  '<S90>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Reset Signal/Disabled'
//  '<S91>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Saturation/External'
//  '<S92>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Saturation/External/Saturation Dynamic'
//  '<S93>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Saturation Fdbk/Disabled'
//  '<S94>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Sum/Passthrough_P'
//  '<S95>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Sum Fdbk/Disabled'
//  '<S96>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Tracking Mode/Disabled'
//  '<S97>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S98>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S99>'  : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S100>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/postSat Signal/Forward_Path'
//  '<S101>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller3/preSat Signal/Forward_Path'
//  '<S102>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Anti-windup'
//  '<S103>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/D Gain'
//  '<S104>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/External Derivative'
//  '<S105>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Filter'
//  '<S106>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Filter ICs'
//  '<S107>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/I Gain'
//  '<S108>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Ideal P Gain'
//  '<S109>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S110>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Integrator'
//  '<S111>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Integrator ICs'
//  '<S112>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/N Copy'
//  '<S113>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/N Gain'
//  '<S114>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/P Copy'
//  '<S115>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Parallel P Gain'
//  '<S116>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Reset Signal'
//  '<S117>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Saturation'
//  '<S118>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Saturation Fdbk'
//  '<S119>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Sum'
//  '<S120>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Sum Fdbk'
//  '<S121>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Tracking Mode'
//  '<S122>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Tracking Mode Sum'
//  '<S123>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Tsamp - Integral'
//  '<S124>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Tsamp - Ngain'
//  '<S125>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/postSat Signal'
//  '<S126>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/preSat Signal'
//  '<S127>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Anti-windup/Disabled'
//  '<S128>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/D Gain/Disabled'
//  '<S129>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/External Derivative/Disabled'
//  '<S130>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Filter/Disabled'
//  '<S131>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Filter ICs/Disabled'
//  '<S132>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/I Gain/Disabled'
//  '<S133>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S134>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S135>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Integrator/Disabled'
//  '<S136>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Integrator ICs/Disabled'
//  '<S137>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S138>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/N Gain/Disabled'
//  '<S139>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/P Copy/Disabled'
//  '<S140>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Parallel P Gain/External Parameters'
//  '<S141>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Reset Signal/Disabled'
//  '<S142>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Saturation/External'
//  '<S143>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Saturation/External/Saturation Dynamic'
//  '<S144>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S145>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Sum/Passthrough_P'
//  '<S146>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S147>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Tracking Mode/Disabled'
//  '<S148>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S149>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S150>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S151>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S152>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S153>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Anti-windup'
//  '<S154>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/D Gain'
//  '<S155>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/External Derivative'
//  '<S156>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Filter'
//  '<S157>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Filter ICs'
//  '<S158>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/I Gain'
//  '<S159>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Ideal P Gain'
//  '<S160>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Ideal P Gain Fdbk'
//  '<S161>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Integrator'
//  '<S162>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Integrator ICs'
//  '<S163>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/N Copy'
//  '<S164>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/N Gain'
//  '<S165>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/P Copy'
//  '<S166>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Parallel P Gain'
//  '<S167>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Reset Signal'
//  '<S168>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Saturation'
//  '<S169>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Saturation Fdbk'
//  '<S170>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Sum'
//  '<S171>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Sum Fdbk'
//  '<S172>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Tracking Mode'
//  '<S173>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Tracking Mode Sum'
//  '<S174>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Tsamp - Integral'
//  '<S175>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Tsamp - Ngain'
//  '<S176>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/postSat Signal'
//  '<S177>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/preSat Signal'
//  '<S178>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Anti-windup/Disabled'
//  '<S179>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/D Gain/Disabled'
//  '<S180>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/External Derivative/Disabled'
//  '<S181>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Filter/Disabled'
//  '<S182>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Filter ICs/Disabled'
//  '<S183>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/I Gain/Disabled'
//  '<S184>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Ideal P Gain/Passthrough'
//  '<S185>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Ideal P Gain Fdbk/Disabled'
//  '<S186>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Integrator/Disabled'
//  '<S187>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Integrator ICs/Disabled'
//  '<S188>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/N Copy/Disabled wSignal Specification'
//  '<S189>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/N Gain/Disabled'
//  '<S190>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/P Copy/Disabled'
//  '<S191>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Parallel P Gain/External Parameters'
//  '<S192>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Reset Signal/Disabled'
//  '<S193>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Saturation/External'
//  '<S194>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Saturation/External/Saturation Dynamic'
//  '<S195>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Saturation Fdbk/Disabled'
//  '<S196>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Sum/Passthrough_P'
//  '<S197>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Sum Fdbk/Disabled'
//  '<S198>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Tracking Mode/Disabled'
//  '<S199>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Tracking Mode Sum/Passthrough'
//  '<S200>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Tsamp - Integral/TsSignalSpecification'
//  '<S201>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/Tsamp - Ngain/Passthrough'
//  '<S202>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/postSat Signal/Forward_Path'
//  '<S203>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_att_controller/PID Controller5/preSat Signal/Forward_Path'
//  '<S204>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/Altitude Signal conditioning'
//  '<S205>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/Calculate Transformation Matrix'
//  '<S206>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/Degrees to Radians'
//  '<S207>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller'
//  '<S208>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1'
//  '<S209>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude'
//  '<S210>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz'
//  '<S211>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/Altitude Signal conditioning/Saturation Dynamic'
//  '<S212>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Anti-windup'
//  '<S213>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/D Gain'
//  '<S214>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/External Derivative'
//  '<S215>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Filter'
//  '<S216>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Filter ICs'
//  '<S217>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/I Gain'
//  '<S218>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Ideal P Gain'
//  '<S219>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Ideal P Gain Fdbk'
//  '<S220>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Integrator'
//  '<S221>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Integrator ICs'
//  '<S222>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/N Copy'
//  '<S223>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/N Gain'
//  '<S224>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/P Copy'
//  '<S225>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Parallel P Gain'
//  '<S226>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Reset Signal'
//  '<S227>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Saturation'
//  '<S228>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Saturation Fdbk'
//  '<S229>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Sum'
//  '<S230>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Sum Fdbk'
//  '<S231>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Tracking Mode'
//  '<S232>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Tracking Mode Sum'
//  '<S233>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Tsamp - Integral'
//  '<S234>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Tsamp - Ngain'
//  '<S235>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/postSat Signal'
//  '<S236>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/preSat Signal'
//  '<S237>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Anti-windup/Disabled'
//  '<S238>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/D Gain/Disabled'
//  '<S239>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/External Derivative/Disabled'
//  '<S240>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Filter/Disabled'
//  '<S241>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Filter ICs/Disabled'
//  '<S242>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/I Gain/Disabled'
//  '<S243>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S244>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S245>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Integrator/Disabled'
//  '<S246>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Integrator ICs/Disabled'
//  '<S247>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S248>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/N Gain/Disabled'
//  '<S249>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/P Copy/Disabled'
//  '<S250>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Parallel P Gain/External Parameters'
//  '<S251>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Reset Signal/Disabled'
//  '<S252>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Saturation/External'
//  '<S253>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Saturation/External/Saturation Dynamic'
//  '<S254>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S255>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Sum/Passthrough_P'
//  '<S256>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Sum Fdbk/Disabled'
//  '<S257>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Tracking Mode/Disabled'
//  '<S258>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S259>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S260>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S261>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/postSat Signal/Forward_Path'
//  '<S262>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller/preSat Signal/Forward_Path'
//  '<S263>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Anti-windup'
//  '<S264>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/D Gain'
//  '<S265>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/External Derivative'
//  '<S266>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Filter'
//  '<S267>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Filter ICs'
//  '<S268>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/I Gain'
//  '<S269>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Ideal P Gain'
//  '<S270>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S271>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Integrator'
//  '<S272>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Integrator ICs'
//  '<S273>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/N Copy'
//  '<S274>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/N Gain'
//  '<S275>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/P Copy'
//  '<S276>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Parallel P Gain'
//  '<S277>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Reset Signal'
//  '<S278>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Saturation'
//  '<S279>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Saturation Fdbk'
//  '<S280>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Sum'
//  '<S281>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Sum Fdbk'
//  '<S282>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Tracking Mode'
//  '<S283>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Tracking Mode Sum'
//  '<S284>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Tsamp - Integral'
//  '<S285>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Tsamp - Ngain'
//  '<S286>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/postSat Signal'
//  '<S287>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/preSat Signal'
//  '<S288>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Anti-windup/Disabled'
//  '<S289>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/D Gain/Disabled'
//  '<S290>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/External Derivative/Disabled'
//  '<S291>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Filter/Disabled'
//  '<S292>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Filter ICs/Disabled'
//  '<S293>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/I Gain/Disabled'
//  '<S294>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S295>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S296>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Integrator/Disabled'
//  '<S297>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Integrator ICs/Disabled'
//  '<S298>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S299>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/N Gain/Disabled'
//  '<S300>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/P Copy/Disabled'
//  '<S301>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Parallel P Gain/External Parameters'
//  '<S302>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Reset Signal/Disabled'
//  '<S303>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Saturation/External'
//  '<S304>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Saturation/External/Saturation Dynamic'
//  '<S305>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S306>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Sum/Passthrough_P'
//  '<S307>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S308>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Tracking Mode/Disabled'
//  '<S309>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S310>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S311>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S312>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S313>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S314>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Anti-windup'
//  '<S315>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/D Gain'
//  '<S316>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/External Derivative'
//  '<S317>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Filter'
//  '<S318>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Filter ICs'
//  '<S319>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/I Gain'
//  '<S320>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Ideal P Gain'
//  '<S321>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S322>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Integrator'
//  '<S323>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Integrator ICs'
//  '<S324>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/N Copy'
//  '<S325>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/N Gain'
//  '<S326>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/P Copy'
//  '<S327>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Parallel P Gain'
//  '<S328>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Reset Signal'
//  '<S329>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Saturation'
//  '<S330>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Saturation Fdbk'
//  '<S331>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Sum'
//  '<S332>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Sum Fdbk'
//  '<S333>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Tracking Mode'
//  '<S334>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Tracking Mode Sum'
//  '<S335>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Tsamp - Integral'
//  '<S336>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Tsamp - Ngain'
//  '<S337>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/postSat Signal'
//  '<S338>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/preSat Signal'
//  '<S339>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Anti-windup/Disabled'
//  '<S340>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/D Gain/Disabled'
//  '<S341>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/External Derivative/Disabled'
//  '<S342>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Filter/Disabled'
//  '<S343>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Filter ICs/Disabled'
//  '<S344>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/I Gain/Disabled'
//  '<S345>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S346>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Ideal P Gain Fdbk/Disabled'
//  '<S347>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Integrator/Disabled'
//  '<S348>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Integrator ICs/Disabled'
//  '<S349>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/N Copy/Disabled wSignal Specification'
//  '<S350>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/N Gain/Disabled'
//  '<S351>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/P Copy/Disabled'
//  '<S352>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Parallel P Gain/External Parameters'
//  '<S353>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Reset Signal/Disabled'
//  '<S354>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Saturation/External'
//  '<S355>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Saturation/External/Saturation Dynamic'
//  '<S356>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Saturation Fdbk/Disabled'
//  '<S357>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Sum/Passthrough_P'
//  '<S358>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Sum Fdbk/Disabled'
//  '<S359>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S360>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S361>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S362>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S363>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/postSat Signal/Forward_Path'
//  '<S364>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_Altitude/preSat Signal/Forward_Path'
//  '<S365>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Anti-windup'
//  '<S366>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/D Gain'
//  '<S367>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/External Derivative'
//  '<S368>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Filter'
//  '<S369>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Filter ICs'
//  '<S370>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/I Gain'
//  '<S371>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Ideal P Gain'
//  '<S372>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Ideal P Gain Fdbk'
//  '<S373>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Integrator'
//  '<S374>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Integrator ICs'
//  '<S375>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/N Copy'
//  '<S376>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/N Gain'
//  '<S377>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/P Copy'
//  '<S378>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Parallel P Gain'
//  '<S379>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Reset Signal'
//  '<S380>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Saturation'
//  '<S381>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Saturation Fdbk'
//  '<S382>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Sum'
//  '<S383>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Sum Fdbk'
//  '<S384>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Tracking Mode'
//  '<S385>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Tracking Mode Sum'
//  '<S386>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Tsamp - Integral'
//  '<S387>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Tsamp - Ngain'
//  '<S388>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/postSat Signal'
//  '<S389>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/preSat Signal'
//  '<S390>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Anti-windup/Disc. Clamping Parallel'
//  '<S391>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S392>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S393>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/D Gain/External Parameters'
//  '<S394>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/External Derivative/Error'
//  '<S395>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Filter/Disc. Forward Euler Filter'
//  '<S396>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Filter ICs/Internal IC - Filter'
//  '<S397>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/I Gain/External Parameters'
//  '<S398>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Ideal P Gain/Passthrough'
//  '<S399>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Ideal P Gain Fdbk/Passthrough'
//  '<S400>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Integrator/Discrete'
//  '<S401>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Integrator ICs/Internal IC'
//  '<S402>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/N Copy/Disabled'
//  '<S403>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/N Gain/External Parameters'
//  '<S404>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/P Copy/Disabled'
//  '<S405>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Parallel P Gain/External Parameters'
//  '<S406>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Reset Signal/Disabled'
//  '<S407>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Saturation/Enabled'
//  '<S408>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Saturation Fdbk/Passthrough'
//  '<S409>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Sum/Sum_PID'
//  '<S410>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Sum Fdbk/Enabled'
//  '<S411>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Tracking Mode/Disabled'
//  '<S412>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Tracking Mode Sum/Passthrough'
//  '<S413>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Tsamp - Integral/TsSignalSpecification'
//  '<S414>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/Tsamp - Ngain/Passthrough'
//  '<S415>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/postSat Signal/Feedback_Path'
//  '<S416>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_pos_controller/PID_vz/preSat Signal/Feedback_Path'
//  '<S417>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller'
//  '<S418>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1'
//  '<S419>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2'
//  '<S420>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Anti-windup'
//  '<S421>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/D Gain'
//  '<S422>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/External Derivative'
//  '<S423>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Filter'
//  '<S424>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Filter ICs'
//  '<S425>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/I Gain'
//  '<S426>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Ideal P Gain'
//  '<S427>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Ideal P Gain Fdbk'
//  '<S428>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Integrator'
//  '<S429>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Integrator ICs'
//  '<S430>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/N Copy'
//  '<S431>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/N Gain'
//  '<S432>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/P Copy'
//  '<S433>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Parallel P Gain'
//  '<S434>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Reset Signal'
//  '<S435>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Saturation'
//  '<S436>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Saturation Fdbk'
//  '<S437>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Sum'
//  '<S438>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Sum Fdbk'
//  '<S439>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Tracking Mode'
//  '<S440>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Tracking Mode Sum'
//  '<S441>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Tsamp - Integral'
//  '<S442>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Tsamp - Ngain'
//  '<S443>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/postSat Signal'
//  '<S444>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/preSat Signal'
//  '<S445>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S446>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S447>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S448>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/D Gain/External Parameters'
//  '<S449>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/External Derivative/Error'
//  '<S450>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S451>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S452>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/I Gain/External Parameters'
//  '<S453>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S454>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S455>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Integrator/Discrete'
//  '<S456>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Integrator ICs/Internal IC'
//  '<S457>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/N Copy/Disabled'
//  '<S458>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/N Gain/External Parameters'
//  '<S459>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/P Copy/Disabled'
//  '<S460>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Parallel P Gain/External Parameters'
//  '<S461>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Reset Signal/Disabled'
//  '<S462>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Saturation/Enabled'
//  '<S463>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S464>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Sum/Sum_PID'
//  '<S465>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Sum Fdbk/Disabled'
//  '<S466>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Tracking Mode/Disabled'
//  '<S467>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S468>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S469>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S470>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/postSat Signal/Forward_Path'
//  '<S471>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller/preSat Signal/Forward_Path'
//  '<S472>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Anti-windup'
//  '<S473>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/D Gain'
//  '<S474>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/External Derivative'
//  '<S475>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Filter'
//  '<S476>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Filter ICs'
//  '<S477>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/I Gain'
//  '<S478>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Ideal P Gain'
//  '<S479>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S480>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Integrator'
//  '<S481>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Integrator ICs'
//  '<S482>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/N Copy'
//  '<S483>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/N Gain'
//  '<S484>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/P Copy'
//  '<S485>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Parallel P Gain'
//  '<S486>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Reset Signal'
//  '<S487>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Saturation'
//  '<S488>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Saturation Fdbk'
//  '<S489>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Sum'
//  '<S490>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Sum Fdbk'
//  '<S491>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Tracking Mode'
//  '<S492>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Tracking Mode Sum'
//  '<S493>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Tsamp - Integral'
//  '<S494>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Tsamp - Ngain'
//  '<S495>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/postSat Signal'
//  '<S496>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/preSat Signal'
//  '<S497>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S498>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S499>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S500>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/D Gain/External Parameters'
//  '<S501>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/External Derivative/Error'
//  '<S502>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S503>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S504>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/I Gain/External Parameters'
//  '<S505>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S506>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S507>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Integrator/Discrete'
//  '<S508>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Integrator ICs/Internal IC'
//  '<S509>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/N Copy/Disabled'
//  '<S510>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/N Gain/External Parameters'
//  '<S511>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/P Copy/Disabled'
//  '<S512>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Parallel P Gain/External Parameters'
//  '<S513>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Reset Signal/Disabled'
//  '<S514>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Saturation/Enabled'
//  '<S515>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S516>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Sum/Sum_PID'
//  '<S517>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S518>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Tracking Mode/Disabled'
//  '<S519>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S520>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S521>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S522>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S523>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S524>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Anti-windup'
//  '<S525>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/D Gain'
//  '<S526>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/External Derivative'
//  '<S527>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Filter'
//  '<S528>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Filter ICs'
//  '<S529>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/I Gain'
//  '<S530>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Ideal P Gain'
//  '<S531>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Ideal P Gain Fdbk'
//  '<S532>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Integrator'
//  '<S533>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Integrator ICs'
//  '<S534>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/N Copy'
//  '<S535>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/N Gain'
//  '<S536>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/P Copy'
//  '<S537>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Parallel P Gain'
//  '<S538>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Reset Signal'
//  '<S539>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Saturation'
//  '<S540>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Saturation Fdbk'
//  '<S541>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Sum'
//  '<S542>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Sum Fdbk'
//  '<S543>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Tracking Mode'
//  '<S544>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Tracking Mode Sum'
//  '<S545>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Tsamp - Integral'
//  '<S546>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Tsamp - Ngain'
//  '<S547>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/postSat Signal'
//  '<S548>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/preSat Signal'
//  '<S549>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S550>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S551>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S552>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/D Gain/External Parameters'
//  '<S553>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/External Derivative/Error'
//  '<S554>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S555>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S556>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/I Gain/External Parameters'
//  '<S557>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Ideal P Gain/Passthrough'
//  '<S558>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S559>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Integrator/Discrete'
//  '<S560>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Integrator ICs/Internal IC'
//  '<S561>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/N Copy/Disabled'
//  '<S562>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/N Gain/External Parameters'
//  '<S563>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/P Copy/Disabled'
//  '<S564>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Parallel P Gain/External Parameters'
//  '<S565>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Reset Signal/Disabled'
//  '<S566>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Saturation/Enabled'
//  '<S567>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Saturation Fdbk/Disabled'
//  '<S568>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Sum/Sum_PID'
//  '<S569>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Sum Fdbk/Disabled'
//  '<S570>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Tracking Mode/Disabled'
//  '<S571>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S572>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S573>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S574>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/postSat Signal/Forward_Path'
//  '<S575>' : 'HITL_HEXA_MISSION/CLAW/Controller/mc_rate_controller/PID Controller2/preSat Signal/Forward_Path'
//  '<S576>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm'
//  '<S577>' : 'HITL_HEXA_MISSION/Navigation/uORB Publish'
//  '<S578>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission'
//  '<S579>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem'
//  '<S580>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC'
//  '<S581>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE'
//  '<S582>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land'
//  '<S583>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off'
//  '<S584>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint'
//  '<S585>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE'
//  '<S586>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE/Enabled Subsystem2'
//  '<S587>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land'
//  '<S588>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land'
//  '<S589>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land/Enabled Subsystem'
//  '<S590>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land/Enabled Subsystem2'
//  '<S591>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Ensure smooth ascend during Takeoff'
//  '<S592>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff'
//  '<S593>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff/Enabled Subsystem2'
//  '<S594>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning'
//  '<S595>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning/Compare To Constant'
//  '<S596>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC'
//  '<S597>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC'
//  '<S598>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead'
//  '<S599>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead'
//  '<S600>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/Compare To Constant'
//  '<S601>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read'
//  '<S602>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read/Enabled Subsystem'
//  '<S603>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint'
//  '<S604>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_WayPoint'
//  '<S605>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Empty_WayPoint'
//  '<S606>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Next_WayPoint'
//  '<S607>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Message'
//  '<S608>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Write'
//  '<S609>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP'
//  '<S610>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem'
//  '<S611>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem1'
//  '<S612>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem2'
//  '<S613>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead/Enabled Subsystem'
//  '<S614>' : 'HITL_HEXA_MISSION/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead/Enabled Subsystem'
//  '<S615>' : 'HITL_HEXA_MISSION/Navigation/uORB Publish/PX4 uORB Message'
//  '<S616>' : 'HITL_HEXA_MISSION/Navigation/uORB Publish/PX4 uORB Write'
//  '<S617>' : 'HITL_HEXA_MISSION/uORBInput/PX4 uORB Read1'
//  '<S618>' : 'HITL_HEXA_MISSION/uORBInput/PX4 uORB Read2'
//  '<S619>' : 'HITL_HEXA_MISSION/uORBInput/vehicle_attitude'
//  '<S620>' : 'HITL_HEXA_MISSION/uORBInput/vehicle_local_pos'
//  '<S621>' : 'HITL_HEXA_MISSION/uORBInput/PX4 uORB Read1/Enabled Subsystem'
//  '<S622>' : 'HITL_HEXA_MISSION/uORBInput/PX4 uORB Read2/Enabled Subsystem'
//  '<S623>' : 'HITL_HEXA_MISSION/uORBInput/vehicle_attitude/Enabled Subsystem'
//  '<S624>' : 'HITL_HEXA_MISSION/uORBInput/vehicle_local_pos/Enabled Subsystem'

#endif                                 // HITL_HEXA_MISSION_h_

//
// File trailer for generated code.
//
// [EOF]
//
