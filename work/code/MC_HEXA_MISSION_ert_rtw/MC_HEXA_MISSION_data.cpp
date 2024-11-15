//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MC_HEXA_MISSION_data.cpp
//
// Code generated for Simulink model 'MC_HEXA_MISSION'.
//
// Model version                  : 4.139
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Aug 10 19:48:00 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "MC_HEXA_MISSION.h"

// Block parameters (default storage)
P_MC_HEXA_MISSION_T MC_HEXA_MISSION_P = {
  // Mask Parameter: PID_vz_InitialConditionForFilter
  //  Referenced by: '<S381>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditionForFilter
  //  Referenced by: '<S434>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialConditionForFilter
  //  Referenced by: '<S484>/Filter'

  0.0,

  // Mask Parameter: PIDController2_InitialConditionForFilter
  //  Referenced by: '<S534>/Filter'

  0.0,

  // Mask Parameter: PID_vz_InitialConditionForIntegrator
  //  Referenced by: '<S386>/Integrator'

  0.0,

  // Mask Parameter: PIDController_InitialConditionForIntegrator
  //  Referenced by: '<S439>/Integrator'

  0.0,

  // Mask Parameter: PIDController1_InitialConditionForIntegrator
  //  Referenced by: '<S489>/Integrator'

  0.0,

  // Mask Parameter: PIDController2_InitialConditionForIntegrator
  //  Referenced by: '<S539>/Integrator'

  0.0,

  // Mask Parameter: PID_vz_LowerSaturationLimit
  //  Referenced by:
  //    '<S393>/Saturation'
  //    '<S379>/DeadZone'

  0.0,

  // Mask Parameter: PIDController_LowerSaturationLimit
  //  Referenced by:
  //    '<S446>/Saturation'
  //    '<S432>/DeadZone'

  -0.1,

  // Mask Parameter: PIDController1_LowerSaturationLimit
  //  Referenced by:
  //    '<S496>/Saturation'
  //    '<S482>/DeadZone'

  -0.2,

  // Mask Parameter: PIDController2_LowerSaturationLimit
  //  Referenced by:
  //    '<S546>/Saturation'
  //    '<S532>/DeadZone'

  -0.2,

  // Mask Parameter: PID_vz_UpperSaturationLimit
  //  Referenced by:
  //    '<S393>/Saturation'
  //    '<S379>/DeadZone'

  1.0,

  // Mask Parameter: PIDController_UpperSaturationLimit
  //  Referenced by:
  //    '<S446>/Saturation'
  //    '<S432>/DeadZone'

  0.1,

  // Mask Parameter: PIDController1_UpperSaturationLimit
  //  Referenced by:
  //    '<S496>/Saturation'
  //    '<S482>/DeadZone'

  0.2,

  // Mask Parameter: PIDController2_UpperSaturationLimit
  //  Referenced by:
  //    '<S546>/Saturation'
  //    '<S532>/DeadZone'

  0.2,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S11>/Constant'

  1800.0,

  // Mask Parameter: CompareToConstant_const_k
  //  Referenced by: '<S18>/Constant'

  1400U,

  // Mask Parameter: CompareToConstant_const_d
  //  Referenced by: '<S575>/Constant'

  5U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S582>/Out1'

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
  //  Referenced by: '<S587>/Constant'

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
  //  Referenced by: '<S581>/Constant'

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

  // Computed Parameter: Out1_Y0_e
  //  Referenced by: '<S601>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q_offset

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // pose_covariance
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // rollspeed
    0.0F,                              // pitchspeed
    0.0F,                              // yawspeed

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // velocity_covariance
    0U,                                // local_frame
    0U,                                // velocity_frame

    {
      0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S597>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q_offset

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // pose_covariance
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // rollspeed
    0.0F,                              // pitchspeed
    0.0F,                              // yawspeed

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // velocity_covariance
    0U,                                // local_frame
    0U,                                // velocity_frame

    {
      0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S594>/Out1'

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
      false,                           // velocity_valid
      0U,                              // velocity_frame
      false,                           // alt_valid
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      0,                               // landing_gear
      0,                               // loiter_direction
      false,                           // disable_weather_vane

      {
        0U, 0U, 0U, 0U, 0U, 0U }
      // _padding0
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
      false,                           // velocity_valid
      0U,                              // velocity_frame
      false,                           // alt_valid
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      0,                               // landing_gear
      0,                               // loiter_direction
      false,                           // disable_weather_vane

      {
        0U, 0U, 0U, 0U, 0U, 0U }
      // _padding0
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
      false,                           // velocity_valid
      0U,                              // velocity_frame
      false,                           // alt_valid
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      0,                               // landing_gear
      0,                               // loiter_direction
      false,                           // disable_weather_vane

      {
        0U, 0U, 0U, 0U, 0U, 0U }
      // _padding0
    }                                  // next
  },

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S579>/Constant'

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
      false,                           // velocity_valid
      0U,                              // velocity_frame
      false,                           // alt_valid
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      0,                               // landing_gear
      0,                               // loiter_direction
      false,                           // disable_weather_vane

      {
        0U, 0U, 0U, 0U, 0U, 0U }
      // _padding0
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
      false,                           // velocity_valid
      0U,                              // velocity_frame
      false,                           // alt_valid
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      0,                               // landing_gear
      0,                               // loiter_direction
      false,                           // disable_weather_vane

      {
        0U, 0U, 0U, 0U, 0U, 0U }
      // _padding0
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
      false,                           // velocity_valid
      0U,                              // velocity_frame
      false,                           // alt_valid
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      0,                               // landing_gear
      0,                               // loiter_direction
      false,                           // disable_weather_vane

      {
        0U, 0U, 0U, 0U, 0U, 0U }
      // _padding0
    }                                  // next
  },

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S604>/Out1'

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
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S600>/Constant'

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
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield

    {
      0U, 0U, 0U }
    // _padding0
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

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S595>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // yaw
    0.0F,                              // yawspeed
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // acceleration

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // jerk

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // thrust

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
  //  Referenced by: '<S19>/Constant'

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
    false,                             // roll_reset_integral
    false,                             // pitch_reset_integral
    false,                             // yaw_reset_integral
    false,                             // fw_control_yaw
    0U,                                // apply_flaps

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S603>/Out1'

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
  //  Referenced by: '<S599>/Constant'

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

  // Computed Parameter: Out1_Y0_o
  //  Referenced by: '<S593>/Out1'

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
  //  Referenced by: '<S578>/Constant'

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

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S33>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll
    0.0F,                              // pitch
    0.0F,                              // yaw

    {
      0.0F, 0.0F, 0.0F }
    // thrust_body
  },

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S602>/Out1'

  {
    (0ULL),                            // timestamp
    false,                             // armed
    false,                             // prearmed
    false,                             // ready_to_arm
    false,                             // lockdown
    false,                             // manual_lockdown
    false,                             // force_failsafe
    false,                             // in_esc_calibration_mode
    false                              // soft_stop
  },

  // Computed Parameter: Constant_Value_jl
  //  Referenced by: '<S598>/Constant'

  {
    (0ULL),                            // timestamp
    false,                             // armed
    false,                             // prearmed
    false,                             // ready_to_arm
    false,                             // lockdown
    false,                             // manual_lockdown
    false,                             // force_failsafe
    false,                             // in_esc_calibration_mode
    false                              // soft_stop
  },

  // Expression: 1000
  //  Referenced by: '<S6>/Constant1'

  1000.0,

  // Expression: 100
  //  Referenced by: '<S7>/Fault1'

  100.0,

  // Expression: 100
  //  Referenced by: '<S7>/Constant1'

  100.0,

  // Expression: 1100
  //  Referenced by: '<S13>/Constant'

  1100.0,

  // Expression: 0.01
  //  Referenced by: '<S13>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S13>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S13>/Saturation1'

  0.0,

  // Expression: 1100
  //  Referenced by: '<S13>/IDLE PWM'

  1100.0,

  // Expression: 1000
  //  Referenced by: '<S6>/Constant2'

  1000.0,

  // Expression: 100
  //  Referenced by: '<S7>/Fault2'

  100.0,

  // Expression: 100
  //  Referenced by: '<S7>/Constant2'

  100.0,

  // Expression: 1100
  //  Referenced by: '<S14>/Constant'

  1100.0,

  // Expression: 0.01
  //  Referenced by: '<S14>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S14>/Saturation1'

  0.0,

  // Expression: 1100
  //  Referenced by: '<S14>/IDLE PWM'

  1100.0,

  // Expression: 1000
  //  Referenced by: '<S6>/Constant3'

  1000.0,

  // Expression: 100
  //  Referenced by: '<S7>/Fault3'

  100.0,

  // Expression: 100
  //  Referenced by: '<S7>/Constant3'

  100.0,

  // Expression: 1100
  //  Referenced by: '<S15>/Constant'

  1100.0,

  // Expression: 0.01
  //  Referenced by: '<S15>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S15>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S15>/Saturation1'

  0.0,

  // Expression: 1100
  //  Referenced by: '<S15>/IDLE PWM'

  1100.0,

  // Expression: 1000
  //  Referenced by: '<S6>/Constant4'

  1000.0,

  // Expression: 100
  //  Referenced by: '<S7>/Fault4'

  100.0,

  // Expression: 100
  //  Referenced by: '<S7>/Constant4'

  100.0,

  // Expression: 1100
  //  Referenced by: '<S16>/Constant'

  1100.0,

  // Expression: 0.01
  //  Referenced by: '<S16>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S16>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S16>/Saturation1'

  0.0,

  // Expression: 1100
  //  Referenced by: '<S16>/IDLE PWM'

  1100.0,

  // Expression: 1000
  //  Referenced by: '<S6>/Constant5'

  1000.0,

  // Expression: 100
  //  Referenced by: '<S7>/Fault5'

  100.0,

  // Expression: 100
  //  Referenced by: '<S7>/Constant5'

  100.0,

  // Expression: 1100
  //  Referenced by: '<S17>/Constant'

  1100.0,

  // Expression: 0.01
  //  Referenced by: '<S17>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S17>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S17>/Saturation1'

  0.0,

  // Expression: 1100
  //  Referenced by: '<S17>/IDLE PWM'

  1100.0,

  // Expression: 1000
  //  Referenced by: '<S6>/Constant'

  1000.0,

  // Expression: 100
  //  Referenced by: '<S7>/Fault'

  100.0,

  // Expression: 100
  //  Referenced by: '<S7>/Constant'

  100.0,

  // Expression: 1100
  //  Referenced by: '<S12>/Constant'

  1100.0,

  // Expression: 0.01
  //  Referenced by: '<S12>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S12>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S12>/Saturation1'

  0.0,

  // Expression: 1100
  //  Referenced by: '<S12>/IDLE PWM'

  1100.0,

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
  //  Referenced by: '<S198>/Constant'

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
  //  Referenced by: '<S377>/Constant1'

  0.0,

  // Expression: 10
  //  Referenced by: '<S29>/Constant'

  10.0,

  // Expression: 0
  //  Referenced by: '<S377>/Clamping_zero'

  0.0,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S381>/Filter'

  0.004,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S386>/Integrator'

  0.004,

  // Expression: -1
  //  Referenced by: '<S199>/Gain'

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
  //  Referenced by: '<S430>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S480>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S530>/Constant1'

  0.0,

  // Expression: 100
  //  Referenced by: '<S30>/Constant'

  100.0,

  // Computed Parameter: Filter_gainval_f
  //  Referenced by: '<S434>/Filter'

  0.004,

  // Computed Parameter: Integrator_gainval_h
  //  Referenced by: '<S439>/Integrator'

  0.004,

  // Expression: 0
  //  Referenced by: '<S430>/Clamping_zero'

  0.0,

  // Expression: 50
  //  Referenced by: '<S30>/Constant1'

  50.0,

  // Computed Parameter: Filter_gainval_l
  //  Referenced by: '<S484>/Filter'

  0.004,

  // Computed Parameter: Integrator_gainval_b
  //  Referenced by: '<S489>/Integrator'

  0.004,

  // Expression: 0
  //  Referenced by: '<S480>/Clamping_zero'

  0.0,

  // Expression: 50
  //  Referenced by: '<S30>/Constant2'

  50.0,

  // Computed Parameter: Filter_gainval_a
  //  Referenced by: '<S534>/Filter'

  0.004,

  // Computed Parameter: Integrator_gainval_n
  //  Referenced by: '<S539>/Integrator'

  0.004,

  // Expression: 0
  //  Referenced by: '<S530>/Clamping_zero'

  0.0,

  // Computed Parameter: yaw_Out_Y0
  //  Referenced by: '<S573>/yaw_Out'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S571>/Delay'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S571>/Rate'

  0.01,

  // Expression: -1
  //  Referenced by: '<S571>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S571>/Gain'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S572>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S572>/Constant'

  0.0,

  // Computed Parameter: Out_Y0
  //  Referenced by: '<S569>/Out'

  0.0,

  // Expression: -1
  //  Referenced by: '<S567>/Gain'

  -1.0,

  // Computed Parameter: yaw_Out_Y0_f
  //  Referenced by: '<S570>/yaw_Out'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S562>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S567>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S567>/Switch'

  0.0,

  // Expression: 0.02
  //  Referenced by: '<S567>/Rate of descent'

  0.02,

  // Expression: -1
  //  Referenced by: '<S567>/Gain2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S567>/Gain1'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S568>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S568>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S574>/Constant'

  0.0,

  // Expression: 6
  //  Referenced by: '<S564>/Constant'

  6.0,

  // Computed Parameter: yaw_Out_Y0_p
  //  Referenced by: '<S566>/yaw_Out'

  0.0,

  // Expression: 1
  //  Referenced by: '<S565>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S565>/Constant'

  0.0,

  // Expression: -1
  //  Referenced by: '<S560>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S592>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S591>/Read Parameter'

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
  //  Referenced by: '<S585>/Constant7'

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
  //  Referenced by: '<S198>/Gain1'

  -1.0F,

  // Computed Parameter: Gain1_Gain_p
  //  Referenced by: '<S200>/Gain1'

  0.0174532924F,

  // Computed Parameter: Gain_Gain_m
  //  Referenced by: '<S29>/Gain'

  -1.0F,

  // Computed Parameter: Gain2_Gain_i
  //  Referenced by: '<S29>/Gain2'

  -1.0F,

  // Computed Parameter: Constant1_Value_d
  //  Referenced by: '<S592>/Constant1'

  { 0.0F, 0.0F },

  // Computed Parameter: Constant_Value_f2
  //  Referenced by: '<S592>/Constant'

  0.0F,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: '<S591>/Gain'

  -1.0F,

  // Computed Parameter: Constant1_Value_k4
  //  Referenced by: '<S591>/Constant1'

  { 0.0F, 0.0F },

  // Computed Parameter: Constant_Value_l4
  //  Referenced by: '<S591>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_fh
  //  Referenced by: '<S585>/Constant'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant1_Value_h
  //  Referenced by: '<S585>/Constant1'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant2_Value_f
  //  Referenced by: '<S585>/Constant2'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant3_Value_a
  //  Referenced by: '<S585>/Constant3'

  0.0F,

  // Computed Parameter: Constant4_Value_g
  //  Referenced by: '<S585>/Constant4'

  0.0F,

  // Computed Parameter: Constant5_Value_j
  //  Referenced by: '<S583>/Constant5'

  true,

  // Computed Parameter: Constant5_Value_k
  //  Referenced by: '<S584>/Constant5'

  true,

  // Computed Parameter: Constant1_Value_dl
  //  Referenced by: '<S586>/Constant1'

  true,

  // Computed Parameter: Constant5_Value_h
  //  Referenced by: '<S586>/Constant5'

  true,

  // Computed Parameter: Constant5_Value_l
  //  Referenced by: '<S585>/Constant5'

  false,

  // Computed Parameter: Constant_Value_mp
  //  Referenced by: '<S377>/Constant'

  1,

  // Computed Parameter: Constant2_Value_k
  //  Referenced by: '<S377>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_i
  //  Referenced by: '<S377>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_j
  //  Referenced by: '<S377>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_dt
  //  Referenced by: '<S430>/Constant'

  1,

  // Computed Parameter: Constant2_Value_l
  //  Referenced by: '<S430>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_j
  //  Referenced by: '<S430>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_c
  //  Referenced by: '<S430>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_d5
  //  Referenced by: '<S480>/Constant'

  1,

  // Computed Parameter: Constant2_Value_e
  //  Referenced by: '<S480>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_k
  //  Referenced by: '<S480>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_n
  //  Referenced by: '<S480>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S530>/Constant'

  1,

  // Computed Parameter: Constant2_Value_m
  //  Referenced by: '<S530>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_d
  //  Referenced by: '<S530>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_b
  //  Referenced by: '<S530>/Constant4'

  -1,

  // Computed Parameter: ManualSwitch1_CurrentSetting
  //  Referenced by: '<S7>/Manual Switch1'

  0U,

  // Computed Parameter: ManualSwitch2_CurrentSetting
  //  Referenced by: '<S7>/Manual Switch2'

  0U,

  // Computed Parameter: ManualSwitch3_CurrentSetting
  //  Referenced by: '<S7>/Manual Switch3'

  0U,

  // Computed Parameter: ManualSwitch4_CurrentSetting
  //  Referenced by: '<S7>/Manual Switch4'

  0U,

  // Computed Parameter: ManualSwitch5_CurrentSetting
  //  Referenced by: '<S7>/Manual Switch5'

  0U,

  // Computed Parameter: ManualSwitch_CurrentSetting
  //  Referenced by: '<S7>/Manual Switch'

  0U,

  // Computed Parameter: Constant_Value_fm
  //  Referenced by: '<S577>/Constant'

  0U,

  // Computed Parameter: Constant6_Value
  //  Referenced by: '<S585>/Constant6'

  255U
};

//
// File trailer for generated code.
//
// [EOF]
//
