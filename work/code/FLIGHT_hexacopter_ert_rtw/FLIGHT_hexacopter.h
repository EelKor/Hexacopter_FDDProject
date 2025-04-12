//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_hexacopter.h
//
// Code generated for Simulink model 'FLIGHT_hexacopter'.
//
// Model version                  : 1.114
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Sat Apr 12 17:48:33 2025
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
#include <uORB/topics/actuator_motors.h>
#include <uORB/topics/vehicle_local_position_setpoint.h>
#include <uORB/topics/vehicle_attitude_setpoint.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/vehicle_rates_setpoint.h>
#include <uORB/topics/vehicle_torque_setpoint.h>
#include <math.h>

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

// Block states (default storage) for system '<S18>/Read Parameter'
struct DW_ReadParameter_FLIGHT_hexac_T {
  px4_internal_block_ParameterU_T obj; // '<S18>/Read Parameter'
  boolean_T objisempty;                // '<S18>/Read Parameter'
};

// Block signals for system '<S19>/Read Parameter'
struct B_ReadParameter_FLIGHT_hexa_c_T {
  real32_T ReadParameter_o1;           // '<S19>/Read Parameter'
};

// Block states (default storage) for system '<S19>/Read Parameter'
struct DW_ReadParameter_FLIGHT_hex_f_T {
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

// Block signals for system '<S11>/PX4 Timestamp'
struct B_PX4Timestamp_FLIGHT_hexacop_T {
  uint64_T PX4Timestamp;               // '<S11>/PX4 Timestamp'
};

// Block states (default storage) for system '<S11>/PX4 Timestamp'
struct DW_PX4Timestamp_FLIGHT_hexaco_T {
  px4_internal_block_getPX4Abso_T obj; // '<S11>/PX4 Timestamp'
  boolean_T objisempty;                // '<S11>/PX4 Timestamp'
};

// Block signals (default storage)
struct B_FLIGHT_hexacopter_T {
  px4_Bus_vehicle_local_position In1;  // '<S406>/In1'
  px4_Bus_vehicle_local_position r;
  px4_Bus_vehicle_odometry In1_k;      // '<S409>/In1'
  px4_Bus_vehicle_odometry r1;
  px4_Bus_actuator_outputs BusAssignment;// '<S575>/Bus Assignment'
  px4_Bus_input_rc In1_n;              // '<S414>/In1'
  px4_Bus_input_rc r2;
  px4_Bus_actuator_motors BusAssignment_f;// '<S574>/Bus Assignment'
  px4_Bus_vehicle_local_position_setpoint BusAssignment_g;// '<S13>/Bus Assignment' 
  px4_Bus_vehicle_attitude_setpoint BusAssignment_d;// '<S12>/Bus Assignment'
  px4_Bus_vehicle_angular_velocity In1_h;// '<S407>/In1'
  px4_Bus_vehicle_angular_velocity r3;
  px4_Bus_vehicle_rates_setpoint BusAssignment_e;// '<S14>/Bus Assignment'
  px4_Bus_vehicle_torque_setpoint BusAssignment_n;// '<S15>/Bus Assignment'
  uint16_T pwmValue[8];
  real32_T Merge1[4];                  // '<Root>/Merge1'
  uint16_T DataTypeConversion_j[6];    // '<Root>/Data Type Conversion'
  uint16_T DataTypeConversion6[6];     // '<S3>/Data Type Conversion6'
  uint16_T DataTypeConversion7[6];     // '<S3>/Data Type Conversion7'
  real_T Product_k;                    // '<S569>/Product'
  real_T Signal;                       // '<S571>/fromWS_Signal 1'
  real_T Signal_a;                     // '<S21>/fromWS_Signal 1'
  uint64_T rtb_PX4Timestamp_m;
  real32_T Merge;                      // '<Root>/Merge'
  real32_T Sum_cc;                     // '<S510>/Sum'
  real32_T Sum_a;                      // '<S460>/Sum'
  real32_T Sum_i;                      // '<S560>/Sum'
  real32_T OutportBufferFordes_xy[2];  // '<S4>/Constant'
  real32_T Add;                        // '<S4>/Add'
  real32_T Saturation[2];              // '<S193>/Saturation'
  real32_T Gain1;                      // '<S193>/Gain1'
  real32_T PProdOut[2];                // '<S337>/PProd Out'
  real32_T des_vz;                     // '<S191>/des_vz'
  real32_T Saturation1;                // '<S191>/Saturation1'
  real32_T Saturation1_i;              // '<S19>/Saturation1'
  real32_T Switch2;                    // '<S172>/Switch2'
  real32_T Switch2_i;                  // '<S121>/Switch2'
  uint16_T Output_Limits1[6];          // '<S5>/Output_Limits1'
  int32_T ParamStep;
  int32_T ParamStep_c;
  int32_T ParamStep_k;
  int32_T ParamStep_cx;
  B_PX4Timestamp_FLIGHT_hexacop_T PX4Timestamp_pna;// '<S11>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexacop_T PX4Timestamp_p;// '<S11>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexacop_T PX4Timestamp_o;// '<S11>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexacop_T PX4Timestamp_n;// '<S11>/PX4 Timestamp'
  B_PX4Timestamp_FLIGHT_hexacop_T PX4Timestamp;// '<S11>/PX4 Timestamp'
  B_ReadParameter3_FLIGHT_hexac_T ReadParameter3_pn;// '<S19>/Read Parameter3'
  B_ReadParameter2_FLIGHT_hexac_T ReadParameter2_pn;// '<S19>/Read Parameter2'
  B_ReadParameter1_FLIGHT_hexac_T ReadParameter1_pnae;// '<S19>/Read Parameter1' 
  B_ReadParameter_FLIGHT_hexa_c_T ReadParameter_pna;// '<S19>/Read Parameter'
  B_ReadParameter3_FLIGHT_hexac_T ReadParameter3_p;// '<S19>/Read Parameter3'
  B_ReadParameter2_FLIGHT_hexac_T ReadParameter2_p;// '<S19>/Read Parameter2'
  B_ReadParameter1_FLIGHT_hexac_T ReadParameter1_pn;// '<S19>/Read Parameter1'
  B_ReadParameter_FLIGHT_hexa_c_T ReadParameter_pn;// '<S19>/Read Parameter'
};

// Block states (default storage) for system '<Root>'
struct DW_FLIGHT_hexacopter_T {
  px4_internal_block_ParameterU_T obj; // '<S8>/Read Parameter8'
  px4_internal_block_ParameterU_T obj_j;// '<S8>/Read Parameter7'
  px4_internal_block_ParameterU_T obj_a;// '<S8>/Read Parameter6'
  px4_internal_block_ParameterU_T obj_h;// '<S8>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_p;// '<S8>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_b;// '<S8>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_d;// '<S8>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_e;// '<S8>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_i;// '<S8>/Read Parameter'
  px4_internal_block_ParameterU_T obj_pi;// '<S193>/Read Parameter'
  px4_internal_block_ParameterU_T obj_eq;// '<S192>/Read Parameter'
  px4_internal_block_ParameterU_T obj_m;// '<S189>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_aq;// '<S3>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_c;// '<S3>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_n;// '<S3>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_ao;// '<S3>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_g;// '<S3>/Read Parameter13'
  px4_internal_block_ParameterU_T obj_j5;// '<S3>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_k;// '<S2>/Read Parameter9'
  px4_internal_block_ParameterU_T obj_ds;// '<S2>/Read Parameter10'
  px4_internal_block_ParameterU_T obj_o;// '<S2>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_jz;// '<S2>/Read Parameter'
  px4_internal_block_Subscriber_T obj_p2;// '<S413>/SourceBlock'
  px4_internal_block_Subscriber_T obj_ab;// '<S408>/SourceBlock'
  px4_internal_block_Subscriber_T obj_pe;// '<S404>/SourceBlock'
  px4_internal_block_Subscriber_T obj_kk;// '<S403>/SourceBlock'
  px4_internal_block_getPX4Abso_T obj_ky;// '<S13>/PX4 Timestamp'
  px4_internal_block_PWM_FLIGHT_T obj_dl;// '<Root>/PX4 PWM Output'
  px4_internal_block_Publisher__T obj_my;// '<S588>/SinkBlock'
  px4_internal_block_Publisher__T obj_a4;// '<S586>/SinkBlock'
  px4_internal_block_Publisher__T obj_pa;// '<S584>/SinkBlock'
  px4_internal_block_Publisher__T obj_pt;// '<S581>/SinkBlock'
  px4_internal_block_Publisher__T obj_px;// '<S579>/SinkBlock'
  px4_internal_block_Publisher__T obj_hf;// '<S577>/SinkBlock'
  real_T UD_DSTATE;                    // '<S572>/UD'
  real_T UD_DSTATE_j;                  // '<S22>/UD'
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK;              // '<S571>/fromWS_Signal 1'

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK_i;            // '<S21>/fromWS_Signal 1'

  real32_T Filter_DSTATE;              // '<S496>/Filter'
  real32_T Integrator_DSTATE;          // '<S501>/Integrator'
  real32_T Filter_DSTATE_j;            // '<S446>/Filter'
  real32_T Integrator_DSTATE_c;        // '<S451>/Integrator'
  real32_T Filter_DSTATE_h;            // '<S546>/Filter'
  real32_T Integrator_DSTATE_l;        // '<S551>/Integrator'
  real32_T Filter_DSTATE_g;            // '<S276>/Filter'
  real32_T Integrator_DSTATE_k;        // '<S281>/Integrator'
  real32_T Filter_DSTATE_i;            // '<S54>/Filter'
  real32_T Integrator_DSTATE_e;        // '<S59>/Integrator'
  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK;              // '<S571>/fromWS_Signal 1'

  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK_n;            // '<S21>/fromWS_Signal 1'

  int8_T Filter_PrevResetState;        // '<S276>/Filter'
  int8_T Integrator_PrevResetState;    // '<S281>/Integrator'
  DW_PX4Timestamp_FLIGHT_hexaco_T PX4Timestamp_pna;// '<S11>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexaco_T PX4Timestamp_p;// '<S11>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexaco_T PX4Timestamp_o;// '<S11>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexaco_T PX4Timestamp_n;// '<S11>/PX4 Timestamp'
  DW_PX4Timestamp_FLIGHT_hexaco_T PX4Timestamp;// '<S11>/PX4 Timestamp'
  DW_ReadParameter_FLIGHT_hexac_T ReadParameter_pnaevv;// '<S18>/Read Parameter' 
  DW_ReadParameter3_FLIGHT_hexa_T ReadParameter3_pn;// '<S19>/Read Parameter3'
  DW_ReadParameter2_FLIGHT_hexa_T ReadParameter2_pn;// '<S19>/Read Parameter2'
  DW_ReadParameter1_FLIGHT_hexa_T ReadParameter1_pnae;// '<S19>/Read Parameter1' 
  DW_ReadParameter_FLIGHT_hex_f_T ReadParameter_pna;// '<S19>/Read Parameter'
  DW_ReadParameter3_FLIGHT_hexa_T ReadParameter3_p;// '<S19>/Read Parameter3'
  DW_ReadParameter2_FLIGHT_hexa_T ReadParameter2_p;// '<S19>/Read Parameter2'
  DW_ReadParameter1_FLIGHT_hexa_T ReadParameter1_pn;// '<S19>/Read Parameter1'
  DW_ReadParameter_FLIGHT_hex_f_T ReadParameter_pn;// '<S19>/Read Parameter'
  DW_ReadParameter_FLIGHT_hexac_T ReadParameter_p;// '<S18>/Read Parameter'
};

// Parameters (default storage)
struct P_FLIGHT_hexacopter_T_ {
  real_T SampleTime;                   // Variable: SampleTime
                                          //  Referenced by:
                                          //    '<S2>/Read Parameter'
                                          //    '<S2>/Read Parameter1'
                                          //    '<S2>/Read Parameter10'
                                          //    '<S2>/Read Parameter9'
                                          //    '<S8>/Read Parameter'
                                          //    '<S8>/Read Parameter1'
                                          //    '<S8>/Read Parameter2'
                                          //    '<S8>/Read Parameter3'
                                          //    '<S8>/Read Parameter4'
                                          //    '<S8>/Read Parameter5'
                                          //    '<S8>/Read Parameter6'
                                          //    '<S8>/Read Parameter7'
                                          //    '<S8>/Read Parameter8'
                                          //    '<S18>/Read Parameter'
                                          //    '<S19>/Read Parameter'
                                          //    '<S19>/Read Parameter1'
                                          //    '<S19>/Read Parameter2'
                                          //    '<S19>/Read Parameter3'
                                          //    '<S189>/Read Parameter1'
                                          //    '<S191>/Read Parameter'
                                          //    '<S191>/Read Parameter1'
                                          //    '<S191>/Read Parameter2'
                                          //    '<S191>/Read Parameter3'
                                          //    '<S192>/Read Parameter'
                                          //    '<S193>/Read Parameter'
                                          //    '<S569>/Read Parameter'

  real32_T MAX_CONTROL_ANGLE_PITCH;    // Variable: MAX_CONTROL_ANGLE_PITCH
                                          //  Referenced by:
                                          //    '<S9>/Gain5'
                                          //    '<S16>/Gain2'

  real32_T MAX_CONTROL_ANGLE_RATE_Y;   // Variable: MAX_CONTROL_ANGLE_RATE_Y
                                          //  Referenced by:
                                          //    '<S9>/Gain6'
                                          //    '<S16>/Gain3'
                                          //    '<S190>/Gain3'

  real32_T MAX_CONTROL_ANGLE_ROLL;     // Variable: MAX_CONTROL_ANGLE_ROLL
                                          //  Referenced by:
                                          //    '<S9>/Gain4'
                                          //    '<S16>/Gain1'

  real_T TransferFcnFirstOrder_ICPrevOut;
                              // Mask Parameter: TransferFcnFirstOrder_ICPrevOut
                                 //  Referenced by: '<S22>/UD'

  real_T TransferFcnFirstOrder_ICPrevO_m;
                              // Mask Parameter: TransferFcnFirstOrder_ICPrevO_m
                                 //  Referenced by: '<S572>/UD'

  real_T TransferFcnFirstOrder_PoleZ;
                                  // Mask Parameter: TransferFcnFirstOrder_PoleZ
                                     //  Referenced by: '<S22>/Gain'

  real_T TransferFcnFirstOrder_PoleZ_o;
                                // Mask Parameter: TransferFcnFirstOrder_PoleZ_o
                                   //  Referenced by: '<S572>/Gain'

  real32_T PIDController4_InitialCondition;
                              // Mask Parameter: PIDController4_InitialCondition
                                 //  Referenced by: '<S54>/Filter'

  real32_T PIDController4_InitialConditi_l;
                              // Mask Parameter: PIDController4_InitialConditi_l
                                 //  Referenced by: '<S276>/Filter'

  real32_T PIDController2_InitialCondition;
                              // Mask Parameter: PIDController2_InitialCondition
                                 //  Referenced by: '<S496>/Filter'

  real32_T PIDController1_InitialCondition;
                              // Mask Parameter: PIDController1_InitialCondition
                                 //  Referenced by: '<S446>/Filter'

  real32_T PIDController6_InitialCondition;
                              // Mask Parameter: PIDController6_InitialCondition
                                 //  Referenced by: '<S546>/Filter'

  real32_T PIDController4_InitialConditi_a;
                              // Mask Parameter: PIDController4_InitialConditi_a
                                 //  Referenced by: '<S59>/Integrator'

  real32_T PIDController4_InitialConditi_i;
                              // Mask Parameter: PIDController4_InitialConditi_i
                                 //  Referenced by: '<S281>/Integrator'

  real32_T PIDController2_InitialConditi_c;
                              // Mask Parameter: PIDController2_InitialConditi_c
                                 //  Referenced by: '<S501>/Integrator'

  real32_T PIDController1_InitialConditi_c;
                              // Mask Parameter: PIDController1_InitialConditi_c
                                 //  Referenced by: '<S451>/Integrator'

  real32_T PIDController6_InitialConditi_h;
                              // Mask Parameter: PIDController6_InitialConditi_h
                                 //  Referenced by: '<S551>/Integrator'

  real32_T PIDController4_LowerSaturationL;
                              // Mask Parameter: PIDController4_LowerSaturationL
                                 //  Referenced by:
                                 //    '<S66>/Saturation'
                                 //    '<S51>/DeadZone'

  real32_T PIDController4_LowerSaturatio_a;
                              // Mask Parameter: PIDController4_LowerSaturatio_a
                                 //  Referenced by: '<S235>/Saturation'

  real32_T PIDController4_LowerSaturatio_f;
                              // Mask Parameter: PIDController4_LowerSaturatio_f
                                 //  Referenced by:
                                 //    '<S288>/Saturation'
                                 //    '<S273>/DeadZone'

  real32_T PIDController4_UpperSaturationL;
                              // Mask Parameter: PIDController4_UpperSaturationL
                                 //  Referenced by:
                                 //    '<S66>/Saturation'
                                 //    '<S51>/DeadZone'

  real32_T PIDController4_UpperSaturatio_h;
                              // Mask Parameter: PIDController4_UpperSaturatio_h
                                 //  Referenced by: '<S235>/Saturation'

  real32_T PIDController4_UpperSaturati_hy;
                              // Mask Parameter: PIDController4_UpperSaturati_hy
                                 //  Referenced by:
                                 //    '<S288>/Saturation'
                                 //    '<S273>/DeadZone'

  real32_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S17>/Constant'

  uint16_T CompareToConstant_const_l;
                                    // Mask Parameter: CompareToConstant_const_l
                                       //  Referenced by: '<S568>/Constant'

  uint16_T CompareToConstant3_const; // Mask Parameter: CompareToConstant3_const
                                        //  Referenced by: '<S412>/Constant'

  uint16_T CompareToConstant_const_g;
                                    // Mask Parameter: CompareToConstant_const_g
                                       //  Referenced by: '<S182>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0;// Computed Parameter: Out1_Y0
                                            //  Referenced by: '<S406>/Out1'

  px4_Bus_vehicle_local_position Constant_Value;// Computed Parameter: Constant_Value
                                                   //  Referenced by: '<S403>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0_d;  // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S409>/Out1'

  px4_Bus_vehicle_odometry Constant_Value_g;// Computed Parameter: Constant_Value_g
                                               //  Referenced by: '<S408>/Constant'

  px4_Bus_actuator_outputs Constant_Value_f;// Computed Parameter: Constant_Value_f
                                               //  Referenced by: '<S578>/Constant'

  px4_Bus_actuator_motors Constant_Value_m;// Computed Parameter: Constant_Value_m
                                              //  Referenced by: '<S576>/Constant'

  px4_Bus_input_rc Out1_Y0_p;          // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S414>/Out1'

  px4_Bus_input_rc Constant_Value_b;   // Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<S413>/Constant'

  px4_Bus_vehicle_local_position_setpoint Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                              //  Referenced by: '<S583>/Constant'

  px4_Bus_vehicle_attitude_setpoint Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                        //  Referenced by: '<S580>/Constant'

  px4_Bus_vehicle_angular_velocity Out1_Y0_pn;// Computed Parameter: Out1_Y0_pn
                                                 //  Referenced by: '<S407>/Out1'

  px4_Bus_vehicle_angular_velocity Constant_Value_gk;// Computed Parameter: Constant_Value_gk
                                                        //  Referenced by: '<S404>/Constant'

  px4_Bus_vehicle_rates_setpoint Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                     //  Referenced by: '<S585>/Constant'

  px4_Bus_vehicle_torque_setpoint Constant_Value_n1;// Computed Parameter: Constant_Value_n1
                                                       //  Referenced by: '<S587>/Constant'

  real_T ReadParameter1_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S3>/Read Parameter1'

  real_T ReadParameter13_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S3>/Read Parameter13'

  real_T ReadParameter2_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S3>/Read Parameter2'

  real_T ReadParameter3_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S3>/Read Parameter3'

  real_T ReadParameter4_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S3>/Read Parameter4'

  real_T ReadParameter5_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S3>/Read Parameter5'

  real_T Constant1_Value;              // Expression: 100
                                          //  Referenced by: '<S3>/Constant1'

  real_T Constant2_Value;              // Expression: 100
                                          //  Referenced by: '<S3>/Constant2'

  real_T Constant3_Value;              // Expression: 100
                                          //  Referenced by: '<S3>/Constant3'

  real_T Constant4_Value;              // Expression: 100
                                          //  Referenced by: '<S3>/Constant4'

  real_T Constant5_Value;              // Expression: 100
                                          //  Referenced by: '<S3>/Constant5'

  real_T Constant_Value_mc;            // Expression: 100
                                          //  Referenced by: '<S3>/Constant'

  real_T doublet_Y0;                   // Computed Parameter: doublet_Y0
                                          //  Referenced by: '<S18>/doublet'

  real_T doublet_Y0_a;                 // Computed Parameter: doublet_Y0_a
                                          //  Referenced by: '<S569>/doublet'

  real_T Constant_Value_c;             // Expression: 1094
                                          //  Referenced by: '<S9>/Constant'

  real_T Gain_Gain;                    // Expression: 1/800
                                          //  Referenced by: '<S9>/Gain'

  real_T Gain_Gain_j;                  // Expression: 0.01
                                          //  Referenced by: '<S183>/Gain'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<S183>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S183>/Saturation'

  real_T Gain_Gain_h;                  // Expression: 0.01
                                          //  Referenced by: '<S184>/Gain'

  real_T Saturation_UpperSat_m;        // Expression: 1
                                          //  Referenced by: '<S184>/Saturation'

  real_T Saturation_LowerSat_o;        // Expression: 0
                                          //  Referenced by: '<S184>/Saturation'

  real_T Gain_Gain_c;                  // Expression: 0.01
                                          //  Referenced by: '<S185>/Gain'

  real_T Saturation_UpperSat_b;        // Expression: 1
                                          //  Referenced by: '<S185>/Saturation'

  real_T Saturation_LowerSat_g;        // Expression: 0
                                          //  Referenced by: '<S185>/Saturation'

  real_T Gain_Gain_n;                  // Expression: 0.01
                                          //  Referenced by: '<S186>/Gain'

  real_T Saturation_UpperSat_be;       // Expression: 1
                                          //  Referenced by: '<S186>/Saturation'

  real_T Saturation_LowerSat_e;        // Expression: 0
                                          //  Referenced by: '<S186>/Saturation'

  real_T Gain_Gain_f;                  // Expression: 0.01
                                          //  Referenced by: '<S187>/Gain'

  real_T Saturation_UpperSat_d;        // Expression: 1
                                          //  Referenced by: '<S187>/Saturation'

  real_T Saturation_LowerSat_l;        // Expression: 0
                                          //  Referenced by: '<S187>/Saturation'

  real_T Gain_Gain_m;                  // Expression: 0.01
                                          //  Referenced by: '<S188>/Gain'

  real_T Saturation_UpperSat_i;        // Expression: 1
                                          //  Referenced by: '<S188>/Saturation'

  real_T Saturation_LowerSat_n;        // Expression: 0
                                          //  Referenced by: '<S188>/Saturation'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S2>/Gain1'

  real32_T Gain_Gain_m3;               // Computed Parameter: Gain_Gain_m3
                                          //  Referenced by: '<S2>/Gain'

  real32_T des_p_Y0;                   // Computed Parameter: des_p_Y0
                                          //  Referenced by: '<S2>/des_p'

  real32_T des_q_Y0;                   // Computed Parameter: des_q_Y0
                                          //  Referenced by: '<S2>/des_q'

  real32_T Gain1_Gain_g;               // Computed Parameter: Gain1_Gain_g
                                          //  Referenced by: '<S76>/Gain1'

  real32_T Gain1_Gain_c;               // Computed Parameter: Gain1_Gain_c
                                          //  Referenced by: '<S77>/Gain1'

  real32_T Constant_Value_h;           // Computed Parameter: Constant_Value_h
                                          //  Referenced by: '<S18>/Constant'

  real32_T Gain1_Gain_d;               // Computed Parameter: Gain1_Gain_d
                                          //  Referenced by: '<S20>/Gain1'

  real32_T DeadZone3_Start;            // Computed Parameter: DeadZone3_Start
                                          //  Referenced by: '<S16>/Dead Zone3'

  real32_T DeadZone3_End;              // Computed Parameter: DeadZone3_End
                                          //  Referenced by: '<S16>/Dead Zone3'

  real32_T Saturation9_UpperSat;     // Computed Parameter: Saturation9_UpperSat
                                        //  Referenced by: '<S16>/Saturation9'

  real32_T Saturation9_LowerSat;     // Computed Parameter: Saturation9_LowerSat
                                        //  Referenced by: '<S16>/Saturation9'

  real32_T throttle_Y0;                // Computed Parameter: throttle_Y0
                                          //  Referenced by: '<S19>/throttle'

  real32_T Constant1_Value_n;          // Computed Parameter: Constant1_Value_n
                                          //  Referenced by: '<S49>/Constant1'

  real32_T Constant_Value_bi;          // Computed Parameter: Constant_Value_bi
                                          //  Referenced by: '<S19>/Constant'

  real32_T Gain_Gain_d;                // Computed Parameter: Gain_Gain_d
                                          //  Referenced by: '<S19>/Gain'

  real32_T Filter_gainval;             // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S54>/Filter'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S59>/Integrator'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S19>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S19>/Saturation1'

  real32_T Clamping_zero_Value;       // Computed Parameter: Clamping_zero_Value
                                         //  Referenced by: '<S49>/Clamping_zero'

  real32_T DeadZone2_Start;            // Computed Parameter: DeadZone2_Start
                                          //  Referenced by: '<S16>/Dead Zone2'

  real32_T DeadZone2_End;              // Computed Parameter: DeadZone2_End
                                          //  Referenced by: '<S16>/Dead Zone2'

  real32_T Saturation3_UpperSat;     // Computed Parameter: Saturation3_UpperSat
                                        //  Referenced by: '<S16>/Saturation3'

  real32_T Saturation3_LowerSat;     // Computed Parameter: Saturation3_LowerSat
                                        //  Referenced by: '<S16>/Saturation3'

  real32_T DeadZone4_Start;            // Computed Parameter: DeadZone4_Start
                                          //  Referenced by: '<S16>/Dead Zone4'

  real32_T DeadZone4_End;              // Computed Parameter: DeadZone4_End
                                          //  Referenced by: '<S16>/Dead Zone4'

  real32_T Saturation10_UpperSat;   // Computed Parameter: Saturation10_UpperSat
                                       //  Referenced by: '<S16>/Saturation10'

  real32_T Saturation10_LowerSat;   // Computed Parameter: Saturation10_LowerSat
                                       //  Referenced by: '<S16>/Saturation10'

  real32_T Gain_Gain_e;                // Computed Parameter: Gain_Gain_e
                                          //  Referenced by: '<S16>/Gain'

  real32_T DeadZone1_Start;            // Computed Parameter: DeadZone1_Start
                                          //  Referenced by: '<S16>/Dead Zone1'

  real32_T DeadZone1_End;              // Computed Parameter: DeadZone1_End
                                          //  Referenced by: '<S16>/Dead Zone1'

  real32_T Saturation1_UpperSat_d; // Computed Parameter: Saturation1_UpperSat_d
                                      //  Referenced by: '<S16>/Saturation1'

  real32_T Saturation1_LowerSat_b; // Computed Parameter: Saturation1_LowerSat_b
                                      //  Referenced by: '<S16>/Saturation1'

  real32_T des_vz_Y0;                  // Computed Parameter: des_vz_Y0
                                          //  Referenced by: '<S189>/des_vz'

  real32_T throttle_Y0_o;              // Computed Parameter: throttle_Y0_o
                                          //  Referenced by: '<S191>/throttle'

  real32_T log_alt_Y0;                 // Computed Parameter: log_alt_Y0
                                          //  Referenced by: '<S191>/log_alt'

  real32_T Constant1_Value_m;          // Computed Parameter: Constant1_Value_m
                                          //  Referenced by: '<S271>/Constant1'

  real32_T Constant_Value_e;           // Computed Parameter: Constant_Value_e
                                          //  Referenced by: '<S191>/Constant'

  real32_T Gain_Gain_b;                // Computed Parameter: Gain_Gain_b
                                          //  Referenced by: '<S191>/Gain'

  real32_T Filter_gainval_h;           // Computed Parameter: Filter_gainval_h
                                          //  Referenced by: '<S276>/Filter'

  real32_T Integrator_gainval_l;     // Computed Parameter: Integrator_gainval_l
                                        //  Referenced by: '<S281>/Integrator'

  real32_T Saturation1_UpperSat_e; // Computed Parameter: Saturation1_UpperSat_e
                                      //  Referenced by: '<S191>/Saturation1'

  real32_T Saturation1_LowerSat_bn;
                                  // Computed Parameter: Saturation1_LowerSat_bn
                                     //  Referenced by: '<S191>/Saturation1'

  real32_T Clamping_zero_Value_f;   // Computed Parameter: Clamping_zero_Value_f
                                       //  Referenced by: '<S271>/Clamping_zero'

  real32_T des_vxvy_Y0;                // Computed Parameter: des_vxvy_Y0
                                          //  Referenced by: '<S192>/des_vxvy'

  real32_T des_pitch_Y0;               // Computed Parameter: des_pitch_Y0
                                          //  Referenced by: '<S193>/des_pitch'

  real32_T des_roll_Y0;                // Computed Parameter: des_roll_Y0
                                          //  Referenced by: '<S193>/des_roll'

  real32_T Gain_Gain_a;                // Computed Parameter: Gain_Gain_a
                                          //  Referenced by: '<S351>/Gain'

  real32_T Saturation_UpperSat_e;   // Computed Parameter: Saturation_UpperSat_e
                                       //  Referenced by: '<S193>/Saturation'

  real32_T Saturation_LowerSat_a;   // Computed Parameter: Saturation_LowerSat_a
                                       //  Referenced by: '<S193>/Saturation'

  real32_T Gain1_Gain_i;               // Computed Parameter: Gain1_Gain_i
                                          //  Referenced by: '<S193>/Gain1'

  real32_T des_z_Y0;                   // Computed Parameter: des_z_Y0
                                          //  Referenced by: '<S4>/des_z'

  real32_T Constant_Value_k[2];        // Computed Parameter: Constant_Value_k
                                          //  Referenced by: '<S4>/Constant'

  real32_T DeadZone4_Start_d;          // Computed Parameter: DeadZone4_Start_d
                                          //  Referenced by: '<S190>/Dead Zone4'

  real32_T DeadZone4_End_l;            // Computed Parameter: DeadZone4_End_l
                                          //  Referenced by: '<S190>/Dead Zone4'

  real32_T Saturation10_UpperSat_m;
                                  // Computed Parameter: Saturation10_UpperSat_m
                                     //  Referenced by: '<S190>/Saturation10'

  real32_T Saturation10_LowerSat_n;
                                  // Computed Parameter: Saturation10_LowerSat_n
                                     //  Referenced by: '<S190>/Saturation10'

  real32_T Gain_Gain_o;                // Computed Parameter: Gain_Gain_o
                                          //  Referenced by: '<S190>/Gain'

  real32_T DeadZone2_Start_k;          // Computed Parameter: DeadZone2_Start_k
                                          //  Referenced by: '<S190>/Dead Zone2'

  real32_T DeadZone2_End_k;            // Computed Parameter: DeadZone2_End_k
                                          //  Referenced by: '<S190>/Dead Zone2'

  real32_T Saturation3_UpperSat_b; // Computed Parameter: Saturation3_UpperSat_b
                                      //  Referenced by: '<S190>/Saturation3'

  real32_T Saturation3_LowerSat_a; // Computed Parameter: Saturation3_LowerSat_a
                                      //  Referenced by: '<S190>/Saturation3'

  real32_T Constant_Value_gq;          // Computed Parameter: Constant_Value_gq
                                          //  Referenced by: '<S569>/Constant'

  real32_T Gain1_Gain_p;               // Computed Parameter: Gain1_Gain_p
                                          //  Referenced by: '<S570>/Gain1'

  real32_T Constant3_Value_e;          // Computed Parameter: Constant3_Value_e
                                          //  Referenced by: '<S9>/Constant3'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<S9>/Gain3'

  real32_T DeadZone_Start;             // Computed Parameter: DeadZone_Start
                                          //  Referenced by: '<S9>/Dead Zone'

  real32_T DeadZone_End;               // Computed Parameter: DeadZone_End
                                          //  Referenced by: '<S9>/Dead Zone'

  real32_T Saturation3_UpperSat_b4;
                                  // Computed Parameter: Saturation3_UpperSat_b4
                                     //  Referenced by: '<S9>/Saturation3'

  real32_T Saturation3_LowerSat_j; // Computed Parameter: Saturation3_LowerSat_j
                                      //  Referenced by: '<S9>/Saturation3'

  real32_T DeadZone3_Start_p;          // Computed Parameter: DeadZone3_Start_p
                                          //  Referenced by: '<S9>/Dead Zone3'

  real32_T DeadZone3_End_l;            // Computed Parameter: DeadZone3_End_l
                                          //  Referenced by: '<S9>/Dead Zone3'

  real32_T Saturation_UpperSat_o;   // Computed Parameter: Saturation_UpperSat_o
                                       //  Referenced by: '<S9>/Saturation'

  real32_T Saturation_LowerSat_el; // Computed Parameter: Saturation_LowerSat_el
                                      //  Referenced by: '<S9>/Saturation'

  real32_T Constant1_Value_l;          // Computed Parameter: Constant1_Value_l
                                          //  Referenced by: '<S9>/Constant1'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S9>/Gain2'

  real32_T DeadZone2_Start_o;          // Computed Parameter: DeadZone2_Start_o
                                          //  Referenced by: '<S9>/Dead Zone2'

  real32_T DeadZone2_End_e;            // Computed Parameter: DeadZone2_End_e
                                          //  Referenced by: '<S9>/Dead Zone2'

  real32_T Saturation1_UpperSat_l; // Computed Parameter: Saturation1_UpperSat_l
                                      //  Referenced by: '<S9>/Saturation1'

  real32_T Saturation1_LowerSat_i; // Computed Parameter: Saturation1_LowerSat_i
                                      //  Referenced by: '<S9>/Saturation1'

  real32_T Constant2_Value_i;          // Computed Parameter: Constant2_Value_i
                                          //  Referenced by: '<S9>/Constant2'

  real32_T Gain1_Gain_m;               // Computed Parameter: Gain1_Gain_m
                                          //  Referenced by: '<S9>/Gain1'

  real32_T DeadZone1_Start_c;          // Computed Parameter: DeadZone1_Start_c
                                          //  Referenced by: '<S9>/Dead Zone1'

  real32_T DeadZone1_End_m;            // Computed Parameter: DeadZone1_End_m
                                          //  Referenced by: '<S9>/Dead Zone1'

  real32_T Saturation2_UpperSat;     // Computed Parameter: Saturation2_UpperSat
                                        //  Referenced by: '<S9>/Saturation2'

  real32_T Saturation2_LowerSat;     // Computed Parameter: Saturation2_LowerSat
                                        //  Referenced by: '<S9>/Saturation2'

  real32_T tau_roll_Y0;                // Computed Parameter: tau_roll_Y0
                                          //  Referenced by: '<S8>/tau_roll'

  real32_T tau_pitch_Y0;               // Computed Parameter: tau_pitch_Y0
                                          //  Referenced by: '<S8>/tau_pitch'

  real32_T tau_yaw_Y0;                 // Computed Parameter: tau_yaw_Y0
                                          //  Referenced by: '<S8>/tau_yaw'

  real32_T Constant_Value_j4;          // Computed Parameter: Constant_Value_j4
                                          //  Referenced by: '<S8>/Constant'

  real32_T Filter_gainval_o;           // Computed Parameter: Filter_gainval_o
                                          //  Referenced by: '<S496>/Filter'

  real32_T Integrator_gainval_i;     // Computed Parameter: Integrator_gainval_i
                                        //  Referenced by: '<S501>/Integrator'

  real32_T Constant1_Value_f;          // Computed Parameter: Constant1_Value_f
                                          //  Referenced by: '<S8>/Constant1'

  real32_T Filter_gainval_f;           // Computed Parameter: Filter_gainval_f
                                          //  Referenced by: '<S446>/Filter'

  real32_T Integrator_gainval_im;   // Computed Parameter: Integrator_gainval_im
                                       //  Referenced by: '<S451>/Integrator'

  real32_T Constant2_Value_m;          // Computed Parameter: Constant2_Value_m
                                          //  Referenced by: '<S8>/Constant2'

  real32_T Filter_gainval_m;           // Computed Parameter: Filter_gainval_m
                                          //  Referenced by: '<S546>/Filter'

  real32_T Integrator_gainval_e;     // Computed Parameter: Integrator_gainval_e
                                        //  Referenced by: '<S551>/Integrator'

  real32_T Merge1_InitialOutput;     // Computed Parameter: Merge1_InitialOutput
                                        //  Referenced by: '<Root>/Merge1'

  real32_T Constant1_Value_i[6];       // Computed Parameter: Constant1_Value_i
                                          //  Referenced by: '<S11>/Constant1'

  real32_T Saturation_UpperSat_ep; // Computed Parameter: Saturation_UpperSat_ep
                                      //  Referenced by: '<S573>/Saturation'

  real32_T Saturation_LowerSat_p;   // Computed Parameter: Saturation_LowerSat_p
                                       //  Referenced by: '<S573>/Saturation'

  real32_T Constant_Value_ez;          // Computed Parameter: Constant_Value_ez
                                          //  Referenced by: '<S573>/Constant'

  real32_T Gain_Gain_mg;               // Computed Parameter: Gain_Gain_mg
                                          //  Referenced by: '<S573>/Gain'

  real32_T Constant_Value_kf;          // Computed Parameter: Constant_Value_kf
                                          //  Referenced by: '<S183>/Constant'

  real32_T Constant_Value_ms;          // Computed Parameter: Constant_Value_ms
                                          //  Referenced by: '<S184>/Constant'

  real32_T Constant_Value_ii;          // Computed Parameter: Constant_Value_ii
                                          //  Referenced by: '<S185>/Constant'

  real32_T Constant_Value_j4x;         // Computed Parameter: Constant_Value_j4x
                                          //  Referenced by: '<S186>/Constant'

  real32_T Constant_Value_l;           // Computed Parameter: Constant_Value_l
                                          //  Referenced by: '<S187>/Constant'

  real32_T Constant_Value_o;           // Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S188>/Constant'

  real32_T Constant_Value_bm[4];       // Computed Parameter: Constant_Value_bm
                                          //  Referenced by: '<S11>/Constant'

  real32_T Constant_Value_a;           // Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<Root>/Constant'

  real32_T u2_Gain;                    // Computed Parameter: u2_Gain
                                          //  Referenced by: '<S582>/1//2'

  real32_T Constant_Value_gqy;         // Computed Parameter: Constant_Value_gqy
                                          //  Referenced by: '<S12>/Constant'

  real32_T Constant_Value_ll;          // Computed Parameter: Constant_Value_ll
                                          //  Referenced by: '<S14>/Constant'

  real32_T Merge_InitialOutput;       // Computed Parameter: Merge_InitialOutput
                                         //  Referenced by: '<Root>/Merge'

  uint32_T Constant2_Value_e;          // Computed Parameter: Constant2_Value_e
                                          //  Referenced by: '<S11>/Constant2'

  uint16_T PWM_Y0;                     // Computed Parameter: PWM_Y0
                                          //  Referenced by: '<S5>/PWM'

  uint16_T Output_Limits1_UpperSat;
                                  // Computed Parameter: Output_Limits1_UpperSat
                                     //  Referenced by: '<S5>/Output_Limits1'

  uint16_T Output_Limits1_LowerSat;
                                  // Computed Parameter: Output_Limits1_LowerSat
                                     //  Referenced by: '<S5>/Output_Limits1'

  int8_T Constant_Value_jc;            // Computed Parameter: Constant_Value_jc
                                          //  Referenced by: '<S49>/Constant'

  int8_T Constant2_Value_mj;           // Computed Parameter: Constant2_Value_mj
                                          //  Referenced by: '<S49>/Constant2'

  int8_T Constant3_Value_es;           // Computed Parameter: Constant3_Value_es
                                          //  Referenced by: '<S49>/Constant3'

  int8_T Constant4_Value_j;            // Computed Parameter: Constant4_Value_j
                                          //  Referenced by: '<S49>/Constant4'

  int8_T Constant_Value_mn;            // Computed Parameter: Constant_Value_mn
                                          //  Referenced by: '<S271>/Constant'

  int8_T Constant2_Value_p;            // Computed Parameter: Constant2_Value_p
                                          //  Referenced by: '<S271>/Constant2'

  int8_T Constant3_Value_n;            // Computed Parameter: Constant3_Value_n
                                          //  Referenced by: '<S271>/Constant3'

  int8_T Constant4_Value_i;            // Computed Parameter: Constant4_Value_i
                                          //  Referenced by: '<S271>/Constant4'

};

// Real-time Model Data Structure
struct tag_RTM_FLIGHT_hexacopter_T {
  const char_T * volatile errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
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
//  Block '<S16>/Display' : Unused code path elimination
//  Block '<S16>/Display1' : Unused code path elimination
//  Block '<S16>/Display2' : Unused code path elimination
//  Block '<S16>/Display3' : Unused code path elimination
//  Block '<S22>/Data Type Duplicate' : Unused code path elimination
//  Block '<S121>/Data Type Duplicate' : Unused code path elimination
//  Block '<S121>/Data Type Propagation' : Unused code path elimination
//  Block '<S172>/Data Type Duplicate' : Unused code path elimination
//  Block '<S172>/Data Type Propagation' : Unused code path elimination
//  Block '<Root>/Display' : Unused code path elimination
//  Block '<S190>/Data Type Conversion1' : Unused code path elimination
//  Block '<S190>/Data Type Conversion2' : Unused code path elimination
//  Block '<S190>/Dead Zone1' : Unused code path elimination
//  Block '<S190>/Dead Zone3' : Unused code path elimination
//  Block '<S190>/Display' : Unused code path elimination
//  Block '<S190>/Display1' : Unused code path elimination
//  Block '<S190>/Display2' : Unused code path elimination
//  Block '<S190>/Display3' : Unused code path elimination
//  Block '<S190>/Fcn1' : Unused code path elimination
//  Block '<S190>/Fcn2' : Unused code path elimination
//  Block '<S190>/Gain1' : Unused code path elimination
//  Block '<S190>/Gain2' : Unused code path elimination
//  Block '<S190>/Saturation1' : Unused code path elimination
//  Block '<S190>/Saturation9' : Unused code path elimination
//  Block '<S403>/NOT' : Unused code path elimination
//  Block '<S404>/NOT' : Unused code path elimination
//  Block '<S408>/NOT' : Unused code path elimination
//  Block '<S405>/Signal Copy' : Unused code path elimination
//  Block '<S405>/Signal Copy1' : Unused code path elimination
//  Block '<S405>/Signal Copy2' : Unused code path elimination
//  Block '<S411>/Bitwise Operator' : Unused code path elimination
//  Block '<S411>/Data Type Conversion' : Unused code path elimination
//  Block '<S411>/Data Type Conversion1' : Unused code path elimination
//  Block '<S411>/Data Type Conversion2' : Unused code path elimination
//  Block '<S411>/Gain' : Unused code path elimination
//  Block '<S411>/Gain1' : Unused code path elimination
//  Block '<S413>/NOT' : Unused code path elimination
//  Block '<Root>/Scope1' : Unused code path elimination
//  Block '<Root>/Scope2' : Unused code path elimination
//  Block '<S9>/Display' : Unused code path elimination
//  Block '<S9>/Display1' : Unused code path elimination
//  Block '<S9>/Display2' : Unused code path elimination
//  Block '<S9>/Display3' : Unused code path elimination
//  Block '<S9>/Display5' : Unused code path elimination
//  Block '<S9>/Display6' : Unused code path elimination
//  Block '<S9>/Display7' : Unused code path elimination
//  Block '<S572>/Data Type Duplicate' : Unused code path elimination
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<S6>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S6>/Data Type Conversion9' : Eliminate redundant data type conversion
//  Block '<S11>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S11>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S11>/Data Type Conversion3' : Eliminate redundant data type conversion


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
//  '<S3>'   : 'FLIGHT_hexacopter/Fault_Injection'
//  '<S4>'   : 'FLIGHT_hexacopter/If Action Subsystem'
//  '<S5>'   : 'FLIGHT_hexacopter/Mixer'
//  '<S6>'   : 'FLIGHT_hexacopter/Read uORB'
//  '<S7>'   : 'FLIGHT_hexacopter/Remote Control'
//  '<S8>'   : 'FLIGHT_hexacopter/SAS'
//  '<S9>'   : 'FLIGHT_hexacopter/Stabilized_Mode'
//  '<S10>'  : 'FLIGHT_hexacopter/quat2eul'
//  '<S11>'  : 'FLIGHT_hexacopter/uORB_actuator_outputs2'
//  '<S12>'  : 'FLIGHT_hexacopter/vehicle_attitude_setpoint'
//  '<S13>'  : 'FLIGHT_hexacopter/vehicle_local_position_setpoint'
//  '<S14>'  : 'FLIGHT_hexacopter/vehicle_rate_setpoint'
//  '<S15>'  : 'FLIGHT_hexacopter/vehicle_torque_setpoint'
//  '<S16>'  : 'FLIGHT_hexacopter/Altitude_Mode/Altitude_Mode_Stick2Command'
//  '<S17>'  : 'FLIGHT_hexacopter/Altitude_Mode/Compare To Constant'
//  '<S18>'  : 'FLIGHT_hexacopter/Altitude_Mode/Enabled Subsystem'
//  '<S19>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller'
//  '<S20>'  : 'FLIGHT_hexacopter/Altitude_Mode/Enabled Subsystem/Degrees to Radians'
//  '<S21>'  : 'FLIGHT_hexacopter/Altitude_Mode/Enabled Subsystem/Signal Editor'
//  '<S22>'  : 'FLIGHT_hexacopter/Altitude_Mode/Enabled Subsystem/Transfer Fcn First Order'
//  '<S23>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4'
//  '<S24>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Anti-windup'
//  '<S25>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/D Gain'
//  '<S26>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/External Derivative'
//  '<S27>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Filter'
//  '<S28>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Filter ICs'
//  '<S29>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/I Gain'
//  '<S30>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Ideal P Gain'
//  '<S31>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S32>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Integrator'
//  '<S33>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Integrator ICs'
//  '<S34>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/N Copy'
//  '<S35>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/N Gain'
//  '<S36>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/P Copy'
//  '<S37>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Parallel P Gain'
//  '<S38>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Reset Signal'
//  '<S39>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Saturation'
//  '<S40>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Saturation Fdbk'
//  '<S41>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Sum'
//  '<S42>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Sum Fdbk'
//  '<S43>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tracking Mode'
//  '<S44>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tracking Mode Sum'
//  '<S45>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tsamp - Integral'
//  '<S46>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tsamp - Ngain'
//  '<S47>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/postSat Signal'
//  '<S48>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/preSat Signal'
//  '<S49>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel'
//  '<S50>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S51>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S52>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/D Gain/External Parameters'
//  '<S53>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/External Derivative/Error'
//  '<S54>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Filter/Disc. Forward Euler Filter'
//  '<S55>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Filter ICs/Internal IC - Filter'
//  '<S56>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/I Gain/External Parameters'
//  '<S57>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S58>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S59>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Integrator/Discrete'
//  '<S60>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Integrator ICs/Internal IC'
//  '<S61>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/N Copy/Disabled'
//  '<S62>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/N Gain/External Parameters'
//  '<S63>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/P Copy/Disabled'
//  '<S64>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Parallel P Gain/External Parameters'
//  '<S65>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Reset Signal/Disabled'
//  '<S66>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Saturation/Enabled'
//  '<S67>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S68>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Sum/Sum_PID'
//  '<S69>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S70>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tracking Mode/Disabled'
//  '<S71>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S72>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S73>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S74>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S75>'  : 'FLIGHT_hexacopter/Altitude_Mode/Vz Controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S76>'  : 'FLIGHT_hexacopter/CAS/Degrees to Radians'
//  '<S77>'  : 'FLIGHT_hexacopter/CAS/Degrees to Radians1'
//  '<S78>'  : 'FLIGHT_hexacopter/CAS/PID Controller3'
//  '<S79>'  : 'FLIGHT_hexacopter/CAS/PID Controller4'
//  '<S80>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Anti-windup'
//  '<S81>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/D Gain'
//  '<S82>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/External Derivative'
//  '<S83>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Filter'
//  '<S84>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Filter ICs'
//  '<S85>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/I Gain'
//  '<S86>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Ideal P Gain'
//  '<S87>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Ideal P Gain Fdbk'
//  '<S88>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Integrator'
//  '<S89>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Integrator ICs'
//  '<S90>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/N Copy'
//  '<S91>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/N Gain'
//  '<S92>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/P Copy'
//  '<S93>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Parallel P Gain'
//  '<S94>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Reset Signal'
//  '<S95>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation'
//  '<S96>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation Fdbk'
//  '<S97>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Sum'
//  '<S98>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Sum Fdbk'
//  '<S99>'  : 'FLIGHT_hexacopter/CAS/PID Controller3/Tracking Mode'
//  '<S100>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tracking Mode Sum'
//  '<S101>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tsamp - Integral'
//  '<S102>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tsamp - Ngain'
//  '<S103>' : 'FLIGHT_hexacopter/CAS/PID Controller3/postSat Signal'
//  '<S104>' : 'FLIGHT_hexacopter/CAS/PID Controller3/preSat Signal'
//  '<S105>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Anti-windup/Disabled'
//  '<S106>' : 'FLIGHT_hexacopter/CAS/PID Controller3/D Gain/Disabled'
//  '<S107>' : 'FLIGHT_hexacopter/CAS/PID Controller3/External Derivative/Disabled'
//  '<S108>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Filter/Disabled'
//  '<S109>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Filter ICs/Disabled'
//  '<S110>' : 'FLIGHT_hexacopter/CAS/PID Controller3/I Gain/Disabled'
//  '<S111>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Ideal P Gain/Passthrough'
//  '<S112>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S113>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Integrator/Disabled'
//  '<S114>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Integrator ICs/Disabled'
//  '<S115>' : 'FLIGHT_hexacopter/CAS/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S116>' : 'FLIGHT_hexacopter/CAS/PID Controller3/N Gain/Disabled'
//  '<S117>' : 'FLIGHT_hexacopter/CAS/PID Controller3/P Copy/Disabled'
//  '<S118>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Parallel P Gain/External Parameters'
//  '<S119>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Reset Signal/Disabled'
//  '<S120>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation/External'
//  '<S121>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation/External/Saturation Dynamic'
//  '<S122>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Saturation Fdbk/Disabled'
//  '<S123>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Sum/Passthrough_P'
//  '<S124>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Sum Fdbk/Disabled'
//  '<S125>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tracking Mode/Disabled'
//  '<S126>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S127>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S128>' : 'FLIGHT_hexacopter/CAS/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S129>' : 'FLIGHT_hexacopter/CAS/PID Controller3/postSat Signal/Forward_Path'
//  '<S130>' : 'FLIGHT_hexacopter/CAS/PID Controller3/preSat Signal/Forward_Path'
//  '<S131>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Anti-windup'
//  '<S132>' : 'FLIGHT_hexacopter/CAS/PID Controller4/D Gain'
//  '<S133>' : 'FLIGHT_hexacopter/CAS/PID Controller4/External Derivative'
//  '<S134>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Filter'
//  '<S135>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Filter ICs'
//  '<S136>' : 'FLIGHT_hexacopter/CAS/PID Controller4/I Gain'
//  '<S137>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Ideal P Gain'
//  '<S138>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Ideal P Gain Fdbk'
//  '<S139>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Integrator'
//  '<S140>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Integrator ICs'
//  '<S141>' : 'FLIGHT_hexacopter/CAS/PID Controller4/N Copy'
//  '<S142>' : 'FLIGHT_hexacopter/CAS/PID Controller4/N Gain'
//  '<S143>' : 'FLIGHT_hexacopter/CAS/PID Controller4/P Copy'
//  '<S144>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Parallel P Gain'
//  '<S145>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Reset Signal'
//  '<S146>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation'
//  '<S147>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation Fdbk'
//  '<S148>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Sum'
//  '<S149>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Sum Fdbk'
//  '<S150>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tracking Mode'
//  '<S151>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tracking Mode Sum'
//  '<S152>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tsamp - Integral'
//  '<S153>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tsamp - Ngain'
//  '<S154>' : 'FLIGHT_hexacopter/CAS/PID Controller4/postSat Signal'
//  '<S155>' : 'FLIGHT_hexacopter/CAS/PID Controller4/preSat Signal'
//  '<S156>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Anti-windup/Disabled'
//  '<S157>' : 'FLIGHT_hexacopter/CAS/PID Controller4/D Gain/Disabled'
//  '<S158>' : 'FLIGHT_hexacopter/CAS/PID Controller4/External Derivative/Disabled'
//  '<S159>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Filter/Disabled'
//  '<S160>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Filter ICs/Disabled'
//  '<S161>' : 'FLIGHT_hexacopter/CAS/PID Controller4/I Gain/Disabled'
//  '<S162>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Ideal P Gain/Passthrough'
//  '<S163>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S164>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Integrator/Disabled'
//  '<S165>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Integrator ICs/Disabled'
//  '<S166>' : 'FLIGHT_hexacopter/CAS/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S167>' : 'FLIGHT_hexacopter/CAS/PID Controller4/N Gain/Disabled'
//  '<S168>' : 'FLIGHT_hexacopter/CAS/PID Controller4/P Copy/Disabled'
//  '<S169>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Parallel P Gain/External Parameters'
//  '<S170>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Reset Signal/Disabled'
//  '<S171>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation/External'
//  '<S172>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation/External/Saturation Dynamic'
//  '<S173>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Saturation Fdbk/Disabled'
//  '<S174>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Sum/Passthrough_P'
//  '<S175>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Sum Fdbk/Disabled'
//  '<S176>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tracking Mode/Disabled'
//  '<S177>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S178>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S179>' : 'FLIGHT_hexacopter/CAS/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S180>' : 'FLIGHT_hexacopter/CAS/PID Controller4/postSat Signal/Forward_Path'
//  '<S181>' : 'FLIGHT_hexacopter/CAS/PID Controller4/preSat Signal/Forward_Path'
//  '<S182>' : 'FLIGHT_hexacopter/Fault_Injection/Compare To Constant'
//  '<S183>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference'
//  '<S184>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference1'
//  '<S185>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference2'
//  '<S186>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference3'
//  '<S187>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference4'
//  '<S188>' : 'FLIGHT_hexacopter/Fault_Injection/Subsystem Reference5'
//  '<S189>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller'
//  '<S190>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude_Mode_Stick2Command'
//  '<S191>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller'
//  '<S192>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller'
//  '<S193>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller'
//  '<S194>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4'
//  '<S195>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Anti-windup'
//  '<S196>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/D Gain'
//  '<S197>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/External Derivative'
//  '<S198>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Filter'
//  '<S199>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Filter ICs'
//  '<S200>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/I Gain'
//  '<S201>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Ideal P Gain'
//  '<S202>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S203>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Integrator'
//  '<S204>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Integrator ICs'
//  '<S205>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/N Copy'
//  '<S206>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/N Gain'
//  '<S207>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/P Copy'
//  '<S208>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Parallel P Gain'
//  '<S209>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Reset Signal'
//  '<S210>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Saturation'
//  '<S211>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Saturation Fdbk'
//  '<S212>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Sum'
//  '<S213>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Sum Fdbk'
//  '<S214>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tracking Mode'
//  '<S215>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tracking Mode Sum'
//  '<S216>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tsamp - Integral'
//  '<S217>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tsamp - Ngain'
//  '<S218>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/postSat Signal'
//  '<S219>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/preSat Signal'
//  '<S220>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Anti-windup/Disabled'
//  '<S221>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/D Gain/Disabled'
//  '<S222>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/External Derivative/Disabled'
//  '<S223>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Filter/Disabled'
//  '<S224>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Filter ICs/Disabled'
//  '<S225>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/I Gain/Disabled'
//  '<S226>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S227>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S228>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Integrator/Disabled'
//  '<S229>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Integrator ICs/Disabled'
//  '<S230>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S231>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/N Gain/Disabled'
//  '<S232>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/P Copy/Disabled'
//  '<S233>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Parallel P Gain/External Parameters'
//  '<S234>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Reset Signal/Disabled'
//  '<S235>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Saturation/Enabled'
//  '<S236>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S237>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Sum/Passthrough_P'
//  '<S238>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S239>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tracking Mode/Disabled'
//  '<S240>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S241>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S242>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S243>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S244>' : 'FLIGHT_hexacopter/If Action Subsystem/Altitude Controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S245>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4'
//  '<S246>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Anti-windup'
//  '<S247>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/D Gain'
//  '<S248>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/External Derivative'
//  '<S249>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Filter'
//  '<S250>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Filter ICs'
//  '<S251>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/I Gain'
//  '<S252>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Ideal P Gain'
//  '<S253>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S254>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Integrator'
//  '<S255>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Integrator ICs'
//  '<S256>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/N Copy'
//  '<S257>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/N Gain'
//  '<S258>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/P Copy'
//  '<S259>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Parallel P Gain'
//  '<S260>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Reset Signal'
//  '<S261>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Saturation'
//  '<S262>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Saturation Fdbk'
//  '<S263>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Sum'
//  '<S264>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Sum Fdbk'
//  '<S265>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tracking Mode'
//  '<S266>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tracking Mode Sum'
//  '<S267>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tsamp - Integral'
//  '<S268>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tsamp - Ngain'
//  '<S269>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/postSat Signal'
//  '<S270>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/preSat Signal'
//  '<S271>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel'
//  '<S272>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S273>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S274>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/D Gain/External Parameters'
//  '<S275>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/External Derivative/Error'
//  '<S276>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Filter/Disc. Forward Euler Filter'
//  '<S277>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Filter ICs/Internal IC - Filter'
//  '<S278>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/I Gain/External Parameters'
//  '<S279>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S280>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S281>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Integrator/Discrete'
//  '<S282>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Integrator ICs/Internal IC'
//  '<S283>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/N Copy/Disabled'
//  '<S284>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/N Gain/External Parameters'
//  '<S285>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/P Copy/Disabled'
//  '<S286>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Parallel P Gain/External Parameters'
//  '<S287>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Reset Signal/External Reset'
//  '<S288>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Saturation/Enabled'
//  '<S289>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S290>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Sum/Sum_PID'
//  '<S291>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S292>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tracking Mode/Disabled'
//  '<S293>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S294>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S295>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S296>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S297>' : 'FLIGHT_hexacopter/If Action Subsystem/Vz Controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S298>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude'
//  '<S299>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Anti-windup'
//  '<S300>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/D Gain'
//  '<S301>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/External Derivative'
//  '<S302>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Filter'
//  '<S303>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Filter ICs'
//  '<S304>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/I Gain'
//  '<S305>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Ideal P Gain'
//  '<S306>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S307>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Integrator'
//  '<S308>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Integrator ICs'
//  '<S309>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/N Copy'
//  '<S310>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/N Gain'
//  '<S311>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/P Copy'
//  '<S312>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Parallel P Gain'
//  '<S313>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Reset Signal'
//  '<S314>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Saturation'
//  '<S315>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Saturation Fdbk'
//  '<S316>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Sum'
//  '<S317>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Sum Fdbk'
//  '<S318>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tracking Mode'
//  '<S319>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tracking Mode Sum'
//  '<S320>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tsamp - Integral'
//  '<S321>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tsamp - Ngain'
//  '<S322>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/postSat Signal'
//  '<S323>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/preSat Signal'
//  '<S324>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Anti-windup/Disabled'
//  '<S325>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/D Gain/Disabled'
//  '<S326>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/External Derivative/Disabled'
//  '<S327>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Filter/Disabled'
//  '<S328>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Filter ICs/Disabled'
//  '<S329>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/I Gain/Disabled'
//  '<S330>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S331>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Ideal P Gain Fdbk/Disabled'
//  '<S332>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Integrator/Disabled'
//  '<S333>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Integrator ICs/Disabled'
//  '<S334>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/N Copy/Disabled wSignal Specification'
//  '<S335>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/N Gain/Disabled'
//  '<S336>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/P Copy/Disabled'
//  '<S337>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Parallel P Gain/External Parameters'
//  '<S338>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Reset Signal/Disabled'
//  '<S339>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Saturation/Passthrough'
//  '<S340>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Saturation Fdbk/Disabled'
//  '<S341>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Sum/Passthrough_P'
//  '<S342>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Sum Fdbk/Disabled'
//  '<S343>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S344>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S345>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S346>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S347>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/postSat Signal/Forward_Path'
//  '<S348>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Pos Controller/PID_Altitude/preSat Signal/Forward_Path'
//  '<S349>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/NED2Body1'
//  '<S350>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude'
//  '<S351>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/NED2Body1/Calculate Transformation Matrix'
//  '<S352>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Anti-windup'
//  '<S353>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/D Gain'
//  '<S354>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/External Derivative'
//  '<S355>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Filter'
//  '<S356>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Filter ICs'
//  '<S357>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/I Gain'
//  '<S358>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Ideal P Gain'
//  '<S359>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S360>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Integrator'
//  '<S361>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Integrator ICs'
//  '<S362>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/N Copy'
//  '<S363>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/N Gain'
//  '<S364>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/P Copy'
//  '<S365>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Parallel P Gain'
//  '<S366>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Reset Signal'
//  '<S367>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Saturation'
//  '<S368>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Saturation Fdbk'
//  '<S369>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Sum'
//  '<S370>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Sum Fdbk'
//  '<S371>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tracking Mode'
//  '<S372>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tracking Mode Sum'
//  '<S373>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tsamp - Integral'
//  '<S374>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tsamp - Ngain'
//  '<S375>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/postSat Signal'
//  '<S376>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/preSat Signal'
//  '<S377>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Anti-windup/Disabled'
//  '<S378>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/D Gain/Disabled'
//  '<S379>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/External Derivative/Disabled'
//  '<S380>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Filter/Disabled'
//  '<S381>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Filter ICs/Disabled'
//  '<S382>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/I Gain/Disabled'
//  '<S383>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S384>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Ideal P Gain Fdbk/Disabled'
//  '<S385>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Integrator/Disabled'
//  '<S386>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Integrator ICs/Disabled'
//  '<S387>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/N Copy/Disabled wSignal Specification'
//  '<S388>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/N Gain/Disabled'
//  '<S389>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/P Copy/Disabled'
//  '<S390>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Parallel P Gain/External Parameters'
//  '<S391>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Reset Signal/Disabled'
//  '<S392>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Saturation/Passthrough'
//  '<S393>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Saturation Fdbk/Disabled'
//  '<S394>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Sum/Passthrough_P'
//  '<S395>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Sum Fdbk/Disabled'
//  '<S396>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S397>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S398>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S399>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S400>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/postSat Signal/Forward_Path'
//  '<S401>' : 'FLIGHT_hexacopter/If Action Subsystem/XY Velocity Controller/PID_Altitude/preSat Signal/Forward_Path'
//  '<S402>' : 'FLIGHT_hexacopter/Mixer/pwm_out2'
//  '<S403>' : 'FLIGHT_hexacopter/Read uORB/PX4 uORB Read'
//  '<S404>' : 'FLIGHT_hexacopter/Read uORB/PX4 uORB Read1'
//  '<S405>' : 'FLIGHT_hexacopter/Read uORB/Vehicle Attitude'
//  '<S406>' : 'FLIGHT_hexacopter/Read uORB/PX4 uORB Read/Enabled Subsystem'
//  '<S407>' : 'FLIGHT_hexacopter/Read uORB/PX4 uORB Read1/Enabled Subsystem'
//  '<S408>' : 'FLIGHT_hexacopter/Read uORB/Vehicle Attitude/PX4 uORB Read'
//  '<S409>' : 'FLIGHT_hexacopter/Read uORB/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'
//  '<S410>' : 'FLIGHT_hexacopter/Remote Control/Arm1'
//  '<S411>' : 'FLIGHT_hexacopter/Remote Control/Radio Control Transmitter'
//  '<S412>' : 'FLIGHT_hexacopter/Remote Control/Arm1/Compare To Constant3'
//  '<S413>' : 'FLIGHT_hexacopter/Remote Control/Radio Control Transmitter/PX4 uORB Read'
//  '<S414>' : 'FLIGHT_hexacopter/Remote Control/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S415>' : 'FLIGHT_hexacopter/SAS/PID Controller1'
//  '<S416>' : 'FLIGHT_hexacopter/SAS/PID Controller2'
//  '<S417>' : 'FLIGHT_hexacopter/SAS/PID Controller6'
//  '<S418>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Anti-windup'
//  '<S419>' : 'FLIGHT_hexacopter/SAS/PID Controller1/D Gain'
//  '<S420>' : 'FLIGHT_hexacopter/SAS/PID Controller1/External Derivative'
//  '<S421>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Filter'
//  '<S422>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Filter ICs'
//  '<S423>' : 'FLIGHT_hexacopter/SAS/PID Controller1/I Gain'
//  '<S424>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Ideal P Gain'
//  '<S425>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Ideal P Gain Fdbk'
//  '<S426>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Integrator'
//  '<S427>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Integrator ICs'
//  '<S428>' : 'FLIGHT_hexacopter/SAS/PID Controller1/N Copy'
//  '<S429>' : 'FLIGHT_hexacopter/SAS/PID Controller1/N Gain'
//  '<S430>' : 'FLIGHT_hexacopter/SAS/PID Controller1/P Copy'
//  '<S431>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Parallel P Gain'
//  '<S432>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Reset Signal'
//  '<S433>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Saturation'
//  '<S434>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Saturation Fdbk'
//  '<S435>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Sum'
//  '<S436>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Sum Fdbk'
//  '<S437>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Tracking Mode'
//  '<S438>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Tracking Mode Sum'
//  '<S439>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Tsamp - Integral'
//  '<S440>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Tsamp - Ngain'
//  '<S441>' : 'FLIGHT_hexacopter/SAS/PID Controller1/postSat Signal'
//  '<S442>' : 'FLIGHT_hexacopter/SAS/PID Controller1/preSat Signal'
//  '<S443>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Anti-windup/Passthrough'
//  '<S444>' : 'FLIGHT_hexacopter/SAS/PID Controller1/D Gain/External Parameters'
//  '<S445>' : 'FLIGHT_hexacopter/SAS/PID Controller1/External Derivative/Error'
//  '<S446>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S447>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S448>' : 'FLIGHT_hexacopter/SAS/PID Controller1/I Gain/External Parameters'
//  '<S449>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Ideal P Gain/Passthrough'
//  '<S450>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S451>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Integrator/Discrete'
//  '<S452>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Integrator ICs/Internal IC'
//  '<S453>' : 'FLIGHT_hexacopter/SAS/PID Controller1/N Copy/Disabled'
//  '<S454>' : 'FLIGHT_hexacopter/SAS/PID Controller1/N Gain/External Parameters'
//  '<S455>' : 'FLIGHT_hexacopter/SAS/PID Controller1/P Copy/Disabled'
//  '<S456>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Parallel P Gain/External Parameters'
//  '<S457>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Reset Signal/Disabled'
//  '<S458>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Saturation/Passthrough'
//  '<S459>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Saturation Fdbk/Disabled'
//  '<S460>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Sum/Sum_PID'
//  '<S461>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Sum Fdbk/Disabled'
//  '<S462>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Tracking Mode/Disabled'
//  '<S463>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S464>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S465>' : 'FLIGHT_hexacopter/SAS/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S466>' : 'FLIGHT_hexacopter/SAS/PID Controller1/postSat Signal/Forward_Path'
//  '<S467>' : 'FLIGHT_hexacopter/SAS/PID Controller1/preSat Signal/Forward_Path'
//  '<S468>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Anti-windup'
//  '<S469>' : 'FLIGHT_hexacopter/SAS/PID Controller2/D Gain'
//  '<S470>' : 'FLIGHT_hexacopter/SAS/PID Controller2/External Derivative'
//  '<S471>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Filter'
//  '<S472>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Filter ICs'
//  '<S473>' : 'FLIGHT_hexacopter/SAS/PID Controller2/I Gain'
//  '<S474>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Ideal P Gain'
//  '<S475>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Ideal P Gain Fdbk'
//  '<S476>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Integrator'
//  '<S477>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Integrator ICs'
//  '<S478>' : 'FLIGHT_hexacopter/SAS/PID Controller2/N Copy'
//  '<S479>' : 'FLIGHT_hexacopter/SAS/PID Controller2/N Gain'
//  '<S480>' : 'FLIGHT_hexacopter/SAS/PID Controller2/P Copy'
//  '<S481>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Parallel P Gain'
//  '<S482>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Reset Signal'
//  '<S483>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Saturation'
//  '<S484>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Saturation Fdbk'
//  '<S485>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Sum'
//  '<S486>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Sum Fdbk'
//  '<S487>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Tracking Mode'
//  '<S488>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Tracking Mode Sum'
//  '<S489>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Tsamp - Integral'
//  '<S490>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Tsamp - Ngain'
//  '<S491>' : 'FLIGHT_hexacopter/SAS/PID Controller2/postSat Signal'
//  '<S492>' : 'FLIGHT_hexacopter/SAS/PID Controller2/preSat Signal'
//  '<S493>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Anti-windup/Passthrough'
//  '<S494>' : 'FLIGHT_hexacopter/SAS/PID Controller2/D Gain/External Parameters'
//  '<S495>' : 'FLIGHT_hexacopter/SAS/PID Controller2/External Derivative/Error'
//  '<S496>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S497>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S498>' : 'FLIGHT_hexacopter/SAS/PID Controller2/I Gain/External Parameters'
//  '<S499>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Ideal P Gain/Passthrough'
//  '<S500>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S501>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Integrator/Discrete'
//  '<S502>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Integrator ICs/Internal IC'
//  '<S503>' : 'FLIGHT_hexacopter/SAS/PID Controller2/N Copy/Disabled'
//  '<S504>' : 'FLIGHT_hexacopter/SAS/PID Controller2/N Gain/External Parameters'
//  '<S505>' : 'FLIGHT_hexacopter/SAS/PID Controller2/P Copy/Disabled'
//  '<S506>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Parallel P Gain/External Parameters'
//  '<S507>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Reset Signal/Disabled'
//  '<S508>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Saturation/Passthrough'
//  '<S509>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Saturation Fdbk/Disabled'
//  '<S510>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Sum/Sum_PID'
//  '<S511>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Sum Fdbk/Disabled'
//  '<S512>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Tracking Mode/Disabled'
//  '<S513>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S514>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S515>' : 'FLIGHT_hexacopter/SAS/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S516>' : 'FLIGHT_hexacopter/SAS/PID Controller2/postSat Signal/Forward_Path'
//  '<S517>' : 'FLIGHT_hexacopter/SAS/PID Controller2/preSat Signal/Forward_Path'
//  '<S518>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Anti-windup'
//  '<S519>' : 'FLIGHT_hexacopter/SAS/PID Controller6/D Gain'
//  '<S520>' : 'FLIGHT_hexacopter/SAS/PID Controller6/External Derivative'
//  '<S521>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Filter'
//  '<S522>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Filter ICs'
//  '<S523>' : 'FLIGHT_hexacopter/SAS/PID Controller6/I Gain'
//  '<S524>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Ideal P Gain'
//  '<S525>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Ideal P Gain Fdbk'
//  '<S526>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Integrator'
//  '<S527>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Integrator ICs'
//  '<S528>' : 'FLIGHT_hexacopter/SAS/PID Controller6/N Copy'
//  '<S529>' : 'FLIGHT_hexacopter/SAS/PID Controller6/N Gain'
//  '<S530>' : 'FLIGHT_hexacopter/SAS/PID Controller6/P Copy'
//  '<S531>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Parallel P Gain'
//  '<S532>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Reset Signal'
//  '<S533>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Saturation'
//  '<S534>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Saturation Fdbk'
//  '<S535>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Sum'
//  '<S536>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Sum Fdbk'
//  '<S537>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Tracking Mode'
//  '<S538>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Tracking Mode Sum'
//  '<S539>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Tsamp - Integral'
//  '<S540>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Tsamp - Ngain'
//  '<S541>' : 'FLIGHT_hexacopter/SAS/PID Controller6/postSat Signal'
//  '<S542>' : 'FLIGHT_hexacopter/SAS/PID Controller6/preSat Signal'
//  '<S543>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Anti-windup/Passthrough'
//  '<S544>' : 'FLIGHT_hexacopter/SAS/PID Controller6/D Gain/External Parameters'
//  '<S545>' : 'FLIGHT_hexacopter/SAS/PID Controller6/External Derivative/Error'
//  '<S546>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Filter/Disc. Forward Euler Filter'
//  '<S547>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Filter ICs/Internal IC - Filter'
//  '<S548>' : 'FLIGHT_hexacopter/SAS/PID Controller6/I Gain/External Parameters'
//  '<S549>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Ideal P Gain/Passthrough'
//  '<S550>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Ideal P Gain Fdbk/Disabled'
//  '<S551>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Integrator/Discrete'
//  '<S552>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Integrator ICs/Internal IC'
//  '<S553>' : 'FLIGHT_hexacopter/SAS/PID Controller6/N Copy/Disabled'
//  '<S554>' : 'FLIGHT_hexacopter/SAS/PID Controller6/N Gain/External Parameters'
//  '<S555>' : 'FLIGHT_hexacopter/SAS/PID Controller6/P Copy/Disabled'
//  '<S556>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Parallel P Gain/External Parameters'
//  '<S557>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Reset Signal/Disabled'
//  '<S558>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Saturation/Passthrough'
//  '<S559>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Saturation Fdbk/Disabled'
//  '<S560>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Sum/Sum_PID'
//  '<S561>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Sum Fdbk/Disabled'
//  '<S562>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Tracking Mode/Disabled'
//  '<S563>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Tracking Mode Sum/Passthrough'
//  '<S564>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Tsamp - Integral/TsSignalSpecification'
//  '<S565>' : 'FLIGHT_hexacopter/SAS/PID Controller6/Tsamp - Ngain/Passthrough'
//  '<S566>' : 'FLIGHT_hexacopter/SAS/PID Controller6/postSat Signal/Forward_Path'
//  '<S567>' : 'FLIGHT_hexacopter/SAS/PID Controller6/preSat Signal/Forward_Path'
//  '<S568>' : 'FLIGHT_hexacopter/Stabilized_Mode/Compare To Constant'
//  '<S569>' : 'FLIGHT_hexacopter/Stabilized_Mode/Enabled Subsystem'
//  '<S570>' : 'FLIGHT_hexacopter/Stabilized_Mode/Enabled Subsystem/Degrees to Radians'
//  '<S571>' : 'FLIGHT_hexacopter/Stabilized_Mode/Enabled Subsystem/Signal Editor'
//  '<S572>' : 'FLIGHT_hexacopter/Stabilized_Mode/Enabled Subsystem/Transfer Fcn First Order'
//  '<S573>' : 'FLIGHT_hexacopter/uORB_actuator_outputs2/Normalize_pwm6'
//  '<S574>' : 'FLIGHT_hexacopter/uORB_actuator_outputs2/PX4 ULog'
//  '<S575>' : 'FLIGHT_hexacopter/uORB_actuator_outputs2/PX4 ULog1'
//  '<S576>' : 'FLIGHT_hexacopter/uORB_actuator_outputs2/PX4 ULog/PX4 uORB Message'
//  '<S577>' : 'FLIGHT_hexacopter/uORB_actuator_outputs2/PX4 ULog/PX4_log_write'
//  '<S578>' : 'FLIGHT_hexacopter/uORB_actuator_outputs2/PX4 ULog1/PX4 uORB Message'
//  '<S579>' : 'FLIGHT_hexacopter/uORB_actuator_outputs2/PX4 ULog1/PX4_log_write'
//  '<S580>' : 'FLIGHT_hexacopter/vehicle_attitude_setpoint/PX4 uORB Message'
//  '<S581>' : 'FLIGHT_hexacopter/vehicle_attitude_setpoint/PX4 uORB Write'
//  '<S582>' : 'FLIGHT_hexacopter/vehicle_attitude_setpoint/Rotation Angles to Quaternions'
//  '<S583>' : 'FLIGHT_hexacopter/vehicle_local_position_setpoint/PX4 uORB Message'
//  '<S584>' : 'FLIGHT_hexacopter/vehicle_local_position_setpoint/PX4 uORB Write'
//  '<S585>' : 'FLIGHT_hexacopter/vehicle_rate_setpoint/PX4 uORB Message'
//  '<S586>' : 'FLIGHT_hexacopter/vehicle_rate_setpoint/PX4 uORB Write'
//  '<S587>' : 'FLIGHT_hexacopter/vehicle_torque_setpoint/PX4 uORB Message'
//  '<S588>' : 'FLIGHT_hexacopter/vehicle_torque_setpoint/PX4 uORB Write'

#endif                                 // FLIGHT_hexacopter_h_

//
// File trailer for generated code.
//
// [EOF]
//
