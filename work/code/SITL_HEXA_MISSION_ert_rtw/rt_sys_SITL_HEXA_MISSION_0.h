//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_sys_SITL_HEXA_MISSION_0.h
//
// Code generated for Simulink model 'SITL_HEXA_MISSION'.
//
// Model version                  : 5.6
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Sun Oct 20 19:46:11 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef rt_sys_SITL_HEXA_MISSION_0_h_
#define rt_sys_SITL_HEXA_MISSION_0_h_
#include <drivers/drv_hrt.h>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "MW_uORB_Write.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include "SITL_HEXA_MISSION_types.h"

// Block signals for system '<S6>/PX4 Timestamp'
struct B_PX4Timestamp_SITL_HEXA_MISSION_T {
  uint64_T PX4Timestamp;               // '<S6>/PX4 Timestamp'
};

// Block states (default storage) for system '<S6>/PX4 Timestamp'
struct DW_PX4Timestamp_SITL_HEXA_MISSION_T {
  px4_internal_block_getPX4AbsoluteTime_SITL_HEXA_MISSION_T obj;// '<S6>/PX4 Timestamp' 
  boolean_T objisempty;                // '<S6>/PX4 Timestamp'
};

extern void SITL_HEXA_MISSION_PX4Timestamp_Init
  (DW_PX4Timestamp_SITL_HEXA_MISSION_T *localDW);
extern void SITL_HEXA_MISSION_PX4Timestamp(B_PX4Timestamp_SITL_HEXA_MISSION_T
  *localB);
extern void SITL_HEXA_MISSION_PX4Timestamp_Term
  (DW_PX4Timestamp_SITL_HEXA_MISSION_T *localDW);

#endif                                 // rt_sys_SITL_HEXA_MISSION_0_h_

//
// File trailer for generated code.
//
// [EOF]
//
