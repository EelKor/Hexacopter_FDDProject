//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mc_rate_controller.cpp
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
#include "mc_rate_controller.h"
#include "SITL_HEXA_MISSION.h"
#include "rtwtypes.h"
#include "SITL_HEXA_MISSION_private.h"

// System initialize for enable system: '<S5>/mc_rate_controller'
void SITL_HEXA_MISSION_mc_rate_controller_Init(void)
{
  // InitializeConditions for DiscreteIntegrator: '<S430>/Integrator'
  SITL_HEXA_MISSION_DW.Integrator_DSTATE =
    SITL_HEXA_MISSION_P.PIDController_InitialConditionForIntegrator;

  // InitializeConditions for DiscreteIntegrator: '<S425>/Filter'
  SITL_HEXA_MISSION_DW.Filter_DSTATE =
    SITL_HEXA_MISSION_P.PIDController_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S482>/Integrator'
  SITL_HEXA_MISSION_DW.Integrator_DSTATE_d =
    SITL_HEXA_MISSION_P.PIDController1_InitialConditionForIntegrator;

  // InitializeConditions for DiscreteIntegrator: '<S477>/Filter'
  SITL_HEXA_MISSION_DW.Filter_DSTATE_h =
    SITL_HEXA_MISSION_P.PIDController1_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S534>/Integrator'
  SITL_HEXA_MISSION_DW.Integrator_DSTATE_dd =
    SITL_HEXA_MISSION_P.PIDController2_InitialConditionForIntegrator;

  // InitializeConditions for DiscreteIntegrator: '<S529>/Filter'
  SITL_HEXA_MISSION_DW.Filter_DSTATE_l =
    SITL_HEXA_MISSION_P.PIDController2_InitialConditionForFilter;

  // SystemInitialize for Saturate: '<S437>/Saturation' incorporates:
  //   Outport: '<S13>/tau_yaw'

  SITL_HEXA_MISSION_B.Saturation = SITL_HEXA_MISSION_P.tau_yaw_Y0;

  // SystemInitialize for Saturate: '<S489>/Saturation' incorporates:
  //   Outport: '<S13>/tau_pitch'

  SITL_HEXA_MISSION_B.Saturation_c = SITL_HEXA_MISSION_P.tau_pitch_Y0;

  // SystemInitialize for Saturate: '<S541>/Saturation' incorporates:
  //   Outport: '<S13>/tau_roll'

  SITL_HEXA_MISSION_B.Saturation_b = SITL_HEXA_MISSION_P.tau_roll_Y0;
}

// Output and update for enable system: '<S5>/mc_rate_controller'
void SITL_HEXA_MISSION_mc_rate_controller(void)
{
  // Outputs for Enabled SubSystem: '<S5>/mc_rate_controller' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (SITL_HEXA_MISSION_B.In1_b.armed) {
    real_T rtb_DeadZone;
    real_T rtb_FilterCoefficient;
    real_T rtb_FilterCoefficient_a;
    real_T rtb_FilterCoefficient_o;
    real_T rtb_Filter_g;
    real_T rtb_Filter_n;
    real_T rtb_Integrator_a;
    int8_T tmp;
    int8_T tmp_0;
    int8_T tmp_1;
    int8_T tmp_2;
    boolean_T rtb_RelationalOperator_e;
    boolean_T rtb_RelationalOperator_m;

    // Sum: '<S13>/Sum4'
    SITL_HEXA_MISSION_B.Filter_j = SITL_HEXA_MISSION_B.Saturation_e -
      SITL_HEXA_MISSION_B.DataTypeConversion2[2];

    // Gain: '<S427>/Integral Gain'
    rtb_Integrator_a = SITL_HEXA_MISSION_P.MC_YAWRATE_I *
      SITL_HEXA_MISSION_B.Filter_j;

    // Gain: '<S433>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S425>/Filter'
    //   Gain: '<S423>/Derivative Gain'
    //   Sum: '<S425>/SumD'

    rtb_FilterCoefficient = (SITL_HEXA_MISSION_P.MC_YAWRATE_D *
      SITL_HEXA_MISSION_B.Filter_j - SITL_HEXA_MISSION_DW.Filter_DSTATE) *
      SITL_HEXA_MISSION_P.PIDController_N;

    // Sum: '<S439>/Sum' incorporates:
    //   DiscreteIntegrator: '<S430>/Integrator'
    //   Gain: '<S435>/Proportional Gain'

    SITL_HEXA_MISSION_B.Filter_j = (SITL_HEXA_MISSION_P.MC_YAWRATE_P *
      SITL_HEXA_MISSION_B.Filter_j + SITL_HEXA_MISSION_DW.Integrator_DSTATE) +
      rtb_FilterCoefficient;

    // DeadZone: '<S422>/DeadZone'
    if (SITL_HEXA_MISSION_B.Filter_j >
        SITL_HEXA_MISSION_P.PIDController_UpperSaturationLimit_p) {
      rtb_Filter_n = SITL_HEXA_MISSION_B.Filter_j -
        SITL_HEXA_MISSION_P.PIDController_UpperSaturationLimit_p;
    } else if (SITL_HEXA_MISSION_B.Filter_j >=
               SITL_HEXA_MISSION_P.PIDController_LowerSaturationLimit_b) {
      rtb_Filter_n = 0.0;
    } else {
      rtb_Filter_n = SITL_HEXA_MISSION_B.Filter_j -
        SITL_HEXA_MISSION_P.PIDController_LowerSaturationLimit_b;
    }

    // End of DeadZone: '<S422>/DeadZone'

    // Switch: '<S420>/Switch1' incorporates:
    //   Constant: '<S420>/Clamping_zero'
    //   Constant: '<S420>/Constant'
    //   Constant: '<S420>/Constant2'
    //   RelationalOperator: '<S420>/fix for DT propagation issue'

    if (rtb_Filter_n > SITL_HEXA_MISSION_P.Clamping_zero_Value_i) {
      tmp = SITL_HEXA_MISSION_P.Constant_Value_dt;
    } else {
      tmp = SITL_HEXA_MISSION_P.Constant2_Value_l;
    }

    // Switch: '<S420>/Switch2' incorporates:
    //   Constant: '<S420>/Clamping_zero'
    //   Constant: '<S420>/Constant3'
    //   Constant: '<S420>/Constant4'
    //   RelationalOperator: '<S420>/fix for DT propagation issue1'

    if (rtb_Integrator_a > SITL_HEXA_MISSION_P.Clamping_zero_Value_i) {
      tmp_0 = SITL_HEXA_MISSION_P.Constant3_Value_j;
    } else {
      tmp_0 = SITL_HEXA_MISSION_P.Constant4_Value_c;
    }

    // RelationalOperator: '<S420>/Relational Operator' incorporates:
    //   Constant: '<S420>/Clamping_zero'

    rtb_RelationalOperator_e = (SITL_HEXA_MISSION_P.Clamping_zero_Value_i !=
      rtb_Filter_n);

    // Saturate: '<S437>/Saturation'
    if (SITL_HEXA_MISSION_B.Filter_j >
        SITL_HEXA_MISSION_P.PIDController_UpperSaturationLimit_p) {
      // Saturate: '<S437>/Saturation'
      SITL_HEXA_MISSION_B.Saturation =
        SITL_HEXA_MISSION_P.PIDController_UpperSaturationLimit_p;
    } else if (SITL_HEXA_MISSION_B.Filter_j <
               SITL_HEXA_MISSION_P.PIDController_LowerSaturationLimit_b) {
      // Saturate: '<S437>/Saturation'
      SITL_HEXA_MISSION_B.Saturation =
        SITL_HEXA_MISSION_P.PIDController_LowerSaturationLimit_b;
    } else {
      // Saturate: '<S437>/Saturation'
      SITL_HEXA_MISSION_B.Saturation = SITL_HEXA_MISSION_B.Filter_j;
    }

    // End of Saturate: '<S437>/Saturation'

    // Sum: '<S13>/Sum'
    rtb_Filter_n = SITL_HEXA_MISSION_B.ProportionalGain -
      SITL_HEXA_MISSION_B.DataTypeConversion2[1];

    // Gain: '<S479>/Integral Gain'
    SITL_HEXA_MISSION_B.Filter_j = SITL_HEXA_MISSION_P.MC_PITCHRATE_I *
      rtb_Filter_n;

    // Gain: '<S485>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S477>/Filter'
    //   Gain: '<S475>/Derivative Gain'
    //   Sum: '<S477>/SumD'

    rtb_FilterCoefficient_o = (SITL_HEXA_MISSION_P.MC_PITCHRATE_D * rtb_Filter_n
      - SITL_HEXA_MISSION_DW.Filter_DSTATE_h) *
      SITL_HEXA_MISSION_P.PIDController1_N;

    // Sum: '<S491>/Sum' incorporates:
    //   DiscreteIntegrator: '<S482>/Integrator'
    //   Gain: '<S487>/Proportional Gain'

    rtb_Filter_n = (SITL_HEXA_MISSION_P.MC_PITCHRATE_P * rtb_Filter_n +
                    SITL_HEXA_MISSION_DW.Integrator_DSTATE_d) +
      rtb_FilterCoefficient_o;

    // DeadZone: '<S474>/DeadZone'
    if (rtb_Filter_n > SITL_HEXA_MISSION_P.PIDController1_UpperSaturationLimit)
    {
      rtb_Filter_g = rtb_Filter_n -
        SITL_HEXA_MISSION_P.PIDController1_UpperSaturationLimit;
    } else if (rtb_Filter_n >=
               SITL_HEXA_MISSION_P.PIDController1_LowerSaturationLimit) {
      rtb_Filter_g = 0.0;
    } else {
      rtb_Filter_g = rtb_Filter_n -
        SITL_HEXA_MISSION_P.PIDController1_LowerSaturationLimit;
    }

    // End of DeadZone: '<S474>/DeadZone'

    // RelationalOperator: '<S472>/Relational Operator' incorporates:
    //   Constant: '<S472>/Clamping_zero'

    rtb_RelationalOperator_m = (SITL_HEXA_MISSION_P.Clamping_zero_Value_d !=
      rtb_Filter_g);

    // Switch: '<S472>/Switch1' incorporates:
    //   Constant: '<S472>/Clamping_zero'
    //   Constant: '<S472>/Constant'
    //   Constant: '<S472>/Constant2'
    //   RelationalOperator: '<S472>/fix for DT propagation issue'

    if (rtb_Filter_g > SITL_HEXA_MISSION_P.Clamping_zero_Value_d) {
      tmp_1 = SITL_HEXA_MISSION_P.Constant_Value_d5;
    } else {
      tmp_1 = SITL_HEXA_MISSION_P.Constant2_Value_e;
    }

    // Switch: '<S472>/Switch2' incorporates:
    //   Constant: '<S472>/Clamping_zero'
    //   Constant: '<S472>/Constant3'
    //   Constant: '<S472>/Constant4'
    //   RelationalOperator: '<S472>/fix for DT propagation issue1'

    if (SITL_HEXA_MISSION_B.Filter_j > SITL_HEXA_MISSION_P.Clamping_zero_Value_d)
    {
      tmp_2 = SITL_HEXA_MISSION_P.Constant3_Value_k;
    } else {
      tmp_2 = SITL_HEXA_MISSION_P.Constant4_Value_n;
    }

    // Saturate: '<S489>/Saturation'
    if (rtb_Filter_n > SITL_HEXA_MISSION_P.PIDController1_UpperSaturationLimit)
    {
      // Saturate: '<S489>/Saturation'
      SITL_HEXA_MISSION_B.Saturation_c =
        SITL_HEXA_MISSION_P.PIDController1_UpperSaturationLimit;
    } else if (rtb_Filter_n <
               SITL_HEXA_MISSION_P.PIDController1_LowerSaturationLimit) {
      // Saturate: '<S489>/Saturation'
      SITL_HEXA_MISSION_B.Saturation_c =
        SITL_HEXA_MISSION_P.PIDController1_LowerSaturationLimit;
    } else {
      // Saturate: '<S489>/Saturation'
      SITL_HEXA_MISSION_B.Saturation_c = rtb_Filter_n;
    }

    // End of Saturate: '<S489>/Saturation'

    // Sum: '<S13>/Sum1'
    rtb_Filter_g = SITL_HEXA_MISSION_B.ProportionalGain_a -
      SITL_HEXA_MISSION_B.DataTypeConversion2[0];

    // Gain: '<S531>/Integral Gain'
    rtb_Filter_n = SITL_HEXA_MISSION_P.MC_ROLLRATE_I * rtb_Filter_g;

    // Gain: '<S537>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S529>/Filter'
    //   Gain: '<S527>/Derivative Gain'
    //   Sum: '<S529>/SumD'

    rtb_FilterCoefficient_a = (SITL_HEXA_MISSION_P.MC_ROLLRATE_D * rtb_Filter_g
      - SITL_HEXA_MISSION_DW.Filter_DSTATE_l) *
      SITL_HEXA_MISSION_P.PIDController2_N;

    // Sum: '<S543>/Sum' incorporates:
    //   DiscreteIntegrator: '<S534>/Integrator'
    //   Gain: '<S539>/Proportional Gain'

    rtb_Filter_g = (SITL_HEXA_MISSION_P.MC_ROLLRATE_P * rtb_Filter_g +
                    SITL_HEXA_MISSION_DW.Integrator_DSTATE_dd) +
      rtb_FilterCoefficient_a;

    // DeadZone: '<S526>/DeadZone' incorporates:
    //   Saturate: '<S541>/Saturation'

    if (rtb_Filter_g > SITL_HEXA_MISSION_P.PIDController2_UpperSaturationLimit)
    {
      rtb_DeadZone = rtb_Filter_g -
        SITL_HEXA_MISSION_P.PIDController2_UpperSaturationLimit;

      // Saturate: '<S541>/Saturation'
      SITL_HEXA_MISSION_B.Saturation_b =
        SITL_HEXA_MISSION_P.PIDController2_UpperSaturationLimit;
    } else {
      if (rtb_Filter_g >=
          SITL_HEXA_MISSION_P.PIDController2_LowerSaturationLimit) {
        rtb_DeadZone = 0.0;
      } else {
        rtb_DeadZone = rtb_Filter_g -
          SITL_HEXA_MISSION_P.PIDController2_LowerSaturationLimit;
      }

      if (rtb_Filter_g < SITL_HEXA_MISSION_P.PIDController2_LowerSaturationLimit)
      {
        // Saturate: '<S541>/Saturation'
        SITL_HEXA_MISSION_B.Saturation_b =
          SITL_HEXA_MISSION_P.PIDController2_LowerSaturationLimit;
      } else {
        // Saturate: '<S541>/Saturation'
        SITL_HEXA_MISSION_B.Saturation_b = rtb_Filter_g;
      }
    }

    // End of DeadZone: '<S526>/DeadZone'

    // Switch: '<S420>/Switch' incorporates:
    //   Constant: '<S420>/Constant1'
    //   Logic: '<S420>/AND3'
    //   RelationalOperator: '<S420>/Equal1'
    //   Switch: '<S420>/Switch1'
    //   Switch: '<S420>/Switch2'

    if (rtb_RelationalOperator_e && (tmp == tmp_0)) {
      rtb_Integrator_a = SITL_HEXA_MISSION_P.Constant1_Value_k;
    }

    // Update for DiscreteIntegrator: '<S430>/Integrator' incorporates:
    //   Switch: '<S420>/Switch'

    SITL_HEXA_MISSION_DW.Integrator_DSTATE +=
      SITL_HEXA_MISSION_P.Integrator_gainval_h * rtb_Integrator_a;

    // Update for DiscreteIntegrator: '<S425>/Filter'
    SITL_HEXA_MISSION_DW.Filter_DSTATE += SITL_HEXA_MISSION_P.Filter_gainval_f *
      rtb_FilterCoefficient;

    // Switch: '<S472>/Switch' incorporates:
    //   Constant: '<S472>/Constant1'
    //   Logic: '<S472>/AND3'
    //   RelationalOperator: '<S472>/Equal1'
    //   Switch: '<S472>/Switch1'
    //   Switch: '<S472>/Switch2'

    if (rtb_RelationalOperator_m && (tmp_1 == tmp_2)) {
      SITL_HEXA_MISSION_B.Filter_j = SITL_HEXA_MISSION_P.Constant1_Value_j;
    }

    // Update for DiscreteIntegrator: '<S482>/Integrator' incorporates:
    //   Switch: '<S472>/Switch'

    SITL_HEXA_MISSION_DW.Integrator_DSTATE_d +=
      SITL_HEXA_MISSION_P.Integrator_gainval_b * SITL_HEXA_MISSION_B.Filter_j;

    // Update for DiscreteIntegrator: '<S477>/Filter'
    SITL_HEXA_MISSION_DW.Filter_DSTATE_h += SITL_HEXA_MISSION_P.Filter_gainval_l
      * rtb_FilterCoefficient_o;

    // Switch: '<S524>/Switch1' incorporates:
    //   Constant: '<S524>/Clamping_zero'
    //   Constant: '<S524>/Constant'
    //   Constant: '<S524>/Constant2'
    //   RelationalOperator: '<S524>/fix for DT propagation issue'

    if (rtb_DeadZone > SITL_HEXA_MISSION_P.Clamping_zero_Value_e) {
      tmp = SITL_HEXA_MISSION_P.Constant_Value_km;
    } else {
      tmp = SITL_HEXA_MISSION_P.Constant2_Value_m;
    }

    // Switch: '<S524>/Switch2' incorporates:
    //   Constant: '<S524>/Clamping_zero'
    //   Constant: '<S524>/Constant3'
    //   Constant: '<S524>/Constant4'
    //   RelationalOperator: '<S524>/fix for DT propagation issue1'

    if (rtb_Filter_n > SITL_HEXA_MISSION_P.Clamping_zero_Value_e) {
      tmp_0 = SITL_HEXA_MISSION_P.Constant3_Value_d;
    } else {
      tmp_0 = SITL_HEXA_MISSION_P.Constant4_Value_b;
    }

    // Switch: '<S524>/Switch' incorporates:
    //   Constant: '<S524>/Clamping_zero'
    //   Constant: '<S524>/Constant1'
    //   Logic: '<S524>/AND3'
    //   RelationalOperator: '<S524>/Equal1'
    //   RelationalOperator: '<S524>/Relational Operator'
    //   Switch: '<S524>/Switch1'
    //   Switch: '<S524>/Switch2'

    if ((SITL_HEXA_MISSION_P.Clamping_zero_Value_e != rtb_DeadZone) && (tmp ==
         tmp_0)) {
      rtb_Filter_n = SITL_HEXA_MISSION_P.Constant1_Value_ka;
    }

    // Update for DiscreteIntegrator: '<S534>/Integrator' incorporates:
    //   Switch: '<S524>/Switch'

    SITL_HEXA_MISSION_DW.Integrator_DSTATE_dd +=
      SITL_HEXA_MISSION_P.Integrator_gainval_n * rtb_Filter_n;

    // Update for DiscreteIntegrator: '<S529>/Filter'
    SITL_HEXA_MISSION_DW.Filter_DSTATE_l += SITL_HEXA_MISSION_P.Filter_gainval_a
      * rtb_FilterCoefficient_a;
  }

  // End of Outputs for SubSystem: '<S5>/mc_rate_controller'
}

//
// File trailer for generated code.
//
// [EOF]
//
