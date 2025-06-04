//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_Hexacopter_V2_1.h
//
// Code generated for Simulink model 'FLIGHT_Hexacopter_V2_1'.
//
// Model version                  : 1.93
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Sun May 25 21:09:13 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef FLIGHT_Hexacopter_V2_1_h_
#define FLIGHT_Hexacopter_V2_1_h_
#include <drivers/drv_hrt.h>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "MW_PX4_PWM.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Write.h"
#include "MW_uORB_Read.h"
#include "FLIGHT_Hexacopter_V2_1_types.h"
#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/actuator_motors.h>
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

// Block signals for system '<S23>/PX4 Timestamp'
struct B_PX4Timestamp_FLIGHT_Hexacop_T {
  uint64_T PX4Timestamp;               // '<S23>/PX4 Timestamp'
};

// Block states (default storage) for system '<S23>/PX4 Timestamp'
struct DW_PX4Timestamp_FLIGHT_Hexaco_T {
  px4_internal_block_getPX4Abso_T obj; // '<S23>/PX4 Timestamp'
  boolean_T objisempty;                // '<S23>/PX4 Timestamp'
};

// Block signals for system '<S24>/PX4 Timestamp'
struct B_PX4Timestamp_FLIGHT_Hexac_l_T {
  uint64_T PX4Timestamp;               // '<S24>/PX4 Timestamp'
};

// Block states (default storage) for system '<S24>/PX4 Timestamp'
struct DW_PX4Timestamp_FLIGHT_Hexa_j_T {
  px4_internal_block_getPX4Abso_T obj; // '<S24>/PX4 Timestamp'
  boolean_T objisempty;                // '<S24>/PX4 Timestamp'
};

// Block signals for system '<S209>/SourceBlock'
struct B_SourceBlock_FLIGHT_Hexacopt_T {
  px4_Bus_actuator_armed SourceBlock_o2;// '<S209>/SourceBlock'
  boolean_T SourceBlock_o1;            // '<S209>/SourceBlock'
};

// Block states (default storage) for system '<S209>/SourceBlock'
struct DW_SourceBlock_FLIGHT_Hexacop_T {
  px4_internal_block_Subscriber_T obj; // '<S209>/SourceBlock'
  boolean_T objisempty;                // '<S209>/SourceBlock'
};

// Block signals (default storage)
struct B_FLIGHT_Hexacopter_V2_1_T {
  px4_Bus_vehicle_local_position In1;  // '<S217>/In1'
  px4_Bus_vehicle_local_position r;
  px4_Bus_vehicle_odometry In1_b;      // '<S220>/In1'
  px4_Bus_vehicle_odometry r1;
  px4_Bus_input_rc In1_p;              // '<S205>/In1'
  px4_Bus_actuator_motors BusAssignment;// '<S27>/Bus Assignment'
  px4_Bus_input_rc r2;
  px4_Bus_vehicle_status In1_m;        // '<S216>/In1'
  px4_Bus_vehicle_status r3;
  px4_Bus_vehicle_local_position_setpoint BusAssignment_g;// '<S28>/Bus Assignment' 
  px4_Bus_vehicle_attitude_setpoint BusAssignment_f;// '<S24>/Bus Assignment'
  px4_Bus_vehicle_rates_setpoint BusAssignment_e;// '<S25>/Bus Assignment'
  px4_Bus_vehicle_angular_velocity In1_k;// '<S207>/In1'
  px4_Bus_vehicle_angular_velocity r4;
  real32_T CreateDiagonalMatrix[9];    // '<S439>/Create Diagonal Matrix'
  px4_Bus_actuator_controls_status BusAssignment_j;// '<S23>/Bus Assignment'
  px4_Bus_actuator_armed In1_d;        // '<S218>/In1'
  px4_Bus_actuator_armed In1_e;        // '<S215>/In1'
  uint16_T pwmValue[8];
  real32_T U[3];
  real32_T omega_phi[3];               // '<S225>/Omega_phi'
  real32_T G1[3];                      // '<S225>/MATLAB Function1'
  real32_T TSamp_p[3];                 // '<S442>/TSamp'
  real32_T u[3];                       // '<S225>/MATLAB Function2'
  real32_T b_A[3];
  uint16_T DataTypeConversion7[6];     // '<S11>/Data Type Conversion7'
  real_T reletive_time_sec;
  real_T peak_angle_rad;
  real_T out_roll;                     // '<S4>/MATLAB Function1'
  real_T out_pitch;                    // '<S4>/MATLAB Function1'
  real_T out_yawrate;                  // '<S4>/MATLAB Function1'
  real_T u0;
  uint64_T rtb_PX4Timestamp_m;
  real32_T RateTransition4;            // '<S9>/Rate Transition4'
  real32_T RateTransition3;            // '<S9>/Rate Transition3'
  real32_T RateTransition;             // '<S224>/Rate Transition'
  real32_T RateTransition4_a;          // '<S224>/Rate Transition4'
  real32_T RateTransition2;            // '<S224>/Rate Transition2'
  real32_T RateTransition3_b;          // '<S224>/Rate Transition3'
  real32_T RateTransition_e;           // '<S223>/Rate Transition'
  real32_T RateTransition4_b;          // '<S223>/Rate Transition4'
  real32_T RateTransition2_b;          // '<S223>/Rate Transition2'
  real32_T RateTransition3_be;         // '<S223>/Rate Transition3'
  real32_T RateTransition_j;           // '<S9>/Rate Transition'
  real32_T RateTransition1;            // '<S9>/Rate Transition1'
  real32_T RateTransition_f;           // '<S226>/Rate Transition'
  real32_T RateTransition4_ar;         // '<S226>/Rate Transition4'
  real32_T RateTransition2_d;          // '<S226>/Rate Transition2'
  real32_T RateTransition3_e;          // '<S226>/Rate Transition3'
  real32_T RateTransition1_c;          // '<S226>/Rate Transition1'
  real32_T RateTransition1_d;          // '<S223>/Rate Transition1'
  real32_T RateTransition1_o;          // '<S224>/Rate Transition1'
  real32_T absx;
  real32_T ParamStep;
  real32_T ParamStep_c;
  real32_T ParamStep_k;
  real32_T ParamStep_cx;
  real32_T ParamStep_b;
  real32_T Integrator_p;               // '<S84>/Integrator'
  real32_T IProdOut_g;                 // '<S81>/IProd Out'
  real32_T Gain7;                      // '<S4>/Gain7'
  real32_T Gain4;                      // '<S4>/Gain4'
  real32_T Gain5;                      // '<S4>/Gain5'
  real32_T Gain6;                      // '<S4>/Gain6'
  real32_T NProdOut;                   // '<S87>/NProd Out'
  real32_T DeadZone;                   // '<S76>/DeadZone'
  real32_T Saturation5;                // '<S4>/Saturation5'
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
  real32_T rtb_Sum7_idx_1;
  real32_T rtb_MatrixConcatenate_idx_3;
  real32_T rtb_MatrixConcatenate_idx_0;
  real32_T anrm;
  real32_T roll;                       // '<S224>/Sum1'
  real32_T p;                          // '<S388>/Gain'
  real32_T q;                          // '<S388>/Product2'
  real32_T r_c;                        // '<S388>/Bias'
  real32_T d;                          // '<S388>/Add1'
  real32_T Sum5_nz;                    // '<S224>/Sum5'
  real32_T TSamp;                      // '<S384>/TSamp'
  real32_T Switch;                     // '<S2>/Switch'
  real32_T roll_h;                     // '<S223>/Sum1'
  real32_T p_e;                        // '<S333>/Gain'
  real32_T q_e;                        // '<S333>/Product2'
  real32_T r_a;                        // '<S333>/Bias'
  real32_T d_m;                        // '<S333>/Add1'
  real32_T roll_l;                     // '<S226>/Sum1'
  real32_T TSamp_c;                    // '<S329>/TSamp'
  int32_T exponent;
  int32_T ic;
  int32_T b_ic;
  int32_T i;
  int32_T ParamStep_f;
  int32_T ParamStep_g;
  int32_T ParamStep_g1;
  int32_T ParamStep_m;
  int32_T ParamStep_n;
  int32_T ParamStep_p;
  uint16_T rc_ctrl_switch;             // '<Root>/Rate Transition'
  uint16_T rc_inject_failure;          // '<Root>/Rate Transition'
  boolean_T RateTransition6;           // '<S224>/Rate Transition6'
  boolean_T RateTransition6_a;         // '<S223>/Rate Transition6'
  boolean_T RateTransition6_o;         // '<S226>/Rate Transition6'
  boolean_T VehicleStatus_flag_armed;  // '<Root>/Rate Transition2'
  boolean_T VehicleStatus_flag_kill;   // '<Root>/Rate Transition2'
  B_SourceBlock_FLIGHT_Hexacopt_T SourceBlock_p;// '<S209>/SourceBlock'
  B_SourceBlock_FLIGHT_Hexacopt_T SourceBlock_l;// '<S209>/SourceBlock'
  B_PX4Timestamp_FLIGHT_Hexac_l_T PX4Timestamp_k;// '<S24>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexacop_T PX4Timestamp_e;// '<S23>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexac_l_T PX4Timestamp_p;// '<S24>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexac_l_T PX4Timestamp_j;// '<S24>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexacop_T PX4Timestamp_c;// '<S23>/PX4 Timestamp'
};

// Block states (default storage) for system '<Root>'
struct DW_FLIGHT_Hexacopter_V2_1_T {
  px4_internal_block_ParameterU_T obj; // '<S5>/read_mc_rollrate_p'
  px4_internal_block_ParameterU_T obj_a;// '<S5>/Read Parameter9'
  px4_internal_block_ParameterU_T obj_f;// '<S5>/Read Parameter8'
  px4_internal_block_ParameterU_T obj_fj;// '<S5>/Read Parameter7'
  px4_internal_block_ParameterU_T obj_p;// '<S5>/Read Parameter6'
  px4_internal_block_ParameterU_T obj_i;// '<S5>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_c;// '<S5>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_b;// '<S5>/Read Parameter33'
  px4_internal_block_ParameterU_T obj_l;// '<S5>/Read Parameter32'
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
  px4_internal_block_ParameterU_T obj_ic5;// '<S11>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_jg;// '<S11>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_h;// '<S11>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_ps;// '<S11>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_o;// '<S11>/Read Parameter13'
  px4_internal_block_ParameterU_T obj_aw;// '<S11>/Read Parameter1'
  px4_internal_block_getPX4Abso_T obj_bqr;// '<S4>/PX4 Timestamp'
  px4_internal_block_getPX4Abso_T obj_a5;// '<S3>/PX4 Timestamp'
  px4_internal_block_Subscriber_T obj_i4;// '<S219>/SourceBlock'
  px4_internal_block_Subscriber_T obj_lk;// '<S211>/SourceBlock'
  px4_internal_block_Subscriber_T obj_ab;// '<S210>/SourceBlock'
  px4_internal_block_Subscriber_T obj_mh;// '<S206>/SourceBlock'
  px4_internal_block_Subscriber_T obj_nt;// '<S204>/SourceBlock'
  px4_internal_block_PWM_FLIGHT_T obj_md;// '<S1>/PX4 PWM Output'
  px4_internal_block_Publisher__T obj_pm;// '<S38>/SinkBlock'
  px4_internal_block_Publisher__T obj_nf;// '<S36>/SinkBlock'
  px4_internal_block_Publisher__T obj_mp;// '<S34>/SinkBlock'
  px4_internal_block_Publisher__T obj_m1;// '<S32>/SinkBlock'
  px4_internal_block_Publisher__T obj_fe;// '<S30>/SinkBlock'
  real_T start_time_usec;              // '<S4>/MATLAB Function1'
  real32_T Integrator_DSTATE;          // '<S422>/Integrator'
  real32_T UnitDelay1_DSTATE;          // '<S387>/Unit Delay1'
  real32_T UD_DSTATE;                  // '<S384>/UD'
  real32_T Integrator_DSTATE_c;        // '<S367>/Integrator'
  real32_T UnitDelay1_DSTATE_k;        // '<S332>/Unit Delay1'
  real32_T UD_DSTATE_o;                // '<S329>/UD'
  real32_T Integrator_DSTATE_o;        // '<S488>/Integrator'
  real32_T UnitDelay1_DSTATE_kh;       // '<S453>/Unit Delay1'
  real32_T UD_DSTATE_k;                // '<S450>/UD'
  real32_T UnitDelay2_DSTATE;          // '<S453>/Unit Delay2'
  real32_T UnitDelay2_DSTATE_l;        // '<S332>/Unit Delay2'
  real32_T UnitDelay2_DSTATE_h;        // '<S387>/Unit Delay2'
  real32_T Integrator_DSTATE_i;        // '<S84>/Integrator'
  real32_T Filter_DSTATE;              // '<S79>/Filter'
  real32_T DiscreteTimeIntegrator_DSTATE;// '<S4>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator1_DSTATE;// '<S4>/Discrete-Time Integrator1'
  real32_T UD_DSTATE_c[3];             // '<S442>/UD'
  real32_T UD_DSTATE_a;                // '<S440>/UD'
  real32_T UD_DSTATE_e;                // '<S443>/UD'
  real32_T DiscreteTimeIntegrator_DSTATE_d;// '<S225>/Discrete-Time Integrator'
  real32_T RateTransition4_Buffer0;    // '<S9>/Rate Transition4'
  real32_T RateTransition3_Buffer0;    // '<S9>/Rate Transition3'
  real32_T RateTransition_Buffer0;     // '<S224>/Rate Transition'
  real32_T RateTransition4_Buffer0_e;  // '<S224>/Rate Transition4'
  real32_T RateTransition2_Buffer0;    // '<S224>/Rate Transition2'
  real32_T RateTransition3_Buffer0_e;  // '<S224>/Rate Transition3'
  real32_T RateTransition_Buffer0_c;   // '<S223>/Rate Transition'
  real32_T RateTransition4_Buffer0_k;  // '<S223>/Rate Transition4'
  real32_T RateTransition2_Buffer0_l;  // '<S223>/Rate Transition2'
  real32_T RateTransition3_Buffer0_p;  // '<S223>/Rate Transition3'
  real32_T RateTransition_Buffer0_h;   // '<S9>/Rate Transition'
  real32_T RateTransition1_Buffer0;    // '<S9>/Rate Transition1'
  real32_T RateTransition_Buffer0_hv;  // '<S226>/Rate Transition'
  real32_T RateTransition4_Buffer0_c;  // '<S226>/Rate Transition4'
  real32_T RateTransition2_Buffer0_d;  // '<S226>/Rate Transition2'
  real32_T RateTransition3_Buffer0_d;  // '<S226>/Rate Transition3'
  real32_T RateTransition1_Buffer0_m;  // '<S226>/Rate Transition1'
  real32_T RateTransition1_Buffer0_l;  // '<S223>/Rate Transition1'
  real32_T RateTransition1_Buffer0_l4; // '<S224>/Rate Transition1'
  real32_T RateTransition2_Buffer[3];  // '<S9>/Rate Transition2'
  real32_T RateTransition_Buffer;      // '<S3>/Rate Transition'
  uint16_T RateTransition_8_Buffer0;   // '<Root>/Rate Transition'
  uint16_T RateTransition_4_Buffer0;   // '<Root>/Rate Transition'
  int8_T Integrator_PrevResetState;    // '<S422>/Integrator'
  int8_T Integrator_PrevResetState_h;  // '<S367>/Integrator'
  int8_T Integrator_PrevResetState_hd; // '<S488>/Integrator'
  int8_T Integrator_PrevResetState_e;  // '<S84>/Integrator'
  int8_T Filter_PrevResetState;        // '<S79>/Filter'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S4>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator1_PrevRes;// '<S4>/Discrete-Time Integrator1'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S4>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;// '<S4>/Discrete-Time Integrator1'
  boolean_T RateTransition6_Buffer0;   // '<S224>/Rate Transition6'
  boolean_T RateTransition6_Buffer0_i; // '<S223>/Rate Transition6'
  boolean_T RateTransition6_Buffer0_o; // '<S226>/Rate Transition6'
  boolean_T RateTransition2_16_Buffer0;// '<Root>/Rate Transition2'
  boolean_T RateTransition2_17_Buffer0;// '<Root>/Rate Transition2'
  DW_SourceBlock_FLIGHT_Hexacop_T SourceBlock_p;// '<S209>/SourceBlock'
  DW_SourceBlock_FLIGHT_Hexacop_T SourceBlock_l;// '<S209>/SourceBlock'
  DW_PX4Timestamp_FLIGHT_Hexa_j_T PX4Timestamp_k;// '<S24>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexaco_T PX4Timestamp_e;// '<S23>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexa_j_T PX4Timestamp_p;// '<S24>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexa_j_T PX4Timestamp_j;// '<S24>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexaco_T PX4Timestamp_c;// '<S23>/PX4 Timestamp'
};

// Parameters (default storage)
struct P_FLIGHT_Hexacopter_V2_1_T_ {
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
                                          //    '<S5>/Read Parameter4'
                                          //    '<S5>/Read Parameter5'
                                          //    '<S5>/Read Parameter6'
                                          //    '<S5>/Read Parameter7'
                                          //    '<S5>/Read Parameter8'
                                          //    '<S5>/Read Parameter9'
                                          //    '<S5>/read_mc_rollrate_p'

  real_T SampleTime_SAS;               // Variable: SampleTime_SAS
                                          //  Referenced by:
                                          //    '<S11>/Read Parameter1'
                                          //    '<S11>/Read Parameter13'
                                          //    '<S11>/Read Parameter2'
                                          //    '<S11>/Read Parameter3'
                                          //    '<S11>/Read Parameter4'
                                          //    '<S11>/Read Parameter5'

  real32_T Jxx;                        // Variable: Jxx
                                          //  Referenced by: '<S439>/Constant'

  real32_T Jyy;                        // Variable: Jyy
                                          //  Referenced by: '<S439>/Constant1'

  real32_T Jzz;                        // Variable: Jzz
                                          //  Referenced by: '<S439>/Constant2'

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
                                 //  Referenced by: '<S384>/UD'

  real32_T DiscreteDerivative2_ICPrevSca_k;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_k
                                 //  Referenced by: '<S329>/UD'

  real32_T DiscreteDerivative2_ICPrevSca_f;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_f
                                 //  Referenced by: '<S450>/UD'

  real32_T DiscreteDerivative2_ICPrevSca_b;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_b
                                 //  Referenced by: '<S442>/UD'

  real32_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S440>/UD'

  real32_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: '<S441>/UD'

  real32_T DiscreteDerivative3_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative3_ICPrevScale
                                 //  Referenced by: '<S443>/UD'

  real32_T PIDController_InitialConditionF;
                              // Mask Parameter: PIDController_InitialConditionF
                                 //  Referenced by: '<S79>/Filter'

  real32_T pid_ctrl_rollrate_InitialCondit;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCondit
                                 //  Referenced by: '<S422>/Integrator'

  real32_T pid_ctrl_rollrate_InitialCond_l;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCond_l
                                 //  Referenced by: '<S367>/Integrator'

  real32_T pid_ctrl_rollrate_InitialCond_p;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCond_p
                                 //  Referenced by: '<S488>/Integrator'

  real32_T PIDController_InitialConditio_d;
                              // Mask Parameter: PIDController_InitialConditio_d
                                 //  Referenced by: '<S84>/Integrator'

  real32_T PIDController_LowerIntegratorSa;
                              // Mask Parameter: PIDController_LowerIntegratorSa
                                 //  Referenced by: '<S84>/Integrator'

  real32_T PIDController_LowerSaturationLi;
                              // Mask Parameter: PIDController_LowerSaturationLi
                                 //  Referenced by:
                                 //    '<S91>/Saturation'
                                 //    '<S76>/DeadZone'

  real32_T PIDController_UpperIntegratorSa;
                              // Mask Parameter: PIDController_UpperIntegratorSa
                                 //  Referenced by: '<S84>/Integrator'

  real32_T PIDController_UpperSaturationLi;
                              // Mask Parameter: PIDController_UpperSaturationLi
                                 //  Referenced by:
                                 //    '<S91>/Saturation'
                                 //    '<S76>/DeadZone'

  uint16_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S10>/Constant'

  uint16_T CompareToConstant_const_a;
                                    // Mask Parameter: CompareToConstant_const_a
                                       //  Referenced by: '<S14>/Constant'

  uint16_T CompareToConstant1_const; // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: '<S39>/Constant'

  uint16_T CompareToConstant2_const; // Mask Parameter: CompareToConstant2_const
                                        //  Referenced by: '<S40>/Constant'

  uint16_T CompareToConstant3_const; // Mask Parameter: CompareToConstant3_const
                                        //  Referenced by: '<S41>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0;// Computed Parameter: Out1_Y0
                                            //  Referenced by: '<S217>/Out1'

  px4_Bus_vehicle_local_position Constant_Value;// Computed Parameter: Constant_Value
                                                   //  Referenced by: '<S211>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0_c;  // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S220>/Out1'

  px4_Bus_vehicle_odometry Constant_Value_j;// Computed Parameter: Constant_Value_j
                                               //  Referenced by: '<S219>/Constant'

  px4_Bus_actuator_motors Constant_Value_e;// Computed Parameter: Constant_Value_e
                                              //  Referenced by: '<S35>/Constant'

  px4_Bus_input_rc Out1_Y0_h;          // Computed Parameter: Out1_Y0_h
                                          //  Referenced by: '<S205>/Out1'

  px4_Bus_input_rc Constant_Value_l;   // Computed Parameter: Constant_Value_l
                                          //  Referenced by: '<S204>/Constant'

  px4_Bus_vehicle_status Out1_Y0_e;    // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S216>/Out1'

  px4_Bus_vehicle_status Constant_Value_k;// Computed Parameter: Constant_Value_k
                                             //  Referenced by: '<S210>/Constant'

  px4_Bus_vehicle_local_position_setpoint Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                              //  Referenced by: '<S37>/Constant'

  px4_Bus_vehicle_attitude_setpoint Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                        //  Referenced by: '<S31>/Constant'

  px4_Bus_vehicle_angular_velocity Out1_Y0_a;// Computed Parameter: Out1_Y0_a
                                                //  Referenced by: '<S207>/Out1'

  px4_Bus_vehicle_angular_velocity Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                       //  Referenced by: '<S206>/Constant'

  px4_Bus_vehicle_rates_setpoint Constant_Value_ek;// Computed Parameter: Constant_Value_ek
                                                      //  Referenced by: '<S33>/Constant'

  px4_Bus_actuator_controls_status Constant_Value_l5;// Computed Parameter: Constant_Value_l5
                                                        //  Referenced by: '<S29>/Constant'

  px4_Bus_actuator_armed Out1_Y0_p;    // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S215>/Out1'

  px4_Bus_actuator_armed Out1_Y0_g;    // Computed Parameter: Out1_Y0_g
                                          //  Referenced by: '<S218>/Out1'

  px4_Bus_actuator_armed Constant_Value_f;// Computed Parameter: Constant_Value_f
                                             //  Referenced by: '<S209>/Constant'

  px4_Bus_actuator_armed Constant_Value_a;// Computed Parameter: Constant_Value_a
                                             //  Referenced by: '<S212>/Constant'

  real_T Constant1_Value;              // Expression: 100
                                          //  Referenced by: '<S11>/Constant1'

  real_T Constant2_Value;              // Expression: 100
                                          //  Referenced by: '<S11>/Constant2'

  real_T Constant3_Value;              // Expression: 100
                                          //  Referenced by: '<S11>/Constant3'

  real_T Constant4_Value;              // Expression: 100
                                          //  Referenced by: '<S11>/Constant4'

  real_T Constant5_Value;              // Expression: 100
                                          //  Referenced by: '<S11>/Constant5'

  real_T Constant_Value_hs;            // Expression: 100
                                          //  Referenced by: '<S11>/Constant'

  real_T Gain_Gain;                    // Expression: 0.01
                                          //  Referenced by: '<S15>/Gain'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<S15>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S15>/Saturation'

  real_T Gain_Gain_l;                  // Expression: 0.01
                                          //  Referenced by: '<S16>/Gain'

  real_T Saturation_UpperSat_f;        // Expression: 1
                                          //  Referenced by: '<S16>/Saturation'

  real_T Saturation_LowerSat_a;        // Expression: 0
                                          //  Referenced by: '<S16>/Saturation'

  real_T Gain_Gain_e;                  // Expression: 0.01
                                          //  Referenced by: '<S17>/Gain'

  real_T Saturation_UpperSat_e;        // Expression: 1
                                          //  Referenced by: '<S17>/Saturation'

  real_T Saturation_LowerSat_m;        // Expression: 0
                                          //  Referenced by: '<S17>/Saturation'

  real_T Gain_Gain_n;                  // Expression: 0.01
                                          //  Referenced by: '<S18>/Gain'

  real_T Saturation_UpperSat_a;        // Expression: 1
                                          //  Referenced by: '<S18>/Saturation'

  real_T Saturation_LowerSat_d;        // Expression: 0
                                          //  Referenced by: '<S18>/Saturation'

  real_T Gain_Gain_g;                  // Expression: 0.01
                                          //  Referenced by: '<S19>/Gain'

  real_T Saturation_UpperSat_en;       // Expression: 1
                                          //  Referenced by: '<S19>/Saturation'

  real_T Saturation_LowerSat_o;        // Expression: 0
                                          //  Referenced by: '<S19>/Saturation'

  real_T Gain_Gain_f;                  // Expression: 0.01
                                          //  Referenced by: '<S20>/Gain'

  real_T Saturation_UpperSat_k;        // Expression: 1
                                          //  Referenced by: '<S20>/Saturation'

  real_T Saturation_LowerSat_k;        // Expression: 0
                                          //  Referenced by: '<S20>/Saturation'

  real_T Constant_Value_k3;            // Expression: 1094
                                          //  Referenced by: '<S4>/Constant'

  real_T Gain_Gain_b;                  // Expression: 1/800
                                          //  Referenced by: '<S4>/Gain'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S9>/Gain1'

  real32_T Gain_Gain_o;                // Computed Parameter: Gain_Gain_o
                                          //  Referenced by: '<S9>/Gain'

  real32_T Constant1_Value_h;          // Computed Parameter: Constant1_Value_h
                                          //  Referenced by: '<S74>/Constant1'

  real32_T Constant_Value_b;           // Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<S15>/Constant'

  real32_T RateTransition4_InitialConditio;
                          // Computed Parameter: RateTransition4_InitialConditio
                             //  Referenced by: '<S9>/Rate Transition4'

  real32_T RateTransition3_InitialConditio;
                          // Computed Parameter: RateTransition3_InitialConditio
                             //  Referenced by: '<S9>/Rate Transition3'

  real32_T RateTransition_InitialCondition;
                          // Computed Parameter: RateTransition_InitialCondition
                             //  Referenced by: '<S224>/Rate Transition'

  real32_T RateTransition4_InitialCondit_l;
                          // Computed Parameter: RateTransition4_InitialCondit_l
                             //  Referenced by: '<S224>/Rate Transition4'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S422>/Integrator'

  real32_T RateTransition2_InitialConditio;
                          // Computed Parameter: RateTransition2_InitialConditio
                             //  Referenced by: '<S224>/Rate Transition2'

  real32_T UnitDelay1_InitialCondition;
                              // Computed Parameter: UnitDelay1_InitialCondition
                                 //  Referenced by: '<S387>/Unit Delay1'

  real32_T RateTransition3_InitialCondit_o;
                          // Computed Parameter: RateTransition3_InitialCondit_o
                             //  Referenced by: '<S224>/Rate Transition3'

  real32_T tau_Gain;                   // Computed Parameter: tau_Gain
                                          //  Referenced by: '<S387>/tau'

  real32_T Bias_Bias;                  // Computed Parameter: Bias_Bias
                                          //  Referenced by: '<S388>/Bias'

  real32_T Gain_Gain_f5;               // Computed Parameter: Gain_Gain_f5
                                          //  Referenced by: '<S388>/Gain'

  real32_T TSamp_WtEt;                 // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S384>/TSamp'

  real32_T RateTransition_InitialConditi_n;
                          // Computed Parameter: RateTransition_InitialConditi_n
                             //  Referenced by: '<S223>/Rate Transition'

  real32_T RateTransition4_InitialCondit_d;
                          // Computed Parameter: RateTransition4_InitialCondit_d
                             //  Referenced by: '<S223>/Rate Transition4'

  real32_T Integrator_gainval_d;     // Computed Parameter: Integrator_gainval_d
                                        //  Referenced by: '<S367>/Integrator'

  real32_T RateTransition2_InitialCondit_p;
                          // Computed Parameter: RateTransition2_InitialCondit_p
                             //  Referenced by: '<S223>/Rate Transition2'

  real32_T UnitDelay1_InitialCondition_h;
                            // Computed Parameter: UnitDelay1_InitialCondition_h
                               //  Referenced by: '<S332>/Unit Delay1'

  real32_T RateTransition3_InitialCondit_m;
                          // Computed Parameter: RateTransition3_InitialCondit_m
                             //  Referenced by: '<S223>/Rate Transition3'

  real32_T tau_Gain_d;                 // Computed Parameter: tau_Gain_d
                                          //  Referenced by: '<S332>/tau'

  real32_T Bias_Bias_o;                // Computed Parameter: Bias_Bias_o
                                          //  Referenced by: '<S333>/Bias'

  real32_T Gain_Gain_bi;               // Computed Parameter: Gain_Gain_bi
                                          //  Referenced by: '<S333>/Gain'

  real32_T TSamp_WtEt_g;               // Computed Parameter: TSamp_WtEt_g
                                          //  Referenced by: '<S329>/TSamp'

  real32_T RateTransition_InitialConditi_c;
                          // Computed Parameter: RateTransition_InitialConditi_c
                             //  Referenced by: '<S9>/Rate Transition'

  real32_T RateTransition1_InitialConditio;
                          // Computed Parameter: RateTransition1_InitialConditio
                             //  Referenced by: '<S9>/Rate Transition1'

  real32_T RateTransition_InitialConditi_m;
                          // Computed Parameter: RateTransition_InitialConditi_m
                             //  Referenced by: '<S226>/Rate Transition'

  real32_T RateTransition4_InitialCondit_a;
                          // Computed Parameter: RateTransition4_InitialCondit_a
                             //  Referenced by: '<S226>/Rate Transition4'

  real32_T Integrator_gainval_b;     // Computed Parameter: Integrator_gainval_b
                                        //  Referenced by: '<S488>/Integrator'

  real32_T RateTransition2_InitialCondit_d;
                          // Computed Parameter: RateTransition2_InitialCondit_d
                             //  Referenced by: '<S226>/Rate Transition2'

  real32_T UnitDelay1_InitialCondition_c;
                            // Computed Parameter: UnitDelay1_InitialCondition_c
                               //  Referenced by: '<S453>/Unit Delay1'

  real32_T RateTransition3_InitialCondi_o5;
                          // Computed Parameter: RateTransition3_InitialCondi_o5
                             //  Referenced by: '<S226>/Rate Transition3'

  real32_T tau_Gain_m;                 // Computed Parameter: tau_Gain_m
                                          //  Referenced by: '<S453>/tau'

  real32_T Bias_Bias_g;                // Computed Parameter: Bias_Bias_g
                                          //  Referenced by: '<S454>/Bias'

  real32_T Gain_Gain_a;                // Computed Parameter: Gain_Gain_a
                                          //  Referenced by: '<S454>/Gain'

  real32_T TSamp_WtEt_m;               // Computed Parameter: TSamp_WtEt_m
                                          //  Referenced by: '<S450>/TSamp'

  real32_T Constant_Value_lg;          // Computed Parameter: Constant_Value_lg
                                          //  Referenced by: '<S16>/Constant'

  real32_T Constant_Value_n;           // Computed Parameter: Constant_Value_n
                                          //  Referenced by: '<S17>/Constant'

  real32_T Constant_Value_e3;          // Computed Parameter: Constant_Value_e3
                                          //  Referenced by: '<S18>/Constant'

  real32_T Constant_Value_d;           // Computed Parameter: Constant_Value_d
                                          //  Referenced by: '<S19>/Constant'

  real32_T Constant_Value_lv;          // Computed Parameter: Constant_Value_lv
                                          //  Referenced by: '<S20>/Constant'

  real32_T Constant_Value_ew;          // Computed Parameter: Constant_Value_ew
                                          //  Referenced by: '<S22>/Constant'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S22>/Gain'

  real32_T Bias1_Bias;                 // Computed Parameter: Bias1_Bias
                                          //  Referenced by: '<S454>/Bias1'

  real32_T Gain1_Gain_d;               // Computed Parameter: Gain1_Gain_d
                                          //  Referenced by: '<S453>/Gain1'

  real32_T UnitDelay2_InitialCondition;
                              // Computed Parameter: UnitDelay2_InitialCondition
                                 //  Referenced by: '<S453>/Unit Delay2'

  real32_T RateTransition1_InitialCondit_d;
                          // Computed Parameter: RateTransition1_InitialCondit_d
                             //  Referenced by: '<S226>/Rate Transition1'

  real32_T Bias1_Bias_k;               // Computed Parameter: Bias1_Bias_k
                                          //  Referenced by: '<S333>/Bias1'

  real32_T Gain1_Gain_m;               // Computed Parameter: Gain1_Gain_m
                                          //  Referenced by: '<S332>/Gain1'

  real32_T UnitDelay2_InitialCondition_b;
                            // Computed Parameter: UnitDelay2_InitialCondition_b
                               //  Referenced by: '<S332>/Unit Delay2'

  real32_T RateTransition1_InitialCondit_f;
                          // Computed Parameter: RateTransition1_InitialCondit_f
                             //  Referenced by: '<S223>/Rate Transition1'

  real32_T Bias1_Bias_a;               // Computed Parameter: Bias1_Bias_a
                                          //  Referenced by: '<S388>/Bias1'

  real32_T Gain1_Gain_i;               // Computed Parameter: Gain1_Gain_i
                                          //  Referenced by: '<S387>/Gain1'

  real32_T UnitDelay2_InitialCondition_e;
                            // Computed Parameter: UnitDelay2_InitialCondition_e
                               //  Referenced by: '<S387>/Unit Delay2'

  real32_T RateTransition1_InitialCondit_p;
                          // Computed Parameter: RateTransition1_InitialCondit_p
                             //  Referenced by: '<S224>/Rate Transition1'

  real32_T Gain_Gain_az;               // Computed Parameter: Gain_Gain_az
                                          //  Referenced by: '<S48>/Gain'

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
                                        //  Referenced by: '<S84>/Integrator'

  real32_T Filter_gainval;             // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S79>/Filter'

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

  real32_T TSamp_WtEt_l;               // Computed Parameter: TSamp_WtEt_l
                                          //  Referenced by: '<S442>/TSamp'

  real32_T TSamp_WtEt_p;               // Computed Parameter: TSamp_WtEt_p
                                          //  Referenced by: '<S440>/TSamp'

  real32_T TSamp_WtEt_j;               // Computed Parameter: TSamp_WtEt_j
                                          //  Referenced by: '<S441>/TSamp'

  real32_T TSamp_WtEt_k;               // Computed Parameter: TSamp_WtEt_k
                                          //  Referenced by: '<S443>/TSamp'

  real32_T DiscreteTimeIntegrator_gainva_o;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_o
                             //  Referenced by: '<S225>/Discrete-Time Integrator'

  real32_T DiscreteTimeIntegrator_IC;
                                // Computed Parameter: DiscreteTimeIntegrator_IC
                                   //  Referenced by: '<S225>/Discrete-Time Integrator'

  real32_T Constant1_Value_f;          // Computed Parameter: Constant1_Value_f
                                          //  Referenced by: '<S3>/Constant1'

  real32_T u2_Gain;                    // Computed Parameter: u2_Gain
                                          //  Referenced by: '<S26>/1//2'

  real32_T Constant_Value_i;           // Computed Parameter: Constant_Value_i
                                          //  Referenced by: '<S3>/Constant'

  real32_T Gain1_Gain_o;               // Computed Parameter: Gain1_Gain_o
                                          //  Referenced by: '<S201>/Gain1'

  real32_T Gain1_Gain_j;               // Computed Parameter: Gain1_Gain_j
                                          //  Referenced by: '<S202>/Gain1'

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

  real32_T Saturation2_UpperSat_j; // Computed Parameter: Saturation2_UpperSat_j
                                      //  Referenced by: '<S225>/Saturation2'

  real32_T Saturation2_LowerSat_h; // Computed Parameter: Saturation2_LowerSat_h
                                      //  Referenced by: '<S225>/Saturation2'

  real32_T Clamping_zero_Value;       // Computed Parameter: Clamping_zero_Value
                                         //  Referenced by: '<S74>/Clamping_zero'

  uint16_T RateTransition_8_InitialConditi;
                          // Computed Parameter: RateTransition_8_InitialConditi
                             //  Referenced by: '<Root>/Rate Transition'

  uint16_T RateTransition_4_InitialConditi;
                          // Computed Parameter: RateTransition_4_InitialConditi
                             //  Referenced by: '<Root>/Rate Transition'

  uint16_T Constant4_Value_f[6];       // Computed Parameter: Constant4_Value_f
                                          //  Referenced by: '<S3>/Constant4'

  uint16_T Saturation_UpperSat_d;   // Computed Parameter: Saturation_UpperSat_d
                                       //  Referenced by: '<S22>/Saturation'

  uint16_T Saturation_LowerSat_d0; // Computed Parameter: Saturation_LowerSat_d0
                                      //  Referenced by: '<S22>/Saturation'

  boolean_T RateTransition6_InitialConditio;
                          // Computed Parameter: RateTransition6_InitialConditio
                             //  Referenced by: '<S224>/Rate Transition6'

  boolean_T RateTransition6_InitialCondit_l;
                          // Computed Parameter: RateTransition6_InitialCondit_l
                             //  Referenced by: '<S223>/Rate Transition6'

  boolean_T RateTransition6_InitialCondit_e;
                          // Computed Parameter: RateTransition6_InitialCondit_e
                             //  Referenced by: '<S226>/Rate Transition6'

  boolean_T RateTransition2_16_InitialCondi;
                          // Computed Parameter: RateTransition2_16_InitialCondi
                             //  Referenced by: '<Root>/Rate Transition2'

  boolean_T RateTransition2_17_InitialCondi;
                          // Computed Parameter: RateTransition2_17_InitialCondi
                             //  Referenced by: '<Root>/Rate Transition2'

  int8_T Constant_Value_kn;            // Computed Parameter: Constant_Value_kn
                                          //  Referenced by: '<S74>/Constant'

  int8_T Constant2_Value_n;            // Computed Parameter: Constant2_Value_n
                                          //  Referenced by: '<S74>/Constant2'

  int8_T Constant3_Value_a;            // Computed Parameter: Constant3_Value_a
                                          //  Referenced by: '<S74>/Constant3'

  int8_T Constant4_Value_fz;           // Computed Parameter: Constant4_Value_fz
                                          //  Referenced by: '<S74>/Constant4'

};

// Real-time Model Data Structure
struct tag_RTM_FLIGHT_Hexacopter_V2__T {
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

  extern P_FLIGHT_Hexacopter_V2_1_T FLIGHT_Hexacopter_V2_1_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_FLIGHT_Hexacopter_V2_1_T FLIGHT_Hexacopter_V2_1_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_FLIGHT_Hexacopter_V2_1_T FLIGHT_Hexacopter_V2_1_DW;

// External function called from main
#ifdef __cplusplus

extern "C"
{

#endif

  extern void FLIGHT_Hexacopter_V2_1_SetEventsForThisBaseStep(boolean_T
    *eventFlags);

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void FLIGHT_Hexacopter_V2_1_initialize(void);
  extern void FLIGHT_Hexacopter_V2_1_step0(void);
  extern void FLIGHT_Hexacopter_V2_1_step1(void);
  extern void FLIGHT_Hexacopter_V2_1_step(int_T tid);
  extern void FLIGHT_Hexacopter_V2_1_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_FLIGHT_Hexacopter_V2_T *const FLIGHT_Hexacopter_V2_1_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S12>/Add1' : Unused code path elimination
//  Block '<S12>/Constant1' : Unused code path elimination
//  Block '<S12>/Data Type Conversion' : Unused code path elimination
//  Block '<S12>/Gain2' : Unused code path elimination
//  Block '<S12>/Mixer matrix' : Unused code path elimination
//  Block '<S12>/Product1' : Unused code path elimination
//  Block '<S12>/Saturation1' : Unused code path elimination
//  Block '<S13>/Add' : Unused code path elimination
//  Block '<S13>/Constant' : Unused code path elimination
//  Block '<S13>/Gain' : Unused code path elimination
//  Block '<S204>/NOT' : Unused code path elimination
//  Block '<S206>/NOT' : Unused code path elimination
//  Block '<S209>/NOT' : Unused code path elimination
//  Block '<S210>/NOT' : Unused code path elimination
//  Block '<S211>/NOT' : Unused code path elimination
//  Block '<S212>/NOT' : Unused code path elimination
//  Block '<S219>/NOT' : Unused code path elimination
//  Block '<S213>/Signal Copy' : Unused code path elimination
//  Block '<S213>/Signal Copy1' : Unused code path elimination
//  Block '<S213>/Signal Copy2' : Unused code path elimination
//  Block '<S268>/Data Type Duplicate' : Unused code path elimination
//  Block '<S268>/Data Type Propagation' : Unused code path elimination
//  Block '<S319>/Data Type Duplicate' : Unused code path elimination
//  Block '<S319>/Data Type Propagation' : Unused code path elimination
//  Block '<S329>/Data Type Duplicate' : Unused code path elimination
//  Block '<S384>/Data Type Duplicate' : Unused code path elimination
//  Block '<S440>/Data Type Duplicate' : Unused code path elimination
//  Block '<S441>/Data Type Duplicate' : Unused code path elimination
//  Block '<S442>/Data Type Duplicate' : Unused code path elimination
//  Block '<S443>/Data Type Duplicate' : Unused code path elimination
//  Block '<S450>/Data Type Duplicate' : Unused code path elimination
//  Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S8>/Data Type Conversion9' : Eliminate redundant data type conversion
//  Block '<S223>/Rate Transition5' : Eliminated since input and output rates are identical
//  Block '<S224>/Rate Transition5' : Eliminated since input and output rates are identical
//  Block '<S439>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S439>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S226>/Rate Transition5' : Eliminated since input and output rates are identical


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
//  '<Root>' : 'FLIGHT_Hexacopter_V2_1'
//  '<S1>'   : 'FLIGHT_Hexacopter_V2_1/Actuator'
//  '<S2>'   : 'FLIGHT_Hexacopter_V2_1/ControlAllocation(CA)'
//  '<S3>'   : 'FLIGHT_Hexacopter_V2_1/Logging'
//  '<S4>'   : 'FLIGHT_Hexacopter_V2_1/OFP'
//  '<S5>'   : 'FLIGHT_Hexacopter_V2_1/Parameters_PARAMS'
//  '<S6>'   : 'FLIGHT_Hexacopter_V2_1/RCCommand(CMD)'
//  '<S7>'   : 'FLIGHT_Hexacopter_V2_1/Read_uORB(1000hz)_SENSORS1000'
//  '<S8>'   : 'FLIGHT_Hexacopter_V2_1/Read_uORB(250hz)_SENSORS250'
//  '<S9>'   : 'FLIGHT_Hexacopter_V2_1/SCAS'
//  '<S10>'  : 'FLIGHT_Hexacopter_V2_1/ControlAllocation(CA)/Compare To Constant'
//  '<S11>'  : 'FLIGHT_Hexacopter_V2_1/ControlAllocation(CA)/Fault_Injection'
//  '<S12>'  : 'FLIGHT_Hexacopter_V2_1/ControlAllocation(CA)/Subsystem Reference'
//  '<S13>'  : 'FLIGHT_Hexacopter_V2_1/ControlAllocation(CA)/Subsystem Reference1'
//  '<S14>'  : 'FLIGHT_Hexacopter_V2_1/ControlAllocation(CA)/Fault_Injection/Compare To Constant'
//  '<S15>'  : 'FLIGHT_Hexacopter_V2_1/ControlAllocation(CA)/Fault_Injection/Subsystem Reference'
//  '<S16>'  : 'FLIGHT_Hexacopter_V2_1/ControlAllocation(CA)/Fault_Injection/Subsystem Reference1'
//  '<S17>'  : 'FLIGHT_Hexacopter_V2_1/ControlAllocation(CA)/Fault_Injection/Subsystem Reference2'
//  '<S18>'  : 'FLIGHT_Hexacopter_V2_1/ControlAllocation(CA)/Fault_Injection/Subsystem Reference3'
//  '<S19>'  : 'FLIGHT_Hexacopter_V2_1/ControlAllocation(CA)/Fault_Injection/Subsystem Reference4'
//  '<S20>'  : 'FLIGHT_Hexacopter_V2_1/ControlAllocation(CA)/Fault_Injection/Subsystem Reference5'
//  '<S21>'  : 'FLIGHT_Hexacopter_V2_1/ControlAllocation(CA)/Subsystem Reference1/pwm_out2'
//  '<S22>'  : 'FLIGHT_Hexacopter_V2_1/Logging/Normalize_pwm6'
//  '<S23>'  : 'FLIGHT_Hexacopter_V2_1/Logging/PX4 ULog ActuatorControlsStatus'
//  '<S24>'  : 'FLIGHT_Hexacopter_V2_1/Logging/PX4 ULog VehicleAttitudeSetpoint'
//  '<S25>'  : 'FLIGHT_Hexacopter_V2_1/Logging/PX4 ULog2 VehicleRatesSetpoint'
//  '<S26>'  : 'FLIGHT_Hexacopter_V2_1/Logging/Rotation Angles to Quaternions'
//  '<S27>'  : 'FLIGHT_Hexacopter_V2_1/Logging/ULog_ActuatorMotors'
//  '<S28>'  : 'FLIGHT_Hexacopter_V2_1/Logging/ULog_VehicleLocalPositionSetpoint'
//  '<S29>'  : 'FLIGHT_Hexacopter_V2_1/Logging/PX4 ULog ActuatorControlsStatus/PX4 uORB Message'
//  '<S30>'  : 'FLIGHT_Hexacopter_V2_1/Logging/PX4 ULog ActuatorControlsStatus/PX4_log_write'
//  '<S31>'  : 'FLIGHT_Hexacopter_V2_1/Logging/PX4 ULog VehicleAttitudeSetpoint/PX4 uORB Message'
//  '<S32>'  : 'FLIGHT_Hexacopter_V2_1/Logging/PX4 ULog VehicleAttitudeSetpoint/PX4_log_write'
//  '<S33>'  : 'FLIGHT_Hexacopter_V2_1/Logging/PX4 ULog2 VehicleRatesSetpoint/PX4 uORB Message'
//  '<S34>'  : 'FLIGHT_Hexacopter_V2_1/Logging/PX4 ULog2 VehicleRatesSetpoint/PX4_log_write'
//  '<S35>'  : 'FLIGHT_Hexacopter_V2_1/Logging/ULog_ActuatorMotors/PX4 uORB Message'
//  '<S36>'  : 'FLIGHT_Hexacopter_V2_1/Logging/ULog_ActuatorMotors/PX4_log_write'
//  '<S37>'  : 'FLIGHT_Hexacopter_V2_1/Logging/ULog_VehicleLocalPositionSetpoint/PX4 uORB Message'
//  '<S38>'  : 'FLIGHT_Hexacopter_V2_1/Logging/ULog_VehicleLocalPositionSetpoint/PX4_log_write'
//  '<S39>'  : 'FLIGHT_Hexacopter_V2_1/OFP/Compare To Constant1'
//  '<S40>'  : 'FLIGHT_Hexacopter_V2_1/OFP/Compare To Constant2'
//  '<S41>'  : 'FLIGHT_Hexacopter_V2_1/OFP/Compare To Constant3'
//  '<S42>'  : 'FLIGHT_Hexacopter_V2_1/OFP/MATLAB Function'
//  '<S43>'  : 'FLIGHT_Hexacopter_V2_1/OFP/MATLAB Function1'
//  '<S44>'  : 'FLIGHT_Hexacopter_V2_1/OFP/NED2Body1'
//  '<S45>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller'
//  '<S46>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude'
//  '<S47>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1'
//  '<S48>'  : 'FLIGHT_Hexacopter_V2_1/OFP/NED2Body1/Calculate Transformation Matrix'
//  '<S49>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Anti-windup'
//  '<S50>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/D Gain'
//  '<S51>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/External Derivative'
//  '<S52>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Filter'
//  '<S53>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Filter ICs'
//  '<S54>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/I Gain'
//  '<S55>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Ideal P Gain'
//  '<S56>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Ideal P Gain Fdbk'
//  '<S57>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Integrator'
//  '<S58>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Integrator ICs'
//  '<S59>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/N Copy'
//  '<S60>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/N Gain'
//  '<S61>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/P Copy'
//  '<S62>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Parallel P Gain'
//  '<S63>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Reset Signal'
//  '<S64>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Saturation'
//  '<S65>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Saturation Fdbk'
//  '<S66>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Sum'
//  '<S67>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Sum Fdbk'
//  '<S68>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Tracking Mode'
//  '<S69>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Tracking Mode Sum'
//  '<S70>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Tsamp - Integral'
//  '<S71>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Tsamp - Ngain'
//  '<S72>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/postSat Signal'
//  '<S73>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/preSat Signal'
//  '<S74>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S75>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S76>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S77>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/D Gain/External Parameters'
//  '<S78>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/External Derivative/Error'
//  '<S79>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S80>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S81>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/I Gain/External Parameters'
//  '<S82>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Ideal P Gain/Passthrough'
//  '<S83>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S84>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Integrator/Discrete'
//  '<S85>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Integrator ICs/Internal IC'
//  '<S86>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/N Copy/Disabled'
//  '<S87>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/N Gain/External Parameters'
//  '<S88>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/P Copy/Disabled'
//  '<S89>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Parallel P Gain/External Parameters'
//  '<S90>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Reset Signal/External Reset'
//  '<S91>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Saturation/Enabled'
//  '<S92>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Saturation Fdbk/Disabled'
//  '<S93>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Sum/Sum_PID'
//  '<S94>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Sum Fdbk/Disabled'
//  '<S95>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Tracking Mode/Disabled'
//  '<S96>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S97>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S98>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S99>'  : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/postSat Signal/Forward_Path'
//  '<S100>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID Controller/preSat Signal/Forward_Path'
//  '<S101>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Anti-windup'
//  '<S102>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/D Gain'
//  '<S103>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/External Derivative'
//  '<S104>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Filter'
//  '<S105>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Filter ICs'
//  '<S106>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/I Gain'
//  '<S107>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Ideal P Gain'
//  '<S108>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Ideal P Gain Fdbk'
//  '<S109>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Integrator'
//  '<S110>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Integrator ICs'
//  '<S111>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/N Copy'
//  '<S112>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/N Gain'
//  '<S113>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/P Copy'
//  '<S114>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Parallel P Gain'
//  '<S115>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Reset Signal'
//  '<S116>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Saturation'
//  '<S117>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Saturation Fdbk'
//  '<S118>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Sum'
//  '<S119>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Sum Fdbk'
//  '<S120>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Tracking Mode'
//  '<S121>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Tracking Mode Sum'
//  '<S122>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Tsamp - Integral'
//  '<S123>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Tsamp - Ngain'
//  '<S124>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/postSat Signal'
//  '<S125>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/preSat Signal'
//  '<S126>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Anti-windup/Disabled'
//  '<S127>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/D Gain/Disabled'
//  '<S128>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/External Derivative/Disabled'
//  '<S129>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Filter/Disabled'
//  '<S130>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Filter ICs/Disabled'
//  '<S131>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/I Gain/Disabled'
//  '<S132>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S133>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Ideal P Gain Fdbk/Disabled'
//  '<S134>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Integrator/Disabled'
//  '<S135>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Integrator ICs/Disabled'
//  '<S136>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/N Copy/Disabled wSignal Specification'
//  '<S137>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/N Gain/Disabled'
//  '<S138>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/P Copy/Disabled'
//  '<S139>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Parallel P Gain/External Parameters'
//  '<S140>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Reset Signal/Disabled'
//  '<S141>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Saturation/Passthrough'
//  '<S142>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Saturation Fdbk/Disabled'
//  '<S143>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Sum/Passthrough_P'
//  '<S144>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Sum Fdbk/Disabled'
//  '<S145>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Tracking Mode/Disabled'
//  '<S146>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S147>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S148>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S149>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/postSat Signal/Forward_Path'
//  '<S150>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude/preSat Signal/Forward_Path'
//  '<S151>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Anti-windup'
//  '<S152>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/D Gain'
//  '<S153>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/External Derivative'
//  '<S154>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Filter'
//  '<S155>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Filter ICs'
//  '<S156>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/I Gain'
//  '<S157>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Ideal P Gain'
//  '<S158>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Ideal P Gain Fdbk'
//  '<S159>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Integrator'
//  '<S160>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Integrator ICs'
//  '<S161>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/N Copy'
//  '<S162>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/N Gain'
//  '<S163>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/P Copy'
//  '<S164>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Parallel P Gain'
//  '<S165>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Reset Signal'
//  '<S166>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Saturation'
//  '<S167>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Saturation Fdbk'
//  '<S168>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Sum'
//  '<S169>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Sum Fdbk'
//  '<S170>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Tracking Mode'
//  '<S171>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Tracking Mode Sum'
//  '<S172>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Tsamp - Integral'
//  '<S173>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Tsamp - Ngain'
//  '<S174>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/postSat Signal'
//  '<S175>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/preSat Signal'
//  '<S176>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Anti-windup/Disabled'
//  '<S177>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/D Gain/Disabled'
//  '<S178>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/External Derivative/Disabled'
//  '<S179>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Filter/Disabled'
//  '<S180>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Filter ICs/Disabled'
//  '<S181>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/I Gain/Disabled'
//  '<S182>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Ideal P Gain/Passthrough'
//  '<S183>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Ideal P Gain Fdbk/Disabled'
//  '<S184>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Integrator/Disabled'
//  '<S185>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Integrator ICs/Disabled'
//  '<S186>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/N Copy/Disabled wSignal Specification'
//  '<S187>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/N Gain/Disabled'
//  '<S188>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/P Copy/Disabled'
//  '<S189>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Parallel P Gain/External Parameters'
//  '<S190>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Reset Signal/Disabled'
//  '<S191>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Saturation/Passthrough'
//  '<S192>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Saturation Fdbk/Disabled'
//  '<S193>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Sum/Passthrough_P'
//  '<S194>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Sum Fdbk/Disabled'
//  '<S195>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Tracking Mode/Disabled'
//  '<S196>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Tracking Mode Sum/Passthrough'
//  '<S197>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Tsamp - Integral/TsSignalSpecification'
//  '<S198>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/Tsamp - Ngain/Passthrough'
//  '<S199>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/postSat Signal/Forward_Path'
//  '<S200>' : 'FLIGHT_Hexacopter_V2_1/OFP/PID_Altitude1/preSat Signal/Forward_Path'
//  '<S201>' : 'FLIGHT_Hexacopter_V2_1/Parameters_PARAMS/Degrees to Radians'
//  '<S202>' : 'FLIGHT_Hexacopter_V2_1/Parameters_PARAMS/Degrees to Radians1'
//  '<S203>' : 'FLIGHT_Hexacopter_V2_1/Parameters_PARAMS/MATLAB Function'
//  '<S204>' : 'FLIGHT_Hexacopter_V2_1/RCCommand(CMD)/PX4 uORB Read'
//  '<S205>' : 'FLIGHT_Hexacopter_V2_1/RCCommand(CMD)/PX4 uORB Read/Enabled Subsystem'
//  '<S206>' : 'FLIGHT_Hexacopter_V2_1/Read_uORB(1000hz)_SENSORS1000/PX4 uORB Read1'
//  '<S207>' : 'FLIGHT_Hexacopter_V2_1/Read_uORB(1000hz)_SENSORS1000/PX4 uORB Read1/Enabled Subsystem'
//  '<S208>' : 'FLIGHT_Hexacopter_V2_1/Read_uORB(250hz)_SENSORS250/MATLAB Function'
//  '<S209>' : 'FLIGHT_Hexacopter_V2_1/Read_uORB(250hz)_SENSORS250/PX4 uORB Read'
//  '<S210>' : 'FLIGHT_Hexacopter_V2_1/Read_uORB(250hz)_SENSORS250/PX4 uORB Read1'
//  '<S211>' : 'FLIGHT_Hexacopter_V2_1/Read_uORB(250hz)_SENSORS250/PX4 uORB Read2'
//  '<S212>' : 'FLIGHT_Hexacopter_V2_1/Read_uORB(250hz)_SENSORS250/PX4 uORB Read3'
//  '<S213>' : 'FLIGHT_Hexacopter_V2_1/Read_uORB(250hz)_SENSORS250/Vehicle Attitude'
//  '<S214>' : 'FLIGHT_Hexacopter_V2_1/Read_uORB(250hz)_SENSORS250/quat2eul'
//  '<S215>' : 'FLIGHT_Hexacopter_V2_1/Read_uORB(250hz)_SENSORS250/PX4 uORB Read/Enabled Subsystem'
//  '<S216>' : 'FLIGHT_Hexacopter_V2_1/Read_uORB(250hz)_SENSORS250/PX4 uORB Read1/Enabled Subsystem'
//  '<S217>' : 'FLIGHT_Hexacopter_V2_1/Read_uORB(250hz)_SENSORS250/PX4 uORB Read2/Enabled Subsystem'
//  '<S218>' : 'FLIGHT_Hexacopter_V2_1/Read_uORB(250hz)_SENSORS250/PX4 uORB Read3/Enabled Subsystem'
//  '<S219>' : 'FLIGHT_Hexacopter_V2_1/Read_uORB(250hz)_SENSORS250/Vehicle Attitude/PX4 uORB Read'
//  '<S220>' : 'FLIGHT_Hexacopter_V2_1/Read_uORB(250hz)_SENSORS250/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'
//  '<S221>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3'
//  '<S222>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4'
//  '<S223>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate'
//  '<S224>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate'
//  '<S225>' : 'FLIGHT_Hexacopter_V2_1/SCAS/SMC'
//  '<S226>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate'
//  '<S227>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Anti-windup'
//  '<S228>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/D Gain'
//  '<S229>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/External Derivative'
//  '<S230>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Filter'
//  '<S231>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Filter ICs'
//  '<S232>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/I Gain'
//  '<S233>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Ideal P Gain'
//  '<S234>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Ideal P Gain Fdbk'
//  '<S235>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Integrator'
//  '<S236>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Integrator ICs'
//  '<S237>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/N Copy'
//  '<S238>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/N Gain'
//  '<S239>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/P Copy'
//  '<S240>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Parallel P Gain'
//  '<S241>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Reset Signal'
//  '<S242>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Saturation'
//  '<S243>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Saturation Fdbk'
//  '<S244>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Sum'
//  '<S245>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Sum Fdbk'
//  '<S246>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Tracking Mode'
//  '<S247>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Tracking Mode Sum'
//  '<S248>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Tsamp - Integral'
//  '<S249>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Tsamp - Ngain'
//  '<S250>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/postSat Signal'
//  '<S251>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/preSat Signal'
//  '<S252>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Anti-windup/Disabled'
//  '<S253>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/D Gain/Disabled'
//  '<S254>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/External Derivative/Disabled'
//  '<S255>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Filter/Disabled'
//  '<S256>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Filter ICs/Disabled'
//  '<S257>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/I Gain/Disabled'
//  '<S258>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Ideal P Gain/Passthrough'
//  '<S259>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S260>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Integrator/Disabled'
//  '<S261>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Integrator ICs/Disabled'
//  '<S262>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S263>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/N Gain/Disabled'
//  '<S264>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/P Copy/Disabled'
//  '<S265>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Parallel P Gain/External Parameters'
//  '<S266>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Reset Signal/Disabled'
//  '<S267>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Saturation/External'
//  '<S268>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Saturation/External/Saturation Dynamic'
//  '<S269>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Saturation Fdbk/Disabled'
//  '<S270>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Sum/Passthrough_P'
//  '<S271>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Sum Fdbk/Disabled'
//  '<S272>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Tracking Mode/Disabled'
//  '<S273>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S274>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S275>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S276>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/postSat Signal/Forward_Path'
//  '<S277>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller3/preSat Signal/Forward_Path'
//  '<S278>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Anti-windup'
//  '<S279>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/D Gain'
//  '<S280>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/External Derivative'
//  '<S281>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Filter'
//  '<S282>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Filter ICs'
//  '<S283>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/I Gain'
//  '<S284>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Ideal P Gain'
//  '<S285>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Ideal P Gain Fdbk'
//  '<S286>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Integrator'
//  '<S287>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Integrator ICs'
//  '<S288>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/N Copy'
//  '<S289>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/N Gain'
//  '<S290>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/P Copy'
//  '<S291>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Parallel P Gain'
//  '<S292>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Reset Signal'
//  '<S293>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Saturation'
//  '<S294>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Saturation Fdbk'
//  '<S295>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Sum'
//  '<S296>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Sum Fdbk'
//  '<S297>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Tracking Mode'
//  '<S298>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Tracking Mode Sum'
//  '<S299>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Tsamp - Integral'
//  '<S300>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Tsamp - Ngain'
//  '<S301>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/postSat Signal'
//  '<S302>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/preSat Signal'
//  '<S303>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Anti-windup/Disabled'
//  '<S304>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/D Gain/Disabled'
//  '<S305>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/External Derivative/Disabled'
//  '<S306>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Filter/Disabled'
//  '<S307>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Filter ICs/Disabled'
//  '<S308>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/I Gain/Disabled'
//  '<S309>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Ideal P Gain/Passthrough'
//  '<S310>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S311>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Integrator/Disabled'
//  '<S312>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Integrator ICs/Disabled'
//  '<S313>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S314>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/N Gain/Disabled'
//  '<S315>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/P Copy/Disabled'
//  '<S316>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Parallel P Gain/External Parameters'
//  '<S317>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Reset Signal/Disabled'
//  '<S318>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Saturation/External'
//  '<S319>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Saturation/External/Saturation Dynamic'
//  '<S320>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Saturation Fdbk/Disabled'
//  '<S321>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Sum/Passthrough_P'
//  '<S322>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Sum Fdbk/Disabled'
//  '<S323>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Tracking Mode/Disabled'
//  '<S324>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S325>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S326>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S327>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/postSat Signal/Forward_Path'
//  '<S328>' : 'FLIGHT_Hexacopter_V2_1/SCAS/PID Controller4/preSat Signal/Forward_Path'
//  '<S329>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/Discrete Derivative2'
//  '<S330>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/Discrete Varying Lowpass2'
//  '<S331>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate'
//  '<S332>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/Discrete Varying Lowpass2/SOS1'
//  '<S333>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/Discrete Varying Lowpass2/SOS1/Arithmetic'
//  '<S334>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Anti-windup'
//  '<S335>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/D Gain'
//  '<S336>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/External Derivative'
//  '<S337>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Filter'
//  '<S338>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Filter ICs'
//  '<S339>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/I Gain'
//  '<S340>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Ideal P Gain'
//  '<S341>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Ideal P Gain Fdbk'
//  '<S342>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Integrator'
//  '<S343>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Integrator ICs'
//  '<S344>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/N Copy'
//  '<S345>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/N Gain'
//  '<S346>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/P Copy'
//  '<S347>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Parallel P Gain'
//  '<S348>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Reset Signal'
//  '<S349>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Saturation'
//  '<S350>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Saturation Fdbk'
//  '<S351>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Sum'
//  '<S352>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Sum Fdbk'
//  '<S353>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Tracking Mode'
//  '<S354>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Tracking Mode Sum'
//  '<S355>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Tsamp - Integral'
//  '<S356>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Tsamp - Ngain'
//  '<S357>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/postSat Signal'
//  '<S358>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/preSat Signal'
//  '<S359>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Anti-windup/Passthrough'
//  '<S360>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/D Gain/Disabled'
//  '<S361>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/External Derivative/Disabled'
//  '<S362>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Filter/Disabled'
//  '<S363>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Filter ICs/Disabled'
//  '<S364>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/I Gain/External Parameters'
//  '<S365>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Ideal P Gain/Passthrough'
//  '<S366>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Ideal P Gain Fdbk/Disabled'
//  '<S367>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Integrator/Discrete'
//  '<S368>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Integrator ICs/Internal IC'
//  '<S369>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/N Copy/Disabled wSignal Specification'
//  '<S370>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/N Gain/Disabled'
//  '<S371>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/P Copy/Disabled'
//  '<S372>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Parallel P Gain/External Parameters'
//  '<S373>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Reset Signal/External Reset'
//  '<S374>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Saturation/Passthrough'
//  '<S375>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Saturation Fdbk/Disabled'
//  '<S376>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Sum/Sum_PI'
//  '<S377>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Sum Fdbk/Disabled'
//  '<S378>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Tracking Mode/Disabled'
//  '<S379>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Tracking Mode Sum/Passthrough'
//  '<S380>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Tsamp - Integral/TsSignalSpecification'
//  '<S381>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/Tsamp - Ngain/Passthrough'
//  '<S382>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/postSat Signal/Forward_Path'
//  '<S383>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Pitchrate/pid_ctrl_rollrate/preSat Signal/Forward_Path'
//  '<S384>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/Discrete Derivative2'
//  '<S385>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/Discrete Varying Lowpass2'
//  '<S386>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate'
//  '<S387>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/Discrete Varying Lowpass2/SOS1'
//  '<S388>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/Discrete Varying Lowpass2/SOS1/Arithmetic'
//  '<S389>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Anti-windup'
//  '<S390>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/D Gain'
//  '<S391>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/External Derivative'
//  '<S392>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Filter'
//  '<S393>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Filter ICs'
//  '<S394>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/I Gain'
//  '<S395>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Ideal P Gain'
//  '<S396>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Ideal P Gain Fdbk'
//  '<S397>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Integrator'
//  '<S398>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Integrator ICs'
//  '<S399>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/N Copy'
//  '<S400>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/N Gain'
//  '<S401>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/P Copy'
//  '<S402>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Parallel P Gain'
//  '<S403>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Reset Signal'
//  '<S404>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Saturation'
//  '<S405>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Saturation Fdbk'
//  '<S406>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Sum'
//  '<S407>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Sum Fdbk'
//  '<S408>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Tracking Mode'
//  '<S409>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Tracking Mode Sum'
//  '<S410>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Tsamp - Integral'
//  '<S411>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Tsamp - Ngain'
//  '<S412>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/postSat Signal'
//  '<S413>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/preSat Signal'
//  '<S414>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Anti-windup/Passthrough'
//  '<S415>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/D Gain/Disabled'
//  '<S416>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/External Derivative/Disabled'
//  '<S417>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Filter/Disabled'
//  '<S418>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Filter ICs/Disabled'
//  '<S419>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/I Gain/External Parameters'
//  '<S420>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Ideal P Gain/Passthrough'
//  '<S421>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Ideal P Gain Fdbk/Disabled'
//  '<S422>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Integrator/Discrete'
//  '<S423>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Integrator ICs/Internal IC'
//  '<S424>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/N Copy/Disabled wSignal Specification'
//  '<S425>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/N Gain/Disabled'
//  '<S426>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/P Copy/Disabled'
//  '<S427>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Parallel P Gain/External Parameters'
//  '<S428>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Reset Signal/External Reset'
//  '<S429>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Saturation/Passthrough'
//  '<S430>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Saturation Fdbk/Disabled'
//  '<S431>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Sum/Sum_PI'
//  '<S432>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Sum Fdbk/Disabled'
//  '<S433>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Tracking Mode/Disabled'
//  '<S434>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Tracking Mode Sum/Passthrough'
//  '<S435>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Tsamp - Integral/TsSignalSpecification'
//  '<S436>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/Tsamp - Ngain/Passthrough'
//  '<S437>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/postSat Signal/Forward_Path'
//  '<S438>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Rollrate/pid_ctrl_rollrate/preSat Signal/Forward_Path'
//  '<S439>' : 'FLIGHT_Hexacopter_V2_1/SCAS/SMC/Calc_Fx_Gx'
//  '<S440>' : 'FLIGHT_Hexacopter_V2_1/SCAS/SMC/Discrete Derivative'
//  '<S441>' : 'FLIGHT_Hexacopter_V2_1/SCAS/SMC/Discrete Derivative1'
//  '<S442>' : 'FLIGHT_Hexacopter_V2_1/SCAS/SMC/Discrete Derivative2'
//  '<S443>' : 'FLIGHT_Hexacopter_V2_1/SCAS/SMC/Discrete Derivative3'
//  '<S444>' : 'FLIGHT_Hexacopter_V2_1/SCAS/SMC/MATLAB Function'
//  '<S445>' : 'FLIGHT_Hexacopter_V2_1/SCAS/SMC/MATLAB Function1'
//  '<S446>' : 'FLIGHT_Hexacopter_V2_1/SCAS/SMC/MATLAB Function2'
//  '<S447>' : 'FLIGHT_Hexacopter_V2_1/SCAS/SMC/MATLAB Function3'
//  '<S448>' : 'FLIGHT_Hexacopter_V2_1/SCAS/SMC/MATLAB Function4'
//  '<S449>' : 'FLIGHT_Hexacopter_V2_1/SCAS/SMC/Omega_phi'
//  '<S450>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/Discrete Derivative2'
//  '<S451>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/Discrete Varying Lowpass2'
//  '<S452>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate'
//  '<S453>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/Discrete Varying Lowpass2/SOS1'
//  '<S454>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/Discrete Varying Lowpass2/SOS1/Arithmetic'
//  '<S455>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Anti-windup'
//  '<S456>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/D Gain'
//  '<S457>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/External Derivative'
//  '<S458>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Filter'
//  '<S459>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Filter ICs'
//  '<S460>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/I Gain'
//  '<S461>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Ideal P Gain'
//  '<S462>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Ideal P Gain Fdbk'
//  '<S463>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Integrator'
//  '<S464>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Integrator ICs'
//  '<S465>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/N Copy'
//  '<S466>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/N Gain'
//  '<S467>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/P Copy'
//  '<S468>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Parallel P Gain'
//  '<S469>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Reset Signal'
//  '<S470>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Saturation'
//  '<S471>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Saturation Fdbk'
//  '<S472>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Sum'
//  '<S473>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Sum Fdbk'
//  '<S474>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Tracking Mode'
//  '<S475>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Tracking Mode Sum'
//  '<S476>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Tsamp - Integral'
//  '<S477>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Tsamp - Ngain'
//  '<S478>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/postSat Signal'
//  '<S479>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/preSat Signal'
//  '<S480>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Anti-windup/Passthrough'
//  '<S481>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/D Gain/Disabled'
//  '<S482>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/External Derivative/Disabled'
//  '<S483>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Filter/Disabled'
//  '<S484>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Filter ICs/Disabled'
//  '<S485>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/I Gain/External Parameters'
//  '<S486>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Ideal P Gain/Passthrough'
//  '<S487>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Ideal P Gain Fdbk/Disabled'
//  '<S488>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Integrator/Discrete'
//  '<S489>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Integrator ICs/Internal IC'
//  '<S490>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/N Copy/Disabled wSignal Specification'
//  '<S491>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/N Gain/Disabled'
//  '<S492>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/P Copy/Disabled'
//  '<S493>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Parallel P Gain/External Parameters'
//  '<S494>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Reset Signal/External Reset'
//  '<S495>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Saturation/Passthrough'
//  '<S496>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Saturation Fdbk/Disabled'
//  '<S497>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Sum/Sum_PI'
//  '<S498>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Sum Fdbk/Disabled'
//  '<S499>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Tracking Mode/Disabled'
//  '<S500>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Tracking Mode Sum/Passthrough'
//  '<S501>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Tsamp - Integral/TsSignalSpecification'
//  '<S502>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/Tsamp - Ngain/Passthrough'
//  '<S503>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/postSat Signal/Forward_Path'
//  '<S504>' : 'FLIGHT_Hexacopter_V2_1/SCAS/Yawrate/pid_ctrl_rollrate/preSat Signal/Forward_Path'

#endif                                 // FLIGHT_Hexacopter_V2_1_h_

//
// File trailer for generated code.
//
// [EOF]
//
