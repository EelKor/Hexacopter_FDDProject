//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_Hexacopter_fromNCMS.h
//
// Code generated for Simulink model 'FLIGHT_Hexacopter_fromNCMS'.
//
// Model version                  : 6.14
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Thu Jan  9 19:43:22 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef FLIGHT_Hexacopter_fromNCMS_h_
#define FLIGHT_Hexacopter_fromNCMS_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rt_logging.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "FLIGHT_Hexacopter_fromNCMS_types.h"
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/sensor_gyro.h>

extern "C"
{

#include "rtGetNaN.h"

}

#include <float.h>
#include <stddef.h>

extern "C"
{

#include "rt_nonfinite.h"

}

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

// Block signals (default storage)
struct B_FLIGHT_Hexacopter_fromNCMS_T {
  px4_Bus_vehicle_local_position In1;  // '<S182>/In1'
  px4_Bus_vehicle_local_position r;
  px4_Bus_vehicle_odometry In1_n;      // '<S184>/In1'
  px4_Bus_vehicle_odometry r1;
  px4_Bus_input_rc In1_k;              // '<S187>/In1'
  px4_Bus_input_rc r2;
  px4_Bus_sensor_gyro In1_l;           // '<S181>/In1'
  px4_Bus_sensor_gyro r3;
  uint16_T pwmValue[8];
  real32_T Merge1[4];                  // '<Root>/Merge1'
  real_T u0;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real32_T IntegralGain_e;             // '<S46>/Integral Gain'
  real32_T FilterCoefficient_i;        // '<S52>/Filter Coefficient'
  real32_T DeadZone_k;                 // '<S41>/DeadZone'
  int32_T ParamStep;
  int32_T ParamStep_m;
  int32_T ParamStep_c;
  int32_T ParamStep_k;
  int32_T ParamStep_cx;
  int32_T ParamStep_b;
};

// Block states (default storage) for system '<Root>'
struct DW_FLIGHT_Hexacopter_fromNCMS_T {
  px4_internal_block_ParameterU_T obj; // '<S4>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_f;// '<S4>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_n;// '<S4>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_b;// '<S4>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_k;// '<S4>/Read Parameter13'
  px4_internal_block_ParameterU_T obj_fo;// '<S4>/Read Parameter1'
  px4_internal_block_Subscriber_T obj_fg;// '<S186>/SourceBlock'
  px4_internal_block_Subscriber_T obj_j;// '<S183>/SourceBlock'
  px4_internal_block_Subscriber_T obj_e;// '<S178>/SourceBlock'
  px4_internal_block_Subscriber_T obj_no;// '<S180>/SourceBlock'
  px4_internal_block_PWM_FLIGHT_T obj_nt;// '<Root>/PX4 PWM Output'
  real32_T Integrator_DSTATE;          // '<S278>/Integrator'
  real32_T Filter_DSTATE;              // '<S273>/Filter'
  real32_T Integrator_DSTATE_g;        // '<S226>/Integrator'
  real32_T Filter_DSTATE_f;            // '<S221>/Filter'
  real32_T Integrator_DSTATE_h;        // '<S330>/Integrator'
  real32_T Filter_DSTATE_n;            // '<S325>/Filter'
  real32_T Integrator_DSTATE_n;        // '<S49>/Integrator'
  real32_T Filter_DSTATE_b;            // '<S44>/Filter'
  real32_T PrevY;                      // '<S3>/Rate Limiter1'
  real32_T PrevY_o;                    // '<S3>/Rate Limiter2'
};

// Parameters (default storage)
struct P_FLIGHT_Hexacopter_fromNCMS_T_ {
  real32_T Kdpr;                       // Variable: Kdpr
                                          //  Referenced by: '<S219>/Derivative Gain'

  real32_T Kdrr;                       // Variable: Kdrr
                                          //  Referenced by: '<S271>/Derivative Gain'

  real32_T Kdvz;                       // Variable: Kdvz
                                          //  Referenced by: '<S42>/Derivative Gain'

  real32_T Kdyr;                       // Variable: Kdyr
                                          //  Referenced by: '<S323>/Derivative Gain'

  real32_T Kipr;                       // Variable: Kipr
                                          //  Referenced by: '<S223>/Integral Gain'

  real32_T Kirr;                       // Variable: Kirr
                                          //  Referenced by: '<S275>/Integral Gain'

  real32_T Kivz;                       // Variable: Kivz
                                          //  Referenced by: '<S46>/Integral Gain'

  real32_T Kiyr;                       // Variable: Kiyr
                                          //  Referenced by: '<S327>/Integral Gain'

  real32_T Kpp;                        // Variable: Kpp
                                          //  Referenced by: '<S107>/Proportional Gain'

  real32_T Kppr;                       // Variable: Kppr
                                          //  Referenced by: '<S231>/Proportional Gain'

  real32_T Kpr;                        // Variable: Kpr
                                          //  Referenced by: '<S157>/Proportional Gain'

  real32_T Kprr;                       // Variable: Kprr
                                          //  Referenced by: '<S283>/Proportional Gain'

  real32_T Kpvz;                       // Variable: Kpvz
                                          //  Referenced by: '<S54>/Proportional Gain'

  real32_T Kpyr;                       // Variable: Kpyr
                                          //  Referenced by: '<S335>/Proportional Gain'

  real32_T MAX_CONTROL_ANGLE_PITCH;    // Variable: MAX_CONTROL_ANGLE_PITCH
                                          //  Referenced by:
                                          //    '<S3>/Saturation1'
                                          //    '<S11>/Gain2'

  real32_T MAX_CONTROL_ANGLE_RATE_PITCH;// Variable: MAX_CONTROL_ANGLE_RATE_PITCH
                                           //  Referenced by: '<S109>/Saturation'

  real32_T MAX_CONTROL_ANGLE_RATE_ROLL;// Variable: MAX_CONTROL_ANGLE_RATE_ROLL
                                          //  Referenced by: '<S159>/Saturation'

  real32_T MAX_CONTROL_ANGLE_RATE_Y;   // Variable: MAX_CONTROL_ANGLE_RATE_Y
                                          //  Referenced by: '<S11>/Gain3'

  real32_T MAX_CONTROL_ANGLE_ROLL;     // Variable: MAX_CONTROL_ANGLE_ROLL
                                          //  Referenced by:
                                          //    '<S3>/Saturation'
                                          //    '<S11>/Gain1'

  real32_T Npr;                        // Variable: Npr
                                          //  Referenced by: '<S229>/Filter Coefficient'

  real32_T Nrr;                        // Variable: Nrr
                                          //  Referenced by: '<S281>/Filter Coefficient'

  real32_T Nvz;                        // Variable: Nvz
                                          //  Referenced by: '<S52>/Filter Coefficient'

  real32_T Nyr;                        // Variable: Nyr
                                          //  Referenced by: '<S333>/Filter Coefficient'

  real32_T THR_HOVER;                  // Variable: THR_HOVER
                                          //  Referenced by: '<S12>/Hovering Thrust'

  real32_T PIDController4_InitialCondition;
                              // Mask Parameter: PIDController4_InitialCondition
                                 //  Referenced by: '<S44>/Filter'

  real32_T PIDController2_InitialCondition;
                              // Mask Parameter: PIDController2_InitialCondition
                                 //  Referenced by: '<S273>/Filter'

  real32_T PIDController1_InitialCondition;
                              // Mask Parameter: PIDController1_InitialCondition
                                 //  Referenced by: '<S221>/Filter'

  real32_T PIDController6_InitialCondition;
                              // Mask Parameter: PIDController6_InitialCondition
                                 //  Referenced by: '<S325>/Filter'

  real32_T PIDController4_InitialConditi_l;
                              // Mask Parameter: PIDController4_InitialConditi_l
                                 //  Referenced by: '<S49>/Integrator'

  real32_T PIDController2_InitialConditi_l;
                              // Mask Parameter: PIDController2_InitialConditi_l
                                 //  Referenced by: '<S278>/Integrator'

  real32_T PIDController1_InitialConditi_o;
                              // Mask Parameter: PIDController1_InitialConditi_o
                                 //  Referenced by: '<S226>/Integrator'

  real32_T PIDController6_InitialConditi_g;
                              // Mask Parameter: PIDController6_InitialConditi_g
                                 //  Referenced by: '<S330>/Integrator'

  real32_T PIDController4_LowerSaturationL;
                              // Mask Parameter: PIDController4_LowerSaturationL
                                 //  Referenced by:
                                 //    '<S56>/Saturation'
                                 //    '<S41>/DeadZone'

  real32_T PIDController4_LowerSaturatio_m;
                              // Mask Parameter: PIDController4_LowerSaturatio_m
                                 //  Referenced by: '<S159>/Saturation'

  real32_T PIDController2_LowerSaturationL;
                              // Mask Parameter: PIDController2_LowerSaturationL
                                 //  Referenced by:
                                 //    '<S285>/Saturation'
                                 //    '<S270>/DeadZone'

  real32_T PIDController3_LowerSaturationL;
                              // Mask Parameter: PIDController3_LowerSaturationL
                                 //  Referenced by: '<S109>/Saturation'

  real32_T PIDController1_LowerSaturationL;
                              // Mask Parameter: PIDController1_LowerSaturationL
                                 //  Referenced by:
                                 //    '<S233>/Saturation'
                                 //    '<S218>/DeadZone'

  real32_T PIDController6_LowerSaturationL;
                              // Mask Parameter: PIDController6_LowerSaturationL
                                 //  Referenced by:
                                 //    '<S337>/Saturation'
                                 //    '<S322>/DeadZone'

  real32_T PIDController4_UpperSaturationL;
                              // Mask Parameter: PIDController4_UpperSaturationL
                                 //  Referenced by:
                                 //    '<S56>/Saturation'
                                 //    '<S41>/DeadZone'

  real32_T PIDController2_UpperSaturationL;
                              // Mask Parameter: PIDController2_UpperSaturationL
                                 //  Referenced by:
                                 //    '<S285>/Saturation'
                                 //    '<S270>/DeadZone'

  real32_T PIDController1_UpperSaturationL;
                              // Mask Parameter: PIDController1_UpperSaturationL
                                 //  Referenced by:
                                 //    '<S233>/Saturation'
                                 //    '<S218>/DeadZone'

  real32_T PIDController6_UpperSaturationL;
                              // Mask Parameter: PIDController6_UpperSaturationL
                                 //  Referenced by:
                                 //    '<S337>/Saturation'
                                 //    '<S322>/DeadZone'

  uint16_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S169>/Constant'

  uint16_T CompareToConstant3_const; // Mask Parameter: CompareToConstant3_const
                                        //  Referenced by: '<S66>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0;// Computed Parameter: Out1_Y0
                                            //  Referenced by: '<S182>/Out1'

  px4_Bus_vehicle_local_position Constant_Value;// Computed Parameter: Constant_Value
                                                   //  Referenced by: '<S178>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0_b;  // Computed Parameter: Out1_Y0_b
                                          //  Referenced by: '<S184>/Out1'

  px4_Bus_vehicle_odometry Constant_Value_m;// Computed Parameter: Constant_Value_m
                                               //  Referenced by: '<S183>/Constant'

  px4_Bus_input_rc Out1_Y0_o;          // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S187>/Out1'

  px4_Bus_input_rc Constant_Value_a;   // Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<S186>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_k;       // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S181>/Out1'

  px4_Bus_sensor_gyro Constant_Value_j;// Computed Parameter: Constant_Value_j
                                          //  Referenced by: '<S180>/Constant'

  real_T ReadParameter1_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S4>/Read Parameter1'

  real_T ReadParameter13_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S4>/Read Parameter13'

  real_T ReadParameter2_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S4>/Read Parameter2'

  real_T ReadParameter3_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S4>/Read Parameter3'

  real_T ReadParameter4_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S4>/Read Parameter4'

  real_T ReadParameter5_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S4>/Read Parameter5'

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

  real_T Constant_Value_c;             // Expression: 100
                                          //  Referenced by: '<S4>/Constant'

  real_T Constant_Value_a1;            // Expression: 1100
                                          //  Referenced by: '<S9>/Constant'

  real_T Gain_Gain;                    // Expression: 1/800
                                          //  Referenced by: '<S9>/Gain'

  real_T RateLimiter1_RisingLim;       // Expression: 40*pi/180
                                          //  Referenced by: '<S3>/Rate Limiter1'

  real_T RateLimiter1_FallingLim;      // Expression: -40*pi/180
                                          //  Referenced by: '<S3>/Rate Limiter1'

  real_T RateLimiter2_RisingLim;       // Expression: 40*pi/180
                                          //  Referenced by: '<S3>/Rate Limiter2'

  real_T RateLimiter2_FallingLim;      // Expression: -40*pi/180
                                          //  Referenced by: '<S3>/Rate Limiter2'

  real_T Gain_Gain_k;                  // Expression: 0.01
                                          //  Referenced by: '<S170>/Gain'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<S170>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S170>/Saturation'

  real_T Gain_Gain_h;                  // Expression: 0.01
                                          //  Referenced by: '<S171>/Gain'

  real_T Saturation_UpperSat_l;        // Expression: 1
                                          //  Referenced by: '<S171>/Saturation'

  real_T Saturation_LowerSat_h;        // Expression: 0
                                          //  Referenced by: '<S171>/Saturation'

  real_T Gain_Gain_n;                  // Expression: 0.01
                                          //  Referenced by: '<S172>/Gain'

  real_T Saturation_UpperSat_d;        // Expression: 1
                                          //  Referenced by: '<S172>/Saturation'

  real_T Saturation_LowerSat_c;        // Expression: 0
                                          //  Referenced by: '<S172>/Saturation'

  real_T Gain_Gain_f;                  // Expression: 0.01
                                          //  Referenced by: '<S173>/Gain'

  real_T Saturation_UpperSat_lk;       // Expression: 1
                                          //  Referenced by: '<S173>/Saturation'

  real_T Saturation_LowerSat_l;        // Expression: 0
                                          //  Referenced by: '<S173>/Saturation'

  real_T Gain_Gain_b;                  // Expression: 0.01
                                          //  Referenced by: '<S174>/Gain'

  real_T Saturation_UpperSat_o;        // Expression: 1
                                          //  Referenced by: '<S174>/Saturation'

  real_T Saturation_LowerSat_o;        // Expression: 0
                                          //  Referenced by: '<S174>/Saturation'

  real_T Gain_Gain_o;                  // Expression: 0.01
                                          //  Referenced by: '<S175>/Gain'

  real_T Saturation_UpperSat_m;        // Expression: 1
                                          //  Referenced by: '<S175>/Saturation'

  real_T Saturation_LowerSat_m;        // Expression: 0
                                          //  Referenced by: '<S175>/Saturation'

  real32_T log_alt_Y0;                 // Computed Parameter: log_alt_Y0
                                          //  Referenced by: '<S1>/log_alt'

  real32_T vz_Y0;                      // Computed Parameter: vz_Y0
                                          //  Referenced by: '<S1>/vz'

  real32_T Constant1_Value_f;          // Computed Parameter: Constant1_Value_f
                                          //  Referenced by: '<S39>/Constant1'

  real32_T DeadZone4_Start;            // Computed Parameter: DeadZone4_Start
                                          //  Referenced by: '<S11>/Dead Zone4'

  real32_T DeadZone4_End;              // Computed Parameter: DeadZone4_End
                                          //  Referenced by: '<S11>/Dead Zone4'

  real32_T Saturation10_UpperSat;   // Computed Parameter: Saturation10_UpperSat
                                       //  Referenced by: '<S11>/Saturation10'

  real32_T Saturation10_LowerSat;   // Computed Parameter: Saturation10_LowerSat
                                       //  Referenced by: '<S11>/Saturation10'

  real32_T Gain_Gain_fo;               // Computed Parameter: Gain_Gain_fo
                                          //  Referenced by: '<S11>/Gain'

  real32_T Gain_Gain_n1;               // Computed Parameter: Gain_Gain_n1
                                          //  Referenced by: '<S12>/Gain'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S49>/Integrator'

  real32_T Filter_gainval;             // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S44>/Filter'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S12>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S12>/Saturation1'

  real32_T Clamping_zero_Value;       // Computed Parameter: Clamping_zero_Value
                                         //  Referenced by: '<S39>/Clamping_zero'

  real32_T DeadZone3_Start;            // Computed Parameter: DeadZone3_Start
                                          //  Referenced by: '<S11>/Dead Zone3'

  real32_T DeadZone3_End;              // Computed Parameter: DeadZone3_End
                                          //  Referenced by: '<S11>/Dead Zone3'

  real32_T Saturation9_UpperSat;     // Computed Parameter: Saturation9_UpperSat
                                        //  Referenced by: '<S11>/Saturation9'

  real32_T Saturation9_LowerSat;     // Computed Parameter: Saturation9_LowerSat
                                        //  Referenced by: '<S11>/Saturation9'

  real32_T DeadZone2_Start;            // Computed Parameter: DeadZone2_Start
                                          //  Referenced by: '<S11>/Dead Zone2'

  real32_T DeadZone2_End;              // Computed Parameter: DeadZone2_End
                                          //  Referenced by: '<S11>/Dead Zone2'

  real32_T Saturation3_UpperSat;     // Computed Parameter: Saturation3_UpperSat
                                        //  Referenced by: '<S11>/Saturation3'

  real32_T Saturation3_LowerSat;     // Computed Parameter: Saturation3_LowerSat
                                        //  Referenced by: '<S11>/Saturation3'

  real32_T DeadZone1_Start;            // Computed Parameter: DeadZone1_Start
                                          //  Referenced by: '<S11>/Dead Zone1'

  real32_T DeadZone1_End;              // Computed Parameter: DeadZone1_End
                                          //  Referenced by: '<S11>/Dead Zone1'

  real32_T Saturation1_UpperSat_b; // Computed Parameter: Saturation1_UpperSat_b
                                      //  Referenced by: '<S11>/Saturation1'

  real32_T Saturation1_LowerSat_d; // Computed Parameter: Saturation1_LowerSat_d
                                      //  Referenced by: '<S11>/Saturation1'

  real32_T Saturation_UpperSat_k;   // Computed Parameter: Saturation_UpperSat_k
                                       //  Referenced by: '<S9>/Saturation'

  real32_T Saturation_LowerSat_b;   // Computed Parameter: Saturation_LowerSat_b
                                       //  Referenced by: '<S9>/Saturation'

  real32_T Constant1_Value_k;          // Computed Parameter: Constant1_Value_k
                                          //  Referenced by: '<S9>/Constant1'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S9>/Gain2'

  real32_T Saturation1_UpperSat_i; // Computed Parameter: Saturation1_UpperSat_i
                                      //  Referenced by: '<S9>/Saturation1'

  real32_T Saturation1_LowerSat_c; // Computed Parameter: Saturation1_LowerSat_c
                                      //  Referenced by: '<S9>/Saturation1'

  real32_T Constant2_Value_b;          // Computed Parameter: Constant2_Value_b
                                          //  Referenced by: '<S9>/Constant2'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S9>/Gain1'

  real32_T Saturation2_UpperSat;     // Computed Parameter: Saturation2_UpperSat
                                        //  Referenced by: '<S9>/Saturation2'

  real32_T Saturation2_LowerSat;     // Computed Parameter: Saturation2_LowerSat
                                        //  Referenced by: '<S9>/Saturation2'

  real32_T Constant3_Value_h;          // Computed Parameter: Constant3_Value_h
                                          //  Referenced by: '<S9>/Constant3'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<S9>/Gain3'

  real32_T Saturation3_UpperSat_e; // Computed Parameter: Saturation3_UpperSat_e
                                      //  Referenced by: '<S9>/Saturation3'

  real32_T Saturation3_LowerSat_n; // Computed Parameter: Saturation3_LowerSat_n
                                      //  Referenced by: '<S9>/Saturation3'

  real32_T Constant1_Value_c;          // Computed Parameter: Constant1_Value_c
                                          //  Referenced by: '<S216>/Constant1'

  real32_T Constant1_Value_o;          // Computed Parameter: Constant1_Value_o
                                          //  Referenced by: '<S268>/Constant1'

  real32_T Constant1_Value_j;          // Computed Parameter: Constant1_Value_j
                                          //  Referenced by: '<S320>/Constant1'

  real32_T Merge1_InitialOutput;     // Computed Parameter: Merge1_InitialOutput
                                        //  Referenced by: '<Root>/Merge1'

  real32_T RateLimiter1_IC;            // Computed Parameter: RateLimiter1_IC
                                          //  Referenced by: '<S3>/Rate Limiter1'

  real32_T Saturation_LowerSat_k;   // Computed Parameter: Saturation_LowerSat_k
                                       //  Referenced by: '<S3>/Saturation'

  real32_T Integrator_gainval_h;     // Computed Parameter: Integrator_gainval_h
                                        //  Referenced by: '<S278>/Integrator'

  real32_T Filter_gainval_o;           // Computed Parameter: Filter_gainval_o
                                          //  Referenced by: '<S273>/Filter'

  real32_T RateLimiter2_IC;            // Computed Parameter: RateLimiter2_IC
                                          //  Referenced by: '<S3>/Rate Limiter2'

  real32_T Saturation1_LowerSat_cj;
                                  // Computed Parameter: Saturation1_LowerSat_cj
                                     //  Referenced by: '<S3>/Saturation1'

  real32_T Integrator_gainval_g;     // Computed Parameter: Integrator_gainval_g
                                        //  Referenced by: '<S226>/Integrator'

  real32_T Filter_gainval_h;           // Computed Parameter: Filter_gainval_h
                                          //  Referenced by: '<S221>/Filter'

  real32_T Integrator_gainval_a;     // Computed Parameter: Integrator_gainval_a
                                        //  Referenced by: '<S330>/Integrator'

  real32_T Filter_gainval_f;           // Computed Parameter: Filter_gainval_f
                                          //  Referenced by: '<S325>/Filter'

  real32_T Constant_Value_n;           // Computed Parameter: Constant_Value_n
                                          //  Referenced by: '<S170>/Constant'

  real32_T Constant_Value_i;           // Computed Parameter: Constant_Value_i
                                          //  Referenced by: '<S171>/Constant'

  real32_T Constant_Value_p;           // Computed Parameter: Constant_Value_p
                                          //  Referenced by: '<S172>/Constant'

  real32_T Constant_Value_e;           // Computed Parameter: Constant_Value_e
                                          //  Referenced by: '<S173>/Constant'

  real32_T Constant_Value_jb;          // Computed Parameter: Constant_Value_jb
                                          //  Referenced by: '<S174>/Constant'

  real32_T Constant_Value_ef;          // Computed Parameter: Constant_Value_ef
                                          //  Referenced by: '<S175>/Constant'

  real32_T Clamping_zero_Value_n;   // Computed Parameter: Clamping_zero_Value_n
                                       //  Referenced by: '<S320>/Clamping_zero'

  real32_T Clamping_zero_Value_j;   // Computed Parameter: Clamping_zero_Value_j
                                       //  Referenced by: '<S216>/Clamping_zero'

  real32_T Clamping_zero_Value_d;   // Computed Parameter: Clamping_zero_Value_d
                                       //  Referenced by: '<S268>/Clamping_zero'

  uint16_T Output_Limits1_UpperSat;
                                  // Computed Parameter: Output_Limits1_UpperSat
                                     //  Referenced by: '<S5>/Output_Limits1'

  uint16_T Output_Limits1_LowerSat;
                                  // Computed Parameter: Output_Limits1_LowerSat
                                     //  Referenced by: '<S5>/Output_Limits1'

  int8_T Constant_Value_ej;            // Computed Parameter: Constant_Value_ej
                                          //  Referenced by: '<S39>/Constant'

  int8_T Constant2_Value_d;            // Computed Parameter: Constant2_Value_d
                                          //  Referenced by: '<S39>/Constant2'

  int8_T Constant3_Value_p;            // Computed Parameter: Constant3_Value_p
                                          //  Referenced by: '<S39>/Constant3'

  int8_T Constant4_Value_f;            // Computed Parameter: Constant4_Value_f
                                          //  Referenced by: '<S39>/Constant4'

  int8_T Constant_Value_d;             // Computed Parameter: Constant_Value_d
                                          //  Referenced by: '<S216>/Constant'

  int8_T Constant2_Value_h;            // Computed Parameter: Constant2_Value_h
                                          //  Referenced by: '<S216>/Constant2'

  int8_T Constant3_Value_f;            // Computed Parameter: Constant3_Value_f
                                          //  Referenced by: '<S216>/Constant3'

  int8_T Constant4_Value_b;            // Computed Parameter: Constant4_Value_b
                                          //  Referenced by: '<S216>/Constant4'

  int8_T Constant_Value_h;             // Computed Parameter: Constant_Value_h
                                          //  Referenced by: '<S268>/Constant'

  int8_T Constant2_Value_g;            // Computed Parameter: Constant2_Value_g
                                          //  Referenced by: '<S268>/Constant2'

  int8_T Constant3_Value_l;            // Computed Parameter: Constant3_Value_l
                                          //  Referenced by: '<S268>/Constant3'

  int8_T Constant4_Value_n;            // Computed Parameter: Constant4_Value_n
                                          //  Referenced by: '<S268>/Constant4'

  int8_T Constant_Value_iw;            // Computed Parameter: Constant_Value_iw
                                          //  Referenced by: '<S320>/Constant'

  int8_T Constant2_Value_l;            // Computed Parameter: Constant2_Value_l
                                          //  Referenced by: '<S320>/Constant2'

  int8_T Constant3_Value_p2;           // Computed Parameter: Constant3_Value_p2
                                          //  Referenced by: '<S320>/Constant3'

  int8_T Constant4_Value_k;            // Computed Parameter: Constant4_Value_k
                                          //  Referenced by: '<S320>/Constant4'

};

// Real-time Model Data Structure
struct tag_RTM_FLIGHT_Hexacopter_fro_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_FLIGHT_Hexacopter_fromNCMS_T FLIGHT_Hexacopter_fromNCMS_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_FLIGHT_Hexacopter_fromNCMS_T FLIGHT_Hexacopter_fromNCMS_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_FLIGHT_Hexacopter_fromNCMS_T FLIGHT_Hexacopter_fromNCMS_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void FLIGHT_Hexacopter_fromNCMS_initialize(void);
  extern void FLIGHT_Hexacopter_fromNCMS_step(void);
  extern void FLIGHT_Hexacopter_fromNCMS_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_FLIGHT_Hexacopter_fr_T *const FLIGHT_Hexacopter_fromNCMS_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S11>/Display' : Unused code path elimination
//  Block '<S11>/Display1' : Unused code path elimination
//  Block '<S11>/Display2' : Unused code path elimination
//  Block '<S11>/Display3' : Unused code path elimination
//  Block '<S6>/Data Type Conversion' : Unused code path elimination
//  Block '<S180>/NOT' : Unused code path elimination
//  Block '<S178>/NOT' : Unused code path elimination
//  Block '<S183>/NOT' : Unused code path elimination
//  Block '<S179>/Signal Copy' : Unused code path elimination
//  Block '<S179>/Signal Copy1' : Unused code path elimination
//  Block '<S179>/Signal Copy2' : Unused code path elimination
//  Block '<S185>/Bitwise Operator' : Unused code path elimination
//  Block '<S185>/Data Type Conversion' : Unused code path elimination
//  Block '<S185>/Data Type Conversion1' : Unused code path elimination
//  Block '<S185>/Data Type Conversion2' : Unused code path elimination
//  Block '<S185>/Gain' : Unused code path elimination
//  Block '<S185>/Gain1' : Unused code path elimination
//  Block '<S186>/NOT' : Unused code path elimination
//  Block '<S8>/Gain1' : Unused code path elimination
//  Block '<S8>/Gain15' : Unused code path elimination
//  Block '<S8>/Gain2' : Unused code path elimination
//  Block '<S8>/Gain3' : Unused code path elimination
//  Block '<S8>/Gain4' : Unused code path elimination
//  Block '<S8>/Gain5' : Unused code path elimination
//  Block '<S8>/Gain6' : Unused code path elimination
//  Block '<S6>/Data Type Conversion9' : Eliminate redundant data type conversion


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
//  '<Root>' : 'FLIGHT_Hexacopter_fromNCMS'
//  '<S1>'   : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode'
//  '<S2>'   : 'FLIGHT_Hexacopter_fromNCMS/Arm'
//  '<S3>'   : 'FLIGHT_Hexacopter_fromNCMS/CAS'
//  '<S4>'   : 'FLIGHT_Hexacopter_fromNCMS/Fault_Injection'
//  '<S5>'   : 'FLIGHT_Hexacopter_fromNCMS/Mixer'
//  '<S6>'   : 'FLIGHT_Hexacopter_fromNCMS/Read uORB'
//  '<S7>'   : 'FLIGHT_Hexacopter_fromNCMS/Remote Control'
//  '<S8>'   : 'FLIGHT_Hexacopter_fromNCMS/SAS'
//  '<S9>'   : 'FLIGHT_Hexacopter_fromNCMS/Stabilized_Mode'
//  '<S10>'  : 'FLIGHT_Hexacopter_fromNCMS/quat2eul'
//  '<S11>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Altitude_Mode_Stick2Command'
//  '<S12>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller'
//  '<S13>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4'
//  '<S14>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Anti-windup'
//  '<S15>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/D Gain'
//  '<S16>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/External Derivative'
//  '<S17>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Filter'
//  '<S18>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Filter ICs'
//  '<S19>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/I Gain'
//  '<S20>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Ideal P Gain'
//  '<S21>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S22>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Integrator'
//  '<S23>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Integrator ICs'
//  '<S24>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/N Copy'
//  '<S25>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/N Gain'
//  '<S26>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/P Copy'
//  '<S27>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Parallel P Gain'
//  '<S28>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Reset Signal'
//  '<S29>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Saturation'
//  '<S30>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Saturation Fdbk'
//  '<S31>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Sum'
//  '<S32>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Sum Fdbk'
//  '<S33>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Tracking Mode'
//  '<S34>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Tracking Mode Sum'
//  '<S35>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Tsamp - Integral'
//  '<S36>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Tsamp - Ngain'
//  '<S37>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/postSat Signal'
//  '<S38>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/preSat Signal'
//  '<S39>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel'
//  '<S40>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S41>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S42>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/D Gain/Internal Parameters'
//  '<S43>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/External Derivative/Error'
//  '<S44>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Filter/Disc. Forward Euler Filter'
//  '<S45>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Filter ICs/Internal IC - Filter'
//  '<S46>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/I Gain/Internal Parameters'
//  '<S47>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S48>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S49>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Integrator/Discrete'
//  '<S50>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Integrator ICs/Internal IC'
//  '<S51>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/N Copy/Disabled'
//  '<S52>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/N Gain/Internal Parameters'
//  '<S53>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/P Copy/Disabled'
//  '<S54>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S55>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Reset Signal/Disabled'
//  '<S56>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Saturation/Enabled'
//  '<S57>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S58>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Sum/Sum_PID'
//  '<S59>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S60>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Tracking Mode/Disabled'
//  '<S61>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S62>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S63>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S64>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S65>'  : 'FLIGHT_Hexacopter_fromNCMS/Altitude_Mode/Vz Controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S66>'  : 'FLIGHT_Hexacopter_fromNCMS/Arm/Compare To Constant3'
//  '<S67>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3'
//  '<S68>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4'
//  '<S69>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Anti-windup'
//  '<S70>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/D Gain'
//  '<S71>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/External Derivative'
//  '<S72>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Filter'
//  '<S73>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Filter ICs'
//  '<S74>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/I Gain'
//  '<S75>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Ideal P Gain'
//  '<S76>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Ideal P Gain Fdbk'
//  '<S77>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Integrator'
//  '<S78>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Integrator ICs'
//  '<S79>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/N Copy'
//  '<S80>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/N Gain'
//  '<S81>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/P Copy'
//  '<S82>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Parallel P Gain'
//  '<S83>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Reset Signal'
//  '<S84>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Saturation'
//  '<S85>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Saturation Fdbk'
//  '<S86>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Sum'
//  '<S87>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Sum Fdbk'
//  '<S88>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Tracking Mode'
//  '<S89>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Tracking Mode Sum'
//  '<S90>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Tsamp - Integral'
//  '<S91>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Tsamp - Ngain'
//  '<S92>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/postSat Signal'
//  '<S93>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/preSat Signal'
//  '<S94>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Anti-windup/Disabled'
//  '<S95>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/D Gain/Disabled'
//  '<S96>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/External Derivative/Disabled'
//  '<S97>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Filter/Disabled'
//  '<S98>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Filter ICs/Disabled'
//  '<S99>'  : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/I Gain/Disabled'
//  '<S100>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Ideal P Gain/Passthrough'
//  '<S101>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S102>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Integrator/Disabled'
//  '<S103>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Integrator ICs/Disabled'
//  '<S104>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S105>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/N Gain/Disabled'
//  '<S106>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/P Copy/Disabled'
//  '<S107>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S108>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Reset Signal/Disabled'
//  '<S109>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Saturation/Enabled'
//  '<S110>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Saturation Fdbk/Disabled'
//  '<S111>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Sum/Passthrough_P'
//  '<S112>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Sum Fdbk/Disabled'
//  '<S113>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Tracking Mode/Disabled'
//  '<S114>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S115>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S116>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S117>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/postSat Signal/Forward_Path'
//  '<S118>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller3/preSat Signal/Forward_Path'
//  '<S119>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Anti-windup'
//  '<S120>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/D Gain'
//  '<S121>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/External Derivative'
//  '<S122>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Filter'
//  '<S123>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Filter ICs'
//  '<S124>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/I Gain'
//  '<S125>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Ideal P Gain'
//  '<S126>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Ideal P Gain Fdbk'
//  '<S127>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Integrator'
//  '<S128>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Integrator ICs'
//  '<S129>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/N Copy'
//  '<S130>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/N Gain'
//  '<S131>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/P Copy'
//  '<S132>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Parallel P Gain'
//  '<S133>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Reset Signal'
//  '<S134>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Saturation'
//  '<S135>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Saturation Fdbk'
//  '<S136>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Sum'
//  '<S137>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Sum Fdbk'
//  '<S138>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Tracking Mode'
//  '<S139>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Tracking Mode Sum'
//  '<S140>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Tsamp - Integral'
//  '<S141>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Tsamp - Ngain'
//  '<S142>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/postSat Signal'
//  '<S143>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/preSat Signal'
//  '<S144>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Anti-windup/Disabled'
//  '<S145>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/D Gain/Disabled'
//  '<S146>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/External Derivative/Disabled'
//  '<S147>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Filter/Disabled'
//  '<S148>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Filter ICs/Disabled'
//  '<S149>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/I Gain/Disabled'
//  '<S150>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Ideal P Gain/Passthrough'
//  '<S151>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S152>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Integrator/Disabled'
//  '<S153>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Integrator ICs/Disabled'
//  '<S154>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S155>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/N Gain/Disabled'
//  '<S156>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/P Copy/Disabled'
//  '<S157>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S158>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Reset Signal/Disabled'
//  '<S159>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Saturation/Enabled'
//  '<S160>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Saturation Fdbk/Disabled'
//  '<S161>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Sum/Passthrough_P'
//  '<S162>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Sum Fdbk/Disabled'
//  '<S163>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Tracking Mode/Disabled'
//  '<S164>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S165>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S166>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S167>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/postSat Signal/Forward_Path'
//  '<S168>' : 'FLIGHT_Hexacopter_fromNCMS/CAS/PID Controller4/preSat Signal/Forward_Path'
//  '<S169>' : 'FLIGHT_Hexacopter_fromNCMS/Fault_Injection/Compare To Constant'
//  '<S170>' : 'FLIGHT_Hexacopter_fromNCMS/Fault_Injection/Subsystem Reference'
//  '<S171>' : 'FLIGHT_Hexacopter_fromNCMS/Fault_Injection/Subsystem Reference1'
//  '<S172>' : 'FLIGHT_Hexacopter_fromNCMS/Fault_Injection/Subsystem Reference2'
//  '<S173>' : 'FLIGHT_Hexacopter_fromNCMS/Fault_Injection/Subsystem Reference3'
//  '<S174>' : 'FLIGHT_Hexacopter_fromNCMS/Fault_Injection/Subsystem Reference4'
//  '<S175>' : 'FLIGHT_Hexacopter_fromNCMS/Fault_Injection/Subsystem Reference5'
//  '<S176>' : 'FLIGHT_Hexacopter_fromNCMS/Mixer/pwm_out2'
//  '<S177>' : 'FLIGHT_Hexacopter_fromNCMS/Read uORB/Gyroscope'
//  '<S178>' : 'FLIGHT_Hexacopter_fromNCMS/Read uORB/PX4 uORB Read'
//  '<S179>' : 'FLIGHT_Hexacopter_fromNCMS/Read uORB/Vehicle Attitude'
//  '<S180>' : 'FLIGHT_Hexacopter_fromNCMS/Read uORB/Gyroscope/PX4 uORB Read'
//  '<S181>' : 'FLIGHT_Hexacopter_fromNCMS/Read uORB/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S182>' : 'FLIGHT_Hexacopter_fromNCMS/Read uORB/PX4 uORB Read/Enabled Subsystem'
//  '<S183>' : 'FLIGHT_Hexacopter_fromNCMS/Read uORB/Vehicle Attitude/PX4 uORB Read'
//  '<S184>' : 'FLIGHT_Hexacopter_fromNCMS/Read uORB/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'
//  '<S185>' : 'FLIGHT_Hexacopter_fromNCMS/Remote Control/Radio Control Transmitter'
//  '<S186>' : 'FLIGHT_Hexacopter_fromNCMS/Remote Control/Radio Control Transmitter/PX4 uORB Read'
//  '<S187>' : 'FLIGHT_Hexacopter_fromNCMS/Remote Control/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S188>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1'
//  '<S189>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2'
//  '<S190>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6'
//  '<S191>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Anti-windup'
//  '<S192>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/D Gain'
//  '<S193>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/External Derivative'
//  '<S194>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Filter'
//  '<S195>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Filter ICs'
//  '<S196>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/I Gain'
//  '<S197>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Ideal P Gain'
//  '<S198>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Ideal P Gain Fdbk'
//  '<S199>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Integrator'
//  '<S200>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Integrator ICs'
//  '<S201>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/N Copy'
//  '<S202>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/N Gain'
//  '<S203>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/P Copy'
//  '<S204>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Parallel P Gain'
//  '<S205>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Reset Signal'
//  '<S206>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Saturation'
//  '<S207>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Saturation Fdbk'
//  '<S208>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Sum'
//  '<S209>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Sum Fdbk'
//  '<S210>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Tracking Mode'
//  '<S211>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Tracking Mode Sum'
//  '<S212>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Tsamp - Integral'
//  '<S213>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Tsamp - Ngain'
//  '<S214>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/postSat Signal'
//  '<S215>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/preSat Signal'
//  '<S216>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S217>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S218>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S219>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/D Gain/Internal Parameters'
//  '<S220>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/External Derivative/Error'
//  '<S221>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S222>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S223>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/I Gain/Internal Parameters'
//  '<S224>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Ideal P Gain/Passthrough'
//  '<S225>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S226>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Integrator/Discrete'
//  '<S227>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Integrator ICs/Internal IC'
//  '<S228>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/N Copy/Disabled'
//  '<S229>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/N Gain/Internal Parameters'
//  '<S230>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/P Copy/Disabled'
//  '<S231>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S232>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Reset Signal/Disabled'
//  '<S233>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Saturation/Enabled'
//  '<S234>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Saturation Fdbk/Disabled'
//  '<S235>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Sum/Sum_PID'
//  '<S236>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Sum Fdbk/Disabled'
//  '<S237>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Tracking Mode/Disabled'
//  '<S238>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S239>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S240>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S241>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/postSat Signal/Forward_Path'
//  '<S242>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller1/preSat Signal/Forward_Path'
//  '<S243>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Anti-windup'
//  '<S244>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/D Gain'
//  '<S245>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/External Derivative'
//  '<S246>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Filter'
//  '<S247>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Filter ICs'
//  '<S248>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/I Gain'
//  '<S249>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Ideal P Gain'
//  '<S250>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Ideal P Gain Fdbk'
//  '<S251>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Integrator'
//  '<S252>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Integrator ICs'
//  '<S253>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/N Copy'
//  '<S254>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/N Gain'
//  '<S255>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/P Copy'
//  '<S256>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Parallel P Gain'
//  '<S257>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Reset Signal'
//  '<S258>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Saturation'
//  '<S259>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Saturation Fdbk'
//  '<S260>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Sum'
//  '<S261>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Sum Fdbk'
//  '<S262>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Tracking Mode'
//  '<S263>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Tracking Mode Sum'
//  '<S264>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Tsamp - Integral'
//  '<S265>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Tsamp - Ngain'
//  '<S266>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/postSat Signal'
//  '<S267>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/preSat Signal'
//  '<S268>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S269>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S270>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S271>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/D Gain/Internal Parameters'
//  '<S272>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/External Derivative/Error'
//  '<S273>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S274>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S275>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/I Gain/Internal Parameters'
//  '<S276>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Ideal P Gain/Passthrough'
//  '<S277>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S278>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Integrator/Discrete'
//  '<S279>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Integrator ICs/Internal IC'
//  '<S280>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/N Copy/Disabled'
//  '<S281>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/N Gain/Internal Parameters'
//  '<S282>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/P Copy/Disabled'
//  '<S283>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S284>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Reset Signal/Disabled'
//  '<S285>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Saturation/Enabled'
//  '<S286>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Saturation Fdbk/Disabled'
//  '<S287>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Sum/Sum_PID'
//  '<S288>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Sum Fdbk/Disabled'
//  '<S289>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Tracking Mode/Disabled'
//  '<S290>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S291>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S292>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S293>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/postSat Signal/Forward_Path'
//  '<S294>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller2/preSat Signal/Forward_Path'
//  '<S295>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Anti-windup'
//  '<S296>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/D Gain'
//  '<S297>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/External Derivative'
//  '<S298>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Filter'
//  '<S299>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Filter ICs'
//  '<S300>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/I Gain'
//  '<S301>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Ideal P Gain'
//  '<S302>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Ideal P Gain Fdbk'
//  '<S303>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Integrator'
//  '<S304>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Integrator ICs'
//  '<S305>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/N Copy'
//  '<S306>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/N Gain'
//  '<S307>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/P Copy'
//  '<S308>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Parallel P Gain'
//  '<S309>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Reset Signal'
//  '<S310>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Saturation'
//  '<S311>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Saturation Fdbk'
//  '<S312>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Sum'
//  '<S313>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Sum Fdbk'
//  '<S314>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Tracking Mode'
//  '<S315>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Tracking Mode Sum'
//  '<S316>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Tsamp - Integral'
//  '<S317>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Tsamp - Ngain'
//  '<S318>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/postSat Signal'
//  '<S319>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/preSat Signal'
//  '<S320>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Anti-windup/Disc. Clamping Parallel'
//  '<S321>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S322>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S323>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/D Gain/Internal Parameters'
//  '<S324>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/External Derivative/Error'
//  '<S325>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Filter/Disc. Forward Euler Filter'
//  '<S326>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Filter ICs/Internal IC - Filter'
//  '<S327>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/I Gain/Internal Parameters'
//  '<S328>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Ideal P Gain/Passthrough'
//  '<S329>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Ideal P Gain Fdbk/Disabled'
//  '<S330>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Integrator/Discrete'
//  '<S331>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Integrator ICs/Internal IC'
//  '<S332>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/N Copy/Disabled'
//  '<S333>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/N Gain/Internal Parameters'
//  '<S334>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/P Copy/Disabled'
//  '<S335>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Parallel P Gain/Internal Parameters'
//  '<S336>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Reset Signal/Disabled'
//  '<S337>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Saturation/Enabled'
//  '<S338>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Saturation Fdbk/Disabled'
//  '<S339>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Sum/Sum_PID'
//  '<S340>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Sum Fdbk/Disabled'
//  '<S341>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Tracking Mode/Disabled'
//  '<S342>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Tracking Mode Sum/Passthrough'
//  '<S343>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Tsamp - Integral/TsSignalSpecification'
//  '<S344>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/Tsamp - Ngain/Passthrough'
//  '<S345>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/postSat Signal/Forward_Path'
//  '<S346>' : 'FLIGHT_Hexacopter_fromNCMS/SAS/PID Controller6/preSat Signal/Forward_Path'

#endif                                 // FLIGHT_Hexacopter_fromNCMS_h_

//
// File trailer for generated code.
//
// [EOF]
//
