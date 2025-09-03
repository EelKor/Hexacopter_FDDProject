//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_Hexacopter_V2.h
//
// Code generated for Simulink model 'FLIGHT_Hexacopter_V2'.
//
// Model version                  : 3.72
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Sep  3 23:21:41 2025
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

// Block signals for system 'PX4 Timestamp' (':1287')
struct B_PX4Timestamp_FLIGHT_Hexacop_T {
  uint64_T PX4Timestamp;               // 'PX4 Timestamp' (':1287')
};

// Block states (default storage) for system 'PX4 Timestamp' (':1287')
struct DW_PX4Timestamp_FLIGHT_Hexaco_T {
  px4_internal_block_getPX4Abso_T obj; // 'PX4 Timestamp' (':1287')
  boolean_T objisempty;                // 'PX4 Timestamp' (':1287')
};

// Block signals for system 'PX4 Timestamp' (':1210:105')
struct B_PX4Timestamp_FLIGHT_Hexac_a_T {
  uint64_T PX4Timestamp;               // 'PX4 Timestamp' (':1210:105')
};

// Block states (default storage) for system 'PX4 Timestamp' (':1210:105')
struct DW_PX4Timestamp_FLIGHT_Hexa_o_T {
  px4_internal_block_getPX4Abso_T obj; // 'PX4 Timestamp' (':1210:105')
  boolean_T objisempty;                // 'PX4 Timestamp' (':1210:105')
};

// Block signals for system 'PX4 Timestamp' (':1230:105')
struct B_PX4Timestamp_FLIGHT_Hexac_l_T {
  uint64_T PX4Timestamp;               // 'PX4 Timestamp' (':1230:105')
};

// Block states (default storage) for system 'PX4 Timestamp' (':1230:105')
struct DW_PX4Timestamp_FLIGHT_Hexa_j_T {
  px4_internal_block_getPX4Abso_T obj; // 'PX4 Timestamp' (':1230:105')
  boolean_T objisempty;                // 'PX4 Timestamp' (':1230:105')
};

// Block signals for system 'SourceBlock' (':318:9')
struct B_SourceBlock_FLIGHT_Hexacopt_T {
  px4_Bus_actuator_armed SourceBlock_o2;// 'SourceBlock' (':318:9')
  boolean_T SourceBlock_o1;            // 'SourceBlock' (':318:9')
};

// Block states (default storage) for system 'SourceBlock' (':318:9')
struct DW_SourceBlock_FLIGHT_Hexacop_T {
  px4_internal_block_Subscriber_T obj; // 'SourceBlock' (':318:9')
  boolean_T objisempty;                // 'SourceBlock' (':318:9')
};

// Block signals (default storage)
struct B_FLIGHT_Hexacopter_V2_T {
  px4_Bus_vehicle_local_position In1;  // 'In1' (':320:0')
  px4_Bus_vehicle_local_position r;
  px4_Bus_vehicle_odometry In1_b;      // 'In1' (':326:6:0')
  px4_Bus_vehicle_attitude_smc_setpoint BusAssignment;// 'Bus Assignment' (':1699') 
  px4_Bus_vehicle_odometry r1;
  real_T dv[10];
  px4_Bus_input_rc In1_p;              // 'In1' (':281:0')
  px4_Bus_actuator_motors BusAssignment_e;// 'Bus Assignment' (':1288:101')
  px4_Bus_input_rc r2;
  px4_Bus_vehicle_status In1_m;        // 'In1' (':319:0')
  px4_Bus_vehicle_status r3;
  real_T CreateDiagonalMatrix[9];      // 'Create Diagonal Matrix' (':1482')
  px4_Bus_vehicle_local_position_setpoint BusAssignment_g;// 'Bus Assignment' (':1256:101') 
  px4_Bus_vehicle_attitude_setpoint BusAssignment_f;// 'Bus Assignment' (':1230:101') 
  real32_T Gain_g[12];                 // 'Gain' (':1283')
  px4_Bus_vehicle_rates_setpoint BusAssignment_e0;// 'Bus Assignment' (':1251:101') 
  px4_Bus_vehicle_angular_velocity In1_k;// 'In1' (':299:0')
  px4_Bus_vehicle_angular_velocity r4;
  px4_Bus_actuator_controls_status BusAssignment_j;// 'Bus Assignment' (':1210:101') 
  uint16_T pwmValue[8];
  real32_T fv[4];
  px4_Bus_actuator_armed In1_d;        // 'In1' (':1186:0')
  px4_Bus_actuator_armed In1_e;        // 'In1' (':318:0')
  real32_T ypr[3];                     // 'quat2eul' (':327')
  real32_T U[3];
  real32_T G1[3];                      // 'MATLAB Function1' (':1575')
  real32_T G1_inv[3];                  // 'MATLAB Function2' (':1576')
  real32_T b_A[3];
  uint16_T DataTypeConversion_g[6];    // 'Data Type Conversion' (':160:2982')
  uint16_T DataTypeConversion6[6];     // 'Data Type Conversion6' (':1089')
  real_T reletive_time_sec;
  real_T peak_angle_rad;
  real_T out_yawrate;                  // 'MATLAB Function1' (':641')
  real_T rtb_Current_WP_idx_0;
  real_T rtb_Current_WP_idx_1;
  real_T WP;
  real_T WP_m;
  real_T u0;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  uint64_T rtb_PX4Timestamp_c;
  real32_T RateTransition4;            // 'Rate Transition4' (':1068')
  real32_T RateTransition5;            // 'Rate Transition5' (':1981')
  real32_T RateTransition2;            // 'Rate Transition2' (':1974')
  real32_T RateTransition18;           // 'Rate Transition18' (':2012')
  real32_T RateTransition3;            // 'Rate Transition3' (':1980')
  real32_T RateTransition2_a[3];       // 'Rate Transition2' (':884')
  real32_T RateTransition4_l;          // 'Rate Transition4' (':1912')
  real32_T RateTransition5_n;          // 'Rate Transition5' (':1913')
  real32_T RateTransition6;            // 'Rate Transition6' (':1914')
  real32_T RateTransition9;            // 'Rate Transition9' (':1917')
  real32_T RateTransition10;           // 'Rate Transition10' (':1918')
  real32_T RateTransition11;           // 'Rate Transition11' (':1919')
  real32_T RateTransition17;           // 'Rate Transition17' (':1927')
  real32_T RateTransition1;            // 'Rate Transition1' (':1911')
  real32_T RateTransition7;            // 'Rate Transition7' (':1915')
  real32_T RateTransition8;            // 'Rate Transition8' (':1916')
  real32_T RateTransition12;           // 'Rate Transition12' (':1920')
  real32_T RateTransition13;           // 'Rate Transition13' (':1921')
  real32_T RateTransition14;           // 'Rate Transition14' (':1922')
  real32_T RateTransition8_i;          // 'Rate Transition8' (':1988')
  real32_T RateTransition19;           // 'Rate Transition19' (':2013')
  real32_T RateTransition10_j;         // 'Rate Transition10' (':1995')
  real32_T RateTransition7_h;          // 'Rate Transition7' (':1987')
  real32_T RateTransition;             // 'Rate Transition' (':732')
  real32_T RateTransition1_a;          // 'Rate Transition1' (':733')
  real32_T RateTransition13_a;         // 'Rate Transition13' (':2004')
  real32_T RateTransition20;           // 'Rate Transition20' (':2014')
  real32_T RateTransition11_a;         // 'Rate Transition11' (':2002')
  real32_T RateTransition12_j;         // 'Rate Transition12' (':2003')
  real32_T RateTransition14_c;         // 'Rate Transition14' (':2005')
  real32_T RateTransition9_p;          // 'Rate Transition9' (':1989')
  real32_T RateTransition6_o;          // 'Rate Transition6' (':1982')
  real32_T ParamStep;
  real32_T ParamStep_k;
  real32_T ParamStep_c;
  real32_T Gain7;                      // 'Gain7' (':1862')
  real32_T Gain6;                      // 'Gain6' (':387')
  real32_T roll;                       // 'Sum1' (':1821:8')
  real32_T w_radps;                    // 'MATLAB Function' (':192')
  real32_T p_j;                        // 'Gain' (':1821:2:220:358')
  real32_T q_c;                        // 'Product2' (':1821:2:220:361')
  real32_T r_o;                        // 'Bias' (':1821:2:220:373')
  real32_T d_n;                        // 'Add1' (':1821:2:220:364')
  real32_T Sum2_g;                     // 'Sum2' (':686')
  real32_T TSamp_ku;                   // 'TSamp' (':1821:1:4')
  real32_T des_throttle;               // 'MATLAB Function2' (':1854')
  real32_T ReadParameter12_o1;         // 'Read Parameter12' (':197')
  real32_T ReadParameter13_o1;         // 'Read Parameter13' (':198')
  real32_T ReadParameter14_o1;         // 'Read Parameter14' (':199')
  real32_T ReadParameter15_o1;         // 'Read Parameter15' (':200')
  real32_T ReadParameter16_o1;         // 'Read Parameter16' (':201')
  real32_T ReadParameter17_o1;         // 'Read Parameter17' (':202')
  real32_T ReadParameter18_o1;         // 'Read Parameter18' (':203')
  real32_T ReadParameter19_o1;         // 'Read Parameter19' (':204')
  real32_T ReadParameter29_o1;         // 'Read Parameter29' (':1032')
  real32_T ReadParameter30_o1;         // 'Read Parameter30' (':1033')
  real32_T ReadParameter31_o1;         // 'Read Parameter31' (':1034')
  real32_T ReadParameter32_o1;         // 'Read Parameter32' (':1035')
  real32_T ReadParameter33_o1;         // 'Read Parameter33' (':1036')
  real32_T ReadParameter34_o1;         // 'Read Parameter34' (':1725')
  real32_T ReadParameter35_o1;         // 'Read Parameter35' (':1726')
  real32_T ReadParameter36_o1;         // 'Read Parameter36' (':1727')
  real32_T ReadParameter37_o1;         // 'Read Parameter37' (':1752')
  real32_T ReadParameter41_o1;         // 'Read Parameter41' (':1904')
  real32_T ReadParameter42_o1;         // 'Read Parameter42' (':1905')
  real32_T ReadParameter8_o1;          // 'Read Parameter8' (':217')
  real32_T V;
  real32_T absx;
  real32_T IProdOut_b;                 // 'IProd Out' (':1978:787')
  real32_T DeadZone;                   // 'DeadZone' (':1978:660')
  real32_T Sum5_f;                     // 'Sum5' (':1977')
  real32_T p;                          // 'Gain' (':1967:220:358')
  real32_T q;                          // 'Product2' (':1967:220:361')
  real32_T r_b;                        // 'Bias' (':1967:220:373')
  real32_T d_p;                        // 'Add1' (':1967:220:364')
  real32_T Product2_gt;                // 'Product2' (':1756:219:339')
  real32_T TSamp;                      // 'TSamp' (':1966:4')
  real32_T Product_p;                  // 'Product' (':1514')
  real32_T Product2_m;                 // 'Product2' (':1516')
  real32_T Product4;                   // 'Product4' (':1518')
  real32_T Sum_o;                      // 'Sum' (':1756:219:332')
  real32_T Product1_m;                 // 'Product1' (':1756:219:334')
  real32_T TSamp_oi;                   // 'TSamp' (':1522:4')
  real32_T Diff_k;                     // 'Diff' (':1522:3')
  real32_T TSamp_d;                    // 'TSamp' (':1523:4')
  real32_T Subtract;                   // 'Subtract' (':1583')
  real32_T H;                          // 'MATLAB Function' (':1574')
  real32_T FilterCoefficient;          // 'Filter Coefficient' (':1817:882')
  real32_T Sum_n;                      // 'Sum' (':1817:3522')
  real32_T s;                          // 'MATLAB Function3' (':1577')
  real32_T R;                          // 'MATLAB Function4' (':1578')
  real32_T Saturation2;                // 'Saturation2' (':1581')
  real32_T IProdOut_p;                 // 'IProd Out' (':1991:787')
  real32_T DeadZone_d;                 // 'DeadZone' (':1991:660')
  real32_T Sum4;                       // 'Sum4' (':1990')
  real32_T Product2_l;                 // 'Product2' (':1984:220:344')
  real32_T p_l;                        // 'Gain' (':1984:220:358')
  real32_T q_o;                        // 'Product2' (':1984:220:361')
  real32_T r_d;                        // 'Bias' (':1984:220:373')
  real32_T d_g;                        // 'Add1' (':1984:220:364')
  real32_T IProdOut_g;                 // 'IProd Out' (':2008:787')
  real32_T DeadZone_db;                // 'DeadZone' (':2008:660')
  real32_T Product2_d;                 // 'Product2' (':1999:220:344')
  real32_T p_g;                        // 'Gain' (':1999:220:358')
  real32_T q_i;                        // 'Product2' (':1999:220:361')
  real32_T r_m;                        // 'Bias' (':1999:220:373')
  real32_T d_c;                        // 'Add1' (':1999:220:364')
  real32_T Sum2_au;                    // 'Sum2' (':1967:220:341')
  real32_T TSamp_p;                    // 'TSamp' (':1998:4')
  real32_T rtb_Gain_g_c;
  real32_T rtb_TSamp_o_f;
  real32_T rtb_omega_phi_idx_1;
  real32_T rtb_omega_phi_idx_2;
  real32_T rtb_TSamp_o_idx_1;
  real32_T anrm;
  real32_T absxk;
  int32_T ParamStep_g;
  int32_T ParamStep_g1;
  int32_T ParamStep_m;
  int32_T ParamStep_n;
  int32_T ParamStep_p;
  int32_T ParamStep_l;
  int32_T i;
  uint16_T rc_ctrl_switch;             // 'Rate Transition' (':1176')
  uint16_T rc_inject_failure;          // 'Rate Transition' (':1176')
  boolean_T RateTransition15;          // 'Rate Transition15' (':2009')
  boolean_T RateTransition16;          // 'Rate Transition16' (':1925')
  boolean_T RateTransition15_l;        // 'Rate Transition15' (':1924')
  boolean_T RateTransition16_e;        // 'Rate Transition16' (':2010')
  boolean_T RateTransition17_h;        // 'Rate Transition17' (':2011')
  boolean_T VehicleStatus_flag_armed;  // 'Rate Transition2' (':1298')
  boolean_T VehicleStatus_flag_kill;   // 'Rate Transition2' (':1298')
  B_SourceBlock_FLIGHT_Hexacopt_T SourceBlock_p;// 'SourceBlock' (':318:9')
  B_SourceBlock_FLIGHT_Hexacopt_T SourceBlock_l;// 'SourceBlock' (':318:9')
  B_PX4Timestamp_FLIGHT_Hexac_l_T PX4Timestamp_k;// 'PX4 Timestamp' (':1230:105') 
  B_PX4Timestamp_FLIGHT_Hexac_a_T PX4Timestamp_e;// 'PX4 Timestamp' (':1210:105') 
  B_PX4Timestamp_FLIGHT_Hexacop_T PX4Timestamp_pn;// 'PX4 Timestamp' (':1287')
  B_PX4Timestamp_FLIGHT_Hexac_l_T PX4Timestamp_p;// 'PX4 Timestamp' (':1230:105') 
  B_PX4Timestamp_FLIGHT_Hexac_l_T PX4Timestamp_j;// 'PX4 Timestamp' (':1230:105') 
  B_PX4Timestamp_FLIGHT_Hexac_a_T PX4Timestamp_c;// 'PX4 Timestamp' (':1210:105') 
  B_PX4Timestamp_FLIGHT_Hexacop_T PX4Timestamp;// 'PX4 Timestamp' (':1287')
};

// Block states (default storage) for system 'FLIGHT_Hexacopter_V2'
struct DW_FLIGHT_Hexacopter_V2_T {
  px4_internal_block_getPX4Abso_T obj; // 'PX4 Timestamp' (':642')
  px4_internal_block_Subscriber_T obj_i;// 'SourceBlock' (':326:6:9')
  px4_internal_block_Subscriber_T obj_l;// 'SourceBlock' (':320:9')
  px4_internal_block_Subscriber_T obj_a;// 'SourceBlock' (':319:9')
  px4_internal_block_Subscriber_T obj_m;// 'SourceBlock' (':299:9')
  px4_internal_block_Subscriber_T obj_n;// 'SourceBlock' (':281:9')
  px4_internal_block_PWM_FLIGHT_T obj_md;// 'PX4 PWM Output' (':1181')
  px4_internal_block_ParameterU_T obj_c;// 'read_mc_rollrate_p' (':246')
  px4_internal_block_ParameterU_T obj_ai;// 'Read Parameter9' (':218')
  px4_internal_block_ParameterU_T obj_f;// 'Read Parameter8' (':217')
  px4_internal_block_ParameterU_T obj_fj;// 'Read Parameter7' (':216')
  px4_internal_block_ParameterU_T obj_p;// 'Read Parameter6' (':215')
  px4_internal_block_ParameterU_T obj_ia;// 'Read Parameter5' (':214')
  px4_internal_block_ParameterU_T obj_pc;// 'Read Parameter46' (':2024')
  px4_internal_block_ParameterU_T obj_k;// 'Read Parameter45' (':2023')
  px4_internal_block_ParameterU_T obj_o;// 'Read Parameter44' (':1932')
  px4_internal_block_ParameterU_T obj_ox;// 'Read Parameter43' (':1930')
  px4_internal_block_ParameterU_T obj_fy;// 'Read Parameter42' (':1905')
  px4_internal_block_ParameterU_T obj_h;// 'Read Parameter41' (':1904')
  px4_internal_block_ParameterU_T obj_pn;// 'Read Parameter40' (':1867')
  px4_internal_block_ParameterU_T obj_c1;// 'Read Parameter4' (':213')
  px4_internal_block_ParameterU_T obj_g;// 'Read Parameter39' (':1856')
  px4_internal_block_ParameterU_T obj_e;// 'Read Parameter38' (':1760')
  px4_internal_block_ParameterU_T obj_pi;// 'Read Parameter37' (':1752')
  px4_internal_block_ParameterU_T obj_ln;// 'Read Parameter36' (':1727')
  px4_internal_block_ParameterU_T obj_b;// 'Read Parameter35' (':1726')
  px4_internal_block_ParameterU_T obj_oq;// 'Read Parameter34' (':1725')
  px4_internal_block_ParameterU_T obj_bd;// 'Read Parameter33' (':1036')
  px4_internal_block_ParameterU_T obj_lv;// 'Read Parameter32' (':1035')
  px4_internal_block_ParameterU_T obj_as;// 'Read Parameter31' (':1034')
  px4_internal_block_ParameterU_T obj_mo;// 'Read Parameter30' (':1033')
  px4_internal_block_ParameterU_T obj_c4;// 'Read Parameter3' (':212')
  px4_internal_block_ParameterU_T obj_br;// 'Read Parameter29' (':1032')
  px4_internal_block_ParameterU_T obj_ic;// 'Read Parameter28' (':528')
  px4_internal_block_ParameterU_T obj_l3;// 'Read Parameter27' (':479')
  px4_internal_block_ParameterU_T obj_lt;// 'Read Parameter26' (':423')
  px4_internal_block_ParameterU_T obj_a1;// 'Read Parameter2' (':205')
  px4_internal_block_ParameterU_T obj_mc;// 'Read Parameter19' (':204')
  px4_internal_block_ParameterU_T obj_ml;// 'Read Parameter18' (':203')
  px4_internal_block_ParameterU_T obj_d;// 'Read Parameter17' (':202')
  px4_internal_block_ParameterU_T obj_j;// 'Read Parameter16' (':201')
  px4_internal_block_ParameterU_T obj_nn;// 'Read Parameter15' (':200')
  px4_internal_block_ParameterU_T obj_fd;// 'Read Parameter14' (':199')
  px4_internal_block_ParameterU_T obj_pf;// 'Read Parameter13' (':198')
  px4_internal_block_ParameterU_T obj_jo;// 'Read Parameter12' (':197')
  px4_internal_block_ParameterU_T obj_jk;// 'Read Parameter11' (':196')
  px4_internal_block_ParameterU_T obj_bq;// 'Read Parameter10' (':195')
  px4_internal_block_ParameterU_T obj_l4;// 'Read Parameter1' (':194')
  px4_internal_block_ParameterU_T obj_jf;// 'Read Parameter' (':193')
  px4_internal_block_ParameterU_T obj_ic5;// 'Read Parameter5' (':1129')
  px4_internal_block_ParameterU_T obj_jg;// 'Read Parameter4' (':1128')
  px4_internal_block_ParameterU_T obj_hi;// 'Read Parameter3' (':1127')
  px4_internal_block_ParameterU_T obj_ps;// 'Read Parameter2' (':1126')
  px4_internal_block_ParameterU_T obj_oe;// 'Read Parameter13' (':1125')
  px4_internal_block_ParameterU_T obj_aw;// 'Read Parameter1' (':1124')
  px4_internal_block_Publisher__T obj_pm;// 'SinkBlock' (':1256:104:15')
  px4_internal_block_Publisher__T obj_nf;// 'SinkBlock' (':1288:104:15')
  px4_internal_block_Publisher__T obj_kg;// 'SinkBlock' (':1700:15')
  px4_internal_block_Publisher__T obj_mp;// 'SinkBlock' (':1251:104:15')
  px4_internal_block_Publisher__T obj_m1;// 'SinkBlock' (':1230:104:15')
  px4_internal_block_Publisher__T obj_fe;// 'SinkBlock' (':1210:104:15')
  real_T X0[2];                        // 'MATLAB Function5' (':2069')
  real_T WP_num;                       // 'MATLAB Function5' (':2069')
  real_T WP[10];                       // 'MATLAB Function5' (':2069')
  real_T start_time_usec;              // 'MATLAB Function1' (':641')
  real32_T Integrator_DSTATE;          // 'Integrator' (':1978:843')
  real32_T UnitDelay1_DSTATE;          // 'Unit Delay1' (':1967:220:338')
  real32_T UD_DSTATE;                  // 'UD' (':1966:5')
  real32_T UD_DSTATE_h[3];             // 'UD' (':1524:5')
  real32_T UnitDelay_DSTATE;           // 'Unit Delay' (':1756:219:331')
  real32_T UD_DSTATE_o;                // 'UD' (':1522:5')
  real32_T UD_DSTATE_e;                // 'UD' (':1523:5')
  real32_T Filter_DSTATE;              // 'Filter' (':1817:737')
  real32_T Integrator_DSTATE_h;        // 'Integrator' (':1820:843')
  real32_T DiscreteTimeIntegrator_DSTATE;// 'Discrete-Time Integrator' (':1887') 
  real32_T Integrator_DSTATE_l;        // 'Integrator' (':1991:843')
  real32_T UnitDelay1_DSTATE_a;        // 'Unit Delay1' (':1984:220:338')
  real32_T UD_DSTATE_b;                // 'UD' (':1983:5')
  real32_T Integrator_DSTATE_o;        // 'Integrator' (':2008:843')
  real32_T UnitDelay1_DSTATE_p;        // 'Unit Delay1' (':1999:220:338')
  real32_T UD_DSTATE_d;                // 'UD' (':1998:5')
  real32_T UnitDelay2_DSTATE;          // 'Unit Delay2' (':1999:220:342')
  real32_T UnitDelay2_DSTATE_c;        // 'Unit Delay2' (':1984:220:342')
  real32_T UnitDelay2_DSTATE_i;        // 'Unit Delay2' (':1967:220:342')
  real32_T Integrator_DSTATE_lu;       // 'Integrator' (':1821:10:843')
  real32_T UnitDelay1_DSTATE_i;        // 'Unit Delay1' (':1821:2:220:338')
  real32_T UD_DSTATE_a;                // 'UD' (':1821:1:5')
  real32_T DiscreteTimeIntegrator_DSTATE_c;// 'Discrete-Time Integrator' (':436') 
  real32_T DiscreteTimeIntegrator1_DSTATE;// 'Discrete-Time Integrator1' (':437') 
  real32_T Integrator_DSTATE_k[2];     // 'Integrator' (':514:843')
  real32_T Filter_DSTATE_i[2];         // 'Filter' (':514:737')
  real32_T UnitDelay2_DSTATE_f;        // 'Unit Delay2' (':1821:2:220:342')
  real32_T RateTransition4_Buffer0;    // 'Rate Transition4' (':1068')
  real32_T RateTransition5_Buffer0;    // 'Rate Transition5' (':1981')
  real32_T RateTransition2_Buffer0;    // 'Rate Transition2' (':1974')
  real32_T RateTransition18_Buffer0;   // 'Rate Transition18' (':2012')
  real32_T RateTransition3_Buffer0;    // 'Rate Transition3' (':1980')
  real32_T RateTransition2_Buffer0_d[3];// 'Rate Transition2' (':884')
  real32_T RateTransition4_Buffer0_d;  // 'Rate Transition4' (':1912')
  real32_T RateTransition5_Buffer0_h;  // 'Rate Transition5' (':1913')
  real32_T RateTransition6_Buffer0;    // 'Rate Transition6' (':1914')
  real32_T RateTransition9_Buffer0;    // 'Rate Transition9' (':1917')
  real32_T RateTransition10_Buffer0;   // 'Rate Transition10' (':1918')
  real32_T RateTransition11_Buffer0;   // 'Rate Transition11' (':1919')
  real32_T RateTransition17_Buffer0;   // 'Rate Transition17' (':1927')
  real32_T RateTransition1_Buffer0;    // 'Rate Transition1' (':1911')
  real32_T RateTransition7_Buffer0;    // 'Rate Transition7' (':1915')
  real32_T RateTransition8_Buffer0;    // 'Rate Transition8' (':1916')
  real32_T RateTransition12_Buffer0;   // 'Rate Transition12' (':1920')
  real32_T RateTransition13_Buffer0;   // 'Rate Transition13' (':1921')
  real32_T RateTransition14_Buffer0;   // 'Rate Transition14' (':1922')
  real32_T RateTransition8_Buffer0_a;  // 'Rate Transition8' (':1988')
  real32_T RateTransition19_Buffer0;   // 'Rate Transition19' (':2013')
  real32_T RateTransition10_Buffer0_g; // 'Rate Transition10' (':1995')
  real32_T RateTransition7_Buffer0_e;  // 'Rate Transition7' (':1987')
  real32_T RateTransition_Buffer0;     // 'Rate Transition' (':732')
  real32_T RateTransition1_Buffer0_g;  // 'Rate Transition1' (':733')
  real32_T RateTransition13_Buffer0_d; // 'Rate Transition13' (':2004')
  real32_T RateTransition20_Buffer0;   // 'Rate Transition20' (':2014')
  real32_T RateTransition11_Buffer0_b; // 'Rate Transition11' (':2002')
  real32_T RateTransition12_Buffer0_j; // 'Rate Transition12' (':2003')
  real32_T RateTransition14_Buffer0_o; // 'Rate Transition14' (':2005')
  real32_T RateTransition9_Buffer0_h;  // 'Rate Transition9' (':1989')
  real32_T RateTransition6_Buffer0_e;  // 'Rate Transition6' (':1982')
  uint16_T RateTransition_8_Buffer0;   // 'Rate Transition' (':1176')
  uint16_T RateTransition_4_Buffer0;   // 'Rate Transition' (':1176')
  int8_T Integrator_PrevResetState;    // 'Integrator' (':1978:843')
  int8_T Integrator_PrevResetState_h;  // 'Integrator' (':1820:843')
  int8_T DiscreteTimeIntegrator_PrevRese;// 'Discrete-Time Integrator' (':1887') 
  int8_T Integrator_PrevResetState_e;  // 'Integrator' (':1991:843')
  int8_T Integrator_PrevResetState_es; // 'Integrator' (':2008:843')
  int8_T Integrator_PrevResetState_l;  // 'Integrator' (':1821:10:843')
  int8_T DiscreteTimeIntegrator_PrevRe_l;// 'Discrete-Time Integrator' (':436')
  int8_T DiscreteTimeIntegrator1_PrevRes;// 'Discrete-Time Integrator1' (':437') 
  int8_T Integrator_PrevResetState_l3; // 'Integrator' (':514:843')
  int8_T Filter_PrevResetState;        // 'Filter' (':514:737')
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// 'Discrete-Time Integrator' (':436') 
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;// 'Discrete-Time Integrator1' (':437') 
  boolean_T RateTransition15_Buffer0;  // 'Rate Transition15' (':2009')
  boolean_T RateTransition16_Buffer0;  // 'Rate Transition16' (':1925')
  boolean_T RateTransition15_Buffer0_a;// 'Rate Transition15' (':1924')
  boolean_T RateTransition16_Buffer0_g;// 'Rate Transition16' (':2010')
  boolean_T RateTransition17_Buffer0_e;// 'Rate Transition17' (':2011')
  boolean_T RateTransition2_16_Buffer0;// 'Rate Transition2' (':1298')
  boolean_T RateTransition2_17_Buffer0;// 'Rate Transition2' (':1298')
  DW_SourceBlock_FLIGHT_Hexacop_T SourceBlock_p;// 'SourceBlock' (':318:9')
  DW_SourceBlock_FLIGHT_Hexacop_T SourceBlock_l;// 'SourceBlock' (':318:9')
  DW_PX4Timestamp_FLIGHT_Hexa_j_T PX4Timestamp_k;// 'PX4 Timestamp' (':1230:105') 
  DW_PX4Timestamp_FLIGHT_Hexa_o_T PX4Timestamp_e;// 'PX4 Timestamp' (':1210:105') 
  DW_PX4Timestamp_FLIGHT_Hexaco_T PX4Timestamp_pn;// 'PX4 Timestamp' (':1287')
  DW_PX4Timestamp_FLIGHT_Hexa_j_T PX4Timestamp_p;// 'PX4 Timestamp' (':1230:105') 
  DW_PX4Timestamp_FLIGHT_Hexa_j_T PX4Timestamp_j;// 'PX4 Timestamp' (':1230:105') 
  DW_PX4Timestamp_FLIGHT_Hexa_o_T PX4Timestamp_c;// 'PX4 Timestamp' (':1210:105') 
  DW_PX4Timestamp_FLIGHT_Hexaco_T PX4Timestamp;// 'PX4 Timestamp' (':1287')
};

// Parameters (default storage)
struct P_FLIGHT_Hexacopter_V2_T_ {
  real32_T MAX_CONTROL_ANGLE_PITCH;    // Variable: MAX_CONTROL_ANGLE_PITCH
                                          //  Referenced by: 'Gain5' (':386')

  real32_T MAX_CONTROL_ANGLE_RATE_Y;   // Variable: MAX_CONTROL_ANGLE_RATE_Y
                                          //  Referenced by: 'Gain6' (':387')

  real32_T MAX_CONTROL_ANGLE_ROLL;     // Variable: MAX_CONTROL_ANGLE_ROLL
                                          //  Referenced by: 'Gain4' (':385')

  real32_T DiscretePIDController1_D; // Mask Parameter: DiscretePIDController1_D
                                        //  Referenced by: 'Derivative Gain' (':1817:688')

  real32_T DiscretePIDController2_I; // Mask Parameter: DiscretePIDController2_I
                                        //  Referenced by: 'Integral Gain' (':1820:791')

  real32_T DiscreteDerivative2_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative2_ICPrevScale
                                 //  Referenced by: 'UD' (':1966:5')

  real32_T DiscreteDerivative2_ICPrevSca_e;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_e
                                 //  Referenced by: 'UD' (':1524:5')

  real32_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: 'UD' (':1522:5')

  real32_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: 'UD' (':1523:5')

  real32_T DiscreteDerivative1_ICPrevSca_o;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_o
                                 //  Referenced by: 'UD' (':1983:5')

  real32_T DiscreteDerivative3_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative3_ICPrevScale
                                 //  Referenced by: 'UD' (':1998:5')

  real32_T DiscreteDerivative2_ICPrevSca_n;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_n
                                 //  Referenced by: 'UD' (':1821:1:5')

  real32_T DiscretePIDController1_InitialC;
                              // Mask Parameter: DiscretePIDController1_InitialC
                                 //  Referenced by: 'Filter' (':1817:737')

  real32_T PID_Altitude1_InitialConditionF;
                              // Mask Parameter: PID_Altitude1_InitialConditionF
                                 //  Referenced by: 'Filter' (':514:737')

  real32_T pid_ctrl_rollrate_InitialCondit;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCondit
                                 //  Referenced by: 'Integrator' (':1978:843')

  real32_T DiscretePIDController2_InitialC;
                              // Mask Parameter: DiscretePIDController2_InitialC
                                 //  Referenced by: 'Integrator' (':1820:843')

  real32_T pid_ctrl_rollrate1_InitialCondi;
                              // Mask Parameter: pid_ctrl_rollrate1_InitialCondi
                                 //  Referenced by: 'Integrator' (':1991:843')

  real32_T pid_ctrl_rollrate2_InitialCondi;
                              // Mask Parameter: pid_ctrl_rollrate2_InitialCondi
                                 //  Referenced by: 'Integrator' (':2008:843')

  real32_T pid_ctrl_rollrate_InitialCond_p;
                              // Mask Parameter: pid_ctrl_rollrate_InitialCond_p
                                 //  Referenced by: 'Integrator' (':1821:10:843')

  real32_T PID_Altitude1_InitialConditio_f;
                              // Mask Parameter: PID_Altitude1_InitialConditio_f
                                 //  Referenced by: 'Integrator' (':514:843')

  real32_T pid_ctrl_rollrate_LowerIntegrat;
                              // Mask Parameter: pid_ctrl_rollrate_LowerIntegrat
                                 //  Referenced by: 'Integrator' (':1978:843')

  real32_T pid_ctrl_rollrate1_LowerIntegra;
                              // Mask Parameter: pid_ctrl_rollrate1_LowerIntegra
                                 //  Referenced by: 'Integrator' (':1991:843')

  real32_T pid_ctrl_rollrate2_LowerIntegra;
                              // Mask Parameter: pid_ctrl_rollrate2_LowerIntegra
                                 //  Referenced by: 'Integrator' (':2008:843')

  real32_T PID_Altitude1_LowerIntegratorSa;
                              // Mask Parameter: PID_Altitude1_LowerIntegratorSa
                                 //  Referenced by: 'Integrator' (':514:843')

  real32_T pid_ctrl_rollrate_LowerSaturati;
                              // Mask Parameter: pid_ctrl_rollrate_LowerSaturati
                                 //  Referenced by:
                                 //    'Saturation' (':1978:923')
                                 //    'DeadZone' (':1978:660')

  real32_T pid_ctrl_rollrate1_LowerSaturat;
                              // Mask Parameter: pid_ctrl_rollrate1_LowerSaturat
                                 //  Referenced by:
                                 //    'Saturation' (':1991:923')
                                 //    'DeadZone' (':1991:660')

  real32_T pid_ctrl_rollrate2_LowerSaturat;
                              // Mask Parameter: pid_ctrl_rollrate2_LowerSaturat
                                 //  Referenced by:
                                 //    'Saturation' (':2008:923')
                                 //    'DeadZone' (':2008:660')

  real32_T DiscretePIDController_LowerSatu;
                              // Mask Parameter: DiscretePIDController_LowerSatu
                                 //  Referenced by: 'Saturation' (':2050:923')

  real32_T DiscretePIDController1_N; // Mask Parameter: DiscretePIDController1_N
                                        //  Referenced by: 'Filter Coefficient' (':1817:882')

  real32_T DiscretePIDController1_P; // Mask Parameter: DiscretePIDController1_P
                                        //  Referenced by: 'Proportional Gain' (':1817:913')

  real32_T pid_ctrl_rollrate_UpperIntegrat;
                              // Mask Parameter: pid_ctrl_rollrate_UpperIntegrat
                                 //  Referenced by: 'Integrator' (':1978:843')

  real32_T pid_ctrl_rollrate1_UpperIntegra;
                              // Mask Parameter: pid_ctrl_rollrate1_UpperIntegra
                                 //  Referenced by: 'Integrator' (':1991:843')

  real32_T pid_ctrl_rollrate2_UpperIntegra;
                              // Mask Parameter: pid_ctrl_rollrate2_UpperIntegra
                                 //  Referenced by: 'Integrator' (':2008:843')

  real32_T PID_Altitude1_UpperIntegratorSa;
                              // Mask Parameter: PID_Altitude1_UpperIntegratorSa
                                 //  Referenced by: 'Integrator' (':514:843')

  real32_T pid_ctrl_rollrate_UpperSaturati;
                              // Mask Parameter: pid_ctrl_rollrate_UpperSaturati
                                 //  Referenced by:
                                 //    'Saturation' (':1978:923')
                                 //    'DeadZone' (':1978:660')

  real32_T pid_ctrl_rollrate1_UpperSaturat;
                              // Mask Parameter: pid_ctrl_rollrate1_UpperSaturat
                                 //  Referenced by:
                                 //    'Saturation' (':1991:923')
                                 //    'DeadZone' (':1991:660')

  real32_T pid_ctrl_rollrate2_UpperSaturat;
                              // Mask Parameter: pid_ctrl_rollrate2_UpperSaturat
                                 //  Referenced by:
                                 //    'Saturation' (':2008:923')
                                 //    'DeadZone' (':2008:660')

  real32_T DiscretePIDController_UpperSatu;
                              // Mask Parameter: DiscretePIDController_UpperSatu
                                 //  Referenced by: 'Saturation' (':2050:923')

  real32_T CompareToConstant6_const; // Mask Parameter: CompareToConstant6_const
                                        //  Referenced by: 'Constant' (':1881:3')

  real32_T CompareToConstant5_const; // Mask Parameter: CompareToConstant5_const
                                        //  Referenced by: 'Constant' (':1880:3')

  uint16_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: 'Constant' (':1315:3')

  uint16_T CompareToConstant_const_a;
                                    // Mask Parameter: CompareToConstant_const_a
                                       //  Referenced by: 'Constant' (':1076:3')

  uint16_T CompareToConstant1_const; // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: 'Constant' (':429:3')

  uint16_T CompareToConstant2_const; // Mask Parameter: CompareToConstant2_const
                                        //  Referenced by: 'Constant' (':449:3')

  uint16_T CompareToConstant7_const; // Mask Parameter: CompareToConstant7_const
                                        //  Referenced by: 'Constant' (':2137:3')

  uint16_T CompareToConstant4_const; // Mask Parameter: CompareToConstant4_const
                                        //  Referenced by: 'Constant' (':1876:3')

  uint16_T CompareToConstant8_const; // Mask Parameter: CompareToConstant8_const
                                        //  Referenced by: 'Constant' (':2138:3')

  uint16_T CompareToConstant_const_p;
                                    // Mask Parameter: CompareToConstant_const_p
                                       //  Referenced by: 'Constant' (':2118:3')

  uint16_T CompareToConstant3_const; // Mask Parameter: CompareToConstant3_const
                                        //  Referenced by: 'Constant' (':623:3')

  uint16_T CompareToConstant_const_o;
                                    // Mask Parameter: CompareToConstant_const_o
                                       //  Referenced by: 'Constant' (':1720:3')

  uint16_T CompareToConstant1_const_j;
                                   // Mask Parameter: CompareToConstant1_const_j
                                      //  Referenced by: 'Constant' (':1899:3')

  uint16_T CompareToConstant_const_j;
                                    // Mask Parameter: CompareToConstant_const_j
                                       //  Referenced by: 'Constant' (':1710:3')

  px4_Bus_vehicle_local_position Out1_Y0;// Computed Parameter: Out1_Y0
                                            //  Referenced by: 'Out1' (':320:6')

  px4_Bus_vehicle_local_position Constant_Value;// Computed Parameter: Constant_Value
                                                   //  Referenced by: 'Constant' (':320:2')

  px4_Bus_vehicle_attitude_smc_setpoint Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                            //  Referenced by: 'Constant' (':1698:17')

  px4_Bus_vehicle_odometry Out1_Y0_c;  // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: 'Out1' (':326:6:6')

  px4_Bus_vehicle_odometry Constant_Value_j;// Computed Parameter: Constant_Value_j
                                               //  Referenced by: 'Constant' (':326:6:2')

  px4_Bus_actuator_motors Constant_Value_e;// Computed Parameter: Constant_Value_e
                                              //  Referenced by: 'Constant' (':1288:103:17')

  px4_Bus_input_rc Out1_Y0_h;          // Computed Parameter: Out1_Y0_h
                                          //  Referenced by: 'Out1' (':281:6')

  px4_Bus_input_rc Constant_Value_l;   // Computed Parameter: Constant_Value_l
                                          //  Referenced by: 'Constant' (':281:2')

  px4_Bus_vehicle_status Out1_Y0_e;    // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: 'Out1' (':319:6')

  px4_Bus_vehicle_status Constant_Value_k;// Computed Parameter: Constant_Value_k
                                             //  Referenced by: 'Constant' (':319:2')

  px4_Bus_vehicle_local_position_setpoint Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                              //  Referenced by: 'Constant' (':1256:103:17')

  px4_Bus_vehicle_attitude_setpoint Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                        //  Referenced by: 'Constant' (':1230:103:17')

  px4_Bus_vehicle_angular_velocity Out1_Y0_a;// Computed Parameter: Out1_Y0_a
                                                //  Referenced by: 'Out1' (':299:6')

  px4_Bus_vehicle_angular_velocity Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                       //  Referenced by: 'Constant' (':299:2')

  px4_Bus_vehicle_rates_setpoint Constant_Value_ek;// Computed Parameter: Constant_Value_ek
                                                      //  Referenced by: 'Constant' (':1251:103:17')

  px4_Bus_actuator_controls_status Constant_Value_l5;// Computed Parameter: Constant_Value_l5
                                                        //  Referenced by: 'Constant' (':1210:103:17')

  px4_Bus_actuator_armed Out1_Y0_p;    // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: 'Out1' (':318:6')

  px4_Bus_actuator_armed Out1_Y0_g;    // Computed Parameter: Out1_Y0_g
                                          //  Referenced by: 'Out1' (':1186:6')

  px4_Bus_actuator_armed Constant_Value_f;// Computed Parameter: Constant_Value_f
                                             //  Referenced by: 'Constant' (':318:2')

  px4_Bus_actuator_armed Constant_Value_a;// Computed Parameter: Constant_Value_a
                                             //  Referenced by: 'Constant' (':1186:2')

  real_T Constant1_Value;              // Expression: 100
                                          //  Referenced by: 'Constant1' (':1078')

  real_T Constant2_Value;              // Expression: 100
                                          //  Referenced by: 'Constant2' (':1079')

  real_T Constant3_Value;              // Expression: 100
                                          //  Referenced by: 'Constant3' (':1080')

  real_T Constant4_Value;              // Expression: 100
                                          //  Referenced by: 'Constant4' (':1081')

  real_T Constant5_Value;              // Expression: 100
                                          //  Referenced by: 'Constant5' (':1082')

  real_T Constant_Value_hs;            // Expression: 100
                                          //  Referenced by: 'Constant' (':1077')

  real_T Constant_Value_gr;            // Expression: 1
                                          //  Referenced by: 'Constant' (':1744')

  real_T Constant1_Value_f;            // Expression: 1
                                          //  Referenced by: 'Constant1' (':1747')

  real_T Constant2_Value_n;            // Expression: 1
                                          //  Referenced by: 'Constant2' (':1748')

  real_T Gain_Gain;                    // Expression: 0.01
                                          //  Referenced by: 'Gain' (':1136:1')

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: 'Saturation' (':1136:6')

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: 'Saturation' (':1136:6')

  real_T Gain_Gain_l;                  // Expression: 0.01
                                          //  Referenced by: 'Gain' (':1137:1')

  real_T Saturation_UpperSat_f;        // Expression: 1
                                          //  Referenced by: 'Saturation' (':1137:6')

  real_T Saturation_LowerSat_a;        // Expression: 0
                                          //  Referenced by: 'Saturation' (':1137:6')

  real_T Gain_Gain_e;                  // Expression: 0.01
                                          //  Referenced by: 'Gain' (':1138:1')

  real_T Saturation_UpperSat_e;        // Expression: 1
                                          //  Referenced by: 'Saturation' (':1138:6')

  real_T Saturation_LowerSat_m;        // Expression: 0
                                          //  Referenced by: 'Saturation' (':1138:6')

  real_T Gain_Gain_n;                  // Expression: 0.01
                                          //  Referenced by: 'Gain' (':1139:1')

  real_T Saturation_UpperSat_a;        // Expression: 1
                                          //  Referenced by: 'Saturation' (':1139:6')

  real_T Saturation_LowerSat_d;        // Expression: 0
                                          //  Referenced by: 'Saturation' (':1139:6')

  real_T Gain_Gain_g;                  // Expression: 0.01
                                          //  Referenced by: 'Gain' (':1140:1')

  real_T Saturation_UpperSat_en;       // Expression: 1
                                          //  Referenced by: 'Saturation' (':1140:6')

  real_T Saturation_LowerSat_o;        // Expression: 0
                                          //  Referenced by: 'Saturation' (':1140:6')

  real_T Gain_Gain_f;                  // Expression: 0.01
                                          //  Referenced by: 'Gain' (':1141:1')

  real_T Saturation_UpperSat_k;        // Expression: 1
                                          //  Referenced by: 'Saturation' (':1141:6')

  real_T Saturation_LowerSat_k;        // Expression: 0
                                          //  Referenced by: 'Saturation' (':1141:6')

  real_T Constant_Value_k3;            // Expression: 1094
                                          //  Referenced by: 'Constant' (':352')

  real_T Gain_Gain_b;                  // Expression: 1/800
                                          //  Referenced by: 'Gain' (':380')

  real_T Constant5_Value_j;            // Expression: 5
                                          //  Referenced by: 'Constant5' (':2114')

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: 'Gain1' (':683')

  real32_T Gain_Gain_o;                // Computed Parameter: Gain_Gain_o
                                          //  Referenced by: 'Gain' (':682')

  real32_T Constant1_Value_j;          // Computed Parameter: Constant1_Value_j
                                          //  Referenced by: 'Constant1' (':1978:655')

  real32_T Constant1_Value_jy;         // Computed Parameter: Constant1_Value_jy
                                          //  Referenced by: 'Constant1' (':1991:655')

  real32_T Constant1_Value_i;          // Computed Parameter: Constant1_Value_i
                                          //  Referenced by: 'Constant1' (':2008:655')

  real32_T Mixermatrix_Value[24];      // Computed Parameter: Mixermatrix_Value
                                          //  Referenced by: 'Mixer matrix' (':160:192')

  real32_T Constant1_Value_k;          // Computed Parameter: Constant1_Value_k
                                          //  Referenced by: 'Constant1' (':160:2981')

  real32_T RateTransition4_InitialConditio;
                          // Computed Parameter: RateTransition4_InitialConditio
                             //  Referenced by: 'Rate Transition4' (':1068')

  real32_T RateTransition5_InitialConditio;
                          // Computed Parameter: RateTransition5_InitialConditio
                             //  Referenced by: 'Rate Transition5' (':1981')

  real32_T RateTransition2_InitialConditio;
                          // Computed Parameter: RateTransition2_InitialConditio
                             //  Referenced by: 'Rate Transition2' (':1974')

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: 'Integrator' (':1978:843')

  real32_T RateTransition18_InitialConditi;
                          // Computed Parameter: RateTransition18_InitialConditi
                             //  Referenced by: 'Rate Transition18' (':2012')

  real32_T UnitDelay1_InitialCondition;
                              // Computed Parameter: UnitDelay1_InitialCondition
                                 //  Referenced by: 'Unit Delay1' (':1967:220:338')

  real32_T RateTransition3_InitialConditio;
                          // Computed Parameter: RateTransition3_InitialConditio
                             //  Referenced by: 'Rate Transition3' (':1980')

  real32_T tau_Gain;                   // Computed Parameter: tau_Gain
                                          //  Referenced by: 'tau' (':1967:220:372')

  real32_T Bias_Bias;                  // Computed Parameter: Bias_Bias
                                          //  Referenced by: 'Bias' (':1967:220:373')

  real32_T Gain_Gain_a;                // Computed Parameter: Gain_Gain_a
                                          //  Referenced by: 'Gain' (':1967:220:358')

  real32_T TSamp_WtEt;                 // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: 'TSamp' (':1966:4')

  real32_T RateTransition2_InitialCondit_h;
                          // Computed Parameter: RateTransition2_InitialCondit_h
                             //  Referenced by: 'Rate Transition2' (':884')

  real32_T TSamp_WtEt_m;               // Computed Parameter: TSamp_WtEt_m
                                          //  Referenced by: 'TSamp' (':1524:4')

  real32_T RateTransition4_InitialCondit_m;
                          // Computed Parameter: RateTransition4_InitialCondit_m
                             //  Referenced by: 'Rate Transition4' (':1912')

  real32_T RateTransition5_InitialCondit_g;
                          // Computed Parameter: RateTransition5_InitialCondit_g
                             //  Referenced by: 'Rate Transition5' (':1913')

  real32_T RateTransition6_InitialConditio;
                          // Computed Parameter: RateTransition6_InitialConditio
                             //  Referenced by: 'Rate Transition6' (':1914')

  real32_T RateTransition9_InitialConditio;
                          // Computed Parameter: RateTransition9_InitialConditio
                             //  Referenced by: 'Rate Transition9' (':1917')

  real32_T RateTransition10_InitialConditi;
                          // Computed Parameter: RateTransition10_InitialConditi
                             //  Referenced by: 'Rate Transition10' (':1918')

  real32_T RateTransition11_InitialConditi;
                          // Computed Parameter: RateTransition11_InitialConditi
                             //  Referenced by: 'Rate Transition11' (':1919')

  real32_T RateTransition17_InitialConditi;
                          // Computed Parameter: RateTransition17_InitialConditi
                             //  Referenced by: 'Rate Transition17' (':1927')

  real32_T tau_Gain_f;                 // Computed Parameter: tau_Gain_f
                                          //  Referenced by: 'tau' (':1756:219:350')

  real32_T Bias_Bias_h;                // Computed Parameter: Bias_Bias_h
                                          //  Referenced by: 'Bias' (':1756:219:351')

  real32_T RateTransition1_InitialConditio;
                          // Computed Parameter: RateTransition1_InitialConditio
                             //  Referenced by: 'Rate Transition1' (':1911')

  real32_T UnitDelay_InitialCondition;
                               // Computed Parameter: UnitDelay_InitialCondition
                                  //  Referenced by: 'Unit Delay' (':1756:219:331')

  real32_T TSamp_WtEt_p;               // Computed Parameter: TSamp_WtEt_p
                                          //  Referenced by: 'TSamp' (':1522:4')

  real32_T TSamp_WtEt_l;               // Computed Parameter: TSamp_WtEt_l
                                          //  Referenced by: 'TSamp' (':1523:4')

  real32_T RateTransition7_InitialConditio;
                          // Computed Parameter: RateTransition7_InitialConditio
                             //  Referenced by: 'Rate Transition7' (':1915')

  real32_T RateTransition8_InitialConditio;
                          // Computed Parameter: RateTransition8_InitialConditio
                             //  Referenced by: 'Rate Transition8' (':1916')

  real32_T RateTransition12_InitialConditi;
                          // Computed Parameter: RateTransition12_InitialConditi
                             //  Referenced by: 'Rate Transition12' (':1920')

  real32_T RateTransition13_InitialConditi;
                          // Computed Parameter: RateTransition13_InitialConditi
                             //  Referenced by: 'Rate Transition13' (':1921')

  real32_T RateTransition14_InitialConditi;
                          // Computed Parameter: RateTransition14_InitialConditi
                             //  Referenced by: 'Rate Transition14' (':1922')

  real32_T Filter_gainval;             // Computed Parameter: Filter_gainval
                                          //  Referenced by: 'Filter' (':1817:737')

  real32_T Integrator_gainval_c;     // Computed Parameter: Integrator_gainval_c
                                        //  Referenced by: 'Integrator' (':1820:843')

  real32_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: 'Discrete-Time Integrator' (':1887')

  real32_T DiscreteTimeIntegrator_IC;
                                // Computed Parameter: DiscreteTimeIntegrator_IC
                                   //  Referenced by: 'Discrete-Time Integrator' (':1887')

  real32_T Saturation2_UpperSat;     // Computed Parameter: Saturation2_UpperSat
                                        //  Referenced by: 'Saturation2' (':1581')

  real32_T Saturation2_LowerSat;     // Computed Parameter: Saturation2_LowerSat
                                        //  Referenced by: 'Saturation2' (':1581')

  real32_T RateTransition8_InitialCondit_c;
                          // Computed Parameter: RateTransition8_InitialCondit_c
                             //  Referenced by: 'Rate Transition8' (':1988')

  real32_T RateTransition19_InitialConditi;
                          // Computed Parameter: RateTransition19_InitialConditi
                             //  Referenced by: 'Rate Transition19' (':2013')

  real32_T Integrator_gainval_l;     // Computed Parameter: Integrator_gainval_l
                                        //  Referenced by: 'Integrator' (':1991:843')

  real32_T RateTransition10_InitialCondi_k;
                          // Computed Parameter: RateTransition10_InitialCondi_k
                             //  Referenced by: 'Rate Transition10' (':1995')

  real32_T UnitDelay1_InitialCondition_i;
                            // Computed Parameter: UnitDelay1_InitialCondition_i
                               //  Referenced by: 'Unit Delay1' (':1984:220:338')

  real32_T RateTransition7_InitialCondit_l;
                          // Computed Parameter: RateTransition7_InitialCondit_l
                             //  Referenced by: 'Rate Transition7' (':1987')

  real32_T tau_Gain_k;                 // Computed Parameter: tau_Gain_k
                                          //  Referenced by: 'tau' (':1984:220:372')

  real32_T Bias_Bias_b;                // Computed Parameter: Bias_Bias_b
                                          //  Referenced by: 'Bias' (':1984:220:373')

  real32_T Gain_Gain_b3;               // Computed Parameter: Gain_Gain_b3
                                          //  Referenced by: 'Gain' (':1984:220:358')

  real32_T TSamp_WtEt_d;               // Computed Parameter: TSamp_WtEt_d
                                          //  Referenced by: 'TSamp' (':1983:4')

  real32_T RateTransition_InitialCondition;
                          // Computed Parameter: RateTransition_InitialCondition
                             //  Referenced by: 'Rate Transition' (':732')

  real32_T RateTransition1_InitialCondit_e;
                          // Computed Parameter: RateTransition1_InitialCondit_e
                             //  Referenced by: 'Rate Transition1' (':733')

  real32_T RateTransition13_InitialCondi_h;
                          // Computed Parameter: RateTransition13_InitialCondi_h
                             //  Referenced by: 'Rate Transition13' (':2004')

  real32_T RateTransition20_InitialConditi;
                          // Computed Parameter: RateTransition20_InitialConditi
                             //  Referenced by: 'Rate Transition20' (':2014')

  real32_T Integrator_gainval_e;     // Computed Parameter: Integrator_gainval_e
                                        //  Referenced by: 'Integrator' (':2008:843')

  real32_T RateTransition11_InitialCondi_g;
                          // Computed Parameter: RateTransition11_InitialCondi_g
                             //  Referenced by: 'Rate Transition11' (':2002')

  real32_T UnitDelay1_InitialCondition_m;
                            // Computed Parameter: UnitDelay1_InitialCondition_m
                               //  Referenced by: 'Unit Delay1' (':1999:220:338')

  real32_T RateTransition12_InitialCondi_h;
                          // Computed Parameter: RateTransition12_InitialCondi_h
                             //  Referenced by: 'Rate Transition12' (':2003')

  real32_T tau_Gain_d;                 // Computed Parameter: tau_Gain_d
                                          //  Referenced by: 'tau' (':1999:220:372')

  real32_T Bias_Bias_p;                // Computed Parameter: Bias_Bias_p
                                          //  Referenced by: 'Bias' (':1999:220:373')

  real32_T Gain_Gain_ow;               // Computed Parameter: Gain_Gain_ow
                                          //  Referenced by: 'Gain' (':1999:220:358')

  real32_T TSamp_WtEt_b;               // Computed Parameter: TSamp_WtEt_b
                                          //  Referenced by: 'TSamp' (':1998:4')

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: 'Saturation1' (':160:198')

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: 'Saturation1' (':160:198')

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: 'Gain2' (':160:2979')

  real32_T Constant_Value_ew;          // Computed Parameter: Constant_Value_ew
                                          //  Referenced by: 'Constant' (':1282')

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: 'Gain' (':1283')

  real32_T Constant_Value_b;           // Computed Parameter: Constant_Value_b
                                          //  Referenced by: 'Constant' (':1136:4658')

  real32_T Constant_Value_lg;          // Computed Parameter: Constant_Value_lg
                                          //  Referenced by: 'Constant' (':1137:4658')

  real32_T Constant_Value_n;           // Computed Parameter: Constant_Value_n
                                          //  Referenced by: 'Constant' (':1138:4658')

  real32_T Constant_Value_e3;          // Computed Parameter: Constant_Value_e3
                                          //  Referenced by: 'Constant' (':1139:4658')

  real32_T Constant_Value_d;           // Computed Parameter: Constant_Value_d
                                          //  Referenced by: 'Constant' (':1140:4658')

  real32_T Constant_Value_lv;          // Computed Parameter: Constant_Value_lv
                                          //  Referenced by: 'Constant' (':1141:4658')

  real32_T Bias1_Bias;                 // Computed Parameter: Bias1_Bias
                                          //  Referenced by: 'Bias1' (':1999:220:375')

  real32_T Gain1_Gain_b;               // Computed Parameter: Gain1_Gain_b
                                          //  Referenced by: 'Gain1' (':1999:220:340')

  real32_T UnitDelay2_InitialCondition;
                              // Computed Parameter: UnitDelay2_InitialCondition
                                 //  Referenced by: 'Unit Delay2' (':1999:220:342')

  real32_T Clamping_zero_Value;       // Computed Parameter: Clamping_zero_Value
                                         //  Referenced by: 'Clamping_zero' (':2008:4030')

  real32_T RateTransition14_InitialCondi_f;
                          // Computed Parameter: RateTransition14_InitialCondi_f
                             //  Referenced by: 'Rate Transition14' (':2005')

  real32_T Bias1_Bias_o;               // Computed Parameter: Bias1_Bias_o
                                          //  Referenced by: 'Bias1' (':1984:220:375')

  real32_T Gain1_Gain_l;               // Computed Parameter: Gain1_Gain_l
                                          //  Referenced by: 'Gain1' (':1984:220:340')

  real32_T UnitDelay2_InitialCondition_i;
                            // Computed Parameter: UnitDelay2_InitialCondition_i
                               //  Referenced by: 'Unit Delay2' (':1984:220:342')

  real32_T Clamping_zero_Value_a;   // Computed Parameter: Clamping_zero_Value_a
                                       //  Referenced by: 'Clamping_zero' (':1991:4030')

  real32_T RateTransition9_InitialCondit_i;
                          // Computed Parameter: RateTransition9_InitialCondit_i
                             //  Referenced by: 'Rate Transition9' (':1989')

  real32_T Gain_Gain_ar;               // Computed Parameter: Gain_Gain_ar
                                          //  Referenced by: 'Gain' (':1756:219:343')

  real32_T Bias1_Bias_k;               // Computed Parameter: Bias1_Bias_k
                                          //  Referenced by: 'Bias1' (':1756:219:352')

  real32_T Bias1_Bias_f;               // Computed Parameter: Bias1_Bias_f
                                          //  Referenced by: 'Bias1' (':1967:220:375')

  real32_T Gain1_Gain_h;               // Computed Parameter: Gain1_Gain_h
                                          //  Referenced by: 'Gain1' (':1967:220:340')

  real32_T UnitDelay2_InitialCondition_n;
                            // Computed Parameter: UnitDelay2_InitialCondition_n
                               //  Referenced by: 'Unit Delay2' (':1967:220:342')

  real32_T Clamping_zero_Value_b;   // Computed Parameter: Clamping_zero_Value_b
                                       //  Referenced by: 'Clamping_zero' (':1978:4030')

  real32_T RateTransition6_InitialCondit_f;
                          // Computed Parameter: RateTransition6_InitialCondit_f
                             //  Referenced by: 'Rate Transition6' (':1982')

  real32_T Constant3_Value_h;          // Computed Parameter: Constant3_Value_h
                                          //  Referenced by: 'Constant3' (':355')

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                          //  Referenced by: 'Gain3' (':384')

  real32_T DeadZone_Start;             // Computed Parameter: DeadZone_Start
                                          //  Referenced by: 'Dead Zone' (':364')

  real32_T DeadZone_End;               // Computed Parameter: DeadZone_End
                                          //  Referenced by: 'Dead Zone' (':364')

  real32_T Saturation3_UpperSat;     // Computed Parameter: Saturation3_UpperSat
                                        //  Referenced by: 'Saturation3' (':404')

  real32_T Saturation3_LowerSat;     // Computed Parameter: Saturation3_LowerSat
                                        //  Referenced by: 'Saturation3' (':404')

  real32_T Constant2_Value_e;          // Computed Parameter: Constant2_Value_e
                                          //  Referenced by: 'Constant2' (':354')

  real32_T Gain1_Gain_f;               // Computed Parameter: Gain1_Gain_f
                                          //  Referenced by: 'Gain1' (':381')

  real32_T DeadZone1_Start;            // Computed Parameter: DeadZone1_Start
                                          //  Referenced by: 'Dead Zone1' (':365')

  real32_T DeadZone1_End;              // Computed Parameter: DeadZone1_End
                                          //  Referenced by: 'Dead Zone1' (':365')

  real32_T Saturation2_UpperSat_c; // Computed Parameter: Saturation2_UpperSat_c
                                      //  Referenced by: 'Saturation2' (':403')

  real32_T Saturation2_LowerSat_h; // Computed Parameter: Saturation2_LowerSat_h
                                      //  Referenced by: 'Saturation2' (':403')

  real32_T Constant1_Value_c;          // Computed Parameter: Constant1_Value_c
                                          //  Referenced by: 'Constant1' (':353')

  real32_T Gain2_Gain_l;               // Computed Parameter: Gain2_Gain_l
                                          //  Referenced by: 'Gain2' (':383')

  real32_T DeadZone2_Start;            // Computed Parameter: DeadZone2_Start
                                          //  Referenced by: 'Dead Zone2' (':366')

  real32_T DeadZone2_End;              // Computed Parameter: DeadZone2_End
                                          //  Referenced by: 'Dead Zone2' (':366')

  real32_T Saturation1_UpperSat_p; // Computed Parameter: Saturation1_UpperSat_p
                                      //  Referenced by: 'Saturation1' (':401')

  real32_T Saturation1_LowerSat_e; // Computed Parameter: Saturation1_LowerSat_e
                                      //  Referenced by: 'Saturation1' (':401')

  real32_T DeadZone3_Start;            // Computed Parameter: DeadZone3_Start
                                          //  Referenced by: 'Dead Zone3' (':367')

  real32_T DeadZone3_End;              // Computed Parameter: DeadZone3_End
                                          //  Referenced by: 'Dead Zone3' (':367')

  real32_T Saturation_UpperSat_h;   // Computed Parameter: Saturation_UpperSat_h
                                       //  Referenced by: 'Saturation' (':400')

  real32_T Saturation_LowerSat_p;   // Computed Parameter: Saturation_LowerSat_p
                                       //  Referenced by: 'Saturation' (':400')

  real32_T DeadZone7_Start;            // Computed Parameter: DeadZone7_Start
                                          //  Referenced by: 'Dead Zone7' (':370')

  real32_T DeadZone7_End;              // Computed Parameter: DeadZone7_End
                                          //  Referenced by: 'Dead Zone7' (':370')

  real32_T Saturation10_UpperSat;   // Computed Parameter: Saturation10_UpperSat
                                       //  Referenced by: 'Saturation10' (':402')

  real32_T Saturation10_LowerSat;   // Computed Parameter: Saturation10_LowerSat
                                       //  Referenced by: 'Saturation10' (':402')

  real32_T Gain7_Gain;                 // Computed Parameter: Gain7_Gain
                                          //  Referenced by: 'Gain7' (':1862')

  real32_T Integrator_gainval_ei;   // Computed Parameter: Integrator_gainval_ei
                                       //  Referenced by: 'Integrator' (':1821:10:843')

  real32_T UnitDelay1_InitialCondition_e;
                            // Computed Parameter: UnitDelay1_InitialCondition_e
                               //  Referenced by: 'Unit Delay1' (':1821:2:220:338')

  real32_T tau_Gain_g;                 // Computed Parameter: tau_Gain_g
                                          //  Referenced by: 'tau' (':1821:2:220:372')

  real32_T Bias_Bias_n;                // Computed Parameter: Bias_Bias_n
                                          //  Referenced by: 'Bias' (':1821:2:220:373')

  real32_T Gain_Gain_oj;               // Computed Parameter: Gain_Gain_oj
                                          //  Referenced by: 'Gain' (':1821:2:220:358')

  real32_T TSamp_WtEt_n;               // Computed Parameter: TSamp_WtEt_n
                                          //  Referenced by: 'TSamp' (':1821:1:4')

  real32_T DeadZone6_Start;            // Computed Parameter: DeadZone6_Start
                                          //  Referenced by: 'Dead Zone6' (':369')

  real32_T DeadZone6_End;              // Computed Parameter: DeadZone6_End
                                          //  Referenced by: 'Dead Zone6' (':369')

  real32_T Saturation9_UpperSat;     // Computed Parameter: Saturation9_UpperSat
                                        //  Referenced by: 'Saturation9' (':407')

  real32_T Saturation9_LowerSat;     // Computed Parameter: Saturation9_LowerSat
                                        //  Referenced by: 'Saturation9' (':407')

  real32_T Gain8_Gain;                 // Computed Parameter: Gain8_Gain
                                          //  Referenced by: 'Gain8' (':1882')

  real32_T DeadZone4_Start;            // Computed Parameter: DeadZone4_Start
                                          //  Referenced by: 'Dead Zone4' (':368')

  real32_T DeadZone4_End;              // Computed Parameter: DeadZone4_End
                                          //  Referenced by: 'Dead Zone4' (':368')

  real32_T Saturation4_UpperSat;     // Computed Parameter: Saturation4_UpperSat
                                        //  Referenced by: 'Saturation4' (':405')

  real32_T Saturation4_LowerSat;     // Computed Parameter: Saturation4_LowerSat
                                        //  Referenced by: 'Saturation4' (':405')

  real32_T Gain9_Gain;                 // Computed Parameter: Gain9_Gain
                                          //  Referenced by: 'Gain9' (':1883')

  real32_T DiscreteTimeIntegrator_gainva_h;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_h
                             //  Referenced by: 'Discrete-Time Integrator' (':436')

  real32_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: 'Discrete-Time Integrator1' (':437')

  real32_T Integrator_gainval_f;     // Computed Parameter: Integrator_gainval_f
                                        //  Referenced by: 'Integrator' (':514:843')

  real32_T Constant4_Value_b;          // Computed Parameter: Constant4_Value_b
                                          //  Referenced by: 'Constant4' (':2034')

  real32_T Filter_gainval_f;           // Computed Parameter: Filter_gainval_f
                                          //  Referenced by: 'Filter' (':514:737')

  real32_T Constant1_Value_fy;         // Computed Parameter: Constant1_Value_fy
                                          //  Referenced by: 'Constant1' (':1239')

  real32_T u2_Gain;                    // Computed Parameter: u2_Gain
                                          //  Referenced by: '1//2' (':1231:2')

  real32_T Constant_Value_i;           // Computed Parameter: Constant_Value_i
                                          //  Referenced by: 'Constant' (':1224')

  real32_T Gain1_Gain_o;               // Computed Parameter: Gain1_Gain_o
                                          //  Referenced by: 'Gain1' (':190:180')

  real32_T Gain1_Gain_j;               // Computed Parameter: Gain1_Gain_j
                                          //  Referenced by: 'Gain1' (':191:180')

  real32_T Constant3_Value_m;          // Computed Parameter: Constant3_Value_m
                                          //  Referenced by: 'Constant3' (':1247')

  real32_T Bias1_Bias_m;               // Computed Parameter: Bias1_Bias_m
                                          //  Referenced by: 'Bias1' (':1821:2:220:375')

  real32_T Gain1_Gain_a;               // Computed Parameter: Gain1_Gain_a
                                          //  Referenced by: 'Gain1' (':1821:2:220:340')

  real32_T UnitDelay2_InitialCondition_m;
                            // Computed Parameter: UnitDelay2_InitialCondition_m
                               //  Referenced by: 'Unit Delay2' (':1821:2:220:342')

  real32_T Gain_Gain_eb;               // Computed Parameter: Gain_Gain_eb
                                          //  Referenced by: 'Gain' (':1763')

  uint16_T RateTransition_8_InitialConditi;
                          // Computed Parameter: RateTransition_8_InitialConditi
                             //  Referenced by: 'Rate Transition' (':1176')

  uint16_T Constant4_Value_f[6];       // Computed Parameter: Constant4_Value_f
                                          //  Referenced by: 'Constant4' (':1269')

  uint16_T Saturation_UpperSat_d;   // Computed Parameter: Saturation_UpperSat_d
                                       //  Referenced by: 'Saturation' (':1284')

  uint16_T Saturation_LowerSat_d0; // Computed Parameter: Saturation_LowerSat_d0
                                      //  Referenced by: 'Saturation' (':1284')

  uint16_T RateTransition_4_InitialConditi;
                          // Computed Parameter: RateTransition_4_InitialConditi
                             //  Referenced by: 'Rate Transition' (':1176')

  uint16_T Switch_Threshold;           // Computed Parameter: Switch_Threshold
                                          //  Referenced by: 'Switch' (':2119')

  boolean_T RateTransition15_InitialConditi;
                          // Computed Parameter: RateTransition15_InitialConditi
                             //  Referenced by: 'Rate Transition15' (':2009')

  boolean_T RateTransition16_InitialConditi;
                          // Computed Parameter: RateTransition16_InitialConditi
                             //  Referenced by: 'Rate Transition16' (':1925')

  boolean_T RateTransition15_InitialCondi_p;
                          // Computed Parameter: RateTransition15_InitialCondi_p
                             //  Referenced by: 'Rate Transition15' (':1924')

  boolean_T RateTransition16_InitialCondi_i;
                          // Computed Parameter: RateTransition16_InitialCondi_i
                             //  Referenced by: 'Rate Transition16' (':2010')

  boolean_T RateTransition17_InitialCondi_p;
                          // Computed Parameter: RateTransition17_InitialCondi_p
                             //  Referenced by: 'Rate Transition17' (':2011')

  boolean_T RateTransition2_16_InitialCondi;
                          // Computed Parameter: RateTransition2_16_InitialCondi
                             //  Referenced by: 'Rate Transition2' (':1298')

  boolean_T RateTransition2_17_InitialCondi;
                          // Computed Parameter: RateTransition2_17_InitialCondi
                             //  Referenced by: 'Rate Transition2' (':1298')

  int8_T Constant_Value_dr;            // Computed Parameter: Constant_Value_dr
                                          //  Referenced by: 'Constant' (':1978:3944')

  int8_T Constant2_Value_ns;           // Computed Parameter: Constant2_Value_ns
                                          //  Referenced by: 'Constant2' (':1978:3945')

  int8_T Constant3_Value_n;            // Computed Parameter: Constant3_Value_n
                                          //  Referenced by: 'Constant3' (':1978:3947')

  int8_T Constant4_Value_bo;           // Computed Parameter: Constant4_Value_bo
                                          //  Referenced by: 'Constant4' (':1978:3948')

  int8_T Constant_Value_fd;            // Computed Parameter: Constant_Value_fd
                                          //  Referenced by: 'Constant' (':1991:3944')

  int8_T Constant2_Value_g;            // Computed Parameter: Constant2_Value_g
                                          //  Referenced by: 'Constant2' (':1991:3945')

  int8_T Constant3_Value_b;            // Computed Parameter: Constant3_Value_b
                                          //  Referenced by: 'Constant3' (':1991:3947')

  int8_T Constant4_Value_h;            // Computed Parameter: Constant4_Value_h
                                          //  Referenced by: 'Constant4' (':1991:3948')

  int8_T Constant_Value_gl;            // Computed Parameter: Constant_Value_gl
                                          //  Referenced by: 'Constant' (':2008:3944')

  int8_T Constant2_Value_i;            // Computed Parameter: Constant2_Value_i
                                          //  Referenced by: 'Constant2' (':2008:3945')

  int8_T Constant3_Value_nf;           // Computed Parameter: Constant3_Value_nf
                                          //  Referenced by: 'Constant3' (':2008:3947')

  int8_T Constant4_Value_e;            // Computed Parameter: Constant4_Value_e
                                          //  Referenced by: 'Constant4' (':2008:3948')

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
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Unused code path elimination
//  Block synthesized block : Eliminate redundant data type conversion
//  Block synthesized block : Eliminate redundant data type conversion
//  Block synthesized block : Eliminate redundant data type conversion
//  Block synthesized block : Eliminate redundant data type conversion
//  Block synthesized block : Eliminated since input and output rates are identical


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is 'block_name' ('SID'), where block_name is the name of the block
//  and SID is the Simulink identifier of the block without the model name.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system(':3')    - opens block with Simulink identifier 'model:3'

#endif                                 // FLIGHT_Hexacopter_V2_h_

//
// File trailer for generated code.
//
// [EOF]
//
