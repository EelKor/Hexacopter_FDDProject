//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: calcFaultInjectedPWM.h
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
#ifndef RTW_HEADER_calcFaultInjectedPWM_h_
#define RTW_HEADER_calcFaultInjectedPWM_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "Mixer_FaultInjection_types.h"

// Parameters for system: '<S2>/CalcFaultInjectedPWM1'
struct P_calcFaultInjectedPWM_T_ {
  real_T Gain_Gain;                    // Expression: 0.01
                                          //  Referenced by: '<S9>/Gain'

  real_T Saturation1_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S9>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: 0
                                          //  Referenced by: '<S9>/Saturation1'

};

extern void calcFaultInjectedPWM(real32_T rtu_PWMIn, real_T rtu_ActuatorStatus,
  real_T *rty_PWMOut, P_calcFaultInjectedPWM_T *localP);

#endif                                 // RTW_HEADER_calcFaultInjectedPWM_h_

//
// File trailer for generated code.
//
// [EOF]
//
