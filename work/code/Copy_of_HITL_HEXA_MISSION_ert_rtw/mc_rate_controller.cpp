//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mc_rate_controller.cpp
//
// Code generated for Simulink model 'Copy_of_HITL_HEXA_MISSION'.
//
// Model version                  : 5.1
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Mon Oct 14 16:51:03 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "mc_rate_controller.h"
#include "Copy_of_HITL_HEXA_MISSION.h"
#include "rtwtypes.h"
#include "Copy_of_HITL_HEXA_MISSION_private.h"

// System initialize for enable system: '<S23>/mc_rate_controller'
void Copy_of_HITL_HEXA_MISSION_mc_rate_controller_Init(void)
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

  // InitializeConditions for DiscreteIntegrator: '<S450>/Filter'
  Copy_of_HITL_HEXA_MISSION_DW.Filter_DSTATE =
    Copy_of_HITL_HEXA_MISSION_P.PIDController_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S455>/Integrator'
  Copy_of_HITL_HEXA_MISSION_DW.Integrator_DSTATE =
    Copy_of_HITL_HEXA_MISSION_P.PIDController_InitialConditionForIntegrator;

  // InitializeConditions for DiscreteIntegrator: '<S502>/Filter'
  Copy_of_HITL_HEXA_MISSION_DW.Filter_DSTATE_h =
    Copy_of_HITL_HEXA_MISSION_P.PIDController1_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S507>/Integrator'
  Copy_of_HITL_HEXA_MISSION_DW.Integrator_DSTATE_d =
    Copy_of_HITL_HEXA_MISSION_P.PIDController1_InitialConditionForIntegrator;

  // InitializeConditions for DiscreteIntegrator: '<S554>/Filter'
  Copy_of_HITL_HEXA_MISSION_DW.Filter_DSTATE_l =
    Copy_of_HITL_HEXA_MISSION_P.PIDController2_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S559>/Integrator'
  Copy_of_HITL_HEXA_MISSION_DW.Integrator_DSTATE_dd =
    Copy_of_HITL_HEXA_MISSION_P.PIDController2_InitialConditionForIntegrator;

  // Start for MATLABSystem: '<S30>/Read Parameter21'
  Copy_of_HITL_HEXA_MISSION_DW.obj_j.matlabCodegenIsDeleted = false;
  Copy_of_HITL_HEXA_MISSION_DW.obj_j.SampleTime =
    Copy_of_HITL_HEXA_MISSION_P.ReadParameter21_SampleTime;
  Copy_of_HITL_HEXA_MISSION_DW.obj_j.isInitialized = 1;
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_j.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_j.SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_DW.obj_j.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr[0], true, tmp * 1000.0);
  Copy_of_HITL_HEXA_MISSION_DW.obj_j.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter21'

  // Start for MATLABSystem: '<S30>/Read Parameter19'
  Copy_of_HITL_HEXA_MISSION_DW.obj_nu.matlabCodegenIsDeleted = false;
  Copy_of_HITL_HEXA_MISSION_DW.obj_nu.SampleTime =
    Copy_of_HITL_HEXA_MISSION_P.ReadParameter19_SampleTime;
  Copy_of_HITL_HEXA_MISSION_DW.obj_nu.isInitialized = 1;
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_nu.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_nu.SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_DW.obj_nu.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_0[0], true, tmp * 1000.0);
  Copy_of_HITL_HEXA_MISSION_DW.obj_nu.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter19'

  // Start for MATLABSystem: '<S30>/Read Parameter20'
  Copy_of_HITL_HEXA_MISSION_DW.obj_l.matlabCodegenIsDeleted = false;
  Copy_of_HITL_HEXA_MISSION_DW.obj_l.SampleTime =
    Copy_of_HITL_HEXA_MISSION_P.ReadParameter20_SampleTime;
  Copy_of_HITL_HEXA_MISSION_DW.obj_l.isInitialized = 1;
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_l.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_l.SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_DW.obj_l.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_1[0], true, tmp * 1000.0);
  Copy_of_HITL_HEXA_MISSION_DW.obj_l.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter20'

  // Start for MATLABSystem: '<S30>/Read Parameter18'
  Copy_of_HITL_HEXA_MISSION_DW.obj_h.matlabCodegenIsDeleted = false;
  Copy_of_HITL_HEXA_MISSION_DW.obj_h.SampleTime =
    Copy_of_HITL_HEXA_MISSION_P.ReadParameter18_SampleTime;
  Copy_of_HITL_HEXA_MISSION_DW.obj_h.isInitialized = 1;
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_h.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_h.SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_DW.obj_h.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_2[0], true, tmp * 1000.0);
  Copy_of_HITL_HEXA_MISSION_DW.obj_h.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter18'

  // Start for MATLABSystem: '<S30>/Read Parameter16'
  Copy_of_HITL_HEXA_MISSION_DW.obj_gu.matlabCodegenIsDeleted = false;
  Copy_of_HITL_HEXA_MISSION_DW.obj_gu.SampleTime =
    Copy_of_HITL_HEXA_MISSION_P.ReadParameter16_SampleTime;
  Copy_of_HITL_HEXA_MISSION_DW.obj_gu.isInitialized = 1;
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_gu.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_gu.SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_DW.obj_gu.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_3[0], true, tmp * 1000.0);
  Copy_of_HITL_HEXA_MISSION_DW.obj_gu.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter16'

  // Start for MATLABSystem: '<S30>/Read Parameter17'
  Copy_of_HITL_HEXA_MISSION_DW.obj_hj.matlabCodegenIsDeleted = false;
  Copy_of_HITL_HEXA_MISSION_DW.obj_hj.SampleTime =
    Copy_of_HITL_HEXA_MISSION_P.ReadParameter17_SampleTime;
  Copy_of_HITL_HEXA_MISSION_DW.obj_hj.isInitialized = 1;
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_hj.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_hj.SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_DW.obj_hj.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_4[0], true, tmp * 1000.0);
  Copy_of_HITL_HEXA_MISSION_DW.obj_hj.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter17'

  // Start for MATLABSystem: '<S30>/Read Parameter24'
  Copy_of_HITL_HEXA_MISSION_DW.obj_n.matlabCodegenIsDeleted = false;
  Copy_of_HITL_HEXA_MISSION_DW.obj_n.SampleTime =
    Copy_of_HITL_HEXA_MISSION_P.ReadParameter24_SampleTime;
  Copy_of_HITL_HEXA_MISSION_DW.obj_n.isInitialized = 1;
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_n.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_n.SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_DW.obj_n.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_5[0], true, tmp * 1000.0);
  Copy_of_HITL_HEXA_MISSION_DW.obj_n.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter24'

  // Start for MATLABSystem: '<S30>/Read Parameter22'
  Copy_of_HITL_HEXA_MISSION_DW.obj_d.matlabCodegenIsDeleted = false;
  Copy_of_HITL_HEXA_MISSION_DW.obj_d.SampleTime =
    Copy_of_HITL_HEXA_MISSION_P.ReadParameter22_SampleTime;
  Copy_of_HITL_HEXA_MISSION_DW.obj_d.isInitialized = 1;
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_d.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_d.SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_6[0], true, tmp * 1000.0);
  Copy_of_HITL_HEXA_MISSION_DW.obj_d.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter22'

  // Start for MATLABSystem: '<S30>/Read Parameter23'
  Copy_of_HITL_HEXA_MISSION_DW.obj_f.matlabCodegenIsDeleted = false;
  Copy_of_HITL_HEXA_MISSION_DW.obj_f.SampleTime =
    Copy_of_HITL_HEXA_MISSION_P.ReadParameter23_SampleTime;
  Copy_of_HITL_HEXA_MISSION_DW.obj_f.isInitialized = 1;
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_f.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_f.SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_DW.obj_f.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_7[0], true, tmp * 1000.0);
  Copy_of_HITL_HEXA_MISSION_DW.obj_f.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter23'

  // SystemInitialize for Saturate: '<S462>/Saturation' incorporates:
  //   Outport: '<S30>/tau_yaw'

  Copy_of_HITL_HEXA_MISSION_B.Saturation =
    Copy_of_HITL_HEXA_MISSION_P.tau_yaw_Y0;

  // SystemInitialize for Saturate: '<S514>/Saturation' incorporates:
  //   Outport: '<S30>/tau_pitch'

  Copy_of_HITL_HEXA_MISSION_B.Saturation_c =
    Copy_of_HITL_HEXA_MISSION_P.tau_pitch_Y0;

  // SystemInitialize for Saturate: '<S566>/Saturation' incorporates:
  //   Outport: '<S30>/tau_roll'

  Copy_of_HITL_HEXA_MISSION_B.Saturation_b =
    Copy_of_HITL_HEXA_MISSION_P.tau_roll_Y0;
}

// Output and update for enable system: '<S23>/mc_rate_controller'
void Copy_of_HITL_HEXA_MISSION_mc_rate_controller(void)
{
  real32_T ParamStep;

  // Outputs for Enabled SubSystem: '<S23>/mc_rate_controller' incorporates:
  //   EnablePort: '<S30>/Enable'

  if (Copy_of_HITL_HEXA_MISSION_B.In1_b.armed) {
    real_T rtb_NProdOut;
    real_T rtb_NProdOut_bg;
    real_T rtb_NProdOut_f;
    real_T rtb_Sum1;
    real_T rtb_Switch_i;
    real_T rtb_Switch_pn;
    int8_T rtb_Switch1_a;
    int8_T tmp;
    boolean_T b_varargout_2;
    boolean_T rtb_RelationalOperator;
    boolean_T rtb_fixforDTpropagationissue_lk;

    // Sum: '<S30>/Sum4'
    Copy_of_HITL_HEXA_MISSION_B.IProdOut = Copy_of_HITL_HEXA_MISSION_B.Switch2_o
      - Copy_of_HITL_HEXA_MISSION_B.In1_l.xyz[2];

    // MATLABSystem: '<S30>/Read Parameter21'
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_j.SampleTime !=
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter21_SampleTime) {
      Copy_of_HITL_HEXA_MISSION_DW.obj_j.SampleTime =
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter21_SampleTime;
    }

    b_varargout_2 = MW_Param_Step
      (Copy_of_HITL_HEXA_MISSION_DW.obj_j.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S458>/NProd Out' incorporates:
    //   Constant: '<S30>/Constant'
    //   DiscreteIntegrator: '<S450>/Filter'
    //   MATLABSystem: '<S30>/Read Parameter21'
    //   Product: '<S448>/DProd Out'
    //   Sum: '<S450>/SumD'
    //
    rtb_NProdOut = (Copy_of_HITL_HEXA_MISSION_B.IProdOut * ParamStep -
                    Copy_of_HITL_HEXA_MISSION_DW.Filter_DSTATE) *
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_pd;

    // MATLABSystem: '<S30>/Read Parameter19'
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_nu.SampleTime !=
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter19_SampleTime) {
      Copy_of_HITL_HEXA_MISSION_DW.obj_nu.SampleTime =
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter19_SampleTime;
    }

    b_varargout_2 = MW_Param_Step
      (Copy_of_HITL_HEXA_MISSION_DW.obj_nu.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Sum: '<S464>/Sum' incorporates:
    //   DiscreteIntegrator: '<S455>/Integrator'
    //   MATLABSystem: '<S30>/Read Parameter19'
    //   Product: '<S460>/PProd Out'
    //
    rtb_Sum1 = (Copy_of_HITL_HEXA_MISSION_B.IProdOut * ParamStep +
                Copy_of_HITL_HEXA_MISSION_DW.Integrator_DSTATE) + rtb_NProdOut;

    // Saturate: '<S462>/Saturation' incorporates:
    //   DeadZone: '<S447>/DeadZone'

    if (rtb_Sum1 >
        Copy_of_HITL_HEXA_MISSION_P.PIDController_UpperSaturationLimit) {
      // Saturate: '<S462>/Saturation'
      Copy_of_HITL_HEXA_MISSION_B.Saturation =
        Copy_of_HITL_HEXA_MISSION_P.PIDController_UpperSaturationLimit;
      rtb_Sum1 -= Copy_of_HITL_HEXA_MISSION_P.PIDController_UpperSaturationLimit;
    } else {
      if (rtb_Sum1 <
          Copy_of_HITL_HEXA_MISSION_P.PIDController_LowerSaturationLimit) {
        // Saturate: '<S462>/Saturation'
        Copy_of_HITL_HEXA_MISSION_B.Saturation =
          Copy_of_HITL_HEXA_MISSION_P.PIDController_LowerSaturationLimit;
      } else {
        // Saturate: '<S462>/Saturation'
        Copy_of_HITL_HEXA_MISSION_B.Saturation = rtb_Sum1;
      }

      if (rtb_Sum1 >=
          Copy_of_HITL_HEXA_MISSION_P.PIDController_LowerSaturationLimit) {
        rtb_Sum1 = 0.0;
      } else {
        rtb_Sum1 -=
          Copy_of_HITL_HEXA_MISSION_P.PIDController_LowerSaturationLimit;
      }
    }

    // End of Saturate: '<S462>/Saturation'

    // RelationalOperator: '<S445>/Relational Operator' incorporates:
    //   Constant: '<S445>/Clamping_zero'

    rtb_RelationalOperator = (Copy_of_HITL_HEXA_MISSION_P.Clamping_zero_Value_i
      != rtb_Sum1);

    // RelationalOperator: '<S445>/fix for DT propagation issue' incorporates:
    //   Constant: '<S445>/Clamping_zero'

    rtb_fixforDTpropagationissue_lk = (rtb_Sum1 >
      Copy_of_HITL_HEXA_MISSION_P.Clamping_zero_Value_i);

    // MATLABSystem: '<S30>/Read Parameter20'
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_l.SampleTime !=
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter20_SampleTime) {
      Copy_of_HITL_HEXA_MISSION_DW.obj_l.SampleTime =
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter20_SampleTime;
    }

    b_varargout_2 = MW_Param_Step
      (Copy_of_HITL_HEXA_MISSION_DW.obj_l.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S452>/IProd Out' incorporates:
    //   MATLABSystem: '<S30>/Read Parameter20'
    //
    rtb_Sum1 = Copy_of_HITL_HEXA_MISSION_B.IProdOut * ParamStep;

    // Switch: '<S445>/Switch1' incorporates:
    //   Constant: '<S445>/Constant'
    //   Constant: '<S445>/Constant2'

    if (rtb_fixforDTpropagationissue_lk) {
      tmp = Copy_of_HITL_HEXA_MISSION_P.Constant_Value_dt;
    } else {
      tmp = Copy_of_HITL_HEXA_MISSION_P.Constant2_Value_l;
    }

    // Switch: '<S445>/Switch2' incorporates:
    //   Constant: '<S445>/Clamping_zero'
    //   Constant: '<S445>/Constant3'
    //   Constant: '<S445>/Constant4'
    //   RelationalOperator: '<S445>/fix for DT propagation issue1'

    if (rtb_Sum1 > Copy_of_HITL_HEXA_MISSION_P.Clamping_zero_Value_i) {
      rtb_Switch1_a = Copy_of_HITL_HEXA_MISSION_P.Constant3_Value_j;
    } else {
      rtb_Switch1_a = Copy_of_HITL_HEXA_MISSION_P.Constant4_Value_c;
    }

    // Switch: '<S445>/Switch' incorporates:
    //   Constant: '<S445>/Constant1'
    //   Logic: '<S445>/AND3'
    //   RelationalOperator: '<S445>/Equal1'
    //   Switch: '<S445>/Switch1'
    //   Switch: '<S445>/Switch2'

    if (rtb_RelationalOperator && (tmp == rtb_Switch1_a)) {
      rtb_Switch_i = Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_k;
    } else {
      rtb_Switch_i = rtb_Sum1;
    }

    // End of Switch: '<S445>/Switch'

    // Sum: '<S30>/Sum'
    rtb_Sum1 = Copy_of_HITL_HEXA_MISSION_B.Switch2_l -
      Copy_of_HITL_HEXA_MISSION_B.In1_l.xyz[1];

    // MATLABSystem: '<S30>/Read Parameter18'
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_h.SampleTime !=
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter18_SampleTime) {
      Copy_of_HITL_HEXA_MISSION_DW.obj_h.SampleTime =
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter18_SampleTime;
    }

    b_varargout_2 = MW_Param_Step
      (Copy_of_HITL_HEXA_MISSION_DW.obj_h.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S510>/NProd Out' incorporates:
    //   Constant: '<S30>/Constant1'
    //   DiscreteIntegrator: '<S502>/Filter'
    //   MATLABSystem: '<S30>/Read Parameter18'
    //   Product: '<S500>/DProd Out'
    //   Sum: '<S502>/SumD'
    //
    rtb_NProdOut_f = (rtb_Sum1 * ParamStep -
                      Copy_of_HITL_HEXA_MISSION_DW.Filter_DSTATE_h) *
      Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_f;

    // MATLABSystem: '<S30>/Read Parameter16'
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_gu.SampleTime !=
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter16_SampleTime) {
      Copy_of_HITL_HEXA_MISSION_DW.obj_gu.SampleTime =
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter16_SampleTime;
    }

    b_varargout_2 = MW_Param_Step
      (Copy_of_HITL_HEXA_MISSION_DW.obj_gu.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Sum: '<S516>/Sum' incorporates:
    //   DiscreteIntegrator: '<S507>/Integrator'
    //   MATLABSystem: '<S30>/Read Parameter16'
    //   Product: '<S512>/PProd Out'
    //
    Copy_of_HITL_HEXA_MISSION_B.IProdOut = (rtb_Sum1 * ParamStep +
      Copy_of_HITL_HEXA_MISSION_DW.Integrator_DSTATE_d) + rtb_NProdOut_f;

    // Saturate: '<S514>/Saturation' incorporates:
    //   DeadZone: '<S499>/DeadZone'

    if (Copy_of_HITL_HEXA_MISSION_B.IProdOut >
        Copy_of_HITL_HEXA_MISSION_P.PIDController1_UpperSaturationLimit) {
      // Saturate: '<S514>/Saturation'
      Copy_of_HITL_HEXA_MISSION_B.Saturation_c =
        Copy_of_HITL_HEXA_MISSION_P.PIDController1_UpperSaturationLimit;
      Copy_of_HITL_HEXA_MISSION_B.IProdOut -=
        Copy_of_HITL_HEXA_MISSION_P.PIDController1_UpperSaturationLimit;
    } else {
      if (Copy_of_HITL_HEXA_MISSION_B.IProdOut <
          Copy_of_HITL_HEXA_MISSION_P.PIDController1_LowerSaturationLimit) {
        // Saturate: '<S514>/Saturation'
        Copy_of_HITL_HEXA_MISSION_B.Saturation_c =
          Copy_of_HITL_HEXA_MISSION_P.PIDController1_LowerSaturationLimit;
      } else {
        // Saturate: '<S514>/Saturation'
        Copy_of_HITL_HEXA_MISSION_B.Saturation_c =
          Copy_of_HITL_HEXA_MISSION_B.IProdOut;
      }

      if (Copy_of_HITL_HEXA_MISSION_B.IProdOut >=
          Copy_of_HITL_HEXA_MISSION_P.PIDController1_LowerSaturationLimit) {
        Copy_of_HITL_HEXA_MISSION_B.IProdOut = 0.0;
      } else {
        Copy_of_HITL_HEXA_MISSION_B.IProdOut -=
          Copy_of_HITL_HEXA_MISSION_P.PIDController1_LowerSaturationLimit;
      }
    }

    // End of Saturate: '<S514>/Saturation'

    // RelationalOperator: '<S497>/Relational Operator' incorporates:
    //   Constant: '<S497>/Clamping_zero'

    rtb_RelationalOperator = (Copy_of_HITL_HEXA_MISSION_P.Clamping_zero_Value_d
      != Copy_of_HITL_HEXA_MISSION_B.IProdOut);

    // RelationalOperator: '<S497>/fix for DT propagation issue' incorporates:
    //   Constant: '<S497>/Clamping_zero'

    rtb_fixforDTpropagationissue_lk = (Copy_of_HITL_HEXA_MISSION_B.IProdOut >
      Copy_of_HITL_HEXA_MISSION_P.Clamping_zero_Value_d);

    // MATLABSystem: '<S30>/Read Parameter17'
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_hj.SampleTime !=
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter17_SampleTime) {
      Copy_of_HITL_HEXA_MISSION_DW.obj_hj.SampleTime =
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter17_SampleTime;
    }

    b_varargout_2 = MW_Param_Step
      (Copy_of_HITL_HEXA_MISSION_DW.obj_hj.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S504>/IProd Out' incorporates:
    //   MATLABSystem: '<S30>/Read Parameter17'
    //
    Copy_of_HITL_HEXA_MISSION_B.IProdOut = rtb_Sum1 * ParamStep;

    // Switch: '<S497>/Switch1' incorporates:
    //   Constant: '<S497>/Constant'
    //   Constant: '<S497>/Constant2'

    if (rtb_fixforDTpropagationissue_lk) {
      tmp = Copy_of_HITL_HEXA_MISSION_P.Constant_Value_d5;
    } else {
      tmp = Copy_of_HITL_HEXA_MISSION_P.Constant2_Value_e;
    }

    // Switch: '<S497>/Switch2' incorporates:
    //   Constant: '<S497>/Clamping_zero'
    //   Constant: '<S497>/Constant3'
    //   Constant: '<S497>/Constant4'
    //   RelationalOperator: '<S497>/fix for DT propagation issue1'

    if (Copy_of_HITL_HEXA_MISSION_B.IProdOut >
        Copy_of_HITL_HEXA_MISSION_P.Clamping_zero_Value_d) {
      rtb_Switch1_a = Copy_of_HITL_HEXA_MISSION_P.Constant3_Value_k;
    } else {
      rtb_Switch1_a = Copy_of_HITL_HEXA_MISSION_P.Constant4_Value_n;
    }

    // Switch: '<S497>/Switch' incorporates:
    //   Constant: '<S497>/Constant1'
    //   Logic: '<S497>/AND3'
    //   RelationalOperator: '<S497>/Equal1'
    //   Switch: '<S497>/Switch1'
    //   Switch: '<S497>/Switch2'

    if (rtb_RelationalOperator && (tmp == rtb_Switch1_a)) {
      rtb_Switch_pn = Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_jx;
    } else {
      rtb_Switch_pn = Copy_of_HITL_HEXA_MISSION_B.IProdOut;
    }

    // End of Switch: '<S497>/Switch'

    // Sum: '<S30>/Sum1'
    rtb_Sum1 = Copy_of_HITL_HEXA_MISSION_B.Switch2_n -
      Copy_of_HITL_HEXA_MISSION_B.In1_l.xyz[0];

    // MATLABSystem: '<S30>/Read Parameter24'
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_n.SampleTime !=
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter24_SampleTime) {
      Copy_of_HITL_HEXA_MISSION_DW.obj_n.SampleTime =
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter24_SampleTime;
    }

    b_varargout_2 = MW_Param_Step
      (Copy_of_HITL_HEXA_MISSION_DW.obj_n.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S562>/NProd Out' incorporates:
    //   Constant: '<S30>/Constant2'
    //   DiscreteIntegrator: '<S554>/Filter'
    //   MATLABSystem: '<S30>/Read Parameter24'
    //   Product: '<S552>/DProd Out'
    //   Sum: '<S554>/SumD'
    //
    rtb_NProdOut_bg = (rtb_Sum1 * ParamStep -
                       Copy_of_HITL_HEXA_MISSION_DW.Filter_DSTATE_l) *
      Copy_of_HITL_HEXA_MISSION_P.Constant2_Value_n;

    // MATLABSystem: '<S30>/Read Parameter22'
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_d.SampleTime !=
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter22_SampleTime) {
      Copy_of_HITL_HEXA_MISSION_DW.obj_d.SampleTime =
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter22_SampleTime;
    }

    b_varargout_2 = MW_Param_Step
      (Copy_of_HITL_HEXA_MISSION_DW.obj_d.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Sum: '<S568>/Sum' incorporates:
    //   DiscreteIntegrator: '<S559>/Integrator'
    //   MATLABSystem: '<S30>/Read Parameter22'
    //   Product: '<S564>/PProd Out'
    //
    Copy_of_HITL_HEXA_MISSION_B.IProdOut = (rtb_Sum1 * ParamStep +
      Copy_of_HITL_HEXA_MISSION_DW.Integrator_DSTATE_dd) + rtb_NProdOut_bg;

    // Saturate: '<S566>/Saturation' incorporates:
    //   DeadZone: '<S551>/DeadZone'

    if (Copy_of_HITL_HEXA_MISSION_B.IProdOut >
        Copy_of_HITL_HEXA_MISSION_P.PIDController2_UpperSaturationLimit) {
      // Saturate: '<S566>/Saturation'
      Copy_of_HITL_HEXA_MISSION_B.Saturation_b =
        Copy_of_HITL_HEXA_MISSION_P.PIDController2_UpperSaturationLimit;
      Copy_of_HITL_HEXA_MISSION_B.IProdOut -=
        Copy_of_HITL_HEXA_MISSION_P.PIDController2_UpperSaturationLimit;
    } else {
      if (Copy_of_HITL_HEXA_MISSION_B.IProdOut <
          Copy_of_HITL_HEXA_MISSION_P.PIDController2_LowerSaturationLimit) {
        // Saturate: '<S566>/Saturation'
        Copy_of_HITL_HEXA_MISSION_B.Saturation_b =
          Copy_of_HITL_HEXA_MISSION_P.PIDController2_LowerSaturationLimit;
      } else {
        // Saturate: '<S566>/Saturation'
        Copy_of_HITL_HEXA_MISSION_B.Saturation_b =
          Copy_of_HITL_HEXA_MISSION_B.IProdOut;
      }

      if (Copy_of_HITL_HEXA_MISSION_B.IProdOut >=
          Copy_of_HITL_HEXA_MISSION_P.PIDController2_LowerSaturationLimit) {
        Copy_of_HITL_HEXA_MISSION_B.IProdOut = 0.0;
      } else {
        Copy_of_HITL_HEXA_MISSION_B.IProdOut -=
          Copy_of_HITL_HEXA_MISSION_P.PIDController2_LowerSaturationLimit;
      }
    }

    // End of Saturate: '<S566>/Saturation'

    // RelationalOperator: '<S549>/Relational Operator' incorporates:
    //   Constant: '<S549>/Clamping_zero'

    rtb_RelationalOperator = (Copy_of_HITL_HEXA_MISSION_P.Clamping_zero_Value_e
      != Copy_of_HITL_HEXA_MISSION_B.IProdOut);

    // Switch: '<S549>/Switch1' incorporates:
    //   Constant: '<S549>/Clamping_zero'
    //   Constant: '<S549>/Constant'
    //   Constant: '<S549>/Constant2'
    //   RelationalOperator: '<S549>/fix for DT propagation issue'

    if (Copy_of_HITL_HEXA_MISSION_B.IProdOut >
        Copy_of_HITL_HEXA_MISSION_P.Clamping_zero_Value_e) {
      rtb_Switch1_a = Copy_of_HITL_HEXA_MISSION_P.Constant_Value_k;
    } else {
      rtb_Switch1_a = Copy_of_HITL_HEXA_MISSION_P.Constant2_Value_m;
    }

    // End of Switch: '<S549>/Switch1'

    // MATLABSystem: '<S30>/Read Parameter23'
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_f.SampleTime !=
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter23_SampleTime) {
      Copy_of_HITL_HEXA_MISSION_DW.obj_f.SampleTime =
        Copy_of_HITL_HEXA_MISSION_P.ReadParameter23_SampleTime;
    }

    b_varargout_2 = MW_Param_Step
      (Copy_of_HITL_HEXA_MISSION_DW.obj_f.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S556>/IProd Out' incorporates:
    //   MATLABSystem: '<S30>/Read Parameter23'
    //
    Copy_of_HITL_HEXA_MISSION_B.IProdOut = rtb_Sum1 * ParamStep;

    // Update for DiscreteIntegrator: '<S450>/Filter'
    Copy_of_HITL_HEXA_MISSION_DW.Filter_DSTATE +=
      Copy_of_HITL_HEXA_MISSION_P.Filter_gainval_f * rtb_NProdOut;

    // Update for DiscreteIntegrator: '<S455>/Integrator'
    Copy_of_HITL_HEXA_MISSION_DW.Integrator_DSTATE +=
      Copy_of_HITL_HEXA_MISSION_P.Integrator_gainval_h * rtb_Switch_i;

    // Update for DiscreteIntegrator: '<S502>/Filter'
    Copy_of_HITL_HEXA_MISSION_DW.Filter_DSTATE_h +=
      Copy_of_HITL_HEXA_MISSION_P.Filter_gainval_l * rtb_NProdOut_f;

    // Update for DiscreteIntegrator: '<S507>/Integrator'
    Copy_of_HITL_HEXA_MISSION_DW.Integrator_DSTATE_d +=
      Copy_of_HITL_HEXA_MISSION_P.Integrator_gainval_b * rtb_Switch_pn;

    // Update for DiscreteIntegrator: '<S554>/Filter'
    Copy_of_HITL_HEXA_MISSION_DW.Filter_DSTATE_l +=
      Copy_of_HITL_HEXA_MISSION_P.Filter_gainval_a * rtb_NProdOut_bg;

    // Switch: '<S549>/Switch2' incorporates:
    //   Constant: '<S549>/Clamping_zero'
    //   Constant: '<S549>/Constant3'
    //   Constant: '<S549>/Constant4'
    //   RelationalOperator: '<S549>/fix for DT propagation issue1'

    if (Copy_of_HITL_HEXA_MISSION_B.IProdOut >
        Copy_of_HITL_HEXA_MISSION_P.Clamping_zero_Value_e) {
      tmp = Copy_of_HITL_HEXA_MISSION_P.Constant3_Value_d;
    } else {
      tmp = Copy_of_HITL_HEXA_MISSION_P.Constant4_Value_b;
    }

    // Switch: '<S549>/Switch' incorporates:
    //   Constant: '<S549>/Constant1'
    //   Logic: '<S549>/AND3'
    //   RelationalOperator: '<S549>/Equal1'
    //   Switch: '<S549>/Switch2'

    if (rtb_RelationalOperator && (rtb_Switch1_a == tmp)) {
      Copy_of_HITL_HEXA_MISSION_B.IProdOut =
        Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_ka;
    }

    // Update for DiscreteIntegrator: '<S559>/Integrator' incorporates:
    //   Switch: '<S549>/Switch'

    Copy_of_HITL_HEXA_MISSION_DW.Integrator_DSTATE_dd +=
      Copy_of_HITL_HEXA_MISSION_P.Integrator_gainval_n *
      Copy_of_HITL_HEXA_MISSION_B.IProdOut;
  }

  // End of Outputs for SubSystem: '<S23>/mc_rate_controller'
}

// Termination for enable system: '<S23>/mc_rate_controller'
void Copy_of_HITL_HEXA_MISSION_mc_rate_controller_Term(void)
{
  // Terminate for MATLABSystem: '<S30>/Read Parameter21'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_j.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter21'

  // Terminate for MATLABSystem: '<S30>/Read Parameter19'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_nu.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_nu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter19'

  // Terminate for MATLABSystem: '<S30>/Read Parameter20'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_l.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter20'

  // Terminate for MATLABSystem: '<S30>/Read Parameter18'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_h.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter18'

  // Terminate for MATLABSystem: '<S30>/Read Parameter16'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_gu.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_gu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter16'

  // Terminate for MATLABSystem: '<S30>/Read Parameter17'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_hj.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_hj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter17'

  // Terminate for MATLABSystem: '<S30>/Read Parameter24'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_n.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter24'

  // Terminate for MATLABSystem: '<S30>/Read Parameter22'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_d.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter22'

  // Terminate for MATLABSystem: '<S30>/Read Parameter23'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_f.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter23'
}

//
// File trailer for generated code.
//
// [EOF]
//
