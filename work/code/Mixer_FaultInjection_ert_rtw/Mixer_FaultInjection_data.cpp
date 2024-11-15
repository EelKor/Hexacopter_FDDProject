//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Mixer_FaultInjection_data.cpp
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
#include "Mixer_FaultInjection.h"

// Block parameters (default storage)
P_Mixer_FaultInjection_T Mixer_FaultInjection_P = {
  // Variable: IDLEPWM
  //  Referenced by:
  //    '<S8>/Constant'
  //    '<S8>/IDLE PWM'
  //    '<S9>/Constant'
  //    '<S9>/IDLE PWM'
  //    '<S10>/Constant'
  //    '<S10>/IDLE PWM'
  //    '<S11>/Constant'
  //    '<S11>/IDLE PWM'
  //    '<S12>/Constant'
  //    '<S12>/IDLE PWM'
  //    '<S13>/Constant'
  //    '<S13>/IDLE PWM'

  900.0,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S7>/Constant'

  1800.0,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S17>/Constant'

  {
    (0ULL),                            // timestamp
    0U,                                // noutputs

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // output

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S16>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    0U,                                // channel_count
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source

    {
      0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S15>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    0U,                                // channel_count
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source

    {
      0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_c
  //  Referenced by: '<S14>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    // control
  },

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S4>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    // control
  },

  // Expression: 1000
  //  Referenced by: '<S1>/Constant1'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1>/Constant2'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1>/Constant3'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1>/Constant4'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1>/Constant5'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1>/Constant'

  1000.0,

  // Expression: -1
  //  Referenced by: '<S2>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S2>/Read Parameter1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S2>/Read Parameter13'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S2>/Read Parameter2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S2>/Read Parameter3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S2>/Read Parameter4'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S6>/Constant'

  0.0,

  // Expression: 6
  //  Referenced by: '<S6>/Constant17'

  6.0,

  // Start of '<S2>/CalcFaultInjectedPWM'
  {
    // Expression: 0.01
    //  Referenced by: '<S8>/Gain'

    0.01,

    // Expression: 1
    //  Referenced by: '<S8>/Saturation1'

    1.0,

    // Expression: 0
    //  Referenced by: '<S8>/Saturation1'

    0.0
  }
  ,

  // End of '<S2>/CalcFaultInjectedPWM'

  // Start of '<S2>/CalcFaultInjectedPWM5'
  {
    // Expression: 0.01
    //  Referenced by: '<S13>/Gain'

    0.01,

    // Expression: 1
    //  Referenced by: '<S13>/Saturation1'

    1.0,

    // Expression: 0
    //  Referenced by: '<S13>/Saturation1'

    0.0
  }
  ,

  // End of '<S2>/CalcFaultInjectedPWM5'

  // Start of '<S2>/CalcFaultInjectedPWM4'
  {
    // Expression: 0.01
    //  Referenced by: '<S12>/Gain'

    0.01,

    // Expression: 1
    //  Referenced by: '<S12>/Saturation1'

    1.0,

    // Expression: 0
    //  Referenced by: '<S12>/Saturation1'

    0.0
  }
  ,

  // End of '<S2>/CalcFaultInjectedPWM4'

  // Start of '<S2>/CalcFaultInjectedPWM3'
  {
    // Expression: 0.01
    //  Referenced by: '<S11>/Gain'

    0.01,

    // Expression: 1
    //  Referenced by: '<S11>/Saturation1'

    1.0,

    // Expression: 0
    //  Referenced by: '<S11>/Saturation1'

    0.0
  }
  ,

  // End of '<S2>/CalcFaultInjectedPWM3'

  // Start of '<S2>/CalcFaultInjectedPWM2'
  {
    // Expression: 0.01
    //  Referenced by: '<S10>/Gain'

    0.01,

    // Expression: 1
    //  Referenced by: '<S10>/Saturation1'

    1.0,

    // Expression: 0
    //  Referenced by: '<S10>/Saturation1'

    0.0
  }
  ,

  // End of '<S2>/CalcFaultInjectedPWM2'

  // Start of '<S2>/CalcFaultInjectedPWM1'
  {
    // Expression: 0.01
    //  Referenced by: '<S9>/Gain'

    0.01,

    // Expression: 1
    //  Referenced by: '<S9>/Saturation1'

    1.0,

    // Expression: 0
    //  Referenced by: '<S9>/Saturation1'

    0.0
  }
  // End of '<S2>/CalcFaultInjectedPWM1'
};

//
// File trailer for generated code.
//
// [EOF]
//
