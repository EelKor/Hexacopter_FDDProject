//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Hexacopter_ControllerWithNavigation_ver2023b.h
//
// Code generated for Simulink model 'Hexacopter_ControllerWithNavigation_ver2023b'.
//
// Model version                  : 4.4
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Jul 27 17:27:58 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Hexacopter_ControllerWithNavigation_ver2023b_h_
#define RTW_HEADER_Hexacopter_ControllerWithNavigation_ver2023b_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "Hexacopter_ControllerWithNavigation_ver2023b_types.h"
#include <uORB/topics/vehicle_trajectory_waypoint.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/position_setpoint_triplet.h>
#include <uORB/topics/vehicle_local_position.h>
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
struct B_MATLABSystem_Hexacopter_ControllerWithNavigation_ver2023b_T {
  real32_T MATLABSystem[3];            // '<S51>/MATLAB System'
  real_T dLat;
};

// Block states (default storage) for system '<S51>/MATLAB System'
struct DW_MATLABSystem_Hexacopter_ControllerWithNavigation_ver2023b_T {
  px4_internal_block_LLA2LocalCoordinatesNED_Hexacopter_Control_T obj;// '<S51>/MATLAB System' 
  boolean_T objisempty;                // '<S51>/MATLAB System'
};

// Block signals (default storage)
struct B_Hexacopter_ControllerWithNavigation_ver2023b_T {
  px4_Bus_vehicle_trajectory_waypoint In1;// '<S50>/In1'
  px4_Bus_vehicle_trajectory_waypoint b_varargout_2;
  px4_Bus_vehicle_trajectory_waypoint BusAssignment1;// '<S45>/Bus Assignment1'
  px4_Bus_vehicle_trajectory_waypoint BusAssignment1_m;// '<S45>/Bus Assignment1' 
  px4_Bus_vehicle_odometry In1_l;      // '<S19>/In1'
  px4_Bus_vehicle_odometry b_varargout_2_c;
  px4_Bus_position_setpoint_triplet In1_p;// '<S62>/In1'
  px4_Bus_position_setpoint_triplet b_varargout_2_k;
  px4_Bus_vehicle_local_position In1_c;// '<S24>/In1'
  px4_Bus_vehicle_local_position b_varargout_2_cx;
  px4_Bus_input_rc In1_j;              // '<S22>/In1'
  px4_Bus_input_rc b_varargout_2_b;
  real_T b_waypointsIn_data[9];
  real_T MatrixConcatenate_p[9];       // '<S32>/Matrix Concatenate'
  px4_Bus_vehicle_attitude In1_m;      // '<S23>/In1'
  px4_Bus_vehicle_attitude b_varargout_2_p;
  px4_Bus_trajectory_waypoint BusAssignment1_f;// '<S53>/Bus Assignment1'
  px4_Bus_home_position In1_f;         // '<S61>/In1'
  px4_Bus_home_position b_varargout_2_cv;
  real_T b_varargout_3[3];
  real_T lla0[3];
  real_T VectorConcatenate[3];         // '<S574>/Vector Concatenate'
  real_T DataTypeConversion2[3];       // '<S2>/Data Type Conversion2'
  real_T rtb_TmpSignalConversionAtProduc[3];
  px4_Bus_actuator_armed In1_b;        // '<S20>/In1'
  px4_Bus_actuator_armed b_varargout_2_f;
  uint16_T pwmValue[8];
  real_T Saturation[2];                // '<S367>/Saturation'
  uint16_T CastToDouble[6];            // '<S6>/Cast To Double'
  real_T Gain1;                        // '<S66>/Gain1'
  real_T Saturation_a;                 // '<S463>/Saturation'
  real_T Saturation_o;                 // '<S563>/Saturation'
  real_T Saturation_n;                 // '<S114>/Saturation'
  real_T Saturation_b;                 // '<S164>/Saturation'
  real_T Saturation_a1;                // '<S214>/Saturation'
  real_T yaw_In;                       // '<S34>/yaw_In'
  real_T yaw_In_i;                     // '<S38>/yaw_In'
  real_T In;                           // '<S37>/In'
  real_T yaw_In_ik;                    // '<S41>/yaw_In'
  real_T lambda;
  real_T b;
  real_T Gain_i;                       // '<S39>/Gain'
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
  real_T rtb_VectorConcatenate_tmp_g;
  real_T rtb_VectorConcatenate_tmp_g1;
  real_T rtb_VectorConcatenate_tmp_m;
  real_T dLat;
  real_T dLon;
  real_T Rn;
  real_T flat;
  real_T b_x;
  real_T absx;
  real_T absx_n;
  real_T q;
  real_T scale;
  real_T absxk;
  real_T t;
  boolean_T x[6];
  real32_T ParamStep;
  int32_T ParamStep_p;
  int32_T ParamStep_l;
  int32_T ParamStep_j;
  int32_T ParamStep_d;
  int32_T ParamStep_g;
  int32_T i2;
  int32_T i1;
  int32_T waypoints_size_idx_0;
  int32_T b_k;
  int32_T i;
  int32_T i1_l;
  int8_T tmp_data[3];
  boolean_T distinctWptsIdx[3];
  boolean_T b_d[3];
  uint16_T status;
  boolean_T IsNaN_l[2];                // '<S30>/IsNaN'
  int8_T rtPrevAction;
  int8_T i2_d;
  boolean_T latp2;
  boolean_T Compare_f;                 // '<S13>/Compare'
  boolean_T latp2_l;
  B_MATLABSystem_Hexacopter_ControllerWithNavigation_ver2023b_T MATLABSystem_b;// '<S51>/MATLAB System' 
  B_MATLABSystem_Hexacopter_ControllerWithNavigation_ver2023b_T MATLABSystem;// '<S51>/MATLAB System' 
};

// Block states (default storage) for system '<Root>'
struct DW_Hexacopter_ControllerWithNavigation_ver2023b_T {
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
  px4_internal_block_PWM_Hexacopter_ControllerWithNavigation_ve_T obj_pk;// '<S5>/PX4 PWM Output' 
  px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T obj_kz;// '<S47>/SourceBlock' 
  px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T obj_gf;// '<S46>/SourceBlock' 
  px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T obj_e;// '<S49>/SourceBlock' 
  px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T obj_m;// '<S18>/SourceBlock' 
  px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T obj_gv;// '<S17>/SourceBlock' 
  px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T obj_ah;// '<S21>/SourceBlock' 
  px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T obj_d0;// '<S15>/SourceBlock' 
  px4_internal_block_Subscriber_Hexacopter_ControllerWithNaviga_T obj_po;// '<S14>/SourceBlock' 
  px4_internal_block_getPX4AbsoluteTime_Hexacopter_ControllerWi_T obj_n;// '<S44>/PX4 Timestamp' 
  px4_internal_block_LLA2LocalCoordinates_Hexacopter_Controller_T obj_mr;// '<S28>/LLA2LocalCoordinates' 
  px4_internal_block_Publisher_Hexacopter_ControllerWithNavigat_T obj_mc;// '<S56>/SinkBlock' 
  real_T Filter_DSTATE;                // '<S501>/Filter'
  real_T Integrator_DSTATE;            // '<S506>/Integrator'
  real_T Filter_DSTATE_o;              // '<S551>/Filter'
  real_T Integrator_DSTATE_o;          // '<S556>/Integrator'
  real_T Integrator_DSTATE_i;          // '<S107>/Integrator'
  real_T Filter_DSTATE_ov;             // '<S102>/Filter'
  real_T Integrator_DSTATE_h;          // '<S157>/Integrator'
  real_T Filter_DSTATE_c;              // '<S152>/Filter'
  real_T Integrator_DSTATE_ih;         // '<S207>/Integrator'
  real_T Filter_DSTATE_f;              // '<S202>/Filter'
  real_T Delay_DSTATE;                 // '<S33>/Delay'
  real_T Delay_DSTATE_l[2];            // '<S30>/Delay'
  real_T Delay_DSTATE_n;               // '<S35>/Delay'
  real_T Delay_DSTATE_b;               // '<S36>/Delay'
  real_T Delay_DSTATE_c;               // '<S39>/Delay'
  real_T Delay_DSTATE_d;               // '<S40>/Delay'
  real_T PrevY;                        // '<S63>/Rate Limiter2'
  real_T PrevY_l;                      // '<S63>/Rate Limiter1'
  px4_internal_block_LLA2LocalCoordinatesNED_Hexacopter_Control_T obj_mu;// '<S54>/MATLAB System' 
  int8_T If_ActiveSubsystem;           // '<S27>/If'
  uint8_T is_active_c3_Hexacopter_ControllerWithNavigation_ver2023b;// '<S4>/Chart' 
  uint8_T is_c3_Hexacopter_ControllerWithNavigation_ver2023b;// '<S4>/Chart'
  DW_MATLABSystem_Hexacopter_ControllerWithNavigation_ver2023b_T MATLABSystem_b;// '<S51>/MATLAB System' 
  DW_MATLABSystem_Hexacopter_ControllerWithNavigation_ver2023b_T MATLABSystem;// '<S51>/MATLAB System' 
};

// Parameters (default storage)
struct P_Hexacopter_ControllerWithNavigation_ver2023b_T_ {
  real_T PIDController_D;              // Mask Parameter: PIDController_D
                                          //  Referenced by: '<S101>/Derivative Gain'

  real_T PIDController1_D;             // Mask Parameter: PIDController1_D
                                          //  Referenced by: '<S151>/Derivative Gain'

  real_T PIDController2_D;             // Mask Parameter: PIDController2_D
                                          //  Referenced by: '<S201>/Derivative Gain'

  real_T PID_Altitude_D;               // Mask Parameter: PID_Altitude_D
                                          //  Referenced by: '<S500>/Derivative Gain'

  real_T PID_vz_D;                     // Mask Parameter: PID_vz_D
                                          //  Referenced by: '<S550>/Derivative Gain'

  real_T PIDController_I;              // Mask Parameter: PIDController_I
                                          //  Referenced by: '<S104>/Integral Gain'

  real_T PIDController1_I;             // Mask Parameter: PIDController1_I
                                          //  Referenced by: '<S154>/Integral Gain'

  real_T PIDController2_I;             // Mask Parameter: PIDController2_I
                                          //  Referenced by: '<S204>/Integral Gain'

  real_T PID_Altitude_I;               // Mask Parameter: PID_Altitude_I
                                          //  Referenced by: '<S503>/Integral Gain'

  real_T PID_vz_I;                     // Mask Parameter: PID_vz_I
                                          //  Referenced by: '<S553>/Integral Gain'

  real_T PIDController_InitialConditionForFilter;
                      // Mask Parameter: PIDController_InitialConditionForFilter
                         //  Referenced by: '<S102>/Filter'

  real_T PIDController1_InitialConditionForFilter;
                     // Mask Parameter: PIDController1_InitialConditionForFilter
                        //  Referenced by: '<S152>/Filter'

  real_T PIDController2_InitialConditionForFilter;
                     // Mask Parameter: PIDController2_InitialConditionForFilter
                        //  Referenced by: '<S202>/Filter'

  real_T PID_Altitude_InitialConditionForFilter;
                       // Mask Parameter: PID_Altitude_InitialConditionForFilter
                          //  Referenced by: '<S501>/Filter'

  real_T PID_vz_InitialConditionForFilter;
                             // Mask Parameter: PID_vz_InitialConditionForFilter
                                //  Referenced by: '<S551>/Filter'

  real_T PIDController_InitialConditionForIntegrator;
                  // Mask Parameter: PIDController_InitialConditionForIntegrator
                     //  Referenced by: '<S107>/Integrator'

  real_T PIDController1_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController1_InitialConditionForIntegrator
                    //  Referenced by: '<S157>/Integrator'

  real_T PIDController2_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController2_InitialConditionForIntegrator
                    //  Referenced by: '<S207>/Integrator'

  real_T PID_Altitude_InitialConditionForIntegrator;
                   // Mask Parameter: PID_Altitude_InitialConditionForIntegrator
                      //  Referenced by: '<S506>/Integrator'

  real_T PID_vz_InitialConditionForIntegrator;
                         // Mask Parameter: PID_vz_InitialConditionForIntegrator
                            //  Referenced by: '<S556>/Integrator'

  real_T PIDController_LowerSaturationLimit;
                           // Mask Parameter: PIDController_LowerSaturationLimit
                              //  Referenced by:
                              //    '<S114>/Saturation'
                              //    '<S100>/DeadZone'

  real_T PIDController1_LowerSaturationLimit;
                          // Mask Parameter: PIDController1_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S164>/Saturation'
                             //    '<S150>/DeadZone'

  real_T PIDController2_LowerSaturationLimit;
                          // Mask Parameter: PIDController2_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S214>/Saturation'
                             //    '<S200>/DeadZone'

  real_T PIDController1_LowerSaturationLimit_e;
                        // Mask Parameter: PIDController1_LowerSaturationLimit_e
                           //  Referenced by: '<S415>/Saturation'

  real_T PIDController_LowerSaturationLimit_j;
                         // Mask Parameter: PIDController_LowerSaturationLimit_j
                            //  Referenced by: '<S367>/Saturation'

  real_T PIDController5_LowerSaturationLimit;
                          // Mask Parameter: PIDController5_LowerSaturationLimit
                             //  Referenced by: '<S463>/Saturation'

  real_T PID_Altitude_LowerSaturationLimit;
                            // Mask Parameter: PID_Altitude_LowerSaturationLimit
                               //  Referenced by:
                               //    '<S513>/Saturation'
                               //    '<S499>/DeadZone'

  real_T PID_vz_LowerSaturationLimit;
                                  // Mask Parameter: PID_vz_LowerSaturationLimit
                                     //  Referenced by:
                                     //    '<S563>/Saturation'
                                     //    '<S549>/DeadZone'

  real_T PIDController_N;              // Mask Parameter: PIDController_N
                                          //  Referenced by: '<S110>/Filter Coefficient'

  real_T PIDController1_N;             // Mask Parameter: PIDController1_N
                                          //  Referenced by: '<S160>/Filter Coefficient'

  real_T PIDController2_N;             // Mask Parameter: PIDController2_N
                                          //  Referenced by: '<S210>/Filter Coefficient'

  real_T PID_Altitude_N;               // Mask Parameter: PID_Altitude_N
                                          //  Referenced by: '<S509>/Filter Coefficient'

  real_T PID_vz_N;                     // Mask Parameter: PID_vz_N
                                          //  Referenced by: '<S559>/Filter Coefficient'

  real_T PIDController_P;              // Mask Parameter: PIDController_P
                                          //  Referenced by: '<S112>/Proportional Gain'

  real_T PIDController3_P;             // Mask Parameter: PIDController3_P
                                          //  Referenced by: '<S260>/Proportional Gain'

  real_T PIDController1_P;             // Mask Parameter: PIDController1_P
                                          //  Referenced by: '<S162>/Proportional Gain'

  real_T PIDController4_P;             // Mask Parameter: PIDController4_P
                                          //  Referenced by: '<S308>/Proportional Gain'

  real_T PIDController2_P;             // Mask Parameter: PIDController2_P
                                          //  Referenced by: '<S212>/Proportional Gain'

  real_T PIDController1_P_h;           // Mask Parameter: PIDController1_P_h
                                          //  Referenced by: '<S413>/Proportional Gain'

  real_T PIDController_P_d;            // Mask Parameter: PIDController_P_d
                                          //  Referenced by: '<S365>/Proportional Gain'

  real_T PIDController5_P;             // Mask Parameter: PIDController5_P
                                          //  Referenced by: '<S461>/Proportional Gain'

  real_T PID_Altitude_P;               // Mask Parameter: PID_Altitude_P
                                          //  Referenced by: '<S511>/Proportional Gain'

  real_T PID_vz_P;                     // Mask Parameter: PID_vz_P
                                          //  Referenced by: '<S561>/Proportional Gain'

  real_T PIDController_UpperSaturationLimit;
                           // Mask Parameter: PIDController_UpperSaturationLimit
                              //  Referenced by:
                              //    '<S114>/Saturation'
                              //    '<S100>/DeadZone'

  real_T PIDController1_UpperSaturationLimit;
                          // Mask Parameter: PIDController1_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S164>/Saturation'
                             //    '<S150>/DeadZone'

  real_T PIDController2_UpperSaturationLimit;
                          // Mask Parameter: PIDController2_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S214>/Saturation'
                             //    '<S200>/DeadZone'

  real_T PIDController1_UpperSaturationLimit_l;
                        // Mask Parameter: PIDController1_UpperSaturationLimit_l
                           //  Referenced by: '<S415>/Saturation'

  real_T PIDController_UpperSaturationLimit_b;
                         // Mask Parameter: PIDController_UpperSaturationLimit_b
                            //  Referenced by: '<S367>/Saturation'

  real_T PIDController5_UpperSaturationLimit;
                          // Mask Parameter: PIDController5_UpperSaturationLimit
                             //  Referenced by: '<S463>/Saturation'

  real_T PID_Altitude_UpperSaturationLimit;
                            // Mask Parameter: PID_Altitude_UpperSaturationLimit
                               //  Referenced by:
                               //    '<S513>/Saturation'
                               //    '<S499>/DeadZone'

  real_T PID_vz_UpperSaturationLimit;
                                  // Mask Parameter: PID_vz_UpperSaturationLimit
                                     //  Referenced by:
                                     //    '<S563>/Saturation'
                                     //    '<S549>/DeadZone'

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

  px4_Bus_vehicle_odometry Out1_Y0_e;  // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S19>/Out1'

  px4_Bus_vehicle_odometry Constant_Value_n;// Computed Parameter: Constant_Value_n
                                               //  Referenced by: '<S14>/Constant'

  px4_Bus_position_setpoint_triplet Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                 //  Referenced by: '<S62>/Out1'

  px4_Bus_position_setpoint_triplet Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                        //  Referenced by: '<S47>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                              //  Referenced by: '<S24>/Out1'

  px4_Bus_vehicle_local_position Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                     //  Referenced by: '<S18>/Constant'

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
                                          //  Referenced by: '<S98>/Constant1'

  real_T Constant1_Value_c;            // Expression: 0
                                          //  Referenced by: '<S148>/Constant1'

  real_T Constant1_Value_k;            // Expression: 0
                                          //  Referenced by: '<S198>/Constant1'

  real_T Clamping_zero_Value;          // Expression: 0
                                          //  Referenced by: '<S98>/Clamping_zero'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S107>/Integrator'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S102>/Filter'

  real_T RateLimiter2_RisingLim;       // Expression: 180*pi/180
                                          //  Referenced by: '<S63>/Rate Limiter2'

  real_T RateLimiter2_FallingLim;      // Expression: -180*pi/180
                                          //  Referenced by: '<S63>/Rate Limiter2'

  real_T RateLimiter2_IC;              // Expression: 0
                                          //  Referenced by: '<S63>/Rate Limiter2'

  real_T Saturation1_UpperSat;         // Expression: 20*pi/180
                                          //  Referenced by: '<S63>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -20*pi/180
                                          //  Referenced by: '<S63>/Saturation1'

  real_T Clamping_zero_Value_e;        // Expression: 0
                                          //  Referenced by: '<S148>/Clamping_zero'

  real_T Integrator_gainval_i;       // Computed Parameter: Integrator_gainval_i
                                        //  Referenced by: '<S157>/Integrator'

  real_T Filter_gainval_e;             // Computed Parameter: Filter_gainval_e
                                          //  Referenced by: '<S152>/Filter'

  real_T RateLimiter1_RisingLim;       // Expression: 180*pi/180
                                          //  Referenced by: '<S63>/Rate Limiter1'

  real_T RateLimiter1_FallingLim;      // Expression: -180*pi/180
                                          //  Referenced by: '<S63>/Rate Limiter1'

  real_T RateLimiter1_IC;              // Expression: 0
                                          //  Referenced by: '<S63>/Rate Limiter1'

  real_T Saturation_UpperSat;          // Expression: 20*pi/180
                                          //  Referenced by: '<S63>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -20*pi/180
                                          //  Referenced by: '<S63>/Saturation'

  real_T Clamping_zero_Value_j;        // Expression: 0
                                          //  Referenced by: '<S198>/Clamping_zero'

  real_T Integrator_gainval_f;       // Computed Parameter: Integrator_gainval_f
                                        //  Referenced by: '<S207>/Integrator'

  real_T Filter_gainval_l;             // Computed Parameter: Filter_gainval_l
                                          //  Referenced by: '<S202>/Filter'

  real_T Constant_Value_ib;            // Expression: 0
                                          //  Referenced by: '<S320>/Constant'

  real_T Switch1_Threshold;            // Expression: 0
                                          //  Referenced by: '<S322>/Switch1'

  real_T des_pitch_Y0;                 // Computed Parameter: des_pitch_Y0
                                          //  Referenced by: '<S66>/des_pitch'

  real_T des_roll_Y0;                  // Computed Parameter: des_roll_Y0
                                          //  Referenced by: '<S66>/des_roll'

  real_T des_yawrate_Y0;               // Computed Parameter: des_yawrate_Y0
                                          //  Referenced by: '<S66>/des_yawrate'

  real_T tau_Thrust_Y0;                // Computed Parameter: tau_Thrust_Y0
                                          //  Referenced by: '<S66>/tau_Thrust'

  real_T Constant1_Value_l;            // Expression: 0
                                          //  Referenced by: '<S497>/Constant1'

  real_T Constant1_Value_f;            // Expression: 0
                                          //  Referenced by: '<S547>/Constant1'

  real_T Gain_Gain_o;                  // Expression: -1
                                          //  Referenced by: '<S321>/Gain'

  real_T Constant_Value_g4;            // Expression: 2*pi
                                          //  Referenced by: '<S322>/Constant'

  real_T Switch_Threshold_e;           // Expression: pi
                                          //  Referenced by: '<S322>/Switch'

  real_T Gain1_Gain_m;                 // Expression: -1
                                          //  Referenced by: '<S66>/Gain1'

  real_T Gain1_Gain_h;                 // Expression: -1
                                          //  Referenced by: '<S320>/Gain1'

  real_T Clamping_zero_Value_f;        // Expression: 0
                                          //  Referenced by: '<S497>/Clamping_zero'

  real_T Filter_gainval_i;             // Computed Parameter: Filter_gainval_i
                                          //  Referenced by: '<S501>/Filter'

  real_T Integrator_gainval_p;       // Computed Parameter: Integrator_gainval_p
                                        //  Referenced by: '<S506>/Integrator'

  real_T Clamping_zero_Value_a;        // Expression: 0
                                          //  Referenced by: '<S547>/Clamping_zero'

  real_T Filter_gainval_m;             // Computed Parameter: Filter_gainval_m
                                          //  Referenced by: '<S551>/Filter'

  real_T Integrator_gainval_k;       // Computed Parameter: Integrator_gainval_k
                                        //  Referenced by: '<S556>/Integrator'

  real_T Constant_Value_m[4];          // Expression: [1 0 0 0]
                                          //  Referenced by: '<S67>/Constant'

  real_T Constant_Value_ji;            // Expression: 1
                                          //  Referenced by: '<S577>/Constant'

  real_T Constant_Value_hi;            // Expression: 1
                                          //  Referenced by: '<S578>/Constant'

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
                                          //  Referenced by: '<S98>/Constant'

  int8_T Constant2_Value_j;            // Computed Parameter: Constant2_Value_j
                                          //  Referenced by: '<S98>/Constant2'

  int8_T Constant3_Value_l;            // Computed Parameter: Constant3_Value_l
                                          //  Referenced by: '<S98>/Constant3'

  int8_T Constant4_Value_o;            // Computed Parameter: Constant4_Value_o
                                          //  Referenced by: '<S98>/Constant4'

  int8_T Constant_Value_bd;            // Computed Parameter: Constant_Value_bd
                                          //  Referenced by: '<S148>/Constant'

  int8_T Constant2_Value_fs;           // Computed Parameter: Constant2_Value_fs
                                          //  Referenced by: '<S148>/Constant2'

  int8_T Constant3_Value_n;            // Computed Parameter: Constant3_Value_n
                                          //  Referenced by: '<S148>/Constant3'

  int8_T Constant4_Value_n;            // Computed Parameter: Constant4_Value_n
                                          //  Referenced by: '<S148>/Constant4'

  int8_T Constant_Value_a;             // Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<S198>/Constant'

  int8_T Constant2_Value_p;            // Computed Parameter: Constant2_Value_p
                                          //  Referenced by: '<S198>/Constant2'

  int8_T Constant3_Value_b;            // Computed Parameter: Constant3_Value_b
                                          //  Referenced by: '<S198>/Constant3'

  int8_T Constant4_Value_l;            // Computed Parameter: Constant4_Value_l
                                          //  Referenced by: '<S198>/Constant4'

  int8_T Constant_Value_nq;            // Computed Parameter: Constant_Value_nq
                                          //  Referenced by: '<S497>/Constant'

  int8_T Constant2_Value_o;            // Computed Parameter: Constant2_Value_o
                                          //  Referenced by: '<S497>/Constant2'

  int8_T Constant3_Value_o;            // Computed Parameter: Constant3_Value_o
                                          //  Referenced by: '<S497>/Constant3'

  int8_T Constant4_Value_d;            // Computed Parameter: Constant4_Value_d
                                          //  Referenced by: '<S497>/Constant4'

  int8_T Constant_Value_d3;            // Computed Parameter: Constant_Value_d3
                                          //  Referenced by: '<S547>/Constant'

  int8_T Constant2_Value_pb;           // Computed Parameter: Constant2_Value_pb
                                          //  Referenced by: '<S547>/Constant2'

  int8_T Constant3_Value_m;            // Computed Parameter: Constant3_Value_m
                                          //  Referenced by: '<S547>/Constant3'

  int8_T Constant4_Value_c;            // Computed Parameter: Constant4_Value_c
                                          //  Referenced by: '<S547>/Constant4'

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
struct tag_RTM_Hexacopter_ControllerWithNavigation_ver2023b_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_Hexacopter_ControllerWithNavigation_ver2023b_T
    Hexacopter_ControllerWithNavigation_ver2023b_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_Hexacopter_ControllerWithNavigation_ver2023b_T
    Hexacopter_ControllerWithNavigation_ver2023b_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_Hexacopter_ControllerWithNavigation_ver2023b_T
  Hexacopter_ControllerWithNavigation_ver2023b_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void Hexacopter_ControllerWithNavigation_ver2023b_initialize(void);
  extern void Hexacopter_ControllerWithNavigation_ver2023b_step(void);
  extern void Hexacopter_ControllerWithNavigation_ver2023b_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_Hexacopter_ControllerWithNavigation_ver2023b_T *const
    Hexacopter_ControllerWithNavigation_ver2023b_M;

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
//  Block '<S328>/Data Type Duplicate' : Unused code path elimination
//  Block '<S328>/Data Type Propagation' : Unused code path elimination
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
//  '<Root>' : 'Hexacopter_ControllerWithNavigation_ver2023b'
//  '<S1>'   : 'Hexacopter_ControllerWithNavigation_ver2023b/Actuator'
//  '<S2>'   : 'Hexacopter_ControllerWithNavigation_ver2023b/Estimator Output'
//  '<S3>'   : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation'
//  '<S4>'   : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller'
//  '<S5>'   : 'Hexacopter_ControllerWithNavigation_ver2023b/Actuator/Custom Mixer and PWM Output Block'
//  '<S6>'   : 'Hexacopter_ControllerWithNavigation_ver2023b/Actuator/Custom Mixer and PWM Output Block/Fault_Injection'
//  '<S7>'   : 'Hexacopter_ControllerWithNavigation_ver2023b/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM'
//  '<S8>'   : 'Hexacopter_ControllerWithNavigation_ver2023b/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM1'
//  '<S9>'   : 'Hexacopter_ControllerWithNavigation_ver2023b/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM2'
//  '<S10>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM3'
//  '<S11>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM4'
//  '<S12>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM5'
//  '<S13>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Compare To Constant'
//  '<S14>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Estimator Output/PX4 uORB Read1'
//  '<S15>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Estimator Output/PX4 uORB Read2'
//  '<S16>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Estimator Output/Radio Control Transmitter'
//  '<S17>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Estimator Output/vehicle_attitude'
//  '<S18>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Estimator Output/vehicle_local_pos'
//  '<S19>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Estimator Output/PX4 uORB Read1/Enabled Subsystem'
//  '<S20>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Estimator Output/PX4 uORB Read2/Enabled Subsystem'
//  '<S21>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Estimator Output/Radio Control Transmitter/PX4 uORB Read'
//  '<S22>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Estimator Output/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S23>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Estimator Output/vehicle_attitude/Enabled Subsystem'
//  '<S24>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Estimator Output/vehicle_local_pos/Enabled Subsystem'
//  '<S25>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm'
//  '<S26>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission'
//  '<S27>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem'
//  '<S28>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC'
//  '<S29>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE'
//  '<S30>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land'
//  '<S31>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off'
//  '<S32>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint'
//  '<S33>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE'
//  '<S34>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE/Enabled Subsystem2'
//  '<S35>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land'
//  '<S36>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land'
//  '<S37>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land/Enabled Subsystem'
//  '<S38>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land/Enabled Subsystem2'
//  '<S39>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Ensure smooth ascend during Takeoff'
//  '<S40>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff'
//  '<S41>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff/Enabled Subsystem2'
//  '<S42>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning'
//  '<S43>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning/Compare To Constant'
//  '<S44>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC'
//  '<S45>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC'
//  '<S46>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead'
//  '<S47>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead'
//  '<S48>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/Compare To Constant'
//  '<S49>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read'
//  '<S50>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read/Enabled Subsystem'
//  '<S51>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint'
//  '<S52>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_WayPoint'
//  '<S53>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Empty_WayPoint'
//  '<S54>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Next_WayPoint'
//  '<S55>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Message'
//  '<S56>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Write'
//  '<S57>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP'
//  '<S58>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem'
//  '<S59>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem1'
//  '<S60>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem2'
//  '<S61>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead/Enabled Subsystem'
//  '<S62>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead/Enabled Subsystem'
//  '<S63>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller'
//  '<S64>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Chart'
//  '<S65>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/PWM2CMD'
//  '<S66>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller'
//  '<S67>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Quaternion Validity Check'
//  '<S68>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Quaternions to Rotation Angles'
//  '<S69>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller'
//  '<S70>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1'
//  '<S71>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2'
//  '<S72>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3'
//  '<S73>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4'
//  '<S74>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Anti-windup'
//  '<S75>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/D Gain'
//  '<S76>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Filter'
//  '<S77>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Filter ICs'
//  '<S78>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/I Gain'
//  '<S79>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Ideal P Gain'
//  '<S80>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Ideal P Gain Fdbk'
//  '<S81>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Integrator'
//  '<S82>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Integrator ICs'
//  '<S83>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/N Copy'
//  '<S84>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/N Gain'
//  '<S85>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/P Copy'
//  '<S86>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Parallel P Gain'
//  '<S87>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Reset Signal'
//  '<S88>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Saturation'
//  '<S89>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Saturation Fdbk'
//  '<S90>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Sum'
//  '<S91>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Sum Fdbk'
//  '<S92>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Tracking Mode'
//  '<S93>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Tracking Mode Sum'
//  '<S94>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Tsamp - Integral'
//  '<S95>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Tsamp - Ngain'
//  '<S96>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/postSat Signal'
//  '<S97>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/preSat Signal'
//  '<S98>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S99>'  : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S100>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S101>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/D Gain/Internal Parameters'
//  '<S102>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S103>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S104>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/I Gain/Internal Parameters'
//  '<S105>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S106>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S107>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Integrator/Discrete'
//  '<S108>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Integrator ICs/Internal IC'
//  '<S109>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/N Copy/Disabled'
//  '<S110>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/N Gain/Internal Parameters'
//  '<S111>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/P Copy/Disabled'
//  '<S112>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S113>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Reset Signal/Disabled'
//  '<S114>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Saturation/Enabled'
//  '<S115>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S116>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Sum/Sum_PID'
//  '<S117>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Sum Fdbk/Disabled'
//  '<S118>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Tracking Mode/Disabled'
//  '<S119>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S120>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S121>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S122>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/postSat Signal/Forward_Path'
//  '<S123>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller/preSat Signal/Forward_Path'
//  '<S124>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Anti-windup'
//  '<S125>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/D Gain'
//  '<S126>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Filter'
//  '<S127>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Filter ICs'
//  '<S128>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/I Gain'
//  '<S129>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Ideal P Gain'
//  '<S130>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S131>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Integrator'
//  '<S132>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Integrator ICs'
//  '<S133>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/N Copy'
//  '<S134>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/N Gain'
//  '<S135>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/P Copy'
//  '<S136>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Parallel P Gain'
//  '<S137>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Reset Signal'
//  '<S138>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Saturation'
//  '<S139>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Saturation Fdbk'
//  '<S140>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Sum'
//  '<S141>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Sum Fdbk'
//  '<S142>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Tracking Mode'
//  '<S143>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Tracking Mode Sum'
//  '<S144>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Tsamp - Integral'
//  '<S145>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Tsamp - Ngain'
//  '<S146>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/postSat Signal'
//  '<S147>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/preSat Signal'
//  '<S148>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S149>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S150>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S151>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/D Gain/Internal Parameters'
//  '<S152>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S153>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S154>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/I Gain/Internal Parameters'
//  '<S155>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S156>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S157>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Integrator/Discrete'
//  '<S158>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Integrator ICs/Internal IC'
//  '<S159>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/N Copy/Disabled'
//  '<S160>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/N Gain/Internal Parameters'
//  '<S161>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/P Copy/Disabled'
//  '<S162>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S163>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Reset Signal/Disabled'
//  '<S164>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Saturation/Enabled'
//  '<S165>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S166>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Sum/Sum_PID'
//  '<S167>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S168>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Tracking Mode/Disabled'
//  '<S169>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S170>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S171>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S172>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S173>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S174>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Anti-windup'
//  '<S175>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/D Gain'
//  '<S176>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Filter'
//  '<S177>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Filter ICs'
//  '<S178>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/I Gain'
//  '<S179>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Ideal P Gain'
//  '<S180>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Ideal P Gain Fdbk'
//  '<S181>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Integrator'
//  '<S182>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Integrator ICs'
//  '<S183>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/N Copy'
//  '<S184>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/N Gain'
//  '<S185>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/P Copy'
//  '<S186>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Parallel P Gain'
//  '<S187>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Reset Signal'
//  '<S188>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Saturation'
//  '<S189>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Saturation Fdbk'
//  '<S190>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Sum'
//  '<S191>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Sum Fdbk'
//  '<S192>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Tracking Mode'
//  '<S193>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Tracking Mode Sum'
//  '<S194>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Tsamp - Integral'
//  '<S195>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Tsamp - Ngain'
//  '<S196>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/postSat Signal'
//  '<S197>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/preSat Signal'
//  '<S198>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S199>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S200>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S201>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/D Gain/Internal Parameters'
//  '<S202>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S203>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S204>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/I Gain/Internal Parameters'
//  '<S205>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Ideal P Gain/Passthrough'
//  '<S206>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S207>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Integrator/Discrete'
//  '<S208>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Integrator ICs/Internal IC'
//  '<S209>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/N Copy/Disabled'
//  '<S210>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/N Gain/Internal Parameters'
//  '<S211>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/P Copy/Disabled'
//  '<S212>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S213>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Reset Signal/Disabled'
//  '<S214>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Saturation/Enabled'
//  '<S215>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Saturation Fdbk/Disabled'
//  '<S216>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Sum/Sum_PID'
//  '<S217>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Sum Fdbk/Disabled'
//  '<S218>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Tracking Mode/Disabled'
//  '<S219>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S220>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S221>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S222>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/postSat Signal/Forward_Path'
//  '<S223>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller2/preSat Signal/Forward_Path'
//  '<S224>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Anti-windup'
//  '<S225>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/D Gain'
//  '<S226>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Filter'
//  '<S227>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Filter ICs'
//  '<S228>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/I Gain'
//  '<S229>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Ideal P Gain'
//  '<S230>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Ideal P Gain Fdbk'
//  '<S231>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Integrator'
//  '<S232>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Integrator ICs'
//  '<S233>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/N Copy'
//  '<S234>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/N Gain'
//  '<S235>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/P Copy'
//  '<S236>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Parallel P Gain'
//  '<S237>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Reset Signal'
//  '<S238>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Saturation'
//  '<S239>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Saturation Fdbk'
//  '<S240>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Sum'
//  '<S241>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Sum Fdbk'
//  '<S242>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Tracking Mode'
//  '<S243>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Tracking Mode Sum'
//  '<S244>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Tsamp - Integral'
//  '<S245>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Tsamp - Ngain'
//  '<S246>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/postSat Signal'
//  '<S247>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/preSat Signal'
//  '<S248>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Anti-windup/Disabled'
//  '<S249>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/D Gain/Disabled'
//  '<S250>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Filter/Disabled'
//  '<S251>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Filter ICs/Disabled'
//  '<S252>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/I Gain/Disabled'
//  '<S253>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Ideal P Gain/Passthrough'
//  '<S254>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S255>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Integrator/Disabled'
//  '<S256>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Integrator ICs/Disabled'
//  '<S257>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S258>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/N Gain/Disabled'
//  '<S259>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/P Copy/Disabled'
//  '<S260>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S261>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Reset Signal/Disabled'
//  '<S262>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Saturation/Passthrough'
//  '<S263>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Saturation Fdbk/Disabled'
//  '<S264>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Sum/Passthrough_P'
//  '<S265>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Sum Fdbk/Disabled'
//  '<S266>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Tracking Mode/Disabled'
//  '<S267>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S268>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S269>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S270>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/postSat Signal/Forward_Path'
//  '<S271>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller3/preSat Signal/Forward_Path'
//  '<S272>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Anti-windup'
//  '<S273>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/D Gain'
//  '<S274>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Filter'
//  '<S275>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Filter ICs'
//  '<S276>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/I Gain'
//  '<S277>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Ideal P Gain'
//  '<S278>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S279>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Integrator'
//  '<S280>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Integrator ICs'
//  '<S281>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/N Copy'
//  '<S282>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/N Gain'
//  '<S283>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/P Copy'
//  '<S284>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Parallel P Gain'
//  '<S285>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Reset Signal'
//  '<S286>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Saturation'
//  '<S287>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Saturation Fdbk'
//  '<S288>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Sum'
//  '<S289>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Sum Fdbk'
//  '<S290>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Tracking Mode'
//  '<S291>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Tracking Mode Sum'
//  '<S292>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Tsamp - Integral'
//  '<S293>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Tsamp - Ngain'
//  '<S294>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/postSat Signal'
//  '<S295>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/preSat Signal'
//  '<S296>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Anti-windup/Disabled'
//  '<S297>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/D Gain/Disabled'
//  '<S298>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Filter/Disabled'
//  '<S299>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Filter ICs/Disabled'
//  '<S300>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/I Gain/Disabled'
//  '<S301>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S302>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S303>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Integrator/Disabled'
//  '<S304>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Integrator ICs/Disabled'
//  '<S305>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S306>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/N Gain/Disabled'
//  '<S307>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/P Copy/Disabled'
//  '<S308>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S309>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Reset Signal/Disabled'
//  '<S310>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Saturation/Passthrough'
//  '<S311>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S312>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Sum/Passthrough_P'
//  '<S313>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S314>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Tracking Mode/Disabled'
//  '<S315>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S316>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S317>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S318>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S319>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Attitude controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S320>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/Altitude Signal conditioning'
//  '<S321>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/Calculate Transformation Matrix'
//  '<S322>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/Calculate minimum Turn'
//  '<S323>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller'
//  '<S324>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1'
//  '<S325>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5'
//  '<S326>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude'
//  '<S327>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz'
//  '<S328>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/Altitude Signal conditioning/Saturation Dynamic'
//  '<S329>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Anti-windup'
//  '<S330>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/D Gain'
//  '<S331>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Filter'
//  '<S332>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Filter ICs'
//  '<S333>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/I Gain'
//  '<S334>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Ideal P Gain'
//  '<S335>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Ideal P Gain Fdbk'
//  '<S336>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Integrator'
//  '<S337>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Integrator ICs'
//  '<S338>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/N Copy'
//  '<S339>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/N Gain'
//  '<S340>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/P Copy'
//  '<S341>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Parallel P Gain'
//  '<S342>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Reset Signal'
//  '<S343>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Saturation'
//  '<S344>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Saturation Fdbk'
//  '<S345>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Sum'
//  '<S346>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Sum Fdbk'
//  '<S347>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Tracking Mode'
//  '<S348>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Tracking Mode Sum'
//  '<S349>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Tsamp - Integral'
//  '<S350>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Tsamp - Ngain'
//  '<S351>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/postSat Signal'
//  '<S352>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/preSat Signal'
//  '<S353>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Anti-windup/Disabled'
//  '<S354>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/D Gain/Disabled'
//  '<S355>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Filter/Disabled'
//  '<S356>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Filter ICs/Disabled'
//  '<S357>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/I Gain/Disabled'
//  '<S358>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S359>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S360>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Integrator/Disabled'
//  '<S361>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Integrator ICs/Disabled'
//  '<S362>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S363>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/N Gain/Disabled'
//  '<S364>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/P Copy/Disabled'
//  '<S365>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S366>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Reset Signal/Disabled'
//  '<S367>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Saturation/Enabled'
//  '<S368>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S369>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Sum/Passthrough_P'
//  '<S370>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Sum Fdbk/Disabled'
//  '<S371>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Tracking Mode/Disabled'
//  '<S372>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S373>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S374>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S375>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/postSat Signal/Forward_Path'
//  '<S376>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller/preSat Signal/Forward_Path'
//  '<S377>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Anti-windup'
//  '<S378>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/D Gain'
//  '<S379>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Filter'
//  '<S380>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Filter ICs'
//  '<S381>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/I Gain'
//  '<S382>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Ideal P Gain'
//  '<S383>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S384>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Integrator'
//  '<S385>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Integrator ICs'
//  '<S386>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/N Copy'
//  '<S387>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/N Gain'
//  '<S388>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/P Copy'
//  '<S389>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Parallel P Gain'
//  '<S390>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Reset Signal'
//  '<S391>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Saturation'
//  '<S392>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Saturation Fdbk'
//  '<S393>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Sum'
//  '<S394>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Sum Fdbk'
//  '<S395>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tracking Mode'
//  '<S396>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tracking Mode Sum'
//  '<S397>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tsamp - Integral'
//  '<S398>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tsamp - Ngain'
//  '<S399>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/postSat Signal'
//  '<S400>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/preSat Signal'
//  '<S401>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Anti-windup/Disabled'
//  '<S402>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/D Gain/Disabled'
//  '<S403>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Filter/Disabled'
//  '<S404>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Filter ICs/Disabled'
//  '<S405>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/I Gain/Disabled'
//  '<S406>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S407>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S408>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Integrator/Disabled'
//  '<S409>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Integrator ICs/Disabled'
//  '<S410>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S411>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/N Gain/Disabled'
//  '<S412>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/P Copy/Disabled'
//  '<S413>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S414>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Reset Signal/Disabled'
//  '<S415>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Saturation/Enabled'
//  '<S416>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S417>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Sum/Passthrough_P'
//  '<S418>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S419>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tracking Mode/Disabled'
//  '<S420>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S421>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S422>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S423>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S424>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S425>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Anti-windup'
//  '<S426>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/D Gain'
//  '<S427>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Filter'
//  '<S428>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Filter ICs'
//  '<S429>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/I Gain'
//  '<S430>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Ideal P Gain'
//  '<S431>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Ideal P Gain Fdbk'
//  '<S432>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Integrator'
//  '<S433>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Integrator ICs'
//  '<S434>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/N Copy'
//  '<S435>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/N Gain'
//  '<S436>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/P Copy'
//  '<S437>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Parallel P Gain'
//  '<S438>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Reset Signal'
//  '<S439>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Saturation'
//  '<S440>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Saturation Fdbk'
//  '<S441>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Sum'
//  '<S442>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Sum Fdbk'
//  '<S443>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tracking Mode'
//  '<S444>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tracking Mode Sum'
//  '<S445>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tsamp - Integral'
//  '<S446>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tsamp - Ngain'
//  '<S447>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/postSat Signal'
//  '<S448>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/preSat Signal'
//  '<S449>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Anti-windup/Disabled'
//  '<S450>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/D Gain/Disabled'
//  '<S451>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Filter/Disabled'
//  '<S452>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Filter ICs/Disabled'
//  '<S453>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/I Gain/Disabled'
//  '<S454>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Ideal P Gain/Passthrough'
//  '<S455>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Ideal P Gain Fdbk/Disabled'
//  '<S456>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Integrator/Disabled'
//  '<S457>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Integrator ICs/Disabled'
//  '<S458>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/N Copy/Disabled wSignal Specification'
//  '<S459>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/N Gain/Disabled'
//  '<S460>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/P Copy/Disabled'
//  '<S461>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Parallel P Gain/Internal Parameters'
//  '<S462>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Reset Signal/Disabled'
//  '<S463>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Saturation/Enabled'
//  '<S464>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Saturation Fdbk/Disabled'
//  '<S465>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Sum/Passthrough_P'
//  '<S466>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Sum Fdbk/Disabled'
//  '<S467>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tracking Mode/Disabled'
//  '<S468>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tracking Mode Sum/Passthrough'
//  '<S469>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tsamp - Integral/TsSignalSpecification'
//  '<S470>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tsamp - Ngain/Passthrough'
//  '<S471>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/postSat Signal/Forward_Path'
//  '<S472>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID Controller5/preSat Signal/Forward_Path'
//  '<S473>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Anti-windup'
//  '<S474>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/D Gain'
//  '<S475>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Filter'
//  '<S476>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Filter ICs'
//  '<S477>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/I Gain'
//  '<S478>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain'
//  '<S479>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S480>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Integrator'
//  '<S481>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Integrator ICs'
//  '<S482>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/N Copy'
//  '<S483>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/N Gain'
//  '<S484>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/P Copy'
//  '<S485>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Parallel P Gain'
//  '<S486>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Reset Signal'
//  '<S487>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Saturation'
//  '<S488>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Saturation Fdbk'
//  '<S489>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Sum'
//  '<S490>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Sum Fdbk'
//  '<S491>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tracking Mode'
//  '<S492>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tracking Mode Sum'
//  '<S493>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tsamp - Integral'
//  '<S494>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tsamp - Ngain'
//  '<S495>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/postSat Signal'
//  '<S496>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/preSat Signal'
//  '<S497>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel'
//  '<S498>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S499>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S500>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/D Gain/Internal Parameters'
//  '<S501>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Filter/Disc. Forward Euler Filter'
//  '<S502>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Filter ICs/Internal IC - Filter'
//  '<S503>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/I Gain/Internal Parameters'
//  '<S504>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S505>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain Fdbk/Passthrough'
//  '<S506>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Integrator/Discrete'
//  '<S507>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Integrator ICs/Internal IC'
//  '<S508>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/N Copy/Disabled'
//  '<S509>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/N Gain/Internal Parameters'
//  '<S510>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/P Copy/Disabled'
//  '<S511>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Parallel P Gain/Internal Parameters'
//  '<S512>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Reset Signal/Disabled'
//  '<S513>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Saturation/Enabled'
//  '<S514>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Saturation Fdbk/Passthrough'
//  '<S515>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Sum/Sum_PID'
//  '<S516>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Sum Fdbk/Enabled'
//  '<S517>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S518>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S519>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S520>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S521>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/postSat Signal/Feedback_Path'
//  '<S522>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_Altitude/preSat Signal/Feedback_Path'
//  '<S523>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Anti-windup'
//  '<S524>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/D Gain'
//  '<S525>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Filter'
//  '<S526>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Filter ICs'
//  '<S527>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/I Gain'
//  '<S528>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Ideal P Gain'
//  '<S529>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Ideal P Gain Fdbk'
//  '<S530>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Integrator'
//  '<S531>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Integrator ICs'
//  '<S532>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/N Copy'
//  '<S533>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/N Gain'
//  '<S534>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/P Copy'
//  '<S535>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Parallel P Gain'
//  '<S536>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Reset Signal'
//  '<S537>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Saturation'
//  '<S538>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Saturation Fdbk'
//  '<S539>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Sum'
//  '<S540>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Sum Fdbk'
//  '<S541>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Tracking Mode'
//  '<S542>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Tracking Mode Sum'
//  '<S543>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Tsamp - Integral'
//  '<S544>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Tsamp - Ngain'
//  '<S545>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/postSat Signal'
//  '<S546>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/preSat Signal'
//  '<S547>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel'
//  '<S548>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S549>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S550>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/D Gain/Internal Parameters'
//  '<S551>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Filter/Disc. Forward Euler Filter'
//  '<S552>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Filter ICs/Internal IC - Filter'
//  '<S553>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/I Gain/Internal Parameters'
//  '<S554>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Ideal P Gain/Passthrough'
//  '<S555>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Ideal P Gain Fdbk/Passthrough'
//  '<S556>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Integrator/Discrete'
//  '<S557>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Integrator ICs/Internal IC'
//  '<S558>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/N Copy/Disabled'
//  '<S559>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/N Gain/Internal Parameters'
//  '<S560>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/P Copy/Disabled'
//  '<S561>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Parallel P Gain/Internal Parameters'
//  '<S562>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Reset Signal/Disabled'
//  '<S563>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Saturation/Enabled'
//  '<S564>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Saturation Fdbk/Passthrough'
//  '<S565>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Sum/Sum_PID'
//  '<S566>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Sum Fdbk/Enabled'
//  '<S567>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Tracking Mode/Disabled'
//  '<S568>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Tracking Mode Sum/Passthrough'
//  '<S569>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Tsamp - Integral/TsSignalSpecification'
//  '<S570>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/Tsamp - Ngain/Passthrough'
//  '<S571>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/postSat Signal/Feedback_Path'
//  '<S572>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Position & Altitude controller/PID_vz/preSat Signal/Feedback_Path'
//  '<S573>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Quaternion Validity Check/Quaternion Norm'
//  '<S574>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Quaternions to Rotation Angles/Angle Calculation'
//  '<S575>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S576>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S577>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S578>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S579>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S580>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S581>' : 'Hexacopter_ControllerWithNavigation_ver2023b/Position & Rate Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif            // RTW_HEADER_Hexacopter_ControllerWithNavigation_ver2023b_h_

//
// File trailer for generated code.
//
// [EOF]
//
