//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mc_pos_controller.h
//
// Code generated for Simulink model 'HITL_HEXA_MISSION'.
//
// Model version                  : 5.5
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Oct 16 17:31:56 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef mc_pos_controller_h_
#define mc_pos_controller_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"

extern void HITL_HEXA_MISSION_mc_pos_controller_Init(void);
extern void HITL_HEXA_MISSION_mc_pos_controller(void);
extern void HITL_HEXA_MISSION_mc_pos_controller_Term(void);

#endif                                 // mc_pos_controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
