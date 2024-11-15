//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mc_pos_controller.h
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
#ifndef RTW_HEADER_mc_pos_controller_h_
#define RTW_HEADER_mc_pos_controller_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"

extern void F550_FaultInjection_mc_pos_controller_Init(void);
extern void F550_FaultInjection_mc_pos_controller(void);
extern void F550_FaultInjection_mc_pos_controller_Term(void);

#endif                                 // RTW_HEADER_mc_pos_controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
