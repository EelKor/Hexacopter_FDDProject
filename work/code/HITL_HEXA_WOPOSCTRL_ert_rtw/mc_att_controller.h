//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mc_att_controller.h
//
// Code generated for Simulink model 'HITL_HEXA_WOPOSCTRL'.
//
// Model version                  : 4.141
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Sep 25 17:31:40 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_mc_att_controller_h_
#define RTW_HEADER_mc_att_controller_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"

extern void HITL_HEXA_WOPOSCTRL_mc_att_controller_Init(void);
extern void HITL_HEXA_WOPOSCTRL_mc_att_controller(void);
extern void HITL_HEXA_WOPOSCTRL_mc_att_controller_Term(void);

#endif                                 // RTW_HEADER_mc_att_controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
