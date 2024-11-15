//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: uORBReadWrite_example_data.cpp
//
// Code generated for Simulink model 'uORBReadWrite_example'.
//
// Model version                  : 1.1
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Aug  1 15:06:36 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "uORBReadWrite_example.h"

// Block parameters (default storage)
P_uORBReadWrite_example_T uORBReadWrite_example_P = {
  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S4>/Out1'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_body
    0.0F,                              // pitch_body
    0.0F,                              // yaw_body
    0.0F,                              // yaw_sp_move_rate

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q_d

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // thrust_body
    false,                             // roll_reset_integral
    false,                             // pitch_reset_integral
    false,                             // yaw_reset_integral
    false,                             // fw_control_yaw
    0U,                                // apply_flaps

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S2>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_body
    0.0F,                              // pitch_body
    0.0F,                              // yaw_body
    0.0F,                              // yaw_sp_move_rate

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q_d

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // thrust_body
    false,                             // roll_reset_integral
    false,                             // pitch_reset_integral
    false,                             // yaw_reset_integral
    false,                             // fw_control_yaw
    0U,                                // apply_flaps

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S1>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll
    0.0F,                              // pitch
    0.0F,                              // yaw

    {
      0.0F, 0.0F, 0.0F }
    // thrust_body
  },

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<Root>/Constant'

  100.0F
};

//
// File trailer for generated code.
//
// [EOF]
//
