//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: HITL_HEXA_WOPOSCTRL.h
//
// Code generated for Simulink model 'HITL_HEXA_WOPOSCTRL'.
//
// Model version                  : 4.141
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Sep 25 17:31:40 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_HITL_HEXA_WOPOSCTRL_h_
#define RTW_HEADER_HITL_HEXA_WOPOSCTRL_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "HITL_HEXA_WOPOSCTRL_types.h"
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/vehicle_attitude_setpoint.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_rates_setpoint.h>
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

// Block signals (default storage)
struct B_HITL_HEXA_WOPOSCTRL_T {
  px4_Bus_vehicle_odometry In1;        // '<S350>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  px4_Bus_actuator_outputs BusAssignment;// '<S9>/Bus Assignment'
  px4_Bus_actuator_outputs BusAssignment_m;// '<S9>/Bus Assignment'
  px4_Bus_input_rc In1_k;              // '<S19>/In1'
  px4_Bus_input_rc b_varargout_2_c;
  px4_Bus_vehicle_attitude_setpoint In1_c;// '<S353>/In1'
  px4_Bus_vehicle_attitude_setpoint b_varargout_2_k;
  px4_Bus_vehicle_attitude In1_m;      // '<S352>/In1'
  px4_Bus_vehicle_attitude b_varargout_2_cx;
  px4_Bus_vehicle_rates_setpoint BusAssignment_h;// '<S23>/Bus Assignment'
  px4_Bus_actuator_armed In1_b;        // '<S351>/In1'
  real_T CastToDouble2[3];             // '<S3>/Cast To Double2'
  real_T CastToDouble[6];              // '<S3>/Cast To Double'
  real_T VectorConcatenate[3];         // '<S31>/Vector Concatenate'
  px4_Bus_actuator_armed b_varargout_2_b;
  real_T Saturation;                   // '<S236>/Saturation'
  real_T Saturation_c;                 // '<S286>/Saturation'
  real_T Saturation_b;                 // '<S336>/Saturation'
  real_T Switch2;                      // '<S183>/Switch2'
  real_T Switch2_l;                    // '<S85>/Switch2'
  real_T Switch2_n;                    // '<S134>/Switch2'
  real_T IProdOut;                     // '<S326>/IProd Out'
  real_T Switch2_a;                    // '<S5>/Switch2'
  real_T Switch1_d;                    // '<S5>/Switch1'
  real_T Gain2;                        // '<S4>/Gain2'
  real_T Gain3;                        // '<S4>/Gain3'
  real_T Saturation1;                  // '<S11>/Saturation1'
  real_T rtb_Switch_j_idx_0;
  real_T rtb_Switch_j_idx_1;
  real_T rtb_Switch_j_idx_2;
  real_T rtb_Switch_j_idx_3;
  real_T u0;
  int32_T ParamStep;
  int32_T i;
};

// Block states (default storage) for system '<Root>'
struct DW_HITL_HEXA_WOPOSCTRL_T {
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj;// '<S27>/Read Parameter24' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_f;// '<S27>/Read Parameter23' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_d;// '<S27>/Read Parameter22' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_j;// '<S27>/Read Parameter21' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_l;// '<S27>/Read Parameter20' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_n;// '<S27>/Read Parameter19' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_h;// '<S27>/Read Parameter18' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_hj;// '<S27>/Read Parameter17' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_g;// '<S27>/Read Parameter16' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_p;// '<S26>/Read Parameter9' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_m;// '<S26>/Read Parameter6' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_jv;// '<S26>/Read Parameter5' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_k;// '<S26>/Read Parameter4' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_hg;// '<S26>/Read Parameter11' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_g2;// '<S26>/Read Parameter10' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_p1;// '<S6>/Read Parameter5' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_c;// '<S6>/Read Parameter4' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_n0;// '<S6>/Read Parameter3' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_ng;// '<S6>/Read Parameter2' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_ka;// '<S6>/Read Parameter13' 
  px4_internal_block_ParameterUpdate_HITL_HEXA_WOPOSCTRL_T obj_a;// '<S6>/Read Parameter1' 
  px4_internal_block_Subscriber_HITL_HEXA_WOPOSCTRL_T obj_mg;// '<S349>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_WOPOSCTRL_T obj_gv;// '<S348>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_WOPOSCTRL_T obj_d0;// '<S347>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_WOPOSCTRL_T obj_po;// '<S346>/SourceBlock' 
  px4_internal_block_Subscriber_HITL_HEXA_WOPOSCTRL_T obj_da;// '<S18>/SourceBlock' 
  px4_internal_block_getPX4AbsoluteTime_HITL_HEXA_WOPOSCTRL_T obj_kn;// '<S23>/PX4 Timestamp' 
  px4_internal_block_Publisher_HITL_HEXA_WOPOSCTRL_T obj_dz;// '<S29>/SinkBlock' 
  px4_internal_block_Publisher_HITL_HEXA_WOPOSCTRL_T obj_hy;// '<S21>/SinkBlock' 
  real_T Filter_DSTATE;                // '<S224>/Filter'
  real_T Integrator_DSTATE;            // '<S229>/Integrator'
  real_T Filter_DSTATE_h;              // '<S274>/Filter'
  real_T Integrator_DSTATE_d;          // '<S279>/Integrator'
  real_T Filter_DSTATE_l;              // '<S324>/Filter'
  real_T Integrator_DSTATE_dd;         // '<S329>/Integrator'
  real_T PrevY;                        // '<S26>/Rate Limiter2'
  real_T PrevY_b;                      // '<S26>/Rate Limiter1'
};

// Parameters (default storage)
struct P_HITL_HEXA_WOPOSCTRL_T_ {
  real_T PIDController_InitialConditionForFilter;
                      // Mask Parameter: PIDController_InitialConditionForFilter
                         //  Referenced by: '<S224>/Filter'

  real_T PIDController1_InitialConditionForFilter;
                     // Mask Parameter: PIDController1_InitialConditionForFilter
                        //  Referenced by: '<S274>/Filter'

  real_T PIDController2_InitialConditionForFilter;
                     // Mask Parameter: PIDController2_InitialConditionForFilter
                        //  Referenced by: '<S324>/Filter'

  real_T PIDController_InitialConditionForIntegrator;
                  // Mask Parameter: PIDController_InitialConditionForIntegrator
                     //  Referenced by: '<S229>/Integrator'

  real_T PIDController1_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController1_InitialConditionForIntegrator
                    //  Referenced by: '<S279>/Integrator'

  real_T PIDController2_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController2_InitialConditionForIntegrator
                    //  Referenced by: '<S329>/Integrator'

  real_T PIDController_LowerSaturationLimit;
                           // Mask Parameter: PIDController_LowerSaturationLimit
                              //  Referenced by:
                              //    '<S236>/Saturation'
                              //    '<S222>/DeadZone'

  real_T PIDController1_LowerSaturationLimit;
                          // Mask Parameter: PIDController1_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S286>/Saturation'
                             //    '<S272>/DeadZone'

  real_T PIDController2_LowerSaturationLimit;
                          // Mask Parameter: PIDController2_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S336>/Saturation'
                             //    '<S322>/DeadZone'

  real_T PIDController_UpperSaturationLimit;
                           // Mask Parameter: PIDController_UpperSaturationLimit
                              //  Referenced by:
                              //    '<S236>/Saturation'
                              //    '<S222>/DeadZone'

  real_T PIDController1_UpperSaturationLimit;
                          // Mask Parameter: PIDController1_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S286>/Saturation'
                             //    '<S272>/DeadZone'

  real_T PIDController2_UpperSaturationLimit;
                          // Mask Parameter: PIDController2_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S336>/Saturation'
                             //    '<S322>/DeadZone'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S10>/Constant'

  uint16_T CompareToConstant_const_k;
                                    // Mask Parameter: CompareToConstant_const_k
                                       //  Referenced by: '<S17>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S350>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S346>/Constant'

  px4_Bus_actuator_outputs Constant_Value_c;// Computed Parameter: Constant_Value_c
                                               //  Referenced by: '<S20>/Constant'

  px4_Bus_input_rc Out1_Y0_i;          // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S19>/Out1'

  px4_Bus_input_rc Constant_Value_l;   // Computed Parameter: Constant_Value_l
                                          //  Referenced by: '<S18>/Constant'

  px4_Bus_vehicle_attitude_setpoint Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                                 //  Referenced by: '<S353>/Out1'

  px4_Bus_vehicle_attitude_setpoint Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                        //  Referenced by: '<S349>/Constant'

  px4_Bus_vehicle_attitude Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S352>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_lh;// Computed Parameter: Constant_Value_lh
                                                //  Referenced by: '<S348>/Constant'

  px4_Bus_vehicle_rates_setpoint Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                     //  Referenced by: '<S28>/Constant'

  px4_Bus_actuator_armed Out1_Y0_d;    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S351>/Out1'

  px4_Bus_actuator_armed Constant_Value_jl;// Computed Parameter: Constant_Value_jl
                                              //  Referenced by: '<S347>/Constant'

  real_T Constant1_Value;              // Expression: 1000
                                          //  Referenced by: '<S5>/Constant1'

  real_T Fault1_Value;                 // Expression: 100
                                          //  Referenced by: '<S6>/Fault1'

  real_T Constant1_Value_j;            // Expression: 100
                                          //  Referenced by: '<S6>/Constant1'

  real_T Constant_Value_e1;            // Expression: 1100
                                          //  Referenced by: '<S12>/Constant'

  real_T Gain_Gain;                    // Expression: 0.01
                                          //  Referenced by: '<S12>/Gain'

  real_T Saturation1_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S12>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: 0
                                          //  Referenced by: '<S12>/Saturation1'

  real_T IDLEPWM_Value;                // Expression: 1100
                                          //  Referenced by: '<S12>/IDLE PWM'

  real_T Constant2_Value;              // Expression: 1000
                                          //  Referenced by: '<S5>/Constant2'

  real_T Fault2_Value;                 // Expression: 100
                                          //  Referenced by: '<S6>/Fault2'

  real_T Constant2_Value_o;            // Expression: 100
                                          //  Referenced by: '<S6>/Constant2'

  real_T Constant_Value_f;             // Expression: 1100
                                          //  Referenced by: '<S13>/Constant'

  real_T Gain_Gain_d;                  // Expression: 0.01
                                          //  Referenced by: '<S13>/Gain'

  real_T Saturation1_UpperSat_e;       // Expression: 1
                                          //  Referenced by: '<S13>/Saturation1'

  real_T Saturation1_LowerSat_m;       // Expression: 0
                                          //  Referenced by: '<S13>/Saturation1'

  real_T IDLEPWM_Value_j;              // Expression: 1100
                                          //  Referenced by: '<S13>/IDLE PWM'

  real_T Constant3_Value;              // Expression: 1000
                                          //  Referenced by: '<S5>/Constant3'

  real_T Fault3_Value;                 // Expression: 100
                                          //  Referenced by: '<S6>/Fault3'

  real_T Constant3_Value_b;            // Expression: 100
                                          //  Referenced by: '<S6>/Constant3'

  real_T Constant_Value_a;             // Expression: 1100
                                          //  Referenced by: '<S14>/Constant'

  real_T Gain_Gain_a;                  // Expression: 0.01
                                          //  Referenced by: '<S14>/Gain'

  real_T Saturation1_UpperSat_l;       // Expression: 1
                                          //  Referenced by: '<S14>/Saturation1'

  real_T Saturation1_LowerSat_g;       // Expression: 0
                                          //  Referenced by: '<S14>/Saturation1'

  real_T IDLEPWM_Value_k;              // Expression: 1100
                                          //  Referenced by: '<S14>/IDLE PWM'

  real_T Constant4_Value;              // Expression: 1000
                                          //  Referenced by: '<S5>/Constant4'

  real_T Fault4_Value;                 // Expression: 100
                                          //  Referenced by: '<S6>/Fault4'

  real_T Constant4_Value_e;            // Expression: 100
                                          //  Referenced by: '<S6>/Constant4'

  real_T Constant_Value_j3;            // Expression: 1100
                                          //  Referenced by: '<S15>/Constant'

  real_T Gain_Gain_o;                  // Expression: 0.01
                                          //  Referenced by: '<S15>/Gain'

  real_T Saturation1_UpperSat_eb;      // Expression: 1
                                          //  Referenced by: '<S15>/Saturation1'

  real_T Saturation1_LowerSat_b;       // Expression: 0
                                          //  Referenced by: '<S15>/Saturation1'

  real_T IDLEPWM_Value_c;              // Expression: 1100
                                          //  Referenced by: '<S15>/IDLE PWM'

  real_T Constant5_Value;              // Expression: 1000
                                          //  Referenced by: '<S5>/Constant5'

  real_T Fault5_Value;                 // Expression: 100
                                          //  Referenced by: '<S6>/Fault5'

  real_T Constant5_Value_f;            // Expression: 100
                                          //  Referenced by: '<S6>/Constant5'

  real_T Constant_Value_cx;            // Expression: 1100
                                          //  Referenced by: '<S16>/Constant'

  real_T Gain_Gain_ap;                 // Expression: 0.01
                                          //  Referenced by: '<S16>/Gain'

  real_T Saturation1_UpperSat_b;       // Expression: 1
                                          //  Referenced by: '<S16>/Saturation1'

  real_T Saturation1_LowerSat_o;       // Expression: 0
                                          //  Referenced by: '<S16>/Saturation1'

  real_T IDLEPWM_Value_e;              // Expression: 1100
                                          //  Referenced by: '<S16>/IDLE PWM'

  real_T Constant_Value_o;             // Expression: 1000
                                          //  Referenced by: '<S5>/Constant'

  real_T Fault_Value;                  // Expression: 100
                                          //  Referenced by: '<S6>/Fault'

  real_T Constant_Value_d;             // Expression: 100
                                          //  Referenced by: '<S6>/Constant'

  real_T Constant_Value_h;             // Expression: 1100
                                          //  Referenced by: '<S11>/Constant'

  real_T Gain_Gain_c;                  // Expression: 0.01
                                          //  Referenced by: '<S11>/Gain'

  real_T Saturation1_UpperSat_g;       // Expression: 1
                                          //  Referenced by: '<S11>/Saturation1'

  real_T Saturation1_LowerSat_c;       // Expression: 0
                                          //  Referenced by: '<S11>/Saturation1'

  real_T IDLEPWM_Value_h;              // Expression: 1100
                                          //  Referenced by: '<S11>/IDLE PWM'

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

  real_T Constant_Value_i[4];          // Expression: [1 0 0 0]
                                          //  Referenced by: '<S24>/Constant'

  real_T Constant_Value_b;             // Expression: 1
                                          //  Referenced by: '<S34>/Constant'

  real_T Constant_Value_m;             // Expression: 1
                                          //  Referenced by: '<S35>/Constant'

  real_T Switch1_Threshold;            // Expression: 0
                                          //  Referenced by: '<S39>/Switch1'

  real_T ReadParameter10_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S26>/Read Parameter10'

  real_T ReadParameter11_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S26>/Read Parameter11'

  real_T ReadParameter4_SampleTime_b;  // Expression: -1
                                          //  Referenced by: '<S26>/Read Parameter4'

  real_T ReadParameter5_SampleTime_m;  // Expression: -1
                                          //  Referenced by: '<S26>/Read Parameter5'

  real_T ReadParameter6_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S26>/Read Parameter6'

  real_T ReadParameter9_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S26>/Read Parameter9'

  real_T Yawrate_sp_Y0;                // Computed Parameter: Yawrate_sp_Y0
                                          //  Referenced by: '<S26>/Yawrate_sp'

  real_T Pitchrate_sp_Y0;              // Computed Parameter: Pitchrate_sp_Y0
                                          //  Referenced by: '<S26>/Pitchrate_sp'

  real_T Rollrate_spl_Y0;              // Computed Parameter: Rollrate_spl_Y0
                                          //  Referenced by: '<S26>/Rollrate_spl'

  real_T Constant_Value_p;             // Expression: 2*pi
                                          //  Referenced by: '<S39>/Constant'

  real_T Switch_Threshold;             // Expression: pi
                                          //  Referenced by: '<S39>/Switch'

  real_T RateLimiter2_RisingLim;       // Expression: 180*pi/180
                                          //  Referenced by: '<S26>/Rate Limiter2'

  real_T RateLimiter2_FallingLim;      // Expression: -180*pi/180
                                          //  Referenced by: '<S26>/Rate Limiter2'

  real_T RateLimiter2_IC;              // Expression: 0
                                          //  Referenced by: '<S26>/Rate Limiter2'

  real_T RateLimiter1_RisingLim;       // Expression: 180*pi/180
                                          //  Referenced by: '<S26>/Rate Limiter1'

  real_T RateLimiter1_FallingLim;      // Expression: -180*pi/180
                                          //  Referenced by: '<S26>/Rate Limiter1'

  real_T RateLimiter1_IC;              // Expression: 0
                                          //  Referenced by: '<S26>/Rate Limiter1'

  real_T ReadParameter16_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S27>/Read Parameter16'

  real_T ReadParameter17_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S27>/Read Parameter17'

  real_T ReadParameter18_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S27>/Read Parameter18'

  real_T ReadParameter19_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S27>/Read Parameter19'

  real_T ReadParameter20_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S27>/Read Parameter20'

  real_T ReadParameter21_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S27>/Read Parameter21'

  real_T ReadParameter22_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S27>/Read Parameter22'

  real_T ReadParameter23_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S27>/Read Parameter23'

  real_T ReadParameter24_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S27>/Read Parameter24'

  real_T tau_yaw_Y0;                   // Computed Parameter: tau_yaw_Y0
                                          //  Referenced by: '<S27>/tau_yaw'

  real_T tau_pitch_Y0;                 // Computed Parameter: tau_pitch_Y0
                                          //  Referenced by: '<S27>/tau_pitch'

  real_T tau_roll_Y0;                  // Computed Parameter: tau_roll_Y0
                                          //  Referenced by: '<S27>/tau_roll'

  real_T Constant1_Value_k;            // Expression: 0
                                          //  Referenced by: '<S220>/Constant1'

  real_T Constant1_Value_jx;           // Expression: 0
                                          //  Referenced by: '<S270>/Constant1'

  real_T Constant1_Value_ka;           // Expression: 0
                                          //  Referenced by: '<S320>/Constant1'

  real_T Constant_Value_pd;            // Expression: 100
                                          //  Referenced by: '<S27>/Constant'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S224>/Filter'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S229>/Integrator'

  real_T Clamping_zero_Value;          // Expression: 0
                                          //  Referenced by: '<S220>/Clamping_zero'

  real_T Constant1_Value_f;            // Expression: 50
                                          //  Referenced by: '<S27>/Constant1'

  real_T Filter_gainval_l;             // Computed Parameter: Filter_gainval_l
                                          //  Referenced by: '<S274>/Filter'

  real_T Integrator_gainval_b;       // Computed Parameter: Integrator_gainval_b
                                        //  Referenced by: '<S279>/Integrator'

  real_T Clamping_zero_Value_d;        // Expression: 0
                                          //  Referenced by: '<S270>/Clamping_zero'

  real_T Constant2_Value_n;            // Expression: 50
                                          //  Referenced by: '<S27>/Constant2'

  real_T Filter_gainval_a;             // Computed Parameter: Filter_gainval_a
                                          //  Referenced by: '<S324>/Filter'

  real_T Integrator_gainval_n;       // Computed Parameter: Integrator_gainval_n
                                        //  Referenced by: '<S329>/Integrator'

  real_T Clamping_zero_Value_e;        // Expression: 0
                                          //  Referenced by: '<S320>/Clamping_zero'

  real_T Switch_Threshold_l;           // Expression: 0
                                          //  Referenced by: '<S24>/Switch'

  real_T Gain_Gain_j;                  // Expression: 5
                                          //  Referenced by: '<S4>/Gain'

  real_T Gain1_Gain;                   // Expression: 5
                                          //  Referenced by: '<S4>/Gain1'

  real_T Gain2_Gain;                   // Expression: 10
                                          //  Referenced by: '<S4>/Gain2'

  real_T Gain3_Gain;                   // Expression: 1
                                          //  Referenced by: '<S4>/Gain3'

  real_T Constant_Value_g;             // Expression: 0
                                          //  Referenced by: '<S9>/Constant'

  real_T thrust_sp_bX_Value;           // Expression: 0
                                          //  Referenced by: '<S23>/thrust_sp_bX'

  real_T thrust_sp_bY_Value;           // Expression: 0
                                          //  Referenced by: '<S23>/thrust_sp_bY'

  real_T Constant17_Value;             // Expression: 6
                                          //  Referenced by: '<S9>/Constant17'

  real32_T Gain1_Gain_k;               // Computed Parameter: Gain1_Gain_k
                                          //  Referenced by: '<S42>/Gain1'

  real32_T Gain1_Gain_i;               // Computed Parameter: Gain1_Gain_i
                                          //  Referenced by: '<S40>/Gain1'

  real32_T Gain1_Gain_o;               // Computed Parameter: Gain1_Gain_o
                                          //  Referenced by: '<S41>/Gain1'

  int8_T Constant_Value_dt;            // Computed Parameter: Constant_Value_dt
                                          //  Referenced by: '<S220>/Constant'

  int8_T Constant2_Value_l;            // Computed Parameter: Constant2_Value_l
                                          //  Referenced by: '<S220>/Constant2'

  int8_T Constant3_Value_j;            // Computed Parameter: Constant3_Value_j
                                          //  Referenced by: '<S220>/Constant3'

  int8_T Constant4_Value_c;            // Computed Parameter: Constant4_Value_c
                                          //  Referenced by: '<S220>/Constant4'

  int8_T Constant_Value_d5;            // Computed Parameter: Constant_Value_d5
                                          //  Referenced by: '<S270>/Constant'

  int8_T Constant2_Value_e;            // Computed Parameter: Constant2_Value_e
                                          //  Referenced by: '<S270>/Constant2'

  int8_T Constant3_Value_k;            // Computed Parameter: Constant3_Value_k
                                          //  Referenced by: '<S270>/Constant3'

  int8_T Constant4_Value_n;            // Computed Parameter: Constant4_Value_n
                                          //  Referenced by: '<S270>/Constant4'

  int8_T Constant_Value_k;             // Computed Parameter: Constant_Value_k
                                          //  Referenced by: '<S320>/Constant'

  int8_T Constant2_Value_m;            // Computed Parameter: Constant2_Value_m
                                          //  Referenced by: '<S320>/Constant2'

  int8_T Constant3_Value_d;            // Computed Parameter: Constant3_Value_d
                                          //  Referenced by: '<S320>/Constant3'

  int8_T Constant4_Value_b;            // Computed Parameter: Constant4_Value_b
                                          //  Referenced by: '<S320>/Constant4'

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

};

// Real-time Model Data Structure
struct tag_RTM_HITL_HEXA_WOPOSCTRL_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_HITL_HEXA_WOPOSCTRL_T HITL_HEXA_WOPOSCTRL_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_HITL_HEXA_WOPOSCTRL_T HITL_HEXA_WOPOSCTRL_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_HITL_HEXA_WOPOSCTRL_T HITL_HEXA_WOPOSCTRL_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void HITL_HEXA_WOPOSCTRL_initialize(void);
  extern void HITL_HEXA_WOPOSCTRL_step(void);
  extern void HITL_HEXA_WOPOSCTRL_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_HITL_HEXA_WOPOSCTRL_T *const HITL_HEXA_WOPOSCTRL_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S6>/Scope' : Unused code path elimination
//  Block '<S8>/Bitwise Operator' : Unused code path elimination
//  Block '<S8>/Data Type Conversion' : Unused code path elimination
//  Block '<S8>/Data Type Conversion1' : Unused code path elimination
//  Block '<S8>/Data Type Conversion2' : Unused code path elimination
//  Block '<S8>/Gain' : Unused code path elimination
//  Block '<S8>/Gain1' : Unused code path elimination
//  Block '<S18>/NOT' : Unused code path elimination
//  Block '<S85>/Data Type Duplicate' : Unused code path elimination
//  Block '<S85>/Data Type Propagation' : Unused code path elimination
//  Block '<S134>/Data Type Duplicate' : Unused code path elimination
//  Block '<S134>/Data Type Propagation' : Unused code path elimination
//  Block '<S183>/Data Type Duplicate' : Unused code path elimination
//  Block '<S183>/Data Type Propagation' : Unused code path elimination
//  Block '<S346>/NOT' : Unused code path elimination
//  Block '<S347>/NOT' : Unused code path elimination
//  Block '<S348>/NOT' : Unused code path elimination
//  Block '<S349>/NOT' : Unused code path elimination
//  Block '<S22>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion3' : Eliminate redundant data type conversion


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
//  '<Root>' : 'HITL_HEXA_WOPOSCTRL'
//  '<S1>'   : 'HITL_HEXA_WOPOSCTRL/Actuator'
//  '<S2>'   : 'HITL_HEXA_WOPOSCTRL/CLAW'
//  '<S3>'   : 'HITL_HEXA_WOPOSCTRL/uORBInput'
//  '<S4>'   : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block'
//  '<S5>'   : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/Emergency Kill'
//  '<S6>'   : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/Fault_Injection'
//  '<S7>'   : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/MATLAB Function'
//  '<S8>'   : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/Radio Control Transmitter'
//  '<S9>'   : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/Subsystem'
//  '<S10>'  : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/Emergency Kill/Compare To Constant'
//  '<S11>'  : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM'
//  '<S12>'  : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM1'
//  '<S13>'  : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM2'
//  '<S14>'  : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM3'
//  '<S15>'  : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM4'
//  '<S16>'  : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Caculate Fault Injected PWM5'
//  '<S17>'  : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/Fault_Injection/Compare To Constant'
//  '<S18>'  : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/Radio Control Transmitter/PX4 uORB Read'
//  '<S19>'  : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S20>'  : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/Subsystem/PX4 uORB Message'
//  '<S21>'  : 'HITL_HEXA_WOPOSCTRL/Actuator/Custom Mixer and PWM Output Block/Subsystem/PX4 uORB Write'
//  '<S22>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller'
//  '<S23>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/Publish vehicle_rate_setpoint'
//  '<S24>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/Quaternion Validity Check'
//  '<S25>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/Quaternions to Rotation Angles'
//  '<S26>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller'
//  '<S27>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller'
//  '<S28>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/Publish vehicle_rate_setpoint/PX4 uORB Message'
//  '<S29>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/Publish vehicle_rate_setpoint/PX4 uORB Write'
//  '<S30>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/Quaternion Validity Check/Quaternion Norm'
//  '<S31>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation'
//  '<S32>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S33>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S34>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S35>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S36>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S37>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S38>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S39>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/Calculate minimum Turn'
//  '<S40>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/Degrees to Radians'
//  '<S41>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/Degrees to Radians1'
//  '<S42>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/Degrees to Radians2'
//  '<S43>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3'
//  '<S44>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4'
//  '<S45>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5'
//  '<S46>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Anti-windup'
//  '<S47>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/D Gain'
//  '<S48>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Filter'
//  '<S49>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Filter ICs'
//  '<S50>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/I Gain'
//  '<S51>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Ideal P Gain'
//  '<S52>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Ideal P Gain Fdbk'
//  '<S53>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Integrator'
//  '<S54>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Integrator ICs'
//  '<S55>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/N Copy'
//  '<S56>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/N Gain'
//  '<S57>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/P Copy'
//  '<S58>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Parallel P Gain'
//  '<S59>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Reset Signal'
//  '<S60>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Saturation'
//  '<S61>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Saturation Fdbk'
//  '<S62>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Sum'
//  '<S63>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Sum Fdbk'
//  '<S64>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Tracking Mode'
//  '<S65>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Tracking Mode Sum'
//  '<S66>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Tsamp - Integral'
//  '<S67>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Tsamp - Ngain'
//  '<S68>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/postSat Signal'
//  '<S69>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/preSat Signal'
//  '<S70>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Anti-windup/Disabled'
//  '<S71>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/D Gain/Disabled'
//  '<S72>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Filter/Disabled'
//  '<S73>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Filter ICs/Disabled'
//  '<S74>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/I Gain/Disabled'
//  '<S75>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Ideal P Gain/Passthrough'
//  '<S76>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S77>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Integrator/Disabled'
//  '<S78>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Integrator ICs/Disabled'
//  '<S79>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S80>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/N Gain/Disabled'
//  '<S81>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/P Copy/Disabled'
//  '<S82>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Parallel P Gain/External Parameters'
//  '<S83>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Reset Signal/Disabled'
//  '<S84>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Saturation/External'
//  '<S85>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Saturation/External/Saturation Dynamic'
//  '<S86>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Saturation Fdbk/Disabled'
//  '<S87>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Sum/Passthrough_P'
//  '<S88>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Sum Fdbk/Disabled'
//  '<S89>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Tracking Mode/Disabled'
//  '<S90>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S91>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S92>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S93>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/postSat Signal/Forward_Path'
//  '<S94>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller3/preSat Signal/Forward_Path'
//  '<S95>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Anti-windup'
//  '<S96>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/D Gain'
//  '<S97>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Filter'
//  '<S98>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Filter ICs'
//  '<S99>'  : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/I Gain'
//  '<S100>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Ideal P Gain'
//  '<S101>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S102>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Integrator'
//  '<S103>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Integrator ICs'
//  '<S104>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/N Copy'
//  '<S105>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/N Gain'
//  '<S106>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/P Copy'
//  '<S107>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Parallel P Gain'
//  '<S108>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Reset Signal'
//  '<S109>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Saturation'
//  '<S110>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Saturation Fdbk'
//  '<S111>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Sum'
//  '<S112>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Sum Fdbk'
//  '<S113>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Tracking Mode'
//  '<S114>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Tracking Mode Sum'
//  '<S115>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Tsamp - Integral'
//  '<S116>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Tsamp - Ngain'
//  '<S117>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/postSat Signal'
//  '<S118>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/preSat Signal'
//  '<S119>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Anti-windup/Disabled'
//  '<S120>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/D Gain/Disabled'
//  '<S121>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Filter/Disabled'
//  '<S122>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Filter ICs/Disabled'
//  '<S123>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/I Gain/Disabled'
//  '<S124>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S125>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S126>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Integrator/Disabled'
//  '<S127>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Integrator ICs/Disabled'
//  '<S128>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S129>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/N Gain/Disabled'
//  '<S130>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/P Copy/Disabled'
//  '<S131>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Parallel P Gain/External Parameters'
//  '<S132>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Reset Signal/Disabled'
//  '<S133>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Saturation/External'
//  '<S134>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Saturation/External/Saturation Dynamic'
//  '<S135>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S136>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Sum/Passthrough_P'
//  '<S137>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S138>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Tracking Mode/Disabled'
//  '<S139>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S140>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S141>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S142>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S143>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S144>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Anti-windup'
//  '<S145>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/D Gain'
//  '<S146>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Filter'
//  '<S147>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Filter ICs'
//  '<S148>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/I Gain'
//  '<S149>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Ideal P Gain'
//  '<S150>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Ideal P Gain Fdbk'
//  '<S151>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Integrator'
//  '<S152>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Integrator ICs'
//  '<S153>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/N Copy'
//  '<S154>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/N Gain'
//  '<S155>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/P Copy'
//  '<S156>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Parallel P Gain'
//  '<S157>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Reset Signal'
//  '<S158>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Saturation'
//  '<S159>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Saturation Fdbk'
//  '<S160>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Sum'
//  '<S161>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Sum Fdbk'
//  '<S162>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Tracking Mode'
//  '<S163>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Tracking Mode Sum'
//  '<S164>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Tsamp - Integral'
//  '<S165>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Tsamp - Ngain'
//  '<S166>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/postSat Signal'
//  '<S167>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/preSat Signal'
//  '<S168>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Anti-windup/Disabled'
//  '<S169>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/D Gain/Disabled'
//  '<S170>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Filter/Disabled'
//  '<S171>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Filter ICs/Disabled'
//  '<S172>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/I Gain/Disabled'
//  '<S173>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Ideal P Gain/Passthrough'
//  '<S174>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Ideal P Gain Fdbk/Disabled'
//  '<S175>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Integrator/Disabled'
//  '<S176>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Integrator ICs/Disabled'
//  '<S177>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/N Copy/Disabled wSignal Specification'
//  '<S178>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/N Gain/Disabled'
//  '<S179>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/P Copy/Disabled'
//  '<S180>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Parallel P Gain/External Parameters'
//  '<S181>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Reset Signal/Disabled'
//  '<S182>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Saturation/External'
//  '<S183>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Saturation/External/Saturation Dynamic'
//  '<S184>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Saturation Fdbk/Disabled'
//  '<S185>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Sum/Passthrough_P'
//  '<S186>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Sum Fdbk/Disabled'
//  '<S187>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Tracking Mode/Disabled'
//  '<S188>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Tracking Mode Sum/Passthrough'
//  '<S189>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Tsamp - Integral/TsSignalSpecification'
//  '<S190>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/Tsamp - Ngain/Passthrough'
//  '<S191>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/postSat Signal/Forward_Path'
//  '<S192>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_att_controller/PID Controller5/preSat Signal/Forward_Path'
//  '<S193>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller'
//  '<S194>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1'
//  '<S195>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2'
//  '<S196>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Anti-windup'
//  '<S197>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/D Gain'
//  '<S198>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Filter'
//  '<S199>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Filter ICs'
//  '<S200>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/I Gain'
//  '<S201>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Ideal P Gain'
//  '<S202>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Ideal P Gain Fdbk'
//  '<S203>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Integrator'
//  '<S204>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Integrator ICs'
//  '<S205>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/N Copy'
//  '<S206>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/N Gain'
//  '<S207>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/P Copy'
//  '<S208>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Parallel P Gain'
//  '<S209>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Reset Signal'
//  '<S210>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Saturation'
//  '<S211>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Saturation Fdbk'
//  '<S212>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Sum'
//  '<S213>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Sum Fdbk'
//  '<S214>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Tracking Mode'
//  '<S215>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Tracking Mode Sum'
//  '<S216>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Tsamp - Integral'
//  '<S217>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Tsamp - Ngain'
//  '<S218>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/postSat Signal'
//  '<S219>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/preSat Signal'
//  '<S220>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S221>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S222>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S223>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/D Gain/External Parameters'
//  '<S224>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S225>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S226>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/I Gain/External Parameters'
//  '<S227>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S228>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S229>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Integrator/Discrete'
//  '<S230>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Integrator ICs/Internal IC'
//  '<S231>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/N Copy/Disabled'
//  '<S232>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/N Gain/External Parameters'
//  '<S233>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/P Copy/Disabled'
//  '<S234>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Parallel P Gain/External Parameters'
//  '<S235>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Reset Signal/Disabled'
//  '<S236>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Saturation/Enabled'
//  '<S237>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S238>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Sum/Sum_PID'
//  '<S239>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Sum Fdbk/Disabled'
//  '<S240>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Tracking Mode/Disabled'
//  '<S241>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S242>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S243>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S244>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/postSat Signal/Forward_Path'
//  '<S245>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller/preSat Signal/Forward_Path'
//  '<S246>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Anti-windup'
//  '<S247>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/D Gain'
//  '<S248>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Filter'
//  '<S249>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Filter ICs'
//  '<S250>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/I Gain'
//  '<S251>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Ideal P Gain'
//  '<S252>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S253>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Integrator'
//  '<S254>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Integrator ICs'
//  '<S255>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/N Copy'
//  '<S256>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/N Gain'
//  '<S257>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/P Copy'
//  '<S258>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Parallel P Gain'
//  '<S259>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Reset Signal'
//  '<S260>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Saturation'
//  '<S261>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Saturation Fdbk'
//  '<S262>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Sum'
//  '<S263>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Sum Fdbk'
//  '<S264>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Tracking Mode'
//  '<S265>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Tracking Mode Sum'
//  '<S266>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Tsamp - Integral'
//  '<S267>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Tsamp - Ngain'
//  '<S268>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/postSat Signal'
//  '<S269>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/preSat Signal'
//  '<S270>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S271>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S272>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S273>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/D Gain/External Parameters'
//  '<S274>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S275>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S276>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/I Gain/External Parameters'
//  '<S277>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S278>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S279>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Integrator/Discrete'
//  '<S280>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Integrator ICs/Internal IC'
//  '<S281>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/N Copy/Disabled'
//  '<S282>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/N Gain/External Parameters'
//  '<S283>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/P Copy/Disabled'
//  '<S284>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Parallel P Gain/External Parameters'
//  '<S285>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Reset Signal/Disabled'
//  '<S286>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Saturation/Enabled'
//  '<S287>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S288>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Sum/Sum_PID'
//  '<S289>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S290>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Tracking Mode/Disabled'
//  '<S291>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S292>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S293>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S294>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S295>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S296>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Anti-windup'
//  '<S297>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/D Gain'
//  '<S298>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Filter'
//  '<S299>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Filter ICs'
//  '<S300>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/I Gain'
//  '<S301>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Ideal P Gain'
//  '<S302>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Ideal P Gain Fdbk'
//  '<S303>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Integrator'
//  '<S304>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Integrator ICs'
//  '<S305>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/N Copy'
//  '<S306>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/N Gain'
//  '<S307>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/P Copy'
//  '<S308>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Parallel P Gain'
//  '<S309>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Reset Signal'
//  '<S310>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Saturation'
//  '<S311>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Saturation Fdbk'
//  '<S312>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Sum'
//  '<S313>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Sum Fdbk'
//  '<S314>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Tracking Mode'
//  '<S315>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Tracking Mode Sum'
//  '<S316>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Tsamp - Integral'
//  '<S317>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Tsamp - Ngain'
//  '<S318>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/postSat Signal'
//  '<S319>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/preSat Signal'
//  '<S320>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S321>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S322>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S323>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/D Gain/External Parameters'
//  '<S324>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S325>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S326>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/I Gain/External Parameters'
//  '<S327>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Ideal P Gain/Passthrough'
//  '<S328>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S329>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Integrator/Discrete'
//  '<S330>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Integrator ICs/Internal IC'
//  '<S331>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/N Copy/Disabled'
//  '<S332>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/N Gain/External Parameters'
//  '<S333>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/P Copy/Disabled'
//  '<S334>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Parallel P Gain/External Parameters'
//  '<S335>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Reset Signal/Disabled'
//  '<S336>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Saturation/Enabled'
//  '<S337>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Saturation Fdbk/Disabled'
//  '<S338>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Sum/Sum_PID'
//  '<S339>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Sum Fdbk/Disabled'
//  '<S340>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Tracking Mode/Disabled'
//  '<S341>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S342>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S343>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S344>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/postSat Signal/Forward_Path'
//  '<S345>' : 'HITL_HEXA_WOPOSCTRL/CLAW/Controller/mc_rate_controller/PID Controller2/preSat Signal/Forward_Path'
//  '<S346>' : 'HITL_HEXA_WOPOSCTRL/uORBInput/PX4 uORB Read1'
//  '<S347>' : 'HITL_HEXA_WOPOSCTRL/uORBInput/PX4 uORB Read2'
//  '<S348>' : 'HITL_HEXA_WOPOSCTRL/uORBInput/vehicle_attitude'
//  '<S349>' : 'HITL_HEXA_WOPOSCTRL/uORBInput/vehicle_attitude_setpoint'
//  '<S350>' : 'HITL_HEXA_WOPOSCTRL/uORBInput/PX4 uORB Read1/Enabled Subsystem'
//  '<S351>' : 'HITL_HEXA_WOPOSCTRL/uORBInput/PX4 uORB Read2/Enabled Subsystem'
//  '<S352>' : 'HITL_HEXA_WOPOSCTRL/uORBInput/vehicle_attitude/Enabled Subsystem'
//  '<S353>' : 'HITL_HEXA_WOPOSCTRL/uORBInput/vehicle_attitude_setpoint/Enabled Subsystem'

#endif                                 // RTW_HEADER_HITL_HEXA_WOPOSCTRL_h_

//
// File trailer for generated code.
//
// [EOF]
//
