//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_hexacopter.h
//
// Code generated for Simulink model 'FLIGHT_hexacopter'.
//
// Model version                  : 1.250
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Fri May 23 13:47:19 2025
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
#include <uORB/topics/vehicle_status.h>
#include <uORB/topics/actuator_motors.h>
#include <uORB/topics/vehicle_local_position_setpoint.h>
#include <uORB/topics/vehicle_attitude_setpoint.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/vehicle_rates_setpoint.h>
#include <uORB/topics/actuator_controls_status.h>
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

// Block signals for system '<S490>/PX4 Timestamp'
struct B_PX4Timestamp_FLIGHT_hexac_l_T {
  uint64_T PX4Timestamp;               // '<S490>/PX4 Timestamp'
};

// Block states (default storage) for system '<S490>/PX4 Timestamp'
struct DW_PX4Timestamp_FLIGHT_hexa_b_T {
  px4_internal_block_getPX4Abso_T obj; // '<S490>/PX4 Timestamp'
  boolean_T objisempty;                // '<S490>/PX4 Timestamp'
};

// Block signals for system '<S504>/PX4 Timestamp'
struct B_PX4Timestamp_FLIGHT_hexac_h_T {
  uint64_T PX4Timestamp;               // '<S504>/PX4 Timestamp'
};

// Block states (default storage) for system '<S504>/PX4 Timestamp'
struct DW_PX4Timestamp_FLIGHT_hexa_f_T {
  px4_internal_block_getPX4Abso_T obj; // '<S504>/PX4 Timestamp'
  boolean_T objisempty;                // '<S504>/PX4 Timestamp'
};

// Block signals (default storage)
struct B_FLIGHT_hexacopter_T {
  px4_Bus_vehicle_local_position In1;  // '<S303>/In1'
  px4_Bus_vehicle_local_position r;
  px4_Bus_vehicle_odometry In1_k;      // '<S305>/In1'
  px4_Bus_vehicle_odometry r1;
  px4_Bus_input_rc In1_i;              // '<S307>/In1'
  px4_Bus_input_rc r2;
  px4_Bus_vehicle_status In1_f;        // '<S503>/In1'
  px4_Bus_actuator_motors BusAssignment;// '<S494>/Bus Assignment'
  px4_Bus_vehicle_status r3;
  px4_Bus_vehicle_local_position_setpoint BusAssignment_g;// '<S20>/Bus Assignment' 
  px4_Bus_vehicle_attitude_setpoint BusAssignment_p;// '<S504>/Bus Assignment'
  px4_Bus_vehicle_angular_velocity r4;
  px4_Bus_vehicle_rates_setpoint BusAssignment_a;// '<S510>/Bus Assignment'
  px4_Bus_vehicle_angular_velocity In1_h;// '<S498>/In1'
  real32_T CreateDiagonalMatrix[9];    // '<S477>/Create Diagonal Matrix'
  px4_Bus_actuator_controls_status BusAssignment_gi;// '<S490>/Bus Assignment'
  uint16_T pwmValue[8];
  px4_Bus_actuator_armed In1_n;        // '<S502>/In1'
  px4_Bus_actuator_armed r5;
  real32_T U[3];
  real32_T ypr[3];                     // '<Root>/quat2eul'
  real32_T TmpSignalConversionAtSFun_c[3];// '<S11>/MATLAB Function'
  real32_T G1[3];                      // '<S11>/MATLAB Function1'
  real32_T TSamp[3];                   // '<S480>/TSamp'
  uint16_T DataTypeConversion6[6];     // '<S4>/Data Type Conversion6'
  real_T reletive_time_sec;
  real_T peak_angle_rad;
  real_T out_roll;                     // '<S3>/MATLAB Function'
  real_T out_pitch;                    // '<S3>/MATLAB Function'
  real_T out_yawrate;                  // '<S3>/MATLAB Function'
  real_T u0;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real32_T rate_transition_des_p;      // '<Root>/rate_transition_des_p'
  real32_T rate_transition_des_q;      // '<Root>/rate_transition_des_q'
  real32_T rate_transition_des_r;      // '<Root>/rate_transition_des_r'
  real32_T RateTransition1;            // '<Root>/Rate Transition1'
  real32_T rate_transition_throttle;   // '<Root>/rate_transition_throttle'
  real32_T Sum5;                       // '<S309>/Sum5'
  real32_T Sum5_d;                     // '<S310>/Sum5'
  real32_T Sum;                        // '<S10>/Sum'
  real32_T Switch2;                    // '<S173>/Switch2'
  real32_T Switch2_i;                  // '<S122>/Switch2'
  real32_T cfromc;
  real32_T ctoc;
  real32_T mul;
  real32_T t;
  real32_T ParamStep;
  real32_T ParamStep_m;
  real32_T Product5_l;                 // '<S477>/Product5'
  real32_T Gain_i;                     // '<S22>/Gain'
  real32_T Gain3;                      // '<S22>/Gain3'
  real32_T IProdOut_d;                 // '<S57>/IProd Out'
  real32_T NProdOut;                   // '<S63>/NProd Out'
  real32_T DeadZone;                   // '<S52>/DeadZone'
  int32_T r_c;
  int32_T br;
  int32_T b_ic;
  int32_T ParamStep_k;
  int32_T ParamStep_c;
  int32_T ParamStep_b;
  int32_T ParamStep_p;
  int32_T ParamStep_cv;
  int32_T ParamStep_f;
  uint16_T rate_transition_ctrl_sw;    // '<Root>/rate_transition_ctrl_sw'
  uint16_T RateTransition4;            // '<Root>/Rate Transition4'
  uint16_T Output_Limits1[6];          // '<S7>/Output_Limits1'
  boolean_T rate_transition_arm;       // '<Root>/rate_transition_arm'
  boolean_T RateTransition7;           // '<Root>/Rate Transition7'
  B_PX4Timestamp_FLIGHT_hexac_h_T PX4Timestamp_i;// '<S504>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexacop_T PX4Timestamp_pn;// '<S3>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexac_h_T PX4Timestamp_nd;// '<S504>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexac_l_T PX4Timestamp_n;// '<S490>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexac_l_T PX4Timestamp_p;// '<S490>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexac_l_T PX4Timestamp_o;// '<S490>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexacop_T PX4Timestamp;// '<S3>/PX4 Timestamp'
};

// Block states (default storage) for system '<Root>'
struct DW_FLIGHT_hexacopter_T {
  px4_internal_block_ParameterU_T obj; // '<S11>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_n;// '<S11>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_k;// '<S11>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_d;// '<S11>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_g;// '<S11>/Read Parameter'
  px4_internal_block_ParameterU_T obj_i;// '<S10>/read_mc_rollrate_p'
  px4_internal_block_ParameterU_T obj_e;// '<S10>/Read Parameter9'
  px4_internal_block_ParameterU_T obj_i4;// '<S10>/Read Parameter8'
  px4_internal_block_ParameterU_T obj_j;// '<S10>/Read Parameter7'
  px4_internal_block_ParameterU_T obj_a;// '<S10>/Read Parameter6'
  px4_internal_block_ParameterU_T obj_h;// '<S10>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_p;// '<S10>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_b;// '<S10>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_da;// '<S10>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_c;// '<S10>/Read Parameter10'
  px4_internal_block_ParameterU_T obj_ea;// '<S10>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_pi;// '<S195>/Read Parameter'
  px4_internal_block_ParameterU_T obj_eq;// '<S194>/Read Parameter'
  px4_internal_block_ParameterU_T obj_aq;// '<S4>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_cx;// '<S4>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_nt;// '<S4>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_ao;// '<S4>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_gv;// '<S4>/Read Parameter13'
  px4_internal_block_ParameterU_T obj_j5;// '<S4>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_l;// '<S3>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_ct;// '<S3>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_cf;// '<S3>/Read Parameter'
  px4_internal_block_ParameterU_T obj_k4;// '<S2>/Read Parameter9'
  px4_internal_block_ParameterU_T obj_ds;// '<S2>/Read Parameter10'
  px4_internal_block_ParameterU_T obj_o;// '<S2>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_jz;// '<S2>/Read Parameter'
  px4_internal_block_ParameterU_T obj_lx;// '<S1>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_l5;// '<S1>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_in;// '<S1>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_m;// '<S1>/Read Parameter1'
  px4_internal_block_Subscriber_T obj_bw;// '<S501>/SourceBlock'
  px4_internal_block_Subscriber_T obj_hm;// '<S500>/SourceBlock'
  px4_internal_block_Subscriber_T obj_pe;// '<S497>/SourceBlock'
  px4_internal_block_Subscriber_T obj_n2;// '<S306>/SourceBlock'
  px4_internal_block_Subscriber_T obj_ab;// '<S304>/SourceBlock'
  px4_internal_block_Subscriber_T obj_kk;// '<S301>/SourceBlock'
  px4_internal_block_PWM_FLIGHT_T obj_dl;// '<Root>/PX4 PWM Output'
  px4_internal_block_Publisher__T obj_mq;// '<S512>/SinkBlock'
  px4_internal_block_Publisher__T obj_pa;// '<S509>/SinkBlock'
  px4_internal_block_Publisher__T obj_ez;// '<S507>/SinkBlock'
  px4_internal_block_Publisher__T obj_hf;// '<S496>/SinkBlock'
  px4_internal_block_Publisher__T obj_jk;// '<S492>/SinkBlock'
  real_T start_time_usec;              // '<S3>/MATLAB Function'
  real32_T Integrator_DSTATE;          // '<S60>/Integrator'
  real32_T Filter_DSTATE;              // '<S55>/Filter'
  real32_T UD_DSTATE[3];               // '<S480>/UD'
  real32_T UD_DSTATE_j;                // '<S478>/UD'
  real32_T UD_DSTATE_g;                // '<S479>/UD'
  real32_T UD_DSTATE_n;                // '<S481>/UD'
  real32_T DiscreteTimeIntegrator_DSTATE;// '<S11>/Discrete-Time Integrator'
  real32_T UnitDelay1_DSTATE;          // '<S315>/Unit Delay1'
  real32_T UnitDelay2_DSTATE;          // '<S315>/Unit Delay2'
  real32_T UD_DSTATE_l;                // '<S312>/UD'
  real32_T Integrator_DSTATE_p;        // '<S350>/Integrator'
  real32_T UnitDelay1_DSTATE_f;        // '<S370>/Unit Delay1'
  real32_T UnitDelay2_DSTATE_c;        // '<S370>/Unit Delay2'
  real32_T UD_DSTATE_m;                // '<S367>/UD'
  real32_T Integrator_DSTATE_c;        // '<S405>/Integrator'
  real32_T UnitDelay1_DSTATE_e;        // '<S425>/Unit Delay1'
  real32_T UnitDelay2_DSTATE_e;        // '<S425>/Unit Delay2'
  real32_T UD_DSTATE_jy;               // '<S422>/UD'
  real32_T Integrator_DSTATE_g;        // '<S460>/Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_l;// '<S5>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator1_DSTATE;// '<S5>/Discrete-Time Integrator1'
  real32_T rate_transition_des_p_Buffer0;// '<Root>/rate_transition_des_p'
  real32_T rate_transition_des_q_Buffer0;// '<Root>/rate_transition_des_q'
  real32_T rate_transition_des_r_Buffer0;// '<Root>/rate_transition_des_r'
  real32_T RateTransition1_Buffer0;    // '<Root>/Rate Transition1'
  real32_T rate_transition_throttle_Buffer;// '<Root>/rate_transition_throttle'
  real32_T RateTransition_Buffer[3];   // '<Root>/Rate Transition'
  uint16_T rate_transition_ctrl_sw_Buffer0;// '<Root>/rate_transition_ctrl_sw'
  uint16_T RateTransition4_Buffer0;    // '<Root>/Rate Transition4'
  int8_T Integrator_PrevResetState;    // '<S60>/Integrator'
  int8_T Filter_PrevResetState;        // '<S55>/Filter'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S5>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator1_PrevRes;// '<S5>/Discrete-Time Integrator1'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S5>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;// '<S5>/Discrete-Time Integrator1'
  boolean_T rate_transition_arm_Buffer0;// '<Root>/rate_transition_arm'
  boolean_T RateTransition7_Buffer0;   // '<Root>/Rate Transition7'
  DW_PX4Timestamp_FLIGHT_hexa_f_T PX4Timestamp_i;// '<S504>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexaco_T PX4Timestamp_pn;// '<S3>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexa_f_T PX4Timestamp_nd;// '<S504>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexa_b_T PX4Timestamp_n;// '<S490>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexa_b_T PX4Timestamp_p;// '<S490>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexa_b_T PX4Timestamp_o;// '<S490>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexaco_T PX4Timestamp;// '<S3>/PX4 Timestamp'
};

// Parameters (default storage)
struct P_FLIGHT_hexacopter_T_ {
  real_T SampleTime;                   // Variable: SampleTime
                                          //  Referenced by:
                                          //    '<S1>/Read Parameter1'
                                          //    '<S1>/Read Parameter2'
                                          //    '<S1>/Read Parameter3'
                                          //    '<S1>/Read Parameter4'
                                          //    '<S2>/Read Parameter'
                                          //    '<S2>/Read Parameter1'
                                          //    '<S2>/Read Parameter10'
                                          //    '<S2>/Read Parameter9'
                                          //    '<S3>/Read Parameter'
                                          //    '<S3>/Read Parameter1'
                                          //    '<S3>/Read Parameter2'
                                          //    '<S11>/Read Parameter'
                                          //    '<S11>/Read Parameter1'
                                          //    '<S11>/Read Parameter2'
                                          //    '<S11>/Read Parameter3'
                                          //    '<S11>/Read Parameter4'
                                          //    '<S194>/Read Parameter'
                                          //    '<S195>/Read Parameter'

  real_T SampleTime_SAS;               // Variable: SampleTime_SAS
                                          //  Referenced by:
                                          //    '<S4>/Read Parameter1'
                                          //    '<S4>/Read Parameter13'
                                          //    '<S4>/Read Parameter2'
                                          //    '<S4>/Read Parameter3'
                                          //    '<S4>/Read Parameter4'
                                          //    '<S4>/Read Parameter5'
                                          //    '<S10>/Read Parameter1'
                                          //    '<S10>/Read Parameter10'
                                          //    '<S10>/Read Parameter2'
                                          //    '<S10>/Read Parameter3'
                                          //    '<S10>/Read Parameter4'
                                          //    '<S10>/Read Parameter5'
                                          //    '<S10>/Read Parameter6'
                                          //    '<S10>/Read Parameter7'
                                          //    '<S10>/Read Parameter8'
                                          //    '<S10>/Read Parameter9'
                                          //    '<S10>/read_mc_rollrate_p'

  real32_T Jxx;                        // Variable: Jxx
                                          //  Referenced by: '<S477>/Constant'

  real32_T Jyy;                        // Variable: Jyy
                                          //  Referenced by: '<S477>/Constant1'

  real32_T Jzz;                        // Variable: Jzz
                                          //  Referenced by: '<S477>/Constant2'

  real32_T MAX_CONTROL_ANGLE_PITCH;    // Variable: MAX_CONTROL_ANGLE_PITCH
                                          //  Referenced by:
                                          //    '<S12>/Gain5'
                                          //    '<S22>/Gain2'

  real32_T MAX_CONTROL_ANGLE_RATE_Y;   // Variable: MAX_CONTROL_ANGLE_RATE_Y
                                          //  Referenced by:
                                          //    '<S12>/Gain6'
                                          //    '<S22>/Gain3'

  real32_T MAX_CONTROL_ANGLE_ROLL;     // Variable: MAX_CONTROL_ANGLE_ROLL
                                          //  Referenced by:
                                          //    '<S12>/Gain4'
                                          //    '<S22>/Gain1'

  real32_T MAX_CONTROL_VELOCITY_XY;    // Variable: MAX_CONTROL_VELOCITY_XY
                                          //  Referenced by: '<S192>/Gain1'

  real32_T DiscreteDerivative2_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative2_ICPrevScale
                                 //  Referenced by: '<S312>/UD'

  real32_T DiscreteDerivative2_ICPrevSca_n;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_n
                                 //  Referenced by: '<S367>/UD'

  real32_T DiscreteDerivative2_ICPrevSca_o;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_o
                                 //  Referenced by: '<S422>/UD'

  real32_T DiscreteDerivative2_ICPrevSca_a;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_a
                                 //  Referenced by: '<S480>/UD'

  real32_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S478>/UD'

  real32_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: '<S479>/UD'

  real32_T DiscreteDerivative3_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative3_ICPrevScale
                                 //  Referenced by: '<S481>/UD'

  real32_T PIDController_InitialConditionF;
                              // Mask Parameter: PIDController_InitialConditionF
                                 //  Referenced by: '<S55>/Filter'

  real32_T pid_ctrl_rollrate_InitialCondit;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCondit
                                 //  Referenced by: '<S350>/Integrator'

  real32_T pid_ctrl_rollrate_InitialCond_j;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCond_j
                                 //  Referenced by: '<S405>/Integrator'

  real32_T pid_ctrl_rollrate_InitialCond_p;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCond_p
                                 //  Referenced by: '<S460>/Integrator'

  real32_T PIDController_InitialConditio_a;
                              // Mask Parameter: PIDController_InitialConditio_a
                                 //  Referenced by: '<S60>/Integrator'

  real32_T PIDController_LowerIntegratorSa;
                              // Mask Parameter: PIDController_LowerIntegratorSa
                                 //  Referenced by: '<S60>/Integrator'

  real32_T PIDController_LowerSaturationLi;
                              // Mask Parameter: PIDController_LowerSaturationLi
                                 //  Referenced by:
                                 //    '<S67>/Saturation'
                                 //    '<S52>/DeadZone'

  real32_T PIDController_UpperIntegratorSa;
                              // Mask Parameter: PIDController_UpperIntegratorSa
                                 //  Referenced by: '<S60>/Integrator'

  real32_T PIDController_UpperSaturationLi;
                              // Mask Parameter: PIDController_UpperSaturationLi
                                 //  Referenced by:
                                 //    '<S67>/Saturation'
                                 //    '<S52>/DeadZone'

  uint16_T CompareToConstant2_const; // Mask Parameter: CompareToConstant2_const
                                        //  Referenced by: '<S193>/Constant'

  uint16_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S488>/Constant'

  uint16_T CompareToConstant_const_g;
                                    // Mask Parameter: CompareToConstant_const_g
                                       //  Referenced by: '<S185>/Constant'

  uint16_T CompareToConstant1_const; // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: '<S23>/Constant'

  uint16_T CompareToConstant1_const_e;
                                   // Mask Parameter: CompareToConstant1_const_e
                                      //  Referenced by: '<S183>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0;// Computed Parameter: Out1_Y0
                                            //  Referenced by: '<S303>/Out1'

  px4_Bus_vehicle_local_position Constant_Value;// Computed Parameter: Constant_Value
                                                   //  Referenced by: '<S301>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0_d;  // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S305>/Out1'

  px4_Bus_vehicle_odometry Constant_Value_g;// Computed Parameter: Constant_Value_g
                                               //  Referenced by: '<S304>/Constant'

  px4_Bus_actuator_motors Constant_Value_m;// Computed Parameter: Constant_Value_m
                                              //  Referenced by: '<S495>/Constant'

  px4_Bus_input_rc Out1_Y0_o;          // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S307>/Out1'

  px4_Bus_input_rc Constant_Value_m1;  // Computed Parameter: Constant_Value_m1
                                          //  Referenced by: '<S306>/Constant'

  px4_Bus_vehicle_status Out1_Y0_a;    // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S503>/Out1'

  px4_Bus_vehicle_status Constant_Value_o;// Computed Parameter: Constant_Value_o
                                             //  Referenced by: '<S501>/Constant'

  px4_Bus_vehicle_local_position_setpoint Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                              //  Referenced by: '<S508>/Constant'

  px4_Bus_vehicle_attitude_setpoint Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                        //  Referenced by: '<S506>/Constant'

  px4_Bus_vehicle_angular_velocity Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                                //  Referenced by: '<S498>/Out1'

  px4_Bus_vehicle_angular_velocity Constant_Value_gk;// Computed Parameter: Constant_Value_gk
                                                        //  Referenced by: '<S497>/Constant'

  px4_Bus_vehicle_rates_setpoint Constant_Value_ni;// Computed Parameter: Constant_Value_ni
                                                      //  Referenced by: '<S511>/Constant'

  px4_Bus_actuator_controls_status Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                       //  Referenced by: '<S491>/Constant'

  px4_Bus_actuator_armed Out1_Y0_h;    // Computed Parameter: Out1_Y0_h
                                          //  Referenced by: '<S502>/Out1'

  px4_Bus_actuator_armed Constant_Value_m3;// Computed Parameter: Constant_Value_m3
                                              //  Referenced by: '<S500>/Constant'

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
                                          //  Referenced by: '<S12>/Constant'

  real_T Gain_Gain;                    // Expression: 1/800
                                          //  Referenced by: '<S12>/Gain'

  real_T Gain_Gain_j;                  // Expression: 0.01
                                          //  Referenced by: '<S186>/Gain'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<S186>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S186>/Saturation'

  real_T Gain_Gain_h;                  // Expression: 0.01
                                          //  Referenced by: '<S187>/Gain'

  real_T Saturation_UpperSat_m;        // Expression: 1
                                          //  Referenced by: '<S187>/Saturation'

  real_T Saturation_LowerSat_o;        // Expression: 0
                                          //  Referenced by: '<S187>/Saturation'

  real_T Gain_Gain_c;                  // Expression: 0.01
                                          //  Referenced by: '<S188>/Gain'

  real_T Saturation_UpperSat_b;        // Expression: 1
                                          //  Referenced by: '<S188>/Saturation'

  real_T Saturation_LowerSat_g;        // Expression: 0
                                          //  Referenced by: '<S188>/Saturation'

  real_T Gain_Gain_n;                  // Expression: 0.01
                                          //  Referenced by: '<S189>/Gain'

  real_T Saturation_UpperSat_be;       // Expression: 1
                                          //  Referenced by: '<S189>/Saturation'

  real_T Saturation_LowerSat_e;        // Expression: 0
                                          //  Referenced by: '<S189>/Saturation'

  real_T Gain_Gain_f;                  // Expression: 0.01
                                          //  Referenced by: '<S190>/Gain'

  real_T Saturation_UpperSat_d;        // Expression: 1
                                          //  Referenced by: '<S190>/Saturation'

  real_T Saturation_LowerSat_l;        // Expression: 0
                                          //  Referenced by: '<S190>/Saturation'

  real_T Gain_Gain_m;                  // Expression: 0.01
                                          //  Referenced by: '<S191>/Gain'

  real_T Saturation_UpperSat_i;        // Expression: 1
                                          //  Referenced by: '<S191>/Saturation'

  real_T Saturation_LowerSat_n;        // Expression: 0
                                          //  Referenced by: '<S191>/Saturation'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S2>/Gain1'

  real32_T Gain_Gain_m3;               // Computed Parameter: Gain_Gain_m3
                                          //  Referenced by: '<S2>/Gain'

  real32_T des_p_Y0;                   // Computed Parameter: des_p_Y0
                                          //  Referenced by: '<S2>/des_p'

  real32_T des_q_Y0;                   // Computed Parameter: des_q_Y0
                                          //  Referenced by: '<S2>/des_q'

  real32_T Gain1_Gain_g;               // Computed Parameter: Gain1_Gain_g
                                          //  Referenced by: '<S77>/Gain1'

  real32_T Gain1_Gain_c;               // Computed Parameter: Gain1_Gain_c
                                          //  Referenced by: '<S78>/Gain1'

  real32_T Gain_Gain_a;                // Computed Parameter: Gain_Gain_a
                                          //  Referenced by: '<S249>/Gain'

  real32_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S5>/Discrete-Time Integrator'

  real32_T DiscreteTimeIntegrator_UpperSat;
                          // Computed Parameter: DiscreteTimeIntegrator_UpperSat
                             //  Referenced by: '<S5>/Discrete-Time Integrator'

  real32_T DiscreteTimeIntegrator_LowerSat;
                          // Computed Parameter: DiscreteTimeIntegrator_LowerSat
                             //  Referenced by: '<S5>/Discrete-Time Integrator'

  real32_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<S5>/Discrete-Time Integrator1'

  real32_T DiscreteTimeIntegrator1_UpperSa;
                          // Computed Parameter: DiscreteTimeIntegrator1_UpperSa
                             //  Referenced by: '<S5>/Discrete-Time Integrator1'

  real32_T DiscreteTimeIntegrator1_LowerSa;
                          // Computed Parameter: DiscreteTimeIntegrator1_LowerSa
                             //  Referenced by: '<S5>/Discrete-Time Integrator1'

  real32_T Saturation_UpperSat_e;   // Computed Parameter: Saturation_UpperSat_e
                                       //  Referenced by: '<S195>/Saturation'

  real32_T Saturation_LowerSat_a;   // Computed Parameter: Saturation_LowerSat_a
                                       //  Referenced by: '<S195>/Saturation'

  real32_T Gain1_Gain_i;               // Computed Parameter: Gain1_Gain_i
                                          //  Referenced by: '<S195>/Gain1'

  real32_T DeadZone3_Start;            // Computed Parameter: DeadZone3_Start
                                          //  Referenced by: '<S192>/Dead Zone3'

  real32_T DeadZone3_End;              // Computed Parameter: DeadZone3_End
                                          //  Referenced by: '<S192>/Dead Zone3'

  real32_T Saturation9_UpperSat;     // Computed Parameter: Saturation9_UpperSat
                                        //  Referenced by: '<S192>/Saturation9'

  real32_T Saturation9_LowerSat;     // Computed Parameter: Saturation9_LowerSat
                                        //  Referenced by: '<S192>/Saturation9'

  real32_T DeadZone1_Start;            // Computed Parameter: DeadZone1_Start
                                          //  Referenced by: '<S192>/Dead Zone1'

  real32_T DeadZone1_End;              // Computed Parameter: DeadZone1_End
                                          //  Referenced by: '<S192>/Dead Zone1'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S192>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S192>/Saturation1'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S192>/Gain2'

  real32_T tau_roll_Y0;                // Computed Parameter: tau_roll_Y0
                                          //  Referenced by: '<S10>/tau_roll'

  real32_T tau_pitch_Y0;               // Computed Parameter: tau_pitch_Y0
                                          //  Referenced by: '<S10>/tau_pitch'

  real32_T tau_yaw_Y0;                 // Computed Parameter: tau_yaw_Y0
                                          //  Referenced by: '<S10>/tau_yaw'

  real32_T tau_Gain;                   // Computed Parameter: tau_Gain
                                          //  Referenced by: '<S315>/tau'

  real32_T Bias1_Bias;                 // Computed Parameter: Bias1_Bias
                                          //  Referenced by: '<S316>/Bias1'

  real32_T Bias_Bias;                  // Computed Parameter: Bias_Bias
                                          //  Referenced by: '<S316>/Bias'

  real32_T Gain_Gain_i;                // Computed Parameter: Gain_Gain_i
                                          //  Referenced by: '<S316>/Gain'

  real32_T UnitDelay1_InitialCondition;
                              // Computed Parameter: UnitDelay1_InitialCondition
                                 //  Referenced by: '<S315>/Unit Delay1'

  real32_T Gain1_Gain_j;               // Computed Parameter: Gain1_Gain_j
                                          //  Referenced by: '<S315>/Gain1'

  real32_T UnitDelay2_InitialCondition;
                              // Computed Parameter: UnitDelay2_InitialCondition
                                 //  Referenced by: '<S315>/Unit Delay2'

  real32_T TSamp_WtEt;                 // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S312>/TSamp'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S350>/Integrator'

  real32_T tau_Gain_n;                 // Computed Parameter: tau_Gain_n
                                          //  Referenced by: '<S370>/tau'

  real32_T Bias1_Bias_n;               // Computed Parameter: Bias1_Bias_n
                                          //  Referenced by: '<S371>/Bias1'

  real32_T Bias_Bias_b;                // Computed Parameter: Bias_Bias_b
                                          //  Referenced by: '<S371>/Bias'

  real32_T Gain_Gain_e;                // Computed Parameter: Gain_Gain_e
                                          //  Referenced by: '<S371>/Gain'

  real32_T UnitDelay1_InitialCondition_p;
                            // Computed Parameter: UnitDelay1_InitialCondition_p
                               //  Referenced by: '<S370>/Unit Delay1'

  real32_T Gain1_Gain_e;               // Computed Parameter: Gain1_Gain_e
                                          //  Referenced by: '<S370>/Gain1'

  real32_T UnitDelay2_InitialCondition_e;
                            // Computed Parameter: UnitDelay2_InitialCondition_e
                               //  Referenced by: '<S370>/Unit Delay2'

  real32_T TSamp_WtEt_m;               // Computed Parameter: TSamp_WtEt_m
                                          //  Referenced by: '<S367>/TSamp'

  real32_T Integrator_gainval_b;     // Computed Parameter: Integrator_gainval_b
                                        //  Referenced by: '<S405>/Integrator'

  real32_T tau_Gain_c;                 // Computed Parameter: tau_Gain_c
                                          //  Referenced by: '<S425>/tau'

  real32_T Bias1_Bias_i;               // Computed Parameter: Bias1_Bias_i
                                          //  Referenced by: '<S426>/Bias1'

  real32_T Bias_Bias_c;                // Computed Parameter: Bias_Bias_c
                                          //  Referenced by: '<S426>/Bias'

  real32_T Gain_Gain_b;                // Computed Parameter: Gain_Gain_b
                                          //  Referenced by: '<S426>/Gain'

  real32_T UnitDelay1_InitialCondition_e;
                            // Computed Parameter: UnitDelay1_InitialCondition_e
                               //  Referenced by: '<S425>/Unit Delay1'

  real32_T Gain1_Gain_iw;              // Computed Parameter: Gain1_Gain_iw
                                          //  Referenced by: '<S425>/Gain1'

  real32_T UnitDelay2_InitialCondition_m;
                            // Computed Parameter: UnitDelay2_InitialCondition_m
                               //  Referenced by: '<S425>/Unit Delay2'

  real32_T TSamp_WtEt_p;               // Computed Parameter: TSamp_WtEt_p
                                          //  Referenced by: '<S422>/TSamp'

  real32_T Integrator_gainval_p;     // Computed Parameter: Integrator_gainval_p
                                        //  Referenced by: '<S460>/Integrator'

  real32_T DeadZone3_Start_p;          // Computed Parameter: DeadZone3_Start_p
                                          //  Referenced by: '<S12>/Dead Zone3'

  real32_T DeadZone3_End_l;            // Computed Parameter: DeadZone3_End_l
                                          //  Referenced by: '<S12>/Dead Zone3'

  real32_T Saturation_UpperSat_o;   // Computed Parameter: Saturation_UpperSat_o
                                       //  Referenced by: '<S12>/Saturation'

  real32_T Saturation_LowerSat_el; // Computed Parameter: Saturation_LowerSat_el
                                      //  Referenced by: '<S12>/Saturation'

  real32_T Constant1_Value_l;          // Computed Parameter: Constant1_Value_l
                                          //  Referenced by: '<S12>/Constant1'

  real32_T Gain2_Gain_a;               // Computed Parameter: Gain2_Gain_a
                                          //  Referenced by: '<S12>/Gain2'

  real32_T DeadZone2_Start;            // Computed Parameter: DeadZone2_Start
                                          //  Referenced by: '<S12>/Dead Zone2'

  real32_T DeadZone2_End;              // Computed Parameter: DeadZone2_End
                                          //  Referenced by: '<S12>/Dead Zone2'

  real32_T Saturation1_UpperSat_l; // Computed Parameter: Saturation1_UpperSat_l
                                      //  Referenced by: '<S12>/Saturation1'

  real32_T Saturation1_LowerSat_i; // Computed Parameter: Saturation1_LowerSat_i
                                      //  Referenced by: '<S12>/Saturation1'

  real32_T Constant2_Value_i;          // Computed Parameter: Constant2_Value_i
                                          //  Referenced by: '<S12>/Constant2'

  real32_T Gain1_Gain_m;               // Computed Parameter: Gain1_Gain_m
                                          //  Referenced by: '<S12>/Gain1'

  real32_T DeadZone1_Start_c;          // Computed Parameter: DeadZone1_Start_c
                                          //  Referenced by: '<S12>/Dead Zone1'

  real32_T DeadZone1_End_m;            // Computed Parameter: DeadZone1_End_m
                                          //  Referenced by: '<S12>/Dead Zone1'

  real32_T Saturation2_UpperSat;     // Computed Parameter: Saturation2_UpperSat
                                        //  Referenced by: '<S12>/Saturation2'

  real32_T Saturation2_LowerSat;     // Computed Parameter: Saturation2_LowerSat
                                        //  Referenced by: '<S12>/Saturation2'

  real32_T Constant3_Value_e;          // Computed Parameter: Constant3_Value_e
                                          //  Referenced by: '<S12>/Constant3'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<S12>/Gain3'

  real32_T DeadZone_Start;             // Computed Parameter: DeadZone_Start
                                          //  Referenced by: '<S12>/Dead Zone'

  real32_T DeadZone_End;               // Computed Parameter: DeadZone_End
                                          //  Referenced by: '<S12>/Dead Zone'

  real32_T Saturation3_UpperSat;     // Computed Parameter: Saturation3_UpperSat
                                        //  Referenced by: '<S12>/Saturation3'

  real32_T Saturation3_LowerSat;     // Computed Parameter: Saturation3_LowerSat
                                        //  Referenced by: '<S12>/Saturation3'

  real32_T Constant1_Value_g;          // Computed Parameter: Constant1_Value_g
                                          //  Referenced by: '<S50>/Constant1'

  real32_T rate_transition_des_p_InitialCo;
                          // Computed Parameter: rate_transition_des_p_InitialCo
                             //  Referenced by: '<Root>/rate_transition_des_p'

  real32_T rate_transition_des_q_InitialCo;
                          // Computed Parameter: rate_transition_des_q_InitialCo
                             //  Referenced by: '<Root>/rate_transition_des_q'

  real32_T rate_transition_des_r_InitialCo;
                          // Computed Parameter: rate_transition_des_r_InitialCo
                             //  Referenced by: '<Root>/rate_transition_des_r'

  real32_T RateTransition1_InitialConditio;
                          // Computed Parameter: RateTransition1_InitialConditio
                             //  Referenced by: '<Root>/Rate Transition1'

  real32_T rate_transition_throttle_Initia;
                          // Computed Parameter: rate_transition_throttle_Initia
                             //  Referenced by: '<Root>/rate_transition_throttle'

  real32_T Constant1_Value_i[6];       // Computed Parameter: Constant1_Value_i
                                          //  Referenced by: '<S15>/Constant1'

  real32_T Saturation_UpperSat_ep; // Computed Parameter: Saturation_UpperSat_ep
                                      //  Referenced by: '<S493>/Saturation'

  real32_T Saturation_LowerSat_p;   // Computed Parameter: Saturation_LowerSat_p
                                       //  Referenced by: '<S493>/Saturation'

  real32_T Constant_Value_e;           // Computed Parameter: Constant_Value_e
                                          //  Referenced by: '<S493>/Constant'

  real32_T Gain_Gain_mg;               // Computed Parameter: Gain_Gain_mg
                                          //  Referenced by: '<S493>/Gain'

  real32_T Constant_Value_k;           // Computed Parameter: Constant_Value_k
                                          //  Referenced by: '<S186>/Constant'

  real32_T Constant_Value_ms;          // Computed Parameter: Constant_Value_ms
                                          //  Referenced by: '<S187>/Constant'

  real32_T Constant_Value_i;           // Computed Parameter: Constant_Value_i
                                          //  Referenced by: '<S188>/Constant'

  real32_T Constant_Value_j;           // Computed Parameter: Constant_Value_j
                                          //  Referenced by: '<S189>/Constant'

  real32_T Constant_Value_lw;          // Computed Parameter: Constant_Value_lw
                                          //  Referenced by: '<S190>/Constant'

  real32_T Constant_Value_ox;          // Computed Parameter: Constant_Value_ox
                                          //  Referenced by: '<S191>/Constant'

  real32_T DeadZone3_Start_l;          // Computed Parameter: DeadZone3_Start_l
                                          //  Referenced by: '<S22>/Dead Zone3'

  real32_T DeadZone3_End_n;            // Computed Parameter: DeadZone3_End_n
                                          //  Referenced by: '<S22>/Dead Zone3'

  real32_T Saturation9_UpperSat_c; // Computed Parameter: Saturation9_UpperSat_c
                                      //  Referenced by: '<S22>/Saturation9'

  real32_T Saturation9_LowerSat_i; // Computed Parameter: Saturation9_LowerSat_i
                                      //  Referenced by: '<S22>/Saturation9'

  real32_T DeadZone1_Start_n;          // Computed Parameter: DeadZone1_Start_n
                                          //  Referenced by: '<S22>/Dead Zone1'

  real32_T DeadZone1_End_mj;           // Computed Parameter: DeadZone1_End_mj
                                          //  Referenced by: '<S22>/Dead Zone1'

  real32_T Saturation1_UpperSat_d; // Computed Parameter: Saturation1_UpperSat_d
                                      //  Referenced by: '<S22>/Saturation1'

  real32_T Saturation1_LowerSat_b; // Computed Parameter: Saturation1_LowerSat_b
                                      //  Referenced by: '<S22>/Saturation1'

  real32_T DeadZone2_Start_m;          // Computed Parameter: DeadZone2_Start_m
                                          //  Referenced by: '<S22>/Dead Zone2'

  real32_T DeadZone2_End_b;            // Computed Parameter: DeadZone2_End_b
                                          //  Referenced by: '<S22>/Dead Zone2'

  real32_T Saturation3_UpperSat_d; // Computed Parameter: Saturation3_UpperSat_d
                                      //  Referenced by: '<S22>/Saturation3'

  real32_T Saturation3_LowerSat_n; // Computed Parameter: Saturation3_LowerSat_n
                                      //  Referenced by: '<S22>/Saturation3'

  real32_T DeadZone4_Start;            // Computed Parameter: DeadZone4_Start
                                          //  Referenced by: '<S22>/Dead Zone4'

  real32_T DeadZone4_End;              // Computed Parameter: DeadZone4_End
                                          //  Referenced by: '<S22>/Dead Zone4'

  real32_T Saturation10_UpperSat;   // Computed Parameter: Saturation10_UpperSat
                                       //  Referenced by: '<S22>/Saturation10'

  real32_T Saturation10_LowerSat;   // Computed Parameter: Saturation10_LowerSat
                                       //  Referenced by: '<S22>/Saturation10'

  real32_T Gain_Gain_er;               // Computed Parameter: Gain_Gain_er
                                          //  Referenced by: '<S22>/Gain'

  real32_T Gain_Gain_o;                // Computed Parameter: Gain_Gain_o
                                          //  Referenced by: '<S1>/Gain'

  real32_T Integrator_gainval_h;     // Computed Parameter: Integrator_gainval_h
                                        //  Referenced by: '<S60>/Integrator'

  real32_T Filter_gainval;             // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S55>/Filter'

  real32_T Constant_Value_gx;          // Computed Parameter: Constant_Value_gx
                                          //  Referenced by: '<S1>/Constant'

  real32_T Saturation1_UpperSat_lr;
                                  // Computed Parameter: Saturation1_UpperSat_lr
                                     //  Referenced by: '<S1>/Saturation1'

  real32_T Saturation1_LowerSat_e; // Computed Parameter: Saturation1_LowerSat_e
                                      //  Referenced by: '<S1>/Saturation1'

  real32_T TSamp_WtEt_k;               // Computed Parameter: TSamp_WtEt_k
                                          //  Referenced by: '<S480>/TSamp'

  real32_T TSamp_WtEt_c;               // Computed Parameter: TSamp_WtEt_c
                                          //  Referenced by: '<S478>/TSamp'

  real32_T TSamp_WtEt_b;               // Computed Parameter: TSamp_WtEt_b
                                          //  Referenced by: '<S479>/TSamp'

  real32_T TSamp_WtEt_py;              // Computed Parameter: TSamp_WtEt_py
                                          //  Referenced by: '<S481>/TSamp'

  real32_T DiscreteTimeIntegrator_gainva_c;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_c
                             //  Referenced by: '<S11>/Discrete-Time Integrator'

  real32_T DiscreteTimeIntegrator_IC;
                                // Computed Parameter: DiscreteTimeIntegrator_IC
                                   //  Referenced by: '<S11>/Discrete-Time Integrator'

  real32_T Saturation2_UpperSat_i; // Computed Parameter: Saturation2_UpperSat_i
                                      //  Referenced by: '<S11>/Saturation2'

  real32_T Saturation2_LowerSat_k; // Computed Parameter: Saturation2_LowerSat_k
                                      //  Referenced by: '<S11>/Saturation2'

  real32_T Constant_Value_ll;          // Computed Parameter: Constant_Value_ll
                                          //  Referenced by: '<S21>/Constant'

  real32_T Constant_Value_a5;          // Computed Parameter: Constant_Value_a5
                                          //  Referenced by: '<Root>/Constant'

  real32_T Clamping_zero_Value;       // Computed Parameter: Clamping_zero_Value
                                         //  Referenced by: '<S50>/Clamping_zero'

  uint16_T PWM_Y0;                     // Computed Parameter: PWM_Y0
                                          //  Referenced by: '<S7>/PWM'

  uint16_T Output_Limits1_UpperSat;
                                  // Computed Parameter: Output_Limits1_UpperSat
                                     //  Referenced by: '<S7>/Output_Limits1'

  uint16_T Output_Limits1_LowerSat;
                                  // Computed Parameter: Output_Limits1_LowerSat
                                     //  Referenced by: '<S7>/Output_Limits1'

  uint16_T rate_transition_ctrl_sw_Initial;
                          // Computed Parameter: rate_transition_ctrl_sw_Initial
                             //  Referenced by: '<Root>/rate_transition_ctrl_sw'

  uint16_T RateTransition4_InitialConditio;
                          // Computed Parameter: RateTransition4_InitialConditio
                             //  Referenced by: '<Root>/Rate Transition4'

  boolean_T rate_transition_arm_InitialCond;
                          // Computed Parameter: rate_transition_arm_InitialCond
                             //  Referenced by: '<Root>/rate_transition_arm'

  boolean_T RateTransition7_InitialConditio;
                          // Computed Parameter: RateTransition7_InitialConditio
                             //  Referenced by: '<Root>/Rate Transition7'

  int8_T Constant_Value_ko;            // Computed Parameter: Constant_Value_ko
                                          //  Referenced by: '<S50>/Constant'

  int8_T Constant2_Value_e;            // Computed Parameter: Constant2_Value_e
                                          //  Referenced by: '<S50>/Constant2'

  int8_T Constant3_Value_i;            // Computed Parameter: Constant3_Value_i
                                          //  Referenced by: '<S50>/Constant3'

  int8_T Constant4_Value_d;            // Computed Parameter: Constant4_Value_d
                                          //  Referenced by: '<S50>/Constant4'

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
//  Block '<S22>/Display' : Unused code path elimination
//  Block '<S22>/Display1' : Unused code path elimination
//  Block '<S22>/Display2' : Unused code path elimination
//  Block '<S22>/Display3' : Unused code path elimination
//  Block '<S122>/Data Type Duplicate' : Unused code path elimination
//  Block '<S122>/Data Type Propagation' : Unused code path elimination
//  Block '<S173>/Data Type Duplicate' : Unused code path elimination
//  Block '<S173>/Data Type Propagation' : Unused code path elimination
//  Block '<S192>/Data Type Conversion10' : Unused code path elimination
//  Block '<S192>/Data Type Conversion11' : Unused code path elimination
//  Block '<S192>/Dead Zone2' : Unused code path elimination
//  Block '<S192>/Dead Zone4' : Unused code path elimination
//  Block '<S192>/Display' : Unused code path elimination
//  Block '<S192>/Display1' : Unused code path elimination
//  Block '<S192>/Display2' : Unused code path elimination
//  Block '<S192>/Display3' : Unused code path elimination
//  Block '<S192>/Fcn3' : Unused code path elimination
//  Block '<S192>/Fcn7' : Unused code path elimination
//  Block '<S192>/Gain' : Unused code path elimination
//  Block '<S192>/Gain3' : Unused code path elimination
//  Block '<S192>/Saturation10' : Unused code path elimination
//  Block '<S192>/Saturation3' : Unused code path elimination
//  Block '<S301>/NOT' : Unused code path elimination
//  Block '<S304>/NOT' : Unused code path elimination
//  Block '<S302>/Signal Copy' : Unused code path elimination
//  Block '<S302>/Signal Copy1' : Unused code path elimination
//  Block '<S302>/Signal Copy2' : Unused code path elimination
//  Block '<S306>/NOT' : Unused code path elimination
//  Block '<S312>/Data Type Duplicate' : Unused code path elimination
//  Block '<S367>/Data Type Duplicate' : Unused code path elimination
//  Block '<S422>/Data Type Duplicate' : Unused code path elimination
//  Block '<S478>/Data Type Duplicate' : Unused code path elimination
//  Block '<S479>/Data Type Duplicate' : Unused code path elimination
//  Block '<S480>/Data Type Duplicate' : Unused code path elimination
//  Block '<S481>/Data Type Duplicate' : Unused code path elimination
//  Block '<Root>/Scope1' : Unused code path elimination
//  Block '<S12>/Display' : Unused code path elimination
//  Block '<S12>/Display1' : Unused code path elimination
//  Block '<S12>/Display2' : Unused code path elimination
//  Block '<S12>/Display3' : Unused code path elimination
//  Block '<S12>/Display5' : Unused code path elimination
//  Block '<S12>/Display6' : Unused code path elimination
//  Block '<S12>/Display7' : Unused code path elimination
//  Block '<S497>/NOT' : Unused code path elimination
//  Block '<S500>/NOT' : Unused code path elimination
//  Block '<S501>/NOT' : Unused code path elimination
//  Block '<S19>/Constant' : Unused code path elimination
//  Block '<S505>/1//2' : Unused code path elimination
//  Block '<S505>/q0' : Unused code path elimination
//  Block '<S505>/q1' : Unused code path elimination
//  Block '<S505>/q2' : Unused code path elimination
//  Block '<S505>/q3' : Unused code path elimination
//  Block '<S505>/sincos' : Unused code path elimination
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S8>/Data Type Conversion9' : Eliminate redundant data type conversion
//  Block '<S477>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S477>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion1' : Eliminate redundant data type conversion


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
//  '<S6>'   : 'FLIGHT_hexacopter/MATLAB Function'
//  '<S7>'   : 'FLIGHT_hexacopter/Mixer'
//  '<S8>'   : 'FLIGHT_hexacopter/Read uORB'
//  '<S9>'   : 'FLIGHT_hexacopter/Remote Control'
//  '<S10>'  : 'FLIGHT_hexacopter/SAS'
//  '<S11>'  : 'FLIGHT_hexacopter/SMC'
//  '<S12>'  : 'FLIGHT_hexacopter/Stabilized_Mode'
//  '<S13>'  : 'FLIGHT_hexacopter/Subsystem'
//  '<S14>'  : 'FLIGHT_hexacopter/actuator_controls'
//  '<S15>'  : 'FLIGHT_hexacopter/actuator_outputs_motors'
//  '<S16>'  : 'FLIGHT_hexacopter/quat2eul'
//  '<S17>'  : 'FLIGHT_hexacopter/sub_vehicle_angular_velocity'
//  '<S18>'  : 'FLIGHT_hexacopter/sub_vehicle_status'
//  '<S19>'  : 'FLIGHT_hexacopter/vehicle_attitude_setpoint'
//  '<S20>'  : 'FLIGHT_hexacopter/vehicle_local_position_setpoint'
//  '<S21>'  : 'FLIGHT_hexacopter/vehicle_rate_setpoint'
//  '<S22>'  : 'FLIGHT_hexacopter/Altitude_Mode/Altitude_Mode_Stick2Command'
//  '<S23>'  : 'FLIGHT_hexacopter/Altitude_Mode/Compare To Constant1'
//  '<S24>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller'
//  '<S25>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Anti-windup'
//  '<S26>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/D Gain'
//  '<S27>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/External Derivative'
//  '<S28>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Filter'
//  '<S29>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Filter ICs'
//  '<S30>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/I Gain'
//  '<S31>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Ideal P Gain'
//  '<S32>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Ideal P Gain Fdbk'
//  '<S33>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Integrator'
//  '<S34>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Integrator ICs'
//  '<S35>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/N Copy'
//  '<S36>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/N Gain'
//  '<S37>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/P Copy'
//  '<S38>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Parallel P Gain'
//  '<S39>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Reset Signal'
//  '<S40>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Saturation'
//  '<S41>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Saturation Fdbk'
//  '<S42>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Sum'
//  '<S43>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Sum Fdbk'
//  '<S44>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Tracking Mode'
//  '<S45>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Tracking Mode Sum'
//  '<S46>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Tsamp - Integral'
//  '<S47>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Tsamp - Ngain'
//  '<S48>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/postSat Signal'
//  '<S49>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/preSat Signal'
//  '<S50>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S51>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S52>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S53>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/D Gain/External Parameters'
//  '<S54>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/External Derivative/Error'
//  '<S55>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S56>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S57>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/I Gain/External Parameters'
//  '<S58>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Ideal P Gain/Passthrough'
//  '<S59>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S60>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Integrator/Discrete'
//  '<S61>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Integrator ICs/Internal IC'
//  '<S62>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/N Copy/Disabled'
//  '<S63>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/N Gain/External Parameters'
//  '<S64>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/P Copy/Disabled'
//  '<S65>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Parallel P Gain/External Parameters'
//  '<S66>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Reset Signal/External Reset'
//  '<S67>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Saturation/Enabled'
//  '<S68>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Saturation Fdbk/Disabled'
//  '<S69>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Sum/Sum_PID'
//  '<S70>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Sum Fdbk/Disabled'
//  '<S71>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Tracking Mode/Disabled'
//  '<S72>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S73>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S74>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S75>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/postSat Signal/Forward_Path'
//  '<S76>'  : 'FLIGHT_hexacopter/Altitude_Mode/PID Controller/preSat Signal/Forward_Path'
//  '<S77>'  : 'FLIGHT_hexacopter/CAS/Degrees to Radians'
//  '<S78>'  : 'FLIGHT_hexacopter/CAS/Degrees to Radians1'
//  '<S79>'  : 'FLIGHT_hexacopter/CAS/PID Controller3'
//  '<S80>'  : 'FLIGHT_hexacopter/CAS/PID Controller4'
//  '<S81>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Anti-windup'
//  '<S82>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/D Gain'
//  '<S83>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/External Derivative'
//  '<S84>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Filter'
//  '<S85>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Filter ICs'
//  '<S86>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/I Gain'
//  '<S87>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Ideal P Gain'
//  '<S88>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Ideal P Gain Fdbk'
//  '<S89>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Integrator'
//  '<S90>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Integrator ICs'
//  '<S91>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/N Copy'
//  '<S92>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/N Gain'
//  '<S93>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/P Copy'
//  '<S94>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Parallel P Gain'
//  '<S95>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Reset Signal'
//  '<S96>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation'
//  '<S97>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation Fdbk'
//  '<S98>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Sum'
//  '<S99>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Sum Fdbk'
//  '<S100>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tracking Mode'
//  '<S101>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tracking Mode Sum'
//  '<S102>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tsamp - Integral'
//  '<S103>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tsamp - Ngain'
//  '<S104>' : 'FLIGHT_hexacopter/CAS/PID Controller3/postSat Signal'
//  '<S105>' : 'FLIGHT_hexacopter/CAS/PID Controller3/preSat Signal'
//  '<S106>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Anti-windup/Disabled'
//  '<S107>' : 'FLIGHT_hexacopter/CAS/PID Controller3/D Gain/Disabled'
//  '<S108>' : 'FLIGHT_hexacopter/CAS/PID Controller3/External Derivative/Disabled'
//  '<S109>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Filter/Disabled'
//  '<S110>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Filter ICs/Disabled'
//  '<S111>' : 'FLIGHT_hexacopter/CAS/PID Controller3/I Gain/Disabled'
//  '<S112>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Ideal P Gain/Passthrough'
//  '<S113>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S114>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Integrator/Disabled'
//  '<S115>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Integrator ICs/Disabled'
//  '<S116>' : 'FLIGHT_hexacopter/CAS/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S117>' : 'FLIGHT_hexacopter/CAS/PID Controller3/N Gain/Disabled'
//  '<S118>' : 'FLIGHT_hexacopter/CAS/PID Controller3/P Copy/Disabled'
//  '<S119>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Parallel P Gain/External Parameters'
//  '<S120>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Reset Signal/Disabled'
//  '<S121>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation/External'
//  '<S122>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation/External/Saturation Dynamic'
//  '<S123>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation Fdbk/Disabled'
//  '<S124>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Sum/Passthrough_P'
//  '<S125>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Sum Fdbk/Disabled'
//  '<S126>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tracking Mode/Disabled'
//  '<S127>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S128>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S129>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S130>' : 'FLIGHT_hexacopter/CAS/PID Controller3/postSat Signal/Forward_Path'
//  '<S131>' : 'FLIGHT_hexacopter/CAS/PID Controller3/preSat Signal/Forward_Path'
//  '<S132>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Anti-windup'
//  '<S133>' : 'FLIGHT_hexacopter/CAS/PID Controller4/D Gain'
//  '<S134>' : 'FLIGHT_hexacopter/CAS/PID Controller4/External Derivative'
//  '<S135>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Filter'
//  '<S136>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Filter ICs'
//  '<S137>' : 'FLIGHT_hexacopter/CAS/PID Controller4/I Gain'
//  '<S138>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Ideal P Gain'
//  '<S139>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Ideal P Gain Fdbk'
//  '<S140>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Integrator'
//  '<S141>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Integrator ICs'
//  '<S142>' : 'FLIGHT_hexacopter/CAS/PID Controller4/N Copy'
//  '<S143>' : 'FLIGHT_hexacopter/CAS/PID Controller4/N Gain'
//  '<S144>' : 'FLIGHT_hexacopter/CAS/PID Controller4/P Copy'
//  '<S145>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Parallel P Gain'
//  '<S146>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Reset Signal'
//  '<S147>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation'
//  '<S148>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation Fdbk'
//  '<S149>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Sum'
//  '<S150>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Sum Fdbk'
//  '<S151>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tracking Mode'
//  '<S152>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tracking Mode Sum'
//  '<S153>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tsamp - Integral'
//  '<S154>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tsamp - Ngain'
//  '<S155>' : 'FLIGHT_hexacopter/CAS/PID Controller4/postSat Signal'
//  '<S156>' : 'FLIGHT_hexacopter/CAS/PID Controller4/preSat Signal'
//  '<S157>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Anti-windup/Disabled'
//  '<S158>' : 'FLIGHT_hexacopter/CAS/PID Controller4/D Gain/Disabled'
//  '<S159>' : 'FLIGHT_hexacopter/CAS/PID Controller4/External Derivative/Disabled'
//  '<S160>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Filter/Disabled'
//  '<S161>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Filter ICs/Disabled'
//  '<S162>' : 'FLIGHT_hexacopter/CAS/PID Controller4/I Gain/Disabled'
//  '<S163>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Ideal P Gain/Passthrough'
//  '<S164>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S165>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Integrator/Disabled'
//  '<S166>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Integrator ICs/Disabled'
//  '<S167>' : 'FLIGHT_hexacopter/CAS/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S168>' : 'FLIGHT_hexacopter/CAS/PID Controller4/N Gain/Disabled'
//  '<S169>' : 'FLIGHT_hexacopter/CAS/PID Controller4/P Copy/Disabled'
//  '<S170>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Parallel P Gain/External Parameters'
//  '<S171>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Reset Signal/Disabled'
//  '<S172>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation/External'
//  '<S173>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation/External/Saturation Dynamic'
//  '<S174>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation Fdbk/Disabled'
//  '<S175>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Sum/Passthrough_P'
//  '<S176>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Sum Fdbk/Disabled'
//  '<S177>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tracking Mode/Disabled'
//  '<S178>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S179>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S180>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S181>' : 'FLIGHT_hexacopter/CAS/PID Controller4/postSat Signal/Forward_Path'
//  '<S182>' : 'FLIGHT_hexacopter/CAS/PID Controller4/preSat Signal/Forward_Path'
//  '<S183>' : 'FLIGHT_hexacopter/Doublet_Generator/Compare To Constant1'
//  '<S184>' : 'FLIGHT_hexacopter/Doublet_Generator/MATLAB Function'
//  '<S185>' : 'FLIGHT_hexacopter/Fault_Injection/Compare To Constant'
//  '<S186>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference'
//  '<S187>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference1'
//  '<S188>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference2'
//  '<S189>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference3'
//  '<S190>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference4'
//  '<S191>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference5'
//  '<S192>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude_Mode_Stick2Command'
//  '<S193>' : 'FLIGHT_hexacopter/If Action Subsystem/Compare To Constant2'
//  '<S194>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller'
//  '<S195>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller'
//  '<S196>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude'
//  '<S197>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Anti-windup'
//  '<S198>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/D Gain'
//  '<S199>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/External Derivative'
//  '<S200>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Filter'
//  '<S201>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Filter ICs'
//  '<S202>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/I Gain'
//  '<S203>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Ideal P Gain'
//  '<S204>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S205>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Integrator'
//  '<S206>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Integrator ICs'
//  '<S207>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/N Copy'
//  '<S208>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/N Gain'
//  '<S209>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/P Copy'
//  '<S210>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Parallel P Gain'
//  '<S211>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Reset Signal'
//  '<S212>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Saturation'
//  '<S213>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Saturation Fdbk'
//  '<S214>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Sum'
//  '<S215>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Sum Fdbk'
//  '<S216>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tracking Mode'
//  '<S217>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tracking Mode Sum'
//  '<S218>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tsamp - Integral'
//  '<S219>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tsamp - Ngain'
//  '<S220>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/postSat Signal'
//  '<S221>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/preSat Signal'
//  '<S222>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Anti-windup/Disabled'
//  '<S223>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/D Gain/Disabled'
//  '<S224>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/External Derivative/Disabled'
//  '<S225>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Filter/Disabled'
//  '<S226>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Filter ICs/Disabled'
//  '<S227>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/I Gain/Disabled'
//  '<S228>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S229>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Ideal P Gain Fdbk/Disabled'
//  '<S230>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Integrator/Disabled'
//  '<S231>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Integrator ICs/Disabled'
//  '<S232>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/N Copy/Disabled wSignal Specification'
//  '<S233>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/N Gain/Disabled'
//  '<S234>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/P Copy/Disabled'
//  '<S235>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Parallel P Gain/External Parameters'
//  '<S236>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Reset Signal/Disabled'
//  '<S237>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Saturation/Passthrough'
//  '<S238>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Saturation Fdbk/Disabled'
//  '<S239>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Sum/Passthrough_P'
//  '<S240>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Sum Fdbk/Disabled'
//  '<S241>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S242>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S243>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S244>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S245>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/postSat Signal/Forward_Path'
//  '<S246>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/preSat Signal/Forward_Path'
//  '<S247>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/NED2Body1'
//  '<S248>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude'
//  '<S249>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/NED2Body1/Calculate Transformation Matrix'
//  '<S250>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Anti-windup'
//  '<S251>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/D Gain'
//  '<S252>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/External Derivative'
//  '<S253>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Filter'
//  '<S254>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Filter ICs'
//  '<S255>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/I Gain'
//  '<S256>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Ideal P Gain'
//  '<S257>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S258>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Integrator'
//  '<S259>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Integrator ICs'
//  '<S260>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/N Copy'
//  '<S261>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/N Gain'
//  '<S262>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/P Copy'
//  '<S263>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Parallel P Gain'
//  '<S264>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Reset Signal'
//  '<S265>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Saturation'
//  '<S266>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Saturation Fdbk'
//  '<S267>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Sum'
//  '<S268>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Sum Fdbk'
//  '<S269>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tracking Mode'
//  '<S270>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tracking Mode Sum'
//  '<S271>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tsamp - Integral'
//  '<S272>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tsamp - Ngain'
//  '<S273>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/postSat Signal'
//  '<S274>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/preSat Signal'
//  '<S275>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Anti-windup/Disabled'
//  '<S276>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/D Gain/Disabled'
//  '<S277>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/External Derivative/Disabled'
//  '<S278>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Filter/Disabled'
//  '<S279>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Filter ICs/Disabled'
//  '<S280>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/I Gain/Disabled'
//  '<S281>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S282>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Ideal P Gain Fdbk/Disabled'
//  '<S283>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Integrator/Disabled'
//  '<S284>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Integrator ICs/Disabled'
//  '<S285>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/N Copy/Disabled wSignal Specification'
//  '<S286>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/N Gain/Disabled'
//  '<S287>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/P Copy/Disabled'
//  '<S288>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Parallel P Gain/External Parameters'
//  '<S289>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Reset Signal/Disabled'
//  '<S290>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Saturation/Passthrough'
//  '<S291>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Saturation Fdbk/Disabled'
//  '<S292>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Sum/Passthrough_P'
//  '<S293>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Sum Fdbk/Disabled'
//  '<S294>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S295>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S296>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S297>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S298>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/postSat Signal/Forward_Path'
//  '<S299>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/preSat Signal/Forward_Path'
//  '<S300>' : 'FLIGHT_hexacopter/Mixer/pwm_out2'
//  '<S301>' : 'FLIGHT_hexacopter/Read uORB/PX4 uORB Read'
//  '<S302>' : 'FLIGHT_hexacopter/Read uORB/Vehicle Attitude'
//  '<S303>' : 'FLIGHT_hexacopter/Read uORB/PX4 uORB Read/Enabled Subsystem'
//  '<S304>' : 'FLIGHT_hexacopter/Read uORB/Vehicle Attitude/PX4 uORB Read'
//  '<S305>' : 'FLIGHT_hexacopter/Read uORB/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'
//  '<S306>' : 'FLIGHT_hexacopter/Remote Control/PX4 uORB Read'
//  '<S307>' : 'FLIGHT_hexacopter/Remote Control/PX4 uORB Read/Enabled Subsystem'
//  '<S308>' : 'FLIGHT_hexacopter/SAS/MATLAB Function'
//  '<S309>' : 'FLIGHT_hexacopter/SAS/Pitchrate'
//  '<S310>' : 'FLIGHT_hexacopter/SAS/Rollrate'
//  '<S311>' : 'FLIGHT_hexacopter/SAS/Yawrate'
//  '<S312>' : 'FLIGHT_hexacopter/SAS/Pitchrate/Discrete Derivative2'
//  '<S313>' : 'FLIGHT_hexacopter/SAS/Pitchrate/Discrete Varying Lowpass2'
//  '<S314>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate'
//  '<S315>' : 'FLIGHT_hexacopter/SAS/Pitchrate/Discrete Varying Lowpass2/SOS1'
//  '<S316>' : 'FLIGHT_hexacopter/SAS/Pitchrate/Discrete Varying Lowpass2/SOS1/Arithmetic'
//  '<S317>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Anti-windup'
//  '<S318>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/D Gain'
//  '<S319>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/External Derivative'
//  '<S320>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Filter'
//  '<S321>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Filter ICs'
//  '<S322>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/I Gain'
//  '<S323>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Ideal P Gain'
//  '<S324>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Ideal P Gain Fdbk'
//  '<S325>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Integrator'
//  '<S326>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Integrator ICs'
//  '<S327>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/N Copy'
//  '<S328>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/N Gain'
//  '<S329>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/P Copy'
//  '<S330>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Parallel P Gain'
//  '<S331>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Reset Signal'
//  '<S332>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Saturation'
//  '<S333>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Saturation Fdbk'
//  '<S334>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Sum'
//  '<S335>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Sum Fdbk'
//  '<S336>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Tracking Mode'
//  '<S337>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Tracking Mode Sum'
//  '<S338>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Tsamp - Integral'
//  '<S339>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Tsamp - Ngain'
//  '<S340>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/postSat Signal'
//  '<S341>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/preSat Signal'
//  '<S342>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Anti-windup/Passthrough'
//  '<S343>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/D Gain/Disabled'
//  '<S344>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/External Derivative/Disabled'
//  '<S345>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Filter/Disabled'
//  '<S346>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Filter ICs/Disabled'
//  '<S347>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/I Gain/External Parameters'
//  '<S348>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Ideal P Gain/Passthrough'
//  '<S349>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Ideal P Gain Fdbk/Disabled'
//  '<S350>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Integrator/Discrete'
//  '<S351>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Integrator ICs/Internal IC'
//  '<S352>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/N Copy/Disabled wSignal Specification'
//  '<S353>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/N Gain/Disabled'
//  '<S354>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/P Copy/Disabled'
//  '<S355>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Parallel P Gain/External Parameters'
//  '<S356>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Reset Signal/Disabled'
//  '<S357>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Saturation/Passthrough'
//  '<S358>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Saturation Fdbk/Disabled'
//  '<S359>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Sum/Sum_PI'
//  '<S360>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Sum Fdbk/Disabled'
//  '<S361>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Tracking Mode/Disabled'
//  '<S362>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Tracking Mode Sum/Passthrough'
//  '<S363>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Tsamp - Integral/TsSignalSpecification'
//  '<S364>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/Tsamp - Ngain/Passthrough'
//  '<S365>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/postSat Signal/Forward_Path'
//  '<S366>' : 'FLIGHT_hexacopter/SAS/Pitchrate/pid_ctrl_rollrate/preSat Signal/Forward_Path'
//  '<S367>' : 'FLIGHT_hexacopter/SAS/Rollrate/Discrete Derivative2'
//  '<S368>' : 'FLIGHT_hexacopter/SAS/Rollrate/Discrete Varying Lowpass2'
//  '<S369>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate'
//  '<S370>' : 'FLIGHT_hexacopter/SAS/Rollrate/Discrete Varying Lowpass2/SOS1'
//  '<S371>' : 'FLIGHT_hexacopter/SAS/Rollrate/Discrete Varying Lowpass2/SOS1/Arithmetic'
//  '<S372>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Anti-windup'
//  '<S373>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/D Gain'
//  '<S374>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/External Derivative'
//  '<S375>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Filter'
//  '<S376>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Filter ICs'
//  '<S377>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/I Gain'
//  '<S378>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Ideal P Gain'
//  '<S379>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Ideal P Gain Fdbk'
//  '<S380>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Integrator'
//  '<S381>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Integrator ICs'
//  '<S382>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/N Copy'
//  '<S383>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/N Gain'
//  '<S384>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/P Copy'
//  '<S385>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Parallel P Gain'
//  '<S386>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Reset Signal'
//  '<S387>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Saturation'
//  '<S388>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Saturation Fdbk'
//  '<S389>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Sum'
//  '<S390>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Sum Fdbk'
//  '<S391>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Tracking Mode'
//  '<S392>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Tracking Mode Sum'
//  '<S393>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Tsamp - Integral'
//  '<S394>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Tsamp - Ngain'
//  '<S395>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/postSat Signal'
//  '<S396>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/preSat Signal'
//  '<S397>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Anti-windup/Passthrough'
//  '<S398>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/D Gain/Disabled'
//  '<S399>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/External Derivative/Disabled'
//  '<S400>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Filter/Disabled'
//  '<S401>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Filter ICs/Disabled'
//  '<S402>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/I Gain/External Parameters'
//  '<S403>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Ideal P Gain/Passthrough'
//  '<S404>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Ideal P Gain Fdbk/Disabled'
//  '<S405>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Integrator/Discrete'
//  '<S406>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Integrator ICs/Internal IC'
//  '<S407>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/N Copy/Disabled wSignal Specification'
//  '<S408>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/N Gain/Disabled'
//  '<S409>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/P Copy/Disabled'
//  '<S410>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Parallel P Gain/External Parameters'
//  '<S411>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Reset Signal/Disabled'
//  '<S412>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Saturation/Passthrough'
//  '<S413>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Saturation Fdbk/Disabled'
//  '<S414>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Sum/Sum_PI'
//  '<S415>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Sum Fdbk/Disabled'
//  '<S416>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Tracking Mode/Disabled'
//  '<S417>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Tracking Mode Sum/Passthrough'
//  '<S418>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Tsamp - Integral/TsSignalSpecification'
//  '<S419>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/Tsamp - Ngain/Passthrough'
//  '<S420>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/postSat Signal/Forward_Path'
//  '<S421>' : 'FLIGHT_hexacopter/SAS/Rollrate/pid_ctrl_rollrate/preSat Signal/Forward_Path'
//  '<S422>' : 'FLIGHT_hexacopter/SAS/Yawrate/Discrete Derivative2'
//  '<S423>' : 'FLIGHT_hexacopter/SAS/Yawrate/Discrete Varying Lowpass2'
//  '<S424>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate'
//  '<S425>' : 'FLIGHT_hexacopter/SAS/Yawrate/Discrete Varying Lowpass2/SOS1'
//  '<S426>' : 'FLIGHT_hexacopter/SAS/Yawrate/Discrete Varying Lowpass2/SOS1/Arithmetic'
//  '<S427>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Anti-windup'
//  '<S428>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/D Gain'
//  '<S429>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/External Derivative'
//  '<S430>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Filter'
//  '<S431>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Filter ICs'
//  '<S432>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/I Gain'
//  '<S433>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Ideal P Gain'
//  '<S434>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Ideal P Gain Fdbk'
//  '<S435>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Integrator'
//  '<S436>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Integrator ICs'
//  '<S437>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/N Copy'
//  '<S438>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/N Gain'
//  '<S439>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/P Copy'
//  '<S440>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Parallel P Gain'
//  '<S441>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Reset Signal'
//  '<S442>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Saturation'
//  '<S443>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Saturation Fdbk'
//  '<S444>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Sum'
//  '<S445>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Sum Fdbk'
//  '<S446>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Tracking Mode'
//  '<S447>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Tracking Mode Sum'
//  '<S448>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Tsamp - Integral'
//  '<S449>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Tsamp - Ngain'
//  '<S450>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/postSat Signal'
//  '<S451>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/preSat Signal'
//  '<S452>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Anti-windup/Passthrough'
//  '<S453>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/D Gain/Disabled'
//  '<S454>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/External Derivative/Disabled'
//  '<S455>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Filter/Disabled'
//  '<S456>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Filter ICs/Disabled'
//  '<S457>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/I Gain/External Parameters'
//  '<S458>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Ideal P Gain/Passthrough'
//  '<S459>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Ideal P Gain Fdbk/Disabled'
//  '<S460>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Integrator/Discrete'
//  '<S461>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Integrator ICs/Internal IC'
//  '<S462>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/N Copy/Disabled wSignal Specification'
//  '<S463>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/N Gain/Disabled'
//  '<S464>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/P Copy/Disabled'
//  '<S465>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Parallel P Gain/External Parameters'
//  '<S466>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Reset Signal/Disabled'
//  '<S467>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Saturation/Passthrough'
//  '<S468>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Saturation Fdbk/Disabled'
//  '<S469>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Sum/Sum_PI'
//  '<S470>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Sum Fdbk/Disabled'
//  '<S471>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Tracking Mode/Disabled'
//  '<S472>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Tracking Mode Sum/Passthrough'
//  '<S473>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Tsamp - Integral/TsSignalSpecification'
//  '<S474>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/Tsamp - Ngain/Passthrough'
//  '<S475>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/postSat Signal/Forward_Path'
//  '<S476>' : 'FLIGHT_hexacopter/SAS/Yawrate/pid_ctrl_rollrate/preSat Signal/Forward_Path'
//  '<S477>' : 'FLIGHT_hexacopter/SMC/Calc_Fx_Gx'
//  '<S478>' : 'FLIGHT_hexacopter/SMC/Discrete Derivative'
//  '<S479>' : 'FLIGHT_hexacopter/SMC/Discrete Derivative1'
//  '<S480>' : 'FLIGHT_hexacopter/SMC/Discrete Derivative2'
//  '<S481>' : 'FLIGHT_hexacopter/SMC/Discrete Derivative3'
//  '<S482>' : 'FLIGHT_hexacopter/SMC/MATLAB Function'
//  '<S483>' : 'FLIGHT_hexacopter/SMC/MATLAB Function1'
//  '<S484>' : 'FLIGHT_hexacopter/SMC/MATLAB Function2'
//  '<S485>' : 'FLIGHT_hexacopter/SMC/MATLAB Function3'
//  '<S486>' : 'FLIGHT_hexacopter/SMC/MATLAB Function4'
//  '<S487>' : 'FLIGHT_hexacopter/SMC/Omega_phi'
//  '<S488>' : 'FLIGHT_hexacopter/Subsystem/Compare To Constant'
//  '<S489>' : 'FLIGHT_hexacopter/Subsystem/MATLAB Function'
//  '<S490>' : 'FLIGHT_hexacopter/actuator_controls/PX4 ULog'
//  '<S491>' : 'FLIGHT_hexacopter/actuator_controls/PX4 ULog/PX4 uORB Message'
//  '<S492>' : 'FLIGHT_hexacopter/actuator_controls/PX4 ULog/PX4_log_write'
//  '<S493>' : 'FLIGHT_hexacopter/actuator_outputs_motors/Normalize_pwm6'
//  '<S494>' : 'FLIGHT_hexacopter/actuator_outputs_motors/PX4 ULog'
//  '<S495>' : 'FLIGHT_hexacopter/actuator_outputs_motors/PX4 ULog/PX4 uORB Message'
//  '<S496>' : 'FLIGHT_hexacopter/actuator_outputs_motors/PX4 ULog/PX4_log_write'
//  '<S497>' : 'FLIGHT_hexacopter/sub_vehicle_angular_velocity/PX4 uORB Read1'
//  '<S498>' : 'FLIGHT_hexacopter/sub_vehicle_angular_velocity/PX4 uORB Read1/Enabled Subsystem'
//  '<S499>' : 'FLIGHT_hexacopter/sub_vehicle_status/MATLAB Function'
//  '<S500>' : 'FLIGHT_hexacopter/sub_vehicle_status/PX4 uORB Read'
//  '<S501>' : 'FLIGHT_hexacopter/sub_vehicle_status/PX4 uORB Read1'
//  '<S502>' : 'FLIGHT_hexacopter/sub_vehicle_status/PX4 uORB Read/Enabled Subsystem'
//  '<S503>' : 'FLIGHT_hexacopter/sub_vehicle_status/PX4 uORB Read1/Enabled Subsystem'
//  '<S504>' : 'FLIGHT_hexacopter/vehicle_attitude_setpoint/PX4 ULog'
//  '<S505>' : 'FLIGHT_hexacopter/vehicle_attitude_setpoint/Rotation Angles to Quaternions'
//  '<S506>' : 'FLIGHT_hexacopter/vehicle_attitude_setpoint/PX4 ULog/PX4 uORB Message'
//  '<S507>' : 'FLIGHT_hexacopter/vehicle_attitude_setpoint/PX4 ULog/PX4_log_write'
//  '<S508>' : 'FLIGHT_hexacopter/vehicle_local_position_setpoint/PX4 uORB Message'
//  '<S509>' : 'FLIGHT_hexacopter/vehicle_local_position_setpoint/PX4 uORB Write'
//  '<S510>' : 'FLIGHT_hexacopter/vehicle_rate_setpoint/PX4 ULog'
//  '<S511>' : 'FLIGHT_hexacopter/vehicle_rate_setpoint/PX4 ULog/PX4 uORB Message'
//  '<S512>' : 'FLIGHT_hexacopter/vehicle_rate_setpoint/PX4 ULog/PX4_log_write'

#endif                                 // FLIGHT_hexacopter_h_

//
// File trailer for generated code.
//
// [EOF]
//
