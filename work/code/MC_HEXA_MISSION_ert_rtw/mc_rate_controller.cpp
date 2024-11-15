//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mc_rate_controller.cpp
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
#include "mc_rate_controller.h"
#include "MC_HEXA_MISSION.h"
#include "rtwtypes.h"
#include "MC_HEXA_MISSION_private.h"

// System initialize for enable system: '<S23>/mc_rate_controller'
void MC_HEXA_MISSION_mc_rate_controller_Init(void)
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

  // InitializeConditions for DiscreteIntegrator: '<S434>/Filter'
  MC_HEXA_MISSION_DW.Filter_DSTATE =
    MC_HEXA_MISSION_P.PIDController_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S439>/Integrator'
  MC_HEXA_MISSION_DW.Integrator_DSTATE =
    MC_HEXA_MISSION_P.PIDController_InitialConditionForIntegrator;

  // InitializeConditions for DiscreteIntegrator: '<S484>/Filter'
  MC_HEXA_MISSION_DW.Filter_DSTATE_h =
    MC_HEXA_MISSION_P.PIDController1_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S489>/Integrator'
  MC_HEXA_MISSION_DW.Integrator_DSTATE_d =
    MC_HEXA_MISSION_P.PIDController1_InitialConditionForIntegrator;

  // InitializeConditions for DiscreteIntegrator: '<S534>/Filter'
  MC_HEXA_MISSION_DW.Filter_DSTATE_l =
    MC_HEXA_MISSION_P.PIDController2_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S539>/Integrator'
  MC_HEXA_MISSION_DW.Integrator_DSTATE_dd =
    MC_HEXA_MISSION_P.PIDController2_InitialConditionForIntegrator;

  // Start for MATLABSystem: '<S30>/Read Parameter21'
  MC_HEXA_MISSION_DW.obj_j.matlabCodegenIsDeleted = false;
  MC_HEXA_MISSION_DW.obj_j.SampleTime =
    MC_HEXA_MISSION_P.ReadParameter21_SampleTime;
  MC_HEXA_MISSION_DW.obj_j.isInitialized = 1;
  if (MC_HEXA_MISSION_DW.obj_j.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = MC_HEXA_MISSION_DW.obj_j.SampleTime;
  }

  MC_HEXA_MISSION_DW.obj_j.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0],
    true, tmp * 1000.0);
  MC_HEXA_MISSION_DW.obj_j.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter21'

  // Start for MATLABSystem: '<S30>/Read Parameter19'
  MC_HEXA_MISSION_DW.obj_nu.matlabCodegenIsDeleted = false;
  MC_HEXA_MISSION_DW.obj_nu.SampleTime =
    MC_HEXA_MISSION_P.ReadParameter19_SampleTime;
  MC_HEXA_MISSION_DW.obj_nu.isInitialized = 1;
  if (MC_HEXA_MISSION_DW.obj_nu.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = MC_HEXA_MISSION_DW.obj_nu.SampleTime;
  }

  MC_HEXA_MISSION_DW.obj_nu.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_0[0],
    true, tmp * 1000.0);
  MC_HEXA_MISSION_DW.obj_nu.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter19'

  // Start for MATLABSystem: '<S30>/Read Parameter20'
  MC_HEXA_MISSION_DW.obj_l.matlabCodegenIsDeleted = false;
  MC_HEXA_MISSION_DW.obj_l.SampleTime =
    MC_HEXA_MISSION_P.ReadParameter20_SampleTime;
  MC_HEXA_MISSION_DW.obj_l.isInitialized = 1;
  if (MC_HEXA_MISSION_DW.obj_l.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = MC_HEXA_MISSION_DW.obj_l.SampleTime;
  }

  MC_HEXA_MISSION_DW.obj_l.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1[0],
    true, tmp * 1000.0);
  MC_HEXA_MISSION_DW.obj_l.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter20'

  // Start for MATLABSystem: '<S30>/Read Parameter18'
  MC_HEXA_MISSION_DW.obj_h.matlabCodegenIsDeleted = false;
  MC_HEXA_MISSION_DW.obj_h.SampleTime =
    MC_HEXA_MISSION_P.ReadParameter18_SampleTime;
  MC_HEXA_MISSION_DW.obj_h.isInitialized = 1;
  if (MC_HEXA_MISSION_DW.obj_h.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = MC_HEXA_MISSION_DW.obj_h.SampleTime;
  }

  MC_HEXA_MISSION_DW.obj_h.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2[0],
    true, tmp * 1000.0);
  MC_HEXA_MISSION_DW.obj_h.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter18'

  // Start for MATLABSystem: '<S30>/Read Parameter16'
  MC_HEXA_MISSION_DW.obj_gu.matlabCodegenIsDeleted = false;
  MC_HEXA_MISSION_DW.obj_gu.SampleTime =
    MC_HEXA_MISSION_P.ReadParameter16_SampleTime;
  MC_HEXA_MISSION_DW.obj_gu.isInitialized = 1;
  if (MC_HEXA_MISSION_DW.obj_gu.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = MC_HEXA_MISSION_DW.obj_gu.SampleTime;
  }

  MC_HEXA_MISSION_DW.obj_gu.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3[0],
    true, tmp * 1000.0);
  MC_HEXA_MISSION_DW.obj_gu.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter16'

  // Start for MATLABSystem: '<S30>/Read Parameter17'
  MC_HEXA_MISSION_DW.obj_hj.matlabCodegenIsDeleted = false;
  MC_HEXA_MISSION_DW.obj_hj.SampleTime =
    MC_HEXA_MISSION_P.ReadParameter17_SampleTime;
  MC_HEXA_MISSION_DW.obj_hj.isInitialized = 1;
  if (MC_HEXA_MISSION_DW.obj_hj.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = MC_HEXA_MISSION_DW.obj_hj.SampleTime;
  }

  MC_HEXA_MISSION_DW.obj_hj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_4[0],
    true, tmp * 1000.0);
  MC_HEXA_MISSION_DW.obj_hj.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter17'

  // Start for MATLABSystem: '<S30>/Read Parameter24'
  MC_HEXA_MISSION_DW.obj_n.matlabCodegenIsDeleted = false;
  MC_HEXA_MISSION_DW.obj_n.SampleTime =
    MC_HEXA_MISSION_P.ReadParameter24_SampleTime;
  MC_HEXA_MISSION_DW.obj_n.isInitialized = 1;
  if (MC_HEXA_MISSION_DW.obj_n.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = MC_HEXA_MISSION_DW.obj_n.SampleTime;
  }

  MC_HEXA_MISSION_DW.obj_n.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_5[0],
    true, tmp * 1000.0);
  MC_HEXA_MISSION_DW.obj_n.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter24'

  // Start for MATLABSystem: '<S30>/Read Parameter22'
  MC_HEXA_MISSION_DW.obj_d.matlabCodegenIsDeleted = false;
  MC_HEXA_MISSION_DW.obj_d.SampleTime =
    MC_HEXA_MISSION_P.ReadParameter22_SampleTime;
  MC_HEXA_MISSION_DW.obj_d.isInitialized = 1;
  if (MC_HEXA_MISSION_DW.obj_d.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = MC_HEXA_MISSION_DW.obj_d.SampleTime;
  }

  MC_HEXA_MISSION_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_6[0],
    true, tmp * 1000.0);
  MC_HEXA_MISSION_DW.obj_d.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter22'

  // Start for MATLABSystem: '<S30>/Read Parameter23'
  MC_HEXA_MISSION_DW.obj_f.matlabCodegenIsDeleted = false;
  MC_HEXA_MISSION_DW.obj_f.SampleTime =
    MC_HEXA_MISSION_P.ReadParameter23_SampleTime;
  MC_HEXA_MISSION_DW.obj_f.isInitialized = 1;
  if (MC_HEXA_MISSION_DW.obj_f.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = MC_HEXA_MISSION_DW.obj_f.SampleTime;
  }

  MC_HEXA_MISSION_DW.obj_f.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_7[0],
    true, tmp * 1000.0);
  MC_HEXA_MISSION_DW.obj_f.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S30>/Read Parameter23'

  // SystemInitialize for Saturate: '<S446>/Saturation' incorporates:
  //   Outport: '<S30>/tau_yaw'

  MC_HEXA_MISSION_B.Saturation = MC_HEXA_MISSION_P.tau_yaw_Y0;

  // SystemInitialize for Saturate: '<S496>/Saturation' incorporates:
  //   Outport: '<S30>/tau_pitch'

  MC_HEXA_MISSION_B.Saturation_c = MC_HEXA_MISSION_P.tau_pitch_Y0;

  // SystemInitialize for Saturate: '<S546>/Saturation' incorporates:
  //   Outport: '<S30>/tau_roll'

  MC_HEXA_MISSION_B.Saturation_b = MC_HEXA_MISSION_P.tau_roll_Y0;
}

// Output and update for enable system: '<S23>/mc_rate_controller'
void MC_HEXA_MISSION_mc_rate_controller(void)
{
  real32_T ParamStep;

  // Outputs for Enabled SubSystem: '<S23>/mc_rate_controller' incorporates:
  //   EnablePort: '<S30>/Enable'

  if (MC_HEXA_MISSION_B.In1_b.armed) {
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
    MC_HEXA_MISSION_B.IProdOut = MC_HEXA_MISSION_B.Switch2_o -
      MC_HEXA_MISSION_B.In1_l.yawspeed;

    // MATLABSystem: '<S30>/Read Parameter21'
    if (MC_HEXA_MISSION_DW.obj_j.SampleTime !=
        MC_HEXA_MISSION_P.ReadParameter21_SampleTime) {
      MC_HEXA_MISSION_DW.obj_j.SampleTime =
        MC_HEXA_MISSION_P.ReadParameter21_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(MC_HEXA_MISSION_DW.obj_j.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S442>/NProd Out' incorporates:
    //   Constant: '<S30>/Constant'
    //   DiscreteIntegrator: '<S434>/Filter'
    //   MATLABSystem: '<S30>/Read Parameter21'
    //   Product: '<S433>/DProd Out'
    //   Sum: '<S434>/SumD'
    //
    rtb_NProdOut = (MC_HEXA_MISSION_B.IProdOut * ParamStep -
                    MC_HEXA_MISSION_DW.Filter_DSTATE) *
      MC_HEXA_MISSION_P.Constant_Value_pd;

    // MATLABSystem: '<S30>/Read Parameter19'
    if (MC_HEXA_MISSION_DW.obj_nu.SampleTime !=
        MC_HEXA_MISSION_P.ReadParameter19_SampleTime) {
      MC_HEXA_MISSION_DW.obj_nu.SampleTime =
        MC_HEXA_MISSION_P.ReadParameter19_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(MC_HEXA_MISSION_DW.obj_nu.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Sum: '<S448>/Sum' incorporates:
    //   DiscreteIntegrator: '<S439>/Integrator'
    //   MATLABSystem: '<S30>/Read Parameter19'
    //   Product: '<S444>/PProd Out'
    //
    rtb_Sum1 = (MC_HEXA_MISSION_B.IProdOut * ParamStep +
                MC_HEXA_MISSION_DW.Integrator_DSTATE) + rtb_NProdOut;

    // Saturate: '<S446>/Saturation' incorporates:
    //   DeadZone: '<S432>/DeadZone'

    if (rtb_Sum1 > MC_HEXA_MISSION_P.PIDController_UpperSaturationLimit) {
      // Saturate: '<S446>/Saturation'
      MC_HEXA_MISSION_B.Saturation =
        MC_HEXA_MISSION_P.PIDController_UpperSaturationLimit;
      rtb_Sum1 -= MC_HEXA_MISSION_P.PIDController_UpperSaturationLimit;
    } else {
      if (rtb_Sum1 < MC_HEXA_MISSION_P.PIDController_LowerSaturationLimit) {
        // Saturate: '<S446>/Saturation'
        MC_HEXA_MISSION_B.Saturation =
          MC_HEXA_MISSION_P.PIDController_LowerSaturationLimit;
      } else {
        // Saturate: '<S446>/Saturation'
        MC_HEXA_MISSION_B.Saturation = rtb_Sum1;
      }

      if (rtb_Sum1 >= MC_HEXA_MISSION_P.PIDController_LowerSaturationLimit) {
        rtb_Sum1 = 0.0;
      } else {
        rtb_Sum1 -= MC_HEXA_MISSION_P.PIDController_LowerSaturationLimit;
      }
    }

    // End of Saturate: '<S446>/Saturation'

    // RelationalOperator: '<S430>/Relational Operator' incorporates:
    //   Constant: '<S430>/Clamping_zero'

    rtb_RelationalOperator = (MC_HEXA_MISSION_P.Clamping_zero_Value_i !=
      rtb_Sum1);

    // RelationalOperator: '<S430>/fix for DT propagation issue' incorporates:
    //   Constant: '<S430>/Clamping_zero'

    rtb_fixforDTpropagationissue_lk = (rtb_Sum1 >
      MC_HEXA_MISSION_P.Clamping_zero_Value_i);

    // MATLABSystem: '<S30>/Read Parameter20'
    if (MC_HEXA_MISSION_DW.obj_l.SampleTime !=
        MC_HEXA_MISSION_P.ReadParameter20_SampleTime) {
      MC_HEXA_MISSION_DW.obj_l.SampleTime =
        MC_HEXA_MISSION_P.ReadParameter20_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(MC_HEXA_MISSION_DW.obj_l.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S436>/IProd Out' incorporates:
    //   MATLABSystem: '<S30>/Read Parameter20'
    //
    rtb_Sum1 = MC_HEXA_MISSION_B.IProdOut * ParamStep;

    // Switch: '<S430>/Switch1' incorporates:
    //   Constant: '<S430>/Constant'
    //   Constant: '<S430>/Constant2'

    if (rtb_fixforDTpropagationissue_lk) {
      tmp = MC_HEXA_MISSION_P.Constant_Value_dt;
    } else {
      tmp = MC_HEXA_MISSION_P.Constant2_Value_l;
    }

    // Switch: '<S430>/Switch2' incorporates:
    //   Constant: '<S430>/Clamping_zero'
    //   Constant: '<S430>/Constant3'
    //   Constant: '<S430>/Constant4'
    //   RelationalOperator: '<S430>/fix for DT propagation issue1'

    if (rtb_Sum1 > MC_HEXA_MISSION_P.Clamping_zero_Value_i) {
      rtb_Switch1_a = MC_HEXA_MISSION_P.Constant3_Value_j;
    } else {
      rtb_Switch1_a = MC_HEXA_MISSION_P.Constant4_Value_c;
    }

    // Switch: '<S430>/Switch' incorporates:
    //   Constant: '<S430>/Constant1'
    //   Logic: '<S430>/AND3'
    //   RelationalOperator: '<S430>/Equal1'
    //   Switch: '<S430>/Switch1'
    //   Switch: '<S430>/Switch2'

    if (rtb_RelationalOperator && (tmp == rtb_Switch1_a)) {
      rtb_Switch_i = MC_HEXA_MISSION_P.Constant1_Value_k;
    } else {
      rtb_Switch_i = rtb_Sum1;
    }

    // End of Switch: '<S430>/Switch'

    // Sum: '<S30>/Sum'
    rtb_Sum1 = MC_HEXA_MISSION_B.Switch2_l - MC_HEXA_MISSION_B.In1_l.pitchspeed;

    // MATLABSystem: '<S30>/Read Parameter18'
    if (MC_HEXA_MISSION_DW.obj_h.SampleTime !=
        MC_HEXA_MISSION_P.ReadParameter18_SampleTime) {
      MC_HEXA_MISSION_DW.obj_h.SampleTime =
        MC_HEXA_MISSION_P.ReadParameter18_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(MC_HEXA_MISSION_DW.obj_h.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S492>/NProd Out' incorporates:
    //   Constant: '<S30>/Constant1'
    //   DiscreteIntegrator: '<S484>/Filter'
    //   MATLABSystem: '<S30>/Read Parameter18'
    //   Product: '<S483>/DProd Out'
    //   Sum: '<S484>/SumD'
    //
    rtb_NProdOut_f = (rtb_Sum1 * ParamStep - MC_HEXA_MISSION_DW.Filter_DSTATE_h)
      * MC_HEXA_MISSION_P.Constant1_Value_f;

    // MATLABSystem: '<S30>/Read Parameter16'
    if (MC_HEXA_MISSION_DW.obj_gu.SampleTime !=
        MC_HEXA_MISSION_P.ReadParameter16_SampleTime) {
      MC_HEXA_MISSION_DW.obj_gu.SampleTime =
        MC_HEXA_MISSION_P.ReadParameter16_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(MC_HEXA_MISSION_DW.obj_gu.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Sum: '<S498>/Sum' incorporates:
    //   DiscreteIntegrator: '<S489>/Integrator'
    //   MATLABSystem: '<S30>/Read Parameter16'
    //   Product: '<S494>/PProd Out'
    //
    MC_HEXA_MISSION_B.IProdOut = (rtb_Sum1 * ParamStep +
      MC_HEXA_MISSION_DW.Integrator_DSTATE_d) + rtb_NProdOut_f;

    // Saturate: '<S496>/Saturation' incorporates:
    //   DeadZone: '<S482>/DeadZone'

    if (MC_HEXA_MISSION_B.IProdOut >
        MC_HEXA_MISSION_P.PIDController1_UpperSaturationLimit) {
      // Saturate: '<S496>/Saturation'
      MC_HEXA_MISSION_B.Saturation_c =
        MC_HEXA_MISSION_P.PIDController1_UpperSaturationLimit;
      MC_HEXA_MISSION_B.IProdOut -=
        MC_HEXA_MISSION_P.PIDController1_UpperSaturationLimit;
    } else {
      if (MC_HEXA_MISSION_B.IProdOut <
          MC_HEXA_MISSION_P.PIDController1_LowerSaturationLimit) {
        // Saturate: '<S496>/Saturation'
        MC_HEXA_MISSION_B.Saturation_c =
          MC_HEXA_MISSION_P.PIDController1_LowerSaturationLimit;
      } else {
        // Saturate: '<S496>/Saturation'
        MC_HEXA_MISSION_B.Saturation_c = MC_HEXA_MISSION_B.IProdOut;
      }

      if (MC_HEXA_MISSION_B.IProdOut >=
          MC_HEXA_MISSION_P.PIDController1_LowerSaturationLimit) {
        MC_HEXA_MISSION_B.IProdOut = 0.0;
      } else {
        MC_HEXA_MISSION_B.IProdOut -=
          MC_HEXA_MISSION_P.PIDController1_LowerSaturationLimit;
      }
    }

    // End of Saturate: '<S496>/Saturation'

    // RelationalOperator: '<S480>/Relational Operator' incorporates:
    //   Constant: '<S480>/Clamping_zero'

    rtb_RelationalOperator = (MC_HEXA_MISSION_P.Clamping_zero_Value_d !=
      MC_HEXA_MISSION_B.IProdOut);

    // RelationalOperator: '<S480>/fix for DT propagation issue' incorporates:
    //   Constant: '<S480>/Clamping_zero'

    rtb_fixforDTpropagationissue_lk = (MC_HEXA_MISSION_B.IProdOut >
      MC_HEXA_MISSION_P.Clamping_zero_Value_d);

    // MATLABSystem: '<S30>/Read Parameter17'
    if (MC_HEXA_MISSION_DW.obj_hj.SampleTime !=
        MC_HEXA_MISSION_P.ReadParameter17_SampleTime) {
      MC_HEXA_MISSION_DW.obj_hj.SampleTime =
        MC_HEXA_MISSION_P.ReadParameter17_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(MC_HEXA_MISSION_DW.obj_hj.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S486>/IProd Out' incorporates:
    //   MATLABSystem: '<S30>/Read Parameter17'
    //
    MC_HEXA_MISSION_B.IProdOut = rtb_Sum1 * ParamStep;

    // Switch: '<S480>/Switch1' incorporates:
    //   Constant: '<S480>/Constant'
    //   Constant: '<S480>/Constant2'

    if (rtb_fixforDTpropagationissue_lk) {
      tmp = MC_HEXA_MISSION_P.Constant_Value_d5;
    } else {
      tmp = MC_HEXA_MISSION_P.Constant2_Value_e;
    }

    // Switch: '<S480>/Switch2' incorporates:
    //   Constant: '<S480>/Clamping_zero'
    //   Constant: '<S480>/Constant3'
    //   Constant: '<S480>/Constant4'
    //   RelationalOperator: '<S480>/fix for DT propagation issue1'

    if (MC_HEXA_MISSION_B.IProdOut > MC_HEXA_MISSION_P.Clamping_zero_Value_d) {
      rtb_Switch1_a = MC_HEXA_MISSION_P.Constant3_Value_k;
    } else {
      rtb_Switch1_a = MC_HEXA_MISSION_P.Constant4_Value_n;
    }

    // Switch: '<S480>/Switch' incorporates:
    //   Constant: '<S480>/Constant1'
    //   Logic: '<S480>/AND3'
    //   RelationalOperator: '<S480>/Equal1'
    //   Switch: '<S480>/Switch1'
    //   Switch: '<S480>/Switch2'

    if (rtb_RelationalOperator && (tmp == rtb_Switch1_a)) {
      rtb_Switch_pn = MC_HEXA_MISSION_P.Constant1_Value_jx;
    } else {
      rtb_Switch_pn = MC_HEXA_MISSION_B.IProdOut;
    }

    // End of Switch: '<S480>/Switch'

    // Sum: '<S30>/Sum1'
    rtb_Sum1 = MC_HEXA_MISSION_B.Switch2_n - MC_HEXA_MISSION_B.In1_l.rollspeed;

    // MATLABSystem: '<S30>/Read Parameter24'
    if (MC_HEXA_MISSION_DW.obj_n.SampleTime !=
        MC_HEXA_MISSION_P.ReadParameter24_SampleTime) {
      MC_HEXA_MISSION_DW.obj_n.SampleTime =
        MC_HEXA_MISSION_P.ReadParameter24_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(MC_HEXA_MISSION_DW.obj_n.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S542>/NProd Out' incorporates:
    //   Constant: '<S30>/Constant2'
    //   DiscreteIntegrator: '<S534>/Filter'
    //   MATLABSystem: '<S30>/Read Parameter24'
    //   Product: '<S533>/DProd Out'
    //   Sum: '<S534>/SumD'
    //
    rtb_NProdOut_bg = (rtb_Sum1 * ParamStep - MC_HEXA_MISSION_DW.Filter_DSTATE_l)
      * MC_HEXA_MISSION_P.Constant2_Value_n;

    // MATLABSystem: '<S30>/Read Parameter22'
    if (MC_HEXA_MISSION_DW.obj_d.SampleTime !=
        MC_HEXA_MISSION_P.ReadParameter22_SampleTime) {
      MC_HEXA_MISSION_DW.obj_d.SampleTime =
        MC_HEXA_MISSION_P.ReadParameter22_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(MC_HEXA_MISSION_DW.obj_d.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Sum: '<S548>/Sum' incorporates:
    //   DiscreteIntegrator: '<S539>/Integrator'
    //   MATLABSystem: '<S30>/Read Parameter22'
    //   Product: '<S544>/PProd Out'
    //
    MC_HEXA_MISSION_B.IProdOut = (rtb_Sum1 * ParamStep +
      MC_HEXA_MISSION_DW.Integrator_DSTATE_dd) + rtb_NProdOut_bg;

    // Saturate: '<S546>/Saturation' incorporates:
    //   DeadZone: '<S532>/DeadZone'

    if (MC_HEXA_MISSION_B.IProdOut >
        MC_HEXA_MISSION_P.PIDController2_UpperSaturationLimit) {
      // Saturate: '<S546>/Saturation'
      MC_HEXA_MISSION_B.Saturation_b =
        MC_HEXA_MISSION_P.PIDController2_UpperSaturationLimit;
      MC_HEXA_MISSION_B.IProdOut -=
        MC_HEXA_MISSION_P.PIDController2_UpperSaturationLimit;
    } else {
      if (MC_HEXA_MISSION_B.IProdOut <
          MC_HEXA_MISSION_P.PIDController2_LowerSaturationLimit) {
        // Saturate: '<S546>/Saturation'
        MC_HEXA_MISSION_B.Saturation_b =
          MC_HEXA_MISSION_P.PIDController2_LowerSaturationLimit;
      } else {
        // Saturate: '<S546>/Saturation'
        MC_HEXA_MISSION_B.Saturation_b = MC_HEXA_MISSION_B.IProdOut;
      }

      if (MC_HEXA_MISSION_B.IProdOut >=
          MC_HEXA_MISSION_P.PIDController2_LowerSaturationLimit) {
        MC_HEXA_MISSION_B.IProdOut = 0.0;
      } else {
        MC_HEXA_MISSION_B.IProdOut -=
          MC_HEXA_MISSION_P.PIDController2_LowerSaturationLimit;
      }
    }

    // End of Saturate: '<S546>/Saturation'

    // RelationalOperator: '<S530>/Relational Operator' incorporates:
    //   Constant: '<S530>/Clamping_zero'

    rtb_RelationalOperator = (MC_HEXA_MISSION_P.Clamping_zero_Value_e !=
      MC_HEXA_MISSION_B.IProdOut);

    // Switch: '<S530>/Switch1' incorporates:
    //   Constant: '<S530>/Clamping_zero'
    //   Constant: '<S530>/Constant'
    //   Constant: '<S530>/Constant2'
    //   RelationalOperator: '<S530>/fix for DT propagation issue'

    if (MC_HEXA_MISSION_B.IProdOut > MC_HEXA_MISSION_P.Clamping_zero_Value_e) {
      rtb_Switch1_a = MC_HEXA_MISSION_P.Constant_Value_k;
    } else {
      rtb_Switch1_a = MC_HEXA_MISSION_P.Constant2_Value_m;
    }

    // End of Switch: '<S530>/Switch1'

    // MATLABSystem: '<S30>/Read Parameter23'
    if (MC_HEXA_MISSION_DW.obj_f.SampleTime !=
        MC_HEXA_MISSION_P.ReadParameter23_SampleTime) {
      MC_HEXA_MISSION_DW.obj_f.SampleTime =
        MC_HEXA_MISSION_P.ReadParameter23_SampleTime;
    }

    b_varargout_2 = MW_Param_Step(MC_HEXA_MISSION_DW.obj_f.MW_PARAMHANDLE,
      MW_SINGLE, &ParamStep);
    if (b_varargout_2) {
      ParamStep = 0.0F;
    }

    // Product: '<S536>/IProd Out' incorporates:
    //   MATLABSystem: '<S30>/Read Parameter23'
    //
    MC_HEXA_MISSION_B.IProdOut = rtb_Sum1 * ParamStep;

    // Update for DiscreteIntegrator: '<S434>/Filter'
    MC_HEXA_MISSION_DW.Filter_DSTATE += MC_HEXA_MISSION_P.Filter_gainval_f *
      rtb_NProdOut;

    // Update for DiscreteIntegrator: '<S439>/Integrator'
    MC_HEXA_MISSION_DW.Integrator_DSTATE +=
      MC_HEXA_MISSION_P.Integrator_gainval_h * rtb_Switch_i;

    // Update for DiscreteIntegrator: '<S484>/Filter'
    MC_HEXA_MISSION_DW.Filter_DSTATE_h += MC_HEXA_MISSION_P.Filter_gainval_l *
      rtb_NProdOut_f;

    // Update for DiscreteIntegrator: '<S489>/Integrator'
    MC_HEXA_MISSION_DW.Integrator_DSTATE_d +=
      MC_HEXA_MISSION_P.Integrator_gainval_b * rtb_Switch_pn;

    // Update for DiscreteIntegrator: '<S534>/Filter'
    MC_HEXA_MISSION_DW.Filter_DSTATE_l += MC_HEXA_MISSION_P.Filter_gainval_a *
      rtb_NProdOut_bg;

    // Switch: '<S530>/Switch2' incorporates:
    //   Constant: '<S530>/Clamping_zero'
    //   Constant: '<S530>/Constant3'
    //   Constant: '<S530>/Constant4'
    //   RelationalOperator: '<S530>/fix for DT propagation issue1'

    if (MC_HEXA_MISSION_B.IProdOut > MC_HEXA_MISSION_P.Clamping_zero_Value_e) {
      tmp = MC_HEXA_MISSION_P.Constant3_Value_d;
    } else {
      tmp = MC_HEXA_MISSION_P.Constant4_Value_b;
    }

    // Switch: '<S530>/Switch' incorporates:
    //   Constant: '<S530>/Constant1'
    //   Logic: '<S530>/AND3'
    //   RelationalOperator: '<S530>/Equal1'
    //   Switch: '<S530>/Switch2'

    if (rtb_RelationalOperator && (rtb_Switch1_a == tmp)) {
      MC_HEXA_MISSION_B.IProdOut = MC_HEXA_MISSION_P.Constant1_Value_ka;
    }

    // Update for DiscreteIntegrator: '<S539>/Integrator' incorporates:
    //   Switch: '<S530>/Switch'

    MC_HEXA_MISSION_DW.Integrator_DSTATE_dd +=
      MC_HEXA_MISSION_P.Integrator_gainval_n * MC_HEXA_MISSION_B.IProdOut;
  }

  // End of Outputs for SubSystem: '<S23>/mc_rate_controller'
}

// Termination for enable system: '<S23>/mc_rate_controller'
void MC_HEXA_MISSION_mc_rate_controller_Term(void)
{
  // Terminate for MATLABSystem: '<S30>/Read Parameter21'
  if (!MC_HEXA_MISSION_DW.obj_j.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter21'

  // Terminate for MATLABSystem: '<S30>/Read Parameter19'
  if (!MC_HEXA_MISSION_DW.obj_nu.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_nu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter19'

  // Terminate for MATLABSystem: '<S30>/Read Parameter20'
  if (!MC_HEXA_MISSION_DW.obj_l.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter20'

  // Terminate for MATLABSystem: '<S30>/Read Parameter18'
  if (!MC_HEXA_MISSION_DW.obj_h.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter18'

  // Terminate for MATLABSystem: '<S30>/Read Parameter16'
  if (!MC_HEXA_MISSION_DW.obj_gu.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_gu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter16'

  // Terminate for MATLABSystem: '<S30>/Read Parameter17'
  if (!MC_HEXA_MISSION_DW.obj_hj.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_hj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter17'

  // Terminate for MATLABSystem: '<S30>/Read Parameter24'
  if (!MC_HEXA_MISSION_DW.obj_n.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter24'

  // Terminate for MATLABSystem: '<S30>/Read Parameter22'
  if (!MC_HEXA_MISSION_DW.obj_d.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter22'

  // Terminate for MATLABSystem: '<S30>/Read Parameter23'
  if (!MC_HEXA_MISSION_DW.obj_f.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/Read Parameter23'
}

//
// File trailer for generated code.
//
// [EOF]
//
