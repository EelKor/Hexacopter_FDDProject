//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_HEXA_Hovering.h
//
// Code generated for Simulink model 'FLIGHT_HEXA_Hovering'.
//
// Model version                  : 5.30
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Thu Jan  9 13:36:09 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef FLIGHT_HEXA_Hovering_h_
#define FLIGHT_HEXA_Hovering_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_uORB_Read.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Write.h"
#include "FLIGHT_HEXA_Hovering_types.h"
#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/vehicle_trajectory_waypoint.h>
#include <uORB/topics/position_setpoint_triplet.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/actuator_motors.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/trajectory_waypoint.h>
#include <uORB/topics/home_position.h>
#include <uORB/topics/vehicle_angular_velocity.h>

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

// Block signals for system '<S6>/SourceBlock'
struct B_SourceBlock_FLIGHT_HEXA_Hovering_T {
  px4_Bus_actuator_armed SourceBlock_o2;// '<S6>/SourceBlock'
  boolean_T SourceBlock_o1;            // '<S6>/SourceBlock'
};

// Block states (default storage) for system '<S6>/SourceBlock'
struct DW_SourceBlock_FLIGHT_HEXA_Hovering_T {
  px4_internal_block_Subscriber_FLIGHT_HEXA_Hovering_T obj;// '<S6>/SourceBlock' 
  boolean_T objisempty;                // '<S6>/SourceBlock'
};

// Block signals for system '<S12>/SourceBlock'
struct B_SourceBlock_FLIGHT_HEXA_Hovering_i_T {
  px4_Bus_input_rc SourceBlock_o2;     // '<S12>/SourceBlock'
  boolean_T SourceBlock_o1;            // '<S12>/SourceBlock'
};

// Block states (default storage) for system '<S12>/SourceBlock'
struct DW_SourceBlock_FLIGHT_HEXA_Hovering_m_T {
  px4_internal_block_Subscriber_FLIGHT_HEXA_Hovering_T obj;// '<S12>/SourceBlock' 
  boolean_T objisempty;                // '<S12>/SourceBlock'
};

// Block signals for system '<S42>/MATLAB System'
struct B_MATLABSystem_FLIGHT_HEXA_Hovering_T {
  real32_T MATLABSystem[3];            // '<S42>/MATLAB System'
  real_T dLat;
};

// Block states (default storage) for system '<S42>/MATLAB System'
struct DW_MATLABSystem_FLIGHT_HEXA_Hovering_T {
  px4_internal_block_LLA2LocalCoordinatesNED_FLIGHT_HEXA_Hoveri_T obj;// '<S42>/MATLAB System' 
  boolean_T objisempty;                // '<S42>/MATLAB System'
};

// Block signals (default storage)
struct B_FLIGHT_HEXA_Hovering_T {
  px4_Bus_vehicle_trajectory_waypoint BusAssignment1;// '<S36>/Bus Assignment1'
  px4_Bus_vehicle_trajectory_waypoint In1;// '<S41>/In1'
  px4_Bus_vehicle_trajectory_waypoint r;
  px4_Bus_position_setpoint_triplet In1_p;// '<S53>/In1'
  px4_Bus_position_setpoint_triplet r1;
  px4_Bus_vehicle_local_position In1_c;// '<S15>/In1'
  px4_Bus_vehicle_local_position r2;
  px4_Bus_input_rc In1_h;              // '<S70>/In1'
  px4_Bus_input_rc In1_j;              // '<S13>/In1'
  px4_Bus_actuator_motors BusAssignment;// '<S59>/Bus Assignment'
  real_T b_waypointsIn_data[9];
  real_T MatrixConcatenate_p[9];       // '<S23>/Matrix Concatenate'
  px4_Bus_vehicle_attitude In1_m;      // '<S14>/In1'
  px4_Bus_vehicle_attitude r3;
  px4_Bus_trajectory_waypoint BusAssignment1_f;// '<S44>/Bus Assignment1'
  px4_Bus_home_position In1_f;         // '<S52>/In1'
  px4_Bus_home_position r4;
  px4_Bus_vehicle_angular_velocity In1_l;// '<S10>/In1'
  px4_Bus_vehicle_angular_velocity r5;
  real_T lla0[3];
  real_T virtualWaypoint[3];
  real_T b_startWaypoint[3];
  real_T VectorConcatenate[3];         // '<S604>/Vector Concatenate'
  real_T DataTypeConversion2[3];       // '<S1>/Data Type Conversion2'
  real_T dv[3];
  px4_Bus_actuator_armed In1_b;        // '<S11>/In1'
  real_T Saturation[2];                // '<S389>/Saturation'
  real_T Gain1;                        // '<S76>/Gain1'
  real_T Saturation_e;                 // '<S489>/Saturation'
  real_T Saturation_f;                 // '<S593>/Saturation'
  real_T Saturation_l;                 // '<S126>/Saturation'
  real_T Saturation_o;                 // '<S178>/Saturation'
  real_T Saturation_m;                 // '<S230>/Saturation'
  real_T yaw_In;                       // '<S25>/yaw_In'
  real_T yaw_In_i;                     // '<S29>/yaw_In'
  real_T In;                           // '<S28>/In'
  real_T yaw_In_ik;                    // '<S32>/yaw_In'
  real_T Switch3;                      // '<S54>/Switch3'
  real_T Switch2;                      // '<S54>/Switch2'
  real_T Sum;                          // '<S603>/Sum'
  real_T Gain2;                        // '<S4>/Gain2'
  real_T Gain_i;                       // '<S30>/Gain'
  real_T Sum5;                         // '<S76>/Sum5'
  real_T rtb_Merge_idx_3;
  real_T rtb_Switch_aw_idx_0;
  real_T rtb_Switch_aw_idx_1;
  real_T rtb_Switch_aw_idx_2;
  real_T rtb_Switch_aw_idx_3;
  real_T rtb_Merge_idx_2;
  real_T rtb_Merge_idx_0;
  real_T rtb_Merge_idx_1;
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
  boolean_T IsNaN_l[2];                // '<S21>/IsNaN'
  int8_T rtPrevAction;
  int8_T rtAction;
  boolean_T Compare_k;                 // '<S60>/Compare'
  boolean_T OR_g;                      // '<S21>/OR'
  boolean_T Compare;                   // '<S61>/Compare'
  boolean_T latp2;
  B_SourceBlock_FLIGHT_HEXA_Hovering_i_T SourceBlock_g;// '<S12>/SourceBlock'
  B_SourceBlock_FLIGHT_HEXA_Hovering_T SourceBlock_h;// '<S6>/SourceBlock'
  B_MATLABSystem_FLIGHT_HEXA_Hovering_T MATLABSystem_b;// '<S42>/MATLAB System'
  B_MATLABSystem_FLIGHT_HEXA_Hovering_T MATLABSystem;// '<S42>/MATLAB System'
  B_SourceBlock_FLIGHT_HEXA_Hovering_i_T SourceBlock_b;// '<S12>/SourceBlock'
  B_SourceBlock_FLIGHT_HEXA_Hovering_T SourceBlock_l;// '<S6>/SourceBlock'
};

// Block states (default storage) for system '<Root>'
struct DW_FLIGHT_HEXA_Hovering_T {
  uav_sluav_internal_system_WaypointFollower_FLIGHT_HEXA_Hoveri_T obj;// '<S23>/UAV Waypoint Follower' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_c;// '<S55>/Read Parameter5' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_d;// '<S55>/Read Parameter4' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_i;// '<S55>/Read Parameter3' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_m;// '<S55>/Read Parameter2' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_b;// '<S55>/Read Parameter13' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_a;// '<S55>/Read Parameter1' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_b4;// '<S50>/Read Parameter' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_g;// '<S51>/Read Parameter' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_k;// '<S19>/Read Parameter' 
  px4_internal_block_Subscriber_FLIGHT_HEXA_Hovering_T obj_kz;// '<S38>/SourceBlock' 
  px4_internal_block_Subscriber_FLIGHT_HEXA_Hovering_T obj_gf;// '<S37>/SourceBlock' 
  px4_internal_block_Subscriber_FLIGHT_HEXA_Hovering_T obj_e;// '<S40>/SourceBlock' 
  px4_internal_block_Subscriber_FLIGHT_HEXA_Hovering_T obj_mg;// '<S9>/SourceBlock' 
  px4_internal_block_Subscriber_FLIGHT_HEXA_Hovering_T obj_gv;// '<S8>/SourceBlock' 
  px4_internal_block_Subscriber_FLIGHT_HEXA_Hovering_T obj_p;// '<S5>/SourceBlock' 
  px4_internal_block_getPX4AbsoluteTime_FLIGHT_HEXA_Hovering_T obj_n;// '<S35>/PX4 Timestamp' 
  px4_internal_block_LLA2LocalCoordinates_FLIGHT_HEXA_Hovering_T obj_mr;// '<S19>/LLA2LocalCoordinates' 
  px4_internal_block_Publisher_FLIGHT_HEXA_Hovering_T obj_m4;// '<S72>/SinkBlock' 
  px4_internal_block_Publisher_FLIGHT_HEXA_Hovering_T obj_mc;// '<S47>/SinkBlock' 
  real_T Filter_DSTATE;                // '<S529>/Filter'
  real_T Integrator_DSTATE;            // '<S534>/Integrator'
  real_T Filter_DSTATE_n;              // '<S581>/Filter'
  real_T Integrator_DSTATE_c;          // '<S586>/Integrator'
  real_T Integrator_DSTATE_k;          // '<S119>/Integrator'
  real_T Filter_DSTATE_e;              // '<S114>/Filter'
  real_T Integrator_DSTATE_kd;         // '<S171>/Integrator'
  real_T Filter_DSTATE_ek;             // '<S166>/Filter'
  real_T Integrator_DSTATE_i;          // '<S223>/Integrator'
  real_T Filter_DSTATE_j;              // '<S218>/Filter'
  real_T Delay_DSTATE;                 // '<S24>/Delay'
  real_T Delay_DSTATE_l[2];            // '<S21>/Delay'
  real_T Delay_DSTATE_n;               // '<S26>/Delay'
  real_T Delay_DSTATE_b;               // '<S27>/Delay'
  real_T Delay_DSTATE_c;               // '<S30>/Delay'
  real_T Delay_DSTATE_d;               // '<S31>/Delay'
  real_T PrevY;                        // '<S73>/Rate Limiter2'
  real_T PrevY_f;                      // '<S73>/Rate Limiter1'
  px4_internal_block_LLA2LocalCoordinatesNED_FLIGHT_HEXA_Hoveri_T obj_mu;// '<S45>/MATLAB System' 
  int8_T If_ActiveSubsystem;           // '<S18>/If'
  uint8_T is_active_c3_FLIGHT_HEXA_Hovering;// '<S4>/Chart'
  uint8_T is_c3_FLIGHT_HEXA_Hovering;  // '<S4>/Chart'
  DW_SourceBlock_FLIGHT_HEXA_Hovering_m_T SourceBlock_g;// '<S12>/SourceBlock'
  DW_SourceBlock_FLIGHT_HEXA_Hovering_T SourceBlock_h;// '<S6>/SourceBlock'
  DW_MATLABSystem_FLIGHT_HEXA_Hovering_T MATLABSystem_b;// '<S42>/MATLAB System' 
  DW_MATLABSystem_FLIGHT_HEXA_Hovering_T MATLABSystem;// '<S42>/MATLAB System'
  DW_SourceBlock_FLIGHT_HEXA_Hovering_m_T SourceBlock_b;// '<S12>/SourceBlock'
  DW_SourceBlock_FLIGHT_HEXA_Hovering_T SourceBlock_l;// '<S6>/SourceBlock'
};

// Parameters (default storage)
struct P_FLIGHT_HEXA_Hovering_T_ {
  real_T PIDController_D;              // Mask Parameter: PIDController_D
                                          //  Referenced by: '<S112>/Derivative Gain'

  real_T PIDController1_D;             // Mask Parameter: PIDController1_D
                                          //  Referenced by: '<S164>/Derivative Gain'

  real_T PIDController2_D;             // Mask Parameter: PIDController2_D
                                          //  Referenced by: '<S216>/Derivative Gain'

  real_T PID_Altitude_D;               // Mask Parameter: PID_Altitude_D
                                          //  Referenced by: '<S527>/Derivative Gain'

  real_T PID_vz_D;                     // Mask Parameter: PID_vz_D
                                          //  Referenced by: '<S579>/Derivative Gain'

  real_T PIDController_I;              // Mask Parameter: PIDController_I
                                          //  Referenced by: '<S116>/Integral Gain'

  real_T PIDController1_I;             // Mask Parameter: PIDController1_I
                                          //  Referenced by: '<S168>/Integral Gain'

  real_T PIDController2_I;             // Mask Parameter: PIDController2_I
                                          //  Referenced by: '<S220>/Integral Gain'

  real_T PID_Altitude_I;               // Mask Parameter: PID_Altitude_I
                                          //  Referenced by: '<S531>/Integral Gain'

  real_T PID_vz_I;                     // Mask Parameter: PID_vz_I
                                          //  Referenced by: '<S583>/Integral Gain'

  real_T PIDController_InitialConditionForFilter;
                      // Mask Parameter: PIDController_InitialConditionForFilter
                         //  Referenced by: '<S114>/Filter'

  real_T PIDController1_InitialConditionForFilter;
                     // Mask Parameter: PIDController1_InitialConditionForFilter
                        //  Referenced by: '<S166>/Filter'

  real_T PIDController2_InitialConditionForFilter;
                     // Mask Parameter: PIDController2_InitialConditionForFilter
                        //  Referenced by: '<S218>/Filter'

  real_T PID_Altitude_InitialConditionForFilter;
                       // Mask Parameter: PID_Altitude_InitialConditionForFilter
                          //  Referenced by: '<S529>/Filter'

  real_T PID_vz_InitialConditionForFilter;
                             // Mask Parameter: PID_vz_InitialConditionForFilter
                                //  Referenced by: '<S581>/Filter'

  real_T PIDController_InitialConditionForIntegrator;
                  // Mask Parameter: PIDController_InitialConditionForIntegrator
                     //  Referenced by: '<S119>/Integrator'

  real_T PIDController1_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController1_InitialConditionForIntegrator
                    //  Referenced by: '<S171>/Integrator'

  real_T PIDController2_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController2_InitialConditionForIntegrator
                    //  Referenced by: '<S223>/Integrator'

  real_T PID_Altitude_InitialConditionForIntegrator;
                   // Mask Parameter: PID_Altitude_InitialConditionForIntegrator
                      //  Referenced by: '<S534>/Integrator'

  real_T PID_vz_InitialConditionForIntegrator;
                         // Mask Parameter: PID_vz_InitialConditionForIntegrator
                            //  Referenced by: '<S586>/Integrator'

  real_T PIDController_LowerSaturationLimit;
                           // Mask Parameter: PIDController_LowerSaturationLimit
                              //  Referenced by:
                              //    '<S126>/Saturation'
                              //    '<S111>/DeadZone'

  real_T PIDController1_LowerSaturationLimit;
                          // Mask Parameter: PIDController1_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S178>/Saturation'
                             //    '<S163>/DeadZone'

  real_T PIDController2_LowerSaturationLimit;
                          // Mask Parameter: PIDController2_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S230>/Saturation'
                             //    '<S215>/DeadZone'

  real_T PIDController1_LowerSaturationLimit_h;
                        // Mask Parameter: PIDController1_LowerSaturationLimit_h
                           //  Referenced by: '<S439>/Saturation'

  real_T PIDController_LowerSaturationLimit_o;
                         // Mask Parameter: PIDController_LowerSaturationLimit_o
                            //  Referenced by: '<S389>/Saturation'

  real_T PIDController5_LowerSaturationLimit;
                          // Mask Parameter: PIDController5_LowerSaturationLimit
                             //  Referenced by: '<S489>/Saturation'

  real_T PID_Altitude_LowerSaturationLimit;
                            // Mask Parameter: PID_Altitude_LowerSaturationLimit
                               //  Referenced by:
                               //    '<S541>/Saturation'
                               //    '<S526>/DeadZone'

  real_T PID_vz_LowerSaturationLimit;
                                  // Mask Parameter: PID_vz_LowerSaturationLimit
                                     //  Referenced by:
                                     //    '<S593>/Saturation'
                                     //    '<S578>/DeadZone'

  real_T PIDController_N;              // Mask Parameter: PIDController_N
                                          //  Referenced by: '<S122>/Filter Coefficient'

  real_T PIDController1_N;             // Mask Parameter: PIDController1_N
                                          //  Referenced by: '<S174>/Filter Coefficient'

  real_T PIDController2_N;             // Mask Parameter: PIDController2_N
                                          //  Referenced by: '<S226>/Filter Coefficient'

  real_T PID_Altitude_N;               // Mask Parameter: PID_Altitude_N
                                          //  Referenced by: '<S537>/Filter Coefficient'

  real_T PID_vz_N;                     // Mask Parameter: PID_vz_N
                                          //  Referenced by: '<S589>/Filter Coefficient'

  real_T PIDController_P;              // Mask Parameter: PIDController_P
                                          //  Referenced by: '<S124>/Proportional Gain'

  real_T PIDController3_P;             // Mask Parameter: PIDController3_P
                                          //  Referenced by: '<S278>/Proportional Gain'

  real_T PIDController1_P;             // Mask Parameter: PIDController1_P
                                          //  Referenced by: '<S176>/Proportional Gain'

  real_T PIDController4_P;             // Mask Parameter: PIDController4_P
                                          //  Referenced by: '<S328>/Proportional Gain'

  real_T PIDController2_P;             // Mask Parameter: PIDController2_P
                                          //  Referenced by: '<S228>/Proportional Gain'

  real_T PIDController1_P_f;           // Mask Parameter: PIDController1_P_f
                                          //  Referenced by: '<S437>/Proportional Gain'

  real_T PIDController_P_b;            // Mask Parameter: PIDController_P_b
                                          //  Referenced by: '<S387>/Proportional Gain'

  real_T PIDController5_P;             // Mask Parameter: PIDController5_P
                                          //  Referenced by: '<S487>/Proportional Gain'

  real_T PID_Altitude_P;               // Mask Parameter: PID_Altitude_P
                                          //  Referenced by: '<S539>/Proportional Gain'

  real_T PID_vz_P;                     // Mask Parameter: PID_vz_P
                                          //  Referenced by: '<S591>/Proportional Gain'

  real_T PIDController_UpperSaturationLimit;
                           // Mask Parameter: PIDController_UpperSaturationLimit
                              //  Referenced by:
                              //    '<S126>/Saturation'
                              //    '<S111>/DeadZone'

  real_T PIDController1_UpperSaturationLimit;
                          // Mask Parameter: PIDController1_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S178>/Saturation'
                             //    '<S163>/DeadZone'

  real_T PIDController2_UpperSaturationLimit;
                          // Mask Parameter: PIDController2_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S230>/Saturation'
                             //    '<S215>/DeadZone'

  real_T PIDController1_UpperSaturationLimit_e;
                        // Mask Parameter: PIDController1_UpperSaturationLimit_e
                           //  Referenced by: '<S439>/Saturation'

  real_T PIDController_UpperSaturationLimit_e;
                         // Mask Parameter: PIDController_UpperSaturationLimit_e
                            //  Referenced by: '<S389>/Saturation'

  real_T PIDController5_UpperSaturationLimit;
                          // Mask Parameter: PIDController5_UpperSaturationLimit
                             //  Referenced by: '<S489>/Saturation'

  real_T PID_Altitude_UpperSaturationLimit;
                            // Mask Parameter: PID_Altitude_UpperSaturationLimit
                               //  Referenced by:
                               //    '<S541>/Saturation'
                               //    '<S526>/DeadZone'

  real_T PID_vz_UpperSaturationLimit;
                                  // Mask Parameter: PID_vz_UpperSaturationLimit
                                     //  Referenced by:
                                     //    '<S593>/Saturation'
                                     //    '<S578>/DeadZone'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S60>/Constant'

  uint16_T CompareToConstant_const_d;
                                    // Mask Parameter: CompareToConstant_const_d
                                       //  Referenced by: '<S61>/Constant'

  uint8_T CompareToConstant_const_dt;
                                   // Mask Parameter: CompareToConstant_const_dt
                                      //  Referenced by: '<S34>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Out1_Y0;// Computed Parameter: Out1_Y0
                                                 //  Referenced by: '<S41>/Out1'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value;// Computed Parameter: Constant_Value
                                                        //  Referenced by: '<S46>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                          //  Referenced by: '<S40>/Constant'

  px4_Bus_position_setpoint_triplet Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                 //  Referenced by: '<S53>/Out1'

  px4_Bus_position_setpoint_triplet Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                        //  Referenced by: '<S38>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                              //  Referenced by: '<S15>/Out1'

  px4_Bus_vehicle_local_position Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                     //  Referenced by: '<S9>/Constant'

  px4_Bus_actuator_motors Constant_Value_f;// Computed Parameter: Constant_Value_f
                                              //  Referenced by: '<S71>/Constant'

  px4_Bus_input_rc Out1_Y0_m;          // Computed Parameter: Out1_Y0_m
                                          //  Referenced by: '<S13>/Out1'

  px4_Bus_input_rc Out1_Y0_j;          // Computed Parameter: Out1_Y0_j
                                          //  Referenced by: '<S70>/Out1'

  px4_Bus_input_rc Constant_Value_m;   // Computed Parameter: Constant_Value_m
                                          //  Referenced by: '<S69>/Constant'

  px4_Bus_input_rc Constant_Value_o;   // Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S12>/Constant'

  px4_Bus_vehicle_attitude Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S14>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_l;// Computed Parameter: Constant_Value_l
                                               //  Referenced by: '<S8>/Constant'

  px4_Bus_home_position Out1_Y0_o;     // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S52>/Out1'

  px4_Bus_home_position Constant_Value_b;// Computed Parameter: Constant_Value_b
                                            //  Referenced by: '<S37>/Constant'

  px4_Bus_vehicle_angular_velocity Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                //  Referenced by: '<S10>/Out1'

  px4_Bus_vehicle_angular_velocity Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                       //  Referenced by: '<S5>/Constant'

  px4_Bus_actuator_armed Out1_Y0_d;    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S11>/Out1'

  px4_Bus_actuator_armed Out1_Y0_l;    // Computed Parameter: Out1_Y0_l
                                          //  Referenced by: '<S68>/Out1'

  px4_Bus_actuator_armed Constant_Value_j;// Computed Parameter: Constant_Value_j
                                             //  Referenced by: '<S6>/Constant'

  px4_Bus_actuator_armed Constant_Value_k;// Computed Parameter: Constant_Value_k
                                             //  Referenced by: '<S57>/Constant'

  real_T yaw_Out_Y0;                   // Computed Parameter: yaw_Out_Y0
                                          //  Referenced by: '<S32>/yaw_Out'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay'

  real_T Rate_Value;                   // Expression: 0.01
                                          //  Referenced by: '<S30>/Rate'

  real_T Gain1_Gain;                   // Expression: -1
                                          //  Referenced by: '<S30>/Gain1'

  real_T Gain_Gain;                    // Expression: -1
                                          //  Referenced by: '<S30>/Gain'

  real_T Delay_InitialCondition_g;     // Expression: 1
                                          //  Referenced by: '<S31>/Delay'

  real_T Constant_Value_fo;            // Expression: 0
                                          //  Referenced by: '<S31>/Constant'

  real_T Out_Y0;                       // Computed Parameter: Out_Y0
                                          //  Referenced by: '<S28>/Out'

  real_T Gain_Gain_l;                  // Expression: -1
                                          //  Referenced by: '<S26>/Gain'

  real_T yaw_Out_Y0_f;                 // Computed Parameter: yaw_Out_Y0_f
                                          //  Referenced by: '<S29>/yaw_Out'

  real_T Delay_InitialCondition_n;     // Expression: 0.0
                                          //  Referenced by: '<S21>/Delay'

  real_T Delay_InitialCondition_m;     // Expression: 0.0
                                          //  Referenced by: '<S26>/Delay'

  real_T Switch_Threshold;             // Expression: 0
                                          //  Referenced by: '<S26>/Switch'

  real_T Rateofdescent_Value;          // Expression: 0.02
                                          //  Referenced by: '<S26>/Rate of descent'

  real_T Gain2_Gain;                   // Expression: -1
                                          //  Referenced by: '<S26>/Gain2'

  real_T Gain1_Gain_a;                 // Expression: -1
                                          //  Referenced by: '<S26>/Gain1'

  real_T Delay_InitialCondition_j;     // Expression: 1
                                          //  Referenced by: '<S27>/Delay'

  real_T Constant_Value_nn;            // Expression: 0
                                          //  Referenced by: '<S27>/Constant'

  real_T Constant_Value_jd;            // Expression: 0
                                          //  Referenced by: '<S33>/Constant'

  real_T Constant_Value_gw;            // Expression: 6
                                          //  Referenced by: '<S23>/Constant'

  real_T yaw_Out_Y0_p;                 // Computed Parameter: yaw_Out_Y0_p
                                          //  Referenced by: '<S25>/yaw_Out'

  real_T Delay_InitialCondition_g0;    // Expression: 1
                                          //  Referenced by: '<S24>/Delay'

  real_T Constant_Value_i;             // Expression: 0
                                          //  Referenced by: '<S24>/Constant'

  real_T ReadParameter_SampleTime;     // Expression: -1
                                          //  Referenced by: '<S19>/Read Parameter'

  real_T ReadParameter_SampleTime_c;   // Expression: -1
                                          //  Referenced by: '<S51>/Read Parameter'

  real_T ReadParameter_SampleTime_g;   // Expression: -1
                                          //  Referenced by: '<S50>/Read Parameter'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S54>/Constant1'

  real_T Constant1_Value_g;            // Expression: 100
                                          //  Referenced by: '<S55>/Constant1'

  real_T Gain_Gain_m;                  // Expression: 0.01
                                          //  Referenced by: '<S63>/Gain'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<S63>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S63>/Saturation'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S54>/Constant2'

  real_T Constant2_Value_p;            // Expression: 100
                                          //  Referenced by: '<S55>/Constant2'

  real_T Gain_Gain_k;                  // Expression: 0.01
                                          //  Referenced by: '<S64>/Gain'

  real_T Saturation_UpperSat_c;        // Expression: 1
                                          //  Referenced by: '<S64>/Saturation'

  real_T Saturation_LowerSat_p;        // Expression: 0
                                          //  Referenced by: '<S64>/Saturation'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<S54>/Constant3'

  real_T Constant3_Value_o;            // Expression: 100
                                          //  Referenced by: '<S55>/Constant3'

  real_T Gain_Gain_lf;                 // Expression: 0.01
                                          //  Referenced by: '<S65>/Gain'

  real_T Saturation_UpperSat_f;        // Expression: 1
                                          //  Referenced by: '<S65>/Saturation'

  real_T Saturation_LowerSat_c;        // Expression: 0
                                          //  Referenced by: '<S65>/Saturation'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<S54>/Constant4'

  real_T Constant4_Value_h;            // Expression: 100
                                          //  Referenced by: '<S55>/Constant4'

  real_T Gain_Gain_mp;                 // Expression: 0.01
                                          //  Referenced by: '<S66>/Gain'

  real_T Saturation_UpperSat_o;        // Expression: 1
                                          //  Referenced by: '<S66>/Saturation'

  real_T Saturation_LowerSat_a;        // Expression: 0
                                          //  Referenced by: '<S66>/Saturation'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<S54>/Constant5'

  real_T Constant5_Value_e;            // Expression: 100
                                          //  Referenced by: '<S55>/Constant5'

  real_T Gain_Gain_g;                  // Expression: 0.01
                                          //  Referenced by: '<S67>/Gain'

  real_T Saturation_UpperSat_fq;       // Expression: 1
                                          //  Referenced by: '<S67>/Saturation'

  real_T Saturation_LowerSat_e;        // Expression: 0
                                          //  Referenced by: '<S67>/Saturation'

  real_T Constant_Value_bd;            // Expression: 0
                                          //  Referenced by: '<S54>/Constant'

  real_T Constant_Value_a;             // Expression: 100
                                          //  Referenced by: '<S55>/Constant'

  real_T Gain_Gain_mg;                 // Expression: 0.01
                                          //  Referenced by: '<S62>/Gain'

  real_T Saturation_UpperSat_j;        // Expression: 1
                                          //  Referenced by: '<S62>/Saturation'

  real_T Saturation_LowerSat_av;       // Expression: 0
                                          //  Referenced by: '<S62>/Saturation'

  real_T ReadParameter1_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S55>/Read Parameter1'

  real_T ReadParameter13_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S55>/Read Parameter13'

  real_T ReadParameter2_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S55>/Read Parameter2'

  real_T ReadParameter3_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S55>/Read Parameter3'

  real_T ReadParameter4_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S55>/Read Parameter4'

  real_T ReadParameter5_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S55>/Read Parameter5'

  real_T tau_Yaw_Y0;                   // Computed Parameter: tau_Yaw_Y0
                                          //  Referenced by: '<S73>/tau_Yaw'

  real_T tau_Pitch_Y0;                 // Computed Parameter: tau_Pitch_Y0
                                          //  Referenced by: '<S73>/tau_Pitch'

  real_T tau_Roll_Y0;                  // Computed Parameter: tau_Roll_Y0
                                          //  Referenced by: '<S73>/tau_Roll'

  real_T Constant1_Value_k;            // Expression: 0
                                          //  Referenced by: '<S109>/Constant1'

  real_T Constant1_Value_o;            // Expression: 0
                                          //  Referenced by: '<S161>/Constant1'

  real_T Constant1_Value_p;            // Expression: 0
                                          //  Referenced by: '<S213>/Constant1'

  real_T Clamping_zero_Value;          // Expression: 0
                                          //  Referenced by: '<S109>/Clamping_zero'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S119>/Integrator'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S114>/Filter'

  real_T RateLimiter2_RisingLim;       // Expression: 40*pi/180
                                          //  Referenced by: '<S73>/Rate Limiter2'

  real_T RateLimiter2_FallingLim;      // Expression: -40*pi/180
                                          //  Referenced by: '<S73>/Rate Limiter2'

  real_T RateLimiter2_IC;              // Expression: 0
                                          //  Referenced by: '<S73>/Rate Limiter2'

  real_T Saturation1_UpperSat;         // Expression: 20*pi/180
                                          //  Referenced by: '<S73>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -20*pi/180
                                          //  Referenced by: '<S73>/Saturation1'

  real_T Clamping_zero_Value_b;        // Expression: 0
                                          //  Referenced by: '<S161>/Clamping_zero'

  real_T Integrator_gainval_i;       // Computed Parameter: Integrator_gainval_i
                                        //  Referenced by: '<S171>/Integrator'

  real_T Filter_gainval_p;             // Computed Parameter: Filter_gainval_p
                                          //  Referenced by: '<S166>/Filter'

  real_T RateLimiter1_RisingLim;       // Expression: 40*pi/180
                                          //  Referenced by: '<S73>/Rate Limiter1'

  real_T RateLimiter1_FallingLim;      // Expression: -40*pi/180
                                          //  Referenced by: '<S73>/Rate Limiter1'

  real_T RateLimiter1_IC;              // Expression: 0
                                          //  Referenced by: '<S73>/Rate Limiter1'

  real_T Saturation_UpperSat_m;        // Expression: 20*pi/180
                                          //  Referenced by: '<S73>/Saturation'

  real_T Saturation_LowerSat_l;        // Expression: -20*pi/180
                                          //  Referenced by: '<S73>/Saturation'

  real_T Clamping_zero_Value_f;        // Expression: 0
                                          //  Referenced by: '<S213>/Clamping_zero'

  real_T Integrator_gainval_p;       // Computed Parameter: Integrator_gainval_p
                                        //  Referenced by: '<S223>/Integrator'

  real_T Filter_gainval_k;             // Computed Parameter: Filter_gainval_k
                                          //  Referenced by: '<S218>/Filter'

  real_T Constant_Value_ag;            // Expression: 0
                                          //  Referenced by: '<S340>/Constant'

  real_T Switch1_Threshold;            // Expression: 0
                                          //  Referenced by: '<S342>/Switch1'

  real_T des_pitch_Y0;                 // Computed Parameter: des_pitch_Y0
                                          //  Referenced by: '<S76>/des_pitch'

  real_T des_roll_Y0;                  // Computed Parameter: des_roll_Y0
                                          //  Referenced by: '<S76>/des_roll'

  real_T des_yawrate_Y0;               // Computed Parameter: des_yawrate_Y0
                                          //  Referenced by: '<S76>/des_yawrate'

  real_T tau_Thrust_Y0;                // Computed Parameter: tau_Thrust_Y0
                                          //  Referenced by: '<S76>/tau_Thrust'

  real_T Constant1_Value_c;            // Expression: 0
                                          //  Referenced by: '<S524>/Constant1'

  real_T Constant1_Value_f;            // Expression: 0
                                          //  Referenced by: '<S576>/Constant1'

  real_T Gain_Gain_a;                  // Expression: -1
                                          //  Referenced by: '<S341>/Gain'

  real_T Constant_Value_p;             // Expression: 2*pi
                                          //  Referenced by: '<S342>/Constant'

  real_T Switch_Threshold_p;           // Expression: pi
                                          //  Referenced by: '<S342>/Switch'

  real_T Gain1_Gain_ad;                // Expression: -1
                                          //  Referenced by: '<S76>/Gain1'

  real_T Gain1_Gain_j;                 // Expression: -1
                                          //  Referenced by: '<S340>/Gain1'

  real_T Clamping_zero_Value_o;        // Expression: 0
                                          //  Referenced by: '<S524>/Clamping_zero'

  real_T Filter_gainval_i;             // Computed Parameter: Filter_gainval_i
                                          //  Referenced by: '<S529>/Filter'

  real_T Integrator_gainval_p4;     // Computed Parameter: Integrator_gainval_p4
                                       //  Referenced by: '<S534>/Integrator'

  real_T Clamping_zero_Value_bl;       // Expression: 0
                                          //  Referenced by: '<S576>/Clamping_zero'

  real_T Filter_gainval_d;             // Computed Parameter: Filter_gainval_d
                                          //  Referenced by: '<S581>/Filter'

  real_T Integrator_gainval_ik;     // Computed Parameter: Integrator_gainval_ik
                                       //  Referenced by: '<S586>/Integrator'

  real_T Constant_Value_pp[4];         // Expression: [1 0 0 0]
                                          //  Referenced by: '<S77>/Constant'

  real_T Constant_Value_c;             // Expression: 1
                                          //  Referenced by: '<S607>/Constant'

  real_T Constant_Value_md;            // Expression: 1
                                          //  Referenced by: '<S608>/Constant'

  real_T Switch_Threshold_o;           // Expression: 0
                                          //  Referenced by: '<S77>/Switch'

  real_T Constant2_Value_g;            // Expression: 1500
                                          //  Referenced by: '<S75>/Constant2'

  real_T Gain2_Gain_d;                 // Expression: 1/400
                                          //  Referenced by: '<S75>/Gain2'

  real_T Saturation2_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S75>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S75>/Saturation2'

  real_T Gain1_Gain_h;                 // Expression: -20*pi/180
                                          //  Referenced by: '<S4>/Gain1'

  real_T Constant1_Value_h;            // Expression: 1500
                                          //  Referenced by: '<S75>/Constant1'

  real_T Gain1_Gain_e;                 // Expression: 1/400
                                          //  Referenced by: '<S75>/Gain1'

  real_T Saturation1_UpperSat_p;       // Expression: 1
                                          //  Referenced by: '<S75>/Saturation1'

  real_T Saturation1_LowerSat_j;       // Expression: -1
                                          //  Referenced by: '<S75>/Saturation1'

  real_T Gain2_Gain_m;                 // Expression: 20*pi/180
                                          //  Referenced by: '<S4>/Gain2'

  real_T Constant_Value_ol;            // Expression: 1100
                                          //  Referenced by: '<S75>/Constant'

  real_T Gain_Gain_e;                  // Expression: 1/800
                                          //  Referenced by: '<S75>/Gain'

  real_T Saturation_UpperSat_ji;       // Expression: 0.90
                                          //  Referenced by: '<S75>/Saturation'

  real_T Saturation_LowerSat_l4;       // Expression: 0
                                          //  Referenced by: '<S75>/Saturation'

  real_T Constant3_Value_n;            // Expression: 1500
                                          //  Referenced by: '<S75>/Constant3'

  real_T Gain3_Gain;                   // Expression: 1/400
                                          //  Referenced by: '<S75>/Gain3'

  real_T Saturation3_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S75>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S75>/Saturation3'

  real_T Gain4_Gain;                   // Expression: 50*pi/180
                                          //  Referenced by: '<S4>/Gain4'

  real_T Gain_Gain_k1;                 // Expression: -1
                                          //  Referenced by: '<S4>/Gain'

  real_T Gain_Gain_kw;                 // Expression: 5
                                          //  Referenced by: '<S3>/Gain'

  real_T Gain1_Gain_b;                 // Expression: 5
                                          //  Referenced by: '<S3>/Gain1'

  real_T Gain2_Gain_du;                // Expression: 10
                                          //  Referenced by: '<S3>/Gain2'

  real_T Gain3_Gain_o;                 // Expression: 1
                                          //  Referenced by: '<S3>/Gain3'

  real_T Constant_Value_olz;           // Expression: 0
                                          //  Referenced by: '<S59>/Constant'

  uint64_T Constant7_Value;            // Computed Parameter: Constant7_Value
                                          //  Referenced by: '<S44>/Constant7'

  real32_T Constant1_Value_d[2];       // Computed Parameter: Constant1_Value_d
                                          //  Referenced by: '<S51>/Constant1'

  real32_T Constant_Value_f2;          // Computed Parameter: Constant_Value_f2
                                          //  Referenced by: '<S51>/Constant'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S50>/Gain'

  real32_T Constant1_Value_k4[2];      // Computed Parameter: Constant1_Value_k4
                                          //  Referenced by: '<S50>/Constant1'

  real32_T Constant_Value_l4;          // Computed Parameter: Constant_Value_l4
                                          //  Referenced by: '<S50>/Constant'

  real32_T Constant_Value_fh[3];       // Computed Parameter: Constant_Value_fh
                                          //  Referenced by: '<S44>/Constant'

  real32_T Constant1_Value_hv[3];      // Computed Parameter: Constant1_Value_hv
                                          //  Referenced by: '<S44>/Constant1'

  real32_T Constant2_Value_f[3];       // Computed Parameter: Constant2_Value_f
                                          //  Referenced by: '<S44>/Constant2'

  real32_T Constant3_Value_a;          // Computed Parameter: Constant3_Value_a
                                          //  Referenced by: '<S44>/Constant3'

  real32_T Constant4_Value_g;          // Computed Parameter: Constant4_Value_g
                                          //  Referenced by: '<S44>/Constant4'

  boolean_T Constant5_Value_j;         // Computed Parameter: Constant5_Value_j
                                          //  Referenced by: '<S42>/Constant5'

  boolean_T Constant5_Value_k;         // Computed Parameter: Constant5_Value_k
                                          //  Referenced by: '<S43>/Constant5'

  boolean_T Constant1_Value_dl;        // Computed Parameter: Constant1_Value_dl
                                          //  Referenced by: '<S45>/Constant1'

  boolean_T Constant5_Value_h;         // Computed Parameter: Constant5_Value_h
                                          //  Referenced by: '<S45>/Constant5'

  boolean_T Constant5_Value_l;         // Computed Parameter: Constant5_Value_l
                                          //  Referenced by: '<S44>/Constant5'

  int8_T Constant_Value_ge;            // Computed Parameter: Constant_Value_ge
                                          //  Referenced by: '<S109>/Constant'

  int8_T Constant2_Value_i;            // Computed Parameter: Constant2_Value_i
                                          //  Referenced by: '<S109>/Constant2'

  int8_T Constant3_Value_h;            // Computed Parameter: Constant3_Value_h
                                          //  Referenced by: '<S109>/Constant3'

  int8_T Constant4_Value_f;            // Computed Parameter: Constant4_Value_f
                                          //  Referenced by: '<S109>/Constant4'

  int8_T Constant_Value_a1;            // Computed Parameter: Constant_Value_a1
                                          //  Referenced by: '<S161>/Constant'

  int8_T Constant2_Value_l;            // Computed Parameter: Constant2_Value_l
                                          //  Referenced by: '<S161>/Constant2'

  int8_T Constant3_Value_j;            // Computed Parameter: Constant3_Value_j
                                          //  Referenced by: '<S161>/Constant3'

  int8_T Constant4_Value_a;            // Computed Parameter: Constant4_Value_a
                                          //  Referenced by: '<S161>/Constant4'

  int8_T Constant_Value_jj;            // Computed Parameter: Constant_Value_jj
                                          //  Referenced by: '<S213>/Constant'

  int8_T Constant2_Value_o;            // Computed Parameter: Constant2_Value_o
                                          //  Referenced by: '<S213>/Constant2'

  int8_T Constant3_Value_l;            // Computed Parameter: Constant3_Value_l
                                          //  Referenced by: '<S213>/Constant3'

  int8_T Constant4_Value_n;            // Computed Parameter: Constant4_Value_n
                                          //  Referenced by: '<S213>/Constant4'

  int8_T Constant_Value_n1;            // Computed Parameter: Constant_Value_n1
                                          //  Referenced by: '<S524>/Constant'

  int8_T Constant2_Value_gq;           // Computed Parameter: Constant2_Value_gq
                                          //  Referenced by: '<S524>/Constant2'

  int8_T Constant3_Value_i;            // Computed Parameter: Constant3_Value_i
                                          //  Referenced by: '<S524>/Constant3'

  int8_T Constant4_Value_hf;           // Computed Parameter: Constant4_Value_hf
                                          //  Referenced by: '<S524>/Constant4'

  int8_T Constant_Value_gf;            // Computed Parameter: Constant_Value_gf
                                          //  Referenced by: '<S576>/Constant'

  int8_T Constant2_Value_ga;           // Computed Parameter: Constant2_Value_ga
                                          //  Referenced by: '<S576>/Constant2'

  int8_T Constant3_Value_b;            // Computed Parameter: Constant3_Value_b
                                          //  Referenced by: '<S576>/Constant3'

  int8_T Constant4_Value_fv;           // Computed Parameter: Constant4_Value_fv
                                          //  Referenced by: '<S576>/Constant4'

  uint8_T Constant_Value_fm;           // Computed Parameter: Constant_Value_fm
                                          //  Referenced by: '<S36>/Constant'

  uint8_T Constant6_Value;             // Computed Parameter: Constant6_Value
                                          //  Referenced by: '<S44>/Constant6'

};

// Real-time Model Data Structure
struct tag_RTM_FLIGHT_HEXA_Hovering_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_FLIGHT_HEXA_Hovering_T FLIGHT_HEXA_Hovering_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_FLIGHT_HEXA_Hovering_T FLIGHT_HEXA_Hovering_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_FLIGHT_HEXA_Hovering_T FLIGHT_HEXA_Hovering_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void FLIGHT_HEXA_Hovering_initialize(void);
  extern void FLIGHT_HEXA_Hovering_step(void);
  extern void FLIGHT_HEXA_Hovering_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_FLIGHT_HEXA_Hovering_T *const FLIGHT_HEXA_Hovering_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S5>/NOT' : Unused code path elimination
//  Block '<S6>/NOT' : Unused code path elimination
//  Block '<S7>/Bitwise Operator' : Unused code path elimination
//  Block '<S7>/Data Type Conversion' : Unused code path elimination
//  Block '<S7>/Data Type Conversion1' : Unused code path elimination
//  Block '<S7>/Data Type Conversion2' : Unused code path elimination
//  Block '<S7>/Gain' : Unused code path elimination
//  Block '<S7>/Gain1' : Unused code path elimination
//  Block '<S12>/NOT' : Unused code path elimination
//  Block '<S8>/NOT' : Unused code path elimination
//  Block '<S9>/NOT' : Unused code path elimination
//  Block '<S39>/Compare' : Unused code path elimination
//  Block '<S39>/Constant' : Unused code path elimination
//  Block '<S40>/NOT' : Unused code path elimination
//  Block '<S35>/Subtract' : Unused code path elimination
//  Block '<S37>/NOT' : Unused code path elimination
//  Block '<S38>/NOT' : Unused code path elimination
//  Block '<S57>/NOT' : Unused code path elimination
//  Block '<S58>/Bitwise Operator' : Unused code path elimination
//  Block '<S58>/Data Type Conversion' : Unused code path elimination
//  Block '<S58>/Data Type Conversion1' : Unused code path elimination
//  Block '<S58>/Data Type Conversion2' : Unused code path elimination
//  Block '<S58>/Gain' : Unused code path elimination
//  Block '<S58>/Gain1' : Unused code path elimination
//  Block '<S69>/NOT' : Unused code path elimination
//  Block '<S348>/Data Type Duplicate' : Unused code path elimination
//  Block '<S348>/Data Type Propagation' : Unused code path elimination
//  Block '<S21>/Reshape1' : Reshape block reduction
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
//  '<Root>' : 'FLIGHT_HEXA_Hovering'
//  '<S1>'   : 'FLIGHT_HEXA_Hovering/Estimator Output'
//  '<S2>'   : 'FLIGHT_HEXA_Hovering/Navigation'
//  '<S3>'   : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors'
//  '<S4>'   : 'FLIGHT_HEXA_Hovering/Subsystem Reference'
//  '<S5>'   : 'FLIGHT_HEXA_Hovering/Estimator Output/PX4 uORB Read1'
//  '<S6>'   : 'FLIGHT_HEXA_Hovering/Estimator Output/PX4 uORB Read2'
//  '<S7>'   : 'FLIGHT_HEXA_Hovering/Estimator Output/Radio Control Transmitter'
//  '<S8>'   : 'FLIGHT_HEXA_Hovering/Estimator Output/vehicle_attitude'
//  '<S9>'   : 'FLIGHT_HEXA_Hovering/Estimator Output/vehicle_local_pos'
//  '<S10>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/PX4 uORB Read1/Enabled Subsystem'
//  '<S11>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/PX4 uORB Read2/Enabled Subsystem'
//  '<S12>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/Radio Control Transmitter/PX4 uORB Read'
//  '<S13>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S14>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/vehicle_attitude/Enabled Subsystem'
//  '<S15>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/vehicle_local_pos/Enabled Subsystem'
//  '<S16>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm'
//  '<S17>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission'
//  '<S18>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem'
//  '<S19>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC'
//  '<S20>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE'
//  '<S21>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land'
//  '<S22>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off'
//  '<S23>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint'
//  '<S24>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE'
//  '<S25>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE/Enabled Subsystem2'
//  '<S26>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land'
//  '<S27>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land'
//  '<S28>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land/Enabled Subsystem'
//  '<S29>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land/Enabled Subsystem2'
//  '<S30>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Ensure smooth ascend during Takeoff'
//  '<S31>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff'
//  '<S32>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff/Enabled Subsystem2'
//  '<S33>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning'
//  '<S34>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning/Compare To Constant'
//  '<S35>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC'
//  '<S36>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC'
//  '<S37>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead'
//  '<S38>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead'
//  '<S39>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/Compare To Constant'
//  '<S40>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read'
//  '<S41>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read/Enabled Subsystem'
//  '<S42>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint'
//  '<S43>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_WayPoint'
//  '<S44>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Empty_WayPoint'
//  '<S45>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Next_WayPoint'
//  '<S46>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Message'
//  '<S47>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Write'
//  '<S48>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP'
//  '<S49>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem'
//  '<S50>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem1'
//  '<S51>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem2'
//  '<S52>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead/Enabled Subsystem'
//  '<S53>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead/Enabled Subsystem'
//  '<S54>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/Emergency Kill'
//  '<S55>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/Fault_Injection'
//  '<S56>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/MATLAB Function'
//  '<S57>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/PX4 uORB Read2'
//  '<S58>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/Radio Control Transmitter'
//  '<S59>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/Subsystem'
//  '<S60>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/Emergency Kill/Compare To Constant'
//  '<S61>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/Fault_Injection/Compare To Constant'
//  '<S62>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/Fault_Injection/Subsystem Reference'
//  '<S63>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/Fault_Injection/Subsystem Reference1'
//  '<S64>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/Fault_Injection/Subsystem Reference2'
//  '<S65>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/Fault_Injection/Subsystem Reference3'
//  '<S66>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/Fault_Injection/Subsystem Reference4'
//  '<S67>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/Fault_Injection/Subsystem Reference5'
//  '<S68>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/PX4 uORB Read2/Enabled Subsystem'
//  '<S69>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/Radio Control Transmitter/PX4 uORB Read'
//  '<S70>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S71>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/Subsystem/PX4 uORB Message'
//  '<S72>'  : 'FLIGHT_HEXA_Hovering/Publish ActuatorMotors/Subsystem/PX4 uORB Write'
//  '<S73>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller'
//  '<S74>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Chart'
//  '<S75>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/PWM2CMD'
//  '<S76>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller'
//  '<S77>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Quaternion Validity Check'
//  '<S78>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles'
//  '<S79>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller'
//  '<S80>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1'
//  '<S81>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2'
//  '<S82>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3'
//  '<S83>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4'
//  '<S84>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Anti-windup'
//  '<S85>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/D Gain'
//  '<S86>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/External Derivative'
//  '<S87>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Filter'
//  '<S88>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Filter ICs'
//  '<S89>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/I Gain'
//  '<S90>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Ideal P Gain'
//  '<S91>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Ideal P Gain Fdbk'
//  '<S92>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Integrator'
//  '<S93>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Integrator ICs'
//  '<S94>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/N Copy'
//  '<S95>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/N Gain'
//  '<S96>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/P Copy'
//  '<S97>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Parallel P Gain'
//  '<S98>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Reset Signal'
//  '<S99>'  : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Saturation'
//  '<S100>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Saturation Fdbk'
//  '<S101>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Sum'
//  '<S102>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Sum Fdbk'
//  '<S103>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Tracking Mode'
//  '<S104>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Tracking Mode Sum'
//  '<S105>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Tsamp - Integral'
//  '<S106>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Tsamp - Ngain'
//  '<S107>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/postSat Signal'
//  '<S108>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/preSat Signal'
//  '<S109>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S110>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S111>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S112>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/D Gain/Internal Parameters'
//  '<S113>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/External Derivative/Error'
//  '<S114>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S115>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S116>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/I Gain/Internal Parameters'
//  '<S117>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S118>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S119>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Integrator/Discrete'
//  '<S120>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Integrator ICs/Internal IC'
//  '<S121>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/N Copy/Disabled'
//  '<S122>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/N Gain/Internal Parameters'
//  '<S123>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/P Copy/Disabled'
//  '<S124>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S125>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Reset Signal/Disabled'
//  '<S126>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Saturation/Enabled'
//  '<S127>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S128>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Sum/Sum_PID'
//  '<S129>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Sum Fdbk/Disabled'
//  '<S130>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Tracking Mode/Disabled'
//  '<S131>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S132>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S133>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S134>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/postSat Signal/Forward_Path'
//  '<S135>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller/preSat Signal/Forward_Path'
//  '<S136>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Anti-windup'
//  '<S137>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/D Gain'
//  '<S138>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/External Derivative'
//  '<S139>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Filter'
//  '<S140>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Filter ICs'
//  '<S141>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/I Gain'
//  '<S142>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Ideal P Gain'
//  '<S143>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S144>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Integrator'
//  '<S145>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Integrator ICs'
//  '<S146>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/N Copy'
//  '<S147>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/N Gain'
//  '<S148>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/P Copy'
//  '<S149>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Parallel P Gain'
//  '<S150>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Reset Signal'
//  '<S151>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Saturation'
//  '<S152>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Saturation Fdbk'
//  '<S153>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Sum'
//  '<S154>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Sum Fdbk'
//  '<S155>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Tracking Mode'
//  '<S156>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Tracking Mode Sum'
//  '<S157>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Tsamp - Integral'
//  '<S158>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Tsamp - Ngain'
//  '<S159>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/postSat Signal'
//  '<S160>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/preSat Signal'
//  '<S161>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S162>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S163>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S164>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/D Gain/Internal Parameters'
//  '<S165>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/External Derivative/Error'
//  '<S166>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S167>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S168>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/I Gain/Internal Parameters'
//  '<S169>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S170>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S171>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Integrator/Discrete'
//  '<S172>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Integrator ICs/Internal IC'
//  '<S173>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/N Copy/Disabled'
//  '<S174>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/N Gain/Internal Parameters'
//  '<S175>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/P Copy/Disabled'
//  '<S176>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S177>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Reset Signal/Disabled'
//  '<S178>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Saturation/Enabled'
//  '<S179>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S180>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Sum/Sum_PID'
//  '<S181>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S182>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Tracking Mode/Disabled'
//  '<S183>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S184>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S185>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S186>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S187>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S188>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Anti-windup'
//  '<S189>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/D Gain'
//  '<S190>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/External Derivative'
//  '<S191>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Filter'
//  '<S192>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Filter ICs'
//  '<S193>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/I Gain'
//  '<S194>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Ideal P Gain'
//  '<S195>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Ideal P Gain Fdbk'
//  '<S196>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Integrator'
//  '<S197>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Integrator ICs'
//  '<S198>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/N Copy'
//  '<S199>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/N Gain'
//  '<S200>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/P Copy'
//  '<S201>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Parallel P Gain'
//  '<S202>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Reset Signal'
//  '<S203>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Saturation'
//  '<S204>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Saturation Fdbk'
//  '<S205>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Sum'
//  '<S206>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Sum Fdbk'
//  '<S207>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Tracking Mode'
//  '<S208>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Tracking Mode Sum'
//  '<S209>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Tsamp - Integral'
//  '<S210>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Tsamp - Ngain'
//  '<S211>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/postSat Signal'
//  '<S212>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/preSat Signal'
//  '<S213>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S214>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S215>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S216>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/D Gain/Internal Parameters'
//  '<S217>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/External Derivative/Error'
//  '<S218>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S219>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S220>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/I Gain/Internal Parameters'
//  '<S221>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Ideal P Gain/Passthrough'
//  '<S222>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S223>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Integrator/Discrete'
//  '<S224>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Integrator ICs/Internal IC'
//  '<S225>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/N Copy/Disabled'
//  '<S226>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/N Gain/Internal Parameters'
//  '<S227>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/P Copy/Disabled'
//  '<S228>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S229>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Reset Signal/Disabled'
//  '<S230>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Saturation/Enabled'
//  '<S231>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Saturation Fdbk/Disabled'
//  '<S232>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Sum/Sum_PID'
//  '<S233>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Sum Fdbk/Disabled'
//  '<S234>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Tracking Mode/Disabled'
//  '<S235>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S236>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S237>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S238>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/postSat Signal/Forward_Path'
//  '<S239>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller2/preSat Signal/Forward_Path'
//  '<S240>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Anti-windup'
//  '<S241>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/D Gain'
//  '<S242>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/External Derivative'
//  '<S243>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Filter'
//  '<S244>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Filter ICs'
//  '<S245>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/I Gain'
//  '<S246>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Ideal P Gain'
//  '<S247>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Ideal P Gain Fdbk'
//  '<S248>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Integrator'
//  '<S249>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Integrator ICs'
//  '<S250>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/N Copy'
//  '<S251>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/N Gain'
//  '<S252>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/P Copy'
//  '<S253>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Parallel P Gain'
//  '<S254>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Reset Signal'
//  '<S255>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Saturation'
//  '<S256>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Saturation Fdbk'
//  '<S257>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Sum'
//  '<S258>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Sum Fdbk'
//  '<S259>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Tracking Mode'
//  '<S260>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Tracking Mode Sum'
//  '<S261>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Tsamp - Integral'
//  '<S262>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Tsamp - Ngain'
//  '<S263>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/postSat Signal'
//  '<S264>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/preSat Signal'
//  '<S265>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Anti-windup/Disabled'
//  '<S266>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/D Gain/Disabled'
//  '<S267>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/External Derivative/Disabled'
//  '<S268>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Filter/Disabled'
//  '<S269>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Filter ICs/Disabled'
//  '<S270>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/I Gain/Disabled'
//  '<S271>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Ideal P Gain/Passthrough'
//  '<S272>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S273>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Integrator/Disabled'
//  '<S274>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Integrator ICs/Disabled'
//  '<S275>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S276>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/N Gain/Disabled'
//  '<S277>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/P Copy/Disabled'
//  '<S278>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S279>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Reset Signal/Disabled'
//  '<S280>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Saturation/Passthrough'
//  '<S281>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Saturation Fdbk/Disabled'
//  '<S282>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Sum/Passthrough_P'
//  '<S283>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Sum Fdbk/Disabled'
//  '<S284>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Tracking Mode/Disabled'
//  '<S285>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S286>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S287>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S288>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/postSat Signal/Forward_Path'
//  '<S289>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller3/preSat Signal/Forward_Path'
//  '<S290>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Anti-windup'
//  '<S291>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/D Gain'
//  '<S292>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/External Derivative'
//  '<S293>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Filter'
//  '<S294>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Filter ICs'
//  '<S295>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/I Gain'
//  '<S296>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Ideal P Gain'
//  '<S297>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S298>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Integrator'
//  '<S299>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Integrator ICs'
//  '<S300>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/N Copy'
//  '<S301>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/N Gain'
//  '<S302>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/P Copy'
//  '<S303>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Parallel P Gain'
//  '<S304>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Reset Signal'
//  '<S305>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Saturation'
//  '<S306>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Saturation Fdbk'
//  '<S307>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Sum'
//  '<S308>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Sum Fdbk'
//  '<S309>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Tracking Mode'
//  '<S310>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Tracking Mode Sum'
//  '<S311>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Tsamp - Integral'
//  '<S312>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Tsamp - Ngain'
//  '<S313>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/postSat Signal'
//  '<S314>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/preSat Signal'
//  '<S315>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Anti-windup/Disabled'
//  '<S316>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/D Gain/Disabled'
//  '<S317>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/External Derivative/Disabled'
//  '<S318>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Filter/Disabled'
//  '<S319>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Filter ICs/Disabled'
//  '<S320>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/I Gain/Disabled'
//  '<S321>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S322>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S323>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Integrator/Disabled'
//  '<S324>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Integrator ICs/Disabled'
//  '<S325>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S326>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/N Gain/Disabled'
//  '<S327>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/P Copy/Disabled'
//  '<S328>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S329>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Reset Signal/Disabled'
//  '<S330>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Saturation/Passthrough'
//  '<S331>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S332>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Sum/Passthrough_P'
//  '<S333>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S334>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Tracking Mode/Disabled'
//  '<S335>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S336>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S337>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S338>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S339>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Attitude controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S340>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/Altitude Signal conditioning'
//  '<S341>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/Calculate Transformation Matrix'
//  '<S342>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/Calculate minimum Turn'
//  '<S343>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller'
//  '<S344>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1'
//  '<S345>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5'
//  '<S346>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude'
//  '<S347>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz'
//  '<S348>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/Altitude Signal conditioning/Saturation Dynamic'
//  '<S349>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Anti-windup'
//  '<S350>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/D Gain'
//  '<S351>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/External Derivative'
//  '<S352>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Filter'
//  '<S353>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Filter ICs'
//  '<S354>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/I Gain'
//  '<S355>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Ideal P Gain'
//  '<S356>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Ideal P Gain Fdbk'
//  '<S357>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Integrator'
//  '<S358>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Integrator ICs'
//  '<S359>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/N Copy'
//  '<S360>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/N Gain'
//  '<S361>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/P Copy'
//  '<S362>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Parallel P Gain'
//  '<S363>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Reset Signal'
//  '<S364>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Saturation'
//  '<S365>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Saturation Fdbk'
//  '<S366>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Sum'
//  '<S367>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Sum Fdbk'
//  '<S368>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Tracking Mode'
//  '<S369>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Tracking Mode Sum'
//  '<S370>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Tsamp - Integral'
//  '<S371>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Tsamp - Ngain'
//  '<S372>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/postSat Signal'
//  '<S373>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/preSat Signal'
//  '<S374>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Anti-windup/Disabled'
//  '<S375>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/D Gain/Disabled'
//  '<S376>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/External Derivative/Disabled'
//  '<S377>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Filter/Disabled'
//  '<S378>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Filter ICs/Disabled'
//  '<S379>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/I Gain/Disabled'
//  '<S380>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S381>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S382>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Integrator/Disabled'
//  '<S383>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Integrator ICs/Disabled'
//  '<S384>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S385>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/N Gain/Disabled'
//  '<S386>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/P Copy/Disabled'
//  '<S387>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S388>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Reset Signal/Disabled'
//  '<S389>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Saturation/Enabled'
//  '<S390>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S391>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Sum/Passthrough_P'
//  '<S392>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Sum Fdbk/Disabled'
//  '<S393>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Tracking Mode/Disabled'
//  '<S394>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S395>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S396>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S397>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/postSat Signal/Forward_Path'
//  '<S398>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller/preSat Signal/Forward_Path'
//  '<S399>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Anti-windup'
//  '<S400>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/D Gain'
//  '<S401>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/External Derivative'
//  '<S402>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Filter'
//  '<S403>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Filter ICs'
//  '<S404>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/I Gain'
//  '<S405>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Ideal P Gain'
//  '<S406>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S407>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Integrator'
//  '<S408>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Integrator ICs'
//  '<S409>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/N Copy'
//  '<S410>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/N Gain'
//  '<S411>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/P Copy'
//  '<S412>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Parallel P Gain'
//  '<S413>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Reset Signal'
//  '<S414>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Saturation'
//  '<S415>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Saturation Fdbk'
//  '<S416>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Sum'
//  '<S417>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Sum Fdbk'
//  '<S418>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Tracking Mode'
//  '<S419>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Tracking Mode Sum'
//  '<S420>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Tsamp - Integral'
//  '<S421>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Tsamp - Ngain'
//  '<S422>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/postSat Signal'
//  '<S423>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/preSat Signal'
//  '<S424>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Anti-windup/Disabled'
//  '<S425>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/D Gain/Disabled'
//  '<S426>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/External Derivative/Disabled'
//  '<S427>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Filter/Disabled'
//  '<S428>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Filter ICs/Disabled'
//  '<S429>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/I Gain/Disabled'
//  '<S430>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S431>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S432>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Integrator/Disabled'
//  '<S433>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Integrator ICs/Disabled'
//  '<S434>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S435>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/N Gain/Disabled'
//  '<S436>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/P Copy/Disabled'
//  '<S437>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S438>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Reset Signal/Disabled'
//  '<S439>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Saturation/Enabled'
//  '<S440>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S441>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Sum/Passthrough_P'
//  '<S442>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S443>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Tracking Mode/Disabled'
//  '<S444>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S445>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S446>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S447>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S448>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S449>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Anti-windup'
//  '<S450>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/D Gain'
//  '<S451>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/External Derivative'
//  '<S452>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Filter'
//  '<S453>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Filter ICs'
//  '<S454>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/I Gain'
//  '<S455>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Ideal P Gain'
//  '<S456>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Ideal P Gain Fdbk'
//  '<S457>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Integrator'
//  '<S458>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Integrator ICs'
//  '<S459>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/N Copy'
//  '<S460>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/N Gain'
//  '<S461>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/P Copy'
//  '<S462>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Parallel P Gain'
//  '<S463>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Reset Signal'
//  '<S464>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Saturation'
//  '<S465>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Saturation Fdbk'
//  '<S466>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Sum'
//  '<S467>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Sum Fdbk'
//  '<S468>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Tracking Mode'
//  '<S469>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Tracking Mode Sum'
//  '<S470>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Tsamp - Integral'
//  '<S471>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Tsamp - Ngain'
//  '<S472>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/postSat Signal'
//  '<S473>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/preSat Signal'
//  '<S474>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Anti-windup/Disabled'
//  '<S475>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/D Gain/Disabled'
//  '<S476>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/External Derivative/Disabled'
//  '<S477>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Filter/Disabled'
//  '<S478>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Filter ICs/Disabled'
//  '<S479>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/I Gain/Disabled'
//  '<S480>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Ideal P Gain/Passthrough'
//  '<S481>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Ideal P Gain Fdbk/Disabled'
//  '<S482>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Integrator/Disabled'
//  '<S483>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Integrator ICs/Disabled'
//  '<S484>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/N Copy/Disabled wSignal Specification'
//  '<S485>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/N Gain/Disabled'
//  '<S486>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/P Copy/Disabled'
//  '<S487>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Parallel P Gain/Internal Parameters'
//  '<S488>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Reset Signal/Disabled'
//  '<S489>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Saturation/Enabled'
//  '<S490>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Saturation Fdbk/Disabled'
//  '<S491>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Sum/Passthrough_P'
//  '<S492>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Sum Fdbk/Disabled'
//  '<S493>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Tracking Mode/Disabled'
//  '<S494>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Tracking Mode Sum/Passthrough'
//  '<S495>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Tsamp - Integral/TsSignalSpecification'
//  '<S496>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/Tsamp - Ngain/Passthrough'
//  '<S497>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/postSat Signal/Forward_Path'
//  '<S498>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID Controller5/preSat Signal/Forward_Path'
//  '<S499>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Anti-windup'
//  '<S500>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/D Gain'
//  '<S501>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/External Derivative'
//  '<S502>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Filter'
//  '<S503>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Filter ICs'
//  '<S504>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/I Gain'
//  '<S505>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Ideal P Gain'
//  '<S506>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S507>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Integrator'
//  '<S508>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Integrator ICs'
//  '<S509>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/N Copy'
//  '<S510>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/N Gain'
//  '<S511>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/P Copy'
//  '<S512>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Parallel P Gain'
//  '<S513>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Reset Signal'
//  '<S514>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Saturation'
//  '<S515>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Saturation Fdbk'
//  '<S516>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Sum'
//  '<S517>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Sum Fdbk'
//  '<S518>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Tracking Mode'
//  '<S519>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Tracking Mode Sum'
//  '<S520>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Tsamp - Integral'
//  '<S521>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Tsamp - Ngain'
//  '<S522>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/postSat Signal'
//  '<S523>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/preSat Signal'
//  '<S524>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel'
//  '<S525>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S526>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S527>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/D Gain/Internal Parameters'
//  '<S528>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/External Derivative/Error'
//  '<S529>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Filter/Disc. Forward Euler Filter'
//  '<S530>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Filter ICs/Internal IC - Filter'
//  '<S531>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/I Gain/Internal Parameters'
//  '<S532>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S533>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Ideal P Gain Fdbk/Passthrough'
//  '<S534>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Integrator/Discrete'
//  '<S535>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Integrator ICs/Internal IC'
//  '<S536>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/N Copy/Disabled'
//  '<S537>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/N Gain/Internal Parameters'
//  '<S538>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/P Copy/Disabled'
//  '<S539>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Parallel P Gain/Internal Parameters'
//  '<S540>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Reset Signal/Disabled'
//  '<S541>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Saturation/Enabled'
//  '<S542>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Saturation Fdbk/Passthrough'
//  '<S543>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Sum/Sum_PID'
//  '<S544>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Sum Fdbk/Enabled'
//  '<S545>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S546>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S547>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S548>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S549>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/postSat Signal/Feedback_Path'
//  '<S550>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_Altitude/preSat Signal/Feedback_Path'
//  '<S551>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Anti-windup'
//  '<S552>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/D Gain'
//  '<S553>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/External Derivative'
//  '<S554>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Filter'
//  '<S555>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Filter ICs'
//  '<S556>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/I Gain'
//  '<S557>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Ideal P Gain'
//  '<S558>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Ideal P Gain Fdbk'
//  '<S559>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Integrator'
//  '<S560>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Integrator ICs'
//  '<S561>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/N Copy'
//  '<S562>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/N Gain'
//  '<S563>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/P Copy'
//  '<S564>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Parallel P Gain'
//  '<S565>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Reset Signal'
//  '<S566>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Saturation'
//  '<S567>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Saturation Fdbk'
//  '<S568>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Sum'
//  '<S569>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Sum Fdbk'
//  '<S570>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Tracking Mode'
//  '<S571>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Tracking Mode Sum'
//  '<S572>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Tsamp - Integral'
//  '<S573>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Tsamp - Ngain'
//  '<S574>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/postSat Signal'
//  '<S575>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/preSat Signal'
//  '<S576>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel'
//  '<S577>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S578>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S579>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/D Gain/Internal Parameters'
//  '<S580>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/External Derivative/Error'
//  '<S581>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Filter/Disc. Forward Euler Filter'
//  '<S582>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Filter ICs/Internal IC - Filter'
//  '<S583>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/I Gain/Internal Parameters'
//  '<S584>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Ideal P Gain/Passthrough'
//  '<S585>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Ideal P Gain Fdbk/Passthrough'
//  '<S586>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Integrator/Discrete'
//  '<S587>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Integrator ICs/Internal IC'
//  '<S588>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/N Copy/Disabled'
//  '<S589>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/N Gain/Internal Parameters'
//  '<S590>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/P Copy/Disabled'
//  '<S591>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Parallel P Gain/Internal Parameters'
//  '<S592>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Reset Signal/Disabled'
//  '<S593>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Saturation/Enabled'
//  '<S594>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Saturation Fdbk/Passthrough'
//  '<S595>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Sum/Sum_PID'
//  '<S596>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Sum Fdbk/Enabled'
//  '<S597>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Tracking Mode/Disabled'
//  '<S598>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Tracking Mode Sum/Passthrough'
//  '<S599>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Tsamp - Integral/TsSignalSpecification'
//  '<S600>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/Tsamp - Ngain/Passthrough'
//  '<S601>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/postSat Signal/Feedback_Path'
//  '<S602>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Position & Altitude controller/PID_vz/preSat Signal/Feedback_Path'
//  '<S603>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Quaternion Validity Check/Quaternion Norm'
//  '<S604>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles/Angle Calculation'
//  '<S605>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S606>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S607>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S608>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S609>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S610>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S611>' : 'FLIGHT_HEXA_Hovering/Subsystem Reference/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                                 // FLIGHT_HEXA_Hovering_h_

//
// File trailer for generated code.
//
// [EOF]
//
