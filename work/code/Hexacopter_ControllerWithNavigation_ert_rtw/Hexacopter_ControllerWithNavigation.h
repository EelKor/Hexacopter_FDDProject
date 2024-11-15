//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Hexacopter_ControllerWithNavigation.h
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
#ifndef Hexacopter_ControllerWithNavigation_h_
#define Hexacopter_ControllerWithNavigation_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "Hexacopter_ControllerWithNavigation_types.h"
#include <uORB/topics/vehicle_trajectory_waypoint.h>
#include <uORB/topics/position_setpoint_triplet.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/trajectory_waypoint.h>
#include <uORB/topics/home_position.h>
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

// Block signals for system '<S51>/MATLAB System'
struct B_MATLABSystem_Hexacopter_ControllerWithNavigation_T {
  real32_T MATLABSystem[3];            // '<S51>/MATLAB System'
  real_T dLat;
};

// Block states (default storage) for system '<S51>/MATLAB System'
struct DW_MATLABSystem_Hexacopter_ControllerWithNavigation_T {
  px4_internal_block_LLA2LocalCoordinatesNED_Hexacopter_Control_T obj;// '<S51>/MATLAB System' 
  boolean_T objisempty;                // '<S51>/MATLAB System'
};

// Block signals (default storage)
struct B_Hexacopter_ControllerWithNavigation_T {
  px4_Bus_vehicle_trajectory_waypoint BusAssignment1;// '<S45>/Bus Assignment1'
  px4_Bus_vehicle_trajectory_waypoint In1;// '<S50>/In1'
  px4_Bus_vehicle_trajectory_waypoint r;
  px4_Bus_position_setpoint_triplet In1_p;// '<S62>/In1'
  px4_Bus_position_setpoint_triplet r1;
  px4_Bus_vehicle_local_position In1_c;// '<S24>/In1'
  px4_Bus_vehicle_local_position r2;
  px4_Bus_vehicle_odometry In1_l;      // '<S19>/In1'
  px4_Bus_vehicle_odometry r3;
  px4_Bus_input_rc In1_j;              // '<S22>/In1'
  px4_Bus_input_rc r4;
  real_T b_waypointsIn_data[9];
  real_T MatrixConcatenate_p[9];       // '<S32>/Matrix Concatenate'
  px4_Bus_vehicle_attitude In1_m;      // '<S23>/In1'
  px4_Bus_vehicle_attitude r5;
  px4_Bus_trajectory_waypoint BusAssignment1_f;// '<S53>/Bus Assignment1'
  px4_Bus_home_position In1_f;         // '<S61>/In1'
  px4_Bus_home_position r6;
  real_T lla0[3];
  real_T virtualWaypoint[3];
  real_T VectorConcatenate[3];         // '<S594>/Vector Concatenate'
  real_T DataTypeConversion2[3];       // '<S2>/Data Type Conversion2'
  real_T dv[3];
  px4_Bus_actuator_armed In1_b;        // '<S20>/In1'
  px4_Bus_actuator_armed r7;
  uint16_T pwmValue[8];
  real_T Saturation[2];                // '<S379>/Saturation'
  uint16_T CastToDouble[6];            // '<S6>/Cast To Double'
  real_T Gain1;                        // '<S66>/Gain1'
  real_T Saturation_a;                 // '<S479>/Saturation'
  real_T Saturation_o;                 // '<S583>/Saturation'
  real_T Saturation_n;                 // '<S116>/Saturation'
  real_T Saturation_b;                 // '<S168>/Saturation'
  real_T Saturation_a1;                // '<S220>/Saturation'
  real_T yaw_In;                       // '<S34>/yaw_In'
  real_T yaw_In_i;                     // '<S38>/yaw_In'
  real_T In;                           // '<S37>/In'
  real_T yaw_In_ik;                    // '<S41>/yaw_In'
  real_T Gain_i;                       // '<S39>/Gain'
  real_T Gain1_m;                      // '<S4>/Gain1'
  real_T Gain2;                        // '<S4>/Gain2'
  real_T Gain4;                        // '<S4>/Gain4'
  real_T Sum_o;                        // '<S9>/Sum'
  real_T rtb_Merge_idx_3;
  real_T rtb_Merge_idx_2;
  real_T rtb_TmpSignalConversionAtProduct1Inport2_idx_3;
  real_T rtb_TmpSignalConversionAtProduct1Inport2_idx_0;
  real_T rtb_TmpSignalConversionAtProduct1Inport2_idx_1;
  real_T rtb_TmpSignalConversionAtProduct1Inport2_idx_2;
  real_T rtb_Merge_idx_0;
  real_T rtb_Merge_idx_1;
  real_T rtb_VectorConcatenate_tmp;
  real_T rtb_VectorConcatenate_tmp_c;
  real_T rtb_VectorConcatenate_tmp_k;
  real_T rtb_VectorConcatenate_tmp_cx;
  real_T dLat;
  real_T dLon;
  real_T Rn;
  real_T flat;
  real_T b_x;
  real_T absx;
  real_T absx_b;
  real_T q;
  real_T scale;
  real_T absxk;
  real_T t;
  boolean_T x[6];
  real32_T ParamStep;
  int32_T ParamStep_p;
  int32_T ParamStep_c;
  int32_T ParamStep_f;
  int32_T ParamStep_g;
  int32_T ParamStep_g1;
  int32_T i2;
  int32_T i1;
  int32_T b_k;
  int32_T i;
  int32_T i1_m;
  int8_T tmp_data[3];
  boolean_T distinctWptsIdx[3];
  boolean_T b[3];
  uint16_T u0;
  boolean_T IsNaN_l[2];                // '<S30>/IsNaN'
  int8_T rtPrevAction;
  int8_T i2_n;
  boolean_T latp2;
  boolean_T Compare_f;                 // '<S13>/Compare'
  boolean_T latp2_p;
  B_MATLABSystem_Hexacopter_ControllerWithNavigation_T MATLABSystem_b;// '<S51>/MATLAB System' 
  B_MATLABSystem_Hexacopter_ControllerWithNavigation_T MATLABSystem;// '<S51>/MATLAB System' 
};

// Block states (default storage) for system '<Root>'
struct DW_Hexacopter_ControllerWithNavigation_T {
  uav_sluav_internal_system_WaypointFollower_Hexacopter_Control_T obj;// '<S32>/UAV Waypoint Follower' 
  px4_internal_block_ParameterUpdate_Hexacopter_ControllerWithN_T obj_b;// '<S59>/Read Parameter' 
  px4_internal_block_ParameterUpdate_Hexacopter_ControllerWithN_T obj_g;// '<S60>/Read Parameter' 
  px4_internal_block_ParameterUpdate_Hexacopter_ControllerWithN_T obj_k;// '<S28>/Read Parameter' 
  px4_internal_block_ParameterUpdate_Hexacopter_ControllerWithN_T obj_d;// '<S6>/Read Parameter5' 
  px4_internal_block_ParameterUpdate_Hexacopter_ControllerWithN_T obj_j;// '<S6>/Read Parameter4' 
  px4_internal_block_ParameterUpdate_Hexacopter_ControllerWithN_T obj_p;// '<S6>/Read Parameter3' 
  px4_internal_block_ParameterUpdate_Hexacopter_ControllerWithN_T obj_jh;// '<S6>/Read Parameter2' 
  px4_internal_block_ParameterUpdate_Hexacopter_ControllerWithN_T obj_a;// '<S6>/Read Parameter13' 
  px4_internal_block_ParameterUpdate_Hexacopter_ControllerWithN_T obj_l;// '<S6>/Read Parameter1' 
  px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T obj_kz;// '<S47>/SourceBlock' 
  px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T obj_gf;// '<S46>/SourceBlock' 
  px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T obj_e;// '<S49>/SourceBlock' 
  px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T obj_m;// '<S18>/SourceBlock' 
  px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T obj_gv;// '<S17>/SourceBlock' 
  px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T obj_ah;// '<S21>/SourceBlock' 
  px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T obj_d0;// '<S15>/SourceBlock' 
  px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T obj_po;// '<S14>/SourceBlock' 
  px4_internal_block_getPX4AbsoluteTime_Hexacopter_ControllerWi_T obj_n;// '<S44>/PX4 Timestamp' 
  px4_internal_block_PWM_Hexacopter_ControllerWithNavigation_T obj_pk;// '<S5>/PX4 PWM Output' 
  px4_internal_block_LLA2LocalCoordinates_Hexacopter_Controller_T obj_mr;// '<S28>/LLA2LocalCoordinates' 
  px4_internal_block_Publisher_Hexacopter_ControllerWithNavigat_T obj_mc;// '<S56>/SinkBlock' 
  real_T Filter_DSTATE;                // '<S519>/Filter'
  real_T Integrator_DSTATE;            // '<S524>/Integrator'
  real_T Filter_DSTATE_o;              // '<S571>/Filter'
  real_T Integrator_DSTATE_o;          // '<S576>/Integrator'
  real_T Integrator_DSTATE_i;          // '<S109>/Integrator'
  real_T Filter_DSTATE_ov;             // '<S104>/Filter'
  real_T Integrator_DSTATE_h;          // '<S161>/Integrator'
  real_T Filter_DSTATE_c;              // '<S156>/Filter'
  real_T Integrator_DSTATE_ih;         // '<S213>/Integrator'
  real_T Filter_DSTATE_f;              // '<S208>/Filter'
  real_T Delay_DSTATE;                 // '<S33>/Delay'
  real_T Delay_DSTATE_l[2];            // '<S30>/Delay'
  real_T Delay_DSTATE_n;               // '<S35>/Delay'
  real_T Delay_DSTATE_b;               // '<S36>/Delay'
  real_T Delay_DSTATE_c;               // '<S39>/Delay'
  real_T Delay_DSTATE_d;               // '<S40>/Delay'
  real_T PrevY;                        // '<S63>/Rate Limiter2'
  real_T PrevY_m;                      // '<S63>/Rate Limiter1'
  px4_internal_block_LLA2LocalCoordinatesNED_Hexacopter_Control_T obj_mu;// '<S54>/MATLAB System' 
  int8_T If_ActiveSubsystem;           // '<S27>/If'
  uint8_T is_active_c3_Hexacopter_ControllerWithNavigation;// '<S4>/Chart'
  uint8_T is_c3_Hexacopter_ControllerWithNavigation;// '<S4>/Chart'
  DW_MATLABSystem_Hexacopter_ControllerWithNavigation_T MATLABSystem_b;// '<S51>/MATLAB System' 
  DW_MATLABSystem_Hexacopter_ControllerWithNavigation_T MATLABSystem;// '<S51>/MATLAB System' 
};

// Parameters (default storage)
struct P_Hexacopter_ControllerWithNavigation_T_ {
  real_T PIDController_D;              // Mask Parameter: PIDController_D
                                          //  Referenced by: '<S102>/Derivative Gain'

  real_T PIDController1_D;             // Mask Parameter: PIDController1_D
                                          //  Referenced by: '<S154>/Derivative Gain'

  real_T PIDController2_D;             // Mask Parameter: PIDController2_D
                                          //  Referenced by: '<S206>/Derivative Gain'

  real_T PID_Altitude_D;               // Mask Parameter: PID_Altitude_D
                                          //  Referenced by: '<S517>/Derivative Gain'

  real_T PID_vz_D;                     // Mask Parameter: PID_vz_D
                                          //  Referenced by: '<S569>/Derivative Gain'

  real_T PIDController_I;              // Mask Parameter: PIDController_I
                                          //  Referenced by: '<S106>/Integral Gain'

  real_T PIDController1_I;             // Mask Parameter: PIDController1_I
                                          //  Referenced by: '<S158>/Integral Gain'

  real_T PIDController2_I;             // Mask Parameter: PIDController2_I
                                          //  Referenced by: '<S210>/Integral Gain'

  real_T PID_Altitude_I;               // Mask Parameter: PID_Altitude_I
                                          //  Referenced by: '<S521>/Integral Gain'

  real_T PID_vz_I;                     // Mask Parameter: PID_vz_I
                                          //  Referenced by: '<S573>/Integral Gain'

  real_T PIDController_InitialConditionForFilter;
                      // Mask Parameter: PIDController_InitialConditionForFilter
                         //  Referenced by: '<S104>/Filter'

  real_T PIDController1_InitialConditionForFilter;
                     // Mask Parameter: PIDController1_InitialConditionForFilter
                        //  Referenced by: '<S156>/Filter'

  real_T PIDController2_InitialConditionForFilter;
                     // Mask Parameter: PIDController2_InitialConditionForFilter
                        //  Referenced by: '<S208>/Filter'

  real_T PID_Altitude_InitialConditionForFilter;
                       // Mask Parameter: PID_Altitude_InitialConditionForFilter
                          //  Referenced by: '<S519>/Filter'

  real_T PID_vz_InitialConditionForFilter;
                             // Mask Parameter: PID_vz_InitialConditionForFilter
                                //  Referenced by: '<S571>/Filter'

  real_T PIDController_InitialConditionForIntegrator;
                  // Mask Parameter: PIDController_InitialConditionForIntegrator
                     //  Referenced by: '<S109>/Integrator'

  real_T PIDController1_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController1_InitialConditionForIntegrator
                    //  Referenced by: '<S161>/Integrator'

  real_T PIDController2_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController2_InitialConditionForIntegrator
                    //  Referenced by: '<S213>/Integrator'

  real_T PID_Altitude_InitialConditionForIntegrator;
                   // Mask Parameter: PID_Altitude_InitialConditionForIntegrator
                      //  Referenced by: '<S524>/Integrator'

  real_T PID_vz_InitialConditionForIntegrator;
                         // Mask Parameter: PID_vz_InitialConditionForIntegrator
                            //  Referenced by: '<S576>/Integrator'

  real_T PIDController_LowerSaturationLimit;
                           // Mask Parameter: PIDController_LowerSaturationLimit
                              //  Referenced by:
                              //    '<S116>/Saturation'
                              //    '<S101>/DeadZone'

  real_T PIDController1_LowerSaturationLimit;
                          // Mask Parameter: PIDController1_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S168>/Saturation'
                             //    '<S153>/DeadZone'

  real_T PIDController2_LowerSaturationLimit;
                          // Mask Parameter: PIDController2_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S220>/Saturation'
                             //    '<S205>/DeadZone'

  real_T PIDController1_LowerSaturationLimit_e;
                        // Mask Parameter: PIDController1_LowerSaturationLimit_e
                           //  Referenced by: '<S429>/Saturation'

  real_T PIDController_LowerSaturationLimit_j;
                         // Mask Parameter: PIDController_LowerSaturationLimit_j
                            //  Referenced by: '<S379>/Saturation'

  real_T PIDController5_LowerSaturationLimit;
                          // Mask Parameter: PIDController5_LowerSaturationLimit
                             //  Referenced by: '<S479>/Saturation'

  real_T PID_Altitude_LowerSaturationLimit;
                            // Mask Parameter: PID_Altitude_LowerSaturationLimit
                               //  Referenced by:
                               //    '<S531>/Saturation'
                               //    '<S516>/DeadZone'

  real_T PID_vz_LowerSaturationLimit;
                                  // Mask Parameter: PID_vz_LowerSaturationLimit
                                     //  Referenced by:
                                     //    '<S583>/Saturation'
                                     //    '<S568>/DeadZone'

  real_T PIDController_N;              // Mask Parameter: PIDController_N
                                          //  Referenced by: '<S112>/Filter Coefficient'

  real_T PIDController1_N;             // Mask Parameter: PIDController1_N
                                          //  Referenced by: '<S164>/Filter Coefficient'

  real_T PIDController2_N;             // Mask Parameter: PIDController2_N
                                          //  Referenced by: '<S216>/Filter Coefficient'

  real_T PID_Altitude_N;               // Mask Parameter: PID_Altitude_N
                                          //  Referenced by: '<S527>/Filter Coefficient'

  real_T PID_vz_N;                     // Mask Parameter: PID_vz_N
                                          //  Referenced by: '<S579>/Filter Coefficient'

  real_T PIDController_P;              // Mask Parameter: PIDController_P
                                          //  Referenced by: '<S114>/Proportional Gain'

  real_T PIDController3_P;             // Mask Parameter: PIDController3_P
                                          //  Referenced by: '<S268>/Proportional Gain'

  real_T PIDController1_P;             // Mask Parameter: PIDController1_P
                                          //  Referenced by: '<S166>/Proportional Gain'

  real_T PIDController4_P;             // Mask Parameter: PIDController4_P
                                          //  Referenced by: '<S318>/Proportional Gain'

  real_T PIDController2_P;             // Mask Parameter: PIDController2_P
                                          //  Referenced by: '<S218>/Proportional Gain'

  real_T PIDController1_P_h;           // Mask Parameter: PIDController1_P_h
                                          //  Referenced by: '<S427>/Proportional Gain'

  real_T PIDController_P_d;            // Mask Parameter: PIDController_P_d
                                          //  Referenced by: '<S377>/Proportional Gain'

  real_T PIDController5_P;             // Mask Parameter: PIDController5_P
                                          //  Referenced by: '<S477>/Proportional Gain'

  real_T PID_Altitude_P;               // Mask Parameter: PID_Altitude_P
                                          //  Referenced by: '<S529>/Proportional Gain'

  real_T PID_vz_P;                     // Mask Parameter: PID_vz_P
                                          //  Referenced by: '<S581>/Proportional Gain'

  real_T PIDController_UpperSaturationLimit;
                           // Mask Parameter: PIDController_UpperSaturationLimit
                              //  Referenced by:
                              //    '<S116>/Saturation'
                              //    '<S101>/DeadZone'

  real_T PIDController1_UpperSaturationLimit;
                          // Mask Parameter: PIDController1_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S168>/Saturation'
                             //    '<S153>/DeadZone'

  real_T PIDController2_UpperSaturationLimit;
                          // Mask Parameter: PIDController2_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S220>/Saturation'
                             //    '<S205>/DeadZone'

  real_T PIDController1_UpperSaturationLimit_l;
                        // Mask Parameter: PIDController1_UpperSaturationLimit_l
                           //  Referenced by: '<S429>/Saturation'

  real_T PIDController_UpperSaturationLimit_b;
                         // Mask Parameter: PIDController_UpperSaturationLimit_b
                            //  Referenced by: '<S379>/Saturation'

  real_T PIDController5_UpperSaturationLimit;
                          // Mask Parameter: PIDController5_UpperSaturationLimit
                             //  Referenced by: '<S479>/Saturation'

  real_T PID_Altitude_UpperSaturationLimit;
                            // Mask Parameter: PID_Altitude_UpperSaturationLimit
                               //  Referenced by:
                               //    '<S531>/Saturation'
                               //    '<S516>/DeadZone'

  real_T PID_vz_UpperSaturationLimit;
                                  // Mask Parameter: PID_vz_UpperSaturationLimit
                                     //  Referenced by:
                                     //    '<S583>/Saturation'
                                     //    '<S568>/DeadZone'

  uint16_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S13>/Constant'

  uint8_T CompareToConstant_const_d;// Mask Parameter: CompareToConstant_const_d
                                       //  Referenced by: '<S43>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Out1_Y0;// Computed Parameter: Out1_Y0
                                                 //  Referenced by: '<S50>/Out1'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value;// Computed Parameter: Constant_Value
                                                        //  Referenced by: '<S55>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                          //  Referenced by: '<S49>/Constant'

  px4_Bus_position_setpoint_triplet Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                 //  Referenced by: '<S62>/Out1'

  px4_Bus_position_setpoint_triplet Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                        //  Referenced by: '<S47>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                              //  Referenced by: '<S24>/Out1'

  px4_Bus_vehicle_local_position Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                     //  Referenced by: '<S18>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0_e;  // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S19>/Out1'

  px4_Bus_vehicle_odometry Constant_Value_n;// Computed Parameter: Constant_Value_n
                                               //  Referenced by: '<S14>/Constant'

  px4_Bus_input_rc Out1_Y0_m;          // Computed Parameter: Out1_Y0_m
                                          //  Referenced by: '<S22>/Out1'

  px4_Bus_input_rc Constant_Value_o;   // Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S21>/Constant'

  px4_Bus_vehicle_attitude Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S23>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_l;// Computed Parameter: Constant_Value_l
                                               //  Referenced by: '<S17>/Constant'

  px4_Bus_home_position Out1_Y0_o;     // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S61>/Out1'

  px4_Bus_home_position Constant_Value_b;// Computed Parameter: Constant_Value_b
                                            //  Referenced by: '<S46>/Constant'

  px4_Bus_actuator_armed Out1_Y0_d;    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S20>/Out1'

  px4_Bus_actuator_armed Constant_Value_j;// Computed Parameter: Constant_Value_j
                                             //  Referenced by: '<S15>/Constant'

  real_T ReadParameter1_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S6>/Read Parameter1'

  real_T ReadParameter13_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S6>/Read Parameter13'

  real_T ReadParameter2_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S6>/Read Parameter2'

  real_T ReadParameter3_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S6>/Read Parameter3'

  real_T ReadParameter4_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S6>/Read Parameter4'

  real_T ReadParameter5_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S6>/Read Parameter5'

  real_T Fault1_Value;                 // Expression: 100
                                          //  Referenced by: '<S6>/Fault1'

  real_T Constant1_Value;              // Expression: 100
                                          //  Referenced by: '<S6>/Constant1'

  real_T Fault2_Value;                 // Expression: 100
                                          //  Referenced by: '<S6>/Fault2'

  real_T Constant2_Value;              // Expression: 100
                                          //  Referenced by: '<S6>/Constant2'

  real_T Fault3_Value;                 // Expression: 100
                                          //  Referenced by: '<S6>/Fault3'

  real_T Constant3_Value;              // Expression: 100
                                          //  Referenced by: '<S6>/Constant3'

  real_T Fault4_Value;                 // Expression: 100
                                          //  Referenced by: '<S6>/Fault4'

  real_T Constant4_Value;              // Expression: 100
                                          //  Referenced by: '<S6>/Constant4'

  real_T Fault5_Value;                 // Expression: 100
                                          //  Referenced by: '<S6>/Fault5'

  real_T Constant5_Value;              // Expression: 100
                                          //  Referenced by: '<S6>/Constant5'

  real_T Fault_Value;                  // Expression: 100
                                          //  Referenced by: '<S6>/Fault'

  real_T Constant_Value_h;             // Expression: 100
                                          //  Referenced by: '<S6>/Constant'

  real_T yaw_Out_Y0;                   // Computed Parameter: yaw_Out_Y0
                                          //  Referenced by: '<S41>/yaw_Out'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S39>/Delay'

  real_T Rate_Value;                   // Expression: 0.01
                                          //  Referenced by: '<S39>/Rate'

  real_T Gain1_Gain;                   // Expression: -1
                                          //  Referenced by: '<S39>/Gain1'

  real_T Gain_Gain;                    // Expression: -1
                                          //  Referenced by: '<S39>/Gain'

  real_T Delay_InitialCondition_g;     // Expression: 1
                                          //  Referenced by: '<S40>/Delay'

  real_T Constant_Value_f;             // Expression: 0
                                          //  Referenced by: '<S40>/Constant'

  real_T Out_Y0;                       // Computed Parameter: Out_Y0
                                          //  Referenced by: '<S37>/Out'

  real_T Gain_Gain_l;                  // Expression: -1
                                          //  Referenced by: '<S35>/Gain'

  real_T yaw_Out_Y0_f;                 // Computed Parameter: yaw_Out_Y0_f
                                          //  Referenced by: '<S38>/yaw_Out'

  real_T Delay_InitialCondition_n;     // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay'

  real_T Delay_InitialCondition_m;     // Expression: 0.0
                                          //  Referenced by: '<S35>/Delay'

  real_T Switch_Threshold;             // Expression: 0
                                          //  Referenced by: '<S35>/Switch'

  real_T Rateofdescent_Value;          // Expression: 0.02
                                          //  Referenced by: '<S35>/Rate of descent'

  real_T Gain2_Gain;                   // Expression: -1
                                          //  Referenced by: '<S35>/Gain2'

  real_T Gain1_Gain_a;                 // Expression: -1
                                          //  Referenced by: '<S35>/Gain1'

  real_T Delay_InitialCondition_j;     // Expression: 1
                                          //  Referenced by: '<S36>/Delay'

  real_T Constant_Value_nn;            // Expression: 0
                                          //  Referenced by: '<S36>/Constant'

  real_T Constant_Value_jd;            // Expression: 0
                                          //  Referenced by: '<S42>/Constant'

  real_T Constant_Value_gw;            // Expression: 6
                                          //  Referenced by: '<S32>/Constant'

  real_T yaw_Out_Y0_p;                 // Computed Parameter: yaw_Out_Y0_p
                                          //  Referenced by: '<S34>/yaw_Out'

  real_T Delay_InitialCondition_g0;    // Expression: 1
                                          //  Referenced by: '<S33>/Delay'

  real_T Constant_Value_i;             // Expression: 0
                                          //  Referenced by: '<S33>/Constant'

  real_T ReadParameter_SampleTime;     // Expression: -1
                                          //  Referenced by: '<S28>/Read Parameter'

  real_T ReadParameter_SampleTime_c;   // Expression: -1
                                          //  Referenced by: '<S60>/Read Parameter'

  real_T ReadParameter_SampleTime_g;   // Expression: -1
                                          //  Referenced by: '<S59>/Read Parameter'

  real_T tau_Yaw_Y0;                   // Computed Parameter: tau_Yaw_Y0
                                          //  Referenced by: '<S63>/tau_Yaw'

  real_T tau_Pitch_Y0;                 // Computed Parameter: tau_Pitch_Y0
                                          //  Referenced by: '<S63>/tau_Pitch'

  real_T tau_Roll_Y0;                  // Computed Parameter: tau_Roll_Y0
                                          //  Referenced by: '<S63>/tau_Roll'

  real_T Constant1_Value_m;            // Expression: 0
                                          //  Referenced by: '<S99>/Constant1'

  real_T Constant1_Value_c;            // Expression: 0
                                          //  Referenced by: '<S151>/Constant1'

  real_T Constant1_Value_k;            // Expression: 0
                                          //  Referenced by: '<S203>/Constant1'

  real_T Clamping_zero_Value;          // Expression: 0
                                          //  Referenced by: '<S99>/Clamping_zero'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S109>/Integrator'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S104>/Filter'

  real_T RateLimiter2_RisingLim;       // Expression: 40*pi/180
                                          //  Referenced by: '<S63>/Rate Limiter2'

  real_T RateLimiter2_FallingLim;      // Expression: -40*pi/180
                                          //  Referenced by: '<S63>/Rate Limiter2'

  real_T RateLimiter2_IC;              // Expression: 0
                                          //  Referenced by: '<S63>/Rate Limiter2'

  real_T Saturation1_UpperSat;         // Expression: 20*pi/180
                                          //  Referenced by: '<S63>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -20*pi/180
                                          //  Referenced by: '<S63>/Saturation1'

  real_T Clamping_zero_Value_e;        // Expression: 0
                                          //  Referenced by: '<S151>/Clamping_zero'

  real_T Integrator_gainval_i;       // Computed Parameter: Integrator_gainval_i
                                        //  Referenced by: '<S161>/Integrator'

  real_T Filter_gainval_e;             // Computed Parameter: Filter_gainval_e
                                          //  Referenced by: '<S156>/Filter'

  real_T RateLimiter1_RisingLim;       // Expression: 40*pi/180
                                          //  Referenced by: '<S63>/Rate Limiter1'

  real_T RateLimiter1_FallingLim;      // Expression: -40*pi/180
                                          //  Referenced by: '<S63>/Rate Limiter1'

  real_T RateLimiter1_IC;              // Expression: 0
                                          //  Referenced by: '<S63>/Rate Limiter1'

  real_T Saturation_UpperSat;          // Expression: 20*pi/180
                                          //  Referenced by: '<S63>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -20*pi/180
                                          //  Referenced by: '<S63>/Saturation'

  real_T Clamping_zero_Value_j;        // Expression: 0
                                          //  Referenced by: '<S203>/Clamping_zero'

  real_T Integrator_gainval_f;       // Computed Parameter: Integrator_gainval_f
                                        //  Referenced by: '<S213>/Integrator'

  real_T Filter_gainval_l;             // Computed Parameter: Filter_gainval_l
                                          //  Referenced by: '<S208>/Filter'

  real_T Constant_Value_ib;            // Expression: 0
                                          //  Referenced by: '<S330>/Constant'

  real_T Switch1_Threshold;            // Expression: 0
                                          //  Referenced by: '<S332>/Switch1'

  real_T des_pitch_Y0;                 // Computed Parameter: des_pitch_Y0
                                          //  Referenced by: '<S66>/des_pitch'

  real_T des_roll_Y0;                  // Computed Parameter: des_roll_Y0
                                          //  Referenced by: '<S66>/des_roll'

  real_T des_yawrate_Y0;               // Computed Parameter: des_yawrate_Y0
                                          //  Referenced by: '<S66>/des_yawrate'

  real_T tau_Thrust_Y0;                // Computed Parameter: tau_Thrust_Y0
                                          //  Referenced by: '<S66>/tau_Thrust'

  real_T Constant1_Value_l;            // Expression: 0
                                          //  Referenced by: '<S514>/Constant1'

  real_T Constant1_Value_f;            // Expression: 0
                                          //  Referenced by: '<S566>/Constant1'

  real_T Gain_Gain_o;                  // Expression: -1
                                          //  Referenced by: '<S331>/Gain'

  real_T Constant_Value_g4;            // Expression: 2*pi
                                          //  Referenced by: '<S332>/Constant'

  real_T Switch_Threshold_e;           // Expression: pi
                                          //  Referenced by: '<S332>/Switch'

  real_T Gain1_Gain_m;                 // Expression: -1
                                          //  Referenced by: '<S66>/Gain1'

  real_T Gain1_Gain_h;                 // Expression: -1
                                          //  Referenced by: '<S330>/Gain1'

  real_T Clamping_zero_Value_f;        // Expression: 0
                                          //  Referenced by: '<S514>/Clamping_zero'

  real_T Filter_gainval_i;             // Computed Parameter: Filter_gainval_i
                                          //  Referenced by: '<S519>/Filter'

  real_T Integrator_gainval_p;       // Computed Parameter: Integrator_gainval_p
                                        //  Referenced by: '<S524>/Integrator'

  real_T Clamping_zero_Value_a;        // Expression: 0
                                          //  Referenced by: '<S566>/Clamping_zero'

  real_T Filter_gainval_m;             // Computed Parameter: Filter_gainval_m
                                          //  Referenced by: '<S571>/Filter'

  real_T Integrator_gainval_k;       // Computed Parameter: Integrator_gainval_k
                                        //  Referenced by: '<S576>/Integrator'

  real_T Constant_Value_m[4];          // Expression: [1 0 0 0]
                                          //  Referenced by: '<S67>/Constant'

  real_T Constant_Value_ji;            // Expression: 1
                                          //  Referenced by: '<S597>/Constant'

  real_T Constant_Value_hi;            // Expression: 1
                                          //  Referenced by: '<S598>/Constant'

  real_T Mixermatrix_Value[24];
  // Expression: [1 -1 0 -1;1 1 0 1;1 0.5 0.5 -1;1 -0.5 -0.5 1; 1 -0.5 0.5 1; 1 0.5 -0.5 -1]
     //  Referenced by: '<S5>/Mixer matrix'

  real_T Constant2_Value_b;            // Expression: 1500
                                          //  Referenced by: '<S65>/Constant2'

  real_T Gain2_Gain_j;                 // Expression: 1/400
                                          //  Referenced by: '<S65>/Gain2'

  real_T Saturation2_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S65>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S65>/Saturation2'

  real_T Gain1_Gain_hq;                // Expression: -20*pi/180
                                          //  Referenced by: '<S4>/Gain1'

  real_T Constant1_Value_d;            // Expression: 1500
                                          //  Referenced by: '<S65>/Constant1'

  real_T Gain1_Gain_mu;                // Expression: 1/400
                                          //  Referenced by: '<S65>/Gain1'

  real_T Saturation1_UpperSat_p;       // Expression: 1
                                          //  Referenced by: '<S65>/Saturation1'

  real_T Saturation1_LowerSat_e;       // Expression: -1
                                          //  Referenced by: '<S65>/Saturation1'

  real_T Gain2_Gain_b;                 // Expression: 20*pi/180
                                          //  Referenced by: '<S4>/Gain2'

  real_T Constant_Value_bk;            // Expression: 1100
                                          //  Referenced by: '<S65>/Constant'

  real_T Gain_Gain_k;                  // Expression: 1/800
                                          //  Referenced by: '<S65>/Gain'

  real_T Saturation_UpperSat_c;        // Expression: 0.90
                                          //  Referenced by: '<S65>/Saturation'

  real_T Saturation_LowerSat_g;        // Expression: 0
                                          //  Referenced by: '<S65>/Saturation'

  real_T Constant3_Value_a;            // Expression: 1500
                                          //  Referenced by: '<S65>/Constant3'

  real_T Gain3_Gain;                   // Expression: 1/400
                                          //  Referenced by: '<S65>/Gain3'

  real_T Saturation3_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S65>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S65>/Saturation3'

  real_T Gain4_Gain;                   // Expression: 50*pi/180
                                          //  Referenced by: '<S4>/Gain4'

  real_T Switch_Threshold_d;           // Expression: 0
                                          //  Referenced by: '<S67>/Switch'

  real_T Gain_Gain_b;                  // Expression: -1
                                          //  Referenced by: '<S4>/Gain'

  real_T Bias_Bias;                    // Expression: 1
                                          //  Referenced by: '<S5>/Bias'

  real_T Gain1_Gain_p;                 // Expression: 1000
                                          //  Referenced by: '<S5>/Gain1'

  real_T IDLEPWM_Value;                // Expression: 1100
                                          //  Referenced by: '<S7>/IDLE PWM'

  real_T Gain_Gain_i;                  // Expression: 0.01
                                          //  Referenced by: '<S7>/Gain'

  real_T Saturation1_UpperSat_j;       // Expression: 1
                                          //  Referenced by: '<S7>/Saturation1'

  real_T Saturation1_LowerSat_b;       // Expression: 0
                                          //  Referenced by: '<S7>/Saturation1'

  real_T Constant_Value_ik;            // Expression: 1100
                                          //  Referenced by: '<S7>/Constant'

  real_T IDLEPWM_Value_c;              // Expression: 1100
                                          //  Referenced by: '<S8>/IDLE PWM'

  real_T Gain_Gain_n;                  // Expression: 0.01
                                          //  Referenced by: '<S8>/Gain'

  real_T Saturation1_UpperSat_g;       // Expression: 1
                                          //  Referenced by: '<S8>/Saturation1'

  real_T Saturation1_LowerSat_k;       // Expression: 0
                                          //  Referenced by: '<S8>/Saturation1'

  real_T Constant_Value_c;             // Expression: 1100
                                          //  Referenced by: '<S8>/Constant'

  real_T IDLEPWM_Value_o;              // Expression: 1100
                                          //  Referenced by: '<S9>/IDLE PWM'

  real_T Gain_Gain_g;                  // Expression: 0.01
                                          //  Referenced by: '<S9>/Gain'

  real_T Saturation1_UpperSat_h;       // Expression: 1
                                          //  Referenced by: '<S9>/Saturation1'

  real_T Saturation1_LowerSat_i;       // Expression: 0
                                          //  Referenced by: '<S9>/Saturation1'

  real_T Constant_Value_g1;            // Expression: 1100
                                          //  Referenced by: '<S9>/Constant'

  real_T IDLEPWM_Value_h;              // Expression: 1100
                                          //  Referenced by: '<S10>/IDLE PWM'

  real_T Gain_Gain_ni;                 // Expression: 0.01
                                          //  Referenced by: '<S10>/Gain'

  real_T Saturation1_UpperSat_h1;      // Expression: 1
                                          //  Referenced by: '<S10>/Saturation1'

  real_T Saturation1_LowerSat_bv;      // Expression: 0
                                          //  Referenced by: '<S10>/Saturation1'

  real_T Constant_Value_gp;            // Expression: 1100
                                          //  Referenced by: '<S10>/Constant'

  real_T IDLEPWM_Value_n;              // Expression: 1100
                                          //  Referenced by: '<S11>/IDLE PWM'

  real_T Gain_Gain_i4;                 // Expression: 0.01
                                          //  Referenced by: '<S11>/Gain'

  real_T Saturation1_UpperSat_a;       // Expression: 1
                                          //  Referenced by: '<S11>/Saturation1'

  real_T Saturation1_LowerSat_p;       // Expression: 0
                                          //  Referenced by: '<S11>/Saturation1'

  real_T Constant_Value_fa;            // Expression: 1100
                                          //  Referenced by: '<S11>/Constant'

  real_T IDLEPWM_Value_l;              // Expression: 1100
                                          //  Referenced by: '<S12>/IDLE PWM'

  real_T Gain_Gain_ly;                 // Expression: 0.01
                                          //  Referenced by: '<S12>/Gain'

  real_T Saturation1_UpperSat_k;       // Expression: 1
                                          //  Referenced by: '<S12>/Saturation1'

  real_T Saturation1_LowerSat_h;       // Expression: 0
                                          //  Referenced by: '<S12>/Saturation1'

  real_T Constant_Value_cc;            // Expression: 1100
                                          //  Referenced by: '<S12>/Constant'

  uint64_T Constant7_Value;            // Computed Parameter: Constant7_Value
                                          //  Referenced by: '<S53>/Constant7'

  real32_T Constant1_Value_dr[2];      // Computed Parameter: Constant1_Value_dr
                                          //  Referenced by: '<S60>/Constant1'

  real32_T Constant_Value_f2;          // Computed Parameter: Constant_Value_f2
                                          //  Referenced by: '<S60>/Constant'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S59>/Gain'

  real32_T Constant1_Value_k4[2];      // Computed Parameter: Constant1_Value_k4
                                          //  Referenced by: '<S59>/Constant1'

  real32_T Constant_Value_l4;          // Computed Parameter: Constant_Value_l4
                                          //  Referenced by: '<S59>/Constant'

  real32_T Constant_Value_fh[3];       // Computed Parameter: Constant_Value_fh
                                          //  Referenced by: '<S53>/Constant'

  real32_T Constant1_Value_h[3];       // Computed Parameter: Constant1_Value_h
                                          //  Referenced by: '<S53>/Constant1'

  real32_T Constant2_Value_f[3];       // Computed Parameter: Constant2_Value_f
                                          //  Referenced by: '<S53>/Constant2'

  real32_T Constant3_Value_al;         // Computed Parameter: Constant3_Value_al
                                          //  Referenced by: '<S53>/Constant3'

  real32_T Constant4_Value_g;          // Computed Parameter: Constant4_Value_g
                                          //  Referenced by: '<S53>/Constant4'

  uint16_T Saturation_UpperSat_g;   // Computed Parameter: Saturation_UpperSat_g
                                       //  Referenced by: '<S5>/Saturation'

  uint16_T Saturation_LowerSat_j;   // Computed Parameter: Saturation_LowerSat_j
                                       //  Referenced by: '<S5>/Saturation'

  boolean_T Constant5_Value_j;         // Computed Parameter: Constant5_Value_j
                                          //  Referenced by: '<S51>/Constant5'

  boolean_T Constant5_Value_k;         // Computed Parameter: Constant5_Value_k
                                          //  Referenced by: '<S52>/Constant5'

  boolean_T Constant1_Value_dl;        // Computed Parameter: Constant1_Value_dl
                                          //  Referenced by: '<S54>/Constant1'

  boolean_T Constant5_Value_h;         // Computed Parameter: Constant5_Value_h
                                          //  Referenced by: '<S54>/Constant5'

  boolean_T Constant5_Value_l;         // Computed Parameter: Constant5_Value_l
                                          //  Referenced by: '<S53>/Constant5'

  boolean_T Constant1_Value_ct;        // Expression: false
                                          //  Referenced by: '<S5>/Constant1'

  int8_T Constant_Value_k;             // Computed Parameter: Constant_Value_k
                                          //  Referenced by: '<S99>/Constant'

  int8_T Constant2_Value_j;            // Computed Parameter: Constant2_Value_j
                                          //  Referenced by: '<S99>/Constant2'

  int8_T Constant3_Value_l;            // Computed Parameter: Constant3_Value_l
                                          //  Referenced by: '<S99>/Constant3'

  int8_T Constant4_Value_o;            // Computed Parameter: Constant4_Value_o
                                          //  Referenced by: '<S99>/Constant4'

  int8_T Constant_Value_bd;            // Computed Parameter: Constant_Value_bd
                                          //  Referenced by: '<S151>/Constant'

  int8_T Constant2_Value_fs;           // Computed Parameter: Constant2_Value_fs
                                          //  Referenced by: '<S151>/Constant2'

  int8_T Constant3_Value_n;            // Computed Parameter: Constant3_Value_n
                                          //  Referenced by: '<S151>/Constant3'

  int8_T Constant4_Value_n;            // Computed Parameter: Constant4_Value_n
                                          //  Referenced by: '<S151>/Constant4'

  int8_T Constant_Value_a;             // Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<S203>/Constant'

  int8_T Constant2_Value_p;            // Computed Parameter: Constant2_Value_p
                                          //  Referenced by: '<S203>/Constant2'

  int8_T Constant3_Value_b;            // Computed Parameter: Constant3_Value_b
                                          //  Referenced by: '<S203>/Constant3'

  int8_T Constant4_Value_l;            // Computed Parameter: Constant4_Value_l
                                          //  Referenced by: '<S203>/Constant4'

  int8_T Constant_Value_nq;            // Computed Parameter: Constant_Value_nq
                                          //  Referenced by: '<S514>/Constant'

  int8_T Constant2_Value_o;            // Computed Parameter: Constant2_Value_o
                                          //  Referenced by: '<S514>/Constant2'

  int8_T Constant3_Value_o;            // Computed Parameter: Constant3_Value_o
                                          //  Referenced by: '<S514>/Constant3'

  int8_T Constant4_Value_d;            // Computed Parameter: Constant4_Value_d
                                          //  Referenced by: '<S514>/Constant4'

  int8_T Constant_Value_d3;            // Computed Parameter: Constant_Value_d3
                                          //  Referenced by: '<S566>/Constant'

  int8_T Constant2_Value_pb;           // Computed Parameter: Constant2_Value_pb
                                          //  Referenced by: '<S566>/Constant2'

  int8_T Constant3_Value_m;            // Computed Parameter: Constant3_Value_m
                                          //  Referenced by: '<S566>/Constant3'

  int8_T Constant4_Value_c;            // Computed Parameter: Constant4_Value_c
                                          //  Referenced by: '<S566>/Constant4'

  uint8_T ManualSwitch1_CurrentSetting;
                             // Computed Parameter: ManualSwitch1_CurrentSetting
                                //  Referenced by: '<S6>/Manual Switch1'

  uint8_T ManualSwitch2_CurrentSetting;
                             // Computed Parameter: ManualSwitch2_CurrentSetting
                                //  Referenced by: '<S6>/Manual Switch2'

  uint8_T ManualSwitch3_CurrentSetting;
                             // Computed Parameter: ManualSwitch3_CurrentSetting
                                //  Referenced by: '<S6>/Manual Switch3'

  uint8_T ManualSwitch4_CurrentSetting;
                             // Computed Parameter: ManualSwitch4_CurrentSetting
                                //  Referenced by: '<S6>/Manual Switch4'

  uint8_T ManualSwitch5_CurrentSetting;
                             // Computed Parameter: ManualSwitch5_CurrentSetting
                                //  Referenced by: '<S6>/Manual Switch5'

  uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<S6>/Manual Switch'

  uint8_T Constant_Value_fm;           // Computed Parameter: Constant_Value_fm
                                          //  Referenced by: '<S45>/Constant'

  uint8_T Constant6_Value;             // Computed Parameter: Constant6_Value
                                          //  Referenced by: '<S53>/Constant6'

};

// Real-time Model Data Structure
struct tag_RTM_Hexacopter_ControllerWithNavigation_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_Hexacopter_ControllerWithNavigation_T
    Hexacopter_ControllerWithNavigation_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_Hexacopter_ControllerWithNavigation_T
    Hexacopter_ControllerWithNavigation_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_Hexacopter_ControllerWithNavigation_T
  Hexacopter_ControllerWithNavigation_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void Hexacopter_ControllerWithNavigation_initialize(void);
  extern void Hexacopter_ControllerWithNavigation_step(void);
  extern void Hexacopter_ControllerWithNavigation_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_Hexacopter_ControllerWithNavigation_T *const
    Hexacopter_ControllerWithNavigation_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S6>/Scope' : Unused code path elimination
//  Block '<S14>/NOT' : Unused code path elimination
//  Block '<S15>/NOT' : Unused code path elimination
//  Block '<S16>/Bitwise Operator' : Unused code path elimination
//  Block '<S16>/Data Type Conversion' : Unused code path elimination
//  Block '<S16>/Data Type Conversion1' : Unused code path elimination
//  Block '<S16>/Data Type Conversion2' : Unused code path elimination
//  Block '<S16>/Gain' : Unused code path elimination
//  Block '<S16>/Gain1' : Unused code path elimination
//  Block '<S21>/NOT' : Unused code path elimination
//  Block '<S17>/NOT' : Unused code path elimination
//  Block '<S18>/NOT' : Unused code path elimination
//  Block '<S48>/Compare' : Unused code path elimination
//  Block '<S48>/Constant' : Unused code path elimination
//  Block '<S49>/NOT' : Unused code path elimination
//  Block '<S44>/Subtract' : Unused code path elimination
//  Block '<S46>/NOT' : Unused code path elimination
//  Block '<S47>/NOT' : Unused code path elimination
//  Block '<S338>/Data Type Duplicate' : Unused code path elimination
//  Block '<S338>/Data Type Propagation' : Unused code path elimination
//  Block '<S30>/Reshape1' : Reshape block reduction
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
//  '<Root>' : 'Hexacopter_ControllerWithNavigation'
//  '<S1>'   : 'Hexacopter_ControllerWithNavigation/Actuator'
//  '<S2>'   : 'Hexacopter_ControllerWithNavigation/Estimator Output'
//  '<S3>'   : 'Hexacopter_ControllerWithNavigation/Navigation'
//  '<S4>'   : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller'
//  '<S5>'   : 'Hexacopter_ControllerWithNavigation/Actuator/Custom Mixer and PWM Output Block'
//  '<S6>'   : 'Hexacopter_ControllerWithNavigation/Actuator/Custom Mixer and PWM Output Block/Fault_Injection'
//  '<S7>'   : 'Hexacopter_ControllerWithNavigation/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM'
//  '<S8>'   : 'Hexacopter_ControllerWithNavigation/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM1'
//  '<S9>'   : 'Hexacopter_ControllerWithNavigation/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM2'
//  '<S10>'  : 'Hexacopter_ControllerWithNavigation/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM3'
//  '<S11>'  : 'Hexacopter_ControllerWithNavigation/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM4'
//  '<S12>'  : 'Hexacopter_ControllerWithNavigation/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM5'
//  '<S13>'  : 'Hexacopter_ControllerWithNavigation/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Compare To Constant'
//  '<S14>'  : 'Hexacopter_ControllerWithNavigation/Estimator Output/PX4 uORB Read1'
//  '<S15>'  : 'Hexacopter_ControllerWithNavigation/Estimator Output/PX4 uORB Read2'
//  '<S16>'  : 'Hexacopter_ControllerWithNavigation/Estimator Output/Radio Control Transmitter'
//  '<S17>'  : 'Hexacopter_ControllerWithNavigation/Estimator Output/vehicle_attitude'
//  '<S18>'  : 'Hexacopter_ControllerWithNavigation/Estimator Output/vehicle_local_pos'
//  '<S19>'  : 'Hexacopter_ControllerWithNavigation/Estimator Output/PX4 uORB Read1/Enabled Subsystem'
//  '<S20>'  : 'Hexacopter_ControllerWithNavigation/Estimator Output/PX4 uORB Read2/Enabled Subsystem'
//  '<S21>'  : 'Hexacopter_ControllerWithNavigation/Estimator Output/Radio Control Transmitter/PX4 uORB Read'
//  '<S22>'  : 'Hexacopter_ControllerWithNavigation/Estimator Output/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S23>'  : 'Hexacopter_ControllerWithNavigation/Estimator Output/vehicle_attitude/Enabled Subsystem'
//  '<S24>'  : 'Hexacopter_ControllerWithNavigation/Estimator Output/vehicle_local_pos/Enabled Subsystem'
//  '<S25>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm'
//  '<S26>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission'
//  '<S27>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem'
//  '<S28>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC'
//  '<S29>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE'
//  '<S30>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land'
//  '<S31>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off'
//  '<S32>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint'
//  '<S33>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE'
//  '<S34>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE/Enabled Subsystem2'
//  '<S35>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land'
//  '<S36>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land'
//  '<S37>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land/Enabled Subsystem'
//  '<S38>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land/Enabled Subsystem2'
//  '<S39>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Ensure smooth ascend during Takeoff'
//  '<S40>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff'
//  '<S41>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff/Enabled Subsystem2'
//  '<S42>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning'
//  '<S43>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning/Compare To Constant'
//  '<S44>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC'
//  '<S45>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC'
//  '<S46>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead'
//  '<S47>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead'
//  '<S48>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/Compare To Constant'
//  '<S49>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read'
//  '<S50>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read/Enabled Subsystem'
//  '<S51>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint'
//  '<S52>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_WayPoint'
//  '<S53>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Empty_WayPoint'
//  '<S54>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Next_WayPoint'
//  '<S55>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Message'
//  '<S56>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Write'
//  '<S57>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP'
//  '<S58>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem'
//  '<S59>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem1'
//  '<S60>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem2'
//  '<S61>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead/Enabled Subsystem'
//  '<S62>'  : 'Hexacopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead/Enabled Subsystem'
//  '<S63>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller'
//  '<S64>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Chart'
//  '<S65>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/PWM2CMD'
//  '<S66>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller'
//  '<S67>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Quaternion Validity Check'
//  '<S68>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Quaternions to Rotation Angles'
//  '<S69>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller'
//  '<S70>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1'
//  '<S71>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2'
//  '<S72>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3'
//  '<S73>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4'
//  '<S74>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Anti-windup'
//  '<S75>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/D Gain'
//  '<S76>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/External Derivative'
//  '<S77>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Filter'
//  '<S78>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Filter ICs'
//  '<S79>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/I Gain'
//  '<S80>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Ideal P Gain'
//  '<S81>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Ideal P Gain Fdbk'
//  '<S82>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Integrator'
//  '<S83>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Integrator ICs'
//  '<S84>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/N Copy'
//  '<S85>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/N Gain'
//  '<S86>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/P Copy'
//  '<S87>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Parallel P Gain'
//  '<S88>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Reset Signal'
//  '<S89>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Saturation'
//  '<S90>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Saturation Fdbk'
//  '<S91>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Sum'
//  '<S92>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Sum Fdbk'
//  '<S93>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Tracking Mode'
//  '<S94>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Tracking Mode Sum'
//  '<S95>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Tsamp - Integral'
//  '<S96>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Tsamp - Ngain'
//  '<S97>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/postSat Signal'
//  '<S98>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/preSat Signal'
//  '<S99>'  : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S100>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S101>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S102>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/D Gain/Internal Parameters'
//  '<S103>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/External Derivative/Error'
//  '<S104>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S105>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S106>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/I Gain/Internal Parameters'
//  '<S107>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S108>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S109>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Integrator/Discrete'
//  '<S110>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Integrator ICs/Internal IC'
//  '<S111>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/N Copy/Disabled'
//  '<S112>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/N Gain/Internal Parameters'
//  '<S113>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/P Copy/Disabled'
//  '<S114>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S115>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Reset Signal/Disabled'
//  '<S116>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Saturation/Enabled'
//  '<S117>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S118>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Sum/Sum_PID'
//  '<S119>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Sum Fdbk/Disabled'
//  '<S120>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Tracking Mode/Disabled'
//  '<S121>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S122>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S123>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S124>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/postSat Signal/Forward_Path'
//  '<S125>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller/preSat Signal/Forward_Path'
//  '<S126>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Anti-windup'
//  '<S127>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/D Gain'
//  '<S128>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/External Derivative'
//  '<S129>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Filter'
//  '<S130>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Filter ICs'
//  '<S131>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/I Gain'
//  '<S132>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Ideal P Gain'
//  '<S133>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S134>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Integrator'
//  '<S135>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Integrator ICs'
//  '<S136>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/N Copy'
//  '<S137>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/N Gain'
//  '<S138>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/P Copy'
//  '<S139>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Parallel P Gain'
//  '<S140>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Reset Signal'
//  '<S141>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Saturation'
//  '<S142>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Saturation Fdbk'
//  '<S143>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Sum'
//  '<S144>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Sum Fdbk'
//  '<S145>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Tracking Mode'
//  '<S146>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Tracking Mode Sum'
//  '<S147>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Tsamp - Integral'
//  '<S148>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Tsamp - Ngain'
//  '<S149>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/postSat Signal'
//  '<S150>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/preSat Signal'
//  '<S151>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S152>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S153>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S154>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/D Gain/Internal Parameters'
//  '<S155>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/External Derivative/Error'
//  '<S156>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S157>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S158>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/I Gain/Internal Parameters'
//  '<S159>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S160>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S161>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Integrator/Discrete'
//  '<S162>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Integrator ICs/Internal IC'
//  '<S163>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/N Copy/Disabled'
//  '<S164>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/N Gain/Internal Parameters'
//  '<S165>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/P Copy/Disabled'
//  '<S166>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S167>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Reset Signal/Disabled'
//  '<S168>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Saturation/Enabled'
//  '<S169>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S170>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Sum/Sum_PID'
//  '<S171>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S172>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Tracking Mode/Disabled'
//  '<S173>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S174>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S175>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S176>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S177>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S178>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Anti-windup'
//  '<S179>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/D Gain'
//  '<S180>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/External Derivative'
//  '<S181>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Filter'
//  '<S182>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Filter ICs'
//  '<S183>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/I Gain'
//  '<S184>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Ideal P Gain'
//  '<S185>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Ideal P Gain Fdbk'
//  '<S186>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Integrator'
//  '<S187>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Integrator ICs'
//  '<S188>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/N Copy'
//  '<S189>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/N Gain'
//  '<S190>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/P Copy'
//  '<S191>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Parallel P Gain'
//  '<S192>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Reset Signal'
//  '<S193>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Saturation'
//  '<S194>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Saturation Fdbk'
//  '<S195>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Sum'
//  '<S196>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Sum Fdbk'
//  '<S197>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Tracking Mode'
//  '<S198>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Tracking Mode Sum'
//  '<S199>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Tsamp - Integral'
//  '<S200>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Tsamp - Ngain'
//  '<S201>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/postSat Signal'
//  '<S202>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/preSat Signal'
//  '<S203>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S204>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S205>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S206>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/D Gain/Internal Parameters'
//  '<S207>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/External Derivative/Error'
//  '<S208>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S209>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S210>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/I Gain/Internal Parameters'
//  '<S211>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Ideal P Gain/Passthrough'
//  '<S212>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S213>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Integrator/Discrete'
//  '<S214>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Integrator ICs/Internal IC'
//  '<S215>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/N Copy/Disabled'
//  '<S216>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/N Gain/Internal Parameters'
//  '<S217>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/P Copy/Disabled'
//  '<S218>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S219>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Reset Signal/Disabled'
//  '<S220>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Saturation/Enabled'
//  '<S221>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Saturation Fdbk/Disabled'
//  '<S222>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Sum/Sum_PID'
//  '<S223>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Sum Fdbk/Disabled'
//  '<S224>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Tracking Mode/Disabled'
//  '<S225>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S226>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S227>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S228>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/postSat Signal/Forward_Path'
//  '<S229>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller2/preSat Signal/Forward_Path'
//  '<S230>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Anti-windup'
//  '<S231>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/D Gain'
//  '<S232>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/External Derivative'
//  '<S233>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Filter'
//  '<S234>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Filter ICs'
//  '<S235>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/I Gain'
//  '<S236>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Ideal P Gain'
//  '<S237>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Ideal P Gain Fdbk'
//  '<S238>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Integrator'
//  '<S239>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Integrator ICs'
//  '<S240>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/N Copy'
//  '<S241>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/N Gain'
//  '<S242>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/P Copy'
//  '<S243>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Parallel P Gain'
//  '<S244>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Reset Signal'
//  '<S245>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Saturation'
//  '<S246>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Saturation Fdbk'
//  '<S247>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Sum'
//  '<S248>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Sum Fdbk'
//  '<S249>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Tracking Mode'
//  '<S250>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Tracking Mode Sum'
//  '<S251>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Tsamp - Integral'
//  '<S252>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Tsamp - Ngain'
//  '<S253>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/postSat Signal'
//  '<S254>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/preSat Signal'
//  '<S255>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Anti-windup/Disabled'
//  '<S256>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/D Gain/Disabled'
//  '<S257>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/External Derivative/Disabled'
//  '<S258>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Filter/Disabled'
//  '<S259>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Filter ICs/Disabled'
//  '<S260>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/I Gain/Disabled'
//  '<S261>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Ideal P Gain/Passthrough'
//  '<S262>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S263>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Integrator/Disabled'
//  '<S264>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Integrator ICs/Disabled'
//  '<S265>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S266>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/N Gain/Disabled'
//  '<S267>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/P Copy/Disabled'
//  '<S268>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S269>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Reset Signal/Disabled'
//  '<S270>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Saturation/Passthrough'
//  '<S271>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Saturation Fdbk/Disabled'
//  '<S272>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Sum/Passthrough_P'
//  '<S273>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Sum Fdbk/Disabled'
//  '<S274>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Tracking Mode/Disabled'
//  '<S275>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S276>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S277>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S278>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/postSat Signal/Forward_Path'
//  '<S279>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller3/preSat Signal/Forward_Path'
//  '<S280>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Anti-windup'
//  '<S281>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/D Gain'
//  '<S282>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/External Derivative'
//  '<S283>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Filter'
//  '<S284>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Filter ICs'
//  '<S285>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/I Gain'
//  '<S286>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Ideal P Gain'
//  '<S287>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S288>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Integrator'
//  '<S289>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Integrator ICs'
//  '<S290>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/N Copy'
//  '<S291>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/N Gain'
//  '<S292>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/P Copy'
//  '<S293>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Parallel P Gain'
//  '<S294>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Reset Signal'
//  '<S295>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Saturation'
//  '<S296>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Saturation Fdbk'
//  '<S297>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Sum'
//  '<S298>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Sum Fdbk'
//  '<S299>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Tracking Mode'
//  '<S300>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Tracking Mode Sum'
//  '<S301>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Tsamp - Integral'
//  '<S302>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Tsamp - Ngain'
//  '<S303>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/postSat Signal'
//  '<S304>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/preSat Signal'
//  '<S305>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Anti-windup/Disabled'
//  '<S306>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/D Gain/Disabled'
//  '<S307>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/External Derivative/Disabled'
//  '<S308>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Filter/Disabled'
//  '<S309>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Filter ICs/Disabled'
//  '<S310>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/I Gain/Disabled'
//  '<S311>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S312>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S313>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Integrator/Disabled'
//  '<S314>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Integrator ICs/Disabled'
//  '<S315>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S316>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/N Gain/Disabled'
//  '<S317>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/P Copy/Disabled'
//  '<S318>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S319>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Reset Signal/Disabled'
//  '<S320>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Saturation/Passthrough'
//  '<S321>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S322>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Sum/Passthrough_P'
//  '<S323>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S324>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Tracking Mode/Disabled'
//  '<S325>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S326>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S327>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S328>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S329>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Attitude controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S330>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/Altitude Signal conditioning'
//  '<S331>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/Calculate Transformation Matrix'
//  '<S332>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/Calculate minimum Turn'
//  '<S333>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller'
//  '<S334>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1'
//  '<S335>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5'
//  '<S336>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude'
//  '<S337>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz'
//  '<S338>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/Altitude Signal conditioning/Saturation Dynamic'
//  '<S339>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Anti-windup'
//  '<S340>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/D Gain'
//  '<S341>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/External Derivative'
//  '<S342>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Filter'
//  '<S343>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Filter ICs'
//  '<S344>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/I Gain'
//  '<S345>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Ideal P Gain'
//  '<S346>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Ideal P Gain Fdbk'
//  '<S347>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Integrator'
//  '<S348>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Integrator ICs'
//  '<S349>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/N Copy'
//  '<S350>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/N Gain'
//  '<S351>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/P Copy'
//  '<S352>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Parallel P Gain'
//  '<S353>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Reset Signal'
//  '<S354>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Saturation'
//  '<S355>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Saturation Fdbk'
//  '<S356>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Sum'
//  '<S357>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Sum Fdbk'
//  '<S358>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Tracking Mode'
//  '<S359>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Tracking Mode Sum'
//  '<S360>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Tsamp - Integral'
//  '<S361>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Tsamp - Ngain'
//  '<S362>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/postSat Signal'
//  '<S363>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/preSat Signal'
//  '<S364>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Anti-windup/Disabled'
//  '<S365>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/D Gain/Disabled'
//  '<S366>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/External Derivative/Disabled'
//  '<S367>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Filter/Disabled'
//  '<S368>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Filter ICs/Disabled'
//  '<S369>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/I Gain/Disabled'
//  '<S370>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S371>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S372>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Integrator/Disabled'
//  '<S373>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Integrator ICs/Disabled'
//  '<S374>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S375>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/N Gain/Disabled'
//  '<S376>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/P Copy/Disabled'
//  '<S377>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S378>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Reset Signal/Disabled'
//  '<S379>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Saturation/Enabled'
//  '<S380>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S381>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Sum/Passthrough_P'
//  '<S382>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Sum Fdbk/Disabled'
//  '<S383>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Tracking Mode/Disabled'
//  '<S384>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S385>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S386>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S387>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/postSat Signal/Forward_Path'
//  '<S388>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller/preSat Signal/Forward_Path'
//  '<S389>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Anti-windup'
//  '<S390>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/D Gain'
//  '<S391>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/External Derivative'
//  '<S392>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Filter'
//  '<S393>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Filter ICs'
//  '<S394>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/I Gain'
//  '<S395>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Ideal P Gain'
//  '<S396>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S397>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Integrator'
//  '<S398>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Integrator ICs'
//  '<S399>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/N Copy'
//  '<S400>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/N Gain'
//  '<S401>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/P Copy'
//  '<S402>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Parallel P Gain'
//  '<S403>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Reset Signal'
//  '<S404>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Saturation'
//  '<S405>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Saturation Fdbk'
//  '<S406>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Sum'
//  '<S407>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Sum Fdbk'
//  '<S408>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tracking Mode'
//  '<S409>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tracking Mode Sum'
//  '<S410>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tsamp - Integral'
//  '<S411>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tsamp - Ngain'
//  '<S412>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/postSat Signal'
//  '<S413>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/preSat Signal'
//  '<S414>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Anti-windup/Disabled'
//  '<S415>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/D Gain/Disabled'
//  '<S416>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/External Derivative/Disabled'
//  '<S417>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Filter/Disabled'
//  '<S418>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Filter ICs/Disabled'
//  '<S419>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/I Gain/Disabled'
//  '<S420>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S421>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S422>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Integrator/Disabled'
//  '<S423>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Integrator ICs/Disabled'
//  '<S424>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S425>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/N Gain/Disabled'
//  '<S426>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/P Copy/Disabled'
//  '<S427>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S428>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Reset Signal/Disabled'
//  '<S429>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Saturation/Enabled'
//  '<S430>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S431>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Sum/Passthrough_P'
//  '<S432>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S433>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tracking Mode/Disabled'
//  '<S434>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S435>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S436>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S437>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S438>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S439>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Anti-windup'
//  '<S440>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/D Gain'
//  '<S441>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/External Derivative'
//  '<S442>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Filter'
//  '<S443>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Filter ICs'
//  '<S444>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/I Gain'
//  '<S445>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Ideal P Gain'
//  '<S446>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Ideal P Gain Fdbk'
//  '<S447>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Integrator'
//  '<S448>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Integrator ICs'
//  '<S449>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/N Copy'
//  '<S450>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/N Gain'
//  '<S451>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/P Copy'
//  '<S452>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Parallel P Gain'
//  '<S453>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Reset Signal'
//  '<S454>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Saturation'
//  '<S455>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Saturation Fdbk'
//  '<S456>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Sum'
//  '<S457>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Sum Fdbk'
//  '<S458>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tracking Mode'
//  '<S459>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tracking Mode Sum'
//  '<S460>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tsamp - Integral'
//  '<S461>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tsamp - Ngain'
//  '<S462>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/postSat Signal'
//  '<S463>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/preSat Signal'
//  '<S464>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Anti-windup/Disabled'
//  '<S465>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/D Gain/Disabled'
//  '<S466>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/External Derivative/Disabled'
//  '<S467>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Filter/Disabled'
//  '<S468>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Filter ICs/Disabled'
//  '<S469>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/I Gain/Disabled'
//  '<S470>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Ideal P Gain/Passthrough'
//  '<S471>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Ideal P Gain Fdbk/Disabled'
//  '<S472>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Integrator/Disabled'
//  '<S473>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Integrator ICs/Disabled'
//  '<S474>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/N Copy/Disabled wSignal Specification'
//  '<S475>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/N Gain/Disabled'
//  '<S476>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/P Copy/Disabled'
//  '<S477>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Parallel P Gain/Internal Parameters'
//  '<S478>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Reset Signal/Disabled'
//  '<S479>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Saturation/Enabled'
//  '<S480>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Saturation Fdbk/Disabled'
//  '<S481>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Sum/Passthrough_P'
//  '<S482>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Sum Fdbk/Disabled'
//  '<S483>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tracking Mode/Disabled'
//  '<S484>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tracking Mode Sum/Passthrough'
//  '<S485>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tsamp - Integral/TsSignalSpecification'
//  '<S486>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tsamp - Ngain/Passthrough'
//  '<S487>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/postSat Signal/Forward_Path'
//  '<S488>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID Controller5/preSat Signal/Forward_Path'
//  '<S489>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Anti-windup'
//  '<S490>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/D Gain'
//  '<S491>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/External Derivative'
//  '<S492>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Filter'
//  '<S493>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Filter ICs'
//  '<S494>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/I Gain'
//  '<S495>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain'
//  '<S496>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S497>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Integrator'
//  '<S498>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Integrator ICs'
//  '<S499>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/N Copy'
//  '<S500>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/N Gain'
//  '<S501>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/P Copy'
//  '<S502>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Parallel P Gain'
//  '<S503>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Reset Signal'
//  '<S504>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Saturation'
//  '<S505>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Saturation Fdbk'
//  '<S506>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Sum'
//  '<S507>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Sum Fdbk'
//  '<S508>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tracking Mode'
//  '<S509>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tracking Mode Sum'
//  '<S510>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tsamp - Integral'
//  '<S511>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tsamp - Ngain'
//  '<S512>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/postSat Signal'
//  '<S513>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/preSat Signal'
//  '<S514>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel'
//  '<S515>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S516>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S517>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/D Gain/Internal Parameters'
//  '<S518>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/External Derivative/Error'
//  '<S519>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Filter/Disc. Forward Euler Filter'
//  '<S520>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Filter ICs/Internal IC - Filter'
//  '<S521>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/I Gain/Internal Parameters'
//  '<S522>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S523>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain Fdbk/Passthrough'
//  '<S524>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Integrator/Discrete'
//  '<S525>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Integrator ICs/Internal IC'
//  '<S526>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/N Copy/Disabled'
//  '<S527>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/N Gain/Internal Parameters'
//  '<S528>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/P Copy/Disabled'
//  '<S529>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Parallel P Gain/Internal Parameters'
//  '<S530>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Reset Signal/Disabled'
//  '<S531>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Saturation/Enabled'
//  '<S532>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Saturation Fdbk/Passthrough'
//  '<S533>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Sum/Sum_PID'
//  '<S534>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Sum Fdbk/Enabled'
//  '<S535>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S536>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S537>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S538>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S539>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/postSat Signal/Feedback_Path'
//  '<S540>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_Altitude/preSat Signal/Feedback_Path'
//  '<S541>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Anti-windup'
//  '<S542>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/D Gain'
//  '<S543>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/External Derivative'
//  '<S544>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Filter'
//  '<S545>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Filter ICs'
//  '<S546>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/I Gain'
//  '<S547>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Ideal P Gain'
//  '<S548>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Ideal P Gain Fdbk'
//  '<S549>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Integrator'
//  '<S550>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Integrator ICs'
//  '<S551>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/N Copy'
//  '<S552>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/N Gain'
//  '<S553>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/P Copy'
//  '<S554>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Parallel P Gain'
//  '<S555>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Reset Signal'
//  '<S556>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Saturation'
//  '<S557>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Saturation Fdbk'
//  '<S558>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Sum'
//  '<S559>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Sum Fdbk'
//  '<S560>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Tracking Mode'
//  '<S561>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Tracking Mode Sum'
//  '<S562>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Tsamp - Integral'
//  '<S563>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Tsamp - Ngain'
//  '<S564>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/postSat Signal'
//  '<S565>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/preSat Signal'
//  '<S566>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel'
//  '<S567>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S568>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S569>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/D Gain/Internal Parameters'
//  '<S570>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/External Derivative/Error'
//  '<S571>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Filter/Disc. Forward Euler Filter'
//  '<S572>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Filter ICs/Internal IC - Filter'
//  '<S573>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/I Gain/Internal Parameters'
//  '<S574>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Ideal P Gain/Passthrough'
//  '<S575>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Ideal P Gain Fdbk/Passthrough'
//  '<S576>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Integrator/Discrete'
//  '<S577>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Integrator ICs/Internal IC'
//  '<S578>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/N Copy/Disabled'
//  '<S579>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/N Gain/Internal Parameters'
//  '<S580>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/P Copy/Disabled'
//  '<S581>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Parallel P Gain/Internal Parameters'
//  '<S582>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Reset Signal/Disabled'
//  '<S583>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Saturation/Enabled'
//  '<S584>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Saturation Fdbk/Passthrough'
//  '<S585>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Sum/Sum_PID'
//  '<S586>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Sum Fdbk/Enabled'
//  '<S587>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Tracking Mode/Disabled'
//  '<S588>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Tracking Mode Sum/Passthrough'
//  '<S589>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Tsamp - Integral/TsSignalSpecification'
//  '<S590>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/Tsamp - Ngain/Passthrough'
//  '<S591>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/postSat Signal/Feedback_Path'
//  '<S592>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Position & Altitude controller/PID_vz/preSat Signal/Feedback_Path'
//  '<S593>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Quaternion Validity Check/Quaternion Norm'
//  '<S594>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Quaternions to Rotation Angles/Angle Calculation'
//  '<S595>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S596>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S597>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S598>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S599>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S600>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S601>' : 'Hexacopter_ControllerWithNavigation/Position & Rate Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                                // Hexacopter_ControllerWithNavigation_h_

//
// File trailer for generated code.
//
// [EOF]
//
