//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_sys_CLAW_70.h
//
// Code generated for Simulink model 'F550_FaultInjection'.
//
// Model version                  : 4.153
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Aug 10 17:25:22 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_rt_sys_CLAW_70_h_
#define RTW_HEADER_rt_sys_CLAW_70_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "F550_FaultInjection_types.h"

// Block signals for system '<S24>/PX4 Timestamp'
struct B_PX4Timestamp_F550_FaultInjection_T {
  uint64_T PX4Timestamp;               // '<S24>/PX4 Timestamp'
};

// Block states (default storage) for system '<S24>/PX4 Timestamp'
struct DW_PX4Timestamp_F550_FaultInjection_T {
  px4_internal_block_getPX4AbsoluteTime_F550_FaultInjection_T obj;// '<S24>/PX4 Timestamp' 
  boolean_T objisempty;                // '<S24>/PX4 Timestamp'
};

extern void F550_FaultInjection_PX4Timestamp_Init
  (DW_PX4Timestamp_F550_FaultInjection_T *localDW);
extern void F550_FaultInjection_PX4Timestamp
  (B_PX4Timestamp_F550_FaultInjection_T *localB);
extern void F550_FaultInjection_PX4Timestamp_Term
  (DW_PX4Timestamp_F550_FaultInjection_T *localDW);

#endif                                 // RTW_HEADER_rt_sys_CLAW_70_h_

//
// File trailer for generated code.
//
// [EOF]
//
