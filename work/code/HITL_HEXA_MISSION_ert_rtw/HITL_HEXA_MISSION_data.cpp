//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: HITL_HEXA_MISSION_data.cpp
//
// Code generated for Simulink model 'HITL_HEXA_MISSION'.
//
// Model version                  : 5.5
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Oct 16 17:31:56 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "HITL_HEXA_MISSION.h"

// Block parameters (default storage)
P_HITL_HEXA_MISSION_T HITL_HEXA_MISSION_P = {
  // Mask Parameter: PID_vz_InitialConditionForFilter
  //  Referenced by: '<S395>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditionForFilter
  //  Referenced by: '<S450>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialConditionForFilter
  //  Referenced by: '<S502>/Filter'

  0.0,

  // Mask Parameter: PIDController2_InitialConditionForFilter
  //  Referenced by: '<S554>/Filter'

  0.0,

  // Mask Parameter: PID_vz_InitialConditionForIntegrator
  //  Referenced by: '<S400>/Integrator'

  0.0,

  // Mask Parameter: PIDController_InitialConditionForIntegrator
  //  Referenced by: '<S455>/Integrator'

  0.0,

  // Mask Parameter: PIDController1_InitialConditionForIntegrator
  //  Referenced by: '<S507>/Integrator'

  0.0,

  // Mask Parameter: PIDController2_InitialConditionForIntegrator
  //  Referenced by: '<S559>/Integrator'

  0.0,

  // Mask Parameter: PID_vz_LowerSaturationLimit
  //  Referenced by:
  //    '<S407>/Saturation'
  //    '<S392>/DeadZone'

  0.0,

  // Mask Parameter: PIDController_LowerSaturationLimit
  //  Referenced by:
  //    '<S462>/Saturation'
  //    '<S447>/DeadZone'

  -0.1,

  // Mask Parameter: PIDController1_LowerSaturationLimit
  //  Referenced by:
  //    '<S514>/Saturation'
  //    '<S499>/DeadZone'

  -0.2,

  // Mask Parameter: PIDController2_LowerSaturationLimit
  //  Referenced by:
  //    '<S566>/Saturation'
  //    '<S551>/DeadZone'

  -0.2,

  // Mask Parameter: PID_vz_UpperSaturationLimit
  //  Referenced by:
  //    '<S407>/Saturation'
  //    '<S392>/DeadZone'

  1.0,

  // Mask Parameter: PIDController_UpperSaturationLimit
  //  Referenced by:
  //    '<S462>/Saturation'
  //    '<S447>/DeadZone'

  0.1,

  // Mask Parameter: PIDController1_UpperSaturationLimit
  //  Referenced by:
  //    '<S514>/Saturation'
  //    '<S499>/DeadZone'

  0.2,

  // Mask Parameter: PIDController2_UpperSaturationLimit
  //  Referenced by:
  //    '<S566>/Saturation'
  //    '<S551>/DeadZone'

  0.2,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S11>/Constant'

  1800.0,

  // Mask Parameter: CompareToConstant_const_k
  //  Referenced by: '<S12>/Constant'

  1400U,

  // Mask Parameter: CompareToConstant_const_d
  //  Referenced by: '<S595>/Constant'

  5U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S602>/Out1'

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
  //  Referenced by: '<S607>/Constant'

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
  //  Referenced by: '<S601>/Constant'

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
  //  Referenced by: '<S614>/Out1'

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
  //  Referenced by: '<S599>/Constant'

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
  //  Referenced by: '<S624>/Out1'

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
  //  Referenced by: '<S620>/Constant'

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

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S21>/Constant'

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

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S20>/Out1'

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
  //  Referenced by: '<S19>/Constant'

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
  //  Referenced by: '<S615>/Constant'

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
  //  Referenced by: '<S623>/Out1'

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
  //  Referenced by: '<S619>/Constant'

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
  //  Referenced by: '<S31>/Constant'

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
  //  Referenced by: '<S613>/Out1'

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
  //  Referenced by: '<S598>/Constant'

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
  //  Referenced by: '<S621>/Out1'

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
  //  Referenced by: '<S617>/Constant'

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
  //  Referenced by: '<S33>/Constant'

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
  //  Referenced by: '<S622>/Out1'

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
  //  Referenced by: '<S618>/Constant'

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

  // Expression: 0
  //  Referenced by: '<S6>/Constant1'

  0.0,

  // Expression: 100
  //  Referenced by: '<S7>/Constant1'

  100.0,

  // Expression: 0.01
  //  Referenced by: '<S14>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S14>/Saturation1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S6>/Constant2'

  0.0,

  // Expression: 100
  //  Referenced by: '<S7>/Constant2'

  100.0,

  // Expression: 0.01
  //  Referenced by: '<S15>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S15>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S15>/Saturation1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S6>/Constant3'

  0.0,

  // Expression: 100
  //  Referenced by: '<S7>/Constant3'

  100.0,

  // Expression: 0.01
  //  Referenced by: '<S16>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S16>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S16>/Saturation1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S6>/Constant4'

  0.0,

  // Expression: 100
  //  Referenced by: '<S7>/Constant4'

  100.0,

  // Expression: 0.01
  //  Referenced by: '<S17>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S17>/Saturation1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S6>/Constant5'

  0.0,

  // Expression: 100
  //  Referenced by: '<S7>/Constant5'

  100.0,

  // Expression: 0.01
  //  Referenced by: '<S18>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S18>/Saturation1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S6>/Constant'

  0.0,

  // Expression: 100
  //  Referenced by: '<S7>/Constant'

  100.0,

  // Expression: 0.01
  //  Referenced by: '<S13>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S13>/Saturation1'

  0.0,

  // Expression: -1
  //  Referenced by: '<S7>/Read Parameter1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S7>/Read Parameter13'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S7>/Read Parameter2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S7>/Read Parameter3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S7>/Read Parameter4'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S7>/Read Parameter5'

  -1.0,

  // Expression: [1 0 0 0]
  //  Referenced by: '<S26>/Constant'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<S39>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S40>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S44>/Switch1'

  0.0,

  // Expression: -1
  //  Referenced by: '<S28>/Read Parameter10'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S28>/Read Parameter11'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S28>/Read Parameter4'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S28>/Read Parameter5'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S28>/Read Parameter6'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S28>/Read Parameter9'

  -1.0,

  // Computed Parameter: Yawrate_sp_Y0
  //  Referenced by: '<S28>/Yawrate_sp'

  0.0,

  // Computed Parameter: Pitchrate_sp_Y0
  //  Referenced by: '<S28>/Pitchrate_sp'

  0.0,

  // Computed Parameter: Rollrate_spl_Y0
  //  Referenced by: '<S28>/Rollrate_spl'

  0.0,

  // Expression: 2*pi
  //  Referenced by: '<S44>/Constant'

  6.2831853071795862,

  // Expression: pi
  //  Referenced by: '<S44>/Switch'

  3.1415926535897931,

  // Expression: 180*pi/180
  //  Referenced by: '<S28>/Rate Limiter2'

  3.1415926535897931,

  // Expression: -180*pi/180
  //  Referenced by: '<S28>/Rate Limiter2'

  -3.1415926535897931,

  // Expression: 0
  //  Referenced by: '<S28>/Rate Limiter2'

  0.0,

  // Expression: 180*pi/180
  //  Referenced by: '<S28>/Rate Limiter1'

  3.1415926535897931,

  // Expression: -180*pi/180
  //  Referenced by: '<S28>/Rate Limiter1'

  -3.1415926535897931,

  // Expression: 0
  //  Referenced by: '<S28>/Rate Limiter1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S204>/Constant'

  0.0,

  // Expression: -1
  //  Referenced by: '<S29>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S29>/Read Parameter1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S29>/Read Parameter12'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S29>/Read Parameter13'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S29>/Read Parameter14'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S29>/Read Parameter15'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S29>/Read Parameter2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S29>/Read Parameter3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S29>/Read Parameter7'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S29>/Read Parameter8'

  -1.0,

  // Computed Parameter: tau_Thrust_Y0
  //  Referenced by: '<S29>/tau_Thrust'

  0.0,

  // Computed Parameter: des_pitch_Y0
  //  Referenced by: '<S29>/des_pitch'

  0.0,

  // Computed Parameter: des_roll_Y0
  //  Referenced by: '<S29>/des_roll'

  0.0,

  // Expression: 0
  //  Referenced by: '<S390>/Constant1'

  0.0,

  // Expression: 10
  //  Referenced by: '<S29>/Constant'

  10.0,

  // Expression: 0
  //  Referenced by: '<S390>/Clamping_zero'

  0.0,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S395>/Filter'

  0.004,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S400>/Integrator'

  0.004,

  // Expression: -1
  //  Referenced by: '<S205>/Gain'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S29>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S30>/Read Parameter16'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S30>/Read Parameter17'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S30>/Read Parameter18'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S30>/Read Parameter19'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S30>/Read Parameter20'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S30>/Read Parameter21'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S30>/Read Parameter22'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S30>/Read Parameter23'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S30>/Read Parameter24'

  -1.0,

  // Computed Parameter: tau_yaw_Y0
  //  Referenced by: '<S30>/tau_yaw'

  0.0,

  // Computed Parameter: tau_pitch_Y0
  //  Referenced by: '<S30>/tau_pitch'

  0.0,

  // Computed Parameter: tau_roll_Y0
  //  Referenced by: '<S30>/tau_roll'

  0.0,

  // Expression: 0
  //  Referenced by: '<S445>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S497>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S549>/Constant1'

  0.0,

  // Expression: 100
  //  Referenced by: '<S30>/Constant'

  100.0,

  // Computed Parameter: Filter_gainval_f
  //  Referenced by: '<S450>/Filter'

  0.004,

  // Computed Parameter: Integrator_gainval_h
  //  Referenced by: '<S455>/Integrator'

  0.004,

  // Expression: 0
  //  Referenced by: '<S445>/Clamping_zero'

  0.0,

  // Expression: 50
  //  Referenced by: '<S30>/Constant1'

  50.0,

  // Computed Parameter: Filter_gainval_l
  //  Referenced by: '<S502>/Filter'

  0.004,

  // Computed Parameter: Integrator_gainval_b
  //  Referenced by: '<S507>/Integrator'

  0.004,

  // Expression: 0
  //  Referenced by: '<S497>/Clamping_zero'

  0.0,

  // Expression: 50
  //  Referenced by: '<S30>/Constant2'

  50.0,

  // Computed Parameter: Filter_gainval_a
  //  Referenced by: '<S554>/Filter'

  0.004,

  // Computed Parameter: Integrator_gainval_n
  //  Referenced by: '<S559>/Integrator'

  0.004,

  // Expression: 0
  //  Referenced by: '<S549>/Clamping_zero'

  0.0,

  // Computed Parameter: yaw_Out_Y0
  //  Referenced by: '<S593>/yaw_Out'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S591>/Delay'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S591>/Rate'

  0.01,

  // Expression: -1
  //  Referenced by: '<S591>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S591>/Gain'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S592>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S592>/Constant'

  0.0,

  // Computed Parameter: Out_Y0
  //  Referenced by: '<S589>/Out'

  0.0,

  // Expression: -1
  //  Referenced by: '<S587>/Gain'

  -1.0,

  // Computed Parameter: yaw_Out_Y0_f
  //  Referenced by: '<S590>/yaw_Out'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S582>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S587>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S587>/Switch'

  0.0,

  // Expression: 0.02
  //  Referenced by: '<S587>/Rate of descent'

  0.02,

  // Expression: -1
  //  Referenced by: '<S587>/Gain2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S587>/Gain1'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S588>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S588>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S594>/Constant'

  0.0,

  // Expression: 6
  //  Referenced by: '<S584>/Constant'

  6.0,

  // Computed Parameter: yaw_Out_Y0_p
  //  Referenced by: '<S586>/yaw_Out'

  0.0,

  // Expression: 1
  //  Referenced by: '<S585>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S585>/Constant'

  0.0,

  // Expression: -1
  //  Referenced by: '<S580>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S612>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S611>/Read Parameter'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S26>/Switch'

  0.0,

  // Expression: -1
  //  Referenced by: '<S23>/Gain'

  -1.0,

  // Expression: 5
  //  Referenced by: '<S5>/Gain'

  5.0,

  // Expression: 5
  //  Referenced by: '<S5>/Gain1'

  5.0,

  // Expression: 10
  //  Referenced by: '<S5>/Gain2'

  10.0,

  // Expression: 1
  //  Referenced by: '<S5>/Gain3'

  1.0,

  // Expression: 0
  //  Referenced by: '<S10>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S24>/thrust_sp_bX'

  0.0,

  // Expression: 0
  //  Referenced by: '<S24>/thrust_sp_bY'

  0.0,

  // Expression: 0
  //  Referenced by: '<S25>/thrust_sp_bX'

  0.0,

  // Expression: 0
  //  Referenced by: '<S25>/thrust_sp_bY'

  0.0,

  // Expression: 6
  //  Referenced by: '<S10>/Constant17'

  6.0,

  // Computed Parameter: Constant7_Value
  //  Referenced by: '<S605>/Constant7'

  (0ULL),

  // Computed Parameter: Gain1_Gain_k
  //  Referenced by: '<S47>/Gain1'

  0.0174532924F,

  // Computed Parameter: Gain1_Gain_i
  //  Referenced by: '<S45>/Gain1'

  0.0174532924F,

  // Computed Parameter: Gain1_Gain_o
  //  Referenced by: '<S46>/Gain1'

  0.0174532924F,

  // Computed Parameter: Gain1_Gain_o1
  //  Referenced by: '<S204>/Gain1'

  -1.0F,

  // Computed Parameter: Gain1_Gain_p
  //  Referenced by: '<S206>/Gain1'

  0.0174532924F,

  // Computed Parameter: Gain_Gain_md
  //  Referenced by: '<S29>/Gain'

  -1.0F,

  // Computed Parameter: Gain2_Gain_i
  //  Referenced by: '<S29>/Gain2'

  -1.0F,

  // Computed Parameter: Constant1_Value_d
  //  Referenced by: '<S612>/Constant1'

  { 0.0F, 0.0F },

  // Computed Parameter: Constant_Value_f2
  //  Referenced by: '<S612>/Constant'

  0.0F,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: '<S611>/Gain'

  -1.0F,

  // Computed Parameter: Constant1_Value_k4
  //  Referenced by: '<S611>/Constant1'

  { 0.0F, 0.0F },

  // Computed Parameter: Constant_Value_l4
  //  Referenced by: '<S611>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_fh
  //  Referenced by: '<S605>/Constant'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant1_Value_h
  //  Referenced by: '<S605>/Constant1'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant2_Value_f
  //  Referenced by: '<S605>/Constant2'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant3_Value_a
  //  Referenced by: '<S605>/Constant3'

  0.0F,

  // Computed Parameter: Constant4_Value_g
  //  Referenced by: '<S605>/Constant4'

  0.0F,

  // Computed Parameter: Constant5_Value_j
  //  Referenced by: '<S603>/Constant5'

  true,

  // Computed Parameter: Constant5_Value_k
  //  Referenced by: '<S604>/Constant5'

  true,

  // Computed Parameter: Constant1_Value_dl
  //  Referenced by: '<S606>/Constant1'

  true,

  // Computed Parameter: Constant5_Value_h
  //  Referenced by: '<S606>/Constant5'

  true,

  // Computed Parameter: Constant5_Value_l
  //  Referenced by: '<S605>/Constant5'

  false,

  // Computed Parameter: Constant_Value_mp
  //  Referenced by: '<S390>/Constant'

  1,

  // Computed Parameter: Constant2_Value_k
  //  Referenced by: '<S390>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_i
  //  Referenced by: '<S390>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_j
  //  Referenced by: '<S390>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_dt
  //  Referenced by: '<S445>/Constant'

  1,

  // Computed Parameter: Constant2_Value_l
  //  Referenced by: '<S445>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_j
  //  Referenced by: '<S445>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_c
  //  Referenced by: '<S445>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_d5
  //  Referenced by: '<S497>/Constant'

  1,

  // Computed Parameter: Constant2_Value_e
  //  Referenced by: '<S497>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_k
  //  Referenced by: '<S497>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_n
  //  Referenced by: '<S497>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S549>/Constant'

  1,

  // Computed Parameter: Constant2_Value_m
  //  Referenced by: '<S549>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_d
  //  Referenced by: '<S549>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_b
  //  Referenced by: '<S549>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_fm
  //  Referenced by: '<S597>/Constant'

  0U,

  // Computed Parameter: Constant6_Value
  //  Referenced by: '<S605>/Constant6'

  255U
};

//
// File trailer for generated code.
//
// [EOF]
//
