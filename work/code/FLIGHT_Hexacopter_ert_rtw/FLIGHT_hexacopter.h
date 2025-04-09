//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_hexacopter.h
//
// Code generated for Simulink model 'FLIGHT_hexacopter'.
//
// Model version                  : 1.96
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Apr  9 15:25:53 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef FLIGHT_hexacopter_h_
#define FLIGHT_hexacopter_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "FLIGHT_hexacopter_types.h"
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/vehicle_local_position_setpoint.h>
#include <uORB/topics/vehicle_attitude_setpoint.h>
#include <uORB/topics/sensor_gyro.h>
#include <uORB/topics/vehicle_rates_setpoint.h>
#include <uORB/topics/vehicle_torque_setpoint.h>

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

// Block signals for system '<S18>/Read Parameter'
struct B_ReadParameter_FLIGHT_hexaco_T {
  real32_T ReadParameter_o1;           // '<S18>/Read Parameter'
};

// Block states (default storage) for system '<S18>/Read Parameter'
struct DW_ReadParameter_FLIGHT_hexac_T {
  px4_internal_block_ParameterU_T obj; // '<S18>/Read Parameter'
  boolean_T objisempty;                // '<S18>/Read Parameter'
};

// Block signals for system '<S18>/Read Parameter1'
struct B_ReadParameter1_FLIGHT_hexac_T {
  real32_T ReadParameter1_o1;          // '<S18>/Read Parameter1'
};

// Block states (default storage) for system '<S18>/Read Parameter1'
struct DW_ReadParameter1_FLIGHT_hexa_T {
  px4_internal_block_ParameterU_T obj; // '<S18>/Read Parameter1'
  boolean_T objisempty;                // '<S18>/Read Parameter1'
};

// Block signals for system '<S18>/Read Parameter2'
struct B_ReadParameter2_FLIGHT_hexac_T {
  real32_T ReadParameter2_o1;          // '<S18>/Read Parameter2'
};

// Block states (default storage) for system '<S18>/Read Parameter2'
struct DW_ReadParameter2_FLIGHT_hexa_T {
  px4_internal_block_ParameterU_T obj; // '<S18>/Read Parameter2'
  boolean_T objisempty;                // '<S18>/Read Parameter2'
};

// Block signals for system '<S18>/Read Parameter3'
struct B_ReadParameter3_FLIGHT_hexac_T {
  real32_T ReadParameter3_o1;          // '<S18>/Read Parameter3'
};

// Block states (default storage) for system '<S18>/Read Parameter3'
struct DW_ReadParameter3_FLIGHT_hexa_T {
  px4_internal_block_ParameterU_T obj; // '<S18>/Read Parameter3'
  boolean_T objisempty;                // '<S18>/Read Parameter3'
};

// Block signals for system '<S12>/PX4 Timestamp'
struct B_PX4Timestamp_FLIGHT_hexacop_T {
  uint64_T PX4Timestamp;               // '<S12>/PX4 Timestamp'
};

// Block states (default storage) for system '<S12>/PX4 Timestamp'
struct DW_PX4Timestamp_FLIGHT_hexaco_T {
  px4_internal_block_getPX4Abso_T obj; // '<S12>/PX4 Timestamp'
  boolean_T objisempty;                // '<S12>/PX4 Timestamp'
};

// Block signals (default storage)
struct B_FLIGHT_hexacopter_T {
  px4_Bus_vehicle_local_position In1;  // '<S401>/In1'
  px4_Bus_vehicle_local_position r;
  px4_Bus_vehicle_odometry In1_k;      // '<S403>/In1'
  px4_Bus_vehicle_odometry r1;
  px4_Bus_actuator_outputs BusAssignment;// '<S12>/Bus Assignment'
  px4_Bus_input_rc In1_n;              // '<S406>/In1'
  px4_Bus_input_rc r2;
  px4_Bus_vehicle_local_position_setpoint BusAssignment_g;// '<S14>/Bus Assignment' 
  px4_Bus_vehicle_attitude_setpoint BusAssignment_d;// '<S13>/Bus Assignment'
  px4_Bus_sensor_gyro In1_e;           // '<S400>/In1'
  px4_Bus_sensor_gyro r3;
  px4_Bus_vehicle_rates_setpoint BusAssignment_e;// '<S15>/Bus Assignment'
  px4_Bus_vehicle_torque_setpoint BusAssignment_n;// '<S16>/Bus Assignment'
  uint16_T pwmValue[8];
  real32_T Merge1[4];                  // '<Root>/Merge1'
  uint16_T Output_Limits1[6];          // '<S6>/Output_Limits1'
  uint16_T DataTypeConversion6[6];     // '<S4>/Data Type Conversion6'
  uint16_T DataTypeConversion7[6];     // '<S4>/Data Type Conversion7'
  real_T Add1;                         // '<S561>/Add1'
  uint64_T rtb_PX4Timestamp_m;
  real32_T Merge;                      // '<Root>/Merge'
  real32_T DataTypeConversion;         // '<S561>/Data Type Conversion'
  real32_T PProdOut[2];                // '<S330>/PProd Out'
  real32_T OutportBufferFordes_xy[2];  // '<S5>/Constant'
  real32_T Add;                        // '<S5>/Add'
  real32_T ParamStep;
  real32_T ParamStep_c;
  real32_T Filter_a;                   // '<S269>/Filter'
  real32_T Integrator_m;               // '<S274>/Integrator'
  real32_T Saturation3;                // '<S10>/Saturation3'
  real32_T PProdOut_i;                 // '<S163>/PProd Out'
  real32_T DeadZone;                   // '<S266>/DeadZone'
  real32_T Sum_c;                      // '<S502>/Sum'
  real32_T PProdOut_h;                 // '<S113>/PProd Out'
  int32_T ParamStep_k;
  int32_T ParamStep_cx;
  int32_T ParamStep_b;
  int32_T ParamStep_p;
  int32_T ParamStep_cv;
  B_PX4Timestamp_FLIGHT_hexacop_T PX4Timestamp_pna;// '<S12>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexacop_T PX4Timestamp_p;// '<S12>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexacop_T PX4Timestamp;// '<S12>/PX4 Timestamp'
  B_ReadParameter3_FLIGHT_hexac_T ReadParameter3_pna;// '<S18>/Read Parameter3'
  B_ReadParameter2_FLIGHT_hexac_T ReadParameter2_pna;// '<S18>/Read Parameter2'
  B_ReadParameter1_FLIGHT_hexac_T ReadParameter1_pnaev;// '<S18>/Read Parameter1' 
  B_ReadParameter_FLIGHT_hexaco_T ReadParameter_pna;// '<S18>/Read Parameter'
  B_ReadParameter3_FLIGHT_hexac_T ReadParameter3_pn;// '<S18>/Read Parameter3'
  B_ReadParameter2_FLIGHT_hexac_T ReadParameter2_pn;// '<S18>/Read Parameter2'
  B_ReadParameter1_FLIGHT_hexac_T ReadParameter1_pna;// '<S18>/Read Parameter1'
  B_ReadParameter_FLIGHT_hexaco_T ReadParameter_pn;// '<S18>/Read Parameter'
};

// Block states (default storage) for system '<Root>'
struct DW_FLIGHT_hexacopter_T {
  px4_internal_block_ParameterU_T obj; // '<S9>/Read Parameter8'
  px4_internal_block_ParameterU_T obj_j;// '<S9>/Read Parameter7'
  px4_internal_block_ParameterU_T obj_a;// '<S9>/Read Parameter6'
  px4_internal_block_ParameterU_T obj_h;// '<S9>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_p;// '<S9>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_b;// '<S9>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_d;// '<S9>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_e;// '<S9>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_i;// '<S9>/Read Parameter'
  px4_internal_block_ParameterU_T obj_pi;// '<S186>/Read Parameter'
  px4_internal_block_ParameterU_T obj_eq;// '<S185>/Read Parameter'
  px4_internal_block_ParameterU_T obj_m;// '<S182>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_aq;// '<S4>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_c;// '<S4>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_n;// '<S4>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_ao;// '<S4>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_g;// '<S4>/Read Parameter13'
  px4_internal_block_ParameterU_T obj_j5;// '<S4>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_o;// '<S3>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_jz;// '<S3>/Read Parameter'
  px4_internal_block_Subscriber_T obj_p2;// '<S405>/SourceBlock'
  px4_internal_block_Subscriber_T obj_ab;// '<S402>/SourceBlock'
  px4_internal_block_Subscriber_T obj_k;// '<S397>/SourceBlock'
  px4_internal_block_Subscriber_T obj_l;// '<S399>/SourceBlock'
  px4_internal_block_getPX4Abso_T obj_ky;// '<S14>/PX4 Timestamp'
  px4_internal_block_PWM_FLIGHT_T obj_dl;// '<Root>/PX4 PWM Output'
  px4_internal_block_Publisher__T obj_my;// '<S572>/SinkBlock'
  px4_internal_block_Publisher__T obj_a4;// '<S570>/SinkBlock'
  px4_internal_block_Publisher__T obj_pa;// '<S568>/SinkBlock'
  px4_internal_block_Publisher__T obj_pt;// '<S565>/SinkBlock'
  px4_internal_block_Publisher__T obj_jj;// '<S563>/SinkBlock'
  real32_T Integrator_DSTATE;          // '<S493>/Integrator'
  real32_T Filter_DSTATE;              // '<S488>/Filter'
  real32_T Integrator_DSTATE_c;        // '<S443>/Integrator'
  real32_T Filter_DSTATE_j;            // '<S438>/Filter'
  real32_T Integrator_DSTATE_l;        // '<S543>/Integrator'
  real32_T Filter_DSTATE_h;            // '<S538>/Filter'
  real32_T Integrator_DSTATE_k;        // '<S274>/Integrator'
  real32_T Filter_DSTATE_g;            // '<S269>/Filter'
  real32_T Integrator_DSTATE_e;        // '<S55>/Integrator'
  real32_T Filter_DSTATE_i;            // '<S50>/Filter'
  int32_T clockTickCounter;            // '<S561>/Discrete Pulse Generator'
  int8_T Integrator_PrevResetState;    // '<S274>/Integrator'
  int8_T Filter_PrevResetState;        // '<S269>/Filter'
  DW_PX4Timestamp_FLIGHT_hexaco_T PX4Timestamp_pna;// '<S12>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexaco_T PX4Timestamp_p;// '<S12>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexaco_T PX4Timestamp;// '<S12>/PX4 Timestamp'
  DW_ReadParameter3_FLIGHT_hexa_T ReadParameter3_pna;// '<S18>/Read Parameter3'
  DW_ReadParameter2_FLIGHT_hexa_T ReadParameter2_pna;// '<S18>/Read Parameter2'
  DW_ReadParameter1_FLIGHT_hexa_T ReadParameter1_pnaev;// '<S18>/Read Parameter1' 
  DW_ReadParameter_FLIGHT_hexac_T ReadParameter_pna;// '<S18>/Read Parameter'
  DW_ReadParameter3_FLIGHT_hexa_T ReadParameter3_pn;// '<S18>/Read Parameter3'
  DW_ReadParameter2_FLIGHT_hexa_T ReadParameter2_pn;// '<S18>/Read Parameter2'
  DW_ReadParameter1_FLIGHT_hexa_T ReadParameter1_pna;// '<S18>/Read Parameter1'
  DW_ReadParameter_FLIGHT_hexac_T ReadParameter_pn;// '<S18>/Read Parameter'
};

// Parameters (default storage)
struct P_FLIGHT_hexacopter_T_ {
  real_T SampleTime;                   // Variable: SampleTime
                                          //  Referenced by:
                                          //    '<S3>/Read Parameter'
                                          //    '<S3>/Read Parameter1'
                                          //    '<S9>/Read Parameter'
                                          //    '<S9>/Read Parameter1'
                                          //    '<S9>/Read Parameter2'
                                          //    '<S9>/Read Parameter3'
                                          //    '<S9>/Read Parameter4'
                                          //    '<S9>/Read Parameter5'
                                          //    '<S9>/Read Parameter6'
                                          //    '<S9>/Read Parameter7'
                                          //    '<S9>/Read Parameter8'
                                          //    '<S18>/Read Parameter'
                                          //    '<S18>/Read Parameter1'
                                          //    '<S18>/Read Parameter2'
                                          //    '<S18>/Read Parameter3'
                                          //    '<S182>/Read Parameter1'
                                          //    '<S184>/Read Parameter'
                                          //    '<S184>/Read Parameter1'
                                          //    '<S184>/Read Parameter2'
                                          //    '<S184>/Read Parameter3'
                                          //    '<S185>/Read Parameter'
                                          //    '<S186>/Read Parameter'

  real_T d2r;                          // Variable: d2r
                                          //  Referenced by:
                                          //    '<S561>/Constant'
                                          //    '<S561>/Discrete Pulse Generator'

  real32_T MAX_CONTROL_ANGLE_PITCH;    // Variable: MAX_CONTROL_ANGLE_PITCH
                                          //  Referenced by:
                                          //    '<S10>/Gain5'
                                          //    '<S17>/Gain2'

  real32_T MAX_CONTROL_ANGLE_RATE_Y;   // Variable: MAX_CONTROL_ANGLE_RATE_Y
                                          //  Referenced by:
                                          //    '<S10>/Gain6'
                                          //    '<S17>/Gain3'
                                          //    '<S183>/Gain3'

  real32_T MAX_CONTROL_ANGLE_ROLL;     // Variable: MAX_CONTROL_ANGLE_ROLL
                                          //  Referenced by:
                                          //    '<S10>/Gain4'
                                          //    '<S17>/Gain1'

  real32_T PIDController4_InitialCondition;
                              // Mask Parameter: PIDController4_InitialCondition
                                 //  Referenced by: '<S50>/Filter'

  real32_T PIDController4_InitialConditi_l;
                              // Mask Parameter: PIDController4_InitialConditi_l
                                 //  Referenced by: '<S269>/Filter'

  real32_T PIDController2_InitialCondition;
                              // Mask Parameter: PIDController2_InitialCondition
                                 //  Referenced by: '<S488>/Filter'

  real32_T PIDController1_InitialCondition;
                              // Mask Parameter: PIDController1_InitialCondition
                                 //  Referenced by: '<S438>/Filter'

  real32_T PIDController6_InitialCondition;
                              // Mask Parameter: PIDController6_InitialCondition
                                 //  Referenced by: '<S538>/Filter'

  real32_T PIDController4_InitialConditi_a;
                              // Mask Parameter: PIDController4_InitialConditi_a
                                 //  Referenced by: '<S55>/Integrator'

  real32_T PIDController4_InitialConditi_i;
                              // Mask Parameter: PIDController4_InitialConditi_i
                                 //  Referenced by: '<S274>/Integrator'

  real32_T PIDController2_InitialConditi_c;
                              // Mask Parameter: PIDController2_InitialConditi_c
                                 //  Referenced by: '<S493>/Integrator'

  real32_T PIDController1_InitialConditi_c;
                              // Mask Parameter: PIDController1_InitialConditi_c
                                 //  Referenced by: '<S443>/Integrator'

  real32_T PIDController6_InitialConditi_h;
                              // Mask Parameter: PIDController6_InitialConditi_h
                                 //  Referenced by: '<S543>/Integrator'

  real32_T PIDController4_LowerSaturationL;
                              // Mask Parameter: PIDController4_LowerSaturationL
                                 //  Referenced by:
                                 //    '<S62>/Saturation'
                                 //    '<S47>/DeadZone'

  real32_T PIDController4_LowerSaturatio_a;
                              // Mask Parameter: PIDController4_LowerSaturatio_a
                                 //  Referenced by: '<S228>/Saturation'

  real32_T PIDController4_LowerSaturatio_f;
                              // Mask Parameter: PIDController4_LowerSaturatio_f
                                 //  Referenced by:
                                 //    '<S281>/Saturation'
                                 //    '<S266>/DeadZone'

  real32_T PIDController4_UpperSaturationL;
                              // Mask Parameter: PIDController4_UpperSaturationL
                                 //  Referenced by:
                                 //    '<S62>/Saturation'
                                 //    '<S47>/DeadZone'

  real32_T PIDController4_UpperSaturatio_h;
                              // Mask Parameter: PIDController4_UpperSaturatio_h
                                 //  Referenced by: '<S228>/Saturation'

  real32_T PIDController4_UpperSaturati_hy;
                              // Mask Parameter: PIDController4_UpperSaturati_hy
                                 //  Referenced by:
                                 //    '<S281>/Saturation'
                                 //    '<S266>/DeadZone'

  uint16_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S560>/Constant'

  uint16_T CompareToConstant_const_g;
                                    // Mask Parameter: CompareToConstant_const_g
                                       //  Referenced by: '<S175>/Constant'

  uint16_T CompareToConstant3_const; // Mask Parameter: CompareToConstant3_const
                                        //  Referenced by: '<S72>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0;// Computed Parameter: Out1_Y0
                                            //  Referenced by: '<S401>/Out1'

  px4_Bus_vehicle_local_position Constant_Value;// Computed Parameter: Constant_Value
                                                   //  Referenced by: '<S397>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0_d;  // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S403>/Out1'

  px4_Bus_vehicle_odometry Constant_Value_g;// Computed Parameter: Constant_Value_g
                                               //  Referenced by: '<S402>/Constant'

  px4_Bus_actuator_outputs Constant_Value_b;// Computed Parameter: Constant_Value_b
                                               //  Referenced by: '<S562>/Constant'

  px4_Bus_input_rc Out1_Y0_p;          // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S406>/Out1'

  px4_Bus_input_rc Constant_Value_bd;  // Computed Parameter: Constant_Value_bd
                                          //  Referenced by: '<S405>/Constant'

  px4_Bus_vehicle_local_position_setpoint Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                              //  Referenced by: '<S567>/Constant'

  px4_Bus_vehicle_attitude_setpoint Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                        //  Referenced by: '<S564>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_n;       // Computed Parameter: Out1_Y0_n
                                          //  Referenced by: '<S400>/Out1'

  px4_Bus_sensor_gyro Constant_Value_k;// Computed Parameter: Constant_Value_k
                                          //  Referenced by: '<S399>/Constant'

  px4_Bus_vehicle_rates_setpoint Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                     //  Referenced by: '<S569>/Constant'

  px4_Bus_vehicle_torque_setpoint Constant_Value_n1;// Computed Parameter: Constant_Value_n1
                                                       //  Referenced by: '<S571>/Constant'

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

  real_T Constant_Value_m;             // Expression: 100
                                          //  Referenced by: '<S4>/Constant'

  real_T DiscretePulseGenerator_Period;
                            // Computed Parameter: DiscretePulseGenerator_Period
                               //  Referenced by: '<S561>/Discrete Pulse Generator'

  real_T DiscretePulseGenerator_Duty;
                              // Computed Parameter: DiscretePulseGenerator_Duty
                                 //  Referenced by: '<S561>/Discrete Pulse Generator'

  real_T DiscretePulseGenerator_PhaseDel;// Expression: 0
                                            //  Referenced by: '<S561>/Discrete Pulse Generator'

  real_T Constant_Value_c;             // Expression: 1094
                                          //  Referenced by: '<S10>/Constant'

  real_T Gain_Gain;                    // Expression: 1/800
                                          //  Referenced by: '<S10>/Gain'

  real_T Gain_Gain_j;                  // Expression: 0.01
                                          //  Referenced by: '<S176>/Gain'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<S176>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S176>/Saturation'

  real_T Gain_Gain_h;                  // Expression: 0.01
                                          //  Referenced by: '<S177>/Gain'

  real_T Saturation_UpperSat_m;        // Expression: 1
                                          //  Referenced by: '<S177>/Saturation'

  real_T Saturation_LowerSat_o;        // Expression: 0
                                          //  Referenced by: '<S177>/Saturation'

  real_T Gain_Gain_c;                  // Expression: 0.01
                                          //  Referenced by: '<S178>/Gain'

  real_T Saturation_UpperSat_b;        // Expression: 1
                                          //  Referenced by: '<S178>/Saturation'

  real_T Saturation_LowerSat_g;        // Expression: 0
                                          //  Referenced by: '<S178>/Saturation'

  real_T Gain_Gain_n;                  // Expression: 0.01
                                          //  Referenced by: '<S179>/Gain'

  real_T Saturation_UpperSat_be;       // Expression: 1
                                          //  Referenced by: '<S179>/Saturation'

  real_T Saturation_LowerSat_e;        // Expression: 0
                                          //  Referenced by: '<S179>/Saturation'

  real_T Gain_Gain_f;                  // Expression: 0.01
                                          //  Referenced by: '<S180>/Gain'

  real_T Saturation_UpperSat_d;        // Expression: 1
                                          //  Referenced by: '<S180>/Saturation'

  real_T Saturation_LowerSat_l;        // Expression: 0
                                          //  Referenced by: '<S180>/Saturation'

  real_T Gain_Gain_m;                  // Expression: 0.01
                                          //  Referenced by: '<S181>/Gain'

  real_T Saturation_UpperSat_i;        // Expression: 1
                                          //  Referenced by: '<S181>/Saturation'

  real_T Saturation_LowerSat_n;        // Expression: 0
                                          //  Referenced by: '<S181>/Saturation'

  real32_T Constant1_Value_n;          // Computed Parameter: Constant1_Value_n
                                          //  Referenced by: '<S45>/Constant1'

  real32_T DeadZone3_Start;            // Computed Parameter: DeadZone3_Start
                                          //  Referenced by: '<S17>/Dead Zone3'

  real32_T DeadZone3_End;              // Computed Parameter: DeadZone3_End
                                          //  Referenced by: '<S17>/Dead Zone3'

  real32_T Saturation9_UpperSat;     // Computed Parameter: Saturation9_UpperSat
                                        //  Referenced by: '<S17>/Saturation9'

  real32_T Saturation9_LowerSat;     // Computed Parameter: Saturation9_LowerSat
                                        //  Referenced by: '<S17>/Saturation9'

  real32_T DeadZone4_Start;            // Computed Parameter: DeadZone4_Start
                                          //  Referenced by: '<S17>/Dead Zone4'

  real32_T DeadZone4_End;              // Computed Parameter: DeadZone4_End
                                          //  Referenced by: '<S17>/Dead Zone4'

  real32_T Saturation10_UpperSat;   // Computed Parameter: Saturation10_UpperSat
                                       //  Referenced by: '<S17>/Saturation10'

  real32_T Saturation10_LowerSat;   // Computed Parameter: Saturation10_LowerSat
                                       //  Referenced by: '<S17>/Saturation10'

  real32_T Gain_Gain_e;                // Computed Parameter: Gain_Gain_e
                                          //  Referenced by: '<S17>/Gain'

  real32_T Gain_Gain_d;                // Computed Parameter: Gain_Gain_d
                                          //  Referenced by: '<S18>/Gain'

  real32_T Clamping_zero_Value;       // Computed Parameter: Clamping_zero_Value
                                         //  Referenced by: '<S45>/Clamping_zero'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S55>/Integrator'

  real32_T Constant_Value_bi;          // Computed Parameter: Constant_Value_bi
                                          //  Referenced by: '<S18>/Constant'

  real32_T Filter_gainval;             // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S50>/Filter'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S18>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S18>/Saturation1'

  real32_T DeadZone2_Start;            // Computed Parameter: DeadZone2_Start
                                          //  Referenced by: '<S17>/Dead Zone2'

  real32_T DeadZone2_End;              // Computed Parameter: DeadZone2_End
                                          //  Referenced by: '<S17>/Dead Zone2'

  real32_T Saturation3_UpperSat;     // Computed Parameter: Saturation3_UpperSat
                                        //  Referenced by: '<S17>/Saturation3'

  real32_T Saturation3_LowerSat;     // Computed Parameter: Saturation3_LowerSat
                                        //  Referenced by: '<S17>/Saturation3'

  real32_T DeadZone1_Start;            // Computed Parameter: DeadZone1_Start
                                          //  Referenced by: '<S17>/Dead Zone1'

  real32_T DeadZone1_End;              // Computed Parameter: DeadZone1_End
                                          //  Referenced by: '<S17>/Dead Zone1'

  real32_T Saturation1_UpperSat_d; // Computed Parameter: Saturation1_UpperSat_d
                                      //  Referenced by: '<S17>/Saturation1'

  real32_T Saturation1_LowerSat_b; // Computed Parameter: Saturation1_LowerSat_b
                                      //  Referenced by: '<S17>/Saturation1'

  real32_T des_z_Y0;                   // Computed Parameter: des_z_Y0
                                          //  Referenced by: '<S5>/des_z'

  real32_T des_vxvy_Y0;                // Computed Parameter: des_vxvy_Y0
                                          //  Referenced by: '<S5>/des_vxvy'

  real32_T Constant1_Value_m;          // Computed Parameter: Constant1_Value_m
                                          //  Referenced by: '<S264>/Constant1'

  real32_T Gain_Gain_a;                // Computed Parameter: Gain_Gain_a
                                          //  Referenced by: '<S344>/Gain'

  real32_T Constant_Value_kn[2];       // Computed Parameter: Constant_Value_kn
                                          //  Referenced by: '<S5>/Constant'

  real32_T Saturation_UpperSat_e;   // Computed Parameter: Saturation_UpperSat_e
                                       //  Referenced by: '<S186>/Saturation'

  real32_T Saturation_LowerSat_a;   // Computed Parameter: Saturation_LowerSat_a
                                       //  Referenced by: '<S186>/Saturation'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S186>/Gain1'

  real32_T DeadZone4_Start_d;          // Computed Parameter: DeadZone4_Start_d
                                          //  Referenced by: '<S183>/Dead Zone4'

  real32_T DeadZone4_End_l;            // Computed Parameter: DeadZone4_End_l
                                          //  Referenced by: '<S183>/Dead Zone4'

  real32_T Saturation10_UpperSat_m;
                                  // Computed Parameter: Saturation10_UpperSat_m
                                     //  Referenced by: '<S183>/Saturation10'

  real32_T Saturation10_LowerSat_n;
                                  // Computed Parameter: Saturation10_LowerSat_n
                                     //  Referenced by: '<S183>/Saturation10'

  real32_T Gain_Gain_o;                // Computed Parameter: Gain_Gain_o
                                          //  Referenced by: '<S183>/Gain'

  real32_T Gain_Gain_b;                // Computed Parameter: Gain_Gain_b
                                          //  Referenced by: '<S184>/Gain'

  real32_T Integrator_gainval_l;     // Computed Parameter: Integrator_gainval_l
                                        //  Referenced by: '<S274>/Integrator'

  real32_T Constant_Value_e;           // Computed Parameter: Constant_Value_e
                                          //  Referenced by: '<S184>/Constant'

  real32_T Filter_gainval_h;           // Computed Parameter: Filter_gainval_h
                                          //  Referenced by: '<S269>/Filter'

  real32_T Saturation1_UpperSat_e; // Computed Parameter: Saturation1_UpperSat_e
                                      //  Referenced by: '<S184>/Saturation1'

  real32_T Saturation1_LowerSat_bn;
                                  // Computed Parameter: Saturation1_LowerSat_bn
                                     //  Referenced by: '<S184>/Saturation1'

  real32_T Clamping_zero_Value_f;   // Computed Parameter: Clamping_zero_Value_f
                                       //  Referenced by: '<S264>/Clamping_zero'

  real32_T DeadZone2_Start_k;          // Computed Parameter: DeadZone2_Start_k
                                          //  Referenced by: '<S183>/Dead Zone2'

  real32_T DeadZone2_End_k;            // Computed Parameter: DeadZone2_End_k
                                          //  Referenced by: '<S183>/Dead Zone2'

  real32_T Saturation3_UpperSat_b; // Computed Parameter: Saturation3_UpperSat_b
                                      //  Referenced by: '<S183>/Saturation3'

  real32_T Saturation3_LowerSat_a; // Computed Parameter: Saturation3_LowerSat_a
                                      //  Referenced by: '<S183>/Saturation3'

  real32_T doublet_Y0;                 // Computed Parameter: doublet_Y0
                                          //  Referenced by: '<S561>/doublet'

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

  real32_T Merge1_InitialOutput;     // Computed Parameter: Merge1_InitialOutput
                                        //  Referenced by: '<Root>/Merge1'

  real32_T Integrator_gainval_i;     // Computed Parameter: Integrator_gainval_i
                                        //  Referenced by: '<S493>/Integrator'

  real32_T Filter_gainval_o;           // Computed Parameter: Filter_gainval_o
                                          //  Referenced by: '<S488>/Filter'

  real32_T Constant_Value_j4;          // Computed Parameter: Constant_Value_j4
                                          //  Referenced by: '<S9>/Constant'

  real32_T Integrator_gainval_im;   // Computed Parameter: Integrator_gainval_im
                                       //  Referenced by: '<S443>/Integrator'

  real32_T Filter_gainval_f;           // Computed Parameter: Filter_gainval_f
                                          //  Referenced by: '<S438>/Filter'

  real32_T Constant1_Value_f;          // Computed Parameter: Constant1_Value_f
                                          //  Referenced by: '<S9>/Constant1'

  real32_T Integrator_gainval_e;     // Computed Parameter: Integrator_gainval_e
                                        //  Referenced by: '<S543>/Integrator'

  real32_T Filter_gainval_m;           // Computed Parameter: Filter_gainval_m
                                          //  Referenced by: '<S538>/Filter'

  real32_T Constant2_Value_m;          // Computed Parameter: Constant2_Value_m
                                          //  Referenced by: '<S9>/Constant2'

  real32_T Constant_Value_kf;          // Computed Parameter: Constant_Value_kf
                                          //  Referenced by: '<S176>/Constant'

  real32_T Constant_Value_ms;          // Computed Parameter: Constant_Value_ms
                                          //  Referenced by: '<S177>/Constant'

  real32_T Constant_Value_ii;          // Computed Parameter: Constant_Value_ii
                                          //  Referenced by: '<S178>/Constant'

  real32_T Constant_Value_j4x;         // Computed Parameter: Constant_Value_j4x
                                          //  Referenced by: '<S179>/Constant'

  real32_T Constant_Value_l;           // Computed Parameter: Constant_Value_l
                                          //  Referenced by: '<S180>/Constant'

  real32_T Constant_Value_o;           // Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S181>/Constant'

  real32_T Constant_Value_a;           // Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<Root>/Constant'

  real32_T u2_Gain;                    // Computed Parameter: u2_Gain
                                          //  Referenced by: '<S566>/1//2'

  real32_T Constant_Value_gq;          // Computed Parameter: Constant_Value_gq
                                          //  Referenced by: '<S13>/Constant'

  real32_T Constant_Value_ov;          // Computed Parameter: Constant_Value_ov
                                          //  Referenced by: '<S12>/Constant'

  real32_T Constant_Value_ll;          // Computed Parameter: Constant_Value_ll
                                          //  Referenced by: '<S15>/Constant'

  real32_T Merge_InitialOutput;       // Computed Parameter: Merge_InitialOutput
                                         //  Referenced by: '<Root>/Merge'

  uint32_T Constant2_Value_l;          // Computed Parameter: Constant2_Value_l
                                          //  Referenced by: '<S12>/Constant2'

  uint16_T Output_Limits1_UpperSat;
                                  // Computed Parameter: Output_Limits1_UpperSat
                                     //  Referenced by: '<S6>/Output_Limits1'

  uint16_T Output_Limits1_LowerSat;
                                  // Computed Parameter: Output_Limits1_LowerSat
                                     //  Referenced by: '<S6>/Output_Limits1'

  int8_T Constant_Value_jc;            // Computed Parameter: Constant_Value_jc
                                          //  Referenced by: '<S45>/Constant'

  int8_T Constant2_Value_mj;           // Computed Parameter: Constant2_Value_mj
                                          //  Referenced by: '<S45>/Constant2'

  int8_T Constant3_Value_es;           // Computed Parameter: Constant3_Value_es
                                          //  Referenced by: '<S45>/Constant3'

  int8_T Constant4_Value_j;            // Computed Parameter: Constant4_Value_j
                                          //  Referenced by: '<S45>/Constant4'

  int8_T Constant_Value_mn;            // Computed Parameter: Constant_Value_mn
                                          //  Referenced by: '<S264>/Constant'

  int8_T Constant2_Value_p;            // Computed Parameter: Constant2_Value_p
                                          //  Referenced by: '<S264>/Constant2'

  int8_T Constant3_Value_n;            // Computed Parameter: Constant3_Value_n
                                          //  Referenced by: '<S264>/Constant3'

  int8_T Constant4_Value_i;            // Computed Parameter: Constant4_Value_i
                                          //  Referenced by: '<S264>/Constant4'

};

// Real-time Model Data Structure
struct tag_RTM_FLIGHT_hexacopter_T {
  const char_T * volatile errorStatus;
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

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void FLIGHT_hexacopter_initialize(void);
  extern void FLIGHT_hexacopter_step(void);
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
//  Block '<S17>/Display' : Unused code path elimination
//  Block '<S17>/Display1' : Unused code path elimination
//  Block '<S17>/Display2' : Unused code path elimination
//  Block '<S17>/Display3' : Unused code path elimination
//  Block '<S183>/Data Type Conversion1' : Unused code path elimination
//  Block '<S183>/Data Type Conversion2' : Unused code path elimination
//  Block '<S183>/Dead Zone1' : Unused code path elimination
//  Block '<S183>/Dead Zone3' : Unused code path elimination
//  Block '<S183>/Display' : Unused code path elimination
//  Block '<S183>/Display1' : Unused code path elimination
//  Block '<S183>/Display2' : Unused code path elimination
//  Block '<S183>/Display3' : Unused code path elimination
//  Block '<S183>/Fcn1' : Unused code path elimination
//  Block '<S183>/Fcn2' : Unused code path elimination
//  Block '<S183>/Gain1' : Unused code path elimination
//  Block '<S183>/Gain2' : Unused code path elimination
//  Block '<S183>/Saturation1' : Unused code path elimination
//  Block '<S183>/Saturation9' : Unused code path elimination
//  Block '<S399>/NOT' : Unused code path elimination
//  Block '<S397>/NOT' : Unused code path elimination
//  Block '<S402>/NOT' : Unused code path elimination
//  Block '<S398>/Signal Copy' : Unused code path elimination
//  Block '<S398>/Signal Copy1' : Unused code path elimination
//  Block '<S398>/Signal Copy2' : Unused code path elimination
//  Block '<S404>/Bitwise Operator' : Unused code path elimination
//  Block '<S404>/Data Type Conversion' : Unused code path elimination
//  Block '<S404>/Data Type Conversion1' : Unused code path elimination
//  Block '<S404>/Data Type Conversion2' : Unused code path elimination
//  Block '<S404>/Gain' : Unused code path elimination
//  Block '<S404>/Gain1' : Unused code path elimination
//  Block '<S405>/NOT' : Unused code path elimination
//  Block '<S9>/sas-roll_pitch_errror' : Unused code path elimination
//  Block '<Root>/Scope1' : Unused code path elimination
//  Block '<Root>/Scope2' : Unused code path elimination
//  Block '<S10>/Display' : Unused code path elimination
//  Block '<S10>/Display1' : Unused code path elimination
//  Block '<S10>/Display2' : Unused code path elimination
//  Block '<S10>/Display3' : Unused code path elimination
//  Block '<S10>/Display5' : Unused code path elimination
//  Block '<S10>/Display6' : Unused code path elimination
//  Block '<S10>/Display7' : Unused code path elimination
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<S7>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S7>/Data Type Conversion9' : Eliminate redundant data type conversion
//  Block '<S12>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S12>/Data Type Conversion3' : Eliminate redundant data type conversion


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
//  '<S2>'   : 'FLIGHT_hexacopter/Arm'
//  '<S3>'   : 'FLIGHT_hexacopter/CAS'
//  '<S4>'   : 'FLIGHT_hexacopter/Fault_Injection'
//  '<S5>'   : 'FLIGHT_hexacopter/If Action Subsystem'
//  '<S6>'   : 'FLIGHT_hexacopter/Mixer'
//  '<S7>'   : 'FLIGHT_hexacopter/Read uORB'
//  '<S8>'   : 'FLIGHT_hexacopter/Remote Control'
//  '<S9>'   : 'FLIGHT_hexacopter/SAS'
//  '<S10>'  : 'FLIGHT_hexacopter/Stabilized_Mode'
//  '<S11>'  : 'FLIGHT_hexacopter/quat2eul'
//  '<S12>'  : 'FLIGHT_hexacopter/uORB_actuator_outputs1'
//  '<S13>'  : 'FLIGHT_hexacopter/vehicle_attitude_setpoint'
//  '<S14>'  : 'FLIGHT_hexacopter/vehicle_local_position_setpoint'
//  '<S15>'  : 'FLIGHT_hexacopter/vehicle_rate_setpoint'
//  '<S16>'  : 'FLIGHT_hexacopter/vehicle_torque_setpoint'
//  '<S17>'  : 'FLIGHT_hexacopter/Altitude_Mode/Altitude_Mode_Stick2Command'
//  '<S18>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller'
//  '<S19>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4'
//  '<S20>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Anti-windup'
//  '<S21>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/D Gain'
//  '<S22>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/External Derivative'
//  '<S23>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Filter'
//  '<S24>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Filter ICs'
//  '<S25>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/I Gain'
//  '<S26>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Ideal P Gain'
//  '<S27>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S28>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Integrator'
//  '<S29>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Integrator ICs'
//  '<S30>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/N Copy'
//  '<S31>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/N Gain'
//  '<S32>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/P Copy'
//  '<S33>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Parallel P Gain'
//  '<S34>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Reset Signal'
//  '<S35>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Saturation'
//  '<S36>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Saturation Fdbk'
//  '<S37>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Sum'
//  '<S38>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Sum Fdbk'
//  '<S39>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tracking Mode'
//  '<S40>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tracking Mode Sum'
//  '<S41>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tsamp - Integral'
//  '<S42>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tsamp - Ngain'
//  '<S43>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/postSat Signal'
//  '<S44>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/preSat Signal'
//  '<S45>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel'
//  '<S46>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S47>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S48>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/D Gain/External Parameters'
//  '<S49>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/External Derivative/Error'
//  '<S50>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Filter/Disc. Forward Euler Filter'
//  '<S51>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Filter ICs/Internal IC - Filter'
//  '<S52>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/I Gain/External Parameters'
//  '<S53>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S54>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S55>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Integrator/Discrete'
//  '<S56>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Integrator ICs/Internal IC'
//  '<S57>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/N Copy/Disabled'
//  '<S58>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/N Gain/External Parameters'
//  '<S59>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/P Copy/Disabled'
//  '<S60>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Parallel P Gain/External Parameters'
//  '<S61>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Reset Signal/Disabled'
//  '<S62>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Saturation/Enabled'
//  '<S63>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S64>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Sum/Sum_PID'
//  '<S65>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S66>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tracking Mode/Disabled'
//  '<S67>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S68>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S69>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S70>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S71>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S72>'  : 'FLIGHT_hexacopter/Arm/Compare To Constant3'
//  '<S73>'  : 'FLIGHT_hexacopter/CAS/PID Controller3'
//  '<S74>'  : 'FLIGHT_hexacopter/CAS/PID Controller4'
//  '<S75>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Anti-windup'
//  '<S76>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/D Gain'
//  '<S77>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/External Derivative'
//  '<S78>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Filter'
//  '<S79>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Filter ICs'
//  '<S80>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/I Gain'
//  '<S81>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Ideal P Gain'
//  '<S82>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Ideal P Gain Fdbk'
//  '<S83>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Integrator'
//  '<S84>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Integrator ICs'
//  '<S85>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/N Copy'
//  '<S86>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/N Gain'
//  '<S87>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/P Copy'
//  '<S88>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Parallel P Gain'
//  '<S89>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Reset Signal'
//  '<S90>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation'
//  '<S91>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation Fdbk'
//  '<S92>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Sum'
//  '<S93>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Sum Fdbk'
//  '<S94>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Tracking Mode'
//  '<S95>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Tracking Mode Sum'
//  '<S96>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Tsamp - Integral'
//  '<S97>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Tsamp - Ngain'
//  '<S98>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/postSat Signal'
//  '<S99>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/preSat Signal'
//  '<S100>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Anti-windup/Disabled'
//  '<S101>' : 'FLIGHT_hexacopter/CAS/PID Controller3/D Gain/Disabled'
//  '<S102>' : 'FLIGHT_hexacopter/CAS/PID Controller3/External Derivative/Disabled'
//  '<S103>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Filter/Disabled'
//  '<S104>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Filter ICs/Disabled'
//  '<S105>' : 'FLIGHT_hexacopter/CAS/PID Controller3/I Gain/Disabled'
//  '<S106>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Ideal P Gain/Passthrough'
//  '<S107>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S108>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Integrator/Disabled'
//  '<S109>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Integrator ICs/Disabled'
//  '<S110>' : 'FLIGHT_hexacopter/CAS/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S111>' : 'FLIGHT_hexacopter/CAS/PID Controller3/N Gain/Disabled'
//  '<S112>' : 'FLIGHT_hexacopter/CAS/PID Controller3/P Copy/Disabled'
//  '<S113>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Parallel P Gain/External Parameters'
//  '<S114>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Reset Signal/Disabled'
//  '<S115>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation/Passthrough'
//  '<S116>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation Fdbk/Disabled'
//  '<S117>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Sum/Passthrough_P'
//  '<S118>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Sum Fdbk/Disabled'
//  '<S119>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tracking Mode/Disabled'
//  '<S120>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S121>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S122>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S123>' : 'FLIGHT_hexacopter/CAS/PID Controller3/postSat Signal/Forward_Path'
//  '<S124>' : 'FLIGHT_hexacopter/CAS/PID Controller3/preSat Signal/Forward_Path'
//  '<S125>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Anti-windup'
//  '<S126>' : 'FLIGHT_hexacopter/CAS/PID Controller4/D Gain'
//  '<S127>' : 'FLIGHT_hexacopter/CAS/PID Controller4/External Derivative'
//  '<S128>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Filter'
//  '<S129>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Filter ICs'
//  '<S130>' : 'FLIGHT_hexacopter/CAS/PID Controller4/I Gain'
//  '<S131>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Ideal P Gain'
//  '<S132>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Ideal P Gain Fdbk'
//  '<S133>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Integrator'
//  '<S134>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Integrator ICs'
//  '<S135>' : 'FLIGHT_hexacopter/CAS/PID Controller4/N Copy'
//  '<S136>' : 'FLIGHT_hexacopter/CAS/PID Controller4/N Gain'
//  '<S137>' : 'FLIGHT_hexacopter/CAS/PID Controller4/P Copy'
//  '<S138>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Parallel P Gain'
//  '<S139>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Reset Signal'
//  '<S140>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation'
//  '<S141>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation Fdbk'
//  '<S142>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Sum'
//  '<S143>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Sum Fdbk'
//  '<S144>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tracking Mode'
//  '<S145>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tracking Mode Sum'
//  '<S146>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tsamp - Integral'
//  '<S147>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tsamp - Ngain'
//  '<S148>' : 'FLIGHT_hexacopter/CAS/PID Controller4/postSat Signal'
//  '<S149>' : 'FLIGHT_hexacopter/CAS/PID Controller4/preSat Signal'
//  '<S150>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Anti-windup/Disabled'
//  '<S151>' : 'FLIGHT_hexacopter/CAS/PID Controller4/D Gain/Disabled'
//  '<S152>' : 'FLIGHT_hexacopter/CAS/PID Controller4/External Derivative/Disabled'
//  '<S153>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Filter/Disabled'
//  '<S154>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Filter ICs/Disabled'
//  '<S155>' : 'FLIGHT_hexacopter/CAS/PID Controller4/I Gain/Disabled'
//  '<S156>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Ideal P Gain/Passthrough'
//  '<S157>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S158>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Integrator/Disabled'
//  '<S159>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Integrator ICs/Disabled'
//  '<S160>' : 'FLIGHT_hexacopter/CAS/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S161>' : 'FLIGHT_hexacopter/CAS/PID Controller4/N Gain/Disabled'
//  '<S162>' : 'FLIGHT_hexacopter/CAS/PID Controller4/P Copy/Disabled'
//  '<S163>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Parallel P Gain/External Parameters'
//  '<S164>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Reset Signal/Disabled'
//  '<S165>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation/Passthrough'
//  '<S166>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation Fdbk/Disabled'
//  '<S167>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Sum/Passthrough_P'
//  '<S168>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Sum Fdbk/Disabled'
//  '<S169>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tracking Mode/Disabled'
//  '<S170>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S171>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S172>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S173>' : 'FLIGHT_hexacopter/CAS/PID Controller4/postSat Signal/Forward_Path'
//  '<S174>' : 'FLIGHT_hexacopter/CAS/PID Controller4/preSat Signal/Forward_Path'
//  '<S175>' : 'FLIGHT_hexacopter/Fault_Injection/Compare To Constant'
//  '<S176>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference'
//  '<S177>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference1'
//  '<S178>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference2'
//  '<S179>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference3'
//  '<S180>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference4'
//  '<S181>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference5'
//  '<S182>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller'
//  '<S183>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude_Mode_Stick2Command'
//  '<S184>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller'
//  '<S185>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller'
//  '<S186>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller'
//  '<S187>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4'
//  '<S188>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Anti-windup'
//  '<S189>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/D Gain'
//  '<S190>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/External Derivative'
//  '<S191>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Filter'
//  '<S192>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Filter ICs'
//  '<S193>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/I Gain'
//  '<S194>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Ideal P Gain'
//  '<S195>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S196>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Integrator'
//  '<S197>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Integrator ICs'
//  '<S198>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/N Copy'
//  '<S199>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/N Gain'
//  '<S200>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/P Copy'
//  '<S201>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Parallel P Gain'
//  '<S202>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Reset Signal'
//  '<S203>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Saturation'
//  '<S204>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Saturation Fdbk'
//  '<S205>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Sum'
//  '<S206>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Sum Fdbk'
//  '<S207>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tracking Mode'
//  '<S208>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tracking Mode Sum'
//  '<S209>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tsamp - Integral'
//  '<S210>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tsamp - Ngain'
//  '<S211>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/postSat Signal'
//  '<S212>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/preSat Signal'
//  '<S213>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Anti-windup/Disabled'
//  '<S214>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/D Gain/Disabled'
//  '<S215>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/External Derivative/Disabled'
//  '<S216>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Filter/Disabled'
//  '<S217>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Filter ICs/Disabled'
//  '<S218>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/I Gain/Disabled'
//  '<S219>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S220>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S221>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Integrator/Disabled'
//  '<S222>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Integrator ICs/Disabled'
//  '<S223>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S224>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/N Gain/Disabled'
//  '<S225>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/P Copy/Disabled'
//  '<S226>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Parallel P Gain/External Parameters'
//  '<S227>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Reset Signal/Disabled'
//  '<S228>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Saturation/Enabled'
//  '<S229>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S230>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Sum/Passthrough_P'
//  '<S231>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S232>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tracking Mode/Disabled'
//  '<S233>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S234>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S235>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S236>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S237>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S238>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4'
//  '<S239>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Anti-windup'
//  '<S240>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/D Gain'
//  '<S241>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/External Derivative'
//  '<S242>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Filter'
//  '<S243>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Filter ICs'
//  '<S244>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/I Gain'
//  '<S245>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Ideal P Gain'
//  '<S246>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S247>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Integrator'
//  '<S248>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Integrator ICs'
//  '<S249>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/N Copy'
//  '<S250>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/N Gain'
//  '<S251>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/P Copy'
//  '<S252>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Parallel P Gain'
//  '<S253>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Reset Signal'
//  '<S254>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Saturation'
//  '<S255>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Saturation Fdbk'
//  '<S256>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Sum'
//  '<S257>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Sum Fdbk'
//  '<S258>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tracking Mode'
//  '<S259>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tracking Mode Sum'
//  '<S260>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tsamp - Integral'
//  '<S261>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tsamp - Ngain'
//  '<S262>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/postSat Signal'
//  '<S263>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/preSat Signal'
//  '<S264>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel'
//  '<S265>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S266>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S267>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/D Gain/External Parameters'
//  '<S268>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/External Derivative/Error'
//  '<S269>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Filter/Disc. Forward Euler Filter'
//  '<S270>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Filter ICs/Internal IC - Filter'
//  '<S271>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/I Gain/External Parameters'
//  '<S272>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S273>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S274>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Integrator/Discrete'
//  '<S275>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Integrator ICs/Internal IC'
//  '<S276>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/N Copy/Disabled'
//  '<S277>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/N Gain/External Parameters'
//  '<S278>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/P Copy/Disabled'
//  '<S279>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Parallel P Gain/External Parameters'
//  '<S280>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Reset Signal/External Reset'
//  '<S281>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Saturation/Enabled'
//  '<S282>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S283>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Sum/Sum_PID'
//  '<S284>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S285>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tracking Mode/Disabled'
//  '<S286>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S287>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S288>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S289>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S290>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S291>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude'
//  '<S292>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Anti-windup'
//  '<S293>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/D Gain'
//  '<S294>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/External Derivative'
//  '<S295>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Filter'
//  '<S296>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Filter ICs'
//  '<S297>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/I Gain'
//  '<S298>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Ideal P Gain'
//  '<S299>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S300>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Integrator'
//  '<S301>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Integrator ICs'
//  '<S302>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/N Copy'
//  '<S303>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/N Gain'
//  '<S304>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/P Copy'
//  '<S305>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Parallel P Gain'
//  '<S306>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Reset Signal'
//  '<S307>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Saturation'
//  '<S308>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Saturation Fdbk'
//  '<S309>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Sum'
//  '<S310>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Sum Fdbk'
//  '<S311>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tracking Mode'
//  '<S312>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tracking Mode Sum'
//  '<S313>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tsamp - Integral'
//  '<S314>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tsamp - Ngain'
//  '<S315>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/postSat Signal'
//  '<S316>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/preSat Signal'
//  '<S317>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Anti-windup/Disabled'
//  '<S318>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/D Gain/Disabled'
//  '<S319>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/External Derivative/Disabled'
//  '<S320>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Filter/Disabled'
//  '<S321>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Filter ICs/Disabled'
//  '<S322>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/I Gain/Disabled'
//  '<S323>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S324>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Ideal P Gain Fdbk/Disabled'
//  '<S325>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Integrator/Disabled'
//  '<S326>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Integrator ICs/Disabled'
//  '<S327>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/N Copy/Disabled wSignal Specification'
//  '<S328>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/N Gain/Disabled'
//  '<S329>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/P Copy/Disabled'
//  '<S330>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Parallel P Gain/External Parameters'
//  '<S331>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Reset Signal/Disabled'
//  '<S332>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Saturation/Passthrough'
//  '<S333>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Saturation Fdbk/Disabled'
//  '<S334>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Sum/Passthrough_P'
//  '<S335>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Sum Fdbk/Disabled'
//  '<S336>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S337>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S338>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S339>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S340>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/postSat Signal/Forward_Path'
//  '<S341>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/preSat Signal/Forward_Path'
//  '<S342>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/NED2Body1'
//  '<S343>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude'
//  '<S344>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/NED2Body1/Calculate Transformation Matrix'
//  '<S345>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Anti-windup'
//  '<S346>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/D Gain'
//  '<S347>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/External Derivative'
//  '<S348>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Filter'
//  '<S349>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Filter ICs'
//  '<S350>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/I Gain'
//  '<S351>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Ideal P Gain'
//  '<S352>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S353>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Integrator'
//  '<S354>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Integrator ICs'
//  '<S355>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/N Copy'
//  '<S356>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/N Gain'
//  '<S357>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/P Copy'
//  '<S358>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Parallel P Gain'
//  '<S359>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Reset Signal'
//  '<S360>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Saturation'
//  '<S361>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Saturation Fdbk'
//  '<S362>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Sum'
//  '<S363>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Sum Fdbk'
//  '<S364>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tracking Mode'
//  '<S365>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tracking Mode Sum'
//  '<S366>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tsamp - Integral'
//  '<S367>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tsamp - Ngain'
//  '<S368>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/postSat Signal'
//  '<S369>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/preSat Signal'
//  '<S370>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Anti-windup/Disabled'
//  '<S371>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/D Gain/Disabled'
//  '<S372>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/External Derivative/Disabled'
//  '<S373>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Filter/Disabled'
//  '<S374>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Filter ICs/Disabled'
//  '<S375>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/I Gain/Disabled'
//  '<S376>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S377>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Ideal P Gain Fdbk/Disabled'
//  '<S378>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Integrator/Disabled'
//  '<S379>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Integrator ICs/Disabled'
//  '<S380>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/N Copy/Disabled wSignal Specification'
//  '<S381>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/N Gain/Disabled'
//  '<S382>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/P Copy/Disabled'
//  '<S383>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Parallel P Gain/External Parameters'
//  '<S384>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Reset Signal/Disabled'
//  '<S385>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Saturation/Passthrough'
//  '<S386>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Saturation Fdbk/Disabled'
//  '<S387>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Sum/Passthrough_P'
//  '<S388>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Sum Fdbk/Disabled'
//  '<S389>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S390>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S391>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S392>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S393>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/postSat Signal/Forward_Path'
//  '<S394>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/preSat Signal/Forward_Path'
//  '<S395>' : 'FLIGHT_hexacopter/Mixer/pwm_out2'
//  '<S396>' : 'FLIGHT_hexacopter/Read uORB/Gyroscope'
//  '<S397>' : 'FLIGHT_hexacopter/Read uORB/PX4 uORB Read'
//  '<S398>' : 'FLIGHT_hexacopter/Read uORB/Vehicle Attitude'
//  '<S399>' : 'FLIGHT_hexacopter/Read uORB/Gyroscope/PX4 uORB Read'
//  '<S400>' : 'FLIGHT_hexacopter/Read uORB/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S401>' : 'FLIGHT_hexacopter/Read uORB/PX4 uORB Read/Enabled Subsystem'
//  '<S402>' : 'FLIGHT_hexacopter/Read uORB/Vehicle Attitude/PX4 uORB Read'
//  '<S403>' : 'FLIGHT_hexacopter/Read uORB/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'
//  '<S404>' : 'FLIGHT_hexacopter/Remote Control/Radio Control Transmitter'
//  '<S405>' : 'FLIGHT_hexacopter/Remote Control/Radio Control Transmitter/PX4 uORB Read'
//  '<S406>' : 'FLIGHT_hexacopter/Remote Control/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S407>' : 'FLIGHT_hexacopter/SAS/PID Controller1'
//  '<S408>' : 'FLIGHT_hexacopter/SAS/PID Controller2'
//  '<S409>' : 'FLIGHT_hexacopter/SAS/PID Controller6'
//  '<S410>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Anti-windup'
//  '<S411>' : 'FLIGHT_hexacopter/SAS/PID Controller1/D Gain'
//  '<S412>' : 'FLIGHT_hexacopter/SAS/PID Controller1/External Derivative'
//  '<S413>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Filter'
//  '<S414>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Filter ICs'
//  '<S415>' : 'FLIGHT_hexacopter/SAS/PID Controller1/I Gain'
//  '<S416>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Ideal P Gain'
//  '<S417>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Ideal P Gain Fdbk'
//  '<S418>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Integrator'
//  '<S419>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Integrator ICs'
//  '<S420>' : 'FLIGHT_hexacopter/SAS/PID Controller1/N Copy'
//  '<S421>' : 'FLIGHT_hexacopter/SAS/PID Controller1/N Gain'
//  '<S422>' : 'FLIGHT_hexacopter/SAS/PID Controller1/P Copy'
//  '<S423>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Parallel P Gain'
//  '<S424>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Reset Signal'
//  '<S425>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Saturation'
//  '<S426>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Saturation Fdbk'
//  '<S427>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Sum'
//  '<S428>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Sum Fdbk'
//  '<S429>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Tracking Mode'
//  '<S430>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Tracking Mode Sum'
//  '<S431>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Tsamp - Integral'
//  '<S432>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Tsamp - Ngain'
//  '<S433>' : 'FLIGHT_hexacopter/SAS/PID Controller1/postSat Signal'
//  '<S434>' : 'FLIGHT_hexacopter/SAS/PID Controller1/preSat Signal'
//  '<S435>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Anti-windup/Passthrough'
//  '<S436>' : 'FLIGHT_hexacopter/SAS/PID Controller1/D Gain/External Parameters'
//  '<S437>' : 'FLIGHT_hexacopter/SAS/PID Controller1/External Derivative/Error'
//  '<S438>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S439>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S440>' : 'FLIGHT_hexacopter/SAS/PID Controller1/I Gain/External Parameters'
//  '<S441>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Ideal P Gain/Passthrough'
//  '<S442>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S443>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Integrator/Discrete'
//  '<S444>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Integrator ICs/Internal IC'
//  '<S445>' : 'FLIGHT_hexacopter/SAS/PID Controller1/N Copy/Disabled'
//  '<S446>' : 'FLIGHT_hexacopter/SAS/PID Controller1/N Gain/External Parameters'
//  '<S447>' : 'FLIGHT_hexacopter/SAS/PID Controller1/P Copy/Disabled'
//  '<S448>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Parallel P Gain/External Parameters'
//  '<S449>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Reset Signal/Disabled'
//  '<S450>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Saturation/Passthrough'
//  '<S451>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Saturation Fdbk/Disabled'
//  '<S452>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Sum/Sum_PID'
//  '<S453>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Sum Fdbk/Disabled'
//  '<S454>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Tracking Mode/Disabled'
//  '<S455>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S456>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S457>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S458>' : 'FLIGHT_hexacopter/SAS/PID Controller1/postSat Signal/Forward_Path'
//  '<S459>' : 'FLIGHT_hexacopter/SAS/PID Controller1/preSat Signal/Forward_Path'
//  '<S460>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Anti-windup'
//  '<S461>' : 'FLIGHT_hexacopter/SAS/PID Controller2/D Gain'
//  '<S462>' : 'FLIGHT_hexacopter/SAS/PID Controller2/External Derivative'
//  '<S463>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Filter'
//  '<S464>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Filter ICs'
//  '<S465>' : 'FLIGHT_hexacopter/SAS/PID Controller2/I Gain'
//  '<S466>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Ideal P Gain'
//  '<S467>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Ideal P Gain Fdbk'
//  '<S468>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Integrator'
//  '<S469>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Integrator ICs'
//  '<S470>' : 'FLIGHT_hexacopter/SAS/PID Controller2/N Copy'
//  '<S471>' : 'FLIGHT_hexacopter/SAS/PID Controller2/N Gain'
//  '<S472>' : 'FLIGHT_hexacopter/SAS/PID Controller2/P Copy'
//  '<S473>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Parallel P Gain'
//  '<S474>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Reset Signal'
//  '<S475>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Saturation'
//  '<S476>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Saturation Fdbk'
//  '<S477>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Sum'
//  '<S478>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Sum Fdbk'
//  '<S479>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Tracking Mode'
//  '<S480>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Tracking Mode Sum'
//  '<S481>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Tsamp - Integral'
//  '<S482>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Tsamp - Ngain'
//  '<S483>' : 'FLIGHT_hexacopter/SAS/PID Controller2/postSat Signal'
//  '<S484>' : 'FLIGHT_hexacopter/SAS/PID Controller2/preSat Signal'
//  '<S485>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Anti-windup/Passthrough'
//  '<S486>' : 'FLIGHT_hexacopter/SAS/PID Controller2/D Gain/External Parameters'
//  '<S487>' : 'FLIGHT_hexacopter/SAS/PID Controller2/External Derivative/Error'
//  '<S488>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S489>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S490>' : 'FLIGHT_hexacopter/SAS/PID Controller2/I Gain/External Parameters'
//  '<S491>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Ideal P Gain/Passthrough'
//  '<S492>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S493>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Integrator/Discrete'
//  '<S494>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Integrator ICs/Internal IC'
//  '<S495>' : 'FLIGHT_hexacopter/SAS/PID Controller2/N Copy/Disabled'
//  '<S496>' : 'FLIGHT_hexacopter/SAS/PID Controller2/N Gain/External Parameters'
//  '<S497>' : 'FLIGHT_hexacopter/SAS/PID Controller2/P Copy/Disabled'
//  '<S498>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Parallel P Gain/External Parameters'
//  '<S499>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Reset Signal/Disabled'
//  '<S500>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Saturation/Passthrough'
//  '<S501>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Saturation Fdbk/Disabled'
//  '<S502>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Sum/Sum_PID'
//  '<S503>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Sum Fdbk/Disabled'
//  '<S504>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Tracking Mode/Disabled'
//  '<S505>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S506>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S507>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S508>' : 'FLIGHT_hexacopter/SAS/PID Controller2/postSat Signal/Forward_Path'
//  '<S509>' : 'FLIGHT_hexacopter/SAS/PID Controller2/preSat Signal/Forward_Path'
//  '<S510>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Anti-windup'
//  '<S511>' : 'FLIGHT_hexacopter/SAS/PID Controller6/D Gain'
//  '<S512>' : 'FLIGHT_hexacopter/SAS/PID Controller6/External Derivative'
//  '<S513>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Filter'
//  '<S514>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Filter ICs'
//  '<S515>' : 'FLIGHT_hexacopter/SAS/PID Controller6/I Gain'
//  '<S516>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Ideal P Gain'
//  '<S517>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Ideal P Gain Fdbk'
//  '<S518>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Integrator'
//  '<S519>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Integrator ICs'
//  '<S520>' : 'FLIGHT_hexacopter/SAS/PID Controller6/N Copy'
//  '<S521>' : 'FLIGHT_hexacopter/SAS/PID Controller6/N Gain'
//  '<S522>' : 'FLIGHT_hexacopter/SAS/PID Controller6/P Copy'
//  '<S523>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Parallel P Gain'
//  '<S524>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Reset Signal'
//  '<S525>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Saturation'
//  '<S526>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Saturation Fdbk'
//  '<S527>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Sum'
//  '<S528>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Sum Fdbk'
//  '<S529>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Tracking Mode'
//  '<S530>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Tracking Mode Sum'
//  '<S531>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Tsamp - Integral'
//  '<S532>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Tsamp - Ngain'
//  '<S533>' : 'FLIGHT_hexacopter/SAS/PID Controller6/postSat Signal'
//  '<S534>' : 'FLIGHT_hexacopter/SAS/PID Controller6/preSat Signal'
//  '<S535>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Anti-windup/Passthrough'
//  '<S536>' : 'FLIGHT_hexacopter/SAS/PID Controller6/D Gain/External Parameters'
//  '<S537>' : 'FLIGHT_hexacopter/SAS/PID Controller6/External Derivative/Error'
//  '<S538>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Filter/Disc. Forward Euler Filter'
//  '<S539>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Filter ICs/Internal IC - Filter'
//  '<S540>' : 'FLIGHT_hexacopter/SAS/PID Controller6/I Gain/External Parameters'
//  '<S541>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Ideal P Gain/Passthrough'
//  '<S542>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Ideal P Gain Fdbk/Disabled'
//  '<S543>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Integrator/Discrete'
//  '<S544>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Integrator ICs/Internal IC'
//  '<S545>' : 'FLIGHT_hexacopter/SAS/PID Controller6/N Copy/Disabled'
//  '<S546>' : 'FLIGHT_hexacopter/SAS/PID Controller6/N Gain/External Parameters'
//  '<S547>' : 'FLIGHT_hexacopter/SAS/PID Controller6/P Copy/Disabled'
//  '<S548>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Parallel P Gain/External Parameters'
//  '<S549>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Reset Signal/Disabled'
//  '<S550>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Saturation/Passthrough'
//  '<S551>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Saturation Fdbk/Disabled'
//  '<S552>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Sum/Sum_PID'
//  '<S553>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Sum Fdbk/Disabled'
//  '<S554>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Tracking Mode/Disabled'
//  '<S555>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Tracking Mode Sum/Passthrough'
//  '<S556>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Tsamp - Integral/TsSignalSpecification'
//  '<S557>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Tsamp - Ngain/Passthrough'
//  '<S558>' : 'FLIGHT_hexacopter/SAS/PID Controller6/postSat Signal/Forward_Path'
//  '<S559>' : 'FLIGHT_hexacopter/SAS/PID Controller6/preSat Signal/Forward_Path'
//  '<S560>' : 'FLIGHT_hexacopter/Stabilized_Mode/Compare To Constant'
//  '<S561>' : 'FLIGHT_hexacopter/Stabilized_Mode/Enabled Subsystem'
//  '<S562>' : 'FLIGHT_hexacopter/uORB_actuator_outputs1/PX4 uORB Message'
//  '<S563>' : 'FLIGHT_hexacopter/uORB_actuator_outputs1/PX4 uORB Write'
//  '<S564>' : 'FLIGHT_hexacopter/vehicle_attitude_setpoint/PX4 uORB Message'
//  '<S565>' : 'FLIGHT_hexacopter/vehicle_attitude_setpoint/PX4 uORB Write'
//  '<S566>' : 'FLIGHT_hexacopter/vehicle_attitude_setpoint/Rotation Angles to Quaternions'
//  '<S567>' : 'FLIGHT_hexacopter/vehicle_local_position_setpoint/PX4 uORB Message'
//  '<S568>' : 'FLIGHT_hexacopter/vehicle_local_position_setpoint/PX4 uORB Write'
//  '<S569>' : 'FLIGHT_hexacopter/vehicle_rate_setpoint/PX4 uORB Message'
//  '<S570>' : 'FLIGHT_hexacopter/vehicle_rate_setpoint/PX4 uORB Write'
//  '<S571>' : 'FLIGHT_hexacopter/vehicle_torque_setpoint/PX4 uORB Message'
//  '<S572>' : 'FLIGHT_hexacopter/vehicle_torque_setpoint/PX4 uORB Write'

#endif                                 // FLIGHT_hexacopter_h_

//
// File trailer for generated code.
//
// [EOF]
//
