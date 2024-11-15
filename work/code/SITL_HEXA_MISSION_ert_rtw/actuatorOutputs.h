//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: actuatorOutputs.h
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
#ifndef actuatorOutputs_h_
#define actuatorOutputs_h_
#include <drivers/drv_hrt.h>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "MW_uORB_Write.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"

extern void SITL_HEXA_MISSION_actuatorOutputs_Init(void);
extern void SITL_HEXA_MISSION_actuatorOutputs(void);
extern void SITL_HEXA_MISSION_actuatorOutputs_Term(void);

#endif                                 // actuatorOutputs_h_

//
// File trailer for generated code.
//
// [EOF]
//
