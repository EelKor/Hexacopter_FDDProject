//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mc_rate_controller.cpp
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
#include "mc_rate_controller.h"
#include "HITL_HEXA_WOPOSCTRL.h"
#include "rtwtypes.h"
#include "HITL_HEXA_WOPOSCTRL_private.h"

// System initialize for enable system: '<S22>/mc_rate_controller'
void HITL_HEXA_WOPOSCTRL_mc_rate_controller_Init(void)
{
  static const char_T ParameterNameStr[13] = "SL_YAWRATE_D";
  static const char_T ParameterNameStr_0[13] = "SL_YAWRATE_P";
  static const char_T ParameterNameStr_1[13] = "SL_YAWRATE_I";
  static const char_T ParameterNameStr_2[15] = "SL_PITCHRATE_D";
  static const char_T ParameterNameStr_3[15] = "SL_PITCHRATE_P";
  static const char_T ParameterNameStr_4[15] = "SL_PITCHRATE_I";
  static const char_T ParameterNameStr_5[14] = "SL_ROLLRATE_D";
  static const char_T ParameterNameStr_6[14] = "SL_ROLLRATE_P";
  static const char_T ParameterNameStr_7[14] = "SL_ROLLRATE_I";
  real_T tmp;

  // InitializeConditions for DiscreteIntegrator: '<S224>/Filter'
  HITL_HEXA_WOPOSCTRL_DW.Filter_DSTATE =
    HITL_HEXA_WOPOSCTRL_P.PIDController_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S229>/Integrator'
  HITL_HEXA_WOPOSCTRL_DW.Integrator_DSTATE =
    HITL_HEXA_WOPOSCTRL_P.PIDController_InitialConditionForIntegrator;

  // InitializeConditions for DiscreteIntegrator: '<S274>/Filter'
  HITL_HEXA_WOPOSCTRL_DW.Filter_DSTATE_h =
    HITL_HEXA_WOPOSCTRL_P.PIDController1_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S279>/Integrator'
  HITL_HEXA_WOPOSCTRL_DW.Integrator_DSTATE_d =
    HITL_HEXA_WOPOSCTRL_P.PIDController1_InitialConditionForIntegrator;

  // InitializeConditions for DiscreteIntegrator: '<S324>/Filter'
  HITL_HEXA_WOPOSCTRL_DW.Filter_DSTATE_l =
    HITL_HEXA_WOPOSCTRL_P.PIDController2_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S329>/Integrator'
  HITL_HEXA_WOPOSCTRL_DW.Integrator_DSTATE_dd =
    HITL_HEXA_WOPOSCTRL_P.PIDController2_InitialConditionForIntegrator;

  // Start for MATLABSystem: '<S27>/Read Parameter21'
  HITL_HEXA_WOPOSCTRL_DW.obj_j.matlabCodegenIsDeleted = false;
  HITL_HEXA_WOPOSCTRL_DW.obj_j.SampleTime =
    HITL_HEXA_WOPOSCTRL_P.ReadParameter21_SampleTime;
  HITL_HEXA_WOPOSCTRL_DW.obj_j.isInitialized = 1;
  if (HITL_HEXA_WOPOSCTRL_DW.obj_j.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_WOPOSCTRL_DW.obj_j.SampleTime;
  }

  HITL_HEXA_WOPOSCTRL_DW.obj_j.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr
    [0], true, tmp * 1000.0);
  HITL_HEXA_WOPOSCTRL_DW.obj_j.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S27>/Read Parameter21'

  // Start for MATLABSystem: '<S27>/Read Parameter19'
  HITL_HEXA_WOPOSCTRL_DW.obj_n.matlabCodegenIsDeleted = false;
  HITL_HEXA_WOPOSCTRL_DW.obj_n.SampleTime =
    HITL_HEXA_WOPOSCTRL_P.ReadParameter19_SampleTime;
  HITL_HEXA_WOPOSCTRL_DW.obj_n.isInitialized = 1;
  if (HITL_HEXA_WOPOSCTRL_DW.obj_n.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_WOPOSCTRL_DW.obj_n.SampleTime;
  }

  HITL_HEXA_WOPOSCTRL_DW.obj_n.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_0[0], true, tmp * 1000.0);
  HITL_HEXA_WOPOSCTRL_DW.obj_n.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S27>/Read Parameter19'

  // Start for MATLABSystem: '<S27>/Read Parameter20'
  HITL_HEXA_WOPOSCTRL_DW.obj_l.matlabCodegenIsDeleted = false;
  HITL_HEXA_WOPOSCTRL_DW.obj_l.SampleTime =
    HITL_HEXA_WOPOSCTRL_P.ReadParameter20_SampleTime;
  HITL_HEXA_WOPOSCTRL_DW.obj_l.isInitialized = 1;
  if (HITL_HEXA_WOPOSCTRL_DW.obj_l.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_WOPOSCTRL_DW.obj_l.SampleTime;
  }

  HITL_HEXA_WOPOSCTRL_DW.obj_l.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_1[0], true, tmp * 1000.0);
  HITL_HEXA_WOPOSCTRL_DW.obj_l.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S27>/Read Parameter20'

  // Start for MATLABSystem: '<S27>/Read Parameter18'
  HITL_HEXA_WOPOSCTRL_DW.obj_h.matlabCodegenIsDeleted = false;
  HITL_HEXA_WOPOSCTRL_DW.obj_h.SampleTime =
    HITL_HEXA_WOPOSCTRL_P.ReadParameter18_SampleTime;
  HITL_HEXA_WOPOSCTRL_DW.obj_h.isInitialized = 1;
  if (HITL_HEXA_WOPOSCTRL_DW.obj_h.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_WOPOSCTRL_DW.obj_h.SampleTime;
  }

  HITL_HEXA_WOPOSCTRL_DW.obj_h.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_2[0], true, tmp * 1000.0);
  HITL_HEXA_WOPOSCTRL_DW.obj_h.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S27>/Read Parameter18'

  // Start for MATLABSystem: '<S27>/Read Parameter16'
  HITL_HEXA_WOPOSCTRL_DW.obj_g.matlabCodegenIsDeleted = false;
  HITL_HEXA_WOPOSCTRL_DW.obj_g.SampleTime =
    HITL_HEXA_WOPOSCTRL_P.ReadParameter16_SampleTime;
  HITL_HEXA_WOPOSCTRL_DW.obj_g.isInitialized = 1;
  if (HITL_HEXA_WOPOSCTRL_DW.obj_g.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_WOPOSCTRL_DW.obj_g.SampleTime;
  }

  HITL_HEXA_WOPOSCTRL_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_3[0], true, tmp * 1000.0);
  HITL_HEXA_WOPOSCTRL_DW.obj_g.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S27>/Read Parameter16'

  // Start for MATLABSystem: '<S27>/Read Parameter17'
  HITL_HEXA_WOPOSCTRL_DW.obj_hj.matlabCodegenIsDeleted = false;
  HITL_HEXA_WOPOSCTRL_DW.obj_hj.SampleTime =
    HITL_HEXA_WOPOSCTRL_P.ReadParameter17_SampleTime;
  HITL_HEXA_WOPOSCTRL_DW.obj_hj.isInitialized = 1;
  if (HITL_HEXA_WOPOSCTRL_DW.obj_hj.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_WOPOSCTRL_DW.obj_hj.SampleTime;
  }

  HITL_HEXA_WOPOSCTRL_DW.obj_hj.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_4[0], true, tmp * 1000.0);
  HITL_HEXA_WOPOSCTRL_DW.obj_hj.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S27>/Read Parameter17'

  // Start for MATLABSystem: '<S27>/Read Parameter24'
  HITL_HEXA_WOPOSCTRL_DW.obj.matlabCodegenIsDeleted = false;
  HITL_HEXA_WOPOSCTRL_DW.obj.SampleTime =
    HITL_HEXA_WOPOSCTRL_P.ReadParameter24_SampleTime;
  HITL_HEXA_WOPOSCTRL_DW.obj.isInitialized = 1;
  if (HITL_HEXA_WOPOSCTRL_DW.obj.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_WOPOSCTRL_DW.obj.SampleTime;
  }

  HITL_HEXA_WOPOSCTRL_DW.obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_5
    [0], true, tmp * 1000.0);
  HITL_HEXA_WOPOSCTRL_DW.obj.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S27>/Read Parameter24'

  // Start for MATLABSystem: '<S27>/Read Parameter22'
  HITL_HEXA_WOPOSCTRL_DW.obj_d.matlabCodegenIsDeleted = false;
  HITL_HEXA_WOPOSCTRL_DW.obj_d.SampleTime =
    HITL_HEXA_WOPOSCTRL_P.ReadParameter22_SampleTime;
  HITL_HEXA_WOPOSCTRL_DW.obj_d.isInitialized = 1;
  if (HITL_HEXA_WOPOSCTRL_DW.obj_d.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_WOPOSCTRL_DW.obj_d.SampleTime;
  }

  HITL_HEXA_WOPOSCTRL_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_6[0], true, tmp * 1000.0);
  HITL_HEXA_WOPOSCTRL_DW.obj_d.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S27>/Read Parameter22'

  // Start for MATLABSystem: '<S27>/Read Parameter23'
  HITL_HEXA_WOPOSCTRL_DW.obj_f.matlabCodegenIsDeleted = false;
  HITL_HEXA_WOPOSCTRL_DW.obj_f.SampleTime =
    HITL_HEXA_WOPOSCTRL_P.ReadParameter23_SampleTime;
  HITL_HEXA_WOPOSCTRL_DW.obj_f.isInitialized = 1;
  if (HITL_HEXA_WOPOSCTRL_DW.obj_f.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = HITL_HEXA_WOPOSCTRL_DW.obj_f.SampleTime;
  }

  HITL_HEXA_WOPOSCTRL_DW.obj_f.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_7[0], true, tmp * 1000.0);
  HITL_HEXA_WOPOSCTRL_DW.obj_f.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S27>/Read Parameter23'

  // SystemInitialize for Saturate: '<S236>/Saturation' incorporates:
  //   Outport: '<S27>/tau_yaw'

  HITL_HEXA_WOPOSCTRL_B.Saturation = HITL_HEXA_WOPOSCTRL_P.tau_yaw_Y0;

  // SystemInitialize for Saturate: '<S286>/Saturation' incorporates:
  //   Outport: '<S27>/tau_pitch'

  HITL_HEXA_WOPOSCTRL_B.Saturation_c = HITL_HEXA_WOPOSCTRL_P.tau_pitch_Y0;

  // SystemInitialize for Saturate: '<S336>/Saturation' incorporates:
  //   Outport: '<S27>/tau_roll'

  HITL_HEXA_WOPOSCTRL_B.Saturation_b = HITL_HEXA_WOPOSCTRL_P.tau_roll_Y0;
}

// Output and update for enable system: '<S22>/mc_rate_controller'
void HITL_HEXA_WOPOSCTRL_mc_rate_controller(void)
{
  real32_T ParamStep;

  // Outputs for Enabled SubSystem: '<S22>/mc_rate_controller' incorporates:
  //   EnablePort: '<S27>/Enable'

  if (HITL_HEXA_WOPOSCTRL_B.In1_b.armed) {
    real_T rtb_NProdOut;
    real_T rtb_NProdOut_bg;
    real_T rtb_NProdOut_f;
    real_T rtb_Sum1;
    real_T rtb_Switch_i;
    real_T rtb_Switch_pn;
    int8_T rtb_Switch1_o;
    int8_T tmp;
    boolean_T b_varargout_2;
    boolean_T rtb_RelationalOperator;
    boolean_T rtb_fixforDTpropagationissue;

    // Sum: '<S27>/Sum4'
    HITL_HEXA_WOPOSCTRL_B.IProdOut = HITL_HEXA_WOPOSCTRL_B.Switch2 -
      HITL_HEXA_WOPOSCTRL_B.CastToDouble2[2];

    // MATLABSystem: '<S27>/Read Parameter21'
    if (HITL_HEXA_WOPOSCTRL_DW.obj_j.SampleTime !=
        HITL_HEXA_WOPOSCTRL_P.ReadParameter21_SampleTime) {
      HITL_HEXA_WOPOSCTRL_DW.obj_j.SampleTime =
        HITL_HEXA_WOPOSCTRL_P.ReadParameter21_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_j.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S232>/NProd Out' incorporates:
    //   Constant: '<S27>/Constant'
    //   DiscreteIntegrator: '<S224>/Filter'
    //   MATLABSystem: '<S27>/Read Parameter21'
    //   Product: '<S223>/DProd Out'
    //   Sum: '<S224>/SumD'
    //
    rtb_NProdOut = (HITL_HEXA_WOPOSCTRL_B.IProdOut * ParamStep -
                    HITL_HEXA_WOPOSCTRL_DW.Filter_DSTATE) *
      HITL_HEXA_WOPOSCTRL_P.Constant_Value_pd;

    // MATLABSystem: '<S27>/Read Parameter19'
    if (HITL_HEXA_WOPOSCTRL_DW.obj_n.SampleTime !=
        HITL_HEXA_WOPOSCTRL_P.ReadParameter19_SampleTime) {
      HITL_HEXA_WOPOSCTRL_DW.obj_n.SampleTime =
        HITL_HEXA_WOPOSCTRL_P.ReadParameter19_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_n.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Sum: '<S238>/Sum' incorporates:
    //   DiscreteIntegrator: '<S229>/Integrator'
    //   MATLABSystem: '<S27>/Read Parameter19'
    //   Product: '<S234>/PProd Out'
    //
    rtb_Sum1 = (HITL_HEXA_WOPOSCTRL_B.IProdOut * ParamStep +
                HITL_HEXA_WOPOSCTRL_DW.Integrator_DSTATE) + rtb_NProdOut;

    // Saturate: '<S236>/Saturation' incorporates:
    //   DeadZone: '<S222>/DeadZone'

    if (rtb_Sum1 > HITL_HEXA_WOPOSCTRL_P.PIDController_UpperSaturationLimit) {
      // Saturate: '<S236>/Saturation'
      HITL_HEXA_WOPOSCTRL_B.Saturation =
        HITL_HEXA_WOPOSCTRL_P.PIDController_UpperSaturationLimit;
      rtb_Sum1 -= HITL_HEXA_WOPOSCTRL_P.PIDController_UpperSaturationLimit;
    } else {
      if (rtb_Sum1 < HITL_HEXA_WOPOSCTRL_P.PIDController_LowerSaturationLimit) {
        // Saturate: '<S236>/Saturation'
        HITL_HEXA_WOPOSCTRL_B.Saturation =
          HITL_HEXA_WOPOSCTRL_P.PIDController_LowerSaturationLimit;
      } else {
        // Saturate: '<S236>/Saturation'
        HITL_HEXA_WOPOSCTRL_B.Saturation = rtb_Sum1;
      }

      if (rtb_Sum1 >= HITL_HEXA_WOPOSCTRL_P.PIDController_LowerSaturationLimit)
      {
        rtb_Sum1 = 0.0;
      } else {
        rtb_Sum1 -= HITL_HEXA_WOPOSCTRL_P.PIDController_LowerSaturationLimit;
      }
    }

    // End of Saturate: '<S236>/Saturation'

    // RelationalOperator: '<S220>/Relational Operator' incorporates:
    //   Constant: '<S220>/Clamping_zero'

    rtb_RelationalOperator = (HITL_HEXA_WOPOSCTRL_P.Clamping_zero_Value !=
      rtb_Sum1);

    // RelationalOperator: '<S220>/fix for DT propagation issue' incorporates:
    //   Constant: '<S220>/Clamping_zero'

    rtb_fixforDTpropagationissue = (rtb_Sum1 >
      HITL_HEXA_WOPOSCTRL_P.Clamping_zero_Value);

    // MATLABSystem: '<S27>/Read Parameter20'
    if (HITL_HEXA_WOPOSCTRL_DW.obj_l.SampleTime !=
        HITL_HEXA_WOPOSCTRL_P.ReadParameter20_SampleTime) {
      HITL_HEXA_WOPOSCTRL_DW.obj_l.SampleTime =
        HITL_HEXA_WOPOSCTRL_P.ReadParameter20_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_l.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S226>/IProd Out' incorporates:
    //   MATLABSystem: '<S27>/Read Parameter20'
    //
    rtb_Sum1 = HITL_HEXA_WOPOSCTRL_B.IProdOut * ParamStep;

    // Switch: '<S220>/Switch1' incorporates:
    //   Constant: '<S220>/Constant'
    //   Constant: '<S220>/Constant2'

    if (rtb_fixforDTpropagationissue) {
      tmp = HITL_HEXA_WOPOSCTRL_P.Constant_Value_dt;
    } else {
      tmp = HITL_HEXA_WOPOSCTRL_P.Constant2_Value_l;
    }

    // Switch: '<S220>/Switch2' incorporates:
    //   Constant: '<S220>/Clamping_zero'
    //   Constant: '<S220>/Constant3'
    //   Constant: '<S220>/Constant4'
    //   RelationalOperator: '<S220>/fix for DT propagation issue1'

    if (rtb_Sum1 > HITL_HEXA_WOPOSCTRL_P.Clamping_zero_Value) {
      rtb_Switch1_o = HITL_HEXA_WOPOSCTRL_P.Constant3_Value_j;
    } else {
      rtb_Switch1_o = HITL_HEXA_WOPOSCTRL_P.Constant4_Value_c;
    }

    // Switch: '<S220>/Switch' incorporates:
    //   Constant: '<S220>/Constant1'
    //   Logic: '<S220>/AND3'
    //   RelationalOperator: '<S220>/Equal1'
    //   Switch: '<S220>/Switch1'
    //   Switch: '<S220>/Switch2'

    if (rtb_RelationalOperator && (tmp == rtb_Switch1_o)) {
      rtb_Switch_i = HITL_HEXA_WOPOSCTRL_P.Constant1_Value_k;
    } else {
      rtb_Switch_i = rtb_Sum1;
    }

    // End of Switch: '<S220>/Switch'

    // Sum: '<S27>/Sum'
    rtb_Sum1 = HITL_HEXA_WOPOSCTRL_B.Switch2_l -
      HITL_HEXA_WOPOSCTRL_B.CastToDouble2[1];

    // MATLABSystem: '<S27>/Read Parameter18'
    if (HITL_HEXA_WOPOSCTRL_DW.obj_h.SampleTime !=
        HITL_HEXA_WOPOSCTRL_P.ReadParameter18_SampleTime) {
      HITL_HEXA_WOPOSCTRL_DW.obj_h.SampleTime =
        HITL_HEXA_WOPOSCTRL_P.ReadParameter18_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_h.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S282>/NProd Out' incorporates:
    //   Constant: '<S27>/Constant1'
    //   DiscreteIntegrator: '<S274>/Filter'
    //   MATLABSystem: '<S27>/Read Parameter18'
    //   Product: '<S273>/DProd Out'
    //   Sum: '<S274>/SumD'
    //
    rtb_NProdOut_f = (rtb_Sum1 * ParamStep -
                      HITL_HEXA_WOPOSCTRL_DW.Filter_DSTATE_h) *
      HITL_HEXA_WOPOSCTRL_P.Constant1_Value_f;

    // MATLABSystem: '<S27>/Read Parameter16'
    if (HITL_HEXA_WOPOSCTRL_DW.obj_g.SampleTime !=
        HITL_HEXA_WOPOSCTRL_P.ReadParameter16_SampleTime) {
      HITL_HEXA_WOPOSCTRL_DW.obj_g.SampleTime =
        HITL_HEXA_WOPOSCTRL_P.ReadParameter16_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_g.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Sum: '<S288>/Sum' incorporates:
    //   DiscreteIntegrator: '<S279>/Integrator'
    //   MATLABSystem: '<S27>/Read Parameter16'
    //   Product: '<S284>/PProd Out'
    //
    HITL_HEXA_WOPOSCTRL_B.IProdOut = (rtb_Sum1 * ParamStep +
      HITL_HEXA_WOPOSCTRL_DW.Integrator_DSTATE_d) + rtb_NProdOut_f;

    // Saturate: '<S286>/Saturation' incorporates:
    //   DeadZone: '<S272>/DeadZone'

    if (HITL_HEXA_WOPOSCTRL_B.IProdOut >
        HITL_HEXA_WOPOSCTRL_P.PIDController1_UpperSaturationLimit) {
      // Saturate: '<S286>/Saturation'
      HITL_HEXA_WOPOSCTRL_B.Saturation_c =
        HITL_HEXA_WOPOSCTRL_P.PIDController1_UpperSaturationLimit;
      HITL_HEXA_WOPOSCTRL_B.IProdOut -=
        HITL_HEXA_WOPOSCTRL_P.PIDController1_UpperSaturationLimit;
    } else {
      if (HITL_HEXA_WOPOSCTRL_B.IProdOut <
          HITL_HEXA_WOPOSCTRL_P.PIDController1_LowerSaturationLimit) {
        // Saturate: '<S286>/Saturation'
        HITL_HEXA_WOPOSCTRL_B.Saturation_c =
          HITL_HEXA_WOPOSCTRL_P.PIDController1_LowerSaturationLimit;
      } else {
        // Saturate: '<S286>/Saturation'
        HITL_HEXA_WOPOSCTRL_B.Saturation_c = HITL_HEXA_WOPOSCTRL_B.IProdOut;
      }

      if (HITL_HEXA_WOPOSCTRL_B.IProdOut >=
          HITL_HEXA_WOPOSCTRL_P.PIDController1_LowerSaturationLimit) {
        HITL_HEXA_WOPOSCTRL_B.IProdOut = 0.0;
      } else {
        HITL_HEXA_WOPOSCTRL_B.IProdOut -=
          HITL_HEXA_WOPOSCTRL_P.PIDController1_LowerSaturationLimit;
      }
    }

    // End of Saturate: '<S286>/Saturation'

    // RelationalOperator: '<S270>/Relational Operator' incorporates:
    //   Constant: '<S270>/Clamping_zero'

    rtb_RelationalOperator = (HITL_HEXA_WOPOSCTRL_P.Clamping_zero_Value_d !=
      HITL_HEXA_WOPOSCTRL_B.IProdOut);

    // RelationalOperator: '<S270>/fix for DT propagation issue' incorporates:
    //   Constant: '<S270>/Clamping_zero'

    rtb_fixforDTpropagationissue = (HITL_HEXA_WOPOSCTRL_B.IProdOut >
      HITL_HEXA_WOPOSCTRL_P.Clamping_zero_Value_d);

    // MATLABSystem: '<S27>/Read Parameter17'
    if (HITL_HEXA_WOPOSCTRL_DW.obj_hj.SampleTime !=
        HITL_HEXA_WOPOSCTRL_P.ReadParameter17_SampleTime) {
      HITL_HEXA_WOPOSCTRL_DW.obj_hj.SampleTime =
        HITL_HEXA_WOPOSCTRL_P.ReadParameter17_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_hj.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S276>/IProd Out' incorporates:
    //   MATLABSystem: '<S27>/Read Parameter17'
    //
    HITL_HEXA_WOPOSCTRL_B.IProdOut = rtb_Sum1 * ParamStep;

    // Switch: '<S270>/Switch1' incorporates:
    //   Constant: '<S270>/Constant'
    //   Constant: '<S270>/Constant2'

    if (rtb_fixforDTpropagationissue) {
      tmp = HITL_HEXA_WOPOSCTRL_P.Constant_Value_d5;
    } else {
      tmp = HITL_HEXA_WOPOSCTRL_P.Constant2_Value_e;
    }

    // Switch: '<S270>/Switch2' incorporates:
    //   Constant: '<S270>/Clamping_zero'
    //   Constant: '<S270>/Constant3'
    //   Constant: '<S270>/Constant4'
    //   RelationalOperator: '<S270>/fix for DT propagation issue1'

    if (HITL_HEXA_WOPOSCTRL_B.IProdOut >
        HITL_HEXA_WOPOSCTRL_P.Clamping_zero_Value_d) {
      rtb_Switch1_o = HITL_HEXA_WOPOSCTRL_P.Constant3_Value_k;
    } else {
      rtb_Switch1_o = HITL_HEXA_WOPOSCTRL_P.Constant4_Value_n;
    }

    // Switch: '<S270>/Switch' incorporates:
    //   Constant: '<S270>/Constant1'
    //   Logic: '<S270>/AND3'
    //   RelationalOperator: '<S270>/Equal1'
    //   Switch: '<S270>/Switch1'
    //   Switch: '<S270>/Switch2'

    if (rtb_RelationalOperator && (tmp == rtb_Switch1_o)) {
      rtb_Switch_pn = HITL_HEXA_WOPOSCTRL_P.Constant1_Value_jx;
    } else {
      rtb_Switch_pn = HITL_HEXA_WOPOSCTRL_B.IProdOut;
    }

    // End of Switch: '<S270>/Switch'

    // Sum: '<S27>/Sum1'
    rtb_Sum1 = HITL_HEXA_WOPOSCTRL_B.Switch2_n -
      HITL_HEXA_WOPOSCTRL_B.CastToDouble2[0];

    // MATLABSystem: '<S27>/Read Parameter24'
    if (HITL_HEXA_WOPOSCTRL_DW.obj.SampleTime !=
        HITL_HEXA_WOPOSCTRL_P.ReadParameter24_SampleTime) {
      HITL_HEXA_WOPOSCTRL_DW.obj.SampleTime =
        HITL_HEXA_WOPOSCTRL_P.ReadParameter24_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S332>/NProd Out' incorporates:
    //   Constant: '<S27>/Constant2'
    //   DiscreteIntegrator: '<S324>/Filter'
    //   MATLABSystem: '<S27>/Read Parameter24'
    //   Product: '<S323>/DProd Out'
    //   Sum: '<S324>/SumD'
    //
    rtb_NProdOut_bg = (rtb_Sum1 * ParamStep -
                       HITL_HEXA_WOPOSCTRL_DW.Filter_DSTATE_l) *
      HITL_HEXA_WOPOSCTRL_P.Constant2_Value_n;

    // MATLABSystem: '<S27>/Read Parameter22'
    if (HITL_HEXA_WOPOSCTRL_DW.obj_d.SampleTime !=
        HITL_HEXA_WOPOSCTRL_P.ReadParameter22_SampleTime) {
      HITL_HEXA_WOPOSCTRL_DW.obj_d.SampleTime =
        HITL_HEXA_WOPOSCTRL_P.ReadParameter22_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_d.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Sum: '<S338>/Sum' incorporates:
    //   DiscreteIntegrator: '<S329>/Integrator'
    //   MATLABSystem: '<S27>/Read Parameter22'
    //   Product: '<S334>/PProd Out'
    //
    HITL_HEXA_WOPOSCTRL_B.IProdOut = (rtb_Sum1 * ParamStep +
      HITL_HEXA_WOPOSCTRL_DW.Integrator_DSTATE_dd) + rtb_NProdOut_bg;

    // Saturate: '<S336>/Saturation' incorporates:
    //   DeadZone: '<S322>/DeadZone'

    if (HITL_HEXA_WOPOSCTRL_B.IProdOut >
        HITL_HEXA_WOPOSCTRL_P.PIDController2_UpperSaturationLimit) {
      // Saturate: '<S336>/Saturation'
      HITL_HEXA_WOPOSCTRL_B.Saturation_b =
        HITL_HEXA_WOPOSCTRL_P.PIDController2_UpperSaturationLimit;
      HITL_HEXA_WOPOSCTRL_B.IProdOut -=
        HITL_HEXA_WOPOSCTRL_P.PIDController2_UpperSaturationLimit;
    } else {
      if (HITL_HEXA_WOPOSCTRL_B.IProdOut <
          HITL_HEXA_WOPOSCTRL_P.PIDController2_LowerSaturationLimit) {
        // Saturate: '<S336>/Saturation'
        HITL_HEXA_WOPOSCTRL_B.Saturation_b =
          HITL_HEXA_WOPOSCTRL_P.PIDController2_LowerSaturationLimit;
      } else {
        // Saturate: '<S336>/Saturation'
        HITL_HEXA_WOPOSCTRL_B.Saturation_b = HITL_HEXA_WOPOSCTRL_B.IProdOut;
      }

      if (HITL_HEXA_WOPOSCTRL_B.IProdOut >=
          HITL_HEXA_WOPOSCTRL_P.PIDController2_LowerSaturationLimit) {
        HITL_HEXA_WOPOSCTRL_B.IProdOut = 0.0;
      } else {
        HITL_HEXA_WOPOSCTRL_B.IProdOut -=
          HITL_HEXA_WOPOSCTRL_P.PIDController2_LowerSaturationLimit;
      }
    }

    // End of Saturate: '<S336>/Saturation'

    // RelationalOperator: '<S320>/Relational Operator' incorporates:
    //   Constant: '<S320>/Clamping_zero'

    rtb_RelationalOperator = (HITL_HEXA_WOPOSCTRL_P.Clamping_zero_Value_e !=
      HITL_HEXA_WOPOSCTRL_B.IProdOut);

    // Switch: '<S320>/Switch1' incorporates:
    //   Constant: '<S320>/Clamping_zero'
    //   Constant: '<S320>/Constant'
    //   Constant: '<S320>/Constant2'
    //   RelationalOperator: '<S320>/fix for DT propagation issue'

    if (HITL_HEXA_WOPOSCTRL_B.IProdOut >
        HITL_HEXA_WOPOSCTRL_P.Clamping_zero_Value_e) {
      rtb_Switch1_o = HITL_HEXA_WOPOSCTRL_P.Constant_Value_k;
    } else {
      rtb_Switch1_o = HITL_HEXA_WOPOSCTRL_P.Constant2_Value_m;
    }

    // End of Switch: '<S320>/Switch1'

    // MATLABSystem: '<S27>/Read Parameter23'
    if (HITL_HEXA_WOPOSCTRL_DW.obj_f.SampleTime !=
        HITL_HEXA_WOPOSCTRL_P.ReadParameter23_SampleTime) {
      HITL_HEXA_WOPOSCTRL_DW.obj_f.SampleTime =
        HITL_HEXA_WOPOSCTRL_P.ReadParameter23_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(HITL_HEXA_WOPOSCTRL_DW.obj_f.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S326>/IProd Out' incorporates:
    //   MATLABSystem: '<S27>/Read Parameter23'
    //
    HITL_HEXA_WOPOSCTRL_B.IProdOut = rtb_Sum1 * ParamStep;

    // Update for DiscreteIntegrator: '<S224>/Filter'
    HITL_HEXA_WOPOSCTRL_DW.Filter_DSTATE += HITL_HEXA_WOPOSCTRL_P.Filter_gainval
      * rtb_NProdOut;

    // Update for DiscreteIntegrator: '<S229>/Integrator'
    HITL_HEXA_WOPOSCTRL_DW.Integrator_DSTATE +=
      HITL_HEXA_WOPOSCTRL_P.Integrator_gainval * rtb_Switch_i;

    // Update for DiscreteIntegrator: '<S274>/Filter'
    HITL_HEXA_WOPOSCTRL_DW.Filter_DSTATE_h +=
      HITL_HEXA_WOPOSCTRL_P.Filter_gainval_l * rtb_NProdOut_f;

    // Update for DiscreteIntegrator: '<S279>/Integrator'
    HITL_HEXA_WOPOSCTRL_DW.Integrator_DSTATE_d +=
      HITL_HEXA_WOPOSCTRL_P.Integrator_gainval_b * rtb_Switch_pn;

    // Update for DiscreteIntegrator: '<S324>/Filter'
    HITL_HEXA_WOPOSCTRL_DW.Filter_DSTATE_l +=
      HITL_HEXA_WOPOSCTRL_P.Filter_gainval_a * rtb_NProdOut_bg;

    // Switch: '<S320>/Switch2' incorporates:
    //   Constant: '<S320>/Clamping_zero'
    //   Constant: '<S320>/Constant3'
    //   Constant: '<S320>/Constant4'
    //   RelationalOperator: '<S320>/fix for DT propagation issue1'

    if (HITL_HEXA_WOPOSCTRL_B.IProdOut >
        HITL_HEXA_WOPOSCTRL_P.Clamping_zero_Value_e) {
      tmp = HITL_HEXA_WOPOSCTRL_P.Constant3_Value_d;
    } else {
      tmp = HITL_HEXA_WOPOSCTRL_P.Constant4_Value_b;
    }

    // Switch: '<S320>/Switch' incorporates:
    //   Constant: '<S320>/Constant1'
    //   Logic: '<S320>/AND3'
    //   RelationalOperator: '<S320>/Equal1'
    //   Switch: '<S320>/Switch2'

    if (rtb_RelationalOperator && (rtb_Switch1_o == tmp)) {
      HITL_HEXA_WOPOSCTRL_B.IProdOut = HITL_HEXA_WOPOSCTRL_P.Constant1_Value_ka;
    }

    // Update for DiscreteIntegrator: '<S329>/Integrator' incorporates:
    //   Switch: '<S320>/Switch'

    HITL_HEXA_WOPOSCTRL_DW.Integrator_DSTATE_dd +=
      HITL_HEXA_WOPOSCTRL_P.Integrator_gainval_n *
      HITL_HEXA_WOPOSCTRL_B.IProdOut;
  }

  // End of Outputs for SubSystem: '<S22>/mc_rate_controller'
}

// Termination for enable system: '<S22>/mc_rate_controller'
void HITL_HEXA_WOPOSCTRL_mc_rate_controller_Term(void)
{
  // Terminate for MATLABSystem: '<S27>/Read Parameter21'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_j.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S27>/Read Parameter21'

  // Terminate for MATLABSystem: '<S27>/Read Parameter19'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_n.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S27>/Read Parameter19'

  // Terminate for MATLABSystem: '<S27>/Read Parameter20'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_l.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S27>/Read Parameter20'

  // Terminate for MATLABSystem: '<S27>/Read Parameter18'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_h.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S27>/Read Parameter18'

  // Terminate for MATLABSystem: '<S27>/Read Parameter16'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_g.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S27>/Read Parameter16'

  // Terminate for MATLABSystem: '<S27>/Read Parameter17'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_hj.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_hj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S27>/Read Parameter17'

  // Terminate for MATLABSystem: '<S27>/Read Parameter24'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S27>/Read Parameter24'

  // Terminate for MATLABSystem: '<S27>/Read Parameter22'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_d.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S27>/Read Parameter22'

  // Terminate for MATLABSystem: '<S27>/Read Parameter23'
  if (!HITL_HEXA_WOPOSCTRL_DW.obj_f.matlabCodegenIsDeleted) {
    HITL_HEXA_WOPOSCTRL_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S27>/Read Parameter23'
}

//
// File trailer for generated code.
//
// [EOF]
//
