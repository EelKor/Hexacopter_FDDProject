//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_Hexacopter_V2.h
//
// Code generated for Simulink model 'FLIGHT_Hexacopter_V2'.
//
// Model version                  : 1.148
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed May 28 14:23:37 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef FLIGHT_Hexacopter_V2_h_
#define FLIGHT_Hexacopter_V2_h_
#include <drivers/drv_hrt.h>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "MW_PX4_PWM.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Write.h"
#include "MW_uORB_Read.h"
#include "FLIGHT_Hexacopter_V2_types.h"
#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/vehicle_attitude_smc_setpoint.h>
#include <uORB/topics/actuator_motors.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/vehicle_status.h>
#include <uORB/topics/vehicle_local_position_setpoint.h>
#include <uORB/topics/vehicle_attitude_setpoint.h>
#include <uORB/topics/vehicle_rates_setpoint.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/actuator_controls_status.h>

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

// Block signals for system '<S24>/PX4 Timestamp'
struct B_PX4Timestamp_FLIGHT_Hexacop_T {
  uint64_T PX4Timestamp;               // '<S24>/PX4 Timestamp'
};

// Block states (default storage) for system '<S24>/PX4 Timestamp'
struct DW_PX4Timestamp_FLIGHT_Hexaco_T {
  px4_internal_block_getPX4Abso_T obj; // '<S24>/PX4 Timestamp'
  boolean_T objisempty;                // '<S24>/PX4 Timestamp'
};

// Block signals for system '<S25>/PX4 Timestamp'
struct B_PX4Timestamp_FLIGHT_Hexac_l_T {
  uint64_T PX4Timestamp;               // '<S25>/PX4 Timestamp'
};

// Block states (default storage) for system '<S25>/PX4 Timestamp'
struct DW_PX4Timestamp_FLIGHT_Hexa_j_T {
  px4_internal_block_getPX4Abso_T obj; // '<S25>/PX4 Timestamp'
  boolean_T objisempty;                // '<S25>/PX4 Timestamp'
};

// Block signals for system '<S28>/PX4 Timestamp'
struct B_PX4Timestamp_FLIGHT_Hexac_c_T {
  uint64_T PX4Timestamp;               // '<S28>/PX4 Timestamp'
};

// Block states (default storage) for system '<S28>/PX4 Timestamp'
struct DW_PX4Timestamp_FLIGHT_Hexa_f_T {
  px4_internal_block_getPX4Abso_T obj; // '<S28>/PX4 Timestamp'
  boolean_T objisempty;                // '<S28>/PX4 Timestamp'
};

// Block signals for system '<S213>/SourceBlock'
struct B_SourceBlock_FLIGHT_Hexacopt_T {
  px4_Bus_actuator_armed SourceBlock_o2;// '<S213>/SourceBlock'
  boolean_T SourceBlock_o1;            // '<S213>/SourceBlock'
};

// Block states (default storage) for system '<S213>/SourceBlock'
struct DW_SourceBlock_FLIGHT_Hexacop_T {
  px4_internal_block_Subscriber_T obj; // '<S213>/SourceBlock'
  boolean_T objisempty;                // '<S213>/SourceBlock'
};

// Block signals (default storage)
struct B_FLIGHT_Hexacopter_V2_T {
  px4_Bus_vehicle_local_position In1;  // '<S221>/In1'
  px4_Bus_vehicle_local_position r;
  px4_Bus_vehicle_odometry In1_b;      // '<S224>/In1'
  px4_Bus_vehicle_attitude_smc_setpoint BusAssignment;// '<S28>/Bus Assignment'
  px4_Bus_vehicle_odometry r1;
  px4_Bus_actuator_motors BusAssignment_e;// '<S29>/Bus Assignment'
  px4_Bus_input_rc r2;
  px4_Bus_vehicle_status In1_m;        // '<S220>/In1'
  px4_Bus_input_rc In1_p;              // '<S209>/In1'
  px4_Bus_vehicle_status r3;
  real_T CreateDiagonalMatrix[9];      // '<S225>/Create Diagonal Matrix'
  px4_Bus_vehicle_local_position_setpoint BusAssignment_g;// '<S30>/Bus Assignment' 
  px4_Bus_vehicle_attitude_setpoint BusAssignment_f;// '<S25>/Bus Assignment'
  px4_Bus_vehicle_rates_setpoint BusAssignment_e0;// '<S26>/Bus Assignment'
  px4_Bus_vehicle_angular_velocity In1_k;// '<S211>/In1'
  px4_Bus_vehicle_angular_velocity r4;
  px4_Bus_actuator_controls_status BusAssignment_j;// '<S24>/Bus Assignment'
  px4_Bus_actuator_armed In1_d;        // '<S222>/In1'
  px4_Bus_actuator_armed In1_e;        // '<S219>/In1'
  uint16_T pwmValue[8];
  real32_T U[3];
  real32_T omega_phi[3];               // '<S9>/Omega_phi'
  real32_T G1[3];                      // '<S9>/MATLAB Function1'
  real32_T TSamp_o[3];                 // '<S229>/TSamp'
  real32_T G1_inv[3];                  // '<S9>/MATLAB Function2'
  real32_T b_A[3];
  real_T reletive_time_sec;
  real_T peak_angle_rad;
  real_T out_roll;                     // '<S4>/MATLAB Function1'
  real_T out_pitch;                    // '<S4>/MATLAB Function1'
  real_T out_yawrate;                  // '<S4>/MATLAB Function1'
  real_T u0;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real32_T RateTransition4;            // '<S10>/Rate Transition4'
  real32_T RateTransition3;            // '<S9>/Rate Transition3'
  real32_T RateTransition;             // '<S246>/Rate Transition'
  real32_T RateTransition4_a;          // '<S246>/Rate Transition4'
  real32_T RateTransition2;            // '<S246>/Rate Transition2'
  real32_T RateTransition3_b;          // '<S246>/Rate Transition3'
  real32_T RateTransition_e;           // '<S245>/Rate Transition'
  real32_T RateTransition4_b;          // '<S245>/Rate Transition4'
  real32_T RateTransition2_b;          // '<S245>/Rate Transition2'
  real32_T RateTransition3_be;         // '<S245>/Rate Transition3'
  real32_T RateTransition_j;           // '<S10>/Rate Transition'
  real32_T RateTransition1;            // '<S10>/Rate Transition1'
  real32_T RateTransition_f;           // '<S247>/Rate Transition'
  real32_T RateTransition4_ar;         // '<S247>/Rate Transition4'
  real32_T RateTransition2_d;          // '<S247>/Rate Transition2'
  real32_T RateTransition3_e;          // '<S247>/Rate Transition3'
  real32_T RateTransition1_c;          // '<S247>/Rate Transition1'
  real32_T RateTransition1_d;          // '<S245>/Rate Transition1'
  real32_T RateTransition1_o;          // '<S246>/Rate Transition1'
  real32_T ParamStep;
  real32_T ParamStep_m;
  real32_T ParamStep_c;
  real32_T ParamStep_k;
  real32_T ParamStep_cx;
  real32_T ParamStep_b;
  real32_T Integrator_p;               // '<S88>/Integrator'
  real32_T IProdOut_g;                 // '<S85>/IProd Out'
  real32_T Gain7;                      // '<S4>/Gain7'
  real32_T Gain4;                      // '<S4>/Gain4'
  real32_T Gain5;                      // '<S4>/Gain5'
  real32_T Gain6;                      // '<S4>/Gain6'
  real32_T NProdOut;                   // '<S91>/NProd Out'
  real32_T DeadZone;                   // '<S80>/DeadZone'
  real32_T Saturation5;                // '<S4>/Saturation5'
  real32_T Product_p;                  // '<S225>/Product'
  real32_T Product2_m;                 // '<S225>/Product2'
  real32_T Product4_gc;                // '<S225>/Product4'
  real32_T Diff_kx;                    // '<S227>/Diff'
  real32_T H;                          // '<S9>/MATLAB Function'
  real32_T Diff_o;                     // '<S230>/Diff'
  real32_T ReadParameter12_o1;         // '<S5>/Read Parameter12'
  real32_T ReadParameter13_o1;         // '<S5>/Read Parameter13'
  real32_T ReadParameter14_o1;         // '<S5>/Read Parameter14'
  real32_T ReadParameter15_o1;         // '<S5>/Read Parameter15'
  real32_T ReadParameter16_o1;         // '<S5>/Read Parameter16'
  real32_T ReadParameter17_o1;         // '<S5>/Read Parameter17'
  real32_T ReadParameter18_o1;         // '<S5>/Read Parameter18'
  real32_T ReadParameter19_o1;         // '<S5>/Read Parameter19'
  real32_T ReadParameter8_o1;          // '<S5>/Read Parameter8'
  real32_T read_mc_rollrate_p_o1;      // '<S5>/read_mc_rollrate_p'
  real32_T Gain7_p;                    // '<S4>/Gain7'
  real32_T rtb_MatrixConcatenate_idx_3;
  real32_T rtb_MatrixConcatenate_idx_0;
  real32_T rtb_sincos_o2_idx_2;
  real32_T rtb_ypr_idx_1;
  real32_T rtb_ypr_idx_2;
  real32_T rtb_G1_c;
  real32_T rtb_G1_f;
  real32_T f;
  real32_T anrm;
  real32_T roll;                       // '<S246>/Sum1'
  real32_T p;                          // '<S409>/Gain'
  real32_T q;                          // '<S409>/Product2'
  real32_T r_g;                        // '<S409>/Bias'
  real32_T d_g;                        // '<S409>/Add1'
  real32_T Sum5_nz;                    // '<S246>/Sum5'
  real32_T TSamp;                      // '<S405>/TSamp'
  real32_T Switch;                     // '<S2>/Switch'
  real32_T roll_h;                     // '<S245>/Sum1'
  real32_T p_e;                        // '<S354>/Gain'
  real32_T q_e;                        // '<S354>/Product2'
  real32_T r_a;                        // '<S354>/Bias'
  real32_T d_m;                        // '<S354>/Add1'
  real32_T roll_l;                     // '<S247>/Sum1'
  real32_T TSamp_c;                    // '<S350>/TSamp'
  int32_T exponent;
  int32_T ic;
  int32_T b_ic;
  int32_T i;
  int32_T ParamStep_me;
  int32_T ParamStep_n;
  int32_T ParamStep_p;
  int32_T ParamStep_l;
  int32_T ParamStep_j;
  int32_T ParamStep_d;
  uint16_T rc_ctrl_switch;             // '<Root>/Rate Transition'
  uint16_T rc_inject_failure;          // '<Root>/Rate Transition'
  boolean_T RateTransition6;           // '<S246>/Rate Transition6'
  boolean_T RateTransition6_a;         // '<S245>/Rate Transition6'
  boolean_T RateTransition6_o;         // '<S247>/Rate Transition6'
  boolean_T VehicleStatus_flag_armed;  // '<Root>/Rate Transition2'
  boolean_T VehicleStatus_flag_kill;   // '<Root>/Rate Transition2'
  B_SourceBlock_FLIGHT_Hexacopt_T SourceBlock_p;// '<S213>/SourceBlock'
  B_SourceBlock_FLIGHT_Hexacopt_T SourceBlock_l;// '<S213>/SourceBlock'
  B_PX4Timestamp_FLIGHT_Hexac_c_T PX4Timestamp_pna;// '<S28>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexac_l_T PX4Timestamp_k;// '<S25>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexacop_T PX4Timestamp_e;// '<S24>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexac_c_T PX4Timestamp_pn;// '<S28>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexac_l_T PX4Timestamp_p;// '<S25>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexac_l_T PX4Timestamp_j;// '<S25>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexacop_T PX4Timestamp_c;// '<S24>/PX4 Timestamp'
};

// Block states (default storage) for system '<Root>'
struct DW_FLIGHT_Hexacopter_V2_T {
  px4_internal_block_ParameterU_T obj; // '<S5>/read_mc_rollrate_p'
  px4_internal_block_ParameterU_T obj_a;// '<S5>/Read Parameter9'
  px4_internal_block_ParameterU_T obj_f;// '<S5>/Read Parameter8'
  px4_internal_block_ParameterU_T obj_fj;// '<S5>/Read Parameter7'
  px4_internal_block_ParameterU_T obj_p;// '<S5>/Read Parameter6'
  px4_internal_block_ParameterU_T obj_i;// '<S5>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_c;// '<S5>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_e;// '<S5>/Read Parameter38'
  px4_internal_block_ParameterU_T obj_pi;// '<S5>/Read Parameter37'
  px4_internal_block_ParameterU_T obj_l;// '<S5>/Read Parameter36'
  px4_internal_block_ParameterU_T obj_b;// '<S5>/Read Parameter35'
  px4_internal_block_ParameterU_T obj_o;// '<S5>/Read Parameter34'
  px4_internal_block_ParameterU_T obj_bd;// '<S5>/Read Parameter33'
  px4_internal_block_ParameterU_T obj_lv;// '<S5>/Read Parameter32'
  px4_internal_block_ParameterU_T obj_as;// '<S5>/Read Parameter31'
  px4_internal_block_ParameterU_T obj_m;// '<S5>/Read Parameter30'
  px4_internal_block_ParameterU_T obj_c4;// '<S5>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_br;// '<S5>/Read Parameter29'
  px4_internal_block_ParameterU_T obj_ic;// '<S5>/Read Parameter28'
  px4_internal_block_ParameterU_T obj_l3;// '<S5>/Read Parameter27'
  px4_internal_block_ParameterU_T obj_lt;// '<S5>/Read Parameter26'
  px4_internal_block_ParameterU_T obj_a1;// '<S5>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_mc;// '<S5>/Read Parameter19'
  px4_internal_block_ParameterU_T obj_ml;// '<S5>/Read Parameter18'
  px4_internal_block_ParameterU_T obj_d;// '<S5>/Read Parameter17'
  px4_internal_block_ParameterU_T obj_j;// '<S5>/Read Parameter16'
  px4_internal_block_ParameterU_T obj_n;// '<S5>/Read Parameter15'
  px4_internal_block_ParameterU_T obj_fd;// '<S5>/Read Parameter14'
  px4_internal_block_ParameterU_T obj_pf;// '<S5>/Read Parameter13'
  px4_internal_block_ParameterU_T obj_jo;// '<S5>/Read Parameter12'
  px4_internal_block_ParameterU_T obj_jk;// '<S5>/Read Parameter11'
  px4_internal_block_ParameterU_T obj_bq;// '<S5>/Read Parameter10'
  px4_internal_block_ParameterU_T obj_l4;// '<S5>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_jf;// '<S5>/Read Parameter'
  px4_internal_block_ParameterU_T obj_ic5;// '<S12>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_jg;// '<S12>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_h;// '<S12>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_ps;// '<S12>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_oe;// '<S12>/Read Parameter13'
  px4_internal_block_ParameterU_T obj_aw;// '<S12>/Read Parameter1'
  px4_internal_block_getPX4Abso_T obj_a5;// '<S3>/PX4 Timestamp'
  px4_internal_block_Subscriber_T obj_i4;// '<S223>/SourceBlock'
  px4_internal_block_Subscriber_T obj_lk;// '<S215>/SourceBlock'
  px4_internal_block_Subscriber_T obj_ab;// '<S214>/SourceBlock'
  px4_internal_block_Subscriber_T obj_mh;// '<S210>/SourceBlock'
  px4_internal_block_Subscriber_T obj_nt;// '<S208>/SourceBlock'
  px4_internal_block_PWM_FLIGHT_T obj_md;// '<S1>/PX4 PWM Output'
  px4_internal_block_Publisher__T obj_pm;// '<S42>/SinkBlock'
  px4_internal_block_Publisher__T obj_nf;// '<S40>/SinkBlock'
  px4_internal_block_Publisher__T obj_k;// '<S38>/SinkBlock'
  px4_internal_block_Publisher__T obj_mp;// '<S36>/SinkBlock'
  px4_internal_block_Publisher__T obj_m1;// '<S34>/SinkBlock'
  px4_internal_block_Publisher__T obj_fe;// '<S32>/SinkBlock'
  real_T start_time_usec;              // '<S4>/MATLAB Function1'
  real32_T Integrator_DSTATE;          // '<S443>/Integrator'
  real32_T UnitDelay1_DSTATE;          // '<S408>/Unit Delay1'
  real32_T UD_DSTATE;                  // '<S405>/UD'
  real32_T Integrator_DSTATE_c;        // '<S388>/Integrator'
  real32_T UnitDelay1_DSTATE_k;        // '<S353>/Unit Delay1'
  real32_T UD_DSTATE_o;                // '<S350>/UD'
  real32_T Integrator_DSTATE_o;        // '<S498>/Integrator'
  real32_T UnitDelay1_DSTATE_kh;       // '<S463>/Unit Delay1'
  real32_T UD_DSTATE_k;                // '<S460>/UD'
  real32_T UnitDelay2_DSTATE;          // '<S463>/Unit Delay2'
  real32_T UnitDelay2_DSTATE_l;        // '<S353>/Unit Delay2'
  real32_T UnitDelay2_DSTATE_h;        // '<S408>/Unit Delay2'
  real32_T Integrator_DSTATE_i;        // '<S88>/Integrator'
  real32_T Filter_DSTATE;              // '<S83>/Filter'
  real32_T DiscreteTimeIntegrator_DSTATE;// '<S4>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator1_DSTATE;// '<S4>/Discrete-Time Integrator1'
  real32_T UD_DSTATE_h[3];             // '<S229>/UD'
  real32_T UnitDelay_DSTATE;           // '<S238>/Unit Delay'
  real32_T UD_DSTATE_o2;               // '<S227>/UD'
  real32_T UD_DSTATE_e;                // '<S228>/UD'
  real32_T UD_DSTATE_g;                // '<S230>/UD'
  real32_T DiscreteTimeIntegrator_DSTATE_l;// '<S9>/Discrete-Time Integrator'
  real32_T RateTransition4_Buffer0;    // '<S10>/Rate Transition4'
  real32_T RateTransition3_Buffer0;    // '<S9>/Rate Transition3'
  real32_T RateTransition_Buffer0;     // '<S246>/Rate Transition'
  real32_T RateTransition4_Buffer0_e;  // '<S246>/Rate Transition4'
  real32_T RateTransition2_Buffer0;    // '<S246>/Rate Transition2'
  real32_T RateTransition3_Buffer0_e;  // '<S246>/Rate Transition3'
  real32_T RateTransition_Buffer0_c;   // '<S245>/Rate Transition'
  real32_T RateTransition4_Buffer0_k;  // '<S245>/Rate Transition4'
  real32_T RateTransition2_Buffer0_l;  // '<S245>/Rate Transition2'
  real32_T RateTransition3_Buffer0_p;  // '<S245>/Rate Transition3'
  real32_T RateTransition_Buffer0_h;   // '<S10>/Rate Transition'
  real32_T RateTransition1_Buffer0;    // '<S10>/Rate Transition1'
  real32_T RateTransition_Buffer0_hv;  // '<S247>/Rate Transition'
  real32_T RateTransition4_Buffer0_c;  // '<S247>/Rate Transition4'
  real32_T RateTransition2_Buffer0_d;  // '<S247>/Rate Transition2'
  real32_T RateTransition3_Buffer0_d;  // '<S247>/Rate Transition3'
  real32_T RateTransition1_Buffer0_m;  // '<S247>/Rate Transition1'
  real32_T RateTransition1_Buffer0_l;  // '<S245>/Rate Transition1'
  real32_T RateTransition1_Buffer0_l4; // '<S246>/Rate Transition1'
  real32_T RateTransition2_Buffer[3];  // '<S9>/Rate Transition2'
  real32_T RateTransition_Buffer;      // '<S3>/Rate Transition'
  uint16_T RateTransition_8_Buffer0;   // '<Root>/Rate Transition'
  uint16_T RateTransition_4_Buffer0;   // '<Root>/Rate Transition'
  int8_T Integrator_PrevResetState;    // '<S443>/Integrator'
  int8_T Integrator_PrevResetState_h;  // '<S388>/Integrator'
  int8_T Integrator_PrevResetState_hd; // '<S498>/Integrator'
  int8_T Integrator_PrevResetState_e;  // '<S88>/Integrator'
  int8_T Filter_PrevResetState;        // '<S83>/Filter'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S4>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator1_PrevRes;// '<S4>/Discrete-Time Integrator1'
  int8_T DiscreteTimeIntegrator_PrevRe_l;// '<S9>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S4>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;// '<S4>/Discrete-Time Integrator1'
  boolean_T RateTransition6_Buffer0;   // '<S246>/Rate Transition6'
  boolean_T RateTransition6_Buffer0_i; // '<S245>/Rate Transition6'
  boolean_T RateTransition6_Buffer0_o; // '<S247>/Rate Transition6'
  boolean_T RateTransition2_16_Buffer0;// '<Root>/Rate Transition2'
  boolean_T RateTransition2_17_Buffer0;// '<Root>/Rate Transition2'
  DW_SourceBlock_FLIGHT_Hexacop_T SourceBlock_p;// '<S213>/SourceBlock'
  DW_SourceBlock_FLIGHT_Hexacop_T SourceBlock_l;// '<S213>/SourceBlock'
  DW_PX4Timestamp_FLIGHT_Hexa_f_T PX4Timestamp_pna;// '<S28>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexa_j_T PX4Timestamp_k;// '<S25>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexaco_T PX4Timestamp_e;// '<S24>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexa_f_T PX4Timestamp_pn;// '<S28>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexa_j_T PX4Timestamp_p;// '<S25>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexa_j_T PX4Timestamp_j;// '<S25>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexaco_T PX4Timestamp_c;// '<S24>/PX4 Timestamp'
};

// Parameters (default storage)
struct P_FLIGHT_Hexacopter_V2_T_ {
  real_T SampleTime;                   // Variable: SampleTime
                                          //  Referenced by:
                                          //    '<S5>/Read Parameter'
                                          //    '<S5>/Read Parameter1'
                                          //    '<S5>/Read Parameter10'
                                          //    '<S5>/Read Parameter11'
                                          //    '<S5>/Read Parameter12'
                                          //    '<S5>/Read Parameter13'
                                          //    '<S5>/Read Parameter14'
                                          //    '<S5>/Read Parameter15'
                                          //    '<S5>/Read Parameter16'
                                          //    '<S5>/Read Parameter17'
                                          //    '<S5>/Read Parameter18'
                                          //    '<S5>/Read Parameter19'
                                          //    '<S5>/Read Parameter2'
                                          //    '<S5>/Read Parameter26'
                                          //    '<S5>/Read Parameter27'
                                          //    '<S5>/Read Parameter28'
                                          //    '<S5>/Read Parameter29'
                                          //    '<S5>/Read Parameter3'
                                          //    '<S5>/Read Parameter30'
                                          //    '<S5>/Read Parameter31'
                                          //    '<S5>/Read Parameter32'
                                          //    '<S5>/Read Parameter33'
                                          //    '<S5>/Read Parameter34'
                                          //    '<S5>/Read Parameter35'
                                          //    '<S5>/Read Parameter36'
                                          //    '<S5>/Read Parameter37'
                                          //    '<S5>/Read Parameter38'
                                          //    '<S5>/Read Parameter4'
                                          //    '<S5>/Read Parameter5'
                                          //    '<S5>/Read Parameter6'
                                          //    '<S5>/Read Parameter7'
                                          //    '<S5>/Read Parameter8'
                                          //    '<S5>/Read Parameter9'
                                          //    '<S5>/read_mc_rollrate_p'

  real_T SampleTime_SAS;               // Variable: SampleTime_SAS
                                          //  Referenced by:
                                          //    '<S12>/Read Parameter1'
                                          //    '<S12>/Read Parameter13'
                                          //    '<S12>/Read Parameter2'
                                          //    '<S12>/Read Parameter3'
                                          //    '<S12>/Read Parameter4'
                                          //    '<S12>/Read Parameter5'

  real32_T MAX_CONTROL_ANGLE_PITCH;    // Variable: MAX_CONTROL_ANGLE_PITCH
                                          //  Referenced by: '<S4>/Gain5'

  real32_T MAX_CONTROL_ANGLE_RATE_Y;   // Variable: MAX_CONTROL_ANGLE_RATE_Y
                                          //  Referenced by: '<S4>/Gain6'

  real32_T MAX_CONTROL_ANGLE_ROLL;     // Variable: MAX_CONTROL_ANGLE_ROLL
                                          //  Referenced by: '<S4>/Gain4'

  real32_T MAX_CONTROL_VELOCITY_XY;    // Variable: MAX_CONTROL_VELOCITY_XY
                                          //  Referenced by: '<S4>/Gain9'

  real32_T DiscreteDerivative2_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative2_ICPrevScale
                                 //  Referenced by: '<S405>/UD'

  real32_T DiscreteDerivative2_ICPrevSca_k;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_k
                                 //  Referenced by: '<S350>/UD'

  real32_T DiscreteDerivative2_ICPrevSca_f;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_f
                                 //  Referenced by: '<S460>/UD'

  real32_T DiscreteDerivative2_ICPrevSca_e;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_e
                                 //  Referenced by: '<S229>/UD'

  real32_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S227>/UD'

  real32_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: '<S228>/UD'

  real32_T DiscreteDerivative3_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative3_ICPrevScale
                                 //  Referenced by: '<S230>/UD'

  real32_T PIDController_InitialConditionF;
                              // Mask Parameter: PIDController_InitialConditionF
                                 //  Referenced by: '<S83>/Filter'

  real32_T pid_ctrl_rollrate_InitialCondit;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCondit
                                 //  Referenced by: '<S443>/Integrator'

  real32_T pid_ctrl_rollrate_InitialCond_l;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCond_l
                                 //  Referenced by: '<S388>/Integrator'

  real32_T pid_ctrl_rollrate_InitialCond_p;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCond_p
                                 //  Referenced by: '<S498>/Integrator'

  real32_T PIDController_InitialConditio_d;
                              // Mask Parameter: PIDController_InitialConditio_d
                                 //  Referenced by: '<S88>/Integrator'

  real32_T PIDController_LowerIntegratorSa;
                              // Mask Parameter: PIDController_LowerIntegratorSa
                                 //  Referenced by: '<S88>/Integrator'

  real32_T PIDController_LowerSaturationLi;
                              // Mask Parameter: PIDController_LowerSaturationLi
                                 //  Referenced by:
                                 //    '<S95>/Saturation'
                                 //    '<S80>/DeadZone'

  real32_T PIDController_UpperIntegratorSa;
                              // Mask Parameter: PIDController_UpperIntegratorSa
                                 //  Referenced by: '<S88>/Integrator'

  real32_T PIDController_UpperSaturationLi;
                              // Mask Parameter: PIDController_UpperSaturationLi
                                 //  Referenced by:
                                 //    '<S95>/Saturation'
                                 //    '<S80>/DeadZone'

  uint16_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S11>/Constant'

  uint16_T CompareToConstant_const_a;
                                    // Mask Parameter: CompareToConstant_const_a
                                       //  Referenced by: '<S15>/Constant'

  uint16_T CompareToConstant1_const; // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: '<S43>/Constant'

  uint16_T CompareToConstant2_const; // Mask Parameter: CompareToConstant2_const
                                        //  Referenced by: '<S44>/Constant'

  uint16_T CompareToConstant3_const; // Mask Parameter: CompareToConstant3_const
                                        //  Referenced by: '<S45>/Constant'

  uint16_T CompareToConstant_const_o;
                                    // Mask Parameter: CompareToConstant_const_o
                                       //  Referenced by: '<S226>/Constant'

  uint16_T CompareToConstant_const_j;
                                    // Mask Parameter: CompareToConstant_const_j
                                       //  Referenced by: '<S240>/Constant'

  uint16_T CompareToConstant1_const_p;
                                   // Mask Parameter: CompareToConstant1_const_p
                                      //  Referenced by: '<S241>/Constant'

  uint16_T CompareToConstant2_const_p;
                                   // Mask Parameter: CompareToConstant2_const_p
                                      //  Referenced by: '<S242>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0;// Computed Parameter: Out1_Y0
                                            //  Referenced by: '<S221>/Out1'

  px4_Bus_vehicle_local_position Constant_Value;// Computed Parameter: Constant_Value
                                                   //  Referenced by: '<S215>/Constant'

  px4_Bus_vehicle_attitude_smc_setpoint Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                            //  Referenced by: '<S37>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0_c;  // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S224>/Out1'

  px4_Bus_vehicle_odometry Constant_Value_j;// Computed Parameter: Constant_Value_j
                                               //  Referenced by: '<S223>/Constant'

  px4_Bus_actuator_motors Constant_Value_e;// Computed Parameter: Constant_Value_e
                                              //  Referenced by: '<S39>/Constant'

  px4_Bus_input_rc Out1_Y0_h;          // Computed Parameter: Out1_Y0_h
                                          //  Referenced by: '<S209>/Out1'

  px4_Bus_input_rc Constant_Value_l;   // Computed Parameter: Constant_Value_l
                                          //  Referenced by: '<S208>/Constant'

  px4_Bus_vehicle_status Out1_Y0_e;    // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S220>/Out1'

  px4_Bus_vehicle_status Constant_Value_k;// Computed Parameter: Constant_Value_k
                                             //  Referenced by: '<S214>/Constant'

  px4_Bus_vehicle_local_position_setpoint Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                              //  Referenced by: '<S41>/Constant'

  px4_Bus_vehicle_attitude_setpoint Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                        //  Referenced by: '<S33>/Constant'

  px4_Bus_vehicle_angular_velocity Out1_Y0_a;// Computed Parameter: Out1_Y0_a
                                                //  Referenced by: '<S211>/Out1'

  px4_Bus_vehicle_angular_velocity Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                       //  Referenced by: '<S210>/Constant'

  px4_Bus_vehicle_rates_setpoint Constant_Value_ek;// Computed Parameter: Constant_Value_ek
                                                      //  Referenced by: '<S35>/Constant'

  px4_Bus_actuator_controls_status Constant_Value_l5;// Computed Parameter: Constant_Value_l5
                                                        //  Referenced by: '<S31>/Constant'

  px4_Bus_actuator_armed Out1_Y0_p;    // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S219>/Out1'

  px4_Bus_actuator_armed Out1_Y0_g;    // Computed Parameter: Out1_Y0_g
                                          //  Referenced by: '<S222>/Out1'

  px4_Bus_actuator_armed Constant_Value_f;// Computed Parameter: Constant_Value_f
                                             //  Referenced by: '<S213>/Constant'

  px4_Bus_actuator_armed Constant_Value_a;// Computed Parameter: Constant_Value_a
                                             //  Referenced by: '<S216>/Constant'

  real_T Constant1_Value;              // Expression: 100
                                          //  Referenced by: '<S12>/Constant1'

  real_T Constant2_Value;              // Expression: 100
                                          //  Referenced by: '<S12>/Constant2'

  real_T Constant3_Value;              // Expression: 100
                                          //  Referenced by: '<S12>/Constant3'

  real_T Constant4_Value;              // Expression: 100
                                          //  Referenced by: '<S12>/Constant4'

  real_T Constant5_Value;              // Expression: 100
                                          //  Referenced by: '<S12>/Constant5'

  real_T Constant_Value_hs;            // Expression: 100
                                          //  Referenced by: '<S12>/Constant'

  real_T Gain_Gain;                    // Expression: 0.01
                                          //  Referenced by: '<S16>/Gain'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<S16>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S16>/Saturation'

  real_T Gain_Gain_l;                  // Expression: 0.01
                                          //  Referenced by: '<S17>/Gain'

  real_T Saturation_UpperSat_f;        // Expression: 1
                                          //  Referenced by: '<S17>/Saturation'

  real_T Saturation_LowerSat_a;        // Expression: 0
                                          //  Referenced by: '<S17>/Saturation'

  real_T Gain_Gain_e;                  // Expression: 0.01
                                          //  Referenced by: '<S18>/Gain'

  real_T Saturation_UpperSat_e;        // Expression: 1
                                          //  Referenced by: '<S18>/Saturation'

  real_T Saturation_LowerSat_m;        // Expression: 0
                                          //  Referenced by: '<S18>/Saturation'

  real_T Gain_Gain_n;                  // Expression: 0.01
                                          //  Referenced by: '<S19>/Gain'

  real_T Saturation_UpperSat_a;        // Expression: 1
                                          //  Referenced by: '<S19>/Saturation'

  real_T Saturation_LowerSat_d;        // Expression: 0
                                          //  Referenced by: '<S19>/Saturation'

  real_T Gain_Gain_g;                  // Expression: 0.01
                                          //  Referenced by: '<S20>/Gain'

  real_T Saturation_UpperSat_en;       // Expression: 1
                                          //  Referenced by: '<S20>/Saturation'

  real_T Saturation_LowerSat_o;        // Expression: 0
                                          //  Referenced by: '<S20>/Saturation'

  real_T Gain_Gain_f;                  // Expression: 0.01
                                          //  Referenced by: '<S21>/Gain'

  real_T Saturation_UpperSat_k;        // Expression: 1
                                          //  Referenced by: '<S21>/Saturation'

  real_T Saturation_LowerSat_k;        // Expression: 0
                                          //  Referenced by: '<S21>/Saturation'

  real_T Constant_Value_gr;            // Expression: 1
                                          //  Referenced by: '<S225>/Constant'

  real_T Constant1_Value_f;            // Expression: 1
                                          //  Referenced by: '<S225>/Constant1'

  real_T Constant2_Value_n;            // Expression: 1
                                          //  Referenced by: '<S225>/Constant2'

  real_T Constant_Value_k3;            // Expression: 1094
                                          //  Referenced by: '<S4>/Constant'

  real_T Gain_Gain_b;                  // Expression: 1/800
                                          //  Referenced by: '<S4>/Gain'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S10>/Gain1'

  real32_T Gain_Gain_o;                // Computed Parameter: Gain_Gain_o
                                          //  Referenced by: '<S10>/Gain'

  real32_T Constant1_Value_h;          // Computed Parameter: Constant1_Value_h
                                          //  Referenced by: '<S78>/Constant1'

  real32_T RateTransition4_InitialConditio;
                          // Computed Parameter: RateTransition4_InitialConditio
                             //  Referenced by: '<S10>/Rate Transition4'

  real32_T RateTransition3_InitialConditio;
                          // Computed Parameter: RateTransition3_InitialConditio
                             //  Referenced by: '<S9>/Rate Transition3'

  real32_T RateTransition_InitialCondition;
                          // Computed Parameter: RateTransition_InitialCondition
                             //  Referenced by: '<S246>/Rate Transition'

  real32_T RateTransition4_InitialCondit_l;
                          // Computed Parameter: RateTransition4_InitialCondit_l
                             //  Referenced by: '<S246>/Rate Transition4'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S443>/Integrator'

  real32_T RateTransition2_InitialConditio;
                          // Computed Parameter: RateTransition2_InitialConditio
                             //  Referenced by: '<S246>/Rate Transition2'

  real32_T UnitDelay1_InitialCondition;
                              // Computed Parameter: UnitDelay1_InitialCondition
                                 //  Referenced by: '<S408>/Unit Delay1'

  real32_T RateTransition3_InitialCondit_o;
                          // Computed Parameter: RateTransition3_InitialCondit_o
                             //  Referenced by: '<S246>/Rate Transition3'

  real32_T tau_Gain;                   // Computed Parameter: tau_Gain
                                          //  Referenced by: '<S408>/tau'

  real32_T Bias_Bias;                  // Computed Parameter: Bias_Bias
                                          //  Referenced by: '<S409>/Bias'

  real32_T Gain_Gain_f5;               // Computed Parameter: Gain_Gain_f5
                                          //  Referenced by: '<S409>/Gain'

  real32_T TSamp_WtEt;                 // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S405>/TSamp'

  real32_T RateTransition_InitialConditi_n;
                          // Computed Parameter: RateTransition_InitialConditi_n
                             //  Referenced by: '<S245>/Rate Transition'

  real32_T RateTransition4_InitialCondit_d;
                          // Computed Parameter: RateTransition4_InitialCondit_d
                             //  Referenced by: '<S245>/Rate Transition4'

  real32_T Integrator_gainval_d;     // Computed Parameter: Integrator_gainval_d
                                        //  Referenced by: '<S388>/Integrator'

  real32_T RateTransition2_InitialCondit_p;
                          // Computed Parameter: RateTransition2_InitialCondit_p
                             //  Referenced by: '<S245>/Rate Transition2'

  real32_T UnitDelay1_InitialCondition_h;
                            // Computed Parameter: UnitDelay1_InitialCondition_h
                               //  Referenced by: '<S353>/Unit Delay1'

  real32_T RateTransition3_InitialCondit_m;
                          // Computed Parameter: RateTransition3_InitialCondit_m
                             //  Referenced by: '<S245>/Rate Transition3'

  real32_T tau_Gain_d;                 // Computed Parameter: tau_Gain_d
                                          //  Referenced by: '<S353>/tau'

  real32_T Bias_Bias_o;                // Computed Parameter: Bias_Bias_o
                                          //  Referenced by: '<S354>/Bias'

  real32_T Gain_Gain_bi;               // Computed Parameter: Gain_Gain_bi
                                          //  Referenced by: '<S354>/Gain'

  real32_T TSamp_WtEt_g;               // Computed Parameter: TSamp_WtEt_g
                                          //  Referenced by: '<S350>/TSamp'

  real32_T RateTransition_InitialConditi_c;
                          // Computed Parameter: RateTransition_InitialConditi_c
                             //  Referenced by: '<S10>/Rate Transition'

  real32_T RateTransition1_InitialConditio;
                          // Computed Parameter: RateTransition1_InitialConditio
                             //  Referenced by: '<S10>/Rate Transition1'

  real32_T RateTransition_InitialConditi_m;
                          // Computed Parameter: RateTransition_InitialConditi_m
                             //  Referenced by: '<S247>/Rate Transition'

  real32_T RateTransition4_InitialCondit_a;
                          // Computed Parameter: RateTransition4_InitialCondit_a
                             //  Referenced by: '<S247>/Rate Transition4'

  real32_T Integrator_gainval_b;     // Computed Parameter: Integrator_gainval_b
                                        //  Referenced by: '<S498>/Integrator'

  real32_T RateTransition2_InitialCondit_d;
                          // Computed Parameter: RateTransition2_InitialCondit_d
                             //  Referenced by: '<S247>/Rate Transition2'

  real32_T UnitDelay1_InitialCondition_c;
                            // Computed Parameter: UnitDelay1_InitialCondition_c
                               //  Referenced by: '<S463>/Unit Delay1'

  real32_T RateTransition3_InitialCondi_o5;
                          // Computed Parameter: RateTransition3_InitialCondi_o5
                             //  Referenced by: '<S247>/Rate Transition3'

  real32_T tau_Gain_m;                 // Computed Parameter: tau_Gain_m
                                          //  Referenced by: '<S463>/tau'

  real32_T Bias_Bias_g;                // Computed Parameter: Bias_Bias_g
                                          //  Referenced by: '<S464>/Bias'

  real32_T Gain_Gain_a;                // Computed Parameter: Gain_Gain_a
                                          //  Referenced by: '<S464>/Gain'

  real32_T TSamp_WtEt_m;               // Computed Parameter: TSamp_WtEt_m
                                          //  Referenced by: '<S460>/TSamp'

  real32_T Constant_Value_ew;          // Computed Parameter: Constant_Value_ew
                                          //  Referenced by: '<S23>/Constant'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S23>/Gain'

  real32_T Constant_Value_b;           // Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<S16>/Constant'

  real32_T Constant_Value_lg;          // Computed Parameter: Constant_Value_lg
                                          //  Referenced by: '<S17>/Constant'

  real32_T Constant_Value_n;           // Computed Parameter: Constant_Value_n
                                          //  Referenced by: '<S18>/Constant'

  real32_T Constant_Value_e3;          // Computed Parameter: Constant_Value_e3
                                          //  Referenced by: '<S19>/Constant'

  real32_T Constant_Value_d;           // Computed Parameter: Constant_Value_d
                                          //  Referenced by: '<S20>/Constant'

  real32_T Constant_Value_lv;          // Computed Parameter: Constant_Value_lv
                                          //  Referenced by: '<S21>/Constant'

  real32_T Bias1_Bias;                 // Computed Parameter: Bias1_Bias
                                          //  Referenced by: '<S464>/Bias1'

  real32_T Gain1_Gain_d;               // Computed Parameter: Gain1_Gain_d
                                          //  Referenced by: '<S463>/Gain1'

  real32_T UnitDelay2_InitialCondition;
                              // Computed Parameter: UnitDelay2_InitialCondition
                                 //  Referenced by: '<S463>/Unit Delay2'

  real32_T RateTransition1_InitialCondit_d;
                          // Computed Parameter: RateTransition1_InitialCondit_d
                             //  Referenced by: '<S247>/Rate Transition1'

  real32_T Bias1_Bias_k;               // Computed Parameter: Bias1_Bias_k
                                          //  Referenced by: '<S354>/Bias1'

  real32_T Gain1_Gain_m;               // Computed Parameter: Gain1_Gain_m
                                          //  Referenced by: '<S353>/Gain1'

  real32_T UnitDelay2_InitialCondition_b;
                            // Computed Parameter: UnitDelay2_InitialCondition_b
                               //  Referenced by: '<S353>/Unit Delay2'

  real32_T RateTransition1_InitialCondit_f;
                          // Computed Parameter: RateTransition1_InitialCondit_f
                             //  Referenced by: '<S245>/Rate Transition1'

  real32_T Bias1_Bias_a;               // Computed Parameter: Bias1_Bias_a
                                          //  Referenced by: '<S409>/Bias1'

  real32_T Gain1_Gain_i;               // Computed Parameter: Gain1_Gain_i
                                          //  Referenced by: '<S408>/Gain1'

  real32_T UnitDelay2_InitialCondition_e;
                            // Computed Parameter: UnitDelay2_InitialCondition_e
                               //  Referenced by: '<S408>/Unit Delay2'

  real32_T RateTransition1_InitialCondit_p;
                          // Computed Parameter: RateTransition1_InitialCondit_p
                             //  Referenced by: '<S246>/Rate Transition1'

  real32_T Gain_Gain_az;               // Computed Parameter: Gain_Gain_az
                                          //  Referenced by: '<S52>/Gain'

  real32_T Constant3_Value_h;          // Computed Parameter: Constant3_Value_h
                                          //  Referenced by: '<S4>/Constant3'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<S4>/Gain3'

  real32_T DeadZone_Start;             // Computed Parameter: DeadZone_Start
                                          //  Referenced by: '<S4>/Dead Zone'

  real32_T DeadZone_End;               // Computed Parameter: DeadZone_End
                                          //  Referenced by: '<S4>/Dead Zone'

  real32_T Saturation3_UpperSat;     // Computed Parameter: Saturation3_UpperSat
                                        //  Referenced by: '<S4>/Saturation3'

  real32_T Saturation3_LowerSat;     // Computed Parameter: Saturation3_LowerSat
                                        //  Referenced by: '<S4>/Saturation3'

  real32_T Constant2_Value_e;          // Computed Parameter: Constant2_Value_e
                                          //  Referenced by: '<S4>/Constant2'

  real32_T Gain1_Gain_f;               // Computed Parameter: Gain1_Gain_f
                                          //  Referenced by: '<S4>/Gain1'

  real32_T DeadZone1_Start;            // Computed Parameter: DeadZone1_Start
                                          //  Referenced by: '<S4>/Dead Zone1'

  real32_T DeadZone1_End;              // Computed Parameter: DeadZone1_End
                                          //  Referenced by: '<S4>/Dead Zone1'

  real32_T Saturation2_UpperSat;     // Computed Parameter: Saturation2_UpperSat
                                        //  Referenced by: '<S4>/Saturation2'

  real32_T Saturation2_LowerSat;     // Computed Parameter: Saturation2_LowerSat
                                        //  Referenced by: '<S4>/Saturation2'

  real32_T Constant1_Value_c;          // Computed Parameter: Constant1_Value_c
                                          //  Referenced by: '<S4>/Constant1'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S4>/Gain2'

  real32_T DeadZone2_Start;            // Computed Parameter: DeadZone2_Start
                                          //  Referenced by: '<S4>/Dead Zone2'

  real32_T DeadZone2_End;              // Computed Parameter: DeadZone2_End
                                          //  Referenced by: '<S4>/Dead Zone2'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S4>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S4>/Saturation1'

  real32_T DeadZone3_Start;            // Computed Parameter: DeadZone3_Start
                                          //  Referenced by: '<S4>/Dead Zone3'

  real32_T DeadZone3_End;              // Computed Parameter: DeadZone3_End
                                          //  Referenced by: '<S4>/Dead Zone3'

  real32_T Saturation_UpperSat_h;   // Computed Parameter: Saturation_UpperSat_h
                                       //  Referenced by: '<S4>/Saturation'

  real32_T Saturation_LowerSat_p;   // Computed Parameter: Saturation_LowerSat_p
                                       //  Referenced by: '<S4>/Saturation'

  real32_T DeadZone7_Start;            // Computed Parameter: DeadZone7_Start
                                          //  Referenced by: '<S4>/Dead Zone7'

  real32_T DeadZone7_End;              // Computed Parameter: DeadZone7_End
                                          //  Referenced by: '<S4>/Dead Zone7'

  real32_T Saturation10_UpperSat;   // Computed Parameter: Saturation10_UpperSat
                                       //  Referenced by: '<S4>/Saturation10'

  real32_T Saturation10_LowerSat;   // Computed Parameter: Saturation10_LowerSat
                                       //  Referenced by: '<S4>/Saturation10'

  real32_T Gain7_Gain;                 // Computed Parameter: Gain7_Gain
                                          //  Referenced by: '<S4>/Gain7'

  real32_T Gain8_Gain;                 // Computed Parameter: Gain8_Gain
                                          //  Referenced by: '<S4>/Gain8'

  real32_T Integrator_gainval_a;     // Computed Parameter: Integrator_gainval_a
                                        //  Referenced by: '<S88>/Integrator'

  real32_T Filter_gainval;             // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S83>/Filter'

  real32_T Constant4_Value_e;          // Computed Parameter: Constant4_Value_e
                                          //  Referenced by: '<S4>/Constant4'

  real32_T Saturation5_UpperSat;     // Computed Parameter: Saturation5_UpperSat
                                        //  Referenced by: '<S4>/Saturation5'

  real32_T Saturation5_LowerSat;     // Computed Parameter: Saturation5_LowerSat
                                        //  Referenced by: '<S4>/Saturation5'

  real32_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S4>/Discrete-Time Integrator'

  real32_T DiscreteTimeIntegrator_UpperSat;
                          // Computed Parameter: DiscreteTimeIntegrator_UpperSat
                             //  Referenced by: '<S4>/Discrete-Time Integrator'

  real32_T DiscreteTimeIntegrator_LowerSat;
                          // Computed Parameter: DiscreteTimeIntegrator_LowerSat
                             //  Referenced by: '<S4>/Discrete-Time Integrator'

  real32_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<S4>/Discrete-Time Integrator1'

  real32_T DiscreteTimeIntegrator1_UpperSa;
                          // Computed Parameter: DiscreteTimeIntegrator1_UpperSa
                             //  Referenced by: '<S4>/Discrete-Time Integrator1'

  real32_T DiscreteTimeIntegrator1_LowerSa;
                          // Computed Parameter: DiscreteTimeIntegrator1_LowerSa
                             //  Referenced by: '<S4>/Discrete-Time Integrator1'

  real32_T Saturation6_UpperSat;     // Computed Parameter: Saturation6_UpperSat
                                        //  Referenced by: '<S4>/Saturation6'

  real32_T Saturation6_LowerSat;     // Computed Parameter: Saturation6_LowerSat
                                        //  Referenced by: '<S4>/Saturation6'

  real32_T Gain11_Gain;                // Computed Parameter: Gain11_Gain
                                          //  Referenced by: '<S4>/Gain11'

  real32_T TSamp_WtEt_ma;              // Computed Parameter: TSamp_WtEt_ma
                                          //  Referenced by: '<S229>/TSamp'

  real32_T Gain_Gain_eb;               // Computed Parameter: Gain_Gain_eb
                                          //  Referenced by: '<S9>/Gain'

  real32_T tau_Gain_f;                 // Computed Parameter: tau_Gain_f
                                          //  Referenced by: '<S238>/tau'

  real32_T Bias_Bias_h;                // Computed Parameter: Bias_Bias_h
                                          //  Referenced by: '<S239>/Bias'

  real32_T UnitDelay_InitialCondition;
                               // Computed Parameter: UnitDelay_InitialCondition
                                  //  Referenced by: '<S238>/Unit Delay'

  real32_T TSamp_WtEt_p;               // Computed Parameter: TSamp_WtEt_p
                                          //  Referenced by: '<S227>/TSamp'

  real32_T TSamp_WtEt_l;               // Computed Parameter: TSamp_WtEt_l
                                          //  Referenced by: '<S228>/TSamp'

  real32_T TSamp_WtEt_n;               // Computed Parameter: TSamp_WtEt_n
                                          //  Referenced by: '<S230>/TSamp'

  real32_T DiscreteTimeIntegrator_gainva_o;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_o
                             //  Referenced by: '<S9>/Discrete-Time Integrator'

  real32_T DiscreteTimeIntegrator_IC;
                                // Computed Parameter: DiscreteTimeIntegrator_IC
                                   //  Referenced by: '<S9>/Discrete-Time Integrator'

  real32_T Constant1_Value_fy;         // Computed Parameter: Constant1_Value_fy
                                          //  Referenced by: '<S3>/Constant1'

  real32_T u2_Gain;                    // Computed Parameter: u2_Gain
                                          //  Referenced by: '<S27>/1//2'

  real32_T Constant_Value_i;           // Computed Parameter: Constant_Value_i
                                          //  Referenced by: '<S3>/Constant'

  real32_T Gain1_Gain_o;               // Computed Parameter: Gain1_Gain_o
                                          //  Referenced by: '<S205>/Gain1'

  real32_T Gain1_Gain_j;               // Computed Parameter: Gain1_Gain_j
                                          //  Referenced by: '<S206>/Gain1'

  real32_T Constant3_Value_m;          // Computed Parameter: Constant3_Value_m
                                          //  Referenced by: '<S3>/Constant3'

  real32_T DeadZone4_Start;            // Computed Parameter: DeadZone4_Start
                                          //  Referenced by: '<S4>/Dead Zone4'

  real32_T DeadZone4_End;              // Computed Parameter: DeadZone4_End
                                          //  Referenced by: '<S4>/Dead Zone4'

  real32_T Saturation4_UpperSat;     // Computed Parameter: Saturation4_UpperSat
                                        //  Referenced by: '<S4>/Saturation4'

  real32_T Saturation4_LowerSat;     // Computed Parameter: Saturation4_LowerSat
                                        //  Referenced by: '<S4>/Saturation4'

  real32_T Gain10_Gain;                // Computed Parameter: Gain10_Gain
                                          //  Referenced by: '<S4>/Gain10'

  real32_T DeadZone6_Start;            // Computed Parameter: DeadZone6_Start
                                          //  Referenced by: '<S4>/Dead Zone6'

  real32_T DeadZone6_End;              // Computed Parameter: DeadZone6_End
                                          //  Referenced by: '<S4>/Dead Zone6'

  real32_T Saturation9_UpperSat;     // Computed Parameter: Saturation9_UpperSat
                                        //  Referenced by: '<S4>/Saturation9'

  real32_T Saturation9_LowerSat;     // Computed Parameter: Saturation9_LowerSat
                                        //  Referenced by: '<S4>/Saturation9'

  real32_T Saturation2_UpperSat_h; // Computed Parameter: Saturation2_UpperSat_h
                                      //  Referenced by: '<S9>/Saturation2'

  real32_T Saturation2_LowerSat_i; // Computed Parameter: Saturation2_LowerSat_i
                                      //  Referenced by: '<S9>/Saturation2'

  real32_T Gain_Gain_ar;               // Computed Parameter: Gain_Gain_ar
                                          //  Referenced by: '<S239>/Gain'

  real32_T Bias1_Bias_ka;              // Computed Parameter: Bias1_Bias_ka
                                          //  Referenced by: '<S239>/Bias1'

  real32_T Clamping_zero_Value;       // Computed Parameter: Clamping_zero_Value
                                         //  Referenced by: '<S78>/Clamping_zero'

  uint16_T RateTransition_8_InitialConditi;
                          // Computed Parameter: RateTransition_8_InitialConditi
                             //  Referenced by: '<Root>/Rate Transition'

  uint16_T Constant4_Value_f[6];       // Computed Parameter: Constant4_Value_f
                                          //  Referenced by: '<S3>/Constant4'

  uint16_T Saturation_UpperSat_d;   // Computed Parameter: Saturation_UpperSat_d
                                       //  Referenced by: '<S23>/Saturation'

  uint16_T Saturation_LowerSat_d0; // Computed Parameter: Saturation_LowerSat_d0
                                      //  Referenced by: '<S23>/Saturation'

  uint16_T RateTransition_4_InitialConditi;
                          // Computed Parameter: RateTransition_4_InitialConditi
                             //  Referenced by: '<Root>/Rate Transition'

  boolean_T RateTransition6_InitialConditio;
                          // Computed Parameter: RateTransition6_InitialConditio
                             //  Referenced by: '<S246>/Rate Transition6'

  boolean_T RateTransition6_InitialCondit_l;
                          // Computed Parameter: RateTransition6_InitialCondit_l
                             //  Referenced by: '<S245>/Rate Transition6'

  boolean_T RateTransition6_InitialCondit_e;
                          // Computed Parameter: RateTransition6_InitialCondit_e
                             //  Referenced by: '<S247>/Rate Transition6'

  boolean_T RateTransition2_16_InitialCondi;
                          // Computed Parameter: RateTransition2_16_InitialCondi
                             //  Referenced by: '<Root>/Rate Transition2'

  boolean_T RateTransition2_17_InitialCondi;
                          // Computed Parameter: RateTransition2_17_InitialCondi
                             //  Referenced by: '<Root>/Rate Transition2'

  int8_T Constant_Value_kn;            // Computed Parameter: Constant_Value_kn
                                          //  Referenced by: '<S78>/Constant'

  int8_T Constant2_Value_nv;           // Computed Parameter: Constant2_Value_nv
                                          //  Referenced by: '<S78>/Constant2'

  int8_T Constant3_Value_a;            // Computed Parameter: Constant3_Value_a
                                          //  Referenced by: '<S78>/Constant3'

  int8_T Constant4_Value_fz;           // Computed Parameter: Constant4_Value_fz
                                          //  Referenced by: '<S78>/Constant4'

};

// Real-time Model Data Structure
struct tag_RTM_FLIGHT_Hexacopter_V2_T {
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

  extern P_FLIGHT_Hexacopter_V2_T FLIGHT_Hexacopter_V2_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_FLIGHT_Hexacopter_V2_T FLIGHT_Hexacopter_V2_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_FLIGHT_Hexacopter_V2_T FLIGHT_Hexacopter_V2_DW;

// External function called from main
#ifdef __cplusplus

extern "C"
{

#endif

  extern void FLIGHT_Hexacopter_V2_SetEventsForThisBaseStep(boolean_T
    *eventFlags);

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void FLIGHT_Hexacopter_V2_initialize(void);
  extern void FLIGHT_Hexacopter_V2_step0(void);
  extern void FLIGHT_Hexacopter_V2_step1(void);
  extern void FLIGHT_Hexacopter_V2_step(int_T tid);
  extern void FLIGHT_Hexacopter_V2_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_FLIGHT_Hexacopter_V2_T *const FLIGHT_Hexacopter_V2_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S13>/Add1' : Unused code path elimination
//  Block '<S13>/Constant1' : Unused code path elimination
//  Block '<S13>/Data Type Conversion' : Unused code path elimination
//  Block '<S13>/Gain2' : Unused code path elimination
//  Block '<S13>/Mixer matrix' : Unused code path elimination
//  Block '<S13>/Product1' : Unused code path elimination
//  Block '<S13>/Saturation1' : Unused code path elimination
//  Block '<S14>/Add' : Unused code path elimination
//  Block '<S14>/Constant' : Unused code path elimination
//  Block '<S14>/Gain' : Unused code path elimination
//  Block '<S208>/NOT' : Unused code path elimination
//  Block '<S210>/NOT' : Unused code path elimination
//  Block '<S213>/NOT' : Unused code path elimination
//  Block '<S214>/NOT' : Unused code path elimination
//  Block '<S215>/NOT' : Unused code path elimination
//  Block '<S216>/NOT' : Unused code path elimination
//  Block '<S223>/NOT' : Unused code path elimination
//  Block '<S217>/Signal Copy' : Unused code path elimination
//  Block '<S217>/Signal Copy1' : Unused code path elimination
//  Block '<S217>/Signal Copy2' : Unused code path elimination
//  Block '<S227>/Data Type Duplicate' : Unused code path elimination
//  Block '<S228>/Data Type Duplicate' : Unused code path elimination
//  Block '<S229>/Data Type Duplicate' : Unused code path elimination
//  Block '<S230>/Data Type Duplicate' : Unused code path elimination
//  Block '<S289>/Data Type Duplicate' : Unused code path elimination
//  Block '<S289>/Data Type Propagation' : Unused code path elimination
//  Block '<S340>/Data Type Duplicate' : Unused code path elimination
//  Block '<S340>/Data Type Propagation' : Unused code path elimination
//  Block '<S350>/Data Type Duplicate' : Unused code path elimination
//  Block '<S405>/Data Type Duplicate' : Unused code path elimination
//  Block '<S460>/Data Type Duplicate' : Unused code path elimination
//  Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S8>/Data Type Conversion9' : Eliminate redundant data type conversion
//  Block '<S225>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S245>/Rate Transition5' : Eliminated since input and output rates are identical
//  Block '<S246>/Rate Transition5' : Eliminated since input and output rates are identical
//  Block '<S247>/Rate Transition5' : Eliminated since input and output rates are identical


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
//  '<Root>' : 'FLIGHT_Hexacopter_V2'
//  '<S1>'   : 'FLIGHT_Hexacopter_V2/Actuator'
//  '<S2>'   : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)'
//  '<S3>'   : 'FLIGHT_Hexacopter_V2/Logging'
//  '<S4>'   : 'FLIGHT_Hexacopter_V2/OFP'
//  '<S5>'   : 'FLIGHT_Hexacopter_V2/Parameters_PARAMS'
//  '<S6>'   : 'FLIGHT_Hexacopter_V2/RCCommand(CMD)'
//  '<S7>'   : 'FLIGHT_Hexacopter_V2/Read_uORB(1000hz)_SENSORS1000'
//  '<S8>'   : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250'
//  '<S9>'   : 'FLIGHT_Hexacopter_V2/Roll SMC'
//  '<S10>'  : 'FLIGHT_Hexacopter_V2/SCAS'
//  '<S11>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Compare To Constant'
//  '<S12>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Fault_Injection'
//  '<S13>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Subsystem Reference'
//  '<S14>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Subsystem Reference1'
//  '<S15>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Fault_Injection/Compare To Constant'
//  '<S16>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Fault_Injection/Subsystem Reference'
//  '<S17>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Fault_Injection/Subsystem Reference1'
//  '<S18>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Fault_Injection/Subsystem Reference2'
//  '<S19>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Fault_Injection/Subsystem Reference3'
//  '<S20>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Fault_Injection/Subsystem Reference4'
//  '<S21>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Fault_Injection/Subsystem Reference5'
//  '<S22>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Subsystem Reference1/pwm_out2'
//  '<S23>'  : 'FLIGHT_Hexacopter_V2/Logging/Normalize_pwm6'
//  '<S24>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog ActuatorControlsStatus'
//  '<S25>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog VehicleAttitudeSetpoint'
//  '<S26>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog2 VehicleRatesSetpoint'
//  '<S27>'  : 'FLIGHT_Hexacopter_V2/Logging/Rotation Angles to Quaternions'
//  '<S28>'  : 'FLIGHT_Hexacopter_V2/Logging/Subsystem'
//  '<S29>'  : 'FLIGHT_Hexacopter_V2/Logging/ULog_ActuatorMotors'
//  '<S30>'  : 'FLIGHT_Hexacopter_V2/Logging/ULog_VehicleLocalPositionSetpoint'
//  '<S31>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog ActuatorControlsStatus/PX4 uORB Message'
//  '<S32>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog ActuatorControlsStatus/PX4_log_write'
//  '<S33>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog VehicleAttitudeSetpoint/PX4 uORB Message'
//  '<S34>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog VehicleAttitudeSetpoint/PX4_log_write'
//  '<S35>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog2 VehicleRatesSetpoint/PX4 uORB Message'
//  '<S36>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog2 VehicleRatesSetpoint/PX4_log_write'
//  '<S37>'  : 'FLIGHT_Hexacopter_V2/Logging/Subsystem/PX4 uORB Message'
//  '<S38>'  : 'FLIGHT_Hexacopter_V2/Logging/Subsystem/PX4 uORB Write'
//  '<S39>'  : 'FLIGHT_Hexacopter_V2/Logging/ULog_ActuatorMotors/PX4 uORB Message'
//  '<S40>'  : 'FLIGHT_Hexacopter_V2/Logging/ULog_ActuatorMotors/PX4_log_write'
//  '<S41>'  : 'FLIGHT_Hexacopter_V2/Logging/ULog_VehicleLocalPositionSetpoint/PX4 uORB Message'
//  '<S42>'  : 'FLIGHT_Hexacopter_V2/Logging/ULog_VehicleLocalPositionSetpoint/PX4_log_write'
//  '<S43>'  : 'FLIGHT_Hexacopter_V2/OFP/Compare To Constant1'
//  '<S44>'  : 'FLIGHT_Hexacopter_V2/OFP/Compare To Constant2'
//  '<S45>'  : 'FLIGHT_Hexacopter_V2/OFP/Compare To Constant3'
//  '<S46>'  : 'FLIGHT_Hexacopter_V2/OFP/MATLAB Function'
//  '<S47>'  : 'FLIGHT_Hexacopter_V2/OFP/MATLAB Function1'
//  '<S48>'  : 'FLIGHT_Hexacopter_V2/OFP/NED2Body1'
//  '<S49>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller'
//  '<S50>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude'
//  '<S51>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1'
//  '<S52>'  : 'FLIGHT_Hexacopter_V2/OFP/NED2Body1/Calculate Transformation Matrix'
//  '<S53>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Anti-windup'
//  '<S54>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/D Gain'
//  '<S55>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/External Derivative'
//  '<S56>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Filter'
//  '<S57>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Filter ICs'
//  '<S58>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/I Gain'
//  '<S59>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Ideal P Gain'
//  '<S60>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Ideal P Gain Fdbk'
//  '<S61>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Integrator'
//  '<S62>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Integrator ICs'
//  '<S63>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/N Copy'
//  '<S64>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/N Gain'
//  '<S65>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/P Copy'
//  '<S66>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Parallel P Gain'
//  '<S67>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Reset Signal'
//  '<S68>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Saturation'
//  '<S69>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Saturation Fdbk'
//  '<S70>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Sum'
//  '<S71>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Sum Fdbk'
//  '<S72>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Tracking Mode'
//  '<S73>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Tracking Mode Sum'
//  '<S74>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Tsamp - Integral'
//  '<S75>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Tsamp - Ngain'
//  '<S76>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/postSat Signal'
//  '<S77>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/preSat Signal'
//  '<S78>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S79>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S80>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S81>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/D Gain/External Parameters'
//  '<S82>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/External Derivative/Error'
//  '<S83>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S84>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S85>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/I Gain/External Parameters'
//  '<S86>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Ideal P Gain/Passthrough'
//  '<S87>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S88>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Integrator/Discrete'
//  '<S89>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Integrator ICs/Internal IC'
//  '<S90>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/N Copy/Disabled'
//  '<S91>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/N Gain/External Parameters'
//  '<S92>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/P Copy/Disabled'
//  '<S93>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Parallel P Gain/External Parameters'
//  '<S94>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Reset Signal/External Reset'
//  '<S95>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Saturation/Enabled'
//  '<S96>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Saturation Fdbk/Disabled'
//  '<S97>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Sum/Sum_PID'
//  '<S98>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Sum Fdbk/Disabled'
//  '<S99>'  : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Tracking Mode/Disabled'
//  '<S100>' : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S101>' : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S102>' : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S103>' : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/postSat Signal/Forward_Path'
//  '<S104>' : 'FLIGHT_Hexacopter_V2/OFP/PID Controller/preSat Signal/Forward_Path'
//  '<S105>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Anti-windup'
//  '<S106>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/D Gain'
//  '<S107>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/External Derivative'
//  '<S108>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Filter'
//  '<S109>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Filter ICs'
//  '<S110>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/I Gain'
//  '<S111>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Ideal P Gain'
//  '<S112>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Ideal P Gain Fdbk'
//  '<S113>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Integrator'
//  '<S114>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Integrator ICs'
//  '<S115>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/N Copy'
//  '<S116>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/N Gain'
//  '<S117>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/P Copy'
//  '<S118>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Parallel P Gain'
//  '<S119>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Reset Signal'
//  '<S120>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Saturation'
//  '<S121>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Saturation Fdbk'
//  '<S122>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Sum'
//  '<S123>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Sum Fdbk'
//  '<S124>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tracking Mode'
//  '<S125>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tracking Mode Sum'
//  '<S126>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tsamp - Integral'
//  '<S127>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tsamp - Ngain'
//  '<S128>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/postSat Signal'
//  '<S129>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/preSat Signal'
//  '<S130>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Anti-windup/Disabled'
//  '<S131>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/D Gain/Disabled'
//  '<S132>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/External Derivative/Disabled'
//  '<S133>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Filter/Disabled'
//  '<S134>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Filter ICs/Disabled'
//  '<S135>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/I Gain/Disabled'
//  '<S136>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S137>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Ideal P Gain Fdbk/Disabled'
//  '<S138>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Integrator/Disabled'
//  '<S139>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Integrator ICs/Disabled'
//  '<S140>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/N Copy/Disabled wSignal Specification'
//  '<S141>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/N Gain/Disabled'
//  '<S142>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/P Copy/Disabled'
//  '<S143>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Parallel P Gain/External Parameters'
//  '<S144>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Reset Signal/Disabled'
//  '<S145>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Saturation/Passthrough'
//  '<S146>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Saturation Fdbk/Disabled'
//  '<S147>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Sum/Passthrough_P'
//  '<S148>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Sum Fdbk/Disabled'
//  '<S149>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tracking Mode/Disabled'
//  '<S150>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S151>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S152>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S153>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/postSat Signal/Forward_Path'
//  '<S154>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/preSat Signal/Forward_Path'
//  '<S155>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Anti-windup'
//  '<S156>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/D Gain'
//  '<S157>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/External Derivative'
//  '<S158>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Filter'
//  '<S159>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Filter ICs'
//  '<S160>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/I Gain'
//  '<S161>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Ideal P Gain'
//  '<S162>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Ideal P Gain Fdbk'
//  '<S163>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Integrator'
//  '<S164>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Integrator ICs'
//  '<S165>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/N Copy'
//  '<S166>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/N Gain'
//  '<S167>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/P Copy'
//  '<S168>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Parallel P Gain'
//  '<S169>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Reset Signal'
//  '<S170>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Saturation'
//  '<S171>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Saturation Fdbk'
//  '<S172>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Sum'
//  '<S173>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Sum Fdbk'
//  '<S174>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tracking Mode'
//  '<S175>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tracking Mode Sum'
//  '<S176>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tsamp - Integral'
//  '<S177>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tsamp - Ngain'
//  '<S178>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/postSat Signal'
//  '<S179>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/preSat Signal'
//  '<S180>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Anti-windup/Disabled'
//  '<S181>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/D Gain/Disabled'
//  '<S182>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/External Derivative/Disabled'
//  '<S183>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Filter/Disabled'
//  '<S184>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Filter ICs/Disabled'
//  '<S185>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/I Gain/Disabled'
//  '<S186>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Ideal P Gain/Passthrough'
//  '<S187>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Ideal P Gain Fdbk/Disabled'
//  '<S188>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Integrator/Disabled'
//  '<S189>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Integrator ICs/Disabled'
//  '<S190>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/N Copy/Disabled wSignal Specification'
//  '<S191>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/N Gain/Disabled'
//  '<S192>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/P Copy/Disabled'
//  '<S193>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Parallel P Gain/External Parameters'
//  '<S194>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Reset Signal/Disabled'
//  '<S195>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Saturation/Passthrough'
//  '<S196>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Saturation Fdbk/Disabled'
//  '<S197>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Sum/Passthrough_P'
//  '<S198>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Sum Fdbk/Disabled'
//  '<S199>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tracking Mode/Disabled'
//  '<S200>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tracking Mode Sum/Passthrough'
//  '<S201>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tsamp - Integral/TsSignalSpecification'
//  '<S202>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tsamp - Ngain/Passthrough'
//  '<S203>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/postSat Signal/Forward_Path'
//  '<S204>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/preSat Signal/Forward_Path'
//  '<S205>' : 'FLIGHT_Hexacopter_V2/Parameters_PARAMS/Degrees to Radians'
//  '<S206>' : 'FLIGHT_Hexacopter_V2/Parameters_PARAMS/Degrees to Radians1'
//  '<S207>' : 'FLIGHT_Hexacopter_V2/Parameters_PARAMS/MATLAB Function'
//  '<S208>' : 'FLIGHT_Hexacopter_V2/RCCommand(CMD)/PX4 uORB Read'
//  '<S209>' : 'FLIGHT_Hexacopter_V2/RCCommand(CMD)/PX4 uORB Read/Enabled Subsystem'
//  '<S210>' : 'FLIGHT_Hexacopter_V2/Read_uORB(1000hz)_SENSORS1000/PX4 uORB Read1'
//  '<S211>' : 'FLIGHT_Hexacopter_V2/Read_uORB(1000hz)_SENSORS1000/PX4 uORB Read1/Enabled Subsystem'
//  '<S212>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/MATLAB Function'
//  '<S213>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read'
//  '<S214>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read1'
//  '<S215>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read2'
//  '<S216>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read3'
//  '<S217>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/Vehicle Attitude'
//  '<S218>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/quat2eul'
//  '<S219>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read/Enabled Subsystem'
//  '<S220>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read1/Enabled Subsystem'
//  '<S221>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read2/Enabled Subsystem'
//  '<S222>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read3/Enabled Subsystem'
//  '<S223>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/Vehicle Attitude/PX4 uORB Read'
//  '<S224>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'
//  '<S225>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Calc_Fx_Gx'
//  '<S226>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Compare To Constant'
//  '<S227>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Derivative'
//  '<S228>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Derivative1'
//  '<S229>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Derivative2'
//  '<S230>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Derivative3'
//  '<S231>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Varying Lowpass'
//  '<S232>' : 'FLIGHT_Hexacopter_V2/Roll SMC/MATLAB Function'
//  '<S233>' : 'FLIGHT_Hexacopter_V2/Roll SMC/MATLAB Function1'
//  '<S234>' : 'FLIGHT_Hexacopter_V2/Roll SMC/MATLAB Function2'
//  '<S235>' : 'FLIGHT_Hexacopter_V2/Roll SMC/MATLAB Function3'
//  '<S236>' : 'FLIGHT_Hexacopter_V2/Roll SMC/MATLAB Function4'
//  '<S237>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Omega_phi'
//  '<S238>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Varying Lowpass/FOS'
//  '<S239>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Varying Lowpass/FOS/Arithmetic'
//  '<S240>' : 'FLIGHT_Hexacopter_V2/SCAS/Compare To Constant'
//  '<S241>' : 'FLIGHT_Hexacopter_V2/SCAS/Compare To Constant1'
//  '<S242>' : 'FLIGHT_Hexacopter_V2/SCAS/Compare To Constant2'
//  '<S243>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3'
//  '<S244>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4'
//  '<S245>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate'
//  '<S246>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate'
//  '<S247>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate'
//  '<S248>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Anti-windup'
//  '<S249>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/D Gain'
//  '<S250>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/External Derivative'
//  '<S251>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Filter'
//  '<S252>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Filter ICs'
//  '<S253>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/I Gain'
//  '<S254>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Ideal P Gain'
//  '<S255>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Ideal P Gain Fdbk'
//  '<S256>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Integrator'
//  '<S257>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Integrator ICs'
//  '<S258>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/N Copy'
//  '<S259>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/N Gain'
//  '<S260>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/P Copy'
//  '<S261>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Parallel P Gain'
//  '<S262>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Reset Signal'
//  '<S263>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Saturation'
//  '<S264>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Saturation Fdbk'
//  '<S265>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Sum'
//  '<S266>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Sum Fdbk'
//  '<S267>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tracking Mode'
//  '<S268>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tracking Mode Sum'
//  '<S269>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tsamp - Integral'
//  '<S270>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tsamp - Ngain'
//  '<S271>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/postSat Signal'
//  '<S272>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/preSat Signal'
//  '<S273>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Anti-windup/Disabled'
//  '<S274>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/D Gain/Disabled'
//  '<S275>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/External Derivative/Disabled'
//  '<S276>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Filter/Disabled'
//  '<S277>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Filter ICs/Disabled'
//  '<S278>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/I Gain/Disabled'
//  '<S279>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Ideal P Gain/Passthrough'
//  '<S280>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S281>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Integrator/Disabled'
//  '<S282>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Integrator ICs/Disabled'
//  '<S283>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S284>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/N Gain/Disabled'
//  '<S285>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/P Copy/Disabled'
//  '<S286>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Parallel P Gain/External Parameters'
//  '<S287>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Reset Signal/Disabled'
//  '<S288>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Saturation/External'
//  '<S289>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Saturation/External/Saturation Dynamic'
//  '<S290>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Saturation Fdbk/Disabled'
//  '<S291>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Sum/Passthrough_P'
//  '<S292>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Sum Fdbk/Disabled'
//  '<S293>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tracking Mode/Disabled'
//  '<S294>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S295>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S296>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S297>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/postSat Signal/Forward_Path'
//  '<S298>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/preSat Signal/Forward_Path'
//  '<S299>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Anti-windup'
//  '<S300>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/D Gain'
//  '<S301>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/External Derivative'
//  '<S302>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Filter'
//  '<S303>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Filter ICs'
//  '<S304>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/I Gain'
//  '<S305>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Ideal P Gain'
//  '<S306>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Ideal P Gain Fdbk'
//  '<S307>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Integrator'
//  '<S308>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Integrator ICs'
//  '<S309>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/N Copy'
//  '<S310>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/N Gain'
//  '<S311>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/P Copy'
//  '<S312>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Parallel P Gain'
//  '<S313>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Reset Signal'
//  '<S314>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Saturation'
//  '<S315>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Saturation Fdbk'
//  '<S316>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Sum'
//  '<S317>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Sum Fdbk'
//  '<S318>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tracking Mode'
//  '<S319>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tracking Mode Sum'
//  '<S320>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tsamp - Integral'
//  '<S321>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tsamp - Ngain'
//  '<S322>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/postSat Signal'
//  '<S323>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/preSat Signal'
//  '<S324>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Anti-windup/Disabled'
//  '<S325>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/D Gain/Disabled'
//  '<S326>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/External Derivative/Disabled'
//  '<S327>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Filter/Disabled'
//  '<S328>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Filter ICs/Disabled'
//  '<S329>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/I Gain/Disabled'
//  '<S330>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Ideal P Gain/Passthrough'
//  '<S331>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S332>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Integrator/Disabled'
//  '<S333>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Integrator ICs/Disabled'
//  '<S334>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S335>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/N Gain/Disabled'
//  '<S336>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/P Copy/Disabled'
//  '<S337>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Parallel P Gain/External Parameters'
//  '<S338>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Reset Signal/Disabled'
//  '<S339>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Saturation/External'
//  '<S340>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Saturation/External/Saturation Dynamic'
//  '<S341>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Saturation Fdbk/Disabled'
//  '<S342>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Sum/Passthrough_P'
//  '<S343>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Sum Fdbk/Disabled'
//  '<S344>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tracking Mode/Disabled'
//  '<S345>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S346>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S347>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S348>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/postSat Signal/Forward_Path'
//  '<S349>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/preSat Signal/Forward_Path'
//  '<S350>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/Discrete Derivative2'
//  '<S351>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/Discrete Varying Lowpass2'
//  '<S352>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate'
//  '<S353>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/Discrete Varying Lowpass2/SOS1'
//  '<S354>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/Discrete Varying Lowpass2/SOS1/Arithmetic'
//  '<S355>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Anti-windup'
//  '<S356>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/D Gain'
//  '<S357>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/External Derivative'
//  '<S358>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Filter'
//  '<S359>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Filter ICs'
//  '<S360>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/I Gain'
//  '<S361>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Ideal P Gain'
//  '<S362>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Ideal P Gain Fdbk'
//  '<S363>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Integrator'
//  '<S364>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Integrator ICs'
//  '<S365>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/N Copy'
//  '<S366>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/N Gain'
//  '<S367>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/P Copy'
//  '<S368>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Parallel P Gain'
//  '<S369>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Reset Signal'
//  '<S370>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Saturation'
//  '<S371>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Saturation Fdbk'
//  '<S372>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Sum'
//  '<S373>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Sum Fdbk'
//  '<S374>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Tracking Mode'
//  '<S375>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Tracking Mode Sum'
//  '<S376>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Tsamp - Integral'
//  '<S377>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Tsamp - Ngain'
//  '<S378>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/postSat Signal'
//  '<S379>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/preSat Signal'
//  '<S380>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Anti-windup/Passthrough'
//  '<S381>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/D Gain/Disabled'
//  '<S382>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/External Derivative/Disabled'
//  '<S383>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Filter/Disabled'
//  '<S384>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Filter ICs/Disabled'
//  '<S385>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/I Gain/External Parameters'
//  '<S386>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Ideal P Gain/Passthrough'
//  '<S387>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Ideal P Gain Fdbk/Disabled'
//  '<S388>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Integrator/Discrete'
//  '<S389>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Integrator ICs/Internal IC'
//  '<S390>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/N Copy/Disabled wSignal Specification'
//  '<S391>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/N Gain/Disabled'
//  '<S392>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/P Copy/Disabled'
//  '<S393>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Parallel P Gain/External Parameters'
//  '<S394>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Reset Signal/External Reset'
//  '<S395>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Saturation/Passthrough'
//  '<S396>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Saturation Fdbk/Disabled'
//  '<S397>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Sum/Sum_PI'
//  '<S398>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Sum Fdbk/Disabled'
//  '<S399>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Tracking Mode/Disabled'
//  '<S400>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Tracking Mode Sum/Passthrough'
//  '<S401>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Tsamp - Integral/TsSignalSpecification'
//  '<S402>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Tsamp - Ngain/Passthrough'
//  '<S403>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/postSat Signal/Forward_Path'
//  '<S404>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/preSat Signal/Forward_Path'
//  '<S405>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/Discrete Derivative2'
//  '<S406>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/Discrete Varying Lowpass2'
//  '<S407>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate'
//  '<S408>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/Discrete Varying Lowpass2/SOS1'
//  '<S409>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/Discrete Varying Lowpass2/SOS1/Arithmetic'
//  '<S410>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Anti-windup'
//  '<S411>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/D Gain'
//  '<S412>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/External Derivative'
//  '<S413>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Filter'
//  '<S414>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Filter ICs'
//  '<S415>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/I Gain'
//  '<S416>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Ideal P Gain'
//  '<S417>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Ideal P Gain Fdbk'
//  '<S418>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Integrator'
//  '<S419>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Integrator ICs'
//  '<S420>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/N Copy'
//  '<S421>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/N Gain'
//  '<S422>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/P Copy'
//  '<S423>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Parallel P Gain'
//  '<S424>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Reset Signal'
//  '<S425>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Saturation'
//  '<S426>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Saturation Fdbk'
//  '<S427>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Sum'
//  '<S428>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Sum Fdbk'
//  '<S429>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Tracking Mode'
//  '<S430>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Tracking Mode Sum'
//  '<S431>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Tsamp - Integral'
//  '<S432>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Tsamp - Ngain'
//  '<S433>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/postSat Signal'
//  '<S434>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/preSat Signal'
//  '<S435>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Anti-windup/Passthrough'
//  '<S436>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/D Gain/Disabled'
//  '<S437>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/External Derivative/Disabled'
//  '<S438>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Filter/Disabled'
//  '<S439>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Filter ICs/Disabled'
//  '<S440>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/I Gain/External Parameters'
//  '<S441>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Ideal P Gain/Passthrough'
//  '<S442>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Ideal P Gain Fdbk/Disabled'
//  '<S443>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Integrator/Discrete'
//  '<S444>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Integrator ICs/Internal IC'
//  '<S445>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/N Copy/Disabled wSignal Specification'
//  '<S446>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/N Gain/Disabled'
//  '<S447>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/P Copy/Disabled'
//  '<S448>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Parallel P Gain/External Parameters'
//  '<S449>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Reset Signal/External Reset'
//  '<S450>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Saturation/Passthrough'
//  '<S451>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Saturation Fdbk/Disabled'
//  '<S452>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Sum/Sum_PI'
//  '<S453>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Sum Fdbk/Disabled'
//  '<S454>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Tracking Mode/Disabled'
//  '<S455>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Tracking Mode Sum/Passthrough'
//  '<S456>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Tsamp - Integral/TsSignalSpecification'
//  '<S457>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Tsamp - Ngain/Passthrough'
//  '<S458>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/postSat Signal/Forward_Path'
//  '<S459>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/preSat Signal/Forward_Path'
//  '<S460>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/Discrete Derivative2'
//  '<S461>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/Discrete Varying Lowpass2'
//  '<S462>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate'
//  '<S463>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/Discrete Varying Lowpass2/SOS1'
//  '<S464>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/Discrete Varying Lowpass2/SOS1/Arithmetic'
//  '<S465>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Anti-windup'
//  '<S466>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/D Gain'
//  '<S467>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/External Derivative'
//  '<S468>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Filter'
//  '<S469>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Filter ICs'
//  '<S470>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/I Gain'
//  '<S471>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Ideal P Gain'
//  '<S472>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Ideal P Gain Fdbk'
//  '<S473>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Integrator'
//  '<S474>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Integrator ICs'
//  '<S475>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/N Copy'
//  '<S476>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/N Gain'
//  '<S477>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/P Copy'
//  '<S478>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Parallel P Gain'
//  '<S479>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Reset Signal'
//  '<S480>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Saturation'
//  '<S481>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Saturation Fdbk'
//  '<S482>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Sum'
//  '<S483>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Sum Fdbk'
//  '<S484>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Tracking Mode'
//  '<S485>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Tracking Mode Sum'
//  '<S486>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Tsamp - Integral'
//  '<S487>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Tsamp - Ngain'
//  '<S488>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/postSat Signal'
//  '<S489>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/preSat Signal'
//  '<S490>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Anti-windup/Passthrough'
//  '<S491>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/D Gain/Disabled'
//  '<S492>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/External Derivative/Disabled'
//  '<S493>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Filter/Disabled'
//  '<S494>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Filter ICs/Disabled'
//  '<S495>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/I Gain/External Parameters'
//  '<S496>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Ideal P Gain/Passthrough'
//  '<S497>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Ideal P Gain Fdbk/Disabled'
//  '<S498>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Integrator/Discrete'
//  '<S499>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Integrator ICs/Internal IC'
//  '<S500>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/N Copy/Disabled wSignal Specification'
//  '<S501>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/N Gain/Disabled'
//  '<S502>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/P Copy/Disabled'
//  '<S503>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Parallel P Gain/External Parameters'
//  '<S504>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Reset Signal/External Reset'
//  '<S505>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Saturation/Passthrough'
//  '<S506>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Saturation Fdbk/Disabled'
//  '<S507>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Sum/Sum_PI'
//  '<S508>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Sum Fdbk/Disabled'
//  '<S509>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Tracking Mode/Disabled'
//  '<S510>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Tracking Mode Sum/Passthrough'
//  '<S511>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Tsamp - Integral/TsSignalSpecification'
//  '<S512>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Tsamp - Ngain/Passthrough'
//  '<S513>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/postSat Signal/Forward_Path'
//  '<S514>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/preSat Signal/Forward_Path'

#endif                                 // FLIGHT_Hexacopter_V2_h_

//
// File trailer for generated code.
//
// [EOF]
//
