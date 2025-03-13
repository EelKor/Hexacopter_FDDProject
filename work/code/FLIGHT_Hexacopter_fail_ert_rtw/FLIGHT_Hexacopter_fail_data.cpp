//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_Hexacopter_fail_data.cpp
//
// Code generated for Simulink model 'FLIGHT_Hexacopter_fail'.
//
// Model version                  : 6.19
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Fri Jan 10 13:51:29 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FLIGHT_Hexacopter_fail.h"

// Block parameters (default storage)
P_FLIGHT_Hexacopter_fail_T FLIGHT_Hexacopter_fail_P = {
  // Variable: Kdpr
  //  Referenced by: '<S219>/Derivative Gain'

  0.004F,

  // Variable: Kdrr
  //  Referenced by: '<S271>/Derivative Gain'

  0.004F,

  // Variable: Kdvz
  //  Referenced by: '<S42>/Derivative Gain'

  0.0254F,

  // Variable: Kdyr
  //  Referenced by: '<S323>/Derivative Gain'

  0.0298F,

  // Variable: Kipr
  //  Referenced by: '<S223>/Integral Gain'

  0.0F,

  // Variable: Kirr
  //  Referenced by: '<S275>/Integral Gain'

  0.0F,

  // Variable: Kivz
  //  Referenced by: '<S46>/Integral Gain'

  0.6304F,

  // Variable: Kiyr
  //  Referenced by: '<S327>/Integral Gain'

  0.0F,

  // Variable: Kpp
  //  Referenced by: '<S107>/Proportional Gain'

  3.3894F,

  // Variable: Kppr
  //  Referenced by: '<S231>/Proportional Gain'

  0.1F,

  // Variable: Kpr
  //  Referenced by: '<S157>/Proportional Gain'

  3.3894F,

  // Variable: Kprr
  //  Referenced by: '<S283>/Proportional Gain'

  0.1F,

  // Variable: Kpvz
  //  Referenced by: '<S54>/Proportional Gain'

  0.3191F,

  // Variable: Kpyr
  //  Referenced by: '<S335>/Proportional Gain'

  0.3744F,

  // Variable: MAX_CONTROL_ANGLE_PITCH
  //  Referenced by:
  //    '<S3>/Saturation1'
  //    '<S11>/Gain2'

  0.34906584F,

  // Variable: MAX_CONTROL_ANGLE_RATE_PITCH
  //  Referenced by: '<S109>/Saturation'

  6.28318548F,

  // Variable: MAX_CONTROL_ANGLE_RATE_ROLL
  //  Referenced by: '<S159>/Saturation'

  6.28318548F,

  // Variable: MAX_CONTROL_ANGLE_RATE_Y
  //  Referenced by: '<S11>/Gain3'

  2.09439516F,

  // Variable: MAX_CONTROL_ANGLE_ROLL
  //  Referenced by:
  //    '<S3>/Saturation'
  //    '<S11>/Gain1'

  0.34906584F,

  // Variable: Npr
  //  Referenced by: '<S229>/Filter Coefficient'

  50.0F,

  // Variable: Nrr
  //  Referenced by: '<S281>/Filter Coefficient'

  50.0F,

  // Variable: Nvz
  //  Referenced by: '<S52>/Filter Coefficient'

  50.0F,

  // Variable: Nyr
  //  Referenced by: '<S333>/Filter Coefficient'

  50.0F,

  // Variable: THR_HOVER
  //  Referenced by: '<S12>/Hovering Thrust'

  0.6085F,

  // Mask Parameter: PIDController4_InitialCondition
  //  Referenced by: '<S44>/Filter'

  0.0F,

  // Mask Parameter: PIDController2_InitialCondition
  //  Referenced by: '<S273>/Filter'

  0.0F,

  // Mask Parameter: PIDController1_InitialCondition
  //  Referenced by: '<S221>/Filter'

  0.0F,

  // Mask Parameter: PIDController6_InitialCondition
  //  Referenced by: '<S325>/Filter'

  0.0F,

  // Mask Parameter: PIDController4_InitialConditi_l
  //  Referenced by: '<S49>/Integrator'

  0.0F,

  // Mask Parameter: PIDController2_InitialConditi_l
  //  Referenced by: '<S278>/Integrator'

  0.0F,

  // Mask Parameter: PIDController1_InitialConditi_o
  //  Referenced by: '<S226>/Integrator'

  0.0F,

  // Mask Parameter: PIDController6_InitialConditi_g
  //  Referenced by: '<S330>/Integrator'

  0.0F,

  // Mask Parameter: PIDController4_LowerSaturationL
  //  Referenced by:
  //    '<S56>/Saturation'
  //    '<S41>/DeadZone'

  -1.0F,

  // Mask Parameter: PIDController4_LowerSaturatio_m
  //  Referenced by: '<S159>/Saturation'

  -6.28318548F,

  // Mask Parameter: PIDController2_LowerSaturationL
  //  Referenced by:
  //    '<S285>/Saturation'
  //    '<S270>/DeadZone'

  -0.2F,

  // Mask Parameter: PIDController3_LowerSaturationL
  //  Referenced by: '<S109>/Saturation'

  -6.28318548F,

  // Mask Parameter: PIDController1_LowerSaturationL
  //  Referenced by:
  //    '<S233>/Saturation'
  //    '<S218>/DeadZone'

  -0.2F,

  // Mask Parameter: PIDController6_LowerSaturationL
  //  Referenced by:
  //    '<S337>/Saturation'
  //    '<S322>/DeadZone'

  -0.4F,

  // Mask Parameter: PIDController4_UpperSaturationL
  //  Referenced by:
  //    '<S56>/Saturation'
  //    '<S41>/DeadZone'

  1.0F,

  // Mask Parameter: PIDController2_UpperSaturationL
  //  Referenced by:
  //    '<S285>/Saturation'
  //    '<S270>/DeadZone'

  0.2F,

  // Mask Parameter: PIDController1_UpperSaturationL
  //  Referenced by:
  //    '<S233>/Saturation'
  //    '<S218>/DeadZone'

  0.2F,

  // Mask Parameter: PIDController6_UpperSaturationL
  //  Referenced by:
  //    '<S337>/Saturation'
  //    '<S322>/DeadZone'

  0.4F,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S169>/Constant'

  1400U,

  // Mask Parameter: CompareToConstant3_const
  //  Referenced by: '<S66>/Constant'

  1800U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S182>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // heading
    0.0F,                              // delta_heading
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    0U,                                // heading_reset_counter
    false,                             // heading_good_for_control
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield
    false,                             // dead_reckoning
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S178>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // heading
    0.0F,                              // delta_heading
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    0U,                                // heading_reset_counter
    false,                             // heading_good_for_control
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield
    false,                             // dead_reckoning
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_b
  //  Referenced by: '<S184>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // angular_velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // orientation_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity_variance
    0U,                                // pose_frame
    0U,                                // velocity_frame
    0U,                                // reset_counter
    0,                                 // quality

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S183>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // angular_velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // orientation_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity_variance
    0U,                                // pose_frame
    0U,                                // velocity_frame
    0U,                                // reset_counter
    0,                                 // quality

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_o
  //  Referenced by: '<S187>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0.0F,                              // rssi_dbm
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
    0,                                 // link_quality
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S186>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0.0F,                              // rssi_dbm
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
    0,                                 // link_quality
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S181>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count

    {
      0U, 0U, 0U }
    ,                                  // clip_counter
    0U,                                // samples

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S180>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count

    {
      0U, 0U, 0U }
    ,                                  // clip_counter
    0U,                                // samples

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Expression: -1
  //  Referenced by: '<S4>/Read Parameter1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S4>/Read Parameter13'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S4>/Read Parameter2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S4>/Read Parameter3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S4>/Read Parameter4'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S4>/Read Parameter5'

  -1.0,

  // Expression: 100
  //  Referenced by: '<S4>/Constant1'

  100.0,

  // Expression: 100
  //  Referenced by: '<S4>/Constant2'

  100.0,

  // Expression: 100
  //  Referenced by: '<S4>/Constant3'

  100.0,

  // Expression: 100
  //  Referenced by: '<S4>/Constant4'

  100.0,

  // Expression: 100
  //  Referenced by: '<S4>/Constant5'

  100.0,

  // Expression: 100
  //  Referenced by: '<S4>/Constant'

  100.0,

  // Expression: 1100
  //  Referenced by: '<S9>/Constant'

  1100.0,

  // Expression: 1/800
  //  Referenced by: '<S9>/Gain'

  0.00125,

  // Expression: 40*pi/180
  //  Referenced by: '<S3>/Rate Limiter1'

  0.69813170079773179,

  // Expression: -40*pi/180
  //  Referenced by: '<S3>/Rate Limiter1'

  -0.69813170079773179,

  // Expression: 40*pi/180
  //  Referenced by: '<S3>/Rate Limiter2'

  0.69813170079773179,

  // Expression: -40*pi/180
  //  Referenced by: '<S3>/Rate Limiter2'

  -0.69813170079773179,

  // Expression: 0.01
  //  Referenced by: '<S170>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S170>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S170>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S171>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S171>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S171>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S172>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S172>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S172>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S173>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S173>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S173>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S174>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S174>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S174>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S175>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S175>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S175>/Saturation'

  0.0,

  // Computed Parameter: log_alt_Y0
  //  Referenced by: '<S1>/log_alt'

  0.0F,

  // Computed Parameter: vz_Y0
  //  Referenced by: '<S1>/vz'

  0.0F,

  // Computed Parameter: Constant1_Value_f
  //  Referenced by: '<S39>/Constant1'

  0.0F,

  // Computed Parameter: DeadZone4_Start
  //  Referenced by: '<S11>/Dead Zone4'

  -0.03F,

  // Computed Parameter: DeadZone4_End
  //  Referenced by: '<S11>/Dead Zone4'

  0.03F,

  // Computed Parameter: Saturation10_UpperSat
  //  Referenced by: '<S11>/Saturation10'

  1.0F,

  // Computed Parameter: Saturation10_LowerSat
  //  Referenced by: '<S11>/Saturation10'

  -1.0F,

  // Computed Parameter: Gain_Gain_fo
  //  Referenced by: '<S11>/Gain'

  -1.0F,

  // Computed Parameter: Gain_Gain_n1
  //  Referenced by: '<S12>/Gain'

  -1.0F,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S49>/Integrator'

  0.01F,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S44>/Filter'

  0.01F,

  // Computed Parameter: Saturation1_UpperSat
  //  Referenced by: '<S12>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat
  //  Referenced by: '<S12>/Saturation1'

  0.0F,

  // Computed Parameter: Clamping_zero_Value
  //  Referenced by: '<S39>/Clamping_zero'

  0.0F,

  // Computed Parameter: DeadZone3_Start
  //  Referenced by: '<S11>/Dead Zone3'

  -0.003F,

  // Computed Parameter: DeadZone3_End
  //  Referenced by: '<S11>/Dead Zone3'

  0.003F,

  // Computed Parameter: Saturation9_UpperSat
  //  Referenced by: '<S11>/Saturation9'

  1.0F,

  // Computed Parameter: Saturation9_LowerSat
  //  Referenced by: '<S11>/Saturation9'

  -1.0F,

  // Computed Parameter: DeadZone2_Start
  //  Referenced by: '<S11>/Dead Zone2'

  -0.005F,

  // Computed Parameter: DeadZone2_End
  //  Referenced by: '<S11>/Dead Zone2'

  0.005F,

  // Computed Parameter: Saturation3_UpperSat
  //  Referenced by: '<S11>/Saturation3'

  1.0F,

  // Computed Parameter: Saturation3_LowerSat
  //  Referenced by: '<S11>/Saturation3'

  -1.0F,

  // Computed Parameter: DeadZone1_Start
  //  Referenced by: '<S11>/Dead Zone1'

  -0.001F,

  // Computed Parameter: DeadZone1_End
  //  Referenced by: '<S11>/Dead Zone1'

  0.001F,

  // Computed Parameter: Saturation1_UpperSat_b
  //  Referenced by: '<S11>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat_d
  //  Referenced by: '<S11>/Saturation1'

  -1.0F,

  // Computed Parameter: Saturation_UpperSat_k
  //  Referenced by: '<S9>/Saturation'

  0.9F,

  // Computed Parameter: Saturation_LowerSat_b
  //  Referenced by: '<S9>/Saturation'

  0.0F,

  // Computed Parameter: Constant1_Value_k
  //  Referenced by: '<S9>/Constant1'

  1500.0F,

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<S9>/Gain2'

  0.0025F,

  // Computed Parameter: Saturation1_UpperSat_i
  //  Referenced by: '<S9>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat_c
  //  Referenced by: '<S9>/Saturation1'

  -1.0F,

  // Computed Parameter: Constant2_Value_b
  //  Referenced by: '<S9>/Constant2'

  1500.0F,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S9>/Gain1'

  0.0025F,

  // Computed Parameter: Saturation2_UpperSat
  //  Referenced by: '<S9>/Saturation2'

  1.0F,

  // Computed Parameter: Saturation2_LowerSat
  //  Referenced by: '<S9>/Saturation2'

  -1.0F,

  // Computed Parameter: Constant3_Value_h
  //  Referenced by: '<S9>/Constant3'

  1500.0F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<S9>/Gain3'

  0.0025F,

  // Computed Parameter: Saturation3_UpperSat_e
  //  Referenced by: '<S9>/Saturation3'

  1.0F,

  // Computed Parameter: Saturation3_LowerSat_n
  //  Referenced by: '<S9>/Saturation3'

  -1.0F,

  // Computed Parameter: Constant1_Value_c
  //  Referenced by: '<S216>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_o
  //  Referenced by: '<S268>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_j
  //  Referenced by: '<S320>/Constant1'

  0.0F,

  // Computed Parameter: Merge1_InitialOutput
  //  Referenced by: '<Root>/Merge1'

  0.0F,

  // Computed Parameter: RateLimiter1_IC
  //  Referenced by: '<S3>/Rate Limiter1'

  0.0F,

  // Computed Parameter: Saturation_LowerSat_k
  //  Referenced by: '<S3>/Saturation'

  -0.34906584F,

  // Computed Parameter: Integrator_gainval_h
  //  Referenced by: '<S278>/Integrator'

  1.0F,

  // Computed Parameter: Filter_gainval_o
  //  Referenced by: '<S273>/Filter'

  0.01F,

  // Computed Parameter: RateLimiter2_IC
  //  Referenced by: '<S3>/Rate Limiter2'

  0.0F,

  // Computed Parameter: Saturation1_LowerSat_cj
  //  Referenced by: '<S3>/Saturation1'

  -0.34906584F,

  // Computed Parameter: Integrator_gainval_g
  //  Referenced by: '<S226>/Integrator'

  1.0F,

  // Computed Parameter: Filter_gainval_h
  //  Referenced by: '<S221>/Filter'

  0.01F,

  // Computed Parameter: Integrator_gainval_a
  //  Referenced by: '<S330>/Integrator'

  1.0F,

  // Computed Parameter: Filter_gainval_f
  //  Referenced by: '<S325>/Filter'

  0.01F,

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S170>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S171>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S172>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S173>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_jb
  //  Referenced by: '<S174>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_ef
  //  Referenced by: '<S175>/Constant'

  1000.0F,

  // Computed Parameter: Clamping_zero_Value_n
  //  Referenced by: '<S320>/Clamping_zero'

  0.0F,

  // Computed Parameter: Clamping_zero_Value_j
  //  Referenced by: '<S216>/Clamping_zero'

  0.0F,

  // Computed Parameter: Clamping_zero_Value_d
  //  Referenced by: '<S268>/Clamping_zero'

  0.0F,

  // Computed Parameter: Output_Limits1_UpperSat
  //  Referenced by: '<S5>/Output_Limits1'

  2000U,

  // Computed Parameter: Output_Limits1_LowerSat
  //  Referenced by: '<S5>/Output_Limits1'

  1000U,

  // Computed Parameter: Constant_Value_ej
  //  Referenced by: '<S39>/Constant'

  1,

  // Computed Parameter: Constant2_Value_d
  //  Referenced by: '<S39>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_p
  //  Referenced by: '<S39>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_f
  //  Referenced by: '<S39>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S216>/Constant'

  1,

  // Computed Parameter: Constant2_Value_h
  //  Referenced by: '<S216>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_f
  //  Referenced by: '<S216>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_b
  //  Referenced by: '<S216>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S268>/Constant'

  1,

  // Computed Parameter: Constant2_Value_g
  //  Referenced by: '<S268>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_l
  //  Referenced by: '<S268>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_n
  //  Referenced by: '<S268>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_iw
  //  Referenced by: '<S320>/Constant'

  1,

  // Computed Parameter: Constant2_Value_l
  //  Referenced by: '<S320>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_p2
  //  Referenced by: '<S320>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_k
  //  Referenced by: '<S320>/Constant4'

  -1
};

//
// File trailer for generated code.
//
// [EOF]
//
