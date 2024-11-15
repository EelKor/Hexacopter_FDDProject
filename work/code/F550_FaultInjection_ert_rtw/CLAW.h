//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CLAW.h
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
#ifndef RTW_HEADER_CLAW_h_
#define RTW_HEADER_CLAW_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern void F550_FaultInjection_CLAW_Init(void);
extern void F550_FaultInjection_CLAW(void);
extern void F550_FaultInjection_CLAW_Term(void);

#endif                                 // RTW_HEADER_CLAW_h_

//
// File trailer for generated code.
//
// [EOF]
//
