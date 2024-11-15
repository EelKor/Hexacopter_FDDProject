//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: F550_FaultInjection.h
//
// Code generated for Simulink model 'F550_FaultInjection'.
//
// Model version                  : 4.153
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Aug 10 17:25:22 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_F550_FaultInjection_h_
#define RTW_HEADER_F550_FaultInjection_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "F550_FaultInjection_types.h"
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
#include "rt_sys_CLAW_70.h"
#include "rt_sys_F550_FaultInjection_44.h"

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

// Block signals for system '<S586>/MATLAB System'
struct B_MATLABSystem_F550_FaultInjection_T {
  real32_T MATLABSystem[3];            // '<S586>/MATLAB System'
  real_T dLat;
};

// Block states (default storage) for system '<S586>/MATLAB System'
struct DW_MATLABSystem_F550_FaultInjection_T {
  px4_internal_block_LLA2LocalCoordinatesNED_F550_FaultInjectio_T obj;// '<S586>/MATLAB System' 
  boolean_T objisempty;                // '<S586>/MATLAB System'
};

// Block signals (default storage)
struct B_F550_FaultInjection_T {
  px4_Bus_vehicle_trajectory_waypoint In1;// '<S585>/In1'
  px4_Bus_vehicle_trajectory_waypoint b_varargout_2_m;
  px4_Bus_vehicle_trajectory_waypoint BusAssignment1;// '<S580>/Bus Assignment1' 
  px4_Bus_vehicle_trajectory_waypoint BusAssignment1_c;// '<S580>/Bus Assignment1' 
  px4_Bus_vehicle_odometry In1_l;      // '<S604>/In1'
  px4_Bus_vehicle_odometry b_varargout_2_k;
  px4_Bus_position_setpoint_triplet In1_p;// '<S597>/In1'
  px4_Bus_position_setpoint_triplet b_varargout_2_c;
  px4_Bus_vehicle_local_position In1_c;// '<S607>/In1'
  px4_Bus_vehicle_local_position b_varargout_2_b;
  px4_Bus_actuator_outputs BusAssignment_l;// '<S10>/Bus Assignment'
  px4_Bus_actuator_outputs BusAssignment_l_p;// '<S10>/Bus Assignment'
  px4_Bus_vehicle_local_position_setpoint BusAssignment_m_c;// '<S560>/Bus Assignment' 
  px4_Bus_vehicle_local_position_setpoint BusAssignment_m_f;// '<S560>/Bus Assignment' 
  px4_Bus_input_rc In1_e;              // '<S46>/In1'
  px4_Bus_input_rc In1_k;              // '<S20>/In1'
  real_T b_waypointsIn_data[9];
  real_T MatrixConcatenate_p[9];       // '<S567>/Matrix Concatenate'
  px4_Bus_vehicle_attitude_setpoint BusAssignment;// '<S24>/Bus Assignment'
  px4_Bus_vehicle_attitude_setpoint BusAssignment_m;// '<S24>/Bus Assignment'
  px4_Bus_trajectory_waypoint BusAssignment1_f;// '<S588>/Bus Assignment1'
  px4_Bus_vehicle_attitude In1_m;      // '<S606>/In1'
  px4_Bus_vehicle_attitude b_varargout_2_g;
  px4_Bus_home_position In1_f;         // '<S596>/In1'
  px4_Bus_home_position b_varargout_2_g1;
  px4_Bus_vehicle_rates_setpoint BusAssignment_j;// '<S25>/Bus Assignment'
  real_T Merge[4];                     // '<S562>/Merge'
  real_T DataTypeConversion[4];        // '<S4>/Data Type Conversion'
  real_T DataTypeConversion2[3];       // '<S4>/Data Type Conversion2'
  real_T b_varargout_3[3];
  real_T lla0[3];
  real_T MatrixConcatenate1[3];        // '<S586>/Matrix Concatenate1'
  real_T MatrixConcatenate1_k[3];      // '<S580>/Matrix Concatenate1'
  real_T rtb_Reshape1_m[3];
  px4_Bus_actuator_armed In1_b;        // '<S605>/In1'
  real_T DataTypeConversion1[7];       // '<S4>/Data Type Conversion1'
  px4_Bus_actuator_armed b_varargout_2_n;
  real_T yaw_In;                       // '<S569>/yaw_In'
  real_T yaw_In_i;                     // '<S573>/yaw_In'
  real_T In;                           // '<S572>/In'
  real_T yaw_In_ik;                    // '<S576>/yaw_In'
  real_T VectorConcatenate[3];         // '<S37>/Vector Concatenate'
  real_T Merge_n[4];                   // '<S2>/Merge'
  real_T Saturation;                   // '<S549>/Saturation'
  real_T Saturation_o;                 // '<S499>/Saturation'
  real_T Saturation_k;                 // '<S449>/Saturation'
  real_T Gain1;                        // '<S149>/Gain1'
  real_T IProdOut;                     // '<S386>/IProd Out'
  real_T Sum;                          // '<S398>/Sum'
  real_T Integrator_g;                 // '<S442>/Integrator'
  real_T Switch_m;                     // '<S483>/Switch'
  real_T NProdOut_a;                   // '<S445>/NProd Out'
  real_T rtb_Switch_es_idx_0;
  real_T rtb_Switch_es_idx_1;
  real_T rtb_Switch_es_idx_2;
  real_T rtb_Switch_es_idx_3;
  real_T VectorConcatenate_tmp;
  real_T VectorConcatenate_tmp_c;
  real_T Gain_i;                       // '<S574>/Gain'
  real_T Sum_f;                        // '<S574>/Sum'
  real_T Gain2_g;                      // '<S5>/Gain2'
  real_T Gain3_k;                      // '<S5>/Gain3'
  real_T Saturation1;                  // '<S12>/Saturation1'
  real_T Saturation1_f;                // '<S13>/Saturation1'
  real_T Saturation1_g;                // '<S14>/Saturation1'
  real_T Saturation1_d;                // '<S15>/Saturation1'
  real_T Saturation1_l;                // '<S16>/Saturation1'
  real_T rtb_MatrixConcatenate1_pp;
  real_T dLat;
  real_T dLon;
  real_T flat;
  real_T absx;
  real_T r;
  real_T flat_tmp;
  real_T absx_l;
  real_T q;
  real_T scale;
  real_T absxk;
  real_T t;
  boolean_T x[6];
  real32_T ParamStep;
  real32_T Gain1_o;                    // '<S47>/Gain1'
  real32_T ParamStep_j;
  int32_T i;
  int32_T i1;
  int32_T ParamStep_d;
  int32_T ParamStep_g;
  int32_T iy;
  int32_T i1_l;
  int32_T j;
  int32_T ix;
  int32_T b_exponent;
  int32_T waypoints_data_tmp;
  int32_T b_k;
  int32_T i_d;
  int32_T i1_d;
  int8_T tmp_data[3];
  boolean_T distinctWptsIdx[3];
  boolean_T b[3];
  boolean_T IsNaN_l[2];                // '<S565>/IsNaN'
  int8_T i2;
  int8_T i3;
  int8_T rtPrevAction;
  int8_T rtAction;
  boolean_T b_varargout_2;
  boolean_T RelationalOperator_i;      // '<S533>/Relational Operator'
  boolean_T fixforDTpropagationissue_h;// '<S533>/fix for DT propagation issue'
  boolean_T RelationalOperator_h;      // '<S483>/Relational Operator'
  boolean_T fixforDTpropagationissue_c;// '<S483>/fix for DT propagation issue'
  boolean_T Compare_k;                 // '<S11>/Compare'
  boolean_T OR_g;                      // '<S565>/OR'
  boolean_T Compare;                   // '<S18>/Compare'
  boolean_T latp2;
  B_PX4Timestamp_F550_FaultInjection_T PX4Timestamp_p;// '<S24>/PX4 Timestamp'
  B_MATLABSystem_F550_FaultInjection_T MATLABSystem_b;// '<S586>/MATLAB System'
  B_MATLABSystem_F550_FaultInjection_T MATLABSystem;// '<S586>/MATLAB System'
  B_PX4Timestamp_F550_FaultInjection_T PX4Timestamp;// '<S24>/PX4 Timestamp'
  B_SourceBlock_F550_FaultInjection_T SourceBlock_b;// '<S19>/SourceBlock'
  B_PX4Timestamp_F550_FaultInjection_T PX4Timestamp_pna;// '<S24>/PX4 Timestamp' 
  B_PX4Timestamp_F550_FaultInjection_T PX4Timestamp_pn;// '<S24>/PX4 Timestamp'
  B_SourceBlock_F550_FaultInjection_T SourceBlock;// '<S19>/SourceBlock'
};

// Block states (default storage) for system '<Root>'
struct DW_F550_FaultInjection_T {
  uav_sluav_internal_system_WaypointFollower_F550_FaultInjectio_T obj;// '<S567>/UAV Waypoint Follower' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_b;// '<S594>/Read Parameter' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_g;// '<S595>/Read Parameter' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_k;// '<S563>/Read Parameter' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_k1;// '<S31>/Read Parameter24' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_p;// '<S31>/Read Parameter23' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_l;// '<S31>/Read Parameter22' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_m;// '<S31>/Read Parameter21' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_d;// '<S31>/Read Parameter20' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_pe;// '<S31>/Read Parameter19' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_pa;// '<S31>/Read Parameter18' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_dn;// '<S31>/Read Parameter17' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_p4;// '<S31>/Read Parameter16' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_j;// '<S29>/Read Parameter9' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_o;// '<S29>/Read Parameter6' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_m4;// '<S29>/Read Parameter5' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_bt;// '<S29>/Read Parameter10' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_l0;// '<S30>/Read Parameter8' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_d3;// '<S30>/Read Parameter7' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_ds;// '<S30>/Read Parameter4' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_f;// '<S30>/Read Parameter3' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_pc;// '<S30>/Read Parameter2' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_ba;// '<S30>/Read Parameter15' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_a;// '<S30>/Read Parameter14' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_km;// '<S30>/Read Parameter13' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_mn;// '<S30>/Read Parameter12' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_kf;// '<S30>/Read Parameter11' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_j0;// '<S30>/Read Parameter1' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_bu;// '<S30>/Read Parameter' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_p1;// '<S7>/Read Parameter5' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_c;// '<S7>/Read Parameter4' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_n;// '<S7>/Read Parameter3' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_ng;// '<S7>/Read Parameter2' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_ka;// '<S7>/Read Parameter13' 
  px4_internal_block_ParameterUpdate_F550_FaultInjection_T obj_a4;// '<S7>/Read Parameter1' 
  px4_internal_block_Subscriber_F550_FaultInjection_T obj_mg;// '<S603>/SourceBlock' 
  px4_internal_block_Subscriber_F550_FaultInjection_T obj_gv;// '<S602>/SourceBlock' 
  px4_internal_block_Subscriber_F550_FaultInjection_T obj_d0;// '<S601>/SourceBlock' 
  px4_internal_block_Subscriber_F550_FaultInjection_T obj_po;// '<S600>/SourceBlock' 
  px4_internal_block_Subscriber_F550_FaultInjection_T obj_kz;// '<S582>/SourceBlock' 
  px4_internal_block_Subscriber_F550_FaultInjection_T obj_gf;// '<S581>/SourceBlock' 
  px4_internal_block_Subscriber_F550_FaultInjection_T obj_e;// '<S584>/SourceBlock' 
  px4_internal_block_Publisher_F550_FaultInjection_T obj_o2;// '<S599>/SinkBlock' 
  px4_internal_block_Publisher_F550_FaultInjection_T obj_mc;// '<S591>/SinkBlock' 
  px4_internal_block_Publisher_F550_FaultInjection_T obj_ln;// '<S35>/SinkBlock' 
  px4_internal_block_Publisher_F550_FaultInjection_T obj_i;// '<S33>/SinkBlock'
  px4_internal_block_Publisher_F550_FaultInjection_T obj_h;// '<S22>/SinkBlock'
  px4_internal_block_LLA2LocalCoordinates_F550_FaultInjection_T obj_mr;// '<S563>/LLA2LocalCoordinates' 
  real_T Delay_DSTATE;                 // '<S568>/Delay'
  real_T Delay_DSTATE_l[2];            // '<S565>/Delay'
  real_T Delay_DSTATE_n;               // '<S570>/Delay'
  real_T Delay_DSTATE_b;               // '<S571>/Delay'
  real_T Delay_DSTATE_c;               // '<S574>/Delay'
  real_T Delay_DSTATE_d;               // '<S575>/Delay'
  real_T Integrator_DSTATE;            // '<S542>/Integrator'
  real_T Filter_DSTATE;                // '<S537>/Filter'
  real_T Integrator_DSTATE_h;          // '<S492>/Integrator'
  real_T Filter_DSTATE_e;              // '<S487>/Filter'
  real_T Integrator_DSTATE_d;          // '<S442>/Integrator'
  real_T Filter_DSTATE_a;              // '<S437>/Filter'
  real_T Filter_DSTATE_k;              // '<S384>/Filter'
  real_T Integrator_DSTATE_o;          // '<S389>/Integrator'
  real_T PrevY;                        // '<S29>/Rate Limiter2'
  real_T PrevY_h;                      // '<S29>/Rate Limiter1'
  px4_internal_block_LLA2LocalCoordinatesNED_F550_FaultInjectio_T obj_mu;// '<S589>/MATLAB System' 
  int8_T If_ActiveSubsystem;           // '<S562>/If'
  DW_PX4Timestamp_F550_FaultInjection_T PX4Timestamp_p;// '<S24>/PX4 Timestamp'
  DW_MATLABSystem_F550_FaultInjection_T MATLABSystem_b;// '<S586>/MATLAB System' 
  DW_MATLABSystem_F550_FaultInjection_T MATLABSystem;// '<S586>/MATLAB System'
  DW_PX4Timestamp_F550_FaultInjection_T PX4Timestamp;// '<S24>/PX4 Timestamp'
  DW_SourceBlock_F550_FaultInjection_T SourceBlock_b;// '<S19>/SourceBlock'
  DW_PX4Timestamp_F550_FaultInjection_T PX4Timestamp_pna;// '<S24>/PX4 Timestamp' 
  DW_PX4Timestamp_F550_FaultInjection_T PX4Timestamp_pn;// '<S24>/PX4 Timestamp' 
  DW_SourceBlock_F550_FaultInjection_T SourceBlock;// '<S19>/SourceBlock'
};

// Parameters (default storage)
struct P_F550_FaultInjection_T_ {
  real_T PID_vz_InitialConditionForFilter;
                             // Mask Parameter: PID_vz_InitialConditionForFilter
                                //  Referenced by: '<S384>/Filter'

  real_T PIDController2_InitialConditionForFilter;
                     // Mask Parameter: PIDController2_InitialConditionForFilter
                        //  Referenced by: '<S537>/Filter'

  real_T PIDController1_InitialConditionForFilter;
                     // Mask Parameter: PIDController1_InitialConditionForFilter
                        //  Referenced by: '<S487>/Filter'

  real_T PIDController_InitialConditionForFilter;
                      // Mask Parameter: PIDController_InitialConditionForFilter
                         //  Referenced by: '<S437>/Filter'

  real_T PID_vz_InitialConditionForIntegrator;
                         // Mask Parameter: PID_vz_InitialConditionForIntegrator
                            //  Referenced by: '<S389>/Integrator'

  real_T PIDController2_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController2_InitialConditionForIntegrator
                    //  Referenced by: '<S542>/Integrator'

  real_T PIDController1_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController1_InitialConditionForIntegrator
                    //  Referenced by: '<S492>/Integrator'

  real_T PIDController_InitialConditionForIntegrator;
                  // Mask Parameter: PIDController_InitialConditionForIntegrator
                     //  Referenced by: '<S442>/Integrator'

  real_T PID_vz_LowerSaturationLimit;
                                  // Mask Parameter: PID_vz_LowerSaturationLimit
                                     //  Referenced by:
                                     //    '<S396>/Saturation'
                                     //    '<S382>/DeadZone'

  real_T PIDController2_LowerSaturationLimit;
                          // Mask Parameter: PIDController2_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S549>/Saturation'
                             //    '<S535>/DeadZone'

  real_T PIDController1_LowerSaturationLimit;
                          // Mask Parameter: PIDController1_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S499>/Saturation'
                             //    '<S485>/DeadZone'

  real_T PIDController_LowerSaturationLimit;
                           // Mask Parameter: PIDController_LowerSaturationLimit
                              //  Referenced by:
                              //    '<S449>/Saturation'
                              //    '<S435>/DeadZone'

  real_T PID_vz_UpperSaturationLimit;
                                  // Mask Parameter: PID_vz_UpperSaturationLimit
                                     //  Referenced by:
                                     //    '<S396>/Saturation'
                                     //    '<S382>/DeadZone'

  real_T PIDController2_UpperSaturationLimit;
                          // Mask Parameter: PIDController2_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S549>/Saturation'
                             //    '<S535>/DeadZone'

  real_T PIDController1_UpperSaturationLimit;
                          // Mask Parameter: PIDController1_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S499>/Saturation'
                             //    '<S485>/DeadZone'

  real_T PIDController_UpperSaturationLimit;
                           // Mask Parameter: PIDController_UpperSaturationLimit
                              //  Referenced by:
                              //    '<S449>/Saturation'
                              //    '<S435>/DeadZone'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S11>/Constant'

  uint16_T CompareToConstant_const_k;
                                    // Mask Parameter: CompareToConstant_const_k
                                       //  Referenced by: '<S18>/Constant'

  uint8_T CompareToConstant_const_d;// Mask Parameter: CompareToConstant_const_d
                                       //  Referenced by: '<S578>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Out1_Y0;// Computed Parameter: Out1_Y0
                                                 //  Referenced by: '<S585>/Out1'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value;// Computed Parameter: Constant_Value
                                                        //  Referenced by: '<S590>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                          //  Referenced by: '<S584>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0_e;  // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S604>/Out1'

  px4_Bus_vehicle_odometry Constant_Value_n;// Computed Parameter: Constant_Value_n
                                               //  Referenced by: '<S600>/Constant'

  px4_Bus_position_setpoint_triplet Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                 //  Referenced by: '<S597>/Out1'

  px4_Bus_position_setpoint_triplet Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                        //  Referenced by: '<S582>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                              //  Referenced by: '<S607>/Out1'

  px4_Bus_vehicle_local_position Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                     //  Referenced by: '<S603>/Constant'

  px4_Bus_actuator_outputs Constant_Value_c;// Computed Parameter: Constant_Value_c
                                               //  Referenced by: '<S21>/Constant'

  px4_Bus_vehicle_local_position_setpoint Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                              //  Referenced by: '<S598>/Constant'

  px4_Bus_input_rc Out1_Y0_i;          // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S20>/Out1'

  px4_Bus_input_rc Out1_Y0_ii;         // Computed Parameter: Out1_Y0_ii
                                          //  Referenced by: '<S46>/Out1'

  px4_Bus_input_rc Constant_Value_f;   // Computed Parameter: Constant_Value_f
                                          //  Referenced by: '<S45>/Constant'

  px4_Bus_input_rc Constant_Value_l;   // Computed Parameter: Constant_Value_l
                                          //  Referenced by: '<S19>/Constant'

  px4_Bus_vehicle_attitude_setpoint Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                        //  Referenced by: '<S32>/Constant'

  px4_Bus_vehicle_attitude Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S606>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_lh;// Computed Parameter: Constant_Value_lh
                                                //  Referenced by: '<S602>/Constant'

  px4_Bus_home_position Out1_Y0_o;     // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S596>/Out1'

  px4_Bus_home_position Constant_Value_b;// Computed Parameter: Constant_Value_b
                                            //  Referenced by: '<S581>/Constant'

  px4_Bus_vehicle_rates_setpoint Constant_Value_c4;// Computed Parameter: Constant_Value_c4
                                                      //  Referenced by: '<S34>/Constant'

  px4_Bus_actuator_armed Out1_Y0_d;    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S605>/Out1'

  px4_Bus_actuator_armed Constant_Value_j;// Computed Parameter: Constant_Value_j
                                             //  Referenced by: '<S601>/Constant'

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

  real_T Constant_Value_fl;            // Expression: 1100
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

  real_T Constant_Value_a0;            // Expression: 1100
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

  real_T Constant_Value_gu;            // Expression: 1100
                                          //  Referenced by: '<S23>/Constant'

  real_T Gain_Gain_e;                  // Expression: 1/800
                                          //  Referenced by: '<S23>/Gain'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<S23>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S23>/Saturation'

  real_T Constant1_Value_n;            // Expression: 1500
                                          //  Referenced by: '<S23>/Constant1'

  real_T Gain1_Gain;                   // Expression: 1/400
                                          //  Referenced by: '<S23>/Gain1'

  real_T Saturation1_UpperSat_k;       // Expression: 1
                                          //  Referenced by: '<S23>/Saturation1'

  real_T Saturation1_LowerSat_i;       // Expression: -1
                                          //  Referenced by: '<S23>/Saturation1'

  real_T Constant2_Value_k;            // Expression: 1500
                                          //  Referenced by: '<S23>/Constant2'

  real_T Gain2_Gain;                   // Expression: 1/400
                                          //  Referenced by: '<S23>/Gain2'

  real_T Saturation2_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S23>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S23>/Saturation2'

  real_T Constant3_Value_j;            // Expression: 1500
                                          //  Referenced by: '<S23>/Constant3'

  real_T Gain3_Gain;                   // Expression: 1/400
                                          //  Referenced by: '<S23>/Gain3'

  real_T Saturation3_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S23>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S23>/Saturation3'

  real_T Constant_Value_gl;            // Expression: 0
                                          //  Referenced by: '<S149>/Constant'

  real_T Switch1_Threshold;            // Expression: 0
                                          //  Referenced by: '<S151>/Switch1'

  real_T ReadParameter_SampleTime;     // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter'

  real_T ReadParameter1_SampleTime_o;  // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter1'

  real_T ReadParameter11_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter11'

  real_T ReadParameter12_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter12'

  real_T ReadParameter13_SampleTime_c; // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter13'

  real_T ReadParameter14_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter14'

  real_T ReadParameter15_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter15'

  real_T ReadParameter2_SampleTime_m;  // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter2'

  real_T ReadParameter3_SampleTime_l;  // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter3'

  real_T ReadParameter4_SampleTime_b;  // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter4'

  real_T ReadParameter7_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter7'

  real_T ReadParameter8_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S30>/Read Parameter8'

  real_T Constant1_Value_f;            // Expression: 0
                                          //  Referenced by: '<S380>/Constant1'

  real_T Gain1_Gain_j;                 // Expression: -1
                                          //  Referenced by: '<S149>/Gain1'

  real_T Gain_Gain_j;                  // Expression: -1
                                          //  Referenced by: '<S150>/Gain'

  real_T Constant_Value_jc;            // Expression: 2*pi
                                          //  Referenced by: '<S151>/Constant'

  real_T Switch_Threshold;             // Expression: pi
                                          //  Referenced by: '<S151>/Switch'

  real_T Gain1_Gain_m;                 // Expression: -1
                                          //  Referenced by: '<S30>/Gain1'

  real_T Gain3_Gain_k;                 // Expression: -1
                                          //  Referenced by: '<S30>/Gain3'

  real_T Clamping_zero_Value;          // Expression: 0
                                          //  Referenced by: '<S380>/Clamping_zero'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S384>/Filter'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S389>/Integrator'

  real_T Constant_Value_aa[4];         // Expression: [1 0 0 0]
                                          //  Referenced by: '<S26>/Constant'

  real_T Constant_Value_ch;            // Expression: 1
                                          //  Referenced by: '<S40>/Constant'

  real_T Constant_Value_ex;            // Expression: 1
                                          //  Referenced by: '<S41>/Constant'

  real_T ReadParameter10_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S29>/Read Parameter10'

  real_T ReadParameter5_SampleTime_m;  // Expression: -1
                                          //  Referenced by: '<S29>/Read Parameter5'

  real_T ReadParameter6_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S29>/Read Parameter6'

  real_T ReadParameter9_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S29>/Read Parameter9'

  real_T ReadParameter16_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S31>/Read Parameter16'

  real_T ReadParameter17_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S31>/Read Parameter17'

  real_T ReadParameter18_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S31>/Read Parameter18'

  real_T ReadParameter19_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S31>/Read Parameter19'

  real_T ReadParameter20_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S31>/Read Parameter20'

  real_T ReadParameter21_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S31>/Read Parameter21'

  real_T ReadParameter22_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S31>/Read Parameter22'

  real_T ReadParameter23_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S31>/Read Parameter23'

  real_T ReadParameter24_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S31>/Read Parameter24'

  real_T tau_Yaw_Y0;                   // Computed Parameter: tau_Yaw_Y0
                                          //  Referenced by: '<S2>/tau_Yaw'

  real_T tau_Pitch_Y0;                 // Computed Parameter: tau_Pitch_Y0
                                          //  Referenced by: '<S2>/tau_Pitch'

  real_T tau_Roll_Y0;                  // Computed Parameter: tau_Roll_Y0
                                          //  Referenced by: '<S2>/tau_Roll'

  real_T Constant1_Value_fh;           // Expression: 0
                                          //  Referenced by: '<S433>/Constant1'

  real_T Constant1_Value_nh;           // Expression: 0
                                          //  Referenced by: '<S483>/Constant1'

  real_T Constant1_Value_i;            // Expression: 0
                                          //  Referenced by: '<S533>/Constant1'

  real_T Switch_Threshold_n;           // Expression: 0
                                          //  Referenced by: '<S26>/Switch'

  real_T Merge_InitialOutput;         // Computed Parameter: Merge_InitialOutput
                                         //  Referenced by: '<S2>/Merge'

  real_T thrust_sp_bX_Value;           // Expression: 0
                                          //  Referenced by: '<S24>/thrust_sp_bX'

  real_T thrust_sp_bY_Value;           // Expression: 0
                                          //  Referenced by: '<S24>/thrust_sp_bY'

  real_T thrust_sp_bX_Value_m;         // Expression: 0
                                          //  Referenced by: '<S25>/thrust_sp_bX'

  real_T thrust_sp_bY_Value_f;         // Expression: 0
                                          //  Referenced by: '<S25>/thrust_sp_bY'

  real_T RateLimiter2_RisingLim;       // Expression: 180*pi/180
                                          //  Referenced by: '<S29>/Rate Limiter2'

  real_T RateLimiter2_FallingLim;      // Expression: -180*pi/180
                                          //  Referenced by: '<S29>/Rate Limiter2'

  real_T RateLimiter2_IC;              // Expression: 0
                                          //  Referenced by: '<S29>/Rate Limiter2'

  real_T RateLimiter1_RisingLim;       // Expression: 180*pi/180
                                          //  Referenced by: '<S29>/Rate Limiter1'

  real_T RateLimiter1_FallingLim;      // Expression: -180*pi/180
                                          //  Referenced by: '<S29>/Rate Limiter1'

  real_T RateLimiter1_IC;              // Expression: 0
                                          //  Referenced by: '<S29>/Rate Limiter1'

  real_T Integrator_gainval_n;       // Computed Parameter: Integrator_gainval_n
                                        //  Referenced by: '<S542>/Integrator'

  real_T Constant2_Value_o4;           // Expression: 50
                                          //  Referenced by: '<S31>/Constant2'

  real_T Filter_gainval_d;             // Computed Parameter: Filter_gainval_d
                                          //  Referenced by: '<S537>/Filter'

  real_T Clamping_zero_Value_g;        // Expression: 0
                                          //  Referenced by: '<S533>/Clamping_zero'

  real_T Integrator_gainval_c;       // Computed Parameter: Integrator_gainval_c
                                        //  Referenced by: '<S492>/Integrator'

  real_T Constant1_Value_e;            // Expression: 50
                                          //  Referenced by: '<S31>/Constant1'

  real_T Filter_gainval_c;             // Computed Parameter: Filter_gainval_c
                                          //  Referenced by: '<S487>/Filter'

  real_T Clamping_zero_Value_gi;       // Expression: 0
                                          //  Referenced by: '<S483>/Clamping_zero'

  real_T Integrator_gainval_p;       // Computed Parameter: Integrator_gainval_p
                                        //  Referenced by: '<S442>/Integrator'

  real_T Constant_Value_lz;            // Expression: 100
                                          //  Referenced by: '<S31>/Constant'

  real_T Filter_gainval_dc;            // Computed Parameter: Filter_gainval_dc
                                          //  Referenced by: '<S437>/Filter'

  real_T Clamping_zero_Value_m;        // Expression: 0
                                          //  Referenced by: '<S433>/Clamping_zero'

  real_T yaw_Out_Y0;                   // Computed Parameter: yaw_Out_Y0
                                          //  Referenced by: '<S576>/yaw_Out'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S574>/Delay'

  real_T Rate_Value;                   // Expression: 0.01
                                          //  Referenced by: '<S574>/Rate'

  real_T Gain1_Gain_b;                 // Expression: -1
                                          //  Referenced by: '<S574>/Gain1'

  real_T Gain_Gain_e3;                 // Expression: -1
                                          //  Referenced by: '<S574>/Gain'

  real_T Delay_InitialCondition_g;     // Expression: 1
                                          //  Referenced by: '<S575>/Delay'

  real_T Constant_Value_fo;            // Expression: 0
                                          //  Referenced by: '<S575>/Constant'

  real_T Out_Y0;                       // Computed Parameter: Out_Y0
                                          //  Referenced by: '<S572>/Out'

  real_T Gain_Gain_l;                  // Expression: -1
                                          //  Referenced by: '<S570>/Gain'

  real_T yaw_Out_Y0_f;                 // Computed Parameter: yaw_Out_Y0_f
                                          //  Referenced by: '<S573>/yaw_Out'

  real_T Delay_InitialCondition_n;     // Expression: 0.0
                                          //  Referenced by: '<S565>/Delay'

  real_T Delay_InitialCondition_m;     // Expression: 0.0
                                          //  Referenced by: '<S570>/Delay'

  real_T Switch_Threshold_j;           // Expression: 0
                                          //  Referenced by: '<S570>/Switch'

  real_T Rateofdescent_Value;          // Expression: 0.02
                                          //  Referenced by: '<S570>/Rate of descent'

  real_T Gain2_Gain_g;                 // Expression: -1
                                          //  Referenced by: '<S570>/Gain2'

  real_T Gain1_Gain_a;                 // Expression: -1
                                          //  Referenced by: '<S570>/Gain1'

  real_T Delay_InitialCondition_j;     // Expression: 1
                                          //  Referenced by: '<S571>/Delay'

  real_T Constant_Value_nn;            // Expression: 0
                                          //  Referenced by: '<S571>/Constant'

  real_T Constant_Value_jd;            // Expression: 0
                                          //  Referenced by: '<S577>/Constant'

  real_T Constant_Value_gw;            // Expression: 6
                                          //  Referenced by: '<S567>/Constant'

  real_T yaw_Out_Y0_p;                 // Computed Parameter: yaw_Out_Y0_p
                                          //  Referenced by: '<S569>/yaw_Out'

  real_T Delay_InitialCondition_g0;    // Expression: 1
                                          //  Referenced by: '<S568>/Delay'

  real_T Constant_Value_ic;            // Expression: 0
                                          //  Referenced by: '<S568>/Constant'

  real_T ReadParameter_SampleTime_d;   // Expression: -1
                                          //  Referenced by: '<S563>/Read Parameter'

  real_T ReadParameter_SampleTime_c;   // Expression: -1
                                          //  Referenced by: '<S595>/Read Parameter'

  real_T ReadParameter_SampleTime_g;   // Expression: -1
                                          //  Referenced by: '<S594>/Read Parameter'

  real_T Gain_Gain_jo;                 // Expression: 5
                                          //  Referenced by: '<S5>/Gain'

  real_T Gain1_Gain_j0;                // Expression: 5
                                          //  Referenced by: '<S5>/Gain1'

  real_T Gain2_Gain_f;                 // Expression: 10
                                          //  Referenced by: '<S5>/Gain2'

  real_T Gain3_Gain_c;                 // Expression: 1
                                          //  Referenced by: '<S5>/Gain3'

  real_T Constant_Value_gp;            // Expression: 0
                                          //  Referenced by: '<S10>/Constant'

  real_T Constant17_Value;             // Expression: 6
                                          //  Referenced by: '<S10>/Constant17'

  uint64_T Constant7_Value;            // Computed Parameter: Constant7_Value
                                          //  Referenced by: '<S588>/Constant7'

  real32_T Constant_Value_gk;          // Computed Parameter: Constant_Value_gk
                                          //  Referenced by: '<S30>/Constant'

  real32_T Gain1_Gain_p;               // Computed Parameter: Gain1_Gain_p
                                          //  Referenced by: '<S152>/Gain1'

  real32_T Gain1_Gain_f;               // Computed Parameter: Gain1_Gain_f
                                          //  Referenced by: '<S153>/Gain1'

  real32_T Gain_Gain_dz;               // Computed Parameter: Gain_Gain_dz
                                          //  Referenced by: '<S30>/Gain'

  real32_T Gain2_Gain_a;               // Computed Parameter: Gain2_Gain_a
                                          //  Referenced by: '<S30>/Gain2'

  real32_T Gain1_Gain_l;               // Computed Parameter: Gain1_Gain_l
                                          //  Referenced by: '<S47>/Gain1'

  real32_T Gain1_Gain_c;               // Computed Parameter: Gain1_Gain_c
                                          //  Referenced by: '<S48>/Gain1'

  real32_T Constant1_Value_d[2];       // Computed Parameter: Constant1_Value_d
                                          //  Referenced by: '<S595>/Constant1'

  real32_T Constant_Value_f2;          // Computed Parameter: Constant_Value_f2
                                          //  Referenced by: '<S595>/Constant'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S594>/Gain'

  real32_T Constant1_Value_k[2];       // Computed Parameter: Constant1_Value_k
                                          //  Referenced by: '<S594>/Constant1'

  real32_T Constant_Value_l4;          // Computed Parameter: Constant_Value_l4
                                          //  Referenced by: '<S594>/Constant'

  real32_T Constant_Value_fh[3];       // Computed Parameter: Constant_Value_fh
                                          //  Referenced by: '<S588>/Constant'

  real32_T Constant1_Value_h[3];       // Computed Parameter: Constant1_Value_h
                                          //  Referenced by: '<S588>/Constant1'

  real32_T Constant2_Value_f[3];       // Computed Parameter: Constant2_Value_f
                                          //  Referenced by: '<S588>/Constant2'

  real32_T Constant3_Value_a;          // Computed Parameter: Constant3_Value_a
                                          //  Referenced by: '<S588>/Constant3'

  real32_T Constant4_Value_g;          // Computed Parameter: Constant4_Value_g
                                          //  Referenced by: '<S588>/Constant4'

  boolean_T Constant5_Value_j;         // Computed Parameter: Constant5_Value_j
                                          //  Referenced by: '<S586>/Constant5'

  boolean_T Constant5_Value_k;         // Computed Parameter: Constant5_Value_k
                                          //  Referenced by: '<S587>/Constant5'

  boolean_T Constant1_Value_dl;        // Computed Parameter: Constant1_Value_dl
                                          //  Referenced by: '<S589>/Constant1'

  boolean_T Constant5_Value_h;         // Computed Parameter: Constant5_Value_h
                                          //  Referenced by: '<S589>/Constant5'

  boolean_T Constant5_Value_l;         // Computed Parameter: Constant5_Value_l
                                          //  Referenced by: '<S588>/Constant5'

  int8_T Constant_Value_dl;            // Computed Parameter: Constant_Value_dl
                                          //  Referenced by: '<S380>/Constant'

  int8_T Constant2_Value_c;            // Computed Parameter: Constant2_Value_c
                                          //  Referenced by: '<S380>/Constant2'

  int8_T Constant3_Value_k;            // Computed Parameter: Constant3_Value_k
                                          //  Referenced by: '<S380>/Constant3'

  int8_T Constant4_Value_b;            // Computed Parameter: Constant4_Value_b
                                          //  Referenced by: '<S380>/Constant4'

  int8_T Constant_Value_dm;            // Computed Parameter: Constant_Value_dm
                                          //  Referenced by: '<S433>/Constant'

  int8_T Constant2_Value_l;            // Computed Parameter: Constant2_Value_l
                                          //  Referenced by: '<S433>/Constant2'

  int8_T Constant3_Value_by;           // Computed Parameter: Constant3_Value_by
                                          //  Referenced by: '<S433>/Constant3'

  int8_T Constant4_Value_i;            // Computed Parameter: Constant4_Value_i
                                          //  Referenced by: '<S433>/Constant4'

  int8_T Constant_Value_ol;            // Computed Parameter: Constant_Value_ol
                                          //  Referenced by: '<S483>/Constant'

  int8_T Constant2_Value_d;            // Computed Parameter: Constant2_Value_d
                                          //  Referenced by: '<S483>/Constant2'

  int8_T Constant3_Value_m;            // Computed Parameter: Constant3_Value_m
                                          //  Referenced by: '<S483>/Constant3'

  int8_T Constant4_Value_m;            // Computed Parameter: Constant4_Value_m
                                          //  Referenced by: '<S483>/Constant4'

  int8_T Constant_Value_ix;            // Computed Parameter: Constant_Value_ix
                                          //  Referenced by: '<S533>/Constant'

  int8_T Constant2_Value_f2;           // Computed Parameter: Constant2_Value_f2
                                          //  Referenced by: '<S533>/Constant2'

  int8_T Constant3_Value_ki;           // Computed Parameter: Constant3_Value_ki
                                          //  Referenced by: '<S533>/Constant3'

  int8_T Constant4_Value_l;            // Computed Parameter: Constant4_Value_l
                                          //  Referenced by: '<S533>/Constant4'

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
                                          //  Referenced by: '<S580>/Constant'

  uint8_T Constant6_Value;             // Computed Parameter: Constant6_Value
                                          //  Referenced by: '<S588>/Constant6'

};

// Real-time Model Data Structure
struct tag_RTM_F550_FaultInjection_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_F550_FaultInjection_T F550_FaultInjection_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_F550_FaultInjection_T F550_FaultInjection_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_F550_FaultInjection_T F550_FaultInjection_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void F550_FaultInjection_initialize(void);
  extern void F550_FaultInjection_step(void);
  extern void F550_FaultInjection_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_F550_FaultInjection_T *const F550_FaultInjection_M;

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
//  Block '<S28>/Bitwise Operator' : Unused code path elimination
//  Block '<S28>/Data Type Conversion' : Unused code path elimination
//  Block '<S28>/Data Type Conversion1' : Unused code path elimination
//  Block '<S28>/Data Type Conversion2' : Unused code path elimination
//  Block '<S28>/Gain' : Unused code path elimination
//  Block '<S28>/Gain1' : Unused code path elimination
//  Block '<S45>/NOT' : Unused code path elimination
//  Block '<S2>/Scope' : Unused code path elimination
//  Block '<S90>/Data Type Duplicate' : Unused code path elimination
//  Block '<S90>/Data Type Propagation' : Unused code path elimination
//  Block '<S139>/Data Type Duplicate' : Unused code path elimination
//  Block '<S139>/Data Type Propagation' : Unused code path elimination
//  Block '<S159>/Data Type Duplicate' : Unused code path elimination
//  Block '<S159>/Data Type Propagation' : Unused code path elimination
//  Block '<S199>/Data Type Duplicate' : Unused code path elimination
//  Block '<S199>/Data Type Propagation' : Unused code path elimination
//  Block '<S248>/Data Type Duplicate' : Unused code path elimination
//  Block '<S248>/Data Type Propagation' : Unused code path elimination
//  Block '<S297>/Data Type Duplicate' : Unused code path elimination
//  Block '<S297>/Data Type Propagation' : Unused code path elimination
//  Block '<S346>/Data Type Duplicate' : Unused code path elimination
//  Block '<S346>/Data Type Propagation' : Unused code path elimination
//  Block '<S583>/Compare' : Unused code path elimination
//  Block '<S583>/Constant' : Unused code path elimination
//  Block '<S584>/NOT' : Unused code path elimination
//  Block '<S579>/Subtract' : Unused code path elimination
//  Block '<S581>/NOT' : Unused code path elimination
//  Block '<S582>/NOT' : Unused code path elimination
//  Block '<S600>/NOT' : Unused code path elimination
//  Block '<S601>/NOT' : Unused code path elimination
//  Block '<S602>/NOT' : Unused code path elimination
//  Block '<S603>/NOT' : Unused code path elimination
//  Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S24>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S565>/Reshape1' : Reshape block reduction
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
//  '<Root>' : 'F550_FaultInjection'
//  '<S1>'   : 'F550_FaultInjection/Actuator'
//  '<S2>'   : 'F550_FaultInjection/CLAW'
//  '<S3>'   : 'F550_FaultInjection/Navigation'
//  '<S4>'   : 'F550_FaultInjection/uORBInput'
//  '<S5>'   : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block'
//  '<S6>'   : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/Emergency Kill'
//  '<S7>'   : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/Fault_Injection'
//  '<S8>'   : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/MATLAB Function'
//  '<S9>'   : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/Radio Control Transmitter'
//  '<S10>'  : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/Subsystem'
//  '<S11>'  : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/Emergency Kill/Compare To Constant'
//  '<S12>'  : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM'
//  '<S13>'  : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM1'
//  '<S14>'  : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM2'
//  '<S15>'  : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM3'
//  '<S16>'  : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM4'
//  '<S17>'  : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM5'
//  '<S18>'  : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Compare To Constant'
//  '<S19>'  : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/Radio Control Transmitter/PX4 uORB Read'
//  '<S20>'  : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S21>'  : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/Subsystem/PX4 uORB Message'
//  '<S22>'  : 'F550_FaultInjection/Actuator/Custom Mixer and PWM Output Block/Subsystem/PX4 uORB Write'
//  '<S23>'  : 'F550_FaultInjection/CLAW/PWM2CMD'
//  '<S24>'  : 'F550_FaultInjection/CLAW/Publish vehicle_attitude_setpoint'
//  '<S25>'  : 'F550_FaultInjection/CLAW/Publish vehicle_rate_setpoint'
//  '<S26>'  : 'F550_FaultInjection/CLAW/Quaternion Validity Check'
//  '<S27>'  : 'F550_FaultInjection/CLAW/Quaternions to Rotation Angles'
//  '<S28>'  : 'F550_FaultInjection/CLAW/Radio Control Transmitter'
//  '<S29>'  : 'F550_FaultInjection/CLAW/mc_att_controller'
//  '<S30>'  : 'F550_FaultInjection/CLAW/mc_pos_controller'
//  '<S31>'  : 'F550_FaultInjection/CLAW/mc_rate_controller'
//  '<S32>'  : 'F550_FaultInjection/CLAW/Publish vehicle_attitude_setpoint/PX4 uORB Message'
//  '<S33>'  : 'F550_FaultInjection/CLAW/Publish vehicle_attitude_setpoint/PX4 uORB Write'
//  '<S34>'  : 'F550_FaultInjection/CLAW/Publish vehicle_rate_setpoint/PX4 uORB Message'
//  '<S35>'  : 'F550_FaultInjection/CLAW/Publish vehicle_rate_setpoint/PX4 uORB Write'
//  '<S36>'  : 'F550_FaultInjection/CLAW/Quaternion Validity Check/Quaternion Norm'
//  '<S37>'  : 'F550_FaultInjection/CLAW/Quaternions to Rotation Angles/Angle Calculation'
//  '<S38>'  : 'F550_FaultInjection/CLAW/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S39>'  : 'F550_FaultInjection/CLAW/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S40>'  : 'F550_FaultInjection/CLAW/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S41>'  : 'F550_FaultInjection/CLAW/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S42>'  : 'F550_FaultInjection/CLAW/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S43>'  : 'F550_FaultInjection/CLAW/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S44>'  : 'F550_FaultInjection/CLAW/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S45>'  : 'F550_FaultInjection/CLAW/Radio Control Transmitter/PX4 uORB Read'
//  '<S46>'  : 'F550_FaultInjection/CLAW/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S47>'  : 'F550_FaultInjection/CLAW/mc_att_controller/Degrees to Radians'
//  '<S48>'  : 'F550_FaultInjection/CLAW/mc_att_controller/Degrees to Radians1'
//  '<S49>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3'
//  '<S50>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4'
//  '<S51>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Anti-windup'
//  '<S52>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/D Gain'
//  '<S53>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Filter'
//  '<S54>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Filter ICs'
//  '<S55>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/I Gain'
//  '<S56>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Ideal P Gain'
//  '<S57>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Ideal P Gain Fdbk'
//  '<S58>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Integrator'
//  '<S59>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Integrator ICs'
//  '<S60>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/N Copy'
//  '<S61>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/N Gain'
//  '<S62>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/P Copy'
//  '<S63>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Parallel P Gain'
//  '<S64>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Reset Signal'
//  '<S65>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Saturation'
//  '<S66>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Saturation Fdbk'
//  '<S67>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Sum'
//  '<S68>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Sum Fdbk'
//  '<S69>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Tracking Mode'
//  '<S70>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Tracking Mode Sum'
//  '<S71>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Tsamp - Integral'
//  '<S72>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Tsamp - Ngain'
//  '<S73>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/postSat Signal'
//  '<S74>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/preSat Signal'
//  '<S75>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Anti-windup/Disabled'
//  '<S76>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/D Gain/Disabled'
//  '<S77>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Filter/Disabled'
//  '<S78>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Filter ICs/Disabled'
//  '<S79>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/I Gain/Disabled'
//  '<S80>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Ideal P Gain/Passthrough'
//  '<S81>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S82>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Integrator/Disabled'
//  '<S83>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Integrator ICs/Disabled'
//  '<S84>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S85>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/N Gain/Disabled'
//  '<S86>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/P Copy/Disabled'
//  '<S87>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Parallel P Gain/External Parameters'
//  '<S88>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Reset Signal/Disabled'
//  '<S89>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Saturation/External'
//  '<S90>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Saturation/External/Saturation Dynamic'
//  '<S91>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Saturation Fdbk/Disabled'
//  '<S92>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Sum/Passthrough_P'
//  '<S93>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Sum Fdbk/Disabled'
//  '<S94>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Tracking Mode/Disabled'
//  '<S95>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S96>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S97>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S98>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/postSat Signal/Forward_Path'
//  '<S99>'  : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller3/preSat Signal/Forward_Path'
//  '<S100>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Anti-windup'
//  '<S101>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/D Gain'
//  '<S102>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Filter'
//  '<S103>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Filter ICs'
//  '<S104>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/I Gain'
//  '<S105>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Ideal P Gain'
//  '<S106>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S107>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Integrator'
//  '<S108>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Integrator ICs'
//  '<S109>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/N Copy'
//  '<S110>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/N Gain'
//  '<S111>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/P Copy'
//  '<S112>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Parallel P Gain'
//  '<S113>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Reset Signal'
//  '<S114>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Saturation'
//  '<S115>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Saturation Fdbk'
//  '<S116>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Sum'
//  '<S117>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Sum Fdbk'
//  '<S118>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Tracking Mode'
//  '<S119>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Tracking Mode Sum'
//  '<S120>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Tsamp - Integral'
//  '<S121>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Tsamp - Ngain'
//  '<S122>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/postSat Signal'
//  '<S123>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/preSat Signal'
//  '<S124>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Anti-windup/Disabled'
//  '<S125>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/D Gain/Disabled'
//  '<S126>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Filter/Disabled'
//  '<S127>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Filter ICs/Disabled'
//  '<S128>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/I Gain/Disabled'
//  '<S129>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S130>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S131>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Integrator/Disabled'
//  '<S132>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Integrator ICs/Disabled'
//  '<S133>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S134>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/N Gain/Disabled'
//  '<S135>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/P Copy/Disabled'
//  '<S136>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Parallel P Gain/External Parameters'
//  '<S137>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Reset Signal/Disabled'
//  '<S138>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Saturation/External'
//  '<S139>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Saturation/External/Saturation Dynamic'
//  '<S140>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S141>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Sum/Passthrough_P'
//  '<S142>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S143>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Tracking Mode/Disabled'
//  '<S144>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S145>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S146>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S147>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S148>' : 'F550_FaultInjection/CLAW/mc_att_controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S149>' : 'F550_FaultInjection/CLAW/mc_pos_controller/Altitude Signal conditioning'
//  '<S150>' : 'F550_FaultInjection/CLAW/mc_pos_controller/Calculate Transformation Matrix'
//  '<S151>' : 'F550_FaultInjection/CLAW/mc_pos_controller/Calculate minimum Turn'
//  '<S152>' : 'F550_FaultInjection/CLAW/mc_pos_controller/Degrees to Radians'
//  '<S153>' : 'F550_FaultInjection/CLAW/mc_pos_controller/Degrees to Radians2'
//  '<S154>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller'
//  '<S155>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1'
//  '<S156>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5'
//  '<S157>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude'
//  '<S158>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz'
//  '<S159>' : 'F550_FaultInjection/CLAW/mc_pos_controller/Altitude Signal conditioning/Saturation Dynamic'
//  '<S160>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Anti-windup'
//  '<S161>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/D Gain'
//  '<S162>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Filter'
//  '<S163>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Filter ICs'
//  '<S164>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/I Gain'
//  '<S165>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Ideal P Gain'
//  '<S166>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Ideal P Gain Fdbk'
//  '<S167>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Integrator'
//  '<S168>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Integrator ICs'
//  '<S169>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/N Copy'
//  '<S170>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/N Gain'
//  '<S171>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/P Copy'
//  '<S172>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Parallel P Gain'
//  '<S173>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Reset Signal'
//  '<S174>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Saturation'
//  '<S175>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Saturation Fdbk'
//  '<S176>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Sum'
//  '<S177>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Sum Fdbk'
//  '<S178>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Tracking Mode'
//  '<S179>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Tracking Mode Sum'
//  '<S180>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Tsamp - Integral'
//  '<S181>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Tsamp - Ngain'
//  '<S182>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/postSat Signal'
//  '<S183>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/preSat Signal'
//  '<S184>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Anti-windup/Disabled'
//  '<S185>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/D Gain/Disabled'
//  '<S186>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Filter/Disabled'
//  '<S187>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Filter ICs/Disabled'
//  '<S188>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/I Gain/Disabled'
//  '<S189>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S190>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S191>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Integrator/Disabled'
//  '<S192>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Integrator ICs/Disabled'
//  '<S193>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S194>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/N Gain/Disabled'
//  '<S195>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/P Copy/Disabled'
//  '<S196>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Parallel P Gain/External Parameters'
//  '<S197>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Reset Signal/Disabled'
//  '<S198>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Saturation/External'
//  '<S199>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Saturation/External/Saturation Dynamic'
//  '<S200>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S201>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Sum/Passthrough_P'
//  '<S202>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Sum Fdbk/Disabled'
//  '<S203>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Tracking Mode/Disabled'
//  '<S204>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S205>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S206>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S207>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/postSat Signal/Forward_Path'
//  '<S208>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller/preSat Signal/Forward_Path'
//  '<S209>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Anti-windup'
//  '<S210>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/D Gain'
//  '<S211>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Filter'
//  '<S212>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Filter ICs'
//  '<S213>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/I Gain'
//  '<S214>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Ideal P Gain'
//  '<S215>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S216>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Integrator'
//  '<S217>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Integrator ICs'
//  '<S218>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/N Copy'
//  '<S219>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/N Gain'
//  '<S220>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/P Copy'
//  '<S221>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Parallel P Gain'
//  '<S222>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Reset Signal'
//  '<S223>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Saturation'
//  '<S224>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Saturation Fdbk'
//  '<S225>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Sum'
//  '<S226>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Sum Fdbk'
//  '<S227>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Tracking Mode'
//  '<S228>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Tracking Mode Sum'
//  '<S229>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Tsamp - Integral'
//  '<S230>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Tsamp - Ngain'
//  '<S231>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/postSat Signal'
//  '<S232>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/preSat Signal'
//  '<S233>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Anti-windup/Disabled'
//  '<S234>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/D Gain/Disabled'
//  '<S235>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Filter/Disabled'
//  '<S236>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Filter ICs/Disabled'
//  '<S237>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/I Gain/Disabled'
//  '<S238>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S239>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S240>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Integrator/Disabled'
//  '<S241>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Integrator ICs/Disabled'
//  '<S242>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S243>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/N Gain/Disabled'
//  '<S244>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/P Copy/Disabled'
//  '<S245>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Parallel P Gain/External Parameters'
//  '<S246>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Reset Signal/Disabled'
//  '<S247>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Saturation/External'
//  '<S248>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Saturation/External/Saturation Dynamic'
//  '<S249>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S250>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Sum/Passthrough_P'
//  '<S251>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S252>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Tracking Mode/Disabled'
//  '<S253>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S254>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S255>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S256>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S257>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S258>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Anti-windup'
//  '<S259>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/D Gain'
//  '<S260>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Filter'
//  '<S261>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Filter ICs'
//  '<S262>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/I Gain'
//  '<S263>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Ideal P Gain'
//  '<S264>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Ideal P Gain Fdbk'
//  '<S265>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Integrator'
//  '<S266>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Integrator ICs'
//  '<S267>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/N Copy'
//  '<S268>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/N Gain'
//  '<S269>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/P Copy'
//  '<S270>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Parallel P Gain'
//  '<S271>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Reset Signal'
//  '<S272>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Saturation'
//  '<S273>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Saturation Fdbk'
//  '<S274>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Sum'
//  '<S275>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Sum Fdbk'
//  '<S276>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Tracking Mode'
//  '<S277>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Tracking Mode Sum'
//  '<S278>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Tsamp - Integral'
//  '<S279>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Tsamp - Ngain'
//  '<S280>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/postSat Signal'
//  '<S281>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/preSat Signal'
//  '<S282>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Anti-windup/Disabled'
//  '<S283>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/D Gain/Disabled'
//  '<S284>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Filter/Disabled'
//  '<S285>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Filter ICs/Disabled'
//  '<S286>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/I Gain/Disabled'
//  '<S287>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Ideal P Gain/Passthrough'
//  '<S288>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Ideal P Gain Fdbk/Disabled'
//  '<S289>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Integrator/Disabled'
//  '<S290>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Integrator ICs/Disabled'
//  '<S291>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/N Copy/Disabled wSignal Specification'
//  '<S292>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/N Gain/Disabled'
//  '<S293>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/P Copy/Disabled'
//  '<S294>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Parallel P Gain/External Parameters'
//  '<S295>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Reset Signal/Disabled'
//  '<S296>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Saturation/External'
//  '<S297>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Saturation/External/Saturation Dynamic'
//  '<S298>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Saturation Fdbk/Disabled'
//  '<S299>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Sum/Passthrough_P'
//  '<S300>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Sum Fdbk/Disabled'
//  '<S301>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Tracking Mode/Disabled'
//  '<S302>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Tracking Mode Sum/Passthrough'
//  '<S303>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Tsamp - Integral/TsSignalSpecification'
//  '<S304>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/Tsamp - Ngain/Passthrough'
//  '<S305>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/postSat Signal/Forward_Path'
//  '<S306>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID Controller5/preSat Signal/Forward_Path'
//  '<S307>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Anti-windup'
//  '<S308>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/D Gain'
//  '<S309>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Filter'
//  '<S310>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Filter ICs'
//  '<S311>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/I Gain'
//  '<S312>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Ideal P Gain'
//  '<S313>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S314>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Integrator'
//  '<S315>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Integrator ICs'
//  '<S316>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/N Copy'
//  '<S317>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/N Gain'
//  '<S318>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/P Copy'
//  '<S319>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Parallel P Gain'
//  '<S320>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Reset Signal'
//  '<S321>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Saturation'
//  '<S322>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Saturation Fdbk'
//  '<S323>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Sum'
//  '<S324>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Sum Fdbk'
//  '<S325>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Tracking Mode'
//  '<S326>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Tracking Mode Sum'
//  '<S327>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Tsamp - Integral'
//  '<S328>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Tsamp - Ngain'
//  '<S329>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/postSat Signal'
//  '<S330>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/preSat Signal'
//  '<S331>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Anti-windup/Disabled'
//  '<S332>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/D Gain/Disabled'
//  '<S333>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Filter/Disabled'
//  '<S334>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Filter ICs/Disabled'
//  '<S335>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/I Gain/Disabled'
//  '<S336>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S337>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Ideal P Gain Fdbk/Disabled'
//  '<S338>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Integrator/Disabled'
//  '<S339>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Integrator ICs/Disabled'
//  '<S340>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/N Copy/Disabled wSignal Specification'
//  '<S341>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/N Gain/Disabled'
//  '<S342>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/P Copy/Disabled'
//  '<S343>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Parallel P Gain/External Parameters'
//  '<S344>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Reset Signal/Disabled'
//  '<S345>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Saturation/External'
//  '<S346>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Saturation/External/Saturation Dynamic'
//  '<S347>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Saturation Fdbk/Disabled'
//  '<S348>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Sum/Passthrough_P'
//  '<S349>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Sum Fdbk/Disabled'
//  '<S350>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S351>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S352>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S353>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S354>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/postSat Signal/Forward_Path'
//  '<S355>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_Altitude/preSat Signal/Forward_Path'
//  '<S356>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Anti-windup'
//  '<S357>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/D Gain'
//  '<S358>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Filter'
//  '<S359>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Filter ICs'
//  '<S360>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/I Gain'
//  '<S361>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Ideal P Gain'
//  '<S362>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Ideal P Gain Fdbk'
//  '<S363>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Integrator'
//  '<S364>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Integrator ICs'
//  '<S365>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/N Copy'
//  '<S366>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/N Gain'
//  '<S367>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/P Copy'
//  '<S368>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Parallel P Gain'
//  '<S369>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Reset Signal'
//  '<S370>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Saturation'
//  '<S371>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Saturation Fdbk'
//  '<S372>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Sum'
//  '<S373>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Sum Fdbk'
//  '<S374>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Tracking Mode'
//  '<S375>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Tracking Mode Sum'
//  '<S376>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Tsamp - Integral'
//  '<S377>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Tsamp - Ngain'
//  '<S378>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/postSat Signal'
//  '<S379>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/preSat Signal'
//  '<S380>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Anti-windup/Disc. Clamping Parallel'
//  '<S381>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S382>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S383>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/D Gain/External Parameters'
//  '<S384>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Filter/Disc. Forward Euler Filter'
//  '<S385>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Filter ICs/Internal IC - Filter'
//  '<S386>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/I Gain/External Parameters'
//  '<S387>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Ideal P Gain/Passthrough'
//  '<S388>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Ideal P Gain Fdbk/Passthrough'
//  '<S389>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Integrator/Discrete'
//  '<S390>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Integrator ICs/Internal IC'
//  '<S391>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/N Copy/Disabled'
//  '<S392>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/N Gain/External Parameters'
//  '<S393>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/P Copy/Disabled'
//  '<S394>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Parallel P Gain/External Parameters'
//  '<S395>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Reset Signal/Disabled'
//  '<S396>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Saturation/Enabled'
//  '<S397>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Saturation Fdbk/Passthrough'
//  '<S398>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Sum/Sum_PID'
//  '<S399>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Sum Fdbk/Enabled'
//  '<S400>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Tracking Mode/Disabled'
//  '<S401>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Tracking Mode Sum/Passthrough'
//  '<S402>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Tsamp - Integral/TsSignalSpecification'
//  '<S403>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/Tsamp - Ngain/Passthrough'
//  '<S404>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/postSat Signal/Feedback_Path'
//  '<S405>' : 'F550_FaultInjection/CLAW/mc_pos_controller/PID_vz/preSat Signal/Feedback_Path'
//  '<S406>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller'
//  '<S407>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1'
//  '<S408>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2'
//  '<S409>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Anti-windup'
//  '<S410>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/D Gain'
//  '<S411>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Filter'
//  '<S412>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Filter ICs'
//  '<S413>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/I Gain'
//  '<S414>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Ideal P Gain'
//  '<S415>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Ideal P Gain Fdbk'
//  '<S416>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Integrator'
//  '<S417>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Integrator ICs'
//  '<S418>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/N Copy'
//  '<S419>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/N Gain'
//  '<S420>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/P Copy'
//  '<S421>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Parallel P Gain'
//  '<S422>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Reset Signal'
//  '<S423>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Saturation'
//  '<S424>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Saturation Fdbk'
//  '<S425>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Sum'
//  '<S426>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Sum Fdbk'
//  '<S427>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Tracking Mode'
//  '<S428>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Tracking Mode Sum'
//  '<S429>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Tsamp - Integral'
//  '<S430>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Tsamp - Ngain'
//  '<S431>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/postSat Signal'
//  '<S432>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/preSat Signal'
//  '<S433>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S434>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S435>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S436>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/D Gain/External Parameters'
//  '<S437>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S438>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S439>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/I Gain/External Parameters'
//  '<S440>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S441>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S442>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Integrator/Discrete'
//  '<S443>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Integrator ICs/Internal IC'
//  '<S444>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/N Copy/Disabled'
//  '<S445>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/N Gain/External Parameters'
//  '<S446>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/P Copy/Disabled'
//  '<S447>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Parallel P Gain/External Parameters'
//  '<S448>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Reset Signal/Disabled'
//  '<S449>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Saturation/Enabled'
//  '<S450>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S451>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Sum/Sum_PID'
//  '<S452>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Sum Fdbk/Disabled'
//  '<S453>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Tracking Mode/Disabled'
//  '<S454>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S455>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S456>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S457>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/postSat Signal/Forward_Path'
//  '<S458>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller/preSat Signal/Forward_Path'
//  '<S459>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Anti-windup'
//  '<S460>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/D Gain'
//  '<S461>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Filter'
//  '<S462>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Filter ICs'
//  '<S463>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/I Gain'
//  '<S464>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Ideal P Gain'
//  '<S465>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S466>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Integrator'
//  '<S467>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Integrator ICs'
//  '<S468>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/N Copy'
//  '<S469>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/N Gain'
//  '<S470>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/P Copy'
//  '<S471>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Parallel P Gain'
//  '<S472>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Reset Signal'
//  '<S473>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Saturation'
//  '<S474>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Saturation Fdbk'
//  '<S475>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Sum'
//  '<S476>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Sum Fdbk'
//  '<S477>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Tracking Mode'
//  '<S478>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Tracking Mode Sum'
//  '<S479>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Tsamp - Integral'
//  '<S480>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Tsamp - Ngain'
//  '<S481>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/postSat Signal'
//  '<S482>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/preSat Signal'
//  '<S483>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S484>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S485>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S486>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/D Gain/External Parameters'
//  '<S487>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S488>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S489>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/I Gain/External Parameters'
//  '<S490>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S491>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S492>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Integrator/Discrete'
//  '<S493>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Integrator ICs/Internal IC'
//  '<S494>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/N Copy/Disabled'
//  '<S495>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/N Gain/External Parameters'
//  '<S496>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/P Copy/Disabled'
//  '<S497>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Parallel P Gain/External Parameters'
//  '<S498>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Reset Signal/Disabled'
//  '<S499>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Saturation/Enabled'
//  '<S500>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S501>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Sum/Sum_PID'
//  '<S502>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S503>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Tracking Mode/Disabled'
//  '<S504>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S505>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S506>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S507>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S508>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S509>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Anti-windup'
//  '<S510>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/D Gain'
//  '<S511>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Filter'
//  '<S512>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Filter ICs'
//  '<S513>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/I Gain'
//  '<S514>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Ideal P Gain'
//  '<S515>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Ideal P Gain Fdbk'
//  '<S516>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Integrator'
//  '<S517>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Integrator ICs'
//  '<S518>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/N Copy'
//  '<S519>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/N Gain'
//  '<S520>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/P Copy'
//  '<S521>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Parallel P Gain'
//  '<S522>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Reset Signal'
//  '<S523>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Saturation'
//  '<S524>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Saturation Fdbk'
//  '<S525>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Sum'
//  '<S526>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Sum Fdbk'
//  '<S527>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Tracking Mode'
//  '<S528>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Tracking Mode Sum'
//  '<S529>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Tsamp - Integral'
//  '<S530>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Tsamp - Ngain'
//  '<S531>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/postSat Signal'
//  '<S532>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/preSat Signal'
//  '<S533>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S534>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S535>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S536>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/D Gain/External Parameters'
//  '<S537>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S538>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S539>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/I Gain/External Parameters'
//  '<S540>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Ideal P Gain/Passthrough'
//  '<S541>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S542>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Integrator/Discrete'
//  '<S543>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Integrator ICs/Internal IC'
//  '<S544>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/N Copy/Disabled'
//  '<S545>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/N Gain/External Parameters'
//  '<S546>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/P Copy/Disabled'
//  '<S547>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Parallel P Gain/External Parameters'
//  '<S548>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Reset Signal/Disabled'
//  '<S549>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Saturation/Enabled'
//  '<S550>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Saturation Fdbk/Disabled'
//  '<S551>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Sum/Sum_PID'
//  '<S552>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Sum Fdbk/Disabled'
//  '<S553>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Tracking Mode/Disabled'
//  '<S554>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S555>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S556>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S557>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/postSat Signal/Forward_Path'
//  '<S558>' : 'F550_FaultInjection/CLAW/mc_rate_controller/PID Controller2/preSat Signal/Forward_Path'
//  '<S559>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm'
//  '<S560>' : 'F550_FaultInjection/Navigation/uORB Publish'
//  '<S561>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission'
//  '<S562>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem'
//  '<S563>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC'
//  '<S564>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE'
//  '<S565>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land'
//  '<S566>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off'
//  '<S567>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint'
//  '<S568>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE'
//  '<S569>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE/Enabled Subsystem2'
//  '<S570>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land'
//  '<S571>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land'
//  '<S572>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land/Enabled Subsystem'
//  '<S573>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land/Enabled Subsystem2'
//  '<S574>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Ensure smooth ascend during Takeoff'
//  '<S575>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff'
//  '<S576>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff/Enabled Subsystem2'
//  '<S577>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning'
//  '<S578>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning/Compare To Constant'
//  '<S579>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC'
//  '<S580>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC'
//  '<S581>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead'
//  '<S582>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead'
//  '<S583>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/Compare To Constant'
//  '<S584>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read'
//  '<S585>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read/Enabled Subsystem'
//  '<S586>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint'
//  '<S587>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_WayPoint'
//  '<S588>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Empty_WayPoint'
//  '<S589>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Next_WayPoint'
//  '<S590>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Message'
//  '<S591>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Write'
//  '<S592>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP'
//  '<S593>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem'
//  '<S594>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem1'
//  '<S595>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem2'
//  '<S596>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead/Enabled Subsystem'
//  '<S597>' : 'F550_FaultInjection/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead/Enabled Subsystem'
//  '<S598>' : 'F550_FaultInjection/Navigation/uORB Publish/PX4 uORB Message'
//  '<S599>' : 'F550_FaultInjection/Navigation/uORB Publish/PX4 uORB Write'
//  '<S600>' : 'F550_FaultInjection/uORBInput/PX4 uORB Read1'
//  '<S601>' : 'F550_FaultInjection/uORBInput/PX4 uORB Read2'
//  '<S602>' : 'F550_FaultInjection/uORBInput/vehicle_attitude'
//  '<S603>' : 'F550_FaultInjection/uORBInput/vehicle_local_pos'
//  '<S604>' : 'F550_FaultInjection/uORBInput/PX4 uORB Read1/Enabled Subsystem'
//  '<S605>' : 'F550_FaultInjection/uORBInput/PX4 uORB Read2/Enabled Subsystem'
//  '<S606>' : 'F550_FaultInjection/uORBInput/vehicle_attitude/Enabled Subsystem'
//  '<S607>' : 'F550_FaultInjection/uORBInput/vehicle_local_pos/Enabled Subsystem'

#endif                                 // RTW_HEADER_F550_FaultInjection_h_

//
// File trailer for generated code.
//
// [EOF]
//
