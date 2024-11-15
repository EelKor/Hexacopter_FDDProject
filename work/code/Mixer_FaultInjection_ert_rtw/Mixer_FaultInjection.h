//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Mixer_FaultInjection.h
//
// Code generated for Simulink model 'Mixer_FaultInjection'.
//
// Model version                  : 4.142
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Aug 23 16:15:46 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Mixer_FaultInjection_h_
#define RTW_HEADER_Mixer_FaultInjection_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "Mixer_FaultInjection_types.h"
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/actuator_controls.h>
#include "calcFaultInjectedPWM.h"

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

// Block signals (default storage)
struct B_Mixer_FaultInjection_T {
  px4_Bus_actuator_outputs BusAssignment;// '<S6>/Bus Assignment'
  px4_Bus_actuator_outputs BusAssignment_m;// '<S6>/Bus Assignment'
  px4_Bus_input_rc In1;                // '<S16>/In1'
  px4_Bus_input_rc b_varargout_2;
  px4_Bus_actuator_controls In1_m;     // '<S14>/In1'
  px4_Bus_actuator_controls b_varargout_2_c;
  real_T Switch;                       // '<S1>/Switch'
  real_T Switch1;                      // '<S1>/Switch1'
};

// Block states (default storage) for system '<Root>'
struct DW_Mixer_FaultInjection_T {
  px4_internal_block_ParameterUpdate_Mixer_FaultInjection_T obj;// '<S2>/Read Parameter4' 
  px4_internal_block_ParameterUpdate_Mixer_FaultInjection_T obj_e;// '<S2>/Read Parameter3' 
  px4_internal_block_ParameterUpdate_Mixer_FaultInjection_T obj_g;// '<S2>/Read Parameter2' 
  px4_internal_block_ParameterUpdate_Mixer_FaultInjection_T obj_h;// '<S2>/Read Parameter13' 
  px4_internal_block_ParameterUpdate_Mixer_FaultInjection_T obj_o;// '<S2>/Read Parameter1' 
  px4_internal_block_ParameterUpdate_Mixer_FaultInjection_T obj_hy;// '<S2>/Read Parameter' 
  px4_internal_block_Subscriber_Mixer_FaultInjection_T obj_d;// '<S15>/SourceBlock' 
  px4_internal_block_Subscriber_Mixer_FaultInjection_T obj_f;// '<S4>/SourceBlock' 
  px4_internal_block_Publisher_Mixer_FaultInjection_T obj_hyc;// '<S18>/SinkBlock' 
};

// Parameters (default storage)
struct P_Mixer_FaultInjection_T_ {
  real_T IDLEPWM;                      // Variable: IDLEPWM
                                          //  Referenced by:
                                          //    '<S8>/Constant'
                                          //    '<S8>/IDLE PWM'
                                          //    '<S9>/Constant'
                                          //    '<S9>/IDLE PWM'
                                          //    '<S10>/Constant'
                                          //    '<S10>/IDLE PWM'
                                          //    '<S11>/Constant'
                                          //    '<S11>/IDLE PWM'
                                          //    '<S12>/Constant'
                                          //    '<S12>/IDLE PWM'
                                          //    '<S13>/Constant'
                                          //    '<S13>/IDLE PWM'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S7>/Constant'

  px4_Bus_actuator_outputs Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S17>/Constant'

  px4_Bus_input_rc Out1_Y0;            // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S16>/Out1'

  px4_Bus_input_rc Constant_Value_l;   // Computed Parameter: Constant_Value_l
                                          //  Referenced by: '<S15>/Constant'

  px4_Bus_actuator_controls Out1_Y0_c; // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S14>/Out1'

  px4_Bus_actuator_controls Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                //  Referenced by: '<S4>/Constant'

  real_T Constant1_Value;              // Expression: 1000
                                          //  Referenced by: '<S1>/Constant1'

  real_T Constant2_Value;              // Expression: 1000
                                          //  Referenced by: '<S1>/Constant2'

  real_T Constant3_Value;              // Expression: 1000
                                          //  Referenced by: '<S1>/Constant3'

  real_T Constant4_Value;              // Expression: 1000
                                          //  Referenced by: '<S1>/Constant4'

  real_T Constant5_Value;              // Expression: 1000
                                          //  Referenced by: '<S1>/Constant5'

  real_T Constant_Value_o;             // Expression: 1000
                                          //  Referenced by: '<S1>/Constant'

  real_T ReadParameter_SampleTime;     // Expression: -1
                                          //  Referenced by: '<S2>/Read Parameter'

  real_T ReadParameter1_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S2>/Read Parameter1'

  real_T ReadParameter13_SampleTime;   // Expression: -1
                                          //  Referenced by: '<S2>/Read Parameter13'

  real_T ReadParameter2_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S2>/Read Parameter2'

  real_T ReadParameter3_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S2>/Read Parameter3'

  real_T ReadParameter4_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S2>/Read Parameter4'

  real_T Constant_Value_g;             // Expression: 0
                                          //  Referenced by: '<S6>/Constant'

  real_T Constant17_Value;             // Expression: 6
                                          //  Referenced by: '<S6>/Constant17'

  P_calcFaultInjectedPWM_T CalcFaultInjectedPWM;// '<S2>/CalcFaultInjectedPWM'
  P_calcFaultInjectedPWM_T CalcFaultInjectedPWM5;// '<S2>/CalcFaultInjectedPWM5' 
  P_calcFaultInjectedPWM_T CalcFaultInjectedPWM4;// '<S2>/CalcFaultInjectedPWM4' 
  P_calcFaultInjectedPWM_T CalcFaultInjectedPWM3;// '<S2>/CalcFaultInjectedPWM3' 
  P_calcFaultInjectedPWM_T CalcFaultInjectedPWM2;// '<S2>/CalcFaultInjectedPWM2' 
  P_calcFaultInjectedPWM_T CalcFaultInjectedPWM1;// '<S2>/CalcFaultInjectedPWM1' 
};

// Real-time Model Data Structure
struct tag_RTM_Mixer_FaultInjection_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_Mixer_FaultInjection_T Mixer_FaultInjection_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_Mixer_FaultInjection_T Mixer_FaultInjection_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_Mixer_FaultInjection_T Mixer_FaultInjection_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void Mixer_FaultInjection_initialize(void);
  extern void Mixer_FaultInjection_step(void);
  extern void Mixer_FaultInjection_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_Mixer_FaultInjection_T *const Mixer_FaultInjection_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S4>/NOT' : Unused code path elimination
//  Block '<S5>/Bitwise Operator' : Unused code path elimination
//  Block '<S5>/Data Type Conversion' : Unused code path elimination
//  Block '<S5>/Data Type Conversion1' : Unused code path elimination
//  Block '<S5>/Data Type Conversion2' : Unused code path elimination
//  Block '<S5>/Gain' : Unused code path elimination
//  Block '<S5>/Gain1' : Unused code path elimination
//  Block '<S15>/NOT' : Unused code path elimination


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
//  '<Root>' : 'Mixer_FaultInjection'
//  '<S1>'   : 'Mixer_FaultInjection/Emergency Kill'
//  '<S2>'   : 'Mixer_FaultInjection/Fault_Injection_SIL'
//  '<S3>'   : 'Mixer_FaultInjection/MATLAB Function'
//  '<S4>'   : 'Mixer_FaultInjection/PX4 uORB Read'
//  '<S5>'   : 'Mixer_FaultInjection/Radio Control Transmitter'
//  '<S6>'   : 'Mixer_FaultInjection/Subsystem'
//  '<S7>'   : 'Mixer_FaultInjection/Emergency Kill/Compare To Constant'
//  '<S8>'   : 'Mixer_FaultInjection/Fault_Injection_SIL/CalcFaultInjectedPWM'
//  '<S9>'   : 'Mixer_FaultInjection/Fault_Injection_SIL/CalcFaultInjectedPWM1'
//  '<S10>'  : 'Mixer_FaultInjection/Fault_Injection_SIL/CalcFaultInjectedPWM2'
//  '<S11>'  : 'Mixer_FaultInjection/Fault_Injection_SIL/CalcFaultInjectedPWM3'
//  '<S12>'  : 'Mixer_FaultInjection/Fault_Injection_SIL/CalcFaultInjectedPWM4'
//  '<S13>'  : 'Mixer_FaultInjection/Fault_Injection_SIL/CalcFaultInjectedPWM5'
//  '<S14>'  : 'Mixer_FaultInjection/PX4 uORB Read/Enabled Subsystem'
//  '<S15>'  : 'Mixer_FaultInjection/Radio Control Transmitter/PX4 uORB Read'
//  '<S16>'  : 'Mixer_FaultInjection/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S17>'  : 'Mixer_FaultInjection/Subsystem/PX4 uORB Message'
//  '<S18>'  : 'Mixer_FaultInjection/Subsystem/PX4 uORB Write'

#endif                                 // RTW_HEADER_Mixer_FaultInjection_h_

//
// File trailer for generated code.
//
// [EOF]
//
