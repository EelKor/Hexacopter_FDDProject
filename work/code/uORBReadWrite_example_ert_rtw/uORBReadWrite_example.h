//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: uORBReadWrite_example.h
//
// Code generated for Simulink model 'uORBReadWrite_example'.
//
// Model version                  : 1.1
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Aug  1 15:06:36 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_uORBReadWrite_example_h_
#define RTW_HEADER_uORBReadWrite_example_h_
#include <drivers/drv_hrt.h>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "uORBReadWrite_example_types.h"
#include <uORB/topics/vehicle_attitude_setpoint.h>
#include <uORB/topics/vehicle_rates_setpoint.h>
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_uORBReadWrite_example_T {
  px4_Bus_vehicle_attitude_setpoint In1;// '<S4>/In1'
  px4_Bus_vehicle_attitude_setpoint b_varargout_2;
};

// Block states (default storage) for system '<Root>'
struct DW_uORBReadWrite_example_T {
  px4_internal_block_getPX4Abso_T obj; // '<Root>/PX4 Timestamp'
  px4_internal_block_Subscriber_T obj_p;// '<S2>/SourceBlock'
  px4_internal_block_Publisher__T obj_a;// '<S3>/SinkBlock'
};

// Parameters (default storage)
struct P_uORBReadWrite_example_T_ {
  px4_Bus_vehicle_attitude_setpoint Out1_Y0;// Computed Parameter: Out1_Y0
                                               //  Referenced by: '<S4>/Out1'

  px4_Bus_vehicle_attitude_setpoint Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S2>/Constant'

  px4_Bus_vehicle_rates_setpoint Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                     //  Referenced by: '<S1>/Constant'

  real32_T Constant_Value_e;           // Computed Parameter: Constant_Value_e
                                          //  Referenced by: '<Root>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_uORBReadWrite_example_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_uORBReadWrite_example_T uORBReadWrite_example_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_uORBReadWrite_example_T uORBReadWrite_example_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_uORBReadWrite_example_T uORBReadWrite_example_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void uORBReadWrite_example_initialize(void);
  extern void uORBReadWrite_example_step(void);
  extern void uORBReadWrite_example_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_uORBReadWrite_exampl_T *const uORBReadWrite_example_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/NOT' : Unused code path elimination


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
//  '<Root>' : 'uORBReadWrite_example'
//  '<S1>'   : 'uORBReadWrite_example/PX4 uORB Message'
//  '<S2>'   : 'uORBReadWrite_example/PX4 uORB Read'
//  '<S3>'   : 'uORBReadWrite_example/PX4 uORB Write'
//  '<S4>'   : 'uORBReadWrite_example/PX4 uORB Read/Enabled Subsystem'

#endif                                 // RTW_HEADER_uORBReadWrite_example_h_

//
// File trailer for generated code.
//
// [EOF]
//
