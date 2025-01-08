//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: HITL_HEXA_Hovering.h
//
// Code generated for Simulink model 'HITL_HEXA_Hovering'.
//
// Model version                  : 5.30
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Jan  8 14:27:22 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef HITL_HEXA_Hovering_h_
#define HITL_HEXA_Hovering_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "HITL_HEXA_Hovering_types.h"
#include <uORB/topics/input_rc.h>
#include <uORB/topics/vehicle_trajectory_waypoint.h>
#include <uORB/topics/position_setpoint_triplet.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/trajectory_waypoint.h>
#include <uORB/topics/home_position.h>
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

// Block signals for system '<S19>/SourceBlock'
struct B_SourceBlock_HITL_HEXA_Hovering_T {
  px4_Bus_input_rc SourceBlock_o2;     // '<S19>/SourceBlock'
  boolean_T SourceBlock_o1;            // '<S19>/SourceBlock'
};

// Block states (default storage) for system '<S19>/SourceBlock'
struct DW_SourceBlock_HITL_HEXA_Hovering_T {
  px4_internal_block_Subscriber_HITL_HEXA_Hovering_T obj;// '<S19>/SourceBlock'
  boolean_T objisempty;                // '<S19>/SourceBlock'
};

// Block signals for system '<S60>/MATLAB System'
struct B_MATLABSystem_HITL_HEXA_Hovering_T {
  real32_T MATLABSystem[3];            // '<S60>/MATLAB System'
  real_T dLat;
};

// Block states (default storage) for system '<S60>/MATLAB System'
struct DW_MATLABSystem_HITL_HEXA_Hovering_T {
  px4_internal_block_LLA2LocalCoordinatesNED_HITL_HEXA_Hovering_T obj;// '<S60>/MATLAB System' 
  boolean_T objisempty;                // '<S60>/MATLAB System'
};

// Block signals (default storage)
struct B_HITL_HEXA_Hovering_T {
  px4_Bus_vehicle_trajectory_waypoint BusAssignment1;// '<S54>/Bus Assignment1'
  px4_Bus_vehicle_trajectory_waypoint In1;// '<S59>/In1'
  px4_Bus_vehicle_trajectory_waypoint r;
  px4_Bus_position_setpoint_triplet In1_p;// '<S71>/In1'
  px4_Bus_position_setpoint_triplet r1;
  px4_Bus_vehicle_local_position In1_c;// '<S33>/In1'
  px4_Bus_vehicle_local_position r2;
  px4_Bus_actuator_outputs BusAssignment;// '<S10>/Bus Assignment'
  px4_Bus_input_rc In1_j;              // '<S31>/In1'
  px4_Bus_input_rc In1_b;              // '<S20>/In1'
  real_T b_waypointsIn_data[9];
  real_T MatrixConcatenate_p[9];       // '<S41>/Matrix Concatenate'
  px4_Bus_vehicle_attitude In1_m;      // '<S32>/In1'
  px4_Bus_vehicle_attitude r3;
  px4_Bus_trajectory_waypoint BusAssignment1_f;// '<S62>/Bus Assignment1'
  px4_Bus_home_position In1_f;         // '<S70>/In1'
  px4_Bus_home_position r4;
  px4_Bus_vehicle_angular_velocity In1_l;// '<S28>/In1'
  px4_Bus_vehicle_angular_velocity r5;
  real_T lla0[3];
  real_T virtualWaypoint[3];
  real_T b_startWaypoint[3];
  real_T VectorConcatenate[3];         // '<S603>/Vector Concatenate'
  real_T DataTypeConversion2[3];       // '<S2>/Data Type Conversion2'
  real_T dv[3];
  px4_Bus_actuator_armed In1_bs;       // '<S29>/In1'
  px4_Bus_actuator_armed r6;
  real_T Saturation[2];                // '<S388>/Saturation'
  real_T Gain1;                        // '<S75>/Gain1'
  real_T Saturation_e;                 // '<S488>/Saturation'
  real_T Saturation_f;                 // '<S592>/Saturation'
  real_T Saturation_l;                 // '<S125>/Saturation'
  real_T Saturation_o;                 // '<S177>/Saturation'
  real_T Saturation_m;                 // '<S229>/Saturation'
  real_T yaw_In;                       // '<S43>/yaw_In'
  real_T yaw_In_i;                     // '<S47>/yaw_In'
  real_T In;                           // '<S46>/In'
  real_T yaw_In_ik;                    // '<S50>/yaw_In'
  real_T Switch4;                      // '<S6>/Switch4'
  real_T Switch3;                      // '<S6>/Switch3'
  real_T Switch2;                      // '<S6>/Switch2'
  real_T Switch_m;                     // '<S6>/Switch'
  real_T Subtract_f;                   // '<S44>/Subtract'
  real_T rtb_Merge_idx_3;
  real_T rtb_Transpose_idx_0;
  real_T rtb_Transpose_idx_1;
  real_T rtb_Transpose_idx_2;
  real_T rtb_Transpose_idx_3;
  real_T rtb_Merge_idx_0;
  real_T virtualWaypoint_tmp;
  real_T dLat;
  real_T dLon;
  real_T Rn;
  real_T flat;
  real_T b_x;
  real_T absx;
  real_T absx_m;
  real_T q;
  real_T scale;
  real_T absxk;
  real_T t;
  boolean_T x[6];
  real32_T ParamStep;
  int32_T ParamStep_c;
  int32_T ParamStep_k;
  int32_T i2;
  int32_T i1;
  int32_T j;
  int32_T ix;
  int32_T b_exponent;
  int32_T b_k;
  int32_T i;
  int32_T i1_c;
  int8_T tmp_data[3];
  boolean_T distinctWptsIdx[3];
  boolean_T b[3];
  boolean_T IsNaN_l[2];                // '<S39>/IsNaN'
  int8_T rtPrevAction;
  int8_T i2_b;
  boolean_T b_varargout_1;
  boolean_T Compare_h;                 // '<S11>/Compare'
  boolean_T Compare;                   // '<S12>/Compare'
  boolean_T latp2;
  B_MATLABSystem_HITL_HEXA_Hovering_T MATLABSystem_b;// '<S60>/MATLAB System'
  B_MATLABSystem_HITL_HEXA_Hovering_T MATLABSystem;// '<S60>/MATLAB System'
  B_SourceBlock_HITL_HEXA_Hovering_T SourceBlock_b;// '<S19>/SourceBlock'
  B_SourceBlock_HITL_HEXA_Hovering_T SourceBlock;// '<S19>/SourceBlock'
};

// Block states (default storage) for system '<Root>'
struct DW_HITL_HEXA_Hovering_T {
  uav_sluav_internal_system_WaypointFollower_HITL_HEXA_Hovering_T obj;// '<S41>/UAV Waypoint Follower' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_Hovering_T obj_b;// '<S68>/Read Parameter' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_Hovering_T obj_g;// '<S69>/Read Parameter' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_Hovering_T obj_k;// '<S37>/Read Parameter' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_Hovering_T obj_m;// '<S7>/Read Parameter5' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_Hovering_T obj_gw;// '<S7>/Read Parameter4' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_Hovering_T obj_be;// '<S7>/Read Parameter3' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_Hovering_T obj_m0;// '<S7>/Read Parameter2' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_Hovering_T obj_d;// '<S7>/Read Parameter13' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_Hovering_T obj_p;// '<S7>/Read Parameter1' 
  px4_internal_block_Subscriber_HITL_HEXA_Hovering_T obj_kz;// '<S56>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_Hovering_T obj_gf;// '<S55>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_Hovering_T obj_e;// '<S58>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_Hovering_T obj_mg;// '<S27>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_Hovering_T obj_gv;// '<S26>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_Hovering_T obj_d0;// '<S24>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_Hovering_T obj_po;// '<S23>/SourceBlock' 
  px4_internal_block_getPX4AbsoluteTime_HITL_HEXA_Hovering_T obj_n;// '<S53>/PX4 Timestamp' 
  px4_internal_block_Publisher_HITL_HEXA_Hovering_T obj_mc;// '<S65>/SinkBlock'
  px4_internal_block_Publisher_HITL_HEXA_Hovering_T obj_nt;// '<S22>/SinkBlock'
  px4_internal_block_LLA2LocalCoordinates_HITL_HEXA_Hovering_T obj_mr;// '<S37>/LLA2LocalCoordinates' 
  real_T Filter_DSTATE;                // '<S528>/Filter'
  real_T Integrator_DSTATE;            // '<S533>/Integrator'
  real_T Filter_DSTATE_n;              // '<S580>/Filter'
  real_T Integrator_DSTATE_c;          // '<S585>/Integrator'
  real_T Integrator_DSTATE_k;          // '<S118>/Integrator'
  real_T Filter_DSTATE_e;              // '<S113>/Filter'
  real_T Integrator_DSTATE_kd;         // '<S170>/Integrator'
  real_T Filter_DSTATE_ek;             // '<S165>/Filter'
  real_T Integrator_DSTATE_i;          // '<S222>/Integrator'
  real_T Filter_DSTATE_j;              // '<S217>/Filter'
  real_T Delay_DSTATE;                 // '<S42>/Delay'
  real_T Delay_DSTATE_l[2];            // '<S39>/Delay'
  real_T Delay_DSTATE_n;               // '<S44>/Delay'
  real_T Delay_DSTATE_b;               // '<S45>/Delay'
  real_T Delay_DSTATE_c;               // '<S48>/Delay'
  real_T Delay_DSTATE_d;               // '<S49>/Delay'
  real_T PrevY;                        // '<S72>/Rate Limiter2'
  real_T PrevY_f;                      // '<S72>/Rate Limiter1'
  px4_internal_block_LLA2LocalCoordinatesNED_HITL_HEXA_Hovering_T obj_mu;// '<S63>/MATLAB System' 
  int8_T If_ActiveSubsystem;           // '<S36>/If'
  uint8_T is_active_c3_HITL_HEXA_Hovering;// '<S4>/Chart'
  uint8_T is_c3_HITL_HEXA_Hovering;    // '<S4>/Chart'
  DW_MATLABSystem_HITL_HEXA_Hovering_T MATLABSystem_b;// '<S60>/MATLAB System'
  DW_MATLABSystem_HITL_HEXA_Hovering_T MATLABSystem;// '<S60>/MATLAB System'
  DW_SourceBlock_HITL_HEXA_Hovering_T SourceBlock_b;// '<S19>/SourceBlock'
  DW_SourceBlock_HITL_HEXA_Hovering_T SourceBlock;// '<S19>/SourceBlock'
};

// Parameters (default storage)
struct P_HITL_HEXA_Hovering_T_ {
  real_T PIDController_D;              // Mask Parameter: PIDController_D
                                          //  Referenced by: '<S111>/Derivative Gain'

  real_T PIDController1_D;             // Mask Parameter: PIDController1_D
                                          //  Referenced by: '<S163>/Derivative Gain'

  real_T PIDController2_D;             // Mask Parameter: PIDController2_D
                                          //  Referenced by: '<S215>/Derivative Gain'

  real_T PID_Altitude_D;               // Mask Parameter: PID_Altitude_D
                                          //  Referenced by: '<S526>/Derivative Gain'

  real_T PID_vz_D;                     // Mask Parameter: PID_vz_D
                                          //  Referenced by: '<S578>/Derivative Gain'

  real_T PIDController_I;              // Mask Parameter: PIDController_I
                                          //  Referenced by: '<S115>/Integral Gain'

  real_T PIDController1_I;             // Mask Parameter: PIDController1_I
                                          //  Referenced by: '<S167>/Integral Gain'

  real_T PIDController2_I;             // Mask Parameter: PIDController2_I
                                          //  Referenced by: '<S219>/Integral Gain'

  real_T PID_Altitude_I;               // Mask Parameter: PID_Altitude_I
                                          //  Referenced by: '<S530>/Integral Gain'

  real_T PID_vz_I;                     // Mask Parameter: PID_vz_I
                                          //  Referenced by: '<S582>/Integral Gain'

  real_T PIDController_InitialConditionForFilter;
                      // Mask Parameter: PIDController_InitialConditionForFilter
                         //  Referenced by: '<S113>/Filter'

  real_T PIDController1_InitialConditionForFilter;
                     // Mask Parameter: PIDController1_InitialConditionForFilter
                        //  Referenced by: '<S165>/Filter'

  real_T PIDController2_InitialConditionForFilter;
                     // Mask Parameter: PIDController2_InitialConditionForFilter
                        //  Referenced by: '<S217>/Filter'

  real_T PID_Altitude_InitialConditionForFilter;
                       // Mask Parameter: PID_Altitude_InitialConditionForFilter
                          //  Referenced by: '<S528>/Filter'

  real_T PID_vz_InitialConditionForFilter;
                             // Mask Parameter: PID_vz_InitialConditionForFilter
                                //  Referenced by: '<S580>/Filter'

  real_T PIDController_InitialConditionForIntegrator;
                  // Mask Parameter: PIDController_InitialConditionForIntegrator
                     //  Referenced by: '<S118>/Integrator'

  real_T PIDController1_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController1_InitialConditionForIntegrator
                    //  Referenced by: '<S170>/Integrator'

  real_T PIDController2_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController2_InitialConditionForIntegrator
                    //  Referenced by: '<S222>/Integrator'

  real_T PID_Altitude_InitialConditionForIntegrator;
                   // Mask Parameter: PID_Altitude_InitialConditionForIntegrator
                      //  Referenced by: '<S533>/Integrator'

  real_T PID_vz_InitialConditionForIntegrator;
                         // Mask Parameter: PID_vz_InitialConditionForIntegrator
                            //  Referenced by: '<S585>/Integrator'

  real_T PIDController_LowerSaturationLimit;
                           // Mask Parameter: PIDController_LowerSaturationLimit
                              //  Referenced by:
                              //    '<S125>/Saturation'
                              //    '<S110>/DeadZone'

  real_T PIDController1_LowerSaturationLimit;
                          // Mask Parameter: PIDController1_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S177>/Saturation'
                             //    '<S162>/DeadZone'

  real_T PIDController2_LowerSaturationLimit;
                          // Mask Parameter: PIDController2_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S229>/Saturation'
                             //    '<S214>/DeadZone'

  real_T PIDController1_LowerSaturationLimit_h;
                        // Mask Parameter: PIDController1_LowerSaturationLimit_h
                           //  Referenced by: '<S438>/Saturation'

  real_T PIDController_LowerSaturationLimit_o;
                         // Mask Parameter: PIDController_LowerSaturationLimit_o
                            //  Referenced by: '<S388>/Saturation'

  real_T PIDController5_LowerSaturationLimit;
                          // Mask Parameter: PIDController5_LowerSaturationLimit
                             //  Referenced by: '<S488>/Saturation'

  real_T PID_Altitude_LowerSaturationLimit;
                            // Mask Parameter: PID_Altitude_LowerSaturationLimit
                               //  Referenced by:
                               //    '<S540>/Saturation'
                               //    '<S525>/DeadZone'

  real_T PID_vz_LowerSaturationLimit;
                                  // Mask Parameter: PID_vz_LowerSaturationLimit
                                     //  Referenced by:
                                     //    '<S592>/Saturation'
                                     //    '<S577>/DeadZone'

  real_T PIDController_N;              // Mask Parameter: PIDController_N
                                          //  Referenced by: '<S121>/Filter Coefficient'

  real_T PIDController1_N;             // Mask Parameter: PIDController1_N
                                          //  Referenced by: '<S173>/Filter Coefficient'

  real_T PIDController2_N;             // Mask Parameter: PIDController2_N
                                          //  Referenced by: '<S225>/Filter Coefficient'

  real_T PID_Altitude_N;               // Mask Parameter: PID_Altitude_N
                                          //  Referenced by: '<S536>/Filter Coefficient'

  real_T PID_vz_N;                     // Mask Parameter: PID_vz_N
                                          //  Referenced by: '<S588>/Filter Coefficient'

  real_T PIDController_P;              // Mask Parameter: PIDController_P
                                          //  Referenced by: '<S123>/Proportional Gain'

  real_T PIDController3_P;             // Mask Parameter: PIDController3_P
                                          //  Referenced by: '<S277>/Proportional Gain'

  real_T PIDController1_P;             // Mask Parameter: PIDController1_P
                                          //  Referenced by: '<S175>/Proportional Gain'

  real_T PIDController4_P;             // Mask Parameter: PIDController4_P
                                          //  Referenced by: '<S327>/Proportional Gain'

  real_T PIDController2_P;             // Mask Parameter: PIDController2_P
                                          //  Referenced by: '<S227>/Proportional Gain'

  real_T PIDController1_P_f;           // Mask Parameter: PIDController1_P_f
                                          //  Referenced by: '<S436>/Proportional Gain'

  real_T PIDController_P_b;            // Mask Parameter: PIDController_P_b
                                          //  Referenced by: '<S386>/Proportional Gain'

  real_T PIDController5_P;             // Mask Parameter: PIDController5_P
                                          //  Referenced by: '<S486>/Proportional Gain'

  real_T PID_Altitude_P;               // Mask Parameter: PID_Altitude_P
                                          //  Referenced by: '<S538>/Proportional Gain'

  real_T PID_vz_P;                     // Mask Parameter: PID_vz_P
                                          //  Referenced by: '<S590>/Proportional Gain'

  real_T PIDController_UpperSaturationLimit;
                           // Mask Parameter: PIDController_UpperSaturationLimit
                              //  Referenced by:
                              //    '<S125>/Saturation'
                              //    '<S110>/DeadZone'

  real_T PIDController1_UpperSaturationLimit;
                          // Mask Parameter: PIDController1_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S177>/Saturation'
                             //    '<S162>/DeadZone'

  real_T PIDController2_UpperSaturationLimit;
                          // Mask Parameter: PIDController2_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S229>/Saturation'
                             //    '<S214>/DeadZone'

  real_T PIDController1_UpperSaturationLimit_e;
                        // Mask Parameter: PIDController1_UpperSaturationLimit_e
                           //  Referenced by: '<S438>/Saturation'

  real_T PIDController_UpperSaturationLimit_e;
                         // Mask Parameter: PIDController_UpperSaturationLimit_e
                            //  Referenced by: '<S388>/Saturation'

  real_T PIDController5_UpperSaturationLimit;
                          // Mask Parameter: PIDController5_UpperSaturationLimit
                             //  Referenced by: '<S488>/Saturation'

  real_T PID_Altitude_UpperSaturationLimit;
                            // Mask Parameter: PID_Altitude_UpperSaturationLimit
                               //  Referenced by:
                               //    '<S540>/Saturation'
                               //    '<S525>/DeadZone'

  real_T PID_vz_UpperSaturationLimit;
                                  // Mask Parameter: PID_vz_UpperSaturationLimit
                                     //  Referenced by:
                                     //    '<S592>/Saturation'
                                     //    '<S577>/DeadZone'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S11>/Constant'

  uint16_T CompareToConstant_const_c;
                                    // Mask Parameter: CompareToConstant_const_c
                                       //  Referenced by: '<S12>/Constant'

  uint8_T CompareToConstant_const_d;// Mask Parameter: CompareToConstant_const_d
                                       //  Referenced by: '<S52>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Out1_Y0;// Computed Parameter: Out1_Y0
                                                 //  Referenced by: '<S59>/Out1'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value;// Computed Parameter: Constant_Value
                                                        //  Referenced by: '<S64>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                          //  Referenced by: '<S58>/Constant'

  px4_Bus_position_setpoint_triplet Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                 //  Referenced by: '<S71>/Out1'

  px4_Bus_position_setpoint_triplet Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                        //  Referenced by: '<S56>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                              //  Referenced by: '<S33>/Out1'

  px4_Bus_vehicle_local_position Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                     //  Referenced by: '<S27>/Constant'

  px4_Bus_actuator_outputs Constant_Value_c;// Computed Parameter: Constant_Value_c
                                               //  Referenced by: '<S21>/Constant'

  px4_Bus_input_rc Out1_Y0_l;          // Computed Parameter: Out1_Y0_l
                                          //  Referenced by: '<S20>/Out1'

  px4_Bus_input_rc Out1_Y0_m;          // Computed Parameter: Out1_Y0_m
                                          //  Referenced by: '<S31>/Out1'

  px4_Bus_input_rc Constant_Value_ge;  // Computed Parameter: Constant_Value_ge
                                          //  Referenced by: '<S19>/Constant'

  px4_Bus_input_rc Constant_Value_o;   // Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S30>/Constant'

  px4_Bus_vehicle_attitude Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S32>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_l;// Computed Parameter: Constant_Value_l
                                               //  Referenced by: '<S26>/Constant'

  px4_Bus_home_position Out1_Y0_o;     // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S70>/Out1'

  px4_Bus_home_position Constant_Value_b;// Computed Parameter: Constant_Value_b
                                            //  Referenced by: '<S55>/Constant'

  px4_Bus_vehicle_angular_velocity Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                //  Referenced by: '<S28>/Out1'

  px4_Bus_vehicle_angular_velocity Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                       //  Referenced by: '<S23>/Constant'

  px4_Bus_actuator_armed Out1_Y0_d;    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S29>/Out1'

  px4_Bus_actuator_armed Constant_Value_j;// Computed Parameter: Constant_Value_j
                                             //  Referenced by: '<S24>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S6>/Constant1'

  real_T Constant1_Value_c;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant1'

  real_T Gain_Gain;                    // Expression: 0.01
                                          //  Referenced by: '<S14>/Gain'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<S14>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S14>/Saturation'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S6>/Constant2'

  real_T Constant2_Value_e;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant2'

  real_T Gain_Gain_i;                  // Expression: 0.01
                                          //  Referenced by: '<S15>/Gain'

  real_T Saturation_UpperSat_l;        // Expression: 1
                                          //  Referenced by: '<S15>/Saturation'

  real_T Saturation_LowerSat_i;        // Expression: 0
                                          //  Referenced by: '<S15>/Saturation'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<S6>/Constant3'

  real_T Constant3_Value_f;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant3'

  real_T Gain_Gain_j;                  // Expression: 0.01
                                          //  Referenced by: '<S16>/Gain'

  real_T Saturation_UpperSat_d;        // Expression: 1
                                          //  Referenced by: '<S16>/Saturation'

  real_T Saturation_LowerSat_o;        // Expression: 0
                                          //  Referenced by: '<S16>/Saturation'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<S6>/Constant4'

  real_T Constant4_Value_m;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant4'

  real_T Gain_Gain_jb;                 // Expression: 0.01
                                          //  Referenced by: '<S17>/Gain'

  real_T Saturation_UpperSat_c;        // Expression: 1
                                          //  Referenced by: '<S17>/Saturation'

  real_T Saturation_LowerSat_f;        // Expression: 0
                                          //  Referenced by: '<S17>/Saturation'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<S6>/Constant5'

  real_T Constant5_Value_j;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant5'

  real_T Gain_Gain_k;                  // Expression: 0.01
                                          //  Referenced by: '<S18>/Gain'

  real_T Saturation_UpperSat_cb;       // Expression: 1
                                          //  Referenced by: '<S18>/Saturation'

  real_T Saturation_LowerSat_k;        // Expression: 0
                                          //  Referenced by: '<S18>/Saturation'

  real_T Constant_Value_oh;            // Expression: 0
                                          //  Referenced by: '<S6>/Constant'

  real_T Constant_Value_i;             // Expression: 100
                                          //  Referenced by: '<S7>/Constant'

  real_T Gain_Gain_d;                  // Expression: 0.01
                                          //  Referenced by: '<S13>/Gain'

  real_T Saturation_UpperSat_f;        // Expression: 1
                                          //  Referenced by: '<S13>/Saturation'

  real_T Saturation_LowerSat_p;        // Expression: 0
                                          //  Referenced by: '<S13>/Saturation'

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

  real_T yaw_Out_Y0;                   // Computed Parameter: yaw_Out_Y0
                                          //  Referenced by: '<S50>/yaw_Out'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S48>/Delay'

  real_T Rate_Value;                   // Expression: 0.01
                                          //  Referenced by: '<S48>/Rate'

  real_T Gain1_Gain;                   // Expression: -1
                                          //  Referenced by: '<S48>/Gain1'

  real_T Gain_Gain_e;                  // Expression: -1
                                          //  Referenced by: '<S48>/Gain'

  real_T Delay_InitialCondition_g;     // Expression: 1
                                          //  Referenced by: '<S49>/Delay'

  real_T Constant_Value_f;             // Expression: 0
                                          //  Referenced by: '<S49>/Constant'

  real_T Out_Y0;                       // Computed Parameter: Out_Y0
                                          //  Referenced by: '<S46>/Out'

  real_T Gain_Gain_l;                  // Expression: -1
                                          //  Referenced by: '<S44>/Gain'

  real_T yaw_Out_Y0_f;                 // Computed Parameter: yaw_Out_Y0_f
                                          //  Referenced by: '<S47>/yaw_Out'

  real_T Delay_InitialCondition_n;     // Expression: 0.0
                                          //  Referenced by: '<S39>/Delay'

  real_T Delay_InitialCondition_m;     // Expression: 0.0
                                          //  Referenced by: '<S44>/Delay'

  real_T Switch_Threshold;             // Expression: 0
                                          //  Referenced by: '<S44>/Switch'

  real_T Rateofdescent_Value;          // Expression: 0.02
                                          //  Referenced by: '<S44>/Rate of descent'

  real_T Gain2_Gain;                   // Expression: -1
                                          //  Referenced by: '<S44>/Gain2'

  real_T Gain1_Gain_a;                 // Expression: -1
                                          //  Referenced by: '<S44>/Gain1'

  real_T Delay_InitialCondition_j;     // Expression: 1
                                          //  Referenced by: '<S45>/Delay'

  real_T Constant_Value_nn;            // Expression: 0
                                          //  Referenced by: '<S45>/Constant'

  real_T Constant_Value_jd;            // Expression: 0
                                          //  Referenced by: '<S51>/Constant'

  real_T Constant_Value_gw;            // Expression: 6
                                          //  Referenced by: '<S41>/Constant'

  real_T yaw_Out_Y0_p;                 // Computed Parameter: yaw_Out_Y0_p
                                          //  Referenced by: '<S43>/yaw_Out'

  real_T Delay_InitialCondition_g0;    // Expression: 1
                                          //  Referenced by: '<S42>/Delay'

  real_T Constant_Value_ic;            // Expression: 0
                                          //  Referenced by: '<S42>/Constant'

  real_T ReadParameter_SampleTime;     // Expression: -1
                                          //  Referenced by: '<S37>/Read Parameter'

  real_T ReadParameter_SampleTime_c;   // Expression: -1
                                          //  Referenced by: '<S69>/Read Parameter'

  real_T ReadParameter_SampleTime_g;   // Expression: -1
                                          //  Referenced by: '<S68>/Read Parameter'

  real_T tau_Yaw_Y0;                   // Computed Parameter: tau_Yaw_Y0
                                          //  Referenced by: '<S72>/tau_Yaw'

  real_T tau_Pitch_Y0;                 // Computed Parameter: tau_Pitch_Y0
                                          //  Referenced by: '<S72>/tau_Pitch'

  real_T tau_Roll_Y0;                  // Computed Parameter: tau_Roll_Y0
                                          //  Referenced by: '<S72>/tau_Roll'

  real_T Constant1_Value_k;            // Expression: 0
                                          //  Referenced by: '<S108>/Constant1'

  real_T Constant1_Value_o;            // Expression: 0
                                          //  Referenced by: '<S160>/Constant1'

  real_T Constant1_Value_p;            // Expression: 0
                                          //  Referenced by: '<S212>/Constant1'

  real_T Clamping_zero_Value;          // Expression: 0
                                          //  Referenced by: '<S108>/Clamping_zero'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S118>/Integrator'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S113>/Filter'

  real_T RateLimiter2_RisingLim;       // Expression: 40*pi/180
                                          //  Referenced by: '<S72>/Rate Limiter2'

  real_T RateLimiter2_FallingLim;      // Expression: -40*pi/180
                                          //  Referenced by: '<S72>/Rate Limiter2'

  real_T RateLimiter2_IC;              // Expression: 0
                                          //  Referenced by: '<S72>/Rate Limiter2'

  real_T Saturation1_UpperSat;         // Expression: 20*pi/180
                                          //  Referenced by: '<S72>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -20*pi/180
                                          //  Referenced by: '<S72>/Saturation1'

  real_T Clamping_zero_Value_b;        // Expression: 0
                                          //  Referenced by: '<S160>/Clamping_zero'

  real_T Integrator_gainval_i;       // Computed Parameter: Integrator_gainval_i
                                        //  Referenced by: '<S170>/Integrator'

  real_T Filter_gainval_p;             // Computed Parameter: Filter_gainval_p
                                          //  Referenced by: '<S165>/Filter'

  real_T RateLimiter1_RisingLim;       // Expression: 40*pi/180
                                          //  Referenced by: '<S72>/Rate Limiter1'

  real_T RateLimiter1_FallingLim;      // Expression: -40*pi/180
                                          //  Referenced by: '<S72>/Rate Limiter1'

  real_T RateLimiter1_IC;              // Expression: 0
                                          //  Referenced by: '<S72>/Rate Limiter1'

  real_T Saturation_UpperSat_m;        // Expression: 20*pi/180
                                          //  Referenced by: '<S72>/Saturation'

  real_T Saturation_LowerSat_l;        // Expression: -20*pi/180
                                          //  Referenced by: '<S72>/Saturation'

  real_T Clamping_zero_Value_f;        // Expression: 0
                                          //  Referenced by: '<S212>/Clamping_zero'

  real_T Integrator_gainval_p;       // Computed Parameter: Integrator_gainval_p
                                        //  Referenced by: '<S222>/Integrator'

  real_T Filter_gainval_k;             // Computed Parameter: Filter_gainval_k
                                          //  Referenced by: '<S217>/Filter'

  real_T Constant_Value_a;             // Expression: 0
                                          //  Referenced by: '<S339>/Constant'

  real_T Switch1_Threshold;            // Expression: 0
                                          //  Referenced by: '<S341>/Switch1'

  real_T des_pitch_Y0;                 // Computed Parameter: des_pitch_Y0
                                          //  Referenced by: '<S75>/des_pitch'

  real_T des_roll_Y0;                  // Computed Parameter: des_roll_Y0
                                          //  Referenced by: '<S75>/des_roll'

  real_T des_yawrate_Y0;               // Computed Parameter: des_yawrate_Y0
                                          //  Referenced by: '<S75>/des_yawrate'

  real_T tau_Thrust_Y0;                // Computed Parameter: tau_Thrust_Y0
                                          //  Referenced by: '<S75>/tau_Thrust'

  real_T Constant1_Value_cc;           // Expression: 0
                                          //  Referenced by: '<S523>/Constant1'

  real_T Constant1_Value_f;            // Expression: 0
                                          //  Referenced by: '<S575>/Constant1'

  real_T Gain_Gain_a;                  // Expression: -1
                                          //  Referenced by: '<S340>/Gain'

  real_T Constant_Value_p;             // Expression: 2*pi
                                          //  Referenced by: '<S341>/Constant'

  real_T Switch_Threshold_p;           // Expression: pi
                                          //  Referenced by: '<S341>/Switch'

  real_T Gain1_Gain_ad;                // Expression: -1
                                          //  Referenced by: '<S75>/Gain1'

  real_T Gain1_Gain_j;                 // Expression: -1
                                          //  Referenced by: '<S339>/Gain1'

  real_T Clamping_zero_Value_o;        // Expression: 0
                                          //  Referenced by: '<S523>/Clamping_zero'

  real_T Filter_gainval_i;             // Computed Parameter: Filter_gainval_i
                                          //  Referenced by: '<S528>/Filter'

  real_T Integrator_gainval_p4;     // Computed Parameter: Integrator_gainval_p4
                                       //  Referenced by: '<S533>/Integrator'

  real_T Clamping_zero_Value_bl;       // Expression: 0
                                          //  Referenced by: '<S575>/Clamping_zero'

  real_T Filter_gainval_d;             // Computed Parameter: Filter_gainval_d
                                          //  Referenced by: '<S580>/Filter'

  real_T Integrator_gainval_ik;     // Computed Parameter: Integrator_gainval_ik
                                       //  Referenced by: '<S585>/Integrator'

  real_T Constant_Value_pp[4];         // Expression: [1 0 0 0]
                                          //  Referenced by: '<S76>/Constant'

  real_T Constant_Value_cs;            // Expression: 1
                                          //  Referenced by: '<S606>/Constant'

  real_T Constant_Value_m;             // Expression: 1
                                          //  Referenced by: '<S607>/Constant'

  real_T Switch_Threshold_o;           // Expression: 0
                                          //  Referenced by: '<S76>/Switch'

  real_T Constant2_Value_g;            // Expression: 1500
                                          //  Referenced by: '<S74>/Constant2'

  real_T Gain2_Gain_d;                 // Expression: 1/400
                                          //  Referenced by: '<S74>/Gain2'

  real_T Saturation2_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S74>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S74>/Saturation2'

  real_T Gain1_Gain_h;                 // Expression: -20*pi/180
                                          //  Referenced by: '<S4>/Gain1'

  real_T Constant1_Value_h;            // Expression: 1500
                                          //  Referenced by: '<S74>/Constant1'

  real_T Gain1_Gain_e;                 // Expression: 1/400
                                          //  Referenced by: '<S74>/Gain1'

  real_T Saturation1_UpperSat_p;       // Expression: 1
                                          //  Referenced by: '<S74>/Saturation1'

  real_T Saturation1_LowerSat_j;       // Expression: -1
                                          //  Referenced by: '<S74>/Saturation1'

  real_T Gain2_Gain_m;                 // Expression: 20*pi/180
                                          //  Referenced by: '<S4>/Gain2'

  real_T Constant_Value_ol;            // Expression: 1100
                                          //  Referenced by: '<S74>/Constant'

  real_T Gain_Gain_et;                 // Expression: 1/800
                                          //  Referenced by: '<S74>/Gain'

  real_T Saturation_UpperSat_j;        // Expression: 0.90
                                          //  Referenced by: '<S74>/Saturation'

  real_T Saturation_LowerSat_l4;       // Expression: 0
                                          //  Referenced by: '<S74>/Saturation'

  real_T Constant3_Value_n;            // Expression: 1500
                                          //  Referenced by: '<S74>/Constant3'

  real_T Gain3_Gain;                   // Expression: 1/400
                                          //  Referenced by: '<S74>/Gain3'

  real_T Saturation3_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S74>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S74>/Saturation3'

  real_T Gain4_Gain;                   // Expression: 50*pi/180
                                          //  Referenced by: '<S4>/Gain4'

  real_T Gain_Gain_k1;                 // Expression: -1
                                          //  Referenced by: '<S4>/Gain'

  real_T Gain_Gain_e2;                 // Expression: 5
                                          //  Referenced by: '<S5>/Gain'

  real_T Gain1_Gain_a2;                // Expression: 5
                                          //  Referenced by: '<S5>/Gain1'

  real_T Gain2_Gain_e;                 // Expression: 10
                                          //  Referenced by: '<S5>/Gain2'

  real_T Gain3_Gain_b;                 // Expression: 1
                                          //  Referenced by: '<S5>/Gain3'

  real_T Constant_Value_me;            // Expression: 0
                                          //  Referenced by: '<S10>/Constant'

  real_T Constant17_Value;             // Expression: 6
                                          //  Referenced by: '<S10>/Constant17'

  uint64_T Constant7_Value;            // Computed Parameter: Constant7_Value
                                          //  Referenced by: '<S62>/Constant7'

  real32_T Constant1_Value_d[2];       // Computed Parameter: Constant1_Value_d
                                          //  Referenced by: '<S69>/Constant1'

  real32_T Constant_Value_f2;          // Computed Parameter: Constant_Value_f2
                                          //  Referenced by: '<S69>/Constant'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S68>/Gain'

  real32_T Constant1_Value_k4[2];      // Computed Parameter: Constant1_Value_k4
                                          //  Referenced by: '<S68>/Constant1'

  real32_T Constant_Value_l4;          // Computed Parameter: Constant_Value_l4
                                          //  Referenced by: '<S68>/Constant'

  real32_T Constant_Value_fh[3];       // Computed Parameter: Constant_Value_fh
                                          //  Referenced by: '<S62>/Constant'

  real32_T Constant1_Value_hv[3];      // Computed Parameter: Constant1_Value_hv
                                          //  Referenced by: '<S62>/Constant1'

  real32_T Constant2_Value_f[3];       // Computed Parameter: Constant2_Value_f
                                          //  Referenced by: '<S62>/Constant2'

  real32_T Constant3_Value_a;          // Computed Parameter: Constant3_Value_a
                                          //  Referenced by: '<S62>/Constant3'

  real32_T Constant4_Value_g;          // Computed Parameter: Constant4_Value_g
                                          //  Referenced by: '<S62>/Constant4'

  boolean_T Constant5_Value_jn;        // Computed Parameter: Constant5_Value_jn
                                          //  Referenced by: '<S60>/Constant5'

  boolean_T Constant5_Value_k;         // Computed Parameter: Constant5_Value_k
                                          //  Referenced by: '<S61>/Constant5'

  boolean_T Constant1_Value_dl;        // Computed Parameter: Constant1_Value_dl
                                          //  Referenced by: '<S63>/Constant1'

  boolean_T Constant5_Value_h;         // Computed Parameter: Constant5_Value_h
                                          //  Referenced by: '<S63>/Constant5'

  boolean_T Constant5_Value_l;         // Computed Parameter: Constant5_Value_l
                                          //  Referenced by: '<S62>/Constant5'

  int8_T Constant_Value_gep;           // Computed Parameter: Constant_Value_gep
                                          //  Referenced by: '<S108>/Constant'

  int8_T Constant2_Value_i;            // Computed Parameter: Constant2_Value_i
                                          //  Referenced by: '<S108>/Constant2'

  int8_T Constant3_Value_h;            // Computed Parameter: Constant3_Value_h
                                          //  Referenced by: '<S108>/Constant3'

  int8_T Constant4_Value_f;            // Computed Parameter: Constant4_Value_f
                                          //  Referenced by: '<S108>/Constant4'

  int8_T Constant_Value_a1;            // Computed Parameter: Constant_Value_a1
                                          //  Referenced by: '<S160>/Constant'

  int8_T Constant2_Value_l;            // Computed Parameter: Constant2_Value_l
                                          //  Referenced by: '<S160>/Constant2'

  int8_T Constant3_Value_j;            // Computed Parameter: Constant3_Value_j
                                          //  Referenced by: '<S160>/Constant3'

  int8_T Constant4_Value_a;            // Computed Parameter: Constant4_Value_a
                                          //  Referenced by: '<S160>/Constant4'

  int8_T Constant_Value_jj;            // Computed Parameter: Constant_Value_jj
                                          //  Referenced by: '<S212>/Constant'

  int8_T Constant2_Value_o;            // Computed Parameter: Constant2_Value_o
                                          //  Referenced by: '<S212>/Constant2'

  int8_T Constant3_Value_l;            // Computed Parameter: Constant3_Value_l
                                          //  Referenced by: '<S212>/Constant3'

  int8_T Constant4_Value_n;            // Computed Parameter: Constant4_Value_n
                                          //  Referenced by: '<S212>/Constant4'

  int8_T Constant_Value_n1;            // Computed Parameter: Constant_Value_n1
                                          //  Referenced by: '<S523>/Constant'

  int8_T Constant2_Value_gq;           // Computed Parameter: Constant2_Value_gq
                                          //  Referenced by: '<S523>/Constant2'

  int8_T Constant3_Value_i;            // Computed Parameter: Constant3_Value_i
                                          //  Referenced by: '<S523>/Constant3'

  int8_T Constant4_Value_h;            // Computed Parameter: Constant4_Value_h
                                          //  Referenced by: '<S523>/Constant4'

  int8_T Constant_Value_gf;            // Computed Parameter: Constant_Value_gf
                                          //  Referenced by: '<S575>/Constant'

  int8_T Constant2_Value_ga;           // Computed Parameter: Constant2_Value_ga
                                          //  Referenced by: '<S575>/Constant2'

  int8_T Constant3_Value_b;            // Computed Parameter: Constant3_Value_b
                                          //  Referenced by: '<S575>/Constant3'

  int8_T Constant4_Value_fv;           // Computed Parameter: Constant4_Value_fv
                                          //  Referenced by: '<S575>/Constant4'

  uint8_T Constant_Value_fm;           // Computed Parameter: Constant_Value_fm
                                          //  Referenced by: '<S54>/Constant'

  uint8_T Constant6_Value;             // Computed Parameter: Constant6_Value
                                          //  Referenced by: '<S62>/Constant6'

};

// Real-time Model Data Structure
struct tag_RTM_HITL_HEXA_Hovering_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_HITL_HEXA_Hovering_T HITL_HEXA_Hovering_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_HITL_HEXA_Hovering_T HITL_HEXA_Hovering_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_HITL_HEXA_Hovering_T HITL_HEXA_Hovering_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void HITL_HEXA_Hovering_initialize(void);
  extern void HITL_HEXA_Hovering_step(void);
  extern void HITL_HEXA_Hovering_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_HITL_HEXA_Hovering_T *const HITL_HEXA_Hovering_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S9>/Bitwise Operator' : Unused code path elimination
//  Block '<S9>/Data Type Conversion' : Unused code path elimination
//  Block '<S9>/Data Type Conversion1' : Unused code path elimination
//  Block '<S9>/Data Type Conversion2' : Unused code path elimination
//  Block '<S9>/Gain' : Unused code path elimination
//  Block '<S9>/Gain1' : Unused code path elimination
//  Block '<S19>/NOT' : Unused code path elimination
//  Block '<S23>/NOT' : Unused code path elimination
//  Block '<S24>/NOT' : Unused code path elimination
//  Block '<S25>/Bitwise Operator' : Unused code path elimination
//  Block '<S25>/Data Type Conversion' : Unused code path elimination
//  Block '<S25>/Data Type Conversion1' : Unused code path elimination
//  Block '<S25>/Data Type Conversion2' : Unused code path elimination
//  Block '<S25>/Gain' : Unused code path elimination
//  Block '<S25>/Gain1' : Unused code path elimination
//  Block '<S30>/NOT' : Unused code path elimination
//  Block '<S26>/NOT' : Unused code path elimination
//  Block '<S27>/NOT' : Unused code path elimination
//  Block '<S57>/Compare' : Unused code path elimination
//  Block '<S57>/Constant' : Unused code path elimination
//  Block '<S58>/NOT' : Unused code path elimination
//  Block '<S53>/Subtract' : Unused code path elimination
//  Block '<S55>/NOT' : Unused code path elimination
//  Block '<S56>/NOT' : Unused code path elimination
//  Block '<S347>/Data Type Duplicate' : Unused code path elimination
//  Block '<S347>/Data Type Propagation' : Unused code path elimination
//  Block '<S39>/Reshape1' : Reshape block reduction
//  Block '<S4>/Data Type Conversion' : Eliminate redundant data type conversion


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
//  '<Root>' : 'HITL_HEXA_Hovering'
//  '<S1>'   : 'HITL_HEXA_Hovering/Actuator'
//  '<S2>'   : 'HITL_HEXA_Hovering/Estimator Output'
//  '<S3>'   : 'HITL_HEXA_Hovering/Navigation'
//  '<S4>'   : 'HITL_HEXA_Hovering/Subsystem Reference'
//  '<S5>'   : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block'
//  '<S6>'   : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/Emergency Kill'
//  '<S7>'   : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/Fault_Injection'
//  '<S8>'   : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/MATLAB Function'
//  '<S9>'   : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/Radio Control Transmitter'
//  '<S10>'  : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/Subsystem'
//  '<S11>'  : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/Emergency Kill/Compare To Constant'
//  '<S12>'  : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Compare To Constant'
//  '<S13>'  : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference'
//  '<S14>'  : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference1'
//  '<S15>'  : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference2'
//  '<S16>'  : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference3'
//  '<S17>'  : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference4'
//  '<S18>'  : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference5'
//  '<S19>'  : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/Radio Control Transmitter/PX4 uORB Read'
//  '<S20>'  : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S21>'  : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/Subsystem/PX4 uORB Message'
//  '<S22>'  : 'HITL_HEXA_Hovering/Actuator/Custom Mixer and PWM Output Block/Subsystem/PX4 uORB Write'
//  '<S23>'  : 'HITL_HEXA_Hovering/Estimator Output/PX4 uORB Read1'
//  '<S24>'  : 'HITL_HEXA_Hovering/Estimator Output/PX4 uORB Read2'
//  '<S25>'  : 'HITL_HEXA_Hovering/Estimator Output/Radio Control Transmitter'
//  '<S26>'  : 'HITL_HEXA_Hovering/Estimator Output/vehicle_attitude'
//  '<S27>'  : 'HITL_HEXA_Hovering/Estimator Output/vehicle_local_pos'
//  '<S28>'  : 'HITL_HEXA_Hovering/Estimator Output/PX4 uORB Read1/Enabled Subsystem'
//  '<S29>'  : 'HITL_HEXA_Hovering/Estimator Output/PX4 uORB Read2/Enabled Subsystem'
//  '<S30>'  : 'HITL_HEXA_Hovering/Estimator Output/Radio Control Transmitter/PX4 uORB Read'
//  '<S31>'  : 'HITL_HEXA_Hovering/Estimator Output/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S32>'  : 'HITL_HEXA_Hovering/Estimator Output/vehicle_attitude/Enabled Subsystem'
//  '<S33>'  : 'HITL_HEXA_Hovering/Estimator Output/vehicle_local_pos/Enabled Subsystem'
//  '<S34>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm'
//  '<S35>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission'
//  '<S36>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem'
//  '<S37>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC'
//  '<S38>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE'
//  '<S39>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land'
//  '<S40>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off'
//  '<S41>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint'
//  '<S42>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE'
//  '<S43>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE/Enabled Subsystem2'
//  '<S44>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land'
//  '<S45>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land'
//  '<S46>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land/Enabled Subsystem'
//  '<S47>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land/Enabled Subsystem2'
//  '<S48>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Ensure smooth ascend during Takeoff'
//  '<S49>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff'
//  '<S50>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff/Enabled Subsystem2'
//  '<S51>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning'
//  '<S52>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning/Compare To Constant'
//  '<S53>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC'
//  '<S54>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC'
//  '<S55>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead'
//  '<S56>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead'
//  '<S57>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/Compare To Constant'
//  '<S58>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read'
//  '<S59>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read/Enabled Subsystem'
//  '<S60>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint'
//  '<S61>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_WayPoint'
//  '<S62>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Empty_WayPoint'
//  '<S63>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Next_WayPoint'
//  '<S64>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Message'
//  '<S65>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Write'
//  '<S66>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP'
//  '<S67>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem'
//  '<S68>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem1'
//  '<S69>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem2'
//  '<S70>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead/Enabled Subsystem'
//  '<S71>'  : 'HITL_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead/Enabled Subsystem'
//  '<S72>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller'
//  '<S73>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Chart'
//  '<S74>'  : 'HITL_HEXA_Hovering/Subsystem Reference/PWM2CMD'
//  '<S75>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller'
//  '<S76>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Quaternion Validity Check'
//  '<S77>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles'
//  '<S78>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller'
//  '<S79>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1'
//  '<S80>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2'
//  '<S81>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3'
//  '<S82>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4'
//  '<S83>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Anti-windup'
//  '<S84>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/D Gain'
//  '<S85>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/External Derivative'
//  '<S86>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Filter'
//  '<S87>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Filter ICs'
//  '<S88>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/I Gain'
//  '<S89>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Ideal P Gain'
//  '<S90>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Ideal P Gain Fdbk'
//  '<S91>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Integrator'
//  '<S92>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Integrator ICs'
//  '<S93>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/N Copy'
//  '<S94>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/N Gain'
//  '<S95>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/P Copy'
//  '<S96>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Parallel P Gain'
//  '<S97>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Reset Signal'
//  '<S98>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Saturation'
//  '<S99>'  : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Saturation Fdbk'
//  '<S100>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Sum'
//  '<S101>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Sum Fdbk'
//  '<S102>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Tracking Mode'
//  '<S103>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Tracking Mode Sum'
//  '<S104>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Tsamp - Integral'
//  '<S105>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Tsamp - Ngain'
//  '<S106>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/postSat Signal'
//  '<S107>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/preSat Signal'
//  '<S108>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S109>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S110>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S111>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/D Gain/Internal Parameters'
//  '<S112>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/External Derivative/Error'
//  '<S113>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S114>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S115>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/I Gain/Internal Parameters'
//  '<S116>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S117>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S118>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Integrator/Discrete'
//  '<S119>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Integrator ICs/Internal IC'
//  '<S120>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/N Copy/Disabled'
//  '<S121>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/N Gain/Internal Parameters'
//  '<S122>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/P Copy/Disabled'
//  '<S123>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S124>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Reset Signal/Disabled'
//  '<S125>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Saturation/Enabled'
//  '<S126>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S127>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Sum/Sum_PID'
//  '<S128>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Sum Fdbk/Disabled'
//  '<S129>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Tracking Mode/Disabled'
//  '<S130>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S131>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S132>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S133>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/postSat Signal/Forward_Path'
//  '<S134>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/preSat Signal/Forward_Path'
//  '<S135>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Anti-windup'
//  '<S136>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/D Gain'
//  '<S137>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/External Derivative'
//  '<S138>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Filter'
//  '<S139>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Filter ICs'
//  '<S140>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/I Gain'
//  '<S141>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Ideal P Gain'
//  '<S142>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S143>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Integrator'
//  '<S144>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Integrator ICs'
//  '<S145>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/N Copy'
//  '<S146>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/N Gain'
//  '<S147>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/P Copy'
//  '<S148>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Parallel P Gain'
//  '<S149>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Reset Signal'
//  '<S150>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Saturation'
//  '<S151>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Saturation Fdbk'
//  '<S152>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Sum'
//  '<S153>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Sum Fdbk'
//  '<S154>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Tracking Mode'
//  '<S155>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Tracking Mode Sum'
//  '<S156>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Tsamp - Integral'
//  '<S157>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Tsamp - Ngain'
//  '<S158>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/postSat Signal'
//  '<S159>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/preSat Signal'
//  '<S160>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S161>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S162>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S163>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/D Gain/Internal Parameters'
//  '<S164>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/External Derivative/Error'
//  '<S165>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S166>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S167>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/I Gain/Internal Parameters'
//  '<S168>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S169>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S170>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Integrator/Discrete'
//  '<S171>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Integrator ICs/Internal IC'
//  '<S172>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/N Copy/Disabled'
//  '<S173>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/N Gain/Internal Parameters'
//  '<S174>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/P Copy/Disabled'
//  '<S175>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S176>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Reset Signal/Disabled'
//  '<S177>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Saturation/Enabled'
//  '<S178>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S179>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Sum/Sum_PID'
//  '<S180>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S181>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Tracking Mode/Disabled'
//  '<S182>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S183>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S184>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S185>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S186>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S187>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Anti-windup'
//  '<S188>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/D Gain'
//  '<S189>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/External Derivative'
//  '<S190>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Filter'
//  '<S191>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Filter ICs'
//  '<S192>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/I Gain'
//  '<S193>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Ideal P Gain'
//  '<S194>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Ideal P Gain Fdbk'
//  '<S195>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Integrator'
//  '<S196>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Integrator ICs'
//  '<S197>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/N Copy'
//  '<S198>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/N Gain'
//  '<S199>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/P Copy'
//  '<S200>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Parallel P Gain'
//  '<S201>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Reset Signal'
//  '<S202>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Saturation'
//  '<S203>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Saturation Fdbk'
//  '<S204>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Sum'
//  '<S205>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Sum Fdbk'
//  '<S206>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Tracking Mode'
//  '<S207>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Tracking Mode Sum'
//  '<S208>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Tsamp - Integral'
//  '<S209>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Tsamp - Ngain'
//  '<S210>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/postSat Signal'
//  '<S211>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/preSat Signal'
//  '<S212>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S213>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S214>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S215>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/D Gain/Internal Parameters'
//  '<S216>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/External Derivative/Error'
//  '<S217>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S218>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S219>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/I Gain/Internal Parameters'
//  '<S220>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Ideal P Gain/Passthrough'
//  '<S221>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S222>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Integrator/Discrete'
//  '<S223>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Integrator ICs/Internal IC'
//  '<S224>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/N Copy/Disabled'
//  '<S225>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/N Gain/Internal Parameters'
//  '<S226>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/P Copy/Disabled'
//  '<S227>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S228>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Reset Signal/Disabled'
//  '<S229>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Saturation/Enabled'
//  '<S230>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Saturation Fdbk/Disabled'
//  '<S231>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Sum/Sum_PID'
//  '<S232>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Sum Fdbk/Disabled'
//  '<S233>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Tracking Mode/Disabled'
//  '<S234>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S235>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S236>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S237>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/postSat Signal/Forward_Path'
//  '<S238>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/preSat Signal/Forward_Path'
//  '<S239>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Anti-windup'
//  '<S240>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/D Gain'
//  '<S241>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/External Derivative'
//  '<S242>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Filter'
//  '<S243>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Filter ICs'
//  '<S244>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/I Gain'
//  '<S245>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Ideal P Gain'
//  '<S246>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Ideal P Gain Fdbk'
//  '<S247>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Integrator'
//  '<S248>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Integrator ICs'
//  '<S249>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/N Copy'
//  '<S250>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/N Gain'
//  '<S251>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/P Copy'
//  '<S252>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Parallel P Gain'
//  '<S253>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Reset Signal'
//  '<S254>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Saturation'
//  '<S255>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Saturation Fdbk'
//  '<S256>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Sum'
//  '<S257>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Sum Fdbk'
//  '<S258>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Tracking Mode'
//  '<S259>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Tracking Mode Sum'
//  '<S260>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Tsamp - Integral'
//  '<S261>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Tsamp - Ngain'
//  '<S262>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/postSat Signal'
//  '<S263>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/preSat Signal'
//  '<S264>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Anti-windup/Disabled'
//  '<S265>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/D Gain/Disabled'
//  '<S266>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/External Derivative/Disabled'
//  '<S267>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Filter/Disabled'
//  '<S268>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Filter ICs/Disabled'
//  '<S269>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/I Gain/Disabled'
//  '<S270>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Ideal P Gain/Passthrough'
//  '<S271>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S272>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Integrator/Disabled'
//  '<S273>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Integrator ICs/Disabled'
//  '<S274>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S275>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/N Gain/Disabled'
//  '<S276>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/P Copy/Disabled'
//  '<S277>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S278>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Reset Signal/Disabled'
//  '<S279>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Saturation/Passthrough'
//  '<S280>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Saturation Fdbk/Disabled'
//  '<S281>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Sum/Passthrough_P'
//  '<S282>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Sum Fdbk/Disabled'
//  '<S283>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Tracking Mode/Disabled'
//  '<S284>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S285>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S286>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S287>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/postSat Signal/Forward_Path'
//  '<S288>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/preSat Signal/Forward_Path'
//  '<S289>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Anti-windup'
//  '<S290>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/D Gain'
//  '<S291>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/External Derivative'
//  '<S292>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Filter'
//  '<S293>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Filter ICs'
//  '<S294>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/I Gain'
//  '<S295>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Ideal P Gain'
//  '<S296>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S297>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Integrator'
//  '<S298>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Integrator ICs'
//  '<S299>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/N Copy'
//  '<S300>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/N Gain'
//  '<S301>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/P Copy'
//  '<S302>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Parallel P Gain'
//  '<S303>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Reset Signal'
//  '<S304>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Saturation'
//  '<S305>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Saturation Fdbk'
//  '<S306>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Sum'
//  '<S307>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Sum Fdbk'
//  '<S308>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Tracking Mode'
//  '<S309>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Tracking Mode Sum'
//  '<S310>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Tsamp - Integral'
//  '<S311>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Tsamp - Ngain'
//  '<S312>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/postSat Signal'
//  '<S313>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/preSat Signal'
//  '<S314>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Anti-windup/Disabled'
//  '<S315>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/D Gain/Disabled'
//  '<S316>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/External Derivative/Disabled'
//  '<S317>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Filter/Disabled'
//  '<S318>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Filter ICs/Disabled'
//  '<S319>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/I Gain/Disabled'
//  '<S320>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S321>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S322>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Integrator/Disabled'
//  '<S323>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Integrator ICs/Disabled'
//  '<S324>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S325>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/N Gain/Disabled'
//  '<S326>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/P Copy/Disabled'
//  '<S327>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S328>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Reset Signal/Disabled'
//  '<S329>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Saturation/Passthrough'
//  '<S330>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S331>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Sum/Passthrough_P'
//  '<S332>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S333>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Tracking Mode/Disabled'
//  '<S334>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S335>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S336>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S337>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S338>' : 'HITL_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S339>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/Altitude Signal conditioning'
//  '<S340>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/Calculate Transformation Matrix'
//  '<S341>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/Calculate minimum Turn'
//  '<S342>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller'
//  '<S343>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1'
//  '<S344>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5'
//  '<S345>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude'
//  '<S346>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz'
//  '<S347>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/Altitude Signal conditioning/Saturation Dynamic'
//  '<S348>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Anti-windup'
//  '<S349>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/D Gain'
//  '<S350>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/External Derivative'
//  '<S351>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Filter'
//  '<S352>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Filter ICs'
//  '<S353>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/I Gain'
//  '<S354>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Ideal P Gain'
//  '<S355>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Ideal P Gain Fdbk'
//  '<S356>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Integrator'
//  '<S357>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Integrator ICs'
//  '<S358>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/N Copy'
//  '<S359>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/N Gain'
//  '<S360>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/P Copy'
//  '<S361>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Parallel P Gain'
//  '<S362>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Reset Signal'
//  '<S363>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Saturation'
//  '<S364>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Saturation Fdbk'
//  '<S365>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Sum'
//  '<S366>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Sum Fdbk'
//  '<S367>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Tracking Mode'
//  '<S368>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Tracking Mode Sum'
//  '<S369>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Tsamp - Integral'
//  '<S370>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Tsamp - Ngain'
//  '<S371>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/postSat Signal'
//  '<S372>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/preSat Signal'
//  '<S373>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Anti-windup/Disabled'
//  '<S374>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/D Gain/Disabled'
//  '<S375>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/External Derivative/Disabled'
//  '<S376>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Filter/Disabled'
//  '<S377>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Filter ICs/Disabled'
//  '<S378>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/I Gain/Disabled'
//  '<S379>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S380>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S381>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Integrator/Disabled'
//  '<S382>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Integrator ICs/Disabled'
//  '<S383>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S384>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/N Gain/Disabled'
//  '<S385>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/P Copy/Disabled'
//  '<S386>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S387>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Reset Signal/Disabled'
//  '<S388>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Saturation/Enabled'
//  '<S389>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S390>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Sum/Passthrough_P'
//  '<S391>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Sum Fdbk/Disabled'
//  '<S392>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Tracking Mode/Disabled'
//  '<S393>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S394>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S395>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S396>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/postSat Signal/Forward_Path'
//  '<S397>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/preSat Signal/Forward_Path'
//  '<S398>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Anti-windup'
//  '<S399>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/D Gain'
//  '<S400>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/External Derivative'
//  '<S401>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Filter'
//  '<S402>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Filter ICs'
//  '<S403>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/I Gain'
//  '<S404>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Ideal P Gain'
//  '<S405>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S406>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Integrator'
//  '<S407>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Integrator ICs'
//  '<S408>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/N Copy'
//  '<S409>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/N Gain'
//  '<S410>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/P Copy'
//  '<S411>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Parallel P Gain'
//  '<S412>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Reset Signal'
//  '<S413>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Saturation'
//  '<S414>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Saturation Fdbk'
//  '<S415>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Sum'
//  '<S416>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Sum Fdbk'
//  '<S417>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Tracking Mode'
//  '<S418>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Tracking Mode Sum'
//  '<S419>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Tsamp - Integral'
//  '<S420>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Tsamp - Ngain'
//  '<S421>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/postSat Signal'
//  '<S422>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/preSat Signal'
//  '<S423>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Anti-windup/Disabled'
//  '<S424>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/D Gain/Disabled'
//  '<S425>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/External Derivative/Disabled'
//  '<S426>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Filter/Disabled'
//  '<S427>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Filter ICs/Disabled'
//  '<S428>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/I Gain/Disabled'
//  '<S429>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S430>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S431>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Integrator/Disabled'
//  '<S432>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Integrator ICs/Disabled'
//  '<S433>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S434>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/N Gain/Disabled'
//  '<S435>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/P Copy/Disabled'
//  '<S436>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S437>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Reset Signal/Disabled'
//  '<S438>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Saturation/Enabled'
//  '<S439>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S440>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Sum/Passthrough_P'
//  '<S441>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S442>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Tracking Mode/Disabled'
//  '<S443>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S444>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S445>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S446>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S447>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S448>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Anti-windup'
//  '<S449>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/D Gain'
//  '<S450>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/External Derivative'
//  '<S451>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Filter'
//  '<S452>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Filter ICs'
//  '<S453>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/I Gain'
//  '<S454>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Ideal P Gain'
//  '<S455>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Ideal P Gain Fdbk'
//  '<S456>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Integrator'
//  '<S457>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Integrator ICs'
//  '<S458>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/N Copy'
//  '<S459>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/N Gain'
//  '<S460>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/P Copy'
//  '<S461>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Parallel P Gain'
//  '<S462>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Reset Signal'
//  '<S463>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Saturation'
//  '<S464>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Saturation Fdbk'
//  '<S465>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Sum'
//  '<S466>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Sum Fdbk'
//  '<S467>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Tracking Mode'
//  '<S468>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Tracking Mode Sum'
//  '<S469>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Tsamp - Integral'
//  '<S470>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Tsamp - Ngain'
//  '<S471>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/postSat Signal'
//  '<S472>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/preSat Signal'
//  '<S473>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Anti-windup/Disabled'
//  '<S474>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/D Gain/Disabled'
//  '<S475>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/External Derivative/Disabled'
//  '<S476>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Filter/Disabled'
//  '<S477>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Filter ICs/Disabled'
//  '<S478>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/I Gain/Disabled'
//  '<S479>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Ideal P Gain/Passthrough'
//  '<S480>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Ideal P Gain Fdbk/Disabled'
//  '<S481>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Integrator/Disabled'
//  '<S482>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Integrator ICs/Disabled'
//  '<S483>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/N Copy/Disabled wSignal Specification'
//  '<S484>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/N Gain/Disabled'
//  '<S485>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/P Copy/Disabled'
//  '<S486>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Parallel P Gain/Internal Parameters'
//  '<S487>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Reset Signal/Disabled'
//  '<S488>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Saturation/Enabled'
//  '<S489>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Saturation Fdbk/Disabled'
//  '<S490>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Sum/Passthrough_P'
//  '<S491>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Sum Fdbk/Disabled'
//  '<S492>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Tracking Mode/Disabled'
//  '<S493>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Tracking Mode Sum/Passthrough'
//  '<S494>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Tsamp - Integral/TsSignalSpecification'
//  '<S495>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Tsamp - Ngain/Passthrough'
//  '<S496>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/postSat Signal/Forward_Path'
//  '<S497>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/preSat Signal/Forward_Path'
//  '<S498>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Anti-windup'
//  '<S499>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/D Gain'
//  '<S500>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/External Derivative'
//  '<S501>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Filter'
//  '<S502>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Filter ICs'
//  '<S503>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/I Gain'
//  '<S504>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Ideal P Gain'
//  '<S505>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S506>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Integrator'
//  '<S507>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Integrator ICs'
//  '<S508>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/N Copy'
//  '<S509>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/N Gain'
//  '<S510>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/P Copy'
//  '<S511>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Parallel P Gain'
//  '<S512>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Reset Signal'
//  '<S513>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Saturation'
//  '<S514>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Saturation Fdbk'
//  '<S515>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Sum'
//  '<S516>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Sum Fdbk'
//  '<S517>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Tracking Mode'
//  '<S518>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Tracking Mode Sum'
//  '<S519>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Tsamp - Integral'
//  '<S520>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Tsamp - Ngain'
//  '<S521>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/postSat Signal'
//  '<S522>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/preSat Signal'
//  '<S523>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel'
//  '<S524>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S525>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S526>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/D Gain/Internal Parameters'
//  '<S527>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/External Derivative/Error'
//  '<S528>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Filter/Disc. Forward Euler Filter'
//  '<S529>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Filter ICs/Internal IC - Filter'
//  '<S530>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/I Gain/Internal Parameters'
//  '<S531>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S532>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Ideal P Gain Fdbk/Passthrough'
//  '<S533>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Integrator/Discrete'
//  '<S534>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Integrator ICs/Internal IC'
//  '<S535>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/N Copy/Disabled'
//  '<S536>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/N Gain/Internal Parameters'
//  '<S537>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/P Copy/Disabled'
//  '<S538>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Parallel P Gain/Internal Parameters'
//  '<S539>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Reset Signal/Disabled'
//  '<S540>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Saturation/Enabled'
//  '<S541>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Saturation Fdbk/Passthrough'
//  '<S542>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Sum/Sum_PID'
//  '<S543>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Sum Fdbk/Enabled'
//  '<S544>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S545>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S546>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S547>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S548>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/postSat Signal/Feedback_Path'
//  '<S549>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/preSat Signal/Feedback_Path'
//  '<S550>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Anti-windup'
//  '<S551>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/D Gain'
//  '<S552>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/External Derivative'
//  '<S553>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Filter'
//  '<S554>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Filter ICs'
//  '<S555>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/I Gain'
//  '<S556>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Ideal P Gain'
//  '<S557>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Ideal P Gain Fdbk'
//  '<S558>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Integrator'
//  '<S559>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Integrator ICs'
//  '<S560>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/N Copy'
//  '<S561>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/N Gain'
//  '<S562>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/P Copy'
//  '<S563>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Parallel P Gain'
//  '<S564>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Reset Signal'
//  '<S565>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Saturation'
//  '<S566>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Saturation Fdbk'
//  '<S567>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Sum'
//  '<S568>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Sum Fdbk'
//  '<S569>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Tracking Mode'
//  '<S570>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Tracking Mode Sum'
//  '<S571>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Tsamp - Integral'
//  '<S572>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Tsamp - Ngain'
//  '<S573>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/postSat Signal'
//  '<S574>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/preSat Signal'
//  '<S575>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel'
//  '<S576>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S577>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S578>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/D Gain/Internal Parameters'
//  '<S579>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/External Derivative/Error'
//  '<S580>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Filter/Disc. Forward Euler Filter'
//  '<S581>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Filter ICs/Internal IC - Filter'
//  '<S582>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/I Gain/Internal Parameters'
//  '<S583>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Ideal P Gain/Passthrough'
//  '<S584>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Ideal P Gain Fdbk/Passthrough'
//  '<S585>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Integrator/Discrete'
//  '<S586>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Integrator ICs/Internal IC'
//  '<S587>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/N Copy/Disabled'
//  '<S588>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/N Gain/Internal Parameters'
//  '<S589>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/P Copy/Disabled'
//  '<S590>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Parallel P Gain/Internal Parameters'
//  '<S591>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Reset Signal/Disabled'
//  '<S592>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Saturation/Enabled'
//  '<S593>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Saturation Fdbk/Passthrough'
//  '<S594>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Sum/Sum_PID'
//  '<S595>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Sum Fdbk/Enabled'
//  '<S596>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Tracking Mode/Disabled'
//  '<S597>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Tracking Mode Sum/Passthrough'
//  '<S598>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Tsamp - Integral/TsSignalSpecification'
//  '<S599>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Tsamp - Ngain/Passthrough'
//  '<S600>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/postSat Signal/Feedback_Path'
//  '<S601>' : 'HITL_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/preSat Signal/Feedback_Path'
//  '<S602>' : 'HITL_HEXA_Hovering/Subsystem Reference/Quaternion Validity Check/Quaternion Norm'
//  '<S603>' : 'HITL_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles/Angle Calculation'
//  '<S604>' : 'HITL_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S605>' : 'HITL_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S606>' : 'HITL_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S607>' : 'HITL_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S608>' : 'HITL_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S609>' : 'HITL_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S610>' : 'HITL_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                                 // HITL_HEXA_Hovering_h_

//
// File trailer for generated code.
//
// [EOF]
//
