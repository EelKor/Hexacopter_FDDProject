//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_HEXA_Hovering.h
//
// Code generated for Simulink model 'FLIGHT_HEXA_Hovering'.
//
// Model version                  : 5.27
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Tue Jan  7 14:03:20 2025
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
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
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

// Block signals for system '<S9>/SourceBlock'
struct B_SourceBlock_FLIGHT_HEXA_Hovering_T {
  px4_Bus_actuator_armed SourceBlock_o2;// '<S9>/SourceBlock'
  boolean_T SourceBlock_o1;            // '<S9>/SourceBlock'
};

// Block states (default storage) for system '<S9>/SourceBlock'
struct DW_SourceBlock_FLIGHT_HEXA_Hovering_T {
  px4_internal_block_Subscriber_FLIGHT_HEXA_Hovering_T obj;// '<S9>/SourceBlock' 
  boolean_T objisempty;                // '<S9>/SourceBlock'
};

// Block signals for system '<S21>/SourceBlock'
struct B_SourceBlock_FLIGHT_HEXA_Hovering_d_T {
  px4_Bus_input_rc SourceBlock_o2;     // '<S21>/SourceBlock'
  boolean_T SourceBlock_o1;            // '<S21>/SourceBlock'
};

// Block states (default storage) for system '<S21>/SourceBlock'
struct DW_SourceBlock_FLIGHT_HEXA_Hovering_e_T {
  px4_internal_block_Subscriber_FLIGHT_HEXA_Hovering_T obj;// '<S21>/SourceBlock' 
  boolean_T objisempty;                // '<S21>/SourceBlock'
};

// Block signals for system '<S62>/MATLAB System'
struct B_MATLABSystem_FLIGHT_HEXA_Hovering_T {
  real32_T MATLABSystem[3];            // '<S62>/MATLAB System'
  real_T dLat;
};

// Block states (default storage) for system '<S62>/MATLAB System'
struct DW_MATLABSystem_FLIGHT_HEXA_Hovering_T {
  px4_internal_block_LLA2LocalCoordinatesNED_FLIGHT_HEXA_Hoveri_T obj;// '<S62>/MATLAB System' 
  boolean_T objisempty;                // '<S62>/MATLAB System'
};

// Block signals (default storage)
struct B_FLIGHT_HEXA_Hovering_T {
  px4_Bus_vehicle_trajectory_waypoint BusAssignment1;// '<S56>/Bus Assignment1'
  px4_Bus_vehicle_trajectory_waypoint In1;// '<S61>/In1'
  px4_Bus_vehicle_trajectory_waypoint r;
  px4_Bus_position_setpoint_triplet In1_p;// '<S73>/In1'
  px4_Bus_position_setpoint_triplet r1;
  px4_Bus_vehicle_local_position In1_c;// '<S35>/In1'
  px4_Bus_vehicle_local_position r2;
  px4_Bus_input_rc In1_j;              // '<S33>/In1'
  px4_Bus_input_rc In1_a;              // '<S22>/In1'
  px4_Bus_actuator_motors BusAssignment;// '<S11>/Bus Assignment'
  real_T b_waypointsIn_data[9];
  real_T MatrixConcatenate_p[9];       // '<S43>/Matrix Concatenate'
  px4_Bus_vehicle_attitude In1_m;      // '<S34>/In1'
  px4_Bus_vehicle_attitude r3;
  px4_Bus_trajectory_waypoint BusAssignment1_f;// '<S64>/Bus Assignment1'
  px4_Bus_home_position In1_f;         // '<S72>/In1'
  px4_Bus_home_position r4;
  px4_Bus_vehicle_angular_velocity In1_l;// '<S30>/In1'
  px4_Bus_vehicle_angular_velocity r5;
  real_T lla0[3];
  real_T virtualWaypoint[3];
  real_T b_startWaypoint[3];
  real_T VectorConcatenate[3];         // '<S605>/Vector Concatenate'
  real_T DataTypeConversion2[3];       // '<S2>/Data Type Conversion2'
  real_T dv[3];
  px4_Bus_actuator_armed In1_b;        // '<S31>/In1'
  real_T Saturation[2];                // '<S390>/Saturation'
  real_T Gain1;                        // '<S77>/Gain1'
  real_T Saturation_a;                 // '<S490>/Saturation'
  real_T Saturation_o;                 // '<S594>/Saturation'
  real_T Saturation_n;                 // '<S127>/Saturation'
  real_T Saturation_b;                 // '<S179>/Saturation'
  real_T Saturation_a1;                // '<S231>/Saturation'
  real_T yaw_In;                       // '<S45>/yaw_In'
  real_T yaw_In_i;                     // '<S49>/yaw_In'
  real_T In;                           // '<S48>/In'
  real_T yaw_In_ik;                    // '<S52>/yaw_In'
  real_T Switch4;                      // '<S6>/Switch4'
  real_T Switch3;                      // '<S6>/Switch3'
  real_T Switch2;                      // '<S6>/Switch2'
  real_T Switch_fw;                    // '<S6>/Switch'
  real_T Subtract_f;                   // '<S46>/Subtract'
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
  boolean_T IsNaN_l[2];                // '<S41>/IsNaN'
  int8_T rtPrevAction;
  int8_T i2_b;
  boolean_T b_varargout_1;
  boolean_T Compare_b;                 // '<S12>/Compare'
  boolean_T Compare;                   // '<S13>/Compare'
  boolean_T latp2;
  B_MATLABSystem_FLIGHT_HEXA_Hovering_T MATLABSystem_b;// '<S62>/MATLAB System'
  B_MATLABSystem_FLIGHT_HEXA_Hovering_T MATLABSystem;// '<S62>/MATLAB System'
  B_SourceBlock_FLIGHT_HEXA_Hovering_d_T SourceBlock_b;// '<S21>/SourceBlock'
  B_SourceBlock_FLIGHT_HEXA_Hovering_T SourceBlock_l;// '<S9>/SourceBlock'
  B_SourceBlock_FLIGHT_HEXA_Hovering_d_T SourceBlock_d;// '<S21>/SourceBlock'
  B_SourceBlock_FLIGHT_HEXA_Hovering_T SourceBlock;// '<S9>/SourceBlock'
};

// Block states (default storage) for system '<Root>'
struct DW_FLIGHT_HEXA_Hovering_T {
  uav_sluav_internal_system_WaypointFollower_FLIGHT_HEXA_Hoveri_T obj;// '<S43>/UAV Waypoint Follower' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_b;// '<S70>/Read Parameter' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_g;// '<S71>/Read Parameter' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_k;// '<S39>/Read Parameter' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_f;// '<S7>/Read Parameter5' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_a;// '<S7>/Read Parameter4' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_p;// '<S7>/Read Parameter3' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_gv;// '<S7>/Read Parameter2' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_bs;// '<S7>/Read Parameter13' 
  px4_internal_block_ParameterUpdate_FLIGHT_HEXA_Hovering_T obj_d;// '<S7>/Read Parameter1' 
  px4_internal_block_Subscriber_FLIGHT_HEXA_Hovering_T obj_kz;// '<S58>/SourceBlock' 
  px4_internal_block_Subscriber_FLIGHT_HEXA_Hovering_T obj_gf;// '<S57>/SourceBlock' 
  px4_internal_block_Subscriber_FLIGHT_HEXA_Hovering_T obj_e;// '<S60>/SourceBlock' 
  px4_internal_block_Subscriber_FLIGHT_HEXA_Hovering_T obj_m;// '<S29>/SourceBlock' 
  px4_internal_block_Subscriber_FLIGHT_HEXA_Hovering_T obj_gvl;// '<S28>/SourceBlock' 
  px4_internal_block_Subscriber_FLIGHT_HEXA_Hovering_T obj_po;// '<S25>/SourceBlock' 
  px4_internal_block_getPX4AbsoluteTime_FLIGHT_HEXA_Hovering_T obj_n;// '<S55>/PX4 Timestamp' 
  px4_internal_block_Publisher_FLIGHT_HEXA_Hovering_T obj_mc;// '<S67>/SinkBlock' 
  px4_internal_block_Publisher_FLIGHT_HEXA_Hovering_T obj_c;// '<S24>/SinkBlock' 
  px4_internal_block_LLA2LocalCoordinates_FLIGHT_HEXA_Hovering_T obj_mr;// '<S39>/LLA2LocalCoordinates' 
  real_T Filter_DSTATE;                // '<S530>/Filter'
  real_T Integrator_DSTATE;            // '<S535>/Integrator'
  real_T Filter_DSTATE_o;              // '<S582>/Filter'
  real_T Integrator_DSTATE_o;          // '<S587>/Integrator'
  real_T Integrator_DSTATE_i;          // '<S120>/Integrator'
  real_T Filter_DSTATE_ov;             // '<S115>/Filter'
  real_T Integrator_DSTATE_h;          // '<S172>/Integrator'
  real_T Filter_DSTATE_c;              // '<S167>/Filter'
  real_T Integrator_DSTATE_ih;         // '<S224>/Integrator'
  real_T Filter_DSTATE_f;              // '<S219>/Filter'
  real_T Delay_DSTATE;                 // '<S44>/Delay'
  real_T Delay_DSTATE_l[2];            // '<S41>/Delay'
  real_T Delay_DSTATE_n;               // '<S46>/Delay'
  real_T Delay_DSTATE_b;               // '<S47>/Delay'
  real_T Delay_DSTATE_c;               // '<S50>/Delay'
  real_T Delay_DSTATE_d;               // '<S51>/Delay'
  real_T PrevY;                        // '<S74>/Rate Limiter2'
  real_T PrevY_m;                      // '<S74>/Rate Limiter1'
  px4_internal_block_LLA2LocalCoordinatesNED_FLIGHT_HEXA_Hoveri_T obj_mu;// '<S65>/MATLAB System' 
  int8_T If_ActiveSubsystem;           // '<S38>/If'
  uint8_T is_active_c3_FLIGHT_HEXA_Hovering;// '<S4>/Chart'
  uint8_T is_c3_FLIGHT_HEXA_Hovering;  // '<S4>/Chart'
  DW_MATLABSystem_FLIGHT_HEXA_Hovering_T MATLABSystem_b;// '<S62>/MATLAB System' 
  DW_MATLABSystem_FLIGHT_HEXA_Hovering_T MATLABSystem;// '<S62>/MATLAB System'
  DW_SourceBlock_FLIGHT_HEXA_Hovering_e_T SourceBlock_b;// '<S21>/SourceBlock'
  DW_SourceBlock_FLIGHT_HEXA_Hovering_T SourceBlock_l;// '<S9>/SourceBlock'
  DW_SourceBlock_FLIGHT_HEXA_Hovering_e_T SourceBlock_d;// '<S21>/SourceBlock'
  DW_SourceBlock_FLIGHT_HEXA_Hovering_T SourceBlock;// '<S9>/SourceBlock'
};

// Parameters (default storage)
struct P_FLIGHT_HEXA_Hovering_T_ {
  real_T PIDController_D;              // Mask Parameter: PIDController_D
                                          //  Referenced by: '<S113>/Derivative Gain'

  real_T PIDController1_D;             // Mask Parameter: PIDController1_D
                                          //  Referenced by: '<S165>/Derivative Gain'

  real_T PIDController2_D;             // Mask Parameter: PIDController2_D
                                          //  Referenced by: '<S217>/Derivative Gain'

  real_T PID_Altitude_D;               // Mask Parameter: PID_Altitude_D
                                          //  Referenced by: '<S528>/Derivative Gain'

  real_T PID_vz_D;                     // Mask Parameter: PID_vz_D
                                          //  Referenced by: '<S580>/Derivative Gain'

  real_T PIDController_I;              // Mask Parameter: PIDController_I
                                          //  Referenced by: '<S117>/Integral Gain'

  real_T PIDController1_I;             // Mask Parameter: PIDController1_I
                                          //  Referenced by: '<S169>/Integral Gain'

  real_T PIDController2_I;             // Mask Parameter: PIDController2_I
                                          //  Referenced by: '<S221>/Integral Gain'

  real_T PID_Altitude_I;               // Mask Parameter: PID_Altitude_I
                                          //  Referenced by: '<S532>/Integral Gain'

  real_T PID_vz_I;                     // Mask Parameter: PID_vz_I
                                          //  Referenced by: '<S584>/Integral Gain'

  real_T PIDController_InitialConditionForFilter;
                      // Mask Parameter: PIDController_InitialConditionForFilter
                         //  Referenced by: '<S115>/Filter'

  real_T PIDController1_InitialConditionForFilter;
                     // Mask Parameter: PIDController1_InitialConditionForFilter
                        //  Referenced by: '<S167>/Filter'

  real_T PIDController2_InitialConditionForFilter;
                     // Mask Parameter: PIDController2_InitialConditionForFilter
                        //  Referenced by: '<S219>/Filter'

  real_T PID_Altitude_InitialConditionForFilter;
                       // Mask Parameter: PID_Altitude_InitialConditionForFilter
                          //  Referenced by: '<S530>/Filter'

  real_T PID_vz_InitialConditionForFilter;
                             // Mask Parameter: PID_vz_InitialConditionForFilter
                                //  Referenced by: '<S582>/Filter'

  real_T PIDController_InitialConditionForIntegrator;
                  // Mask Parameter: PIDController_InitialConditionForIntegrator
                     //  Referenced by: '<S120>/Integrator'

  real_T PIDController1_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController1_InitialConditionForIntegrator
                    //  Referenced by: '<S172>/Integrator'

  real_T PIDController2_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController2_InitialConditionForIntegrator
                    //  Referenced by: '<S224>/Integrator'

  real_T PID_Altitude_InitialConditionForIntegrator;
                   // Mask Parameter: PID_Altitude_InitialConditionForIntegrator
                      //  Referenced by: '<S535>/Integrator'

  real_T PID_vz_InitialConditionForIntegrator;
                         // Mask Parameter: PID_vz_InitialConditionForIntegrator
                            //  Referenced by: '<S587>/Integrator'

  real_T PIDController_LowerSaturationLimit;
                           // Mask Parameter: PIDController_LowerSaturationLimit
                              //  Referenced by:
                              //    '<S127>/Saturation'
                              //    '<S112>/DeadZone'

  real_T PIDController1_LowerSaturationLimit;
                          // Mask Parameter: PIDController1_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S179>/Saturation'
                             //    '<S164>/DeadZone'

  real_T PIDController2_LowerSaturationLimit;
                          // Mask Parameter: PIDController2_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S231>/Saturation'
                             //    '<S216>/DeadZone'

  real_T PIDController1_LowerSaturationLimit_e;
                        // Mask Parameter: PIDController1_LowerSaturationLimit_e
                           //  Referenced by: '<S440>/Saturation'

  real_T PIDController_LowerSaturationLimit_j;
                         // Mask Parameter: PIDController_LowerSaturationLimit_j
                            //  Referenced by: '<S390>/Saturation'

  real_T PIDController5_LowerSaturationLimit;
                          // Mask Parameter: PIDController5_LowerSaturationLimit
                             //  Referenced by: '<S490>/Saturation'

  real_T PID_Altitude_LowerSaturationLimit;
                            // Mask Parameter: PID_Altitude_LowerSaturationLimit
                               //  Referenced by:
                               //    '<S542>/Saturation'
                               //    '<S527>/DeadZone'

  real_T PID_vz_LowerSaturationLimit;
                                  // Mask Parameter: PID_vz_LowerSaturationLimit
                                     //  Referenced by:
                                     //    '<S594>/Saturation'
                                     //    '<S579>/DeadZone'

  real_T PIDController_N;              // Mask Parameter: PIDController_N
                                          //  Referenced by: '<S123>/Filter Coefficient'

  real_T PIDController1_N;             // Mask Parameter: PIDController1_N
                                          //  Referenced by: '<S175>/Filter Coefficient'

  real_T PIDController2_N;             // Mask Parameter: PIDController2_N
                                          //  Referenced by: '<S227>/Filter Coefficient'

  real_T PID_Altitude_N;               // Mask Parameter: PID_Altitude_N
                                          //  Referenced by: '<S538>/Filter Coefficient'

  real_T PID_vz_N;                     // Mask Parameter: PID_vz_N
                                          //  Referenced by: '<S590>/Filter Coefficient'

  real_T PIDController_P;              // Mask Parameter: PIDController_P
                                          //  Referenced by: '<S125>/Proportional Gain'

  real_T PIDController3_P;             // Mask Parameter: PIDController3_P
                                          //  Referenced by: '<S279>/Proportional Gain'

  real_T PIDController1_P;             // Mask Parameter: PIDController1_P
                                          //  Referenced by: '<S177>/Proportional Gain'

  real_T PIDController4_P;             // Mask Parameter: PIDController4_P
                                          //  Referenced by: '<S329>/Proportional Gain'

  real_T PIDController2_P;             // Mask Parameter: PIDController2_P
                                          //  Referenced by: '<S229>/Proportional Gain'

  real_T PIDController1_P_h;           // Mask Parameter: PIDController1_P_h
                                          //  Referenced by: '<S438>/Proportional Gain'

  real_T PIDController_P_d;            // Mask Parameter: PIDController_P_d
                                          //  Referenced by: '<S388>/Proportional Gain'

  real_T PIDController5_P;             // Mask Parameter: PIDController5_P
                                          //  Referenced by: '<S488>/Proportional Gain'

  real_T PID_Altitude_P;               // Mask Parameter: PID_Altitude_P
                                          //  Referenced by: '<S540>/Proportional Gain'

  real_T PID_vz_P;                     // Mask Parameter: PID_vz_P
                                          //  Referenced by: '<S592>/Proportional Gain'

  real_T PIDController_UpperSaturationLimit;
                           // Mask Parameter: PIDController_UpperSaturationLimit
                              //  Referenced by:
                              //    '<S127>/Saturation'
                              //    '<S112>/DeadZone'

  real_T PIDController1_UpperSaturationLimit;
                          // Mask Parameter: PIDController1_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S179>/Saturation'
                             //    '<S164>/DeadZone'

  real_T PIDController2_UpperSaturationLimit;
                          // Mask Parameter: PIDController2_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S231>/Saturation'
                             //    '<S216>/DeadZone'

  real_T PIDController1_UpperSaturationLimit_l;
                        // Mask Parameter: PIDController1_UpperSaturationLimit_l
                           //  Referenced by: '<S440>/Saturation'

  real_T PIDController_UpperSaturationLimit_b;
                         // Mask Parameter: PIDController_UpperSaturationLimit_b
                            //  Referenced by: '<S390>/Saturation'

  real_T PIDController5_UpperSaturationLimit;
                          // Mask Parameter: PIDController5_UpperSaturationLimit
                             //  Referenced by: '<S490>/Saturation'

  real_T PID_Altitude_UpperSaturationLimit;
                            // Mask Parameter: PID_Altitude_UpperSaturationLimit
                               //  Referenced by:
                               //    '<S542>/Saturation'
                               //    '<S527>/DeadZone'

  real_T PID_vz_UpperSaturationLimit;
                                  // Mask Parameter: PID_vz_UpperSaturationLimit
                                     //  Referenced by:
                                     //    '<S594>/Saturation'
                                     //    '<S579>/DeadZone'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S12>/Constant'

  uint16_T CompareToConstant_const_m;
                                    // Mask Parameter: CompareToConstant_const_m
                                       //  Referenced by: '<S13>/Constant'

  uint8_T CompareToConstant_const_d;// Mask Parameter: CompareToConstant_const_d
                                       //  Referenced by: '<S54>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Out1_Y0;// Computed Parameter: Out1_Y0
                                                 //  Referenced by: '<S61>/Out1'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value;// Computed Parameter: Constant_Value
                                                        //  Referenced by: '<S66>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                          //  Referenced by: '<S60>/Constant'

  px4_Bus_position_setpoint_triplet Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                 //  Referenced by: '<S73>/Out1'

  px4_Bus_position_setpoint_triplet Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                        //  Referenced by: '<S58>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                              //  Referenced by: '<S35>/Out1'

  px4_Bus_vehicle_local_position Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                     //  Referenced by: '<S29>/Constant'

  px4_Bus_actuator_motors Constant_Value_o;// Computed Parameter: Constant_Value_o
                                              //  Referenced by: '<S23>/Constant'

  px4_Bus_input_rc Out1_Y0_j;          // Computed Parameter: Out1_Y0_j
                                          //  Referenced by: '<S22>/Out1'

  px4_Bus_input_rc Out1_Y0_m;          // Computed Parameter: Out1_Y0_m
                                          //  Referenced by: '<S33>/Out1'

  px4_Bus_input_rc Constant_Value_dd;  // Computed Parameter: Constant_Value_dd
                                          //  Referenced by: '<S21>/Constant'

  px4_Bus_input_rc Constant_Value_ov;  // Computed Parameter: Constant_Value_ov
                                          //  Referenced by: '<S32>/Constant'

  px4_Bus_vehicle_attitude Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S34>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_l;// Computed Parameter: Constant_Value_l
                                               //  Referenced by: '<S28>/Constant'

  px4_Bus_home_position Out1_Y0_o;     // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S72>/Out1'

  px4_Bus_home_position Constant_Value_b;// Computed Parameter: Constant_Value_b
                                            //  Referenced by: '<S57>/Constant'

  px4_Bus_vehicle_angular_velocity Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                //  Referenced by: '<S30>/Out1'

  px4_Bus_vehicle_angular_velocity Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                       //  Referenced by: '<S25>/Constant'

  px4_Bus_actuator_armed Out1_Y0_j5;   // Computed Parameter: Out1_Y0_j5
                                          //  Referenced by: '<S20>/Out1'

  px4_Bus_actuator_armed Out1_Y0_d;    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S31>/Out1'

  px4_Bus_actuator_armed Constant_Value_j;// Computed Parameter: Constant_Value_j
                                             //  Referenced by: '<S26>/Constant'

  px4_Bus_actuator_armed Constant_Value_f;// Computed Parameter: Constant_Value_f
                                             //  Referenced by: '<S9>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S6>/Constant1'

  real_T Constant1_Value_f;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant1'

  real_T Gain_Gain;                    // Expression: 0.01
                                          //  Referenced by: '<S15>/Gain'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<S15>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S15>/Saturation'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S6>/Constant2'

  real_T Constant2_Value_l;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant2'

  real_T Gain_Gain_e;                  // Expression: 0.01
                                          //  Referenced by: '<S16>/Gain'

  real_T Saturation_UpperSat_f;        // Expression: 1
                                          //  Referenced by: '<S16>/Saturation'

  real_T Saturation_LowerSat_c;        // Expression: 0
                                          //  Referenced by: '<S16>/Saturation'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<S6>/Constant3'

  real_T Constant3_Value_p;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant3'

  real_T Gain_Gain_b;                  // Expression: 0.01
                                          //  Referenced by: '<S17>/Gain'

  real_T Saturation_UpperSat_o;        // Expression: 1
                                          //  Referenced by: '<S17>/Saturation'

  real_T Saturation_LowerSat_cl;       // Expression: 0
                                          //  Referenced by: '<S17>/Saturation'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<S6>/Constant4'

  real_T Constant4_Value_j;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant4'

  real_T Gain_Gain_el;                 // Expression: 0.01
                                          //  Referenced by: '<S18>/Gain'

  real_T Saturation_UpperSat_l;        // Expression: 1
                                          //  Referenced by: '<S18>/Saturation'

  real_T Saturation_LowerSat_l;        // Expression: 0
                                          //  Referenced by: '<S18>/Saturation'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<S6>/Constant5'

  real_T Constant5_Value_m;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant5'

  real_T Gain_Gain_a;                  // Expression: 0.01
                                          //  Referenced by: '<S19>/Gain'

  real_T Saturation_UpperSat_k;        // Expression: 1
                                          //  Referenced by: '<S19>/Saturation'

  real_T Saturation_LowerSat_k;        // Expression: 0
                                          //  Referenced by: '<S19>/Saturation'

  real_T Constant_Value_bv;            // Expression: 0
                                          //  Referenced by: '<S6>/Constant'

  real_T Constant_Value_jp;            // Expression: 100
                                          //  Referenced by: '<S7>/Constant'

  real_T Gain_Gain_o;                  // Expression: 0.01
                                          //  Referenced by: '<S14>/Gain'

  real_T Saturation_UpperSat_or;       // Expression: 1
                                          //  Referenced by: '<S14>/Saturation'

  real_T Saturation_LowerSat_cq;       // Expression: 0
                                          //  Referenced by: '<S14>/Saturation'

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
                                          //  Referenced by: '<S52>/yaw_Out'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S50>/Delay'

  real_T Rate_Value;                   // Expression: 0.01
                                          //  Referenced by: '<S50>/Rate'

  real_T Gain1_Gain;                   // Expression: -1
                                          //  Referenced by: '<S50>/Gain1'

  real_T Gain_Gain_e3;                 // Expression: -1
                                          //  Referenced by: '<S50>/Gain'

  real_T Delay_InitialCondition_g;     // Expression: 1
                                          //  Referenced by: '<S51>/Delay'

  real_T Constant_Value_fo;            // Expression: 0
                                          //  Referenced by: '<S51>/Constant'

  real_T Out_Y0;                       // Computed Parameter: Out_Y0
                                          //  Referenced by: '<S48>/Out'

  real_T Gain_Gain_l;                  // Expression: -1
                                          //  Referenced by: '<S46>/Gain'

  real_T yaw_Out_Y0_f;                 // Computed Parameter: yaw_Out_Y0_f
                                          //  Referenced by: '<S49>/yaw_Out'

  real_T Delay_InitialCondition_n;     // Expression: 0.0
                                          //  Referenced by: '<S41>/Delay'

  real_T Delay_InitialCondition_m;     // Expression: 0.0
                                          //  Referenced by: '<S46>/Delay'

  real_T Switch_Threshold;             // Expression: 0
                                          //  Referenced by: '<S46>/Switch'

  real_T Rateofdescent_Value;          // Expression: 0.02
                                          //  Referenced by: '<S46>/Rate of descent'

  real_T Gain2_Gain;                   // Expression: -1
                                          //  Referenced by: '<S46>/Gain2'

  real_T Gain1_Gain_a;                 // Expression: -1
                                          //  Referenced by: '<S46>/Gain1'

  real_T Delay_InitialCondition_j;     // Expression: 1
                                          //  Referenced by: '<S47>/Delay'

  real_T Constant_Value_nn;            // Expression: 0
                                          //  Referenced by: '<S47>/Constant'

  real_T Constant_Value_jd;            // Expression: 0
                                          //  Referenced by: '<S53>/Constant'

  real_T Constant_Value_gw;            // Expression: 6
                                          //  Referenced by: '<S43>/Constant'

  real_T yaw_Out_Y0_p;                 // Computed Parameter: yaw_Out_Y0_p
                                          //  Referenced by: '<S45>/yaw_Out'

  real_T Delay_InitialCondition_g0;    // Expression: 1
                                          //  Referenced by: '<S44>/Delay'

  real_T Constant_Value_i;             // Expression: 0
                                          //  Referenced by: '<S44>/Constant'

  real_T ReadParameter_SampleTime;     // Expression: -1
                                          //  Referenced by: '<S39>/Read Parameter'

  real_T ReadParameter_SampleTime_c;   // Expression: -1
                                          //  Referenced by: '<S71>/Read Parameter'

  real_T ReadParameter_SampleTime_g;   // Expression: -1
                                          //  Referenced by: '<S70>/Read Parameter'

  real_T tau_Yaw_Y0;                   // Computed Parameter: tau_Yaw_Y0
                                          //  Referenced by: '<S74>/tau_Yaw'

  real_T tau_Pitch_Y0;                 // Computed Parameter: tau_Pitch_Y0
                                          //  Referenced by: '<S74>/tau_Pitch'

  real_T tau_Roll_Y0;                  // Computed Parameter: tau_Roll_Y0
                                          //  Referenced by: '<S74>/tau_Roll'

  real_T Constant1_Value_m;            // Expression: 0
                                          //  Referenced by: '<S110>/Constant1'

  real_T Constant1_Value_c;            // Expression: 0
                                          //  Referenced by: '<S162>/Constant1'

  real_T Constant1_Value_k;            // Expression: 0
                                          //  Referenced by: '<S214>/Constant1'

  real_T Clamping_zero_Value;          // Expression: 0
                                          //  Referenced by: '<S110>/Clamping_zero'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S120>/Integrator'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S115>/Filter'

  real_T RateLimiter2_RisingLim;       // Expression: 40*pi/180
                                          //  Referenced by: '<S74>/Rate Limiter2'

  real_T RateLimiter2_FallingLim;      // Expression: -40*pi/180
                                          //  Referenced by: '<S74>/Rate Limiter2'

  real_T RateLimiter2_IC;              // Expression: 0
                                          //  Referenced by: '<S74>/Rate Limiter2'

  real_T Saturation1_UpperSat;         // Expression: 20*pi/180
                                          //  Referenced by: '<S74>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -20*pi/180
                                          //  Referenced by: '<S74>/Saturation1'

  real_T Clamping_zero_Value_e;        // Expression: 0
                                          //  Referenced by: '<S162>/Clamping_zero'

  real_T Integrator_gainval_i;       // Computed Parameter: Integrator_gainval_i
                                        //  Referenced by: '<S172>/Integrator'

  real_T Filter_gainval_e;             // Computed Parameter: Filter_gainval_e
                                          //  Referenced by: '<S167>/Filter'

  real_T RateLimiter1_RisingLim;       // Expression: 40*pi/180
                                          //  Referenced by: '<S74>/Rate Limiter1'

  real_T RateLimiter1_FallingLim;      // Expression: -40*pi/180
                                          //  Referenced by: '<S74>/Rate Limiter1'

  real_T RateLimiter1_IC;              // Expression: 0
                                          //  Referenced by: '<S74>/Rate Limiter1'

  real_T Saturation_UpperSat_a;        // Expression: 20*pi/180
                                          //  Referenced by: '<S74>/Saturation'

  real_T Saturation_LowerSat_a;        // Expression: -20*pi/180
                                          //  Referenced by: '<S74>/Saturation'

  real_T Clamping_zero_Value_j;        // Expression: 0
                                          //  Referenced by: '<S214>/Clamping_zero'

  real_T Integrator_gainval_f;       // Computed Parameter: Integrator_gainval_f
                                        //  Referenced by: '<S224>/Integrator'

  real_T Filter_gainval_l;             // Computed Parameter: Filter_gainval_l
                                          //  Referenced by: '<S219>/Filter'

  real_T Constant_Value_ib;            // Expression: 0
                                          //  Referenced by: '<S341>/Constant'

  real_T Switch1_Threshold;            // Expression: 0
                                          //  Referenced by: '<S343>/Switch1'

  real_T des_pitch_Y0;                 // Computed Parameter: des_pitch_Y0
                                          //  Referenced by: '<S77>/des_pitch'

  real_T des_roll_Y0;                  // Computed Parameter: des_roll_Y0
                                          //  Referenced by: '<S77>/des_roll'

  real_T des_yawrate_Y0;               // Computed Parameter: des_yawrate_Y0
                                          //  Referenced by: '<S77>/des_yawrate'

  real_T tau_Thrust_Y0;                // Computed Parameter: tau_Thrust_Y0
                                          //  Referenced by: '<S77>/tau_Thrust'

  real_T Constant1_Value_l;            // Expression: 0
                                          //  Referenced by: '<S525>/Constant1'

  real_T Constant1_Value_fq;           // Expression: 0
                                          //  Referenced by: '<S577>/Constant1'

  real_T Gain_Gain_or;                 // Expression: -1
                                          //  Referenced by: '<S342>/Gain'

  real_T Constant_Value_g4;            // Expression: 2*pi
                                          //  Referenced by: '<S343>/Constant'

  real_T Switch_Threshold_e;           // Expression: pi
                                          //  Referenced by: '<S343>/Switch'

  real_T Gain1_Gain_m;                 // Expression: -1
                                          //  Referenced by: '<S77>/Gain1'

  real_T Gain1_Gain_h;                 // Expression: -1
                                          //  Referenced by: '<S341>/Gain1'

  real_T Clamping_zero_Value_f;        // Expression: 0
                                          //  Referenced by: '<S525>/Clamping_zero'

  real_T Filter_gainval_i;             // Computed Parameter: Filter_gainval_i
                                          //  Referenced by: '<S530>/Filter'

  real_T Integrator_gainval_p;       // Computed Parameter: Integrator_gainval_p
                                        //  Referenced by: '<S535>/Integrator'

  real_T Clamping_zero_Value_a;        // Expression: 0
                                          //  Referenced by: '<S577>/Clamping_zero'

  real_T Filter_gainval_m;             // Computed Parameter: Filter_gainval_m
                                          //  Referenced by: '<S582>/Filter'

  real_T Integrator_gainval_k;       // Computed Parameter: Integrator_gainval_k
                                        //  Referenced by: '<S587>/Integrator'

  real_T Constant_Value_m[4];          // Expression: [1 0 0 0]
                                          //  Referenced by: '<S78>/Constant'

  real_T Constant_Value_ji;            // Expression: 1
                                          //  Referenced by: '<S608>/Constant'

  real_T Constant_Value_h;             // Expression: 1
                                          //  Referenced by: '<S609>/Constant'

  real_T Switch_Threshold_d;           // Expression: 0
                                          //  Referenced by: '<S78>/Switch'

  real_T Constant2_Value_b;            // Expression: 1500
                                          //  Referenced by: '<S76>/Constant2'

  real_T Gain2_Gain_j;                 // Expression: 1/400
                                          //  Referenced by: '<S76>/Gain2'

  real_T Saturation2_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S76>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S76>/Saturation2'

  real_T Gain1_Gain_hq;                // Expression: -20*pi/180
                                          //  Referenced by: '<S4>/Gain1'

  real_T Constant1_Value_d;            // Expression: 1500
                                          //  Referenced by: '<S76>/Constant1'

  real_T Gain1_Gain_mu;                // Expression: 1/400
                                          //  Referenced by: '<S76>/Gain1'

  real_T Saturation1_UpperSat_p;       // Expression: 1
                                          //  Referenced by: '<S76>/Saturation1'

  real_T Saturation1_LowerSat_e;       // Expression: -1
                                          //  Referenced by: '<S76>/Saturation1'

  real_T Gain2_Gain_b;                 // Expression: 20*pi/180
                                          //  Referenced by: '<S4>/Gain2'

  real_T Constant_Value_bk;            // Expression: 1100
                                          //  Referenced by: '<S76>/Constant'

  real_T Gain_Gain_k;                  // Expression: 1/800
                                          //  Referenced by: '<S76>/Gain'

  real_T Saturation_UpperSat_c;        // Expression: 0.90
                                          //  Referenced by: '<S76>/Saturation'

  real_T Saturation_LowerSat_g;        // Expression: 0
                                          //  Referenced by: '<S76>/Saturation'

  real_T Constant3_Value_a;            // Expression: 1500
                                          //  Referenced by: '<S76>/Constant3'

  real_T Gain3_Gain;                   // Expression: 1/400
                                          //  Referenced by: '<S76>/Gain3'

  real_T Saturation3_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S76>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S76>/Saturation3'

  real_T Gain4_Gain;                   // Expression: 50*pi/180
                                          //  Referenced by: '<S4>/Gain4'

  real_T Gain_Gain_bp;                 // Expression: -1
                                          //  Referenced by: '<S4>/Gain'

  real_T Gain_Gain_d;                  // Expression: 5
                                          //  Referenced by: '<S5>/Gain'

  real_T Gain1_Gain_hr;                // Expression: 5
                                          //  Referenced by: '<S5>/Gain1'

  real_T Gain2_Gain_i;                 // Expression: 10
                                          //  Referenced by: '<S5>/Gain2'

  real_T Gain3_Gain_e;                 // Expression: 1
                                          //  Referenced by: '<S5>/Gain3'

  real_T Constant_Value_p;             // Expression: 0
                                          //  Referenced by: '<S11>/Constant'

  uint64_T Constant7_Value;            // Computed Parameter: Constant7_Value
                                          //  Referenced by: '<S64>/Constant7'

  real32_T Constant1_Value_dr[2];      // Computed Parameter: Constant1_Value_dr
                                          //  Referenced by: '<S71>/Constant1'

  real32_T Constant_Value_f2;          // Computed Parameter: Constant_Value_f2
                                          //  Referenced by: '<S71>/Constant'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S70>/Gain'

  real32_T Constant1_Value_k4[2];      // Computed Parameter: Constant1_Value_k4
                                          //  Referenced by: '<S70>/Constant1'

  real32_T Constant_Value_l4;          // Computed Parameter: Constant_Value_l4
                                          //  Referenced by: '<S70>/Constant'

  real32_T Constant_Value_fh[3];       // Computed Parameter: Constant_Value_fh
                                          //  Referenced by: '<S64>/Constant'

  real32_T Constant1_Value_h[3];       // Computed Parameter: Constant1_Value_h
                                          //  Referenced by: '<S64>/Constant1'

  real32_T Constant2_Value_f[3];       // Computed Parameter: Constant2_Value_f
                                          //  Referenced by: '<S64>/Constant2'

  real32_T Constant3_Value_al;         // Computed Parameter: Constant3_Value_al
                                          //  Referenced by: '<S64>/Constant3'

  real32_T Constant4_Value_g;          // Computed Parameter: Constant4_Value_g
                                          //  Referenced by: '<S64>/Constant4'

  boolean_T Constant5_Value_j;         // Computed Parameter: Constant5_Value_j
                                          //  Referenced by: '<S62>/Constant5'

  boolean_T Constant5_Value_k;         // Computed Parameter: Constant5_Value_k
                                          //  Referenced by: '<S63>/Constant5'

  boolean_T Constant1_Value_dl;        // Computed Parameter: Constant1_Value_dl
                                          //  Referenced by: '<S65>/Constant1'

  boolean_T Constant5_Value_h;         // Computed Parameter: Constant5_Value_h
                                          //  Referenced by: '<S65>/Constant5'

  boolean_T Constant5_Value_l;         // Computed Parameter: Constant5_Value_l
                                          //  Referenced by: '<S64>/Constant5'

  int8_T Constant_Value_k;             // Computed Parameter: Constant_Value_k
                                          //  Referenced by: '<S110>/Constant'

  int8_T Constant2_Value_j;            // Computed Parameter: Constant2_Value_j
                                          //  Referenced by: '<S110>/Constant2'

  int8_T Constant3_Value_l;            // Computed Parameter: Constant3_Value_l
                                          //  Referenced by: '<S110>/Constant3'

  int8_T Constant4_Value_o;            // Computed Parameter: Constant4_Value_o
                                          //  Referenced by: '<S110>/Constant4'

  int8_T Constant_Value_bd;            // Computed Parameter: Constant_Value_bd
                                          //  Referenced by: '<S162>/Constant'

  int8_T Constant2_Value_fs;           // Computed Parameter: Constant2_Value_fs
                                          //  Referenced by: '<S162>/Constant2'

  int8_T Constant3_Value_n;            // Computed Parameter: Constant3_Value_n
                                          //  Referenced by: '<S162>/Constant3'

  int8_T Constant4_Value_n;            // Computed Parameter: Constant4_Value_n
                                          //  Referenced by: '<S162>/Constant4'

  int8_T Constant_Value_a;             // Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<S214>/Constant'

  int8_T Constant2_Value_p;            // Computed Parameter: Constant2_Value_p
                                          //  Referenced by: '<S214>/Constant2'

  int8_T Constant3_Value_b;            // Computed Parameter: Constant3_Value_b
                                          //  Referenced by: '<S214>/Constant3'

  int8_T Constant4_Value_l;            // Computed Parameter: Constant4_Value_l
                                          //  Referenced by: '<S214>/Constant4'

  int8_T Constant_Value_nq;            // Computed Parameter: Constant_Value_nq
                                          //  Referenced by: '<S525>/Constant'

  int8_T Constant2_Value_o;            // Computed Parameter: Constant2_Value_o
                                          //  Referenced by: '<S525>/Constant2'

  int8_T Constant3_Value_o;            // Computed Parameter: Constant3_Value_o
                                          //  Referenced by: '<S525>/Constant3'

  int8_T Constant4_Value_d;            // Computed Parameter: Constant4_Value_d
                                          //  Referenced by: '<S525>/Constant4'

  int8_T Constant_Value_d3;            // Computed Parameter: Constant_Value_d3
                                          //  Referenced by: '<S577>/Constant'

  int8_T Constant2_Value_pb;           // Computed Parameter: Constant2_Value_pb
                                          //  Referenced by: '<S577>/Constant2'

  int8_T Constant3_Value_m;            // Computed Parameter: Constant3_Value_m
                                          //  Referenced by: '<S577>/Constant3'

  int8_T Constant4_Value_c;            // Computed Parameter: Constant4_Value_c
                                          //  Referenced by: '<S577>/Constant4'

  uint8_T Constant_Value_fm;           // Computed Parameter: Constant_Value_fm
                                          //  Referenced by: '<S56>/Constant'

  uint8_T Constant6_Value;             // Computed Parameter: Constant6_Value
                                          //  Referenced by: '<S64>/Constant6'

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
//  Block '<S9>/NOT' : Unused code path elimination
//  Block '<S10>/Bitwise Operator' : Unused code path elimination
//  Block '<S10>/Data Type Conversion' : Unused code path elimination
//  Block '<S10>/Data Type Conversion1' : Unused code path elimination
//  Block '<S10>/Data Type Conversion2' : Unused code path elimination
//  Block '<S10>/Gain' : Unused code path elimination
//  Block '<S10>/Gain1' : Unused code path elimination
//  Block '<S21>/NOT' : Unused code path elimination
//  Block '<S25>/NOT' : Unused code path elimination
//  Block '<S26>/NOT' : Unused code path elimination
//  Block '<S27>/Bitwise Operator' : Unused code path elimination
//  Block '<S27>/Data Type Conversion' : Unused code path elimination
//  Block '<S27>/Data Type Conversion1' : Unused code path elimination
//  Block '<S27>/Data Type Conversion2' : Unused code path elimination
//  Block '<S27>/Gain' : Unused code path elimination
//  Block '<S27>/Gain1' : Unused code path elimination
//  Block '<S32>/NOT' : Unused code path elimination
//  Block '<S28>/NOT' : Unused code path elimination
//  Block '<S29>/NOT' : Unused code path elimination
//  Block '<S59>/Compare' : Unused code path elimination
//  Block '<S59>/Constant' : Unused code path elimination
//  Block '<S60>/NOT' : Unused code path elimination
//  Block '<S55>/Subtract' : Unused code path elimination
//  Block '<S57>/NOT' : Unused code path elimination
//  Block '<S58>/NOT' : Unused code path elimination
//  Block '<S349>/Data Type Duplicate' : Unused code path elimination
//  Block '<S349>/Data Type Propagation' : Unused code path elimination
//  Block '<S41>/Reshape1' : Reshape block reduction
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
//  '<S1>'   : 'FLIGHT_HEXA_Hovering/Actuator1'
//  '<S2>'   : 'FLIGHT_HEXA_Hovering/Estimator Output'
//  '<S3>'   : 'FLIGHT_HEXA_Hovering/Navigation'
//  '<S4>'   : 'FLIGHT_HEXA_Hovering/Position & Rate Controller'
//  '<S5>'   : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block'
//  '<S6>'   : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/Emergency Kill'
//  '<S7>'   : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/Fault_Injection'
//  '<S8>'   : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/MATLAB Function'
//  '<S9>'   : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/PX4 uORB Read2'
//  '<S10>'  : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/Radio Control Transmitter'
//  '<S11>'  : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/Subsystem'
//  '<S12>'  : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/Emergency Kill/Compare To Constant'
//  '<S13>'  : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/Fault_Injection/Compare To Constant'
//  '<S14>'  : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference'
//  '<S15>'  : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference1'
//  '<S16>'  : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference2'
//  '<S17>'  : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference3'
//  '<S18>'  : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference4'
//  '<S19>'  : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/Fault_Injection/Subsystem Reference5'
//  '<S20>'  : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/PX4 uORB Read2/Enabled Subsystem'
//  '<S21>'  : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/Radio Control Transmitter/PX4 uORB Read'
//  '<S22>'  : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S23>'  : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/Subsystem/PX4 uORB Message'
//  '<S24>'  : 'FLIGHT_HEXA_Hovering/Actuator1/Custom Mixer and PWM Output Block/Subsystem/PX4 uORB Write'
//  '<S25>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/PX4 uORB Read1'
//  '<S26>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/PX4 uORB Read2'
//  '<S27>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/Radio Control Transmitter'
//  '<S28>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/vehicle_attitude'
//  '<S29>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/vehicle_local_pos'
//  '<S30>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/PX4 uORB Read1/Enabled Subsystem'
//  '<S31>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/PX4 uORB Read2/Enabled Subsystem'
//  '<S32>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/Radio Control Transmitter/PX4 uORB Read'
//  '<S33>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S34>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/vehicle_attitude/Enabled Subsystem'
//  '<S35>'  : 'FLIGHT_HEXA_Hovering/Estimator Output/vehicle_local_pos/Enabled Subsystem'
//  '<S36>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm'
//  '<S37>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission'
//  '<S38>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem'
//  '<S39>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC'
//  '<S40>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE'
//  '<S41>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land'
//  '<S42>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off'
//  '<S43>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint'
//  '<S44>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE'
//  '<S45>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE/Enabled Subsystem2'
//  '<S46>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land'
//  '<S47>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land'
//  '<S48>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land/Enabled Subsystem'
//  '<S49>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land/Enabled Subsystem2'
//  '<S50>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Ensure smooth ascend during Takeoff'
//  '<S51>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff'
//  '<S52>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff/Enabled Subsystem2'
//  '<S53>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning'
//  '<S54>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning/Compare To Constant'
//  '<S55>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC'
//  '<S56>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC'
//  '<S57>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead'
//  '<S58>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead'
//  '<S59>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/Compare To Constant'
//  '<S60>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read'
//  '<S61>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read/Enabled Subsystem'
//  '<S62>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint'
//  '<S63>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_WayPoint'
//  '<S64>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Empty_WayPoint'
//  '<S65>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Next_WayPoint'
//  '<S66>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Message'
//  '<S67>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Write'
//  '<S68>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP'
//  '<S69>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem'
//  '<S70>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem1'
//  '<S71>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem2'
//  '<S72>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead/Enabled Subsystem'
//  '<S73>'  : 'FLIGHT_HEXA_Hovering/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead/Enabled Subsystem'
//  '<S74>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller'
//  '<S75>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Chart'
//  '<S76>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/PWM2CMD'
//  '<S77>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller'
//  '<S78>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Quaternion Validity Check'
//  '<S79>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Quaternions to Rotation Angles'
//  '<S80>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller'
//  '<S81>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1'
//  '<S82>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2'
//  '<S83>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3'
//  '<S84>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4'
//  '<S85>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Anti-windup'
//  '<S86>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/D Gain'
//  '<S87>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/External Derivative'
//  '<S88>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Filter'
//  '<S89>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Filter ICs'
//  '<S90>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/I Gain'
//  '<S91>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Ideal P Gain'
//  '<S92>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Ideal P Gain Fdbk'
//  '<S93>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Integrator'
//  '<S94>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Integrator ICs'
//  '<S95>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/N Copy'
//  '<S96>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/N Gain'
//  '<S97>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/P Copy'
//  '<S98>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Parallel P Gain'
//  '<S99>'  : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Reset Signal'
//  '<S100>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Saturation'
//  '<S101>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Saturation Fdbk'
//  '<S102>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Sum'
//  '<S103>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Sum Fdbk'
//  '<S104>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Tracking Mode'
//  '<S105>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Tracking Mode Sum'
//  '<S106>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Tsamp - Integral'
//  '<S107>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Tsamp - Ngain'
//  '<S108>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/postSat Signal'
//  '<S109>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/preSat Signal'
//  '<S110>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S111>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S112>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S113>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/D Gain/Internal Parameters'
//  '<S114>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/External Derivative/Error'
//  '<S115>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S116>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S117>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/I Gain/Internal Parameters'
//  '<S118>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S119>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S120>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Integrator/Discrete'
//  '<S121>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Integrator ICs/Internal IC'
//  '<S122>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/N Copy/Disabled'
//  '<S123>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/N Gain/Internal Parameters'
//  '<S124>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/P Copy/Disabled'
//  '<S125>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S126>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Reset Signal/Disabled'
//  '<S127>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Saturation/Enabled'
//  '<S128>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S129>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Sum/Sum_PID'
//  '<S130>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Sum Fdbk/Disabled'
//  '<S131>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Tracking Mode/Disabled'
//  '<S132>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S133>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S134>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S135>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/postSat Signal/Forward_Path'
//  '<S136>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller/preSat Signal/Forward_Path'
//  '<S137>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Anti-windup'
//  '<S138>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/D Gain'
//  '<S139>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/External Derivative'
//  '<S140>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Filter'
//  '<S141>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Filter ICs'
//  '<S142>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/I Gain'
//  '<S143>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Ideal P Gain'
//  '<S144>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S145>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Integrator'
//  '<S146>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Integrator ICs'
//  '<S147>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/N Copy'
//  '<S148>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/N Gain'
//  '<S149>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/P Copy'
//  '<S150>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Parallel P Gain'
//  '<S151>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Reset Signal'
//  '<S152>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Saturation'
//  '<S153>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Saturation Fdbk'
//  '<S154>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Sum'
//  '<S155>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Sum Fdbk'
//  '<S156>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Tracking Mode'
//  '<S157>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Tracking Mode Sum'
//  '<S158>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Tsamp - Integral'
//  '<S159>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Tsamp - Ngain'
//  '<S160>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/postSat Signal'
//  '<S161>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/preSat Signal'
//  '<S162>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S163>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S164>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S165>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/D Gain/Internal Parameters'
//  '<S166>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/External Derivative/Error'
//  '<S167>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S168>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S169>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/I Gain/Internal Parameters'
//  '<S170>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S171>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S172>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Integrator/Discrete'
//  '<S173>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Integrator ICs/Internal IC'
//  '<S174>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/N Copy/Disabled'
//  '<S175>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/N Gain/Internal Parameters'
//  '<S176>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/P Copy/Disabled'
//  '<S177>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S178>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Reset Signal/Disabled'
//  '<S179>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Saturation/Enabled'
//  '<S180>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S181>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Sum/Sum_PID'
//  '<S182>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S183>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Tracking Mode/Disabled'
//  '<S184>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S185>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S186>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S187>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S188>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S189>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Anti-windup'
//  '<S190>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/D Gain'
//  '<S191>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/External Derivative'
//  '<S192>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Filter'
//  '<S193>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Filter ICs'
//  '<S194>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/I Gain'
//  '<S195>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Ideal P Gain'
//  '<S196>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Ideal P Gain Fdbk'
//  '<S197>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Integrator'
//  '<S198>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Integrator ICs'
//  '<S199>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/N Copy'
//  '<S200>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/N Gain'
//  '<S201>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/P Copy'
//  '<S202>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Parallel P Gain'
//  '<S203>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Reset Signal'
//  '<S204>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Saturation'
//  '<S205>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Saturation Fdbk'
//  '<S206>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Sum'
//  '<S207>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Sum Fdbk'
//  '<S208>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Tracking Mode'
//  '<S209>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Tracking Mode Sum'
//  '<S210>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Tsamp - Integral'
//  '<S211>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Tsamp - Ngain'
//  '<S212>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/postSat Signal'
//  '<S213>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/preSat Signal'
//  '<S214>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S215>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S216>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S217>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/D Gain/Internal Parameters'
//  '<S218>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/External Derivative/Error'
//  '<S219>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S220>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S221>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/I Gain/Internal Parameters'
//  '<S222>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Ideal P Gain/Passthrough'
//  '<S223>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S224>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Integrator/Discrete'
//  '<S225>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Integrator ICs/Internal IC'
//  '<S226>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/N Copy/Disabled'
//  '<S227>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/N Gain/Internal Parameters'
//  '<S228>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/P Copy/Disabled'
//  '<S229>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S230>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Reset Signal/Disabled'
//  '<S231>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Saturation/Enabled'
//  '<S232>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Saturation Fdbk/Disabled'
//  '<S233>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Sum/Sum_PID'
//  '<S234>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Sum Fdbk/Disabled'
//  '<S235>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Tracking Mode/Disabled'
//  '<S236>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S237>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S238>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S239>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/postSat Signal/Forward_Path'
//  '<S240>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller2/preSat Signal/Forward_Path'
//  '<S241>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Anti-windup'
//  '<S242>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/D Gain'
//  '<S243>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/External Derivative'
//  '<S244>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Filter'
//  '<S245>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Filter ICs'
//  '<S246>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/I Gain'
//  '<S247>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Ideal P Gain'
//  '<S248>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Ideal P Gain Fdbk'
//  '<S249>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Integrator'
//  '<S250>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Integrator ICs'
//  '<S251>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/N Copy'
//  '<S252>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/N Gain'
//  '<S253>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/P Copy'
//  '<S254>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Parallel P Gain'
//  '<S255>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Reset Signal'
//  '<S256>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Saturation'
//  '<S257>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Saturation Fdbk'
//  '<S258>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Sum'
//  '<S259>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Sum Fdbk'
//  '<S260>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Tracking Mode'
//  '<S261>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Tracking Mode Sum'
//  '<S262>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Tsamp - Integral'
//  '<S263>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Tsamp - Ngain'
//  '<S264>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/postSat Signal'
//  '<S265>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/preSat Signal'
//  '<S266>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Anti-windup/Disabled'
//  '<S267>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/D Gain/Disabled'
//  '<S268>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/External Derivative/Disabled'
//  '<S269>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Filter/Disabled'
//  '<S270>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Filter ICs/Disabled'
//  '<S271>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/I Gain/Disabled'
//  '<S272>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Ideal P Gain/Passthrough'
//  '<S273>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S274>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Integrator/Disabled'
//  '<S275>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Integrator ICs/Disabled'
//  '<S276>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S277>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/N Gain/Disabled'
//  '<S278>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/P Copy/Disabled'
//  '<S279>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S280>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Reset Signal/Disabled'
//  '<S281>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Saturation/Passthrough'
//  '<S282>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Saturation Fdbk/Disabled'
//  '<S283>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Sum/Passthrough_P'
//  '<S284>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Sum Fdbk/Disabled'
//  '<S285>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Tracking Mode/Disabled'
//  '<S286>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S287>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S288>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S289>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/postSat Signal/Forward_Path'
//  '<S290>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller3/preSat Signal/Forward_Path'
//  '<S291>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Anti-windup'
//  '<S292>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/D Gain'
//  '<S293>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/External Derivative'
//  '<S294>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Filter'
//  '<S295>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Filter ICs'
//  '<S296>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/I Gain'
//  '<S297>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Ideal P Gain'
//  '<S298>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S299>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Integrator'
//  '<S300>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Integrator ICs'
//  '<S301>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/N Copy'
//  '<S302>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/N Gain'
//  '<S303>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/P Copy'
//  '<S304>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Parallel P Gain'
//  '<S305>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Reset Signal'
//  '<S306>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Saturation'
//  '<S307>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Saturation Fdbk'
//  '<S308>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Sum'
//  '<S309>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Sum Fdbk'
//  '<S310>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Tracking Mode'
//  '<S311>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Tracking Mode Sum'
//  '<S312>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Tsamp - Integral'
//  '<S313>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Tsamp - Ngain'
//  '<S314>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/postSat Signal'
//  '<S315>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/preSat Signal'
//  '<S316>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Anti-windup/Disabled'
//  '<S317>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/D Gain/Disabled'
//  '<S318>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/External Derivative/Disabled'
//  '<S319>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Filter/Disabled'
//  '<S320>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Filter ICs/Disabled'
//  '<S321>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/I Gain/Disabled'
//  '<S322>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S323>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S324>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Integrator/Disabled'
//  '<S325>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Integrator ICs/Disabled'
//  '<S326>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S327>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/N Gain/Disabled'
//  '<S328>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/P Copy/Disabled'
//  '<S329>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S330>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Reset Signal/Disabled'
//  '<S331>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Saturation/Passthrough'
//  '<S332>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S333>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Sum/Passthrough_P'
//  '<S334>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S335>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Tracking Mode/Disabled'
//  '<S336>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S337>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S338>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S339>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S340>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Attitude controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S341>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/Altitude Signal conditioning'
//  '<S342>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/Calculate Transformation Matrix'
//  '<S343>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/Calculate minimum Turn'
//  '<S344>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller'
//  '<S345>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1'
//  '<S346>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5'
//  '<S347>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude'
//  '<S348>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz'
//  '<S349>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/Altitude Signal conditioning/Saturation Dynamic'
//  '<S350>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Anti-windup'
//  '<S351>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/D Gain'
//  '<S352>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/External Derivative'
//  '<S353>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Filter'
//  '<S354>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Filter ICs'
//  '<S355>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/I Gain'
//  '<S356>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Ideal P Gain'
//  '<S357>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Ideal P Gain Fdbk'
//  '<S358>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Integrator'
//  '<S359>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Integrator ICs'
//  '<S360>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/N Copy'
//  '<S361>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/N Gain'
//  '<S362>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/P Copy'
//  '<S363>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Parallel P Gain'
//  '<S364>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Reset Signal'
//  '<S365>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Saturation'
//  '<S366>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Saturation Fdbk'
//  '<S367>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Sum'
//  '<S368>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Sum Fdbk'
//  '<S369>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Tracking Mode'
//  '<S370>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Tracking Mode Sum'
//  '<S371>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Tsamp - Integral'
//  '<S372>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Tsamp - Ngain'
//  '<S373>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/postSat Signal'
//  '<S374>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/preSat Signal'
//  '<S375>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Anti-windup/Disabled'
//  '<S376>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/D Gain/Disabled'
//  '<S377>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/External Derivative/Disabled'
//  '<S378>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Filter/Disabled'
//  '<S379>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Filter ICs/Disabled'
//  '<S380>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/I Gain/Disabled'
//  '<S381>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S382>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S383>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Integrator/Disabled'
//  '<S384>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Integrator ICs/Disabled'
//  '<S385>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S386>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/N Gain/Disabled'
//  '<S387>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/P Copy/Disabled'
//  '<S388>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S389>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Reset Signal/Disabled'
//  '<S390>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Saturation/Enabled'
//  '<S391>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S392>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Sum/Passthrough_P'
//  '<S393>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Sum Fdbk/Disabled'
//  '<S394>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Tracking Mode/Disabled'
//  '<S395>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S396>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S397>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S398>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/postSat Signal/Forward_Path'
//  '<S399>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller/preSat Signal/Forward_Path'
//  '<S400>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Anti-windup'
//  '<S401>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/D Gain'
//  '<S402>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/External Derivative'
//  '<S403>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Filter'
//  '<S404>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Filter ICs'
//  '<S405>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/I Gain'
//  '<S406>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Ideal P Gain'
//  '<S407>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S408>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Integrator'
//  '<S409>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Integrator ICs'
//  '<S410>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/N Copy'
//  '<S411>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/N Gain'
//  '<S412>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/P Copy'
//  '<S413>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Parallel P Gain'
//  '<S414>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Reset Signal'
//  '<S415>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Saturation'
//  '<S416>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Saturation Fdbk'
//  '<S417>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Sum'
//  '<S418>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Sum Fdbk'
//  '<S419>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tracking Mode'
//  '<S420>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tracking Mode Sum'
//  '<S421>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tsamp - Integral'
//  '<S422>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tsamp - Ngain'
//  '<S423>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/postSat Signal'
//  '<S424>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/preSat Signal'
//  '<S425>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Anti-windup/Disabled'
//  '<S426>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/D Gain/Disabled'
//  '<S427>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/External Derivative/Disabled'
//  '<S428>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Filter/Disabled'
//  '<S429>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Filter ICs/Disabled'
//  '<S430>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/I Gain/Disabled'
//  '<S431>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S432>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S433>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Integrator/Disabled'
//  '<S434>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Integrator ICs/Disabled'
//  '<S435>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S436>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/N Gain/Disabled'
//  '<S437>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/P Copy/Disabled'
//  '<S438>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S439>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Reset Signal/Disabled'
//  '<S440>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Saturation/Enabled'
//  '<S441>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S442>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Sum/Passthrough_P'
//  '<S443>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S444>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tracking Mode/Disabled'
//  '<S445>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S446>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S447>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S448>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S449>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S450>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Anti-windup'
//  '<S451>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/D Gain'
//  '<S452>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/External Derivative'
//  '<S453>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Filter'
//  '<S454>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Filter ICs'
//  '<S455>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/I Gain'
//  '<S456>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Ideal P Gain'
//  '<S457>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Ideal P Gain Fdbk'
//  '<S458>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Integrator'
//  '<S459>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Integrator ICs'
//  '<S460>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/N Copy'
//  '<S461>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/N Gain'
//  '<S462>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/P Copy'
//  '<S463>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Parallel P Gain'
//  '<S464>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Reset Signal'
//  '<S465>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Saturation'
//  '<S466>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Saturation Fdbk'
//  '<S467>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Sum'
//  '<S468>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Sum Fdbk'
//  '<S469>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tracking Mode'
//  '<S470>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tracking Mode Sum'
//  '<S471>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tsamp - Integral'
//  '<S472>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tsamp - Ngain'
//  '<S473>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/postSat Signal'
//  '<S474>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/preSat Signal'
//  '<S475>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Anti-windup/Disabled'
//  '<S476>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/D Gain/Disabled'
//  '<S477>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/External Derivative/Disabled'
//  '<S478>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Filter/Disabled'
//  '<S479>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Filter ICs/Disabled'
//  '<S480>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/I Gain/Disabled'
//  '<S481>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Ideal P Gain/Passthrough'
//  '<S482>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Ideal P Gain Fdbk/Disabled'
//  '<S483>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Integrator/Disabled'
//  '<S484>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Integrator ICs/Disabled'
//  '<S485>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/N Copy/Disabled wSignal Specification'
//  '<S486>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/N Gain/Disabled'
//  '<S487>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/P Copy/Disabled'
//  '<S488>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Parallel P Gain/Internal Parameters'
//  '<S489>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Reset Signal/Disabled'
//  '<S490>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Saturation/Enabled'
//  '<S491>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Saturation Fdbk/Disabled'
//  '<S492>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Sum/Passthrough_P'
//  '<S493>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Sum Fdbk/Disabled'
//  '<S494>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tracking Mode/Disabled'
//  '<S495>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tracking Mode Sum/Passthrough'
//  '<S496>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tsamp - Integral/TsSignalSpecification'
//  '<S497>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/Tsamp - Ngain/Passthrough'
//  '<S498>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/postSat Signal/Forward_Path'
//  '<S499>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID Controller5/preSat Signal/Forward_Path'
//  '<S500>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Anti-windup'
//  '<S501>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/D Gain'
//  '<S502>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/External Derivative'
//  '<S503>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Filter'
//  '<S504>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Filter ICs'
//  '<S505>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/I Gain'
//  '<S506>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain'
//  '<S507>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S508>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Integrator'
//  '<S509>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Integrator ICs'
//  '<S510>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/N Copy'
//  '<S511>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/N Gain'
//  '<S512>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/P Copy'
//  '<S513>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Parallel P Gain'
//  '<S514>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Reset Signal'
//  '<S515>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Saturation'
//  '<S516>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Saturation Fdbk'
//  '<S517>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Sum'
//  '<S518>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Sum Fdbk'
//  '<S519>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tracking Mode'
//  '<S520>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tracking Mode Sum'
//  '<S521>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tsamp - Integral'
//  '<S522>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tsamp - Ngain'
//  '<S523>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/postSat Signal'
//  '<S524>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/preSat Signal'
//  '<S525>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel'
//  '<S526>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S527>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S528>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/D Gain/Internal Parameters'
//  '<S529>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/External Derivative/Error'
//  '<S530>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Filter/Disc. Forward Euler Filter'
//  '<S531>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Filter ICs/Internal IC - Filter'
//  '<S532>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/I Gain/Internal Parameters'
//  '<S533>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S534>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain Fdbk/Passthrough'
//  '<S535>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Integrator/Discrete'
//  '<S536>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Integrator ICs/Internal IC'
//  '<S537>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/N Copy/Disabled'
//  '<S538>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/N Gain/Internal Parameters'
//  '<S539>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/P Copy/Disabled'
//  '<S540>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Parallel P Gain/Internal Parameters'
//  '<S541>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Reset Signal/Disabled'
//  '<S542>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Saturation/Enabled'
//  '<S543>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Saturation Fdbk/Passthrough'
//  '<S544>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Sum/Sum_PID'
//  '<S545>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Sum Fdbk/Enabled'
//  '<S546>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S547>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S548>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S549>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S550>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/postSat Signal/Feedback_Path'
//  '<S551>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_Altitude/preSat Signal/Feedback_Path'
//  '<S552>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Anti-windup'
//  '<S553>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/D Gain'
//  '<S554>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/External Derivative'
//  '<S555>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Filter'
//  '<S556>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Filter ICs'
//  '<S557>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/I Gain'
//  '<S558>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Ideal P Gain'
//  '<S559>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Ideal P Gain Fdbk'
//  '<S560>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Integrator'
//  '<S561>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Integrator ICs'
//  '<S562>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/N Copy'
//  '<S563>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/N Gain'
//  '<S564>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/P Copy'
//  '<S565>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Parallel P Gain'
//  '<S566>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Reset Signal'
//  '<S567>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Saturation'
//  '<S568>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Saturation Fdbk'
//  '<S569>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Sum'
//  '<S570>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Sum Fdbk'
//  '<S571>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Tracking Mode'
//  '<S572>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Tracking Mode Sum'
//  '<S573>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Tsamp - Integral'
//  '<S574>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Tsamp - Ngain'
//  '<S575>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/postSat Signal'
//  '<S576>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/preSat Signal'
//  '<S577>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel'
//  '<S578>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S579>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S580>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/D Gain/Internal Parameters'
//  '<S581>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/External Derivative/Error'
//  '<S582>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Filter/Disc. Forward Euler Filter'
//  '<S583>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Filter ICs/Internal IC - Filter'
//  '<S584>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/I Gain/Internal Parameters'
//  '<S585>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Ideal P Gain/Passthrough'
//  '<S586>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Ideal P Gain Fdbk/Passthrough'
//  '<S587>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Integrator/Discrete'
//  '<S588>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Integrator ICs/Internal IC'
//  '<S589>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/N Copy/Disabled'
//  '<S590>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/N Gain/Internal Parameters'
//  '<S591>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/P Copy/Disabled'
//  '<S592>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Parallel P Gain/Internal Parameters'
//  '<S593>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Reset Signal/Disabled'
//  '<S594>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Saturation/Enabled'
//  '<S595>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Saturation Fdbk/Passthrough'
//  '<S596>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Sum/Sum_PID'
//  '<S597>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Sum Fdbk/Enabled'
//  '<S598>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Tracking Mode/Disabled'
//  '<S599>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Tracking Mode Sum/Passthrough'
//  '<S600>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Tsamp - Integral/TsSignalSpecification'
//  '<S601>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/Tsamp - Ngain/Passthrough'
//  '<S602>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/postSat Signal/Feedback_Path'
//  '<S603>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Position & Altitude controller/PID_vz/preSat Signal/Feedback_Path'
//  '<S604>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Quaternion Validity Check/Quaternion Norm'
//  '<S605>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Quaternions to Rotation Angles/Angle Calculation'
//  '<S606>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S607>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S608>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S609>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S610>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S611>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S612>' : 'FLIGHT_HEXA_Hovering/Position & Rate Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                                 // FLIGHT_HEXA_Hovering_h_

//
// File trailer for generated code.
//
// [EOF]
//
