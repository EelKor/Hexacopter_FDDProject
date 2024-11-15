//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: SITL_HEXA_MISSION.cpp
//
// Code generated for Simulink model 'SITL_HEXA_MISSION'.
//
// Model version                  : 5.6
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Sun Oct 20 19:46:11 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "SITL_HEXA_MISSION.h"
#include "rtwtypes.h"
#include "Navigation.h"
#include "mc_pos_controller.h"
#include "rt_sys_SITL_HEXA_MISSION_0.h"
#include <math.h>
#include "mc_att_controller.h"
#include "mc_rate_controller.h"
#include "actuatorOutputs.h"
#include "rt_sys_SITL_HEXA_MISSION_2.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"
#include "SITL_HEXA_MISSION_private.h"

// Block signals (default storage)
B_SITL_HEXA_MISSION_T SITL_HEXA_MISSION_B;

// Block states (default storage)
DW_SITL_HEXA_MISSION_T SITL_HEXA_MISSION_DW;

// Real-time model
RT_MODEL_SITL_HEXA_MISSION_T SITL_HEXA_MISSION_M_ = RT_MODEL_SITL_HEXA_MISSION_T
  ();
RT_MODEL_SITL_HEXA_MISSION_T *const SITL_HEXA_MISSION_M = &SITL_HEXA_MISSION_M_;

// Forward declaration for local functions
static real_T SITL_HEXA_MISSION_rt_atan2d_snf_i(real_T u0, real_T u1);
static real_T SITL_HEXA_MISSION_rt_atan2d_snf_i(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      SITL_HEXA_MISSION_B.i_p = 1;
    } else {
      SITL_HEXA_MISSION_B.i_p = -1;
    }

    if (u1 > 0.0) {
      SITL_HEXA_MISSION_B.i1_cv = 1;
    } else {
      SITL_HEXA_MISSION_B.i1_cv = -1;
    }

    y = atan2(static_cast<real_T>(SITL_HEXA_MISSION_B.i_p), static_cast<real_T>
              (SITL_HEXA_MISSION_B.i1_cv));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// Model step function
void SITL_HEXA_MISSION_step(void)
{
  // MATLABSystem: '<S605>/SourceBlock'
  SITL_HEXA_MISSION_B.b_varargout_1 = uORB_read_step
    (SITL_HEXA_MISSION_DW.obj_m.orbMetadataObj,
     &SITL_HEXA_MISSION_DW.obj_m.eventStructObj, &SITL_HEXA_MISSION_B.r_mb,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S605>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S609>/Enable'

  // Start for MATLABSystem: '<S605>/SourceBlock'
  if (SITL_HEXA_MISSION_B.b_varargout_1) {
    // SignalConversion generated from: '<S609>/In1'
    SITL_HEXA_MISSION_B.In1_c = SITL_HEXA_MISSION_B.r_mb;
  }

  // End of Outputs for SubSystem: '<S605>/Enabled Subsystem'

  // DataTypeConversion: '<S4>/Data Type Conversion1'
  SITL_HEXA_MISSION_B.DataTypeConversion1[0] = SITL_HEXA_MISSION_B.In1_c.x;
  SITL_HEXA_MISSION_B.DataTypeConversion1[1] = SITL_HEXA_MISSION_B.In1_c.y;
  SITL_HEXA_MISSION_B.DataTypeConversion1[2] = SITL_HEXA_MISSION_B.In1_c.z;
  SITL_HEXA_MISSION_B.DataTypeConversion1[3] = SITL_HEXA_MISSION_B.In1_c.vx;
  SITL_HEXA_MISSION_B.DataTypeConversion1[4] = SITL_HEXA_MISSION_B.In1_c.vy;
  SITL_HEXA_MISSION_B.DataTypeConversion1[5] = SITL_HEXA_MISSION_B.In1_c.vz;
  SITL_HEXA_MISSION_B.DataTypeConversion1[6] = SITL_HEXA_MISSION_B.In1_c.heading;

  // Outputs for Atomic SubSystem: '<Root>/Navigation'
  SITL_HEXA_MISSION_Navigation();

  // End of Outputs for SubSystem: '<Root>/Navigation'

  // MATLABSystem: '<S604>/SourceBlock'
  SITL_HEXA_MISSION_B.b_varargout_1 = uORB_read_step
    (SITL_HEXA_MISSION_DW.obj_gv.orbMetadataObj,
     &SITL_HEXA_MISSION_DW.obj_gv.eventStructObj, &SITL_HEXA_MISSION_B.r1_c,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S604>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S608>/Enable'

  // Start for MATLABSystem: '<S604>/SourceBlock'
  if (SITL_HEXA_MISSION_B.b_varargout_1) {
    // SignalConversion generated from: '<S608>/In1'
    SITL_HEXA_MISSION_B.In1_m = SITL_HEXA_MISSION_B.r1_c;
  }

  // End of Outputs for SubSystem: '<S604>/Enabled Subsystem'

  // DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
  //   Switch: '<S9>/Switch'

  SITL_HEXA_MISSION_B.rtb_Switch_j_idx_0 = SITL_HEXA_MISSION_B.In1_m.q[0];
  SITL_HEXA_MISSION_B.rtb_Switch_j_idx_1 = SITL_HEXA_MISSION_B.In1_m.q[1];
  SITL_HEXA_MISSION_B.rtb_Switch_j_idx_2 = SITL_HEXA_MISSION_B.In1_m.q[2];
  SITL_HEXA_MISSION_B.rtb_Switch_j_idx_3 = SITL_HEXA_MISSION_B.In1_m.q[3];

  // Switch: '<S9>/Switch' incorporates:
  //   Constant: '<S9>/Constant'
  //   DataTypeConversion: '<S4>/Data Type Conversion'
  //   Product: '<S20>/Product'
  //   Product: '<S20>/Product1'
  //   Product: '<S20>/Product2'
  //   Product: '<S20>/Product3'
  //   Sum: '<S20>/Sum'

  if (!(((static_cast<real_T>(SITL_HEXA_MISSION_B.In1_m.q[0]) *
          SITL_HEXA_MISSION_B.In1_m.q[0] + static_cast<real_T>
          (SITL_HEXA_MISSION_B.In1_m.q[1]) * SITL_HEXA_MISSION_B.In1_m.q[1]) +
         static_cast<real_T>(SITL_HEXA_MISSION_B.In1_m.q[2]) *
         SITL_HEXA_MISSION_B.In1_m.q[2]) + static_cast<real_T>
        (SITL_HEXA_MISSION_B.In1_m.q[3]) * SITL_HEXA_MISSION_B.In1_m.q[3] >
        SITL_HEXA_MISSION_P.Switch_Threshold_l)) {
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_0 =
      SITL_HEXA_MISSION_P.Constant_Value_im[0];
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_1 =
      SITL_HEXA_MISSION_P.Constant_Value_im[1];
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_2 =
      SITL_HEXA_MISSION_P.Constant_Value_im[2];
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_3 =
      SITL_HEXA_MISSION_P.Constant_Value_im[3];
  }

  // End of Switch: '<S9>/Switch'

  // MATLABSystem: '<S602>/SourceBlock'
  SITL_HEXA_MISSION_B.b_varargout_1 = uORB_read_step
    (SITL_HEXA_MISSION_DW.obj_p.orbMetadataObj,
     &SITL_HEXA_MISSION_DW.obj_p.eventStructObj, &SITL_HEXA_MISSION_B.r2_k,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S602>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S606>/Enable'

  // Start for MATLABSystem: '<S602>/SourceBlock'
  if (SITL_HEXA_MISSION_B.b_varargout_1) {
    // SignalConversion generated from: '<S606>/In1'
    SITL_HEXA_MISSION_B.In1_l = SITL_HEXA_MISSION_B.r2_k;
  }

  // End of Outputs for SubSystem: '<S602>/Enabled Subsystem'

  // DataTypeConversion: '<S4>/Data Type Conversion2'
  SITL_HEXA_MISSION_B.DataTypeConversion2[0] = SITL_HEXA_MISSION_B.In1_l.xyz[0];
  SITL_HEXA_MISSION_B.DataTypeConversion2[1] = SITL_HEXA_MISSION_B.In1_l.xyz[1];
  SITL_HEXA_MISSION_B.DataTypeConversion2[2] = SITL_HEXA_MISSION_B.In1_l.xyz[2];

  // Gain: '<S5>/Gain'
  SITL_HEXA_MISSION_B.desiredZ = SITL_HEXA_MISSION_P.Gain_Gain_c *
    SITL_HEXA_MISSION_B.Merge[2];

  // MATLABSystem: '<S603>/SourceBlock'
  SITL_HEXA_MISSION_B.b_varargout_1 = uORB_read_step
    (SITL_HEXA_MISSION_DW.obj_d0.orbMetadataObj,
     &SITL_HEXA_MISSION_DW.obj_d0.eventStructObj, &SITL_HEXA_MISSION_B.r3, false,
     1.0);

  // Outputs for Enabled SubSystem: '<S603>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S607>/Enable'

  // Start for MATLABSystem: '<S603>/SourceBlock'
  if (SITL_HEXA_MISSION_B.b_varargout_1) {
    // SignalConversion generated from: '<S607>/In1'
    SITL_HEXA_MISSION_B.In1_b = SITL_HEXA_MISSION_B.r3;
  }

  // End of Outputs for SubSystem: '<S603>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S5>/mc_pos_controller'
  SITL_HEXA_MISSION_mc_pos_controller();

  // End of Outputs for SubSystem: '<S5>/mc_pos_controller'
  SITL_HEXA_MISSION_PX4Timestamp(&SITL_HEXA_MISSION_B.PX4Timestamp_pn);

  // Sqrt: '<S27>/sqrt' incorporates:
  //   Product: '<S28>/Product'
  //   Product: '<S28>/Product1'
  //   Product: '<S28>/Product2'
  //   Product: '<S28>/Product3'
  //   Sum: '<S28>/Sum'

  SITL_HEXA_MISSION_B.Sum_l = sqrt(((SITL_HEXA_MISSION_B.rtb_Switch_j_idx_0 *
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_0 +
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_1 *
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_1) +
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_2 *
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_2) +
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_3 *
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_3);

  // Product: '<S22>/Product'
  SITL_HEXA_MISSION_B.rtb_Switch_j_idx_0 /= SITL_HEXA_MISSION_B.Sum_l;

  // Product: '<S22>/Product1'
  SITL_HEXA_MISSION_B.rtb_Switch_j_idx_1 /= SITL_HEXA_MISSION_B.Sum_l;

  // Product: '<S22>/Product2'
  SITL_HEXA_MISSION_B.rtb_Switch_j_idx_2 /= SITL_HEXA_MISSION_B.Sum_l;

  // Product: '<S22>/Product3'
  SITL_HEXA_MISSION_B.Sum_l = SITL_HEXA_MISSION_B.rtb_Switch_j_idx_3 /
    SITL_HEXA_MISSION_B.Sum_l;

  // Fcn: '<S10>/fcn2' incorporates:
  //   Fcn: '<S10>/fcn5'

  SITL_HEXA_MISSION_B.rtb_Switch_j_idx_3 =
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_0 *
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_0;
  SITL_HEXA_MISSION_B.VectorConcatenate_tmp =
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_1 *
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_1;
  SITL_HEXA_MISSION_B.VectorConcatenate_tmp_c =
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_2 *
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_2;
  SITL_HEXA_MISSION_B.VectorConcatenate_tmp_b = SITL_HEXA_MISSION_B.Sum_l *
    SITL_HEXA_MISSION_B.Sum_l;

  // Trigonometry: '<S21>/Trigonometric Function1' incorporates:
  //   Fcn: '<S10>/fcn1'
  //   Fcn: '<S10>/fcn2'

  SITL_HEXA_MISSION_B.VectorConcatenate[0] = SITL_HEXA_MISSION_rt_atan2d_snf_i
    ((SITL_HEXA_MISSION_B.rtb_Switch_j_idx_1 *
      SITL_HEXA_MISSION_B.rtb_Switch_j_idx_2 +
      SITL_HEXA_MISSION_B.rtb_Switch_j_idx_0 * SITL_HEXA_MISSION_B.Sum_l) * 2.0,
     ((SITL_HEXA_MISSION_B.rtb_Switch_j_idx_3 +
       SITL_HEXA_MISSION_B.VectorConcatenate_tmp) -
      SITL_HEXA_MISSION_B.VectorConcatenate_tmp_c) -
     SITL_HEXA_MISSION_B.VectorConcatenate_tmp_b);

  // Fcn: '<S10>/fcn3'
  SITL_HEXA_MISSION_B.fcn3 = (SITL_HEXA_MISSION_B.rtb_Switch_j_idx_1 *
    SITL_HEXA_MISSION_B.Sum_l - SITL_HEXA_MISSION_B.rtb_Switch_j_idx_0 *
    SITL_HEXA_MISSION_B.rtb_Switch_j_idx_2) * -2.0;

  // If: '<S23>/If' incorporates:
  //   Constant: '<S24>/Constant'
  //   Constant: '<S25>/Constant'
  //   Trigonometry: '<S21>/trigFcn'

  if (SITL_HEXA_MISSION_B.fcn3 > 1.0) {
    SITL_HEXA_MISSION_B.fcn3 = SITL_HEXA_MISSION_P.Constant_Value_be;
  } else if (SITL_HEXA_MISSION_B.fcn3 < -1.0) {
    SITL_HEXA_MISSION_B.fcn3 = SITL_HEXA_MISSION_P.Constant_Value_m;
  }

  if (SITL_HEXA_MISSION_B.fcn3 > 1.0) {
    SITL_HEXA_MISSION_B.fcn3 = 1.0;
  } else if (SITL_HEXA_MISSION_B.fcn3 < -1.0) {
    SITL_HEXA_MISSION_B.fcn3 = -1.0;
  }

  // End of If: '<S23>/If'

  // Trigonometry: '<S21>/trigFcn'
  SITL_HEXA_MISSION_B.VectorConcatenate[1] = asin(SITL_HEXA_MISSION_B.fcn3);

  // Trigonometry: '<S21>/Trigonometric Function3' incorporates:
  //   Fcn: '<S10>/fcn4'
  //   Fcn: '<S10>/fcn5'

  SITL_HEXA_MISSION_B.VectorConcatenate[2] = SITL_HEXA_MISSION_rt_atan2d_snf_i
    ((SITL_HEXA_MISSION_B.rtb_Switch_j_idx_2 * SITL_HEXA_MISSION_B.Sum_l +
      SITL_HEXA_MISSION_B.rtb_Switch_j_idx_0 *
      SITL_HEXA_MISSION_B.rtb_Switch_j_idx_1) * 2.0,
     ((SITL_HEXA_MISSION_B.rtb_Switch_j_idx_3 -
       SITL_HEXA_MISSION_B.VectorConcatenate_tmp) -
      SITL_HEXA_MISSION_B.VectorConcatenate_tmp_c) +
     SITL_HEXA_MISSION_B.VectorConcatenate_tmp_b);

  // Outputs for Enabled SubSystem: '<S5>/mc_att_controller'
  SITL_HEXA_MISSION_mc_att_controller();

  // End of Outputs for SubSystem: '<S5>/mc_att_controller'

  // BusAssignment: '<S8>/Bus Assignment' incorporates:
  //   Constant: '<S18>/Constant'

  SITL_HEXA_MISSION_B.BusAssignment_h4 = SITL_HEXA_MISSION_P.Constant_Value_j;

  // BusAssignment: '<S8>/Bus Assignment' incorporates:
  //   Constant: '<S8>/thrust_sp_bX'
  //   Constant: '<S8>/thrust_sp_bY'
  //   DataTypeConversion: '<S8>/Data Type Conversion'
  //   DataTypeConversion: '<S8>/Data Type Conversion1'
  //   DataTypeConversion: '<S8>/Data Type Conversion2'
  //   DataTypeConversion: '<S8>/Data Type Conversion3'
  //   MATLABSystem: '<S8>/PX4 Timestamp'

  SITL_HEXA_MISSION_B.BusAssignment_h4.timestamp =
    SITL_HEXA_MISSION_B.PX4Timestamp_pn.PX4Timestamp;
  SITL_HEXA_MISSION_B.BusAssignment_h4.roll = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.Saturation_e);
  SITL_HEXA_MISSION_B.BusAssignment_h4.pitch = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.ProportionalGain);
  SITL_HEXA_MISSION_B.BusAssignment_h4.yaw = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.ProportionalGain_a);
  SITL_HEXA_MISSION_B.BusAssignment_h4.thrust_body[0] = static_cast<real32_T>
    (SITL_HEXA_MISSION_P.thrust_sp_bX_Value_m);
  SITL_HEXA_MISSION_B.BusAssignment_h4.thrust_body[1] = static_cast<real32_T>
    (SITL_HEXA_MISSION_P.thrust_sp_bY_Value_m);
  SITL_HEXA_MISSION_B.BusAssignment_h4.thrust_body[2] = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.Saturation_d);

  // MATLABSystem: '<S19>/SinkBlock' incorporates:
  //   BusAssignment: '<S8>/Bus Assignment'

  uORB_write_step(SITL_HEXA_MISSION_DW.obj_dz.orbMetadataObj,
                  &SITL_HEXA_MISSION_DW.obj_dz.orbAdvertiseObj,
                  &SITL_HEXA_MISSION_B.BusAssignment_h4);

  // Outputs for Enabled SubSystem: '<S5>/mc_rate_controller'
  SITL_HEXA_MISSION_mc_rate_controller();

  // End of Outputs for SubSystem: '<S5>/mc_rate_controller'

  // Outputs for Atomic SubSystem: '<Root>/actuatorOutputs'
  SITL_HEXA_MISSION_actuatorOutputs();

  // End of Outputs for SubSystem: '<Root>/actuatorOutputs'
  SITL_HEXA_MISSION_PX4Timestamp(&SITL_HEXA_MISSION_B.PX4Timestamp_p);

  // BusAssignment: '<S7>/Bus Assignment' incorporates:
  //   Constant: '<S16>/Constant'

  SITL_HEXA_MISSION_B.BusAssignment_a = SITL_HEXA_MISSION_P.Constant_Value_l;

  // BusAssignment: '<S7>/Bus Assignment' incorporates:
  //   Constant: '<S7>/Constant'
  //   DataTypeConversion: '<S7>/Data Type Conversion'
  //   DataTypeConversion: '<S7>/Data Type Conversion1'
  //   DataTypeConversion: '<S7>/Data Type Conversion2'
  //   DataTypeConversion: '<S7>/Data Type Conversion3'
  //   DataTypeConversion: '<S7>/Data Type Conversion4'
  //   DataTypeConversion: '<S7>/Data Type Conversion5'
  //   DataTypeConversion: '<S7>/Data Type Conversion6'
  //   DataTypeConversion: '<S7>/Data Type Conversion7'
  //   Gain: '<S5>/Gain1'
  //   Gain: '<S5>/Gain2'
  //   MATLABSystem: '<S7>/PX4 Timestamp'

  SITL_HEXA_MISSION_B.BusAssignment_a.timestamp =
    SITL_HEXA_MISSION_B.PX4Timestamp_p.PX4Timestamp;
  SITL_HEXA_MISSION_B.BusAssignment_a.x = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.Merge[0]);
  SITL_HEXA_MISSION_B.BusAssignment_a.y = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.Merge[1]);
  SITL_HEXA_MISSION_B.BusAssignment_a.z = static_cast<real32_T>
    (SITL_HEXA_MISSION_P.Gain1_Gain_j * SITL_HEXA_MISSION_B.desiredZ);
  SITL_HEXA_MISSION_B.BusAssignment_a.vx = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.Saturation_bi[0]);
  SITL_HEXA_MISSION_B.BusAssignment_a.vy = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.Saturation_bi[1]);
  SITL_HEXA_MISSION_B.BusAssignment_a.vz = static_cast<real32_T>
    (SITL_HEXA_MISSION_P.Gain2_Gain_n * SITL_HEXA_MISSION_B.Saturation_o);
  SITL_HEXA_MISSION_B.BusAssignment_a.yaw = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.Merge[3]);
  SITL_HEXA_MISSION_B.BusAssignment_a.thrust[0] = static_cast<real32_T>
    (SITL_HEXA_MISSION_P.Constant_Value_go);
  SITL_HEXA_MISSION_B.BusAssignment_a.thrust[1] = static_cast<real32_T>
    (SITL_HEXA_MISSION_P.Constant_Value_go);
  SITL_HEXA_MISSION_B.BusAssignment_a.thrust[2] = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.Saturation_d);
  SITL_HEXA_MISSION_SinkBlock(&SITL_HEXA_MISSION_B.BusAssignment_a,
    &SITL_HEXA_MISSION_DW.SinkBlock_m);
  SITL_HEXA_MISSION_PX4Timestamp(&SITL_HEXA_MISSION_B.PX4Timestamp);

  // BusAssignment: '<S6>/Bus Assignment' incorporates:
  //   Constant: '<S14>/Constant'

  SITL_HEXA_MISSION_B.BusAssignment_h = SITL_HEXA_MISSION_P.Constant_Value_b;

  // BusAssignment: '<S6>/Bus Assignment' incorporates:
  //   Constant: '<S6>/thrust_sp_bX'
  //   Constant: '<S6>/thrust_sp_bY'
  //   DataTypeConversion: '<S6>/Data Type Conversion'
  //   DataTypeConversion: '<S6>/Data Type Conversion1'
  //   DataTypeConversion: '<S6>/Data Type Conversion2'
  //   DataTypeConversion: '<S6>/Data Type Conversion3'
  //   MATLABSystem: '<S6>/PX4 Timestamp'

  SITL_HEXA_MISSION_B.BusAssignment_h.timestamp =
    SITL_HEXA_MISSION_B.PX4Timestamp.PX4Timestamp;
  SITL_HEXA_MISSION_B.BusAssignment_h.roll_body = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.Saturation_n[1]);
  SITL_HEXA_MISSION_B.BusAssignment_h.pitch_body = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.Gain1);
  SITL_HEXA_MISSION_B.BusAssignment_h.yaw_body = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.Merge[3]);
  SITL_HEXA_MISSION_B.BusAssignment_h.thrust_body[0] = static_cast<real32_T>
    (SITL_HEXA_MISSION_P.thrust_sp_bX_Value);
  SITL_HEXA_MISSION_B.BusAssignment_h.thrust_body[1] = static_cast<real32_T>
    (SITL_HEXA_MISSION_P.thrust_sp_bY_Value);
  SITL_HEXA_MISSION_B.BusAssignment_h.thrust_body[2] = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.Saturation_d);

  // MATLABSystem: '<S15>/SinkBlock' incorporates:
  //   BusAssignment: '<S6>/Bus Assignment'

  uORB_write_step(SITL_HEXA_MISSION_DW.obj_mg.orbMetadataObj,
                  &SITL_HEXA_MISSION_DW.obj_mg.orbAdvertiseObj,
                  &SITL_HEXA_MISSION_B.BusAssignment_h);
}

// Model initialize function
void SITL_HEXA_MISSION_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  SITL_HEXA_MISSION_P.Constant1_Value_d[0] = rtNaNF;
  SITL_HEXA_MISSION_P.Constant1_Value_d[1] = rtNaNF;
  SITL_HEXA_MISSION_P.Constant_Value_f2 = rtNaNF;
  SITL_HEXA_MISSION_P.Constant1_Value_k4[0] = rtNaNF;
  SITL_HEXA_MISSION_P.Constant1_Value_k4[1] = rtNaNF;
  SITL_HEXA_MISSION_P.Constant_Value_l4 = rtNaNF;
  SITL_HEXA_MISSION_P.Constant_Value_fh[0] = rtNaNF;
  SITL_HEXA_MISSION_P.Constant_Value_fh[1] = rtNaNF;
  SITL_HEXA_MISSION_P.Constant_Value_fh[2] = rtNaNF;
  SITL_HEXA_MISSION_P.Constant1_Value_h[0] = rtNaNF;
  SITL_HEXA_MISSION_P.Constant1_Value_h[1] = rtNaNF;
  SITL_HEXA_MISSION_P.Constant1_Value_h[2] = rtNaNF;
  SITL_HEXA_MISSION_P.Constant2_Value[0] = rtNaNF;
  SITL_HEXA_MISSION_P.Constant2_Value[1] = rtNaNF;
  SITL_HEXA_MISSION_P.Constant2_Value[2] = rtNaNF;
  SITL_HEXA_MISSION_P.Constant3_Value = rtNaNF;
  SITL_HEXA_MISSION_P.Constant4_Value = rtNaNF;

  // SystemInitialize for Enabled SubSystem: '<S605>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S609>/In1' incorporates:
  //   Outport: '<S609>/Out1'

  SITL_HEXA_MISSION_B.In1_c = SITL_HEXA_MISSION_P.Out1_Y0_p;

  // End of SystemInitialize for SubSystem: '<S605>/Enabled Subsystem'

  // SystemInitialize for Atomic SubSystem: '<Root>/Navigation'
  SITL_HEXA_MISSION_Navigation_Init();

  // End of SystemInitialize for SubSystem: '<Root>/Navigation'

  // SystemInitialize for Enabled SubSystem: '<S604>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S608>/In1' incorporates:
  //   Outport: '<S608>/Out1'

  SITL_HEXA_MISSION_B.In1_m = SITL_HEXA_MISSION_P.Out1_Y0_k;

  // End of SystemInitialize for SubSystem: '<S604>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S602>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S606>/In1' incorporates:
  //   Outport: '<S606>/Out1'

  SITL_HEXA_MISSION_B.In1_l = SITL_HEXA_MISSION_P.Out1_Y0_e;

  // End of SystemInitialize for SubSystem: '<S602>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S603>/Enabled Subsystem'
  // SystemInitialize for Outport: '<S607>/Out1' incorporates:
  //   SignalConversion generated from: '<S607>/In1'

  SITL_HEXA_MISSION_B.In1_b = SITL_HEXA_MISSION_P.Out1_Y0_d;

  // End of SystemInitialize for SubSystem: '<S603>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S5>/mc_pos_controller'
  SITL_HEXA_MISSION_mc_pos_controller_Init();

  // End of SystemInitialize for SubSystem: '<S5>/mc_pos_controller'

  // SystemInitialize for Enabled SubSystem: '<S5>/mc_att_controller'
  SITL_HEXA_MISSION_mc_att_controller_Init();

  // End of SystemInitialize for SubSystem: '<S5>/mc_att_controller'

  // SystemInitialize for Enabled SubSystem: '<S5>/mc_rate_controller'
  SITL_HEXA_MISSION_mc_rate_controller_Init();

  // End of SystemInitialize for SubSystem: '<S5>/mc_rate_controller'

  // SystemInitialize for Atomic SubSystem: '<Root>/actuatorOutputs'
  SITL_HEXA_MISSION_actuatorOutputs_Init();

  // End of SystemInitialize for SubSystem: '<Root>/actuatorOutputs'

  // Start for MATLABSystem: '<S605>/SourceBlock'
  SITL_HEXA_MISSION_DW.obj_m.matlabCodegenIsDeleted = false;
  SITL_HEXA_MISSION_DW.obj_m.isInitialized = 1;
  SITL_HEXA_MISSION_DW.obj_m.orbMetadataObj = ORB_ID(vehicle_local_position);
  uORB_read_initialize(SITL_HEXA_MISSION_DW.obj_m.orbMetadataObj,
                       &SITL_HEXA_MISSION_DW.obj_m.eventStructObj);
  SITL_HEXA_MISSION_DW.obj_m.isSetupComplete = true;

  // Start for MATLABSystem: '<S604>/SourceBlock'
  SITL_HEXA_MISSION_DW.obj_gv.matlabCodegenIsDeleted = false;
  SITL_HEXA_MISSION_DW.obj_gv.isInitialized = 1;
  SITL_HEXA_MISSION_DW.obj_gv.orbMetadataObj = ORB_ID(vehicle_attitude);
  uORB_read_initialize(SITL_HEXA_MISSION_DW.obj_gv.orbMetadataObj,
                       &SITL_HEXA_MISSION_DW.obj_gv.eventStructObj);
  SITL_HEXA_MISSION_DW.obj_gv.isSetupComplete = true;

  // Start for MATLABSystem: '<S602>/SourceBlock'
  SITL_HEXA_MISSION_DW.obj_p.matlabCodegenIsDeleted = false;
  SITL_HEXA_MISSION_DW.obj_p.isInitialized = 1;
  SITL_HEXA_MISSION_DW.obj_p.orbMetadataObj = ORB_ID(vehicle_angular_velocity);
  uORB_read_initialize(SITL_HEXA_MISSION_DW.obj_p.orbMetadataObj,
                       &SITL_HEXA_MISSION_DW.obj_p.eventStructObj);
  SITL_HEXA_MISSION_DW.obj_p.isSetupComplete = true;

  // Start for MATLABSystem: '<S603>/SourceBlock'
  SITL_HEXA_MISSION_DW.obj_d0.matlabCodegenIsDeleted = false;
  SITL_HEXA_MISSION_DW.obj_d0.isInitialized = 1;
  SITL_HEXA_MISSION_DW.obj_d0.orbMetadataObj = ORB_ID(actuator_armed);
  uORB_read_initialize(SITL_HEXA_MISSION_DW.obj_d0.orbMetadataObj,
                       &SITL_HEXA_MISSION_DW.obj_d0.eventStructObj);
  SITL_HEXA_MISSION_DW.obj_d0.isSetupComplete = true;
  SITL_HEXA_MISSION_PX4Timestamp_Init(&SITL_HEXA_MISSION_DW.PX4Timestamp_pn);

  // Start for MATLABSystem: '<S19>/SinkBlock' incorporates:
  //   BusAssignment: '<S8>/Bus Assignment'

  SITL_HEXA_MISSION_DW.obj_dz.matlabCodegenIsDeleted = false;
  SITL_HEXA_MISSION_DW.obj_dz.isInitialized = 1;
  SITL_HEXA_MISSION_DW.obj_dz.orbMetadataObj = ORB_ID(vehicle_rates_setpoint);
  uORB_write_initialize(SITL_HEXA_MISSION_DW.obj_dz.orbMetadataObj,
                        &SITL_HEXA_MISSION_DW.obj_dz.orbAdvertiseObj,
                        &SITL_HEXA_MISSION_B.BusAssignment_h4, 1);
  SITL_HEXA_MISSION_DW.obj_dz.isSetupComplete = true;
  SITL_HEXA_MISSION_PX4Timestamp_Init(&SITL_HEXA_MISSION_DW.PX4Timestamp_p);
  SITL_HEXA_MISSION_SinkBlock_Init(&SITL_HEXA_MISSION_B.BusAssignment_a,
    &SITL_HEXA_MISSION_DW.SinkBlock_m);
  SITL_HEXA_MISSION_PX4Timestamp_Init(&SITL_HEXA_MISSION_DW.PX4Timestamp);

  // Start for MATLABSystem: '<S15>/SinkBlock' incorporates:
  //   BusAssignment: '<S6>/Bus Assignment'

  SITL_HEXA_MISSION_DW.obj_mg.matlabCodegenIsDeleted = false;
  SITL_HEXA_MISSION_DW.obj_mg.isInitialized = 1;
  SITL_HEXA_MISSION_DW.obj_mg.orbMetadataObj = ORB_ID(vehicle_attitude_setpoint);
  uORB_write_initialize(SITL_HEXA_MISSION_DW.obj_mg.orbMetadataObj,
                        &SITL_HEXA_MISSION_DW.obj_mg.orbAdvertiseObj,
                        &SITL_HEXA_MISSION_B.BusAssignment_h, 1);
  SITL_HEXA_MISSION_DW.obj_mg.isSetupComplete = true;
}

// Model terminate function
void SITL_HEXA_MISSION_terminate(void)
{
  // Terminate for MATLABSystem: '<S605>/SourceBlock'
  if (!SITL_HEXA_MISSION_DW.obj_m.matlabCodegenIsDeleted) {
    SITL_HEXA_MISSION_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((SITL_HEXA_MISSION_DW.obj_m.isInitialized == 1) &&
        SITL_HEXA_MISSION_DW.obj_m.isSetupComplete) {
      uORB_read_terminate(&SITL_HEXA_MISSION_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S605>/SourceBlock'

  // Terminate for Atomic SubSystem: '<Root>/Navigation'
  SITL_HEXA_MISSION_Navigation_Term();

  // End of Terminate for SubSystem: '<Root>/Navigation'

  // Terminate for MATLABSystem: '<S604>/SourceBlock'
  if (!SITL_HEXA_MISSION_DW.obj_gv.matlabCodegenIsDeleted) {
    SITL_HEXA_MISSION_DW.obj_gv.matlabCodegenIsDeleted = true;
    if ((SITL_HEXA_MISSION_DW.obj_gv.isInitialized == 1) &&
        SITL_HEXA_MISSION_DW.obj_gv.isSetupComplete) {
      uORB_read_terminate(&SITL_HEXA_MISSION_DW.obj_gv.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S604>/SourceBlock'

  // Terminate for MATLABSystem: '<S602>/SourceBlock'
  if (!SITL_HEXA_MISSION_DW.obj_p.matlabCodegenIsDeleted) {
    SITL_HEXA_MISSION_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((SITL_HEXA_MISSION_DW.obj_p.isInitialized == 1) &&
        SITL_HEXA_MISSION_DW.obj_p.isSetupComplete) {
      uORB_read_terminate(&SITL_HEXA_MISSION_DW.obj_p.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S602>/SourceBlock'

  // Terminate for MATLABSystem: '<S603>/SourceBlock'
  if (!SITL_HEXA_MISSION_DW.obj_d0.matlabCodegenIsDeleted) {
    SITL_HEXA_MISSION_DW.obj_d0.matlabCodegenIsDeleted = true;
    if ((SITL_HEXA_MISSION_DW.obj_d0.isInitialized == 1) &&
        SITL_HEXA_MISSION_DW.obj_d0.isSetupComplete) {
      uORB_read_terminate(&SITL_HEXA_MISSION_DW.obj_d0.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S603>/SourceBlock'
  SITL_HEXA_MISSION_PX4Timestamp_Term(&SITL_HEXA_MISSION_DW.PX4Timestamp_pn);

  // Terminate for MATLABSystem: '<S19>/SinkBlock'
  if (!SITL_HEXA_MISSION_DW.obj_dz.matlabCodegenIsDeleted) {
    SITL_HEXA_MISSION_DW.obj_dz.matlabCodegenIsDeleted = true;
    if ((SITL_HEXA_MISSION_DW.obj_dz.isInitialized == 1) &&
        SITL_HEXA_MISSION_DW.obj_dz.isSetupComplete) {
      uORB_write_terminate(&SITL_HEXA_MISSION_DW.obj_dz.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S19>/SinkBlock'

  // Terminate for Atomic SubSystem: '<Root>/actuatorOutputs'
  SITL_HEXA_MISSION_actuatorOutputs_Term();

  // End of Terminate for SubSystem: '<Root>/actuatorOutputs'
  SITL_HEXA_MISSION_PX4Timestamp_Term(&SITL_HEXA_MISSION_DW.PX4Timestamp_p);
  SITL_HEXA_MISSION_SinkBlock_Term(&SITL_HEXA_MISSION_DW.SinkBlock_m);
  SITL_HEXA_MISSION_PX4Timestamp_Term(&SITL_HEXA_MISSION_DW.PX4Timestamp);

  // Terminate for MATLABSystem: '<S15>/SinkBlock'
  if (!SITL_HEXA_MISSION_DW.obj_mg.matlabCodegenIsDeleted) {
    SITL_HEXA_MISSION_DW.obj_mg.matlabCodegenIsDeleted = true;
    if ((SITL_HEXA_MISSION_DW.obj_mg.isInitialized == 1) &&
        SITL_HEXA_MISSION_DW.obj_mg.isSetupComplete) {
      uORB_write_terminate(&SITL_HEXA_MISSION_DW.obj_mg.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S15>/SinkBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
