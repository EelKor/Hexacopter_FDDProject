//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_Hexacopter_V2_data.cpp
//
// Code generated for Simulink model 'FLIGHT_Hexacopter_V2'.
//
// Model version                  : 3.72
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Sep  3 23:21:41 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FLIGHT_Hexacopter_V2.h"

// Block parameters (default storage)
P_FLIGHT_Hexacopter_V2_T FLIGHT_Hexacopter_V2_P = {
  // Variable: MAX_CONTROL_ANGLE_PITCH
  //  Referenced by: 'Gain5' (':386')

  0.52359879F,

  // Variable: MAX_CONTROL_ANGLE_RATE_Y
  //  Referenced by: 'Gain6' (':387')

  2.09439516F,

  // Variable: MAX_CONTROL_ANGLE_ROLL
  //  Referenced by: 'Gain4' (':385')

  0.52359879F,

  // Mask Parameter: DiscretePIDController1_D
  //  Referenced by: 'Derivative Gain' (':1817:688')

  1.0F,

  // Mask Parameter: DiscretePIDController2_I
  //  Referenced by: 'Integral Gain' (':1820:791')

  1.0F,

  // Mask Parameter: DiscreteDerivative2_ICPrevScale
  //  Referenced by: 'UD' (':1966:5')

  0.0F,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_e
  //  Referenced by: 'UD' (':1524:5')

  0.0F,

  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: 'UD' (':1522:5')

  0.0F,

  // Mask Parameter: DiscreteDerivative1_ICPrevScale
  //  Referenced by: 'UD' (':1523:5')

  0.0F,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_o
  //  Referenced by: 'UD' (':1983:5')

  0.0F,

  // Mask Parameter: DiscreteDerivative3_ICPrevScale
  //  Referenced by: 'UD' (':1998:5')

  0.0F,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_n
  //  Referenced by: 'UD' (':1821:1:5')

  0.0F,

  // Mask Parameter: DiscretePIDController1_InitialC
  //  Referenced by: 'Filter' (':1817:737')

  0.0F,

  // Mask Parameter: PID_Altitude1_InitialConditionF
  //  Referenced by: 'Filter' (':514:737')

  0.0F,

  // Mask Parameter: pid_ctrl_rollrate_InitialCondit
  //  Referenced by: 'Integrator' (':1978:843')

  0.0F,

  // Mask Parameter: DiscretePIDController2_InitialC
  //  Referenced by: 'Integrator' (':1820:843')

  0.0F,

  // Mask Parameter: pid_ctrl_rollrate1_InitialCondi
  //  Referenced by: 'Integrator' (':1991:843')

  0.0F,

  // Mask Parameter: pid_ctrl_rollrate2_InitialCondi
  //  Referenced by: 'Integrator' (':2008:843')

  0.0F,

  // Mask Parameter: pid_ctrl_rollrate_InitialCond_p
  //  Referenced by: 'Integrator' (':1821:10:843')

  0.0F,

  // Mask Parameter: PID_Altitude1_InitialConditio_f
  //  Referenced by: 'Integrator' (':514:843')

  0.0F,

  // Mask Parameter: pid_ctrl_rollrate_LowerIntegrat
  //  Referenced by: 'Integrator' (':1978:843')

  -0.06F,

  // Mask Parameter: pid_ctrl_rollrate1_LowerIntegra
  //  Referenced by: 'Integrator' (':1991:843')

  -0.06F,

  // Mask Parameter: pid_ctrl_rollrate2_LowerIntegra
  //  Referenced by: 'Integrator' (':2008:843')

  -0.09F,

  // Mask Parameter: PID_Altitude1_LowerIntegratorSa
  //  Referenced by: 'Integrator' (':514:843')

  -0.157079637F,

  // Mask Parameter: pid_ctrl_rollrate_LowerSaturati
  //  Referenced by:
  //    'Saturation' (':1978:923')
  //    'DeadZone' (':1978:660')

  -0.2F,

  // Mask Parameter: pid_ctrl_rollrate1_LowerSaturat
  //  Referenced by:
  //    'Saturation' (':1991:923')
  //    'DeadZone' (':1991:660')

  -0.2F,

  // Mask Parameter: pid_ctrl_rollrate2_LowerSaturat
  //  Referenced by:
  //    'Saturation' (':2008:923')
  //    'DeadZone' (':2008:660')

  -0.3F,

  // Mask Parameter: DiscretePIDController_LowerSatu
  //  Referenced by: 'Saturation' (':2050:923')

  -5.0F,

  // Mask Parameter: DiscretePIDController1_N
  //  Referenced by: 'Filter Coefficient' (':1817:882')

  100.0F,

  // Mask Parameter: DiscretePIDController1_P
  //  Referenced by: 'Proportional Gain' (':1817:913')

  0.0F,

  // Mask Parameter: pid_ctrl_rollrate_UpperIntegrat
  //  Referenced by: 'Integrator' (':1978:843')

  0.06F,

  // Mask Parameter: pid_ctrl_rollrate1_UpperIntegra
  //  Referenced by: 'Integrator' (':1991:843')

  0.06F,

  // Mask Parameter: pid_ctrl_rollrate2_UpperIntegra
  //  Referenced by: 'Integrator' (':2008:843')

  0.09F,

  // Mask Parameter: PID_Altitude1_UpperIntegratorSa
  //  Referenced by: 'Integrator' (':514:843')

  0.157079637F,

  // Mask Parameter: pid_ctrl_rollrate_UpperSaturati
  //  Referenced by:
  //    'Saturation' (':1978:923')
  //    'DeadZone' (':1978:660')

  0.2F,

  // Mask Parameter: pid_ctrl_rollrate1_UpperSaturat
  //  Referenced by:
  //    'Saturation' (':1991:923')
  //    'DeadZone' (':1991:660')

  0.2F,

  // Mask Parameter: pid_ctrl_rollrate2_UpperSaturat
  //  Referenced by:
  //    'Saturation' (':2008:923')
  //    'DeadZone' (':2008:660')

  0.3F,

  // Mask Parameter: DiscretePIDController_UpperSatu
  //  Referenced by: 'Saturation' (':2050:923')

  5.0F,

  // Mask Parameter: CompareToConstant6_const
  //  Referenced by: 'Constant' (':1881:3')

  0.0F,

  // Mask Parameter: CompareToConstant5_const
  //  Referenced by: 'Constant' (':1880:3')

  0.0F,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: 'Constant' (':1315:3')

  1300U,

  // Mask Parameter: CompareToConstant_const_a
  //  Referenced by: 'Constant' (':1076:3')

  1400U,

  // Mask Parameter: CompareToConstant1_const
  //  Referenced by: 'Constant' (':429:3')

  1400U,

  // Mask Parameter: CompareToConstant2_const
  //  Referenced by: 'Constant' (':449:3')

  1800U,

  // Mask Parameter: CompareToConstant7_const
  //  Referenced by: 'Constant' (':2137:3')

  1800U,

  // Mask Parameter: CompareToConstant4_const
  //  Referenced by: 'Constant' (':1876:3')

  1800U,

  // Mask Parameter: CompareToConstant8_const
  //  Referenced by: 'Constant' (':2138:3')

  1800U,

  // Mask Parameter: CompareToConstant_const_p
  //  Referenced by: 'Constant' (':2118:3')

  1800U,

  // Mask Parameter: CompareToConstant3_const
  //  Referenced by: 'Constant' (':623:3')

  1800U,

  // Mask Parameter: CompareToConstant_const_o
  //  Referenced by: 'Constant' (':1720:3')

  1300U,

  // Mask Parameter: CompareToConstant1_const_j
  //  Referenced by: 'Constant' (':1899:3')

  1800U,

  // Mask Parameter: CompareToConstant_const_j
  //  Referenced by: 'Constant' (':1710:3')

  1800U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: 'Out1' (':320:6')

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
  //  Referenced by: 'Constant' (':320:2')

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
  //  Referenced by: 'Constant' (':1698:17')

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
  //  Referenced by: 'Out1' (':326:6:6')

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
  //  Referenced by: 'Constant' (':326:6:2')

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
  //  Referenced by: 'Constant' (':1288:103:17')

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
  //  Referenced by: 'Out1' (':281:6')

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
  //  Referenced by: 'Constant' (':281:2')

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
  //  Referenced by: 'Out1' (':319:6')

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
  //  Referenced by: 'Constant' (':319:2')

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
  //  Referenced by: 'Constant' (':1256:103:17')

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
  //  Referenced by: 'Constant' (':1230:103:17')

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
  //  Referenced by: 'Out1' (':299:6')

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
  //  Referenced by: 'Constant' (':299:2')

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
  //  Referenced by: 'Constant' (':1251:103:17')

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
  //  Referenced by: 'Constant' (':1210:103:17')

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
  //  Referenced by: 'Out1' (':318:6')

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
  //  Referenced by: 'Out1' (':1186:6')

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
  //  Referenced by: 'Constant' (':318:2')

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
  //  Referenced by: 'Constant' (':1186:2')

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
  //  Referenced by: 'Constant1' (':1078')

  100.0,

  // Expression: 100
  //  Referenced by: 'Constant2' (':1079')

  100.0,

  // Expression: 100
  //  Referenced by: 'Constant3' (':1080')

  100.0,

  // Expression: 100
  //  Referenced by: 'Constant4' (':1081')

  100.0,

  // Expression: 100
  //  Referenced by: 'Constant5' (':1082')

  100.0,

  // Expression: 100
  //  Referenced by: 'Constant' (':1077')

  100.0,

  // Expression: 1
  //  Referenced by: 'Constant' (':1744')

  1.0,

  // Expression: 1
  //  Referenced by: 'Constant1' (':1747')

  1.0,

  // Expression: 1
  //  Referenced by: 'Constant2' (':1748')

  1.0,

  // Expression: 0.01
  //  Referenced by: 'Gain' (':1136:1')

  0.01,

  // Expression: 1
  //  Referenced by: 'Saturation' (':1136:6')

  1.0,

  // Expression: 0
  //  Referenced by: 'Saturation' (':1136:6')

  0.0,

  // Expression: 0.01
  //  Referenced by: 'Gain' (':1137:1')

  0.01,

  // Expression: 1
  //  Referenced by: 'Saturation' (':1137:6')

  1.0,

  // Expression: 0
  //  Referenced by: 'Saturation' (':1137:6')

  0.0,

  // Expression: 0.01
  //  Referenced by: 'Gain' (':1138:1')

  0.01,

  // Expression: 1
  //  Referenced by: 'Saturation' (':1138:6')

  1.0,

  // Expression: 0
  //  Referenced by: 'Saturation' (':1138:6')

  0.0,

  // Expression: 0.01
  //  Referenced by: 'Gain' (':1139:1')

  0.01,

  // Expression: 1
  //  Referenced by: 'Saturation' (':1139:6')

  1.0,

  // Expression: 0
  //  Referenced by: 'Saturation' (':1139:6')

  0.0,

  // Expression: 0.01
  //  Referenced by: 'Gain' (':1140:1')

  0.01,

  // Expression: 1
  //  Referenced by: 'Saturation' (':1140:6')

  1.0,

  // Expression: 0
  //  Referenced by: 'Saturation' (':1140:6')

  0.0,

  // Expression: 0.01
  //  Referenced by: 'Gain' (':1141:1')

  0.01,

  // Expression: 1
  //  Referenced by: 'Saturation' (':1141:6')

  1.0,

  // Expression: 0
  //  Referenced by: 'Saturation' (':1141:6')

  0.0,

  // Expression: 1094
  //  Referenced by: 'Constant' (':352')

  1094.0,

  // Expression: 1/800
  //  Referenced by: 'Gain' (':380')

  0.00125,

  // Expression: 5
  //  Referenced by: 'Constant5' (':2114')

  5.0,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: 'Gain1' (':683')

  -1.0F,

  // Computed Parameter: Gain_Gain_o
  //  Referenced by: 'Gain' (':682')

  -1.0F,

  // Computed Parameter: Constant1_Value_j
  //  Referenced by: 'Constant1' (':1978:655')

  0.0F,

  // Computed Parameter: Constant1_Value_jy
  //  Referenced by: 'Constant1' (':1991:655')

  0.0F,

  // Computed Parameter: Constant1_Value_i
  //  Referenced by: 'Constant1' (':2008:655')

  0.0F,

  // Computed Parameter: Mixermatrix_Value
  //  Referenced by: 'Mixer matrix' (':160:192')

  { 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, -1.0F, 1.0F, 0.5F, -0.5F, -0.5F, 0.5F,
    0.0F, 0.0F, 0.87F, -0.87F, 0.87F, -0.87F, -1.0F, 1.0F, -1.0F, 1.0F, 1.0F,
    -1.0F },

  // Computed Parameter: Constant1_Value_k
  //  Referenced by: 'Constant1' (':160:2981')

  1000.0F,

  // Computed Parameter: RateTransition4_InitialConditio
  //  Referenced by: 'Rate Transition4' (':1068')

  0.0F,

  // Computed Parameter: RateTransition5_InitialConditio
  //  Referenced by: 'Rate Transition5' (':1981')

  0.0F,

  // Computed Parameter: RateTransition2_InitialConditio
  //  Referenced by: 'Rate Transition2' (':1974')

  0.0F,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: 'Integrator' (':1978:843')

  0.001F,

  // Computed Parameter: RateTransition18_InitialConditi
  //  Referenced by: 'Rate Transition18' (':2012')

  0.0F,

  // Computed Parameter: UnitDelay1_InitialCondition
  //  Referenced by: 'Unit Delay1' (':1967:220:338')

  0.0F,

  // Computed Parameter: RateTransition3_InitialConditio
  //  Referenced by: 'Rate Transition3' (':1980')

  0.0F,

  // Computed Parameter: tau_Gain
  //  Referenced by: 'tau' (':1967:220:372')

  0.0005F,

  // Computed Parameter: Bias_Bias
  //  Referenced by: 'Bias' (':1967:220:373')

  1.0F,

  // Computed Parameter: Gain_Gain_a
  //  Referenced by: 'Gain' (':1967:220:358')

  1.41421354F,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: 'TSamp' (':1966:4')

  1000.0F,

  // Computed Parameter: RateTransition2_InitialCondit_h
  //  Referenced by: 'Rate Transition2' (':884')

  0.0F,

  // Computed Parameter: TSamp_WtEt_m
  //  Referenced by: 'TSamp' (':1524:4')

  1000.0F,

  // Computed Parameter: RateTransition4_InitialCondit_m
  //  Referenced by: 'Rate Transition4' (':1912')

  0.0F,

  // Computed Parameter: RateTransition5_InitialCondit_g
  //  Referenced by: 'Rate Transition5' (':1913')

  0.0F,

  // Computed Parameter: RateTransition6_InitialConditio
  //  Referenced by: 'Rate Transition6' (':1914')

  0.0F,

  // Computed Parameter: RateTransition9_InitialConditio
  //  Referenced by: 'Rate Transition9' (':1917')

  0.0F,

  // Computed Parameter: RateTransition10_InitialConditi
  //  Referenced by: 'Rate Transition10' (':1918')

  0.0F,

  // Computed Parameter: RateTransition11_InitialConditi
  //  Referenced by: 'Rate Transition11' (':1919')

  0.0F,

  // Computed Parameter: RateTransition17_InitialConditi
  //  Referenced by: 'Rate Transition17' (':1927')

  0.0F,

  // Computed Parameter: tau_Gain_f
  //  Referenced by: 'tau' (':1756:219:350')

  0.0005F,

  // Computed Parameter: Bias_Bias_h
  //  Referenced by: 'Bias' (':1756:219:351')

  1.0F,

  // Computed Parameter: RateTransition1_InitialConditio
  //  Referenced by: 'Rate Transition1' (':1911')

  0.0F,

  // Computed Parameter: UnitDelay_InitialCondition
  //  Referenced by: 'Unit Delay' (':1756:219:331')

  0.0F,

  // Computed Parameter: TSamp_WtEt_p
  //  Referenced by: 'TSamp' (':1522:4')

  1000.0F,

  // Computed Parameter: TSamp_WtEt_l
  //  Referenced by: 'TSamp' (':1523:4')

  1000.0F,

  // Computed Parameter: RateTransition7_InitialConditio
  //  Referenced by: 'Rate Transition7' (':1915')

  0.0F,

  // Computed Parameter: RateTransition8_InitialConditio
  //  Referenced by: 'Rate Transition8' (':1916')

  0.0F,

  // Computed Parameter: RateTransition12_InitialConditi
  //  Referenced by: 'Rate Transition12' (':1920')

  0.0F,

  // Computed Parameter: RateTransition13_InitialConditi
  //  Referenced by: 'Rate Transition13' (':1921')

  0.0F,

  // Computed Parameter: RateTransition14_InitialConditi
  //  Referenced by: 'Rate Transition14' (':1922')

  0.0F,

  // Computed Parameter: Filter_gainval
  //  Referenced by: 'Filter' (':1817:737')

  0.001F,

  // Computed Parameter: Integrator_gainval_c
  //  Referenced by: 'Integrator' (':1820:843')

  0.001F,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: 'Discrete-Time Integrator' (':1887')

  0.001F,

  // Computed Parameter: DiscreteTimeIntegrator_IC
  //  Referenced by: 'Discrete-Time Integrator' (':1887')

  0.0F,

  // Computed Parameter: Saturation2_UpperSat
  //  Referenced by: 'Saturation2' (':1581')

  2.0F,

  // Computed Parameter: Saturation2_LowerSat
  //  Referenced by: 'Saturation2' (':1581')

  -2.0F,

  // Computed Parameter: RateTransition8_InitialCondit_c
  //  Referenced by: 'Rate Transition8' (':1988')

  0.0F,

  // Computed Parameter: RateTransition19_InitialConditi
  //  Referenced by: 'Rate Transition19' (':2013')

  0.0F,

  // Computed Parameter: Integrator_gainval_l
  //  Referenced by: 'Integrator' (':1991:843')

  0.001F,

  // Computed Parameter: RateTransition10_InitialCondi_k
  //  Referenced by: 'Rate Transition10' (':1995')

  0.0F,

  // Computed Parameter: UnitDelay1_InitialCondition_i
  //  Referenced by: 'Unit Delay1' (':1984:220:338')

  0.0F,

  // Computed Parameter: RateTransition7_InitialCondit_l
  //  Referenced by: 'Rate Transition7' (':1987')

  0.0F,

  // Computed Parameter: tau_Gain_k
  //  Referenced by: 'tau' (':1984:220:372')

  0.0005F,

  // Computed Parameter: Bias_Bias_b
  //  Referenced by: 'Bias' (':1984:220:373')

  1.0F,

  // Computed Parameter: Gain_Gain_b3
  //  Referenced by: 'Gain' (':1984:220:358')

  1.41421354F,

  // Computed Parameter: TSamp_WtEt_d
  //  Referenced by: 'TSamp' (':1983:4')

  1000.0F,

  // Computed Parameter: RateTransition_InitialCondition
  //  Referenced by: 'Rate Transition' (':732')

  0.0F,

  // Computed Parameter: RateTransition1_InitialCondit_e
  //  Referenced by: 'Rate Transition1' (':733')

  0.0F,

  // Computed Parameter: RateTransition13_InitialCondi_h
  //  Referenced by: 'Rate Transition13' (':2004')

  0.0F,

  // Computed Parameter: RateTransition20_InitialConditi
  //  Referenced by: 'Rate Transition20' (':2014')

  0.0F,

  // Computed Parameter: Integrator_gainval_e
  //  Referenced by: 'Integrator' (':2008:843')

  0.001F,

  // Computed Parameter: RateTransition11_InitialCondi_g
  //  Referenced by: 'Rate Transition11' (':2002')

  0.0F,

  // Computed Parameter: UnitDelay1_InitialCondition_m
  //  Referenced by: 'Unit Delay1' (':1999:220:338')

  0.0F,

  // Computed Parameter: RateTransition12_InitialCondi_h
  //  Referenced by: 'Rate Transition12' (':2003')

  0.0F,

  // Computed Parameter: tau_Gain_d
  //  Referenced by: 'tau' (':1999:220:372')

  0.0005F,

  // Computed Parameter: Bias_Bias_p
  //  Referenced by: 'Bias' (':1999:220:373')

  1.0F,

  // Computed Parameter: Gain_Gain_ow
  //  Referenced by: 'Gain' (':1999:220:358')

  1.41421354F,

  // Computed Parameter: TSamp_WtEt_b
  //  Referenced by: 'TSamp' (':1998:4')

  1000.0F,

  // Computed Parameter: Saturation1_UpperSat
  //  Referenced by: 'Saturation1' (':160:198')

  1.0F,

  // Computed Parameter: Saturation1_LowerSat
  //  Referenced by: 'Saturation1' (':160:198')

  0.0F,

  // Computed Parameter: Gain2_Gain
  //  Referenced by: 'Gain2' (':160:2979')

  1000.0F,

  // Computed Parameter: Constant_Value_ew
  //  Referenced by: 'Constant' (':1282')

  1000.0F,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: 'Gain' (':1283')

  0.001F,

  // Computed Parameter: Constant_Value_b
  //  Referenced by: 'Constant' (':1136:4658')

  1000.0F,

  // Computed Parameter: Constant_Value_lg
  //  Referenced by: 'Constant' (':1137:4658')

  1000.0F,

  // Computed Parameter: Constant_Value_n
  //  Referenced by: 'Constant' (':1138:4658')

  1000.0F,

  // Computed Parameter: Constant_Value_e3
  //  Referenced by: 'Constant' (':1139:4658')

  1000.0F,

  // Computed Parameter: Constant_Value_d
  //  Referenced by: 'Constant' (':1140:4658')

  1000.0F,

  // Computed Parameter: Constant_Value_lv
  //  Referenced by: 'Constant' (':1141:4658')

  1000.0F,

  // Computed Parameter: Bias1_Bias
  //  Referenced by: 'Bias1' (':1999:220:375')

  1.0F,

  // Computed Parameter: Gain1_Gain_b
  //  Referenced by: 'Gain1' (':1999:220:340')

  2.0F,

  // Computed Parameter: UnitDelay2_InitialCondition
  //  Referenced by: 'Unit Delay2' (':1999:220:342')

  0.0F,

  // Computed Parameter: Clamping_zero_Value
  //  Referenced by: 'Clamping_zero' (':2008:4030')

  0.0F,

  // Computed Parameter: RateTransition14_InitialCondi_f
  //  Referenced by: 'Rate Transition14' (':2005')

  0.0F,

  // Computed Parameter: Bias1_Bias_o
  //  Referenced by: 'Bias1' (':1984:220:375')

  1.0F,

  // Computed Parameter: Gain1_Gain_l
  //  Referenced by: 'Gain1' (':1984:220:340')

  2.0F,

  // Computed Parameter: UnitDelay2_InitialCondition_i
  //  Referenced by: 'Unit Delay2' (':1984:220:342')

  0.0F,

  // Computed Parameter: Clamping_zero_Value_a
  //  Referenced by: 'Clamping_zero' (':1991:4030')

  0.0F,

  // Computed Parameter: RateTransition9_InitialCondit_i
  //  Referenced by: 'Rate Transition9' (':1989')

  0.0F,

  // Computed Parameter: Gain_Gain_ar
  //  Referenced by: 'Gain' (':1756:219:343')

  -2.0F,

  // Computed Parameter: Bias1_Bias_k
  //  Referenced by: 'Bias1' (':1756:219:352')

  1.0F,

  // Computed Parameter: Bias1_Bias_f
  //  Referenced by: 'Bias1' (':1967:220:375')

  1.0F,

  // Computed Parameter: Gain1_Gain_h
  //  Referenced by: 'Gain1' (':1967:220:340')

  2.0F,

  // Computed Parameter: UnitDelay2_InitialCondition_n
  //  Referenced by: 'Unit Delay2' (':1967:220:342')

  0.0F,

  // Computed Parameter: Clamping_zero_Value_b
  //  Referenced by: 'Clamping_zero' (':1978:4030')

  0.0F,

  // Computed Parameter: RateTransition6_InitialCondit_f
  //  Referenced by: 'Rate Transition6' (':1982')

  0.0F,

  // Computed Parameter: Constant3_Value_h
  //  Referenced by: 'Constant3' (':355')

  1514.0F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: 'Gain3' (':384')

  0.0025F,

  // Computed Parameter: DeadZone_Start
  //  Referenced by: 'Dead Zone' (':364')

  -0.005F,

  // Computed Parameter: DeadZone_End
  //  Referenced by: 'Dead Zone' (':364')

  0.005F,

  // Computed Parameter: Saturation3_UpperSat
  //  Referenced by: 'Saturation3' (':404')

  1.0F,

  // Computed Parameter: Saturation3_LowerSat
  //  Referenced by: 'Saturation3' (':404')

  -1.0F,

  // Computed Parameter: Constant2_Value_e
  //  Referenced by: 'Constant2' (':354')

  1514.0F,

  // Computed Parameter: Gain1_Gain_f
  //  Referenced by: 'Gain1' (':381')

  0.0025F,

  // Computed Parameter: DeadZone1_Start
  //  Referenced by: 'Dead Zone1' (':365')

  -0.005F,

  // Computed Parameter: DeadZone1_End
  //  Referenced by: 'Dead Zone1' (':365')

  0.005F,

  // Computed Parameter: Saturation2_UpperSat_c
  //  Referenced by: 'Saturation2' (':403')

  1.0F,

  // Computed Parameter: Saturation2_LowerSat_h
  //  Referenced by: 'Saturation2' (':403')

  -1.0F,

  // Computed Parameter: Constant1_Value_c
  //  Referenced by: 'Constant1' (':353')

  1514.0F,

  // Computed Parameter: Gain2_Gain_l
  //  Referenced by: 'Gain2' (':383')

  0.0025F,

  // Computed Parameter: DeadZone2_Start
  //  Referenced by: 'Dead Zone2' (':366')

  -0.005F,

  // Computed Parameter: DeadZone2_End
  //  Referenced by: 'Dead Zone2' (':366')

  0.005F,

  // Computed Parameter: Saturation1_UpperSat_p
  //  Referenced by: 'Saturation1' (':401')

  1.0F,

  // Computed Parameter: Saturation1_LowerSat_e
  //  Referenced by: 'Saturation1' (':401')

  -1.0F,

  // Computed Parameter: DeadZone3_Start
  //  Referenced by: 'Dead Zone3' (':367')

  -0.005F,

  // Computed Parameter: DeadZone3_End
  //  Referenced by: 'Dead Zone3' (':367')

  0.005F,

  // Computed Parameter: Saturation_UpperSat_h
  //  Referenced by: 'Saturation' (':400')

  0.9F,

  // Computed Parameter: Saturation_LowerSat_p
  //  Referenced by: 'Saturation' (':400')

  0.0F,

  // Computed Parameter: DeadZone7_Start
  //  Referenced by: 'Dead Zone7' (':370')

  -0.1F,

  // Computed Parameter: DeadZone7_End
  //  Referenced by: 'Dead Zone7' (':370')

  0.1F,

  // Computed Parameter: Saturation10_UpperSat
  //  Referenced by: 'Saturation10' (':402')

  1.0F,

  // Computed Parameter: Saturation10_LowerSat
  //  Referenced by: 'Saturation10' (':402')

  -1.0F,

  // Computed Parameter: Gain7_Gain
  //  Referenced by: 'Gain7' (':1862')

  -1.0F,

  // Computed Parameter: Integrator_gainval_ei
  //  Referenced by: 'Integrator' (':1821:10:843')

  0.004F,

  // Computed Parameter: UnitDelay1_InitialCondition_e
  //  Referenced by: 'Unit Delay1' (':1821:2:220:338')

  0.0F,

  // Computed Parameter: tau_Gain_g
  //  Referenced by: 'tau' (':1821:2:220:372')

  0.002F,

  // Computed Parameter: Bias_Bias_n
  //  Referenced by: 'Bias' (':1821:2:220:373')

  1.0F,

  // Computed Parameter: Gain_Gain_oj
  //  Referenced by: 'Gain' (':1821:2:220:358')

  1.41421354F,

  // Computed Parameter: TSamp_WtEt_n
  //  Referenced by: 'TSamp' (':1821:1:4')

  250.0F,

  // Computed Parameter: DeadZone6_Start
  //  Referenced by: 'Dead Zone6' (':369')

  -0.05F,

  // Computed Parameter: DeadZone6_End
  //  Referenced by: 'Dead Zone6' (':369')

  0.05F,

  // Computed Parameter: Saturation9_UpperSat
  //  Referenced by: 'Saturation9' (':407')

  1.0F,

  // Computed Parameter: Saturation9_LowerSat
  //  Referenced by: 'Saturation9' (':407')

  -1.0F,

  // Computed Parameter: Gain8_Gain
  //  Referenced by: 'Gain8' (':1882')

  1.0F,

  // Computed Parameter: DeadZone4_Start
  //  Referenced by: 'Dead Zone4' (':368')

  -0.05F,

  // Computed Parameter: DeadZone4_End
  //  Referenced by: 'Dead Zone4' (':368')

  0.05F,

  // Computed Parameter: Saturation4_UpperSat
  //  Referenced by: 'Saturation4' (':405')

  1.0F,

  // Computed Parameter: Saturation4_LowerSat
  //  Referenced by: 'Saturation4' (':405')

  -1.0F,

  // Computed Parameter: Gain9_Gain
  //  Referenced by: 'Gain9' (':1883')

  -1.0F,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_h
  //  Referenced by: 'Discrete-Time Integrator' (':436')

  0.004F,

  // Computed Parameter: DiscreteTimeIntegrator1_gainval
  //  Referenced by: 'Discrete-Time Integrator1' (':437')

  0.004F,

  // Computed Parameter: Integrator_gainval_f
  //  Referenced by: 'Integrator' (':514:843')

  0.004F,

  // Computed Parameter: Constant4_Value_b
  //  Referenced by: 'Constant4' (':2034')

  100.0F,

  // Computed Parameter: Filter_gainval_f
  //  Referenced by: 'Filter' (':514:737')

  0.004F,

  // Computed Parameter: Constant1_Value_fy
  //  Referenced by: 'Constant1' (':1239')

  0.0F,

  // Computed Parameter: u2_Gain
  //  Referenced by: '1//2' (':1231:2')

  0.5F,

  // Computed Parameter: Constant_Value_i
  //  Referenced by: 'Constant' (':1224')

  0.0F,

  // Computed Parameter: Gain1_Gain_o
  //  Referenced by: 'Gain1' (':190:180')

  0.0174532924F,

  // Computed Parameter: Gain1_Gain_j
  //  Referenced by: 'Gain1' (':191:180')

  0.0174532924F,

  // Computed Parameter: Constant3_Value_m
  //  Referenced by: 'Constant3' (':1247')

  0.0F,

  // Computed Parameter: Bias1_Bias_m
  //  Referenced by: 'Bias1' (':1821:2:220:375')

  1.0F,

  // Computed Parameter: Gain1_Gain_a
  //  Referenced by: 'Gain1' (':1821:2:220:340')

  2.0F,

  // Computed Parameter: UnitDelay2_InitialCondition_m
  //  Referenced by: 'Unit Delay2' (':1821:2:220:342')

  0.0F,

  // Computed Parameter: Gain_Gain_eb
  //  Referenced by: 'Gain' (':1763')

  6.28318548F,

  // Computed Parameter: RateTransition_8_InitialConditi
  //  Referenced by: 'Rate Transition' (':1176')

  0U,

  // Computed Parameter: Constant4_Value_f
  //  Referenced by: 'Constant4' (':1269')

  { 0U, 0U, 0U, 0U, 0U, 0U },

  // Computed Parameter: Saturation_UpperSat_d
  //  Referenced by: 'Saturation' (':1284')

  2000U,

  // Computed Parameter: Saturation_LowerSat_d0
  //  Referenced by: 'Saturation' (':1284')

  1000U,

  // Computed Parameter: RateTransition_4_InitialConditi
  //  Referenced by: 'Rate Transition' (':1176')

  0U,

  // Computed Parameter: Switch_Threshold
  //  Referenced by: 'Switch' (':2119')

  1800U,

  // Computed Parameter: RateTransition15_InitialConditi
  //  Referenced by: 'Rate Transition15' (':2009')

  false,

  // Computed Parameter: RateTransition16_InitialConditi
  //  Referenced by: 'Rate Transition16' (':1925')

  false,

  // Computed Parameter: RateTransition15_InitialCondi_p
  //  Referenced by: 'Rate Transition15' (':1924')

  false,

  // Computed Parameter: RateTransition16_InitialCondi_i
  //  Referenced by: 'Rate Transition16' (':2010')

  false,

  // Computed Parameter: RateTransition17_InitialCondi_p
  //  Referenced by: 'Rate Transition17' (':2011')

  false,

  // Computed Parameter: RateTransition2_16_InitialCondi
  //  Referenced by: 'Rate Transition2' (':1298')

  false,

  // Computed Parameter: RateTransition2_17_InitialCondi
  //  Referenced by: 'Rate Transition2' (':1298')

  false,

  // Computed Parameter: Constant_Value_dr
  //  Referenced by: 'Constant' (':1978:3944')

  1,

  // Computed Parameter: Constant2_Value_ns
  //  Referenced by: 'Constant2' (':1978:3945')

  -1,

  // Computed Parameter: Constant3_Value_n
  //  Referenced by: 'Constant3' (':1978:3947')

  1,

  // Computed Parameter: Constant4_Value_bo
  //  Referenced by: 'Constant4' (':1978:3948')

  -1,

  // Computed Parameter: Constant_Value_fd
  //  Referenced by: 'Constant' (':1991:3944')

  1,

  // Computed Parameter: Constant2_Value_g
  //  Referenced by: 'Constant2' (':1991:3945')

  -1,

  // Computed Parameter: Constant3_Value_b
  //  Referenced by: 'Constant3' (':1991:3947')

  1,

  // Computed Parameter: Constant4_Value_h
  //  Referenced by: 'Constant4' (':1991:3948')

  -1,

  // Computed Parameter: Constant_Value_gl
  //  Referenced by: 'Constant' (':2008:3944')

  1,

  // Computed Parameter: Constant2_Value_i
  //  Referenced by: 'Constant2' (':2008:3945')

  -1,

  // Computed Parameter: Constant3_Value_nf
  //  Referenced by: 'Constant3' (':2008:3947')

  1,

  // Computed Parameter: Constant4_Value_e
  //  Referenced by: 'Constant4' (':2008:3948')

  -1
};

//
// File trailer for generated code.
//
// [EOF]
//
