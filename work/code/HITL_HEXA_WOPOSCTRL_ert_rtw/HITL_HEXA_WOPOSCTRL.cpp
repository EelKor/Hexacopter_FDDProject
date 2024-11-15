//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: HITL_HEXA_WOPOSCTRL.cpp
//
// Code generated for Simulink model 'HITL_HEXA_WOPOSCTRL'.
//
// Model version                  : 4.141
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Sep 25 17:31:40 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "HITL_HEXA_WOPOSCTRL.h"
#include "rtwtypes.h"
#include <math.h>
#include "mc_att_controller.h"
#include "mc_rate_controller.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <uORB/topics/vehicle_rates_setpoint.h>
#include "rt_defines.h"
#include "HITL_HEXA_WOPOSCTRL_private.h"

// Block signals (default storage)
B_HITL_HEXA_WOPOSCTRL_T HITL_HEXA_WOPOSCTRL_B;

// Block states (default storage)
DW_HITL_HEXA_WOPOSCTRL_T HITL_HEXA_WOPOSCTRL_DW;

// Real-time model
RT_MODEL_HITL_HEXA_WOPOSCTRL_T HITL_HEXA_WOPOSCTRL_M_ =
  RT_MODEL_HITL_HEXA_WOPOSCTRL_T();
RT_MODEL_HITL_HEXA_WOPOSCTRL_T *const HITL_HEXA_WOPOSCTRL_M =
  &HITL_HEXA_WOPOSCTRL_M_;

// Forward declaration for local functions
static real_T HITL_HEXA_WOPOSCTRL_rt_atan2d_snf(real_T u0, real_T u1);
static real_T HITL_HEXA_WOPOSCTRL_rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    if (u0 > 0.0) {
      HITL_HEXA_WOPOSCTRL_B.i = 1;
    } else {
      HITL_HEXA_WOPOSCTRL_B.i = -1;
    }

    if (u1 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    y = atan2(static_cast<real_T>(HITL_HEXA_WOPOSCTRL_B.i), static_cast<real_T>
              (tmp));
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
void HITL_HEXA_WOPOSCTRL_step(void)
{
  boolean_T b_varargout_1;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_k;

  // MATLABSystem: '<S18>/SourceBlock'
  b_varargout_1 = uORB_read_step(HITL_HEXA_WOPOSCTRL_DW.obj_da.orbMetadataObj,
    &HITL_HEXA_WOPOSCTRL_DW.obj_da.eventStructObj,
    &HITL_HEXA_WOPOSCTRL_B.b_varargout_2_c, false, 5000.0);

  // Outputs for Enabled SubSystem: '<S18>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S19>/Enable'

  // Start for MATLABSystem: '<S18>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S19>/In1'
    HITL_HEXA_WOPOSCTRL_B.In1_k = HITL_HEXA_WOPOSCTRL_B.b_varargout_2_c;
  }

  // End of Outputs for SubSystem: '<S18>/Enabled Subsystem'

  // RelationalOperator: '<S10>/Compare' incorporates:
  //   Constant: '<S10>/Constant'
  //   DataTypeConversion: '<S5>/Data Type Conversion'

  rtb_Compare_k = (HITL_HEXA_WOPOSCTRL_B.In1_k.values[6] >=
                   HITL_HEXA_WOPOSCTRL_P.CompareToConstant_const);

  // MATLABSystem: '<S346>/SourceBlock'
  b_varargout_1 = uORB_read_step(HITL_HEXA_WOPOSCTRL_DW.obj_po.orbMetadataObj,
    &HITL_HEXA_WOPOSCTRL_DW.obj_po.eventStructObj,
    &HITL_HEXA_WOPOSCTRL_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S346>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S350>/Enable'

  // Start for MATLABSystem: '<S346>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S350>/In1'
    HITL_HEXA_WOPOSCTRL_B.In1 = HITL_HEXA_WOPOSCTRL_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S346>/Enabled Subsystem'

  // DataTypeConversion: '<S3>/Cast To Double2'
  HITL_HEXA_WOPOSCTRL_B.CastToDouble2[0] = HITL_HEXA_WOPOSCTRL_B.In1.rollspeed;
  HITL_HEXA_WOPOSCTRL_B.CastToDouble2[1] = HITL_HEXA_WOPOSCTRL_B.In1.pitchspeed;
  HITL_HEXA_WOPOSCTRL_B.CastToDouble2[2] = HITL_HEXA_WOPOSCTRL_B.In1.yawspeed;

  // MATLABSystem: '<S347>/SourceBlock'
  b_varargout_1 = uORB_read_step(HITL_HEXA_WOPOSCTRL_DW.obj_d0.orbMetadataObj,
    &HITL_HEXA_WOPOSCTRL_DW.obj_d0.eventStructObj,
    &HITL_HEXA_WOPOSCTRL_B.b_varargout_2_b, false, 1.0);

  // Outputs for Enabled SubSystem: '<S347>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S351>/Enable'

  // Start for MATLABSystem: '<S347>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S351>/In1'
    HITL_HEXA_WOPOSCTRL_B.In1_b = HITL_HEXA_WOPOSCTRL_B.b_varargout_2_b;
  }

  // End of Outputs for SubSystem: '<S347>/Enabled Subsystem'

  // MATLABSystem: '<S349>/SourceBlock'
  b_varargout_1 = uORB_read_step(HITL_HEXA_WOPOSCTRL_DW.obj_mg.orbMetadataObj,
    &HITL_HEXA_WOPOSCTRL_DW.obj_mg.eventStructObj,
    &HITL_HEXA_WOPOSCTRL_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S349>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S353>/Enable'

  // Start for MATLABSystem: '<S349>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S353>/In1'
    HITL_HEXA_WOPOSCTRL_B.In1_c = HITL_HEXA_WOPOSCTRL_B.b_varargout_2_k;
  }

  // End of Outputs for SubSystem: '<S349>/Enabled Subsystem'

  // DataTypeConversion: '<S3>/Cast To Double'
  HITL_HEXA_WOPOSCTRL_B.CastToDouble[0] = HITL_HEXA_WOPOSCTRL_B.In1_c.roll_body;
  HITL_HEXA_WOPOSCTRL_B.CastToDouble[1] = HITL_HEXA_WOPOSCTRL_B.In1_c.pitch_body;
  HITL_HEXA_WOPOSCTRL_B.CastToDouble[2] = HITL_HEXA_WOPOSCTRL_B.In1_c.yaw_body;
  HITL_HEXA_WOPOSCTRL_B.CastToDouble[3] =
    HITL_HEXA_WOPOSCTRL_B.In1_c.thrust_body[0];
  HITL_HEXA_WOPOSCTRL_B.CastToDouble[4] =
    HITL_HEXA_WOPOSCTRL_B.In1_c.thrust_body[1];
  HITL_HEXA_WOPOSCTRL_B.CastToDouble[5] =
    HITL_HEXA_WOPOSCTRL_B.In1_c.thrust_body[2];

  // MATLABSystem: '<S348>/SourceBlock'
  b_varargout_1 = uORB_read_step(HITL_HEXA_WOPOSCTRL_DW.obj_gv.orbMetadataObj,
    &HITL_HEXA_WOPOSCTRL_DW.obj_gv.eventStructObj,
    &HITL_HEXA_WOPOSCTRL_B.b_varargout_2_cx, false, 1.0);

  // Outputs for Enabled SubSystem: '<S348>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S352>/Enable'

  // Start for MATLABSystem: '<S348>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S352>/In1'
    HITL_HEXA_WOPOSCTRL_B.In1_m = HITL_HEXA_WOPOSCTRL_B.b_varargout_2_cx;
  }

  // End of Outputs for SubSystem: '<S348>/Enabled Subsystem'

  // DataTypeConversion: '<S3>/Cast To Double1' incorporates:
  //   Switch: '<S24>/Switch'

  HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_0 = HITL_HEXA_WOPOSCTRL_B.In1_m.q[0];
  HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_1 = HITL_HEXA_WOPOSCTRL_B.In1_m.q[1];
  HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2 = HITL_HEXA_WOPOSCTRL_B.In1_m.q[2];
  HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3 = HITL_HEXA_WOPOSCTRL_B.In1_m.q[3];

  // Switch: '<S24>/Switch' incorporates:
  //   Constant: '<S24>/Constant'
  //   DataTypeConversion: '<S3>/Cast To Double1'
  //   Product: '<S30>/Product'
  //   Product: '<S30>/Product1'
  //   Product: '<S30>/Product2'
  //   Product: '<S30>/Product3'
  //   Sum: '<S30>/Sum'

  if (!(((static_cast<real_T>(HITL_HEXA_WOPOSCTRL_B.In1_m.q[0]) *
          HITL_HEXA_WOPOSCTRL_B.In1_m.q[0] + static_cast<real_T>
          (HITL_HEXA_WOPOSCTRL_B.In1_m.q[1]) * HITL_HEXA_WOPOSCTRL_B.In1_m.q[1])
         + static_cast<real_T>(HITL_HEXA_WOPOSCTRL_B.In1_m.q[2]) *
         HITL_HEXA_WOPOSCTRL_B.In1_m.q[2]) + static_cast<real_T>
        (HITL_HEXA_WOPOSCTRL_B.In1_m.q[3]) * HITL_HEXA_WOPOSCTRL_B.In1_m.q[3] >
        HITL_HEXA_WOPOSCTRL_P.Switch_Threshold_l)) {
    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_0 =
      HITL_HEXA_WOPOSCTRL_P.Constant_Value_i[0];
    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_1 =
      HITL_HEXA_WOPOSCTRL_P.Constant_Value_i[1];
    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2 =
      HITL_HEXA_WOPOSCTRL_P.Constant_Value_i[2];
    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3 =
      HITL_HEXA_WOPOSCTRL_P.Constant_Value_i[3];
  }

  // End of Switch: '<S24>/Switch'

  // Sqrt: '<S37>/sqrt' incorporates:
  //   Product: '<S38>/Product'
  //   Product: '<S38>/Product1'
  //   Product: '<S38>/Product2'
  //   Product: '<S38>/Product3'
  //   Sum: '<S38>/Sum'

  HITL_HEXA_WOPOSCTRL_B.Switch2_a = sqrt
    (((HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_0 *
       HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_0 +
       HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_1 *
       HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_1) +
      HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2 *
      HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2) +
     HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3 *
     HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3);

  // Product: '<S32>/Product'
  HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_0 /= HITL_HEXA_WOPOSCTRL_B.Switch2_a;

  // Product: '<S32>/Product1'
  HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_1 /= HITL_HEXA_WOPOSCTRL_B.Switch2_a;

  // Product: '<S32>/Product2'
  HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2 /= HITL_HEXA_WOPOSCTRL_B.Switch2_a;

  // Product: '<S32>/Product3'
  HITL_HEXA_WOPOSCTRL_B.Switch2_a = HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3 /
    HITL_HEXA_WOPOSCTRL_B.Switch2_a;

  // Fcn: '<S25>/fcn2' incorporates:
  //   Fcn: '<S25>/fcn5'

  HITL_HEXA_WOPOSCTRL_B.Gain2 = HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_0 *
    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_0;
  HITL_HEXA_WOPOSCTRL_B.Gain3 = HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_1 *
    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_1;
  HITL_HEXA_WOPOSCTRL_B.Saturation1 = HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2 *
    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2;
  HITL_HEXA_WOPOSCTRL_B.Switch1_d = HITL_HEXA_WOPOSCTRL_B.Switch2_a *
    HITL_HEXA_WOPOSCTRL_B.Switch2_a;

  // Trigonometry: '<S31>/Trigonometric Function1' incorporates:
  //   Fcn: '<S25>/fcn1'
  //   Fcn: '<S25>/fcn2'

  HITL_HEXA_WOPOSCTRL_B.VectorConcatenate[0] = HITL_HEXA_WOPOSCTRL_rt_atan2d_snf
    ((HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_1 *
      HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2 +
      HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_0 * HITL_HEXA_WOPOSCTRL_B.Switch2_a)
     * 2.0, ((HITL_HEXA_WOPOSCTRL_B.Gain2 + HITL_HEXA_WOPOSCTRL_B.Gain3) -
             HITL_HEXA_WOPOSCTRL_B.Saturation1) -
     HITL_HEXA_WOPOSCTRL_B.Switch1_d);

  // Fcn: '<S25>/fcn3'
  HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3 =
    (HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_1 * HITL_HEXA_WOPOSCTRL_B.Switch2_a
     - HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_0 *
     HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2) * -2.0;

  // If: '<S33>/If' incorporates:
  //   Constant: '<S34>/Constant'
  //   Constant: '<S35>/Constant'
  //   Trigonometry: '<S31>/trigFcn'

  if (HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3 > 1.0) {
    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3 =
      HITL_HEXA_WOPOSCTRL_P.Constant_Value_b;
  } else if (HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3 < -1.0) {
    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3 =
      HITL_HEXA_WOPOSCTRL_P.Constant_Value_m;
  }

  if (HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3 > 1.0) {
    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3 = 1.0;
  } else if (HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3 < -1.0) {
    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3 = -1.0;
  }

  // End of If: '<S33>/If'

  // Trigonometry: '<S31>/trigFcn'
  HITL_HEXA_WOPOSCTRL_B.VectorConcatenate[1] = asin
    (HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3);

  // Trigonometry: '<S31>/Trigonometric Function3' incorporates:
  //   Fcn: '<S25>/fcn4'
  //   Fcn: '<S25>/fcn5'

  HITL_HEXA_WOPOSCTRL_B.VectorConcatenate[2] = HITL_HEXA_WOPOSCTRL_rt_atan2d_snf
    ((HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2 * HITL_HEXA_WOPOSCTRL_B.Switch2_a
      + HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_0 *
      HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_1) * 2.0,
     ((HITL_HEXA_WOPOSCTRL_B.Gain2 - HITL_HEXA_WOPOSCTRL_B.Gain3) -
      HITL_HEXA_WOPOSCTRL_B.Saturation1) + HITL_HEXA_WOPOSCTRL_B.Switch1_d);

  // Outputs for Enabled SubSystem: '<S22>/mc_att_controller'
  HITL_HEXA_WOPOSCTRL_mc_att_controller();

  // End of Outputs for SubSystem: '<S22>/mc_att_controller'

  // Outputs for Enabled SubSystem: '<S22>/mc_rate_controller'
  HITL_HEXA_WOPOSCTRL_mc_rate_controller();

  // End of Outputs for SubSystem: '<S22>/mc_rate_controller'

  // Gain: '<S4>/Gain'
  HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2 = HITL_HEXA_WOPOSCTRL_P.Gain_Gain_j *
    HITL_HEXA_WOPOSCTRL_B.Saturation_b;

  // Gain: '<S4>/Gain1'
  HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3 = HITL_HEXA_WOPOSCTRL_P.Gain1_Gain *
    HITL_HEXA_WOPOSCTRL_B.Saturation_c;

  // Gain: '<S4>/Gain2'
  HITL_HEXA_WOPOSCTRL_B.Gain2 = HITL_HEXA_WOPOSCTRL_P.Gain2_Gain *
    HITL_HEXA_WOPOSCTRL_B.Saturation;

  // Gain: '<S4>/Gain3'
  HITL_HEXA_WOPOSCTRL_B.Gain3 = HITL_HEXA_WOPOSCTRL_P.Gain3_Gain *
    HITL_HEXA_WOPOSCTRL_B.CastToDouble[5];

  // BusAssignment: '<S9>/Bus Assignment' incorporates:
  //   Constant: '<S20>/Constant'

  HITL_HEXA_WOPOSCTRL_B.BusAssignment = HITL_HEXA_WOPOSCTRL_P.Constant_Value_c;

  // MATLABSystem: '<S6>/Read Parameter13'
  if (HITL_HEXA_WOPOSCTRL_DW.obj_ka.SampleTime !=
      HITL_HEXA_WOPOSCTRL_P.ReadParameter13_SampleTime) {
    HITL_HEXA_WOPOSCTRL_DW.obj_ka.SampleTime =
      HITL_HEXA_WOPOSCTRL_P.ReadParameter13_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_ka.MW_PARAMHANDLE,
    MW_INT32, &HITL_HEXA_WOPOSCTRL_B.ParamStep);
  if (b_varargout_1) {
    HITL_HEXA_WOPOSCTRL_B.ParamStep = 0;
  }

  // RelationalOperator: '<S17>/Compare' incorporates:
  //   Constant: '<S17>/Constant'

  rtb_Compare = (HITL_HEXA_WOPOSCTRL_B.In1_k.values[7] >=
                 HITL_HEXA_WOPOSCTRL_P.CompareToConstant_const_k);

  // Switch: '<S5>/Switch' incorporates:
  //   Constant: '<S11>/Constant'
  //   Constant: '<S11>/IDLE PWM'
  //   Constant: '<S5>/Constant'
  //   MATLAB Function: '<S4>/MATLAB Function'
  //   Product: '<S11>/Product'
  //   Saturate: '<S11>/Saturation1'
  //   Sum: '<S11>/Add'
  //   Sum: '<S11>/Sum'
  //   Switch: '<S6>/Switch'

  if (rtb_Compare_k) {
    HITL_HEXA_WOPOSCTRL_B.Saturation1 = HITL_HEXA_WOPOSCTRL_P.Constant_Value_o;
  } else {
    if (rtb_Compare) {
      // ManualSwitch: '<S6>/Manual Switch' incorporates:
      //   Constant: '<S6>/Fault'
      //   DataTypeConversion: '<S6>/Data Type Conversion3'
      //   MATLABSystem: '<S6>/Read Parameter13'
      //   Switch: '<S6>/Switch'
      //
      if (HITL_HEXA_WOPOSCTRL_P.ManualSwitch_CurrentSetting == 1) {
        HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Fault_Value;
      } else {
        HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_B.ParamStep;
      }

      // End of ManualSwitch: '<S6>/Manual Switch'
    } else {
      // Switch: '<S6>/Switch' incorporates:
      //   Constant: '<S6>/Constant'

      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Constant_Value_d;
    }

    // Gain: '<S11>/Gain' incorporates:
    //   Switch: '<S6>/Switch'

    HITL_HEXA_WOPOSCTRL_B.u0 *= HITL_HEXA_WOPOSCTRL_P.Gain_Gain_c;

    // Saturate: '<S11>/Saturation1'
    if (HITL_HEXA_WOPOSCTRL_B.u0 > HITL_HEXA_WOPOSCTRL_P.Saturation1_UpperSat_g)
    {
      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Saturation1_UpperSat_g;
    } else if (HITL_HEXA_WOPOSCTRL_B.u0 <
               HITL_HEXA_WOPOSCTRL_P.Saturation1_LowerSat_c) {
      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Saturation1_LowerSat_c;
    }

    HITL_HEXA_WOPOSCTRL_B.Saturation1 =
      ((((-HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2 -
          HITL_HEXA_WOPOSCTRL_B.Gain2) * HITL_HEXA_WOPOSCTRL_B.Gain3 / 3.0 +
         HITL_HEXA_WOPOSCTRL_B.Gain3) * 1000.0 + 1000.0) -
       HITL_HEXA_WOPOSCTRL_P.IDLEPWM_Value_h) * HITL_HEXA_WOPOSCTRL_B.u0 +
      HITL_HEXA_WOPOSCTRL_P.Constant_Value_h;
  }

  // End of Switch: '<S5>/Switch'

  // MATLABSystem: '<S6>/Read Parameter1'
  if (HITL_HEXA_WOPOSCTRL_DW.obj_a.SampleTime !=
      HITL_HEXA_WOPOSCTRL_P.ReadParameter1_SampleTime) {
    HITL_HEXA_WOPOSCTRL_DW.obj_a.SampleTime =
      HITL_HEXA_WOPOSCTRL_P.ReadParameter1_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_a.MW_PARAMHANDLE,
    MW_INT32, &HITL_HEXA_WOPOSCTRL_B.ParamStep);
  if (b_varargout_1) {
    HITL_HEXA_WOPOSCTRL_B.ParamStep = 0;
  }

  // Switch: '<S5>/Switch1' incorporates:
  //   Constant: '<S12>/Constant'
  //   Constant: '<S12>/IDLE PWM'
  //   Constant: '<S5>/Constant1'
  //   MATLAB Function: '<S4>/MATLAB Function'
  //   Product: '<S12>/Product'
  //   Saturate: '<S12>/Saturation1'
  //   Sum: '<S12>/Add'
  //   Sum: '<S12>/Sum'
  //   Switch: '<S6>/Switch1'

  if (rtb_Compare_k) {
    HITL_HEXA_WOPOSCTRL_B.Switch1_d = HITL_HEXA_WOPOSCTRL_P.Constant1_Value;
  } else {
    if (rtb_Compare) {
      // ManualSwitch: '<S6>/Manual Switch1' incorporates:
      //   Constant: '<S6>/Fault1'
      //   DataTypeConversion: '<S6>/Data Type Conversion2'
      //   MATLABSystem: '<S6>/Read Parameter1'
      //   Switch: '<S6>/Switch1'
      //
      if (HITL_HEXA_WOPOSCTRL_P.ManualSwitch1_CurrentSetting == 1) {
        HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Fault1_Value;
      } else {
        HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_B.ParamStep;
      }

      // End of ManualSwitch: '<S6>/Manual Switch1'
    } else {
      // Switch: '<S6>/Switch1' incorporates:
      //   Constant: '<S6>/Constant1'

      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Constant1_Value_j;
    }

    // Gain: '<S12>/Gain' incorporates:
    //   Switch: '<S6>/Switch1'

    HITL_HEXA_WOPOSCTRL_B.u0 *= HITL_HEXA_WOPOSCTRL_P.Gain_Gain;

    // Saturate: '<S12>/Saturation1'
    if (HITL_HEXA_WOPOSCTRL_B.u0 > HITL_HEXA_WOPOSCTRL_P.Saturation1_UpperSat) {
      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Saturation1_UpperSat;
    } else if (HITL_HEXA_WOPOSCTRL_B.u0 <
               HITL_HEXA_WOPOSCTRL_P.Saturation1_LowerSat) {
      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Saturation1_LowerSat;
    }

    HITL_HEXA_WOPOSCTRL_B.Switch1_d =
      ((((HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2 + HITL_HEXA_WOPOSCTRL_B.Gain2)
         * HITL_HEXA_WOPOSCTRL_B.Gain3 / 3.0 + HITL_HEXA_WOPOSCTRL_B.Gain3) *
        1000.0 + 1000.0) - HITL_HEXA_WOPOSCTRL_P.IDLEPWM_Value) *
      HITL_HEXA_WOPOSCTRL_B.u0 + HITL_HEXA_WOPOSCTRL_P.Constant_Value_e1;
  }

  // End of Switch: '<S5>/Switch1'

  // MATLABSystem: '<S6>/Read Parameter2'
  if (HITL_HEXA_WOPOSCTRL_DW.obj_ng.SampleTime !=
      HITL_HEXA_WOPOSCTRL_P.ReadParameter2_SampleTime) {
    HITL_HEXA_WOPOSCTRL_DW.obj_ng.SampleTime =
      HITL_HEXA_WOPOSCTRL_P.ReadParameter2_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_ng.MW_PARAMHANDLE,
    MW_INT32, &HITL_HEXA_WOPOSCTRL_B.ParamStep);
  if (b_varargout_1) {
    HITL_HEXA_WOPOSCTRL_B.ParamStep = 0;
  }

  // Switch: '<S5>/Switch2' incorporates:
  //   Constant: '<S13>/Constant'
  //   Constant: '<S13>/IDLE PWM'
  //   Constant: '<S5>/Constant2'
  //   MATLAB Function: '<S4>/MATLAB Function'
  //   Product: '<S13>/Product'
  //   Saturate: '<S13>/Saturation1'
  //   Sum: '<S13>/Add'
  //   Sum: '<S13>/Sum'
  //   Switch: '<S6>/Switch2'

  if (rtb_Compare_k) {
    HITL_HEXA_WOPOSCTRL_B.Switch2_a = HITL_HEXA_WOPOSCTRL_P.Constant2_Value;
  } else {
    if (rtb_Compare) {
      // ManualSwitch: '<S6>/Manual Switch2' incorporates:
      //   Constant: '<S6>/Fault2'
      //   DataTypeConversion: '<S6>/Data Type Conversion'
      //   MATLABSystem: '<S6>/Read Parameter2'
      //   Switch: '<S6>/Switch2'
      //
      if (HITL_HEXA_WOPOSCTRL_P.ManualSwitch2_CurrentSetting == 1) {
        HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Fault2_Value;
      } else {
        HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_B.ParamStep;
      }

      // End of ManualSwitch: '<S6>/Manual Switch2'
    } else {
      // Switch: '<S6>/Switch2' incorporates:
      //   Constant: '<S6>/Constant2'

      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Constant2_Value_o;
    }

    // Gain: '<S13>/Gain' incorporates:
    //   Switch: '<S6>/Switch2'

    HITL_HEXA_WOPOSCTRL_B.u0 *= HITL_HEXA_WOPOSCTRL_P.Gain_Gain_d;

    // Saturate: '<S13>/Saturation1'
    if (HITL_HEXA_WOPOSCTRL_B.u0 > HITL_HEXA_WOPOSCTRL_P.Saturation1_UpperSat_e)
    {
      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Saturation1_UpperSat_e;
    } else if (HITL_HEXA_WOPOSCTRL_B.u0 <
               HITL_HEXA_WOPOSCTRL_P.Saturation1_LowerSat_m) {
      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Saturation1_LowerSat_m;
    }

    HITL_HEXA_WOPOSCTRL_B.Switch2_a =
      (((((HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2 / 2.0 +
           HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3) -
          HITL_HEXA_WOPOSCTRL_B.Gain2) * HITL_HEXA_WOPOSCTRL_B.Gain3 / 3.0 +
         HITL_HEXA_WOPOSCTRL_B.Gain3) * 1000.0 + 1000.0) -
       HITL_HEXA_WOPOSCTRL_P.IDLEPWM_Value_j) * HITL_HEXA_WOPOSCTRL_B.u0 +
      HITL_HEXA_WOPOSCTRL_P.Constant_Value_f;
  }

  // End of Switch: '<S5>/Switch2'

  // MATLABSystem: '<S6>/Read Parameter3'
  if (HITL_HEXA_WOPOSCTRL_DW.obj_n0.SampleTime !=
      HITL_HEXA_WOPOSCTRL_P.ReadParameter3_SampleTime) {
    HITL_HEXA_WOPOSCTRL_DW.obj_n0.SampleTime =
      HITL_HEXA_WOPOSCTRL_P.ReadParameter3_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_n0.MW_PARAMHANDLE,
    MW_INT32, &HITL_HEXA_WOPOSCTRL_B.ParamStep);
  if (b_varargout_1) {
    HITL_HEXA_WOPOSCTRL_B.ParamStep = 0;
  }

  // Switch: '<S5>/Switch3' incorporates:
  //   Constant: '<S14>/Constant'
  //   Constant: '<S14>/IDLE PWM'
  //   Constant: '<S5>/Constant3'
  //   MATLAB Function: '<S4>/MATLAB Function'
  //   Product: '<S14>/Product'
  //   Saturate: '<S14>/Saturation1'
  //   Sum: '<S14>/Add'
  //   Sum: '<S14>/Sum'
  //   Switch: '<S6>/Switch3'

  if (rtb_Compare_k) {
    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_0 =
      HITL_HEXA_WOPOSCTRL_P.Constant3_Value;
  } else {
    if (rtb_Compare) {
      // ManualSwitch: '<S6>/Manual Switch3' incorporates:
      //   Constant: '<S6>/Fault3'
      //   DataTypeConversion: '<S6>/Data Type Conversion4'
      //   MATLABSystem: '<S6>/Read Parameter3'
      //   Switch: '<S6>/Switch3'
      //
      if (HITL_HEXA_WOPOSCTRL_P.ManualSwitch3_CurrentSetting == 1) {
        HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Fault3_Value;
      } else {
        HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_B.ParamStep;
      }

      // End of ManualSwitch: '<S6>/Manual Switch3'
    } else {
      // Switch: '<S6>/Switch3' incorporates:
      //   Constant: '<S6>/Constant3'

      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Constant3_Value_b;
    }

    // Gain: '<S14>/Gain' incorporates:
    //   Switch: '<S6>/Switch3'

    HITL_HEXA_WOPOSCTRL_B.u0 *= HITL_HEXA_WOPOSCTRL_P.Gain_Gain_a;

    // Saturate: '<S14>/Saturation1'
    if (HITL_HEXA_WOPOSCTRL_B.u0 > HITL_HEXA_WOPOSCTRL_P.Saturation1_UpperSat_l)
    {
      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Saturation1_UpperSat_l;
    } else if (HITL_HEXA_WOPOSCTRL_B.u0 <
               HITL_HEXA_WOPOSCTRL_P.Saturation1_LowerSat_g) {
      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Saturation1_LowerSat_g;
    }

    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_0 =
      (((((-HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3 -
           HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2 / 2.0) +
          HITL_HEXA_WOPOSCTRL_B.Gain2) * HITL_HEXA_WOPOSCTRL_B.Gain3 / 3.0 +
         HITL_HEXA_WOPOSCTRL_B.Gain3) * 1000.0 + 1000.0) -
       HITL_HEXA_WOPOSCTRL_P.IDLEPWM_Value_k) * HITL_HEXA_WOPOSCTRL_B.u0 +
      HITL_HEXA_WOPOSCTRL_P.Constant_Value_a;
  }

  // End of Switch: '<S5>/Switch3'

  // MATLABSystem: '<S6>/Read Parameter4'
  if (HITL_HEXA_WOPOSCTRL_DW.obj_c.SampleTime !=
      HITL_HEXA_WOPOSCTRL_P.ReadParameter4_SampleTime) {
    HITL_HEXA_WOPOSCTRL_DW.obj_c.SampleTime =
      HITL_HEXA_WOPOSCTRL_P.ReadParameter4_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_c.MW_PARAMHANDLE,
    MW_INT32, &HITL_HEXA_WOPOSCTRL_B.ParamStep);
  if (b_varargout_1) {
    HITL_HEXA_WOPOSCTRL_B.ParamStep = 0;
  }

  // Switch: '<S5>/Switch4' incorporates:
  //   Constant: '<S15>/Constant'
  //   Constant: '<S15>/IDLE PWM'
  //   Constant: '<S5>/Constant4'
  //   MATLAB Function: '<S4>/MATLAB Function'
  //   Product: '<S15>/Product'
  //   Saturate: '<S15>/Saturation1'
  //   Sum: '<S15>/Add'
  //   Sum: '<S15>/Sum'
  //   Switch: '<S6>/Switch4'

  if (rtb_Compare_k) {
    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_1 =
      HITL_HEXA_WOPOSCTRL_P.Constant4_Value;
  } else {
    if (rtb_Compare) {
      // ManualSwitch: '<S6>/Manual Switch4' incorporates:
      //   Constant: '<S6>/Fault4'
      //   DataTypeConversion: '<S6>/Data Type Conversion1'
      //   MATLABSystem: '<S6>/Read Parameter4'
      //   Switch: '<S6>/Switch4'
      //
      if (HITL_HEXA_WOPOSCTRL_P.ManualSwitch4_CurrentSetting == 1) {
        HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Fault4_Value;
      } else {
        HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_B.ParamStep;
      }

      // End of ManualSwitch: '<S6>/Manual Switch4'
    } else {
      // Switch: '<S6>/Switch4' incorporates:
      //   Constant: '<S6>/Constant4'

      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Constant4_Value_e;
    }

    // Gain: '<S15>/Gain' incorporates:
    //   Switch: '<S6>/Switch4'

    HITL_HEXA_WOPOSCTRL_B.u0 *= HITL_HEXA_WOPOSCTRL_P.Gain_Gain_o;

    // Saturate: '<S15>/Saturation1'
    if (HITL_HEXA_WOPOSCTRL_B.u0 > HITL_HEXA_WOPOSCTRL_P.Saturation1_UpperSat_eb)
    {
      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Saturation1_UpperSat_eb;
    } else if (HITL_HEXA_WOPOSCTRL_B.u0 <
               HITL_HEXA_WOPOSCTRL_P.Saturation1_LowerSat_b) {
      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Saturation1_LowerSat_b;
    }

    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_1 =
      (((((HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3 -
           HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2 / 2.0) +
          HITL_HEXA_WOPOSCTRL_B.Gain2) * HITL_HEXA_WOPOSCTRL_B.Gain3 / 3.0 +
         HITL_HEXA_WOPOSCTRL_B.Gain3) * 1000.0 + 1000.0) -
       HITL_HEXA_WOPOSCTRL_P.IDLEPWM_Value_c) * HITL_HEXA_WOPOSCTRL_B.u0 +
      HITL_HEXA_WOPOSCTRL_P.Constant_Value_j3;
  }

  // End of Switch: '<S5>/Switch4'

  // MATLABSystem: '<S6>/Read Parameter5'
  if (HITL_HEXA_WOPOSCTRL_DW.obj_p1.SampleTime !=
      HITL_HEXA_WOPOSCTRL_P.ReadParameter5_SampleTime) {
    HITL_HEXA_WOPOSCTRL_DW.obj_p1.SampleTime =
      HITL_HEXA_WOPOSCTRL_P.ReadParameter5_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_p1.MW_PARAMHANDLE,
    MW_INT32, &HITL_HEXA_WOPOSCTRL_B.ParamStep);
  if (b_varargout_1) {
    HITL_HEXA_WOPOSCTRL_B.ParamStep = 0;
  }

  // Switch: '<S5>/Switch5' incorporates:
  //   Constant: '<S16>/Constant'
  //   Constant: '<S16>/IDLE PWM'
  //   Constant: '<S5>/Constant5'
  //   MATLAB Function: '<S4>/MATLAB Function'
  //   Product: '<S16>/Product'
  //   Saturate: '<S16>/Saturation1'
  //   Sum: '<S16>/Add'
  //   Sum: '<S16>/Sum'
  //   Switch: '<S6>/Switch5'

  if (rtb_Compare_k) {
    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2 =
      HITL_HEXA_WOPOSCTRL_P.Constant5_Value;
  } else {
    if (rtb_Compare) {
      // ManualSwitch: '<S6>/Manual Switch5' incorporates:
      //   Constant: '<S6>/Fault5'
      //   DataTypeConversion: '<S6>/Data Type Conversion5'
      //   MATLABSystem: '<S6>/Read Parameter5'
      //   Switch: '<S6>/Switch5'
      //
      if (HITL_HEXA_WOPOSCTRL_P.ManualSwitch5_CurrentSetting == 1) {
        HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Fault5_Value;
      } else {
        HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_B.ParamStep;
      }

      // End of ManualSwitch: '<S6>/Manual Switch5'
    } else {
      // Switch: '<S6>/Switch5' incorporates:
      //   Constant: '<S6>/Constant5'

      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Constant5_Value_f;
    }

    // Gain: '<S16>/Gain' incorporates:
    //   Switch: '<S6>/Switch5'

    HITL_HEXA_WOPOSCTRL_B.u0 *= HITL_HEXA_WOPOSCTRL_P.Gain_Gain_ap;

    // Saturate: '<S16>/Saturation1'
    if (HITL_HEXA_WOPOSCTRL_B.u0 > HITL_HEXA_WOPOSCTRL_P.Saturation1_UpperSat_b)
    {
      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Saturation1_UpperSat_b;
    } else if (HITL_HEXA_WOPOSCTRL_B.u0 <
               HITL_HEXA_WOPOSCTRL_P.Saturation1_LowerSat_o) {
      HITL_HEXA_WOPOSCTRL_B.u0 = HITL_HEXA_WOPOSCTRL_P.Saturation1_LowerSat_o;
    }

    HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2 =
      (((((HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2 / 2.0 -
           HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_3) -
          HITL_HEXA_WOPOSCTRL_B.Gain2) * HITL_HEXA_WOPOSCTRL_B.Gain3 / 3.0 +
         HITL_HEXA_WOPOSCTRL_B.Gain3) * 1000.0 + 1000.0) -
       HITL_HEXA_WOPOSCTRL_P.IDLEPWM_Value_e) * HITL_HEXA_WOPOSCTRL_B.u0 +
      HITL_HEXA_WOPOSCTRL_P.Constant_Value_cx;
  }

  // End of Switch: '<S5>/Switch5'

  // BusAssignment: '<S23>/Bus Assignment' incorporates:
  //   Constant: '<S23>/thrust_sp_bX'
  //   Constant: '<S23>/thrust_sp_bY'
  //   DataTypeConversion: '<S23>/Data Type Conversion'
  //   DataTypeConversion: '<S23>/Data Type Conversion1'
  //   DataTypeConversion: '<S23>/Data Type Conversion2'
  //   DataTypeConversion: '<S23>/Data Type Conversion3'
  //   MATLABSystem: '<S23>/PX4 Timestamp'

  HITL_HEXA_WOPOSCTRL_B.BusAssignment_h.timestamp = hrt_absolute_time();
  HITL_HEXA_WOPOSCTRL_B.BusAssignment_h.roll = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_B.Switch2);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment_h.pitch = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_B.Switch2_l);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment_h.yaw = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_B.Switch2_n);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment_h.thrust_body[0] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_P.thrust_sp_bX_Value);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment_h.thrust_body[1] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_P.thrust_sp_bY_Value);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment_h.thrust_body[2] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_B.CastToDouble[5]);

  // MATLABSystem: '<S29>/SinkBlock' incorporates:
  //   BusAssignment: '<S23>/Bus Assignment'

  uORB_write_step(HITL_HEXA_WOPOSCTRL_DW.obj_dz.orbMetadataObj,
                  &HITL_HEXA_WOPOSCTRL_DW.obj_dz.orbAdvertiseObj,
                  &HITL_HEXA_WOPOSCTRL_B.BusAssignment_h);

  // DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
  //   Constant: '<S9>/Constant17'

  HITL_HEXA_WOPOSCTRL_B.u0 = floor(HITL_HEXA_WOPOSCTRL_P.Constant17_Value);
  if (rtIsNaN(HITL_HEXA_WOPOSCTRL_B.u0) || rtIsInf(HITL_HEXA_WOPOSCTRL_B.u0)) {
    HITL_HEXA_WOPOSCTRL_B.u0 = 0.0;
  } else {
    HITL_HEXA_WOPOSCTRL_B.u0 = fmod(HITL_HEXA_WOPOSCTRL_B.u0, 4.294967296E+9);
  }

  // BusAssignment: '<S9>/Bus Assignment' incorporates:
  //   Constant: '<S9>/Constant'
  //   DataTypeConversion: '<S9>/Data Type Conversion'
  //   DataTypeConversion: '<S9>/Data Type Conversion1'

  HITL_HEXA_WOPOSCTRL_B.BusAssignment.noutputs = HITL_HEXA_WOPOSCTRL_B.u0 < 0.0 ?
    static_cast<uint32_T>(-static_cast<int32_T>(static_cast<uint32_T>
    (-HITL_HEXA_WOPOSCTRL_B.u0))) : static_cast<uint32_T>
    (HITL_HEXA_WOPOSCTRL_B.u0);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment.output[0] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_B.Saturation1);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment.output[1] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_B.Switch1_d);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment.output[2] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_B.Switch2_a);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment.output[3] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_0);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment.output[4] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_1);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment.output[5] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_B.rtb_Switch_j_idx_2);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment.output[6] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_P.Constant_Value_g);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment.output[7] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_P.Constant_Value_g);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment.output[8] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_P.Constant_Value_g);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment.output[9] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_P.Constant_Value_g);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment.output[10] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_P.Constant_Value_g);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment.output[11] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_P.Constant_Value_g);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment.output[12] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_P.Constant_Value_g);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment.output[13] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_P.Constant_Value_g);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment.output[14] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_P.Constant_Value_g);
  HITL_HEXA_WOPOSCTRL_B.BusAssignment.output[15] = static_cast<real32_T>
    (HITL_HEXA_WOPOSCTRL_P.Constant_Value_g);

  // MATLABSystem: '<S21>/SinkBlock' incorporates:
  //   BusAssignment: '<S9>/Bus Assignment'

  uORB_write_step(HITL_HEXA_WOPOSCTRL_DW.obj_hy.orbMetadataObj,
                  &HITL_HEXA_WOPOSCTRL_DW.obj_hy.orbAdvertiseObj,
                  &HITL_HEXA_WOPOSCTRL_B.BusAssignment);
}

// Model initialize function
void HITL_HEXA_WOPOSCTRL_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const char_T ParameterNameStr[14] = "FDD_M1_STATUS";
    static const char_T ParameterNameStr_0[14] = "FDD_M2_STATUS";
    static const char_T ParameterNameStr_1[14] = "FDD_M3_STATUS";
    static const char_T ParameterNameStr_2[14] = "FDD_M4_STATUS";
    static const char_T ParameterNameStr_3[14] = "FDD_M5_STATUS";
    static const char_T ParameterNameStr_4[14] = "FDD_M6_STATUS";
    px4_Bus_vehicle_rates_setpoint rtb_BusAssignment_p;
    real_T tmp;

    // SystemInitialize for Enabled SubSystem: '<S18>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S19>/In1' incorporates:
    //   Outport: '<S19>/Out1'

    HITL_HEXA_WOPOSCTRL_B.In1_k = HITL_HEXA_WOPOSCTRL_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S18>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S346>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S350>/In1' incorporates:
    //   Outport: '<S350>/Out1'

    HITL_HEXA_WOPOSCTRL_B.In1 = HITL_HEXA_WOPOSCTRL_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S346>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S347>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S351>/Out1' incorporates:
    //   SignalConversion generated from: '<S351>/In1'

    HITL_HEXA_WOPOSCTRL_B.In1_b = HITL_HEXA_WOPOSCTRL_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S347>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S349>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S353>/In1' incorporates:
    //   Outport: '<S353>/Out1'

    HITL_HEXA_WOPOSCTRL_B.In1_c = HITL_HEXA_WOPOSCTRL_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S349>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S348>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S352>/In1' incorporates:
    //   Outport: '<S352>/Out1'

    HITL_HEXA_WOPOSCTRL_B.In1_m = HITL_HEXA_WOPOSCTRL_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S348>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S22>/mc_att_controller'
    HITL_HEXA_WOPOSCTRL_mc_att_controller_Init();

    // End of SystemInitialize for SubSystem: '<S22>/mc_att_controller'

    // SystemInitialize for Enabled SubSystem: '<S22>/mc_rate_controller'
    HITL_HEXA_WOPOSCTRL_mc_rate_controller_Init();

    // End of SystemInitialize for SubSystem: '<S22>/mc_rate_controller'

    // Start for MATLABSystem: '<S18>/SourceBlock'
    HITL_HEXA_WOPOSCTRL_DW.obj_da.matlabCodegenIsDeleted = false;
    HITL_HEXA_WOPOSCTRL_DW.obj_da.isInitialized = 1;
    HITL_HEXA_WOPOSCTRL_DW.obj_da.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(HITL_HEXA_WOPOSCTRL_DW.obj_da.orbMetadataObj,
                         &HITL_HEXA_WOPOSCTRL_DW.obj_da.eventStructObj);
    HITL_HEXA_WOPOSCTRL_DW.obj_da.isSetupComplete = true;

    // Start for MATLABSystem: '<S346>/SourceBlock'
    HITL_HEXA_WOPOSCTRL_DW.obj_po.matlabCodegenIsDeleted = false;
    HITL_HEXA_WOPOSCTRL_DW.obj_po.isInitialized = 1;
    HITL_HEXA_WOPOSCTRL_DW.obj_po.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(HITL_HEXA_WOPOSCTRL_DW.obj_po.orbMetadataObj,
                         &HITL_HEXA_WOPOSCTRL_DW.obj_po.eventStructObj);
    HITL_HEXA_WOPOSCTRL_DW.obj_po.isSetupComplete = true;

    // Start for MATLABSystem: '<S347>/SourceBlock'
    HITL_HEXA_WOPOSCTRL_DW.obj_d0.matlabCodegenIsDeleted = false;
    HITL_HEXA_WOPOSCTRL_DW.obj_d0.isInitialized = 1;
    HITL_HEXA_WOPOSCTRL_DW.obj_d0.orbMetadataObj = ORB_ID(actuator_armed);
    uORB_read_initialize(HITL_HEXA_WOPOSCTRL_DW.obj_d0.orbMetadataObj,
                         &HITL_HEXA_WOPOSCTRL_DW.obj_d0.eventStructObj);
    HITL_HEXA_WOPOSCTRL_DW.obj_d0.isSetupComplete = true;

    // Start for MATLABSystem: '<S349>/SourceBlock'
    HITL_HEXA_WOPOSCTRL_DW.obj_mg.matlabCodegenIsDeleted = false;
    HITL_HEXA_WOPOSCTRL_DW.obj_mg.isInitialized = 1;
    HITL_HEXA_WOPOSCTRL_DW.obj_mg.orbMetadataObj = ORB_ID(vehicle_local_position);
    uORB_read_initialize(HITL_HEXA_WOPOSCTRL_DW.obj_mg.orbMetadataObj,
                         &HITL_HEXA_WOPOSCTRL_DW.obj_mg.eventStructObj);
    HITL_HEXA_WOPOSCTRL_DW.obj_mg.isSetupComplete = true;

    // Start for MATLABSystem: '<S348>/SourceBlock'
    HITL_HEXA_WOPOSCTRL_DW.obj_gv.matlabCodegenIsDeleted = false;
    HITL_HEXA_WOPOSCTRL_DW.obj_gv.isInitialized = 1;
    HITL_HEXA_WOPOSCTRL_DW.obj_gv.orbMetadataObj = ORB_ID(vehicle_attitude);
    uORB_read_initialize(HITL_HEXA_WOPOSCTRL_DW.obj_gv.orbMetadataObj,
                         &HITL_HEXA_WOPOSCTRL_DW.obj_gv.eventStructObj);
    HITL_HEXA_WOPOSCTRL_DW.obj_gv.isSetupComplete = true;

    // Start for MATLABSystem: '<S6>/Read Parameter13'
    HITL_HEXA_WOPOSCTRL_DW.obj_ka.matlabCodegenIsDeleted = false;
    HITL_HEXA_WOPOSCTRL_DW.obj_ka.SampleTime =
      HITL_HEXA_WOPOSCTRL_P.ReadParameter13_SampleTime;
    HITL_HEXA_WOPOSCTRL_DW.obj_ka.isInitialized = 1;
    if (HITL_HEXA_WOPOSCTRL_DW.obj_ka.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = HITL_HEXA_WOPOSCTRL_DW.obj_ka.SampleTime;
    }

    HITL_HEXA_WOPOSCTRL_DW.obj_ka.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr[0], true, tmp * 1000.0);
    HITL_HEXA_WOPOSCTRL_DW.obj_ka.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter13'

    // Start for MATLABSystem: '<S6>/Read Parameter1'
    HITL_HEXA_WOPOSCTRL_DW.obj_a.matlabCodegenIsDeleted = false;
    HITL_HEXA_WOPOSCTRL_DW.obj_a.SampleTime =
      HITL_HEXA_WOPOSCTRL_P.ReadParameter1_SampleTime;
    HITL_HEXA_WOPOSCTRL_DW.obj_a.isInitialized = 1;
    if (HITL_HEXA_WOPOSCTRL_DW.obj_a.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = HITL_HEXA_WOPOSCTRL_DW.obj_a.SampleTime;
    }

    HITL_HEXA_WOPOSCTRL_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, tmp * 1000.0);
    HITL_HEXA_WOPOSCTRL_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter1'

    // Start for MATLABSystem: '<S6>/Read Parameter2'
    HITL_HEXA_WOPOSCTRL_DW.obj_ng.matlabCodegenIsDeleted = false;
    HITL_HEXA_WOPOSCTRL_DW.obj_ng.SampleTime =
      HITL_HEXA_WOPOSCTRL_P.ReadParameter2_SampleTime;
    HITL_HEXA_WOPOSCTRL_DW.obj_ng.isInitialized = 1;
    if (HITL_HEXA_WOPOSCTRL_DW.obj_ng.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = HITL_HEXA_WOPOSCTRL_DW.obj_ng.SampleTime;
    }

    HITL_HEXA_WOPOSCTRL_DW.obj_ng.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1[0], true, tmp * 1000.0);
    HITL_HEXA_WOPOSCTRL_DW.obj_ng.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter2'

    // Start for MATLABSystem: '<S6>/Read Parameter3'
    HITL_HEXA_WOPOSCTRL_DW.obj_n0.matlabCodegenIsDeleted = false;
    HITL_HEXA_WOPOSCTRL_DW.obj_n0.SampleTime =
      HITL_HEXA_WOPOSCTRL_P.ReadParameter3_SampleTime;
    HITL_HEXA_WOPOSCTRL_DW.obj_n0.isInitialized = 1;
    if (HITL_HEXA_WOPOSCTRL_DW.obj_n0.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = HITL_HEXA_WOPOSCTRL_DW.obj_n0.SampleTime;
    }

    HITL_HEXA_WOPOSCTRL_DW.obj_n0.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, tmp * 1000.0);
    HITL_HEXA_WOPOSCTRL_DW.obj_n0.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter3'

    // Start for MATLABSystem: '<S6>/Read Parameter4'
    HITL_HEXA_WOPOSCTRL_DW.obj_c.matlabCodegenIsDeleted = false;
    HITL_HEXA_WOPOSCTRL_DW.obj_c.SampleTime =
      HITL_HEXA_WOPOSCTRL_P.ReadParameter4_SampleTime;
    HITL_HEXA_WOPOSCTRL_DW.obj_c.isInitialized = 1;
    if (HITL_HEXA_WOPOSCTRL_DW.obj_c.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = HITL_HEXA_WOPOSCTRL_DW.obj_c.SampleTime;
    }

    HITL_HEXA_WOPOSCTRL_DW.obj_c.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, tmp * 1000.0);
    HITL_HEXA_WOPOSCTRL_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter4'

    // Start for MATLABSystem: '<S6>/Read Parameter5'
    HITL_HEXA_WOPOSCTRL_DW.obj_p1.matlabCodegenIsDeleted = false;
    HITL_HEXA_WOPOSCTRL_DW.obj_p1.SampleTime =
      HITL_HEXA_WOPOSCTRL_P.ReadParameter5_SampleTime;
    HITL_HEXA_WOPOSCTRL_DW.obj_p1.isInitialized = 1;
    if (HITL_HEXA_WOPOSCTRL_DW.obj_p1.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = HITL_HEXA_WOPOSCTRL_DW.obj_p1.SampleTime;
    }

    HITL_HEXA_WOPOSCTRL_DW.obj_p1.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, tmp * 1000.0);
    HITL_HEXA_WOPOSCTRL_DW.obj_p1.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter5'

    // Start for MATLABSystem: '<S23>/PX4 Timestamp'
    HITL_HEXA_WOPOSCTRL_DW.obj_kn.matlabCodegenIsDeleted = false;
    HITL_HEXA_WOPOSCTRL_DW.obj_kn.isInitialized = 1;
    HITL_HEXA_WOPOSCTRL_DW.obj_kn.isSetupComplete = true;

    // Start for MATLABSystem: '<S29>/SinkBlock' incorporates:
    //   BusAssignment: '<S23>/Bus Assignment'

    HITL_HEXA_WOPOSCTRL_DW.obj_dz.matlabCodegenIsDeleted = false;
    HITL_HEXA_WOPOSCTRL_DW.obj_dz.isInitialized = 1;
    HITL_HEXA_WOPOSCTRL_DW.obj_dz.orbMetadataObj = ORB_ID(vehicle_rates_setpoint);
    uORB_write_initialize(HITL_HEXA_WOPOSCTRL_DW.obj_dz.orbMetadataObj,
                          &HITL_HEXA_WOPOSCTRL_DW.obj_dz.orbAdvertiseObj,
                          &rtb_BusAssignment_p, 1);
    HITL_HEXA_WOPOSCTRL_DW.obj_dz.isSetupComplete = true;

    // Start for MATLABSystem: '<S21>/SinkBlock' incorporates:
    //   BusAssignment: '<S9>/Bus Assignment'

    HITL_HEXA_WOPOSCTRL_DW.obj_hy.matlabCodegenIsDeleted = false;
    HITL_HEXA_WOPOSCTRL_DW.obj_hy.isInitialized = 1;
    HITL_HEXA_WOPOSCTRL_DW.obj_hy.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_write_initialize(HITL_HEXA_WOPOSCTRL_DW.obj_hy.orbMetadataObj,
                          &HITL_HEXA_WOPOSCTRL_DW.obj_hy.orbAdvertiseObj,
                          &HITL_HEXA_WOPOSCTRL_B.BusAssignment_m, 1);
    HITL_HEXA_WOPOSCTRL_DW.obj_hy.isSetupComplete = true;
  }
}

// Model terminate function
void HITL_HEXA_WOPOSCTRL_terminate(void)
{
  // Terminate for MATLABSystem: '<S18>/SourceBlock'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_da.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_da.matlabCodegenIsDeleted = true;
    if ((HITL_HEXA_WOPOSCTRL_DW.obj_da.isInitialized == 1) &&
        HITL_HEXA_WOPOSCTRL_DW.obj_da.isSetupComplete) {
      uORB_read_terminate(&HITL_HEXA_WOPOSCTRL_DW.obj_da.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S18>/SourceBlock'

  // Terminate for MATLABSystem: '<S346>/SourceBlock'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_po.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_po.matlabCodegenIsDeleted = true;
    if ((HITL_HEXA_WOPOSCTRL_DW.obj_po.isInitialized == 1) &&
        HITL_HEXA_WOPOSCTRL_DW.obj_po.isSetupComplete) {
      uORB_read_terminate(&HITL_HEXA_WOPOSCTRL_DW.obj_po.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S346>/SourceBlock'

  // Terminate for MATLABSystem: '<S347>/SourceBlock'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_d0.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_d0.matlabCodegenIsDeleted = true;
    if ((HITL_HEXA_WOPOSCTRL_DW.obj_d0.isInitialized == 1) &&
        HITL_HEXA_WOPOSCTRL_DW.obj_d0.isSetupComplete) {
      uORB_read_terminate(&HITL_HEXA_WOPOSCTRL_DW.obj_d0.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S347>/SourceBlock'

  // Terminate for MATLABSystem: '<S349>/SourceBlock'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_mg.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_mg.matlabCodegenIsDeleted = true;
    if ((HITL_HEXA_WOPOSCTRL_DW.obj_mg.isInitialized == 1) &&
        HITL_HEXA_WOPOSCTRL_DW.obj_mg.isSetupComplete) {
      uORB_read_terminate(&HITL_HEXA_WOPOSCTRL_DW.obj_mg.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S349>/SourceBlock'

  // Terminate for MATLABSystem: '<S348>/SourceBlock'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_gv.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_gv.matlabCodegenIsDeleted = true;
    if ((HITL_HEXA_WOPOSCTRL_DW.obj_gv.isInitialized == 1) &&
        HITL_HEXA_WOPOSCTRL_DW.obj_gv.isSetupComplete) {
      uORB_read_terminate(&HITL_HEXA_WOPOSCTRL_DW.obj_gv.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S348>/SourceBlock'

  // Terminate for Enabled SubSystem: '<S22>/mc_att_controller'
  HITL_HEXA_WOPOSCTRL_mc_att_controller_Term();

  // End of Terminate for SubSystem: '<S22>/mc_att_controller'

  // Terminate for Enabled SubSystem: '<S22>/mc_rate_controller'
  HITL_HEXA_WOPOSCTRL_mc_rate_controller_Term();

  // End of Terminate for SubSystem: '<S22>/mc_rate_controller'

  // Terminate for MATLABSystem: '<S6>/Read Parameter13'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_ka.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_ka.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter13'

  // Terminate for MATLABSystem: '<S6>/Read Parameter1'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_a.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter1'

  // Terminate for MATLABSystem: '<S6>/Read Parameter2'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_ng.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_ng.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter2'

  // Terminate for MATLABSystem: '<S6>/Read Parameter3'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_n0.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_n0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter3'

  // Terminate for MATLABSystem: '<S6>/Read Parameter4'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_c.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter4'

  // Terminate for MATLABSystem: '<S6>/Read Parameter5'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_p1.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_p1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter5'

  // Terminate for MATLABSystem: '<S23>/PX4 Timestamp'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_kn.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_kn.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S23>/PX4 Timestamp'

  // Terminate for MATLABSystem: '<S29>/SinkBlock'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_dz.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_dz.matlabCodegenIsDeleted = true;
    if ((HITL_HEXA_WOPOSCTRL_DW.obj_dz.isInitialized == 1) &&
        HITL_HEXA_WOPOSCTRL_DW.obj_dz.isSetupComplete) {
      uORB_write_terminate(&HITL_HEXA_WOPOSCTRL_DW.obj_dz.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S29>/SinkBlock'

  // Terminate for MATLABSystem: '<S21>/SinkBlock'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_hy.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_hy.matlabCodegenIsDeleted = true;
    if ((HITL_HEXA_WOPOSCTRL_DW.obj_hy.isInitialized == 1) &&
        HITL_HEXA_WOPOSCTRL_DW.obj_hy.isSetupComplete) {
      uORB_write_terminate(&HITL_HEXA_WOPOSCTRL_DW.obj_hy.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S21>/SinkBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
