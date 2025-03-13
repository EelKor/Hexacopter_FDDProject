//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_hexacopter_data.cpp
//
// Code generated for Simulink model 'FLIGHT_hexacopter'.
//
// Model version                  : 1.90
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Fri Mar  7 17:53:58 2025
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
  //    '<S3>/Read Parameter'
  //    '<S3>/Read Parameter1'
  //    '<S9>/Read Parameter'
  //    '<S9>/Read Parameter1'
  //    '<S9>/Read Parameter2'
  //    '<S9>/Read Parameter3'
  //    '<S9>/Read Parameter4'
  //    '<S9>/Read Parameter5'
  //    '<S9>/Read Parameter6'
  //    '<S9>/Read Parameter7'
  //    '<S9>/Read Parameter8'
  //    '<S18>/Read Parameter'
  //    '<S18>/Read Parameter1'
  //    '<S18>/Read Parameter2'
  //    '<S18>/Read Parameter3'
  //    '<S182>/Read Parameter1'
  //    '<S184>/Read Parameter'
  //    '<S184>/Read Parameter1'
  //    '<S184>/Read Parameter2'
  //    '<S184>/Read Parameter3'
  //    '<S185>/Read Parameter'
  //    '<S186>/Read Parameter'

  0.005,

  // Variable: d2r
  //  Referenced by:
  //    '<S561>/Constant'
  //    '<S561>/Discrete Pulse Generator'

  0.017453292519943295,

  // Variable: MAX_CONTROL_ANGLE_PITCH
  //  Referenced by:
  //    '<S10>/Gain5'
  //    '<S17>/Gain2'

  0.34906584F,

  // Variable: MAX_CONTROL_ANGLE_RATE_Y
  //  Referenced by:
  //    '<S10>/Gain6'
  //    '<S17>/Gain3'
  //    '<S183>/Gain3'

  2.09439516F,

  // Variable: MAX_CONTROL_ANGLE_ROLL
  //  Referenced by:
  //    '<S10>/Gain4'
  //    '<S17>/Gain1'

  0.34906584F,

  // Mask Parameter: PIDController4_InitialCondition
  //  Referenced by: '<S50>/Filter'

  0.0F,

  // Mask Parameter: PIDController4_InitialConditi_l
  //  Referenced by: '<S269>/Filter'

  0.0F,

  // Mask Parameter: PIDController2_InitialCondition
  //  Referenced by: '<S488>/Filter'

  0.0F,

  // Mask Parameter: PIDController1_InitialCondition
  //  Referenced by: '<S438>/Filter'

  0.0F,

  // Mask Parameter: PIDController6_InitialCondition
  //  Referenced by: '<S538>/Filter'

  0.0F,

  // Mask Parameter: PIDController4_InitialConditi_a
  //  Referenced by: '<S55>/Integrator'

  0.0F,

  // Mask Parameter: PIDController4_InitialConditi_i
  //  Referenced by: '<S274>/Integrator'

  0.0F,

  // Mask Parameter: PIDController2_InitialConditi_c
  //  Referenced by: '<S493>/Integrator'

  0.0F,

  // Mask Parameter: PIDController1_InitialConditi_c
  //  Referenced by: '<S443>/Integrator'

  0.0F,

  // Mask Parameter: PIDController6_InitialConditi_h
  //  Referenced by: '<S543>/Integrator'

  0.0F,

  // Mask Parameter: PIDController4_LowerSaturationL
  //  Referenced by:
  //    '<S62>/Saturation'
  //    '<S47>/DeadZone'

  -1.0F,

  // Mask Parameter: PIDController4_LowerSaturatio_a
  //  Referenced by: '<S228>/Saturation'

  -1.0F,

  // Mask Parameter: PIDController4_LowerSaturatio_f
  //  Referenced by:
  //    '<S281>/Saturation'
  //    '<S266>/DeadZone'

  -1.0F,

  // Mask Parameter: PIDController4_UpperSaturationL
  //  Referenced by:
  //    '<S62>/Saturation'
  //    '<S47>/DeadZone'

  1.0F,

  // Mask Parameter: PIDController4_UpperSaturatio_h
  //  Referenced by: '<S228>/Saturation'

  1.0F,

  // Mask Parameter: PIDController4_UpperSaturati_hy
  //  Referenced by:
  //    '<S281>/Saturation'
  //    '<S266>/DeadZone'

  1.0F,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S560>/Constant'

  1800U,

  // Mask Parameter: CompareToConstant_const_g
  //  Referenced by: '<S175>/Constant'

  1400U,

  // Mask Parameter: CompareToConstant3_const
  //  Referenced by: '<S72>/Constant'

  1800U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S401>/Out1'

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
  //  Referenced by: '<S397>/Constant'

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
  //  Referenced by: '<S403>/Out1'

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
  //  Referenced by: '<S402>/Constant'

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

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S562>/Constant'

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

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S406>/Out1'

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

  // Computed Parameter: Constant_Value_bd
  //  Referenced by: '<S405>/Constant'

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
  //  Referenced by: '<S567>/Constant'

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
  //  Referenced by: '<S564>/Constant'

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

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S400>/Out1'

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

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S399>/Constant'

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

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S569>/Constant'

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

  // Computed Parameter: Constant_Value_n1
  //  Referenced by: '<S571>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // xyz

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

  // Computed Parameter: DiscretePulseGenerator_Period
  //  Referenced by: '<S561>/Discrete Pulse Generator'

  1200.0,

  // Computed Parameter: DiscretePulseGenerator_Duty
  //  Referenced by: '<S561>/Discrete Pulse Generator'

  600.0,

  // Expression: 0
  //  Referenced by: '<S561>/Discrete Pulse Generator'

  0.0,

  // Expression: 1094
  //  Referenced by: '<S10>/Constant'

  1094.0,

  // Expression: 1/800
  //  Referenced by: '<S10>/Gain'

  0.00125,

  // Expression: 0.01
  //  Referenced by: '<S176>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S176>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S176>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S177>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S177>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S177>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S178>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S178>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S178>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S179>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S179>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S179>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S180>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S180>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S180>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S181>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S181>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S181>/Saturation'

  0.0,

  // Computed Parameter: Constant1_Value_n
  //  Referenced by: '<S45>/Constant1'

  0.0F,

  // Computed Parameter: DeadZone3_Start
  //  Referenced by: '<S17>/Dead Zone3'

  -0.003F,

  // Computed Parameter: DeadZone3_End
  //  Referenced by: '<S17>/Dead Zone3'

  0.003F,

  // Computed Parameter: Saturation9_UpperSat
  //  Referenced by: '<S17>/Saturation9'

  1.0F,

  // Computed Parameter: Saturation9_LowerSat
  //  Referenced by: '<S17>/Saturation9'

  -1.0F,

  // Computed Parameter: DeadZone4_Start
  //  Referenced by: '<S17>/Dead Zone4'

  -0.03F,

  // Computed Parameter: DeadZone4_End
  //  Referenced by: '<S17>/Dead Zone4'

  0.03F,

  // Computed Parameter: Saturation10_UpperSat
  //  Referenced by: '<S17>/Saturation10'

  1.0F,

  // Computed Parameter: Saturation10_LowerSat
  //  Referenced by: '<S17>/Saturation10'

  -1.0F,

  // Computed Parameter: Gain_Gain_e
  //  Referenced by: '<S17>/Gain'

  -1.0F,

  // Computed Parameter: Gain_Gain_d
  //  Referenced by: '<S18>/Gain'

  -1.0F,

  // Computed Parameter: Clamping_zero_Value
  //  Referenced by: '<S45>/Clamping_zero'

  0.0F,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S55>/Integrator'

  0.005F,

  // Computed Parameter: Constant_Value_bi
  //  Referenced by: '<S18>/Constant'

  50.0F,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S50>/Filter'

  0.005F,

  // Computed Parameter: Saturation1_UpperSat
  //  Referenced by: '<S18>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat
  //  Referenced by: '<S18>/Saturation1'

  0.0F,

  // Computed Parameter: DeadZone2_Start
  //  Referenced by: '<S17>/Dead Zone2'

  -0.005F,

  // Computed Parameter: DeadZone2_End
  //  Referenced by: '<S17>/Dead Zone2'

  0.005F,

  // Computed Parameter: Saturation3_UpperSat
  //  Referenced by: '<S17>/Saturation3'

  1.0F,

  // Computed Parameter: Saturation3_LowerSat
  //  Referenced by: '<S17>/Saturation3'

  -1.0F,

  // Computed Parameter: DeadZone1_Start
  //  Referenced by: '<S17>/Dead Zone1'

  -0.001F,

  // Computed Parameter: DeadZone1_End
  //  Referenced by: '<S17>/Dead Zone1'

  0.001F,

  // Computed Parameter: Saturation1_UpperSat_d
  //  Referenced by: '<S17>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat_b
  //  Referenced by: '<S17>/Saturation1'

  -1.0F,

  // Computed Parameter: des_z_Y0
  //  Referenced by: '<S5>/des_z'

  0.0F,

  // Computed Parameter: des_vxvy_Y0
  //  Referenced by: '<S5>/des_vxvy'

  0.0F,

  // Computed Parameter: Constant1_Value_m
  //  Referenced by: '<S264>/Constant1'

  0.0F,

  // Computed Parameter: Gain_Gain_a
  //  Referenced by: '<S344>/Gain'

  -1.0F,

  // Computed Parameter: Constant_Value_kn
  //  Referenced by: '<S5>/Constant'

  { 0.0F, 0.0F },

  // Computed Parameter: Saturation_UpperSat_g
  //  Referenced by: '<S5>/Saturation'

  12.0F,

  // Computed Parameter: Saturation_LowerSat_lt
  //  Referenced by: '<S5>/Saturation'

  -12.0F,

  // Computed Parameter: Saturation_UpperSat_e
  //  Referenced by: '<S186>/Saturation'

  0.17453292F,

  // Computed Parameter: Saturation_LowerSat_a
  //  Referenced by: '<S186>/Saturation'

  -0.17453292F,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S186>/Gain1'

  -1.0F,

  // Computed Parameter: DeadZone4_Start_d
  //  Referenced by: '<S183>/Dead Zone4'

  -0.1F,

  // Computed Parameter: DeadZone4_End_l
  //  Referenced by: '<S183>/Dead Zone4'

  0.1F,

  // Computed Parameter: Saturation10_UpperSat_m
  //  Referenced by: '<S183>/Saturation10'

  1.0F,

  // Computed Parameter: Saturation10_LowerSat_n
  //  Referenced by: '<S183>/Saturation10'

  -1.0F,

  // Computed Parameter: Gain_Gain_o
  //  Referenced by: '<S183>/Gain'

  -1.0F,

  // Computed Parameter: Gain_Gain_b
  //  Referenced by: '<S184>/Gain'

  -1.0F,

  // Computed Parameter: Integrator_gainval_l
  //  Referenced by: '<S274>/Integrator'

  0.005F,

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S184>/Constant'

  50.0F,

  // Computed Parameter: Filter_gainval_h
  //  Referenced by: '<S269>/Filter'

  0.005F,

  // Computed Parameter: Saturation1_UpperSat_e
  //  Referenced by: '<S184>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat_bn
  //  Referenced by: '<S184>/Saturation1'

  0.0F,

  // Computed Parameter: Clamping_zero_Value_f
  //  Referenced by: '<S264>/Clamping_zero'

  0.0F,

  // Computed Parameter: DeadZone2_Start_k
  //  Referenced by: '<S183>/Dead Zone2'

  -0.1F,

  // Computed Parameter: DeadZone2_End_k
  //  Referenced by: '<S183>/Dead Zone2'

  0.1F,

  // Computed Parameter: Saturation3_UpperSat_b
  //  Referenced by: '<S183>/Saturation3'

  1.0F,

  // Computed Parameter: Saturation3_LowerSat_a
  //  Referenced by: '<S183>/Saturation3'

  -1.0F,

  // Computed Parameter: doublet_Y0
  //  Referenced by: '<S561>/doublet'

  0.0F,

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

  // Computed Parameter: Merge1_InitialOutput
  //  Referenced by: '<Root>/Merge1'

  0.0F,

  // Computed Parameter: Integrator_gainval_i
  //  Referenced by: '<S493>/Integrator'

  0.005F,

  // Computed Parameter: Filter_gainval_o
  //  Referenced by: '<S488>/Filter'

  0.005F,

  // Computed Parameter: Constant_Value_j4
  //  Referenced by: '<S9>/Constant'

  50.0F,

  // Computed Parameter: Integrator_gainval_im
  //  Referenced by: '<S443>/Integrator'

  0.005F,

  // Computed Parameter: Filter_gainval_f
  //  Referenced by: '<S438>/Filter'

  0.005F,

  // Computed Parameter: Constant1_Value_f
  //  Referenced by: '<S9>/Constant1'

  50.0F,

  // Computed Parameter: Integrator_gainval_e
  //  Referenced by: '<S543>/Integrator'

  0.005F,

  // Computed Parameter: Filter_gainval_m
  //  Referenced by: '<S538>/Filter'

  0.005F,

  // Computed Parameter: Constant2_Value_m
  //  Referenced by: '<S9>/Constant2'

  50.0F,

  // Computed Parameter: Constant_Value_kf
  //  Referenced by: '<S176>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_ms
  //  Referenced by: '<S177>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_ii
  //  Referenced by: '<S178>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_j4x
  //  Referenced by: '<S179>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S180>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S181>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<Root>/Constant'

  0.0F,

  // Computed Parameter: u2_Gain
  //  Referenced by: '<S566>/1//2'

  0.5F,

  // Computed Parameter: Constant_Value_gq
  //  Referenced by: '<S13>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_ov
  //  Referenced by: '<S12>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_ll
  //  Referenced by: '<S15>/Constant'

  0.0F,

  // Computed Parameter: Merge_InitialOutput
  //  Referenced by: '<Root>/Merge'

  0.0F,

  // Computed Parameter: Constant2_Value_l
  //  Referenced by: '<S12>/Constant2'

  12U,

  // Computed Parameter: Output_Limits1_UpperSat
  //  Referenced by: '<S6>/Output_Limits1'

  2000U,

  // Computed Parameter: Output_Limits1_LowerSat
  //  Referenced by: '<S6>/Output_Limits1'

  1000U,

  // Computed Parameter: Constant_Value_jc
  //  Referenced by: '<S45>/Constant'

  1,

  // Computed Parameter: Constant2_Value_mj
  //  Referenced by: '<S45>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_es
  //  Referenced by: '<S45>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_j
  //  Referenced by: '<S45>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_mn
  //  Referenced by: '<S264>/Constant'

  1,

  // Computed Parameter: Constant2_Value_p
  //  Referenced by: '<S264>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_n
  //  Referenced by: '<S264>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_i
  //  Referenced by: '<S264>/Constant4'

  -1
};

//
// File trailer for generated code.
//
// [EOF]
//
