//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_hexacopter.cpp
//
// Code generated for Simulink model 'FLIGHT_hexacopter'.
//
// Model version                  : 1.90
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Fri Mar  7 17:53:58 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FLIGHT_hexacopter.h"
#include "FLIGHT_hexacopter_types.h"
#include "rtwtypes.h"
#include "FLIGHT_hexacopter_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"

// Block signals (default storage)
B_FLIGHT_hexacopter_T FLIGHT_hexacopter_B;

// Block states (default storage)
DW_FLIGHT_hexacopter_T FLIGHT_hexacopter_DW;

// Real-time model
RT_MODEL_FLIGHT_hexacopter_T FLIGHT_hexacopter_M_ = RT_MODEL_FLIGHT_hexacopter_T
  ();
RT_MODEL_FLIGHT_hexacopter_T *const FLIGHT_hexacopter_M = &FLIGHT_hexacopter_M_;

// Forward declaration for local functions
static void FLIGHT_hexacopter_PWM_setupImpl(px4_internal_block_PWM_FLIGHT_T *obj,
  boolean_T armPWM, boolean_T forceFailsafe);

// System initialize for atomic system:
void FLIGHT_hexac_ReadParameter_Init(DW_ReadParameter_FLIGHT_hexac_T *localDW)
{
  static const char_T ParameterNameStr[14] = "MPC_THR_HOVER";
  real_T tmp;

  // Start for MATLABSystem: '<S18>/Read Parameter'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  localDW->obj.isInitialized = 1;
  if (localDW->obj.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = localDW->obj.SampleTime;
  }

  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, tmp *
    1000.0);
  localDW->obj.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S18>/Read Parameter'
}

// Output and update for atomic system:
void FLIGHT_hexacopter_ReadParameter(B_ReadParameter_FLIGHT_hexaco_T *localB,
  DW_ReadParameter_FLIGHT_hexac_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S18>/Read Parameter'
  if (localDW->obj.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  b_varargout_2 = MW_Param_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter_o1);
  if (b_varargout_2) {
    localB->ReadParameter_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S18>/Read Parameter'
}

// Termination for atomic system:
void FLIGHT_hexac_ReadParameter_Term(DW_ReadParameter_FLIGHT_hexac_T *localDW)
{
  // Terminate for MATLABSystem: '<S18>/Read Parameter'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S18>/Read Parameter'
}

// System initialize for atomic system:
void FLIGHT_hexa_ReadParameter1_Init(DW_ReadParameter1_FLIGHT_hexa_T *localDW)
{
  static const char_T ParameterNameStr[16] = "MPC_Z_VEL_P_ACC";
  real_T tmp;

  // Start for MATLABSystem: '<S18>/Read Parameter1'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  localDW->obj.isInitialized = 1;
  if (localDW->obj.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = localDW->obj.SampleTime;
  }

  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, tmp *
    1000.0);
  localDW->obj.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S18>/Read Parameter1'
}

// Output and update for atomic system:
void FLIGHT_hexacopte_ReadParameter1(B_ReadParameter1_FLIGHT_hexac_T *localB,
  DW_ReadParameter1_FLIGHT_hexa_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S18>/Read Parameter1'
  if (localDW->obj.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  b_varargout_2 = MW_Param_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter1_o1);
  if (b_varargout_2) {
    localB->ReadParameter1_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S18>/Read Parameter1'
}

// Termination for atomic system:
void FLIGHT_hexa_ReadParameter1_Term(DW_ReadParameter1_FLIGHT_hexa_T *localDW)
{
  // Terminate for MATLABSystem: '<S18>/Read Parameter1'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S18>/Read Parameter1'
}

// System initialize for atomic system:
void FLIGHT_hexa_ReadParameter2_Init(DW_ReadParameter2_FLIGHT_hexa_T *localDW)
{
  static const char_T ParameterNameStr[16] = "MPC_Z_VEL_I_ACC";
  real_T tmp;

  // Start for MATLABSystem: '<S18>/Read Parameter2'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  localDW->obj.isInitialized = 1;
  if (localDW->obj.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = localDW->obj.SampleTime;
  }

  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, tmp *
    1000.0);
  localDW->obj.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S18>/Read Parameter2'
}

// Output and update for atomic system:
void FLIGHT_hexacopte_ReadParameter2(B_ReadParameter2_FLIGHT_hexac_T *localB,
  DW_ReadParameter2_FLIGHT_hexa_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S18>/Read Parameter2'
  if (localDW->obj.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  b_varargout_2 = MW_Param_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter2_o1);
  if (b_varargout_2) {
    localB->ReadParameter2_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S18>/Read Parameter2'
}

// Termination for atomic system:
void FLIGHT_hexa_ReadParameter2_Term(DW_ReadParameter2_FLIGHT_hexa_T *localDW)
{
  // Terminate for MATLABSystem: '<S18>/Read Parameter2'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S18>/Read Parameter2'
}

// System initialize for atomic system:
void FLIGHT_hexa_ReadParameter3_Init(DW_ReadParameter3_FLIGHT_hexa_T *localDW)
{
  static const char_T ParameterNameStr[16] = "MPC_Z_VEL_D_ACC";
  real_T tmp;

  // Start for MATLABSystem: '<S18>/Read Parameter3'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  localDW->obj.isInitialized = 1;
  if (localDW->obj.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = localDW->obj.SampleTime;
  }

  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, tmp *
    1000.0);
  localDW->obj.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S18>/Read Parameter3'
}

// Output and update for atomic system:
void FLIGHT_hexacopte_ReadParameter3(B_ReadParameter3_FLIGHT_hexac_T *localB,
  DW_ReadParameter3_FLIGHT_hexa_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S18>/Read Parameter3'
  if (localDW->obj.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  b_varargout_2 = MW_Param_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter3_o1);
  if (b_varargout_2) {
    localB->ReadParameter3_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S18>/Read Parameter3'
}

// Termination for atomic system:
void FLIGHT_hexa_ReadParameter3_Term(DW_ReadParameter3_FLIGHT_hexa_T *localDW)
{
  // Terminate for MATLABSystem: '<S18>/Read Parameter3'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S18>/Read Parameter3'
}

// System initialize for atomic system:
void FLIGHT_hexaco_PX4Timestamp_Init(DW_PX4Timestamp_FLIGHT_hexaco_T *localDW)
{
  // Start for MATLABSystem: '<S12>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_hexacopter_PX4Timestamp(B_PX4Timestamp_FLIGHT_hexacop_T *localB)
{
  // MATLABSystem: '<S12>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void FLIGHT_hexaco_PX4Timestamp_Term(DW_PX4Timestamp_FLIGHT_hexaco_T *localDW)
{
  // Terminate for MATLABSystem: '<S12>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/PX4 Timestamp'
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = static_cast<real32_T>(atan2(static_cast<real_T>(static_cast<real32_T>
      (tmp)), static_cast<real_T>(static_cast<real32_T>(tmp_0))));
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = static_cast<real32_T>(atan2(static_cast<real_T>(u0), static_cast<real_T>
      (u1)));
  }

  return y;
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if (static_cast<real32_T>(fabs(static_cast<real_T>(u))) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = static_cast<real32_T>(floor(static_cast<real_T>(u + 0.5F)));
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = static_cast<real32_T>(ceil(static_cast<real_T>(u - 0.5F)));
    }
  } else {
    y = u;
  }

  return y;
}

static void FLIGHT_hexacopter_PWM_setupImpl(px4_internal_block_PWM_FLIGHT_T *obj,
  boolean_T armPWM, boolean_T forceFailsafe)
{
  obj->isMain = true;
  pwm_open(&obj->actuatorAdvertiseObj, &obj->armAdvertiseObj);
  obj->servoCount = 8;
  if (armPWM) {
    pwm_arm(&obj->armAdvertiseObj);
    obj->isArmed = true;
  } else {
    pwm_disarm(&obj->armAdvertiseObj);
    obj->isArmed = false;
  }

  obj->channelMask = 63;
  if (obj->isMain) {
    if (forceFailsafe) {
      pwm_disarm(&obj->armAdvertiseObj);
    } else {
      pwm_arm(&obj->armAdvertiseObj);
    }
  }
}

// Model step function
void FLIGHT_hexacopter_step(void)
{
  int32_T i;
  real32_T rtb_NProdOut_ef;
  real32_T rtb_Sum4;
  real32_T rtb_Sum_e;
  real32_T rtb_sincos_o2_idx_0;
  real32_T rtb_sincos_o2_idx_1;
  real32_T rtb_sincos_o2_idx_2;
  real32_T rtb_ypr_0;
  real32_T rtb_ypr_idx_0;
  real32_T rtb_ypr_idx_1;
  real32_T tmp_3;
  uint32_T tmp;
  uint16_T tmp_2;
  int8_T tmp_0;
  int8_T tmp_1;
  boolean_T rtb_AND3_i;
  boolean_T rtb_Compare_a;

  // MATLABSystem: '<S405>/SourceBlock'
  rtb_AND3_i = uORB_read_step(FLIGHT_hexacopter_DW.obj_p2.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_p2.eventStructObj, &FLIGHT_hexacopter_B.r2, false,
    5000.0);

  // Outputs for Enabled SubSystem: '<S405>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S406>/Enable'

  // Start for MATLABSystem: '<S405>/SourceBlock'
  if (rtb_AND3_i) {
    // SignalConversion generated from: '<S406>/In1'
    FLIGHT_hexacopter_B.In1_n = FLIGHT_hexacopter_B.r2;
  }

  // End of Outputs for SubSystem: '<S405>/Enabled Subsystem'

  // MATLABSystem: '<S397>/SourceBlock'
  rtb_AND3_i = uORB_read_step(FLIGHT_hexacopter_DW.obj_k.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_k.eventStructObj, &FLIGHT_hexacopter_B.r, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S397>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S401>/Enable'

  // Start for MATLABSystem: '<S397>/SourceBlock'
  if (rtb_AND3_i) {
    // SignalConversion generated from: '<S401>/In1'
    FLIGHT_hexacopter_B.In1 = FLIGHT_hexacopter_B.r;
  }

  // End of Outputs for SubSystem: '<S397>/Enabled Subsystem'

  // If: '<Root>/If' incorporates:
  //   Constant: '<S560>/Constant'
  //   RelationalOperator: '<S560>/Compare'
  //   SignalConversion generated from: '<S404>/Bus Selector'

  if ((FLIGHT_hexacopter_B.In1_n.values[5] > 1400) &&
      (FLIGHT_hexacopter_B.In1_n.values[5] < 1800)) {
    // Outputs for IfAction SubSystem: '<Root>/Altitude_Mode' incorporates:
    //   ActionPort: '<S1>/Action Port'

    // Saturate: '<S228>/Saturation' incorporates:
    //   DataTypeConversion: '<S17>/Data Type Conversion1'
    //   Fcn: '<S17>/Fcn2'

    FLIGHT_hexacopter_B.Merge = (static_cast<real32_T>
      (FLIGHT_hexacopter_B.In1_n.values[0]) - 1514.0F) / 500.0F;

    // DeadZone: '<S17>/Dead Zone3'
    if (FLIGHT_hexacopter_B.Merge > FLIGHT_hexacopter_P.DeadZone3_End) {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Merge -
        FLIGHT_hexacopter_P.DeadZone3_End;
    } else if (FLIGHT_hexacopter_B.Merge >= FLIGHT_hexacopter_P.DeadZone3_Start)
    {
      FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
    } else {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Merge -
        FLIGHT_hexacopter_P.DeadZone3_Start;
    }

    // End of DeadZone: '<S17>/Dead Zone3'

    // Saturate: '<S17>/Saturation9'
    if (FLIGHT_hexacopter_B.ParamStep_c >
        FLIGHT_hexacopter_P.Saturation9_UpperSat) {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_P.Saturation9_UpperSat;
    } else if (FLIGHT_hexacopter_B.ParamStep_c <
               FLIGHT_hexacopter_P.Saturation9_LowerSat) {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_P.Saturation9_LowerSat;
    }

    // SignalConversion generated from: '<S1>/des_roll' incorporates:
    //   Gain: '<S17>/Gain1'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S17>/Saturation9'

    FLIGHT_hexacopter_B.Merge1[0] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_ROLL *
      FLIGHT_hexacopter_B.ParamStep_c;

    // Saturate: '<S228>/Saturation' incorporates:
    //   DataTypeConversion: '<S17>/Data Type Conversion11'
    //   Fcn: '<S17>/Fcn3'

    FLIGHT_hexacopter_B.Merge = (static_cast<real32_T>
      (FLIGHT_hexacopter_B.In1_n.values[2]) - 1514.0F) / 500.0F;

    // DeadZone: '<S17>/Dead Zone4'
    if (FLIGHT_hexacopter_B.Merge > FLIGHT_hexacopter_P.DeadZone4_End) {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Merge -
        FLIGHT_hexacopter_P.DeadZone4_End;
    } else if (FLIGHT_hexacopter_B.Merge >= FLIGHT_hexacopter_P.DeadZone4_Start)
    {
      FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
    } else {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Merge -
        FLIGHT_hexacopter_P.DeadZone4_Start;
    }

    // End of DeadZone: '<S17>/Dead Zone4'

    // Saturate: '<S17>/Saturation10'
    if (FLIGHT_hexacopter_B.ParamStep_c >
        FLIGHT_hexacopter_P.Saturation10_UpperSat) {
      FLIGHT_hexacopter_B.ParamStep_c =
        FLIGHT_hexacopter_P.Saturation10_UpperSat;
    } else if (FLIGHT_hexacopter_B.ParamStep_c <
               FLIGHT_hexacopter_P.Saturation10_LowerSat) {
      FLIGHT_hexacopter_B.ParamStep_c =
        FLIGHT_hexacopter_P.Saturation10_LowerSat;
    }

    // Saturate: '<S228>/Saturation' incorporates:
    //   Gain: '<S17>/Gain'
    //   Saturate: '<S17>/Saturation10'

    FLIGHT_hexacopter_B.Merge = FLIGHT_hexacopter_P.Gain_Gain_e *
      FLIGHT_hexacopter_B.ParamStep_c;

    // Gain: '<S18>/Gain' incorporates:
    //   Sum: '<S18>/Sum3'

    FLIGHT_hexacopter_B.Saturation3 = (FLIGHT_hexacopter_B.Merge -
      FLIGHT_hexacopter_B.In1.vz) * FLIGHT_hexacopter_P.Gain_Gain_d;
    FLIGHT_hexacopte_ReadParameter2(&FLIGHT_hexacopter_B.ReadParameter2_pn,
      &FLIGHT_hexacopter_DW.ReadParameter2_pn);

    // Product: '<S52>/IProd Out'
    FLIGHT_hexacopter_B.Filter_a = FLIGHT_hexacopter_B.Saturation3 *
      FLIGHT_hexacopter_B.ReadParameter2_pn.ReadParameter2_o1;
    FLIGHT_hexacopte_ReadParameter1(&FLIGHT_hexacopter_B.ReadParameter1_pna,
      &FLIGHT_hexacopter_DW.ReadParameter1_pna);
    FLIGHT_hexacopte_ReadParameter3(&FLIGHT_hexacopter_B.ReadParameter3_pn,
      &FLIGHT_hexacopter_DW.ReadParameter3_pn);

    // Product: '<S58>/NProd Out' incorporates:
    //   Constant: '<S18>/Constant'
    //   DiscreteIntegrator: '<S50>/Filter'
    //   Product: '<S48>/DProd Out'
    //   Sum: '<S50>/SumD'

    FLIGHT_hexacopter_B.Integrator_m = (FLIGHT_hexacopter_B.Saturation3 *
      FLIGHT_hexacopter_B.ReadParameter3_pn.ReadParameter3_o1 -
      FLIGHT_hexacopter_DW.Filter_DSTATE_i) *
      FLIGHT_hexacopter_P.Constant_Value_bi;

    // Sum: '<S64>/Sum' incorporates:
    //   DiscreteIntegrator: '<S55>/Integrator'
    //   Product: '<S60>/PProd Out'

    FLIGHT_hexacopter_B.Saturation3 = (FLIGHT_hexacopter_B.Saturation3 *
      FLIGHT_hexacopter_B.ReadParameter1_pna.ReadParameter1_o1 +
      FLIGHT_hexacopter_DW.Integrator_DSTATE_e) +
      FLIGHT_hexacopter_B.Integrator_m;

    // DeadZone: '<S47>/DeadZone'
    if (FLIGHT_hexacopter_B.Saturation3 >
        FLIGHT_hexacopter_P.PIDController4_UpperSaturationL) {
      FLIGHT_hexacopter_B.DeadZone = FLIGHT_hexacopter_B.Saturation3 -
        FLIGHT_hexacopter_P.PIDController4_UpperSaturationL;
    } else if (FLIGHT_hexacopter_B.Saturation3 >=
               FLIGHT_hexacopter_P.PIDController4_LowerSaturationL) {
      FLIGHT_hexacopter_B.DeadZone = 0.0F;
    } else {
      FLIGHT_hexacopter_B.DeadZone = FLIGHT_hexacopter_B.Saturation3 -
        FLIGHT_hexacopter_P.PIDController4_LowerSaturationL;
    }

    // End of DeadZone: '<S47>/DeadZone'

    // Switch: '<S45>/Switch1' incorporates:
    //   Constant: '<S45>/Clamping_zero'
    //   Constant: '<S45>/Constant'
    //   Constant: '<S45>/Constant2'
    //   RelationalOperator: '<S45>/fix for DT propagation issue'

    if (FLIGHT_hexacopter_B.DeadZone > FLIGHT_hexacopter_P.Clamping_zero_Value)
    {
      tmp_0 = FLIGHT_hexacopter_P.Constant_Value_jc;
    } else {
      tmp_0 = FLIGHT_hexacopter_P.Constant2_Value_mj;
    }

    // Switch: '<S45>/Switch2' incorporates:
    //   Constant: '<S45>/Clamping_zero'
    //   Constant: '<S45>/Constant3'
    //   Constant: '<S45>/Constant4'
    //   RelationalOperator: '<S45>/fix for DT propagation issue1'

    if (FLIGHT_hexacopter_B.Filter_a > FLIGHT_hexacopter_P.Clamping_zero_Value)
    {
      tmp_1 = FLIGHT_hexacopter_P.Constant3_Value_es;
    } else {
      tmp_1 = FLIGHT_hexacopter_P.Constant4_Value_j;
    }

    // Logic: '<S45>/AND3' incorporates:
    //   Constant: '<S45>/Clamping_zero'
    //   RelationalOperator: '<S45>/Equal1'
    //   RelationalOperator: '<S45>/Relational Operator'
    //   Switch: '<S45>/Switch1'
    //   Switch: '<S45>/Switch2'

    rtb_AND3_i = ((FLIGHT_hexacopter_P.Clamping_zero_Value !=
                   FLIGHT_hexacopter_B.DeadZone) && (tmp_0 == tmp_1));
    FLIGHT_hexacopter_ReadParameter(&FLIGHT_hexacopter_B.ReadParameter_pn,
      &FLIGHT_hexacopter_DW.ReadParameter_pn);

    // Saturate: '<S62>/Saturation'
    if (FLIGHT_hexacopter_B.Saturation3 >
        FLIGHT_hexacopter_P.PIDController4_UpperSaturationL) {
      FLIGHT_hexacopter_B.Saturation3 =
        FLIGHT_hexacopter_P.PIDController4_UpperSaturationL;
    } else if (FLIGHT_hexacopter_B.Saturation3 <
               FLIGHT_hexacopter_P.PIDController4_LowerSaturationL) {
      FLIGHT_hexacopter_B.Saturation3 =
        FLIGHT_hexacopter_P.PIDController4_LowerSaturationL;
    }

    // Sum: '<S18>/Sum6' incorporates:
    //   Saturate: '<S62>/Saturation'

    FLIGHT_hexacopter_B.Saturation3 +=
      FLIGHT_hexacopter_B.ReadParameter_pn.ReadParameter_o1;

    // Saturate: '<S18>/Saturation1' incorporates:
    //   Merge: '<Root>/Merge1'

    if (FLIGHT_hexacopter_B.Saturation3 >
        FLIGHT_hexacopter_P.Saturation1_UpperSat) {
      FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_P.Saturation1_UpperSat;
    } else if (FLIGHT_hexacopter_B.Saturation3 <
               FLIGHT_hexacopter_P.Saturation1_LowerSat) {
      FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_P.Saturation1_LowerSat;
    } else {
      FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_B.Saturation3;
    }

    // End of Saturate: '<S18>/Saturation1'

    // Fcn: '<S17>/Fcn7' incorporates:
    //   DataTypeConversion: '<S17>/Data Type Conversion10'

    FLIGHT_hexacopter_B.DeadZone = (static_cast<real32_T>
      (FLIGHT_hexacopter_B.In1_n.values[3]) - 1514.0F) / 500.0F;

    // DeadZone: '<S17>/Dead Zone2'
    if (FLIGHT_hexacopter_B.DeadZone > FLIGHT_hexacopter_P.DeadZone2_End) {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.DeadZone -
        FLIGHT_hexacopter_P.DeadZone2_End;
    } else if (FLIGHT_hexacopter_B.DeadZone >=
               FLIGHT_hexacopter_P.DeadZone2_Start) {
      FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
    } else {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.DeadZone -
        FLIGHT_hexacopter_P.DeadZone2_Start;
    }

    // End of DeadZone: '<S17>/Dead Zone2'

    // Saturate: '<S17>/Saturation3'
    if (FLIGHT_hexacopter_B.ParamStep_c >
        FLIGHT_hexacopter_P.Saturation3_UpperSat) {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_P.Saturation3_UpperSat;
    } else if (FLIGHT_hexacopter_B.ParamStep_c <
               FLIGHT_hexacopter_P.Saturation3_LowerSat) {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_P.Saturation3_LowerSat;
    }

    // SignalConversion generated from: '<S1>/des_r' incorporates:
    //   Gain: '<S17>/Gain3'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S17>/Saturation3'

    FLIGHT_hexacopter_B.Merge1[2] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_RATE_Y
      * FLIGHT_hexacopter_B.ParamStep_c;

    // Fcn: '<S17>/Fcn1' incorporates:
    //   DataTypeConversion: '<S17>/Data Type Conversion2'

    FLIGHT_hexacopter_B.DeadZone = (static_cast<real32_T>
      (FLIGHT_hexacopter_B.In1_n.values[1]) - 1514.0F) / 500.0F;

    // DeadZone: '<S17>/Dead Zone1'
    if (FLIGHT_hexacopter_B.DeadZone > FLIGHT_hexacopter_P.DeadZone1_End) {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.DeadZone -
        FLIGHT_hexacopter_P.DeadZone1_End;
    } else if (FLIGHT_hexacopter_B.DeadZone >=
               FLIGHT_hexacopter_P.DeadZone1_Start) {
      FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
    } else {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.DeadZone -
        FLIGHT_hexacopter_P.DeadZone1_Start;
    }

    // End of DeadZone: '<S17>/Dead Zone1'

    // Saturate: '<S17>/Saturation1'
    if (FLIGHT_hexacopter_B.ParamStep_c >
        FLIGHT_hexacopter_P.Saturation1_UpperSat_d) {
      FLIGHT_hexacopter_B.ParamStep_c =
        FLIGHT_hexacopter_P.Saturation1_UpperSat_d;
    } else if (FLIGHT_hexacopter_B.ParamStep_c <
               FLIGHT_hexacopter_P.Saturation1_LowerSat_b) {
      FLIGHT_hexacopter_B.ParamStep_c =
        FLIGHT_hexacopter_P.Saturation1_LowerSat_b;
    }

    // SignalConversion generated from: '<S1>/des_pitch' incorporates:
    //   Gain: '<S17>/Gain2'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S17>/Saturation1'

    FLIGHT_hexacopter_B.Merge1[1] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_PITCH *
      FLIGHT_hexacopter_B.ParamStep_c;

    // Switch: '<S45>/Switch' incorporates:
    //   Constant: '<S45>/Constant1'

    if (rtb_AND3_i) {
      FLIGHT_hexacopter_B.Filter_a = FLIGHT_hexacopter_P.Constant1_Value_n;
    }

    // Update for DiscreteIntegrator: '<S55>/Integrator' incorporates:
    //   Switch: '<S45>/Switch'

    FLIGHT_hexacopter_DW.Integrator_DSTATE_e +=
      FLIGHT_hexacopter_P.Integrator_gainval * FLIGHT_hexacopter_B.Filter_a;

    // Update for DiscreteIntegrator: '<S50>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_i += FLIGHT_hexacopter_P.Filter_gainval *
      FLIGHT_hexacopter_B.Integrator_m;

    // End of Outputs for SubSystem: '<Root>/Altitude_Mode'
  } else if (FLIGHT_hexacopter_B.In1_n.values[5] >= 1800) {
    // Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
    //   ActionPort: '<S5>/Action Port'

    // Trigonometry: '<S344>/SinCos'
    FLIGHT_hexacopter_B.Filter_a = static_cast<real32_T>(sin(static_cast<real_T>
      (FLIGHT_hexacopter_B.In1.heading)));
    FLIGHT_hexacopter_B.Integrator_m = static_cast<real32_T>(cos
      (static_cast<real_T>(FLIGHT_hexacopter_B.In1.heading)));

    // MATLABSystem: '<S185>/Read Parameter'
    if (FLIGHT_hexacopter_DW.obj_eq.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_eq.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_eq.MW_PARAMHANDLE,
      MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep_c);
    if (rtb_AND3_i) {
      FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
    }

    // Product: '<S330>/PProd Out' incorporates:
    //   Constant: '<S5>/Constant'
    //   MATLABSystem: '<S185>/Read Parameter'
    //   Sum: '<S185>/Sum'
    //
    FLIGHT_hexacopter_B.Saturation3 = (FLIGHT_hexacopter_P.Constant_Value_kn[0]
      - FLIGHT_hexacopter_B.In1.x) * FLIGHT_hexacopter_B.ParamStep_c;

    // Saturate: '<S5>/Saturation'
    if (FLIGHT_hexacopter_B.Saturation3 >
        FLIGHT_hexacopter_P.Saturation_UpperSat_g) {
      // Saturate: '<S5>/Saturation'
      FLIGHT_hexacopter_B.Saturation[0] =
        FLIGHT_hexacopter_P.Saturation_UpperSat_g;
    } else if (FLIGHT_hexacopter_B.Saturation3 <
               FLIGHT_hexacopter_P.Saturation_LowerSat_lt) {
      // Saturate: '<S5>/Saturation'
      FLIGHT_hexacopter_B.Saturation[0] =
        FLIGHT_hexacopter_P.Saturation_LowerSat_lt;
    } else {
      // Saturate: '<S5>/Saturation'
      FLIGHT_hexacopter_B.Saturation[0] = FLIGHT_hexacopter_B.Saturation3;
    }

    // Product: '<S330>/PProd Out' incorporates:
    //   Constant: '<S5>/Constant'
    //   MATLABSystem: '<S185>/Read Parameter'
    //   Sum: '<S185>/Sum'
    //
    FLIGHT_hexacopter_B.Saturation3 = (FLIGHT_hexacopter_P.Constant_Value_kn[1]
      - FLIGHT_hexacopter_B.In1.y) * FLIGHT_hexacopter_B.ParamStep_c;

    // Saturate: '<S5>/Saturation'
    if (FLIGHT_hexacopter_B.Saturation3 >
        FLIGHT_hexacopter_P.Saturation_UpperSat_g) {
      // Saturate: '<S5>/Saturation'
      FLIGHT_hexacopter_B.Saturation[1] =
        FLIGHT_hexacopter_P.Saturation_UpperSat_g;
    } else if (FLIGHT_hexacopter_B.Saturation3 <
               FLIGHT_hexacopter_P.Saturation_LowerSat_lt) {
      // Saturate: '<S5>/Saturation'
      FLIGHT_hexacopter_B.Saturation[1] =
        FLIGHT_hexacopter_P.Saturation_LowerSat_lt;
    } else {
      // Saturate: '<S5>/Saturation'
      FLIGHT_hexacopter_B.Saturation[1] = FLIGHT_hexacopter_B.Saturation3;
    }

    // MATLABSystem: '<S186>/Read Parameter'
    if (FLIGHT_hexacopter_DW.obj_pi.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_pi.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_pi.MW_PARAMHANDLE,
      MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep_c);
    if (rtb_AND3_i) {
      FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
    }

    // Sum: '<S186>/Sum'
    FLIGHT_hexacopter_B.DeadZone = FLIGHT_hexacopter_B.Saturation[0] -
      FLIGHT_hexacopter_B.In1.vx;
    rtb_Sum4 = FLIGHT_hexacopter_B.Saturation[1] - FLIGHT_hexacopter_B.In1.vy;

    // Saturate: '<S186>/Saturation' incorporates:
    //   MATLABSystem: '<S186>/Read Parameter'
    //   Product: '<S342>/MatrixMultiply'
    //   Product: '<S383>/PProd Out'
    //   Reshape: '<S344>/Reshape'
    //   Reshape: '<S344>/Reshape1'
    //
    FLIGHT_hexacopter_B.Saturation3 = (FLIGHT_hexacopter_B.Integrator_m *
      FLIGHT_hexacopter_B.DeadZone + FLIGHT_hexacopter_B.Filter_a * rtb_Sum4) *
      FLIGHT_hexacopter_B.ParamStep_c;

    // SignalConversion generated from: '<S5>/des_xy' incorporates:
    //   Constant: '<S5>/Constant'

    FLIGHT_hexacopter_B.OutportBufferFordes_xy[0] =
      FLIGHT_hexacopter_P.Constant_Value_kn[0];

    // Saturate: '<S186>/Saturation' incorporates:
    //   Gain: '<S344>/Gain'
    //   MATLABSystem: '<S186>/Read Parameter'
    //   Product: '<S342>/MatrixMultiply'
    //   Product: '<S383>/PProd Out'
    //   Reshape: '<S344>/Reshape1'
    //
    FLIGHT_hexacopter_B.Filter_a = (FLIGHT_hexacopter_P.Gain_Gain_a *
      FLIGHT_hexacopter_B.Filter_a * FLIGHT_hexacopter_B.DeadZone +
      FLIGHT_hexacopter_B.Integrator_m * rtb_Sum4) *
      FLIGHT_hexacopter_B.ParamStep_c;

    // SignalConversion generated from: '<S5>/des_xy' incorporates:
    //   Constant: '<S5>/Constant'

    FLIGHT_hexacopter_B.OutportBufferFordes_xy[1] =
      FLIGHT_hexacopter_P.Constant_Value_kn[1];

    // Saturate: '<S186>/Saturation'
    if (FLIGHT_hexacopter_B.Filter_a > FLIGHT_hexacopter_P.Saturation_UpperSat_e)
    {
      // SignalConversion generated from: '<S5>/des_roll' incorporates:
      //   Merge: '<Root>/Merge1'

      FLIGHT_hexacopter_B.Merge1[0] = FLIGHT_hexacopter_P.Saturation_UpperSat_e;
    } else if (FLIGHT_hexacopter_B.Filter_a <
               FLIGHT_hexacopter_P.Saturation_LowerSat_a) {
      // SignalConversion generated from: '<S5>/des_roll' incorporates:
      //   Merge: '<Root>/Merge1'

      FLIGHT_hexacopter_B.Merge1[0] = FLIGHT_hexacopter_P.Saturation_LowerSat_a;
    } else {
      // SignalConversion generated from: '<S5>/des_roll' incorporates:
      //   Merge: '<Root>/Merge1'

      FLIGHT_hexacopter_B.Merge1[0] = FLIGHT_hexacopter_B.Filter_a;
    }

    if (FLIGHT_hexacopter_B.Saturation3 >
        FLIGHT_hexacopter_P.Saturation_UpperSat_e) {
      FLIGHT_hexacopter_B.Saturation3 =
        FLIGHT_hexacopter_P.Saturation_UpperSat_e;
    } else if (FLIGHT_hexacopter_B.Saturation3 <
               FLIGHT_hexacopter_P.Saturation_LowerSat_a) {
      FLIGHT_hexacopter_B.Saturation3 =
        FLIGHT_hexacopter_P.Saturation_LowerSat_a;
    }

    // Gain: '<S186>/Gain1' incorporates:
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S186>/Saturation'

    FLIGHT_hexacopter_B.Merge1[1] = FLIGHT_hexacopter_P.Gain1_Gain *
      FLIGHT_hexacopter_B.Saturation3;

    // Fcn: '<S183>/Fcn3' incorporates:
    //   DataTypeConversion: '<S183>/Data Type Conversion11'

    FLIGHT_hexacopter_B.Filter_a = (static_cast<real32_T>
      (FLIGHT_hexacopter_B.In1_n.values[2]) - 1514.0F) / 500.0F;

    // DeadZone: '<S183>/Dead Zone4'
    if (FLIGHT_hexacopter_B.Filter_a > FLIGHT_hexacopter_P.DeadZone4_End_l) {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Filter_a -
        FLIGHT_hexacopter_P.DeadZone4_End_l;
    } else if (FLIGHT_hexacopter_B.Filter_a >=
               FLIGHT_hexacopter_P.DeadZone4_Start_d) {
      FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
    } else {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Filter_a -
        FLIGHT_hexacopter_P.DeadZone4_Start_d;
    }

    // End of DeadZone: '<S183>/Dead Zone4'

    // Saturate: '<S183>/Saturation10'
    if (FLIGHT_hexacopter_B.ParamStep_c >
        FLIGHT_hexacopter_P.Saturation10_UpperSat_m) {
      FLIGHT_hexacopter_B.ParamStep_c =
        FLIGHT_hexacopter_P.Saturation10_UpperSat_m;
    } else if (FLIGHT_hexacopter_B.ParamStep_c <
               FLIGHT_hexacopter_P.Saturation10_LowerSat_n) {
      FLIGHT_hexacopter_B.ParamStep_c =
        FLIGHT_hexacopter_P.Saturation10_LowerSat_n;
    }

    // Sum: '<S5>/Add' incorporates:
    //   Gain: '<S183>/Gain'
    //   Saturate: '<S183>/Saturation10'

    FLIGHT_hexacopter_B.Add = FLIGHT_hexacopter_P.Gain_Gain_o *
      FLIGHT_hexacopter_B.ParamStep_c + FLIGHT_hexacopter_B.In1.z;

    // MATLABSystem: '<S182>/Read Parameter1'
    if (FLIGHT_hexacopter_DW.obj_m.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_m.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_m.MW_PARAMHANDLE,
      MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep_c);
    if (rtb_AND3_i) {
      FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
    }

    // Saturate: '<S228>/Saturation' incorporates:
    //   MATLABSystem: '<S182>/Read Parameter1'
    //   Product: '<S226>/PProd Out'
    //   Sum: '<S182>/Sum'
    //
    FLIGHT_hexacopter_B.Merge = (FLIGHT_hexacopter_B.Add -
      FLIGHT_hexacopter_B.In1.z) * FLIGHT_hexacopter_B.ParamStep_c;

    // Saturate: '<S228>/Saturation'
    if (FLIGHT_hexacopter_B.Merge >
        FLIGHT_hexacopter_P.PIDController4_UpperSaturatio_h) {
      // Saturate: '<S228>/Saturation'
      FLIGHT_hexacopter_B.Merge =
        FLIGHT_hexacopter_P.PIDController4_UpperSaturatio_h;
    } else if (FLIGHT_hexacopter_B.Merge <
               FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_a) {
      // Saturate: '<S228>/Saturation'
      FLIGHT_hexacopter_B.Merge =
        FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_a;
    }

    // End of Saturate: '<S228>/Saturation'

    // Gain: '<S184>/Gain' incorporates:
    //   Sum: '<S184>/Sum3'

    FLIGHT_hexacopter_B.Filter_a = (FLIGHT_hexacopter_B.Merge -
      FLIGHT_hexacopter_B.In1.vz) * FLIGHT_hexacopter_P.Gain_Gain_b;
    FLIGHT_hexacopte_ReadParameter1(&FLIGHT_hexacopter_B.ReadParameter1_pnaev,
      &FLIGHT_hexacopter_DW.ReadParameter1_pnaev);

    // DiscreteIntegrator: '<S274>/Integrator'
    if ((FLIGHT_hexacopter_B.Merge > 0.0F) &&
        (FLIGHT_hexacopter_DW.Integrator_PrevResetState <= 0)) {
      FLIGHT_hexacopter_DW.Integrator_DSTATE_k =
        FLIGHT_hexacopter_P.PIDController4_InitialConditi_i;
    }

    FLIGHT_hexacopte_ReadParameter3(&FLIGHT_hexacopter_B.ReadParameter3_pna,
      &FLIGHT_hexacopter_DW.ReadParameter3_pna);

    // DiscreteIntegrator: '<S269>/Filter'
    if ((FLIGHT_hexacopter_B.Merge > 0.0F) &&
        (FLIGHT_hexacopter_DW.Filter_PrevResetState <= 0)) {
      FLIGHT_hexacopter_DW.Filter_DSTATE_g =
        FLIGHT_hexacopter_P.PIDController4_InitialConditi_l;
    }

    // Product: '<S277>/NProd Out' incorporates:
    //   Constant: '<S184>/Constant'
    //   DiscreteIntegrator: '<S269>/Filter'
    //   Product: '<S267>/DProd Out'
    //   Sum: '<S269>/SumD'

    FLIGHT_hexacopter_B.Integrator_m = (FLIGHT_hexacopter_B.Filter_a *
      FLIGHT_hexacopter_B.ReadParameter3_pna.ReadParameter3_o1 -
      FLIGHT_hexacopter_DW.Filter_DSTATE_g) *
      FLIGHT_hexacopter_P.Constant_Value_e;

    // Sum: '<S283>/Sum' incorporates:
    //   DiscreteIntegrator: '<S274>/Integrator'
    //   Product: '<S279>/PProd Out'

    FLIGHT_hexacopter_B.DeadZone = (FLIGHT_hexacopter_B.Filter_a *
      FLIGHT_hexacopter_B.ReadParameter1_pnaev.ReadParameter1_o1 +
      FLIGHT_hexacopter_DW.Integrator_DSTATE_k) +
      FLIGHT_hexacopter_B.Integrator_m;
    FLIGHT_hexacopter_ReadParameter(&FLIGHT_hexacopter_B.ReadParameter_pna,
      &FLIGHT_hexacopter_DW.ReadParameter_pna);

    // Saturate: '<S281>/Saturation'
    if (FLIGHT_hexacopter_B.DeadZone >
        FLIGHT_hexacopter_P.PIDController4_UpperSaturati_hy) {
      FLIGHT_hexacopter_B.ParamStep_c =
        FLIGHT_hexacopter_P.PIDController4_UpperSaturati_hy;
    } else if (FLIGHT_hexacopter_B.DeadZone <
               FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_f) {
      FLIGHT_hexacopter_B.ParamStep_c =
        FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_f;
    } else {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.DeadZone;
    }

    // Sum: '<S184>/Sum6' incorporates:
    //   Saturate: '<S281>/Saturation'

    FLIGHT_hexacopter_B.Saturation3 = FLIGHT_hexacopter_B.ParamStep_c +
      FLIGHT_hexacopter_B.ReadParameter_pna.ReadParameter_o1;

    // Saturate: '<S184>/Saturation1' incorporates:
    //   Merge: '<Root>/Merge1'

    if (FLIGHT_hexacopter_B.Saturation3 >
        FLIGHT_hexacopter_P.Saturation1_UpperSat_e) {
      FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_P.Saturation1_UpperSat_e;
    } else if (FLIGHT_hexacopter_B.Saturation3 <
               FLIGHT_hexacopter_P.Saturation1_LowerSat_bn) {
      FLIGHT_hexacopter_B.Merge1[3] =
        FLIGHT_hexacopter_P.Saturation1_LowerSat_bn;
    } else {
      FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_B.Saturation3;
    }

    // End of Saturate: '<S184>/Saturation1'

    // DeadZone: '<S266>/DeadZone'
    if (FLIGHT_hexacopter_B.DeadZone >
        FLIGHT_hexacopter_P.PIDController4_UpperSaturati_hy) {
      FLIGHT_hexacopter_B.DeadZone -=
        FLIGHT_hexacopter_P.PIDController4_UpperSaturati_hy;
    } else if (FLIGHT_hexacopter_B.DeadZone >=
               FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_f) {
      FLIGHT_hexacopter_B.DeadZone = 0.0F;
    } else {
      FLIGHT_hexacopter_B.DeadZone -=
        FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_f;
    }

    // End of DeadZone: '<S266>/DeadZone'
    FLIGHT_hexacopte_ReadParameter2(&FLIGHT_hexacopter_B.ReadParameter2_pna,
      &FLIGHT_hexacopter_DW.ReadParameter2_pna);

    // Product: '<S271>/IProd Out'
    FLIGHT_hexacopter_B.Filter_a *=
      FLIGHT_hexacopter_B.ReadParameter2_pna.ReadParameter2_o1;

    // Fcn: '<S183>/Fcn7' incorporates:
    //   DataTypeConversion: '<S183>/Data Type Conversion10'

    FLIGHT_hexacopter_B.Saturation3 = (static_cast<real32_T>
      (FLIGHT_hexacopter_B.In1_n.values[3]) - 1514.0F) / 500.0F;

    // DeadZone: '<S183>/Dead Zone2'
    if (FLIGHT_hexacopter_B.Saturation3 > FLIGHT_hexacopter_P.DeadZone2_End_k) {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Saturation3 -
        FLIGHT_hexacopter_P.DeadZone2_End_k;
    } else if (FLIGHT_hexacopter_B.Saturation3 >=
               FLIGHT_hexacopter_P.DeadZone2_Start_k) {
      FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
    } else {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Saturation3 -
        FLIGHT_hexacopter_P.DeadZone2_Start_k;
    }

    // End of DeadZone: '<S183>/Dead Zone2'

    // Saturate: '<S183>/Saturation3'
    if (FLIGHT_hexacopter_B.ParamStep_c >
        FLIGHT_hexacopter_P.Saturation3_UpperSat_b) {
      FLIGHT_hexacopter_B.ParamStep_c =
        FLIGHT_hexacopter_P.Saturation3_UpperSat_b;
    } else if (FLIGHT_hexacopter_B.ParamStep_c <
               FLIGHT_hexacopter_P.Saturation3_LowerSat_a) {
      FLIGHT_hexacopter_B.ParamStep_c =
        FLIGHT_hexacopter_P.Saturation3_LowerSat_a;
    }

    // SignalConversion generated from: '<S5>/des_r' incorporates:
    //   Gain: '<S183>/Gain3'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S183>/Saturation3'

    FLIGHT_hexacopter_B.Merge1[2] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_RATE_Y
      * FLIGHT_hexacopter_B.ParamStep_c;

    // Switch: '<S264>/Switch1' incorporates:
    //   Constant: '<S264>/Clamping_zero'
    //   Constant: '<S264>/Constant'
    //   Constant: '<S264>/Constant2'
    //   RelationalOperator: '<S264>/fix for DT propagation issue'

    if (FLIGHT_hexacopter_B.DeadZone > FLIGHT_hexacopter_P.Clamping_zero_Value_f)
    {
      tmp_0 = FLIGHT_hexacopter_P.Constant_Value_mn;
    } else {
      tmp_0 = FLIGHT_hexacopter_P.Constant2_Value_p;
    }

    // Switch: '<S264>/Switch2' incorporates:
    //   Constant: '<S264>/Clamping_zero'
    //   Constant: '<S264>/Constant3'
    //   Constant: '<S264>/Constant4'
    //   RelationalOperator: '<S264>/fix for DT propagation issue1'

    if (FLIGHT_hexacopter_B.Filter_a > FLIGHT_hexacopter_P.Clamping_zero_Value_f)
    {
      tmp_1 = FLIGHT_hexacopter_P.Constant3_Value_n;
    } else {
      tmp_1 = FLIGHT_hexacopter_P.Constant4_Value_i;
    }

    // Switch: '<S264>/Switch' incorporates:
    //   Constant: '<S264>/Clamping_zero'
    //   Constant: '<S264>/Constant1'
    //   Logic: '<S264>/AND3'
    //   RelationalOperator: '<S264>/Equal1'
    //   RelationalOperator: '<S264>/Relational Operator'
    //   Switch: '<S264>/Switch1'
    //   Switch: '<S264>/Switch2'

    if ((FLIGHT_hexacopter_P.Clamping_zero_Value_f !=
         FLIGHT_hexacopter_B.DeadZone) && (tmp_0 == tmp_1)) {
      FLIGHT_hexacopter_B.Filter_a = FLIGHT_hexacopter_P.Constant1_Value_m;
    }

    // Update for DiscreteIntegrator: '<S274>/Integrator' incorporates:
    //   Switch: '<S264>/Switch'

    FLIGHT_hexacopter_DW.Integrator_DSTATE_k +=
      FLIGHT_hexacopter_P.Integrator_gainval_l * FLIGHT_hexacopter_B.Filter_a;
    if (FLIGHT_hexacopter_B.Merge > 0.0F) {
      FLIGHT_hexacopter_DW.Integrator_PrevResetState = 1;
    } else if (FLIGHT_hexacopter_B.Merge < 0.0F) {
      FLIGHT_hexacopter_DW.Integrator_PrevResetState = -1;
    } else if (FLIGHT_hexacopter_B.Merge == 0.0F) {
      FLIGHT_hexacopter_DW.Integrator_PrevResetState = 0;
    } else {
      FLIGHT_hexacopter_DW.Integrator_PrevResetState = 2;
    }

    // End of Update for DiscreteIntegrator: '<S274>/Integrator'

    // Update for DiscreteIntegrator: '<S269>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_g += FLIGHT_hexacopter_P.Filter_gainval_h
      * FLIGHT_hexacopter_B.Integrator_m;
    if (FLIGHT_hexacopter_B.Merge > 0.0F) {
      FLIGHT_hexacopter_DW.Filter_PrevResetState = 1;
    } else if (FLIGHT_hexacopter_B.Merge < 0.0F) {
      FLIGHT_hexacopter_DW.Filter_PrevResetState = -1;
    } else if (FLIGHT_hexacopter_B.Merge == 0.0F) {
      FLIGHT_hexacopter_DW.Filter_PrevResetState = 0;
    } else {
      FLIGHT_hexacopter_DW.Filter_PrevResetState = 2;
    }

    // End of Update for DiscreteIntegrator: '<S269>/Filter'
    // End of Outputs for SubSystem: '<Root>/If Action Subsystem'
  } else {
    // Outputs for IfAction SubSystem: '<Root>/Stabilized_Mode' incorporates:
    //   ActionPort: '<S10>/Action Port'

    // Outputs for Enabled SubSystem: '<S10>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S561>/Enable'

    if (FLIGHT_hexacopter_B.In1_n.values[6] >=
        FLIGHT_hexacopter_P.CompareToConstant_const) {
      // DiscretePulseGenerator: '<S561>/Discrete Pulse Generator'
      FLIGHT_hexacopter_B.Add1 = (FLIGHT_hexacopter_DW.clockTickCounter <
        FLIGHT_hexacopter_P.DiscretePulseGenerator_Duty) &&
        (FLIGHT_hexacopter_DW.clockTickCounter >= 0) ? 8.0 *
        FLIGHT_hexacopter_P.d2r : 0.0;
      if (FLIGHT_hexacopter_DW.clockTickCounter >=
          FLIGHT_hexacopter_P.DiscretePulseGenerator_Period - 1.0) {
        FLIGHT_hexacopter_DW.clockTickCounter = 0;
      } else {
        FLIGHT_hexacopter_DW.clockTickCounter++;
      }

      // End of DiscretePulseGenerator: '<S561>/Discrete Pulse Generator'

      // DataTypeConversion: '<S561>/Data Type Conversion' incorporates:
      //   Constant: '<S561>/Constant'
      //   Sum: '<S561>/Add1'

      FLIGHT_hexacopter_B.DataTypeConversion = static_cast<real32_T>
        (FLIGHT_hexacopter_B.Add1 - 4.0 * FLIGHT_hexacopter_P.d2r);

      // Switch: '<S10>/Switch' incorporates:
      //   Merge: '<Root>/Merge1'

      FLIGHT_hexacopter_B.Merge1[0] = FLIGHT_hexacopter_B.DataTypeConversion;
    } else {
      // Gain: '<S10>/Gain3' incorporates:
      //   Constant: '<S10>/Constant3'
      //   Sum: '<S10>/Sum3'
      //   Switch: '<S10>/Switch'

      FLIGHT_hexacopter_B.Saturation3 = (static_cast<real32_T>
        (FLIGHT_hexacopter_B.In1_n.values[0]) -
        FLIGHT_hexacopter_P.Constant3_Value_e) * FLIGHT_hexacopter_P.Gain3_Gain;

      // DeadZone: '<S10>/Dead Zone' incorporates:
      //   Switch: '<S10>/Switch'

      if (FLIGHT_hexacopter_B.Saturation3 > FLIGHT_hexacopter_P.DeadZone_End) {
        FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Saturation3 -
          FLIGHT_hexacopter_P.DeadZone_End;
      } else if (FLIGHT_hexacopter_B.Saturation3 >=
                 FLIGHT_hexacopter_P.DeadZone_Start) {
        FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
      } else {
        FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Saturation3 -
          FLIGHT_hexacopter_P.DeadZone_Start;
      }

      // End of DeadZone: '<S10>/Dead Zone'

      // Saturate: '<S10>/Saturation3' incorporates:
      //   Switch: '<S10>/Switch'

      if (FLIGHT_hexacopter_B.ParamStep_c >
          FLIGHT_hexacopter_P.Saturation3_UpperSat_b4) {
        FLIGHT_hexacopter_B.ParamStep_c =
          FLIGHT_hexacopter_P.Saturation3_UpperSat_b4;
      } else if (FLIGHT_hexacopter_B.ParamStep_c <
                 FLIGHT_hexacopter_P.Saturation3_LowerSat_j) {
        FLIGHT_hexacopter_B.ParamStep_c =
          FLIGHT_hexacopter_P.Saturation3_LowerSat_j;
      }

      // Switch: '<S10>/Switch' incorporates:
      //   Gain: '<S10>/Gain4'
      //   Merge: '<Root>/Merge1'
      //   Saturate: '<S10>/Saturation3'

      FLIGHT_hexacopter_B.Merge1[0] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_ROLL
        * FLIGHT_hexacopter_B.ParamStep_c;
    }

    // End of Outputs for SubSystem: '<S10>/Enabled Subsystem'

    // Gain: '<S10>/Gain' incorporates:
    //   Constant: '<S10>/Constant'
    //   Sum: '<S10>/Sum'

    FLIGHT_hexacopter_B.Saturation3 = static_cast<real32_T>((static_cast<real_T>
      (FLIGHT_hexacopter_B.In1_n.values[2]) -
      FLIGHT_hexacopter_P.Constant_Value_c) * FLIGHT_hexacopter_P.Gain_Gain);

    // DeadZone: '<S10>/Dead Zone3'
    if (FLIGHT_hexacopter_B.Saturation3 > FLIGHT_hexacopter_P.DeadZone3_End_l) {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Saturation3 -
        FLIGHT_hexacopter_P.DeadZone3_End_l;
    } else if (FLIGHT_hexacopter_B.Saturation3 >=
               FLIGHT_hexacopter_P.DeadZone3_Start_p) {
      FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
    } else {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Saturation3 -
        FLIGHT_hexacopter_P.DeadZone3_Start_p;
    }

    // End of DeadZone: '<S10>/Dead Zone3'

    // Saturate: '<S10>/Saturation'
    if (FLIGHT_hexacopter_B.ParamStep_c >
        FLIGHT_hexacopter_P.Saturation_UpperSat_o) {
      // SignalConversion generated from: '<S10>/throttle' incorporates:
      //   Merge: '<Root>/Merge1'

      FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_P.Saturation_UpperSat_o;
    } else if (FLIGHT_hexacopter_B.ParamStep_c <
               FLIGHT_hexacopter_P.Saturation_LowerSat_el) {
      // SignalConversion generated from: '<S10>/throttle' incorporates:
      //   Merge: '<Root>/Merge1'

      FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_P.Saturation_LowerSat_el;
    } else {
      // SignalConversion generated from: '<S10>/throttle' incorporates:
      //   Merge: '<Root>/Merge1'

      FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_B.ParamStep_c;
    }

    // End of Saturate: '<S10>/Saturation'

    // Gain: '<S10>/Gain2' incorporates:
    //   Constant: '<S10>/Constant1'
    //   Sum: '<S10>/Sum1'

    FLIGHT_hexacopter_B.Saturation3 = (static_cast<real32_T>
      (FLIGHT_hexacopter_B.In1_n.values[3]) -
      FLIGHT_hexacopter_P.Constant1_Value_l) * FLIGHT_hexacopter_P.Gain2_Gain;

    // DeadZone: '<S10>/Dead Zone2'
    if (FLIGHT_hexacopter_B.Saturation3 > FLIGHT_hexacopter_P.DeadZone2_End_e) {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Saturation3 -
        FLIGHT_hexacopter_P.DeadZone2_End_e;
    } else if (FLIGHT_hexacopter_B.Saturation3 >=
               FLIGHT_hexacopter_P.DeadZone2_Start_o) {
      FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
    } else {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Saturation3 -
        FLIGHT_hexacopter_P.DeadZone2_Start_o;
    }

    // End of DeadZone: '<S10>/Dead Zone2'

    // Saturate: '<S10>/Saturation1'
    if (FLIGHT_hexacopter_B.ParamStep_c >
        FLIGHT_hexacopter_P.Saturation1_UpperSat_l) {
      FLIGHT_hexacopter_B.ParamStep_c =
        FLIGHT_hexacopter_P.Saturation1_UpperSat_l;
    } else if (FLIGHT_hexacopter_B.ParamStep_c <
               FLIGHT_hexacopter_P.Saturation1_LowerSat_i) {
      FLIGHT_hexacopter_B.ParamStep_c =
        FLIGHT_hexacopter_P.Saturation1_LowerSat_i;
    }

    // SignalConversion generated from: '<S10>/des_r' incorporates:
    //   Gain: '<S10>/Gain6'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S10>/Saturation1'

    FLIGHT_hexacopter_B.Merge1[2] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_RATE_Y
      * FLIGHT_hexacopter_B.ParamStep_c;

    // Gain: '<S10>/Gain1' incorporates:
    //   Constant: '<S10>/Constant2'
    //   Sum: '<S10>/Sum2'

    FLIGHT_hexacopter_B.Saturation3 = (static_cast<real32_T>
      (FLIGHT_hexacopter_B.In1_n.values[1]) -
      FLIGHT_hexacopter_P.Constant2_Value_i) * FLIGHT_hexacopter_P.Gain1_Gain_m;

    // DeadZone: '<S10>/Dead Zone1'
    if (FLIGHT_hexacopter_B.Saturation3 > FLIGHT_hexacopter_P.DeadZone1_End_m) {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Saturation3 -
        FLIGHT_hexacopter_P.DeadZone1_End_m;
    } else if (FLIGHT_hexacopter_B.Saturation3 >=
               FLIGHT_hexacopter_P.DeadZone1_Start_c) {
      FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
    } else {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_B.Saturation3 -
        FLIGHT_hexacopter_P.DeadZone1_Start_c;
    }

    // End of DeadZone: '<S10>/Dead Zone1'

    // Saturate: '<S10>/Saturation2'
    if (FLIGHT_hexacopter_B.ParamStep_c >
        FLIGHT_hexacopter_P.Saturation2_UpperSat) {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_P.Saturation2_UpperSat;
    } else if (FLIGHT_hexacopter_B.ParamStep_c <
               FLIGHT_hexacopter_P.Saturation2_LowerSat) {
      FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_P.Saturation2_LowerSat;
    }

    // SignalConversion generated from: '<S10>/des_P' incorporates:
    //   Gain: '<S10>/Gain5'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S10>/Saturation2'

    FLIGHT_hexacopter_B.Merge1[1] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_PITCH *
      FLIGHT_hexacopter_B.ParamStep_c;

    // End of Outputs for SubSystem: '<Root>/Stabilized_Mode'
  }

  // End of If: '<Root>/If'

  // MATLABSystem: '<S402>/SourceBlock'
  rtb_AND3_i = uORB_read_step(FLIGHT_hexacopter_DW.obj_ab.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_ab.eventStructObj, &FLIGHT_hexacopter_B.r1, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S402>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S403>/Enable'

  // Start for MATLABSystem: '<S402>/SourceBlock'
  if (rtb_AND3_i) {
    // SignalConversion generated from: '<S403>/In1'
    FLIGHT_hexacopter_B.In1_k = FLIGHT_hexacopter_B.r1;
  }

  // End of Outputs for SubSystem: '<S402>/Enabled Subsystem'

  // MATLABSystem: '<S3>/Read Parameter'
  if (FLIGHT_hexacopter_DW.obj_jz.SampleTime != FLIGHT_hexacopter_P.SampleTime)
  {
    FLIGHT_hexacopter_DW.obj_jz.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_jz.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep_c);
  if (rtb_AND3_i) {
    FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
  }

  // Product: '<S163>/PProd Out' incorporates:
  //   MATLAB Function: '<Root>/quat2eul'
  //   MATLABSystem: '<S3>/Read Parameter'
  //   Sum: '<S3>/Sum3'
  //
  FLIGHT_hexacopter_B.PProdOut_i = (FLIGHT_hexacopter_B.Merge1[0] -
    rt_atan2f_snf((FLIGHT_hexacopter_B.In1_k.q[0] * FLIGHT_hexacopter_B.In1_k.q
                   [1] + FLIGHT_hexacopter_B.In1_k.q[2] *
                   FLIGHT_hexacopter_B.In1_k.q[3]) * 2.0F,
                  ((FLIGHT_hexacopter_B.In1_k.q[0] *
                    FLIGHT_hexacopter_B.In1_k.q[0] -
                    FLIGHT_hexacopter_B.In1_k.q[1] *
                    FLIGHT_hexacopter_B.In1_k.q[1]) -
                   FLIGHT_hexacopter_B.In1_k.q[2] * FLIGHT_hexacopter_B.In1_k.q
                   [2]) + FLIGHT_hexacopter_B.In1_k.q[3] *
                  FLIGHT_hexacopter_B.In1_k.q[3])) *
    FLIGHT_hexacopter_B.ParamStep_c;

  // MATLABSystem: '<S399>/SourceBlock'
  rtb_AND3_i = uORB_read_step(FLIGHT_hexacopter_DW.obj_l.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_l.eventStructObj, &FLIGHT_hexacopter_B.r3, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S399>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S400>/Enable'

  // Start for MATLABSystem: '<S399>/SourceBlock'
  if (rtb_AND3_i) {
    // SignalConversion generated from: '<S400>/In1'
    FLIGHT_hexacopter_B.In1_e = FLIGHT_hexacopter_B.r3;
  }

  // End of Outputs for SubSystem: '<S399>/Enabled Subsystem'

  // Sum: '<S9>/Sum1'
  FLIGHT_hexacopter_B.Saturation3 = FLIGHT_hexacopter_B.PProdOut_i -
    FLIGHT_hexacopter_B.In1_e.x;

  // MATLABSystem: '<S9>/Read Parameter'
  if (FLIGHT_hexacopter_DW.obj_i.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj_i.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_i.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep_c);
  if (rtb_AND3_i) {
    FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
  }

  // MATLABSystem: '<S9>/Read Parameter2'
  if (FLIGHT_hexacopter_DW.obj_d.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj_d.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_d.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep);
  if (rtb_AND3_i) {
    FLIGHT_hexacopter_B.ParamStep = 0.0F;
  }

  // Product: '<S496>/NProd Out' incorporates:
  //   Constant: '<S9>/Constant'
  //   DiscreteIntegrator: '<S488>/Filter'
  //   MATLABSystem: '<S9>/Read Parameter2'
  //   Product: '<S486>/DProd Out'
  //   Sum: '<S488>/SumD'
  //
  FLIGHT_hexacopter_B.Filter_a = (FLIGHT_hexacopter_B.Saturation3 *
    FLIGHT_hexacopter_B.ParamStep - FLIGHT_hexacopter_DW.Filter_DSTATE) *
    FLIGHT_hexacopter_P.Constant_Value_j4;

  // Sum: '<S502>/Sum' incorporates:
  //   DiscreteIntegrator: '<S493>/Integrator'
  //   MATLABSystem: '<S9>/Read Parameter'
  //   Product: '<S498>/PProd Out'
  //
  FLIGHT_hexacopter_B.Sum_c = (FLIGHT_hexacopter_B.Saturation3 *
    FLIGHT_hexacopter_B.ParamStep_c + FLIGHT_hexacopter_DW.Integrator_DSTATE) +
    FLIGHT_hexacopter_B.Filter_a;

  // MATLABSystem: '<S3>/Read Parameter1'
  if (FLIGHT_hexacopter_DW.obj_o.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj_o.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_o.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep_c);
  if (rtb_AND3_i) {
    FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
  }

  // Product: '<S113>/PProd Out' incorporates:
  //   MATLAB Function: '<Root>/quat2eul'
  //   MATLABSystem: '<S3>/Read Parameter1'
  //   Sum: '<S3>/Sum2'
  //
  FLIGHT_hexacopter_B.PProdOut_h = (FLIGHT_hexacopter_B.Merge1[1] -
    static_cast<real32_T>(asin(static_cast<real_T>((FLIGHT_hexacopter_B.In1_k.q
    [1] * FLIGHT_hexacopter_B.In1_k.q[3] - FLIGHT_hexacopter_B.In1_k.q[0] *
    FLIGHT_hexacopter_B.In1_k.q[2]) * -2.0F)))) *
    FLIGHT_hexacopter_B.ParamStep_c;

  // Sum: '<S9>/Sum'
  FLIGHT_hexacopter_B.Integrator_m = FLIGHT_hexacopter_B.PProdOut_h -
    FLIGHT_hexacopter_B.In1_e.y;

  // MATLABSystem: '<S9>/Read Parameter3'
  if (FLIGHT_hexacopter_DW.obj_b.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj_b.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_b.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep_c);
  if (rtb_AND3_i) {
    FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
  }

  // MATLABSystem: '<S9>/Read Parameter5'
  if (FLIGHT_hexacopter_DW.obj_h.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj_h.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_h.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep);
  if (rtb_AND3_i) {
    FLIGHT_hexacopter_B.ParamStep = 0.0F;
  }

  // Product: '<S446>/NProd Out' incorporates:
  //   Constant: '<S9>/Constant1'
  //   DiscreteIntegrator: '<S438>/Filter'
  //   MATLABSystem: '<S9>/Read Parameter5'
  //   Product: '<S436>/DProd Out'
  //   Sum: '<S438>/SumD'
  //
  FLIGHT_hexacopter_B.DeadZone = (FLIGHT_hexacopter_B.Integrator_m *
    FLIGHT_hexacopter_B.ParamStep - FLIGHT_hexacopter_DW.Filter_DSTATE_j) *
    FLIGHT_hexacopter_P.Constant1_Value_f;

  // Sum: '<S452>/Sum' incorporates:
  //   DiscreteIntegrator: '<S443>/Integrator'
  //   MATLABSystem: '<S9>/Read Parameter3'
  //   Product: '<S448>/PProd Out'
  //
  rtb_Sum_e = (FLIGHT_hexacopter_B.Integrator_m *
               FLIGHT_hexacopter_B.ParamStep_c +
               FLIGHT_hexacopter_DW.Integrator_DSTATE_c) +
    FLIGHT_hexacopter_B.DeadZone;

  // Sum: '<S9>/Sum4'
  rtb_Sum4 = FLIGHT_hexacopter_B.Merge1[2] - FLIGHT_hexacopter_B.In1_e.z;

  // MATLABSystem: '<S9>/Read Parameter6'
  if (FLIGHT_hexacopter_DW.obj_a.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj_a.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_a.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep_c);
  if (rtb_AND3_i) {
    FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
  }

  // MATLABSystem: '<S9>/Read Parameter8'
  if (FLIGHT_hexacopter_DW.obj.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj.MW_PARAMHANDLE, MW_SINGLE,
    &FLIGHT_hexacopter_B.ParamStep);
  if (rtb_AND3_i) {
    FLIGHT_hexacopter_B.ParamStep = 0.0F;
  }

  // Product: '<S546>/NProd Out' incorporates:
  //   Constant: '<S9>/Constant2'
  //   DiscreteIntegrator: '<S538>/Filter'
  //   MATLABSystem: '<S9>/Read Parameter8'
  //   Product: '<S536>/DProd Out'
  //   Sum: '<S538>/SumD'
  //
  rtb_NProdOut_ef = (rtb_Sum4 * FLIGHT_hexacopter_B.ParamStep -
                     FLIGHT_hexacopter_DW.Filter_DSTATE_h) *
    FLIGHT_hexacopter_P.Constant2_Value_m;

  // Sum: '<S552>/Sum' incorporates:
  //   DiscreteIntegrator: '<S543>/Integrator'
  //   MATLABSystem: '<S9>/Read Parameter6'
  //   Product: '<S548>/PProd Out'
  //
  FLIGHT_hexacopter_B.ParamStep = (rtb_Sum4 * FLIGHT_hexacopter_B.ParamStep_c +
    FLIGHT_hexacopter_DW.Integrator_DSTATE_l) + rtb_NProdOut_ef;

  // MATLAB Function: '<S6>/pwm_out2'
  FLIGHT_hexacopter_B.ParamStep_c = rt_roundf_snf(((-FLIGHT_hexacopter_B.Sum_c -
    FLIGHT_hexacopter_B.ParamStep) * FLIGHT_hexacopter_B.Merge1[3] / 3.0F +
    FLIGHT_hexacopter_B.Merge1[3]) * 1000.0F);
  if (FLIGHT_hexacopter_B.ParamStep_c < 65536.0F) {
    if (FLIGHT_hexacopter_B.ParamStep_c >= 0.0F) {
      tmp_2 = static_cast<uint16_T>(FLIGHT_hexacopter_B.ParamStep_c);
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint16_T;
  }

  tmp = tmp_2 + 1000U;
  if (FLIGHT_hexacopter_B.ParamStep_c < 65536.0F) {
    if (FLIGHT_hexacopter_B.ParamStep_c >= 0.0F) {
      tmp_2 = static_cast<uint16_T>(FLIGHT_hexacopter_B.ParamStep_c);
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint16_T;
  }

  if (tmp_2 + 1000U > 65535U) {
    tmp = 65535U;
  }

  // Saturate: '<S6>/Output_Limits1' incorporates:
  //   MATLAB Function: '<S6>/pwm_out2'

  if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
  {
    FLIGHT_hexacopter_B.Output_Limits1[0] =
      FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
  } else if (static_cast<uint16_T>(tmp) <
             FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
    FLIGHT_hexacopter_B.Output_Limits1[0] =
      FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
  } else {
    FLIGHT_hexacopter_B.Output_Limits1[0] = static_cast<uint16_T>(tmp);
  }

  // MATLAB Function: '<S6>/pwm_out2'
  FLIGHT_hexacopter_B.ParamStep_c = rt_roundf_snf(((FLIGHT_hexacopter_B.Sum_c +
    FLIGHT_hexacopter_B.ParamStep) * FLIGHT_hexacopter_B.Merge1[3] / 3.0F +
    FLIGHT_hexacopter_B.Merge1[3]) * 1000.0F);
  if (FLIGHT_hexacopter_B.ParamStep_c < 65536.0F) {
    if (FLIGHT_hexacopter_B.ParamStep_c >= 0.0F) {
      tmp_2 = static_cast<uint16_T>(FLIGHT_hexacopter_B.ParamStep_c);
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint16_T;
  }

  tmp = tmp_2 + 1000U;
  if (FLIGHT_hexacopter_B.ParamStep_c < 65536.0F) {
    if (FLIGHT_hexacopter_B.ParamStep_c >= 0.0F) {
      tmp_2 = static_cast<uint16_T>(FLIGHT_hexacopter_B.ParamStep_c);
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint16_T;
  }

  if (tmp_2 + 1000U > 65535U) {
    tmp = 65535U;
  }

  // Saturate: '<S6>/Output_Limits1' incorporates:
  //   MATLAB Function: '<S6>/pwm_out2'

  if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
  {
    FLIGHT_hexacopter_B.Output_Limits1[1] =
      FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
  } else if (static_cast<uint16_T>(tmp) <
             FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
    FLIGHT_hexacopter_B.Output_Limits1[1] =
      FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
  } else {
    FLIGHT_hexacopter_B.Output_Limits1[1] = static_cast<uint16_T>(tmp);
  }

  // MATLAB Function: '<S6>/pwm_out2'
  FLIGHT_hexacopter_B.ParamStep_c = rt_roundf_snf((((FLIGHT_hexacopter_B.Sum_c /
    2.0F + rtb_Sum_e) - FLIGHT_hexacopter_B.ParamStep) *
    FLIGHT_hexacopter_B.Merge1[3] / 3.0F + FLIGHT_hexacopter_B.Merge1[3]) *
    1000.0F);
  if (FLIGHT_hexacopter_B.ParamStep_c < 65536.0F) {
    if (FLIGHT_hexacopter_B.ParamStep_c >= 0.0F) {
      tmp_2 = static_cast<uint16_T>(FLIGHT_hexacopter_B.ParamStep_c);
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint16_T;
  }

  tmp = tmp_2 + 1000U;
  if (FLIGHT_hexacopter_B.ParamStep_c < 65536.0F) {
    if (FLIGHT_hexacopter_B.ParamStep_c >= 0.0F) {
      tmp_2 = static_cast<uint16_T>(FLIGHT_hexacopter_B.ParamStep_c);
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint16_T;
  }

  if (tmp_2 + 1000U > 65535U) {
    tmp = 65535U;
  }

  // Saturate: '<S6>/Output_Limits1' incorporates:
  //   MATLAB Function: '<S6>/pwm_out2'

  if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
  {
    FLIGHT_hexacopter_B.Output_Limits1[2] =
      FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
  } else if (static_cast<uint16_T>(tmp) <
             FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
    FLIGHT_hexacopter_B.Output_Limits1[2] =
      FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
  } else {
    FLIGHT_hexacopter_B.Output_Limits1[2] = static_cast<uint16_T>(tmp);
  }

  // MATLAB Function: '<S6>/pwm_out2'
  FLIGHT_hexacopter_B.ParamStep_c = rt_roundf_snf((((-rtb_Sum_e -
    FLIGHT_hexacopter_B.Sum_c / 2.0F) + FLIGHT_hexacopter_B.ParamStep) *
    FLIGHT_hexacopter_B.Merge1[3] / 3.0F + FLIGHT_hexacopter_B.Merge1[3]) *
    1000.0F);
  if (FLIGHT_hexacopter_B.ParamStep_c < 65536.0F) {
    if (FLIGHT_hexacopter_B.ParamStep_c >= 0.0F) {
      tmp_2 = static_cast<uint16_T>(FLIGHT_hexacopter_B.ParamStep_c);
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint16_T;
  }

  tmp = tmp_2 + 1000U;
  if (FLIGHT_hexacopter_B.ParamStep_c < 65536.0F) {
    if (FLIGHT_hexacopter_B.ParamStep_c >= 0.0F) {
      tmp_2 = static_cast<uint16_T>(FLIGHT_hexacopter_B.ParamStep_c);
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint16_T;
  }

  if (tmp_2 + 1000U > 65535U) {
    tmp = 65535U;
  }

  // Saturate: '<S6>/Output_Limits1' incorporates:
  //   MATLAB Function: '<S6>/pwm_out2'

  if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
  {
    FLIGHT_hexacopter_B.Output_Limits1[3] =
      FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
  } else if (static_cast<uint16_T>(tmp) <
             FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
    FLIGHT_hexacopter_B.Output_Limits1[3] =
      FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
  } else {
    FLIGHT_hexacopter_B.Output_Limits1[3] = static_cast<uint16_T>(tmp);
  }

  // MATLAB Function: '<S6>/pwm_out2'
  FLIGHT_hexacopter_B.ParamStep_c = rt_roundf_snf((((rtb_Sum_e -
    FLIGHT_hexacopter_B.Sum_c / 2.0F) + FLIGHT_hexacopter_B.ParamStep) *
    FLIGHT_hexacopter_B.Merge1[3] / 3.0F + FLIGHT_hexacopter_B.Merge1[3]) *
    1000.0F);
  if (FLIGHT_hexacopter_B.ParamStep_c < 65536.0F) {
    if (FLIGHT_hexacopter_B.ParamStep_c >= 0.0F) {
      tmp_2 = static_cast<uint16_T>(FLIGHT_hexacopter_B.ParamStep_c);
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint16_T;
  }

  tmp = tmp_2 + 1000U;
  if (FLIGHT_hexacopter_B.ParamStep_c < 65536.0F) {
    if (FLIGHT_hexacopter_B.ParamStep_c >= 0.0F) {
      tmp_2 = static_cast<uint16_T>(FLIGHT_hexacopter_B.ParamStep_c);
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint16_T;
  }

  if (tmp_2 + 1000U > 65535U) {
    tmp = 65535U;
  }

  // Saturate: '<S6>/Output_Limits1' incorporates:
  //   MATLAB Function: '<S6>/pwm_out2'

  if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
  {
    FLIGHT_hexacopter_B.Output_Limits1[4] =
      FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
  } else if (static_cast<uint16_T>(tmp) <
             FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
    FLIGHT_hexacopter_B.Output_Limits1[4] =
      FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
  } else {
    FLIGHT_hexacopter_B.Output_Limits1[4] = static_cast<uint16_T>(tmp);
  }

  // MATLAB Function: '<S6>/pwm_out2'
  FLIGHT_hexacopter_B.ParamStep_c = rt_roundf_snf((((FLIGHT_hexacopter_B.Sum_c /
    2.0F - rtb_Sum_e) - FLIGHT_hexacopter_B.ParamStep) *
    FLIGHT_hexacopter_B.Merge1[3] / 3.0F + FLIGHT_hexacopter_B.Merge1[3]) *
    1000.0F);
  if (FLIGHT_hexacopter_B.ParamStep_c < 65536.0F) {
    if (FLIGHT_hexacopter_B.ParamStep_c >= 0.0F) {
      tmp_2 = static_cast<uint16_T>(FLIGHT_hexacopter_B.ParamStep_c);
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint16_T;
  }

  tmp = tmp_2 + 1000U;
  if (FLIGHT_hexacopter_B.ParamStep_c < 65536.0F) {
    if (FLIGHT_hexacopter_B.ParamStep_c >= 0.0F) {
      tmp_2 = static_cast<uint16_T>(FLIGHT_hexacopter_B.ParamStep_c);
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint16_T;
  }

  if (tmp_2 + 1000U > 65535U) {
    tmp = 65535U;
  }

  // Saturate: '<S6>/Output_Limits1' incorporates:
  //   MATLAB Function: '<S6>/pwm_out2'

  if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
  {
    FLIGHT_hexacopter_B.Output_Limits1[5] =
      FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
  } else if (static_cast<uint16_T>(tmp) <
             FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
    FLIGHT_hexacopter_B.Output_Limits1[5] =
      FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
  } else {
    FLIGHT_hexacopter_B.Output_Limits1[5] = static_cast<uint16_T>(tmp);
  }

  // DataTypeConversion: '<S4>/Data Type Conversion6'
  for (i = 0; i < 6; i++) {
    FLIGHT_hexacopter_B.DataTypeConversion6[i] =
      FLIGHT_hexacopter_B.Output_Limits1[i];
  }

  // End of DataTypeConversion: '<S4>/Data Type Conversion6'

  // MATLABSystem: '<S4>/Read Parameter13'
  if (FLIGHT_hexacopter_DW.obj_g.SampleTime !=
      FLIGHT_hexacopter_P.ReadParameter13_SampleTime) {
    FLIGHT_hexacopter_DW.obj_g.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter13_SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_g.MW_PARAMHANDLE, MW_INT32,
    &i);
  if (rtb_AND3_i) {
    i = 0;
  }

  // RelationalOperator: '<S175>/Compare' incorporates:
  //   Constant: '<S175>/Constant'
  //   SignalConversion generated from: '<S404>/Bus Selector'

  rtb_Compare_a = (FLIGHT_hexacopter_B.In1_n.values[7] >=
                   FLIGHT_hexacopter_P.CompareToConstant_const_g);

  // MATLABSystem: '<S4>/Read Parameter1'
  if (FLIGHT_hexacopter_DW.obj_j5.SampleTime !=
      FLIGHT_hexacopter_P.ReadParameter1_SampleTime) {
    FLIGHT_hexacopter_DW.obj_j5.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter1_SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_j5.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_hexacopter_B.ParamStep_k);
  if (rtb_AND3_i) {
    FLIGHT_hexacopter_B.ParamStep_k = 0;
  }

  // MATLABSystem: '<S4>/Read Parameter2'
  if (FLIGHT_hexacopter_DW.obj_ao.SampleTime !=
      FLIGHT_hexacopter_P.ReadParameter2_SampleTime) {
    FLIGHT_hexacopter_DW.obj_ao.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter2_SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_ao.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_hexacopter_B.ParamStep_cx);
  if (rtb_AND3_i) {
    FLIGHT_hexacopter_B.ParamStep_cx = 0;
  }

  // MATLABSystem: '<S4>/Read Parameter3'
  if (FLIGHT_hexacopter_DW.obj_n.SampleTime !=
      FLIGHT_hexacopter_P.ReadParameter3_SampleTime) {
    FLIGHT_hexacopter_DW.obj_n.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter3_SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_n.MW_PARAMHANDLE, MW_INT32,
    &FLIGHT_hexacopter_B.ParamStep_b);
  if (rtb_AND3_i) {
    FLIGHT_hexacopter_B.ParamStep_b = 0;
  }

  // MATLABSystem: '<S4>/Read Parameter4'
  if (FLIGHT_hexacopter_DW.obj_c.SampleTime !=
      FLIGHT_hexacopter_P.ReadParameter4_SampleTime) {
    FLIGHT_hexacopter_DW.obj_c.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter4_SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_c.MW_PARAMHANDLE, MW_INT32,
    &FLIGHT_hexacopter_B.ParamStep_p);
  if (rtb_AND3_i) {
    FLIGHT_hexacopter_B.ParamStep_p = 0;
  }

  // MATLABSystem: '<S4>/Read Parameter5'
  if (FLIGHT_hexacopter_DW.obj_aq.SampleTime !=
      FLIGHT_hexacopter_P.ReadParameter5_SampleTime) {
    FLIGHT_hexacopter_DW.obj_aq.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter5_SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_aq.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_hexacopter_B.ParamStep_cv);
  if (rtb_AND3_i) {
    FLIGHT_hexacopter_B.ParamStep_cv = 0;
  }

  // Switch: '<S4>/Switch' incorporates:
  //   Constant: '<S4>/Constant'
  //   DataTypeConversion: '<S4>/Data Type Conversion3'
  //   MATLABSystem: '<S4>/Read Parameter13'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.Add1 = i;
  } else {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Constant_Value_m;
  }

  // Gain: '<S176>/Gain' incorporates:
  //   Switch: '<S4>/Switch'

  FLIGHT_hexacopter_B.Add1 *= FLIGHT_hexacopter_P.Gain_Gain_j;

  // Saturate: '<S176>/Saturation'
  if (FLIGHT_hexacopter_B.Add1 > FLIGHT_hexacopter_P.Saturation_UpperSat) {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Saturation_UpperSat;
  } else if (FLIGHT_hexacopter_B.Add1 < FLIGHT_hexacopter_P.Saturation_LowerSat)
  {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Saturation_LowerSat;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S176>/Constant'
  //   Product: '<S176>/Product'
  //   Saturate: '<S176>/Saturation'
  //   Sum: '<S176>/Sum'
  //   Sum: '<S176>/Sum1'

  FLIGHT_hexacopter_B.Add1 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[0]) -
    FLIGHT_hexacopter_P.Constant_Value_kf) * FLIGHT_hexacopter_B.Add1 +
    FLIGHT_hexacopter_P.Constant_Value_kf);
  if (rtIsNaN(FLIGHT_hexacopter_B.Add1) || rtIsInf(FLIGHT_hexacopter_B.Add1)) {
    FLIGHT_hexacopter_B.Add1 = 0.0;
  } else {
    FLIGHT_hexacopter_B.Add1 = fmod(FLIGHT_hexacopter_B.Add1, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7[0] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.Add1 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>
      (-static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_hexacopter_B.Add1))))
     : static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_hexacopter_B.Add1)));

  // Switch: '<S4>/Switch1' incorporates:
  //   Constant: '<S4>/Constant1'
  //   DataTypeConversion: '<S4>/Data Type Conversion2'
  //   MATLABSystem: '<S4>/Read Parameter1'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_B.ParamStep_k;
  } else {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Constant1_Value;
  }

  // Gain: '<S177>/Gain' incorporates:
  //   Switch: '<S4>/Switch1'

  FLIGHT_hexacopter_B.Add1 *= FLIGHT_hexacopter_P.Gain_Gain_h;

  // Saturate: '<S177>/Saturation'
  if (FLIGHT_hexacopter_B.Add1 > FLIGHT_hexacopter_P.Saturation_UpperSat_m) {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Saturation_UpperSat_m;
  } else if (FLIGHT_hexacopter_B.Add1 <
             FLIGHT_hexacopter_P.Saturation_LowerSat_o) {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Saturation_LowerSat_o;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S177>/Constant'
  //   Product: '<S177>/Product'
  //   Saturate: '<S177>/Saturation'
  //   Sum: '<S177>/Sum'
  //   Sum: '<S177>/Sum1'

  FLIGHT_hexacopter_B.Add1 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[1]) -
    FLIGHT_hexacopter_P.Constant_Value_ms) * FLIGHT_hexacopter_B.Add1 +
    FLIGHT_hexacopter_P.Constant_Value_ms);
  if (rtIsNaN(FLIGHT_hexacopter_B.Add1) || rtIsInf(FLIGHT_hexacopter_B.Add1)) {
    FLIGHT_hexacopter_B.Add1 = 0.0;
  } else {
    FLIGHT_hexacopter_B.Add1 = fmod(FLIGHT_hexacopter_B.Add1, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7[1] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.Add1 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>
      (-static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_hexacopter_B.Add1))))
     : static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_hexacopter_B.Add1)));

  // Switch: '<S4>/Switch2' incorporates:
  //   Constant: '<S4>/Constant2'
  //   DataTypeConversion: '<S4>/Data Type Conversion'
  //   MATLABSystem: '<S4>/Read Parameter2'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_B.ParamStep_cx;
  } else {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Constant2_Value;
  }

  // Gain: '<S178>/Gain' incorporates:
  //   Switch: '<S4>/Switch2'

  FLIGHT_hexacopter_B.Add1 *= FLIGHT_hexacopter_P.Gain_Gain_c;

  // Saturate: '<S178>/Saturation'
  if (FLIGHT_hexacopter_B.Add1 > FLIGHT_hexacopter_P.Saturation_UpperSat_b) {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Saturation_UpperSat_b;
  } else if (FLIGHT_hexacopter_B.Add1 <
             FLIGHT_hexacopter_P.Saturation_LowerSat_g) {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Saturation_LowerSat_g;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S178>/Constant'
  //   Product: '<S178>/Product'
  //   Saturate: '<S178>/Saturation'
  //   Sum: '<S178>/Sum'
  //   Sum: '<S178>/Sum1'

  FLIGHT_hexacopter_B.Add1 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[2]) -
    FLIGHT_hexacopter_P.Constant_Value_ii) * FLIGHT_hexacopter_B.Add1 +
    FLIGHT_hexacopter_P.Constant_Value_ii);
  if (rtIsNaN(FLIGHT_hexacopter_B.Add1) || rtIsInf(FLIGHT_hexacopter_B.Add1)) {
    FLIGHT_hexacopter_B.Add1 = 0.0;
  } else {
    FLIGHT_hexacopter_B.Add1 = fmod(FLIGHT_hexacopter_B.Add1, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7[2] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.Add1 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>
      (-static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_hexacopter_B.Add1))))
     : static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_hexacopter_B.Add1)));

  // Switch: '<S4>/Switch3' incorporates:
  //   Constant: '<S4>/Constant3'
  //   DataTypeConversion: '<S4>/Data Type Conversion4'
  //   MATLABSystem: '<S4>/Read Parameter3'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_B.ParamStep_b;
  } else {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Constant3_Value;
  }

  // Gain: '<S179>/Gain' incorporates:
  //   Switch: '<S4>/Switch3'

  FLIGHT_hexacopter_B.Add1 *= FLIGHT_hexacopter_P.Gain_Gain_n;

  // Saturate: '<S179>/Saturation'
  if (FLIGHT_hexacopter_B.Add1 > FLIGHT_hexacopter_P.Saturation_UpperSat_be) {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Saturation_UpperSat_be;
  } else if (FLIGHT_hexacopter_B.Add1 <
             FLIGHT_hexacopter_P.Saturation_LowerSat_e) {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Saturation_LowerSat_e;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S179>/Constant'
  //   Product: '<S179>/Product'
  //   Saturate: '<S179>/Saturation'
  //   Sum: '<S179>/Sum'
  //   Sum: '<S179>/Sum1'

  FLIGHT_hexacopter_B.Add1 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[3]) -
    FLIGHT_hexacopter_P.Constant_Value_j4x) * FLIGHT_hexacopter_B.Add1 +
    FLIGHT_hexacopter_P.Constant_Value_j4x);
  if (rtIsNaN(FLIGHT_hexacopter_B.Add1) || rtIsInf(FLIGHT_hexacopter_B.Add1)) {
    FLIGHT_hexacopter_B.Add1 = 0.0;
  } else {
    FLIGHT_hexacopter_B.Add1 = fmod(FLIGHT_hexacopter_B.Add1, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7[3] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.Add1 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>
      (-static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_hexacopter_B.Add1))))
     : static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_hexacopter_B.Add1)));

  // Switch: '<S4>/Switch4' incorporates:
  //   Constant: '<S4>/Constant4'
  //   DataTypeConversion: '<S4>/Data Type Conversion1'
  //   MATLABSystem: '<S4>/Read Parameter4'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_B.ParamStep_p;
  } else {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Constant4_Value;
  }

  // Gain: '<S180>/Gain' incorporates:
  //   Switch: '<S4>/Switch4'

  FLIGHT_hexacopter_B.Add1 *= FLIGHT_hexacopter_P.Gain_Gain_f;

  // Saturate: '<S180>/Saturation'
  if (FLIGHT_hexacopter_B.Add1 > FLIGHT_hexacopter_P.Saturation_UpperSat_d) {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Saturation_UpperSat_d;
  } else if (FLIGHT_hexacopter_B.Add1 <
             FLIGHT_hexacopter_P.Saturation_LowerSat_l) {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Saturation_LowerSat_l;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S180>/Constant'
  //   Product: '<S180>/Product'
  //   Saturate: '<S180>/Saturation'
  //   Sum: '<S180>/Sum'
  //   Sum: '<S180>/Sum1'

  FLIGHT_hexacopter_B.Add1 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[4]) -
    FLIGHT_hexacopter_P.Constant_Value_l) * FLIGHT_hexacopter_B.Add1 +
    FLIGHT_hexacopter_P.Constant_Value_l);
  if (rtIsNaN(FLIGHT_hexacopter_B.Add1) || rtIsInf(FLIGHT_hexacopter_B.Add1)) {
    FLIGHT_hexacopter_B.Add1 = 0.0;
  } else {
    FLIGHT_hexacopter_B.Add1 = fmod(FLIGHT_hexacopter_B.Add1, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7[4] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.Add1 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>
      (-static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_hexacopter_B.Add1))))
     : static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_hexacopter_B.Add1)));

  // Switch: '<S4>/Switch5' incorporates:
  //   Constant: '<S4>/Constant5'
  //   DataTypeConversion: '<S4>/Data Type Conversion5'
  //   MATLABSystem: '<S4>/Read Parameter5'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_B.ParamStep_cv;
  } else {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Constant5_Value;
  }

  // Gain: '<S181>/Gain' incorporates:
  //   Switch: '<S4>/Switch5'

  FLIGHT_hexacopter_B.Add1 *= FLIGHT_hexacopter_P.Gain_Gain_m;

  // Saturate: '<S181>/Saturation'
  if (FLIGHT_hexacopter_B.Add1 > FLIGHT_hexacopter_P.Saturation_UpperSat_i) {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Saturation_UpperSat_i;
  } else if (FLIGHT_hexacopter_B.Add1 <
             FLIGHT_hexacopter_P.Saturation_LowerSat_n) {
    FLIGHT_hexacopter_B.Add1 = FLIGHT_hexacopter_P.Saturation_LowerSat_n;
  }

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Constant: '<S181>/Constant'
  //   Product: '<S181>/Product'
  //   Saturate: '<S181>/Saturation'
  //   Sum: '<S181>/Sum'
  //   Sum: '<S181>/Sum1'

  FLIGHT_hexacopter_B.Add1 = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[5]) -
    FLIGHT_hexacopter_P.Constant_Value_o) * FLIGHT_hexacopter_B.Add1 +
    FLIGHT_hexacopter_P.Constant_Value_o);
  if (rtIsNaN(FLIGHT_hexacopter_B.Add1) || rtIsInf(FLIGHT_hexacopter_B.Add1)) {
    FLIGHT_hexacopter_B.Add1 = 0.0;
  } else {
    FLIGHT_hexacopter_B.Add1 = fmod(FLIGHT_hexacopter_B.Add1, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7[5] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.Add1 < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>
      (-static_cast<int16_T>(static_cast<uint16_T>(-FLIGHT_hexacopter_B.Add1))))
     : static_cast<int32_T>(static_cast<uint16_T>(FLIGHT_hexacopter_B.Add1)));

  // RelationalOperator: '<S72>/Compare' incorporates:
  //   Constant: '<S72>/Constant'
  //   SignalConversion generated from: '<S404>/Bus Selector'

  rtb_AND3_i = (FLIGHT_hexacopter_B.In1_n.values[4] >=
                FLIGHT_hexacopter_P.CompareToConstant3_const);

  // MATLABSystem: '<Root>/PX4 PWM Output' incorporates:
  //   Logic: '<Root>/NOT'

  for (i = 0; i < 8; i++) {
    FLIGHT_hexacopter_B.pwmValue[i] = 0U;
  }

  FLIGHT_hexacopter_B.pwmValue[0] = FLIGHT_hexacopter_B.DataTypeConversion7[0];
  FLIGHT_hexacopter_B.pwmValue[1] = FLIGHT_hexacopter_B.DataTypeConversion7[1];
  FLIGHT_hexacopter_B.pwmValue[2] = FLIGHT_hexacopter_B.DataTypeConversion7[2];
  FLIGHT_hexacopter_B.pwmValue[3] = FLIGHT_hexacopter_B.DataTypeConversion7[3];
  FLIGHT_hexacopter_B.pwmValue[4] = FLIGHT_hexacopter_B.DataTypeConversion7[4];
  FLIGHT_hexacopter_B.pwmValue[5] = FLIGHT_hexacopter_B.DataTypeConversion7[5];
  if (rtb_AND3_i) {
    if (!FLIGHT_hexacopter_DW.obj_dl.isArmed) {
      FLIGHT_hexacopter_DW.obj_dl.isArmed = true;
      pwm_arm(&FLIGHT_hexacopter_DW.obj_dl.armAdvertiseObj);
    }

    pwm_setServo(FLIGHT_hexacopter_DW.obj_dl.servoCount,
                 FLIGHT_hexacopter_DW.obj_dl.channelMask,
                 &FLIGHT_hexacopter_B.pwmValue[0],
                 FLIGHT_hexacopter_DW.obj_dl.isMain,
                 &FLIGHT_hexacopter_DW.obj_dl.actuatorAdvertiseObj);
  } else {
    pwm_disarm(&FLIGHT_hexacopter_DW.obj_dl.armAdvertiseObj);
    FLIGHT_hexacopter_DW.obj_dl.isArmed = false;
    pwm_resetServo(FLIGHT_hexacopter_DW.obj_dl.servoCount,
                   FLIGHT_hexacopter_DW.obj_dl.isMain,
                   &FLIGHT_hexacopter_DW.obj_dl.actuatorAdvertiseObj);
  }

  if (FLIGHT_hexacopter_DW.obj_dl.isMain) {
    if (!rtb_AND3_i) {
      pwm_disarm(&FLIGHT_hexacopter_DW.obj_dl.armAdvertiseObj);
    } else {
      pwm_arm(&FLIGHT_hexacopter_DW.obj_dl.armAdvertiseObj);
    }
  }

  // End of MATLABSystem: '<Root>/PX4 PWM Output'

  // Gain: '<S566>/1//2' incorporates:
  //   Constant: '<Root>/Constant'

  rtb_ypr_idx_0 = FLIGHT_hexacopter_P.u2_Gain *
    FLIGHT_hexacopter_P.Constant_Value_a;
  rtb_ypr_idx_1 = FLIGHT_hexacopter_P.u2_Gain * FLIGHT_hexacopter_B.Merge1[1];
  FLIGHT_hexacopter_B.ParamStep_c = FLIGHT_hexacopter_P.u2_Gain *
    FLIGHT_hexacopter_B.Merge1[0];

  // Trigonometry: '<S566>/sincos'
  rtb_sincos_o2_idx_0 = static_cast<real32_T>(cos(static_cast<real_T>
    (rtb_ypr_idx_0)));
  rtb_ypr_idx_0 = static_cast<real32_T>(sin(static_cast<real_T>(rtb_ypr_idx_0)));
  rtb_sincos_o2_idx_1 = static_cast<real32_T>(cos(static_cast<real_T>
    (rtb_ypr_idx_1)));
  rtb_ypr_idx_1 = static_cast<real32_T>(sin(static_cast<real_T>(rtb_ypr_idx_1)));
  rtb_sincos_o2_idx_2 = static_cast<real32_T>(cos(static_cast<real_T>
    (FLIGHT_hexacopter_B.ParamStep_c)));
  rtb_ypr_0 = static_cast<real32_T>(sin(static_cast<real_T>
    (FLIGHT_hexacopter_B.ParamStep_c)));
  FLIGHT_hexacopter_PX4Timestamp(&FLIGHT_hexacopter_B.PX4Timestamp_p);

  // BusAssignment: '<S13>/Bus Assignment' incorporates:
  //   Constant: '<S564>/Constant'

  FLIGHT_hexacopter_B.BusAssignment_d = FLIGHT_hexacopter_P.Constant_Value_j;

  // BusAssignment: '<S13>/Bus Assignment' incorporates:
  //   Constant: '<S13>/Constant'
  //   MATLABSystem: '<S13>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment_d.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_p.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment_d.roll_body = FLIGHT_hexacopter_B.Merge1[0];
  FLIGHT_hexacopter_B.BusAssignment_d.pitch_body = FLIGHT_hexacopter_B.Merge1[1];
  FLIGHT_hexacopter_B.BusAssignment_d.yaw_sp_move_rate =
    FLIGHT_hexacopter_B.Merge1[2];
  FLIGHT_hexacopter_B.BusAssignment_d.thrust_body[0] =
    FLIGHT_hexacopter_P.Constant_Value_gq;
  FLIGHT_hexacopter_B.BusAssignment_d.thrust_body[1] =
    FLIGHT_hexacopter_P.Constant_Value_gq;
  FLIGHT_hexacopter_B.BusAssignment_d.thrust_body[2] =
    FLIGHT_hexacopter_B.Merge1[3];

  // Fcn: '<S566>/q0' incorporates:
  //   Fcn: '<S566>/q1'
  //   Trigonometry: '<S566>/sincos'

  FLIGHT_hexacopter_B.ParamStep_c = rtb_sincos_o2_idx_0 * rtb_sincos_o2_idx_1;
  tmp_3 = rtb_ypr_idx_0 * rtb_ypr_idx_1;

  // BusAssignment: '<S13>/Bus Assignment' incorporates:
  //   Fcn: '<S566>/q0'
  //   Fcn: '<S566>/q1'
  //   Trigonometry: '<S566>/sincos'

  FLIGHT_hexacopter_B.BusAssignment_d.q_d[0] = FLIGHT_hexacopter_B.ParamStep_c *
    rtb_sincos_o2_idx_2 + tmp_3 * rtb_ypr_0;
  FLIGHT_hexacopter_B.BusAssignment_d.q_d[1] = FLIGHT_hexacopter_B.ParamStep_c *
    rtb_ypr_0 - tmp_3 * rtb_sincos_o2_idx_2;

  // Fcn: '<S566>/q2' incorporates:
  //   Fcn: '<S566>/q3'
  //   Trigonometry: '<S566>/sincos'

  FLIGHT_hexacopter_B.ParamStep_c = rtb_ypr_idx_0 * rtb_sincos_o2_idx_1;
  tmp_3 = rtb_sincos_o2_idx_0 * rtb_ypr_idx_1;

  // BusAssignment: '<S13>/Bus Assignment' incorporates:
  //   Fcn: '<S566>/q2'
  //   Fcn: '<S566>/q3'
  //   Trigonometry: '<S566>/sincos'

  FLIGHT_hexacopter_B.BusAssignment_d.q_d[2] = tmp_3 * rtb_sincos_o2_idx_2 +
    FLIGHT_hexacopter_B.ParamStep_c * rtb_ypr_0;
  FLIGHT_hexacopter_B.BusAssignment_d.q_d[3] = FLIGHT_hexacopter_B.ParamStep_c *
    rtb_sincos_o2_idx_2 - tmp_3 * rtb_ypr_0;

  // MATLABSystem: '<S565>/SinkBlock' incorporates:
  //   BusAssignment: '<S13>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_pt.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_pt.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_d);
  FLIGHT_hexacopter_PX4Timestamp(&FLIGHT_hexacopter_B.PX4Timestamp);

  // BusAssignment: '<S12>/Bus Assignment' incorporates:
  //   Constant: '<S562>/Constant'

  FLIGHT_hexacopter_B.BusAssignment = FLIGHT_hexacopter_P.Constant_Value_b;

  // BusAssignment: '<S12>/Bus Assignment' incorporates:
  //   Constant: '<S12>/Constant'
  //   Constant: '<S12>/Constant2'
  //   DataTypeConversion: '<Root>/Data Type Conversion'
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   MATLABSystem: '<S12>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment.noutputs =
    FLIGHT_hexacopter_P.Constant2_Value_l;
  for (i = 0; i < 6; i++) {
    FLIGHT_hexacopter_B.BusAssignment.output[i] =
      FLIGHT_hexacopter_B.Output_Limits1[i];
    FLIGHT_hexacopter_B.BusAssignment.output[i + 6] =
      FLIGHT_hexacopter_B.DataTypeConversion7[i];
  }

  FLIGHT_hexacopter_B.BusAssignment.output[12] =
    FLIGHT_hexacopter_P.Constant_Value_ov;
  FLIGHT_hexacopter_B.BusAssignment.output[13] =
    FLIGHT_hexacopter_P.Constant_Value_ov;
  FLIGHT_hexacopter_B.BusAssignment.output[14] =
    FLIGHT_hexacopter_P.Constant_Value_ov;
  FLIGHT_hexacopter_B.BusAssignment.output[15] =
    FLIGHT_hexacopter_P.Constant_Value_ov;

  // MATLABSystem: '<S563>/SinkBlock' incorporates:
  //   BusAssignment: '<S12>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_jj.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_jj.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment);

  // BusAssignment: '<S16>/Bus Assignment' incorporates:
  //   Constant: '<S571>/Constant'

  FLIGHT_hexacopter_B.BusAssignment_n = FLIGHT_hexacopter_P.Constant_Value_n1;

  // BusAssignment: '<S16>/Bus Assignment'
  FLIGHT_hexacopter_B.BusAssignment_n.xyz[0] = FLIGHT_hexacopter_B.Sum_c;
  FLIGHT_hexacopter_B.BusAssignment_n.xyz[1] = rtb_Sum_e;
  FLIGHT_hexacopter_B.BusAssignment_n.xyz[2] = FLIGHT_hexacopter_B.ParamStep;

  // MATLABSystem: '<S572>/SinkBlock' incorporates:
  //   BusAssignment: '<S16>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_my.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_my.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_n);

  // MATLABSystem: '<S9>/Read Parameter7'
  if (FLIGHT_hexacopter_DW.obj_j.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj_j.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_j.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep_c);
  if (rtb_AND3_i) {
    FLIGHT_hexacopter_B.ParamStep_c = 0.0F;
  }

  // MATLABSystem: '<S9>/Read Parameter4'
  if (FLIGHT_hexacopter_DW.obj_p.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj_p.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_p.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.ParamStep);
  if (rtb_AND3_i) {
    FLIGHT_hexacopter_B.ParamStep = 0.0F;
  }

  FLIGHT_hexacopter_PX4Timestamp(&FLIGHT_hexacopter_B.PX4Timestamp_pna);

  // BusAssignment: '<S15>/Bus Assignment' incorporates:
  //   Constant: '<S569>/Constant'

  FLIGHT_hexacopter_B.BusAssignment_e = FLIGHT_hexacopter_P.Constant_Value_i;

  // BusAssignment: '<S15>/Bus Assignment' incorporates:
  //   Constant: '<S15>/Constant'
  //   MATLABSystem: '<S15>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment_e.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_pna.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment_e.roll = FLIGHT_hexacopter_B.PProdOut_i;
  FLIGHT_hexacopter_B.BusAssignment_e.pitch = FLIGHT_hexacopter_B.PProdOut_h;
  FLIGHT_hexacopter_B.BusAssignment_e.yaw = FLIGHT_hexacopter_B.Merge1[2];
  FLIGHT_hexacopter_B.BusAssignment_e.thrust_body[0] =
    FLIGHT_hexacopter_P.Constant_Value_ll;
  FLIGHT_hexacopter_B.BusAssignment_e.thrust_body[1] =
    FLIGHT_hexacopter_P.Constant_Value_ll;
  FLIGHT_hexacopter_B.BusAssignment_e.thrust_body[2] =
    FLIGHT_hexacopter_B.Merge1[3];

  // MATLABSystem: '<S570>/SinkBlock' incorporates:
  //   BusAssignment: '<S15>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_a4.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_a4.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_e);

  // MATLABSystem: '<S9>/Read Parameter1'
  if (FLIGHT_hexacopter_DW.obj_e.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    FLIGHT_hexacopter_DW.obj_e.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  rtb_AND3_i = MW_Param_Step(FLIGHT_hexacopter_DW.obj_e.MW_PARAMHANDLE,
    MW_SINGLE, &FLIGHT_hexacopter_B.PProdOut_i);
  if (rtb_AND3_i) {
    FLIGHT_hexacopter_B.PProdOut_i = 0.0F;
  }

  // MATLABSystem: '<S14>/PX4 Timestamp'
  FLIGHT_hexacopter_B.rtb_PX4Timestamp_m = hrt_absolute_time();

  // BusAssignment: '<S14>/Bus Assignment' incorporates:
  //   Constant: '<S567>/Constant'

  FLIGHT_hexacopter_B.BusAssignment_g = FLIGHT_hexacopter_P.Constant_Value_n;

  // BusAssignment: '<S14>/Bus Assignment' incorporates:
  //   MATLABSystem: '<S14>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment_g.timestamp =
    FLIGHT_hexacopter_B.rtb_PX4Timestamp_m;
  FLIGHT_hexacopter_B.BusAssignment_g.vx = FLIGHT_hexacopter_B.Saturation[0];
  FLIGHT_hexacopter_B.BusAssignment_g.vy = FLIGHT_hexacopter_B.Saturation[1];
  FLIGHT_hexacopter_B.BusAssignment_g.vz = FLIGHT_hexacopter_B.Merge;
  FLIGHT_hexacopter_B.BusAssignment_g.x =
    FLIGHT_hexacopter_B.OutportBufferFordes_xy[0];
  FLIGHT_hexacopter_B.BusAssignment_g.y =
    FLIGHT_hexacopter_B.OutportBufferFordes_xy[1];
  FLIGHT_hexacopter_B.BusAssignment_g.z = FLIGHT_hexacopter_B.Add;

  // MATLABSystem: '<S568>/SinkBlock' incorporates:
  //   BusAssignment: '<S14>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_pa.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_pa.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_g);

  // Update for DiscreteIntegrator: '<S493>/Integrator' incorporates:
  //   MATLABSystem: '<S9>/Read Parameter1'
  //   Product: '<S490>/IProd Out'
  //
  FLIGHT_hexacopter_DW.Integrator_DSTATE += FLIGHT_hexacopter_B.Saturation3 *
    FLIGHT_hexacopter_B.PProdOut_i * FLIGHT_hexacopter_P.Integrator_gainval_i;

  // Update for DiscreteIntegrator: '<S488>/Filter'
  FLIGHT_hexacopter_DW.Filter_DSTATE += FLIGHT_hexacopter_P.Filter_gainval_o *
    FLIGHT_hexacopter_B.Filter_a;

  // Update for DiscreteIntegrator: '<S443>/Integrator' incorporates:
  //   MATLABSystem: '<S9>/Read Parameter4'
  //   Product: '<S440>/IProd Out'
  //
  FLIGHT_hexacopter_DW.Integrator_DSTATE_c += FLIGHT_hexacopter_B.Integrator_m *
    FLIGHT_hexacopter_B.ParamStep * FLIGHT_hexacopter_P.Integrator_gainval_im;

  // Update for DiscreteIntegrator: '<S438>/Filter'
  FLIGHT_hexacopter_DW.Filter_DSTATE_j += FLIGHT_hexacopter_P.Filter_gainval_f *
    FLIGHT_hexacopter_B.DeadZone;

  // Update for DiscreteIntegrator: '<S543>/Integrator' incorporates:
  //   MATLABSystem: '<S9>/Read Parameter7'
  //   Product: '<S540>/IProd Out'
  //
  FLIGHT_hexacopter_DW.Integrator_DSTATE_l += rtb_Sum4 *
    FLIGHT_hexacopter_B.ParamStep_c * FLIGHT_hexacopter_P.Integrator_gainval_e;

  // Update for DiscreteIntegrator: '<S538>/Filter'
  FLIGHT_hexacopter_DW.Filter_DSTATE_h += FLIGHT_hexacopter_P.Filter_gainval_m *
    rtb_NProdOut_ef;
}

// Model initialize function
void FLIGHT_hexacopter_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const char_T ParameterNameStr[10] = "MC_ROLL_P";
    static const char_T ParameterNameStr_0[14] = "MC_ROLLRATE_P";
    static const char_T ParameterNameStr_1[14] = "MC_ROLLRATE_D";
    static const char_T ParameterNameStr_2[11] = "MC_PITCH_P";
    static const char_T ParameterNameStr_3[15] = "MC_PITCHRATE_P";
    static const char_T ParameterNameStr_4[15] = "MC_PITCHRATE_D";
    static const char_T ParameterNameStr_5[13] = "MC_YAWRATE_P";
    static const char_T ParameterNameStr_6[13] = "MC_YAWRATE_D";
    static const char_T ParameterNameStr_7[14] = "FDD_M1_STATUS";
    static const char_T ParameterNameStr_8[14] = "FDD_M2_STATUS";
    static const char_T ParameterNameStr_9[14] = "FDD_M3_STATUS";
    static const char_T ParameterNameStr_a[14] = "FDD_M4_STATUS";
    static const char_T ParameterNameStr_b[14] = "FDD_M5_STATUS";
    static const char_T ParameterNameStr_c[14] = "FDD_M6_STATUS";
    static const char_T ParameterNameStr_d[13] = "MC_YAWRATE_I";
    static const char_T ParameterNameStr_e[15] = "MC_PITCHRATE_I";
    static const char_T ParameterNameStr_f[14] = "MC_ROLLRATE_I";
    static const char_T ParameterNameStr_g[9] = "MPC_XY_P";
    static const char_T ParameterNameStr_h[17] = "MPC_XY_VEL_P_ACC";
    static const char_T ParameterNameStr_i[8] = "MPC_Z_P";
    real_T tmp;

    // InitializeConditions for DiscreteIntegrator: '<S493>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE =
      FLIGHT_hexacopter_P.PIDController2_InitialConditi_c;

    // InitializeConditions for DiscreteIntegrator: '<S488>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE =
      FLIGHT_hexacopter_P.PIDController2_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S443>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_c =
      FLIGHT_hexacopter_P.PIDController1_InitialConditi_c;

    // InitializeConditions for DiscreteIntegrator: '<S438>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_j =
      FLIGHT_hexacopter_P.PIDController1_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S543>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_l =
      FLIGHT_hexacopter_P.PIDController6_InitialConditi_h;

    // InitializeConditions for DiscreteIntegrator: '<S538>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_h =
      FLIGHT_hexacopter_P.PIDController6_InitialCondition;

    // SystemInitialize for Enabled SubSystem: '<S405>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S406>/In1' incorporates:
    //   Outport: '<S406>/Out1'

    FLIGHT_hexacopter_B.In1_n = FLIGHT_hexacopter_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S405>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S397>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S401>/In1' incorporates:
    //   Outport: '<S401>/Out1'

    FLIGHT_hexacopter_B.In1 = FLIGHT_hexacopter_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S397>/Enabled Subsystem'

    // SystemInitialize for IfAction SubSystem: '<Root>/If Action Subsystem'
    // InitializeConditions for DiscreteIntegrator: '<S274>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_k =
      FLIGHT_hexacopter_P.PIDController4_InitialConditi_i;
    FLIGHT_hexacopter_DW.Integrator_PrevResetState = 2;

    // InitializeConditions for DiscreteIntegrator: '<S269>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_g =
      FLIGHT_hexacopter_P.PIDController4_InitialConditi_l;
    FLIGHT_hexacopter_DW.Filter_PrevResetState = 2;

    // SystemInitialize for SignalConversion generated from: '<S5>/des_xy' incorporates:
    //   Constant: '<S5>/Constant'

    FLIGHT_hexacopter_B.OutportBufferFordes_xy[0] =
      FLIGHT_hexacopter_P.Constant_Value_kn[0];
    FLIGHT_hexacopter_B.OutportBufferFordes_xy[1] =
      FLIGHT_hexacopter_P.Constant_Value_kn[1];

    // Start for MATLABSystem: '<S185>/Read Parameter'
    FLIGHT_hexacopter_DW.obj_eq.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_eq.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_eq.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_eq.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_eq.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_eq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_g[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_eq.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S185>/Read Parameter'

    // Start for MATLABSystem: '<S186>/Read Parameter'
    FLIGHT_hexacopter_DW.obj_pi.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_pi.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_pi.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_pi.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_pi.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_pi.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_h[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_pi.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S186>/Read Parameter'

    // Start for MATLABSystem: '<S182>/Read Parameter1'
    FLIGHT_hexacopter_DW.obj_m.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_m.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_m.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_m.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_m.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_m.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_i[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S182>/Read Parameter1'
    FLIGHT_hexa_ReadParameter1_Init(&FLIGHT_hexacopter_DW.ReadParameter1_pnaev);
    FLIGHT_hexa_ReadParameter3_Init(&FLIGHT_hexacopter_DW.ReadParameter3_pna);
    FLIGHT_hexac_ReadParameter_Init(&FLIGHT_hexacopter_DW.ReadParameter_pna);
    FLIGHT_hexa_ReadParameter2_Init(&FLIGHT_hexacopter_DW.ReadParameter2_pna);

    // SystemInitialize for Sum: '<S5>/Add' incorporates:
    //   Outport: '<S5>/des_z'

    FLIGHT_hexacopter_B.Add = FLIGHT_hexacopter_P.des_z_Y0;

    // SystemInitialize for Saturate: '<S5>/Saturation' incorporates:
    //   Outport: '<S5>/des_vxvy'

    FLIGHT_hexacopter_B.Saturation[0] = FLIGHT_hexacopter_P.des_vxvy_Y0;
    FLIGHT_hexacopter_B.Saturation[1] = FLIGHT_hexacopter_P.des_vxvy_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem'

    // SystemInitialize for IfAction SubSystem: '<Root>/Altitude_Mode'
    // InitializeConditions for DiscreteIntegrator: '<S55>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_e =
      FLIGHT_hexacopter_P.PIDController4_InitialConditi_a;

    // InitializeConditions for DiscreteIntegrator: '<S50>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_i =
      FLIGHT_hexacopter_P.PIDController4_InitialCondition;
    FLIGHT_hexa_ReadParameter2_Init(&FLIGHT_hexacopter_DW.ReadParameter2_pn);
    FLIGHT_hexa_ReadParameter1_Init(&FLIGHT_hexacopter_DW.ReadParameter1_pna);
    FLIGHT_hexa_ReadParameter3_Init(&FLIGHT_hexacopter_DW.ReadParameter3_pn);
    FLIGHT_hexac_ReadParameter_Init(&FLIGHT_hexacopter_DW.ReadParameter_pn);

    // End of SystemInitialize for SubSystem: '<Root>/Altitude_Mode'

    // SystemInitialize for IfAction SubSystem: '<Root>/Stabilized_Mode'
    // SystemInitialize for Enabled SubSystem: '<S10>/Enabled Subsystem'
    // SystemInitialize for DataTypeConversion: '<S561>/Data Type Conversion' incorporates:
    //   Outport: '<S561>/doublet'

    FLIGHT_hexacopter_B.DataTypeConversion = FLIGHT_hexacopter_P.doublet_Y0;

    // End of SystemInitialize for SubSystem: '<S10>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Stabilized_Mode'

    // SystemInitialize for Merge: '<Root>/Merge1'
    FLIGHT_hexacopter_B.Merge1[0] = FLIGHT_hexacopter_P.Merge1_InitialOutput;
    FLIGHT_hexacopter_B.Merge1[1] = FLIGHT_hexacopter_P.Merge1_InitialOutput;
    FLIGHT_hexacopter_B.Merge1[2] = FLIGHT_hexacopter_P.Merge1_InitialOutput;
    FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_P.Merge1_InitialOutput;

    // SystemInitialize for Enabled SubSystem: '<S402>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S403>/In1' incorporates:
    //   Outport: '<S403>/Out1'

    FLIGHT_hexacopter_B.In1_k = FLIGHT_hexacopter_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S402>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S399>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S400>/In1' incorporates:
    //   Outport: '<S400>/Out1'

    FLIGHT_hexacopter_B.In1_e = FLIGHT_hexacopter_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S399>/Enabled Subsystem'

    // SystemInitialize for Saturate: '<S228>/Saturation' incorporates:
    //   Merge: '<Root>/Merge'

    FLIGHT_hexacopter_B.Merge = FLIGHT_hexacopter_P.Merge_InitialOutput;

    // Start for MATLABSystem: '<S405>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_p2.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_p2.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_p2.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_p2.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_p2.eventStructObj);
    FLIGHT_hexacopter_DW.obj_p2.isSetupComplete = true;

    // Start for MATLABSystem: '<S397>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_k.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_k.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_k.orbMetadataObj = ORB_ID(vehicle_local_position);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_k.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_k.eventStructObj);
    FLIGHT_hexacopter_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<S402>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_ab.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_ab.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_ab.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_ab.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_ab.eventStructObj);
    FLIGHT_hexacopter_DW.obj_ab.isSetupComplete = true;

    // Start for MATLABSystem: '<S3>/Read Parameter'
    FLIGHT_hexacopter_DW.obj_jz.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_jz.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_jz.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_jz.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_jz.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_jz.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_jz.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/Read Parameter'

    // Start for MATLABSystem: '<S399>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_l.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_l.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_l.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_l.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_l.eventStructObj);
    FLIGHT_hexacopter_DW.obj_l.isSetupComplete = true;

    // Start for MATLABSystem: '<S9>/Read Parameter'
    FLIGHT_hexacopter_DW.obj_i.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_i.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_i.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_i.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_i.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_i.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_i.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter'

    // Start for MATLABSystem: '<S9>/Read Parameter2'
    FLIGHT_hexacopter_DW.obj_d.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_d.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_d.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_d.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_d.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter2'

    // Start for MATLABSystem: '<S3>/Read Parameter1'
    FLIGHT_hexacopter_DW.obj_o.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_o.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_o.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_o.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_o.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_o.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/Read Parameter1'

    // Start for MATLABSystem: '<S9>/Read Parameter3'
    FLIGHT_hexacopter_DW.obj_b.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_b.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_b.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_b.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_b.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter3'

    // Start for MATLABSystem: '<S9>/Read Parameter5'
    FLIGHT_hexacopter_DW.obj_h.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_h.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_h.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_h.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_h.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_h.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter5'

    // Start for MATLABSystem: '<S9>/Read Parameter6'
    FLIGHT_hexacopter_DW.obj_a.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_a.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_a.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_a.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_a.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter6'

    // Start for MATLABSystem: '<S9>/Read Parameter8'
    FLIGHT_hexacopter_DW.obj.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_6
      [0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter8'

    // Start for MATLABSystem: '<S4>/Read Parameter13'
    FLIGHT_hexacopter_DW.obj_g.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_g.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter13_SampleTime;
    FLIGHT_hexacopter_DW.obj_g.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_g.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_g.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_7[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter13'

    // Start for MATLABSystem: '<S4>/Read Parameter1'
    FLIGHT_hexacopter_DW.obj_j5.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_j5.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter1_SampleTime;
    FLIGHT_hexacopter_DW.obj_j5.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_j5.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_j5.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_j5.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_8[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_j5.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter1'

    // Start for MATLABSystem: '<S4>/Read Parameter2'
    FLIGHT_hexacopter_DW.obj_ao.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_ao.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter2_SampleTime;
    FLIGHT_hexacopter_DW.obj_ao.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_ao.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_ao.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_ao.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_9[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_ao.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter2'

    // Start for MATLABSystem: '<S4>/Read Parameter3'
    FLIGHT_hexacopter_DW.obj_n.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_n.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter3_SampleTime;
    FLIGHT_hexacopter_DW.obj_n.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_n.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_n.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_n.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_a[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter3'

    // Start for MATLABSystem: '<S4>/Read Parameter4'
    FLIGHT_hexacopter_DW.obj_c.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_c.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter4_SampleTime;
    FLIGHT_hexacopter_DW.obj_c.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_c.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_c.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_c.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_b[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter4'

    // Start for MATLABSystem: '<S4>/Read Parameter5'
    FLIGHT_hexacopter_DW.obj_aq.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_aq.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter5_SampleTime;
    FLIGHT_hexacopter_DW.obj_aq.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_aq.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_aq.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_aq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_c[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_aq.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter5'

    // Start for MATLABSystem: '<Root>/PX4 PWM Output'
    FLIGHT_hexacopter_DW.obj_dl.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_dl.isSetupComplete = false;
    FLIGHT_hexacopter_DW.obj_dl.isInitialized = 1;
    FLIGHT_hexacopter_PWM_setupImpl(&FLIGHT_hexacopter_DW.obj_dl, false, false);
    FLIGHT_hexacopter_DW.obj_dl.isSetupComplete = true;
    FLIGHT_hexaco_PX4Timestamp_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_p);

    // Start for MATLABSystem: '<S565>/SinkBlock' incorporates:
    //   BusAssignment: '<S13>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_pt.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_pt.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_pt.orbMetadataObj = ORB_ID
      (vehicle_attitude_setpoint);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_pt.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_pt.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_d, 1);
    FLIGHT_hexacopter_DW.obj_pt.isSetupComplete = true;
    FLIGHT_hexaco_PX4Timestamp_Init(&FLIGHT_hexacopter_DW.PX4Timestamp);

    // Start for MATLABSystem: '<S563>/SinkBlock' incorporates:
    //   BusAssignment: '<S12>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_jj.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_jj.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_jj.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_jj.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_jj.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment, 1);
    FLIGHT_hexacopter_DW.obj_jj.isSetupComplete = true;

    // Start for MATLABSystem: '<S572>/SinkBlock' incorporates:
    //   BusAssignment: '<S16>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_my.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_my.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_my.orbMetadataObj = ORB_ID(vehicle_torque_setpoint);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_my.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_my.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_n, 1);
    FLIGHT_hexacopter_DW.obj_my.isSetupComplete = true;

    // Start for MATLABSystem: '<S9>/Read Parameter7'
    FLIGHT_hexacopter_DW.obj_j.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_j.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_j.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_j.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_j.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_j.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_d[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter7'

    // Start for MATLABSystem: '<S9>/Read Parameter4'
    FLIGHT_hexacopter_DW.obj_p.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_p.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_p.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_p.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_p.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_e[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter4'
    FLIGHT_hexaco_PX4Timestamp_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_pna);

    // Start for MATLABSystem: '<S570>/SinkBlock' incorporates:
    //   BusAssignment: '<S15>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_a4.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_a4.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_a4.orbMetadataObj = ORB_ID(vehicle_rates_setpoint);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_a4.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_a4.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_e, 1);
    FLIGHT_hexacopter_DW.obj_a4.isSetupComplete = true;

    // Start for MATLABSystem: '<S9>/Read Parameter1'
    FLIGHT_hexacopter_DW.obj_e.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_e.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_e.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_e.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_e.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_e.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_f[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/Read Parameter1'

    // Start for MATLABSystem: '<S14>/PX4 Timestamp'
    FLIGHT_hexacopter_DW.obj_ky.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_ky.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_ky.isSetupComplete = true;

    // Start for MATLABSystem: '<S568>/SinkBlock' incorporates:
    //   BusAssignment: '<S14>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_pa.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_pa.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_pa.orbMetadataObj = ORB_ID
      (vehicle_local_position_setpoint);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_pa.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_pa.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_g, 1);
    FLIGHT_hexacopter_DW.obj_pa.isSetupComplete = true;
  }
}

// Model terminate function
void FLIGHT_hexacopter_terminate(void)
{
  // Terminate for MATLABSystem: '<S405>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_p2.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_p2.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_p2.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_p2.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_p2.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S405>/SourceBlock'

  // Terminate for MATLABSystem: '<S397>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_k.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_k.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_k.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_k.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S397>/SourceBlock'

  // Terminate for IfAction SubSystem: '<Root>/If Action Subsystem'
  // Terminate for MATLABSystem: '<S185>/Read Parameter'
  if (!FLIGHT_hexacopter_DW.obj_eq.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_eq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S185>/Read Parameter'

  // Terminate for MATLABSystem: '<S186>/Read Parameter'
  if (!FLIGHT_hexacopter_DW.obj_pi.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_pi.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S186>/Read Parameter'

  // Terminate for MATLABSystem: '<S182>/Read Parameter1'
  if (!FLIGHT_hexacopter_DW.obj_m.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S182>/Read Parameter1'
  FLIGHT_hexa_ReadParameter1_Term(&FLIGHT_hexacopter_DW.ReadParameter1_pnaev);
  FLIGHT_hexa_ReadParameter3_Term(&FLIGHT_hexacopter_DW.ReadParameter3_pna);
  FLIGHT_hexac_ReadParameter_Term(&FLIGHT_hexacopter_DW.ReadParameter_pna);
  FLIGHT_hexa_ReadParameter2_Term(&FLIGHT_hexacopter_DW.ReadParameter2_pna);

  // End of Terminate for SubSystem: '<Root>/If Action Subsystem'

  // Terminate for IfAction SubSystem: '<Root>/Altitude_Mode'
  FLIGHT_hexa_ReadParameter2_Term(&FLIGHT_hexacopter_DW.ReadParameter2_pn);
  FLIGHT_hexa_ReadParameter1_Term(&FLIGHT_hexacopter_DW.ReadParameter1_pna);
  FLIGHT_hexa_ReadParameter3_Term(&FLIGHT_hexacopter_DW.ReadParameter3_pn);
  FLIGHT_hexac_ReadParameter_Term(&FLIGHT_hexacopter_DW.ReadParameter_pn);

  // End of Terminate for SubSystem: '<Root>/Altitude_Mode'

  // Terminate for MATLABSystem: '<S402>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_ab.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_ab.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_ab.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_ab.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_ab.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S402>/SourceBlock'

  // Terminate for MATLABSystem: '<S3>/Read Parameter'
  if (!FLIGHT_hexacopter_DW.obj_jz.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_jz.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Read Parameter'

  // Terminate for MATLABSystem: '<S399>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_l.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_l.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S399>/SourceBlock'

  // Terminate for MATLABSystem: '<S9>/Read Parameter'
  if (!FLIGHT_hexacopter_DW.obj_i.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter'

  // Terminate for MATLABSystem: '<S9>/Read Parameter2'
  if (!FLIGHT_hexacopter_DW.obj_d.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter2'

  // Terminate for MATLABSystem: '<S3>/Read Parameter1'
  if (!FLIGHT_hexacopter_DW.obj_o.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Read Parameter1'

  // Terminate for MATLABSystem: '<S9>/Read Parameter3'
  if (!FLIGHT_hexacopter_DW.obj_b.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter3'

  // Terminate for MATLABSystem: '<S9>/Read Parameter5'
  if (!FLIGHT_hexacopter_DW.obj_h.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter5'

  // Terminate for MATLABSystem: '<S9>/Read Parameter6'
  if (!FLIGHT_hexacopter_DW.obj_a.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter6'

  // Terminate for MATLABSystem: '<S9>/Read Parameter8'
  if (!FLIGHT_hexacopter_DW.obj.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter8'

  // Terminate for MATLABSystem: '<S4>/Read Parameter13'
  if (!FLIGHT_hexacopter_DW.obj_g.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter13'

  // Terminate for MATLABSystem: '<S4>/Read Parameter1'
  if (!FLIGHT_hexacopter_DW.obj_j5.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_j5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter1'

  // Terminate for MATLABSystem: '<S4>/Read Parameter2'
  if (!FLIGHT_hexacopter_DW.obj_ao.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_ao.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter2'

  // Terminate for MATLABSystem: '<S4>/Read Parameter3'
  if (!FLIGHT_hexacopter_DW.obj_n.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter3'

  // Terminate for MATLABSystem: '<S4>/Read Parameter4'
  if (!FLIGHT_hexacopter_DW.obj_c.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter4'

  // Terminate for MATLABSystem: '<S4>/Read Parameter5'
  if (!FLIGHT_hexacopter_DW.obj_aq.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_aq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter5'

  // Terminate for MATLABSystem: '<Root>/PX4 PWM Output'
  if (!FLIGHT_hexacopter_DW.obj_dl.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_dl.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_dl.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_dl.isSetupComplete) {
      pwm_disarm(&FLIGHT_hexacopter_DW.obj_dl.armAdvertiseObj);
      pwm_resetServo(FLIGHT_hexacopter_DW.obj_dl.servoCount,
                     FLIGHT_hexacopter_DW.obj_dl.isMain,
                     &FLIGHT_hexacopter_DW.obj_dl.actuatorAdvertiseObj);
      pwm_close(FLIGHT_hexacopter_DW.obj_dl.servoCount,
                &FLIGHT_hexacopter_DW.obj_dl.actuatorAdvertiseObj,
                &FLIGHT_hexacopter_DW.obj_dl.armAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 PWM Output'
  FLIGHT_hexaco_PX4Timestamp_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_p);

  // Terminate for MATLABSystem: '<S565>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_pt.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_pt.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_pt.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_pt.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_pt.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S565>/SinkBlock'
  FLIGHT_hexaco_PX4Timestamp_Term(&FLIGHT_hexacopter_DW.PX4Timestamp);

  // Terminate for MATLABSystem: '<S563>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_jj.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_jj.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_jj.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_jj.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_jj.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S563>/SinkBlock'

  // Terminate for MATLABSystem: '<S572>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_my.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_my.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_my.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_my.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_my.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S572>/SinkBlock'

  // Terminate for MATLABSystem: '<S9>/Read Parameter7'
  if (!FLIGHT_hexacopter_DW.obj_j.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter7'

  // Terminate for MATLABSystem: '<S9>/Read Parameter4'
  if (!FLIGHT_hexacopter_DW.obj_p.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter4'
  FLIGHT_hexaco_PX4Timestamp_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_pna);

  // Terminate for MATLABSystem: '<S570>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_a4.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_a4.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_a4.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_a4.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_a4.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S570>/SinkBlock'

  // Terminate for MATLABSystem: '<S9>/Read Parameter1'
  if (!FLIGHT_hexacopter_DW.obj_e.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Read Parameter1'

  // Terminate for MATLABSystem: '<S14>/PX4 Timestamp'
  if (!FLIGHT_hexacopter_DW.obj_ky.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_ky.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/PX4 Timestamp'

  // Terminate for MATLABSystem: '<S568>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_pa.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_pa.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_pa.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_pa.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_pa.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S568>/SinkBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
