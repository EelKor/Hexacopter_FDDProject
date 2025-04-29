//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_hexacopter.h
//
// Code generated for Simulink model 'FLIGHT_hexacopter'.
//
// Model version                  : 1.160
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Tue Apr 29 13:35:41 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef FLIGHT_hexacopter_h_
#define FLIGHT_hexacopter_h_
#include <drivers/drv_hrt.h>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "FLIGHT_hexacopter_types.h"
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/actuator_motors.h>
#include <uORB/topics/vehicle_local_position_setpoint.h>
#include <uORB/topics/vehicle_attitude_setpoint.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/vehicle_rates_setpoint.h>
#include <uORB/topics/actuator_controls_status.h>

extern "C"
{

#include "rtGetNaN.h"

}

extern "C"
{

#include "rt_nonfinite.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

// Block signals for system '<S3>/PX4 Timestamp'
struct B_PX4Timestamp_FLIGHT_hexacop_T {
  uint64_T PX4Timestamp;               // '<S3>/PX4 Timestamp'
};

// Block states (default storage) for system '<S3>/PX4 Timestamp'
struct DW_PX4Timestamp_FLIGHT_hexaco_T {
  px4_internal_block_getPX4Abso_T obj; // '<S3>/PX4 Timestamp'
  boolean_T objisempty;                // '<S3>/PX4 Timestamp'
};

// Block signals for system '<S19>/Read Parameter'
struct B_ReadParameter_FLIGHT_hexaco_T {
  real32_T ReadParameter_o1;           // '<S19>/Read Parameter'
};

// Block states (default storage) for system '<S19>/Read Parameter'
struct DW_ReadParameter_FLIGHT_hexac_T {
  px4_internal_block_ParameterU_T obj; // '<S19>/Read Parameter'
  boolean_T objisempty;                // '<S19>/Read Parameter'
};

// Block signals for system '<S19>/Read Parameter1'
struct B_ReadParameter1_FLIGHT_hexac_T {
  real32_T ReadParameter1_o1;          // '<S19>/Read Parameter1'
};

// Block states (default storage) for system '<S19>/Read Parameter1'
struct DW_ReadParameter1_FLIGHT_hexa_T {
  px4_internal_block_ParameterU_T obj; // '<S19>/Read Parameter1'
  boolean_T objisempty;                // '<S19>/Read Parameter1'
};

// Block signals for system '<S19>/Read Parameter2'
struct B_ReadParameter2_FLIGHT_hexac_T {
  real32_T ReadParameter2_o1;          // '<S19>/Read Parameter2'
};

// Block states (default storage) for system '<S19>/Read Parameter2'
struct DW_ReadParameter2_FLIGHT_hexa_T {
  px4_internal_block_ParameterU_T obj; // '<S19>/Read Parameter2'
  boolean_T objisempty;                // '<S19>/Read Parameter2'
};

// Block signals for system '<S19>/Read Parameter3'
struct B_ReadParameter3_FLIGHT_hexac_T {
  real32_T ReadParameter3_o1;          // '<S19>/Read Parameter3'
};

// Block states (default storage) for system '<S19>/Read Parameter3'
struct DW_ReadParameter3_FLIGHT_hexa_T {
  px4_internal_block_ParameterU_T obj; // '<S19>/Read Parameter3'
  boolean_T objisempty;                // '<S19>/Read Parameter3'
};

// Block signals for system '<S578>/PX4 Timestamp'
struct B_PX4Timestamp_FLIGHT_hexac_l_T {
  uint64_T PX4Timestamp;               // '<S578>/PX4 Timestamp'
};

// Block states (default storage) for system '<S578>/PX4 Timestamp'
struct DW_PX4Timestamp_FLIGHT_hexa_b_T {
  px4_internal_block_getPX4Abso_T obj; // '<S578>/PX4 Timestamp'
  boolean_T objisempty;                // '<S578>/PX4 Timestamp'
};

// Block signals for system '<S15>/PX4 Timestamp'
struct B_PX4Timestamp_FLIGHT_hexac_c_T {
  uint64_T PX4Timestamp;               // '<S15>/PX4 Timestamp'
};

// Block states (default storage) for system '<S15>/PX4 Timestamp'
struct DW_PX4Timestamp_FLIGHT_hexa_f_T {
  px4_internal_block_getPX4Abso_T obj; // '<S15>/PX4 Timestamp'
  boolean_T objisempty;                // '<S15>/PX4 Timestamp'
};

// Block signals (default storage)
struct B_FLIGHT_hexacopter_T {
  px4_Bus_vehicle_local_position In1;  // '<S403>/In1'
  px4_Bus_vehicle_local_position r;
  px4_Bus_vehicle_odometry In1_k;      // '<S405>/In1'
  px4_Bus_vehicle_odometry r1;
  px4_Bus_input_rc In1_n;              // '<S411>/In1'
  px4_Bus_input_rc r2;
  px4_Bus_actuator_motors BusAssignment;// '<S582>/Bus Assignment'
  px4_Bus_vehicle_local_position_setpoint BusAssignment_g;// '<S16>/Bus Assignment' 
  px4_Bus_vehicle_attitude_setpoint BusAssignment_d;// '<S15>/Bus Assignment'
  px4_Bus_vehicle_angular_velocity r3;
  px4_Bus_vehicle_rates_setpoint BusAssignment_e;// '<S17>/Bus Assignment'
  px4_Bus_vehicle_angular_velocity In1_h;// '<S586>/In1'
  uint16_T values[18];
  px4_Bus_actuator_controls_status BusAssignment_gi;// '<S578>/Bus Assignment'
  uint16_T pwmValue[8];
  uint16_T DataTypeConversion6[6];     // '<S4>/Data Type Conversion6'
  real_T reletive_time_sec;
  real_T peak_angle_rad;
  real_T out_roll;                     // '<S3>/MATLAB Function'
  real_T out_pitch;                    // '<S3>/MATLAB Function'
  real_T u0;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real32_T RateTransition;             // '<Root>/Rate Transition'
  real32_T RateTransition1;            // '<Root>/Rate Transition1'
  real32_T RateTransition2;            // '<Root>/Rate Transition2'
  real32_T RateTransition3;            // '<Root>/Rate Transition3'
  real32_T Merge1[4];                  // '<Root>/Merge1'
  real32_T Merge;                      // '<Root>/Merge'
  real32_T Sum2;                       // '<S9>/Sum2'
  real32_T Sum3;                       // '<S9>/Sum3'
  real32_T Sum5;                       // '<S9>/Sum5'
  real32_T OutportBufferFordes_xy[2];  // '<S5>/Constant'
  real32_T Add;                        // '<S5>/Add'
  real32_T Saturation[2];              // '<S191>/Saturation'
  real32_T Gain1;                      // '<S191>/Gain1'
  real32_T PProdOut[2];                // '<S335>/PProd Out'
  real32_T des_vz;                     // '<S189>/des_vz'
  real32_T Saturation1;                // '<S189>/Saturation1'
  real32_T Saturation1_i;              // '<S19>/Saturation1'
  real32_T Switch2;                    // '<S169>/Switch2'
  real32_T Switch2_i;                  // '<S118>/Switch2'
  uint16_T Output_Limits1[6];          // '<S6>/Output_Limits1'
  int32_T ParamStep;
  int32_T ParamStep_m;
  int32_T ParamStep_c;
  int32_T ParamStep_k;
  uint16_T RateTransition4;            // '<Root>/Rate Transition4'
  boolean_T RateTransition5;           // '<Root>/Rate Transition5'
  boolean_T RateTransition6;           // '<Root>/Rate Transition6'
  B_PX4Timestamp_FLIGHT_hexac_c_T PX4Timestamp_pnae;// '<S15>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexacop_T PX4Timestamp_pna;// '<S3>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexac_c_T PX4Timestamp_pn;// '<S15>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexac_l_T PX4Timestamp_n;// '<S578>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexac_l_T PX4Timestamp_p;// '<S578>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexac_l_T PX4Timestamp_o;// '<S578>/PX4 Timestamp'
  B_ReadParameter3_FLIGHT_hexac_T ReadParameter3_pn;// '<S19>/Read Parameter3'
  B_ReadParameter2_FLIGHT_hexac_T ReadParameter2_pna;// '<S19>/Read Parameter2'
  B_ReadParameter1_FLIGHT_hexac_T ReadParameter1_pnaev;// '<S19>/Read Parameter1' 
  B_ReadParameter_FLIGHT_hexaco_T ReadParameter_pna;// '<S19>/Read Parameter'
  B_ReadParameter3_FLIGHT_hexac_T ReadParameter3_p;// '<S19>/Read Parameter3'
  B_ReadParameter2_FLIGHT_hexac_T ReadParameter2_pn;// '<S19>/Read Parameter2'
  B_ReadParameter1_FLIGHT_hexac_T ReadParameter1_pna;// '<S19>/Read Parameter1'
  B_ReadParameter_FLIGHT_hexaco_T ReadParameter_pn;// '<S19>/Read Parameter'
  B_PX4Timestamp_FLIGHT_hexacop_T PX4Timestamp;// '<S3>/PX4 Timestamp'
};

// Block states (default storage) for system '<Root>'
struct DW_FLIGHT_hexacopter_T {
  px4_internal_block_ParameterU_T obj; // '<S9>/read_mc_rollrate_p'
  px4_internal_block_ParameterU_T obj_e;// '<S9>/Read Parameter9'
  px4_internal_block_ParameterU_T obj_i;// '<S9>/Read Parameter8'
  px4_internal_block_ParameterU_T obj_j;// '<S9>/Read Parameter7'
  px4_internal_block_ParameterU_T obj_a;// '<S9>/Read Parameter6'
  px4_internal_block_ParameterU_T obj_h;// '<S9>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_p;// '<S9>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_b;// '<S9>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_d;// '<S9>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_c;// '<S9>/Read Parameter10'
  px4_internal_block_ParameterU_T obj_ea;// '<S9>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_pi;// '<S191>/Read Parameter'
  px4_internal_block_ParameterU_T obj_eq;// '<S190>/Read Parameter'
  px4_internal_block_ParameterU_T obj_m;// '<S187>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_aq;// '<S4>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_cx;// '<S4>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_n;// '<S4>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_ao;// '<S4>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_g;// '<S4>/Read Parameter13'
  px4_internal_block_ParameterU_T obj_j5;// '<S4>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_l;// '<S3>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_ct;// '<S3>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_cf;// '<S3>/Read Parameter'
  px4_internal_block_ParameterU_T obj_k;// '<S2>/Read Parameter9'
  px4_internal_block_ParameterU_T obj_ds;// '<S2>/Read Parameter10'
  px4_internal_block_ParameterU_T obj_o;// '<S2>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_jz;// '<S2>/Read Parameter'
  px4_internal_block_Subscriber_T obj_pe;// '<S585>/SourceBlock'
  px4_internal_block_Subscriber_T obj_p2;// '<S410>/SourceBlock'
  px4_internal_block_Subscriber_T obj_ab;// '<S404>/SourceBlock'
  px4_internal_block_Subscriber_T obj_kk;// '<S401>/SourceBlock'
  px4_internal_block_PWM_FLIGHT_T obj_dl;// '<Root>/PX4 PWM Output'
  px4_internal_block_Publisher__T obj_a4;// '<S593>/SinkBlock'
  px4_internal_block_Publisher__T obj_pa;// '<S591>/SinkBlock'
  px4_internal_block_Publisher__T obj_pt;// '<S588>/SinkBlock'
  px4_internal_block_Publisher__T obj_hf;// '<S584>/SinkBlock'
  px4_internal_block_Publisher__T obj_jk;// '<S580>/SinkBlock'
  real_T start_time_usec;              // '<S3>/MATLAB Function'
  real32_T UnitDelay1_DSTATE;          // '<S422>/Unit Delay1'
  real32_T UD_DSTATE;                  // '<S412>/UD'
  real32_T Integrator_DSTATE;          // '<S561>/Integrator'
  real32_T UnitDelay2_DSTATE;          // '<S422>/Unit Delay2'
  real32_T UnitDelay1_DSTATE_d;        // '<S424>/Unit Delay1'
  real32_T UnitDelay2_DSTATE_n;        // '<S424>/Unit Delay2'
  real32_T UD_DSTATE_i;                // '<S413>/UD'
  real32_T Integrator_DSTATE_c;        // '<S461>/Integrator'
  real32_T UnitDelay1_DSTATE_o;        // '<S426>/Unit Delay1'
  real32_T UnitDelay2_DSTATE_k;        // '<S426>/Unit Delay2'
  real32_T UD_DSTATE_p;                // '<S414>/UD'
  real32_T Integrator_DSTATE_f;        // '<S511>/Integrator'
  real32_T Filter_DSTATE;              // '<S274>/Filter'
  real32_T Integrator_DSTATE_k;        // '<S279>/Integrator'
  real32_T Filter_DSTATE_i;            // '<S51>/Filter'
  real32_T Integrator_DSTATE_e;        // '<S56>/Integrator'
  real32_T RateTransition_Buffer0;     // '<Root>/Rate Transition'
  real32_T RateTransition1_Buffer0;    // '<Root>/Rate Transition1'
  real32_T RateTransition2_Buffer0;    // '<Root>/Rate Transition2'
  real32_T RateTransition3_Buffer0;    // '<Root>/Rate Transition3'
  uint16_T RateTransition4_Buffer0;    // '<Root>/Rate Transition4'
  int8_T Filter_PrevResetState;        // '<S274>/Filter'
  int8_T Integrator_PrevResetState;    // '<S279>/Integrator'
  boolean_T RateTransition5_Buffer0;   // '<Root>/Rate Transition5'
  boolean_T RateTransition6_Buffer0;   // '<Root>/Rate Transition6'
  DW_PX4Timestamp_FLIGHT_hexa_f_T PX4Timestamp_pnae;// '<S15>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexaco_T PX4Timestamp_pna;// '<S3>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexa_f_T PX4Timestamp_pn;// '<S15>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexa_b_T PX4Timestamp_n;// '<S578>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexa_b_T PX4Timestamp_p;// '<S578>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexa_b_T PX4Timestamp_o;// '<S578>/PX4 Timestamp'
  DW_ReadParameter3_FLIGHT_hexa_T ReadParameter3_pn;// '<S19>/Read Parameter3'
  DW_ReadParameter2_FLIGHT_hexa_T ReadParameter2_pna;// '<S19>/Read Parameter2'
  DW_ReadParameter1_FLIGHT_hexa_T ReadParameter1_pnaev;// '<S19>/Read Parameter1' 
  DW_ReadParameter_FLIGHT_hexac_T ReadParameter_pna;// '<S19>/Read Parameter'
  DW_ReadParameter3_FLIGHT_hexa_T ReadParameter3_p;// '<S19>/Read Parameter3'
  DW_ReadParameter2_FLIGHT_hexa_T ReadParameter2_pn;// '<S19>/Read Parameter2'
  DW_ReadParameter1_FLIGHT_hexa_T ReadParameter1_pna;// '<S19>/Read Parameter1'
  DW_ReadParameter_FLIGHT_hexac_T ReadParameter_pn;// '<S19>/Read Parameter'
  DW_PX4Timestamp_FLIGHT_hexaco_T PX4Timestamp;// '<S3>/PX4 Timestamp'
};

// Parameters (default storage)
struct P_FLIGHT_hexacopter_T_ {
  real_T SampleTime;                   // Variable: SampleTime
                                          //  Referenced by:
                                          //    '<S2>/Read Parameter'
                                          //    '<S2>/Read Parameter1'
                                          //    '<S2>/Read Parameter10'
                                          //    '<S2>/Read Parameter9'
                                          //    '<S3>/Read Parameter'
                                          //    '<S3>/Read Parameter1'
                                          //    '<S3>/Read Parameter2'
                                          //    '<S19>/Read Parameter'
                                          //    '<S19>/Read Parameter1'
                                          //    '<S19>/Read Parameter2'
                                          //    '<S19>/Read Parameter3'
                                          //    '<S187>/Read Parameter1'
                                          //    '<S189>/Read Parameter'
                                          //    '<S189>/Read Parameter1'
                                          //    '<S189>/Read Parameter2'
                                          //    '<S189>/Read Parameter3'
                                          //    '<S190>/Read Parameter'
                                          //    '<S191>/Read Parameter'

  real_T SampleTime_SAS;               // Variable: SampleTime_SAS
                                          //  Referenced by:
                                          //    '<S4>/Read Parameter1'
                                          //    '<S4>/Read Parameter13'
                                          //    '<S4>/Read Parameter2'
                                          //    '<S4>/Read Parameter3'
                                          //    '<S4>/Read Parameter4'
                                          //    '<S4>/Read Parameter5'
                                          //    '<S9>/Read Parameter1'
                                          //    '<S9>/Read Parameter10'
                                          //    '<S9>/Read Parameter2'
                                          //    '<S9>/Read Parameter3'
                                          //    '<S9>/Read Parameter4'
                                          //    '<S9>/Read Parameter5'
                                          //    '<S9>/Read Parameter6'
                                          //    '<S9>/Read Parameter7'
                                          //    '<S9>/Read Parameter8'
                                          //    '<S9>/Read Parameter9'
                                          //    '<S9>/read_mc_rollrate_p'

  real32_T MAX_CONTROL_ANGLE_PITCH;    // Variable: MAX_CONTROL_ANGLE_PITCH
                                          //  Referenced by:
                                          //    '<S10>/Gain5'
                                          //    '<S18>/Gain2'

  real32_T MAX_CONTROL_ANGLE_RATE_Y;   // Variable: MAX_CONTROL_ANGLE_RATE_Y
                                          //  Referenced by:
                                          //    '<S10>/Gain6'
                                          //    '<S18>/Gain3'
                                          //    '<S188>/Gain3'

  real32_T MAX_CONTROL_ANGLE_ROLL;     // Variable: MAX_CONTROL_ANGLE_ROLL
                                          //  Referenced by:
                                          //    '<S10>/Gain4'
                                          //    '<S18>/Gain1'

  real32_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S412>/UD'

  real32_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: '<S413>/UD'

  real32_T DiscreteDerivative2_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative2_ICPrevScale
                                 //  Referenced by: '<S414>/UD'

  real32_T PIDController4_InitialCondition;
                              // Mask Parameter: PIDController4_InitialCondition
                                 //  Referenced by: '<S51>/Filter'

  real32_T PIDController4_InitialConditi_l;
                              // Mask Parameter: PIDController4_InitialConditi_l
                                 //  Referenced by: '<S274>/Filter'

  real32_T PIDController4_InitialConditi_a;
                              // Mask Parameter: PIDController4_InitialConditi_a
                                 //  Referenced by: '<S56>/Integrator'

  real32_T PIDController4_InitialConditi_i;
                              // Mask Parameter: PIDController4_InitialConditi_i
                                 //  Referenced by: '<S279>/Integrator'

  real32_T pid_ctrl_yawrate_InitialConditi;
                              // Mask Parameter: pid_ctrl_yawrate_InitialConditi
                                 //  Referenced by: '<S561>/Integrator'

  real32_T pid_ctrl_pitchrate_InitialCondi;
                              // Mask Parameter: pid_ctrl_pitchrate_InitialCondi
                                 //  Referenced by: '<S461>/Integrator'

  real32_T pid_ctrl_rollrate_InitialCondit;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCondit
                                 //  Referenced by: '<S511>/Integrator'

  real32_T PIDController4_LowerSaturationL;
                              // Mask Parameter: PIDController4_LowerSaturationL
                                 //  Referenced by:
                                 //    '<S63>/Saturation'
                                 //    '<S48>/DeadZone'

  real32_T PIDController4_LowerSaturatio_a;
                              // Mask Parameter: PIDController4_LowerSaturatio_a
                                 //  Referenced by: '<S233>/Saturation'

  real32_T PIDController4_LowerSaturatio_f;
                              // Mask Parameter: PIDController4_LowerSaturatio_f
                                 //  Referenced by:
                                 //    '<S286>/Saturation'
                                 //    '<S271>/DeadZone'

  real32_T PIDController4_UpperSaturationL;
                              // Mask Parameter: PIDController4_UpperSaturationL
                                 //  Referenced by:
                                 //    '<S63>/Saturation'
                                 //    '<S48>/DeadZone'

  real32_T PIDController4_UpperSaturatio_h;
                              // Mask Parameter: PIDController4_UpperSaturatio_h
                                 //  Referenced by: '<S233>/Saturation'

  real32_T PIDController4_UpperSaturati_hy;
                              // Mask Parameter: PIDController4_UpperSaturati_hy
                                 //  Referenced by:
                                 //    '<S286>/Saturation'
                                 //    '<S271>/DeadZone'

  uint16_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S180>/Constant'

  uint16_T CompareToConstant3_const; // Mask Parameter: CompareToConstant3_const
                                        //  Referenced by: '<S409>/Constant'

  uint16_T CompareToConstant_const_n;
                                    // Mask Parameter: CompareToConstant_const_n
                                       //  Referenced by: '<S407>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0;// Computed Parameter: Out1_Y0
                                            //  Referenced by: '<S403>/Out1'

  px4_Bus_vehicle_local_position Constant_Value;// Computed Parameter: Constant_Value
                                                   //  Referenced by: '<S401>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0_d;  // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S405>/Out1'

  px4_Bus_vehicle_odometry Constant_Value_g;// Computed Parameter: Constant_Value_g
                                               //  Referenced by: '<S404>/Constant'

  px4_Bus_actuator_motors Constant_Value_m;// Computed Parameter: Constant_Value_m
                                              //  Referenced by: '<S583>/Constant'

  px4_Bus_input_rc Out1_Y0_p;          // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S411>/Out1'

  px4_Bus_input_rc Constant_Value_b;   // Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<S410>/Constant'

  px4_Bus_vehicle_local_position_setpoint Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                              //  Referenced by: '<S590>/Constant'

  px4_Bus_vehicle_attitude_setpoint Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                        //  Referenced by: '<S587>/Constant'

  px4_Bus_vehicle_angular_velocity Out1_Y0_pn;// Computed Parameter: Out1_Y0_pn
                                                 //  Referenced by: '<S586>/Out1'

  px4_Bus_vehicle_angular_velocity Constant_Value_gk;// Computed Parameter: Constant_Value_gk
                                                        //  Referenced by: '<S585>/Constant'

  px4_Bus_vehicle_rates_setpoint Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                     //  Referenced by: '<S592>/Constant'

  px4_Bus_actuator_controls_status Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                       //  Referenced by: '<S579>/Constant'

  real_T Constant1_Value;              // Expression: 100
                                          //  Referenced by: '<S4>/Constant1'

  real_T Constant2_Value;              // Expression: 100
                                          //  Referenced by: '<S4>/Constant2'

  real_T Constant3_Value;              // Expression: 100
                                          //  Referenced by: '<S4>/Constant3'

  real_T Constant4_Value;              // Expression: 100
                                          //  Referenced by: '<S4>/Constant4'

  real_T Constant5_Value;              // Expression: 100
                                          //  Referenced by: '<S4>/Constant5'

  real_T Constant_Value_mc;            // Expression: 100
                                          //  Referenced by: '<S4>/Constant'

  real_T Constant_Value_c;             // Expression: 1094
                                          //  Referenced by: '<S10>/Constant'

  real_T Gain_Gain;                    // Expression: 1/800
                                          //  Referenced by: '<S10>/Gain'

  real_T Gain_Gain_j;                  // Expression: 0.01
                                          //  Referenced by: '<S181>/Gain'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<S181>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S181>/Saturation'

  real_T Gain_Gain_h;                  // Expression: 0.01
                                          //  Referenced by: '<S182>/Gain'

  real_T Saturation_UpperSat_m;        // Expression: 1
                                          //  Referenced by: '<S182>/Saturation'

  real_T Saturation_LowerSat_o;        // Expression: 0
                                          //  Referenced by: '<S182>/Saturation'

  real_T Gain_Gain_c;                  // Expression: 0.01
                                          //  Referenced by: '<S183>/Gain'

  real_T Saturation_UpperSat_b;        // Expression: 1
                                          //  Referenced by: '<S183>/Saturation'

  real_T Saturation_LowerSat_g;        // Expression: 0
                                          //  Referenced by: '<S183>/Saturation'

  real_T Gain_Gain_n;                  // Expression: 0.01
                                          //  Referenced by: '<S184>/Gain'

  real_T Saturation_UpperSat_be;       // Expression: 1
                                          //  Referenced by: '<S184>/Saturation'

  real_T Saturation_LowerSat_e;        // Expression: 0
                                          //  Referenced by: '<S184>/Saturation'

  real_T Gain_Gain_f;                  // Expression: 0.01
                                          //  Referenced by: '<S185>/Gain'

  real_T Saturation_UpperSat_d;        // Expression: 1
                                          //  Referenced by: '<S185>/Saturation'

  real_T Saturation_LowerSat_l;        // Expression: 0
                                          //  Referenced by: '<S185>/Saturation'

  real_T Gain_Gain_m;                  // Expression: 0.01
                                          //  Referenced by: '<S186>/Gain'

  real_T Saturation_UpperSat_i;        // Expression: 1
                                          //  Referenced by: '<S186>/Saturation'

  real_T Saturation_LowerSat_n;        // Expression: 0
                                          //  Referenced by: '<S186>/Saturation'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S2>/Gain1'

  real32_T Gain_Gain_m3;               // Computed Parameter: Gain_Gain_m3
                                          //  Referenced by: '<S2>/Gain'

  real32_T des_p_Y0;                   // Computed Parameter: des_p_Y0
                                          //  Referenced by: '<S2>/des_p'

  real32_T des_q_Y0;                   // Computed Parameter: des_q_Y0
                                          //  Referenced by: '<S2>/des_q'

  real32_T Gain1_Gain_g;               // Computed Parameter: Gain1_Gain_g
                                          //  Referenced by: '<S73>/Gain1'

  real32_T Gain1_Gain_c;               // Computed Parameter: Gain1_Gain_c
                                          //  Referenced by: '<S74>/Gain1'

  real32_T throttle_Y0;                // Computed Parameter: throttle_Y0
                                          //  Referenced by: '<S19>/throttle'

  real32_T Constant1_Value_n;          // Computed Parameter: Constant1_Value_n
                                          //  Referenced by: '<S46>/Constant1'

  real32_T Constant_Value_bi;          // Computed Parameter: Constant_Value_bi
                                          //  Referenced by: '<S19>/Constant'

  real32_T Gain_Gain_d;                // Computed Parameter: Gain_Gain_d
                                          //  Referenced by: '<S19>/Gain'

  real32_T Filter_gainval;             // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S51>/Filter'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S56>/Integrator'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S19>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S19>/Saturation1'

  real32_T Clamping_zero_Value;       // Computed Parameter: Clamping_zero_Value
                                         //  Referenced by: '<S46>/Clamping_zero'

  real32_T DeadZone3_Start;            // Computed Parameter: DeadZone3_Start
                                          //  Referenced by: '<S18>/Dead Zone3'

  real32_T DeadZone3_End;              // Computed Parameter: DeadZone3_End
                                          //  Referenced by: '<S18>/Dead Zone3'

  real32_T Saturation9_UpperSat;     // Computed Parameter: Saturation9_UpperSat
                                        //  Referenced by: '<S18>/Saturation9'

  real32_T Saturation9_LowerSat;     // Computed Parameter: Saturation9_LowerSat
                                        //  Referenced by: '<S18>/Saturation9'

  real32_T DeadZone2_Start;            // Computed Parameter: DeadZone2_Start
                                          //  Referenced by: '<S18>/Dead Zone2'

  real32_T DeadZone2_End;              // Computed Parameter: DeadZone2_End
                                          //  Referenced by: '<S18>/Dead Zone2'

  real32_T Saturation3_UpperSat;     // Computed Parameter: Saturation3_UpperSat
                                        //  Referenced by: '<S18>/Saturation3'

  real32_T Saturation3_LowerSat;     // Computed Parameter: Saturation3_LowerSat
                                        //  Referenced by: '<S18>/Saturation3'

  real32_T DeadZone4_Start;            // Computed Parameter: DeadZone4_Start
                                          //  Referenced by: '<S18>/Dead Zone4'

  real32_T DeadZone4_End;              // Computed Parameter: DeadZone4_End
                                          //  Referenced by: '<S18>/Dead Zone4'

  real32_T Saturation10_UpperSat;   // Computed Parameter: Saturation10_UpperSat
                                       //  Referenced by: '<S18>/Saturation10'

  real32_T Saturation10_LowerSat;   // Computed Parameter: Saturation10_LowerSat
                                       //  Referenced by: '<S18>/Saturation10'

  real32_T Gain_Gain_e;                // Computed Parameter: Gain_Gain_e
                                          //  Referenced by: '<S18>/Gain'

  real32_T DeadZone1_Start;            // Computed Parameter: DeadZone1_Start
                                          //  Referenced by: '<S18>/Dead Zone1'

  real32_T DeadZone1_End;              // Computed Parameter: DeadZone1_End
                                          //  Referenced by: '<S18>/Dead Zone1'

  real32_T Saturation1_UpperSat_d; // Computed Parameter: Saturation1_UpperSat_d
                                      //  Referenced by: '<S18>/Saturation1'

  real32_T Saturation1_LowerSat_b; // Computed Parameter: Saturation1_LowerSat_b
                                      //  Referenced by: '<S18>/Saturation1'

  real32_T des_vz_Y0;                  // Computed Parameter: des_vz_Y0
                                          //  Referenced by: '<S187>/des_vz'

  real32_T throttle_Y0_o;              // Computed Parameter: throttle_Y0_o
                                          //  Referenced by: '<S189>/throttle'

  real32_T log_alt_Y0;                 // Computed Parameter: log_alt_Y0
                                          //  Referenced by: '<S189>/log_alt'

  real32_T Constant1_Value_m;          // Computed Parameter: Constant1_Value_m
                                          //  Referenced by: '<S269>/Constant1'

  real32_T Constant_Value_e;           // Computed Parameter: Constant_Value_e
                                          //  Referenced by: '<S189>/Constant'

  real32_T Gain_Gain_b;                // Computed Parameter: Gain_Gain_b
                                          //  Referenced by: '<S189>/Gain'

  real32_T Filter_gainval_h;           // Computed Parameter: Filter_gainval_h
                                          //  Referenced by: '<S274>/Filter'

  real32_T Integrator_gainval_l;     // Computed Parameter: Integrator_gainval_l
                                        //  Referenced by: '<S279>/Integrator'

  real32_T Saturation1_UpperSat_e; // Computed Parameter: Saturation1_UpperSat_e
                                      //  Referenced by: '<S189>/Saturation1'

  real32_T Saturation1_LowerSat_bn;
                                  // Computed Parameter: Saturation1_LowerSat_bn
                                     //  Referenced by: '<S189>/Saturation1'

  real32_T Clamping_zero_Value_f;   // Computed Parameter: Clamping_zero_Value_f
                                       //  Referenced by: '<S269>/Clamping_zero'

  real32_T des_vxvy_Y0;                // Computed Parameter: des_vxvy_Y0
                                          //  Referenced by: '<S190>/des_vxvy'

  real32_T des_pitch_Y0;               // Computed Parameter: des_pitch_Y0
                                          //  Referenced by: '<S191>/des_pitch'

  real32_T des_roll_Y0;                // Computed Parameter: des_roll_Y0
                                          //  Referenced by: '<S191>/des_roll'

  real32_T Gain_Gain_a;                // Computed Parameter: Gain_Gain_a
                                          //  Referenced by: '<S349>/Gain'

  real32_T Saturation_UpperSat_e;   // Computed Parameter: Saturation_UpperSat_e
                                       //  Referenced by: '<S191>/Saturation'

  real32_T Saturation_LowerSat_a;   // Computed Parameter: Saturation_LowerSat_a
                                       //  Referenced by: '<S191>/Saturation'

  real32_T Gain1_Gain_i;               // Computed Parameter: Gain1_Gain_i
                                          //  Referenced by: '<S191>/Gain1'

  real32_T des_z_Y0;                   // Computed Parameter: des_z_Y0
                                          //  Referenced by: '<S5>/des_z'

  real32_T Constant_Value_k[2];        // Computed Parameter: Constant_Value_k
                                          //  Referenced by: '<S5>/Constant'

  real32_T DeadZone4_Start_d;          // Computed Parameter: DeadZone4_Start_d
                                          //  Referenced by: '<S188>/Dead Zone4'

  real32_T DeadZone4_End_l;            // Computed Parameter: DeadZone4_End_l
                                          //  Referenced by: '<S188>/Dead Zone4'

  real32_T Saturation10_UpperSat_m;
                                  // Computed Parameter: Saturation10_UpperSat_m
                                     //  Referenced by: '<S188>/Saturation10'

  real32_T Saturation10_LowerSat_n;
                                  // Computed Parameter: Saturation10_LowerSat_n
                                     //  Referenced by: '<S188>/Saturation10'

  real32_T Gain_Gain_o;                // Computed Parameter: Gain_Gain_o
                                          //  Referenced by: '<S188>/Gain'

  real32_T DeadZone2_Start_k;          // Computed Parameter: DeadZone2_Start_k
                                          //  Referenced by: '<S188>/Dead Zone2'

  real32_T DeadZone2_End_k;            // Computed Parameter: DeadZone2_End_k
                                          //  Referenced by: '<S188>/Dead Zone2'

  real32_T Saturation3_UpperSat_b; // Computed Parameter: Saturation3_UpperSat_b
                                      //  Referenced by: '<S188>/Saturation3'

  real32_T Saturation3_LowerSat_a; // Computed Parameter: Saturation3_LowerSat_a
                                      //  Referenced by: '<S188>/Saturation3'

  real32_T DeadZone3_Start_p;          // Computed Parameter: DeadZone3_Start_p
                                          //  Referenced by: '<S10>/Dead Zone3'

  real32_T DeadZone3_End_l;            // Computed Parameter: DeadZone3_End_l
                                          //  Referenced by: '<S10>/Dead Zone3'

  real32_T Saturation_UpperSat_o;   // Computed Parameter: Saturation_UpperSat_o
                                       //  Referenced by: '<S10>/Saturation'

  real32_T Saturation_LowerSat_el; // Computed Parameter: Saturation_LowerSat_el
                                      //  Referenced by: '<S10>/Saturation'

  real32_T Constant1_Value_l;          // Computed Parameter: Constant1_Value_l
                                          //  Referenced by: '<S10>/Constant1'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S10>/Gain2'

  real32_T DeadZone2_Start_o;          // Computed Parameter: DeadZone2_Start_o
                                          //  Referenced by: '<S10>/Dead Zone2'

  real32_T DeadZone2_End_e;            // Computed Parameter: DeadZone2_End_e
                                          //  Referenced by: '<S10>/Dead Zone2'

  real32_T Saturation1_UpperSat_l; // Computed Parameter: Saturation1_UpperSat_l
                                      //  Referenced by: '<S10>/Saturation1'

  real32_T Saturation1_LowerSat_i; // Computed Parameter: Saturation1_LowerSat_i
                                      //  Referenced by: '<S10>/Saturation1'

  real32_T Constant2_Value_i;          // Computed Parameter: Constant2_Value_i
                                          //  Referenced by: '<S10>/Constant2'

  real32_T Gain1_Gain_m;               // Computed Parameter: Gain1_Gain_m
                                          //  Referenced by: '<S10>/Gain1'

  real32_T DeadZone1_Start_c;          // Computed Parameter: DeadZone1_Start_c
                                          //  Referenced by: '<S10>/Dead Zone1'

  real32_T DeadZone1_End_m;            // Computed Parameter: DeadZone1_End_m
                                          //  Referenced by: '<S10>/Dead Zone1'

  real32_T Saturation2_UpperSat;     // Computed Parameter: Saturation2_UpperSat
                                        //  Referenced by: '<S10>/Saturation2'

  real32_T Saturation2_LowerSat;     // Computed Parameter: Saturation2_LowerSat
                                        //  Referenced by: '<S10>/Saturation2'

  real32_T Constant3_Value_e;          // Computed Parameter: Constant3_Value_e
                                          //  Referenced by: '<S10>/Constant3'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<S10>/Gain3'

  real32_T DeadZone_Start;             // Computed Parameter: DeadZone_Start
                                          //  Referenced by: '<S10>/Dead Zone'

  real32_T DeadZone_End;               // Computed Parameter: DeadZone_End
                                          //  Referenced by: '<S10>/Dead Zone'

  real32_T Saturation3_UpperSat_b4;
                                  // Computed Parameter: Saturation3_UpperSat_b4
                                     //  Referenced by: '<S10>/Saturation3'

  real32_T Saturation3_LowerSat_j; // Computed Parameter: Saturation3_LowerSat_j
                                      //  Referenced by: '<S10>/Saturation3'

  real32_T tau_roll_Y0;                // Computed Parameter: tau_roll_Y0
                                          //  Referenced by: '<S9>/tau_roll'

  real32_T tau_pitch_Y0;               // Computed Parameter: tau_pitch_Y0
                                          //  Referenced by: '<S9>/tau_pitch'

  real32_T tau_yaw_Y0;                 // Computed Parameter: tau_yaw_Y0
                                          //  Referenced by: '<S9>/tau_yaw'

  real32_T UnitDelay1_InitialCondition;
                              // Computed Parameter: UnitDelay1_InitialCondition
                                 //  Referenced by: '<S422>/Unit Delay1'

  real32_T tau_Gain;                   // Computed Parameter: tau_Gain
                                          //  Referenced by: '<S422>/tau'

  real32_T Bias_Bias;                  // Computed Parameter: Bias_Bias
                                          //  Referenced by: '<S423>/Bias'

  real32_T Gain_Gain_cw;               // Computed Parameter: Gain_Gain_cw
                                          //  Referenced by: '<S423>/Gain'

  real32_T TSamp_WtEt;                 // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S412>/TSamp'

  real32_T Integrator_gainval_e;     // Computed Parameter: Integrator_gainval_e
                                        //  Referenced by: '<S561>/Integrator'

  real32_T Bias1_Bias;                 // Computed Parameter: Bias1_Bias
                                          //  Referenced by: '<S423>/Bias1'

  real32_T Gain1_Gain_go;              // Computed Parameter: Gain1_Gain_go
                                          //  Referenced by: '<S422>/Gain1'

  real32_T UnitDelay2_InitialCondition;
                              // Computed Parameter: UnitDelay2_InitialCondition
                                 //  Referenced by: '<S422>/Unit Delay2'

  real32_T tau_Gain_n;                 // Computed Parameter: tau_Gain_n
                                          //  Referenced by: '<S424>/tau'

  real32_T Bias1_Bias_i;               // Computed Parameter: Bias1_Bias_i
                                          //  Referenced by: '<S425>/Bias1'

  real32_T Bias_Bias_l;                // Computed Parameter: Bias_Bias_l
                                          //  Referenced by: '<S425>/Bias'

  real32_T Gain_Gain_j0;               // Computed Parameter: Gain_Gain_j0
                                          //  Referenced by: '<S425>/Gain'

  real32_T UnitDelay1_InitialCondition_e;
                            // Computed Parameter: UnitDelay1_InitialCondition_e
                               //  Referenced by: '<S424>/Unit Delay1'

  real32_T Gain1_Gain_l;               // Computed Parameter: Gain1_Gain_l
                                          //  Referenced by: '<S424>/Gain1'

  real32_T UnitDelay2_InitialCondition_m;
                            // Computed Parameter: UnitDelay2_InitialCondition_m
                               //  Referenced by: '<S424>/Unit Delay2'

  real32_T TSamp_WtEt_m;               // Computed Parameter: TSamp_WtEt_m
                                          //  Referenced by: '<S413>/TSamp'

  real32_T Integrator_gainval_i;     // Computed Parameter: Integrator_gainval_i
                                        //  Referenced by: '<S461>/Integrator'

  real32_T tau_Gain_k;                 // Computed Parameter: tau_Gain_k
                                          //  Referenced by: '<S426>/tau'

  real32_T Bias1_Bias_j;               // Computed Parameter: Bias1_Bias_j
                                          //  Referenced by: '<S427>/Bias1'

  real32_T Bias_Bias_d;                // Computed Parameter: Bias_Bias_d
                                          //  Referenced by: '<S427>/Bias'

  real32_T Gain_Gain_og;               // Computed Parameter: Gain_Gain_og
                                          //  Referenced by: '<S427>/Gain'

  real32_T UnitDelay1_InitialCondition_d;
                            // Computed Parameter: UnitDelay1_InitialCondition_d
                               //  Referenced by: '<S426>/Unit Delay1'

  real32_T Gain1_Gain_g0;              // Computed Parameter: Gain1_Gain_g0
                                          //  Referenced by: '<S426>/Gain1'

  real32_T UnitDelay2_InitialCondition_f;
                            // Computed Parameter: UnitDelay2_InitialCondition_f
                               //  Referenced by: '<S426>/Unit Delay2'

  real32_T TSamp_WtEt_o;               // Computed Parameter: TSamp_WtEt_o
                                          //  Referenced by: '<S414>/TSamp'

  real32_T Integrator_gainval_i3;   // Computed Parameter: Integrator_gainval_i3
                                       //  Referenced by: '<S511>/Integrator'

  real32_T RateTransition_InitialCondition;
                          // Computed Parameter: RateTransition_InitialCondition
                             //  Referenced by: '<Root>/Rate Transition'

  real32_T RateTransition1_InitialConditio;
                          // Computed Parameter: RateTransition1_InitialConditio
                             //  Referenced by: '<Root>/Rate Transition1'

  real32_T RateTransition2_InitialConditio;
                          // Computed Parameter: RateTransition2_InitialConditio
                             //  Referenced by: '<Root>/Rate Transition2'

  real32_T RateTransition3_InitialConditio;
                          // Computed Parameter: RateTransition3_InitialConditio
                             //  Referenced by: '<Root>/Rate Transition3'

  real32_T Constant_Value_kf;          // Computed Parameter: Constant_Value_kf
                                          //  Referenced by: '<S181>/Constant'

  real32_T Constant_Value_ms;          // Computed Parameter: Constant_Value_ms
                                          //  Referenced by: '<S182>/Constant'

  real32_T Constant_Value_ii;          // Computed Parameter: Constant_Value_ii
                                          //  Referenced by: '<S183>/Constant'

  real32_T Constant_Value_j4;          // Computed Parameter: Constant_Value_j4
                                          //  Referenced by: '<S184>/Constant'

  real32_T Constant_Value_l;           // Computed Parameter: Constant_Value_l
                                          //  Referenced by: '<S185>/Constant'

  real32_T Constant_Value_o;           // Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S186>/Constant'

  real32_T Constant1_Value_i[6];       // Computed Parameter: Constant1_Value_i
                                          //  Referenced by: '<S12>/Constant1'

  real32_T Saturation_UpperSat_ep; // Computed Parameter: Saturation_UpperSat_ep
                                      //  Referenced by: '<S581>/Saturation'

  real32_T Saturation_LowerSat_p;   // Computed Parameter: Saturation_LowerSat_p
                                       //  Referenced by: '<S581>/Saturation'

  real32_T Constant_Value_ez;          // Computed Parameter: Constant_Value_ez
                                          //  Referenced by: '<S581>/Constant'

  real32_T Gain_Gain_mg;               // Computed Parameter: Gain_Gain_mg
                                          //  Referenced by: '<S581>/Gain'

  real32_T Merge1_InitialOutput;     // Computed Parameter: Merge1_InitialOutput
                                        //  Referenced by: '<Root>/Merge1'

  real32_T Constant_Value_gq;          // Computed Parameter: Constant_Value_gq
                                          //  Referenced by: '<S15>/Constant'

  real32_T Constant_Value_a5;          // Computed Parameter: Constant_Value_a5
                                          //  Referenced by: '<Root>/Constant'

  real32_T u2_Gain;                    // Computed Parameter: u2_Gain
                                          //  Referenced by: '<S589>/1//2'

  real32_T Merge_InitialOutput;       // Computed Parameter: Merge_InitialOutput
                                         //  Referenced by: '<Root>/Merge'

  real32_T Constant_Value_ll;          // Computed Parameter: Constant_Value_ll
                                          //  Referenced by: '<S17>/Constant'

  uint16_T PWM_Y0;                     // Computed Parameter: PWM_Y0
                                          //  Referenced by: '<S6>/PWM'

  uint16_T Output_Limits1_UpperSat;
                                  // Computed Parameter: Output_Limits1_UpperSat
                                     //  Referenced by: '<S6>/Output_Limits1'

  uint16_T Output_Limits1_LowerSat;
                                  // Computed Parameter: Output_Limits1_LowerSat
                                     //  Referenced by: '<S6>/Output_Limits1'

  uint16_T RateTransition4_InitialConditio;
                          // Computed Parameter: RateTransition4_InitialConditio
                             //  Referenced by: '<Root>/Rate Transition4'

  boolean_T RateTransition5_InitialConditio;
                          // Computed Parameter: RateTransition5_InitialConditio
                             //  Referenced by: '<Root>/Rate Transition5'

  boolean_T RateTransition6_InitialConditio;
                          // Computed Parameter: RateTransition6_InitialConditio
                             //  Referenced by: '<Root>/Rate Transition6'

  int8_T Constant_Value_jc;            // Computed Parameter: Constant_Value_jc
                                          //  Referenced by: '<S46>/Constant'

  int8_T Constant2_Value_m;            // Computed Parameter: Constant2_Value_m
                                          //  Referenced by: '<S46>/Constant2'

  int8_T Constant3_Value_es;           // Computed Parameter: Constant3_Value_es
                                          //  Referenced by: '<S46>/Constant3'

  int8_T Constant4_Value_j;            // Computed Parameter: Constant4_Value_j
                                          //  Referenced by: '<S46>/Constant4'

  int8_T Constant_Value_mn;            // Computed Parameter: Constant_Value_mn
                                          //  Referenced by: '<S269>/Constant'

  int8_T Constant2_Value_p;            // Computed Parameter: Constant2_Value_p
                                          //  Referenced by: '<S269>/Constant2'

  int8_T Constant3_Value_n;            // Computed Parameter: Constant3_Value_n
                                          //  Referenced by: '<S269>/Constant3'

  int8_T Constant4_Value_i;            // Computed Parameter: Constant4_Value_i
                                          //  Referenced by: '<S269>/Constant4'

};

// Real-time Model Data Structure
struct tag_RTM_FLIGHT_hexacopter_T {
  const char_T * volatile errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_FLIGHT_hexacopter_T FLIGHT_hexacopter_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_FLIGHT_hexacopter_T FLIGHT_hexacopter_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_FLIGHT_hexacopter_T FLIGHT_hexacopter_DW;

// External function called from main
#ifdef __cplusplus

extern "C"
{

#endif

  extern void FLIGHT_hexacopter_SetEventsForThisBaseStep(boolean_T *eventFlags);

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void FLIGHT_hexacopter_initialize(void);
  extern void FLIGHT_hexacopter_step0(void);
  extern void FLIGHT_hexacopter_step1(void);
  extern void FLIGHT_hexacopter_step(int_T tid);
  extern void FLIGHT_hexacopter_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_FLIGHT_hexacopter_T *const FLIGHT_hexacopter_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S18>/Display' : Unused code path elimination
//  Block '<S18>/Display1' : Unused code path elimination
//  Block '<S18>/Display2' : Unused code path elimination
//  Block '<S18>/Display3' : Unused code path elimination
//  Block '<S118>/Data Type Duplicate' : Unused code path elimination
//  Block '<S118>/Data Type Propagation' : Unused code path elimination
//  Block '<S169>/Data Type Duplicate' : Unused code path elimination
//  Block '<S169>/Data Type Propagation' : Unused code path elimination
//  Block '<Root>/Display' : Unused code path elimination
//  Block '<S188>/Data Type Conversion1' : Unused code path elimination
//  Block '<S188>/Data Type Conversion2' : Unused code path elimination
//  Block '<S188>/Dead Zone1' : Unused code path elimination
//  Block '<S188>/Dead Zone3' : Unused code path elimination
//  Block '<S188>/Display' : Unused code path elimination
//  Block '<S188>/Display1' : Unused code path elimination
//  Block '<S188>/Display2' : Unused code path elimination
//  Block '<S188>/Display3' : Unused code path elimination
//  Block '<S188>/Fcn1' : Unused code path elimination
//  Block '<S188>/Fcn2' : Unused code path elimination
//  Block '<S188>/Gain1' : Unused code path elimination
//  Block '<S188>/Gain2' : Unused code path elimination
//  Block '<S188>/Saturation1' : Unused code path elimination
//  Block '<S188>/Saturation9' : Unused code path elimination
//  Block '<S401>/NOT' : Unused code path elimination
//  Block '<S404>/NOT' : Unused code path elimination
//  Block '<S402>/Signal Copy' : Unused code path elimination
//  Block '<S402>/Signal Copy1' : Unused code path elimination
//  Block '<S402>/Signal Copy2' : Unused code path elimination
//  Block '<S408>/Bitwise Operator' : Unused code path elimination
//  Block '<S408>/Data Type Conversion' : Unused code path elimination
//  Block '<S408>/Data Type Conversion1' : Unused code path elimination
//  Block '<S408>/Data Type Conversion2' : Unused code path elimination
//  Block '<S408>/Gain' : Unused code path elimination
//  Block '<S408>/Gain1' : Unused code path elimination
//  Block '<S410>/NOT' : Unused code path elimination
//  Block '<S412>/Data Type Duplicate' : Unused code path elimination
//  Block '<S413>/Data Type Duplicate' : Unused code path elimination
//  Block '<S414>/Data Type Duplicate' : Unused code path elimination
//  Block '<S10>/Display' : Unused code path elimination
//  Block '<S10>/Display1' : Unused code path elimination
//  Block '<S10>/Display2' : Unused code path elimination
//  Block '<S10>/Display3' : Unused code path elimination
//  Block '<S10>/Display5' : Unused code path elimination
//  Block '<S10>/Display6' : Unused code path elimination
//  Block '<S10>/Display7' : Unused code path elimination
//  Block '<S585>/NOT' : Unused code path elimination
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<S7>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S7>/Data Type Conversion9' : Eliminate redundant data type conversion
//  Block '<S12>/Data Type Conversion1' : Eliminate redundant data type conversion


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
//  '<Root>' : 'FLIGHT_hexacopter'
//  '<S1>'   : 'FLIGHT_hexacopter/Altitude_Mode'
//  '<S2>'   : 'FLIGHT_hexacopter/CAS'
//  '<S3>'   : 'FLIGHT_hexacopter/Doublet_Generator'
//  '<S4>'   : 'FLIGHT_hexacopter/Fault_Injection'
//  '<S5>'   : 'FLIGHT_hexacopter/If Action Subsystem'
//  '<S6>'   : 'FLIGHT_hexacopter/Mixer'
//  '<S7>'   : 'FLIGHT_hexacopter/Read uORB'
//  '<S8>'   : 'FLIGHT_hexacopter/Remote Control'
//  '<S9>'   : 'FLIGHT_hexacopter/SAS'
//  '<S10>'  : 'FLIGHT_hexacopter/Stabilized_Mode'
//  '<S11>'  : 'FLIGHT_hexacopter/actuator_controls'
//  '<S12>'  : 'FLIGHT_hexacopter/actuator_outputs_motors'
//  '<S13>'  : 'FLIGHT_hexacopter/quat2eul'
//  '<S14>'  : 'FLIGHT_hexacopter/sub_vehicle_angular_velocity'
//  '<S15>'  : 'FLIGHT_hexacopter/vehicle_attitude_setpoint'
//  '<S16>'  : 'FLIGHT_hexacopter/vehicle_local_position_setpoint'
//  '<S17>'  : 'FLIGHT_hexacopter/vehicle_rate_setpoint'
//  '<S18>'  : 'FLIGHT_hexacopter/Altitude_Mode/Altitude_Mode_Stick2Command'
//  '<S19>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller'
//  '<S20>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4'
//  '<S21>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Anti-windup'
//  '<S22>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/D Gain'
//  '<S23>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/External Derivative'
//  '<S24>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Filter'
//  '<S25>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Filter ICs'
//  '<S26>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/I Gain'
//  '<S27>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Ideal P Gain'
//  '<S28>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S29>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Integrator'
//  '<S30>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Integrator ICs'
//  '<S31>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/N Copy'
//  '<S32>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/N Gain'
//  '<S33>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/P Copy'
//  '<S34>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Parallel P Gain'
//  '<S35>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Reset Signal'
//  '<S36>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Saturation'
//  '<S37>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Saturation Fdbk'
//  '<S38>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Sum'
//  '<S39>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Sum Fdbk'
//  '<S40>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tracking Mode'
//  '<S41>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tracking Mode Sum'
//  '<S42>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tsamp - Integral'
//  '<S43>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tsamp - Ngain'
//  '<S44>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/postSat Signal'
//  '<S45>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/preSat Signal'
//  '<S46>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel'
//  '<S47>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S48>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S49>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/D Gain/External Parameters'
//  '<S50>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/External Derivative/Error'
//  '<S51>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Filter/Disc. Forward Euler Filter'
//  '<S52>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Filter ICs/Internal IC - Filter'
//  '<S53>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/I Gain/External Parameters'
//  '<S54>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S55>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S56>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Integrator/Discrete'
//  '<S57>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Integrator ICs/Internal IC'
//  '<S58>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/N Copy/Disabled'
//  '<S59>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/N Gain/External Parameters'
//  '<S60>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/P Copy/Disabled'
//  '<S61>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Parallel P Gain/External Parameters'
//  '<S62>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Reset Signal/Disabled'
//  '<S63>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Saturation/Enabled'
//  '<S64>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S65>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Sum/Sum_PID'
//  '<S66>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S67>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tracking Mode/Disabled'
//  '<S68>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S69>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S70>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S71>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S72>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S73>'  : 'FLIGHT_hexacopter/CAS/Degrees to Radians'
//  '<S74>'  : 'FLIGHT_hexacopter/CAS/Degrees to Radians1'
//  '<S75>'  : 'FLIGHT_hexacopter/CAS/PID Controller3'
//  '<S76>'  : 'FLIGHT_hexacopter/CAS/PID Controller4'
//  '<S77>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Anti-windup'
//  '<S78>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/D Gain'
//  '<S79>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/External Derivative'
//  '<S80>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Filter'
//  '<S81>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Filter ICs'
//  '<S82>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/I Gain'
//  '<S83>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Ideal P Gain'
//  '<S84>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Ideal P Gain Fdbk'
//  '<S85>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Integrator'
//  '<S86>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Integrator ICs'
//  '<S87>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/N Copy'
//  '<S88>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/N Gain'
//  '<S89>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/P Copy'
//  '<S90>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Parallel P Gain'
//  '<S91>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Reset Signal'
//  '<S92>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation'
//  '<S93>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation Fdbk'
//  '<S94>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Sum'
//  '<S95>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Sum Fdbk'
//  '<S96>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Tracking Mode'
//  '<S97>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Tracking Mode Sum'
//  '<S98>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Tsamp - Integral'
//  '<S99>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Tsamp - Ngain'
//  '<S100>' : 'FLIGHT_hexacopter/CAS/PID Controller3/postSat Signal'
//  '<S101>' : 'FLIGHT_hexacopter/CAS/PID Controller3/preSat Signal'
//  '<S102>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Anti-windup/Disabled'
//  '<S103>' : 'FLIGHT_hexacopter/CAS/PID Controller3/D Gain/Disabled'
//  '<S104>' : 'FLIGHT_hexacopter/CAS/PID Controller3/External Derivative/Disabled'
//  '<S105>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Filter/Disabled'
//  '<S106>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Filter ICs/Disabled'
//  '<S107>' : 'FLIGHT_hexacopter/CAS/PID Controller3/I Gain/Disabled'
//  '<S108>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Ideal P Gain/Passthrough'
//  '<S109>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S110>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Integrator/Disabled'
//  '<S111>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Integrator ICs/Disabled'
//  '<S112>' : 'FLIGHT_hexacopter/CAS/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S113>' : 'FLIGHT_hexacopter/CAS/PID Controller3/N Gain/Disabled'
//  '<S114>' : 'FLIGHT_hexacopter/CAS/PID Controller3/P Copy/Disabled'
//  '<S115>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Parallel P Gain/External Parameters'
//  '<S116>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Reset Signal/Disabled'
//  '<S117>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation/External'
//  '<S118>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation/External/Saturation Dynamic'
//  '<S119>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation Fdbk/Disabled'
//  '<S120>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Sum/Passthrough_P'
//  '<S121>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Sum Fdbk/Disabled'
//  '<S122>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tracking Mode/Disabled'
//  '<S123>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S124>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S125>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S126>' : 'FLIGHT_hexacopter/CAS/PID Controller3/postSat Signal/Forward_Path'
//  '<S127>' : 'FLIGHT_hexacopter/CAS/PID Controller3/preSat Signal/Forward_Path'
//  '<S128>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Anti-windup'
//  '<S129>' : 'FLIGHT_hexacopter/CAS/PID Controller4/D Gain'
//  '<S130>' : 'FLIGHT_hexacopter/CAS/PID Controller4/External Derivative'
//  '<S131>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Filter'
//  '<S132>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Filter ICs'
//  '<S133>' : 'FLIGHT_hexacopter/CAS/PID Controller4/I Gain'
//  '<S134>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Ideal P Gain'
//  '<S135>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Ideal P Gain Fdbk'
//  '<S136>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Integrator'
//  '<S137>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Integrator ICs'
//  '<S138>' : 'FLIGHT_hexacopter/CAS/PID Controller4/N Copy'
//  '<S139>' : 'FLIGHT_hexacopter/CAS/PID Controller4/N Gain'
//  '<S140>' : 'FLIGHT_hexacopter/CAS/PID Controller4/P Copy'
//  '<S141>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Parallel P Gain'
//  '<S142>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Reset Signal'
//  '<S143>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation'
//  '<S144>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation Fdbk'
//  '<S145>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Sum'
//  '<S146>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Sum Fdbk'
//  '<S147>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tracking Mode'
//  '<S148>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tracking Mode Sum'
//  '<S149>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tsamp - Integral'
//  '<S150>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tsamp - Ngain'
//  '<S151>' : 'FLIGHT_hexacopter/CAS/PID Controller4/postSat Signal'
//  '<S152>' : 'FLIGHT_hexacopter/CAS/PID Controller4/preSat Signal'
//  '<S153>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Anti-windup/Disabled'
//  '<S154>' : 'FLIGHT_hexacopter/CAS/PID Controller4/D Gain/Disabled'
//  '<S155>' : 'FLIGHT_hexacopter/CAS/PID Controller4/External Derivative/Disabled'
//  '<S156>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Filter/Disabled'
//  '<S157>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Filter ICs/Disabled'
//  '<S158>' : 'FLIGHT_hexacopter/CAS/PID Controller4/I Gain/Disabled'
//  '<S159>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Ideal P Gain/Passthrough'
//  '<S160>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S161>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Integrator/Disabled'
//  '<S162>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Integrator ICs/Disabled'
//  '<S163>' : 'FLIGHT_hexacopter/CAS/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S164>' : 'FLIGHT_hexacopter/CAS/PID Controller4/N Gain/Disabled'
//  '<S165>' : 'FLIGHT_hexacopter/CAS/PID Controller4/P Copy/Disabled'
//  '<S166>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Parallel P Gain/External Parameters'
//  '<S167>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Reset Signal/Disabled'
//  '<S168>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation/External'
//  '<S169>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation/External/Saturation Dynamic'
//  '<S170>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation Fdbk/Disabled'
//  '<S171>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Sum/Passthrough_P'
//  '<S172>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Sum Fdbk/Disabled'
//  '<S173>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tracking Mode/Disabled'
//  '<S174>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S175>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S176>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S177>' : 'FLIGHT_hexacopter/CAS/PID Controller4/postSat Signal/Forward_Path'
//  '<S178>' : 'FLIGHT_hexacopter/CAS/PID Controller4/preSat Signal/Forward_Path'
//  '<S179>' : 'FLIGHT_hexacopter/Doublet_Generator/MATLAB Function'
//  '<S180>' : 'FLIGHT_hexacopter/Fault_Injection/Compare To Constant'
//  '<S181>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference'
//  '<S182>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference1'
//  '<S183>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference2'
//  '<S184>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference3'
//  '<S185>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference4'
//  '<S186>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference5'
//  '<S187>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller'
//  '<S188>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude_Mode_Stick2Command'
//  '<S189>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller'
//  '<S190>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller'
//  '<S191>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller'
//  '<S192>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4'
//  '<S193>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Anti-windup'
//  '<S194>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/D Gain'
//  '<S195>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/External Derivative'
//  '<S196>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Filter'
//  '<S197>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Filter ICs'
//  '<S198>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/I Gain'
//  '<S199>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Ideal P Gain'
//  '<S200>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S201>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Integrator'
//  '<S202>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Integrator ICs'
//  '<S203>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/N Copy'
//  '<S204>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/N Gain'
//  '<S205>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/P Copy'
//  '<S206>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Parallel P Gain'
//  '<S207>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Reset Signal'
//  '<S208>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Saturation'
//  '<S209>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Saturation Fdbk'
//  '<S210>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Sum'
//  '<S211>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Sum Fdbk'
//  '<S212>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tracking Mode'
//  '<S213>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tracking Mode Sum'
//  '<S214>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tsamp - Integral'
//  '<S215>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tsamp - Ngain'
//  '<S216>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/postSat Signal'
//  '<S217>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/preSat Signal'
//  '<S218>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Anti-windup/Disabled'
//  '<S219>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/D Gain/Disabled'
//  '<S220>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/External Derivative/Disabled'
//  '<S221>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Filter/Disabled'
//  '<S222>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Filter ICs/Disabled'
//  '<S223>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/I Gain/Disabled'
//  '<S224>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S225>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S226>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Integrator/Disabled'
//  '<S227>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Integrator ICs/Disabled'
//  '<S228>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S229>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/N Gain/Disabled'
//  '<S230>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/P Copy/Disabled'
//  '<S231>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Parallel P Gain/External Parameters'
//  '<S232>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Reset Signal/Disabled'
//  '<S233>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Saturation/Enabled'
//  '<S234>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S235>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Sum/Passthrough_P'
//  '<S236>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S237>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tracking Mode/Disabled'
//  '<S238>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S239>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S240>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S241>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S242>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S243>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4'
//  '<S244>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Anti-windup'
//  '<S245>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/D Gain'
//  '<S246>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/External Derivative'
//  '<S247>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Filter'
//  '<S248>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Filter ICs'
//  '<S249>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/I Gain'
//  '<S250>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Ideal P Gain'
//  '<S251>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S252>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Integrator'
//  '<S253>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Integrator ICs'
//  '<S254>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/N Copy'
//  '<S255>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/N Gain'
//  '<S256>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/P Copy'
//  '<S257>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Parallel P Gain'
//  '<S258>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Reset Signal'
//  '<S259>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Saturation'
//  '<S260>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Saturation Fdbk'
//  '<S261>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Sum'
//  '<S262>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Sum Fdbk'
//  '<S263>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tracking Mode'
//  '<S264>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tracking Mode Sum'
//  '<S265>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tsamp - Integral'
//  '<S266>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tsamp - Ngain'
//  '<S267>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/postSat Signal'
//  '<S268>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/preSat Signal'
//  '<S269>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel'
//  '<S270>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S271>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S272>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/D Gain/External Parameters'
//  '<S273>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/External Derivative/Error'
//  '<S274>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Filter/Disc. Forward Euler Filter'
//  '<S275>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Filter ICs/Internal IC - Filter'
//  '<S276>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/I Gain/External Parameters'
//  '<S277>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S278>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S279>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Integrator/Discrete'
//  '<S280>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Integrator ICs/Internal IC'
//  '<S281>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/N Copy/Disabled'
//  '<S282>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/N Gain/External Parameters'
//  '<S283>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/P Copy/Disabled'
//  '<S284>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Parallel P Gain/External Parameters'
//  '<S285>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Reset Signal/External Reset'
//  '<S286>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Saturation/Enabled'
//  '<S287>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S288>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Sum/Sum_PID'
//  '<S289>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S290>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tracking Mode/Disabled'
//  '<S291>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S292>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S293>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S294>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S295>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S296>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude'
//  '<S297>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Anti-windup'
//  '<S298>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/D Gain'
//  '<S299>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/External Derivative'
//  '<S300>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Filter'
//  '<S301>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Filter ICs'
//  '<S302>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/I Gain'
//  '<S303>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Ideal P Gain'
//  '<S304>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S305>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Integrator'
//  '<S306>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Integrator ICs'
//  '<S307>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/N Copy'
//  '<S308>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/N Gain'
//  '<S309>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/P Copy'
//  '<S310>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Parallel P Gain'
//  '<S311>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Reset Signal'
//  '<S312>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Saturation'
//  '<S313>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Saturation Fdbk'
//  '<S314>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Sum'
//  '<S315>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Sum Fdbk'
//  '<S316>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tracking Mode'
//  '<S317>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tracking Mode Sum'
//  '<S318>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tsamp - Integral'
//  '<S319>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tsamp - Ngain'
//  '<S320>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/postSat Signal'
//  '<S321>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/preSat Signal'
//  '<S322>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Anti-windup/Disabled'
//  '<S323>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/D Gain/Disabled'
//  '<S324>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/External Derivative/Disabled'
//  '<S325>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Filter/Disabled'
//  '<S326>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Filter ICs/Disabled'
//  '<S327>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/I Gain/Disabled'
//  '<S328>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S329>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Ideal P Gain Fdbk/Disabled'
//  '<S330>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Integrator/Disabled'
//  '<S331>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Integrator ICs/Disabled'
//  '<S332>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/N Copy/Disabled wSignal Specification'
//  '<S333>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/N Gain/Disabled'
//  '<S334>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/P Copy/Disabled'
//  '<S335>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Parallel P Gain/External Parameters'
//  '<S336>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Reset Signal/Disabled'
//  '<S337>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Saturation/Passthrough'
//  '<S338>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Saturation Fdbk/Disabled'
//  '<S339>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Sum/Passthrough_P'
//  '<S340>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Sum Fdbk/Disabled'
//  '<S341>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S342>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S343>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S344>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S345>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/postSat Signal/Forward_Path'
//  '<S346>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/preSat Signal/Forward_Path'
//  '<S347>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/NED2Body1'
//  '<S348>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude'
//  '<S349>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/NED2Body1/Calculate Transformation Matrix'
//  '<S350>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Anti-windup'
//  '<S351>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/D Gain'
//  '<S352>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/External Derivative'
//  '<S353>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Filter'
//  '<S354>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Filter ICs'
//  '<S355>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/I Gain'
//  '<S356>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Ideal P Gain'
//  '<S357>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S358>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Integrator'
//  '<S359>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Integrator ICs'
//  '<S360>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/N Copy'
//  '<S361>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/N Gain'
//  '<S362>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/P Copy'
//  '<S363>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Parallel P Gain'
//  '<S364>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Reset Signal'
//  '<S365>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Saturation'
//  '<S366>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Saturation Fdbk'
//  '<S367>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Sum'
//  '<S368>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Sum Fdbk'
//  '<S369>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tracking Mode'
//  '<S370>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tracking Mode Sum'
//  '<S371>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tsamp - Integral'
//  '<S372>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tsamp - Ngain'
//  '<S373>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/postSat Signal'
//  '<S374>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/preSat Signal'
//  '<S375>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Anti-windup/Disabled'
//  '<S376>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/D Gain/Disabled'
//  '<S377>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/External Derivative/Disabled'
//  '<S378>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Filter/Disabled'
//  '<S379>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Filter ICs/Disabled'
//  '<S380>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/I Gain/Disabled'
//  '<S381>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S382>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Ideal P Gain Fdbk/Disabled'
//  '<S383>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Integrator/Disabled'
//  '<S384>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Integrator ICs/Disabled'
//  '<S385>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/N Copy/Disabled wSignal Specification'
//  '<S386>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/N Gain/Disabled'
//  '<S387>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/P Copy/Disabled'
//  '<S388>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Parallel P Gain/External Parameters'
//  '<S389>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Reset Signal/Disabled'
//  '<S390>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Saturation/Passthrough'
//  '<S391>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Saturation Fdbk/Disabled'
//  '<S392>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Sum/Passthrough_P'
//  '<S393>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Sum Fdbk/Disabled'
//  '<S394>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S395>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S396>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S397>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S398>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/postSat Signal/Forward_Path'
//  '<S399>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/preSat Signal/Forward_Path'
//  '<S400>' : 'FLIGHT_hexacopter/Mixer/pwm_out2'
//  '<S401>' : 'FLIGHT_hexacopter/Read uORB/PX4 uORB Read'
//  '<S402>' : 'FLIGHT_hexacopter/Read uORB/Vehicle Attitude'
//  '<S403>' : 'FLIGHT_hexacopter/Read uORB/PX4 uORB Read/Enabled Subsystem'
//  '<S404>' : 'FLIGHT_hexacopter/Read uORB/Vehicle Attitude/PX4 uORB Read'
//  '<S405>' : 'FLIGHT_hexacopter/Read uORB/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'
//  '<S406>' : 'FLIGHT_hexacopter/Remote Control/Arm1'
//  '<S407>' : 'FLIGHT_hexacopter/Remote Control/Compare To Constant'
//  '<S408>' : 'FLIGHT_hexacopter/Remote Control/Radio Control Transmitter'
//  '<S409>' : 'FLIGHT_hexacopter/Remote Control/Arm1/Compare To Constant3'
//  '<S410>' : 'FLIGHT_hexacopter/Remote Control/Radio Control Transmitter/PX4 uORB Read'
//  '<S411>' : 'FLIGHT_hexacopter/Remote Control/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S412>' : 'FLIGHT_hexacopter/SAS/Discrete Derivative'
//  '<S413>' : 'FLIGHT_hexacopter/SAS/Discrete Derivative1'
//  '<S414>' : 'FLIGHT_hexacopter/SAS/Discrete Derivative2'
//  '<S415>' : 'FLIGHT_hexacopter/SAS/Discrete Varying Lowpass'
//  '<S416>' : 'FLIGHT_hexacopter/SAS/Discrete Varying Lowpass1'
//  '<S417>' : 'FLIGHT_hexacopter/SAS/Discrete Varying Lowpass2'
//  '<S418>' : 'FLIGHT_hexacopter/SAS/MATLAB Function'
//  '<S419>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate'
//  '<S420>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate'
//  '<S421>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate'
//  '<S422>' : 'FLIGHT_hexacopter/SAS/Discrete Varying Lowpass/SOS1'
//  '<S423>' : 'FLIGHT_hexacopter/SAS/Discrete Varying Lowpass/SOS1/Arithmetic'
//  '<S424>' : 'FLIGHT_hexacopter/SAS/Discrete Varying Lowpass1/SOS1'
//  '<S425>' : 'FLIGHT_hexacopter/SAS/Discrete Varying Lowpass1/SOS1/Arithmetic'
//  '<S426>' : 'FLIGHT_hexacopter/SAS/Discrete Varying Lowpass2/SOS1'
//  '<S427>' : 'FLIGHT_hexacopter/SAS/Discrete Varying Lowpass2/SOS1/Arithmetic'
//  '<S428>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Anti-windup'
//  '<S429>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/D Gain'
//  '<S430>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/External Derivative'
//  '<S431>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Filter'
//  '<S432>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Filter ICs'
//  '<S433>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/I Gain'
//  '<S434>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Ideal P Gain'
//  '<S435>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Ideal P Gain Fdbk'
//  '<S436>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Integrator'
//  '<S437>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Integrator ICs'
//  '<S438>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/N Copy'
//  '<S439>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/N Gain'
//  '<S440>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/P Copy'
//  '<S441>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Parallel P Gain'
//  '<S442>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Reset Signal'
//  '<S443>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Saturation'
//  '<S444>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Saturation Fdbk'
//  '<S445>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Sum'
//  '<S446>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Sum Fdbk'
//  '<S447>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Tracking Mode'
//  '<S448>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Tracking Mode Sum'
//  '<S449>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Tsamp - Integral'
//  '<S450>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Tsamp - Ngain'
//  '<S451>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/postSat Signal'
//  '<S452>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/preSat Signal'
//  '<S453>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Anti-windup/Passthrough'
//  '<S454>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/D Gain/Disabled'
//  '<S455>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/External Derivative/Disabled'
//  '<S456>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Filter/Disabled'
//  '<S457>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Filter ICs/Disabled'
//  '<S458>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/I Gain/External Parameters'
//  '<S459>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Ideal P Gain/Passthrough'
//  '<S460>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Ideal P Gain Fdbk/Disabled'
//  '<S461>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Integrator/Discrete'
//  '<S462>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Integrator ICs/Internal IC'
//  '<S463>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/N Copy/Disabled wSignal Specification'
//  '<S464>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/N Gain/Disabled'
//  '<S465>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/P Copy/Disabled'
//  '<S466>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Parallel P Gain/External Parameters'
//  '<S467>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Reset Signal/Disabled'
//  '<S468>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Saturation/Passthrough'
//  '<S469>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Saturation Fdbk/Disabled'
//  '<S470>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Sum/Sum_PI'
//  '<S471>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Sum Fdbk/Disabled'
//  '<S472>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Tracking Mode/Disabled'
//  '<S473>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Tracking Mode Sum/Passthrough'
//  '<S474>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Tsamp - Integral/TsSignalSpecification'
//  '<S475>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/Tsamp - Ngain/Passthrough'
//  '<S476>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/postSat Signal/Forward_Path'
//  '<S477>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_pitchrate/preSat Signal/Forward_Path'
//  '<S478>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Anti-windup'
//  '<S479>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/D Gain'
//  '<S480>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/External Derivative'
//  '<S481>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Filter'
//  '<S482>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Filter ICs'
//  '<S483>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/I Gain'
//  '<S484>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Ideal P Gain'
//  '<S485>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Ideal P Gain Fdbk'
//  '<S486>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Integrator'
//  '<S487>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Integrator ICs'
//  '<S488>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/N Copy'
//  '<S489>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/N Gain'
//  '<S490>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/P Copy'
//  '<S491>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Parallel P Gain'
//  '<S492>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Reset Signal'
//  '<S493>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Saturation'
//  '<S494>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Saturation Fdbk'
//  '<S495>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Sum'
//  '<S496>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Sum Fdbk'
//  '<S497>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Tracking Mode'
//  '<S498>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Tracking Mode Sum'
//  '<S499>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Tsamp - Integral'
//  '<S500>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Tsamp - Ngain'
//  '<S501>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/postSat Signal'
//  '<S502>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/preSat Signal'
//  '<S503>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Anti-windup/Passthrough'
//  '<S504>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/D Gain/Disabled'
//  '<S505>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/External Derivative/Disabled'
//  '<S506>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Filter/Disabled'
//  '<S507>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Filter ICs/Disabled'
//  '<S508>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/I Gain/External Parameters'
//  '<S509>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Ideal P Gain/Passthrough'
//  '<S510>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Ideal P Gain Fdbk/Disabled'
//  '<S511>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Integrator/Discrete'
//  '<S512>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Integrator ICs/Internal IC'
//  '<S513>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/N Copy/Disabled wSignal Specification'
//  '<S514>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/N Gain/Disabled'
//  '<S515>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/P Copy/Disabled'
//  '<S516>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Parallel P Gain/External Parameters'
//  '<S517>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Reset Signal/Disabled'
//  '<S518>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Saturation/Passthrough'
//  '<S519>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Saturation Fdbk/Disabled'
//  '<S520>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Sum/Sum_PI'
//  '<S521>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Sum Fdbk/Disabled'
//  '<S522>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Tracking Mode/Disabled'
//  '<S523>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Tracking Mode Sum/Passthrough'
//  '<S524>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Tsamp - Integral/TsSignalSpecification'
//  '<S525>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/Tsamp - Ngain/Passthrough'
//  '<S526>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/postSat Signal/Forward_Path'
//  '<S527>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_rollrate/preSat Signal/Forward_Path'
//  '<S528>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Anti-windup'
//  '<S529>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/D Gain'
//  '<S530>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/External Derivative'
//  '<S531>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Filter'
//  '<S532>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Filter ICs'
//  '<S533>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/I Gain'
//  '<S534>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Ideal P Gain'
//  '<S535>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Ideal P Gain Fdbk'
//  '<S536>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Integrator'
//  '<S537>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Integrator ICs'
//  '<S538>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/N Copy'
//  '<S539>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/N Gain'
//  '<S540>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/P Copy'
//  '<S541>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Parallel P Gain'
//  '<S542>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Reset Signal'
//  '<S543>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Saturation'
//  '<S544>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Saturation Fdbk'
//  '<S545>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Sum'
//  '<S546>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Sum Fdbk'
//  '<S547>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Tracking Mode'
//  '<S548>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Tracking Mode Sum'
//  '<S549>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Tsamp - Integral'
//  '<S550>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Tsamp - Ngain'
//  '<S551>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/postSat Signal'
//  '<S552>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/preSat Signal'
//  '<S553>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Anti-windup/Passthrough'
//  '<S554>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/D Gain/Disabled'
//  '<S555>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/External Derivative/Disabled'
//  '<S556>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Filter/Disabled'
//  '<S557>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Filter ICs/Disabled'
//  '<S558>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/I Gain/External Parameters'
//  '<S559>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Ideal P Gain/Passthrough'
//  '<S560>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Ideal P Gain Fdbk/Disabled'
//  '<S561>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Integrator/Discrete'
//  '<S562>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Integrator ICs/Internal IC'
//  '<S563>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/N Copy/Disabled wSignal Specification'
//  '<S564>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/N Gain/Disabled'
//  '<S565>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/P Copy/Disabled'
//  '<S566>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Parallel P Gain/External Parameters'
//  '<S567>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Reset Signal/Disabled'
//  '<S568>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Saturation/Passthrough'
//  '<S569>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Saturation Fdbk/Disabled'
//  '<S570>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Sum/Sum_PI'
//  '<S571>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Sum Fdbk/Disabled'
//  '<S572>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Tracking Mode/Disabled'
//  '<S573>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Tracking Mode Sum/Passthrough'
//  '<S574>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Tsamp - Integral/TsSignalSpecification'
//  '<S575>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/Tsamp - Ngain/Passthrough'
//  '<S576>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/postSat Signal/Forward_Path'
//  '<S577>' : 'FLIGHT_hexacopter/SAS/pid_ctrl_yawrate/preSat Signal/Forward_Path'
//  '<S578>' : 'FLIGHT_hexacopter/actuator_controls/PX4 ULog'
//  '<S579>' : 'FLIGHT_hexacopter/actuator_controls/PX4 ULog/PX4 uORB Message'
//  '<S580>' : 'FLIGHT_hexacopter/actuator_controls/PX4 ULog/PX4_log_write'
//  '<S581>' : 'FLIGHT_hexacopter/actuator_outputs_motors/Normalize_pwm6'
//  '<S582>' : 'FLIGHT_hexacopter/actuator_outputs_motors/PX4 ULog'
//  '<S583>' : 'FLIGHT_hexacopter/actuator_outputs_motors/PX4 ULog/PX4 uORB Message'
//  '<S584>' : 'FLIGHT_hexacopter/actuator_outputs_motors/PX4 ULog/PX4_log_write'
//  '<S585>' : 'FLIGHT_hexacopter/sub_vehicle_angular_velocity/PX4 uORB Read1'
//  '<S586>' : 'FLIGHT_hexacopter/sub_vehicle_angular_velocity/PX4 uORB Read1/Enabled Subsystem'
//  '<S587>' : 'FLIGHT_hexacopter/vehicle_attitude_setpoint/PX4 uORB Message'
//  '<S588>' : 'FLIGHT_hexacopter/vehicle_attitude_setpoint/PX4 uORB Write'
//  '<S589>' : 'FLIGHT_hexacopter/vehicle_attitude_setpoint/Rotation Angles to Quaternions'
//  '<S590>' : 'FLIGHT_hexacopter/vehicle_local_position_setpoint/PX4 uORB Message'
//  '<S591>' : 'FLIGHT_hexacopter/vehicle_local_position_setpoint/PX4 uORB Write'
//  '<S592>' : 'FLIGHT_hexacopter/vehicle_rate_setpoint/PX4 uORB Message'
//  '<S593>' : 'FLIGHT_hexacopter/vehicle_rate_setpoint/PX4 uORB Write'

#endif                                 // FLIGHT_hexacopter_h_

//
// File trailer for generated code.
//
// [EOF]
//
