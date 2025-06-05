//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_Hexacopter_V2_data.cpp
//
// Code generated for Simulink model 'FLIGHT_Hexacopter_V2'.
//
// Model version                  : 1.158
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Tue Jun  3 13:11:16 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FLIGHT_Hexacopter_V2.h"

// Block parameters (default storage)
P_FLIGHT_Hexacopter_V2_T FLIGHT_Hexacopter_V2_P = {
  // Variable: SampleTime
  //  Referenced by:
  //    '<S5>/Read Parameter'
  //    '<S5>/Read Parameter1'
  //    '<S5>/Read Parameter10'
  //    '<S5>/Read Parameter11'
  //    '<S5>/Read Parameter12'
  //    '<S5>/Read Parameter13'
  //    '<S5>/Read Parameter14'
  //    '<S5>/Read Parameter15'
  //    '<S5>/Read Parameter16'
  //    '<S5>/Read Parameter17'
  //    '<S5>/Read Parameter18'
  //    '<S5>/Read Parameter19'
  //    '<S5>/Read Parameter2'
  //    '<S5>/Read Parameter26'
  //    '<S5>/Read Parameter27'
  //    '<S5>/Read Parameter28'
  //    '<S5>/Read Parameter29'
  //    '<S5>/Read Parameter3'
  //    '<S5>/Read Parameter30'
  //    '<S5>/Read Parameter31'
  //    '<S5>/Read Parameter32'
  //    '<S5>/Read Parameter33'
  //    '<S5>/Read Parameter34'
  //    '<S5>/Read Parameter35'
  //    '<S5>/Read Parameter36'
  //    '<S5>/Read Parameter37'
  //    '<S5>/Read Parameter38'
  //    '<S5>/Read Parameter4'
  //    '<S5>/Read Parameter5'
  //    '<S5>/Read Parameter6'
  //    '<S5>/Read Parameter7'
  //    '<S5>/Read Parameter8'
  //    '<S5>/Read Parameter9'
  //    '<S5>/read_mc_rollrate_p'

  0.004,

  // Variable: SampleTime_SAS
  //  Referenced by:
  //    '<S12>/Read Parameter1'
  //    '<S12>/Read Parameter13'
  //    '<S12>/Read Parameter2'
  //    '<S12>/Read Parameter3'
  //    '<S12>/Read Parameter4'
  //    '<S12>/Read Parameter5'

  0.001,

  // Variable: MAX_CONTROL_ANGLE_PITCH
  //  Referenced by: '<S4>/Gain5'

  0.52359879F,

  // Variable: MAX_CONTROL_ANGLE_RATE_Y
  //  Referenced by: '<S4>/Gain6'

  2.09439516F,

  // Variable: MAX_CONTROL_ANGLE_ROLL
  //  Referenced by: '<S4>/Gain4'

  0.52359879F,

  // Variable: MAX_CONTROL_VELOCITY_XY
  //  Referenced by: '<S4>/Gain9'

  1.5F,

  // Mask Parameter: DiscretePIDController1_D
  //  Referenced by: '<S316>/Derivative Gain'

  1.0F,

  // Mask Parameter: DiscretePIDController2_I
  //  Referenced by: '<S370>/Integral Gain'

  1.0F,

  // Mask Parameter: DiscreteDerivative2_ICPrevScale
  //  Referenced by: '<S557>/UD'

  0.0F,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_k
  //  Referenced by: '<S502>/UD'

  0.0F,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_f
  //  Referenced by: '<S612>/UD'

  0.0F,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_e
  //  Referenced by: '<S229>/UD'

  0.0F,

  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S227>/UD'

  0.0F,

  // Mask Parameter: DiscreteDerivative1_ICPrevScale
  //  Referenced by: '<S228>/UD'

  0.0F,

  // Mask Parameter: PIDController_InitialConditionF
  //  Referenced by: '<S83>/Filter'

  0.0F,

  // Mask Parameter: DiscretePIDController1_InitialC
  //  Referenced by: '<S318>/Filter'

  0.0F,

  // Mask Parameter: pid_ctrl_rollrate_InitialCondit
  //  Referenced by: '<S595>/Integrator'

  0.0F,

  // Mask Parameter: pid_ctrl_rollrate_InitialCond_l
  //  Referenced by: '<S540>/Integrator'

  0.0F,

  // Mask Parameter: pid_ctrl_rollrate_InitialCond_p
  //  Referenced by: '<S650>/Integrator'

  0.0F,

  // Mask Parameter: PIDController_InitialConditio_d
  //  Referenced by: '<S88>/Integrator'

  0.0F,

  // Mask Parameter: DiscretePIDController2_InitialC
  //  Referenced by: '<S373>/Integrator'

  0.0F,

  // Mask Parameter: PIDController_LowerIntegratorSa
  //  Referenced by: '<S88>/Integrator'

  -0.3F,

  // Mask Parameter: PIDController_LowerSaturationLi
  //  Referenced by:
  //    '<S95>/Saturation'
  //    '<S80>/DeadZone'

  0.0F,

  // Mask Parameter: DiscretePIDController1_N
  //  Referenced by: '<S326>/Filter Coefficient'

  100.0F,

  // Mask Parameter: DiscretePIDController1_P
  //  Referenced by: '<S328>/Proportional Gain'

  0.0F,

  // Mask Parameter: PIDController_UpperIntegratorSa
  //  Referenced by: '<S88>/Integrator'

  0.3F,

  // Mask Parameter: PIDController_UpperSaturationLi
  //  Referenced by:
  //    '<S95>/Saturation'
  //    '<S80>/DeadZone'

  1.0F,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S11>/Constant'

  1800U,

  // Mask Parameter: CompareToConstant_const_a
  //  Referenced by: '<S15>/Constant'

  1400U,

  // Mask Parameter: CompareToConstant1_const
  //  Referenced by: '<S43>/Constant'

  1400U,

  // Mask Parameter: CompareToConstant2_const
  //  Referenced by: '<S44>/Constant'

  1800U,

  // Mask Parameter: CompareToConstant3_const
  //  Referenced by: '<S45>/Constant'

  1800U,

  // Mask Parameter: CompareToConstant_const_o
  //  Referenced by: '<S226>/Constant'

  1800U,

  // Mask Parameter: CompareToConstant_const_j
  //  Referenced by: '<S392>/Constant'

  1800U,

  // Mask Parameter: CompareToConstant1_const_p
  //  Referenced by: '<S393>/Constant'

  1800U,

  // Mask Parameter: CompareToConstant2_const_p
  //  Referenced by: '<S394>/Constant'

  1800U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S221>/Out1'

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
  //  Referenced by: '<S215>/Constant'

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

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S37>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // tau_roll
    0.0F,                              // s
    0.0F,                              // hx

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // g1x

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // fx

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // omega

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // omega_dot

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // w
    0.0F,                              // e
    0.0F,                              // e_dot
    0.0F,                              // integral_e
    0.0F,                              // phi_cmd
    0.0F,                              // phi_cmd_dot
    0.0F,                              // phi_cmd_ddot
    0.0F,                              // r

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_c
  //  Referenced by: '<S224>/Out1'

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

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S223>/Constant'

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

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S39>/Constant'

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

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S209>/Out1'

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

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S208>/Constant'

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

  // Computed Parameter: Out1_Y0_e
  //  Referenced by: '<S220>/Out1'

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

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S214>/Constant'

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

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S41>/Constant'

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

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S33>/Constant'

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

  // Computed Parameter: Out1_Y0_a
  //  Referenced by: '<S211>/Out1'

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

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S210>/Constant'

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

  // Computed Parameter: Constant_Value_ek
  //  Referenced by: '<S35>/Constant'

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

  // Computed Parameter: Constant_Value_l5
  //  Referenced by: '<S31>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // control_power

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S219>/Out1'

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

  // Computed Parameter: Out1_Y0_g
  //  Referenced by: '<S222>/Out1'

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

  // Computed Parameter: Constant_Value_f
  //  Referenced by: '<S213>/Constant'

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

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S216>/Constant'

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
  //  Referenced by: '<S12>/Constant1'

  100.0,

  // Expression: 100
  //  Referenced by: '<S12>/Constant2'

  100.0,

  // Expression: 100
  //  Referenced by: '<S12>/Constant3'

  100.0,

  // Expression: 100
  //  Referenced by: '<S12>/Constant4'

  100.0,

  // Expression: 100
  //  Referenced by: '<S12>/Constant5'

  100.0,

  // Expression: 100
  //  Referenced by: '<S12>/Constant'

  100.0,

  // Expression: 0.01
  //  Referenced by: '<S16>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S16>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S16>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S17>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S17>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S18>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S18>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S19>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S19>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S19>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S20>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S20>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S20>/Saturation'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S21>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S21>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S21>/Saturation'

  0.0,

  // Expression: 1
  //  Referenced by: '<S225>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S225>/Constant1'

  1.0,

  // Expression: 1
  //  Referenced by: '<S225>/Constant2'

  1.0,

  // Expression: 1094
  //  Referenced by: '<S4>/Constant'

  1094.0,

  // Expression: 1/800
  //  Referenced by: '<S4>/Gain'

  0.00125,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S10>/Gain1'

  -1.0F,

  // Computed Parameter: Gain_Gain_o
  //  Referenced by: '<S10>/Gain'

  -1.0F,

  // Computed Parameter: Constant1_Value_h
  //  Referenced by: '<S78>/Constant1'

  0.0F,

  // Computed Parameter: RateTransition4_InitialConditio
  //  Referenced by: '<S10>/Rate Transition4'

  0.0F,

  // Computed Parameter: RateTransition3_InitialConditio
  //  Referenced by: '<S9>/Rate Transition3'

  0.0F,

  // Computed Parameter: RateTransition_InitialCondition
  //  Referenced by: '<S398>/Rate Transition'

  0.0F,

  // Computed Parameter: RateTransition4_InitialCondit_l
  //  Referenced by: '<S398>/Rate Transition4'

  0.0F,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S595>/Integrator'

  0.001F,

  // Computed Parameter: RateTransition2_InitialConditio
  //  Referenced by: '<S398>/Rate Transition2'

  0.0F,

  // Computed Parameter: UnitDelay1_InitialCondition
  //  Referenced by: '<S560>/Unit Delay1'

  0.0F,

  // Computed Parameter: RateTransition3_InitialCondit_o
  //  Referenced by: '<S398>/Rate Transition3'

  0.0F,

  // Computed Parameter: tau_Gain
  //  Referenced by: '<S560>/tau'

  0.0005F,

  // Computed Parameter: Bias_Bias
  //  Referenced by: '<S561>/Bias'

  1.0F,

  // Computed Parameter: Gain_Gain_f5
  //  Referenced by: '<S561>/Gain'

  1.41421354F,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S557>/TSamp'

  1000.0F,

  // Computed Parameter: RateTransition_InitialConditi_n
  //  Referenced by: '<S397>/Rate Transition'

  0.0F,

  // Computed Parameter: RateTransition4_InitialCondit_d
  //  Referenced by: '<S397>/Rate Transition4'

  0.0F,

  // Computed Parameter: Integrator_gainval_d
  //  Referenced by: '<S540>/Integrator'

  0.001F,

  // Computed Parameter: RateTransition2_InitialCondit_p
  //  Referenced by: '<S397>/Rate Transition2'

  0.0F,

  // Computed Parameter: UnitDelay1_InitialCondition_h
  //  Referenced by: '<S505>/Unit Delay1'

  0.0F,

  // Computed Parameter: RateTransition3_InitialCondit_m
  //  Referenced by: '<S397>/Rate Transition3'

  0.0F,

  // Computed Parameter: tau_Gain_d
  //  Referenced by: '<S505>/tau'

  0.0005F,

  // Computed Parameter: Bias_Bias_o
  //  Referenced by: '<S506>/Bias'

  1.0F,

  // Computed Parameter: Gain_Gain_bi
  //  Referenced by: '<S506>/Gain'

  1.41421354F,

  // Computed Parameter: TSamp_WtEt_g
  //  Referenced by: '<S502>/TSamp'

  1000.0F,

  // Computed Parameter: RateTransition_InitialConditi_c
  //  Referenced by: '<S10>/Rate Transition'

  0.0F,

  // Computed Parameter: RateTransition1_InitialConditio
  //  Referenced by: '<S10>/Rate Transition1'

  0.0F,

  // Computed Parameter: RateTransition_InitialConditi_m
  //  Referenced by: '<S399>/Rate Transition'

  0.0F,

  // Computed Parameter: RateTransition4_InitialCondit_a
  //  Referenced by: '<S399>/Rate Transition4'

  0.0F,

  // Computed Parameter: Integrator_gainval_b
  //  Referenced by: '<S650>/Integrator'

  0.001F,

  // Computed Parameter: RateTransition2_InitialCondit_d
  //  Referenced by: '<S399>/Rate Transition2'

  0.0F,

  // Computed Parameter: UnitDelay1_InitialCondition_c
  //  Referenced by: '<S615>/Unit Delay1'

  0.0F,

  // Computed Parameter: RateTransition3_InitialCondi_o5
  //  Referenced by: '<S399>/Rate Transition3'

  0.0F,

  // Computed Parameter: tau_Gain_m
  //  Referenced by: '<S615>/tau'

  0.0005F,

  // Computed Parameter: Bias_Bias_g
  //  Referenced by: '<S616>/Bias'

  1.0F,

  // Computed Parameter: Gain_Gain_a
  //  Referenced by: '<S616>/Gain'

  1.41421354F,

  // Computed Parameter: TSamp_WtEt_m
  //  Referenced by: '<S612>/TSamp'

  1000.0F,

  // Computed Parameter: Constant_Value_ew
  //  Referenced by: '<S23>/Constant'

  1000.0F,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: '<S23>/Gain'

  0.001F,

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S16>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_lg
  //  Referenced by: '<S17>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S18>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_e3
  //  Referenced by: '<S19>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S20>/Constant'

  1000.0F,

  // Computed Parameter: Constant_Value_lv
  //  Referenced by: '<S21>/Constant'

  1000.0F,

  // Computed Parameter: Bias1_Bias
  //  Referenced by: '<S616>/Bias1'

  1.0F,

  // Computed Parameter: Gain1_Gain_d
  //  Referenced by: '<S615>/Gain1'

  2.0F,

  // Computed Parameter: UnitDelay2_InitialCondition
  //  Referenced by: '<S615>/Unit Delay2'

  0.0F,

  // Computed Parameter: RateTransition1_InitialCondit_d
  //  Referenced by: '<S399>/Rate Transition1'

  0.0F,

  // Computed Parameter: Bias1_Bias_k
  //  Referenced by: '<S506>/Bias1'

  1.0F,

  // Computed Parameter: Gain1_Gain_m
  //  Referenced by: '<S505>/Gain1'

  2.0F,

  // Computed Parameter: UnitDelay2_InitialCondition_b
  //  Referenced by: '<S505>/Unit Delay2'

  0.0F,

  // Computed Parameter: RateTransition1_InitialCondit_f
  //  Referenced by: '<S397>/Rate Transition1'

  0.0F,

  // Computed Parameter: Bias1_Bias_a
  //  Referenced by: '<S561>/Bias1'

  1.0F,

  // Computed Parameter: Gain1_Gain_i
  //  Referenced by: '<S560>/Gain1'

  2.0F,

  // Computed Parameter: UnitDelay2_InitialCondition_e
  //  Referenced by: '<S560>/Unit Delay2'

  0.0F,

  // Computed Parameter: RateTransition1_InitialCondit_p
  //  Referenced by: '<S398>/Rate Transition1'

  0.0F,

  // Computed Parameter: Gain_Gain_az
  //  Referenced by: '<S52>/Gain'

  -1.0F,

  // Computed Parameter: Constant3_Value_h
  //  Referenced by: '<S4>/Constant3'

  1514.0F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<S4>/Gain3'

  0.0025F,

  // Computed Parameter: DeadZone_Start
  //  Referenced by: '<S4>/Dead Zone'

  -0.005F,

  // Computed Parameter: DeadZone_End
  //  Referenced by: '<S4>/Dead Zone'

  0.005F,

  // Computed Parameter: Saturation3_UpperSat
  //  Referenced by: '<S4>/Saturation3'

  1.0F,

  // Computed Parameter: Saturation3_LowerSat
  //  Referenced by: '<S4>/Saturation3'

  -1.0F,

  // Computed Parameter: Constant2_Value_e
  //  Referenced by: '<S4>/Constant2'

  1514.0F,

  // Computed Parameter: Gain1_Gain_f
  //  Referenced by: '<S4>/Gain1'

  0.0025F,

  // Computed Parameter: DeadZone1_Start
  //  Referenced by: '<S4>/Dead Zone1'

  -0.005F,

  // Computed Parameter: DeadZone1_End
  //  Referenced by: '<S4>/Dead Zone1'

  0.005F,

  // Computed Parameter: Saturation2_UpperSat
  //  Referenced by: '<S4>/Saturation2'

  1.0F,

  // Computed Parameter: Saturation2_LowerSat
  //  Referenced by: '<S4>/Saturation2'

  -1.0F,

  // Computed Parameter: Constant1_Value_c
  //  Referenced by: '<S4>/Constant1'

  1514.0F,

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<S4>/Gain2'

  0.0025F,

  // Computed Parameter: DeadZone2_Start
  //  Referenced by: '<S4>/Dead Zone2'

  -0.005F,

  // Computed Parameter: DeadZone2_End
  //  Referenced by: '<S4>/Dead Zone2'

  0.005F,

  // Computed Parameter: Saturation1_UpperSat
  //  Referenced by: '<S4>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat
  //  Referenced by: '<S4>/Saturation1'

  -1.0F,

  // Computed Parameter: DeadZone3_Start
  //  Referenced by: '<S4>/Dead Zone3'

  -0.05F,

  // Computed Parameter: DeadZone3_End
  //  Referenced by: '<S4>/Dead Zone3'

  0.05F,

  // Computed Parameter: Saturation_UpperSat_h
  //  Referenced by: '<S4>/Saturation'

  0.9F,

  // Computed Parameter: Saturation_LowerSat_p
  //  Referenced by: '<S4>/Saturation'

  0.0F,

  // Computed Parameter: DeadZone7_Start
  //  Referenced by: '<S4>/Dead Zone7'

  -0.1F,

  // Computed Parameter: DeadZone7_End
  //  Referenced by: '<S4>/Dead Zone7'

  0.1F,

  // Computed Parameter: Saturation10_UpperSat
  //  Referenced by: '<S4>/Saturation10'

  1.0F,

  // Computed Parameter: Saturation10_LowerSat
  //  Referenced by: '<S4>/Saturation10'

  -1.0F,

  // Computed Parameter: Gain7_Gain
  //  Referenced by: '<S4>/Gain7'

  -1.0F,

  // Computed Parameter: Gain8_Gain
  //  Referenced by: '<S4>/Gain8'

  -1.0F,

  // Computed Parameter: Integrator_gainval_a
  //  Referenced by: '<S88>/Integrator'

  0.004F,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S83>/Filter'

  0.004F,

  // Computed Parameter: Constant4_Value_e
  //  Referenced by: '<S4>/Constant4'

  50.0F,

  // Computed Parameter: Saturation5_UpperSat
  //  Referenced by: '<S4>/Saturation5'

  1.0F,

  // Computed Parameter: Saturation5_LowerSat
  //  Referenced by: '<S4>/Saturation5'

  0.0F,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S4>/Discrete-Time Integrator'

  0.004F,

  // Computed Parameter: DiscreteTimeIntegrator_UpperSat
  //  Referenced by: '<S4>/Discrete-Time Integrator'

  10.0F,

  // Computed Parameter: DiscreteTimeIntegrator_LowerSat
  //  Referenced by: '<S4>/Discrete-Time Integrator'

  -50.0F,

  // Computed Parameter: DiscreteTimeIntegrator1_gainval
  //  Referenced by: '<S4>/Discrete-Time Integrator1'

  0.004F,

  // Computed Parameter: DiscreteTimeIntegrator1_UpperSa
  //  Referenced by: '<S4>/Discrete-Time Integrator1'

  10.0F,

  // Computed Parameter: DiscreteTimeIntegrator1_LowerSa
  //  Referenced by: '<S4>/Discrete-Time Integrator1'

  -50.0F,

  // Computed Parameter: Saturation6_UpperSat
  //  Referenced by: '<S4>/Saturation6'

  0.610865235F,

  // Computed Parameter: Saturation6_LowerSat
  //  Referenced by: '<S4>/Saturation6'

  -0.610865235F,

  // Computed Parameter: Gain11_Gain
  //  Referenced by: '<S4>/Gain11'

  -1.0F,

  // Computed Parameter: TSamp_WtEt_ma
  //  Referenced by: '<S229>/TSamp'

  250.0F,

  // Computed Parameter: Gain_Gain_eb
  //  Referenced by: '<S9>/Gain'

  6.28318548F,

  // Computed Parameter: tau_Gain_f
  //  Referenced by: '<S390>/tau'

  0.002F,

  // Computed Parameter: Bias_Bias_h
  //  Referenced by: '<S391>/Bias'

  1.0F,

  // Computed Parameter: UnitDelay_InitialCondition
  //  Referenced by: '<S390>/Unit Delay'

  0.0F,

  // Computed Parameter: TSamp_WtEt_p
  //  Referenced by: '<S227>/TSamp'

  250.0F,

  // Computed Parameter: TSamp_WtEt_l
  //  Referenced by: '<S228>/TSamp'

  250.0F,

  // Computed Parameter: Filter_gainval_f
  //  Referenced by: '<S318>/Filter'

  0.004F,

  // Computed Parameter: Integrator_gainval_c
  //  Referenced by: '<S373>/Integrator'

  0.004F,

  // Computed Parameter: Constant1_Value_fy
  //  Referenced by: '<S3>/Constant1'

  0.0F,

  // Computed Parameter: u2_Gain
  //  Referenced by: '<S27>/1//2'

  0.5F,

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S3>/Constant'

  0.0F,

  // Computed Parameter: Gain1_Gain_o
  //  Referenced by: '<S205>/Gain1'

  0.0174532924F,

  // Computed Parameter: Gain1_Gain_j
  //  Referenced by: '<S206>/Gain1'

  0.0174532924F,

  // Computed Parameter: Constant3_Value_m
  //  Referenced by: '<S3>/Constant3'

  0.0F,

  // Computed Parameter: DeadZone4_Start
  //  Referenced by: '<S4>/Dead Zone4'

  -0.1F,

  // Computed Parameter: DeadZone4_End
  //  Referenced by: '<S4>/Dead Zone4'

  0.1F,

  // Computed Parameter: Saturation4_UpperSat
  //  Referenced by: '<S4>/Saturation4'

  1.0F,

  // Computed Parameter: Saturation4_LowerSat
  //  Referenced by: '<S4>/Saturation4'

  -1.0F,

  // Computed Parameter: Gain10_Gain
  //  Referenced by: '<S4>/Gain10'

  -1.5F,

  // Computed Parameter: DeadZone6_Start
  //  Referenced by: '<S4>/Dead Zone6'

  -0.1F,

  // Computed Parameter: DeadZone6_End
  //  Referenced by: '<S4>/Dead Zone6'

  0.1F,

  // Computed Parameter: Saturation9_UpperSat
  //  Referenced by: '<S4>/Saturation9'

  1.0F,

  // Computed Parameter: Saturation9_LowerSat
  //  Referenced by: '<S4>/Saturation9'

  -1.0F,

  // Computed Parameter: Saturation2_UpperSat_h
  //  Referenced by: '<S9>/Saturation2'

  2.0F,

  // Computed Parameter: Saturation2_LowerSat_i
  //  Referenced by: '<S9>/Saturation2'

  -2.0F,

  // Computed Parameter: Gain_Gain_ar
  //  Referenced by: '<S391>/Gain'

  -2.0F,

  // Computed Parameter: Bias1_Bias_ka
  //  Referenced by: '<S391>/Bias1'

  1.0F,

  // Computed Parameter: Clamping_zero_Value
  //  Referenced by: '<S78>/Clamping_zero'

  0.0F,

  // Computed Parameter: RateTransition_8_InitialConditi
  //  Referenced by: '<Root>/Rate Transition'

  0U,

  // Computed Parameter: Constant4_Value_f
  //  Referenced by: '<S3>/Constant4'

  { 0U, 0U, 0U, 0U, 0U, 0U },

  // Computed Parameter: Saturation_UpperSat_d
  //  Referenced by: '<S23>/Saturation'

  2000U,

  // Computed Parameter: Saturation_LowerSat_d0
  //  Referenced by: '<S23>/Saturation'

  1000U,

  // Computed Parameter: RateTransition_4_InitialConditi
  //  Referenced by: '<Root>/Rate Transition'

  0U,

  // Computed Parameter: RateTransition6_InitialConditio
  //  Referenced by: '<S398>/Rate Transition6'

  false,

  // Computed Parameter: RateTransition6_InitialCondit_l
  //  Referenced by: '<S397>/Rate Transition6'

  false,

  // Computed Parameter: RateTransition6_InitialCondit_e
  //  Referenced by: '<S399>/Rate Transition6'

  false,

  // Computed Parameter: RateTransition2_16_InitialCondi
  //  Referenced by: '<Root>/Rate Transition2'

  false,

  // Computed Parameter: RateTransition2_17_InitialCondi
  //  Referenced by: '<Root>/Rate Transition2'

  false,

  // Computed Parameter: Constant_Value_kn
  //  Referenced by: '<S78>/Constant'

  1,

  // Computed Parameter: Constant2_Value_nv
  //  Referenced by: '<S78>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_a
  //  Referenced by: '<S78>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_fz
  //  Referenced by: '<S78>/Constant4'

  -1
};

//
// File trailer for generated code.
//
// [EOF]
//
