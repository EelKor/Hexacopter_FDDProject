//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_hexacopter_data.cpp
//
// Code generated for Simulink model 'FLIGHT_hexacopter'.
//
// Model version                  : 1.150
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Fri Apr 25 14:30:21 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FLIGHT_hexacopter.h"

// Block parameters (default storage)
P_FLIGHT_hexacopter_T FLIGHT_hexacopter_P = {
  // Variable: SampleTime
  //  Referenced by:
  //    '<S2>/Read Parameter'
  //    '<S2>/Read Parameter1'
  //    '<S2>/Read Parameter10'
  //    '<S2>/Read Parameter9'
  //    '<S3>/Read Parameter'
  //    '<S3>/Read Parameter1'
  //    '<S3>/Read Parameter2'
  //    '<S19>/Read Parameter'
  //    '<S19>/Read Parameter1'
  //    '<S19>/Read Parameter2'
  //    '<S19>/Read Parameter3'
  //    '<S187>/Read Parameter1'
  //    '<S189>/Read Parameter'
  //    '<S189>/Read Parameter1'
  //    '<S189>/Read Parameter2'
  //    '<S189>/Read Parameter3'
  //    '<S190>/Read Parameter'
  //    '<S191>/Read Parameter'

  0.005,

  // Variable: SampleTime_SAS
  //  Referenced by:
  //    '<S4>/Read Parameter1'
  //    '<S4>/Read Parameter13'
  //    '<S4>/Read Parameter2'
  //    '<S4>/Read Parameter3'
  //    '<S4>/Read Parameter4'
  //    '<S4>/Read Parameter5'
  //    '<S9>/Read Parameter1'
  //    '<S9>/Read Parameter2'
  //    '<S9>/Read Parameter3'
  //    '<S9>/Read Parameter4'
  //    '<S9>/Read Parameter5'
  //    '<S9>/Read Parameter6'
  //    '<S9>/Read Parameter7'
  //    '<S9>/Read Parameter8'
  //    '<S9>/Read Parameter9'
  //    '<S9>/read_mc_rollrate_p'

  0.001,

  // Variable: MAX_CONTROL_ANGLE_PITCH
  //  Referenced by:
  //    '<S10>/Gain5'
  //    '<S18>/Gain2'

  0.52359879F,

  // Variable: MAX_CONTROL_ANGLE_RATE_Y
  //  Referenced by:
  //    '<S10>/Gain6'
  //    '<S18>/Gain3'
  //    '<S188>/Gain3'

  2.09439516F,

  // Variable: MAX_CONTROL_ANGLE_ROLL
  //  Referenced by:
  //    '<S10>/Gain4'
  //    '<S18>/Gain1'

  0.52359879F,

  // Mask Parameter: PIDController4_InitialCondition
  //  Referenced by: '<S51>/Filter'

  0.0F,

  // Mask Parameter: PIDController4_InitialConditi_l
  //  Referenced by: '<S274>/Filter'

  0.0F,

  // Mask Parameter: pid_ctrl_rollrate_InitialCondit
  //  Referenced by: '<S493>/Filter'

  0.0F,

  // Mask Parameter: pid_ctrl_pitchrate_InitialCondi
  //  Referenced by: '<S443>/Filter'

  0.0F,

  // Mask Parameter: pid_ctrl_yawrate_InitialConditi
  //  Referenced by: '<S543>/Filter'

  0.0F,

  // Mask Parameter: PIDController4_InitialConditi_a
  //  Referenced by: '<S56>/Integrator'

  0.0F,

  // Mask Parameter: PIDController4_InitialConditi_i
  //  Referenced by: '<S279>/Integrator'

  0.0F,

  // Mask Parameter: pid_ctrl_rollrate_InitialCond_c
  //  Referenced by: '<S498>/Integrator'

  0.0F,

  // Mask Parameter: pid_ctrl_pitchrate_InitialCon_c
  //  Referenced by: '<S448>/Integrator'

  0.0F,

  // Mask Parameter: pid_ctrl_yawrate_InitialCondi_h
  //  Referenced by: '<S548>/Integrator'

  0.0F,

  // Mask Parameter: PIDController4_LowerSaturationL
  //  Referenced by:
  //    '<S63>/Saturation'
  //    '<S48>/DeadZone'

  -1.0F,

  // Mask Parameter: PIDController4_LowerSaturatio_a
  //  Referenced by: '<S233>/Saturation'

  -1.0F,

  // Mask Parameter: PIDController4_LowerSaturatio_f
  //  Referenced by:
  //    '<S286>/Saturation'
  //    '<S271>/DeadZone'

  -1.0F,

  // Mask Parameter: PIDController4_UpperSaturationL
  //  Referenced by:
  //    '<S63>/Saturation'
  //    '<S48>/DeadZone'

  1.0F,

  // Mask Parameter: PIDController4_UpperSaturatio_h
  //  Referenced by: '<S233>/Saturation'

  1.0F,

  // Mask Parameter: PIDController4_UpperSaturati_hy
  //  Referenced by:
  //    '<S286>/Saturation'
  //    '<S271>/DeadZone'

  1.0F,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S180>/Constant'

  1400U,

  // Mask Parameter: CompareToConstant3_const
  //  Referenced by: '<S409>/Constant'

  1800U,

  // Mask Parameter: CompareToConstant_const_n
  //  Referenced by: '<S407>/Constant'

  1800U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S403>/Out1'

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
  //  Referenced by: '<S401>/Constant'

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

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S405>/Out1'

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

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S404>/Constant'

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
  //  Referenced by: '<S570>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // control
    0U,                                // reversible_flags

    {
      0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S411>/Out1'

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

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S410>/Constant'

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

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S577>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // acceleration

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // thrust
    0.0F,                              // yaw
    0.0F                               // yawspeed
  },

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S574>/Constant'

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
    false,                             // reset_integral
    false,                             // fw_control_yaw_wheel

    {
      0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_pn
  //  Referenced by: '<S573>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // xyz

    {
      0.0F, 0.0F, 0.0F }
    // xyz_derivative
  },

  // Computed Parameter: Constant_Value_gk
  //  Referenced by: '<S572>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // xyz

    {
      0.0F, 0.0F, 0.0F }
    // xyz_derivative
  },

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S579>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll
    0.0F,                              // pitch
    0.0F,                              // yaw

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // thrust_body
    false,                             // reset_integral

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S566>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // control_power

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

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

  // Expression: 1094
  //  Referenced by: '<S10>/Constant'

  1094.0,

  // Expression: 1/800
  //  Referenced by: '<S10>/Gain'

  0.00125,

  // Expression: 0.01
  //  Referenced by: '<S181>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S181>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S181>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S182>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S182>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S182>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S183>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S183>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S183>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S184>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S184>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S184>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S185>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S185>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S185>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S186>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S186>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S186>/Saturation'

  0.0,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S2>/Gain1'

  -1.0F,

  // Computed Parameter: Gain_Gain_m3
  //  Referenced by: '<S2>/Gain'

  -1.0F,

  // Computed Parameter: des_p_Y0
  //  Referenced by: '<S2>/des_p'

  0.0F,

  // Computed Parameter: des_q_Y0
  //  Referenced by: '<S2>/des_q'

  0.0F,

  // Computed Parameter: Gain1_Gain_g
  //  Referenced by: '<S73>/Gain1'

  0.0174532924F,

  // Computed Parameter: Gain1_Gain_c
  //  Referenced by: '<S74>/Gain1'

  0.0174532924F,

  // Computed Parameter: throttle_Y0
  //  Referenced by: '<S19>/throttle'

  0.0F,

  // Computed Parameter: Constant1_Value_n
  //  Referenced by: '<S46>/Constant1'

  0.0F,

  // Computed Parameter: Constant_Value_bi
  //  Referenced by: '<S19>/Constant'

  50.0F,

  // Computed Parameter: Gain_Gain_d
  //  Referenced by: '<S19>/Gain'

  -1.0F,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S51>/Filter'

  0.005F,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S56>/Integrator'

  0.005F,

  // Computed Parameter: Saturation1_UpperSat
  //  Referenced by: '<S19>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat
  //  Referenced by: '<S19>/Saturation1'

  0.0F,

  // Computed Parameter: Clamping_zero_Value
  //  Referenced by: '<S46>/Clamping_zero'

  0.0F,

  // Computed Parameter: DeadZone3_Start
  //  Referenced by: '<S18>/Dead Zone3'

  -0.003F,

  // Computed Parameter: DeadZone3_End
  //  Referenced by: '<S18>/Dead Zone3'

  0.003F,

  // Computed Parameter: Saturation9_UpperSat
  //  Referenced by: '<S18>/Saturation9'

  1.0F,

  // Computed Parameter: Saturation9_LowerSat
  //  Referenced by: '<S18>/Saturation9'

  -1.0F,

  // Computed Parameter: DeadZone2_Start
  //  Referenced by: '<S18>/Dead Zone2'

  -0.005F,

  // Computed Parameter: DeadZone2_End
  //  Referenced by: '<S18>/Dead Zone2'

  0.005F,

  // Computed Parameter: Saturation3_UpperSat
  //  Referenced by: '<S18>/Saturation3'

  1.0F,

  // Computed Parameter: Saturation3_LowerSat
  //  Referenced by: '<S18>/Saturation3'

  -1.0F,

  // Computed Parameter: DeadZone4_Start
  //  Referenced by: '<S18>/Dead Zone4'

  -0.03F,

  // Computed Parameter: DeadZone4_End
  //  Referenced by: '<S18>/Dead Zone4'

  0.03F,

  // Computed Parameter: Saturation10_UpperSat
  //  Referenced by: '<S18>/Saturation10'

  1.0F,

  // Computed Parameter: Saturation10_LowerSat
  //  Referenced by: '<S18>/Saturation10'

  -1.0F,

  // Computed Parameter: Gain_Gain_e
  //  Referenced by: '<S18>/Gain'

  -1.0F,

  // Computed Parameter: DeadZone1_Start
  //  Referenced by: '<S18>/Dead Zone1'

  -0.001F,

  // Computed Parameter: DeadZone1_End
  //  Referenced by: '<S18>/Dead Zone1'

  0.001F,

  // Computed Parameter: Saturation1_UpperSat_d
  //  Referenced by: '<S18>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat_b
  //  Referenced by: '<S18>/Saturation1'

  -1.0F,

  // Computed Parameter: des_vz_Y0
  //  Referenced by: '<S187>/des_vz'

  0.0F,

  // Computed Parameter: throttle_Y0_o
  //  Referenced by: '<S189>/throttle'

  0.0F,

  // Computed Parameter: log_alt_Y0
  //  Referenced by: '<S189>/log_alt'

  0.0F,

  // Computed Parameter: Constant1_Value_m
  //  Referenced by: '<S269>/Constant1'

  0.0F,

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S189>/Constant'

  50.0F,

  // Computed Parameter: Gain_Gain_b
  //  Referenced by: '<S189>/Gain'

  -1.0F,

  // Computed Parameter: Filter_gainval_h
  //  Referenced by: '<S274>/Filter'

  0.005F,

  // Computed Parameter: Integrator_gainval_l
  //  Referenced by: '<S279>/Integrator'

  0.005F,

  // Computed Parameter: Saturation1_UpperSat_e
  //  Referenced by: '<S189>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat_bn
  //  Referenced by: '<S189>/Saturation1'

  0.0F,

  // Computed Parameter: Clamping_zero_Value_f
  //  Referenced by: '<S269>/Clamping_zero'

  0.0F,

  // Computed Parameter: des_vxvy_Y0
  //  Referenced by: '<S190>/des_vxvy'

  0.0F,

  // Computed Parameter: des_pitch_Y0
  //  Referenced by: '<S191>/des_pitch'

  0.0F,

  // Computed Parameter: des_roll_Y0
  //  Referenced by: '<S191>/des_roll'

  0.0F,

  // Computed Parameter: Gain_Gain_a
  //  Referenced by: '<S349>/Gain'

  -1.0F,

  // Computed Parameter: Saturation_UpperSat_e
  //  Referenced by: '<S191>/Saturation'

  0.610865235F,

  // Computed Parameter: Saturation_LowerSat_a
  //  Referenced by: '<S191>/Saturation'

  -0.610865235F,

  // Computed Parameter: Gain1_Gain_i
  //  Referenced by: '<S191>/Gain1'

  -1.0F,

  // Computed Parameter: des_z_Y0
  //  Referenced by: '<S5>/des_z'

  0.0F,

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S5>/Constant'

  { 0.0F, 0.0F },

  // Computed Parameter: DeadZone4_Start_d
  //  Referenced by: '<S188>/Dead Zone4'

  -0.1F,

  // Computed Parameter: DeadZone4_End_l
  //  Referenced by: '<S188>/Dead Zone4'

  0.1F,

  // Computed Parameter: Saturation10_UpperSat_m
  //  Referenced by: '<S188>/Saturation10'

  1.0F,

  // Computed Parameter: Saturation10_LowerSat_n
  //  Referenced by: '<S188>/Saturation10'

  -1.0F,

  // Computed Parameter: Gain_Gain_o
  //  Referenced by: '<S188>/Gain'

  -1.0F,

  // Computed Parameter: DeadZone2_Start_k
  //  Referenced by: '<S188>/Dead Zone2'

  -0.1F,

  // Computed Parameter: DeadZone2_End_k
  //  Referenced by: '<S188>/Dead Zone2'

  0.1F,

  // Computed Parameter: Saturation3_UpperSat_b
  //  Referenced by: '<S188>/Saturation3'

  1.0F,

  // Computed Parameter: Saturation3_LowerSat_a
  //  Referenced by: '<S188>/Saturation3'

  -1.0F,

  // Computed Parameter: DeadZone3_Start_p
  //  Referenced by: '<S10>/Dead Zone3'

  -0.05F,

  // Computed Parameter: DeadZone3_End_l
  //  Referenced by: '<S10>/Dead Zone3'

  0.05F,

  // Computed Parameter: Saturation_UpperSat_o
  //  Referenced by: '<S10>/Saturation'

  0.9F,

  // Computed Parameter: Saturation_LowerSat_el
  //  Referenced by: '<S10>/Saturation'

  0.0F,

  // Computed Parameter: Constant1_Value_l
  //  Referenced by: '<S10>/Constant1'

  1514.0F,

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<S10>/Gain2'

  0.0025F,

  // Computed Parameter: DeadZone2_Start_o
  //  Referenced by: '<S10>/Dead Zone2'

  -0.005F,

  // Computed Parameter: DeadZone2_End_e
  //  Referenced by: '<S10>/Dead Zone2'

  0.005F,

  // Computed Parameter: Saturation1_UpperSat_l
  //  Referenced by: '<S10>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat_i
  //  Referenced by: '<S10>/Saturation1'

  -1.0F,

  // Computed Parameter: Constant2_Value_i
  //  Referenced by: '<S10>/Constant2'

  1514.0F,

  // Computed Parameter: Gain1_Gain_m
  //  Referenced by: '<S10>/Gain1'

  0.0025F,

  // Computed Parameter: DeadZone1_Start_c
  //  Referenced by: '<S10>/Dead Zone1'

  -0.005F,

  // Computed Parameter: DeadZone1_End_m
  //  Referenced by: '<S10>/Dead Zone1'

  0.005F,

  // Computed Parameter: Saturation2_UpperSat
  //  Referenced by: '<S10>/Saturation2'

  1.0F,

  // Computed Parameter: Saturation2_LowerSat
  //  Referenced by: '<S10>/Saturation2'

  -1.0F,

  // Computed Parameter: Constant3_Value_e
  //  Referenced by: '<S10>/Constant3'

  1514.0F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<S10>/Gain3'

  0.0025F,

  // Computed Parameter: DeadZone_Start
  //  Referenced by: '<S10>/Dead Zone'

  -0.005F,

  // Computed Parameter: DeadZone_End
  //  Referenced by: '<S10>/Dead Zone'

  0.005F,

  // Computed Parameter: Saturation3_UpperSat_b4
  //  Referenced by: '<S10>/Saturation3'

  1.0F,

  // Computed Parameter: Saturation3_LowerSat_j
  //  Referenced by: '<S10>/Saturation3'

  -1.0F,

  // Computed Parameter: tau_roll_Y0
  //  Referenced by: '<S9>/tau_roll'

  0.0F,

  // Computed Parameter: tau_pitch_Y0
  //  Referenced by: '<S9>/tau_pitch'

  0.0F,

  // Computed Parameter: tau_yaw_Y0
  //  Referenced by: '<S9>/tau_yaw'

  0.0F,

  // Computed Parameter: Constant_Value_j4
  //  Referenced by: '<S9>/Constant'

  100.0F,

  // Computed Parameter: Filter_gainval_o
  //  Referenced by: '<S493>/Filter'

  0.001F,

  // Computed Parameter: Integrator_gainval_i
  //  Referenced by: '<S498>/Integrator'

  0.001F,

  // Computed Parameter: Constant1_Value_f
  //  Referenced by: '<S9>/Constant1'

  100.0F,

  // Computed Parameter: Filter_gainval_f
  //  Referenced by: '<S443>/Filter'

  0.001F,

  // Computed Parameter: Integrator_gainval_im
  //  Referenced by: '<S448>/Integrator'

  0.001F,

  // Computed Parameter: Constant2_Value_m
  //  Referenced by: '<S9>/Constant2'

  100.0F,

  // Computed Parameter: Filter_gainval_m
  //  Referenced by: '<S543>/Filter'

  0.001F,

  // Computed Parameter: Integrator_gainval_e
  //  Referenced by: '<S548>/Integrator'

  0.001F,

  // Computed Parameter: RateTransition_InitialCondition
  //  Referenced by: '<Root>/Rate Transition'

  0.0F,

  // Computed Parameter: RateTransition1_InitialConditio
  //  Referenced by: '<Root>/Rate Transition1'

  0.0F,

  // Computed Parameter: RateTransition2_InitialConditio
  //  Referenced by: '<Root>/Rate Transition2'

  0.0F,

  // Computed Parameter: RateTransition3_InitialConditio
  //  Referenced by: '<Root>/Rate Transition3'

  0.0F,

  // Computed Parameter: Constant_Value_kf
  //  Referenced by: '<S181>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_ms
  //  Referenced by: '<S182>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_ii
  //  Referenced by: '<S183>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_j4x
  //  Referenced by: '<S184>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S185>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S186>/Constant'

  1000.0F,

  // Computed Parameter: Constant1_Value_i
  //  Referenced by: '<S12>/Constant1'

  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Saturation_UpperSat_ep
  //  Referenced by: '<S568>/Saturation'

  2000.0F,

  // Computed Parameter: Saturation_LowerSat_p
  //  Referenced by: '<S568>/Saturation'

  1000.0F,

  // Computed Parameter: Constant_Value_ez
  //  Referenced by: '<S568>/Constant'

  1000.0F,

  // Computed Parameter: Gain_Gain_mg
  //  Referenced by: '<S568>/Gain'

  0.001F,

  // Computed Parameter: Merge1_InitialOutput
  //  Referenced by: '<Root>/Merge1'

  0.0F,

  // Computed Parameter: Constant_Value_gq
  //  Referenced by: '<S15>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_a5
  //  Referenced by: '<Root>/Constant'

  0.0F,

  // Computed Parameter: u2_Gain
  //  Referenced by: '<S576>/1//2'

  0.5F,

  // Computed Parameter: Merge_InitialOutput
  //  Referenced by: '<Root>/Merge'

  0.0F,

  // Computed Parameter: Constant_Value_ll
  //  Referenced by: '<S17>/Constant'

  0.0F,

  // Computed Parameter: PWM_Y0
  //  Referenced by: '<S6>/PWM'

  0U,

  // Computed Parameter: Output_Limits1_UpperSat
  //  Referenced by: '<S6>/Output_Limits1'

  2000U,

  // Computed Parameter: Output_Limits1_LowerSat
  //  Referenced by: '<S6>/Output_Limits1'

  1000U,

  // Computed Parameter: RateTransition4_InitialConditio
  //  Referenced by: '<Root>/Rate Transition4'

  0U,

  // Computed Parameter: RateTransition5_InitialConditio
  //  Referenced by: '<Root>/Rate Transition5'

  false,

  // Computed Parameter: RateTransition6_InitialConditio
  //  Referenced by: '<Root>/Rate Transition6'

  false,

  // Computed Parameter: Constant_Value_jc
  //  Referenced by: '<S46>/Constant'

  1,

  // Computed Parameter: Constant2_Value_mj
  //  Referenced by: '<S46>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_es
  //  Referenced by: '<S46>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_j
  //  Referenced by: '<S46>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_mn
  //  Referenced by: '<S269>/Constant'

  1,

  // Computed Parameter: Constant2_Value_p
  //  Referenced by: '<S269>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_n
  //  Referenced by: '<S269>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_i
  //  Referenced by: '<S269>/Constant4'

  -1
};

//
// File trailer for generated code.
//
// [EOF]
//
