//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_hexacopter_data.cpp
//
// Code generated for Simulink model 'FLIGHT_hexacopter'.
//
// Model version                  : 1.250
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Fri May 23 13:47:19 2025
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
  //    '<S1>/Read Parameter1'
  //    '<S1>/Read Parameter2'
  //    '<S1>/Read Parameter3'
  //    '<S1>/Read Parameter4'
  //    '<S2>/Read Parameter'
  //    '<S2>/Read Parameter1'
  //    '<S2>/Read Parameter10'
  //    '<S2>/Read Parameter9'
  //    '<S3>/Read Parameter'
  //    '<S3>/Read Parameter1'
  //    '<S3>/Read Parameter2'
  //    '<S11>/Read Parameter'
  //    '<S11>/Read Parameter1'
  //    '<S11>/Read Parameter2'
  //    '<S11>/Read Parameter3'
  //    '<S11>/Read Parameter4'
  //    '<S194>/Read Parameter'
  //    '<S195>/Read Parameter'

  0.004,

  // Variable: SampleTime_SAS
  //  Referenced by:
  //    '<S4>/Read Parameter1'
  //    '<S4>/Read Parameter13'
  //    '<S4>/Read Parameter2'
  //    '<S4>/Read Parameter3'
  //    '<S4>/Read Parameter4'
  //    '<S4>/Read Parameter5'
  //    '<S10>/Read Parameter1'
  //    '<S10>/Read Parameter10'
  //    '<S10>/Read Parameter2'
  //    '<S10>/Read Parameter3'
  //    '<S10>/Read Parameter4'
  //    '<S10>/Read Parameter5'
  //    '<S10>/Read Parameter6'
  //    '<S10>/Read Parameter7'
  //    '<S10>/Read Parameter8'
  //    '<S10>/Read Parameter9'
  //    '<S10>/read_mc_rollrate_p'

  0.001,

  // Variable: Jxx
  //  Referenced by: '<S477>/Constant'

  0.0211F,

  // Variable: Jyy
  //  Referenced by: '<S477>/Constant1'

  0.0219F,

  // Variable: Jzz
  //  Referenced by: '<S477>/Constant2'

  0.0366F,

  // Variable: MAX_CONTROL_ANGLE_PITCH
  //  Referenced by:
  //    '<S12>/Gain5'
  //    '<S22>/Gain2'

  0.52359879F,

  // Variable: MAX_CONTROL_ANGLE_RATE_Y
  //  Referenced by:
  //    '<S12>/Gain6'
  //    '<S22>/Gain3'

  2.09439516F,

  // Variable: MAX_CONTROL_ANGLE_ROLL
  //  Referenced by:
  //    '<S12>/Gain4'
  //    '<S22>/Gain1'

  0.52359879F,

  // Variable: MAX_CONTROL_VELOCITY_XY
  //  Referenced by: '<S192>/Gain1'

  1.5F,

  // Mask Parameter: DiscreteDerivative2_ICPrevScale
  //  Referenced by: '<S312>/UD'

  0.0F,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_n
  //  Referenced by: '<S367>/UD'

  0.0F,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_o
  //  Referenced by: '<S422>/UD'

  0.0F,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_a
  //  Referenced by: '<S480>/UD'

  0.0F,

  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S478>/UD'

  0.0F,

  // Mask Parameter: DiscreteDerivative1_ICPrevScale
  //  Referenced by: '<S479>/UD'

  0.0F,

  // Mask Parameter: DiscreteDerivative3_ICPrevScale
  //  Referenced by: '<S481>/UD'

  0.0F,

  // Mask Parameter: PIDController_InitialConditionF
  //  Referenced by: '<S55>/Filter'

  0.0F,

  // Mask Parameter: pid_ctrl_rollrate_InitialCondit
  //  Referenced by: '<S350>/Integrator'

  0.0F,

  // Mask Parameter: pid_ctrl_rollrate_InitialCond_j
  //  Referenced by: '<S405>/Integrator'

  0.0F,

  // Mask Parameter: pid_ctrl_rollrate_InitialCond_p
  //  Referenced by: '<S460>/Integrator'

  0.0F,

  // Mask Parameter: PIDController_InitialConditio_a
  //  Referenced by: '<S60>/Integrator'

  0.0F,

  // Mask Parameter: PIDController_LowerIntegratorSa
  //  Referenced by: '<S60>/Integrator'

  -0.3F,

  // Mask Parameter: PIDController_LowerSaturationLi
  //  Referenced by:
  //    '<S67>/Saturation'
  //    '<S52>/DeadZone'

  0.0F,

  // Mask Parameter: PIDController_UpperIntegratorSa
  //  Referenced by: '<S60>/Integrator'

  0.3F,

  // Mask Parameter: PIDController_UpperSaturationLi
  //  Referenced by:
  //    '<S67>/Saturation'
  //    '<S52>/DeadZone'

  1.0F,

  // Mask Parameter: CompareToConstant2_const
  //  Referenced by: '<S193>/Constant'

  1800U,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S488>/Constant'

  1800U,

  // Mask Parameter: CompareToConstant_const_g
  //  Referenced by: '<S185>/Constant'

  1400U,

  // Mask Parameter: CompareToConstant1_const
  //  Referenced by: '<S23>/Constant'

  1400U,

  // Mask Parameter: CompareToConstant1_const_e
  //  Referenced by: '<S183>/Constant'

  1800U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S303>/Out1'

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
  //  Referenced by: '<S301>/Constant'

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
  //  Referenced by: '<S305>/Out1'

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
  //  Referenced by: '<S304>/Constant'

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
  //  Referenced by: '<S495>/Constant'

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

  // Computed Parameter: Out1_Y0_o
  //  Referenced by: '<S307>/Out1'

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

  // Computed Parameter: Constant_Value_m1
  //  Referenced by: '<S306>/Constant'

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

  // Computed Parameter: Out1_Y0_a
  //  Referenced by: '<S503>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // armed_time
    (0ULL),                            // takeoff_time
    (0ULL),                            // nav_state_timestamp
    0U,                                // failure_detector_status
    0U,                                // arming_state
    0U,                                // latest_arming_reason
    0U,                                // latest_disarming_reason
    0U,                                // nav_state_user_intention
    0U,                                // nav_state
    0U,                                // hil_state
    0U,                                // vehicle_type
    false,                             // failsafe
    false,                             // failsafe_and_user_took_over
    false,                             // gcs_connection_lost
    0U,                                // gcs_connection_lost_counter
    false,                             // high_latency_data_link_lost
    false,                             // is_vtol
    false,                             // is_vtol_tailsitter
    false,                             // in_transition_mode
    false,                             // in_transition_to_fw
    0U,                                // system_type
    0U,                                // system_id
    0U,                                // component_id
    false,                             // safety_button_available
    false,                             // safety_off
    false,                             // power_input_valid
    false,                             // usb_connected
    false,                             // open_drone_id_system_present
    false,                             // open_drone_id_system_healthy
    false,                             // parachute_system_present
    false,                             // parachute_system_healthy
    false,                             // avoidance_system_required
    false,                             // avoidance_system_valid
    false,                             // rc_calibration_in_progress
    false,                             // calibration_enabled
    false,                             // pre_flight_checks_pass

    {
      0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S501>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // armed_time
    (0ULL),                            // takeoff_time
    (0ULL),                            // nav_state_timestamp
    0U,                                // failure_detector_status
    0U,                                // arming_state
    0U,                                // latest_arming_reason
    0U,                                // latest_disarming_reason
    0U,                                // nav_state_user_intention
    0U,                                // nav_state
    0U,                                // hil_state
    0U,                                // vehicle_type
    false,                             // failsafe
    false,                             // failsafe_and_user_took_over
    false,                             // gcs_connection_lost
    0U,                                // gcs_connection_lost_counter
    false,                             // high_latency_data_link_lost
    false,                             // is_vtol
    false,                             // is_vtol_tailsitter
    false,                             // in_transition_mode
    false,                             // in_transition_to_fw
    0U,                                // system_type
    0U,                                // system_id
    0U,                                // component_id
    false,                             // safety_button_available
    false,                             // safety_off
    false,                             // power_input_valid
    false,                             // usb_connected
    false,                             // open_drone_id_system_present
    false,                             // open_drone_id_system_healthy
    false,                             // parachute_system_present
    false,                             // parachute_system_healthy
    false,                             // avoidance_system_required
    false,                             // avoidance_system_valid
    false,                             // rc_calibration_in_progress
    false,                             // calibration_enabled
    false,                             // pre_flight_checks_pass

    {
      0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S508>/Constant'

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

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S506>/Constant'

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

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S498>/Out1'

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
  //  Referenced by: '<S497>/Constant'

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

  // Computed Parameter: Constant_Value_ni
  //  Referenced by: '<S511>/Constant'

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
  //  Referenced by: '<S491>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // control_power

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S502>/Out1'

  {
    (0ULL),                            // timestamp
    false,                             // armed
    false,                             // prearmed
    false,                             // ready_to_arm
    false,                             // lockdown
    false,                             // manual_lockdown
    false,                             // force_failsafe
    false,                             // in_esc_calibration_mode
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_m3
  //  Referenced by: '<S500>/Constant'

  {
    (0ULL),                            // timestamp
    false,                             // armed
    false,                             // prearmed
    false,                             // ready_to_arm
    false,                             // lockdown
    false,                             // manual_lockdown
    false,                             // force_failsafe
    false,                             // in_esc_calibration_mode
    0U                                 // _padding0
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
  //  Referenced by: '<S12>/Constant'

  1094.0,

  // Expression: 1/800
  //  Referenced by: '<S12>/Gain'

  0.00125,

  // Expression: 0.01
  //  Referenced by: '<S186>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S186>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S186>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S187>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S187>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S187>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S188>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S188>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S188>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S189>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S189>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S189>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S190>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S190>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S190>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S191>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S191>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S191>/Saturation'

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
  //  Referenced by: '<S77>/Gain1'

  0.0174532924F,

  // Computed Parameter: Gain1_Gain_c
  //  Referenced by: '<S78>/Gain1'

  0.0174532924F,

  // Computed Parameter: Gain_Gain_a
  //  Referenced by: '<S249>/Gain'

  -1.0F,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S5>/Discrete-Time Integrator'

  0.004F,

  // Computed Parameter: DiscreteTimeIntegrator_UpperSat
  //  Referenced by: '<S5>/Discrete-Time Integrator'

  10.0F,

  // Computed Parameter: DiscreteTimeIntegrator_LowerSat
  //  Referenced by: '<S5>/Discrete-Time Integrator'

  -50.0F,

  // Computed Parameter: DiscreteTimeIntegrator1_gainval
  //  Referenced by: '<S5>/Discrete-Time Integrator1'

  0.004F,

  // Computed Parameter: DiscreteTimeIntegrator1_UpperSa
  //  Referenced by: '<S5>/Discrete-Time Integrator1'

  10.0F,

  // Computed Parameter: DiscreteTimeIntegrator1_LowerSa
  //  Referenced by: '<S5>/Discrete-Time Integrator1'

  -50.0F,

  // Computed Parameter: Saturation_UpperSat_e
  //  Referenced by: '<S195>/Saturation'

  0.610865235F,

  // Computed Parameter: Saturation_LowerSat_a
  //  Referenced by: '<S195>/Saturation'

  -0.610865235F,

  // Computed Parameter: Gain1_Gain_i
  //  Referenced by: '<S195>/Gain1'

  -1.0F,

  // Computed Parameter: DeadZone3_Start
  //  Referenced by: '<S192>/Dead Zone3'

  -0.1F,

  // Computed Parameter: DeadZone3_End
  //  Referenced by: '<S192>/Dead Zone3'

  0.1F,

  // Computed Parameter: Saturation9_UpperSat
  //  Referenced by: '<S192>/Saturation9'

  1.0F,

  // Computed Parameter: Saturation9_LowerSat
  //  Referenced by: '<S192>/Saturation9'

  -1.0F,

  // Computed Parameter: DeadZone1_Start
  //  Referenced by: '<S192>/Dead Zone1'

  -0.1F,

  // Computed Parameter: DeadZone1_End
  //  Referenced by: '<S192>/Dead Zone1'

  0.1F,

  // Computed Parameter: Saturation1_UpperSat
  //  Referenced by: '<S192>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat
  //  Referenced by: '<S192>/Saturation1'

  -1.0F,

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<S192>/Gain2'

  -1.5F,

  // Computed Parameter: tau_roll_Y0
  //  Referenced by: '<S10>/tau_roll'

  0.0F,

  // Computed Parameter: tau_pitch_Y0
  //  Referenced by: '<S10>/tau_pitch'

  0.0F,

  // Computed Parameter: tau_yaw_Y0
  //  Referenced by: '<S10>/tau_yaw'

  0.0F,

  // Computed Parameter: tau_Gain
  //  Referenced by: '<S315>/tau'

  0.0005F,

  // Computed Parameter: Bias1_Bias
  //  Referenced by: '<S316>/Bias1'

  1.0F,

  // Computed Parameter: Bias_Bias
  //  Referenced by: '<S316>/Bias'

  1.0F,

  // Computed Parameter: Gain_Gain_i
  //  Referenced by: '<S316>/Gain'

  1.41421354F,

  // Computed Parameter: UnitDelay1_InitialCondition
  //  Referenced by: '<S315>/Unit Delay1'

  0.0F,

  // Computed Parameter: Gain1_Gain_j
  //  Referenced by: '<S315>/Gain1'

  2.0F,

  // Computed Parameter: UnitDelay2_InitialCondition
  //  Referenced by: '<S315>/Unit Delay2'

  0.0F,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S312>/TSamp'

  1000.0F,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S350>/Integrator'

  0.001F,

  // Computed Parameter: tau_Gain_n
  //  Referenced by: '<S370>/tau'

  0.0005F,

  // Computed Parameter: Bias1_Bias_n
  //  Referenced by: '<S371>/Bias1'

  1.0F,

  // Computed Parameter: Bias_Bias_b
  //  Referenced by: '<S371>/Bias'

  1.0F,

  // Computed Parameter: Gain_Gain_e
  //  Referenced by: '<S371>/Gain'

  1.41421354F,

  // Computed Parameter: UnitDelay1_InitialCondition_p
  //  Referenced by: '<S370>/Unit Delay1'

  0.0F,

  // Computed Parameter: Gain1_Gain_e
  //  Referenced by: '<S370>/Gain1'

  2.0F,

  // Computed Parameter: UnitDelay2_InitialCondition_e
  //  Referenced by: '<S370>/Unit Delay2'

  0.0F,

  // Computed Parameter: TSamp_WtEt_m
  //  Referenced by: '<S367>/TSamp'

  1000.0F,

  // Computed Parameter: Integrator_gainval_b
  //  Referenced by: '<S405>/Integrator'

  0.001F,

  // Computed Parameter: tau_Gain_c
  //  Referenced by: '<S425>/tau'

  0.0005F,

  // Computed Parameter: Bias1_Bias_i
  //  Referenced by: '<S426>/Bias1'

  1.0F,

  // Computed Parameter: Bias_Bias_c
  //  Referenced by: '<S426>/Bias'

  1.0F,

  // Computed Parameter: Gain_Gain_b
  //  Referenced by: '<S426>/Gain'

  1.41421354F,

  // Computed Parameter: UnitDelay1_InitialCondition_e
  //  Referenced by: '<S425>/Unit Delay1'

  0.0F,

  // Computed Parameter: Gain1_Gain_iw
  //  Referenced by: '<S425>/Gain1'

  2.0F,

  // Computed Parameter: UnitDelay2_InitialCondition_m
  //  Referenced by: '<S425>/Unit Delay2'

  0.0F,

  // Computed Parameter: TSamp_WtEt_p
  //  Referenced by: '<S422>/TSamp'

  1000.0F,

  // Computed Parameter: Integrator_gainval_p
  //  Referenced by: '<S460>/Integrator'

  0.001F,

  // Computed Parameter: DeadZone3_Start_p
  //  Referenced by: '<S12>/Dead Zone3'

  -0.05F,

  // Computed Parameter: DeadZone3_End_l
  //  Referenced by: '<S12>/Dead Zone3'

  0.05F,

  // Computed Parameter: Saturation_UpperSat_o
  //  Referenced by: '<S12>/Saturation'

  0.9F,

  // Computed Parameter: Saturation_LowerSat_el
  //  Referenced by: '<S12>/Saturation'

  0.0F,

  // Computed Parameter: Constant1_Value_l
  //  Referenced by: '<S12>/Constant1'

  1514.0F,

  // Computed Parameter: Gain2_Gain_a
  //  Referenced by: '<S12>/Gain2'

  0.0025F,

  // Computed Parameter: DeadZone2_Start
  //  Referenced by: '<S12>/Dead Zone2'

  -0.005F,

  // Computed Parameter: DeadZone2_End
  //  Referenced by: '<S12>/Dead Zone2'

  0.005F,

  // Computed Parameter: Saturation1_UpperSat_l
  //  Referenced by: '<S12>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat_i
  //  Referenced by: '<S12>/Saturation1'

  -1.0F,

  // Computed Parameter: Constant2_Value_i
  //  Referenced by: '<S12>/Constant2'

  1514.0F,

  // Computed Parameter: Gain1_Gain_m
  //  Referenced by: '<S12>/Gain1'

  0.0025F,

  // Computed Parameter: DeadZone1_Start_c
  //  Referenced by: '<S12>/Dead Zone1'

  -0.005F,

  // Computed Parameter: DeadZone1_End_m
  //  Referenced by: '<S12>/Dead Zone1'

  0.005F,

  // Computed Parameter: Saturation2_UpperSat
  //  Referenced by: '<S12>/Saturation2'

  1.0F,

  // Computed Parameter: Saturation2_LowerSat
  //  Referenced by: '<S12>/Saturation2'

  -1.0F,

  // Computed Parameter: Constant3_Value_e
  //  Referenced by: '<S12>/Constant3'

  1514.0F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<S12>/Gain3'

  0.0025F,

  // Computed Parameter: DeadZone_Start
  //  Referenced by: '<S12>/Dead Zone'

  -0.005F,

  // Computed Parameter: DeadZone_End
  //  Referenced by: '<S12>/Dead Zone'

  0.005F,

  // Computed Parameter: Saturation3_UpperSat
  //  Referenced by: '<S12>/Saturation3'

  1.0F,

  // Computed Parameter: Saturation3_LowerSat
  //  Referenced by: '<S12>/Saturation3'

  -1.0F,

  // Computed Parameter: Constant1_Value_g
  //  Referenced by: '<S50>/Constant1'

  0.0F,

  // Computed Parameter: rate_transition_des_p_InitialCo
  //  Referenced by: '<Root>/rate_transition_des_p'

  0.0F,

  // Computed Parameter: rate_transition_des_q_InitialCo
  //  Referenced by: '<Root>/rate_transition_des_q'

  0.0F,

  // Computed Parameter: rate_transition_des_r_InitialCo
  //  Referenced by: '<Root>/rate_transition_des_r'

  0.0F,

  // Computed Parameter: RateTransition1_InitialConditio
  //  Referenced by: '<Root>/Rate Transition1'

  0.0F,

  // Computed Parameter: rate_transition_throttle_Initia
  //  Referenced by: '<Root>/rate_transition_throttle'

  0.0F,

  // Computed Parameter: Constant1_Value_i
  //  Referenced by: '<S15>/Constant1'

  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Saturation_UpperSat_ep
  //  Referenced by: '<S493>/Saturation'

  2000.0F,

  // Computed Parameter: Saturation_LowerSat_p
  //  Referenced by: '<S493>/Saturation'

  1000.0F,

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S493>/Constant'

  1000.0F,

  // Computed Parameter: Gain_Gain_mg
  //  Referenced by: '<S493>/Gain'

  0.001F,

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S186>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_ms
  //  Referenced by: '<S187>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S188>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S189>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_lw
  //  Referenced by: '<S190>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_ox
  //  Referenced by: '<S191>/Constant'

  1000.0F,

  // Computed Parameter: DeadZone3_Start_l
  //  Referenced by: '<S22>/Dead Zone3'

  -0.003F,

  // Computed Parameter: DeadZone3_End_n
  //  Referenced by: '<S22>/Dead Zone3'

  0.003F,

  // Computed Parameter: Saturation9_UpperSat_c
  //  Referenced by: '<S22>/Saturation9'

  1.0F,

  // Computed Parameter: Saturation9_LowerSat_i
  //  Referenced by: '<S22>/Saturation9'

  -1.0F,

  // Computed Parameter: DeadZone1_Start_n
  //  Referenced by: '<S22>/Dead Zone1'

  -0.001F,

  // Computed Parameter: DeadZone1_End_mj
  //  Referenced by: '<S22>/Dead Zone1'

  0.001F,

  // Computed Parameter: Saturation1_UpperSat_d
  //  Referenced by: '<S22>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat_b
  //  Referenced by: '<S22>/Saturation1'

  -1.0F,

  // Computed Parameter: DeadZone2_Start_m
  //  Referenced by: '<S22>/Dead Zone2'

  -0.005F,

  // Computed Parameter: DeadZone2_End_b
  //  Referenced by: '<S22>/Dead Zone2'

  0.005F,

  // Computed Parameter: Saturation3_UpperSat_d
  //  Referenced by: '<S22>/Saturation3'

  1.0F,

  // Computed Parameter: Saturation3_LowerSat_n
  //  Referenced by: '<S22>/Saturation3'

  -1.0F,

  // Computed Parameter: DeadZone4_Start
  //  Referenced by: '<S22>/Dead Zone4'

  -0.1F,

  // Computed Parameter: DeadZone4_End
  //  Referenced by: '<S22>/Dead Zone4'

  0.1F,

  // Computed Parameter: Saturation10_UpperSat
  //  Referenced by: '<S22>/Saturation10'

  1.0F,

  // Computed Parameter: Saturation10_LowerSat
  //  Referenced by: '<S22>/Saturation10'

  -1.0F,

  // Computed Parameter: Gain_Gain_er
  //  Referenced by: '<S22>/Gain'

  -1.0F,

  // Computed Parameter: Gain_Gain_o
  //  Referenced by: '<S1>/Gain'

  -1.0F,

  // Computed Parameter: Integrator_gainval_h
  //  Referenced by: '<S60>/Integrator'

  0.004F,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S55>/Filter'

  0.004F,

  // Computed Parameter: Constant_Value_gx
  //  Referenced by: '<S1>/Constant'

  50.0F,

  // Computed Parameter: Saturation1_UpperSat_lr
  //  Referenced by: '<S1>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat_e
  //  Referenced by: '<S1>/Saturation1'

  0.0F,

  // Computed Parameter: TSamp_WtEt_k
  //  Referenced by: '<S480>/TSamp'

  250.0F,

  // Computed Parameter: TSamp_WtEt_c
  //  Referenced by: '<S478>/TSamp'

  250.0F,

  // Computed Parameter: TSamp_WtEt_b
  //  Referenced by: '<S479>/TSamp'

  250.0F,

  // Computed Parameter: TSamp_WtEt_py
  //  Referenced by: '<S481>/TSamp'

  250.0F,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_c
  //  Referenced by: '<S11>/Discrete-Time Integrator'

  0.004F,

  // Computed Parameter: DiscreteTimeIntegrator_IC
  //  Referenced by: '<S11>/Discrete-Time Integrator'

  0.0F,

  // Computed Parameter: Saturation2_UpperSat_i
  //  Referenced by: '<S11>/Saturation2'

  1.0F,

  // Computed Parameter: Saturation2_LowerSat_k
  //  Referenced by: '<S11>/Saturation2'

  -1.0F,

  // Computed Parameter: Constant_Value_ll
  //  Referenced by: '<S21>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_a5
  //  Referenced by: '<Root>/Constant'

  0.0F,

  // Computed Parameter: Clamping_zero_Value
  //  Referenced by: '<S50>/Clamping_zero'

  0.0F,

  // Computed Parameter: PWM_Y0
  //  Referenced by: '<S7>/PWM'

  0U,

  // Computed Parameter: Output_Limits1_UpperSat
  //  Referenced by: '<S7>/Output_Limits1'

  2000U,

  // Computed Parameter: Output_Limits1_LowerSat
  //  Referenced by: '<S7>/Output_Limits1'

  1000U,

  // Computed Parameter: rate_transition_ctrl_sw_Initial
  //  Referenced by: '<Root>/rate_transition_ctrl_sw'

  0U,

  // Computed Parameter: RateTransition4_InitialConditio
  //  Referenced by: '<Root>/Rate Transition4'

  0U,

  // Computed Parameter: rate_transition_arm_InitialCond
  //  Referenced by: '<Root>/rate_transition_arm'

  false,

  // Computed Parameter: RateTransition7_InitialConditio
  //  Referenced by: '<Root>/Rate Transition7'

  false,

  // Computed Parameter: Constant_Value_ko
  //  Referenced by: '<S50>/Constant'

  1,

  // Computed Parameter: Constant2_Value_e
  //  Referenced by: '<S50>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_i
  //  Referenced by: '<S50>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_d
  //  Referenced by: '<S50>/Constant4'

  -1
};

//
// File trailer for generated code.
//
// [EOF]
//
