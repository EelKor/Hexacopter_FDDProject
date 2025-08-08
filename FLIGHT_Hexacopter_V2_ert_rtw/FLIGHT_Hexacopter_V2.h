//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_Hexacopter_V2.h
//
// Code generated for Simulink model 'FLIGHT_Hexacopter_V2'.
//
// Model version                  : 3.5
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Aug  6 11:25:39 2025
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
#include "MW_PX4_Parameter.h"
#include "MW_Parameter.h"
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

// Block signals for system '<S3>/PX4 Timestamp'
struct B_PX4Timestamp_FLIGHT_Hexacop_T {
  uint64_T PX4Timestamp;               // '<S3>/PX4 Timestamp'
};

// Block states (default storage) for system '<S3>/PX4 Timestamp'
struct DW_PX4Timestamp_FLIGHT_Hexaco_T {
  px4_internal_block_getPX4Abso_T obj; // '<S3>/PX4 Timestamp'
  boolean_T objisempty;                // '<S3>/PX4 Timestamp'
};

// Block signals for system '<S24>/PX4 Timestamp'
struct B_PX4Timestamp_FLIGHT_Hexac_a_T {
  uint64_T PX4Timestamp;               // '<S24>/PX4 Timestamp'
};

// Block states (default storage) for system '<S24>/PX4 Timestamp'
struct DW_PX4Timestamp_FLIGHT_Hexa_o_T {
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

// Block signals for system '<S226>/SourceBlock'
struct B_SourceBlock_FLIGHT_Hexacopt_T {
  px4_Bus_actuator_armed SourceBlock_o2;// '<S226>/SourceBlock'
  boolean_T SourceBlock_o1;            // '<S226>/SourceBlock'
};

// Block states (default storage) for system '<S226>/SourceBlock'
struct DW_SourceBlock_FLIGHT_Hexacop_T {
  px4_internal_block_Subscriber_T obj; // '<S226>/SourceBlock'
  boolean_T objisempty;                // '<S226>/SourceBlock'
};

// Block signals (default storage)
struct B_FLIGHT_Hexacopter_V2_T {
  px4_Bus_vehicle_local_position In1;  // '<S234>/In1'
  px4_Bus_vehicle_local_position r;
  px4_Bus_vehicle_odometry In1_b;      // '<S237>/In1'
  px4_Bus_vehicle_attitude_smc_setpoint BusAssignment;// '<S28>/Bus Assignment'
  px4_Bus_vehicle_odometry r1;
  px4_Bus_actuator_motors BusAssignment_e;// '<S29>/Bus Assignment'
  px4_Bus_input_rc r2;
  px4_Bus_vehicle_status In1_m;        // '<S233>/In1'
  px4_Bus_input_rc In1_p;              // '<S222>/In1'
  px4_Bus_vehicle_status r3;
  real_T CreateDiagonalMatrix[9];      // '<S238>/Create Diagonal Matrix'
  px4_Bus_vehicle_local_position_setpoint BusAssignment_g;// '<S30>/Bus Assignment' 
  px4_Bus_vehicle_attitude_setpoint BusAssignment_f;// '<S25>/Bus Assignment'
  px4_Bus_vehicle_rates_setpoint BusAssignment_e0;// '<S26>/Bus Assignment'
  px4_Bus_vehicle_angular_velocity In1_k;// '<S224>/In1'
  px4_Bus_vehicle_angular_velocity r4;
  px4_Bus_actuator_controls_status BusAssignment_j;// '<S24>/Bus Assignment'
  px4_Bus_actuator_armed In1_d;        // '<S235>/In1'
  px4_Bus_actuator_armed In1_e;        // '<S232>/In1'
  uint16_T pwmValue[8];
  real32_T ypr[3];                     // '<S8>/quat2eul'
  real32_T U[3];
  real32_T G1[3];                      // '<S9>/MATLAB Function1'
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
  uint64_T rtb_PX4Timestamp_m;
  real32_T RateTransition4;            // '<S10>/Rate Transition4'
  real32_T RateTransition;             // '<S365>/Rate Transition'
  real32_T RateTransition4_a;          // '<S365>/Rate Transition4'
  real32_T RateTransition2;            // '<S365>/Rate Transition2'
  real32_T RateTransition3;            // '<S365>/Rate Transition3'
  real32_T RateTransition2_a[3];       // '<S9>/Rate Transition2'
  real32_T RateTransition4_l;          // '<S9>/Rate Transition4'
  real32_T RateTransition5;            // '<S9>/Rate Transition5'
  real32_T RateTransition6;            // '<S9>/Rate Transition6'
  real32_T RateTransition9;            // '<S9>/Rate Transition9'
  real32_T RateTransition10;           // '<S9>/Rate Transition10'
  real32_T RateTransition11;           // '<S9>/Rate Transition11'
  real32_T RateTransition17;           // '<S9>/Rate Transition17'
  real32_T RateTransition1;            // '<S9>/Rate Transition1'
  real32_T RateTransition7;            // '<S9>/Rate Transition7'
  real32_T RateTransition8;            // '<S9>/Rate Transition8'
  real32_T RateTransition12;           // '<S9>/Rate Transition12'
  real32_T RateTransition13;           // '<S9>/Rate Transition13'
  real32_T RateTransition14;           // '<S9>/Rate Transition14'
  real32_T RateTransition_e;           // '<S364>/Rate Transition'
  real32_T RateTransition4_b;          // '<S364>/Rate Transition4'
  real32_T RateTransition2_b;          // '<S364>/Rate Transition2'
  real32_T RateTransition3_b;          // '<S364>/Rate Transition3'
  real32_T RateTransition_j;           // '<S10>/Rate Transition'
  real32_T RateTransition1_a;          // '<S10>/Rate Transition1'
  real32_T RateTransition_f;           // '<S366>/Rate Transition'
  real32_T RateTransition4_ar;         // '<S366>/Rate Transition4'
  real32_T RateTransition2_d;          // '<S366>/Rate Transition2'
  real32_T RateTransition3_e;          // '<S366>/Rate Transition3'
  real32_T RateTransition1_c;          // '<S366>/Rate Transition1'
  real32_T RateTransition1_d;          // '<S364>/Rate Transition1'
  real32_T RateTransition1_o;          // '<S365>/Rate Transition1'
  real32_T ParamStep;
  real32_T ParamStep_c;
  real32_T ParamStep_k;
  real32_T Integrator_c;               // '<S200>/Integrator'
  real32_T roll_g;                     // '<S55>/Sum1'
  real32_T Gain7;                      // '<S4>/Gain7'
  real32_T Gain4;                      // '<S4>/Gain4'
  real32_T Gain5;                      // '<S4>/Gain5'
  real32_T Gain6;                      // '<S4>/Gain6'
  real32_T w_radps;                    // '<S5>/MATLAB Function'
  real32_T p_j;                        // '<S165>/Gain'
  real32_T q_c;                        // '<S165>/Product2'
  real32_T r_o;                        // '<S165>/Bias'
  real32_T d_n;                        // '<S165>/Add1'
  real32_T Product1_e;                 // '<S4>/Product1'
  real32_T TSamp_k;                    // '<S161>/TSamp'
  real32_T Saturation5;                // '<S4>/Saturation5'
  real32_T Gain8;                      // '<S4>/Gain8'
  real32_T Product2_e;                 // '<S4>/Product2'
  real32_T ReadParameter12_o1;         // '<S5>/Read Parameter12'
  real32_T ReadParameter13_o1;         // '<S5>/Read Parameter13'
  real32_T ReadParameter14_o1;         // '<S5>/Read Parameter14'
  real32_T ReadParameter15_o1;         // '<S5>/Read Parameter15'
  real32_T ReadParameter16_o1;         // '<S5>/Read Parameter16'
  real32_T ReadParameter17_o1;         // '<S5>/Read Parameter17'
  real32_T ReadParameter18_o1;         // '<S5>/Read Parameter18'
  real32_T ReadParameter19_o1;         // '<S5>/Read Parameter19'
  real32_T ReadParameter29_o1;         // '<S5>/Read Parameter29'
  real32_T ReadParameter30_o1;         // '<S5>/Read Parameter30'
  real32_T ReadParameter31_o1;         // '<S5>/Read Parameter31'
  real32_T ReadParameter32_o1;         // '<S5>/Read Parameter32'
  real32_T ReadParameter33_o1;         // '<S5>/Read Parameter33'
  real32_T ReadParameter34_o1;         // '<S5>/Read Parameter34'
  real32_T ReadParameter35_o1;         // '<S5>/Read Parameter35'
  real32_T ReadParameter36_o1;         // '<S5>/Read Parameter36'
  real32_T ReadParameter37_o1;         // '<S5>/Read Parameter37'
  real32_T ReadParameter41_o1;         // '<S5>/Read Parameter41'
  real32_T ReadParameter42_o1;         // '<S5>/Read Parameter42'
  real32_T V;
  real32_T absx;
  real32_T roll;                       // '<S365>/Sum1'
  real32_T p;                          // '<S534>/Gain'
  real32_T q;                          // '<S534>/Product2'
  real32_T r_c;                        // '<S534>/Bias'
  real32_T d_b;                        // '<S534>/Add1'
  real32_T Sum5_nz;                    // '<S365>/Sum5'
  real32_T TSamp;                      // '<S530>/TSamp'
  real32_T Product2_gt;                // '<S358>/Product2'
  real32_T Product_p;                  // '<S238>/Product'
  real32_T Product2_m;                 // '<S238>/Product2'
  real32_T Product4;                   // '<S238>/Product4'
  real32_T Sum_oj;                     // '<S357>/Sum'
  real32_T Product1;                   // '<S357>/Product1'
  real32_T TSamp_oi;                   // '<S241>/TSamp'
  real32_T Diff_k;                     // '<S241>/Diff'
  real32_T TSamp_d;                    // '<S242>/TSamp'
  real32_T Subtract;                   // '<S9>/Subtract'
  real32_T H;                          // '<S9>/MATLAB Function'
  real32_T FilterCoefficient;          // '<S290>/Filter Coefficient'
  real32_T Sum_n;                      // '<S296>/Sum'
  real32_T s;                          // '<S9>/MATLAB Function3'
  real32_T R;                          // '<S9>/MATLAB Function4'
  real32_T Saturation2;                // '<S9>/Saturation2'
  real32_T Switch_e;                   // '<S2>/Switch'
  real32_T roll_h;                     // '<S364>/Sum1'
  real32_T Product2_h;                 // '<S476>/Product2'
  real32_T p_e;                        // '<S477>/Gain'
  real32_T q_e;                        // '<S477>/Product2'
  real32_T r_a;                        // '<S477>/Bias'
  real32_T d_m;                        // '<S477>/Add1'
  real32_T TSamp_c;                    // '<S473>/TSamp'
  real32_T Sum5;                       // '<S364>/Sum5'
  real32_T Product2_mi;                // '<S590>/Product2'
  real32_T p_i;                        // '<S591>/Gain'
  real32_T q_n;                        // '<S591>/Product2'
  real32_T r_h;                        // '<S591>/Bias'
  real32_T d_e;                        // '<S591>/Add1'
  real32_T TSamp_a;                    // '<S587>/TSamp'
  real32_T Sum_g;                      // '<S10>/Sum'
  real32_T rtb_TSamp_o_p;
  real32_T rtb_omega_phi_idx_1;
  real32_T rtb_omega_phi_idx_2;
  real32_T rtb_TSamp_o_idx_1;
  real32_T f;
  real32_T anrm;
  int32_T ParamStep_cv;
  int32_T ParamStep_f;
  int32_T ParamStep_g;
  int32_T ParamStep_g1;
  int32_T ParamStep_m;
  int32_T ParamStep_n;
  int32_T i;
  uint32_T u;
  uint32_T u1;
  uint32_T u2;
  uint32_T u3;
  uint32_T u4;
  uint32_T u5;
  uint16_T rc_ctrl_switch;             // '<Root>/Rate Transition'
  uint16_T rc_inject_failure;          // '<Root>/Rate Transition'
  boolean_T RateTransition6_h;         // '<S365>/Rate Transition6'
  boolean_T RateTransition16;          // '<S9>/Rate Transition16'
  boolean_T RateTransition15;          // '<S9>/Rate Transition15'
  boolean_T RateTransition6_a;         // '<S364>/Rate Transition6'
  boolean_T RateTransition6_o;         // '<S366>/Rate Transition6'
  boolean_T VehicleStatus_flag_armed;  // '<Root>/Rate Transition2'
  boolean_T VehicleStatus_flag_kill;   // '<Root>/Rate Transition2'
  B_SourceBlock_FLIGHT_Hexacopt_T SourceBlock_p;// '<S226>/SourceBlock'
  B_SourceBlock_FLIGHT_Hexacopt_T SourceBlock_l;// '<S226>/SourceBlock'
  B_PX4Timestamp_FLIGHT_Hexac_l_T PX4Timestamp_k;// '<S25>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexac_a_T PX4Timestamp_e;// '<S24>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexacop_T PX4Timestamp_pn;// '<S3>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexac_l_T PX4Timestamp_p;// '<S25>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexac_l_T PX4Timestamp_j;// '<S25>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexac_a_T PX4Timestamp_c;// '<S24>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexacop_T PX4Timestamp;// '<S3>/PX4 Timestamp'
};

// Block states (default storage) for system '<Root>'
struct DW_FLIGHT_Hexacopter_V2_T {
  px4_internal_block_getPX4Abso_T obj; // '<S4>/PX4 Timestamp'
  px4_internal_block_Subscriber_T obj_i;// '<S236>/SourceBlock'
  px4_internal_block_Subscriber_T obj_l;// '<S228>/SourceBlock'
  px4_internal_block_Subscriber_T obj_a;// '<S227>/SourceBlock'
  px4_internal_block_Subscriber_T obj_m;// '<S223>/SourceBlock'
  px4_internal_block_Subscriber_T obj_n;// '<S221>/SourceBlock'
  px4_internal_block_PWM_FLIGHT_T obj_md;// '<S1>/PX4 PWM Output'
  px4_internal_block_ParameterU_T obj_c;// '<S5>/read_mc_rollrate_p'
  px4_internal_block_ParameterU_T obj_ai;// '<S5>/Read Parameter9'
  px4_internal_block_ParameterU_T obj_f;// '<S5>/Read Parameter8'
  px4_internal_block_ParameterU_T obj_fj;// '<S5>/Read Parameter7'
  px4_internal_block_ParameterU_T obj_p;// '<S5>/Read Parameter6'
  px4_internal_block_ParameterU_T obj_ia;// '<S5>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_fy;// '<S5>/Read Parameter42'
  px4_internal_block_ParameterU_T obj_h;// '<S5>/Read Parameter41'
  px4_internal_block_ParameterU_T obj_pn;// '<S5>/Read Parameter40'
  px4_internal_block_ParameterU_T obj_c1;// '<S5>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_g;// '<S5>/Read Parameter39'
  px4_internal_block_ParameterU_T obj_e;// '<S5>/Read Parameter38'
  px4_internal_block_ParameterU_T obj_pi;// '<S5>/Read Parameter37'
  px4_internal_block_ParameterU_T obj_ln;// '<S5>/Read Parameter36'
  px4_internal_block_ParameterU_T obj_b;// '<S5>/Read Parameter35'
  px4_internal_block_ParameterU_T obj_o;// '<S5>/Read Parameter34'
  px4_internal_block_ParameterU_T obj_bd;// '<S5>/Read Parameter33'
  px4_internal_block_ParameterU_T obj_lv;// '<S5>/Read Parameter32'
  px4_internal_block_ParameterU_T obj_as;// '<S5>/Read Parameter31'
  px4_internal_block_ParameterU_T obj_mo;// '<S5>/Read Parameter30'
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
  px4_internal_block_ParameterU_T obj_nn;// '<S5>/Read Parameter15'
  px4_internal_block_ParameterU_T obj_fd;// '<S5>/Read Parameter14'
  px4_internal_block_ParameterU_T obj_pf;// '<S5>/Read Parameter13'
  px4_internal_block_ParameterU_T obj_jo;// '<S5>/Read Parameter12'
  px4_internal_block_ParameterU_T obj_jk;// '<S5>/Read Parameter11'
  px4_internal_block_ParameterU_T obj_bq;// '<S5>/Read Parameter10'
  px4_internal_block_ParameterU_T obj_l4;// '<S5>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_jf;// '<S5>/Read Parameter'
  px4_internal_block_ParameterU_T obj_ic5;// '<S12>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_jg;// '<S12>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_hi;// '<S12>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_ps;// '<S12>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_oe;// '<S12>/Read Parameter13'
  px4_internal_block_ParameterU_T obj_aw;// '<S12>/Read Parameter1'
  px4_internal_block_Publisher__T obj_pm;// '<S42>/SinkBlock'
  px4_internal_block_Publisher__T obj_nf;// '<S40>/SinkBlock'
  px4_internal_block_Publisher__T obj_k;// '<S38>/SinkBlock'
  px4_internal_block_Publisher__T obj_mp;// '<S36>/SinkBlock'
  px4_internal_block_Publisher__T obj_m1;// '<S34>/SinkBlock'
  px4_internal_block_Publisher__T obj_fe;// '<S32>/SinkBlock'
  real_T start_time_usec;              // '<S4>/MATLAB Function1'
  real32_T Integrator_DSTATE;          // '<S569>/Integrator'
  real32_T UnitDelay1_DSTATE;          // '<S533>/Unit Delay1'
  real32_T UD_DSTATE;                  // '<S530>/UD'
  real32_T UD_DSTATE_h[3];             // '<S243>/UD'
  real32_T UnitDelay_DSTATE;           // '<S357>/Unit Delay'
  real32_T UD_DSTATE_o;                // '<S241>/UD'
  real32_T UD_DSTATE_e;                // '<S242>/UD'
  real32_T Filter_DSTATE;              // '<S282>/Filter'
  real32_T Integrator_DSTATE_h;        // '<S339>/Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE;// '<S9>/Discrete-Time Integrator'
  real32_T Integrator_DSTATE_c;        // '<S512>/Integrator'
  real32_T UnitDelay1_DSTATE_k;        // '<S476>/Unit Delay1'
  real32_T UD_DSTATE_oi;               // '<S473>/UD'
  real32_T Integrator_DSTATE_o;        // '<S626>/Integrator'
  real32_T UnitDelay1_DSTATE_kh;       // '<S590>/Unit Delay1'
  real32_T UD_DSTATE_k;                // '<S587>/UD'
  real32_T UnitDelay2_DSTATE;          // '<S590>/Unit Delay2'
  real32_T UnitDelay2_DSTATE_l;        // '<S476>/Unit Delay2'
  real32_T UnitDelay2_DSTATE_h;        // '<S533>/Unit Delay2'
  real32_T Integrator_DSTATE_l;        // '<S200>/Integrator'
  real32_T UnitDelay1_DSTATE_i;        // '<S164>/Unit Delay1'
  real32_T UD_DSTATE_a;                // '<S161>/UD'
  real32_T DiscreteTimeIntegrator_DSTATE_c;// '<S4>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator1_DSTATE;// '<S4>/Discrete-Time Integrator1'
  real32_T UnitDelay2_DSTATE_f;        // '<S164>/Unit Delay2'
  real32_T RateTransition4_Buffer0;    // '<S10>/Rate Transition4'
  real32_T RateTransition_Buffer0;     // '<S365>/Rate Transition'
  real32_T RateTransition4_Buffer0_e;  // '<S365>/Rate Transition4'
  real32_T RateTransition2_Buffer0;    // '<S365>/Rate Transition2'
  real32_T RateTransition3_Buffer0;    // '<S365>/Rate Transition3'
  real32_T RateTransition2_Buffer0_d[3];// '<S9>/Rate Transition2'
  real32_T RateTransition4_Buffer0_d;  // '<S9>/Rate Transition4'
  real32_T RateTransition5_Buffer0;    // '<S9>/Rate Transition5'
  real32_T RateTransition6_Buffer0;    // '<S9>/Rate Transition6'
  real32_T RateTransition9_Buffer0;    // '<S9>/Rate Transition9'
  real32_T RateTransition10_Buffer0;   // '<S9>/Rate Transition10'
  real32_T RateTransition11_Buffer0;   // '<S9>/Rate Transition11'
  real32_T RateTransition17_Buffer0;   // '<S9>/Rate Transition17'
  real32_T RateTransition1_Buffer0;    // '<S9>/Rate Transition1'
  real32_T RateTransition7_Buffer0;    // '<S9>/Rate Transition7'
  real32_T RateTransition8_Buffer0;    // '<S9>/Rate Transition8'
  real32_T RateTransition12_Buffer0;   // '<S9>/Rate Transition12'
  real32_T RateTransition13_Buffer0;   // '<S9>/Rate Transition13'
  real32_T RateTransition14_Buffer0;   // '<S9>/Rate Transition14'
  real32_T RateTransition_Buffer0_c;   // '<S364>/Rate Transition'
  real32_T RateTransition4_Buffer0_k;  // '<S364>/Rate Transition4'
  real32_T RateTransition2_Buffer0_l;  // '<S364>/Rate Transition2'
  real32_T RateTransition3_Buffer0_p;  // '<S364>/Rate Transition3'
  real32_T RateTransition_Buffer0_h;   // '<S10>/Rate Transition'
  real32_T RateTransition1_Buffer0_g;  // '<S10>/Rate Transition1'
  real32_T RateTransition_Buffer0_hv;  // '<S366>/Rate Transition'
  real32_T RateTransition4_Buffer0_c;  // '<S366>/Rate Transition4'
  real32_T RateTransition2_Buffer0_dg; // '<S366>/Rate Transition2'
  real32_T RateTransition3_Buffer0_d;  // '<S366>/Rate Transition3'
  real32_T RateTransition1_Buffer0_m;  // '<S366>/Rate Transition1'
  real32_T RateTransition1_Buffer0_l;  // '<S364>/Rate Transition1'
  real32_T RateTransition1_Buffer0_l4; // '<S365>/Rate Transition1'
  real32_T PrevY[2];                   // '<S4>/Rate Limiter'
  uint16_T RateTransition_8_Buffer0;   // '<Root>/Rate Transition'
  uint16_T RateTransition_4_Buffer0;   // '<Root>/Rate Transition'
  int8_T Integrator_PrevResetState;    // '<S569>/Integrator'
  int8_T Integrator_PrevResetState_h;  // '<S339>/Integrator'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S9>/Discrete-Time Integrator'
  int8_T Integrator_PrevResetState_hx; // '<S512>/Integrator'
  int8_T Integrator_PrevResetState_hd; // '<S626>/Integrator'
  int8_T Integrator_PrevResetState_l;  // '<S200>/Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_l;// '<S4>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator1_PrevRes;// '<S4>/Discrete-Time Integrator1'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S4>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;// '<S4>/Discrete-Time Integrator1'
  boolean_T RateTransition6_Buffer0_a; // '<S365>/Rate Transition6'
  boolean_T RateTransition16_Buffer0;  // '<S9>/Rate Transition16'
  boolean_T RateTransition15_Buffer0;  // '<S9>/Rate Transition15'
  boolean_T RateTransition6_Buffer0_i; // '<S364>/Rate Transition6'
  boolean_T RateTransition6_Buffer0_o; // '<S366>/Rate Transition6'
  boolean_T RateTransition2_16_Buffer0;// '<Root>/Rate Transition2'
  boolean_T RateTransition2_17_Buffer0;// '<Root>/Rate Transition2'
  DW_SourceBlock_FLIGHT_Hexacop_T SourceBlock_p;// '<S226>/SourceBlock'
  DW_SourceBlock_FLIGHT_Hexacop_T SourceBlock_l;// '<S226>/SourceBlock'
  DW_PX4Timestamp_FLIGHT_Hexa_j_T PX4Timestamp_k;// '<S25>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexa_o_T PX4Timestamp_e;// '<S24>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexaco_T PX4Timestamp_pn;// '<S3>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexa_j_T PX4Timestamp_p;// '<S25>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexa_j_T PX4Timestamp_j;// '<S25>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexa_o_T PX4Timestamp_c;// '<S24>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexaco_T PX4Timestamp;// '<S3>/PX4 Timestamp'
};

// Parameters (default storage)
struct P_FLIGHT_Hexacopter_V2_T_ {
  real_T d2r;                          // Variable: d2r
                                          //  Referenced by: '<S4>/Rate Limiter'

  real32_T MAX_CONTROL_ANGLE_PITCH;    // Variable: MAX_CONTROL_ANGLE_PITCH
                                          //  Referenced by: '<S4>/Gain5'

  real32_T MAX_CONTROL_ANGLE_RATE_Y;   // Variable: MAX_CONTROL_ANGLE_RATE_Y
                                          //  Referenced by: '<S4>/Gain6'

  real32_T MAX_CONTROL_ANGLE_ROLL;     // Variable: MAX_CONTROL_ANGLE_ROLL
                                          //  Referenced by: '<S4>/Gain4'

  real32_T DiscretePIDController1_D; // Mask Parameter: DiscretePIDController1_D
                                        //  Referenced by: '<S280>/Derivative Gain'

  real32_T DiscretePIDController2_I; // Mask Parameter: DiscretePIDController2_I
                                        //  Referenced by: '<S336>/Integral Gain'

  real32_T DiscreteDerivative2_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative2_ICPrevScale
                                 //  Referenced by: '<S530>/UD'

  real32_T DiscreteDerivative2_ICPrevSca_e;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_e
                                 //  Referenced by: '<S243>/UD'

  real32_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S241>/UD'

  real32_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: '<S242>/UD'

  real32_T DiscreteDerivative2_ICPrevSca_k;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_k
                                 //  Referenced by: '<S473>/UD'

  real32_T DiscreteDerivative2_ICPrevSca_f;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_f
                                 //  Referenced by: '<S587>/UD'

  real32_T DiscreteDerivative2_ICPrevSca_n;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_n
                                 //  Referenced by: '<S161>/UD'

  real32_T DiscretePIDController1_InitialC;
                              // Mask Parameter: DiscretePIDController1_InitialC
                                 //  Referenced by: '<S282>/Filter'

  real32_T pid_ctrl_rollrate_InitialCondit;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCondit
                                 //  Referenced by: '<S569>/Integrator'

  real32_T DiscretePIDController2_InitialC;
                              // Mask Parameter: DiscretePIDController2_InitialC
                                 //  Referenced by: '<S339>/Integrator'

  real32_T pid_ctrl_rollrate_InitialCond_l;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCond_l
                                 //  Referenced by: '<S512>/Integrator'

  real32_T pid_ctrl_rollrate_InitialCond_p;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCond_p
                                 //  Referenced by: '<S626>/Integrator'

  real32_T pid_ctrl_rollrate_InitialCon_pr;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCon_pr
                                 //  Referenced by: '<S200>/Integrator'

  real32_T DiscretePIDController1_N; // Mask Parameter: DiscretePIDController1_N
                                        //  Referenced by: '<S290>/Filter Coefficient'

  real32_T DiscretePIDController1_P; // Mask Parameter: DiscretePIDController1_P
                                        //  Referenced by: '<S292>/Proportional Gain'

  real32_T CompareToConstant6_const; // Mask Parameter: CompareToConstant6_const
                                        //  Referenced by: '<S48>/Constant'

  real32_T CompareToConstant5_const; // Mask Parameter: CompareToConstant5_const
                                        //  Referenced by: '<S47>/Constant'

  uint16_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S11>/Constant'

  uint16_T CompareToConstant_const_a;
                                    // Mask Parameter: CompareToConstant_const_a
                                       //  Referenced by: '<S15>/Constant'

  uint16_T CompareToConstant1_const; // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: '<S43>/Constant'

  uint16_T CompareToConstant2_const; // Mask Parameter: CompareToConstant2_const
                                        //  Referenced by: '<S44>/Constant'

  uint16_T CompareToConstant4_const; // Mask Parameter: CompareToConstant4_const
                                        //  Referenced by: '<S46>/Constant'

  uint16_T CompareToConstant3_const; // Mask Parameter: CompareToConstant3_const
                                        //  Referenced by: '<S45>/Constant'

  uint16_T CompareToConstant_const_o;
                                    // Mask Parameter: CompareToConstant_const_o
                                       //  Referenced by: '<S239>/Constant'

  uint16_T CompareToConstant1_const_j;
                                   // Mask Parameter: CompareToConstant1_const_j
                                      //  Referenced by: '<S240>/Constant'

  uint16_T CompareToConstant_const_j;
                                    // Mask Parameter: CompareToConstant_const_j
                                       //  Referenced by: '<S359>/Constant'

  uint16_T CompareToConstant1_const_p;
                                   // Mask Parameter: CompareToConstant1_const_p
                                      //  Referenced by: '<S360>/Constant'

  uint16_T CompareToConstant2_const_p;
                                   // Mask Parameter: CompareToConstant2_const_p
                                      //  Referenced by: '<S361>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0;// Computed Parameter: Out1_Y0
                                            //  Referenced by: '<S234>/Out1'

  px4_Bus_vehicle_local_position Constant_Value;// Computed Parameter: Constant_Value
                                                   //  Referenced by: '<S228>/Constant'

  px4_Bus_vehicle_attitude_smc_setpoint Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                            //  Referenced by: '<S37>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0_c;  // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S237>/Out1'

  px4_Bus_vehicle_odometry Constant_Value_j;// Computed Parameter: Constant_Value_j
                                               //  Referenced by: '<S236>/Constant'

  px4_Bus_actuator_motors Constant_Value_e;// Computed Parameter: Constant_Value_e
                                              //  Referenced by: '<S39>/Constant'

  px4_Bus_input_rc Out1_Y0_h;          // Computed Parameter: Out1_Y0_h
                                          //  Referenced by: '<S222>/Out1'

  px4_Bus_input_rc Constant_Value_l;   // Computed Parameter: Constant_Value_l
                                          //  Referenced by: '<S221>/Constant'

  px4_Bus_vehicle_status Out1_Y0_e;    // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S233>/Out1'

  px4_Bus_vehicle_status Constant_Value_k;// Computed Parameter: Constant_Value_k
                                             //  Referenced by: '<S227>/Constant'

  px4_Bus_vehicle_local_position_setpoint Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                              //  Referenced by: '<S41>/Constant'

  px4_Bus_vehicle_attitude_setpoint Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                        //  Referenced by: '<S33>/Constant'

  px4_Bus_vehicle_angular_velocity Out1_Y0_a;// Computed Parameter: Out1_Y0_a
                                                //  Referenced by: '<S224>/Out1'

  px4_Bus_vehicle_angular_velocity Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                       //  Referenced by: '<S223>/Constant'

  px4_Bus_vehicle_rates_setpoint Constant_Value_ek;// Computed Parameter: Constant_Value_ek
                                                      //  Referenced by: '<S35>/Constant'

  px4_Bus_actuator_controls_status Constant_Value_l5;// Computed Parameter: Constant_Value_l5
                                                        //  Referenced by: '<S31>/Constant'

  px4_Bus_actuator_armed Out1_Y0_p;    // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S232>/Out1'

  px4_Bus_actuator_armed Out1_Y0_g;    // Computed Parameter: Out1_Y0_g
                                          //  Referenced by: '<S235>/Out1'

  px4_Bus_actuator_armed Constant_Value_f;// Computed Parameter: Constant_Value_f
                                             //  Referenced by: '<S226>/Constant'

  px4_Bus_actuator_armed Constant_Value_a;// Computed Parameter: Constant_Value_a
                                             //  Referenced by: '<S229>/Constant'

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

  real_T Constant_Value_gr;            // Expression: 1
                                          //  Referenced by: '<S238>/Constant'

  real_T Constant1_Value_f;            // Expression: 1
                                          //  Referenced by: '<S238>/Constant1'

  real_T Constant2_Value_n;            // Expression: 1
                                          //  Referenced by: '<S238>/Constant2'

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

  real_T Constant_Value_k3;            // Expression: 1094
                                          //  Referenced by: '<S4>/Constant'

  real_T Gain_Gain_b;                  // Expression: 1/800
                                          //  Referenced by: '<S4>/Gain'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S10>/Gain1'

  real32_T Gain_Gain_o;                // Computed Parameter: Gain_Gain_o
                                          //  Referenced by: '<S10>/Gain'

  real32_T RateTransition4_InitialConditio;
                          // Computed Parameter: RateTransition4_InitialConditio
                             //  Referenced by: '<S10>/Rate Transition4'

  real32_T RateTransition_InitialCondition;
                          // Computed Parameter: RateTransition_InitialCondition
                             //  Referenced by: '<S365>/Rate Transition'

  real32_T RateTransition4_InitialCondit_l;
                          // Computed Parameter: RateTransition4_InitialCondit_l
                             //  Referenced by: '<S365>/Rate Transition4'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S569>/Integrator'

  real32_T RateTransition2_InitialConditio;
                          // Computed Parameter: RateTransition2_InitialConditio
                             //  Referenced by: '<S365>/Rate Transition2'

  real32_T UnitDelay1_InitialCondition;
                              // Computed Parameter: UnitDelay1_InitialCondition
                                 //  Referenced by: '<S533>/Unit Delay1'

  real32_T RateTransition3_InitialConditio;
                          // Computed Parameter: RateTransition3_InitialConditio
                             //  Referenced by: '<S365>/Rate Transition3'

  real32_T tau_Gain;                   // Computed Parameter: tau_Gain
                                          //  Referenced by: '<S533>/tau'

  real32_T Bias_Bias;                  // Computed Parameter: Bias_Bias
                                          //  Referenced by: '<S534>/Bias'

  real32_T Gain_Gain_f5;               // Computed Parameter: Gain_Gain_f5
                                          //  Referenced by: '<S534>/Gain'

  real32_T TSamp_WtEt;                 // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S530>/TSamp'

  real32_T RateTransition2_InitialCondit_h;
                          // Computed Parameter: RateTransition2_InitialCondit_h
                             //  Referenced by: '<S9>/Rate Transition2'

  real32_T TSamp_WtEt_m;               // Computed Parameter: TSamp_WtEt_m
                                          //  Referenced by: '<S243>/TSamp'

  real32_T RateTransition4_InitialCondit_m;
                          // Computed Parameter: RateTransition4_InitialCondit_m
                             //  Referenced by: '<S9>/Rate Transition4'

  real32_T RateTransition5_InitialConditio;
                          // Computed Parameter: RateTransition5_InitialConditio
                             //  Referenced by: '<S9>/Rate Transition5'

  real32_T RateTransition6_InitialConditio;
                          // Computed Parameter: RateTransition6_InitialConditio
                             //  Referenced by: '<S9>/Rate Transition6'

  real32_T RateTransition9_InitialConditio;
                          // Computed Parameter: RateTransition9_InitialConditio
                             //  Referenced by: '<S9>/Rate Transition9'

  real32_T RateTransition10_InitialConditi;
                          // Computed Parameter: RateTransition10_InitialConditi
                             //  Referenced by: '<S9>/Rate Transition10'

  real32_T RateTransition11_InitialConditi;
                          // Computed Parameter: RateTransition11_InitialConditi
                             //  Referenced by: '<S9>/Rate Transition11'

  real32_T RateTransition17_InitialConditi;
                          // Computed Parameter: RateTransition17_InitialConditi
                             //  Referenced by: '<S9>/Rate Transition17'

  real32_T tau_Gain_f;                 // Computed Parameter: tau_Gain_f
                                          //  Referenced by: '<S357>/tau'

  real32_T Bias_Bias_h;                // Computed Parameter: Bias_Bias_h
                                          //  Referenced by: '<S358>/Bias'

  real32_T RateTransition1_InitialConditio;
                          // Computed Parameter: RateTransition1_InitialConditio
                             //  Referenced by: '<S9>/Rate Transition1'

  real32_T UnitDelay_InitialCondition;
                               // Computed Parameter: UnitDelay_InitialCondition
                                  //  Referenced by: '<S357>/Unit Delay'

  real32_T TSamp_WtEt_p;               // Computed Parameter: TSamp_WtEt_p
                                          //  Referenced by: '<S241>/TSamp'

  real32_T TSamp_WtEt_l;               // Computed Parameter: TSamp_WtEt_l
                                          //  Referenced by: '<S242>/TSamp'

  real32_T RateTransition7_InitialConditio;
                          // Computed Parameter: RateTransition7_InitialConditio
                             //  Referenced by: '<S9>/Rate Transition7'

  real32_T RateTransition8_InitialConditio;
                          // Computed Parameter: RateTransition8_InitialConditio
                             //  Referenced by: '<S9>/Rate Transition8'

  real32_T RateTransition12_InitialConditi;
                          // Computed Parameter: RateTransition12_InitialConditi
                             //  Referenced by: '<S9>/Rate Transition12'

  real32_T RateTransition13_InitialConditi;
                          // Computed Parameter: RateTransition13_InitialConditi
                             //  Referenced by: '<S9>/Rate Transition13'

  real32_T RateTransition14_InitialConditi;
                          // Computed Parameter: RateTransition14_InitialConditi
                             //  Referenced by: '<S9>/Rate Transition14'

  real32_T Filter_gainval;             // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S282>/Filter'

  real32_T Integrator_gainval_c;     // Computed Parameter: Integrator_gainval_c
                                        //  Referenced by: '<S339>/Integrator'

  real32_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S9>/Discrete-Time Integrator'

  real32_T DiscreteTimeIntegrator_IC;
                                // Computed Parameter: DiscreteTimeIntegrator_IC
                                   //  Referenced by: '<S9>/Discrete-Time Integrator'

  real32_T Saturation2_UpperSat;     // Computed Parameter: Saturation2_UpperSat
                                        //  Referenced by: '<S9>/Saturation2'

  real32_T Saturation2_LowerSat;     // Computed Parameter: Saturation2_LowerSat
                                        //  Referenced by: '<S9>/Saturation2'

  real32_T RateTransition_InitialConditi_n;
                          // Computed Parameter: RateTransition_InitialConditi_n
                             //  Referenced by: '<S364>/Rate Transition'

  real32_T RateTransition4_InitialCondit_d;
                          // Computed Parameter: RateTransition4_InitialCondit_d
                             //  Referenced by: '<S364>/Rate Transition4'

  real32_T Integrator_gainval_d;     // Computed Parameter: Integrator_gainval_d
                                        //  Referenced by: '<S512>/Integrator'

  real32_T RateTransition2_InitialCondit_p;
                          // Computed Parameter: RateTransition2_InitialCondit_p
                             //  Referenced by: '<S364>/Rate Transition2'

  real32_T UnitDelay1_InitialCondition_h;
                            // Computed Parameter: UnitDelay1_InitialCondition_h
                               //  Referenced by: '<S476>/Unit Delay1'

  real32_T RateTransition3_InitialCondit_m;
                          // Computed Parameter: RateTransition3_InitialCondit_m
                             //  Referenced by: '<S364>/Rate Transition3'

  real32_T tau_Gain_d;                 // Computed Parameter: tau_Gain_d
                                          //  Referenced by: '<S476>/tau'

  real32_T Bias_Bias_o;                // Computed Parameter: Bias_Bias_o
                                          //  Referenced by: '<S477>/Bias'

  real32_T Gain_Gain_bi;               // Computed Parameter: Gain_Gain_bi
                                          //  Referenced by: '<S477>/Gain'

  real32_T TSamp_WtEt_g;               // Computed Parameter: TSamp_WtEt_g
                                          //  Referenced by: '<S473>/TSamp'

  real32_T RateTransition_InitialConditi_c;
                          // Computed Parameter: RateTransition_InitialConditi_c
                             //  Referenced by: '<S10>/Rate Transition'

  real32_T RateTransition1_InitialCondit_e;
                          // Computed Parameter: RateTransition1_InitialCondit_e
                             //  Referenced by: '<S10>/Rate Transition1'

  real32_T RateTransition_InitialConditi_m;
                          // Computed Parameter: RateTransition_InitialConditi_m
                             //  Referenced by: '<S366>/Rate Transition'

  real32_T RateTransition4_InitialCondit_a;
                          // Computed Parameter: RateTransition4_InitialCondit_a
                             //  Referenced by: '<S366>/Rate Transition4'

  real32_T Integrator_gainval_b;     // Computed Parameter: Integrator_gainval_b
                                        //  Referenced by: '<S626>/Integrator'

  real32_T RateTransition2_InitialCondit_d;
                          // Computed Parameter: RateTransition2_InitialCondit_d
                             //  Referenced by: '<S366>/Rate Transition2'

  real32_T UnitDelay1_InitialCondition_c;
                            // Computed Parameter: UnitDelay1_InitialCondition_c
                               //  Referenced by: '<S590>/Unit Delay1'

  real32_T RateTransition3_InitialCondit_o;
                          // Computed Parameter: RateTransition3_InitialCondit_o
                             //  Referenced by: '<S366>/Rate Transition3'

  real32_T tau_Gain_m;                 // Computed Parameter: tau_Gain_m
                                          //  Referenced by: '<S590>/tau'

  real32_T Bias_Bias_g;                // Computed Parameter: Bias_Bias_g
                                          //  Referenced by: '<S591>/Bias'

  real32_T Gain_Gain_a;                // Computed Parameter: Gain_Gain_a
                                          //  Referenced by: '<S591>/Gain'

  real32_T TSamp_WtEt_ma;              // Computed Parameter: TSamp_WtEt_ma
                                          //  Referenced by: '<S587>/TSamp'

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
                                          //  Referenced by: '<S591>/Bias1'

  real32_T Gain1_Gain_d;               // Computed Parameter: Gain1_Gain_d
                                          //  Referenced by: '<S590>/Gain1'

  real32_T UnitDelay2_InitialCondition;
                              // Computed Parameter: UnitDelay2_InitialCondition
                                 //  Referenced by: '<S590>/Unit Delay2'

  real32_T RateTransition1_InitialCondit_d;
                          // Computed Parameter: RateTransition1_InitialCondit_d
                             //  Referenced by: '<S366>/Rate Transition1'

  real32_T Bias1_Bias_k;               // Computed Parameter: Bias1_Bias_k
                                          //  Referenced by: '<S477>/Bias1'

  real32_T Gain1_Gain_m;               // Computed Parameter: Gain1_Gain_m
                                          //  Referenced by: '<S476>/Gain1'

  real32_T UnitDelay2_InitialCondition_b;
                            // Computed Parameter: UnitDelay2_InitialCondition_b
                               //  Referenced by: '<S476>/Unit Delay2'

  real32_T RateTransition1_InitialCondit_f;
                          // Computed Parameter: RateTransition1_InitialCondit_f
                             //  Referenced by: '<S364>/Rate Transition1'

  real32_T Gain_Gain_ar;               // Computed Parameter: Gain_Gain_ar
                                          //  Referenced by: '<S358>/Gain'

  real32_T Bias1_Bias_ka;              // Computed Parameter: Bias1_Bias_ka
                                          //  Referenced by: '<S358>/Bias1'

  real32_T Bias1_Bias_a;               // Computed Parameter: Bias1_Bias_a
                                          //  Referenced by: '<S534>/Bias1'

  real32_T Gain1_Gain_i;               // Computed Parameter: Gain1_Gain_i
                                          //  Referenced by: '<S533>/Gain1'

  real32_T UnitDelay2_InitialCondition_e;
                            // Computed Parameter: UnitDelay2_InitialCondition_e
                               //  Referenced by: '<S533>/Unit Delay2'

  real32_T RateTransition1_InitialCondit_p;
                          // Computed Parameter: RateTransition1_InitialCondit_p
                             //  Referenced by: '<S365>/Rate Transition1'

  real32_T Gain_Gain_az;               // Computed Parameter: Gain_Gain_az
                                          //  Referenced by: '<S56>/Gain'

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

  real32_T Saturation2_UpperSat_c; // Computed Parameter: Saturation2_UpperSat_c
                                      //  Referenced by: '<S4>/Saturation2'

  real32_T Saturation2_LowerSat_h; // Computed Parameter: Saturation2_LowerSat_h
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

  real32_T Integrator_gainval_e;     // Computed Parameter: Integrator_gainval_e
                                        //  Referenced by: '<S200>/Integrator'

  real32_T UnitDelay1_InitialCondition_e;
                            // Computed Parameter: UnitDelay1_InitialCondition_e
                               //  Referenced by: '<S164>/Unit Delay1'

  real32_T tau_Gain_g;                 // Computed Parameter: tau_Gain_g
                                          //  Referenced by: '<S164>/tau'

  real32_T Bias_Bias_n;                // Computed Parameter: Bias_Bias_n
                                          //  Referenced by: '<S165>/Bias'

  real32_T Gain_Gain_oj;               // Computed Parameter: Gain_Gain_oj
                                          //  Referenced by: '<S165>/Gain'

  real32_T TSamp_WtEt_n;               // Computed Parameter: TSamp_WtEt_n
                                          //  Referenced by: '<S161>/TSamp'

  real32_T Saturation5_UpperSat;     // Computed Parameter: Saturation5_UpperSat
                                        //  Referenced by: '<S4>/Saturation5'

  real32_T Saturation5_LowerSat;     // Computed Parameter: Saturation5_LowerSat
                                        //  Referenced by: '<S4>/Saturation5'

  real32_T DeadZone6_Start;            // Computed Parameter: DeadZone6_Start
                                          //  Referenced by: '<S4>/Dead Zone6'

  real32_T DeadZone6_End;              // Computed Parameter: DeadZone6_End
                                          //  Referenced by: '<S4>/Dead Zone6'

  real32_T Saturation9_UpperSat;     // Computed Parameter: Saturation9_UpperSat
                                        //  Referenced by: '<S4>/Saturation9'

  real32_T Saturation9_LowerSat;     // Computed Parameter: Saturation9_LowerSat
                                        //  Referenced by: '<S4>/Saturation9'

  real32_T Gain8_Gain;                 // Computed Parameter: Gain8_Gain
                                          //  Referenced by: '<S4>/Gain8'

  real32_T DiscreteTimeIntegrator_gainva_h;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_h
                             //  Referenced by: '<S4>/Discrete-Time Integrator'

  real32_T DeadZone4_Start;            // Computed Parameter: DeadZone4_Start
                                          //  Referenced by: '<S4>/Dead Zone4'

  real32_T DeadZone4_End;              // Computed Parameter: DeadZone4_End
                                          //  Referenced by: '<S4>/Dead Zone4'

  real32_T Saturation4_UpperSat;     // Computed Parameter: Saturation4_UpperSat
                                        //  Referenced by: '<S4>/Saturation4'

  real32_T Saturation4_LowerSat;     // Computed Parameter: Saturation4_LowerSat
                                        //  Referenced by: '<S4>/Saturation4'

  real32_T Gain9_Gain;                 // Computed Parameter: Gain9_Gain
                                          //  Referenced by: '<S4>/Gain9'

  real32_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<S4>/Discrete-Time Integrator1'

  real32_T RateLimiter_IC;             // Computed Parameter: RateLimiter_IC
                                          //  Referenced by: '<S4>/Rate Limiter'

  real32_T Saturation6_UpperSat;     // Computed Parameter: Saturation6_UpperSat
                                        //  Referenced by: '<S4>/Saturation6'

  real32_T Saturation6_LowerSat;     // Computed Parameter: Saturation6_LowerSat
                                        //  Referenced by: '<S4>/Saturation6'

  real32_T Gain11_Gain;                // Computed Parameter: Gain11_Gain
                                          //  Referenced by: '<S4>/Gain11'

  real32_T Constant1_Value_fy;         // Computed Parameter: Constant1_Value_fy
                                          //  Referenced by: '<S3>/Constant1'

  real32_T u2_Gain;                    // Computed Parameter: u2_Gain
                                          //  Referenced by: '<S27>/1//2'

  real32_T Constant_Value_i;           // Computed Parameter: Constant_Value_i
                                          //  Referenced by: '<S3>/Constant'

  real32_T Gain1_Gain_o;               // Computed Parameter: Gain1_Gain_o
                                          //  Referenced by: '<S218>/Gain1'

  real32_T Gain1_Gain_j;               // Computed Parameter: Gain1_Gain_j
                                          //  Referenced by: '<S219>/Gain1'

  real32_T Constant3_Value_m;          // Computed Parameter: Constant3_Value_m
                                          //  Referenced by: '<S3>/Constant3'

  real32_T Bias1_Bias_m;               // Computed Parameter: Bias1_Bias_m
                                          //  Referenced by: '<S165>/Bias1'

  real32_T Gain1_Gain_a;               // Computed Parameter: Gain1_Gain_a
                                          //  Referenced by: '<S164>/Gain1'

  real32_T UnitDelay2_InitialCondition_m;
                            // Computed Parameter: UnitDelay2_InitialCondition_m
                               //  Referenced by: '<S164>/Unit Delay2'

  real32_T Gain_Gain_eb;               // Computed Parameter: Gain_Gain_eb
                                          //  Referenced by: '<S9>/Gain'

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

  boolean_T RateTransition6_InitialCondit_j;
                          // Computed Parameter: RateTransition6_InitialCondit_j
                             //  Referenced by: '<S365>/Rate Transition6'

  boolean_T RateTransition16_InitialConditi;
                          // Computed Parameter: RateTransition16_InitialConditi
                             //  Referenced by: '<S9>/Rate Transition16'

  boolean_T RateTransition15_InitialConditi;
                          // Computed Parameter: RateTransition15_InitialConditi
                             //  Referenced by: '<S9>/Rate Transition15'

  boolean_T RateTransition6_InitialCondit_l;
                          // Computed Parameter: RateTransition6_InitialCondit_l
                             //  Referenced by: '<S364>/Rate Transition6'

  boolean_T RateTransition6_InitialCondit_e;
                          // Computed Parameter: RateTransition6_InitialCondit_e
                             //  Referenced by: '<S366>/Rate Transition6'

  boolean_T RateTransition2_16_InitialCondi;
                          // Computed Parameter: RateTransition2_16_InitialCondi
                             //  Referenced by: '<Root>/Rate Transition2'

  boolean_T RateTransition2_17_InitialCondi;
                          // Computed Parameter: RateTransition2_17_InitialCondi
                             //  Referenced by: '<Root>/Rate Transition2'

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

  uint8_T &TaskCounter(int32_T idx);
  boolean_T StepTask(int32_T idx) const;
  const char_T* getErrorStatus() const;
  void setErrorStatus(const char_T* const volatile aErrorStatus);
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
  extern void FLIGHT_Hexacopter_V2_step0(void);// Sample time: [0.001s, 0.0s]
  extern void FLIGHT_Hexacopter_V2_step1(void);// Sample time: [0.004s, 0.0s]
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
//  Block '<S161>/Data Type Duplicate' : Unused code path elimination
//  Block '<S221>/NOT' : Unused code path elimination
//  Block '<S223>/NOT' : Unused code path elimination
//  Block '<S226>/NOT' : Unused code path elimination
//  Block '<S227>/NOT' : Unused code path elimination
//  Block '<S228>/NOT' : Unused code path elimination
//  Block '<S229>/NOT' : Unused code path elimination
//  Block '<S236>/NOT' : Unused code path elimination
//  Block '<S230>/Signal Copy' : Unused code path elimination
//  Block '<S230>/Signal Copy1' : Unused code path elimination
//  Block '<S230>/Signal Copy2' : Unused code path elimination
//  Block '<S241>/Data Type Duplicate' : Unused code path elimination
//  Block '<S242>/Data Type Duplicate' : Unused code path elimination
//  Block '<S243>/Data Type Duplicate' : Unused code path elimination
//  Block '<S409>/Data Type Duplicate' : Unused code path elimination
//  Block '<S409>/Data Type Propagation' : Unused code path elimination
//  Block '<S462>/Data Type Duplicate' : Unused code path elimination
//  Block '<S462>/Data Type Propagation' : Unused code path elimination
//  Block '<S473>/Data Type Duplicate' : Unused code path elimination
//  Block '<S530>/Data Type Duplicate' : Unused code path elimination
//  Block '<S587>/Data Type Duplicate' : Unused code path elimination
//  Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S8>/Data Type Conversion9' : Eliminate redundant data type conversion
//  Block '<S238>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S9>/Rate Transition3' : Eliminated since input and output rates are identical
//  Block '<S364>/Rate Transition5' : Eliminated since input and output rates are identical
//  Block '<S365>/Rate Transition5' : Eliminated since input and output rates are identical
//  Block '<S366>/Rate Transition5' : Eliminated since input and output rates are identical


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
//  '<S46>'  : 'FLIGHT_Hexacopter_V2/OFP/Compare To Constant4'
//  '<S47>'  : 'FLIGHT_Hexacopter_V2/OFP/Compare To Constant5'
//  '<S48>'  : 'FLIGHT_Hexacopter_V2/OFP/Compare To Constant6'
//  '<S49>'  : 'FLIGHT_Hexacopter_V2/OFP/MATLAB Function'
//  '<S50>'  : 'FLIGHT_Hexacopter_V2/OFP/MATLAB Function1'
//  '<S51>'  : 'FLIGHT_Hexacopter_V2/OFP/MATLAB Function2'
//  '<S52>'  : 'FLIGHT_Hexacopter_V2/OFP/NED2Body1'
//  '<S53>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude'
//  '<S54>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1'
//  '<S55>'  : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference'
//  '<S56>'  : 'FLIGHT_Hexacopter_V2/OFP/NED2Body1/Calculate Transformation Matrix'
//  '<S57>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Anti-windup'
//  '<S58>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/D Gain'
//  '<S59>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/External Derivative'
//  '<S60>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Filter'
//  '<S61>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Filter ICs'
//  '<S62>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/I Gain'
//  '<S63>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Ideal P Gain'
//  '<S64>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Ideal P Gain Fdbk'
//  '<S65>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Integrator'
//  '<S66>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Integrator ICs'
//  '<S67>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/N Copy'
//  '<S68>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/N Gain'
//  '<S69>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/P Copy'
//  '<S70>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Parallel P Gain'
//  '<S71>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Reset Signal'
//  '<S72>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Saturation'
//  '<S73>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Saturation Fdbk'
//  '<S74>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Sum'
//  '<S75>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Sum Fdbk'
//  '<S76>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tracking Mode'
//  '<S77>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tracking Mode Sum'
//  '<S78>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tsamp - Integral'
//  '<S79>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tsamp - Ngain'
//  '<S80>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/postSat Signal'
//  '<S81>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/preInt Signal'
//  '<S82>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/preSat Signal'
//  '<S83>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Anti-windup/Disabled'
//  '<S84>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/D Gain/Disabled'
//  '<S85>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/External Derivative/Disabled'
//  '<S86>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Filter/Disabled'
//  '<S87>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Filter ICs/Disabled'
//  '<S88>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/I Gain/Disabled'
//  '<S89>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S90>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Ideal P Gain Fdbk/Disabled'
//  '<S91>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Integrator/Disabled'
//  '<S92>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Integrator ICs/Disabled'
//  '<S93>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/N Copy/Disabled wSignal Specification'
//  '<S94>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/N Gain/Disabled'
//  '<S95>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/P Copy/Disabled'
//  '<S96>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Parallel P Gain/External Parameters'
//  '<S97>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Reset Signal/Disabled'
//  '<S98>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Saturation/Passthrough'
//  '<S99>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Saturation Fdbk/Disabled'
//  '<S100>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Sum/Passthrough_P'
//  '<S101>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Sum Fdbk/Disabled'
//  '<S102>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tracking Mode/Disabled'
//  '<S103>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S104>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S105>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S106>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/postSat Signal/Forward_Path'
//  '<S107>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/preInt Signal/Internal PreInt'
//  '<S108>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/preSat Signal/Forward_Path'
//  '<S109>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Anti-windup'
//  '<S110>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/D Gain'
//  '<S111>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/External Derivative'
//  '<S112>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Filter'
//  '<S113>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Filter ICs'
//  '<S114>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/I Gain'
//  '<S115>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Ideal P Gain'
//  '<S116>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Ideal P Gain Fdbk'
//  '<S117>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Integrator'
//  '<S118>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Integrator ICs'
//  '<S119>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/N Copy'
//  '<S120>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/N Gain'
//  '<S121>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/P Copy'
//  '<S122>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Parallel P Gain'
//  '<S123>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Reset Signal'
//  '<S124>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Saturation'
//  '<S125>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Saturation Fdbk'
//  '<S126>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Sum'
//  '<S127>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Sum Fdbk'
//  '<S128>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tracking Mode'
//  '<S129>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tracking Mode Sum'
//  '<S130>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tsamp - Integral'
//  '<S131>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tsamp - Ngain'
//  '<S132>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/postSat Signal'
//  '<S133>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/preInt Signal'
//  '<S134>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/preSat Signal'
//  '<S135>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Anti-windup/Disabled'
//  '<S136>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/D Gain/Disabled'
//  '<S137>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/External Derivative/Disabled'
//  '<S138>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Filter/Disabled'
//  '<S139>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Filter ICs/Disabled'
//  '<S140>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/I Gain/Disabled'
//  '<S141>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Ideal P Gain/Passthrough'
//  '<S142>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Ideal P Gain Fdbk/Disabled'
//  '<S143>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Integrator/Disabled'
//  '<S144>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Integrator ICs/Disabled'
//  '<S145>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/N Copy/Disabled wSignal Specification'
//  '<S146>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/N Gain/Disabled'
//  '<S147>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/P Copy/Disabled'
//  '<S148>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Parallel P Gain/External Parameters'
//  '<S149>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Reset Signal/Disabled'
//  '<S150>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Saturation/Passthrough'
//  '<S151>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Saturation Fdbk/Disabled'
//  '<S152>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Sum/Passthrough_P'
//  '<S153>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Sum Fdbk/Disabled'
//  '<S154>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tracking Mode/Disabled'
//  '<S155>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tracking Mode Sum/Passthrough'
//  '<S156>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tsamp - Integral/TsSignalSpecification'
//  '<S157>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tsamp - Ngain/Passthrough'
//  '<S158>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/postSat Signal/Forward_Path'
//  '<S159>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/preInt Signal/Internal PreInt'
//  '<S160>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/preSat Signal/Forward_Path'
//  '<S161>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/Discrete Derivative2'
//  '<S162>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/Discrete Varying Lowpass2'
//  '<S163>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate'
//  '<S164>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/Discrete Varying Lowpass2/SOS1'
//  '<S165>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/Discrete Varying Lowpass2/SOS1/Arithmetic'
//  '<S166>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Anti-windup'
//  '<S167>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/D Gain'
//  '<S168>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/External Derivative'
//  '<S169>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Filter'
//  '<S170>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Filter ICs'
//  '<S171>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/I Gain'
//  '<S172>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Ideal P Gain'
//  '<S173>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Ideal P Gain Fdbk'
//  '<S174>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Integrator'
//  '<S175>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Integrator ICs'
//  '<S176>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/N Copy'
//  '<S177>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/N Gain'
//  '<S178>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/P Copy'
//  '<S179>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Parallel P Gain'
//  '<S180>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Reset Signal'
//  '<S181>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Saturation'
//  '<S182>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Saturation Fdbk'
//  '<S183>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Sum'
//  '<S184>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Sum Fdbk'
//  '<S185>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Tracking Mode'
//  '<S186>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Tracking Mode Sum'
//  '<S187>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Tsamp - Integral'
//  '<S188>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Tsamp - Ngain'
//  '<S189>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/postSat Signal'
//  '<S190>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/preInt Signal'
//  '<S191>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/preSat Signal'
//  '<S192>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Anti-windup/Passthrough'
//  '<S193>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/D Gain/Disabled'
//  '<S194>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/External Derivative/Disabled'
//  '<S195>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Filter/Disabled'
//  '<S196>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Filter ICs/Disabled'
//  '<S197>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/I Gain/External Parameters'
//  '<S198>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Ideal P Gain/Passthrough'
//  '<S199>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Ideal P Gain Fdbk/Disabled'
//  '<S200>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Integrator/Discrete'
//  '<S201>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Integrator ICs/Internal IC'
//  '<S202>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/N Copy/Disabled wSignal Specification'
//  '<S203>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/N Gain/Disabled'
//  '<S204>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/P Copy/Disabled'
//  '<S205>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Parallel P Gain/External Parameters'
//  '<S206>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Reset Signal/External Reset'
//  '<S207>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Saturation/Passthrough'
//  '<S208>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Saturation Fdbk/Disabled'
//  '<S209>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Sum/Sum_PI'
//  '<S210>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Sum Fdbk/Disabled'
//  '<S211>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Tracking Mode/Disabled'
//  '<S212>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Tracking Mode Sum/Passthrough'
//  '<S213>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Tsamp - Integral/TsSignalSpecification'
//  '<S214>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Tsamp - Ngain/Passthrough'
//  '<S215>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/postSat Signal/Forward_Path'
//  '<S216>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/preInt Signal/Internal PreInt'
//  '<S217>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/preSat Signal/Forward_Path'
//  '<S218>' : 'FLIGHT_Hexacopter_V2/Parameters_PARAMS/Degrees to Radians'
//  '<S219>' : 'FLIGHT_Hexacopter_V2/Parameters_PARAMS/Degrees to Radians1'
//  '<S220>' : 'FLIGHT_Hexacopter_V2/Parameters_PARAMS/MATLAB Function'
//  '<S221>' : 'FLIGHT_Hexacopter_V2/RCCommand(CMD)/PX4 uORB Read'
//  '<S222>' : 'FLIGHT_Hexacopter_V2/RCCommand(CMD)/PX4 uORB Read/Enabled Subsystem'
//  '<S223>' : 'FLIGHT_Hexacopter_V2/Read_uORB(1000hz)_SENSORS1000/PX4 uORB Read1'
//  '<S224>' : 'FLIGHT_Hexacopter_V2/Read_uORB(1000hz)_SENSORS1000/PX4 uORB Read1/Enabled Subsystem'
//  '<S225>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/MATLAB Function'
//  '<S226>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read'
//  '<S227>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read1'
//  '<S228>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read2'
//  '<S229>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read3'
//  '<S230>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/Vehicle Attitude'
//  '<S231>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/quat2eul'
//  '<S232>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read/Enabled Subsystem'
//  '<S233>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read1/Enabled Subsystem'
//  '<S234>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read2/Enabled Subsystem'
//  '<S235>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read3/Enabled Subsystem'
//  '<S236>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/Vehicle Attitude/PX4 uORB Read'
//  '<S237>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'
//  '<S238>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Calc_Fx_Gx'
//  '<S239>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Compare To Constant'
//  '<S240>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Compare To Constant1'
//  '<S241>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Derivative'
//  '<S242>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Derivative1'
//  '<S243>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Derivative2'
//  '<S244>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1'
//  '<S245>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2'
//  '<S246>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Varying Lowpass'
//  '<S247>' : 'FLIGHT_Hexacopter_V2/Roll SMC/MATLAB Function'
//  '<S248>' : 'FLIGHT_Hexacopter_V2/Roll SMC/MATLAB Function1'
//  '<S249>' : 'FLIGHT_Hexacopter_V2/Roll SMC/MATLAB Function2'
//  '<S250>' : 'FLIGHT_Hexacopter_V2/Roll SMC/MATLAB Function3'
//  '<S251>' : 'FLIGHT_Hexacopter_V2/Roll SMC/MATLAB Function4'
//  '<S252>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Omega_phi'
//  '<S253>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Anti-windup'
//  '<S254>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/D Gain'
//  '<S255>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/External Derivative'
//  '<S256>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Filter'
//  '<S257>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Filter ICs'
//  '<S258>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/I Gain'
//  '<S259>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Ideal P Gain'
//  '<S260>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S261>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Integrator'
//  '<S262>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Integrator ICs'
//  '<S263>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/N Copy'
//  '<S264>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/N Gain'
//  '<S265>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/P Copy'
//  '<S266>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Parallel P Gain'
//  '<S267>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Reset Signal'
//  '<S268>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Saturation'
//  '<S269>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Saturation Fdbk'
//  '<S270>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Sum'
//  '<S271>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Sum Fdbk'
//  '<S272>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Tracking Mode'
//  '<S273>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Tracking Mode Sum'
//  '<S274>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Tsamp - Integral'
//  '<S275>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Tsamp - Ngain'
//  '<S276>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/postSat Signal'
//  '<S277>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/preInt Signal'
//  '<S278>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/preSat Signal'
//  '<S279>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Anti-windup/Disabled'
//  '<S280>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/D Gain/Internal Parameters'
//  '<S281>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/External Derivative/Error'
//  '<S282>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S283>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S284>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/I Gain/Disabled'
//  '<S285>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S286>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S287>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Integrator/Disabled'
//  '<S288>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Integrator ICs/Disabled'
//  '<S289>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/N Copy/Disabled'
//  '<S290>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/N Gain/Internal Parameters'
//  '<S291>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/P Copy/Disabled'
//  '<S292>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S293>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S294>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Saturation/Passthrough'
//  '<S295>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S296>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Sum/Sum_PD'
//  '<S297>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S298>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S299>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S300>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S301>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S302>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S303>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/preInt Signal/Internal PreInt'
//  '<S304>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S305>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Anti-windup'
//  '<S306>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/D Gain'
//  '<S307>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/External Derivative'
//  '<S308>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Filter'
//  '<S309>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Filter ICs'
//  '<S310>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/I Gain'
//  '<S311>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Ideal P Gain'
//  '<S312>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Ideal P Gain Fdbk'
//  '<S313>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Integrator'
//  '<S314>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Integrator ICs'
//  '<S315>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/N Copy'
//  '<S316>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/N Gain'
//  '<S317>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/P Copy'
//  '<S318>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Parallel P Gain'
//  '<S319>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Reset Signal'
//  '<S320>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Saturation'
//  '<S321>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Saturation Fdbk'
//  '<S322>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Sum'
//  '<S323>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Sum Fdbk'
//  '<S324>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Tracking Mode'
//  '<S325>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Tracking Mode Sum'
//  '<S326>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Tsamp - Integral'
//  '<S327>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Tsamp - Ngain'
//  '<S328>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/postSat Signal'
//  '<S329>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/preInt Signal'
//  '<S330>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/preSat Signal'
//  '<S331>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Anti-windup/Passthrough'
//  '<S332>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/D Gain/Disabled'
//  '<S333>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/External Derivative/Disabled'
//  '<S334>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Filter/Disabled'
//  '<S335>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Filter ICs/Disabled'
//  '<S336>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/I Gain/Internal Parameters'
//  '<S337>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Ideal P Gain/Passthrough'
//  '<S338>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S339>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Integrator/Discrete'
//  '<S340>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Integrator ICs/Internal IC'
//  '<S341>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/N Copy/Disabled wSignal Specification'
//  '<S342>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/N Gain/Disabled'
//  '<S343>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/P Copy/Disabled'
//  '<S344>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Parallel P Gain/Disabled'
//  '<S345>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Reset Signal/External Reset'
//  '<S346>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Saturation/Passthrough'
//  '<S347>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Saturation Fdbk/Disabled'
//  '<S348>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Sum/Passthrough_I'
//  '<S349>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Sum Fdbk/Disabled'
//  '<S350>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Tracking Mode/Disabled'
//  '<S351>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S352>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S353>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S354>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/postSat Signal/Forward_Path'
//  '<S355>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/preInt Signal/Internal PreInt'
//  '<S356>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/preSat Signal/Forward_Path'
//  '<S357>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Varying Lowpass/FOS'
//  '<S358>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Varying Lowpass/FOS/Arithmetic'
//  '<S359>' : 'FLIGHT_Hexacopter_V2/SCAS/Compare To Constant'
//  '<S360>' : 'FLIGHT_Hexacopter_V2/SCAS/Compare To Constant1'
//  '<S361>' : 'FLIGHT_Hexacopter_V2/SCAS/Compare To Constant2'
//  '<S362>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3'
//  '<S363>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4'
//  '<S364>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate'
//  '<S365>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate'
//  '<S366>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate'
//  '<S367>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Anti-windup'
//  '<S368>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/D Gain'
//  '<S369>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/External Derivative'
//  '<S370>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Filter'
//  '<S371>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Filter ICs'
//  '<S372>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/I Gain'
//  '<S373>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Ideal P Gain'
//  '<S374>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Ideal P Gain Fdbk'
//  '<S375>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Integrator'
//  '<S376>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Integrator ICs'
//  '<S377>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/N Copy'
//  '<S378>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/N Gain'
//  '<S379>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/P Copy'
//  '<S380>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Parallel P Gain'
//  '<S381>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Reset Signal'
//  '<S382>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Saturation'
//  '<S383>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Saturation Fdbk'
//  '<S384>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Sum'
//  '<S385>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Sum Fdbk'
//  '<S386>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tracking Mode'
//  '<S387>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tracking Mode Sum'
//  '<S388>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tsamp - Integral'
//  '<S389>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tsamp - Ngain'
//  '<S390>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/postSat Signal'
//  '<S391>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/preInt Signal'
//  '<S392>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/preSat Signal'
//  '<S393>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Anti-windup/Disabled'
//  '<S394>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/D Gain/Disabled'
//  '<S395>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/External Derivative/Disabled'
//  '<S396>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Filter/Disabled'
//  '<S397>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Filter ICs/Disabled'
//  '<S398>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/I Gain/Disabled'
//  '<S399>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Ideal P Gain/Passthrough'
//  '<S400>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S401>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Integrator/Disabled'
//  '<S402>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Integrator ICs/Disabled'
//  '<S403>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S404>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/N Gain/Disabled'
//  '<S405>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/P Copy/Disabled'
//  '<S406>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Parallel P Gain/External Parameters'
//  '<S407>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Reset Signal/Disabled'
//  '<S408>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Saturation/External'
//  '<S409>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Saturation/External/Saturation Dynamic'
//  '<S410>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Saturation Fdbk/Disabled'
//  '<S411>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Sum/Passthrough_P'
//  '<S412>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Sum Fdbk/Disabled'
//  '<S413>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tracking Mode/Disabled'
//  '<S414>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S415>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S416>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S417>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/postSat Signal/Forward_Path'
//  '<S418>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/preInt Signal/Internal PreInt'
//  '<S419>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/preSat Signal/Forward_Path'
//  '<S420>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Anti-windup'
//  '<S421>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/D Gain'
//  '<S422>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/External Derivative'
//  '<S423>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Filter'
//  '<S424>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Filter ICs'
//  '<S425>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/I Gain'
//  '<S426>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Ideal P Gain'
//  '<S427>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Ideal P Gain Fdbk'
//  '<S428>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Integrator'
//  '<S429>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Integrator ICs'
//  '<S430>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/N Copy'
//  '<S431>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/N Gain'
//  '<S432>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/P Copy'
//  '<S433>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Parallel P Gain'
//  '<S434>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Reset Signal'
//  '<S435>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Saturation'
//  '<S436>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Saturation Fdbk'
//  '<S437>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Sum'
//  '<S438>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Sum Fdbk'
//  '<S439>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tracking Mode'
//  '<S440>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tracking Mode Sum'
//  '<S441>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tsamp - Integral'
//  '<S442>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tsamp - Ngain'
//  '<S443>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/postSat Signal'
//  '<S444>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/preInt Signal'
//  '<S445>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/preSat Signal'
//  '<S446>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Anti-windup/Disabled'
//  '<S447>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/D Gain/Disabled'
//  '<S448>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/External Derivative/Disabled'
//  '<S449>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Filter/Disabled'
//  '<S450>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Filter ICs/Disabled'
//  '<S451>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/I Gain/Disabled'
//  '<S452>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Ideal P Gain/Passthrough'
//  '<S453>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S454>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Integrator/Disabled'
//  '<S455>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Integrator ICs/Disabled'
//  '<S456>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S457>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/N Gain/Disabled'
//  '<S458>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/P Copy/Disabled'
//  '<S459>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Parallel P Gain/External Parameters'
//  '<S460>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Reset Signal/Disabled'
//  '<S461>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Saturation/External'
//  '<S462>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Saturation/External/Saturation Dynamic'
//  '<S463>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Saturation Fdbk/Disabled'
//  '<S464>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Sum/Passthrough_P'
//  '<S465>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Sum Fdbk/Disabled'
//  '<S466>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tracking Mode/Disabled'
//  '<S467>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S468>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S469>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S470>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/postSat Signal/Forward_Path'
//  '<S471>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/preInt Signal/Internal PreInt'
//  '<S472>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/preSat Signal/Forward_Path'
//  '<S473>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/Discrete Derivative2'
//  '<S474>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/Discrete Varying Lowpass2'
//  '<S475>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate'
//  '<S476>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/Discrete Varying Lowpass2/SOS1'
//  '<S477>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/Discrete Varying Lowpass2/SOS1/Arithmetic'
//  '<S478>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Anti-windup'
//  '<S479>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/D Gain'
//  '<S480>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/External Derivative'
//  '<S481>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Filter'
//  '<S482>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Filter ICs'
//  '<S483>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/I Gain'
//  '<S484>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Ideal P Gain'
//  '<S485>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Ideal P Gain Fdbk'
//  '<S486>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Integrator'
//  '<S487>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Integrator ICs'
//  '<S488>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/N Copy'
//  '<S489>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/N Gain'
//  '<S490>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/P Copy'
//  '<S491>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Parallel P Gain'
//  '<S492>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Reset Signal'
//  '<S493>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Saturation'
//  '<S494>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Saturation Fdbk'
//  '<S495>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Sum'
//  '<S496>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Sum Fdbk'
//  '<S497>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Tracking Mode'
//  '<S498>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Tracking Mode Sum'
//  '<S499>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Tsamp - Integral'
//  '<S500>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Tsamp - Ngain'
//  '<S501>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/postSat Signal'
//  '<S502>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/preInt Signal'
//  '<S503>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/preSat Signal'
//  '<S504>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Anti-windup/Passthrough'
//  '<S505>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/D Gain/Disabled'
//  '<S506>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/External Derivative/Disabled'
//  '<S507>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Filter/Disabled'
//  '<S508>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Filter ICs/Disabled'
//  '<S509>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/I Gain/External Parameters'
//  '<S510>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Ideal P Gain/Passthrough'
//  '<S511>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Ideal P Gain Fdbk/Disabled'
//  '<S512>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Integrator/Discrete'
//  '<S513>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Integrator ICs/Internal IC'
//  '<S514>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/N Copy/Disabled wSignal Specification'
//  '<S515>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/N Gain/Disabled'
//  '<S516>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/P Copy/Disabled'
//  '<S517>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Parallel P Gain/External Parameters'
//  '<S518>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Reset Signal/External Reset'
//  '<S519>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Saturation/Passthrough'
//  '<S520>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Saturation Fdbk/Disabled'
//  '<S521>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Sum/Sum_PI'
//  '<S522>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Sum Fdbk/Disabled'
//  '<S523>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Tracking Mode/Disabled'
//  '<S524>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Tracking Mode Sum/Passthrough'
//  '<S525>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Tsamp - Integral/TsSignalSpecification'
//  '<S526>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/Tsamp - Ngain/Passthrough'
//  '<S527>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/postSat Signal/Forward_Path'
//  '<S528>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/preInt Signal/Internal PreInt'
//  '<S529>' : 'FLIGHT_Hexacopter_V2/SCAS/Pitchrate/pid_ctrl_rollrate/preSat Signal/Forward_Path'
//  '<S530>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/Discrete Derivative2'
//  '<S531>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/Discrete Varying Lowpass2'
//  '<S532>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate'
//  '<S533>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/Discrete Varying Lowpass2/SOS1'
//  '<S534>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/Discrete Varying Lowpass2/SOS1/Arithmetic'
//  '<S535>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Anti-windup'
//  '<S536>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/D Gain'
//  '<S537>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/External Derivative'
//  '<S538>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Filter'
//  '<S539>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Filter ICs'
//  '<S540>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/I Gain'
//  '<S541>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Ideal P Gain'
//  '<S542>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Ideal P Gain Fdbk'
//  '<S543>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Integrator'
//  '<S544>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Integrator ICs'
//  '<S545>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/N Copy'
//  '<S546>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/N Gain'
//  '<S547>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/P Copy'
//  '<S548>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Parallel P Gain'
//  '<S549>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Reset Signal'
//  '<S550>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Saturation'
//  '<S551>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Saturation Fdbk'
//  '<S552>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Sum'
//  '<S553>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Sum Fdbk'
//  '<S554>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Tracking Mode'
//  '<S555>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Tracking Mode Sum'
//  '<S556>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Tsamp - Integral'
//  '<S557>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Tsamp - Ngain'
//  '<S558>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/postSat Signal'
//  '<S559>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/preInt Signal'
//  '<S560>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/preSat Signal'
//  '<S561>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Anti-windup/Passthrough'
//  '<S562>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/D Gain/Disabled'
//  '<S563>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/External Derivative/Disabled'
//  '<S564>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Filter/Disabled'
//  '<S565>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Filter ICs/Disabled'
//  '<S566>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/I Gain/External Parameters'
//  '<S567>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Ideal P Gain/Passthrough'
//  '<S568>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Ideal P Gain Fdbk/Disabled'
//  '<S569>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Integrator/Discrete'
//  '<S570>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Integrator ICs/Internal IC'
//  '<S571>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/N Copy/Disabled wSignal Specification'
//  '<S572>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/N Gain/Disabled'
//  '<S573>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/P Copy/Disabled'
//  '<S574>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Parallel P Gain/External Parameters'
//  '<S575>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Reset Signal/External Reset'
//  '<S576>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Saturation/Passthrough'
//  '<S577>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Saturation Fdbk/Disabled'
//  '<S578>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Sum/Sum_PI'
//  '<S579>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Sum Fdbk/Disabled'
//  '<S580>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Tracking Mode/Disabled'
//  '<S581>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Tracking Mode Sum/Passthrough'
//  '<S582>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Tsamp - Integral/TsSignalSpecification'
//  '<S583>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/Tsamp - Ngain/Passthrough'
//  '<S584>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/postSat Signal/Forward_Path'
//  '<S585>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/preInt Signal/Internal PreInt'
//  '<S586>' : 'FLIGHT_Hexacopter_V2/SCAS/Rollrate/pid_ctrl_rollrate/preSat Signal/Forward_Path'
//  '<S587>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/Discrete Derivative2'
//  '<S588>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/Discrete Varying Lowpass2'
//  '<S589>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate'
//  '<S590>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/Discrete Varying Lowpass2/SOS1'
//  '<S591>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/Discrete Varying Lowpass2/SOS1/Arithmetic'
//  '<S592>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Anti-windup'
//  '<S593>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/D Gain'
//  '<S594>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/External Derivative'
//  '<S595>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Filter'
//  '<S596>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Filter ICs'
//  '<S597>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/I Gain'
//  '<S598>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Ideal P Gain'
//  '<S599>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Ideal P Gain Fdbk'
//  '<S600>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Integrator'
//  '<S601>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Integrator ICs'
//  '<S602>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/N Copy'
//  '<S603>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/N Gain'
//  '<S604>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/P Copy'
//  '<S605>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Parallel P Gain'
//  '<S606>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Reset Signal'
//  '<S607>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Saturation'
//  '<S608>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Saturation Fdbk'
//  '<S609>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Sum'
//  '<S610>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Sum Fdbk'
//  '<S611>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Tracking Mode'
//  '<S612>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Tracking Mode Sum'
//  '<S613>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Tsamp - Integral'
//  '<S614>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Tsamp - Ngain'
//  '<S615>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/postSat Signal'
//  '<S616>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/preInt Signal'
//  '<S617>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/preSat Signal'
//  '<S618>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Anti-windup/Passthrough'
//  '<S619>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/D Gain/Disabled'
//  '<S620>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/External Derivative/Disabled'
//  '<S621>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Filter/Disabled'
//  '<S622>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Filter ICs/Disabled'
//  '<S623>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/I Gain/External Parameters'
//  '<S624>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Ideal P Gain/Passthrough'
//  '<S625>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Ideal P Gain Fdbk/Disabled'
//  '<S626>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Integrator/Discrete'
//  '<S627>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Integrator ICs/Internal IC'
//  '<S628>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/N Copy/Disabled wSignal Specification'
//  '<S629>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/N Gain/Disabled'
//  '<S630>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/P Copy/Disabled'
//  '<S631>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Parallel P Gain/External Parameters'
//  '<S632>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Reset Signal/External Reset'
//  '<S633>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Saturation/Passthrough'
//  '<S634>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Saturation Fdbk/Disabled'
//  '<S635>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Sum/Sum_PI'
//  '<S636>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Sum Fdbk/Disabled'
//  '<S637>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Tracking Mode/Disabled'
//  '<S638>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Tracking Mode Sum/Passthrough'
//  '<S639>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Tsamp - Integral/TsSignalSpecification'
//  '<S640>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/Tsamp - Ngain/Passthrough'
//  '<S641>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/postSat Signal/Forward_Path'
//  '<S642>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/preInt Signal/Internal PreInt'
//  '<S643>' : 'FLIGHT_Hexacopter_V2/SCAS/Yawrate/pid_ctrl_rollrate/preSat Signal/Forward_Path'

#endif                                 // FLIGHT_Hexacopter_V2_h_

//
// File trailer for generated code.
//
// [EOF]
//
