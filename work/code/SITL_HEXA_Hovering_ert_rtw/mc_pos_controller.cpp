//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mc_pos_controller.cpp
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
#include "mc_pos_controller.h"
#include "SITL_HEXA_Hovering.h"
#include <math.h>
#include "rtwtypes.h"
#include "SITL_HEXA_Hovering_private.h"

// System initialize for enable system: '<S5>/mc_pos_controller'
void SITL_HEXA_Hovering_mc_pos_controller_Init(void)
{
  // InitializeConditions for DiscreteIntegrator: '<S370>/Filter'
  SITL_HEXA_Hovering_DW.Filter_DSTATE_m =
    SITL_HEXA_Hovering_P.PID_vz_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S375>/Integrator'
  SITL_HEXA_Hovering_DW.Integrator_DSTATE_c =
    SITL_HEXA_Hovering_P.PID_vz_InitialConditionForIntegrator;

  // SystemInitialize for Saturate: '<S382>/Saturation' incorporates:
  //   Outport: '<S12>/tau_Thrust'

  SITL_HEXA_Hovering_B.Saturation_d = SITL_HEXA_Hovering_P.tau_Thrust_Y0;

  // SystemInitialize for Outport: '<S12>/des_pitch' incorporates:
  //   Gain: '<S12>/Gain1'

  SITL_HEXA_Hovering_B.Gain1 = SITL_HEXA_Hovering_P.des_pitch_Y0;

  // SystemInitialize for Outport: '<S12>/des_roll'
  SITL_HEXA_Hovering_B.Saturation_n[1] = SITL_HEXA_Hovering_P.des_roll_Y0;

  // SystemInitialize for Saturate: '<S280>/Saturation' incorporates:
  //   Outport: '<S12>/XY_velocity_setpoint'

  SITL_HEXA_Hovering_B.Saturation_bi[0] =
    SITL_HEXA_Hovering_P.XY_velocity_setpoint_Y0;
  SITL_HEXA_Hovering_B.Saturation_bi[1] =
    SITL_HEXA_Hovering_P.XY_velocity_setpoint_Y0;

  // SystemInitialize for Saturate: '<S330>/Saturation' incorporates:
  //   Outport: '<S12>/Z_velocity_setpoint'

  SITL_HEXA_Hovering_B.Saturation_o =
    SITL_HEXA_Hovering_P.Z_velocity_setpoint_Y0;
}

// Output and update for enable system: '<S5>/mc_pos_controller'
void SITL_HEXA_Hovering_mc_pos_controller(void)
{
  // Outputs for Enabled SubSystem: '<S5>/mc_pos_controller' incorporates:
  //   EnablePort: '<S12>/Enable'

  if (SITL_HEXA_Hovering_B.In1_b.armed) {
    real_T rtb_FilterCoefficient;
    real_T rtb_Gain;
    real_T rtb_Gain1;
    real_T rtb_SinCos_o1;
    real_T tmp;
    real_T u0;
    real_T y_tmp;
    int8_T tmp_0;
    int8_T tmp_1;

    // Gain: '<S183>/Gain1'
    rtb_Gain1 = SITL_HEXA_Hovering_P.Gain1_Gain *
      SITL_HEXA_Hovering_B.DataTypeConversion1[2];

    // Switch: '<S189>/Switch' incorporates:
    //   Constant: '<S183>/Constant'
    //   RelationalOperator: '<S189>/UpperRelop'
    //   Switch: '<S189>/Switch2'

    if (rtb_Gain1 < SITL_HEXA_Hovering_P.Constant_Value_j4) {
      rtb_Gain1 = SITL_HEXA_Hovering_P.Constant_Value_j4;
    }

    // Gain: '<S328>/Proportional Gain' incorporates:
    //   Sum: '<S12>/Sum2'
    //   Switch: '<S189>/Switch'
    //   Switch: '<S189>/Switch2'

    u0 = (SITL_HEXA_Hovering_B.desiredZ - rtb_Gain1) *
      SITL_HEXA_Hovering_P.MPC_Z_P;

    // Saturate: '<S330>/Saturation'
    rtb_Gain1 = -fabs(SITL_HEXA_Hovering_P.MPC_Z_VEL_MAX_DN);
    if (u0 > SITL_HEXA_Hovering_P.MPC_Z_VEL_MAX_UP) {
      // Saturate: '<S330>/Saturation'
      SITL_HEXA_Hovering_B.Saturation_o = SITL_HEXA_Hovering_P.MPC_Z_VEL_MAX_UP;
    } else if (u0 < rtb_Gain1) {
      // Saturate: '<S330>/Saturation'
      SITL_HEXA_Hovering_B.Saturation_o = rtb_Gain1;
    } else {
      // Saturate: '<S330>/Saturation'
      SITL_HEXA_Hovering_B.Saturation_o = u0;
    }

    // End of Saturate: '<S330>/Saturation'

    // Sum: '<S12>/Sum3' incorporates:
    //   UnaryMinus: '<S12>/Unary Minus'

    rtb_Gain = SITL_HEXA_Hovering_B.Saturation_o -
      (-SITL_HEXA_Hovering_B.DataTypeConversion1[5]);

    // Gain: '<S380>/Proportional Gain'
    rtb_Gain1 = SITL_HEXA_Hovering_P.MPC_Z_VEL_P_ACC * rtb_Gain;

    // Gain: '<S378>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S370>/Filter'
    //   Gain: '<S368>/Derivative Gain'
    //   Sum: '<S370>/SumD'

    rtb_FilterCoefficient = (SITL_HEXA_Hovering_P.MPC_Z_VEL_D_ACC * rtb_Gain -
      SITL_HEXA_Hovering_DW.Filter_DSTATE_m) * SITL_HEXA_Hovering_P.PID_vz_N;

    // Sum: '<S385>/Sum Fdbk'
    rtb_SinCos_o1 = (rtb_Gain1 + SITL_HEXA_Hovering_DW.Integrator_DSTATE_c) +
      rtb_FilterCoefficient;

    // DeadZone: '<S367>/DeadZone'
    if (rtb_SinCos_o1 > SITL_HEXA_Hovering_P.PID_vz_UpperSaturationLimit) {
      rtb_SinCos_o1 -= SITL_HEXA_Hovering_P.PID_vz_UpperSaturationLimit;
    } else if (rtb_SinCos_o1 >= SITL_HEXA_Hovering_P.PID_vz_LowerSaturationLimit)
    {
      rtb_SinCos_o1 = 0.0;
    } else {
      rtb_SinCos_o1 -= SITL_HEXA_Hovering_P.PID_vz_LowerSaturationLimit;
    }

    // End of DeadZone: '<S367>/DeadZone'

    // Gain: '<S372>/Integral Gain'
    rtb_Gain *= SITL_HEXA_Hovering_P.MPC_Z_VEL_I_ACC;

    // Switch: '<S365>/Switch1' incorporates:
    //   Constant: '<S365>/Clamping_zero'
    //   Constant: '<S365>/Constant'
    //   Constant: '<S365>/Constant2'
    //   RelationalOperator: '<S365>/fix for DT propagation issue'

    if (rtb_SinCos_o1 > SITL_HEXA_Hovering_P.Clamping_zero_Value) {
      tmp_0 = SITL_HEXA_Hovering_P.Constant_Value_mp;
    } else {
      tmp_0 = SITL_HEXA_Hovering_P.Constant2_Value_k;
    }

    // Switch: '<S365>/Switch2' incorporates:
    //   Constant: '<S365>/Clamping_zero'
    //   Constant: '<S365>/Constant3'
    //   Constant: '<S365>/Constant4'
    //   RelationalOperator: '<S365>/fix for DT propagation issue1'

    if (rtb_Gain > SITL_HEXA_Hovering_P.Clamping_zero_Value) {
      tmp_1 = SITL_HEXA_Hovering_P.Constant3_Value_i;
    } else {
      tmp_1 = SITL_HEXA_Hovering_P.Constant4_Value_j;
    }

    // Switch: '<S365>/Switch' incorporates:
    //   Constant: '<S365>/Clamping_zero'
    //   Constant: '<S365>/Constant1'
    //   Logic: '<S365>/AND3'
    //   RelationalOperator: '<S365>/Equal1'
    //   RelationalOperator: '<S365>/Relational Operator'
    //   Switch: '<S365>/Switch1'
    //   Switch: '<S365>/Switch2'

    if ((SITL_HEXA_Hovering_P.Clamping_zero_Value != rtb_SinCos_o1) && (tmp_0 ==
         tmp_1)) {
      rtb_Gain = SITL_HEXA_Hovering_P.Constant1_Value;
    }

    // DiscreteIntegrator: '<S375>/Integrator' incorporates:
    //   Switch: '<S365>/Switch'

    rtb_Gain = SITL_HEXA_Hovering_P.Integrator_gainval * rtb_Gain +
      SITL_HEXA_Hovering_DW.Integrator_DSTATE_c;

    // Sum: '<S384>/Sum'
    u0 = (rtb_Gain1 + rtb_Gain) + rtb_FilterCoefficient;

    // Saturate: '<S382>/Saturation'
    if (u0 > SITL_HEXA_Hovering_P.PID_vz_UpperSaturationLimit) {
      // Saturate: '<S382>/Saturation'
      SITL_HEXA_Hovering_B.Saturation_d =
        SITL_HEXA_Hovering_P.PID_vz_UpperSaturationLimit;
    } else if (u0 < SITL_HEXA_Hovering_P.PID_vz_LowerSaturationLimit) {
      // Saturate: '<S382>/Saturation'
      SITL_HEXA_Hovering_B.Saturation_d =
        SITL_HEXA_Hovering_P.PID_vz_LowerSaturationLimit;
    } else {
      // Saturate: '<S382>/Saturation'
      SITL_HEXA_Hovering_B.Saturation_d = u0;
    }

    // End of Saturate: '<S382>/Saturation'

    // Trigonometry: '<S184>/SinCos'
    rtb_SinCos_o1 = sin(SITL_HEXA_Hovering_B.VectorConcatenate[0]);
    rtb_Gain1 = cos(SITL_HEXA_Hovering_B.VectorConcatenate[0]);

    // Saturate: '<S280>/Saturation'
    y_tmp = fabs(SITL_HEXA_Hovering_P.MPC_XY_VEL_MAX);

    // Gain: '<S278>/Proportional Gain' incorporates:
    //   Constant: '<S5>/Constant'
    //   Sum: '<S12>/Sum1'

    u0 = (SITL_HEXA_Hovering_P.Constant_Value_n5 -
          SITL_HEXA_Hovering_B.DataTypeConversion1[0]) *
      SITL_HEXA_Hovering_P.MPC_XY_P;

    // Saturate: '<S280>/Saturation'
    if (u0 > y_tmp) {
      // Saturate: '<S280>/Saturation'
      SITL_HEXA_Hovering_B.Saturation_bi[0] = y_tmp;
    } else if (u0 < -y_tmp) {
      // Saturate: '<S280>/Saturation'
      SITL_HEXA_Hovering_B.Saturation_bi[0] = -y_tmp;
    } else {
      // Saturate: '<S280>/Saturation'
      SITL_HEXA_Hovering_B.Saturation_bi[0] = u0;
    }

    // Gain: '<S278>/Proportional Gain' incorporates:
    //   Constant: '<S5>/Constant1'
    //   Sum: '<S12>/Sum1'

    u0 = (SITL_HEXA_Hovering_P.Constant1_Value_b -
          SITL_HEXA_Hovering_B.DataTypeConversion1[1]) *
      SITL_HEXA_Hovering_P.MPC_XY_P;

    // Saturate: '<S280>/Saturation'
    if (u0 > y_tmp) {
      // Saturate: '<S280>/Saturation'
      SITL_HEXA_Hovering_B.Saturation_bi[1] = y_tmp;
    } else if (u0 < -y_tmp) {
      // Saturate: '<S280>/Saturation'
      SITL_HEXA_Hovering_B.Saturation_bi[1] = -y_tmp;
    } else {
      // Saturate: '<S280>/Saturation'
      SITL_HEXA_Hovering_B.Saturation_bi[1] = u0;
    }

    // Sum: '<S12>/Sum'
    y_tmp = SITL_HEXA_Hovering_B.Saturation_bi[0] -
      SITL_HEXA_Hovering_B.DataTypeConversion1[3];
    tmp = SITL_HEXA_Hovering_B.Saturation_bi[1] -
      SITL_HEXA_Hovering_B.DataTypeConversion1[4];

    // Saturate: '<S230>/Saturation' incorporates:
    //   Gain: '<S184>/Gain'
    //   Gain: '<S228>/Proportional Gain'
    //   Product: '<S12>/MatrixMultiply'
    //   Reshape: '<S184>/Reshape'
    //   Reshape: '<S184>/Reshape1'

    u0 = (rtb_Gain1 * y_tmp + rtb_SinCos_o1 * tmp) *
      SITL_HEXA_Hovering_P.PIDController_P;
    if (u0 > SITL_HEXA_Hovering_P.PIDController_UpperSaturationLimit) {
      SITL_HEXA_Hovering_B.Saturation_n[0] =
        SITL_HEXA_Hovering_P.PIDController_UpperSaturationLimit;
    } else if (u0 < SITL_HEXA_Hovering_P.PIDController_LowerSaturationLimit) {
      SITL_HEXA_Hovering_B.Saturation_n[0] =
        SITL_HEXA_Hovering_P.PIDController_LowerSaturationLimit;
    } else {
      SITL_HEXA_Hovering_B.Saturation_n[0] = u0;
    }

    u0 = (SITL_HEXA_Hovering_P.Gain_Gain * rtb_SinCos_o1 * y_tmp + rtb_Gain1 *
          tmp) * SITL_HEXA_Hovering_P.PIDController_P;
    if (u0 > SITL_HEXA_Hovering_P.PIDController_UpperSaturationLimit) {
      SITL_HEXA_Hovering_B.Saturation_n[1] =
        SITL_HEXA_Hovering_P.PIDController_UpperSaturationLimit;
    } else if (u0 < SITL_HEXA_Hovering_P.PIDController_LowerSaturationLimit) {
      SITL_HEXA_Hovering_B.Saturation_n[1] =
        SITL_HEXA_Hovering_P.PIDController_LowerSaturationLimit;
    } else {
      SITL_HEXA_Hovering_B.Saturation_n[1] = u0;
    }

    // End of Saturate: '<S230>/Saturation'

    // Gain: '<S12>/Gain1'
    SITL_HEXA_Hovering_B.Gain1 = SITL_HEXA_Hovering_P.Gain1_Gain_f *
      SITL_HEXA_Hovering_B.Saturation_n[0];

    // Update for DiscreteIntegrator: '<S370>/Filter'
    SITL_HEXA_Hovering_DW.Filter_DSTATE_m += SITL_HEXA_Hovering_P.Filter_gainval
      * rtb_FilterCoefficient;

    // Update for DiscreteIntegrator: '<S375>/Integrator'
    SITL_HEXA_Hovering_DW.Integrator_DSTATE_c = rtb_Gain;
  }

  // End of Outputs for SubSystem: '<S5>/mc_pos_controller'
}

//
// File trailer for generated code.
//
// [EOF]
//
