//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_sys_F550_FaultInjection_44.h
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
#ifndef RTW_HEADER_rt_sys_F550_FaultInjection_44_h_
#define RTW_HEADER_rt_sys_F550_FaultInjection_44_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include <uORB/topics/input_rc.h>
#include "F550_FaultInjection_types.h"

// Block signals for system '<S19>/SourceBlock'
struct B_SourceBlock_F550_FaultInjection_T {
  px4_Bus_input_rc SourceBlock_o2;     // '<S19>/SourceBlock'
  boolean_T SourceBlock_o1;            // '<S19>/SourceBlock'
};

// Block states (default storage) for system '<S19>/SourceBlock'
struct DW_SourceBlock_F550_FaultInjection_T {
  px4_internal_block_Subscriber_F550_FaultInjection_T obj;// '<S19>/SourceBlock' 
  boolean_T objisempty;                // '<S19>/SourceBlock'
};

extern void F550_FaultInjection_SourceBlock_Init
  (DW_SourceBlock_F550_FaultInjection_T *localDW);
extern void F550_FaultInjection_SourceBlock(B_SourceBlock_F550_FaultInjection_T *
  localB, DW_SourceBlock_F550_FaultInjection_T *localDW);
extern void F550_FaultInjection_SourceBlock_Term
  (DW_SourceBlock_F550_FaultInjection_T *localDW);

#endif                           // RTW_HEADER_rt_sys_F550_FaultInjection_44_h_

//
// File trailer for generated code.
//
// [EOF]
//
