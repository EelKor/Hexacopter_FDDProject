//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_Hexacopter_V2.h
//
// Code generated for Simulink model 'FLIGHT_Hexacopter_V2'.
//
// Model version                  : 3.26
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Aug 20 15:10:09 2025
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

// Block signals for system '<S22>/PX4 Timestamp'
struct B_PX4Timestamp_FLIGHT_Hexac_a_T {
  uint64_T PX4Timestamp;               // '<S22>/PX4 Timestamp'
};

// Block states (default storage) for system '<S22>/PX4 Timestamp'
struct DW_PX4Timestamp_FLIGHT_Hexa_o_T {
  px4_internal_block_getPX4Abso_T obj; // '<S22>/PX4 Timestamp'
  boolean_T objisempty;                // '<S22>/PX4 Timestamp'
};

// Block signals for system '<S23>/PX4 Timestamp'
struct B_PX4Timestamp_FLIGHT_Hexac_l_T {
  uint64_T PX4Timestamp;               // '<S23>/PX4 Timestamp'
};

// Block states (default storage) for system '<S23>/PX4 Timestamp'
struct DW_PX4Timestamp_FLIGHT_Hexa_j_T {
  px4_internal_block_getPX4Abso_T obj; // '<S23>/PX4 Timestamp'
  boolean_T objisempty;                // '<S23>/PX4 Timestamp'
};

// Block signals for system '<S224>/SourceBlock'
struct B_SourceBlock_FLIGHT_Hexacopt_T {
  px4_Bus_actuator_armed SourceBlock_o2;// '<S224>/SourceBlock'
  boolean_T SourceBlock_o1;            // '<S224>/SourceBlock'
};

// Block states (default storage) for system '<S224>/SourceBlock'
struct DW_SourceBlock_FLIGHT_Hexacop_T {
  px4_internal_block_Subscriber_T obj; // '<S224>/SourceBlock'
  boolean_T objisempty;                // '<S224>/SourceBlock'
};

// Block signals (default storage)
struct B_FLIGHT_Hexacopter_V2_T {
  px4_Bus_vehicle_local_position In1;  // '<S232>/In1'
  px4_Bus_vehicle_local_position r;
  px4_Bus_vehicle_odometry In1_b;      // '<S235>/In1'
  px4_Bus_vehicle_attitude_smc_setpoint BusAssignment;// '<S26>/Bus Assignment'
  px4_Bus_vehicle_odometry r1;
  px4_Bus_actuator_motors BusAssignment_e;// '<S27>/Bus Assignment'
  px4_Bus_input_rc r2;
  px4_Bus_vehicle_status In1_m;        // '<S231>/In1'
  px4_Bus_input_rc In1_p;              // '<S220>/In1'
  px4_Bus_vehicle_status r3;
  real_T CreateDiagonalMatrix[9];      // '<S236>/Create Diagonal Matrix'
  px4_Bus_vehicle_local_position_setpoint BusAssignment_g;// '<S28>/Bus Assignment' 
  px4_Bus_vehicle_attitude_setpoint BusAssignment_f;// '<S23>/Bus Assignment'
  real32_T Gain_g[12];                 // '<S21>/Gain'
  px4_Bus_vehicle_rates_setpoint BusAssignment_e0;// '<S24>/Bus Assignment'
  px4_Bus_vehicle_angular_velocity In1_k;// '<S222>/In1'
  px4_Bus_vehicle_angular_velocity r4;
  px4_Bus_actuator_controls_status BusAssignment_j;// '<S22>/Bus Assignment'
  real32_T fv[4];
  px4_Bus_actuator_armed In1_d;        // '<S233>/In1'
  px4_Bus_actuator_armed In1_e;        // '<S230>/In1'
  uint16_T pwmValue[8];
  real32_T ypr[3];                     // '<S8>/quat2eul'
  real32_T U[3];
  real32_T G1[3];                      // '<S9>/MATLAB Function1'
  real32_T G1_inv[3];                  // '<S9>/MATLAB Function2'
  real32_T b_A[3];
  uint16_T DataTypeConversion_g[6];    // '<S13>/Data Type Conversion'
  uint16_T DataTypeConversion6[6];     // '<S12>/Data Type Conversion6'
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
  real32_T RateTransition5;            // '<S10>/Rate Transition5'
  real32_T RateTransition2;            // '<S10>/Rate Transition2'
  real32_T RateTransition18;           // '<S10>/Rate Transition18'
  real32_T RateTransition3;            // '<S10>/Rate Transition3'
  real32_T RateTransition2_a[3];       // '<S9>/Rate Transition2'
  real32_T RateTransition4_l;          // '<S9>/Rate Transition4'
  real32_T RateTransition5_n;          // '<S9>/Rate Transition5'
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
  real32_T RateTransition8_i;          // '<S10>/Rate Transition8'
  real32_T RateTransition19;           // '<S10>/Rate Transition19'
  real32_T RateTransition10_j;         // '<S10>/Rate Transition10'
  real32_T RateTransition7_h;          // '<S10>/Rate Transition7'
  real32_T RateTransition;             // '<S10>/Rate Transition'
  real32_T RateTransition1_a;          // '<S10>/Rate Transition1'
  real32_T RateTransition13_a;         // '<S10>/Rate Transition13'
  real32_T RateTransition20;           // '<S10>/Rate Transition20'
  real32_T RateTransition11_a;         // '<S10>/Rate Transition11'
  real32_T RateTransition12_j;         // '<S10>/Rate Transition12'
  real32_T RateTransition14_c;         // '<S10>/Rate Transition14'
  real32_T RateTransition9_p;          // '<S10>/Rate Transition9'
  real32_T RateTransition6_o;          // '<S10>/Rate Transition6'
  real32_T ParamStep;
  real32_T ParamStep_c;
  real32_T ParamStep_k;
  real32_T Integrator_c;               // '<S198>/Integrator'
  real32_T roll;                       // '<S53>/Sum1'
  real32_T Gain7;                      // '<S4>/Gain7'
  real32_T Gain4;                      // '<S4>/Gain4'
  real32_T Gain5;                      // '<S4>/Gain5'
  real32_T Gain6;                      // '<S4>/Gain6'
  real32_T w_radps;                    // '<S5>/MATLAB Function'
  real32_T p_j;                        // '<S163>/Gain'
  real32_T q_c;                        // '<S163>/Product2'
  real32_T r_o;                        // '<S163>/Bias'
  real32_T d_n;                        // '<S163>/Add1'
  real32_T Product1_e;                 // '<S4>/Product1'
  real32_T TSamp_ku;                   // '<S159>/TSamp'
  real32_T des_throttle;               // '<S4>/MATLAB Function2'
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
  real32_T IProdOut_b;                 // '<S514>/IProd Out'
  real32_T DeadZone;                   // '<S509>/DeadZone'
  real32_T Sum5_f;                     // '<S10>/Sum5'
  real32_T p;                          // '<S372>/Gain'
  real32_T q;                          // '<S372>/Product2'
  real32_T r_c;                        // '<S372>/Bias'
  real32_T d_b;                        // '<S372>/Add1'
  real32_T Product2_gt;                // '<S356>/Product2'
  real32_T TSamp;                      // '<S359>/TSamp'
  real32_T Product_p;                  // '<S236>/Product'
  real32_T Product2_m;                 // '<S236>/Product2'
  real32_T Product4;                   // '<S236>/Product4'
  real32_T Sum_o;                      // '<S355>/Sum'
  real32_T Product1_m;                 // '<S355>/Product1'
  real32_T TSamp_oi;                   // '<S239>/TSamp'
  real32_T Diff_k;                     // '<S239>/Diff'
  real32_T TSamp_d;                    // '<S240>/TSamp'
  real32_T Subtract;                   // '<S9>/Subtract'
  real32_T H;                          // '<S9>/MATLAB Function'
  real32_T FilterCoefficient;          // '<S288>/Filter Coefficient'
  real32_T Sum_n;                      // '<S294>/Sum'
  real32_T s;                          // '<S9>/MATLAB Function3'
  real32_T R;                          // '<S9>/MATLAB Function4'
  real32_T Saturation2;                // '<S9>/Saturation2'
  real32_T IProdOut_p;                 // '<S568>/IProd Out'
  real32_T DeadZone_d;                 // '<S563>/DeadZone'
  real32_T Sum4;                       // '<S10>/Sum4'
  real32_T Product2_l;                 // '<S369>/Product2'
  real32_T p_l;                        // '<S370>/Gain'
  real32_T q_o;                        // '<S370>/Product2'
  real32_T r_d;                        // '<S370>/Bias'
  real32_T d_g;                        // '<S370>/Add1'
  real32_T IProdOut_g;                 // '<S622>/IProd Out'
  real32_T DeadZone_db;                // '<S617>/DeadZone'
  real32_T Product2_d;                 // '<S373>/Product2'
  real32_T p_g;                        // '<S374>/Gain'
  real32_T q_i;                        // '<S374>/Product2'
  real32_T r_m;                        // '<S374>/Bias'
  real32_T d_c;                        // '<S374>/Add1'
  real32_T Sum2_au;                    // '<S371>/Sum2'
  real32_T TSamp_p;                    // '<S360>/TSamp'
  real32_T rtb_Gain_g_p;
  real32_T rtb_TSamp_o_c;
  real32_T rtb_omega_phi_idx_1;
  real32_T rtb_omega_phi_idx_2;
  real32_T rtb_TSamp_o_idx_1;
  real32_T anrm;
  real32_T absxk;
  int32_T ParamStep_f;
  int32_T ParamStep_g;
  int32_T ParamStep_g1;
  int32_T ParamStep_m;
  int32_T ParamStep_n;
  int32_T ParamStep_p;
  int32_T i;
  uint16_T rc_ctrl_switch;             // '<Root>/Rate Transition'
  uint16_T rc_inject_failure;          // '<Root>/Rate Transition'
  boolean_T RateTransition15;          // '<S10>/Rate Transition15'
  boolean_T RateTransition16;          // '<S9>/Rate Transition16'
  boolean_T RateTransition15_l;        // '<S9>/Rate Transition15'
  boolean_T RateTransition16_e;        // '<S10>/Rate Transition16'
  boolean_T RateTransition17_h;        // '<S10>/Rate Transition17'
  boolean_T VehicleStatus_flag_armed;  // '<Root>/Rate Transition2'
  boolean_T VehicleStatus_flag_kill;   // '<Root>/Rate Transition2'
  B_SourceBlock_FLIGHT_Hexacopt_T SourceBlock_p;// '<S224>/SourceBlock'
  B_SourceBlock_FLIGHT_Hexacopt_T SourceBlock_l;// '<S224>/SourceBlock'
  B_PX4Timestamp_FLIGHT_Hexac_l_T PX4Timestamp_k;// '<S23>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexac_a_T PX4Timestamp_e;// '<S22>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexacop_T PX4Timestamp_pn;// '<S3>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexac_l_T PX4Timestamp_p;// '<S23>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexac_l_T PX4Timestamp_j;// '<S23>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexac_a_T PX4Timestamp_c;// '<S22>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_Hexacop_T PX4Timestamp;// '<S3>/PX4 Timestamp'
};

// Block states (default storage) for system '<Root>'
struct DW_FLIGHT_Hexacopter_V2_T {
  px4_internal_block_getPX4Abso_T obj; // '<S4>/PX4 Timestamp'
  px4_internal_block_Subscriber_T obj_i;// '<S234>/SourceBlock'
  px4_internal_block_Subscriber_T obj_l;// '<S226>/SourceBlock'
  px4_internal_block_Subscriber_T obj_a;// '<S225>/SourceBlock'
  px4_internal_block_Subscriber_T obj_m;// '<S221>/SourceBlock'
  px4_internal_block_Subscriber_T obj_n;// '<S219>/SourceBlock'
  px4_internal_block_PWM_FLIGHT_T obj_md;// '<S1>/PX4 PWM Output'
  px4_internal_block_ParameterU_T obj_c;// '<S5>/read_mc_rollrate_p'
  px4_internal_block_ParameterU_T obj_ai;// '<S5>/Read Parameter9'
  px4_internal_block_ParameterU_T obj_f;// '<S5>/Read Parameter8'
  px4_internal_block_ParameterU_T obj_fj;// '<S5>/Read Parameter7'
  px4_internal_block_ParameterU_T obj_p;// '<S5>/Read Parameter6'
  px4_internal_block_ParameterU_T obj_ia;// '<S5>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_o;// '<S5>/Read Parameter44'
  px4_internal_block_ParameterU_T obj_ox;// '<S5>/Read Parameter43'
  px4_internal_block_ParameterU_T obj_fy;// '<S5>/Read Parameter42'
  px4_internal_block_ParameterU_T obj_h;// '<S5>/Read Parameter41'
  px4_internal_block_ParameterU_T obj_pn;// '<S5>/Read Parameter40'
  px4_internal_block_ParameterU_T obj_c1;// '<S5>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_g;// '<S5>/Read Parameter39'
  px4_internal_block_ParameterU_T obj_e;// '<S5>/Read Parameter38'
  px4_internal_block_ParameterU_T obj_pi;// '<S5>/Read Parameter37'
  px4_internal_block_ParameterU_T obj_ln;// '<S5>/Read Parameter36'
  px4_internal_block_ParameterU_T obj_b;// '<S5>/Read Parameter35'
  px4_internal_block_ParameterU_T obj_oq;// '<S5>/Read Parameter34'
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
  px4_internal_block_Publisher__T obj_pm;// '<S40>/SinkBlock'
  px4_internal_block_Publisher__T obj_nf;// '<S38>/SinkBlock'
  px4_internal_block_Publisher__T obj_k;// '<S36>/SinkBlock'
  px4_internal_block_Publisher__T obj_mp;// '<S34>/SinkBlock'
  px4_internal_block_Publisher__T obj_m1;// '<S32>/SinkBlock'
  px4_internal_block_Publisher__T obj_fe;// '<S30>/SinkBlock'
  real_T start_time_usec;              // '<S4>/MATLAB Function1'
  real32_T Integrator_DSTATE;          // '<S517>/Integrator'
  real32_T UnitDelay1_DSTATE;          // '<S371>/Unit Delay1'
  real32_T UD_DSTATE;                  // '<S359>/UD'
  real32_T UD_DSTATE_h[3];             // '<S241>/UD'
  real32_T UnitDelay_DSTATE;           // '<S355>/Unit Delay'
  real32_T UD_DSTATE_o;                // '<S239>/UD'
  real32_T UD_DSTATE_e;                // '<S240>/UD'
  real32_T Filter_DSTATE;              // '<S280>/Filter'
  real32_T Integrator_DSTATE_h;        // '<S337>/Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE;// '<S9>/Discrete-Time Integrator'
  real32_T Integrator_DSTATE_l;        // '<S571>/Integrator'
  real32_T UnitDelay1_DSTATE_a;        // '<S369>/Unit Delay1'
  real32_T UD_DSTATE_b;                // '<S358>/UD'
  real32_T Integrator_DSTATE_o;        // '<S625>/Integrator'
  real32_T UnitDelay1_DSTATE_p;        // '<S373>/Unit Delay1'
  real32_T UD_DSTATE_d;                // '<S360>/UD'
  real32_T UnitDelay2_DSTATE;          // '<S373>/Unit Delay2'
  real32_T UnitDelay2_DSTATE_c;        // '<S369>/Unit Delay2'
  real32_T UnitDelay2_DSTATE_i;        // '<S371>/Unit Delay2'
  real32_T Integrator_DSTATE_lu;       // '<S198>/Integrator'
  real32_T UnitDelay1_DSTATE_i;        // '<S162>/Unit Delay1'
  real32_T UD_DSTATE_a;                // '<S159>/UD'
  real32_T DiscreteTimeIntegrator_DSTATE_c;// '<S4>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator1_DSTATE;// '<S4>/Discrete-Time Integrator1'
  real32_T UnitDelay2_DSTATE_f;        // '<S162>/Unit Delay2'
  real32_T RateTransition4_Buffer0;    // '<S10>/Rate Transition4'
  real32_T RateTransition5_Buffer0;    // '<S10>/Rate Transition5'
  real32_T RateTransition2_Buffer0;    // '<S10>/Rate Transition2'
  real32_T RateTransition18_Buffer0;   // '<S10>/Rate Transition18'
  real32_T RateTransition3_Buffer0;    // '<S10>/Rate Transition3'
  real32_T RateTransition2_Buffer0_d[3];// '<S9>/Rate Transition2'
  real32_T RateTransition4_Buffer0_d;  // '<S9>/Rate Transition4'
  real32_T RateTransition5_Buffer0_h;  // '<S9>/Rate Transition5'
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
  real32_T RateTransition8_Buffer0_a;  // '<S10>/Rate Transition8'
  real32_T RateTransition19_Buffer0;   // '<S10>/Rate Transition19'
  real32_T RateTransition10_Buffer0_g; // '<S10>/Rate Transition10'
  real32_T RateTransition7_Buffer0_e;  // '<S10>/Rate Transition7'
  real32_T RateTransition_Buffer0;     // '<S10>/Rate Transition'
  real32_T RateTransition1_Buffer0_g;  // '<S10>/Rate Transition1'
  real32_T RateTransition13_Buffer0_d; // '<S10>/Rate Transition13'
  real32_T RateTransition20_Buffer0;   // '<S10>/Rate Transition20'
  real32_T RateTransition11_Buffer0_b; // '<S10>/Rate Transition11'
  real32_T RateTransition12_Buffer0_j; // '<S10>/Rate Transition12'
  real32_T RateTransition14_Buffer0_o; // '<S10>/Rate Transition14'
  real32_T RateTransition9_Buffer0_h;  // '<S10>/Rate Transition9'
  real32_T RateTransition6_Buffer0_e;  // '<S10>/Rate Transition6'
  real32_T PrevY[2];                   // '<S4>/Rate Limiter'
  uint16_T RateTransition_8_Buffer0;   // '<Root>/Rate Transition'
  uint16_T RateTransition_4_Buffer0;   // '<Root>/Rate Transition'
  int8_T Integrator_PrevResetState;    // '<S517>/Integrator'
  int8_T Integrator_PrevResetState_h;  // '<S337>/Integrator'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S9>/Discrete-Time Integrator'
  int8_T Integrator_PrevResetState_e;  // '<S571>/Integrator'
  int8_T Integrator_PrevResetState_es; // '<S625>/Integrator'
  int8_T Integrator_PrevResetState_l;  // '<S198>/Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_l;// '<S4>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator1_PrevRes;// '<S4>/Discrete-Time Integrator1'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S4>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;// '<S4>/Discrete-Time Integrator1'
  boolean_T RateTransition15_Buffer0;  // '<S10>/Rate Transition15'
  boolean_T RateTransition16_Buffer0;  // '<S9>/Rate Transition16'
  boolean_T RateTransition15_Buffer0_a;// '<S9>/Rate Transition15'
  boolean_T RateTransition16_Buffer0_g;// '<S10>/Rate Transition16'
  boolean_T RateTransition17_Buffer0_e;// '<S10>/Rate Transition17'
  boolean_T RateTransition2_16_Buffer0;// '<Root>/Rate Transition2'
  boolean_T RateTransition2_17_Buffer0;// '<Root>/Rate Transition2'
  DW_SourceBlock_FLIGHT_Hexacop_T SourceBlock_p;// '<S224>/SourceBlock'
  DW_SourceBlock_FLIGHT_Hexacop_T SourceBlock_l;// '<S224>/SourceBlock'
  DW_PX4Timestamp_FLIGHT_Hexa_j_T PX4Timestamp_k;// '<S23>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexa_o_T PX4Timestamp_e;// '<S22>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexaco_T PX4Timestamp_pn;// '<S3>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexa_j_T PX4Timestamp_p;// '<S23>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexa_j_T PX4Timestamp_j;// '<S23>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_Hexa_o_T PX4Timestamp_c;// '<S22>/PX4 Timestamp'
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
                                        //  Referenced by: '<S278>/Derivative Gain'

  real32_T DiscretePIDController2_I; // Mask Parameter: DiscretePIDController2_I
                                        //  Referenced by: '<S334>/Integral Gain'

  real32_T DiscreteDerivative2_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative2_ICPrevScale
                                 //  Referenced by: '<S359>/UD'

  real32_T DiscreteDerivative2_ICPrevSca_e;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_e
                                 //  Referenced by: '<S241>/UD'

  real32_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S239>/UD'

  real32_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: '<S240>/UD'

  real32_T DiscreteDerivative1_ICPrevSca_o;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_o
                                 //  Referenced by: '<S358>/UD'

  real32_T DiscreteDerivative3_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative3_ICPrevScale
                                 //  Referenced by: '<S360>/UD'

  real32_T DiscreteDerivative2_ICPrevSca_n;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_n
                                 //  Referenced by: '<S159>/UD'

  real32_T DiscretePIDController1_InitialC;
                              // Mask Parameter: DiscretePIDController1_InitialC
                                 //  Referenced by: '<S280>/Filter'

  real32_T pid_ctrl_rollrate_InitialCondit;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCondit
                                 //  Referenced by: '<S517>/Integrator'

  real32_T DiscretePIDController2_InitialC;
                              // Mask Parameter: DiscretePIDController2_InitialC
                                 //  Referenced by: '<S337>/Integrator'

  real32_T pid_ctrl_rollrate1_InitialCondi;
                              // Mask Parameter: pid_ctrl_rollrate1_InitialCondi
                                 //  Referenced by: '<S571>/Integrator'

  real32_T pid_ctrl_rollrate2_InitialCondi;
                              // Mask Parameter: pid_ctrl_rollrate2_InitialCondi
                                 //  Referenced by: '<S625>/Integrator'

  real32_T pid_ctrl_rollrate_InitialCond_p;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCond_p
                                 //  Referenced by: '<S198>/Integrator'

  real32_T pid_ctrl_rollrate_LowerIntegrat;
                              // Mask Parameter: pid_ctrl_rollrate_LowerIntegrat
                                 //  Referenced by: '<S517>/Integrator'

  real32_T pid_ctrl_rollrate1_LowerIntegra;
                              // Mask Parameter: pid_ctrl_rollrate1_LowerIntegra
                                 //  Referenced by: '<S571>/Integrator'

  real32_T pid_ctrl_rollrate2_LowerIntegra;
                              // Mask Parameter: pid_ctrl_rollrate2_LowerIntegra
                                 //  Referenced by: '<S625>/Integrator'

  real32_T pid_ctrl_rollrate_LowerSaturati;
                              // Mask Parameter: pid_ctrl_rollrate_LowerSaturati
                                 //  Referenced by:
                                 //    '<S524>/Saturation'
                                 //    '<S509>/DeadZone'

  real32_T pid_ctrl_rollrate1_LowerSaturat;
                              // Mask Parameter: pid_ctrl_rollrate1_LowerSaturat
                                 //  Referenced by:
                                 //    '<S578>/Saturation'
                                 //    '<S563>/DeadZone'

  real32_T pid_ctrl_rollrate2_LowerSaturat;
                              // Mask Parameter: pid_ctrl_rollrate2_LowerSaturat
                                 //  Referenced by:
                                 //    '<S632>/Saturation'
                                 //    '<S617>/DeadZone'

  real32_T DiscretePIDController1_N; // Mask Parameter: DiscretePIDController1_N
                                        //  Referenced by: '<S288>/Filter Coefficient'

  real32_T DiscretePIDController1_P; // Mask Parameter: DiscretePIDController1_P
                                        //  Referenced by: '<S290>/Proportional Gain'

  real32_T pid_ctrl_rollrate_UpperIntegrat;
                              // Mask Parameter: pid_ctrl_rollrate_UpperIntegrat
                                 //  Referenced by: '<S517>/Integrator'

  real32_T pid_ctrl_rollrate1_UpperIntegra;
                              // Mask Parameter: pid_ctrl_rollrate1_UpperIntegra
                                 //  Referenced by: '<S571>/Integrator'

  real32_T pid_ctrl_rollrate2_UpperIntegra;
                              // Mask Parameter: pid_ctrl_rollrate2_UpperIntegra
                                 //  Referenced by: '<S625>/Integrator'

  real32_T pid_ctrl_rollrate_UpperSaturati;
                              // Mask Parameter: pid_ctrl_rollrate_UpperSaturati
                                 //  Referenced by:
                                 //    '<S524>/Saturation'
                                 //    '<S509>/DeadZone'

  real32_T pid_ctrl_rollrate1_UpperSaturat;
                              // Mask Parameter: pid_ctrl_rollrate1_UpperSaturat
                                 //  Referenced by:
                                 //    '<S578>/Saturation'
                                 //    '<S563>/DeadZone'

  real32_T pid_ctrl_rollrate2_UpperSaturat;
                              // Mask Parameter: pid_ctrl_rollrate2_UpperSaturat
                                 //  Referenced by:
                                 //    '<S632>/Saturation'
                                 //    '<S617>/DeadZone'

  real32_T CompareToConstant6_const; // Mask Parameter: CompareToConstant6_const
                                        //  Referenced by: '<S46>/Constant'

  real32_T CompareToConstant5_const; // Mask Parameter: CompareToConstant5_const
                                        //  Referenced by: '<S45>/Constant'

  uint16_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S11>/Constant'

  uint16_T CompareToConstant_const_a;
                                    // Mask Parameter: CompareToConstant_const_a
                                       //  Referenced by: '<S14>/Constant'

  uint16_T CompareToConstant1_const; // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: '<S41>/Constant'

  uint16_T CompareToConstant2_const; // Mask Parameter: CompareToConstant2_const
                                        //  Referenced by: '<S42>/Constant'

  uint16_T CompareToConstant4_const; // Mask Parameter: CompareToConstant4_const
                                        //  Referenced by: '<S44>/Constant'

  uint16_T CompareToConstant3_const; // Mask Parameter: CompareToConstant3_const
                                        //  Referenced by: '<S43>/Constant'

  uint16_T CompareToConstant_const_o;
                                    // Mask Parameter: CompareToConstant_const_o
                                       //  Referenced by: '<S237>/Constant'

  uint16_T CompareToConstant1_const_j;
                                   // Mask Parameter: CompareToConstant1_const_j
                                      //  Referenced by: '<S238>/Constant'

  uint16_T CompareToConstant_const_j;
                                    // Mask Parameter: CompareToConstant_const_j
                                       //  Referenced by: '<S357>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0;// Computed Parameter: Out1_Y0
                                            //  Referenced by: '<S232>/Out1'

  px4_Bus_vehicle_local_position Constant_Value;// Computed Parameter: Constant_Value
                                                   //  Referenced by: '<S226>/Constant'

  px4_Bus_vehicle_attitude_smc_setpoint Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                            //  Referenced by: '<S35>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0_c;  // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S235>/Out1'

  px4_Bus_vehicle_odometry Constant_Value_j;// Computed Parameter: Constant_Value_j
                                               //  Referenced by: '<S234>/Constant'

  px4_Bus_actuator_motors Constant_Value_e;// Computed Parameter: Constant_Value_e
                                              //  Referenced by: '<S37>/Constant'

  px4_Bus_input_rc Out1_Y0_h;          // Computed Parameter: Out1_Y0_h
                                          //  Referenced by: '<S220>/Out1'

  px4_Bus_input_rc Constant_Value_l;   // Computed Parameter: Constant_Value_l
                                          //  Referenced by: '<S219>/Constant'

  px4_Bus_vehicle_status Out1_Y0_e;    // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S231>/Out1'

  px4_Bus_vehicle_status Constant_Value_k;// Computed Parameter: Constant_Value_k
                                             //  Referenced by: '<S225>/Constant'

  px4_Bus_vehicle_local_position_setpoint Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                              //  Referenced by: '<S39>/Constant'

  px4_Bus_vehicle_attitude_setpoint Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                        //  Referenced by: '<S31>/Constant'

  px4_Bus_vehicle_angular_velocity Out1_Y0_a;// Computed Parameter: Out1_Y0_a
                                                //  Referenced by: '<S222>/Out1'

  px4_Bus_vehicle_angular_velocity Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                       //  Referenced by: '<S221>/Constant'

  px4_Bus_vehicle_rates_setpoint Constant_Value_ek;// Computed Parameter: Constant_Value_ek
                                                      //  Referenced by: '<S33>/Constant'

  px4_Bus_actuator_controls_status Constant_Value_l5;// Computed Parameter: Constant_Value_l5
                                                        //  Referenced by: '<S29>/Constant'

  px4_Bus_actuator_armed Out1_Y0_p;    // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S230>/Out1'

  px4_Bus_actuator_armed Out1_Y0_g;    // Computed Parameter: Out1_Y0_g
                                          //  Referenced by: '<S233>/Out1'

  px4_Bus_actuator_armed Constant_Value_f;// Computed Parameter: Constant_Value_f
                                             //  Referenced by: '<S224>/Constant'

  px4_Bus_actuator_armed Constant_Value_a;// Computed Parameter: Constant_Value_a
                                             //  Referenced by: '<S227>/Constant'

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
                                          //  Referenced by: '<S236>/Constant'

  real_T Constant1_Value_f;            // Expression: 1
                                          //  Referenced by: '<S236>/Constant1'

  real_T Constant2_Value_n;            // Expression: 1
                                          //  Referenced by: '<S236>/Constant2'

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
                                          //  Referenced by: '<S10>/Gain1'

  real32_T Gain_Gain_o;                // Computed Parameter: Gain_Gain_o
                                          //  Referenced by: '<S10>/Gain'

  real32_T Constant1_Value_j;          // Computed Parameter: Constant1_Value_j
                                          //  Referenced by: '<S507>/Constant1'

  real32_T Constant1_Value_jy;         // Computed Parameter: Constant1_Value_jy
                                          //  Referenced by: '<S561>/Constant1'

  real32_T Constant1_Value_i;          // Computed Parameter: Constant1_Value_i
                                          //  Referenced by: '<S615>/Constant1'

  real32_T Mixermatrix_Value[24];      // Computed Parameter: Mixermatrix_Value
                                          //  Referenced by: '<S13>/Mixer matrix'

  real32_T Constant1_Value_k;          // Computed Parameter: Constant1_Value_k
                                          //  Referenced by: '<S13>/Constant1'

  real32_T RateTransition4_InitialConditio;
                          // Computed Parameter: RateTransition4_InitialConditio
                             //  Referenced by: '<S10>/Rate Transition4'

  real32_T RateTransition5_InitialConditio;
                          // Computed Parameter: RateTransition5_InitialConditio
                             //  Referenced by: '<S10>/Rate Transition5'

  real32_T RateTransition2_InitialConditio;
                          // Computed Parameter: RateTransition2_InitialConditio
                             //  Referenced by: '<S10>/Rate Transition2'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S517>/Integrator'

  real32_T RateTransition18_InitialConditi;
                          // Computed Parameter: RateTransition18_InitialConditi
                             //  Referenced by: '<S10>/Rate Transition18'

  real32_T UnitDelay1_InitialCondition;
                              // Computed Parameter: UnitDelay1_InitialCondition
                                 //  Referenced by: '<S371>/Unit Delay1'

  real32_T RateTransition3_InitialConditio;
                          // Computed Parameter: RateTransition3_InitialConditio
                             //  Referenced by: '<S10>/Rate Transition3'

  real32_T tau_Gain;                   // Computed Parameter: tau_Gain
                                          //  Referenced by: '<S371>/tau'

  real32_T Bias_Bias;                  // Computed Parameter: Bias_Bias
                                          //  Referenced by: '<S372>/Bias'

  real32_T Gain_Gain_a;                // Computed Parameter: Gain_Gain_a
                                          //  Referenced by: '<S372>/Gain'

  real32_T TSamp_WtEt;                 // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S359>/TSamp'

  real32_T RateTransition2_InitialCondit_h;
                          // Computed Parameter: RateTransition2_InitialCondit_h
                             //  Referenced by: '<S9>/Rate Transition2'

  real32_T TSamp_WtEt_m;               // Computed Parameter: TSamp_WtEt_m
                                          //  Referenced by: '<S241>/TSamp'

  real32_T RateTransition4_InitialCondit_m;
                          // Computed Parameter: RateTransition4_InitialCondit_m
                             //  Referenced by: '<S9>/Rate Transition4'

  real32_T RateTransition5_InitialCondit_g;
                          // Computed Parameter: RateTransition5_InitialCondit_g
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
                                          //  Referenced by: '<S355>/tau'

  real32_T Bias_Bias_h;                // Computed Parameter: Bias_Bias_h
                                          //  Referenced by: '<S356>/Bias'

  real32_T RateTransition1_InitialConditio;
                          // Computed Parameter: RateTransition1_InitialConditio
                             //  Referenced by: '<S9>/Rate Transition1'

  real32_T UnitDelay_InitialCondition;
                               // Computed Parameter: UnitDelay_InitialCondition
                                  //  Referenced by: '<S355>/Unit Delay'

  real32_T TSamp_WtEt_p;               // Computed Parameter: TSamp_WtEt_p
                                          //  Referenced by: '<S239>/TSamp'

  real32_T TSamp_WtEt_l;               // Computed Parameter: TSamp_WtEt_l
                                          //  Referenced by: '<S240>/TSamp'

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
                                          //  Referenced by: '<S280>/Filter'

  real32_T Integrator_gainval_c;     // Computed Parameter: Integrator_gainval_c
                                        //  Referenced by: '<S337>/Integrator'

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

  real32_T RateTransition8_InitialCondit_c;
                          // Computed Parameter: RateTransition8_InitialCondit_c
                             //  Referenced by: '<S10>/Rate Transition8'

  real32_T RateTransition19_InitialConditi;
                          // Computed Parameter: RateTransition19_InitialConditi
                             //  Referenced by: '<S10>/Rate Transition19'

  real32_T Integrator_gainval_l;     // Computed Parameter: Integrator_gainval_l
                                        //  Referenced by: '<S571>/Integrator'

  real32_T RateTransition10_InitialCondi_k;
                          // Computed Parameter: RateTransition10_InitialCondi_k
                             //  Referenced by: '<S10>/Rate Transition10'

  real32_T UnitDelay1_InitialCondition_i;
                            // Computed Parameter: UnitDelay1_InitialCondition_i
                               //  Referenced by: '<S369>/Unit Delay1'

  real32_T RateTransition7_InitialCondit_l;
                          // Computed Parameter: RateTransition7_InitialCondit_l
                             //  Referenced by: '<S10>/Rate Transition7'

  real32_T tau_Gain_k;                 // Computed Parameter: tau_Gain_k
                                          //  Referenced by: '<S369>/tau'

  real32_T Bias_Bias_b;                // Computed Parameter: Bias_Bias_b
                                          //  Referenced by: '<S370>/Bias'

  real32_T Gain_Gain_b3;               // Computed Parameter: Gain_Gain_b3
                                          //  Referenced by: '<S370>/Gain'

  real32_T TSamp_WtEt_d;               // Computed Parameter: TSamp_WtEt_d
                                          //  Referenced by: '<S358>/TSamp'

  real32_T RateTransition_InitialCondition;
                          // Computed Parameter: RateTransition_InitialCondition
                             //  Referenced by: '<S10>/Rate Transition'

  real32_T RateTransition1_InitialCondit_e;
                          // Computed Parameter: RateTransition1_InitialCondit_e
                             //  Referenced by: '<S10>/Rate Transition1'

  real32_T RateTransition13_InitialCondi_h;
                          // Computed Parameter: RateTransition13_InitialCondi_h
                             //  Referenced by: '<S10>/Rate Transition13'

  real32_T RateTransition20_InitialConditi;
                          // Computed Parameter: RateTransition20_InitialConditi
                             //  Referenced by: '<S10>/Rate Transition20'

  real32_T Integrator_gainval_e;     // Computed Parameter: Integrator_gainval_e
                                        //  Referenced by: '<S625>/Integrator'

  real32_T RateTransition11_InitialCondi_g;
                          // Computed Parameter: RateTransition11_InitialCondi_g
                             //  Referenced by: '<S10>/Rate Transition11'

  real32_T UnitDelay1_InitialCondition_m;
                            // Computed Parameter: UnitDelay1_InitialCondition_m
                               //  Referenced by: '<S373>/Unit Delay1'

  real32_T RateTransition12_InitialCondi_h;
                          // Computed Parameter: RateTransition12_InitialCondi_h
                             //  Referenced by: '<S10>/Rate Transition12'

  real32_T tau_Gain_d;                 // Computed Parameter: tau_Gain_d
                                          //  Referenced by: '<S373>/tau'

  real32_T Bias_Bias_p;                // Computed Parameter: Bias_Bias_p
                                          //  Referenced by: '<S374>/Bias'

  real32_T Gain_Gain_ow;               // Computed Parameter: Gain_Gain_ow
                                          //  Referenced by: '<S374>/Gain'

  real32_T TSamp_WtEt_b;               // Computed Parameter: TSamp_WtEt_b
                                          //  Referenced by: '<S360>/TSamp'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S13>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S13>/Saturation1'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S13>/Gain2'

  real32_T Constant_Value_ew;          // Computed Parameter: Constant_Value_ew
                                          //  Referenced by: '<S21>/Constant'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S21>/Gain'

  real32_T Constant_Value_b;           // Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<S15>/Constant'

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

  real32_T Bias1_Bias;                 // Computed Parameter: Bias1_Bias
                                          //  Referenced by: '<S374>/Bias1'

  real32_T Gain1_Gain_b;               // Computed Parameter: Gain1_Gain_b
                                          //  Referenced by: '<S373>/Gain1'

  real32_T UnitDelay2_InitialCondition;
                              // Computed Parameter: UnitDelay2_InitialCondition
                                 //  Referenced by: '<S373>/Unit Delay2'

  real32_T Clamping_zero_Value;       // Computed Parameter: Clamping_zero_Value
                                         //  Referenced by: '<S615>/Clamping_zero'

  real32_T RateTransition14_InitialCondi_f;
                          // Computed Parameter: RateTransition14_InitialCondi_f
                             //  Referenced by: '<S10>/Rate Transition14'

  real32_T Bias1_Bias_o;               // Computed Parameter: Bias1_Bias_o
                                          //  Referenced by: '<S370>/Bias1'

  real32_T Gain1_Gain_l;               // Computed Parameter: Gain1_Gain_l
                                          //  Referenced by: '<S369>/Gain1'

  real32_T UnitDelay2_InitialCondition_i;
                            // Computed Parameter: UnitDelay2_InitialCondition_i
                               //  Referenced by: '<S369>/Unit Delay2'

  real32_T Clamping_zero_Value_a;   // Computed Parameter: Clamping_zero_Value_a
                                       //  Referenced by: '<S561>/Clamping_zero'

  real32_T RateTransition9_InitialCondit_i;
                          // Computed Parameter: RateTransition9_InitialCondit_i
                             //  Referenced by: '<S10>/Rate Transition9'

  real32_T Gain_Gain_ar;               // Computed Parameter: Gain_Gain_ar
                                          //  Referenced by: '<S356>/Gain'

  real32_T Bias1_Bias_k;               // Computed Parameter: Bias1_Bias_k
                                          //  Referenced by: '<S356>/Bias1'

  real32_T Bias1_Bias_f;               // Computed Parameter: Bias1_Bias_f
                                          //  Referenced by: '<S372>/Bias1'

  real32_T Gain1_Gain_h;               // Computed Parameter: Gain1_Gain_h
                                          //  Referenced by: '<S371>/Gain1'

  real32_T UnitDelay2_InitialCondition_n;
                            // Computed Parameter: UnitDelay2_InitialCondition_n
                               //  Referenced by: '<S371>/Unit Delay2'

  real32_T Clamping_zero_Value_b;   // Computed Parameter: Clamping_zero_Value_b
                                       //  Referenced by: '<S507>/Clamping_zero'

  real32_T RateTransition6_InitialCondit_f;
                          // Computed Parameter: RateTransition6_InitialCondit_f
                             //  Referenced by: '<S10>/Rate Transition6'

  real32_T Gain_Gain_az;               // Computed Parameter: Gain_Gain_az
                                          //  Referenced by: '<S54>/Gain'

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

  real32_T Gain2_Gain_l;               // Computed Parameter: Gain2_Gain_l
                                          //  Referenced by: '<S4>/Gain2'

  real32_T DeadZone2_Start;            // Computed Parameter: DeadZone2_Start
                                          //  Referenced by: '<S4>/Dead Zone2'

  real32_T DeadZone2_End;              // Computed Parameter: DeadZone2_End
                                          //  Referenced by: '<S4>/Dead Zone2'

  real32_T Saturation1_UpperSat_p; // Computed Parameter: Saturation1_UpperSat_p
                                      //  Referenced by: '<S4>/Saturation1'

  real32_T Saturation1_LowerSat_e; // Computed Parameter: Saturation1_LowerSat_e
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

  real32_T Integrator_gainval_ei;   // Computed Parameter: Integrator_gainval_ei
                                       //  Referenced by: '<S198>/Integrator'

  real32_T UnitDelay1_InitialCondition_e;
                            // Computed Parameter: UnitDelay1_InitialCondition_e
                               //  Referenced by: '<S162>/Unit Delay1'

  real32_T tau_Gain_g;                 // Computed Parameter: tau_Gain_g
                                          //  Referenced by: '<S162>/tau'

  real32_T Bias_Bias_n;                // Computed Parameter: Bias_Bias_n
                                          //  Referenced by: '<S163>/Bias'

  real32_T Gain_Gain_oj;               // Computed Parameter: Gain_Gain_oj
                                          //  Referenced by: '<S163>/Gain'

  real32_T TSamp_WtEt_n;               // Computed Parameter: TSamp_WtEt_n
                                          //  Referenced by: '<S159>/TSamp'

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
                                          //  Referenced by: '<S25>/1//2'

  real32_T Constant_Value_i;           // Computed Parameter: Constant_Value_i
                                          //  Referenced by: '<S3>/Constant'

  real32_T Gain1_Gain_o;               // Computed Parameter: Gain1_Gain_o
                                          //  Referenced by: '<S216>/Gain1'

  real32_T Gain1_Gain_j;               // Computed Parameter: Gain1_Gain_j
                                          //  Referenced by: '<S217>/Gain1'

  real32_T Constant3_Value_m;          // Computed Parameter: Constant3_Value_m
                                          //  Referenced by: '<S3>/Constant3'

  real32_T Bias1_Bias_m;               // Computed Parameter: Bias1_Bias_m
                                          //  Referenced by: '<S163>/Bias1'

  real32_T Gain1_Gain_a;               // Computed Parameter: Gain1_Gain_a
                                          //  Referenced by: '<S162>/Gain1'

  real32_T UnitDelay2_InitialCondition_m;
                            // Computed Parameter: UnitDelay2_InitialCondition_m
                               //  Referenced by: '<S162>/Unit Delay2'

  real32_T Gain_Gain_eb;               // Computed Parameter: Gain_Gain_eb
                                          //  Referenced by: '<S9>/Gain'

  uint16_T RateTransition_8_InitialConditi;
                          // Computed Parameter: RateTransition_8_InitialConditi
                             //  Referenced by: '<Root>/Rate Transition'

  uint16_T Constant4_Value_f[6];       // Computed Parameter: Constant4_Value_f
                                          //  Referenced by: '<S3>/Constant4'

  uint16_T Saturation_UpperSat_d;   // Computed Parameter: Saturation_UpperSat_d
                                       //  Referenced by: '<S21>/Saturation'

  uint16_T Saturation_LowerSat_d0; // Computed Parameter: Saturation_LowerSat_d0
                                      //  Referenced by: '<S21>/Saturation'

  uint16_T RateTransition_4_InitialConditi;
                          // Computed Parameter: RateTransition_4_InitialConditi
                             //  Referenced by: '<Root>/Rate Transition'

  boolean_T RateTransition15_InitialConditi;
                          // Computed Parameter: RateTransition15_InitialConditi
                             //  Referenced by: '<S10>/Rate Transition15'

  boolean_T RateTransition16_InitialConditi;
                          // Computed Parameter: RateTransition16_InitialConditi
                             //  Referenced by: '<S9>/Rate Transition16'

  boolean_T RateTransition15_InitialCondi_p;
                          // Computed Parameter: RateTransition15_InitialCondi_p
                             //  Referenced by: '<S9>/Rate Transition15'

  boolean_T RateTransition16_InitialCondi_i;
                          // Computed Parameter: RateTransition16_InitialCondi_i
                             //  Referenced by: '<S10>/Rate Transition16'

  boolean_T RateTransition17_InitialCondi_p;
                          // Computed Parameter: RateTransition17_InitialCondi_p
                             //  Referenced by: '<S10>/Rate Transition17'

  boolean_T RateTransition2_16_InitialCondi;
                          // Computed Parameter: RateTransition2_16_InitialCondi
                             //  Referenced by: '<Root>/Rate Transition2'

  boolean_T RateTransition2_17_InitialCondi;
                          // Computed Parameter: RateTransition2_17_InitialCondi
                             //  Referenced by: '<Root>/Rate Transition2'

  int8_T Constant_Value_dr;            // Computed Parameter: Constant_Value_dr
                                          //  Referenced by: '<S507>/Constant'

  int8_T Constant2_Value_ns;           // Computed Parameter: Constant2_Value_ns
                                          //  Referenced by: '<S507>/Constant2'

  int8_T Constant3_Value_n;            // Computed Parameter: Constant3_Value_n
                                          //  Referenced by: '<S507>/Constant3'

  int8_T Constant4_Value_b;            // Computed Parameter: Constant4_Value_b
                                          //  Referenced by: '<S507>/Constant4'

  int8_T Constant_Value_fd;            // Computed Parameter: Constant_Value_fd
                                          //  Referenced by: '<S561>/Constant'

  int8_T Constant2_Value_g;            // Computed Parameter: Constant2_Value_g
                                          //  Referenced by: '<S561>/Constant2'

  int8_T Constant3_Value_b;            // Computed Parameter: Constant3_Value_b
                                          //  Referenced by: '<S561>/Constant3'

  int8_T Constant4_Value_h;            // Computed Parameter: Constant4_Value_h
                                          //  Referenced by: '<S561>/Constant4'

  int8_T Constant_Value_gl;            // Computed Parameter: Constant_Value_gl
                                          //  Referenced by: '<S615>/Constant'

  int8_T Constant2_Value_i;            // Computed Parameter: Constant2_Value_i
                                          //  Referenced by: '<S615>/Constant2'

  int8_T Constant3_Value_nf;           // Computed Parameter: Constant3_Value_nf
                                          //  Referenced by: '<S615>/Constant3'

  int8_T Constant4_Value_e;            // Computed Parameter: Constant4_Value_e
                                          //  Referenced by: '<S615>/Constant4'

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
//  Block '<S159>/Data Type Duplicate' : Unused code path elimination
//  Block '<S219>/NOT' : Unused code path elimination
//  Block '<S221>/NOT' : Unused code path elimination
//  Block '<S224>/NOT' : Unused code path elimination
//  Block '<S225>/NOT' : Unused code path elimination
//  Block '<S226>/NOT' : Unused code path elimination
//  Block '<S227>/NOT' : Unused code path elimination
//  Block '<S234>/NOT' : Unused code path elimination
//  Block '<S228>/Signal Copy' : Unused code path elimination
//  Block '<S228>/Signal Copy1' : Unused code path elimination
//  Block '<S228>/Signal Copy2' : Unused code path elimination
//  Block '<S239>/Data Type Duplicate' : Unused code path elimination
//  Block '<S240>/Data Type Duplicate' : Unused code path elimination
//  Block '<S241>/Data Type Duplicate' : Unused code path elimination
//  Block '<S358>/Data Type Duplicate' : Unused code path elimination
//  Block '<S359>/Data Type Duplicate' : Unused code path elimination
//  Block '<S360>/Data Type Duplicate' : Unused code path elimination
//  Block '<S417>/Data Type Duplicate' : Unused code path elimination
//  Block '<S417>/Data Type Propagation' : Unused code path elimination
//  Block '<S470>/Data Type Duplicate' : Unused code path elimination
//  Block '<S470>/Data Type Propagation' : Unused code path elimination
//  Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S8>/Data Type Conversion9' : Eliminate redundant data type conversion
//  Block '<S236>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S9>/Rate Transition3' : Eliminated since input and output rates are identical


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
//  '<S14>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Fault_Injection/Compare To Constant'
//  '<S15>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Fault_Injection/Subsystem Reference'
//  '<S16>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Fault_Injection/Subsystem Reference1'
//  '<S17>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Fault_Injection/Subsystem Reference2'
//  '<S18>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Fault_Injection/Subsystem Reference3'
//  '<S19>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Fault_Injection/Subsystem Reference4'
//  '<S20>'  : 'FLIGHT_Hexacopter_V2/ControlAllocation(CA)/Fault_Injection/Subsystem Reference5'
//  '<S21>'  : 'FLIGHT_Hexacopter_V2/Logging/Normalize_pwm6'
//  '<S22>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog ActuatorControlsStatus'
//  '<S23>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog VehicleAttitudeSetpoint'
//  '<S24>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog2 VehicleRatesSetpoint'
//  '<S25>'  : 'FLIGHT_Hexacopter_V2/Logging/Rotation Angles to Quaternions'
//  '<S26>'  : 'FLIGHT_Hexacopter_V2/Logging/Subsystem'
//  '<S27>'  : 'FLIGHT_Hexacopter_V2/Logging/ULog_ActuatorMotors'
//  '<S28>'  : 'FLIGHT_Hexacopter_V2/Logging/ULog_VehicleLocalPositionSetpoint'
//  '<S29>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog ActuatorControlsStatus/PX4 uORB Message'
//  '<S30>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog ActuatorControlsStatus/PX4_log_write'
//  '<S31>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog VehicleAttitudeSetpoint/PX4 uORB Message'
//  '<S32>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog VehicleAttitudeSetpoint/PX4_log_write'
//  '<S33>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog2 VehicleRatesSetpoint/PX4 uORB Message'
//  '<S34>'  : 'FLIGHT_Hexacopter_V2/Logging/PX4 ULog2 VehicleRatesSetpoint/PX4_log_write'
//  '<S35>'  : 'FLIGHT_Hexacopter_V2/Logging/Subsystem/PX4 uORB Message'
//  '<S36>'  : 'FLIGHT_Hexacopter_V2/Logging/Subsystem/PX4 uORB Write'
//  '<S37>'  : 'FLIGHT_Hexacopter_V2/Logging/ULog_ActuatorMotors/PX4 uORB Message'
//  '<S38>'  : 'FLIGHT_Hexacopter_V2/Logging/ULog_ActuatorMotors/PX4_log_write'
//  '<S39>'  : 'FLIGHT_Hexacopter_V2/Logging/ULog_VehicleLocalPositionSetpoint/PX4 uORB Message'
//  '<S40>'  : 'FLIGHT_Hexacopter_V2/Logging/ULog_VehicleLocalPositionSetpoint/PX4_log_write'
//  '<S41>'  : 'FLIGHT_Hexacopter_V2/OFP/Compare To Constant1'
//  '<S42>'  : 'FLIGHT_Hexacopter_V2/OFP/Compare To Constant2'
//  '<S43>'  : 'FLIGHT_Hexacopter_V2/OFP/Compare To Constant3'
//  '<S44>'  : 'FLIGHT_Hexacopter_V2/OFP/Compare To Constant4'
//  '<S45>'  : 'FLIGHT_Hexacopter_V2/OFP/Compare To Constant5'
//  '<S46>'  : 'FLIGHT_Hexacopter_V2/OFP/Compare To Constant6'
//  '<S47>'  : 'FLIGHT_Hexacopter_V2/OFP/MATLAB Function'
//  '<S48>'  : 'FLIGHT_Hexacopter_V2/OFP/MATLAB Function1'
//  '<S49>'  : 'FLIGHT_Hexacopter_V2/OFP/MATLAB Function2'
//  '<S50>'  : 'FLIGHT_Hexacopter_V2/OFP/NED2Body1'
//  '<S51>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude'
//  '<S52>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1'
//  '<S53>'  : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference'
//  '<S54>'  : 'FLIGHT_Hexacopter_V2/OFP/NED2Body1/Calculate Transformation Matrix'
//  '<S55>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Anti-windup'
//  '<S56>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/D Gain'
//  '<S57>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/External Derivative'
//  '<S58>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Filter'
//  '<S59>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Filter ICs'
//  '<S60>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/I Gain'
//  '<S61>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Ideal P Gain'
//  '<S62>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Ideal P Gain Fdbk'
//  '<S63>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Integrator'
//  '<S64>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Integrator ICs'
//  '<S65>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/N Copy'
//  '<S66>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/N Gain'
//  '<S67>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/P Copy'
//  '<S68>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Parallel P Gain'
//  '<S69>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Reset Signal'
//  '<S70>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Saturation'
//  '<S71>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Saturation Fdbk'
//  '<S72>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Sum'
//  '<S73>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Sum Fdbk'
//  '<S74>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tracking Mode'
//  '<S75>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tracking Mode Sum'
//  '<S76>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tsamp - Integral'
//  '<S77>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tsamp - Ngain'
//  '<S78>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/postSat Signal'
//  '<S79>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/preInt Signal'
//  '<S80>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/preSat Signal'
//  '<S81>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Anti-windup/Disabled'
//  '<S82>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/D Gain/Disabled'
//  '<S83>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/External Derivative/Disabled'
//  '<S84>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Filter/Disabled'
//  '<S85>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Filter ICs/Disabled'
//  '<S86>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/I Gain/Disabled'
//  '<S87>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S88>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Ideal P Gain Fdbk/Disabled'
//  '<S89>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Integrator/Disabled'
//  '<S90>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Integrator ICs/Disabled'
//  '<S91>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/N Copy/Disabled wSignal Specification'
//  '<S92>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/N Gain/Disabled'
//  '<S93>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/P Copy/Disabled'
//  '<S94>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Parallel P Gain/External Parameters'
//  '<S95>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Reset Signal/Disabled'
//  '<S96>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Saturation/Passthrough'
//  '<S97>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Saturation Fdbk/Disabled'
//  '<S98>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Sum/Passthrough_P'
//  '<S99>'  : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Sum Fdbk/Disabled'
//  '<S100>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tracking Mode/Disabled'
//  '<S101>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S102>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S103>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S104>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/postSat Signal/Forward_Path'
//  '<S105>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/preInt Signal/Internal PreInt'
//  '<S106>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude/preSat Signal/Forward_Path'
//  '<S107>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Anti-windup'
//  '<S108>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/D Gain'
//  '<S109>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/External Derivative'
//  '<S110>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Filter'
//  '<S111>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Filter ICs'
//  '<S112>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/I Gain'
//  '<S113>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Ideal P Gain'
//  '<S114>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Ideal P Gain Fdbk'
//  '<S115>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Integrator'
//  '<S116>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Integrator ICs'
//  '<S117>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/N Copy'
//  '<S118>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/N Gain'
//  '<S119>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/P Copy'
//  '<S120>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Parallel P Gain'
//  '<S121>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Reset Signal'
//  '<S122>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Saturation'
//  '<S123>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Saturation Fdbk'
//  '<S124>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Sum'
//  '<S125>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Sum Fdbk'
//  '<S126>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tracking Mode'
//  '<S127>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tracking Mode Sum'
//  '<S128>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tsamp - Integral'
//  '<S129>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tsamp - Ngain'
//  '<S130>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/postSat Signal'
//  '<S131>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/preInt Signal'
//  '<S132>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/preSat Signal'
//  '<S133>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Anti-windup/Disabled'
//  '<S134>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/D Gain/Disabled'
//  '<S135>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/External Derivative/Disabled'
//  '<S136>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Filter/Disabled'
//  '<S137>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Filter ICs/Disabled'
//  '<S138>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/I Gain/Disabled'
//  '<S139>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Ideal P Gain/Passthrough'
//  '<S140>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Ideal P Gain Fdbk/Disabled'
//  '<S141>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Integrator/Disabled'
//  '<S142>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Integrator ICs/Disabled'
//  '<S143>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/N Copy/Disabled wSignal Specification'
//  '<S144>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/N Gain/Disabled'
//  '<S145>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/P Copy/Disabled'
//  '<S146>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Parallel P Gain/External Parameters'
//  '<S147>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Reset Signal/Disabled'
//  '<S148>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Saturation/Passthrough'
//  '<S149>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Saturation Fdbk/Disabled'
//  '<S150>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Sum/Passthrough_P'
//  '<S151>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Sum Fdbk/Disabled'
//  '<S152>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tracking Mode/Disabled'
//  '<S153>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tracking Mode Sum/Passthrough'
//  '<S154>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tsamp - Integral/TsSignalSpecification'
//  '<S155>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/Tsamp - Ngain/Passthrough'
//  '<S156>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/postSat Signal/Forward_Path'
//  '<S157>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/preInt Signal/Internal PreInt'
//  '<S158>' : 'FLIGHT_Hexacopter_V2/OFP/PID_Altitude1/preSat Signal/Forward_Path'
//  '<S159>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/Discrete Derivative2'
//  '<S160>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/Discrete Varying Lowpass2'
//  '<S161>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate'
//  '<S162>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/Discrete Varying Lowpass2/SOS1'
//  '<S163>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/Discrete Varying Lowpass2/SOS1/Arithmetic'
//  '<S164>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Anti-windup'
//  '<S165>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/D Gain'
//  '<S166>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/External Derivative'
//  '<S167>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Filter'
//  '<S168>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Filter ICs'
//  '<S169>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/I Gain'
//  '<S170>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Ideal P Gain'
//  '<S171>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Ideal P Gain Fdbk'
//  '<S172>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Integrator'
//  '<S173>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Integrator ICs'
//  '<S174>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/N Copy'
//  '<S175>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/N Gain'
//  '<S176>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/P Copy'
//  '<S177>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Parallel P Gain'
//  '<S178>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Reset Signal'
//  '<S179>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Saturation'
//  '<S180>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Saturation Fdbk'
//  '<S181>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Sum'
//  '<S182>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Sum Fdbk'
//  '<S183>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Tracking Mode'
//  '<S184>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Tracking Mode Sum'
//  '<S185>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Tsamp - Integral'
//  '<S186>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Tsamp - Ngain'
//  '<S187>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/postSat Signal'
//  '<S188>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/preInt Signal'
//  '<S189>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/preSat Signal'
//  '<S190>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Anti-windup/Passthrough'
//  '<S191>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/D Gain/Disabled'
//  '<S192>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/External Derivative/Disabled'
//  '<S193>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Filter/Disabled'
//  '<S194>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Filter ICs/Disabled'
//  '<S195>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/I Gain/External Parameters'
//  '<S196>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Ideal P Gain/Passthrough'
//  '<S197>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Ideal P Gain Fdbk/Disabled'
//  '<S198>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Integrator/Discrete'
//  '<S199>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Integrator ICs/Internal IC'
//  '<S200>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/N Copy/Disabled wSignal Specification'
//  '<S201>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/N Gain/Disabled'
//  '<S202>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/P Copy/Disabled'
//  '<S203>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Parallel P Gain/External Parameters'
//  '<S204>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Reset Signal/External Reset'
//  '<S205>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Saturation/Passthrough'
//  '<S206>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Saturation Fdbk/Disabled'
//  '<S207>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Sum/Sum_PI'
//  '<S208>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Sum Fdbk/Disabled'
//  '<S209>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Tracking Mode/Disabled'
//  '<S210>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Tracking Mode Sum/Passthrough'
//  '<S211>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Tsamp - Integral/TsSignalSpecification'
//  '<S212>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/Tsamp - Ngain/Passthrough'
//  '<S213>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/postSat Signal/Forward_Path'
//  '<S214>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/preInt Signal/Internal PreInt'
//  '<S215>' : 'FLIGHT_Hexacopter_V2/OFP/Subsystem Reference/pid_ctrl_rollrate/preSat Signal/Forward_Path'
//  '<S216>' : 'FLIGHT_Hexacopter_V2/Parameters_PARAMS/Degrees to Radians'
//  '<S217>' : 'FLIGHT_Hexacopter_V2/Parameters_PARAMS/Degrees to Radians1'
//  '<S218>' : 'FLIGHT_Hexacopter_V2/Parameters_PARAMS/MATLAB Function'
//  '<S219>' : 'FLIGHT_Hexacopter_V2/RCCommand(CMD)/PX4 uORB Read'
//  '<S220>' : 'FLIGHT_Hexacopter_V2/RCCommand(CMD)/PX4 uORB Read/Enabled Subsystem'
//  '<S221>' : 'FLIGHT_Hexacopter_V2/Read_uORB(1000hz)_SENSORS1000/PX4 uORB Read1'
//  '<S222>' : 'FLIGHT_Hexacopter_V2/Read_uORB(1000hz)_SENSORS1000/PX4 uORB Read1/Enabled Subsystem'
//  '<S223>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/MATLAB Function'
//  '<S224>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read'
//  '<S225>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read1'
//  '<S226>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read2'
//  '<S227>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read3'
//  '<S228>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/Vehicle Attitude'
//  '<S229>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/quat2eul'
//  '<S230>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read/Enabled Subsystem'
//  '<S231>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read1/Enabled Subsystem'
//  '<S232>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read2/Enabled Subsystem'
//  '<S233>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/PX4 uORB Read3/Enabled Subsystem'
//  '<S234>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/Vehicle Attitude/PX4 uORB Read'
//  '<S235>' : 'FLIGHT_Hexacopter_V2/Read_uORB(250hz)_SENSORS250/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'
//  '<S236>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Calc_Fx_Gx'
//  '<S237>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Compare To Constant'
//  '<S238>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Compare To Constant1'
//  '<S239>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Derivative'
//  '<S240>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Derivative1'
//  '<S241>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Derivative2'
//  '<S242>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1'
//  '<S243>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2'
//  '<S244>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Varying Lowpass'
//  '<S245>' : 'FLIGHT_Hexacopter_V2/Roll SMC/MATLAB Function'
//  '<S246>' : 'FLIGHT_Hexacopter_V2/Roll SMC/MATLAB Function1'
//  '<S247>' : 'FLIGHT_Hexacopter_V2/Roll SMC/MATLAB Function2'
//  '<S248>' : 'FLIGHT_Hexacopter_V2/Roll SMC/MATLAB Function3'
//  '<S249>' : 'FLIGHT_Hexacopter_V2/Roll SMC/MATLAB Function4'
//  '<S250>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Omega_phi'
//  '<S251>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Anti-windup'
//  '<S252>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/D Gain'
//  '<S253>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/External Derivative'
//  '<S254>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Filter'
//  '<S255>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Filter ICs'
//  '<S256>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/I Gain'
//  '<S257>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Ideal P Gain'
//  '<S258>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S259>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Integrator'
//  '<S260>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Integrator ICs'
//  '<S261>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/N Copy'
//  '<S262>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/N Gain'
//  '<S263>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/P Copy'
//  '<S264>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Parallel P Gain'
//  '<S265>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Reset Signal'
//  '<S266>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Saturation'
//  '<S267>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Saturation Fdbk'
//  '<S268>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Sum'
//  '<S269>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Sum Fdbk'
//  '<S270>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Tracking Mode'
//  '<S271>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Tracking Mode Sum'
//  '<S272>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Tsamp - Integral'
//  '<S273>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Tsamp - Ngain'
//  '<S274>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/postSat Signal'
//  '<S275>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/preInt Signal'
//  '<S276>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/preSat Signal'
//  '<S277>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Anti-windup/Disabled'
//  '<S278>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/D Gain/Internal Parameters'
//  '<S279>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/External Derivative/Error'
//  '<S280>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S281>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S282>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/I Gain/Disabled'
//  '<S283>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S284>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S285>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Integrator/Disabled'
//  '<S286>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Integrator ICs/Disabled'
//  '<S287>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/N Copy/Disabled'
//  '<S288>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/N Gain/Internal Parameters'
//  '<S289>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/P Copy/Disabled'
//  '<S290>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S291>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S292>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Saturation/Passthrough'
//  '<S293>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S294>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Sum/Sum_PD'
//  '<S295>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S296>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S297>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S298>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S299>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S300>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S301>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/preInt Signal/Internal PreInt'
//  '<S302>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S303>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Anti-windup'
//  '<S304>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/D Gain'
//  '<S305>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/External Derivative'
//  '<S306>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Filter'
//  '<S307>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Filter ICs'
//  '<S308>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/I Gain'
//  '<S309>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Ideal P Gain'
//  '<S310>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Ideal P Gain Fdbk'
//  '<S311>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Integrator'
//  '<S312>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Integrator ICs'
//  '<S313>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/N Copy'
//  '<S314>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/N Gain'
//  '<S315>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/P Copy'
//  '<S316>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Parallel P Gain'
//  '<S317>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Reset Signal'
//  '<S318>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Saturation'
//  '<S319>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Saturation Fdbk'
//  '<S320>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Sum'
//  '<S321>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Sum Fdbk'
//  '<S322>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Tracking Mode'
//  '<S323>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Tracking Mode Sum'
//  '<S324>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Tsamp - Integral'
//  '<S325>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Tsamp - Ngain'
//  '<S326>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/postSat Signal'
//  '<S327>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/preInt Signal'
//  '<S328>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/preSat Signal'
//  '<S329>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Anti-windup/Passthrough'
//  '<S330>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/D Gain/Disabled'
//  '<S331>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/External Derivative/Disabled'
//  '<S332>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Filter/Disabled'
//  '<S333>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Filter ICs/Disabled'
//  '<S334>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/I Gain/Internal Parameters'
//  '<S335>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Ideal P Gain/Passthrough'
//  '<S336>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S337>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Integrator/Discrete'
//  '<S338>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Integrator ICs/Internal IC'
//  '<S339>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/N Copy/Disabled wSignal Specification'
//  '<S340>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/N Gain/Disabled'
//  '<S341>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/P Copy/Disabled'
//  '<S342>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Parallel P Gain/Disabled'
//  '<S343>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Reset Signal/External Reset'
//  '<S344>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Saturation/Passthrough'
//  '<S345>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Saturation Fdbk/Disabled'
//  '<S346>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Sum/Passthrough_I'
//  '<S347>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Sum Fdbk/Disabled'
//  '<S348>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Tracking Mode/Disabled'
//  '<S349>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S350>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S351>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S352>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/postSat Signal/Forward_Path'
//  '<S353>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/preInt Signal/Internal PreInt'
//  '<S354>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete PID Controller2/preSat Signal/Forward_Path'
//  '<S355>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Varying Lowpass/FOS'
//  '<S356>' : 'FLIGHT_Hexacopter_V2/Roll SMC/Discrete Varying Lowpass/FOS/Arithmetic'
//  '<S357>' : 'FLIGHT_Hexacopter_V2/SCAS/Compare To Constant'
//  '<S358>' : 'FLIGHT_Hexacopter_V2/SCAS/Discrete Derivative1'
//  '<S359>' : 'FLIGHT_Hexacopter_V2/SCAS/Discrete Derivative2'
//  '<S360>' : 'FLIGHT_Hexacopter_V2/SCAS/Discrete Derivative3'
//  '<S361>' : 'FLIGHT_Hexacopter_V2/SCAS/Discrete Varying Lowpass1'
//  '<S362>' : 'FLIGHT_Hexacopter_V2/SCAS/Discrete Varying Lowpass2'
//  '<S363>' : 'FLIGHT_Hexacopter_V2/SCAS/Discrete Varying Lowpass3'
//  '<S364>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3'
//  '<S365>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4'
//  '<S366>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate'
//  '<S367>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1'
//  '<S368>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2'
//  '<S369>' : 'FLIGHT_Hexacopter_V2/SCAS/Discrete Varying Lowpass1/SOS1'
//  '<S370>' : 'FLIGHT_Hexacopter_V2/SCAS/Discrete Varying Lowpass1/SOS1/Arithmetic'
//  '<S371>' : 'FLIGHT_Hexacopter_V2/SCAS/Discrete Varying Lowpass2/SOS1'
//  '<S372>' : 'FLIGHT_Hexacopter_V2/SCAS/Discrete Varying Lowpass2/SOS1/Arithmetic'
//  '<S373>' : 'FLIGHT_Hexacopter_V2/SCAS/Discrete Varying Lowpass3/SOS1'
//  '<S374>' : 'FLIGHT_Hexacopter_V2/SCAS/Discrete Varying Lowpass3/SOS1/Arithmetic'
//  '<S375>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Anti-windup'
//  '<S376>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/D Gain'
//  '<S377>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/External Derivative'
//  '<S378>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Filter'
//  '<S379>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Filter ICs'
//  '<S380>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/I Gain'
//  '<S381>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Ideal P Gain'
//  '<S382>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Ideal P Gain Fdbk'
//  '<S383>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Integrator'
//  '<S384>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Integrator ICs'
//  '<S385>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/N Copy'
//  '<S386>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/N Gain'
//  '<S387>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/P Copy'
//  '<S388>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Parallel P Gain'
//  '<S389>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Reset Signal'
//  '<S390>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Saturation'
//  '<S391>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Saturation Fdbk'
//  '<S392>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Sum'
//  '<S393>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Sum Fdbk'
//  '<S394>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tracking Mode'
//  '<S395>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tracking Mode Sum'
//  '<S396>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tsamp - Integral'
//  '<S397>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tsamp - Ngain'
//  '<S398>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/postSat Signal'
//  '<S399>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/preInt Signal'
//  '<S400>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/preSat Signal'
//  '<S401>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Anti-windup/Disabled'
//  '<S402>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/D Gain/Disabled'
//  '<S403>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/External Derivative/Disabled'
//  '<S404>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Filter/Disabled'
//  '<S405>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Filter ICs/Disabled'
//  '<S406>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/I Gain/Disabled'
//  '<S407>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Ideal P Gain/Passthrough'
//  '<S408>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S409>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Integrator/Disabled'
//  '<S410>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Integrator ICs/Disabled'
//  '<S411>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S412>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/N Gain/Disabled'
//  '<S413>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/P Copy/Disabled'
//  '<S414>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Parallel P Gain/External Parameters'
//  '<S415>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Reset Signal/Disabled'
//  '<S416>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Saturation/External'
//  '<S417>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Saturation/External/Saturation Dynamic'
//  '<S418>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Saturation Fdbk/Disabled'
//  '<S419>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Sum/Passthrough_P'
//  '<S420>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Sum Fdbk/Disabled'
//  '<S421>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tracking Mode/Disabled'
//  '<S422>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S423>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S424>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S425>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/postSat Signal/Forward_Path'
//  '<S426>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/preInt Signal/Internal PreInt'
//  '<S427>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller3/preSat Signal/Forward_Path'
//  '<S428>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Anti-windup'
//  '<S429>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/D Gain'
//  '<S430>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/External Derivative'
//  '<S431>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Filter'
//  '<S432>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Filter ICs'
//  '<S433>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/I Gain'
//  '<S434>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Ideal P Gain'
//  '<S435>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Ideal P Gain Fdbk'
//  '<S436>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Integrator'
//  '<S437>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Integrator ICs'
//  '<S438>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/N Copy'
//  '<S439>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/N Gain'
//  '<S440>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/P Copy'
//  '<S441>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Parallel P Gain'
//  '<S442>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Reset Signal'
//  '<S443>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Saturation'
//  '<S444>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Saturation Fdbk'
//  '<S445>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Sum'
//  '<S446>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Sum Fdbk'
//  '<S447>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tracking Mode'
//  '<S448>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tracking Mode Sum'
//  '<S449>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tsamp - Integral'
//  '<S450>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tsamp - Ngain'
//  '<S451>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/postSat Signal'
//  '<S452>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/preInt Signal'
//  '<S453>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/preSat Signal'
//  '<S454>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Anti-windup/Disabled'
//  '<S455>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/D Gain/Disabled'
//  '<S456>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/External Derivative/Disabled'
//  '<S457>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Filter/Disabled'
//  '<S458>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Filter ICs/Disabled'
//  '<S459>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/I Gain/Disabled'
//  '<S460>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Ideal P Gain/Passthrough'
//  '<S461>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S462>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Integrator/Disabled'
//  '<S463>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Integrator ICs/Disabled'
//  '<S464>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S465>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/N Gain/Disabled'
//  '<S466>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/P Copy/Disabled'
//  '<S467>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Parallel P Gain/External Parameters'
//  '<S468>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Reset Signal/Disabled'
//  '<S469>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Saturation/External'
//  '<S470>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Saturation/External/Saturation Dynamic'
//  '<S471>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Saturation Fdbk/Disabled'
//  '<S472>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Sum/Passthrough_P'
//  '<S473>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Sum Fdbk/Disabled'
//  '<S474>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tracking Mode/Disabled'
//  '<S475>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S476>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S477>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S478>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/postSat Signal/Forward_Path'
//  '<S479>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/preInt Signal/Internal PreInt'
//  '<S480>' : 'FLIGHT_Hexacopter_V2/SCAS/PID Controller4/preSat Signal/Forward_Path'
//  '<S481>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Anti-windup'
//  '<S482>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/D Gain'
//  '<S483>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/External Derivative'
//  '<S484>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Filter'
//  '<S485>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Filter ICs'
//  '<S486>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/I Gain'
//  '<S487>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Ideal P Gain'
//  '<S488>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Ideal P Gain Fdbk'
//  '<S489>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Integrator'
//  '<S490>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Integrator ICs'
//  '<S491>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/N Copy'
//  '<S492>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/N Gain'
//  '<S493>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/P Copy'
//  '<S494>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Parallel P Gain'
//  '<S495>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Reset Signal'
//  '<S496>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Saturation'
//  '<S497>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Saturation Fdbk'
//  '<S498>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Sum'
//  '<S499>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Sum Fdbk'
//  '<S500>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Tracking Mode'
//  '<S501>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Tracking Mode Sum'
//  '<S502>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Tsamp - Integral'
//  '<S503>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Tsamp - Ngain'
//  '<S504>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/postSat Signal'
//  '<S505>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/preInt Signal'
//  '<S506>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/preSat Signal'
//  '<S507>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Anti-windup/Disc. Clamping Parallel'
//  '<S508>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S509>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S510>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/D Gain/Disabled'
//  '<S511>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/External Derivative/Disabled'
//  '<S512>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Filter/Disabled'
//  '<S513>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Filter ICs/Disabled'
//  '<S514>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/I Gain/External Parameters'
//  '<S515>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Ideal P Gain/Passthrough'
//  '<S516>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Ideal P Gain Fdbk/Disabled'
//  '<S517>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Integrator/Discrete'
//  '<S518>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Integrator ICs/Internal IC'
//  '<S519>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/N Copy/Disabled wSignal Specification'
//  '<S520>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/N Gain/Disabled'
//  '<S521>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/P Copy/Disabled'
//  '<S522>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Parallel P Gain/External Parameters'
//  '<S523>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Reset Signal/External Reset'
//  '<S524>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Saturation/Enabled'
//  '<S525>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Saturation Fdbk/Disabled'
//  '<S526>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Sum/Sum_PI'
//  '<S527>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Sum Fdbk/Disabled'
//  '<S528>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Tracking Mode/Disabled'
//  '<S529>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Tracking Mode Sum/Passthrough'
//  '<S530>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Tsamp - Integral/TsSignalSpecification'
//  '<S531>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/Tsamp - Ngain/Passthrough'
//  '<S532>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/postSat Signal/Forward_Path'
//  '<S533>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/preInt Signal/Internal PreInt'
//  '<S534>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate/preSat Signal/Forward_Path'
//  '<S535>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Anti-windup'
//  '<S536>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/D Gain'
//  '<S537>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/External Derivative'
//  '<S538>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Filter'
//  '<S539>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Filter ICs'
//  '<S540>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/I Gain'
//  '<S541>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Ideal P Gain'
//  '<S542>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Ideal P Gain Fdbk'
//  '<S543>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Integrator'
//  '<S544>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Integrator ICs'
//  '<S545>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/N Copy'
//  '<S546>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/N Gain'
//  '<S547>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/P Copy'
//  '<S548>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Parallel P Gain'
//  '<S549>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Reset Signal'
//  '<S550>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Saturation'
//  '<S551>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Saturation Fdbk'
//  '<S552>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Sum'
//  '<S553>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Sum Fdbk'
//  '<S554>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Tracking Mode'
//  '<S555>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Tracking Mode Sum'
//  '<S556>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Tsamp - Integral'
//  '<S557>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Tsamp - Ngain'
//  '<S558>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/postSat Signal'
//  '<S559>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/preInt Signal'
//  '<S560>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/preSat Signal'
//  '<S561>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Anti-windup/Disc. Clamping Parallel'
//  '<S562>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S563>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S564>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/D Gain/Disabled'
//  '<S565>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/External Derivative/Disabled'
//  '<S566>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Filter/Disabled'
//  '<S567>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Filter ICs/Disabled'
//  '<S568>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/I Gain/External Parameters'
//  '<S569>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Ideal P Gain/Passthrough'
//  '<S570>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Ideal P Gain Fdbk/Disabled'
//  '<S571>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Integrator/Discrete'
//  '<S572>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Integrator ICs/Internal IC'
//  '<S573>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/N Copy/Disabled wSignal Specification'
//  '<S574>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/N Gain/Disabled'
//  '<S575>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/P Copy/Disabled'
//  '<S576>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Parallel P Gain/External Parameters'
//  '<S577>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Reset Signal/External Reset'
//  '<S578>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Saturation/Enabled'
//  '<S579>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Saturation Fdbk/Disabled'
//  '<S580>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Sum/Sum_PI'
//  '<S581>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Sum Fdbk/Disabled'
//  '<S582>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Tracking Mode/Disabled'
//  '<S583>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Tracking Mode Sum/Passthrough'
//  '<S584>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Tsamp - Integral/TsSignalSpecification'
//  '<S585>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/Tsamp - Ngain/Passthrough'
//  '<S586>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/postSat Signal/Forward_Path'
//  '<S587>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/preInt Signal/Internal PreInt'
//  '<S588>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate1/preSat Signal/Forward_Path'
//  '<S589>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Anti-windup'
//  '<S590>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/D Gain'
//  '<S591>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/External Derivative'
//  '<S592>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Filter'
//  '<S593>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Filter ICs'
//  '<S594>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/I Gain'
//  '<S595>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Ideal P Gain'
//  '<S596>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Ideal P Gain Fdbk'
//  '<S597>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Integrator'
//  '<S598>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Integrator ICs'
//  '<S599>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/N Copy'
//  '<S600>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/N Gain'
//  '<S601>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/P Copy'
//  '<S602>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Parallel P Gain'
//  '<S603>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Reset Signal'
//  '<S604>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Saturation'
//  '<S605>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Saturation Fdbk'
//  '<S606>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Sum'
//  '<S607>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Sum Fdbk'
//  '<S608>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Tracking Mode'
//  '<S609>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Tracking Mode Sum'
//  '<S610>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Tsamp - Integral'
//  '<S611>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Tsamp - Ngain'
//  '<S612>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/postSat Signal'
//  '<S613>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/preInt Signal'
//  '<S614>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/preSat Signal'
//  '<S615>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Anti-windup/Disc. Clamping Parallel'
//  '<S616>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S617>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S618>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/D Gain/Disabled'
//  '<S619>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/External Derivative/Disabled'
//  '<S620>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Filter/Disabled'
//  '<S621>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Filter ICs/Disabled'
//  '<S622>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/I Gain/External Parameters'
//  '<S623>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Ideal P Gain/Passthrough'
//  '<S624>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Ideal P Gain Fdbk/Disabled'
//  '<S625>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Integrator/Discrete'
//  '<S626>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Integrator ICs/Internal IC'
//  '<S627>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/N Copy/Disabled wSignal Specification'
//  '<S628>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/N Gain/Disabled'
//  '<S629>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/P Copy/Disabled'
//  '<S630>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Parallel P Gain/External Parameters'
//  '<S631>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Reset Signal/External Reset'
//  '<S632>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Saturation/Enabled'
//  '<S633>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Saturation Fdbk/Disabled'
//  '<S634>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Sum/Sum_PI'
//  '<S635>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Sum Fdbk/Disabled'
//  '<S636>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Tracking Mode/Disabled'
//  '<S637>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Tracking Mode Sum/Passthrough'
//  '<S638>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Tsamp - Integral/TsSignalSpecification'
//  '<S639>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/Tsamp - Ngain/Passthrough'
//  '<S640>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/postSat Signal/Forward_Path'
//  '<S641>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/preInt Signal/Internal PreInt'
//  '<S642>' : 'FLIGHT_Hexacopter_V2/SCAS/pid_ctrl_rollrate2/preSat Signal/Forward_Path'

#endif                                 // FLIGHT_Hexacopter_V2_h_

//
// File trailer for generated code.
//
// [EOF]
//
