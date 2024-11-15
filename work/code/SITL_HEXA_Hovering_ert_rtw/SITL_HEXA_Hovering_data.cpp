//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: SITL_HEXA_Hovering_data.cpp
//
// Code generated for Simulink model 'SITL_HEXA_Hovering'.
//
// Model version                  : 5.7
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Oct 16 15:41:08 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "SITL_HEXA_Hovering.h"

// Block parameters (default storage)
P_SITL_HEXA_Hovering_T SITL_HEXA_Hovering_P = {
  // Variable: MC_PITCHRATE_D
  //  Referenced by: '<S475>/Derivative Gain'

  0.001,

  // Variable: MC_PITCHRATE_I
  //  Referenced by: '<S479>/Integral Gain'

  0.04,

  // Variable: MC_PITCHRATE_P
  //  Referenced by: '<S487>/Proportional Gain'

  0.08,

  // Variable: MC_PITCH_P
  //  Referenced by: '<S71>/Proportional Gain'

  9.0,

  // Variable: MC_ROLLRATE_D
  //  Referenced by: '<S527>/Derivative Gain'

  0.001,

  // Variable: MC_ROLLRATE_I
  //  Referenced by: '<S531>/Integral Gain'

  0.04,

  // Variable: MC_ROLLRATE_P
  //  Referenced by: '<S539>/Proportional Gain'

  0.08,

  // Variable: MC_ROLL_P
  //  Referenced by: '<S121>/Proportional Gain'

  9.0,

  // Variable: MC_YAWRATE_D
  //  Referenced by: '<S423>/Derivative Gain'

  0.0,

  // Variable: MC_YAWRATE_I
  //  Referenced by: '<S427>/Integral Gain'

  0.1,

  // Variable: MC_YAWRATE_P
  //  Referenced by: '<S435>/Proportional Gain'

  0.2,

  // Variable: MC_YAW_P
  //  Referenced by: '<S171>/Proportional Gain'

  2.8,

  // Variable: MPC_XY_P
  //  Referenced by: '<S278>/Proportional Gain'

  1.0,

  // Variable: MPC_XY_VEL_MAX
  //  Referenced by: '<S280>/Saturation'

  4.0,

  // Variable: MPC_Z_P
  //  Referenced by: '<S328>/Proportional Gain'

  1.0,

  // Variable: MPC_Z_VEL_D_ACC
  //  Referenced by: '<S368>/Derivative Gain'

  0.05,

  // Variable: MPC_Z_VEL_I_ACC
  //  Referenced by: '<S372>/Integral Gain'

  0.1,

  // Variable: MPC_Z_VEL_MAX_DN
  //  Referenced by: '<S330>/Saturation'

  2.0,

  // Variable: MPC_Z_VEL_MAX_UP
  //  Referenced by: '<S330>/Saturation'

  2.0,

  // Variable: MPC_Z_VEL_P_ACC
  //  Referenced by: '<S380>/Proportional Gain'

  0.5,

  // Mask Parameter: PID_vz_InitialConditionForFilter
  //  Referenced by: '<S370>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditionForFilter
  //  Referenced by: '<S425>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialConditionForFilter
  //  Referenced by: '<S477>/Filter'

  0.0,

  // Mask Parameter: PIDController2_InitialConditionForFilter
  //  Referenced by: '<S529>/Filter'

  0.0,

  // Mask Parameter: PID_vz_InitialConditionForIntegrator
  //  Referenced by: '<S375>/Integrator'

  0.0,

  // Mask Parameter: PIDController_InitialConditionForIntegrator
  //  Referenced by: '<S430>/Integrator'

  0.0,

  // Mask Parameter: PIDController1_InitialConditionForIntegrator
  //  Referenced by: '<S482>/Integrator'

  0.0,

  // Mask Parameter: PIDController2_InitialConditionForIntegrator
  //  Referenced by: '<S534>/Integrator'

  0.0,

  // Mask Parameter: PIDController5_LowerSaturationLimit
  //  Referenced by: '<S173>/Saturation'

  -0.87266462599716477,

  // Mask Parameter: PID_vz_LowerSaturationLimit
  //  Referenced by:
  //    '<S382>/Saturation'
  //    '<S367>/DeadZone'

  0.0,

  // Mask Parameter: PIDController_LowerSaturationLimit
  //  Referenced by: '<S230>/Saturation'

  -0.3490658503988659,

  // Mask Parameter: PIDController_LowerSaturationLimit_b
  //  Referenced by:
  //    '<S437>/Saturation'
  //    '<S422>/DeadZone'

  -0.1,

  // Mask Parameter: PIDController1_LowerSaturationLimit
  //  Referenced by:
  //    '<S489>/Saturation'
  //    '<S474>/DeadZone'

  -0.2,

  // Mask Parameter: PIDController2_LowerSaturationLimit
  //  Referenced by:
  //    '<S541>/Saturation'
  //    '<S526>/DeadZone'

  -0.2,

  // Mask Parameter: PID_vz_N
  //  Referenced by: '<S378>/Filter Coefficient'

  10.0,

  // Mask Parameter: PIDController_N
  //  Referenced by: '<S433>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController1_N
  //  Referenced by: '<S485>/Filter Coefficient'

  50.0,

  // Mask Parameter: PIDController2_N
  //  Referenced by: '<S537>/Filter Coefficient'

  50.0,

  // Mask Parameter: PIDController_P
  //  Referenced by: '<S228>/Proportional Gain'

  0.3,

  // Mask Parameter: PIDController5_UpperSaturationLimit
  //  Referenced by: '<S173>/Saturation'

  0.87266462599716477,

  // Mask Parameter: PID_vz_UpperSaturationLimit
  //  Referenced by:
  //    '<S382>/Saturation'
  //    '<S367>/DeadZone'

  1.0,

  // Mask Parameter: PIDController_UpperSaturationLimit
  //  Referenced by: '<S230>/Saturation'

  0.3490658503988659,

  // Mask Parameter: PIDController_UpperSaturationLimit_p
  //  Referenced by:
  //    '<S437>/Saturation'
  //    '<S422>/DeadZone'

  0.1,

  // Mask Parameter: PIDController1_UpperSaturationLimit
  //  Referenced by:
  //    '<S489>/Saturation'
  //    '<S474>/DeadZone'

  0.2,

  // Mask Parameter: PIDController2_UpperSaturationLimit
  //  Referenced by:
  //    '<S541>/Saturation'
  //    '<S526>/DeadZone'

  0.2,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S570>/Constant'

  5U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S577>/Out1'

  {
    (0ULL),                            // timestamp
    0U,                                // type

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // _padding0

    {
      {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      } }
    // waypoints
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S582>/Constant'

  {
    (0ULL),                            // timestamp
    0U,                                // type

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // _padding0

    {
      {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      } }
    // waypoints
  },

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S576>/Constant'

  {
    (0ULL),                            // timestamp
    0U,                                // type

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // _padding0

    {
      {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      } }
    // waypoints
  },

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S589>/Out1'

  {
    (0ULL),                            // timestamp

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    },                                 // previous

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    },                                 // current

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    }                                  // next
  },

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S574>/Constant'

  {
    (0ULL),                            // timestamp

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    },                                 // previous

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    },                                 // current

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    }                                  // next
  },

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S609>/Out1'

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

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S605>/Constant'

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

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S600>/Constant'

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

  // Computed Parameter: Out1_Y0_f
  //  Referenced by: '<S599>/Out1'

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

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S598>/Constant'

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

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S590>/Constant'

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
  //  Referenced by: '<S16>/Constant'

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

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S608>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_lh
  //  Referenced by: '<S604>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S14>/Constant'

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

  // Computed Parameter: Out1_Y0_o
  //  Referenced by: '<S588>/Out1'

  {
    (0ULL),                            // timestamp
    0.0,                               // lat
    0.0,                               // lon
    0.0F,                              // alt
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // yaw
    false,                             // valid_alt
    false,                             // valid_hpos
    false,                             // valid_lpos
    false                              // manual_home
  },

  // Computed Parameter: Constant_Value_b0
  //  Referenced by: '<S573>/Constant'

  {
    (0ULL),                            // timestamp
    0.0,                               // lat
    0.0,                               // lon
    0.0F,                              // alt
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // yaw
    false,                             // valid_alt
    false,                             // valid_hpos
    false,                             // valid_lpos
    false                              // manual_home
  },

  // Computed Parameter: Out1_Y0_e
  //  Referenced by: '<S606>/Out1'

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

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S602>/Constant'

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

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S18>/Constant'

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

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S607>/Out1'

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

  // Computed Parameter: Constant_Value_jl
  //  Referenced by: '<S603>/Constant'

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

  // Expression: [1 0 0 0]
  //  Referenced by: '<S9>/Constant'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<S24>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S25>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S29>/Switch1'

  0.0,

  // Computed Parameter: Yawrate_sp_Y0
  //  Referenced by: '<S11>/Yawrate_sp'

  0.0,

  // Computed Parameter: Pitchrate_sp_Y0
  //  Referenced by: '<S11>/Pitchrate_sp'

  0.0,

  // Computed Parameter: Rollrate_spl_Y0
  //  Referenced by: '<S11>/Rollrate_spl'

  0.0,

  // Expression: 2*pi
  //  Referenced by: '<S29>/Constant'

  6.2831853071795862,

  // Expression: pi
  //  Referenced by: '<S29>/Switch'

  3.1415926535897931,

  // Expression: 180*pi/180
  //  Referenced by: '<S11>/Rate Limiter2'

  3.1415926535897931,

  // Expression: -180*pi/180
  //  Referenced by: '<S11>/Rate Limiter2'

  -3.1415926535897931,

  // Expression: 0
  //  Referenced by: '<S11>/Rate Limiter2'

  0.0,

  // Expression: 180*pi/180
  //  Referenced by: '<S11>/Rate Limiter1'

  3.1415926535897931,

  // Expression: -180*pi/180
  //  Referenced by: '<S11>/Rate Limiter1'

  -3.1415926535897931,

  // Expression: 0
  //  Referenced by: '<S11>/Rate Limiter1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S183>/Constant'

  0.0,

  // Computed Parameter: tau_Thrust_Y0
  //  Referenced by: '<S12>/tau_Thrust'

  0.0,

  // Computed Parameter: des_pitch_Y0
  //  Referenced by: '<S12>/des_pitch'

  0.0,

  // Computed Parameter: des_roll_Y0
  //  Referenced by: '<S12>/des_roll'

  0.0,

  // Computed Parameter: XY_velocity_setpoint_Y0
  //  Referenced by: '<S12>/XY_velocity_setpoint'

  0.0,

  // Computed Parameter: Z_velocity_setpoint_Y0
  //  Referenced by: '<S12>/Z_velocity_setpoint'

  0.0,

  // Expression: 0
  //  Referenced by: '<S365>/Constant1'

  0.0,

  // Expression: -1
  //  Referenced by: '<S183>/Gain1'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S365>/Clamping_zero'

  0.0,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S370>/Filter'

  0.004,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S375>/Integrator'

  0.004,

  // Expression: -1
  //  Referenced by: '<S184>/Gain'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S12>/Gain1'

  -1.0,

  // Computed Parameter: tau_yaw_Y0
  //  Referenced by: '<S13>/tau_yaw'

  0.0,

  // Computed Parameter: tau_pitch_Y0
  //  Referenced by: '<S13>/tau_pitch'

  0.0,

  // Computed Parameter: tau_roll_Y0
  //  Referenced by: '<S13>/tau_roll'

  0.0,

  // Expression: 0
  //  Referenced by: '<S420>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S472>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S524>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S420>/Clamping_zero'

  0.0,

  // Computed Parameter: Integrator_gainval_h
  //  Referenced by: '<S430>/Integrator'

  0.004,

  // Computed Parameter: Filter_gainval_f
  //  Referenced by: '<S425>/Filter'

  0.004,

  // Expression: 0
  //  Referenced by: '<S472>/Clamping_zero'

  0.0,

  // Computed Parameter: Integrator_gainval_b
  //  Referenced by: '<S482>/Integrator'

  0.004,

  // Computed Parameter: Filter_gainval_l
  //  Referenced by: '<S477>/Filter'

  0.004,

  // Expression: 0
  //  Referenced by: '<S524>/Clamping_zero'

  0.0,

  // Computed Parameter: Integrator_gainval_n
  //  Referenced by: '<S534>/Integrator'

  0.004,

  // Computed Parameter: Filter_gainval_a
  //  Referenced by: '<S529>/Filter'

  0.004,

  // Computed Parameter: yaw_Out_Y0
  //  Referenced by: '<S568>/yaw_Out'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S566>/Delay'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S566>/Rate'

  0.01,

  // Expression: -1
  //  Referenced by: '<S566>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S566>/Gain'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S567>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S567>/Constant'

  0.0,

  // Computed Parameter: Out_Y0
  //  Referenced by: '<S564>/Out'

  0.0,

  // Expression: -1
  //  Referenced by: '<S562>/Gain'

  -1.0,

  // Computed Parameter: yaw_Out_Y0_f
  //  Referenced by: '<S565>/yaw_Out'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S557>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S562>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S562>/Switch'

  0.0,

  // Expression: 0.02
  //  Referenced by: '<S562>/Rate of descent'

  0.02,

  // Expression: -1
  //  Referenced by: '<S562>/Gain2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S562>/Gain1'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S563>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S563>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S569>/Constant'

  0.0,

  // Expression: 6
  //  Referenced by: '<S559>/Constant'

  6.0,

  // Computed Parameter: yaw_Out_Y0_p
  //  Referenced by: '<S561>/yaw_Out'

  0.0,

  // Expression: 1
  //  Referenced by: '<S560>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S560>/Constant'

  0.0,

  // Expression: -1
  //  Referenced by: '<S555>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S587>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S586>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S596>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S596>/Read Parameter1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S596>/Read Parameter13'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S596>/Read Parameter2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S596>/Read Parameter3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S596>/Read Parameter4'

  -1.0,

  // Expression: 5
  //  Referenced by: '<S3>/Gain'

  5.0,

  // Expression: 1
  //  Referenced by: '<S3>/Saturation3'

  1.0,

  // Expression: -1
  //  Referenced by: '<S3>/Saturation3'

  -1.0,

  // Expression: 5
  //  Referenced by: '<S3>/Gain1'

  5.0,

  // Expression: 1
  //  Referenced by: '<S3>/Saturation2'

  1.0,

  // Expression: -1
  //  Referenced by: '<S3>/Saturation2'

  -1.0,

  // Expression: 10
  //  Referenced by: '<S3>/Gain2'

  10.0,

  // Expression: 1
  //  Referenced by: '<S3>/Saturation1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S3>/Saturation1'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S3>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S3>/Saturation'

  0.0,

  // Expression: 1
  //  Referenced by: '<S3>/Saturation4'

  1.0,

  // Expression: 0
  //  Referenced by: '<S3>/Saturation4'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S596>/Gain'

  0.01,

  // Expression: 0.01
  //  Referenced by: '<S596>/Gain1'

  0.01,

  // Expression: 0.01
  //  Referenced by: '<S596>/Gain2'

  0.01,

  // Expression: 0.01
  //  Referenced by: '<S596>/Gain3'

  0.01,

  // Expression: 0.01
  //  Referenced by: '<S596>/Gain4'

  0.01,

  // Expression: 0.01
  //  Referenced by: '<S596>/Gain5'

  0.01,

  // Expression: 0
  //  Referenced by: '<S595>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S9>/Switch'

  0.0,

  // Expression: 0
  //  Referenced by: '<S5>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S5>/Constant1'

  0.0,

  // Expression: -5
  //  Referenced by: '<S5>/Constant2'

  -5.0,

  // Expression: -1
  //  Referenced by: '<S5>/Gain'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S6>/thrust_sp_bX'

  0.0,

  // Expression: 0
  //  Referenced by: '<S6>/thrust_sp_bY'

  0.0,

  // Expression: 0
  //  Referenced by: '<S7>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S8>/thrust_sp_bX'

  0.0,

  // Expression: 0
  //  Referenced by: '<S8>/thrust_sp_bY'

  0.0,

  // Expression: -1
  //  Referenced by: '<S5>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S5>/Gain2'

  -1.0,

  // Computed Parameter: Constant7_Value
  //  Referenced by: '<S580>/Constant7'

  (0ULL),

  // Computed Parameter: Constant1_Value_d
  //  Referenced by: '<S587>/Constant1'

  { 0.0F, 0.0F },

  // Computed Parameter: Constant_Value_f2
  //  Referenced by: '<S587>/Constant'

  0.0F,

  // Computed Parameter: Gain_Gain_hp
  //  Referenced by: '<S586>/Gain'

  -1.0F,

  // Computed Parameter: Constant1_Value_k4
  //  Referenced by: '<S586>/Constant1'

  { 0.0F, 0.0F },

  // Computed Parameter: Constant_Value_l4
  //  Referenced by: '<S586>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_fh
  //  Referenced by: '<S580>/Constant'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant1_Value_h
  //  Referenced by: '<S580>/Constant1'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant2_Value_f
  //  Referenced by: '<S580>/Constant2'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant3_Value
  //  Referenced by: '<S580>/Constant3'

  0.0F,

  // Computed Parameter: Constant4_Value
  //  Referenced by: '<S580>/Constant4'

  0.0F,

  // Computed Parameter: Constant5_Value
  //  Referenced by: '<S578>/Constant5'

  true,

  // Computed Parameter: Constant5_Value_k
  //  Referenced by: '<S579>/Constant5'

  true,

  // Computed Parameter: Constant1_Value_dl
  //  Referenced by: '<S581>/Constant1'

  true,

  // Computed Parameter: Constant5_Value_h
  //  Referenced by: '<S581>/Constant5'

  true,

  // Computed Parameter: Constant5_Value_l
  //  Referenced by: '<S580>/Constant5'

  false,

  // Computed Parameter: Constant_Value_mp
  //  Referenced by: '<S365>/Constant'

  1,

  // Computed Parameter: Constant2_Value_k
  //  Referenced by: '<S365>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_i
  //  Referenced by: '<S365>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_j
  //  Referenced by: '<S365>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_dt
  //  Referenced by: '<S420>/Constant'

  1,

  // Computed Parameter: Constant2_Value_l
  //  Referenced by: '<S420>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_j
  //  Referenced by: '<S420>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_c
  //  Referenced by: '<S420>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_d5
  //  Referenced by: '<S472>/Constant'

  1,

  // Computed Parameter: Constant2_Value_e
  //  Referenced by: '<S472>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_k
  //  Referenced by: '<S472>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_n
  //  Referenced by: '<S472>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_km
  //  Referenced by: '<S524>/Constant'

  1,

  // Computed Parameter: Constant2_Value_m
  //  Referenced by: '<S524>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_d
  //  Referenced by: '<S524>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_b
  //  Referenced by: '<S524>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_fm
  //  Referenced by: '<S572>/Constant'

  0U,

  // Computed Parameter: Constant6_Value
  //  Referenced by: '<S580>/Constant6'

  255U
};

//
// File trailer for generated code.
//
// [EOF]
//
