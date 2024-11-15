//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Mixer_FaultInjection.cpp
//
// Code generated for Simulink model 'Mixer_FaultInjection'.
//
// Model version                  : 4.142
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Aug 23 16:15:46 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Mixer_FaultInjection.h"
#include "calcFaultInjectedPWM.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rtwtypes.h"
#include "Mixer_FaultInjection_private.h"

// Block signals (default storage)
B_Mixer_FaultInjection_T Mixer_FaultInjection_B;

// Block states (default storage)
DW_Mixer_FaultInjection_T Mixer_FaultInjection_DW;

// Real-time model
RT_MODEL_Mixer_FaultInjection_T Mixer_FaultInjection_M_ =
  RT_MODEL_Mixer_FaultInjection_T();
RT_MODEL_Mixer_FaultInjection_T *const Mixer_FaultInjection_M =
  &Mixer_FaultInjection_M_;

// Model step function
void Mixer_FaultInjection_step(void)
{
  real_T rtb_Switch2;
  real_T rtb_Switch3;
  real_T rtb_Switch4;
  real_T rtb_Switch5;
  real_T tmp;
  int32_T ParamStep;
  real32_T ParamStep_0;
  boolean_T b_varargout_1;
  boolean_T rtb_Compare;

  // MATLABSystem: '<S15>/SourceBlock'
  b_varargout_1 = uORB_read_step(Mixer_FaultInjection_DW.obj_d.orbMetadataObj,
    &Mixer_FaultInjection_DW.obj_d.eventStructObj,
    &Mixer_FaultInjection_B.b_varargout_2, false, 5000.0);

  // Outputs for Enabled SubSystem: '<S15>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S16>/Enable'

  // Start for MATLABSystem: '<S15>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S16>/In1'
    Mixer_FaultInjection_B.In1 = Mixer_FaultInjection_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S15>/Enabled Subsystem'

  // RelationalOperator: '<S7>/Compare' incorporates:
  //   Constant: '<S7>/Constant'
  //   DataTypeConversion: '<S1>/Data Type Conversion'

  rtb_Compare = (Mixer_FaultInjection_B.In1.values[6] >=
                 Mixer_FaultInjection_P.CompareToConstant_const);

  // MATLABSystem: '<S4>/SourceBlock'
  b_varargout_1 = uORB_read_step(Mixer_FaultInjection_DW.obj_f.orbMetadataObj,
    &Mixer_FaultInjection_DW.obj_f.eventStructObj,
    &Mixer_FaultInjection_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S14>/Enable'

  // Start for MATLABSystem: '<S4>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S14>/In1'
    Mixer_FaultInjection_B.In1_m = Mixer_FaultInjection_B.b_varargout_2_c;
  }

  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'

  // MATLABSystem: '<S2>/Read Parameter13'
  if (Mixer_FaultInjection_DW.obj_h.SampleTime !=
      Mixer_FaultInjection_P.ReadParameter13_SampleTime) {
    Mixer_FaultInjection_DW.obj_h.SampleTime =
      Mixer_FaultInjection_P.ReadParameter13_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(Mixer_FaultInjection_DW.obj_h.MW_PARAMHANDLE,
    MW_INT32, &ParamStep);
  if (b_varargout_1) {
    ParamStep = 0;
  }

  // Switch: '<S1>/Switch' incorporates:
  //   Constant: '<S1>/Constant'
  //   DataTypeConversion: '<S2>/Data Type Conversion3'
  //   MATLAB Function: '<Root>/MATLAB Function'
  //   MATLABSystem: '<S2>/Read Parameter13'
  //
  if (rtb_Compare) {
    Mixer_FaultInjection_B.Switch = Mixer_FaultInjection_P.Constant_Value_o;
  } else {
    // Outputs for Atomic SubSystem: '<S2>/CalcFaultInjectedPWM'
    calcFaultInjectedPWM(((-Mixer_FaultInjection_B.In1_m.control[0] -
      Mixer_FaultInjection_B.In1_m.control[2]) *
                          Mixer_FaultInjection_B.In1_m.control[3] / 3.0F +
                          Mixer_FaultInjection_B.In1_m.control[3]) * 1000.0F +
                         1000.0F, static_cast<real_T>(ParamStep),
                         &Mixer_FaultInjection_B.Switch,
                         &Mixer_FaultInjection_P.CalcFaultInjectedPWM);

    // End of Outputs for SubSystem: '<S2>/CalcFaultInjectedPWM'
  }

  // End of Switch: '<S1>/Switch'

  // MATLABSystem: '<S2>/Read Parameter1'
  if (Mixer_FaultInjection_DW.obj_o.SampleTime !=
      Mixer_FaultInjection_P.ReadParameter1_SampleTime) {
    Mixer_FaultInjection_DW.obj_o.SampleTime =
      Mixer_FaultInjection_P.ReadParameter1_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(Mixer_FaultInjection_DW.obj_o.MW_PARAMHANDLE,
    MW_INT32, &ParamStep);
  if (b_varargout_1) {
    ParamStep = 0;
  }

  // Switch: '<S1>/Switch1' incorporates:
  //   Constant: '<S1>/Constant1'
  //   DataTypeConversion: '<S2>/Data Type Conversion1'
  //   MATLAB Function: '<Root>/MATLAB Function'
  //   MATLABSystem: '<S2>/Read Parameter1'
  //
  if (rtb_Compare) {
    Mixer_FaultInjection_B.Switch1 = Mixer_FaultInjection_P.Constant1_Value;
  } else {
    // Outputs for Atomic SubSystem: '<S2>/CalcFaultInjectedPWM1'
    calcFaultInjectedPWM(((Mixer_FaultInjection_B.In1_m.control[0] +
      Mixer_FaultInjection_B.In1_m.control[2]) *
                          Mixer_FaultInjection_B.In1_m.control[3] / 3.0F +
                          Mixer_FaultInjection_B.In1_m.control[3]) * 1000.0F +
                         1000.0F, static_cast<real_T>(ParamStep),
                         &Mixer_FaultInjection_B.Switch1,
                         &Mixer_FaultInjection_P.CalcFaultInjectedPWM1);

    // End of Outputs for SubSystem: '<S2>/CalcFaultInjectedPWM1'
  }

  // End of Switch: '<S1>/Switch1'

  // MATLABSystem: '<S2>/Read Parameter2'
  if (Mixer_FaultInjection_DW.obj_g.SampleTime !=
      Mixer_FaultInjection_P.ReadParameter2_SampleTime) {
    Mixer_FaultInjection_DW.obj_g.SampleTime =
      Mixer_FaultInjection_P.ReadParameter2_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(Mixer_FaultInjection_DW.obj_g.MW_PARAMHANDLE,
    MW_INT32, &ParamStep);
  if (b_varargout_1) {
    ParamStep = 0;
  }

  // Switch: '<S1>/Switch2' incorporates:
  //   Constant: '<S1>/Constant2'
  //   DataTypeConversion: '<S2>/Data Type Conversion2'
  //   MATLAB Function: '<Root>/MATLAB Function'
  //   MATLABSystem: '<S2>/Read Parameter2'
  //
  if (rtb_Compare) {
    rtb_Switch2 = Mixer_FaultInjection_P.Constant2_Value;
  } else {
    // Outputs for Atomic SubSystem: '<S2>/CalcFaultInjectedPWM2'
    calcFaultInjectedPWM((((Mixer_FaultInjection_B.In1_m.control[1] +
      Mixer_FaultInjection_B.In1_m.control[0] / 2.0F) -
      Mixer_FaultInjection_B.In1_m.control[2]) *
                          Mixer_FaultInjection_B.In1_m.control[3] / 3.0F +
                          Mixer_FaultInjection_B.In1_m.control[3]) * 1000.0F +
                         1000.0F, static_cast<real_T>(ParamStep), &rtb_Switch2,
                         &Mixer_FaultInjection_P.CalcFaultInjectedPWM2);

    // End of Outputs for SubSystem: '<S2>/CalcFaultInjectedPWM2'
  }

  // End of Switch: '<S1>/Switch2'

  // MATLABSystem: '<S2>/Read Parameter3'
  if (Mixer_FaultInjection_DW.obj_e.SampleTime !=
      Mixer_FaultInjection_P.ReadParameter3_SampleTime) {
    Mixer_FaultInjection_DW.obj_e.SampleTime =
      Mixer_FaultInjection_P.ReadParameter3_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(Mixer_FaultInjection_DW.obj_e.MW_PARAMHANDLE,
    MW_INT32, &ParamStep);
  if (b_varargout_1) {
    ParamStep = 0;
  }

  // Switch: '<S1>/Switch3' incorporates:
  //   Constant: '<S1>/Constant3'
  //   DataTypeConversion: '<S2>/Data Type Conversion4'
  //   MATLAB Function: '<Root>/MATLAB Function'
  //   MATLABSystem: '<S2>/Read Parameter3'
  //
  if (rtb_Compare) {
    rtb_Switch3 = Mixer_FaultInjection_P.Constant3_Value;
  } else {
    // Outputs for Atomic SubSystem: '<S2>/CalcFaultInjectedPWM3'
    calcFaultInjectedPWM((((-Mixer_FaultInjection_B.In1_m.control[1] -
      Mixer_FaultInjection_B.In1_m.control[0] / 2.0F) +
      Mixer_FaultInjection_B.In1_m.control[2]) *
                          Mixer_FaultInjection_B.In1_m.control[3] / 3.0F +
                          Mixer_FaultInjection_B.In1_m.control[3]) * 1000.0F +
                         1000.0F, static_cast<real_T>(ParamStep), &rtb_Switch3,
                         &Mixer_FaultInjection_P.CalcFaultInjectedPWM3);

    // End of Outputs for SubSystem: '<S2>/CalcFaultInjectedPWM3'
  }

  // End of Switch: '<S1>/Switch3'

  // MATLABSystem: '<S2>/Read Parameter4'
  if (Mixer_FaultInjection_DW.obj.SampleTime !=
      Mixer_FaultInjection_P.ReadParameter4_SampleTime) {
    Mixer_FaultInjection_DW.obj.SampleTime =
      Mixer_FaultInjection_P.ReadParameter4_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(Mixer_FaultInjection_DW.obj.MW_PARAMHANDLE,
    MW_INT32, &ParamStep);
  if (b_varargout_1) {
    ParamStep = 0;
  }

  // Switch: '<S1>/Switch4' incorporates:
  //   Constant: '<S1>/Constant4'
  //   DataTypeConversion: '<S2>/Data Type Conversion5'
  //   MATLAB Function: '<Root>/MATLAB Function'
  //   MATLABSystem: '<S2>/Read Parameter4'
  //
  if (rtb_Compare) {
    rtb_Switch4 = Mixer_FaultInjection_P.Constant4_Value;
  } else {
    // Outputs for Atomic SubSystem: '<S2>/CalcFaultInjectedPWM4'
    calcFaultInjectedPWM((((Mixer_FaultInjection_B.In1_m.control[1] -
      Mixer_FaultInjection_B.In1_m.control[0] / 2.0F) +
      Mixer_FaultInjection_B.In1_m.control[2]) *
                          Mixer_FaultInjection_B.In1_m.control[3] / 3.0F +
                          Mixer_FaultInjection_B.In1_m.control[3]) * 1000.0F +
                         1000.0F, static_cast<real_T>(ParamStep), &rtb_Switch4,
                         &Mixer_FaultInjection_P.CalcFaultInjectedPWM4);

    // End of Outputs for SubSystem: '<S2>/CalcFaultInjectedPWM4'
  }

  // End of Switch: '<S1>/Switch4'

  // MATLABSystem: '<S2>/Read Parameter'
  if (Mixer_FaultInjection_DW.obj_hy.SampleTime !=
      Mixer_FaultInjection_P.ReadParameter_SampleTime) {
    Mixer_FaultInjection_DW.obj_hy.SampleTime =
      Mixer_FaultInjection_P.ReadParameter_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(Mixer_FaultInjection_DW.obj_hy.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep_0);
  if (b_varargout_1) {
    ParamStep_0 = 0.0F;
  }

  // Switch: '<S1>/Switch5' incorporates:
  //   Constant: '<S1>/Constant5'
  //   DataTypeConversion: '<S2>/Data Type Conversion6'
  //   MATLAB Function: '<Root>/MATLAB Function'
  //   MATLABSystem: '<S2>/Read Parameter'
  //
  if (rtb_Compare) {
    rtb_Switch5 = Mixer_FaultInjection_P.Constant5_Value;
  } else {
    // Outputs for Atomic SubSystem: '<S2>/CalcFaultInjectedPWM5'
    calcFaultInjectedPWM((((-Mixer_FaultInjection_B.In1_m.control[1] +
      Mixer_FaultInjection_B.In1_m.control[0] / 2.0F) -
      Mixer_FaultInjection_B.In1_m.control[2]) *
                          Mixer_FaultInjection_B.In1_m.control[3] / 3.0F +
                          Mixer_FaultInjection_B.In1_m.control[3]) * 1000.0F +
                         1000.0F, static_cast<real_T>(ParamStep_0), &rtb_Switch5,
                         &Mixer_FaultInjection_P.CalcFaultInjectedPWM5);

    // End of Outputs for SubSystem: '<S2>/CalcFaultInjectedPWM5'
  }

  // End of Switch: '<S1>/Switch5'

  // BusAssignment: '<S6>/Bus Assignment' incorporates:
  //   Constant: '<S17>/Constant'

  Mixer_FaultInjection_B.BusAssignment = Mixer_FaultInjection_P.Constant_Value;

  // DataTypeConversion: '<S6>/Data Type Conversion1' incorporates:
  //   Constant: '<S6>/Constant17'

  tmp = floor(Mixer_FaultInjection_P.Constant17_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  // BusAssignment: '<S6>/Bus Assignment' incorporates:
  //   Constant: '<S6>/Constant'
  //   DataTypeConversion: '<S6>/Data Type Conversion'
  //   DataTypeConversion: '<S6>/Data Type Conversion1'

  Mixer_FaultInjection_B.BusAssignment.noutputs = tmp < 0.0 ?
    static_cast<uint32_T>(-static_cast<int32_T>(static_cast<uint32_T>(-tmp))) :
    static_cast<uint32_T>(tmp);
  Mixer_FaultInjection_B.BusAssignment.output[0] = static_cast<real32_T>
    (Mixer_FaultInjection_B.Switch);
  Mixer_FaultInjection_B.BusAssignment.output[1] = static_cast<real32_T>
    (Mixer_FaultInjection_B.Switch1);
  Mixer_FaultInjection_B.BusAssignment.output[2] = static_cast<real32_T>
    (rtb_Switch2);
  Mixer_FaultInjection_B.BusAssignment.output[3] = static_cast<real32_T>
    (rtb_Switch3);
  Mixer_FaultInjection_B.BusAssignment.output[4] = static_cast<real32_T>
    (rtb_Switch4);
  Mixer_FaultInjection_B.BusAssignment.output[5] = static_cast<real32_T>
    (rtb_Switch5);
  Mixer_FaultInjection_B.BusAssignment.output[6] = static_cast<real32_T>
    (Mixer_FaultInjection_P.Constant_Value_g);
  Mixer_FaultInjection_B.BusAssignment.output[7] = static_cast<real32_T>
    (Mixer_FaultInjection_P.Constant_Value_g);
  Mixer_FaultInjection_B.BusAssignment.output[8] = static_cast<real32_T>
    (Mixer_FaultInjection_P.Constant_Value_g);
  Mixer_FaultInjection_B.BusAssignment.output[9] = static_cast<real32_T>
    (Mixer_FaultInjection_P.Constant_Value_g);
  Mixer_FaultInjection_B.BusAssignment.output[10] = static_cast<real32_T>
    (Mixer_FaultInjection_P.Constant_Value_g);
  Mixer_FaultInjection_B.BusAssignment.output[11] = static_cast<real32_T>
    (Mixer_FaultInjection_P.Constant_Value_g);
  Mixer_FaultInjection_B.BusAssignment.output[12] = static_cast<real32_T>
    (Mixer_FaultInjection_P.Constant_Value_g);
  Mixer_FaultInjection_B.BusAssignment.output[13] = static_cast<real32_T>
    (Mixer_FaultInjection_P.Constant_Value_g);
  Mixer_FaultInjection_B.BusAssignment.output[14] = static_cast<real32_T>
    (Mixer_FaultInjection_P.Constant_Value_g);
  Mixer_FaultInjection_B.BusAssignment.output[15] = static_cast<real32_T>
    (Mixer_FaultInjection_P.Constant_Value_g);

  // MATLABSystem: '<S18>/SinkBlock' incorporates:
  //   BusAssignment: '<S6>/Bus Assignment'

  uORB_write_step(Mixer_FaultInjection_DW.obj_hyc.orbMetadataObj,
                  &Mixer_FaultInjection_DW.obj_hyc.orbAdvertiseObj,
                  &Mixer_FaultInjection_B.BusAssignment);
}

// Model initialize function
void Mixer_FaultInjection_initialize(void)
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
    real_T tmp;

    // SystemInitialize for Enabled SubSystem: '<S15>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S16>/In1' incorporates:
    //   Outport: '<S16>/Out1'

    Mixer_FaultInjection_B.In1 = Mixer_FaultInjection_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S15>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S14>/In1' incorporates:
    //   Outport: '<S14>/Out1'

    Mixer_FaultInjection_B.In1_m = Mixer_FaultInjection_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S15>/SourceBlock'
    Mixer_FaultInjection_DW.obj_d.matlabCodegenIsDeleted = false;
    Mixer_FaultInjection_DW.obj_d.isInitialized = 1;
    Mixer_FaultInjection_DW.obj_d.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(Mixer_FaultInjection_DW.obj_d.orbMetadataObj,
                         &Mixer_FaultInjection_DW.obj_d.eventStructObj);
    Mixer_FaultInjection_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S4>/SourceBlock'
    Mixer_FaultInjection_DW.obj_f.matlabCodegenIsDeleted = false;
    Mixer_FaultInjection_DW.obj_f.isInitialized = 1;
    Mixer_FaultInjection_DW.obj_f.orbMetadataObj = ORB_ID(actuator_controls_0);
    uORB_read_initialize(Mixer_FaultInjection_DW.obj_f.orbMetadataObj,
                         &Mixer_FaultInjection_DW.obj_f.eventStructObj);
    Mixer_FaultInjection_DW.obj_f.isSetupComplete = true;

    // Start for MATLABSystem: '<S2>/Read Parameter13'
    Mixer_FaultInjection_DW.obj_h.matlabCodegenIsDeleted = false;
    Mixer_FaultInjection_DW.obj_h.SampleTime =
      Mixer_FaultInjection_P.ReadParameter13_SampleTime;
    Mixer_FaultInjection_DW.obj_h.isInitialized = 1;
    if (Mixer_FaultInjection_DW.obj_h.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Mixer_FaultInjection_DW.obj_h.SampleTime;
    }

    Mixer_FaultInjection_DW.obj_h.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr[0], true, tmp * 1000.0);
    Mixer_FaultInjection_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Read Parameter13'

    // Start for MATLABSystem: '<S2>/Read Parameter1'
    Mixer_FaultInjection_DW.obj_o.matlabCodegenIsDeleted = false;
    Mixer_FaultInjection_DW.obj_o.SampleTime =
      Mixer_FaultInjection_P.ReadParameter1_SampleTime;
    Mixer_FaultInjection_DW.obj_o.isInitialized = 1;
    if (Mixer_FaultInjection_DW.obj_o.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Mixer_FaultInjection_DW.obj_o.SampleTime;
    }

    Mixer_FaultInjection_DW.obj_o.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, tmp * 1000.0);
    Mixer_FaultInjection_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Read Parameter1'

    // Start for MATLABSystem: '<S2>/Read Parameter2'
    Mixer_FaultInjection_DW.obj_g.matlabCodegenIsDeleted = false;
    Mixer_FaultInjection_DW.obj_g.SampleTime =
      Mixer_FaultInjection_P.ReadParameter2_SampleTime;
    Mixer_FaultInjection_DW.obj_g.isInitialized = 1;
    if (Mixer_FaultInjection_DW.obj_g.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Mixer_FaultInjection_DW.obj_g.SampleTime;
    }

    Mixer_FaultInjection_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1[0], true, tmp * 1000.0);
    Mixer_FaultInjection_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Read Parameter2'

    // Start for MATLABSystem: '<S2>/Read Parameter3'
    Mixer_FaultInjection_DW.obj_e.matlabCodegenIsDeleted = false;
    Mixer_FaultInjection_DW.obj_e.SampleTime =
      Mixer_FaultInjection_P.ReadParameter3_SampleTime;
    Mixer_FaultInjection_DW.obj_e.isInitialized = 1;
    if (Mixer_FaultInjection_DW.obj_e.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Mixer_FaultInjection_DW.obj_e.SampleTime;
    }

    Mixer_FaultInjection_DW.obj_e.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, tmp * 1000.0);
    Mixer_FaultInjection_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Read Parameter3'

    // Start for MATLABSystem: '<S2>/Read Parameter4'
    Mixer_FaultInjection_DW.obj.matlabCodegenIsDeleted = false;
    Mixer_FaultInjection_DW.obj.SampleTime =
      Mixer_FaultInjection_P.ReadParameter4_SampleTime;
    Mixer_FaultInjection_DW.obj.isInitialized = 1;
    if (Mixer_FaultInjection_DW.obj.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Mixer_FaultInjection_DW.obj.SampleTime;
    }

    Mixer_FaultInjection_DW.obj.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, tmp * 1000.0);
    Mixer_FaultInjection_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Read Parameter4'

    // Start for MATLABSystem: '<S2>/Read Parameter'
    Mixer_FaultInjection_DW.obj_hy.matlabCodegenIsDeleted = false;
    Mixer_FaultInjection_DW.obj_hy.SampleTime =
      Mixer_FaultInjection_P.ReadParameter_SampleTime;
    Mixer_FaultInjection_DW.obj_hy.isInitialized = 1;
    if (Mixer_FaultInjection_DW.obj_hy.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Mixer_FaultInjection_DW.obj_hy.SampleTime;
    }

    Mixer_FaultInjection_DW.obj_hy.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, tmp * 1000.0);
    Mixer_FaultInjection_DW.obj_hy.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Read Parameter'

    // Start for MATLABSystem: '<S18>/SinkBlock' incorporates:
    //   BusAssignment: '<S6>/Bus Assignment'

    Mixer_FaultInjection_DW.obj_hyc.matlabCodegenIsDeleted = false;
    Mixer_FaultInjection_DW.obj_hyc.isInitialized = 1;
    Mixer_FaultInjection_DW.obj_hyc.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_write_initialize(Mixer_FaultInjection_DW.obj_hyc.orbMetadataObj,
                          &Mixer_FaultInjection_DW.obj_hyc.orbAdvertiseObj,
                          &Mixer_FaultInjection_B.BusAssignment_m, 1);
    Mixer_FaultInjection_DW.obj_hyc.isSetupComplete = true;
  }
}

// Model terminate function
void Mixer_FaultInjection_terminate(void)
{
  // Terminate for MATLABSystem: '<S15>/SourceBlock'
  if (!Mixer_FaultInjection_DW.obj_d.matlabCodegenIsDeleted) {
    Mixer_FaultInjection_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Mixer_FaultInjection_DW.obj_d.isInitialized == 1) &&
        Mixer_FaultInjection_DW.obj_d.isSetupComplete) {
      uORB_read_terminate(&Mixer_FaultInjection_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S15>/SourceBlock'

  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!Mixer_FaultInjection_DW.obj_f.matlabCodegenIsDeleted) {
    Mixer_FaultInjection_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Mixer_FaultInjection_DW.obj_f.isInitialized == 1) &&
        Mixer_FaultInjection_DW.obj_f.isSetupComplete) {
      uORB_read_terminate(&Mixer_FaultInjection_DW.obj_f.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'

  // Terminate for MATLABSystem: '<S2>/Read Parameter13'
  if (!Mixer_FaultInjection_DW.obj_h.matlabCodegenIsDeleted) {
    Mixer_FaultInjection_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Read Parameter13'

  // Terminate for MATLABSystem: '<S2>/Read Parameter1'
  if (!Mixer_FaultInjection_DW.obj_o.matlabCodegenIsDeleted) {
    Mixer_FaultInjection_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Read Parameter1'

  // Terminate for MATLABSystem: '<S2>/Read Parameter2'
  if (!Mixer_FaultInjection_DW.obj_g.matlabCodegenIsDeleted) {
    Mixer_FaultInjection_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Read Parameter2'

  // Terminate for MATLABSystem: '<S2>/Read Parameter3'
  if (!Mixer_FaultInjection_DW.obj_e.matlabCodegenIsDeleted) {
    Mixer_FaultInjection_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Read Parameter3'

  // Terminate for MATLABSystem: '<S2>/Read Parameter4'
  if (!Mixer_FaultInjection_DW.obj.matlabCodegenIsDeleted) {
    Mixer_FaultInjection_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Read Parameter4'

  // Terminate for MATLABSystem: '<S2>/Read Parameter'
  if (!Mixer_FaultInjection_DW.obj_hy.matlabCodegenIsDeleted) {
    Mixer_FaultInjection_DW.obj_hy.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Read Parameter'

  // Terminate for MATLABSystem: '<S18>/SinkBlock'
  if (!Mixer_FaultInjection_DW.obj_hyc.matlabCodegenIsDeleted) {
    Mixer_FaultInjection_DW.obj_hyc.matlabCodegenIsDeleted = true;
    if ((Mixer_FaultInjection_DW.obj_hyc.isInitialized == 1) &&
        Mixer_FaultInjection_DW.obj_hyc.isSetupComplete) {
      uORB_write_terminate(&Mixer_FaultInjection_DW.obj_hyc.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S18>/SinkBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
