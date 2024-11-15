//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_HEXA_Hovering_data.cpp
//
// Code generated for Simulink model 'FLIGHT_HEXA_Hovering'.
//
// Model version                  : 5.25
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Oct 16 16:25:30 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FLIGHT_HEXA_Hovering.h"

// Block parameters (default storage)
P_FLIGHT_HEXA_Hovering_T FLIGHT_HEXA_Hovering_P = {
  // Mask Parameter: PIDController_D
  //  Referenced by: '<S102>/Derivative Gain'

  0.0,

  // Mask Parameter: PIDController1_D
  //  Referenced by: '<S154>/Derivative Gain'

  0.0025,

  // Mask Parameter: PIDController2_D
  //  Referenced by: '<S206>/Derivative Gain'

  0.0025,

  // Mask Parameter: PID_Altitude_D
  //  Referenced by: '<S517>/Derivative Gain'

  0.01,

  // Mask Parameter: PID_vz_D
  //  Referenced by: '<S569>/Derivative Gain'

  0.05,

  // Mask Parameter: PIDController_I
  //  Referenced by: '<S106>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController1_I
  //  Referenced by: '<S158>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController2_I
  //  Referenced by: '<S210>/Integral Gain'

  0.0,

  // Mask Parameter: PID_Altitude_I
  //  Referenced by: '<S521>/Integral Gain'

  0.01,

  // Mask Parameter: PID_vz_I
  //  Referenced by: '<S573>/Integral Gain'

  0.1,

  // Mask Parameter: PIDController_InitialConditionForFilter
  //  Referenced by: '<S104>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialConditionForFilter
  //  Referenced by: '<S156>/Filter'

  0.0,

  // Mask Parameter: PIDController2_InitialConditionForFilter
  //  Referenced by: '<S208>/Filter'

  0.0,

  // Mask Parameter: PID_Altitude_InitialConditionForFilter
  //  Referenced by: '<S519>/Filter'

  0.0,

  // Mask Parameter: PID_vz_InitialConditionForFilter
  //  Referenced by: '<S571>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditionForIntegrator
  //  Referenced by: '<S109>/Integrator'

  0.0,

  // Mask Parameter: PIDController1_InitialConditionForIntegrator
  //  Referenced by: '<S161>/Integrator'

  0.0,

  // Mask Parameter: PIDController2_InitialConditionForIntegrator
  //  Referenced by: '<S213>/Integrator'

  0.0,

  // Mask Parameter: PID_Altitude_InitialConditionForIntegrator
  //  Referenced by: '<S524>/Integrator'

  0.0,

  // Mask Parameter: PID_vz_InitialConditionForIntegrator
  //  Referenced by: '<S576>/Integrator'

  0.0,

  // Mask Parameter: PIDController_LowerSaturationLimit
  //  Referenced by:
  //    '<S116>/Saturation'
  //    '<S101>/DeadZone'

  -0.1,

  // Mask Parameter: PIDController1_LowerSaturationLimit
  //  Referenced by:
  //    '<S168>/Saturation'
  //    '<S153>/DeadZone'

  -0.2,

  // Mask Parameter: PIDController2_LowerSaturationLimit
  //  Referenced by:
  //    '<S220>/Saturation'
  //    '<S205>/DeadZone'

  -0.2,

  // Mask Parameter: PIDController1_LowerSaturationLimit_e
  //  Referenced by: '<S429>/Saturation'

  -4.0,

  // Mask Parameter: PIDController_LowerSaturationLimit_j
  //  Referenced by: '<S379>/Saturation'

  -0.3490658503988659,

  // Mask Parameter: PIDController5_LowerSaturationLimit
  //  Referenced by: '<S479>/Saturation'

  -0.87266462599716477,

  // Mask Parameter: PID_Altitude_LowerSaturationLimit
  //  Referenced by:
  //    '<S531>/Saturation'
  //    '<S516>/DeadZone'

  -2.0,

  // Mask Parameter: PID_vz_LowerSaturationLimit
  //  Referenced by:
  //    '<S583>/Saturation'
  //    '<S568>/DeadZone'

  0.0,

  // Mask Parameter: PIDController_N
  //  Referenced by: '<S112>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController1_N
  //  Referenced by: '<S164>/Filter Coefficient'

  50.0,

  // Mask Parameter: PIDController2_N
  //  Referenced by: '<S216>/Filter Coefficient'

  50.0,

  // Mask Parameter: PID_Altitude_N
  //  Referenced by: '<S527>/Filter Coefficient'

  10.0,

  // Mask Parameter: PID_vz_N
  //  Referenced by: '<S579>/Filter Coefficient'

  10.0,

  // Mask Parameter: PIDController_P
  //  Referenced by: '<S114>/Proportional Gain'

  0.2,

  // Mask Parameter: PIDController3_P
  //  Referenced by: '<S268>/Proportional Gain'

  4.0,

  // Mask Parameter: PIDController1_P
  //  Referenced by: '<S166>/Proportional Gain'

  0.035,

  // Mask Parameter: PIDController4_P
  //  Referenced by: '<S318>/Proportional Gain'

  4.0,

  // Mask Parameter: PIDController2_P
  //  Referenced by: '<S218>/Proportional Gain'

  0.035,

  // Mask Parameter: PIDController1_P_h
  //  Referenced by: '<S427>/Proportional Gain'

  0.6,

  // Mask Parameter: PIDController_P_d
  //  Referenced by: '<S377>/Proportional Gain'

  0.3,

  // Mask Parameter: PIDController5_P
  //  Referenced by: '<S477>/Proportional Gain'

  2.0,

  // Mask Parameter: PID_Altitude_P
  //  Referenced by: '<S529>/Proportional Gain'

  1.5,

  // Mask Parameter: PID_vz_P
  //  Referenced by: '<S581>/Proportional Gain'

  0.5,

  // Mask Parameter: PIDController_UpperSaturationLimit
  //  Referenced by:
  //    '<S116>/Saturation'
  //    '<S101>/DeadZone'

  0.1,

  // Mask Parameter: PIDController1_UpperSaturationLimit
  //  Referenced by:
  //    '<S168>/Saturation'
  //    '<S153>/DeadZone'

  0.2,

  // Mask Parameter: PIDController2_UpperSaturationLimit
  //  Referenced by:
  //    '<S220>/Saturation'
  //    '<S205>/DeadZone'

  0.2,

  // Mask Parameter: PIDController1_UpperSaturationLimit_l
  //  Referenced by: '<S429>/Saturation'

  4.0,

  // Mask Parameter: PIDController_UpperSaturationLimit_b
  //  Referenced by: '<S379>/Saturation'

  0.3490658503988659,

  // Mask Parameter: PIDController5_UpperSaturationLimit
  //  Referenced by: '<S479>/Saturation'

  0.87266462599716477,

  // Mask Parameter: PID_Altitude_UpperSaturationLimit
  //  Referenced by:
  //    '<S531>/Saturation'
  //    '<S516>/DeadZone'

  2.0,

  // Mask Parameter: PID_vz_UpperSaturationLimit
  //  Referenced by:
  //    '<S583>/Saturation'
  //    '<S568>/DeadZone'

  1.0,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S13>/Constant'

  1400U,

  // Mask Parameter: CompareToConstant_const_d
  //  Referenced by: '<S43>/Constant'

  5U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S50>/Out1'

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
  //  Referenced by: '<S55>/Constant'

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
  //  Referenced by: '<S49>/Constant'

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
  //  Referenced by: '<S62>/Out1'

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
  //  Referenced by: '<S47>/Constant'

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
  //  Referenced by: '<S24>/Out1'

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
  //  Referenced by: '<S18>/Constant'

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

  // Computed Parameter: Out1_Y0_m
  //  Referenced by: '<S22>/Out1'

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

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S21>/Constant'

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
  //  Referenced by: '<S23>/Out1'

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

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S17>/Constant'

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
  //  Referenced by: '<S61>/Out1'

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

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S46>/Constant'

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
  //  Referenced by: '<S19>/Out1'

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
  //  Referenced by: '<S14>/Constant'

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

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S20>/Out1'

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

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S15>/Constant'

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

  // Expression: -1
  //  Referenced by: '<S6>/Read Parameter1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S6>/Read Parameter13'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S6>/Read Parameter2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S6>/Read Parameter3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S6>/Read Parameter4'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S6>/Read Parameter5'

  -1.0,

  // Expression: 100
  //  Referenced by: '<S6>/Fault1'

  100.0,

  // Expression: 100
  //  Referenced by: '<S6>/Constant1'

  100.0,

  // Expression: 100
  //  Referenced by: '<S6>/Fault2'

  100.0,

  // Expression: 100
  //  Referenced by: '<S6>/Constant2'

  100.0,

  // Expression: 100
  //  Referenced by: '<S6>/Fault3'

  100.0,

  // Expression: 100
  //  Referenced by: '<S6>/Constant3'

  100.0,

  // Expression: 100
  //  Referenced by: '<S6>/Fault4'

  100.0,

  // Expression: 100
  //  Referenced by: '<S6>/Constant4'

  100.0,

  // Expression: 100
  //  Referenced by: '<S6>/Fault5'

  100.0,

  // Expression: 100
  //  Referenced by: '<S6>/Constant5'

  100.0,

  // Expression: 100
  //  Referenced by: '<S6>/Fault'

  100.0,

  // Expression: 100
  //  Referenced by: '<S6>/Constant'

  100.0,

  // Computed Parameter: yaw_Out_Y0
  //  Referenced by: '<S41>/yaw_Out'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S39>/Delay'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S39>/Rate'

  0.01,

  // Expression: -1
  //  Referenced by: '<S39>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S39>/Gain'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S40>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S40>/Constant'

  0.0,

  // Computed Parameter: Out_Y0
  //  Referenced by: '<S37>/Out'

  0.0,

  // Expression: -1
  //  Referenced by: '<S35>/Gain'

  -1.0,

  // Computed Parameter: yaw_Out_Y0_f
  //  Referenced by: '<S38>/yaw_Out'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S35>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S35>/Switch'

  0.0,

  // Expression: 0.02
  //  Referenced by: '<S35>/Rate of descent'

  0.02,

  // Expression: -1
  //  Referenced by: '<S35>/Gain2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S35>/Gain1'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S36>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S36>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S42>/Constant'

  0.0,

  // Expression: 6
  //  Referenced by: '<S32>/Constant'

  6.0,

  // Computed Parameter: yaw_Out_Y0_p
  //  Referenced by: '<S34>/yaw_Out'

  0.0,

  // Expression: 1
  //  Referenced by: '<S33>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant'

  0.0,

  // Expression: -1
  //  Referenced by: '<S28>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S59>/Read Parameter'

  -1.0,

  // Computed Parameter: tau_Yaw_Y0
  //  Referenced by: '<S63>/tau_Yaw'

  0.0,

  // Computed Parameter: tau_Pitch_Y0
  //  Referenced by: '<S63>/tau_Pitch'

  0.0,

  // Computed Parameter: tau_Roll_Y0
  //  Referenced by: '<S63>/tau_Roll'

  0.0,

  // Expression: 0
  //  Referenced by: '<S99>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S151>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S203>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S99>/Clamping_zero'

  0.0,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S109>/Integrator'

  0.004,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S104>/Filter'

  0.004,

  // Expression: 40*pi/180
  //  Referenced by: '<S63>/Rate Limiter2'

  0.69813170079773179,

  // Expression: -40*pi/180
  //  Referenced by: '<S63>/Rate Limiter2'

  -0.69813170079773179,

  // Expression: 0
  //  Referenced by: '<S63>/Rate Limiter2'

  0.0,

  // Expression: 20*pi/180
  //  Referenced by: '<S63>/Saturation1'

  0.3490658503988659,

  // Expression: -20*pi/180
  //  Referenced by: '<S63>/Saturation1'

  -0.3490658503988659,

  // Expression: 0
  //  Referenced by: '<S151>/Clamping_zero'

  0.0,

  // Computed Parameter: Integrator_gainval_i
  //  Referenced by: '<S161>/Integrator'

  0.004,

  // Computed Parameter: Filter_gainval_e
  //  Referenced by: '<S156>/Filter'

  0.004,

  // Expression: 40*pi/180
  //  Referenced by: '<S63>/Rate Limiter1'

  0.69813170079773179,

  // Expression: -40*pi/180
  //  Referenced by: '<S63>/Rate Limiter1'

  -0.69813170079773179,

  // Expression: 0
  //  Referenced by: '<S63>/Rate Limiter1'

  0.0,

  // Expression: 20*pi/180
  //  Referenced by: '<S63>/Saturation'

  0.3490658503988659,

  // Expression: -20*pi/180
  //  Referenced by: '<S63>/Saturation'

  -0.3490658503988659,

  // Expression: 0
  //  Referenced by: '<S203>/Clamping_zero'

  0.0,

  // Computed Parameter: Integrator_gainval_f
  //  Referenced by: '<S213>/Integrator'

  0.004,

  // Computed Parameter: Filter_gainval_l
  //  Referenced by: '<S208>/Filter'

  0.004,

  // Expression: 0
  //  Referenced by: '<S330>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S332>/Switch1'

  0.0,

  // Computed Parameter: des_pitch_Y0
  //  Referenced by: '<S66>/des_pitch'

  0.0,

  // Computed Parameter: des_roll_Y0
  //  Referenced by: '<S66>/des_roll'

  0.0,

  // Computed Parameter: des_yawrate_Y0
  //  Referenced by: '<S66>/des_yawrate'

  0.0,

  // Computed Parameter: tau_Thrust_Y0
  //  Referenced by: '<S66>/tau_Thrust'

  0.0,

  // Expression: 0
  //  Referenced by: '<S514>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S566>/Constant1'

  0.0,

  // Expression: -1
  //  Referenced by: '<S331>/Gain'

  -1.0,

  // Expression: 2*pi
  //  Referenced by: '<S332>/Constant'

  6.2831853071795862,

  // Expression: pi
  //  Referenced by: '<S332>/Switch'

  3.1415926535897931,

  // Expression: -1
  //  Referenced by: '<S66>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S330>/Gain1'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S514>/Clamping_zero'

  0.0,

  // Computed Parameter: Filter_gainval_i
  //  Referenced by: '<S519>/Filter'

  0.004,

  // Computed Parameter: Integrator_gainval_p
  //  Referenced by: '<S524>/Integrator'

  0.004,

  // Expression: 0
  //  Referenced by: '<S566>/Clamping_zero'

  0.0,

  // Computed Parameter: Filter_gainval_m
  //  Referenced by: '<S571>/Filter'

  0.004,

  // Computed Parameter: Integrator_gainval_k
  //  Referenced by: '<S576>/Integrator'

  0.004,

  // Expression: [1 0 0 0]
  //  Referenced by: '<S67>/Constant'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<S597>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S598>/Constant'

  1.0,

  // Expression: [1 -1 0 -1;1 1 0 1;1 0.5 0.5 -1;1 -0.5 -0.5 1; 1 -0.5 0.5 1; 1 0.5 -0.5 -1]
  //  Referenced by: '<S5>/Mixer matrix'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 0.5, -0.5, -0.5, 0.5, 0.0, 0.0, 0.5,
    -0.5, 0.5, -0.5, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0 },

  // Expression: 1500
  //  Referenced by: '<S65>/Constant2'

  1500.0,

  // Expression: 1/400
  //  Referenced by: '<S65>/Gain2'

  0.0025,

  // Expression: 1
  //  Referenced by: '<S65>/Saturation2'

  1.0,

  // Expression: -1
  //  Referenced by: '<S65>/Saturation2'

  -1.0,

  // Expression: -20*pi/180
  //  Referenced by: '<S4>/Gain1'

  -0.3490658503988659,

  // Expression: 1500
  //  Referenced by: '<S65>/Constant1'

  1500.0,

  // Expression: 1/400
  //  Referenced by: '<S65>/Gain1'

  0.0025,

  // Expression: 1
  //  Referenced by: '<S65>/Saturation1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S65>/Saturation1'

  -1.0,

  // Expression: 20*pi/180
  //  Referenced by: '<S4>/Gain2'

  0.3490658503988659,

  // Expression: 1100
  //  Referenced by: '<S65>/Constant'

  1100.0,

  // Expression: 1/800
  //  Referenced by: '<S65>/Gain'

  0.00125,

  // Expression: 0.90
  //  Referenced by: '<S65>/Saturation'

  0.9,

  // Expression: 0
  //  Referenced by: '<S65>/Saturation'

  0.0,

  // Expression: 1500
  //  Referenced by: '<S65>/Constant3'

  1500.0,

  // Expression: 1/400
  //  Referenced by: '<S65>/Gain3'

  0.0025,

  // Expression: 1
  //  Referenced by: '<S65>/Saturation3'

  1.0,

  // Expression: -1
  //  Referenced by: '<S65>/Saturation3'

  -1.0,

  // Expression: 50*pi/180
  //  Referenced by: '<S4>/Gain4'

  0.87266462599716477,

  // Expression: 0
  //  Referenced by: '<S67>/Switch'

  0.0,

  // Expression: -1
  //  Referenced by: '<S4>/Gain'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S5>/Bias'

  1.0,

  // Expression: 1000
  //  Referenced by: '<S5>/Gain1'

  1000.0,

  // Expression: 1100
  //  Referenced by: '<S7>/IDLE PWM'

  1100.0,

  // Expression: 0.01
  //  Referenced by: '<S7>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S7>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S7>/Saturation1'

  0.0,

  // Expression: 1100
  //  Referenced by: '<S7>/Constant'

  1100.0,

  // Expression: 1100
  //  Referenced by: '<S8>/IDLE PWM'

  1100.0,

  // Expression: 0.01
  //  Referenced by: '<S8>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S8>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S8>/Saturation1'

  0.0,

  // Expression: 1100
  //  Referenced by: '<S8>/Constant'

  1100.0,

  // Expression: 1100
  //  Referenced by: '<S9>/IDLE PWM'

  1100.0,

  // Expression: 0.01
  //  Referenced by: '<S9>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S9>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S9>/Saturation1'

  0.0,

  // Expression: 1100
  //  Referenced by: '<S9>/Constant'

  1100.0,

  // Expression: 1100
  //  Referenced by: '<S10>/IDLE PWM'

  1100.0,

  // Expression: 0.01
  //  Referenced by: '<S10>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S10>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S10>/Saturation1'

  0.0,

  // Expression: 1100
  //  Referenced by: '<S10>/Constant'

  1100.0,

  // Expression: 1100
  //  Referenced by: '<S11>/IDLE PWM'

  1100.0,

  // Expression: 0.01
  //  Referenced by: '<S11>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S11>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S11>/Saturation1'

  0.0,

  // Expression: 1100
  //  Referenced by: '<S11>/Constant'

  1100.0,

  // Expression: 1100
  //  Referenced by: '<S12>/IDLE PWM'

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
  //  Referenced by: '<S12>/Constant'

  1100.0,

  // Computed Parameter: Constant7_Value
  //  Referenced by: '<S53>/Constant7'

  (0ULL),

  // Computed Parameter: Constant1_Value_dr
  //  Referenced by: '<S60>/Constant1'

  { 0.0F, 0.0F },

  // Computed Parameter: Constant_Value_f2
  //  Referenced by: '<S60>/Constant'

  0.0F,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: '<S59>/Gain'

  -1.0F,

  // Computed Parameter: Constant1_Value_k4
  //  Referenced by: '<S59>/Constant1'

  { 0.0F, 0.0F },

  // Computed Parameter: Constant_Value_l4
  //  Referenced by: '<S59>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_fh
  //  Referenced by: '<S53>/Constant'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant1_Value_h
  //  Referenced by: '<S53>/Constant1'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant2_Value_f
  //  Referenced by: '<S53>/Constant2'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant3_Value_al
  //  Referenced by: '<S53>/Constant3'

  0.0F,

  // Computed Parameter: Constant4_Value_g
  //  Referenced by: '<S53>/Constant4'

  0.0F,

  // Computed Parameter: Saturation_UpperSat_g
  //  Referenced by: '<S5>/Saturation'

  2000U,

  // Computed Parameter: Saturation_LowerSat_j
  //  Referenced by: '<S5>/Saturation'

  1000U,

  // Computed Parameter: Constant5_Value_j
  //  Referenced by: '<S51>/Constant5'

  true,

  // Computed Parameter: Constant5_Value_k
  //  Referenced by: '<S52>/Constant5'

  true,

  // Computed Parameter: Constant1_Value_dl
  //  Referenced by: '<S54>/Constant1'

  true,

  // Computed Parameter: Constant5_Value_h
  //  Referenced by: '<S54>/Constant5'

  true,

  // Computed Parameter: Constant5_Value_l
  //  Referenced by: '<S53>/Constant5'

  false,

  // Expression: false
  //  Referenced by: '<S5>/Constant1'

  false,

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S99>/Constant'

  1,

  // Computed Parameter: Constant2_Value_j
  //  Referenced by: '<S99>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_l
  //  Referenced by: '<S99>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_o
  //  Referenced by: '<S99>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_bd
  //  Referenced by: '<S151>/Constant'

  1,

  // Computed Parameter: Constant2_Value_fs
  //  Referenced by: '<S151>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_n
  //  Referenced by: '<S151>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_n
  //  Referenced by: '<S151>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S203>/Constant'

  1,

  // Computed Parameter: Constant2_Value_p
  //  Referenced by: '<S203>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_b
  //  Referenced by: '<S203>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_l
  //  Referenced by: '<S203>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_nq
  //  Referenced by: '<S514>/Constant'

  1,

  // Computed Parameter: Constant2_Value_o
  //  Referenced by: '<S514>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_o
  //  Referenced by: '<S514>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_d
  //  Referenced by: '<S514>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_d3
  //  Referenced by: '<S566>/Constant'

  1,

  // Computed Parameter: Constant2_Value_pb
  //  Referenced by: '<S566>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_m
  //  Referenced by: '<S566>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_c
  //  Referenced by: '<S566>/Constant4'

  -1,

  // Computed Parameter: ManualSwitch1_CurrentSetting
  //  Referenced by: '<S6>/Manual Switch1'

  0U,

  // Computed Parameter: ManualSwitch2_CurrentSetting
  //  Referenced by: '<S6>/Manual Switch2'

  0U,

  // Computed Parameter: ManualSwitch3_CurrentSetting
  //  Referenced by: '<S6>/Manual Switch3'

  0U,

  // Computed Parameter: ManualSwitch4_CurrentSetting
  //  Referenced by: '<S6>/Manual Switch4'

  0U,

  // Computed Parameter: ManualSwitch5_CurrentSetting
  //  Referenced by: '<S6>/Manual Switch5'

  0U,

  // Computed Parameter: ManualSwitch_CurrentSetting
  //  Referenced by: '<S6>/Manual Switch'

  0U,

  // Computed Parameter: Constant_Value_fm
  //  Referenced by: '<S45>/Constant'

  0U,

  // Computed Parameter: Constant6_Value
  //  Referenced by: '<S53>/Constant6'

  255U
};

//
// File trailer for generated code.
//
// [EOF]
//
