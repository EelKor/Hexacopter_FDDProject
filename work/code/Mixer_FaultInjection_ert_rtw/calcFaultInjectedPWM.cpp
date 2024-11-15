//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: calcFaultInjectedPWM.cpp
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
#include "rtwtypes.h"
#include "calcFaultInjectedPWM.h"
#include "Mixer_FaultInjection.h"
#include "Mixer_FaultInjection_private.h"

//
// Output and update for atomic system:
//    '<S2>/CalcFaultInjectedPWM1'
//    '<S2>/CalcFaultInjectedPWM2'
//    '<S2>/CalcFaultInjectedPWM3'
//    '<S2>/CalcFaultInjectedPWM4'
//    '<S2>/CalcFaultInjectedPWM5'
//    '<S2>/CalcFaultInjectedPWM'
//
void calcFaultInjectedPWM(real32_T rtu_PWMIn, real_T rtu_ActuatorStatus, real_T *
  rty_PWMOut, P_calcFaultInjectedPWM_T *localP)
{
  real_T u0;

  // Gain: '<S9>/Gain'
  u0 = localP->Gain_Gain * rtu_ActuatorStatus;

  // Saturate: '<S9>/Saturation1'
  if (u0 > localP->Saturation1_UpperSat) {
    u0 = localP->Saturation1_UpperSat;
  } else if (u0 < localP->Saturation1_LowerSat) {
    u0 = localP->Saturation1_LowerSat;
  }

  // Sum: '<S9>/Sum' incorporates:
  //   Constant: '<S9>/Constant'
  //   Constant: '<S9>/IDLE PWM'
  //   Product: '<S9>/Product'
  //   Saturate: '<S9>/Saturation1'
  //   Sum: '<S9>/Add'

  *rty_PWMOut = (rtu_PWMIn - Mixer_FaultInjection_P.IDLEPWM) * u0 +
    Mixer_FaultInjection_P.IDLEPWM;
}

//
// File trailer for generated code.
//
// [EOF]
//
