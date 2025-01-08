//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_HEXA_Hovering_data.cpp
//
// Code generated for Simulink model 'FLIGHT_HEXA_Hovering'.
//
// Model version                  : 5.30
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Jan  8 13:53:58 2025
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
  //  Referenced by: '<S112>/Derivative Gain'

  0.0,

  // Mask Parameter: PIDController1_D
  //  Referenced by: '<S164>/Derivative Gain'

  0.0025,

  // Mask Parameter: PIDController2_D
  //  Referenced by: '<S216>/Derivative Gain'

  0.0025,

  // Mask Parameter: PID_Altitude_D
  //  Referenced by: '<S527>/Derivative Gain'

  0.01,

  // Mask Parameter: PID_vz_D
  //  Referenced by: '<S579>/Derivative Gain'

  0.05,

  // Mask Parameter: PIDController_I
  //  Referenced by: '<S116>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController1_I
  //  Referenced by: '<S168>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController2_I
  //  Referenced by: '<S220>/Integral Gain'

  0.0,

  // Mask Parameter: PID_Altitude_I
  //  Referenced by: '<S531>/Integral Gain'

  0.01,

  // Mask Parameter: PID_vz_I
  //  Referenced by: '<S583>/Integral Gain'

  0.1,

  // Mask Parameter: PIDController_InitialConditionForFilter
  //  Referenced by: '<S114>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialConditionForFilter
  //  Referenced by: '<S166>/Filter'

  0.0,

  // Mask Parameter: PIDController2_InitialConditionForFilter
  //  Referenced by: '<S218>/Filter'

  0.0,

  // Mask Parameter: PID_Altitude_InitialConditionForFilter
  //  Referenced by: '<S529>/Filter'

  0.0,

  // Mask Parameter: PID_vz_InitialConditionForFilter
  //  Referenced by: '<S581>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditionForIntegrator
  //  Referenced by: '<S119>/Integrator'

  0.0,

  // Mask Parameter: PIDController1_InitialConditionForIntegrator
  //  Referenced by: '<S171>/Integrator'

  0.0,

  // Mask Parameter: PIDController2_InitialConditionForIntegrator
  //  Referenced by: '<S223>/Integrator'

  0.0,

  // Mask Parameter: PID_Altitude_InitialConditionForIntegrator
  //  Referenced by: '<S534>/Integrator'

  0.0,

  // Mask Parameter: PID_vz_InitialConditionForIntegrator
  //  Referenced by: '<S586>/Integrator'

  0.0,

  // Mask Parameter: PIDController_LowerSaturationLimit
  //  Referenced by:
  //    '<S126>/Saturation'
  //    '<S111>/DeadZone'

  -0.1,

  // Mask Parameter: PIDController1_LowerSaturationLimit
  //  Referenced by:
  //    '<S178>/Saturation'
  //    '<S163>/DeadZone'

  -0.2,

  // Mask Parameter: PIDController2_LowerSaturationLimit
  //  Referenced by:
  //    '<S230>/Saturation'
  //    '<S215>/DeadZone'

  -0.2,

  // Mask Parameter: PIDController1_LowerSaturationLimit_h
  //  Referenced by: '<S439>/Saturation'

  -4.0,

  // Mask Parameter: PIDController_LowerSaturationLimit_o
  //  Referenced by: '<S389>/Saturation'

  -0.3490658503988659,

  // Mask Parameter: PIDController5_LowerSaturationLimit
  //  Referenced by: '<S489>/Saturation'

  -0.87266462599716477,

  // Mask Parameter: PID_Altitude_LowerSaturationLimit
  //  Referenced by:
  //    '<S541>/Saturation'
  //    '<S526>/DeadZone'

  -2.0,

  // Mask Parameter: PID_vz_LowerSaturationLimit
  //  Referenced by:
  //    '<S593>/Saturation'
  //    '<S578>/DeadZone'

  0.0,

  // Mask Parameter: PIDController_N
  //  Referenced by: '<S122>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController1_N
  //  Referenced by: '<S174>/Filter Coefficient'

  50.0,

  // Mask Parameter: PIDController2_N
  //  Referenced by: '<S226>/Filter Coefficient'

  50.0,

  // Mask Parameter: PID_Altitude_N
  //  Referenced by: '<S537>/Filter Coefficient'

  10.0,

  // Mask Parameter: PID_vz_N
  //  Referenced by: '<S589>/Filter Coefficient'

  10.0,

  // Mask Parameter: PIDController_P
  //  Referenced by: '<S124>/Proportional Gain'

  0.2,

  // Mask Parameter: PIDController3_P
  //  Referenced by: '<S278>/Proportional Gain'

  4.0,

  // Mask Parameter: PIDController1_P
  //  Referenced by: '<S176>/Proportional Gain'

  0.035,

  // Mask Parameter: PIDController4_P
  //  Referenced by: '<S328>/Proportional Gain'

  4.0,

  // Mask Parameter: PIDController2_P
  //  Referenced by: '<S228>/Proportional Gain'

  0.035,

  // Mask Parameter: PIDController1_P_f
  //  Referenced by: '<S437>/Proportional Gain'

  0.6,

  // Mask Parameter: PIDController_P_b
  //  Referenced by: '<S387>/Proportional Gain'

  0.3,

  // Mask Parameter: PIDController5_P
  //  Referenced by: '<S487>/Proportional Gain'

  2.0,

  // Mask Parameter: PID_Altitude_P
  //  Referenced by: '<S539>/Proportional Gain'

  1.5,

  // Mask Parameter: PID_vz_P
  //  Referenced by: '<S591>/Proportional Gain'

  0.5,

  // Mask Parameter: PIDController_UpperSaturationLimit
  //  Referenced by:
  //    '<S126>/Saturation'
  //    '<S111>/DeadZone'

  0.1,

  // Mask Parameter: PIDController1_UpperSaturationLimit
  //  Referenced by:
  //    '<S178>/Saturation'
  //    '<S163>/DeadZone'

  0.2,

  // Mask Parameter: PIDController2_UpperSaturationLimit
  //  Referenced by:
  //    '<S230>/Saturation'
  //    '<S215>/DeadZone'

  0.2,

  // Mask Parameter: PIDController1_UpperSaturationLimit_e
  //  Referenced by: '<S439>/Saturation'

  4.0,

  // Mask Parameter: PIDController_UpperSaturationLimit_e
  //  Referenced by: '<S389>/Saturation'

  0.3490658503988659,

  // Mask Parameter: PIDController5_UpperSaturationLimit
  //  Referenced by: '<S489>/Saturation'

  0.87266462599716477,

  // Mask Parameter: PID_Altitude_UpperSaturationLimit
  //  Referenced by:
  //    '<S541>/Saturation'
  //    '<S526>/DeadZone'

  2.0,

  // Mask Parameter: PID_vz_UpperSaturationLimit
  //  Referenced by:
  //    '<S593>/Saturation'
  //    '<S578>/DeadZone'

  1.0,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S60>/Constant'

  1800.0,

  // Mask Parameter: CompareToConstant_const_d
  //  Referenced by: '<S61>/Constant'

  1400U,

  // Mask Parameter: CompareToConstant_const_dt
  //  Referenced by: '<S34>/Constant'

  5U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S41>/Out1'

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
  //  Referenced by: '<S46>/Constant'

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
  //  Referenced by: '<S40>/Constant'

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
  //  Referenced by: '<S53>/Out1'

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
  //  Referenced by: '<S38>/Constant'

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
  //  Referenced by: '<S15>/Out1'

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
  //  Referenced by: '<S9>/Constant'

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

  // Computed Parameter: Constant_Value_f
  //  Referenced by: '<S71>/Constant'

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

  // Computed Parameter: Out1_Y0_m
  //  Referenced by: '<S13>/Out1'

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

  // Computed Parameter: Out1_Y0_j
  //  Referenced by: '<S70>/Out1'

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

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S69>/Constant'

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
  //  Referenced by: '<S12>/Constant'

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
  //  Referenced by: '<S14>/Out1'

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
  //  Referenced by: '<S8>/Constant'

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
  //  Referenced by: '<S52>/Out1'

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
  //  Referenced by: '<S37>/Constant'

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
  //  Referenced by: '<S10>/Out1'

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
  //  Referenced by: '<S5>/Constant'

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
  //  Referenced by: '<S11>/Out1'

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

  // Computed Parameter: Out1_Y0_l
  //  Referenced by: '<S68>/Out1'

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
  //  Referenced by: '<S6>/Constant'

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

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S57>/Constant'

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

  // Computed Parameter: yaw_Out_Y0
  //  Referenced by: '<S32>/yaw_Out'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S30>/Rate'

  0.01,

  // Expression: -1
  //  Referenced by: '<S30>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S30>/Gain'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S31>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S31>/Constant'

  0.0,

  // Computed Parameter: Out_Y0
  //  Referenced by: '<S28>/Out'

  0.0,

  // Expression: -1
  //  Referenced by: '<S26>/Gain'

  -1.0,

  // Computed Parameter: yaw_Out_Y0_f
  //  Referenced by: '<S29>/yaw_Out'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S21>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S26>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S26>/Switch'

  0.0,

  // Expression: 0.02
  //  Referenced by: '<S26>/Rate of descent'

  0.02,

  // Expression: -1
  //  Referenced by: '<S26>/Gain2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S26>/Gain1'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S27>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S27>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant'

  0.0,

  // Expression: 6
  //  Referenced by: '<S23>/Constant'

  6.0,

  // Computed Parameter: yaw_Out_Y0_p
  //  Referenced by: '<S25>/yaw_Out'

  0.0,

  // Expression: 1
  //  Referenced by: '<S24>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S24>/Constant'

  0.0,

  // Expression: -1
  //  Referenced by: '<S19>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S51>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S50>/Read Parameter'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S54>/Constant1'

  0.0,

  // Expression: 100
  //  Referenced by: '<S55>/Constant1'

  100.0,

  // Expression: 0.01
  //  Referenced by: '<S63>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S63>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S63>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S54>/Constant2'

  0.0,

  // Expression: 100
  //  Referenced by: '<S55>/Constant2'

  100.0,

  // Expression: 0.01
  //  Referenced by: '<S64>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S64>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S64>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S54>/Constant3'

  0.0,

  // Expression: 100
  //  Referenced by: '<S55>/Constant3'

  100.0,

  // Expression: 0.01
  //  Referenced by: '<S65>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S65>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S65>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S54>/Constant4'

  0.0,

  // Expression: 100
  //  Referenced by: '<S55>/Constant4'

  100.0,

  // Expression: 0.01
  //  Referenced by: '<S66>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S66>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S66>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S54>/Constant5'

  0.0,

  // Expression: 100
  //  Referenced by: '<S55>/Constant5'

  100.0,

  // Expression: 0.01
  //  Referenced by: '<S67>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S67>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S67>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S54>/Constant'

  0.0,

  // Expression: 100
  //  Referenced by: '<S55>/Constant'

  100.0,

  // Expression: 0.01
  //  Referenced by: '<S62>/Gain'

  0.01,

  // Expression: 1
  //  Referenced by: '<S62>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S62>/Saturation'

  0.0,

  // Expression: -1
  //  Referenced by: '<S55>/Read Parameter1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S55>/Read Parameter13'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S55>/Read Parameter2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S55>/Read Parameter3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S55>/Read Parameter4'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S55>/Read Parameter5'

  -1.0,

  // Computed Parameter: tau_Yaw_Y0
  //  Referenced by: '<S73>/tau_Yaw'

  0.0,

  // Computed Parameter: tau_Pitch_Y0
  //  Referenced by: '<S73>/tau_Pitch'

  0.0,

  // Computed Parameter: tau_Roll_Y0
  //  Referenced by: '<S73>/tau_Roll'

  0.0,

  // Expression: 0
  //  Referenced by: '<S109>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S161>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S213>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S109>/Clamping_zero'

  0.0,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S119>/Integrator'

  0.004,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S114>/Filter'

  0.004,

  // Expression: 40*pi/180
  //  Referenced by: '<S73>/Rate Limiter2'

  0.69813170079773179,

  // Expression: -40*pi/180
  //  Referenced by: '<S73>/Rate Limiter2'

  -0.69813170079773179,

  // Expression: 0
  //  Referenced by: '<S73>/Rate Limiter2'

  0.0,

  // Expression: 20*pi/180
  //  Referenced by: '<S73>/Saturation1'

  0.3490658503988659,

  // Expression: -20*pi/180
  //  Referenced by: '<S73>/Saturation1'

  -0.3490658503988659,

  // Expression: 0
  //  Referenced by: '<S161>/Clamping_zero'

  0.0,

  // Computed Parameter: Integrator_gainval_i
  //  Referenced by: '<S171>/Integrator'

  0.004,

  // Computed Parameter: Filter_gainval_p
  //  Referenced by: '<S166>/Filter'

  0.004,

  // Expression: 40*pi/180
  //  Referenced by: '<S73>/Rate Limiter1'

  0.69813170079773179,

  // Expression: -40*pi/180
  //  Referenced by: '<S73>/Rate Limiter1'

  -0.69813170079773179,

  // Expression: 0
  //  Referenced by: '<S73>/Rate Limiter1'

  0.0,

  // Expression: 20*pi/180
  //  Referenced by: '<S73>/Saturation'

  0.3490658503988659,

  // Expression: -20*pi/180
  //  Referenced by: '<S73>/Saturation'

  -0.3490658503988659,

  // Expression: 0
  //  Referenced by: '<S213>/Clamping_zero'

  0.0,

  // Computed Parameter: Integrator_gainval_p
  //  Referenced by: '<S223>/Integrator'

  0.004,

  // Computed Parameter: Filter_gainval_k
  //  Referenced by: '<S218>/Filter'

  0.004,

  // Expression: 0
  //  Referenced by: '<S340>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S342>/Switch1'

  0.0,

  // Computed Parameter: des_pitch_Y0
  //  Referenced by: '<S76>/des_pitch'

  0.0,

  // Computed Parameter: des_roll_Y0
  //  Referenced by: '<S76>/des_roll'

  0.0,

  // Computed Parameter: des_yawrate_Y0
  //  Referenced by: '<S76>/des_yawrate'

  0.0,

  // Computed Parameter: tau_Thrust_Y0
  //  Referenced by: '<S76>/tau_Thrust'

  0.0,

  // Expression: 0
  //  Referenced by: '<S524>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S576>/Constant1'

  0.0,

  // Expression: -1
  //  Referenced by: '<S341>/Gain'

  -1.0,

  // Expression: 2*pi
  //  Referenced by: '<S342>/Constant'

  6.2831853071795862,

  // Expression: pi
  //  Referenced by: '<S342>/Switch'

  3.1415926535897931,

  // Expression: -1
  //  Referenced by: '<S76>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S340>/Gain1'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S524>/Clamping_zero'

  0.0,

  // Computed Parameter: Filter_gainval_i
  //  Referenced by: '<S529>/Filter'

  0.004,

  // Computed Parameter: Integrator_gainval_p4
  //  Referenced by: '<S534>/Integrator'

  0.004,

  // Expression: 0
  //  Referenced by: '<S576>/Clamping_zero'

  0.0,

  // Computed Parameter: Filter_gainval_d
  //  Referenced by: '<S581>/Filter'

  0.004,

  // Computed Parameter: Integrator_gainval_ik
  //  Referenced by: '<S586>/Integrator'

  0.004,

  // Expression: [1 0 0 0]
  //  Referenced by: '<S77>/Constant'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<S607>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S608>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S77>/Switch'

  0.0,

  // Expression: 1500
  //  Referenced by: '<S75>/Constant2'

  1500.0,

  // Expression: 1/400
  //  Referenced by: '<S75>/Gain2'

  0.0025,

  // Expression: 1
  //  Referenced by: '<S75>/Saturation2'

  1.0,

  // Expression: -1
  //  Referenced by: '<S75>/Saturation2'

  -1.0,

  // Expression: -20*pi/180
  //  Referenced by: '<S4>/Gain1'

  -0.3490658503988659,

  // Expression: 1500
  //  Referenced by: '<S75>/Constant1'

  1500.0,

  // Expression: 1/400
  //  Referenced by: '<S75>/Gain1'

  0.0025,

  // Expression: 1
  //  Referenced by: '<S75>/Saturation1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S75>/Saturation1'

  -1.0,

  // Expression: 20*pi/180
  //  Referenced by: '<S4>/Gain2'

  0.3490658503988659,

  // Expression: 1100
  //  Referenced by: '<S75>/Constant'

  1100.0,

  // Expression: 1/800
  //  Referenced by: '<S75>/Gain'

  0.00125,

  // Expression: 0.90
  //  Referenced by: '<S75>/Saturation'

  0.9,

  // Expression: 0
  //  Referenced by: '<S75>/Saturation'

  0.0,

  // Expression: 1500
  //  Referenced by: '<S75>/Constant3'

  1500.0,

  // Expression: 1/400
  //  Referenced by: '<S75>/Gain3'

  0.0025,

  // Expression: 1
  //  Referenced by: '<S75>/Saturation3'

  1.0,

  // Expression: -1
  //  Referenced by: '<S75>/Saturation3'

  -1.0,

  // Expression: 50*pi/180
  //  Referenced by: '<S4>/Gain4'

  0.87266462599716477,

  // Expression: -1
  //  Referenced by: '<S4>/Gain'

  -1.0,

  // Expression: 5
  //  Referenced by: '<S3>/Gain'

  5.0,

  // Expression: 5
  //  Referenced by: '<S3>/Gain1'

  5.0,

  // Expression: 10
  //  Referenced by: '<S3>/Gain2'

  10.0,

  // Expression: 1
  //  Referenced by: '<S3>/Gain3'

  1.0,

  // Expression: 0
  //  Referenced by: '<S59>/Constant'

  0.0,

  // Computed Parameter: Constant7_Value
  //  Referenced by: '<S44>/Constant7'

  (0ULL),

  // Computed Parameter: Constant1_Value_d
  //  Referenced by: '<S51>/Constant1'

  { 0.0F, 0.0F },

  // Computed Parameter: Constant_Value_f2
  //  Referenced by: '<S51>/Constant'

  0.0F,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: '<S50>/Gain'

  -1.0F,

  // Computed Parameter: Constant1_Value_k4
  //  Referenced by: '<S50>/Constant1'

  { 0.0F, 0.0F },

  // Computed Parameter: Constant_Value_l4
  //  Referenced by: '<S50>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_fh
  //  Referenced by: '<S44>/Constant'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant1_Value_hv
  //  Referenced by: '<S44>/Constant1'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant2_Value_f
  //  Referenced by: '<S44>/Constant2'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant3_Value_a
  //  Referenced by: '<S44>/Constant3'

  0.0F,

  // Computed Parameter: Constant4_Value_g
  //  Referenced by: '<S44>/Constant4'

  0.0F,

  // Computed Parameter: Constant5_Value_j
  //  Referenced by: '<S42>/Constant5'

  true,

  // Computed Parameter: Constant5_Value_k
  //  Referenced by: '<S43>/Constant5'

  true,

  // Computed Parameter: Constant1_Value_dl
  //  Referenced by: '<S45>/Constant1'

  true,

  // Computed Parameter: Constant5_Value_h
  //  Referenced by: '<S45>/Constant5'

  true,

  // Computed Parameter: Constant5_Value_l
  //  Referenced by: '<S44>/Constant5'

  false,

  // Computed Parameter: Constant_Value_ge
  //  Referenced by: '<S109>/Constant'

  1,

  // Computed Parameter: Constant2_Value_i
  //  Referenced by: '<S109>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_h
  //  Referenced by: '<S109>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_f
  //  Referenced by: '<S109>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_a1
  //  Referenced by: '<S161>/Constant'

  1,

  // Computed Parameter: Constant2_Value_l
  //  Referenced by: '<S161>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_j
  //  Referenced by: '<S161>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_a
  //  Referenced by: '<S161>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_jj
  //  Referenced by: '<S213>/Constant'

  1,

  // Computed Parameter: Constant2_Value_o
  //  Referenced by: '<S213>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_l
  //  Referenced by: '<S213>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_n
  //  Referenced by: '<S213>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_n1
  //  Referenced by: '<S524>/Constant'

  1,

  // Computed Parameter: Constant2_Value_gq
  //  Referenced by: '<S524>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_i
  //  Referenced by: '<S524>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_hf
  //  Referenced by: '<S524>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_gf
  //  Referenced by: '<S576>/Constant'

  1,

  // Computed Parameter: Constant2_Value_ga
  //  Referenced by: '<S576>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_b
  //  Referenced by: '<S576>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_fv
  //  Referenced by: '<S576>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_fm
  //  Referenced by: '<S36>/Constant'

  0U,

  // Computed Parameter: Constant6_Value
  //  Referenced by: '<S44>/Constant6'

  255U
};

//
// File trailer for generated code.
//
// [EOF]
//
