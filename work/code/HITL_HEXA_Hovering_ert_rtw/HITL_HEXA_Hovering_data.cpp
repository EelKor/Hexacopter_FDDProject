//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: HITL_HEXA_Hovering_data.cpp
//
// Code generated for Simulink model 'HITL_HEXA_Hovering'.
//
// Model version                  : 5.30
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Jan  8 14:27:22 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "HITL_HEXA_Hovering.h"

// Block parameters (default storage)
P_HITL_HEXA_Hovering_T HITL_HEXA_Hovering_P = {
  // Mask Parameter: PIDController_D
  //  Referenced by: '<S111>/Derivative Gain'

  0.0,

  // Mask Parameter: PIDController1_D
  //  Referenced by: '<S163>/Derivative Gain'

  0.0025,

  // Mask Parameter: PIDController2_D
  //  Referenced by: '<S215>/Derivative Gain'

  0.0025,

  // Mask Parameter: PID_Altitude_D
  //  Referenced by: '<S526>/Derivative Gain'

  0.01,

  // Mask Parameter: PID_vz_D
  //  Referenced by: '<S578>/Derivative Gain'

  0.05,

  // Mask Parameter: PIDController_I
  //  Referenced by: '<S115>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController1_I
  //  Referenced by: '<S167>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController2_I
  //  Referenced by: '<S219>/Integral Gain'

  0.0,

  // Mask Parameter: PID_Altitude_I
  //  Referenced by: '<S530>/Integral Gain'

  0.01,

  // Mask Parameter: PID_vz_I
  //  Referenced by: '<S582>/Integral Gain'

  0.1,

  // Mask Parameter: PIDController_InitialConditionForFilter
  //  Referenced by: '<S113>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialConditionForFilter
  //  Referenced by: '<S165>/Filter'

  0.0,

  // Mask Parameter: PIDController2_InitialConditionForFilter
  //  Referenced by: '<S217>/Filter'

  0.0,

  // Mask Parameter: PID_Altitude_InitialConditionForFilter
  //  Referenced by: '<S528>/Filter'

  0.0,

  // Mask Parameter: PID_vz_InitialConditionForFilter
  //  Referenced by: '<S580>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditionForIntegrator
  //  Referenced by: '<S118>/Integrator'

  0.0,

  // Mask Parameter: PIDController1_InitialConditionForIntegrator
  //  Referenced by: '<S170>/Integrator'

  0.0,

  // Mask Parameter: PIDController2_InitialConditionForIntegrator
  //  Referenced by: '<S222>/Integrator'

  0.0,

  // Mask Parameter: PID_Altitude_InitialConditionForIntegrator
  //  Referenced by: '<S533>/Integrator'

  0.0,

  // Mask Parameter: PID_vz_InitialConditionForIntegrator
  //  Referenced by: '<S585>/Integrator'

  0.0,

  // Mask Parameter: PIDController_LowerSaturationLimit
  //  Referenced by:
  //    '<S125>/Saturation'
  //    '<S110>/DeadZone'

  -0.1,

  // Mask Parameter: PIDController1_LowerSaturationLimit
  //  Referenced by:
  //    '<S177>/Saturation'
  //    '<S162>/DeadZone'

  -0.2,

  // Mask Parameter: PIDController2_LowerSaturationLimit
  //  Referenced by:
  //    '<S229>/Saturation'
  //    '<S214>/DeadZone'

  -0.2,

  // Mask Parameter: PIDController1_LowerSaturationLimit_h
  //  Referenced by: '<S438>/Saturation'

  -4.0,

  // Mask Parameter: PIDController_LowerSaturationLimit_o
  //  Referenced by: '<S388>/Saturation'

  -0.3490658503988659,

  // Mask Parameter: PIDController5_LowerSaturationLimit
  //  Referenced by: '<S488>/Saturation'

  -0.87266462599716477,

  // Mask Parameter: PID_Altitude_LowerSaturationLimit
  //  Referenced by:
  //    '<S540>/Saturation'
  //    '<S525>/DeadZone'

  -2.0,

  // Mask Parameter: PID_vz_LowerSaturationLimit
  //  Referenced by:
  //    '<S592>/Saturation'
  //    '<S577>/DeadZone'

  0.0,

  // Mask Parameter: PIDController_N
  //  Referenced by: '<S121>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController1_N
  //  Referenced by: '<S173>/Filter Coefficient'

  50.0,

  // Mask Parameter: PIDController2_N
  //  Referenced by: '<S225>/Filter Coefficient'

  50.0,

  // Mask Parameter: PID_Altitude_N
  //  Referenced by: '<S536>/Filter Coefficient'

  10.0,

  // Mask Parameter: PID_vz_N
  //  Referenced by: '<S588>/Filter Coefficient'

  10.0,

  // Mask Parameter: PIDController_P
  //  Referenced by: '<S123>/Proportional Gain'

  0.2,

  // Mask Parameter: PIDController3_P
  //  Referenced by: '<S277>/Proportional Gain'

  4.0,

  // Mask Parameter: PIDController1_P
  //  Referenced by: '<S175>/Proportional Gain'

  0.035,

  // Mask Parameter: PIDController4_P
  //  Referenced by: '<S327>/Proportional Gain'

  4.0,

  // Mask Parameter: PIDController2_P
  //  Referenced by: '<S227>/Proportional Gain'

  0.035,

  // Mask Parameter: PIDController1_P_f
  //  Referenced by: '<S436>/Proportional Gain'

  0.6,

  // Mask Parameter: PIDController_P_b
  //  Referenced by: '<S386>/Proportional Gain'

  0.3,

  // Mask Parameter: PIDController5_P
  //  Referenced by: '<S486>/Proportional Gain'

  2.0,

  // Mask Parameter: PID_Altitude_P
  //  Referenced by: '<S538>/Proportional Gain'

  1.5,

  // Mask Parameter: PID_vz_P
  //  Referenced by: '<S590>/Proportional Gain'

  0.5,

  // Mask Parameter: PIDController_UpperSaturationLimit
  //  Referenced by:
  //    '<S125>/Saturation'
  //    '<S110>/DeadZone'

  0.1,

  // Mask Parameter: PIDController1_UpperSaturationLimit
  //  Referenced by:
  //    '<S177>/Saturation'
  //    '<S162>/DeadZone'

  0.2,

  // Mask Parameter: PIDController2_UpperSaturationLimit
  //  Referenced by:
  //    '<S229>/Saturation'
  //    '<S214>/DeadZone'

  0.2,

  // Mask Parameter: PIDController1_UpperSaturationLimit_e
  //  Referenced by: '<S438>/Saturation'

  4.0,

  // Mask Parameter: PIDController_UpperSaturationLimit_e
  //  Referenced by: '<S388>/Saturation'

  0.3490658503988659,

  // Mask Parameter: PIDController5_UpperSaturationLimit
  //  Referenced by: '<S488>/Saturation'

  0.87266462599716477,

  // Mask Parameter: PID_Altitude_UpperSaturationLimit
  //  Referenced by:
  //    '<S540>/Saturation'
  //    '<S525>/DeadZone'

  2.0,

  // Mask Parameter: PID_vz_UpperSaturationLimit
  //  Referenced by:
  //    '<S592>/Saturation'
  //    '<S577>/DeadZone'

  1.0,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S11>/Constant'

  1800.0,

  // Mask Parameter: CompareToConstant_const_c
  //  Referenced by: '<S12>/Constant'

  1400U,

  // Mask Parameter: CompareToConstant_const_d
  //  Referenced by: '<S52>/Constant'

  5U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S59>/Out1'

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
  //  Referenced by: '<S64>/Constant'

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
  //  Referenced by: '<S58>/Constant'

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
  //  Referenced by: '<S71>/Out1'

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
  //  Referenced by: '<S56>/Constant'

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
  //  Referenced by: '<S33>/Out1'

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
  //  Referenced by: '<S27>/Constant'

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

  // Computed Parameter: Out1_Y0_l
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

  // Computed Parameter: Out1_Y0_m
  //  Referenced by: '<S31>/Out1'

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

  // Computed Parameter: Constant_Value_ge
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

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S30>/Constant'

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
  //  Referenced by: '<S32>/Out1'

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
  //  Referenced by: '<S26>/Constant'

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
  //  Referenced by: '<S70>/Out1'

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
  //  Referenced by: '<S55>/Constant'

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
  //  Referenced by: '<S28>/Out1'

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
  //  Referenced by: '<S23>/Constant'

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
  //  Referenced by: '<S29>/Out1'

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
  //  Referenced by: '<S24>/Constant'

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
  //  Referenced by: '<S14>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S14>/Saturation'

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
  //  Referenced by: '<S15>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S15>/Saturation'

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
  //  Referenced by: '<S16>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S16>/Saturation'

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
  //  Referenced by: '<S17>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S17>/Saturation'

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
  //  Referenced by: '<S18>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S18>/Saturation'

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
  //  Referenced by: '<S13>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S13>/Saturation'

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

  // Computed Parameter: yaw_Out_Y0
  //  Referenced by: '<S50>/yaw_Out'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S48>/Delay'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S48>/Rate'

  0.01,

  // Expression: -1
  //  Referenced by: '<S48>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S48>/Gain'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S49>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S49>/Constant'

  0.0,

  // Computed Parameter: Out_Y0
  //  Referenced by: '<S46>/Out'

  0.0,

  // Expression: -1
  //  Referenced by: '<S44>/Gain'

  -1.0,

  // Computed Parameter: yaw_Out_Y0_f
  //  Referenced by: '<S47>/yaw_Out'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S39>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S44>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S44>/Switch'

  0.0,

  // Expression: 0.02
  //  Referenced by: '<S44>/Rate of descent'

  0.02,

  // Expression: -1
  //  Referenced by: '<S44>/Gain2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S44>/Gain1'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S45>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S45>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S51>/Constant'

  0.0,

  // Expression: 6
  //  Referenced by: '<S41>/Constant'

  6.0,

  // Computed Parameter: yaw_Out_Y0_p
  //  Referenced by: '<S43>/yaw_Out'

  0.0,

  // Expression: 1
  //  Referenced by: '<S42>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S42>/Constant'

  0.0,

  // Expression: -1
  //  Referenced by: '<S37>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S69>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S68>/Read Parameter'

  -1.0,

  // Computed Parameter: tau_Yaw_Y0
  //  Referenced by: '<S72>/tau_Yaw'

  0.0,

  // Computed Parameter: tau_Pitch_Y0
  //  Referenced by: '<S72>/tau_Pitch'

  0.0,

  // Computed Parameter: tau_Roll_Y0
  //  Referenced by: '<S72>/tau_Roll'

  0.0,

  // Expression: 0
  //  Referenced by: '<S108>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S160>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S212>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S108>/Clamping_zero'

  0.0,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S118>/Integrator'

  0.004,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S113>/Filter'

  0.004,

  // Expression: 40*pi/180
  //  Referenced by: '<S72>/Rate Limiter2'

  0.69813170079773179,

  // Expression: -40*pi/180
  //  Referenced by: '<S72>/Rate Limiter2'

  -0.69813170079773179,

  // Expression: 0
  //  Referenced by: '<S72>/Rate Limiter2'

  0.0,

  // Expression: 20*pi/180
  //  Referenced by: '<S72>/Saturation1'

  0.3490658503988659,

  // Expression: -20*pi/180
  //  Referenced by: '<S72>/Saturation1'

  -0.3490658503988659,

  // Expression: 0
  //  Referenced by: '<S160>/Clamping_zero'

  0.0,

  // Computed Parameter: Integrator_gainval_i
  //  Referenced by: '<S170>/Integrator'

  0.004,

  // Computed Parameter: Filter_gainval_p
  //  Referenced by: '<S165>/Filter'

  0.004,

  // Expression: 40*pi/180
  //  Referenced by: '<S72>/Rate Limiter1'

  0.69813170079773179,

  // Expression: -40*pi/180
  //  Referenced by: '<S72>/Rate Limiter1'

  -0.69813170079773179,

  // Expression: 0
  //  Referenced by: '<S72>/Rate Limiter1'

  0.0,

  // Expression: 20*pi/180
  //  Referenced by: '<S72>/Saturation'

  0.3490658503988659,

  // Expression: -20*pi/180
  //  Referenced by: '<S72>/Saturation'

  -0.3490658503988659,

  // Expression: 0
  //  Referenced by: '<S212>/Clamping_zero'

  0.0,

  // Computed Parameter: Integrator_gainval_p
  //  Referenced by: '<S222>/Integrator'

  0.004,

  // Computed Parameter: Filter_gainval_k
  //  Referenced by: '<S217>/Filter'

  0.004,

  // Expression: 0
  //  Referenced by: '<S339>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S341>/Switch1'

  0.0,

  // Computed Parameter: des_pitch_Y0
  //  Referenced by: '<S75>/des_pitch'

  0.0,

  // Computed Parameter: des_roll_Y0
  //  Referenced by: '<S75>/des_roll'

  0.0,

  // Computed Parameter: des_yawrate_Y0
  //  Referenced by: '<S75>/des_yawrate'

  0.0,

  // Computed Parameter: tau_Thrust_Y0
  //  Referenced by: '<S75>/tau_Thrust'

  0.0,

  // Expression: 0
  //  Referenced by: '<S523>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S575>/Constant1'

  0.0,

  // Expression: -1
  //  Referenced by: '<S340>/Gain'

  -1.0,

  // Expression: 2*pi
  //  Referenced by: '<S341>/Constant'

  6.2831853071795862,

  // Expression: pi
  //  Referenced by: '<S341>/Switch'

  3.1415926535897931,

  // Expression: -1
  //  Referenced by: '<S75>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S339>/Gain1'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S523>/Clamping_zero'

  0.0,

  // Computed Parameter: Filter_gainval_i
  //  Referenced by: '<S528>/Filter'

  0.004,

  // Computed Parameter: Integrator_gainval_p4
  //  Referenced by: '<S533>/Integrator'

  0.004,

  // Expression: 0
  //  Referenced by: '<S575>/Clamping_zero'

  0.0,

  // Computed Parameter: Filter_gainval_d
  //  Referenced by: '<S580>/Filter'

  0.004,

  // Computed Parameter: Integrator_gainval_ik
  //  Referenced by: '<S585>/Integrator'

  0.004,

  // Expression: [1 0 0 0]
  //  Referenced by: '<S76>/Constant'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<S606>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S607>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S76>/Switch'

  0.0,

  // Expression: 1500
  //  Referenced by: '<S74>/Constant2'

  1500.0,

  // Expression: 1/400
  //  Referenced by: '<S74>/Gain2'

  0.0025,

  // Expression: 1
  //  Referenced by: '<S74>/Saturation2'

  1.0,

  // Expression: -1
  //  Referenced by: '<S74>/Saturation2'

  -1.0,

  // Expression: -20*pi/180
  //  Referenced by: '<S4>/Gain1'

  -0.3490658503988659,

  // Expression: 1500
  //  Referenced by: '<S74>/Constant1'

  1500.0,

  // Expression: 1/400
  //  Referenced by: '<S74>/Gain1'

  0.0025,

  // Expression: 1
  //  Referenced by: '<S74>/Saturation1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S74>/Saturation1'

  -1.0,

  // Expression: 20*pi/180
  //  Referenced by: '<S4>/Gain2'

  0.3490658503988659,

  // Expression: 1100
  //  Referenced by: '<S74>/Constant'

  1100.0,

  // Expression: 1/800
  //  Referenced by: '<S74>/Gain'

  0.00125,

  // Expression: 0.90
  //  Referenced by: '<S74>/Saturation'

  0.9,

  // Expression: 0
  //  Referenced by: '<S74>/Saturation'

  0.0,

  // Expression: 1500
  //  Referenced by: '<S74>/Constant3'

  1500.0,

  // Expression: 1/400
  //  Referenced by: '<S74>/Gain3'

  0.0025,

  // Expression: 1
  //  Referenced by: '<S74>/Saturation3'

  1.0,

  // Expression: -1
  //  Referenced by: '<S74>/Saturation3'

  -1.0,

  // Expression: 50*pi/180
  //  Referenced by: '<S4>/Gain4'

  0.87266462599716477,

  // Expression: -1
  //  Referenced by: '<S4>/Gain'

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

  // Expression: 6
  //  Referenced by: '<S10>/Constant17'

  6.0,

  // Computed Parameter: Constant7_Value
  //  Referenced by: '<S62>/Constant7'

  (0ULL),

  // Computed Parameter: Constant1_Value_d
  //  Referenced by: '<S69>/Constant1'

  { 0.0F, 0.0F },

  // Computed Parameter: Constant_Value_f2
  //  Referenced by: '<S69>/Constant'

  0.0F,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: '<S68>/Gain'

  -1.0F,

  // Computed Parameter: Constant1_Value_k4
  //  Referenced by: '<S68>/Constant1'

  { 0.0F, 0.0F },

  // Computed Parameter: Constant_Value_l4
  //  Referenced by: '<S68>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_fh
  //  Referenced by: '<S62>/Constant'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant1_Value_hv
  //  Referenced by: '<S62>/Constant1'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant2_Value_f
  //  Referenced by: '<S62>/Constant2'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant3_Value_a
  //  Referenced by: '<S62>/Constant3'

  0.0F,

  // Computed Parameter: Constant4_Value_g
  //  Referenced by: '<S62>/Constant4'

  0.0F,

  // Computed Parameter: Constant5_Value_jn
  //  Referenced by: '<S60>/Constant5'

  true,

  // Computed Parameter: Constant5_Value_k
  //  Referenced by: '<S61>/Constant5'

  true,

  // Computed Parameter: Constant1_Value_dl
  //  Referenced by: '<S63>/Constant1'

  true,

  // Computed Parameter: Constant5_Value_h
  //  Referenced by: '<S63>/Constant5'

  true,

  // Computed Parameter: Constant5_Value_l
  //  Referenced by: '<S62>/Constant5'

  false,

  // Computed Parameter: Constant_Value_gep
  //  Referenced by: '<S108>/Constant'

  1,

  // Computed Parameter: Constant2_Value_i
  //  Referenced by: '<S108>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_h
  //  Referenced by: '<S108>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_f
  //  Referenced by: '<S108>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_a1
  //  Referenced by: '<S160>/Constant'

  1,

  // Computed Parameter: Constant2_Value_l
  //  Referenced by: '<S160>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_j
  //  Referenced by: '<S160>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_a
  //  Referenced by: '<S160>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_jj
  //  Referenced by: '<S212>/Constant'

  1,

  // Computed Parameter: Constant2_Value_o
  //  Referenced by: '<S212>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_l
  //  Referenced by: '<S212>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_n
  //  Referenced by: '<S212>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_n1
  //  Referenced by: '<S523>/Constant'

  1,

  // Computed Parameter: Constant2_Value_gq
  //  Referenced by: '<S523>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_i
  //  Referenced by: '<S523>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_h
  //  Referenced by: '<S523>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_gf
  //  Referenced by: '<S575>/Constant'

  1,

  // Computed Parameter: Constant2_Value_ga
  //  Referenced by: '<S575>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_b
  //  Referenced by: '<S575>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_fv
  //  Referenced by: '<S575>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_fm
  //  Referenced by: '<S54>/Constant'

  0U,

  // Computed Parameter: Constant6_Value
  //  Referenced by: '<S62>/Constant6'

  255U
};

//
// File trailer for generated code.
//
// [EOF]
//
